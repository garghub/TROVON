static inline struct sharp_nt_panel *to_sharp_nt_panel(struct drm_panel *panel)
{
return container_of(panel, struct sharp_nt_panel, base);
}
static int sharp_nt_panel_init(struct sharp_nt_panel *sharp_nt)
{
struct mipi_dsi_device *dsi = sharp_nt->dsi;
int ret;
dsi->mode_flags |= MIPI_DSI_MODE_LPM;
ret = mipi_dsi_dcs_exit_sleep_mode(dsi);
if (ret < 0)
return ret;
msleep(120);
ret = mipi_dsi_dcs_write(dsi, 0xae, (u8[]){ 0x03 }, 1);
if (ret < 0)
return ret;
ret = mipi_dsi_dcs_set_pixel_format(dsi, MIPI_DCS_PIXEL_FMT_24BIT |
(MIPI_DCS_PIXEL_FMT_24BIT << 4));
if (ret < 0)
return ret;
return 0;
}
static int sharp_nt_panel_on(struct sharp_nt_panel *sharp_nt)
{
struct mipi_dsi_device *dsi = sharp_nt->dsi;
int ret;
dsi->mode_flags |= MIPI_DSI_MODE_LPM;
ret = mipi_dsi_dcs_set_display_on(dsi);
if (ret < 0)
return ret;
return 0;
}
static int sharp_nt_panel_off(struct sharp_nt_panel *sharp_nt)
{
struct mipi_dsi_device *dsi = sharp_nt->dsi;
int ret;
dsi->mode_flags &= ~MIPI_DSI_MODE_LPM;
ret = mipi_dsi_dcs_set_display_off(dsi);
if (ret < 0)
return ret;
ret = mipi_dsi_dcs_enter_sleep_mode(dsi);
if (ret < 0)
return ret;
return 0;
}
static int sharp_nt_panel_disable(struct drm_panel *panel)
{
struct sharp_nt_panel *sharp_nt = to_sharp_nt_panel(panel);
if (!sharp_nt->enabled)
return 0;
if (sharp_nt->backlight) {
sharp_nt->backlight->props.power = FB_BLANK_POWERDOWN;
backlight_update_status(sharp_nt->backlight);
}
sharp_nt->enabled = false;
return 0;
}
static int sharp_nt_panel_unprepare(struct drm_panel *panel)
{
struct sharp_nt_panel *sharp_nt = to_sharp_nt_panel(panel);
int ret;
if (!sharp_nt->prepared)
return 0;
ret = sharp_nt_panel_off(sharp_nt);
if (ret < 0) {
dev_err(panel->dev, "failed to set panel off: %d\n", ret);
return ret;
}
regulator_disable(sharp_nt->supply);
if (sharp_nt->reset_gpio)
gpiod_set_value(sharp_nt->reset_gpio, 0);
sharp_nt->prepared = false;
return 0;
}
static int sharp_nt_panel_prepare(struct drm_panel *panel)
{
struct sharp_nt_panel *sharp_nt = to_sharp_nt_panel(panel);
int ret;
if (sharp_nt->prepared)
return 0;
ret = regulator_enable(sharp_nt->supply);
if (ret < 0)
return ret;
msleep(20);
if (sharp_nt->reset_gpio) {
gpiod_set_value(sharp_nt->reset_gpio, 1);
msleep(1);
gpiod_set_value(sharp_nt->reset_gpio, 0);
msleep(1);
gpiod_set_value(sharp_nt->reset_gpio, 1);
msleep(10);
}
ret = sharp_nt_panel_init(sharp_nt);
if (ret < 0) {
dev_err(panel->dev, "failed to init panel: %d\n", ret);
goto poweroff;
}
ret = sharp_nt_panel_on(sharp_nt);
if (ret < 0) {
dev_err(panel->dev, "failed to set panel on: %d\n", ret);
goto poweroff;
}
sharp_nt->prepared = true;
return 0;
poweroff:
regulator_disable(sharp_nt->supply);
if (sharp_nt->reset_gpio)
gpiod_set_value(sharp_nt->reset_gpio, 0);
return ret;
}
static int sharp_nt_panel_enable(struct drm_panel *panel)
{
struct sharp_nt_panel *sharp_nt = to_sharp_nt_panel(panel);
if (sharp_nt->enabled)
return 0;
if (sharp_nt->backlight) {
sharp_nt->backlight->props.power = FB_BLANK_UNBLANK;
backlight_update_status(sharp_nt->backlight);
}
sharp_nt->enabled = true;
return 0;
}
static int sharp_nt_panel_get_modes(struct drm_panel *panel)
{
struct drm_display_mode *mode;
mode = drm_mode_duplicate(panel->drm, &default_mode);
if (!mode) {
dev_err(panel->drm->dev, "failed to add mode %ux%ux@%u\n",
default_mode.hdisplay, default_mode.vdisplay,
default_mode.vrefresh);
return -ENOMEM;
}
drm_mode_set_name(mode);
drm_mode_probed_add(panel->connector, mode);
panel->connector->display_info.width_mm = 54;
panel->connector->display_info.height_mm = 95;
return 1;
}
static int sharp_nt_panel_add(struct sharp_nt_panel *sharp_nt)
{
struct device *dev = &sharp_nt->dsi->dev;
struct device_node *np;
int ret;
sharp_nt->mode = &default_mode;
sharp_nt->supply = devm_regulator_get(dev, "avdd");
if (IS_ERR(sharp_nt->supply))
return PTR_ERR(sharp_nt->supply);
sharp_nt->reset_gpio = devm_gpiod_get(dev, "reset", GPIOD_OUT_LOW);
if (IS_ERR(sharp_nt->reset_gpio)) {
dev_err(dev, "cannot get reset-gpios %ld\n",
PTR_ERR(sharp_nt->reset_gpio));
sharp_nt->reset_gpio = NULL;
} else {
gpiod_set_value(sharp_nt->reset_gpio, 0);
}
np = of_parse_phandle(dev->of_node, "backlight", 0);
if (np) {
sharp_nt->backlight = of_find_backlight_by_node(np);
of_node_put(np);
if (!sharp_nt->backlight)
return -EPROBE_DEFER;
}
drm_panel_init(&sharp_nt->base);
sharp_nt->base.funcs = &sharp_nt_panel_funcs;
sharp_nt->base.dev = &sharp_nt->dsi->dev;
ret = drm_panel_add(&sharp_nt->base);
if (ret < 0)
goto put_backlight;
return 0;
put_backlight:
if (sharp_nt->backlight)
put_device(&sharp_nt->backlight->dev);
return ret;
}
static void sharp_nt_panel_del(struct sharp_nt_panel *sharp_nt)
{
if (sharp_nt->base.dev)
drm_panel_remove(&sharp_nt->base);
if (sharp_nt->backlight)
put_device(&sharp_nt->backlight->dev);
}
static int sharp_nt_panel_probe(struct mipi_dsi_device *dsi)
{
struct sharp_nt_panel *sharp_nt;
int ret;
dsi->lanes = 2;
dsi->format = MIPI_DSI_FMT_RGB888;
dsi->mode_flags = MIPI_DSI_MODE_VIDEO |
MIPI_DSI_MODE_VIDEO_HSE |
MIPI_DSI_CLOCK_NON_CONTINUOUS |
MIPI_DSI_MODE_EOT_PACKET;
sharp_nt = devm_kzalloc(&dsi->dev, sizeof(*sharp_nt), GFP_KERNEL);
if (!sharp_nt)
return -ENOMEM;
mipi_dsi_set_drvdata(dsi, sharp_nt);
sharp_nt->dsi = dsi;
ret = sharp_nt_panel_add(sharp_nt);
if (ret < 0)
return ret;
return mipi_dsi_attach(dsi);
}
static int sharp_nt_panel_remove(struct mipi_dsi_device *dsi)
{
struct sharp_nt_panel *sharp_nt = mipi_dsi_get_drvdata(dsi);
int ret;
ret = sharp_nt_panel_disable(&sharp_nt->base);
if (ret < 0)
dev_err(&dsi->dev, "failed to disable panel: %d\n", ret);
ret = mipi_dsi_detach(dsi);
if (ret < 0)
dev_err(&dsi->dev, "failed to detach from DSI host: %d\n", ret);
drm_panel_detach(&sharp_nt->base);
sharp_nt_panel_del(sharp_nt);
return 0;
}
static void sharp_nt_panel_shutdown(struct mipi_dsi_device *dsi)
{
struct sharp_nt_panel *sharp_nt = mipi_dsi_get_drvdata(dsi);
sharp_nt_panel_disable(&sharp_nt->base);
}
