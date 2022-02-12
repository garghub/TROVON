static inline void at91_wdt_reset(void)
{
wdt_write(AT91_WDT_CR, AT91_WDT_KEY | AT91_WDT_WDRSTT);
}
static void at91_ping(unsigned long data)
{
if (time_before(jiffies, at91wdt_private.next_heartbeat) ||
(!nowayout && !at91wdt_private.open)) {
at91_wdt_reset();
mod_timer(&at91wdt_private.timer, jiffies + WDT_TIMEOUT);
} else
printk(KERN_CRIT DRV_NAME": I will reset your machine !\n");
}
static int at91_wdt_open(struct inode *inode, struct file *file)
{
if (test_and_set_bit(0, &at91wdt_private.open))
return -EBUSY;
at91wdt_private.next_heartbeat = jiffies + heartbeat * HZ;
mod_timer(&at91wdt_private.timer, jiffies + WDT_TIMEOUT);
return nonseekable_open(inode, file);
}
static int at91_wdt_close(struct inode *inode, struct file *file)
{
clear_bit(0, &at91wdt_private.open);
if (!at91wdt_private.expect_close)
del_timer(&at91wdt_private.timer);
at91wdt_private.expect_close = 0;
return 0;
}
static int at91_wdt_settimeout(unsigned int timeout)
{
unsigned int reg;
unsigned int mr;
mr = wdt_read(AT91_WDT_MR);
if (mr & AT91_WDT_WDDIS) {
printk(KERN_ERR DRV_NAME": sorry, watchdog is disabled\n");
return -EIO;
}
reg = AT91_WDT_WDRSTEN
| AT91_WDT_WDDBGHLT
| AT91_WDT_WDD
| (timeout & AT91_WDT_WDV);
wdt_write(AT91_WDT_MR, reg);
return 0;
}
static long at91_wdt_ioctl(struct file *file,
unsigned int cmd, unsigned long arg)
{
void __user *argp = (void __user *)arg;
int __user *p = argp;
int new_value;
switch (cmd) {
case WDIOC_GETSUPPORT:
return copy_to_user(argp, &at91_wdt_info,
sizeof(at91_wdt_info)) ? -EFAULT : 0;
case WDIOC_GETSTATUS:
case WDIOC_GETBOOTSTATUS:
return put_user(0, p);
case WDIOC_KEEPALIVE:
at91wdt_private.next_heartbeat = jiffies + heartbeat * HZ;
return 0;
case WDIOC_SETTIMEOUT:
if (get_user(new_value, p))
return -EFAULT;
heartbeat = new_value;
at91wdt_private.next_heartbeat = jiffies + heartbeat * HZ;
return put_user(new_value, p);
case WDIOC_GETTIMEOUT:
return put_user(heartbeat, p);
}
return -ENOTTY;
}
static ssize_t at91_wdt_write(struct file *file, const char *data, size_t len,
loff_t *ppos)
{
if (!len)
return 0;
if (!nowayout) {
size_t i;
at91wdt_private.expect_close = 0;
for (i = 0; i < len; i++) {
char c;
if (get_user(c, data + i))
return -EFAULT;
if (c == 'V') {
at91wdt_private.expect_close = 42;
break;
}
}
}
at91wdt_private.next_heartbeat = jiffies + heartbeat * HZ;
return len;
}
static int __init at91wdt_probe(struct platform_device *pdev)
{
struct resource *r;
int res;
if (at91wdt_miscdev.parent)
return -EBUSY;
at91wdt_miscdev.parent = &pdev->dev;
r = platform_get_resource(pdev, IORESOURCE_MEM, 0);
if (!r)
return -ENODEV;
at91wdt_private.base = ioremap(r->start, resource_size(r));
if (!at91wdt_private.base) {
dev_err(&pdev->dev, "failed to map registers, aborting.\n");
return -ENOMEM;
}
res = at91_wdt_settimeout(ms_to_ticks(WDT_HW_TIMEOUT * 1000));
if (res)
return res;
res = misc_register(&at91wdt_miscdev);
if (res)
return res;
at91wdt_private.next_heartbeat = jiffies + heartbeat * HZ;
setup_timer(&at91wdt_private.timer, at91_ping, 0);
mod_timer(&at91wdt_private.timer, jiffies + WDT_TIMEOUT);
printk(KERN_INFO DRV_NAME " enabled (heartbeat=%d sec, nowayout=%d)\n",
heartbeat, nowayout);
return 0;
}
static int __exit at91wdt_remove(struct platform_device *pdev)
{
int res;
res = misc_deregister(&at91wdt_miscdev);
if (!res)
at91wdt_miscdev.parent = NULL;
return res;
}
static int __init at91sam_wdt_init(void)
{
return platform_driver_probe(&at91wdt_driver, at91wdt_probe);
}
static void __exit at91sam_wdt_exit(void)
{
platform_driver_unregister(&at91wdt_driver);
}
