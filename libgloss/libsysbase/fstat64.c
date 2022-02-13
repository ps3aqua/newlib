#include "config.h"
#include <_ansi.h>
#include <_syslist.h>
#include <reent.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/syscalls.h>

#ifdef REENTRANT_SYSCALLS_PROVIDED
int _fstat64_r(struct _reent *r, int fd, struct stat *st) {
#else
int _fstat64(int fd, struct stat *st) {
	struct _reent *r = _REENT;
#endif
	if(__syscalls.fstat64_r)
		return __syscalls.fstat64_r(r,fd,st);

	r->_errno = ENOSYS;
	return -1;
}
