static const struct xenbus_device_id *
match_device(const struct xenbus_device_id *arr, struct xenbus_device *dev)
{
for (; *arr->devicetype != '\0'; arr++) {
if (!strcmp(arr->devicetype, dev->devicetype))
return arr;
}
return NULL;
}
int xenbus_match(struct device *_dev, struct device_driver *_drv)
{
struct xenbus_driver *drv = to_xenbus_driver(_drv);
if (!drv->ids)
return 0;
return match_device(drv->ids, to_xenbus_device(_dev)) != NULL;
}
static void free_otherend_details(struct xenbus_device *dev)
{
kfree(dev->otherend);
dev->otherend = NULL;
}
static void free_otherend_watch(struct xenbus_device *dev)
{
if (dev->otherend_watch.node) {
unregister_xenbus_watch(&dev->otherend_watch);
kfree(dev->otherend_watch.node);
dev->otherend_watch.node = NULL;
}
}
static int talk_to_otherend(struct xenbus_device *dev)
{
struct xenbus_driver *drv = to_xenbus_driver(dev->dev.driver);
free_otherend_watch(dev);
free_otherend_details(dev);
return drv->read_otherend_details(dev);
}
static int watch_otherend(struct xenbus_device *dev)
{
struct xen_bus_type *bus =
container_of(dev->dev.bus, struct xen_bus_type, bus);
return xenbus_watch_pathfmt(dev, &dev->otherend_watch,
bus->otherend_changed,
"%s/%s", dev->otherend, "state");
}
int xenbus_read_otherend_details(struct xenbus_device *xendev,
char *id_node, char *path_node)
{
int err = xenbus_gather(XBT_NIL, xendev->nodename,
id_node, "%i", &xendev->otherend_id,
path_node, NULL, &xendev->otherend,
NULL);
if (err) {
xenbus_dev_fatal(xendev, err,
"reading other end details from %s",
xendev->nodename);
return err;
}
if (strlen(xendev->otherend) == 0 ||
!xenbus_exists(XBT_NIL, xendev->otherend, "")) {
xenbus_dev_fatal(xendev, -ENOENT,
"unable to read other end from %s. "
"missing or inaccessible.",
xendev->nodename);
free_otherend_details(xendev);
return -ENOENT;
}
return 0;
}
void xenbus_otherend_changed(struct xenbus_watch *watch,
const char **vec, unsigned int len,
int ignore_on_shutdown)
{
struct xenbus_device *dev =
container_of(watch, struct xenbus_device, otherend_watch);
struct xenbus_driver *drv = to_xenbus_driver(dev->dev.driver);
enum xenbus_state state;
if (!dev->otherend ||
strncmp(dev->otherend, vec[XS_WATCH_PATH],
strlen(dev->otherend))) {
dev_dbg(&dev->dev, "Ignoring watch at %s\n",
vec[XS_WATCH_PATH]);
return;
}
state = xenbus_read_driver_state(dev->otherend);
dev_dbg(&dev->dev, "state is %d, (%s), %s, %s\n",
state, xenbus_strstate(state), dev->otherend_watch.node,
vec[XS_WATCH_PATH]);
if (system_state > SYSTEM_RUNNING) {
if (ignore_on_shutdown && (state == XenbusStateClosing))
xenbus_frontend_closed(dev);
return;
}
if (drv->otherend_changed)
drv->otherend_changed(dev, state);
}
int xenbus_dev_probe(struct device *_dev)
{
struct xenbus_device *dev = to_xenbus_device(_dev);
struct xenbus_driver *drv = to_xenbus_driver(_dev->driver);
const struct xenbus_device_id *id;
int err;
DPRINTK("%s", dev->nodename);
if (!drv->probe) {
err = -ENODEV;
goto fail;
}
id = match_device(drv->ids, dev);
if (!id) {
err = -ENODEV;
goto fail;
}
err = talk_to_otherend(dev);
if (err) {
dev_warn(&dev->dev, "talk_to_otherend on %s failed.\n",
dev->nodename);
return err;
}
err = drv->probe(dev, id);
if (err)
goto fail;
err = watch_otherend(dev);
if (err) {
dev_warn(&dev->dev, "watch_otherend on %s failed.\n",
dev->nodename);
return err;
}
return 0;
fail:
xenbus_dev_error(dev, err, "xenbus_dev_probe on %s", dev->nodename);
xenbus_switch_state(dev, XenbusStateClosed);
return err;
}
int xenbus_dev_remove(struct device *_dev)
{
struct xenbus_device *dev = to_xenbus_device(_dev);
struct xenbus_driver *drv = to_xenbus_driver(_dev->driver);
DPRINTK("%s", dev->nodename);
free_otherend_watch(dev);
if (drv->remove)
drv->remove(dev);
free_otherend_details(dev);
xenbus_switch_state(dev, XenbusStateClosed);
return 0;
}
void xenbus_dev_shutdown(struct device *_dev)
{
struct xenbus_device *dev = to_xenbus_device(_dev);
unsigned long timeout = 5*HZ;
DPRINTK("%s", dev->nodename);
get_device(&dev->dev);
if (dev->state != XenbusStateConnected) {
printk(KERN_INFO "%s: %s: %s != Connected, skipping\n", __func__,
dev->nodename, xenbus_strstate(dev->state));
goto out;
}
xenbus_switch_state(dev, XenbusStateClosing);
timeout = wait_for_completion_timeout(&dev->down, timeout);
if (!timeout)
printk(KERN_INFO "%s: %s timeout closing device\n",
__func__, dev->nodename);
out:
put_device(&dev->dev);
}
int xenbus_register_driver_common(struct xenbus_driver *drv,
struct xen_bus_type *bus)
{
drv->driver.bus = &bus->bus;
return driver_register(&drv->driver);
}
void xenbus_unregister_driver(struct xenbus_driver *drv)
{
driver_unregister(&drv->driver);
}
static int cmp_dev(struct device *dev, void *data)
{
struct xenbus_device *xendev = to_xenbus_device(dev);
struct xb_find_info *info = data;
if (!strcmp(xendev->nodename, info->nodename)) {
info->dev = xendev;
get_device(dev);
return 1;
}
return 0;
}
static struct xenbus_device *xenbus_device_find(const char *nodename,
struct bus_type *bus)
{
struct xb_find_info info = { .dev = NULL, .nodename = nodename };
bus_for_each_dev(bus, NULL, &info, cmp_dev);
return info.dev;
}
static int cleanup_dev(struct device *dev, void *data)
{
struct xenbus_device *xendev = to_xenbus_device(dev);
struct xb_find_info *info = data;
int len = strlen(info->nodename);
DPRINTK("%s", info->nodename);
if (strncmp(xendev->nodename, info->nodename, len))
return 0;
if ((strlen(xendev->nodename) > len) && (xendev->nodename[len] != '/'))
return 0;
info->dev = xendev;
get_device(dev);
return 1;
}
static void xenbus_cleanup_devices(const char *path, struct bus_type *bus)
{
struct xb_find_info info = { .nodename = path };
do {
info.dev = NULL;
bus_for_each_dev(bus, NULL, &info, cleanup_dev);
if (info.dev) {
device_unregister(&info.dev->dev);
put_device(&info.dev->dev);
}
} while (info.dev);
}
static void xenbus_dev_release(struct device *dev)
{
if (dev)
kfree(to_xenbus_device(dev));
}
static ssize_t nodename_show(struct device *dev,
struct device_attribute *attr, char *buf)
{
return sprintf(buf, "%s\n", to_xenbus_device(dev)->nodename);
}
static ssize_t devtype_show(struct device *dev,
struct device_attribute *attr, char *buf)
{
return sprintf(buf, "%s\n", to_xenbus_device(dev)->devicetype);
}
static ssize_t modalias_show(struct device *dev,
struct device_attribute *attr, char *buf)
{
return sprintf(buf, "%s:%s\n", dev->bus->name,
to_xenbus_device(dev)->devicetype);
}
int xenbus_probe_node(struct xen_bus_type *bus,
const char *type,
const char *nodename)
{
char devname[XEN_BUS_ID_SIZE];
int err;
struct xenbus_device *xendev;
size_t stringlen;
char *tmpstring;
enum xenbus_state state = xenbus_read_driver_state(nodename);
if (state != XenbusStateInitialising) {
return 0;
}
stringlen = strlen(nodename) + 1 + strlen(type) + 1;
xendev = kzalloc(sizeof(*xendev) + stringlen, GFP_KERNEL);
if (!xendev)
return -ENOMEM;
xendev->state = XenbusStateInitialising;
tmpstring = (char *)(xendev + 1);
strcpy(tmpstring, nodename);
xendev->nodename = tmpstring;
tmpstring += strlen(tmpstring) + 1;
strcpy(tmpstring, type);
xendev->devicetype = tmpstring;
init_completion(&xendev->down);
xendev->dev.bus = &bus->bus;
xendev->dev.release = xenbus_dev_release;
err = bus->get_bus_id(devname, xendev->nodename);
if (err)
goto fail;
dev_set_name(&xendev->dev, devname);
err = device_register(&xendev->dev);
if (err)
goto fail;
return 0;
fail:
kfree(xendev);
return err;
}
static int xenbus_probe_device_type(struct xen_bus_type *bus, const char *type)
{
int err = 0;
char **dir;
unsigned int dir_n = 0;
int i;
dir = xenbus_directory(XBT_NIL, bus->root, type, &dir_n);
if (IS_ERR(dir))
return PTR_ERR(dir);
for (i = 0; i < dir_n; i++) {
err = bus->probe(bus, type, dir[i]);
if (err)
break;
}
kfree(dir);
return err;
}
int xenbus_probe_devices(struct xen_bus_type *bus)
{
int err = 0;
char **dir;
unsigned int i, dir_n;
dir = xenbus_directory(XBT_NIL, bus->root, "", &dir_n);
if (IS_ERR(dir))
return PTR_ERR(dir);
for (i = 0; i < dir_n; i++) {
err = xenbus_probe_device_type(bus, dir[i]);
if (err)
break;
}
kfree(dir);
return err;
}
static unsigned int char_count(const char *str, char c)
{
unsigned int i, ret = 0;
for (i = 0; str[i]; i++)
if (str[i] == c)
ret++;
return ret;
}
static int strsep_len(const char *str, char c, unsigned int len)
{
unsigned int i;
for (i = 0; str[i]; i++)
if (str[i] == c) {
if (len == 0)
return i;
len--;
}
return (len == 0) ? i : -ERANGE;
}
void xenbus_dev_changed(const char *node, struct xen_bus_type *bus)
{
int exists, rootlen;
struct xenbus_device *dev;
char type[XEN_BUS_ID_SIZE];
const char *p, *root;
if (char_count(node, '/') < 2)
return;
exists = xenbus_exists(XBT_NIL, node, "");
if (!exists) {
xenbus_cleanup_devices(node, &bus->bus);
return;
}
p = strchr(node, '/') + 1;
snprintf(type, XEN_BUS_ID_SIZE, "%.*s", (int)strcspn(p, "/"), p);
type[XEN_BUS_ID_SIZE-1] = '\0';
rootlen = strsep_len(node, '/', bus->levels);
if (rootlen < 0)
return;
root = kasprintf(GFP_KERNEL, "%.*s", rootlen, node);
if (!root)
return;
dev = xenbus_device_find(root, &bus->bus);
if (!dev)
xenbus_probe_node(bus, type, root);
else
put_device(&dev->dev);
kfree(root);
}
int xenbus_dev_suspend(struct device *dev)
{
int err = 0;
struct xenbus_driver *drv;
struct xenbus_device *xdev
= container_of(dev, struct xenbus_device, dev);
DPRINTK("%s", xdev->nodename);
if (dev->driver == NULL)
return 0;
drv = to_xenbus_driver(dev->driver);
if (drv->suspend)
err = drv->suspend(xdev);
if (err)
printk(KERN_WARNING
"xenbus: suspend %s failed: %i\n", dev_name(dev), err);
return 0;
}
int xenbus_dev_resume(struct device *dev)
{
int err;
struct xenbus_driver *drv;
struct xenbus_device *xdev
= container_of(dev, struct xenbus_device, dev);
DPRINTK("%s", xdev->nodename);
if (dev->driver == NULL)
return 0;
drv = to_xenbus_driver(dev->driver);
err = talk_to_otherend(xdev);
if (err) {
printk(KERN_WARNING
"xenbus: resume (talk_to_otherend) %s failed: %i\n",
dev_name(dev), err);
return err;
}
xdev->state = XenbusStateInitialising;
if (drv->resume) {
err = drv->resume(xdev);
if (err) {
printk(KERN_WARNING
"xenbus: resume %s failed: %i\n",
dev_name(dev), err);
return err;
}
}
err = watch_otherend(xdev);
if (err) {
printk(KERN_WARNING
"xenbus_probe: resume (watch_otherend) %s failed: "
"%d.\n", dev_name(dev), err);
return err;
}
return 0;
}
int xenbus_dev_cancel(struct device *dev)
{
DPRINTK("cancel");
return 0;
}
int register_xenstore_notifier(struct notifier_block *nb)
{
int ret = 0;
if (xenstored_ready > 0)
ret = nb->notifier_call(nb, 0, NULL);
else
blocking_notifier_chain_register(&xenstore_chain, nb);
return ret;
}
void unregister_xenstore_notifier(struct notifier_block *nb)
{
blocking_notifier_chain_unregister(&xenstore_chain, nb);
}
void xenbus_probe(struct work_struct *unused)
{
xenstored_ready = 1;
blocking_notifier_call_chain(&xenstore_chain, 0, NULL);
}
static int __init xenbus_probe_initcall(void)
{
if (!xen_domain())
return -ENODEV;
if (xen_initial_domain() || xen_hvm_domain())
return 0;
xenbus_probe(NULL);
return 0;
}
static int __init xenstored_local_init(void)
{
int err = 0;
unsigned long page = 0;
struct evtchn_alloc_unbound alloc_unbound;
page = get_zeroed_page(GFP_KERNEL);
if (!page)
goto out_err;
xen_store_mfn = xen_start_info->store_mfn =
pfn_to_mfn(virt_to_phys((void *)page) >>
PAGE_SHIFT);
alloc_unbound.dom = DOMID_SELF;
alloc_unbound.remote_dom = DOMID_SELF;
err = HYPERVISOR_event_channel_op(EVTCHNOP_alloc_unbound,
&alloc_unbound);
if (err == -ENOSYS)
goto out_err;
BUG_ON(err);
xen_store_evtchn = xen_start_info->store_evtchn =
alloc_unbound.port;
return 0;
out_err:
if (page != 0)
free_page(page);
return err;
}
static int __init xenbus_init(void)
{
int err = 0;
enum xenstore_init usage = UNKNOWN;
uint64_t v = 0;
if (!xen_domain())
return -ENODEV;
xenbus_ring_ops_init();
if (xen_pv_domain())
usage = PV;
if (xen_hvm_domain())
usage = HVM;
if (xen_hvm_domain() && xen_initial_domain())
usage = LOCAL;
if (xen_pv_domain() && !xen_start_info->store_evtchn)
usage = LOCAL;
if (xen_pv_domain() && xen_start_info->store_evtchn)
xenstored_ready = 1;
switch (usage) {
case LOCAL:
err = xenstored_local_init();
if (err)
goto out_error;
xen_store_interface = mfn_to_virt(xen_store_mfn);
break;
case PV:
xen_store_evtchn = xen_start_info->store_evtchn;
xen_store_mfn = xen_start_info->store_mfn;
xen_store_interface = mfn_to_virt(xen_store_mfn);
break;
case HVM:
err = hvm_get_parameter(HVM_PARAM_STORE_EVTCHN, &v);
if (err)
goto out_error;
xen_store_evtchn = (int)v;
err = hvm_get_parameter(HVM_PARAM_STORE_PFN, &v);
if (err)
goto out_error;
xen_store_mfn = (unsigned long)v;
xen_store_interface =
xen_remap(xen_store_mfn << PAGE_SHIFT, PAGE_SIZE);
break;
default:
pr_warn("Xenstore state unknown\n");
break;
}
err = xs_init();
if (err) {
printk(KERN_WARNING
"XENBUS: Error initializing xenstore comms: %i\n", err);
goto out_error;
}
#ifdef CONFIG_XEN_COMPAT_XENFS
proc_mkdir("xen", NULL);
#endif
out_error:
return err;
}
