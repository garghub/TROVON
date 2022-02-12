static void scx200_wdt_ping(void)
{
spin_lock(&scx_lock);
outw(wdto_restart, scx200_cb_base + SCx200_WDT_WDTO);
spin_unlock(&scx_lock);
}
static void scx200_wdt_update_margin(void)
{
pr_info("timer margin %d seconds\n", margin);
wdto_restart = margin * W_SCALE;
}
static void scx200_wdt_enable(void)
{
pr_debug("enabling watchdog timer, wdto_restart = %d\n", wdto_restart);
spin_lock(&scx_lock);
outw(0, scx200_cb_base + SCx200_WDT_WDTO);
outb(SCx200_WDT_WDSTS_WDOVF, scx200_cb_base + SCx200_WDT_WDSTS);
outw(W_ENABLE, scx200_cb_base + SCx200_WDT_WDCNFG);
spin_unlock(&scx_lock);
scx200_wdt_ping();
}
static void scx200_wdt_disable(void)
{
pr_debug("disabling watchdog timer\n");
spin_lock(&scx_lock);
outw(0, scx200_cb_base + SCx200_WDT_WDTO);
outb(SCx200_WDT_WDSTS_WDOVF, scx200_cb_base + SCx200_WDT_WDSTS);
outw(W_DISABLE, scx200_cb_base + SCx200_WDT_WDCNFG);
spin_unlock(&scx_lock);
}
static int scx200_wdt_open(struct inode *inode, struct file *file)
{
if (test_and_set_bit(0, &open_lock))
return -EBUSY;
scx200_wdt_enable();
return nonseekable_open(inode, file);
}
static int scx200_wdt_release(struct inode *inode, struct file *file)
{
if (expect_close != 42)
pr_warn("watchdog device closed unexpectedly, will not disable the watchdog timer\n");
else if (!nowayout)
scx200_wdt_disable();
expect_close = 0;
clear_bit(0, &open_lock);
return 0;
}
static int scx200_wdt_notify_sys(struct notifier_block *this,
unsigned long code, void *unused)
{
if (code == SYS_HALT || code == SYS_POWER_OFF)
if (!nowayout)
scx200_wdt_disable();
return NOTIFY_DONE;
}
static ssize_t scx200_wdt_write(struct file *file, const char __user *data,
size_t len, loff_t *ppos)
{
if (len) {
size_t i;
scx200_wdt_ping();
expect_close = 0;
for (i = 0; i < len; ++i) {
char c;
if (get_user(c, data + i))
return -EFAULT;
if (c == 'V')
expect_close = 42;
}
return len;
}
return 0;
}
static long scx200_wdt_ioctl(struct file *file, unsigned int cmd,
unsigned long arg)
{
void __user *argp = (void __user *)arg;
int __user *p = argp;
static const struct watchdog_info ident = {
.identity = "NatSemi SCx200 Watchdog",
.firmware_version = 1,
.options = WDIOF_SETTIMEOUT | WDIOF_KEEPALIVEPING |
WDIOF_MAGICCLOSE,
};
int new_margin;
switch (cmd) {
case WDIOC_GETSUPPORT:
if (copy_to_user(argp, &ident, sizeof(ident)))
return -EFAULT;
return 0;
case WDIOC_GETSTATUS:
case WDIOC_GETBOOTSTATUS:
if (put_user(0, p))
return -EFAULT;
return 0;
case WDIOC_KEEPALIVE:
scx200_wdt_ping();
return 0;
case WDIOC_SETTIMEOUT:
if (get_user(new_margin, p))
return -EFAULT;
if (new_margin < 1)
return -EINVAL;
margin = new_margin;
scx200_wdt_update_margin();
scx200_wdt_ping();
case WDIOC_GETTIMEOUT:
if (put_user(margin, p))
return -EFAULT;
return 0;
default:
return -ENOTTY;
}
}
static int __init scx200_wdt_init(void)
{
int r;
pr_debug("NatSemi SCx200 Watchdog Driver\n");
if (!scx200_cb_present())
return -ENODEV;
if (!request_region(scx200_cb_base + SCx200_WDT_OFFSET,
SCx200_WDT_SIZE,
"NatSemi SCx200 Watchdog")) {
pr_warn("watchdog I/O region busy\n");
return -EBUSY;
}
scx200_wdt_update_margin();
scx200_wdt_disable();
r = register_reboot_notifier(&scx200_wdt_notifier);
if (r) {
pr_err("unable to register reboot notifier\n");
release_region(scx200_cb_base + SCx200_WDT_OFFSET,
SCx200_WDT_SIZE);
return r;
}
r = misc_register(&scx200_wdt_miscdev);
if (r) {
unregister_reboot_notifier(&scx200_wdt_notifier);
release_region(scx200_cb_base + SCx200_WDT_OFFSET,
SCx200_WDT_SIZE);
return r;
}
return 0;
}
static void __exit scx200_wdt_cleanup(void)
{
misc_deregister(&scx200_wdt_miscdev);
unregister_reboot_notifier(&scx200_wdt_notifier);
release_region(scx200_cb_base + SCx200_WDT_OFFSET,
SCx200_WDT_SIZE);
}
