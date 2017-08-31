# mruby-imgtype 

Imgtype class

## install by mrbgems

- add conf.gem line to `build_config.rb`

```ruby
MRuby::Build.new do |conf|

    # ... (snip) ...

    conf.gem :github => 'kjunichi/mruby-imgtype'
end
```
## example

You need to install mruby-webcam.

```ruby
Imgtype.init

cam = Webcam.new
cam.setFmt "ppm"
cam.capture {|img|
  Imgtype.imgtype img
}
while true
    cam.snap
    Sleep::usleep(1000)
    if Imgtype.get_key == "ESC" then
        break
    end
end
Imgtype.close
```

## License
under the MIT License:
- see LICENSE file
