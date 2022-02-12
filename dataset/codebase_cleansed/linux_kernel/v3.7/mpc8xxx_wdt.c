static void mpc8xxx_wdt_keepalive(void)
{
spin_lock(&wdt_spinlock);
out_be16(&wd_base->swsrr, 0x556c);
out_be16(&wd_base->swsrr, 0xaa39);
spin_unlock(&wdt_spinlock);
}
static void mpc8xxx_wdt_timer_ping(unsigned long arg)
{
mpc8xxx_wdt_keepalive();
mod_timer(&wdt_timer, jiffies + HZ * timeout_sec / 2);
}
static void mpc8xxx_wdt_pr_warn(const char *msg)
{
pr_crit("%s, expect the %s soon!\n", msg,
reset ? "reset" : "machine check exception");
}
static ssize_t mpc8xxx_wdt_write(struct file *file, const char __user *buf,
size_t count, loff_t *ppos)
{
if (count)
mpc8xxx_wdt_keepalive();
return count;
}
static int mpc8xxx_wdt_open(struct inode *inode, struct file *file)
{
u32 tmp = SWCRR_SWEN;
if (test_and_set_bit(0, &wdt_is_open))
return -EBUSY;
if (nowayout)
__module_get(THIS_MODULE);
if (prescale)
tmp |= SWCRR_SWPR;
if (reset)
tmp |= SWCRR_SWRI;
tmp |= timeout << 16;
out_be32(&wd_base->swcrr, tmp);
del_timer_sync(&wdt_timer);
return nonseekable_open(inode, file);
}
static int mpc8xxx_wdt_release(struct inode *inode, struct file *file)
{
if (!nowayout)
mpc8xxx_wdt_timer_ping(0);
else
mpc8xxx_wdt_pr_warn("watchdog closed");
clear_bit(0, &wdt_is_open);
return 0;
}
static long mpc8xxx_wdt_ioctl(struct file *file, unsigned int cmd,
unsigned long arg)
{
void __user *argp = (void __user *)arg;
int __user *p = argp;
static const struct watchdog_info ident = {
.options = WDIOF_KEEPALIVEPING,
.firmware_version = 1,
.identity = "MPC8xxx",
};
switch (cmd) {
case WDIOC_GETSUPPORT:
return copy_to_user(argp, &ident, sizeof(ident)) ? -EFAULT : 0;
case WDIOC_GETSTATUS:
case WDIOC_GETBOOTSTATUS:
return put_user(0, p);
case WDIOC_KEEPALIVE:
mpc8xxx_wdt_keepalive();
return 0;
case WDIOC_GETTIMEOUT:
return put_user(timeout_sec, p);
default:
return -ENOTTY;
}
}
static int __devinit mpc8xxx_wdt_probe(struct platform_device *ofdev)
{
int ret;
const struct of_device_id *match;
struct device_node *np = ofdev->dev.of_node;
const struct mpc8xxx_wdt_type *wdt_type;
u32 freq = fsl_get_sys_freq();
bool enabled;
match = of_match_device(mpc8xxx_wdt_match, &ofdev->dev);
if (!match)
return -EINVAL;
wdt_type = match->data;
if (!freq || freq == -1)
return -EINVAL;
wd_base = of_iomap(np, 0);
if (!wd_base)
return -ENOMEM;
enabled = in_be32(&wd_base->swcrr) & SWCRR_SWEN;
if (!enabled && wdt_type->hw_enabled) {
pr_info("could not be enabled in software\n");
ret = -ENOSYS;
goto err_unmap;
}
if (prescale)
timeout_sec = (timeout * wdt_type->prescaler) / freq;
else
timeout_sec = timeout / freq;
#ifdef MODULE
ret = mpc8xxx_wdt_init_late();
if (ret)
goto err_unmap;
#endif
pr_info("WDT driver for MPC8xxx initialized. mode:%s timeout=%d (%d seconds)\n",
reset ? "reset" : "interrupt", timeout, timeout_sec);
if (enabled)
mpc8xxx_wdt_timer_ping(0);
return 0;
err_unmap:
iounmap(wd_base);
wd_base = NULL;
return ret;
}
static int __devexit mpc8xxx_wdt_remove(struct platform_device *ofdev)
{
mpc8xxx_wdt_pr_warn("watchdog removed");
del_timer_sync(&wdt_timer);
misc_deregister(&mpc8xxx_wdt_miscdev);
iounmap(wd_base);
return 0;
}
static int mpc8xxx_wdt_init_late(void)
{
int ret;
if (!wd_base)
return -ENODEV;
ret = misc_register(&mpc8xxx_wdt_miscdev);
if (ret) {
pr_err("cannot register miscdev on minor=%d (err=%d)\n",
WATCHDOG_MINOR, ret);
return ret;
}
return 0;
}
static int __init mpc8xxx_wdt_init(void)
{
return platform_driver_register(&mpc8xxx_wdt_driver);
}
static void __exit mpc8xxx_wdt_exit(void)
{
platform_driver_unregister(&mpc8xxx_wdt_driver);
}
