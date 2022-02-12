static int watchdog_ping(struct watchdog_device *wdd)
{
int err = 0;
mutex_lock(&wdd->lock);
if (test_bit(WDOG_UNREGISTERED, &wdd->status)) {
err = -ENODEV;
goto out_ping;
}
if (!watchdog_active(wdd))
goto out_ping;
if (wdd->ops->ping)
err = wdd->ops->ping(wdd);
else
err = wdd->ops->start(wdd);
out_ping:
mutex_unlock(&wdd->lock);
return err;
}
static int watchdog_start(struct watchdog_device *wdd)
{
int err = 0;
mutex_lock(&wdd->lock);
if (test_bit(WDOG_UNREGISTERED, &wdd->status)) {
err = -ENODEV;
goto out_start;
}
if (watchdog_active(wdd))
goto out_start;
err = wdd->ops->start(wdd);
if (err == 0)
set_bit(WDOG_ACTIVE, &wdd->status);
out_start:
mutex_unlock(&wdd->lock);
return err;
}
static int watchdog_stop(struct watchdog_device *wdd)
{
int err = 0;
mutex_lock(&wdd->lock);
if (test_bit(WDOG_UNREGISTERED, &wdd->status)) {
err = -ENODEV;
goto out_stop;
}
if (!watchdog_active(wdd))
goto out_stop;
if (test_bit(WDOG_NO_WAY_OUT, &wdd->status)) {
dev_info(wdd->dev, "nowayout prevents watchdog being stopped!\n");
err = -EBUSY;
goto out_stop;
}
err = wdd->ops->stop(wdd);
if (err == 0)
clear_bit(WDOG_ACTIVE, &wdd->status);
out_stop:
mutex_unlock(&wdd->lock);
return err;
}
static int watchdog_get_status(struct watchdog_device *wdd,
unsigned int *status)
{
int err = 0;
*status = 0;
if (!wdd->ops->status)
return -EOPNOTSUPP;
mutex_lock(&wdd->lock);
if (test_bit(WDOG_UNREGISTERED, &wdd->status)) {
err = -ENODEV;
goto out_status;
}
*status = wdd->ops->status(wdd);
out_status:
mutex_unlock(&wdd->lock);
return err;
}
static int watchdog_set_timeout(struct watchdog_device *wdd,
unsigned int timeout)
{
int err;
if (!wdd->ops->set_timeout || !(wdd->info->options & WDIOF_SETTIMEOUT))
return -EOPNOTSUPP;
if (watchdog_timeout_invalid(wdd, timeout))
return -EINVAL;
mutex_lock(&wdd->lock);
if (test_bit(WDOG_UNREGISTERED, &wdd->status)) {
err = -ENODEV;
goto out_timeout;
}
err = wdd->ops->set_timeout(wdd, timeout);
out_timeout:
mutex_unlock(&wdd->lock);
return err;
}
static int watchdog_get_timeleft(struct watchdog_device *wdd,
unsigned int *timeleft)
{
int err = 0;
*timeleft = 0;
if (!wdd->ops->get_timeleft)
return -EOPNOTSUPP;
mutex_lock(&wdd->lock);
if (test_bit(WDOG_UNREGISTERED, &wdd->status)) {
err = -ENODEV;
goto out_timeleft;
}
*timeleft = wdd->ops->get_timeleft(wdd);
out_timeleft:
mutex_unlock(&wdd->lock);
return err;
}
static int watchdog_ioctl_op(struct watchdog_device *wdd, unsigned int cmd,
unsigned long arg)
{
int err;
if (!wdd->ops->ioctl)
return -ENOIOCTLCMD;
mutex_lock(&wdd->lock);
if (test_bit(WDOG_UNREGISTERED, &wdd->status)) {
err = -ENODEV;
goto out_ioctl;
}
err = wdd->ops->ioctl(wdd, cmd, arg);
out_ioctl:
mutex_unlock(&wdd->lock);
return err;
}
static ssize_t watchdog_write(struct file *file, const char __user *data,
size_t len, loff_t *ppos)
{
struct watchdog_device *wdd = file->private_data;
size_t i;
char c;
int err;
if (len == 0)
return 0;
clear_bit(WDOG_ALLOW_RELEASE, &wdd->status);
for (i = 0; i != len; i++) {
if (get_user(c, data + i))
return -EFAULT;
if (c == 'V')
set_bit(WDOG_ALLOW_RELEASE, &wdd->status);
}
err = watchdog_ping(wdd);
if (err < 0)
return err;
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
return watchdog_ping(wdd);
case WDIOC_SETTIMEOUT:
if (get_user(val, p))
return -EFAULT;
err = watchdog_set_timeout(wdd, val);
if (err < 0)
return err;
err = watchdog_ping(wdd);
if (err < 0)
return err;
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
if (!test_bit(WDOG_ACTIVE, &wdd->status))
err = 0;
else if (test_and_clear_bit(WDOG_ALLOW_RELEASE, &wdd->status) ||
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
int watchdog_dev_register(struct watchdog_device *wdd)
{
int err, devno;
if (wdd->id == 0) {
old_wdd = wdd;
watchdog_miscdev.parent = wdd->parent;
err = misc_register(&watchdog_miscdev);
if (err != 0) {
pr_err("%s: cannot register miscdev on minor=%d (err=%d).\n",
wdd->info->identity, WATCHDOG_MINOR, err);
if (err == -EBUSY)
pr_err("%s: a legacy watchdog module is probably present.\n",
wdd->info->identity);
old_wdd = NULL;
return err;
}
}
devno = MKDEV(MAJOR(watchdog_devt), wdd->id);
cdev_init(&wdd->cdev, &watchdog_fops);
wdd->cdev.owner = wdd->ops->owner;
err = cdev_add(&wdd->cdev, devno, 1);
if (err) {
pr_err("watchdog%d unable to add device %d:%d\n",
wdd->id, MAJOR(watchdog_devt), wdd->id);
if (wdd->id == 0) {
misc_deregister(&watchdog_miscdev);
old_wdd = NULL;
}
}
return err;
}
int watchdog_dev_unregister(struct watchdog_device *wdd)
{
mutex_lock(&wdd->lock);
set_bit(WDOG_UNREGISTERED, &wdd->status);
mutex_unlock(&wdd->lock);
cdev_del(&wdd->cdev);
if (wdd->id == 0) {
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
