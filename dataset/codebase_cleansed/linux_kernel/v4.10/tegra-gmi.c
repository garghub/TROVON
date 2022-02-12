static int tegra_gmi_enable(struct tegra_gmi *gmi)
{
int err;
err = clk_prepare_enable(gmi->clk);
if (err < 0) {
dev_err(gmi->dev, "failed to enable clock: %d\n", err);
return err;
}
reset_control_assert(gmi->rst);
usleep_range(2000, 4000);
reset_control_deassert(gmi->rst);
writel(gmi->snor_timing0, gmi->base + TEGRA_GMI_TIMING0);
writel(gmi->snor_timing1, gmi->base + TEGRA_GMI_TIMING1);
gmi->snor_config |= TEGRA_GMI_CONFIG_GO;
writel(gmi->snor_config, gmi->base + TEGRA_GMI_CONFIG);
return 0;
}
static void tegra_gmi_disable(struct tegra_gmi *gmi)
{
u32 config;
config = readl(gmi->base + TEGRA_GMI_CONFIG);
config &= ~TEGRA_GMI_CONFIG_GO;
writel(config, gmi->base + TEGRA_GMI_CONFIG);
reset_control_assert(gmi->rst);
clk_disable_unprepare(gmi->clk);
}
static int tegra_gmi_parse_dt(struct tegra_gmi *gmi)
{
struct device_node *child;
u32 property, ranges[4];
int err;
child = of_get_next_available_child(gmi->dev->of_node, NULL);
if (!child) {
dev_err(gmi->dev, "no child nodes found\n");
return -ENODEV;
}
if (of_get_child_count(gmi->dev->of_node) > 1)
dev_warn(gmi->dev, "only one child device is supported.");
if (of_property_read_bool(child, "nvidia,snor-data-width-32bit"))
gmi->snor_config |= TEGRA_GMI_BUS_WIDTH_32BIT;
if (of_property_read_bool(child, "nvidia,snor-mux-mode"))
gmi->snor_config |= TEGRA_GMI_MUX_MODE;
if (of_property_read_bool(child, "nvidia,snor-rdy-active-before-data"))
gmi->snor_config |= TEGRA_GMI_RDY_BEFORE_DATA;
if (of_property_read_bool(child, "nvidia,snor-rdy-active-high"))
gmi->snor_config |= TEGRA_GMI_RDY_ACTIVE_HIGH;
if (of_property_read_bool(child, "nvidia,snor-adv-active-high"))
gmi->snor_config |= TEGRA_GMI_ADV_ACTIVE_HIGH;
if (of_property_read_bool(child, "nvidia,snor-oe-active-high"))
gmi->snor_config |= TEGRA_GMI_OE_ACTIVE_HIGH;
if (of_property_read_bool(child, "nvidia,snor-cs-active-high"))
gmi->snor_config |= TEGRA_GMI_CS_ACTIVE_HIGH;
err = of_property_read_u32_array(child, "ranges", ranges, 4);
if (err < 0) {
if (err == -EOVERFLOW) {
dev_err(gmi->dev,
"failed to decode CS: invalid ranges length\n");
goto error_cs;
}
err = of_property_read_u32(child, "reg", &property);
if (err < 0) {
dev_err(gmi->dev,
"failed to decode CS: no reg property found\n");
goto error_cs;
}
} else {
property = ranges[1];
}
if (property >= TEGRA_GMI_MAX_CHIP_SELECT) {
dev_err(gmi->dev, "invalid chip select: %d", property);
err = -EINVAL;
goto error_cs;
}
gmi->snor_config |= TEGRA_GMI_CS_SELECT(property);
if (!of_property_read_u32(child, "nvidia,snor-muxed-width", &property))
gmi->snor_timing0 |= TEGRA_GMI_MUXED_WIDTH(property);
else
gmi->snor_timing0 |= TEGRA_GMI_MUXED_WIDTH(1);
if (!of_property_read_u32(child, "nvidia,snor-hold-width", &property))
gmi->snor_timing0 |= TEGRA_GMI_HOLD_WIDTH(property);
else
gmi->snor_timing0 |= TEGRA_GMI_HOLD_WIDTH(1);
if (!of_property_read_u32(child, "nvidia,snor-adv-width", &property))
gmi->snor_timing0 |= TEGRA_GMI_ADV_WIDTH(property);
else
gmi->snor_timing0 |= TEGRA_GMI_ADV_WIDTH(1);
if (!of_property_read_u32(child, "nvidia,snor-ce-width", &property))
gmi->snor_timing0 |= TEGRA_GMI_CE_WIDTH(property);
else
gmi->snor_timing0 |= TEGRA_GMI_CE_WIDTH(4);
if (!of_property_read_u32(child, "nvidia,snor-we-width", &property))
gmi->snor_timing1 |= TEGRA_GMI_WE_WIDTH(property);
else
gmi->snor_timing1 |= TEGRA_GMI_WE_WIDTH(1);
if (!of_property_read_u32(child, "nvidia,snor-oe-width", &property))
gmi->snor_timing1 |= TEGRA_GMI_OE_WIDTH(property);
else
gmi->snor_timing1 |= TEGRA_GMI_OE_WIDTH(1);
if (!of_property_read_u32(child, "nvidia,snor-wait-width", &property))
gmi->snor_timing1 |= TEGRA_GMI_WAIT_WIDTH(property);
else
gmi->snor_timing1 |= TEGRA_GMI_WAIT_WIDTH(3);
error_cs:
of_node_put(child);
return err;
}
static int tegra_gmi_probe(struct platform_device *pdev)
{
struct device *dev = &pdev->dev;
struct tegra_gmi *gmi;
struct resource *res;
int err;
gmi = devm_kzalloc(dev, sizeof(*gmi), GFP_KERNEL);
if (!gmi)
return -ENOMEM;
gmi->dev = dev;
res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
gmi->base = devm_ioremap_resource(dev, res);
if (IS_ERR(gmi->base))
return PTR_ERR(gmi->base);
gmi->clk = devm_clk_get(dev, "gmi");
if (IS_ERR(gmi->clk)) {
dev_err(dev, "can not get clock\n");
return PTR_ERR(gmi->clk);
}
gmi->rst = devm_reset_control_get(dev, "gmi");
if (IS_ERR(gmi->rst)) {
dev_err(dev, "can not get reset\n");
return PTR_ERR(gmi->rst);
}
err = tegra_gmi_parse_dt(gmi);
if (err)
return err;
err = tegra_gmi_enable(gmi);
if (err < 0)
return err;
err = of_platform_default_populate(dev->of_node, NULL, dev);
if (err < 0) {
dev_err(dev, "fail to create devices.\n");
tegra_gmi_disable(gmi);
return err;
}
platform_set_drvdata(pdev, gmi);
return 0;
}
static int tegra_gmi_remove(struct platform_device *pdev)
{
struct tegra_gmi *gmi = platform_get_drvdata(pdev);
of_platform_depopulate(gmi->dev);
tegra_gmi_disable(gmi);
return 0;
}
