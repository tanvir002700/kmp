#include<ruby.h>

static VALUE test(VALUE klass)
{
  return rb_str_new2("hello world from test");
}

void show(VALUE mKmp)
{
    rb_warn("ok");
    rb_define_singleton_method(mKmp, "test", test, 0);
}
