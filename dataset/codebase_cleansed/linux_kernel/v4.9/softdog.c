static void softdog_fire(unsigned long data)
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
}
static void softdog_pretimeout(unsigned long data)
{
watchdog_notify_pretimeout(&softdog_dev);
}
static int softdog_ping(struct watchdog_device *w)
{
if (!mod_timer(&softdog_ticktock, jiffies + (w->timeout * HZ)))
__module_get(THIS_MODULE);
if (w->pretimeout)
mod_timer(&softdog_preticktock, jiffies +
(w->timeout - w->pretimeout) * HZ);
else
del_timer(&softdog_preticktock);
return 0;
}
static int softdog_stop(struct watchdog_device *w)
{
if (del_timer(&softdog_ticktock))
module_put(THIS_MODULE);
del_timer(&softdog_preticktock);
return 0;
}
static int __init softdog_init(void)
{
int ret;
watchdog_init_timeout(&softdog_dev, soft_margin, NULL);
watchdog_set_nowayout(&softdog_dev, nowayout);
watchdog_stop_on_reboot(&softdog_dev);
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
