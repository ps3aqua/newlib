#include "config.h"
#include <_ansi.h>
#include <_syslist.h>
#include <sys/errno.h>
#include <sys/syscalls.h>

#ifdef REENTRANT_SYSCALLS_PROVIDED
void * _sbrk_r(struct _reent *ptr, ptrdiff_t incr) {
#else
void * _sbrk(ptrdiff_t incr) {
	struct _reent *ptr = _REENT;
#endif
	if(__syscalls.sbrk_r)
		return __syscalls.sbrk_r(ptr,incr);
	else {
		ptr->_errno = ENOMEM;
		return (caddr_t)-1;
	}
}
