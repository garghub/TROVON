static void mpc8xxx_wdt_keepalive(struct mpc8xxx_wdt_ddata *ddata)
{
spin_lock(&ddata->lock);
out_be16(&ddata->base->swsrr, 0x556c);
out_be16(&ddata->base->swsrr, 0xaa39);
spin_unlock(&ddata->lock);
}
static void mpc8xxx_wdt_timer_ping(unsigned long arg)
{
struct mpc8xxx_wdt_ddata *ddata = (void *)arg;
mpc8xxx_wdt_keepalive(ddata);
mod_timer(&ddata->timer, jiffies + HZ * ddata->wdd.timeout / 2);
}
static int mpc8xxx_wdt_start(struct watchdog_device *w)
{
struct mpc8xxx_wdt_ddata *ddata =
container_of(w, struct mpc8xxx_wdt_ddata, wdd);
u32 tmp = SWCRR_SWEN | SWCRR_SWPR;
if (reset)
tmp |= SWCRR_SWRI;
tmp |= timeout << 16;
out_be32(&ddata->base->swcrr, tmp);
del_timer_sync(&ddata->timer);
return 0;
}
static int mpc8xxx_wdt_ping(struct watchdog_device *w)
{
struct mpc8xxx_wdt_ddata *ddata =
container_of(w, struct mpc8xxx_wdt_ddata, wdd);
mpc8xxx_wdt_keepalive(ddata);
return 0;
}
static int mpc8xxx_wdt_stop(struct watchdog_device *w)
{
struct mpc8xxx_wdt_ddata *ddata =
container_of(w, struct mpc8xxx_wdt_ddata, wdd);
mod_timer(&ddata->timer, jiffies);
return 0;
}
static int mpc8xxx_wdt_probe(struct platform_device *ofdev)
{
int ret;
struct resource *res;
const struct mpc8xxx_wdt_type *wdt_type;
struct mpc8xxx_wdt_ddata *ddata;
u32 freq = fsl_get_sys_freq();
bool enabled;
unsigned int timeout_sec;
wdt_type = of_device_get_match_data(&ofdev->dev);
if (!wdt_type)
return -EINVAL;
if (!freq || freq == -1)
return -EINVAL;
ddata = devm_kzalloc(&ofdev->dev, sizeof(*ddata), GFP_KERNEL);
if (!ddata)
return -ENOMEM;
res = platform_get_resource(ofdev, IORESOURCE_MEM, 0);
ddata->base = devm_ioremap_resource(&ofdev->dev, res);
if (IS_ERR(ddata->base))
return PTR_ERR(ddata->base);
enabled = in_be32(&ddata->base->swcrr) & SWCRR_SWEN;
if (!enabled && wdt_type->hw_enabled) {
pr_info("could not be enabled in software\n");
return -ENODEV;
}
spin_lock_init(&ddata->lock);
setup_timer(&ddata->timer, mpc8xxx_wdt_timer_ping,
(unsigned long)ddata);
ddata->wdd.info = &mpc8xxx_wdt_info,
ddata->wdd.ops = &mpc8xxx_wdt_ops,
timeout_sec = (timeout * wdt_type->prescaler) / freq;
ddata->wdd.timeout = timeout_sec;
watchdog_set_nowayout(&ddata->wdd, nowayout);
ret = watchdog_register_device(&ddata->wdd);
if (ret) {
pr_err("cannot register watchdog device (err=%d)\n", ret);
return ret;
}
pr_info("WDT driver for MPC8xxx initialized. mode:%s timeout=%d (%d seconds)\n",
reset ? "reset" : "interrupt", timeout, timeout_sec);
if (enabled)
mod_timer(&ddata->timer, jiffies);
platform_set_drvdata(ofdev, ddata);
return 0;
}
static int mpc8xxx_wdt_remove(struct platform_device *ofdev)
{
struct mpc8xxx_wdt_ddata *ddata = platform_get_drvdata(ofdev);
pr_crit("Watchdog removed, expect the %s soon!\n",
reset ? "reset" : "machine check exception");
del_timer_sync(&ddata->timer);
watchdog_unregister_device(&ddata->wdd);
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
