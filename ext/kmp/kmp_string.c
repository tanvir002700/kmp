#include<ruby.h>

static void deallocate(void * str)
{
    free((char *) str);
}

static void allocate(VALUE klass)
{
    char * str = malloc(sizeof(char));
    return Data_Wrap_Struct(klass, NULL, deallocate, str);
}

static VALUE initialize(VALUE self)
{
    return self;
}

void Init_kmp_string(VALUE mKmp)
{
    VALUE cKmpString = rb_define_class_under(mKmp, "String", rb_cObject);

    rb_define_alloc_func(cKmpString, allocate);
    rb_define_method(cKmpString, "initialize", initialize, 0);

}
