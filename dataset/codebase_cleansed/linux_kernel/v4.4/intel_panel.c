void
intel_fixed_panel_mode(const struct drm_display_mode *fixed_mode,
struct drm_display_mode *adjusted_mode)
{
drm_mode_copy(adjusted_mode, fixed_mode);
drm_mode_set_crtcinfo(adjusted_mode, 0);
}
struct drm_display_mode *
intel_find_panel_downclock(struct drm_device *dev,
struct drm_display_mode *fixed_mode,
struct drm_connector *connector)
{
struct drm_display_mode *scan, *tmp_mode;
int temp_downclock;
temp_downclock = fixed_mode->clock;
tmp_mode = NULL;
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
tmp_mode = scan;
}
}
}
if (temp_downclock < fixed_mode->clock)
return drm_mode_duplicate(dev, tmp_mode);
else
return NULL;
}
void
intel_pch_panel_fitting(struct intel_crtc *intel_crtc,
struct intel_crtc_state *pipe_config,
int fitting_mode)
{
const struct drm_display_mode *adjusted_mode = &pipe_config->base.adjusted_mode;
int x = 0, y = 0, width = 0, height = 0;
if (adjusted_mode->crtc_hdisplay == pipe_config->pipe_src_w &&
adjusted_mode->crtc_vdisplay == pipe_config->pipe_src_h)
goto done;
switch (fitting_mode) {
case DRM_MODE_SCALE_CENTER:
width = pipe_config->pipe_src_w;
height = pipe_config->pipe_src_h;
x = (adjusted_mode->crtc_hdisplay - width + 1)/2;
y = (adjusted_mode->crtc_vdisplay - height + 1)/2;
break;
case DRM_MODE_SCALE_ASPECT:
{
u32 scaled_width = adjusted_mode->crtc_hdisplay
* pipe_config->pipe_src_h;
u32 scaled_height = pipe_config->pipe_src_w
* adjusted_mode->crtc_vdisplay;
if (scaled_width > scaled_height) {
width = scaled_height / pipe_config->pipe_src_h;
if (width & 1)
width++;
x = (adjusted_mode->crtc_hdisplay - width + 1) / 2;
y = 0;
height = adjusted_mode->crtc_vdisplay;
} else if (scaled_width < scaled_height) {
height = scaled_width / pipe_config->pipe_src_w;
if (height & 1)
height++;
y = (adjusted_mode->crtc_vdisplay - height + 1) / 2;
x = 0;
width = adjusted_mode->crtc_hdisplay;
} else {
x = y = 0;
width = adjusted_mode->crtc_hdisplay;
height = adjusted_mode->crtc_vdisplay;
}
}
break;
case DRM_MODE_SCALE_FULLSCREEN:
x = y = 0;
width = adjusted_mode->crtc_hdisplay;
height = adjusted_mode->crtc_vdisplay;
break;
default:
WARN(1, "bad panel fit mode: %d\n", fitting_mode);
return;
}
done:
pipe_config->pch_pfit.pos = (x << 16) | y;
pipe_config->pch_pfit.size = (width << 16) | height;
pipe_config->pch_pfit.enabled = pipe_config->pch_pfit.size != 0;
}
static void
centre_horizontally(struct drm_display_mode *adjusted_mode,
int width)
{
u32 border, sync_pos, blank_width, sync_width;
sync_width = adjusted_mode->crtc_hsync_end - adjusted_mode->crtc_hsync_start;
blank_width = adjusted_mode->crtc_hblank_end - adjusted_mode->crtc_hblank_start;
sync_pos = (blank_width - sync_width + 1) / 2;
border = (adjusted_mode->crtc_hdisplay - width + 1) / 2;
border += border & 1;
adjusted_mode->crtc_hdisplay = width;
adjusted_mode->crtc_hblank_start = width + border;
adjusted_mode->crtc_hblank_end = adjusted_mode->crtc_hblank_start + blank_width;
adjusted_mode->crtc_hsync_start = adjusted_mode->crtc_hblank_start + sync_pos;
adjusted_mode->crtc_hsync_end = adjusted_mode->crtc_hsync_start + sync_width;
}
static void
centre_vertically(struct drm_display_mode *adjusted_mode,
int height)
{
u32 border, sync_pos, blank_width, sync_width;
sync_width = adjusted_mode->crtc_vsync_end - adjusted_mode->crtc_vsync_start;
blank_width = adjusted_mode->crtc_vblank_end - adjusted_mode->crtc_vblank_start;
sync_pos = (blank_width - sync_width + 1) / 2;
border = (adjusted_mode->crtc_vdisplay - height + 1) / 2;
adjusted_mode->crtc_vdisplay = height;
adjusted_mode->crtc_vblank_start = height + border;
adjusted_mode->crtc_vblank_end = adjusted_mode->crtc_vblank_start + blank_width;
adjusted_mode->crtc_vsync_start = adjusted_mode->crtc_vblank_start + sync_pos;
adjusted_mode->crtc_vsync_end = adjusted_mode->crtc_vsync_start + sync_width;
}
static inline u32 panel_fitter_scaling(u32 source, u32 target)
{
#define ACCURACY 12
#define FACTOR (1 << ACCURACY)
u32 ratio = source * FACTOR / target;
return (FACTOR * ratio + FACTOR/2) / FACTOR;
}
static void i965_scale_aspect(struct intel_crtc_state *pipe_config,
u32 *pfit_control)
{
const struct drm_display_mode *adjusted_mode = &pipe_config->base.adjusted_mode;
u32 scaled_width = adjusted_mode->crtc_hdisplay *
pipe_config->pipe_src_h;
u32 scaled_height = pipe_config->pipe_src_w *
adjusted_mode->crtc_vdisplay;
if (scaled_width > scaled_height)
*pfit_control |= PFIT_ENABLE |
PFIT_SCALING_PILLAR;
else if (scaled_width < scaled_height)
*pfit_control |= PFIT_ENABLE |
PFIT_SCALING_LETTER;
else if (adjusted_mode->crtc_hdisplay != pipe_config->pipe_src_w)
*pfit_control |= PFIT_ENABLE | PFIT_SCALING_AUTO;
}
static void i9xx_scale_aspect(struct intel_crtc_state *pipe_config,
u32 *pfit_control, u32 *pfit_pgm_ratios,
u32 *border)
{
struct drm_display_mode *adjusted_mode = &pipe_config->base.adjusted_mode;
u32 scaled_width = adjusted_mode->crtc_hdisplay *
pipe_config->pipe_src_h;
u32 scaled_height = pipe_config->pipe_src_w *
adjusted_mode->crtc_vdisplay;
u32 bits;
if (scaled_width > scaled_height) {
centre_horizontally(adjusted_mode,
scaled_height /
pipe_config->pipe_src_h);
*border = LVDS_BORDER_ENABLE;
if (pipe_config->pipe_src_h != adjusted_mode->crtc_vdisplay) {
bits = panel_fitter_scaling(pipe_config->pipe_src_h,
adjusted_mode->crtc_vdisplay);
*pfit_pgm_ratios |= (bits << PFIT_HORIZ_SCALE_SHIFT |
bits << PFIT_VERT_SCALE_SHIFT);
*pfit_control |= (PFIT_ENABLE |
VERT_INTERP_BILINEAR |
HORIZ_INTERP_BILINEAR);
}
} else if (scaled_width < scaled_height) {
centre_vertically(adjusted_mode,
scaled_width /
pipe_config->pipe_src_w);
*border = LVDS_BORDER_ENABLE;
if (pipe_config->pipe_src_w != adjusted_mode->crtc_hdisplay) {
bits = panel_fitter_scaling(pipe_config->pipe_src_w,
adjusted_mode->crtc_hdisplay);
*pfit_pgm_ratios |= (bits << PFIT_HORIZ_SCALE_SHIFT |
bits << PFIT_VERT_SCALE_SHIFT);
*pfit_control |= (PFIT_ENABLE |
VERT_INTERP_BILINEAR |
HORIZ_INTERP_BILINEAR);
}
} else {
*pfit_control |= (PFIT_ENABLE |
VERT_AUTO_SCALE | HORIZ_AUTO_SCALE |
VERT_INTERP_BILINEAR |
HORIZ_INTERP_BILINEAR);
}
}
void intel_gmch_panel_fitting(struct intel_crtc *intel_crtc,
struct intel_crtc_state *pipe_config,
int fitting_mode)
{
struct drm_device *dev = intel_crtc->base.dev;
u32 pfit_control = 0, pfit_pgm_ratios = 0, border = 0;
struct drm_display_mode *adjusted_mode = &pipe_config->base.adjusted_mode;
if (adjusted_mode->crtc_hdisplay == pipe_config->pipe_src_w &&
adjusted_mode->crtc_vdisplay == pipe_config->pipe_src_h)
goto out;
switch (fitting_mode) {
case DRM_MODE_SCALE_CENTER:
centre_horizontally(adjusted_mode, pipe_config->pipe_src_w);
centre_vertically(adjusted_mode, pipe_config->pipe_src_h);
border = LVDS_BORDER_ENABLE;
break;
case DRM_MODE_SCALE_ASPECT:
if (INTEL_INFO(dev)->gen >= 4)
i965_scale_aspect(pipe_config, &pfit_control);
else
i9xx_scale_aspect(pipe_config, &pfit_control,
&pfit_pgm_ratios, &border);
break;
case DRM_MODE_SCALE_FULLSCREEN:
if (pipe_config->pipe_src_h != adjusted_mode->crtc_vdisplay ||
pipe_config->pipe_src_w != adjusted_mode->crtc_hdisplay) {
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
WARN(1, "bad panel fit mode: %d\n", fitting_mode);
return;
}
if (INTEL_INFO(dev)->gen >= 4)
pfit_control |= ((intel_crtc->pipe << PFIT_PIPE_SHIFT) |
PFIT_FILTER_FUZZY);
out:
if ((pfit_control & PFIT_ENABLE) == 0) {
pfit_control = 0;
pfit_pgm_ratios = 0;
}
if (INTEL_INFO(dev)->gen < 4 && pipe_config->pipe_bpp == 18)
pfit_control |= PANEL_8TO6_DITHER_ENABLE;
pipe_config->gmch_pfit.control = pfit_control;
pipe_config->gmch_pfit.pgm_ratios = pfit_pgm_ratios;
pipe_config->gmch_pfit.lvds_border_bits = border;
}
enum drm_connector_status
intel_panel_detect(struct drm_device *dev)
{
struct drm_i915_private *dev_priv = dev->dev_private;
if (!i915.panel_ignore_lid && dev_priv->opregion.lid_state) {
return *dev_priv->opregion.lid_state & 0x1 ?
connector_status_connected :
connector_status_disconnected;
}
switch (i915.panel_ignore_lid) {
case -2:
return connector_status_connected;
case -1:
return connector_status_disconnected;
default:
return connector_status_unknown;
}
}
static uint32_t scale(uint32_t source_val,
uint32_t source_min, uint32_t source_max,
uint32_t target_min, uint32_t target_max)
{
uint64_t target_val;
WARN_ON(source_min > source_max);
WARN_ON(target_min > target_max);
source_val = clamp(source_val, source_min, source_max);
target_val = DIV_ROUND_CLOSEST_ULL((uint64_t)(source_val - source_min) *
(target_max - target_min), source_max - source_min);
target_val += target_min;
return target_val;
}
static inline u32 scale_user_to_hw(struct intel_connector *connector,
u32 user_level, u32 user_max)
{
struct intel_panel *panel = &connector->panel;
return scale(user_level, 0, user_max,
panel->backlight.min, panel->backlight.max);
}
static inline u32 clamp_user_to_hw(struct intel_connector *connector,
u32 user_level, u32 user_max)
{
struct intel_panel *panel = &connector->panel;
u32 hw_level;
hw_level = scale(user_level, 0, user_max, 0, panel->backlight.max);
hw_level = clamp(hw_level, panel->backlight.min, panel->backlight.max);
return hw_level;
}
static inline u32 scale_hw_to_user(struct intel_connector *connector,
u32 hw_level, u32 user_max)
{
struct intel_panel *panel = &connector->panel;
return scale(hw_level, panel->backlight.min, panel->backlight.max,
0, user_max);
}
static u32 intel_panel_compute_brightness(struct intel_connector *connector,
u32 val)
{
struct drm_device *dev = connector->base.dev;
struct drm_i915_private *dev_priv = dev->dev_private;
struct intel_panel *panel = &connector->panel;
WARN_ON(panel->backlight.max == 0);
if (i915.invert_brightness < 0)
return val;
if (i915.invert_brightness > 0 ||
dev_priv->quirks & QUIRK_INVERT_BRIGHTNESS) {
return panel->backlight.max - val;
}
return val;
}
static u32 lpt_get_backlight(struct intel_connector *connector)
{
struct drm_device *dev = connector->base.dev;
struct drm_i915_private *dev_priv = dev->dev_private;
return I915_READ(BLC_PWM_PCH_CTL2) & BACKLIGHT_DUTY_CYCLE_MASK;
}
static u32 pch_get_backlight(struct intel_connector *connector)
{
struct drm_device *dev = connector->base.dev;
struct drm_i915_private *dev_priv = dev->dev_private;
return I915_READ(BLC_PWM_CPU_CTL) & BACKLIGHT_DUTY_CYCLE_MASK;
}
static u32 i9xx_get_backlight(struct intel_connector *connector)
{
struct drm_device *dev = connector->base.dev;
struct drm_i915_private *dev_priv = dev->dev_private;
struct intel_panel *panel = &connector->panel;
u32 val;
val = I915_READ(BLC_PWM_CTL) & BACKLIGHT_DUTY_CYCLE_MASK;
if (INTEL_INFO(dev)->gen < 4)
val >>= 1;
if (panel->backlight.combination_mode) {
u8 lbpc;
pci_read_config_byte(dev->pdev, PCI_LBPC, &lbpc);
val *= lbpc;
}
return val;
}
static u32 _vlv_get_backlight(struct drm_device *dev, enum pipe pipe)
{
struct drm_i915_private *dev_priv = dev->dev_private;
if (WARN_ON(pipe != PIPE_A && pipe != PIPE_B))
return 0;
return I915_READ(VLV_BLC_PWM_CTL(pipe)) & BACKLIGHT_DUTY_CYCLE_MASK;
}
static u32 vlv_get_backlight(struct intel_connector *connector)
{
struct drm_device *dev = connector->base.dev;
enum pipe pipe = intel_get_pipe_from_connector(connector);
return _vlv_get_backlight(dev, pipe);
}
static u32 bxt_get_backlight(struct intel_connector *connector)
{
struct drm_device *dev = connector->base.dev;
struct intel_panel *panel = &connector->panel;
struct drm_i915_private *dev_priv = dev->dev_private;
return I915_READ(BXT_BLC_PWM_DUTY(panel->backlight.controller));
}
static u32 pwm_get_backlight(struct intel_connector *connector)
{
struct intel_panel *panel = &connector->panel;
int duty_ns;
duty_ns = pwm_get_duty_cycle(panel->backlight.pwm);
return DIV_ROUND_UP(duty_ns * 100, CRC_PMIC_PWM_PERIOD_NS);
}
static u32 intel_panel_get_backlight(struct intel_connector *connector)
{
struct drm_device *dev = connector->base.dev;
struct drm_i915_private *dev_priv = dev->dev_private;
struct intel_panel *panel = &connector->panel;
u32 val = 0;
mutex_lock(&dev_priv->backlight_lock);
if (panel->backlight.enabled) {
val = panel->backlight.get(connector);
val = intel_panel_compute_brightness(connector, val);
}
mutex_unlock(&dev_priv->backlight_lock);
DRM_DEBUG_DRIVER("get backlight PWM = %d\n", val);
return val;
}
static void lpt_set_backlight(struct intel_connector *connector, u32 level)
{
struct drm_device *dev = connector->base.dev;
struct drm_i915_private *dev_priv = dev->dev_private;
u32 val = I915_READ(BLC_PWM_PCH_CTL2) & ~BACKLIGHT_DUTY_CYCLE_MASK;
I915_WRITE(BLC_PWM_PCH_CTL2, val | level);
}
static void pch_set_backlight(struct intel_connector *connector, u32 level)
{
struct drm_device *dev = connector->base.dev;
struct drm_i915_private *dev_priv = dev->dev_private;
u32 tmp;
tmp = I915_READ(BLC_PWM_CPU_CTL) & ~BACKLIGHT_DUTY_CYCLE_MASK;
I915_WRITE(BLC_PWM_CPU_CTL, tmp | level);
}
static void i9xx_set_backlight(struct intel_connector *connector, u32 level)
{
struct drm_device *dev = connector->base.dev;
struct drm_i915_private *dev_priv = dev->dev_private;
struct intel_panel *panel = &connector->panel;
u32 tmp, mask;
WARN_ON(panel->backlight.max == 0);
if (panel->backlight.combination_mode) {
u8 lbpc;
lbpc = level * 0xfe / panel->backlight.max + 1;
level /= lbpc;
pci_write_config_byte(dev->pdev, PCI_LBPC, lbpc);
}
if (IS_GEN4(dev)) {
mask = BACKLIGHT_DUTY_CYCLE_MASK;
} else {
level <<= 1;
mask = BACKLIGHT_DUTY_CYCLE_MASK_PNV;
}
tmp = I915_READ(BLC_PWM_CTL) & ~mask;
I915_WRITE(BLC_PWM_CTL, tmp | level);
}
static void vlv_set_backlight(struct intel_connector *connector, u32 level)
{
struct drm_device *dev = connector->base.dev;
struct drm_i915_private *dev_priv = dev->dev_private;
enum pipe pipe = intel_get_pipe_from_connector(connector);
u32 tmp;
if (WARN_ON(pipe != PIPE_A && pipe != PIPE_B))
return;
tmp = I915_READ(VLV_BLC_PWM_CTL(pipe)) & ~BACKLIGHT_DUTY_CYCLE_MASK;
I915_WRITE(VLV_BLC_PWM_CTL(pipe), tmp | level);
}
static void bxt_set_backlight(struct intel_connector *connector, u32 level)
{
struct drm_device *dev = connector->base.dev;
struct drm_i915_private *dev_priv = dev->dev_private;
struct intel_panel *panel = &connector->panel;
I915_WRITE(BXT_BLC_PWM_DUTY(panel->backlight.controller), level);
}
static void pwm_set_backlight(struct intel_connector *connector, u32 level)
{
struct intel_panel *panel = &connector->panel;
int duty_ns = DIV_ROUND_UP(level * CRC_PMIC_PWM_PERIOD_NS, 100);
pwm_config(panel->backlight.pwm, duty_ns, CRC_PMIC_PWM_PERIOD_NS);
}
static void
intel_panel_actually_set_backlight(struct intel_connector *connector, u32 level)
{
struct intel_panel *panel = &connector->panel;
DRM_DEBUG_DRIVER("set backlight PWM = %d\n", level);
level = intel_panel_compute_brightness(connector, level);
panel->backlight.set(connector, level);
}
static void intel_panel_set_backlight(struct intel_connector *connector,
u32 user_level, u32 user_max)
{
struct drm_device *dev = connector->base.dev;
struct drm_i915_private *dev_priv = dev->dev_private;
struct intel_panel *panel = &connector->panel;
u32 hw_level;
if (!panel->backlight.present)
return;
mutex_lock(&dev_priv->backlight_lock);
WARN_ON(panel->backlight.max == 0);
hw_level = scale_user_to_hw(connector, user_level, user_max);
panel->backlight.level = hw_level;
if (panel->backlight.enabled)
intel_panel_actually_set_backlight(connector, hw_level);
mutex_unlock(&dev_priv->backlight_lock);
}
void intel_panel_set_backlight_acpi(struct intel_connector *connector,
u32 user_level, u32 user_max)
{
struct drm_device *dev = connector->base.dev;
struct drm_i915_private *dev_priv = dev->dev_private;
struct intel_panel *panel = &connector->panel;
enum pipe pipe = intel_get_pipe_from_connector(connector);
u32 hw_level;
if (!panel->backlight.present || pipe == INVALID_PIPE)
return;
mutex_lock(&dev_priv->backlight_lock);
WARN_ON(panel->backlight.max == 0);
hw_level = clamp_user_to_hw(connector, user_level, user_max);
panel->backlight.level = hw_level;
if (panel->backlight.device)
panel->backlight.device->props.brightness =
scale_hw_to_user(connector,
panel->backlight.level,
panel->backlight.device->props.max_brightness);
if (panel->backlight.enabled)
intel_panel_actually_set_backlight(connector, hw_level);
mutex_unlock(&dev_priv->backlight_lock);
}
static void lpt_disable_backlight(struct intel_connector *connector)
{
struct drm_device *dev = connector->base.dev;
struct drm_i915_private *dev_priv = dev->dev_private;
u32 tmp;
intel_panel_actually_set_backlight(connector, 0);
tmp = I915_READ(BLC_PWM_CPU_CTL2);
if (tmp & BLM_PWM_ENABLE) {
DRM_DEBUG_KMS("cpu backlight was enabled, disabling\n");
I915_WRITE(BLC_PWM_CPU_CTL2, tmp & ~BLM_PWM_ENABLE);
}
tmp = I915_READ(BLC_PWM_PCH_CTL1);
I915_WRITE(BLC_PWM_PCH_CTL1, tmp & ~BLM_PCH_PWM_ENABLE);
}
static void pch_disable_backlight(struct intel_connector *connector)
{
struct drm_device *dev = connector->base.dev;
struct drm_i915_private *dev_priv = dev->dev_private;
u32 tmp;
intel_panel_actually_set_backlight(connector, 0);
tmp = I915_READ(BLC_PWM_CPU_CTL2);
I915_WRITE(BLC_PWM_CPU_CTL2, tmp & ~BLM_PWM_ENABLE);
tmp = I915_READ(BLC_PWM_PCH_CTL1);
I915_WRITE(BLC_PWM_PCH_CTL1, tmp & ~BLM_PCH_PWM_ENABLE);
}
static void i9xx_disable_backlight(struct intel_connector *connector)
{
intel_panel_actually_set_backlight(connector, 0);
}
static void i965_disable_backlight(struct intel_connector *connector)
{
struct drm_device *dev = connector->base.dev;
struct drm_i915_private *dev_priv = dev->dev_private;
u32 tmp;
intel_panel_actually_set_backlight(connector, 0);
tmp = I915_READ(BLC_PWM_CTL2);
I915_WRITE(BLC_PWM_CTL2, tmp & ~BLM_PWM_ENABLE);
}
static void vlv_disable_backlight(struct intel_connector *connector)
{
struct drm_device *dev = connector->base.dev;
struct drm_i915_private *dev_priv = dev->dev_private;
enum pipe pipe = intel_get_pipe_from_connector(connector);
u32 tmp;
if (WARN_ON(pipe != PIPE_A && pipe != PIPE_B))
return;
intel_panel_actually_set_backlight(connector, 0);
tmp = I915_READ(VLV_BLC_PWM_CTL2(pipe));
I915_WRITE(VLV_BLC_PWM_CTL2(pipe), tmp & ~BLM_PWM_ENABLE);
}
static void bxt_disable_backlight(struct intel_connector *connector)
{
struct drm_device *dev = connector->base.dev;
struct drm_i915_private *dev_priv = dev->dev_private;
struct intel_panel *panel = &connector->panel;
u32 tmp, val;
intel_panel_actually_set_backlight(connector, 0);
tmp = I915_READ(BXT_BLC_PWM_CTL(panel->backlight.controller));
I915_WRITE(BXT_BLC_PWM_CTL(panel->backlight.controller),
tmp & ~BXT_BLC_PWM_ENABLE);
if (panel->backlight.controller == 1) {
val = I915_READ(UTIL_PIN_CTL);
val &= ~UTIL_PIN_ENABLE;
I915_WRITE(UTIL_PIN_CTL, val);
}
}
static void pwm_disable_backlight(struct intel_connector *connector)
{
struct intel_panel *panel = &connector->panel;
pwm_config(panel->backlight.pwm, 0, CRC_PMIC_PWM_PERIOD_NS);
usleep_range(2000, 3000);
pwm_disable(panel->backlight.pwm);
}
void intel_panel_disable_backlight(struct intel_connector *connector)
{
struct drm_device *dev = connector->base.dev;
struct drm_i915_private *dev_priv = dev->dev_private;
struct intel_panel *panel = &connector->panel;
if (!panel->backlight.present)
return;
if (dev->switch_power_state == DRM_SWITCH_POWER_CHANGING) {
DRM_DEBUG_DRIVER("Skipping backlight disable on vga switch\n");
return;
}
mutex_lock(&dev_priv->backlight_lock);
if (panel->backlight.device)
panel->backlight.device->props.power = FB_BLANK_POWERDOWN;
panel->backlight.enabled = false;
panel->backlight.disable(connector);
mutex_unlock(&dev_priv->backlight_lock);
}
static void lpt_enable_backlight(struct intel_connector *connector)
{
struct drm_device *dev = connector->base.dev;
struct drm_i915_private *dev_priv = dev->dev_private;
struct intel_panel *panel = &connector->panel;
u32 pch_ctl1, pch_ctl2;
pch_ctl1 = I915_READ(BLC_PWM_PCH_CTL1);
if (pch_ctl1 & BLM_PCH_PWM_ENABLE) {
DRM_DEBUG_KMS("pch backlight already enabled\n");
pch_ctl1 &= ~BLM_PCH_PWM_ENABLE;
I915_WRITE(BLC_PWM_PCH_CTL1, pch_ctl1);
}
pch_ctl2 = panel->backlight.max << 16;
I915_WRITE(BLC_PWM_PCH_CTL2, pch_ctl2);
pch_ctl1 = 0;
if (panel->backlight.active_low_pwm)
pch_ctl1 |= BLM_PCH_POLARITY;
if (HAS_PCH_LPT(dev_priv))
pch_ctl1 |= BLM_PCH_OVERRIDE_ENABLE;
I915_WRITE(BLC_PWM_PCH_CTL1, pch_ctl1);
POSTING_READ(BLC_PWM_PCH_CTL1);
I915_WRITE(BLC_PWM_PCH_CTL1, pch_ctl1 | BLM_PCH_PWM_ENABLE);
intel_panel_actually_set_backlight(connector, panel->backlight.level);
}
static void pch_enable_backlight(struct intel_connector *connector)
{
struct drm_device *dev = connector->base.dev;
struct drm_i915_private *dev_priv = dev->dev_private;
struct intel_panel *panel = &connector->panel;
enum pipe pipe = intel_get_pipe_from_connector(connector);
enum transcoder cpu_transcoder =
intel_pipe_to_cpu_transcoder(dev_priv, pipe);
u32 cpu_ctl2, pch_ctl1, pch_ctl2;
cpu_ctl2 = I915_READ(BLC_PWM_CPU_CTL2);
if (cpu_ctl2 & BLM_PWM_ENABLE) {
DRM_DEBUG_KMS("cpu backlight already enabled\n");
cpu_ctl2 &= ~BLM_PWM_ENABLE;
I915_WRITE(BLC_PWM_CPU_CTL2, cpu_ctl2);
}
pch_ctl1 = I915_READ(BLC_PWM_PCH_CTL1);
if (pch_ctl1 & BLM_PCH_PWM_ENABLE) {
DRM_DEBUG_KMS("pch backlight already enabled\n");
pch_ctl1 &= ~BLM_PCH_PWM_ENABLE;
I915_WRITE(BLC_PWM_PCH_CTL1, pch_ctl1);
}
if (cpu_transcoder == TRANSCODER_EDP)
cpu_ctl2 = BLM_TRANSCODER_EDP;
else
cpu_ctl2 = BLM_PIPE(cpu_transcoder);
I915_WRITE(BLC_PWM_CPU_CTL2, cpu_ctl2);
POSTING_READ(BLC_PWM_CPU_CTL2);
I915_WRITE(BLC_PWM_CPU_CTL2, cpu_ctl2 | BLM_PWM_ENABLE);
intel_panel_actually_set_backlight(connector, panel->backlight.level);
pch_ctl2 = panel->backlight.max << 16;
I915_WRITE(BLC_PWM_PCH_CTL2, pch_ctl2);
pch_ctl1 = 0;
if (panel->backlight.active_low_pwm)
pch_ctl1 |= BLM_PCH_POLARITY;
I915_WRITE(BLC_PWM_PCH_CTL1, pch_ctl1);
POSTING_READ(BLC_PWM_PCH_CTL1);
I915_WRITE(BLC_PWM_PCH_CTL1, pch_ctl1 | BLM_PCH_PWM_ENABLE);
}
static void i9xx_enable_backlight(struct intel_connector *connector)
{
struct drm_device *dev = connector->base.dev;
struct drm_i915_private *dev_priv = dev->dev_private;
struct intel_panel *panel = &connector->panel;
u32 ctl, freq;
ctl = I915_READ(BLC_PWM_CTL);
if (ctl & BACKLIGHT_DUTY_CYCLE_MASK_PNV) {
DRM_DEBUG_KMS("backlight already enabled\n");
I915_WRITE(BLC_PWM_CTL, 0);
}
freq = panel->backlight.max;
if (panel->backlight.combination_mode)
freq /= 0xff;
ctl = freq << 17;
if (panel->backlight.combination_mode)
ctl |= BLM_LEGACY_MODE;
if (IS_PINEVIEW(dev) && panel->backlight.active_low_pwm)
ctl |= BLM_POLARITY_PNV;
I915_WRITE(BLC_PWM_CTL, ctl);
POSTING_READ(BLC_PWM_CTL);
intel_panel_actually_set_backlight(connector, panel->backlight.level);
if (IS_GEN2(dev))
I915_WRITE(BLC_HIST_CTL, BLM_HISTOGRAM_ENABLE);
}
static void i965_enable_backlight(struct intel_connector *connector)
{
struct drm_device *dev = connector->base.dev;
struct drm_i915_private *dev_priv = dev->dev_private;
struct intel_panel *panel = &connector->panel;
enum pipe pipe = intel_get_pipe_from_connector(connector);
u32 ctl, ctl2, freq;
ctl2 = I915_READ(BLC_PWM_CTL2);
if (ctl2 & BLM_PWM_ENABLE) {
DRM_DEBUG_KMS("backlight already enabled\n");
ctl2 &= ~BLM_PWM_ENABLE;
I915_WRITE(BLC_PWM_CTL2, ctl2);
}
freq = panel->backlight.max;
if (panel->backlight.combination_mode)
freq /= 0xff;
ctl = freq << 16;
I915_WRITE(BLC_PWM_CTL, ctl);
ctl2 = BLM_PIPE(pipe);
if (panel->backlight.combination_mode)
ctl2 |= BLM_COMBINATION_MODE;
if (panel->backlight.active_low_pwm)
ctl2 |= BLM_POLARITY_I965;
I915_WRITE(BLC_PWM_CTL2, ctl2);
POSTING_READ(BLC_PWM_CTL2);
I915_WRITE(BLC_PWM_CTL2, ctl2 | BLM_PWM_ENABLE);
intel_panel_actually_set_backlight(connector, panel->backlight.level);
}
static void vlv_enable_backlight(struct intel_connector *connector)
{
struct drm_device *dev = connector->base.dev;
struct drm_i915_private *dev_priv = dev->dev_private;
struct intel_panel *panel = &connector->panel;
enum pipe pipe = intel_get_pipe_from_connector(connector);
u32 ctl, ctl2;
if (WARN_ON(pipe != PIPE_A && pipe != PIPE_B))
return;
ctl2 = I915_READ(VLV_BLC_PWM_CTL2(pipe));
if (ctl2 & BLM_PWM_ENABLE) {
DRM_DEBUG_KMS("backlight already enabled\n");
ctl2 &= ~BLM_PWM_ENABLE;
I915_WRITE(VLV_BLC_PWM_CTL2(pipe), ctl2);
}
ctl = panel->backlight.max << 16;
I915_WRITE(VLV_BLC_PWM_CTL(pipe), ctl);
intel_panel_actually_set_backlight(connector, panel->backlight.level);
ctl2 = 0;
if (panel->backlight.active_low_pwm)
ctl2 |= BLM_POLARITY_I965;
I915_WRITE(VLV_BLC_PWM_CTL2(pipe), ctl2);
POSTING_READ(VLV_BLC_PWM_CTL2(pipe));
I915_WRITE(VLV_BLC_PWM_CTL2(pipe), ctl2 | BLM_PWM_ENABLE);
}
static void bxt_enable_backlight(struct intel_connector *connector)
{
struct drm_device *dev = connector->base.dev;
struct drm_i915_private *dev_priv = dev->dev_private;
struct intel_panel *panel = &connector->panel;
enum pipe pipe = intel_get_pipe_from_connector(connector);
u32 pwm_ctl, val;
if (panel->backlight.controller == 1) {
val = I915_READ(UTIL_PIN_CTL);
if (val & UTIL_PIN_ENABLE) {
DRM_DEBUG_KMS("util pin already enabled\n");
val &= ~UTIL_PIN_ENABLE;
I915_WRITE(UTIL_PIN_CTL, val);
}
val = 0;
if (panel->backlight.util_pin_active_low)
val |= UTIL_PIN_POLARITY;
I915_WRITE(UTIL_PIN_CTL, val | UTIL_PIN_PIPE(pipe) |
UTIL_PIN_MODE_PWM | UTIL_PIN_ENABLE);
}
pwm_ctl = I915_READ(BXT_BLC_PWM_CTL(panel->backlight.controller));
if (pwm_ctl & BXT_BLC_PWM_ENABLE) {
DRM_DEBUG_KMS("backlight already enabled\n");
pwm_ctl &= ~BXT_BLC_PWM_ENABLE;
I915_WRITE(BXT_BLC_PWM_CTL(panel->backlight.controller),
pwm_ctl);
}
I915_WRITE(BXT_BLC_PWM_FREQ(panel->backlight.controller),
panel->backlight.max);
intel_panel_actually_set_backlight(connector, panel->backlight.level);
pwm_ctl = 0;
if (panel->backlight.active_low_pwm)
pwm_ctl |= BXT_BLC_PWM_POLARITY;
I915_WRITE(BXT_BLC_PWM_CTL(panel->backlight.controller), pwm_ctl);
POSTING_READ(BXT_BLC_PWM_CTL(panel->backlight.controller));
I915_WRITE(BXT_BLC_PWM_CTL(panel->backlight.controller),
pwm_ctl | BXT_BLC_PWM_ENABLE);
}
static void pwm_enable_backlight(struct intel_connector *connector)
{
struct intel_panel *panel = &connector->panel;
pwm_enable(panel->backlight.pwm);
intel_panel_actually_set_backlight(connector, panel->backlight.level);
}
void intel_panel_enable_backlight(struct intel_connector *connector)
{
struct drm_device *dev = connector->base.dev;
struct drm_i915_private *dev_priv = dev->dev_private;
struct intel_panel *panel = &connector->panel;
enum pipe pipe = intel_get_pipe_from_connector(connector);
if (!panel->backlight.present)
return;
DRM_DEBUG_KMS("pipe %c\n", pipe_name(pipe));
mutex_lock(&dev_priv->backlight_lock);
WARN_ON(panel->backlight.max == 0);
if (panel->backlight.level <= panel->backlight.min) {
panel->backlight.level = panel->backlight.max;
if (panel->backlight.device)
panel->backlight.device->props.brightness =
scale_hw_to_user(connector,
panel->backlight.level,
panel->backlight.device->props.max_brightness);
}
panel->backlight.enable(connector);
panel->backlight.enabled = true;
if (panel->backlight.device)
panel->backlight.device->props.power = FB_BLANK_UNBLANK;
mutex_unlock(&dev_priv->backlight_lock);
}
static int intel_backlight_device_update_status(struct backlight_device *bd)
{
struct intel_connector *connector = bl_get_data(bd);
struct intel_panel *panel = &connector->panel;
struct drm_device *dev = connector->base.dev;
drm_modeset_lock(&dev->mode_config.connection_mutex, NULL);
DRM_DEBUG_KMS("updating intel_backlight, brightness=%d/%d\n",
bd->props.brightness, bd->props.max_brightness);
intel_panel_set_backlight(connector, bd->props.brightness,
bd->props.max_brightness);
if (panel->backlight.enabled) {
if (panel->backlight.power) {
bool enable = bd->props.power == FB_BLANK_UNBLANK &&
bd->props.brightness != 0;
panel->backlight.power(connector, enable);
}
} else {
bd->props.power = FB_BLANK_POWERDOWN;
}
drm_modeset_unlock(&dev->mode_config.connection_mutex);
return 0;
}
static int intel_backlight_device_get_brightness(struct backlight_device *bd)
{
struct intel_connector *connector = bl_get_data(bd);
struct drm_device *dev = connector->base.dev;
struct drm_i915_private *dev_priv = dev->dev_private;
u32 hw_level;
int ret;
intel_runtime_pm_get(dev_priv);
drm_modeset_lock(&dev->mode_config.connection_mutex, NULL);
hw_level = intel_panel_get_backlight(connector);
ret = scale_hw_to_user(connector, hw_level, bd->props.max_brightness);
drm_modeset_unlock(&dev->mode_config.connection_mutex);
intel_runtime_pm_put(dev_priv);
return ret;
}
static int intel_backlight_device_register(struct intel_connector *connector)
{
struct intel_panel *panel = &connector->panel;
struct backlight_properties props;
if (WARN_ON(panel->backlight.device))
return -ENODEV;
if (!panel->backlight.present)
return 0;
WARN_ON(panel->backlight.max == 0);
memset(&props, 0, sizeof(props));
props.type = BACKLIGHT_RAW;
props.max_brightness = panel->backlight.max;
props.brightness = scale_hw_to_user(connector,
panel->backlight.level,
props.max_brightness);
if (panel->backlight.enabled)
props.power = FB_BLANK_UNBLANK;
else
props.power = FB_BLANK_POWERDOWN;
panel->backlight.device =
backlight_device_register("intel_backlight",
connector->base.kdev,
connector,
&intel_backlight_device_ops, &props);
if (IS_ERR(panel->backlight.device)) {
DRM_ERROR("Failed to register backlight: %ld\n",
PTR_ERR(panel->backlight.device));
panel->backlight.device = NULL;
return -ENODEV;
}
DRM_DEBUG_KMS("Connector %s backlight sysfs interface registered\n",
connector->base.name);
return 0;
}
static void intel_backlight_device_unregister(struct intel_connector *connector)
{
struct intel_panel *panel = &connector->panel;
if (panel->backlight.device) {
backlight_device_unregister(panel->backlight.device);
panel->backlight.device = NULL;
}
}
static int intel_backlight_device_register(struct intel_connector *connector)
{
return 0;
}
static void intel_backlight_device_unregister(struct intel_connector *connector)
{
}
static u32 spt_hz_to_pwm(struct intel_connector *connector, u32 pwm_freq_hz)
{
struct drm_device *dev = connector->base.dev;
struct drm_i915_private *dev_priv = dev->dev_private;
u32 mul, clock;
if (I915_READ(SOUTH_CHICKEN1) & SPT_PWM_GRANULARITY)
mul = 128;
else
mul = 16;
clock = MHz(24);
return clock / (pwm_freq_hz * mul);
}
static u32 lpt_hz_to_pwm(struct intel_connector *connector, u32 pwm_freq_hz)
{
struct drm_device *dev = connector->base.dev;
struct drm_i915_private *dev_priv = dev->dev_private;
u32 mul, clock;
if (I915_READ(SOUTH_CHICKEN2) & LPT_PWM_GRANULARITY)
mul = 16;
else
mul = 128;
if (dev_priv->pch_id == INTEL_PCH_LPT_DEVICE_ID_TYPE)
clock = MHz(135);
else
clock = MHz(24);
return clock / (pwm_freq_hz * mul);
}
static u32 pch_hz_to_pwm(struct intel_connector *connector, u32 pwm_freq_hz)
{
struct drm_device *dev = connector->base.dev;
int clock = MHz(intel_pch_rawclk(dev));
return clock / (pwm_freq_hz * 128);
}
static u32 i9xx_hz_to_pwm(struct intel_connector *connector, u32 pwm_freq_hz)
{
struct drm_device *dev = connector->base.dev;
struct drm_i915_private *dev_priv = dev->dev_private;
int clock;
if (IS_PINEVIEW(dev))
clock = intel_hrawclk(dev);
else
clock = 1000 * dev_priv->display.get_display_clock_speed(dev);
return clock / (pwm_freq_hz * 32);
}
static u32 i965_hz_to_pwm(struct intel_connector *connector, u32 pwm_freq_hz)
{
struct drm_device *dev = connector->base.dev;
struct drm_i915_private *dev_priv = dev->dev_private;
int clock = 1000 * dev_priv->display.get_display_clock_speed(dev);
return clock / (pwm_freq_hz * 128);
}
static u32 vlv_hz_to_pwm(struct intel_connector *connector, u32 pwm_freq_hz)
{
struct drm_device *dev = connector->base.dev;
struct drm_i915_private *dev_priv = dev->dev_private;
int clock;
if ((I915_READ(CBR1_VLV) & CBR_PWM_CLOCK_MUX_SELECT) == 0) {
if (IS_CHERRYVIEW(dev))
return KHz(19200) / (pwm_freq_hz * 16);
else
return MHz(25) / (pwm_freq_hz * 16);
} else {
clock = intel_hrawclk(dev);
return MHz(clock) / (pwm_freq_hz * 128);
}
}
static u32 get_backlight_max_vbt(struct intel_connector *connector)
{
struct drm_device *dev = connector->base.dev;
struct drm_i915_private *dev_priv = dev->dev_private;
struct intel_panel *panel = &connector->panel;
u16 pwm_freq_hz = dev_priv->vbt.backlight.pwm_freq_hz;
u32 pwm;
if (!pwm_freq_hz) {
DRM_DEBUG_KMS("backlight frequency not specified in VBT\n");
return 0;
}
if (!panel->backlight.hz_to_pwm) {
DRM_DEBUG_KMS("backlight frequency setting from VBT currently not supported on this platform\n");
return 0;
}
pwm = panel->backlight.hz_to_pwm(connector, pwm_freq_hz);
if (!pwm) {
DRM_DEBUG_KMS("backlight frequency conversion failed\n");
return 0;
}
DRM_DEBUG_KMS("backlight frequency %u Hz from VBT\n", pwm_freq_hz);
return pwm;
}
static u32 get_backlight_min_vbt(struct intel_connector *connector)
{
struct drm_device *dev = connector->base.dev;
struct drm_i915_private *dev_priv = dev->dev_private;
struct intel_panel *panel = &connector->panel;
int min;
WARN_ON(panel->backlight.max == 0);
min = clamp_t(int, dev_priv->vbt.backlight.min_brightness, 0, 64);
if (min != dev_priv->vbt.backlight.min_brightness) {
DRM_DEBUG_KMS("clamping VBT min backlight %d/255 to %d/255\n",
dev_priv->vbt.backlight.min_brightness, min);
}
return scale(min, 0, 255, 0, panel->backlight.max);
}
static int lpt_setup_backlight(struct intel_connector *connector, enum pipe unused)
{
struct drm_device *dev = connector->base.dev;
struct drm_i915_private *dev_priv = dev->dev_private;
struct intel_panel *panel = &connector->panel;
u32 pch_ctl1, pch_ctl2, val;
pch_ctl1 = I915_READ(BLC_PWM_PCH_CTL1);
panel->backlight.active_low_pwm = pch_ctl1 & BLM_PCH_POLARITY;
pch_ctl2 = I915_READ(BLC_PWM_PCH_CTL2);
panel->backlight.max = pch_ctl2 >> 16;
if (!panel->backlight.max)
panel->backlight.max = get_backlight_max_vbt(connector);
if (!panel->backlight.max)
return -ENODEV;
panel->backlight.min = get_backlight_min_vbt(connector);
val = lpt_get_backlight(connector);
panel->backlight.level = intel_panel_compute_brightness(connector, val);
panel->backlight.enabled = (pch_ctl1 & BLM_PCH_PWM_ENABLE) &&
panel->backlight.level != 0;
return 0;
}
static int pch_setup_backlight(struct intel_connector *connector, enum pipe unused)
{
struct drm_device *dev = connector->base.dev;
struct drm_i915_private *dev_priv = dev->dev_private;
struct intel_panel *panel = &connector->panel;
u32 cpu_ctl2, pch_ctl1, pch_ctl2, val;
pch_ctl1 = I915_READ(BLC_PWM_PCH_CTL1);
panel->backlight.active_low_pwm = pch_ctl1 & BLM_PCH_POLARITY;
pch_ctl2 = I915_READ(BLC_PWM_PCH_CTL2);
panel->backlight.max = pch_ctl2 >> 16;
if (!panel->backlight.max)
panel->backlight.max = get_backlight_max_vbt(connector);
if (!panel->backlight.max)
return -ENODEV;
panel->backlight.min = get_backlight_min_vbt(connector);
val = pch_get_backlight(connector);
panel->backlight.level = intel_panel_compute_brightness(connector, val);
cpu_ctl2 = I915_READ(BLC_PWM_CPU_CTL2);
panel->backlight.enabled = (cpu_ctl2 & BLM_PWM_ENABLE) &&
(pch_ctl1 & BLM_PCH_PWM_ENABLE) && panel->backlight.level != 0;
return 0;
}
static int i9xx_setup_backlight(struct intel_connector *connector, enum pipe unused)
{
struct drm_device *dev = connector->base.dev;
struct drm_i915_private *dev_priv = dev->dev_private;
struct intel_panel *panel = &connector->panel;
u32 ctl, val;
ctl = I915_READ(BLC_PWM_CTL);
if (IS_GEN2(dev) || IS_I915GM(dev) || IS_I945GM(dev))
panel->backlight.combination_mode = ctl & BLM_LEGACY_MODE;
if (IS_PINEVIEW(dev))
panel->backlight.active_low_pwm = ctl & BLM_POLARITY_PNV;
panel->backlight.max = ctl >> 17;
if (!panel->backlight.max) {
panel->backlight.max = get_backlight_max_vbt(connector);
panel->backlight.max >>= 1;
}
if (!panel->backlight.max)
return -ENODEV;
if (panel->backlight.combination_mode)
panel->backlight.max *= 0xff;
panel->backlight.min = get_backlight_min_vbt(connector);
val = i9xx_get_backlight(connector);
panel->backlight.level = intel_panel_compute_brightness(connector, val);
panel->backlight.enabled = panel->backlight.level != 0;
return 0;
}
static int i965_setup_backlight(struct intel_connector *connector, enum pipe unused)
{
struct drm_device *dev = connector->base.dev;
struct drm_i915_private *dev_priv = dev->dev_private;
struct intel_panel *panel = &connector->panel;
u32 ctl, ctl2, val;
ctl2 = I915_READ(BLC_PWM_CTL2);
panel->backlight.combination_mode = ctl2 & BLM_COMBINATION_MODE;
panel->backlight.active_low_pwm = ctl2 & BLM_POLARITY_I965;
ctl = I915_READ(BLC_PWM_CTL);
panel->backlight.max = ctl >> 16;
if (!panel->backlight.max)
panel->backlight.max = get_backlight_max_vbt(connector);
if (!panel->backlight.max)
return -ENODEV;
if (panel->backlight.combination_mode)
panel->backlight.max *= 0xff;
panel->backlight.min = get_backlight_min_vbt(connector);
val = i9xx_get_backlight(connector);
panel->backlight.level = intel_panel_compute_brightness(connector, val);
panel->backlight.enabled = (ctl2 & BLM_PWM_ENABLE) &&
panel->backlight.level != 0;
return 0;
}
static int vlv_setup_backlight(struct intel_connector *connector, enum pipe pipe)
{
struct drm_device *dev = connector->base.dev;
struct drm_i915_private *dev_priv = dev->dev_private;
struct intel_panel *panel = &connector->panel;
u32 ctl, ctl2, val;
if (WARN_ON(pipe != PIPE_A && pipe != PIPE_B))
return -ENODEV;
ctl2 = I915_READ(VLV_BLC_PWM_CTL2(pipe));
panel->backlight.active_low_pwm = ctl2 & BLM_POLARITY_I965;
ctl = I915_READ(VLV_BLC_PWM_CTL(pipe));
panel->backlight.max = ctl >> 16;
if (!panel->backlight.max)
panel->backlight.max = get_backlight_max_vbt(connector);
if (!panel->backlight.max)
return -ENODEV;
panel->backlight.min = get_backlight_min_vbt(connector);
val = _vlv_get_backlight(dev, pipe);
panel->backlight.level = intel_panel_compute_brightness(connector, val);
panel->backlight.enabled = (ctl2 & BLM_PWM_ENABLE) &&
panel->backlight.level != 0;
return 0;
}
static int
bxt_setup_backlight(struct intel_connector *connector, enum pipe unused)
{
struct drm_device *dev = connector->base.dev;
struct drm_i915_private *dev_priv = dev->dev_private;
struct intel_panel *panel = &connector->panel;
u32 pwm_ctl, val;
panel->backlight.controller = 0;
pwm_ctl = I915_READ(BXT_BLC_PWM_CTL(panel->backlight.controller));
if (panel->backlight.controller == 1) {
val = I915_READ(UTIL_PIN_CTL);
panel->backlight.util_pin_active_low =
val & UTIL_PIN_POLARITY;
}
panel->backlight.active_low_pwm = pwm_ctl & BXT_BLC_PWM_POLARITY;
panel->backlight.max =
I915_READ(BXT_BLC_PWM_FREQ(panel->backlight.controller));
if (!panel->backlight.max)
panel->backlight.max = get_backlight_max_vbt(connector);
if (!panel->backlight.max)
return -ENODEV;
val = bxt_get_backlight(connector);
panel->backlight.level = intel_panel_compute_brightness(connector, val);
panel->backlight.enabled = (pwm_ctl & BXT_BLC_PWM_ENABLE) &&
panel->backlight.level != 0;
return 0;
}
static int pwm_setup_backlight(struct intel_connector *connector,
enum pipe pipe)
{
struct drm_device *dev = connector->base.dev;
struct intel_panel *panel = &connector->panel;
int retval;
panel->backlight.pwm = pwm_get(dev->dev, "pwm_backlight");
if (IS_ERR(panel->backlight.pwm)) {
DRM_ERROR("Failed to own the pwm chip\n");
panel->backlight.pwm = NULL;
return -ENODEV;
}
retval = pwm_config(panel->backlight.pwm, CRC_PMIC_PWM_PERIOD_NS,
CRC_PMIC_PWM_PERIOD_NS);
if (retval < 0) {
DRM_ERROR("Failed to configure the pwm chip\n");
pwm_put(panel->backlight.pwm);
panel->backlight.pwm = NULL;
return retval;
}
panel->backlight.min = 0;
panel->backlight.max = 100;
panel->backlight.level = DIV_ROUND_UP(
pwm_get_duty_cycle(panel->backlight.pwm) * 100,
CRC_PMIC_PWM_PERIOD_NS);
panel->backlight.enabled = panel->backlight.level != 0;
return 0;
}
int intel_panel_setup_backlight(struct drm_connector *connector, enum pipe pipe)
{
struct drm_device *dev = connector->dev;
struct drm_i915_private *dev_priv = dev->dev_private;
struct intel_connector *intel_connector = to_intel_connector(connector);
struct intel_panel *panel = &intel_connector->panel;
int ret;
if (!dev_priv->vbt.backlight.present) {
if (dev_priv->quirks & QUIRK_BACKLIGHT_PRESENT) {
DRM_DEBUG_KMS("no backlight present per VBT, but present per quirk\n");
} else {
DRM_DEBUG_KMS("no backlight present per VBT\n");
return 0;
}
}
if (WARN_ON(!panel->backlight.setup))
return -ENODEV;
mutex_lock(&dev_priv->backlight_lock);
ret = panel->backlight.setup(intel_connector, pipe);
mutex_unlock(&dev_priv->backlight_lock);
if (ret) {
DRM_DEBUG_KMS("failed to setup backlight for connector %s\n",
connector->name);
return ret;
}
panel->backlight.present = true;
DRM_DEBUG_KMS("Connector %s backlight initialized, %s, brightness %u/%u\n",
connector->name,
panel->backlight.enabled ? "enabled" : "disabled",
panel->backlight.level, panel->backlight.max);
return 0;
}
void intel_panel_destroy_backlight(struct drm_connector *connector)
{
struct intel_connector *intel_connector = to_intel_connector(connector);
struct intel_panel *panel = &intel_connector->panel;
if (panel->backlight.pwm)
pwm_put(panel->backlight.pwm);
panel->backlight.present = false;
}
static void
intel_panel_init_backlight_funcs(struct intel_panel *panel)
{
struct intel_connector *intel_connector =
container_of(panel, struct intel_connector, panel);
struct drm_device *dev = intel_connector->base.dev;
struct drm_i915_private *dev_priv = dev->dev_private;
if (IS_BROXTON(dev)) {
panel->backlight.setup = bxt_setup_backlight;
panel->backlight.enable = bxt_enable_backlight;
panel->backlight.disable = bxt_disable_backlight;
panel->backlight.set = bxt_set_backlight;
panel->backlight.get = bxt_get_backlight;
} else if (HAS_PCH_LPT(dev) || HAS_PCH_SPT(dev)) {
panel->backlight.setup = lpt_setup_backlight;
panel->backlight.enable = lpt_enable_backlight;
panel->backlight.disable = lpt_disable_backlight;
panel->backlight.set = lpt_set_backlight;
panel->backlight.get = lpt_get_backlight;
if (HAS_PCH_LPT(dev))
panel->backlight.hz_to_pwm = lpt_hz_to_pwm;
else
panel->backlight.hz_to_pwm = spt_hz_to_pwm;
} else if (HAS_PCH_SPLIT(dev)) {
panel->backlight.setup = pch_setup_backlight;
panel->backlight.enable = pch_enable_backlight;
panel->backlight.disable = pch_disable_backlight;
panel->backlight.set = pch_set_backlight;
panel->backlight.get = pch_get_backlight;
panel->backlight.hz_to_pwm = pch_hz_to_pwm;
} else if (IS_VALLEYVIEW(dev)) {
if (dev_priv->vbt.has_mipi) {
panel->backlight.setup = pwm_setup_backlight;
panel->backlight.enable = pwm_enable_backlight;
panel->backlight.disable = pwm_disable_backlight;
panel->backlight.set = pwm_set_backlight;
panel->backlight.get = pwm_get_backlight;
} else {
panel->backlight.setup = vlv_setup_backlight;
panel->backlight.enable = vlv_enable_backlight;
panel->backlight.disable = vlv_disable_backlight;
panel->backlight.set = vlv_set_backlight;
panel->backlight.get = vlv_get_backlight;
panel->backlight.hz_to_pwm = vlv_hz_to_pwm;
}
} else if (IS_GEN4(dev)) {
panel->backlight.setup = i965_setup_backlight;
panel->backlight.enable = i965_enable_backlight;
panel->backlight.disable = i965_disable_backlight;
panel->backlight.set = i9xx_set_backlight;
panel->backlight.get = i9xx_get_backlight;
panel->backlight.hz_to_pwm = i965_hz_to_pwm;
} else {
panel->backlight.setup = i9xx_setup_backlight;
panel->backlight.enable = i9xx_enable_backlight;
panel->backlight.disable = i9xx_disable_backlight;
panel->backlight.set = i9xx_set_backlight;
panel->backlight.get = i9xx_get_backlight;
panel->backlight.hz_to_pwm = i9xx_hz_to_pwm;
}
}
int intel_panel_init(struct intel_panel *panel,
struct drm_display_mode *fixed_mode,
struct drm_display_mode *downclock_mode)
{
intel_panel_init_backlight_funcs(panel);
panel->fixed_mode = fixed_mode;
panel->downclock_mode = downclock_mode;
return 0;
}
void intel_panel_fini(struct intel_panel *panel)
{
struct intel_connector *intel_connector =
container_of(panel, struct intel_connector, panel);
if (panel->fixed_mode)
drm_mode_destroy(intel_connector->base.dev, panel->fixed_mode);
if (panel->downclock_mode)
drm_mode_destroy(intel_connector->base.dev,
panel->downclock_mode);
}
void intel_backlight_register(struct drm_device *dev)
{
struct intel_connector *connector;
list_for_each_entry(connector, &dev->mode_config.connector_list, base.head)
intel_backlight_device_register(connector);
}
void intel_backlight_unregister(struct drm_device *dev)
{
struct intel_connector *connector;
list_for_each_entry(connector, &dev->mode_config.connector_list, base.head)
intel_backlight_device_unregister(connector);
}
