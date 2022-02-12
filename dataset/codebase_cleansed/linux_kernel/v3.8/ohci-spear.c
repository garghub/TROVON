static void spear_start_ohci(struct spear_ohci *ohci)
{
clk_prepare_enable(ohci->clk);
}
static void spear_stop_ohci(struct spear_ohci *ohci)
{
clk_disable_unprepare(ohci->clk);
}
static int ohci_spear_start(struct usb_hcd *hcd)
{
struct ohci_hcd *ohci = hcd_to_ohci(hcd);
int ret;
ret = ohci_init(ohci);
if (ret < 0)
return ret;
ohci->regs = hcd->regs;
ret = ohci_run(ohci);
if (ret < 0) {
dev_err(hcd->self.controller, "can't start\n");
ohci_stop(hcd);
return ret;
}
create_debug_files(ohci);
#ifdef DEBUG
ohci_dump(ohci, 1);
#endif
return 0;
}
static int spear_ohci_hcd_drv_probe(struct platform_device *pdev)
{
const struct hc_driver *driver = &ohci_spear_hc_driver;
struct usb_hcd *hcd = NULL;
struct clk *usbh_clk;
struct spear_ohci *ohci_p;
struct resource *res;
int retval, irq;
irq = platform_get_irq(pdev, 0);
if (irq < 0) {
retval = irq;
goto fail;
}
if (!pdev->dev.dma_mask)
pdev->dev.dma_mask = &spear_ohci_dma_mask;
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
hcd->rsrc_start = pdev->resource[0].start;
hcd->rsrc_len = resource_size(res);
if (!devm_request_mem_region(&pdev->dev, hcd->rsrc_start, hcd->rsrc_len,
hcd_name)) {
dev_dbg(&pdev->dev, "request_mem_region failed\n");
retval = -EBUSY;
goto err_put_hcd;
}
hcd->regs = devm_ioremap(&pdev->dev, hcd->rsrc_start, hcd->rsrc_len);
if (!hcd->regs) {
dev_dbg(&pdev->dev, "ioremap failed\n");
retval = -ENOMEM;
goto err_put_hcd;
}
ohci_p = (struct spear_ohci *)hcd_to_ohci(hcd);
ohci_p->clk = usbh_clk;
spear_start_ohci(ohci_p);
ohci_hcd_init(hcd_to_ohci(hcd));
retval = usb_add_hcd(hcd, platform_get_irq(pdev, 0), 0);
if (retval == 0)
return retval;
spear_stop_ohci(ohci_p);
err_put_hcd:
usb_put_hcd(hcd);
fail:
dev_err(&pdev->dev, "init fail, %d\n", retval);
return retval;
}
static int spear_ohci_hcd_drv_remove(struct platform_device *pdev)
{
struct usb_hcd *hcd = platform_get_drvdata(pdev);
struct spear_ohci *ohci_p = to_spear_ohci(hcd);
usb_remove_hcd(hcd);
if (ohci_p->clk)
spear_stop_ohci(ohci_p);
usb_put_hcd(hcd);
platform_set_drvdata(pdev, NULL);
return 0;
}
static int spear_ohci_hcd_drv_suspend(struct platform_device *dev,
pm_message_t message)
{
struct usb_hcd *hcd = platform_get_drvdata(dev);
struct ohci_hcd *ohci = hcd_to_ohci(hcd);
struct spear_ohci *ohci_p = to_spear_ohci(hcd);
if (time_before(jiffies, ohci->next_statechange))
msleep(5);
ohci->next_statechange = jiffies;
spear_stop_ohci(ohci_p);
return 0;
}
static int spear_ohci_hcd_drv_resume(struct platform_device *dev)
{
struct usb_hcd *hcd = platform_get_drvdata(dev);
struct ohci_hcd *ohci = hcd_to_ohci(hcd);
struct spear_ohci *ohci_p = to_spear_ohci(hcd);
if (time_before(jiffies, ohci->next_statechange))
msleep(5);
ohci->next_statechange = jiffies;
spear_start_ohci(ohci_p);
ohci_resume(hcd, false);
return 0;
}
