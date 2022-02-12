static int dwc3_exynos_register_phys(struct dwc3_exynos *exynos)
{
struct nop_usb_xceiv_platform_data pdata;
struct platform_device *pdev;
int ret;
memset(&pdata, 0x00, sizeof(pdata));
pdev = platform_device_alloc("nop_usb_xceiv", PLATFORM_DEVID_AUTO);
if (!pdev)
return -ENOMEM;
exynos->usb2_phy = pdev;
pdata.type = USB_PHY_TYPE_USB2;
ret = platform_device_add_data(exynos->usb2_phy, &pdata, sizeof(pdata));
if (ret)
goto err1;
pdev = platform_device_alloc("nop_usb_xceiv", PLATFORM_DEVID_AUTO);
if (!pdev) {
ret = -ENOMEM;
goto err1;
}
exynos->usb3_phy = pdev;
pdata.type = USB_PHY_TYPE_USB3;
ret = platform_device_add_data(exynos->usb3_phy, &pdata, sizeof(pdata));
if (ret)
goto err2;
ret = platform_device_add(exynos->usb2_phy);
if (ret)
goto err2;
ret = platform_device_add(exynos->usb3_phy);
if (ret)
goto err3;
return 0;
err3:
platform_device_del(exynos->usb2_phy);
err2:
platform_device_put(exynos->usb3_phy);
err1:
platform_device_put(exynos->usb2_phy);
return ret;
}
static int dwc3_exynos_probe(struct platform_device *pdev)
{
struct platform_device *dwc3;
struct dwc3_exynos *exynos;
struct clk *clk;
struct device *dev = &pdev->dev;
int ret = -ENOMEM;
exynos = devm_kzalloc(dev, sizeof(*exynos), GFP_KERNEL);
if (!exynos) {
dev_err(dev, "not enough memory\n");
return -ENOMEM;
}
if (!pdev->dev.dma_mask)
pdev->dev.dma_mask = &dwc3_exynos_dma_mask;
platform_set_drvdata(pdev, exynos);
ret = dwc3_exynos_register_phys(exynos);
if (ret) {
dev_err(dev, "couldn't register PHYs\n");
return ret;
}
dwc3 = platform_device_alloc("dwc3", PLATFORM_DEVID_AUTO);
if (!dwc3) {
dev_err(dev, "couldn't allocate dwc3 device\n");
return -ENOMEM;
}
clk = devm_clk_get(dev, "usbdrd30");
if (IS_ERR(clk)) {
dev_err(dev, "couldn't get clock\n");
ret = -EINVAL;
goto err1;
}
dma_set_coherent_mask(&dwc3->dev, dev->coherent_dma_mask);
dwc3->dev.parent = dev;
dwc3->dev.dma_mask = dev->dma_mask;
dwc3->dev.dma_parms = dev->dma_parms;
exynos->dwc3 = dwc3;
exynos->dev = dev;
exynos->clk = clk;
clk_enable(exynos->clk);
ret = platform_device_add_resources(dwc3, pdev->resource,
pdev->num_resources);
if (ret) {
dev_err(dev, "couldn't add resources to dwc3 device\n");
goto err2;
}
ret = platform_device_add(dwc3);
if (ret) {
dev_err(dev, "failed to register dwc3 device\n");
goto err2;
}
return 0;
err2:
clk_disable(clk);
err1:
platform_device_put(dwc3);
return ret;
}
static int dwc3_exynos_remove(struct platform_device *pdev)
{
struct dwc3_exynos *exynos = platform_get_drvdata(pdev);
platform_device_unregister(exynos->dwc3);
platform_device_unregister(exynos->usb2_phy);
platform_device_unregister(exynos->usb3_phy);
clk_disable(exynos->clk);
return 0;
}
