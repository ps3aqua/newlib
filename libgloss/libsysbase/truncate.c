#include "config.h"
#include <_ansi.h>
#include <_syslist.h>
#include <reent.h>
#include <errno.h>
#include <fcntl.h>
#include <sys/syscalls.h>

int truncate(const char *path, off_t len)
{
	struct _reent *r = _REENT;

	if(__syscalls.truncate_r)
		return __syscalls.truncate_r(r,path,len);

	r->_errno = ENOSYS;
	return -1;
}
