##
## Imgtype Test
##

assert("Imgtype#hello") do
  t = Imgtype.new "hello"
  assert_equal("hello", t.hello)
end

assert("Imgtype#bye") do
  t = Imgtype.new "hello"
  assert_equal("hello bye", t.bye)
end

assert("Imgtype.hi") do
  assert_equal("hi!!", Imgtype.hi)
end
