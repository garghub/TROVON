static int usbhs_rcar2_hardware_init(struct platform_device *pdev)
{
struct usbhs_priv *priv = usbhs_pdev_to_priv(pdev);
struct usb_phy *phy;
phy = usb_get_phy_dev(&pdev->dev, 0);
if (IS_ERR(phy))
return PTR_ERR(phy);
priv->phy = phy;
return 0;
}
static int usbhs_rcar2_hardware_exit(struct platform_device *pdev)
{
struct usbhs_priv *priv = usbhs_pdev_to_priv(pdev);
if (!priv->phy)
return 0;
usb_put_phy(priv->phy);
priv->phy = NULL;
return 0;
}
static int usbhs_rcar2_power_ctrl(struct platform_device *pdev,
void __iomem *base, int enable)
{
struct usbhs_priv *priv = usbhs_pdev_to_priv(pdev);
if (!priv->phy)
return -ENODEV;
if (enable) {
int retval = usb_phy_init(priv->phy);
if (!retval)
retval = usb_phy_set_suspend(priv->phy, 0);
return retval;
}
usb_phy_set_suspend(priv->phy, 1);
usb_phy_shutdown(priv->phy);
return 0;
}
static int usbhs_rcar2_get_id(struct platform_device *pdev)
{
return USBHS_GADGET;
}
