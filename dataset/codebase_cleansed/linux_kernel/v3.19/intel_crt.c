static struct intel_crt *intel_encoder_to_crt(struct intel_encoder *encoder)
{
return container_of(encoder, struct intel_crt, base);
}
static struct intel_crt *intel_attached_crt(struct drm_connector *connector)
{
return intel_encoder_to_crt(intel_attached_encoder(connector));
}
static bool intel_crt_get_hw_state(struct intel_encoder *encoder,
enum pipe *pipe)
{
struct drm_device *dev = encoder->base.dev;
struct drm_i915_private *dev_priv = dev->dev_private;
struct intel_crt *crt = intel_encoder_to_crt(encoder);
enum intel_display_power_domain power_domain;
u32 tmp;
power_domain = intel_display_port_power_domain(encoder);
if (!intel_display_power_is_enabled(dev_priv, power_domain))
return false;
tmp = I915_READ(crt->adpa_reg);
if (!(tmp & ADPA_DAC_ENABLE))
return false;
if (HAS_PCH_CPT(dev))
*pipe = PORT_TO_PIPE_CPT(tmp);
else
*pipe = PORT_TO_PIPE(tmp);
return true;
}
static unsigned int intel_crt_get_flags(struct intel_encoder *encoder)
{
struct drm_i915_private *dev_priv = encoder->base.dev->dev_private;
struct intel_crt *crt = intel_encoder_to_crt(encoder);
u32 tmp, flags = 0;
tmp = I915_READ(crt->adpa_reg);
if (tmp & ADPA_HSYNC_ACTIVE_HIGH)
flags |= DRM_MODE_FLAG_PHSYNC;
else
flags |= DRM_MODE_FLAG_NHSYNC;
if (tmp & ADPA_VSYNC_ACTIVE_HIGH)
flags |= DRM_MODE_FLAG_PVSYNC;
else
flags |= DRM_MODE_FLAG_NVSYNC;
return flags;
}
static void intel_crt_get_config(struct intel_encoder *encoder,
struct intel_crtc_config *pipe_config)
{
struct drm_device *dev = encoder->base.dev;
int dotclock;
pipe_config->adjusted_mode.flags |= intel_crt_get_flags(encoder);
dotclock = pipe_config->port_clock;
if (HAS_PCH_SPLIT(dev))
ironlake_check_encoder_dotclock(pipe_config, dotclock);
pipe_config->adjusted_mode.crtc_clock = dotclock;
}
static void hsw_crt_get_config(struct intel_encoder *encoder,
struct intel_crtc_config *pipe_config)
{
intel_ddi_get_config(encoder, pipe_config);
pipe_config->adjusted_mode.flags &= ~(DRM_MODE_FLAG_PHSYNC |
DRM_MODE_FLAG_NHSYNC |
DRM_MODE_FLAG_PVSYNC |
DRM_MODE_FLAG_NVSYNC);
pipe_config->adjusted_mode.flags |= intel_crt_get_flags(encoder);
}
static void hsw_crt_pre_enable(struct intel_encoder *encoder)
{
struct drm_device *dev = encoder->base.dev;
struct drm_i915_private *dev_priv = dev->dev_private;
WARN(I915_READ(SPLL_CTL) & SPLL_PLL_ENABLE, "SPLL already enabled\n");
I915_WRITE(SPLL_CTL,
SPLL_PLL_ENABLE | SPLL_PLL_FREQ_1350MHz | SPLL_PLL_SSC);
POSTING_READ(SPLL_CTL);
udelay(20);
}
static void intel_crt_set_dpms(struct intel_encoder *encoder, int mode)
{
struct drm_device *dev = encoder->base.dev;
struct drm_i915_private *dev_priv = dev->dev_private;
struct intel_crt *crt = intel_encoder_to_crt(encoder);
struct intel_crtc *crtc = to_intel_crtc(encoder->base.crtc);
struct drm_display_mode *adjusted_mode = &crtc->config.adjusted_mode;
u32 adpa;
if (INTEL_INFO(dev)->gen >= 5)
adpa = ADPA_HOTPLUG_BITS;
else
adpa = 0;
if (adjusted_mode->flags & DRM_MODE_FLAG_PHSYNC)
adpa |= ADPA_HSYNC_ACTIVE_HIGH;
if (adjusted_mode->flags & DRM_MODE_FLAG_PVSYNC)
adpa |= ADPA_VSYNC_ACTIVE_HIGH;
if (HAS_PCH_LPT(dev))
;
else if (HAS_PCH_CPT(dev))
adpa |= PORT_TRANS_SEL_CPT(crtc->pipe);
else if (crtc->pipe == 0)
adpa |= ADPA_PIPE_A_SELECT;
else
adpa |= ADPA_PIPE_B_SELECT;
if (!HAS_PCH_SPLIT(dev))
I915_WRITE(BCLRPAT(crtc->pipe), 0);
switch (mode) {
case DRM_MODE_DPMS_ON:
adpa |= ADPA_DAC_ENABLE;
break;
case DRM_MODE_DPMS_STANDBY:
adpa |= ADPA_DAC_ENABLE | ADPA_HSYNC_CNTL_DISABLE;
break;
case DRM_MODE_DPMS_SUSPEND:
adpa |= ADPA_DAC_ENABLE | ADPA_VSYNC_CNTL_DISABLE;
break;
case DRM_MODE_DPMS_OFF:
adpa |= ADPA_HSYNC_CNTL_DISABLE | ADPA_VSYNC_CNTL_DISABLE;
break;
}
I915_WRITE(crt->adpa_reg, adpa);
}
static void intel_disable_crt(struct intel_encoder *encoder)
{
intel_crt_set_dpms(encoder, DRM_MODE_DPMS_OFF);
}
static void hsw_crt_post_disable(struct intel_encoder *encoder)
{
struct drm_device *dev = encoder->base.dev;
struct drm_i915_private *dev_priv = dev->dev_private;
uint32_t val;
DRM_DEBUG_KMS("Disabling SPLL\n");
val = I915_READ(SPLL_CTL);
WARN_ON(!(val & SPLL_PLL_ENABLE));
I915_WRITE(SPLL_CTL, val & ~SPLL_PLL_ENABLE);
POSTING_READ(SPLL_CTL);
}
static void intel_enable_crt(struct intel_encoder *encoder)
{
struct intel_crt *crt = intel_encoder_to_crt(encoder);
intel_crt_set_dpms(encoder, crt->connector->base.dpms);
}
static void intel_crt_dpms(struct drm_connector *connector, int mode)
{
struct drm_device *dev = connector->dev;
struct intel_encoder *encoder = intel_attached_encoder(connector);
struct drm_crtc *crtc;
int old_dpms;
if (INTEL_INFO(dev)->gen >= 5 && mode != DRM_MODE_DPMS_ON)
mode = DRM_MODE_DPMS_OFF;
if (mode == connector->dpms)
return;
old_dpms = connector->dpms;
connector->dpms = mode;
crtc = encoder->base.crtc;
if (!crtc) {
encoder->connectors_active = false;
return;
}
if (mode == DRM_MODE_DPMS_OFF)
encoder->connectors_active = false;
else
encoder->connectors_active = true;
if (mode < old_dpms) {
intel_crtc_update_dpms(crtc);
intel_crt_set_dpms(encoder, mode);
} else {
intel_crt_set_dpms(encoder, mode);
intel_crtc_update_dpms(crtc);
}
intel_modeset_check_state(connector->dev);
}
static enum drm_mode_status
intel_crt_mode_valid(struct drm_connector *connector,
struct drm_display_mode *mode)
{
struct drm_device *dev = connector->dev;
int max_clock = 0;
if (mode->flags & DRM_MODE_FLAG_DBLSCAN)
return MODE_NO_DBLESCAN;
if (mode->clock < 25000)
return MODE_CLOCK_LOW;
if (IS_GEN2(dev))
max_clock = 350000;
else
max_clock = 400000;
if (mode->clock > max_clock)
return MODE_CLOCK_HIGH;
if (HAS_PCH_LPT(dev) &&
(ironlake_get_lanes_required(mode->clock, 270000, 24) > 2))
return MODE_CLOCK_HIGH;
return MODE_OK;
}
static bool intel_crt_compute_config(struct intel_encoder *encoder,
struct intel_crtc_config *pipe_config)
{
struct drm_device *dev = encoder->base.dev;
if (HAS_PCH_SPLIT(dev))
pipe_config->has_pch_encoder = true;
if (HAS_PCH_LPT(dev))
pipe_config->pipe_bpp = 24;
if (HAS_DDI(dev)) {
pipe_config->ddi_pll_sel = PORT_CLK_SEL_SPLL;
pipe_config->port_clock = 135000 * 2;
}
return true;
}
static bool intel_ironlake_crt_detect_hotplug(struct drm_connector *connector)
{
struct drm_device *dev = connector->dev;
struct intel_crt *crt = intel_attached_crt(connector);
struct drm_i915_private *dev_priv = dev->dev_private;
u32 adpa;
bool ret;
if (crt->force_hotplug_required) {
bool turn_off_dac = HAS_PCH_SPLIT(dev);
u32 save_adpa;
crt->force_hotplug_required = 0;
save_adpa = adpa = I915_READ(crt->adpa_reg);
DRM_DEBUG_KMS("trigger hotplug detect cycle: adpa=0x%x\n", adpa);
adpa |= ADPA_CRT_HOTPLUG_FORCE_TRIGGER;
if (turn_off_dac)
adpa &= ~ADPA_DAC_ENABLE;
I915_WRITE(crt->adpa_reg, adpa);
if (wait_for((I915_READ(crt->adpa_reg) & ADPA_CRT_HOTPLUG_FORCE_TRIGGER) == 0,
1000))
DRM_DEBUG_KMS("timed out waiting for FORCE_TRIGGER");
if (turn_off_dac) {
I915_WRITE(crt->adpa_reg, save_adpa);
POSTING_READ(crt->adpa_reg);
}
}
adpa = I915_READ(crt->adpa_reg);
if ((adpa & ADPA_CRT_HOTPLUG_MONITOR_MASK) != 0)
ret = true;
else
ret = false;
DRM_DEBUG_KMS("ironlake hotplug adpa=0x%x, result %d\n", adpa, ret);
return ret;
}
static bool valleyview_crt_detect_hotplug(struct drm_connector *connector)
{
struct drm_device *dev = connector->dev;
struct intel_crt *crt = intel_attached_crt(connector);
struct drm_i915_private *dev_priv = dev->dev_private;
u32 adpa;
bool ret;
u32 save_adpa;
save_adpa = adpa = I915_READ(crt->adpa_reg);
DRM_DEBUG_KMS("trigger hotplug detect cycle: adpa=0x%x\n", adpa);
adpa |= ADPA_CRT_HOTPLUG_FORCE_TRIGGER;
I915_WRITE(crt->adpa_reg, adpa);
if (wait_for((I915_READ(crt->adpa_reg) & ADPA_CRT_HOTPLUG_FORCE_TRIGGER) == 0,
1000)) {
DRM_DEBUG_KMS("timed out waiting for FORCE_TRIGGER");
I915_WRITE(crt->adpa_reg, save_adpa);
}
adpa = I915_READ(crt->adpa_reg);
if ((adpa & ADPA_CRT_HOTPLUG_MONITOR_MASK) != 0)
ret = true;
else
ret = false;
DRM_DEBUG_KMS("valleyview hotplug adpa=0x%x, result %d\n", adpa, ret);
return ret;
}
static bool intel_crt_detect_hotplug(struct drm_connector *connector)
{
struct drm_device *dev = connector->dev;
struct drm_i915_private *dev_priv = dev->dev_private;
u32 hotplug_en, orig, stat;
bool ret = false;
int i, tries = 0;
if (HAS_PCH_SPLIT(dev))
return intel_ironlake_crt_detect_hotplug(connector);
if (IS_VALLEYVIEW(dev))
return valleyview_crt_detect_hotplug(connector);
if (IS_G4X(dev) && !IS_GM45(dev))
tries = 2;
else
tries = 1;
hotplug_en = orig = I915_READ(PORT_HOTPLUG_EN);
hotplug_en |= CRT_HOTPLUG_FORCE_DETECT;
for (i = 0; i < tries ; i++) {
I915_WRITE(PORT_HOTPLUG_EN, hotplug_en);
if (wait_for((I915_READ(PORT_HOTPLUG_EN) &
CRT_HOTPLUG_FORCE_DETECT) == 0,
1000))
DRM_DEBUG_KMS("timed out waiting for FORCE_DETECT to go off");
}
stat = I915_READ(PORT_HOTPLUG_STAT);
if ((stat & CRT_HOTPLUG_MONITOR_MASK) != CRT_HOTPLUG_MONITOR_NONE)
ret = true;
I915_WRITE(PORT_HOTPLUG_STAT, CRT_HOTPLUG_INT_STATUS);
I915_WRITE(PORT_HOTPLUG_EN, orig);
return ret;
}
static struct edid *intel_crt_get_edid(struct drm_connector *connector,
struct i2c_adapter *i2c)
{
struct edid *edid;
edid = drm_get_edid(connector, i2c);
if (!edid && !intel_gmbus_is_forced_bit(i2c)) {
DRM_DEBUG_KMS("CRT GMBUS EDID read failed, retry using GPIO bit-banging\n");
intel_gmbus_force_bit(i2c, true);
edid = drm_get_edid(connector, i2c);
intel_gmbus_force_bit(i2c, false);
}
return edid;
}
static int intel_crt_ddc_get_modes(struct drm_connector *connector,
struct i2c_adapter *adapter)
{
struct edid *edid;
int ret;
edid = intel_crt_get_edid(connector, adapter);
if (!edid)
return 0;
ret = intel_connector_update_modes(connector, edid);
kfree(edid);
return ret;
}
static bool intel_crt_detect_ddc(struct drm_connector *connector)
{
struct intel_crt *crt = intel_attached_crt(connector);
struct drm_i915_private *dev_priv = crt->base.base.dev->dev_private;
struct edid *edid;
struct i2c_adapter *i2c;
BUG_ON(crt->base.type != INTEL_OUTPUT_ANALOG);
i2c = intel_gmbus_get_adapter(dev_priv, dev_priv->vbt.crt_ddc_pin);
edid = intel_crt_get_edid(connector, i2c);
if (edid) {
bool is_digital = edid->input & DRM_EDID_INPUT_DIGITAL;
if (!is_digital) {
DRM_DEBUG_KMS("CRT detected via DDC:0x50 [EDID]\n");
return true;
}
DRM_DEBUG_KMS("CRT not detected via DDC:0x50 [EDID reports a digital panel]\n");
} else {
DRM_DEBUG_KMS("CRT not detected via DDC:0x50 [no valid EDID found]\n");
}
kfree(edid);
return false;
}
static enum drm_connector_status
intel_crt_load_detect(struct intel_crt *crt)
{
struct drm_device *dev = crt->base.base.dev;
struct drm_i915_private *dev_priv = dev->dev_private;
uint32_t pipe = to_intel_crtc(crt->base.base.crtc)->pipe;
uint32_t save_bclrpat;
uint32_t save_vtotal;
uint32_t vtotal, vactive;
uint32_t vsample;
uint32_t vblank, vblank_start, vblank_end;
uint32_t dsl;
uint32_t bclrpat_reg;
uint32_t vtotal_reg;
uint32_t vblank_reg;
uint32_t vsync_reg;
uint32_t pipeconf_reg;
uint32_t pipe_dsl_reg;
uint8_t st00;
enum drm_connector_status status;
DRM_DEBUG_KMS("starting load-detect on CRT\n");
bclrpat_reg = BCLRPAT(pipe);
vtotal_reg = VTOTAL(pipe);
vblank_reg = VBLANK(pipe);
vsync_reg = VSYNC(pipe);
pipeconf_reg = PIPECONF(pipe);
pipe_dsl_reg = PIPEDSL(pipe);
save_bclrpat = I915_READ(bclrpat_reg);
save_vtotal = I915_READ(vtotal_reg);
vblank = I915_READ(vblank_reg);
vtotal = ((save_vtotal >> 16) & 0xfff) + 1;
vactive = (save_vtotal & 0x7ff) + 1;
vblank_start = (vblank & 0xfff) + 1;
vblank_end = ((vblank >> 16) & 0xfff) + 1;
I915_WRITE(bclrpat_reg, 0x500050);
if (!IS_GEN2(dev)) {
uint32_t pipeconf = I915_READ(pipeconf_reg);
I915_WRITE(pipeconf_reg, pipeconf | PIPECONF_FORCE_BORDER);
POSTING_READ(pipeconf_reg);
intel_wait_for_vblank(dev, pipe);
st00 = I915_READ8(VGA_MSR_WRITE);
status = ((st00 & (1 << 4)) != 0) ?
connector_status_connected :
connector_status_disconnected;
I915_WRITE(pipeconf_reg, pipeconf);
} else {
bool restore_vblank = false;
int count, detect;
if (vblank_start <= vactive && vblank_end >= vtotal) {
uint32_t vsync = I915_READ(vsync_reg);
uint32_t vsync_start = (vsync & 0xffff) + 1;
vblank_start = vsync_start;
I915_WRITE(vblank_reg,
(vblank_start - 1) |
((vblank_end - 1) << 16));
restore_vblank = true;
}
if (vblank_start - vactive >= vtotal - vblank_end)
vsample = (vblank_start + vactive) >> 1;
else
vsample = (vtotal + vblank_end) >> 1;
while (I915_READ(pipe_dsl_reg) >= vactive)
;
while ((dsl = I915_READ(pipe_dsl_reg)) <= vsample)
;
detect = 0;
count = 0;
do {
count++;
st00 = I915_READ8(VGA_MSR_WRITE);
if (st00 & (1 << 4))
detect++;
} while ((I915_READ(pipe_dsl_reg) == dsl));
if (restore_vblank)
I915_WRITE(vblank_reg, vblank);
status = detect * 4 > count * 3 ?
connector_status_connected :
connector_status_disconnected;
}
I915_WRITE(bclrpat_reg, save_bclrpat);
return status;
}
static enum drm_connector_status
intel_crt_detect(struct drm_connector *connector, bool force)
{
struct drm_device *dev = connector->dev;
struct drm_i915_private *dev_priv = dev->dev_private;
struct intel_crt *crt = intel_attached_crt(connector);
struct intel_encoder *intel_encoder = &crt->base;
enum intel_display_power_domain power_domain;
enum drm_connector_status status;
struct intel_load_detect_pipe tmp;
struct drm_modeset_acquire_ctx ctx;
DRM_DEBUG_KMS("[CONNECTOR:%d:%s] force=%d\n",
connector->base.id, connector->name,
force);
power_domain = intel_display_port_power_domain(intel_encoder);
intel_display_power_get(dev_priv, power_domain);
if (I915_HAS_HOTPLUG(dev)) {
if (intel_crt_detect_hotplug(connector)) {
DRM_DEBUG_KMS("CRT detected via hotplug\n");
status = connector_status_connected;
goto out;
} else
DRM_DEBUG_KMS("CRT not detected via hotplug\n");
}
if (intel_crt_detect_ddc(connector)) {
status = connector_status_connected;
goto out;
}
if (I915_HAS_HOTPLUG(dev)) {
status = connector_status_disconnected;
goto out;
}
if (!force) {
status = connector->status;
goto out;
}
drm_modeset_acquire_init(&ctx, 0);
if (intel_get_load_detect_pipe(connector, NULL, &tmp, &ctx)) {
if (intel_crt_detect_ddc(connector))
status = connector_status_connected;
else
status = intel_crt_load_detect(crt);
intel_release_load_detect_pipe(connector, &tmp);
} else
status = connector_status_unknown;
drm_modeset_drop_locks(&ctx);
drm_modeset_acquire_fini(&ctx);
out:
intel_display_power_put(dev_priv, power_domain);
return status;
}
static void intel_crt_destroy(struct drm_connector *connector)
{
drm_connector_cleanup(connector);
kfree(connector);
}
static int intel_crt_get_modes(struct drm_connector *connector)
{
struct drm_device *dev = connector->dev;
struct drm_i915_private *dev_priv = dev->dev_private;
struct intel_crt *crt = intel_attached_crt(connector);
struct intel_encoder *intel_encoder = &crt->base;
enum intel_display_power_domain power_domain;
int ret;
struct i2c_adapter *i2c;
power_domain = intel_display_port_power_domain(intel_encoder);
intel_display_power_get(dev_priv, power_domain);
i2c = intel_gmbus_get_adapter(dev_priv, dev_priv->vbt.crt_ddc_pin);
ret = intel_crt_ddc_get_modes(connector, i2c);
if (ret || !IS_G4X(dev))
goto out;
i2c = intel_gmbus_get_adapter(dev_priv, GMBUS_PORT_DPB);
ret = intel_crt_ddc_get_modes(connector, i2c);
out:
intel_display_power_put(dev_priv, power_domain);
return ret;
}
static int intel_crt_set_property(struct drm_connector *connector,
struct drm_property *property,
uint64_t value)
{
return 0;
}
static void intel_crt_reset(struct drm_connector *connector)
{
struct drm_device *dev = connector->dev;
struct drm_i915_private *dev_priv = dev->dev_private;
struct intel_crt *crt = intel_attached_crt(connector);
if (INTEL_INFO(dev)->gen >= 5) {
u32 adpa;
adpa = I915_READ(crt->adpa_reg);
adpa &= ~ADPA_CRT_HOTPLUG_MASK;
adpa |= ADPA_HOTPLUG_BITS;
I915_WRITE(crt->adpa_reg, adpa);
POSTING_READ(crt->adpa_reg);
DRM_DEBUG_KMS("crt adpa set to 0x%x\n", adpa);
crt->force_hotplug_required = 1;
}
}
static int intel_no_crt_dmi_callback(const struct dmi_system_id *id)
{
DRM_INFO("Skipping CRT initialization for %s\n", id->ident);
return 1;
}
void intel_crt_init(struct drm_device *dev)
{
struct drm_connector *connector;
struct intel_crt *crt;
struct intel_connector *intel_connector;
struct drm_i915_private *dev_priv = dev->dev_private;
if (dmi_check_system(intel_no_crt))
return;
crt = kzalloc(sizeof(struct intel_crt), GFP_KERNEL);
if (!crt)
return;
intel_connector = kzalloc(sizeof(*intel_connector), GFP_KERNEL);
if (!intel_connector) {
kfree(crt);
return;
}
connector = &intel_connector->base;
crt->connector = intel_connector;
drm_connector_init(dev, &intel_connector->base,
&intel_crt_connector_funcs, DRM_MODE_CONNECTOR_VGA);
drm_encoder_init(dev, &crt->base.base, &intel_crt_enc_funcs,
DRM_MODE_ENCODER_DAC);
intel_connector_attach_encoder(intel_connector, &crt->base);
crt->base.type = INTEL_OUTPUT_ANALOG;
crt->base.cloneable = (1 << INTEL_OUTPUT_DVO) | (1 << INTEL_OUTPUT_HDMI);
if (IS_I830(dev))
crt->base.crtc_mask = (1 << 0);
else
crt->base.crtc_mask = (1 << 0) | (1 << 1) | (1 << 2);
if (IS_GEN2(dev))
connector->interlace_allowed = 0;
else
connector->interlace_allowed = 1;
connector->doublescan_allowed = 0;
if (HAS_PCH_SPLIT(dev))
crt->adpa_reg = PCH_ADPA;
else if (IS_VALLEYVIEW(dev))
crt->adpa_reg = VLV_ADPA;
else
crt->adpa_reg = ADPA;
crt->base.compute_config = intel_crt_compute_config;
crt->base.disable = intel_disable_crt;
crt->base.enable = intel_enable_crt;
if (I915_HAS_HOTPLUG(dev))
crt->base.hpd_pin = HPD_CRT;
if (HAS_DDI(dev)) {
crt->base.get_config = hsw_crt_get_config;
crt->base.get_hw_state = intel_ddi_get_hw_state;
crt->base.pre_enable = hsw_crt_pre_enable;
crt->base.post_disable = hsw_crt_post_disable;
} else {
crt->base.get_config = intel_crt_get_config;
crt->base.get_hw_state = intel_crt_get_hw_state;
}
intel_connector->get_hw_state = intel_connector_get_hw_state;
intel_connector->unregister = intel_connector_unregister;
drm_connector_helper_add(connector, &intel_crt_connector_helper_funcs);
drm_connector_register(connector);
if (!I915_HAS_HOTPLUG(dev))
intel_connector->polled = DRM_CONNECTOR_POLL_CONNECT;
crt->force_hotplug_required = 0;
if (HAS_PCH_LPT(dev)) {
u32 fdi_config = FDI_RX_POLARITY_REVERSED_LPT |
FDI_RX_LINK_REVERSAL_OVERRIDE;
dev_priv->fdi_rx_config = I915_READ(_FDI_RXA_CTL) & fdi_config;
}
intel_crt_reset(connector);
}
