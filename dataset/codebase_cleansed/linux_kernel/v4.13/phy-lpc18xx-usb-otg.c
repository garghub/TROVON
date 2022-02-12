static int lpc18xx_usb_otg_phy_init(struct phy *phy)
{
struct lpc18xx_usb_otg_phy *lpc = phy_get_drvdata(phy);
int ret;
ret = clk_set_rate(lpc->clk, 480000000);
if (ret)
return ret;
return clk_prepare(lpc->clk);
}
static int lpc18xx_usb_otg_phy_exit(struct phy *phy)
{
struct lpc18xx_usb_otg_phy *lpc = phy_get_drvdata(phy);
clk_unprepare(lpc->clk);
return 0;
}
static int lpc18xx_usb_otg_phy_power_on(struct phy *phy)
{
struct lpc18xx_usb_otg_phy *lpc = phy_get_drvdata(phy);
int ret;
ret = clk_enable(lpc->clk);
if (ret)
return ret;
return regmap_update_bits(lpc->reg, LPC18XX_CREG_CREG0,
LPC18XX_CREG_CREG0_USB0PHY, 0);
}
static int lpc18xx_usb_otg_phy_power_off(struct phy *phy)
{
struct lpc18xx_usb_otg_phy *lpc = phy_get_drvdata(phy);
int ret;
ret = regmap_update_bits(lpc->reg, LPC18XX_CREG_CREG0,
LPC18XX_CREG_CREG0_USB0PHY,
LPC18XX_CREG_CREG0_USB0PHY);
if (ret)
return ret;
clk_disable(lpc->clk);
return 0;
}
static int lpc18xx_usb_otg_phy_probe(struct platform_device *pdev)
{
struct phy_provider *phy_provider;
struct lpc18xx_usb_otg_phy *lpc;
lpc = devm_kzalloc(&pdev->dev, sizeof(*lpc), GFP_KERNEL);
if (!lpc)
return -ENOMEM;
lpc->reg = syscon_node_to_regmap(pdev->dev.of_node->parent);
if (IS_ERR(lpc->reg)) {
dev_err(&pdev->dev, "failed to get syscon\n");
return PTR_ERR(lpc->reg);
}
lpc->clk = devm_clk_get(&pdev->dev, NULL);
if (IS_ERR(lpc->clk)) {
dev_err(&pdev->dev, "failed to get clock\n");
return PTR_ERR(lpc->clk);
}
lpc->phy = devm_phy_create(&pdev->dev, NULL, &lpc18xx_usb_otg_phy_ops);
if (IS_ERR(lpc->phy)) {
dev_err(&pdev->dev, "failed to create PHY\n");
return PTR_ERR(lpc->phy);
}
phy_set_drvdata(lpc->phy, lpc);
phy_provider = devm_of_phy_provider_register(&pdev->dev,
of_phy_simple_xlate);
return PTR_ERR_OR_ZERO(phy_provider);
}
