u64 gb_timesync_platform_get_counter(void)
{
return (u64)get_cycles();
}
u32 gb_timesync_platform_get_clock_rate(void)
{
if (unlikely(!gb_timesync_clock_frequency)) {
gb_timesync_clock_frequency = cpufreq_get(0);
if (!gb_timesync_clock_frequency)
gb_timesync_clock_frequency = DEFAULT_FRAMETIME_CLOCK_HZ;
}
return gb_timesync_clock_frequency;
}
int gb_timesync_platform_lock_bus(struct gb_timesync_svc *pdata)
{
return arche_platform_change_state_cb(ARCHE_PLATFORM_STATE_TIME_SYNC,
pdata);
}
void gb_timesync_platform_unlock_bus(void)
{
arche_platform_change_state_cb(ARCHE_PLATFORM_STATE_ACTIVE, NULL);
}
int __init gb_timesync_platform_init(void)
{
struct device_node *np;
np = of_find_matching_node(NULL, arch_timer_of_match);
if (!np) {
pr_warn("Unable to find a compatible ARMv7 timer\n");
return 0;
}
if (of_property_read_u32(np, "clock-frequency",
&gb_timesync_clock_frequency)) {
pr_err("Unable to find timer clock-frequency\n");
return -ENODEV;
}
return 0;
}
void gb_timesync_platform_exit(void) {}
