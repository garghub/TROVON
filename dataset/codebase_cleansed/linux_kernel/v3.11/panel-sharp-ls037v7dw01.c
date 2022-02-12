static int sharp_ls_connect(struct omap_dss_device *dssdev)
{
struct panel_drv_data *ddata = to_panel_data(dssdev);
struct omap_dss_device *in = ddata->in;
int r;
if (omapdss_device_is_connected(dssdev))
return 0;
r = in->ops.dpi->connect(in, dssdev);
if (r)
return r;
return 0;
}
static void sharp_ls_disconnect(struct omap_dss_device *dssdev)
{
struct panel_drv_data *ddata = to_panel_data(dssdev);
struct omap_dss_device *in = ddata->in;
if (!omapdss_device_is_connected(dssdev))
return;
in->ops.dpi->disconnect(in, dssdev);
}
static int sharp_ls_enable(struct omap_dss_device *dssdev)
{
struct panel_drv_data *ddata = to_panel_data(dssdev);
struct omap_dss_device *in = ddata->in;
int r;
if (!omapdss_device_is_connected(dssdev))
return -ENODEV;
if (omapdss_device_is_enabled(dssdev))
return 0;
in->ops.dpi->set_data_lines(in, ddata->data_lines);
in->ops.dpi->set_timings(in, &ddata->videomode);
r = in->ops.dpi->enable(in);
if (r)
return r;
msleep(50);
if (gpio_is_valid(ddata->resb_gpio))
gpio_set_value_cansleep(ddata->resb_gpio, 1);
if (gpio_is_valid(ddata->ini_gpio))
gpio_set_value_cansleep(ddata->ini_gpio, 1);
dssdev->state = OMAP_DSS_DISPLAY_ACTIVE;
return 0;
}
static void sharp_ls_disable(struct omap_dss_device *dssdev)
{
struct panel_drv_data *ddata = to_panel_data(dssdev);
struct omap_dss_device *in = ddata->in;
if (!omapdss_device_is_enabled(dssdev))
return;
if (gpio_is_valid(ddata->ini_gpio))
gpio_set_value_cansleep(ddata->ini_gpio, 0);
if (gpio_is_valid(ddata->resb_gpio))
gpio_set_value_cansleep(ddata->resb_gpio, 0);
msleep(100);
in->ops.dpi->disable(in);
dssdev->state = OMAP_DSS_DISPLAY_DISABLED;
}
static void sharp_ls_set_timings(struct omap_dss_device *dssdev,
struct omap_video_timings *timings)
{
struct panel_drv_data *ddata = to_panel_data(dssdev);
struct omap_dss_device *in = ddata->in;
ddata->videomode = *timings;
dssdev->panel.timings = *timings;
in->ops.dpi->set_timings(in, timings);
}
static void sharp_ls_get_timings(struct omap_dss_device *dssdev,
struct omap_video_timings *timings)
{
struct panel_drv_data *ddata = to_panel_data(dssdev);
*timings = ddata->videomode;
}
static int sharp_ls_check_timings(struct omap_dss_device *dssdev,
struct omap_video_timings *timings)
{
struct panel_drv_data *ddata = to_panel_data(dssdev);
struct omap_dss_device *in = ddata->in;
return in->ops.dpi->check_timings(in, timings);
}
static int sharp_ls_probe_pdata(struct platform_device *pdev)
{
const struct panel_sharp_ls037v7dw01_platform_data *pdata;
struct panel_drv_data *ddata = platform_get_drvdata(pdev);
struct omap_dss_device *dssdev, *in;
pdata = dev_get_platdata(&pdev->dev);
in = omap_dss_find_output(pdata->source);
if (in == NULL) {
dev_err(&pdev->dev, "failed to find video source '%s'\n",
pdata->source);
return -EPROBE_DEFER;
}
ddata->in = in;
ddata->data_lines = pdata->data_lines;
dssdev = &ddata->dssdev;
dssdev->name = pdata->name;
ddata->resb_gpio = pdata->resb_gpio;
ddata->ini_gpio = pdata->ini_gpio;
ddata->mo_gpio = pdata->mo_gpio;
ddata->lr_gpio = pdata->lr_gpio;
ddata->ud_gpio = pdata->ud_gpio;
return 0;
}
static int sharp_ls_probe(struct platform_device *pdev)
{
struct panel_drv_data *ddata;
struct omap_dss_device *dssdev;
int r;
ddata = devm_kzalloc(&pdev->dev, sizeof(*ddata), GFP_KERNEL);
if (ddata == NULL)
return -ENOMEM;
platform_set_drvdata(pdev, ddata);
if (dev_get_platdata(&pdev->dev)) {
r = sharp_ls_probe_pdata(pdev);
if (r)
return r;
} else {
return -ENODEV;
}
if (gpio_is_valid(ddata->mo_gpio)) {
r = devm_gpio_request_one(&pdev->dev, ddata->mo_gpio,
GPIOF_OUT_INIT_LOW, "lcd MO");
if (r)
goto err_gpio;
}
if (gpio_is_valid(ddata->lr_gpio)) {
r = devm_gpio_request_one(&pdev->dev, ddata->lr_gpio,
GPIOF_OUT_INIT_HIGH, "lcd LR");
if (r)
goto err_gpio;
}
if (gpio_is_valid(ddata->ud_gpio)) {
r = devm_gpio_request_one(&pdev->dev, ddata->ud_gpio,
GPIOF_OUT_INIT_HIGH, "lcd UD");
if (r)
goto err_gpio;
}
if (gpio_is_valid(ddata->resb_gpio)) {
r = devm_gpio_request_one(&pdev->dev, ddata->resb_gpio,
GPIOF_OUT_INIT_LOW, "lcd RESB");
if (r)
goto err_gpio;
}
if (gpio_is_valid(ddata->ini_gpio)) {
r = devm_gpio_request_one(&pdev->dev, ddata->ini_gpio,
GPIOF_OUT_INIT_LOW, "lcd INI");
if (r)
goto err_gpio;
}
ddata->videomode = sharp_ls_timings;
dssdev = &ddata->dssdev;
dssdev->dev = &pdev->dev;
dssdev->driver = &sharp_ls_ops;
dssdev->type = OMAP_DISPLAY_TYPE_DPI;
dssdev->owner = THIS_MODULE;
dssdev->panel.timings = ddata->videomode;
dssdev->phy.dpi.data_lines = ddata->data_lines;
r = omapdss_register_display(dssdev);
if (r) {
dev_err(&pdev->dev, "Failed to register panel\n");
goto err_reg;
}
return 0;
err_reg:
err_gpio:
omap_dss_put_device(ddata->in);
return r;
}
static int __exit sharp_ls_remove(struct platform_device *pdev)
{
struct panel_drv_data *ddata = platform_get_drvdata(pdev);
struct omap_dss_device *dssdev = &ddata->dssdev;
struct omap_dss_device *in = ddata->in;
omapdss_unregister_display(dssdev);
sharp_ls_disable(dssdev);
sharp_ls_disconnect(dssdev);
omap_dss_put_device(in);
return 0;
}
