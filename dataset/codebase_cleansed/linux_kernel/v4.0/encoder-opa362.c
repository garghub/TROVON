static int opa362_connect(struct omap_dss_device *dssdev,
struct omap_dss_device *dst)
{
struct panel_drv_data *ddata = to_panel_data(dssdev);
struct omap_dss_device *in = ddata->in;
int r;
dev_dbg(dssdev->dev, "connect\n");
if (omapdss_device_is_connected(dssdev))
return -EBUSY;
r = in->ops.atv->connect(in, dssdev);
if (r)
return r;
dst->src = dssdev;
dssdev->dst = dst;
return 0;
}
static void opa362_disconnect(struct omap_dss_device *dssdev,
struct omap_dss_device *dst)
{
struct panel_drv_data *ddata = to_panel_data(dssdev);
struct omap_dss_device *in = ddata->in;
dev_dbg(dssdev->dev, "disconnect\n");
WARN_ON(!omapdss_device_is_connected(dssdev));
if (!omapdss_device_is_connected(dssdev))
return;
WARN_ON(dst != dssdev->dst);
if (dst != dssdev->dst)
return;
dst->src = NULL;
dssdev->dst = NULL;
in->ops.atv->disconnect(in, &ddata->dssdev);
}
static int opa362_enable(struct omap_dss_device *dssdev)
{
struct panel_drv_data *ddata = to_panel_data(dssdev);
struct omap_dss_device *in = ddata->in;
int r;
dev_dbg(dssdev->dev, "enable\n");
if (!omapdss_device_is_connected(dssdev))
return -ENODEV;
if (omapdss_device_is_enabled(dssdev))
return 0;
in->ops.atv->set_timings(in, &ddata->timings);
r = in->ops.atv->enable(in);
if (r)
return r;
if (ddata->enable_gpio)
gpiod_set_value_cansleep(ddata->enable_gpio, 1);
dssdev->state = OMAP_DSS_DISPLAY_ACTIVE;
return 0;
}
static void opa362_disable(struct omap_dss_device *dssdev)
{
struct panel_drv_data *ddata = to_panel_data(dssdev);
struct omap_dss_device *in = ddata->in;
dev_dbg(dssdev->dev, "disable\n");
if (!omapdss_device_is_enabled(dssdev))
return;
if (ddata->enable_gpio)
gpiod_set_value_cansleep(ddata->enable_gpio, 0);
in->ops.atv->disable(in);
dssdev->state = OMAP_DSS_DISPLAY_DISABLED;
}
static void opa362_set_timings(struct omap_dss_device *dssdev,
struct omap_video_timings *timings)
{
struct panel_drv_data *ddata = to_panel_data(dssdev);
struct omap_dss_device *in = ddata->in;
dev_dbg(dssdev->dev, "set_timings\n");
ddata->timings = *timings;
dssdev->panel.timings = *timings;
in->ops.atv->set_timings(in, timings);
}
static void opa362_get_timings(struct omap_dss_device *dssdev,
struct omap_video_timings *timings)
{
struct panel_drv_data *ddata = to_panel_data(dssdev);
dev_dbg(dssdev->dev, "get_timings\n");
*timings = ddata->timings;
}
static int opa362_check_timings(struct omap_dss_device *dssdev,
struct omap_video_timings *timings)
{
struct panel_drv_data *ddata = to_panel_data(dssdev);
struct omap_dss_device *in = ddata->in;
dev_dbg(dssdev->dev, "check_timings\n");
return in->ops.atv->check_timings(in, timings);
}
static void opa362_set_type(struct omap_dss_device *dssdev,
enum omap_dss_venc_type type)
{
WARN_ON(type != OMAP_DSS_VENC_TYPE_COMPOSITE);
}
static int opa362_probe(struct platform_device *pdev)
{
struct device_node *node = pdev->dev.of_node;
struct panel_drv_data *ddata;
struct omap_dss_device *dssdev, *in;
struct gpio_desc *gpio;
int r;
dev_dbg(&pdev->dev, "probe\n");
if (node == NULL) {
dev_err(&pdev->dev, "Unable to find device tree\n");
return -EINVAL;
}
ddata = devm_kzalloc(&pdev->dev, sizeof(*ddata), GFP_KERNEL);
if (!ddata)
return -ENOMEM;
platform_set_drvdata(pdev, ddata);
gpio = devm_gpiod_get(&pdev->dev, "enable");
if (IS_ERR(gpio)) {
if (PTR_ERR(gpio) != -ENOENT)
return PTR_ERR(gpio);
gpio = NULL;
} else {
gpiod_direction_output(gpio, 0);
}
ddata->enable_gpio = gpio;
in = omapdss_of_find_source_for_first_ep(node);
if (IS_ERR(in)) {
dev_err(&pdev->dev, "failed to find video source\n");
return PTR_ERR(in);
}
ddata->in = in;
dssdev = &ddata->dssdev;
dssdev->ops.atv = &opa362_atv_ops;
dssdev->dev = &pdev->dev;
dssdev->type = OMAP_DISPLAY_TYPE_VENC;
dssdev->output_type = OMAP_DISPLAY_TYPE_VENC;
dssdev->owner = THIS_MODULE;
r = omapdss_register_output(dssdev);
if (r) {
dev_err(&pdev->dev, "Failed to register output\n");
goto err_reg;
}
return 0;
err_reg:
omap_dss_put_device(ddata->in);
return r;
}
static int __exit opa362_remove(struct platform_device *pdev)
{
struct panel_drv_data *ddata = platform_get_drvdata(pdev);
struct omap_dss_device *dssdev = &ddata->dssdev;
struct omap_dss_device *in = ddata->in;
omapdss_unregister_output(&ddata->dssdev);
WARN_ON(omapdss_device_is_enabled(dssdev));
if (omapdss_device_is_enabled(dssdev))
opa362_disable(dssdev);
WARN_ON(omapdss_device_is_connected(dssdev));
if (omapdss_device_is_connected(dssdev))
opa362_disconnect(dssdev, dssdev->dst);
omap_dss_put_device(in);
return 0;
}
