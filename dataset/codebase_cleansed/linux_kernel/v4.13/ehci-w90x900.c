static int ehci_w90x900_probe(struct platform_device *pdev)
{
struct usb_hcd *hcd;
struct ehci_hcd *ehci;
struct resource *res;
int retval = 0, irq;
unsigned long val;
hcd = usb_create_hcd(&ehci_w90x900_hc_driver,
&pdev->dev, "w90x900 EHCI");
if (!hcd) {
retval = -ENOMEM;
goto err1;
}
res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
hcd->regs = devm_ioremap_resource(&pdev->dev, res);
if (IS_ERR(hcd->regs)) {
retval = PTR_ERR(hcd->regs);
goto err2;
}
hcd->rsrc_start = res->start;
hcd->rsrc_len = resource_size(res);
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
if (irq < 0) {
retval = irq;
goto err2;
}
retval = usb_add_hcd(hcd, irq, IRQF_SHARED);
if (retval != 0)
goto err2;
device_wakeup_enable(hcd->self.controller);
return retval;
err2:
usb_put_hcd(hcd);
err1:
return retval;
}
static int ehci_w90x900_remove(struct platform_device *pdev)
{
struct usb_hcd *hcd = platform_get_drvdata(pdev);
usb_remove_hcd(hcd);
usb_put_hcd(hcd);
return 0;
}
static int __init ehci_w90X900_init(void)
{
if (usb_disabled())
return -ENODEV;
pr_info("%s: " DRIVER_DESC "\n", hcd_name);
ehci_init_driver(&ehci_w90x900_hc_driver, NULL);
return platform_driver_register(&ehci_hcd_w90x900_driver);
}
static void __exit ehci_w90X900_cleanup(void)
{
platform_driver_unregister(&ehci_hcd_w90x900_driver);
}
