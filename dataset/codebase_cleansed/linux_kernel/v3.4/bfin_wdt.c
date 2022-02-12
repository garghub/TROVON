static int bfin_wdt_keepalive(void)
{
stampit();
bfin_write_WDOG_STAT(0);
return 0;
}
static int bfin_wdt_stop(void)
{
stampit();
bfin_write_WDOG_CTL(WDEN_DISABLE);
return 0;
}
static int bfin_wdt_start(void)
{
stampit();
bfin_write_WDOG_CTL(WDEN_ENABLE | ICTL_RESET);
return 0;
}
static int bfin_wdt_running(void)
{
stampit();
return ((bfin_read_WDOG_CTL() & WDEN_MASK) != WDEN_DISABLE);
}
static int bfin_wdt_set_timeout(unsigned long t)
{
u32 cnt, max_t, sclk;
unsigned long flags;
sclk = get_sclk();
max_t = -1 / sclk;
cnt = t * sclk;
stamp("maxtimeout=%us newtimeout=%lus (cnt=%#x)", max_t, t, cnt);
if (t > max_t) {
pr_warn("timeout value is too large\n");
return -EINVAL;
}
spin_lock_irqsave(&bfin_wdt_spinlock, flags);
{
int run = bfin_wdt_running();
bfin_wdt_stop();
bfin_write_WDOG_CNT(cnt);
if (run)
bfin_wdt_start();
}
spin_unlock_irqrestore(&bfin_wdt_spinlock, flags);
timeout = t;
return 0;
}
static int bfin_wdt_open(struct inode *inode, struct file *file)
{
stampit();
if (test_and_set_bit(0, &open_check))
return -EBUSY;
if (nowayout)
__module_get(THIS_MODULE);
bfin_wdt_keepalive();
bfin_wdt_start();
return nonseekable_open(inode, file);
}
static int bfin_wdt_release(struct inode *inode, struct file *file)
{
stampit();
if (expect_close == 42)
bfin_wdt_stop();
else {
pr_crit("Unexpected close, not stopping watchdog!\n");
bfin_wdt_keepalive();
}
expect_close = 0;
clear_bit(0, &open_check);
return 0;
}
static ssize_t bfin_wdt_write(struct file *file, const char __user *data,
size_t len, loff_t *ppos)
{
stampit();
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
bfin_wdt_keepalive();
}
return len;
}
static long bfin_wdt_ioctl(struct file *file,
unsigned int cmd, unsigned long arg)
{
void __user *argp = (void __user *)arg;
int __user *p = argp;
stampit();
switch (cmd) {
case WDIOC_GETSUPPORT:
if (copy_to_user(argp, &bfin_wdt_info, sizeof(bfin_wdt_info)))
return -EFAULT;
else
return 0;
case WDIOC_GETSTATUS:
case WDIOC_GETBOOTSTATUS:
return put_user(!!(_bfin_swrst & SWRST_RESET_WDOG), p);
case WDIOC_SETOPTIONS: {
unsigned long flags;
int options, ret = -EINVAL;
if (get_user(options, p))
return -EFAULT;
spin_lock_irqsave(&bfin_wdt_spinlock, flags);
if (options & WDIOS_DISABLECARD) {
bfin_wdt_stop();
ret = 0;
}
if (options & WDIOS_ENABLECARD) {
bfin_wdt_start();
ret = 0;
}
spin_unlock_irqrestore(&bfin_wdt_spinlock, flags);
return ret;
}
case WDIOC_KEEPALIVE:
bfin_wdt_keepalive();
return 0;
case WDIOC_SETTIMEOUT: {
int new_timeout;
if (get_user(new_timeout, p))
return -EFAULT;
if (bfin_wdt_set_timeout(new_timeout))
return -EINVAL;
}
case WDIOC_GETTIMEOUT:
return put_user(timeout, p);
default:
return -ENOTTY;
}
}
static int bfin_wdt_suspend(struct platform_device *pdev, pm_message_t state)
{
stampit();
state_before_suspend = bfin_wdt_running();
bfin_wdt_stop();
return 0;
}
static int bfin_wdt_resume(struct platform_device *pdev)
{
stampit();
if (state_before_suspend) {
bfin_wdt_set_timeout(timeout);
bfin_wdt_start();
}
return 0;
}
static int __devinit bfin_wdt_probe(struct platform_device *pdev)
{
int ret;
ret = misc_register(&bfin_wdt_miscdev);
if (ret) {
pr_err("cannot register miscdev on minor=%d (err=%d)\n",
WATCHDOG_MINOR, ret);
return ret;
}
pr_info("initialized: timeout=%d sec (nowayout=%d)\n",
timeout, nowayout);
return 0;
}
static int __devexit bfin_wdt_remove(struct platform_device *pdev)
{
misc_deregister(&bfin_wdt_miscdev);
return 0;
}
static void bfin_wdt_shutdown(struct platform_device *pdev)
{
stampit();
bfin_wdt_stop();
}
static int __init bfin_wdt_init(void)
{
int ret;
stampit();
if (bfin_wdt_set_timeout(timeout))
return -EINVAL;
ret = platform_driver_register(&bfin_wdt_driver);
if (ret) {
pr_err("unable to register driver\n");
return ret;
}
bfin_wdt_device = platform_device_register_simple(WATCHDOG_NAME,
-1, NULL, 0);
if (IS_ERR(bfin_wdt_device)) {
pr_err("unable to register device\n");
platform_driver_unregister(&bfin_wdt_driver);
return PTR_ERR(bfin_wdt_device);
}
return 0;
}
static void __exit bfin_wdt_exit(void)
{
platform_device_unregister(bfin_wdt_device);
platform_driver_unregister(&bfin_wdt_driver);
}
