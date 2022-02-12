static inline struct innolux_panel *to_innolux_panel(struct drm_panel *panel)
{
return container_of(panel, struct innolux_panel, base);
}
static int innolux_panel_disable(struct drm_panel *panel)
{
struct innolux_panel *innolux = to_innolux_panel(panel);
int err;
if (!innolux->enabled)
return 0;
innolux->backlight->props.power = FB_BLANK_POWERDOWN;
backlight_update_status(innolux->backlight);
err = mipi_dsi_dcs_set_display_off(innolux->link);
if (err < 0)
DRM_DEV_ERROR(panel->dev, "failed to set display off: %d\n",
err);
innolux->enabled = false;
return 0;
}
static int innolux_panel_unprepare(struct drm_panel *panel)
{
struct innolux_panel *innolux = to_innolux_panel(panel);
int err;
if (!innolux->prepared)
return 0;
err = mipi_dsi_dcs_enter_sleep_mode(innolux->link);
if (err < 0) {
DRM_DEV_ERROR(panel->dev, "failed to enter sleep mode: %d\n",
err);
return err;
}
gpiod_set_value_cansleep(innolux->enable_gpio, 0);
msleep(80);
err = regulator_disable(innolux->supply);
if (err < 0)
return err;
innolux->prepared = false;
return 0;
}
static int innolux_panel_prepare(struct drm_panel *panel)
{
struct innolux_panel *innolux = to_innolux_panel(panel);
int err, regulator_err;
if (innolux->prepared)
return 0;
gpiod_set_value_cansleep(innolux->enable_gpio, 0);
err = regulator_enable(innolux->supply);
if (err < 0)
return err;
usleep_range(15000, 16000);
gpiod_set_value_cansleep(innolux->enable_gpio, 1);
usleep_range(15000, 16000);
err = mipi_dsi_dcs_exit_sleep_mode(innolux->link);
if (err < 0) {
DRM_DEV_ERROR(panel->dev, "failed to exit sleep mode: %d\n",
err);
goto poweroff;
}
msleep(120);
err = mipi_dsi_dcs_set_display_on(innolux->link);
if (err < 0) {
DRM_DEV_ERROR(panel->dev, "failed to set display on: %d\n",
err);
goto poweroff;
}
usleep_range(5000, 6000);
innolux->prepared = true;
return 0;
poweroff:
regulator_err = regulator_disable(innolux->supply);
if (regulator_err)
DRM_DEV_ERROR(panel->dev, "failed to disable regulator: %d\n",
regulator_err);
gpiod_set_value_cansleep(innolux->enable_gpio, 0);
return err;
}
static int innolux_panel_enable(struct drm_panel *panel)
{
struct innolux_panel *innolux = to_innolux_panel(panel);
int ret;
if (innolux->enabled)
return 0;
innolux->backlight->props.power = FB_BLANK_UNBLANK;
ret = backlight_update_status(innolux->backlight);
if (ret) {
DRM_DEV_ERROR(panel->drm->dev,
"Failed to enable backlight %d\n", ret);
return ret;
}
innolux->enabled = true;
return 0;
}
static int innolux_panel_get_modes(struct drm_panel *panel)
{
struct drm_display_mode *mode;
mode = drm_mode_duplicate(panel->drm, &default_mode);
if (!mode) {
DRM_DEV_ERROR(panel->drm->dev, "failed to add mode %ux%ux@%u\n",
default_mode.hdisplay, default_mode.vdisplay,
default_mode.vrefresh);
return -ENOMEM;
}
drm_mode_set_name(mode);
drm_mode_probed_add(panel->connector, mode);
panel->connector->display_info.width_mm = 120;
panel->connector->display_info.height_mm = 160;
panel->connector->display_info.bpc = 8;
return 1;
}
static int innolux_panel_add(struct innolux_panel *innolux)
{
struct device *dev = &innolux->link->dev;
struct device_node *np;
int err;
innolux->supply = devm_regulator_get(dev, "power");
if (IS_ERR(innolux->supply))
return PTR_ERR(innolux->supply);
innolux->enable_gpio = devm_gpiod_get_optional(dev, "enable",
GPIOD_OUT_HIGH);
if (IS_ERR(innolux->enable_gpio)) {
err = PTR_ERR(innolux->enable_gpio);
dev_dbg(dev, "failed to get enable gpio: %d\n", err);
innolux->enable_gpio = NULL;
}
np = of_parse_phandle(dev->of_node, "backlight", 0);
if (np) {
innolux->backlight = of_find_backlight_by_node(np);
of_node_put(np);
if (!innolux->backlight)
return -EPROBE_DEFER;
}
drm_panel_init(&innolux->base);
innolux->base.funcs = &innolux_panel_funcs;
innolux->base.dev = &innolux->link->dev;
err = drm_panel_add(&innolux->base);
if (err < 0)
goto put_backlight;
return 0;
put_backlight:
put_device(&innolux->backlight->dev);
return err;
}
static void innolux_panel_del(struct innolux_panel *innolux)
{
if (innolux->base.dev)
drm_panel_remove(&innolux->base);
put_device(&innolux->backlight->dev);
}
static int innolux_panel_probe(struct mipi_dsi_device *dsi)
{
struct innolux_panel *innolux;
int err;
dsi->lanes = 4;
dsi->format = MIPI_DSI_FMT_RGB888;
dsi->mode_flags = MIPI_DSI_MODE_VIDEO | MIPI_DSI_MODE_VIDEO_SYNC_PULSE |
MIPI_DSI_MODE_LPM;
innolux = devm_kzalloc(&dsi->dev, sizeof(*innolux), GFP_KERNEL);
if (!innolux)
return -ENOMEM;
mipi_dsi_set_drvdata(dsi, innolux);
innolux->link = dsi;
err = innolux_panel_add(innolux);
if (err < 0)
return err;
err = mipi_dsi_attach(dsi);
return err;
}
static int innolux_panel_remove(struct mipi_dsi_device *dsi)
{
struct innolux_panel *innolux = mipi_dsi_get_drvdata(dsi);
int err;
err = innolux_panel_unprepare(&innolux->base);
if (err < 0)
DRM_DEV_ERROR(&dsi->dev, "failed to unprepare panel: %d\n",
err);
err = innolux_panel_disable(&innolux->base);
if (err < 0)
DRM_DEV_ERROR(&dsi->dev, "failed to disable panel: %d\n", err);
err = mipi_dsi_detach(dsi);
if (err < 0)
DRM_DEV_ERROR(&dsi->dev, "failed to detach from DSI host: %d\n",
err);
drm_panel_detach(&innolux->base);
innolux_panel_del(innolux);
return 0;
}
static void innolux_panel_shutdown(struct mipi_dsi_device *dsi)
{
struct innolux_panel *innolux = mipi_dsi_get_drvdata(dsi);
innolux_panel_unprepare(&innolux->base);
innolux_panel_disable(&innolux->base);
}
