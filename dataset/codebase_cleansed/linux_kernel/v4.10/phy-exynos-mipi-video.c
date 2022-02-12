static int __set_phy_state(const struct exynos_mipi_phy_desc *data,
struct exynos_mipi_video_phy *state, unsigned int on)
{
u32 val;
spin_lock(&state->slock);
if (!on && data->coupled_phy_id >= 0 &&
state->phys[data->coupled_phy_id].phy->power_count == 0) {
regmap_read(state->regmaps[data->enable_map], data->enable_reg,
&val);
val &= ~data->enable_val;
regmap_write(state->regmaps[data->enable_map], data->enable_reg,
val);
}
regmap_read(state->regmaps[data->resetn_map], data->resetn_reg, &val);
val = on ? (val | data->resetn_val) : (val & ~data->resetn_val);
regmap_write(state->regmaps[data->resetn_map], data->resetn_reg, val);
if (on) {
regmap_read(state->regmaps[data->enable_map], data->enable_reg,
&val);
val |= data->enable_val;
regmap_write(state->regmaps[data->enable_map], data->enable_reg,
val);
}
spin_unlock(&state->slock);
return 0;
}
static int exynos_mipi_video_phy_power_on(struct phy *phy)
{
struct video_phy_desc *phy_desc = phy_get_drvdata(phy);
struct exynos_mipi_video_phy *state = to_mipi_video_phy(phy_desc);
return __set_phy_state(phy_desc->data, state, 1);
}
static int exynos_mipi_video_phy_power_off(struct phy *phy)
{
struct video_phy_desc *phy_desc = phy_get_drvdata(phy);
struct exynos_mipi_video_phy *state = to_mipi_video_phy(phy_desc);
return __set_phy_state(phy_desc->data, state, 0);
}
static struct phy *exynos_mipi_video_phy_xlate(struct device *dev,
struct of_phandle_args *args)
{
struct exynos_mipi_video_phy *state = dev_get_drvdata(dev);
if (WARN_ON(args->args[0] >= state->num_phys))
return ERR_PTR(-ENODEV);
return state->phys[args->args[0]].phy;
}
static int exynos_mipi_video_phy_probe(struct platform_device *pdev)
{
const struct mipi_phy_device_desc *phy_dev;
struct exynos_mipi_video_phy *state;
struct device *dev = &pdev->dev;
struct device_node *np = dev->of_node;
struct phy_provider *phy_provider;
unsigned int i;
phy_dev = of_device_get_match_data(dev);
if (!phy_dev)
return -ENODEV;
state = devm_kzalloc(dev, sizeof(*state), GFP_KERNEL);
if (!state)
return -ENOMEM;
for (i = 0; i < phy_dev->num_regmaps; i++) {
state->regmaps[i] = syscon_regmap_lookup_by_phandle(np,
phy_dev->regmap_names[i]);
if (IS_ERR(state->regmaps[i]))
return PTR_ERR(state->regmaps[i]);
}
state->num_phys = phy_dev->num_phys;
spin_lock_init(&state->slock);
dev_set_drvdata(dev, state);
for (i = 0; i < state->num_phys; i++) {
struct phy *phy = devm_phy_create(dev, NULL,
&exynos_mipi_video_phy_ops);
if (IS_ERR(phy)) {
dev_err(dev, "failed to create PHY %d\n", i);
return PTR_ERR(phy);
}
state->phys[i].phy = phy;
state->phys[i].index = i;
state->phys[i].data = &phy_dev->phys[i];
phy_set_drvdata(phy, &state->phys[i]);
}
phy_provider = devm_of_phy_provider_register(dev,
exynos_mipi_video_phy_xlate);
return PTR_ERR_OR_ZERO(phy_provider);
}
