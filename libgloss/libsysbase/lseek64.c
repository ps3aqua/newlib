#include "config.h"
#include <_ansi.h>
#include <_syslist.h>
#include <stdio.h>
#include <reent.h>
#include <errno.h>
#include <sys/syscalls.h>

#ifdef REENTRANT_SYSCALLS_PROVIDED
_off64_t _lseek64_r(struct _reent *r, int fd, _off64_t pos, int dir) {
#else
_off64_t _lseek64(int fd, _off64_t pos, int dir) {
	struct _reent *r = _REENT;
#endif
	if(__syscalls.lseek64_r)
		return __syscalls.lseek64_r(r,fd,pos,dir);

	r->_errno = ENOSYS;
	return -1;
}
