static inline struct vc4_vec_encoder *
to_vc4_vec_encoder(struct drm_encoder *encoder)
{
return container_of(encoder, struct vc4_vec_encoder, base.base);
}
static inline struct vc4_vec_connector *
to_vc4_vec_connector(struct drm_connector *connector)
{
return container_of(connector, struct vc4_vec_connector, base);
}
int vc4_vec_debugfs_regs(struct seq_file *m, void *unused)
{
struct drm_info_node *node = (struct drm_info_node *)m->private;
struct drm_device *dev = node->minor->dev;
struct vc4_dev *vc4 = to_vc4_dev(dev);
struct vc4_vec *vec = vc4->vec;
int i;
if (!vec)
return 0;
for (i = 0; i < ARRAY_SIZE(vec_regs); i++) {
seq_printf(m, "%s (0x%04x): 0x%08x\n",
vec_regs[i].name, vec_regs[i].reg,
VEC_READ(vec_regs[i].reg));
}
return 0;
}
static void vc4_vec_ntsc_mode_set(struct vc4_vec *vec)
{
VEC_WRITE(VEC_CONFIG0, VEC_CONFIG0_NTSC_STD | VEC_CONFIG0_PDEN);
VEC_WRITE(VEC_CONFIG1, VEC_CONFIG1_C_CVBS_CVBS);
}
static void vc4_vec_ntsc_j_mode_set(struct vc4_vec *vec)
{
VEC_WRITE(VEC_CONFIG0, VEC_CONFIG0_NTSC_STD);
VEC_WRITE(VEC_CONFIG1, VEC_CONFIG1_C_CVBS_CVBS);
}
static void vc4_vec_pal_mode_set(struct vc4_vec *vec)
{
VEC_WRITE(VEC_CONFIG0, VEC_CONFIG0_PAL_BDGHI_STD);
VEC_WRITE(VEC_CONFIG1, VEC_CONFIG1_C_CVBS_CVBS);
}
static void vc4_vec_pal_m_mode_set(struct vc4_vec *vec)
{
VEC_WRITE(VEC_CONFIG0, VEC_CONFIG0_PAL_BDGHI_STD);
VEC_WRITE(VEC_CONFIG1,
VEC_CONFIG1_C_CVBS_CVBS | VEC_CONFIG1_CUSTOM_FREQ);
VEC_WRITE(VEC_FREQ3_2, 0x223b);
VEC_WRITE(VEC_FREQ1_0, 0x61d1);
}
static enum drm_connector_status
vc4_vec_connector_detect(struct drm_connector *connector, bool force)
{
return connector_status_unknown;
}
static void vc4_vec_connector_destroy(struct drm_connector *connector)
{
drm_connector_unregister(connector);
drm_connector_cleanup(connector);
}
static int vc4_vec_connector_get_modes(struct drm_connector *connector)
{
struct drm_connector_state *state = connector->state;
struct drm_display_mode *mode;
mode = drm_mode_duplicate(connector->dev,
vc4_vec_tv_modes[state->tv.mode].mode);
if (!mode) {
DRM_ERROR("Failed to create a new display mode\n");
return -ENOMEM;
}
drm_mode_probed_add(connector, mode);
return 1;
}
static struct drm_connector *vc4_vec_connector_init(struct drm_device *dev,
struct vc4_vec *vec)
{
struct drm_connector *connector = NULL;
struct vc4_vec_connector *vec_connector;
vec_connector = devm_kzalloc(dev->dev, sizeof(*vec_connector),
GFP_KERNEL);
if (!vec_connector)
return ERR_PTR(-ENOMEM);
connector = &vec_connector->base;
connector->interlace_allowed = true;
vec_connector->encoder = vec->encoder;
vec_connector->vec = vec;
drm_connector_init(dev, connector, &vc4_vec_connector_funcs,
DRM_MODE_CONNECTOR_Composite);
drm_connector_helper_add(connector, &vc4_vec_connector_helper_funcs);
drm_object_attach_property(&connector->base,
dev->mode_config.tv_mode_property,
VC4_VEC_TV_MODE_NTSC);
vec->tv_mode = &vc4_vec_tv_modes[VC4_VEC_TV_MODE_NTSC];
drm_mode_connector_attach_encoder(connector, vec->encoder);
return connector;
}
static void vc4_vec_encoder_disable(struct drm_encoder *encoder)
{
struct vc4_vec_encoder *vc4_vec_encoder = to_vc4_vec_encoder(encoder);
struct vc4_vec *vec = vc4_vec_encoder->vec;
int ret;
VEC_WRITE(VEC_CFG, 0);
VEC_WRITE(VEC_DAC_MISC,
VEC_DAC_MISC_VCD_PWRDN |
VEC_DAC_MISC_BIAS_PWRDN |
VEC_DAC_MISC_DAC_PWRDN |
VEC_DAC_MISC_LDO_PWRDN);
clk_disable_unprepare(vec->clock);
ret = pm_runtime_put(&vec->pdev->dev);
if (ret < 0) {
DRM_ERROR("Failed to release power domain: %d\n", ret);
return;
}
}
static void vc4_vec_encoder_enable(struct drm_encoder *encoder)
{
struct vc4_vec_encoder *vc4_vec_encoder = to_vc4_vec_encoder(encoder);
struct vc4_vec *vec = vc4_vec_encoder->vec;
int ret;
ret = pm_runtime_get_sync(&vec->pdev->dev);
if (ret < 0) {
DRM_ERROR("Failed to retain power domain: %d\n", ret);
return;
}
ret = clk_set_rate(vec->clock, 108000000);
if (ret) {
DRM_ERROR("Failed to set clock rate: %d\n", ret);
return;
}
ret = clk_prepare_enable(vec->clock);
if (ret) {
DRM_ERROR("Failed to turn on core clock: %d\n", ret);
return;
}
VEC_WRITE(VEC_WSE_RESET, 1);
VEC_WRITE(VEC_SOFT_RESET, 1);
VEC_WRITE(VEC_WSE_CONTROL, 0);
VEC_WRITE(VEC_SCHPH, 0x28);
VEC_WRITE(VEC_CLMP0_START, 0xac);
VEC_WRITE(VEC_CLMP0_END, 0xec);
VEC_WRITE(VEC_CONFIG2,
VEC_CONFIG2_UV_DIG_DIS | VEC_CONFIG2_RGB_DIG_DIS);
VEC_WRITE(VEC_CONFIG3, VEC_CONFIG3_HORIZ_LEN_STD);
VEC_WRITE(VEC_DAC_CONFIG,
VEC_DAC_CONFIG_DAC_CTRL(0xc) |
VEC_DAC_CONFIG_DRIVER_CTRL(0xc) |
VEC_DAC_CONFIG_LDO_BIAS_CTRL(0x46));
VEC_WRITE(VEC_MASK0, 0);
vec->tv_mode->mode_set(vec);
VEC_WRITE(VEC_DAC_MISC,
VEC_DAC_MISC_VID_ACT | VEC_DAC_MISC_DAC_RST_N);
VEC_WRITE(VEC_CFG, VEC_CFG_VEC_EN);
}
static bool vc4_vec_encoder_mode_fixup(struct drm_encoder *encoder,
const struct drm_display_mode *mode,
struct drm_display_mode *adjusted_mode)
{
return true;
}
static void vc4_vec_encoder_atomic_mode_set(struct drm_encoder *encoder,
struct drm_crtc_state *crtc_state,
struct drm_connector_state *conn_state)
{
struct vc4_vec_encoder *vc4_vec_encoder = to_vc4_vec_encoder(encoder);
struct vc4_vec *vec = vc4_vec_encoder->vec;
vec->tv_mode = &vc4_vec_tv_modes[conn_state->tv.mode];
}
static int vc4_vec_encoder_atomic_check(struct drm_encoder *encoder,
struct drm_crtc_state *crtc_state,
struct drm_connector_state *conn_state)
{
const struct vc4_vec_tv_mode *vec_mode;
vec_mode = &vc4_vec_tv_modes[conn_state->tv.mode];
if (conn_state->crtc &&
!drm_mode_equal(vec_mode->mode, &crtc_state->adjusted_mode))
return -EINVAL;
return 0;
}
static int vc4_vec_bind(struct device *dev, struct device *master, void *data)
{
struct platform_device *pdev = to_platform_device(dev);
struct drm_device *drm = dev_get_drvdata(master);
struct vc4_dev *vc4 = to_vc4_dev(drm);
struct vc4_vec *vec;
struct vc4_vec_encoder *vc4_vec_encoder;
int ret;
ret = drm_mode_create_tv_properties(drm, ARRAY_SIZE(tv_mode_names),
tv_mode_names);
if (ret)
return ret;
vec = devm_kzalloc(dev, sizeof(*vec), GFP_KERNEL);
if (!vec)
return -ENOMEM;
vc4_vec_encoder = devm_kzalloc(dev, sizeof(*vc4_vec_encoder),
GFP_KERNEL);
if (!vc4_vec_encoder)
return -ENOMEM;
vc4_vec_encoder->base.type = VC4_ENCODER_TYPE_VEC;
vc4_vec_encoder->vec = vec;
vec->encoder = &vc4_vec_encoder->base.base;
vec->pdev = pdev;
vec->regs = vc4_ioremap_regs(pdev, 0);
if (IS_ERR(vec->regs))
return PTR_ERR(vec->regs);
vec->clock = devm_clk_get(dev, NULL);
if (IS_ERR(vec->clock)) {
ret = PTR_ERR(vec->clock);
if (ret != -EPROBE_DEFER)
DRM_ERROR("Failed to get clock: %d\n", ret);
return ret;
}
pm_runtime_enable(dev);
drm_encoder_init(drm, vec->encoder, &vc4_vec_encoder_funcs,
DRM_MODE_ENCODER_TVDAC, NULL);
drm_encoder_helper_add(vec->encoder, &vc4_vec_encoder_helper_funcs);
vec->connector = vc4_vec_connector_init(drm, vec);
if (IS_ERR(vec->connector)) {
ret = PTR_ERR(vec->connector);
goto err_destroy_encoder;
}
dev_set_drvdata(dev, vec);
vc4->vec = vec;
return 0;
err_destroy_encoder:
drm_encoder_cleanup(vec->encoder);
pm_runtime_disable(dev);
return ret;
}
static void vc4_vec_unbind(struct device *dev, struct device *master,
void *data)
{
struct drm_device *drm = dev_get_drvdata(master);
struct vc4_dev *vc4 = to_vc4_dev(drm);
struct vc4_vec *vec = dev_get_drvdata(dev);
vc4_vec_connector_destroy(vec->connector);
drm_encoder_cleanup(vec->encoder);
pm_runtime_disable(dev);
vc4->vec = NULL;
}
static int vc4_vec_dev_probe(struct platform_device *pdev)
{
return component_add(&pdev->dev, &vc4_vec_ops);
}
static int vc4_vec_dev_remove(struct platform_device *pdev)
{
component_del(&pdev->dev, &vc4_vec_ops);
return 0;
}
