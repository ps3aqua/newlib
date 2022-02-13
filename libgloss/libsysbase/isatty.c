#include "config.h"
#include <_ansi.h>
#include <_syslist.h>
#include <stdio.h>
#include <errno.h>
#include <sys/syscalls.h>

#ifdef REENTRANT_SYSCALLS_PROVIDED
int _isatty_r(struct _reent *ptr, int fd) {
#else
int isatty(int fd) {
	struct _reent *ptr = _REENT;
#endif
	if(__syscalls.isatty_r)
		return __syscalls.isatty_r(ptr,fd);

	ptr->_errno = ENOTTY;
	return 0;
}
