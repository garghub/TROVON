static void __init s3c64xx_dt_map_io(void)
{
debug_ll_io_init();
iotable_init(s3c64xx_dt_iodesc, ARRAY_SIZE(s3c64xx_dt_iodesc));
s3c64xx_init_cpu();
if (!soc_is_s3c64xx())
panic("SoC is not S3C64xx!");
}
static void __init s3c64xx_dt_init_machine(void)
{
samsung_wdt_reset_of_init();
of_platform_populate(NULL, of_default_bus_match_table, NULL, NULL);
}
static void s3c64xx_dt_restart(enum reboot_mode mode, const char *cmd)
{
if (mode != REBOOT_SOFT)
samsung_wdt_reset();
soft_restart(0);
}
