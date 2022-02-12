static void __init at91sam9_common_init(void)
{
struct soc_device *soc;
struct device *soc_dev = NULL;
soc = at91_soc_init(at91sam9_socs);
if (soc != NULL)
soc_dev = soc_device_to_device(soc);
of_platform_populate(NULL, of_default_bus_match_table, NULL, soc_dev);
arm_pm_idle = at91sam9_idle;
}
static void __init at91sam9_dt_device_init(void)
{
at91sam9_common_init();
at91sam9260_pm_init();
}
