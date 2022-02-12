static int watchdog_ping(struct watchdog_device *wdd)
{
int err;
if (!watchdog_active(wdd))
return 0;
if (wdd->ops->ping)
err = wdd->ops->ping(wdd);
else
err = wdd->ops->start(wdd);
return err;
}
static int watchdog_start(struct watchdog_device *wdd)
{
int err;
if (watchdog_active(wdd))
return 0;
err = wdd->ops->start(wdd);
if (err == 0)
set_bit(WDOG_ACTIVE, &wdd->status);
return err;
}
static int watchdog_stop(struct watchdog_device *wdd)
{
int err;
if (!watchdog_active(wdd))
return 0;
if (test_bit(WDOG_NO_WAY_OUT, &wdd->status)) {
pr_info("watchdog%d: nowayout prevents watchdog being stopped!\n",
wdd->id);
return -EBUSY;
}
err = wdd->ops->stop(wdd);
if (err == 0)
clear_bit(WDOG_ACTIVE, &wdd->status);
return err;
}
static unsigned int watchdog_get_status(struct watchdog_device *wdd)
{
if (!wdd->ops->status)
return 0;
return wdd->ops->status(wdd);
}
static int watchdog_set_timeout(struct watchdog_device *wdd,
unsigned int timeout)
{
if (!wdd->ops->set_timeout || !(wdd->info->options & WDIOF_SETTIMEOUT))
return -EOPNOTSUPP;
if (watchdog_timeout_invalid(wdd, timeout))
return -EINVAL;
return wdd->ops->set_timeout(wdd, timeout);
}
static int watchdog_get_timeleft(struct watchdog_device *wdd,
unsigned int *timeleft)
{
*timeleft = 0;
if (!wdd->ops->get_timeleft)
return -EOPNOTSUPP;
*timeleft = wdd->ops->get_timeleft(wdd);
return 0;
}
static ssize_t nowayout_show(struct device *dev, struct device_attribute *attr,
char *buf)
{
struct watchdog_device *wdd = dev_get_drvdata(dev);
return sprintf(buf, "%d\n", !!test_bit(WDOG_NO_WAY_OUT, &wdd->status));
}
static ssize_t status_show(struct device *dev, struct device_attribute *attr,
char *buf)
{
struct watchdog_device *wdd = dev_get_drvdata(dev);
struct watchdog_core_data *wd_data = wdd->wd_data;
unsigned int status;
mutex_lock(&wd_data->lock);
status = watchdog_get_status(wdd);
mutex_unlock(&wd_data->lock);
return sprintf(buf, "%u\n", status);
}
static ssize_t bootstatus_show(struct device *dev,
struct device_attribute *attr, char *buf)
{
struct watchdog_device *wdd = dev_get_drvdata(dev);
return sprintf(buf, "%u\n", wdd->bootstatus);
}
static ssize_t timeleft_show(struct device *dev, struct device_attribute *attr,
char *buf)
{
struct watchdog_device *wdd = dev_get_drvdata(dev);
struct watchdog_core_data *wd_data = wdd->wd_data;
ssize_t status;
unsigned int val;
mutex_lock(&wd_data->lock);
status = watchdog_get_timeleft(wdd, &val);
mutex_unlock(&wd_data->lock);
if (!status)
status = sprintf(buf, "%u\n", val);
return status;
}
static ssize_t timeout_show(struct device *dev, struct device_attribute *attr,
char *buf)
{
struct watchdog_device *wdd = dev_get_drvdata(dev);
return sprintf(buf, "%u\n", wdd->timeout);
}
static ssize_t identity_show(struct device *dev, struct device_attribute *attr,
char *buf)
{
struct watchdog_device *wdd = dev_get_drvdata(dev);
return sprintf(buf, "%s\n", wdd->info->identity);
}
static ssize_t state_show(struct device *dev, struct device_attribute *attr,
char *buf)
{
struct watchdog_device *wdd = dev_get_drvdata(dev);
if (watchdog_active(wdd))
return sprintf(buf, "active\n");
return sprintf(buf, "inactive\n");
}
static umode_t wdt_is_visible(struct kobject *kobj, struct attribute *attr,
int n)
{
struct device *dev = container_of(kobj, struct device, kobj);
struct watchdog_device *wdd = dev_get_drvdata(dev);
umode_t mode = attr->mode;
if (attr == &dev_attr_status.attr && !wdd->ops->status)
mode = 0;
else if (attr == &dev_attr_timeleft.attr && !wdd->ops->get_timeleft)
mode = 0;
return mode;
}
static int watchdog_ioctl_op(struct watchdog_device *wdd, unsigned int cmd,
unsigned long arg)
{
if (!wdd->ops->ioctl)
return -ENOIOCTLCMD;
return wdd->ops->ioctl(wdd, cmd, arg);
}
static ssize_t watchdog_write(struct file *file, const char __user *data,
size_t len, loff_t *ppos)
{
struct watchdog_core_data *wd_data = file->private_data;
struct watchdog_device *wdd;
int err;
size_t i;
char c;
if (len == 0)
return 0;
clear_bit(_WDOG_ALLOW_RELEASE, &wd_data->status);
for (i = 0; i != len; i++) {
if (get_user(c, data + i))
return -EFAULT;
if (c == 'V')
set_bit(_WDOG_ALLOW_RELEASE, &wd_data->status);
}
err = -ENODEV;
mutex_lock(&wd_data->lock);
wdd = wd_data->wdd;
if (wdd)
err = watchdog_ping(wdd);
mutex_unlock(&wd_data->lock);
if (err < 0)
return err;
return len;
}
static long watchdog_ioctl(struct file *file, unsigned int cmd,
unsigned long arg)
{
struct watchdog_core_data *wd_data = file->private_data;
void __user *argp = (void __user *)arg;
struct watchdog_device *wdd;
int __user *p = argp;
unsigned int val;
int err;
mutex_lock(&wd_data->lock);
wdd = wd_data->wdd;
if (!wdd) {
err = -ENODEV;
goto out_ioctl;
}
err = watchdog_ioctl_op(wdd, cmd, arg);
if (err != -ENOIOCTLCMD)
goto out_ioctl;
switch (cmd) {
case WDIOC_GETSUPPORT:
err = copy_to_user(argp, wdd->info,
sizeof(struct watchdog_info)) ? -EFAULT : 0;
break;
case WDIOC_GETSTATUS:
val = watchdog_get_status(wdd);
err = put_user(val, p);
break;
case WDIOC_GETBOOTSTATUS:
err = put_user(wdd->bootstatus, p);
break;
case WDIOC_SETOPTIONS:
if (get_user(val, p)) {
err = -EFAULT;
break;
}
if (val & WDIOS_DISABLECARD) {
err = watchdog_stop(wdd);
if (err < 0)
break;
}
if (val & WDIOS_ENABLECARD)
err = watchdog_start(wdd);
break;
case WDIOC_KEEPALIVE:
if (!(wdd->info->options & WDIOF_KEEPALIVEPING)) {
err = -EOPNOTSUPP;
break;
}
err = watchdog_ping(wdd);
break;
case WDIOC_SETTIMEOUT:
if (get_user(val, p)) {
err = -EFAULT;
break;
}
err = watchdog_set_timeout(wdd, val);
if (err < 0)
break;
err = watchdog_ping(wdd);
if (err < 0)
break;
case WDIOC_GETTIMEOUT:
if (wdd->timeout == 0) {
err = -EOPNOTSUPP;
break;
}
err = put_user(wdd->timeout, p);
break;
case WDIOC_GETTIMELEFT:
err = watchdog_get_timeleft(wdd, &val);
if (err < 0)
break;
err = put_user(val, p);
break;
default:
err = -ENOTTY;
break;
}
out_ioctl:
mutex_unlock(&wd_data->lock);
return err;
}
static int watchdog_open(struct inode *inode, struct file *file)
{
struct watchdog_core_data *wd_data;
struct watchdog_device *wdd;
int err;
if (imajor(inode) == MISC_MAJOR)
wd_data = old_wd_data;
else
wd_data = container_of(inode->i_cdev, struct watchdog_core_data,
cdev);
if (test_and_set_bit(_WDOG_DEV_OPEN, &wd_data->status))
return -EBUSY;
wdd = wd_data->wdd;
if (!try_module_get(wdd->ops->owner)) {
err = -EBUSY;
goto out_clear;
}
err = watchdog_start(wdd);
if (err < 0)
goto out_mod;
file->private_data = wd_data;
kref_get(&wd_data->kref);
return nonseekable_open(inode, file);
out_mod:
module_put(wd_data->wdd->ops->owner);
out_clear:
clear_bit(_WDOG_DEV_OPEN, &wd_data->status);
return err;
}
static void watchdog_core_data_release(struct kref *kref)
{
struct watchdog_core_data *wd_data;
wd_data = container_of(kref, struct watchdog_core_data, kref);
kfree(wd_data);
}
static int watchdog_release(struct inode *inode, struct file *file)
{
struct watchdog_core_data *wd_data = file->private_data;
struct watchdog_device *wdd;
int err = -EBUSY;
mutex_lock(&wd_data->lock);
wdd = wd_data->wdd;
if (!wdd)
goto done;
if (!test_bit(WDOG_ACTIVE, &wdd->status))
err = 0;
else if (test_and_clear_bit(_WDOG_ALLOW_RELEASE, &wd_data->status) ||
!(wdd->info->options & WDIOF_MAGICCLOSE))
err = watchdog_stop(wdd);
if (err < 0) {
pr_crit("watchdog%d: watchdog did not stop!\n", wdd->id);
watchdog_ping(wdd);
}
clear_bit(_WDOG_DEV_OPEN, &wd_data->status);
done:
mutex_unlock(&wd_data->lock);
module_put(wd_data->cdev.owner);
kref_put(&wd_data->kref, watchdog_core_data_release);
return 0;
}
static int watchdog_cdev_register(struct watchdog_device *wdd, dev_t devno)
{
struct watchdog_core_data *wd_data;
int err;
wd_data = kzalloc(sizeof(struct watchdog_core_data), GFP_KERNEL);
if (!wd_data)
return -ENOMEM;
kref_init(&wd_data->kref);
mutex_init(&wd_data->lock);
wd_data->wdd = wdd;
wdd->wd_data = wd_data;
if (wdd->id == 0) {
old_wd_data = wd_data;
watchdog_miscdev.parent = wdd->parent;
err = misc_register(&watchdog_miscdev);
if (err != 0) {
pr_err("%s: cannot register miscdev on minor=%d (err=%d).\n",
wdd->info->identity, WATCHDOG_MINOR, err);
if (err == -EBUSY)
pr_err("%s: a legacy watchdog module is probably present.\n",
wdd->info->identity);
old_wd_data = NULL;
kfree(wd_data);
return err;
}
}
cdev_init(&wd_data->cdev, &watchdog_fops);
wd_data->cdev.owner = wdd->ops->owner;
err = cdev_add(&wd_data->cdev, devno, 1);
if (err) {
pr_err("watchdog%d unable to add device %d:%d\n",
wdd->id, MAJOR(watchdog_devt), wdd->id);
if (wdd->id == 0) {
misc_deregister(&watchdog_miscdev);
old_wd_data = NULL;
kref_put(&wd_data->kref, watchdog_core_data_release);
}
}
return err;
}
static void watchdog_cdev_unregister(struct watchdog_device *wdd)
{
struct watchdog_core_data *wd_data = wdd->wd_data;
cdev_del(&wd_data->cdev);
if (wdd->id == 0) {
misc_deregister(&watchdog_miscdev);
old_wd_data = NULL;
}
mutex_lock(&wd_data->lock);
wd_data->wdd = NULL;
wdd->wd_data = NULL;
mutex_unlock(&wd_data->lock);
kref_put(&wd_data->kref, watchdog_core_data_release);
}
int watchdog_dev_register(struct watchdog_device *wdd)
{
struct device *dev;
dev_t devno;
int ret;
devno = MKDEV(MAJOR(watchdog_devt), wdd->id);
ret = watchdog_cdev_register(wdd, devno);
if (ret)
return ret;
dev = device_create_with_groups(&watchdog_class, wdd->parent,
devno, wdd, wdd->groups,
"watchdog%d", wdd->id);
if (IS_ERR(dev)) {
watchdog_cdev_unregister(wdd);
return PTR_ERR(dev);
}
return ret;
}
void watchdog_dev_unregister(struct watchdog_device *wdd)
{
device_destroy(&watchdog_class, wdd->wd_data->cdev.dev);
watchdog_cdev_unregister(wdd);
}
int __init watchdog_dev_init(void)
{
int err;
err = class_register(&watchdog_class);
if (err < 0) {
pr_err("couldn't register class\n");
return err;
}
err = alloc_chrdev_region(&watchdog_devt, 0, MAX_DOGS, "watchdog");
if (err < 0) {
pr_err("watchdog: unable to allocate char dev region\n");
class_unregister(&watchdog_class);
return err;
}
return 0;
}
void __exit watchdog_dev_exit(void)
{
unregister_chrdev_region(watchdog_devt, MAX_DOGS);
class_unregister(&watchdog_class);
}
