static void __init msm_dt_init_irq(void)
{
of_irq_init(msm_dt_gic_match);
}
static void __init msm_dt_init(void)
{
of_platform_populate(NULL, of_default_bus_match_table, NULL, NULL);
}
