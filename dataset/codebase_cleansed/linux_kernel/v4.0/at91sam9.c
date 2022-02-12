static void __init at91sam9_dt_device_init(void)
{
of_platform_populate(NULL, of_default_bus_match_table, NULL, NULL);
arm_pm_idle = at91sam9_idle;
at91sam9260_pm_init();
}
