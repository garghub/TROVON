static void epx_c3_start(void)
{
outb(1, EPXC3_WATCHDOG_CTL_REG);
}
static void epx_c3_stop(void)
{
outb(0, EPXC3_WATCHDOG_CTL_REG);
pr_info("Stopped watchdog timer\n");
}
static void epx_c3_pet(void)
{
outb(1, EPXC3_WATCHDOG_PET_REG);
}
static int epx_c3_open(struct inode *inode, struct file *file)
{
if (epx_c3_alive)
return -EBUSY;
if (nowayout)
__module_get(THIS_MODULE);
epx_c3_start();
epx_c3_pet();
epx_c3_alive = 1;
pr_info("Started watchdog timer\n");
return nonseekable_open(inode, file);
}
static int epx_c3_release(struct inode *inode, struct file *file)
{
if (!nowayout)
epx_c3_stop();
epx_c3_alive = 0;
return 0;
}
static ssize_t epx_c3_write(struct file *file, const char __user *data,
size_t len, loff_t *ppos)
{
if (len)
epx_c3_pet();
return len;
}
static long epx_c3_ioctl(struct file *file, unsigned int cmd,
unsigned long arg)
{
int options, retval = -EINVAL;
int __user *argp = (void __user *)arg;
static const struct watchdog_info ident = {
.options = WDIOF_KEEPALIVEPING,
.firmware_version = 0,
.identity = "Winsystems EPX-C3 H/W Watchdog",
};
switch (cmd) {
case WDIOC_GETSUPPORT:
if (copy_to_user(argp, &ident, sizeof(ident)))
return -EFAULT;
return 0;
case WDIOC_GETSTATUS:
case WDIOC_GETBOOTSTATUS:
return put_user(0, argp);
case WDIOC_SETOPTIONS:
if (get_user(options, argp))
return -EFAULT;
if (options & WDIOS_DISABLECARD) {
epx_c3_stop();
retval = 0;
}
if (options & WDIOS_ENABLECARD) {
epx_c3_start();
retval = 0;
}
return retval;
case WDIOC_KEEPALIVE:
epx_c3_pet();
return 0;
case WDIOC_GETTIMEOUT:
return put_user(WATCHDOG_TIMEOUT, argp);
default:
return -ENOTTY;
}
}
static int epx_c3_notify_sys(struct notifier_block *this, unsigned long code,
void *unused)
{
if (code == SYS_DOWN || code == SYS_HALT)
epx_c3_stop();
return NOTIFY_DONE;
}
static int __init watchdog_init(void)
{
int ret;
if (!request_region(EPXC3_WATCHDOG_CTL_REG, 2, "epxc3_watchdog"))
return -EBUSY;
ret = register_reboot_notifier(&epx_c3_notifier);
if (ret) {
pr_err("cannot register reboot notifier (err=%d)\n", ret);
goto out;
}
ret = misc_register(&epx_c3_miscdev);
if (ret) {
pr_err("cannot register miscdev on minor=%d (err=%d)\n",
WATCHDOG_MINOR, ret);
unregister_reboot_notifier(&epx_c3_notifier);
goto out;
}
pr_info("Hardware Watchdog Timer for Winsystems EPX-C3 SBC: 0.1\n");
return 0;
out:
release_region(EPXC3_WATCHDOG_CTL_REG, 2);
return ret;
}
static void __exit watchdog_exit(void)
{
misc_deregister(&epx_c3_miscdev);
unregister_reboot_notifier(&epx_c3_notifier);
release_region(EPXC3_WATCHDOG_CTL_REG, 2);
}
