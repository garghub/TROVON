static void periodic_work_func(struct work_struct *work)
{
PERIODIC_WORK *periodic_work =
container_of(work, struct PERIODIC_WORK_Tag, work.work);
(*periodic_work->workfunc)(periodic_work->workfuncarg);
}
PERIODIC_WORK *visor_periodic_work_create(ulong jiffy_interval,
struct workqueue_struct *workqueue,
void (*workfunc)(void *),
void *workfuncarg,
const char *devnam)
{
PERIODIC_WORK *periodic_work = kzalloc(sizeof(PERIODIC_WORK),
GFP_KERNEL | __GFP_NORETRY);
if (periodic_work == NULL) {
ERRDRV("periodic_work allocation failed ");
return NULL;
}
rwlock_init(&periodic_work->lock);
periodic_work->jiffy_interval = jiffy_interval;
periodic_work->workqueue = workqueue;
periodic_work->workfunc = workfunc;
periodic_work->workfuncarg = workfuncarg;
periodic_work->devnam = devnam;
return periodic_work;
}
void visor_periodic_work_destroy(PERIODIC_WORK *periodic_work)
{
if (periodic_work == NULL)
return;
kfree(periodic_work);
}
BOOL visor_periodic_work_nextperiod(PERIODIC_WORK *periodic_work)
{
BOOL rc = FALSE;
write_lock(&periodic_work->lock);
if (periodic_work->want_to_stop) {
periodic_work->is_scheduled = FALSE;
periodic_work->want_to_stop = FALSE;
rc = TRUE;
goto Away;
} else if (queue_delayed_work(periodic_work->workqueue,
&periodic_work->work,
periodic_work->jiffy_interval) < 0) {
ERRDEV(periodic_work->devnam, "queue_delayed_work failed!");
periodic_work->is_scheduled = FALSE;
rc = FALSE;
goto Away;
}
rc = TRUE;
Away:
write_unlock(&periodic_work->lock);
return rc;
}
BOOL visor_periodic_work_start(PERIODIC_WORK *periodic_work)
{
BOOL rc = FALSE;
write_lock(&periodic_work->lock);
if (periodic_work->is_scheduled) {
rc = FALSE;
goto Away;
}
if (periodic_work->want_to_stop) {
ERRDEV(periodic_work->devnam,
"dev_start_periodic_work failed!");
rc = FALSE;
goto Away;
}
INIT_DELAYED_WORK(&periodic_work->work, &periodic_work_func);
if (queue_delayed_work(periodic_work->workqueue,
&periodic_work->work,
periodic_work->jiffy_interval) < 0) {
ERRDEV(periodic_work->devnam,
"%s queue_delayed_work failed!", __func__);
rc = FALSE;
goto Away;
}
periodic_work->is_scheduled = TRUE;
rc = TRUE;
Away:
write_unlock(&periodic_work->lock);
return rc;
}
BOOL visor_periodic_work_stop(PERIODIC_WORK *periodic_work)
{
BOOL stopped_something = FALSE;
write_lock(&periodic_work->lock);
stopped_something = periodic_work->is_scheduled &&
(!periodic_work->want_to_stop);
while (periodic_work->is_scheduled) {
periodic_work->want_to_stop = TRUE;
if (cancel_delayed_work(&periodic_work->work)) {
ASSERT(periodic_work->is_scheduled);
periodic_work->is_scheduled = FALSE;
} else {
}
if (periodic_work->is_scheduled) {
write_unlock(&periodic_work->lock);
WARNDEV(periodic_work->devnam,
"waiting for delayed work...");
SLEEPJIFFIES(10);
write_lock(&periodic_work->lock);
} else
periodic_work->want_to_stop = FALSE;
}
write_unlock(&periodic_work->lock);
return stopped_something;
}
