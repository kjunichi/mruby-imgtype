/*
** mrb_imgtype.c - Imgtype class
**
** Copyright (c) Junichi Kajiwara 2017
**
** See Copyright Notice in LICENSE
*/

#include "mruby.h"
#include "mruby/data.h"
#include "mrb_imgtype.h"
#include <windows.h>

extern void
termPutImage(unsigned char *, int, int);
extern void
termInit();
extern void
termFlush();
extern void
termClose();
extern void
termWait();
extern int
parse_ppm_header(char *ppmbuf, int len, int *width, int *height, int *depth);

#define DONE mrb_gc_arena_restore(mrb, 0);

typedef struct {
  char *str;
  int len;
} mrb_imgtype_data;

static const struct mrb_data_type mrb_imgtype_data_type = {
  "mrb_imgtype_data", mrb_free,
};

static void
imgtype(unsigned char *pixmap, int width, int height)
{
  // termInit();
  termPutImage(pixmap, width, height);
  termFlush();
  // termWait();
  // termClose();
}
static mrb_value
mrb_imgtype_term_imgtype(mrb_state *mrb, mrb_value self)
{
  int width, height, len, start_pixmap, depth;
  unsigned char *pixmap;
  char *str;

  mrb_get_args(mrb, "s", &str, &len);
  start_pixmap = parse_ppm_header(str, len, &width, &height, &depth);
  pixmap = &str[start_pixmap];
  imgtype(pixmap, width, height);
  return mrb_str_new_cstr(mrb, "hi!!");
}

static mrb_value
mrb_imgtype_term_init(mrb_state *mrb, mrb_value self)
{
  termInit();
  return mrb_str_new_cstr(mrb, "");
}

static mrb_value
mrb_imgtype_term_close(mrb_state *mrb, mrb_value self)
{
  termClose();
  return mrb_str_new_cstr(mrb, "");
}

static mrb_value
mrb_imgtype_term_get_key(mrb_state *mrb, mrb_value self)
{
  if (GetAsyncKeyState(VK_ESCAPE) && 0x80) {
    return mrb_str_new_cstr(mrb, "ESC");
  }
  return mrb_str_new_cstr(mrb, "");
}

void
mrb_mruby_imgtype_gem_init(mrb_state *mrb)
{
  struct RClass *imgtype;
  imgtype = mrb_define_class(mrb, "Imgtype", mrb->object_class);
  mrb_define_class_method(mrb, imgtype, "imgtype", mrb_imgtype_term_imgtype, MRB_ARGS_REQ(1));
  mrb_define_class_method(mrb, imgtype, "close", mrb_imgtype_term_close, MRB_ARGS_NONE());
  mrb_define_class_method(mrb, imgtype, "get_key", mrb_imgtype_term_get_key, MRB_ARGS_NONE());
  mrb_define_class_method(mrb, imgtype, "init", mrb_imgtype_term_init, MRB_ARGS_NONE());
  DONE;
}

void
mrb_mruby_imgtype_gem_final(mrb_state *mrb)
{
}
