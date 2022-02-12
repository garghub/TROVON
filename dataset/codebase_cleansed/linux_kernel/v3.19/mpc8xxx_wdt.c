static void mpc8xxx_wdt_keepalive(void)
{
spin_lock(&wdt_spinlock);
out_be16(&wd_base->swsrr, 0x556c);
out_be16(&wd_base->swsrr, 0xaa39);
spin_unlock(&wdt_spinlock);
}
static void mpc8xxx_wdt_timer_ping(unsigned long arg)
{
struct watchdog_device *w = (struct watchdog_device *)arg;
mpc8xxx_wdt_keepalive();
mod_timer(&wdt_timer, jiffies + HZ * w->timeout / 2);
}
static int mpc8xxx_wdt_start(struct watchdog_device *w)
{
u32 tmp = SWCRR_SWEN;
if (prescale)
tmp |= SWCRR_SWPR;
if (reset)
tmp |= SWCRR_SWRI;
tmp |= timeout << 16;
out_be32(&wd_base->swcrr, tmp);
del_timer_sync(&wdt_timer);
return 0;
}
static int mpc8xxx_wdt_ping(struct watchdog_device *w)
{
mpc8xxx_wdt_keepalive();
return 0;
}
static int mpc8xxx_wdt_stop(struct watchdog_device *w)
{
mod_timer(&wdt_timer, jiffies);
return 0;
}
static int mpc8xxx_wdt_probe(struct platform_device *ofdev)
{
int ret;
const struct of_device_id *match;
struct device_node *np = ofdev->dev.of_node;
const struct mpc8xxx_wdt_type *wdt_type;
u32 freq = fsl_get_sys_freq();
bool enabled;
unsigned int timeout_sec;
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
mpc8xxx_wdt_dev.timeout = timeout_sec;
#ifdef MODULE
ret = mpc8xxx_wdt_init_late();
if (ret)
goto err_unmap;
#endif
pr_info("WDT driver for MPC8xxx initialized. mode:%s timeout=%d (%d seconds)\n",
reset ? "reset" : "interrupt", timeout, timeout_sec);
if (enabled)
mod_timer(&wdt_timer, jiffies);
return 0;
err_unmap:
iounmap(wd_base);
wd_base = NULL;
return ret;
}
static int mpc8xxx_wdt_remove(struct platform_device *ofdev)
{
pr_crit("Watchdog removed, expect the %s soon!\n",
reset ? "reset" : "machine check exception");
del_timer_sync(&wdt_timer);
watchdog_unregister_device(&mpc8xxx_wdt_dev);
iounmap(wd_base);
return 0;
}
static int mpc8xxx_wdt_init_late(void)
{
int ret;
if (!wd_base)
return -ENODEV;
watchdog_set_nowayout(&mpc8xxx_wdt_dev, nowayout);
ret = watchdog_register_device(&mpc8xxx_wdt_dev);
if (ret) {
pr_err("cannot register watchdog device (err=%d)\n", ret);
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
