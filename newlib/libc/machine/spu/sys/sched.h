#ifndef _SYS_SCHED_H
#define _SYS_SCHED_H
#ifdef __cplusplus
extern "C" {
#endif

int sched_yield(void);

struct sched_param {
  int sched_priority;           /* Process execution scheduling priority */
};

#ifdef __cplusplus
}
#endif
#endif
