static int rockchip_hdmi_parse_dt(struct rockchip_hdmi *hdmi)
{
struct device_node *np = hdmi->dev->of_node;
int ret;
hdmi->regmap = syscon_regmap_lookup_by_phandle(np, "rockchip,grf");
if (IS_ERR(hdmi->regmap)) {
dev_err(hdmi->dev, "Unable to get rockchip,grf\n");
return PTR_ERR(hdmi->regmap);
}
hdmi->vpll_clk = devm_clk_get(hdmi->dev, "vpll");
if (PTR_ERR(hdmi->vpll_clk) == -ENOENT) {
hdmi->vpll_clk = NULL;
} else if (PTR_ERR(hdmi->vpll_clk) == -EPROBE_DEFER) {
return -EPROBE_DEFER;
} else if (IS_ERR(hdmi->vpll_clk)) {
dev_err(hdmi->dev, "failed to get grf clock\n");
return PTR_ERR(hdmi->vpll_clk);
}
hdmi->grf_clk = devm_clk_get(hdmi->dev, "grf");
if (PTR_ERR(hdmi->grf_clk) == -ENOENT) {
hdmi->grf_clk = NULL;
} else if (PTR_ERR(hdmi->grf_clk) == -EPROBE_DEFER) {
return -EPROBE_DEFER;
} else if (IS_ERR(hdmi->grf_clk)) {
dev_err(hdmi->dev, "failed to get grf clock\n");
return PTR_ERR(hdmi->grf_clk);
}
ret = clk_prepare_enable(hdmi->vpll_clk);
if (ret) {
dev_err(hdmi->dev, "Failed to enable HDMI vpll: %d\n", ret);
return ret;
}
return 0;
}
static enum drm_mode_status
dw_hdmi_rockchip_mode_valid(struct drm_connector *connector,
const struct drm_display_mode *mode)
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
struct rockchip_hdmi *hdmi = to_rockchip_hdmi(encoder);
clk_set_rate(hdmi->vpll_clk, adj_mode->clock * 1000);
}
static void dw_hdmi_rockchip_encoder_enable(struct drm_encoder *encoder)
{
struct rockchip_hdmi *hdmi = to_rockchip_hdmi(encoder);
u32 val;
int ret;
ret = drm_of_encoder_active_endpoint_id(hdmi->dev->of_node, encoder);
if (ret)
val = hdmi->chip_data->lcdsel_lit;
else
val = hdmi->chip_data->lcdsel_big;
ret = clk_prepare_enable(hdmi->grf_clk);
if (ret < 0) {
dev_err(hdmi->dev, "failed to enable grfclk %d\n", ret);
return;
}
ret = regmap_write(hdmi->regmap, hdmi->chip_data->lcdsel_grf_reg, val);
if (ret != 0)
dev_err(hdmi->dev, "Could not write to GRF: %d\n", ret);
clk_disable_unprepare(hdmi->grf_clk);
dev_dbg(hdmi->dev, "vop %s output to hdmi\n",
ret ? "LIT" : "BIG");
}
static int
dw_hdmi_rockchip_encoder_atomic_check(struct drm_encoder *encoder,
struct drm_crtc_state *crtc_state,
struct drm_connector_state *conn_state)
{
struct rockchip_crtc_state *s = to_rockchip_crtc_state(crtc_state);
s->output_mode = ROCKCHIP_OUT_MODE_AAAA;
s->output_type = DRM_MODE_CONNECTOR_HDMIA;
return 0;
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
int ret;
if (!pdev->dev.of_node)
return -ENODEV;
hdmi = devm_kzalloc(&pdev->dev, sizeof(*hdmi), GFP_KERNEL);
if (!hdmi)
return -ENOMEM;
match = of_match_node(dw_hdmi_rockchip_dt_ids, pdev->dev.of_node);
plat_data = match->data;
hdmi->dev = &pdev->dev;
hdmi->chip_data = plat_data->phy_data;
encoder = &hdmi->encoder;
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
ret = dw_hdmi_bind(pdev, encoder, plat_data);
if (ret)
drm_encoder_cleanup(encoder);
return ret;
}
static void dw_hdmi_rockchip_unbind(struct device *dev, struct device *master,
void *data)
{
return dw_hdmi_unbind(dev);
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
