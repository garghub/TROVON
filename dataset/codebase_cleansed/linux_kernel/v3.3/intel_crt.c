static struct intel_crt *intel_attached_crt(struct drm_connector *connector)
{
return container_of(intel_attached_encoder(connector),
struct intel_crt, base);
}
static void intel_crt_dpms(struct drm_encoder *encoder, int mode)
{
struct drm_device *dev = encoder->dev;
struct drm_i915_private *dev_priv = dev->dev_private;
u32 temp, reg;
if (HAS_PCH_SPLIT(dev))
reg = PCH_ADPA;
else
reg = ADPA;
temp = I915_READ(reg);
temp &= ~(ADPA_HSYNC_CNTL_DISABLE | ADPA_VSYNC_CNTL_DISABLE);
temp &= ~ADPA_DAC_ENABLE;
switch (mode) {
case DRM_MODE_DPMS_ON:
temp |= ADPA_DAC_ENABLE;
break;
case DRM_MODE_DPMS_STANDBY:
temp |= ADPA_DAC_ENABLE | ADPA_HSYNC_CNTL_DISABLE;
break;
case DRM_MODE_DPMS_SUSPEND:
temp |= ADPA_DAC_ENABLE | ADPA_VSYNC_CNTL_DISABLE;
break;
case DRM_MODE_DPMS_OFF:
temp |= ADPA_HSYNC_CNTL_DISABLE | ADPA_VSYNC_CNTL_DISABLE;
break;
}
I915_WRITE(reg, temp);
}
static int intel_crt_mode_valid(struct drm_connector *connector,
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
return MODE_OK;
}
static bool intel_crt_mode_fixup(struct drm_encoder *encoder,
struct drm_display_mode *mode,
struct drm_display_mode *adjusted_mode)
{
return true;
}
static void intel_crt_mode_set(struct drm_encoder *encoder,
struct drm_display_mode *mode,
struct drm_display_mode *adjusted_mode)
{
struct drm_device *dev = encoder->dev;
struct drm_crtc *crtc = encoder->crtc;
struct intel_crtc *intel_crtc = to_intel_crtc(crtc);
struct drm_i915_private *dev_priv = dev->dev_private;
int dpll_md_reg;
u32 adpa, dpll_md;
u32 adpa_reg;
dpll_md_reg = DPLL_MD(intel_crtc->pipe);
if (HAS_PCH_SPLIT(dev))
adpa_reg = PCH_ADPA;
else
adpa_reg = ADPA;
if (INTEL_INFO(dev)->gen >= 4 && !HAS_PCH_SPLIT(dev)) {
dpll_md = I915_READ(dpll_md_reg);
I915_WRITE(dpll_md_reg,
dpll_md & ~DPLL_MD_UDI_MULTIPLIER_MASK);
}
adpa = ADPA_HOTPLUG_BITS;
if (adjusted_mode->flags & DRM_MODE_FLAG_PHSYNC)
adpa |= ADPA_HSYNC_ACTIVE_HIGH;
if (adjusted_mode->flags & DRM_MODE_FLAG_PVSYNC)
adpa |= ADPA_VSYNC_ACTIVE_HIGH;
if (HAS_PCH_CPT(dev))
adpa |= PORT_TRANS_SEL_CPT(intel_crtc->pipe);
else if (intel_crtc->pipe == 0)
adpa |= ADPA_PIPE_A_SELECT;
else
adpa |= ADPA_PIPE_B_SELECT;
if (!HAS_PCH_SPLIT(dev))
I915_WRITE(BCLRPAT(intel_crtc->pipe), 0);
I915_WRITE(adpa_reg, adpa);
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
save_adpa = adpa = I915_READ(PCH_ADPA);
DRM_DEBUG_KMS("trigger hotplug detect cycle: adpa=0x%x\n", adpa);
adpa |= ADPA_CRT_HOTPLUG_FORCE_TRIGGER;
if (turn_off_dac)
adpa &= ~ADPA_DAC_ENABLE;
I915_WRITE(PCH_ADPA, adpa);
if (wait_for((I915_READ(PCH_ADPA) & ADPA_CRT_HOTPLUG_FORCE_TRIGGER) == 0,
1000))
DRM_DEBUG_KMS("timed out waiting for FORCE_TRIGGER");
if (turn_off_dac) {
I915_WRITE(PCH_ADPA, save_adpa);
POSTING_READ(PCH_ADPA);
}
}
adpa = I915_READ(PCH_ADPA);
if ((adpa & ADPA_CRT_HOTPLUG_MONITOR_MASK) != 0)
ret = true;
else
ret = false;
DRM_DEBUG_KMS("ironlake hotplug adpa=0x%x, result %d\n", adpa, ret);
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
static bool intel_crt_detect_ddc(struct drm_connector *connector)
{
struct intel_crt *crt = intel_attached_crt(connector);
struct drm_i915_private *dev_priv = crt->base.base.dev->dev_private;
if (crt->base.type != INTEL_OUTPUT_ANALOG)
return false;
if (intel_ddc_probe(&crt->base, dev_priv->crt_ddc_pin)) {
struct edid *edid;
bool is_digital = false;
edid = drm_get_edid(connector,
&dev_priv->gmbus[dev_priv->crt_ddc_pin].adapter);
if (edid != NULL) {
is_digital = edid->input & DRM_EDID_INPUT_DIGITAL;
connector->display_info.raw_edid = NULL;
kfree(edid);
}
if (!is_digital) {
DRM_DEBUG_KMS("CRT detected via DDC:0x50 [EDID]\n");
return true;
} else {
DRM_DEBUG_KMS("CRT not detected via DDC:0x50 [EDID reports a digital panel]\n");
}
}
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
struct intel_crt *crt = intel_attached_crt(connector);
struct drm_crtc *crtc;
enum drm_connector_status status;
if (I915_HAS_HOTPLUG(dev)) {
if (intel_crt_detect_hotplug(connector)) {
DRM_DEBUG_KMS("CRT detected via hotplug\n");
return connector_status_connected;
} else {
DRM_DEBUG_KMS("CRT not detected via hotplug\n");
return connector_status_disconnected;
}
}
if (intel_crt_detect_ddc(connector))
return connector_status_connected;
if (!force)
return connector->status;
crtc = crt->base.base.crtc;
if (crtc && crtc->enabled) {
status = intel_crt_load_detect(crt);
} else {
struct intel_load_detect_pipe tmp;
if (intel_get_load_detect_pipe(&crt->base, connector, NULL,
&tmp)) {
if (intel_crt_detect_ddc(connector))
status = connector_status_connected;
else
status = intel_crt_load_detect(crt);
intel_release_load_detect_pipe(&crt->base, connector,
&tmp);
} else
status = connector_status_unknown;
}
return status;
}
static void intel_crt_destroy(struct drm_connector *connector)
{
drm_sysfs_connector_remove(connector);
drm_connector_cleanup(connector);
kfree(connector);
}
static int intel_crt_get_modes(struct drm_connector *connector)
{
struct drm_device *dev = connector->dev;
struct drm_i915_private *dev_priv = dev->dev_private;
int ret;
ret = intel_ddc_get_modes(connector,
&dev_priv->gmbus[dev_priv->crt_ddc_pin].adapter);
if (ret || !IS_G4X(dev))
return ret;
return intel_ddc_get_modes(connector,
&dev_priv->gmbus[GMBUS_PORT_DPB].adapter);
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
struct intel_crt *crt = intel_attached_crt(connector);
if (HAS_PCH_SPLIT(dev))
crt->force_hotplug_required = 1;
}
static int __init intel_no_crt_dmi_callback(const struct dmi_system_id *id)
{
DRM_DEBUG_KMS("Skipping CRT initialization for %s\n", id->ident);
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
intel_connector = kzalloc(sizeof(struct intel_connector), GFP_KERNEL);
if (!intel_connector) {
kfree(crt);
return;
}
connector = &intel_connector->base;
drm_connector_init(dev, &intel_connector->base,
&intel_crt_connector_funcs, DRM_MODE_CONNECTOR_VGA);
drm_encoder_init(dev, &crt->base.base, &intel_crt_enc_funcs,
DRM_MODE_ENCODER_DAC);
intel_connector_attach_encoder(intel_connector, &crt->base);
crt->base.type = INTEL_OUTPUT_ANALOG;
crt->base.clone_mask = (1 << INTEL_SDVO_NON_TV_CLONE_BIT |
1 << INTEL_ANALOG_CLONE_BIT |
1 << INTEL_SDVO_LVDS_CLONE_BIT);
crt->base.crtc_mask = (1 << 0) | (1 << 1);
connector->interlace_allowed = 1;
connector->doublescan_allowed = 0;
drm_encoder_helper_add(&crt->base.base, &intel_crt_helper_funcs);
drm_connector_helper_add(connector, &intel_crt_connector_helper_funcs);
drm_sysfs_connector_add(connector);
if (I915_HAS_HOTPLUG(dev))
connector->polled = DRM_CONNECTOR_POLL_HPD;
else
connector->polled = DRM_CONNECTOR_POLL_CONNECT;
crt->force_hotplug_required = 0;
if (HAS_PCH_SPLIT(dev)) {
u32 adpa;
adpa = I915_READ(PCH_ADPA);
adpa &= ~ADPA_CRT_HOTPLUG_MASK;
adpa |= ADPA_HOTPLUG_BITS;
I915_WRITE(PCH_ADPA, adpa);
POSTING_READ(PCH_ADPA);
DRM_DEBUG_KMS("pch crt adpa set to 0x%x\n", adpa);
crt->force_hotplug_required = 1;
}
dev_priv->hotplug_supported_mask |= CRT_HOTPLUG_INT_STATUS;
}
