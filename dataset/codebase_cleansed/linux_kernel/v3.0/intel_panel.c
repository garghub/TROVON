void
intel_fixed_panel_mode(struct drm_display_mode *fixed_mode,
struct drm_display_mode *adjusted_mode)
{
adjusted_mode->hdisplay = fixed_mode->hdisplay;
adjusted_mode->hsync_start = fixed_mode->hsync_start;
adjusted_mode->hsync_end = fixed_mode->hsync_end;
adjusted_mode->htotal = fixed_mode->htotal;
adjusted_mode->vdisplay = fixed_mode->vdisplay;
adjusted_mode->vsync_start = fixed_mode->vsync_start;
adjusted_mode->vsync_end = fixed_mode->vsync_end;
adjusted_mode->vtotal = fixed_mode->vtotal;
adjusted_mode->clock = fixed_mode->clock;
drm_mode_set_crtcinfo(adjusted_mode, CRTC_INTERLACE_HALVE_V);
}
void
intel_pch_panel_fitting(struct drm_device *dev,
int fitting_mode,
struct drm_display_mode *mode,
struct drm_display_mode *adjusted_mode)
{
struct drm_i915_private *dev_priv = dev->dev_private;
int x, y, width, height;
x = y = width = height = 0;
if (adjusted_mode->hdisplay == mode->hdisplay &&
adjusted_mode->vdisplay == mode->vdisplay)
goto done;
switch (fitting_mode) {
case DRM_MODE_SCALE_CENTER:
width = mode->hdisplay;
height = mode->vdisplay;
x = (adjusted_mode->hdisplay - width + 1)/2;
y = (adjusted_mode->vdisplay - height + 1)/2;
break;
case DRM_MODE_SCALE_ASPECT:
{
u32 scaled_width = adjusted_mode->hdisplay * mode->vdisplay;
u32 scaled_height = mode->hdisplay * adjusted_mode->vdisplay;
if (scaled_width > scaled_height) {
width = scaled_height / mode->vdisplay;
x = (adjusted_mode->hdisplay - width + 1) / 2;
y = 0;
height = adjusted_mode->vdisplay;
} else if (scaled_width < scaled_height) {
height = scaled_width / mode->hdisplay;
y = (adjusted_mode->vdisplay - height + 1) / 2;
x = 0;
width = adjusted_mode->hdisplay;
} else {
x = y = 0;
width = adjusted_mode->hdisplay;
height = adjusted_mode->vdisplay;
}
}
break;
default:
case DRM_MODE_SCALE_FULLSCREEN:
x = y = 0;
width = adjusted_mode->hdisplay;
height = adjusted_mode->vdisplay;
break;
}
done:
dev_priv->pch_pf_pos = (x << 16) | y;
dev_priv->pch_pf_size = (width << 16) | height;
}
static int is_backlight_combination_mode(struct drm_device *dev)
{
struct drm_i915_private *dev_priv = dev->dev_private;
if (INTEL_INFO(dev)->gen >= 4)
return I915_READ(BLC_PWM_CTL2) & BLM_COMBINATION_MODE;
if (IS_GEN2(dev))
return I915_READ(BLC_PWM_CTL) & BLM_LEGACY_MODE;
return 0;
}
static u32 i915_read_blc_pwm_ctl(struct drm_i915_private *dev_priv)
{
u32 val;
if (HAS_PCH_SPLIT(dev_priv->dev)) {
val = I915_READ(BLC_PWM_PCH_CTL2);
if (dev_priv->saveBLC_PWM_CTL2 == 0) {
dev_priv->saveBLC_PWM_CTL2 = val;
} else if (val == 0) {
I915_WRITE(BLC_PWM_PCH_CTL2,
dev_priv->saveBLC_PWM_CTL);
val = dev_priv->saveBLC_PWM_CTL;
}
} else {
val = I915_READ(BLC_PWM_CTL);
if (dev_priv->saveBLC_PWM_CTL == 0) {
dev_priv->saveBLC_PWM_CTL = val;
dev_priv->saveBLC_PWM_CTL2 = I915_READ(BLC_PWM_CTL2);
} else if (val == 0) {
I915_WRITE(BLC_PWM_CTL,
dev_priv->saveBLC_PWM_CTL);
I915_WRITE(BLC_PWM_CTL2,
dev_priv->saveBLC_PWM_CTL2);
val = dev_priv->saveBLC_PWM_CTL;
}
}
return val;
}
u32 intel_panel_get_max_backlight(struct drm_device *dev)
{
struct drm_i915_private *dev_priv = dev->dev_private;
u32 max;
max = i915_read_blc_pwm_ctl(dev_priv);
if (max == 0) {
printk_once(KERN_WARNING "fixme: max PWM is zero.\n");
return 1;
}
if (HAS_PCH_SPLIT(dev)) {
max >>= 16;
} else {
if (IS_PINEVIEW(dev)) {
max >>= 17;
} else {
max >>= 16;
if (INTEL_INFO(dev)->gen < 4)
max &= ~1;
}
if (is_backlight_combination_mode(dev))
max *= 0xff;
}
DRM_DEBUG_DRIVER("max backlight PWM = %d\n", max);
return max;
}
u32 intel_panel_get_backlight(struct drm_device *dev)
{
struct drm_i915_private *dev_priv = dev->dev_private;
u32 val;
if (HAS_PCH_SPLIT(dev)) {
val = I915_READ(BLC_PWM_CPU_CTL) & BACKLIGHT_DUTY_CYCLE_MASK;
} else {
val = I915_READ(BLC_PWM_CTL) & BACKLIGHT_DUTY_CYCLE_MASK;
if (IS_PINEVIEW(dev))
val >>= 1;
if (is_backlight_combination_mode(dev)){
u8 lbpc;
val &= ~1;
pci_read_config_byte(dev->pdev, PCI_LBPC, &lbpc);
val *= lbpc;
}
}
DRM_DEBUG_DRIVER("get backlight PWM = %d\n", val);
return val;
}
static void intel_pch_panel_set_backlight(struct drm_device *dev, u32 level)
{
struct drm_i915_private *dev_priv = dev->dev_private;
u32 val = I915_READ(BLC_PWM_CPU_CTL) & ~BACKLIGHT_DUTY_CYCLE_MASK;
I915_WRITE(BLC_PWM_CPU_CTL, val | level);
}
void intel_panel_set_backlight(struct drm_device *dev, u32 level)
{
struct drm_i915_private *dev_priv = dev->dev_private;
u32 tmp;
DRM_DEBUG_DRIVER("set backlight PWM = %d\n", level);
if (HAS_PCH_SPLIT(dev))
return intel_pch_panel_set_backlight(dev, level);
if (is_backlight_combination_mode(dev)){
u32 max = intel_panel_get_max_backlight(dev);
u8 lbpc;
lbpc = level * 0xfe / max + 1;
level /= lbpc;
pci_write_config_byte(dev->pdev, PCI_LBPC, lbpc);
}
tmp = I915_READ(BLC_PWM_CTL);
if (IS_PINEVIEW(dev)) {
tmp &= ~(BACKLIGHT_DUTY_CYCLE_MASK - 1);
level <<= 1;
} else
tmp &= ~BACKLIGHT_DUTY_CYCLE_MASK;
I915_WRITE(BLC_PWM_CTL, tmp | level);
}
void intel_panel_disable_backlight(struct drm_device *dev)
{
struct drm_i915_private *dev_priv = dev->dev_private;
if (dev_priv->backlight_enabled) {
dev_priv->backlight_level = intel_panel_get_backlight(dev);
dev_priv->backlight_enabled = false;
}
intel_panel_set_backlight(dev, 0);
}
void intel_panel_enable_backlight(struct drm_device *dev)
{
struct drm_i915_private *dev_priv = dev->dev_private;
if (dev_priv->backlight_level == 0)
dev_priv->backlight_level = intel_panel_get_max_backlight(dev);
intel_panel_set_backlight(dev, dev_priv->backlight_level);
dev_priv->backlight_enabled = true;
}
void intel_panel_setup_backlight(struct drm_device *dev)
{
struct drm_i915_private *dev_priv = dev->dev_private;
dev_priv->backlight_level = intel_panel_get_backlight(dev);
dev_priv->backlight_enabled = dev_priv->backlight_level != 0;
}
enum drm_connector_status
intel_panel_detect(struct drm_device *dev)
{
#if 0
struct drm_i915_private *dev_priv = dev->dev_private;
#endif
if (i915_panel_ignore_lid)
return i915_panel_ignore_lid > 0 ?
connector_status_connected :
connector_status_disconnected;
#if 0
if (dev_priv->opregion.lid_state)
return ioread32(dev_priv->opregion.lid_state) & 0x1 ?
connector_status_connected :
connector_status_disconnected;
#endif
return connector_status_unknown;
}
