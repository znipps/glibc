/* Multiple versions of stpcpy
   All versions must be listed in ifunc-impl-list.c.  */
#define USE_AS_STPCPY
#define STRCPY __stpcpy
#include "strcpy.S"

weak_alias (__stpcpy, stpcpy)
libc_hidden_def (__stpcpy)
libc_hidden_builtin_def (stpcpy)
