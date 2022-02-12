static int rockchip_hdmi_parse_dt(struct rockchip_hdmi *hdmi)
{
struct device_node *np = hdmi->dev->of_node;
hdmi->regmap = syscon_regmap_lookup_by_phandle(np, "rockchip,grf");
if (IS_ERR(hdmi->regmap)) {
dev_err(hdmi->dev, "Unable to get rockchip,grf\n");
return PTR_ERR(hdmi->regmap);
}
return 0;
}
static enum drm_mode_status
dw_hdmi_rockchip_mode_valid(struct drm_connector *connector,
struct drm_display_mode *mode)
{
const struct dw_hdmi_mpll_config *mpll_cfg = rockchip_mpll_cfg;
int pclk = mode->clock * 1000;
bool valid = false;
int i;
for (i = 0; mpll_cfg[i].mpixelclock != (~0UL); i++) {
if (pclk == mpll_cfg[i].mpixelclock) {
valid = true;
break;
}
}
return (valid) ? MODE_OK : MODE_BAD;
}
static void dw_hdmi_rockchip_encoder_disable(struct drm_encoder *encoder)
{
}
static bool
dw_hdmi_rockchip_encoder_mode_fixup(struct drm_encoder *encoder,
const struct drm_display_mode *mode,
struct drm_display_mode *adj_mode)
{
return true;
}
static void dw_hdmi_rockchip_encoder_mode_set(struct drm_encoder *encoder,
struct drm_display_mode *mode,
struct drm_display_mode *adj_mode)
{
}
static void dw_hdmi_rockchip_encoder_enable(struct drm_encoder *encoder)
{
struct rockchip_hdmi *hdmi = to_rockchip_hdmi(encoder);
u32 val;
int mux;
rockchip_drm_crtc_mode_config(encoder->crtc, DRM_MODE_CONNECTOR_HDMIA,
ROCKCHIP_OUT_MODE_AAAA);
mux = drm_of_encoder_active_endpoint_id(hdmi->dev->of_node, encoder);
if (mux)
val = HDMI_SEL_VOP_LIT | (HDMI_SEL_VOP_LIT << 16);
else
val = HDMI_SEL_VOP_LIT << 16;
regmap_write(hdmi->regmap, GRF_SOC_CON6, val);
dev_dbg(hdmi->dev, "vop %s output to hdmi\n",
(mux) ? "LIT" : "BIG");
}
static int dw_hdmi_rockchip_bind(struct device *dev, struct device *master,
void *data)
{
struct platform_device *pdev = to_platform_device(dev);
const struct dw_hdmi_plat_data *plat_data;
const struct of_device_id *match;
struct drm_device *drm = data;
struct drm_encoder *encoder;
struct rockchip_hdmi *hdmi;
struct resource *iores;
int irq;
int ret;
if (!pdev->dev.of_node)
return -ENODEV;
hdmi = devm_kzalloc(&pdev->dev, sizeof(*hdmi), GFP_KERNEL);
if (!hdmi)
return -ENOMEM;
match = of_match_node(dw_hdmi_rockchip_dt_ids, pdev->dev.of_node);
plat_data = match->data;
hdmi->dev = &pdev->dev;
encoder = &hdmi->encoder;
irq = platform_get_irq(pdev, 0);
if (irq < 0)
return irq;
iores = platform_get_resource(pdev, IORESOURCE_MEM, 0);
if (!iores)
return -ENXIO;
encoder->possible_crtcs = drm_of_find_possible_crtcs(drm, dev->of_node);
if (encoder->possible_crtcs == 0)
return -EPROBE_DEFER;
ret = rockchip_hdmi_parse_dt(hdmi);
if (ret) {
dev_err(hdmi->dev, "Unable to parse OF data\n");
return ret;
}
drm_encoder_helper_add(encoder, &dw_hdmi_rockchip_encoder_helper_funcs);
drm_encoder_init(drm, encoder, &dw_hdmi_rockchip_encoder_funcs,
DRM_MODE_ENCODER_TMDS, NULL);
ret = dw_hdmi_bind(dev, master, data, encoder, iores, irq, plat_data);
if (ret)
drm_encoder_cleanup(encoder);
return ret;
}
static void dw_hdmi_rockchip_unbind(struct device *dev, struct device *master,
void *data)
{
return dw_hdmi_unbind(dev, master, data);
}
static int dw_hdmi_rockchip_probe(struct platform_device *pdev)
{
return component_add(&pdev->dev, &dw_hdmi_rockchip_ops);
}
static int dw_hdmi_rockchip_remove(struct platform_device *pdev)
{
component_del(&pdev->dev, &dw_hdmi_rockchip_ops);
return 0;
}
