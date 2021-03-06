static inline struct panel_lvds *to_panel_lvds(struct drm_panel *panel)
{
return container_of(panel, struct panel_lvds, panel);
}
static int panel_lvds_disable(struct drm_panel *panel)
{
struct panel_lvds *lvds = to_panel_lvds(panel);
if (lvds->backlight) {
lvds->backlight->props.power = FB_BLANK_POWERDOWN;
lvds->backlight->props.state |= BL_CORE_FBBLANK;
backlight_update_status(lvds->backlight);
}
return 0;
}
static int panel_lvds_unprepare(struct drm_panel *panel)
{
struct panel_lvds *lvds = to_panel_lvds(panel);
if (lvds->enable_gpio)
gpiod_set_value_cansleep(lvds->enable_gpio, 0);
return 0;
}
static int panel_lvds_prepare(struct drm_panel *panel)
{
struct panel_lvds *lvds = to_panel_lvds(panel);
if (lvds->enable_gpio)
gpiod_set_value_cansleep(lvds->enable_gpio, 1);
return 0;
}
static int panel_lvds_enable(struct drm_panel *panel)
{
struct panel_lvds *lvds = to_panel_lvds(panel);
if (lvds->backlight) {
lvds->backlight->props.state &= ~BL_CORE_FBBLANK;
lvds->backlight->props.power = FB_BLANK_UNBLANK;
backlight_update_status(lvds->backlight);
}
return 0;
}
static int panel_lvds_get_modes(struct drm_panel *panel)
{
struct panel_lvds *lvds = to_panel_lvds(panel);
struct drm_connector *connector = lvds->panel.connector;
struct drm_display_mode *mode;
mode = drm_mode_create(lvds->panel.drm);
if (!mode)
return 0;
drm_display_mode_from_videomode(&lvds->video_mode, mode);
mode->type |= DRM_MODE_TYPE_DRIVER | DRM_MODE_TYPE_PREFERRED;
drm_mode_probed_add(connector, mode);
connector->display_info.width_mm = lvds->width;
connector->display_info.height_mm = lvds->height;
drm_display_info_set_bus_formats(&connector->display_info,
&lvds->bus_format, 1);
connector->display_info.bus_flags = lvds->data_mirror
? DRM_BUS_FLAG_DATA_LSB_TO_MSB
: DRM_BUS_FLAG_DATA_MSB_TO_LSB;
return 1;
}
static int panel_lvds_parse_dt(struct panel_lvds *lvds)
{
struct device_node *np = lvds->dev->of_node;
struct display_timing timing;
const char *mapping;
int ret;
ret = of_get_display_timing(np, "panel-timing", &timing);
if (ret < 0)
return ret;
videomode_from_timing(&timing, &lvds->video_mode);
ret = of_property_read_u32(np, "width-mm", &lvds->width);
if (ret < 0) {
dev_err(lvds->dev, "%s: invalid or missing %s DT property\n",
of_node_full_name(np), "width-mm");
return -ENODEV;
}
ret = of_property_read_u32(np, "height-mm", &lvds->height);
if (ret < 0) {
dev_err(lvds->dev, "%s: invalid or missing %s DT property\n",
of_node_full_name(np), "height-mm");
return -ENODEV;
}
of_property_read_string(np, "label", &lvds->label);
ret = of_property_read_string(np, "data-mapping", &mapping);
if (ret < 0) {
dev_err(lvds->dev, "%s: invalid or missing %s DT property\n",
of_node_full_name(np), "data-mapping");
return -ENODEV;
}
if (!strcmp(mapping, "jeida-18")) {
lvds->bus_format = MEDIA_BUS_FMT_RGB666_1X7X3_SPWG;
} else if (!strcmp(mapping, "jeida-24")) {
lvds->bus_format = MEDIA_BUS_FMT_RGB888_1X7X4_JEIDA;
} else if (!strcmp(mapping, "vesa-24")) {
lvds->bus_format = MEDIA_BUS_FMT_RGB888_1X7X4_SPWG;
} else {
dev_err(lvds->dev, "%s: invalid or missing %s DT property\n",
of_node_full_name(np), "data-mapping");
return -EINVAL;
}
lvds->data_mirror = of_property_read_bool(np, "data-mirror");
return 0;
}
static int panel_lvds_probe(struct platform_device *pdev)
{
struct panel_lvds *lvds;
struct device_node *np;
int ret;
lvds = devm_kzalloc(&pdev->dev, sizeof(*lvds), GFP_KERNEL);
if (!lvds)
return -ENOMEM;
lvds->dev = &pdev->dev;
ret = panel_lvds_parse_dt(lvds);
if (ret < 0)
return ret;
lvds->enable_gpio = devm_gpiod_get_optional(lvds->dev, "enable",
GPIOD_OUT_LOW);
if (IS_ERR(lvds->enable_gpio)) {
ret = PTR_ERR(lvds->enable_gpio);
dev_err(lvds->dev, "failed to request %s GPIO: %d\n",
"enable", ret);
return ret;
}
lvds->reset_gpio = devm_gpiod_get_optional(lvds->dev, "reset",
GPIOD_OUT_HIGH);
if (IS_ERR(lvds->reset_gpio)) {
ret = PTR_ERR(lvds->reset_gpio);
dev_err(lvds->dev, "failed to request %s GPIO: %d\n",
"reset", ret);
return ret;
}
np = of_parse_phandle(lvds->dev->of_node, "backlight", 0);
if (np) {
lvds->backlight = of_find_backlight_by_node(np);
of_node_put(np);
if (!lvds->backlight)
return -EPROBE_DEFER;
}
drm_panel_init(&lvds->panel);
lvds->panel.dev = lvds->dev;
lvds->panel.funcs = &panel_lvds_funcs;
ret = drm_panel_add(&lvds->panel);
if (ret < 0)
goto error;
dev_set_drvdata(lvds->dev, lvds);
return 0;
error:
put_device(&lvds->backlight->dev);
return ret;
}
static int panel_lvds_remove(struct platform_device *pdev)
{
struct panel_lvds *lvds = dev_get_drvdata(&pdev->dev);
drm_panel_detach(&lvds->panel);
drm_panel_remove(&lvds->panel);
panel_lvds_disable(&lvds->panel);
if (lvds->backlight)
put_device(&lvds->backlight->dev);
return 0;
}
