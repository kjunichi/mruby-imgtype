MRuby::Build.new do |conf|
  toolchain :visualcpp
  conf.gembox 'default'
  conf.gem '../mruby-imgtype'
  conf.enable_test
end
