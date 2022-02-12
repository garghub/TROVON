const char *
intel_display_power_domain_str(enum intel_display_power_domain domain)
{
switch (domain) {
case POWER_DOMAIN_PIPE_A:
return "PIPE_A";
case POWER_DOMAIN_PIPE_B:
return "PIPE_B";
case POWER_DOMAIN_PIPE_C:
return "PIPE_C";
case POWER_DOMAIN_PIPE_A_PANEL_FITTER:
return "PIPE_A_PANEL_FITTER";
case POWER_DOMAIN_PIPE_B_PANEL_FITTER:
return "PIPE_B_PANEL_FITTER";
case POWER_DOMAIN_PIPE_C_PANEL_FITTER:
return "PIPE_C_PANEL_FITTER";
case POWER_DOMAIN_TRANSCODER_A:
return "TRANSCODER_A";
case POWER_DOMAIN_TRANSCODER_B:
return "TRANSCODER_B";
case POWER_DOMAIN_TRANSCODER_C:
return "TRANSCODER_C";
case POWER_DOMAIN_TRANSCODER_EDP:
return "TRANSCODER_EDP";
case POWER_DOMAIN_TRANSCODER_DSI_A:
return "TRANSCODER_DSI_A";
case POWER_DOMAIN_TRANSCODER_DSI_C:
return "TRANSCODER_DSI_C";
case POWER_DOMAIN_PORT_DDI_A_LANES:
return "PORT_DDI_A_LANES";
case POWER_DOMAIN_PORT_DDI_B_LANES:
return "PORT_DDI_B_LANES";
case POWER_DOMAIN_PORT_DDI_C_LANES:
return "PORT_DDI_C_LANES";
case POWER_DOMAIN_PORT_DDI_D_LANES:
return "PORT_DDI_D_LANES";
case POWER_DOMAIN_PORT_DDI_E_LANES:
return "PORT_DDI_E_LANES";
case POWER_DOMAIN_PORT_DSI:
return "PORT_DSI";
case POWER_DOMAIN_PORT_CRT:
return "PORT_CRT";
case POWER_DOMAIN_PORT_OTHER:
return "PORT_OTHER";
case POWER_DOMAIN_VGA:
return "VGA";
case POWER_DOMAIN_AUDIO:
return "AUDIO";
case POWER_DOMAIN_PLLS:
return "PLLS";
case POWER_DOMAIN_AUX_A:
return "AUX_A";
case POWER_DOMAIN_AUX_B:
return "AUX_B";
case POWER_DOMAIN_AUX_C:
return "AUX_C";
case POWER_DOMAIN_AUX_D:
return "AUX_D";
case POWER_DOMAIN_GMBUS:
return "GMBUS";
case POWER_DOMAIN_INIT:
return "INIT";
case POWER_DOMAIN_MODESET:
return "MODESET";
default:
MISSING_CASE(domain);
return "?";
}
}
static void intel_power_well_enable(struct drm_i915_private *dev_priv,
struct i915_power_well *power_well)
{
DRM_DEBUG_KMS("enabling %s\n", power_well->name);
power_well->ops->enable(dev_priv, power_well);
power_well->hw_enabled = true;
}
static void intel_power_well_disable(struct drm_i915_private *dev_priv,
struct i915_power_well *power_well)
{
DRM_DEBUG_KMS("disabling %s\n", power_well->name);
power_well->hw_enabled = false;
power_well->ops->disable(dev_priv, power_well);
}
static bool hsw_power_well_enabled(struct drm_i915_private *dev_priv,
struct i915_power_well *power_well)
{
return I915_READ(HSW_PWR_WELL_DRIVER) ==
(HSW_PWR_WELL_ENABLE_REQUEST | HSW_PWR_WELL_STATE_ENABLED);
}
bool __intel_display_power_is_enabled(struct drm_i915_private *dev_priv,
enum intel_display_power_domain domain)
{
struct i915_power_domains *power_domains;
struct i915_power_well *power_well;
bool is_enabled;
int i;
if (dev_priv->pm.suspended)
return false;
power_domains = &dev_priv->power_domains;
is_enabled = true;
for_each_power_well_rev(i, power_well, BIT(domain), power_domains) {
if (power_well->always_on)
continue;
if (!power_well->hw_enabled) {
is_enabled = false;
break;
}
}
return is_enabled;
}
bool intel_display_power_is_enabled(struct drm_i915_private *dev_priv,
enum intel_display_power_domain domain)
{
struct i915_power_domains *power_domains;
bool ret;
power_domains = &dev_priv->power_domains;
mutex_lock(&power_domains->lock);
ret = __intel_display_power_is_enabled(dev_priv, domain);
mutex_unlock(&power_domains->lock);
return ret;
}
void intel_display_set_init_power(struct drm_i915_private *dev_priv,
bool enable)
{
if (dev_priv->power_domains.init_power_on == enable)
return;
if (enable)
intel_display_power_get(dev_priv, POWER_DOMAIN_INIT);
else
intel_display_power_put(dev_priv, POWER_DOMAIN_INIT);
dev_priv->power_domains.init_power_on = enable;
}
static void hsw_power_well_post_enable(struct drm_i915_private *dev_priv)
{
struct drm_device *dev = dev_priv->dev;
vga_get_uninterruptible(dev->pdev, VGA_RSRC_LEGACY_IO);
outb(inb(VGA_MSR_READ), VGA_MSR_WRITE);
vga_put(dev->pdev, VGA_RSRC_LEGACY_IO);
if (IS_BROADWELL(dev))
gen8_irq_power_well_post_enable(dev_priv,
1 << PIPE_C | 1 << PIPE_B);
}
static void hsw_power_well_pre_disable(struct drm_i915_private *dev_priv)
{
if (IS_BROADWELL(dev_priv))
gen8_irq_power_well_pre_disable(dev_priv,
1 << PIPE_C | 1 << PIPE_B);
}
static void skl_power_well_post_enable(struct drm_i915_private *dev_priv,
struct i915_power_well *power_well)
{
struct drm_device *dev = dev_priv->dev;
if (power_well->data == SKL_DISP_PW_2) {
vga_get_uninterruptible(dev->pdev, VGA_RSRC_LEGACY_IO);
outb(inb(VGA_MSR_READ), VGA_MSR_WRITE);
vga_put(dev->pdev, VGA_RSRC_LEGACY_IO);
gen8_irq_power_well_post_enable(dev_priv,
1 << PIPE_C | 1 << PIPE_B);
}
}
static void skl_power_well_pre_disable(struct drm_i915_private *dev_priv,
struct i915_power_well *power_well)
{
if (power_well->data == SKL_DISP_PW_2)
gen8_irq_power_well_pre_disable(dev_priv,
1 << PIPE_C | 1 << PIPE_B);
}
static void hsw_set_power_well(struct drm_i915_private *dev_priv,
struct i915_power_well *power_well, bool enable)
{
bool is_enabled, enable_requested;
uint32_t tmp;
tmp = I915_READ(HSW_PWR_WELL_DRIVER);
is_enabled = tmp & HSW_PWR_WELL_STATE_ENABLED;
enable_requested = tmp & HSW_PWR_WELL_ENABLE_REQUEST;
if (enable) {
if (!enable_requested)
I915_WRITE(HSW_PWR_WELL_DRIVER,
HSW_PWR_WELL_ENABLE_REQUEST);
if (!is_enabled) {
DRM_DEBUG_KMS("Enabling power well\n");
if (wait_for((I915_READ(HSW_PWR_WELL_DRIVER) &
HSW_PWR_WELL_STATE_ENABLED), 20))
DRM_ERROR("Timeout enabling power well\n");
hsw_power_well_post_enable(dev_priv);
}
} else {
if (enable_requested) {
hsw_power_well_pre_disable(dev_priv);
I915_WRITE(HSW_PWR_WELL_DRIVER, 0);
POSTING_READ(HSW_PWR_WELL_DRIVER);
DRM_DEBUG_KMS("Requesting to disable the power well\n");
}
}
}
static void assert_can_enable_dc9(struct drm_i915_private *dev_priv)
{
WARN_ONCE((I915_READ(DC_STATE_EN) & DC_STATE_EN_DC9),
"DC9 already programmed to be enabled.\n");
WARN_ONCE(I915_READ(DC_STATE_EN) & DC_STATE_EN_UPTO_DC5,
"DC5 still not disabled to enable DC9.\n");
WARN_ONCE(I915_READ(HSW_PWR_WELL_DRIVER), "Power well on.\n");
WARN_ONCE(intel_irqs_enabled(dev_priv),
"Interrupts not disabled yet.\n");
}
static void assert_can_disable_dc9(struct drm_i915_private *dev_priv)
{
WARN_ONCE(intel_irqs_enabled(dev_priv),
"Interrupts not disabled yet.\n");
WARN_ONCE(I915_READ(DC_STATE_EN) & DC_STATE_EN_UPTO_DC5,
"DC5 still not disabled.\n");
}
static void gen9_write_dc_state(struct drm_i915_private *dev_priv,
u32 state)
{
int rewrites = 0;
int rereads = 0;
u32 v;
I915_WRITE(DC_STATE_EN, state);
do {
v = I915_READ(DC_STATE_EN);
if (v != state) {
I915_WRITE(DC_STATE_EN, state);
rewrites++;
rereads = 0;
} else if (rereads++ > 5) {
break;
}
} while (rewrites < 100);
if (v != state)
DRM_ERROR("Writing dc state to 0x%x failed, now 0x%x\n",
state, v);
if (rewrites > 1)
DRM_DEBUG_KMS("Rewrote dc state to 0x%x %d times\n",
state, rewrites);
}
static u32 gen9_dc_mask(struct drm_i915_private *dev_priv)
{
u32 mask;
mask = DC_STATE_EN_UPTO_DC5;
if (IS_BROXTON(dev_priv))
mask |= DC_STATE_EN_DC9;
else
mask |= DC_STATE_EN_UPTO_DC6;
return mask;
}
void gen9_sanitize_dc_state(struct drm_i915_private *dev_priv)
{
u32 val;
val = I915_READ(DC_STATE_EN) & gen9_dc_mask(dev_priv);
DRM_DEBUG_KMS("Resetting DC state tracking from %02x to %02x\n",
dev_priv->csr.dc_state, val);
dev_priv->csr.dc_state = val;
}
static void gen9_set_dc_state(struct drm_i915_private *dev_priv, uint32_t state)
{
uint32_t val;
uint32_t mask;
if (WARN_ON_ONCE(state & ~dev_priv->csr.allowed_dc_mask))
state &= dev_priv->csr.allowed_dc_mask;
val = I915_READ(DC_STATE_EN);
mask = gen9_dc_mask(dev_priv);
DRM_DEBUG_KMS("Setting DC state from %02x to %02x\n",
val & mask, state);
if ((val & mask) != dev_priv->csr.dc_state)
DRM_ERROR("DC state mismatch (0x%x -> 0x%x)\n",
dev_priv->csr.dc_state, val & mask);
val &= ~mask;
val |= state;
gen9_write_dc_state(dev_priv, val);
dev_priv->csr.dc_state = val & mask;
}
void bxt_enable_dc9(struct drm_i915_private *dev_priv)
{
assert_can_enable_dc9(dev_priv);
DRM_DEBUG_KMS("Enabling DC9\n");
gen9_set_dc_state(dev_priv, DC_STATE_EN_DC9);
}
void bxt_disable_dc9(struct drm_i915_private *dev_priv)
{
assert_can_disable_dc9(dev_priv);
DRM_DEBUG_KMS("Disabling DC9\n");
gen9_set_dc_state(dev_priv, DC_STATE_DISABLE);
}
static void assert_csr_loaded(struct drm_i915_private *dev_priv)
{
WARN_ONCE(!I915_READ(CSR_PROGRAM(0)),
"CSR program storage start is NULL\n");
WARN_ONCE(!I915_READ(CSR_SSP_BASE), "CSR SSP Base Not fine\n");
WARN_ONCE(!I915_READ(CSR_HTP_SKL), "CSR HTP Not fine\n");
}
static void assert_can_enable_dc5(struct drm_i915_private *dev_priv)
{
bool pg2_enabled = intel_display_power_well_is_enabled(dev_priv,
SKL_DISP_PW_2);
WARN_ONCE(pg2_enabled, "PG2 not disabled to enable DC5.\n");
WARN_ONCE((I915_READ(DC_STATE_EN) & DC_STATE_EN_UPTO_DC5),
"DC5 already programmed to be enabled.\n");
assert_rpm_wakelock_held(dev_priv);
assert_csr_loaded(dev_priv);
}
void gen9_enable_dc5(struct drm_i915_private *dev_priv)
{
assert_can_enable_dc5(dev_priv);
DRM_DEBUG_KMS("Enabling DC5\n");
gen9_set_dc_state(dev_priv, DC_STATE_EN_UPTO_DC5);
}
static void assert_can_enable_dc6(struct drm_i915_private *dev_priv)
{
WARN_ONCE(I915_READ(UTIL_PIN_CTL) & UTIL_PIN_ENABLE,
"Backlight is not disabled.\n");
WARN_ONCE((I915_READ(DC_STATE_EN) & DC_STATE_EN_UPTO_DC6),
"DC6 already programmed to be enabled.\n");
assert_csr_loaded(dev_priv);
}
void skl_enable_dc6(struct drm_i915_private *dev_priv)
{
assert_can_enable_dc6(dev_priv);
DRM_DEBUG_KMS("Enabling DC6\n");
gen9_set_dc_state(dev_priv, DC_STATE_EN_UPTO_DC6);
}
void skl_disable_dc6(struct drm_i915_private *dev_priv)
{
DRM_DEBUG_KMS("Disabling DC6\n");
gen9_set_dc_state(dev_priv, DC_STATE_DISABLE);
}
static void
gen9_sanitize_power_well_requests(struct drm_i915_private *dev_priv,
struct i915_power_well *power_well)
{
enum skl_disp_power_wells power_well_id = power_well->data;
u32 val;
u32 mask;
mask = SKL_POWER_WELL_REQ(power_well_id);
val = I915_READ(HSW_PWR_WELL_KVMR);
if (WARN_ONCE(val & mask, "Clearing unexpected KVMR request for %s\n",
power_well->name))
I915_WRITE(HSW_PWR_WELL_KVMR, val & ~mask);
val = I915_READ(HSW_PWR_WELL_BIOS);
val |= I915_READ(HSW_PWR_WELL_DEBUG);
if (!(val & mask))
return;
if (power_well_id == SKL_DISP_PW_1 ||
((IS_SKYLAKE(dev_priv) || IS_KABYLAKE(dev_priv)) &&
power_well_id == SKL_DISP_PW_MISC_IO))
DRM_DEBUG_DRIVER("Clearing auxiliary requests for %s forced on "
"by DMC\n", power_well->name);
else
WARN_ONCE(1, "Clearing unexpected auxiliary requests for %s\n",
power_well->name);
I915_WRITE(HSW_PWR_WELL_BIOS, val & ~mask);
I915_WRITE(HSW_PWR_WELL_DEBUG, val & ~mask);
}
static void skl_set_power_well(struct drm_i915_private *dev_priv,
struct i915_power_well *power_well, bool enable)
{
uint32_t tmp, fuse_status;
uint32_t req_mask, state_mask;
bool is_enabled, enable_requested, check_fuse_status = false;
tmp = I915_READ(HSW_PWR_WELL_DRIVER);
fuse_status = I915_READ(SKL_FUSE_STATUS);
switch (power_well->data) {
case SKL_DISP_PW_1:
if (wait_for((I915_READ(SKL_FUSE_STATUS) &
SKL_FUSE_PG0_DIST_STATUS), 1)) {
DRM_ERROR("PG0 not enabled\n");
return;
}
break;
case SKL_DISP_PW_2:
if (!(fuse_status & SKL_FUSE_PG1_DIST_STATUS)) {
DRM_ERROR("PG1 in disabled state\n");
return;
}
break;
case SKL_DISP_PW_DDI_A_E:
case SKL_DISP_PW_DDI_B:
case SKL_DISP_PW_DDI_C:
case SKL_DISP_PW_DDI_D:
case SKL_DISP_PW_MISC_IO:
break;
default:
WARN(1, "Unknown power well %lu\n", power_well->data);
return;
}
req_mask = SKL_POWER_WELL_REQ(power_well->data);
enable_requested = tmp & req_mask;
state_mask = SKL_POWER_WELL_STATE(power_well->data);
is_enabled = tmp & state_mask;
if (!enable && enable_requested)
skl_power_well_pre_disable(dev_priv, power_well);
if (enable) {
if (!enable_requested) {
WARN((tmp & state_mask) &&
!I915_READ(HSW_PWR_WELL_BIOS),
"Invalid for power well status to be enabled, unless done by the BIOS, \
when request is to disable!\n");
I915_WRITE(HSW_PWR_WELL_DRIVER, tmp | req_mask);
}
if (!is_enabled) {
DRM_DEBUG_KMS("Enabling %s\n", power_well->name);
check_fuse_status = true;
}
} else {
if (enable_requested) {
I915_WRITE(HSW_PWR_WELL_DRIVER, tmp & ~req_mask);
POSTING_READ(HSW_PWR_WELL_DRIVER);
DRM_DEBUG_KMS("Disabling %s\n", power_well->name);
}
if (IS_GEN9(dev_priv))
gen9_sanitize_power_well_requests(dev_priv, power_well);
}
if (wait_for(!!(I915_READ(HSW_PWR_WELL_DRIVER) & state_mask) == enable,
1))
DRM_ERROR("%s %s timeout\n",
power_well->name, enable ? "enable" : "disable");
if (check_fuse_status) {
if (power_well->data == SKL_DISP_PW_1) {
if (wait_for((I915_READ(SKL_FUSE_STATUS) &
SKL_FUSE_PG1_DIST_STATUS), 1))
DRM_ERROR("PG1 distributing status timeout\n");
} else if (power_well->data == SKL_DISP_PW_2) {
if (wait_for((I915_READ(SKL_FUSE_STATUS) &
SKL_FUSE_PG2_DIST_STATUS), 1))
DRM_ERROR("PG2 distributing status timeout\n");
}
}
if (enable && !is_enabled)
skl_power_well_post_enable(dev_priv, power_well);
}
static void hsw_power_well_sync_hw(struct drm_i915_private *dev_priv,
struct i915_power_well *power_well)
{
hsw_set_power_well(dev_priv, power_well, power_well->count > 0);
if (I915_READ(HSW_PWR_WELL_BIOS) & HSW_PWR_WELL_ENABLE_REQUEST)
I915_WRITE(HSW_PWR_WELL_BIOS, 0);
}
static void hsw_power_well_enable(struct drm_i915_private *dev_priv,
struct i915_power_well *power_well)
{
hsw_set_power_well(dev_priv, power_well, true);
}
static void hsw_power_well_disable(struct drm_i915_private *dev_priv,
struct i915_power_well *power_well)
{
hsw_set_power_well(dev_priv, power_well, false);
}
static bool skl_power_well_enabled(struct drm_i915_private *dev_priv,
struct i915_power_well *power_well)
{
uint32_t mask = SKL_POWER_WELL_REQ(power_well->data) |
SKL_POWER_WELL_STATE(power_well->data);
return (I915_READ(HSW_PWR_WELL_DRIVER) & mask) == mask;
}
static void skl_power_well_sync_hw(struct drm_i915_private *dev_priv,
struct i915_power_well *power_well)
{
skl_set_power_well(dev_priv, power_well, power_well->count > 0);
I915_WRITE(HSW_PWR_WELL_BIOS, 0);
}
static void skl_power_well_enable(struct drm_i915_private *dev_priv,
struct i915_power_well *power_well)
{
skl_set_power_well(dev_priv, power_well, true);
}
static void skl_power_well_disable(struct drm_i915_private *dev_priv,
struct i915_power_well *power_well)
{
skl_set_power_well(dev_priv, power_well, false);
}
static bool gen9_dc_off_power_well_enabled(struct drm_i915_private *dev_priv,
struct i915_power_well *power_well)
{
return (I915_READ(DC_STATE_EN) & DC_STATE_EN_UPTO_DC5_DC6_MASK) == 0;
}
static void gen9_dc_off_power_well_enable(struct drm_i915_private *dev_priv,
struct i915_power_well *power_well)
{
gen9_set_dc_state(dev_priv, DC_STATE_DISABLE);
if (IS_BROXTON(dev_priv)) {
broxton_cdclk_verify_state(dev_priv);
broxton_ddi_phy_verify_state(dev_priv);
}
}
static void gen9_dc_off_power_well_disable(struct drm_i915_private *dev_priv,
struct i915_power_well *power_well)
{
if (!dev_priv->csr.dmc_payload)
return;
if (dev_priv->csr.allowed_dc_mask & DC_STATE_EN_UPTO_DC6)
skl_enable_dc6(dev_priv);
else if (dev_priv->csr.allowed_dc_mask & DC_STATE_EN_UPTO_DC5)
gen9_enable_dc5(dev_priv);
}
static void gen9_dc_off_power_well_sync_hw(struct drm_i915_private *dev_priv,
struct i915_power_well *power_well)
{
if (power_well->count > 0)
gen9_dc_off_power_well_enable(dev_priv, power_well);
else
gen9_dc_off_power_well_disable(dev_priv, power_well);
}
static void i9xx_always_on_power_well_noop(struct drm_i915_private *dev_priv,
struct i915_power_well *power_well)
{
}
static bool i9xx_always_on_power_well_enabled(struct drm_i915_private *dev_priv,
struct i915_power_well *power_well)
{
return true;
}
static void vlv_set_power_well(struct drm_i915_private *dev_priv,
struct i915_power_well *power_well, bool enable)
{
enum punit_power_well power_well_id = power_well->data;
u32 mask;
u32 state;
u32 ctrl;
mask = PUNIT_PWRGT_MASK(power_well_id);
state = enable ? PUNIT_PWRGT_PWR_ON(power_well_id) :
PUNIT_PWRGT_PWR_GATE(power_well_id);
mutex_lock(&dev_priv->rps.hw_lock);
#define COND \
((vlv_punit_read(dev_priv, PUNIT_REG_PWRGT_STATUS) & mask) == state)
if (COND)
goto out;
ctrl = vlv_punit_read(dev_priv, PUNIT_REG_PWRGT_CTRL);
ctrl &= ~mask;
ctrl |= state;
vlv_punit_write(dev_priv, PUNIT_REG_PWRGT_CTRL, ctrl);
if (wait_for(COND, 100))
DRM_ERROR("timeout setting power well state %08x (%08x)\n",
state,
vlv_punit_read(dev_priv, PUNIT_REG_PWRGT_CTRL));
#undef COND
out:
mutex_unlock(&dev_priv->rps.hw_lock);
}
static void vlv_power_well_sync_hw(struct drm_i915_private *dev_priv,
struct i915_power_well *power_well)
{
vlv_set_power_well(dev_priv, power_well, power_well->count > 0);
}
static void vlv_power_well_enable(struct drm_i915_private *dev_priv,
struct i915_power_well *power_well)
{
vlv_set_power_well(dev_priv, power_well, true);
}
static void vlv_power_well_disable(struct drm_i915_private *dev_priv,
struct i915_power_well *power_well)
{
vlv_set_power_well(dev_priv, power_well, false);
}
static bool vlv_power_well_enabled(struct drm_i915_private *dev_priv,
struct i915_power_well *power_well)
{
int power_well_id = power_well->data;
bool enabled = false;
u32 mask;
u32 state;
u32 ctrl;
mask = PUNIT_PWRGT_MASK(power_well_id);
ctrl = PUNIT_PWRGT_PWR_ON(power_well_id);
mutex_lock(&dev_priv->rps.hw_lock);
state = vlv_punit_read(dev_priv, PUNIT_REG_PWRGT_STATUS) & mask;
WARN_ON(state != PUNIT_PWRGT_PWR_ON(power_well_id) &&
state != PUNIT_PWRGT_PWR_GATE(power_well_id));
if (state == ctrl)
enabled = true;
ctrl = vlv_punit_read(dev_priv, PUNIT_REG_PWRGT_CTRL) & mask;
WARN_ON(ctrl != state);
mutex_unlock(&dev_priv->rps.hw_lock);
return enabled;
}
static void vlv_init_display_clock_gating(struct drm_i915_private *dev_priv)
{
I915_WRITE(DSPCLK_GATE_D, VRHUNIT_CLOCK_GATE_DISABLE);
I915_WRITE(MI_ARB_VLV, MI_ARB_DISPLAY_TRICKLE_FEED_DISABLE);
I915_WRITE(CBR1_VLV, 0);
}
static void vlv_display_power_well_init(struct drm_i915_private *dev_priv)
{
enum pipe pipe;
for_each_pipe(dev_priv->dev, pipe) {
u32 val = I915_READ(DPLL(pipe));
val |= DPLL_REF_CLK_ENABLE_VLV | DPLL_VGA_MODE_DIS;
if (pipe != PIPE_A)
val |= DPLL_INTEGRATED_CRI_CLK_VLV;
I915_WRITE(DPLL(pipe), val);
}
vlv_init_display_clock_gating(dev_priv);
spin_lock_irq(&dev_priv->irq_lock);
valleyview_enable_display_irqs(dev_priv);
spin_unlock_irq(&dev_priv->irq_lock);
if (dev_priv->power_domains.initializing)
return;
intel_hpd_init(dev_priv);
i915_redisable_vga_power_on(dev_priv->dev);
}
static void vlv_display_power_well_deinit(struct drm_i915_private *dev_priv)
{
spin_lock_irq(&dev_priv->irq_lock);
valleyview_disable_display_irqs(dev_priv);
spin_unlock_irq(&dev_priv->irq_lock);
synchronize_irq(dev_priv->dev->irq);
vlv_power_sequencer_reset(dev_priv);
}
static void vlv_display_power_well_enable(struct drm_i915_private *dev_priv,
struct i915_power_well *power_well)
{
WARN_ON_ONCE(power_well->data != PUNIT_POWER_WELL_DISP2D);
vlv_set_power_well(dev_priv, power_well, true);
vlv_display_power_well_init(dev_priv);
}
static void vlv_display_power_well_disable(struct drm_i915_private *dev_priv,
struct i915_power_well *power_well)
{
WARN_ON_ONCE(power_well->data != PUNIT_POWER_WELL_DISP2D);
vlv_display_power_well_deinit(dev_priv);
vlv_set_power_well(dev_priv, power_well, false);
}
static void vlv_dpio_cmn_power_well_enable(struct drm_i915_private *dev_priv,
struct i915_power_well *power_well)
{
WARN_ON_ONCE(power_well->data != PUNIT_POWER_WELL_DPIO_CMN_BC);
udelay(1);
vlv_set_power_well(dev_priv, power_well, true);
I915_WRITE(DPIO_CTL, I915_READ(DPIO_CTL) | DPIO_CMNRST);
}
static void vlv_dpio_cmn_power_well_disable(struct drm_i915_private *dev_priv,
struct i915_power_well *power_well)
{
enum pipe pipe;
WARN_ON_ONCE(power_well->data != PUNIT_POWER_WELL_DPIO_CMN_BC);
for_each_pipe(dev_priv, pipe)
assert_pll_disabled(dev_priv, pipe);
I915_WRITE(DPIO_CTL, I915_READ(DPIO_CTL) & ~DPIO_CMNRST);
vlv_set_power_well(dev_priv, power_well, false);
}
static struct i915_power_well *lookup_power_well(struct drm_i915_private *dev_priv,
int power_well_id)
{
struct i915_power_domains *power_domains = &dev_priv->power_domains;
int i;
for (i = 0; i < power_domains->power_well_count; i++) {
struct i915_power_well *power_well;
power_well = &power_domains->power_wells[i];
if (power_well->data == power_well_id)
return power_well;
}
return NULL;
}
static void assert_chv_phy_status(struct drm_i915_private *dev_priv)
{
struct i915_power_well *cmn_bc =
lookup_power_well(dev_priv, PUNIT_POWER_WELL_DPIO_CMN_BC);
struct i915_power_well *cmn_d =
lookup_power_well(dev_priv, PUNIT_POWER_WELL_DPIO_CMN_D);
u32 phy_control = dev_priv->chv_phy_control;
u32 phy_status = 0;
u32 phy_status_mask = 0xffffffff;
u32 tmp;
if (!dev_priv->chv_phy_assert[DPIO_PHY0])
phy_status_mask &= ~(PHY_STATUS_CMN_LDO(DPIO_PHY0, DPIO_CH0) |
PHY_STATUS_SPLINE_LDO(DPIO_PHY0, DPIO_CH0, 0) |
PHY_STATUS_SPLINE_LDO(DPIO_PHY0, DPIO_CH0, 1) |
PHY_STATUS_CMN_LDO(DPIO_PHY0, DPIO_CH1) |
PHY_STATUS_SPLINE_LDO(DPIO_PHY0, DPIO_CH1, 0) |
PHY_STATUS_SPLINE_LDO(DPIO_PHY0, DPIO_CH1, 1));
if (!dev_priv->chv_phy_assert[DPIO_PHY1])
phy_status_mask &= ~(PHY_STATUS_CMN_LDO(DPIO_PHY1, DPIO_CH0) |
PHY_STATUS_SPLINE_LDO(DPIO_PHY1, DPIO_CH0, 0) |
PHY_STATUS_SPLINE_LDO(DPIO_PHY1, DPIO_CH0, 1));
if (cmn_bc->ops->is_enabled(dev_priv, cmn_bc)) {
phy_status |= PHY_POWERGOOD(DPIO_PHY0);
if ((phy_control & PHY_CH_POWER_DOWN_OVRD_EN(DPIO_PHY0, DPIO_CH0)) == 0)
phy_control |= PHY_CH_POWER_DOWN_OVRD(0xf, DPIO_PHY0, DPIO_CH0);
if ((phy_control & PHY_CH_POWER_DOWN_OVRD_EN(DPIO_PHY0, DPIO_CH1)) == 0)
phy_control |= PHY_CH_POWER_DOWN_OVRD(0xf, DPIO_PHY0, DPIO_CH1);
if (BITS_SET(phy_control,
PHY_CH_POWER_DOWN_OVRD(0xf, DPIO_PHY0, DPIO_CH0) |
PHY_CH_POWER_DOWN_OVRD(0xf, DPIO_PHY0, DPIO_CH1)))
phy_status |= PHY_STATUS_CMN_LDO(DPIO_PHY0, DPIO_CH0);
if (BITS_SET(phy_control,
PHY_CH_POWER_DOWN_OVRD(0xf, DPIO_PHY0, DPIO_CH1)) &&
(I915_READ(DPLL(PIPE_B)) & DPLL_VCO_ENABLE) == 0)
phy_status |= PHY_STATUS_CMN_LDO(DPIO_PHY0, DPIO_CH1);
if (BITS_SET(phy_control,
PHY_CH_POWER_DOWN_OVRD(0x3, DPIO_PHY0, DPIO_CH0)))
phy_status |= PHY_STATUS_SPLINE_LDO(DPIO_PHY0, DPIO_CH0, 0);
if (BITS_SET(phy_control,
PHY_CH_POWER_DOWN_OVRD(0xc, DPIO_PHY0, DPIO_CH0)))
phy_status |= PHY_STATUS_SPLINE_LDO(DPIO_PHY0, DPIO_CH0, 1);
if (BITS_SET(phy_control,
PHY_CH_POWER_DOWN_OVRD(0x3, DPIO_PHY0, DPIO_CH1)))
phy_status |= PHY_STATUS_SPLINE_LDO(DPIO_PHY0, DPIO_CH1, 0);
if (BITS_SET(phy_control,
PHY_CH_POWER_DOWN_OVRD(0xc, DPIO_PHY0, DPIO_CH1)))
phy_status |= PHY_STATUS_SPLINE_LDO(DPIO_PHY0, DPIO_CH1, 1);
}
if (cmn_d->ops->is_enabled(dev_priv, cmn_d)) {
phy_status |= PHY_POWERGOOD(DPIO_PHY1);
if ((phy_control & PHY_CH_POWER_DOWN_OVRD_EN(DPIO_PHY1, DPIO_CH0)) == 0)
phy_control |= PHY_CH_POWER_DOWN_OVRD(0xf, DPIO_PHY1, DPIO_CH0);
if (BITS_SET(phy_control,
PHY_CH_POWER_DOWN_OVRD(0xf, DPIO_PHY1, DPIO_CH0)))
phy_status |= PHY_STATUS_CMN_LDO(DPIO_PHY1, DPIO_CH0);
if (BITS_SET(phy_control,
PHY_CH_POWER_DOWN_OVRD(0x3, DPIO_PHY1, DPIO_CH0)))
phy_status |= PHY_STATUS_SPLINE_LDO(DPIO_PHY1, DPIO_CH0, 0);
if (BITS_SET(phy_control,
PHY_CH_POWER_DOWN_OVRD(0xc, DPIO_PHY1, DPIO_CH0)))
phy_status |= PHY_STATUS_SPLINE_LDO(DPIO_PHY1, DPIO_CH0, 1);
}
phy_status &= phy_status_mask;
if (wait_for((tmp = I915_READ(DISPLAY_PHY_STATUS) & phy_status_mask) == phy_status, 10))
WARN(phy_status != tmp,
"Unexpected PHY_STATUS 0x%08x, expected 0x%08x (PHY_CONTROL=0x%08x)\n",
tmp, phy_status, dev_priv->chv_phy_control);
}
static void chv_dpio_cmn_power_well_enable(struct drm_i915_private *dev_priv,
struct i915_power_well *power_well)
{
enum dpio_phy phy;
enum pipe pipe;
uint32_t tmp;
WARN_ON_ONCE(power_well->data != PUNIT_POWER_WELL_DPIO_CMN_BC &&
power_well->data != PUNIT_POWER_WELL_DPIO_CMN_D);
if (power_well->data == PUNIT_POWER_WELL_DPIO_CMN_BC) {
pipe = PIPE_A;
phy = DPIO_PHY0;
} else {
pipe = PIPE_C;
phy = DPIO_PHY1;
}
udelay(1);
vlv_set_power_well(dev_priv, power_well, true);
if (wait_for(I915_READ(DISPLAY_PHY_STATUS) & PHY_POWERGOOD(phy), 1))
DRM_ERROR("Display PHY %d is not power up\n", phy);
mutex_lock(&dev_priv->sb_lock);
tmp = vlv_dpio_read(dev_priv, pipe, CHV_CMN_DW28);
tmp |= DPIO_DYNPWRDOWNEN_CH0 | DPIO_CL1POWERDOWNEN |
DPIO_SUS_CLK_CONFIG_GATE_CLKREQ;
vlv_dpio_write(dev_priv, pipe, CHV_CMN_DW28, tmp);
if (power_well->data == PUNIT_POWER_WELL_DPIO_CMN_BC) {
tmp = vlv_dpio_read(dev_priv, pipe, _CHV_CMN_DW6_CH1);
tmp |= DPIO_DYNPWRDOWNEN_CH1;
vlv_dpio_write(dev_priv, pipe, _CHV_CMN_DW6_CH1, tmp);
} else {
tmp = vlv_dpio_read(dev_priv, pipe, CHV_CMN_DW30);
tmp |= DPIO_CL2_LDOFUSE_PWRENB;
vlv_dpio_write(dev_priv, pipe, CHV_CMN_DW30, tmp);
}
mutex_unlock(&dev_priv->sb_lock);
dev_priv->chv_phy_control |= PHY_COM_LANE_RESET_DEASSERT(phy);
I915_WRITE(DISPLAY_PHY_CONTROL, dev_priv->chv_phy_control);
DRM_DEBUG_KMS("Enabled DPIO PHY%d (PHY_CONTROL=0x%08x)\n",
phy, dev_priv->chv_phy_control);
assert_chv_phy_status(dev_priv);
}
static void chv_dpio_cmn_power_well_disable(struct drm_i915_private *dev_priv,
struct i915_power_well *power_well)
{
enum dpio_phy phy;
WARN_ON_ONCE(power_well->data != PUNIT_POWER_WELL_DPIO_CMN_BC &&
power_well->data != PUNIT_POWER_WELL_DPIO_CMN_D);
if (power_well->data == PUNIT_POWER_WELL_DPIO_CMN_BC) {
phy = DPIO_PHY0;
assert_pll_disabled(dev_priv, PIPE_A);
assert_pll_disabled(dev_priv, PIPE_B);
} else {
phy = DPIO_PHY1;
assert_pll_disabled(dev_priv, PIPE_C);
}
dev_priv->chv_phy_control &= ~PHY_COM_LANE_RESET_DEASSERT(phy);
I915_WRITE(DISPLAY_PHY_CONTROL, dev_priv->chv_phy_control);
vlv_set_power_well(dev_priv, power_well, false);
DRM_DEBUG_KMS("Disabled DPIO PHY%d (PHY_CONTROL=0x%08x)\n",
phy, dev_priv->chv_phy_control);
dev_priv->chv_phy_assert[phy] = true;
assert_chv_phy_status(dev_priv);
}
static void assert_chv_phy_powergate(struct drm_i915_private *dev_priv, enum dpio_phy phy,
enum dpio_channel ch, bool override, unsigned int mask)
{
enum pipe pipe = phy == DPIO_PHY0 ? PIPE_A : PIPE_C;
u32 reg, val, expected, actual;
if (!dev_priv->chv_phy_assert[phy])
return;
if (ch == DPIO_CH0)
reg = _CHV_CMN_DW0_CH0;
else
reg = _CHV_CMN_DW6_CH1;
mutex_lock(&dev_priv->sb_lock);
val = vlv_dpio_read(dev_priv, pipe, reg);
mutex_unlock(&dev_priv->sb_lock);
if (!override || mask == 0xf) {
expected = DPIO_ALLDL_POWERDOWN | DPIO_ANYDL_POWERDOWN;
if (ch == DPIO_CH1 && val == 0)
expected = 0;
} else if (mask != 0x0) {
expected = DPIO_ANYDL_POWERDOWN;
} else {
expected = 0;
}
if (ch == DPIO_CH0)
actual = val >> DPIO_ANYDL_POWERDOWN_SHIFT_CH0;
else
actual = val >> DPIO_ANYDL_POWERDOWN_SHIFT_CH1;
actual &= DPIO_ALLDL_POWERDOWN | DPIO_ANYDL_POWERDOWN;
WARN(actual != expected,
"Unexpected DPIO lane power down: all %d, any %d. Expected: all %d, any %d. (0x%x = 0x%08x)\n",
!!(actual & DPIO_ALLDL_POWERDOWN), !!(actual & DPIO_ANYDL_POWERDOWN),
!!(expected & DPIO_ALLDL_POWERDOWN), !!(expected & DPIO_ANYDL_POWERDOWN),
reg, val);
}
bool chv_phy_powergate_ch(struct drm_i915_private *dev_priv, enum dpio_phy phy,
enum dpio_channel ch, bool override)
{
struct i915_power_domains *power_domains = &dev_priv->power_domains;
bool was_override;
mutex_lock(&power_domains->lock);
was_override = dev_priv->chv_phy_control & PHY_CH_POWER_DOWN_OVRD_EN(phy, ch);
if (override == was_override)
goto out;
if (override)
dev_priv->chv_phy_control |= PHY_CH_POWER_DOWN_OVRD_EN(phy, ch);
else
dev_priv->chv_phy_control &= ~PHY_CH_POWER_DOWN_OVRD_EN(phy, ch);
I915_WRITE(DISPLAY_PHY_CONTROL, dev_priv->chv_phy_control);
DRM_DEBUG_KMS("Power gating DPIO PHY%d CH%d (DPIO_PHY_CONTROL=0x%08x)\n",
phy, ch, dev_priv->chv_phy_control);
assert_chv_phy_status(dev_priv);
out:
mutex_unlock(&power_domains->lock);
return was_override;
}
void chv_phy_powergate_lanes(struct intel_encoder *encoder,
bool override, unsigned int mask)
{
struct drm_i915_private *dev_priv = to_i915(encoder->base.dev);
struct i915_power_domains *power_domains = &dev_priv->power_domains;
enum dpio_phy phy = vlv_dport_to_phy(enc_to_dig_port(&encoder->base));
enum dpio_channel ch = vlv_dport_to_channel(enc_to_dig_port(&encoder->base));
mutex_lock(&power_domains->lock);
dev_priv->chv_phy_control &= ~PHY_CH_POWER_DOWN_OVRD(0xf, phy, ch);
dev_priv->chv_phy_control |= PHY_CH_POWER_DOWN_OVRD(mask, phy, ch);
if (override)
dev_priv->chv_phy_control |= PHY_CH_POWER_DOWN_OVRD_EN(phy, ch);
else
dev_priv->chv_phy_control &= ~PHY_CH_POWER_DOWN_OVRD_EN(phy, ch);
I915_WRITE(DISPLAY_PHY_CONTROL, dev_priv->chv_phy_control);
DRM_DEBUG_KMS("Power gating DPIO PHY%d CH%d lanes 0x%x (PHY_CONTROL=0x%08x)\n",
phy, ch, mask, dev_priv->chv_phy_control);
assert_chv_phy_status(dev_priv);
assert_chv_phy_powergate(dev_priv, phy, ch, override, mask);
mutex_unlock(&power_domains->lock);
}
static bool chv_pipe_power_well_enabled(struct drm_i915_private *dev_priv,
struct i915_power_well *power_well)
{
enum pipe pipe = power_well->data;
bool enabled;
u32 state, ctrl;
mutex_lock(&dev_priv->rps.hw_lock);
state = vlv_punit_read(dev_priv, PUNIT_REG_DSPFREQ) & DP_SSS_MASK(pipe);
WARN_ON(state != DP_SSS_PWR_ON(pipe) && state != DP_SSS_PWR_GATE(pipe));
enabled = state == DP_SSS_PWR_ON(pipe);
ctrl = vlv_punit_read(dev_priv, PUNIT_REG_DSPFREQ) & DP_SSC_MASK(pipe);
WARN_ON(ctrl << 16 != state);
mutex_unlock(&dev_priv->rps.hw_lock);
return enabled;
}
static void chv_set_pipe_power_well(struct drm_i915_private *dev_priv,
struct i915_power_well *power_well,
bool enable)
{
enum pipe pipe = power_well->data;
u32 state;
u32 ctrl;
state = enable ? DP_SSS_PWR_ON(pipe) : DP_SSS_PWR_GATE(pipe);
mutex_lock(&dev_priv->rps.hw_lock);
#define COND \
((vlv_punit_read(dev_priv, PUNIT_REG_DSPFREQ) & DP_SSS_MASK(pipe)) == state)
if (COND)
goto out;
ctrl = vlv_punit_read(dev_priv, PUNIT_REG_DSPFREQ);
ctrl &= ~DP_SSC_MASK(pipe);
ctrl |= enable ? DP_SSC_PWR_ON(pipe) : DP_SSC_PWR_GATE(pipe);
vlv_punit_write(dev_priv, PUNIT_REG_DSPFREQ, ctrl);
if (wait_for(COND, 100))
DRM_ERROR("timeout setting power well state %08x (%08x)\n",
state,
vlv_punit_read(dev_priv, PUNIT_REG_DSPFREQ));
#undef COND
out:
mutex_unlock(&dev_priv->rps.hw_lock);
}
static void chv_pipe_power_well_sync_hw(struct drm_i915_private *dev_priv,
struct i915_power_well *power_well)
{
WARN_ON_ONCE(power_well->data != PIPE_A);
chv_set_pipe_power_well(dev_priv, power_well, power_well->count > 0);
}
static void chv_pipe_power_well_enable(struct drm_i915_private *dev_priv,
struct i915_power_well *power_well)
{
WARN_ON_ONCE(power_well->data != PIPE_A);
chv_set_pipe_power_well(dev_priv, power_well, true);
vlv_display_power_well_init(dev_priv);
}
static void chv_pipe_power_well_disable(struct drm_i915_private *dev_priv,
struct i915_power_well *power_well)
{
WARN_ON_ONCE(power_well->data != PIPE_A);
vlv_display_power_well_deinit(dev_priv);
chv_set_pipe_power_well(dev_priv, power_well, false);
}
static void
__intel_display_power_get_domain(struct drm_i915_private *dev_priv,
enum intel_display_power_domain domain)
{
struct i915_power_domains *power_domains = &dev_priv->power_domains;
struct i915_power_well *power_well;
int i;
for_each_power_well(i, power_well, BIT(domain), power_domains) {
if (!power_well->count++)
intel_power_well_enable(dev_priv, power_well);
}
power_domains->domain_use_count[domain]++;
}
void intel_display_power_get(struct drm_i915_private *dev_priv,
enum intel_display_power_domain domain)
{
struct i915_power_domains *power_domains = &dev_priv->power_domains;
intel_runtime_pm_get(dev_priv);
mutex_lock(&power_domains->lock);
__intel_display_power_get_domain(dev_priv, domain);
mutex_unlock(&power_domains->lock);
}
bool intel_display_power_get_if_enabled(struct drm_i915_private *dev_priv,
enum intel_display_power_domain domain)
{
struct i915_power_domains *power_domains = &dev_priv->power_domains;
bool is_enabled;
if (!intel_runtime_pm_get_if_in_use(dev_priv))
return false;
mutex_lock(&power_domains->lock);
if (__intel_display_power_is_enabled(dev_priv, domain)) {
__intel_display_power_get_domain(dev_priv, domain);
is_enabled = true;
} else {
is_enabled = false;
}
mutex_unlock(&power_domains->lock);
if (!is_enabled)
intel_runtime_pm_put(dev_priv);
return is_enabled;
}
void intel_display_power_put(struct drm_i915_private *dev_priv,
enum intel_display_power_domain domain)
{
struct i915_power_domains *power_domains;
struct i915_power_well *power_well;
int i;
power_domains = &dev_priv->power_domains;
mutex_lock(&power_domains->lock);
WARN(!power_domains->domain_use_count[domain],
"Use count on domain %s is already zero\n",
intel_display_power_domain_str(domain));
power_domains->domain_use_count[domain]--;
for_each_power_well_rev(i, power_well, BIT(domain), power_domains) {
WARN(!power_well->count,
"Use count on power well %s is already zero",
power_well->name);
if (!--power_well->count)
intel_power_well_disable(dev_priv, power_well);
}
mutex_unlock(&power_domains->lock);
intel_runtime_pm_put(dev_priv);
}
bool intel_display_power_well_is_enabled(struct drm_i915_private *dev_priv,
int power_well_id)
{
struct i915_power_well *power_well;
bool ret;
power_well = lookup_power_well(dev_priv, power_well_id);
ret = power_well->ops->is_enabled(dev_priv, power_well);
return ret;
}
static int
sanitize_disable_power_well_option(const struct drm_i915_private *dev_priv,
int disable_power_well)
{
if (disable_power_well >= 0)
return !!disable_power_well;
return 1;
}
static uint32_t get_allowed_dc_mask(const struct drm_i915_private *dev_priv,
int enable_dc)
{
uint32_t mask;
int requested_dc;
int max_dc;
if (IS_SKYLAKE(dev_priv) || IS_KABYLAKE(dev_priv)) {
max_dc = 2;
mask = 0;
} else if (IS_BROXTON(dev_priv)) {
max_dc = 1;
mask = DC_STATE_EN_DC9;
} else {
max_dc = 0;
mask = 0;
}
if (!i915.disable_power_well)
max_dc = 0;
if (enable_dc >= 0 && enable_dc <= max_dc) {
requested_dc = enable_dc;
} else if (enable_dc == -1) {
requested_dc = max_dc;
} else if (enable_dc > max_dc && enable_dc <= 2) {
DRM_DEBUG_KMS("Adjusting requested max DC state (%d->%d)\n",
enable_dc, max_dc);
requested_dc = max_dc;
} else {
DRM_ERROR("Unexpected value for enable_dc (%d)\n", enable_dc);
requested_dc = max_dc;
}
if (requested_dc > 1)
mask |= DC_STATE_EN_UPTO_DC6;
if (requested_dc > 0)
mask |= DC_STATE_EN_UPTO_DC5;
DRM_DEBUG_KMS("Allowed DC state mask %02x\n", mask);
return mask;
}
int intel_power_domains_init(struct drm_i915_private *dev_priv)
{
struct i915_power_domains *power_domains = &dev_priv->power_domains;
i915.disable_power_well = sanitize_disable_power_well_option(dev_priv,
i915.disable_power_well);
dev_priv->csr.allowed_dc_mask = get_allowed_dc_mask(dev_priv,
i915.enable_dc);
BUILD_BUG_ON(POWER_DOMAIN_NUM > 31);
mutex_init(&power_domains->lock);
if (IS_HASWELL(dev_priv)) {
set_power_wells(power_domains, hsw_power_wells);
} else if (IS_BROADWELL(dev_priv)) {
set_power_wells(power_domains, bdw_power_wells);
} else if (IS_SKYLAKE(dev_priv) || IS_KABYLAKE(dev_priv)) {
set_power_wells(power_domains, skl_power_wells);
} else if (IS_BROXTON(dev_priv)) {
set_power_wells(power_domains, bxt_power_wells);
} else if (IS_CHERRYVIEW(dev_priv)) {
set_power_wells(power_domains, chv_power_wells);
} else if (IS_VALLEYVIEW(dev_priv)) {
set_power_wells(power_domains, vlv_power_wells);
} else {
set_power_wells(power_domains, i9xx_always_on_power_well);
}
return 0;
}
void intel_power_domains_fini(struct drm_i915_private *dev_priv)
{
struct device *device = &dev_priv->dev->pdev->dev;
intel_display_set_init_power(dev_priv, true);
if (!i915.disable_power_well)
intel_display_power_put(dev_priv, POWER_DOMAIN_INIT);
if (!HAS_RUNTIME_PM(dev_priv))
pm_runtime_put(device);
}
static void intel_power_domains_sync_hw(struct drm_i915_private *dev_priv)
{
struct i915_power_domains *power_domains = &dev_priv->power_domains;
struct i915_power_well *power_well;
int i;
mutex_lock(&power_domains->lock);
for_each_power_well(i, power_well, POWER_DOMAIN_MASK, power_domains) {
power_well->ops->sync_hw(dev_priv, power_well);
power_well->hw_enabled = power_well->ops->is_enabled(dev_priv,
power_well);
}
mutex_unlock(&power_domains->lock);
}
static void skl_display_core_init(struct drm_i915_private *dev_priv,
bool resume)
{
struct i915_power_domains *power_domains = &dev_priv->power_domains;
struct i915_power_well *well;
uint32_t val;
gen9_set_dc_state(dev_priv, DC_STATE_DISABLE);
val = I915_READ(HSW_NDE_RSTWRN_OPT);
I915_WRITE(HSW_NDE_RSTWRN_OPT, val | RESET_PCH_HANDSHAKE_ENABLE);
mutex_lock(&power_domains->lock);
well = lookup_power_well(dev_priv, SKL_DISP_PW_1);
intel_power_well_enable(dev_priv, well);
well = lookup_power_well(dev_priv, SKL_DISP_PW_MISC_IO);
intel_power_well_enable(dev_priv, well);
mutex_unlock(&power_domains->lock);
if (!resume)
return;
skl_init_cdclk(dev_priv);
if (dev_priv->csr.dmc_payload)
intel_csr_load_program(dev_priv);
}
static void skl_display_core_uninit(struct drm_i915_private *dev_priv)
{
struct i915_power_domains *power_domains = &dev_priv->power_domains;
struct i915_power_well *well;
gen9_set_dc_state(dev_priv, DC_STATE_DISABLE);
skl_uninit_cdclk(dev_priv);
mutex_lock(&power_domains->lock);
well = lookup_power_well(dev_priv, SKL_DISP_PW_MISC_IO);
intel_power_well_disable(dev_priv, well);
well = lookup_power_well(dev_priv, SKL_DISP_PW_1);
intel_power_well_disable(dev_priv, well);
mutex_unlock(&power_domains->lock);
}
void bxt_display_core_init(struct drm_i915_private *dev_priv,
bool resume)
{
struct i915_power_domains *power_domains = &dev_priv->power_domains;
struct i915_power_well *well;
uint32_t val;
gen9_set_dc_state(dev_priv, DC_STATE_DISABLE);
val = I915_READ(HSW_NDE_RSTWRN_OPT);
val &= ~RESET_PCH_HANDSHAKE_ENABLE;
I915_WRITE(HSW_NDE_RSTWRN_OPT, val);
mutex_lock(&power_domains->lock);
well = lookup_power_well(dev_priv, SKL_DISP_PW_1);
intel_power_well_enable(dev_priv, well);
mutex_unlock(&power_domains->lock);
broxton_init_cdclk(dev_priv);
broxton_ddi_phy_init(dev_priv);
broxton_cdclk_verify_state(dev_priv);
broxton_ddi_phy_verify_state(dev_priv);
if (resume && dev_priv->csr.dmc_payload)
intel_csr_load_program(dev_priv);
}
void bxt_display_core_uninit(struct drm_i915_private *dev_priv)
{
struct i915_power_domains *power_domains = &dev_priv->power_domains;
struct i915_power_well *well;
gen9_set_dc_state(dev_priv, DC_STATE_DISABLE);
broxton_ddi_phy_uninit(dev_priv);
broxton_uninit_cdclk(dev_priv);
mutex_lock(&power_domains->lock);
well = lookup_power_well(dev_priv, SKL_DISP_PW_1);
intel_power_well_disable(dev_priv, well);
mutex_unlock(&power_domains->lock);
}
static void chv_phy_control_init(struct drm_i915_private *dev_priv)
{
struct i915_power_well *cmn_bc =
lookup_power_well(dev_priv, PUNIT_POWER_WELL_DPIO_CMN_BC);
struct i915_power_well *cmn_d =
lookup_power_well(dev_priv, PUNIT_POWER_WELL_DPIO_CMN_D);
dev_priv->chv_phy_control =
PHY_LDO_SEQ_DELAY(PHY_LDO_DELAY_600NS, DPIO_PHY0) |
PHY_LDO_SEQ_DELAY(PHY_LDO_DELAY_600NS, DPIO_PHY1) |
PHY_CH_POWER_MODE(PHY_CH_DEEP_PSR, DPIO_PHY0, DPIO_CH0) |
PHY_CH_POWER_MODE(PHY_CH_DEEP_PSR, DPIO_PHY0, DPIO_CH1) |
PHY_CH_POWER_MODE(PHY_CH_DEEP_PSR, DPIO_PHY1, DPIO_CH0);
if (cmn_bc->ops->is_enabled(dev_priv, cmn_bc)) {
uint32_t status = I915_READ(DPLL(PIPE_A));
unsigned int mask;
mask = status & DPLL_PORTB_READY_MASK;
if (mask == 0xf)
mask = 0x0;
else
dev_priv->chv_phy_control |=
PHY_CH_POWER_DOWN_OVRD_EN(DPIO_PHY0, DPIO_CH0);
dev_priv->chv_phy_control |=
PHY_CH_POWER_DOWN_OVRD(mask, DPIO_PHY0, DPIO_CH0);
mask = (status & DPLL_PORTC_READY_MASK) >> 4;
if (mask == 0xf)
mask = 0x0;
else
dev_priv->chv_phy_control |=
PHY_CH_POWER_DOWN_OVRD_EN(DPIO_PHY0, DPIO_CH1);
dev_priv->chv_phy_control |=
PHY_CH_POWER_DOWN_OVRD(mask, DPIO_PHY0, DPIO_CH1);
dev_priv->chv_phy_control |= PHY_COM_LANE_RESET_DEASSERT(DPIO_PHY0);
dev_priv->chv_phy_assert[DPIO_PHY0] = false;
} else {
dev_priv->chv_phy_assert[DPIO_PHY0] = true;
}
if (cmn_d->ops->is_enabled(dev_priv, cmn_d)) {
uint32_t status = I915_READ(DPIO_PHY_STATUS);
unsigned int mask;
mask = status & DPLL_PORTD_READY_MASK;
if (mask == 0xf)
mask = 0x0;
else
dev_priv->chv_phy_control |=
PHY_CH_POWER_DOWN_OVRD_EN(DPIO_PHY1, DPIO_CH0);
dev_priv->chv_phy_control |=
PHY_CH_POWER_DOWN_OVRD(mask, DPIO_PHY1, DPIO_CH0);
dev_priv->chv_phy_control |= PHY_COM_LANE_RESET_DEASSERT(DPIO_PHY1);
dev_priv->chv_phy_assert[DPIO_PHY1] = false;
} else {
dev_priv->chv_phy_assert[DPIO_PHY1] = true;
}
I915_WRITE(DISPLAY_PHY_CONTROL, dev_priv->chv_phy_control);
DRM_DEBUG_KMS("Initial PHY_CONTROL=0x%08x\n",
dev_priv->chv_phy_control);
}
static void vlv_cmnlane_wa(struct drm_i915_private *dev_priv)
{
struct i915_power_well *cmn =
lookup_power_well(dev_priv, PUNIT_POWER_WELL_DPIO_CMN_BC);
struct i915_power_well *disp2d =
lookup_power_well(dev_priv, PUNIT_POWER_WELL_DISP2D);
if (cmn->ops->is_enabled(dev_priv, cmn) &&
disp2d->ops->is_enabled(dev_priv, disp2d) &&
I915_READ(DPIO_CTL) & DPIO_CMNRST)
return;
DRM_DEBUG_KMS("toggling display PHY side reset\n");
disp2d->ops->enable(dev_priv, disp2d);
cmn->ops->disable(dev_priv, cmn);
}
void intel_power_domains_init_hw(struct drm_i915_private *dev_priv, bool resume)
{
struct drm_device *dev = dev_priv->dev;
struct i915_power_domains *power_domains = &dev_priv->power_domains;
power_domains->initializing = true;
if (IS_SKYLAKE(dev) || IS_KABYLAKE(dev)) {
skl_display_core_init(dev_priv, resume);
} else if (IS_BROXTON(dev)) {
bxt_display_core_init(dev_priv, resume);
} else if (IS_CHERRYVIEW(dev)) {
mutex_lock(&power_domains->lock);
chv_phy_control_init(dev_priv);
mutex_unlock(&power_domains->lock);
} else if (IS_VALLEYVIEW(dev)) {
mutex_lock(&power_domains->lock);
vlv_cmnlane_wa(dev_priv);
mutex_unlock(&power_domains->lock);
}
intel_display_set_init_power(dev_priv, true);
if (!i915.disable_power_well)
intel_display_power_get(dev_priv, POWER_DOMAIN_INIT);
intel_power_domains_sync_hw(dev_priv);
power_domains->initializing = false;
}
void intel_power_domains_suspend(struct drm_i915_private *dev_priv)
{
if (!i915.disable_power_well)
intel_display_power_put(dev_priv, POWER_DOMAIN_INIT);
if (IS_SKYLAKE(dev_priv) || IS_KABYLAKE(dev_priv))
skl_display_core_uninit(dev_priv);
else if (IS_BROXTON(dev_priv))
bxt_display_core_uninit(dev_priv);
}
void intel_runtime_pm_get(struct drm_i915_private *dev_priv)
{
struct drm_device *dev = dev_priv->dev;
struct device *device = &dev->pdev->dev;
pm_runtime_get_sync(device);
atomic_inc(&dev_priv->pm.wakeref_count);
assert_rpm_wakelock_held(dev_priv);
}
bool intel_runtime_pm_get_if_in_use(struct drm_i915_private *dev_priv)
{
struct drm_device *dev = dev_priv->dev;
struct device *device = &dev->pdev->dev;
if (IS_ENABLED(CONFIG_PM)) {
int ret = pm_runtime_get_if_in_use(device);
WARN_ON_ONCE(ret < 0);
if (ret <= 0)
return false;
}
atomic_inc(&dev_priv->pm.wakeref_count);
assert_rpm_wakelock_held(dev_priv);
return true;
}
void intel_runtime_pm_get_noresume(struct drm_i915_private *dev_priv)
{
struct drm_device *dev = dev_priv->dev;
struct device *device = &dev->pdev->dev;
assert_rpm_wakelock_held(dev_priv);
pm_runtime_get_noresume(device);
atomic_inc(&dev_priv->pm.wakeref_count);
}
void intel_runtime_pm_put(struct drm_i915_private *dev_priv)
{
struct drm_device *dev = dev_priv->dev;
struct device *device = &dev->pdev->dev;
assert_rpm_wakelock_held(dev_priv);
if (atomic_dec_and_test(&dev_priv->pm.wakeref_count))
atomic_inc(&dev_priv->pm.atomic_seq);
pm_runtime_mark_last_busy(device);
pm_runtime_put_autosuspend(device);
}
void intel_runtime_pm_enable(struct drm_i915_private *dev_priv)
{
struct drm_device *dev = dev_priv->dev;
struct device *device = &dev->pdev->dev;
pm_runtime_set_autosuspend_delay(device, 10000);
pm_runtime_mark_last_busy(device);
if (!HAS_RUNTIME_PM(dev)) {
pm_runtime_dont_use_autosuspend(device);
pm_runtime_get_sync(device);
} else {
pm_runtime_use_autosuspend(device);
}
pm_runtime_put_autosuspend(device);
}
