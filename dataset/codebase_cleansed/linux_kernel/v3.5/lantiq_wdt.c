static void
ltq_wdt_enable(void)
{
unsigned long int timeout = ltq_wdt_timeout *
(ltq_io_region_clk_rate / LTQ_WDT_DIVIDER) + 0x1000;
if (timeout > LTQ_MAX_TIMEOUT)
timeout = LTQ_MAX_TIMEOUT;
ltq_w32(LTQ_WDT_PW1, ltq_wdt_membase + LTQ_WDT_CR);
ltq_w32(LTQ_WDT_SR_EN | LTQ_WDT_SR_PWD | LTQ_WDT_SR_CLKDIV |
LTQ_WDT_PW2 | timeout, ltq_wdt_membase + LTQ_WDT_CR);
}
static void
ltq_wdt_disable(void)
{
ltq_w32(LTQ_WDT_PW1, ltq_wdt_membase + LTQ_WDT_CR);
ltq_w32(LTQ_WDT_PW2, ltq_wdt_membase + LTQ_WDT_CR);
}
static ssize_t
ltq_wdt_write(struct file *file, const char __user *data,
size_t len, loff_t *ppos)
{
if (len) {
if (!nowayout) {
size_t i;
ltq_wdt_ok_to_close = 0;
for (i = 0; i != len; i++) {
char c;
if (get_user(c, data + i))
return -EFAULT;
if (c == 'V')
ltq_wdt_ok_to_close = 1;
else
ltq_wdt_ok_to_close = 0;
}
}
ltq_wdt_enable();
}
return len;
}
static long
ltq_wdt_ioctl(struct file *file,
unsigned int cmd, unsigned long arg)
{
int ret = -ENOTTY;
switch (cmd) {
case WDIOC_GETSUPPORT:
ret = copy_to_user((struct watchdog_info __user *)arg, &ident,
sizeof(ident)) ? -EFAULT : 0;
break;
case WDIOC_GETBOOTSTATUS:
ret = put_user(ltq_wdt_bootstatus, (int __user *)arg);
break;
case WDIOC_GETSTATUS:
ret = put_user(0, (int __user *)arg);
break;
case WDIOC_SETTIMEOUT:
ret = get_user(ltq_wdt_timeout, (int __user *)arg);
if (!ret)
ltq_wdt_enable();
case WDIOC_GETTIMEOUT:
ret = put_user(ltq_wdt_timeout, (int __user *)arg);
break;
case WDIOC_KEEPALIVE:
ltq_wdt_enable();
ret = 0;
break;
}
return ret;
}
static int
ltq_wdt_open(struct inode *inode, struct file *file)
{
if (test_and_set_bit(0, &ltq_wdt_in_use))
return -EBUSY;
ltq_wdt_in_use = 1;
ltq_wdt_enable();
return nonseekable_open(inode, file);
}
static int
ltq_wdt_release(struct inode *inode, struct file *file)
{
if (ltq_wdt_ok_to_close)
ltq_wdt_disable();
else
pr_err("watchdog closed without warning\n");
ltq_wdt_ok_to_close = 0;
clear_bit(0, &ltq_wdt_in_use);
return 0;
}
static int __devinit
ltq_wdt_probe(struct platform_device *pdev)
{
struct resource *res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
struct clk *clk;
if (!res) {
dev_err(&pdev->dev, "cannot obtain I/O memory region");
return -ENOENT;
}
ltq_wdt_membase = devm_request_and_ioremap(&pdev->dev, res);
if (!ltq_wdt_membase) {
dev_err(&pdev->dev, "cannot remap I/O memory region\n");
return -ENOMEM;
}
clk = clk_get_io();
if (IS_ERR(clk)) {
dev_err(&pdev->dev, "Failed to get clock\n");
return -ENOENT;
}
ltq_io_region_clk_rate = clk_get_rate(clk);
clk_put(clk);
if (ltq_reset_cause() == LTQ_RST_CAUSE_WDTRST)
ltq_wdt_bootstatus = WDIOF_CARDRESET;
dev_info(&pdev->dev, "Init done\n");
return misc_register(&ltq_wdt_miscdev);
}
static int __devexit
ltq_wdt_remove(struct platform_device *pdev)
{
misc_deregister(&ltq_wdt_miscdev);
return 0;
}
