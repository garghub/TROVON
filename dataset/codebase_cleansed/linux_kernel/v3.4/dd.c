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
list_add(&dev->p->deferred_probe, &deferred_probe_pending_list);
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
list_splice_tail_init(&deferred_probe_pending_list,
&deferred_probe_active_list);
mutex_unlock(&deferred_probe_mutex);
queue_work(deferred_wq, &deferred_probe_work);
}
static int deferred_probe_initcall(void)
{
deferred_wq = create_singlethread_workqueue("deferwq");
if (WARN_ON(!deferred_wq))
return -ENOMEM;
driver_deferred_probe_enable = true;
driver_deferred_probe_trigger();
return 0;
}
static void driver_bound(struct device *dev)
{
if (klist_node_attached(&dev->p->knode_driver)) {
printk(KERN_WARNING "%s: device %s already bound\n",
__func__, kobject_name(&dev->kobj));
return;
}
pr_debug("driver: '%s': %s: bound to device '%s'\n", dev_name(dev),
__func__, dev->driver->name);
klist_add_tail(&dev->p->knode_driver, &dev->driver->p->klist_devices);
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
return ret;
}
static int really_probe(struct device *dev, struct device_driver *drv)
{
int ret = 0;
atomic_inc(&probe_count);
pr_debug("bus: '%s': %s: probing driver %s with device %s\n",
drv->bus->name, __func__, drv->name, dev_name(dev));
WARN_ON(!list_empty(&dev->devres_head));
dev->driver = drv;
if (driver_sysfs_add(dev)) {
printk(KERN_ERR "%s: driver_sysfs_add(%s) failed\n",
__func__, dev_name(dev));
goto probe_failed;
}
if (dev->bus->probe) {
ret = dev->bus->probe(dev);
if (ret)
goto probe_failed;
} else if (drv->probe) {
ret = drv->probe(dev);
if (ret)
goto probe_failed;
}
driver_bound(dev);
ret = 1;
pr_debug("bus: '%s': %s: bound device %s to driver %s\n",
drv->bus->name, __func__, dev_name(dev), drv->name);
goto done;
probe_failed:
devres_release_all(dev);
driver_sysfs_remove(dev);
dev->driver = NULL;
if (ret == -EPROBE_DEFER) {
dev_info(dev, "Driver %s requests probe deferral\n", drv->name);
driver_deferred_probe_add(dev);
} else if (ret != -ENODEV && ret != -ENXIO) {
printk(KERN_WARNING
"%s: probe of %s failed with error %d\n",
drv->name, dev_name(dev), ret);
} else {
pr_debug("%s: probe of %s rejects match %d\n",
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
pm_runtime_get_noresume(dev);
pm_runtime_barrier(dev);
ret = really_probe(dev, drv);
pm_runtime_put_sync(dev);
return ret;
}
static int __device_attach(struct device_driver *drv, void *data)
{
struct device *dev = data;
if (!driver_match_device(drv, dev))
return 0;
return driver_probe_device(drv, dev);
}
int device_attach(struct device *dev)
{
int ret = 0;
device_lock(dev);
if (dev->driver) {
if (klist_node_attached(&dev->p->knode_driver)) {
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
pm_runtime_get_noresume(dev);
ret = bus_for_each_drv(dev->bus, NULL, dev, __device_attach);
pm_runtime_put_sync(dev);
}
out_unlock:
device_unlock(dev);
return ret;
}
static int __driver_attach(struct device *dev, void *data)
{
struct device_driver *drv = data;
if (!driver_match_device(drv, dev))
return 0;
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
static void __device_release_driver(struct device *dev)
{
struct device_driver *drv;
drv = dev->driver;
if (drv) {
pm_runtime_get_sync(dev);
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
devres_release_all(dev);
dev->driver = NULL;
klist_remove(&dev->p->knode_driver);
if (dev->bus)
blocking_notifier_call_chain(&dev->bus->p->bus_notifier,
BUS_NOTIFY_UNBOUND_DRIVER,
dev);
}
}
void device_release_driver(struct device *dev)
{
device_lock(dev);
__device_release_driver(dev);
device_unlock(dev);
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
if (dev->parent)
device_lock(dev->parent);
device_lock(dev);
if (dev->driver == drv)
__device_release_driver(dev);
device_unlock(dev);
if (dev->parent)
device_unlock(dev->parent);
put_device(dev);
}
}
void *dev_get_drvdata(const struct device *dev)
{
if (dev && dev->p)
return dev->p->driver_data;
return NULL;
}
int dev_set_drvdata(struct device *dev, void *data)
{
int error;
if (!dev->p) {
error = device_private_init(dev);
if (error)
return error;
}
dev->p->driver_data = data;
return 0;
}
