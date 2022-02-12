static u32 tvout_read(struct sti_tvout *tvout, int offset)
{
return readl(tvout->regs + offset);
}
static void tvout_write(struct sti_tvout *tvout, u32 val, int offset)
{
writel(val, tvout->regs + offset);
}
static void tvout_vip_set_color_order(struct sti_tvout *tvout, int reg,
u32 cr_r, u32 y_g, u32 cb_b)
{
u32 val = tvout_read(tvout, reg);
val &= ~(TVO_VIP_REORDER_MASK << TVO_VIP_REORDER_R_SHIFT);
val &= ~(TVO_VIP_REORDER_MASK << TVO_VIP_REORDER_G_SHIFT);
val &= ~(TVO_VIP_REORDER_MASK << TVO_VIP_REORDER_B_SHIFT);
val |= cr_r << TVO_VIP_REORDER_R_SHIFT;
val |= y_g << TVO_VIP_REORDER_G_SHIFT;
val |= cb_b << TVO_VIP_REORDER_B_SHIFT;
tvout_write(tvout, val, reg);
}
static void tvout_vip_set_clip_mode(struct sti_tvout *tvout, int reg, u32 range)
{
u32 val = tvout_read(tvout, reg);
val &= ~(TVO_VIP_CLIP_MASK << TVO_VIP_CLIP_SHIFT);
val |= range << TVO_VIP_CLIP_SHIFT;
tvout_write(tvout, val, reg);
}
static void tvout_vip_set_rnd(struct sti_tvout *tvout, int reg, u32 rnd)
{
u32 val = tvout_read(tvout, reg);
val &= ~(TVO_VIP_RND_MASK << TVO_VIP_RND_SHIFT);
val |= rnd << TVO_VIP_RND_SHIFT;
tvout_write(tvout, val, reg);
}
static void tvout_vip_set_sel_input(struct sti_tvout *tvout,
int reg,
bool main_path,
bool sel_input_logic_inverted,
enum sti_tvout_video_out_type video_out)
{
u32 sel_input;
u32 val = tvout_read(tvout, reg);
if (main_path)
sel_input = TVO_VIP_SEL_INPUT_MAIN;
else
sel_input = TVO_VIP_SEL_INPUT_AUX;
switch (video_out) {
case STI_TVOUT_VIDEO_OUT_RGB:
sel_input |= TVO_VIP_SEL_INPUT_BYPASSED;
break;
case STI_TVOUT_VIDEO_OUT_YUV:
sel_input &= ~TVO_VIP_SEL_INPUT_BYPASSED;
break;
}
if (sel_input_logic_inverted)
sel_input = sel_input ^ TVO_VIP_SEL_INPUT_BYPASS_MASK;
val &= ~TVO_VIP_SEL_INPUT_MASK;
val |= sel_input;
tvout_write(tvout, val, reg);
}
static void tvout_vip_set_in_vid_fmt(struct sti_tvout *tvout,
int reg, u32 in_vid_fmt)
{
u32 val = tvout_read(tvout, reg);
val &= ~TVO_IN_FMT_SIGNED;
val |= in_vid_fmt;
tvout_write(tvout, val, reg);
}
static void tvout_dvo_start(struct sti_tvout *tvout, bool main_path)
{
struct device_node *node = tvout->dev->of_node;
bool sel_input_logic_inverted = false;
u32 tvo_in_vid_format;
int val;
dev_dbg(tvout->dev, "%s\n", __func__);
if (main_path) {
DRM_DEBUG_DRIVER("main vip for DVO\n");
val = TVO_SYNC_MAIN_VTG_SET_4 << TVO_SYNC_DVO_PAD_VSYNC_SHIFT;
val |= TVO_SYNC_MAIN_VTG_SET_4 << TVO_SYNC_DVO_PAD_HSYNC_SHIFT;
val |= TVO_SYNC_MAIN_VTG_SET_4;
tvout_write(tvout, val, TVO_DVO_SYNC_SEL);
tvo_in_vid_format = TVO_MAIN_IN_VID_FORMAT;
} else {
DRM_DEBUG_DRIVER("aux vip for DVO\n");
val = TVO_SYNC_AUX_VTG_SET_4 << TVO_SYNC_DVO_PAD_VSYNC_SHIFT;
val |= TVO_SYNC_AUX_VTG_SET_4 << TVO_SYNC_DVO_PAD_HSYNC_SHIFT;
val |= TVO_SYNC_AUX_VTG_SET_4;
tvout_write(tvout, val, TVO_DVO_SYNC_SEL);
tvo_in_vid_format = TVO_AUX_IN_VID_FORMAT;
}
tvout_vip_set_color_order(tvout, TVO_VIP_DVO,
TVO_VIP_REORDER_CR_R_SEL,
TVO_VIP_REORDER_Y_G_SEL,
TVO_VIP_REORDER_CB_B_SEL);
tvout_vip_set_clip_mode(tvout, TVO_VIP_DVO,
TVO_VIP_CLIP_LIMITED_RANGE_RGB_Y);
tvout_vip_set_rnd(tvout, TVO_VIP_DVO, TVO_VIP_RND_8BIT_ROUNDED);
if (of_device_is_compatible(node, "st,stih407-tvout")) {
tvout_vip_set_in_vid_fmt(tvout, tvo_in_vid_format,
TVO_IN_FMT_SIGNED);
sel_input_logic_inverted = true;
}
tvout_vip_set_sel_input(tvout, TVO_VIP_DVO, main_path,
sel_input_logic_inverted,
STI_TVOUT_VIDEO_OUT_RGB);
}
static void tvout_hdmi_start(struct sti_tvout *tvout, bool main_path)
{
struct device_node *node = tvout->dev->of_node;
bool sel_input_logic_inverted = false;
u32 tvo_in_vid_format;
dev_dbg(tvout->dev, "%s\n", __func__);
if (main_path) {
DRM_DEBUG_DRIVER("main vip for hdmi\n");
tvout_write(tvout, TVO_SYNC_MAIN_VTG_SET_1, TVO_HDMI_SYNC_SEL);
tvo_in_vid_format = TVO_MAIN_IN_VID_FORMAT;
} else {
DRM_DEBUG_DRIVER("aux vip for hdmi\n");
tvout_write(tvout, TVO_SYNC_AUX_VTG_SET_1, TVO_HDMI_SYNC_SEL);
tvo_in_vid_format = TVO_AUX_IN_VID_FORMAT;
}
tvout_vip_set_color_order(tvout, TVO_VIP_HDMI,
TVO_VIP_REORDER_CR_R_SEL,
TVO_VIP_REORDER_Y_G_SEL,
TVO_VIP_REORDER_CB_B_SEL);
tvout_vip_set_clip_mode(tvout, TVO_VIP_HDMI,
TVO_VIP_CLIP_LIMITED_RANGE_RGB_Y);
tvout_vip_set_rnd(tvout, TVO_VIP_HDMI, TVO_VIP_RND_8BIT_ROUNDED);
if (of_device_is_compatible(node, "st,stih407-tvout")) {
tvout_vip_set_in_vid_fmt(tvout, tvo_in_vid_format,
TVO_IN_FMT_SIGNED);
sel_input_logic_inverted = true;
}
tvout_vip_set_sel_input(tvout, TVO_VIP_HDMI, main_path,
sel_input_logic_inverted, STI_TVOUT_VIDEO_OUT_RGB);
}
static void tvout_hda_start(struct sti_tvout *tvout, bool main_path)
{
struct device_node *node = tvout->dev->of_node;
bool sel_input_logic_inverted = false;
u32 tvo_in_vid_format;
int val;
dev_dbg(tvout->dev, "%s\n", __func__);
if (main_path) {
val = TVO_SYNC_MAIN_VTG_SET_2 << TVO_SYNC_HD_DCS_SHIFT;
val |= TVO_SYNC_MAIN_VTG_SET_3;
tvout_write(tvout, val, TVO_HD_SYNC_SEL);
tvo_in_vid_format = TVO_MAIN_IN_VID_FORMAT;
} else {
val = TVO_SYNC_AUX_VTG_SET_2 << TVO_SYNC_HD_DCS_SHIFT;
val |= TVO_SYNC_AUX_VTG_SET_3;
tvout_write(tvout, val, TVO_HD_SYNC_SEL);
tvo_in_vid_format = TVO_AUX_IN_VID_FORMAT;
}
tvout_vip_set_color_order(tvout, TVO_VIP_HDF,
TVO_VIP_REORDER_CR_R_SEL,
TVO_VIP_REORDER_Y_G_SEL,
TVO_VIP_REORDER_CB_B_SEL);
tvout_vip_set_clip_mode(tvout, TVO_VIP_HDF, TVO_VIP_CLIP_EAV_SAV);
tvout_vip_set_rnd(tvout, TVO_VIP_HDF, TVO_VIP_RND_10BIT_ROUNDED);
if (of_device_is_compatible(node, "st,stih407-tvout")) {
tvout_vip_set_in_vid_fmt(tvout,
tvo_in_vid_format, TVO_IN_FMT_SIGNED);
sel_input_logic_inverted = true;
}
tvout_vip_set_sel_input(tvout, TVO_VIP_HDF, main_path,
sel_input_logic_inverted,
STI_TVOUT_VIDEO_OUT_YUV);
tvout_write(tvout, 0, TVO_HD_DAC_CFG_OFF);
}
static void sti_tvout_encoder_dpms(struct drm_encoder *encoder, int mode)
{
}
static bool sti_tvout_encoder_mode_fixup(struct drm_encoder *encoder,
const struct drm_display_mode *mode,
struct drm_display_mode *adjusted_mode)
{
return true;
}
static void sti_tvout_encoder_mode_set(struct drm_encoder *encoder,
struct drm_display_mode *mode,
struct drm_display_mode *adjusted_mode)
{
}
static void sti_tvout_encoder_prepare(struct drm_encoder *encoder)
{
}
static void sti_tvout_encoder_destroy(struct drm_encoder *encoder)
{
struct sti_tvout_encoder *sti_encoder = to_sti_tvout_encoder(encoder);
drm_encoder_cleanup(encoder);
kfree(sti_encoder);
}
static void sti_dvo_encoder_commit(struct drm_encoder *encoder)
{
struct sti_tvout *tvout = to_sti_tvout(encoder);
tvout_dvo_start(tvout, sti_drm_crtc_is_main(encoder->crtc));
}
static void sti_dvo_encoder_disable(struct drm_encoder *encoder)
{
struct sti_tvout *tvout = to_sti_tvout(encoder);
tvout_write(tvout, 0x0, TVO_VIP_DVO);
}
static struct drm_encoder *
sti_tvout_create_dvo_encoder(struct drm_device *dev,
struct sti_tvout *tvout)
{
struct sti_tvout_encoder *encoder;
struct drm_encoder *drm_encoder;
encoder = devm_kzalloc(tvout->dev, sizeof(*encoder), GFP_KERNEL);
if (!encoder)
return NULL;
encoder->tvout = tvout;
drm_encoder = (struct drm_encoder *)encoder;
drm_encoder->possible_crtcs = ENCODER_CRTC_MASK;
drm_encoder->possible_clones = 1 << 0;
drm_encoder_init(dev, drm_encoder,
&sti_tvout_encoder_funcs, DRM_MODE_ENCODER_LVDS);
drm_encoder_helper_add(drm_encoder, &sti_dvo_encoder_helper_funcs);
return drm_encoder;
}
static void sti_hda_encoder_commit(struct drm_encoder *encoder)
{
struct sti_tvout *tvout = to_sti_tvout(encoder);
tvout_hda_start(tvout, sti_drm_crtc_is_main(encoder->crtc));
}
static void sti_hda_encoder_disable(struct drm_encoder *encoder)
{
struct sti_tvout *tvout = to_sti_tvout(encoder);
tvout_write(tvout, 0x0, TVO_VIP_HDF);
tvout_write(tvout, 1, TVO_HD_DAC_CFG_OFF);
}
static struct drm_encoder *sti_tvout_create_hda_encoder(struct drm_device *dev,
struct sti_tvout *tvout)
{
struct sti_tvout_encoder *encoder;
struct drm_encoder *drm_encoder;
encoder = devm_kzalloc(tvout->dev, sizeof(*encoder), GFP_KERNEL);
if (!encoder)
return NULL;
encoder->tvout = tvout;
drm_encoder = (struct drm_encoder *) encoder;
drm_encoder->possible_crtcs = ENCODER_CRTC_MASK;
drm_encoder->possible_clones = 1 << 0;
drm_encoder_init(dev, drm_encoder,
&sti_tvout_encoder_funcs, DRM_MODE_ENCODER_DAC);
drm_encoder_helper_add(drm_encoder, &sti_hda_encoder_helper_funcs);
return drm_encoder;
}
static void sti_hdmi_encoder_commit(struct drm_encoder *encoder)
{
struct sti_tvout *tvout = to_sti_tvout(encoder);
tvout_hdmi_start(tvout, sti_drm_crtc_is_main(encoder->crtc));
}
static void sti_hdmi_encoder_disable(struct drm_encoder *encoder)
{
struct sti_tvout *tvout = to_sti_tvout(encoder);
tvout_write(tvout, 0x0, TVO_VIP_HDMI);
}
static struct drm_encoder *sti_tvout_create_hdmi_encoder(struct drm_device *dev,
struct sti_tvout *tvout)
{
struct sti_tvout_encoder *encoder;
struct drm_encoder *drm_encoder;
encoder = devm_kzalloc(tvout->dev, sizeof(*encoder), GFP_KERNEL);
if (!encoder)
return NULL;
encoder->tvout = tvout;
drm_encoder = (struct drm_encoder *) encoder;
drm_encoder->possible_crtcs = ENCODER_CRTC_MASK;
drm_encoder->possible_clones = 1 << 1;
drm_encoder_init(dev, drm_encoder,
&sti_tvout_encoder_funcs, DRM_MODE_ENCODER_TMDS);
drm_encoder_helper_add(drm_encoder, &sti_hdmi_encoder_helper_funcs);
return drm_encoder;
}
static void sti_tvout_create_encoders(struct drm_device *dev,
struct sti_tvout *tvout)
{
tvout->hdmi = sti_tvout_create_hdmi_encoder(dev, tvout);
tvout->hda = sti_tvout_create_hda_encoder(dev, tvout);
tvout->dvo = sti_tvout_create_dvo_encoder(dev, tvout);
}
static void sti_tvout_destroy_encoders(struct sti_tvout *tvout)
{
if (tvout->hdmi)
drm_encoder_cleanup(tvout->hdmi);
tvout->hdmi = NULL;
if (tvout->hda)
drm_encoder_cleanup(tvout->hda);
tvout->hda = NULL;
}
static int sti_tvout_bind(struct device *dev, struct device *master, void *data)
{
struct sti_tvout *tvout = dev_get_drvdata(dev);
struct drm_device *drm_dev = data;
unsigned int i;
int ret;
tvout->drm_dev = drm_dev;
for (i = 0; i < 8; i++) {
tvout_write(tvout, rgb_to_ycbcr_601[i],
TVO_CSC_MAIN_M0 + (i * 4));
tvout_write(tvout, rgb_to_ycbcr_601[i],
TVO_CSC_AUX_M0 + (i * 4));
}
sti_tvout_create_encoders(drm_dev, tvout);
ret = component_bind_all(dev, drm_dev);
if (ret)
sti_tvout_destroy_encoders(tvout);
return ret;
}
static void sti_tvout_unbind(struct device *dev, struct device *master,
void *data)
{
}
static int compare_of(struct device *dev, void *data)
{
return dev->of_node == data;
}
static int sti_tvout_master_bind(struct device *dev)
{
return 0;
}
static void sti_tvout_master_unbind(struct device *dev)
{
}
static int sti_tvout_probe(struct platform_device *pdev)
{
struct device *dev = &pdev->dev;
struct device_node *node = dev->of_node;
struct sti_tvout *tvout;
struct resource *res;
struct device_node *child_np;
struct component_match *match = NULL;
DRM_INFO("%s\n", __func__);
if (!node)
return -ENODEV;
tvout = devm_kzalloc(dev, sizeof(*tvout), GFP_KERNEL);
if (!tvout)
return -ENOMEM;
tvout->dev = dev;
res = platform_get_resource_byname(pdev, IORESOURCE_MEM, "tvout-reg");
if (!res) {
DRM_ERROR("Invalid glue resource\n");
return -ENOMEM;
}
tvout->regs = devm_ioremap_nocache(dev, res->start, resource_size(res));
if (!tvout->regs)
return -ENOMEM;
tvout->reset = devm_reset_control_get(dev, "tvout");
if (!IS_ERR(tvout->reset))
reset_control_deassert(tvout->reset);
platform_set_drvdata(pdev, tvout);
of_platform_populate(node, NULL, NULL, dev);
child_np = of_get_next_available_child(node, NULL);
while (child_np) {
component_match_add(dev, &match, compare_of, child_np);
of_node_put(child_np);
child_np = of_get_next_available_child(node, child_np);
}
component_master_add_with_match(dev, &sti_tvout_master_ops, match);
return component_add(dev, &sti_tvout_ops);
}
static int sti_tvout_remove(struct platform_device *pdev)
{
component_master_del(&pdev->dev, &sti_tvout_master_ops);
component_del(&pdev->dev, &sti_tvout_ops);
return 0;
}
