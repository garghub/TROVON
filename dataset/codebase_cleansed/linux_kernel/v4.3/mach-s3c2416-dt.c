static void __init s3c2416_dt_map_io(void)
{
s3c24xx_init_io(NULL, 0);
}
static void __init s3c2416_dt_machine_init(void)
{
of_platform_populate(NULL, of_default_bus_match_table, NULL, NULL);
s3c_pm_init();
}
