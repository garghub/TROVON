static int ehci_sh_reset(struct usb_hcd *hcd)
{
struct ehci_hcd *ehci = hcd_to_ehci(hcd);
int ret;
ehci->caps = hcd->regs;
ehci->regs = hcd->regs + HC_LENGTH(ehci, ehci_readl(ehci,
&ehci->caps->hc_capbase));
dbg_hcs_params(ehci, "reset");
dbg_hcc_params(ehci, "reset");
ehci->hcs_params = ehci_readl(ehci, &ehci->caps->hcs_params);
ret = ehci_halt(ehci);
if (unlikely(ret))
return ret;
ret = ehci_init(hcd);
if (unlikely(ret))
return ret;
ehci->sbrn = 0x20;
ehci_reset(ehci);
ehci_port_power(ehci, 0);
return ret;
}
static int ehci_hcd_sh_probe(struct platform_device *pdev)
{
const struct hc_driver *driver = &ehci_sh_hc_driver;
struct resource *res;
struct ehci_sh_priv *priv;
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
hcd = usb_create_hcd(&ehci_sh_hc_driver, &pdev->dev,
dev_name(&pdev->dev));
if (!hcd) {
ret = -ENOMEM;
goto fail_create_hcd;
}
hcd->rsrc_start = res->start;
hcd->rsrc_len = resource_size(res);
if (!request_mem_region(hcd->rsrc_start, hcd->rsrc_len,
driver->description)) {
dev_dbg(&pdev->dev, "controller already in use\n");
ret = -EBUSY;
goto fail_request_resource;
}
hcd->regs = ioremap_nocache(hcd->rsrc_start, hcd->rsrc_len);
if (hcd->regs == NULL) {
dev_dbg(&pdev->dev, "error mapping memory\n");
ret = -ENXIO;
goto fail_ioremap;
}
priv = kmalloc(sizeof(struct ehci_sh_priv), GFP_KERNEL);
if (!priv) {
dev_dbg(&pdev->dev, "error allocating priv data\n");
ret = -ENOMEM;
goto fail_alloc;
}
priv->fclk = clk_get(&pdev->dev, "usb_fck");
if (IS_ERR(priv->fclk))
priv->fclk = NULL;
priv->iclk = clk_get(&pdev->dev, "usb_ick");
if (IS_ERR(priv->iclk))
priv->iclk = NULL;
clk_enable(priv->fclk);
clk_enable(priv->iclk);
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
clk_put(priv->iclk);
clk_put(priv->fclk);
kfree(priv);
fail_alloc:
iounmap(hcd->regs);
fail_ioremap:
release_mem_region(hcd->rsrc_start, hcd->rsrc_len);
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
iounmap(hcd->regs);
release_mem_region(hcd->rsrc_start, hcd->rsrc_len);
usb_put_hcd(hcd);
platform_set_drvdata(pdev, NULL);
clk_disable(priv->fclk);
clk_disable(priv->iclk);
clk_put(priv->fclk);
clk_put(priv->iclk);
kfree(priv);
return 0;
}
static void ehci_hcd_sh_shutdown(struct platform_device *pdev)
{
struct ehci_sh_priv *priv = platform_get_drvdata(pdev);
struct usb_hcd *hcd = priv->hcd;
if (hcd->driver->shutdown)
hcd->driver->shutdown(hcd);
}
