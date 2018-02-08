#include<ruby.h>
#include<string.h>

struct Str
{
    char * ptr;
};

static void deallocate(struct Str *str)
{
    free(str);
}

static VALUE allocate(VALUE klass)
{
    struct Str * str = (struct Str *)malloc(sizeof(struct Str));

    VALUE obj = Data_Make_Struct(klass, struct Str, NULL, deallocate, str);
    str->ptr = NULL;
    return obj;
}

static VALUE initialize(VALUE self, VALUE rb_string)
{
    struct Str * str;

    Check_Type(rb_string, T_STRING);
    Data_Get_Struct(self, struct Str, str);

    str->ptr = calloc(RSTRING_LEN(rb_string) + 1 , sizeof(char));
    memcpy(str->ptr, StringValuePtr(rb_string), RSTRING_LEN(rb_string));

    rb_iv_set(self, "@str", rb_string);
    rb_iv_set(self, "@length", INT2NUM(RSTRING_LEN(rb_string)));

    return self;
}

static int* compute_prefix(const char *str)
{
    int len = strlen(str);
    int k = -1;
    int * prefix;

    prefix = (int *) calloc(len+1, sizeof(int));
    prefix[0] = -1;

    for(int i=1; i<len; i++)
    {
        while( k>-1 && str[k+1]!=str[i] ) k = prefix[k];
        if( str[k+1] == str[i] ) k = k+1;
        prefix[i] = k;
    }
    return prefix;
}

static VALUE match(VALUE self, VALUE rb_str)
{
    VALUE positions = rb_ary_new();
    struct Str * obj;
    char * str;
    char * ptrn;
    int * prefix;
    int n,m,q;

    Check_Type(rb_str, T_STRING);

    Data_Get_Struct(self, struct Str, obj);
    str = calloc(strlen(obj->ptr) + 1, sizeof(char));
    strcpy(str, obj->ptr);

    ptrn = (char *) calloc(RSTRING_LEN(rb_str) + 1, sizeof(char));
    memcpy(ptrn, StringValuePtr(rb_str), RSTRING_LEN(rb_str));

    prefix = compute_prefix(ptrn);

    n = strlen(str);
    m = strlen(ptrn);

    q = -1;
    for(int i=0; i<n; i++)
    {
        while( q>-1 && ptrn[q+1]!=str[i] ) q = prefix[q];
        if( ptrn[q+1]==str[i] ) q = q+1;
        if( q==m-1 )
        {
            rb_ary_push(positions, INT2NUM(i-m+1));
            q = prefix[q];
        }
    }
    free(prefix);
    free(ptrn);
    free(str);

    return positions;
}


static VALUE replace(VALUE self, VALUE rb_str, VALUE rb_string_sub)
{
    struct Str * obj;
    char * str;
    char * new_str;
    char * sub_str;

    Data_Get_Struct(self, struct Str, obj);
    str = calloc(strlen(obj->ptr) + 1, sizeof(char));
    strcpy(str, obj->ptr);
    int current_str_len = strlen(str);

    sub_str = (char *) calloc(RSTRING_LEN(rb_string_sub) + 1, sizeof(char));
    memcpy(sub_str, StringValuePtr(rb_string_sub), RSTRING_LEN(rb_string_sub));


    VALUE pos = match(self, rb_str);
    VALUE * arr = rb_array_const_ptr(pos);

    int replace_str_len, sub_string_len, occurance;

    replace_str_len = RSTRING_LEN(rb_str);
    sub_string_len = strlen(sub_str);
    occurance = rb_array_len(pos);

    int new_str_len = (current_str_len - (replace_str_len * occurance) + (sub_string_len * occurance));
    new_str = (char *) calloc(new_str_len+1, sizeof(char));

    int indx = 0;
    int occurance_indx = occurance ? 0 : -1;
    int str_indx = 0;

    while(str_indx<=new_str_len)
    {
        if(occurance_indx != -1 && occurance_indx<occurance && RB_NUM2INT(arr[occurance_indx]) == indx)
        {
            int sub_indx = 0;
            while(sub_indx<sub_string_len)
            {
                new_str[str_indx] = sub_str[sub_indx];
                str_indx++;
                sub_indx++;
            }
            indx += replace_str_len;
            occurance_indx++;
        }
        else
        {
            new_str[str_indx++] = str[indx++];
        }
    }

    VALUE rb_new_str = rb_str_new2(new_str);

    free(new_str);
    free(sub_str);
    free(str);

    return rb_new_str;
}

void Init_kmp_string(VALUE mKmp)
{
    VALUE cKmpString = rb_define_class_under(mKmp, "String", rb_cObject);

    rb_define_alloc_func(cKmpString, allocate);
    rb_define_method(cKmpString, "initialize", initialize, 1);
    rb_define_method(cKmpString, "match", match, 1);
    rb_define_method(cKmpString, "replace", replace, 2);
    rb_define_attr(cKmpString, "str", 1, 0);
    rb_define_attr(cKmpString, "length", 1, 0);
}

