int
uisthread_start(struct uisthread_info *thrinfo,
int (*threadfn)(void *), void *thrcontext, char *name)
{
init_completion(&thrinfo->has_stopped);
thrinfo->task = kthread_run(threadfn, thrcontext, name);
if (IS_ERR(thrinfo->task)) {
thrinfo->id = 0;
return 0;
}
thrinfo->id = thrinfo->task->pid;
return 1;
}
void
uisthread_stop(struct uisthread_info *thrinfo)
{
int stopped = 0;
if (thrinfo->id == 0)
return;
kthread_stop(thrinfo->task);
if (wait_for_completion_timeout(&thrinfo->has_stopped, 60 * HZ))
stopped = 1;
if (stopped)
thrinfo->id = 0;
}
