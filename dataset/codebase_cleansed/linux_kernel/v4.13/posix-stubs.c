asmlinkage long sys_ni_posix_timers(void)
{
pr_err_once("process %d (%s) attempted a POSIX timer syscall "
"while CONFIG_POSIX_TIMERS is not set\n",
current->pid, current->comm);
return -ENOSYS;
}
int do_clock_gettime(clockid_t which_clock, struct timespec64 *tp)
{
switch (which_clock) {
case CLOCK_REALTIME:
ktime_get_real_ts64(tp);
break;
case CLOCK_MONOTONIC:
ktime_get_ts64(tp);
break;
case CLOCK_BOOTTIME:
get_monotonic_boottime64(tp);
break;
default:
return -EINVAL;
}
return 0;
}
