static int rockchip_usb_phy_power(struct rockchip_usb_phy *phy,
bool siddq)
{
return regmap_write(phy->reg_base, phy->reg_offset,
SIDDQ_WRITE_ENA | (siddq ? SIDDQ_ON : SIDDQ_OFF));
}
static int rockchip_usb_phy_power_off(struct phy *_phy)
{
struct rockchip_usb_phy *phy = phy_get_drvdata(_phy);
int ret = 0;
ret = rockchip_usb_phy_power(phy, 1);
if (ret)
return ret;
clk_disable_unprepare(phy->clk);
return 0;
}
static int rockchip_usb_phy_power_on(struct phy *_phy)
{
struct rockchip_usb_phy *phy = phy_get_drvdata(_phy);
int ret = 0;
ret = clk_prepare_enable(phy->clk);
if (ret)
return ret;
ret = rockchip_usb_phy_power(phy, 0);
if (ret) {
clk_disable_unprepare(phy->clk);
return ret;
}
return 0;
}
static int rockchip_usb_phy_probe(struct platform_device *pdev)
{
struct device *dev = &pdev->dev;
struct rockchip_usb_phy *rk_phy;
struct phy_provider *phy_provider;
struct device_node *child;
struct regmap *grf;
unsigned int reg_offset;
grf = syscon_regmap_lookup_by_phandle(dev->of_node, "rockchip,grf");
if (IS_ERR(grf)) {
dev_err(&pdev->dev, "Missing rockchip,grf property\n");
return PTR_ERR(grf);
}
for_each_available_child_of_node(dev->of_node, child) {
rk_phy = devm_kzalloc(dev, sizeof(*rk_phy), GFP_KERNEL);
if (!rk_phy)
return -ENOMEM;
if (of_property_read_u32(child, "reg", &reg_offset)) {
dev_err(dev, "missing reg property in node %s\n",
child->name);
return -EINVAL;
}
rk_phy->reg_offset = reg_offset;
rk_phy->reg_base = grf;
rk_phy->clk = of_clk_get_by_name(child, "phyclk");
if (IS_ERR(rk_phy->clk))
rk_phy->clk = NULL;
rk_phy->phy = devm_phy_create(dev, child, &ops);
if (IS_ERR(rk_phy->phy)) {
dev_err(dev, "failed to create PHY\n");
return PTR_ERR(rk_phy->phy);
}
phy_set_drvdata(rk_phy->phy, rk_phy);
}
phy_provider = devm_of_phy_provider_register(dev, of_phy_simple_xlate);
return PTR_ERR_OR_ZERO(phy_provider);
}
