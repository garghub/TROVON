void omapdss_default_get_resolution(struct omap_dss_device *dssdev,
u16 *xres, u16 *yres)
{
*xres = dssdev->panel.timings.x_res;
*yres = dssdev->panel.timings.y_res;
}
int omapdss_default_get_recommended_bpp(struct omap_dss_device *dssdev)
{
switch (dssdev->type) {
case OMAP_DISPLAY_TYPE_DPI:
if (dssdev->phy.dpi.data_lines == 24)
return 24;
else
return 16;
case OMAP_DISPLAY_TYPE_DBI:
if (dssdev->ctrl.pixel_size == 24)
return 24;
else
return 16;
case OMAP_DISPLAY_TYPE_DSI:
if (dsi_get_pixel_size(dssdev->panel.dsi_pix_fmt) > 16)
return 24;
else
return 16;
case OMAP_DISPLAY_TYPE_VENC:
case OMAP_DISPLAY_TYPE_SDI:
case OMAP_DISPLAY_TYPE_HDMI:
return 24;
default:
BUG();
return 0;
}
}
void omapdss_default_get_timings(struct omap_dss_device *dssdev,
struct omap_video_timings *timings)
{
*timings = dssdev->panel.timings;
}
static int dss_suspend_device(struct device *dev, void *data)
{
struct omap_dss_device *dssdev = to_dss_device(dev);
if (dssdev->state != OMAP_DSS_DISPLAY_ACTIVE) {
dssdev->activate_after_resume = false;
return 0;
}
dssdev->driver->disable(dssdev);
dssdev->activate_after_resume = true;
return 0;
}
int dss_suspend_all_devices(void)
{
int r;
struct bus_type *bus = dss_get_bus();
r = bus_for_each_dev(bus, NULL, NULL, dss_suspend_device);
if (r) {
dss_resume_all_devices();
return r;
}
return 0;
}
static int dss_resume_device(struct device *dev, void *data)
{
int r;
struct omap_dss_device *dssdev = to_dss_device(dev);
if (dssdev->activate_after_resume) {
r = dssdev->driver->enable(dssdev);
if (r)
return r;
}
dssdev->activate_after_resume = false;
return 0;
}
int dss_resume_all_devices(void)
{
struct bus_type *bus = dss_get_bus();
return bus_for_each_dev(bus, NULL, NULL, dss_resume_device);
}
static int dss_disable_device(struct device *dev, void *data)
{
struct omap_dss_device *dssdev = to_dss_device(dev);
if (dssdev->state != OMAP_DSS_DISPLAY_DISABLED)
dssdev->driver->disable(dssdev);
return 0;
}
void dss_disable_all_devices(void)
{
struct bus_type *bus = dss_get_bus();
bus_for_each_dev(bus, NULL, NULL, dss_disable_device);
}
void omap_dss_get_device(struct omap_dss_device *dssdev)
{
get_device(&dssdev->dev);
}
void omap_dss_put_device(struct omap_dss_device *dssdev)
{
put_device(&dssdev->dev);
}
int match(struct device *dev, void *data)
{
return 1;
}
struct omap_dss_device *omap_dss_find_device(void *data,
int (*match)(struct omap_dss_device *dssdev, void *data))
{
struct omap_dss_device *dssdev = NULL;
while ((dssdev = omap_dss_get_next_device(dssdev)) != NULL) {
if (match(dssdev, data))
return dssdev;
}
return NULL;
}
int omap_dss_start_device(struct omap_dss_device *dssdev)
{
if (!dssdev->driver) {
DSSDBG("no driver\n");
return -ENODEV;
}
if (!try_module_get(dssdev->dev.driver->owner)) {
return -ENODEV;
}
return 0;
}
void omap_dss_stop_device(struct omap_dss_device *dssdev)
{
module_put(dssdev->dev.driver->owner);
}
