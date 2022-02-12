static ssize_t display_output_type_show(struct device *dev,
struct device_attribute *attr, char *buf)
{
struct omap_dss_device *dssdev = to_dss_device(dev);
const char *ret;
switch (dssdev->phy.venc.type) {
case OMAP_DSS_VENC_TYPE_COMPOSITE:
ret = "composite";
break;
case OMAP_DSS_VENC_TYPE_SVIDEO:
ret = "svideo";
break;
default:
return -EINVAL;
}
return snprintf(buf, PAGE_SIZE, "%s\n", ret);
}
static ssize_t display_output_type_store(struct device *dev,
struct device_attribute *attr, const char *buf, size_t size)
{
struct omap_dss_device *dssdev = to_dss_device(dev);
enum omap_dss_venc_type new_type;
if (sysfs_streq("composite", buf))
new_type = OMAP_DSS_VENC_TYPE_COMPOSITE;
else if (sysfs_streq("svideo", buf))
new_type = OMAP_DSS_VENC_TYPE_SVIDEO;
else
return -EINVAL;
mutex_lock(&venc_panel.lock);
if (dssdev->phy.venc.type != new_type) {
dssdev->phy.venc.type = new_type;
omapdss_venc_set_type(dssdev, new_type);
if (dssdev->state == OMAP_DSS_DISPLAY_ACTIVE) {
omapdss_venc_display_disable(dssdev);
omapdss_venc_display_enable(dssdev);
}
}
mutex_unlock(&venc_panel.lock);
return size;
}
static int venc_panel_probe(struct omap_dss_device *dssdev)
{
const struct omap_video_timings default_timings = {
.x_res = 720,
.y_res = 574,
.pixel_clock = 13500,
.hsw = 64,
.hfp = 12,
.hbp = 68,
.vsw = 5,
.vfp = 5,
.vbp = 41,
.vsync_level = OMAPDSS_SIG_ACTIVE_HIGH,
.hsync_level = OMAPDSS_SIG_ACTIVE_HIGH,
.interlace = true,
};
mutex_init(&venc_panel.lock);
dssdev->panel.timings = default_timings;
return device_create_file(&dssdev->dev, &dev_attr_output_type);
}
static void venc_panel_remove(struct omap_dss_device *dssdev)
{
device_remove_file(&dssdev->dev, &dev_attr_output_type);
}
static int venc_panel_enable(struct omap_dss_device *dssdev)
{
int r;
dev_dbg(&dssdev->dev, "venc_panel_enable\n");
mutex_lock(&venc_panel.lock);
if (dssdev->state != OMAP_DSS_DISPLAY_DISABLED) {
r = -EINVAL;
goto err;
}
omapdss_venc_set_timings(dssdev, &dssdev->panel.timings);
omapdss_venc_set_type(dssdev, dssdev->phy.venc.type);
omapdss_venc_invert_vid_out_polarity(dssdev,
dssdev->phy.venc.invert_polarity);
r = omapdss_venc_display_enable(dssdev);
if (r)
goto err;
dssdev->state = OMAP_DSS_DISPLAY_ACTIVE;
mutex_unlock(&venc_panel.lock);
return 0;
err:
mutex_unlock(&venc_panel.lock);
return r;
}
static void venc_panel_disable(struct omap_dss_device *dssdev)
{
dev_dbg(&dssdev->dev, "venc_panel_disable\n");
mutex_lock(&venc_panel.lock);
if (dssdev->state == OMAP_DSS_DISPLAY_DISABLED)
goto end;
omapdss_venc_display_disable(dssdev);
dssdev->state = OMAP_DSS_DISPLAY_DISABLED;
end:
mutex_unlock(&venc_panel.lock);
}
static void venc_panel_set_timings(struct omap_dss_device *dssdev,
struct omap_video_timings *timings)
{
dev_dbg(&dssdev->dev, "venc_panel_set_timings\n");
mutex_lock(&venc_panel.lock);
omapdss_venc_set_timings(dssdev, timings);
dssdev->panel.timings = *timings;
mutex_unlock(&venc_panel.lock);
}
static int venc_panel_check_timings(struct omap_dss_device *dssdev,
struct omap_video_timings *timings)
{
dev_dbg(&dssdev->dev, "venc_panel_check_timings\n");
return omapdss_venc_check_timings(dssdev, timings);
}
static u32 venc_panel_get_wss(struct omap_dss_device *dssdev)
{
dev_dbg(&dssdev->dev, "venc_panel_get_wss\n");
return omapdss_venc_get_wss(dssdev);
}
static int venc_panel_set_wss(struct omap_dss_device *dssdev, u32 wss)
{
dev_dbg(&dssdev->dev, "venc_panel_set_wss\n");
return omapdss_venc_set_wss(dssdev, wss);
}
int venc_panel_init(void)
{
return omap_dss_register_driver(&venc_driver);
}
void venc_panel_exit(void)
{
omap_dss_unregister_driver(&venc_driver);
}
