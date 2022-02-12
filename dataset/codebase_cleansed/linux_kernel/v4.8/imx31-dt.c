static void __init imx31_dt_timer_init(void)
{
mx31_clocks_init_dt();
}
static void __init imx31_dt_mach_init(void)
{
platform_device_register_simple("mxc_rnga", -1, imx31_rnga_res,
ARRAY_SIZE(imx31_rnga_res));
}
