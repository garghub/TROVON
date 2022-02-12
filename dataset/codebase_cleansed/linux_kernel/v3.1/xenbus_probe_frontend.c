static int frontend_bus_id(char bus_id[XEN_BUS_ID_SIZE], const char *nodename)
{
nodename = strchr(nodename, '/');
if (!nodename || strlen(nodename + 1) >= XEN_BUS_ID_SIZE) {
printk(KERN_WARNING "XENBUS: bad frontend %s\n", nodename);
return -EINVAL;
}
strlcpy(bus_id, nodename + 1, XEN_BUS_ID_SIZE);
if (!strchr(bus_id, '/')) {
printk(KERN_WARNING "XENBUS: bus_id %s no slash\n", bus_id);
return -EINVAL;
}
*strchr(bus_id, '/') = '-';
return 0;
}
static int xenbus_probe_frontend(struct xen_bus_type *bus, const char *type,
const char *name)
{
char *nodename;
int err;
nodename = kasprintf(GFP_KERNEL, "%s/%s/%s", bus->root, type, name);
if (!nodename)
return -ENOMEM;
DPRINTK("%s", nodename);
err = xenbus_probe_node(bus, type, nodename);
kfree(nodename);
return err;
}
static int xenbus_uevent_frontend(struct device *_dev,
struct kobj_uevent_env *env)
{
struct xenbus_device *dev = to_xenbus_device(_dev);
if (add_uevent_var(env, "MODALIAS=xen:%s", dev->devicetype))
return -ENOMEM;
return 0;
}
static void backend_changed(struct xenbus_watch *watch,
const char **vec, unsigned int len)
{
xenbus_otherend_changed(watch, vec, len, 1);
}
static void frontend_changed(struct xenbus_watch *watch,
const char **vec, unsigned int len)
{
DPRINTK("");
xenbus_dev_changed(vec[XS_WATCH_PATH], &xenbus_frontend);
}
static int read_backend_details(struct xenbus_device *xendev)
{
return xenbus_read_otherend_details(xendev, "backend-id", "backend");
}
static int is_device_connecting(struct device *dev, void *data)
{
struct xenbus_device *xendev = to_xenbus_device(dev);
struct device_driver *drv = data;
struct xenbus_driver *xendrv;
if (!dev->driver)
return 0;
if (drv && (dev->driver != drv))
return 0;
xendrv = to_xenbus_driver(dev->driver);
return (xendev->state < XenbusStateConnected ||
(xendev->state == XenbusStateConnected &&
xendrv->is_ready && !xendrv->is_ready(xendev)));
}
static int exists_connecting_device(struct device_driver *drv)
{
return bus_for_each_dev(&xenbus_frontend.bus, NULL, drv,
is_device_connecting);
}
static int print_device_status(struct device *dev, void *data)
{
struct xenbus_device *xendev = to_xenbus_device(dev);
struct device_driver *drv = data;
if (drv && (dev->driver != drv))
return 0;
if (!dev->driver) {
printk(KERN_INFO "XENBUS: Device with no driver: %s\n",
xendev->nodename);
} else if (xendev->state < XenbusStateConnected) {
enum xenbus_state rstate = XenbusStateUnknown;
if (xendev->otherend)
rstate = xenbus_read_driver_state(xendev->otherend);
printk(KERN_WARNING "XENBUS: Timeout connecting "
"to device: %s (local state %d, remote state %d)\n",
xendev->nodename, xendev->state, rstate);
}
return 0;
}
static void wait_for_devices(struct xenbus_driver *xendrv)
{
unsigned long start = jiffies;
struct device_driver *drv = xendrv ? &xendrv->driver : NULL;
unsigned int seconds_waited = 0;
if (!ready_to_wait_for_devices || !xen_domain())
return;
while (exists_connecting_device(drv)) {
if (time_after(jiffies, start + (seconds_waited+5)*HZ)) {
if (!seconds_waited)
printk(KERN_WARNING "XENBUS: Waiting for "
"devices to initialise: ");
seconds_waited += 5;
printk("%us...", 300 - seconds_waited);
if (seconds_waited == 300)
break;
}
schedule_timeout_interruptible(HZ/10);
}
if (seconds_waited)
printk("\n");
bus_for_each_dev(&xenbus_frontend.bus, NULL, drv,
print_device_status);
}
int __xenbus_register_frontend(struct xenbus_driver *drv,
struct module *owner, const char *mod_name)
{
int ret;
drv->read_otherend_details = read_backend_details;
ret = xenbus_register_driver_common(drv, &xenbus_frontend,
owner, mod_name);
if (ret)
return ret;
wait_for_devices(drv);
return 0;
}
static int frontend_probe_and_watch(struct notifier_block *notifier,
unsigned long event,
void *data)
{
xenbus_probe_devices(&xenbus_frontend);
register_xenbus_watch(&fe_watch);
return NOTIFY_DONE;
}
static int __init xenbus_probe_frontend_init(void)
{
static struct notifier_block xenstore_notifier = {
.notifier_call = frontend_probe_and_watch
};
int err;
DPRINTK("");
err = bus_register(&xenbus_frontend.bus);
if (err)
return err;
register_xenstore_notifier(&xenstore_notifier);
return 0;
}
static int __init boot_wait_for_devices(void)
{
if (xen_hvm_domain() && !xen_platform_pci_unplug)
return -ENODEV;
ready_to_wait_for_devices = 1;
wait_for_devices(NULL);
return 0;
}
