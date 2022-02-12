static void periodic_work_func(struct work_struct *work)
{
struct periodic_work *pw;
pw = container_of(work, struct periodic_work, work.work);
(*pw->workfunc)(pw->workfuncarg);
}
struct periodic_work *visor_periodic_work_create(ulong jiffy_interval,
struct workqueue_struct *workqueue,
void (*workfunc)(void *),
void *workfuncarg,
const char *devnam)
{
struct periodic_work *pw;
pw = kzalloc(sizeof(*pw), GFP_KERNEL | __GFP_NORETRY);
if (!pw)
return NULL;
rwlock_init(&pw->lock);
pw->jiffy_interval = jiffy_interval;
pw->workqueue = workqueue;
pw->workfunc = workfunc;
pw->workfuncarg = workfuncarg;
pw->devnam = devnam;
return pw;
}
void visor_periodic_work_destroy(struct periodic_work *pw)
{
kfree(pw);
}
BOOL visor_periodic_work_nextperiod(struct periodic_work *pw)
{
BOOL rc = FALSE;
write_lock(&pw->lock);
if (pw->want_to_stop) {
pw->is_scheduled = FALSE;
pw->want_to_stop = FALSE;
rc = TRUE;
goto unlock;
} else if (queue_delayed_work(pw->workqueue, &pw->work,
pw->jiffy_interval) < 0) {
ERRDEV(pw->devnam, "queue_delayed_work failed!");
pw->is_scheduled = FALSE;
rc = FALSE;
goto unlock;
}
rc = TRUE;
unlock:
write_unlock(&pw->lock);
return rc;
}
BOOL visor_periodic_work_start(struct periodic_work *pw)
{
BOOL rc = FALSE;
write_lock(&pw->lock);
if (pw->is_scheduled) {
rc = FALSE;
goto unlock;
}
if (pw->want_to_stop) {
ERRDEV(pw->devnam,
"dev_start_periodic_work failed!");
rc = FALSE;
goto unlock;
}
INIT_DELAYED_WORK(&pw->work, &periodic_work_func);
if (queue_delayed_work(pw->workqueue, &pw->work,
pw->jiffy_interval) < 0) {
ERRDEV(pw->devnam, "%s queue_delayed_work failed!", __func__);
rc = FALSE;
goto unlock;
}
pw->is_scheduled = TRUE;
rc = TRUE;
unlock:
write_unlock(&pw->lock);
return rc;
}
BOOL visor_periodic_work_stop(struct periodic_work *pw)
{
BOOL stopped_something = FALSE;
write_lock(&pw->lock);
stopped_something = pw->is_scheduled && (!pw->want_to_stop);
while (pw->is_scheduled) {
pw->want_to_stop = TRUE;
if (cancel_delayed_work(&pw->work)) {
ASSERT(pw->is_scheduled);
pw->is_scheduled = FALSE;
} else {
}
if (pw->is_scheduled) {
write_unlock(&pw->lock);
WARNDEV(pw->devnam,
"waiting for delayed work...");
SLEEPJIFFIES(10);
write_lock(&pw->lock);
} else
pw->want_to_stop = FALSE;
}
write_unlock(&pw->lock);
return stopped_something;
}
