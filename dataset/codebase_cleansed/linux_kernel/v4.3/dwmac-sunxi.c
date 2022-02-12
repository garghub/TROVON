static int sun7i_gmac_init(struct platform_device *pdev, void *priv)
{
struct sunxi_priv_data *gmac = priv;
int ret;
if (gmac->regulator) {
ret = regulator_enable(gmac->regulator);
if (ret)
return ret;
}
if (gmac->interface == PHY_INTERFACE_MODE_RGMII) {
clk_set_rate(gmac->tx_clk, SUN7I_GMAC_GMII_RGMII_RATE);
clk_prepare_enable(gmac->tx_clk);
gmac->clk_enabled = 1;
} else {
clk_set_rate(gmac->tx_clk, SUN7I_GMAC_MII_RATE);
clk_prepare(gmac->tx_clk);
}
return 0;
}
static void sun7i_gmac_exit(struct platform_device *pdev, void *priv)
{
struct sunxi_priv_data *gmac = priv;
if (gmac->clk_enabled) {
clk_disable(gmac->tx_clk);
gmac->clk_enabled = 0;
}
clk_unprepare(gmac->tx_clk);
if (gmac->regulator)
regulator_disable(gmac->regulator);
}
static void sun7i_fix_speed(void *priv, unsigned int speed)
{
struct sunxi_priv_data *gmac = priv;
if (gmac->interface != PHY_INTERFACE_MODE_GMII)
return;
if (gmac->clk_enabled) {
clk_disable(gmac->tx_clk);
gmac->clk_enabled = 0;
}
clk_unprepare(gmac->tx_clk);
if (speed == 1000) {
clk_set_rate(gmac->tx_clk, SUN7I_GMAC_GMII_RGMII_RATE);
clk_prepare_enable(gmac->tx_clk);
gmac->clk_enabled = 1;
} else {
clk_set_rate(gmac->tx_clk, SUN7I_GMAC_MII_RATE);
clk_prepare(gmac->tx_clk);
}
}
static int sun7i_gmac_probe(struct platform_device *pdev)
{
struct plat_stmmacenet_data *plat_dat;
struct stmmac_resources stmmac_res;
struct sunxi_priv_data *gmac;
struct device *dev = &pdev->dev;
int ret;
ret = stmmac_get_platform_resources(pdev, &stmmac_res);
if (ret)
return ret;
plat_dat = stmmac_probe_config_dt(pdev, &stmmac_res.mac);
if (IS_ERR(plat_dat))
return PTR_ERR(plat_dat);
gmac = devm_kzalloc(dev, sizeof(*gmac), GFP_KERNEL);
if (!gmac)
return -ENOMEM;
gmac->interface = of_get_phy_mode(dev->of_node);
gmac->tx_clk = devm_clk_get(dev, "allwinner_gmac_tx");
if (IS_ERR(gmac->tx_clk)) {
dev_err(dev, "could not get tx clock\n");
return PTR_ERR(gmac->tx_clk);
}
gmac->regulator = devm_regulator_get_optional(dev, "phy");
if (IS_ERR(gmac->regulator)) {
if (PTR_ERR(gmac->regulator) == -EPROBE_DEFER)
return -EPROBE_DEFER;
dev_info(dev, "no regulator found\n");
gmac->regulator = NULL;
}
plat_dat->tx_coe = 1;
plat_dat->has_gmac = true;
plat_dat->bsp_priv = gmac;
plat_dat->init = sun7i_gmac_init;
plat_dat->exit = sun7i_gmac_exit;
plat_dat->fix_mac_speed = sun7i_fix_speed;
ret = sun7i_gmac_init(pdev, plat_dat->bsp_priv);
if (ret)
return ret;
return stmmac_dvr_probe(&pdev->dev, plat_dat, &stmmac_res);
}
