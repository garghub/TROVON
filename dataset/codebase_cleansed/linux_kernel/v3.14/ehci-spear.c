static int ehci_spear_drv_suspend(struct device *dev)
{
struct usb_hcd *hcd = dev_get_drvdata(dev);
bool do_wakeup = device_may_wakeup(dev);
return ehci_suspend(hcd, do_wakeup);
}
static int ehci_spear_drv_resume(struct device *dev)
{
struct usb_hcd *hcd = dev_get_drvdata(dev);
ehci_resume(hcd, false);
return 0;
}
static int spear_ehci_hcd_drv_probe(struct platform_device *pdev)
{
struct usb_hcd *hcd ;
struct spear_ehci *sehci;
struct resource *res;
struct clk *usbh_clk;
const struct hc_driver *driver = &ehci_spear_hc_driver;
int irq, retval;
if (usb_disabled())
return -ENODEV;
irq = platform_get_irq(pdev, 0);
if (irq < 0) {
retval = irq;
goto fail;
}
retval = dma_coerce_mask_and_coherent(&pdev->dev, DMA_BIT_MASK(32));
if (retval)
goto fail;
usbh_clk = devm_clk_get(&pdev->dev, NULL);
if (IS_ERR(usbh_clk)) {
dev_err(&pdev->dev, "Error getting interface clock\n");
retval = PTR_ERR(usbh_clk);
goto fail;
}
hcd = usb_create_hcd(driver, &pdev->dev, dev_name(&pdev->dev));
if (!hcd) {
retval = -ENOMEM;
goto fail;
}
res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
if (!res) {
retval = -ENODEV;
goto err_put_hcd;
}
hcd->rsrc_start = res->start;
hcd->rsrc_len = resource_size(res);
if (!devm_request_mem_region(&pdev->dev, hcd->rsrc_start, hcd->rsrc_len,
driver->description)) {
retval = -EBUSY;
goto err_put_hcd;
}
hcd->regs = devm_ioremap(&pdev->dev, hcd->rsrc_start, hcd->rsrc_len);
if (hcd->regs == NULL) {
dev_dbg(&pdev->dev, "error mapping memory\n");
retval = -ENOMEM;
goto err_put_hcd;
}
sehci = to_spear_ehci(hcd);
sehci->clk = usbh_clk;
hcd_to_ehci(hcd)->caps = hcd->regs;
clk_prepare_enable(sehci->clk);
retval = usb_add_hcd(hcd, irq, IRQF_SHARED);
if (retval)
goto err_stop_ehci;
device_wakeup_enable(hcd->self.controller);
return retval;
err_stop_ehci:
clk_disable_unprepare(sehci->clk);
err_put_hcd:
usb_put_hcd(hcd);
fail:
dev_err(&pdev->dev, "init fail, %d\n", retval);
return retval ;
}
static int spear_ehci_hcd_drv_remove(struct platform_device *pdev)
{
struct usb_hcd *hcd = platform_get_drvdata(pdev);
struct spear_ehci *sehci = to_spear_ehci(hcd);
usb_remove_hcd(hcd);
if (sehci->clk)
clk_disable_unprepare(sehci->clk);
usb_put_hcd(hcd);
return 0;
}
static int __init ehci_spear_init(void)
{
if (usb_disabled())
return -ENODEV;
pr_info("%s: " DRIVER_DESC "\n", hcd_name);
ehci_init_driver(&ehci_spear_hc_driver, &spear_overrides);
return platform_driver_register(&spear_ehci_hcd_driver);
}
static void __exit ehci_spear_cleanup(void)
{
platform_driver_unregister(&spear_ehci_hcd_driver);
}
