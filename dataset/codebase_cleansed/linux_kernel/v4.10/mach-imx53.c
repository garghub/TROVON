static void __init imx53_init_early(void)
{
mxc_set_cpu_type(MXC_CPU_MX53);
}
static void __init imx53_dt_init(void)
{
imx_src_init();
imx_aips_allow_unprivileged_access("fsl,imx53-aipstz");
}
static void __init imx53_init_late(void)
{
imx53_pm_init();
}
