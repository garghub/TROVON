static struct intel_tv *enc_to_tv(struct intel_encoder *encoder)
{
return container_of(encoder, struct intel_tv, base);
}
static struct intel_tv *intel_attached_tv(struct drm_connector *connector)
{
return enc_to_tv(intel_attached_encoder(connector));
}
static bool
intel_tv_get_hw_state(struct intel_encoder *encoder, enum pipe *pipe)
{
struct drm_device *dev = encoder->base.dev;
struct drm_i915_private *dev_priv = dev->dev_private;
u32 tmp = I915_READ(TV_CTL);
if (!(tmp & TV_ENC_ENABLE))
return false;
*pipe = PORT_TO_PIPE(tmp);
return true;
}
static void
intel_enable_tv(struct intel_encoder *encoder)
{
struct drm_device *dev = encoder->base.dev;
struct drm_i915_private *dev_priv = dev->dev_private;
I915_WRITE(TV_CTL, I915_READ(TV_CTL) | TV_ENC_ENABLE);
}
static void
intel_disable_tv(struct intel_encoder *encoder)
{
struct drm_device *dev = encoder->base.dev;
struct drm_i915_private *dev_priv = dev->dev_private;
I915_WRITE(TV_CTL, I915_READ(TV_CTL) & ~TV_ENC_ENABLE);
}
static const struct tv_mode *
intel_tv_mode_lookup(const char *tv_format)
{
int i;
for (i = 0; i < ARRAY_SIZE(tv_modes); i++) {
const struct tv_mode *tv_mode = &tv_modes[i];
if (!strcmp(tv_format, tv_mode->name))
return tv_mode;
}
return NULL;
}
static const struct tv_mode *
intel_tv_mode_find(struct intel_tv *intel_tv)
{
return intel_tv_mode_lookup(intel_tv->tv_format);
}
static enum drm_mode_status
intel_tv_mode_valid(struct drm_connector *connector,
struct drm_display_mode *mode)
{
struct intel_tv *intel_tv = intel_attached_tv(connector);
const struct tv_mode *tv_mode = intel_tv_mode_find(intel_tv);
if (tv_mode && abs(tv_mode->refresh - drm_mode_vrefresh(mode) * 1000)
< 1000)
return MODE_OK;
return MODE_CLOCK_RANGE;
}
static bool
intel_tv_compute_config(struct intel_encoder *encoder,
struct intel_crtc_config *pipe_config)
{
struct intel_tv *intel_tv = enc_to_tv(encoder);
const struct tv_mode *tv_mode = intel_tv_mode_find(intel_tv);
if (!tv_mode)
return false;
pipe_config->adjusted_mode.clock = tv_mode->clock;
DRM_DEBUG_KMS("forcing bpc to 8 for TV\n");
pipe_config->pipe_bpp = 8*3;
pipe_config->adjusted_mode.flags = 0;
return true;
}
static void intel_tv_mode_set(struct intel_encoder *encoder)
{
struct drm_device *dev = encoder->base.dev;
struct drm_i915_private *dev_priv = dev->dev_private;
struct intel_crtc *intel_crtc = to_intel_crtc(encoder->base.crtc);
struct intel_tv *intel_tv = enc_to_tv(encoder);
const struct tv_mode *tv_mode = intel_tv_mode_find(intel_tv);
u32 tv_ctl;
u32 hctl1, hctl2, hctl3;
u32 vctl1, vctl2, vctl3, vctl4, vctl5, vctl6, vctl7;
u32 scctl1, scctl2, scctl3;
int i, j;
const struct video_levels *video_levels;
const struct color_conversion *color_conversion;
bool burst_ena;
int pipe = intel_crtc->pipe;
if (!tv_mode)
return;
tv_ctl = I915_READ(TV_CTL);
tv_ctl &= TV_CTL_SAVE;
switch (intel_tv->type) {
default:
case DRM_MODE_CONNECTOR_Unknown:
case DRM_MODE_CONNECTOR_Composite:
tv_ctl |= TV_ENC_OUTPUT_COMPOSITE;
video_levels = tv_mode->composite_levels;
color_conversion = tv_mode->composite_color;
burst_ena = tv_mode->burst_ena;
break;
case DRM_MODE_CONNECTOR_Component:
tv_ctl |= TV_ENC_OUTPUT_COMPONENT;
video_levels = &component_levels;
if (tv_mode->burst_ena)
color_conversion = &sdtv_csc_yprpb;
else
color_conversion = &hdtv_csc_yprpb;
burst_ena = false;
break;
case DRM_MODE_CONNECTOR_SVIDEO:
tv_ctl |= TV_ENC_OUTPUT_SVIDEO;
video_levels = tv_mode->svideo_levels;
color_conversion = tv_mode->svideo_color;
burst_ena = tv_mode->burst_ena;
break;
}
hctl1 = (tv_mode->hsync_end << TV_HSYNC_END_SHIFT) |
(tv_mode->htotal << TV_HTOTAL_SHIFT);
hctl2 = (tv_mode->hburst_start << 16) |
(tv_mode->hburst_len << TV_HBURST_LEN_SHIFT);
if (burst_ena)
hctl2 |= TV_BURST_ENA;
hctl3 = (tv_mode->hblank_start << TV_HBLANK_START_SHIFT) |
(tv_mode->hblank_end << TV_HBLANK_END_SHIFT);
vctl1 = (tv_mode->nbr_end << TV_NBR_END_SHIFT) |
(tv_mode->vi_end_f1 << TV_VI_END_F1_SHIFT) |
(tv_mode->vi_end_f2 << TV_VI_END_F2_SHIFT);
vctl2 = (tv_mode->vsync_len << TV_VSYNC_LEN_SHIFT) |
(tv_mode->vsync_start_f1 << TV_VSYNC_START_F1_SHIFT) |
(tv_mode->vsync_start_f2 << TV_VSYNC_START_F2_SHIFT);
vctl3 = (tv_mode->veq_len << TV_VEQ_LEN_SHIFT) |
(tv_mode->veq_start_f1 << TV_VEQ_START_F1_SHIFT) |
(tv_mode->veq_start_f2 << TV_VEQ_START_F2_SHIFT);
if (tv_mode->veq_ena)
vctl3 |= TV_EQUAL_ENA;
vctl4 = (tv_mode->vburst_start_f1 << TV_VBURST_START_F1_SHIFT) |
(tv_mode->vburst_end_f1 << TV_VBURST_END_F1_SHIFT);
vctl5 = (tv_mode->vburst_start_f2 << TV_VBURST_START_F2_SHIFT) |
(tv_mode->vburst_end_f2 << TV_VBURST_END_F2_SHIFT);
vctl6 = (tv_mode->vburst_start_f3 << TV_VBURST_START_F3_SHIFT) |
(tv_mode->vburst_end_f3 << TV_VBURST_END_F3_SHIFT);
vctl7 = (tv_mode->vburst_start_f4 << TV_VBURST_START_F4_SHIFT) |
(tv_mode->vburst_end_f4 << TV_VBURST_END_F4_SHIFT);
if (intel_crtc->pipe == 1)
tv_ctl |= TV_ENC_PIPEB_SELECT;
tv_ctl |= tv_mode->oversample;
if (tv_mode->progressive)
tv_ctl |= TV_PROGRESSIVE;
if (tv_mode->trilevel_sync)
tv_ctl |= TV_TRILEVEL_SYNC;
if (tv_mode->pal_burst)
tv_ctl |= TV_PAL_BURST;
scctl1 = 0;
if (tv_mode->dda1_inc)
scctl1 |= TV_SC_DDA1_EN;
if (tv_mode->dda2_inc)
scctl1 |= TV_SC_DDA2_EN;
if (tv_mode->dda3_inc)
scctl1 |= TV_SC_DDA3_EN;
scctl1 |= tv_mode->sc_reset;
if (video_levels)
scctl1 |= video_levels->burst << TV_BURST_LEVEL_SHIFT;
scctl1 |= tv_mode->dda1_inc << TV_SCDDA1_INC_SHIFT;
scctl2 = tv_mode->dda2_size << TV_SCDDA2_SIZE_SHIFT |
tv_mode->dda2_inc << TV_SCDDA2_INC_SHIFT;
scctl3 = tv_mode->dda3_size << TV_SCDDA3_SIZE_SHIFT |
tv_mode->dda3_inc << TV_SCDDA3_INC_SHIFT;
if (dev->pci_device < 0x2772)
tv_ctl |= TV_ENC_C0_FIX | TV_ENC_SDP_FIX;
I915_WRITE(TV_H_CTL_1, hctl1);
I915_WRITE(TV_H_CTL_2, hctl2);
I915_WRITE(TV_H_CTL_3, hctl3);
I915_WRITE(TV_V_CTL_1, vctl1);
I915_WRITE(TV_V_CTL_2, vctl2);
I915_WRITE(TV_V_CTL_3, vctl3);
I915_WRITE(TV_V_CTL_4, vctl4);
I915_WRITE(TV_V_CTL_5, vctl5);
I915_WRITE(TV_V_CTL_6, vctl6);
I915_WRITE(TV_V_CTL_7, vctl7);
I915_WRITE(TV_SC_CTL_1, scctl1);
I915_WRITE(TV_SC_CTL_2, scctl2);
I915_WRITE(TV_SC_CTL_3, scctl3);
if (color_conversion) {
I915_WRITE(TV_CSC_Y, (color_conversion->ry << 16) |
color_conversion->gy);
I915_WRITE(TV_CSC_Y2, (color_conversion->by << 16) |
color_conversion->ay);
I915_WRITE(TV_CSC_U, (color_conversion->ru << 16) |
color_conversion->gu);
I915_WRITE(TV_CSC_U2, (color_conversion->bu << 16) |
color_conversion->au);
I915_WRITE(TV_CSC_V, (color_conversion->rv << 16) |
color_conversion->gv);
I915_WRITE(TV_CSC_V2, (color_conversion->bv << 16) |
color_conversion->av);
}
if (INTEL_INFO(dev)->gen >= 4)
I915_WRITE(TV_CLR_KNOBS, 0x00404000);
else
I915_WRITE(TV_CLR_KNOBS, 0x00606000);
if (video_levels)
I915_WRITE(TV_CLR_LEVEL,
((video_levels->black << TV_BLACK_LEVEL_SHIFT) |
(video_levels->blank << TV_BLANK_LEVEL_SHIFT)));
{
int pipeconf_reg = PIPECONF(pipe);
int dspcntr_reg = DSPCNTR(intel_crtc->plane);
int pipeconf = I915_READ(pipeconf_reg);
int dspcntr = I915_READ(dspcntr_reg);
int xpos = 0x0, ypos = 0x0;
unsigned int xsize, ysize;
I915_WRITE(dspcntr_reg, dspcntr & ~DISPLAY_PLANE_ENABLE);
intel_flush_display_plane(dev_priv, intel_crtc->plane);
if (IS_GEN2(dev))
intel_wait_for_vblank(dev, intel_crtc->pipe);
I915_WRITE(pipeconf_reg, pipeconf & ~PIPECONF_ENABLE);
intel_wait_for_pipe_off(dev, intel_crtc->pipe);
I915_WRITE(TV_FILTER_CTL_1, TV_AUTO_SCALE);
xsize = tv_mode->hblank_start - tv_mode->hblank_end;
if (tv_mode->progressive)
ysize = tv_mode->nbr_end + 1;
else
ysize = 2*tv_mode->nbr_end + 1;
xpos += intel_tv->margin[TV_MARGIN_LEFT];
ypos += intel_tv->margin[TV_MARGIN_TOP];
xsize -= (intel_tv->margin[TV_MARGIN_LEFT] +
intel_tv->margin[TV_MARGIN_RIGHT]);
ysize -= (intel_tv->margin[TV_MARGIN_TOP] +
intel_tv->margin[TV_MARGIN_BOTTOM]);
I915_WRITE(TV_WIN_POS, (xpos<<16)|ypos);
I915_WRITE(TV_WIN_SIZE, (xsize<<16)|ysize);
I915_WRITE(pipeconf_reg, pipeconf);
I915_WRITE(dspcntr_reg, dspcntr);
intel_flush_display_plane(dev_priv, intel_crtc->plane);
}
j = 0;
for (i = 0; i < 60; i++)
I915_WRITE(TV_H_LUMA_0 + (i<<2), tv_mode->filter_table[j++]);
for (i = 0; i < 60; i++)
I915_WRITE(TV_H_CHROMA_0 + (i<<2), tv_mode->filter_table[j++]);
for (i = 0; i < 43; i++)
I915_WRITE(TV_V_LUMA_0 + (i<<2), tv_mode->filter_table[j++]);
for (i = 0; i < 43; i++)
I915_WRITE(TV_V_CHROMA_0 + (i<<2), tv_mode->filter_table[j++]);
I915_WRITE(TV_DAC, I915_READ(TV_DAC) & TV_DAC_SAVE);
I915_WRITE(TV_CTL, tv_ctl);
}
static int
intel_tv_detect_type(struct intel_tv *intel_tv,
struct drm_connector *connector)
{
struct drm_encoder *encoder = &intel_tv->base.base;
struct drm_crtc *crtc = encoder->crtc;
struct intel_crtc *intel_crtc = to_intel_crtc(crtc);
struct drm_device *dev = encoder->dev;
struct drm_i915_private *dev_priv = dev->dev_private;
unsigned long irqflags;
u32 tv_ctl, save_tv_ctl;
u32 tv_dac, save_tv_dac;
int type;
if (connector->polled & DRM_CONNECTOR_POLL_HPD) {
spin_lock_irqsave(&dev_priv->irq_lock, irqflags);
i915_disable_pipestat(dev_priv, 0,
PIPE_HOTPLUG_INTERRUPT_ENABLE |
PIPE_HOTPLUG_TV_INTERRUPT_ENABLE);
spin_unlock_irqrestore(&dev_priv->irq_lock, irqflags);
}
save_tv_dac = tv_dac = I915_READ(TV_DAC);
save_tv_ctl = tv_ctl = I915_READ(TV_CTL);
tv_ctl &= ~(TV_ENC_ENABLE | TV_TEST_MODE_MASK);
tv_ctl |= TV_TEST_MODE_MONITOR_DETECT;
if (intel_crtc->pipe == 1)
tv_ctl |= TV_ENC_PIPEB_SELECT;
else
tv_ctl &= ~TV_ENC_PIPEB_SELECT;
tv_dac &= ~(TVDAC_SENSE_MASK | DAC_A_MASK | DAC_B_MASK | DAC_C_MASK);
tv_dac |= (TVDAC_STATE_CHG_EN |
TVDAC_A_SENSE_CTL |
TVDAC_B_SENSE_CTL |
TVDAC_C_SENSE_CTL |
DAC_CTL_OVERRIDE |
DAC_A_0_7_V |
DAC_B_0_7_V |
DAC_C_0_7_V);
if (IS_GM45(dev))
tv_dac &= ~(TVDAC_STATE_CHG_EN | TVDAC_A_SENSE_CTL |
TVDAC_B_SENSE_CTL | TVDAC_C_SENSE_CTL);
I915_WRITE(TV_CTL, tv_ctl);
I915_WRITE(TV_DAC, tv_dac);
POSTING_READ(TV_DAC);
intel_wait_for_vblank(intel_tv->base.base.dev,
to_intel_crtc(intel_tv->base.base.crtc)->pipe);
type = -1;
tv_dac = I915_READ(TV_DAC);
DRM_DEBUG_KMS("TV detected: %x, %x\n", tv_ctl, tv_dac);
if ((tv_dac & TVDAC_SENSE_MASK) == (TVDAC_B_SENSE | TVDAC_C_SENSE)) {
DRM_DEBUG_KMS("Detected Composite TV connection\n");
type = DRM_MODE_CONNECTOR_Composite;
} else if ((tv_dac & (TVDAC_A_SENSE|TVDAC_B_SENSE)) == TVDAC_A_SENSE) {
DRM_DEBUG_KMS("Detected S-Video TV connection\n");
type = DRM_MODE_CONNECTOR_SVIDEO;
} else if ((tv_dac & TVDAC_SENSE_MASK) == 0) {
DRM_DEBUG_KMS("Detected Component TV connection\n");
type = DRM_MODE_CONNECTOR_Component;
} else {
DRM_DEBUG_KMS("Unrecognised TV connection\n");
type = -1;
}
I915_WRITE(TV_DAC, save_tv_dac & ~TVDAC_STATE_CHG_EN);
I915_WRITE(TV_CTL, save_tv_ctl);
POSTING_READ(TV_CTL);
intel_wait_for_vblank(intel_tv->base.base.dev,
to_intel_crtc(intel_tv->base.base.crtc)->pipe);
if (connector->polled & DRM_CONNECTOR_POLL_HPD) {
spin_lock_irqsave(&dev_priv->irq_lock, irqflags);
i915_enable_pipestat(dev_priv, 0,
PIPE_HOTPLUG_INTERRUPT_ENABLE |
PIPE_HOTPLUG_TV_INTERRUPT_ENABLE);
spin_unlock_irqrestore(&dev_priv->irq_lock, irqflags);
}
return type;
}
static void intel_tv_find_better_format(struct drm_connector *connector)
{
struct intel_tv *intel_tv = intel_attached_tv(connector);
const struct tv_mode *tv_mode = intel_tv_mode_find(intel_tv);
int i;
if ((intel_tv->type == DRM_MODE_CONNECTOR_Component) ==
tv_mode->component_only)
return;
for (i = 0; i < sizeof(tv_modes) / sizeof(*tv_modes); i++) {
tv_mode = tv_modes + i;
if ((intel_tv->type == DRM_MODE_CONNECTOR_Component) ==
tv_mode->component_only)
break;
}
intel_tv->tv_format = tv_mode->name;
drm_object_property_set_value(&connector->base,
connector->dev->mode_config.tv_mode_property, i);
}
static enum drm_connector_status
intel_tv_detect(struct drm_connector *connector, bool force)
{
struct drm_display_mode mode;
struct intel_tv *intel_tv = intel_attached_tv(connector);
int type;
DRM_DEBUG_KMS("[CONNECTOR:%d:%s] force=%d\n",
connector->base.id, drm_get_connector_name(connector),
force);
mode = reported_modes[0];
if (force) {
struct intel_load_detect_pipe tmp;
if (intel_get_load_detect_pipe(connector, &mode, &tmp)) {
type = intel_tv_detect_type(intel_tv, connector);
intel_release_load_detect_pipe(connector, &tmp);
} else
return connector_status_unknown;
} else
return connector->status;
if (type < 0)
return connector_status_disconnected;
intel_tv->type = type;
intel_tv_find_better_format(connector);
return connector_status_connected;
}
static void
intel_tv_chose_preferred_modes(struct drm_connector *connector,
struct drm_display_mode *mode_ptr)
{
struct intel_tv *intel_tv = intel_attached_tv(connector);
const struct tv_mode *tv_mode = intel_tv_mode_find(intel_tv);
if (tv_mode->nbr_end < 480 && mode_ptr->vdisplay == 480)
mode_ptr->type |= DRM_MODE_TYPE_PREFERRED;
else if (tv_mode->nbr_end > 480) {
if (tv_mode->progressive == true && tv_mode->nbr_end < 720) {
if (mode_ptr->vdisplay == 720)
mode_ptr->type |= DRM_MODE_TYPE_PREFERRED;
} else if (mode_ptr->vdisplay == 1080)
mode_ptr->type |= DRM_MODE_TYPE_PREFERRED;
}
}
static int
intel_tv_get_modes(struct drm_connector *connector)
{
struct drm_display_mode *mode_ptr;
struct intel_tv *intel_tv = intel_attached_tv(connector);
const struct tv_mode *tv_mode = intel_tv_mode_find(intel_tv);
int j, count = 0;
u64 tmp;
for (j = 0; j < ARRAY_SIZE(input_res_table);
j++) {
const struct input_res *input = &input_res_table[j];
unsigned int hactive_s = input->w;
unsigned int vactive_s = input->h;
if (tv_mode->max_srcw && input->w > tv_mode->max_srcw)
continue;
if (input->w > 1024 && (!tv_mode->progressive
&& !tv_mode->component_only))
continue;
mode_ptr = drm_mode_create(connector->dev);
if (!mode_ptr)
continue;
strncpy(mode_ptr->name, input->name, DRM_DISPLAY_MODE_LEN);
mode_ptr->hdisplay = hactive_s;
mode_ptr->hsync_start = hactive_s + 1;
mode_ptr->hsync_end = hactive_s + 64;
if (mode_ptr->hsync_end <= mode_ptr->hsync_start)
mode_ptr->hsync_end = mode_ptr->hsync_start + 1;
mode_ptr->htotal = hactive_s + 96;
mode_ptr->vdisplay = vactive_s;
mode_ptr->vsync_start = vactive_s + 1;
mode_ptr->vsync_end = vactive_s + 32;
if (mode_ptr->vsync_end <= mode_ptr->vsync_start)
mode_ptr->vsync_end = mode_ptr->vsync_start + 1;
mode_ptr->vtotal = vactive_s + 33;
tmp = (u64) tv_mode->refresh * mode_ptr->vtotal;
tmp *= mode_ptr->htotal;
tmp = div_u64(tmp, 1000000);
mode_ptr->clock = (int) tmp;
mode_ptr->type = DRM_MODE_TYPE_DRIVER;
intel_tv_chose_preferred_modes(connector, mode_ptr);
drm_mode_probed_add(connector, mode_ptr);
count++;
}
return count;
}
static void
intel_tv_destroy(struct drm_connector *connector)
{
drm_sysfs_connector_remove(connector);
drm_connector_cleanup(connector);
kfree(connector);
}
static int
intel_tv_set_property(struct drm_connector *connector, struct drm_property *property,
uint64_t val)
{
struct drm_device *dev = connector->dev;
struct intel_tv *intel_tv = intel_attached_tv(connector);
struct drm_crtc *crtc = intel_tv->base.base.crtc;
int ret = 0;
bool changed = false;
ret = drm_object_property_set_value(&connector->base, property, val);
if (ret < 0)
goto out;
if (property == dev->mode_config.tv_left_margin_property &&
intel_tv->margin[TV_MARGIN_LEFT] != val) {
intel_tv->margin[TV_MARGIN_LEFT] = val;
changed = true;
} else if (property == dev->mode_config.tv_right_margin_property &&
intel_tv->margin[TV_MARGIN_RIGHT] != val) {
intel_tv->margin[TV_MARGIN_RIGHT] = val;
changed = true;
} else if (property == dev->mode_config.tv_top_margin_property &&
intel_tv->margin[TV_MARGIN_TOP] != val) {
intel_tv->margin[TV_MARGIN_TOP] = val;
changed = true;
} else if (property == dev->mode_config.tv_bottom_margin_property &&
intel_tv->margin[TV_MARGIN_BOTTOM] != val) {
intel_tv->margin[TV_MARGIN_BOTTOM] = val;
changed = true;
} else if (property == dev->mode_config.tv_mode_property) {
if (val >= ARRAY_SIZE(tv_modes)) {
ret = -EINVAL;
goto out;
}
if (!strcmp(intel_tv->tv_format, tv_modes[val].name))
goto out;
intel_tv->tv_format = tv_modes[val].name;
changed = true;
} else {
ret = -EINVAL;
goto out;
}
if (changed && crtc)
intel_crtc_restore_mode(crtc);
out:
return ret;
}
static int tv_is_present_in_vbt(struct drm_device *dev)
{
struct drm_i915_private *dev_priv = dev->dev_private;
struct child_device_config *p_child;
int i, ret;
if (!dev_priv->vbt.child_dev_num)
return 1;
ret = 0;
for (i = 0; i < dev_priv->vbt.child_dev_num; i++) {
p_child = dev_priv->vbt.child_dev + i;
if (p_child->device_type != DEVICE_TYPE_INT_TV &&
p_child->device_type != DEVICE_TYPE_TV)
continue;
if (p_child->addin_offset) {
ret = 1;
break;
}
}
return ret;
}
void
intel_tv_init(struct drm_device *dev)
{
struct drm_i915_private *dev_priv = dev->dev_private;
struct drm_connector *connector;
struct intel_tv *intel_tv;
struct intel_encoder *intel_encoder;
struct intel_connector *intel_connector;
u32 tv_dac_on, tv_dac_off, save_tv_dac;
char *tv_format_names[ARRAY_SIZE(tv_modes)];
int i, initial_mode = 0;
if ((I915_READ(TV_CTL) & TV_FUSE_STATE_MASK) == TV_FUSE_STATE_DISABLED)
return;
if (!tv_is_present_in_vbt(dev)) {
DRM_DEBUG_KMS("Integrated TV is not present.\n");
return;
}
if (!dev_priv->vbt.int_tv_support)
return;
save_tv_dac = I915_READ(TV_DAC);
I915_WRITE(TV_DAC, save_tv_dac | TVDAC_STATE_CHG_EN);
tv_dac_on = I915_READ(TV_DAC);
I915_WRITE(TV_DAC, save_tv_dac & ~TVDAC_STATE_CHG_EN);
tv_dac_off = I915_READ(TV_DAC);
I915_WRITE(TV_DAC, save_tv_dac);
if ((tv_dac_on & TVDAC_STATE_CHG_EN) == 0 ||
(tv_dac_off & TVDAC_STATE_CHG_EN) != 0)
return;
intel_tv = kzalloc(sizeof(struct intel_tv), GFP_KERNEL);
if (!intel_tv) {
return;
}
intel_connector = kzalloc(sizeof(struct intel_connector), GFP_KERNEL);
if (!intel_connector) {
kfree(intel_tv);
return;
}
intel_encoder = &intel_tv->base;
connector = &intel_connector->base;
intel_connector->polled = DRM_CONNECTOR_POLL_CONNECT;
drm_connector_init(dev, connector, &intel_tv_connector_funcs,
DRM_MODE_CONNECTOR_SVIDEO);
drm_encoder_init(dev, &intel_encoder->base, &intel_tv_enc_funcs,
DRM_MODE_ENCODER_TVDAC);
intel_encoder->compute_config = intel_tv_compute_config;
intel_encoder->mode_set = intel_tv_mode_set;
intel_encoder->enable = intel_enable_tv;
intel_encoder->disable = intel_disable_tv;
intel_encoder->get_hw_state = intel_tv_get_hw_state;
intel_connector->get_hw_state = intel_connector_get_hw_state;
intel_connector_attach_encoder(intel_connector, intel_encoder);
intel_encoder->type = INTEL_OUTPUT_TVOUT;
intel_encoder->crtc_mask = (1 << 0) | (1 << 1);
intel_encoder->cloneable = false;
intel_encoder->base.possible_crtcs = ((1 << 0) | (1 << 1));
intel_encoder->base.possible_clones = (1 << INTEL_OUTPUT_TVOUT);
intel_tv->type = DRM_MODE_CONNECTOR_Unknown;
intel_tv->margin[TV_MARGIN_LEFT] = 54;
intel_tv->margin[TV_MARGIN_TOP] = 36;
intel_tv->margin[TV_MARGIN_RIGHT] = 46;
intel_tv->margin[TV_MARGIN_BOTTOM] = 37;
intel_tv->tv_format = tv_modes[initial_mode].name;
drm_connector_helper_add(connector, &intel_tv_connector_helper_funcs);
connector->interlace_allowed = false;
connector->doublescan_allowed = false;
for (i = 0; i < ARRAY_SIZE(tv_modes); i++)
tv_format_names[i] = (char *)tv_modes[i].name;
drm_mode_create_tv_properties(dev,
ARRAY_SIZE(tv_modes),
tv_format_names);
drm_object_attach_property(&connector->base, dev->mode_config.tv_mode_property,
initial_mode);
drm_object_attach_property(&connector->base,
dev->mode_config.tv_left_margin_property,
intel_tv->margin[TV_MARGIN_LEFT]);
drm_object_attach_property(&connector->base,
dev->mode_config.tv_top_margin_property,
intel_tv->margin[TV_MARGIN_TOP]);
drm_object_attach_property(&connector->base,
dev->mode_config.tv_right_margin_property,
intel_tv->margin[TV_MARGIN_RIGHT]);
drm_object_attach_property(&connector->base,
dev->mode_config.tv_bottom_margin_property,
intel_tv->margin[TV_MARGIN_BOTTOM]);
drm_sysfs_connector_add(connector);
}
