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
struct tegra_rgb *rgb = to_rgb(output);
unsigned long value;
if (rgb->enabled)
return 0;
tegra_dc_write_regs(rgb->dc, rgb_enable, ARRAY_SIZE(rgb_enable));
value = DE_SELECT_ACTIVE | DE_CONTROL_NORMAL;
tegra_dc_writel(rgb->dc, value, DC_DISP_DATA_ENABLE_OPTIONS);
value = tegra_dc_readl(rgb->dc, DC_COM_PIN_OUTPUT_POLARITY(1));
value &= ~LVS_OUTPUT_POLARITY_LOW;
value &= ~LHS_OUTPUT_POLARITY_LOW;
tegra_dc_writel(rgb->dc, value, DC_COM_PIN_OUTPUT_POLARITY(1));
value = DISP_DATA_FORMAT_DF1P1C | DISP_ALIGNMENT_MSB |
DISP_ORDER_RED_BLUE;
tegra_dc_writel(rgb->dc, value, DC_DISP_DISP_INTERFACE_CONTROL);
value = SC0_H_QUALIFIER_NONE | SC1_H_QUALIFIER_NONE;
tegra_dc_writel(rgb->dc, value, DC_DISP_SHIFT_CLOCK_OPTIONS);
value = tegra_dc_readl(rgb->dc, DC_CMD_DISPLAY_COMMAND);
value &= ~DISP_CTRL_MODE_MASK;
value |= DISP_CTRL_MODE_C_DISPLAY;
tegra_dc_writel(rgb->dc, value, DC_CMD_DISPLAY_COMMAND);
value = tegra_dc_readl(rgb->dc, DC_CMD_DISPLAY_POWER_CONTROL);
value |= PW0_ENABLE | PW1_ENABLE | PW2_ENABLE | PW3_ENABLE |
PW4_ENABLE | PM0_ENABLE | PM1_ENABLE;
tegra_dc_writel(rgb->dc, value, DC_CMD_DISPLAY_POWER_CONTROL);
tegra_dc_writel(rgb->dc, GENERAL_ACT_REQ << 8, DC_CMD_STATE_CONTROL);
tegra_dc_writel(rgb->dc, GENERAL_ACT_REQ, DC_CMD_STATE_CONTROL);
rgb->enabled = true;
return 0;
}
static int tegra_output_rgb_disable(struct tegra_output *output)
{
struct tegra_rgb *rgb = to_rgb(output);
unsigned long value;
if (!rgb->enabled)
return 0;
value = tegra_dc_readl(rgb->dc, DC_CMD_DISPLAY_POWER_CONTROL);
value &= ~(PW0_ENABLE | PW1_ENABLE | PW2_ENABLE | PW3_ENABLE |
PW4_ENABLE | PM0_ENABLE | PM1_ENABLE);
tegra_dc_writel(rgb->dc, value, DC_CMD_DISPLAY_POWER_CONTROL);
value = tegra_dc_readl(rgb->dc, DC_CMD_DISPLAY_COMMAND);
value &= ~DISP_CTRL_MODE_MASK;
tegra_dc_writel(rgb->dc, value, DC_CMD_DISPLAY_COMMAND);
tegra_dc_writel(rgb->dc, GENERAL_ACT_REQ << 8, DC_CMD_STATE_CONTROL);
tegra_dc_writel(rgb->dc, GENERAL_ACT_REQ, DC_CMD_STATE_CONTROL);
tegra_dc_write_regs(rgb->dc, rgb_disable, ARRAY_SIZE(rgb_disable));
rgb->enabled = false;
return 0;
}
static int tegra_output_rgb_setup_clock(struct tegra_output *output,
struct clk *clk, unsigned long pclk,
unsigned int *div)
{
struct tegra_rgb *rgb = to_rgb(output);
int err;
err = clk_set_parent(clk, rgb->clk_parent);
if (err < 0) {
dev_err(output->dev, "failed to set parent: %d\n", err);
return err;
}
*div = ((clk_get_rate(clk) * 2) / pclk) - 2;
return 0;
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
rgb->output.dev = dc->dev;
rgb->output.of_node = np;
rgb->dc = dc;
err = tegra_output_probe(&rgb->output);
if (err < 0)
return err;
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
dc->rgb = &rgb->output;
return 0;
}
int tegra_dc_rgb_remove(struct tegra_dc *dc)
{
int err;
if (!dc->rgb)
return 0;
err = tegra_output_remove(dc->rgb);
if (err < 0)
return err;
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
rgb->output.encoder.possible_crtcs = drm_crtc_mask(&dc->base);
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
