static int usb_hcd_ppc_soc_probe(const struct hc_driver *driver,
struct platform_device *pdev)
{
int retval;
struct usb_hcd *hcd;
struct ohci_hcd *ohci;
struct resource *res;
int irq;
pr_debug("initializing PPC-SOC USB Controller\n");
res = platform_get_resource(pdev, IORESOURCE_IRQ, 0);
if (!res) {
pr_debug("%s: no irq\n", __FILE__);
return -ENODEV;
}
irq = res->start;
res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
if (!res) {
pr_debug("%s: no reg addr\n", __FILE__);
return -ENODEV;
}
hcd = usb_create_hcd(driver, &pdev->dev, "PPC-SOC USB");
if (!hcd)
return -ENOMEM;
hcd->rsrc_start = res->start;
hcd->rsrc_len = resource_size(res);
if (!request_mem_region(hcd->rsrc_start, hcd->rsrc_len, hcd_name)) {
pr_debug("%s: request_mem_region failed\n", __FILE__);
retval = -EBUSY;
goto err1;
}
hcd->regs = ioremap(hcd->rsrc_start, hcd->rsrc_len);
if (!hcd->regs) {
pr_debug("%s: ioremap failed\n", __FILE__);
retval = -ENOMEM;
goto err2;
}
ohci = hcd_to_ohci(hcd);
ohci->flags |= OHCI_QUIRK_BE_MMIO | OHCI_QUIRK_BE_DESC;
#ifdef CONFIG_PPC_MPC52xx
ohci->flags |= OHCI_QUIRK_FRAME_NO;
#endif
ohci_hcd_init(ohci);
retval = usb_add_hcd(hcd, irq, 0);
if (retval == 0)
return retval;
pr_debug("Removing PPC-SOC USB Controller\n");
iounmap(hcd->regs);
err2:
release_mem_region(hcd->rsrc_start, hcd->rsrc_len);
err1:
usb_put_hcd(hcd);
return retval;
}
static void usb_hcd_ppc_soc_remove(struct usb_hcd *hcd,
struct platform_device *pdev)
{
usb_remove_hcd(hcd);
pr_debug("stopping PPC-SOC USB Controller\n");
iounmap(hcd->regs);
release_mem_region(hcd->rsrc_start, hcd->rsrc_len);
usb_put_hcd(hcd);
}
static int __devinit
ohci_ppc_soc_start(struct usb_hcd *hcd)
{
struct ohci_hcd *ohci = hcd_to_ohci(hcd);
int ret;
if ((ret = ohci_init(ohci)) < 0)
return ret;
if ((ret = ohci_run(ohci)) < 0) {
dev_err(hcd->self.controller, "can't start %s\n",
hcd->self.bus_name);
ohci_stop(hcd);
return ret;
}
return 0;
}
static int ohci_hcd_ppc_soc_drv_probe(struct platform_device *pdev)
{
int ret;
if (usb_disabled())
return -ENODEV;
ret = usb_hcd_ppc_soc_probe(&ohci_ppc_soc_hc_driver, pdev);
return ret;
}
static int ohci_hcd_ppc_soc_drv_remove(struct platform_device *pdev)
{
struct usb_hcd *hcd = platform_get_drvdata(pdev);
usb_hcd_ppc_soc_remove(hcd, pdev);
return 0;
}
