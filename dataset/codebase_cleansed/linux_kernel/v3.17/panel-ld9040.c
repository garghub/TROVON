static inline struct ld9040 *panel_to_ld9040(struct drm_panel *panel)
{
return container_of(panel, struct ld9040, panel);
}
static int ld9040_clear_error(struct ld9040 *ctx)
{
int ret = ctx->error;
ctx->error = 0;
return ret;
}
static int ld9040_spi_write_word(struct ld9040 *ctx, u16 data)
{
struct spi_device *spi = to_spi_device(ctx->dev);
struct spi_transfer xfer = {
.len = 2,
.tx_buf = &data,
};
struct spi_message msg;
spi_message_init(&msg);
spi_message_add_tail(&xfer, &msg);
return spi_sync(spi, &msg);
}
static void ld9040_dcs_write(struct ld9040 *ctx, const u8 *data, size_t len)
{
int ret = 0;
if (ctx->error < 0 || len == 0)
return;
dev_dbg(ctx->dev, "writing dcs seq: %*ph\n", len, data);
ret = ld9040_spi_write_word(ctx, *data);
while (!ret && --len) {
++data;
ret = ld9040_spi_write_word(ctx, *data | 0x100);
}
if (ret) {
dev_err(ctx->dev, "error %d writing dcs seq: %*ph\n", ret, len,
data);
ctx->error = ret;
}
usleep_range(300, 310);
}
static void ld9040_brightness_set(struct ld9040 *ctx)
{
ld9040_dcs_write(ctx, ld9040_gammas[ctx->brightness],
ARRAY_SIZE(ld9040_gammas[ctx->brightness]));
ld9040_dcs_write_seq_static(ctx, MCS_GAMMA_CTRL, 0x02, 0x5a);
}
static void ld9040_init(struct ld9040 *ctx)
{
ld9040_dcs_write_seq_static(ctx, MCS_USER_SETTING, 0x5a, 0x5a);
ld9040_dcs_write_seq_static(ctx, MCS_PANEL_CONDITION,
0x05, 0x65, 0x96, 0x71, 0x7d, 0x19, 0x3b, 0x0d,
0x19, 0x7e, 0x0d, 0xe2, 0x00, 0x00, 0x7e, 0x7d,
0x07, 0x07, 0x20, 0x20, 0x20, 0x02, 0x02);
ld9040_dcs_write_seq_static(ctx, MCS_DISPCTL,
0x02, 0x08, 0x08, 0x10, 0x10);
ld9040_dcs_write_seq_static(ctx, MCS_MANPWR, 0x04);
ld9040_dcs_write_seq_static(ctx, MCS_POWER_CTRL,
0x0a, 0x87, 0x25, 0x6a, 0x44, 0x02, 0x88);
ld9040_dcs_write_seq_static(ctx, MCS_ELVSS_ON, 0x0d, 0x00, 0x16);
ld9040_dcs_write_seq_static(ctx, MCS_GTCON, 0x09, 0x00, 0x00);
ld9040_brightness_set(ctx);
ld9040_dcs_write_seq_static(ctx, MIPI_DCS_EXIT_SLEEP_MODE);
ld9040_dcs_write_seq_static(ctx, MIPI_DCS_SET_DISPLAY_ON);
}
static int ld9040_power_on(struct ld9040 *ctx)
{
int ret;
ret = regulator_bulk_enable(ARRAY_SIZE(ctx->supplies), ctx->supplies);
if (ret < 0)
return ret;
msleep(ctx->power_on_delay);
gpiod_set_value(ctx->reset_gpio, 0);
msleep(ctx->reset_delay);
gpiod_set_value(ctx->reset_gpio, 1);
msleep(ctx->reset_delay);
return 0;
}
static int ld9040_power_off(struct ld9040 *ctx)
{
return regulator_bulk_disable(ARRAY_SIZE(ctx->supplies), ctx->supplies);
}
static int ld9040_disable(struct drm_panel *panel)
{
return 0;
}
static int ld9040_unprepare(struct drm_panel *panel)
{
struct ld9040 *ctx = panel_to_ld9040(panel);
msleep(120);
ld9040_dcs_write_seq_static(ctx, MIPI_DCS_SET_DISPLAY_OFF);
ld9040_dcs_write_seq_static(ctx, MIPI_DCS_ENTER_SLEEP_MODE);
msleep(40);
ld9040_clear_error(ctx);
return ld9040_power_off(ctx);
}
static int ld9040_prepare(struct drm_panel *panel)
{
struct ld9040 *ctx = panel_to_ld9040(panel);
int ret;
ret = ld9040_power_on(ctx);
if (ret < 0)
return ret;
ld9040_init(ctx);
ret = ld9040_clear_error(ctx);
if (ret < 0)
ld9040_unprepare(panel);
return ret;
}
static int ld9040_enable(struct drm_panel *panel)
{
return 0;
}
static int ld9040_get_modes(struct drm_panel *panel)
{
struct drm_connector *connector = panel->connector;
struct ld9040 *ctx = panel_to_ld9040(panel);
struct drm_display_mode *mode;
mode = drm_mode_create(connector->dev);
if (!mode) {
DRM_ERROR("failed to create a new display mode\n");
return 0;
}
drm_display_mode_from_videomode(&ctx->vm, mode);
mode->width_mm = ctx->width_mm;
mode->height_mm = ctx->height_mm;
connector->display_info.width_mm = mode->width_mm;
connector->display_info.height_mm = mode->height_mm;
mode->type = DRM_MODE_TYPE_DRIVER | DRM_MODE_TYPE_PREFERRED;
drm_mode_probed_add(connector, mode);
return 1;
}
static int ld9040_parse_dt(struct ld9040 *ctx)
{
struct device *dev = ctx->dev;
struct device_node *np = dev->of_node;
int ret;
ret = of_get_videomode(np, &ctx->vm, 0);
if (ret < 0)
return ret;
of_property_read_u32(np, "power-on-delay", &ctx->power_on_delay);
of_property_read_u32(np, "reset-delay", &ctx->reset_delay);
of_property_read_u32(np, "panel-width-mm", &ctx->width_mm);
of_property_read_u32(np, "panel-height-mm", &ctx->height_mm);
return 0;
}
static int ld9040_probe(struct spi_device *spi)
{
struct device *dev = &spi->dev;
struct ld9040 *ctx;
int ret;
ctx = devm_kzalloc(dev, sizeof(struct ld9040), GFP_KERNEL);
if (!ctx)
return -ENOMEM;
spi_set_drvdata(spi, ctx);
ctx->dev = dev;
ctx->brightness = ARRAY_SIZE(ld9040_gammas) - 1;
ret = ld9040_parse_dt(ctx);
if (ret < 0)
return ret;
ctx->supplies[0].supply = "vdd3";
ctx->supplies[1].supply = "vci";
ret = devm_regulator_bulk_get(dev, ARRAY_SIZE(ctx->supplies),
ctx->supplies);
if (ret < 0)
return ret;
ctx->reset_gpio = devm_gpiod_get(dev, "reset");
if (IS_ERR(ctx->reset_gpio)) {
dev_err(dev, "cannot get reset-gpios %ld\n",
PTR_ERR(ctx->reset_gpio));
return PTR_ERR(ctx->reset_gpio);
}
ret = gpiod_direction_output(ctx->reset_gpio, 1);
if (ret < 0) {
dev_err(dev, "cannot configure reset-gpios %d\n", ret);
return ret;
}
spi->bits_per_word = 9;
ret = spi_setup(spi);
if (ret < 0) {
dev_err(dev, "spi setup failed.\n");
return ret;
}
drm_panel_init(&ctx->panel);
ctx->panel.dev = dev;
ctx->panel.funcs = &ld9040_drm_funcs;
return drm_panel_add(&ctx->panel);
}
static int ld9040_remove(struct spi_device *spi)
{
struct ld9040 *ctx = spi_get_drvdata(spi);
ld9040_power_off(ctx);
drm_panel_remove(&ctx->panel);
return 0;
}
