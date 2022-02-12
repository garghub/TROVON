int __init harmony_regulator_init(void)
{
void __iomem *pmc = IO_ADDRESS(TEGRA_PMC_BASE);
u32 pmc_ctrl;
pmc_ctrl = readl(pmc + PMC_CTRL);
writel(pmc_ctrl | PMC_CTRL_INTR_LOW, pmc + PMC_CTRL);
i2c_register_board_info(3, harmony_regulators, 1);
return 0;
}
