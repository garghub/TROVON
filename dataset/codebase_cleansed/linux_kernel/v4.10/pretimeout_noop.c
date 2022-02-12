static void pretimeout_noop(struct watchdog_device *wdd)
{
pr_alert("watchdog%d: pretimeout event\n", wdd->id);
}
static int __init watchdog_gov_noop_register(void)
{
return watchdog_register_governor(&watchdog_gov_noop);
}
static void __exit watchdog_gov_noop_unregister(void)
{
watchdog_unregister_governor(&watchdog_gov_noop);
}
