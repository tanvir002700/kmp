#include<ruby.h>

static VALUE hello_world(VALUE klass)
{
  return rb_str_new2("hello world");
}

void Init_hello()
{
  VALUE mStree = rb_define_module("Hello");
  rb_define_singleton_method(mStree, "hello_world", hello_world, 0);
}
