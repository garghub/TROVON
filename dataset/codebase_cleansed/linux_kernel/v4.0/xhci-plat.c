static void xhci_plat_quirks(struct device *dev, struct xhci_hcd *xhci)
{
xhci->quirks |= XHCI_PLAT;
}
static int xhci_plat_setup(struct usb_hcd *hcd)
{
struct device_node *of_node = hcd->self.controller->of_node;
int ret;
if (of_device_is_compatible(of_node, "renesas,xhci-r8a7790") ||
of_device_is_compatible(of_node, "renesas,xhci-r8a7791")) {
ret = xhci_rcar_init_quirk(hcd);
if (ret)
return ret;
}
return xhci_gen_setup(hcd, xhci_plat_quirks);
}
static int xhci_plat_start(struct usb_hcd *hcd)
{
struct device_node *of_node = hcd->self.controller->of_node;
if (of_device_is_compatible(of_node, "renesas,xhci-r8a7790") ||
of_device_is_compatible(of_node, "renesas,xhci-r8a7791"))
xhci_rcar_start(hcd);
return xhci_run(hcd);
}
static int xhci_plat_probe(struct platform_device *pdev)
{
struct device_node *node = pdev->dev.of_node;
struct usb_xhci_pdata *pdata = dev_get_platdata(&pdev->dev);
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
ret = dma_set_coherent_mask(&pdev->dev, DMA_BIT_MASK(32));
if (ret)
return ret;
if (!pdev->dev.dma_mask)
pdev->dev.dma_mask = &pdev->dev.coherent_dma_mask;
else
dma_set_mask(&pdev->dev, DMA_BIT_MASK(32));
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
}
if (of_device_is_compatible(pdev->dev.of_node,
"marvell,armada-375-xhci") ||
of_device_is_compatible(pdev->dev.of_node,
"marvell,armada-380-xhci")) {
ret = xhci_mvebu_mbus_init_quirk(pdev);
if (ret)
goto disable_clk;
}
ret = usb_add_hcd(hcd, irq, IRQF_SHARED);
if (ret)
goto disable_clk;
device_wakeup_enable(hcd->self.controller);
hcd = platform_get_drvdata(pdev);
xhci = hcd_to_xhci(hcd);
xhci->clk = clk;
xhci->shared_hcd = usb_create_shared_hcd(driver, &pdev->dev,
dev_name(&pdev->dev), hcd);
if (!xhci->shared_hcd) {
ret = -ENOMEM;
goto dealloc_usb2_hcd;
}
if ((node && of_property_read_bool(node, "usb3-lpm-capable")) ||
(pdata && pdata->usb3_lpm_capable))
xhci->quirks |= XHCI_LPM_SUPPORT;
*((struct xhci_hcd **) xhci->shared_hcd->hcd_priv) = xhci;
if (HCC_MAX_PSA(xhci->hcc_params) >= 4)
xhci->shared_hcd->can_do_streams = 1;
ret = usb_add_hcd(xhci->shared_hcd, irq, IRQF_SHARED);
if (ret)
goto put_usb3_hcd;
return 0;
put_usb3_hcd:
usb_put_hcd(xhci->shared_hcd);
dealloc_usb2_hcd:
usb_remove_hcd(hcd);
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
usb_put_hcd(xhci->shared_hcd);
usb_remove_hcd(hcd);
if (!IS_ERR(clk))
clk_disable_unprepare(clk);
usb_put_hcd(hcd);
kfree(xhci);
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
xhci_init_driver(&xhci_plat_hc_driver, xhci_plat_setup);
xhci_plat_hc_driver.start = xhci_plat_start;
return platform_driver_register(&usb_xhci_driver);
}
static void __exit xhci_plat_exit(void)
{
platform_driver_unregister(&usb_xhci_driver);
}
