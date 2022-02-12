static const struct zx_tvenc_mode *
zx_tvenc_find_zmode(struct drm_display_mode *mode)
{
int i;
for (i = 0; i < ARRAY_SIZE(tvenc_modes); i++) {
const struct zx_tvenc_mode *zmode = tvenc_modes[i];
if (drm_mode_equal(mode, &zmode->mode))
return zmode;
}
return NULL;
}
static void zx_tvenc_encoder_mode_set(struct drm_encoder *encoder,
struct drm_display_mode *mode,
struct drm_display_mode *adj_mode)
{
struct zx_tvenc *tvenc = to_zx_tvenc(encoder);
const struct zx_tvenc_mode *zmode;
struct vou_div_config configs[] = {
{ VOU_DIV_INF, VOU_DIV_4 },
{ VOU_DIV_TVENC, VOU_DIV_1 },
{ VOU_DIV_LAYER, VOU_DIV_2 },
};
zx_vou_config_dividers(encoder->crtc, configs, ARRAY_SIZE(configs));
zmode = zx_tvenc_find_zmode(mode);
if (!zmode) {
DRM_DEV_ERROR(tvenc->dev, "failed to find zmode\n");
return;
}
zx_writel(tvenc->mmio + VENC_VIDEO_INFO, zmode->video_info);
zx_writel(tvenc->mmio + VENC_VIDEO_RES, zmode->video_res);
zx_writel(tvenc->mmio + VENC_FIELD1_PARAM, zmode->field1_param);
zx_writel(tvenc->mmio + VENC_FIELD2_PARAM, zmode->field2_param);
zx_writel(tvenc->mmio + VENC_LINE_O_1, zmode->burst_line_odd1);
zx_writel(tvenc->mmio + VENC_LINE_E_1, zmode->burst_line_even1);
zx_writel(tvenc->mmio + VENC_LINE_O_2, zmode->burst_line_odd2);
zx_writel(tvenc->mmio + VENC_LINE_E_2, zmode->burst_line_even2);
zx_writel(tvenc->mmio + VENC_LINE_TIMING_PARAM,
zmode->line_timing_param);
zx_writel(tvenc->mmio + VENC_WEIGHT_VALUE, zmode->weight_value);
zx_writel(tvenc->mmio + VENC_BLANK_BLACK_LEVEL,
zmode->blank_black_level);
zx_writel(tvenc->mmio + VENC_BURST_LEVEL, zmode->burst_level);
zx_writel(tvenc->mmio + VENC_CONTROL_PARAM, zmode->control_param);
zx_writel(tvenc->mmio + VENC_SUB_CARRIER_PHASE1,
zmode->sub_carrier_phase1);
zx_writel(tvenc->mmio + VENC_PHASE_LINE_INCR_CVBS,
zmode->phase_line_incr_cvbs);
}
static void zx_tvenc_encoder_enable(struct drm_encoder *encoder)
{
struct zx_tvenc *tvenc = to_zx_tvenc(encoder);
struct zx_tvenc_pwrctrl *pwrctrl = &tvenc->pwrctrl;
regmap_update_bits(pwrctrl->regmap, pwrctrl->reg, pwrctrl->mask,
pwrctrl->mask);
vou_inf_enable(VOU_TV_ENC, encoder->crtc);
zx_writel(tvenc->mmio + VENC_ENABLE, 1);
}
static void zx_tvenc_encoder_disable(struct drm_encoder *encoder)
{
struct zx_tvenc *tvenc = to_zx_tvenc(encoder);
struct zx_tvenc_pwrctrl *pwrctrl = &tvenc->pwrctrl;
zx_writel(tvenc->mmio + VENC_ENABLE, 0);
vou_inf_disable(VOU_TV_ENC, encoder->crtc);
regmap_update_bits(pwrctrl->regmap, pwrctrl->reg, pwrctrl->mask, 0);
}
static int zx_tvenc_connector_get_modes(struct drm_connector *connector)
{
struct zx_tvenc *tvenc = to_zx_tvenc(connector);
struct device *dev = tvenc->dev;
int i;
for (i = 0; i < ARRAY_SIZE(tvenc_modes); i++) {
const struct zx_tvenc_mode *zmode = tvenc_modes[i];
struct drm_display_mode *mode;
mode = drm_mode_duplicate(connector->dev, &zmode->mode);
if (!mode) {
DRM_DEV_ERROR(dev, "failed to duplicate drm mode\n");
continue;
}
drm_mode_set_name(mode);
drm_mode_probed_add(connector, mode);
}
return i;
}
static enum drm_mode_status
zx_tvenc_connector_mode_valid(struct drm_connector *connector,
struct drm_display_mode *mode)
{
struct zx_tvenc *tvenc = to_zx_tvenc(connector);
const struct zx_tvenc_mode *zmode;
zmode = zx_tvenc_find_zmode(mode);
if (!zmode) {
DRM_DEV_ERROR(tvenc->dev, "unsupported mode: %s\n", mode->name);
return MODE_NOMODE;
}
return MODE_OK;
}
static int zx_tvenc_register(struct drm_device *drm, struct zx_tvenc *tvenc)
{
struct drm_encoder *encoder = &tvenc->encoder;
struct drm_connector *connector = &tvenc->connector;
encoder->possible_crtcs = BIT(1);
drm_encoder_init(drm, encoder, &zx_tvenc_encoder_funcs,
DRM_MODE_ENCODER_TVDAC, NULL);
drm_encoder_helper_add(encoder, &zx_tvenc_encoder_helper_funcs);
connector->interlace_allowed = true;
drm_connector_init(drm, connector, &zx_tvenc_connector_funcs,
DRM_MODE_CONNECTOR_Composite);
drm_connector_helper_add(connector, &zx_tvenc_connector_helper_funcs);
drm_mode_connector_attach_encoder(connector, encoder);
return 0;
}
static int zx_tvenc_pwrctrl_init(struct zx_tvenc *tvenc)
{
struct zx_tvenc_pwrctrl *pwrctrl = &tvenc->pwrctrl;
struct device *dev = tvenc->dev;
struct of_phandle_args out_args;
struct regmap *regmap;
int ret;
ret = of_parse_phandle_with_fixed_args(dev->of_node,
"zte,tvenc-power-control", 2, 0, &out_args);
if (ret)
return ret;
regmap = syscon_node_to_regmap(out_args.np);
if (IS_ERR(regmap)) {
ret = PTR_ERR(regmap);
goto out;
}
pwrctrl->regmap = regmap;
pwrctrl->reg = out_args.args[0];
pwrctrl->mask = out_args.args[1];
out:
of_node_put(out_args.np);
return ret;
}
static int zx_tvenc_bind(struct device *dev, struct device *master, void *data)
{
struct platform_device *pdev = to_platform_device(dev);
struct drm_device *drm = data;
struct resource *res;
struct zx_tvenc *tvenc;
int ret;
tvenc = devm_kzalloc(dev, sizeof(*tvenc), GFP_KERNEL);
if (!tvenc)
return -ENOMEM;
tvenc->dev = dev;
dev_set_drvdata(dev, tvenc);
res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
tvenc->mmio = devm_ioremap_resource(dev, res);
if (IS_ERR(tvenc->mmio)) {
ret = PTR_ERR(tvenc->mmio);
DRM_DEV_ERROR(dev, "failed to remap tvenc region: %d\n", ret);
return ret;
}
ret = zx_tvenc_pwrctrl_init(tvenc);
if (ret) {
DRM_DEV_ERROR(dev, "failed to init power control: %d\n", ret);
return ret;
}
ret = zx_tvenc_register(drm, tvenc);
if (ret) {
DRM_DEV_ERROR(dev, "failed to register tvenc: %d\n", ret);
return ret;
}
return 0;
}
static void zx_tvenc_unbind(struct device *dev, struct device *master,
void *data)
{
}
static int zx_tvenc_probe(struct platform_device *pdev)
{
return component_add(&pdev->dev, &zx_tvenc_component_ops);
}
static int zx_tvenc_remove(struct platform_device *pdev)
{
component_del(&pdev->dev, &zx_tvenc_component_ops);
return 0;
}
