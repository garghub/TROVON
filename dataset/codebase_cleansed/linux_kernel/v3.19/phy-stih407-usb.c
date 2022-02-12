static int stih407_usb2_pico_ctrl(struct stih407_usb2_picophy *phy_dev)
{
reset_control_deassert(phy_dev->rstc);
return regmap_update_bits(phy_dev->regmap, phy_dev->ctrl,
STIH407_USB_PICOPHY_CTRL_PORT_MASK,
STIH407_USB_PICOPHY_CTRL_PORT_CONF);
}
static int stih407_usb2_init_port(struct phy *phy)
{
int ret;
struct stih407_usb2_picophy *phy_dev = phy_get_drvdata(phy);
stih407_usb2_pico_ctrl(phy_dev);
ret = regmap_update_bits(phy_dev->regmap,
phy_dev->param,
STIH407_USB_PICOPHY_PARAM_MASK,
STIH407_USB_PICOPHY_PARAM_DEF);
if (ret)
return ret;
return reset_control_deassert(phy_dev->rstport);
}
static int stih407_usb2_exit_port(struct phy *phy)
{
struct stih407_usb2_picophy *phy_dev = phy_get_drvdata(phy);
return reset_control_assert(phy_dev->rstport);
}
static int stih407_usb2_picophy_probe(struct platform_device *pdev)
{
struct stih407_usb2_picophy *phy_dev;
struct device *dev = &pdev->dev;
struct device_node *np = dev->of_node;
struct phy_provider *phy_provider;
struct phy *phy;
struct resource *res;
phy_dev = devm_kzalloc(dev, sizeof(*phy_dev), GFP_KERNEL);
if (!phy_dev)
return -ENOMEM;
phy_dev->dev = dev;
dev_set_drvdata(dev, phy_dev);
phy_dev->rstc = devm_reset_control_get(dev, "global");
if (IS_ERR(phy_dev->rstc)) {
dev_err(dev, "failed to ctrl picoPHY reset\n");
return PTR_ERR(phy_dev->rstc);
}
phy_dev->rstport = devm_reset_control_get(dev, "port");
if (IS_ERR(phy_dev->rstport)) {
dev_err(dev, "failed to ctrl picoPHY reset\n");
return PTR_ERR(phy_dev->rstport);
}
reset_control_assert(phy_dev->rstport);
phy_dev->regmap = syscon_regmap_lookup_by_phandle(np, "st,syscfg");
if (IS_ERR(phy_dev->regmap)) {
dev_err(dev, "No syscfg phandle specified\n");
return PTR_ERR(phy_dev->regmap);
}
res = platform_get_resource_byname(pdev, IORESOURCE_MEM, "ctrl");
if (!res) {
dev_err(dev, "No ctrl reg found\n");
return -ENXIO;
}
phy_dev->ctrl = res->start;
res = platform_get_resource_byname(pdev, IORESOURCE_MEM, "param");
if (!res) {
dev_err(dev, "No param reg found\n");
return -ENXIO;
}
phy_dev->param = res->start;
phy = devm_phy_create(dev, NULL, &stih407_usb2_picophy_data);
if (IS_ERR(phy)) {
dev_err(dev, "failed to create Display Port PHY\n");
return PTR_ERR(phy);
}
phy_dev->phy = phy;
phy_set_drvdata(phy, phy_dev);
phy_provider = devm_of_phy_provider_register(dev, of_phy_simple_xlate);
if (IS_ERR(phy_provider))
return PTR_ERR(phy_provider);
dev_info(dev, "STiH407 USB Generic picoPHY driver probed!");
return 0;
}
