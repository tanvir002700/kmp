#include<ruby.h>

static VALUE test(VALUE klass)
{
  return rb_str_new2("hello world from test");
}

void Init_kmp_string(VALUE mKmp)
{
    VALUE cKmpString = rb_define_class_under(mKmp, "String", rb_cObject);
}
