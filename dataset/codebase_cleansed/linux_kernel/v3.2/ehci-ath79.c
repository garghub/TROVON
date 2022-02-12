static int ehci_ath79_init(struct usb_hcd *hcd)
{
struct ehci_hcd *ehci = hcd_to_ehci(hcd);
struct platform_device *pdev = to_platform_device(hcd->self.controller);
const struct platform_device_id *id;
int ret;
id = platform_get_device_id(pdev);
if (!id) {
dev_err(hcd->self.controller, "missing device id\n");
return -EINVAL;
}
switch (id->driver_data) {
case EHCI_ATH79_IP_V1:
ehci->has_synopsys_hc_bug = 1;
ehci->caps = hcd->regs;
ehci->regs = hcd->regs +
HC_LENGTH(ehci,
ehci_readl(ehci, &ehci->caps->hc_capbase));
break;
case EHCI_ATH79_IP_V2:
hcd->has_tt = 1;
ehci->caps = hcd->regs + 0x100;
ehci->regs = hcd->regs + 0x100 +
HC_LENGTH(ehci,
ehci_readl(ehci, &ehci->caps->hc_capbase));
break;
default:
BUG();
}
dbg_hcs_params(ehci, "reset");
dbg_hcc_params(ehci, "reset");
ehci->hcs_params = ehci_readl(ehci, &ehci->caps->hcs_params);
ehci->sbrn = 0x20;
ehci_reset(ehci);
ret = ehci_init(hcd);
if (ret)
return ret;
ehci_port_power(ehci, 0);
return 0;
}
static int ehci_ath79_probe(struct platform_device *pdev)
{
struct usb_hcd *hcd;
struct resource *res;
int irq;
int ret;
if (usb_disabled())
return -ENODEV;
res = platform_get_resource(pdev, IORESOURCE_IRQ, 0);
if (!res) {
dev_dbg(&pdev->dev, "no IRQ specified\n");
return -ENODEV;
}
irq = res->start;
res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
if (!res) {
dev_dbg(&pdev->dev, "no base address specified\n");
return -ENODEV;
}
hcd = usb_create_hcd(&ehci_ath79_hc_driver, &pdev->dev,
dev_name(&pdev->dev));
if (!hcd)
return -ENOMEM;
hcd->rsrc_start = res->start;
hcd->rsrc_len = resource_size(res);
if (!request_mem_region(hcd->rsrc_start, hcd->rsrc_len, hcd_name)) {
dev_dbg(&pdev->dev, "controller already in use\n");
ret = -EBUSY;
goto err_put_hcd;
}
hcd->regs = ioremap(hcd->rsrc_start, hcd->rsrc_len);
if (!hcd->regs) {
dev_dbg(&pdev->dev, "error mapping memory\n");
ret = -EFAULT;
goto err_release_region;
}
ret = usb_add_hcd(hcd, irq, IRQF_SHARED);
if (ret)
goto err_iounmap;
return 0;
err_iounmap:
iounmap(hcd->regs);
err_release_region:
release_mem_region(hcd->rsrc_start, hcd->rsrc_len);
err_put_hcd:
usb_put_hcd(hcd);
return ret;
}
static int ehci_ath79_remove(struct platform_device *pdev)
{
struct usb_hcd *hcd = platform_get_drvdata(pdev);
usb_remove_hcd(hcd);
iounmap(hcd->regs);
release_mem_region(hcd->rsrc_start, hcd->rsrc_len);
usb_put_hcd(hcd);
return 0;
}
