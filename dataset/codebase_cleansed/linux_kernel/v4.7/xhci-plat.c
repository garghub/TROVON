static void xhci_priv_plat_start(struct usb_hcd *hcd)
{
struct xhci_plat_priv *priv = hcd_to_xhci_priv(hcd);
if (priv->plat_start)
priv->plat_start(hcd);
}
static int xhci_priv_init_quirk(struct usb_hcd *hcd)
{
struct xhci_plat_priv *priv = hcd_to_xhci_priv(hcd);
if (!priv->init_quirk)
return 0;
return priv->init_quirk(hcd);
}
static void xhci_plat_quirks(struct device *dev, struct xhci_hcd *xhci)
{
xhci->quirks |= XHCI_PLAT;
}
static int xhci_plat_setup(struct usb_hcd *hcd)
{
int ret;
ret = xhci_priv_init_quirk(hcd);
if (ret)
return ret;
return xhci_gen_setup(hcd, xhci_plat_quirks);
}
static int xhci_plat_start(struct usb_hcd *hcd)
{
xhci_priv_plat_start(hcd);
return xhci_run(hcd);
}
static int xhci_plat_probe(struct platform_device *pdev)
{
struct device_node *node = pdev->dev.of_node;
struct usb_xhci_pdata *pdata = dev_get_platdata(&pdev->dev);
const struct of_device_id *match;
const struct hc_driver *driver;
struct xhci_hcd *xhci;
struct resource *res;
struct usb_hcd *hcd;
struct clk *clk;
int ret;
int irq;
if (usb_disabled())
return -ENODEV;
driver = &xhci_plat_hc_driver;
irq = platform_get_irq(pdev, 0);
if (irq < 0)
return -ENODEV;
if (WARN_ON(!pdev->dev.dma_mask))
ret = dma_coerce_mask_and_coherent(&pdev->dev,
DMA_BIT_MASK(64));
else
ret = dma_set_mask_and_coherent(&pdev->dev, DMA_BIT_MASK(64));
if (ret) {
ret = dma_set_mask_and_coherent(&pdev->dev, DMA_BIT_MASK(32));
if (ret)
return ret;
}
hcd = usb_create_hcd(driver, &pdev->dev, dev_name(&pdev->dev));
if (!hcd)
return -ENOMEM;
res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
hcd->regs = devm_ioremap_resource(&pdev->dev, res);
if (IS_ERR(hcd->regs)) {
ret = PTR_ERR(hcd->regs);
goto put_hcd;
}
hcd->rsrc_start = res->start;
hcd->rsrc_len = resource_size(res);
clk = devm_clk_get(&pdev->dev, NULL);
if (!IS_ERR(clk)) {
ret = clk_prepare_enable(clk);
if (ret)
goto put_hcd;
} else if (PTR_ERR(clk) == -EPROBE_DEFER) {
ret = -EPROBE_DEFER;
goto put_hcd;
}
xhci = hcd_to_xhci(hcd);
match = of_match_node(usb_xhci_of_match, node);
if (match) {
const struct xhci_plat_priv *priv_match = match->data;
struct xhci_plat_priv *priv = hcd_to_xhci_priv(hcd);
if (priv_match)
*priv = *priv_match;
}
device_wakeup_enable(hcd->self.controller);
xhci->clk = clk;
xhci->main_hcd = hcd;
xhci->shared_hcd = usb_create_shared_hcd(driver, &pdev->dev,
dev_name(&pdev->dev), hcd);
if (!xhci->shared_hcd) {
ret = -ENOMEM;
goto disable_clk;
}
if ((node && of_property_read_bool(node, "usb3-lpm-capable")) ||
(pdata && pdata->usb3_lpm_capable))
xhci->quirks |= XHCI_LPM_SUPPORT;
if (HCC_MAX_PSA(xhci->hcc_params) >= 4)
xhci->shared_hcd->can_do_streams = 1;
hcd->usb_phy = devm_usb_get_phy_by_phandle(&pdev->dev, "usb-phy", 0);
if (IS_ERR(hcd->usb_phy)) {
ret = PTR_ERR(hcd->usb_phy);
if (ret == -EPROBE_DEFER)
goto put_usb3_hcd;
hcd->usb_phy = NULL;
} else {
ret = usb_phy_init(hcd->usb_phy);
if (ret)
goto put_usb3_hcd;
}
ret = usb_add_hcd(hcd, irq, IRQF_SHARED);
if (ret)
goto disable_usb_phy;
ret = usb_add_hcd(xhci->shared_hcd, irq, IRQF_SHARED);
if (ret)
goto dealloc_usb2_hcd;
return 0;
dealloc_usb2_hcd:
usb_remove_hcd(hcd);
disable_usb_phy:
usb_phy_shutdown(hcd->usb_phy);
put_usb3_hcd:
usb_put_hcd(xhci->shared_hcd);
disable_clk:
if (!IS_ERR(clk))
clk_disable_unprepare(clk);
put_hcd:
usb_put_hcd(hcd);
return ret;
}
static int xhci_plat_remove(struct platform_device *dev)
{
struct usb_hcd *hcd = platform_get_drvdata(dev);
struct xhci_hcd *xhci = hcd_to_xhci(hcd);
struct clk *clk = xhci->clk;
usb_remove_hcd(xhci->shared_hcd);
usb_phy_shutdown(hcd->usb_phy);
usb_remove_hcd(hcd);
usb_put_hcd(xhci->shared_hcd);
if (!IS_ERR(clk))
clk_disable_unprepare(clk);
usb_put_hcd(hcd);
return 0;
}
static int xhci_plat_suspend(struct device *dev)
{
struct usb_hcd *hcd = dev_get_drvdata(dev);
struct xhci_hcd *xhci = hcd_to_xhci(hcd);
return xhci_suspend(xhci, device_may_wakeup(dev));
}
static int xhci_plat_resume(struct device *dev)
{
struct usb_hcd *hcd = dev_get_drvdata(dev);
struct xhci_hcd *xhci = hcd_to_xhci(hcd);
return xhci_resume(xhci, 0);
}
static int __init xhci_plat_init(void)
{
xhci_init_driver(&xhci_plat_hc_driver, &xhci_plat_overrides);
return platform_driver_register(&usb_xhci_driver);
}
static void __exit xhci_plat_exit(void)
{
platform_driver_unregister(&usb_xhci_driver);
}
