static void __init imx6sl_init_machine(void)
{
mxc_arch_reset_init_dt();
of_platform_populate(NULL, of_default_bus_match_table, NULL, NULL);
}
static void __init imx6sl_init_irq(void)
{
l2x0_of_init(0, ~0UL);
imx_src_init();
imx_gpc_init();
irqchip_init();
}
static void __init imx6sl_timer_init(void)
{
of_clk_init(NULL);
}
