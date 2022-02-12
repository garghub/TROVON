static void am35xx_enable_emac_int(void)
{
u32 regval;
regval = omap_ctrl_readl(AM35XX_CONTROL_LVL_INTR_CLEAR);
regval = (regval | AM35XX_CPGMAC_C0_RX_PULSE_CLR |
AM35XX_CPGMAC_C0_TX_PULSE_CLR |
AM35XX_CPGMAC_C0_MISC_PULSE_CLR |
AM35XX_CPGMAC_C0_RX_THRESH_CLR);
omap_ctrl_writel(regval, AM35XX_CONTROL_LVL_INTR_CLEAR);
regval = omap_ctrl_readl(AM35XX_CONTROL_LVL_INTR_CLEAR);
}
static void am35xx_disable_emac_int(void)
{
u32 regval;
regval = omap_ctrl_readl(AM35XX_CONTROL_LVL_INTR_CLEAR);
regval = (regval | AM35XX_CPGMAC_C0_RX_PULSE_CLR |
AM35XX_CPGMAC_C0_TX_PULSE_CLR);
omap_ctrl_writel(regval, AM35XX_CONTROL_LVL_INTR_CLEAR);
regval = omap_ctrl_readl(AM35XX_CONTROL_LVL_INTR_CLEAR);
}
void __init am35xx_emac_init(unsigned long mdio_bus_freq, u8 rmii_en)
{
unsigned int regval;
int err;
am35xx_emac_pdata.rmii_en = rmii_en;
am35xx_emac_mdio_pdata.bus_freq = mdio_bus_freq;
err = platform_device_register(&am35xx_emac_device);
if (err) {
pr_err("AM35x: failed registering EMAC device: %d\n", err);
return;
}
err = platform_device_register(&am35xx_emac_mdio_device);
if (err) {
pr_err("AM35x: failed registering EMAC MDIO device: %d\n", err);
platform_device_unregister(&am35xx_emac_device);
return;
}
regval = omap_ctrl_readl(AM35XX_CONTROL_IP_SW_RESET);
regval = regval & (~(AM35XX_CPGMACSS_SW_RST));
omap_ctrl_writel(regval, AM35XX_CONTROL_IP_SW_RESET);
regval = omap_ctrl_readl(AM35XX_CONTROL_IP_SW_RESET);
}
