static void __init at91rm9200_dt_device_init(void)
{
of_platform_default_populate(NULL, NULL, NULL);
at91rm9200_pm_init();
}
