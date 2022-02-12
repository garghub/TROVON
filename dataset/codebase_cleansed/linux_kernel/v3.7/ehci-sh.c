static int ehci_sh_reset(struct usb_hcd *hcd)
{
struct ehci_hcd *ehci = hcd_to_ehci(hcd);
int ret;
ehci->caps = hcd->regs;
ret = ehci_setup(hcd);
if (unlikely(ret))
return ret;
ehci_port_power(ehci, 0);
return ret;
}
static int ehci_hcd_sh_probe(struct platform_device *pdev)
{
const struct hc_driver *driver = &ehci_sh_hc_driver;
struct resource *res;
struct ehci_sh_priv *priv;
struct ehci_sh_platdata *pdata;
struct usb_hcd *hcd;
int irq, ret;
if (usb_disabled())
return -ENODEV;
res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
if (!res) {
dev_err(&pdev->dev,
"Found HC with no register addr. Check %s setup!\n",
dev_name(&pdev->dev));
ret = -ENODEV;
goto fail_create_hcd;
}
irq = platform_get_irq(pdev, 0);
if (irq <= 0) {
dev_err(&pdev->dev,
"Found HC with no IRQ. Check %s setup!\n",
dev_name(&pdev->dev));
ret = -ENODEV;
goto fail_create_hcd;
}
pdata = pdev->dev.platform_data;
hcd = usb_create_hcd(&ehci_sh_hc_driver, &pdev->dev,
dev_name(&pdev->dev));
if (!hcd) {
ret = -ENOMEM;
goto fail_create_hcd;
}
hcd->rsrc_start = res->start;
hcd->rsrc_len = resource_size(res);
hcd->regs = devm_request_and_ioremap(&pdev->dev, res);
if (hcd->regs == NULL) {
dev_dbg(&pdev->dev, "error mapping memory\n");
ret = -ENXIO;
goto fail_request_resource;
}
priv = devm_kzalloc(&pdev->dev, sizeof(struct ehci_sh_priv),
GFP_KERNEL);
if (!priv) {
dev_dbg(&pdev->dev, "error allocating priv data\n");
ret = -ENOMEM;
goto fail_request_resource;
}
priv->fclk = devm_clk_get(&pdev->dev, "usb_fck");
if (IS_ERR(priv->fclk))
priv->fclk = NULL;
priv->iclk = devm_clk_get(&pdev->dev, "usb_ick");
if (IS_ERR(priv->iclk))
priv->iclk = NULL;
clk_enable(priv->fclk);
clk_enable(priv->iclk);
if (pdata && pdata->phy_init)
pdata->phy_init();
ret = usb_add_hcd(hcd, irq, IRQF_SHARED);
if (ret != 0) {
dev_err(&pdev->dev, "Failed to add hcd");
goto fail_add_hcd;
}
priv->hcd = hcd;
platform_set_drvdata(pdev, priv);
return ret;
fail_add_hcd:
clk_disable(priv->iclk);
clk_disable(priv->fclk);
fail_request_resource:
usb_put_hcd(hcd);
fail_create_hcd:
dev_err(&pdev->dev, "init %s fail, %d\n", dev_name(&pdev->dev), ret);
return ret;
}
static int __exit ehci_hcd_sh_remove(struct platform_device *pdev)
{
struct ehci_sh_priv *priv = platform_get_drvdata(pdev);
struct usb_hcd *hcd = priv->hcd;
usb_remove_hcd(hcd);
usb_put_hcd(hcd);
platform_set_drvdata(pdev, NULL);
clk_disable(priv->fclk);
clk_disable(priv->iclk);
return 0;
}
static void ehci_hcd_sh_shutdown(struct platform_device *pdev)
{
struct ehci_sh_priv *priv = platform_get_drvdata(pdev);
struct usb_hcd *hcd = priv->hcd;
if (hcd->driver->shutdown)
hcd->driver->shutdown(hcd);
}
