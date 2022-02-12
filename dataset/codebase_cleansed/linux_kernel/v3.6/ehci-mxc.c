static int ehci_mxc_setup(struct usb_hcd *hcd)
{
struct ehci_hcd *ehci = hcd_to_ehci(hcd);
int retval;
hcd->has_tt = 1;
retval = ehci_setup(hcd);
if (retval)
return retval;
ehci_port_power(ehci, 0);
return 0;
}
static int ehci_mxc_drv_probe(struct platform_device *pdev)
{
struct mxc_usbh_platform_data *pdata = pdev->dev.platform_data;
struct usb_hcd *hcd;
struct resource *res;
int irq, ret;
unsigned int flags;
struct ehci_mxc_priv *priv;
struct device *dev = &pdev->dev;
struct ehci_hcd *ehci;
dev_info(&pdev->dev, "initializing i.MX USB Controller\n");
if (!pdata) {
dev_err(dev, "No platform data given, bailing out.\n");
return -EINVAL;
}
irq = platform_get_irq(pdev, 0);
hcd = usb_create_hcd(&ehci_mxc_hc_driver, dev, dev_name(dev));
if (!hcd)
return -ENOMEM;
priv = kzalloc(sizeof(*priv), GFP_KERNEL);
if (!priv) {
ret = -ENOMEM;
goto err_alloc;
}
res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
if (!res) {
dev_err(dev, "Found HC with no register addr. Check setup!\n");
ret = -ENODEV;
goto err_get_resource;
}
hcd->rsrc_start = res->start;
hcd->rsrc_len = resource_size(res);
if (!request_mem_region(hcd->rsrc_start, hcd->rsrc_len, hcd_name)) {
dev_dbg(dev, "controller already in use\n");
ret = -EBUSY;
goto err_request_mem;
}
hcd->regs = ioremap(hcd->rsrc_start, hcd->rsrc_len);
if (!hcd->regs) {
dev_err(dev, "error mapping memory\n");
ret = -EFAULT;
goto err_ioremap;
}
priv->usbclk = clk_get(dev, "ipg");
if (IS_ERR(priv->usbclk)) {
ret = PTR_ERR(priv->usbclk);
goto err_clk;
}
clk_prepare_enable(priv->usbclk);
priv->ahbclk = clk_get(dev, "ahb");
if (IS_ERR(priv->ahbclk)) {
ret = PTR_ERR(priv->ahbclk);
goto err_clk_ahb;
}
clk_prepare_enable(priv->ahbclk);
priv->phyclk = clk_get(dev, "phy");
if (IS_ERR(priv->phyclk))
priv->phyclk = NULL;
if (priv->phyclk)
clk_prepare_enable(priv->phyclk);
if (pdata->init) {
ret = pdata->init(pdev);
if (ret) {
dev_err(dev, "platform init failed\n");
goto err_init;
}
mdelay(10);
}
ehci = hcd_to_ehci(hcd);
ehci->caps = hcd->regs + 0x100;
ehci->regs = hcd->regs + 0x100 +
HC_LENGTH(ehci, ehci_readl(ehci, &ehci->caps->hc_capbase));
ehci_writel(ehci, pdata->portsc, &ehci->regs->port_status[0]);
msleep(10);
if (pdata->otg) {
pdata->otg->io_priv = hcd->regs + ULPI_VIEWPORT_OFFSET;
ret = usb_phy_init(pdata->otg);
if (ret) {
dev_err(dev, "unable to init transceiver, probably missing\n");
ret = -ENODEV;
goto err_add;
}
ret = otg_set_vbus(pdata->otg->otg, 1);
if (ret) {
dev_err(dev, "unable to enable vbus on transceiver\n");
goto err_add;
}
}
priv->hcd = hcd;
platform_set_drvdata(pdev, priv);
ret = usb_add_hcd(hcd, irq, IRQF_SHARED);
if (ret)
goto err_add;
if (pdata->otg) {
if (machine_is_mx51_efikamx() || machine_is_mx51_efikasb()) {
flags = usb_phy_io_read(pdata->otg,
ULPI_OTG_CTRL);
flags |= ULPI_OTG_CTRL_CHRGVBUS;
ret = usb_phy_io_write(pdata->otg, flags,
ULPI_OTG_CTRL);
if (ret) {
dev_err(dev, "unable to set CHRVBUS\n");
goto err_add;
}
}
}
return 0;
err_add:
if (pdata && pdata->exit)
pdata->exit(pdev);
err_init:
if (priv->phyclk) {
clk_disable_unprepare(priv->phyclk);
clk_put(priv->phyclk);
}
clk_disable_unprepare(priv->ahbclk);
clk_put(priv->ahbclk);
err_clk_ahb:
clk_disable_unprepare(priv->usbclk);
clk_put(priv->usbclk);
err_clk:
iounmap(hcd->regs);
err_ioremap:
release_mem_region(hcd->rsrc_start, hcd->rsrc_len);
err_request_mem:
err_get_resource:
kfree(priv);
err_alloc:
usb_put_hcd(hcd);
return ret;
}
static int __exit ehci_mxc_drv_remove(struct platform_device *pdev)
{
struct mxc_usbh_platform_data *pdata = pdev->dev.platform_data;
struct ehci_mxc_priv *priv = platform_get_drvdata(pdev);
struct usb_hcd *hcd = priv->hcd;
if (pdata && pdata->exit)
pdata->exit(pdev);
if (pdata->otg)
usb_phy_shutdown(pdata->otg);
usb_remove_hcd(hcd);
iounmap(hcd->regs);
release_mem_region(hcd->rsrc_start, hcd->rsrc_len);
usb_put_hcd(hcd);
platform_set_drvdata(pdev, NULL);
clk_disable_unprepare(priv->usbclk);
clk_put(priv->usbclk);
clk_disable_unprepare(priv->ahbclk);
clk_put(priv->ahbclk);
if (priv->phyclk) {
clk_disable_unprepare(priv->phyclk);
clk_put(priv->phyclk);
}
kfree(priv);
return 0;
}
static void ehci_mxc_drv_shutdown(struct platform_device *pdev)
{
struct ehci_mxc_priv *priv = platform_get_drvdata(pdev);
struct usb_hcd *hcd = priv->hcd;
if (hcd->driver->shutdown)
hcd->driver->shutdown(hcd);
}
