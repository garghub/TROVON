static void deferred_probe_work_func(struct work_struct *work)
{
struct device *dev;
struct device_private *private;
mutex_lock(&deferred_probe_mutex);
while (!list_empty(&deferred_probe_active_list)) {
private = list_first_entry(&deferred_probe_active_list,
typeof(*dev->p), deferred_probe);
dev = private->device;
list_del_init(&private->deferred_probe);
get_device(dev);
mutex_unlock(&deferred_probe_mutex);
device_pm_lock();
device_pm_move_last(dev);
device_pm_unlock();
dev_dbg(dev, "Retrying from deferred list\n");
bus_probe_device(dev);
mutex_lock(&deferred_probe_mutex);
put_device(dev);
}
mutex_unlock(&deferred_probe_mutex);
}
static void driver_deferred_probe_add(struct device *dev)
{
mutex_lock(&deferred_probe_mutex);
if (list_empty(&dev->p->deferred_probe)) {
dev_dbg(dev, "Added to deferred list\n");
list_add_tail(&dev->p->deferred_probe, &deferred_probe_pending_list);
}
mutex_unlock(&deferred_probe_mutex);
}
void driver_deferred_probe_del(struct device *dev)
{
mutex_lock(&deferred_probe_mutex);
if (!list_empty(&dev->p->deferred_probe)) {
dev_dbg(dev, "Removed from deferred list\n");
list_del_init(&dev->p->deferred_probe);
}
mutex_unlock(&deferred_probe_mutex);
}
static void driver_deferred_probe_trigger(void)
{
if (!driver_deferred_probe_enable)
return;
mutex_lock(&deferred_probe_mutex);
atomic_inc(&deferred_trigger_count);
list_splice_tail_init(&deferred_probe_pending_list,
&deferred_probe_active_list);
mutex_unlock(&deferred_probe_mutex);
schedule_work(&deferred_probe_work);
}
void device_block_probing(void)
{
defer_all_probes = true;
wait_for_device_probe();
}
void device_unblock_probing(void)
{
defer_all_probes = false;
driver_deferred_probe_trigger();
}
static int deferred_probe_initcall(void)
{
driver_deferred_probe_enable = true;
driver_deferred_probe_trigger();
flush_work(&deferred_probe_work);
return 0;
}
bool device_is_bound(struct device *dev)
{
return dev->p && klist_node_attached(&dev->p->knode_driver);
}
static void driver_bound(struct device *dev)
{
if (device_is_bound(dev)) {
printk(KERN_WARNING "%s: device %s already bound\n",
__func__, kobject_name(&dev->kobj));
return;
}
pr_debug("driver: '%s': %s: bound to device '%s'\n", dev->driver->name,
__func__, dev_name(dev));
klist_add_tail(&dev->p->knode_driver, &dev->driver->p->klist_devices);
device_links_driver_bound(dev);
device_pm_check_callbacks(dev);
driver_deferred_probe_del(dev);
driver_deferred_probe_trigger();
if (dev->bus)
blocking_notifier_call_chain(&dev->bus->p->bus_notifier,
BUS_NOTIFY_BOUND_DRIVER, dev);
}
static int driver_sysfs_add(struct device *dev)
{
int ret;
if (dev->bus)
blocking_notifier_call_chain(&dev->bus->p->bus_notifier,
BUS_NOTIFY_BIND_DRIVER, dev);
ret = sysfs_create_link(&dev->driver->p->kobj, &dev->kobj,
kobject_name(&dev->kobj));
if (ret == 0) {
ret = sysfs_create_link(&dev->kobj, &dev->driver->p->kobj,
"driver");
if (ret)
sysfs_remove_link(&dev->driver->p->kobj,
kobject_name(&dev->kobj));
}
return ret;
}
static void driver_sysfs_remove(struct device *dev)
{
struct device_driver *drv = dev->driver;
if (drv) {
sysfs_remove_link(&drv->p->kobj, kobject_name(&dev->kobj));
sysfs_remove_link(&dev->kobj, "driver");
}
}
int device_bind_driver(struct device *dev)
{
int ret;
ret = driver_sysfs_add(dev);
if (!ret)
driver_bound(dev);
else if (dev->bus)
blocking_notifier_call_chain(&dev->bus->p->bus_notifier,
BUS_NOTIFY_DRIVER_NOT_BOUND, dev);
return ret;
}
static int really_probe(struct device *dev, struct device_driver *drv)
{
int ret = -EPROBE_DEFER;
int local_trigger_count = atomic_read(&deferred_trigger_count);
bool test_remove = IS_ENABLED(CONFIG_DEBUG_TEST_DRIVER_REMOVE) &&
!drv->suppress_bind_attrs;
if (defer_all_probes) {
dev_dbg(dev, "Driver %s force probe deferral\n", drv->name);
driver_deferred_probe_add(dev);
return ret;
}
ret = device_links_check_suppliers(dev);
if (ret)
return ret;
atomic_inc(&probe_count);
pr_debug("bus: '%s': %s: probing driver %s with device %s\n",
drv->bus->name, __func__, drv->name, dev_name(dev));
WARN_ON(!list_empty(&dev->devres_head));
re_probe:
dev->driver = drv;
ret = pinctrl_bind_pins(dev);
if (ret)
goto pinctrl_bind_failed;
ret = dma_configure(dev);
if (ret)
goto dma_failed;
if (driver_sysfs_add(dev)) {
printk(KERN_ERR "%s: driver_sysfs_add(%s) failed\n",
__func__, dev_name(dev));
goto probe_failed;
}
if (dev->pm_domain && dev->pm_domain->activate) {
ret = dev->pm_domain->activate(dev);
if (ret)
goto probe_failed;
}
devices_kset_move_last(dev);
if (dev->bus->probe) {
ret = dev->bus->probe(dev);
if (ret)
goto probe_failed;
} else if (drv->probe) {
ret = drv->probe(dev);
if (ret)
goto probe_failed;
}
if (test_remove) {
test_remove = false;
if (dev->bus->remove)
dev->bus->remove(dev);
else if (drv->remove)
drv->remove(dev);
devres_release_all(dev);
driver_sysfs_remove(dev);
dev->driver = NULL;
dev_set_drvdata(dev, NULL);
if (dev->pm_domain && dev->pm_domain->dismiss)
dev->pm_domain->dismiss(dev);
pm_runtime_reinit(dev);
goto re_probe;
}
pinctrl_init_done(dev);
if (dev->pm_domain && dev->pm_domain->sync)
dev->pm_domain->sync(dev);
driver_bound(dev);
ret = 1;
pr_debug("bus: '%s': %s: bound device %s to driver %s\n",
drv->bus->name, __func__, dev_name(dev), drv->name);
goto done;
probe_failed:
dma_deconfigure(dev);
dma_failed:
if (dev->bus)
blocking_notifier_call_chain(&dev->bus->p->bus_notifier,
BUS_NOTIFY_DRIVER_NOT_BOUND, dev);
pinctrl_bind_failed:
device_links_no_driver(dev);
devres_release_all(dev);
driver_sysfs_remove(dev);
dev->driver = NULL;
dev_set_drvdata(dev, NULL);
if (dev->pm_domain && dev->pm_domain->dismiss)
dev->pm_domain->dismiss(dev);
pm_runtime_reinit(dev);
switch (ret) {
case -EPROBE_DEFER:
dev_dbg(dev, "Driver %s requests probe deferral\n", drv->name);
driver_deferred_probe_add(dev);
if (local_trigger_count != atomic_read(&deferred_trigger_count))
driver_deferred_probe_trigger();
break;
case -ENODEV:
case -ENXIO:
pr_debug("%s: probe of %s rejects match %d\n",
drv->name, dev_name(dev), ret);
break;
default:
printk(KERN_WARNING
"%s: probe of %s failed with error %d\n",
drv->name, dev_name(dev), ret);
}
ret = 0;
done:
atomic_dec(&probe_count);
wake_up(&probe_waitqueue);
return ret;
}
int driver_probe_done(void)
{
pr_debug("%s: probe_count = %d\n", __func__,
atomic_read(&probe_count));
if (atomic_read(&probe_count))
return -EBUSY;
return 0;
}
void wait_for_device_probe(void)
{
flush_work(&deferred_probe_work);
wait_event(probe_waitqueue, atomic_read(&probe_count) == 0);
async_synchronize_full();
}
int driver_probe_device(struct device_driver *drv, struct device *dev)
{
int ret = 0;
if (!device_is_registered(dev))
return -ENODEV;
pr_debug("bus: '%s': %s: matched device %s with driver %s\n",
drv->bus->name, __func__, dev_name(dev), drv->name);
pm_runtime_get_suppliers(dev);
if (dev->parent)
pm_runtime_get_sync(dev->parent);
pm_runtime_barrier(dev);
ret = really_probe(dev, drv);
pm_request_idle(dev);
if (dev->parent)
pm_runtime_put(dev->parent);
pm_runtime_put_suppliers(dev);
return ret;
}
bool driver_allows_async_probing(struct device_driver *drv)
{
switch (drv->probe_type) {
case PROBE_PREFER_ASYNCHRONOUS:
return true;
case PROBE_FORCE_SYNCHRONOUS:
return false;
default:
if (module_requested_async_probing(drv->owner))
return true;
return false;
}
}
static int __device_attach_driver(struct device_driver *drv, void *_data)
{
struct device_attach_data *data = _data;
struct device *dev = data->dev;
bool async_allowed;
int ret;
if (dev->driver)
return -EBUSY;
ret = driver_match_device(drv, dev);
if (ret == 0) {
return 0;
} else if (ret == -EPROBE_DEFER) {
dev_dbg(dev, "Device match requests probe deferral\n");
driver_deferred_probe_add(dev);
} else if (ret < 0) {
dev_dbg(dev, "Bus failed to match device: %d", ret);
return ret;
}
async_allowed = driver_allows_async_probing(drv);
if (async_allowed)
data->have_async = true;
if (data->check_async && async_allowed != data->want_async)
return 0;
return driver_probe_device(drv, dev);
}
static void __device_attach_async_helper(void *_dev, async_cookie_t cookie)
{
struct device *dev = _dev;
struct device_attach_data data = {
.dev = dev,
.check_async = true,
.want_async = true,
};
device_lock(dev);
if (dev->parent)
pm_runtime_get_sync(dev->parent);
bus_for_each_drv(dev->bus, NULL, &data, __device_attach_driver);
dev_dbg(dev, "async probe completed\n");
pm_request_idle(dev);
if (dev->parent)
pm_runtime_put(dev->parent);
device_unlock(dev);
put_device(dev);
}
static int __device_attach(struct device *dev, bool allow_async)
{
int ret = 0;
device_lock(dev);
if (dev->driver) {
if (device_is_bound(dev)) {
ret = 1;
goto out_unlock;
}
ret = device_bind_driver(dev);
if (ret == 0)
ret = 1;
else {
dev->driver = NULL;
ret = 0;
}
} else {
struct device_attach_data data = {
.dev = dev,
.check_async = allow_async,
.want_async = false,
};
if (dev->parent)
pm_runtime_get_sync(dev->parent);
ret = bus_for_each_drv(dev->bus, NULL, &data,
__device_attach_driver);
if (!ret && allow_async && data.have_async) {
dev_dbg(dev, "scheduling asynchronous probe\n");
get_device(dev);
async_schedule(__device_attach_async_helper, dev);
} else {
pm_request_idle(dev);
}
if (dev->parent)
pm_runtime_put(dev->parent);
}
out_unlock:
device_unlock(dev);
return ret;
}
int device_attach(struct device *dev)
{
return __device_attach(dev, false);
}
void device_initial_probe(struct device *dev)
{
__device_attach(dev, true);
}
static int __driver_attach(struct device *dev, void *data)
{
struct device_driver *drv = data;
int ret;
ret = driver_match_device(drv, dev);
if (ret == 0) {
return 0;
} else if (ret == -EPROBE_DEFER) {
dev_dbg(dev, "Device match requests probe deferral\n");
driver_deferred_probe_add(dev);
} else if (ret < 0) {
dev_dbg(dev, "Bus failed to match device: %d", ret);
return ret;
}
if (dev->parent)
device_lock(dev->parent);
device_lock(dev);
if (!dev->driver)
driver_probe_device(drv, dev);
device_unlock(dev);
if (dev->parent)
device_unlock(dev->parent);
return 0;
}
int driver_attach(struct device_driver *drv)
{
return bus_for_each_dev(drv->bus, NULL, drv, __driver_attach);
}
static void __device_release_driver(struct device *dev, struct device *parent)
{
struct device_driver *drv;
drv = dev->driver;
if (drv) {
if (driver_allows_async_probing(drv))
async_synchronize_full();
while (device_links_busy(dev)) {
device_unlock(dev);
if (parent)
device_unlock(parent);
device_links_unbind_consumers(dev);
if (parent)
device_lock(parent);
device_lock(dev);
if (dev->driver != drv)
return;
}
pm_runtime_get_sync(dev);
pm_runtime_clean_up_links(dev);
driver_sysfs_remove(dev);
if (dev->bus)
blocking_notifier_call_chain(&dev->bus->p->bus_notifier,
BUS_NOTIFY_UNBIND_DRIVER,
dev);
pm_runtime_put_sync(dev);
if (dev->bus && dev->bus->remove)
dev->bus->remove(dev);
else if (drv->remove)
drv->remove(dev);
device_links_driver_cleanup(dev);
dma_deconfigure(dev);
devres_release_all(dev);
dev->driver = NULL;
dev_set_drvdata(dev, NULL);
if (dev->pm_domain && dev->pm_domain->dismiss)
dev->pm_domain->dismiss(dev);
pm_runtime_reinit(dev);
klist_remove(&dev->p->knode_driver);
device_pm_check_callbacks(dev);
if (dev->bus)
blocking_notifier_call_chain(&dev->bus->p->bus_notifier,
BUS_NOTIFY_UNBOUND_DRIVER,
dev);
}
}
void device_release_driver_internal(struct device *dev,
struct device_driver *drv,
struct device *parent)
{
if (parent)
device_lock(parent);
device_lock(dev);
if (!drv || drv == dev->driver)
__device_release_driver(dev, parent);
device_unlock(dev);
if (parent)
device_unlock(parent);
}
void device_release_driver(struct device *dev)
{
device_release_driver_internal(dev, NULL, NULL);
}
void driver_detach(struct device_driver *drv)
{
struct device_private *dev_prv;
struct device *dev;
for (;;) {
spin_lock(&drv->p->klist_devices.k_lock);
if (list_empty(&drv->p->klist_devices.k_list)) {
spin_unlock(&drv->p->klist_devices.k_lock);
break;
}
dev_prv = list_entry(drv->p->klist_devices.k_list.prev,
struct device_private,
knode_driver.n_node);
dev = dev_prv->device;
get_device(dev);
spin_unlock(&drv->p->klist_devices.k_lock);
device_release_driver_internal(dev, drv, dev->parent);
put_device(dev);
}
}
