static void spear_start_ehci(struct spear_ehci *ehci)
{
clk_prepare_enable(ehci->clk);
}
static void spear_stop_ehci(struct spear_ehci *ehci)
{
clk_disable_unprepare(ehci->clk);
}
static int ehci_spear_setup(struct usb_hcd *hcd)
{
struct ehci_hcd *ehci = hcd_to_ehci(hcd);
ehci->caps = hcd->regs;
return ehci_setup(hcd);
}
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
struct spear_ehci *ehci;
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
if (!pdev->dev.dma_mask)
pdev->dev.dma_mask = &spear_ehci_dma_mask;
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
ehci = (struct spear_ehci *)hcd_to_ehci(hcd);
ehci->clk = usbh_clk;
spear_start_ehci(ehci);
retval = usb_add_hcd(hcd, irq, IRQF_SHARED);
if (retval)
goto err_stop_ehci;
return retval;
err_stop_ehci:
spear_stop_ehci(ehci);
err_put_hcd:
usb_put_hcd(hcd);
fail:
dev_err(&pdev->dev, "init fail, %d\n", retval);
return retval ;
}
static int spear_ehci_hcd_drv_remove(struct platform_device *pdev)
{
struct usb_hcd *hcd = platform_get_drvdata(pdev);
struct spear_ehci *ehci_p = to_spear_ehci(hcd);
if (!hcd)
return 0;
if (in_interrupt())
BUG();
usb_remove_hcd(hcd);
if (ehci_p->clk)
spear_stop_ehci(ehci_p);
usb_put_hcd(hcd);
return 0;
}
