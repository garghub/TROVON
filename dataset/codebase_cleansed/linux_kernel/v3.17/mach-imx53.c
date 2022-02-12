static void __init imx53_init_early(void)
{
mxc_set_cpu_type(MXC_CPU_MX53);
}
static void __init imx53_dt_init(void)
{
mxc_arch_reset_init_dt();
imx_src_init();
of_platform_populate(NULL, of_default_bus_match_table, NULL, NULL);
imx_aips_allow_unprivileged_access("fsl,imx53-aipstz");
}
static void __init imx53_init_late(void)
{
imx53_pm_init();
}
