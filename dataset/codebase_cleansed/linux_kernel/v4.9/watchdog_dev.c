static inline bool watchdog_need_worker(struct watchdog_device *wdd)
{
unsigned int hm = wdd->max_hw_heartbeat_ms;
unsigned int t = wdd->timeout * 1000;
return (hm && watchdog_active(wdd) && t > hm) ||
(t && !watchdog_active(wdd) && watchdog_hw_running(wdd));
}
static long watchdog_next_keepalive(struct watchdog_device *wdd)
{
struct watchdog_core_data *wd_data = wdd->wd_data;
unsigned int timeout_ms = wdd->timeout * 1000;
unsigned long keepalive_interval;
unsigned long last_heartbeat;
unsigned long virt_timeout;
unsigned int hw_heartbeat_ms;
virt_timeout = wd_data->last_keepalive + msecs_to_jiffies(timeout_ms);
hw_heartbeat_ms = min_not_zero(timeout_ms, wdd->max_hw_heartbeat_ms);
keepalive_interval = msecs_to_jiffies(hw_heartbeat_ms / 2);
if (!watchdog_active(wdd))
return keepalive_interval;
last_heartbeat = virt_timeout - msecs_to_jiffies(hw_heartbeat_ms);
return min_t(long, last_heartbeat - jiffies, keepalive_interval);
}
static inline void watchdog_update_worker(struct watchdog_device *wdd)
{
struct watchdog_core_data *wd_data = wdd->wd_data;
if (watchdog_need_worker(wdd)) {
long t = watchdog_next_keepalive(wdd);
if (t > 0)
mod_delayed_work(watchdog_wq, &wd_data->work, t);
} else {
cancel_delayed_work(&wd_data->work);
}
}
static int __watchdog_ping(struct watchdog_device *wdd)
{
struct watchdog_core_data *wd_data = wdd->wd_data;
unsigned long earliest_keepalive = wd_data->last_hw_keepalive +
msecs_to_jiffies(wdd->min_hw_heartbeat_ms);
int err;
if (time_is_after_jiffies(earliest_keepalive)) {
mod_delayed_work(watchdog_wq, &wd_data->work,
earliest_keepalive - jiffies);
return 0;
}
wd_data->last_hw_keepalive = jiffies;
if (wdd->ops->ping)
err = wdd->ops->ping(wdd);
else
err = wdd->ops->start(wdd);
watchdog_update_worker(wdd);
return err;
}
static int watchdog_ping(struct watchdog_device *wdd)
{
struct watchdog_core_data *wd_data = wdd->wd_data;
if (!watchdog_active(wdd) && !watchdog_hw_running(wdd))
return 0;
set_bit(_WDOG_KEEPALIVE, &wd_data->status);
wd_data->last_keepalive = jiffies;
return __watchdog_ping(wdd);
}
static void watchdog_ping_work(struct work_struct *work)
{
struct watchdog_core_data *wd_data;
struct watchdog_device *wdd;
wd_data = container_of(to_delayed_work(work), struct watchdog_core_data,
work);
mutex_lock(&wd_data->lock);
wdd = wd_data->wdd;
if (wdd && (watchdog_active(wdd) || watchdog_hw_running(wdd)))
__watchdog_ping(wdd);
mutex_unlock(&wd_data->lock);
}
static int watchdog_start(struct watchdog_device *wdd)
{
struct watchdog_core_data *wd_data = wdd->wd_data;
unsigned long started_at;
int err;
if (watchdog_active(wdd))
return 0;
set_bit(_WDOG_KEEPALIVE, &wd_data->status);
started_at = jiffies;
if (watchdog_hw_running(wdd) && wdd->ops->ping)
err = wdd->ops->ping(wdd);
else
err = wdd->ops->start(wdd);
if (err == 0) {
set_bit(WDOG_ACTIVE, &wdd->status);
wd_data->last_keepalive = started_at;
watchdog_update_worker(wdd);
}
return err;
}
static int watchdog_stop(struct watchdog_device *wdd)
{
int err = 0;
if (!watchdog_active(wdd))
return 0;
if (test_bit(WDOG_NO_WAY_OUT, &wdd->status)) {
pr_info("watchdog%d: nowayout prevents watchdog being stopped!\n",
wdd->id);
return -EBUSY;
}
if (wdd->ops->stop) {
clear_bit(WDOG_HW_RUNNING, &wdd->status);
err = wdd->ops->stop(wdd);
} else {
set_bit(WDOG_HW_RUNNING, &wdd->status);
}
if (err == 0) {
clear_bit(WDOG_ACTIVE, &wdd->status);
watchdog_update_worker(wdd);
}
return err;
}
static unsigned int watchdog_get_status(struct watchdog_device *wdd)
{
struct watchdog_core_data *wd_data = wdd->wd_data;
unsigned int status;
if (wdd->ops->status)
status = wdd->ops->status(wdd);
else
status = wdd->bootstatus & (WDIOF_CARDRESET |
WDIOF_OVERHEAT |
WDIOF_FANFAULT |
WDIOF_EXTERN1 |
WDIOF_EXTERN2 |
WDIOF_POWERUNDER |
WDIOF_POWEROVER);
if (test_bit(_WDOG_ALLOW_RELEASE, &wd_data->status))
status |= WDIOF_MAGICCLOSE;
if (test_and_clear_bit(_WDOG_KEEPALIVE, &wd_data->status))
status |= WDIOF_KEEPALIVEPING;
return status;
}
static int watchdog_set_timeout(struct watchdog_device *wdd,
unsigned int timeout)
{
int err = 0;
if (!(wdd->info->options & WDIOF_SETTIMEOUT))
return -EOPNOTSUPP;
if (watchdog_timeout_invalid(wdd, timeout))
return -EINVAL;
if (wdd->ops->set_timeout) {
err = wdd->ops->set_timeout(wdd, timeout);
} else {
wdd->timeout = timeout;
if (wdd->pretimeout >= wdd->timeout)
wdd->pretimeout = 0;
}
watchdog_update_worker(wdd);
return err;
}
static int watchdog_set_pretimeout(struct watchdog_device *wdd,
unsigned int timeout)
{
int err = 0;
if (!(wdd->info->options & WDIOF_PRETIMEOUT))
return -EOPNOTSUPP;
if (watchdog_pretimeout_invalid(wdd, timeout))
return -EINVAL;
if (wdd->ops->set_pretimeout)
err = wdd->ops->set_pretimeout(wdd, timeout);
else
wdd->pretimeout = timeout;
return err;
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
return sprintf(buf, "0x%x\n", status);
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
static ssize_t pretimeout_show(struct device *dev,
struct device_attribute *attr, char *buf)
{
struct watchdog_device *wdd = dev_get_drvdata(dev);
return sprintf(buf, "%u\n", wdd->pretimeout);
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
static ssize_t pretimeout_available_governors_show(struct device *dev,
struct device_attribute *attr, char *buf)
{
return watchdog_pretimeout_available_governors_get(buf);
}
static ssize_t pretimeout_governor_show(struct device *dev,
struct device_attribute *attr,
char *buf)
{
struct watchdog_device *wdd = dev_get_drvdata(dev);
return watchdog_pretimeout_governor_get(wdd, buf);
}
static ssize_t pretimeout_governor_store(struct device *dev,
struct device_attribute *attr,
const char *buf, size_t count)
{
struct watchdog_device *wdd = dev_get_drvdata(dev);
int ret = watchdog_pretimeout_governor_set(wdd, buf);
if (!ret)
ret = count;
return ret;
}
static umode_t wdt_is_visible(struct kobject *kobj, struct attribute *attr,
int n)
{
struct device *dev = container_of(kobj, struct device, kobj);
struct watchdog_device *wdd = dev_get_drvdata(dev);
umode_t mode = attr->mode;
if (attr == &dev_attr_timeleft.attr && !wdd->ops->get_timeleft)
mode = 0;
else if (attr == &dev_attr_pretimeout.attr &&
!(wdd->info->options & WDIOF_PRETIMEOUT))
mode = 0;
else if ((attr == &dev_attr_pretimeout_governor.attr ||
attr == &dev_attr_pretimeout_available_governors.attr) &&
(!(wdd->info->options & WDIOF_PRETIMEOUT) ||
!IS_ENABLED(CONFIG_WATCHDOG_PRETIMEOUT_GOV)))
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
case WDIOC_SETPRETIMEOUT:
if (get_user(val, p)) {
err = -EFAULT;
break;
}
err = watchdog_set_pretimeout(wdd, val);
break;
case WDIOC_GETPRETIMEOUT:
err = put_user(wdd->pretimeout, p);
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
if (!watchdog_hw_running(wdd) && !try_module_get(wdd->ops->owner)) {
err = -EBUSY;
goto out_clear;
}
err = watchdog_start(wdd);
if (err < 0)
goto out_mod;
file->private_data = wd_data;
if (!watchdog_hw_running(wdd))
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
bool running;
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
watchdog_update_worker(wdd);
clear_bit(_WDOG_DEV_OPEN, &wd_data->status);
done:
running = wdd && watchdog_hw_running(wdd);
mutex_unlock(&wd_data->lock);
if (!running) {
module_put(wd_data->cdev.owner);
kref_put(&wd_data->kref, watchdog_core_data_release);
}
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
if (!watchdog_wq)
return -ENODEV;
INIT_DELAYED_WORK(&wd_data->work, watchdog_ping_work);
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
return err;
}
wd_data->last_hw_keepalive = jiffies - 1;
if (watchdog_hw_running(wdd)) {
__module_get(wdd->ops->owner);
kref_get(&wd_data->kref);
queue_delayed_work(watchdog_wq, &wd_data->work, 0);
}
return 0;
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
cancel_delayed_work_sync(&wd_data->work);
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
ret = watchdog_register_pretimeout(wdd);
if (ret) {
device_destroy(&watchdog_class, devno);
watchdog_cdev_unregister(wdd);
}
return ret;
}
void watchdog_dev_unregister(struct watchdog_device *wdd)
{
watchdog_unregister_pretimeout(wdd);
device_destroy(&watchdog_class, wdd->wd_data->cdev.dev);
watchdog_cdev_unregister(wdd);
}
int __init watchdog_dev_init(void)
{
int err;
watchdog_wq = alloc_workqueue("watchdogd",
WQ_HIGHPRI | WQ_MEM_RECLAIM, 0);
if (!watchdog_wq) {
pr_err("Failed to create watchdog workqueue\n");
return -ENOMEM;
}
err = class_register(&watchdog_class);
if (err < 0) {
pr_err("couldn't register class\n");
goto err_register;
}
err = alloc_chrdev_region(&watchdog_devt, 0, MAX_DOGS, "watchdog");
if (err < 0) {
pr_err("watchdog: unable to allocate char dev region\n");
goto err_alloc;
}
return 0;
err_alloc:
class_unregister(&watchdog_class);
err_register:
destroy_workqueue(watchdog_wq);
return err;
}
void __exit watchdog_dev_exit(void)
{
unregister_chrdev_region(watchdog_devt, MAX_DOGS);
class_unregister(&watchdog_class);
destroy_workqueue(watchdog_wq);
}
