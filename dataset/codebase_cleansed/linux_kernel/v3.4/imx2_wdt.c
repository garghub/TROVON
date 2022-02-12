static inline void imx2_wdt_setup(void)
{
u16 val = __raw_readw(imx2_wdt.base + IMX2_WDT_WCR);
val &= ~IMX2_WDT_WCR_WT;
val &= ~IMX2_WDT_WCR_WRE;
val &= ~IMX2_WDT_WCR_WDE;
val |= WDOG_SEC_TO_COUNT(imx2_wdt.timeout);
__raw_writew(val, imx2_wdt.base + IMX2_WDT_WCR);
val |= IMX2_WDT_WCR_WDE;
__raw_writew(val, imx2_wdt.base + IMX2_WDT_WCR);
}
static inline void imx2_wdt_ping(void)
{
__raw_writew(IMX2_WDT_SEQ1, imx2_wdt.base + IMX2_WDT_WSR);
__raw_writew(IMX2_WDT_SEQ2, imx2_wdt.base + IMX2_WDT_WSR);
}
static void imx2_wdt_timer_ping(unsigned long arg)
{
imx2_wdt_ping();
mod_timer(&imx2_wdt.timer, jiffies + imx2_wdt.timeout * HZ / 2);
}
static void imx2_wdt_start(void)
{
if (!test_and_set_bit(IMX2_WDT_STATUS_STARTED, &imx2_wdt.status)) {
clk_enable(imx2_wdt.clk);
imx2_wdt_setup();
} else
del_timer_sync(&imx2_wdt.timer);
imx2_wdt_ping();
}
static void imx2_wdt_stop(void)
{
imx2_wdt_timer_ping(0);
}
static void imx2_wdt_set_timeout(int new_timeout)
{
u16 val = __raw_readw(imx2_wdt.base + IMX2_WDT_WCR);
val &= ~IMX2_WDT_WCR_WT;
val |= WDOG_SEC_TO_COUNT(new_timeout);
__raw_writew(val, imx2_wdt.base + IMX2_WDT_WCR);
}
static int imx2_wdt_open(struct inode *inode, struct file *file)
{
if (test_and_set_bit(IMX2_WDT_STATUS_OPEN, &imx2_wdt.status))
return -EBUSY;
imx2_wdt_start();
return nonseekable_open(inode, file);
}
static int imx2_wdt_close(struct inode *inode, struct file *file)
{
if (test_bit(IMX2_WDT_EXPECT_CLOSE, &imx2_wdt.status) && !nowayout)
imx2_wdt_stop();
else {
dev_crit(imx2_wdt_miscdev.parent,
"Unexpected close: Expect reboot!\n");
imx2_wdt_ping();
}
clear_bit(IMX2_WDT_EXPECT_CLOSE, &imx2_wdt.status);
clear_bit(IMX2_WDT_STATUS_OPEN, &imx2_wdt.status);
return 0;
}
static long imx2_wdt_ioctl(struct file *file, unsigned int cmd,
unsigned long arg)
{
void __user *argp = (void __user *)arg;
int __user *p = argp;
int new_value;
u16 val;
switch (cmd) {
case WDIOC_GETSUPPORT:
return copy_to_user(argp, &imx2_wdt_info,
sizeof(struct watchdog_info)) ? -EFAULT : 0;
case WDIOC_GETSTATUS:
return put_user(0, p);
case WDIOC_GETBOOTSTATUS:
val = __raw_readw(imx2_wdt.base + IMX2_WDT_WRSR);
new_value = val & IMX2_WDT_WRSR_TOUT ? WDIOF_CARDRESET : 0;
return put_user(new_value, p);
case WDIOC_KEEPALIVE:
imx2_wdt_ping();
return 0;
case WDIOC_SETTIMEOUT:
if (get_user(new_value, p))
return -EFAULT;
if ((new_value < 1) || (new_value > IMX2_WDT_MAX_TIME))
return -EINVAL;
imx2_wdt_set_timeout(new_value);
imx2_wdt.timeout = new_value;
imx2_wdt_ping();
case WDIOC_GETTIMEOUT:
return put_user(imx2_wdt.timeout, p);
default:
return -ENOTTY;
}
}
static ssize_t imx2_wdt_write(struct file *file, const char __user *data,
size_t len, loff_t *ppos)
{
size_t i;
char c;
if (len == 0)
return 0;
clear_bit(IMX2_WDT_EXPECT_CLOSE, &imx2_wdt.status);
for (i = 0; i != len; i++) {
if (get_user(c, data + i))
return -EFAULT;
if (c == 'V')
set_bit(IMX2_WDT_EXPECT_CLOSE, &imx2_wdt.status);
}
imx2_wdt_ping();
return len;
}
static int __init imx2_wdt_probe(struct platform_device *pdev)
{
int ret;
struct resource *res;
res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
if (!res) {
dev_err(&pdev->dev, "can't get device resources\n");
return -ENODEV;
}
imx2_wdt.base = devm_request_and_ioremap(&pdev->dev, res);
if (!imx2_wdt.base) {
dev_err(&pdev->dev, "ioremap failed\n");
return -ENOMEM;
}
imx2_wdt.clk = clk_get(&pdev->dev, NULL);
if (IS_ERR(imx2_wdt.clk)) {
dev_err(&pdev->dev, "can't get Watchdog clock\n");
return PTR_ERR(imx2_wdt.clk);
}
imx2_wdt.timeout = clamp_t(unsigned, timeout, 1, IMX2_WDT_MAX_TIME);
if (imx2_wdt.timeout != timeout)
dev_warn(&pdev->dev, "Initial timeout out of range! "
"Clamped from %u to %u\n", timeout, imx2_wdt.timeout);
setup_timer(&imx2_wdt.timer, imx2_wdt_timer_ping, 0);
imx2_wdt_miscdev.parent = &pdev->dev;
ret = misc_register(&imx2_wdt_miscdev);
if (ret)
goto fail;
dev_info(&pdev->dev,
"IMX2+ Watchdog Timer enabled. timeout=%ds (nowayout=%d)\n",
imx2_wdt.timeout, nowayout);
return 0;
fail:
imx2_wdt_miscdev.parent = NULL;
clk_put(imx2_wdt.clk);
return ret;
}
static int __exit imx2_wdt_remove(struct platform_device *pdev)
{
misc_deregister(&imx2_wdt_miscdev);
if (test_bit(IMX2_WDT_STATUS_STARTED, &imx2_wdt.status)) {
del_timer_sync(&imx2_wdt.timer);
dev_crit(imx2_wdt_miscdev.parent,
"Device removed: Expect reboot!\n");
} else
clk_put(imx2_wdt.clk);
imx2_wdt_miscdev.parent = NULL;
return 0;
}
static void imx2_wdt_shutdown(struct platform_device *pdev)
{
if (test_bit(IMX2_WDT_STATUS_STARTED, &imx2_wdt.status)) {
del_timer_sync(&imx2_wdt.timer);
imx2_wdt_set_timeout(IMX2_WDT_MAX_TIME);
imx2_wdt_ping();
dev_crit(imx2_wdt_miscdev.parent,
"Device shutdown: Expect reboot!\n");
}
}
static int __init imx2_wdt_init(void)
{
return platform_driver_probe(&imx2_wdt_driver, imx2_wdt_probe);
}
static void __exit imx2_wdt_exit(void)
{
platform_driver_unregister(&imx2_wdt_driver);
}
