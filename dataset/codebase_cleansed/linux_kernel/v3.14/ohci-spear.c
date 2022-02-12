static int spear_ohci_hcd_drv_probe(struct platform_device *pdev)
{
const struct hc_driver *driver = &ohci_spear_hc_driver;
struct ohci_hcd *ohci;
struct usb_hcd *hcd = NULL;
struct clk *usbh_clk;
struct spear_ohci *sohci_p;
struct resource *res;
int retval, irq;
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
hcd->rsrc_start = pdev->resource[0].start;
hcd->rsrc_len = resource_size(res);
hcd->regs = devm_ioremap_resource(&pdev->dev, res);
if (IS_ERR(hcd->regs)) {
retval = PTR_ERR(hcd->regs);
goto err_put_hcd;
}
sohci_p = to_spear_ohci(hcd);
sohci_p->clk = usbh_clk;
clk_prepare_enable(sohci_p->clk);
ohci = hcd_to_ohci(hcd);
retval = usb_add_hcd(hcd, platform_get_irq(pdev, 0), 0);
if (retval == 0) {
device_wakeup_enable(hcd->self.controller);
return retval;
}
clk_disable_unprepare(sohci_p->clk);
err_put_hcd:
usb_put_hcd(hcd);
fail:
dev_err(&pdev->dev, "init fail, %d\n", retval);
return retval;
}
static int spear_ohci_hcd_drv_remove(struct platform_device *pdev)
{
struct usb_hcd *hcd = platform_get_drvdata(pdev);
struct spear_ohci *sohci_p = to_spear_ohci(hcd);
usb_remove_hcd(hcd);
if (sohci_p->clk)
clk_disable_unprepare(sohci_p->clk);
usb_put_hcd(hcd);
return 0;
}
static int spear_ohci_hcd_drv_suspend(struct platform_device *pdev,
pm_message_t message)
{
struct usb_hcd *hcd = platform_get_drvdata(pdev);
struct ohci_hcd *ohci = hcd_to_ohci(hcd);
struct spear_ohci *sohci_p = to_spear_ohci(hcd);
bool do_wakeup = device_may_wakeup(&pdev->dev);
int ret;
if (time_before(jiffies, ohci->next_statechange))
msleep(5);
ohci->next_statechange = jiffies;
ret = ohci_suspend(hcd, do_wakeup);
if (ret)
return ret;
clk_disable_unprepare(sohci_p->clk);
return ret;
}
static int spear_ohci_hcd_drv_resume(struct platform_device *dev)
{
struct usb_hcd *hcd = platform_get_drvdata(dev);
struct ohci_hcd *ohci = hcd_to_ohci(hcd);
struct spear_ohci *sohci_p = to_spear_ohci(hcd);
if (time_before(jiffies, ohci->next_statechange))
msleep(5);
ohci->next_statechange = jiffies;
clk_prepare_enable(sohci_p->clk);
ohci_resume(hcd, false);
return 0;
}
static int __init ohci_spear_init(void)
{
if (usb_disabled())
return -ENODEV;
pr_info("%s: " DRIVER_DESC "\n", hcd_name);
ohci_init_driver(&ohci_spear_hc_driver, &spear_overrides);
return platform_driver_register(&spear_ohci_hcd_driver);
}
static void __exit ohci_spear_cleanup(void)
{
platform_driver_unregister(&spear_ohci_hcd_driver);
}
