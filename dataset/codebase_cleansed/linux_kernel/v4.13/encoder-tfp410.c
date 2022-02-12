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
in->ops.dpi->set_timings(in, &ddata->vm);
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
static void tfp410_fix_timings(struct videomode *vm)
{
vm->flags |= DISPLAY_FLAGS_DE_HIGH | DISPLAY_FLAGS_PIXDATA_POSEDGE |
DISPLAY_FLAGS_SYNC_POSEDGE;
}
static void tfp410_set_timings(struct omap_dss_device *dssdev,
struct videomode *vm)
{
struct panel_drv_data *ddata = to_panel_data(dssdev);
struct omap_dss_device *in = ddata->in;
tfp410_fix_timings(vm);
ddata->vm = *vm;
dssdev->panel.vm = *vm;
in->ops.dpi->set_timings(in, vm);
}
static void tfp410_get_timings(struct omap_dss_device *dssdev,
struct videomode *vm)
{
struct panel_drv_data *ddata = to_panel_data(dssdev);
*vm = ddata->vm;
}
static int tfp410_check_timings(struct omap_dss_device *dssdev,
struct videomode *vm)
{
struct panel_drv_data *ddata = to_panel_data(dssdev);
struct omap_dss_device *in = ddata->in;
tfp410_fix_timings(vm);
return in->ops.dpi->check_timings(in, vm);
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
if (!pdev->dev.of_node)
return -ENODEV;
r = tfp410_probe_of(pdev);
if (r)
return r;
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
