static int rockchip_dp_pre_init(struct rockchip_dp_device *dp)
{
reset_control_assert(dp->rst);
usleep_range(10, 20);
reset_control_deassert(dp->rst);
return 0;
}
static int rockchip_dp_poweron(struct analogix_dp_plat_data *plat_data)
{
struct rockchip_dp_device *dp = to_dp(plat_data);
int ret;
ret = clk_prepare_enable(dp->pclk);
if (ret < 0) {
dev_err(dp->dev, "failed to enable pclk %d\n", ret);
return ret;
}
ret = rockchip_dp_pre_init(dp);
if (ret < 0) {
dev_err(dp->dev, "failed to dp pre init %d\n", ret);
return ret;
}
return 0;
}
static int rockchip_dp_powerdown(struct analogix_dp_plat_data *plat_data)
{
struct rockchip_dp_device *dp = to_dp(plat_data);
clk_disable_unprepare(dp->pclk);
return 0;
}
static bool
rockchip_dp_drm_encoder_mode_fixup(struct drm_encoder *encoder,
const struct drm_display_mode *mode,
struct drm_display_mode *adjusted_mode)
{
return true;
}
static void rockchip_dp_drm_encoder_mode_set(struct drm_encoder *encoder,
struct drm_display_mode *mode,
struct drm_display_mode *adjusted)
{
}
static void rockchip_dp_drm_encoder_enable(struct drm_encoder *encoder)
{
struct rockchip_dp_device *dp = to_dp(encoder);
int ret;
u32 val;
ret = drm_of_encoder_active_endpoint_id(dp->dev->of_node, encoder);
if (ret < 0)
return;
if (ret)
val = GRF_EDP_SEL_VOP_LIT | (GRF_EDP_LCD_SEL_MASK << 16);
else
val = GRF_EDP_SEL_VOP_BIG | (GRF_EDP_LCD_SEL_MASK << 16);
dev_dbg(dp->dev, "vop %s output to dp\n", (ret) ? "LIT" : "BIG");
ret = regmap_write(dp->grf, GRF_SOC_CON6, val);
if (ret != 0) {
dev_err(dp->dev, "Could not write to GRF: %d\n", ret);
return;
}
}
static void rockchip_dp_drm_encoder_nop(struct drm_encoder *encoder)
{
}
static int
rockchip_dp_drm_encoder_atomic_check(struct drm_encoder *encoder,
struct drm_crtc_state *crtc_state,
struct drm_connector_state *conn_state)
{
struct rockchip_crtc_state *s = to_rockchip_crtc_state(crtc_state);
s->output_mode = ROCKCHIP_OUT_MODE_AAAA;
s->output_type = DRM_MODE_CONNECTOR_eDP;
return 0;
}
static void rockchip_dp_drm_encoder_destroy(struct drm_encoder *encoder)
{
drm_encoder_cleanup(encoder);
}
static int rockchip_dp_init(struct rockchip_dp_device *dp)
{
struct device *dev = dp->dev;
struct device_node *np = dev->of_node;
int ret;
dp->grf = syscon_regmap_lookup_by_phandle(np, "rockchip,grf");
if (IS_ERR(dp->grf)) {
dev_err(dev, "failed to get rockchip,grf property\n");
return PTR_ERR(dp->grf);
}
dp->pclk = devm_clk_get(dev, "pclk");
if (IS_ERR(dp->pclk)) {
dev_err(dev, "failed to get pclk property\n");
return PTR_ERR(dp->pclk);
}
dp->rst = devm_reset_control_get(dev, "dp");
if (IS_ERR(dp->rst)) {
dev_err(dev, "failed to get dp reset control\n");
return PTR_ERR(dp->rst);
}
ret = clk_prepare_enable(dp->pclk);
if (ret < 0) {
dev_err(dp->dev, "failed to enable pclk %d\n", ret);
return ret;
}
ret = rockchip_dp_pre_init(dp);
if (ret < 0) {
dev_err(dp->dev, "failed to pre init %d\n", ret);
return ret;
}
return 0;
}
static int rockchip_dp_drm_create_encoder(struct rockchip_dp_device *dp)
{
struct drm_encoder *encoder = &dp->encoder;
struct drm_device *drm_dev = dp->drm_dev;
struct device *dev = dp->dev;
int ret;
encoder->possible_crtcs = drm_of_find_possible_crtcs(drm_dev,
dev->of_node);
DRM_DEBUG_KMS("possible_crtcs = 0x%x\n", encoder->possible_crtcs);
ret = drm_encoder_init(drm_dev, encoder, &rockchip_dp_encoder_funcs,
DRM_MODE_ENCODER_TMDS, NULL);
if (ret) {
DRM_ERROR("failed to initialize encoder with drm\n");
return ret;
}
drm_encoder_helper_add(encoder, &rockchip_dp_encoder_helper_funcs);
return 0;
}
static int rockchip_dp_bind(struct device *dev, struct device *master,
void *data)
{
struct rockchip_dp_device *dp = dev_get_drvdata(dev);
struct drm_device *drm_dev = data;
int ret;
dev_set_drvdata(dev, NULL);
ret = rockchip_dp_init(dp);
if (ret < 0)
return ret;
dp->drm_dev = drm_dev;
ret = rockchip_dp_drm_create_encoder(dp);
if (ret) {
DRM_ERROR("failed to create drm encoder\n");
return ret;
}
dp->plat_data.encoder = &dp->encoder;
dp->plat_data.dev_type = RK3288_DP;
dp->plat_data.power_on = rockchip_dp_poweron;
dp->plat_data.power_off = rockchip_dp_powerdown;
return analogix_dp_bind(dev, dp->drm_dev, &dp->plat_data);
}
static void rockchip_dp_unbind(struct device *dev, struct device *master,
void *data)
{
return analogix_dp_unbind(dev, master, data);
}
static int rockchip_dp_probe(struct platform_device *pdev)
{
struct device *dev = &pdev->dev;
struct device_node *panel_node, *port, *endpoint;
struct rockchip_dp_device *dp;
struct drm_panel *panel;
port = of_graph_get_port_by_id(dev->of_node, 1);
if (!port) {
dev_err(dev, "can't find output port\n");
return -EINVAL;
}
endpoint = of_get_child_by_name(port, "endpoint");
of_node_put(port);
if (!endpoint) {
dev_err(dev, "no output endpoint found\n");
return -EINVAL;
}
panel_node = of_graph_get_remote_port_parent(endpoint);
of_node_put(endpoint);
if (!panel_node) {
dev_err(dev, "no output node found\n");
return -EINVAL;
}
panel = of_drm_find_panel(panel_node);
if (!panel) {
DRM_ERROR("failed to find panel\n");
of_node_put(panel_node);
return -EPROBE_DEFER;
}
of_node_put(panel_node);
dp = devm_kzalloc(dev, sizeof(*dp), GFP_KERNEL);
if (!dp)
return -ENOMEM;
dp->dev = dev;
dp->plat_data.panel = panel;
platform_set_drvdata(pdev, dp);
return component_add(dev, &rockchip_dp_component_ops);
}
static int rockchip_dp_remove(struct platform_device *pdev)
{
component_del(&pdev->dev, &rockchip_dp_component_ops);
return 0;
}
static int rockchip_dp_suspend(struct device *dev)
{
return analogix_dp_suspend(dev);
}
static int rockchip_dp_resume(struct device *dev)
{
return analogix_dp_resume(dev);
}
