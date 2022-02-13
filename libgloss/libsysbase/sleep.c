#include "config.h"
#include <_ansi.h>
#include <_syslist.h>
#include <unistd.h>
#include <errno.h>
#include <sys/syscalls.h>

int usleep(useconds_t usec)
{
	struct _reent *r = _REENT;

	if(__syscalls.usleep_r)
		return __syscalls.usleep_r(r,usec);

	r->_errno = ENOSYS;
	return -1;
}

unsigned int sleep(unsigned int sec)
{
	struct _reent *r = _REENT;

	if(__syscalls.sleep_r)
		return __syscalls.sleep_r(r,sec);

	r->_errno = ENOSYS;
	return -1;
}
