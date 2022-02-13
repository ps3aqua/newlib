#include "config.h"
#include <_ansi.h>
#include <_syslist.h>
#include <reent.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/syscalls.h>

#ifdef REENTRANT_SYSCALLS_PROVIDED
int _stat64_r(struct _reent *r, const char *path, struct stat *st) {
#else
int _stat64(const char *path, struct stat *st) {
	struct _reent *r = _REENT;
#endif
	if(__syscalls.stat64_r)
		return __syscalls.stat64_r(r,path,st);

	r->_errno = ENOSYS;
	return -1;
}
