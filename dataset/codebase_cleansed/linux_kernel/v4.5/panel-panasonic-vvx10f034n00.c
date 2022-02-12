static inline struct wuxga_nt_panel *to_wuxga_nt_panel(struct drm_panel *panel)
{
return container_of(panel, struct wuxga_nt_panel, base);
}
static int wuxga_nt_panel_on(struct wuxga_nt_panel *wuxga_nt)
{
struct mipi_dsi_device *dsi = wuxga_nt->dsi;
int ret;
ret = mipi_dsi_turn_on_peripheral(dsi);
if (ret < 0)
return ret;
return 0;
}
static int wuxga_nt_panel_disable(struct drm_panel *panel)
{
struct wuxga_nt_panel *wuxga_nt = to_wuxga_nt_panel(panel);
if (!wuxga_nt->enabled)
return 0;
mipi_dsi_shutdown_peripheral(wuxga_nt->dsi);
if (wuxga_nt->backlight) {
wuxga_nt->backlight->props.power = FB_BLANK_POWERDOWN;
wuxga_nt->backlight->props.state |= BL_CORE_FBBLANK;
backlight_update_status(wuxga_nt->backlight);
}
wuxga_nt->enabled = false;
return 0;
}
static int wuxga_nt_panel_unprepare(struct drm_panel *panel)
{
struct wuxga_nt_panel *wuxga_nt = to_wuxga_nt_panel(panel);
if (!wuxga_nt->prepared)
return 0;
regulator_disable(wuxga_nt->supply);
wuxga_nt->earliest_wake = ktime_add_ms(ktime_get_real(), MIN_POFF_MS);
wuxga_nt->prepared = false;
return 0;
}
static int wuxga_nt_panel_prepare(struct drm_panel *panel)
{
struct wuxga_nt_panel *wuxga_nt = to_wuxga_nt_panel(panel);
int ret;
s64 enablewait;
if (wuxga_nt->prepared)
return 0;
enablewait = ktime_ms_delta(wuxga_nt->earliest_wake, ktime_get_real());
if (enablewait > MIN_POFF_MS)
enablewait = MIN_POFF_MS;
if (enablewait > 0)
msleep(enablewait);
ret = regulator_enable(wuxga_nt->supply);
if (ret < 0)
return ret;
msleep(250);
ret = wuxga_nt_panel_on(wuxga_nt);
if (ret < 0) {
dev_err(panel->dev, "failed to set panel on: %d\n", ret);
goto poweroff;
}
wuxga_nt->prepared = true;
return 0;
poweroff:
regulator_disable(wuxga_nt->supply);
return ret;
}
static int wuxga_nt_panel_enable(struct drm_panel *panel)
{
struct wuxga_nt_panel *wuxga_nt = to_wuxga_nt_panel(panel);
if (wuxga_nt->enabled)
return 0;
if (wuxga_nt->backlight) {
wuxga_nt->backlight->props.power = FB_BLANK_UNBLANK;
wuxga_nt->backlight->props.state &= ~BL_CORE_FBBLANK;
backlight_update_status(wuxga_nt->backlight);
}
wuxga_nt->enabled = true;
return 0;
}
static int wuxga_nt_panel_get_modes(struct drm_panel *panel)
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
panel->connector->display_info.width_mm = 217;
panel->connector->display_info.height_mm = 136;
return 1;
}
static int wuxga_nt_panel_add(struct wuxga_nt_panel *wuxga_nt)
{
struct device *dev = &wuxga_nt->dsi->dev;
struct device_node *np;
int ret;
wuxga_nt->mode = &default_mode;
wuxga_nt->supply = devm_regulator_get(dev, "power");
if (IS_ERR(wuxga_nt->supply))
return PTR_ERR(wuxga_nt->supply);
np = of_parse_phandle(dev->of_node, "backlight", 0);
if (np) {
wuxga_nt->backlight = of_find_backlight_by_node(np);
of_node_put(np);
if (!wuxga_nt->backlight)
return -EPROBE_DEFER;
}
drm_panel_init(&wuxga_nt->base);
wuxga_nt->base.funcs = &wuxga_nt_panel_funcs;
wuxga_nt->base.dev = &wuxga_nt->dsi->dev;
ret = drm_panel_add(&wuxga_nt->base);
if (ret < 0)
goto put_backlight;
return 0;
put_backlight:
if (wuxga_nt->backlight)
put_device(&wuxga_nt->backlight->dev);
return ret;
}
static void wuxga_nt_panel_del(struct wuxga_nt_panel *wuxga_nt)
{
if (wuxga_nt->base.dev)
drm_panel_remove(&wuxga_nt->base);
if (wuxga_nt->backlight)
put_device(&wuxga_nt->backlight->dev);
}
static int wuxga_nt_panel_probe(struct mipi_dsi_device *dsi)
{
struct wuxga_nt_panel *wuxga_nt;
int ret;
dsi->lanes = 4;
dsi->format = MIPI_DSI_FMT_RGB888;
dsi->mode_flags = MIPI_DSI_MODE_VIDEO |
MIPI_DSI_MODE_VIDEO_HSE |
MIPI_DSI_CLOCK_NON_CONTINUOUS |
MIPI_DSI_MODE_LPM;
wuxga_nt = devm_kzalloc(&dsi->dev, sizeof(*wuxga_nt), GFP_KERNEL);
if (!wuxga_nt)
return -ENOMEM;
mipi_dsi_set_drvdata(dsi, wuxga_nt);
wuxga_nt->dsi = dsi;
ret = wuxga_nt_panel_add(wuxga_nt);
if (ret < 0)
return ret;
return mipi_dsi_attach(dsi);
}
static int wuxga_nt_panel_remove(struct mipi_dsi_device *dsi)
{
struct wuxga_nt_panel *wuxga_nt = mipi_dsi_get_drvdata(dsi);
int ret;
ret = wuxga_nt_panel_disable(&wuxga_nt->base);
if (ret < 0)
dev_err(&dsi->dev, "failed to disable panel: %d\n", ret);
ret = mipi_dsi_detach(dsi);
if (ret < 0)
dev_err(&dsi->dev, "failed to detach from DSI host: %d\n", ret);
drm_panel_detach(&wuxga_nt->base);
wuxga_nt_panel_del(wuxga_nt);
return 0;
}
static void wuxga_nt_panel_shutdown(struct mipi_dsi_device *dsi)
{
struct wuxga_nt_panel *wuxga_nt = mipi_dsi_get_drvdata(dsi);
wuxga_nt_panel_disable(&wuxga_nt->base);
}
