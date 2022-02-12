int
uisthread_start(struct uisthread_info *thrinfo,
int (*threadfn)(void *), void *thrcontext, char *name)
{
thrinfo->should_stop = 0;
init_completion(&thrinfo->has_stopped);
thrinfo->task = kthread_create(threadfn, thrcontext, name, NULL);
if (IS_ERR(thrinfo->task)) {
thrinfo->id = 0;
return 0;
}
thrinfo->id = thrinfo->task->pid;
wake_up_process(thrinfo->task);
LOGINF("started thread pid:%d\n", thrinfo->id);
return 1;
}
void
uisthread_stop(struct uisthread_info *thrinfo)
{
int ret;
int stopped = 0;
if (thrinfo->id == 0)
return;
LOGINF("uisthread_stop stopping id:%d\n", thrinfo->id);
thrinfo->should_stop = 1;
ret = KILL(thrinfo->id, SIGHUP, 1);
if (ret) {
LOGERR("unable to signal thread %d\n", ret);
} else {
if (wait_for_completion_timeout(&thrinfo->has_stopped, 60 * HZ))
stopped = 1;
else
LOGERR("timed out trying to signal thread\n");
}
if (stopped) {
LOGINF("uisthread_stop stopped id:%d\n", thrinfo->id);
thrinfo->id = 0;
}
}
