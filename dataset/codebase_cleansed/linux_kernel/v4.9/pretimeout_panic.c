static void pretimeout_panic(struct watchdog_device *wdd)
{
panic("watchdog pretimeout event\n");
}
static int __init watchdog_gov_panic_register(void)
{
return watchdog_register_governor(&watchdog_gov_panic);
}
static void __exit watchdog_gov_panic_unregister(void)
{
watchdog_unregister_governor(&watchdog_gov_panic);
}
