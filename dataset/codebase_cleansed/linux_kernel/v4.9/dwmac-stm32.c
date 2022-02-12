static int stm32_dwmac_init(struct plat_stmmacenet_data *plat_dat)
{
struct stm32_dwmac *dwmac = plat_dat->bsp_priv;
u32 reg = dwmac->mode_reg;
u32 val;
int ret;
val = (plat_dat->interface == PHY_INTERFACE_MODE_MII) ? 0 : 1;
ret = regmap_update_bits(dwmac->regmap, reg, MII_PHY_SEL_MASK, val);
if (ret)
return ret;
ret = clk_prepare_enable(dwmac->clk_tx);
if (ret)
return ret;
ret = clk_prepare_enable(dwmac->clk_rx);
if (ret)
clk_disable_unprepare(dwmac->clk_tx);
return ret;
}
static void stm32_dwmac_clk_disable(struct stm32_dwmac *dwmac)
{
clk_disable_unprepare(dwmac->clk_tx);
clk_disable_unprepare(dwmac->clk_rx);
}
static int stm32_dwmac_parse_data(struct stm32_dwmac *dwmac,
struct device *dev)
{
struct device_node *np = dev->of_node;
int err;
dwmac->clk_tx = devm_clk_get(dev, "mac-clk-tx");
if (IS_ERR(dwmac->clk_tx)) {
dev_err(dev, "No tx clock provided...\n");
return PTR_ERR(dwmac->clk_tx);
}
dwmac->clk_rx = devm_clk_get(dev, "mac-clk-rx");
if (IS_ERR(dwmac->clk_rx)) {
dev_err(dev, "No rx clock provided...\n");
return PTR_ERR(dwmac->clk_rx);
}
dwmac->regmap = syscon_regmap_lookup_by_phandle(np, "st,syscon");
if (IS_ERR(dwmac->regmap))
return PTR_ERR(dwmac->regmap);
err = of_property_read_u32_index(np, "st,syscon", 1, &dwmac->mode_reg);
if (err)
dev_err(dev, "Can't get sysconfig mode offset (%d)\n", err);
return err;
}
static int stm32_dwmac_probe(struct platform_device *pdev)
{
struct plat_stmmacenet_data *plat_dat;
struct stmmac_resources stmmac_res;
struct stm32_dwmac *dwmac;
int ret;
ret = stmmac_get_platform_resources(pdev, &stmmac_res);
if (ret)
return ret;
plat_dat = stmmac_probe_config_dt(pdev, &stmmac_res.mac);
if (IS_ERR(plat_dat))
return PTR_ERR(plat_dat);
dwmac = devm_kzalloc(&pdev->dev, sizeof(*dwmac), GFP_KERNEL);
if (!dwmac) {
ret = -ENOMEM;
goto err_remove_config_dt;
}
ret = stm32_dwmac_parse_data(dwmac, &pdev->dev);
if (ret) {
dev_err(&pdev->dev, "Unable to parse OF data\n");
goto err_remove_config_dt;
}
plat_dat->bsp_priv = dwmac;
ret = stm32_dwmac_init(plat_dat);
if (ret)
goto err_remove_config_dt;
ret = stmmac_dvr_probe(&pdev->dev, plat_dat, &stmmac_res);
if (ret)
goto err_clk_disable;
return 0;
err_clk_disable:
stm32_dwmac_clk_disable(dwmac);
err_remove_config_dt:
stmmac_remove_config_dt(pdev, plat_dat);
return ret;
}
static int stm32_dwmac_remove(struct platform_device *pdev)
{
struct net_device *ndev = platform_get_drvdata(pdev);
struct stmmac_priv *priv = netdev_priv(ndev);
int ret = stmmac_dvr_remove(&pdev->dev);
stm32_dwmac_clk_disable(priv->plat->bsp_priv);
return ret;
}
static int stm32_dwmac_suspend(struct device *dev)
{
struct net_device *ndev = dev_get_drvdata(dev);
struct stmmac_priv *priv = netdev_priv(ndev);
int ret;
ret = stmmac_suspend(dev);
stm32_dwmac_clk_disable(priv->plat->bsp_priv);
return ret;
}
static int stm32_dwmac_resume(struct device *dev)
{
struct net_device *ndev = dev_get_drvdata(dev);
struct stmmac_priv *priv = netdev_priv(ndev);
int ret;
ret = stm32_dwmac_init(priv->plat);
if (ret)
return ret;
ret = stmmac_resume(dev);
return ret;
}
