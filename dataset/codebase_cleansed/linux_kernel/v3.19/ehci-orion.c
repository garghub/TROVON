static void orion_usb_phy_v1_setup(struct usb_hcd *hcd)
{
wrl(USB_CAUSE, 0);
wrl(USB_MASK, 0);
wrl(USB_CMD, rdl(USB_CMD) | 0x2);
while (rdl(USB_CMD) & 0x2);
wrl(USB_IPG, (rdl(USB_IPG) & ~0x7f00) | 0xc00);
wrl(USB_PHY_PWR_CTRL, (rdl(USB_PHY_PWR_CTRL) & ~0xc0)| 0x40);
wrl(USB_PHY_TX_CTRL, (rdl(USB_PHY_TX_CTRL) & ~0x78) | 0x202040);
wrl(USB_PHY_RX_CTRL, (rdl(USB_PHY_RX_CTRL) & ~0xc2003f0) | 0xc0000010);
wrl(USB_PHY_IVREF_CTRL, (rdl(USB_PHY_IVREF_CTRL) & ~0x80003 ) | 0x32);
wrl(USB_PHY_TST_GRP_CTRL, rdl(USB_PHY_TST_GRP_CTRL) & ~0x8000);
wrl(USB_CMD, rdl(USB_CMD) & ~0x1);
wrl(USB_CMD, rdl(USB_CMD) | 0x2);
while (rdl(USB_CMD) & 0x2);
wrl(USB_MODE, 0x13);
}
static void
ehci_orion_conf_mbus_windows(struct usb_hcd *hcd,
const struct mbus_dram_target_info *dram)
{
int i;
for (i = 0; i < 4; i++) {
wrl(USB_WINDOW_CTRL(i), 0);
wrl(USB_WINDOW_BASE(i), 0);
}
for (i = 0; i < dram->num_cs; i++) {
const struct mbus_dram_window *cs = dram->cs + i;
wrl(USB_WINDOW_CTRL(i), ((cs->size - 1) & 0xffff0000) |
(cs->mbus_attr << 8) |
(dram->mbus_dram_target_id << 4) | 1);
wrl(USB_WINDOW_BASE(i), cs->base);
}
}
static int ehci_orion_drv_probe(struct platform_device *pdev)
{
struct orion_ehci_data *pd = dev_get_platdata(&pdev->dev);
const struct mbus_dram_target_info *dram;
struct resource *res;
struct usb_hcd *hcd;
struct ehci_hcd *ehci;
void __iomem *regs;
int irq, err;
enum orion_ehci_phy_ver phy_version;
struct orion_ehci_hcd *priv;
if (usb_disabled())
return -ENODEV;
pr_debug("Initializing Orion-SoC USB Host Controller\n");
irq = platform_get_irq(pdev, 0);
if (irq <= 0) {
dev_err(&pdev->dev,
"Found HC with no IRQ. Check %s setup!\n",
dev_name(&pdev->dev));
err = -ENODEV;
goto err;
}
err = dma_coerce_mask_and_coherent(&pdev->dev, DMA_BIT_MASK(32));
if (err)
goto err;
res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
regs = devm_ioremap_resource(&pdev->dev, res);
if (IS_ERR(regs)) {
err = PTR_ERR(regs);
goto err;
}
hcd = usb_create_hcd(&ehci_orion_hc_driver,
&pdev->dev, dev_name(&pdev->dev));
if (!hcd) {
err = -ENOMEM;
goto err;
}
hcd->rsrc_start = res->start;
hcd->rsrc_len = resource_size(res);
hcd->regs = regs;
ehci = hcd_to_ehci(hcd);
ehci->caps = hcd->regs + 0x100;
hcd->has_tt = 1;
priv = hcd_to_orion_priv(hcd);
priv->clk = devm_clk_get(&pdev->dev, NULL);
if (!IS_ERR(priv->clk))
clk_prepare_enable(priv->clk);
priv->phy = devm_phy_optional_get(&pdev->dev, "usb");
if (IS_ERR(priv->phy)) {
err = PTR_ERR(priv->phy);
goto err_phy_get;
} else {
err = phy_init(priv->phy);
if (err)
goto err_phy_init;
err = phy_power_on(priv->phy);
if (err)
goto err_phy_power_on;
}
dram = mv_mbus_dram_info();
if (dram)
ehci_orion_conf_mbus_windows(hcd, dram);
if (pdev->dev.of_node)
phy_version = EHCI_PHY_NA;
else
phy_version = pd->phy_version;
switch (phy_version) {
case EHCI_PHY_NA:
break;
case EHCI_PHY_ORION:
orion_usb_phy_v1_setup(hcd);
break;
case EHCI_PHY_DD:
case EHCI_PHY_KW:
default:
dev_warn(&pdev->dev, "USB phy version isn't supported.\n");
}
err = usb_add_hcd(hcd, irq, IRQF_SHARED);
if (err)
goto err_add_hcd;
device_wakeup_enable(hcd->self.controller);
return 0;
err_add_hcd:
if (!IS_ERR(priv->phy))
phy_power_off(priv->phy);
err_phy_power_on:
if (!IS_ERR(priv->phy))
phy_exit(priv->phy);
err_phy_init:
err_phy_get:
if (!IS_ERR(priv->clk))
clk_disable_unprepare(priv->clk);
usb_put_hcd(hcd);
err:
dev_err(&pdev->dev, "init %s fail, %d\n",
dev_name(&pdev->dev), err);
return err;
}
static int ehci_orion_drv_remove(struct platform_device *pdev)
{
struct usb_hcd *hcd = platform_get_drvdata(pdev);
struct orion_ehci_hcd *priv = hcd_to_orion_priv(hcd);
usb_remove_hcd(hcd);
if (!IS_ERR(priv->phy)) {
phy_power_off(priv->phy);
phy_exit(priv->phy);
}
if (!IS_ERR(priv->clk))
clk_disable_unprepare(priv->clk);
usb_put_hcd(hcd);
return 0;
}
static int __init ehci_orion_init(void)
{
if (usb_disabled())
return -ENODEV;
pr_info("%s: " DRIVER_DESC "\n", hcd_name);
ehci_init_driver(&ehci_orion_hc_driver, &orion_overrides);
return platform_driver_register(&ehci_orion_driver);
}
static void __exit ehci_orion_cleanup(void)
{
platform_driver_unregister(&ehci_orion_driver);
}
