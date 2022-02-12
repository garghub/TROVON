static int lpc18xx_dwmac_probe(struct platform_device *pdev)
{
struct plat_stmmacenet_data *plat_dat;
struct stmmac_resources stmmac_res;
struct regmap *reg;
u8 ethmode;
int ret;
ret = stmmac_get_platform_resources(pdev, &stmmac_res);
if (ret)
return ret;
plat_dat = stmmac_probe_config_dt(pdev, &stmmac_res.mac);
if (IS_ERR(plat_dat))
return PTR_ERR(plat_dat);
plat_dat->has_gmac = true;
reg = syscon_regmap_lookup_by_compatible("nxp,lpc1850-creg");
if (IS_ERR(reg)) {
dev_err(&pdev->dev, "syscon lookup failed\n");
return PTR_ERR(reg);
}
if (plat_dat->interface == PHY_INTERFACE_MODE_MII) {
ethmode = LPC18XX_CREG_CREG6_ETHMODE_MII;
} else if (plat_dat->interface == PHY_INTERFACE_MODE_RMII) {
ethmode = LPC18XX_CREG_CREG6_ETHMODE_RMII;
} else {
dev_err(&pdev->dev, "Only MII and RMII mode supported\n");
return -EINVAL;
}
regmap_update_bits(reg, LPC18XX_CREG_CREG6,
LPC18XX_CREG_CREG6_ETHMODE_MASK, ethmode);
return stmmac_dvr_probe(&pdev->dev, plat_dat, &stmmac_res);
}
