static void __init imx51_init_early(void)
{
mxc_set_cpu_type(MXC_CPU_MX51);
}
static void __init imx51_ipu_mipi_setup(void)
{
void __iomem *hsc_addr;
hsc_addr = ioremap(MX51_MIPI_HSC_BASE, SZ_16K);
WARN_ON(!hsc_addr);
__raw_writel(0xf00, hsc_addr);
__raw_writel(__raw_readl(hsc_addr + 0x800) | 0x30ff,
hsc_addr + 0x800);
iounmap(hsc_addr);
}
static void __init imx51_dt_init(void)
{
struct platform_device_info devinfo = { .name = "cpufreq-dt", };
mxc_arch_reset_init_dt();
imx51_ipu_mipi_setup();
imx_src_init();
of_platform_populate(NULL, of_default_bus_match_table, NULL, NULL);
platform_device_register_full(&devinfo);
}
static void __init imx51_init_late(void)
{
mx51_neon_fixup();
imx51_pm_init();
}
