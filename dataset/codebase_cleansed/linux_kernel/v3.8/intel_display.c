int
intel_pch_rawclk(struct drm_device *dev)
{
struct drm_i915_private *dev_priv = dev->dev_private;
WARN_ON(!HAS_PCH_SPLIT(dev));
return I915_READ(PCH_RAWCLK_FREQ) & RAWCLK_FREQ_MASK;
}
static inline u32
intel_fdi_link_freq(struct drm_device *dev)
{
if (IS_GEN5(dev)) {
struct drm_i915_private *dev_priv = dev->dev_private;
return (I915_READ(FDI_PLL_BIOS_0) & FDI_PLL_FB_CLOCK_MASK) + 2;
} else
return 27;
}
u32 intel_dpio_read(struct drm_i915_private *dev_priv, int reg)
{
unsigned long flags;
u32 val = 0;
spin_lock_irqsave(&dev_priv->dpio_lock, flags);
if (wait_for_atomic_us((I915_READ(DPIO_PKT) & DPIO_BUSY) == 0, 100)) {
DRM_ERROR("DPIO idle wait timed out\n");
goto out_unlock;
}
I915_WRITE(DPIO_REG, reg);
I915_WRITE(DPIO_PKT, DPIO_RID | DPIO_OP_READ | DPIO_PORTID |
DPIO_BYTE);
if (wait_for_atomic_us((I915_READ(DPIO_PKT) & DPIO_BUSY) == 0, 100)) {
DRM_ERROR("DPIO read wait timed out\n");
goto out_unlock;
}
val = I915_READ(DPIO_DATA);
out_unlock:
spin_unlock_irqrestore(&dev_priv->dpio_lock, flags);
return val;
}
static void intel_dpio_write(struct drm_i915_private *dev_priv, int reg,
u32 val)
{
unsigned long flags;
spin_lock_irqsave(&dev_priv->dpio_lock, flags);
if (wait_for_atomic_us((I915_READ(DPIO_PKT) & DPIO_BUSY) == 0, 100)) {
DRM_ERROR("DPIO idle wait timed out\n");
goto out_unlock;
}
I915_WRITE(DPIO_DATA, val);
I915_WRITE(DPIO_REG, reg);
I915_WRITE(DPIO_PKT, DPIO_RID | DPIO_OP_WRITE | DPIO_PORTID |
DPIO_BYTE);
if (wait_for_atomic_us((I915_READ(DPIO_PKT) & DPIO_BUSY) == 0, 100))
DRM_ERROR("DPIO write wait timed out\n");
out_unlock:
spin_unlock_irqrestore(&dev_priv->dpio_lock, flags);
}
static void vlv_init_dpio(struct drm_device *dev)
{
struct drm_i915_private *dev_priv = dev->dev_private;
I915_WRITE(DPIO_CTL, 0);
POSTING_READ(DPIO_CTL);
I915_WRITE(DPIO_CTL, 1);
POSTING_READ(DPIO_CTL);
}
static int intel_dual_link_lvds_callback(const struct dmi_system_id *id)
{
DRM_INFO("Forcing lvds to dual link mode on %s\n", id->ident);
return 1;
}
static bool is_dual_link_lvds(struct drm_i915_private *dev_priv,
unsigned int reg)
{
unsigned int val;
if (i915_lvds_channel_mode > 0)
return i915_lvds_channel_mode == 2;
if (dmi_check_system(intel_dual_link_lvds))
return true;
if (dev_priv->lvds_val)
val = dev_priv->lvds_val;
else {
val = I915_READ(reg);
if (!(val & ~(LVDS_PIPE_MASK | LVDS_DETECTED)))
val = dev_priv->bios_lvds_val;
dev_priv->lvds_val = val;
}
return (val & LVDS_CLKB_POWER_MASK) == LVDS_CLKB_POWER_UP;
}
static const intel_limit_t *intel_ironlake_limit(struct drm_crtc *crtc,
int refclk)
{
struct drm_device *dev = crtc->dev;
struct drm_i915_private *dev_priv = dev->dev_private;
const intel_limit_t *limit;
if (intel_pipe_has_type(crtc, INTEL_OUTPUT_LVDS)) {
if (is_dual_link_lvds(dev_priv, PCH_LVDS)) {
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
intel_pipe_has_type(crtc, INTEL_OUTPUT_EDP))
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
if (is_dual_link_lvds(dev_priv, LVDS))
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
} else if (IS_VALLEYVIEW(dev)) {
if (intel_pipe_has_type(crtc, INTEL_OUTPUT_ANALOG))
limit = &intel_limits_vlv_dac;
else if (intel_pipe_has_type(crtc, INTEL_OUTPUT_HDMI))
limit = &intel_limits_vlv_hdmi;
else
limit = &intel_limits_vlv_dp;
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
struct intel_encoder *encoder;
for_each_encoder_on_crtc(dev, crtc, encoder)
if (encoder->type == type)
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
int target, int refclk, intel_clock_t *match_clock,
intel_clock_t *best_clock)
{
struct drm_device *dev = crtc->dev;
struct drm_i915_private *dev_priv = dev->dev_private;
intel_clock_t clock;
int err = target;
if (intel_pipe_has_type(crtc, INTEL_OUTPUT_LVDS) &&
(I915_READ(LVDS)) != 0) {
if (is_dual_link_lvds(dev_priv, LVDS))
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
if (match_clock &&
clock.p != match_clock->p)
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
int target, int refclk, intel_clock_t *match_clock,
intel_clock_t *best_clock)
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
if (match_clock &&
clock.p != match_clock->p)
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
int target, int refclk, intel_clock_t *match_clock,
intel_clock_t *best_clock)
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
int target, int refclk, intel_clock_t *match_clock,
intel_clock_t *best_clock)
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
static bool
intel_vlv_find_best_pll(const intel_limit_t *limit, struct drm_crtc *crtc,
int target, int refclk, intel_clock_t *match_clock,
intel_clock_t *best_clock)
{
u32 p1, p2, m1, m2, vco, bestn, bestm1, bestm2, bestp1, bestp2;
u32 m, n, fastclk;
u32 updrate, minupdate, fracbits, p;
unsigned long bestppm, ppm, absppm;
int dotclk, flag;
flag = 0;
dotclk = target * 1000;
bestppm = 1000000;
ppm = absppm = 0;
fastclk = dotclk / (2*100);
updrate = 0;
minupdate = 19200;
fracbits = 1;
n = p = p1 = p2 = m = m1 = m2 = vco = bestn = 0;
bestm1 = bestm2 = bestp1 = bestp2 = 0;
for (n = limit->n.min; n <= ((refclk) / minupdate); n++) {
updrate = refclk / n;
for (p1 = limit->p1.max; p1 > limit->p1.min; p1--) {
for (p2 = limit->p2.p2_fast+1; p2 > 0; p2--) {
if (p2 > 10)
p2 = p2 - 1;
p = p1 * p2;
for (m1 = limit->m1.min; m1 <= limit->m1.max; m1++) {
m2 = (((2*(fastclk * p * n / m1 )) +
refclk) / (2*refclk));
m = m1 * m2;
vco = updrate * m;
if (vco >= limit->vco.min && vco < limit->vco.max) {
ppm = 1000000 * ((vco / p) - fastclk) / fastclk;
absppm = (ppm > 0) ? ppm : (-ppm);
if (absppm < 100 && ((p1 * p2) > (bestp1 * bestp2))) {
bestppm = 0;
flag = 1;
}
if (absppm < bestppm - 10) {
bestppm = absppm;
flag = 1;
}
if (flag) {
bestn = n;
bestm1 = m1;
bestm2 = m2;
bestp1 = p1;
bestp2 = p2;
flag = 0;
}
}
}
}
}
}
best_clock->n = bestn;
best_clock->m1 = bestm1;
best_clock->m2 = bestm2;
best_clock->p1 = bestp1;
best_clock->p2 = bestp2;
return true;
}
enum transcoder intel_pipe_to_cpu_transcoder(struct drm_i915_private *dev_priv,
enum pipe pipe)
{
struct drm_crtc *crtc = dev_priv->pipe_to_crtc_mapping[pipe];
struct intel_crtc *intel_crtc = to_intel_crtc(crtc);
return intel_crtc->cpu_transcoder;
}
static void ironlake_wait_for_vblank(struct drm_device *dev, int pipe)
{
struct drm_i915_private *dev_priv = dev->dev_private;
u32 frame, frame_reg = PIPEFRAME(pipe);
frame = I915_READ(frame_reg);
if (wait_for(I915_READ_NOTRACE(frame_reg) != frame, 50))
DRM_DEBUG_KMS("vblank wait timed out\n");
}
void intel_wait_for_vblank(struct drm_device *dev, int pipe)
{
struct drm_i915_private *dev_priv = dev->dev_private;
int pipestat_reg = PIPESTAT(pipe);
if (INTEL_INFO(dev)->gen >= 5) {
ironlake_wait_for_vblank(dev, pipe);
return;
}
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
enum transcoder cpu_transcoder = intel_pipe_to_cpu_transcoder(dev_priv,
pipe);
if (INTEL_INFO(dev)->gen >= 4) {
int reg = PIPECONF(cpu_transcoder);
if (wait_for((I915_READ(reg) & I965_PIPECONF_ACTIVE) == 0,
100))
WARN(1, "pipe_off wait timed out\n");
} else {
u32 last_line, line_mask;
int reg = PIPEDSL(pipe);
unsigned long timeout = jiffies + msecs_to_jiffies(100);
if (IS_GEN2(dev))
line_mask = DSL_LINEMASK_GEN2;
else
line_mask = DSL_LINEMASK_GEN3;
do {
last_line = I915_READ(reg) & line_mask;
mdelay(5);
} while (((I915_READ(reg) & line_mask) != last_line) &&
time_after(timeout, jiffies));
if (time_after(jiffies, timeout))
WARN(1, "pipe_off wait timed out\n");
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
struct intel_pch_pll *pll,
struct intel_crtc *crtc,
bool state)
{
u32 val;
bool cur_state;
if (HAS_PCH_LPT(dev_priv->dev)) {
DRM_DEBUG_DRIVER("LPT detected: skipping PCH PLL test\n");
return;
}
if (WARN (!pll,
"asserting PCH PLL %s with no PLL\n", state_string(state)))
return;
val = I915_READ(pll->pll_reg);
cur_state = !!(val & DPLL_VCO_ENABLE);
WARN(cur_state != state,
"PCH PLL state for reg %x assertion failure (expected %s, current %s), val=%08x\n",
pll->pll_reg, state_string(state), state_string(cur_state), val);
if (crtc && HAS_PCH_CPT(dev_priv->dev)) {
u32 pch_dpll;
pch_dpll = I915_READ(PCH_DPLL_SEL);
cur_state = pll->pll_reg == _PCH_DPLL_B;
if (!WARN(((pch_dpll >> (4 * crtc->pipe)) & 1) != cur_state,
"PLL[%d] not attached to this transcoder %d: %08x\n",
cur_state, crtc->pipe, pch_dpll)) {
cur_state = !!(val >> (4*crtc->pipe + 3));
WARN(cur_state != state,
"PLL[%d] not %s on this transcoder %d: %08x\n",
pll->pll_reg == _PCH_DPLL_B,
state_string(state),
crtc->pipe,
val);
}
}
}
static void assert_fdi_tx(struct drm_i915_private *dev_priv,
enum pipe pipe, bool state)
{
int reg;
u32 val;
bool cur_state;
enum transcoder cpu_transcoder = intel_pipe_to_cpu_transcoder(dev_priv,
pipe);
if (IS_HASWELL(dev_priv->dev)) {
reg = TRANS_DDI_FUNC_CTL(cpu_transcoder);
val = I915_READ(reg);
cur_state = !!(val & TRANS_DDI_FUNC_ENABLE);
} else {
reg = FDI_TX_CTL(pipe);
val = I915_READ(reg);
cur_state = !!(val & FDI_TX_ENABLE);
}
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
if (IS_HASWELL(dev_priv->dev))
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
enum transcoder cpu_transcoder = intel_pipe_to_cpu_transcoder(dev_priv,
pipe);
if (pipe == PIPE_A && dev_priv->quirks & QUIRK_PIPEA_FORCE)
state = true;
reg = PIPECONF(cpu_transcoder);
val = I915_READ(reg);
cur_state = !!(val & PIPECONF_ENABLE);
WARN(cur_state != state,
"pipe %c assertion failure (expected %s, current %s)\n",
pipe_name(pipe), state_string(state), state_string(cur_state));
}
static void assert_plane(struct drm_i915_private *dev_priv,
enum plane plane, bool state)
{
int reg;
u32 val;
bool cur_state;
reg = DSPCNTR(plane);
val = I915_READ(reg);
cur_state = !!(val & DISPLAY_PLANE_ENABLE);
WARN(cur_state != state,
"plane %c assertion failure (expected %s, current %s)\n",
plane_name(plane), state_string(state), state_string(cur_state));
}
static void assert_planes_disabled(struct drm_i915_private *dev_priv,
enum pipe pipe)
{
int reg, i;
u32 val;
int cur_pipe;
if (HAS_PCH_SPLIT(dev_priv->dev)) {
reg = DSPCNTR(pipe);
val = I915_READ(reg);
WARN((val & DISPLAY_PLANE_ENABLE),
"plane %c assertion failure, should be disabled but not\n",
plane_name(pipe));
return;
}
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
if (HAS_PCH_LPT(dev_priv->dev)) {
DRM_DEBUG_DRIVER("LPT does not has PCH refclk, skipping check\n");
return;
}
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
WARN(HAS_PCH_IBX(dev_priv->dev) && (val & DP_PORT_EN) == 0
&& (val & DP_PIPEB_SELECT),
"IBX PCH dp port still using transcoder B\n");
}
static void assert_pch_hdmi_disabled(struct drm_i915_private *dev_priv,
enum pipe pipe, int reg)
{
u32 val = I915_READ(reg);
WARN(hdmi_pipe_enabled(dev_priv, pipe, val),
"PCH HDMI (0x%08x) enabled on transcoder %c, should be disabled\n",
reg, pipe_name(pipe));
WARN(HAS_PCH_IBX(dev_priv->dev) && (val & PORT_ENABLE) == 0
&& (val & SDVO_PIPE_B_SELECT),
"IBX PCH hdmi port still using transcoder B\n");
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
WARN(adpa_pipe_enabled(dev_priv, pipe, val),
"PCH VGA enabled on transcoder %c, should be disabled\n",
pipe_name(pipe));
reg = PCH_LVDS;
val = I915_READ(reg);
WARN(lvds_pipe_enabled(dev_priv, pipe, val),
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
BUG_ON(!IS_VALLEYVIEW(dev_priv->dev) && dev_priv->info->gen >= 5);
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
static void
intel_sbi_write(struct drm_i915_private *dev_priv, u16 reg, u32 value,
enum intel_sbi_destination destination)
{
unsigned long flags;
u32 tmp;
spin_lock_irqsave(&dev_priv->dpio_lock, flags);
if (wait_for((I915_READ(SBI_CTL_STAT) & SBI_BUSY) == 0, 100)) {
DRM_ERROR("timeout waiting for SBI to become ready\n");
goto out_unlock;
}
I915_WRITE(SBI_ADDR, (reg << 16));
I915_WRITE(SBI_DATA, value);
if (destination == SBI_ICLK)
tmp = SBI_CTL_DEST_ICLK | SBI_CTL_OP_CRWR;
else
tmp = SBI_CTL_DEST_MPHY | SBI_CTL_OP_IOWR;
I915_WRITE(SBI_CTL_STAT, SBI_BUSY | tmp);
if (wait_for((I915_READ(SBI_CTL_STAT) & (SBI_BUSY | SBI_RESPONSE_FAIL)) == 0,
100)) {
DRM_ERROR("timeout waiting for SBI to complete write transaction\n");
goto out_unlock;
}
out_unlock:
spin_unlock_irqrestore(&dev_priv->dpio_lock, flags);
}
static u32
intel_sbi_read(struct drm_i915_private *dev_priv, u16 reg,
enum intel_sbi_destination destination)
{
unsigned long flags;
u32 value = 0;
spin_lock_irqsave(&dev_priv->dpio_lock, flags);
if (wait_for((I915_READ(SBI_CTL_STAT) & SBI_BUSY) == 0, 100)) {
DRM_ERROR("timeout waiting for SBI to become ready\n");
goto out_unlock;
}
I915_WRITE(SBI_ADDR, (reg << 16));
if (destination == SBI_ICLK)
value = SBI_CTL_DEST_ICLK | SBI_CTL_OP_CRRD;
else
value = SBI_CTL_DEST_MPHY | SBI_CTL_OP_IORD;
I915_WRITE(SBI_CTL_STAT, value | SBI_BUSY);
if (wait_for((I915_READ(SBI_CTL_STAT) & (SBI_BUSY | SBI_RESPONSE_FAIL)) == 0,
100)) {
DRM_ERROR("timeout waiting for SBI to complete read transaction\n");
goto out_unlock;
}
value = I915_READ(SBI_DATA);
out_unlock:
spin_unlock_irqrestore(&dev_priv->dpio_lock, flags);
return value;
}
static void ironlake_enable_pch_pll(struct intel_crtc *intel_crtc)
{
struct drm_i915_private *dev_priv = intel_crtc->base.dev->dev_private;
struct intel_pch_pll *pll;
int reg;
u32 val;
BUG_ON(dev_priv->info->gen < 5);
pll = intel_crtc->pch_pll;
if (pll == NULL)
return;
if (WARN_ON(pll->refcount == 0))
return;
DRM_DEBUG_KMS("enable PCH PLL %x (active %d, on? %d)for crtc %d\n",
pll->pll_reg, pll->active, pll->on,
intel_crtc->base.base.id);
assert_pch_refclk_enabled(dev_priv);
if (pll->active++ && pll->on) {
assert_pch_pll_enabled(dev_priv, pll, NULL);
return;
}
DRM_DEBUG_KMS("enabling PCH PLL %x\n", pll->pll_reg);
reg = pll->pll_reg;
val = I915_READ(reg);
val |= DPLL_VCO_ENABLE;
I915_WRITE(reg, val);
POSTING_READ(reg);
udelay(200);
pll->on = true;
}
static void intel_disable_pch_pll(struct intel_crtc *intel_crtc)
{
struct drm_i915_private *dev_priv = intel_crtc->base.dev->dev_private;
struct intel_pch_pll *pll = intel_crtc->pch_pll;
int reg;
u32 val;
BUG_ON(dev_priv->info->gen < 5);
if (pll == NULL)
return;
if (WARN_ON(pll->refcount == 0))
return;
DRM_DEBUG_KMS("disable PCH PLL %x (active %d, on? %d) for crtc %d\n",
pll->pll_reg, pll->active, pll->on,
intel_crtc->base.base.id);
if (WARN_ON(pll->active == 0)) {
assert_pch_pll_disabled(dev_priv, pll, NULL);
return;
}
if (--pll->active) {
assert_pch_pll_enabled(dev_priv, pll, NULL);
return;
}
DRM_DEBUG_KMS("disabling PCH PLL %x\n", pll->pll_reg);
assert_transcoder_disabled(dev_priv, intel_crtc->pipe);
reg = pll->pll_reg;
val = I915_READ(reg);
val &= ~DPLL_VCO_ENABLE;
I915_WRITE(reg, val);
POSTING_READ(reg);
udelay(200);
pll->on = false;
}
static void ironlake_enable_pch_transcoder(struct drm_i915_private *dev_priv,
enum pipe pipe)
{
struct drm_device *dev = dev_priv->dev;
struct drm_crtc *crtc = dev_priv->pipe_to_crtc_mapping[pipe];
uint32_t reg, val, pipeconf_val;
BUG_ON(dev_priv->info->gen < 5);
assert_pch_pll_enabled(dev_priv,
to_intel_crtc(crtc)->pch_pll,
to_intel_crtc(crtc));
assert_fdi_tx_enabled(dev_priv, pipe);
assert_fdi_rx_enabled(dev_priv, pipe);
if (HAS_PCH_CPT(dev)) {
reg = TRANS_CHICKEN2(pipe);
val = I915_READ(reg);
val |= TRANS_CHICKEN2_TIMING_OVERRIDE;
I915_WRITE(reg, val);
}
reg = TRANSCONF(pipe);
val = I915_READ(reg);
pipeconf_val = I915_READ(PIPECONF(pipe));
if (HAS_PCH_IBX(dev_priv->dev)) {
val &= ~PIPE_BPC_MASK;
val |= pipeconf_val & PIPE_BPC_MASK;
}
val &= ~TRANS_INTERLACE_MASK;
if ((pipeconf_val & PIPECONF_INTERLACE_MASK) == PIPECONF_INTERLACED_ILK)
if (HAS_PCH_IBX(dev_priv->dev) &&
intel_pipe_has_type(crtc, INTEL_OUTPUT_SDVO))
val |= TRANS_LEGACY_INTERLACED_ILK;
else
val |= TRANS_INTERLACED;
else
val |= TRANS_PROGRESSIVE;
I915_WRITE(reg, val | TRANS_ENABLE);
if (wait_for(I915_READ(reg) & TRANS_STATE_ENABLE, 100))
DRM_ERROR("failed to enable transcoder %d\n", pipe);
}
static void lpt_enable_pch_transcoder(struct drm_i915_private *dev_priv,
enum transcoder cpu_transcoder)
{
u32 val, pipeconf_val;
BUG_ON(dev_priv->info->gen < 5);
assert_fdi_tx_enabled(dev_priv, cpu_transcoder);
assert_fdi_rx_enabled(dev_priv, TRANSCODER_A);
val = I915_READ(_TRANSA_CHICKEN2);
val |= TRANS_CHICKEN2_TIMING_OVERRIDE;
I915_WRITE(_TRANSA_CHICKEN2, val);
val = TRANS_ENABLE;
pipeconf_val = I915_READ(PIPECONF(cpu_transcoder));
if ((pipeconf_val & PIPECONF_INTERLACE_MASK_HSW) ==
PIPECONF_INTERLACED_ILK)
val |= TRANS_INTERLACED;
else
val |= TRANS_PROGRESSIVE;
I915_WRITE(TRANSCONF(TRANSCODER_A), val);
if (wait_for(I915_READ(_TRANSACONF) & TRANS_STATE_ENABLE, 100))
DRM_ERROR("Failed to enable PCH transcoder\n");
}
static void ironlake_disable_pch_transcoder(struct drm_i915_private *dev_priv,
enum pipe pipe)
{
struct drm_device *dev = dev_priv->dev;
uint32_t reg, val;
assert_fdi_tx_disabled(dev_priv, pipe);
assert_fdi_rx_disabled(dev_priv, pipe);
assert_pch_ports_disabled(dev_priv, pipe);
reg = TRANSCONF(pipe);
val = I915_READ(reg);
val &= ~TRANS_ENABLE;
I915_WRITE(reg, val);
if (wait_for((I915_READ(reg) & TRANS_STATE_ENABLE) == 0, 50))
DRM_ERROR("failed to disable transcoder %d\n", pipe);
if (!HAS_PCH_IBX(dev)) {
reg = TRANS_CHICKEN2(pipe);
val = I915_READ(reg);
val &= ~TRANS_CHICKEN2_TIMING_OVERRIDE;
I915_WRITE(reg, val);
}
}
static void lpt_disable_pch_transcoder(struct drm_i915_private *dev_priv)
{
u32 val;
val = I915_READ(_TRANSACONF);
val &= ~TRANS_ENABLE;
I915_WRITE(_TRANSACONF, val);
if (wait_for((I915_READ(_TRANSACONF) & TRANS_STATE_ENABLE) == 0, 50))
DRM_ERROR("Failed to disable PCH transcoder\n");
val = I915_READ(_TRANSA_CHICKEN2);
val &= ~TRANS_CHICKEN2_TIMING_OVERRIDE;
I915_WRITE(_TRANSA_CHICKEN2, val);
}
static void intel_enable_pipe(struct drm_i915_private *dev_priv, enum pipe pipe,
bool pch_port)
{
enum transcoder cpu_transcoder = intel_pipe_to_cpu_transcoder(dev_priv,
pipe);
enum transcoder pch_transcoder;
int reg;
u32 val;
if (IS_HASWELL(dev_priv->dev))
pch_transcoder = TRANSCODER_A;
else
pch_transcoder = pipe;
if (!HAS_PCH_SPLIT(dev_priv->dev))
assert_pll_enabled(dev_priv, pipe);
else {
if (pch_port) {
assert_fdi_rx_pll_enabled(dev_priv, pch_transcoder);
assert_fdi_tx_pll_enabled(dev_priv, cpu_transcoder);
}
}
reg = PIPECONF(cpu_transcoder);
val = I915_READ(reg);
if (val & PIPECONF_ENABLE)
return;
I915_WRITE(reg, val | PIPECONF_ENABLE);
intel_wait_for_vblank(dev_priv->dev, pipe);
}
static void intel_disable_pipe(struct drm_i915_private *dev_priv,
enum pipe pipe)
{
enum transcoder cpu_transcoder = intel_pipe_to_cpu_transcoder(dev_priv,
pipe);
int reg;
u32 val;
assert_planes_disabled(dev_priv, pipe);
if (pipe == PIPE_A && (dev_priv->quirks & QUIRK_PIPEA_FORCE))
return;
reg = PIPECONF(cpu_transcoder);
val = I915_READ(reg);
if ((val & PIPECONF_ENABLE) == 0)
return;
I915_WRITE(reg, val & ~PIPECONF_ENABLE);
intel_wait_for_pipe_off(dev_priv->dev, pipe);
}
void intel_flush_display_plane(struct drm_i915_private *dev_priv,
enum plane plane)
{
if (dev_priv->info->gen >= 4)
I915_WRITE(DSPSURF(plane), I915_READ(DSPSURF(plane)));
else
I915_WRITE(DSPADDR(plane), I915_READ(DSPADDR(plane)));
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
ret = i915_gem_object_get_fence(obj);
if (ret)
goto err_unpin;
i915_gem_object_pin_fence(obj);
dev_priv->mm.interruptible = true;
return 0;
err_unpin:
i915_gem_object_unpin(obj);
err_interruptible:
dev_priv->mm.interruptible = true;
return ret;
}
void intel_unpin_fb_obj(struct drm_i915_gem_object *obj)
{
i915_gem_object_unpin_fence(obj);
i915_gem_object_unpin(obj);
}
unsigned long intel_gen4_compute_offset_xtiled(int *x, int *y,
unsigned int bpp,
unsigned int pitch)
{
int tile_rows, tiles;
tile_rows = *y / 8;
*y %= 8;
tiles = *x / (512/bpp);
*x %= 512/bpp;
return tile_rows * pitch * 8 + tiles * 4096;
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
unsigned long linear_offset;
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
switch (fb->pixel_format) {
case DRM_FORMAT_C8:
dspcntr |= DISPPLANE_8BPP;
break;
case DRM_FORMAT_XRGB1555:
case DRM_FORMAT_ARGB1555:
dspcntr |= DISPPLANE_BGRX555;
break;
case DRM_FORMAT_RGB565:
dspcntr |= DISPPLANE_BGRX565;
break;
case DRM_FORMAT_XRGB8888:
case DRM_FORMAT_ARGB8888:
dspcntr |= DISPPLANE_BGRX888;
break;
case DRM_FORMAT_XBGR8888:
case DRM_FORMAT_ABGR8888:
dspcntr |= DISPPLANE_RGBX888;
break;
case DRM_FORMAT_XRGB2101010:
case DRM_FORMAT_ARGB2101010:
dspcntr |= DISPPLANE_BGRX101010;
break;
case DRM_FORMAT_XBGR2101010:
case DRM_FORMAT_ABGR2101010:
dspcntr |= DISPPLANE_RGBX101010;
break;
default:
DRM_ERROR("Unknown pixel format 0x%08x\n", fb->pixel_format);
return -EINVAL;
}
if (INTEL_INFO(dev)->gen >= 4) {
if (obj->tiling_mode != I915_TILING_NONE)
dspcntr |= DISPPLANE_TILED;
else
dspcntr &= ~DISPPLANE_TILED;
}
I915_WRITE(reg, dspcntr);
linear_offset = y * fb->pitches[0] + x * (fb->bits_per_pixel / 8);
if (INTEL_INFO(dev)->gen >= 4) {
intel_crtc->dspaddr_offset =
intel_gen4_compute_offset_xtiled(&x, &y,
fb->bits_per_pixel / 8,
fb->pitches[0]);
linear_offset -= intel_crtc->dspaddr_offset;
} else {
intel_crtc->dspaddr_offset = linear_offset;
}
DRM_DEBUG_KMS("Writing base %08X %08lX %d %d %d\n",
obj->gtt_offset, linear_offset, x, y, fb->pitches[0]);
I915_WRITE(DSPSTRIDE(plane), fb->pitches[0]);
if (INTEL_INFO(dev)->gen >= 4) {
I915_MODIFY_DISPBASE(DSPSURF(plane),
obj->gtt_offset + intel_crtc->dspaddr_offset);
I915_WRITE(DSPTILEOFF(plane), (y << 16) | x);
I915_WRITE(DSPLINOFF(plane), linear_offset);
} else
I915_WRITE(DSPADDR(plane), obj->gtt_offset + linear_offset);
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
unsigned long linear_offset;
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
switch (fb->pixel_format) {
case DRM_FORMAT_C8:
dspcntr |= DISPPLANE_8BPP;
break;
case DRM_FORMAT_RGB565:
dspcntr |= DISPPLANE_BGRX565;
break;
case DRM_FORMAT_XRGB8888:
case DRM_FORMAT_ARGB8888:
dspcntr |= DISPPLANE_BGRX888;
break;
case DRM_FORMAT_XBGR8888:
case DRM_FORMAT_ABGR8888:
dspcntr |= DISPPLANE_RGBX888;
break;
case DRM_FORMAT_XRGB2101010:
case DRM_FORMAT_ARGB2101010:
dspcntr |= DISPPLANE_BGRX101010;
break;
case DRM_FORMAT_XBGR2101010:
case DRM_FORMAT_ABGR2101010:
dspcntr |= DISPPLANE_RGBX101010;
break;
default:
DRM_ERROR("Unknown pixel format 0x%08x\n", fb->pixel_format);
return -EINVAL;
}
if (obj->tiling_mode != I915_TILING_NONE)
dspcntr |= DISPPLANE_TILED;
else
dspcntr &= ~DISPPLANE_TILED;
dspcntr |= DISPPLANE_TRICKLE_FEED_DISABLE;
I915_WRITE(reg, dspcntr);
linear_offset = y * fb->pitches[0] + x * (fb->bits_per_pixel / 8);
intel_crtc->dspaddr_offset =
intel_gen4_compute_offset_xtiled(&x, &y,
fb->bits_per_pixel / 8,
fb->pitches[0]);
linear_offset -= intel_crtc->dspaddr_offset;
DRM_DEBUG_KMS("Writing base %08X %08lX %d %d %d\n",
obj->gtt_offset, linear_offset, x, y, fb->pitches[0]);
I915_WRITE(DSPSTRIDE(plane), fb->pitches[0]);
I915_MODIFY_DISPBASE(DSPSURF(plane),
obj->gtt_offset + intel_crtc->dspaddr_offset);
if (IS_HASWELL(dev)) {
I915_WRITE(DSPOFFSET(plane), (y << 16) | x);
} else {
I915_WRITE(DSPTILEOFF(plane), (y << 16) | x);
I915_WRITE(DSPLINOFF(plane), linear_offset);
}
POSTING_READ(reg);
return 0;
}
static int
intel_pipe_set_base_atomic(struct drm_crtc *crtc, struct drm_framebuffer *fb,
int x, int y, enum mode_set_atomic state)
{
struct drm_device *dev = crtc->dev;
struct drm_i915_private *dev_priv = dev->dev_private;
if (dev_priv->display.disable_fbc)
dev_priv->display.disable_fbc(dev);
intel_increase_pllclock(crtc);
return dev_priv->display.update_plane(crtc, fb, x, y);
}
static int
intel_finish_fb(struct drm_framebuffer *old_fb)
{
struct drm_i915_gem_object *obj = to_intel_framebuffer(old_fb)->obj;
struct drm_i915_private *dev_priv = obj->base.dev->dev_private;
bool was_interruptible = dev_priv->mm.interruptible;
int ret;
wait_event(dev_priv->pending_flip_queue,
atomic_read(&dev_priv->mm.wedged) ||
atomic_read(&obj->pending_flip) == 0);
dev_priv->mm.interruptible = false;
ret = i915_gem_object_finish_gpu(obj);
dev_priv->mm.interruptible = was_interruptible;
return ret;
}
static void intel_crtc_update_sarea_pos(struct drm_crtc *crtc, int x, int y)
{
struct drm_device *dev = crtc->dev;
struct drm_i915_master_private *master_priv;
struct intel_crtc *intel_crtc = to_intel_crtc(crtc);
if (!dev->primary->master)
return;
master_priv = dev->primary->master->driver_priv;
if (!master_priv->sarea_priv)
return;
switch (intel_crtc->pipe) {
case 0:
master_priv->sarea_priv->pipeA_x = x;
master_priv->sarea_priv->pipeA_y = y;
break;
case 1:
master_priv->sarea_priv->pipeB_x = x;
master_priv->sarea_priv->pipeB_y = y;
break;
default:
break;
}
}
static int
intel_pipe_set_base(struct drm_crtc *crtc, int x, int y,
struct drm_framebuffer *fb)
{
struct drm_device *dev = crtc->dev;
struct drm_i915_private *dev_priv = dev->dev_private;
struct intel_crtc *intel_crtc = to_intel_crtc(crtc);
struct drm_framebuffer *old_fb;
int ret;
if (!fb) {
DRM_ERROR("No FB bound\n");
return 0;
}
if(intel_crtc->plane > dev_priv->num_pipe) {
DRM_ERROR("no plane for crtc: plane %d, num_pipes %d\n",
intel_crtc->plane,
dev_priv->num_pipe);
return -EINVAL;
}
mutex_lock(&dev->struct_mutex);
ret = intel_pin_and_fence_fb_obj(dev,
to_intel_framebuffer(fb)->obj,
NULL);
if (ret != 0) {
mutex_unlock(&dev->struct_mutex);
DRM_ERROR("pin & fence failed\n");
return ret;
}
if (crtc->fb)
intel_finish_fb(crtc->fb);
ret = dev_priv->display.update_plane(crtc, fb, x, y);
if (ret) {
intel_unpin_fb_obj(to_intel_framebuffer(fb)->obj);
mutex_unlock(&dev->struct_mutex);
DRM_ERROR("failed to update base address\n");
return ret;
}
old_fb = crtc->fb;
crtc->fb = fb;
crtc->x = x;
crtc->y = y;
if (old_fb) {
intel_wait_for_vblank(dev, intel_crtc->pipe);
intel_unpin_fb_obj(to_intel_framebuffer(old_fb)->obj);
}
intel_update_fbc(dev);
mutex_unlock(&dev->struct_mutex);
intel_crtc_update_sarea_pos(crtc, x, y);
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
static void ivb_modeset_global_resources(struct drm_device *dev)
{
struct drm_i915_private *dev_priv = dev->dev_private;
struct intel_crtc *pipe_B_crtc =
to_intel_crtc(dev_priv->pipe_to_crtc_mapping[PIPE_B]);
struct intel_crtc *pipe_C_crtc =
to_intel_crtc(dev_priv->pipe_to_crtc_mapping[PIPE_C]);
uint32_t temp;
if (!pipe_B_crtc->base.enabled && !pipe_C_crtc->base.enabled) {
WARN_ON(I915_READ(FDI_RX_CTL(PIPE_B)) & FDI_RX_ENABLE);
WARN_ON(I915_READ(FDI_RX_CTL(PIPE_C)) & FDI_RX_ENABLE);
temp = I915_READ(SOUTH_CHICKEN1);
temp &= ~FDI_BC_BIFURCATION_SELECT;
DRM_DEBUG_KMS("disabling fdi C rx\n");
I915_WRITE(SOUTH_CHICKEN1, temp);
}
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
I915_WRITE(FDI_RX_CHICKEN(pipe), FDI_RX_PHASE_SYNC_POINTER_OVR);
I915_WRITE(FDI_RX_CHICKEN(pipe), FDI_RX_PHASE_SYNC_POINTER_OVR |
FDI_RX_PHASE_SYNC_POINTER_EN);
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
u32 reg, temp, i, retry;
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
I915_WRITE(FDI_RX_MISC(pipe),
FDI_RX_TP1_TO_TP2_48 | FDI_RX_FDI_DELAY_90);
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
for (i = 0; i < 4; i++) {
reg = FDI_TX_CTL(pipe);
temp = I915_READ(reg);
temp &= ~FDI_LINK_TRAIN_VOL_EMP_MASK;
temp |= snb_b_fdi_train_param[i];
I915_WRITE(reg, temp);
POSTING_READ(reg);
udelay(500);
for (retry = 0; retry < 5; retry++) {
reg = FDI_RX_IIR(pipe);
temp = I915_READ(reg);
DRM_DEBUG_KMS("FDI_RX_IIR 0x%x\n", temp);
if (temp & FDI_RX_BIT_LOCK) {
I915_WRITE(reg, temp | FDI_RX_BIT_LOCK);
DRM_DEBUG_KMS("FDI train 1 done.\n");
break;
}
udelay(50);
}
if (retry < 5)
break;
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
for (retry = 0; retry < 5; retry++) {
reg = FDI_RX_IIR(pipe);
temp = I915_READ(reg);
DRM_DEBUG_KMS("FDI_RX_IIR 0x%x\n", temp);
if (temp & FDI_RX_SYMBOL_LOCK) {
I915_WRITE(reg, temp | FDI_RX_SYMBOL_LOCK);
DRM_DEBUG_KMS("FDI train 2 done.\n");
break;
}
udelay(50);
}
if (retry < 5)
break;
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
DRM_DEBUG_KMS("FDI_RX_IIR before link train 0x%x\n",
I915_READ(FDI_RX_IIR(pipe)));
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
I915_WRITE(FDI_RX_MISC(pipe),
FDI_RX_TP1_TO_TP2_48 | FDI_RX_FDI_DELAY_90);
reg = FDI_RX_CTL(pipe);
temp = I915_READ(reg);
temp &= ~FDI_LINK_TRAIN_AUTO;
temp &= ~FDI_LINK_TRAIN_PATTERN_MASK_CPT;
temp |= FDI_LINK_TRAIN_PATTERN_1_CPT;
temp |= FDI_COMPOSITE_SYNC;
I915_WRITE(reg, temp | FDI_RX_ENABLE);
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
if (temp & FDI_RX_BIT_LOCK ||
(I915_READ(reg) & FDI_RX_BIT_LOCK)) {
I915_WRITE(reg, temp | FDI_RX_BIT_LOCK);
DRM_DEBUG_KMS("FDI train 1 done, level %i.\n", i);
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
DRM_DEBUG_KMS("FDI train 2 done, level %i.\n", i);
break;
}
}
if (i == 4)
DRM_ERROR("FDI train 2 fail!\n");
DRM_DEBUG_KMS("FDI train done.\n");
}
static void ironlake_fdi_pll_enable(struct intel_crtc *intel_crtc)
{
struct drm_device *dev = intel_crtc->base.dev;
struct drm_i915_private *dev_priv = dev->dev_private;
int pipe = intel_crtc->pipe;
u32 reg, temp;
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
if (!IS_HASWELL(dev)) {
reg = FDI_TX_CTL(pipe);
temp = I915_READ(reg);
if ((temp & FDI_TX_PLL_ENABLE) == 0) {
I915_WRITE(reg, temp | FDI_TX_PLL_ENABLE);
POSTING_READ(reg);
udelay(100);
}
}
}
static void ironlake_fdi_pll_disable(struct intel_crtc *intel_crtc)
{
struct drm_device *dev = intel_crtc->base.dev;
struct drm_i915_private *dev_priv = dev->dev_private;
int pipe = intel_crtc->pipe;
u32 reg, temp;
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
static bool intel_crtc_has_pending_flip(struct drm_crtc *crtc)
{
struct drm_device *dev = crtc->dev;
struct drm_i915_private *dev_priv = dev->dev_private;
unsigned long flags;
bool pending;
if (atomic_read(&dev_priv->mm.wedged))
return false;
spin_lock_irqsave(&dev->event_lock, flags);
pending = to_intel_crtc(crtc)->unpin_work != NULL;
spin_unlock_irqrestore(&dev->event_lock, flags);
return pending;
}
static void intel_crtc_wait_for_pending_flips(struct drm_crtc *crtc)
{
struct drm_device *dev = crtc->dev;
struct drm_i915_private *dev_priv = dev->dev_private;
if (crtc->fb == NULL)
return;
wait_event(dev_priv->pending_flip_queue,
!intel_crtc_has_pending_flip(crtc));
mutex_lock(&dev->struct_mutex);
intel_finish_fb(crtc->fb);
mutex_unlock(&dev->struct_mutex);
}
static bool ironlake_crtc_driving_pch(struct drm_crtc *crtc)
{
struct drm_device *dev = crtc->dev;
struct intel_encoder *intel_encoder;
for_each_encoder_on_crtc(dev, crtc, intel_encoder) {
switch (intel_encoder->type) {
case INTEL_OUTPUT_EDP:
if (!intel_encoder_is_pch_edp(&intel_encoder->base))
return false;
continue;
}
}
return true;
}
static bool haswell_crtc_driving_pch(struct drm_crtc *crtc)
{
return intel_pipe_has_type(crtc, INTEL_OUTPUT_ANALOG);
}
static void lpt_program_iclkip(struct drm_crtc *crtc)
{
struct drm_device *dev = crtc->dev;
struct drm_i915_private *dev_priv = dev->dev_private;
u32 divsel, phaseinc, auxdiv, phasedir = 0;
u32 temp;
I915_WRITE(PIXCLK_GATE, PIXCLK_GATE_GATE);
intel_sbi_write(dev_priv, SBI_SSCCTL6,
intel_sbi_read(dev_priv, SBI_SSCCTL6, SBI_ICLK) |
SBI_SSCCTL_DISABLE,
SBI_ICLK);
if (crtc->mode.clock == 20000) {
auxdiv = 1;
divsel = 0x41;
phaseinc = 0x20;
} else {
u32 iclk_virtual_root_freq = 172800 * 1000;
u32 iclk_pi_range = 64;
u32 desired_divisor, msb_divisor_value, pi_value;
desired_divisor = (iclk_virtual_root_freq / crtc->mode.clock);
msb_divisor_value = desired_divisor / iclk_pi_range;
pi_value = desired_divisor % iclk_pi_range;
auxdiv = 0;
divsel = msb_divisor_value - 2;
phaseinc = pi_value;
}
WARN_ON(SBI_SSCDIVINTPHASE_DIVSEL(divsel) &
~SBI_SSCDIVINTPHASE_DIVSEL_MASK);
WARN_ON(SBI_SSCDIVINTPHASE_DIR(phasedir) &
~SBI_SSCDIVINTPHASE_INCVAL_MASK);
DRM_DEBUG_KMS("iCLKIP clock: found settings for %dKHz refresh rate: auxdiv=%x, divsel=%x, phasedir=%x, phaseinc=%x\n",
crtc->mode.clock,
auxdiv,
divsel,
phasedir,
phaseinc);
temp = intel_sbi_read(dev_priv, SBI_SSCDIVINTPHASE6, SBI_ICLK);
temp &= ~SBI_SSCDIVINTPHASE_DIVSEL_MASK;
temp |= SBI_SSCDIVINTPHASE_DIVSEL(divsel);
temp &= ~SBI_SSCDIVINTPHASE_INCVAL_MASK;
temp |= SBI_SSCDIVINTPHASE_INCVAL(phaseinc);
temp |= SBI_SSCDIVINTPHASE_DIR(phasedir);
temp |= SBI_SSCDIVINTPHASE_PROPAGATE;
intel_sbi_write(dev_priv, SBI_SSCDIVINTPHASE6, temp, SBI_ICLK);
temp = intel_sbi_read(dev_priv, SBI_SSCAUXDIV6, SBI_ICLK);
temp &= ~SBI_SSCAUXDIV_FINALDIV2SEL(1);
temp |= SBI_SSCAUXDIV_FINALDIV2SEL(auxdiv);
intel_sbi_write(dev_priv, SBI_SSCAUXDIV6, temp, SBI_ICLK);
temp = intel_sbi_read(dev_priv, SBI_SSCCTL6, SBI_ICLK);
temp &= ~SBI_SSCCTL_DISABLE;
intel_sbi_write(dev_priv, SBI_SSCCTL6, temp, SBI_ICLK);
udelay(24);
I915_WRITE(PIXCLK_GATE, PIXCLK_GATE_UNGATE);
}
static void ironlake_pch_enable(struct drm_crtc *crtc)
{
struct drm_device *dev = crtc->dev;
struct drm_i915_private *dev_priv = dev->dev_private;
struct intel_crtc *intel_crtc = to_intel_crtc(crtc);
int pipe = intel_crtc->pipe;
u32 reg, temp;
assert_transcoder_disabled(dev_priv, pipe);
I915_WRITE(FDI_RX_TUSIZE1(pipe),
I915_READ(PIPE_DATA_M1(pipe)) & TU_SIZE_MASK);
dev_priv->display.fdi_link_train(crtc);
ironlake_enable_pch_pll(intel_crtc);
if (HAS_PCH_CPT(dev)) {
u32 sel;
temp = I915_READ(PCH_DPLL_SEL);
switch (pipe) {
default:
case 0:
temp |= TRANSA_DPLL_ENABLE;
sel = TRANSA_DPLLB_SEL;
break;
case 1:
temp |= TRANSB_DPLL_ENABLE;
sel = TRANSB_DPLLB_SEL;
break;
case 2:
temp |= TRANSC_DPLL_ENABLE;
sel = TRANSC_DPLLB_SEL;
break;
}
if (intel_crtc->pch_pll->pll_reg == _PCH_DPLL_B)
temp |= sel;
else
temp &= ~sel;
I915_WRITE(PCH_DPLL_SEL, temp);
}
assert_panel_unlocked(dev_priv, pipe);
I915_WRITE(TRANS_HTOTAL(pipe), I915_READ(HTOTAL(pipe)));
I915_WRITE(TRANS_HBLANK(pipe), I915_READ(HBLANK(pipe)));
I915_WRITE(TRANS_HSYNC(pipe), I915_READ(HSYNC(pipe)));
I915_WRITE(TRANS_VTOTAL(pipe), I915_READ(VTOTAL(pipe)));
I915_WRITE(TRANS_VBLANK(pipe), I915_READ(VBLANK(pipe)));
I915_WRITE(TRANS_VSYNC(pipe), I915_READ(VSYNC(pipe)));
I915_WRITE(TRANS_VSYNCSHIFT(pipe), I915_READ(VSYNCSHIFT(pipe)));
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
BUG();
}
I915_WRITE(reg, temp);
}
ironlake_enable_pch_transcoder(dev_priv, pipe);
}
static void lpt_pch_enable(struct drm_crtc *crtc)
{
struct drm_device *dev = crtc->dev;
struct drm_i915_private *dev_priv = dev->dev_private;
struct intel_crtc *intel_crtc = to_intel_crtc(crtc);
enum transcoder cpu_transcoder = intel_crtc->cpu_transcoder;
assert_transcoder_disabled(dev_priv, TRANSCODER_A);
lpt_program_iclkip(crtc);
I915_WRITE(_TRANS_HTOTAL_A, I915_READ(HTOTAL(cpu_transcoder)));
I915_WRITE(_TRANS_HBLANK_A, I915_READ(HBLANK(cpu_transcoder)));
I915_WRITE(_TRANS_HSYNC_A, I915_READ(HSYNC(cpu_transcoder)));
I915_WRITE(_TRANS_VTOTAL_A, I915_READ(VTOTAL(cpu_transcoder)));
I915_WRITE(_TRANS_VBLANK_A, I915_READ(VBLANK(cpu_transcoder)));
I915_WRITE(_TRANS_VSYNC_A, I915_READ(VSYNC(cpu_transcoder)));
I915_WRITE(_TRANS_VSYNCSHIFT_A, I915_READ(VSYNCSHIFT(cpu_transcoder)));
lpt_enable_pch_transcoder(dev_priv, cpu_transcoder);
}
static void intel_put_pch_pll(struct intel_crtc *intel_crtc)
{
struct intel_pch_pll *pll = intel_crtc->pch_pll;
if (pll == NULL)
return;
if (pll->refcount == 0) {
WARN(1, "bad PCH PLL refcount\n");
return;
}
--pll->refcount;
intel_crtc->pch_pll = NULL;
}
static struct intel_pch_pll *intel_get_pch_pll(struct intel_crtc *intel_crtc, u32 dpll, u32 fp)
{
struct drm_i915_private *dev_priv = intel_crtc->base.dev->dev_private;
struct intel_pch_pll *pll;
int i;
pll = intel_crtc->pch_pll;
if (pll) {
DRM_DEBUG_KMS("CRTC:%d reusing existing PCH PLL %x\n",
intel_crtc->base.base.id, pll->pll_reg);
goto prepare;
}
if (HAS_PCH_IBX(dev_priv->dev)) {
i = intel_crtc->pipe;
pll = &dev_priv->pch_plls[i];
DRM_DEBUG_KMS("CRTC:%d using pre-allocated PCH PLL %x\n",
intel_crtc->base.base.id, pll->pll_reg);
goto found;
}
for (i = 0; i < dev_priv->num_pch_pll; i++) {
pll = &dev_priv->pch_plls[i];
if (pll->refcount == 0)
continue;
if (dpll == (I915_READ(pll->pll_reg) & 0x7fffffff) &&
fp == I915_READ(pll->fp0_reg)) {
DRM_DEBUG_KMS("CRTC:%d sharing existing PCH PLL %x (refcount %d, ative %d)\n",
intel_crtc->base.base.id,
pll->pll_reg, pll->refcount, pll->active);
goto found;
}
}
for (i = 0; i < dev_priv->num_pch_pll; i++) {
pll = &dev_priv->pch_plls[i];
if (pll->refcount == 0) {
DRM_DEBUG_KMS("CRTC:%d allocated PCH PLL %x\n",
intel_crtc->base.base.id, pll->pll_reg);
goto found;
}
}
return NULL;
found:
intel_crtc->pch_pll = pll;
pll->refcount++;
DRM_DEBUG_DRIVER("using pll %d for pipe %d\n", i, intel_crtc->pipe);
prepare:
DRM_DEBUG_DRIVER("switching PLL %x off\n", pll->pll_reg);
I915_WRITE(pll->pll_reg, dpll & ~DPLL_VCO_ENABLE);
POSTING_READ(pll->pll_reg);
udelay(150);
I915_WRITE(pll->fp0_reg, fp);
I915_WRITE(pll->pll_reg, dpll & ~DPLL_VCO_ENABLE);
pll->on = false;
return pll;
}
void intel_cpt_verify_modeset(struct drm_device *dev, int pipe)
{
struct drm_i915_private *dev_priv = dev->dev_private;
int dslreg = PIPEDSL(pipe);
u32 temp;
temp = I915_READ(dslreg);
udelay(500);
if (wait_for(I915_READ(dslreg) != temp, 5)) {
if (wait_for(I915_READ(dslreg) != temp, 5))
DRM_ERROR("mode set failed: pipe %d stuck\n", pipe);
}
}
static void ironlake_crtc_enable(struct drm_crtc *crtc)
{
struct drm_device *dev = crtc->dev;
struct drm_i915_private *dev_priv = dev->dev_private;
struct intel_crtc *intel_crtc = to_intel_crtc(crtc);
struct intel_encoder *encoder;
int pipe = intel_crtc->pipe;
int plane = intel_crtc->plane;
u32 temp;
bool is_pch_port;
WARN_ON(!crtc->enabled);
if (intel_crtc->active)
return;
intel_crtc->active = true;
intel_update_watermarks(dev);
if (intel_pipe_has_type(crtc, INTEL_OUTPUT_LVDS)) {
temp = I915_READ(PCH_LVDS);
if ((temp & LVDS_PORT_EN) == 0)
I915_WRITE(PCH_LVDS, temp | LVDS_PORT_EN);
}
is_pch_port = ironlake_crtc_driving_pch(crtc);
if (is_pch_port) {
ironlake_fdi_pll_enable(intel_crtc);
} else {
assert_fdi_tx_disabled(dev_priv, pipe);
assert_fdi_rx_disabled(dev_priv, pipe);
}
for_each_encoder_on_crtc(dev, crtc, encoder)
if (encoder->pre_enable)
encoder->pre_enable(encoder);
if (dev_priv->pch_pf_size &&
(intel_pipe_has_type(crtc, INTEL_OUTPUT_LVDS) ||
intel_pipe_has_type(crtc, INTEL_OUTPUT_EDP))) {
if (IS_IVYBRIDGE(dev))
I915_WRITE(PF_CTL(pipe), PF_ENABLE | PF_FILTER_MED_3x3 |
PF_PIPE_SEL_IVB(pipe));
else
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
for_each_encoder_on_crtc(dev, crtc, encoder)
encoder->enable(encoder);
if (HAS_PCH_CPT(dev))
intel_cpt_verify_modeset(dev, intel_crtc->pipe);
intel_wait_for_vblank(dev, intel_crtc->pipe);
}
static void haswell_crtc_enable(struct drm_crtc *crtc)
{
struct drm_device *dev = crtc->dev;
struct drm_i915_private *dev_priv = dev->dev_private;
struct intel_crtc *intel_crtc = to_intel_crtc(crtc);
struct intel_encoder *encoder;
int pipe = intel_crtc->pipe;
int plane = intel_crtc->plane;
bool is_pch_port;
WARN_ON(!crtc->enabled);
if (intel_crtc->active)
return;
intel_crtc->active = true;
intel_update_watermarks(dev);
is_pch_port = haswell_crtc_driving_pch(crtc);
if (is_pch_port)
dev_priv->display.fdi_link_train(crtc);
for_each_encoder_on_crtc(dev, crtc, encoder)
if (encoder->pre_enable)
encoder->pre_enable(encoder);
intel_ddi_enable_pipe_clock(intel_crtc);
if (dev_priv->pch_pf_size &&
intel_pipe_has_type(crtc, INTEL_OUTPUT_EDP)) {
I915_WRITE(PF_CTL(pipe), PF_ENABLE | PF_FILTER_MED_3x3 |
PF_PIPE_SEL_IVB(pipe));
I915_WRITE(PF_WIN_POS(pipe), dev_priv->pch_pf_pos);
I915_WRITE(PF_WIN_SZ(pipe), dev_priv->pch_pf_size);
}
intel_crtc_load_lut(crtc);
intel_ddi_set_pipe_settings(crtc);
intel_ddi_enable_pipe_func(crtc);
intel_enable_pipe(dev_priv, pipe, is_pch_port);
intel_enable_plane(dev_priv, plane, pipe);
if (is_pch_port)
lpt_pch_enable(crtc);
mutex_lock(&dev->struct_mutex);
intel_update_fbc(dev);
mutex_unlock(&dev->struct_mutex);
intel_crtc_update_cursor(crtc, true);
for_each_encoder_on_crtc(dev, crtc, encoder)
encoder->enable(encoder);
intel_wait_for_vblank(dev, intel_crtc->pipe);
}
static void ironlake_crtc_disable(struct drm_crtc *crtc)
{
struct drm_device *dev = crtc->dev;
struct drm_i915_private *dev_priv = dev->dev_private;
struct intel_crtc *intel_crtc = to_intel_crtc(crtc);
struct intel_encoder *encoder;
int pipe = intel_crtc->pipe;
int plane = intel_crtc->plane;
u32 reg, temp;
if (!intel_crtc->active)
return;
for_each_encoder_on_crtc(dev, crtc, encoder)
encoder->disable(encoder);
intel_crtc_wait_for_pending_flips(crtc);
drm_vblank_off(dev, pipe);
intel_crtc_update_cursor(crtc, false);
intel_disable_plane(dev_priv, plane, pipe);
if (dev_priv->cfb_plane == plane)
intel_disable_fbc(dev);
intel_disable_pipe(dev_priv, pipe);
I915_WRITE(PF_CTL(pipe), 0);
I915_WRITE(PF_WIN_SZ(pipe), 0);
for_each_encoder_on_crtc(dev, crtc, encoder)
if (encoder->post_disable)
encoder->post_disable(encoder);
ironlake_fdi_disable(crtc);
ironlake_disable_pch_transcoder(dev_priv, pipe);
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
intel_disable_pch_pll(intel_crtc);
ironlake_fdi_pll_disable(intel_crtc);
intel_crtc->active = false;
intel_update_watermarks(dev);
mutex_lock(&dev->struct_mutex);
intel_update_fbc(dev);
mutex_unlock(&dev->struct_mutex);
}
static void haswell_crtc_disable(struct drm_crtc *crtc)
{
struct drm_device *dev = crtc->dev;
struct drm_i915_private *dev_priv = dev->dev_private;
struct intel_crtc *intel_crtc = to_intel_crtc(crtc);
struct intel_encoder *encoder;
int pipe = intel_crtc->pipe;
int plane = intel_crtc->plane;
enum transcoder cpu_transcoder = intel_crtc->cpu_transcoder;
bool is_pch_port;
if (!intel_crtc->active)
return;
is_pch_port = haswell_crtc_driving_pch(crtc);
for_each_encoder_on_crtc(dev, crtc, encoder)
encoder->disable(encoder);
intel_crtc_wait_for_pending_flips(crtc);
drm_vblank_off(dev, pipe);
intel_crtc_update_cursor(crtc, false);
intel_disable_plane(dev_priv, plane, pipe);
if (dev_priv->cfb_plane == plane)
intel_disable_fbc(dev);
intel_disable_pipe(dev_priv, pipe);
intel_ddi_disable_transcoder_func(dev_priv, cpu_transcoder);
I915_WRITE(PF_CTL(pipe), 0);
I915_WRITE(PF_WIN_SZ(pipe), 0);
intel_ddi_disable_pipe_clock(intel_crtc);
for_each_encoder_on_crtc(dev, crtc, encoder)
if (encoder->post_disable)
encoder->post_disable(encoder);
if (is_pch_port) {
lpt_disable_pch_transcoder(dev_priv);
intel_ddi_fdi_disable(crtc);
}
intel_crtc->active = false;
intel_update_watermarks(dev);
mutex_lock(&dev->struct_mutex);
intel_update_fbc(dev);
mutex_unlock(&dev->struct_mutex);
}
static void ironlake_crtc_off(struct drm_crtc *crtc)
{
struct intel_crtc *intel_crtc = to_intel_crtc(crtc);
intel_put_pch_pll(intel_crtc);
}
static void haswell_crtc_off(struct drm_crtc *crtc)
{
struct intel_crtc *intel_crtc = to_intel_crtc(crtc);
intel_crtc->cpu_transcoder = intel_crtc->pipe;
intel_ddi_put_crtc_pll(crtc);
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
struct intel_encoder *encoder;
int pipe = intel_crtc->pipe;
int plane = intel_crtc->plane;
WARN_ON(!crtc->enabled);
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
for_each_encoder_on_crtc(dev, crtc, encoder)
encoder->enable(encoder);
}
static void i9xx_crtc_disable(struct drm_crtc *crtc)
{
struct drm_device *dev = crtc->dev;
struct drm_i915_private *dev_priv = dev->dev_private;
struct intel_crtc *intel_crtc = to_intel_crtc(crtc);
struct intel_encoder *encoder;
int pipe = intel_crtc->pipe;
int plane = intel_crtc->plane;
if (!intel_crtc->active)
return;
for_each_encoder_on_crtc(dev, crtc, encoder)
encoder->disable(encoder);
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
}
static void i9xx_crtc_off(struct drm_crtc *crtc)
{
}
static void intel_crtc_update_sarea(struct drm_crtc *crtc,
bool enabled)
{
struct drm_device *dev = crtc->dev;
struct drm_i915_master_private *master_priv;
struct intel_crtc *intel_crtc = to_intel_crtc(crtc);
int pipe = intel_crtc->pipe;
if (!dev->primary->master)
return;
master_priv = dev->primary->master->driver_priv;
if (!master_priv->sarea_priv)
return;
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
void intel_crtc_update_dpms(struct drm_crtc *crtc)
{
struct drm_device *dev = crtc->dev;
struct drm_i915_private *dev_priv = dev->dev_private;
struct intel_encoder *intel_encoder;
bool enable = false;
for_each_encoder_on_crtc(dev, crtc, intel_encoder)
enable |= intel_encoder->connectors_active;
if (enable)
dev_priv->display.crtc_enable(crtc);
else
dev_priv->display.crtc_disable(crtc);
intel_crtc_update_sarea(crtc, enable);
}
static void intel_crtc_noop(struct drm_crtc *crtc)
{
}
static void intel_crtc_disable(struct drm_crtc *crtc)
{
struct drm_device *dev = crtc->dev;
struct drm_connector *connector;
struct drm_i915_private *dev_priv = dev->dev_private;
WARN_ON(!crtc->enabled);
dev_priv->display.crtc_disable(crtc);
intel_crtc_update_sarea(crtc, false);
dev_priv->display.off(crtc);
assert_plane_disabled(dev->dev_private, to_intel_crtc(crtc)->plane);
assert_pipe_disabled(dev->dev_private, to_intel_crtc(crtc)->pipe);
if (crtc->fb) {
mutex_lock(&dev->struct_mutex);
intel_unpin_fb_obj(to_intel_framebuffer(crtc->fb)->obj);
mutex_unlock(&dev->struct_mutex);
crtc->fb = NULL;
}
list_for_each_entry(connector, &dev->mode_config.connector_list, head) {
if (!connector->encoder || !connector->encoder->crtc)
continue;
if (connector->encoder->crtc != crtc)
continue;
connector->dpms = DRM_MODE_DPMS_OFF;
to_intel_encoder(connector->encoder)->connectors_active = false;
}
}
void intel_modeset_disable(struct drm_device *dev)
{
struct drm_crtc *crtc;
list_for_each_entry(crtc, &dev->mode_config.crtc_list, head) {
if (crtc->enabled)
intel_crtc_disable(crtc);
}
}
void intel_encoder_noop(struct drm_encoder *encoder)
{
}
void intel_encoder_destroy(struct drm_encoder *encoder)
{
struct intel_encoder *intel_encoder = to_intel_encoder(encoder);
drm_encoder_cleanup(encoder);
kfree(intel_encoder);
}
void intel_encoder_dpms(struct intel_encoder *encoder, int mode)
{
if (mode == DRM_MODE_DPMS_ON) {
encoder->connectors_active = true;
intel_crtc_update_dpms(encoder->base.crtc);
} else {
encoder->connectors_active = false;
intel_crtc_update_dpms(encoder->base.crtc);
}
}
static void intel_connector_check_state(struct intel_connector *connector)
{
if (connector->get_hw_state(connector)) {
struct intel_encoder *encoder = connector->encoder;
struct drm_crtc *crtc;
bool encoder_enabled;
enum pipe pipe;
DRM_DEBUG_KMS("[CONNECTOR:%d:%s]\n",
connector->base.base.id,
drm_get_connector_name(&connector->base));
WARN(connector->base.dpms == DRM_MODE_DPMS_OFF,
"wrong connector dpms state\n");
WARN(connector->base.encoder != &encoder->base,
"active connector not linked to encoder\n");
WARN(!encoder->connectors_active,
"encoder->connectors_active not set\n");
encoder_enabled = encoder->get_hw_state(encoder, &pipe);
WARN(!encoder_enabled, "encoder not enabled\n");
if (WARN_ON(!encoder->base.crtc))
return;
crtc = encoder->base.crtc;
WARN(!crtc->enabled, "crtc not enabled\n");
WARN(!to_intel_crtc(crtc)->active, "crtc not active\n");
WARN(pipe != to_intel_crtc(crtc)->pipe,
"encoder active on the wrong pipe\n");
}
}
void intel_connector_dpms(struct drm_connector *connector, int mode)
{
struct intel_encoder *encoder = intel_attached_encoder(connector);
if (mode != DRM_MODE_DPMS_ON)
mode = DRM_MODE_DPMS_OFF;
if (mode == connector->dpms)
return;
connector->dpms = mode;
if (encoder->base.crtc)
intel_encoder_dpms(encoder, mode);
else
WARN_ON(encoder->connectors_active != false);
intel_modeset_check_state(connector->dev);
}
bool intel_connector_get_hw_state(struct intel_connector *connector)
{
enum pipe pipe = 0;
struct intel_encoder *encoder = connector->encoder;
return encoder->get_hw_state(encoder, &pipe);
}
static bool intel_crtc_mode_fixup(struct drm_crtc *crtc,
const struct drm_display_mode *mode,
struct drm_display_mode *adjusted_mode)
{
struct drm_device *dev = crtc->dev;
if (HAS_PCH_SPLIT(dev)) {
if (mode->clock * 3 > IRONLAKE_FDI_FREQ * 4)
return false;
}
if (!(adjusted_mode->private_flags & INTEL_MODE_CRTC_TIMINGS_SET))
drm_mode_set_crtcinfo(adjusted_mode, 0);
if ((INTEL_INFO(dev)->gen > 4 || IS_G4X(dev)) &&
adjusted_mode->hsync_start == adjusted_mode->hdisplay)
return false;
return true;
}
static int valleyview_get_display_clock_speed(struct drm_device *dev)
{
return 400000;
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
static inline bool intel_panel_use_ssc(struct drm_i915_private *dev_priv)
{
if (i915_panel_use_ssc >= 0)
return i915_panel_use_ssc != 0;
return dev_priv->lvds_use_ssc
&& !(dev_priv->quirks & QUIRK_LVDS_SSC_DISABLE);
}
static bool intel_choose_pipe_bpp_dither(struct drm_crtc *crtc,
struct drm_framebuffer *fb,
unsigned int *pipe_bpp,
struct drm_display_mode *mode)
{
struct drm_device *dev = crtc->dev;
struct drm_i915_private *dev_priv = dev->dev_private;
struct drm_connector *connector;
struct intel_encoder *intel_encoder;
unsigned int display_bpc = UINT_MAX, bpc;
for_each_encoder_on_crtc(dev, crtc, intel_encoder) {
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
list_for_each_entry(connector, &dev->mode_config.connector_list,
head) {
if (connector->encoder != &intel_encoder->base)
continue;
if (connector->display_info.bpc &&
connector->display_info.bpc < display_bpc) {
DRM_DEBUG_KMS("clamping display bpc (was %d) to EDID reported max of %d\n", display_bpc, connector->display_info.bpc);
display_bpc = connector->display_info.bpc;
}
}
if (intel_encoder->type == INTEL_OUTPUT_EDP) {
unsigned int edp_bpc = dev_priv->edp.bpp / 3;
if (edp_bpc && edp_bpc < display_bpc) {
DRM_DEBUG_KMS("clamping display bpc (was %d) to eDP (%d)\n", display_bpc, edp_bpc);
display_bpc = edp_bpc;
}
continue;
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
switch (fb->depth) {
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
static int vlv_get_refclk(struct drm_crtc *crtc)
{
struct drm_device *dev = crtc->dev;
struct drm_i915_private *dev_priv = dev->dev_private;
int refclk = 27000;
return 100000;
if (intel_pipe_has_type(crtc, INTEL_OUTPUT_ANALOG)) {
refclk = 96000;
} else if (intel_pipe_has_type(crtc, INTEL_OUTPUT_LVDS)) {
if (intel_panel_use_ssc(dev_priv))
refclk = 100000;
else
refclk = 96000;
} else if (intel_pipe_has_type(crtc, INTEL_OUTPUT_EDP)) {
refclk = 100000;
}
return refclk;
}
static int i9xx_get_refclk(struct drm_crtc *crtc, int num_connectors)
{
struct drm_device *dev = crtc->dev;
struct drm_i915_private *dev_priv = dev->dev_private;
int refclk;
if (IS_VALLEYVIEW(dev)) {
refclk = vlv_get_refclk(crtc);
} else if (intel_pipe_has_type(crtc, INTEL_OUTPUT_LVDS) &&
intel_panel_use_ssc(dev_priv) && num_connectors < 2) {
refclk = dev_priv->lvds_ssc_freq * 1000;
DRM_DEBUG_KMS("using SSC reference clock of %d MHz\n",
refclk / 1000);
} else if (!IS_GEN2(dev)) {
refclk = 96000;
} else {
refclk = 48000;
}
return refclk;
}
static void i9xx_adjust_sdvo_tv_clock(struct drm_display_mode *adjusted_mode,
intel_clock_t *clock)
{
if (adjusted_mode->clock >= 100000
&& adjusted_mode->clock < 140500) {
clock->p1 = 2;
clock->p2 = 10;
clock->n = 3;
clock->m1 = 16;
clock->m2 = 8;
} else if (adjusted_mode->clock >= 140500
&& adjusted_mode->clock <= 200000) {
clock->p1 = 1;
clock->p2 = 10;
clock->n = 6;
clock->m1 = 12;
clock->m2 = 8;
}
}
static void i9xx_update_pll_dividers(struct drm_crtc *crtc,
intel_clock_t *clock,
intel_clock_t *reduced_clock)
{
struct drm_device *dev = crtc->dev;
struct drm_i915_private *dev_priv = dev->dev_private;
struct intel_crtc *intel_crtc = to_intel_crtc(crtc);
int pipe = intel_crtc->pipe;
u32 fp, fp2 = 0;
if (IS_PINEVIEW(dev)) {
fp = (1 << clock->n) << 16 | clock->m1 << 8 | clock->m2;
if (reduced_clock)
fp2 = (1 << reduced_clock->n) << 16 |
reduced_clock->m1 << 8 | reduced_clock->m2;
} else {
fp = clock->n << 16 | clock->m1 << 8 | clock->m2;
if (reduced_clock)
fp2 = reduced_clock->n << 16 | reduced_clock->m1 << 8 |
reduced_clock->m2;
}
I915_WRITE(FP0(pipe), fp);
intel_crtc->lowfreq_avail = false;
if (intel_pipe_has_type(crtc, INTEL_OUTPUT_LVDS) &&
reduced_clock && i915_powersave) {
I915_WRITE(FP1(pipe), fp2);
intel_crtc->lowfreq_avail = true;
} else {
I915_WRITE(FP1(pipe), fp);
}
}
static void intel_update_lvds(struct drm_crtc *crtc, intel_clock_t *clock,
struct drm_display_mode *adjusted_mode)
{
struct drm_device *dev = crtc->dev;
struct drm_i915_private *dev_priv = dev->dev_private;
struct intel_crtc *intel_crtc = to_intel_crtc(crtc);
int pipe = intel_crtc->pipe;
u32 temp;
temp = I915_READ(LVDS);
temp |= LVDS_PORT_EN | LVDS_A0A2_CLKA_POWER_UP;
if (pipe == 1) {
temp |= LVDS_PIPEB_SELECT;
} else {
temp &= ~LVDS_PIPEB_SELECT;
}
temp |= dev_priv->lvds_border_bits;
if (clock->p2 == 7)
temp |= LVDS_B0B3_POWER_UP | LVDS_CLKB_POWER_UP;
else
temp &= ~(LVDS_B0B3_POWER_UP | LVDS_CLKB_POWER_UP);
if (INTEL_INFO(dev)->gen >= 4) {
if (dev_priv->lvds_dither)
temp |= LVDS_ENABLE_DITHER;
else
temp &= ~LVDS_ENABLE_DITHER;
}
temp &= ~(LVDS_HSYNC_POLARITY | LVDS_VSYNC_POLARITY);
if (adjusted_mode->flags & DRM_MODE_FLAG_NHSYNC)
temp |= LVDS_HSYNC_POLARITY;
if (adjusted_mode->flags & DRM_MODE_FLAG_NVSYNC)
temp |= LVDS_VSYNC_POLARITY;
I915_WRITE(LVDS, temp);
}
static void vlv_update_pll(struct drm_crtc *crtc,
struct drm_display_mode *mode,
struct drm_display_mode *adjusted_mode,
intel_clock_t *clock, intel_clock_t *reduced_clock,
int num_connectors)
{
struct drm_device *dev = crtc->dev;
struct drm_i915_private *dev_priv = dev->dev_private;
struct intel_crtc *intel_crtc = to_intel_crtc(crtc);
int pipe = intel_crtc->pipe;
u32 dpll, mdiv, pdiv;
u32 bestn, bestm1, bestm2, bestp1, bestp2;
bool is_sdvo;
u32 temp;
is_sdvo = intel_pipe_has_type(crtc, INTEL_OUTPUT_SDVO) ||
intel_pipe_has_type(crtc, INTEL_OUTPUT_HDMI);
dpll = DPLL_VGA_MODE_DIS;
dpll |= DPLL_EXT_BUFFER_ENABLE_VLV;
dpll |= DPLL_REFA_CLK_ENABLE_VLV;
dpll |= DPLL_INTEGRATED_CLOCK_VLV;
I915_WRITE(DPLL(pipe), dpll);
POSTING_READ(DPLL(pipe));
bestn = clock->n;
bestm1 = clock->m1;
bestm2 = clock->m2;
bestp1 = clock->p1;
bestp2 = clock->p2;
mdiv = ((bestm1 << DPIO_M1DIV_SHIFT) | (bestm2 & DPIO_M2DIV_MASK));
mdiv |= ((bestp1 << DPIO_P1_SHIFT) | (bestp2 << DPIO_P2_SHIFT));
mdiv |= ((bestn << DPIO_N_SHIFT));
mdiv |= (1 << DPIO_POST_DIV_SHIFT);
mdiv |= (1 << DPIO_K_SHIFT);
mdiv |= DPIO_ENABLE_CALIBRATION;
intel_dpio_write(dev_priv, DPIO_DIV(pipe), mdiv);
intel_dpio_write(dev_priv, DPIO_CORE_CLK(pipe), 0x01000000);
pdiv = (1 << DPIO_REFSEL_OVERRIDE) | (5 << DPIO_PLL_MODESEL_SHIFT) |
(3 << DPIO_BIAS_CURRENT_CTL_SHIFT) | (1<<20) |
(7 << DPIO_PLL_REFCLK_SEL_SHIFT) | (8 << DPIO_DRIVER_CTL_SHIFT) |
(5 << DPIO_CLK_BIAS_CTL_SHIFT);
intel_dpio_write(dev_priv, DPIO_REFSFR(pipe), pdiv);
intel_dpio_write(dev_priv, DPIO_LFP_COEFF(pipe), 0x005f003b);
dpll |= DPLL_VCO_ENABLE;
I915_WRITE(DPLL(pipe), dpll);
POSTING_READ(DPLL(pipe));
if (wait_for(((I915_READ(DPLL(pipe)) & DPLL_LOCK_VLV) == DPLL_LOCK_VLV), 1))
DRM_ERROR("DPLL %d failed to lock\n", pipe);
intel_dpio_write(dev_priv, DPIO_FASTCLK_DISABLE, 0x620);
if (intel_pipe_has_type(crtc, INTEL_OUTPUT_DISPLAYPORT))
intel_dp_set_m_n(crtc, mode, adjusted_mode);
I915_WRITE(DPLL(pipe), dpll);
POSTING_READ(DPLL(pipe));
udelay(150);
temp = 0;
if (is_sdvo) {
temp = intel_mode_get_pixel_multiplier(adjusted_mode);
if (temp > 1)
temp = (temp - 1) << DPLL_MD_UDI_MULTIPLIER_SHIFT;
else
temp = 0;
}
I915_WRITE(DPLL_MD(pipe), temp);
POSTING_READ(DPLL_MD(pipe));
if(intel_pipe_has_type(crtc, INTEL_OUTPUT_DISPLAYPORT)
|| intel_pipe_has_type(crtc, INTEL_OUTPUT_HDMI))
{
temp = 0x1000C4;
if(pipe == 1)
temp |= (1 << 21);
intel_dpio_write(dev_priv, DPIO_DATA_CHANNEL1, temp);
}
if(intel_pipe_has_type(crtc,INTEL_OUTPUT_EDP))
{
temp = 0x1000C4;
if(pipe == 1)
temp |= (1 << 21);
intel_dpio_write(dev_priv, DPIO_DATA_CHANNEL2, temp);
}
}
static void i9xx_update_pll(struct drm_crtc *crtc,
struct drm_display_mode *mode,
struct drm_display_mode *adjusted_mode,
intel_clock_t *clock, intel_clock_t *reduced_clock,
int num_connectors)
{
struct drm_device *dev = crtc->dev;
struct drm_i915_private *dev_priv = dev->dev_private;
struct intel_crtc *intel_crtc = to_intel_crtc(crtc);
int pipe = intel_crtc->pipe;
u32 dpll;
bool is_sdvo;
i9xx_update_pll_dividers(crtc, clock, reduced_clock);
is_sdvo = intel_pipe_has_type(crtc, INTEL_OUTPUT_SDVO) ||
intel_pipe_has_type(crtc, INTEL_OUTPUT_HDMI);
dpll = DPLL_VGA_MODE_DIS;
if (intel_pipe_has_type(crtc, INTEL_OUTPUT_LVDS))
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
if (intel_pipe_has_type(crtc, INTEL_OUTPUT_DISPLAYPORT))
dpll |= DPLL_DVO_HIGH_SPEED;
if (IS_PINEVIEW(dev))
dpll |= (1 << (clock->p1 - 1)) << DPLL_FPA01_P1_POST_DIV_SHIFT_PINEVIEW;
else {
dpll |= (1 << (clock->p1 - 1)) << DPLL_FPA01_P1_POST_DIV_SHIFT;
if (IS_G4X(dev) && reduced_clock)
dpll |= (1 << (reduced_clock->p1 - 1)) << DPLL_FPA1_P1_POST_DIV_SHIFT;
}
switch (clock->p2) {
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
if (is_sdvo && intel_pipe_has_type(crtc, INTEL_OUTPUT_TVOUT))
dpll |= PLL_REF_INPUT_TVCLKINBC;
else if (intel_pipe_has_type(crtc, INTEL_OUTPUT_TVOUT))
dpll |= 3;
else if (intel_pipe_has_type(crtc, INTEL_OUTPUT_LVDS) &&
intel_panel_use_ssc(dev_priv) && num_connectors < 2)
dpll |= PLLB_REF_INPUT_SPREADSPECTRUMIN;
else
dpll |= PLL_REF_INPUT_DREFCLK;
dpll |= DPLL_VCO_ENABLE;
I915_WRITE(DPLL(pipe), dpll & ~DPLL_VCO_ENABLE);
POSTING_READ(DPLL(pipe));
udelay(150);
if (intel_pipe_has_type(crtc, INTEL_OUTPUT_LVDS))
intel_update_lvds(crtc, clock, adjusted_mode);
if (intel_pipe_has_type(crtc, INTEL_OUTPUT_DISPLAYPORT))
intel_dp_set_m_n(crtc, mode, adjusted_mode);
I915_WRITE(DPLL(pipe), dpll);
POSTING_READ(DPLL(pipe));
udelay(150);
if (INTEL_INFO(dev)->gen >= 4) {
u32 temp = 0;
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
}
static void i8xx_update_pll(struct drm_crtc *crtc,
struct drm_display_mode *adjusted_mode,
intel_clock_t *clock, intel_clock_t *reduced_clock,
int num_connectors)
{
struct drm_device *dev = crtc->dev;
struct drm_i915_private *dev_priv = dev->dev_private;
struct intel_crtc *intel_crtc = to_intel_crtc(crtc);
int pipe = intel_crtc->pipe;
u32 dpll;
i9xx_update_pll_dividers(crtc, clock, reduced_clock);
dpll = DPLL_VGA_MODE_DIS;
if (intel_pipe_has_type(crtc, INTEL_OUTPUT_LVDS)) {
dpll |= (1 << (clock->p1 - 1)) << DPLL_FPA01_P1_POST_DIV_SHIFT;
} else {
if (clock->p1 == 2)
dpll |= PLL_P1_DIVIDE_BY_TWO;
else
dpll |= (clock->p1 - 2) << DPLL_FPA01_P1_POST_DIV_SHIFT;
if (clock->p2 == 4)
dpll |= PLL_P2_DIVIDE_BY_4;
}
if (intel_pipe_has_type(crtc, INTEL_OUTPUT_TVOUT))
dpll |= 3;
else if (intel_pipe_has_type(crtc, INTEL_OUTPUT_LVDS) &&
intel_panel_use_ssc(dev_priv) && num_connectors < 2)
dpll |= PLLB_REF_INPUT_SPREADSPECTRUMIN;
else
dpll |= PLL_REF_INPUT_DREFCLK;
dpll |= DPLL_VCO_ENABLE;
I915_WRITE(DPLL(pipe), dpll & ~DPLL_VCO_ENABLE);
POSTING_READ(DPLL(pipe));
udelay(150);
if (intel_pipe_has_type(crtc, INTEL_OUTPUT_LVDS))
intel_update_lvds(crtc, clock, adjusted_mode);
I915_WRITE(DPLL(pipe), dpll);
POSTING_READ(DPLL(pipe));
udelay(150);
I915_WRITE(DPLL(pipe), dpll);
}
static void intel_set_pipe_timings(struct intel_crtc *intel_crtc,
struct drm_display_mode *mode,
struct drm_display_mode *adjusted_mode)
{
struct drm_device *dev = intel_crtc->base.dev;
struct drm_i915_private *dev_priv = dev->dev_private;
enum pipe pipe = intel_crtc->pipe;
enum transcoder cpu_transcoder = intel_crtc->cpu_transcoder;
uint32_t vsyncshift;
if (!IS_GEN2(dev) && adjusted_mode->flags & DRM_MODE_FLAG_INTERLACE) {
adjusted_mode->crtc_vtotal -= 1;
adjusted_mode->crtc_vblank_end -= 1;
vsyncshift = adjusted_mode->crtc_hsync_start
- adjusted_mode->crtc_htotal / 2;
} else {
vsyncshift = 0;
}
if (INTEL_INFO(dev)->gen > 3)
I915_WRITE(VSYNCSHIFT(cpu_transcoder), vsyncshift);
I915_WRITE(HTOTAL(cpu_transcoder),
(adjusted_mode->crtc_hdisplay - 1) |
((adjusted_mode->crtc_htotal - 1) << 16));
I915_WRITE(HBLANK(cpu_transcoder),
(adjusted_mode->crtc_hblank_start - 1) |
((adjusted_mode->crtc_hblank_end - 1) << 16));
I915_WRITE(HSYNC(cpu_transcoder),
(adjusted_mode->crtc_hsync_start - 1) |
((adjusted_mode->crtc_hsync_end - 1) << 16));
I915_WRITE(VTOTAL(cpu_transcoder),
(adjusted_mode->crtc_vdisplay - 1) |
((adjusted_mode->crtc_vtotal - 1) << 16));
I915_WRITE(VBLANK(cpu_transcoder),
(adjusted_mode->crtc_vblank_start - 1) |
((adjusted_mode->crtc_vblank_end - 1) << 16));
I915_WRITE(VSYNC(cpu_transcoder),
(adjusted_mode->crtc_vsync_start - 1) |
((adjusted_mode->crtc_vsync_end - 1) << 16));
if (IS_HASWELL(dev) && cpu_transcoder == TRANSCODER_EDP &&
(pipe == PIPE_B || pipe == PIPE_C))
I915_WRITE(VTOTAL(pipe), I915_READ(VTOTAL(cpu_transcoder)));
I915_WRITE(PIPESRC(pipe),
((mode->hdisplay - 1) << 16) | (mode->vdisplay - 1));
}
static int i9xx_crtc_mode_set(struct drm_crtc *crtc,
struct drm_display_mode *mode,
struct drm_display_mode *adjusted_mode,
int x, int y,
struct drm_framebuffer *fb)
{
struct drm_device *dev = crtc->dev;
struct drm_i915_private *dev_priv = dev->dev_private;
struct intel_crtc *intel_crtc = to_intel_crtc(crtc);
int pipe = intel_crtc->pipe;
int plane = intel_crtc->plane;
int refclk, num_connectors = 0;
intel_clock_t clock, reduced_clock;
u32 dspcntr, pipeconf;
bool ok, has_reduced_clock = false, is_sdvo = false;
bool is_lvds = false, is_tv = false, is_dp = false;
struct intel_encoder *encoder;
const intel_limit_t *limit;
int ret;
for_each_encoder_on_crtc(dev, crtc, encoder) {
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
case INTEL_OUTPUT_DISPLAYPORT:
is_dp = true;
break;
}
num_connectors++;
}
refclk = i9xx_get_refclk(crtc, num_connectors);
limit = intel_limit(crtc, refclk);
ok = limit->find_pll(limit, crtc, adjusted_mode->clock, refclk, NULL,
&clock);
if (!ok) {
DRM_ERROR("Couldn't find PLL settings for mode!\n");
return -EINVAL;
}
intel_crtc_update_cursor(crtc, true);
if (is_lvds && dev_priv->lvds_downclock_avail) {
has_reduced_clock = limit->find_pll(limit, crtc,
dev_priv->lvds_downclock,
refclk,
&clock,
&reduced_clock);
}
if (is_sdvo && is_tv)
i9xx_adjust_sdvo_tv_clock(adjusted_mode, &clock);
if (IS_GEN2(dev))
i8xx_update_pll(crtc, adjusted_mode, &clock,
has_reduced_clock ? &reduced_clock : NULL,
num_connectors);
else if (IS_VALLEYVIEW(dev))
vlv_update_pll(crtc, mode, adjusted_mode, &clock,
has_reduced_clock ? &reduced_clock : NULL,
num_connectors);
else
i9xx_update_pll(crtc, mode, adjusted_mode, &clock,
has_reduced_clock ? &reduced_clock : NULL,
num_connectors);
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
if (adjusted_mode->private_flags & INTEL_MODE_DP_FORCE_6BPC) {
pipeconf |= PIPECONF_BPP_6 |
PIPECONF_DITHER_EN |
PIPECONF_DITHER_TYPE_SP;
}
}
if (IS_VALLEYVIEW(dev) && intel_pipe_has_type(crtc, INTEL_OUTPUT_EDP)) {
if (adjusted_mode->private_flags & INTEL_MODE_DP_FORCE_6BPC) {
pipeconf |= PIPECONF_BPP_6 |
PIPECONF_ENABLE |
I965_PIPECONF_ACTIVE;
}
}
DRM_DEBUG_KMS("Mode for pipe %c:\n", pipe == 0 ? 'A' : 'B');
drm_mode_debug_printmodeline(mode);
if (HAS_PIPE_CXSR(dev)) {
if (intel_crtc->lowfreq_avail) {
DRM_DEBUG_KMS("enabling CxSR downclocking\n");
pipeconf |= PIPECONF_CXSR_DOWNCLOCK;
} else {
DRM_DEBUG_KMS("disabling CxSR downclocking\n");
pipeconf &= ~PIPECONF_CXSR_DOWNCLOCK;
}
}
pipeconf &= ~PIPECONF_INTERLACE_MASK;
if (!IS_GEN2(dev) &&
adjusted_mode->flags & DRM_MODE_FLAG_INTERLACE)
pipeconf |= PIPECONF_INTERLACE_W_FIELD_INDICATION;
else
pipeconf |= PIPECONF_PROGRESSIVE;
intel_set_pipe_timings(intel_crtc, mode, adjusted_mode);
I915_WRITE(DSPSIZE(plane),
((mode->vdisplay - 1) << 16) |
(mode->hdisplay - 1));
I915_WRITE(DSPPOS(plane), 0);
I915_WRITE(PIPECONF(pipe), pipeconf);
POSTING_READ(PIPECONF(pipe));
intel_enable_pipe(dev_priv, pipe, false);
intel_wait_for_vblank(dev, pipe);
I915_WRITE(DSPCNTR(plane), dspcntr);
POSTING_READ(DSPCNTR(plane));
ret = intel_pipe_set_base(crtc, x, y, fb);
intel_update_watermarks(dev);
return ret;
}
static void ironlake_init_pch_refclk(struct drm_device *dev)
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
} else
temp &= ~DREF_SSC1_ENABLE;
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
static void lpt_init_pch_refclk(struct drm_device *dev)
{
struct drm_i915_private *dev_priv = dev->dev_private;
struct drm_mode_config *mode_config = &dev->mode_config;
struct intel_encoder *encoder;
bool has_vga = false;
bool is_sdv = false;
u32 tmp;
list_for_each_entry(encoder, &mode_config->encoder_list, base.head) {
switch (encoder->type) {
case INTEL_OUTPUT_ANALOG:
has_vga = true;
break;
}
}
if (!has_vga)
return;
if (IS_HASWELL(dev) && (dev->pci_device & 0xFF00) == 0x0C00)
is_sdv = true;
tmp = intel_sbi_read(dev_priv, SBI_SSCCTL, SBI_ICLK);
tmp &= ~SBI_SSCCTL_DISABLE;
tmp |= SBI_SSCCTL_PATHALT;
intel_sbi_write(dev_priv, SBI_SSCCTL, tmp, SBI_ICLK);
udelay(24);
tmp = intel_sbi_read(dev_priv, SBI_SSCCTL, SBI_ICLK);
tmp &= ~SBI_SSCCTL_PATHALT;
intel_sbi_write(dev_priv, SBI_SSCCTL, tmp, SBI_ICLK);
if (!is_sdv) {
tmp = I915_READ(SOUTH_CHICKEN2);
tmp |= FDI_MPHY_IOSFSB_RESET_CTL;
I915_WRITE(SOUTH_CHICKEN2, tmp);
if (wait_for_atomic_us(I915_READ(SOUTH_CHICKEN2) &
FDI_MPHY_IOSFSB_RESET_STATUS, 100))
DRM_ERROR("FDI mPHY reset assert timeout\n");
tmp = I915_READ(SOUTH_CHICKEN2);
tmp &= ~FDI_MPHY_IOSFSB_RESET_CTL;
I915_WRITE(SOUTH_CHICKEN2, tmp);
if (wait_for_atomic_us((I915_READ(SOUTH_CHICKEN2) &
FDI_MPHY_IOSFSB_RESET_STATUS) == 0,
100))
DRM_ERROR("FDI mPHY reset de-assert timeout\n");
}
tmp = intel_sbi_read(dev_priv, 0x8008, SBI_MPHY);
tmp &= ~(0xFF << 24);
tmp |= (0x12 << 24);
intel_sbi_write(dev_priv, 0x8008, tmp, SBI_MPHY);
if (!is_sdv) {
tmp = intel_sbi_read(dev_priv, 0x808C, SBI_MPHY);
tmp &= ~(0x3 << 6);
tmp |= (1 << 6) | (1 << 0);
intel_sbi_write(dev_priv, 0x808C, tmp, SBI_MPHY);
}
if (is_sdv) {
tmp = intel_sbi_read(dev_priv, 0x800C, SBI_MPHY);
tmp |= 0x7FFF;
intel_sbi_write(dev_priv, 0x800C, tmp, SBI_MPHY);
}
tmp = intel_sbi_read(dev_priv, 0x2008, SBI_MPHY);
tmp |= (1 << 11);
intel_sbi_write(dev_priv, 0x2008, tmp, SBI_MPHY);
tmp = intel_sbi_read(dev_priv, 0x2108, SBI_MPHY);
tmp |= (1 << 11);
intel_sbi_write(dev_priv, 0x2108, tmp, SBI_MPHY);
if (is_sdv) {
tmp = intel_sbi_read(dev_priv, 0x2038, SBI_MPHY);
tmp |= (0x3F << 24) | (0xF << 20) | (0xF << 16);
intel_sbi_write(dev_priv, 0x2038, tmp, SBI_MPHY);
tmp = intel_sbi_read(dev_priv, 0x2138, SBI_MPHY);
tmp |= (0x3F << 24) | (0xF << 20) | (0xF << 16);
intel_sbi_write(dev_priv, 0x2138, tmp, SBI_MPHY);
tmp = intel_sbi_read(dev_priv, 0x203C, SBI_MPHY);
tmp |= (0x3F << 8);
intel_sbi_write(dev_priv, 0x203C, tmp, SBI_MPHY);
tmp = intel_sbi_read(dev_priv, 0x213C, SBI_MPHY);
tmp |= (0x3F << 8);
intel_sbi_write(dev_priv, 0x213C, tmp, SBI_MPHY);
}
tmp = intel_sbi_read(dev_priv, 0x206C, SBI_MPHY);
tmp |= (1 << 24) | (1 << 21) | (1 << 18);
intel_sbi_write(dev_priv, 0x206C, tmp, SBI_MPHY);
tmp = intel_sbi_read(dev_priv, 0x216C, SBI_MPHY);
tmp |= (1 << 24) | (1 << 21) | (1 << 18);
intel_sbi_write(dev_priv, 0x216C, tmp, SBI_MPHY);
if (!is_sdv) {
tmp = intel_sbi_read(dev_priv, 0x2080, SBI_MPHY);
tmp &= ~(7 << 13);
tmp |= (5 << 13);
intel_sbi_write(dev_priv, 0x2080, tmp, SBI_MPHY);
tmp = intel_sbi_read(dev_priv, 0x2180, SBI_MPHY);
tmp &= ~(7 << 13);
tmp |= (5 << 13);
intel_sbi_write(dev_priv, 0x2180, tmp, SBI_MPHY);
}
tmp = intel_sbi_read(dev_priv, 0x208C, SBI_MPHY);
tmp &= ~0xFF;
tmp |= 0x1C;
intel_sbi_write(dev_priv, 0x208C, tmp, SBI_MPHY);
tmp = intel_sbi_read(dev_priv, 0x218C, SBI_MPHY);
tmp &= ~0xFF;
tmp |= 0x1C;
intel_sbi_write(dev_priv, 0x218C, tmp, SBI_MPHY);
tmp = intel_sbi_read(dev_priv, 0x2098, SBI_MPHY);
tmp &= ~(0xFF << 16);
tmp |= (0x1C << 16);
intel_sbi_write(dev_priv, 0x2098, tmp, SBI_MPHY);
tmp = intel_sbi_read(dev_priv, 0x2198, SBI_MPHY);
tmp &= ~(0xFF << 16);
tmp |= (0x1C << 16);
intel_sbi_write(dev_priv, 0x2198, tmp, SBI_MPHY);
if (!is_sdv) {
tmp = intel_sbi_read(dev_priv, 0x20C4, SBI_MPHY);
tmp |= (1 << 27);
intel_sbi_write(dev_priv, 0x20C4, tmp, SBI_MPHY);
tmp = intel_sbi_read(dev_priv, 0x21C4, SBI_MPHY);
tmp |= (1 << 27);
intel_sbi_write(dev_priv, 0x21C4, tmp, SBI_MPHY);
tmp = intel_sbi_read(dev_priv, 0x20EC, SBI_MPHY);
tmp &= ~(0xF << 28);
tmp |= (4 << 28);
intel_sbi_write(dev_priv, 0x20EC, tmp, SBI_MPHY);
tmp = intel_sbi_read(dev_priv, 0x21EC, SBI_MPHY);
tmp &= ~(0xF << 28);
tmp |= (4 << 28);
intel_sbi_write(dev_priv, 0x21EC, tmp, SBI_MPHY);
}
tmp = intel_sbi_read(dev_priv, SBI_DBUFF0, SBI_ICLK);
tmp |= SBI_DBUFF0_ENABLE;
intel_sbi_write(dev_priv, SBI_DBUFF0, tmp, SBI_ICLK);
}
void intel_init_pch_refclk(struct drm_device *dev)
{
if (HAS_PCH_IBX(dev) || HAS_PCH_CPT(dev))
ironlake_init_pch_refclk(dev);
else if (HAS_PCH_LPT(dev))
lpt_init_pch_refclk(dev);
}
static int ironlake_get_refclk(struct drm_crtc *crtc)
{
struct drm_device *dev = crtc->dev;
struct drm_i915_private *dev_priv = dev->dev_private;
struct intel_encoder *encoder;
struct intel_encoder *edp_encoder = NULL;
int num_connectors = 0;
bool is_lvds = false;
for_each_encoder_on_crtc(dev, crtc, encoder) {
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
static void ironlake_set_pipeconf(struct drm_crtc *crtc,
struct drm_display_mode *adjusted_mode,
bool dither)
{
struct drm_i915_private *dev_priv = crtc->dev->dev_private;
struct intel_crtc *intel_crtc = to_intel_crtc(crtc);
int pipe = intel_crtc->pipe;
uint32_t val;
val = I915_READ(PIPECONF(pipe));
val &= ~PIPE_BPC_MASK;
switch (intel_crtc->bpp) {
case 18:
val |= PIPE_6BPC;
break;
case 24:
val |= PIPE_8BPC;
break;
case 30:
val |= PIPE_10BPC;
break;
case 36:
val |= PIPE_12BPC;
break;
default:
BUG();
}
val &= ~(PIPECONF_DITHER_EN | PIPECONF_DITHER_TYPE_MASK);
if (dither)
val |= (PIPECONF_DITHER_EN | PIPECONF_DITHER_TYPE_SP);
val &= ~PIPECONF_INTERLACE_MASK;
if (adjusted_mode->flags & DRM_MODE_FLAG_INTERLACE)
val |= PIPECONF_INTERLACED_ILK;
else
val |= PIPECONF_PROGRESSIVE;
I915_WRITE(PIPECONF(pipe), val);
POSTING_READ(PIPECONF(pipe));
}
static void haswell_set_pipeconf(struct drm_crtc *crtc,
struct drm_display_mode *adjusted_mode,
bool dither)
{
struct drm_i915_private *dev_priv = crtc->dev->dev_private;
struct intel_crtc *intel_crtc = to_intel_crtc(crtc);
enum transcoder cpu_transcoder = intel_crtc->cpu_transcoder;
uint32_t val;
val = I915_READ(PIPECONF(cpu_transcoder));
val &= ~(PIPECONF_DITHER_EN | PIPECONF_DITHER_TYPE_MASK);
if (dither)
val |= (PIPECONF_DITHER_EN | PIPECONF_DITHER_TYPE_SP);
val &= ~PIPECONF_INTERLACE_MASK_HSW;
if (adjusted_mode->flags & DRM_MODE_FLAG_INTERLACE)
val |= PIPECONF_INTERLACED_ILK;
else
val |= PIPECONF_PROGRESSIVE;
I915_WRITE(PIPECONF(cpu_transcoder), val);
POSTING_READ(PIPECONF(cpu_transcoder));
}
static bool ironlake_compute_clocks(struct drm_crtc *crtc,
struct drm_display_mode *adjusted_mode,
intel_clock_t *clock,
bool *has_reduced_clock,
intel_clock_t *reduced_clock)
{
struct drm_device *dev = crtc->dev;
struct drm_i915_private *dev_priv = dev->dev_private;
struct intel_encoder *intel_encoder;
int refclk;
const intel_limit_t *limit;
bool ret, is_sdvo = false, is_tv = false, is_lvds = false;
for_each_encoder_on_crtc(dev, crtc, intel_encoder) {
switch (intel_encoder->type) {
case INTEL_OUTPUT_LVDS:
is_lvds = true;
break;
case INTEL_OUTPUT_SDVO:
case INTEL_OUTPUT_HDMI:
is_sdvo = true;
if (intel_encoder->needs_tv_clock)
is_tv = true;
break;
case INTEL_OUTPUT_TVOUT:
is_tv = true;
break;
}
}
refclk = ironlake_get_refclk(crtc);
limit = intel_limit(crtc, refclk);
ret = limit->find_pll(limit, crtc, adjusted_mode->clock, refclk, NULL,
clock);
if (!ret)
return false;
if (is_lvds && dev_priv->lvds_downclock_avail) {
*has_reduced_clock = limit->find_pll(limit, crtc,
dev_priv->lvds_downclock,
refclk,
clock,
reduced_clock);
}
if (is_sdvo && is_tv)
i9xx_adjust_sdvo_tv_clock(adjusted_mode, clock);
return true;
}
static void cpt_enable_fdi_bc_bifurcation(struct drm_device *dev)
{
struct drm_i915_private *dev_priv = dev->dev_private;
uint32_t temp;
temp = I915_READ(SOUTH_CHICKEN1);
if (temp & FDI_BC_BIFURCATION_SELECT)
return;
WARN_ON(I915_READ(FDI_RX_CTL(PIPE_B)) & FDI_RX_ENABLE);
WARN_ON(I915_READ(FDI_RX_CTL(PIPE_C)) & FDI_RX_ENABLE);
temp |= FDI_BC_BIFURCATION_SELECT;
DRM_DEBUG_KMS("enabling fdi C rx\n");
I915_WRITE(SOUTH_CHICKEN1, temp);
POSTING_READ(SOUTH_CHICKEN1);
}
static bool ironlake_check_fdi_lanes(struct intel_crtc *intel_crtc)
{
struct drm_device *dev = intel_crtc->base.dev;
struct drm_i915_private *dev_priv = dev->dev_private;
struct intel_crtc *pipe_B_crtc =
to_intel_crtc(dev_priv->pipe_to_crtc_mapping[PIPE_B]);
DRM_DEBUG_KMS("checking fdi config on pipe %i, lanes %i\n",
intel_crtc->pipe, intel_crtc->fdi_lanes);
if (intel_crtc->fdi_lanes > 4) {
DRM_DEBUG_KMS("invalid fdi lane config on pipe %i: %i lanes\n",
intel_crtc->pipe, intel_crtc->fdi_lanes);
intel_crtc->fdi_lanes = 4;
return false;
}
if (dev_priv->num_pipe == 2)
return true;
switch (intel_crtc->pipe) {
case PIPE_A:
return true;
case PIPE_B:
if (dev_priv->pipe_to_crtc_mapping[PIPE_C]->enabled &&
intel_crtc->fdi_lanes > 2) {
DRM_DEBUG_KMS("invalid shared fdi lane config on pipe %i: %i lanes\n",
intel_crtc->pipe, intel_crtc->fdi_lanes);
intel_crtc->fdi_lanes = 2;
return false;
}
if (intel_crtc->fdi_lanes > 2)
WARN_ON(I915_READ(SOUTH_CHICKEN1) & FDI_BC_BIFURCATION_SELECT);
else
cpt_enable_fdi_bc_bifurcation(dev);
return true;
case PIPE_C:
if (!pipe_B_crtc->base.enabled || pipe_B_crtc->fdi_lanes <= 2) {
if (intel_crtc->fdi_lanes > 2) {
DRM_DEBUG_KMS("invalid shared fdi lane config on pipe %i: %i lanes\n",
intel_crtc->pipe, intel_crtc->fdi_lanes);
intel_crtc->fdi_lanes = 2;
return false;
}
} else {
DRM_DEBUG_KMS("fdi link B uses too many lanes to enable link C\n");
return false;
}
cpt_enable_fdi_bc_bifurcation(dev);
return true;
default:
BUG();
}
}
int ironlake_get_lanes_required(int target_clock, int link_bw, int bpp)
{
u32 bps = target_clock * bpp * 21 / 20;
return bps / (link_bw * 8) + 1;
}
static void ironlake_set_m_n(struct drm_crtc *crtc,
struct drm_display_mode *mode,
struct drm_display_mode *adjusted_mode)
{
struct drm_device *dev = crtc->dev;
struct drm_i915_private *dev_priv = dev->dev_private;
struct intel_crtc *intel_crtc = to_intel_crtc(crtc);
enum transcoder cpu_transcoder = intel_crtc->cpu_transcoder;
struct intel_encoder *intel_encoder, *edp_encoder = NULL;
struct fdi_m_n m_n = {0};
int target_clock, pixel_multiplier, lane, link_bw;
bool is_dp = false, is_cpu_edp = false;
for_each_encoder_on_crtc(dev, crtc, intel_encoder) {
switch (intel_encoder->type) {
case INTEL_OUTPUT_DISPLAYPORT:
is_dp = true;
break;
case INTEL_OUTPUT_EDP:
is_dp = true;
if (!intel_encoder_is_pch_edp(&intel_encoder->base))
is_cpu_edp = true;
edp_encoder = intel_encoder;
break;
}
}
pixel_multiplier = intel_mode_get_pixel_multiplier(adjusted_mode);
lane = 0;
if (is_cpu_edp) {
intel_edp_link_config(edp_encoder, &lane, &link_bw);
} else {
link_bw = intel_fdi_link_freq(dev) * MHz(100)/KHz(1)/10;
}
if (edp_encoder)
target_clock = intel_edp_target_clock(edp_encoder, mode);
else if (is_dp)
target_clock = mode->clock;
else
target_clock = adjusted_mode->clock;
if (!lane)
lane = ironlake_get_lanes_required(target_clock, link_bw,
intel_crtc->bpp);
intel_crtc->fdi_lanes = lane;
if (pixel_multiplier > 1)
link_bw *= pixel_multiplier;
ironlake_compute_m_n(intel_crtc->bpp, lane, target_clock, link_bw,
&m_n);
I915_WRITE(PIPE_DATA_M1(cpu_transcoder), TU_SIZE(m_n.tu) | m_n.gmch_m);
I915_WRITE(PIPE_DATA_N1(cpu_transcoder), m_n.gmch_n);
I915_WRITE(PIPE_LINK_M1(cpu_transcoder), m_n.link_m);
I915_WRITE(PIPE_LINK_N1(cpu_transcoder), m_n.link_n);
}
static uint32_t ironlake_compute_dpll(struct intel_crtc *intel_crtc,
struct drm_display_mode *adjusted_mode,
intel_clock_t *clock, u32 fp)
{
struct drm_crtc *crtc = &intel_crtc->base;
struct drm_device *dev = crtc->dev;
struct drm_i915_private *dev_priv = dev->dev_private;
struct intel_encoder *intel_encoder;
uint32_t dpll;
int factor, pixel_multiplier, num_connectors = 0;
bool is_lvds = false, is_sdvo = false, is_tv = false;
bool is_dp = false, is_cpu_edp = false;
for_each_encoder_on_crtc(dev, crtc, intel_encoder) {
switch (intel_encoder->type) {
case INTEL_OUTPUT_LVDS:
is_lvds = true;
break;
case INTEL_OUTPUT_SDVO:
case INTEL_OUTPUT_HDMI:
is_sdvo = true;
if (intel_encoder->needs_tv_clock)
is_tv = true;
break;
case INTEL_OUTPUT_TVOUT:
is_tv = true;
break;
case INTEL_OUTPUT_DISPLAYPORT:
is_dp = true;
break;
case INTEL_OUTPUT_EDP:
is_dp = true;
if (!intel_encoder_is_pch_edp(&intel_encoder->base))
is_cpu_edp = true;
break;
}
num_connectors++;
}
factor = 21;
if (is_lvds) {
if ((intel_panel_use_ssc(dev_priv) &&
dev_priv->lvds_ssc_freq == 100) ||
(I915_READ(PCH_LVDS) & LVDS_CLKB_POWER_MASK) == LVDS_CLKB_POWER_UP)
factor = 25;
} else if (is_sdvo && is_tv)
factor = 20;
if (clock->m < factor * clock->n)
fp |= FP_CB_TUNE;
dpll = 0;
if (is_lvds)
dpll |= DPLLB_MODE_LVDS;
else
dpll |= DPLLB_MODE_DAC_SERIAL;
if (is_sdvo) {
pixel_multiplier = intel_mode_get_pixel_multiplier(adjusted_mode);
if (pixel_multiplier > 1) {
dpll |= (pixel_multiplier - 1) << PLL_REF_SDVO_HDMI_MULTIPLIER_SHIFT;
}
dpll |= DPLL_DVO_HIGH_SPEED;
}
if (is_dp && !is_cpu_edp)
dpll |= DPLL_DVO_HIGH_SPEED;
dpll |= (1 << (clock->p1 - 1)) << DPLL_FPA01_P1_POST_DIV_SHIFT;
dpll |= (1 << (clock->p1 - 1)) << DPLL_FPA1_P1_POST_DIV_SHIFT;
switch (clock->p2) {
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
return dpll;
}
static int ironlake_crtc_mode_set(struct drm_crtc *crtc,
struct drm_display_mode *mode,
struct drm_display_mode *adjusted_mode,
int x, int y,
struct drm_framebuffer *fb)
{
struct drm_device *dev = crtc->dev;
struct drm_i915_private *dev_priv = dev->dev_private;
struct intel_crtc *intel_crtc = to_intel_crtc(crtc);
int pipe = intel_crtc->pipe;
int plane = intel_crtc->plane;
int num_connectors = 0;
intel_clock_t clock, reduced_clock;
u32 dpll, fp = 0, fp2 = 0;
bool ok, has_reduced_clock = false;
bool is_lvds = false, is_dp = false, is_cpu_edp = false;
struct intel_encoder *encoder;
u32 temp;
int ret;
bool dither, fdi_config_ok;
for_each_encoder_on_crtc(dev, crtc, encoder) {
switch (encoder->type) {
case INTEL_OUTPUT_LVDS:
is_lvds = true;
break;
case INTEL_OUTPUT_DISPLAYPORT:
is_dp = true;
break;
case INTEL_OUTPUT_EDP:
is_dp = true;
if (!intel_encoder_is_pch_edp(&encoder->base))
is_cpu_edp = true;
break;
}
num_connectors++;
}
WARN(!(HAS_PCH_IBX(dev) || HAS_PCH_CPT(dev)),
"Unexpected PCH type %d\n", INTEL_PCH_TYPE(dev));
ok = ironlake_compute_clocks(crtc, adjusted_mode, &clock,
&has_reduced_clock, &reduced_clock);
if (!ok) {
DRM_ERROR("Couldn't find PLL settings for mode!\n");
return -EINVAL;
}
intel_crtc_update_cursor(crtc, true);
dither = intel_choose_pipe_bpp_dither(crtc, fb, &intel_crtc->bpp,
adjusted_mode);
if (is_lvds && dev_priv->lvds_dither)
dither = true;
fp = clock.n << 16 | clock.m1 << 8 | clock.m2;
if (has_reduced_clock)
fp2 = reduced_clock.n << 16 | reduced_clock.m1 << 8 |
reduced_clock.m2;
dpll = ironlake_compute_dpll(intel_crtc, adjusted_mode, &clock, fp);
DRM_DEBUG_KMS("Mode for pipe %d:\n", pipe);
drm_mode_debug_printmodeline(mode);
if (!is_cpu_edp) {
struct intel_pch_pll *pll;
pll = intel_get_pch_pll(intel_crtc, dpll, fp);
if (pll == NULL) {
DRM_DEBUG_DRIVER("failed to find PLL for pipe %d\n",
pipe);
return -EINVAL;
}
} else
intel_put_pch_pll(intel_crtc);
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
temp &= ~(LVDS_HSYNC_POLARITY | LVDS_VSYNC_POLARITY);
if (adjusted_mode->flags & DRM_MODE_FLAG_NHSYNC)
temp |= LVDS_HSYNC_POLARITY;
if (adjusted_mode->flags & DRM_MODE_FLAG_NVSYNC)
temp |= LVDS_VSYNC_POLARITY;
I915_WRITE(PCH_LVDS, temp);
}
if (is_dp && !is_cpu_edp) {
intel_dp_set_m_n(crtc, mode, adjusted_mode);
} else {
I915_WRITE(TRANSDATA_M1(pipe), 0);
I915_WRITE(TRANSDATA_N1(pipe), 0);
I915_WRITE(TRANSDPLINK_M1(pipe), 0);
I915_WRITE(TRANSDPLINK_N1(pipe), 0);
}
if (intel_crtc->pch_pll) {
I915_WRITE(intel_crtc->pch_pll->pll_reg, dpll);
POSTING_READ(intel_crtc->pch_pll->pll_reg);
udelay(150);
I915_WRITE(intel_crtc->pch_pll->pll_reg, dpll);
}
intel_crtc->lowfreq_avail = false;
if (intel_crtc->pch_pll) {
if (is_lvds && has_reduced_clock && i915_powersave) {
I915_WRITE(intel_crtc->pch_pll->fp1_reg, fp2);
intel_crtc->lowfreq_avail = true;
} else {
I915_WRITE(intel_crtc->pch_pll->fp1_reg, fp);
}
}
intel_set_pipe_timings(intel_crtc, mode, adjusted_mode);
ironlake_set_m_n(crtc, mode, adjusted_mode);
fdi_config_ok = ironlake_check_fdi_lanes(intel_crtc);
if (is_cpu_edp)
ironlake_set_pll_edp(crtc, adjusted_mode->clock);
ironlake_set_pipeconf(crtc, adjusted_mode, dither);
intel_wait_for_vblank(dev, pipe);
I915_WRITE(DSPCNTR(plane), DISPPLANE_GAMMA_ENABLE);
POSTING_READ(DSPCNTR(plane));
ret = intel_pipe_set_base(crtc, x, y, fb);
intel_update_watermarks(dev);
intel_update_linetime_watermarks(dev, pipe, adjusted_mode);
return fdi_config_ok ? ret : -EINVAL;
}
static int haswell_crtc_mode_set(struct drm_crtc *crtc,
struct drm_display_mode *mode,
struct drm_display_mode *adjusted_mode,
int x, int y,
struct drm_framebuffer *fb)
{
struct drm_device *dev = crtc->dev;
struct drm_i915_private *dev_priv = dev->dev_private;
struct intel_crtc *intel_crtc = to_intel_crtc(crtc);
int pipe = intel_crtc->pipe;
int plane = intel_crtc->plane;
int num_connectors = 0;
intel_clock_t clock, reduced_clock;
u32 dpll = 0, fp = 0, fp2 = 0;
bool ok, has_reduced_clock = false;
bool is_lvds = false, is_dp = false, is_cpu_edp = false;
struct intel_encoder *encoder;
u32 temp;
int ret;
bool dither;
for_each_encoder_on_crtc(dev, crtc, encoder) {
switch (encoder->type) {
case INTEL_OUTPUT_LVDS:
is_lvds = true;
break;
case INTEL_OUTPUT_DISPLAYPORT:
is_dp = true;
break;
case INTEL_OUTPUT_EDP:
is_dp = true;
if (!intel_encoder_is_pch_edp(&encoder->base))
is_cpu_edp = true;
break;
}
num_connectors++;
}
if (is_cpu_edp)
intel_crtc->cpu_transcoder = TRANSCODER_EDP;
else
intel_crtc->cpu_transcoder = pipe;
WARN(!HAS_PCH_LPT(dev), "Unexpected PCH type %d\n",
INTEL_PCH_TYPE(dev));
WARN(num_connectors != 1, "%d connectors attached to pipe %c\n",
num_connectors, pipe_name(pipe));
WARN_ON(I915_READ(PIPECONF(intel_crtc->cpu_transcoder)) &
(PIPECONF_ENABLE | I965_PIPECONF_ACTIVE));
WARN_ON(I915_READ(DSPCNTR(plane)) & DISPLAY_PLANE_ENABLE);
if (!intel_ddi_pll_mode_set(crtc, adjusted_mode->clock))
return -EINVAL;
if (HAS_PCH_IBX(dev) || HAS_PCH_CPT(dev)) {
ok = ironlake_compute_clocks(crtc, adjusted_mode, &clock,
&has_reduced_clock,
&reduced_clock);
if (!ok) {
DRM_ERROR("Couldn't find PLL settings for mode!\n");
return -EINVAL;
}
}
intel_crtc_update_cursor(crtc, true);
dither = intel_choose_pipe_bpp_dither(crtc, fb, &intel_crtc->bpp,
adjusted_mode);
if (is_lvds && dev_priv->lvds_dither)
dither = true;
DRM_DEBUG_KMS("Mode for pipe %d:\n", pipe);
drm_mode_debug_printmodeline(mode);
if (HAS_PCH_IBX(dev) || HAS_PCH_CPT(dev)) {
fp = clock.n << 16 | clock.m1 << 8 | clock.m2;
if (has_reduced_clock)
fp2 = reduced_clock.n << 16 | reduced_clock.m1 << 8 |
reduced_clock.m2;
dpll = ironlake_compute_dpll(intel_crtc, adjusted_mode, &clock,
fp);
if (!is_cpu_edp) {
struct intel_pch_pll *pll;
pll = intel_get_pch_pll(intel_crtc, dpll, fp);
if (pll == NULL) {
DRM_DEBUG_DRIVER("failed to find PLL for pipe %d\n",
pipe);
return -EINVAL;
}
} else
intel_put_pch_pll(intel_crtc);
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
temp &= ~(LVDS_B0B3_POWER_UP |
LVDS_CLKB_POWER_UP);
temp &= ~(LVDS_HSYNC_POLARITY | LVDS_VSYNC_POLARITY);
if (adjusted_mode->flags & DRM_MODE_FLAG_NHSYNC)
temp |= LVDS_HSYNC_POLARITY;
if (adjusted_mode->flags & DRM_MODE_FLAG_NVSYNC)
temp |= LVDS_VSYNC_POLARITY;
I915_WRITE(PCH_LVDS, temp);
}
}
if (is_dp && !is_cpu_edp) {
intel_dp_set_m_n(crtc, mode, adjusted_mode);
} else {
if (HAS_PCH_IBX(dev) || HAS_PCH_CPT(dev)) {
I915_WRITE(TRANSDATA_M1(pipe), 0);
I915_WRITE(TRANSDATA_N1(pipe), 0);
I915_WRITE(TRANSDPLINK_M1(pipe), 0);
I915_WRITE(TRANSDPLINK_N1(pipe), 0);
}
}
intel_crtc->lowfreq_avail = false;
if (HAS_PCH_IBX(dev) || HAS_PCH_CPT(dev)) {
if (intel_crtc->pch_pll) {
I915_WRITE(intel_crtc->pch_pll->pll_reg, dpll);
POSTING_READ(intel_crtc->pch_pll->pll_reg);
udelay(150);
I915_WRITE(intel_crtc->pch_pll->pll_reg, dpll);
}
if (intel_crtc->pch_pll) {
if (is_lvds && has_reduced_clock && i915_powersave) {
I915_WRITE(intel_crtc->pch_pll->fp1_reg, fp2);
intel_crtc->lowfreq_avail = true;
} else {
I915_WRITE(intel_crtc->pch_pll->fp1_reg, fp);
}
}
}
intel_set_pipe_timings(intel_crtc, mode, adjusted_mode);
if (!is_dp || is_cpu_edp)
ironlake_set_m_n(crtc, mode, adjusted_mode);
if (HAS_PCH_IBX(dev) || HAS_PCH_CPT(dev))
if (is_cpu_edp)
ironlake_set_pll_edp(crtc, adjusted_mode->clock);
haswell_set_pipeconf(crtc, adjusted_mode, dither);
I915_WRITE(DSPCNTR(plane), DISPPLANE_GAMMA_ENABLE);
POSTING_READ(DSPCNTR(plane));
ret = intel_pipe_set_base(crtc, x, y, fb);
intel_update_watermarks(dev);
intel_update_linetime_watermarks(dev, pipe, adjusted_mode);
return ret;
}
static int intel_crtc_mode_set(struct drm_crtc *crtc,
struct drm_display_mode *mode,
struct drm_display_mode *adjusted_mode,
int x, int y,
struct drm_framebuffer *fb)
{
struct drm_device *dev = crtc->dev;
struct drm_i915_private *dev_priv = dev->dev_private;
struct drm_encoder_helper_funcs *encoder_funcs;
struct intel_encoder *encoder;
struct intel_crtc *intel_crtc = to_intel_crtc(crtc);
int pipe = intel_crtc->pipe;
int ret;
drm_vblank_pre_modeset(dev, pipe);
ret = dev_priv->display.crtc_mode_set(crtc, mode, adjusted_mode,
x, y, fb);
drm_vblank_post_modeset(dev, pipe);
if (ret != 0)
return ret;
for_each_encoder_on_crtc(dev, crtc, encoder) {
DRM_DEBUG_KMS("[ENCODER:%d:%s] set [MODE:%d:%s]\n",
encoder->base.base.id,
drm_get_encoder_name(&encoder->base),
mode->base.id, mode->name);
encoder_funcs = encoder->base.helper_private;
encoder_funcs->mode_set(&encoder->base, mode, adjusted_mode);
}
return 0;
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
static void haswell_write_eld(struct drm_connector *connector,
struct drm_crtc *crtc)
{
struct drm_i915_private *dev_priv = connector->dev->dev_private;
uint8_t *eld = connector->eld;
struct drm_device *dev = crtc->dev;
uint32_t eldv;
uint32_t i;
int len;
int pipe = to_intel_crtc(crtc)->pipe;
int tmp;
int hdmiw_hdmiedid = HSW_AUD_EDID_DATA(pipe);
int aud_cntl_st = HSW_AUD_DIP_ELD_CTRL(pipe);
int aud_config = HSW_AUD_CFG(pipe);
int aud_cntrl_st2 = HSW_AUD_PIN_ELD_CP_VLD;
DRM_DEBUG_DRIVER("HDMI: Haswell Audio initialize....\n");
DRM_DEBUG_DRIVER("HDMI audio: enable codec\n");
tmp = I915_READ(aud_cntrl_st2);
tmp |= (AUDIO_OUTPUT_ENABLE_A << (pipe * 4));
I915_WRITE(aud_cntrl_st2, tmp);
intel_wait_for_vblank(dev, pipe);
tmp = I915_READ(aud_cntrl_st2);
DRM_DEBUG_DRIVER("HDMI audio: pin eld vld status=0x%8x\n", tmp);
tmp |= (AUDIO_ELD_VALID_A << (pipe * 4));
I915_WRITE(aud_cntrl_st2, tmp);
tmp = I915_READ(aud_cntrl_st2);
DRM_DEBUG_DRIVER("HDMI audio: eld vld status=0x%8x\n", tmp);
tmp = I915_READ(aud_config);
DRM_DEBUG_DRIVER("HDMI audio: audio conf: 0x%8x\n", tmp);
tmp &= ~(AUD_CONFIG_N_VALUE_INDEX | AUD_CONFIG_N_PROG_ENABLE);
I915_WRITE(aud_config, tmp);
DRM_DEBUG_DRIVER("ELD on pipe %c\n", pipe_name(pipe));
eldv = AUDIO_ELD_VALID_A << (pipe * 4);
if (intel_pipe_has_type(crtc, INTEL_OUTPUT_DISPLAYPORT)) {
DRM_DEBUG_DRIVER("ELD: DisplayPort detected\n");
eld[5] |= (1 << 2);
I915_WRITE(aud_config, AUD_CONFIG_N_VALUE_INDEX);
} else
I915_WRITE(aud_config, 0);
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
i = (i >> 29) & DIP_PORT_SEL_MASK;
DRM_DEBUG_DRIVER("port num:%d\n", i);
len = min_t(uint8_t, eld[2], 21);
DRM_DEBUG_DRIVER("ELD size %d\n", len);
for (i = 0; i < len; i++)
I915_WRITE(hdmiw_hdmiedid, *((uint32_t *)eld + i));
i = I915_READ(aud_cntrl_st2);
i |= eldv;
I915_WRITE(aud_cntrl_st2, i);
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
int aud_config;
int aud_cntl_st;
int aud_cntrl_st2;
int pipe = to_intel_crtc(crtc)->pipe;
if (HAS_PCH_IBX(connector->dev)) {
hdmiw_hdmiedid = IBX_HDMIW_HDMIEDID(pipe);
aud_config = IBX_AUD_CFG(pipe);
aud_cntl_st = IBX_AUD_CNTL_ST(pipe);
aud_cntrl_st2 = IBX_AUD_CNTL_ST2;
} else {
hdmiw_hdmiedid = CPT_HDMIW_HDMIEDID(pipe);
aud_config = CPT_AUD_CFG(pipe);
aud_cntl_st = CPT_AUD_CNTL_ST(pipe);
aud_cntrl_st2 = CPT_AUD_CNTRL_ST2;
}
DRM_DEBUG_DRIVER("ELD on pipe %c\n", pipe_name(pipe));
i = I915_READ(aud_cntl_st);
i = (i >> 29) & DIP_PORT_SEL_MASK;
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
I915_WRITE(aud_config, AUD_CONFIG_N_VALUE_INDEX);
} else
I915_WRITE(aud_config, 0);
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
if (IS_IVYBRIDGE(dev) || IS_HASWELL(dev)) {
I915_WRITE(CURPOS_IVB(pipe), pos);
ivb_update_cursor(crtc, base);
} else {
I915_WRITE(CURPOS(pipe), pos);
if (IS_845G(dev) || IS_I865G(dev))
i845_update_cursor(crtc, base);
else
i9xx_update_cursor(crtc, base);
}
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
struct drm_mode_fb_cmd2 mode_cmd = { 0 };
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
bool intel_get_load_detect_pipe(struct drm_connector *connector,
struct drm_display_mode *mode,
struct intel_load_detect_pipe *old)
{
struct intel_crtc *intel_crtc;
struct intel_encoder *intel_encoder =
intel_attached_encoder(connector);
struct drm_crtc *possible_crtc;
struct drm_encoder *encoder = &intel_encoder->base;
struct drm_crtc *crtc = NULL;
struct drm_device *dev = encoder->dev;
struct drm_framebuffer *fb;
int i = -1;
DRM_DEBUG_KMS("[CONNECTOR:%d:%s], [ENCODER:%d:%s]\n",
connector->base.id, drm_get_connector_name(connector),
encoder->base.id, drm_get_encoder_name(encoder));
if (encoder->crtc) {
crtc = encoder->crtc;
old->dpms_mode = connector->dpms;
old->load_detect_temp = false;
if (connector->dpms != DRM_MODE_DPMS_ON)
connector->funcs->dpms(connector, DRM_MODE_DPMS_ON);
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
intel_encoder->new_crtc = to_intel_crtc(crtc);
to_intel_connector(connector)->new_encoder = intel_encoder;
intel_crtc = to_intel_crtc(crtc);
old->dpms_mode = connector->dpms;
old->load_detect_temp = true;
old->release_fb = NULL;
if (!mode)
mode = &load_detect_mode;
fb = mode_fits_in_fbdev(dev, mode);
if (fb == NULL) {
DRM_DEBUG_KMS("creating tmp fb for load-detection\n");
fb = intel_framebuffer_create_for_mode(dev, mode, 24, 32);
old->release_fb = fb;
} else
DRM_DEBUG_KMS("reusing fbdev for load-detection framebuffer\n");
if (IS_ERR(fb)) {
DRM_DEBUG_KMS("failed to allocate framebuffer for load-detection\n");
return false;
}
if (!intel_set_mode(crtc, mode, 0, 0, fb)) {
DRM_DEBUG_KMS("failed to set mode on load-detect pipe\n");
if (old->release_fb)
old->release_fb->funcs->destroy(old->release_fb);
return false;
}
intel_wait_for_vblank(dev, intel_crtc->pipe);
return true;
}
void intel_release_load_detect_pipe(struct drm_connector *connector,
struct intel_load_detect_pipe *old)
{
struct intel_encoder *intel_encoder =
intel_attached_encoder(connector);
struct drm_encoder *encoder = &intel_encoder->base;
DRM_DEBUG_KMS("[CONNECTOR:%d:%s], [ENCODER:%d:%s]\n",
connector->base.id, drm_get_connector_name(connector),
encoder->base.id, drm_get_encoder_name(encoder));
if (old->load_detect_temp) {
struct drm_crtc *crtc = encoder->crtc;
to_intel_connector(connector)->new_encoder = NULL;
intel_encoder->new_crtc = NULL;
intel_set_mode(crtc, NULL, 0, 0, NULL);
if (old->release_fb)
old->release_fb->funcs->destroy(old->release_fb);
return;
}
if (old->dpms_mode != DRM_MODE_DPMS_ON)
connector->funcs->dpms(connector, old->dpms_mode);
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
enum transcoder cpu_transcoder = intel_crtc->cpu_transcoder;
struct drm_display_mode *mode;
int htot = I915_READ(HTOTAL(cpu_transcoder));
int hsync = I915_READ(HSYNC(cpu_transcoder));
int vtot = I915_READ(VTOTAL(cpu_transcoder));
int vsync = I915_READ(VSYNC(cpu_transcoder));
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
return mode;
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
assert_panel_unlocked(dev_priv, pipe);
dpll &= ~DISPLAY_RATE_SELECT_FPA1;
I915_WRITE(dpll_reg, dpll);
intel_wait_for_vblank(dev, pipe);
dpll = I915_READ(dpll_reg);
if (dpll & DISPLAY_RATE_SELECT_FPA1)
DRM_DEBUG_DRIVER("failed to upclock LVDS!\n");
}
}
static void intel_decrease_pllclock(struct drm_crtc *crtc)
{
struct drm_device *dev = crtc->dev;
drm_i915_private_t *dev_priv = dev->dev_private;
struct intel_crtc *intel_crtc = to_intel_crtc(crtc);
if (HAS_PCH_SPLIT(dev))
return;
if (!dev_priv->lvds_downclock_avail)
return;
if (!HAS_PIPE_CXSR(dev) && intel_crtc->lowfreq_avail) {
int pipe = intel_crtc->pipe;
int dpll_reg = DPLL(pipe);
int dpll;
DRM_DEBUG_DRIVER("downclocking LVDS\n");
assert_panel_unlocked(dev_priv, pipe);
dpll = I915_READ(dpll_reg);
dpll |= DISPLAY_RATE_SELECT_FPA1;
I915_WRITE(dpll_reg, dpll);
intel_wait_for_vblank(dev, pipe);
dpll = I915_READ(dpll_reg);
if (!(dpll & DISPLAY_RATE_SELECT_FPA1))
DRM_DEBUG_DRIVER("failed to downclock LVDS!\n");
}
}
void intel_mark_busy(struct drm_device *dev)
{
i915_update_gfx_val(dev->dev_private);
}
void intel_mark_idle(struct drm_device *dev)
{
}
void intel_mark_fb_busy(struct drm_i915_gem_object *obj)
{
struct drm_device *dev = obj->base.dev;
struct drm_crtc *crtc;
if (!i915_powersave)
return;
list_for_each_entry(crtc, &dev->mode_config.crtc_list, head) {
if (!crtc->fb)
continue;
if (to_intel_framebuffer(crtc->fb)->obj == obj)
intel_increase_pllclock(crtc);
}
}
void intel_mark_fb_idle(struct drm_i915_gem_object *obj)
{
struct drm_device *dev = obj->base.dev;
struct drm_crtc *crtc;
if (!i915_powersave)
return;
list_for_each_entry(crtc, &dev->mode_config.crtc_list, head) {
if (!crtc->fb)
continue;
if (to_intel_framebuffer(crtc->fb)->obj == obj)
intel_decrease_pllclock(crtc);
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
struct drm_device *dev = work->crtc->dev;
mutex_lock(&dev->struct_mutex);
intel_unpin_fb_obj(work->old_fb_obj);
drm_gem_object_unreference(&work->pending_flip_obj->base);
drm_gem_object_unreference(&work->old_fb_obj->base);
intel_update_fbc(dev);
mutex_unlock(&dev->struct_mutex);
BUG_ON(atomic_read(&to_intel_crtc(work->crtc)->unpin_work_count) == 0);
atomic_dec(&to_intel_crtc(work->crtc)->unpin_work_count);
kfree(work);
}
static void do_intel_finish_page_flip(struct drm_device *dev,
struct drm_crtc *crtc)
{
drm_i915_private_t *dev_priv = dev->dev_private;
struct intel_crtc *intel_crtc = to_intel_crtc(crtc);
struct intel_unpin_work *work;
struct drm_i915_gem_object *obj;
unsigned long flags;
if (intel_crtc == NULL)
return;
spin_lock_irqsave(&dev->event_lock, flags);
work = intel_crtc->unpin_work;
smp_rmb();
if (work == NULL || atomic_read(&work->pending) < INTEL_FLIP_COMPLETE) {
spin_unlock_irqrestore(&dev->event_lock, flags);
return;
}
smp_rmb();
intel_crtc->unpin_work = NULL;
if (work->event)
drm_send_vblank_event(dev, intel_crtc->pipe, work->event);
drm_vblank_put(dev, intel_crtc->pipe);
spin_unlock_irqrestore(&dev->event_lock, flags);
obj = work->old_fb_obj;
atomic_clear_mask(1 << intel_crtc->plane,
&obj->pending_flip.counter);
wake_up(&dev_priv->pending_flip_queue);
queue_work(dev_priv->wq, &work->work);
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
if (intel_crtc->unpin_work)
atomic_inc_not_zero(&intel_crtc->unpin_work->pending);
spin_unlock_irqrestore(&dev->event_lock, flags);
}
inline static void intel_mark_page_flip_active(struct intel_crtc *intel_crtc)
{
smp_wmb();
atomic_set(&intel_crtc->unpin_work->pending, INTEL_FLIP_PENDING);
smp_wmb();
}
static int intel_gen2_queue_flip(struct drm_device *dev,
struct drm_crtc *crtc,
struct drm_framebuffer *fb,
struct drm_i915_gem_object *obj)
{
struct drm_i915_private *dev_priv = dev->dev_private;
struct intel_crtc *intel_crtc = to_intel_crtc(crtc);
u32 flip_mask;
struct intel_ring_buffer *ring = &dev_priv->ring[RCS];
int ret;
ret = intel_pin_and_fence_fb_obj(dev, obj, ring);
if (ret)
goto err;
ret = intel_ring_begin(ring, 6);
if (ret)
goto err_unpin;
if (intel_crtc->plane)
flip_mask = MI_WAIT_FOR_PLANE_B_FLIP;
else
flip_mask = MI_WAIT_FOR_PLANE_A_FLIP;
intel_ring_emit(ring, MI_WAIT_FOR_EVENT | flip_mask);
intel_ring_emit(ring, MI_NOOP);
intel_ring_emit(ring, MI_DISPLAY_FLIP |
MI_DISPLAY_FLIP_PLANE(intel_crtc->plane));
intel_ring_emit(ring, fb->pitches[0]);
intel_ring_emit(ring, obj->gtt_offset + intel_crtc->dspaddr_offset);
intel_ring_emit(ring, 0);
intel_mark_page_flip_active(intel_crtc);
intel_ring_advance(ring);
return 0;
err_unpin:
intel_unpin_fb_obj(obj);
err:
return ret;
}
static int intel_gen3_queue_flip(struct drm_device *dev,
struct drm_crtc *crtc,
struct drm_framebuffer *fb,
struct drm_i915_gem_object *obj)
{
struct drm_i915_private *dev_priv = dev->dev_private;
struct intel_crtc *intel_crtc = to_intel_crtc(crtc);
u32 flip_mask;
struct intel_ring_buffer *ring = &dev_priv->ring[RCS];
int ret;
ret = intel_pin_and_fence_fb_obj(dev, obj, ring);
if (ret)
goto err;
ret = intel_ring_begin(ring, 6);
if (ret)
goto err_unpin;
if (intel_crtc->plane)
flip_mask = MI_WAIT_FOR_PLANE_B_FLIP;
else
flip_mask = MI_WAIT_FOR_PLANE_A_FLIP;
intel_ring_emit(ring, MI_WAIT_FOR_EVENT | flip_mask);
intel_ring_emit(ring, MI_NOOP);
intel_ring_emit(ring, MI_DISPLAY_FLIP_I915 |
MI_DISPLAY_FLIP_PLANE(intel_crtc->plane));
intel_ring_emit(ring, fb->pitches[0]);
intel_ring_emit(ring, obj->gtt_offset + intel_crtc->dspaddr_offset);
intel_ring_emit(ring, MI_NOOP);
intel_mark_page_flip_active(intel_crtc);
intel_ring_advance(ring);
return 0;
err_unpin:
intel_unpin_fb_obj(obj);
err:
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
struct intel_ring_buffer *ring = &dev_priv->ring[RCS];
int ret;
ret = intel_pin_and_fence_fb_obj(dev, obj, ring);
if (ret)
goto err;
ret = intel_ring_begin(ring, 4);
if (ret)
goto err_unpin;
intel_ring_emit(ring, MI_DISPLAY_FLIP |
MI_DISPLAY_FLIP_PLANE(intel_crtc->plane));
intel_ring_emit(ring, fb->pitches[0]);
intel_ring_emit(ring,
(obj->gtt_offset + intel_crtc->dspaddr_offset) |
obj->tiling_mode);
pf = 0;
pipesrc = I915_READ(PIPESRC(intel_crtc->pipe)) & 0x0fff0fff;
intel_ring_emit(ring, pf | pipesrc);
intel_mark_page_flip_active(intel_crtc);
intel_ring_advance(ring);
return 0;
err_unpin:
intel_unpin_fb_obj(obj);
err:
return ret;
}
static int intel_gen6_queue_flip(struct drm_device *dev,
struct drm_crtc *crtc,
struct drm_framebuffer *fb,
struct drm_i915_gem_object *obj)
{
struct drm_i915_private *dev_priv = dev->dev_private;
struct intel_crtc *intel_crtc = to_intel_crtc(crtc);
struct intel_ring_buffer *ring = &dev_priv->ring[RCS];
uint32_t pf, pipesrc;
int ret;
ret = intel_pin_and_fence_fb_obj(dev, obj, ring);
if (ret)
goto err;
ret = intel_ring_begin(ring, 4);
if (ret)
goto err_unpin;
intel_ring_emit(ring, MI_DISPLAY_FLIP |
MI_DISPLAY_FLIP_PLANE(intel_crtc->plane));
intel_ring_emit(ring, fb->pitches[0] | obj->tiling_mode);
intel_ring_emit(ring, obj->gtt_offset + intel_crtc->dspaddr_offset);
pf = 0;
pipesrc = I915_READ(PIPESRC(intel_crtc->pipe)) & 0x0fff0fff;
intel_ring_emit(ring, pf | pipesrc);
intel_mark_page_flip_active(intel_crtc);
intel_ring_advance(ring);
return 0;
err_unpin:
intel_unpin_fb_obj(obj);
err:
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
uint32_t plane_bit = 0;
int ret;
ret = intel_pin_and_fence_fb_obj(dev, obj, ring);
if (ret)
goto err;
switch(intel_crtc->plane) {
case PLANE_A:
plane_bit = MI_DISPLAY_FLIP_IVB_PLANE_A;
break;
case PLANE_B:
plane_bit = MI_DISPLAY_FLIP_IVB_PLANE_B;
break;
case PLANE_C:
plane_bit = MI_DISPLAY_FLIP_IVB_PLANE_C;
break;
default:
WARN_ONCE(1, "unknown plane in flip command\n");
ret = -ENODEV;
goto err_unpin;
}
ret = intel_ring_begin(ring, 4);
if (ret)
goto err_unpin;
intel_ring_emit(ring, MI_DISPLAY_FLIP_I915 | plane_bit);
intel_ring_emit(ring, (fb->pitches[0] | obj->tiling_mode));
intel_ring_emit(ring, obj->gtt_offset + intel_crtc->dspaddr_offset);
intel_ring_emit(ring, (MI_NOOP));
intel_mark_page_flip_active(intel_crtc);
intel_ring_advance(ring);
return 0;
err_unpin:
intel_unpin_fb_obj(obj);
err:
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
if (fb->pixel_format != crtc->fb->pixel_format)
return -EINVAL;
if (INTEL_INFO(dev)->gen > 3 &&
(fb->offsets[0] != crtc->fb->offsets[0] ||
fb->pitches[0] != crtc->fb->pitches[0]))
return -EINVAL;
work = kzalloc(sizeof *work, GFP_KERNEL);
if (work == NULL)
return -ENOMEM;
work->event = event;
work->crtc = crtc;
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
if (atomic_read(&intel_crtc->unpin_work_count) >= 2)
flush_workqueue(dev_priv->wq);
ret = i915_mutex_lock_interruptible(dev);
if (ret)
goto cleanup;
drm_gem_object_reference(&work->old_fb_obj->base);
drm_gem_object_reference(&obj->base);
crtc->fb = fb;
work->pending_flip_obj = obj;
work->enable_stall_check = true;
atomic_add(1 << intel_crtc->plane, &work->old_fb_obj->pending_flip);
atomic_inc(&intel_crtc->unpin_work_count);
ret = dev_priv->display.queue_flip(dev, crtc, fb, obj);
if (ret)
goto cleanup_pending;
intel_disable_fbc(dev);
intel_mark_fb_busy(obj);
mutex_unlock(&dev->struct_mutex);
trace_i915_flip_request(intel_crtc->plane, obj);
return 0;
cleanup_pending:
atomic_dec(&intel_crtc->unpin_work_count);
atomic_sub(1 << intel_crtc->plane, &work->old_fb_obj->pending_flip);
drm_gem_object_unreference(&work->old_fb_obj->base);
drm_gem_object_unreference(&obj->base);
mutex_unlock(&dev->struct_mutex);
cleanup:
spin_lock_irqsave(&dev->event_lock, flags);
intel_crtc->unpin_work = NULL;
spin_unlock_irqrestore(&dev->event_lock, flags);
drm_vblank_put(dev, intel_crtc->pipe);
free_work:
kfree(work);
return ret;
}
bool intel_encoder_check_is_cloned(struct intel_encoder *encoder)
{
struct intel_encoder *other_encoder;
struct drm_crtc *crtc = &encoder->new_crtc->base;
if (WARN_ON(!crtc))
return false;
list_for_each_entry(other_encoder,
&crtc->dev->mode_config.encoder_list,
base.head) {
if (&other_encoder->new_crtc->base != crtc ||
encoder == other_encoder)
continue;
else
return true;
}
return false;
}
static bool intel_encoder_crtc_ok(struct drm_encoder *encoder,
struct drm_crtc *crtc)
{
struct drm_device *dev;
struct drm_crtc *tmp;
int crtc_mask = 1;
WARN(!crtc, "checking null crtc?\n");
dev = crtc->dev;
list_for_each_entry(tmp, &dev->mode_config.crtc_list, head) {
if (tmp == crtc)
break;
crtc_mask <<= 1;
}
if (encoder->possible_crtcs & crtc_mask)
return true;
return false;
}
static void intel_modeset_update_staged_output_state(struct drm_device *dev)
{
struct intel_encoder *encoder;
struct intel_connector *connector;
list_for_each_entry(connector, &dev->mode_config.connector_list,
base.head) {
connector->new_encoder =
to_intel_encoder(connector->base.encoder);
}
list_for_each_entry(encoder, &dev->mode_config.encoder_list,
base.head) {
encoder->new_crtc =
to_intel_crtc(encoder->base.crtc);
}
}
static void intel_modeset_commit_output_state(struct drm_device *dev)
{
struct intel_encoder *encoder;
struct intel_connector *connector;
list_for_each_entry(connector, &dev->mode_config.connector_list,
base.head) {
connector->base.encoder = &connector->new_encoder->base;
}
list_for_each_entry(encoder, &dev->mode_config.encoder_list,
base.head) {
encoder->base.crtc = &encoder->new_crtc->base;
}
}
static struct drm_display_mode *
intel_modeset_adjusted_mode(struct drm_crtc *crtc,
struct drm_display_mode *mode)
{
struct drm_device *dev = crtc->dev;
struct drm_display_mode *adjusted_mode;
struct drm_encoder_helper_funcs *encoder_funcs;
struct intel_encoder *encoder;
adjusted_mode = drm_mode_duplicate(dev, mode);
if (!adjusted_mode)
return ERR_PTR(-ENOMEM);
list_for_each_entry(encoder, &dev->mode_config.encoder_list,
base.head) {
if (&encoder->new_crtc->base != crtc)
continue;
encoder_funcs = encoder->base.helper_private;
if (!(encoder_funcs->mode_fixup(&encoder->base, mode,
adjusted_mode))) {
DRM_DEBUG_KMS("Encoder fixup failed\n");
goto fail;
}
}
if (!(intel_crtc_mode_fixup(crtc, mode, adjusted_mode))) {
DRM_DEBUG_KMS("CRTC fixup failed\n");
goto fail;
}
DRM_DEBUG_KMS("[CRTC:%d]\n", crtc->base.id);
return adjusted_mode;
fail:
drm_mode_destroy(dev, adjusted_mode);
return ERR_PTR(-EINVAL);
}
static void
intel_modeset_affected_pipes(struct drm_crtc *crtc, unsigned *modeset_pipes,
unsigned *prepare_pipes, unsigned *disable_pipes)
{
struct intel_crtc *intel_crtc;
struct drm_device *dev = crtc->dev;
struct intel_encoder *encoder;
struct intel_connector *connector;
struct drm_crtc *tmp_crtc;
*disable_pipes = *modeset_pipes = *prepare_pipes = 0;
list_for_each_entry(connector, &dev->mode_config.connector_list,
base.head) {
if (connector->base.encoder == &connector->new_encoder->base)
continue;
if (connector->base.encoder) {
tmp_crtc = connector->base.encoder->crtc;
*prepare_pipes |= 1 << to_intel_crtc(tmp_crtc)->pipe;
}
if (connector->new_encoder)
*prepare_pipes |=
1 << connector->new_encoder->new_crtc->pipe;
}
list_for_each_entry(encoder, &dev->mode_config.encoder_list,
base.head) {
if (encoder->base.crtc == &encoder->new_crtc->base)
continue;
if (encoder->base.crtc) {
tmp_crtc = encoder->base.crtc;
*prepare_pipes |= 1 << to_intel_crtc(tmp_crtc)->pipe;
}
if (encoder->new_crtc)
*prepare_pipes |= 1 << encoder->new_crtc->pipe;
}
list_for_each_entry(intel_crtc, &dev->mode_config.crtc_list,
base.head) {
bool used = false;
if (!intel_crtc->base.enabled)
continue;
list_for_each_entry(encoder, &dev->mode_config.encoder_list,
base.head) {
if (encoder->new_crtc == intel_crtc)
used = true;
}
if (!used)
*disable_pipes |= 1 << intel_crtc->pipe;
}
intel_crtc = to_intel_crtc(crtc);
if (crtc->enabled)
*prepare_pipes |= 1 << intel_crtc->pipe;
if (*prepare_pipes)
*modeset_pipes = *prepare_pipes;
*modeset_pipes &= ~(*disable_pipes);
*prepare_pipes &= ~(*disable_pipes);
}
static bool intel_crtc_in_use(struct drm_crtc *crtc)
{
struct drm_encoder *encoder;
struct drm_device *dev = crtc->dev;
list_for_each_entry(encoder, &dev->mode_config.encoder_list, head)
if (encoder->crtc == crtc)
return true;
return false;
}
static void
intel_modeset_update_state(struct drm_device *dev, unsigned prepare_pipes)
{
struct intel_encoder *intel_encoder;
struct intel_crtc *intel_crtc;
struct drm_connector *connector;
list_for_each_entry(intel_encoder, &dev->mode_config.encoder_list,
base.head) {
if (!intel_encoder->base.crtc)
continue;
intel_crtc = to_intel_crtc(intel_encoder->base.crtc);
if (prepare_pipes & (1 << intel_crtc->pipe))
intel_encoder->connectors_active = false;
}
intel_modeset_commit_output_state(dev);
list_for_each_entry(intel_crtc, &dev->mode_config.crtc_list,
base.head) {
intel_crtc->base.enabled = intel_crtc_in_use(&intel_crtc->base);
}
list_for_each_entry(connector, &dev->mode_config.connector_list, head) {
if (!connector->encoder || !connector->encoder->crtc)
continue;
intel_crtc = to_intel_crtc(connector->encoder->crtc);
if (prepare_pipes & (1 << intel_crtc->pipe)) {
struct drm_property *dpms_property =
dev->mode_config.dpms_property;
connector->dpms = DRM_MODE_DPMS_ON;
drm_object_property_set_value(&connector->base,
dpms_property,
DRM_MODE_DPMS_ON);
intel_encoder = to_intel_encoder(connector->encoder);
intel_encoder->connectors_active = true;
}
}
}
bool intel_set_mode(struct drm_crtc *crtc,
struct drm_display_mode *mode,
int x, int y, struct drm_framebuffer *fb)
{
struct drm_device *dev = crtc->dev;
drm_i915_private_t *dev_priv = dev->dev_private;
struct drm_display_mode *adjusted_mode, saved_mode, saved_hwmode;
struct intel_crtc *intel_crtc;
unsigned disable_pipes, prepare_pipes, modeset_pipes;
bool ret = true;
intel_modeset_affected_pipes(crtc, &modeset_pipes,
&prepare_pipes, &disable_pipes);
DRM_DEBUG_KMS("set mode pipe masks: modeset: %x, prepare: %x, disable: %x\n",
modeset_pipes, prepare_pipes, disable_pipes);
for_each_intel_crtc_masked(dev, disable_pipes, intel_crtc)
intel_crtc_disable(&intel_crtc->base);
saved_hwmode = crtc->hwmode;
saved_mode = crtc->mode;
adjusted_mode = NULL;
if (modeset_pipes) {
adjusted_mode = intel_modeset_adjusted_mode(crtc, mode);
if (IS_ERR(adjusted_mode)) {
return false;
}
}
for_each_intel_crtc_masked(dev, prepare_pipes, intel_crtc) {
if (intel_crtc->base.enabled)
dev_priv->display.crtc_disable(&intel_crtc->base);
}
if (modeset_pipes)
crtc->mode = *mode;
intel_modeset_update_state(dev, prepare_pipes);
if (dev_priv->display.modeset_global_resources)
dev_priv->display.modeset_global_resources(dev);
for_each_intel_crtc_masked(dev, modeset_pipes, intel_crtc) {
ret = !intel_crtc_mode_set(&intel_crtc->base,
mode, adjusted_mode,
x, y, fb);
if (!ret)
goto done;
}
for_each_intel_crtc_masked(dev, prepare_pipes, intel_crtc)
dev_priv->display.crtc_enable(&intel_crtc->base);
if (modeset_pipes) {
crtc->hwmode = *adjusted_mode;
drm_calc_timestamping_constants(crtc);
}
done:
drm_mode_destroy(dev, adjusted_mode);
if (!ret && crtc->enabled) {
crtc->hwmode = saved_hwmode;
crtc->mode = saved_mode;
} else {
intel_modeset_check_state(dev);
}
return ret;
}
static void intel_set_config_free(struct intel_set_config *config)
{
if (!config)
return;
kfree(config->save_connector_encoders);
kfree(config->save_encoder_crtcs);
kfree(config);
}
static int intel_set_config_save_state(struct drm_device *dev,
struct intel_set_config *config)
{
struct drm_encoder *encoder;
struct drm_connector *connector;
int count;
config->save_encoder_crtcs =
kcalloc(dev->mode_config.num_encoder,
sizeof(struct drm_crtc *), GFP_KERNEL);
if (!config->save_encoder_crtcs)
return -ENOMEM;
config->save_connector_encoders =
kcalloc(dev->mode_config.num_connector,
sizeof(struct drm_encoder *), GFP_KERNEL);
if (!config->save_connector_encoders)
return -ENOMEM;
count = 0;
list_for_each_entry(encoder, &dev->mode_config.encoder_list, head) {
config->save_encoder_crtcs[count++] = encoder->crtc;
}
count = 0;
list_for_each_entry(connector, &dev->mode_config.connector_list, head) {
config->save_connector_encoders[count++] = connector->encoder;
}
return 0;
}
static void intel_set_config_restore_state(struct drm_device *dev,
struct intel_set_config *config)
{
struct intel_encoder *encoder;
struct intel_connector *connector;
int count;
count = 0;
list_for_each_entry(encoder, &dev->mode_config.encoder_list, base.head) {
encoder->new_crtc =
to_intel_crtc(config->save_encoder_crtcs[count++]);
}
count = 0;
list_for_each_entry(connector, &dev->mode_config.connector_list, base.head) {
connector->new_encoder =
to_intel_encoder(config->save_connector_encoders[count++]);
}
}
static void
intel_set_config_compute_mode_changes(struct drm_mode_set *set,
struct intel_set_config *config)
{
if (set->crtc->fb != set->fb) {
if (set->crtc->fb == NULL) {
DRM_DEBUG_KMS("crtc has no fb, full mode set\n");
config->mode_changed = true;
} else if (set->fb == NULL) {
config->mode_changed = true;
} else if (set->fb->depth != set->crtc->fb->depth) {
config->mode_changed = true;
} else if (set->fb->bits_per_pixel !=
set->crtc->fb->bits_per_pixel) {
config->mode_changed = true;
} else
config->fb_changed = true;
}
if (set->fb && (set->x != set->crtc->x || set->y != set->crtc->y))
config->fb_changed = true;
if (set->mode && !drm_mode_equal(set->mode, &set->crtc->mode)) {
DRM_DEBUG_KMS("modes are different, full mode set\n");
drm_mode_debug_printmodeline(&set->crtc->mode);
drm_mode_debug_printmodeline(set->mode);
config->mode_changed = true;
}
}
static int
intel_modeset_stage_output_state(struct drm_device *dev,
struct drm_mode_set *set,
struct intel_set_config *config)
{
struct drm_crtc *new_crtc;
struct intel_connector *connector;
struct intel_encoder *encoder;
int count, ro;
WARN_ON(!set->fb && (set->num_connectors != 0));
WARN_ON(set->fb && (set->num_connectors == 0));
count = 0;
list_for_each_entry(connector, &dev->mode_config.connector_list,
base.head) {
for (ro = 0; ro < set->num_connectors; ro++) {
if (set->connectors[ro] == &connector->base) {
connector->new_encoder = connector->encoder;
break;
}
}
if ((!set->fb || ro == set->num_connectors) &&
connector->base.encoder &&
connector->base.encoder->crtc == set->crtc) {
connector->new_encoder = NULL;
DRM_DEBUG_KMS("[CONNECTOR:%d:%s] to [NOCRTC]\n",
connector->base.base.id,
drm_get_connector_name(&connector->base));
}
if (&connector->new_encoder->base != connector->base.encoder) {
DRM_DEBUG_KMS("encoder changed, full mode switch\n");
config->mode_changed = true;
}
}
count = 0;
list_for_each_entry(connector, &dev->mode_config.connector_list,
base.head) {
if (!connector->new_encoder)
continue;
new_crtc = connector->new_encoder->base.crtc;
for (ro = 0; ro < set->num_connectors; ro++) {
if (set->connectors[ro] == &connector->base)
new_crtc = set->crtc;
}
if (!intel_encoder_crtc_ok(&connector->new_encoder->base,
new_crtc)) {
return -EINVAL;
}
connector->encoder->new_crtc = to_intel_crtc(new_crtc);
DRM_DEBUG_KMS("[CONNECTOR:%d:%s] to [CRTC:%d]\n",
connector->base.base.id,
drm_get_connector_name(&connector->base),
new_crtc->base.id);
}
list_for_each_entry(encoder, &dev->mode_config.encoder_list,
base.head) {
list_for_each_entry(connector,
&dev->mode_config.connector_list,
base.head) {
if (connector->new_encoder == encoder) {
WARN_ON(!connector->new_encoder->new_crtc);
goto next_encoder;
}
}
encoder->new_crtc = NULL;
next_encoder:
if (&encoder->new_crtc->base != encoder->base.crtc) {
DRM_DEBUG_KMS("crtc changed, full mode switch\n");
config->mode_changed = true;
}
}
return 0;
}
static int intel_crtc_set_config(struct drm_mode_set *set)
{
struct drm_device *dev;
struct drm_mode_set save_set;
struct intel_set_config *config;
int ret;
BUG_ON(!set);
BUG_ON(!set->crtc);
BUG_ON(!set->crtc->helper_private);
if (!set->mode)
set->fb = NULL;
if (set->fb && set->num_connectors == 0)
return 0;
if (set->fb) {
DRM_DEBUG_KMS("[CRTC:%d] [FB:%d] #connectors=%d (x y) (%i %i)\n",
set->crtc->base.id, set->fb->base.id,
(int)set->num_connectors, set->x, set->y);
} else {
DRM_DEBUG_KMS("[CRTC:%d] [NOFB]\n", set->crtc->base.id);
}
dev = set->crtc->dev;
ret = -ENOMEM;
config = kzalloc(sizeof(*config), GFP_KERNEL);
if (!config)
goto out_config;
ret = intel_set_config_save_state(dev, config);
if (ret)
goto out_config;
save_set.crtc = set->crtc;
save_set.mode = &set->crtc->mode;
save_set.x = set->crtc->x;
save_set.y = set->crtc->y;
save_set.fb = set->crtc->fb;
intel_set_config_compute_mode_changes(set, config);
ret = intel_modeset_stage_output_state(dev, set, config);
if (ret)
goto fail;
if (config->mode_changed) {
if (set->mode) {
DRM_DEBUG_KMS("attempting to set mode from"
" userspace\n");
drm_mode_debug_printmodeline(set->mode);
}
if (!intel_set_mode(set->crtc, set->mode,
set->x, set->y, set->fb)) {
DRM_ERROR("failed to set mode on [CRTC:%d]\n",
set->crtc->base.id);
ret = -EINVAL;
goto fail;
}
} else if (config->fb_changed) {
ret = intel_pipe_set_base(set->crtc,
set->x, set->y, set->fb);
}
intel_set_config_free(config);
return 0;
fail:
intel_set_config_restore_state(dev, config);
if (config->mode_changed &&
!intel_set_mode(save_set.crtc, save_set.mode,
save_set.x, save_set.y, save_set.fb))
DRM_ERROR("failed to restore config after modeset failure\n");
out_config:
intel_set_config_free(config);
return ret;
}
static void intel_cpu_pll_init(struct drm_device *dev)
{
if (IS_HASWELL(dev))
intel_ddi_pll_init(dev);
}
static void intel_pch_pll_init(struct drm_device *dev)
{
drm_i915_private_t *dev_priv = dev->dev_private;
int i;
if (dev_priv->num_pch_pll == 0) {
DRM_DEBUG_KMS("No PCH PLLs on this hardware, skipping initialisation\n");
return;
}
for (i = 0; i < dev_priv->num_pch_pll; i++) {
dev_priv->pch_plls[i].pll_reg = _PCH_DPLL(i);
dev_priv->pch_plls[i].fp0_reg = _PCH_FP0(i);
dev_priv->pch_plls[i].fp1_reg = _PCH_FP1(i);
}
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
intel_crtc->cpu_transcoder = pipe;
if (IS_MOBILE(dev) && IS_GEN3(dev)) {
DRM_DEBUG_KMS("swapping pipes & planes for FBC\n");
intel_crtc->plane = !pipe;
}
BUG_ON(pipe >= ARRAY_SIZE(dev_priv->plane_to_crtc_mapping) ||
dev_priv->plane_to_crtc_mapping[intel_crtc->plane] != NULL);
dev_priv->plane_to_crtc_mapping[intel_crtc->plane] = &intel_crtc->base;
dev_priv->pipe_to_crtc_mapping[intel_crtc->pipe] = &intel_crtc->base;
intel_crtc->bpp = 24;
drm_crtc_helper_add(&intel_crtc->base, &intel_helper_funcs);
}
int intel_get_pipe_from_crtc_id(struct drm_device *dev, void *data,
struct drm_file *file)
{
struct drm_i915_get_pipe_from_crtc_id *pipe_from_crtc_id = data;
struct drm_mode_object *drmmode_obj;
struct intel_crtc *crtc;
if (!drm_core_check_feature(dev, DRIVER_MODESET))
return -ENODEV;
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
static int intel_encoder_clones(struct intel_encoder *encoder)
{
struct drm_device *dev = encoder->base.dev;
struct intel_encoder *source_encoder;
int index_mask = 0;
int entry = 0;
list_for_each_entry(source_encoder,
&dev->mode_config.encoder_list, base.head) {
if (encoder == source_encoder)
index_mask |= (1 << entry);
if (encoder->cloneable && source_encoder->cloneable)
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
bool has_lvds;
has_lvds = intel_lvds_init(dev);
if (!has_lvds && !HAS_PCH_SPLIT(dev)) {
I915_WRITE(PFIT_CONTROL, 0);
}
if (!(IS_HASWELL(dev) &&
(I915_READ(DDI_BUF_CTL(PORT_A)) & DDI_A_4_LANES)))
intel_crt_init(dev);
if (IS_HASWELL(dev)) {
int found;
found = I915_READ(DDI_BUF_CTL_A) & DDI_INIT_DISPLAY_DETECTED;
if (found)
intel_ddi_init(dev, PORT_A);
found = I915_READ(SFUSE_STRAP);
if (found & SFUSE_STRAP_DDIB_DETECTED)
intel_ddi_init(dev, PORT_B);
if (found & SFUSE_STRAP_DDIC_DETECTED)
intel_ddi_init(dev, PORT_C);
if (found & SFUSE_STRAP_DDID_DETECTED)
intel_ddi_init(dev, PORT_D);
} else if (HAS_PCH_SPLIT(dev)) {
int found;
dpd_is_edp = intel_dpd_is_edp(dev);
if (has_edp_a(dev))
intel_dp_init(dev, DP_A, PORT_A);
if (I915_READ(HDMIB) & PORT_DETECTED) {
found = intel_sdvo_init(dev, PCH_SDVOB, true);
if (!found)
intel_hdmi_init(dev, HDMIB, PORT_B);
if (!found && (I915_READ(PCH_DP_B) & DP_DETECTED))
intel_dp_init(dev, PCH_DP_B, PORT_B);
}
if (I915_READ(HDMIC) & PORT_DETECTED)
intel_hdmi_init(dev, HDMIC, PORT_C);
if (!dpd_is_edp && I915_READ(HDMID) & PORT_DETECTED)
intel_hdmi_init(dev, HDMID, PORT_D);
if (I915_READ(PCH_DP_C) & DP_DETECTED)
intel_dp_init(dev, PCH_DP_C, PORT_C);
if (I915_READ(PCH_DP_D) & DP_DETECTED)
intel_dp_init(dev, PCH_DP_D, PORT_D);
} else if (IS_VALLEYVIEW(dev)) {
int found;
if (I915_READ(DP_C) & DP_DETECTED)
intel_dp_init(dev, DP_C, PORT_C);
if (I915_READ(SDVOB) & PORT_DETECTED) {
found = intel_sdvo_init(dev, SDVOB, true);
if (!found)
intel_hdmi_init(dev, SDVOB, PORT_B);
if (!found && (I915_READ(DP_B) & DP_DETECTED))
intel_dp_init(dev, DP_B, PORT_B);
}
if (I915_READ(SDVOC) & PORT_DETECTED)
intel_hdmi_init(dev, SDVOC, PORT_C);
} else if (SUPPORTS_DIGITAL_OUTPUTS(dev)) {
bool found = false;
if (I915_READ(SDVOB) & SDVO_DETECTED) {
DRM_DEBUG_KMS("probing SDVOB\n");
found = intel_sdvo_init(dev, SDVOB, true);
if (!found && SUPPORTS_INTEGRATED_HDMI(dev)) {
DRM_DEBUG_KMS("probing HDMI on SDVOB\n");
intel_hdmi_init(dev, SDVOB, PORT_B);
}
if (!found && SUPPORTS_INTEGRATED_DP(dev)) {
DRM_DEBUG_KMS("probing DP_B\n");
intel_dp_init(dev, DP_B, PORT_B);
}
}
if (I915_READ(SDVOB) & SDVO_DETECTED) {
DRM_DEBUG_KMS("probing SDVOC\n");
found = intel_sdvo_init(dev, SDVOC, false);
}
if (!found && (I915_READ(SDVOC) & SDVO_DETECTED)) {
if (SUPPORTS_INTEGRATED_HDMI(dev)) {
DRM_DEBUG_KMS("probing HDMI on SDVOC\n");
intel_hdmi_init(dev, SDVOC, PORT_C);
}
if (SUPPORTS_INTEGRATED_DP(dev)) {
DRM_DEBUG_KMS("probing DP_C\n");
intel_dp_init(dev, DP_C, PORT_C);
}
}
if (SUPPORTS_INTEGRATED_DP(dev) &&
(I915_READ(DP_D) & DP_DETECTED)) {
DRM_DEBUG_KMS("probing DP_D\n");
intel_dp_init(dev, DP_D, PORT_D);
}
} else if (IS_GEN2(dev))
intel_dvo_init(dev);
if (SUPPORTS_TV(dev))
intel_tv_init(dev);
list_for_each_entry(encoder, &dev->mode_config.encoder_list, base.head) {
encoder->base.possible_crtcs = encoder->crtc_mask;
encoder->base.possible_clones =
intel_encoder_clones(encoder);
}
intel_init_pch_refclk(dev);
drm_helper_move_panel_connectors_to_head(dev);
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
if (obj->tiling_mode == I915_TILING_Y) {
DRM_DEBUG("hardware does not support tiling Y\n");
return -EINVAL;
}
if (mode_cmd->pitches[0] & 63) {
DRM_DEBUG("pitch (%d) must be at least 64 byte aligned\n",
mode_cmd->pitches[0]);
return -EINVAL;
}
if (mode_cmd->pitches[0] > 32768) {
DRM_DEBUG("pitch (%d) must be at less than 32768\n",
mode_cmd->pitches[0]);
return -EINVAL;
}
if (obj->tiling_mode != I915_TILING_NONE &&
mode_cmd->pitches[0] != obj->stride) {
DRM_DEBUG("pitch (%d) must match tiling stride (%d)\n",
mode_cmd->pitches[0], obj->stride);
return -EINVAL;
}
switch (mode_cmd->pixel_format) {
case DRM_FORMAT_C8:
case DRM_FORMAT_RGB565:
case DRM_FORMAT_XRGB8888:
case DRM_FORMAT_ARGB8888:
break;
case DRM_FORMAT_XRGB1555:
case DRM_FORMAT_ARGB1555:
if (INTEL_INFO(dev)->gen > 3) {
DRM_DEBUG("invalid format: 0x%08x\n", mode_cmd->pixel_format);
return -EINVAL;
}
break;
case DRM_FORMAT_XBGR8888:
case DRM_FORMAT_ABGR8888:
case DRM_FORMAT_XRGB2101010:
case DRM_FORMAT_ARGB2101010:
case DRM_FORMAT_XBGR2101010:
case DRM_FORMAT_ABGR2101010:
if (INTEL_INFO(dev)->gen < 4) {
DRM_DEBUG("invalid format: 0x%08x\n", mode_cmd->pixel_format);
return -EINVAL;
}
break;
case DRM_FORMAT_YUYV:
case DRM_FORMAT_UYVY:
case DRM_FORMAT_YVYU:
case DRM_FORMAT_VYUY:
if (INTEL_INFO(dev)->gen < 5) {
DRM_DEBUG("invalid format: 0x%08x\n", mode_cmd->pixel_format);
return -EINVAL;
}
break;
default:
DRM_DEBUG("unsupported pixel format 0x%08x\n", mode_cmd->pixel_format);
return -EINVAL;
}
if (mode_cmd->offsets[0] != 0)
return -EINVAL;
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
static void intel_init_display(struct drm_device *dev)
{
struct drm_i915_private *dev_priv = dev->dev_private;
if (IS_HASWELL(dev)) {
dev_priv->display.crtc_mode_set = haswell_crtc_mode_set;
dev_priv->display.crtc_enable = haswell_crtc_enable;
dev_priv->display.crtc_disable = haswell_crtc_disable;
dev_priv->display.off = haswell_crtc_off;
dev_priv->display.update_plane = ironlake_update_plane;
} else if (HAS_PCH_SPLIT(dev)) {
dev_priv->display.crtc_mode_set = ironlake_crtc_mode_set;
dev_priv->display.crtc_enable = ironlake_crtc_enable;
dev_priv->display.crtc_disable = ironlake_crtc_disable;
dev_priv->display.off = ironlake_crtc_off;
dev_priv->display.update_plane = ironlake_update_plane;
} else {
dev_priv->display.crtc_mode_set = i9xx_crtc_mode_set;
dev_priv->display.crtc_enable = i9xx_crtc_enable;
dev_priv->display.crtc_disable = i9xx_crtc_disable;
dev_priv->display.off = i9xx_crtc_off;
dev_priv->display.update_plane = i9xx_update_plane;
}
if (IS_VALLEYVIEW(dev))
dev_priv->display.get_display_clock_speed =
valleyview_get_display_clock_speed;
else if (IS_I945G(dev) || (IS_G33(dev) && !IS_PINEVIEW_M(dev)))
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
if (IS_GEN5(dev)) {
dev_priv->display.fdi_link_train = ironlake_fdi_link_train;
dev_priv->display.write_eld = ironlake_write_eld;
} else if (IS_GEN6(dev)) {
dev_priv->display.fdi_link_train = gen6_fdi_link_train;
dev_priv->display.write_eld = ironlake_write_eld;
} else if (IS_IVYBRIDGE(dev)) {
dev_priv->display.fdi_link_train = ivb_manual_fdi_link_train;
dev_priv->display.write_eld = ironlake_write_eld;
dev_priv->display.modeset_global_resources =
ivb_modeset_global_resources;
} else if (IS_HASWELL(dev)) {
dev_priv->display.fdi_link_train = hsw_fdi_link_train;
dev_priv->display.write_eld = haswell_write_eld;
} else
dev_priv->display.update_wm = NULL;
} else if (IS_G4X(dev)) {
dev_priv->display.write_eld = g4x_write_eld;
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
DRM_INFO("applying pipe a force quirk\n");
}
static void quirk_ssc_force_disable(struct drm_device *dev)
{
struct drm_i915_private *dev_priv = dev->dev_private;
dev_priv->quirks |= QUIRK_LVDS_SSC_DISABLE;
DRM_INFO("applying lvds SSC disable quirk\n");
}
static void quirk_invert_brightness(struct drm_device *dev)
{
struct drm_i915_private *dev_priv = dev->dev_private;
dev_priv->quirks |= QUIRK_INVERT_BRIGHTNESS;
DRM_INFO("applying inverted panel brightness quirk\n");
}
static int intel_dmi_reverse_brightness(const struct dmi_system_id *id)
{
DRM_INFO("Backlight polarity reversed on %s\n", id->ident);
return 1;
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
for (i = 0; i < ARRAY_SIZE(intel_dmi_quirks); i++) {
if (dmi_check_system(*intel_dmi_quirks[i].dmi_id_list) != 0)
intel_dmi_quirks[i].hook(dev);
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
outb(SR01, VGA_SR_INDEX);
sr1 = inb(VGA_SR_DATA);
outb(sr1 | 1<<5, VGA_SR_DATA);
vga_put(dev->pdev, VGA_RSRC_LEGACY_IO);
udelay(300);
I915_WRITE(vga_reg, VGA_DISP_DISABLE);
POSTING_READ(vga_reg);
}
void intel_modeset_init_hw(struct drm_device *dev)
{
intel_init_power_wells(dev);
intel_prepare_ddi(dev);
intel_init_clock_gating(dev);
mutex_lock(&dev->struct_mutex);
intel_enable_gt_powersave(dev);
mutex_unlock(&dev->struct_mutex);
}
void intel_modeset_init(struct drm_device *dev)
{
struct drm_i915_private *dev_priv = dev->dev_private;
int i, ret;
drm_mode_config_init(dev);
dev->mode_config.min_width = 0;
dev->mode_config.min_height = 0;
dev->mode_config.preferred_depth = 24;
dev->mode_config.prefer_shadow = 1;
dev->mode_config.funcs = &intel_mode_funcs;
intel_init_quirks(dev);
intel_init_pm(dev);
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
dev->mode_config.fb_base = dev_priv->mm.gtt_base_addr;
DRM_DEBUG_KMS("%d display pipe%s available.\n",
dev_priv->num_pipe, dev_priv->num_pipe > 1 ? "s" : "");
for (i = 0; i < dev_priv->num_pipe; i++) {
intel_crtc_init(dev, i);
ret = intel_plane_init(dev, i);
if (ret)
DRM_DEBUG_KMS("plane %d init failed: %d\n", i, ret);
}
intel_cpu_pll_init(dev);
intel_pch_pll_init(dev);
i915_disable_vga(dev);
intel_setup_outputs(dev);
}
static void
intel_connector_break_all_links(struct intel_connector *connector)
{
connector->base.dpms = DRM_MODE_DPMS_OFF;
connector->base.encoder = NULL;
connector->encoder->connectors_active = false;
connector->encoder->base.crtc = NULL;
}
static void intel_enable_pipe_a(struct drm_device *dev)
{
struct intel_connector *connector;
struct drm_connector *crt = NULL;
struct intel_load_detect_pipe load_detect_temp;
list_for_each_entry(connector,
&dev->mode_config.connector_list,
base.head) {
if (connector->encoder->type == INTEL_OUTPUT_ANALOG) {
crt = &connector->base;
break;
}
}
if (!crt)
return;
if (intel_get_load_detect_pipe(crt, NULL, &load_detect_temp))
intel_release_load_detect_pipe(crt, &load_detect_temp);
}
static bool
intel_check_plane_mapping(struct intel_crtc *crtc)
{
struct drm_i915_private *dev_priv = crtc->base.dev->dev_private;
u32 reg, val;
if (dev_priv->num_pipe == 1)
return true;
reg = DSPCNTR(!crtc->plane);
val = I915_READ(reg);
if ((val & DISPLAY_PLANE_ENABLE) &&
(!!(val & DISPPLANE_SEL_PIPE_MASK) == crtc->pipe))
return false;
return true;
}
static void intel_sanitize_crtc(struct intel_crtc *crtc)
{
struct drm_device *dev = crtc->base.dev;
struct drm_i915_private *dev_priv = dev->dev_private;
u32 reg;
reg = PIPECONF(crtc->cpu_transcoder);
I915_WRITE(reg, I915_READ(reg) & ~PIPECONF_FRAME_START_DELAY_MASK);
if (INTEL_INFO(dev)->gen < 4 && !intel_check_plane_mapping(crtc)) {
struct intel_connector *connector;
bool plane;
DRM_DEBUG_KMS("[CRTC:%d] wrong plane connection detected!\n",
crtc->base.base.id);
plane = crtc->plane;
crtc->plane = !plane;
dev_priv->display.crtc_disable(&crtc->base);
crtc->plane = plane;
list_for_each_entry(connector, &dev->mode_config.connector_list,
base.head) {
if (connector->encoder->base.crtc != &crtc->base)
continue;
intel_connector_break_all_links(connector);
}
WARN_ON(crtc->active);
crtc->base.enabled = false;
}
if (dev_priv->quirks & QUIRK_PIPEA_FORCE &&
crtc->pipe == PIPE_A && !crtc->active) {
intel_enable_pipe_a(dev);
}
intel_crtc_update_dpms(&crtc->base);
if (crtc->active != crtc->base.enabled) {
struct intel_encoder *encoder;
DRM_DEBUG_KMS("[CRTC:%d] hw state adjusted, was %s, now %s\n",
crtc->base.base.id,
crtc->base.enabled ? "enabled" : "disabled",
crtc->active ? "enabled" : "disabled");
crtc->base.enabled = crtc->active;
WARN_ON(crtc->active);
for_each_encoder_on_crtc(dev, &crtc->base, encoder) {
WARN_ON(encoder->connectors_active);
encoder->base.crtc = NULL;
}
}
}
static void intel_sanitize_encoder(struct intel_encoder *encoder)
{
struct intel_connector *connector;
struct drm_device *dev = encoder->base.dev;
bool has_active_crtc = encoder->base.crtc &&
to_intel_crtc(encoder->base.crtc)->active;
if (encoder->connectors_active && !has_active_crtc) {
DRM_DEBUG_KMS("[ENCODER:%d:%s] has active connectors but no active pipe!\n",
encoder->base.base.id,
drm_get_encoder_name(&encoder->base));
if (encoder->base.crtc) {
DRM_DEBUG_KMS("[ENCODER:%d:%s] manually disabled\n",
encoder->base.base.id,
drm_get_encoder_name(&encoder->base));
encoder->disable(encoder);
}
list_for_each_entry(connector,
&dev->mode_config.connector_list,
base.head) {
if (connector->encoder != encoder)
continue;
intel_connector_break_all_links(connector);
}
}
}
static void i915_redisable_vga(struct drm_device *dev)
{
struct drm_i915_private *dev_priv = dev->dev_private;
u32 vga_reg;
if (HAS_PCH_SPLIT(dev))
vga_reg = CPU_VGACNTRL;
else
vga_reg = VGACNTRL;
if (I915_READ(vga_reg) != VGA_DISP_DISABLE) {
DRM_DEBUG_KMS("Something enabled VGA plane, disabling it\n");
I915_WRITE(vga_reg, VGA_DISP_DISABLE);
POSTING_READ(vga_reg);
}
}
void intel_modeset_setup_hw_state(struct drm_device *dev,
bool force_restore)
{
struct drm_i915_private *dev_priv = dev->dev_private;
enum pipe pipe;
u32 tmp;
struct intel_crtc *crtc;
struct intel_encoder *encoder;
struct intel_connector *connector;
if (IS_HASWELL(dev)) {
tmp = I915_READ(TRANS_DDI_FUNC_CTL(TRANSCODER_EDP));
if (tmp & TRANS_DDI_FUNC_ENABLE) {
switch (tmp & TRANS_DDI_EDP_INPUT_MASK) {
case TRANS_DDI_EDP_INPUT_A_ON:
case TRANS_DDI_EDP_INPUT_A_ONOFF:
pipe = PIPE_A;
break;
case TRANS_DDI_EDP_INPUT_B_ONOFF:
pipe = PIPE_B;
break;
case TRANS_DDI_EDP_INPUT_C_ONOFF:
pipe = PIPE_C;
break;
}
crtc = to_intel_crtc(dev_priv->pipe_to_crtc_mapping[pipe]);
crtc->cpu_transcoder = TRANSCODER_EDP;
DRM_DEBUG_KMS("Pipe %c using transcoder EDP\n",
pipe_name(pipe));
}
}
for_each_pipe(pipe) {
crtc = to_intel_crtc(dev_priv->pipe_to_crtc_mapping[pipe]);
tmp = I915_READ(PIPECONF(crtc->cpu_transcoder));
if (tmp & PIPECONF_ENABLE)
crtc->active = true;
else
crtc->active = false;
crtc->base.enabled = crtc->active;
DRM_DEBUG_KMS("[CRTC:%d] hw state readout: %s\n",
crtc->base.base.id,
crtc->active ? "enabled" : "disabled");
}
if (IS_HASWELL(dev))
intel_ddi_setup_hw_pll_state(dev);
list_for_each_entry(encoder, &dev->mode_config.encoder_list,
base.head) {
pipe = 0;
if (encoder->get_hw_state(encoder, &pipe)) {
encoder->base.crtc =
dev_priv->pipe_to_crtc_mapping[pipe];
} else {
encoder->base.crtc = NULL;
}
encoder->connectors_active = false;
DRM_DEBUG_KMS("[ENCODER:%d:%s] hw state readout: %s, pipe=%i\n",
encoder->base.base.id,
drm_get_encoder_name(&encoder->base),
encoder->base.crtc ? "enabled" : "disabled",
pipe);
}
list_for_each_entry(connector, &dev->mode_config.connector_list,
base.head) {
if (connector->get_hw_state(connector)) {
connector->base.dpms = DRM_MODE_DPMS_ON;
connector->encoder->connectors_active = true;
connector->base.encoder = &connector->encoder->base;
} else {
connector->base.dpms = DRM_MODE_DPMS_OFF;
connector->base.encoder = NULL;
}
DRM_DEBUG_KMS("[CONNECTOR:%d:%s] hw state readout: %s\n",
connector->base.base.id,
drm_get_connector_name(&connector->base),
connector->base.encoder ? "enabled" : "disabled");
}
list_for_each_entry(encoder, &dev->mode_config.encoder_list,
base.head) {
intel_sanitize_encoder(encoder);
}
for_each_pipe(pipe) {
crtc = to_intel_crtc(dev_priv->pipe_to_crtc_mapping[pipe]);
intel_sanitize_crtc(crtc);
}
if (force_restore) {
for_each_pipe(pipe) {
crtc = to_intel_crtc(dev_priv->pipe_to_crtc_mapping[pipe]);
intel_set_mode(&crtc->base, &crtc->base.mode,
crtc->base.x, crtc->base.y, crtc->base.fb);
}
i915_redisable_vga(dev);
} else {
intel_modeset_update_staged_output_state(dev);
}
intel_modeset_check_state(dev);
drm_mode_config_reset(dev);
}
void intel_modeset_gem_init(struct drm_device *dev)
{
intel_modeset_init_hw(dev);
intel_setup_overlay(dev);
intel_modeset_setup_hw_state(dev, false);
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
intel_disable_gt_powersave(dev);
ironlake_teardown_rc6(dev);
if (IS_VALLEYVIEW(dev))
vlv_init_dpio(dev);
mutex_unlock(&dev->struct_mutex);
drm_irq_uninstall(dev);
cancel_work_sync(&dev_priv->hotplug_work);
cancel_work_sync(&dev_priv->rps.work);
flush_scheduled_work();
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
enum transcoder cpu_transcoder;
int i;
error = kmalloc(sizeof(*error), GFP_ATOMIC);
if (error == NULL)
return NULL;
for_each_pipe(i) {
cpu_transcoder = intel_pipe_to_cpu_transcoder(dev_priv, i);
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
error->pipe[i].conf = I915_READ(PIPECONF(cpu_transcoder));
error->pipe[i].source = I915_READ(PIPESRC(i));
error->pipe[i].htotal = I915_READ(HTOTAL(cpu_transcoder));
error->pipe[i].hblank = I915_READ(HBLANK(cpu_transcoder));
error->pipe[i].hsync = I915_READ(HSYNC(cpu_transcoder));
error->pipe[i].vtotal = I915_READ(VTOTAL(cpu_transcoder));
error->pipe[i].vblank = I915_READ(VBLANK(cpu_transcoder));
error->pipe[i].vsync = I915_READ(VSYNC(cpu_transcoder));
}
return error;
}
void
intel_display_print_error_state(struct seq_file *m,
struct drm_device *dev,
struct intel_display_error_state *error)
{
drm_i915_private_t *dev_priv = dev->dev_private;
int i;
seq_printf(m, "Num Pipes: %d\n", dev_priv->num_pipe);
for_each_pipe(i) {
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
