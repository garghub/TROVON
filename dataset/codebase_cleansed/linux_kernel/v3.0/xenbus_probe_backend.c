static int backend_bus_id(char bus_id[XEN_BUS_ID_SIZE], const char *nodename)
{
int domid, err;
const char *devid, *type, *frontend;
unsigned int typelen;
type = strchr(nodename, '/');
if (!type)
return -EINVAL;
type++;
typelen = strcspn(type, "/");
if (!typelen || type[typelen] != '/')
return -EINVAL;
devid = strrchr(nodename, '/') + 1;
err = xenbus_gather(XBT_NIL, nodename, "frontend-id", "%i", &domid,
"frontend", NULL, &frontend,
NULL);
if (err)
return err;
if (strlen(frontend) == 0)
err = -ERANGE;
if (!err && !xenbus_exists(XBT_NIL, frontend, ""))
err = -ENOENT;
kfree(frontend);
if (err)
return err;
if (snprintf(bus_id, XEN_BUS_ID_SIZE, "%.*s-%i-%s",
typelen, type, domid, devid) >= XEN_BUS_ID_SIZE)
return -ENOSPC;
return 0;
}
static int xenbus_uevent_backend(struct device *dev,
struct kobj_uevent_env *env)
{
struct xenbus_device *xdev;
struct xenbus_driver *drv;
struct xen_bus_type *bus;
DPRINTK("");
if (dev == NULL)
return -ENODEV;
xdev = to_xenbus_device(dev);
bus = container_of(xdev->dev.bus, struct xen_bus_type, bus);
if (xdev == NULL)
return -ENODEV;
if (add_uevent_var(env, "XENBUS_TYPE=%s", xdev->devicetype))
return -ENOMEM;
if (add_uevent_var(env, "XENBUS_PATH=%s", xdev->nodename))
return -ENOMEM;
if (add_uevent_var(env, "XENBUS_BASE_PATH=%s", bus->root))
return -ENOMEM;
if (dev->driver) {
drv = to_xenbus_driver(dev->driver);
if (drv && drv->uevent)
return drv->uevent(xdev, env);
}
return 0;
}
static int xenbus_probe_backend_unit(struct xen_bus_type *bus,
const char *dir,
const char *type,
const char *name)
{
char *nodename;
int err;
nodename = kasprintf(GFP_KERNEL, "%s/%s", dir, name);
if (!nodename)
return -ENOMEM;
DPRINTK("%s\n", nodename);
err = xenbus_probe_node(bus, type, nodename);
kfree(nodename);
return err;
}
static int xenbus_probe_backend(struct xen_bus_type *bus, const char *type,
const char *domid)
{
char *nodename;
int err = 0;
char **dir;
unsigned int i, dir_n = 0;
DPRINTK("");
nodename = kasprintf(GFP_KERNEL, "%s/%s/%s", bus->root, type, domid);
if (!nodename)
return -ENOMEM;
dir = xenbus_directory(XBT_NIL, nodename, "", &dir_n);
if (IS_ERR(dir)) {
kfree(nodename);
return PTR_ERR(dir);
}
for (i = 0; i < dir_n; i++) {
err = xenbus_probe_backend_unit(bus, nodename, type, dir[i]);
if (err)
break;
}
kfree(dir);
kfree(nodename);
return err;
}
static void frontend_changed(struct xenbus_watch *watch,
const char **vec, unsigned int len)
{
xenbus_otherend_changed(watch, vec, len, 0);
}
static void backend_changed(struct xenbus_watch *watch,
const char **vec, unsigned int len)
{
DPRINTK("");
xenbus_dev_changed(vec[XS_WATCH_PATH], &xenbus_backend);
}
static int read_frontend_details(struct xenbus_device *xendev)
{
return xenbus_read_otherend_details(xendev, "frontend-id", "frontend");
}
int xenbus_dev_is_online(struct xenbus_device *dev)
{
int rc, val;
rc = xenbus_scanf(XBT_NIL, dev->nodename, "online", "%d", &val);
if (rc != 1)
val = 0;
return val;
}
int __xenbus_register_backend(struct xenbus_driver *drv,
struct module *owner, const char *mod_name)
{
drv->read_otherend_details = read_frontend_details;
return xenbus_register_driver_common(drv, &xenbus_backend,
owner, mod_name);
}
static int backend_probe_and_watch(struct notifier_block *notifier,
unsigned long event,
void *data)
{
xenbus_probe_devices(&xenbus_backend);
register_xenbus_watch(&be_watch);
return NOTIFY_DONE;
}
static int __init xenbus_probe_backend_init(void)
{
static struct notifier_block xenstore_notifier = {
.notifier_call = backend_probe_and_watch
};
int err;
DPRINTK("");
err = bus_register(&xenbus_backend.bus);
if (err)
return err;
register_xenstore_notifier(&xenstore_notifier);
return 0;
}
