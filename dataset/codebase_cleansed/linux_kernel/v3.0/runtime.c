void update_pm_runtime_accounting(struct device *dev)
{
unsigned long now = jiffies;
int delta;
delta = now - dev->power.accounting_timestamp;
if (delta < 0)
delta = 0;
dev->power.accounting_timestamp = now;
if (dev->power.disable_depth > 0)
return;
if (dev->power.runtime_status == RPM_SUSPENDED)
dev->power.suspended_jiffies += delta;
else
dev->power.active_jiffies += delta;
}
static void __update_runtime_status(struct device *dev, enum rpm_status status)
{
update_pm_runtime_accounting(dev);
dev->power.runtime_status = status;
}
static void pm_runtime_deactivate_timer(struct device *dev)
{
if (dev->power.timer_expires > 0) {
del_timer(&dev->power.suspend_timer);
dev->power.timer_expires = 0;
}
}
static void pm_runtime_cancel_pending(struct device *dev)
{
pm_runtime_deactivate_timer(dev);
dev->power.request = RPM_REQ_NONE;
}
unsigned long pm_runtime_autosuspend_expiration(struct device *dev)
{
int autosuspend_delay;
long elapsed;
unsigned long last_busy;
unsigned long expires = 0;
if (!dev->power.use_autosuspend)
goto out;
autosuspend_delay = ACCESS_ONCE(dev->power.autosuspend_delay);
if (autosuspend_delay < 0)
goto out;
last_busy = ACCESS_ONCE(dev->power.last_busy);
elapsed = jiffies - last_busy;
if (elapsed < 0)
goto out;
expires = last_busy + msecs_to_jiffies(autosuspend_delay);
if (autosuspend_delay >= 1000)
expires = round_jiffies(expires);
expires += !expires;
if (elapsed >= expires - last_busy)
expires = 0;
out:
return expires;
}
static int rpm_check_suspend_allowed(struct device *dev)
{
int retval = 0;
if (dev->power.runtime_error)
retval = -EINVAL;
else if (atomic_read(&dev->power.usage_count) > 0
|| dev->power.disable_depth > 0)
retval = -EAGAIN;
else if (!pm_children_suspended(dev))
retval = -EBUSY;
else if ((dev->power.deferred_resume
&& dev->power.runtime_status == RPM_SUSPENDING)
|| (dev->power.request_pending
&& dev->power.request == RPM_REQ_RESUME))
retval = -EAGAIN;
else if (dev->power.runtime_status == RPM_SUSPENDED)
retval = 1;
return retval;
}
static int rpm_idle(struct device *dev, int rpmflags)
{
int (*callback)(struct device *);
int retval;
retval = rpm_check_suspend_allowed(dev);
if (retval < 0)
;
else if (dev->power.runtime_status != RPM_ACTIVE)
retval = -EAGAIN;
else if (dev->power.request_pending &&
dev->power.request > RPM_REQ_IDLE)
retval = -EAGAIN;
else if (dev->power.idle_notification)
retval = -EINPROGRESS;
if (retval)
goto out;
dev->power.request = RPM_REQ_NONE;
if (dev->power.no_callbacks) {
retval = rpm_suspend(dev, rpmflags);
goto out;
}
if (rpmflags & RPM_ASYNC) {
dev->power.request = RPM_REQ_IDLE;
if (!dev->power.request_pending) {
dev->power.request_pending = true;
queue_work(pm_wq, &dev->power.work);
}
goto out;
}
dev->power.idle_notification = true;
if (dev->pwr_domain)
callback = dev->pwr_domain->ops.runtime_idle;
else if (dev->type && dev->type->pm)
callback = dev->type->pm->runtime_idle;
else if (dev->class && dev->class->pm)
callback = dev->class->pm->runtime_idle;
else if (dev->bus && dev->bus->pm)
callback = dev->bus->pm->runtime_idle;
else
callback = NULL;
if (callback) {
spin_unlock_irq(&dev->power.lock);
callback(dev);
spin_lock_irq(&dev->power.lock);
}
dev->power.idle_notification = false;
wake_up_all(&dev->power.wait_queue);
out:
return retval;
}
static int rpm_callback(int (*cb)(struct device *), struct device *dev)
__releases(&dev->power.lock
static int rpm_suspend(struct device *dev, int rpmflags)
__releases(&dev->power.lock
static int rpm_resume(struct device *dev, int rpmflags)
__releases(&dev->power.lock
static void pm_runtime_work(struct work_struct *work)
{
struct device *dev = container_of(work, struct device, power.work);
enum rpm_request req;
spin_lock_irq(&dev->power.lock);
if (!dev->power.request_pending)
goto out;
req = dev->power.request;
dev->power.request = RPM_REQ_NONE;
dev->power.request_pending = false;
switch (req) {
case RPM_REQ_NONE:
break;
case RPM_REQ_IDLE:
rpm_idle(dev, RPM_NOWAIT);
break;
case RPM_REQ_SUSPEND:
rpm_suspend(dev, RPM_NOWAIT);
break;
case RPM_REQ_AUTOSUSPEND:
rpm_suspend(dev, RPM_NOWAIT | RPM_AUTO);
break;
case RPM_REQ_RESUME:
rpm_resume(dev, RPM_NOWAIT);
break;
}
out:
spin_unlock_irq(&dev->power.lock);
}
static void pm_suspend_timer_fn(unsigned long data)
{
struct device *dev = (struct device *)data;
unsigned long flags;
unsigned long expires;
spin_lock_irqsave(&dev->power.lock, flags);
expires = dev->power.timer_expires;
if (expires > 0 && !time_after(expires, jiffies)) {
dev->power.timer_expires = 0;
rpm_suspend(dev, dev->power.timer_autosuspends ?
(RPM_ASYNC | RPM_AUTO) : RPM_ASYNC);
}
spin_unlock_irqrestore(&dev->power.lock, flags);
}
int pm_schedule_suspend(struct device *dev, unsigned int delay)
{
unsigned long flags;
int retval;
spin_lock_irqsave(&dev->power.lock, flags);
if (!delay) {
retval = rpm_suspend(dev, RPM_ASYNC);
goto out;
}
retval = rpm_check_suspend_allowed(dev);
if (retval)
goto out;
pm_runtime_cancel_pending(dev);
dev->power.timer_expires = jiffies + msecs_to_jiffies(delay);
dev->power.timer_expires += !dev->power.timer_expires;
dev->power.timer_autosuspends = 0;
mod_timer(&dev->power.suspend_timer, dev->power.timer_expires);
out:
spin_unlock_irqrestore(&dev->power.lock, flags);
return retval;
}
int __pm_runtime_idle(struct device *dev, int rpmflags)
{
unsigned long flags;
int retval;
if (rpmflags & RPM_GET_PUT) {
if (!atomic_dec_and_test(&dev->power.usage_count))
return 0;
}
spin_lock_irqsave(&dev->power.lock, flags);
retval = rpm_idle(dev, rpmflags);
spin_unlock_irqrestore(&dev->power.lock, flags);
return retval;
}
int __pm_runtime_suspend(struct device *dev, int rpmflags)
{
unsigned long flags;
int retval;
if (rpmflags & RPM_GET_PUT) {
if (!atomic_dec_and_test(&dev->power.usage_count))
return 0;
}
spin_lock_irqsave(&dev->power.lock, flags);
retval = rpm_suspend(dev, rpmflags);
spin_unlock_irqrestore(&dev->power.lock, flags);
return retval;
}
int __pm_runtime_resume(struct device *dev, int rpmflags)
{
unsigned long flags;
int retval;
if (rpmflags & RPM_GET_PUT)
atomic_inc(&dev->power.usage_count);
spin_lock_irqsave(&dev->power.lock, flags);
retval = rpm_resume(dev, rpmflags);
spin_unlock_irqrestore(&dev->power.lock, flags);
return retval;
}
int __pm_runtime_set_status(struct device *dev, unsigned int status)
{
struct device *parent = dev->parent;
unsigned long flags;
bool notify_parent = false;
int error = 0;
if (status != RPM_ACTIVE && status != RPM_SUSPENDED)
return -EINVAL;
spin_lock_irqsave(&dev->power.lock, flags);
if (!dev->power.runtime_error && !dev->power.disable_depth) {
error = -EAGAIN;
goto out;
}
if (dev->power.runtime_status == status)
goto out_set;
if (status == RPM_SUSPENDED) {
if (parent) {
atomic_add_unless(&parent->power.child_count, -1, 0);
notify_parent = !parent->power.ignore_children;
}
goto out_set;
}
if (parent) {
spin_lock_nested(&parent->power.lock, SINGLE_DEPTH_NESTING);
if (!parent->power.disable_depth
&& !parent->power.ignore_children
&& parent->power.runtime_status != RPM_ACTIVE)
error = -EBUSY;
else if (dev->power.runtime_status == RPM_SUSPENDED)
atomic_inc(&parent->power.child_count);
spin_unlock(&parent->power.lock);
if (error)
goto out;
}
out_set:
__update_runtime_status(dev, status);
dev->power.runtime_error = 0;
out:
spin_unlock_irqrestore(&dev->power.lock, flags);
if (notify_parent)
pm_request_idle(parent);
return error;
}
static void __pm_runtime_barrier(struct device *dev)
{
pm_runtime_deactivate_timer(dev);
if (dev->power.request_pending) {
dev->power.request = RPM_REQ_NONE;
spin_unlock_irq(&dev->power.lock);
cancel_work_sync(&dev->power.work);
spin_lock_irq(&dev->power.lock);
dev->power.request_pending = false;
}
if (dev->power.runtime_status == RPM_SUSPENDING
|| dev->power.runtime_status == RPM_RESUMING
|| dev->power.idle_notification) {
DEFINE_WAIT(wait);
for (;;) {
prepare_to_wait(&dev->power.wait_queue, &wait,
TASK_UNINTERRUPTIBLE);
if (dev->power.runtime_status != RPM_SUSPENDING
&& dev->power.runtime_status != RPM_RESUMING
&& !dev->power.idle_notification)
break;
spin_unlock_irq(&dev->power.lock);
schedule();
spin_lock_irq(&dev->power.lock);
}
finish_wait(&dev->power.wait_queue, &wait);
}
}
int pm_runtime_barrier(struct device *dev)
{
int retval = 0;
pm_runtime_get_noresume(dev);
spin_lock_irq(&dev->power.lock);
if (dev->power.request_pending
&& dev->power.request == RPM_REQ_RESUME) {
rpm_resume(dev, 0);
retval = 1;
}
__pm_runtime_barrier(dev);
spin_unlock_irq(&dev->power.lock);
pm_runtime_put_noidle(dev);
return retval;
}
void __pm_runtime_disable(struct device *dev, bool check_resume)
{
spin_lock_irq(&dev->power.lock);
if (dev->power.disable_depth > 0) {
dev->power.disable_depth++;
goto out;
}
if (check_resume && dev->power.request_pending
&& dev->power.request == RPM_REQ_RESUME) {
pm_runtime_get_noresume(dev);
rpm_resume(dev, 0);
pm_runtime_put_noidle(dev);
}
if (!dev->power.disable_depth++)
__pm_runtime_barrier(dev);
out:
spin_unlock_irq(&dev->power.lock);
}
void pm_runtime_enable(struct device *dev)
{
unsigned long flags;
spin_lock_irqsave(&dev->power.lock, flags);
if (dev->power.disable_depth > 0)
dev->power.disable_depth--;
else
dev_warn(dev, "Unbalanced %s!\n", __func__);
spin_unlock_irqrestore(&dev->power.lock, flags);
}
void pm_runtime_forbid(struct device *dev)
{
spin_lock_irq(&dev->power.lock);
if (!dev->power.runtime_auto)
goto out;
dev->power.runtime_auto = false;
atomic_inc(&dev->power.usage_count);
rpm_resume(dev, 0);
out:
spin_unlock_irq(&dev->power.lock);
}
void pm_runtime_allow(struct device *dev)
{
spin_lock_irq(&dev->power.lock);
if (dev->power.runtime_auto)
goto out;
dev->power.runtime_auto = true;
if (atomic_dec_and_test(&dev->power.usage_count))
rpm_idle(dev, RPM_AUTO);
out:
spin_unlock_irq(&dev->power.lock);
}
void pm_runtime_no_callbacks(struct device *dev)
{
spin_lock_irq(&dev->power.lock);
dev->power.no_callbacks = 1;
spin_unlock_irq(&dev->power.lock);
if (device_is_registered(dev))
rpm_sysfs_remove(dev);
}
void pm_runtime_irq_safe(struct device *dev)
{
if (dev->parent)
pm_runtime_get_sync(dev->parent);
spin_lock_irq(&dev->power.lock);
dev->power.irq_safe = 1;
spin_unlock_irq(&dev->power.lock);
}
static void update_autosuspend(struct device *dev, int old_delay, int old_use)
{
int delay = dev->power.autosuspend_delay;
if (dev->power.use_autosuspend && delay < 0) {
if (!old_use || old_delay >= 0) {
atomic_inc(&dev->power.usage_count);
rpm_resume(dev, 0);
}
}
else {
if (old_use && old_delay < 0)
atomic_dec(&dev->power.usage_count);
rpm_idle(dev, RPM_AUTO);
}
}
void pm_runtime_set_autosuspend_delay(struct device *dev, int delay)
{
int old_delay, old_use;
spin_lock_irq(&dev->power.lock);
old_delay = dev->power.autosuspend_delay;
old_use = dev->power.use_autosuspend;
dev->power.autosuspend_delay = delay;
update_autosuspend(dev, old_delay, old_use);
spin_unlock_irq(&dev->power.lock);
}
void __pm_runtime_use_autosuspend(struct device *dev, bool use)
{
int old_delay, old_use;
spin_lock_irq(&dev->power.lock);
old_delay = dev->power.autosuspend_delay;
old_use = dev->power.use_autosuspend;
dev->power.use_autosuspend = use;
update_autosuspend(dev, old_delay, old_use);
spin_unlock_irq(&dev->power.lock);
}
void pm_runtime_init(struct device *dev)
{
dev->power.runtime_status = RPM_SUSPENDED;
dev->power.idle_notification = false;
dev->power.disable_depth = 1;
atomic_set(&dev->power.usage_count, 0);
dev->power.runtime_error = 0;
atomic_set(&dev->power.child_count, 0);
pm_suspend_ignore_children(dev, false);
dev->power.runtime_auto = true;
dev->power.request_pending = false;
dev->power.request = RPM_REQ_NONE;
dev->power.deferred_resume = false;
dev->power.accounting_timestamp = jiffies;
INIT_WORK(&dev->power.work, pm_runtime_work);
dev->power.timer_expires = 0;
setup_timer(&dev->power.suspend_timer, pm_suspend_timer_fn,
(unsigned long)dev);
init_waitqueue_head(&dev->power.wait_queue);
}
void pm_runtime_remove(struct device *dev)
{
__pm_runtime_disable(dev, false);
if (dev->power.runtime_status == RPM_ACTIVE)
pm_runtime_set_suspended(dev);
if (dev->power.irq_safe && dev->parent)
pm_runtime_put_sync(dev->parent);
}
