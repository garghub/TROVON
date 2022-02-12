static inline void at32_wdt_stop(void)
{
unsigned long psel;
spin_lock(&wdt->io_lock);
psel = wdt_readl(wdt, CTRL) & WDT_BF(CTRL_PSEL, 0x0f);
wdt_writel(wdt, CTRL, psel | WDT_BF(CTRL_KEY, 0x55));
wdt_writel(wdt, CTRL, psel | WDT_BF(CTRL_KEY, 0xaa));
spin_unlock(&wdt->io_lock);
}
static inline void at32_wdt_start(void)
{
unsigned long psel = (wdt->timeout > 1) ? 0xf : 0xe;
spin_lock(&wdt->io_lock);
wdt_writel(wdt, CTRL, WDT_BIT(CTRL_EN)
| WDT_BF(CTRL_PSEL, psel)
| WDT_BF(CTRL_KEY, 0x55));
wdt_writel(wdt, CTRL, WDT_BIT(CTRL_EN)
| WDT_BF(CTRL_PSEL, psel)
| WDT_BF(CTRL_KEY, 0xaa));
spin_unlock(&wdt->io_lock);
}
static inline void at32_wdt_pat(void)
{
spin_lock(&wdt->io_lock);
wdt_writel(wdt, CLR, 0x42);
spin_unlock(&wdt->io_lock);
}
static int at32_wdt_open(struct inode *inode, struct file *file)
{
if (test_and_set_bit(1, &wdt->users))
return -EBUSY;
at32_wdt_start();
return nonseekable_open(inode, file);
}
static int at32_wdt_close(struct inode *inode, struct file *file)
{
if (expect_release == 42) {
at32_wdt_stop();
} else {
dev_dbg(wdt->miscdev.parent,
"unexpected close, not stopping watchdog!\n");
at32_wdt_pat();
}
clear_bit(1, &wdt->users);
expect_release = 0;
return 0;
}
static int at32_wdt_settimeout(int time)
{
if ((time < TIMEOUT_MIN) || (time > TIMEOUT_MAX))
return -EINVAL;
wdt->timeout = time;
return 0;
}
static int at32_wdt_get_status(void)
{
int rcause;
int status = 0;
rcause = wdt_readl(wdt, RCAUSE);
switch (rcause) {
case WDT_BIT(RCAUSE_EXT):
status = WDIOF_EXTERN1;
break;
case WDT_BIT(RCAUSE_WDT):
status = WDIOF_CARDRESET;
break;
case WDT_BIT(RCAUSE_POR):
case WDT_BIT(RCAUSE_JTAG):
case WDT_BIT(RCAUSE_SERP):
default:
break;
}
return status;
}
static long at32_wdt_ioctl(struct file *file,
unsigned int cmd, unsigned long arg)
{
int ret = -ENOTTY;
int time;
void __user *argp = (void __user *)arg;
int __user *p = argp;
switch (cmd) {
case WDIOC_GETSUPPORT:
ret = copy_to_user(argp, &at32_wdt_info,
sizeof(at32_wdt_info)) ? -EFAULT : 0;
break;
case WDIOC_GETSTATUS:
ret = put_user(0, p);
break;
case WDIOC_GETBOOTSTATUS:
ret = put_user(wdt->boot_status, p);
break;
case WDIOC_SETOPTIONS:
ret = get_user(time, p);
if (ret)
break;
if (time & WDIOS_DISABLECARD)
at32_wdt_stop();
if (time & WDIOS_ENABLECARD)
at32_wdt_start();
ret = 0;
break;
case WDIOC_KEEPALIVE:
at32_wdt_pat();
ret = 0;
break;
case WDIOC_SETTIMEOUT:
ret = get_user(time, p);
if (ret)
break;
ret = at32_wdt_settimeout(time);
if (ret)
break;
at32_wdt_start();
case WDIOC_GETTIMEOUT:
ret = put_user(wdt->timeout, p);
break;
}
return ret;
}
static ssize_t at32_wdt_write(struct file *file, const char __user *data,
size_t len, loff_t *ppos)
{
if (len) {
if (!nowayout) {
size_t i;
expect_release = 0;
for (i = 0; i != len; i++) {
char c;
if (get_user(c, data + i))
return -EFAULT;
if (c == 'V')
expect_release = 42;
}
}
at32_wdt_pat();
}
return len;
}
static int __init at32_wdt_probe(struct platform_device *pdev)
{
struct resource *regs;
int ret;
if (wdt) {
dev_dbg(&pdev->dev, "only 1 wdt instance supported.\n");
return -EBUSY;
}
regs = platform_get_resource(pdev, IORESOURCE_MEM, 0);
if (!regs) {
dev_dbg(&pdev->dev, "missing mmio resource\n");
return -ENXIO;
}
wdt = devm_kzalloc(&pdev->dev, sizeof(struct wdt_at32ap700x),
GFP_KERNEL);
if (!wdt) {
dev_dbg(&pdev->dev, "no memory for wdt structure\n");
return -ENOMEM;
}
wdt->regs = devm_ioremap(&pdev->dev, regs->start, resource_size(regs));
if (!wdt->regs) {
ret = -ENOMEM;
dev_dbg(&pdev->dev, "could not map I/O memory\n");
goto err_free;
}
spin_lock_init(&wdt->io_lock);
wdt->boot_status = at32_wdt_get_status();
if (wdt->boot_status & WDIOF_CARDRESET) {
dev_info(&pdev->dev, "CPU must be reset with external "
"reset or POR due to silicon errata.\n");
ret = -EIO;
goto err_free;
} else {
wdt->users = 0;
}
wdt->miscdev.minor = WATCHDOG_MINOR;
wdt->miscdev.name = "watchdog";
wdt->miscdev.fops = &at32_wdt_fops;
wdt->miscdev.parent = &pdev->dev;
platform_set_drvdata(pdev, wdt);
if (at32_wdt_settimeout(timeout)) {
at32_wdt_settimeout(TIMEOUT_DEFAULT);
dev_dbg(&pdev->dev,
"default timeout invalid, set to %d sec.\n",
TIMEOUT_DEFAULT);
}
ret = misc_register(&wdt->miscdev);
if (ret) {
dev_dbg(&pdev->dev, "failed to register wdt miscdev\n");
goto err_free;
}
dev_info(&pdev->dev,
"AT32AP700X WDT at 0x%p, timeout %d sec (nowayout=%d)\n",
wdt->regs, wdt->timeout, nowayout);
return 0;
err_free:
wdt = NULL;
return ret;
}
static int __exit at32_wdt_remove(struct platform_device *pdev)
{
if (wdt && platform_get_drvdata(pdev) == wdt) {
if (!nowayout)
at32_wdt_stop();
misc_deregister(&wdt->miscdev);
wdt = NULL;
}
return 0;
}
static void at32_wdt_shutdown(struct platform_device *pdev)
{
at32_wdt_stop();
}
static int at32_wdt_suspend(struct platform_device *pdev, pm_message_t message)
{
at32_wdt_stop();
return 0;
}
static int at32_wdt_resume(struct platform_device *pdev)
{
if (wdt->users)
at32_wdt_start();
return 0;
}
