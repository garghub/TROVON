static int s6e3ha2_dcs_write(struct s6e3ha2 *ctx, const void *data, size_t len)
{
struct mipi_dsi_device *dsi = to_mipi_dsi_device(ctx->dev);
return mipi_dsi_dcs_write_buffer(dsi, data, len);
}
static int s6e3ha2_test_key_on_f0(struct s6e3ha2 *ctx)
{
s6e3ha2_dcs_write_seq_static(ctx, 0xf0, 0x5a, 0x5a);
return 0;
}
static int s6e3ha2_test_key_off_f0(struct s6e3ha2 *ctx)
{
s6e3ha2_dcs_write_seq_static(ctx, 0xf0, 0xa5, 0xa5);
return 0;
}
static int s6e3ha2_test_key_on_fc(struct s6e3ha2 *ctx)
{
s6e3ha2_dcs_write_seq_static(ctx, 0xfc, 0x5a, 0x5a);
return 0;
}
static int s6e3ha2_test_key_off_fc(struct s6e3ha2 *ctx)
{
s6e3ha2_dcs_write_seq_static(ctx, 0xfc, 0xa5, 0xa5);
return 0;
}
static int s6e3ha2_single_dsi_set(struct s6e3ha2 *ctx)
{
s6e3ha2_dcs_write_seq_static(ctx, 0xf2, 0x67);
s6e3ha2_dcs_write_seq_static(ctx, 0xf9, 0x09);
return 0;
}
static int s6e3ha2_freq_calibration(struct s6e3ha2 *ctx)
{
s6e3ha2_dcs_write_seq_static(ctx, 0xfd, 0x1c);
s6e3ha2_dcs_write_seq_static(ctx, 0xfe, 0x20, 0x39);
s6e3ha2_dcs_write_seq_static(ctx, 0xfe, 0xa0);
s6e3ha2_dcs_write_seq_static(ctx, 0xfe, 0x20);
s6e3ha2_dcs_write_seq_static(ctx, 0xce, 0x03, 0x3b, 0x12, 0x62, 0x40,
0x80, 0xc0, 0x28, 0x28, 0x28, 0x28, 0x39, 0xc5);
return 0;
}
static int s6e3ha2_aor_control(struct s6e3ha2 *ctx)
{
s6e3ha2_dcs_write_seq_static(ctx, 0xb2, 0x03, 0x10);
return 0;
}
static int s6e3ha2_caps_elvss_set(struct s6e3ha2 *ctx)
{
s6e3ha2_dcs_write_seq_static(ctx, 0xb6, 0x9c, 0x0a);
return 0;
}
static int s6e3ha2_acl_off(struct s6e3ha2 *ctx)
{
s6e3ha2_dcs_write_seq_static(ctx, 0x55, 0x00);
return 0;
}
static int s6e3ha2_acl_off_opr(struct s6e3ha2 *ctx)
{
s6e3ha2_dcs_write_seq_static(ctx, 0xb5, 0x40);
return 0;
}
static int s6e3ha2_test_global(struct s6e3ha2 *ctx)
{
s6e3ha2_dcs_write_seq_static(ctx, 0xb0, 0x07);
return 0;
}
static int s6e3ha2_test(struct s6e3ha2 *ctx)
{
s6e3ha2_dcs_write_seq_static(ctx, 0xb8, 0x19);
return 0;
}
static int s6e3ha2_touch_hsync_on1(struct s6e3ha2 *ctx)
{
s6e3ha2_dcs_write_seq_static(ctx, 0xbd, 0x33, 0x11, 0x02,
0x16, 0x02, 0x16);
return 0;
}
static int s6e3ha2_pentile_control(struct s6e3ha2 *ctx)
{
s6e3ha2_dcs_write_seq_static(ctx, 0xc0, 0x00, 0x00, 0xd8, 0xd8);
return 0;
}
static int s6e3ha2_poc_global(struct s6e3ha2 *ctx)
{
s6e3ha2_dcs_write_seq_static(ctx, 0xb0, 0x20);
return 0;
}
static int s6e3ha2_poc_setting(struct s6e3ha2 *ctx)
{
s6e3ha2_dcs_write_seq_static(ctx, 0xfe, 0x08);
return 0;
}
static int s6e3ha2_pcd_set_off(struct s6e3ha2 *ctx)
{
s6e3ha2_dcs_write_seq_static(ctx, 0xcc, 0x40, 0x51);
return 0;
}
static int s6e3ha2_err_fg_set(struct s6e3ha2 *ctx)
{
s6e3ha2_dcs_write_seq_static(ctx, 0xed, 0x44);
return 0;
}
static int s6e3ha2_hbm_off(struct s6e3ha2 *ctx)
{
s6e3ha2_dcs_write_seq_static(ctx, 0x53, 0x00);
return 0;
}
static int s6e3ha2_te_start_setting(struct s6e3ha2 *ctx)
{
s6e3ha2_dcs_write_seq_static(ctx, 0xb9, 0x10, 0x09, 0xff, 0x00, 0x09);
return 0;
}
static int s6e3ha2_gamma_update(struct s6e3ha2 *ctx)
{
s6e3ha2_dcs_write_seq_static(ctx, 0xf7, 0x03);
ndelay(100);
s6e3ha2_dcs_write_seq_static(ctx, 0xf7, 0x00);
return 0;
}
static int s6e3ha2_get_brightness(struct backlight_device *bl_dev)
{
return bl_dev->props.brightness;
}
static int s6e3ha2_set_vint(struct s6e3ha2 *ctx)
{
struct backlight_device *bl_dev = ctx->bl_dev;
unsigned int brightness = bl_dev->props.brightness;
unsigned char data[] = { 0xf4, 0x8b,
vint_table[brightness * (S6E3HA2_VINT_STATUS_MAX - 1) /
S6E3HA2_MAX_BRIGHTNESS] };
return s6e3ha2_dcs_write(ctx, data, ARRAY_SIZE(data));
}
static unsigned int s6e3ha2_get_brightness_index(unsigned int brightness)
{
return (brightness * (S6E3HA2_NUM_GAMMA_STEPS - 1)) /
S6E3HA2_MAX_BRIGHTNESS;
}
static int s6e3ha2_update_gamma(struct s6e3ha2 *ctx, unsigned int brightness)
{
struct backlight_device *bl_dev = ctx->bl_dev;
unsigned int index = s6e3ha2_get_brightness_index(brightness);
u8 data[S6E3HA2_GAMMA_CMD_CNT + 1] = { 0xca, };
int ret;
memcpy(data + 1, gamma_tbl + index, S6E3HA2_GAMMA_CMD_CNT);
s6e3ha2_call_write_func(ret,
s6e3ha2_dcs_write(ctx, data, ARRAY_SIZE(data)));
s6e3ha2_call_write_func(ret, s6e3ha2_gamma_update(ctx));
bl_dev->props.brightness = brightness;
return 0;
}
static int s6e3ha2_set_brightness(struct backlight_device *bl_dev)
{
struct s6e3ha2 *ctx = bl_get_data(bl_dev);
unsigned int brightness = bl_dev->props.brightness;
int ret;
if (brightness < S6E3HA2_MIN_BRIGHTNESS ||
brightness > bl_dev->props.max_brightness) {
dev_err(ctx->dev, "Invalid brightness: %u\n", brightness);
return -EINVAL;
}
if (bl_dev->props.power > FB_BLANK_NORMAL)
return -EPERM;
s6e3ha2_call_write_func(ret, s6e3ha2_test_key_on_f0(ctx));
s6e3ha2_call_write_func(ret, s6e3ha2_update_gamma(ctx, brightness));
s6e3ha2_call_write_func(ret, s6e3ha2_aor_control(ctx));
s6e3ha2_call_write_func(ret, s6e3ha2_set_vint(ctx));
s6e3ha2_call_write_func(ret, s6e3ha2_test_key_off_f0(ctx));
return 0;
}
static int s6e3ha2_panel_init(struct s6e3ha2 *ctx)
{
struct mipi_dsi_device *dsi = to_mipi_dsi_device(ctx->dev);
int ret;
s6e3ha2_call_write_func(ret, mipi_dsi_dcs_exit_sleep_mode(dsi));
usleep_range(5000, 6000);
s6e3ha2_call_write_func(ret, s6e3ha2_test_key_on_f0(ctx));
s6e3ha2_call_write_func(ret, s6e3ha2_single_dsi_set(ctx));
s6e3ha2_call_write_func(ret, s6e3ha2_test_key_on_fc(ctx));
s6e3ha2_call_write_func(ret, s6e3ha2_freq_calibration(ctx));
s6e3ha2_call_write_func(ret, s6e3ha2_test_key_off_fc(ctx));
s6e3ha2_call_write_func(ret, s6e3ha2_test_key_off_f0(ctx));
return 0;
}
static int s6e3ha2_power_off(struct s6e3ha2 *ctx)
{
return regulator_bulk_disable(ARRAY_SIZE(ctx->supplies), ctx->supplies);
}
static int s6e3ha2_disable(struct drm_panel *panel)
{
struct s6e3ha2 *ctx = container_of(panel, struct s6e3ha2, panel);
struct mipi_dsi_device *dsi = to_mipi_dsi_device(ctx->dev);
int ret;
s6e3ha2_call_write_func(ret, mipi_dsi_dcs_enter_sleep_mode(dsi));
s6e3ha2_call_write_func(ret, mipi_dsi_dcs_set_display_off(dsi));
msleep(40);
ctx->bl_dev->props.power = FB_BLANK_NORMAL;
return 0;
}
static int s6e3ha2_unprepare(struct drm_panel *panel)
{
struct s6e3ha2 *ctx = container_of(panel, struct s6e3ha2, panel);
return s6e3ha2_power_off(ctx);
}
static int s6e3ha2_power_on(struct s6e3ha2 *ctx)
{
int ret;
ret = regulator_bulk_enable(ARRAY_SIZE(ctx->supplies), ctx->supplies);
if (ret < 0)
return ret;
msleep(120);
gpiod_set_value(ctx->enable_gpio, 0);
usleep_range(5000, 6000);
gpiod_set_value(ctx->enable_gpio, 1);
gpiod_set_value(ctx->reset_gpio, 1);
usleep_range(5000, 6000);
gpiod_set_value(ctx->reset_gpio, 0);
usleep_range(5000, 6000);
return 0;
}
static int s6e3ha2_prepare(struct drm_panel *panel)
{
struct s6e3ha2 *ctx = container_of(panel, struct s6e3ha2, panel);
int ret;
ret = s6e3ha2_power_on(ctx);
if (ret < 0)
return ret;
ret = s6e3ha2_panel_init(ctx);
if (ret < 0)
goto err;
ctx->bl_dev->props.power = FB_BLANK_NORMAL;
return 0;
err:
s6e3ha2_power_off(ctx);
return ret;
}
static int s6e3ha2_enable(struct drm_panel *panel)
{
struct s6e3ha2 *ctx = container_of(panel, struct s6e3ha2, panel);
struct mipi_dsi_device *dsi = to_mipi_dsi_device(ctx->dev);
int ret;
s6e3ha2_call_write_func(ret,
mipi_dsi_dcs_set_tear_on(dsi, MIPI_DSI_DCS_TEAR_MODE_VBLANK));
s6e3ha2_call_write_func(ret, s6e3ha2_test_key_on_f0(ctx));
s6e3ha2_call_write_func(ret, s6e3ha2_test_key_on_fc(ctx));
s6e3ha2_call_write_func(ret, s6e3ha2_touch_hsync_on1(ctx));
s6e3ha2_call_write_func(ret, s6e3ha2_pentile_control(ctx));
s6e3ha2_call_write_func(ret, s6e3ha2_poc_global(ctx));
s6e3ha2_call_write_func(ret, s6e3ha2_poc_setting(ctx));
s6e3ha2_call_write_func(ret, s6e3ha2_test_key_off_fc(ctx));
s6e3ha2_call_write_func(ret, s6e3ha2_pcd_set_off(ctx));
s6e3ha2_call_write_func(ret, s6e3ha2_err_fg_set(ctx));
s6e3ha2_call_write_func(ret, s6e3ha2_te_start_setting(ctx));
s6e3ha2_call_write_func(ret, s6e3ha2_set_brightness(ctx->bl_dev));
s6e3ha2_call_write_func(ret, s6e3ha2_aor_control(ctx));
s6e3ha2_call_write_func(ret, s6e3ha2_caps_elvss_set(ctx));
s6e3ha2_call_write_func(ret, s6e3ha2_gamma_update(ctx));
s6e3ha2_call_write_func(ret, s6e3ha2_acl_off(ctx));
s6e3ha2_call_write_func(ret, s6e3ha2_acl_off_opr(ctx));
s6e3ha2_call_write_func(ret, s6e3ha2_hbm_off(ctx));
s6e3ha2_call_write_func(ret, s6e3ha2_test_global(ctx));
s6e3ha2_call_write_func(ret, s6e3ha2_test(ctx));
s6e3ha2_call_write_func(ret, s6e3ha2_test_key_off_f0(ctx));
s6e3ha2_call_write_func(ret, mipi_dsi_dcs_set_display_on(dsi));
ctx->bl_dev->props.power = FB_BLANK_UNBLANK;
return 0;
}
static int s6e3ha2_get_modes(struct drm_panel *panel)
{
struct drm_connector *connector = panel->connector;
struct drm_display_mode *mode;
mode = drm_mode_duplicate(panel->drm, &default_mode);
if (!mode) {
DRM_ERROR("failed to add mode %ux%ux@%u\n",
default_mode.hdisplay, default_mode.vdisplay,
default_mode.vrefresh);
return -ENOMEM;
}
drm_mode_set_name(mode);
mode->type = DRM_MODE_TYPE_DRIVER | DRM_MODE_TYPE_PREFERRED;
drm_mode_probed_add(connector, mode);
connector->display_info.width_mm = 71;
connector->display_info.height_mm = 125;
return 1;
}
static int s6e3ha2_probe(struct mipi_dsi_device *dsi)
{
struct device *dev = &dsi->dev;
struct s6e3ha2 *ctx;
int ret;
ctx = devm_kzalloc(dev, sizeof(*ctx), GFP_KERNEL);
if (!ctx)
return -ENOMEM;
mipi_dsi_set_drvdata(dsi, ctx);
ctx->dev = dev;
dsi->lanes = 4;
dsi->format = MIPI_DSI_FMT_RGB888;
dsi->mode_flags = MIPI_DSI_CLOCK_NON_CONTINUOUS;
ctx->supplies[0].supply = "vdd3";
ctx->supplies[1].supply = "vci";
ret = devm_regulator_bulk_get(dev, ARRAY_SIZE(ctx->supplies),
ctx->supplies);
if (ret < 0) {
dev_err(dev, "failed to get regulators: %d\n", ret);
return ret;
}
ctx->reset_gpio = devm_gpiod_get(dev, "reset", GPIOD_OUT_LOW);
if (IS_ERR(ctx->reset_gpio)) {
dev_err(dev, "cannot get reset-gpios %ld\n",
PTR_ERR(ctx->reset_gpio));
return PTR_ERR(ctx->reset_gpio);
}
ctx->enable_gpio = devm_gpiod_get(dev, "enable", GPIOD_OUT_HIGH);
if (IS_ERR(ctx->enable_gpio)) {
dev_err(dev, "cannot get enable-gpios %ld\n",
PTR_ERR(ctx->enable_gpio));
return PTR_ERR(ctx->enable_gpio);
}
ctx->bl_dev = backlight_device_register("s6e3ha2", dev, ctx,
&s6e3ha2_bl_ops, NULL);
if (IS_ERR(ctx->bl_dev)) {
dev_err(dev, "failed to register backlight device\n");
return PTR_ERR(ctx->bl_dev);
}
ctx->bl_dev->props.max_brightness = S6E3HA2_MAX_BRIGHTNESS;
ctx->bl_dev->props.brightness = S6E3HA2_DEFAULT_BRIGHTNESS;
ctx->bl_dev->props.power = FB_BLANK_POWERDOWN;
drm_panel_init(&ctx->panel);
ctx->panel.dev = dev;
ctx->panel.funcs = &s6e3ha2_drm_funcs;
ret = drm_panel_add(&ctx->panel);
if (ret < 0)
goto unregister_backlight;
ret = mipi_dsi_attach(dsi);
if (ret < 0)
goto remove_panel;
return ret;
remove_panel:
drm_panel_remove(&ctx->panel);
unregister_backlight:
backlight_device_unregister(ctx->bl_dev);
return ret;
}
static int s6e3ha2_remove(struct mipi_dsi_device *dsi)
{
struct s6e3ha2 *ctx = mipi_dsi_get_drvdata(dsi);
mipi_dsi_detach(dsi);
drm_panel_remove(&ctx->panel);
backlight_device_unregister(ctx->bl_dev);
return 0;
}
