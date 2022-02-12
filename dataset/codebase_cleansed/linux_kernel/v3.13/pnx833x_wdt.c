static void pnx833x_wdt_start(void)
{
PNX833X_REG(PNX833X_RESET + PNX833X_RESET_CONFIG) |= 0x1;
PNX833X_REG(PNX833X_CONFIG +
PNX833X_CONFIG_CPU_WATCHDOG_COMPARE) = pnx833x_wdt_timeout;
PNX833X_REG(PNX833X_CONFIG +
PNX833X_CONFIG_CPU_COUNTERS_CONTROL) |= 0x1;
pr_info("Started watchdog timer\n");
}
static void pnx833x_wdt_stop(void)
{
PNX833X_REG(PNX833X_RESET + PNX833X_CONFIG) &= 0xFFFFFFFE;
PNX833X_REG(PNX833X_CONFIG +
PNX833X_CONFIG_CPU_COUNTERS_CONTROL) &= 0xFFFFFFFE;
pr_info("Stopped watchdog timer\n");
}
static void pnx833x_wdt_ping(void)
{
PNX833X_REG(PNX833X_CONFIG +
PNX833X_CONFIG_CPU_WATCHDOG_COMPARE) = pnx833x_wdt_timeout;
}
static int pnx833x_wdt_open(struct inode *inode, struct file *file)
{
if (test_and_set_bit(0, &pnx833x_wdt_alive))
return -EBUSY;
if (nowayout)
__module_get(THIS_MODULE);
if (!start_enabled)
pnx833x_wdt_start();
pnx833x_wdt_ping();
pr_info("Started watchdog timer\n");
return nonseekable_open(inode, file);
}
static int pnx833x_wdt_release(struct inode *inode, struct file *file)
{
if (!nowayout)
pnx833x_wdt_stop();
clear_bit(0, &pnx833x_wdt_alive);
return 0;
}
static ssize_t pnx833x_wdt_write(struct file *file, const char *data, size_t len, loff_t *ppos)
{
if (len)
pnx833x_wdt_ping();
return len;
}
static long pnx833x_wdt_ioctl(struct file *file, unsigned int cmd,
unsigned long arg)
{
int options, new_timeout = 0;
uint32_t timeout, timeout_left = 0;
static const struct watchdog_info ident = {
.options = WDIOF_KEEPALIVEPING | WDIOF_SETTIMEOUT,
.firmware_version = 0,
.identity = "Hardware Watchdog for PNX833x",
};
switch (cmd) {
default:
return -ENOTTY;
case WDIOC_GETSUPPORT:
if (copy_to_user((struct watchdog_info *)arg,
&ident, sizeof(ident)))
return -EFAULT;
return 0;
case WDIOC_GETSTATUS:
case WDIOC_GETBOOTSTATUS:
return put_user(0, (int *)arg);
case WDIOC_SETOPTIONS:
if (get_user(options, (int *)arg))
return -EFAULT;
if (options & WDIOS_DISABLECARD)
pnx833x_wdt_stop();
if (options & WDIOS_ENABLECARD)
pnx833x_wdt_start();
return 0;
case WDIOC_KEEPALIVE:
pnx833x_wdt_ping();
return 0;
case WDIOC_SETTIMEOUT:
{
if (get_user(new_timeout, (int *)arg))
return -EFAULT;
pnx833x_wdt_timeout = new_timeout;
PNX833X_REG(PNX833X_CONFIG +
PNX833X_CONFIG_CPU_WATCHDOG_COMPARE) = new_timeout;
return put_user(new_timeout, (int *)arg);
}
case WDIOC_GETTIMEOUT:
timeout = PNX833X_REG(PNX833X_CONFIG +
PNX833X_CONFIG_CPU_WATCHDOG_COMPARE);
return put_user(timeout, (int *)arg);
case WDIOC_GETTIMELEFT:
timeout_left = PNX833X_REG(PNX833X_CONFIG +
PNX833X_CONFIG_CPU_WATCHDOG);
return put_user(timeout_left, (int *)arg);
}
}
static int pnx833x_wdt_notify_sys(struct notifier_block *this,
unsigned long code, void *unused)
{
if (code == SYS_DOWN || code == SYS_HALT)
pnx833x_wdt_stop();
return NOTIFY_DONE;
}
static int __init watchdog_init(void)
{
int ret, cause;
cause = PNX833X_REG(PNX833X_RESET);
if (cause & 0x80000000) {
pr_info("The system was previously reset due to the watchdog firing - please investigate...\n");
}
ret = register_reboot_notifier(&pnx833x_wdt_notifier);
if (ret) {
pr_err("cannot register reboot notifier (err=%d)\n", ret);
return ret;
}
ret = misc_register(&pnx833x_wdt_miscdev);
if (ret) {
pr_err("cannot register miscdev on minor=%d (err=%d)\n",
WATCHDOG_MINOR, ret);
unregister_reboot_notifier(&pnx833x_wdt_notifier);
return ret;
}
pr_info("Hardware Watchdog Timer for PNX833x: Version 0.1\n");
if (start_enabled)
pnx833x_wdt_start();
return 0;
}
static void __exit watchdog_exit(void)
{
misc_deregister(&pnx833x_wdt_miscdev);
unregister_reboot_notifier(&pnx833x_wdt_notifier);
}
