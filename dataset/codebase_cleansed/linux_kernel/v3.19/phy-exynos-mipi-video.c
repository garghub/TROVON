static int __set_phy_state(struct exynos_mipi_video_phy *state,
enum exynos_mipi_phy_id id, unsigned int on)
{
void __iomem *addr;
u32 reg, reset;
addr = state->regs + EXYNOS_MIPI_PHY_CONTROL(id / 2);
if (is_mipi_dsim_phy_id(id))
reset = EXYNOS_MIPI_PHY_MRESETN;
else
reset = EXYNOS_MIPI_PHY_SRESETN;
spin_lock(&state->slock);
reg = readl(addr);
if (on)
reg |= reset;
else
reg &= ~reset;
writel(reg, addr);
if (on)
reg |= EXYNOS_MIPI_PHY_ENABLE;
else if (!(reg & EXYNOS_MIPI_PHY_RESET_MASK))
reg &= ~EXYNOS_MIPI_PHY_ENABLE;
writel(reg, addr);
spin_unlock(&state->slock);
return 0;
}
static int exynos_mipi_video_phy_power_on(struct phy *phy)
{
struct video_phy_desc *phy_desc = phy_get_drvdata(phy);
struct exynos_mipi_video_phy *state = to_mipi_video_phy(phy_desc);
return __set_phy_state(state, phy_desc->index, 1);
}
static int exynos_mipi_video_phy_power_off(struct phy *phy)
{
struct video_phy_desc *phy_desc = phy_get_drvdata(phy);
struct exynos_mipi_video_phy *state = to_mipi_video_phy(phy_desc);
return __set_phy_state(state, phy_desc->index, 0);
}
static struct phy *exynos_mipi_video_phy_xlate(struct device *dev,
struct of_phandle_args *args)
{
struct exynos_mipi_video_phy *state = dev_get_drvdata(dev);
if (WARN_ON(args->args[0] >= EXYNOS_MIPI_PHYS_NUM))
return ERR_PTR(-ENODEV);
return state->phys[args->args[0]].phy;
}
static int exynos_mipi_video_phy_probe(struct platform_device *pdev)
{
struct exynos_mipi_video_phy *state;
struct device *dev = &pdev->dev;
struct resource *res;
struct phy_provider *phy_provider;
unsigned int i;
state = devm_kzalloc(dev, sizeof(*state), GFP_KERNEL);
if (!state)
return -ENOMEM;
res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
state->regs = devm_ioremap_resource(dev, res);
if (IS_ERR(state->regs))
return PTR_ERR(state->regs);
dev_set_drvdata(dev, state);
spin_lock_init(&state->slock);
for (i = 0; i < EXYNOS_MIPI_PHYS_NUM; i++) {
struct phy *phy = devm_phy_create(dev, NULL,
&exynos_mipi_video_phy_ops);
if (IS_ERR(phy)) {
dev_err(dev, "failed to create PHY %d\n", i);
return PTR_ERR(phy);
}
state->phys[i].phy = phy;
state->phys[i].index = i;
phy_set_drvdata(phy, &state->phys[i]);
}
phy_provider = devm_of_phy_provider_register(dev,
exynos_mipi_video_phy_xlate);
return PTR_ERR_OR_ZERO(phy_provider);
}
