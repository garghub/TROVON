static int st_ohci_platform_power_on(struct platform_device *dev)
{
struct usb_hcd *hcd = platform_get_drvdata(dev);
struct st_ohci_platform_priv *priv = hcd_to_ohci_priv(hcd);
int clk, ret;
ret = reset_control_deassert(priv->pwr);
if (ret)
return ret;
ret = reset_control_deassert(priv->rst);
if (ret)
goto err_assert_power;
if (priv->clk48) {
ret = clk_set_rate(priv->clk48, 48000000);
if (ret)
goto err_assert_reset;
}
for (clk = 0; clk < USB_MAX_CLKS && priv->clks[clk]; clk++) {
ret = clk_prepare_enable(priv->clks[clk]);
if (ret)
goto err_disable_clks;
}
ret = phy_init(priv->phy);
if (ret)
goto err_disable_clks;
ret = phy_power_on(priv->phy);
if (ret)
goto err_exit_phy;
return 0;
err_exit_phy:
phy_exit(priv->phy);
err_disable_clks:
while (--clk >= 0)
clk_disable_unprepare(priv->clks[clk]);
err_assert_reset:
reset_control_assert(priv->rst);
err_assert_power:
reset_control_assert(priv->pwr);
return ret;
}
static void st_ohci_platform_power_off(struct platform_device *dev)
{
struct usb_hcd *hcd = platform_get_drvdata(dev);
struct st_ohci_platform_priv *priv = hcd_to_ohci_priv(hcd);
int clk;
reset_control_assert(priv->pwr);
reset_control_assert(priv->rst);
phy_power_off(priv->phy);
phy_exit(priv->phy);
for (clk = USB_MAX_CLKS - 1; clk >= 0; clk--)
if (priv->clks[clk])
clk_disable_unprepare(priv->clks[clk]);
}
static int st_ohci_platform_probe(struct platform_device *dev)
{
struct usb_hcd *hcd;
struct resource *res_mem;
struct usb_ohci_pdata *pdata = &ohci_platform_defaults;
struct st_ohci_platform_priv *priv;
struct ohci_hcd *ohci;
int err, irq, clk = 0;
if (usb_disabled())
return -ENODEV;
irq = platform_get_irq(dev, 0);
if (irq < 0) {
dev_err(&dev->dev, "no irq provided");
return irq;
}
res_mem = platform_get_resource(dev, IORESOURCE_MEM, 0);
if (!res_mem) {
dev_err(&dev->dev, "no memory resource provided");
return -ENXIO;
}
hcd = usb_create_hcd(&ohci_platform_hc_driver, &dev->dev,
dev_name(&dev->dev));
if (!hcd)
return -ENOMEM;
platform_set_drvdata(dev, hcd);
dev->dev.platform_data = pdata;
priv = hcd_to_ohci_priv(hcd);
ohci = hcd_to_ohci(hcd);
priv->phy = devm_phy_get(&dev->dev, "usb");
if (IS_ERR(priv->phy)) {
err = PTR_ERR(priv->phy);
goto err_put_hcd;
}
for (clk = 0; clk < USB_MAX_CLKS; clk++) {
priv->clks[clk] = of_clk_get(dev->dev.of_node, clk);
if (IS_ERR(priv->clks[clk])) {
err = PTR_ERR(priv->clks[clk]);
if (err == -EPROBE_DEFER)
goto err_put_clks;
priv->clks[clk] = NULL;
break;
}
}
priv->clk48 = devm_clk_get(&dev->dev, "clk48");
if (IS_ERR(priv->clk48)) {
dev_info(&dev->dev, "48MHz clk not found\n");
priv->clk48 = NULL;
}
priv->pwr = devm_reset_control_get_optional(&dev->dev, "power");
if (IS_ERR(priv->pwr)) {
err = PTR_ERR(priv->pwr);
goto err_put_clks;
}
priv->rst = devm_reset_control_get_optional(&dev->dev, "softreset");
if (IS_ERR(priv->rst)) {
err = PTR_ERR(priv->rst);
goto err_put_clks;
}
if (pdata->power_on) {
err = pdata->power_on(dev);
if (err < 0)
goto err_power;
}
hcd->rsrc_start = res_mem->start;
hcd->rsrc_len = resource_size(res_mem);
hcd->regs = devm_ioremap_resource(&dev->dev, res_mem);
if (IS_ERR(hcd->regs)) {
err = PTR_ERR(hcd->regs);
goto err_power;
}
err = usb_add_hcd(hcd, irq, IRQF_SHARED);
if (err)
goto err_power;
device_wakeup_enable(hcd->self.controller);
platform_set_drvdata(dev, hcd);
return err;
err_power:
if (pdata->power_off)
pdata->power_off(dev);
err_put_clks:
while (--clk >= 0)
clk_put(priv->clks[clk]);
err_put_hcd:
if (pdata == &ohci_platform_defaults)
dev->dev.platform_data = NULL;
usb_put_hcd(hcd);
return err;
}
static int st_ohci_platform_remove(struct platform_device *dev)
{
struct usb_hcd *hcd = platform_get_drvdata(dev);
struct usb_ohci_pdata *pdata = dev_get_platdata(&dev->dev);
struct st_ohci_platform_priv *priv = hcd_to_ohci_priv(hcd);
int clk;
usb_remove_hcd(hcd);
if (pdata->power_off)
pdata->power_off(dev);
for (clk = 0; clk < USB_MAX_CLKS && priv->clks[clk]; clk++)
clk_put(priv->clks[clk]);
usb_put_hcd(hcd);
if (pdata == &ohci_platform_defaults)
dev->dev.platform_data = NULL;
return 0;
}
static int st_ohci_suspend(struct device *dev)
{
struct usb_hcd *hcd = dev_get_drvdata(dev);
struct usb_ohci_pdata *pdata = dev->platform_data;
struct platform_device *pdev = to_platform_device(dev);
bool do_wakeup = device_may_wakeup(dev);
int ret;
ret = ohci_suspend(hcd, do_wakeup);
if (ret)
return ret;
if (pdata->power_suspend)
pdata->power_suspend(pdev);
return ret;
}
static int st_ohci_resume(struct device *dev)
{
struct usb_hcd *hcd = dev_get_drvdata(dev);
struct usb_ohci_pdata *pdata = dev_get_platdata(dev);
struct platform_device *pdev = to_platform_device(dev);
int err;
if (pdata->power_on) {
err = pdata->power_on(pdev);
if (err < 0)
return err;
}
ohci_resume(hcd, false);
return 0;
}
static int __init ohci_platform_init(void)
{
if (usb_disabled())
return -ENODEV;
pr_info("%s: " DRIVER_DESC "\n", hcd_name);
ohci_init_driver(&ohci_platform_hc_driver, &platform_overrides);
return platform_driver_register(&ohci_platform_driver);
}
static void __exit ohci_platform_cleanup(void)
{
platform_driver_unregister(&ohci_platform_driver);
}
