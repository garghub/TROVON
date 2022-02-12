static int oxnas_dwmac_init(struct platform_device *pdev, void *priv)
{
struct oxnas_dwmac *dwmac = priv;
unsigned int value;
int ret;
ret = device_reset(dwmac->dev);
if (ret)
return ret;
ret = clk_prepare_enable(dwmac->clk);
if (ret)
return ret;
ret = regmap_read(dwmac->regmap, OXNAS_DWMAC_CTRL_REGOFFSET, &value);
if (ret < 0) {
clk_disable_unprepare(dwmac->clk);
return ret;
}
value |= BIT(DWMAC_CKEN_GTX) |
BIT(DWMAC_SIMPLE_MUX) |
BIT(DWMAC_AUTO_TX_SOURCE) |
BIT(DWMAC_CKEN_TX_OUT) |
BIT(DWMAC_CKEN_TXN_OUT) |
BIT(DWMAC_CKEN_TX_IN) |
BIT(DWMAC_CKEN_RX_OUT) |
BIT(DWMAC_CKEN_RXN_OUT) |
BIT(DWMAC_CKEN_RX_IN);
regmap_write(dwmac->regmap, OXNAS_DWMAC_CTRL_REGOFFSET, value);
value = DWMAC_TX_VARDELAY(4) |
DWMAC_TXN_VARDELAY(2) |
DWMAC_RX_VARDELAY(10) |
DWMAC_RXN_VARDELAY(8);
regmap_write(dwmac->regmap, OXNAS_DWMAC_DELAY_REGOFFSET, value);
return 0;
}
static void oxnas_dwmac_exit(struct platform_device *pdev, void *priv)
{
struct oxnas_dwmac *dwmac = priv;
clk_disable_unprepare(dwmac->clk);
}
static int oxnas_dwmac_probe(struct platform_device *pdev)
{
struct plat_stmmacenet_data *plat_dat;
struct stmmac_resources stmmac_res;
struct oxnas_dwmac *dwmac;
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
dwmac->dev = &pdev->dev;
plat_dat->bsp_priv = dwmac;
plat_dat->init = oxnas_dwmac_init;
plat_dat->exit = oxnas_dwmac_exit;
dwmac->regmap = syscon_regmap_lookup_by_phandle(pdev->dev.of_node,
"oxsemi,sys-ctrl");
if (IS_ERR(dwmac->regmap)) {
dev_err(&pdev->dev, "failed to have sysctrl regmap\n");
ret = PTR_ERR(dwmac->regmap);
goto err_remove_config_dt;
}
dwmac->clk = devm_clk_get(&pdev->dev, "gmac");
if (IS_ERR(dwmac->clk)) {
ret = PTR_ERR(dwmac->clk);
goto err_remove_config_dt;
}
ret = oxnas_dwmac_init(pdev, plat_dat->bsp_priv);
if (ret)
goto err_remove_config_dt;
ret = stmmac_dvr_probe(&pdev->dev, plat_dat, &stmmac_res);
if (ret)
goto err_dwmac_exit;
return 0;
err_dwmac_exit:
oxnas_dwmac_exit(pdev, plat_dat->bsp_priv);
err_remove_config_dt:
stmmac_remove_config_dt(pdev, plat_dat);
return ret;
}
