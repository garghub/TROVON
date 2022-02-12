static inline struct panel_generic_dpi_data
*get_panel_data(const struct omap_dss_device *dssdev)
{
return (struct panel_generic_dpi_data *) dssdev->data;
}
static int generic_dpi_panel_power_on(struct omap_dss_device *dssdev)
{
int r, i;
struct panel_generic_dpi_data *panel_data = get_panel_data(dssdev);
struct panel_drv_data *drv_data = dev_get_drvdata(dssdev->dev);
struct panel_config *panel_config = drv_data->panel_config;
if (dssdev->state == OMAP_DSS_DISPLAY_ACTIVE)
return 0;
omapdss_dpi_set_timings(dssdev, &dssdev->panel.timings);
omapdss_dpi_set_data_lines(dssdev, dssdev->phy.dpi.data_lines);
r = omapdss_dpi_display_enable(dssdev);
if (r)
goto err0;
if (panel_config->power_on_delay)
msleep(panel_config->power_on_delay);
for (i = 0; i < panel_data->num_gpios; ++i) {
gpio_set_value_cansleep(panel_data->gpios[i],
panel_data->gpio_invert[i] ? 0 : 1);
}
return 0;
err0:
return r;
}
static void generic_dpi_panel_power_off(struct omap_dss_device *dssdev)
{
struct panel_generic_dpi_data *panel_data = get_panel_data(dssdev);
struct panel_drv_data *drv_data = dev_get_drvdata(dssdev->dev);
struct panel_config *panel_config = drv_data->panel_config;
int i;
if (dssdev->state != OMAP_DSS_DISPLAY_ACTIVE)
return;
for (i = panel_data->num_gpios - 1; i >= 0; --i) {
gpio_set_value_cansleep(panel_data->gpios[i],
panel_data->gpio_invert[i] ? 1 : 0);
}
if (panel_config->power_off_delay)
msleep(panel_config->power_off_delay);
omapdss_dpi_display_disable(dssdev);
}
static int generic_dpi_panel_probe(struct omap_dss_device *dssdev)
{
struct panel_generic_dpi_data *panel_data = get_panel_data(dssdev);
struct panel_config *panel_config = NULL;
struct panel_drv_data *drv_data = NULL;
int i, r;
dev_dbg(dssdev->dev, "probe\n");
if (!panel_data || !panel_data->name)
return -EINVAL;
for (i = 0; i < ARRAY_SIZE(generic_dpi_panels); i++) {
if (strcmp(panel_data->name, generic_dpi_panels[i].name) == 0) {
panel_config = &generic_dpi_panels[i];
break;
}
}
if (!panel_config)
return -EINVAL;
for (i = 0; i < panel_data->num_gpios; ++i) {
r = devm_gpio_request_one(dssdev->dev, panel_data->gpios[i],
panel_data->gpio_invert[i] ?
GPIOF_OUT_INIT_HIGH : GPIOF_OUT_INIT_LOW,
"panel gpio");
if (r)
return r;
}
dssdev->panel.timings = panel_config->timings;
drv_data = devm_kzalloc(dssdev->dev, sizeof(*drv_data), GFP_KERNEL);
if (!drv_data)
return -ENOMEM;
drv_data->dssdev = dssdev;
drv_data->panel_config = panel_config;
mutex_init(&drv_data->lock);
dev_set_drvdata(dssdev->dev, drv_data);
return 0;
}
static void __exit generic_dpi_panel_remove(struct omap_dss_device *dssdev)
{
dev_dbg(dssdev->dev, "remove\n");
dev_set_drvdata(dssdev->dev, NULL);
}
static int generic_dpi_panel_enable(struct omap_dss_device *dssdev)
{
struct panel_drv_data *drv_data = dev_get_drvdata(dssdev->dev);
int r;
mutex_lock(&drv_data->lock);
r = generic_dpi_panel_power_on(dssdev);
if (r)
goto err;
dssdev->state = OMAP_DSS_DISPLAY_ACTIVE;
err:
mutex_unlock(&drv_data->lock);
return r;
}
static void generic_dpi_panel_disable(struct omap_dss_device *dssdev)
{
struct panel_drv_data *drv_data = dev_get_drvdata(dssdev->dev);
mutex_lock(&drv_data->lock);
generic_dpi_panel_power_off(dssdev);
dssdev->state = OMAP_DSS_DISPLAY_DISABLED;
mutex_unlock(&drv_data->lock);
}
static void generic_dpi_panel_set_timings(struct omap_dss_device *dssdev,
struct omap_video_timings *timings)
{
struct panel_drv_data *drv_data = dev_get_drvdata(dssdev->dev);
mutex_lock(&drv_data->lock);
omapdss_dpi_set_timings(dssdev, timings);
dssdev->panel.timings = *timings;
mutex_unlock(&drv_data->lock);
}
static void generic_dpi_panel_get_timings(struct omap_dss_device *dssdev,
struct omap_video_timings *timings)
{
struct panel_drv_data *drv_data = dev_get_drvdata(dssdev->dev);
mutex_lock(&drv_data->lock);
*timings = dssdev->panel.timings;
mutex_unlock(&drv_data->lock);
}
static int generic_dpi_panel_check_timings(struct omap_dss_device *dssdev,
struct omap_video_timings *timings)
{
struct panel_drv_data *drv_data = dev_get_drvdata(dssdev->dev);
int r;
mutex_lock(&drv_data->lock);
r = dpi_check_timings(dssdev, timings);
mutex_unlock(&drv_data->lock);
return r;
}
static int __init generic_dpi_panel_drv_init(void)
{
return omap_dss_register_driver(&dpi_driver);
}
static void __exit generic_dpi_panel_drv_exit(void)
{
omap_dss_unregister_driver(&dpi_driver);
}
