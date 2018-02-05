#include<ruby.h>
#include<kmp_string.h>

void Init_kmp()
{
  VALUE mKmp = rb_define_module("Kmp");
  Init_kmp_string(mKmp);
}
