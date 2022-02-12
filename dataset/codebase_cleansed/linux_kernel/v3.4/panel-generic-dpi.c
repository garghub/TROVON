static inline struct panel_generic_dpi_data
*get_panel_data(const struct omap_dss_device *dssdev)
{
return (struct panel_generic_dpi_data *) dssdev->data;
}
static int generic_dpi_panel_power_on(struct omap_dss_device *dssdev)
{
int r;
struct panel_generic_dpi_data *panel_data = get_panel_data(dssdev);
struct panel_drv_data *drv_data = dev_get_drvdata(&dssdev->dev);
struct panel_config *panel_config = drv_data->panel_config;
if (dssdev->state == OMAP_DSS_DISPLAY_ACTIVE)
return 0;
r = omapdss_dpi_display_enable(dssdev);
if (r)
goto err0;
if (panel_config->power_on_delay)
msleep(panel_config->power_on_delay);
if (panel_data->platform_enable) {
r = panel_data->platform_enable(dssdev);
if (r)
goto err1;
}
return 0;
err1:
omapdss_dpi_display_disable(dssdev);
err0:
return r;
}
static void generic_dpi_panel_power_off(struct omap_dss_device *dssdev)
{
struct panel_generic_dpi_data *panel_data = get_panel_data(dssdev);
struct panel_drv_data *drv_data = dev_get_drvdata(&dssdev->dev);
struct panel_config *panel_config = drv_data->panel_config;
if (dssdev->state != OMAP_DSS_DISPLAY_ACTIVE)
return;
if (panel_data->platform_disable)
panel_data->platform_disable(dssdev);
if (panel_config->power_off_delay)
msleep(panel_config->power_off_delay);
omapdss_dpi_display_disable(dssdev);
}
static int generic_dpi_panel_probe(struct omap_dss_device *dssdev)
{
struct panel_generic_dpi_data *panel_data = get_panel_data(dssdev);
struct panel_config *panel_config = NULL;
struct panel_drv_data *drv_data = NULL;
int i;
dev_dbg(&dssdev->dev, "probe\n");
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
dssdev->panel.config = panel_config->config;
dssdev->panel.timings = panel_config->timings;
dssdev->panel.acb = panel_config->acb;
dssdev->panel.acbi = panel_config->acbi;
drv_data = kzalloc(sizeof(*drv_data), GFP_KERNEL);
if (!drv_data)
return -ENOMEM;
drv_data->dssdev = dssdev;
drv_data->panel_config = panel_config;
dev_set_drvdata(&dssdev->dev, drv_data);
return 0;
}
static void __exit generic_dpi_panel_remove(struct omap_dss_device *dssdev)
{
struct panel_drv_data *drv_data = dev_get_drvdata(&dssdev->dev);
dev_dbg(&dssdev->dev, "remove\n");
kfree(drv_data);
dev_set_drvdata(&dssdev->dev, NULL);
}
static int generic_dpi_panel_enable(struct omap_dss_device *dssdev)
{
int r = 0;
r = generic_dpi_panel_power_on(dssdev);
if (r)
return r;
dssdev->state = OMAP_DSS_DISPLAY_ACTIVE;
return 0;
}
static void generic_dpi_panel_disable(struct omap_dss_device *dssdev)
{
generic_dpi_panel_power_off(dssdev);
dssdev->state = OMAP_DSS_DISPLAY_DISABLED;
}
static int generic_dpi_panel_suspend(struct omap_dss_device *dssdev)
{
generic_dpi_panel_power_off(dssdev);
dssdev->state = OMAP_DSS_DISPLAY_SUSPENDED;
return 0;
}
static int generic_dpi_panel_resume(struct omap_dss_device *dssdev)
{
int r = 0;
r = generic_dpi_panel_power_on(dssdev);
if (r)
return r;
dssdev->state = OMAP_DSS_DISPLAY_ACTIVE;
return 0;
}
static void generic_dpi_panel_set_timings(struct omap_dss_device *dssdev,
struct omap_video_timings *timings)
{
dpi_set_timings(dssdev, timings);
}
static void generic_dpi_panel_get_timings(struct omap_dss_device *dssdev,
struct omap_video_timings *timings)
{
*timings = dssdev->panel.timings;
}
static int generic_dpi_panel_check_timings(struct omap_dss_device *dssdev,
struct omap_video_timings *timings)
{
return dpi_check_timings(dssdev, timings);
}
static int __init generic_dpi_panel_drv_init(void)
{
return omap_dss_register_driver(&dpi_driver);
}
static void __exit generic_dpi_panel_drv_exit(void)
{
omap_dss_unregister_driver(&dpi_driver);
}
