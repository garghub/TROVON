static int hdmi_panel_probe(struct omap_dss_device *dssdev)
{
DSSDBG("ENTER hdmi_panel_probe\n");
dssdev->panel.config = OMAP_DSS_LCD_TFT |
OMAP_DSS_LCD_IVS | OMAP_DSS_LCD_IHS;
dssdev->panel.timings = (struct omap_video_timings){640, 480, 25175, 96, 16, 48, 2 , 11, 31};
DSSDBG("hdmi_panel_probe x_res= %d y_res = %d\n",
dssdev->panel.timings.x_res,
dssdev->panel.timings.y_res);
return 0;
}
static void hdmi_panel_remove(struct omap_dss_device *dssdev)
{
}
static int hdmi_panel_enable(struct omap_dss_device *dssdev)
{
int r = 0;
DSSDBG("ENTER hdmi_panel_enable\n");
mutex_lock(&hdmi.hdmi_lock);
if (dssdev->state != OMAP_DSS_DISPLAY_DISABLED) {
r = -EINVAL;
goto err;
}
r = omapdss_hdmi_display_enable(dssdev);
if (r) {
DSSERR("failed to power on\n");
goto err;
}
dssdev->state = OMAP_DSS_DISPLAY_ACTIVE;
err:
mutex_unlock(&hdmi.hdmi_lock);
return r;
}
static void hdmi_panel_disable(struct omap_dss_device *dssdev)
{
mutex_lock(&hdmi.hdmi_lock);
if (dssdev->state == OMAP_DSS_DISPLAY_ACTIVE)
omapdss_hdmi_display_disable(dssdev);
dssdev->state = OMAP_DSS_DISPLAY_DISABLED;
mutex_unlock(&hdmi.hdmi_lock);
}
static int hdmi_panel_suspend(struct omap_dss_device *dssdev)
{
int r = 0;
mutex_lock(&hdmi.hdmi_lock);
if (dssdev->state != OMAP_DSS_DISPLAY_ACTIVE) {
r = -EINVAL;
goto err;
}
dssdev->state = OMAP_DSS_DISPLAY_SUSPENDED;
omapdss_hdmi_display_disable(dssdev);
err:
mutex_unlock(&hdmi.hdmi_lock);
return r;
}
static int hdmi_panel_resume(struct omap_dss_device *dssdev)
{
int r = 0;
mutex_lock(&hdmi.hdmi_lock);
if (dssdev->state != OMAP_DSS_DISPLAY_SUSPENDED) {
r = -EINVAL;
goto err;
}
r = omapdss_hdmi_display_enable(dssdev);
if (r) {
DSSERR("failed to power on\n");
goto err;
}
dssdev->state = OMAP_DSS_DISPLAY_ACTIVE;
err:
mutex_unlock(&hdmi.hdmi_lock);
return r;
}
static void hdmi_get_timings(struct omap_dss_device *dssdev,
struct omap_video_timings *timings)
{
mutex_lock(&hdmi.hdmi_lock);
*timings = dssdev->panel.timings;
mutex_unlock(&hdmi.hdmi_lock);
}
static void hdmi_set_timings(struct omap_dss_device *dssdev,
struct omap_video_timings *timings)
{
DSSDBG("hdmi_set_timings\n");
mutex_lock(&hdmi.hdmi_lock);
dssdev->panel.timings = *timings;
omapdss_hdmi_display_set_timing(dssdev);
mutex_unlock(&hdmi.hdmi_lock);
}
static int hdmi_check_timings(struct omap_dss_device *dssdev,
struct omap_video_timings *timings)
{
int r = 0;
DSSDBG("hdmi_check_timings\n");
mutex_lock(&hdmi.hdmi_lock);
r = omapdss_hdmi_display_check_timing(dssdev, timings);
mutex_unlock(&hdmi.hdmi_lock);
return r;
}
static int hdmi_read_edid(struct omap_dss_device *dssdev, u8 *buf, int len)
{
int r;
mutex_lock(&hdmi.hdmi_lock);
if (dssdev->state != OMAP_DSS_DISPLAY_ACTIVE) {
r = omapdss_hdmi_display_enable(dssdev);
if (r)
goto err;
}
r = omapdss_hdmi_read_edid(buf, len);
if (dssdev->state == OMAP_DSS_DISPLAY_DISABLED ||
dssdev->state == OMAP_DSS_DISPLAY_SUSPENDED)
omapdss_hdmi_display_disable(dssdev);
err:
mutex_unlock(&hdmi.hdmi_lock);
return r;
}
static bool hdmi_detect(struct omap_dss_device *dssdev)
{
int r;
mutex_lock(&hdmi.hdmi_lock);
if (dssdev->state != OMAP_DSS_DISPLAY_ACTIVE) {
r = omapdss_hdmi_display_enable(dssdev);
if (r)
goto err;
}
r = omapdss_hdmi_detect();
if (dssdev->state == OMAP_DSS_DISPLAY_DISABLED ||
dssdev->state == OMAP_DSS_DISPLAY_SUSPENDED)
omapdss_hdmi_display_disable(dssdev);
err:
mutex_unlock(&hdmi.hdmi_lock);
return r;
}
int hdmi_panel_init(void)
{
mutex_init(&hdmi.hdmi_lock);
omap_dss_register_driver(&hdmi_driver);
return 0;
}
void hdmi_panel_exit(void)
{
omap_dss_unregister_driver(&hdmi_driver);
}
