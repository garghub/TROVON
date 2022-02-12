static inline struct panel_simple *to_panel_simple(struct drm_panel *panel)
{
return container_of(panel, struct panel_simple, base);
}
static int panel_simple_get_fixed_modes(struct panel_simple *panel)
{
struct drm_connector *connector = panel->base.connector;
struct drm_device *drm = panel->base.drm;
struct drm_display_mode *mode;
unsigned int i, num = 0;
if (!panel->desc)
return 0;
for (i = 0; i < panel->desc->num_modes; i++) {
const struct drm_display_mode *m = &panel->desc->modes[i];
mode = drm_mode_duplicate(drm, m);
if (!mode) {
dev_err(drm->dev, "failed to add mode %ux%u@%u\n",
m->hdisplay, m->vdisplay, m->vrefresh);
continue;
}
drm_mode_set_name(mode);
drm_mode_probed_add(connector, mode);
num++;
}
connector->display_info.bpc = panel->desc->bpc;
connector->display_info.width_mm = panel->desc->size.width;
connector->display_info.height_mm = panel->desc->size.height;
return num;
}
static int panel_simple_disable(struct drm_panel *panel)
{
struct panel_simple *p = to_panel_simple(panel);
if (!p->enabled)
return 0;
if (p->backlight) {
p->backlight->props.power = FB_BLANK_POWERDOWN;
backlight_update_status(p->backlight);
}
if (p->desc->delay.disable)
msleep(p->desc->delay.disable);
p->enabled = false;
return 0;
}
static int panel_simple_unprepare(struct drm_panel *panel)
{
struct panel_simple *p = to_panel_simple(panel);
if (!p->prepared)
return 0;
if (p->enable_gpio)
gpiod_set_value_cansleep(p->enable_gpio, 0);
regulator_disable(p->supply);
if (p->desc->delay.unprepare)
msleep(p->desc->delay.unprepare);
p->prepared = false;
return 0;
}
static int panel_simple_prepare(struct drm_panel *panel)
{
struct panel_simple *p = to_panel_simple(panel);
int err;
if (p->prepared)
return 0;
err = regulator_enable(p->supply);
if (err < 0) {
dev_err(panel->dev, "failed to enable supply: %d\n", err);
return err;
}
if (p->enable_gpio)
gpiod_set_value_cansleep(p->enable_gpio, 1);
if (p->desc->delay.prepare)
msleep(p->desc->delay.prepare);
p->prepared = true;
return 0;
}
static int panel_simple_enable(struct drm_panel *panel)
{
struct panel_simple *p = to_panel_simple(panel);
if (p->enabled)
return 0;
if (p->desc->delay.enable)
msleep(p->desc->delay.enable);
if (p->backlight) {
p->backlight->props.power = FB_BLANK_UNBLANK;
backlight_update_status(p->backlight);
}
p->enabled = true;
return 0;
}
static int panel_simple_get_modes(struct drm_panel *panel)
{
struct panel_simple *p = to_panel_simple(panel);
int num = 0;
if (p->ddc) {
struct edid *edid = drm_get_edid(panel->connector, p->ddc);
drm_mode_connector_update_edid_property(panel->connector, edid);
if (edid) {
num += drm_add_edid_modes(panel->connector, edid);
kfree(edid);
}
}
num += panel_simple_get_fixed_modes(p);
return num;
}
static int panel_simple_probe(struct device *dev, const struct panel_desc *desc)
{
struct device_node *backlight, *ddc;
struct panel_simple *panel;
int err;
panel = devm_kzalloc(dev, sizeof(*panel), GFP_KERNEL);
if (!panel)
return -ENOMEM;
panel->enabled = false;
panel->prepared = false;
panel->desc = desc;
panel->supply = devm_regulator_get(dev, "power");
if (IS_ERR(panel->supply))
return PTR_ERR(panel->supply);
panel->enable_gpio = devm_gpiod_get_optional(dev, "enable");
if (IS_ERR(panel->enable_gpio)) {
err = PTR_ERR(panel->enable_gpio);
dev_err(dev, "failed to request GPIO: %d\n", err);
return err;
}
if (panel->enable_gpio) {
err = gpiod_direction_output(panel->enable_gpio, 0);
if (err < 0) {
dev_err(dev, "failed to setup GPIO: %d\n", err);
return err;
}
}
backlight = of_parse_phandle(dev->of_node, "backlight", 0);
if (backlight) {
panel->backlight = of_find_backlight_by_node(backlight);
of_node_put(backlight);
if (!panel->backlight)
return -EPROBE_DEFER;
}
ddc = of_parse_phandle(dev->of_node, "ddc-i2c-bus", 0);
if (ddc) {
panel->ddc = of_find_i2c_adapter_by_node(ddc);
of_node_put(ddc);
if (!panel->ddc) {
err = -EPROBE_DEFER;
goto free_backlight;
}
}
drm_panel_init(&panel->base);
panel->base.dev = dev;
panel->base.funcs = &panel_simple_funcs;
err = drm_panel_add(&panel->base);
if (err < 0)
goto free_ddc;
dev_set_drvdata(dev, panel);
return 0;
free_ddc:
if (panel->ddc)
put_device(&panel->ddc->dev);
free_backlight:
if (panel->backlight)
put_device(&panel->backlight->dev);
return err;
}
static int panel_simple_remove(struct device *dev)
{
struct panel_simple *panel = dev_get_drvdata(dev);
drm_panel_detach(&panel->base);
drm_panel_remove(&panel->base);
panel_simple_disable(&panel->base);
if (panel->ddc)
put_device(&panel->ddc->dev);
if (panel->backlight)
put_device(&panel->backlight->dev);
return 0;
}
static void panel_simple_shutdown(struct device *dev)
{
struct panel_simple *panel = dev_get_drvdata(dev);
panel_simple_disable(&panel->base);
}
static int panel_simple_platform_probe(struct platform_device *pdev)
{
const struct of_device_id *id;
id = of_match_node(platform_of_match, pdev->dev.of_node);
if (!id)
return -ENODEV;
return panel_simple_probe(&pdev->dev, id->data);
}
static int panel_simple_platform_remove(struct platform_device *pdev)
{
return panel_simple_remove(&pdev->dev);
}
static void panel_simple_platform_shutdown(struct platform_device *pdev)
{
panel_simple_shutdown(&pdev->dev);
}
static int panel_simple_dsi_probe(struct mipi_dsi_device *dsi)
{
const struct panel_desc_dsi *desc;
const struct of_device_id *id;
int err;
id = of_match_node(dsi_of_match, dsi->dev.of_node);
if (!id)
return -ENODEV;
desc = id->data;
err = panel_simple_probe(&dsi->dev, &desc->desc);
if (err < 0)
return err;
dsi->mode_flags = desc->flags;
dsi->format = desc->format;
dsi->lanes = desc->lanes;
return mipi_dsi_attach(dsi);
}
static int panel_simple_dsi_remove(struct mipi_dsi_device *dsi)
{
int err;
err = mipi_dsi_detach(dsi);
if (err < 0)
dev_err(&dsi->dev, "failed to detach from DSI host: %d\n", err);
return panel_simple_remove(&dsi->dev);
}
static void panel_simple_dsi_shutdown(struct mipi_dsi_device *dsi)
{
panel_simple_shutdown(&dsi->dev);
}
static int __init panel_simple_init(void)
{
int err;
err = platform_driver_register(&panel_simple_platform_driver);
if (err < 0)
return err;
if (IS_ENABLED(CONFIG_DRM_MIPI_DSI)) {
err = mipi_dsi_driver_register(&panel_simple_dsi_driver);
if (err < 0)
return err;
}
return 0;
}
static void __exit panel_simple_exit(void)
{
if (IS_ENABLED(CONFIG_DRM_MIPI_DSI))
mipi_dsi_driver_unregister(&panel_simple_dsi_driver);
platform_driver_unregister(&panel_simple_platform_driver);
}
