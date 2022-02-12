static inline void ehci_write(void __iomem *base, u32 reg, u32 val)
{
__raw_writel(val, base + reg);
}
static inline u32 ehci_read(void __iomem *base, u32 reg)
{
return __raw_readl(base + reg);
}
static int ehci_hcd_omap_probe(struct platform_device *pdev)
{
struct device *dev = &pdev->dev;
struct usbhs_omap_platform_data *pdata = dev_get_platdata(dev);
struct resource *res;
struct usb_hcd *hcd;
void __iomem *regs;
int ret;
int irq;
int i;
struct omap_hcd *omap;
if (usb_disabled())
return -ENODEV;
if (!dev->parent) {
dev_err(dev, "Missing parent device\n");
return -ENODEV;
}
if (dev->of_node) {
pdata = dev_get_platdata(dev->parent);
dev->platform_data = pdata;
}
if (!pdata) {
dev_err(dev, "Missing platform data\n");
return -ENODEV;
}
irq = platform_get_irq(pdev, 0);
if (irq < 0) {
dev_err(dev, "EHCI irq failed\n");
return -ENODEV;
}
res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
regs = devm_ioremap_resource(dev, res);
if (IS_ERR(regs))
return PTR_ERR(regs);
ret = dma_coerce_mask_and_coherent(dev, DMA_BIT_MASK(32));
if (ret)
return ret;
ret = -ENODEV;
hcd = usb_create_hcd(&ehci_omap_hc_driver, dev,
dev_name(dev));
if (!hcd) {
dev_err(dev, "Failed to create HCD\n");
return -ENOMEM;
}
hcd->rsrc_start = res->start;
hcd->rsrc_len = resource_size(res);
hcd->regs = regs;
hcd_to_ehci(hcd)->caps = regs;
omap = (struct omap_hcd *)hcd_to_ehci(hcd)->priv;
omap->nports = pdata->nports;
platform_set_drvdata(pdev, hcd);
for (i = 0 ; i < omap->nports ; i++) {
struct usb_phy *phy;
if (dev->of_node)
phy = devm_usb_get_phy_by_phandle(dev, "phys", i);
else
phy = devm_usb_get_phy_dev(dev, i);
if (IS_ERR(phy)) {
if (pdata->port_mode[i] != OMAP_EHCI_PORT_MODE_PHY)
continue;
ret = PTR_ERR(phy);
dev_err(dev, "Can't get PHY device for port %d: %d\n",
i, ret);
goto err_phy;
}
omap->phy[i] = phy;
if (pdata->port_mode[i] == OMAP_EHCI_PORT_MODE_PHY) {
usb_phy_init(omap->phy[i]);
usb_phy_set_suspend(omap->phy[i], 0);
}
}
pm_runtime_enable(dev);
pm_runtime_get_sync(dev);
ehci_write(regs, EHCI_INSNREG04,
EHCI_INSNREG04_DISABLE_UNSUSPEND);
ret = usb_add_hcd(hcd, irq, IRQF_SHARED);
if (ret) {
dev_err(dev, "failed to add hcd with err %d\n", ret);
goto err_pm_runtime;
}
device_wakeup_enable(hcd->self.controller);
for (i = 0; i < omap->nports; i++) {
if (!omap->phy[i] ||
pdata->port_mode[i] == OMAP_EHCI_PORT_MODE_PHY)
continue;
usb_phy_init(omap->phy[i]);
usb_phy_set_suspend(omap->phy[i], 0);
}
return 0;
err_pm_runtime:
pm_runtime_put_sync(dev);
err_phy:
for (i = 0; i < omap->nports; i++) {
if (omap->phy[i])
usb_phy_shutdown(omap->phy[i]);
}
usb_put_hcd(hcd);
return ret;
}
static int ehci_hcd_omap_remove(struct platform_device *pdev)
{
struct device *dev = &pdev->dev;
struct usb_hcd *hcd = dev_get_drvdata(dev);
struct omap_hcd *omap = (struct omap_hcd *)hcd_to_ehci(hcd)->priv;
int i;
usb_remove_hcd(hcd);
for (i = 0; i < omap->nports; i++) {
if (omap->phy[i])
usb_phy_shutdown(omap->phy[i]);
}
usb_put_hcd(hcd);
pm_runtime_put_sync(dev);
pm_runtime_disable(dev);
return 0;
}
static int __init ehci_omap_init(void)
{
if (usb_disabled())
return -ENODEV;
pr_info("%s: " DRIVER_DESC "\n", hcd_name);
ehci_init_driver(&ehci_omap_hc_driver, &ehci_omap_overrides);
return platform_driver_register(&ehci_hcd_omap_driver);
}
static void __exit ehci_omap_cleanup(void)
{
platform_driver_unregister(&ehci_hcd_omap_driver);
}
