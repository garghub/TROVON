static int usb_w90x900_probe(const struct hc_driver *driver,
struct platform_device *pdev)
{
struct usb_hcd *hcd;
struct ehci_hcd *ehci;
struct resource *res;
int retval = 0, irq;
unsigned long val;
res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
if (!res) {
retval = -ENXIO;
goto err1;
}
hcd = usb_create_hcd(driver, &pdev->dev, "w90x900 EHCI");
if (!hcd) {
retval = -ENOMEM;
goto err1;
}
hcd->rsrc_start = res->start;
hcd->rsrc_len = resource_size(res);
if (!request_mem_region(hcd->rsrc_start, hcd->rsrc_len, hcd_name)) {
retval = -EBUSY;
goto err2;
}
hcd->regs = ioremap(hcd->rsrc_start, hcd->rsrc_len);
if (hcd->regs == NULL) {
retval = -EFAULT;
goto err3;
}
ehci = hcd_to_ehci(hcd);
ehci->caps = hcd->regs;
ehci->regs = hcd->regs +
HC_LENGTH(ehci, ehci_readl(ehci, &ehci->caps->hc_capbase));
val = __raw_readl(ehci->regs+PHY0_CTR);
val |= ENPHY;
__raw_writel(val, ehci->regs+PHY0_CTR);
val = __raw_readl(ehci->regs+PHY1_CTR);
val |= ENPHY;
__raw_writel(val, ehci->regs+PHY1_CTR);
irq = platform_get_irq(pdev, 0);
if (irq < 0)
goto err4;
retval = usb_add_hcd(hcd, irq, IRQF_SHARED);
if (retval != 0)
goto err4;
return retval;
err4:
iounmap(hcd->regs);
err3:
release_mem_region(hcd->rsrc_start, hcd->rsrc_len);
err2:
usb_put_hcd(hcd);
err1:
return retval;
}
static
void usb_w90x900_remove(struct usb_hcd *hcd, struct platform_device *pdev)
{
usb_remove_hcd(hcd);
iounmap(hcd->regs);
release_mem_region(hcd->rsrc_start, hcd->rsrc_len);
usb_put_hcd(hcd);
}
static int ehci_w90x900_probe(struct platform_device *pdev)
{
if (usb_disabled())
return -ENODEV;
return usb_w90x900_probe(&ehci_w90x900_hc_driver, pdev);
}
static int ehci_w90x900_remove(struct platform_device *pdev)
{
struct usb_hcd *hcd = platform_get_drvdata(pdev);
usb_w90x900_remove(hcd, pdev);
return 0;
}
