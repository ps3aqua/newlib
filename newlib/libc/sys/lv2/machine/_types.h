#ifndef _MACHINE__TYPES_H
#define _MACHINE__TYPES_H

#include <machine/_default_types.h>

#ifndef FD_SETSIZE
#define FD_SETSIZE 1024
typedef unsigned int __fd_mask;
#endif

#define __machine_fpos_t_defined
typedef long long _fpos_t;

#define __machine_off_t_defined
typedef long long _off_t;

#endif // _MACHINE__TYPES_H
