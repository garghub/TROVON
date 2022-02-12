static inline struct imx_hdmi *enc_to_imx_hdmi(struct drm_encoder *e)
{
return container_of(e, struct imx_hdmi, encoder);
}
static int dw_hdmi_imx_parse_dt(struct imx_hdmi *hdmi)
{
struct device_node *np = hdmi->dev->of_node;
hdmi->regmap = syscon_regmap_lookup_by_phandle(np, "gpr");
if (IS_ERR(hdmi->regmap)) {
dev_err(hdmi->dev, "Unable to get gpr\n");
return PTR_ERR(hdmi->regmap);
}
return 0;
}
static void dw_hdmi_imx_encoder_disable(struct drm_encoder *encoder)
{
}
static void dw_hdmi_imx_encoder_enable(struct drm_encoder *encoder)
{
struct imx_hdmi *hdmi = enc_to_imx_hdmi(encoder);
int mux = drm_of_encoder_active_port_id(hdmi->dev->of_node, encoder);
regmap_update_bits(hdmi->regmap, IOMUXC_GPR3,
IMX6Q_GPR3_HDMI_MUX_CTL_MASK,
mux << IMX6Q_GPR3_HDMI_MUX_CTL_SHIFT);
}
static int dw_hdmi_imx_atomic_check(struct drm_encoder *encoder,
struct drm_crtc_state *crtc_state,
struct drm_connector_state *conn_state)
{
struct imx_crtc_state *imx_crtc_state = to_imx_crtc_state(crtc_state);
imx_crtc_state->bus_format = MEDIA_BUS_FMT_RGB888_1X24;
imx_crtc_state->di_hsync_pin = 2;
imx_crtc_state->di_vsync_pin = 3;
return 0;
}
static enum drm_mode_status imx6q_hdmi_mode_valid(struct drm_connector *con,
struct drm_display_mode *mode)
{
if (mode->clock < 13500)
return MODE_CLOCK_LOW;
if (mode->clock > 216000)
return MODE_CLOCK_HIGH;
return MODE_OK;
}
static enum drm_mode_status imx6dl_hdmi_mode_valid(struct drm_connector *con,
struct drm_display_mode *mode)
{
if (mode->clock < 13500)
return MODE_CLOCK_LOW;
if (mode->clock > 216000)
return MODE_CLOCK_HIGH;
return MODE_OK;
}
static int dw_hdmi_imx_bind(struct device *dev, struct device *master,
void *data)
{
struct platform_device *pdev = to_platform_device(dev);
const struct dw_hdmi_plat_data *plat_data;
const struct of_device_id *match;
struct drm_device *drm = data;
struct drm_encoder *encoder;
struct imx_hdmi *hdmi;
int ret;
if (!pdev->dev.of_node)
return -ENODEV;
hdmi = devm_kzalloc(&pdev->dev, sizeof(*hdmi), GFP_KERNEL);
if (!hdmi)
return -ENOMEM;
match = of_match_node(dw_hdmi_imx_dt_ids, pdev->dev.of_node);
plat_data = match->data;
hdmi->dev = &pdev->dev;
encoder = &hdmi->encoder;
encoder->possible_crtcs = drm_of_find_possible_crtcs(drm, dev->of_node);
if (encoder->possible_crtcs == 0)
return -EPROBE_DEFER;
ret = dw_hdmi_imx_parse_dt(hdmi);
if (ret < 0)
return ret;
drm_encoder_helper_add(encoder, &dw_hdmi_imx_encoder_helper_funcs);
drm_encoder_init(drm, encoder, &dw_hdmi_imx_encoder_funcs,
DRM_MODE_ENCODER_TMDS, NULL);
ret = dw_hdmi_bind(pdev, encoder, plat_data);
if (ret)
drm_encoder_cleanup(encoder);
return ret;
}
static void dw_hdmi_imx_unbind(struct device *dev, struct device *master,
void *data)
{
return dw_hdmi_unbind(dev);
}
static int dw_hdmi_imx_probe(struct platform_device *pdev)
{
return component_add(&pdev->dev, &dw_hdmi_imx_ops);
}
static int dw_hdmi_imx_remove(struct platform_device *pdev)
{
component_del(&pdev->dev, &dw_hdmi_imx_ops);
return 0;
}
