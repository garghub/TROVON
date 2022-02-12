static int tvc_connect(struct omap_dss_device *dssdev)
{
struct panel_drv_data *ddata = to_panel_data(dssdev);
struct omap_dss_device *in = ddata->in;
int r;
dev_dbg(ddata->dev, "connect\n");
if (omapdss_device_is_connected(dssdev))
return 0;
r = in->ops.atv->connect(in, dssdev);
if (r)
return r;
return 0;
}
static void tvc_disconnect(struct omap_dss_device *dssdev)
{
struct panel_drv_data *ddata = to_panel_data(dssdev);
struct omap_dss_device *in = ddata->in;
dev_dbg(ddata->dev, "disconnect\n");
if (!omapdss_device_is_connected(dssdev))
return;
in->ops.atv->disconnect(in, dssdev);
}
static int tvc_enable(struct omap_dss_device *dssdev)
{
struct panel_drv_data *ddata = to_panel_data(dssdev);
struct omap_dss_device *in = ddata->in;
int r;
dev_dbg(ddata->dev, "enable\n");
if (!omapdss_device_is_connected(dssdev))
return -ENODEV;
if (omapdss_device_is_enabled(dssdev))
return 0;
in->ops.atv->set_timings(in, &ddata->vm);
if (!ddata->dev->of_node) {
in->ops.atv->set_type(in, OMAP_DSS_VENC_TYPE_COMPOSITE);
in->ops.atv->invert_vid_out_polarity(in,
ddata->invert_polarity);
}
r = in->ops.atv->enable(in);
if (r)
return r;
dssdev->state = OMAP_DSS_DISPLAY_ACTIVE;
return r;
}
static void tvc_disable(struct omap_dss_device *dssdev)
{
struct panel_drv_data *ddata = to_panel_data(dssdev);
struct omap_dss_device *in = ddata->in;
dev_dbg(ddata->dev, "disable\n");
if (!omapdss_device_is_enabled(dssdev))
return;
in->ops.atv->disable(in);
dssdev->state = OMAP_DSS_DISPLAY_DISABLED;
}
static void tvc_set_timings(struct omap_dss_device *dssdev,
struct videomode *vm)
{
struct panel_drv_data *ddata = to_panel_data(dssdev);
struct omap_dss_device *in = ddata->in;
ddata->vm = *vm;
dssdev->panel.vm = *vm;
in->ops.atv->set_timings(in, vm);
}
static void tvc_get_timings(struct omap_dss_device *dssdev,
struct videomode *vm)
{
struct panel_drv_data *ddata = to_panel_data(dssdev);
*vm = ddata->vm;
}
static int tvc_check_timings(struct omap_dss_device *dssdev,
struct videomode *vm)
{
struct panel_drv_data *ddata = to_panel_data(dssdev);
struct omap_dss_device *in = ddata->in;
return in->ops.atv->check_timings(in, vm);
}
static u32 tvc_get_wss(struct omap_dss_device *dssdev)
{
struct panel_drv_data *ddata = to_panel_data(dssdev);
struct omap_dss_device *in = ddata->in;
return in->ops.atv->get_wss(in);
}
static int tvc_set_wss(struct omap_dss_device *dssdev, u32 wss)
{
struct panel_drv_data *ddata = to_panel_data(dssdev);
struct omap_dss_device *in = ddata->in;
return in->ops.atv->set_wss(in, wss);
}
static int tvc_probe_pdata(struct platform_device *pdev)
{
struct panel_drv_data *ddata = platform_get_drvdata(pdev);
struct connector_atv_platform_data *pdata;
struct omap_dss_device *in, *dssdev;
pdata = dev_get_platdata(&pdev->dev);
in = omap_dss_find_output(pdata->source);
if (in == NULL) {
dev_err(&pdev->dev, "Failed to find video source\n");
return -EPROBE_DEFER;
}
ddata->in = in;
ddata->invert_polarity = pdata->invert_polarity;
dssdev = &ddata->dssdev;
dssdev->name = pdata->name;
return 0;
}
static int tvc_probe_of(struct platform_device *pdev)
{
struct panel_drv_data *ddata = platform_get_drvdata(pdev);
struct device_node *node = pdev->dev.of_node;
struct omap_dss_device *in;
in = omapdss_of_find_source_for_first_ep(node);
if (IS_ERR(in)) {
dev_err(&pdev->dev, "failed to find video source\n");
return PTR_ERR(in);
}
ddata->in = in;
return 0;
}
static int tvc_probe(struct platform_device *pdev)
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
r = tvc_probe_pdata(pdev);
if (r)
return r;
} else if (pdev->dev.of_node) {
r = tvc_probe_of(pdev);
if (r)
return r;
} else {
return -ENODEV;
}
ddata->vm = tvc_pal_vm;
dssdev = &ddata->dssdev;
dssdev->driver = &tvc_driver;
dssdev->dev = &pdev->dev;
dssdev->type = OMAP_DISPLAY_TYPE_VENC;
dssdev->owner = THIS_MODULE;
dssdev->panel.vm = tvc_pal_vm;
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
static int __exit tvc_remove(struct platform_device *pdev)
{
struct panel_drv_data *ddata = platform_get_drvdata(pdev);
struct omap_dss_device *dssdev = &ddata->dssdev;
struct omap_dss_device *in = ddata->in;
omapdss_unregister_display(&ddata->dssdev);
tvc_disable(dssdev);
tvc_disconnect(dssdev);
omap_dss_put_device(in);
return 0;
}
