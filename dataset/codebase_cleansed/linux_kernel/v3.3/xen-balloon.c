static void watch_target(struct xenbus_watch *watch,
const char **vec, unsigned int len)
{
unsigned long long new_target;
int err;
err = xenbus_scanf(XBT_NIL, "memory", "target", "%llu", &new_target);
if (err != 1) {
return;
}
balloon_set_new_target(new_target >> (PAGE_SHIFT - 10));
}
static int balloon_init_watcher(struct notifier_block *notifier,
unsigned long event,
void *data)
{
int err;
err = register_xenbus_watch(&target_watch);
if (err)
printk(KERN_ERR "Failed to set balloon watcher\n");
return NOTIFY_DONE;
}
static int __init balloon_init(void)
{
if (!xen_domain())
return -ENODEV;
pr_info("xen-balloon: Initialising balloon driver.\n");
register_balloon(&balloon_dev);
register_xen_selfballooning(&balloon_dev);
register_xenstore_notifier(&xenstore_notifier);
return 0;
}
static void balloon_exit(void)
{
return;
}
static ssize_t show_target_kb(struct device *dev, struct device_attribute *attr,
char *buf)
{
return sprintf(buf, "%lu\n", PAGES2KB(balloon_stats.target_pages));
}
static ssize_t store_target_kb(struct device *dev,
struct device_attribute *attr,
const char *buf,
size_t count)
{
char *endchar;
unsigned long long target_bytes;
if (!capable(CAP_SYS_ADMIN))
return -EPERM;
target_bytes = simple_strtoull(buf, &endchar, 0) * 1024;
balloon_set_new_target(target_bytes >> PAGE_SHIFT);
return count;
}
static ssize_t show_target(struct device *dev, struct device_attribute *attr,
char *buf)
{
return sprintf(buf, "%llu\n",
(unsigned long long)balloon_stats.target_pages
<< PAGE_SHIFT);
}
static ssize_t store_target(struct device *dev,
struct device_attribute *attr,
const char *buf,
size_t count)
{
char *endchar;
unsigned long long target_bytes;
if (!capable(CAP_SYS_ADMIN))
return -EPERM;
target_bytes = memparse(buf, &endchar);
balloon_set_new_target(target_bytes >> PAGE_SHIFT);
return count;
}
static int register_balloon(struct device *dev)
{
int i, error;
error = subsys_system_register(&balloon_subsys, NULL);
if (error)
return error;
dev->id = 0;
dev->bus = &balloon_subsys;
error = device_register(dev);
if (error) {
bus_unregister(&balloon_subsys);
return error;
}
for (i = 0; i < ARRAY_SIZE(balloon_attrs); i++) {
error = device_create_file(dev, balloon_attrs[i]);
if (error)
goto fail;
}
error = sysfs_create_group(&dev->kobj, &balloon_info_group);
if (error)
goto fail;
return 0;
fail:
while (--i >= 0)
device_remove_file(dev, balloon_attrs[i]);
device_unregister(dev);
bus_unregister(&balloon_subsys);
return error;
}
