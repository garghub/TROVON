static void __init sama5_dt_device_init(void)
{
of_platform_default_populate(NULL, NULL, NULL);
sama5_pm_init();
}
