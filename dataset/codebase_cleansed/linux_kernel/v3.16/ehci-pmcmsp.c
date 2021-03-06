static void usb_hcd_tdi_set_mode(struct ehci_hcd *ehci)
{
u8 *base;
u8 *statreg;
u8 *fiforeg;
u32 val;
struct ehci_regs *reg_base = ehci->regs;
base = (u8 *)reg_base + USB_EHCI_REG_USB_MODE;
statreg = (u8 *)reg_base + USB_EHCI_REG_USB_STATUS;
fiforeg = (u8 *)reg_base + USB_EHCI_REG_USB_FIFO;
val = ehci_readl(ehci, (u32 *)base);
ehci_writel(ehci, (val | USB_CTRL_MODE_STREAM_DISABLE),
(u32 *)base);
val = ehci_readl(ehci, (u32 *)statreg);
val = val & ~USB_EHCI_REG_BIT_STAT_STS;
ehci_writel(ehci, val, (u32 *)statreg);
ehci_writel(ehci, USB_CTRL_FIFO_THRESH, (u32 *)fiforeg);
gpio_direction_output(MSP_PIN_USB0_HOST_DEV, 1);
}
static int ehci_msp_setup(struct usb_hcd *hcd)
{
struct ehci_hcd *ehci = hcd_to_ehci(hcd);
int retval;
ehci->big_endian_mmio = 1;
ehci->big_endian_desc = 1;
ehci->caps = hcd->regs;
hcd->has_tt = 1;
retval = ehci_setup(hcd);
if (retval)
return retval;
usb_hcd_tdi_set_mode(ehci);
return retval;
}
static int usb_hcd_msp_map_regs(struct mspusb_device *dev)
{
struct resource *res;
struct platform_device *pdev = &dev->dev;
u32 res_len;
int retval;
res = platform_get_resource(pdev, IORESOURCE_MEM, 1);
if (res == NULL)
return -ENOMEM;
res_len = resource_size(res);
if (!request_mem_region(res->start, res_len, "mab regs"))
return -EBUSY;
dev->mab_regs = ioremap_nocache(res->start, res_len);
if (dev->mab_regs == NULL) {
retval = -ENOMEM;
goto err1;
}
res = platform_get_resource(pdev, IORESOURCE_MEM, 2);
if (res == NULL) {
retval = -ENOMEM;
goto err2;
}
res_len = resource_size(res);
if (!request_mem_region(res->start, res_len, "usbid regs")) {
retval = -EBUSY;
goto err2;
}
dev->usbid_regs = ioremap_nocache(res->start, res_len);
if (dev->usbid_regs == NULL) {
retval = -ENOMEM;
goto err3;
}
return 0;
err3:
res = platform_get_resource(pdev, IORESOURCE_MEM, 2);
res_len = resource_size(res);
release_mem_region(res->start, res_len);
err2:
iounmap(dev->mab_regs);
err1:
res = platform_get_resource(pdev, IORESOURCE_MEM, 1);
res_len = resource_size(res);
release_mem_region(res->start, res_len);
dev_err(&pdev->dev, "Failed to map non-EHCI regs.\n");
return retval;
}
int usb_hcd_msp_probe(const struct hc_driver *driver,
struct platform_device *dev)
{
int retval;
struct usb_hcd *hcd;
struct resource *res;
struct ehci_hcd *ehci ;
hcd = usb_create_hcd(driver, &dev->dev, "pmcmsp");
if (!hcd)
return -ENOMEM;
res = platform_get_resource(dev, IORESOURCE_MEM, 0);
if (res == NULL) {
pr_debug("No IOMEM resource info for %s.\n", dev->name);
retval = -ENOMEM;
goto err1;
}
hcd->rsrc_start = res->start;
hcd->rsrc_len = resource_size(res);
if (!request_mem_region(hcd->rsrc_start, hcd->rsrc_len, dev->name)) {
retval = -EBUSY;
goto err1;
}
hcd->regs = ioremap_nocache(hcd->rsrc_start, hcd->rsrc_len);
if (!hcd->regs) {
pr_debug("ioremap failed");
retval = -ENOMEM;
goto err2;
}
res = platform_get_resource(dev, IORESOURCE_IRQ, 0);
if (res == NULL) {
dev_err(&dev->dev, "No IRQ resource info for %s.\n", dev->name);
retval = -ENOMEM;
goto err3;
}
retval = usb_hcd_msp_map_regs(to_mspusb_device(dev));
if (retval != 0)
goto err3;
ehci = hcd_to_ehci(hcd);
ehci->big_endian_mmio = 1;
ehci->big_endian_desc = 1;
retval = usb_add_hcd(hcd, res->start, IRQF_SHARED);
if (retval == 0) {
device_wakeup_enable(hcd->self.controller);
return 0;
}
usb_remove_hcd(hcd);
err3:
iounmap(hcd->regs);
err2:
release_mem_region(hcd->rsrc_start, hcd->rsrc_len);
err1:
usb_put_hcd(hcd);
return retval;
}
void usb_hcd_msp_remove(struct usb_hcd *hcd, struct platform_device *dev)
{
usb_remove_hcd(hcd);
iounmap(hcd->regs);
release_mem_region(hcd->rsrc_start, hcd->rsrc_len);
usb_put_hcd(hcd);
}
static int ehci_hcd_msp_drv_probe(struct platform_device *pdev)
{
int ret;
pr_debug("In ehci_hcd_msp_drv_probe");
if (usb_disabled())
return -ENODEV;
gpio_request(MSP_PIN_USB0_HOST_DEV, "USB0_HOST_DEV_GPIO");
ret = usb_hcd_msp_probe(&ehci_msp_hc_driver, pdev);
return ret;
}
static int ehci_hcd_msp_drv_remove(struct platform_device *pdev)
{
struct usb_hcd *hcd = platform_get_drvdata(pdev);
usb_hcd_msp_remove(hcd, pdev);
gpio_free(MSP_PIN_USB0_HOST_DEV);
return 0;
}
