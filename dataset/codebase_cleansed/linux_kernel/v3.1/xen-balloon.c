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
register_balloon(&balloon_sysdev);
register_xen_selfballooning(&balloon_sysdev);
target_watch.callback = watch_target;
xenstore_notifier.notifier_call = balloon_init_watcher;
register_xenstore_notifier(&xenstore_notifier);
return 0;
}
static void balloon_exit(void)
{
return;
}
static ssize_t show_target_kb(struct sys_device *dev, struct sysdev_attribute *attr,
char *buf)
{
return sprintf(buf, "%lu\n", PAGES2KB(balloon_stats.target_pages));
}
static ssize_t store_target_kb(struct sys_device *dev,
struct sysdev_attribute *attr,
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
static ssize_t show_target(struct sys_device *dev, struct sysdev_attribute *attr,
char *buf)
{
return sprintf(buf, "%llu\n",
(unsigned long long)balloon_stats.target_pages
<< PAGE_SHIFT);
}
static ssize_t store_target(struct sys_device *dev,
struct sysdev_attribute *attr,
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
static int register_balloon(struct sys_device *sysdev)
{
int i, error;
error = sysdev_class_register(&balloon_sysdev_class);
if (error)
return error;
sysdev->id = 0;
sysdev->cls = &balloon_sysdev_class;
error = sysdev_register(sysdev);
if (error) {
sysdev_class_unregister(&balloon_sysdev_class);
return error;
}
for (i = 0; i < ARRAY_SIZE(balloon_attrs); i++) {
error = sysdev_create_file(sysdev, balloon_attrs[i]);
if (error)
goto fail;
}
error = sysfs_create_group(&sysdev->kobj, &balloon_info_group);
if (error)
goto fail;
return 0;
fail:
while (--i >= 0)
sysdev_remove_file(sysdev, balloon_attrs[i]);
sysdev_unregister(sysdev);
sysdev_class_unregister(&balloon_sysdev_class);
return error;
}
