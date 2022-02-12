static enum drm_connector_status imx_pd_connector_detect(
struct drm_connector *connector, bool force)
{
return connector_status_connected;
}
static void imx_pd_connector_destroy(struct drm_connector *connector)
{
}
static int imx_pd_connector_get_modes(struct drm_connector *connector)
{
struct imx_parallel_display *imxpd = con_to_imxpd(connector);
struct device_node *np = imxpd->dev->of_node;
int num_modes = 0;
if (imxpd->edid) {
drm_mode_connector_update_edid_property(connector, imxpd->edid);
num_modes = drm_add_edid_modes(connector, imxpd->edid);
}
if (imxpd->mode_valid) {
struct drm_display_mode *mode = drm_mode_create(connector->dev);
drm_mode_copy(mode, &imxpd->mode);
mode->type |= DRM_MODE_TYPE_DRIVER | DRM_MODE_TYPE_PREFERRED,
drm_mode_probed_add(connector, mode);
num_modes++;
}
if (np) {
struct drm_display_mode *mode = drm_mode_create(connector->dev);
of_get_drm_display_mode(np, &imxpd->mode, 0);
drm_mode_copy(mode, &imxpd->mode);
mode->type |= DRM_MODE_TYPE_DRIVER | DRM_MODE_TYPE_PREFERRED,
drm_mode_probed_add(connector, mode);
num_modes++;
}
return num_modes;
}
static int imx_pd_connector_mode_valid(struct drm_connector *connector,
struct drm_display_mode *mode)
{
return 0;
}
static struct drm_encoder *imx_pd_connector_best_encoder(
struct drm_connector *connector)
{
struct imx_parallel_display *imxpd = con_to_imxpd(connector);
return &imxpd->encoder;
}
static void imx_pd_encoder_dpms(struct drm_encoder *encoder, int mode)
{
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
imx_drm_crtc_panel_format(encoder->crtc, DRM_MODE_ENCODER_NONE,
imxpd->interface_pix_fmt);
}
static void imx_pd_encoder_commit(struct drm_encoder *encoder)
{
}
static void imx_pd_encoder_mode_set(struct drm_encoder *encoder,
struct drm_display_mode *mode,
struct drm_display_mode *adjusted_mode)
{
}
static void imx_pd_encoder_disable(struct drm_encoder *encoder)
{
}
static void imx_pd_encoder_destroy(struct drm_encoder *encoder)
{
}
static int imx_pd_register(struct imx_parallel_display *imxpd)
{
int ret;
drm_mode_connector_attach_encoder(&imxpd->connector, &imxpd->encoder);
imxpd->connector.funcs = &imx_pd_connector_funcs;
imxpd->encoder.funcs = &imx_pd_encoder_funcs;
imxpd->encoder.encoder_type = DRM_MODE_ENCODER_NONE;
imxpd->connector.connector_type = DRM_MODE_CONNECTOR_VGA;
drm_encoder_helper_add(&imxpd->encoder, &imx_pd_encoder_helper_funcs);
ret = imx_drm_add_encoder(&imxpd->encoder, &imxpd->imx_drm_encoder,
THIS_MODULE);
if (ret) {
dev_err(imxpd->dev, "adding encoder failed with %d\n", ret);
return ret;
}
drm_connector_helper_add(&imxpd->connector,
&imx_pd_connector_helper_funcs);
ret = imx_drm_add_connector(&imxpd->connector,
&imxpd->imx_drm_connector, THIS_MODULE);
if (ret) {
imx_drm_remove_encoder(imxpd->imx_drm_encoder);
dev_err(imxpd->dev, "adding connector failed with %d\n", ret);
return ret;
}
imxpd->connector.encoder = &imxpd->encoder;
return 0;
}
static int imx_pd_probe(struct platform_device *pdev)
{
struct device_node *np = pdev->dev.of_node;
const u8 *edidp;
struct imx_parallel_display *imxpd;
int ret;
const char *fmt;
imxpd = devm_kzalloc(&pdev->dev, sizeof(*imxpd), GFP_KERNEL);
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
}
imxpd->dev = &pdev->dev;
ret = imx_pd_register(imxpd);
if (ret)
return ret;
ret = imx_drm_encoder_add_possible_crtcs(imxpd->imx_drm_encoder, np);
platform_set_drvdata(pdev, imxpd);
return 0;
}
static int imx_pd_remove(struct platform_device *pdev)
{
struct imx_parallel_display *imxpd = platform_get_drvdata(pdev);
struct drm_connector *connector = &imxpd->connector;
struct drm_encoder *encoder = &imxpd->encoder;
drm_mode_connector_detach_encoder(connector, encoder);
imx_drm_remove_connector(imxpd->imx_drm_connector);
imx_drm_remove_encoder(imxpd->imx_drm_encoder);
return 0;
}
