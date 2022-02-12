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
static bool dw_hdmi_imx_encoder_mode_fixup(struct drm_encoder *encoder,
const struct drm_display_mode *mode,
struct drm_display_mode *adj_mode)
{
return true;
}
static void dw_hdmi_imx_encoder_mode_set(struct drm_encoder *encoder,
struct drm_display_mode *mode,
struct drm_display_mode *adj_mode)
{
}
static void dw_hdmi_imx_encoder_commit(struct drm_encoder *encoder)
{
struct imx_hdmi *hdmi = container_of(encoder, struct imx_hdmi, encoder);
int mux = imx_drm_encoder_get_mux_id(hdmi->dev->of_node, encoder);
regmap_update_bits(hdmi->regmap, IOMUXC_GPR3,
IMX6Q_GPR3_HDMI_MUX_CTL_MASK,
mux << IMX6Q_GPR3_HDMI_MUX_CTL_SHIFT);
}
static void dw_hdmi_imx_encoder_prepare(struct drm_encoder *encoder)
{
imx_drm_set_bus_format(encoder, MEDIA_BUS_FMT_RGB888_1X24);
}
static enum drm_mode_status imx6q_hdmi_mode_valid(struct drm_connector *con,
struct drm_display_mode *mode)
{
if (mode->clock < 13500)
return MODE_CLOCK_LOW;
if (mode->clock > 266000)
return MODE_CLOCK_HIGH;
return MODE_OK;
}
static enum drm_mode_status imx6dl_hdmi_mode_valid(struct drm_connector *con,
struct drm_display_mode *mode)
{
if (mode->clock < 13500)
return MODE_CLOCK_LOW;
if (mode->clock > 270000)
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
struct resource *iores;
int irq;
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
irq = platform_get_irq(pdev, 0);
if (irq < 0)
return irq;
iores = platform_get_resource(pdev, IORESOURCE_MEM, 0);
if (!iores)
return -ENXIO;
platform_set_drvdata(pdev, hdmi);
encoder->possible_crtcs = drm_of_find_possible_crtcs(drm, dev->of_node);
if (encoder->possible_crtcs == 0)
return -EPROBE_DEFER;
ret = dw_hdmi_imx_parse_dt(hdmi);
if (ret < 0)
return ret;
drm_encoder_helper_add(encoder, &dw_hdmi_imx_encoder_helper_funcs);
drm_encoder_init(drm, encoder, &dw_hdmi_imx_encoder_funcs,
DRM_MODE_ENCODER_TMDS);
return dw_hdmi_bind(dev, master, data, encoder, iores, irq, plat_data);
}
static void dw_hdmi_imx_unbind(struct device *dev, struct device *master,
void *data)
{
return dw_hdmi_unbind(dev, master, data);
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
