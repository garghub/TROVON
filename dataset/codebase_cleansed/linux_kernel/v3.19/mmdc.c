static int imx_mmdc_probe(struct platform_device *pdev)
{
struct device_node *np = pdev->dev.of_node;
void __iomem *mmdc_base, *reg;
u32 val;
int timeout = 0x400;
mmdc_base = of_iomap(np, 0);
WARN_ON(!mmdc_base);
reg = mmdc_base + MMDC_MDMISC;
val = readl_relaxed(reg);
ddr_type = (val & BM_MMDC_MDMISC_DDR_TYPE) >>
BP_MMDC_MDMISC_DDR_TYPE;
reg = mmdc_base + MMDC_MAPSR;
val = readl_relaxed(reg);
val &= ~(1 << BP_MMDC_MAPSR_PSD);
writel_relaxed(val, reg);
while (!(readl_relaxed(reg) & 1 << BP_MMDC_MAPSR_PSS) && --timeout)
cpu_relax();
if (unlikely(!timeout)) {
pr_warn("%s: failed to enable automatic power saving\n",
__func__);
return -EBUSY;
}
return 0;
}
int imx_mmdc_get_ddr_type(void)
{
return ddr_type;
}
static int __init imx_mmdc_init(void)
{
return platform_driver_register(&imx_mmdc_driver);
}
