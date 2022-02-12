static pm_callback_t __rpm_get_callback(struct device *dev, size_t cb_offset)
{
pm_callback_t cb;
const struct dev_pm_ops *ops;
if (dev->pm_domain)
ops = &dev->pm_domain->ops;
else if (dev->type && dev->type->pm)
ops = dev->type->pm;
else if (dev->class && dev->class->pm)
ops = dev->class->pm;
else if (dev->bus && dev->bus->pm)
ops = dev->bus->pm;
else
ops = NULL;
if (ops)
cb = *(pm_callback_t *)((void *)ops + cb_offset);
else
cb = NULL;
if (!cb && dev->driver && dev->driver->pm)
cb = *(pm_callback_t *)((void *)dev->driver->pm + cb_offset);
return cb;
}
void update_pm_runtime_accounting(struct device *dev)
{
unsigned long now = jiffies;
unsigned long delta;
delta = now - dev->power.accounting_timestamp;
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
static int dev_memalloc_noio(struct device *dev, void *data)
{
return dev->power.memalloc_noio;
}
void pm_runtime_set_memalloc_noio(struct device *dev, bool enable)
{
static DEFINE_MUTEX(dev_hotplug_mutex);
mutex_lock(&dev_hotplug_mutex);
for (;;) {
bool enabled;
spin_lock_irq(&dev->power.lock);
enabled = dev->power.memalloc_noio;
dev->power.memalloc_noio = enable;
spin_unlock_irq(&dev->power.lock);
if (enabled && enable)
break;
dev = dev->parent;
if (!dev || (!enable &&
device_for_each_child(dev, NULL,
dev_memalloc_noio)))
break;
}
mutex_unlock(&dev_hotplug_mutex);
}
static int rpm_check_suspend_allowed(struct device *dev)
{
int retval = 0;
if (dev->power.runtime_error)
retval = -EINVAL;
else if (dev->power.disable_depth > 0)
retval = -EACCES;
else if (atomic_read(&dev->power.usage_count) > 0)
retval = -EAGAIN;
else if (!dev->power.ignore_children &&
atomic_read(&dev->power.child_count))
retval = -EBUSY;
else if ((dev->power.deferred_resume
&& dev->power.runtime_status == RPM_SUSPENDING)
|| (dev->power.request_pending
&& dev->power.request == RPM_REQ_RESUME))
retval = -EAGAIN;
else if (__dev_pm_qos_read_value(dev) < 0)
retval = -EPERM;
else if (dev->power.runtime_status == RPM_SUSPENDED)
retval = 1;
return retval;
}
static int rpm_get_suppliers(struct device *dev)
{
struct device_link *link;
list_for_each_entry_rcu(link, &dev->links.suppliers, c_node) {
int retval;
if (!(link->flags & DL_FLAG_PM_RUNTIME))
continue;
if (READ_ONCE(link->status) == DL_STATE_SUPPLIER_UNBIND ||
link->rpm_active)
continue;
retval = pm_runtime_get_sync(link->supplier);
if (retval < 0) {
pm_runtime_put_noidle(link->supplier);
return retval;
}
link->rpm_active = true;
}
return 0;
}
static void rpm_put_suppliers(struct device *dev)
{
struct device_link *link;
list_for_each_entry_rcu(link, &dev->links.suppliers, c_node)
if (link->rpm_active &&
READ_ONCE(link->status) != DL_STATE_SUPPLIER_UNBIND) {
pm_runtime_put(link->supplier);
link->rpm_active = false;
}
}
static int __rpm_callback(int (*cb)(struct device *), struct device *dev)
__releases(&dev->power.lock
static int rpm_idle(struct device *dev, int rpmflags)
{
int (*callback)(struct device *);
int retval;
trace_rpm_idle_rcuidle(dev, rpmflags);
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
if (dev->power.no_callbacks)
goto out;
if (rpmflags & RPM_ASYNC) {
dev->power.request = RPM_REQ_IDLE;
if (!dev->power.request_pending) {
dev->power.request_pending = true;
queue_work(pm_wq, &dev->power.work);
}
trace_rpm_return_int_rcuidle(dev, _THIS_IP_, 0);
return 0;
}
dev->power.idle_notification = true;
callback = RPM_GET_CALLBACK(dev, runtime_idle);
if (callback)
retval = __rpm_callback(callback, dev);
dev->power.idle_notification = false;
wake_up_all(&dev->power.wait_queue);
out:
trace_rpm_return_int_rcuidle(dev, _THIS_IP_, retval);
return retval ? retval : rpm_suspend(dev, rpmflags | RPM_AUTO);
}
static int rpm_callback(int (*cb)(struct device *), struct device *dev)
{
int retval;
if (!cb)
return -ENOSYS;
if (dev->power.memalloc_noio) {
unsigned int noio_flag;
noio_flag = memalloc_noio_save();
retval = __rpm_callback(cb, dev);
memalloc_noio_restore(noio_flag);
} else {
retval = __rpm_callback(cb, dev);
}
dev->power.runtime_error = retval;
return retval != -EACCES ? retval : -EIO;
}
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
might_sleep_if(!(rpmflags & RPM_ASYNC) && !dev->power.irq_safe);
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
might_sleep_if(!(rpmflags & RPM_ASYNC) && !dev->power.irq_safe);
spin_lock_irqsave(&dev->power.lock, flags);
retval = rpm_suspend(dev, rpmflags);
spin_unlock_irqrestore(&dev->power.lock, flags);
return retval;
}
int __pm_runtime_resume(struct device *dev, int rpmflags)
{
unsigned long flags;
int retval;
might_sleep_if(!(rpmflags & RPM_ASYNC) && !dev->power.irq_safe &&
dev->power.runtime_status != RPM_ACTIVE);
if (rpmflags & RPM_GET_PUT)
atomic_inc(&dev->power.usage_count);
spin_lock_irqsave(&dev->power.lock, flags);
retval = rpm_resume(dev, rpmflags);
spin_unlock_irqrestore(&dev->power.lock, flags);
return retval;
}
int pm_runtime_get_if_in_use(struct device *dev)
{
unsigned long flags;
int retval;
spin_lock_irqsave(&dev->power.lock, flags);
retval = dev->power.disable_depth > 0 ? -EINVAL :
dev->power.runtime_status == RPM_ACTIVE
&& atomic_inc_not_zero(&dev->power.usage_count);
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
if (!dev->power.ignore_children &&
atomic_read(&dev->power.child_count)) {
dev_err(dev, "runtime PM trying to suspend device but active child\n");
error = -EBUSY;
goto out;
}
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
&& parent->power.runtime_status != RPM_ACTIVE) {
dev_err(dev, "runtime PM trying to activate child device %s but parent (%s) is not active\n",
dev_name(dev),
dev_name(parent));
error = -EBUSY;
} else if (dev->power.runtime_status == RPM_SUSPENDED) {
atomic_inc(&parent->power.child_count);
}
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
rpm_idle(dev, RPM_AUTO | RPM_ASYNC);
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
void pm_runtime_reinit(struct device *dev)
{
if (!pm_runtime_enabled(dev)) {
if (dev->power.runtime_status == RPM_ACTIVE)
pm_runtime_set_suspended(dev);
if (dev->power.irq_safe) {
spin_lock_irq(&dev->power.lock);
dev->power.irq_safe = 0;
spin_unlock_irq(&dev->power.lock);
if (dev->parent)
pm_runtime_put(dev->parent);
}
}
}
void pm_runtime_remove(struct device *dev)
{
__pm_runtime_disable(dev, false);
pm_runtime_reinit(dev);
}
void pm_runtime_clean_up_links(struct device *dev)
{
struct device_link *link;
int idx;
idx = device_links_read_lock();
list_for_each_entry_rcu(link, &dev->links.consumers, s_node) {
if (link->flags & DL_FLAG_STATELESS)
continue;
if (link->rpm_active) {
pm_runtime_put_noidle(dev);
link->rpm_active = false;
}
}
device_links_read_unlock(idx);
}
void pm_runtime_get_suppliers(struct device *dev)
{
struct device_link *link;
int idx;
idx = device_links_read_lock();
list_for_each_entry_rcu(link, &dev->links.suppliers, c_node)
if (link->flags & DL_FLAG_PM_RUNTIME)
pm_runtime_get_sync(link->supplier);
device_links_read_unlock(idx);
}
void pm_runtime_put_suppliers(struct device *dev)
{
struct device_link *link;
int idx;
idx = device_links_read_lock();
list_for_each_entry_rcu(link, &dev->links.suppliers, c_node)
if (link->flags & DL_FLAG_PM_RUNTIME)
pm_runtime_put(link->supplier);
device_links_read_unlock(idx);
}
void pm_runtime_new_link(struct device *dev)
{
spin_lock_irq(&dev->power.lock);
dev->power.links_count++;
spin_unlock_irq(&dev->power.lock);
}
void pm_runtime_drop_link(struct device *dev)
{
spin_lock_irq(&dev->power.lock);
WARN_ON(dev->power.links_count == 0);
dev->power.links_count--;
spin_unlock_irq(&dev->power.lock);
}
int pm_runtime_force_suspend(struct device *dev)
{
int (*callback)(struct device *);
int ret = 0;
pm_runtime_disable(dev);
if (pm_runtime_status_suspended(dev))
return 0;
callback = RPM_GET_CALLBACK(dev, runtime_suspend);
if (!callback) {
ret = -ENOSYS;
goto err;
}
ret = callback(dev);
if (ret)
goto err;
if (dev->parent && atomic_read(&dev->power.usage_count) > 1)
pm_runtime_get_noresume(dev->parent);
pm_runtime_set_suspended(dev);
return 0;
err:
pm_runtime_enable(dev);
return ret;
}
int pm_runtime_force_resume(struct device *dev)
{
int (*callback)(struct device *);
int ret = 0;
callback = RPM_GET_CALLBACK(dev, runtime_resume);
if (!callback) {
ret = -ENOSYS;
goto out;
}
if (!pm_runtime_status_suspended(dev))
goto out;
if (atomic_read(&dev->power.usage_count) > 1) {
if (dev->parent)
pm_runtime_put_noidle(dev->parent);
} else {
goto out;
}
ret = pm_runtime_set_active(dev);
if (ret)
goto out;
ret = callback(dev);
if (ret) {
pm_runtime_set_suspended(dev);
goto out;
}
pm_runtime_mark_last_busy(dev);
out:
pm_runtime_enable(dev);
return ret;
}
