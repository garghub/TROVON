static void exynos_ohci_phy_enable(struct exynos_ohci_hcd *exynos_ohci)
{
struct platform_device *pdev = to_platform_device(exynos_ohci->dev);
if (exynos_ohci->phy)
usb_phy_init(exynos_ohci->phy);
else if (exynos_ohci->pdata && exynos_ohci->pdata->phy_init)
exynos_ohci->pdata->phy_init(pdev, USB_PHY_TYPE_HOST);
}
static void exynos_ohci_phy_disable(struct exynos_ohci_hcd *exynos_ohci)
{
struct platform_device *pdev = to_platform_device(exynos_ohci->dev);
if (exynos_ohci->phy)
usb_phy_shutdown(exynos_ohci->phy);
else if (exynos_ohci->pdata && exynos_ohci->pdata->phy_exit)
exynos_ohci->pdata->phy_exit(pdev, USB_PHY_TYPE_HOST);
}
static int ohci_exynos_reset(struct usb_hcd *hcd)
{
return ohci_init(hcd_to_ohci(hcd));
}
static int ohci_exynos_start(struct usb_hcd *hcd)
{
struct ohci_hcd *ohci = hcd_to_ohci(hcd);
int ret;
ohci_dbg(ohci, "ohci_exynos_start, ohci:%p", ohci);
ret = ohci_run(ohci);
if (ret < 0) {
dev_err(hcd->self.controller, "can't start %s\n",
hcd->self.bus_name);
ohci_stop(hcd);
return ret;
}
return 0;
}
static int exynos_ohci_probe(struct platform_device *pdev)
{
struct exynos4_ohci_platdata *pdata = pdev->dev.platform_data;
struct exynos_ohci_hcd *exynos_ohci;
struct usb_hcd *hcd;
struct ohci_hcd *ohci;
struct resource *res;
struct usb_phy *phy;
int irq;
int err;
if (!pdev->dev.dma_mask)
pdev->dev.dma_mask = &pdev->dev.coherent_dma_mask;
if (!pdev->dev.coherent_dma_mask)
pdev->dev.coherent_dma_mask = DMA_BIT_MASK(32);
exynos_ohci = devm_kzalloc(&pdev->dev, sizeof(struct exynos_ohci_hcd),
GFP_KERNEL);
if (!exynos_ohci)
return -ENOMEM;
if (of_device_is_compatible(pdev->dev.of_node,
"samsung,exynos5440-ohci"))
goto skip_phy;
phy = devm_usb_get_phy(&pdev->dev, USB_PHY_TYPE_USB2);
if (IS_ERR(phy)) {
if (!pdata) {
dev_warn(&pdev->dev, "no platform data or transceiver defined\n");
return -EPROBE_DEFER;
} else {
exynos_ohci->pdata = pdata;
}
} else {
exynos_ohci->phy = phy;
exynos_ohci->otg = phy->otg;
}
skip_phy:
exynos_ohci->dev = &pdev->dev;
hcd = usb_create_hcd(&exynos_ohci_hc_driver, &pdev->dev,
dev_name(&pdev->dev));
if (!hcd) {
dev_err(&pdev->dev, "Unable to create HCD\n");
return -ENOMEM;
}
exynos_ohci->hcd = hcd;
exynos_ohci->clk = devm_clk_get(&pdev->dev, "usbhost");
if (IS_ERR(exynos_ohci->clk)) {
dev_err(&pdev->dev, "Failed to get usbhost clock\n");
err = PTR_ERR(exynos_ohci->clk);
goto fail_clk;
}
err = clk_prepare_enable(exynos_ohci->clk);
if (err)
goto fail_clk;
res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
if (!res) {
dev_err(&pdev->dev, "Failed to get I/O memory\n");
err = -ENXIO;
goto fail_io;
}
hcd->rsrc_start = res->start;
hcd->rsrc_len = resource_size(res);
hcd->regs = devm_ioremap(&pdev->dev, res->start, hcd->rsrc_len);
if (!hcd->regs) {
dev_err(&pdev->dev, "Failed to remap I/O memory\n");
err = -ENOMEM;
goto fail_io;
}
irq = platform_get_irq(pdev, 0);
if (!irq) {
dev_err(&pdev->dev, "Failed to get IRQ\n");
err = -ENODEV;
goto fail_io;
}
if (exynos_ohci->otg)
exynos_ohci->otg->set_host(exynos_ohci->otg,
&exynos_ohci->hcd->self);
exynos_ohci_phy_enable(exynos_ohci);
ohci = hcd_to_ohci(hcd);
ohci_hcd_init(ohci);
err = usb_add_hcd(hcd, irq, IRQF_SHARED);
if (err) {
dev_err(&pdev->dev, "Failed to add USB HCD\n");
goto fail_add_hcd;
}
platform_set_drvdata(pdev, exynos_ohci);
return 0;
fail_add_hcd:
exynos_ohci_phy_disable(exynos_ohci);
fail_io:
clk_disable_unprepare(exynos_ohci->clk);
fail_clk:
usb_put_hcd(hcd);
return err;
}
static int exynos_ohci_remove(struct platform_device *pdev)
{
struct exynos_ohci_hcd *exynos_ohci = platform_get_drvdata(pdev);
struct usb_hcd *hcd = exynos_ohci->hcd;
usb_remove_hcd(hcd);
if (exynos_ohci->otg)
exynos_ohci->otg->set_host(exynos_ohci->otg,
&exynos_ohci->hcd->self);
exynos_ohci_phy_disable(exynos_ohci);
clk_disable_unprepare(exynos_ohci->clk);
usb_put_hcd(hcd);
return 0;
}
static void exynos_ohci_shutdown(struct platform_device *pdev)
{
struct exynos_ohci_hcd *exynos_ohci = platform_get_drvdata(pdev);
struct usb_hcd *hcd = exynos_ohci->hcd;
if (hcd->driver->shutdown)
hcd->driver->shutdown(hcd);
}
static int exynos_ohci_suspend(struct device *dev)
{
struct exynos_ohci_hcd *exynos_ohci = dev_get_drvdata(dev);
struct usb_hcd *hcd = exynos_ohci->hcd;
struct ohci_hcd *ohci = hcd_to_ohci(hcd);
unsigned long flags;
int rc = 0;
spin_lock_irqsave(&ohci->lock, flags);
if (ohci->rh_state != OHCI_RH_SUSPENDED &&
ohci->rh_state != OHCI_RH_HALTED) {
rc = -EINVAL;
goto fail;
}
clear_bit(HCD_FLAG_HW_ACCESSIBLE, &hcd->flags);
if (exynos_ohci->otg)
exynos_ohci->otg->set_host(exynos_ohci->otg,
&exynos_ohci->hcd->self);
exynos_ohci_phy_disable(exynos_ohci);
clk_disable_unprepare(exynos_ohci->clk);
fail:
spin_unlock_irqrestore(&ohci->lock, flags);
return rc;
}
static int exynos_ohci_resume(struct device *dev)
{
struct exynos_ohci_hcd *exynos_ohci = dev_get_drvdata(dev);
struct usb_hcd *hcd = exynos_ohci->hcd;
clk_prepare_enable(exynos_ohci->clk);
if (exynos_ohci->otg)
exynos_ohci->otg->set_host(exynos_ohci->otg,
&exynos_ohci->hcd->self);
exynos_ohci_phy_enable(exynos_ohci);
ohci_resume(hcd, false);
return 0;
}
