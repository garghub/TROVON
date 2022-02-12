static inline struct tegra_rgb *to_rgb(struct tegra_output *output)
{
return container_of(output, struct tegra_rgb, output);
}
static void tegra_dc_write_regs(struct tegra_dc *dc,
const struct reg_entry *table,
unsigned int num)
{
unsigned int i;
for (i = 0; i < num; i++)
tegra_dc_writel(dc, table[i].value, table[i].offset);
}
static int tegra_output_rgb_enable(struct tegra_output *output)
{
struct tegra_dc *dc = to_tegra_dc(output->encoder.crtc);
tegra_dc_write_regs(dc, rgb_enable, ARRAY_SIZE(rgb_enable));
return 0;
}
static int tegra_output_rgb_disable(struct tegra_output *output)
{
struct tegra_dc *dc = to_tegra_dc(output->encoder.crtc);
tegra_dc_write_regs(dc, rgb_disable, ARRAY_SIZE(rgb_disable));
return 0;
}
static int tegra_output_rgb_setup_clock(struct tegra_output *output,
struct clk *clk, unsigned long pclk)
{
struct tegra_rgb *rgb = to_rgb(output);
return clk_set_parent(clk, rgb->clk_parent);
}
static int tegra_output_rgb_check_mode(struct tegra_output *output,
struct drm_display_mode *mode,
enum drm_mode_status *status)
{
*status = MODE_OK;
return 0;
}
int tegra_dc_rgb_probe(struct tegra_dc *dc)
{
struct device_node *np;
struct tegra_rgb *rgb;
int err;
np = of_get_child_by_name(dc->dev->of_node, "rgb");
if (!np || !of_device_is_available(np))
return -ENODEV;
rgb = devm_kzalloc(dc->dev, sizeof(*rgb), GFP_KERNEL);
if (!rgb)
return -ENOMEM;
rgb->clk = devm_clk_get(dc->dev, NULL);
if (IS_ERR(rgb->clk)) {
dev_err(dc->dev, "failed to get clock\n");
return PTR_ERR(rgb->clk);
}
rgb->clk_parent = devm_clk_get(dc->dev, "parent");
if (IS_ERR(rgb->clk_parent)) {
dev_err(dc->dev, "failed to get parent clock\n");
return PTR_ERR(rgb->clk_parent);
}
err = clk_set_parent(rgb->clk, rgb->clk_parent);
if (err < 0) {
dev_err(dc->dev, "failed to set parent clock: %d\n", err);
return err;
}
rgb->output.dev = dc->dev;
rgb->output.of_node = np;
err = tegra_output_parse_dt(&rgb->output);
if (err < 0)
return err;
dc->rgb = &rgb->output;
return 0;
}
int tegra_dc_rgb_init(struct drm_device *drm, struct tegra_dc *dc)
{
struct tegra_rgb *rgb = to_rgb(dc->rgb);
int err;
if (!dc->rgb)
return -ENODEV;
rgb->output.type = TEGRA_OUTPUT_RGB;
rgb->output.ops = &rgb_ops;
err = tegra_output_init(dc->base.dev, &rgb->output);
if (err < 0) {
dev_err(dc->dev, "output setup failed: %d\n", err);
return err;
}
rgb->output.encoder.possible_crtcs = 1 << dc->pipe;
return 0;
}
int tegra_dc_rgb_exit(struct tegra_dc *dc)
{
if (dc->rgb) {
int err;
err = tegra_output_disable(dc->rgb);
if (err < 0) {
dev_err(dc->dev, "output failed to disable: %d\n", err);
return err;
}
err = tegra_output_exit(dc->rgb);
if (err < 0) {
dev_err(dc->dev, "output cleanup failed: %d\n", err);
return err;
}
dc->rgb = NULL;
}
return 0;
}
