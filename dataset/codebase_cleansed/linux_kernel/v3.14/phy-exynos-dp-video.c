static int __set_phy_state(struct exynos_dp_video_phy *state, unsigned int on)
{
u32 reg;
reg = readl(state->regs);
if (on)
reg |= EXYNOS_DPTX_PHY_ENABLE;
else
reg &= ~EXYNOS_DPTX_PHY_ENABLE;
writel(reg, state->regs);
return 0;
}
static int exynos_dp_video_phy_power_on(struct phy *phy)
{
struct exynos_dp_video_phy *state = phy_get_drvdata(phy);
return __set_phy_state(state, 1);
}
static int exynos_dp_video_phy_power_off(struct phy *phy)
{
struct exynos_dp_video_phy *state = phy_get_drvdata(phy);
return __set_phy_state(state, 0);
}
static int exynos_dp_video_phy_probe(struct platform_device *pdev)
{
struct exynos_dp_video_phy *state;
struct device *dev = &pdev->dev;
struct resource *res;
struct phy_provider *phy_provider;
struct phy *phy;
state = devm_kzalloc(dev, sizeof(*state), GFP_KERNEL);
if (!state)
return -ENOMEM;
res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
state->regs = devm_ioremap_resource(dev, res);
if (IS_ERR(state->regs))
return PTR_ERR(state->regs);
phy = devm_phy_create(dev, &exynos_dp_video_phy_ops, NULL);
if (IS_ERR(phy)) {
dev_err(dev, "failed to create Display Port PHY\n");
return PTR_ERR(phy);
}
phy_set_drvdata(phy, state);
phy_provider = devm_of_phy_provider_register(dev, of_phy_simple_xlate);
if (IS_ERR(phy_provider))
return PTR_ERR(phy_provider);
return 0;
}
