static int tpd_connect(struct omap_dss_device *dssdev,
struct omap_dss_device *dst)
{
struct panel_drv_data *ddata = to_panel_data(dssdev);
struct omap_dss_device *in = ddata->in;
int r;
r = in->ops.hdmi->connect(in, dssdev);
if (r)
return r;
dst->src = dssdev;
dssdev->dst = dst;
gpiod_set_value_cansleep(ddata->ct_cp_hpd_gpio, 1);
udelay(300);
return 0;
}
static void tpd_disconnect(struct omap_dss_device *dssdev,
struct omap_dss_device *dst)
{
struct panel_drv_data *ddata = to_panel_data(dssdev);
struct omap_dss_device *in = ddata->in;
WARN_ON(dst != dssdev->dst);
if (dst != dssdev->dst)
return;
gpiod_set_value_cansleep(ddata->ct_cp_hpd_gpio, 0);
dst->src = NULL;
dssdev->dst = NULL;
in->ops.hdmi->disconnect(in, &ddata->dssdev);
}
static int tpd_enable(struct omap_dss_device *dssdev)
{
struct panel_drv_data *ddata = to_panel_data(dssdev);
struct omap_dss_device *in = ddata->in;
int r;
if (dssdev->state == OMAP_DSS_DISPLAY_ACTIVE)
return 0;
in->ops.hdmi->set_timings(in, &ddata->vm);
r = in->ops.hdmi->enable(in);
if (r)
return r;
dssdev->state = OMAP_DSS_DISPLAY_ACTIVE;
return r;
}
static void tpd_disable(struct omap_dss_device *dssdev)
{
struct panel_drv_data *ddata = to_panel_data(dssdev);
struct omap_dss_device *in = ddata->in;
if (dssdev->state != OMAP_DSS_DISPLAY_ACTIVE)
return;
in->ops.hdmi->disable(in);
dssdev->state = OMAP_DSS_DISPLAY_DISABLED;
}
static void tpd_set_timings(struct omap_dss_device *dssdev,
struct videomode *vm)
{
struct panel_drv_data *ddata = to_panel_data(dssdev);
struct omap_dss_device *in = ddata->in;
ddata->vm = *vm;
dssdev->panel.vm = *vm;
in->ops.hdmi->set_timings(in, vm);
}
static void tpd_get_timings(struct omap_dss_device *dssdev,
struct videomode *vm)
{
struct panel_drv_data *ddata = to_panel_data(dssdev);
*vm = ddata->vm;
}
static int tpd_check_timings(struct omap_dss_device *dssdev,
struct videomode *vm)
{
struct panel_drv_data *ddata = to_panel_data(dssdev);
struct omap_dss_device *in = ddata->in;
int r;
r = in->ops.hdmi->check_timings(in, vm);
return r;
}
static int tpd_read_edid(struct omap_dss_device *dssdev,
u8 *edid, int len)
{
struct panel_drv_data *ddata = to_panel_data(dssdev);
struct omap_dss_device *in = ddata->in;
int r;
if (!gpiod_get_value_cansleep(ddata->hpd_gpio))
return -ENODEV;
gpiod_set_value_cansleep(ddata->ls_oe_gpio, 1);
r = in->ops.hdmi->read_edid(in, edid, len);
gpiod_set_value_cansleep(ddata->ls_oe_gpio, 0);
return r;
}
static bool tpd_detect(struct omap_dss_device *dssdev)
{
struct panel_drv_data *ddata = to_panel_data(dssdev);
return gpiod_get_value_cansleep(ddata->hpd_gpio);
}
static int tpd_set_infoframe(struct omap_dss_device *dssdev,
const struct hdmi_avi_infoframe *avi)
{
struct panel_drv_data *ddata = to_panel_data(dssdev);
struct omap_dss_device *in = ddata->in;
return in->ops.hdmi->set_infoframe(in, avi);
}
static int tpd_set_hdmi_mode(struct omap_dss_device *dssdev,
bool hdmi_mode)
{
struct panel_drv_data *ddata = to_panel_data(dssdev);
struct omap_dss_device *in = ddata->in;
return in->ops.hdmi->set_hdmi_mode(in, hdmi_mode);
}
static int tpd_probe_of(struct platform_device *pdev)
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
static int tpd_probe(struct platform_device *pdev)
{
struct omap_dss_device *in, *dssdev;
struct panel_drv_data *ddata;
int r;
struct gpio_desc *gpio;
ddata = devm_kzalloc(&pdev->dev, sizeof(*ddata), GFP_KERNEL);
if (!ddata)
return -ENOMEM;
platform_set_drvdata(pdev, ddata);
if (!pdev->dev.of_node)
return -ENODEV;
r = tpd_probe_of(pdev);
if (r)
return r;
gpio = devm_gpiod_get_index_optional(&pdev->dev, NULL, 0,
GPIOD_OUT_LOW);
if (IS_ERR(gpio)) {
r = PTR_ERR(gpio);
goto err_gpio;
}
ddata->ct_cp_hpd_gpio = gpio;
gpio = devm_gpiod_get_index_optional(&pdev->dev, NULL, 1,
GPIOD_OUT_LOW);
if (IS_ERR(gpio)) {
r = PTR_ERR(gpio);
goto err_gpio;
}
ddata->ls_oe_gpio = gpio;
gpio = devm_gpiod_get_index(&pdev->dev, NULL, 2,
GPIOD_IN);
if (IS_ERR(gpio)) {
r = PTR_ERR(gpio);
goto err_gpio;
}
ddata->hpd_gpio = gpio;
dssdev = &ddata->dssdev;
dssdev->ops.hdmi = &tpd_hdmi_ops;
dssdev->dev = &pdev->dev;
dssdev->type = OMAP_DISPLAY_TYPE_HDMI;
dssdev->output_type = OMAP_DISPLAY_TYPE_HDMI;
dssdev->owner = THIS_MODULE;
dssdev->port_num = 1;
in = ddata->in;
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
static int __exit tpd_remove(struct platform_device *pdev)
{
struct panel_drv_data *ddata = platform_get_drvdata(pdev);
struct omap_dss_device *dssdev = &ddata->dssdev;
struct omap_dss_device *in = ddata->in;
omapdss_unregister_output(&ddata->dssdev);
WARN_ON(omapdss_device_is_enabled(dssdev));
if (omapdss_device_is_enabled(dssdev))
tpd_disable(dssdev);
WARN_ON(omapdss_device_is_connected(dssdev));
if (omapdss_device_is_connected(dssdev))
tpd_disconnect(dssdev, dssdev->dst);
omap_dss_put_device(in);
return 0;
}
