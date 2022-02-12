static inline struct sun4i_tv *
drm_encoder_to_sun4i_tv(struct drm_encoder *encoder)
{
return container_of(encoder, struct sun4i_tv,
encoder);
}
static inline struct sun4i_tv *
drm_connector_to_sun4i_tv(struct drm_connector *connector)
{
return container_of(connector, struct sun4i_tv,
connector);
}
static const struct tv_mode *sun4i_tv_find_tv_by_mode(const struct drm_display_mode *mode)
{
int i;
for (i = 0; i < ARRAY_SIZE(tv_modes); i++) {
const struct tv_mode *tv_mode = &tv_modes[i];
DRM_DEBUG_DRIVER("Comparing mode %s vs %s",
mode->name, tv_mode->name);
if (!strcmp(mode->name, tv_mode->name))
return tv_mode;
}
for (i = 0; i < ARRAY_SIZE(tv_modes); i++) {
const struct tv_mode *tv_mode = &tv_modes[i];
DRM_DEBUG_DRIVER("Comparing mode %s vs %s (X: %d vs %d)",
mode->name, tv_mode->name,
mode->vdisplay, tv_mode->vdisplay);
if (mode->vdisplay == tv_mode->vdisplay)
return tv_mode;
}
return NULL;
}
static void sun4i_tv_mode_to_drm_mode(const struct tv_mode *tv_mode,
struct drm_display_mode *mode)
{
DRM_DEBUG_DRIVER("Creating mode %s\n", mode->name);
mode->type = DRM_MODE_TYPE_DRIVER;
mode->clock = 13500;
mode->flags = DRM_MODE_FLAG_INTERLACE;
mode->hdisplay = tv_mode->hdisplay;
mode->hsync_start = mode->hdisplay + tv_mode->hfront_porch;
mode->hsync_end = mode->hsync_start + tv_mode->hsync_len;
mode->htotal = mode->hsync_end + tv_mode->hback_porch;
mode->vdisplay = tv_mode->vdisplay;
mode->vsync_start = mode->vdisplay + tv_mode->vfront_porch;
mode->vsync_end = mode->vsync_start + tv_mode->vsync_len;
mode->vtotal = mode->vsync_end + tv_mode->vback_porch;
}
static void sun4i_tv_disable(struct drm_encoder *encoder)
{
struct sun4i_tv *tv = drm_encoder_to_sun4i_tv(encoder);
struct sun4i_crtc *crtc = drm_crtc_to_sun4i_crtc(encoder->crtc);
struct sun4i_tcon *tcon = crtc->tcon;
DRM_DEBUG_DRIVER("Disabling the TV Output\n");
sun4i_tcon_channel_disable(tcon, 1);
regmap_update_bits(tv->regs, SUN4I_TVE_EN_REG,
SUN4I_TVE_EN_ENABLE,
0);
sunxi_engine_disable_color_correction(crtc->engine);
}
static void sun4i_tv_enable(struct drm_encoder *encoder)
{
struct sun4i_tv *tv = drm_encoder_to_sun4i_tv(encoder);
struct sun4i_crtc *crtc = drm_crtc_to_sun4i_crtc(encoder->crtc);
struct sun4i_tcon *tcon = crtc->tcon;
DRM_DEBUG_DRIVER("Enabling the TV Output\n");
sunxi_engine_apply_color_correction(crtc->engine);
regmap_update_bits(tv->regs, SUN4I_TVE_EN_REG,
SUN4I_TVE_EN_ENABLE,
SUN4I_TVE_EN_ENABLE);
sun4i_tcon_channel_enable(tcon, 1);
}
static void sun4i_tv_mode_set(struct drm_encoder *encoder,
struct drm_display_mode *mode,
struct drm_display_mode *adjusted_mode)
{
struct sun4i_tv *tv = drm_encoder_to_sun4i_tv(encoder);
struct sun4i_crtc *crtc = drm_crtc_to_sun4i_crtc(encoder->crtc);
struct sun4i_tcon *tcon = crtc->tcon;
const struct tv_mode *tv_mode = sun4i_tv_find_tv_by_mode(mode);
sun4i_tcon1_mode_set(tcon, mode);
sun4i_tcon_set_mux(tcon, 1, encoder);
regmap_update_bits(tv->regs, SUN4I_TVE_EN_REG,
SUN4I_TVE_EN_DAC_MAP_MASK,
SUN4I_TVE_EN_DAC_MAP(0, 1) |
SUN4I_TVE_EN_DAC_MAP(1, 2) |
SUN4I_TVE_EN_DAC_MAP(2, 3) |
SUN4I_TVE_EN_DAC_MAP(3, 4));
regmap_write(tv->regs, SUN4I_TVE_CFG0_REG,
tv_mode->mode |
(tv_mode->yc_en ? SUN4I_TVE_CFG0_YC_EN : 0) |
SUN4I_TVE_CFG0_COMP_EN |
SUN4I_TVE_CFG0_DAC_CONTROL_54M |
SUN4I_TVE_CFG0_CORE_DATAPATH_54M |
SUN4I_TVE_CFG0_CORE_CONTROL_54M);
regmap_write(tv->regs, SUN4I_TVE_DAC0_REG,
SUN4I_TVE_DAC0_DAC_EN(0) |
(tv_mode->dac3_en ? SUN4I_TVE_DAC0_DAC_EN(3) : 0) |
SUN4I_TVE_DAC0_INTERNAL_DAC_37_5_OHMS |
SUN4I_TVE_DAC0_CHROMA_0_75 |
SUN4I_TVE_DAC0_LUMA_0_4 |
SUN4I_TVE_DAC0_CLOCK_INVERT |
(tv_mode->dac_bit25_en ? BIT(25) : 0) |
BIT(30));
regmap_write(tv->regs, SUN4I_TVE_NOTCH_REG,
SUN4I_TVE_NOTCH_DAC0_TO_DAC_DLY(1, 0) |
SUN4I_TVE_NOTCH_DAC0_TO_DAC_DLY(2, 0));
regmap_write(tv->regs, SUN4I_TVE_CHROMA_FREQ_REG,
tv_mode->chroma_freq);
regmap_write(tv->regs, SUN4I_TVE_PORCH_REG,
SUN4I_TVE_PORCH_BACK(tv_mode->back_porch) |
SUN4I_TVE_PORCH_FRONT(tv_mode->front_porch));
regmap_write(tv->regs, SUN4I_TVE_LINE_REG,
SUN4I_TVE_LINE_FIRST(22) |
SUN4I_TVE_LINE_NUMBER(tv_mode->line_number));
regmap_write(tv->regs, SUN4I_TVE_LEVEL_REG,
SUN4I_TVE_LEVEL_BLANK(tv_mode->video_levels->blank) |
SUN4I_TVE_LEVEL_BLACK(tv_mode->video_levels->black));
regmap_write(tv->regs, SUN4I_TVE_DAC1_REG,
SUN4I_TVE_DAC1_AMPLITUDE(0, 0x18) |
SUN4I_TVE_DAC1_AMPLITUDE(1, 0x18) |
SUN4I_TVE_DAC1_AMPLITUDE(2, 0x18) |
SUN4I_TVE_DAC1_AMPLITUDE(3, 0x18));
regmap_write(tv->regs, SUN4I_TVE_CB_CR_LVL_REG,
SUN4I_TVE_CB_CR_LVL_CB_BURST(tv_mode->burst_levels->cb) |
SUN4I_TVE_CB_CR_LVL_CR_BURST(tv_mode->burst_levels->cr));
regmap_write(tv->regs, SUN4I_TVE_BURST_WIDTH_REG,
SUN4I_TVE_BURST_WIDTH_HSYNC_WIDTH(126) |
SUN4I_TVE_BURST_WIDTH_BURST_WIDTH(68) |
SUN4I_TVE_BURST_WIDTH_BREEZEWAY(22));
regmap_write(tv->regs, SUN4I_TVE_CB_CR_GAIN_REG,
SUN4I_TVE_CB_CR_GAIN_CB(tv_mode->color_gains->cb) |
SUN4I_TVE_CB_CR_GAIN_CR(tv_mode->color_gains->cr));
regmap_write(tv->regs, SUN4I_TVE_SYNC_VBI_REG,
SUN4I_TVE_SYNC_VBI_SYNC(0x10) |
SUN4I_TVE_SYNC_VBI_VBLANK(tv_mode->vblank_level));
regmap_write(tv->regs, SUN4I_TVE_ACTIVE_LINE_REG,
SUN4I_TVE_ACTIVE_LINE(1440));
regmap_write(tv->regs, SUN4I_TVE_CHROMA_REG,
SUN4I_TVE_CHROMA_COMP_GAIN_50);
regmap_write(tv->regs, SUN4I_TVE_12C_REG,
SUN4I_TVE_12C_COMP_YUV_EN |
SUN4I_TVE_12C_NOTCH_WIDTH_WIDE);
regmap_write(tv->regs, SUN4I_TVE_RESYNC_REG,
SUN4I_TVE_RESYNC_PIXEL(tv_mode->resync_params->pixel) |
SUN4I_TVE_RESYNC_LINE(tv_mode->resync_params->line) |
(tv_mode->resync_params->field ?
SUN4I_TVE_RESYNC_FIELD : 0));
regmap_write(tv->regs, SUN4I_TVE_SLAVE_REG, 0);
}
static void sun4i_tv_destroy(struct drm_encoder *encoder)
{
drm_encoder_cleanup(encoder);
}
static int sun4i_tv_comp_get_modes(struct drm_connector *connector)
{
int i;
for (i = 0; i < ARRAY_SIZE(tv_modes); i++) {
struct drm_display_mode *mode;
const struct tv_mode *tv_mode = &tv_modes[i];
mode = drm_mode_create(connector->dev);
if (!mode) {
DRM_ERROR("Failed to create a new display mode\n");
return 0;
}
strcpy(mode->name, tv_mode->name);
sun4i_tv_mode_to_drm_mode(tv_mode, mode);
drm_mode_probed_add(connector, mode);
}
return i;
}
static int sun4i_tv_comp_mode_valid(struct drm_connector *connector,
struct drm_display_mode *mode)
{
return MODE_OK;
}
static void
sun4i_tv_comp_connector_destroy(struct drm_connector *connector)
{
drm_connector_cleanup(connector);
}
static int sun4i_tv_bind(struct device *dev, struct device *master,
void *data)
{
struct platform_device *pdev = to_platform_device(dev);
struct drm_device *drm = data;
struct sun4i_drv *drv = drm->dev_private;
struct sun4i_tv *tv;
struct resource *res;
void __iomem *regs;
int ret;
tv = devm_kzalloc(dev, sizeof(*tv), GFP_KERNEL);
if (!tv)
return -ENOMEM;
tv->drv = drv;
dev_set_drvdata(dev, tv);
res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
regs = devm_ioremap_resource(dev, res);
if (IS_ERR(regs)) {
dev_err(dev, "Couldn't map the TV encoder registers\n");
return PTR_ERR(regs);
}
tv->regs = devm_regmap_init_mmio(dev, regs,
&sun4i_tv_regmap_config);
if (IS_ERR(tv->regs)) {
dev_err(dev, "Couldn't create the TV encoder regmap\n");
return PTR_ERR(tv->regs);
}
tv->reset = devm_reset_control_get(dev, NULL);
if (IS_ERR(tv->reset)) {
dev_err(dev, "Couldn't get our reset line\n");
return PTR_ERR(tv->reset);
}
ret = reset_control_deassert(tv->reset);
if (ret) {
dev_err(dev, "Couldn't deassert our reset line\n");
return ret;
}
tv->clk = devm_clk_get(dev, NULL);
if (IS_ERR(tv->clk)) {
dev_err(dev, "Couldn't get the TV encoder clock\n");
ret = PTR_ERR(tv->clk);
goto err_assert_reset;
}
clk_prepare_enable(tv->clk);
drm_encoder_helper_add(&tv->encoder,
&sun4i_tv_helper_funcs);
ret = drm_encoder_init(drm,
&tv->encoder,
&sun4i_tv_funcs,
DRM_MODE_ENCODER_TVDAC,
NULL);
if (ret) {
dev_err(dev, "Couldn't initialise the TV encoder\n");
goto err_disable_clk;
}
tv->encoder.possible_crtcs = drm_of_find_possible_crtcs(drm,
dev->of_node);
if (!tv->encoder.possible_crtcs) {
ret = -EPROBE_DEFER;
goto err_disable_clk;
}
drm_connector_helper_add(&tv->connector,
&sun4i_tv_comp_connector_helper_funcs);
ret = drm_connector_init(drm, &tv->connector,
&sun4i_tv_comp_connector_funcs,
DRM_MODE_CONNECTOR_Composite);
if (ret) {
dev_err(dev,
"Couldn't initialise the Composite connector\n");
goto err_cleanup_connector;
}
tv->connector.interlace_allowed = true;
drm_mode_connector_attach_encoder(&tv->connector, &tv->encoder);
return 0;
err_cleanup_connector:
drm_encoder_cleanup(&tv->encoder);
err_disable_clk:
clk_disable_unprepare(tv->clk);
err_assert_reset:
reset_control_assert(tv->reset);
return ret;
}
static void sun4i_tv_unbind(struct device *dev, struct device *master,
void *data)
{
struct sun4i_tv *tv = dev_get_drvdata(dev);
drm_connector_cleanup(&tv->connector);
drm_encoder_cleanup(&tv->encoder);
clk_disable_unprepare(tv->clk);
}
static int sun4i_tv_probe(struct platform_device *pdev)
{
return component_add(&pdev->dev, &sun4i_tv_ops);
}
static int sun4i_tv_remove(struct platform_device *pdev)
{
component_del(&pdev->dev, &sun4i_tv_ops);
return 0;
}
