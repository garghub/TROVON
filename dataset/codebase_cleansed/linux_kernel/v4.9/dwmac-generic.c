static int dwmac_generic_probe(struct platform_device *pdev)
{
struct plat_stmmacenet_data *plat_dat;
struct stmmac_resources stmmac_res;
int ret;
ret = stmmac_get_platform_resources(pdev, &stmmac_res);
if (ret)
return ret;
if (pdev->dev.of_node) {
plat_dat = stmmac_probe_config_dt(pdev, &stmmac_res.mac);
if (IS_ERR(plat_dat)) {
dev_err(&pdev->dev, "dt configuration failed\n");
return PTR_ERR(plat_dat);
}
} else {
plat_dat = dev_get_platdata(&pdev->dev);
if (!plat_dat) {
dev_err(&pdev->dev, "no platform data provided\n");
return -EINVAL;
}
plat_dat->multicast_filter_bins = HASH_TABLE_SIZE;
plat_dat->unicast_filter_entries = 1;
}
if (plat_dat->init) {
ret = plat_dat->init(pdev, plat_dat->bsp_priv);
if (ret)
goto err_remove_config_dt;
}
ret = stmmac_dvr_probe(&pdev->dev, plat_dat, &stmmac_res);
if (ret)
goto err_exit;
return 0;
err_exit:
if (plat_dat->exit)
plat_dat->exit(pdev, plat_dat->bsp_priv);
err_remove_config_dt:
if (pdev->dev.of_node)
stmmac_remove_config_dt(pdev, plat_dat);
return ret;
}
