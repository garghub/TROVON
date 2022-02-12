static int __devinit dwc3_exynos_probe(struct platform_device *pdev)
{
struct dwc3_exynos_data *pdata = pdev->dev.platform_data;
struct platform_device *dwc3;
struct dwc3_exynos *exynos;
struct clk *clk;
int devid;
int ret = -ENOMEM;
exynos = kzalloc(sizeof(*exynos), GFP_KERNEL);
if (!exynos) {
dev_err(&pdev->dev, "not enough memory\n");
goto err0;
}
platform_set_drvdata(pdev, exynos);
devid = dwc3_get_device_id();
if (devid < 0)
goto err1;
dwc3 = platform_device_alloc("dwc3", devid);
if (!dwc3) {
dev_err(&pdev->dev, "couldn't allocate dwc3 device\n");
goto err2;
}
clk = clk_get(&pdev->dev, "usbdrd30");
if (IS_ERR(clk)) {
dev_err(&pdev->dev, "couldn't get clock\n");
ret = -EINVAL;
goto err3;
}
dma_set_coherent_mask(&dwc3->dev, pdev->dev.coherent_dma_mask);
dwc3->dev.parent = &pdev->dev;
dwc3->dev.dma_mask = pdev->dev.dma_mask;
dwc3->dev.dma_parms = pdev->dev.dma_parms;
exynos->dwc3 = dwc3;
exynos->dev = &pdev->dev;
exynos->clk = clk;
clk_enable(exynos->clk);
if (!pdata) {
dev_dbg(&pdev->dev, "missing platform data\n");
} else {
if (pdata->phy_init)
pdata->phy_init(pdev, pdata->phy_type);
}
ret = platform_device_add_resources(dwc3, pdev->resource,
pdev->num_resources);
if (ret) {
dev_err(&pdev->dev, "couldn't add resources to dwc3 device\n");
goto err4;
}
ret = platform_device_add(dwc3);
if (ret) {
dev_err(&pdev->dev, "failed to register dwc3 device\n");
goto err4;
}
return 0;
err4:
if (pdata && pdata->phy_exit)
pdata->phy_exit(pdev, pdata->phy_type);
clk_disable(clk);
clk_put(clk);
err3:
platform_device_put(dwc3);
err2:
dwc3_put_device_id(devid);
err1:
kfree(exynos);
err0:
return ret;
}
static int __devexit dwc3_exynos_remove(struct platform_device *pdev)
{
struct dwc3_exynos *exynos = platform_get_drvdata(pdev);
struct dwc3_exynos_data *pdata = pdev->dev.platform_data;
platform_device_unregister(exynos->dwc3);
dwc3_put_device_id(exynos->dwc3->id);
if (pdata && pdata->phy_exit)
pdata->phy_exit(pdev, pdata->phy_type);
clk_disable(exynos->clk);
clk_put(exynos->clk);
kfree(exynos);
return 0;
}
