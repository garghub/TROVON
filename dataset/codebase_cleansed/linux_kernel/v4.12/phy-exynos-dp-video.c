static int exynos_dp_video_phy_power_on(struct phy *phy)
{
struct exynos_dp_video_phy *state = phy_get_drvdata(phy);
return regmap_update_bits(state->regs, state->drvdata->phy_ctrl_offset,
EXYNOS4_PHY_ENABLE, EXYNOS4_PHY_ENABLE);
}
static int exynos_dp_video_phy_power_off(struct phy *phy)
{
struct exynos_dp_video_phy *state = phy_get_drvdata(phy);
return regmap_update_bits(state->regs, state->drvdata->phy_ctrl_offset,
EXYNOS4_PHY_ENABLE, 0);
}
static int exynos_dp_video_phy_probe(struct platform_device *pdev)
{
struct exynos_dp_video_phy *state;
struct device *dev = &pdev->dev;
const struct of_device_id *match;
struct phy_provider *phy_provider;
struct phy *phy;
state = devm_kzalloc(dev, sizeof(*state), GFP_KERNEL);
if (!state)
return -ENOMEM;
state->regs = syscon_regmap_lookup_by_phandle(dev->of_node,
"samsung,pmu-syscon");
if (IS_ERR(state->regs)) {
dev_err(dev, "Failed to lookup PMU regmap\n");
return PTR_ERR(state->regs);
}
match = of_match_node(exynos_dp_video_phy_of_match, dev->of_node);
state->drvdata = match->data;
phy = devm_phy_create(dev, NULL, &exynos_dp_video_phy_ops);
if (IS_ERR(phy)) {
dev_err(dev, "failed to create Display Port PHY\n");
return PTR_ERR(phy);
}
phy_set_drvdata(phy, state);
phy_provider = devm_of_phy_provider_register(dev, of_phy_simple_xlate);
return PTR_ERR_OR_ZERO(phy_provider);
}
