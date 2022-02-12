static void wdt_timer_ping(unsigned long data)
{
char tmp;
if (time_before(jiffies, next_heartbeat)) {
pci_read_config_byte(alim7101_pmu, 0x92, &tmp);
pci_write_config_byte(alim7101_pmu,
ALI_7101_WDT, (tmp & ~ALI_WDT_ARM));
pci_write_config_byte(alim7101_pmu,
ALI_7101_WDT, (tmp | ALI_WDT_ARM));
if (use_gpio) {
pci_read_config_byte(alim7101_pmu,
ALI_7101_GPIO_O, &tmp);
pci_write_config_byte(alim7101_pmu,
ALI_7101_GPIO_O, tmp | 0x20);
pci_write_config_byte(alim7101_pmu,
ALI_7101_GPIO_O, tmp & ~0x20);
}
} else {
pr_warn("Heartbeat lost! Will not ping the watchdog\n");
}
mod_timer(&timer, jiffies + WDT_INTERVAL);
}
static void wdt_change(int writeval)
{
char tmp;
pci_read_config_byte(alim7101_pmu, ALI_7101_WDT, &tmp);
if (writeval == WDT_ENABLE) {
pci_write_config_byte(alim7101_pmu,
ALI_7101_WDT, (tmp | ALI_WDT_ARM));
if (use_gpio) {
pci_read_config_byte(alim7101_pmu,
ALI_7101_GPIO_O, &tmp);
pci_write_config_byte(alim7101_pmu,
ALI_7101_GPIO_O, tmp & ~0x20);
}
} else {
pci_write_config_byte(alim7101_pmu,
ALI_7101_WDT, (tmp & ~ALI_WDT_ARM));
if (use_gpio) {
pci_read_config_byte(alim7101_pmu,
ALI_7101_GPIO_O, &tmp);
pci_write_config_byte(alim7101_pmu,
ALI_7101_GPIO_O, tmp | 0x20);
}
}
}
static void wdt_startup(void)
{
next_heartbeat = jiffies + (timeout * HZ);
wdt_change(WDT_ENABLE);
mod_timer(&timer, jiffies + WDT_INTERVAL);
pr_info("Watchdog timer is now enabled\n");
}
static void wdt_turnoff(void)
{
del_timer_sync(&timer);
wdt_change(WDT_DISABLE);
pr_info("Watchdog timer is now disabled...\n");
}
static void wdt_keepalive(void)
{
next_heartbeat = jiffies + (timeout * HZ);
}
static ssize_t fop_write(struct file *file, const char __user *buf,
size_t count, loff_t *ppos)
{
if (count) {
if (!nowayout) {
size_t ofs;
wdt_expect_close = 0;
for (ofs = 0; ofs != count; ofs++) {
char c;
if (get_user(c, buf + ofs))
return -EFAULT;
if (c == 'V')
wdt_expect_close = 42;
}
}
wdt_keepalive();
}
return count;
}
static int fop_open(struct inode *inode, struct file *file)
{
if (test_and_set_bit(0, &wdt_is_open))
return -EBUSY;
wdt_startup();
return nonseekable_open(inode, file);
}
static int fop_close(struct inode *inode, struct file *file)
{
if (wdt_expect_close == 42)
wdt_turnoff();
else {
pr_crit("device file closed unexpectedly. Will not stop the WDT!\n");
}
clear_bit(0, &wdt_is_open);
wdt_expect_close = 0;
return 0;
}
static long fop_ioctl(struct file *file, unsigned int cmd, unsigned long arg)
{
void __user *argp = (void __user *)arg;
int __user *p = argp;
static const struct watchdog_info ident = {
.options = WDIOF_KEEPALIVEPING | WDIOF_SETTIMEOUT
| WDIOF_MAGICCLOSE,
.firmware_version = 1,
.identity = "ALiM7101",
};
switch (cmd) {
case WDIOC_GETSUPPORT:
return copy_to_user(argp, &ident, sizeof(ident)) ? -EFAULT : 0;
case WDIOC_GETSTATUS:
case WDIOC_GETBOOTSTATUS:
return put_user(0, p);
case WDIOC_SETOPTIONS:
{
int new_options, retval = -EINVAL;
if (get_user(new_options, p))
return -EFAULT;
if (new_options & WDIOS_DISABLECARD) {
wdt_turnoff();
retval = 0;
}
if (new_options & WDIOS_ENABLECARD) {
wdt_startup();
retval = 0;
}
return retval;
}
case WDIOC_KEEPALIVE:
wdt_keepalive();
return 0;
case WDIOC_SETTIMEOUT:
{
int new_timeout;
if (get_user(new_timeout, p))
return -EFAULT;
if (new_timeout < 1 || new_timeout > 3600)
return -EINVAL;
timeout = new_timeout;
wdt_keepalive();
}
case WDIOC_GETTIMEOUT:
return put_user(timeout, p);
default:
return -ENOTTY;
}
}
static int wdt_restart_handle(struct notifier_block *this, unsigned long mode,
void *cmd)
{
wdt_change(WDT_ENABLE);
while (true)
;
return NOTIFY_DONE;
}
static int wdt_notify_sys(struct notifier_block *this,
unsigned long code, void *unused)
{
if (code == SYS_DOWN || code == SYS_HALT)
wdt_turnoff();
return NOTIFY_DONE;
}
static void __exit alim7101_wdt_unload(void)
{
wdt_turnoff();
misc_deregister(&wdt_miscdev);
unregister_reboot_notifier(&wdt_notifier);
unregister_restart_handler(&wdt_restart_handler);
pci_dev_put(alim7101_pmu);
}
static int __init alim7101_wdt_init(void)
{
int rc = -EBUSY;
struct pci_dev *ali1543_south;
char tmp;
pr_info("Steve Hill <steve@navaho.co.uk>\n");
alim7101_pmu = pci_get_device(PCI_VENDOR_ID_AL, PCI_DEVICE_ID_AL_M7101,
NULL);
if (!alim7101_pmu) {
pr_info("ALi M7101 PMU not present - WDT not set\n");
return -EBUSY;
}
pci_write_config_byte(alim7101_pmu, ALI_7101_WDT, 0x02);
ali1543_south = pci_get_device(PCI_VENDOR_ID_AL, PCI_DEVICE_ID_AL_M1533,
NULL);
if (!ali1543_south) {
pr_info("ALi 1543 South-Bridge not present - WDT not set\n");
goto err_out;
}
pci_read_config_byte(ali1543_south, 0x5e, &tmp);
pci_dev_put(ali1543_south);
if ((tmp & 0x1e) == 0x00) {
if (!use_gpio) {
pr_info("Detected old alim7101 revision 'a1d'. If this is a cobalt board, set the 'use_gpio' module parameter.\n");
goto err_out;
}
nowayout = 1;
} else if ((tmp & 0x1e) != 0x12 && (tmp & 0x1e) != 0x00) {
pr_info("ALi 1543 South-Bridge does not have the correct revision number (???1001?) - WDT not set\n");
goto err_out;
}
if (timeout < 1 || timeout > 3600) {
timeout = WATCHDOG_TIMEOUT;
pr_info("timeout value must be 1 <= x <= 3600, using %d\n",
timeout);
}
rc = register_reboot_notifier(&wdt_notifier);
if (rc) {
pr_err("cannot register reboot notifier (err=%d)\n", rc);
goto err_out;
}
rc = register_restart_handler(&wdt_restart_handler);
if (rc) {
pr_err("cannot register restart handler (err=%d)\n", rc);
goto err_out_reboot;
}
rc = misc_register(&wdt_miscdev);
if (rc) {
pr_err("cannot register miscdev on minor=%d (err=%d)\n",
wdt_miscdev.minor, rc);
goto err_out_restart;
}
if (nowayout)
__module_get(THIS_MODULE);
pr_info("WDT driver for ALi M7101 initialised. timeout=%d sec (nowayout=%d)\n",
timeout, nowayout);
return 0;
err_out_restart:
unregister_restart_handler(&wdt_restart_handler);
err_out_reboot:
unregister_reboot_notifier(&wdt_notifier);
err_out:
pci_dev_put(alim7101_pmu);
return rc;
}
