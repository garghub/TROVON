static enum hrtimer_restart softdog_fire(struct hrtimer *timer)
{
module_put(THIS_MODULE);
if (soft_noboot) {
pr_crit("Triggered - Reboot ignored\n");
} else if (soft_panic) {
pr_crit("Initiating panic\n");
panic("Software Watchdog Timer expired");
} else {
pr_crit("Initiating system reboot\n");
emergency_restart();
pr_crit("Reboot didn't ?????\n");
}
return HRTIMER_NORESTART;
}
static enum hrtimer_restart softdog_pretimeout(struct hrtimer *timer)
{
watchdog_notify_pretimeout(&softdog_dev);
return HRTIMER_NORESTART;
}
static int softdog_ping(struct watchdog_device *w)
{
if (!hrtimer_active(&softdog_ticktock))
__module_get(THIS_MODULE);
hrtimer_start(&softdog_ticktock, ktime_set(w->timeout, 0),
HRTIMER_MODE_REL);
if (IS_ENABLED(CONFIG_SOFT_WATCHDOG_PRETIMEOUT)) {
if (w->pretimeout)
hrtimer_start(&softdog_preticktock,
ktime_set(w->timeout - w->pretimeout, 0),
HRTIMER_MODE_REL);
else
hrtimer_cancel(&softdog_preticktock);
}
return 0;
}
static int softdog_stop(struct watchdog_device *w)
{
if (hrtimer_cancel(&softdog_ticktock))
module_put(THIS_MODULE);
if (IS_ENABLED(CONFIG_SOFT_WATCHDOG_PRETIMEOUT))
hrtimer_cancel(&softdog_preticktock);
return 0;
}
static int __init softdog_init(void)
{
int ret;
watchdog_init_timeout(&softdog_dev, soft_margin, NULL);
watchdog_set_nowayout(&softdog_dev, nowayout);
watchdog_stop_on_reboot(&softdog_dev);
hrtimer_init(&softdog_ticktock, CLOCK_MONOTONIC, HRTIMER_MODE_REL);
softdog_ticktock.function = softdog_fire;
if (IS_ENABLED(CONFIG_SOFT_WATCHDOG_PRETIMEOUT)) {
softdog_info.options |= WDIOF_PRETIMEOUT;
hrtimer_init(&softdog_preticktock, CLOCK_MONOTONIC,
HRTIMER_MODE_REL);
softdog_preticktock.function = softdog_pretimeout;
}
ret = watchdog_register_device(&softdog_dev);
if (ret)
return ret;
pr_info("initialized. soft_noboot=%d soft_margin=%d sec soft_panic=%d (nowayout=%d)\n",
soft_noboot, softdog_dev.timeout, soft_panic, nowayout);
return 0;
}
static void __exit softdog_exit(void)
{
watchdog_unregister_device(&softdog_dev);
}
