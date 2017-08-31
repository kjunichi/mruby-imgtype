# mruby-imgtype   [![Build Status](https://travis-ci.org/kjunichi/mruby-imgtype.svg?branch=master)](https://travis-ci.org/kjunichi/mruby-imgtype)
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
```ruby
p Imgtype.hi
#=> "hi!!"
t = Imgtype.new "hello"
p t.hello
#=> "hello"
p t.bye
#=> "hello bye"
```

## License
under the MIT License:
- see LICENSE file
