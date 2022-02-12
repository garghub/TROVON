static int stih41x_usb_phy_init(struct phy *phy)
{
struct stih41x_usb_phy *phy_dev = phy_get_drvdata(phy);
return regmap_update_bits(phy_dev->regmap, phy_dev->cfg->syscfg,
phy_dev->cfg->cfg_mask, phy_dev->cfg->cfg);
}
static int stih41x_usb_phy_power_on(struct phy *phy)
{
struct stih41x_usb_phy *phy_dev = phy_get_drvdata(phy);
int ret;
ret = clk_prepare_enable(phy_dev->clk);
if (ret) {
dev_err(phy_dev->dev, "Failed to enable osc_phy clock\n");
return ret;
}
ret = regmap_update_bits(phy_dev->regmap, phy_dev->cfg->syscfg,
phy_dev->cfg->oscok, phy_dev->cfg->oscok);
if (ret)
clk_disable_unprepare(phy_dev->clk);
return ret;
}
static int stih41x_usb_phy_power_off(struct phy *phy)
{
struct stih41x_usb_phy *phy_dev = phy_get_drvdata(phy);
int ret;
ret = regmap_update_bits(phy_dev->regmap, phy_dev->cfg->syscfg,
phy_dev->cfg->oscok, 0);
if (ret) {
dev_err(phy_dev->dev, "Failed to clear oscok bit\n");
return ret;
}
clk_disable_unprepare(phy_dev->clk);
return 0;
}
static int stih41x_usb_phy_probe(struct platform_device *pdev)
{
struct device_node *np = pdev->dev.of_node;
const struct of_device_id *match;
struct stih41x_usb_phy *phy_dev;
struct device *dev = &pdev->dev;
struct phy_provider *phy_provider;
struct phy *phy;
phy_dev = devm_kzalloc(dev, sizeof(*phy_dev), GFP_KERNEL);
if (!phy_dev)
return -ENOMEM;
match = of_match_device(stih41x_usb_phy_of_match, &pdev->dev);
if (!match)
return -ENODEV;
phy_dev->cfg = match->data;
phy_dev->regmap = syscon_regmap_lookup_by_phandle(np, "st,syscfg");
if (IS_ERR(phy_dev->regmap)) {
dev_err(dev, "No syscfg phandle specified\n");
return PTR_ERR(phy_dev->regmap);
}
phy_dev->clk = devm_clk_get(dev, "osc_phy");
if (IS_ERR(phy_dev->clk)) {
dev_err(dev, "osc_phy clk not found\n");
return PTR_ERR(phy_dev->clk);
}
phy = devm_phy_create(dev, NULL, &stih41x_usb_phy_ops);
if (IS_ERR(phy)) {
dev_err(dev, "failed to create phy\n");
return PTR_ERR(phy);
}
phy_dev->dev = dev;
phy_set_drvdata(phy, phy_dev);
phy_provider = devm_of_phy_provider_register(dev, of_phy_simple_xlate);
return PTR_ERR_OR_ZERO(phy_provider);
}
