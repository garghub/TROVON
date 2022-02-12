asmlinkage long sys_ni_posix_timers(void)
{
pr_err_once("process %d (%s) attempted a POSIX timer syscall "
"while CONFIG_POSIX_TIMERS is not set\n",
current->pid, current->comm);
return -ENOSYS;
}
long clock_nanosleep_restart(struct restart_block *restart_block)
{
return hrtimer_nanosleep_restart(restart_block);
}
