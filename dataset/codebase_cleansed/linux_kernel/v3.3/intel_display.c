static inline u32
intel_fdi_link_freq(struct drm_device *dev)
{
if (IS_GEN5(dev)) {
struct drm_i915_private *dev_priv = dev->dev_private;
return (I915_READ(FDI_PLL_BIOS_0) & FDI_PLL_FB_CLOCK_MASK) + 2;
} else
return 27;
}
static const intel_limit_t *intel_ironlake_limit(struct drm_crtc *crtc,
int refclk)
{
struct drm_device *dev = crtc->dev;
struct drm_i915_private *dev_priv = dev->dev_private;
const intel_limit_t *limit;
if (intel_pipe_has_type(crtc, INTEL_OUTPUT_LVDS)) {
if ((I915_READ(PCH_LVDS) & LVDS_CLKB_POWER_MASK) ==
LVDS_CLKB_POWER_UP) {
if (refclk == 100000)
limit = &intel_limits_ironlake_dual_lvds_100m;
else
limit = &intel_limits_ironlake_dual_lvds;
} else {
if (refclk == 100000)
limit = &intel_limits_ironlake_single_lvds_100m;
else
limit = &intel_limits_ironlake_single_lvds;
}
} else if (intel_pipe_has_type(crtc, INTEL_OUTPUT_DISPLAYPORT) ||
HAS_eDP)
limit = &intel_limits_ironlake_display_port;
else
limit = &intel_limits_ironlake_dac;
return limit;
}
static const intel_limit_t *intel_g4x_limit(struct drm_crtc *crtc)
{
struct drm_device *dev = crtc->dev;
struct drm_i915_private *dev_priv = dev->dev_private;
const intel_limit_t *limit;
if (intel_pipe_has_type(crtc, INTEL_OUTPUT_LVDS)) {
if ((I915_READ(LVDS) & LVDS_CLKB_POWER_MASK) ==
LVDS_CLKB_POWER_UP)
limit = &intel_limits_g4x_dual_channel_lvds;
else
limit = &intel_limits_g4x_single_channel_lvds;
} else if (intel_pipe_has_type(crtc, INTEL_OUTPUT_HDMI) ||
intel_pipe_has_type(crtc, INTEL_OUTPUT_ANALOG)) {
limit = &intel_limits_g4x_hdmi;
} else if (intel_pipe_has_type(crtc, INTEL_OUTPUT_SDVO)) {
limit = &intel_limits_g4x_sdvo;
} else if (intel_pipe_has_type(crtc, INTEL_OUTPUT_DISPLAYPORT)) {
limit = &intel_limits_g4x_display_port;
} else
limit = &intel_limits_i9xx_sdvo;
return limit;
}
static const intel_limit_t *intel_limit(struct drm_crtc *crtc, int refclk)
{
struct drm_device *dev = crtc->dev;
const intel_limit_t *limit;
if (HAS_PCH_SPLIT(dev))
limit = intel_ironlake_limit(crtc, refclk);
else if (IS_G4X(dev)) {
limit = intel_g4x_limit(crtc);
} else if (IS_PINEVIEW(dev)) {
if (intel_pipe_has_type(crtc, INTEL_OUTPUT_LVDS))
limit = &intel_limits_pineview_lvds;
else
limit = &intel_limits_pineview_sdvo;
} else if (!IS_GEN2(dev)) {
if (intel_pipe_has_type(crtc, INTEL_OUTPUT_LVDS))
limit = &intel_limits_i9xx_lvds;
else
limit = &intel_limits_i9xx_sdvo;
} else {
if (intel_pipe_has_type(crtc, INTEL_OUTPUT_LVDS))
limit = &intel_limits_i8xx_lvds;
else
limit = &intel_limits_i8xx_dvo;
}
return limit;
}
static void pineview_clock(int refclk, intel_clock_t *clock)
{
clock->m = clock->m2 + 2;
clock->p = clock->p1 * clock->p2;
clock->vco = refclk * clock->m / clock->n;
clock->dot = clock->vco / clock->p;
}
static void intel_clock(struct drm_device *dev, int refclk, intel_clock_t *clock)
{
if (IS_PINEVIEW(dev)) {
pineview_clock(refclk, clock);
return;
}
clock->m = 5 * (clock->m1 + 2) + (clock->m2 + 2);
clock->p = clock->p1 * clock->p2;
clock->vco = refclk * clock->m / (clock->n + 2);
clock->dot = clock->vco / clock->p;
}
bool intel_pipe_has_type(struct drm_crtc *crtc, int type)
{
struct drm_device *dev = crtc->dev;
struct drm_mode_config *mode_config = &dev->mode_config;
struct intel_encoder *encoder;
list_for_each_entry(encoder, &mode_config->encoder_list, base.head)
if (encoder->base.crtc == crtc && encoder->type == type)
return true;
return false;
}
static bool intel_PLL_is_valid(struct drm_device *dev,
const intel_limit_t *limit,
const intel_clock_t *clock)
{
if (clock->p1 < limit->p1.min || limit->p1.max < clock->p1)
INTELPllInvalid("p1 out of range\n");
if (clock->p < limit->p.min || limit->p.max < clock->p)
INTELPllInvalid("p out of range\n");
if (clock->m2 < limit->m2.min || limit->m2.max < clock->m2)
INTELPllInvalid("m2 out of range\n");
if (clock->m1 < limit->m1.min || limit->m1.max < clock->m1)
INTELPllInvalid("m1 out of range\n");
if (clock->m1 <= clock->m2 && !IS_PINEVIEW(dev))
INTELPllInvalid("m1 <= m2\n");
if (clock->m < limit->m.min || limit->m.max < clock->m)
INTELPllInvalid("m out of range\n");
if (clock->n < limit->n.min || limit->n.max < clock->n)
INTELPllInvalid("n out of range\n");
if (clock->vco < limit->vco.min || limit->vco.max < clock->vco)
INTELPllInvalid("vco out of range\n");
if (clock->dot < limit->dot.min || limit->dot.max < clock->dot)
INTELPllInvalid("dot out of range\n");
return true;
}
static bool
intel_find_best_PLL(const intel_limit_t *limit, struct drm_crtc *crtc,
int target, int refclk, intel_clock_t *best_clock)
{
struct drm_device *dev = crtc->dev;
struct drm_i915_private *dev_priv = dev->dev_private;
intel_clock_t clock;
int err = target;
if (intel_pipe_has_type(crtc, INTEL_OUTPUT_LVDS) &&
(I915_READ(LVDS)) != 0) {
if ((I915_READ(LVDS) & LVDS_CLKB_POWER_MASK) ==
LVDS_CLKB_POWER_UP)
clock.p2 = limit->p2.p2_fast;
else
clock.p2 = limit->p2.p2_slow;
} else {
if (target < limit->p2.dot_limit)
clock.p2 = limit->p2.p2_slow;
else
clock.p2 = limit->p2.p2_fast;
}
memset(best_clock, 0, sizeof(*best_clock));
for (clock.m1 = limit->m1.min; clock.m1 <= limit->m1.max;
clock.m1++) {
for (clock.m2 = limit->m2.min;
clock.m2 <= limit->m2.max; clock.m2++) {
if (clock.m2 >= clock.m1 && !IS_PINEVIEW(dev))
break;
for (clock.n = limit->n.min;
clock.n <= limit->n.max; clock.n++) {
for (clock.p1 = limit->p1.min;
clock.p1 <= limit->p1.max; clock.p1++) {
int this_err;
intel_clock(dev, refclk, &clock);
if (!intel_PLL_is_valid(dev, limit,
&clock))
continue;
this_err = abs(clock.dot - target);
if (this_err < err) {
*best_clock = clock;
err = this_err;
}
}
}
}
}
return (err != target);
}
static bool
intel_g4x_find_best_PLL(const intel_limit_t *limit, struct drm_crtc *crtc,
int target, int refclk, intel_clock_t *best_clock)
{
struct drm_device *dev = crtc->dev;
struct drm_i915_private *dev_priv = dev->dev_private;
intel_clock_t clock;
int max_n;
bool found;
int err_most = (target >> 8) + (target >> 9);
found = false;
if (intel_pipe_has_type(crtc, INTEL_OUTPUT_LVDS)) {
int lvds_reg;
if (HAS_PCH_SPLIT(dev))
lvds_reg = PCH_LVDS;
else
lvds_reg = LVDS;
if ((I915_READ(lvds_reg) & LVDS_CLKB_POWER_MASK) ==
LVDS_CLKB_POWER_UP)
clock.p2 = limit->p2.p2_fast;
else
clock.p2 = limit->p2.p2_slow;
} else {
if (target < limit->p2.dot_limit)
clock.p2 = limit->p2.p2_slow;
else
clock.p2 = limit->p2.p2_fast;
}
memset(best_clock, 0, sizeof(*best_clock));
max_n = limit->n.max;
for (clock.n = limit->n.min; clock.n <= max_n; clock.n++) {
for (clock.m1 = limit->m1.max;
clock.m1 >= limit->m1.min; clock.m1--) {
for (clock.m2 = limit->m2.max;
clock.m2 >= limit->m2.min; clock.m2--) {
for (clock.p1 = limit->p1.max;
clock.p1 >= limit->p1.min; clock.p1--) {
int this_err;
intel_clock(dev, refclk, &clock);
if (!intel_PLL_is_valid(dev, limit,
&clock))
continue;
this_err = abs(clock.dot - target);
if (this_err < err_most) {
*best_clock = clock;
err_most = this_err;
max_n = clock.n;
found = true;
}
}
}
}
}
return found;
}
static bool
intel_find_pll_ironlake_dp(const intel_limit_t *limit, struct drm_crtc *crtc,
int target, int refclk, intel_clock_t *best_clock)
{
struct drm_device *dev = crtc->dev;
intel_clock_t clock;
if (target < 200000) {
clock.n = 1;
clock.p1 = 2;
clock.p2 = 10;
clock.m1 = 12;
clock.m2 = 9;
} else {
clock.n = 2;
clock.p1 = 1;
clock.p2 = 10;
clock.m1 = 14;
clock.m2 = 8;
}
intel_clock(dev, refclk, &clock);
memcpy(best_clock, &clock, sizeof(intel_clock_t));
return true;
}
static bool
intel_find_pll_g4x_dp(const intel_limit_t *limit, struct drm_crtc *crtc,
int target, int refclk, intel_clock_t *best_clock)
{
intel_clock_t clock;
if (target < 200000) {
clock.p1 = 2;
clock.p2 = 10;
clock.n = 2;
clock.m1 = 23;
clock.m2 = 8;
} else {
clock.p1 = 1;
clock.p2 = 10;
clock.n = 1;
clock.m1 = 14;
clock.m2 = 2;
}
clock.m = 5 * (clock.m1 + 2) + (clock.m2 + 2);
clock.p = (clock.p1 * clock.p2);
clock.dot = 96000 * clock.m / (clock.n + 2) / clock.p;
clock.vco = 0;
memcpy(best_clock, &clock, sizeof(intel_clock_t));
return true;
}
void intel_wait_for_vblank(struct drm_device *dev, int pipe)
{
struct drm_i915_private *dev_priv = dev->dev_private;
int pipestat_reg = PIPESTAT(pipe);
I915_WRITE(pipestat_reg,
I915_READ(pipestat_reg) | PIPE_VBLANK_INTERRUPT_STATUS);
if (wait_for(I915_READ(pipestat_reg) &
PIPE_VBLANK_INTERRUPT_STATUS,
50))
DRM_DEBUG_KMS("vblank wait timed out\n");
}
void intel_wait_for_pipe_off(struct drm_device *dev, int pipe)
{
struct drm_i915_private *dev_priv = dev->dev_private;
if (INTEL_INFO(dev)->gen >= 4) {
int reg = PIPECONF(pipe);
if (wait_for((I915_READ(reg) & I965_PIPECONF_ACTIVE) == 0,
100))
DRM_DEBUG_KMS("pipe_off wait timed out\n");
} else {
u32 last_line;
int reg = PIPEDSL(pipe);
unsigned long timeout = jiffies + msecs_to_jiffies(100);
do {
last_line = I915_READ(reg) & DSL_LINEMASK;
mdelay(5);
} while (((I915_READ(reg) & DSL_LINEMASK) != last_line) &&
time_after(timeout, jiffies));
if (time_after(jiffies, timeout))
DRM_DEBUG_KMS("pipe_off wait timed out\n");
}
}
static const char *state_string(bool enabled)
{
return enabled ? "on" : "off";
}
static void assert_pll(struct drm_i915_private *dev_priv,
enum pipe pipe, bool state)
{
int reg;
u32 val;
bool cur_state;
reg = DPLL(pipe);
val = I915_READ(reg);
cur_state = !!(val & DPLL_VCO_ENABLE);
WARN(cur_state != state,
"PLL state assertion failure (expected %s, current %s)\n",
state_string(state), state_string(cur_state));
}
static void assert_pch_pll(struct drm_i915_private *dev_priv,
enum pipe pipe, bool state)
{
int reg;
u32 val;
bool cur_state;
if (HAS_PCH_CPT(dev_priv->dev)) {
u32 pch_dpll;
pch_dpll = I915_READ(PCH_DPLL_SEL);
WARN(!((pch_dpll >> (4 * pipe)) & 8),
"transcoder %d PLL not enabled\n", pipe);
pipe = (pch_dpll >> (4 * pipe)) & 1;
}
reg = PCH_DPLL(pipe);
val = I915_READ(reg);
cur_state = !!(val & DPLL_VCO_ENABLE);
WARN(cur_state != state,
"PCH PLL state assertion failure (expected %s, current %s)\n",
state_string(state), state_string(cur_state));
}
static void assert_fdi_tx(struct drm_i915_private *dev_priv,
enum pipe pipe, bool state)
{
int reg;
u32 val;
bool cur_state;
reg = FDI_TX_CTL(pipe);
val = I915_READ(reg);
cur_state = !!(val & FDI_TX_ENABLE);
WARN(cur_state != state,
"FDI TX state assertion failure (expected %s, current %s)\n",
state_string(state), state_string(cur_state));
}
static void assert_fdi_rx(struct drm_i915_private *dev_priv,
enum pipe pipe, bool state)
{
int reg;
u32 val;
bool cur_state;
reg = FDI_RX_CTL(pipe);
val = I915_READ(reg);
cur_state = !!(val & FDI_RX_ENABLE);
WARN(cur_state != state,
"FDI RX state assertion failure (expected %s, current %s)\n",
state_string(state), state_string(cur_state));
}
static void assert_fdi_tx_pll_enabled(struct drm_i915_private *dev_priv,
enum pipe pipe)
{
int reg;
u32 val;
if (dev_priv->info->gen == 5)
return;
reg = FDI_TX_CTL(pipe);
val = I915_READ(reg);
WARN(!(val & FDI_TX_PLL_ENABLE), "FDI TX PLL assertion failure, should be active but is disabled\n");
}
static void assert_fdi_rx_pll_enabled(struct drm_i915_private *dev_priv,
enum pipe pipe)
{
int reg;
u32 val;
reg = FDI_RX_CTL(pipe);
val = I915_READ(reg);
WARN(!(val & FDI_RX_PLL_ENABLE), "FDI RX PLL assertion failure, should be active but is disabled\n");
}
static void assert_panel_unlocked(struct drm_i915_private *dev_priv,
enum pipe pipe)
{
int pp_reg, lvds_reg;
u32 val;
enum pipe panel_pipe = PIPE_A;
bool locked = true;
if (HAS_PCH_SPLIT(dev_priv->dev)) {
pp_reg = PCH_PP_CONTROL;
lvds_reg = PCH_LVDS;
} else {
pp_reg = PP_CONTROL;
lvds_reg = LVDS;
}
val = I915_READ(pp_reg);
if (!(val & PANEL_POWER_ON) ||
((val & PANEL_UNLOCK_REGS) == PANEL_UNLOCK_REGS))
locked = false;
if (I915_READ(lvds_reg) & LVDS_PIPEB_SELECT)
panel_pipe = PIPE_B;
WARN(panel_pipe == pipe && locked,
"panel assertion failure, pipe %c regs locked\n",
pipe_name(pipe));
}
void assert_pipe(struct drm_i915_private *dev_priv,
enum pipe pipe, bool state)
{
int reg;
u32 val;
bool cur_state;
reg = PIPECONF(pipe);
val = I915_READ(reg);
cur_state = !!(val & PIPECONF_ENABLE);
WARN(cur_state != state,
"pipe %c assertion failure (expected %s, current %s)\n",
pipe_name(pipe), state_string(state), state_string(cur_state));
}
static void assert_plane_enabled(struct drm_i915_private *dev_priv,
enum plane plane)
{
int reg;
u32 val;
reg = DSPCNTR(plane);
val = I915_READ(reg);
WARN(!(val & DISPLAY_PLANE_ENABLE),
"plane %c assertion failure, should be active but is disabled\n",
plane_name(plane));
}
static void assert_planes_disabled(struct drm_i915_private *dev_priv,
enum pipe pipe)
{
int reg, i;
u32 val;
int cur_pipe;
if (HAS_PCH_SPLIT(dev_priv->dev))
return;
for (i = 0; i < 2; i++) {
reg = DSPCNTR(i);
val = I915_READ(reg);
cur_pipe = (val & DISPPLANE_SEL_PIPE_MASK) >>
DISPPLANE_SEL_PIPE_SHIFT;
WARN((val & DISPLAY_PLANE_ENABLE) && pipe == cur_pipe,
"plane %c assertion failure, should be off on pipe %c but is still active\n",
plane_name(i), pipe_name(pipe));
}
}
static void assert_pch_refclk_enabled(struct drm_i915_private *dev_priv)
{
u32 val;
bool enabled;
val = I915_READ(PCH_DREF_CONTROL);
enabled = !!(val & (DREF_SSC_SOURCE_MASK | DREF_NONSPREAD_SOURCE_MASK |
DREF_SUPERSPREAD_SOURCE_MASK));
WARN(!enabled, "PCH refclk assertion failure, should be active but is disabled\n");
}
static void assert_transcoder_disabled(struct drm_i915_private *dev_priv,
enum pipe pipe)
{
int reg;
u32 val;
bool enabled;
reg = TRANSCONF(pipe);
val = I915_READ(reg);
enabled = !!(val & TRANS_ENABLE);
WARN(enabled,
"transcoder assertion failed, should be off on pipe %c but is still active\n",
pipe_name(pipe));
}
static bool dp_pipe_enabled(struct drm_i915_private *dev_priv,
enum pipe pipe, u32 port_sel, u32 val)
{
if ((val & DP_PORT_EN) == 0)
return false;
if (HAS_PCH_CPT(dev_priv->dev)) {
u32 trans_dp_ctl_reg = TRANS_DP_CTL(pipe);
u32 trans_dp_ctl = I915_READ(trans_dp_ctl_reg);
if ((trans_dp_ctl & TRANS_DP_PORT_SEL_MASK) != port_sel)
return false;
} else {
if ((val & DP_PIPE_MASK) != (pipe << 30))
return false;
}
return true;
}
static bool hdmi_pipe_enabled(struct drm_i915_private *dev_priv,
enum pipe pipe, u32 val)
{
if ((val & PORT_ENABLE) == 0)
return false;
if (HAS_PCH_CPT(dev_priv->dev)) {
if ((val & PORT_TRANS_SEL_MASK) != PORT_TRANS_SEL_CPT(pipe))
return false;
} else {
if ((val & TRANSCODER_MASK) != TRANSCODER(pipe))
return false;
}
return true;
}
static bool lvds_pipe_enabled(struct drm_i915_private *dev_priv,
enum pipe pipe, u32 val)
{
if ((val & LVDS_PORT_EN) == 0)
return false;
if (HAS_PCH_CPT(dev_priv->dev)) {
if ((val & PORT_TRANS_SEL_MASK) != PORT_TRANS_SEL_CPT(pipe))
return false;
} else {
if ((val & LVDS_PIPE_MASK) != LVDS_PIPE(pipe))
return false;
}
return true;
}
static bool adpa_pipe_enabled(struct drm_i915_private *dev_priv,
enum pipe pipe, u32 val)
{
if ((val & ADPA_DAC_ENABLE) == 0)
return false;
if (HAS_PCH_CPT(dev_priv->dev)) {
if ((val & PORT_TRANS_SEL_MASK) != PORT_TRANS_SEL_CPT(pipe))
return false;
} else {
if ((val & ADPA_PIPE_SELECT_MASK) != ADPA_PIPE_SELECT(pipe))
return false;
}
return true;
}
static void assert_pch_dp_disabled(struct drm_i915_private *dev_priv,
enum pipe pipe, int reg, u32 port_sel)
{
u32 val = I915_READ(reg);
WARN(dp_pipe_enabled(dev_priv, pipe, port_sel, val),
"PCH DP (0x%08x) enabled on transcoder %c, should be disabled\n",
reg, pipe_name(pipe));
}
static void assert_pch_hdmi_disabled(struct drm_i915_private *dev_priv,
enum pipe pipe, int reg)
{
u32 val = I915_READ(reg);
WARN(hdmi_pipe_enabled(dev_priv, val, pipe),
"PCH DP (0x%08x) enabled on transcoder %c, should be disabled\n",
reg, pipe_name(pipe));
}
static void assert_pch_ports_disabled(struct drm_i915_private *dev_priv,
enum pipe pipe)
{
int reg;
u32 val;
assert_pch_dp_disabled(dev_priv, pipe, PCH_DP_B, TRANS_DP_PORT_SEL_B);
assert_pch_dp_disabled(dev_priv, pipe, PCH_DP_C, TRANS_DP_PORT_SEL_C);
assert_pch_dp_disabled(dev_priv, pipe, PCH_DP_D, TRANS_DP_PORT_SEL_D);
reg = PCH_ADPA;
val = I915_READ(reg);
WARN(adpa_pipe_enabled(dev_priv, val, pipe),
"PCH VGA enabled on transcoder %c, should be disabled\n",
pipe_name(pipe));
reg = PCH_LVDS;
val = I915_READ(reg);
WARN(lvds_pipe_enabled(dev_priv, val, pipe),
"PCH LVDS enabled on transcoder %c, should be disabled\n",
pipe_name(pipe));
assert_pch_hdmi_disabled(dev_priv, pipe, HDMIB);
assert_pch_hdmi_disabled(dev_priv, pipe, HDMIC);
assert_pch_hdmi_disabled(dev_priv, pipe, HDMID);
}
static void intel_enable_pll(struct drm_i915_private *dev_priv, enum pipe pipe)
{
int reg;
u32 val;
BUG_ON(dev_priv->info->gen >= 5);
if (IS_MOBILE(dev_priv->dev) && !IS_I830(dev_priv->dev))
assert_panel_unlocked(dev_priv, pipe);
reg = DPLL(pipe);
val = I915_READ(reg);
val |= DPLL_VCO_ENABLE;
I915_WRITE(reg, val);
POSTING_READ(reg);
udelay(150);
I915_WRITE(reg, val);
POSTING_READ(reg);
udelay(150);
I915_WRITE(reg, val);
POSTING_READ(reg);
udelay(150);
}
static void intel_disable_pll(struct drm_i915_private *dev_priv, enum pipe pipe)
{
int reg;
u32 val;
if (pipe == PIPE_A && (dev_priv->quirks & QUIRK_PIPEA_FORCE))
return;
assert_pipe_disabled(dev_priv, pipe);
reg = DPLL(pipe);
val = I915_READ(reg);
val &= ~DPLL_VCO_ENABLE;
I915_WRITE(reg, val);
POSTING_READ(reg);
}
static void intel_enable_pch_pll(struct drm_i915_private *dev_priv,
enum pipe pipe)
{
int reg;
u32 val;
if (pipe > 1)
return;
BUG_ON(dev_priv->info->gen < 5);
assert_pch_refclk_enabled(dev_priv);
reg = PCH_DPLL(pipe);
val = I915_READ(reg);
val |= DPLL_VCO_ENABLE;
I915_WRITE(reg, val);
POSTING_READ(reg);
udelay(200);
}
static void intel_disable_pch_pll(struct drm_i915_private *dev_priv,
enum pipe pipe)
{
int reg;
u32 val, pll_mask = TRANSC_DPLL_ENABLE | TRANSC_DPLLB_SEL,
pll_sel = TRANSC_DPLL_ENABLE;
if (pipe > 1)
return;
BUG_ON(dev_priv->info->gen < 5);
assert_transcoder_disabled(dev_priv, pipe);
if (pipe == 0)
pll_sel |= TRANSC_DPLLA_SEL;
else if (pipe == 1)
pll_sel |= TRANSC_DPLLB_SEL;
if ((I915_READ(PCH_DPLL_SEL) & pll_mask) == pll_sel)
return;
reg = PCH_DPLL(pipe);
val = I915_READ(reg);
val &= ~DPLL_VCO_ENABLE;
I915_WRITE(reg, val);
POSTING_READ(reg);
udelay(200);
}
static void intel_enable_transcoder(struct drm_i915_private *dev_priv,
enum pipe pipe)
{
int reg;
u32 val;
BUG_ON(dev_priv->info->gen < 5);
assert_pch_pll_enabled(dev_priv, pipe);
assert_fdi_tx_enabled(dev_priv, pipe);
assert_fdi_rx_enabled(dev_priv, pipe);
reg = TRANSCONF(pipe);
val = I915_READ(reg);
if (HAS_PCH_IBX(dev_priv->dev)) {
val &= ~PIPE_BPC_MASK;
val |= I915_READ(PIPECONF(pipe)) & PIPE_BPC_MASK;
}
I915_WRITE(reg, val | TRANS_ENABLE);
if (wait_for(I915_READ(reg) & TRANS_STATE_ENABLE, 100))
DRM_ERROR("failed to enable transcoder %d\n", pipe);
}
static void intel_disable_transcoder(struct drm_i915_private *dev_priv,
enum pipe pipe)
{
int reg;
u32 val;
assert_fdi_tx_disabled(dev_priv, pipe);
assert_fdi_rx_disabled(dev_priv, pipe);
assert_pch_ports_disabled(dev_priv, pipe);
reg = TRANSCONF(pipe);
val = I915_READ(reg);
val &= ~TRANS_ENABLE;
I915_WRITE(reg, val);
if (wait_for((I915_READ(reg) & TRANS_STATE_ENABLE) == 0, 50))
DRM_ERROR("failed to disable transcoder %d\n", pipe);
}
static void intel_enable_pipe(struct drm_i915_private *dev_priv, enum pipe pipe,
bool pch_port)
{
int reg;
u32 val;
if (!HAS_PCH_SPLIT(dev_priv->dev))
assert_pll_enabled(dev_priv, pipe);
else {
if (pch_port) {
assert_fdi_rx_pll_enabled(dev_priv, pipe);
assert_fdi_tx_pll_enabled(dev_priv, pipe);
}
}
reg = PIPECONF(pipe);
val = I915_READ(reg);
if (val & PIPECONF_ENABLE)
return;
I915_WRITE(reg, val | PIPECONF_ENABLE);
intel_wait_for_vblank(dev_priv->dev, pipe);
}
static void intel_disable_pipe(struct drm_i915_private *dev_priv,
enum pipe pipe)
{
int reg;
u32 val;
assert_planes_disabled(dev_priv, pipe);
if (pipe == PIPE_A && (dev_priv->quirks & QUIRK_PIPEA_FORCE))
return;
reg = PIPECONF(pipe);
val = I915_READ(reg);
if ((val & PIPECONF_ENABLE) == 0)
return;
I915_WRITE(reg, val & ~PIPECONF_ENABLE);
intel_wait_for_pipe_off(dev_priv->dev, pipe);
}
static void intel_flush_display_plane(struct drm_i915_private *dev_priv,
enum plane plane)
{
I915_WRITE(DSPADDR(plane), I915_READ(DSPADDR(plane)));
I915_WRITE(DSPSURF(plane), I915_READ(DSPSURF(plane)));
}
static void intel_enable_plane(struct drm_i915_private *dev_priv,
enum plane plane, enum pipe pipe)
{
int reg;
u32 val;
assert_pipe_enabled(dev_priv, pipe);
reg = DSPCNTR(plane);
val = I915_READ(reg);
if (val & DISPLAY_PLANE_ENABLE)
return;
I915_WRITE(reg, val | DISPLAY_PLANE_ENABLE);
intel_flush_display_plane(dev_priv, plane);
intel_wait_for_vblank(dev_priv->dev, pipe);
}
static void intel_disable_plane(struct drm_i915_private *dev_priv,
enum plane plane, enum pipe pipe)
{
int reg;
u32 val;
reg = DSPCNTR(plane);
val = I915_READ(reg);
if ((val & DISPLAY_PLANE_ENABLE) == 0)
return;
I915_WRITE(reg, val & ~DISPLAY_PLANE_ENABLE);
intel_flush_display_plane(dev_priv, plane);
intel_wait_for_vblank(dev_priv->dev, pipe);
}
static void disable_pch_dp(struct drm_i915_private *dev_priv,
enum pipe pipe, int reg, u32 port_sel)
{
u32 val = I915_READ(reg);
if (dp_pipe_enabled(dev_priv, pipe, port_sel, val)) {
DRM_DEBUG_KMS("Disabling pch dp %x on pipe %d\n", reg, pipe);
I915_WRITE(reg, val & ~DP_PORT_EN);
}
}
static void disable_pch_hdmi(struct drm_i915_private *dev_priv,
enum pipe pipe, int reg)
{
u32 val = I915_READ(reg);
if (hdmi_pipe_enabled(dev_priv, val, pipe)) {
DRM_DEBUG_KMS("Disabling pch HDMI %x on pipe %d\n",
reg, pipe);
I915_WRITE(reg, val & ~PORT_ENABLE);
}
}
static void intel_disable_pch_ports(struct drm_i915_private *dev_priv,
enum pipe pipe)
{
u32 reg, val;
val = I915_READ(PCH_PP_CONTROL);
I915_WRITE(PCH_PP_CONTROL, val | PANEL_UNLOCK_REGS);
disable_pch_dp(dev_priv, pipe, PCH_DP_B, TRANS_DP_PORT_SEL_B);
disable_pch_dp(dev_priv, pipe, PCH_DP_C, TRANS_DP_PORT_SEL_C);
disable_pch_dp(dev_priv, pipe, PCH_DP_D, TRANS_DP_PORT_SEL_D);
reg = PCH_ADPA;
val = I915_READ(reg);
if (adpa_pipe_enabled(dev_priv, val, pipe))
I915_WRITE(reg, val & ~ADPA_DAC_ENABLE);
reg = PCH_LVDS;
val = I915_READ(reg);
if (lvds_pipe_enabled(dev_priv, val, pipe)) {
DRM_DEBUG_KMS("disable lvds on pipe %d val 0x%08x\n", pipe, val);
I915_WRITE(reg, val & ~LVDS_PORT_EN);
POSTING_READ(reg);
udelay(100);
}
disable_pch_hdmi(dev_priv, pipe, HDMIB);
disable_pch_hdmi(dev_priv, pipe, HDMIC);
disable_pch_hdmi(dev_priv, pipe, HDMID);
}
static void i8xx_disable_fbc(struct drm_device *dev)
{
struct drm_i915_private *dev_priv = dev->dev_private;
u32 fbc_ctl;
fbc_ctl = I915_READ(FBC_CONTROL);
if ((fbc_ctl & FBC_CTL_EN) == 0)
return;
fbc_ctl &= ~FBC_CTL_EN;
I915_WRITE(FBC_CONTROL, fbc_ctl);
if (wait_for((I915_READ(FBC_STATUS) & FBC_STAT_COMPRESSING) == 0, 10)) {
DRM_DEBUG_KMS("FBC idle timed out\n");
return;
}
DRM_DEBUG_KMS("disabled FBC\n");
}
static void i8xx_enable_fbc(struct drm_crtc *crtc, unsigned long interval)
{
struct drm_device *dev = crtc->dev;
struct drm_i915_private *dev_priv = dev->dev_private;
struct drm_framebuffer *fb = crtc->fb;
struct intel_framebuffer *intel_fb = to_intel_framebuffer(fb);
struct drm_i915_gem_object *obj = intel_fb->obj;
struct intel_crtc *intel_crtc = to_intel_crtc(crtc);
int cfb_pitch;
int plane, i;
u32 fbc_ctl, fbc_ctl2;
cfb_pitch = dev_priv->cfb_size / FBC_LL_SIZE;
if (fb->pitches[0] < cfb_pitch)
cfb_pitch = fb->pitches[0];
cfb_pitch = (cfb_pitch / 64) - 1;
plane = intel_crtc->plane == 0 ? FBC_CTL_PLANEA : FBC_CTL_PLANEB;
for (i = 0; i < (FBC_LL_SIZE / 32) + 1; i++)
I915_WRITE(FBC_TAG + (i * 4), 0);
fbc_ctl2 = FBC_CTL_FENCE_DBL | FBC_CTL_IDLE_IMM | FBC_CTL_CPU_FENCE;
fbc_ctl2 |= plane;
I915_WRITE(FBC_CONTROL2, fbc_ctl2);
I915_WRITE(FBC_FENCE_OFF, crtc->y);
fbc_ctl = FBC_CTL_EN | FBC_CTL_PERIODIC;
if (IS_I945GM(dev))
fbc_ctl |= FBC_CTL_C3_IDLE;
fbc_ctl |= (cfb_pitch & 0xff) << FBC_CTL_STRIDE_SHIFT;
fbc_ctl |= (interval & 0x2fff) << FBC_CTL_INTERVAL_SHIFT;
fbc_ctl |= obj->fence_reg;
I915_WRITE(FBC_CONTROL, fbc_ctl);
DRM_DEBUG_KMS("enabled FBC, pitch %d, yoff %d, plane %d, ",
cfb_pitch, crtc->y, intel_crtc->plane);
}
static bool i8xx_fbc_enabled(struct drm_device *dev)
{
struct drm_i915_private *dev_priv = dev->dev_private;
return I915_READ(FBC_CONTROL) & FBC_CTL_EN;
}
static void g4x_enable_fbc(struct drm_crtc *crtc, unsigned long interval)
{
struct drm_device *dev = crtc->dev;
struct drm_i915_private *dev_priv = dev->dev_private;
struct drm_framebuffer *fb = crtc->fb;
struct intel_framebuffer *intel_fb = to_intel_framebuffer(fb);
struct drm_i915_gem_object *obj = intel_fb->obj;
struct intel_crtc *intel_crtc = to_intel_crtc(crtc);
int plane = intel_crtc->plane == 0 ? DPFC_CTL_PLANEA : DPFC_CTL_PLANEB;
unsigned long stall_watermark = 200;
u32 dpfc_ctl;
dpfc_ctl = plane | DPFC_SR_EN | DPFC_CTL_LIMIT_1X;
dpfc_ctl |= DPFC_CTL_FENCE_EN | obj->fence_reg;
I915_WRITE(DPFC_CHICKEN, DPFC_HT_MODIFY);
I915_WRITE(DPFC_RECOMP_CTL, DPFC_RECOMP_STALL_EN |
(stall_watermark << DPFC_RECOMP_STALL_WM_SHIFT) |
(interval << DPFC_RECOMP_TIMER_COUNT_SHIFT));
I915_WRITE(DPFC_FENCE_YOFF, crtc->y);
I915_WRITE(DPFC_CONTROL, I915_READ(DPFC_CONTROL) | DPFC_CTL_EN);
DRM_DEBUG_KMS("enabled fbc on plane %d\n", intel_crtc->plane);
}
static void g4x_disable_fbc(struct drm_device *dev)
{
struct drm_i915_private *dev_priv = dev->dev_private;
u32 dpfc_ctl;
dpfc_ctl = I915_READ(DPFC_CONTROL);
if (dpfc_ctl & DPFC_CTL_EN) {
dpfc_ctl &= ~DPFC_CTL_EN;
I915_WRITE(DPFC_CONTROL, dpfc_ctl);
DRM_DEBUG_KMS("disabled FBC\n");
}
}
static bool g4x_fbc_enabled(struct drm_device *dev)
{
struct drm_i915_private *dev_priv = dev->dev_private;
return I915_READ(DPFC_CONTROL) & DPFC_CTL_EN;
}
static void sandybridge_blit_fbc_update(struct drm_device *dev)
{
struct drm_i915_private *dev_priv = dev->dev_private;
u32 blt_ecoskpd;
gen6_gt_force_wake_get(dev_priv);
blt_ecoskpd = I915_READ(GEN6_BLITTER_ECOSKPD);
blt_ecoskpd |= GEN6_BLITTER_FBC_NOTIFY <<
GEN6_BLITTER_LOCK_SHIFT;
I915_WRITE(GEN6_BLITTER_ECOSKPD, blt_ecoskpd);
blt_ecoskpd |= GEN6_BLITTER_FBC_NOTIFY;
I915_WRITE(GEN6_BLITTER_ECOSKPD, blt_ecoskpd);
blt_ecoskpd &= ~(GEN6_BLITTER_FBC_NOTIFY <<
GEN6_BLITTER_LOCK_SHIFT);
I915_WRITE(GEN6_BLITTER_ECOSKPD, blt_ecoskpd);
POSTING_READ(GEN6_BLITTER_ECOSKPD);
gen6_gt_force_wake_put(dev_priv);
}
static void ironlake_enable_fbc(struct drm_crtc *crtc, unsigned long interval)
{
struct drm_device *dev = crtc->dev;
struct drm_i915_private *dev_priv = dev->dev_private;
struct drm_framebuffer *fb = crtc->fb;
struct intel_framebuffer *intel_fb = to_intel_framebuffer(fb);
struct drm_i915_gem_object *obj = intel_fb->obj;
struct intel_crtc *intel_crtc = to_intel_crtc(crtc);
int plane = intel_crtc->plane == 0 ? DPFC_CTL_PLANEA : DPFC_CTL_PLANEB;
unsigned long stall_watermark = 200;
u32 dpfc_ctl;
dpfc_ctl = I915_READ(ILK_DPFC_CONTROL);
dpfc_ctl &= DPFC_RESERVED;
dpfc_ctl |= (plane | DPFC_CTL_LIMIT_1X);
dpfc_ctl |= DPFC_CTL_PERSISTENT_MODE;
dpfc_ctl |= (DPFC_CTL_FENCE_EN | obj->fence_reg);
I915_WRITE(ILK_DPFC_CHICKEN, DPFC_HT_MODIFY);
I915_WRITE(ILK_DPFC_RECOMP_CTL, DPFC_RECOMP_STALL_EN |
(stall_watermark << DPFC_RECOMP_STALL_WM_SHIFT) |
(interval << DPFC_RECOMP_TIMER_COUNT_SHIFT));
I915_WRITE(ILK_DPFC_FENCE_YOFF, crtc->y);
I915_WRITE(ILK_FBC_RT_BASE, obj->gtt_offset | ILK_FBC_RT_VALID);
I915_WRITE(ILK_DPFC_CONTROL, dpfc_ctl | DPFC_CTL_EN);
if (IS_GEN6(dev)) {
I915_WRITE(SNB_DPFC_CTL_SA,
SNB_CPU_FENCE_ENABLE | obj->fence_reg);
I915_WRITE(DPFC_CPU_FENCE_OFFSET, crtc->y);
sandybridge_blit_fbc_update(dev);
}
DRM_DEBUG_KMS("enabled fbc on plane %d\n", intel_crtc->plane);
}
static void ironlake_disable_fbc(struct drm_device *dev)
{
struct drm_i915_private *dev_priv = dev->dev_private;
u32 dpfc_ctl;
dpfc_ctl = I915_READ(ILK_DPFC_CONTROL);
if (dpfc_ctl & DPFC_CTL_EN) {
dpfc_ctl &= ~DPFC_CTL_EN;
I915_WRITE(ILK_DPFC_CONTROL, dpfc_ctl);
DRM_DEBUG_KMS("disabled FBC\n");
}
}
static bool ironlake_fbc_enabled(struct drm_device *dev)
{
struct drm_i915_private *dev_priv = dev->dev_private;
return I915_READ(ILK_DPFC_CONTROL) & DPFC_CTL_EN;
}
bool intel_fbc_enabled(struct drm_device *dev)
{
struct drm_i915_private *dev_priv = dev->dev_private;
if (!dev_priv->display.fbc_enabled)
return false;
return dev_priv->display.fbc_enabled(dev);
}
static void intel_fbc_work_fn(struct work_struct *__work)
{
struct intel_fbc_work *work =
container_of(to_delayed_work(__work),
struct intel_fbc_work, work);
struct drm_device *dev = work->crtc->dev;
struct drm_i915_private *dev_priv = dev->dev_private;
mutex_lock(&dev->struct_mutex);
if (work == dev_priv->fbc_work) {
if (work->crtc->fb == work->fb) {
dev_priv->display.enable_fbc(work->crtc,
work->interval);
dev_priv->cfb_plane = to_intel_crtc(work->crtc)->plane;
dev_priv->cfb_fb = work->crtc->fb->base.id;
dev_priv->cfb_y = work->crtc->y;
}
dev_priv->fbc_work = NULL;
}
mutex_unlock(&dev->struct_mutex);
kfree(work);
}
static void intel_cancel_fbc_work(struct drm_i915_private *dev_priv)
{
if (dev_priv->fbc_work == NULL)
return;
DRM_DEBUG_KMS("cancelling pending FBC enable\n");
if (cancel_delayed_work(&dev_priv->fbc_work->work))
kfree(dev_priv->fbc_work);
dev_priv->fbc_work = NULL;
}
static void intel_enable_fbc(struct drm_crtc *crtc, unsigned long interval)
{
struct intel_fbc_work *work;
struct drm_device *dev = crtc->dev;
struct drm_i915_private *dev_priv = dev->dev_private;
if (!dev_priv->display.enable_fbc)
return;
intel_cancel_fbc_work(dev_priv);
work = kzalloc(sizeof *work, GFP_KERNEL);
if (work == NULL) {
dev_priv->display.enable_fbc(crtc, interval);
return;
}
work->crtc = crtc;
work->fb = crtc->fb;
work->interval = interval;
INIT_DELAYED_WORK(&work->work, intel_fbc_work_fn);
dev_priv->fbc_work = work;
DRM_DEBUG_KMS("scheduling delayed FBC enable\n");
schedule_delayed_work(&work->work, msecs_to_jiffies(50));
}
void intel_disable_fbc(struct drm_device *dev)
{
struct drm_i915_private *dev_priv = dev->dev_private;
intel_cancel_fbc_work(dev_priv);
if (!dev_priv->display.disable_fbc)
return;
dev_priv->display.disable_fbc(dev);
dev_priv->cfb_plane = -1;
}
static void intel_update_fbc(struct drm_device *dev)
{
struct drm_i915_private *dev_priv = dev->dev_private;
struct drm_crtc *crtc = NULL, *tmp_crtc;
struct intel_crtc *intel_crtc;
struct drm_framebuffer *fb;
struct intel_framebuffer *intel_fb;
struct drm_i915_gem_object *obj;
int enable_fbc;
DRM_DEBUG_KMS("\n");
if (!i915_powersave)
return;
if (!I915_HAS_FBC(dev))
return;
list_for_each_entry(tmp_crtc, &dev->mode_config.crtc_list, head) {
if (tmp_crtc->enabled && tmp_crtc->fb) {
if (crtc) {
DRM_DEBUG_KMS("more than one pipe active, disabling compression\n");
dev_priv->no_fbc_reason = FBC_MULTIPLE_PIPES;
goto out_disable;
}
crtc = tmp_crtc;
}
}
if (!crtc || crtc->fb == NULL) {
DRM_DEBUG_KMS("no output, disabling\n");
dev_priv->no_fbc_reason = FBC_NO_OUTPUT;
goto out_disable;
}
intel_crtc = to_intel_crtc(crtc);
fb = crtc->fb;
intel_fb = to_intel_framebuffer(fb);
obj = intel_fb->obj;
enable_fbc = i915_enable_fbc;
if (enable_fbc < 0) {
DRM_DEBUG_KMS("fbc set to per-chip default\n");
enable_fbc = 1;
if (INTEL_INFO(dev)->gen <= 6)
enable_fbc = 0;
}
if (!enable_fbc) {
DRM_DEBUG_KMS("fbc disabled per module param\n");
dev_priv->no_fbc_reason = FBC_MODULE_PARAM;
goto out_disable;
}
if (intel_fb->obj->base.size > dev_priv->cfb_size) {
DRM_DEBUG_KMS("framebuffer too large, disabling "
"compression\n");
dev_priv->no_fbc_reason = FBC_STOLEN_TOO_SMALL;
goto out_disable;
}
if ((crtc->mode.flags & DRM_MODE_FLAG_INTERLACE) ||
(crtc->mode.flags & DRM_MODE_FLAG_DBLSCAN)) {
DRM_DEBUG_KMS("mode incompatible with compression, "
"disabling\n");
dev_priv->no_fbc_reason = FBC_UNSUPPORTED_MODE;
goto out_disable;
}
if ((crtc->mode.hdisplay > 2048) ||
(crtc->mode.vdisplay > 1536)) {
DRM_DEBUG_KMS("mode too large for compression, disabling\n");
dev_priv->no_fbc_reason = FBC_MODE_TOO_LARGE;
goto out_disable;
}
if ((IS_I915GM(dev) || IS_I945GM(dev)) && intel_crtc->plane != 0) {
DRM_DEBUG_KMS("plane not 0, disabling compression\n");
dev_priv->no_fbc_reason = FBC_BAD_PLANE;
goto out_disable;
}
if (obj->tiling_mode != I915_TILING_X ||
obj->fence_reg == I915_FENCE_REG_NONE) {
DRM_DEBUG_KMS("framebuffer not tiled or fenced, disabling compression\n");
dev_priv->no_fbc_reason = FBC_NOT_TILED;
goto out_disable;
}
if (in_dbg_master())
goto out_disable;
if (dev_priv->cfb_plane == intel_crtc->plane &&
dev_priv->cfb_fb == fb->base.id &&
dev_priv->cfb_y == crtc->y)
return;
if (intel_fbc_enabled(dev)) {
DRM_DEBUG_KMS("disabling active FBC for update\n");
intel_disable_fbc(dev);
}
intel_enable_fbc(crtc, 500);
return;
out_disable:
if (intel_fbc_enabled(dev)) {
DRM_DEBUG_KMS("unsupported config, disabling FBC\n");
intel_disable_fbc(dev);
}
}
int
intel_pin_and_fence_fb_obj(struct drm_device *dev,
struct drm_i915_gem_object *obj,
struct intel_ring_buffer *pipelined)
{
struct drm_i915_private *dev_priv = dev->dev_private;
u32 alignment;
int ret;
switch (obj->tiling_mode) {
case I915_TILING_NONE:
if (IS_BROADWATER(dev) || IS_CRESTLINE(dev))
alignment = 128 * 1024;
else if (INTEL_INFO(dev)->gen >= 4)
alignment = 4 * 1024;
else
alignment = 64 * 1024;
break;
case I915_TILING_X:
alignment = 0;
break;
case I915_TILING_Y:
DRM_ERROR("Y tiled not allowed for scan out buffers\n");
return -EINVAL;
default:
BUG();
}
dev_priv->mm.interruptible = false;
ret = i915_gem_object_pin_to_display_plane(obj, alignment, pipelined);
if (ret)
goto err_interruptible;
if (obj->tiling_mode != I915_TILING_NONE) {
ret = i915_gem_object_get_fence(obj, pipelined);
if (ret)
goto err_unpin;
}
dev_priv->mm.interruptible = true;
return 0;
err_unpin:
i915_gem_object_unpin(obj);
err_interruptible:
dev_priv->mm.interruptible = true;
return ret;
}
static int i9xx_update_plane(struct drm_crtc *crtc, struct drm_framebuffer *fb,
int x, int y)
{
struct drm_device *dev = crtc->dev;
struct drm_i915_private *dev_priv = dev->dev_private;
struct intel_crtc *intel_crtc = to_intel_crtc(crtc);
struct intel_framebuffer *intel_fb;
struct drm_i915_gem_object *obj;
int plane = intel_crtc->plane;
unsigned long Start, Offset;
u32 dspcntr;
u32 reg;
switch (plane) {
case 0:
case 1:
break;
default:
DRM_ERROR("Can't update plane %d in SAREA\n", plane);
return -EINVAL;
}
intel_fb = to_intel_framebuffer(fb);
obj = intel_fb->obj;
reg = DSPCNTR(plane);
dspcntr = I915_READ(reg);
dspcntr &= ~DISPPLANE_PIXFORMAT_MASK;
switch (fb->bits_per_pixel) {
case 8:
dspcntr |= DISPPLANE_8BPP;
break;
case 16:
if (fb->depth == 15)
dspcntr |= DISPPLANE_15_16BPP;
else
dspcntr |= DISPPLANE_16BPP;
break;
case 24:
case 32:
dspcntr |= DISPPLANE_32BPP_NO_ALPHA;
break;
default:
DRM_ERROR("Unknown color depth %d\n", fb->bits_per_pixel);
return -EINVAL;
}
if (INTEL_INFO(dev)->gen >= 4) {
if (obj->tiling_mode != I915_TILING_NONE)
dspcntr |= DISPPLANE_TILED;
else
dspcntr &= ~DISPPLANE_TILED;
}
I915_WRITE(reg, dspcntr);
Start = obj->gtt_offset;
Offset = y * fb->pitches[0] + x * (fb->bits_per_pixel / 8);
DRM_DEBUG_KMS("Writing base %08lX %08lX %d %d %d\n",
Start, Offset, x, y, fb->pitches[0]);
I915_WRITE(DSPSTRIDE(plane), fb->pitches[0]);
if (INTEL_INFO(dev)->gen >= 4) {
I915_WRITE(DSPSURF(plane), Start);
I915_WRITE(DSPTILEOFF(plane), (y << 16) | x);
I915_WRITE(DSPADDR(plane), Offset);
} else
I915_WRITE(DSPADDR(plane), Start + Offset);
POSTING_READ(reg);
return 0;
}
static int ironlake_update_plane(struct drm_crtc *crtc,
struct drm_framebuffer *fb, int x, int y)
{
struct drm_device *dev = crtc->dev;
struct drm_i915_private *dev_priv = dev->dev_private;
struct intel_crtc *intel_crtc = to_intel_crtc(crtc);
struct intel_framebuffer *intel_fb;
struct drm_i915_gem_object *obj;
int plane = intel_crtc->plane;
unsigned long Start, Offset;
u32 dspcntr;
u32 reg;
switch (plane) {
case 0:
case 1:
case 2:
break;
default:
DRM_ERROR("Can't update plane %d in SAREA\n", plane);
return -EINVAL;
}
intel_fb = to_intel_framebuffer(fb);
obj = intel_fb->obj;
reg = DSPCNTR(plane);
dspcntr = I915_READ(reg);
dspcntr &= ~DISPPLANE_PIXFORMAT_MASK;
switch (fb->bits_per_pixel) {
case 8:
dspcntr |= DISPPLANE_8BPP;
break;
case 16:
if (fb->depth != 16)
return -EINVAL;
dspcntr |= DISPPLANE_16BPP;
break;
case 24:
case 32:
if (fb->depth == 24)
dspcntr |= DISPPLANE_32BPP_NO_ALPHA;
else if (fb->depth == 30)
dspcntr |= DISPPLANE_32BPP_30BIT_NO_ALPHA;
else
return -EINVAL;
break;
default:
DRM_ERROR("Unknown color depth %d\n", fb->bits_per_pixel);
return -EINVAL;
}
if (obj->tiling_mode != I915_TILING_NONE)
dspcntr |= DISPPLANE_TILED;
else
dspcntr &= ~DISPPLANE_TILED;
dspcntr |= DISPPLANE_TRICKLE_FEED_DISABLE;
I915_WRITE(reg, dspcntr);
Start = obj->gtt_offset;
Offset = y * fb->pitches[0] + x * (fb->bits_per_pixel / 8);
DRM_DEBUG_KMS("Writing base %08lX %08lX %d %d %d\n",
Start, Offset, x, y, fb->pitches[0]);
I915_WRITE(DSPSTRIDE(plane), fb->pitches[0]);
I915_WRITE(DSPSURF(plane), Start);
I915_WRITE(DSPTILEOFF(plane), (y << 16) | x);
I915_WRITE(DSPADDR(plane), Offset);
POSTING_READ(reg);
return 0;
}
static int
intel_pipe_set_base_atomic(struct drm_crtc *crtc, struct drm_framebuffer *fb,
int x, int y, enum mode_set_atomic state)
{
struct drm_device *dev = crtc->dev;
struct drm_i915_private *dev_priv = dev->dev_private;
int ret;
ret = dev_priv->display.update_plane(crtc, fb, x, y);
if (ret)
return ret;
intel_update_fbc(dev);
intel_increase_pllclock(crtc);
return 0;
}
static int
intel_pipe_set_base(struct drm_crtc *crtc, int x, int y,
struct drm_framebuffer *old_fb)
{
struct drm_device *dev = crtc->dev;
struct drm_i915_master_private *master_priv;
struct intel_crtc *intel_crtc = to_intel_crtc(crtc);
int ret;
if (!crtc->fb) {
DRM_ERROR("No FB bound\n");
return 0;
}
switch (intel_crtc->plane) {
case 0:
case 1:
break;
case 2:
if (IS_IVYBRIDGE(dev))
break;
default:
DRM_ERROR("no plane for crtc\n");
return -EINVAL;
}
mutex_lock(&dev->struct_mutex);
ret = intel_pin_and_fence_fb_obj(dev,
to_intel_framebuffer(crtc->fb)->obj,
NULL);
if (ret != 0) {
mutex_unlock(&dev->struct_mutex);
DRM_ERROR("pin & fence failed\n");
return ret;
}
if (old_fb) {
struct drm_i915_private *dev_priv = dev->dev_private;
struct drm_i915_gem_object *obj = to_intel_framebuffer(old_fb)->obj;
wait_event(dev_priv->pending_flip_queue,
atomic_read(&dev_priv->mm.wedged) ||
atomic_read(&obj->pending_flip) == 0);
ret = i915_gem_object_finish_gpu(obj);
(void) ret;
}
ret = intel_pipe_set_base_atomic(crtc, crtc->fb, x, y,
LEAVE_ATOMIC_MODE_SET);
if (ret) {
i915_gem_object_unpin(to_intel_framebuffer(crtc->fb)->obj);
mutex_unlock(&dev->struct_mutex);
DRM_ERROR("failed to update base address\n");
return ret;
}
if (old_fb) {
intel_wait_for_vblank(dev, intel_crtc->pipe);
i915_gem_object_unpin(to_intel_framebuffer(old_fb)->obj);
}
mutex_unlock(&dev->struct_mutex);
if (!dev->primary->master)
return 0;
master_priv = dev->primary->master->driver_priv;
if (!master_priv->sarea_priv)
return 0;
if (intel_crtc->pipe) {
master_priv->sarea_priv->pipeB_x = x;
master_priv->sarea_priv->pipeB_y = y;
} else {
master_priv->sarea_priv->pipeA_x = x;
master_priv->sarea_priv->pipeA_y = y;
}
return 0;
}
static void ironlake_set_pll_edp(struct drm_crtc *crtc, int clock)
{
struct drm_device *dev = crtc->dev;
struct drm_i915_private *dev_priv = dev->dev_private;
u32 dpa_ctl;
DRM_DEBUG_KMS("eDP PLL enable for clock %d\n", clock);
dpa_ctl = I915_READ(DP_A);
dpa_ctl &= ~DP_PLL_FREQ_MASK;
if (clock < 200000) {
u32 temp;
dpa_ctl |= DP_PLL_FREQ_160MHZ;
temp = I915_READ(0x4600c);
temp &= 0xffff0000;
I915_WRITE(0x4600c, temp | 0x8124);
temp = I915_READ(0x46010);
I915_WRITE(0x46010, temp | 1);
temp = I915_READ(0x46034);
I915_WRITE(0x46034, temp | (1 << 24));
} else {
dpa_ctl |= DP_PLL_FREQ_270MHZ;
}
I915_WRITE(DP_A, dpa_ctl);
POSTING_READ(DP_A);
udelay(500);
}
static void intel_fdi_normal_train(struct drm_crtc *crtc)
{
struct drm_device *dev = crtc->dev;
struct drm_i915_private *dev_priv = dev->dev_private;
struct intel_crtc *intel_crtc = to_intel_crtc(crtc);
int pipe = intel_crtc->pipe;
u32 reg, temp;
reg = FDI_TX_CTL(pipe);
temp = I915_READ(reg);
if (IS_IVYBRIDGE(dev)) {
temp &= ~FDI_LINK_TRAIN_NONE_IVB;
temp |= FDI_LINK_TRAIN_NONE_IVB | FDI_TX_ENHANCE_FRAME_ENABLE;
} else {
temp &= ~FDI_LINK_TRAIN_NONE;
temp |= FDI_LINK_TRAIN_NONE | FDI_TX_ENHANCE_FRAME_ENABLE;
}
I915_WRITE(reg, temp);
reg = FDI_RX_CTL(pipe);
temp = I915_READ(reg);
if (HAS_PCH_CPT(dev)) {
temp &= ~FDI_LINK_TRAIN_PATTERN_MASK_CPT;
temp |= FDI_LINK_TRAIN_NORMAL_CPT;
} else {
temp &= ~FDI_LINK_TRAIN_NONE;
temp |= FDI_LINK_TRAIN_NONE;
}
I915_WRITE(reg, temp | FDI_RX_ENHANCE_FRAME_ENABLE);
POSTING_READ(reg);
udelay(1000);
if (IS_IVYBRIDGE(dev))
I915_WRITE(reg, I915_READ(reg) | FDI_FS_ERRC_ENABLE |
FDI_FE_ERRC_ENABLE);
}
static void cpt_phase_pointer_enable(struct drm_device *dev, int pipe)
{
struct drm_i915_private *dev_priv = dev->dev_private;
u32 flags = I915_READ(SOUTH_CHICKEN1);
flags |= FDI_PHASE_SYNC_OVR(pipe);
I915_WRITE(SOUTH_CHICKEN1, flags);
flags |= FDI_PHASE_SYNC_EN(pipe);
I915_WRITE(SOUTH_CHICKEN1, flags);
POSTING_READ(SOUTH_CHICKEN1);
}
static void ironlake_fdi_link_train(struct drm_crtc *crtc)
{
struct drm_device *dev = crtc->dev;
struct drm_i915_private *dev_priv = dev->dev_private;
struct intel_crtc *intel_crtc = to_intel_crtc(crtc);
int pipe = intel_crtc->pipe;
int plane = intel_crtc->plane;
u32 reg, temp, tries;
assert_pipe_enabled(dev_priv, pipe);
assert_plane_enabled(dev_priv, plane);
reg = FDI_RX_IMR(pipe);
temp = I915_READ(reg);
temp &= ~FDI_RX_SYMBOL_LOCK;
temp &= ~FDI_RX_BIT_LOCK;
I915_WRITE(reg, temp);
I915_READ(reg);
udelay(150);
reg = FDI_TX_CTL(pipe);
temp = I915_READ(reg);
temp &= ~(7 << 19);
temp |= (intel_crtc->fdi_lanes - 1) << 19;
temp &= ~FDI_LINK_TRAIN_NONE;
temp |= FDI_LINK_TRAIN_PATTERN_1;
I915_WRITE(reg, temp | FDI_TX_ENABLE);
reg = FDI_RX_CTL(pipe);
temp = I915_READ(reg);
temp &= ~FDI_LINK_TRAIN_NONE;
temp |= FDI_LINK_TRAIN_PATTERN_1;
I915_WRITE(reg, temp | FDI_RX_ENABLE);
POSTING_READ(reg);
udelay(150);
if (HAS_PCH_IBX(dev)) {
I915_WRITE(FDI_RX_CHICKEN(pipe), FDI_RX_PHASE_SYNC_POINTER_OVR);
I915_WRITE(FDI_RX_CHICKEN(pipe), FDI_RX_PHASE_SYNC_POINTER_OVR |
FDI_RX_PHASE_SYNC_POINTER_EN);
}
reg = FDI_RX_IIR(pipe);
for (tries = 0; tries < 5; tries++) {
temp = I915_READ(reg);
DRM_DEBUG_KMS("FDI_RX_IIR 0x%x\n", temp);
if ((temp & FDI_RX_BIT_LOCK)) {
DRM_DEBUG_KMS("FDI train 1 done.\n");
I915_WRITE(reg, temp | FDI_RX_BIT_LOCK);
break;
}
}
if (tries == 5)
DRM_ERROR("FDI train 1 fail!\n");
reg = FDI_TX_CTL(pipe);
temp = I915_READ(reg);
temp &= ~FDI_LINK_TRAIN_NONE;
temp |= FDI_LINK_TRAIN_PATTERN_2;
I915_WRITE(reg, temp);
reg = FDI_RX_CTL(pipe);
temp = I915_READ(reg);
temp &= ~FDI_LINK_TRAIN_NONE;
temp |= FDI_LINK_TRAIN_PATTERN_2;
I915_WRITE(reg, temp);
POSTING_READ(reg);
udelay(150);
reg = FDI_RX_IIR(pipe);
for (tries = 0; tries < 5; tries++) {
temp = I915_READ(reg);
DRM_DEBUG_KMS("FDI_RX_IIR 0x%x\n", temp);
if (temp & FDI_RX_SYMBOL_LOCK) {
I915_WRITE(reg, temp | FDI_RX_SYMBOL_LOCK);
DRM_DEBUG_KMS("FDI train 2 done.\n");
break;
}
}
if (tries == 5)
DRM_ERROR("FDI train 2 fail!\n");
DRM_DEBUG_KMS("FDI train done\n");
}
static void gen6_fdi_link_train(struct drm_crtc *crtc)
{
struct drm_device *dev = crtc->dev;
struct drm_i915_private *dev_priv = dev->dev_private;
struct intel_crtc *intel_crtc = to_intel_crtc(crtc);
int pipe = intel_crtc->pipe;
u32 reg, temp, i;
reg = FDI_RX_IMR(pipe);
temp = I915_READ(reg);
temp &= ~FDI_RX_SYMBOL_LOCK;
temp &= ~FDI_RX_BIT_LOCK;
I915_WRITE(reg, temp);
POSTING_READ(reg);
udelay(150);
reg = FDI_TX_CTL(pipe);
temp = I915_READ(reg);
temp &= ~(7 << 19);
temp |= (intel_crtc->fdi_lanes - 1) << 19;
temp &= ~FDI_LINK_TRAIN_NONE;
temp |= FDI_LINK_TRAIN_PATTERN_1;
temp &= ~FDI_LINK_TRAIN_VOL_EMP_MASK;
temp |= FDI_LINK_TRAIN_400MV_0DB_SNB_B;
I915_WRITE(reg, temp | FDI_TX_ENABLE);
reg = FDI_RX_CTL(pipe);
temp = I915_READ(reg);
if (HAS_PCH_CPT(dev)) {
temp &= ~FDI_LINK_TRAIN_PATTERN_MASK_CPT;
temp |= FDI_LINK_TRAIN_PATTERN_1_CPT;
} else {
temp &= ~FDI_LINK_TRAIN_NONE;
temp |= FDI_LINK_TRAIN_PATTERN_1;
}
I915_WRITE(reg, temp | FDI_RX_ENABLE);
POSTING_READ(reg);
udelay(150);
if (HAS_PCH_CPT(dev))
cpt_phase_pointer_enable(dev, pipe);
for (i = 0; i < 4; i++) {
reg = FDI_TX_CTL(pipe);
temp = I915_READ(reg);
temp &= ~FDI_LINK_TRAIN_VOL_EMP_MASK;
temp |= snb_b_fdi_train_param[i];
I915_WRITE(reg, temp);
POSTING_READ(reg);
udelay(500);
reg = FDI_RX_IIR(pipe);
temp = I915_READ(reg);
DRM_DEBUG_KMS("FDI_RX_IIR 0x%x\n", temp);
if (temp & FDI_RX_BIT_LOCK) {
I915_WRITE(reg, temp | FDI_RX_BIT_LOCK);
DRM_DEBUG_KMS("FDI train 1 done.\n");
break;
}
}
if (i == 4)
DRM_ERROR("FDI train 1 fail!\n");
reg = FDI_TX_CTL(pipe);
temp = I915_READ(reg);
temp &= ~FDI_LINK_TRAIN_NONE;
temp |= FDI_LINK_TRAIN_PATTERN_2;
if (IS_GEN6(dev)) {
temp &= ~FDI_LINK_TRAIN_VOL_EMP_MASK;
temp |= FDI_LINK_TRAIN_400MV_0DB_SNB_B;
}
I915_WRITE(reg, temp);
reg = FDI_RX_CTL(pipe);
temp = I915_READ(reg);
if (HAS_PCH_CPT(dev)) {
temp &= ~FDI_LINK_TRAIN_PATTERN_MASK_CPT;
temp |= FDI_LINK_TRAIN_PATTERN_2_CPT;
} else {
temp &= ~FDI_LINK_TRAIN_NONE;
temp |= FDI_LINK_TRAIN_PATTERN_2;
}
I915_WRITE(reg, temp);
POSTING_READ(reg);
udelay(150);
for (i = 0; i < 4; i++) {
reg = FDI_TX_CTL(pipe);
temp = I915_READ(reg);
temp &= ~FDI_LINK_TRAIN_VOL_EMP_MASK;
temp |= snb_b_fdi_train_param[i];
I915_WRITE(reg, temp);
POSTING_READ(reg);
udelay(500);
reg = FDI_RX_IIR(pipe);
temp = I915_READ(reg);
DRM_DEBUG_KMS("FDI_RX_IIR 0x%x\n", temp);
if (temp & FDI_RX_SYMBOL_LOCK) {
I915_WRITE(reg, temp | FDI_RX_SYMBOL_LOCK);
DRM_DEBUG_KMS("FDI train 2 done.\n");
break;
}
}
if (i == 4)
DRM_ERROR("FDI train 2 fail!\n");
DRM_DEBUG_KMS("FDI train done.\n");
}
static void ivb_manual_fdi_link_train(struct drm_crtc *crtc)
{
struct drm_device *dev = crtc->dev;
struct drm_i915_private *dev_priv = dev->dev_private;
struct intel_crtc *intel_crtc = to_intel_crtc(crtc);
int pipe = intel_crtc->pipe;
u32 reg, temp, i;
reg = FDI_RX_IMR(pipe);
temp = I915_READ(reg);
temp &= ~FDI_RX_SYMBOL_LOCK;
temp &= ~FDI_RX_BIT_LOCK;
I915_WRITE(reg, temp);
POSTING_READ(reg);
udelay(150);
reg = FDI_TX_CTL(pipe);
temp = I915_READ(reg);
temp &= ~(7 << 19);
temp |= (intel_crtc->fdi_lanes - 1) << 19;
temp &= ~(FDI_LINK_TRAIN_AUTO | FDI_LINK_TRAIN_NONE_IVB);
temp |= FDI_LINK_TRAIN_PATTERN_1_IVB;
temp &= ~FDI_LINK_TRAIN_VOL_EMP_MASK;
temp |= FDI_LINK_TRAIN_400MV_0DB_SNB_B;
temp |= FDI_COMPOSITE_SYNC;
I915_WRITE(reg, temp | FDI_TX_ENABLE);
reg = FDI_RX_CTL(pipe);
temp = I915_READ(reg);
temp &= ~FDI_LINK_TRAIN_AUTO;
temp &= ~FDI_LINK_TRAIN_PATTERN_MASK_CPT;
temp |= FDI_LINK_TRAIN_PATTERN_1_CPT;
temp |= FDI_COMPOSITE_SYNC;
I915_WRITE(reg, temp | FDI_RX_ENABLE);
POSTING_READ(reg);
udelay(150);
if (HAS_PCH_CPT(dev))
cpt_phase_pointer_enable(dev, pipe);
for (i = 0; i < 4; i++) {
reg = FDI_TX_CTL(pipe);
temp = I915_READ(reg);
temp &= ~FDI_LINK_TRAIN_VOL_EMP_MASK;
temp |= snb_b_fdi_train_param[i];
I915_WRITE(reg, temp);
POSTING_READ(reg);
udelay(500);
reg = FDI_RX_IIR(pipe);
temp = I915_READ(reg);
DRM_DEBUG_KMS("FDI_RX_IIR 0x%x\n", temp);
if (temp & FDI_RX_BIT_LOCK ||
(I915_READ(reg) & FDI_RX_BIT_LOCK)) {
I915_WRITE(reg, temp | FDI_RX_BIT_LOCK);
DRM_DEBUG_KMS("FDI train 1 done.\n");
break;
}
}
if (i == 4)
DRM_ERROR("FDI train 1 fail!\n");
reg = FDI_TX_CTL(pipe);
temp = I915_READ(reg);
temp &= ~FDI_LINK_TRAIN_NONE_IVB;
temp |= FDI_LINK_TRAIN_PATTERN_2_IVB;
temp &= ~FDI_LINK_TRAIN_VOL_EMP_MASK;
temp |= FDI_LINK_TRAIN_400MV_0DB_SNB_B;
I915_WRITE(reg, temp);
reg = FDI_RX_CTL(pipe);
temp = I915_READ(reg);
temp &= ~FDI_LINK_TRAIN_PATTERN_MASK_CPT;
temp |= FDI_LINK_TRAIN_PATTERN_2_CPT;
I915_WRITE(reg, temp);
POSTING_READ(reg);
udelay(150);
for (i = 0; i < 4; i++) {
reg = FDI_TX_CTL(pipe);
temp = I915_READ(reg);
temp &= ~FDI_LINK_TRAIN_VOL_EMP_MASK;
temp |= snb_b_fdi_train_param[i];
I915_WRITE(reg, temp);
POSTING_READ(reg);
udelay(500);
reg = FDI_RX_IIR(pipe);
temp = I915_READ(reg);
DRM_DEBUG_KMS("FDI_RX_IIR 0x%x\n", temp);
if (temp & FDI_RX_SYMBOL_LOCK) {
I915_WRITE(reg, temp | FDI_RX_SYMBOL_LOCK);
DRM_DEBUG_KMS("FDI train 2 done.\n");
break;
}
}
if (i == 4)
DRM_ERROR("FDI train 2 fail!\n");
DRM_DEBUG_KMS("FDI train done.\n");
}
static void ironlake_fdi_pll_enable(struct drm_crtc *crtc)
{
struct drm_device *dev = crtc->dev;
struct drm_i915_private *dev_priv = dev->dev_private;
struct intel_crtc *intel_crtc = to_intel_crtc(crtc);
int pipe = intel_crtc->pipe;
u32 reg, temp;
I915_WRITE(FDI_RX_TUSIZE1(pipe),
I915_READ(PIPE_DATA_M1(pipe)) & TU_SIZE_MASK);
reg = FDI_RX_CTL(pipe);
temp = I915_READ(reg);
temp &= ~((0x7 << 19) | (0x7 << 16));
temp |= (intel_crtc->fdi_lanes - 1) << 19;
temp |= (I915_READ(PIPECONF(pipe)) & PIPE_BPC_MASK) << 11;
I915_WRITE(reg, temp | FDI_RX_PLL_ENABLE);
POSTING_READ(reg);
udelay(200);
temp = I915_READ(reg);
I915_WRITE(reg, temp | FDI_PCDCLK);
POSTING_READ(reg);
udelay(200);
reg = FDI_TX_CTL(pipe);
temp = I915_READ(reg);
if ((temp & FDI_TX_PLL_ENABLE) == 0) {
I915_WRITE(reg, temp | FDI_TX_PLL_ENABLE);
POSTING_READ(reg);
udelay(100);
}
}
static void cpt_phase_pointer_disable(struct drm_device *dev, int pipe)
{
struct drm_i915_private *dev_priv = dev->dev_private;
u32 flags = I915_READ(SOUTH_CHICKEN1);
flags &= ~(FDI_PHASE_SYNC_EN(pipe));
I915_WRITE(SOUTH_CHICKEN1, flags);
flags &= ~(FDI_PHASE_SYNC_OVR(pipe));
I915_WRITE(SOUTH_CHICKEN1, flags);
POSTING_READ(SOUTH_CHICKEN1);
}
static void ironlake_fdi_disable(struct drm_crtc *crtc)
{
struct drm_device *dev = crtc->dev;
struct drm_i915_private *dev_priv = dev->dev_private;
struct intel_crtc *intel_crtc = to_intel_crtc(crtc);
int pipe = intel_crtc->pipe;
u32 reg, temp;
reg = FDI_TX_CTL(pipe);
temp = I915_READ(reg);
I915_WRITE(reg, temp & ~FDI_TX_ENABLE);
POSTING_READ(reg);
reg = FDI_RX_CTL(pipe);
temp = I915_READ(reg);
temp &= ~(0x7 << 16);
temp |= (I915_READ(PIPECONF(pipe)) & PIPE_BPC_MASK) << 11;
I915_WRITE(reg, temp & ~FDI_RX_ENABLE);
POSTING_READ(reg);
udelay(100);
if (HAS_PCH_IBX(dev)) {
I915_WRITE(FDI_RX_CHICKEN(pipe), FDI_RX_PHASE_SYNC_POINTER_OVR);
I915_WRITE(FDI_RX_CHICKEN(pipe),
I915_READ(FDI_RX_CHICKEN(pipe) &
~FDI_RX_PHASE_SYNC_POINTER_EN));
} else if (HAS_PCH_CPT(dev)) {
cpt_phase_pointer_disable(dev, pipe);
}
reg = FDI_TX_CTL(pipe);
temp = I915_READ(reg);
temp &= ~FDI_LINK_TRAIN_NONE;
temp |= FDI_LINK_TRAIN_PATTERN_1;
I915_WRITE(reg, temp);
reg = FDI_RX_CTL(pipe);
temp = I915_READ(reg);
if (HAS_PCH_CPT(dev)) {
temp &= ~FDI_LINK_TRAIN_PATTERN_MASK_CPT;
temp |= FDI_LINK_TRAIN_PATTERN_1_CPT;
} else {
temp &= ~FDI_LINK_TRAIN_NONE;
temp |= FDI_LINK_TRAIN_PATTERN_1;
}
temp &= ~(0x07 << 16);
temp |= (I915_READ(PIPECONF(pipe)) & PIPE_BPC_MASK) << 11;
I915_WRITE(reg, temp);
POSTING_READ(reg);
udelay(100);
}
static void intel_clear_scanline_wait(struct drm_device *dev)
{
struct drm_i915_private *dev_priv = dev->dev_private;
struct intel_ring_buffer *ring;
u32 tmp;
if (IS_GEN2(dev))
return;
ring = LP_RING(dev_priv);
tmp = I915_READ_CTL(ring);
if (tmp & RING_WAIT)
I915_WRITE_CTL(ring, tmp);
}
static void intel_crtc_wait_for_pending_flips(struct drm_crtc *crtc)
{
struct drm_i915_gem_object *obj;
struct drm_i915_private *dev_priv;
if (crtc->fb == NULL)
return;
obj = to_intel_framebuffer(crtc->fb)->obj;
dev_priv = crtc->dev->dev_private;
wait_event(dev_priv->pending_flip_queue,
atomic_read(&obj->pending_flip) == 0);
}
static bool intel_crtc_driving_pch(struct drm_crtc *crtc)
{
struct drm_device *dev = crtc->dev;
struct drm_mode_config *mode_config = &dev->mode_config;
struct intel_encoder *encoder;
list_for_each_entry(encoder, &mode_config->encoder_list, base.head) {
if (encoder->base.crtc != crtc)
continue;
switch (encoder->type) {
case INTEL_OUTPUT_EDP:
if (!intel_encoder_is_pch_edp(&encoder->base))
return false;
continue;
}
}
return true;
}
static void ironlake_pch_enable(struct drm_crtc *crtc)
{
struct drm_device *dev = crtc->dev;
struct drm_i915_private *dev_priv = dev->dev_private;
struct intel_crtc *intel_crtc = to_intel_crtc(crtc);
int pipe = intel_crtc->pipe;
u32 reg, temp, transc_sel;
dev_priv->display.fdi_link_train(crtc);
intel_enable_pch_pll(dev_priv, pipe);
if (HAS_PCH_CPT(dev)) {
transc_sel = intel_crtc->use_pll_a ? TRANSC_DPLLA_SEL :
TRANSC_DPLLB_SEL;
temp = I915_READ(PCH_DPLL_SEL);
if (pipe == 0) {
temp &= ~(TRANSA_DPLLB_SEL);
temp |= (TRANSA_DPLL_ENABLE | TRANSA_DPLLA_SEL);
} else if (pipe == 1) {
temp &= ~(TRANSB_DPLLB_SEL);
temp |= (TRANSB_DPLL_ENABLE | TRANSB_DPLLB_SEL);
} else if (pipe == 2) {
temp &= ~(TRANSC_DPLLB_SEL);
temp |= (TRANSC_DPLL_ENABLE | transc_sel);
}
I915_WRITE(PCH_DPLL_SEL, temp);
}
assert_panel_unlocked(dev_priv, pipe);
I915_WRITE(TRANS_HTOTAL(pipe), I915_READ(HTOTAL(pipe)));
I915_WRITE(TRANS_HBLANK(pipe), I915_READ(HBLANK(pipe)));
I915_WRITE(TRANS_HSYNC(pipe), I915_READ(HSYNC(pipe)));
I915_WRITE(TRANS_VTOTAL(pipe), I915_READ(VTOTAL(pipe)));
I915_WRITE(TRANS_VBLANK(pipe), I915_READ(VBLANK(pipe)));
I915_WRITE(TRANS_VSYNC(pipe), I915_READ(VSYNC(pipe)));
intel_fdi_normal_train(crtc);
if (HAS_PCH_CPT(dev) &&
(intel_pipe_has_type(crtc, INTEL_OUTPUT_DISPLAYPORT) ||
intel_pipe_has_type(crtc, INTEL_OUTPUT_EDP))) {
u32 bpc = (I915_READ(PIPECONF(pipe)) & PIPE_BPC_MASK) >> 5;
reg = TRANS_DP_CTL(pipe);
temp = I915_READ(reg);
temp &= ~(TRANS_DP_PORT_SEL_MASK |
TRANS_DP_SYNC_MASK |
TRANS_DP_BPC_MASK);
temp |= (TRANS_DP_OUTPUT_ENABLE |
TRANS_DP_ENH_FRAMING);
temp |= bpc << 9;
if (crtc->mode.flags & DRM_MODE_FLAG_PHSYNC)
temp |= TRANS_DP_HSYNC_ACTIVE_HIGH;
if (crtc->mode.flags & DRM_MODE_FLAG_PVSYNC)
temp |= TRANS_DP_VSYNC_ACTIVE_HIGH;
switch (intel_trans_dp_port_sel(crtc)) {
case PCH_DP_B:
temp |= TRANS_DP_PORT_SEL_B;
break;
case PCH_DP_C:
temp |= TRANS_DP_PORT_SEL_C;
break;
case PCH_DP_D:
temp |= TRANS_DP_PORT_SEL_D;
break;
default:
DRM_DEBUG_KMS("Wrong PCH DP port return. Guess port B\n");
temp |= TRANS_DP_PORT_SEL_B;
break;
}
I915_WRITE(reg, temp);
}
intel_enable_transcoder(dev_priv, pipe);
}
void intel_cpt_verify_modeset(struct drm_device *dev, int pipe)
{
struct drm_i915_private *dev_priv = dev->dev_private;
int dslreg = PIPEDSL(pipe), tc2reg = TRANS_CHICKEN2(pipe);
u32 temp;
temp = I915_READ(dslreg);
udelay(500);
if (wait_for(I915_READ(dslreg) != temp, 5)) {
I915_WRITE(tc2reg, TRANS_AUTOTRAIN_GEN_STALL_DIS);
udelay(250);
I915_WRITE(tc2reg, 0);
if (wait_for(I915_READ(dslreg) != temp, 5))
DRM_ERROR("mode set failed: pipe %d stuck\n", pipe);
}
}
static void ironlake_crtc_enable(struct drm_crtc *crtc)
{
struct drm_device *dev = crtc->dev;
struct drm_i915_private *dev_priv = dev->dev_private;
struct intel_crtc *intel_crtc = to_intel_crtc(crtc);
int pipe = intel_crtc->pipe;
int plane = intel_crtc->plane;
u32 temp;
bool is_pch_port;
if (intel_crtc->active)
return;
intel_crtc->active = true;
intel_update_watermarks(dev);
if (intel_pipe_has_type(crtc, INTEL_OUTPUT_LVDS)) {
temp = I915_READ(PCH_LVDS);
if ((temp & LVDS_PORT_EN) == 0)
I915_WRITE(PCH_LVDS, temp | LVDS_PORT_EN);
}
is_pch_port = intel_crtc_driving_pch(crtc);
if (is_pch_port)
ironlake_fdi_pll_enable(crtc);
else
ironlake_fdi_disable(crtc);
if (dev_priv->pch_pf_size &&
(intel_pipe_has_type(crtc, INTEL_OUTPUT_LVDS) || HAS_eDP)) {
I915_WRITE(PF_CTL(pipe), PF_ENABLE | PF_FILTER_MED_3x3);
I915_WRITE(PF_WIN_POS(pipe), dev_priv->pch_pf_pos);
I915_WRITE(PF_WIN_SZ(pipe), dev_priv->pch_pf_size);
}
intel_crtc_load_lut(crtc);
intel_enable_pipe(dev_priv, pipe, is_pch_port);
intel_enable_plane(dev_priv, plane, pipe);
if (is_pch_port)
ironlake_pch_enable(crtc);
mutex_lock(&dev->struct_mutex);
intel_update_fbc(dev);
mutex_unlock(&dev->struct_mutex);
intel_crtc_update_cursor(crtc, true);
}
static void ironlake_crtc_disable(struct drm_crtc *crtc)
{
struct drm_device *dev = crtc->dev;
struct drm_i915_private *dev_priv = dev->dev_private;
struct intel_crtc *intel_crtc = to_intel_crtc(crtc);
int pipe = intel_crtc->pipe;
int plane = intel_crtc->plane;
u32 reg, temp;
if (!intel_crtc->active)
return;
intel_crtc_wait_for_pending_flips(crtc);
drm_vblank_off(dev, pipe);
intel_crtc_update_cursor(crtc, false);
intel_disable_plane(dev_priv, plane, pipe);
if (dev_priv->cfb_plane == plane)
intel_disable_fbc(dev);
intel_disable_pipe(dev_priv, pipe);
I915_WRITE(PF_CTL(pipe), 0);
I915_WRITE(PF_WIN_SZ(pipe), 0);
ironlake_fdi_disable(crtc);
intel_disable_pch_ports(dev_priv, pipe);
intel_disable_transcoder(dev_priv, pipe);
if (HAS_PCH_CPT(dev)) {
reg = TRANS_DP_CTL(pipe);
temp = I915_READ(reg);
temp &= ~(TRANS_DP_OUTPUT_ENABLE | TRANS_DP_PORT_SEL_MASK);
temp |= TRANS_DP_PORT_SEL_NONE;
I915_WRITE(reg, temp);
temp = I915_READ(PCH_DPLL_SEL);
switch (pipe) {
case 0:
temp &= ~(TRANSA_DPLL_ENABLE | TRANSA_DPLLB_SEL);
break;
case 1:
temp &= ~(TRANSB_DPLL_ENABLE | TRANSB_DPLLB_SEL);
break;
case 2:
temp &= ~(TRANSC_DPLL_ENABLE | TRANSC_DPLLB_SEL);
break;
default:
BUG();
}
I915_WRITE(PCH_DPLL_SEL, temp);
}
if (!intel_crtc->no_pll)
intel_disable_pch_pll(dev_priv, pipe);
reg = FDI_RX_CTL(pipe);
temp = I915_READ(reg);
I915_WRITE(reg, temp & ~FDI_PCDCLK);
reg = FDI_TX_CTL(pipe);
temp = I915_READ(reg);
I915_WRITE(reg, temp & ~FDI_TX_PLL_ENABLE);
POSTING_READ(reg);
udelay(100);
reg = FDI_RX_CTL(pipe);
temp = I915_READ(reg);
I915_WRITE(reg, temp & ~FDI_RX_PLL_ENABLE);
POSTING_READ(reg);
udelay(100);
intel_crtc->active = false;
intel_update_watermarks(dev);
mutex_lock(&dev->struct_mutex);
intel_update_fbc(dev);
intel_clear_scanline_wait(dev);
mutex_unlock(&dev->struct_mutex);
}
static void ironlake_crtc_dpms(struct drm_crtc *crtc, int mode)
{
struct intel_crtc *intel_crtc = to_intel_crtc(crtc);
int pipe = intel_crtc->pipe;
int plane = intel_crtc->plane;
switch (mode) {
case DRM_MODE_DPMS_ON:
case DRM_MODE_DPMS_STANDBY:
case DRM_MODE_DPMS_SUSPEND:
DRM_DEBUG_KMS("crtc %d/%d dpms on\n", pipe, plane);
ironlake_crtc_enable(crtc);
break;
case DRM_MODE_DPMS_OFF:
DRM_DEBUG_KMS("crtc %d/%d dpms off\n", pipe, plane);
ironlake_crtc_disable(crtc);
break;
}
}
static void intel_crtc_dpms_overlay(struct intel_crtc *intel_crtc, bool enable)
{
if (!enable && intel_crtc->overlay) {
struct drm_device *dev = intel_crtc->base.dev;
struct drm_i915_private *dev_priv = dev->dev_private;
mutex_lock(&dev->struct_mutex);
dev_priv->mm.interruptible = false;
(void) intel_overlay_switch_off(intel_crtc->overlay);
dev_priv->mm.interruptible = true;
mutex_unlock(&dev->struct_mutex);
}
}
static void i9xx_crtc_enable(struct drm_crtc *crtc)
{
struct drm_device *dev = crtc->dev;
struct drm_i915_private *dev_priv = dev->dev_private;
struct intel_crtc *intel_crtc = to_intel_crtc(crtc);
int pipe = intel_crtc->pipe;
int plane = intel_crtc->plane;
if (intel_crtc->active)
return;
intel_crtc->active = true;
intel_update_watermarks(dev);
intel_enable_pll(dev_priv, pipe);
intel_enable_pipe(dev_priv, pipe, false);
intel_enable_plane(dev_priv, plane, pipe);
intel_crtc_load_lut(crtc);
intel_update_fbc(dev);
intel_crtc_dpms_overlay(intel_crtc, true);
intel_crtc_update_cursor(crtc, true);
}
static void i9xx_crtc_disable(struct drm_crtc *crtc)
{
struct drm_device *dev = crtc->dev;
struct drm_i915_private *dev_priv = dev->dev_private;
struct intel_crtc *intel_crtc = to_intel_crtc(crtc);
int pipe = intel_crtc->pipe;
int plane = intel_crtc->plane;
if (!intel_crtc->active)
return;
intel_crtc_wait_for_pending_flips(crtc);
drm_vblank_off(dev, pipe);
intel_crtc_dpms_overlay(intel_crtc, false);
intel_crtc_update_cursor(crtc, false);
if (dev_priv->cfb_plane == plane)
intel_disable_fbc(dev);
intel_disable_plane(dev_priv, plane, pipe);
intel_disable_pipe(dev_priv, pipe);
intel_disable_pll(dev_priv, pipe);
intel_crtc->active = false;
intel_update_fbc(dev);
intel_update_watermarks(dev);
intel_clear_scanline_wait(dev);
}
static void i9xx_crtc_dpms(struct drm_crtc *crtc, int mode)
{
switch (mode) {
case DRM_MODE_DPMS_ON:
case DRM_MODE_DPMS_STANDBY:
case DRM_MODE_DPMS_SUSPEND:
i9xx_crtc_enable(crtc);
break;
case DRM_MODE_DPMS_OFF:
i9xx_crtc_disable(crtc);
break;
}
}
static void intel_crtc_dpms(struct drm_crtc *crtc, int mode)
{
struct drm_device *dev = crtc->dev;
struct drm_i915_private *dev_priv = dev->dev_private;
struct drm_i915_master_private *master_priv;
struct intel_crtc *intel_crtc = to_intel_crtc(crtc);
int pipe = intel_crtc->pipe;
bool enabled;
if (intel_crtc->dpms_mode == mode)
return;
intel_crtc->dpms_mode = mode;
dev_priv->display.dpms(crtc, mode);
if (!dev->primary->master)
return;
master_priv = dev->primary->master->driver_priv;
if (!master_priv->sarea_priv)
return;
enabled = crtc->enabled && mode != DRM_MODE_DPMS_OFF;
switch (pipe) {
case 0:
master_priv->sarea_priv->pipeA_w = enabled ? crtc->mode.hdisplay : 0;
master_priv->sarea_priv->pipeA_h = enabled ? crtc->mode.vdisplay : 0;
break;
case 1:
master_priv->sarea_priv->pipeB_w = enabled ? crtc->mode.hdisplay : 0;
master_priv->sarea_priv->pipeB_h = enabled ? crtc->mode.vdisplay : 0;
break;
default:
DRM_ERROR("Can't update pipe %c in SAREA\n", pipe_name(pipe));
break;
}
}
static void intel_crtc_disable(struct drm_crtc *crtc)
{
struct drm_crtc_helper_funcs *crtc_funcs = crtc->helper_private;
struct drm_device *dev = crtc->dev;
crtc_funcs->dpms(crtc, DRM_MODE_DPMS_OFF);
if (crtc->fb) {
mutex_lock(&dev->struct_mutex);
i915_gem_object_unpin(to_intel_framebuffer(crtc->fb)->obj);
mutex_unlock(&dev->struct_mutex);
}
}
static void i9xx_crtc_prepare(struct drm_crtc *crtc)
{
i9xx_crtc_disable(crtc);
}
static void i9xx_crtc_commit(struct drm_crtc *crtc)
{
i9xx_crtc_enable(crtc);
}
static void ironlake_crtc_prepare(struct drm_crtc *crtc)
{
ironlake_crtc_disable(crtc);
}
static void ironlake_crtc_commit(struct drm_crtc *crtc)
{
ironlake_crtc_enable(crtc);
}
void intel_encoder_prepare(struct drm_encoder *encoder)
{
struct drm_encoder_helper_funcs *encoder_funcs = encoder->helper_private;
encoder_funcs->dpms(encoder, DRM_MODE_DPMS_OFF);
}
void intel_encoder_commit(struct drm_encoder *encoder)
{
struct drm_encoder_helper_funcs *encoder_funcs = encoder->helper_private;
struct drm_device *dev = encoder->dev;
struct intel_encoder *intel_encoder = to_intel_encoder(encoder);
struct intel_crtc *intel_crtc = to_intel_crtc(intel_encoder->base.crtc);
encoder_funcs->dpms(encoder, DRM_MODE_DPMS_ON);
if (HAS_PCH_CPT(dev))
intel_cpt_verify_modeset(dev, intel_crtc->pipe);
}
void intel_encoder_destroy(struct drm_encoder *encoder)
{
struct intel_encoder *intel_encoder = to_intel_encoder(encoder);
drm_encoder_cleanup(encoder);
kfree(intel_encoder);
}
static bool intel_crtc_mode_fixup(struct drm_crtc *crtc,
struct drm_display_mode *mode,
struct drm_display_mode *adjusted_mode)
{
struct drm_device *dev = crtc->dev;
if (HAS_PCH_SPLIT(dev)) {
if (mode->clock * 3 > IRONLAKE_FDI_FREQ * 4)
return false;
}
if (adjusted_mode->crtc_htotal == 0)
drm_mode_set_crtcinfo(adjusted_mode, 0);
return true;
}
static int i945_get_display_clock_speed(struct drm_device *dev)
{
return 400000;
}
static int i915_get_display_clock_speed(struct drm_device *dev)
{
return 333000;
}
static int i9xx_misc_get_display_clock_speed(struct drm_device *dev)
{
return 200000;
}
static int i915gm_get_display_clock_speed(struct drm_device *dev)
{
u16 gcfgc = 0;
pci_read_config_word(dev->pdev, GCFGC, &gcfgc);
if (gcfgc & GC_LOW_FREQUENCY_ENABLE)
return 133000;
else {
switch (gcfgc & GC_DISPLAY_CLOCK_MASK) {
case GC_DISPLAY_CLOCK_333_MHZ:
return 333000;
default:
case GC_DISPLAY_CLOCK_190_200_MHZ:
return 190000;
}
}
}
static int i865_get_display_clock_speed(struct drm_device *dev)
{
return 266000;
}
static int i855_get_display_clock_speed(struct drm_device *dev)
{
u16 hpllcc = 0;
switch (hpllcc & GC_CLOCK_CONTROL_MASK) {
case GC_CLOCK_133_200:
case GC_CLOCK_100_200:
return 200000;
case GC_CLOCK_166_250:
return 250000;
case GC_CLOCK_100_133:
return 133000;
}
return 0;
}
static int i830_get_display_clock_speed(struct drm_device *dev)
{
return 133000;
}
static void
fdi_reduce_ratio(u32 *num, u32 *den)
{
while (*num > 0xffffff || *den > 0xffffff) {
*num >>= 1;
*den >>= 1;
}
}
static void
ironlake_compute_m_n(int bits_per_pixel, int nlanes, int pixel_clock,
int link_clock, struct fdi_m_n *m_n)
{
m_n->tu = 64;
m_n->gmch_m = bits_per_pixel * pixel_clock;
m_n->gmch_n = link_clock * nlanes * 8;
fdi_reduce_ratio(&m_n->gmch_m, &m_n->gmch_n);
m_n->link_m = pixel_clock;
m_n->link_n = link_clock;
fdi_reduce_ratio(&m_n->link_m, &m_n->link_n);
}
static unsigned long intel_calculate_wm(unsigned long clock_in_khz,
const struct intel_watermark_params *wm,
int fifo_size,
int pixel_size,
unsigned long latency_ns)
{
long entries_required, wm_size;
entries_required = ((clock_in_khz / 1000) * pixel_size * latency_ns) /
1000;
entries_required = DIV_ROUND_UP(entries_required, wm->cacheline_size);
DRM_DEBUG_KMS("FIFO entries required for mode: %ld\n", entries_required);
wm_size = fifo_size - (entries_required + wm->guard_size);
DRM_DEBUG_KMS("FIFO watermark level: %ld\n", wm_size);
if (wm_size > (long)wm->max_wm)
wm_size = wm->max_wm;
if (wm_size <= 0)
wm_size = wm->default_wm;
return wm_size;
}
static const struct cxsr_latency *intel_get_cxsr_latency(int is_desktop,
int is_ddr3,
int fsb,
int mem)
{
const struct cxsr_latency *latency;
int i;
if (fsb == 0 || mem == 0)
return NULL;
for (i = 0; i < ARRAY_SIZE(cxsr_latency_table); i++) {
latency = &cxsr_latency_table[i];
if (is_desktop == latency->is_desktop &&
is_ddr3 == latency->is_ddr3 &&
fsb == latency->fsb_freq && mem == latency->mem_freq)
return latency;
}
DRM_DEBUG_KMS("Unknown FSB/MEM found, disable CxSR\n");
return NULL;
}
static void pineview_disable_cxsr(struct drm_device *dev)
{
struct drm_i915_private *dev_priv = dev->dev_private;
I915_WRITE(DSPFW3, I915_READ(DSPFW3) & ~PINEVIEW_SELF_REFRESH_EN);
}
static int i9xx_get_fifo_size(struct drm_device *dev, int plane)
{
struct drm_i915_private *dev_priv = dev->dev_private;
uint32_t dsparb = I915_READ(DSPARB);
int size;
size = dsparb & 0x7f;
if (plane)
size = ((dsparb >> DSPARB_CSTART_SHIFT) & 0x7f) - size;
DRM_DEBUG_KMS("FIFO size - (0x%08x) %s: %d\n", dsparb,
plane ? "B" : "A", size);
return size;
}
static int i85x_get_fifo_size(struct drm_device *dev, int plane)
{
struct drm_i915_private *dev_priv = dev->dev_private;
uint32_t dsparb = I915_READ(DSPARB);
int size;
size = dsparb & 0x1ff;
if (plane)
size = ((dsparb >> DSPARB_BEND_SHIFT) & 0x1ff) - size;
size >>= 1;
DRM_DEBUG_KMS("FIFO size - (0x%08x) %s: %d\n", dsparb,
plane ? "B" : "A", size);
return size;
}
static int i845_get_fifo_size(struct drm_device *dev, int plane)
{
struct drm_i915_private *dev_priv = dev->dev_private;
uint32_t dsparb = I915_READ(DSPARB);
int size;
size = dsparb & 0x7f;
size >>= 2;
DRM_DEBUG_KMS("FIFO size - (0x%08x) %s: %d\n", dsparb,
plane ? "B" : "A",
size);
return size;
}
static int i830_get_fifo_size(struct drm_device *dev, int plane)
{
struct drm_i915_private *dev_priv = dev->dev_private;
uint32_t dsparb = I915_READ(DSPARB);
int size;
size = dsparb & 0x7f;
size >>= 1;
DRM_DEBUG_KMS("FIFO size - (0x%08x) %s: %d\n", dsparb,
plane ? "B" : "A", size);
return size;
}
static struct drm_crtc *single_enabled_crtc(struct drm_device *dev)
{
struct drm_crtc *crtc, *enabled = NULL;
list_for_each_entry(crtc, &dev->mode_config.crtc_list, head) {
if (crtc->enabled && crtc->fb) {
if (enabled)
return NULL;
enabled = crtc;
}
}
return enabled;
}
static void pineview_update_wm(struct drm_device *dev)
{
struct drm_i915_private *dev_priv = dev->dev_private;
struct drm_crtc *crtc;
const struct cxsr_latency *latency;
u32 reg;
unsigned long wm;
latency = intel_get_cxsr_latency(IS_PINEVIEW_G(dev), dev_priv->is_ddr3,
dev_priv->fsb_freq, dev_priv->mem_freq);
if (!latency) {
DRM_DEBUG_KMS("Unknown FSB/MEM found, disable CxSR\n");
pineview_disable_cxsr(dev);
return;
}
crtc = single_enabled_crtc(dev);
if (crtc) {
int clock = crtc->mode.clock;
int pixel_size = crtc->fb->bits_per_pixel / 8;
wm = intel_calculate_wm(clock, &pineview_display_wm,
pineview_display_wm.fifo_size,
pixel_size, latency->display_sr);
reg = I915_READ(DSPFW1);
reg &= ~DSPFW_SR_MASK;
reg |= wm << DSPFW_SR_SHIFT;
I915_WRITE(DSPFW1, reg);
DRM_DEBUG_KMS("DSPFW1 register is %x\n", reg);
wm = intel_calculate_wm(clock, &pineview_cursor_wm,
pineview_display_wm.fifo_size,
pixel_size, latency->cursor_sr);
reg = I915_READ(DSPFW3);
reg &= ~DSPFW_CURSOR_SR_MASK;
reg |= (wm & 0x3f) << DSPFW_CURSOR_SR_SHIFT;
I915_WRITE(DSPFW3, reg);
wm = intel_calculate_wm(clock, &pineview_display_hplloff_wm,
pineview_display_hplloff_wm.fifo_size,
pixel_size, latency->display_hpll_disable);
reg = I915_READ(DSPFW3);
reg &= ~DSPFW_HPLL_SR_MASK;
reg |= wm & DSPFW_HPLL_SR_MASK;
I915_WRITE(DSPFW3, reg);
wm = intel_calculate_wm(clock, &pineview_cursor_hplloff_wm,
pineview_display_hplloff_wm.fifo_size,
pixel_size, latency->cursor_hpll_disable);
reg = I915_READ(DSPFW3);
reg &= ~DSPFW_HPLL_CURSOR_MASK;
reg |= (wm & 0x3f) << DSPFW_HPLL_CURSOR_SHIFT;
I915_WRITE(DSPFW3, reg);
DRM_DEBUG_KMS("DSPFW3 register is %x\n", reg);
I915_WRITE(DSPFW3,
I915_READ(DSPFW3) | PINEVIEW_SELF_REFRESH_EN);
DRM_DEBUG_KMS("Self-refresh is enabled\n");
} else {
pineview_disable_cxsr(dev);
DRM_DEBUG_KMS("Self-refresh is disabled\n");
}
}
static bool g4x_compute_wm0(struct drm_device *dev,
int plane,
const struct intel_watermark_params *display,
int display_latency_ns,
const struct intel_watermark_params *cursor,
int cursor_latency_ns,
int *plane_wm,
int *cursor_wm)
{
struct drm_crtc *crtc;
int htotal, hdisplay, clock, pixel_size;
int line_time_us, line_count;
int entries, tlb_miss;
crtc = intel_get_crtc_for_plane(dev, plane);
if (crtc->fb == NULL || !crtc->enabled) {
*cursor_wm = cursor->guard_size;
*plane_wm = display->guard_size;
return false;
}
htotal = crtc->mode.htotal;
hdisplay = crtc->mode.hdisplay;
clock = crtc->mode.clock;
pixel_size = crtc->fb->bits_per_pixel / 8;
entries = ((clock * pixel_size / 1000) * display_latency_ns) / 1000;
tlb_miss = display->fifo_size*display->cacheline_size - hdisplay * 8;
if (tlb_miss > 0)
entries += tlb_miss;
entries = DIV_ROUND_UP(entries, display->cacheline_size);
*plane_wm = entries + display->guard_size;
if (*plane_wm > (int)display->max_wm)
*plane_wm = display->max_wm;
line_time_us = ((htotal * 1000) / clock);
line_count = (cursor_latency_ns / line_time_us + 1000) / 1000;
entries = line_count * 64 * pixel_size;
tlb_miss = cursor->fifo_size*cursor->cacheline_size - hdisplay * 8;
if (tlb_miss > 0)
entries += tlb_miss;
entries = DIV_ROUND_UP(entries, cursor->cacheline_size);
*cursor_wm = entries + cursor->guard_size;
if (*cursor_wm > (int)cursor->max_wm)
*cursor_wm = (int)cursor->max_wm;
return true;
}
static bool g4x_check_srwm(struct drm_device *dev,
int display_wm, int cursor_wm,
const struct intel_watermark_params *display,
const struct intel_watermark_params *cursor)
{
DRM_DEBUG_KMS("SR watermark: display plane %d, cursor %d\n",
display_wm, cursor_wm);
if (display_wm > display->max_wm) {
DRM_DEBUG_KMS("display watermark is too large(%d/%ld), disabling\n",
display_wm, display->max_wm);
return false;
}
if (cursor_wm > cursor->max_wm) {
DRM_DEBUG_KMS("cursor watermark is too large(%d/%ld), disabling\n",
cursor_wm, cursor->max_wm);
return false;
}
if (!(display_wm || cursor_wm)) {
DRM_DEBUG_KMS("SR latency is 0, disabling\n");
return false;
}
return true;
}
static bool g4x_compute_srwm(struct drm_device *dev,
int plane,
int latency_ns,
const struct intel_watermark_params *display,
const struct intel_watermark_params *cursor,
int *display_wm, int *cursor_wm)
{
struct drm_crtc *crtc;
int hdisplay, htotal, pixel_size, clock;
unsigned long line_time_us;
int line_count, line_size;
int small, large;
int entries;
if (!latency_ns) {
*display_wm = *cursor_wm = 0;
return false;
}
crtc = intel_get_crtc_for_plane(dev, plane);
hdisplay = crtc->mode.hdisplay;
htotal = crtc->mode.htotal;
clock = crtc->mode.clock;
pixel_size = crtc->fb->bits_per_pixel / 8;
line_time_us = (htotal * 1000) / clock;
line_count = (latency_ns / line_time_us + 1000) / 1000;
line_size = hdisplay * pixel_size;
small = ((clock * pixel_size / 1000) * latency_ns) / 1000;
large = line_count * line_size;
entries = DIV_ROUND_UP(min(small, large), display->cacheline_size);
*display_wm = entries + display->guard_size;
entries = line_count * pixel_size * 64;
entries = DIV_ROUND_UP(entries, cursor->cacheline_size);
*cursor_wm = entries + cursor->guard_size;
return g4x_check_srwm(dev,
*display_wm, *cursor_wm,
display, cursor);
}
static void g4x_update_wm(struct drm_device *dev)
{
static const int sr_latency_ns = 12000;
struct drm_i915_private *dev_priv = dev->dev_private;
int planea_wm, planeb_wm, cursora_wm, cursorb_wm;
int plane_sr, cursor_sr;
unsigned int enabled = 0;
if (g4x_compute_wm0(dev, 0,
&g4x_wm_info, latency_ns,
&g4x_cursor_wm_info, latency_ns,
&planea_wm, &cursora_wm))
enabled |= 1;
if (g4x_compute_wm0(dev, 1,
&g4x_wm_info, latency_ns,
&g4x_cursor_wm_info, latency_ns,
&planeb_wm, &cursorb_wm))
enabled |= 2;
plane_sr = cursor_sr = 0;
if (single_plane_enabled(enabled) &&
g4x_compute_srwm(dev, ffs(enabled) - 1,
sr_latency_ns,
&g4x_wm_info,
&g4x_cursor_wm_info,
&plane_sr, &cursor_sr))
I915_WRITE(FW_BLC_SELF, FW_BLC_SELF_EN);
else
I915_WRITE(FW_BLC_SELF,
I915_READ(FW_BLC_SELF) & ~FW_BLC_SELF_EN);
DRM_DEBUG_KMS("Setting FIFO watermarks - A: plane=%d, cursor=%d, B: plane=%d, cursor=%d, SR: plane=%d, cursor=%d\n",
planea_wm, cursora_wm,
planeb_wm, cursorb_wm,
plane_sr, cursor_sr);
I915_WRITE(DSPFW1,
(plane_sr << DSPFW_SR_SHIFT) |
(cursorb_wm << DSPFW_CURSORB_SHIFT) |
(planeb_wm << DSPFW_PLANEB_SHIFT) |
planea_wm);
I915_WRITE(DSPFW2,
(I915_READ(DSPFW2) & DSPFW_CURSORA_MASK) |
(cursora_wm << DSPFW_CURSORA_SHIFT));
I915_WRITE(DSPFW3,
(I915_READ(DSPFW3) & ~DSPFW_HPLL_SR_EN) |
(cursor_sr << DSPFW_CURSOR_SR_SHIFT));
}
static void i965_update_wm(struct drm_device *dev)
{
struct drm_i915_private *dev_priv = dev->dev_private;
struct drm_crtc *crtc;
int srwm = 1;
int cursor_sr = 16;
crtc = single_enabled_crtc(dev);
if (crtc) {
static const int sr_latency_ns = 12000;
int clock = crtc->mode.clock;
int htotal = crtc->mode.htotal;
int hdisplay = crtc->mode.hdisplay;
int pixel_size = crtc->fb->bits_per_pixel / 8;
unsigned long line_time_us;
int entries;
line_time_us = ((htotal * 1000) / clock);
entries = (((sr_latency_ns / line_time_us) + 1000) / 1000) *
pixel_size * hdisplay;
entries = DIV_ROUND_UP(entries, I915_FIFO_LINE_SIZE);
srwm = I965_FIFO_SIZE - entries;
if (srwm < 0)
srwm = 1;
srwm &= 0x1ff;
DRM_DEBUG_KMS("self-refresh entries: %d, wm: %d\n",
entries, srwm);
entries = (((sr_latency_ns / line_time_us) + 1000) / 1000) *
pixel_size * 64;
entries = DIV_ROUND_UP(entries,
i965_cursor_wm_info.cacheline_size);
cursor_sr = i965_cursor_wm_info.fifo_size -
(entries + i965_cursor_wm_info.guard_size);
if (cursor_sr > i965_cursor_wm_info.max_wm)
cursor_sr = i965_cursor_wm_info.max_wm;
DRM_DEBUG_KMS("self-refresh watermark: display plane %d "
"cursor %d\n", srwm, cursor_sr);
if (IS_CRESTLINE(dev))
I915_WRITE(FW_BLC_SELF, FW_BLC_SELF_EN);
} else {
if (IS_CRESTLINE(dev))
I915_WRITE(FW_BLC_SELF, I915_READ(FW_BLC_SELF)
& ~FW_BLC_SELF_EN);
}
DRM_DEBUG_KMS("Setting FIFO watermarks - A: 8, B: 8, C: 8, SR %d\n",
srwm);
I915_WRITE(DSPFW1, (srwm << DSPFW_SR_SHIFT) |
(8 << 16) | (8 << 8) | (8 << 0));
I915_WRITE(DSPFW2, (8 << 8) | (8 << 0));
I915_WRITE(DSPFW3, (cursor_sr << DSPFW_CURSOR_SR_SHIFT));
}
static void i9xx_update_wm(struct drm_device *dev)
{
struct drm_i915_private *dev_priv = dev->dev_private;
const struct intel_watermark_params *wm_info;
uint32_t fwater_lo;
uint32_t fwater_hi;
int cwm, srwm = 1;
int fifo_size;
int planea_wm, planeb_wm;
struct drm_crtc *crtc, *enabled = NULL;
if (IS_I945GM(dev))
wm_info = &i945_wm_info;
else if (!IS_GEN2(dev))
wm_info = &i915_wm_info;
else
wm_info = &i855_wm_info;
fifo_size = dev_priv->display.get_fifo_size(dev, 0);
crtc = intel_get_crtc_for_plane(dev, 0);
if (crtc->enabled && crtc->fb) {
planea_wm = intel_calculate_wm(crtc->mode.clock,
wm_info, fifo_size,
crtc->fb->bits_per_pixel / 8,
latency_ns);
enabled = crtc;
} else
planea_wm = fifo_size - wm_info->guard_size;
fifo_size = dev_priv->display.get_fifo_size(dev, 1);
crtc = intel_get_crtc_for_plane(dev, 1);
if (crtc->enabled && crtc->fb) {
planeb_wm = intel_calculate_wm(crtc->mode.clock,
wm_info, fifo_size,
crtc->fb->bits_per_pixel / 8,
latency_ns);
if (enabled == NULL)
enabled = crtc;
else
enabled = NULL;
} else
planeb_wm = fifo_size - wm_info->guard_size;
DRM_DEBUG_KMS("FIFO watermarks - A: %d, B: %d\n", planea_wm, planeb_wm);
cwm = 2;
if (IS_I945G(dev) || IS_I945GM(dev))
I915_WRITE(FW_BLC_SELF, FW_BLC_SELF_EN_MASK | 0);
else if (IS_I915GM(dev))
I915_WRITE(INSTPM, I915_READ(INSTPM) & ~INSTPM_SELF_EN);
if (HAS_FW_BLC(dev) && enabled) {
static const int sr_latency_ns = 6000;
int clock = enabled->mode.clock;
int htotal = enabled->mode.htotal;
int hdisplay = enabled->mode.hdisplay;
int pixel_size = enabled->fb->bits_per_pixel / 8;
unsigned long line_time_us;
int entries;
line_time_us = (htotal * 1000) / clock;
entries = (((sr_latency_ns / line_time_us) + 1000) / 1000) *
pixel_size * hdisplay;
entries = DIV_ROUND_UP(entries, wm_info->cacheline_size);
DRM_DEBUG_KMS("self-refresh entries: %d\n", entries);
srwm = wm_info->fifo_size - entries;
if (srwm < 0)
srwm = 1;
if (IS_I945G(dev) || IS_I945GM(dev))
I915_WRITE(FW_BLC_SELF,
FW_BLC_SELF_FIFO_MASK | (srwm & 0xff));
else if (IS_I915GM(dev))
I915_WRITE(FW_BLC_SELF, srwm & 0x3f);
}
DRM_DEBUG_KMS("Setting FIFO watermarks - A: %d, B: %d, C: %d, SR %d\n",
planea_wm, planeb_wm, cwm, srwm);
fwater_lo = ((planeb_wm & 0x3f) << 16) | (planea_wm & 0x3f);
fwater_hi = (cwm & 0x1f);
fwater_lo = fwater_lo | (1 << 24) | (1 << 8);
fwater_hi = fwater_hi | (1 << 8);
I915_WRITE(FW_BLC, fwater_lo);
I915_WRITE(FW_BLC2, fwater_hi);
if (HAS_FW_BLC(dev)) {
if (enabled) {
if (IS_I945G(dev) || IS_I945GM(dev))
I915_WRITE(FW_BLC_SELF,
FW_BLC_SELF_EN_MASK | FW_BLC_SELF_EN);
else if (IS_I915GM(dev))
I915_WRITE(INSTPM, I915_READ(INSTPM) | INSTPM_SELF_EN);
DRM_DEBUG_KMS("memory self refresh enabled\n");
} else
DRM_DEBUG_KMS("memory self refresh disabled\n");
}
}
static void i830_update_wm(struct drm_device *dev)
{
struct drm_i915_private *dev_priv = dev->dev_private;
struct drm_crtc *crtc;
uint32_t fwater_lo;
int planea_wm;
crtc = single_enabled_crtc(dev);
if (crtc == NULL)
return;
planea_wm = intel_calculate_wm(crtc->mode.clock, &i830_wm_info,
dev_priv->display.get_fifo_size(dev, 0),
crtc->fb->bits_per_pixel / 8,
latency_ns);
fwater_lo = I915_READ(FW_BLC) & ~0xfff;
fwater_lo |= (3<<8) | planea_wm;
DRM_DEBUG_KMS("Setting FIFO watermarks - A: %d\n", planea_wm);
I915_WRITE(FW_BLC, fwater_lo);
}
static bool ironlake_check_srwm(struct drm_device *dev, int level,
int fbc_wm, int display_wm, int cursor_wm,
const struct intel_watermark_params *display,
const struct intel_watermark_params *cursor)
{
struct drm_i915_private *dev_priv = dev->dev_private;
DRM_DEBUG_KMS("watermark %d: display plane %d, fbc lines %d,"
" cursor %d\n", level, display_wm, fbc_wm, cursor_wm);
if (fbc_wm > SNB_FBC_MAX_SRWM) {
DRM_DEBUG_KMS("fbc watermark(%d) is too large(%d), disabling wm%d+\n",
fbc_wm, SNB_FBC_MAX_SRWM, level);
I915_WRITE(DISP_ARB_CTL,
I915_READ(DISP_ARB_CTL) | DISP_FBC_WM_DIS);
return false;
}
if (display_wm > display->max_wm) {
DRM_DEBUG_KMS("display watermark(%d) is too large(%d), disabling wm%d+\n",
display_wm, SNB_DISPLAY_MAX_SRWM, level);
return false;
}
if (cursor_wm > cursor->max_wm) {
DRM_DEBUG_KMS("cursor watermark(%d) is too large(%d), disabling wm%d+\n",
cursor_wm, SNB_CURSOR_MAX_SRWM, level);
return false;
}
if (!(fbc_wm || display_wm || cursor_wm)) {
DRM_DEBUG_KMS("latency %d is 0, disabling wm%d+\n", level, level);
return false;
}
return true;
}
static bool ironlake_compute_srwm(struct drm_device *dev, int level, int plane,
int latency_ns,
const struct intel_watermark_params *display,
const struct intel_watermark_params *cursor,
int *fbc_wm, int *display_wm, int *cursor_wm)
{
struct drm_crtc *crtc;
unsigned long line_time_us;
int hdisplay, htotal, pixel_size, clock;
int line_count, line_size;
int small, large;
int entries;
if (!latency_ns) {
*fbc_wm = *display_wm = *cursor_wm = 0;
return false;
}
crtc = intel_get_crtc_for_plane(dev, plane);
hdisplay = crtc->mode.hdisplay;
htotal = crtc->mode.htotal;
clock = crtc->mode.clock;
pixel_size = crtc->fb->bits_per_pixel / 8;
line_time_us = (htotal * 1000) / clock;
line_count = (latency_ns / line_time_us + 1000) / 1000;
line_size = hdisplay * pixel_size;
small = ((clock * pixel_size / 1000) * latency_ns) / 1000;
large = line_count * line_size;
entries = DIV_ROUND_UP(min(small, large), display->cacheline_size);
*display_wm = entries + display->guard_size;
*fbc_wm = DIV_ROUND_UP(*display_wm * 64, line_size) + 2;
entries = line_count * pixel_size * 64;
entries = DIV_ROUND_UP(entries, cursor->cacheline_size);
*cursor_wm = entries + cursor->guard_size;
return ironlake_check_srwm(dev, level,
*fbc_wm, *display_wm, *cursor_wm,
display, cursor);
}
static void ironlake_update_wm(struct drm_device *dev)
{
struct drm_i915_private *dev_priv = dev->dev_private;
int fbc_wm, plane_wm, cursor_wm;
unsigned int enabled;
enabled = 0;
if (g4x_compute_wm0(dev, 0,
&ironlake_display_wm_info,
ILK_LP0_PLANE_LATENCY,
&ironlake_cursor_wm_info,
ILK_LP0_CURSOR_LATENCY,
&plane_wm, &cursor_wm)) {
I915_WRITE(WM0_PIPEA_ILK,
(plane_wm << WM0_PIPE_PLANE_SHIFT) | cursor_wm);
DRM_DEBUG_KMS("FIFO watermarks For pipe A -"
" plane %d, " "cursor: %d\n",
plane_wm, cursor_wm);
enabled |= 1;
}
if (g4x_compute_wm0(dev, 1,
&ironlake_display_wm_info,
ILK_LP0_PLANE_LATENCY,
&ironlake_cursor_wm_info,
ILK_LP0_CURSOR_LATENCY,
&plane_wm, &cursor_wm)) {
I915_WRITE(WM0_PIPEB_ILK,
(plane_wm << WM0_PIPE_PLANE_SHIFT) | cursor_wm);
DRM_DEBUG_KMS("FIFO watermarks For pipe B -"
" plane %d, cursor: %d\n",
plane_wm, cursor_wm);
enabled |= 2;
}
I915_WRITE(WM3_LP_ILK, 0);
I915_WRITE(WM2_LP_ILK, 0);
I915_WRITE(WM1_LP_ILK, 0);
if (!single_plane_enabled(enabled))
return;
enabled = ffs(enabled) - 1;
if (!ironlake_compute_srwm(dev, 1, enabled,
ILK_READ_WM1_LATENCY() * 500,
&ironlake_display_srwm_info,
&ironlake_cursor_srwm_info,
&fbc_wm, &plane_wm, &cursor_wm))
return;
I915_WRITE(WM1_LP_ILK,
WM1_LP_SR_EN |
(ILK_READ_WM1_LATENCY() << WM1_LP_LATENCY_SHIFT) |
(fbc_wm << WM1_LP_FBC_SHIFT) |
(plane_wm << WM1_LP_SR_SHIFT) |
cursor_wm);
if (!ironlake_compute_srwm(dev, 2, enabled,
ILK_READ_WM2_LATENCY() * 500,
&ironlake_display_srwm_info,
&ironlake_cursor_srwm_info,
&fbc_wm, &plane_wm, &cursor_wm))
return;
I915_WRITE(WM2_LP_ILK,
WM2_LP_EN |
(ILK_READ_WM2_LATENCY() << WM1_LP_LATENCY_SHIFT) |
(fbc_wm << WM1_LP_FBC_SHIFT) |
(plane_wm << WM1_LP_SR_SHIFT) |
cursor_wm);
}
void sandybridge_update_wm(struct drm_device *dev)
{
struct drm_i915_private *dev_priv = dev->dev_private;
int latency = SNB_READ_WM0_LATENCY() * 100;
int fbc_wm, plane_wm, cursor_wm;
unsigned int enabled;
enabled = 0;
if (g4x_compute_wm0(dev, 0,
&sandybridge_display_wm_info, latency,
&sandybridge_cursor_wm_info, latency,
&plane_wm, &cursor_wm)) {
I915_WRITE(WM0_PIPEA_ILK,
(plane_wm << WM0_PIPE_PLANE_SHIFT) | cursor_wm);
DRM_DEBUG_KMS("FIFO watermarks For pipe A -"
" plane %d, " "cursor: %d\n",
plane_wm, cursor_wm);
enabled |= 1;
}
if (g4x_compute_wm0(dev, 1,
&sandybridge_display_wm_info, latency,
&sandybridge_cursor_wm_info, latency,
&plane_wm, &cursor_wm)) {
I915_WRITE(WM0_PIPEB_ILK,
(plane_wm << WM0_PIPE_PLANE_SHIFT) | cursor_wm);
DRM_DEBUG_KMS("FIFO watermarks For pipe B -"
" plane %d, cursor: %d\n",
plane_wm, cursor_wm);
enabled |= 2;
}
if (IS_IVYBRIDGE(dev) &&
g4x_compute_wm0(dev, 2,
&sandybridge_display_wm_info, latency,
&sandybridge_cursor_wm_info, latency,
&plane_wm, &cursor_wm)) {
I915_WRITE(WM0_PIPEC_IVB,
(plane_wm << WM0_PIPE_PLANE_SHIFT) | cursor_wm);
DRM_DEBUG_KMS("FIFO watermarks For pipe C -"
" plane %d, cursor: %d\n",
plane_wm, cursor_wm);
enabled |= 3;
}
I915_WRITE(WM3_LP_ILK, 0);
I915_WRITE(WM2_LP_ILK, 0);
I915_WRITE(WM1_LP_ILK, 0);
if (!single_plane_enabled(enabled) ||
dev_priv->sprite_scaling_enabled)
return;
enabled = ffs(enabled) - 1;
if (!ironlake_compute_srwm(dev, 1, enabled,
SNB_READ_WM1_LATENCY() * 500,
&sandybridge_display_srwm_info,
&sandybridge_cursor_srwm_info,
&fbc_wm, &plane_wm, &cursor_wm))
return;
I915_WRITE(WM1_LP_ILK,
WM1_LP_SR_EN |
(SNB_READ_WM1_LATENCY() << WM1_LP_LATENCY_SHIFT) |
(fbc_wm << WM1_LP_FBC_SHIFT) |
(plane_wm << WM1_LP_SR_SHIFT) |
cursor_wm);
if (!ironlake_compute_srwm(dev, 2, enabled,
SNB_READ_WM2_LATENCY() * 500,
&sandybridge_display_srwm_info,
&sandybridge_cursor_srwm_info,
&fbc_wm, &plane_wm, &cursor_wm))
return;
I915_WRITE(WM2_LP_ILK,
WM2_LP_EN |
(SNB_READ_WM2_LATENCY() << WM1_LP_LATENCY_SHIFT) |
(fbc_wm << WM1_LP_FBC_SHIFT) |
(plane_wm << WM1_LP_SR_SHIFT) |
cursor_wm);
if (!ironlake_compute_srwm(dev, 3, enabled,
SNB_READ_WM3_LATENCY() * 500,
&sandybridge_display_srwm_info,
&sandybridge_cursor_srwm_info,
&fbc_wm, &plane_wm, &cursor_wm))
return;
I915_WRITE(WM3_LP_ILK,
WM3_LP_EN |
(SNB_READ_WM3_LATENCY() << WM1_LP_LATENCY_SHIFT) |
(fbc_wm << WM1_LP_FBC_SHIFT) |
(plane_wm << WM1_LP_SR_SHIFT) |
cursor_wm);
}
static bool
sandybridge_compute_sprite_wm(struct drm_device *dev, int plane,
uint32_t sprite_width, int pixel_size,
const struct intel_watermark_params *display,
int display_latency_ns, int *sprite_wm)
{
struct drm_crtc *crtc;
int clock;
int entries, tlb_miss;
crtc = intel_get_crtc_for_plane(dev, plane);
if (crtc->fb == NULL || !crtc->enabled) {
*sprite_wm = display->guard_size;
return false;
}
clock = crtc->mode.clock;
entries = ((clock * pixel_size / 1000) * display_latency_ns) / 1000;
tlb_miss = display->fifo_size*display->cacheline_size -
sprite_width * 8;
if (tlb_miss > 0)
entries += tlb_miss;
entries = DIV_ROUND_UP(entries, display->cacheline_size);
*sprite_wm = entries + display->guard_size;
if (*sprite_wm > (int)display->max_wm)
*sprite_wm = display->max_wm;
return true;
}
static bool
sandybridge_compute_sprite_srwm(struct drm_device *dev, int plane,
uint32_t sprite_width, int pixel_size,
const struct intel_watermark_params *display,
int latency_ns, int *sprite_wm)
{
struct drm_crtc *crtc;
unsigned long line_time_us;
int clock;
int line_count, line_size;
int small, large;
int entries;
if (!latency_ns) {
*sprite_wm = 0;
return false;
}
crtc = intel_get_crtc_for_plane(dev, plane);
clock = crtc->mode.clock;
if (!clock) {
*sprite_wm = 0;
return false;
}
line_time_us = (sprite_width * 1000) / clock;
if (!line_time_us) {
*sprite_wm = 0;
return false;
}
line_count = (latency_ns / line_time_us + 1000) / 1000;
line_size = sprite_width * pixel_size;
small = ((clock * pixel_size / 1000) * latency_ns) / 1000;
large = line_count * line_size;
entries = DIV_ROUND_UP(min(small, large), display->cacheline_size);
*sprite_wm = entries + display->guard_size;
return *sprite_wm > 0x3ff ? false : true;
}
static void sandybridge_update_sprite_wm(struct drm_device *dev, int pipe,
uint32_t sprite_width, int pixel_size)
{
struct drm_i915_private *dev_priv = dev->dev_private;
int latency = SNB_READ_WM0_LATENCY() * 100;
int sprite_wm, reg;
int ret;
switch (pipe) {
case 0:
reg = WM0_PIPEA_ILK;
break;
case 1:
reg = WM0_PIPEB_ILK;
break;
case 2:
reg = WM0_PIPEC_IVB;
break;
default:
return;
}
ret = sandybridge_compute_sprite_wm(dev, pipe, sprite_width, pixel_size,
&sandybridge_display_wm_info,
latency, &sprite_wm);
if (!ret) {
DRM_DEBUG_KMS("failed to compute sprite wm for pipe %d\n",
pipe);
return;
}
I915_WRITE(reg, I915_READ(reg) | (sprite_wm << WM0_PIPE_SPRITE_SHIFT));
DRM_DEBUG_KMS("sprite watermarks For pipe %d - %d\n", pipe, sprite_wm);
ret = sandybridge_compute_sprite_srwm(dev, pipe, sprite_width,
pixel_size,
&sandybridge_display_srwm_info,
SNB_READ_WM1_LATENCY() * 500,
&sprite_wm);
if (!ret) {
DRM_DEBUG_KMS("failed to compute sprite lp1 wm on pipe %d\n",
pipe);
return;
}
I915_WRITE(WM1S_LP_ILK, sprite_wm);
if (!IS_IVYBRIDGE(dev))
return;
ret = sandybridge_compute_sprite_srwm(dev, pipe, sprite_width,
pixel_size,
&sandybridge_display_srwm_info,
SNB_READ_WM2_LATENCY() * 500,
&sprite_wm);
if (!ret) {
DRM_DEBUG_KMS("failed to compute sprite lp2 wm on pipe %d\n",
pipe);
return;
}
I915_WRITE(WM2S_LP_IVB, sprite_wm);
ret = sandybridge_compute_sprite_srwm(dev, pipe, sprite_width,
pixel_size,
&sandybridge_display_srwm_info,
SNB_READ_WM3_LATENCY() * 500,
&sprite_wm);
if (!ret) {
DRM_DEBUG_KMS("failed to compute sprite lp3 wm on pipe %d\n",
pipe);
return;
}
I915_WRITE(WM3S_LP_IVB, sprite_wm);
}
static void intel_update_watermarks(struct drm_device *dev)
{
struct drm_i915_private *dev_priv = dev->dev_private;
if (dev_priv->display.update_wm)
dev_priv->display.update_wm(dev);
}
void intel_update_sprite_watermarks(struct drm_device *dev, int pipe,
uint32_t sprite_width, int pixel_size)
{
struct drm_i915_private *dev_priv = dev->dev_private;
if (dev_priv->display.update_sprite_wm)
dev_priv->display.update_sprite_wm(dev, pipe, sprite_width,
pixel_size);
}
static inline bool intel_panel_use_ssc(struct drm_i915_private *dev_priv)
{
if (i915_panel_use_ssc >= 0)
return i915_panel_use_ssc != 0;
return dev_priv->lvds_use_ssc
&& !(dev_priv->quirks & QUIRK_LVDS_SSC_DISABLE);
}
static bool intel_choose_pipe_bpp_dither(struct drm_crtc *crtc,
unsigned int *pipe_bpp,
struct drm_display_mode *mode)
{
struct drm_device *dev = crtc->dev;
struct drm_i915_private *dev_priv = dev->dev_private;
struct drm_encoder *encoder;
struct drm_connector *connector;
unsigned int display_bpc = UINT_MAX, bpc;
list_for_each_entry(encoder, &dev->mode_config.encoder_list, head) {
struct intel_encoder *intel_encoder = to_intel_encoder(encoder);
if (encoder->crtc != crtc)
continue;
if (intel_encoder->type == INTEL_OUTPUT_LVDS) {
unsigned int lvds_bpc;
if ((I915_READ(PCH_LVDS) & LVDS_A3_POWER_MASK) ==
LVDS_A3_POWER_UP)
lvds_bpc = 8;
else
lvds_bpc = 6;
if (lvds_bpc < display_bpc) {
DRM_DEBUG_KMS("clamping display bpc (was %d) to LVDS (%d)\n", display_bpc, lvds_bpc);
display_bpc = lvds_bpc;
}
continue;
}
if (intel_encoder->type == INTEL_OUTPUT_EDP) {
unsigned int edp_bpc = dev_priv->edp.bpp / 3;
if (edp_bpc < display_bpc) {
DRM_DEBUG_KMS("clamping display bpc (was %d) to eDP (%d)\n", display_bpc, edp_bpc);
display_bpc = edp_bpc;
}
continue;
}
list_for_each_entry(connector, &dev->mode_config.connector_list,
head) {
if (connector->encoder != encoder)
continue;
if (connector->display_info.bpc &&
connector->display_info.bpc < display_bpc) {
DRM_DEBUG_KMS("clamping display bpc (was %d) to EDID reported max of %d\n", display_bpc, connector->display_info.bpc);
display_bpc = connector->display_info.bpc;
}
}
if (intel_encoder->type == INTEL_OUTPUT_HDMI) {
if (display_bpc > 8 && display_bpc < 12) {
DRM_DEBUG_KMS("forcing bpc to 12 for HDMI\n");
display_bpc = 12;
} else {
DRM_DEBUG_KMS("forcing bpc to 8 for HDMI\n");
display_bpc = 8;
}
}
}
if (mode->private_flags & INTEL_MODE_DP_FORCE_6BPC) {
DRM_DEBUG_KMS("Dithering DP to 6bpc\n");
display_bpc = 6;
}
switch (crtc->fb->depth) {
case 8:
bpc = 8;
break;
case 15:
case 16:
bpc = 6;
break;
case 24:
bpc = 8;
break;
case 30:
bpc = 10;
break;
case 48:
bpc = 12;
break;
default:
DRM_DEBUG("unsupported depth, assuming 24 bits\n");
bpc = min((unsigned int)8, display_bpc);
break;
}
display_bpc = min(display_bpc, bpc);
DRM_DEBUG_KMS("setting pipe bpc to %d (max display bpc %d)\n",
bpc, display_bpc);
*pipe_bpp = display_bpc * 3;
return display_bpc != bpc;
}
static int i9xx_crtc_mode_set(struct drm_crtc *crtc,
struct drm_display_mode *mode,
struct drm_display_mode *adjusted_mode,
int x, int y,
struct drm_framebuffer *old_fb)
{
struct drm_device *dev = crtc->dev;
struct drm_i915_private *dev_priv = dev->dev_private;
struct intel_crtc *intel_crtc = to_intel_crtc(crtc);
int pipe = intel_crtc->pipe;
int plane = intel_crtc->plane;
int refclk, num_connectors = 0;
intel_clock_t clock, reduced_clock;
u32 dpll, fp = 0, fp2 = 0, dspcntr, pipeconf;
bool ok, has_reduced_clock = false, is_sdvo = false, is_dvo = false;
bool is_crt = false, is_lvds = false, is_tv = false, is_dp = false;
struct drm_mode_config *mode_config = &dev->mode_config;
struct intel_encoder *encoder;
const intel_limit_t *limit;
int ret;
u32 temp;
u32 lvds_sync = 0;
list_for_each_entry(encoder, &mode_config->encoder_list, base.head) {
if (encoder->base.crtc != crtc)
continue;
switch (encoder->type) {
case INTEL_OUTPUT_LVDS:
is_lvds = true;
break;
case INTEL_OUTPUT_SDVO:
case INTEL_OUTPUT_HDMI:
is_sdvo = true;
if (encoder->needs_tv_clock)
is_tv = true;
break;
case INTEL_OUTPUT_DVO:
is_dvo = true;
break;
case INTEL_OUTPUT_TVOUT:
is_tv = true;
break;
case INTEL_OUTPUT_ANALOG:
is_crt = true;
break;
case INTEL_OUTPUT_DISPLAYPORT:
is_dp = true;
break;
}
num_connectors++;
}
if (is_lvds && intel_panel_use_ssc(dev_priv) && num_connectors < 2) {
refclk = dev_priv->lvds_ssc_freq * 1000;
DRM_DEBUG_KMS("using SSC reference clock of %d MHz\n",
refclk / 1000);
} else if (!IS_GEN2(dev)) {
refclk = 96000;
} else {
refclk = 48000;
}
limit = intel_limit(crtc, refclk);
ok = limit->find_pll(limit, crtc, adjusted_mode->clock, refclk, &clock);
if (!ok) {
DRM_ERROR("Couldn't find PLL settings for mode!\n");
return -EINVAL;
}
intel_crtc_update_cursor(crtc, true);
if (is_lvds && dev_priv->lvds_downclock_avail) {
has_reduced_clock = limit->find_pll(limit, crtc,
dev_priv->lvds_downclock,
refclk,
&reduced_clock);
if (has_reduced_clock && (clock.p != reduced_clock.p)) {
DRM_DEBUG_KMS("Different P is found for "
"LVDS clock/downclock\n");
has_reduced_clock = 0;
}
}
if (is_sdvo && is_tv) {
if (adjusted_mode->clock >= 100000
&& adjusted_mode->clock < 140500) {
clock.p1 = 2;
clock.p2 = 10;
clock.n = 3;
clock.m1 = 16;
clock.m2 = 8;
} else if (adjusted_mode->clock >= 140500
&& adjusted_mode->clock <= 200000) {
clock.p1 = 1;
clock.p2 = 10;
clock.n = 6;
clock.m1 = 12;
clock.m2 = 8;
}
}
if (IS_PINEVIEW(dev)) {
fp = (1 << clock.n) << 16 | clock.m1 << 8 | clock.m2;
if (has_reduced_clock)
fp2 = (1 << reduced_clock.n) << 16 |
reduced_clock.m1 << 8 | reduced_clock.m2;
} else {
fp = clock.n << 16 | clock.m1 << 8 | clock.m2;
if (has_reduced_clock)
fp2 = reduced_clock.n << 16 | reduced_clock.m1 << 8 |
reduced_clock.m2;
}
dpll = DPLL_VGA_MODE_DIS;
if (!IS_GEN2(dev)) {
if (is_lvds)
dpll |= DPLLB_MODE_LVDS;
else
dpll |= DPLLB_MODE_DAC_SERIAL;
if (is_sdvo) {
int pixel_multiplier = intel_mode_get_pixel_multiplier(adjusted_mode);
if (pixel_multiplier > 1) {
if (IS_I945G(dev) || IS_I945GM(dev) || IS_G33(dev))
dpll |= (pixel_multiplier - 1) << SDVO_MULTIPLIER_SHIFT_HIRES;
}
dpll |= DPLL_DVO_HIGH_SPEED;
}
if (is_dp)
dpll |= DPLL_DVO_HIGH_SPEED;
if (IS_PINEVIEW(dev))
dpll |= (1 << (clock.p1 - 1)) << DPLL_FPA01_P1_POST_DIV_SHIFT_PINEVIEW;
else {
dpll |= (1 << (clock.p1 - 1)) << DPLL_FPA01_P1_POST_DIV_SHIFT;
if (IS_G4X(dev) && has_reduced_clock)
dpll |= (1 << (reduced_clock.p1 - 1)) << DPLL_FPA1_P1_POST_DIV_SHIFT;
}
switch (clock.p2) {
case 5:
dpll |= DPLL_DAC_SERIAL_P2_CLOCK_DIV_5;
break;
case 7:
dpll |= DPLLB_LVDS_P2_CLOCK_DIV_7;
break;
case 10:
dpll |= DPLL_DAC_SERIAL_P2_CLOCK_DIV_10;
break;
case 14:
dpll |= DPLLB_LVDS_P2_CLOCK_DIV_14;
break;
}
if (INTEL_INFO(dev)->gen >= 4)
dpll |= (6 << PLL_LOAD_PULSE_PHASE_SHIFT);
} else {
if (is_lvds) {
dpll |= (1 << (clock.p1 - 1)) << DPLL_FPA01_P1_POST_DIV_SHIFT;
} else {
if (clock.p1 == 2)
dpll |= PLL_P1_DIVIDE_BY_TWO;
else
dpll |= (clock.p1 - 2) << DPLL_FPA01_P1_POST_DIV_SHIFT;
if (clock.p2 == 4)
dpll |= PLL_P2_DIVIDE_BY_4;
}
}
if (is_sdvo && is_tv)
dpll |= PLL_REF_INPUT_TVCLKINBC;
else if (is_tv)
dpll |= 3;
else if (is_lvds && intel_panel_use_ssc(dev_priv) && num_connectors < 2)
dpll |= PLLB_REF_INPUT_SPREADSPECTRUMIN;
else
dpll |= PLL_REF_INPUT_DREFCLK;
pipeconf = I915_READ(PIPECONF(pipe));
dspcntr = DISPPLANE_GAMMA_ENABLE;
if (pipe == 0)
dspcntr &= ~DISPPLANE_SEL_PIPE_MASK;
else
dspcntr |= DISPPLANE_SEL_PIPE_B;
if (pipe == 0 && INTEL_INFO(dev)->gen < 4) {
if (mode->clock >
dev_priv->display.get_display_clock_speed(dev) * 9 / 10)
pipeconf |= PIPECONF_DOUBLE_WIDE;
else
pipeconf &= ~PIPECONF_DOUBLE_WIDE;
}
pipeconf &= ~(PIPECONF_BPP_MASK | PIPECONF_DITHER_EN);
if (is_dp) {
if (mode->private_flags & INTEL_MODE_DP_FORCE_6BPC) {
pipeconf |= PIPECONF_BPP_6 |
PIPECONF_DITHER_EN |
PIPECONF_DITHER_TYPE_SP;
}
}
dpll |= DPLL_VCO_ENABLE;
DRM_DEBUG_KMS("Mode for pipe %c:\n", pipe == 0 ? 'A' : 'B');
drm_mode_debug_printmodeline(mode);
I915_WRITE(FP0(pipe), fp);
I915_WRITE(DPLL(pipe), dpll & ~DPLL_VCO_ENABLE);
POSTING_READ(DPLL(pipe));
udelay(150);
if (is_lvds) {
temp = I915_READ(LVDS);
temp |= LVDS_PORT_EN | LVDS_A0A2_CLKA_POWER_UP;
if (pipe == 1) {
temp |= LVDS_PIPEB_SELECT;
} else {
temp &= ~LVDS_PIPEB_SELECT;
}
temp |= dev_priv->lvds_border_bits;
if (clock.p2 == 7)
temp |= LVDS_B0B3_POWER_UP | LVDS_CLKB_POWER_UP;
else
temp &= ~(LVDS_B0B3_POWER_UP | LVDS_CLKB_POWER_UP);
if (INTEL_INFO(dev)->gen >= 4) {
if (dev_priv->lvds_dither)
temp |= LVDS_ENABLE_DITHER;
else
temp &= ~LVDS_ENABLE_DITHER;
}
if (adjusted_mode->flags & DRM_MODE_FLAG_NHSYNC)
lvds_sync |= LVDS_HSYNC_POLARITY;
if (adjusted_mode->flags & DRM_MODE_FLAG_NVSYNC)
lvds_sync |= LVDS_VSYNC_POLARITY;
if ((temp & (LVDS_HSYNC_POLARITY | LVDS_VSYNC_POLARITY))
!= lvds_sync) {
char flags[2] = "-+";
DRM_INFO("Changing LVDS panel from "
"(%chsync, %cvsync) to (%chsync, %cvsync)\n",
flags[!(temp & LVDS_HSYNC_POLARITY)],
flags[!(temp & LVDS_VSYNC_POLARITY)],
flags[!(lvds_sync & LVDS_HSYNC_POLARITY)],
flags[!(lvds_sync & LVDS_VSYNC_POLARITY)]);
temp &= ~(LVDS_HSYNC_POLARITY | LVDS_VSYNC_POLARITY);
temp |= lvds_sync;
}
I915_WRITE(LVDS, temp);
}
if (is_dp) {
intel_dp_set_m_n(crtc, mode, adjusted_mode);
}
I915_WRITE(DPLL(pipe), dpll);
POSTING_READ(DPLL(pipe));
udelay(150);
if (INTEL_INFO(dev)->gen >= 4) {
temp = 0;
if (is_sdvo) {
temp = intel_mode_get_pixel_multiplier(adjusted_mode);
if (temp > 1)
temp = (temp - 1) << DPLL_MD_UDI_MULTIPLIER_SHIFT;
else
temp = 0;
}
I915_WRITE(DPLL_MD(pipe), temp);
} else {
I915_WRITE(DPLL(pipe), dpll);
}
intel_crtc->lowfreq_avail = false;
if (is_lvds && has_reduced_clock && i915_powersave) {
I915_WRITE(FP1(pipe), fp2);
intel_crtc->lowfreq_avail = true;
if (HAS_PIPE_CXSR(dev)) {
DRM_DEBUG_KMS("enabling CxSR downclocking\n");
pipeconf |= PIPECONF_CXSR_DOWNCLOCK;
}
} else {
I915_WRITE(FP1(pipe), fp);
if (HAS_PIPE_CXSR(dev)) {
DRM_DEBUG_KMS("disabling CxSR downclocking\n");
pipeconf &= ~PIPECONF_CXSR_DOWNCLOCK;
}
}
pipeconf &= ~PIPECONF_INTERLACE_MASK;
if (adjusted_mode->flags & DRM_MODE_FLAG_INTERLACE) {
pipeconf |= PIPECONF_INTERLACE_W_FIELD_INDICATION;
adjusted_mode->crtc_vdisplay -= 1;
adjusted_mode->crtc_vtotal -= 1;
adjusted_mode->crtc_vblank_start -= 1;
adjusted_mode->crtc_vblank_end -= 1;
adjusted_mode->crtc_vsync_end -= 1;
adjusted_mode->crtc_vsync_start -= 1;
} else
pipeconf |= PIPECONF_PROGRESSIVE;
I915_WRITE(HTOTAL(pipe),
(adjusted_mode->crtc_hdisplay - 1) |
((adjusted_mode->crtc_htotal - 1) << 16));
I915_WRITE(HBLANK(pipe),
(adjusted_mode->crtc_hblank_start - 1) |
((adjusted_mode->crtc_hblank_end - 1) << 16));
I915_WRITE(HSYNC(pipe),
(adjusted_mode->crtc_hsync_start - 1) |
((adjusted_mode->crtc_hsync_end - 1) << 16));
I915_WRITE(VTOTAL(pipe),
(adjusted_mode->crtc_vdisplay - 1) |
((adjusted_mode->crtc_vtotal - 1) << 16));
I915_WRITE(VBLANK(pipe),
(adjusted_mode->crtc_vblank_start - 1) |
((adjusted_mode->crtc_vblank_end - 1) << 16));
I915_WRITE(VSYNC(pipe),
(adjusted_mode->crtc_vsync_start - 1) |
((adjusted_mode->crtc_vsync_end - 1) << 16));
I915_WRITE(DSPSIZE(plane),
((mode->vdisplay - 1) << 16) |
(mode->hdisplay - 1));
I915_WRITE(DSPPOS(plane), 0);
I915_WRITE(PIPESRC(pipe),
((mode->hdisplay - 1) << 16) | (mode->vdisplay - 1));
I915_WRITE(PIPECONF(pipe), pipeconf);
POSTING_READ(PIPECONF(pipe));
intel_enable_pipe(dev_priv, pipe, false);
intel_wait_for_vblank(dev, pipe);
I915_WRITE(DSPCNTR(plane), dspcntr);
POSTING_READ(DSPCNTR(plane));
intel_enable_plane(dev_priv, plane, pipe);
ret = intel_pipe_set_base(crtc, x, y, old_fb);
intel_update_watermarks(dev);
return ret;
}
void ironlake_init_pch_refclk(struct drm_device *dev)
{
struct drm_i915_private *dev_priv = dev->dev_private;
struct drm_mode_config *mode_config = &dev->mode_config;
struct intel_encoder *encoder;
u32 temp;
bool has_lvds = false;
bool has_cpu_edp = false;
bool has_pch_edp = false;
bool has_panel = false;
bool has_ck505 = false;
bool can_ssc = false;
list_for_each_entry(encoder, &mode_config->encoder_list,
base.head) {
switch (encoder->type) {
case INTEL_OUTPUT_LVDS:
has_panel = true;
has_lvds = true;
break;
case INTEL_OUTPUT_EDP:
has_panel = true;
if (intel_encoder_is_pch_edp(&encoder->base))
has_pch_edp = true;
else
has_cpu_edp = true;
break;
}
}
if (HAS_PCH_IBX(dev)) {
has_ck505 = dev_priv->display_clock_mode;
can_ssc = has_ck505;
} else {
has_ck505 = false;
can_ssc = true;
}
DRM_DEBUG_KMS("has_panel %d has_lvds %d has_pch_edp %d has_cpu_edp %d has_ck505 %d\n",
has_panel, has_lvds, has_pch_edp, has_cpu_edp,
has_ck505);
temp = I915_READ(PCH_DREF_CONTROL);
temp &= ~DREF_NONSPREAD_SOURCE_MASK;
if (has_ck505)
temp |= DREF_NONSPREAD_CK505_ENABLE;
else
temp |= DREF_NONSPREAD_SOURCE_ENABLE;
if (has_panel) {
temp &= ~DREF_SSC_SOURCE_MASK;
temp |= DREF_SSC_SOURCE_ENABLE;
if (intel_panel_use_ssc(dev_priv) && can_ssc) {
DRM_DEBUG_KMS("Using SSC on panel\n");
temp |= DREF_SSC1_ENABLE;
}
I915_WRITE(PCH_DREF_CONTROL, temp);
POSTING_READ(PCH_DREF_CONTROL);
udelay(200);
temp &= ~DREF_CPU_SOURCE_OUTPUT_MASK;
if (has_cpu_edp) {
if (intel_panel_use_ssc(dev_priv) && can_ssc) {
DRM_DEBUG_KMS("Using SSC on eDP\n");
temp |= DREF_CPU_SOURCE_OUTPUT_DOWNSPREAD;
}
else
temp |= DREF_CPU_SOURCE_OUTPUT_NONSPREAD;
} else
temp |= DREF_CPU_SOURCE_OUTPUT_DISABLE;
I915_WRITE(PCH_DREF_CONTROL, temp);
POSTING_READ(PCH_DREF_CONTROL);
udelay(200);
} else {
DRM_DEBUG_KMS("Disabling SSC entirely\n");
temp &= ~DREF_CPU_SOURCE_OUTPUT_MASK;
temp |= DREF_CPU_SOURCE_OUTPUT_DISABLE;
I915_WRITE(PCH_DREF_CONTROL, temp);
POSTING_READ(PCH_DREF_CONTROL);
udelay(200);
temp &= ~DREF_SSC_SOURCE_MASK;
temp |= DREF_SSC_SOURCE_DISABLE;
temp &= ~ DREF_SSC1_ENABLE;
I915_WRITE(PCH_DREF_CONTROL, temp);
POSTING_READ(PCH_DREF_CONTROL);
udelay(200);
}
}
static int ironlake_get_refclk(struct drm_crtc *crtc)
{
struct drm_device *dev = crtc->dev;
struct drm_i915_private *dev_priv = dev->dev_private;
struct intel_encoder *encoder;
struct drm_mode_config *mode_config = &dev->mode_config;
struct intel_encoder *edp_encoder = NULL;
int num_connectors = 0;
bool is_lvds = false;
list_for_each_entry(encoder, &mode_config->encoder_list, base.head) {
if (encoder->base.crtc != crtc)
continue;
switch (encoder->type) {
case INTEL_OUTPUT_LVDS:
is_lvds = true;
break;
case INTEL_OUTPUT_EDP:
edp_encoder = encoder;
break;
}
num_connectors++;
}
if (is_lvds && intel_panel_use_ssc(dev_priv) && num_connectors < 2) {
DRM_DEBUG_KMS("using SSC reference clock of %d MHz\n",
dev_priv->lvds_ssc_freq);
return dev_priv->lvds_ssc_freq * 1000;
}
return 120000;
}
static int ironlake_crtc_mode_set(struct drm_crtc *crtc,
struct drm_display_mode *mode,
struct drm_display_mode *adjusted_mode,
int x, int y,
struct drm_framebuffer *old_fb)
{
struct drm_device *dev = crtc->dev;
struct drm_i915_private *dev_priv = dev->dev_private;
struct intel_crtc *intel_crtc = to_intel_crtc(crtc);
int pipe = intel_crtc->pipe;
int plane = intel_crtc->plane;
int refclk, num_connectors = 0;
intel_clock_t clock, reduced_clock;
u32 dpll, fp = 0, fp2 = 0, dspcntr, pipeconf;
bool ok, has_reduced_clock = false, is_sdvo = false;
bool is_crt = false, is_lvds = false, is_tv = false, is_dp = false;
struct intel_encoder *has_edp_encoder = NULL;
struct drm_mode_config *mode_config = &dev->mode_config;
struct intel_encoder *encoder;
const intel_limit_t *limit;
int ret;
struct fdi_m_n m_n = {0};
u32 temp;
u32 lvds_sync = 0;
int target_clock, pixel_multiplier, lane, link_bw, factor;
unsigned int pipe_bpp;
bool dither;
list_for_each_entry(encoder, &mode_config->encoder_list, base.head) {
if (encoder->base.crtc != crtc)
continue;
switch (encoder->type) {
case INTEL_OUTPUT_LVDS:
is_lvds = true;
break;
case INTEL_OUTPUT_SDVO:
case INTEL_OUTPUT_HDMI:
is_sdvo = true;
if (encoder->needs_tv_clock)
is_tv = true;
break;
case INTEL_OUTPUT_TVOUT:
is_tv = true;
break;
case INTEL_OUTPUT_ANALOG:
is_crt = true;
break;
case INTEL_OUTPUT_DISPLAYPORT:
is_dp = true;
break;
case INTEL_OUTPUT_EDP:
has_edp_encoder = encoder;
break;
}
num_connectors++;
}
refclk = ironlake_get_refclk(crtc);
limit = intel_limit(crtc, refclk);
ok = limit->find_pll(limit, crtc, adjusted_mode->clock, refclk, &clock);
if (!ok) {
DRM_ERROR("Couldn't find PLL settings for mode!\n");
return -EINVAL;
}
intel_crtc_update_cursor(crtc, true);
if (is_lvds && dev_priv->lvds_downclock_avail) {
has_reduced_clock = limit->find_pll(limit, crtc,
dev_priv->lvds_downclock,
refclk,
&reduced_clock);
if (has_reduced_clock && (clock.p != reduced_clock.p)) {
DRM_DEBUG_KMS("Different P is found for "
"LVDS clock/downclock\n");
has_reduced_clock = 0;
}
}
if (is_sdvo && is_tv) {
if (adjusted_mode->clock >= 100000
&& adjusted_mode->clock < 140500) {
clock.p1 = 2;
clock.p2 = 10;
clock.n = 3;
clock.m1 = 16;
clock.m2 = 8;
} else if (adjusted_mode->clock >= 140500
&& adjusted_mode->clock <= 200000) {
clock.p1 = 1;
clock.p2 = 10;
clock.n = 6;
clock.m1 = 12;
clock.m2 = 8;
}
}
pixel_multiplier = intel_mode_get_pixel_multiplier(adjusted_mode);
lane = 0;
if (has_edp_encoder &&
!intel_encoder_is_pch_edp(&has_edp_encoder->base)) {
target_clock = mode->clock;
intel_edp_link_config(has_edp_encoder,
&lane, &link_bw);
} else {
if (is_dp || intel_encoder_is_pch_edp(&has_edp_encoder->base))
target_clock = mode->clock;
else
target_clock = adjusted_mode->clock;
link_bw = intel_fdi_link_freq(dev) * MHz(100)/KHz(1)/10;
}
temp = I915_READ(PIPECONF(pipe));
temp &= ~PIPE_BPC_MASK;
dither = intel_choose_pipe_bpp_dither(crtc, &pipe_bpp, mode);
switch (pipe_bpp) {
case 18:
temp |= PIPE_6BPC;
break;
case 24:
temp |= PIPE_8BPC;
break;
case 30:
temp |= PIPE_10BPC;
break;
case 36:
temp |= PIPE_12BPC;
break;
default:
WARN(1, "intel_choose_pipe_bpp returned invalid value %d\n",
pipe_bpp);
temp |= PIPE_8BPC;
pipe_bpp = 24;
break;
}
intel_crtc->bpp = pipe_bpp;
I915_WRITE(PIPECONF(pipe), temp);
if (!lane) {
u32 bps = target_clock * intel_crtc->bpp * 21 / 20;
lane = bps / (link_bw * 8) + 1;
}
intel_crtc->fdi_lanes = lane;
if (pixel_multiplier > 1)
link_bw *= pixel_multiplier;
ironlake_compute_m_n(intel_crtc->bpp, lane, target_clock, link_bw,
&m_n);
fp = clock.n << 16 | clock.m1 << 8 | clock.m2;
if (has_reduced_clock)
fp2 = reduced_clock.n << 16 | reduced_clock.m1 << 8 |
reduced_clock.m2;
factor = 21;
if (is_lvds) {
if ((intel_panel_use_ssc(dev_priv) &&
dev_priv->lvds_ssc_freq == 100) ||
(I915_READ(PCH_LVDS) & LVDS_CLKB_POWER_MASK) == LVDS_CLKB_POWER_UP)
factor = 25;
} else if (is_sdvo && is_tv)
factor = 20;
if (clock.m < factor * clock.n)
fp |= FP_CB_TUNE;
dpll = 0;
if (is_lvds)
dpll |= DPLLB_MODE_LVDS;
else
dpll |= DPLLB_MODE_DAC_SERIAL;
if (is_sdvo) {
int pixel_multiplier = intel_mode_get_pixel_multiplier(adjusted_mode);
if (pixel_multiplier > 1) {
dpll |= (pixel_multiplier - 1) << PLL_REF_SDVO_HDMI_MULTIPLIER_SHIFT;
}
dpll |= DPLL_DVO_HIGH_SPEED;
}
if (is_dp || intel_encoder_is_pch_edp(&has_edp_encoder->base))
dpll |= DPLL_DVO_HIGH_SPEED;
dpll |= (1 << (clock.p1 - 1)) << DPLL_FPA01_P1_POST_DIV_SHIFT;
dpll |= (1 << (clock.p1 - 1)) << DPLL_FPA1_P1_POST_DIV_SHIFT;
switch (clock.p2) {
case 5:
dpll |= DPLL_DAC_SERIAL_P2_CLOCK_DIV_5;
break;
case 7:
dpll |= DPLLB_LVDS_P2_CLOCK_DIV_7;
break;
case 10:
dpll |= DPLL_DAC_SERIAL_P2_CLOCK_DIV_10;
break;
case 14:
dpll |= DPLLB_LVDS_P2_CLOCK_DIV_14;
break;
}
if (is_sdvo && is_tv)
dpll |= PLL_REF_INPUT_TVCLKINBC;
else if (is_tv)
dpll |= 3;
else if (is_lvds && intel_panel_use_ssc(dev_priv) && num_connectors < 2)
dpll |= PLLB_REF_INPUT_SPREADSPECTRUMIN;
else
dpll |= PLL_REF_INPUT_DREFCLK;
pipeconf = I915_READ(PIPECONF(pipe));
dspcntr = DISPPLANE_GAMMA_ENABLE;
DRM_DEBUG_KMS("Mode for pipe %d:\n", pipe);
drm_mode_debug_printmodeline(mode);
if (!intel_crtc->no_pll) {
if (!has_edp_encoder ||
intel_encoder_is_pch_edp(&has_edp_encoder->base)) {
I915_WRITE(PCH_FP0(pipe), fp);
I915_WRITE(PCH_DPLL(pipe), dpll & ~DPLL_VCO_ENABLE);
POSTING_READ(PCH_DPLL(pipe));
udelay(150);
}
} else {
if (dpll == (I915_READ(PCH_DPLL(0)) & 0x7fffffff) &&
fp == I915_READ(PCH_FP0(0))) {
intel_crtc->use_pll_a = true;
DRM_DEBUG_KMS("using pipe a dpll\n");
} else if (dpll == (I915_READ(PCH_DPLL(1)) & 0x7fffffff) &&
fp == I915_READ(PCH_FP0(1))) {
intel_crtc->use_pll_a = false;
DRM_DEBUG_KMS("using pipe b dpll\n");
} else {
DRM_DEBUG_KMS("no matching PLL configuration for pipe 2\n");
return -EINVAL;
}
}
if (is_lvds) {
temp = I915_READ(PCH_LVDS);
temp |= LVDS_PORT_EN | LVDS_A0A2_CLKA_POWER_UP;
if (HAS_PCH_CPT(dev)) {
temp &= ~PORT_TRANS_SEL_MASK;
temp |= PORT_TRANS_SEL_CPT(pipe);
} else {
if (pipe == 1)
temp |= LVDS_PIPEB_SELECT;
else
temp &= ~LVDS_PIPEB_SELECT;
}
temp |= dev_priv->lvds_border_bits;
if (clock.p2 == 7)
temp |= LVDS_B0B3_POWER_UP | LVDS_CLKB_POWER_UP;
else
temp &= ~(LVDS_B0B3_POWER_UP | LVDS_CLKB_POWER_UP);
if (adjusted_mode->flags & DRM_MODE_FLAG_NHSYNC)
lvds_sync |= LVDS_HSYNC_POLARITY;
if (adjusted_mode->flags & DRM_MODE_FLAG_NVSYNC)
lvds_sync |= LVDS_VSYNC_POLARITY;
if ((temp & (LVDS_HSYNC_POLARITY | LVDS_VSYNC_POLARITY))
!= lvds_sync) {
char flags[2] = "-+";
DRM_INFO("Changing LVDS panel from "
"(%chsync, %cvsync) to (%chsync, %cvsync)\n",
flags[!(temp & LVDS_HSYNC_POLARITY)],
flags[!(temp & LVDS_VSYNC_POLARITY)],
flags[!(lvds_sync & LVDS_HSYNC_POLARITY)],
flags[!(lvds_sync & LVDS_VSYNC_POLARITY)]);
temp &= ~(LVDS_HSYNC_POLARITY | LVDS_VSYNC_POLARITY);
temp |= lvds_sync;
}
I915_WRITE(PCH_LVDS, temp);
}
pipeconf &= ~PIPECONF_DITHER_EN;
pipeconf &= ~PIPECONF_DITHER_TYPE_MASK;
if ((is_lvds && dev_priv->lvds_dither) || dither) {
pipeconf |= PIPECONF_DITHER_EN;
pipeconf |= PIPECONF_DITHER_TYPE_SP;
}
if (is_dp || intel_encoder_is_pch_edp(&has_edp_encoder->base)) {
intel_dp_set_m_n(crtc, mode, adjusted_mode);
} else {
I915_WRITE(TRANSDATA_M1(pipe), 0);
I915_WRITE(TRANSDATA_N1(pipe), 0);
I915_WRITE(TRANSDPLINK_M1(pipe), 0);
I915_WRITE(TRANSDPLINK_N1(pipe), 0);
}
if (!intel_crtc->no_pll &&
(!has_edp_encoder ||
intel_encoder_is_pch_edp(&has_edp_encoder->base))) {
I915_WRITE(PCH_DPLL(pipe), dpll);
POSTING_READ(PCH_DPLL(pipe));
udelay(150);
I915_WRITE(PCH_DPLL(pipe), dpll);
}
intel_crtc->lowfreq_avail = false;
if (!intel_crtc->no_pll) {
if (is_lvds && has_reduced_clock && i915_powersave) {
I915_WRITE(PCH_FP1(pipe), fp2);
intel_crtc->lowfreq_avail = true;
if (HAS_PIPE_CXSR(dev)) {
DRM_DEBUG_KMS("enabling CxSR downclocking\n");
pipeconf |= PIPECONF_CXSR_DOWNCLOCK;
}
} else {
I915_WRITE(PCH_FP1(pipe), fp);
if (HAS_PIPE_CXSR(dev)) {
DRM_DEBUG_KMS("disabling CxSR downclocking\n");
pipeconf &= ~PIPECONF_CXSR_DOWNCLOCK;
}
}
}
pipeconf &= ~PIPECONF_INTERLACE_MASK;
if (adjusted_mode->flags & DRM_MODE_FLAG_INTERLACE) {
pipeconf |= PIPECONF_INTERLACE_W_FIELD_INDICATION;
adjusted_mode->crtc_vdisplay -= 1;
adjusted_mode->crtc_vtotal -= 1;
adjusted_mode->crtc_vblank_start -= 1;
adjusted_mode->crtc_vblank_end -= 1;
adjusted_mode->crtc_vsync_end -= 1;
adjusted_mode->crtc_vsync_start -= 1;
} else
pipeconf |= PIPECONF_PROGRESSIVE;
I915_WRITE(HTOTAL(pipe),
(adjusted_mode->crtc_hdisplay - 1) |
((adjusted_mode->crtc_htotal - 1) << 16));
I915_WRITE(HBLANK(pipe),
(adjusted_mode->crtc_hblank_start - 1) |
((adjusted_mode->crtc_hblank_end - 1) << 16));
I915_WRITE(HSYNC(pipe),
(adjusted_mode->crtc_hsync_start - 1) |
((adjusted_mode->crtc_hsync_end - 1) << 16));
I915_WRITE(VTOTAL(pipe),
(adjusted_mode->crtc_vdisplay - 1) |
((adjusted_mode->crtc_vtotal - 1) << 16));
I915_WRITE(VBLANK(pipe),
(adjusted_mode->crtc_vblank_start - 1) |
((adjusted_mode->crtc_vblank_end - 1) << 16));
I915_WRITE(VSYNC(pipe),
(adjusted_mode->crtc_vsync_start - 1) |
((adjusted_mode->crtc_vsync_end - 1) << 16));
I915_WRITE(PIPESRC(pipe),
((mode->hdisplay - 1) << 16) | (mode->vdisplay - 1));
I915_WRITE(PIPE_DATA_M1(pipe), TU_SIZE(m_n.tu) | m_n.gmch_m);
I915_WRITE(PIPE_DATA_N1(pipe), m_n.gmch_n);
I915_WRITE(PIPE_LINK_M1(pipe), m_n.link_m);
I915_WRITE(PIPE_LINK_N1(pipe), m_n.link_n);
if (has_edp_encoder &&
!intel_encoder_is_pch_edp(&has_edp_encoder->base)) {
ironlake_set_pll_edp(crtc, adjusted_mode->clock);
}
I915_WRITE(PIPECONF(pipe), pipeconf);
POSTING_READ(PIPECONF(pipe));
intel_wait_for_vblank(dev, pipe);
if (IS_GEN5(dev)) {
temp = I915_READ(DISP_ARB_CTL);
I915_WRITE(DISP_ARB_CTL, temp | DISP_TILE_SURFACE_SWIZZLING);
}
I915_WRITE(DSPCNTR(plane), dspcntr);
POSTING_READ(DSPCNTR(plane));
ret = intel_pipe_set_base(crtc, x, y, old_fb);
intel_update_watermarks(dev);
return ret;
}
static int intel_crtc_mode_set(struct drm_crtc *crtc,
struct drm_display_mode *mode,
struct drm_display_mode *adjusted_mode,
int x, int y,
struct drm_framebuffer *old_fb)
{
struct drm_device *dev = crtc->dev;
struct drm_i915_private *dev_priv = dev->dev_private;
struct intel_crtc *intel_crtc = to_intel_crtc(crtc);
int pipe = intel_crtc->pipe;
int ret;
drm_vblank_pre_modeset(dev, pipe);
ret = dev_priv->display.crtc_mode_set(crtc, mode, adjusted_mode,
x, y, old_fb);
drm_vblank_post_modeset(dev, pipe);
if (ret)
intel_crtc->dpms_mode = DRM_MODE_DPMS_OFF;
else
intel_crtc->dpms_mode = DRM_MODE_DPMS_ON;
return ret;
}
static bool intel_eld_uptodate(struct drm_connector *connector,
int reg_eldv, uint32_t bits_eldv,
int reg_elda, uint32_t bits_elda,
int reg_edid)
{
struct drm_i915_private *dev_priv = connector->dev->dev_private;
uint8_t *eld = connector->eld;
uint32_t i;
i = I915_READ(reg_eldv);
i &= bits_eldv;
if (!eld[0])
return !i;
if (!i)
return false;
i = I915_READ(reg_elda);
i &= ~bits_elda;
I915_WRITE(reg_elda, i);
for (i = 0; i < eld[2]; i++)
if (I915_READ(reg_edid) != *((uint32_t *)eld + i))
return false;
return true;
}
static void g4x_write_eld(struct drm_connector *connector,
struct drm_crtc *crtc)
{
struct drm_i915_private *dev_priv = connector->dev->dev_private;
uint8_t *eld = connector->eld;
uint32_t eldv;
uint32_t len;
uint32_t i;
i = I915_READ(G4X_AUD_VID_DID);
if (i == INTEL_AUDIO_DEVBLC || i == INTEL_AUDIO_DEVCL)
eldv = G4X_ELDV_DEVCL_DEVBLC;
else
eldv = G4X_ELDV_DEVCTG;
if (intel_eld_uptodate(connector,
G4X_AUD_CNTL_ST, eldv,
G4X_AUD_CNTL_ST, G4X_ELD_ADDR,
G4X_HDMIW_HDMIEDID))
return;
i = I915_READ(G4X_AUD_CNTL_ST);
i &= ~(eldv | G4X_ELD_ADDR);
len = (i >> 9) & 0x1f;
I915_WRITE(G4X_AUD_CNTL_ST, i);
if (!eld[0])
return;
len = min_t(uint8_t, eld[2], len);
DRM_DEBUG_DRIVER("ELD size %d\n", len);
for (i = 0; i < len; i++)
I915_WRITE(G4X_HDMIW_HDMIEDID, *((uint32_t *)eld + i));
i = I915_READ(G4X_AUD_CNTL_ST);
i |= eldv;
I915_WRITE(G4X_AUD_CNTL_ST, i);
}
static void ironlake_write_eld(struct drm_connector *connector,
struct drm_crtc *crtc)
{
struct drm_i915_private *dev_priv = connector->dev->dev_private;
uint8_t *eld = connector->eld;
uint32_t eldv;
uint32_t i;
int len;
int hdmiw_hdmiedid;
int aud_cntl_st;
int aud_cntrl_st2;
if (HAS_PCH_IBX(connector->dev)) {
hdmiw_hdmiedid = IBX_HDMIW_HDMIEDID_A;
aud_cntl_st = IBX_AUD_CNTL_ST_A;
aud_cntrl_st2 = IBX_AUD_CNTL_ST2;
} else {
hdmiw_hdmiedid = CPT_HDMIW_HDMIEDID_A;
aud_cntl_st = CPT_AUD_CNTL_ST_A;
aud_cntrl_st2 = CPT_AUD_CNTRL_ST2;
}
i = to_intel_crtc(crtc)->pipe;
hdmiw_hdmiedid += i * 0x100;
aud_cntl_st += i * 0x100;
DRM_DEBUG_DRIVER("ELD on pipe %c\n", pipe_name(i));
i = I915_READ(aud_cntl_st);
i = (i >> 29) & 0x3;
if (!i) {
DRM_DEBUG_DRIVER("Audio directed to unknown port\n");
eldv = IBX_ELD_VALIDB;
eldv |= IBX_ELD_VALIDB << 4;
eldv |= IBX_ELD_VALIDB << 8;
} else {
DRM_DEBUG_DRIVER("ELD on port %c\n", 'A' + i);
eldv = IBX_ELD_VALIDB << ((i - 1) * 4);
}
if (intel_pipe_has_type(crtc, INTEL_OUTPUT_DISPLAYPORT)) {
DRM_DEBUG_DRIVER("ELD: DisplayPort detected\n");
eld[5] |= (1 << 2);
}
if (intel_eld_uptodate(connector,
aud_cntrl_st2, eldv,
aud_cntl_st, IBX_ELD_ADDRESS,
hdmiw_hdmiedid))
return;
i = I915_READ(aud_cntrl_st2);
i &= ~eldv;
I915_WRITE(aud_cntrl_st2, i);
if (!eld[0])
return;
i = I915_READ(aud_cntl_st);
i &= ~IBX_ELD_ADDRESS;
I915_WRITE(aud_cntl_st, i);
len = min_t(uint8_t, eld[2], 21);
DRM_DEBUG_DRIVER("ELD size %d\n", len);
for (i = 0; i < len; i++)
I915_WRITE(hdmiw_hdmiedid, *((uint32_t *)eld + i));
i = I915_READ(aud_cntrl_st2);
i |= eldv;
I915_WRITE(aud_cntrl_st2, i);
}
void intel_write_eld(struct drm_encoder *encoder,
struct drm_display_mode *mode)
{
struct drm_crtc *crtc = encoder->crtc;
struct drm_connector *connector;
struct drm_device *dev = encoder->dev;
struct drm_i915_private *dev_priv = dev->dev_private;
connector = drm_select_eld(encoder, mode);
if (!connector)
return;
DRM_DEBUG_DRIVER("ELD on [CONNECTOR:%d:%s], [ENCODER:%d:%s]\n",
connector->base.id,
drm_get_connector_name(connector),
connector->encoder->base.id,
drm_get_encoder_name(connector->encoder));
connector->eld[6] = drm_av_sync_delay(connector, mode) / 2;
if (dev_priv->display.write_eld)
dev_priv->display.write_eld(connector, crtc);
}
void intel_crtc_load_lut(struct drm_crtc *crtc)
{
struct drm_device *dev = crtc->dev;
struct drm_i915_private *dev_priv = dev->dev_private;
struct intel_crtc *intel_crtc = to_intel_crtc(crtc);
int palreg = PALETTE(intel_crtc->pipe);
int i;
if (!crtc->enabled || !intel_crtc->active)
return;
if (HAS_PCH_SPLIT(dev))
palreg = LGC_PALETTE(intel_crtc->pipe);
for (i = 0; i < 256; i++) {
I915_WRITE(palreg + 4 * i,
(intel_crtc->lut_r[i] << 16) |
(intel_crtc->lut_g[i] << 8) |
intel_crtc->lut_b[i]);
}
}
static void i845_update_cursor(struct drm_crtc *crtc, u32 base)
{
struct drm_device *dev = crtc->dev;
struct drm_i915_private *dev_priv = dev->dev_private;
struct intel_crtc *intel_crtc = to_intel_crtc(crtc);
bool visible = base != 0;
u32 cntl;
if (intel_crtc->cursor_visible == visible)
return;
cntl = I915_READ(_CURACNTR);
if (visible) {
I915_WRITE(_CURABASE, base);
cntl &= ~(CURSOR_FORMAT_MASK);
cntl |= CURSOR_ENABLE |
CURSOR_GAMMA_ENABLE |
CURSOR_FORMAT_ARGB;
} else
cntl &= ~(CURSOR_ENABLE | CURSOR_GAMMA_ENABLE);
I915_WRITE(_CURACNTR, cntl);
intel_crtc->cursor_visible = visible;
}
static void i9xx_update_cursor(struct drm_crtc *crtc, u32 base)
{
struct drm_device *dev = crtc->dev;
struct drm_i915_private *dev_priv = dev->dev_private;
struct intel_crtc *intel_crtc = to_intel_crtc(crtc);
int pipe = intel_crtc->pipe;
bool visible = base != 0;
if (intel_crtc->cursor_visible != visible) {
uint32_t cntl = I915_READ(CURCNTR(pipe));
if (base) {
cntl &= ~(CURSOR_MODE | MCURSOR_PIPE_SELECT);
cntl |= CURSOR_MODE_64_ARGB_AX | MCURSOR_GAMMA_ENABLE;
cntl |= pipe << 28;
} else {
cntl &= ~(CURSOR_MODE | MCURSOR_GAMMA_ENABLE);
cntl |= CURSOR_MODE_DISABLE;
}
I915_WRITE(CURCNTR(pipe), cntl);
intel_crtc->cursor_visible = visible;
}
I915_WRITE(CURBASE(pipe), base);
}
static void ivb_update_cursor(struct drm_crtc *crtc, u32 base)
{
struct drm_device *dev = crtc->dev;
struct drm_i915_private *dev_priv = dev->dev_private;
struct intel_crtc *intel_crtc = to_intel_crtc(crtc);
int pipe = intel_crtc->pipe;
bool visible = base != 0;
if (intel_crtc->cursor_visible != visible) {
uint32_t cntl = I915_READ(CURCNTR_IVB(pipe));
if (base) {
cntl &= ~CURSOR_MODE;
cntl |= CURSOR_MODE_64_ARGB_AX | MCURSOR_GAMMA_ENABLE;
} else {
cntl &= ~(CURSOR_MODE | MCURSOR_GAMMA_ENABLE);
cntl |= CURSOR_MODE_DISABLE;
}
I915_WRITE(CURCNTR_IVB(pipe), cntl);
intel_crtc->cursor_visible = visible;
}
I915_WRITE(CURBASE_IVB(pipe), base);
}
static void intel_crtc_update_cursor(struct drm_crtc *crtc,
bool on)
{
struct drm_device *dev = crtc->dev;
struct drm_i915_private *dev_priv = dev->dev_private;
struct intel_crtc *intel_crtc = to_intel_crtc(crtc);
int pipe = intel_crtc->pipe;
int x = intel_crtc->cursor_x;
int y = intel_crtc->cursor_y;
u32 base, pos;
bool visible;
pos = 0;
if (on && crtc->enabled && crtc->fb) {
base = intel_crtc->cursor_addr;
if (x > (int) crtc->fb->width)
base = 0;
if (y > (int) crtc->fb->height)
base = 0;
} else
base = 0;
if (x < 0) {
if (x + intel_crtc->cursor_width < 0)
base = 0;
pos |= CURSOR_POS_SIGN << CURSOR_X_SHIFT;
x = -x;
}
pos |= x << CURSOR_X_SHIFT;
if (y < 0) {
if (y + intel_crtc->cursor_height < 0)
base = 0;
pos |= CURSOR_POS_SIGN << CURSOR_Y_SHIFT;
y = -y;
}
pos |= y << CURSOR_Y_SHIFT;
visible = base != 0;
if (!visible && !intel_crtc->cursor_visible)
return;
if (IS_IVYBRIDGE(dev)) {
I915_WRITE(CURPOS_IVB(pipe), pos);
ivb_update_cursor(crtc, base);
} else {
I915_WRITE(CURPOS(pipe), pos);
if (IS_845G(dev) || IS_I865G(dev))
i845_update_cursor(crtc, base);
else
i9xx_update_cursor(crtc, base);
}
if (visible)
intel_mark_busy(dev, to_intel_framebuffer(crtc->fb)->obj);
}
static int intel_crtc_cursor_set(struct drm_crtc *crtc,
struct drm_file *file,
uint32_t handle,
uint32_t width, uint32_t height)
{
struct drm_device *dev = crtc->dev;
struct drm_i915_private *dev_priv = dev->dev_private;
struct intel_crtc *intel_crtc = to_intel_crtc(crtc);
struct drm_i915_gem_object *obj;
uint32_t addr;
int ret;
DRM_DEBUG_KMS("\n");
if (!handle) {
DRM_DEBUG_KMS("cursor off\n");
addr = 0;
obj = NULL;
mutex_lock(&dev->struct_mutex);
goto finish;
}
if (width != 64 || height != 64) {
DRM_ERROR("we currently only support 64x64 cursors\n");
return -EINVAL;
}
obj = to_intel_bo(drm_gem_object_lookup(dev, file, handle));
if (&obj->base == NULL)
return -ENOENT;
if (obj->base.size < width * height * 4) {
DRM_ERROR("buffer is to small\n");
ret = -ENOMEM;
goto fail;
}
mutex_lock(&dev->struct_mutex);
if (!dev_priv->info->cursor_needs_physical) {
if (obj->tiling_mode) {
DRM_ERROR("cursor cannot be tiled\n");
ret = -EINVAL;
goto fail_locked;
}
ret = i915_gem_object_pin_to_display_plane(obj, 0, NULL);
if (ret) {
DRM_ERROR("failed to move cursor bo into the GTT\n");
goto fail_locked;
}
ret = i915_gem_object_put_fence(obj);
if (ret) {
DRM_ERROR("failed to release fence for cursor");
goto fail_unpin;
}
addr = obj->gtt_offset;
} else {
int align = IS_I830(dev) ? 16 * 1024 : 256;
ret = i915_gem_attach_phys_object(dev, obj,
(intel_crtc->pipe == 0) ? I915_GEM_PHYS_CURSOR_0 : I915_GEM_PHYS_CURSOR_1,
align);
if (ret) {
DRM_ERROR("failed to attach phys object\n");
goto fail_locked;
}
addr = obj->phys_obj->handle->busaddr;
}
if (IS_GEN2(dev))
I915_WRITE(CURSIZE, (height << 12) | width);
finish:
if (intel_crtc->cursor_bo) {
if (dev_priv->info->cursor_needs_physical) {
if (intel_crtc->cursor_bo != obj)
i915_gem_detach_phys_object(dev, intel_crtc->cursor_bo);
} else
i915_gem_object_unpin(intel_crtc->cursor_bo);
drm_gem_object_unreference(&intel_crtc->cursor_bo->base);
}
mutex_unlock(&dev->struct_mutex);
intel_crtc->cursor_addr = addr;
intel_crtc->cursor_bo = obj;
intel_crtc->cursor_width = width;
intel_crtc->cursor_height = height;
intel_crtc_update_cursor(crtc, true);
return 0;
fail_unpin:
i915_gem_object_unpin(obj);
fail_locked:
mutex_unlock(&dev->struct_mutex);
fail:
drm_gem_object_unreference_unlocked(&obj->base);
return ret;
}
static int intel_crtc_cursor_move(struct drm_crtc *crtc, int x, int y)
{
struct intel_crtc *intel_crtc = to_intel_crtc(crtc);
intel_crtc->cursor_x = x;
intel_crtc->cursor_y = y;
intel_crtc_update_cursor(crtc, true);
return 0;
}
void intel_crtc_fb_gamma_set(struct drm_crtc *crtc, u16 red, u16 green,
u16 blue, int regno)
{
struct intel_crtc *intel_crtc = to_intel_crtc(crtc);
intel_crtc->lut_r[regno] = red >> 8;
intel_crtc->lut_g[regno] = green >> 8;
intel_crtc->lut_b[regno] = blue >> 8;
}
void intel_crtc_fb_gamma_get(struct drm_crtc *crtc, u16 *red, u16 *green,
u16 *blue, int regno)
{
struct intel_crtc *intel_crtc = to_intel_crtc(crtc);
*red = intel_crtc->lut_r[regno] << 8;
*green = intel_crtc->lut_g[regno] << 8;
*blue = intel_crtc->lut_b[regno] << 8;
}
static void intel_crtc_gamma_set(struct drm_crtc *crtc, u16 *red, u16 *green,
u16 *blue, uint32_t start, uint32_t size)
{
int end = (start + size > 256) ? 256 : start + size, i;
struct intel_crtc *intel_crtc = to_intel_crtc(crtc);
for (i = start; i < end; i++) {
intel_crtc->lut_r[i] = red[i] >> 8;
intel_crtc->lut_g[i] = green[i] >> 8;
intel_crtc->lut_b[i] = blue[i] >> 8;
}
intel_crtc_load_lut(crtc);
}
static struct drm_framebuffer *
intel_framebuffer_create(struct drm_device *dev,
struct drm_mode_fb_cmd2 *mode_cmd,
struct drm_i915_gem_object *obj)
{
struct intel_framebuffer *intel_fb;
int ret;
intel_fb = kzalloc(sizeof(*intel_fb), GFP_KERNEL);
if (!intel_fb) {
drm_gem_object_unreference_unlocked(&obj->base);
return ERR_PTR(-ENOMEM);
}
ret = intel_framebuffer_init(dev, intel_fb, mode_cmd, obj);
if (ret) {
drm_gem_object_unreference_unlocked(&obj->base);
kfree(intel_fb);
return ERR_PTR(ret);
}
return &intel_fb->base;
}
static u32
intel_framebuffer_pitch_for_width(int width, int bpp)
{
u32 pitch = DIV_ROUND_UP(width * bpp, 8);
return ALIGN(pitch, 64);
}
static u32
intel_framebuffer_size_for_mode(struct drm_display_mode *mode, int bpp)
{
u32 pitch = intel_framebuffer_pitch_for_width(mode->hdisplay, bpp);
return ALIGN(pitch * mode->vdisplay, PAGE_SIZE);
}
static struct drm_framebuffer *
intel_framebuffer_create_for_mode(struct drm_device *dev,
struct drm_display_mode *mode,
int depth, int bpp)
{
struct drm_i915_gem_object *obj;
struct drm_mode_fb_cmd2 mode_cmd;
obj = i915_gem_alloc_object(dev,
intel_framebuffer_size_for_mode(mode, bpp));
if (obj == NULL)
return ERR_PTR(-ENOMEM);
mode_cmd.width = mode->hdisplay;
mode_cmd.height = mode->vdisplay;
mode_cmd.pitches[0] = intel_framebuffer_pitch_for_width(mode_cmd.width,
bpp);
mode_cmd.pixel_format = drm_mode_legacy_fb_format(bpp, depth);
return intel_framebuffer_create(dev, &mode_cmd, obj);
}
static struct drm_framebuffer *
mode_fits_in_fbdev(struct drm_device *dev,
struct drm_display_mode *mode)
{
struct drm_i915_private *dev_priv = dev->dev_private;
struct drm_i915_gem_object *obj;
struct drm_framebuffer *fb;
if (dev_priv->fbdev == NULL)
return NULL;
obj = dev_priv->fbdev->ifb.obj;
if (obj == NULL)
return NULL;
fb = &dev_priv->fbdev->ifb.base;
if (fb->pitches[0] < intel_framebuffer_pitch_for_width(mode->hdisplay,
fb->bits_per_pixel))
return NULL;
if (obj->base.size < mode->vdisplay * fb->pitches[0])
return NULL;
return fb;
}
bool intel_get_load_detect_pipe(struct intel_encoder *intel_encoder,
struct drm_connector *connector,
struct drm_display_mode *mode,
struct intel_load_detect_pipe *old)
{
struct intel_crtc *intel_crtc;
struct drm_crtc *possible_crtc;
struct drm_encoder *encoder = &intel_encoder->base;
struct drm_crtc *crtc = NULL;
struct drm_device *dev = encoder->dev;
struct drm_framebuffer *old_fb;
int i = -1;
DRM_DEBUG_KMS("[CONNECTOR:%d:%s], [ENCODER:%d:%s]\n",
connector->base.id, drm_get_connector_name(connector),
encoder->base.id, drm_get_encoder_name(encoder));
if (encoder->crtc) {
crtc = encoder->crtc;
intel_crtc = to_intel_crtc(crtc);
old->dpms_mode = intel_crtc->dpms_mode;
old->load_detect_temp = false;
if (intel_crtc->dpms_mode != DRM_MODE_DPMS_ON) {
struct drm_encoder_helper_funcs *encoder_funcs;
struct drm_crtc_helper_funcs *crtc_funcs;
crtc_funcs = crtc->helper_private;
crtc_funcs->dpms(crtc, DRM_MODE_DPMS_ON);
encoder_funcs = encoder->helper_private;
encoder_funcs->dpms(encoder, DRM_MODE_DPMS_ON);
}
return true;
}
list_for_each_entry(possible_crtc, &dev->mode_config.crtc_list, head) {
i++;
if (!(encoder->possible_crtcs & (1 << i)))
continue;
if (!possible_crtc->enabled) {
crtc = possible_crtc;
break;
}
}
if (!crtc) {
DRM_DEBUG_KMS("no pipe available for load-detect\n");
return false;
}
encoder->crtc = crtc;
connector->encoder = encoder;
intel_crtc = to_intel_crtc(crtc);
old->dpms_mode = intel_crtc->dpms_mode;
old->load_detect_temp = true;
old->release_fb = NULL;
if (!mode)
mode = &load_detect_mode;
old_fb = crtc->fb;
crtc->fb = mode_fits_in_fbdev(dev, mode);
if (crtc->fb == NULL) {
DRM_DEBUG_KMS("creating tmp fb for load-detection\n");
crtc->fb = intel_framebuffer_create_for_mode(dev, mode, 24, 32);
old->release_fb = crtc->fb;
} else
DRM_DEBUG_KMS("reusing fbdev for load-detection framebuffer\n");
if (IS_ERR(crtc->fb)) {
DRM_DEBUG_KMS("failed to allocate framebuffer for load-detection\n");
crtc->fb = old_fb;
return false;
}
if (!drm_crtc_helper_set_mode(crtc, mode, 0, 0, old_fb)) {
DRM_DEBUG_KMS("failed to set mode on load-detect pipe\n");
if (old->release_fb)
old->release_fb->funcs->destroy(old->release_fb);
crtc->fb = old_fb;
return false;
}
intel_wait_for_vblank(dev, intel_crtc->pipe);
return true;
}
void intel_release_load_detect_pipe(struct intel_encoder *intel_encoder,
struct drm_connector *connector,
struct intel_load_detect_pipe *old)
{
struct drm_encoder *encoder = &intel_encoder->base;
struct drm_device *dev = encoder->dev;
struct drm_crtc *crtc = encoder->crtc;
struct drm_encoder_helper_funcs *encoder_funcs = encoder->helper_private;
struct drm_crtc_helper_funcs *crtc_funcs = crtc->helper_private;
DRM_DEBUG_KMS("[CONNECTOR:%d:%s], [ENCODER:%d:%s]\n",
connector->base.id, drm_get_connector_name(connector),
encoder->base.id, drm_get_encoder_name(encoder));
if (old->load_detect_temp) {
connector->encoder = NULL;
drm_helper_disable_unused_functions(dev);
if (old->release_fb)
old->release_fb->funcs->destroy(old->release_fb);
return;
}
if (old->dpms_mode != DRM_MODE_DPMS_ON) {
encoder_funcs->dpms(encoder, old->dpms_mode);
crtc_funcs->dpms(crtc, old->dpms_mode);
}
}
static int intel_crtc_clock_get(struct drm_device *dev, struct drm_crtc *crtc)
{
struct drm_i915_private *dev_priv = dev->dev_private;
struct intel_crtc *intel_crtc = to_intel_crtc(crtc);
int pipe = intel_crtc->pipe;
u32 dpll = I915_READ(DPLL(pipe));
u32 fp;
intel_clock_t clock;
if ((dpll & DISPLAY_RATE_SELECT_FPA1) == 0)
fp = I915_READ(FP0(pipe));
else
fp = I915_READ(FP1(pipe));
clock.m1 = (fp & FP_M1_DIV_MASK) >> FP_M1_DIV_SHIFT;
if (IS_PINEVIEW(dev)) {
clock.n = ffs((fp & FP_N_PINEVIEW_DIV_MASK) >> FP_N_DIV_SHIFT) - 1;
clock.m2 = (fp & FP_M2_PINEVIEW_DIV_MASK) >> FP_M2_DIV_SHIFT;
} else {
clock.n = (fp & FP_N_DIV_MASK) >> FP_N_DIV_SHIFT;
clock.m2 = (fp & FP_M2_DIV_MASK) >> FP_M2_DIV_SHIFT;
}
if (!IS_GEN2(dev)) {
if (IS_PINEVIEW(dev))
clock.p1 = ffs((dpll & DPLL_FPA01_P1_POST_DIV_MASK_PINEVIEW) >>
DPLL_FPA01_P1_POST_DIV_SHIFT_PINEVIEW);
else
clock.p1 = ffs((dpll & DPLL_FPA01_P1_POST_DIV_MASK) >>
DPLL_FPA01_P1_POST_DIV_SHIFT);
switch (dpll & DPLL_MODE_MASK) {
case DPLLB_MODE_DAC_SERIAL:
clock.p2 = dpll & DPLL_DAC_SERIAL_P2_CLOCK_DIV_5 ?
5 : 10;
break;
case DPLLB_MODE_LVDS:
clock.p2 = dpll & DPLLB_LVDS_P2_CLOCK_DIV_7 ?
7 : 14;
break;
default:
DRM_DEBUG_KMS("Unknown DPLL mode %08x in programmed "
"mode\n", (int)(dpll & DPLL_MODE_MASK));
return 0;
}
intel_clock(dev, 96000, &clock);
} else {
bool is_lvds = (pipe == 1) && (I915_READ(LVDS) & LVDS_PORT_EN);
if (is_lvds) {
clock.p1 = ffs((dpll & DPLL_FPA01_P1_POST_DIV_MASK_I830_LVDS) >>
DPLL_FPA01_P1_POST_DIV_SHIFT);
clock.p2 = 14;
if ((dpll & PLL_REF_INPUT_MASK) ==
PLLB_REF_INPUT_SPREADSPECTRUMIN) {
intel_clock(dev, 66000, &clock);
} else
intel_clock(dev, 48000, &clock);
} else {
if (dpll & PLL_P1_DIVIDE_BY_TWO)
clock.p1 = 2;
else {
clock.p1 = ((dpll & DPLL_FPA01_P1_POST_DIV_MASK_I830) >>
DPLL_FPA01_P1_POST_DIV_SHIFT) + 2;
}
if (dpll & PLL_P2_DIVIDE_BY_4)
clock.p2 = 4;
else
clock.p2 = 2;
intel_clock(dev, 48000, &clock);
}
}
return clock.dot;
}
struct drm_display_mode *intel_crtc_mode_get(struct drm_device *dev,
struct drm_crtc *crtc)
{
struct drm_i915_private *dev_priv = dev->dev_private;
struct intel_crtc *intel_crtc = to_intel_crtc(crtc);
int pipe = intel_crtc->pipe;
struct drm_display_mode *mode;
int htot = I915_READ(HTOTAL(pipe));
int hsync = I915_READ(HSYNC(pipe));
int vtot = I915_READ(VTOTAL(pipe));
int vsync = I915_READ(VSYNC(pipe));
mode = kzalloc(sizeof(*mode), GFP_KERNEL);
if (!mode)
return NULL;
mode->clock = intel_crtc_clock_get(dev, crtc);
mode->hdisplay = (htot & 0xffff) + 1;
mode->htotal = ((htot & 0xffff0000) >> 16) + 1;
mode->hsync_start = (hsync & 0xffff) + 1;
mode->hsync_end = ((hsync & 0xffff0000) >> 16) + 1;
mode->vdisplay = (vtot & 0xffff) + 1;
mode->vtotal = ((vtot & 0xffff0000) >> 16) + 1;
mode->vsync_start = (vsync & 0xffff) + 1;
mode->vsync_end = ((vsync & 0xffff0000) >> 16) + 1;
drm_mode_set_name(mode);
drm_mode_set_crtcinfo(mode, 0);
return mode;
}
static void intel_gpu_idle_timer(unsigned long arg)
{
struct drm_device *dev = (struct drm_device *)arg;
drm_i915_private_t *dev_priv = dev->dev_private;
if (!list_empty(&dev_priv->mm.active_list)) {
mod_timer(&dev_priv->idle_timer, jiffies +
msecs_to_jiffies(GPU_IDLE_TIMEOUT));
return;
}
dev_priv->busy = false;
queue_work(dev_priv->wq, &dev_priv->idle_work);
}
static void intel_crtc_idle_timer(unsigned long arg)
{
struct intel_crtc *intel_crtc = (struct intel_crtc *)arg;
struct drm_crtc *crtc = &intel_crtc->base;
drm_i915_private_t *dev_priv = crtc->dev->dev_private;
struct intel_framebuffer *intel_fb;
intel_fb = to_intel_framebuffer(crtc->fb);
if (intel_fb && intel_fb->obj->active) {
mod_timer(&intel_crtc->idle_timer, jiffies +
msecs_to_jiffies(CRTC_IDLE_TIMEOUT));
return;
}
intel_crtc->busy = false;
queue_work(dev_priv->wq, &dev_priv->idle_work);
}
static void intel_increase_pllclock(struct drm_crtc *crtc)
{
struct drm_device *dev = crtc->dev;
drm_i915_private_t *dev_priv = dev->dev_private;
struct intel_crtc *intel_crtc = to_intel_crtc(crtc);
int pipe = intel_crtc->pipe;
int dpll_reg = DPLL(pipe);
int dpll;
if (HAS_PCH_SPLIT(dev))
return;
if (!dev_priv->lvds_downclock_avail)
return;
dpll = I915_READ(dpll_reg);
if (!HAS_PIPE_CXSR(dev) && (dpll & DISPLAY_RATE_SELECT_FPA1)) {
DRM_DEBUG_DRIVER("upclocking LVDS\n");
I915_WRITE(PP_CONTROL,
I915_READ(PP_CONTROL) | PANEL_UNLOCK_REGS);
dpll &= ~DISPLAY_RATE_SELECT_FPA1;
I915_WRITE(dpll_reg, dpll);
intel_wait_for_vblank(dev, pipe);
dpll = I915_READ(dpll_reg);
if (dpll & DISPLAY_RATE_SELECT_FPA1)
DRM_DEBUG_DRIVER("failed to upclock LVDS!\n");
I915_WRITE(PP_CONTROL, I915_READ(PP_CONTROL) & 0x3);
}
mod_timer(&intel_crtc->idle_timer, jiffies +
msecs_to_jiffies(CRTC_IDLE_TIMEOUT));
}
static void intel_decrease_pllclock(struct drm_crtc *crtc)
{
struct drm_device *dev = crtc->dev;
drm_i915_private_t *dev_priv = dev->dev_private;
struct intel_crtc *intel_crtc = to_intel_crtc(crtc);
int pipe = intel_crtc->pipe;
int dpll_reg = DPLL(pipe);
int dpll = I915_READ(dpll_reg);
if (HAS_PCH_SPLIT(dev))
return;
if (!dev_priv->lvds_downclock_avail)
return;
if (!HAS_PIPE_CXSR(dev) && intel_crtc->lowfreq_avail) {
DRM_DEBUG_DRIVER("downclocking LVDS\n");
I915_WRITE(PP_CONTROL, I915_READ(PP_CONTROL) |
PANEL_UNLOCK_REGS);
dpll |= DISPLAY_RATE_SELECT_FPA1;
I915_WRITE(dpll_reg, dpll);
intel_wait_for_vblank(dev, pipe);
dpll = I915_READ(dpll_reg);
if (!(dpll & DISPLAY_RATE_SELECT_FPA1))
DRM_DEBUG_DRIVER("failed to downclock LVDS!\n");
I915_WRITE(PP_CONTROL, I915_READ(PP_CONTROL) & 0x3);
}
}
static void intel_idle_update(struct work_struct *work)
{
drm_i915_private_t *dev_priv = container_of(work, drm_i915_private_t,
idle_work);
struct drm_device *dev = dev_priv->dev;
struct drm_crtc *crtc;
struct intel_crtc *intel_crtc;
if (!i915_powersave)
return;
mutex_lock(&dev->struct_mutex);
i915_update_gfx_val(dev_priv);
list_for_each_entry(crtc, &dev->mode_config.crtc_list, head) {
if (!crtc->fb)
continue;
intel_crtc = to_intel_crtc(crtc);
if (!intel_crtc->busy)
intel_decrease_pllclock(crtc);
}
mutex_unlock(&dev->struct_mutex);
}
void intel_mark_busy(struct drm_device *dev, struct drm_i915_gem_object *obj)
{
drm_i915_private_t *dev_priv = dev->dev_private;
struct drm_crtc *crtc = NULL;
struct intel_framebuffer *intel_fb;
struct intel_crtc *intel_crtc;
if (!drm_core_check_feature(dev, DRIVER_MODESET))
return;
if (!dev_priv->busy)
dev_priv->busy = true;
else
mod_timer(&dev_priv->idle_timer, jiffies +
msecs_to_jiffies(GPU_IDLE_TIMEOUT));
list_for_each_entry(crtc, &dev->mode_config.crtc_list, head) {
if (!crtc->fb)
continue;
intel_crtc = to_intel_crtc(crtc);
intel_fb = to_intel_framebuffer(crtc->fb);
if (intel_fb->obj == obj) {
if (!intel_crtc->busy) {
intel_increase_pllclock(crtc);
intel_crtc->busy = true;
} else {
mod_timer(&intel_crtc->idle_timer, jiffies +
msecs_to_jiffies(CRTC_IDLE_TIMEOUT));
}
}
}
}
static void intel_crtc_destroy(struct drm_crtc *crtc)
{
struct intel_crtc *intel_crtc = to_intel_crtc(crtc);
struct drm_device *dev = crtc->dev;
struct intel_unpin_work *work;
unsigned long flags;
spin_lock_irqsave(&dev->event_lock, flags);
work = intel_crtc->unpin_work;
intel_crtc->unpin_work = NULL;
spin_unlock_irqrestore(&dev->event_lock, flags);
if (work) {
cancel_work_sync(&work->work);
kfree(work);
}
drm_crtc_cleanup(crtc);
kfree(intel_crtc);
}
static void intel_unpin_work_fn(struct work_struct *__work)
{
struct intel_unpin_work *work =
container_of(__work, struct intel_unpin_work, work);
mutex_lock(&work->dev->struct_mutex);
i915_gem_object_unpin(work->old_fb_obj);
drm_gem_object_unreference(&work->pending_flip_obj->base);
drm_gem_object_unreference(&work->old_fb_obj->base);
intel_update_fbc(work->dev);
mutex_unlock(&work->dev->struct_mutex);
kfree(work);
}
static void do_intel_finish_page_flip(struct drm_device *dev,
struct drm_crtc *crtc)
{
drm_i915_private_t *dev_priv = dev->dev_private;
struct intel_crtc *intel_crtc = to_intel_crtc(crtc);
struct intel_unpin_work *work;
struct drm_i915_gem_object *obj;
struct drm_pending_vblank_event *e;
struct timeval tnow, tvbl;
unsigned long flags;
if (intel_crtc == NULL)
return;
do_gettimeofday(&tnow);
spin_lock_irqsave(&dev->event_lock, flags);
work = intel_crtc->unpin_work;
if (work == NULL || !work->pending) {
spin_unlock_irqrestore(&dev->event_lock, flags);
return;
}
intel_crtc->unpin_work = NULL;
if (work->event) {
e = work->event;
e->event.sequence = drm_vblank_count_and_time(dev, intel_crtc->pipe, &tvbl);
if (10 * (timeval_to_ns(&tnow) - timeval_to_ns(&tvbl)) >
9 * crtc->framedur_ns) {
e->event.sequence++;
tvbl = ns_to_timeval(timeval_to_ns(&tvbl) +
crtc->framedur_ns);
}
e->event.tv_sec = tvbl.tv_sec;
e->event.tv_usec = tvbl.tv_usec;
list_add_tail(&e->base.link,
&e->base.file_priv->event_list);
wake_up_interruptible(&e->base.file_priv->event_wait);
}
drm_vblank_put(dev, intel_crtc->pipe);
spin_unlock_irqrestore(&dev->event_lock, flags);
obj = work->old_fb_obj;
atomic_clear_mask(1 << intel_crtc->plane,
&obj->pending_flip.counter);
if (atomic_read(&obj->pending_flip) == 0)
wake_up(&dev_priv->pending_flip_queue);
schedule_work(&work->work);
trace_i915_flip_complete(intel_crtc->plane, work->pending_flip_obj);
}
void intel_finish_page_flip(struct drm_device *dev, int pipe)
{
drm_i915_private_t *dev_priv = dev->dev_private;
struct drm_crtc *crtc = dev_priv->pipe_to_crtc_mapping[pipe];
do_intel_finish_page_flip(dev, crtc);
}
void intel_finish_page_flip_plane(struct drm_device *dev, int plane)
{
drm_i915_private_t *dev_priv = dev->dev_private;
struct drm_crtc *crtc = dev_priv->plane_to_crtc_mapping[plane];
do_intel_finish_page_flip(dev, crtc);
}
void intel_prepare_page_flip(struct drm_device *dev, int plane)
{
drm_i915_private_t *dev_priv = dev->dev_private;
struct intel_crtc *intel_crtc =
to_intel_crtc(dev_priv->plane_to_crtc_mapping[plane]);
unsigned long flags;
spin_lock_irqsave(&dev->event_lock, flags);
if (intel_crtc->unpin_work) {
if ((++intel_crtc->unpin_work->pending) > 1)
DRM_ERROR("Prepared flip multiple times\n");
} else {
DRM_DEBUG_DRIVER("preparing flip with no unpin work?\n");
}
spin_unlock_irqrestore(&dev->event_lock, flags);
}
static int intel_gen2_queue_flip(struct drm_device *dev,
struct drm_crtc *crtc,
struct drm_framebuffer *fb,
struct drm_i915_gem_object *obj)
{
struct drm_i915_private *dev_priv = dev->dev_private;
struct intel_crtc *intel_crtc = to_intel_crtc(crtc);
unsigned long offset;
u32 flip_mask;
int ret;
ret = intel_pin_and_fence_fb_obj(dev, obj, LP_RING(dev_priv));
if (ret)
goto out;
offset = crtc->y * fb->pitches[0] + crtc->x * fb->bits_per_pixel/8;
ret = BEGIN_LP_RING(6);
if (ret)
goto out;
if (intel_crtc->plane)
flip_mask = MI_WAIT_FOR_PLANE_B_FLIP;
else
flip_mask = MI_WAIT_FOR_PLANE_A_FLIP;
OUT_RING(MI_WAIT_FOR_EVENT | flip_mask);
OUT_RING(MI_NOOP);
OUT_RING(MI_DISPLAY_FLIP |
MI_DISPLAY_FLIP_PLANE(intel_crtc->plane));
OUT_RING(fb->pitches[0]);
OUT_RING(obj->gtt_offset + offset);
OUT_RING(MI_NOOP);
ADVANCE_LP_RING();
out:
return ret;
}
static int intel_gen3_queue_flip(struct drm_device *dev,
struct drm_crtc *crtc,
struct drm_framebuffer *fb,
struct drm_i915_gem_object *obj)
{
struct drm_i915_private *dev_priv = dev->dev_private;
struct intel_crtc *intel_crtc = to_intel_crtc(crtc);
unsigned long offset;
u32 flip_mask;
int ret;
ret = intel_pin_and_fence_fb_obj(dev, obj, LP_RING(dev_priv));
if (ret)
goto out;
offset = crtc->y * fb->pitches[0] + crtc->x * fb->bits_per_pixel/8;
ret = BEGIN_LP_RING(6);
if (ret)
goto out;
if (intel_crtc->plane)
flip_mask = MI_WAIT_FOR_PLANE_B_FLIP;
else
flip_mask = MI_WAIT_FOR_PLANE_A_FLIP;
OUT_RING(MI_WAIT_FOR_EVENT | flip_mask);
OUT_RING(MI_NOOP);
OUT_RING(MI_DISPLAY_FLIP_I915 |
MI_DISPLAY_FLIP_PLANE(intel_crtc->plane));
OUT_RING(fb->pitches[0]);
OUT_RING(obj->gtt_offset + offset);
OUT_RING(MI_NOOP);
ADVANCE_LP_RING();
out:
return ret;
}
static int intel_gen4_queue_flip(struct drm_device *dev,
struct drm_crtc *crtc,
struct drm_framebuffer *fb,
struct drm_i915_gem_object *obj)
{
struct drm_i915_private *dev_priv = dev->dev_private;
struct intel_crtc *intel_crtc = to_intel_crtc(crtc);
uint32_t pf, pipesrc;
int ret;
ret = intel_pin_and_fence_fb_obj(dev, obj, LP_RING(dev_priv));
if (ret)
goto out;
ret = BEGIN_LP_RING(4);
if (ret)
goto out;
OUT_RING(MI_DISPLAY_FLIP |
MI_DISPLAY_FLIP_PLANE(intel_crtc->plane));
OUT_RING(fb->pitches[0]);
OUT_RING(obj->gtt_offset | obj->tiling_mode);
pf = 0;
pipesrc = I915_READ(PIPESRC(intel_crtc->pipe)) & 0x0fff0fff;
OUT_RING(pf | pipesrc);
ADVANCE_LP_RING();
out:
return ret;
}
static int intel_gen6_queue_flip(struct drm_device *dev,
struct drm_crtc *crtc,
struct drm_framebuffer *fb,
struct drm_i915_gem_object *obj)
{
struct drm_i915_private *dev_priv = dev->dev_private;
struct intel_crtc *intel_crtc = to_intel_crtc(crtc);
uint32_t pf, pipesrc;
int ret;
ret = intel_pin_and_fence_fb_obj(dev, obj, LP_RING(dev_priv));
if (ret)
goto out;
ret = BEGIN_LP_RING(4);
if (ret)
goto out;
OUT_RING(MI_DISPLAY_FLIP |
MI_DISPLAY_FLIP_PLANE(intel_crtc->plane));
OUT_RING(fb->pitches[0] | obj->tiling_mode);
OUT_RING(obj->gtt_offset);
pf = I915_READ(PF_CTL(intel_crtc->pipe)) & PF_ENABLE;
pipesrc = I915_READ(PIPESRC(intel_crtc->pipe)) & 0x0fff0fff;
OUT_RING(pf | pipesrc);
ADVANCE_LP_RING();
out:
return ret;
}
static int intel_gen7_queue_flip(struct drm_device *dev,
struct drm_crtc *crtc,
struct drm_framebuffer *fb,
struct drm_i915_gem_object *obj)
{
struct drm_i915_private *dev_priv = dev->dev_private;
struct intel_crtc *intel_crtc = to_intel_crtc(crtc);
struct intel_ring_buffer *ring = &dev_priv->ring[BCS];
int ret;
ret = intel_pin_and_fence_fb_obj(dev, obj, ring);
if (ret)
goto out;
ret = intel_ring_begin(ring, 4);
if (ret)
goto out;
intel_ring_emit(ring, MI_DISPLAY_FLIP_I915 | (intel_crtc->plane << 19));
intel_ring_emit(ring, (fb->pitches[0] | obj->tiling_mode));
intel_ring_emit(ring, (obj->gtt_offset));
intel_ring_emit(ring, (MI_NOOP));
intel_ring_advance(ring);
out:
return ret;
}
static int intel_default_queue_flip(struct drm_device *dev,
struct drm_crtc *crtc,
struct drm_framebuffer *fb,
struct drm_i915_gem_object *obj)
{
return -ENODEV;
}
static int intel_crtc_page_flip(struct drm_crtc *crtc,
struct drm_framebuffer *fb,
struct drm_pending_vblank_event *event)
{
struct drm_device *dev = crtc->dev;
struct drm_i915_private *dev_priv = dev->dev_private;
struct intel_framebuffer *intel_fb;
struct drm_i915_gem_object *obj;
struct intel_crtc *intel_crtc = to_intel_crtc(crtc);
struct intel_unpin_work *work;
unsigned long flags;
int ret;
work = kzalloc(sizeof *work, GFP_KERNEL);
if (work == NULL)
return -ENOMEM;
work->event = event;
work->dev = crtc->dev;
intel_fb = to_intel_framebuffer(crtc->fb);
work->old_fb_obj = intel_fb->obj;
INIT_WORK(&work->work, intel_unpin_work_fn);
ret = drm_vblank_get(dev, intel_crtc->pipe);
if (ret)
goto free_work;
spin_lock_irqsave(&dev->event_lock, flags);
if (intel_crtc->unpin_work) {
spin_unlock_irqrestore(&dev->event_lock, flags);
kfree(work);
drm_vblank_put(dev, intel_crtc->pipe);
DRM_DEBUG_DRIVER("flip queue: crtc already busy\n");
return -EBUSY;
}
intel_crtc->unpin_work = work;
spin_unlock_irqrestore(&dev->event_lock, flags);
intel_fb = to_intel_framebuffer(fb);
obj = intel_fb->obj;
mutex_lock(&dev->struct_mutex);
drm_gem_object_reference(&work->old_fb_obj->base);
drm_gem_object_reference(&obj->base);
crtc->fb = fb;
work->pending_flip_obj = obj;
work->enable_stall_check = true;
atomic_add(1 << intel_crtc->plane, &work->old_fb_obj->pending_flip);
ret = dev_priv->display.queue_flip(dev, crtc, fb, obj);
if (ret)
goto cleanup_pending;
intel_disable_fbc(dev);
mutex_unlock(&dev->struct_mutex);
trace_i915_flip_request(intel_crtc->plane, obj);
return 0;
cleanup_pending:
atomic_sub(1 << intel_crtc->plane, &work->old_fb_obj->pending_flip);
drm_gem_object_unreference(&work->old_fb_obj->base);
drm_gem_object_unreference(&obj->base);
mutex_unlock(&dev->struct_mutex);
spin_lock_irqsave(&dev->event_lock, flags);
intel_crtc->unpin_work = NULL;
spin_unlock_irqrestore(&dev->event_lock, flags);
drm_vblank_put(dev, intel_crtc->pipe);
free_work:
kfree(work);
return ret;
}
static void intel_sanitize_modesetting(struct drm_device *dev,
int pipe, int plane)
{
struct drm_i915_private *dev_priv = dev->dev_private;
u32 reg, val;
if (HAS_PCH_SPLIT(dev))
return;
reg = DSPCNTR(plane);
val = I915_READ(reg);
if ((val & DISPLAY_PLANE_ENABLE) == 0)
return;
if (!!(val & DISPPLANE_SEL_PIPE_MASK) == pipe)
return;
pipe = !pipe;
intel_disable_plane(dev_priv, plane, pipe);
intel_disable_pipe(dev_priv, pipe);
}
static void intel_crtc_reset(struct drm_crtc *crtc)
{
struct drm_device *dev = crtc->dev;
struct intel_crtc *intel_crtc = to_intel_crtc(crtc);
intel_crtc->dpms_mode = -1;
intel_sanitize_modesetting(dev, intel_crtc->pipe, intel_crtc->plane);
}
static void intel_crtc_init(struct drm_device *dev, int pipe)
{
drm_i915_private_t *dev_priv = dev->dev_private;
struct intel_crtc *intel_crtc;
int i;
intel_crtc = kzalloc(sizeof(struct intel_crtc) + (INTELFB_CONN_LIMIT * sizeof(struct drm_connector *)), GFP_KERNEL);
if (intel_crtc == NULL)
return;
drm_crtc_init(dev, &intel_crtc->base, &intel_crtc_funcs);
drm_mode_crtc_set_gamma_size(&intel_crtc->base, 256);
for (i = 0; i < 256; i++) {
intel_crtc->lut_r[i] = i;
intel_crtc->lut_g[i] = i;
intel_crtc->lut_b[i] = i;
}
intel_crtc->pipe = pipe;
intel_crtc->plane = pipe;
if (IS_MOBILE(dev) && IS_GEN3(dev)) {
DRM_DEBUG_KMS("swapping pipes & planes for FBC\n");
intel_crtc->plane = !pipe;
}
BUG_ON(pipe >= ARRAY_SIZE(dev_priv->plane_to_crtc_mapping) ||
dev_priv->plane_to_crtc_mapping[intel_crtc->plane] != NULL);
dev_priv->plane_to_crtc_mapping[intel_crtc->plane] = &intel_crtc->base;
dev_priv->pipe_to_crtc_mapping[intel_crtc->pipe] = &intel_crtc->base;
intel_crtc_reset(&intel_crtc->base);
intel_crtc->active = true;
intel_crtc->bpp = 24;
if (HAS_PCH_SPLIT(dev)) {
if (pipe == 2 && IS_IVYBRIDGE(dev))
intel_crtc->no_pll = true;
intel_helper_funcs.prepare = ironlake_crtc_prepare;
intel_helper_funcs.commit = ironlake_crtc_commit;
} else {
intel_helper_funcs.prepare = i9xx_crtc_prepare;
intel_helper_funcs.commit = i9xx_crtc_commit;
}
drm_crtc_helper_add(&intel_crtc->base, &intel_helper_funcs);
intel_crtc->busy = false;
setup_timer(&intel_crtc->idle_timer, intel_crtc_idle_timer,
(unsigned long)intel_crtc);
}
int intel_get_pipe_from_crtc_id(struct drm_device *dev, void *data,
struct drm_file *file)
{
drm_i915_private_t *dev_priv = dev->dev_private;
struct drm_i915_get_pipe_from_crtc_id *pipe_from_crtc_id = data;
struct drm_mode_object *drmmode_obj;
struct intel_crtc *crtc;
if (!dev_priv) {
DRM_ERROR("called with no initialization\n");
return -EINVAL;
}
drmmode_obj = drm_mode_object_find(dev, pipe_from_crtc_id->crtc_id,
DRM_MODE_OBJECT_CRTC);
if (!drmmode_obj) {
DRM_ERROR("no such CRTC id\n");
return -EINVAL;
}
crtc = to_intel_crtc(obj_to_crtc(drmmode_obj));
pipe_from_crtc_id->pipe = crtc->pipe;
return 0;
}
static int intel_encoder_clones(struct drm_device *dev, int type_mask)
{
struct intel_encoder *encoder;
int index_mask = 0;
int entry = 0;
list_for_each_entry(encoder, &dev->mode_config.encoder_list, base.head) {
if (type_mask & encoder->clone_mask)
index_mask |= (1 << entry);
entry++;
}
return index_mask;
}
static bool has_edp_a(struct drm_device *dev)
{
struct drm_i915_private *dev_priv = dev->dev_private;
if (!IS_MOBILE(dev))
return false;
if ((I915_READ(DP_A) & DP_DETECTED) == 0)
return false;
if (IS_GEN5(dev) &&
(I915_READ(ILK_DISPLAY_CHICKEN_FUSES) & ILK_eDP_A_DISABLE))
return false;
return true;
}
static void intel_setup_outputs(struct drm_device *dev)
{
struct drm_i915_private *dev_priv = dev->dev_private;
struct intel_encoder *encoder;
bool dpd_is_edp = false;
bool has_lvds = false;
if (IS_MOBILE(dev) && !IS_I830(dev))
has_lvds = intel_lvds_init(dev);
if (!has_lvds && !HAS_PCH_SPLIT(dev)) {
I915_WRITE(PFIT_CONTROL, 0);
}
if (HAS_PCH_SPLIT(dev)) {
dpd_is_edp = intel_dpd_is_edp(dev);
if (has_edp_a(dev))
intel_dp_init(dev, DP_A);
if (dpd_is_edp && (I915_READ(PCH_DP_D) & DP_DETECTED))
intel_dp_init(dev, PCH_DP_D);
}
intel_crt_init(dev);
if (HAS_PCH_SPLIT(dev)) {
int found;
if (I915_READ(HDMIB) & PORT_DETECTED) {
found = intel_sdvo_init(dev, PCH_SDVOB);
if (!found)
intel_hdmi_init(dev, HDMIB);
if (!found && (I915_READ(PCH_DP_B) & DP_DETECTED))
intel_dp_init(dev, PCH_DP_B);
}
if (I915_READ(HDMIC) & PORT_DETECTED)
intel_hdmi_init(dev, HDMIC);
if (I915_READ(HDMID) & PORT_DETECTED)
intel_hdmi_init(dev, HDMID);
if (I915_READ(PCH_DP_C) & DP_DETECTED)
intel_dp_init(dev, PCH_DP_C);
if (!dpd_is_edp && (I915_READ(PCH_DP_D) & DP_DETECTED))
intel_dp_init(dev, PCH_DP_D);
} else if (SUPPORTS_DIGITAL_OUTPUTS(dev)) {
bool found = false;
if (I915_READ(SDVOB) & SDVO_DETECTED) {
DRM_DEBUG_KMS("probing SDVOB\n");
found = intel_sdvo_init(dev, SDVOB);
if (!found && SUPPORTS_INTEGRATED_HDMI(dev)) {
DRM_DEBUG_KMS("probing HDMI on SDVOB\n");
intel_hdmi_init(dev, SDVOB);
}
if (!found && SUPPORTS_INTEGRATED_DP(dev)) {
DRM_DEBUG_KMS("probing DP_B\n");
intel_dp_init(dev, DP_B);
}
}
if (I915_READ(SDVOB) & SDVO_DETECTED) {
DRM_DEBUG_KMS("probing SDVOC\n");
found = intel_sdvo_init(dev, SDVOC);
}
if (!found && (I915_READ(SDVOC) & SDVO_DETECTED)) {
if (SUPPORTS_INTEGRATED_HDMI(dev)) {
DRM_DEBUG_KMS("probing HDMI on SDVOC\n");
intel_hdmi_init(dev, SDVOC);
}
if (SUPPORTS_INTEGRATED_DP(dev)) {
DRM_DEBUG_KMS("probing DP_C\n");
intel_dp_init(dev, DP_C);
}
}
if (SUPPORTS_INTEGRATED_DP(dev) &&
(I915_READ(DP_D) & DP_DETECTED)) {
DRM_DEBUG_KMS("probing DP_D\n");
intel_dp_init(dev, DP_D);
}
} else if (IS_GEN2(dev))
intel_dvo_init(dev);
if (SUPPORTS_TV(dev))
intel_tv_init(dev);
list_for_each_entry(encoder, &dev->mode_config.encoder_list, base.head) {
encoder->base.possible_crtcs = encoder->crtc_mask;
encoder->base.possible_clones =
intel_encoder_clones(dev, encoder->clone_mask);
}
drm_helper_disable_unused_functions(dev);
if (HAS_PCH_SPLIT(dev))
ironlake_init_pch_refclk(dev);
}
static void intel_user_framebuffer_destroy(struct drm_framebuffer *fb)
{
struct intel_framebuffer *intel_fb = to_intel_framebuffer(fb);
drm_framebuffer_cleanup(fb);
drm_gem_object_unreference_unlocked(&intel_fb->obj->base);
kfree(intel_fb);
}
static int intel_user_framebuffer_create_handle(struct drm_framebuffer *fb,
struct drm_file *file,
unsigned int *handle)
{
struct intel_framebuffer *intel_fb = to_intel_framebuffer(fb);
struct drm_i915_gem_object *obj = intel_fb->obj;
return drm_gem_handle_create(file, &obj->base, handle);
}
int intel_framebuffer_init(struct drm_device *dev,
struct intel_framebuffer *intel_fb,
struct drm_mode_fb_cmd2 *mode_cmd,
struct drm_i915_gem_object *obj)
{
int ret;
if (obj->tiling_mode == I915_TILING_Y)
return -EINVAL;
if (mode_cmd->pitches[0] & 63)
return -EINVAL;
switch (mode_cmd->pixel_format) {
case DRM_FORMAT_RGB332:
case DRM_FORMAT_RGB565:
case DRM_FORMAT_XRGB8888:
case DRM_FORMAT_XBGR8888:
case DRM_FORMAT_ARGB8888:
case DRM_FORMAT_XRGB2101010:
case DRM_FORMAT_ARGB2101010:
break;
case DRM_FORMAT_YUYV:
case DRM_FORMAT_UYVY:
case DRM_FORMAT_YVYU:
case DRM_FORMAT_VYUY:
break;
default:
DRM_ERROR("unsupported pixel format\n");
return -EINVAL;
}
ret = drm_framebuffer_init(dev, &intel_fb->base, &intel_fb_funcs);
if (ret) {
DRM_ERROR("framebuffer init failed %d\n", ret);
return ret;
}
drm_helper_mode_fill_fb_struct(&intel_fb->base, mode_cmd);
intel_fb->obj = obj;
return 0;
}
static struct drm_framebuffer *
intel_user_framebuffer_create(struct drm_device *dev,
struct drm_file *filp,
struct drm_mode_fb_cmd2 *mode_cmd)
{
struct drm_i915_gem_object *obj;
obj = to_intel_bo(drm_gem_object_lookup(dev, filp,
mode_cmd->handles[0]));
if (&obj->base == NULL)
return ERR_PTR(-ENOENT);
return intel_framebuffer_create(dev, mode_cmd, obj);
}
static struct drm_i915_gem_object *
intel_alloc_context_page(struct drm_device *dev)
{
struct drm_i915_gem_object *ctx;
int ret;
WARN_ON(!mutex_is_locked(&dev->struct_mutex));
ctx = i915_gem_alloc_object(dev, 4096);
if (!ctx) {
DRM_DEBUG("failed to alloc power context, RC6 disabled\n");
return NULL;
}
ret = i915_gem_object_pin(ctx, 4096, true);
if (ret) {
DRM_ERROR("failed to pin power context: %d\n", ret);
goto err_unref;
}
ret = i915_gem_object_set_to_gtt_domain(ctx, 1);
if (ret) {
DRM_ERROR("failed to set-domain on power context: %d\n", ret);
goto err_unpin;
}
return ctx;
err_unpin:
i915_gem_object_unpin(ctx);
err_unref:
drm_gem_object_unreference(&ctx->base);
mutex_unlock(&dev->struct_mutex);
return NULL;
}
bool ironlake_set_drps(struct drm_device *dev, u8 val)
{
struct drm_i915_private *dev_priv = dev->dev_private;
u16 rgvswctl;
rgvswctl = I915_READ16(MEMSWCTL);
if (rgvswctl & MEMCTL_CMD_STS) {
DRM_DEBUG("gpu busy, RCS change rejected\n");
return false;
}
rgvswctl = (MEMCTL_CMD_CHFREQ << MEMCTL_CMD_SHIFT) |
(val << MEMCTL_FREQ_SHIFT) | MEMCTL_SFCAVM;
I915_WRITE16(MEMSWCTL, rgvswctl);
POSTING_READ16(MEMSWCTL);
rgvswctl |= MEMCTL_CMD_STS;
I915_WRITE16(MEMSWCTL, rgvswctl);
return true;
}
void ironlake_enable_drps(struct drm_device *dev)
{
struct drm_i915_private *dev_priv = dev->dev_private;
u32 rgvmodectl = I915_READ(MEMMODECTL);
u8 fmax, fmin, fstart, vstart;
I915_WRITE16(PMMISC, I915_READ(PMMISC) | MCPPCE_EN);
I915_WRITE16(TSC1, I915_READ(TSC1) | TSE);
I915_WRITE(RCUPEI, 100000);
I915_WRITE(RCDNEI, 100000);
I915_WRITE(RCBMAXAVG, 90000);
I915_WRITE(RCBMINAVG, 80000);
I915_WRITE(MEMIHYST, 1);
fmax = (rgvmodectl & MEMMODE_FMAX_MASK) >> MEMMODE_FMAX_SHIFT;
fmin = (rgvmodectl & MEMMODE_FMIN_MASK);
fstart = (rgvmodectl & MEMMODE_FSTART_MASK) >>
MEMMODE_FSTART_SHIFT;
vstart = (I915_READ(PXVFREQ_BASE + (fstart * 4)) & PXVFREQ_PX_MASK) >>
PXVFREQ_PX_SHIFT;
dev_priv->fmax = fmax;
dev_priv->fstart = fstart;
dev_priv->max_delay = fstart;
dev_priv->min_delay = fmin;
dev_priv->cur_delay = fstart;
DRM_DEBUG_DRIVER("fmax: %d, fmin: %d, fstart: %d\n",
fmax, fmin, fstart);
I915_WRITE(MEMINTREN, MEMINT_CX_SUPR_EN | MEMINT_EVAL_CHG_EN);
I915_WRITE(VIDSTART, vstart);
POSTING_READ(VIDSTART);
rgvmodectl |= MEMMODE_SWMODE_EN;
I915_WRITE(MEMMODECTL, rgvmodectl);
if (wait_for((I915_READ(MEMSWCTL) & MEMCTL_CMD_STS) == 0, 10))
DRM_ERROR("stuck trying to change perf mode\n");
msleep(1);
ironlake_set_drps(dev, fstart);
dev_priv->last_count1 = I915_READ(0x112e4) + I915_READ(0x112e8) +
I915_READ(0x112e0);
dev_priv->last_time1 = jiffies_to_msecs(jiffies);
dev_priv->last_count2 = I915_READ(0x112f4);
getrawmonotonic(&dev_priv->last_time2);
}
void ironlake_disable_drps(struct drm_device *dev)
{
struct drm_i915_private *dev_priv = dev->dev_private;
u16 rgvswctl = I915_READ16(MEMSWCTL);
I915_WRITE(MEMINTREN, I915_READ(MEMINTREN) & ~MEMINT_EVAL_CHG_EN);
I915_WRITE(MEMINTRSTS, MEMINT_EVAL_CHG);
I915_WRITE(DEIER, I915_READ(DEIER) & ~DE_PCU_EVENT);
I915_WRITE(DEIIR, DE_PCU_EVENT);
I915_WRITE(DEIMR, I915_READ(DEIMR) | DE_PCU_EVENT);
ironlake_set_drps(dev, dev_priv->fstart);
msleep(1);
rgvswctl |= MEMCTL_CMD_STS;
I915_WRITE(MEMSWCTL, rgvswctl);
msleep(1);
}
void gen6_set_rps(struct drm_device *dev, u8 val)
{
struct drm_i915_private *dev_priv = dev->dev_private;
u32 swreq;
swreq = (val & 0x3ff) << 25;
I915_WRITE(GEN6_RPNSWREQ, swreq);
}
void gen6_disable_rps(struct drm_device *dev)
{
struct drm_i915_private *dev_priv = dev->dev_private;
I915_WRITE(GEN6_RPNSWREQ, 1 << 31);
I915_WRITE(GEN6_PMINTRMSK, 0xffffffff);
I915_WRITE(GEN6_PMIER, 0);
spin_lock_irq(&dev_priv->rps_lock);
dev_priv->pm_iir = 0;
spin_unlock_irq(&dev_priv->rps_lock);
I915_WRITE(GEN6_PMIIR, I915_READ(GEN6_PMIIR));
}
static unsigned long intel_pxfreq(u32 vidfreq)
{
unsigned long freq;
int div = (vidfreq & 0x3f0000) >> 16;
int post = (vidfreq & 0x3000) >> 12;
int pre = (vidfreq & 0x7);
if (!pre)
return 0;
freq = ((div * 133333) / ((1<<post) * pre));
return freq;
}
void intel_init_emon(struct drm_device *dev)
{
struct drm_i915_private *dev_priv = dev->dev_private;
u32 lcfuse;
u8 pxw[16];
int i;
I915_WRITE(ECR, 0);
POSTING_READ(ECR);
I915_WRITE(SDEW, 0x15040d00);
I915_WRITE(CSIEW0, 0x007f0000);
I915_WRITE(CSIEW1, 0x1e220004);
I915_WRITE(CSIEW2, 0x04000004);
for (i = 0; i < 5; i++)
I915_WRITE(PEW + (i * 4), 0);
for (i = 0; i < 3; i++)
I915_WRITE(DEW + (i * 4), 0);
for (i = 0; i < 16; i++) {
u32 pxvidfreq = I915_READ(PXVFREQ_BASE + (i * 4));
unsigned long freq = intel_pxfreq(pxvidfreq);
unsigned long vid = (pxvidfreq & PXVFREQ_PX_MASK) >>
PXVFREQ_PX_SHIFT;
unsigned long val;
val = vid * vid;
val *= (freq / 1000);
val *= 255;
val /= (127*127*900);
if (val > 0xff)
DRM_ERROR("bad pxval: %ld\n", val);
pxw[i] = val;
}
pxw[14] = 0;
pxw[15] = 0;
for (i = 0; i < 4; i++) {
u32 val = (pxw[i*4] << 24) | (pxw[(i*4)+1] << 16) |
(pxw[(i*4)+2] << 8) | (pxw[(i*4)+3]);
I915_WRITE(PXW + (i * 4), val);
}
I915_WRITE(OGW0, 0);
I915_WRITE(OGW1, 0);
I915_WRITE(EG0, 0x00007f00);
I915_WRITE(EG1, 0x0000000e);
I915_WRITE(EG2, 0x000e0000);
I915_WRITE(EG3, 0x68000300);
I915_WRITE(EG4, 0x42000000);
I915_WRITE(EG5, 0x00140031);
I915_WRITE(EG6, 0);
I915_WRITE(EG7, 0);
for (i = 0; i < 8; i++)
I915_WRITE(PXWL + (i * 4), 0);
I915_WRITE(ECR, 0x80000019);
lcfuse = I915_READ(LCFUSE02);
dev_priv->corr = (lcfuse & LCFUSE_HIV_MASK);
}
static bool intel_enable_rc6(struct drm_device *dev)
{
if (i915_enable_rc6 >= 0)
return i915_enable_rc6;
if (INTEL_INFO(dev)->gen == 5)
return 0;
if (INTEL_INFO(dev)->gen == 6) {
DRM_DEBUG_DRIVER("Sandybridge: RC6 disabled\n");
return 0;
}
DRM_DEBUG_DRIVER("RC6 enabled\n");
return 1;
}
void gen6_enable_rps(struct drm_i915_private *dev_priv)
{
u32 rp_state_cap = I915_READ(GEN6_RP_STATE_CAP);
u32 gt_perf_status = I915_READ(GEN6_GT_PERF_STATUS);
u32 pcu_mbox, rc6_mask = 0;
int cur_freq, min_freq, max_freq;
int i;
I915_WRITE(GEN6_RC_STATE, 0);
mutex_lock(&dev_priv->dev->struct_mutex);
gen6_gt_force_wake_get(dev_priv);
I915_WRITE(GEN6_RC_CONTROL, 0);
I915_WRITE(GEN6_RC1_WAKE_RATE_LIMIT, 1000 << 16);
I915_WRITE(GEN6_RC6_WAKE_RATE_LIMIT, 40 << 16 | 30);
I915_WRITE(GEN6_RC6pp_WAKE_RATE_LIMIT, 30);
I915_WRITE(GEN6_RC_EVALUATION_INTERVAL, 125000);
I915_WRITE(GEN6_RC_IDLE_HYSTERSIS, 25);
for (i = 0; i < I915_NUM_RINGS; i++)
I915_WRITE(RING_MAX_IDLE(dev_priv->ring[i].mmio_base), 10);
I915_WRITE(GEN6_RC_SLEEP, 0);
I915_WRITE(GEN6_RC1e_THRESHOLD, 1000);
I915_WRITE(GEN6_RC6_THRESHOLD, 50000);
I915_WRITE(GEN6_RC6p_THRESHOLD, 100000);
I915_WRITE(GEN6_RC6pp_THRESHOLD, 64000);
if (intel_enable_rc6(dev_priv->dev))
rc6_mask = GEN6_RC_CTL_RC6_ENABLE |
((IS_GEN7(dev_priv->dev)) ? GEN6_RC_CTL_RC6p_ENABLE : 0);
I915_WRITE(GEN6_RC_CONTROL,
rc6_mask |
GEN6_RC_CTL_EI_MODE(1) |
GEN6_RC_CTL_HW_ENABLE);
I915_WRITE(GEN6_RPNSWREQ,
GEN6_FREQUENCY(10) |
GEN6_OFFSET(0) |
GEN6_AGGRESSIVE_TURBO);
I915_WRITE(GEN6_RC_VIDEO_FREQ,
GEN6_FREQUENCY(12));
I915_WRITE(GEN6_RP_DOWN_TIMEOUT, 1000000);
I915_WRITE(GEN6_RP_INTERRUPT_LIMITS,
18 << 24 |
6 << 16);
I915_WRITE(GEN6_RP_UP_THRESHOLD, 10000);
I915_WRITE(GEN6_RP_DOWN_THRESHOLD, 1000000);
I915_WRITE(GEN6_RP_UP_EI, 100000);
I915_WRITE(GEN6_RP_DOWN_EI, 5000000);
I915_WRITE(GEN6_RP_IDLE_HYSTERSIS, 10);
I915_WRITE(GEN6_RP_CONTROL,
GEN6_RP_MEDIA_TURBO |
GEN6_RP_MEDIA_HW_MODE |
GEN6_RP_MEDIA_IS_GFX |
GEN6_RP_ENABLE |
GEN6_RP_UP_BUSY_AVG |
GEN6_RP_DOWN_IDLE_CONT);
if (wait_for((I915_READ(GEN6_PCODE_MAILBOX) & GEN6_PCODE_READY) == 0,
500))
DRM_ERROR("timeout waiting for pcode mailbox to become idle\n");
I915_WRITE(GEN6_PCODE_DATA, 0);
I915_WRITE(GEN6_PCODE_MAILBOX,
GEN6_PCODE_READY |
GEN6_PCODE_WRITE_MIN_FREQ_TABLE);
if (wait_for((I915_READ(GEN6_PCODE_MAILBOX) & GEN6_PCODE_READY) == 0,
500))
DRM_ERROR("timeout waiting for pcode mailbox to finish\n");
min_freq = (rp_state_cap & 0xff0000) >> 16;
max_freq = rp_state_cap & 0xff;
cur_freq = (gt_perf_status & 0xff00) >> 8;
if (wait_for((I915_READ(GEN6_PCODE_MAILBOX) & GEN6_PCODE_READY) == 0,
500))
DRM_ERROR("timeout waiting for pcode mailbox to become idle\n");
I915_WRITE(GEN6_PCODE_MAILBOX, GEN6_READ_OC_PARAMS);
pcu_mbox = I915_READ(GEN6_PCODE_DATA);
if (wait_for((I915_READ(GEN6_PCODE_MAILBOX) & GEN6_PCODE_READY) == 0,
500))
DRM_ERROR("timeout waiting for pcode mailbox to finish\n");
if (pcu_mbox & (1<<31)) {
max_freq = pcu_mbox & 0xff;
DRM_DEBUG_DRIVER("overclocking supported, adjusting frequency max to %dMHz\n", pcu_mbox * 50);
}
dev_priv->max_delay = max_freq;
dev_priv->min_delay = min_freq;
dev_priv->cur_delay = cur_freq;
I915_WRITE(GEN6_PMIER,
GEN6_PM_MBOX_EVENT |
GEN6_PM_THERMAL_EVENT |
GEN6_PM_RP_DOWN_TIMEOUT |
GEN6_PM_RP_UP_THRESHOLD |
GEN6_PM_RP_DOWN_THRESHOLD |
GEN6_PM_RP_UP_EI_EXPIRED |
GEN6_PM_RP_DOWN_EI_EXPIRED);
spin_lock_irq(&dev_priv->rps_lock);
WARN_ON(dev_priv->pm_iir != 0);
I915_WRITE(GEN6_PMIMR, 0);
spin_unlock_irq(&dev_priv->rps_lock);
I915_WRITE(GEN6_PMINTRMSK, 0);
gen6_gt_force_wake_put(dev_priv);
mutex_unlock(&dev_priv->dev->struct_mutex);
}
void gen6_update_ring_freq(struct drm_i915_private *dev_priv)
{
int min_freq = 15;
int gpu_freq, ia_freq, max_ia_freq;
int scaling_factor = 180;
max_ia_freq = cpufreq_quick_get_max(0);
if (!max_ia_freq)
max_ia_freq = tsc_khz;
max_ia_freq /= 1000;
mutex_lock(&dev_priv->dev->struct_mutex);
for (gpu_freq = dev_priv->max_delay; gpu_freq >= dev_priv->min_delay;
gpu_freq--) {
int diff = dev_priv->max_delay - gpu_freq;
if (gpu_freq < min_freq)
ia_freq = 800;
else
ia_freq = max_ia_freq - ((diff * scaling_factor) / 2);
ia_freq = DIV_ROUND_CLOSEST(ia_freq, 100);
I915_WRITE(GEN6_PCODE_DATA,
(ia_freq << GEN6_PCODE_FREQ_IA_RATIO_SHIFT) |
gpu_freq);
I915_WRITE(GEN6_PCODE_MAILBOX, GEN6_PCODE_READY |
GEN6_PCODE_WRITE_MIN_FREQ_TABLE);
if (wait_for((I915_READ(GEN6_PCODE_MAILBOX) &
GEN6_PCODE_READY) == 0, 10)) {
DRM_ERROR("pcode write of freq table timed out\n");
continue;
}
}
mutex_unlock(&dev_priv->dev->struct_mutex);
}
static void ironlake_init_clock_gating(struct drm_device *dev)
{
struct drm_i915_private *dev_priv = dev->dev_private;
uint32_t dspclk_gate = VRHUNIT_CLOCK_GATE_DISABLE;
dspclk_gate |= DPFCUNIT_CLOCK_GATE_DISABLE |
DPFCRUNIT_CLOCK_GATE_DISABLE |
DPFDUNIT_CLOCK_GATE_DISABLE;
dspclk_gate |= DPARBUNIT_CLOCK_GATE_DISABLE;
I915_WRITE(PCH_3DCGDIS0,
MARIUNIT_CLOCK_GATE_DISABLE |
SVSMUNIT_CLOCK_GATE_DISABLE);
I915_WRITE(PCH_3DCGDIS1,
VFMUNIT_CLOCK_GATE_DISABLE);
I915_WRITE(PCH_DSPCLK_GATE_D, dspclk_gate);
I915_WRITE(ILK_DISPLAY_CHICKEN2,
(I915_READ(ILK_DISPLAY_CHICKEN2) |
ILK_DPARB_GATE | ILK_VSDPFD_FULL));
I915_WRITE(ILK_DSPCLK_GATE,
(I915_READ(ILK_DSPCLK_GATE) |
ILK_DPARB_CLK_GATE));
I915_WRITE(DISP_ARB_CTL,
(I915_READ(DISP_ARB_CTL) |
DISP_FBC_WM_DIS));
I915_WRITE(WM3_LP_ILK, 0);
I915_WRITE(WM2_LP_ILK, 0);
I915_WRITE(WM1_LP_ILK, 0);
if (IS_IRONLAKE_M(dev)) {
I915_WRITE(ILK_DISPLAY_CHICKEN1,
I915_READ(ILK_DISPLAY_CHICKEN1) |
ILK_FBCQ_DIS);
I915_WRITE(ILK_DISPLAY_CHICKEN2,
I915_READ(ILK_DISPLAY_CHICKEN2) |
ILK_DPARB_GATE);
I915_WRITE(ILK_DSPCLK_GATE,
I915_READ(ILK_DSPCLK_GATE) |
ILK_DPFC_DIS1 |
ILK_DPFC_DIS2 |
ILK_CLK_FBC);
}
I915_WRITE(ILK_DISPLAY_CHICKEN2,
I915_READ(ILK_DISPLAY_CHICKEN2) |
ILK_ELPIN_409_SELECT);
I915_WRITE(_3D_CHICKEN2,
_3D_CHICKEN2_WM_READ_PIPELINED << 16 |
_3D_CHICKEN2_WM_READ_PIPELINED);
}
static void gen6_init_clock_gating(struct drm_device *dev)
{
struct drm_i915_private *dev_priv = dev->dev_private;
int pipe;
uint32_t dspclk_gate = VRHUNIT_CLOCK_GATE_DISABLE;
I915_WRITE(PCH_DSPCLK_GATE_D, dspclk_gate);
I915_WRITE(ILK_DISPLAY_CHICKEN2,
I915_READ(ILK_DISPLAY_CHICKEN2) |
ILK_ELPIN_409_SELECT);
I915_WRITE(WM3_LP_ILK, 0);
I915_WRITE(WM2_LP_ILK, 0);
I915_WRITE(WM1_LP_ILK, 0);
I915_WRITE(GEN6_UCGCTL2,
GEN6_RCPBUNIT_CLOCK_GATE_DISABLE |
GEN6_RCCUNIT_CLOCK_GATE_DISABLE);
I915_WRITE(ILK_DISPLAY_CHICKEN1,
I915_READ(ILK_DISPLAY_CHICKEN1) |
ILK_FBCQ_DIS | ILK_PABSTRETCH_DIS);
I915_WRITE(ILK_DISPLAY_CHICKEN2,
I915_READ(ILK_DISPLAY_CHICKEN2) |
ILK_DPARB_GATE | ILK_VSDPFD_FULL);
I915_WRITE(ILK_DSPCLK_GATE,
I915_READ(ILK_DSPCLK_GATE) |
ILK_DPARB_CLK_GATE |
ILK_DPFD_CLK_GATE);
for_each_pipe(pipe) {
I915_WRITE(DSPCNTR(pipe),
I915_READ(DSPCNTR(pipe)) |
DISPPLANE_TRICKLE_FEED_DISABLE);
intel_flush_display_plane(dev_priv, pipe);
}
}
static void ivybridge_init_clock_gating(struct drm_device *dev)
{
struct drm_i915_private *dev_priv = dev->dev_private;
int pipe;
uint32_t dspclk_gate = VRHUNIT_CLOCK_GATE_DISABLE;
I915_WRITE(PCH_DSPCLK_GATE_D, dspclk_gate);
I915_WRITE(WM3_LP_ILK, 0);
I915_WRITE(WM2_LP_ILK, 0);
I915_WRITE(WM1_LP_ILK, 0);
I915_WRITE(GEN6_UCGCTL2, GEN6_RCZUNIT_CLOCK_GATE_DISABLE);
I915_WRITE(ILK_DSPCLK_GATE, IVB_VRHUNIT_CLK_GATE);
I915_WRITE(IVB_CHICKEN3,
CHICKEN3_DGMG_REQ_OUT_FIX_DISABLE |
CHICKEN3_DGMG_DONE_FIX_DISABLE);
I915_WRITE(GEN7_COMMON_SLICE_CHICKEN1,
GEN7_CSC1_RHWO_OPT_DISABLE_IN_RCC);
I915_WRITE(GEN7_L3CNTLREG1,
GEN7_WA_FOR_GEN7_L3_CONTROL);
I915_WRITE(GEN7_L3_CHICKEN_MODE_REGISTER,
GEN7_WA_L3_CHICKEN_MODE);
I915_WRITE(GEN7_SQ_CHICKEN_MBCUNIT_CONFIG,
I915_READ(GEN7_SQ_CHICKEN_MBCUNIT_CONFIG) |
GEN7_SQ_CHICKEN_MBCUNIT_SQINTMOB);
for_each_pipe(pipe) {
I915_WRITE(DSPCNTR(pipe),
I915_READ(DSPCNTR(pipe)) |
DISPPLANE_TRICKLE_FEED_DISABLE);
intel_flush_display_plane(dev_priv, pipe);
}
}
static void g4x_init_clock_gating(struct drm_device *dev)
{
struct drm_i915_private *dev_priv = dev->dev_private;
uint32_t dspclk_gate;
I915_WRITE(RENCLK_GATE_D1, 0);
I915_WRITE(RENCLK_GATE_D2, VF_UNIT_CLOCK_GATE_DISABLE |
GS_UNIT_CLOCK_GATE_DISABLE |
CL_UNIT_CLOCK_GATE_DISABLE);
I915_WRITE(RAMCLK_GATE_D, 0);
dspclk_gate = VRHUNIT_CLOCK_GATE_DISABLE |
OVRUNIT_CLOCK_GATE_DISABLE |
OVCUNIT_CLOCK_GATE_DISABLE;
if (IS_GM45(dev))
dspclk_gate |= DSSUNIT_CLOCK_GATE_DISABLE;
I915_WRITE(DSPCLK_GATE_D, dspclk_gate);
}
static void crestline_init_clock_gating(struct drm_device *dev)
{
struct drm_i915_private *dev_priv = dev->dev_private;
I915_WRITE(RENCLK_GATE_D1, I965_RCC_CLOCK_GATE_DISABLE);
I915_WRITE(RENCLK_GATE_D2, 0);
I915_WRITE(DSPCLK_GATE_D, 0);
I915_WRITE(RAMCLK_GATE_D, 0);
I915_WRITE16(DEUC, 0);
}
static void broadwater_init_clock_gating(struct drm_device *dev)
{
struct drm_i915_private *dev_priv = dev->dev_private;
I915_WRITE(RENCLK_GATE_D1, I965_RCZ_CLOCK_GATE_DISABLE |
I965_RCC_CLOCK_GATE_DISABLE |
I965_RCPB_CLOCK_GATE_DISABLE |
I965_ISC_CLOCK_GATE_DISABLE |
I965_FBC_CLOCK_GATE_DISABLE);
I915_WRITE(RENCLK_GATE_D2, 0);
}
static void gen3_init_clock_gating(struct drm_device *dev)
{
struct drm_i915_private *dev_priv = dev->dev_private;
u32 dstate = I915_READ(D_STATE);
dstate |= DSTATE_PLL_D3_OFF | DSTATE_GFX_CLOCK_GATING |
DSTATE_DOT_CLOCK_GATING;
I915_WRITE(D_STATE, dstate);
}
static void i85x_init_clock_gating(struct drm_device *dev)
{
struct drm_i915_private *dev_priv = dev->dev_private;
I915_WRITE(RENCLK_GATE_D1, SV_CLOCK_GATE_DISABLE);
}
static void i830_init_clock_gating(struct drm_device *dev)
{
struct drm_i915_private *dev_priv = dev->dev_private;
I915_WRITE(DSPCLK_GATE_D, OVRUNIT_CLOCK_GATE_DISABLE);
}
static void ibx_init_clock_gating(struct drm_device *dev)
{
struct drm_i915_private *dev_priv = dev->dev_private;
I915_WRITE(SOUTH_DSPCLK_GATE_D, PCH_DPLSUNIT_CLOCK_GATE_DISABLE);
}
static void cpt_init_clock_gating(struct drm_device *dev)
{
struct drm_i915_private *dev_priv = dev->dev_private;
int pipe;
I915_WRITE(SOUTH_DSPCLK_GATE_D, PCH_DPLSUNIT_CLOCK_GATE_DISABLE);
I915_WRITE(SOUTH_CHICKEN2, I915_READ(SOUTH_CHICKEN2) |
DPLS_EDP_PPS_FIX_DIS);
for_each_pipe(pipe)
I915_WRITE(TRANS_CHICKEN2(pipe), TRANS_AUTOTRAIN_GEN_STALL_DIS);
}
static void ironlake_teardown_rc6(struct drm_device *dev)
{
struct drm_i915_private *dev_priv = dev->dev_private;
if (dev_priv->renderctx) {
i915_gem_object_unpin(dev_priv->renderctx);
drm_gem_object_unreference(&dev_priv->renderctx->base);
dev_priv->renderctx = NULL;
}
if (dev_priv->pwrctx) {
i915_gem_object_unpin(dev_priv->pwrctx);
drm_gem_object_unreference(&dev_priv->pwrctx->base);
dev_priv->pwrctx = NULL;
}
}
static void ironlake_disable_rc6(struct drm_device *dev)
{
struct drm_i915_private *dev_priv = dev->dev_private;
if (I915_READ(PWRCTXA)) {
I915_WRITE(RSTDBYCTL, I915_READ(RSTDBYCTL) | RCX_SW_EXIT);
wait_for(((I915_READ(RSTDBYCTL) & RSX_STATUS_MASK) == RSX_STATUS_ON),
50);
I915_WRITE(PWRCTXA, 0);
POSTING_READ(PWRCTXA);
I915_WRITE(RSTDBYCTL, I915_READ(RSTDBYCTL) & ~RCX_SW_EXIT);
POSTING_READ(RSTDBYCTL);
}
ironlake_teardown_rc6(dev);
}
static int ironlake_setup_rc6(struct drm_device *dev)
{
struct drm_i915_private *dev_priv = dev->dev_private;
if (dev_priv->renderctx == NULL)
dev_priv->renderctx = intel_alloc_context_page(dev);
if (!dev_priv->renderctx)
return -ENOMEM;
if (dev_priv->pwrctx == NULL)
dev_priv->pwrctx = intel_alloc_context_page(dev);
if (!dev_priv->pwrctx) {
ironlake_teardown_rc6(dev);
return -ENOMEM;
}
return 0;
}
void ironlake_enable_rc6(struct drm_device *dev)
{
struct drm_i915_private *dev_priv = dev->dev_private;
int ret;
if (!intel_enable_rc6(dev))
return;
mutex_lock(&dev->struct_mutex);
ret = ironlake_setup_rc6(dev);
if (ret) {
mutex_unlock(&dev->struct_mutex);
return;
}
ret = BEGIN_LP_RING(6);
if (ret) {
ironlake_teardown_rc6(dev);
mutex_unlock(&dev->struct_mutex);
return;
}
OUT_RING(MI_SUSPEND_FLUSH | MI_SUSPEND_FLUSH_EN);
OUT_RING(MI_SET_CONTEXT);
OUT_RING(dev_priv->renderctx->gtt_offset |
MI_MM_SPACE_GTT |
MI_SAVE_EXT_STATE_EN |
MI_RESTORE_EXT_STATE_EN |
MI_RESTORE_INHIBIT);
OUT_RING(MI_SUSPEND_FLUSH);
OUT_RING(MI_NOOP);
OUT_RING(MI_FLUSH);
ADVANCE_LP_RING();
ret = intel_wait_ring_idle(LP_RING(dev_priv));
if (ret) {
DRM_ERROR("failed to enable ironlake power power savings\n");
ironlake_teardown_rc6(dev);
mutex_unlock(&dev->struct_mutex);
return;
}
I915_WRITE(PWRCTXA, dev_priv->pwrctx->gtt_offset | PWRCTX_EN);
I915_WRITE(RSTDBYCTL, I915_READ(RSTDBYCTL) & ~RCX_SW_EXIT);
mutex_unlock(&dev->struct_mutex);
}
void intel_init_clock_gating(struct drm_device *dev)
{
struct drm_i915_private *dev_priv = dev->dev_private;
dev_priv->display.init_clock_gating(dev);
if (dev_priv->display.init_pch_clock_gating)
dev_priv->display.init_pch_clock_gating(dev);
}
static void intel_init_display(struct drm_device *dev)
{
struct drm_i915_private *dev_priv = dev->dev_private;
if (HAS_PCH_SPLIT(dev)) {
dev_priv->display.dpms = ironlake_crtc_dpms;
dev_priv->display.crtc_mode_set = ironlake_crtc_mode_set;
dev_priv->display.update_plane = ironlake_update_plane;
} else {
dev_priv->display.dpms = i9xx_crtc_dpms;
dev_priv->display.crtc_mode_set = i9xx_crtc_mode_set;
dev_priv->display.update_plane = i9xx_update_plane;
}
if (I915_HAS_FBC(dev)) {
if (HAS_PCH_SPLIT(dev)) {
dev_priv->display.fbc_enabled = ironlake_fbc_enabled;
dev_priv->display.enable_fbc = ironlake_enable_fbc;
dev_priv->display.disable_fbc = ironlake_disable_fbc;
} else if (IS_GM45(dev)) {
dev_priv->display.fbc_enabled = g4x_fbc_enabled;
dev_priv->display.enable_fbc = g4x_enable_fbc;
dev_priv->display.disable_fbc = g4x_disable_fbc;
} else if (IS_CRESTLINE(dev)) {
dev_priv->display.fbc_enabled = i8xx_fbc_enabled;
dev_priv->display.enable_fbc = i8xx_enable_fbc;
dev_priv->display.disable_fbc = i8xx_disable_fbc;
}
}
if (IS_I945G(dev) || (IS_G33(dev) && !IS_PINEVIEW_M(dev)))
dev_priv->display.get_display_clock_speed =
i945_get_display_clock_speed;
else if (IS_I915G(dev))
dev_priv->display.get_display_clock_speed =
i915_get_display_clock_speed;
else if (IS_I945GM(dev) || IS_845G(dev) || IS_PINEVIEW_M(dev))
dev_priv->display.get_display_clock_speed =
i9xx_misc_get_display_clock_speed;
else if (IS_I915GM(dev))
dev_priv->display.get_display_clock_speed =
i915gm_get_display_clock_speed;
else if (IS_I865G(dev))
dev_priv->display.get_display_clock_speed =
i865_get_display_clock_speed;
else if (IS_I85X(dev))
dev_priv->display.get_display_clock_speed =
i855_get_display_clock_speed;
else
dev_priv->display.get_display_clock_speed =
i830_get_display_clock_speed;
if (HAS_PCH_SPLIT(dev)) {
dev_priv->display.force_wake_get = __gen6_gt_force_wake_get;
dev_priv->display.force_wake_put = __gen6_gt_force_wake_put;
if (IS_IVYBRIDGE(dev)) {
u32 ecobus;
mutex_lock(&dev->struct_mutex);
__gen6_gt_force_wake_mt_get(dev_priv);
ecobus = I915_READ_NOTRACE(ECOBUS);
__gen6_gt_force_wake_mt_put(dev_priv);
mutex_unlock(&dev->struct_mutex);
if (ecobus & FORCEWAKE_MT_ENABLE) {
DRM_DEBUG_KMS("Using MT version of forcewake\n");
dev_priv->display.force_wake_get =
__gen6_gt_force_wake_mt_get;
dev_priv->display.force_wake_put =
__gen6_gt_force_wake_mt_put;
}
}
if (HAS_PCH_IBX(dev))
dev_priv->display.init_pch_clock_gating = ibx_init_clock_gating;
else if (HAS_PCH_CPT(dev))
dev_priv->display.init_pch_clock_gating = cpt_init_clock_gating;
if (IS_GEN5(dev)) {
if (I915_READ(MLTR_ILK) & ILK_SRLT_MASK)
dev_priv->display.update_wm = ironlake_update_wm;
else {
DRM_DEBUG_KMS("Failed to get proper latency. "
"Disable CxSR\n");
dev_priv->display.update_wm = NULL;
}
dev_priv->display.fdi_link_train = ironlake_fdi_link_train;
dev_priv->display.init_clock_gating = ironlake_init_clock_gating;
dev_priv->display.write_eld = ironlake_write_eld;
} else if (IS_GEN6(dev)) {
if (SNB_READ_WM0_LATENCY()) {
dev_priv->display.update_wm = sandybridge_update_wm;
dev_priv->display.update_sprite_wm = sandybridge_update_sprite_wm;
} else {
DRM_DEBUG_KMS("Failed to read display plane latency. "
"Disable CxSR\n");
dev_priv->display.update_wm = NULL;
}
dev_priv->display.fdi_link_train = gen6_fdi_link_train;
dev_priv->display.init_clock_gating = gen6_init_clock_gating;
dev_priv->display.write_eld = ironlake_write_eld;
} else if (IS_IVYBRIDGE(dev)) {
dev_priv->display.fdi_link_train = ivb_manual_fdi_link_train;
if (SNB_READ_WM0_LATENCY()) {
dev_priv->display.update_wm = sandybridge_update_wm;
dev_priv->display.update_sprite_wm = sandybridge_update_sprite_wm;
} else {
DRM_DEBUG_KMS("Failed to read display plane latency. "
"Disable CxSR\n");
dev_priv->display.update_wm = NULL;
}
dev_priv->display.init_clock_gating = ivybridge_init_clock_gating;
dev_priv->display.write_eld = ironlake_write_eld;
} else
dev_priv->display.update_wm = NULL;
} else if (IS_PINEVIEW(dev)) {
if (!intel_get_cxsr_latency(IS_PINEVIEW_G(dev),
dev_priv->is_ddr3,
dev_priv->fsb_freq,
dev_priv->mem_freq)) {
DRM_INFO("failed to find known CxSR latency "
"(found ddr%s fsb freq %d, mem freq %d), "
"disabling CxSR\n",
(dev_priv->is_ddr3 == 1) ? "3" : "2",
dev_priv->fsb_freq, dev_priv->mem_freq);
pineview_disable_cxsr(dev);
dev_priv->display.update_wm = NULL;
} else
dev_priv->display.update_wm = pineview_update_wm;
dev_priv->display.init_clock_gating = gen3_init_clock_gating;
} else if (IS_G4X(dev)) {
dev_priv->display.write_eld = g4x_write_eld;
dev_priv->display.update_wm = g4x_update_wm;
dev_priv->display.init_clock_gating = g4x_init_clock_gating;
} else if (IS_GEN4(dev)) {
dev_priv->display.update_wm = i965_update_wm;
if (IS_CRESTLINE(dev))
dev_priv->display.init_clock_gating = crestline_init_clock_gating;
else if (IS_BROADWATER(dev))
dev_priv->display.init_clock_gating = broadwater_init_clock_gating;
} else if (IS_GEN3(dev)) {
dev_priv->display.update_wm = i9xx_update_wm;
dev_priv->display.get_fifo_size = i9xx_get_fifo_size;
dev_priv->display.init_clock_gating = gen3_init_clock_gating;
} else if (IS_I865G(dev)) {
dev_priv->display.update_wm = i830_update_wm;
dev_priv->display.init_clock_gating = i85x_init_clock_gating;
dev_priv->display.get_fifo_size = i830_get_fifo_size;
} else if (IS_I85X(dev)) {
dev_priv->display.update_wm = i9xx_update_wm;
dev_priv->display.get_fifo_size = i85x_get_fifo_size;
dev_priv->display.init_clock_gating = i85x_init_clock_gating;
} else {
dev_priv->display.update_wm = i830_update_wm;
dev_priv->display.init_clock_gating = i830_init_clock_gating;
if (IS_845G(dev))
dev_priv->display.get_fifo_size = i845_get_fifo_size;
else
dev_priv->display.get_fifo_size = i830_get_fifo_size;
}
dev_priv->display.queue_flip = intel_default_queue_flip;
switch (INTEL_INFO(dev)->gen) {
case 2:
dev_priv->display.queue_flip = intel_gen2_queue_flip;
break;
case 3:
dev_priv->display.queue_flip = intel_gen3_queue_flip;
break;
case 4:
case 5:
dev_priv->display.queue_flip = intel_gen4_queue_flip;
break;
case 6:
dev_priv->display.queue_flip = intel_gen6_queue_flip;
break;
case 7:
dev_priv->display.queue_flip = intel_gen7_queue_flip;
break;
}
}
static void quirk_pipea_force(struct drm_device *dev)
{
struct drm_i915_private *dev_priv = dev->dev_private;
dev_priv->quirks |= QUIRK_PIPEA_FORCE;
DRM_DEBUG_DRIVER("applying pipe a force quirk\n");
}
static void quirk_ssc_force_disable(struct drm_device *dev)
{
struct drm_i915_private *dev_priv = dev->dev_private;
dev_priv->quirks |= QUIRK_LVDS_SSC_DISABLE;
}
static void intel_init_quirks(struct drm_device *dev)
{
struct pci_dev *d = dev->pdev;
int i;
for (i = 0; i < ARRAY_SIZE(intel_quirks); i++) {
struct intel_quirk *q = &intel_quirks[i];
if (d->device == q->device &&
(d->subsystem_vendor == q->subsystem_vendor ||
q->subsystem_vendor == PCI_ANY_ID) &&
(d->subsystem_device == q->subsystem_device ||
q->subsystem_device == PCI_ANY_ID))
q->hook(dev);
}
}
static void i915_disable_vga(struct drm_device *dev)
{
struct drm_i915_private *dev_priv = dev->dev_private;
u8 sr1;
u32 vga_reg;
if (HAS_PCH_SPLIT(dev))
vga_reg = CPU_VGACNTRL;
else
vga_reg = VGACNTRL;
vga_get_uninterruptible(dev->pdev, VGA_RSRC_LEGACY_IO);
outb(1, VGA_SR_INDEX);
sr1 = inb(VGA_SR_DATA);
outb(sr1 | 1<<5, VGA_SR_DATA);
vga_put(dev->pdev, VGA_RSRC_LEGACY_IO);
udelay(300);
I915_WRITE(vga_reg, VGA_DISP_DISABLE);
POSTING_READ(vga_reg);
}
void intel_modeset_init(struct drm_device *dev)
{
struct drm_i915_private *dev_priv = dev->dev_private;
int i, ret;
drm_mode_config_init(dev);
dev->mode_config.min_width = 0;
dev->mode_config.min_height = 0;
dev->mode_config.funcs = (void *)&intel_mode_funcs;
intel_init_quirks(dev);
intel_init_display(dev);
if (IS_GEN2(dev)) {
dev->mode_config.max_width = 2048;
dev->mode_config.max_height = 2048;
} else if (IS_GEN3(dev)) {
dev->mode_config.max_width = 4096;
dev->mode_config.max_height = 4096;
} else {
dev->mode_config.max_width = 8192;
dev->mode_config.max_height = 8192;
}
dev->mode_config.fb_base = dev->agp->base;
DRM_DEBUG_KMS("%d display pipe%s available.\n",
dev_priv->num_pipe, dev_priv->num_pipe > 1 ? "s" : "");
for (i = 0; i < dev_priv->num_pipe; i++) {
intel_crtc_init(dev, i);
ret = intel_plane_init(dev, i);
if (ret)
DRM_DEBUG_KMS("plane %d init failed: %d\n", i, ret);
}
i915_disable_vga(dev);
intel_setup_outputs(dev);
intel_init_clock_gating(dev);
if (IS_IRONLAKE_M(dev)) {
ironlake_enable_drps(dev);
intel_init_emon(dev);
}
if (IS_GEN6(dev) || IS_GEN7(dev)) {
gen6_enable_rps(dev_priv);
gen6_update_ring_freq(dev_priv);
}
INIT_WORK(&dev_priv->idle_work, intel_idle_update);
setup_timer(&dev_priv->idle_timer, intel_gpu_idle_timer,
(unsigned long)dev);
}
void intel_modeset_gem_init(struct drm_device *dev)
{
if (IS_IRONLAKE_M(dev))
ironlake_enable_rc6(dev);
intel_setup_overlay(dev);
}
void intel_modeset_cleanup(struct drm_device *dev)
{
struct drm_i915_private *dev_priv = dev->dev_private;
struct drm_crtc *crtc;
struct intel_crtc *intel_crtc;
drm_kms_helper_poll_fini(dev);
mutex_lock(&dev->struct_mutex);
intel_unregister_dsm_handler();
list_for_each_entry(crtc, &dev->mode_config.crtc_list, head) {
if (!crtc->fb)
continue;
intel_crtc = to_intel_crtc(crtc);
intel_increase_pllclock(crtc);
}
intel_disable_fbc(dev);
if (IS_IRONLAKE_M(dev))
ironlake_disable_drps(dev);
if (IS_GEN6(dev) || IS_GEN7(dev))
gen6_disable_rps(dev);
if (IS_IRONLAKE_M(dev))
ironlake_disable_rc6(dev);
mutex_unlock(&dev->struct_mutex);
drm_irq_uninstall(dev);
cancel_work_sync(&dev_priv->hotplug_work);
cancel_work_sync(&dev_priv->rps_work);
flush_scheduled_work();
list_for_each_entry(crtc, &dev->mode_config.crtc_list, head) {
intel_crtc = to_intel_crtc(crtc);
del_timer_sync(&intel_crtc->idle_timer);
}
del_timer_sync(&dev_priv->idle_timer);
cancel_work_sync(&dev_priv->idle_work);
drm_mode_config_cleanup(dev);
}
struct drm_encoder *intel_best_encoder(struct drm_connector *connector)
{
return &intel_attached_encoder(connector)->base;
}
void intel_connector_attach_encoder(struct intel_connector *connector,
struct intel_encoder *encoder)
{
connector->encoder = encoder;
drm_mode_connector_attach_encoder(&connector->base,
&encoder->base);
}
int intel_modeset_vga_set_state(struct drm_device *dev, bool state)
{
struct drm_i915_private *dev_priv = dev->dev_private;
u16 gmch_ctrl;
pci_read_config_word(dev_priv->bridge_dev, INTEL_GMCH_CTRL, &gmch_ctrl);
if (state)
gmch_ctrl &= ~INTEL_GMCH_VGA_DISABLE;
else
gmch_ctrl |= INTEL_GMCH_VGA_DISABLE;
pci_write_config_word(dev_priv->bridge_dev, INTEL_GMCH_CTRL, gmch_ctrl);
return 0;
}
struct intel_display_error_state *
intel_display_capture_error_state(struct drm_device *dev)
{
drm_i915_private_t *dev_priv = dev->dev_private;
struct intel_display_error_state *error;
int i;
error = kmalloc(sizeof(*error), GFP_ATOMIC);
if (error == NULL)
return NULL;
for (i = 0; i < 2; i++) {
error->cursor[i].control = I915_READ(CURCNTR(i));
error->cursor[i].position = I915_READ(CURPOS(i));
error->cursor[i].base = I915_READ(CURBASE(i));
error->plane[i].control = I915_READ(DSPCNTR(i));
error->plane[i].stride = I915_READ(DSPSTRIDE(i));
error->plane[i].size = I915_READ(DSPSIZE(i));
error->plane[i].pos = I915_READ(DSPPOS(i));
error->plane[i].addr = I915_READ(DSPADDR(i));
if (INTEL_INFO(dev)->gen >= 4) {
error->plane[i].surface = I915_READ(DSPSURF(i));
error->plane[i].tile_offset = I915_READ(DSPTILEOFF(i));
}
error->pipe[i].conf = I915_READ(PIPECONF(i));
error->pipe[i].source = I915_READ(PIPESRC(i));
error->pipe[i].htotal = I915_READ(HTOTAL(i));
error->pipe[i].hblank = I915_READ(HBLANK(i));
error->pipe[i].hsync = I915_READ(HSYNC(i));
error->pipe[i].vtotal = I915_READ(VTOTAL(i));
error->pipe[i].vblank = I915_READ(VBLANK(i));
error->pipe[i].vsync = I915_READ(VSYNC(i));
}
return error;
}
void
intel_display_print_error_state(struct seq_file *m,
struct drm_device *dev,
struct intel_display_error_state *error)
{
int i;
for (i = 0; i < 2; i++) {
seq_printf(m, "Pipe [%d]:\n", i);
seq_printf(m, " CONF: %08x\n", error->pipe[i].conf);
seq_printf(m, " SRC: %08x\n", error->pipe[i].source);
seq_printf(m, " HTOTAL: %08x\n", error->pipe[i].htotal);
seq_printf(m, " HBLANK: %08x\n", error->pipe[i].hblank);
seq_printf(m, " HSYNC: %08x\n", error->pipe[i].hsync);
seq_printf(m, " VTOTAL: %08x\n", error->pipe[i].vtotal);
seq_printf(m, " VBLANK: %08x\n", error->pipe[i].vblank);
seq_printf(m, " VSYNC: %08x\n", error->pipe[i].vsync);
seq_printf(m, "Plane [%d]:\n", i);
seq_printf(m, " CNTR: %08x\n", error->plane[i].control);
seq_printf(m, " STRIDE: %08x\n", error->plane[i].stride);
seq_printf(m, " SIZE: %08x\n", error->plane[i].size);
seq_printf(m, " POS: %08x\n", error->plane[i].pos);
seq_printf(m, " ADDR: %08x\n", error->plane[i].addr);
if (INTEL_INFO(dev)->gen >= 4) {
seq_printf(m, " SURF: %08x\n", error->plane[i].surface);
seq_printf(m, " TILEOFF: %08x\n", error->plane[i].tile_offset);
}
seq_printf(m, "Cursor [%d]:\n", i);
seq_printf(m, " CNTR: %08x\n", error->cursor[i].control);
seq_printf(m, " POS: %08x\n", error->cursor[i].position);
seq_printf(m, " BASE: %08x\n", error->cursor[i].base);
}
}
