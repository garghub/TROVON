static void __init imx35_dt_init(void)
{
mxc_arch_reset_init_dt();
of_platform_populate(NULL, of_default_bus_match_table,
NULL, NULL);
}
static void __init imx35_irq_init(void)
{
imx_init_l2cache();
mx35_init_irq();
}
