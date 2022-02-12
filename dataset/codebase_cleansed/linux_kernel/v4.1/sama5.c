static void __init sama5_dt_device_init(void)
{
struct soc_device *soc;
struct device *soc_dev = NULL;
soc = at91_soc_init(sama5_socs);
if (soc != NULL)
soc_dev = soc_device_to_device(soc);
of_platform_populate(NULL, of_default_bus_match_table, NULL, soc_dev);
at91sam9x5_pm_init();
}
