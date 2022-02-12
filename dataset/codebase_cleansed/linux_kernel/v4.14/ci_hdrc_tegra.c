static int tegra_udc_probe(struct platform_device *pdev)
{
const struct tegra_udc_soc_info *soc;
struct tegra_udc *udc;
int err;
udc = devm_kzalloc(&pdev->dev, sizeof(*udc), GFP_KERNEL);
if (!udc)
return -ENOMEM;
soc = of_device_get_match_data(&pdev->dev);
if (!soc) {
dev_err(&pdev->dev, "failed to match OF data\n");
return -EINVAL;
}
udc->phy = devm_usb_get_phy_by_phandle(&pdev->dev, "nvidia,phy", 0);
if (IS_ERR(udc->phy)) {
err = PTR_ERR(udc->phy);
dev_err(&pdev->dev, "failed to get PHY: %d\n", err);
return err;
}
udc->clk = devm_clk_get(&pdev->dev, NULL);
if (IS_ERR(udc->clk)) {
err = PTR_ERR(udc->clk);
dev_err(&pdev->dev, "failed to get clock: %d\n", err);
return err;
}
err = clk_prepare_enable(udc->clk);
if (err < 0) {
dev_err(&pdev->dev, "failed to enable clock: %d\n", err);
return err;
}
usb_phy_set_suspend(udc->phy, 0);
udc->data.name = "tegra-udc";
udc->data.flags = soc->flags;
udc->data.usb_phy = udc->phy;
udc->data.capoffset = DEF_CAPOFFSET;
udc->dev = ci_hdrc_add_device(&pdev->dev, pdev->resource,
pdev->num_resources, &udc->data);
if (IS_ERR(udc->dev)) {
err = PTR_ERR(udc->dev);
dev_err(&pdev->dev, "failed to add HDRC device: %d\n", err);
goto fail_power_off;
}
platform_set_drvdata(pdev, udc);
return 0;
fail_power_off:
usb_phy_set_suspend(udc->phy, 1);
clk_disable_unprepare(udc->clk);
return err;
}
static int tegra_udc_remove(struct platform_device *pdev)
{
struct tegra_udc *udc = platform_get_drvdata(pdev);
usb_phy_set_suspend(udc->phy, 1);
clk_disable_unprepare(udc->clk);
return 0;
}
