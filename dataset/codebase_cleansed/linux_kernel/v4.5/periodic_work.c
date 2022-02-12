static void periodic_work_func(struct work_struct *work)
{
struct periodic_work *pw;
pw = container_of(work, struct periodic_work, work.work);
(*pw->workfunc)(pw->workfuncarg);
}
struct periodic_work
*visor_periodic_work_create(ulong jiffy_interval,
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
bool visor_periodic_work_nextperiod(struct periodic_work *pw)
{
bool rc = false;
write_lock(&pw->lock);
if (pw->want_to_stop) {
pw->is_scheduled = false;
pw->want_to_stop = false;
rc = true;
goto unlock;
} else if (!queue_delayed_work(pw->workqueue, &pw->work,
pw->jiffy_interval)) {
pw->is_scheduled = false;
rc = false;
goto unlock;
}
rc = true;
unlock:
write_unlock(&pw->lock);
return rc;
}
bool visor_periodic_work_start(struct periodic_work *pw)
{
bool rc = false;
write_lock(&pw->lock);
if (pw->is_scheduled) {
rc = false;
goto unlock;
}
if (pw->want_to_stop) {
rc = false;
goto unlock;
}
INIT_DELAYED_WORK(&pw->work, &periodic_work_func);
if (!queue_delayed_work(pw->workqueue, &pw->work,
pw->jiffy_interval)) {
rc = false;
goto unlock;
}
pw->is_scheduled = true;
rc = true;
unlock:
write_unlock(&pw->lock);
return rc;
}
bool visor_periodic_work_stop(struct periodic_work *pw)
{
bool stopped_something = false;
write_lock(&pw->lock);
stopped_something = pw->is_scheduled && (!pw->want_to_stop);
while (pw->is_scheduled) {
pw->want_to_stop = true;
if (cancel_delayed_work(&pw->work)) {
WARN_ON(!pw->is_scheduled);
pw->is_scheduled = false;
} else {
}
if (pw->is_scheduled) {
write_unlock(&pw->lock);
schedule_timeout_interruptible(msecs_to_jiffies(10));
write_lock(&pw->lock);
} else {
pw->want_to_stop = false;
}
}
write_unlock(&pw->lock);
return stopped_something;
}
