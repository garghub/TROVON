static int rc32434_wdt_set(int new_timeout)
{
int max_to = WTCOMP2SEC((u32)-1);
if (new_timeout < 0 || new_timeout > max_to) {
printk(KERN_ERR PFX "timeout value must be between 0 and %d",
max_to);
return -EINVAL;
}
timeout = new_timeout;
spin_lock(&rc32434_wdt_device.io_lock);
writel(SEC2WTCOMP(timeout), &wdt_reg->wtcompare);
spin_unlock(&rc32434_wdt_device.io_lock);
return 0;
}
static void rc32434_wdt_start(void)
{
u32 or, nand;
spin_lock(&rc32434_wdt_device.io_lock);
writel(0, &wdt_reg->wtcount);
nand = 1 << RC32434_ERR_WNE;
or = 1 << RC32434_ERR_WRE;
nand |= 1 << RC32434_ERR_WTO;
SET_BITS(wdt_reg->errcs, or, nand);
rc32434_wdt_set(timeout);
nand = 1 << RC32434_WTC_TO;
or = 1 << RC32434_WTC_EN;
SET_BITS(wdt_reg->wtc, or, nand);
spin_unlock(&rc32434_wdt_device.io_lock);
printk(KERN_INFO PFX "Started watchdog timer.\n");
}
static void rc32434_wdt_stop(void)
{
spin_lock(&rc32434_wdt_device.io_lock);
SET_BITS(wdt_reg->wtc, 0, 1 << RC32434_WTC_EN);
spin_unlock(&rc32434_wdt_device.io_lock);
printk(KERN_INFO PFX "Stopped watchdog timer.\n");
}
static void rc32434_wdt_ping(void)
{
spin_lock(&rc32434_wdt_device.io_lock);
writel(0, &wdt_reg->wtcount);
spin_unlock(&rc32434_wdt_device.io_lock);
}
static int rc32434_wdt_open(struct inode *inode, struct file *file)
{
if (test_and_set_bit(0, &rc32434_wdt_device.inuse))
return -EBUSY;
if (nowayout)
__module_get(THIS_MODULE);
rc32434_wdt_start();
rc32434_wdt_ping();
return nonseekable_open(inode, file);
}
static int rc32434_wdt_release(struct inode *inode, struct file *file)
{
if (expect_close == 42) {
rc32434_wdt_stop();
module_put(THIS_MODULE);
} else {
printk(KERN_CRIT PFX
"device closed unexpectedly. WDT will not stop!\n");
rc32434_wdt_ping();
}
clear_bit(0, &rc32434_wdt_device.inuse);
return 0;
}
static ssize_t rc32434_wdt_write(struct file *file, const char *data,
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
rc32434_wdt_ping();
return len;
}
return 0;
}
static long rc32434_wdt_ioctl(struct file *file, unsigned int cmd,
unsigned long arg)
{
void __user *argp = (void __user *)arg;
int new_timeout;
unsigned int value;
static const struct watchdog_info ident = {
.options = WDIOF_SETTIMEOUT |
WDIOF_KEEPALIVEPING |
WDIOF_MAGICCLOSE,
.identity = "RC32434_WDT Watchdog",
};
switch (cmd) {
case WDIOC_GETSUPPORT:
if (copy_to_user(argp, &ident, sizeof(ident)))
return -EFAULT;
break;
case WDIOC_GETSTATUS:
case WDIOC_GETBOOTSTATUS:
value = 0;
if (copy_to_user(argp, &value, sizeof(int)))
return -EFAULT;
break;
case WDIOC_SETOPTIONS:
if (copy_from_user(&value, argp, sizeof(int)))
return -EFAULT;
switch (value) {
case WDIOS_ENABLECARD:
rc32434_wdt_start();
break;
case WDIOS_DISABLECARD:
rc32434_wdt_stop();
break;
default:
return -EINVAL;
}
break;
case WDIOC_KEEPALIVE:
rc32434_wdt_ping();
break;
case WDIOC_SETTIMEOUT:
if (copy_from_user(&new_timeout, argp, sizeof(int)))
return -EFAULT;
if (rc32434_wdt_set(new_timeout))
return -EINVAL;
case WDIOC_GETTIMEOUT:
return copy_to_user(argp, &timeout, sizeof(int));
default:
return -ENOTTY;
}
return 0;
}
static int __devinit rc32434_wdt_probe(struct platform_device *pdev)
{
int ret;
struct resource *r;
r = platform_get_resource_byname(pdev, IORESOURCE_MEM, "rb532_wdt_res");
if (!r) {
printk(KERN_ERR PFX "failed to retrieve resources\n");
return -ENODEV;
}
wdt_reg = ioremap_nocache(r->start, resource_size(r));
if (!wdt_reg) {
printk(KERN_ERR PFX "failed to remap I/O resources\n");
return -ENXIO;
}
spin_lock_init(&rc32434_wdt_device.io_lock);
rc32434_wdt_stop();
if (rc32434_wdt_set(timeout)) {
rc32434_wdt_set(WATCHDOG_TIMEOUT);
printk(KERN_INFO PFX
"timeout value must be between 0 and %d\n",
WTCOMP2SEC((u32)-1));
}
ret = misc_register(&rc32434_wdt_miscdev);
if (ret < 0) {
printk(KERN_ERR PFX "failed to register watchdog device\n");
goto unmap;
}
printk(banner, timeout);
return 0;
unmap:
iounmap(wdt_reg);
return ret;
}
static int __devexit rc32434_wdt_remove(struct platform_device *pdev)
{
misc_deregister(&rc32434_wdt_miscdev);
iounmap(wdt_reg);
return 0;
}
static void rc32434_wdt_shutdown(struct platform_device *pdev)
{
rc32434_wdt_stop();
}
