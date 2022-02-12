static int gef_wdt_toggle_wdc(int enabled_predicate, int field_shift)
{
u32 data;
u32 enabled;
int ret = 0;
spin_lock(&gef_wdt_spinlock);
data = ioread32be(gef_wdt_regs);
enabled = (data >> GEF_WDC_ENABLED_SHIFT) & 1;
if ((enabled ^ enabled_predicate) == 0) {
data = (1 << field_shift) | gef_wdt_count;
iowrite32be(data, gef_wdt_regs);
data = (2 << field_shift) | gef_wdt_count;
iowrite32be(data, gef_wdt_regs);
ret = 1;
}
spin_unlock(&gef_wdt_spinlock);
return ret;
}
static void gef_wdt_service(void)
{
gef_wdt_toggle_wdc(GEF_WDC_ENABLED_TRUE,
GEF_WDC_SERVICE_SHIFT);
}
static void gef_wdt_handler_enable(void)
{
if (gef_wdt_toggle_wdc(GEF_WDC_ENABLED_FALSE,
GEF_WDC_ENABLE_SHIFT)) {
gef_wdt_service();
pr_notice("watchdog activated\n");
}
}
static void gef_wdt_handler_disable(void)
{
if (gef_wdt_toggle_wdc(GEF_WDC_ENABLED_TRUE,
GEF_WDC_ENABLE_SHIFT))
pr_notice("watchdog deactivated\n");
}
static void gef_wdt_set_timeout(unsigned int timeout)
{
if (timeout > 0xFFFFFFFF / bus_clk)
timeout = 0xFFFFFFFF / bus_clk;
gef_wdt_count = (timeout * bus_clk) >> 8;
gef_wdt_timeout = timeout;
}
static ssize_t gef_wdt_write(struct file *file, const char __user *data,
size_t len, loff_t *ppos)
{
if (len) {
if (!nowayout) {
size_t i;
expect_close = 0;
for (i = 0; i != len; i++) {
char c;
if (get_user(c, data + i))
return -EFAULT;
if (c == 'V')
expect_close = 42;
}
}
gef_wdt_service();
}
return len;
}
static long gef_wdt_ioctl(struct file *file, unsigned int cmd,
unsigned long arg)
{
int timeout;
int options;
void __user *argp = (void __user *)arg;
static const struct watchdog_info info = {
.options = WDIOF_SETTIMEOUT | WDIOF_MAGICCLOSE |
WDIOF_KEEPALIVEPING,
.firmware_version = 0,
.identity = "GE watchdog",
};
switch (cmd) {
case WDIOC_GETSUPPORT:
if (copy_to_user(argp, &info, sizeof(info)))
return -EFAULT;
break;
case WDIOC_GETSTATUS:
case WDIOC_GETBOOTSTATUS:
if (put_user(wdt_status, (int __user *)argp))
return -EFAULT;
wdt_status &= ~WDIOF_KEEPALIVEPING;
break;
case WDIOC_SETOPTIONS:
if (get_user(options, (int __user *)argp))
return -EFAULT;
if (options & WDIOS_DISABLECARD)
gef_wdt_handler_disable();
if (options & WDIOS_ENABLECARD)
gef_wdt_handler_enable();
break;
case WDIOC_KEEPALIVE:
gef_wdt_service();
wdt_status |= WDIOF_KEEPALIVEPING;
break;
case WDIOC_SETTIMEOUT:
if (get_user(timeout, (int __user *)argp))
return -EFAULT;
gef_wdt_set_timeout(timeout);
case WDIOC_GETTIMEOUT:
if (put_user(gef_wdt_timeout, (int __user *)argp))
return -EFAULT;
break;
default:
return -ENOTTY;
}
return 0;
}
static int gef_wdt_open(struct inode *inode, struct file *file)
{
if (test_and_set_bit(GEF_WDOG_FLAG_OPENED, &wdt_flags))
return -EBUSY;
if (nowayout)
__module_get(THIS_MODULE);
gef_wdt_handler_enable();
return nonseekable_open(inode, file);
}
static int gef_wdt_release(struct inode *inode, struct file *file)
{
if (expect_close == 42)
gef_wdt_handler_disable();
else {
pr_crit("unexpected close, not stopping timer!\n");
gef_wdt_service();
}
expect_close = 0;
clear_bit(GEF_WDOG_FLAG_OPENED, &wdt_flags);
return 0;
}
static int __devinit gef_wdt_probe(struct platform_device *dev)
{
int timeout = 10;
u32 freq;
bus_clk = 133;
freq = fsl_get_sys_freq();
if (freq != -1)
bus_clk = freq;
gef_wdt_regs = of_iomap(dev->dev.of_node, 0);
if (gef_wdt_regs == NULL)
return -ENOMEM;
gef_wdt_set_timeout(timeout);
gef_wdt_handler_disable();
return misc_register(&gef_wdt_miscdev);
}
static int __devexit gef_wdt_remove(struct platform_device *dev)
{
misc_deregister(&gef_wdt_miscdev);
gef_wdt_handler_disable();
iounmap(gef_wdt_regs);
return 0;
}
static int __init gef_wdt_init(void)
{
pr_info("GE watchdog driver\n");
return platform_driver_register(&gef_wdt_driver);
}
static void __exit gef_wdt_exit(void)
{
platform_driver_unregister(&gef_wdt_driver);
}
