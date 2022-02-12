static struct intel_dvo *enc_to_intel_dvo(struct drm_encoder *encoder)
{
return container_of(encoder, struct intel_dvo, base.base);
}
static struct intel_dvo *intel_attached_dvo(struct drm_connector *connector)
{
return container_of(intel_attached_encoder(connector),
struct intel_dvo, base);
}
static bool intel_dvo_connector_get_hw_state(struct intel_connector *connector)
{
struct intel_dvo *intel_dvo = intel_attached_dvo(&connector->base);
return intel_dvo->dev.dev_ops->get_hw_state(&intel_dvo->dev);
}
static bool intel_dvo_get_hw_state(struct intel_encoder *encoder,
enum pipe *pipe)
{
struct drm_device *dev = encoder->base.dev;
struct drm_i915_private *dev_priv = dev->dev_private;
struct intel_dvo *intel_dvo = enc_to_intel_dvo(&encoder->base);
u32 tmp;
tmp = I915_READ(intel_dvo->dev.dvo_reg);
if (!(tmp & DVO_ENABLE))
return false;
*pipe = PORT_TO_PIPE(tmp);
return true;
}
static void intel_disable_dvo(struct intel_encoder *encoder)
{
struct drm_i915_private *dev_priv = encoder->base.dev->dev_private;
struct intel_dvo *intel_dvo = enc_to_intel_dvo(&encoder->base);
u32 dvo_reg = intel_dvo->dev.dvo_reg;
u32 temp = I915_READ(dvo_reg);
intel_dvo->dev.dev_ops->dpms(&intel_dvo->dev, false);
I915_WRITE(dvo_reg, temp & ~DVO_ENABLE);
I915_READ(dvo_reg);
}
static void intel_enable_dvo(struct intel_encoder *encoder)
{
struct drm_i915_private *dev_priv = encoder->base.dev->dev_private;
struct intel_dvo *intel_dvo = enc_to_intel_dvo(&encoder->base);
u32 dvo_reg = intel_dvo->dev.dvo_reg;
u32 temp = I915_READ(dvo_reg);
I915_WRITE(dvo_reg, temp | DVO_ENABLE);
I915_READ(dvo_reg);
intel_dvo->dev.dev_ops->dpms(&intel_dvo->dev, true);
}
static void intel_dvo_dpms(struct drm_connector *connector, int mode)
{
struct intel_dvo *intel_dvo = intel_attached_dvo(connector);
struct drm_crtc *crtc;
if (mode != DRM_MODE_DPMS_ON)
mode = DRM_MODE_DPMS_OFF;
if (mode == connector->dpms)
return;
connector->dpms = mode;
crtc = intel_dvo->base.base.crtc;
if (!crtc) {
intel_dvo->base.connectors_active = false;
return;
}
if (mode == DRM_MODE_DPMS_ON) {
intel_dvo->base.connectors_active = true;
intel_crtc_update_dpms(crtc);
intel_dvo->dev.dev_ops->dpms(&intel_dvo->dev, true);
} else {
intel_dvo->dev.dev_ops->dpms(&intel_dvo->dev, false);
intel_dvo->base.connectors_active = false;
intel_crtc_update_dpms(crtc);
}
intel_modeset_check_state(connector->dev);
}
static int intel_dvo_mode_valid(struct drm_connector *connector,
struct drm_display_mode *mode)
{
struct intel_dvo *intel_dvo = intel_attached_dvo(connector);
if (mode->flags & DRM_MODE_FLAG_DBLSCAN)
return MODE_NO_DBLESCAN;
if (intel_dvo->panel_fixed_mode) {
if (mode->hdisplay > intel_dvo->panel_fixed_mode->hdisplay)
return MODE_PANEL;
if (mode->vdisplay > intel_dvo->panel_fixed_mode->vdisplay)
return MODE_PANEL;
}
return intel_dvo->dev.dev_ops->mode_valid(&intel_dvo->dev, mode);
}
static bool intel_dvo_mode_fixup(struct drm_encoder *encoder,
const struct drm_display_mode *mode,
struct drm_display_mode *adjusted_mode)
{
struct intel_dvo *intel_dvo = enc_to_intel_dvo(encoder);
if (intel_dvo->panel_fixed_mode != NULL) {
#define C(x) adjusted_mode->x = intel_dvo->panel_fixed_mode->x
C(hdisplay);
C(hsync_start);
C(hsync_end);
C(htotal);
C(vdisplay);
C(vsync_start);
C(vsync_end);
C(vtotal);
C(clock);
#undef C
}
if (intel_dvo->dev.dev_ops->mode_fixup)
return intel_dvo->dev.dev_ops->mode_fixup(&intel_dvo->dev, mode, adjusted_mode);
return true;
}
static void intel_dvo_mode_set(struct drm_encoder *encoder,
struct drm_display_mode *mode,
struct drm_display_mode *adjusted_mode)
{
struct drm_device *dev = encoder->dev;
struct drm_i915_private *dev_priv = dev->dev_private;
struct intel_crtc *intel_crtc = to_intel_crtc(encoder->crtc);
struct intel_dvo *intel_dvo = enc_to_intel_dvo(encoder);
int pipe = intel_crtc->pipe;
u32 dvo_val;
u32 dvo_reg = intel_dvo->dev.dvo_reg, dvo_srcdim_reg;
int dpll_reg = DPLL(pipe);
switch (dvo_reg) {
case DVOA:
default:
dvo_srcdim_reg = DVOA_SRCDIM;
break;
case DVOB:
dvo_srcdim_reg = DVOB_SRCDIM;
break;
case DVOC:
dvo_srcdim_reg = DVOC_SRCDIM;
break;
}
intel_dvo->dev.dev_ops->mode_set(&intel_dvo->dev, mode, adjusted_mode);
dvo_val = I915_READ(dvo_reg) &
(DVO_PRESERVE_MASK | DVO_DATA_ORDER_GBRG);
dvo_val |= DVO_DATA_ORDER_FP | DVO_BORDER_ENABLE |
DVO_BLANK_ACTIVE_HIGH;
if (pipe == 1)
dvo_val |= DVO_PIPE_B_SELECT;
dvo_val |= DVO_PIPE_STALL;
if (adjusted_mode->flags & DRM_MODE_FLAG_PHSYNC)
dvo_val |= DVO_HSYNC_ACTIVE_HIGH;
if (adjusted_mode->flags & DRM_MODE_FLAG_PVSYNC)
dvo_val |= DVO_VSYNC_ACTIVE_HIGH;
I915_WRITE(dpll_reg, I915_READ(dpll_reg) | DPLL_DVO_HIGH_SPEED);
I915_WRITE(dvo_srcdim_reg,
(adjusted_mode->hdisplay << DVO_SRCDIM_HORIZONTAL_SHIFT) |
(adjusted_mode->vdisplay << DVO_SRCDIM_VERTICAL_SHIFT));
I915_WRITE(dvo_reg, dvo_val);
}
static enum drm_connector_status
intel_dvo_detect(struct drm_connector *connector, bool force)
{
struct intel_dvo *intel_dvo = intel_attached_dvo(connector);
return intel_dvo->dev.dev_ops->detect(&intel_dvo->dev);
}
static int intel_dvo_get_modes(struct drm_connector *connector)
{
struct intel_dvo *intel_dvo = intel_attached_dvo(connector);
struct drm_i915_private *dev_priv = connector->dev->dev_private;
intel_ddc_get_modes(connector,
intel_gmbus_get_adapter(dev_priv, GMBUS_PORT_DPC));
if (!list_empty(&connector->probed_modes))
return 1;
if (intel_dvo->panel_fixed_mode != NULL) {
struct drm_display_mode *mode;
mode = drm_mode_duplicate(connector->dev, intel_dvo->panel_fixed_mode);
if (mode) {
drm_mode_probed_add(connector, mode);
return 1;
}
}
return 0;
}
static void intel_dvo_destroy(struct drm_connector *connector)
{
drm_sysfs_connector_remove(connector);
drm_connector_cleanup(connector);
kfree(connector);
}
static void intel_dvo_enc_destroy(struct drm_encoder *encoder)
{
struct intel_dvo *intel_dvo = enc_to_intel_dvo(encoder);
if (intel_dvo->dev.dev_ops->destroy)
intel_dvo->dev.dev_ops->destroy(&intel_dvo->dev);
kfree(intel_dvo->panel_fixed_mode);
intel_encoder_destroy(encoder);
}
static struct drm_display_mode *
intel_dvo_get_current_mode(struct drm_connector *connector)
{
struct drm_device *dev = connector->dev;
struct drm_i915_private *dev_priv = dev->dev_private;
struct intel_dvo *intel_dvo = intel_attached_dvo(connector);
uint32_t dvo_val = I915_READ(intel_dvo->dev.dvo_reg);
struct drm_display_mode *mode = NULL;
if (dvo_val & DVO_ENABLE) {
struct drm_crtc *crtc;
int pipe = (dvo_val & DVO_PIPE_B_SELECT) ? 1 : 0;
crtc = intel_get_crtc_for_pipe(dev, pipe);
if (crtc) {
mode = intel_crtc_mode_get(dev, crtc);
if (mode) {
mode->type |= DRM_MODE_TYPE_PREFERRED;
if (dvo_val & DVO_HSYNC_ACTIVE_HIGH)
mode->flags |= DRM_MODE_FLAG_PHSYNC;
if (dvo_val & DVO_VSYNC_ACTIVE_HIGH)
mode->flags |= DRM_MODE_FLAG_PVSYNC;
}
}
}
return mode;
}
void intel_dvo_init(struct drm_device *dev)
{
struct drm_i915_private *dev_priv = dev->dev_private;
struct intel_encoder *intel_encoder;
struct intel_dvo *intel_dvo;
struct intel_connector *intel_connector;
int i;
int encoder_type = DRM_MODE_ENCODER_NONE;
intel_dvo = kzalloc(sizeof(struct intel_dvo), GFP_KERNEL);
if (!intel_dvo)
return;
intel_connector = kzalloc(sizeof(struct intel_connector), GFP_KERNEL);
if (!intel_connector) {
kfree(intel_dvo);
return;
}
intel_encoder = &intel_dvo->base;
drm_encoder_init(dev, &intel_encoder->base,
&intel_dvo_enc_funcs, encoder_type);
intel_encoder->disable = intel_disable_dvo;
intel_encoder->enable = intel_enable_dvo;
intel_encoder->get_hw_state = intel_dvo_get_hw_state;
intel_connector->get_hw_state = intel_dvo_connector_get_hw_state;
for (i = 0; i < ARRAY_SIZE(intel_dvo_devices); i++) {
struct drm_connector *connector = &intel_connector->base;
const struct intel_dvo_device *dvo = &intel_dvo_devices[i];
struct i2c_adapter *i2c;
int gpio;
bool dvoinit;
if (intel_gmbus_is_port_valid(dvo->gpio))
gpio = dvo->gpio;
else if (dvo->type == INTEL_DVO_CHIP_LVDS)
gpio = GMBUS_PORT_SSC;
else
gpio = GMBUS_PORT_DPB;
i2c = intel_gmbus_get_adapter(dev_priv, gpio);
intel_dvo->dev = *dvo;
intel_gmbus_force_bit(i2c, true);
dvoinit = dvo->dev_ops->init(&intel_dvo->dev, i2c);
intel_gmbus_force_bit(i2c, false);
if (!dvoinit)
continue;
intel_encoder->type = INTEL_OUTPUT_DVO;
intel_encoder->crtc_mask = (1 << 0) | (1 << 1);
switch (dvo->type) {
case INTEL_DVO_CHIP_TMDS:
intel_encoder->cloneable = true;
drm_connector_init(dev, connector,
&intel_dvo_connector_funcs,
DRM_MODE_CONNECTOR_DVII);
encoder_type = DRM_MODE_ENCODER_TMDS;
break;
case INTEL_DVO_CHIP_LVDS:
intel_encoder->cloneable = false;
drm_connector_init(dev, connector,
&intel_dvo_connector_funcs,
DRM_MODE_CONNECTOR_LVDS);
encoder_type = DRM_MODE_ENCODER_LVDS;
break;
}
drm_connector_helper_add(connector,
&intel_dvo_connector_helper_funcs);
connector->display_info.subpixel_order = SubPixelHorizontalRGB;
connector->interlace_allowed = false;
connector->doublescan_allowed = false;
drm_encoder_helper_add(&intel_encoder->base,
&intel_dvo_helper_funcs);
intel_connector_attach_encoder(intel_connector, intel_encoder);
if (dvo->type == INTEL_DVO_CHIP_LVDS) {
intel_dvo->panel_fixed_mode =
intel_dvo_get_current_mode(connector);
intel_dvo->panel_wants_dither = true;
}
drm_sysfs_connector_add(connector);
return;
}
drm_encoder_cleanup(&intel_encoder->base);
kfree(intel_dvo);
kfree(intel_connector);
}
