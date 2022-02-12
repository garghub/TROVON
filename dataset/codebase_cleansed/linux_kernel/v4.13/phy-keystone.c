static inline u32 keystone_usbphy_readl(void __iomem *base, u32 offset)
{
return readl(base + offset);
}
static inline void keystone_usbphy_writel(void __iomem *base,
u32 offset, u32 value)
{
writel(value, base + offset);
}
static int keystone_usbphy_init(struct usb_phy *phy)
{
struct keystone_usbphy *k_phy = dev_get_drvdata(phy->dev);
u32 val;
val = keystone_usbphy_readl(k_phy->phy_ctrl, USB_PHY_CTL_CLOCK);
keystone_usbphy_writel(k_phy->phy_ctrl, USB_PHY_CTL_CLOCK,
val | PHY_REF_SSP_EN);
return 0;
}
static void keystone_usbphy_shutdown(struct usb_phy *phy)
{
struct keystone_usbphy *k_phy = dev_get_drvdata(phy->dev);
u32 val;
val = keystone_usbphy_readl(k_phy->phy_ctrl, USB_PHY_CTL_CLOCK);
keystone_usbphy_writel(k_phy->phy_ctrl, USB_PHY_CTL_CLOCK,
val &= ~PHY_REF_SSP_EN);
}
static int keystone_usbphy_probe(struct platform_device *pdev)
{
struct device *dev = &pdev->dev;
struct keystone_usbphy *k_phy;
struct resource *res;
int ret;
k_phy = devm_kzalloc(dev, sizeof(*k_phy), GFP_KERNEL);
if (!k_phy)
return -ENOMEM;
res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
k_phy->phy_ctrl = devm_ioremap_resource(dev, res);
if (IS_ERR(k_phy->phy_ctrl))
return PTR_ERR(k_phy->phy_ctrl);
ret = usb_phy_gen_create_phy(dev, &k_phy->usb_phy_gen, NULL);
if (ret)
return ret;
k_phy->usb_phy_gen.phy.init = keystone_usbphy_init;
k_phy->usb_phy_gen.phy.shutdown = keystone_usbphy_shutdown;
platform_set_drvdata(pdev, k_phy);
return usb_add_phy_dev(&k_phy->usb_phy_gen.phy);
}
static int keystone_usbphy_remove(struct platform_device *pdev)
{
struct keystone_usbphy *k_phy = platform_get_drvdata(pdev);
usb_remove_phy(&k_phy->usb_phy_gen.phy);
return 0;
}
