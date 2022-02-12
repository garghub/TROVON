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
gpio_set_value_cansleep(ddata->ct_cp_hpd_gpio, 1);
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
gpio_set_value_cansleep(ddata->ct_cp_hpd_gpio, 0);
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
in->ops.hdmi->set_timings(in, &ddata->timings);
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
struct omap_video_timings *timings)
{
struct panel_drv_data *ddata = to_panel_data(dssdev);
struct omap_dss_device *in = ddata->in;
ddata->timings = *timings;
dssdev->panel.timings = *timings;
in->ops.hdmi->set_timings(in, timings);
}
static void tpd_get_timings(struct omap_dss_device *dssdev,
struct omap_video_timings *timings)
{
struct panel_drv_data *ddata = to_panel_data(dssdev);
*timings = ddata->timings;
}
static int tpd_check_timings(struct omap_dss_device *dssdev,
struct omap_video_timings *timings)
{
struct panel_drv_data *ddata = to_panel_data(dssdev);
struct omap_dss_device *in = ddata->in;
int r;
r = in->ops.hdmi->check_timings(in, timings);
return r;
}
static int tpd_read_edid(struct omap_dss_device *dssdev,
u8 *edid, int len)
{
struct panel_drv_data *ddata = to_panel_data(dssdev);
struct omap_dss_device *in = ddata->in;
int r;
if (!gpio_get_value_cansleep(ddata->hpd_gpio))
return -ENODEV;
if (gpio_is_valid(ddata->ls_oe_gpio))
gpio_set_value_cansleep(ddata->ls_oe_gpio, 1);
r = in->ops.hdmi->read_edid(in, edid, len);
if (gpio_is_valid(ddata->ls_oe_gpio))
gpio_set_value_cansleep(ddata->ls_oe_gpio, 0);
return r;
}
static bool tpd_detect(struct omap_dss_device *dssdev)
{
struct panel_drv_data *ddata = to_panel_data(dssdev);
return gpio_get_value_cansleep(ddata->hpd_gpio);
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
static int tpd_probe_pdata(struct platform_device *pdev)
{
struct panel_drv_data *ddata = platform_get_drvdata(pdev);
struct encoder_tpd12s015_platform_data *pdata;
struct omap_dss_device *dssdev, *in;
pdata = dev_get_platdata(&pdev->dev);
ddata->ct_cp_hpd_gpio = pdata->ct_cp_hpd_gpio;
ddata->ls_oe_gpio = pdata->ls_oe_gpio;
ddata->hpd_gpio = pdata->hpd_gpio;
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
static int tpd_probe_of(struct platform_device *pdev)
{
struct panel_drv_data *ddata = platform_get_drvdata(pdev);
struct device_node *node = pdev->dev.of_node;
struct omap_dss_device *in;
int gpio;
gpio = of_get_gpio(node, 0);
if (!gpio_is_valid(gpio)) {
dev_err(&pdev->dev, "failed to parse CT CP HPD gpio\n");
return gpio;
}
ddata->ct_cp_hpd_gpio = gpio;
gpio = of_get_gpio(node, 1);
if (gpio_is_valid(gpio) || gpio == -ENOENT) {
ddata->ls_oe_gpio = gpio;
} else {
dev_err(&pdev->dev, "failed to parse LS OE gpio\n");
return gpio;
}
gpio = of_get_gpio(node, 2);
if (!gpio_is_valid(gpio)) {
dev_err(&pdev->dev, "failed to parse HPD gpio\n");
return gpio;
}
ddata->hpd_gpio = gpio;
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
ddata = devm_kzalloc(&pdev->dev, sizeof(*ddata), GFP_KERNEL);
if (!ddata)
return -ENOMEM;
platform_set_drvdata(pdev, ddata);
if (dev_get_platdata(&pdev->dev)) {
r = tpd_probe_pdata(pdev);
if (r)
return r;
} else if (pdev->dev.of_node) {
r = tpd_probe_of(pdev);
if (r)
return r;
} else {
return -ENODEV;
}
r = devm_gpio_request_one(&pdev->dev, ddata->ct_cp_hpd_gpio,
GPIOF_OUT_INIT_LOW, "hdmi_ct_cp_hpd");
if (r)
goto err_gpio;
if (gpio_is_valid(ddata->ls_oe_gpio)) {
r = devm_gpio_request_one(&pdev->dev, ddata->ls_oe_gpio,
GPIOF_OUT_INIT_LOW, "hdmi_ls_oe");
if (r)
goto err_gpio;
}
r = devm_gpio_request_one(&pdev->dev, ddata->hpd_gpio,
GPIOF_DIR_IN, "hdmi_hpd");
if (r)
goto err_gpio;
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
