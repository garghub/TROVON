static struct intel_lvds_encoder *to_lvds_encoder(struct drm_encoder *encoder)
{
return container_of(encoder, struct intel_lvds_encoder, base.base);
}
static struct intel_lvds_connector *to_lvds_connector(struct drm_connector *connector)
{
return container_of(connector, struct intel_lvds_connector, base.base);
}
static bool intel_lvds_get_hw_state(struct intel_encoder *encoder,
enum pipe *pipe)
{
struct drm_device *dev = encoder->base.dev;
struct drm_i915_private *dev_priv = dev->dev_private;
struct intel_lvds_encoder *lvds_encoder = to_lvds_encoder(&encoder->base);
u32 tmp;
tmp = I915_READ(lvds_encoder->reg);
if (!(tmp & LVDS_PORT_EN))
return false;
if (HAS_PCH_CPT(dev))
*pipe = PORT_TO_PIPE_CPT(tmp);
else
*pipe = PORT_TO_PIPE(tmp);
return true;
}
static void intel_pre_pll_enable_lvds(struct intel_encoder *encoder)
{
struct intel_lvds_encoder *lvds_encoder = to_lvds_encoder(&encoder->base);
struct drm_device *dev = encoder->base.dev;
struct drm_i915_private *dev_priv = dev->dev_private;
struct intel_crtc *intel_crtc = to_intel_crtc(encoder->base.crtc);
struct drm_display_mode *fixed_mode =
lvds_encoder->attached_connector->base.panel.fixed_mode;
int pipe = intel_crtc->pipe;
u32 temp;
temp = I915_READ(lvds_encoder->reg);
temp |= LVDS_PORT_EN | LVDS_A0A2_CLKA_POWER_UP;
if (HAS_PCH_CPT(dev)) {
temp &= ~PORT_TRANS_SEL_MASK;
temp |= PORT_TRANS_SEL_CPT(pipe);
} else {
if (pipe == 1) {
temp |= LVDS_PIPEB_SELECT;
} else {
temp &= ~LVDS_PIPEB_SELECT;
}
}
temp |= dev_priv->lvds_border_bits;
if (lvds_encoder->is_dual_link)
temp |= LVDS_B0B3_POWER_UP | LVDS_CLKB_POWER_UP;
else
temp &= ~(LVDS_B0B3_POWER_UP | LVDS_CLKB_POWER_UP);
if (INTEL_INFO(dev)->gen == 4) {
if (dev_priv->lvds_dither)
temp |= LVDS_ENABLE_DITHER;
else
temp &= ~LVDS_ENABLE_DITHER;
}
temp &= ~(LVDS_HSYNC_POLARITY | LVDS_VSYNC_POLARITY);
if (fixed_mode->flags & DRM_MODE_FLAG_NHSYNC)
temp |= LVDS_HSYNC_POLARITY;
if (fixed_mode->flags & DRM_MODE_FLAG_NVSYNC)
temp |= LVDS_VSYNC_POLARITY;
I915_WRITE(lvds_encoder->reg, temp);
}
static void intel_pre_enable_lvds(struct intel_encoder *encoder)
{
struct drm_device *dev = encoder->base.dev;
struct intel_lvds_encoder *enc = to_lvds_encoder(&encoder->base);
struct drm_i915_private *dev_priv = dev->dev_private;
if (HAS_PCH_SPLIT(dev) || !enc->pfit_control)
return;
DRM_DEBUG_KMS("applying panel-fitter: %x, %x\n",
enc->pfit_control,
enc->pfit_pgm_ratios);
I915_WRITE(PFIT_PGM_RATIOS, enc->pfit_pgm_ratios);
I915_WRITE(PFIT_CONTROL, enc->pfit_control);
}
static void intel_enable_lvds(struct intel_encoder *encoder)
{
struct drm_device *dev = encoder->base.dev;
struct intel_lvds_encoder *lvds_encoder = to_lvds_encoder(&encoder->base);
struct intel_crtc *intel_crtc = to_intel_crtc(encoder->base.crtc);
struct drm_i915_private *dev_priv = dev->dev_private;
u32 ctl_reg, stat_reg;
if (HAS_PCH_SPLIT(dev)) {
ctl_reg = PCH_PP_CONTROL;
stat_reg = PCH_PP_STATUS;
} else {
ctl_reg = PP_CONTROL;
stat_reg = PP_STATUS;
}
I915_WRITE(lvds_encoder->reg, I915_READ(lvds_encoder->reg) | LVDS_PORT_EN);
I915_WRITE(ctl_reg, I915_READ(ctl_reg) | POWER_TARGET_ON);
POSTING_READ(lvds_encoder->reg);
if (wait_for((I915_READ(stat_reg) & PP_ON) != 0, 1000))
DRM_ERROR("timed out waiting for panel to power on\n");
intel_panel_enable_backlight(dev, intel_crtc->pipe);
}
static void intel_disable_lvds(struct intel_encoder *encoder)
{
struct drm_device *dev = encoder->base.dev;
struct intel_lvds_encoder *lvds_encoder = to_lvds_encoder(&encoder->base);
struct drm_i915_private *dev_priv = dev->dev_private;
u32 ctl_reg, stat_reg;
if (HAS_PCH_SPLIT(dev)) {
ctl_reg = PCH_PP_CONTROL;
stat_reg = PCH_PP_STATUS;
} else {
ctl_reg = PP_CONTROL;
stat_reg = PP_STATUS;
}
intel_panel_disable_backlight(dev);
I915_WRITE(ctl_reg, I915_READ(ctl_reg) & ~POWER_TARGET_ON);
if (wait_for((I915_READ(stat_reg) & PP_ON) == 0, 1000))
DRM_ERROR("timed out waiting for panel to power off\n");
I915_WRITE(lvds_encoder->reg, I915_READ(lvds_encoder->reg) & ~LVDS_PORT_EN);
POSTING_READ(lvds_encoder->reg);
}
static int intel_lvds_mode_valid(struct drm_connector *connector,
struct drm_display_mode *mode)
{
struct intel_connector *intel_connector = to_intel_connector(connector);
struct drm_display_mode *fixed_mode = intel_connector->panel.fixed_mode;
if (mode->hdisplay > fixed_mode->hdisplay)
return MODE_PANEL;
if (mode->vdisplay > fixed_mode->vdisplay)
return MODE_PANEL;
return MODE_OK;
}
static void
centre_horizontally(struct drm_display_mode *mode,
int width)
{
u32 border, sync_pos, blank_width, sync_width;
sync_width = mode->crtc_hsync_end - mode->crtc_hsync_start;
blank_width = mode->crtc_hblank_end - mode->crtc_hblank_start;
sync_pos = (blank_width - sync_width + 1) / 2;
border = (mode->hdisplay - width + 1) / 2;
border += border & 1;
mode->crtc_hdisplay = width;
mode->crtc_hblank_start = width + border;
mode->crtc_hblank_end = mode->crtc_hblank_start + blank_width;
mode->crtc_hsync_start = mode->crtc_hblank_start + sync_pos;
mode->crtc_hsync_end = mode->crtc_hsync_start + sync_width;
}
static void
centre_vertically(struct drm_display_mode *mode,
int height)
{
u32 border, sync_pos, blank_width, sync_width;
sync_width = mode->crtc_vsync_end - mode->crtc_vsync_start;
blank_width = mode->crtc_vblank_end - mode->crtc_vblank_start;
sync_pos = (blank_width - sync_width + 1) / 2;
border = (mode->vdisplay - height + 1) / 2;
mode->crtc_vdisplay = height;
mode->crtc_vblank_start = height + border;
mode->crtc_vblank_end = mode->crtc_vblank_start + blank_width;
mode->crtc_vsync_start = mode->crtc_vblank_start + sync_pos;
mode->crtc_vsync_end = mode->crtc_vsync_start + sync_width;
}
static inline u32 panel_fitter_scaling(u32 source, u32 target)
{
#define ACCURACY 12
#define FACTOR (1 << ACCURACY)
u32 ratio = source * FACTOR / target;
return (FACTOR * ratio + FACTOR/2) / FACTOR;
}
static bool intel_lvds_compute_config(struct intel_encoder *intel_encoder,
struct intel_crtc_config *pipe_config)
{
struct drm_device *dev = intel_encoder->base.dev;
struct drm_i915_private *dev_priv = dev->dev_private;
struct intel_lvds_encoder *lvds_encoder =
to_lvds_encoder(&intel_encoder->base);
struct intel_connector *intel_connector =
&lvds_encoder->attached_connector->base;
struct drm_display_mode *adjusted_mode = &pipe_config->adjusted_mode;
struct drm_display_mode *mode = &pipe_config->requested_mode;
struct intel_crtc *intel_crtc = lvds_encoder->base.new_crtc;
u32 pfit_control = 0, pfit_pgm_ratios = 0, border = 0;
unsigned int lvds_bpp;
int pipe;
if (INTEL_INFO(dev)->gen < 4 && intel_crtc->pipe == 0) {
DRM_ERROR("Can't support LVDS on pipe A\n");
return false;
}
if (intel_encoder_check_is_cloned(&lvds_encoder->base))
return false;
if ((I915_READ(lvds_encoder->reg) & LVDS_A3_POWER_MASK) ==
LVDS_A3_POWER_UP)
lvds_bpp = 8*3;
else
lvds_bpp = 6*3;
if (lvds_bpp != pipe_config->pipe_bpp) {
DRM_DEBUG_KMS("forcing display bpp (was %d) to LVDS (%d)\n",
pipe_config->pipe_bpp, lvds_bpp);
pipe_config->pipe_bpp = lvds_bpp;
}
intel_fixed_panel_mode(intel_connector->panel.fixed_mode,
adjusted_mode);
if (HAS_PCH_SPLIT(dev)) {
pipe_config->has_pch_encoder = true;
intel_pch_panel_fitting(dev,
intel_connector->panel.fitting_mode,
mode, adjusted_mode);
return true;
}
if (adjusted_mode->hdisplay == mode->hdisplay &&
adjusted_mode->vdisplay == mode->vdisplay)
goto out;
if (INTEL_INFO(dev)->gen >= 4)
pfit_control |= ((intel_crtc->pipe << PFIT_PIPE_SHIFT) |
PFIT_FILTER_FUZZY);
for_each_pipe(pipe)
I915_WRITE(BCLRPAT(pipe), 0);
drm_mode_set_crtcinfo(adjusted_mode, 0);
pipe_config->timings_set = true;
switch (intel_connector->panel.fitting_mode) {
case DRM_MODE_SCALE_CENTER:
centre_horizontally(adjusted_mode, mode->hdisplay);
centre_vertically(adjusted_mode, mode->vdisplay);
border = LVDS_BORDER_ENABLE;
break;
case DRM_MODE_SCALE_ASPECT:
if (INTEL_INFO(dev)->gen >= 4) {
u32 scaled_width = adjusted_mode->hdisplay * mode->vdisplay;
u32 scaled_height = mode->hdisplay * adjusted_mode->vdisplay;
if (scaled_width > scaled_height)
pfit_control |= PFIT_ENABLE | PFIT_SCALING_PILLAR;
else if (scaled_width < scaled_height)
pfit_control |= PFIT_ENABLE | PFIT_SCALING_LETTER;
else if (adjusted_mode->hdisplay != mode->hdisplay)
pfit_control |= PFIT_ENABLE | PFIT_SCALING_AUTO;
} else {
u32 scaled_width = adjusted_mode->hdisplay * mode->vdisplay;
u32 scaled_height = mode->hdisplay * adjusted_mode->vdisplay;
if (scaled_width > scaled_height) {
centre_horizontally(adjusted_mode, scaled_height / mode->vdisplay);
border = LVDS_BORDER_ENABLE;
if (mode->vdisplay != adjusted_mode->vdisplay) {
u32 bits = panel_fitter_scaling(mode->vdisplay, adjusted_mode->vdisplay);
pfit_pgm_ratios |= (bits << PFIT_HORIZ_SCALE_SHIFT |
bits << PFIT_VERT_SCALE_SHIFT);
pfit_control |= (PFIT_ENABLE |
VERT_INTERP_BILINEAR |
HORIZ_INTERP_BILINEAR);
}
} else if (scaled_width < scaled_height) {
centre_vertically(adjusted_mode, scaled_width / mode->hdisplay);
border = LVDS_BORDER_ENABLE;
if (mode->hdisplay != adjusted_mode->hdisplay) {
u32 bits = panel_fitter_scaling(mode->hdisplay, adjusted_mode->hdisplay);
pfit_pgm_ratios |= (bits << PFIT_HORIZ_SCALE_SHIFT |
bits << PFIT_VERT_SCALE_SHIFT);
pfit_control |= (PFIT_ENABLE |
VERT_INTERP_BILINEAR |
HORIZ_INTERP_BILINEAR);
}
} else
pfit_control |= (PFIT_ENABLE |
VERT_AUTO_SCALE | HORIZ_AUTO_SCALE |
VERT_INTERP_BILINEAR |
HORIZ_INTERP_BILINEAR);
}
break;
case DRM_MODE_SCALE_FULLSCREEN:
if (mode->vdisplay != adjusted_mode->vdisplay ||
mode->hdisplay != adjusted_mode->hdisplay) {
pfit_control |= PFIT_ENABLE;
if (INTEL_INFO(dev)->gen >= 4)
pfit_control |= PFIT_SCALING_AUTO;
else
pfit_control |= (VERT_AUTO_SCALE |
VERT_INTERP_BILINEAR |
HORIZ_AUTO_SCALE |
HORIZ_INTERP_BILINEAR);
}
break;
default:
break;
}
out:
if ((pfit_control & PFIT_ENABLE) == 0) {
pfit_control = 0;
pfit_pgm_ratios = 0;
}
if (INTEL_INFO(dev)->gen < 4 && dev_priv->lvds_dither)
pfit_control |= PANEL_8TO6_DITHER_ENABLE;
if (pfit_control != lvds_encoder->pfit_control ||
pfit_pgm_ratios != lvds_encoder->pfit_pgm_ratios) {
lvds_encoder->pfit_control = pfit_control;
lvds_encoder->pfit_pgm_ratios = pfit_pgm_ratios;
}
dev_priv->lvds_border_bits = border;
return true;
}
static void intel_lvds_mode_set(struct drm_encoder *encoder,
struct drm_display_mode *mode,
struct drm_display_mode *adjusted_mode)
{
}
static enum drm_connector_status
intel_lvds_detect(struct drm_connector *connector, bool force)
{
struct drm_device *dev = connector->dev;
enum drm_connector_status status;
status = intel_panel_detect(dev);
if (status != connector_status_unknown)
return status;
return connector_status_connected;
}
static int intel_lvds_get_modes(struct drm_connector *connector)
{
struct intel_lvds_connector *lvds_connector = to_lvds_connector(connector);
struct drm_device *dev = connector->dev;
struct drm_display_mode *mode;
if (!IS_ERR_OR_NULL(lvds_connector->base.edid))
return drm_add_edid_modes(connector, lvds_connector->base.edid);
mode = drm_mode_duplicate(dev, lvds_connector->base.panel.fixed_mode);
if (mode == NULL)
return 0;
drm_mode_probed_add(connector, mode);
return 1;
}
static int intel_no_modeset_on_lid_dmi_callback(const struct dmi_system_id *id)
{
DRM_INFO("Skipping forced modeset for %s\n", id->ident);
return 1;
}
static int intel_lid_notify(struct notifier_block *nb, unsigned long val,
void *unused)
{
struct intel_lvds_connector *lvds_connector =
container_of(nb, struct intel_lvds_connector, lid_notifier);
struct drm_connector *connector = &lvds_connector->base.base;
struct drm_device *dev = connector->dev;
struct drm_i915_private *dev_priv = dev->dev_private;
if (dev->switch_power_state != DRM_SWITCH_POWER_ON)
return NOTIFY_OK;
mutex_lock(&dev_priv->modeset_restore_lock);
if (dev_priv->modeset_restore == MODESET_SUSPENDED)
goto exit;
connector->status = connector->funcs->detect(connector, false);
if (dmi_check_system(intel_no_modeset_on_lid))
goto exit;
if (!acpi_lid_open()) {
dev_priv->modeset_restore = MODESET_ON_LID_OPEN;
goto exit;
}
if (dev_priv->modeset_restore == MODESET_DONE)
goto exit;
drm_modeset_lock_all(dev);
intel_modeset_setup_hw_state(dev, true);
drm_modeset_unlock_all(dev);
dev_priv->modeset_restore = MODESET_DONE;
exit:
mutex_unlock(&dev_priv->modeset_restore_lock);
return NOTIFY_OK;
}
static void intel_lvds_destroy(struct drm_connector *connector)
{
struct intel_lvds_connector *lvds_connector =
to_lvds_connector(connector);
if (lvds_connector->lid_notifier.notifier_call)
acpi_lid_notifier_unregister(&lvds_connector->lid_notifier);
if (!IS_ERR_OR_NULL(lvds_connector->base.edid))
kfree(lvds_connector->base.edid);
intel_panel_fini(&lvds_connector->base.panel);
drm_sysfs_connector_remove(connector);
drm_connector_cleanup(connector);
kfree(connector);
}
static int intel_lvds_set_property(struct drm_connector *connector,
struct drm_property *property,
uint64_t value)
{
struct intel_connector *intel_connector = to_intel_connector(connector);
struct drm_device *dev = connector->dev;
if (property == dev->mode_config.scaling_mode_property) {
struct drm_crtc *crtc;
if (value == DRM_MODE_SCALE_NONE) {
DRM_DEBUG_KMS("no scaling not supported\n");
return -EINVAL;
}
if (intel_connector->panel.fitting_mode == value) {
return 0;
}
intel_connector->panel.fitting_mode = value;
crtc = intel_attached_encoder(connector)->base.crtc;
if (crtc && crtc->enabled) {
intel_crtc_restore_mode(crtc);
}
}
return 0;
}
static int __init intel_no_lvds_dmi_callback(const struct dmi_system_id *id)
{
DRM_INFO("Skipping LVDS initialization for %s\n", id->ident);
return 1;
}
static void intel_find_lvds_downclock(struct drm_device *dev,
struct drm_display_mode *fixed_mode,
struct drm_connector *connector)
{
struct drm_i915_private *dev_priv = dev->dev_private;
struct drm_display_mode *scan;
int temp_downclock;
temp_downclock = fixed_mode->clock;
list_for_each_entry(scan, &connector->probed_modes, head) {
if (scan->hdisplay == fixed_mode->hdisplay &&
scan->hsync_start == fixed_mode->hsync_start &&
scan->hsync_end == fixed_mode->hsync_end &&
scan->htotal == fixed_mode->htotal &&
scan->vdisplay == fixed_mode->vdisplay &&
scan->vsync_start == fixed_mode->vsync_start &&
scan->vsync_end == fixed_mode->vsync_end &&
scan->vtotal == fixed_mode->vtotal) {
if (scan->clock < temp_downclock) {
temp_downclock = scan->clock;
}
}
}
if (temp_downclock < fixed_mode->clock && i915_lvds_downclock) {
dev_priv->lvds_downclock_avail = 1;
dev_priv->lvds_downclock = temp_downclock;
DRM_DEBUG_KMS("LVDS downclock is found in EDID. "
"Normal clock %dKhz, downclock %dKhz\n",
fixed_mode->clock, temp_downclock);
}
}
static bool lvds_is_present_in_vbt(struct drm_device *dev,
u8 *i2c_pin)
{
struct drm_i915_private *dev_priv = dev->dev_private;
int i;
if (!dev_priv->child_dev_num)
return true;
for (i = 0; i < dev_priv->child_dev_num; i++) {
struct child_device_config *child = dev_priv->child_dev + i;
if (child->device_type != DEVICE_TYPE_INT_LFP &&
child->device_type != DEVICE_TYPE_LFP)
continue;
if (intel_gmbus_is_port_valid(child->i2c_pin))
*i2c_pin = child->i2c_pin;
if (child->addin_offset)
return true;
if (dev_priv->opregion.vbt)
return true;
}
return false;
}
static int intel_dual_link_lvds_callback(const struct dmi_system_id *id)
{
DRM_INFO("Forcing lvds to dual link mode on %s\n", id->ident);
return 1;
}
bool intel_is_dual_link_lvds(struct drm_device *dev)
{
struct intel_encoder *encoder;
struct intel_lvds_encoder *lvds_encoder;
list_for_each_entry(encoder, &dev->mode_config.encoder_list,
base.head) {
if (encoder->type == INTEL_OUTPUT_LVDS) {
lvds_encoder = to_lvds_encoder(&encoder->base);
return lvds_encoder->is_dual_link;
}
}
return false;
}
static bool compute_is_dual_link_lvds(struct intel_lvds_encoder *lvds_encoder)
{
struct drm_device *dev = lvds_encoder->base.base.dev;
unsigned int val;
struct drm_i915_private *dev_priv = dev->dev_private;
if (i915_lvds_channel_mode > 0)
return i915_lvds_channel_mode == 2;
if (dmi_check_system(intel_dual_link_lvds))
return true;
val = I915_READ(lvds_encoder->reg);
if (!(val & ~(LVDS_PIPE_MASK | LVDS_DETECTED)))
val = dev_priv->bios_lvds_val;
return (val & LVDS_CLKB_POWER_MASK) == LVDS_CLKB_POWER_UP;
}
static bool intel_lvds_supported(struct drm_device *dev)
{
if (HAS_PCH_IBX(dev) || HAS_PCH_CPT(dev))
return true;
if (INTEL_INFO(dev)->gen <= 4 && IS_MOBILE(dev) && !IS_I830(dev))
return true;
return false;
}
bool intel_lvds_init(struct drm_device *dev)
{
struct drm_i915_private *dev_priv = dev->dev_private;
struct intel_lvds_encoder *lvds_encoder;
struct intel_encoder *intel_encoder;
struct intel_lvds_connector *lvds_connector;
struct intel_connector *intel_connector;
struct drm_connector *connector;
struct drm_encoder *encoder;
struct drm_display_mode *scan;
struct drm_display_mode *fixed_mode = NULL;
struct edid *edid;
struct drm_crtc *crtc;
u32 lvds;
int pipe;
u8 pin;
if (!intel_lvds_supported(dev))
return false;
if (dmi_check_system(intel_no_lvds))
return false;
pin = GMBUS_PORT_PANEL;
if (!lvds_is_present_in_vbt(dev, &pin)) {
DRM_DEBUG_KMS("LVDS is not present in VBT\n");
return false;
}
if (HAS_PCH_SPLIT(dev)) {
if ((I915_READ(PCH_LVDS) & LVDS_DETECTED) == 0)
return false;
if (dev_priv->edp.support) {
DRM_DEBUG_KMS("disable LVDS for eDP support\n");
return false;
}
}
lvds_encoder = kzalloc(sizeof(struct intel_lvds_encoder), GFP_KERNEL);
if (!lvds_encoder)
return false;
lvds_connector = kzalloc(sizeof(struct intel_lvds_connector), GFP_KERNEL);
if (!lvds_connector) {
kfree(lvds_encoder);
return false;
}
lvds_encoder->attached_connector = lvds_connector;
if (!HAS_PCH_SPLIT(dev)) {
lvds_encoder->pfit_control = I915_READ(PFIT_CONTROL);
}
intel_encoder = &lvds_encoder->base;
encoder = &intel_encoder->base;
intel_connector = &lvds_connector->base;
connector = &intel_connector->base;
drm_connector_init(dev, &intel_connector->base, &intel_lvds_connector_funcs,
DRM_MODE_CONNECTOR_LVDS);
drm_encoder_init(dev, &intel_encoder->base, &intel_lvds_enc_funcs,
DRM_MODE_ENCODER_LVDS);
intel_encoder->enable = intel_enable_lvds;
intel_encoder->pre_enable = intel_pre_enable_lvds;
intel_encoder->pre_pll_enable = intel_pre_pll_enable_lvds;
intel_encoder->compute_config = intel_lvds_compute_config;
intel_encoder->disable = intel_disable_lvds;
intel_encoder->get_hw_state = intel_lvds_get_hw_state;
intel_connector->get_hw_state = intel_connector_get_hw_state;
intel_connector_attach_encoder(intel_connector, intel_encoder);
intel_encoder->type = INTEL_OUTPUT_LVDS;
intel_encoder->cloneable = false;
if (HAS_PCH_SPLIT(dev))
intel_encoder->crtc_mask = (1 << 0) | (1 << 1) | (1 << 2);
else if (IS_GEN4(dev))
intel_encoder->crtc_mask = (1 << 0) | (1 << 1);
else
intel_encoder->crtc_mask = (1 << 1);
drm_encoder_helper_add(encoder, &intel_lvds_helper_funcs);
drm_connector_helper_add(connector, &intel_lvds_connector_helper_funcs);
connector->display_info.subpixel_order = SubPixelHorizontalRGB;
connector->interlace_allowed = false;
connector->doublescan_allowed = false;
if (HAS_PCH_SPLIT(dev)) {
lvds_encoder->reg = PCH_LVDS;
} else {
lvds_encoder->reg = LVDS;
}
drm_mode_create_scaling_mode_property(dev);
drm_object_attach_property(&connector->base,
dev->mode_config.scaling_mode_property,
DRM_MODE_SCALE_ASPECT);
intel_connector->panel.fitting_mode = DRM_MODE_SCALE_ASPECT;
edid = drm_get_edid(connector, intel_gmbus_get_adapter(dev_priv, pin));
if (edid) {
if (drm_add_edid_modes(connector, edid)) {
drm_mode_connector_update_edid_property(connector,
edid);
} else {
kfree(edid);
edid = ERR_PTR(-EINVAL);
}
} else {
edid = ERR_PTR(-ENOENT);
}
lvds_connector->base.edid = edid;
if (IS_ERR_OR_NULL(edid)) {
connector->display_info.min_vfreq = 0;
connector->display_info.max_vfreq = 200;
connector->display_info.min_hfreq = 0;
connector->display_info.max_hfreq = 200;
}
list_for_each_entry(scan, &connector->probed_modes, head) {
if (scan->type & DRM_MODE_TYPE_PREFERRED) {
DRM_DEBUG_KMS("using preferred mode from EDID: ");
drm_mode_debug_printmodeline(scan);
fixed_mode = drm_mode_duplicate(dev, scan);
if (fixed_mode) {
intel_find_lvds_downclock(dev, fixed_mode,
connector);
goto out;
}
}
}
if (dev_priv->lfp_lvds_vbt_mode) {
DRM_DEBUG_KMS("using mode from VBT: ");
drm_mode_debug_printmodeline(dev_priv->lfp_lvds_vbt_mode);
fixed_mode = drm_mode_duplicate(dev, dev_priv->lfp_lvds_vbt_mode);
if (fixed_mode) {
fixed_mode->type |= DRM_MODE_TYPE_PREFERRED;
goto out;
}
}
if (HAS_PCH_SPLIT(dev))
goto failed;
lvds = I915_READ(LVDS);
pipe = (lvds & LVDS_PIPEB_SELECT) ? 1 : 0;
crtc = intel_get_crtc_for_pipe(dev, pipe);
if (crtc && (lvds & LVDS_PORT_EN)) {
fixed_mode = intel_crtc_mode_get(dev, crtc);
if (fixed_mode) {
DRM_DEBUG_KMS("using current (BIOS) mode: ");
drm_mode_debug_printmodeline(fixed_mode);
fixed_mode->type |= DRM_MODE_TYPE_PREFERRED;
goto out;
}
}
if (!fixed_mode)
goto failed;
out:
lvds_encoder->is_dual_link = compute_is_dual_link_lvds(lvds_encoder);
DRM_DEBUG_KMS("detected %s-link lvds configuration\n",
lvds_encoder->is_dual_link ? "dual" : "single");
if (HAS_PCH_SPLIT(dev)) {
I915_WRITE(PCH_PP_CONTROL,
I915_READ(PCH_PP_CONTROL) | PANEL_UNLOCK_REGS);
} else {
I915_WRITE(PP_CONTROL,
I915_READ(PP_CONTROL) | PANEL_UNLOCK_REGS);
}
lvds_connector->lid_notifier.notifier_call = intel_lid_notify;
if (acpi_lid_notifier_register(&lvds_connector->lid_notifier)) {
DRM_DEBUG_KMS("lid notifier registration failed\n");
lvds_connector->lid_notifier.notifier_call = NULL;
}
drm_sysfs_connector_add(connector);
intel_panel_init(&intel_connector->panel, fixed_mode);
intel_panel_setup_backlight(connector);
return true;
failed:
DRM_DEBUG_KMS("No LVDS modes found, disabling.\n");
drm_connector_cleanup(connector);
drm_encoder_cleanup(encoder);
if (fixed_mode)
drm_mode_destroy(dev, fixed_mode);
kfree(lvds_encoder);
kfree(lvds_connector);
return false;
}
