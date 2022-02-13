#include "config.h"
#include <_ansi.h>
#include <_syslist.h>
#include <stdio.h>
#include <errno.h>
#include <sys/syscalls.h>


#ifdef REENTRANT_SYSCALLS_PROVIDED
int _close_r(struct _reent *ptr, int fd) {
#else
int _close(int fd) {
	struct _reent *ptr = _REENT;
#endif
	if(__syscalls.close_r)
		return __syscalls.close_r(ptr,fd);

	ptr->_errno = ENOSYS;
	return -1;
}
