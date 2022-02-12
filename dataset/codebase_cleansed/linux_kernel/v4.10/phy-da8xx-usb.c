static int da8xx_usb11_phy_power_on(struct phy *phy)
{
struct da8xx_usb_phy *d_phy = phy_get_drvdata(phy);
int ret;
ret = clk_prepare_enable(d_phy->usb11_clk);
if (ret)
return ret;
regmap_write_bits(d_phy->regmap, CFGCHIP(2), CFGCHIP2_USB1SUSPENDM,
CFGCHIP2_USB1SUSPENDM);
return 0;
}
static int da8xx_usb11_phy_power_off(struct phy *phy)
{
struct da8xx_usb_phy *d_phy = phy_get_drvdata(phy);
regmap_write_bits(d_phy->regmap, CFGCHIP(2), CFGCHIP2_USB1SUSPENDM, 0);
clk_disable_unprepare(d_phy->usb11_clk);
return 0;
}
static int da8xx_usb20_phy_power_on(struct phy *phy)
{
struct da8xx_usb_phy *d_phy = phy_get_drvdata(phy);
int ret;
ret = clk_prepare_enable(d_phy->usb20_clk);
if (ret)
return ret;
regmap_write_bits(d_phy->regmap, CFGCHIP(2), CFGCHIP2_OTGPWRDN, 0);
return 0;
}
static int da8xx_usb20_phy_power_off(struct phy *phy)
{
struct da8xx_usb_phy *d_phy = phy_get_drvdata(phy);
regmap_write_bits(d_phy->regmap, CFGCHIP(2), CFGCHIP2_OTGPWRDN,
CFGCHIP2_OTGPWRDN);
clk_disable_unprepare(d_phy->usb20_clk);
return 0;
}
static int da8xx_usb20_phy_set_mode(struct phy *phy, enum phy_mode mode)
{
struct da8xx_usb_phy *d_phy = phy_get_drvdata(phy);
u32 val;
switch (mode) {
case PHY_MODE_USB_HOST:
val = CFGCHIP2_OTGMODE_FORCE_HOST;
break;
case PHY_MODE_USB_DEVICE:
val = CFGCHIP2_OTGMODE_FORCE_DEVICE;
break;
case PHY_MODE_USB_OTG:
val = CFGCHIP2_OTGMODE_NO_OVERRIDE;
break;
default:
return -EINVAL;
}
regmap_write_bits(d_phy->regmap, CFGCHIP(2), CFGCHIP2_OTGMODE_MASK,
val);
return 0;
}
static struct phy *da8xx_usb_phy_of_xlate(struct device *dev,
struct of_phandle_args *args)
{
struct da8xx_usb_phy *d_phy = dev_get_drvdata(dev);
if (!d_phy)
return ERR_PTR(-ENODEV);
switch (args->args[0]) {
case 0:
return d_phy->usb20_phy;
case 1:
return d_phy->usb11_phy;
default:
return ERR_PTR(-EINVAL);
}
}
static int da8xx_usb_phy_probe(struct platform_device *pdev)
{
struct device *dev = &pdev->dev;
struct device_node *node = dev->of_node;
struct da8xx_usb_phy *d_phy;
d_phy = devm_kzalloc(dev, sizeof(*d_phy), GFP_KERNEL);
if (!d_phy)
return -ENOMEM;
if (node)
d_phy->regmap = syscon_regmap_lookup_by_compatible(
"ti,da830-cfgchip");
else
d_phy->regmap = syscon_regmap_lookup_by_pdevname("syscon");
if (IS_ERR(d_phy->regmap)) {
dev_err(dev, "Failed to get syscon\n");
return PTR_ERR(d_phy->regmap);
}
d_phy->usb11_clk = devm_clk_get(dev, "usb11_phy");
if (IS_ERR(d_phy->usb11_clk)) {
dev_err(dev, "Failed to get usb11_phy clock\n");
return PTR_ERR(d_phy->usb11_clk);
}
d_phy->usb20_clk = devm_clk_get(dev, "usb20_phy");
if (IS_ERR(d_phy->usb20_clk)) {
dev_err(dev, "Failed to get usb20_phy clock\n");
return PTR_ERR(d_phy->usb20_clk);
}
d_phy->usb11_phy = devm_phy_create(dev, node, &da8xx_usb11_phy_ops);
if (IS_ERR(d_phy->usb11_phy)) {
dev_err(dev, "Failed to create usb11 phy\n");
return PTR_ERR(d_phy->usb11_phy);
}
d_phy->usb20_phy = devm_phy_create(dev, node, &da8xx_usb20_phy_ops);
if (IS_ERR(d_phy->usb20_phy)) {
dev_err(dev, "Failed to create usb20 phy\n");
return PTR_ERR(d_phy->usb20_phy);
}
platform_set_drvdata(pdev, d_phy);
phy_set_drvdata(d_phy->usb11_phy, d_phy);
phy_set_drvdata(d_phy->usb20_phy, d_phy);
if (node) {
d_phy->phy_provider = devm_of_phy_provider_register(dev,
da8xx_usb_phy_of_xlate);
if (IS_ERR(d_phy->phy_provider)) {
dev_err(dev, "Failed to create phy provider\n");
return PTR_ERR(d_phy->phy_provider);
}
} else {
int ret;
ret = phy_create_lookup(d_phy->usb11_phy, "usb-phy",
"ohci-da8xx");
if (ret)
dev_warn(dev, "Failed to create usb11 phy lookup\n");
ret = phy_create_lookup(d_phy->usb20_phy, "usb-phy",
"musb-da8xx");
if (ret)
dev_warn(dev, "Failed to create usb20 phy lookup\n");
}
regmap_write_bits(d_phy->regmap, CFGCHIP(2),
PHY_INIT_BITS, PHY_INIT_BITS);
return 0;
}
static int da8xx_usb_phy_remove(struct platform_device *pdev)
{
struct da8xx_usb_phy *d_phy = platform_get_drvdata(pdev);
if (!pdev->dev.of_node) {
phy_remove_lookup(d_phy->usb20_phy, "usb-phy", "musb-da8xx");
phy_remove_lookup(d_phy->usb11_phy, "usb-phy", "ohci-da8xx");
}
return 0;
}
