static int __rcar_gen2_usbhs_phy_enable(void __iomem *base)
{
u32 val;
int i;
val = ioread32(base + USBHS_UGCTRL_REG);
val &= ~USBHS_UGCTRL_PLLRESET;
iowrite32(val, base + USBHS_UGCTRL_REG);
val = ioread16(base + USBHS_LPSTS_REG);
val |= USBHS_LPSTS_SUSPM;
iowrite16(val, base + USBHS_LPSTS_REG);
for (i = 0; i < 20; i++) {
val = ioread32(base + USBHS_UGSTS_REG);
if ((val & USBHS_UGSTS_LOCK) == USBHS_UGSTS_LOCK) {
val = ioread32(base + USBHS_UGCTRL_REG);
val |= USBHS_UGCTRL_CONNECT;
iowrite32(val, base + USBHS_UGCTRL_REG);
return 0;
}
udelay(1);
}
return -ETIMEDOUT;
}
static int __rcar_gen2_usbhs_phy_disable(void __iomem *base)
{
u32 val;
val = ioread32(base + USBHS_UGCTRL_REG);
val &= ~USBHS_UGCTRL_CONNECT;
iowrite32(val, base + USBHS_UGCTRL_REG);
val = ioread16(base + USBHS_LPSTS_REG);
val &= ~USBHS_LPSTS_SUSPM;
iowrite16(val, base + USBHS_LPSTS_REG);
val = ioread32(base + USBHS_UGCTRL_REG);
val |= USBHS_UGCTRL_PLLRESET;
iowrite32(val, base + USBHS_UGCTRL_REG);
return 0;
}
static void __rcar_gen2_usb_phy_init(struct rcar_gen2_usb_phy_priv *priv)
{
u32 val;
clk_prepare_enable(priv->clk);
val = ioread32(priv->base + USBHS_UGCTRL2_REG);
val &= ~(USBHS_UGCTRL2_USB0_HS | USBHS_UGCTRL2_USB2_SS);
val |= priv->ugctrl2;
iowrite32(val, priv->base + USBHS_UGCTRL2_REG);
}
static void __rcar_gen2_usb_phy_shutdown(struct rcar_gen2_usb_phy_priv *priv)
{
__rcar_gen2_usbhs_phy_disable(priv->base);
clk_disable_unprepare(priv->clk);
}
static int rcar_gen2_usb_phy_set_suspend(struct usb_phy *phy, int suspend)
{
struct rcar_gen2_usb_phy_priv *priv = usb_phy_to_priv(phy);
unsigned long flags;
int retval;
spin_lock_irqsave(&priv->lock, flags);
retval = suspend ? __rcar_gen2_usbhs_phy_disable(priv->base) :
__rcar_gen2_usbhs_phy_enable(priv->base);
spin_unlock_irqrestore(&priv->lock, flags);
return retval;
}
static int rcar_gen2_usb_phy_init(struct usb_phy *phy)
{
struct rcar_gen2_usb_phy_priv *priv = usb_phy_to_priv(phy);
unsigned long flags;
spin_lock_irqsave(&priv->lock, flags);
if (!priv->usecount++)
__rcar_gen2_usb_phy_init(priv);
spin_unlock_irqrestore(&priv->lock, flags);
return 0;
}
static void rcar_gen2_usb_phy_shutdown(struct usb_phy *phy)
{
struct rcar_gen2_usb_phy_priv *priv = usb_phy_to_priv(phy);
unsigned long flags;
spin_lock_irqsave(&priv->lock, flags);
if (!priv->usecount) {
dev_warn(phy->dev, "Trying to disable phy with 0 usecount\n");
goto out;
}
if (!--priv->usecount)
__rcar_gen2_usb_phy_shutdown(priv);
out:
spin_unlock_irqrestore(&priv->lock, flags);
}
static int rcar_gen2_usb_phy_probe(struct platform_device *pdev)
{
struct device *dev = &pdev->dev;
struct rcar_gen2_phy_platform_data *pdata;
struct rcar_gen2_usb_phy_priv *priv;
struct resource *res;
void __iomem *base;
struct clk *clk;
int retval;
pdata = dev_get_platdata(&pdev->dev);
if (!pdata) {
dev_err(dev, "No platform data\n");
return -EINVAL;
}
clk = devm_clk_get(&pdev->dev, "usbhs");
if (IS_ERR(clk)) {
dev_err(&pdev->dev, "Can't get the clock\n");
return PTR_ERR(clk);
}
res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
base = devm_ioremap_resource(dev, res);
if (IS_ERR(base))
return PTR_ERR(base);
priv = devm_kzalloc(dev, sizeof(*priv), GFP_KERNEL);
if (!priv) {
dev_err(dev, "Memory allocation failed\n");
return -ENOMEM;
}
spin_lock_init(&priv->lock);
priv->clk = clk;
priv->base = base;
priv->ugctrl2 = pdata->chan0_pci ?
USBHS_UGCTRL2_USB0_PCI : USBHS_UGCTRL2_USB0_HS;
priv->ugctrl2 |= pdata->chan2_pci ?
USBHS_UGCTRL2_USB2_PCI : USBHS_UGCTRL2_USB2_SS;
priv->phy.dev = dev;
priv->phy.label = dev_name(dev);
priv->phy.init = rcar_gen2_usb_phy_init;
priv->phy.shutdown = rcar_gen2_usb_phy_shutdown;
priv->phy.set_suspend = rcar_gen2_usb_phy_set_suspend;
retval = usb_add_phy(&priv->phy, USB_PHY_TYPE_USB2);
if (retval < 0) {
dev_err(dev, "Failed to add USB phy\n");
return retval;
}
platform_set_drvdata(pdev, priv);
return retval;
}
static int rcar_gen2_usb_phy_remove(struct platform_device *pdev)
{
struct rcar_gen2_usb_phy_priv *priv = platform_get_drvdata(pdev);
usb_remove_phy(&priv->phy);
return 0;
}
