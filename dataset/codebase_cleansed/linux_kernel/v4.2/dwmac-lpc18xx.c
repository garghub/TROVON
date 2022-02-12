static void *lpc18xx_dwmac_setup(struct platform_device *pdev)
{
struct lpc18xx_dwmac_priv_data *dwmac;
dwmac = devm_kzalloc(&pdev->dev, sizeof(*dwmac), GFP_KERNEL);
if (!dwmac)
return ERR_PTR(-ENOMEM);
dwmac->interface = of_get_phy_mode(pdev->dev.of_node);
if (dwmac->interface < 0)
return ERR_PTR(dwmac->interface);
dwmac->reg = syscon_regmap_lookup_by_compatible("nxp,lpc1850-creg");
if (IS_ERR(dwmac->reg)) {
dev_err(&pdev->dev, "Syscon lookup failed\n");
return dwmac->reg;
}
return dwmac;
}
static int lpc18xx_dwmac_init(struct platform_device *pdev, void *priv)
{
struct lpc18xx_dwmac_priv_data *dwmac = priv;
u8 ethmode;
if (dwmac->interface == PHY_INTERFACE_MODE_MII) {
ethmode = LPC18XX_CREG_CREG6_ETHMODE_MII;
} else if (dwmac->interface == PHY_INTERFACE_MODE_RMII) {
ethmode = LPC18XX_CREG_CREG6_ETHMODE_RMII;
} else {
dev_err(&pdev->dev, "Only MII and RMII mode supported\n");
return -EINVAL;
}
regmap_update_bits(dwmac->reg, LPC18XX_CREG_CREG6,
LPC18XX_CREG_CREG6_ETHMODE_MASK, ethmode);
return 0;
}
