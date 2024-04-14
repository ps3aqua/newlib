#include "config.h"
#include <_ansi.h>
#include <_syslist.h>
#include <stdio.h>
#include <errno.h>
#include <sys/syscalls.h>


#ifdef REENTRANT_SYSCALLS_PROVIDED
_ssize_t _write_r(struct _reent *r, int fd, const void *ptr, size_t len) {
#else
_READ_WRITE_RETURN_TYPE _write(int fd, const void *ptr, size_t len) {
	struct _reent *r = _REENT;
#endif
	if(__syscalls.write_r)
		return __syscalls.write_r(r,fd,ptr,len);

	r->_errno = ENOSYS;
	return -1;
}
