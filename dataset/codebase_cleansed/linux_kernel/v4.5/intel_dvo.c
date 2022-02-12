static struct intel_dvo *enc_to_dvo(struct intel_encoder *encoder)
{
return container_of(encoder, struct intel_dvo, base);
}
static struct intel_dvo *intel_attached_dvo(struct drm_connector *connector)
{
return enc_to_dvo(intel_attached_encoder(connector));
}
static bool intel_dvo_connector_get_hw_state(struct intel_connector *connector)
{
struct drm_device *dev = connector->base.dev;
struct drm_i915_private *dev_priv = dev->dev_private;
struct intel_dvo *intel_dvo = intel_attached_dvo(&connector->base);
u32 tmp;
tmp = I915_READ(intel_dvo->dev.dvo_reg);
if (!(tmp & DVO_ENABLE))
return false;
return intel_dvo->dev.dev_ops->get_hw_state(&intel_dvo->dev);
}
static bool intel_dvo_get_hw_state(struct intel_encoder *encoder,
enum pipe *pipe)
{
struct drm_device *dev = encoder->base.dev;
struct drm_i915_private *dev_priv = dev->dev_private;
struct intel_dvo *intel_dvo = enc_to_dvo(encoder);
u32 tmp;
tmp = I915_READ(intel_dvo->dev.dvo_reg);
if (!(tmp & DVO_ENABLE))
return false;
*pipe = PORT_TO_PIPE(tmp);
return true;
}
static void intel_dvo_get_config(struct intel_encoder *encoder,
struct intel_crtc_state *pipe_config)
{
struct drm_i915_private *dev_priv = encoder->base.dev->dev_private;
struct intel_dvo *intel_dvo = enc_to_dvo(encoder);
u32 tmp, flags = 0;
tmp = I915_READ(intel_dvo->dev.dvo_reg);
if (tmp & DVO_HSYNC_ACTIVE_HIGH)
flags |= DRM_MODE_FLAG_PHSYNC;
else
flags |= DRM_MODE_FLAG_NHSYNC;
if (tmp & DVO_VSYNC_ACTIVE_HIGH)
flags |= DRM_MODE_FLAG_PVSYNC;
else
flags |= DRM_MODE_FLAG_NVSYNC;
pipe_config->base.adjusted_mode.flags |= flags;
pipe_config->base.adjusted_mode.crtc_clock = pipe_config->port_clock;
}
static void intel_disable_dvo(struct intel_encoder *encoder)
{
struct drm_i915_private *dev_priv = encoder->base.dev->dev_private;
struct intel_dvo *intel_dvo = enc_to_dvo(encoder);
i915_reg_t dvo_reg = intel_dvo->dev.dvo_reg;
u32 temp = I915_READ(dvo_reg);
intel_dvo->dev.dev_ops->dpms(&intel_dvo->dev, false);
I915_WRITE(dvo_reg, temp & ~DVO_ENABLE);
I915_READ(dvo_reg);
}
static void intel_enable_dvo(struct intel_encoder *encoder)
{
struct drm_i915_private *dev_priv = encoder->base.dev->dev_private;
struct intel_dvo *intel_dvo = enc_to_dvo(encoder);
struct intel_crtc *crtc = to_intel_crtc(encoder->base.crtc);
i915_reg_t dvo_reg = intel_dvo->dev.dvo_reg;
u32 temp = I915_READ(dvo_reg);
intel_dvo->dev.dev_ops->mode_set(&intel_dvo->dev,
&crtc->config->base.mode,
&crtc->config->base.adjusted_mode);
I915_WRITE(dvo_reg, temp | DVO_ENABLE);
I915_READ(dvo_reg);
intel_dvo->dev.dev_ops->dpms(&intel_dvo->dev, true);
}
static enum drm_mode_status
intel_dvo_mode_valid(struct drm_connector *connector,
struct drm_display_mode *mode)
{
struct intel_dvo *intel_dvo = intel_attached_dvo(connector);
const struct drm_display_mode *fixed_mode =
to_intel_connector(connector)->panel.fixed_mode;
int max_dotclk = to_i915(connector->dev)->max_dotclk_freq;
int target_clock = mode->clock;
if (mode->flags & DRM_MODE_FLAG_DBLSCAN)
return MODE_NO_DBLESCAN;
if (fixed_mode) {
if (mode->hdisplay > fixed_mode->hdisplay)
return MODE_PANEL;
if (mode->vdisplay > fixed_mode->vdisplay)
return MODE_PANEL;
target_clock = fixed_mode->clock;
}
if (target_clock > max_dotclk)
return MODE_CLOCK_HIGH;
return intel_dvo->dev.dev_ops->mode_valid(&intel_dvo->dev, mode);
}
static bool intel_dvo_compute_config(struct intel_encoder *encoder,
struct intel_crtc_state *pipe_config)
{
struct intel_dvo *intel_dvo = enc_to_dvo(encoder);
const struct drm_display_mode *fixed_mode =
intel_dvo->attached_connector->panel.fixed_mode;
struct drm_display_mode *adjusted_mode = &pipe_config->base.adjusted_mode;
if (fixed_mode)
intel_fixed_panel_mode(fixed_mode, adjusted_mode);
return true;
}
static void intel_dvo_pre_enable(struct intel_encoder *encoder)
{
struct drm_device *dev = encoder->base.dev;
struct drm_i915_private *dev_priv = dev->dev_private;
struct intel_crtc *crtc = to_intel_crtc(encoder->base.crtc);
const struct drm_display_mode *adjusted_mode = &crtc->config->base.adjusted_mode;
struct intel_dvo *intel_dvo = enc_to_dvo(encoder);
int pipe = crtc->pipe;
u32 dvo_val;
i915_reg_t dvo_reg = intel_dvo->dev.dvo_reg;
i915_reg_t dvo_srcdim_reg = intel_dvo->dev.dvo_srcdim_reg;
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
I915_WRITE(dvo_srcdim_reg,
(adjusted_mode->crtc_hdisplay << DVO_SRCDIM_HORIZONTAL_SHIFT) |
(adjusted_mode->crtc_vdisplay << DVO_SRCDIM_VERTICAL_SHIFT));
I915_WRITE(dvo_reg, dvo_val);
}
static enum drm_connector_status
intel_dvo_detect(struct drm_connector *connector, bool force)
{
struct intel_dvo *intel_dvo = intel_attached_dvo(connector);
DRM_DEBUG_KMS("[CONNECTOR:%d:%s]\n",
connector->base.id, connector->name);
return intel_dvo->dev.dev_ops->detect(&intel_dvo->dev);
}
static int intel_dvo_get_modes(struct drm_connector *connector)
{
struct drm_i915_private *dev_priv = connector->dev->dev_private;
const struct drm_display_mode *fixed_mode =
to_intel_connector(connector)->panel.fixed_mode;
intel_ddc_get_modes(connector,
intel_gmbus_get_adapter(dev_priv, GMBUS_PIN_DPC));
if (!list_empty(&connector->probed_modes))
return 1;
if (fixed_mode) {
struct drm_display_mode *mode;
mode = drm_mode_duplicate(connector->dev, fixed_mode);
if (mode) {
drm_mode_probed_add(connector, mode);
return 1;
}
}
return 0;
}
static void intel_dvo_destroy(struct drm_connector *connector)
{
drm_connector_cleanup(connector);
intel_panel_fini(&to_intel_connector(connector)->panel);
kfree(connector);
}
static void intel_dvo_enc_destroy(struct drm_encoder *encoder)
{
struct intel_dvo *intel_dvo = enc_to_dvo(to_intel_encoder(encoder));
if (intel_dvo->dev.dev_ops->destroy)
intel_dvo->dev.dev_ops->destroy(&intel_dvo->dev);
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
intel_dvo = kzalloc(sizeof(*intel_dvo), GFP_KERNEL);
if (!intel_dvo)
return;
intel_connector = intel_connector_alloc();
if (!intel_connector) {
kfree(intel_dvo);
return;
}
intel_dvo->attached_connector = intel_connector;
intel_encoder = &intel_dvo->base;
drm_encoder_init(dev, &intel_encoder->base,
&intel_dvo_enc_funcs, encoder_type, NULL);
intel_encoder->disable = intel_disable_dvo;
intel_encoder->enable = intel_enable_dvo;
intel_encoder->get_hw_state = intel_dvo_get_hw_state;
intel_encoder->get_config = intel_dvo_get_config;
intel_encoder->compute_config = intel_dvo_compute_config;
intel_encoder->pre_enable = intel_dvo_pre_enable;
intel_connector->get_hw_state = intel_dvo_connector_get_hw_state;
intel_connector->unregister = intel_connector_unregister;
for (i = 0; i < ARRAY_SIZE(intel_dvo_devices); i++) {
struct drm_connector *connector = &intel_connector->base;
const struct intel_dvo_device *dvo = &intel_dvo_devices[i];
struct i2c_adapter *i2c;
int gpio;
bool dvoinit;
enum pipe pipe;
uint32_t dpll[I915_MAX_PIPES];
if (intel_gmbus_is_valid_pin(dev_priv, dvo->gpio))
gpio = dvo->gpio;
else if (dvo->type == INTEL_DVO_CHIP_LVDS)
gpio = GMBUS_PIN_SSC;
else
gpio = GMBUS_PIN_DPB;
i2c = intel_gmbus_get_adapter(dev_priv, gpio);
intel_dvo->dev = *dvo;
intel_gmbus_force_bit(i2c, true);
for_each_pipe(dev_priv, pipe) {
dpll[pipe] = I915_READ(DPLL(pipe));
I915_WRITE(DPLL(pipe), dpll[pipe] | DPLL_DVO_2X_MODE);
}
dvoinit = dvo->dev_ops->init(&intel_dvo->dev, i2c);
for_each_pipe(dev_priv, pipe) {
I915_WRITE(DPLL(pipe), dpll[pipe]);
}
intel_gmbus_force_bit(i2c, false);
if (!dvoinit)
continue;
intel_encoder->type = INTEL_OUTPUT_DVO;
intel_encoder->crtc_mask = (1 << 0) | (1 << 1);
switch (dvo->type) {
case INTEL_DVO_CHIP_TMDS:
intel_encoder->cloneable = (1 << INTEL_OUTPUT_ANALOG) |
(1 << INTEL_OUTPUT_DVO);
drm_connector_init(dev, connector,
&intel_dvo_connector_funcs,
DRM_MODE_CONNECTOR_DVII);
encoder_type = DRM_MODE_ENCODER_TMDS;
break;
case INTEL_DVO_CHIP_LVDS:
intel_encoder->cloneable = 0;
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
intel_connector_attach_encoder(intel_connector, intel_encoder);
if (dvo->type == INTEL_DVO_CHIP_LVDS) {
intel_panel_init(&intel_connector->panel,
intel_dvo_get_current_mode(connector),
NULL);
intel_dvo->panel_wants_dither = true;
}
drm_connector_register(connector);
return;
}
drm_encoder_cleanup(&intel_encoder->base);
kfree(intel_dvo);
kfree(intel_connector);
}
