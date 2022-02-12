static void watchdog_fire(unsigned long data)
{
module_put(THIS_MODULE);
if (soft_noboot)
pr_crit("Triggered - Reboot ignored\n");
else if (soft_panic) {
pr_crit("Initiating panic\n");
panic("Software Watchdog Timer expired");
} else {
pr_crit("Initiating system reboot\n");
emergency_restart();
pr_crit("Reboot didn't ?????\n");
}
}
static int softdog_ping(struct watchdog_device *w)
{
if (!mod_timer(&watchdog_ticktock, jiffies+(w->timeout*HZ)))
__module_get(THIS_MODULE);
return 0;
}
static int softdog_stop(struct watchdog_device *w)
{
if (del_timer(&watchdog_ticktock))
module_put(THIS_MODULE);
return 0;
}
static int softdog_set_timeout(struct watchdog_device *w, unsigned int t)
{
w->timeout = t;
return 0;
}
static int __init watchdog_init(void)
{
int ret;
if (soft_margin < 1 || soft_margin > 65535) {
pr_info("soft_margin must be 0 < soft_margin < 65536, using %d\n",
TIMER_MARGIN);
return -EINVAL;
}
softdog_dev.timeout = soft_margin;
watchdog_set_nowayout(&softdog_dev, nowayout);
watchdog_stop_on_reboot(&softdog_dev);
ret = watchdog_register_device(&softdog_dev);
if (ret)
return ret;
pr_info("Software Watchdog Timer: 0.08 initialized. soft_noboot=%d soft_margin=%d sec soft_panic=%d (nowayout=%d)\n",
soft_noboot, soft_margin, soft_panic, nowayout);
return 0;
}
static void __exit watchdog_exit(void)
{
watchdog_unregister_device(&softdog_dev);
}
