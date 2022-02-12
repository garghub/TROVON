static int watchdog_ping(struct watchdog_device *wddev)
{
int err = 0;
mutex_lock(&wddev->lock);
if (test_bit(WDOG_UNREGISTERED, &wddev->status)) {
err = -ENODEV;
goto out_ping;
}
if (!watchdog_active(wddev))
goto out_ping;
if (wddev->ops->ping)
err = wddev->ops->ping(wddev);
else
err = wddev->ops->start(wddev);
out_ping:
mutex_unlock(&wddev->lock);
return err;
}
static int watchdog_start(struct watchdog_device *wddev)
{
int err = 0;
mutex_lock(&wddev->lock);
if (test_bit(WDOG_UNREGISTERED, &wddev->status)) {
err = -ENODEV;
goto out_start;
}
if (watchdog_active(wddev))
goto out_start;
err = wddev->ops->start(wddev);
if (err == 0)
set_bit(WDOG_ACTIVE, &wddev->status);
out_start:
mutex_unlock(&wddev->lock);
return err;
}
static int watchdog_stop(struct watchdog_device *wddev)
{
int err = 0;
mutex_lock(&wddev->lock);
if (test_bit(WDOG_UNREGISTERED, &wddev->status)) {
err = -ENODEV;
goto out_stop;
}
if (!watchdog_active(wddev))
goto out_stop;
if (test_bit(WDOG_NO_WAY_OUT, &wddev->status)) {
dev_info(wddev->dev, "nowayout prevents watchdog being stopped!\n");
err = -EBUSY;
goto out_stop;
}
err = wddev->ops->stop(wddev);
if (err == 0)
clear_bit(WDOG_ACTIVE, &wddev->status);
out_stop:
mutex_unlock(&wddev->lock);
return err;
}
static int watchdog_get_status(struct watchdog_device *wddev,
unsigned int *status)
{
int err = 0;
*status = 0;
if (!wddev->ops->status)
return -EOPNOTSUPP;
mutex_lock(&wddev->lock);
if (test_bit(WDOG_UNREGISTERED, &wddev->status)) {
err = -ENODEV;
goto out_status;
}
*status = wddev->ops->status(wddev);
out_status:
mutex_unlock(&wddev->lock);
return err;
}
static int watchdog_set_timeout(struct watchdog_device *wddev,
unsigned int timeout)
{
int err;
if ((wddev->ops->set_timeout == NULL) ||
!(wddev->info->options & WDIOF_SETTIMEOUT))
return -EOPNOTSUPP;
if ((wddev->max_timeout != 0) &&
(timeout < wddev->min_timeout || timeout > wddev->max_timeout))
return -EINVAL;
mutex_lock(&wddev->lock);
if (test_bit(WDOG_UNREGISTERED, &wddev->status)) {
err = -ENODEV;
goto out_timeout;
}
err = wddev->ops->set_timeout(wddev, timeout);
out_timeout:
mutex_unlock(&wddev->lock);
return err;
}
static int watchdog_get_timeleft(struct watchdog_device *wddev,
unsigned int *timeleft)
{
int err = 0;
*timeleft = 0;
if (!wddev->ops->get_timeleft)
return -EOPNOTSUPP;
mutex_lock(&wddev->lock);
if (test_bit(WDOG_UNREGISTERED, &wddev->status)) {
err = -ENODEV;
goto out_timeleft;
}
*timeleft = wddev->ops->get_timeleft(wddev);
out_timeleft:
mutex_unlock(&wddev->lock);
return err;
}
static int watchdog_ioctl_op(struct watchdog_device *wddev, unsigned int cmd,
unsigned long arg)
{
int err;
if (!wddev->ops->ioctl)
return -ENOIOCTLCMD;
mutex_lock(&wddev->lock);
if (test_bit(WDOG_UNREGISTERED, &wddev->status)) {
err = -ENODEV;
goto out_ioctl;
}
err = wddev->ops->ioctl(wddev, cmd, arg);
out_ioctl:
mutex_unlock(&wddev->lock);
return err;
}
static ssize_t watchdog_write(struct file *file, const char __user *data,
size_t len, loff_t *ppos)
{
struct watchdog_device *wdd = file->private_data;
size_t i;
char c;
if (len == 0)
return 0;
clear_bit(WDOG_ALLOW_RELEASE, &wdd->status);
for (i = 0; i != len; i++) {
if (get_user(c, data + i))
return -EFAULT;
if (c == 'V')
set_bit(WDOG_ALLOW_RELEASE, &wdd->status);
}
watchdog_ping(wdd);
return len;
}
static long watchdog_ioctl(struct file *file, unsigned int cmd,
unsigned long arg)
{
struct watchdog_device *wdd = file->private_data;
void __user *argp = (void __user *)arg;
int __user *p = argp;
unsigned int val;
int err;
err = watchdog_ioctl_op(wdd, cmd, arg);
if (err != -ENOIOCTLCMD)
return err;
switch (cmd) {
case WDIOC_GETSUPPORT:
return copy_to_user(argp, wdd->info,
sizeof(struct watchdog_info)) ? -EFAULT : 0;
case WDIOC_GETSTATUS:
err = watchdog_get_status(wdd, &val);
if (err == -ENODEV)
return err;
return put_user(val, p);
case WDIOC_GETBOOTSTATUS:
return put_user(wdd->bootstatus, p);
case WDIOC_SETOPTIONS:
if (get_user(val, p))
return -EFAULT;
if (val & WDIOS_DISABLECARD) {
err = watchdog_stop(wdd);
if (err < 0)
return err;
}
if (val & WDIOS_ENABLECARD) {
err = watchdog_start(wdd);
if (err < 0)
return err;
}
return 0;
case WDIOC_KEEPALIVE:
if (!(wdd->info->options & WDIOF_KEEPALIVEPING))
return -EOPNOTSUPP;
watchdog_ping(wdd);
return 0;
case WDIOC_SETTIMEOUT:
if (get_user(val, p))
return -EFAULT;
err = watchdog_set_timeout(wdd, val);
if (err < 0)
return err;
watchdog_ping(wdd);
case WDIOC_GETTIMEOUT:
if (wdd->timeout == 0)
return -EOPNOTSUPP;
return put_user(wdd->timeout, p);
case WDIOC_GETTIMELEFT:
err = watchdog_get_timeleft(wdd, &val);
if (err)
return err;
return put_user(val, p);
default:
return -ENOTTY;
}
}
static int watchdog_open(struct inode *inode, struct file *file)
{
int err = -EBUSY;
struct watchdog_device *wdd;
if (imajor(inode) == MISC_MAJOR)
wdd = old_wdd;
else
wdd = container_of(inode->i_cdev, struct watchdog_device, cdev);
if (test_and_set_bit(WDOG_DEV_OPEN, &wdd->status))
return -EBUSY;
if (!try_module_get(wdd->ops->owner))
goto out;
err = watchdog_start(wdd);
if (err < 0)
goto out_mod;
file->private_data = wdd;
if (wdd->ops->ref)
wdd->ops->ref(wdd);
return nonseekable_open(inode, file);
out_mod:
module_put(wdd->ops->owner);
out:
clear_bit(WDOG_DEV_OPEN, &wdd->status);
return err;
}
static int watchdog_release(struct inode *inode, struct file *file)
{
struct watchdog_device *wdd = file->private_data;
int err = -EBUSY;
if (test_and_clear_bit(WDOG_ALLOW_RELEASE, &wdd->status) ||
!(wdd->info->options & WDIOF_MAGICCLOSE))
err = watchdog_stop(wdd);
if (err < 0) {
mutex_lock(&wdd->lock);
if (!test_bit(WDOG_UNREGISTERED, &wdd->status))
dev_crit(wdd->dev, "watchdog did not stop!\n");
mutex_unlock(&wdd->lock);
watchdog_ping(wdd);
}
module_put(wdd->ops->owner);
clear_bit(WDOG_DEV_OPEN, &wdd->status);
if (wdd->ops->unref)
wdd->ops->unref(wdd);
return 0;
}
int watchdog_dev_register(struct watchdog_device *watchdog)
{
int err, devno;
if (watchdog->id == 0) {
watchdog_miscdev.parent = watchdog->parent;
err = misc_register(&watchdog_miscdev);
if (err != 0) {
pr_err("%s: cannot register miscdev on minor=%d (err=%d).\n",
watchdog->info->identity, WATCHDOG_MINOR, err);
if (err == -EBUSY)
pr_err("%s: a legacy watchdog module is probably present.\n",
watchdog->info->identity);
return err;
}
old_wdd = watchdog;
}
devno = MKDEV(MAJOR(watchdog_devt), watchdog->id);
cdev_init(&watchdog->cdev, &watchdog_fops);
watchdog->cdev.owner = watchdog->ops->owner;
err = cdev_add(&watchdog->cdev, devno, 1);
if (err) {
pr_err("watchdog%d unable to add device %d:%d\n",
watchdog->id, MAJOR(watchdog_devt), watchdog->id);
if (watchdog->id == 0) {
misc_deregister(&watchdog_miscdev);
old_wdd = NULL;
}
}
return err;
}
int watchdog_dev_unregister(struct watchdog_device *watchdog)
{
mutex_lock(&watchdog->lock);
set_bit(WDOG_UNREGISTERED, &watchdog->status);
mutex_unlock(&watchdog->lock);
cdev_del(&watchdog->cdev);
if (watchdog->id == 0) {
misc_deregister(&watchdog_miscdev);
old_wdd = NULL;
}
return 0;
}
int __init watchdog_dev_init(void)
{
int err = alloc_chrdev_region(&watchdog_devt, 0, MAX_DOGS, "watchdog");
if (err < 0)
pr_err("watchdog: unable to allocate char dev region\n");
return err;
}
void __exit watchdog_dev_exit(void)
{
unregister_chrdev_region(watchdog_devt, MAX_DOGS);
}
