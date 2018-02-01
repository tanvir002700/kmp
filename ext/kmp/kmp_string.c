#include<ruby.h>
#include<string.h>

static void deallocate(void * str)
{
    free((char *) str);
}

static void allocate(VALUE klass)
{
    char * str = malloc(sizeof(char));
    return Data_Wrap_Struct(klass, NULL, deallocate, str);
}

static VALUE initialize(VALUE self, VALUE rb_string)
{
    char * str;
    void * data;

    Check_Type(rb_string, T_STRING);
    Data_Get_Struct(self, char, str);
    data = calloc(RSTRING_LEN(rb_string), sizeof(char));
    memcpy(data, StringValuePtr(rb_string), RSTRING_LEN(rb_string));

    strcpy(str, data);
    rb_iv_set(self, "@str", rb_string);

    return self;
}

static VALUE length(VALUE self)
{
    char * str;
    Data_Get_Struct(self, char, str);
    int len = strlen(str);
    return INT2NUM(len);
}

static char* compute_prefix(char *str)
{

}

static VALUE match(VALUE self, VALUE rb_str)
{
    char * str;
    char * ptrn;

    Data_Get_Struct(self, char, str);

    ptrn = calloc(RSTRING_LEN(rb_str), sizeof(char));
    memcpy(ptrn, StringValuePtr(rb_str), RSTRING_LEN(rb_str));

    fprintf(stderr, "%s\n", ptrn);
    return Qtrue;
}

void Init_kmp_string(VALUE mKmp)
{
    VALUE cKmpString = rb_define_class_under(mKmp, "String", rb_cObject);

    rb_define_alloc_func(cKmpString, allocate);
    rb_define_method(cKmpString, "initialize", initialize, 1);
    rb_define_method(cKmpString, "length", length, 0);
    rb_define_method(cKmpString, "match", match, 1);
    rb_define_attr(cKmpString, "str", 1, 0);
}

