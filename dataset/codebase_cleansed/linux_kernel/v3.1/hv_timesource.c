static cycle_t read_hv_clock(struct clocksource *arg)
{
cycle_t current_tick;
rdmsrl(HV_X64_MSR_TIME_REF_COUNT, current_tick);
return current_tick;
}
static int __init init_hv_clocksource(void)
{
if ((x86_hyper != &x86_hyper_ms_hyperv) ||
!(ms_hyperv.features & HV_X64_MSR_TIME_REF_COUNT_AVAILABLE))
return -ENODEV;
if (!dmi_check_system(hv_timesource_dmi_table))
return -ENODEV;
pr_info("Registering HyperV clock source\n");
return clocksource_register(&hyperv_cs);
}
