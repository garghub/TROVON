static void txx9wdt_ping(void)
{
spin_lock(&txx9_lock);
__raw_writel(TXx9_TMWTMR_TWIE | TXx9_TMWTMR_TWC, &txx9wdt_reg->wtmr);
spin_unlock(&txx9_lock);
}
static void txx9wdt_start(void)
{
spin_lock(&txx9_lock);
__raw_writel(WD_TIMER_CLK * timeout, &txx9wdt_reg->cpra);
__raw_writel(WD_TIMER_CCD, &txx9wdt_reg->ccdr);
__raw_writel(0, &txx9wdt_reg->tisr);
__raw_writel(TXx9_TMTCR_TCE | TXx9_TMTCR_CCDE | TXx9_TMTCR_TMODE_WDOG,
&txx9wdt_reg->tcr);
__raw_writel(TXx9_TMWTMR_TWIE | TXx9_TMWTMR_TWC, &txx9wdt_reg->wtmr);
spin_unlock(&txx9_lock);
}
static void txx9wdt_stop(void)
{
spin_lock(&txx9_lock);
__raw_writel(TXx9_TMWTMR_WDIS, &txx9wdt_reg->wtmr);
__raw_writel(__raw_readl(&txx9wdt_reg->tcr) & ~TXx9_TMTCR_TCE,
&txx9wdt_reg->tcr);
spin_unlock(&txx9_lock);
}
static int txx9wdt_open(struct inode *inode, struct file *file)
{
if (test_and_set_bit(0, &txx9wdt_alive))
return -EBUSY;
if (__raw_readl(&txx9wdt_reg->tcr) & TXx9_TMTCR_TCE) {
clear_bit(0, &txx9wdt_alive);
return -EBUSY;
}
if (nowayout)
__module_get(THIS_MODULE);
txx9wdt_start();
return nonseekable_open(inode, file);
}
static int txx9wdt_release(struct inode *inode, struct file *file)
{
if (expect_close)
txx9wdt_stop();
else {
printk(KERN_CRIT "txx9wdt: "
"Unexpected close, not stopping watchdog!\n");
txx9wdt_ping();
}
clear_bit(0, &txx9wdt_alive);
expect_close = 0;
return 0;
}
static ssize_t txx9wdt_write(struct file *file, const char __user *data,
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
expect_close = 1;
}
}
txx9wdt_ping();
}
return len;
}
static long txx9wdt_ioctl(struct file *file, unsigned int cmd,
unsigned long arg)
{
void __user *argp = (void __user *)arg;
int __user *p = argp;
int new_timeout;
static const struct watchdog_info ident = {
.options = WDIOF_SETTIMEOUT |
WDIOF_KEEPALIVEPING |
WDIOF_MAGICCLOSE,
.firmware_version = 0,
.identity = "Hardware Watchdog for TXx9",
};
switch (cmd) {
case WDIOC_GETSUPPORT:
return copy_to_user(argp, &ident, sizeof(ident)) ? -EFAULT : 0;
case WDIOC_GETSTATUS:
case WDIOC_GETBOOTSTATUS:
return put_user(0, p);
case WDIOC_KEEPALIVE:
txx9wdt_ping();
return 0;
case WDIOC_SETTIMEOUT:
if (get_user(new_timeout, p))
return -EFAULT;
if (new_timeout < 1 || new_timeout > WD_MAX_TIMEOUT)
return -EINVAL;
timeout = new_timeout;
txx9wdt_stop();
txx9wdt_start();
case WDIOC_GETTIMEOUT:
return put_user(timeout, p);
default:
return -ENOTTY;
}
}
static int __init txx9wdt_probe(struct platform_device *dev)
{
struct resource *res;
int ret;
txx9_imclk = clk_get(NULL, "imbus_clk");
if (IS_ERR(txx9_imclk)) {
ret = PTR_ERR(txx9_imclk);
txx9_imclk = NULL;
goto exit;
}
ret = clk_enable(txx9_imclk);
if (ret) {
clk_put(txx9_imclk);
txx9_imclk = NULL;
goto exit;
}
res = platform_get_resource(dev, IORESOURCE_MEM, 0);
if (!res)
goto exit_busy;
if (!devm_request_mem_region(&dev->dev, res->start, resource_size(res),
"txx9wdt"))
goto exit_busy;
txx9wdt_reg = devm_ioremap(&dev->dev, res->start, resource_size(res));
if (!txx9wdt_reg)
goto exit_busy;
ret = misc_register(&txx9wdt_miscdev);
if (ret) {
goto exit;
}
printk(KERN_INFO "Hardware Watchdog Timer for TXx9: "
"timeout=%d sec (max %ld) (nowayout= %d)\n",
timeout, WD_MAX_TIMEOUT, nowayout);
return 0;
exit_busy:
ret = -EBUSY;
exit:
if (txx9_imclk) {
clk_disable(txx9_imclk);
clk_put(txx9_imclk);
}
return ret;
}
static int __exit txx9wdt_remove(struct platform_device *dev)
{
misc_deregister(&txx9wdt_miscdev);
clk_disable(txx9_imclk);
clk_put(txx9_imclk);
return 0;
}
static void txx9wdt_shutdown(struct platform_device *dev)
{
txx9wdt_stop();
}
static int __init watchdog_init(void)
{
return platform_driver_probe(&txx9wdt_driver, txx9wdt_probe);
}
static void __exit watchdog_exit(void)
{
platform_driver_unregister(&txx9wdt_driver);
}
