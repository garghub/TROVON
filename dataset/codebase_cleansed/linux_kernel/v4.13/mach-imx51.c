static void __init imx51_init_early(void)
{
mxc_set_cpu_type(MXC_CPU_MX51);
}
static void __init imx51_ipu_mipi_setup(void)
{
void __iomem *hsc_addr;
hsc_addr = ioremap(MX51_MIPI_HSC_BASE, SZ_16K);
WARN_ON(!hsc_addr);
imx_writel(0xf00, hsc_addr);
imx_writel(imx_readl(hsc_addr + 0x800) | 0x30ff, hsc_addr + 0x800);
iounmap(hsc_addr);
}
static void __init imx51_dt_init(void)
{
imx51_ipu_mipi_setup();
imx_src_init();
imx_aips_allow_unprivileged_access("fsl,imx51-aipstz");
}
static void __init imx51_init_late(void)
{
mx51_neon_fixup();
imx51_pm_init();
}
