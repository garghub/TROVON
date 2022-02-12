static void __init at91rm9200_dt_device_init(void)
{
struct soc_device *soc;
struct device *soc_dev = NULL;
soc = at91_soc_init(rm9200_socs);
if (soc != NULL)
soc_dev = soc_device_to_device(soc);
of_platform_populate(NULL, of_default_bus_match_table, NULL, soc_dev);
arm_pm_idle = at91rm9200_idle;
at91rm9200_pm_init();
}
