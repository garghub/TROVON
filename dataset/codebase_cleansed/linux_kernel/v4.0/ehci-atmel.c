static void atmel_start_clock(struct atmel_ehci_priv *atmel_ehci)
{
if (atmel_ehci->clocked)
return;
clk_prepare_enable(atmel_ehci->uclk);
clk_prepare_enable(atmel_ehci->iclk);
atmel_ehci->clocked = true;
}
static void atmel_stop_clock(struct atmel_ehci_priv *atmel_ehci)
{
if (!atmel_ehci->clocked)
return;
clk_disable_unprepare(atmel_ehci->iclk);
clk_disable_unprepare(atmel_ehci->uclk);
atmel_ehci->clocked = false;
}
static void atmel_start_ehci(struct platform_device *pdev)
{
struct usb_hcd *hcd = platform_get_drvdata(pdev);
struct atmel_ehci_priv *atmel_ehci = hcd_to_atmel_ehci_priv(hcd);
dev_dbg(&pdev->dev, "start\n");
atmel_start_clock(atmel_ehci);
}
static void atmel_stop_ehci(struct platform_device *pdev)
{
struct usb_hcd *hcd = platform_get_drvdata(pdev);
struct atmel_ehci_priv *atmel_ehci = hcd_to_atmel_ehci_priv(hcd);
dev_dbg(&pdev->dev, "stop\n");
atmel_stop_clock(atmel_ehci);
}
static int ehci_atmel_drv_probe(struct platform_device *pdev)
{
struct usb_hcd *hcd;
const struct hc_driver *driver = &ehci_atmel_hc_driver;
struct resource *res;
struct ehci_hcd *ehci;
struct atmel_ehci_priv *atmel_ehci;
int irq;
int retval;
if (usb_disabled())
return -ENODEV;
pr_debug("Initializing Atmel-SoC USB Host Controller\n");
irq = platform_get_irq(pdev, 0);
if (irq <= 0) {
dev_err(&pdev->dev,
"Found HC with no IRQ. Check %s setup!\n",
dev_name(&pdev->dev));
retval = -ENODEV;
goto fail_create_hcd;
}
retval = dma_coerce_mask_and_coherent(&pdev->dev, DMA_BIT_MASK(32));
if (retval)
goto fail_create_hcd;
hcd = usb_create_hcd(driver, &pdev->dev, dev_name(&pdev->dev));
if (!hcd) {
retval = -ENOMEM;
goto fail_create_hcd;
}
atmel_ehci = hcd_to_atmel_ehci_priv(hcd);
res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
hcd->regs = devm_ioremap_resource(&pdev->dev, res);
if (IS_ERR(hcd->regs)) {
retval = PTR_ERR(hcd->regs);
goto fail_request_resource;
}
hcd->rsrc_start = res->start;
hcd->rsrc_len = resource_size(res);
atmel_ehci->iclk = devm_clk_get(&pdev->dev, "ehci_clk");
if (IS_ERR(atmel_ehci->iclk)) {
dev_err(&pdev->dev, "Error getting interface clock\n");
retval = -ENOENT;
goto fail_request_resource;
}
atmel_ehci->uclk = devm_clk_get(&pdev->dev, "usb_clk");
if (IS_ERR(atmel_ehci->uclk)) {
dev_err(&pdev->dev, "failed to get uclk\n");
retval = PTR_ERR(atmel_ehci->uclk);
goto fail_request_resource;
}
ehci = hcd_to_ehci(hcd);
ehci->caps = hcd->regs;
atmel_start_ehci(pdev);
retval = usb_add_hcd(hcd, irq, IRQF_SHARED);
if (retval)
goto fail_add_hcd;
device_wakeup_enable(hcd->self.controller);
return retval;
fail_add_hcd:
atmel_stop_ehci(pdev);
fail_request_resource:
usb_put_hcd(hcd);
fail_create_hcd:
dev_err(&pdev->dev, "init %s fail, %d\n",
dev_name(&pdev->dev), retval);
return retval;
}
static int ehci_atmel_drv_remove(struct platform_device *pdev)
{
struct usb_hcd *hcd = platform_get_drvdata(pdev);
usb_remove_hcd(hcd);
usb_put_hcd(hcd);
atmel_stop_ehci(pdev);
return 0;
}
static int ehci_atmel_drv_suspend(struct device *dev)
{
struct usb_hcd *hcd = dev_get_drvdata(dev);
struct atmel_ehci_priv *atmel_ehci = hcd_to_atmel_ehci_priv(hcd);
int ret;
ret = ehci_suspend(hcd, false);
if (ret)
return ret;
atmel_stop_clock(atmel_ehci);
return 0;
}
static int ehci_atmel_drv_resume(struct device *dev)
{
struct usb_hcd *hcd = dev_get_drvdata(dev);
struct atmel_ehci_priv *atmel_ehci = hcd_to_atmel_ehci_priv(hcd);
atmel_start_clock(atmel_ehci);
return ehci_resume(hcd, false);
}
static int __init ehci_atmel_init(void)
{
if (usb_disabled())
return -ENODEV;
pr_info("%s: " DRIVER_DESC "\n", hcd_name);
ehci_init_driver(&ehci_atmel_hc_driver, &ehci_atmel_drv_overrides);
return platform_driver_register(&ehci_atmel_driver);
}
static void __exit ehci_atmel_cleanup(void)
{
platform_driver_unregister(&ehci_atmel_driver);
}
