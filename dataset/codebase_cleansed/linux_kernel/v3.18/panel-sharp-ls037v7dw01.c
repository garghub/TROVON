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
if (ddata->data_lines)
in->ops.dpi->set_data_lines(in, ddata->data_lines);
in->ops.dpi->set_timings(in, &ddata->videomode);
if (ddata->vcc) {
r = regulator_enable(ddata->vcc);
if (r != 0)
return r;
}
r = in->ops.dpi->enable(in);
if (r) {
regulator_disable(ddata->vcc);
return r;
}
msleep(50);
if (ddata->resb_gpio)
gpiod_set_value_cansleep(ddata->resb_gpio, 1);
if (ddata->ini_gpio)
gpiod_set_value_cansleep(ddata->ini_gpio, 1);
dssdev->state = OMAP_DSS_DISPLAY_ACTIVE;
return 0;
}
static void sharp_ls_disable(struct omap_dss_device *dssdev)
{
struct panel_drv_data *ddata = to_panel_data(dssdev);
struct omap_dss_device *in = ddata->in;
if (!omapdss_device_is_enabled(dssdev))
return;
if (ddata->ini_gpio)
gpiod_set_value_cansleep(ddata->ini_gpio, 0);
if (ddata->resb_gpio)
gpiod_set_value_cansleep(ddata->resb_gpio, 0);
msleep(100);
in->ops.dpi->disable(in);
if (ddata->vcc)
regulator_disable(ddata->vcc);
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
static int sharp_ls_get_gpio(struct device *dev, int gpio, unsigned long flags,
char *desc, struct gpio_desc **gpiod)
{
struct gpio_desc *gd;
int r;
*gpiod = NULL;
r = devm_gpio_request_one(dev, gpio, flags, desc);
if (r)
return r == -ENOENT ? 0 : r;
gd = gpio_to_desc(gpio);
if (IS_ERR(gd))
return PTR_ERR(gd) == -ENOENT ? 0 : PTR_ERR(gd);
*gpiod = gd;
return 0;
}
static int sharp_ls_probe_pdata(struct platform_device *pdev)
{
const struct panel_sharp_ls037v7dw01_platform_data *pdata;
struct panel_drv_data *ddata = platform_get_drvdata(pdev);
struct omap_dss_device *dssdev, *in;
int r;
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
r = sharp_ls_get_gpio(&pdev->dev, pdata->mo_gpio, GPIOF_OUT_INIT_LOW,
"lcd MO", &ddata->mo_gpio);
if (r)
return r;
r = sharp_ls_get_gpio(&pdev->dev, pdata->lr_gpio, GPIOF_OUT_INIT_HIGH,
"lcd LR", &ddata->lr_gpio);
if (r)
return r;
r = sharp_ls_get_gpio(&pdev->dev, pdata->ud_gpio, GPIOF_OUT_INIT_HIGH,
"lcd UD", &ddata->ud_gpio);
if (r)
return r;
r = sharp_ls_get_gpio(&pdev->dev, pdata->resb_gpio, GPIOF_OUT_INIT_LOW,
"lcd RESB", &ddata->resb_gpio);
if (r)
return r;
r = sharp_ls_get_gpio(&pdev->dev, pdata->ini_gpio, GPIOF_OUT_INIT_LOW,
"lcd INI", &ddata->ini_gpio);
if (r)
return r;
return 0;
}
static int sharp_ls_get_gpio_of(struct device *dev, int index, int val,
const char *desc, struct gpio_desc **gpiod)
{
struct gpio_desc *gd;
int r;
*gpiod = NULL;
gd = devm_gpiod_get_index(dev, desc, index);
if (IS_ERR(gd))
return PTR_ERR(gd) == -ENOENT ? 0 : PTR_ERR(gd);
r = gpiod_direction_output(gd, val);
if (r)
return r;
*gpiod = gd;
return 0;
}
static int sharp_ls_probe_of(struct platform_device *pdev)
{
struct panel_drv_data *ddata = platform_get_drvdata(pdev);
struct device_node *node = pdev->dev.of_node;
struct omap_dss_device *in;
int r;
ddata->vcc = devm_regulator_get(&pdev->dev, "envdd");
if (IS_ERR(ddata->vcc)) {
dev_err(&pdev->dev, "failed to get regulator\n");
return PTR_ERR(ddata->vcc);
}
r = sharp_ls_get_gpio_of(&pdev->dev, 0, 0, "enable", &ddata->ini_gpio);
if (r)
return r;
r = sharp_ls_get_gpio_of(&pdev->dev, 0, 0, "reset", &ddata->resb_gpio);
if (r)
return r;
r = sharp_ls_get_gpio_of(&pdev->dev, 0, 0, "mode", &ddata->mo_gpio);
if (r)
return r;
r = sharp_ls_get_gpio_of(&pdev->dev, 1, 1, "mode", &ddata->lr_gpio);
if (r)
return r;
r = sharp_ls_get_gpio_of(&pdev->dev, 2, 1, "mode", &ddata->ud_gpio);
if (r)
return r;
in = omapdss_of_find_source_for_first_ep(node);
if (IS_ERR(in)) {
dev_err(&pdev->dev, "failed to find video source\n");
return PTR_ERR(in);
}
ddata->in = in;
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
} else if (pdev->dev.of_node) {
r = sharp_ls_probe_of(pdev);
if (r)
return r;
} else {
return -ENODEV;
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
