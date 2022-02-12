static enum drm_connector_status imx_pd_connector_detect(
struct drm_connector *connector, bool force)
{
return connector_status_connected;
}
static int imx_pd_connector_get_modes(struct drm_connector *connector)
{
struct imx_parallel_display *imxpd = con_to_imxpd(connector);
struct device_node *np = imxpd->dev->of_node;
int num_modes = 0;
if (imxpd->panel && imxpd->panel->funcs &&
imxpd->panel->funcs->get_modes) {
num_modes = imxpd->panel->funcs->get_modes(imxpd->panel);
if (num_modes > 0)
return num_modes;
}
if (imxpd->edid) {
drm_mode_connector_update_edid_property(connector, imxpd->edid);
num_modes = drm_add_edid_modes(connector, imxpd->edid);
}
if (imxpd->mode_valid) {
struct drm_display_mode *mode = drm_mode_create(connector->dev);
if (!mode)
return -EINVAL;
drm_mode_copy(mode, &imxpd->mode);
mode->type |= DRM_MODE_TYPE_DRIVER | DRM_MODE_TYPE_PREFERRED,
drm_mode_probed_add(connector, mode);
num_modes++;
}
if (np) {
struct drm_display_mode *mode = drm_mode_create(connector->dev);
if (!mode)
return -EINVAL;
of_get_drm_display_mode(np, &imxpd->mode, OF_USE_NATIVE_MODE);
drm_mode_copy(mode, &imxpd->mode);
mode->type |= DRM_MODE_TYPE_DRIVER | DRM_MODE_TYPE_PREFERRED,
drm_mode_probed_add(connector, mode);
num_modes++;
}
return num_modes;
}
static struct drm_encoder *imx_pd_connector_best_encoder(
struct drm_connector *connector)
{
struct imx_parallel_display *imxpd = con_to_imxpd(connector);
return &imxpd->encoder;
}
static void imx_pd_encoder_dpms(struct drm_encoder *encoder, int mode)
{
struct imx_parallel_display *imxpd = enc_to_imxpd(encoder);
if (mode != DRM_MODE_DPMS_ON)
drm_panel_disable(imxpd->panel);
else
drm_panel_enable(imxpd->panel);
}
static bool imx_pd_encoder_mode_fixup(struct drm_encoder *encoder,
const struct drm_display_mode *mode,
struct drm_display_mode *adjusted_mode)
{
return true;
}
static void imx_pd_encoder_prepare(struct drm_encoder *encoder)
{
struct imx_parallel_display *imxpd = enc_to_imxpd(encoder);
imx_drm_panel_format(encoder, imxpd->interface_pix_fmt);
}
static void imx_pd_encoder_commit(struct drm_encoder *encoder)
{
struct imx_parallel_display *imxpd = enc_to_imxpd(encoder);
drm_panel_prepare(imxpd->panel);
drm_panel_enable(imxpd->panel);
}
static void imx_pd_encoder_mode_set(struct drm_encoder *encoder,
struct drm_display_mode *mode,
struct drm_display_mode *adjusted_mode)
{
}
static void imx_pd_encoder_disable(struct drm_encoder *encoder)
{
struct imx_parallel_display *imxpd = enc_to_imxpd(encoder);
drm_panel_disable(imxpd->panel);
drm_panel_unprepare(imxpd->panel);
}
static int imx_pd_register(struct drm_device *drm,
struct imx_parallel_display *imxpd)
{
int ret;
ret = imx_drm_encoder_parse_of(drm, &imxpd->encoder,
imxpd->dev->of_node);
if (ret)
return ret;
imxpd->connector.dpms = DRM_MODE_DPMS_OFF;
drm_encoder_helper_add(&imxpd->encoder, &imx_pd_encoder_helper_funcs);
drm_encoder_init(drm, &imxpd->encoder, &imx_pd_encoder_funcs,
DRM_MODE_ENCODER_NONE);
drm_connector_helper_add(&imxpd->connector,
&imx_pd_connector_helper_funcs);
drm_connector_init(drm, &imxpd->connector, &imx_pd_connector_funcs,
DRM_MODE_CONNECTOR_VGA);
if (imxpd->panel)
drm_panel_attach(imxpd->panel, &imxpd->connector);
drm_mode_connector_attach_encoder(&imxpd->connector, &imxpd->encoder);
imxpd->connector.encoder = &imxpd->encoder;
return 0;
}
static int imx_pd_bind(struct device *dev, struct device *master, void *data)
{
struct drm_device *drm = data;
struct device_node *np = dev->of_node;
struct device_node *panel_node;
const u8 *edidp;
struct imx_parallel_display *imxpd;
int ret;
const char *fmt;
imxpd = devm_kzalloc(dev, sizeof(*imxpd), GFP_KERNEL);
if (!imxpd)
return -ENOMEM;
edidp = of_get_property(np, "edid", &imxpd->edid_len);
if (edidp)
imxpd->edid = kmemdup(edidp, imxpd->edid_len, GFP_KERNEL);
ret = of_property_read_string(np, "interface-pix-fmt", &fmt);
if (!ret) {
if (!strcmp(fmt, "rgb24"))
imxpd->interface_pix_fmt = V4L2_PIX_FMT_RGB24;
else if (!strcmp(fmt, "rgb565"))
imxpd->interface_pix_fmt = V4L2_PIX_FMT_RGB565;
else if (!strcmp(fmt, "bgr666"))
imxpd->interface_pix_fmt = V4L2_PIX_FMT_BGR666;
else if (!strcmp(fmt, "lvds666"))
imxpd->interface_pix_fmt =
v4l2_fourcc('L', 'V', 'D', '6');
}
panel_node = of_parse_phandle(np, "fsl,panel", 0);
if (panel_node)
imxpd->panel = of_drm_find_panel(panel_node);
imxpd->dev = dev;
ret = imx_pd_register(drm, imxpd);
if (ret)
return ret;
dev_set_drvdata(dev, imxpd);
return 0;
}
static void imx_pd_unbind(struct device *dev, struct device *master,
void *data)
{
struct imx_parallel_display *imxpd = dev_get_drvdata(dev);
imxpd->encoder.funcs->destroy(&imxpd->encoder);
imxpd->connector.funcs->destroy(&imxpd->connector);
}
static int imx_pd_probe(struct platform_device *pdev)
{
return component_add(&pdev->dev, &imx_pd_ops);
}
static int imx_pd_remove(struct platform_device *pdev)
{
component_del(&pdev->dev, &imx_pd_ops);
return 0;
}
