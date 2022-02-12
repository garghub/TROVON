static inline void ath79_wdt_wr(unsigned reg, u32 val)
{
iowrite32(val, wdt_base + reg);
}
static inline u32 ath79_wdt_rr(unsigned reg)
{
return ioread32(wdt_base + reg);
}
static inline void ath79_wdt_keepalive(void)
{
ath79_wdt_wr(WDOG_REG_TIMER, wdt_freq * timeout);
ath79_wdt_rr(WDOG_REG_TIMER);
}
static inline void ath79_wdt_enable(void)
{
ath79_wdt_keepalive();
udelay(2);
ath79_wdt_wr(WDOG_REG_CTRL, WDOG_CTRL_ACTION_FCR);
ath79_wdt_rr(WDOG_REG_CTRL);
}
static inline void ath79_wdt_disable(void)
{
ath79_wdt_wr(WDOG_REG_CTRL, WDOG_CTRL_ACTION_NONE);
ath79_wdt_rr(WDOG_REG_CTRL);
}
static int ath79_wdt_set_timeout(int val)
{
if (val < 1 || val > max_timeout)
return -EINVAL;
timeout = val;
ath79_wdt_keepalive();
return 0;
}
static int ath79_wdt_open(struct inode *inode, struct file *file)
{
if (test_and_set_bit(WDT_FLAGS_BUSY, &wdt_flags))
return -EBUSY;
clear_bit(WDT_FLAGS_EXPECT_CLOSE, &wdt_flags);
ath79_wdt_enable();
return nonseekable_open(inode, file);
}
static int ath79_wdt_release(struct inode *inode, struct file *file)
{
if (test_bit(WDT_FLAGS_EXPECT_CLOSE, &wdt_flags))
ath79_wdt_disable();
else {
pr_crit("device closed unexpectedly, watchdog timer will not stop!\n");
ath79_wdt_keepalive();
}
clear_bit(WDT_FLAGS_BUSY, &wdt_flags);
clear_bit(WDT_FLAGS_EXPECT_CLOSE, &wdt_flags);
return 0;
}
static ssize_t ath79_wdt_write(struct file *file, const char *data,
size_t len, loff_t *ppos)
{
if (len) {
if (!nowayout) {
size_t i;
clear_bit(WDT_FLAGS_EXPECT_CLOSE, &wdt_flags);
for (i = 0; i != len; i++) {
char c;
if (get_user(c, data + i))
return -EFAULT;
if (c == 'V')
set_bit(WDT_FLAGS_EXPECT_CLOSE,
&wdt_flags);
}
}
ath79_wdt_keepalive();
}
return len;
}
static long ath79_wdt_ioctl(struct file *file, unsigned int cmd,
unsigned long arg)
{
void __user *argp = (void __user *)arg;
int __user *p = argp;
int err;
int t;
switch (cmd) {
case WDIOC_GETSUPPORT:
err = copy_to_user(argp, &ath79_wdt_info,
sizeof(ath79_wdt_info)) ? -EFAULT : 0;
break;
case WDIOC_GETSTATUS:
err = put_user(0, p);
break;
case WDIOC_GETBOOTSTATUS:
err = put_user(boot_status, p);
break;
case WDIOC_KEEPALIVE:
ath79_wdt_keepalive();
err = 0;
break;
case WDIOC_SETTIMEOUT:
err = get_user(t, p);
if (err)
break;
err = ath79_wdt_set_timeout(t);
if (err)
break;
case WDIOC_GETTIMEOUT:
err = put_user(timeout, p);
break;
default:
err = -ENOTTY;
break;
}
return err;
}
static int ath79_wdt_probe(struct platform_device *pdev)
{
struct resource *res;
u32 ctrl;
int err;
if (wdt_base)
return -EBUSY;
res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
wdt_base = devm_ioremap_resource(&pdev->dev, res);
if (IS_ERR(wdt_base))
return PTR_ERR(wdt_base);
wdt_clk = devm_clk_get(&pdev->dev, "wdt");
if (IS_ERR(wdt_clk))
return PTR_ERR(wdt_clk);
err = clk_prepare_enable(wdt_clk);
if (err)
return err;
wdt_freq = clk_get_rate(wdt_clk);
if (!wdt_freq) {
err = -EINVAL;
goto err_clk_disable;
}
max_timeout = (0xfffffffful / wdt_freq);
if (timeout < 1 || timeout > max_timeout) {
timeout = max_timeout;
dev_info(&pdev->dev,
"timeout value must be 0 < timeout < %d, using %d\n",
max_timeout, timeout);
}
ctrl = ath79_wdt_rr(WDOG_REG_CTRL);
boot_status = (ctrl & WDOG_CTRL_LAST_RESET) ? WDIOF_CARDRESET : 0;
err = misc_register(&ath79_wdt_miscdev);
if (err) {
dev_err(&pdev->dev,
"unable to register misc device, err=%d\n", err);
goto err_clk_disable;
}
return 0;
err_clk_disable:
clk_disable_unprepare(wdt_clk);
return err;
}
static int ath79_wdt_remove(struct platform_device *pdev)
{
misc_deregister(&ath79_wdt_miscdev);
clk_disable_unprepare(wdt_clk);
return 0;
}
static void ath97_wdt_shutdown(struct platform_device *pdev)
{
ath79_wdt_disable();
}
