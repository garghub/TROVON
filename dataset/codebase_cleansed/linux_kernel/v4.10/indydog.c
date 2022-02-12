static void indydog_start(void)
{
spin_lock(&indydog_lock);
sgimc->cpuctrl0 |= SGIMC_CCTRL0_WDOG;
spin_unlock(&indydog_lock);
}
static void indydog_stop(void)
{
spin_lock(&indydog_lock);
sgimc->cpuctrl0 &= ~SGIMC_CCTRL0_WDOG;
spin_unlock(&indydog_lock);
pr_info("Stopped watchdog timer\n");
}
static void indydog_ping(void)
{
sgimc->watchdogt = 0;
}
static int indydog_open(struct inode *inode, struct file *file)
{
if (test_and_set_bit(0, &indydog_alive))
return -EBUSY;
if (nowayout)
__module_get(THIS_MODULE);
indydog_start();
indydog_ping();
pr_info("Started watchdog timer\n");
return nonseekable_open(inode, file);
}
static int indydog_release(struct inode *inode, struct file *file)
{
if (!nowayout)
indydog_stop();
clear_bit(0, &indydog_alive);
return 0;
}
static ssize_t indydog_write(struct file *file, const char *data,
size_t len, loff_t *ppos)
{
if (len)
indydog_ping();
return len;
}
static long indydog_ioctl(struct file *file, unsigned int cmd,
unsigned long arg)
{
int options, retval = -EINVAL;
static const struct watchdog_info ident = {
.options = WDIOF_KEEPALIVEPING,
.firmware_version = 0,
.identity = "Hardware Watchdog for SGI IP22",
};
switch (cmd) {
case WDIOC_GETSUPPORT:
if (copy_to_user((struct watchdog_info *)arg,
&ident, sizeof(ident)))
return -EFAULT;
return 0;
case WDIOC_GETSTATUS:
case WDIOC_GETBOOTSTATUS:
return put_user(0, (int *)arg);
case WDIOC_SETOPTIONS:
{
if (get_user(options, (int *)arg))
return -EFAULT;
if (options & WDIOS_DISABLECARD) {
indydog_stop();
retval = 0;
}
if (options & WDIOS_ENABLECARD) {
indydog_start();
retval = 0;
}
return retval;
}
case WDIOC_KEEPALIVE:
indydog_ping();
return 0;
case WDIOC_GETTIMEOUT:
return put_user(WATCHDOG_TIMEOUT, (int *)arg);
default:
return -ENOTTY;
}
}
static int indydog_notify_sys(struct notifier_block *this,
unsigned long code, void *unused)
{
if (code == SYS_DOWN || code == SYS_HALT)
indydog_stop();
return NOTIFY_DONE;
}
static int __init watchdog_init(void)
{
int ret;
ret = register_reboot_notifier(&indydog_notifier);
if (ret) {
pr_err("cannot register reboot notifier (err=%d)\n", ret);
return ret;
}
ret = misc_register(&indydog_miscdev);
if (ret) {
pr_err("cannot register miscdev on minor=%d (err=%d)\n",
WATCHDOG_MINOR, ret);
unregister_reboot_notifier(&indydog_notifier);
return ret;
}
pr_info("Hardware Watchdog Timer for SGI IP22: 0.3\n");
return 0;
}
static void __exit watchdog_exit(void)
{
misc_deregister(&indydog_miscdev);
unregister_reboot_notifier(&indydog_notifier);
}
