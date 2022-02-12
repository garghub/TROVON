void __init cns3xxx_ahci_init(void)
{
u32 tmp;
tmp = __raw_readl(MISC_SATA_POWER_MODE);
tmp |= 0x1 << 16;
tmp |= 0x1 << 17;
__raw_writel(tmp, MISC_SATA_POWER_MODE);
cns3xxx_pwr_power_up(0x1 << PM_PLL_HM_PD_CTRL_REG_OFFSET_SATA_PHY0);
cns3xxx_pwr_power_up(0x1 << PM_PLL_HM_PD_CTRL_REG_OFFSET_SATA_PHY1);
cns3xxx_pwr_clk_en(0x1 << PM_CLK_GATE_REG_OFFSET_SATA);
cns3xxx_pwr_soft_rst(CNS3XXX_PWR_SOFTWARE_RST(SATA));
platform_device_register(&cns3xxx_ahci_pdev);
}
void __init cns3xxx_sdhci_init(void)
{
u32 __iomem *gpioa = IOMEM(CNS3XXX_MISC_BASE_VIRT + 0x0014);
u32 gpioa_pins = __raw_readl(gpioa);
gpioa_pins |= 0x1fff0004;
__raw_writel(gpioa_pins, gpioa);
cns3xxx_pwr_clk_en(CNS3XXX_PWR_CLK_EN(SDIO));
cns3xxx_pwr_soft_rst(CNS3XXX_PWR_SOFTWARE_RST(SDIO));
platform_device_register(&cns3xxx_sdhci_pdev);
}
