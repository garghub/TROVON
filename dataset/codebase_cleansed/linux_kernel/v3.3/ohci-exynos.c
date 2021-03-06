static int ohci_exynos_start(struct usb_hcd *hcd)
{
struct ohci_hcd *ohci = hcd_to_ohci(hcd);
int ret;
ohci_dbg(ohci, "ohci_exynos_start, ohci:%p", ohci);
ret = ohci_init(ohci);
if (ret < 0)
return ret;
ret = ohci_run(ohci);
if (ret < 0) {
err("can't start %s", hcd->self.bus_name);
ohci_stop(hcd);
return ret;
}
return 0;
}
static int __devinit exynos_ohci_probe(struct platform_device *pdev)
{
struct exynos4_ohci_platdata *pdata;
struct exynos_ohci_hcd *exynos_ohci;
struct usb_hcd *hcd;
struct ohci_hcd *ohci;
struct resource *res;
int irq;
int err;
pdata = pdev->dev.platform_data;
if (!pdata) {
dev_err(&pdev->dev, "No platform data defined\n");
return -EINVAL;
}
exynos_ohci = kzalloc(sizeof(struct exynos_ohci_hcd), GFP_KERNEL);
if (!exynos_ohci)
return -ENOMEM;
exynos_ohci->dev = &pdev->dev;
hcd = usb_create_hcd(&exynos_ohci_hc_driver, &pdev->dev,
dev_name(&pdev->dev));
if (!hcd) {
dev_err(&pdev->dev, "Unable to create HCD\n");
err = -ENOMEM;
goto fail_hcd;
}
exynos_ohci->hcd = hcd;
exynos_ohci->clk = clk_get(&pdev->dev, "usbhost");
if (IS_ERR(exynos_ohci->clk)) {
dev_err(&pdev->dev, "Failed to get usbhost clock\n");
err = PTR_ERR(exynos_ohci->clk);
goto fail_clk;
}
err = clk_enable(exynos_ohci->clk);
if (err)
goto fail_clken;
res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
if (!res) {
dev_err(&pdev->dev, "Failed to get I/O memory\n");
err = -ENXIO;
goto fail_io;
}
hcd->rsrc_start = res->start;
hcd->rsrc_len = resource_size(res);
hcd->regs = ioremap(res->start, resource_size(res));
if (!hcd->regs) {
dev_err(&pdev->dev, "Failed to remap I/O memory\n");
err = -ENOMEM;
goto fail_io;
}
irq = platform_get_irq(pdev, 0);
if (!irq) {
dev_err(&pdev->dev, "Failed to get IRQ\n");
err = -ENODEV;
goto fail;
}
if (pdata->phy_init)
pdata->phy_init(pdev, S5P_USB_PHY_HOST);
ohci = hcd_to_ohci(hcd);
ohci_hcd_init(ohci);
err = usb_add_hcd(hcd, irq, IRQF_SHARED);
if (err) {
dev_err(&pdev->dev, "Failed to add USB HCD\n");
goto fail;
}
platform_set_drvdata(pdev, exynos_ohci);
return 0;
fail:
iounmap(hcd->regs);
fail_io:
clk_disable(exynos_ohci->clk);
fail_clken:
clk_put(exynos_ohci->clk);
fail_clk:
usb_put_hcd(hcd);
fail_hcd:
kfree(exynos_ohci);
return err;
}
static int __devexit exynos_ohci_remove(struct platform_device *pdev)
{
struct exynos4_ohci_platdata *pdata = pdev->dev.platform_data;
struct exynos_ohci_hcd *exynos_ohci = platform_get_drvdata(pdev);
struct usb_hcd *hcd = exynos_ohci->hcd;
usb_remove_hcd(hcd);
if (pdata && pdata->phy_exit)
pdata->phy_exit(pdev, S5P_USB_PHY_HOST);
iounmap(hcd->regs);
clk_disable(exynos_ohci->clk);
clk_put(exynos_ohci->clk);
usb_put_hcd(hcd);
kfree(exynos_ohci);
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
struct platform_device *pdev = to_platform_device(dev);
struct exynos4_ohci_platdata *pdata = pdev->dev.platform_data;
unsigned long flags;
int rc = 0;
spin_lock_irqsave(&ohci->lock, flags);
if (hcd->state != HC_STATE_SUSPENDED && hcd->state != HC_STATE_HALT) {
rc = -EINVAL;
goto fail;
}
clear_bit(HCD_FLAG_HW_ACCESSIBLE, &hcd->flags);
if (pdata && pdata->phy_exit)
pdata->phy_exit(pdev, S5P_USB_PHY_HOST);
fail:
spin_unlock_irqrestore(&ohci->lock, flags);
return rc;
}
static int exynos_ohci_resume(struct device *dev)
{
struct exynos_ohci_hcd *exynos_ohci = dev_get_drvdata(dev);
struct usb_hcd *hcd = exynos_ohci->hcd;
struct platform_device *pdev = to_platform_device(dev);
struct exynos4_ohci_platdata *pdata = pdev->dev.platform_data;
if (pdata && pdata->phy_init)
pdata->phy_init(pdev, S5P_USB_PHY_HOST);
set_bit(HCD_FLAG_HW_ACCESSIBLE, &hcd->flags);
ohci_finish_controller_resume(hcd);
return 0;
}
