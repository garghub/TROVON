static void s5p_setup_vbus_gpio(struct platform_device *pdev)
{
int err;
int gpio;
if (!pdev->dev.of_node)
return;
gpio = of_get_named_gpio(pdev->dev.of_node,
"samsung,vbus-gpio", 0);
if (!gpio_is_valid(gpio))
return;
err = gpio_request_one(gpio, GPIOF_OUT_INIT_HIGH, "ehci_vbus_gpio");
if (err)
dev_err(&pdev->dev, "can't request ehci vbus gpio %d", gpio);
}
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
if (!pdev->dev.dma_mask)
pdev->dev.dma_mask = &ehci_s5p_dma_mask;
if (!pdev->dev.coherent_dma_mask)
pdev->dev.coherent_dma_mask = DMA_BIT_MASK(32);
s5p_setup_vbus_gpio(pdev);
s5p_ehci = devm_kzalloc(&pdev->dev, sizeof(struct s5p_ehci_hcd),
GFP_KERNEL);
if (!s5p_ehci)
return -ENOMEM;
s5p_ehci->dev = &pdev->dev;
hcd = usb_create_hcd(&s5p_ehci_hc_driver, &pdev->dev,
dev_name(&pdev->dev));
if (!hcd) {
dev_err(&pdev->dev, "Unable to create HCD\n");
return -ENOMEM;
}
s5p_ehci->hcd = hcd;
s5p_ehci->clk = devm_clk_get(&pdev->dev, "usbhost");
if (IS_ERR(s5p_ehci->clk)) {
dev_err(&pdev->dev, "Failed to get usbhost clock\n");
err = PTR_ERR(s5p_ehci->clk);
goto fail_clk;
}
err = clk_enable(s5p_ehci->clk);
if (err)
goto fail_clk;
res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
if (!res) {
dev_err(&pdev->dev, "Failed to get I/O memory\n");
err = -ENXIO;
goto fail_io;
}
hcd->rsrc_start = res->start;
hcd->rsrc_len = resource_size(res);
hcd->regs = devm_ioremap(&pdev->dev, res->start, hcd->rsrc_len);
if (!hcd->regs) {
dev_err(&pdev->dev, "Failed to remap I/O memory\n");
err = -ENOMEM;
goto fail_io;
}
irq = platform_get_irq(pdev, 0);
if (!irq) {
dev_err(&pdev->dev, "Failed to get IRQ\n");
err = -ENODEV;
goto fail_io;
}
if (pdata->phy_init)
pdata->phy_init(pdev, S5P_USB_PHY_HOST);
ehci = hcd_to_ehci(hcd);
ehci->caps = hcd->regs;
writel(EHCI_INSNREG00_ENABLE_DMA_BURST, EHCI_INSNREG00(hcd->regs));
err = usb_add_hcd(hcd, irq, IRQF_SHARED);
if (err) {
dev_err(&pdev->dev, "Failed to add USB HCD\n");
goto fail_io;
}
platform_set_drvdata(pdev, s5p_ehci);
return 0;
fail_io:
clk_disable(s5p_ehci->clk);
fail_clk:
usb_put_hcd(hcd);
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
clk_disable(s5p_ehci->clk);
usb_put_hcd(hcd);
return 0;
}
static void s5p_ehci_shutdown(struct platform_device *pdev)
{
struct s5p_ehci_hcd *s5p_ehci = platform_get_drvdata(pdev);
struct usb_hcd *hcd = s5p_ehci->hcd;
if (hcd->driver->shutdown)
hcd->driver->shutdown(hcd);
}
static int s5p_ehci_suspend(struct device *dev)
{
struct s5p_ehci_hcd *s5p_ehci = dev_get_drvdata(dev);
struct usb_hcd *hcd = s5p_ehci->hcd;
bool do_wakeup = device_may_wakeup(dev);
struct platform_device *pdev = to_platform_device(dev);
struct s5p_ehci_platdata *pdata = pdev->dev.platform_data;
int rc;
rc = ehci_suspend(hcd, do_wakeup);
if (pdata && pdata->phy_exit)
pdata->phy_exit(pdev, S5P_USB_PHY_HOST);
clk_disable(s5p_ehci->clk);
return rc;
}
static int s5p_ehci_resume(struct device *dev)
{
struct s5p_ehci_hcd *s5p_ehci = dev_get_drvdata(dev);
struct usb_hcd *hcd = s5p_ehci->hcd;
struct platform_device *pdev = to_platform_device(dev);
struct s5p_ehci_platdata *pdata = pdev->dev.platform_data;
clk_enable(s5p_ehci->clk);
if (pdata && pdata->phy_init)
pdata->phy_init(pdev, S5P_USB_PHY_HOST);
writel(EHCI_INSNREG00_ENABLE_DMA_BURST, EHCI_INSNREG00(hcd->regs));
ehci_resume(hcd, false);
return 0;
}
