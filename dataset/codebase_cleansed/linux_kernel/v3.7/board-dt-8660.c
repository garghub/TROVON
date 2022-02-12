static void __init msm8x60_init_irq(void)
{
of_irq_init(msm_dt_gic_match);
}
static void __init msm8x60_init_late(void)
{
smd_debugfs_init();
}
static void __init msm8x60_dt_init(void)
{
of_platform_populate(NULL, of_default_bus_match_table,
msm_auxdata_lookup, NULL);
}
