static int rcar_usb_phy_init(struct usb_phy *phy)
{
struct rcar_usb_phy_priv *priv = usb_phy_to_priv(phy);
struct device *dev = phy->dev;
struct rcar_phy_platform_data *pdata = dev_get_platdata(dev);
void __iomem *reg0 = priv->reg0;
void __iomem *reg1 = priv->reg1;
static const u8 ovcn_act[] = { OVC0_ACT, OVC1_ACT, OVC2_ACT };
int i;
u32 val;
unsigned long flags;
spin_lock_irqsave(&priv->lock, flags);
if (priv->counter++ == 0) {
iowrite32(PHY_ENB, (reg0 + USBPCTRL1));
iowrite32(PHY_ENB | PLL_ENB, (reg0 + USBPCTRL1));
if (reg1) {
u32 hsqctl1 = pdata->ferrite_bead ? 0x41 : 0;
u32 hsqctl2 = pdata->ferrite_bead ? 0x0d : 7;
iowrite32(hsqctl1, reg1 + HSQCTL1);
iowrite32(hsqctl2, reg1 + HSQCTL2);
}
for (i = 0; i < 1024; i++) {
udelay(10);
val = ioread32(reg0 + USBST);
if (val == (ST_ACT | ST_PLL))
break;
}
if (val != (ST_ACT | ST_PLL)) {
dev_err(dev, "USB phy not ready\n");
goto phy_init_end;
}
iowrite32(PHY_ENB | PLL_ENB | PHY_RST, (reg0 + USBPCTRL1));
val = 0;
if (pdata->port1_func)
val |= PORT1;
if (pdata->penc1)
val |= PENC;
for (i = 0; i < 3; i++) {
if (pdata->ovc_pin[i].select_3_3v)
val |= OVC0 << i;
if (pdata->ovc_pin[i].active_high)
val |= ovcn_act[i];
}
iowrite32(val, (reg0 + USBPCTRL0));
iowrite32(0x00000000, (reg0 + USBEH0));
iowrite32(0x00000000, (reg0 + USBOH0));
}
phy_init_end:
spin_unlock_irqrestore(&priv->lock, flags);
return 0;
}
static void rcar_usb_phy_shutdown(struct usb_phy *phy)
{
struct rcar_usb_phy_priv *priv = usb_phy_to_priv(phy);
void __iomem *reg0 = priv->reg0;
unsigned long flags;
spin_lock_irqsave(&priv->lock, flags);
if (priv->counter-- == 1)
iowrite32(0x00000000, (reg0 + USBPCTRL1));
spin_unlock_irqrestore(&priv->lock, flags);
}
static int rcar_usb_phy_probe(struct platform_device *pdev)
{
struct rcar_usb_phy_priv *priv;
struct resource *res0, *res1;
struct device *dev = &pdev->dev;
void __iomem *reg0, *reg1 = NULL;
int ret;
if (!dev_get_platdata(&pdev->dev)) {
dev_err(dev, "No platform data\n");
return -EINVAL;
}
res0 = platform_get_resource(pdev, IORESOURCE_MEM, 0);
reg0 = devm_ioremap_resource(dev, res0);
if (IS_ERR(reg0))
return PTR_ERR(reg0);
res1 = platform_get_resource(pdev, IORESOURCE_MEM, 1);
reg1 = devm_ioremap_resource(dev, res1);
if (IS_ERR(reg1))
return PTR_ERR(reg1);
priv = devm_kzalloc(dev, sizeof(*priv), GFP_KERNEL);
if (!priv)
return -ENOMEM;
priv->reg0 = reg0;
priv->reg1 = reg1;
priv->counter = 0;
priv->phy.dev = dev;
priv->phy.label = dev_name(dev);
priv->phy.init = rcar_usb_phy_init;
priv->phy.shutdown = rcar_usb_phy_shutdown;
spin_lock_init(&priv->lock);
ret = usb_add_phy(&priv->phy, USB_PHY_TYPE_USB2);
if (ret < 0) {
dev_err(dev, "usb phy addition error\n");
return ret;
}
platform_set_drvdata(pdev, priv);
return ret;
}
static int rcar_usb_phy_remove(struct platform_device *pdev)
{
struct rcar_usb_phy_priv *priv = platform_get_drvdata(pdev);
usb_remove_phy(&priv->phy);
return 0;
}
