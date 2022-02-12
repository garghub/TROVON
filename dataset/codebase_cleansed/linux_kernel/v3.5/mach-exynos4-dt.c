static void __init exynos4210_dt_map_io(void)
{
exynos_init_io(NULL, 0);
s3c24xx_init_clocks(24000000);
}
static void __init exynos4210_dt_machine_init(void)
{
of_platform_populate(NULL, of_default_bus_match_table,
exynos4210_auxdata_lookup, NULL);
}
