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
static void tvout_preformatter_set_matrix(struct sti_tvout *tvout,
struct drm_display_mode *mode)
{
unsigned int i;
const u32 *pf_matrix;
if (mode->vdisplay >= TVO_MIN_HD_HEIGHT)
pf_matrix = rgb_to_ycbcr_709;
else
pf_matrix = rgb_to_ycbcr_601;
for (i = 0; i < 8; i++) {
tvout_write(tvout, *(pf_matrix + i),
TVO_CSC_MAIN_M0 + (i * 4));
tvout_write(tvout, *(pf_matrix + i),
TVO_CSC_AUX_M0 + (i * 4));
}
}
static void tvout_dvo_start(struct sti_tvout *tvout, bool main_path)
{
u32 tvo_in_vid_format;
int val, tmp;
dev_dbg(tvout->dev, "%s\n", __func__);
if (main_path) {
DRM_DEBUG_DRIVER("main vip for DVO\n");
tmp = TVO_SYNC_MAIN_VTG_SET_REF | VTG_SYNC_ID_DVO;
val = tmp << TVO_SYNC_DVO_PAD_VSYNC_SHIFT;
val |= tmp << TVO_SYNC_DVO_PAD_HSYNC_SHIFT;
val |= tmp;
tvout_write(tvout, val, TVO_DVO_SYNC_SEL);
tvo_in_vid_format = TVO_MAIN_IN_VID_FORMAT;
} else {
DRM_DEBUG_DRIVER("aux vip for DVO\n");
tmp = TVO_SYNC_AUX_VTG_SET_REF | VTG_SYNC_ID_DVO;
val = tmp << TVO_SYNC_DVO_PAD_VSYNC_SHIFT;
val |= tmp << TVO_SYNC_DVO_PAD_HSYNC_SHIFT;
val |= tmp;
tvout_write(tvout, val, TVO_DVO_SYNC_SEL);
tvo_in_vid_format = TVO_AUX_IN_VID_FORMAT;
}
tvout_vip_set_color_order(tvout, TVO_VIP_DVO,
TVO_VIP_REORDER_CR_R_SEL,
TVO_VIP_REORDER_Y_G_SEL,
TVO_VIP_REORDER_CB_B_SEL);
tvout_vip_set_clip_mode(tvout, TVO_VIP_DVO, TVO_VIP_CLIP_DISABLED);
tvout_vip_set_rnd(tvout, TVO_VIP_DVO, TVO_VIP_RND_8BIT_ROUNDED);
tvout_vip_set_in_vid_fmt(tvout, tvo_in_vid_format, TVO_IN_FMT_SIGNED);
tvout_vip_set_sel_input(tvout, TVO_VIP_DVO, main_path,
STI_TVOUT_VIDEO_OUT_RGB);
}
static void tvout_hdmi_start(struct sti_tvout *tvout, bool main_path)
{
u32 tvo_in_vid_format;
dev_dbg(tvout->dev, "%s\n", __func__);
if (main_path) {
DRM_DEBUG_DRIVER("main vip for hdmi\n");
tvout_write(tvout,
TVO_SYNC_MAIN_VTG_SET_REF | VTG_SYNC_ID_HDMI,
TVO_HDMI_SYNC_SEL);
tvo_in_vid_format = TVO_MAIN_IN_VID_FORMAT;
} else {
DRM_DEBUG_DRIVER("aux vip for hdmi\n");
tvout_write(tvout,
TVO_SYNC_AUX_VTG_SET_REF | VTG_SYNC_ID_HDMI,
TVO_HDMI_SYNC_SEL);
tvo_in_vid_format = TVO_AUX_IN_VID_FORMAT;
}
tvout_vip_set_color_order(tvout, TVO_VIP_HDMI,
TVO_VIP_REORDER_CR_R_SEL,
TVO_VIP_REORDER_Y_G_SEL,
TVO_VIP_REORDER_CB_B_SEL);
tvout_vip_set_clip_mode(tvout, TVO_VIP_HDMI, TVO_VIP_CLIP_DISABLED);
tvout_vip_set_rnd(tvout, TVO_VIP_HDMI, TVO_VIP_RND_8BIT_ROUNDED);
tvout_vip_set_in_vid_fmt(tvout, tvo_in_vid_format, TVO_IN_FMT_SIGNED);
tvout_vip_set_sel_input(tvout, TVO_VIP_HDMI, main_path,
STI_TVOUT_VIDEO_OUT_RGB);
}
static void tvout_hda_start(struct sti_tvout *tvout, bool main_path)
{
u32 tvo_in_vid_format;
int val;
dev_dbg(tvout->dev, "%s\n", __func__);
if (main_path) {
DRM_DEBUG_DRIVER("main vip for HDF\n");
val = TVO_SYNC_MAIN_VTG_SET_REF | VTG_SYNC_ID_HDDCS;
val = val << TVO_SYNC_HD_DCS_SHIFT;
val |= TVO_SYNC_MAIN_VTG_SET_REF | VTG_SYNC_ID_HDF;
tvout_write(tvout, val, TVO_HD_SYNC_SEL);
tvo_in_vid_format = TVO_MAIN_IN_VID_FORMAT;
} else {
DRM_DEBUG_DRIVER("aux vip for HDF\n");
val = TVO_SYNC_AUX_VTG_SET_REF | VTG_SYNC_ID_HDDCS;
val = val << TVO_SYNC_HD_DCS_SHIFT;
val |= TVO_SYNC_AUX_VTG_SET_REF | VTG_SYNC_ID_HDF;
tvout_write(tvout, val, TVO_HD_SYNC_SEL);
tvo_in_vid_format = TVO_AUX_IN_VID_FORMAT;
}
tvout_vip_set_color_order(tvout, TVO_VIP_HDF,
TVO_VIP_REORDER_CR_R_SEL,
TVO_VIP_REORDER_Y_G_SEL,
TVO_VIP_REORDER_CB_B_SEL);
tvout_vip_set_clip_mode(tvout, TVO_VIP_HDF, TVO_VIP_CLIP_DISABLED);
tvout_vip_set_rnd(tvout, TVO_VIP_HDF, TVO_VIP_RND_10BIT_ROUNDED);
tvout_vip_set_in_vid_fmt(tvout, tvo_in_vid_format, TVO_IN_FMT_SIGNED);
tvout_vip_set_sel_input(tvout, TVO_VIP_HDF, main_path,
STI_TVOUT_VIDEO_OUT_YUV);
tvout_write(tvout, 0, TVO_HD_DAC_CFG_OFF);
}
static void tvout_dbg_vip(struct seq_file *s, int val)
{
int r, g, b, tmp, mask;
char *const reorder[] = {"Y_G", "Cb_B", "Cr_R"};
char *const clipping[] = {"No", "EAV/SAV", "Limited range RGB/Y",
"Limited range Cb/Cr", "decided by register"};
char *const round[] = {"8-bit", "10-bit", "12-bit"};
char *const input_sel[] = {"Main (color matrix enabled)",
"Main (color matrix by-passed)",
"", "", "", "", "", "",
"Aux (color matrix enabled)",
"Aux (color matrix by-passed)",
"", "", "", "", "", "Force value"};
seq_puts(s, "\t");
mask = TVO_VIP_REORDER_MASK << TVO_VIP_REORDER_R_SHIFT;
r = (val & mask) >> TVO_VIP_REORDER_R_SHIFT;
mask = TVO_VIP_REORDER_MASK << TVO_VIP_REORDER_G_SHIFT;
g = (val & mask) >> TVO_VIP_REORDER_G_SHIFT;
mask = TVO_VIP_REORDER_MASK << TVO_VIP_REORDER_B_SHIFT;
b = (val & mask) >> TVO_VIP_REORDER_B_SHIFT;
seq_printf(s, "%-24s %s->%s %s->%s %s->%s\n", "Reorder:",
reorder[r], reorder[TVO_VIP_REORDER_CR_R_SEL],
reorder[g], reorder[TVO_VIP_REORDER_Y_G_SEL],
reorder[b], reorder[TVO_VIP_REORDER_CB_B_SEL]);
seq_puts(s, "\t\t\t\t\t");
mask = TVO_VIP_CLIP_MASK << TVO_VIP_CLIP_SHIFT;
tmp = (val & mask) >> TVO_VIP_CLIP_SHIFT;
seq_printf(s, "%-24s %s\n", "Clipping:", clipping[tmp]);
seq_puts(s, "\t\t\t\t\t");
mask = TVO_VIP_RND_MASK << TVO_VIP_RND_SHIFT;
tmp = (val & mask) >> TVO_VIP_RND_SHIFT;
seq_printf(s, "%-24s input data rounded to %s per component\n",
"Round:", round[tmp]);
seq_puts(s, "\t\t\t\t\t");
tmp = (val & TVO_VIP_SEL_INPUT_MASK);
seq_printf(s, "%-24s %s", "Input selection:", input_sel[tmp]);
}
static void tvout_dbg_hd_dac_cfg(struct seq_file *s, int val)
{
seq_printf(s, "\t%-24s %s", "HD DAC:",
val & 1 ? "disabled" : "enabled");
}
static int tvout_dbg_show(struct seq_file *s, void *data)
{
struct drm_info_node *node = s->private;
struct sti_tvout *tvout = (struct sti_tvout *)node->info_ent->data;
struct drm_crtc *crtc;
seq_printf(s, "TVOUT: (vaddr = 0x%p)", tvout->regs);
seq_puts(s, "\n\n HDMI encoder: ");
crtc = tvout->hdmi->crtc;
if (crtc) {
seq_printf(s, "connected to %s path",
sti_crtc_is_main(crtc) ? "main" : "aux");
DBGFS_DUMP(TVO_HDMI_SYNC_SEL);
DBGFS_DUMP(TVO_VIP_HDMI);
tvout_dbg_vip(s, readl(tvout->regs + TVO_VIP_HDMI));
} else {
seq_puts(s, "disabled");
}
seq_puts(s, "\n\n DVO encoder: ");
crtc = tvout->dvo->crtc;
if (crtc) {
seq_printf(s, "connected to %s path",
sti_crtc_is_main(crtc) ? "main" : "aux");
DBGFS_DUMP(TVO_DVO_SYNC_SEL);
DBGFS_DUMP(TVO_DVO_CONFIG);
DBGFS_DUMP(TVO_VIP_DVO);
tvout_dbg_vip(s, readl(tvout->regs + TVO_VIP_DVO));
} else {
seq_puts(s, "disabled");
}
seq_puts(s, "\n\n HDA encoder: ");
crtc = tvout->hda->crtc;
if (crtc) {
seq_printf(s, "connected to %s path",
sti_crtc_is_main(crtc) ? "main" : "aux");
DBGFS_DUMP(TVO_HD_SYNC_SEL);
DBGFS_DUMP(TVO_HD_DAC_CFG_OFF);
tvout_dbg_hd_dac_cfg(s,
readl(tvout->regs + TVO_HD_DAC_CFG_OFF));
DBGFS_DUMP(TVO_VIP_HDF);
tvout_dbg_vip(s, readl(tvout->regs + TVO_VIP_HDF));
} else {
seq_puts(s, "disabled");
}
seq_puts(s, "\n\n main path configuration");
DBGFS_DUMP(TVO_CSC_MAIN_M0);
DBGFS_DUMP(TVO_CSC_MAIN_M1);
DBGFS_DUMP(TVO_CSC_MAIN_M2);
DBGFS_DUMP(TVO_CSC_MAIN_M3);
DBGFS_DUMP(TVO_CSC_MAIN_M4);
DBGFS_DUMP(TVO_CSC_MAIN_M5);
DBGFS_DUMP(TVO_CSC_MAIN_M6);
DBGFS_DUMP(TVO_CSC_MAIN_M7);
DBGFS_DUMP(TVO_MAIN_IN_VID_FORMAT);
seq_puts(s, "\n\n auxiliary path configuration");
DBGFS_DUMP(TVO_CSC_AUX_M0);
DBGFS_DUMP(TVO_CSC_AUX_M2);
DBGFS_DUMP(TVO_CSC_AUX_M3);
DBGFS_DUMP(TVO_CSC_AUX_M4);
DBGFS_DUMP(TVO_CSC_AUX_M5);
DBGFS_DUMP(TVO_CSC_AUX_M6);
DBGFS_DUMP(TVO_CSC_AUX_M7);
DBGFS_DUMP(TVO_AUX_IN_VID_FORMAT);
seq_puts(s, "\n");
return 0;
}
static void tvout_debugfs_exit(struct sti_tvout *tvout, struct drm_minor *minor)
{
drm_debugfs_remove_files(tvout_debugfs_files,
ARRAY_SIZE(tvout_debugfs_files),
minor);
}
static int tvout_debugfs_init(struct sti_tvout *tvout, struct drm_minor *minor)
{
unsigned int i;
for (i = 0; i < ARRAY_SIZE(tvout_debugfs_files); i++)
tvout_debugfs_files[i].data = tvout;
return drm_debugfs_create_files(tvout_debugfs_files,
ARRAY_SIZE(tvout_debugfs_files),
minor->debugfs_root, minor);
}
static void sti_tvout_encoder_dpms(struct drm_encoder *encoder, int mode)
{
}
static void sti_tvout_encoder_mode_set(struct drm_encoder *encoder,
struct drm_display_mode *mode,
struct drm_display_mode *adjusted_mode)
{
}
static void sti_tvout_encoder_destroy(struct drm_encoder *encoder)
{
struct sti_tvout_encoder *sti_encoder = to_sti_tvout_encoder(encoder);
drm_encoder_cleanup(encoder);
kfree(sti_encoder);
}
static int sti_tvout_late_register(struct drm_encoder *encoder)
{
struct sti_tvout *tvout = to_sti_tvout(encoder);
int ret;
if (tvout->debugfs_registered)
return 0;
ret = tvout_debugfs_init(tvout, encoder->dev->primary);
if (ret)
return ret;
tvout->debugfs_registered = true;
return 0;
}
static void sti_tvout_early_unregister(struct drm_encoder *encoder)
{
struct sti_tvout *tvout = to_sti_tvout(encoder);
if (!tvout->debugfs_registered)
return;
tvout_debugfs_exit(tvout, encoder->dev->primary);
tvout->debugfs_registered = false;
}
static void sti_dvo_encoder_enable(struct drm_encoder *encoder)
{
struct sti_tvout *tvout = to_sti_tvout(encoder);
tvout_preformatter_set_matrix(tvout, &encoder->crtc->mode);
tvout_dvo_start(tvout, sti_crtc_is_main(encoder->crtc));
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
&sti_tvout_encoder_funcs, DRM_MODE_ENCODER_LVDS,
NULL);
drm_encoder_helper_add(drm_encoder, &sti_dvo_encoder_helper_funcs);
return drm_encoder;
}
static void sti_hda_encoder_enable(struct drm_encoder *encoder)
{
struct sti_tvout *tvout = to_sti_tvout(encoder);
tvout_preformatter_set_matrix(tvout, &encoder->crtc->mode);
tvout_hda_start(tvout, sti_crtc_is_main(encoder->crtc));
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
&sti_tvout_encoder_funcs, DRM_MODE_ENCODER_DAC, NULL);
drm_encoder_helper_add(drm_encoder, &sti_hda_encoder_helper_funcs);
return drm_encoder;
}
static void sti_hdmi_encoder_enable(struct drm_encoder *encoder)
{
struct sti_tvout *tvout = to_sti_tvout(encoder);
tvout_preformatter_set_matrix(tvout, &encoder->crtc->mode);
tvout_hdmi_start(tvout, sti_crtc_is_main(encoder->crtc));
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
&sti_tvout_encoder_funcs, DRM_MODE_ENCODER_TMDS, NULL);
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
if (tvout->dvo)
drm_encoder_cleanup(tvout->dvo);
tvout->dvo = NULL;
}
static int sti_tvout_bind(struct device *dev, struct device *master, void *data)
{
struct sti_tvout *tvout = dev_get_drvdata(dev);
struct drm_device *drm_dev = data;
tvout->drm_dev = drm_dev;
sti_tvout_create_encoders(drm_dev, tvout);
return 0;
}
static void sti_tvout_unbind(struct device *dev, struct device *master,
void *data)
{
struct sti_tvout *tvout = dev_get_drvdata(dev);
sti_tvout_destroy_encoders(tvout);
}
static int sti_tvout_probe(struct platform_device *pdev)
{
struct device *dev = &pdev->dev;
struct device_node *node = dev->of_node;
struct sti_tvout *tvout;
struct resource *res;
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
return component_add(dev, &sti_tvout_ops);
}
static int sti_tvout_remove(struct platform_device *pdev)
{
component_del(&pdev->dev, &sti_tvout_ops);
return 0;
}
