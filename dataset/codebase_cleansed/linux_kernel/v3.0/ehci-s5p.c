static int __devinit s5p_ehci_probe(struct platform_device *pdev)
{
struct s5p_ehci_platdata *pdata;
struct s5p_ehci_hcd *s5p_ehci;
struct usb_hcd *hcd;
struct ehci_hcd *ehci;
struct resource *res;
int irq;
int err;
pdata = pdev->dev.platform_data;
if (!pdata) {
dev_err(&pdev->dev, "No platform data defined\n");
return -EINVAL;
}
s5p_ehci = kzalloc(sizeof(struct s5p_ehci_hcd), GFP_KERNEL);
if (!s5p_ehci)
return -ENOMEM;
s5p_ehci->dev = &pdev->dev;
hcd = usb_create_hcd(&s5p_ehci_hc_driver, &pdev->dev,
dev_name(&pdev->dev));
if (!hcd) {
dev_err(&pdev->dev, "Unable to create HCD\n");
err = -ENOMEM;
goto fail_hcd;
}
s5p_ehci->clk = clk_get(&pdev->dev, "usbhost");
if (IS_ERR(s5p_ehci->clk)) {
dev_err(&pdev->dev, "Failed to get usbhost clock\n");
err = PTR_ERR(s5p_ehci->clk);
goto fail_clk;
}
err = clk_enable(s5p_ehci->clk);
if (err)
goto fail_clken;
res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
if (!res) {
dev_err(&pdev->dev, "Failed to get I/O memory\n");
err = -ENXIO;
goto fail_io;
}
hcd->rsrc_start = res->start;
hcd->rsrc_len = resource_size(res);
hcd->regs = ioremap(res->start, resource_size(res));
if (!hcd->regs) {
dev_err(&pdev->dev, "Failed to remap I/O memory\n");
err = -ENOMEM;
goto fail_io;
}
irq = platform_get_irq(pdev, 0);
if (!irq) {
dev_err(&pdev->dev, "Failed to get IRQ\n");
err = -ENODEV;
goto fail;
}
if (pdata->phy_init)
pdata->phy_init(pdev, S5P_USB_PHY_HOST);
ehci = hcd_to_ehci(hcd);
ehci->caps = hcd->regs;
ehci->regs = hcd->regs +
HC_LENGTH(ehci, readl(&ehci->caps->hc_capbase));
dbg_hcs_params(ehci, "reset");
dbg_hcc_params(ehci, "reset");
ehci->hcs_params = readl(&ehci->caps->hcs_params);
err = usb_add_hcd(hcd, irq, IRQF_DISABLED | IRQF_SHARED);
if (err) {
dev_err(&pdev->dev, "Failed to add USB HCD\n");
goto fail;
}
platform_set_drvdata(pdev, s5p_ehci);
return 0;
fail:
iounmap(hcd->regs);
fail_io:
clk_disable(s5p_ehci->clk);
fail_clken:
clk_put(s5p_ehci->clk);
fail_clk:
usb_put_hcd(hcd);
fail_hcd:
kfree(s5p_ehci);
return err;
}
static int __devexit s5p_ehci_remove(struct platform_device *pdev)
{
struct s5p_ehci_platdata *pdata = pdev->dev.platform_data;
struct s5p_ehci_hcd *s5p_ehci = platform_get_drvdata(pdev);
struct usb_hcd *hcd = s5p_ehci->hcd;
usb_remove_hcd(hcd);
if (pdata && pdata->phy_exit)
pdata->phy_exit(pdev, S5P_USB_PHY_HOST);
iounmap(hcd->regs);
clk_disable(s5p_ehci->clk);
clk_put(s5p_ehci->clk);
usb_put_hcd(hcd);
kfree(s5p_ehci);
return 0;
}
static void s5p_ehci_shutdown(struct platform_device *pdev)
{
struct s5p_ehci_hcd *s5p_ehci = platform_get_drvdata(pdev);
struct usb_hcd *hcd = s5p_ehci->hcd;
if (hcd->driver->shutdown)
hcd->driver->shutdown(hcd);
}
