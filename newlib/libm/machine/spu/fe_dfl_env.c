#include <fenv.h>
/*
 * Define for FE_DFL_ENV macro, all bits zero.
 */
fenv_t __fe_dfl_env = { 0 };
