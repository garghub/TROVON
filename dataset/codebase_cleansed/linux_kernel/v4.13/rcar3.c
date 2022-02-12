static void usbhs_write32(struct usbhs_priv *priv, u32 reg, u32 data)
{
iowrite32(data, priv->base + reg);
}
static int usbhs_rcar3_power_ctrl(struct platform_device *pdev,
void __iomem *base, int enable)
{
struct usbhs_priv *priv = usbhs_pdev_to_priv(pdev);
usbhs_write32(priv, UGCTRL2, UGCTRL2_RESERVED_3 | UGCTRL2_USB0SEL_OTG |
UGCTRL2_VBUSSEL);
if (enable) {
usbhs_bset(priv, LPSTS, LPSTS_SUSPM, LPSTS_SUSPM);
udelay(45);
} else {
usbhs_bset(priv, LPSTS, LPSTS_SUSPM, 0);
}
return 0;
}
static int usbhs_rcar3_get_id(struct platform_device *pdev)
{
return USBHS_GADGET;
}
