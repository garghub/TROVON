static int hdmic_connect(struct omap_dss_device *dssdev)
{
struct panel_drv_data *ddata = to_panel_data(dssdev);
struct omap_dss_device *in = ddata->in;
int r;
dev_dbg(ddata->dev, "connect\n");
if (omapdss_device_is_connected(dssdev))
return 0;
r = in->ops.hdmi->connect(in, dssdev);
if (r)
return r;
return 0;
}
static void hdmic_disconnect(struct omap_dss_device *dssdev)
{
struct panel_drv_data *ddata = to_panel_data(dssdev);
struct omap_dss_device *in = ddata->in;
dev_dbg(ddata->dev, "disconnect\n");
if (!omapdss_device_is_connected(dssdev))
return;
in->ops.hdmi->disconnect(in, dssdev);
}
static int hdmic_enable(struct omap_dss_device *dssdev)
{
struct panel_drv_data *ddata = to_panel_data(dssdev);
struct omap_dss_device *in = ddata->in;
int r;
dev_dbg(ddata->dev, "enable\n");
if (!omapdss_device_is_connected(dssdev))
return -ENODEV;
if (omapdss_device_is_enabled(dssdev))
return 0;
in->ops.hdmi->set_timings(in, &ddata->timings);
r = in->ops.hdmi->enable(in);
if (r)
return r;
dssdev->state = OMAP_DSS_DISPLAY_ACTIVE;
return r;
}
static void hdmic_disable(struct omap_dss_device *dssdev)
{
struct panel_drv_data *ddata = to_panel_data(dssdev);
struct omap_dss_device *in = ddata->in;
dev_dbg(ddata->dev, "disable\n");
if (!omapdss_device_is_enabled(dssdev))
return;
in->ops.hdmi->disable(in);
dssdev->state = OMAP_DSS_DISPLAY_DISABLED;
}
static void hdmic_set_timings(struct omap_dss_device *dssdev,
struct omap_video_timings *timings)
{
struct panel_drv_data *ddata = to_panel_data(dssdev);
struct omap_dss_device *in = ddata->in;
ddata->timings = *timings;
dssdev->panel.timings = *timings;
in->ops.hdmi->set_timings(in, timings);
}
static void hdmic_get_timings(struct omap_dss_device *dssdev,
struct omap_video_timings *timings)
{
struct panel_drv_data *ddata = to_panel_data(dssdev);
*timings = ddata->timings;
}
static int hdmic_check_timings(struct omap_dss_device *dssdev,
struct omap_video_timings *timings)
{
struct panel_drv_data *ddata = to_panel_data(dssdev);
struct omap_dss_device *in = ddata->in;
return in->ops.hdmi->check_timings(in, timings);
}
static int hdmic_read_edid(struct omap_dss_device *dssdev,
u8 *edid, int len)
{
struct panel_drv_data *ddata = to_panel_data(dssdev);
struct omap_dss_device *in = ddata->in;
return in->ops.hdmi->read_edid(in, edid, len);
}
static bool hdmic_detect(struct omap_dss_device *dssdev)
{
struct panel_drv_data *ddata = to_panel_data(dssdev);
struct omap_dss_device *in = ddata->in;
return in->ops.hdmi->detect(in);
}
static int hdmic_audio_enable(struct omap_dss_device *dssdev)
{
struct panel_drv_data *ddata = to_panel_data(dssdev);
struct omap_dss_device *in = ddata->in;
int r;
if (!omapdss_device_is_enabled(dssdev))
return -EPERM;
r = in->ops.hdmi->audio_enable(in);
if (r)
return r;
dssdev->audio_state = OMAP_DSS_AUDIO_ENABLED;
return 0;
}
static void hdmic_audio_disable(struct omap_dss_device *dssdev)
{
struct panel_drv_data *ddata = to_panel_data(dssdev);
struct omap_dss_device *in = ddata->in;
in->ops.hdmi->audio_disable(in);
dssdev->audio_state = OMAP_DSS_AUDIO_DISABLED;
}
static int hdmic_audio_start(struct omap_dss_device *dssdev)
{
struct panel_drv_data *ddata = to_panel_data(dssdev);
struct omap_dss_device *in = ddata->in;
int r;
if (dssdev->audio_state != OMAP_DSS_AUDIO_ENABLED)
return -EPERM;
r = in->ops.hdmi->audio_start(in);
if (r)
return r;
dssdev->audio_state = OMAP_DSS_AUDIO_PLAYING;
return 0;
}
static void hdmic_audio_stop(struct omap_dss_device *dssdev)
{
struct panel_drv_data *ddata = to_panel_data(dssdev);
struct omap_dss_device *in = ddata->in;
in->ops.hdmi->audio_stop(in);
dssdev->audio_state = OMAP_DSS_AUDIO_ENABLED;
}
static bool hdmic_audio_supported(struct omap_dss_device *dssdev)
{
struct panel_drv_data *ddata = to_panel_data(dssdev);
struct omap_dss_device *in = ddata->in;
if (!omapdss_device_is_enabled(dssdev))
return false;
return in->ops.hdmi->audio_supported(in);
}
static int hdmic_audio_config(struct omap_dss_device *dssdev,
struct omap_dss_audio *audio)
{
struct panel_drv_data *ddata = to_panel_data(dssdev);
struct omap_dss_device *in = ddata->in;
int r;
if (!omapdss_device_is_enabled(dssdev))
return -EPERM;
r = in->ops.hdmi->audio_config(in, audio);
if (r)
return r;
dssdev->audio_state = OMAP_DSS_AUDIO_CONFIGURED;
return 0;
}
static int hdmic_probe_pdata(struct platform_device *pdev)
{
struct panel_drv_data *ddata = platform_get_drvdata(pdev);
struct connector_hdmi_platform_data *pdata;
struct omap_dss_device *in, *dssdev;
pdata = dev_get_platdata(&pdev->dev);
in = omap_dss_find_output(pdata->source);
if (in == NULL) {
dev_err(&pdev->dev, "Failed to find video source\n");
return -ENODEV;
}
ddata->in = in;
dssdev = &ddata->dssdev;
dssdev->name = pdata->name;
return 0;
}
static int hdmic_probe(struct platform_device *pdev)
{
struct panel_drv_data *ddata;
struct omap_dss_device *dssdev;
int r;
ddata = devm_kzalloc(&pdev->dev, sizeof(*ddata), GFP_KERNEL);
if (!ddata)
return -ENOMEM;
platform_set_drvdata(pdev, ddata);
ddata->dev = &pdev->dev;
if (dev_get_platdata(&pdev->dev)) {
r = hdmic_probe_pdata(pdev);
if (r)
return r;
} else {
return -ENODEV;
}
ddata->timings = hdmic_default_timings;
dssdev = &ddata->dssdev;
dssdev->driver = &hdmic_driver;
dssdev->dev = &pdev->dev;
dssdev->type = OMAP_DISPLAY_TYPE_HDMI;
dssdev->owner = THIS_MODULE;
dssdev->panel.timings = hdmic_default_timings;
r = omapdss_register_display(dssdev);
if (r) {
dev_err(&pdev->dev, "Failed to register panel\n");
goto err_reg;
}
return 0;
err_reg:
omap_dss_put_device(ddata->in);
return r;
}
static int __exit hdmic_remove(struct platform_device *pdev)
{
struct panel_drv_data *ddata = platform_get_drvdata(pdev);
struct omap_dss_device *dssdev = &ddata->dssdev;
struct omap_dss_device *in = ddata->in;
omapdss_unregister_display(&ddata->dssdev);
hdmic_disable(dssdev);
hdmic_disconnect(dssdev);
omap_dss_put_device(in);
return 0;
}
