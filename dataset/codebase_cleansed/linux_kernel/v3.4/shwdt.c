static void sh_wdt_start(struct sh_wdt *wdt)
{
unsigned long flags;
u8 csr;
spin_lock_irqsave(&shwdt_lock, flags);
next_heartbeat = jiffies + (heartbeat * HZ);
mod_timer(&wdt->timer, next_ping_period(clock_division_ratio));
csr = sh_wdt_read_csr();
csr |= WTCSR_WT | clock_division_ratio;
sh_wdt_write_csr(csr);
sh_wdt_write_cnt(0);
csr = sh_wdt_read_csr();
csr |= WTCSR_TME;
csr &= ~WTCSR_RSTS;
sh_wdt_write_csr(csr);
#ifdef CONFIG_CPU_SH2
csr = sh_wdt_read_rstcsr();
csr &= ~RSTCSR_RSTS;
sh_wdt_write_rstcsr(csr);
#endif
spin_unlock_irqrestore(&shwdt_lock, flags);
}
static void sh_wdt_stop(struct sh_wdt *wdt)
{
unsigned long flags;
u8 csr;
spin_lock_irqsave(&shwdt_lock, flags);
del_timer(&wdt->timer);
csr = sh_wdt_read_csr();
csr &= ~WTCSR_TME;
sh_wdt_write_csr(csr);
spin_unlock_irqrestore(&shwdt_lock, flags);
}
static inline void sh_wdt_keepalive(struct sh_wdt *wdt)
{
unsigned long flags;
spin_lock_irqsave(&shwdt_lock, flags);
next_heartbeat = jiffies + (heartbeat * HZ);
spin_unlock_irqrestore(&shwdt_lock, flags);
}
static int sh_wdt_set_heartbeat(int t)
{
unsigned long flags;
if (unlikely(t < 1 || t > 3600))
return -EINVAL;
spin_lock_irqsave(&shwdt_lock, flags);
heartbeat = t;
spin_unlock_irqrestore(&shwdt_lock, flags);
return 0;
}
static void sh_wdt_ping(unsigned long data)
{
struct sh_wdt *wdt = (struct sh_wdt *)data;
unsigned long flags;
spin_lock_irqsave(&shwdt_lock, flags);
if (time_before(jiffies, next_heartbeat)) {
u8 csr;
csr = sh_wdt_read_csr();
csr &= ~WTCSR_IOVF;
sh_wdt_write_csr(csr);
sh_wdt_write_cnt(0);
mod_timer(&wdt->timer, next_ping_period(clock_division_ratio));
} else
dev_warn(wdt->dev, "Heartbeat lost! Will not ping "
"the watchdog\n");
spin_unlock_irqrestore(&shwdt_lock, flags);
}
static int sh_wdt_open(struct inode *inode, struct file *file)
{
struct sh_wdt *wdt = platform_get_drvdata(sh_wdt_dev);
if (test_and_set_bit(0, &wdt->enabled))
return -EBUSY;
if (nowayout)
__module_get(THIS_MODULE);
file->private_data = wdt;
sh_wdt_start(wdt);
return nonseekable_open(inode, file);
}
static int sh_wdt_close(struct inode *inode, struct file *file)
{
struct sh_wdt *wdt = file->private_data;
if (wdt->expect_close == 42) {
sh_wdt_stop(wdt);
} else {
dev_crit(wdt->dev, "Unexpected close, not "
"stopping watchdog!\n");
sh_wdt_keepalive(wdt);
}
clear_bit(0, &wdt->enabled);
wdt->expect_close = 0;
return 0;
}
static ssize_t sh_wdt_write(struct file *file, const char *buf,
size_t count, loff_t *ppos)
{
struct sh_wdt *wdt = file->private_data;
if (count) {
if (!nowayout) {
size_t i;
wdt->expect_close = 0;
for (i = 0; i != count; i++) {
char c;
if (get_user(c, buf + i))
return -EFAULT;
if (c == 'V')
wdt->expect_close = 42;
}
}
sh_wdt_keepalive(wdt);
}
return count;
}
static long sh_wdt_ioctl(struct file *file, unsigned int cmd,
unsigned long arg)
{
struct sh_wdt *wdt = file->private_data;
int new_heartbeat;
int options, retval = -EINVAL;
switch (cmd) {
case WDIOC_GETSUPPORT:
return copy_to_user((struct watchdog_info *)arg,
&sh_wdt_info, sizeof(sh_wdt_info)) ? -EFAULT : 0;
case WDIOC_GETSTATUS:
case WDIOC_GETBOOTSTATUS:
return put_user(0, (int *)arg);
case WDIOC_SETOPTIONS:
if (get_user(options, (int *)arg))
return -EFAULT;
if (options & WDIOS_DISABLECARD) {
sh_wdt_stop(wdt);
retval = 0;
}
if (options & WDIOS_ENABLECARD) {
sh_wdt_start(wdt);
retval = 0;
}
return retval;
case WDIOC_KEEPALIVE:
sh_wdt_keepalive(wdt);
return 0;
case WDIOC_SETTIMEOUT:
if (get_user(new_heartbeat, (int *)arg))
return -EFAULT;
if (sh_wdt_set_heartbeat(new_heartbeat))
return -EINVAL;
sh_wdt_keepalive(wdt);
case WDIOC_GETTIMEOUT:
return put_user(heartbeat, (int *)arg);
default:
return -ENOTTY;
}
return 0;
}
static int sh_wdt_notify_sys(struct notifier_block *this,
unsigned long code, void *unused)
{
struct sh_wdt *wdt = platform_get_drvdata(sh_wdt_dev);
if (code == SYS_DOWN || code == SYS_HALT)
sh_wdt_stop(wdt);
return NOTIFY_DONE;
}
static int __devinit sh_wdt_probe(struct platform_device *pdev)
{
struct sh_wdt *wdt;
struct resource *res;
int rc;
if (pdev->id != -1)
return -EINVAL;
res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
if (unlikely(!res))
return -EINVAL;
if (!devm_request_mem_region(&pdev->dev, res->start,
resource_size(res), DRV_NAME))
return -EBUSY;
wdt = devm_kzalloc(&pdev->dev, sizeof(struct sh_wdt), GFP_KERNEL);
if (unlikely(!wdt)) {
rc = -ENOMEM;
goto out_release;
}
wdt->dev = &pdev->dev;
wdt->base = devm_ioremap(&pdev->dev, res->start, resource_size(res));
if (unlikely(!wdt->base)) {
rc = -ENXIO;
goto out_err;
}
rc = register_reboot_notifier(&sh_wdt_notifier);
if (unlikely(rc)) {
dev_err(&pdev->dev,
"Can't register reboot notifier (err=%d)\n", rc);
goto out_unmap;
}
sh_wdt_miscdev.parent = wdt->dev;
rc = misc_register(&sh_wdt_miscdev);
if (unlikely(rc)) {
dev_err(&pdev->dev,
"Can't register miscdev on minor=%d (err=%d)\n",
sh_wdt_miscdev.minor, rc);
goto out_unreg;
}
init_timer(&wdt->timer);
wdt->timer.function = sh_wdt_ping;
wdt->timer.data = (unsigned long)wdt;
wdt->timer.expires = next_ping_period(clock_division_ratio);
platform_set_drvdata(pdev, wdt);
sh_wdt_dev = pdev;
dev_info(&pdev->dev, "initialized.\n");
return 0;
out_unreg:
unregister_reboot_notifier(&sh_wdt_notifier);
out_unmap:
devm_iounmap(&pdev->dev, wdt->base);
out_err:
devm_kfree(&pdev->dev, wdt);
out_release:
devm_release_mem_region(&pdev->dev, res->start, resource_size(res));
return rc;
}
static int __devexit sh_wdt_remove(struct platform_device *pdev)
{
struct sh_wdt *wdt = platform_get_drvdata(pdev);
struct resource *res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
platform_set_drvdata(pdev, NULL);
misc_deregister(&sh_wdt_miscdev);
sh_wdt_dev = NULL;
unregister_reboot_notifier(&sh_wdt_notifier);
devm_release_mem_region(&pdev->dev, res->start, resource_size(res));
devm_iounmap(&pdev->dev, wdt->base);
devm_kfree(&pdev->dev, wdt);
return 0;
}
static int __init sh_wdt_init(void)
{
int rc;
if (unlikely(clock_division_ratio < 0x5 ||
clock_division_ratio > 0x7)) {
clock_division_ratio = WTCSR_CKS_4096;
pr_info("divisor must be 0x5<=x<=0x7, using %d\n",
clock_division_ratio);
}
rc = sh_wdt_set_heartbeat(heartbeat);
if (unlikely(rc)) {
heartbeat = WATCHDOG_HEARTBEAT;
pr_info("heartbeat value must be 1<=x<=3600, using %d\n",
heartbeat);
}
pr_info("configured with heartbeat=%d sec (nowayout=%d)\n",
heartbeat, nowayout);
return platform_driver_register(&sh_wdt_driver);
}
static void __exit sh_wdt_exit(void)
{
platform_driver_unregister(&sh_wdt_driver);
}
