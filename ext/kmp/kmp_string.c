#include<ruby.h>

static VALUE test(VALUE klass)
{
  return rb_str_new2("hello world from test");
}

void show(VALUE mKmp)
{
    rb_warn("ok");
    VALUE cKmpString = rb_define_class_under(mKmp, "String", rb_cObject);
}
