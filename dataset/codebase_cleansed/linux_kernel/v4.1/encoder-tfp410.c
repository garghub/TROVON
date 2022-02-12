static int tfp410_connect(struct omap_dss_device *dssdev,
struct omap_dss_device *dst)
{
struct panel_drv_data *ddata = to_panel_data(dssdev);
struct omap_dss_device *in = ddata->in;
int r;
if (omapdss_device_is_connected(dssdev))
return -EBUSY;
r = in->ops.dpi->connect(in, dssdev);
if (r)
return r;
dst->src = dssdev;
dssdev->dst = dst;
return 0;
}
static void tfp410_disconnect(struct omap_dss_device *dssdev,
struct omap_dss_device *dst)
{
struct panel_drv_data *ddata = to_panel_data(dssdev);
struct omap_dss_device *in = ddata->in;
WARN_ON(!omapdss_device_is_connected(dssdev));
if (!omapdss_device_is_connected(dssdev))
return;
WARN_ON(dst != dssdev->dst);
if (dst != dssdev->dst)
return;
dst->src = NULL;
dssdev->dst = NULL;
in->ops.dpi->disconnect(in, &ddata->dssdev);
}
static int tfp410_enable(struct omap_dss_device *dssdev)
{
struct panel_drv_data *ddata = to_panel_data(dssdev);
struct omap_dss_device *in = ddata->in;
int r;
if (!omapdss_device_is_connected(dssdev))
return -ENODEV;
if (omapdss_device_is_enabled(dssdev))
return 0;
in->ops.dpi->set_timings(in, &ddata->timings);
if (ddata->data_lines)
in->ops.dpi->set_data_lines(in, ddata->data_lines);
r = in->ops.dpi->enable(in);
if (r)
return r;
if (gpio_is_valid(ddata->pd_gpio))
gpio_set_value_cansleep(ddata->pd_gpio, 1);
dssdev->state = OMAP_DSS_DISPLAY_ACTIVE;
return 0;
}
static void tfp410_disable(struct omap_dss_device *dssdev)
{
struct panel_drv_data *ddata = to_panel_data(dssdev);
struct omap_dss_device *in = ddata->in;
if (!omapdss_device_is_enabled(dssdev))
return;
if (gpio_is_valid(ddata->pd_gpio))
gpio_set_value_cansleep(ddata->pd_gpio, 0);
in->ops.dpi->disable(in);
dssdev->state = OMAP_DSS_DISPLAY_DISABLED;
}
static void tfp410_fix_timings(struct omap_video_timings *timings)
{
timings->data_pclk_edge = OMAPDSS_DRIVE_SIG_RISING_EDGE;
timings->sync_pclk_edge = OMAPDSS_DRIVE_SIG_RISING_EDGE;
timings->de_level = OMAPDSS_SIG_ACTIVE_HIGH;
}
static void tfp410_set_timings(struct omap_dss_device *dssdev,
struct omap_video_timings *timings)
{
struct panel_drv_data *ddata = to_panel_data(dssdev);
struct omap_dss_device *in = ddata->in;
tfp410_fix_timings(timings);
ddata->timings = *timings;
dssdev->panel.timings = *timings;
in->ops.dpi->set_timings(in, timings);
}
static void tfp410_get_timings(struct omap_dss_device *dssdev,
struct omap_video_timings *timings)
{
struct panel_drv_data *ddata = to_panel_data(dssdev);
*timings = ddata->timings;
}
static int tfp410_check_timings(struct omap_dss_device *dssdev,
struct omap_video_timings *timings)
{
struct panel_drv_data *ddata = to_panel_data(dssdev);
struct omap_dss_device *in = ddata->in;
tfp410_fix_timings(timings);
return in->ops.dpi->check_timings(in, timings);
}
static int tfp410_probe_pdata(struct platform_device *pdev)
{
struct panel_drv_data *ddata = platform_get_drvdata(pdev);
struct encoder_tfp410_platform_data *pdata;
struct omap_dss_device *dssdev, *in;
pdata = dev_get_platdata(&pdev->dev);
ddata->pd_gpio = pdata->power_down_gpio;
ddata->data_lines = pdata->data_lines;
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
static int tfp410_probe_of(struct platform_device *pdev)
{
struct panel_drv_data *ddata = platform_get_drvdata(pdev);
struct device_node *node = pdev->dev.of_node;
struct omap_dss_device *in;
int gpio;
gpio = of_get_named_gpio(node, "powerdown-gpios", 0);
if (gpio_is_valid(gpio) || gpio == -ENOENT) {
ddata->pd_gpio = gpio;
} else {
dev_err(&pdev->dev, "failed to parse PD gpio\n");
return gpio;
}
in = omapdss_of_find_source_for_first_ep(node);
if (IS_ERR(in)) {
dev_err(&pdev->dev, "failed to find video source\n");
return PTR_ERR(in);
}
ddata->in = in;
return 0;
}
static int tfp410_probe(struct platform_device *pdev)
{
struct panel_drv_data *ddata;
struct omap_dss_device *dssdev;
int r;
ddata = devm_kzalloc(&pdev->dev, sizeof(*ddata), GFP_KERNEL);
if (!ddata)
return -ENOMEM;
platform_set_drvdata(pdev, ddata);
if (dev_get_platdata(&pdev->dev)) {
r = tfp410_probe_pdata(pdev);
if (r)
return r;
} else if (pdev->dev.of_node) {
r = tfp410_probe_of(pdev);
if (r)
return r;
} else {
return -ENODEV;
}
if (gpio_is_valid(ddata->pd_gpio)) {
r = devm_gpio_request_one(&pdev->dev, ddata->pd_gpio,
GPIOF_OUT_INIT_LOW, "tfp410 PD");
if (r) {
dev_err(&pdev->dev, "Failed to request PD GPIO %d\n",
ddata->pd_gpio);
goto err_gpio;
}
}
dssdev = &ddata->dssdev;
dssdev->ops.dvi = &tfp410_dvi_ops;
dssdev->dev = &pdev->dev;
dssdev->type = OMAP_DISPLAY_TYPE_DPI;
dssdev->output_type = OMAP_DISPLAY_TYPE_DVI;
dssdev->owner = THIS_MODULE;
dssdev->phy.dpi.data_lines = ddata->data_lines;
dssdev->port_num = 1;
r = omapdss_register_output(dssdev);
if (r) {
dev_err(&pdev->dev, "Failed to register output\n");
goto err_reg;
}
return 0;
err_reg:
err_gpio:
omap_dss_put_device(ddata->in);
return r;
}
static int __exit tfp410_remove(struct platform_device *pdev)
{
struct panel_drv_data *ddata = platform_get_drvdata(pdev);
struct omap_dss_device *dssdev = &ddata->dssdev;
struct omap_dss_device *in = ddata->in;
omapdss_unregister_output(&ddata->dssdev);
WARN_ON(omapdss_device_is_enabled(dssdev));
if (omapdss_device_is_enabled(dssdev))
tfp410_disable(dssdev);
WARN_ON(omapdss_device_is_connected(dssdev));
if (omapdss_device_is_connected(dssdev))
tfp410_disconnect(dssdev, dssdev->dst);
omap_dss_put_device(in);
return 0;
}
