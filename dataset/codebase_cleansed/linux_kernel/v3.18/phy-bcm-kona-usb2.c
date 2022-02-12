static void bcm_kona_usb_phy_power(struct bcm_kona_usb *phy, int on)
{
u32 val;
val = readl(phy->regs + OTGCTL);
if (on) {
val &= ~(OTGCTL_OTGSTAT2 | OTGCTL_OTGSTAT1 |
OTGCTL_UTMI_LINE_STATE1 | OTGCTL_UTMI_LINE_STATE0);
val |= OTGCTL_PRST_N_SW | OTGCTL_HRESET_N;
} else {
val &= ~(OTGCTL_PRST_N_SW | OTGCTL_HRESET_N);
}
writel(val, phy->regs + OTGCTL);
}
static int bcm_kona_usb_phy_init(struct phy *gphy)
{
struct bcm_kona_usb *phy = phy_get_drvdata(gphy);
u32 val;
val = readl(phy->regs + P1CTL);
val &= ~P1CTL_NON_DRIVING;
val |= P1CTL_SOFT_RESET;
writel(val, phy->regs + P1CTL);
writel(val & ~P1CTL_SOFT_RESET, phy->regs + P1CTL);
mdelay(2);
writel(val | P1CTL_SOFT_RESET, phy->regs + P1CTL);
return 0;
}
static int bcm_kona_usb_phy_power_on(struct phy *gphy)
{
struct bcm_kona_usb *phy = phy_get_drvdata(gphy);
bcm_kona_usb_phy_power(phy, 1);
return 0;
}
static int bcm_kona_usb_phy_power_off(struct phy *gphy)
{
struct bcm_kona_usb *phy = phy_get_drvdata(gphy);
bcm_kona_usb_phy_power(phy, 0);
return 0;
}
static int bcm_kona_usb2_probe(struct platform_device *pdev)
{
struct device *dev = &pdev->dev;
struct bcm_kona_usb *phy;
struct resource *res;
struct phy *gphy;
struct phy_provider *phy_provider;
phy = devm_kzalloc(dev, sizeof(*phy), GFP_KERNEL);
if (!phy)
return -ENOMEM;
res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
phy->regs = devm_ioremap_resource(&pdev->dev, res);
if (IS_ERR(phy->regs))
return PTR_ERR(phy->regs);
platform_set_drvdata(pdev, phy);
gphy = devm_phy_create(dev, NULL, &ops, NULL);
if (IS_ERR(gphy))
return PTR_ERR(gphy);
phy_set_bus_width(gphy, 8);
phy_set_drvdata(gphy, phy);
phy_provider = devm_of_phy_provider_register(dev,
of_phy_simple_xlate);
return PTR_ERR_OR_ZERO(phy_provider);
}
