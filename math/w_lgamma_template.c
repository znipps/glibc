/* Wrapper to set errno for acos.
   Copyright (C) 2011-2016 Free Software Foundation, Inc.
   This file is part of the GNU C Library.

   The GNU C Library is free software; you can redistribute it and/or
   modify it under the terms of the GNU Lesser General Public
   License as published by the Free Software Foundation; either
   version 2.1 of the License, or (at your option) any later version.

   The GNU C Library is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
   Lesser General Public License for more details.

   You should have received a copy of the GNU Lesser General Public
   License along with the GNU C Library; if not, see
   <http://www.gnu.org/licenses/>.  */

/* Do not build wrappers from the templates for the types that define the macro
   below.  This macro is set in math-type-macros-<type>.h in sysdeps/generic
   for each floating-point type.  */
#if defined __USE_WRAPPER_TEMPLATE && __USE_WRAPPER_TEMPLATE

# include <fenv.h>
# include <math.h>
# include <math_private.h>

#define M_CALL_FUNC_X(x) x ## _r
#define M_CALL_FUNC(x) M_CALL_FUNC_X (x)

FLOAT
M_DECL_FUNC (__lgamma) (FLOAT x)
{
  FLOAT y = M_CALL_FUNC (M_SUF (__ieee754_lgamma)) (x, &__signgam);
  if (__builtin_expect (!isfinite (y), 0) && isfinite (x))
    {
      __set_errno (ERANGE);
    }
  return y;
}
declare_mgen_alias (__lgamma, lgamma)

#endif /* __USE_WRAPPER_TEMPLATE.  */