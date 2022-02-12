static int dwc2_get_dr_mode(struct dwc2_hsotg *hsotg)
{
enum usb_dr_mode mode;
hsotg->dr_mode = usb_get_dr_mode(hsotg->dev);
if (hsotg->dr_mode == USB_DR_MODE_UNKNOWN)
hsotg->dr_mode = USB_DR_MODE_OTG;
mode = hsotg->dr_mode;
if (dwc2_hw_is_device(hsotg)) {
if (IS_ENABLED(CONFIG_USB_DWC2_HOST)) {
dev_err(hsotg->dev,
"Controller does not support host mode.\n");
return -EINVAL;
}
mode = USB_DR_MODE_PERIPHERAL;
} else if (dwc2_hw_is_host(hsotg)) {
if (IS_ENABLED(CONFIG_USB_DWC2_PERIPHERAL)) {
dev_err(hsotg->dev,
"Controller does not support device mode.\n");
return -EINVAL;
}
mode = USB_DR_MODE_HOST;
} else {
if (IS_ENABLED(CONFIG_USB_DWC2_HOST))
mode = USB_DR_MODE_HOST;
else if (IS_ENABLED(CONFIG_USB_DWC2_PERIPHERAL))
mode = USB_DR_MODE_PERIPHERAL;
}
if (mode != hsotg->dr_mode) {
dev_warn(hsotg->dev,
"Configuration mismatch. dr_mode forced to %s\n",
mode == USB_DR_MODE_HOST ? "host" : "device");
hsotg->dr_mode = mode;
}
return 0;
}
static int __dwc2_lowlevel_hw_enable(struct dwc2_hsotg *hsotg)
{
struct platform_device *pdev = to_platform_device(hsotg->dev);
int ret;
ret = regulator_bulk_enable(ARRAY_SIZE(hsotg->supplies),
hsotg->supplies);
if (ret)
return ret;
if (hsotg->clk) {
ret = clk_prepare_enable(hsotg->clk);
if (ret)
return ret;
}
if (hsotg->uphy)
ret = usb_phy_init(hsotg->uphy);
else if (hsotg->plat && hsotg->plat->phy_init)
ret = hsotg->plat->phy_init(pdev, hsotg->plat->phy_type);
else {
ret = phy_power_on(hsotg->phy);
if (ret == 0)
ret = phy_init(hsotg->phy);
}
return ret;
}
int dwc2_lowlevel_hw_enable(struct dwc2_hsotg *hsotg)
{
int ret = __dwc2_lowlevel_hw_enable(hsotg);
if (ret == 0)
hsotg->ll_hw_enabled = true;
return ret;
}
static int __dwc2_lowlevel_hw_disable(struct dwc2_hsotg *hsotg)
{
struct platform_device *pdev = to_platform_device(hsotg->dev);
int ret = 0;
if (hsotg->uphy)
usb_phy_shutdown(hsotg->uphy);
else if (hsotg->plat && hsotg->plat->phy_exit)
ret = hsotg->plat->phy_exit(pdev, hsotg->plat->phy_type);
else {
ret = phy_exit(hsotg->phy);
if (ret == 0)
ret = phy_power_off(hsotg->phy);
}
if (ret)
return ret;
if (hsotg->clk)
clk_disable_unprepare(hsotg->clk);
ret = regulator_bulk_disable(ARRAY_SIZE(hsotg->supplies),
hsotg->supplies);
return ret;
}
int dwc2_lowlevel_hw_disable(struct dwc2_hsotg *hsotg)
{
int ret = __dwc2_lowlevel_hw_disable(hsotg);
if (ret == 0)
hsotg->ll_hw_enabled = false;
return ret;
}
static int dwc2_lowlevel_hw_init(struct dwc2_hsotg *hsotg)
{
int i, ret;
hsotg->phyif = GUSBCFG_PHYIF16;
hsotg->phy = devm_phy_get(hsotg->dev, "usb2-phy");
if (IS_ERR(hsotg->phy)) {
ret = PTR_ERR(hsotg->phy);
switch (ret) {
case -ENODEV:
case -ENOSYS:
hsotg->phy = NULL;
break;
case -EPROBE_DEFER:
return ret;
default:
dev_err(hsotg->dev, "error getting phy %d\n", ret);
return ret;
}
}
if (!hsotg->phy) {
hsotg->uphy = devm_usb_get_phy(hsotg->dev, USB_PHY_TYPE_USB2);
if (IS_ERR(hsotg->uphy)) {
ret = PTR_ERR(hsotg->uphy);
switch (ret) {
case -ENODEV:
case -ENXIO:
hsotg->uphy = NULL;
break;
case -EPROBE_DEFER:
return ret;
default:
dev_err(hsotg->dev, "error getting usb phy %d\n",
ret);
return ret;
}
}
}
hsotg->plat = dev_get_platdata(hsotg->dev);
if (hsotg->phy) {
if (phy_get_bus_width(hsotg->phy) == 8)
hsotg->phyif = GUSBCFG_PHYIF8;
}
hsotg->clk = devm_clk_get(hsotg->dev, "otg");
if (IS_ERR(hsotg->clk)) {
hsotg->clk = NULL;
dev_dbg(hsotg->dev, "cannot get otg clock\n");
}
for (i = 0; i < ARRAY_SIZE(hsotg->supplies); i++)
hsotg->supplies[i].supply = dwc2_hsotg_supply_names[i];
ret = devm_regulator_bulk_get(hsotg->dev, ARRAY_SIZE(hsotg->supplies),
hsotg->supplies);
if (ret) {
dev_err(hsotg->dev, "failed to request supplies: %d\n", ret);
return ret;
}
return 0;
}
static int dwc2_driver_remove(struct platform_device *dev)
{
struct dwc2_hsotg *hsotg = platform_get_drvdata(dev);
dwc2_debugfs_exit(hsotg);
if (hsotg->hcd_enabled)
dwc2_hcd_remove(hsotg);
if (hsotg->gadget_enabled)
dwc2_hsotg_remove(hsotg);
if (hsotg->ll_hw_enabled)
dwc2_lowlevel_hw_disable(hsotg);
return 0;
}
static void dwc2_driver_shutdown(struct platform_device *dev)
{
struct dwc2_hsotg *hsotg = platform_get_drvdata(dev);
disable_irq(hsotg->irq);
}
static int dwc2_driver_probe(struct platform_device *dev)
{
const struct of_device_id *match;
const struct dwc2_core_params *params;
struct dwc2_core_params defparams;
struct dwc2_hsotg *hsotg;
struct resource *res;
int retval;
match = of_match_device(dwc2_of_match_table, &dev->dev);
if (match && match->data) {
params = match->data;
} else {
dwc2_set_all_params(&defparams, -1);
params = &defparams;
defparams.dma_desc_enable = 0;
defparams.dma_desc_fs_enable = 0;
}
hsotg = devm_kzalloc(&dev->dev, sizeof(*hsotg), GFP_KERNEL);
if (!hsotg)
return -ENOMEM;
hsotg->dev = &dev->dev;
if (!dev->dev.dma_mask)
dev->dev.dma_mask = &dev->dev.coherent_dma_mask;
retval = dma_set_coherent_mask(&dev->dev, DMA_BIT_MASK(32));
if (retval)
return retval;
res = platform_get_resource(dev, IORESOURCE_MEM, 0);
hsotg->regs = devm_ioremap_resource(&dev->dev, res);
if (IS_ERR(hsotg->regs))
return PTR_ERR(hsotg->regs);
dev_dbg(&dev->dev, "mapped PA %08lx to VA %p\n",
(unsigned long)res->start, hsotg->regs);
retval = dwc2_lowlevel_hw_init(hsotg);
if (retval)
return retval;
spin_lock_init(&hsotg->lock);
hsotg->core_params = devm_kzalloc(&dev->dev,
sizeof(*hsotg->core_params), GFP_KERNEL);
if (!hsotg->core_params)
return -ENOMEM;
dwc2_set_all_params(hsotg->core_params, -1);
hsotg->irq = platform_get_irq(dev, 0);
if (hsotg->irq < 0) {
dev_err(&dev->dev, "missing IRQ resource\n");
return hsotg->irq;
}
dev_dbg(hsotg->dev, "registering common handler for irq%d\n",
hsotg->irq);
retval = devm_request_irq(hsotg->dev, hsotg->irq,
dwc2_handle_common_intr, IRQF_SHARED,
dev_name(hsotg->dev), hsotg);
if (retval)
return retval;
retval = dwc2_lowlevel_hw_enable(hsotg);
if (retval)
return retval;
retval = dwc2_get_dr_mode(hsotg);
if (retval)
return retval;
dwc2_core_reset_and_force_dr_mode(hsotg);
retval = dwc2_get_hwparams(hsotg);
if (retval)
goto error;
dwc2_set_parameters(hsotg, params);
dwc2_force_dr_mode(hsotg);
if (hsotg->dr_mode != USB_DR_MODE_HOST) {
retval = dwc2_gadget_init(hsotg, hsotg->irq);
if (retval)
goto error;
hsotg->gadget_enabled = 1;
}
if (hsotg->dr_mode != USB_DR_MODE_PERIPHERAL) {
retval = dwc2_hcd_init(hsotg, hsotg->irq);
if (retval) {
if (hsotg->gadget_enabled)
dwc2_hsotg_remove(hsotg);
goto error;
}
hsotg->hcd_enabled = 1;
}
platform_set_drvdata(dev, hsotg);
dwc2_debugfs_init(hsotg);
if (hsotg->dr_mode == USB_DR_MODE_PERIPHERAL)
dwc2_lowlevel_hw_disable(hsotg);
return 0;
error:
dwc2_lowlevel_hw_disable(hsotg);
return retval;
}
static int __maybe_unused dwc2_suspend(struct device *dev)
{
struct dwc2_hsotg *dwc2 = dev_get_drvdata(dev);
int ret = 0;
if (dwc2_is_device_mode(dwc2))
dwc2_hsotg_suspend(dwc2);
if (dwc2->ll_hw_enabled)
ret = __dwc2_lowlevel_hw_disable(dwc2);
return ret;
}
static int __maybe_unused dwc2_resume(struct device *dev)
{
struct dwc2_hsotg *dwc2 = dev_get_drvdata(dev);
int ret = 0;
if (dwc2->ll_hw_enabled) {
ret = __dwc2_lowlevel_hw_enable(dwc2);
if (ret)
return ret;
}
if (dwc2_is_device_mode(dwc2))
ret = dwc2_hsotg_resume(dwc2);
return ret;
}
