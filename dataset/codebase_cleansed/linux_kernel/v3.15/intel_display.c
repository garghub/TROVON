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
static void vlv_clock(int refclk, intel_clock_t *clock)
{
clock->m = clock->m1 * clock->m2;
clock->p = clock->p1 * clock->p2;
if (WARN_ON(clock->n == 0 || clock->p == 0))
return;
clock->vco = DIV_ROUND_CLOSEST(refclk * clock->m, clock->n);
clock->dot = DIV_ROUND_CLOSEST(clock->vco, clock->p);
}
static bool intel_pipe_has_type(struct drm_crtc *crtc, int type)
{
struct drm_device *dev = crtc->dev;
struct intel_encoder *encoder;
for_each_encoder_on_crtc(dev, crtc, encoder)
if (encoder->type == type)
return true;
return false;
}
static const intel_limit_t *intel_ironlake_limit(struct drm_crtc *crtc,
int refclk)
{
struct drm_device *dev = crtc->dev;
const intel_limit_t *limit;
if (intel_pipe_has_type(crtc, INTEL_OUTPUT_LVDS)) {
if (intel_is_dual_link_lvds(dev)) {
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
} else
limit = &intel_limits_ironlake_dac;
return limit;
}
static const intel_limit_t *intel_g4x_limit(struct drm_crtc *crtc)
{
struct drm_device *dev = crtc->dev;
const intel_limit_t *limit;
if (intel_pipe_has_type(crtc, INTEL_OUTPUT_LVDS)) {
if (intel_is_dual_link_lvds(dev))
limit = &intel_limits_g4x_dual_channel_lvds;
else
limit = &intel_limits_g4x_single_channel_lvds;
} else if (intel_pipe_has_type(crtc, INTEL_OUTPUT_HDMI) ||
intel_pipe_has_type(crtc, INTEL_OUTPUT_ANALOG)) {
limit = &intel_limits_g4x_hdmi;
} else if (intel_pipe_has_type(crtc, INTEL_OUTPUT_SDVO)) {
limit = &intel_limits_g4x_sdvo;
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
limit = &intel_limits_vlv;
} else if (!IS_GEN2(dev)) {
if (intel_pipe_has_type(crtc, INTEL_OUTPUT_LVDS))
limit = &intel_limits_i9xx_lvds;
else
limit = &intel_limits_i9xx_sdvo;
} else {
if (intel_pipe_has_type(crtc, INTEL_OUTPUT_LVDS))
limit = &intel_limits_i8xx_lvds;
else if (intel_pipe_has_type(crtc, INTEL_OUTPUT_DVO))
limit = &intel_limits_i8xx_dvo;
else
limit = &intel_limits_i8xx_dac;
}
return limit;
}
static void pineview_clock(int refclk, intel_clock_t *clock)
{
clock->m = clock->m2 + 2;
clock->p = clock->p1 * clock->p2;
if (WARN_ON(clock->n == 0 || clock->p == 0))
return;
clock->vco = DIV_ROUND_CLOSEST(refclk * clock->m, clock->n);
clock->dot = DIV_ROUND_CLOSEST(clock->vco, clock->p);
}
static uint32_t i9xx_dpll_compute_m(struct dpll *dpll)
{
return 5 * (dpll->m1 + 2) + (dpll->m2 + 2);
}
static void i9xx_clock(int refclk, intel_clock_t *clock)
{
clock->m = i9xx_dpll_compute_m(clock);
clock->p = clock->p1 * clock->p2;
if (WARN_ON(clock->n + 2 == 0 || clock->p == 0))
return;
clock->vco = DIV_ROUND_CLOSEST(refclk * clock->m, clock->n + 2);
clock->dot = DIV_ROUND_CLOSEST(clock->vco, clock->p);
}
static bool intel_PLL_is_valid(struct drm_device *dev,
const intel_limit_t *limit,
const intel_clock_t *clock)
{
if (clock->n < limit->n.min || limit->n.max < clock->n)
INTELPllInvalid("n out of range\n");
if (clock->p1 < limit->p1.min || limit->p1.max < clock->p1)
INTELPllInvalid("p1 out of range\n");
if (clock->m2 < limit->m2.min || limit->m2.max < clock->m2)
INTELPllInvalid("m2 out of range\n");
if (clock->m1 < limit->m1.min || limit->m1.max < clock->m1)
INTELPllInvalid("m1 out of range\n");
if (!IS_PINEVIEW(dev) && !IS_VALLEYVIEW(dev))
if (clock->m1 <= clock->m2)
INTELPllInvalid("m1 <= m2\n");
if (!IS_VALLEYVIEW(dev)) {
if (clock->p < limit->p.min || limit->p.max < clock->p)
INTELPllInvalid("p out of range\n");
if (clock->m < limit->m.min || limit->m.max < clock->m)
INTELPllInvalid("m out of range\n");
}
if (clock->vco < limit->vco.min || limit->vco.max < clock->vco)
INTELPllInvalid("vco out of range\n");
if (clock->dot < limit->dot.min || limit->dot.max < clock->dot)
INTELPllInvalid("dot out of range\n");
return true;
}
static bool
i9xx_find_best_dpll(const intel_limit_t *limit, struct drm_crtc *crtc,
int target, int refclk, intel_clock_t *match_clock,
intel_clock_t *best_clock)
{
struct drm_device *dev = crtc->dev;
intel_clock_t clock;
int err = target;
if (intel_pipe_has_type(crtc, INTEL_OUTPUT_LVDS)) {
if (intel_is_dual_link_lvds(dev))
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
if (clock.m2 >= clock.m1)
break;
for (clock.n = limit->n.min;
clock.n <= limit->n.max; clock.n++) {
for (clock.p1 = limit->p1.min;
clock.p1 <= limit->p1.max; clock.p1++) {
int this_err;
i9xx_clock(refclk, &clock);
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
pnv_find_best_dpll(const intel_limit_t *limit, struct drm_crtc *crtc,
int target, int refclk, intel_clock_t *match_clock,
intel_clock_t *best_clock)
{
struct drm_device *dev = crtc->dev;
intel_clock_t clock;
int err = target;
if (intel_pipe_has_type(crtc, INTEL_OUTPUT_LVDS)) {
if (intel_is_dual_link_lvds(dev))
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
for (clock.n = limit->n.min;
clock.n <= limit->n.max; clock.n++) {
for (clock.p1 = limit->p1.min;
clock.p1 <= limit->p1.max; clock.p1++) {
int this_err;
pineview_clock(refclk, &clock);
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
g4x_find_best_dpll(const intel_limit_t *limit, struct drm_crtc *crtc,
int target, int refclk, intel_clock_t *match_clock,
intel_clock_t *best_clock)
{
struct drm_device *dev = crtc->dev;
intel_clock_t clock;
int max_n;
bool found;
int err_most = (target >> 8) + (target >> 9);
found = false;
if (intel_pipe_has_type(crtc, INTEL_OUTPUT_LVDS)) {
if (intel_is_dual_link_lvds(dev))
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
i9xx_clock(refclk, &clock);
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
vlv_find_best_dpll(const intel_limit_t *limit, struct drm_crtc *crtc,
int target, int refclk, intel_clock_t *match_clock,
intel_clock_t *best_clock)
{
struct drm_device *dev = crtc->dev;
intel_clock_t clock;
unsigned int bestppm = 1000000;
int max_n = min(limit->n.max, refclk / 19200);
bool found = false;
target *= 5;
memset(best_clock, 0, sizeof(*best_clock));
for (clock.n = limit->n.min; clock.n <= max_n; clock.n++) {
for (clock.p1 = limit->p1.max; clock.p1 >= limit->p1.min; clock.p1--) {
for (clock.p2 = limit->p2.p2_fast; clock.p2 >= limit->p2.p2_slow;
clock.p2 -= clock.p2 > 10 ? 2 : 1) {
clock.p = clock.p1 * clock.p2;
for (clock.m1 = limit->m1.min; clock.m1 <= limit->m1.max; clock.m1++) {
unsigned int ppm, diff;
clock.m2 = DIV_ROUND_CLOSEST(target * clock.p * clock.n,
refclk * clock.m1);
vlv_clock(refclk, &clock);
if (!intel_PLL_is_valid(dev, limit,
&clock))
continue;
diff = abs(clock.dot - target);
ppm = div_u64(1000000ULL * diff, target);
if (ppm < 100 && clock.p > best_clock->p) {
bestppm = 0;
*best_clock = clock;
found = true;
}
if (bestppm >= 10 && ppm < bestppm - 10) {
bestppm = ppm;
*best_clock = clock;
found = true;
}
}
}
}
}
return found;
}
bool intel_crtc_active(struct drm_crtc *crtc)
{
struct intel_crtc *intel_crtc = to_intel_crtc(crtc);
return intel_crtc->active && crtc->primary->fb &&
intel_crtc->config.adjusted_mode.crtc_clock;
}
enum transcoder intel_pipe_to_cpu_transcoder(struct drm_i915_private *dev_priv,
enum pipe pipe)
{
struct drm_crtc *crtc = dev_priv->pipe_to_crtc_mapping[pipe];
struct intel_crtc *intel_crtc = to_intel_crtc(crtc);
return intel_crtc->config.cpu_transcoder;
}
static void g4x_wait_for_vblank(struct drm_device *dev, int pipe)
{
struct drm_i915_private *dev_priv = dev->dev_private;
u32 frame, frame_reg = PIPE_FRMCOUNT_GM45(pipe);
frame = I915_READ(frame_reg);
if (wait_for(I915_READ_NOTRACE(frame_reg) != frame, 50))
DRM_DEBUG_KMS("vblank wait timed out\n");
}
void intel_wait_for_vblank(struct drm_device *dev, int pipe)
{
struct drm_i915_private *dev_priv = dev->dev_private;
int pipestat_reg = PIPESTAT(pipe);
if (IS_G4X(dev) || INTEL_INFO(dev)->gen >= 5) {
g4x_wait_for_vblank(dev, pipe);
return;
}
I915_WRITE(pipestat_reg,
I915_READ(pipestat_reg) | PIPE_VBLANK_INTERRUPT_STATUS);
if (wait_for(I915_READ(pipestat_reg) &
PIPE_VBLANK_INTERRUPT_STATUS,
50))
DRM_DEBUG_KMS("vblank wait timed out\n");
}
static bool pipe_dsl_stopped(struct drm_device *dev, enum pipe pipe)
{
struct drm_i915_private *dev_priv = dev->dev_private;
u32 reg = PIPEDSL(pipe);
u32 line1, line2;
u32 line_mask;
if (IS_GEN2(dev))
line_mask = DSL_LINEMASK_GEN2;
else
line_mask = DSL_LINEMASK_GEN3;
line1 = I915_READ(reg) & line_mask;
mdelay(5);
line2 = I915_READ(reg) & line_mask;
return line1 == line2;
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
if (wait_for(pipe_dsl_stopped(dev, pipe), 100))
WARN(1, "pipe_off wait timed out\n");
}
}
bool ibx_digital_port_connected(struct drm_i915_private *dev_priv,
struct intel_digital_port *port)
{
u32 bit;
if (HAS_PCH_IBX(dev_priv->dev)) {
switch(port->port) {
case PORT_B:
bit = SDE_PORTB_HOTPLUG;
break;
case PORT_C:
bit = SDE_PORTC_HOTPLUG;
break;
case PORT_D:
bit = SDE_PORTD_HOTPLUG;
break;
default:
return true;
}
} else {
switch(port->port) {
case PORT_B:
bit = SDE_PORTB_HOTPLUG_CPT;
break;
case PORT_C:
bit = SDE_PORTC_HOTPLUG_CPT;
break;
case PORT_D:
bit = SDE_PORTD_HOTPLUG_CPT;
break;
default:
return true;
}
}
return I915_READ(SDEISR) & bit;
}
static const char *state_string(bool enabled)
{
return enabled ? "on" : "off";
}
void assert_pll(struct drm_i915_private *dev_priv,
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
static void assert_dsi_pll(struct drm_i915_private *dev_priv, bool state)
{
u32 val;
bool cur_state;
mutex_lock(&dev_priv->dpio_lock);
val = vlv_cck_read(dev_priv, CCK_REG_DSI_PLL_CONTROL);
mutex_unlock(&dev_priv->dpio_lock);
cur_state = val & DSI_PLL_VCO_EN;
WARN(cur_state != state,
"DSI PLL state assertion failure (expected %s, current %s)\n",
state_string(state), state_string(cur_state));
}
struct intel_shared_dpll *
intel_crtc_to_shared_dpll(struct intel_crtc *crtc)
{
struct drm_i915_private *dev_priv = crtc->base.dev->dev_private;
if (crtc->config.shared_dpll < 0)
return NULL;
return &dev_priv->shared_dplls[crtc->config.shared_dpll];
}
void assert_shared_dpll(struct drm_i915_private *dev_priv,
struct intel_shared_dpll *pll,
bool state)
{
bool cur_state;
struct intel_dpll_hw_state hw_state;
if (HAS_PCH_LPT(dev_priv->dev)) {
DRM_DEBUG_DRIVER("LPT detected: skipping PCH PLL test\n");
return;
}
if (WARN (!pll,
"asserting DPLL %s with no DPLL\n", state_string(state)))
return;
cur_state = pll->get_hw_state(dev_priv, pll, &hw_state);
WARN(cur_state != state,
"%s assertion failure (expected %s, current %s)\n",
pll->name, state_string(state), state_string(cur_state));
}
static void assert_fdi_tx(struct drm_i915_private *dev_priv,
enum pipe pipe, bool state)
{
int reg;
u32 val;
bool cur_state;
enum transcoder cpu_transcoder = intel_pipe_to_cpu_transcoder(dev_priv,
pipe);
if (HAS_DDI(dev_priv->dev)) {
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
if (INTEL_INFO(dev_priv->dev)->gen == 5)
return;
if (HAS_DDI(dev_priv->dev))
return;
reg = FDI_TX_CTL(pipe);
val = I915_READ(reg);
WARN(!(val & FDI_TX_PLL_ENABLE), "FDI TX PLL assertion failure, should be active but is disabled\n");
}
void assert_fdi_rx_pll(struct drm_i915_private *dev_priv,
enum pipe pipe, bool state)
{
int reg;
u32 val;
bool cur_state;
reg = FDI_RX_CTL(pipe);
val = I915_READ(reg);
cur_state = !!(val & FDI_RX_PLL_ENABLE);
WARN(cur_state != state,
"FDI RX PLL assertion failure (expected %s, current %s)\n",
state_string(state), state_string(cur_state));
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
static void assert_cursor(struct drm_i915_private *dev_priv,
enum pipe pipe, bool state)
{
struct drm_device *dev = dev_priv->dev;
bool cur_state;
if (IS_845G(dev) || IS_I865G(dev))
cur_state = I915_READ(_CURACNTR) & CURSOR_ENABLE;
else if (INTEL_INFO(dev)->gen <= 6 || IS_VALLEYVIEW(dev))
cur_state = I915_READ(CURCNTR(pipe)) & CURSOR_MODE;
else
cur_state = I915_READ(CURCNTR_IVB(pipe)) & CURSOR_MODE;
WARN(cur_state != state,
"cursor on pipe %c assertion failure (expected %s, current %s)\n",
pipe_name(pipe), state_string(state), state_string(cur_state));
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
if (!intel_display_power_enabled(dev_priv,
POWER_DOMAIN_TRANSCODER(cpu_transcoder))) {
cur_state = false;
} else {
reg = PIPECONF(cpu_transcoder);
val = I915_READ(reg);
cur_state = !!(val & PIPECONF_ENABLE);
}
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
struct drm_device *dev = dev_priv->dev;
int reg, i;
u32 val;
int cur_pipe;
if (INTEL_INFO(dev)->gen >= 4) {
reg = DSPCNTR(pipe);
val = I915_READ(reg);
WARN(val & DISPLAY_PLANE_ENABLE,
"plane %c assertion failure, should be disabled but not\n",
plane_name(pipe));
return;
}
for_each_pipe(i) {
reg = DSPCNTR(i);
val = I915_READ(reg);
cur_pipe = (val & DISPPLANE_SEL_PIPE_MASK) >>
DISPPLANE_SEL_PIPE_SHIFT;
WARN((val & DISPLAY_PLANE_ENABLE) && pipe == cur_pipe,
"plane %c assertion failure, should be off on pipe %c but is still active\n",
plane_name(i), pipe_name(pipe));
}
}
static void assert_sprites_disabled(struct drm_i915_private *dev_priv,
enum pipe pipe)
{
struct drm_device *dev = dev_priv->dev;
int reg, sprite;
u32 val;
if (IS_VALLEYVIEW(dev)) {
for_each_sprite(pipe, sprite) {
reg = SPCNTR(pipe, sprite);
val = I915_READ(reg);
WARN(val & SP_ENABLE,
"sprite %c assertion failure, should be off on pipe %c but is still active\n",
sprite_name(pipe, sprite), pipe_name(pipe));
}
} else if (INTEL_INFO(dev)->gen >= 7) {
reg = SPRCTL(pipe);
val = I915_READ(reg);
WARN(val & SPRITE_ENABLE,
"sprite %c assertion failure, should be off on pipe %c but is still active\n",
plane_name(pipe), pipe_name(pipe));
} else if (INTEL_INFO(dev)->gen >= 5) {
reg = DVSCNTR(pipe);
val = I915_READ(reg);
WARN(val & DVS_ENABLE,
"sprite %c assertion failure, should be off on pipe %c but is still active\n",
plane_name(pipe), pipe_name(pipe));
}
}
static void ibx_assert_pch_refclk_enabled(struct drm_i915_private *dev_priv)
{
u32 val;
bool enabled;
WARN_ON(!(HAS_PCH_IBX(dev_priv->dev) || HAS_PCH_CPT(dev_priv->dev)));
val = I915_READ(PCH_DREF_CONTROL);
enabled = !!(val & (DREF_SSC_SOURCE_MASK | DREF_NONSPREAD_SOURCE_MASK |
DREF_SUPERSPREAD_SOURCE_MASK));
WARN(!enabled, "PCH refclk assertion failure, should be active but is disabled\n");
}
static void assert_pch_transcoder_disabled(struct drm_i915_private *dev_priv,
enum pipe pipe)
{
int reg;
u32 val;
bool enabled;
reg = PCH_TRANSCONF(pipe);
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
if ((val & SDVO_ENABLE) == 0)
return false;
if (HAS_PCH_CPT(dev_priv->dev)) {
if ((val & SDVO_PIPE_SEL_MASK_CPT) != SDVO_PIPE_SEL_CPT(pipe))
return false;
} else {
if ((val & SDVO_PIPE_SEL_MASK) != SDVO_PIPE_SEL(pipe))
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
WARN(HAS_PCH_IBX(dev_priv->dev) && (val & SDVO_ENABLE) == 0
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
assert_pch_hdmi_disabled(dev_priv, pipe, PCH_HDMIB);
assert_pch_hdmi_disabled(dev_priv, pipe, PCH_HDMIC);
assert_pch_hdmi_disabled(dev_priv, pipe, PCH_HDMID);
}
static void intel_init_dpio(struct drm_device *dev)
{
struct drm_i915_private *dev_priv = dev->dev_private;
if (!IS_VALLEYVIEW(dev))
return;
DPIO_PHY_IOSF_PORT(DPIO_PHY0) = IOSF_PORT_DPIO;
}
static void intel_reset_dpio(struct drm_device *dev)
{
struct drm_i915_private *dev_priv = dev->dev_private;
if (!IS_VALLEYVIEW(dev))
return;
I915_WRITE(DPLL(PIPE_B), I915_READ(DPLL(PIPE_B)) |
DPLL_REFA_CLK_ENABLE_VLV |
DPLL_INTEGRATED_CRI_CLK_VLV);
I915_WRITE(DPIO_CTL, I915_READ(DPIO_CTL) | DPIO_CMNRST);
}
static void vlv_enable_pll(struct intel_crtc *crtc)
{
struct drm_device *dev = crtc->base.dev;
struct drm_i915_private *dev_priv = dev->dev_private;
int reg = DPLL(crtc->pipe);
u32 dpll = crtc->config.dpll_hw_state.dpll;
assert_pipe_disabled(dev_priv, crtc->pipe);
BUG_ON(!IS_VALLEYVIEW(dev_priv->dev));
if (IS_MOBILE(dev_priv->dev) && !IS_I830(dev_priv->dev))
assert_panel_unlocked(dev_priv, crtc->pipe);
I915_WRITE(reg, dpll);
POSTING_READ(reg);
udelay(150);
if (wait_for(((I915_READ(reg) & DPLL_LOCK_VLV) == DPLL_LOCK_VLV), 1))
DRM_ERROR("DPLL %d failed to lock\n", crtc->pipe);
I915_WRITE(DPLL_MD(crtc->pipe), crtc->config.dpll_hw_state.dpll_md);
POSTING_READ(DPLL_MD(crtc->pipe));
I915_WRITE(reg, dpll);
POSTING_READ(reg);
udelay(150);
I915_WRITE(reg, dpll);
POSTING_READ(reg);
udelay(150);
I915_WRITE(reg, dpll);
POSTING_READ(reg);
udelay(150);
}
static void i9xx_enable_pll(struct intel_crtc *crtc)
{
struct drm_device *dev = crtc->base.dev;
struct drm_i915_private *dev_priv = dev->dev_private;
int reg = DPLL(crtc->pipe);
u32 dpll = crtc->config.dpll_hw_state.dpll;
assert_pipe_disabled(dev_priv, crtc->pipe);
BUG_ON(INTEL_INFO(dev)->gen >= 5);
if (IS_MOBILE(dev) && !IS_I830(dev))
assert_panel_unlocked(dev_priv, crtc->pipe);
I915_WRITE(reg, dpll);
POSTING_READ(reg);
udelay(150);
if (INTEL_INFO(dev)->gen >= 4) {
I915_WRITE(DPLL_MD(crtc->pipe),
crtc->config.dpll_hw_state.dpll_md);
} else {
I915_WRITE(reg, dpll);
}
I915_WRITE(reg, dpll);
POSTING_READ(reg);
udelay(150);
I915_WRITE(reg, dpll);
POSTING_READ(reg);
udelay(150);
I915_WRITE(reg, dpll);
POSTING_READ(reg);
udelay(150);
}
static void i9xx_disable_pll(struct drm_i915_private *dev_priv, enum pipe pipe)
{
if (pipe == PIPE_A && (dev_priv->quirks & QUIRK_PIPEA_FORCE))
return;
assert_pipe_disabled(dev_priv, pipe);
I915_WRITE(DPLL(pipe), 0);
POSTING_READ(DPLL(pipe));
}
static void vlv_disable_pll(struct drm_i915_private *dev_priv, enum pipe pipe)
{
u32 val = 0;
assert_pipe_disabled(dev_priv, pipe);
if (pipe == PIPE_B)
val = DPLL_INTEGRATED_CRI_CLK_VLV | DPLL_REFA_CLK_ENABLE_VLV;
I915_WRITE(DPLL(pipe), val);
POSTING_READ(DPLL(pipe));
}
void vlv_wait_port_ready(struct drm_i915_private *dev_priv,
struct intel_digital_port *dport)
{
u32 port_mask;
switch (dport->port) {
case PORT_B:
port_mask = DPLL_PORTB_READY_MASK;
break;
case PORT_C:
port_mask = DPLL_PORTC_READY_MASK;
break;
default:
BUG();
}
if (wait_for((I915_READ(DPLL(0)) & port_mask) == 0, 1000))
WARN(1, "timed out waiting for port %c ready: 0x%08x\n",
port_name(dport->port), I915_READ(DPLL(0)));
}
static void ironlake_enable_shared_dpll(struct intel_crtc *crtc)
{
struct drm_device *dev = crtc->base.dev;
struct drm_i915_private *dev_priv = dev->dev_private;
struct intel_shared_dpll *pll = intel_crtc_to_shared_dpll(crtc);
BUG_ON(INTEL_INFO(dev)->gen < 5);
if (WARN_ON(pll == NULL))
return;
if (WARN_ON(pll->refcount == 0))
return;
DRM_DEBUG_KMS("enable %s (active %d, on? %d)for crtc %d\n",
pll->name, pll->active, pll->on,
crtc->base.base.id);
if (pll->active++) {
WARN_ON(!pll->on);
assert_shared_dpll_enabled(dev_priv, pll);
return;
}
WARN_ON(pll->on);
DRM_DEBUG_KMS("enabling %s\n", pll->name);
pll->enable(dev_priv, pll);
pll->on = true;
}
static void intel_disable_shared_dpll(struct intel_crtc *crtc)
{
struct drm_device *dev = crtc->base.dev;
struct drm_i915_private *dev_priv = dev->dev_private;
struct intel_shared_dpll *pll = intel_crtc_to_shared_dpll(crtc);
BUG_ON(INTEL_INFO(dev)->gen < 5);
if (WARN_ON(pll == NULL))
return;
if (WARN_ON(pll->refcount == 0))
return;
DRM_DEBUG_KMS("disable %s (active %d, on? %d) for crtc %d\n",
pll->name, pll->active, pll->on,
crtc->base.base.id);
if (WARN_ON(pll->active == 0)) {
assert_shared_dpll_disabled(dev_priv, pll);
return;
}
assert_shared_dpll_enabled(dev_priv, pll);
WARN_ON(!pll->on);
if (--pll->active)
return;
DRM_DEBUG_KMS("disabling %s\n", pll->name);
pll->disable(dev_priv, pll);
pll->on = false;
}
static void ironlake_enable_pch_transcoder(struct drm_i915_private *dev_priv,
enum pipe pipe)
{
struct drm_device *dev = dev_priv->dev;
struct drm_crtc *crtc = dev_priv->pipe_to_crtc_mapping[pipe];
struct intel_crtc *intel_crtc = to_intel_crtc(crtc);
uint32_t reg, val, pipeconf_val;
BUG_ON(INTEL_INFO(dev)->gen < 5);
assert_shared_dpll_enabled(dev_priv,
intel_crtc_to_shared_dpll(intel_crtc));
assert_fdi_tx_enabled(dev_priv, pipe);
assert_fdi_rx_enabled(dev_priv, pipe);
if (HAS_PCH_CPT(dev)) {
reg = TRANS_CHICKEN2(pipe);
val = I915_READ(reg);
val |= TRANS_CHICKEN2_TIMING_OVERRIDE;
I915_WRITE(reg, val);
}
reg = PCH_TRANSCONF(pipe);
val = I915_READ(reg);
pipeconf_val = I915_READ(PIPECONF(pipe));
if (HAS_PCH_IBX(dev_priv->dev)) {
val &= ~PIPECONF_BPC_MASK;
val |= pipeconf_val & PIPECONF_BPC_MASK;
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
DRM_ERROR("failed to enable transcoder %c\n", pipe_name(pipe));
}
static void lpt_enable_pch_transcoder(struct drm_i915_private *dev_priv,
enum transcoder cpu_transcoder)
{
u32 val, pipeconf_val;
BUG_ON(INTEL_INFO(dev_priv->dev)->gen < 5);
assert_fdi_tx_enabled(dev_priv, (enum pipe) cpu_transcoder);
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
I915_WRITE(LPT_TRANSCONF, val);
if (wait_for(I915_READ(LPT_TRANSCONF) & TRANS_STATE_ENABLE, 100))
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
reg = PCH_TRANSCONF(pipe);
val = I915_READ(reg);
val &= ~TRANS_ENABLE;
I915_WRITE(reg, val);
if (wait_for((I915_READ(reg) & TRANS_STATE_ENABLE) == 0, 50))
DRM_ERROR("failed to disable transcoder %c\n", pipe_name(pipe));
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
val = I915_READ(LPT_TRANSCONF);
val &= ~TRANS_ENABLE;
I915_WRITE(LPT_TRANSCONF, val);
if (wait_for((I915_READ(LPT_TRANSCONF) & TRANS_STATE_ENABLE) == 0, 50))
DRM_ERROR("Failed to disable PCH transcoder\n");
val = I915_READ(_TRANSA_CHICKEN2);
val &= ~TRANS_CHICKEN2_TIMING_OVERRIDE;
I915_WRITE(_TRANSA_CHICKEN2, val);
}
static void intel_enable_pipe(struct intel_crtc *crtc)
{
struct drm_device *dev = crtc->base.dev;
struct drm_i915_private *dev_priv = dev->dev_private;
enum pipe pipe = crtc->pipe;
enum transcoder cpu_transcoder = intel_pipe_to_cpu_transcoder(dev_priv,
pipe);
enum pipe pch_transcoder;
int reg;
u32 val;
assert_planes_disabled(dev_priv, pipe);
assert_cursor_disabled(dev_priv, pipe);
assert_sprites_disabled(dev_priv, pipe);
if (HAS_PCH_LPT(dev_priv->dev))
pch_transcoder = TRANSCODER_A;
else
pch_transcoder = pipe;
if (!HAS_PCH_SPLIT(dev_priv->dev))
if (intel_pipe_has_type(&crtc->base, INTEL_OUTPUT_DSI))
assert_dsi_pll_enabled(dev_priv);
else
assert_pll_enabled(dev_priv, pipe);
else {
if (crtc->config.has_pch_encoder) {
assert_fdi_rx_pll_enabled(dev_priv, pch_transcoder);
assert_fdi_tx_pll_enabled(dev_priv,
(enum pipe) cpu_transcoder);
}
}
reg = PIPECONF(cpu_transcoder);
val = I915_READ(reg);
if (val & PIPECONF_ENABLE) {
WARN_ON(!(pipe == PIPE_A &&
dev_priv->quirks & QUIRK_PIPEA_FORCE));
return;
}
I915_WRITE(reg, val | PIPECONF_ENABLE);
POSTING_READ(reg);
if (INTEL_INFO(dev)->gen <= 7 && !IS_HASWELL(dev))
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
assert_cursor_disabled(dev_priv, pipe);
assert_sprites_disabled(dev_priv, pipe);
if (pipe == PIPE_A && (dev_priv->quirks & QUIRK_PIPEA_FORCE))
return;
reg = PIPECONF(cpu_transcoder);
val = I915_READ(reg);
if ((val & PIPECONF_ENABLE) == 0)
return;
I915_WRITE(reg, val & ~PIPECONF_ENABLE);
intel_wait_for_pipe_off(dev_priv->dev, pipe);
}
void intel_flush_primary_plane(struct drm_i915_private *dev_priv,
enum plane plane)
{
struct drm_device *dev = dev_priv->dev;
u32 reg = INTEL_INFO(dev)->gen >= 4 ? DSPSURF(plane) : DSPADDR(plane);
I915_WRITE(reg, I915_READ(reg));
POSTING_READ(reg);
}
static void intel_enable_primary_hw_plane(struct drm_i915_private *dev_priv,
enum plane plane, enum pipe pipe)
{
struct intel_crtc *intel_crtc =
to_intel_crtc(dev_priv->pipe_to_crtc_mapping[pipe]);
int reg;
u32 val;
assert_pipe_enabled(dev_priv, pipe);
WARN(intel_crtc->primary_enabled, "Primary plane already enabled\n");
intel_crtc->primary_enabled = true;
reg = DSPCNTR(plane);
val = I915_READ(reg);
if (val & DISPLAY_PLANE_ENABLE)
return;
I915_WRITE(reg, val | DISPLAY_PLANE_ENABLE);
intel_flush_primary_plane(dev_priv, plane);
intel_wait_for_vblank(dev_priv->dev, pipe);
}
static void intel_disable_primary_hw_plane(struct drm_i915_private *dev_priv,
enum plane plane, enum pipe pipe)
{
struct intel_crtc *intel_crtc =
to_intel_crtc(dev_priv->pipe_to_crtc_mapping[pipe]);
int reg;
u32 val;
WARN(!intel_crtc->primary_enabled, "Primary plane already disabled\n");
intel_crtc->primary_enabled = false;
reg = DSPCNTR(plane);
val = I915_READ(reg);
if ((val & DISPLAY_PLANE_ENABLE) == 0)
return;
I915_WRITE(reg, val & ~DISPLAY_PLANE_ENABLE);
intel_flush_primary_plane(dev_priv, plane);
intel_wait_for_vblank(dev_priv->dev, pipe);
}
static bool need_vtd_wa(struct drm_device *dev)
{
#ifdef CONFIG_INTEL_IOMMU
if (INTEL_INFO(dev)->gen >= 6 && intel_iommu_gfx_mapped)
return true;
#endif
return false;
}
static int intel_align_height(struct drm_device *dev, int height, bool tiled)
{
int tile_height;
tile_height = tiled ? (IS_GEN2(dev) ? 16 : 8) : 1;
return ALIGN(height, tile_height);
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
WARN(1, "Y tiled bo slipped through, driver bug!\n");
return -EINVAL;
default:
BUG();
}
if (need_vtd_wa(dev) && alignment < 256 * 1024)
alignment = 256 * 1024;
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
i915_gem_object_unpin_from_display_plane(obj);
err_interruptible:
dev_priv->mm.interruptible = true;
return ret;
}
void intel_unpin_fb_obj(struct drm_i915_gem_object *obj)
{
i915_gem_object_unpin_fence(obj);
i915_gem_object_unpin_from_display_plane(obj);
}
unsigned long intel_gen4_compute_page_offset(int *x, int *y,
unsigned int tiling_mode,
unsigned int cpp,
unsigned int pitch)
{
if (tiling_mode != I915_TILING_NONE) {
unsigned int tile_rows, tiles;
tile_rows = *y / 8;
*y %= 8;
tiles = *x / (512/cpp);
*x %= 512/cpp;
return tile_rows * pitch * 8 + tiles * 4096;
} else {
unsigned int offset;
offset = *y * pitch + *x * cpp;
*y = 0;
*x = (offset & 4095) / cpp;
return offset & -4096;
}
}
int intel_format_to_fourcc(int format)
{
switch (format) {
case DISPPLANE_8BPP:
return DRM_FORMAT_C8;
case DISPPLANE_BGRX555:
return DRM_FORMAT_XRGB1555;
case DISPPLANE_BGRX565:
return DRM_FORMAT_RGB565;
default:
case DISPPLANE_BGRX888:
return DRM_FORMAT_XRGB8888;
case DISPPLANE_RGBX888:
return DRM_FORMAT_XBGR8888;
case DISPPLANE_BGRX101010:
return DRM_FORMAT_XRGB2101010;
case DISPPLANE_RGBX101010:
return DRM_FORMAT_XBGR2101010;
}
}
static bool intel_alloc_plane_obj(struct intel_crtc *crtc,
struct intel_plane_config *plane_config)
{
struct drm_device *dev = crtc->base.dev;
struct drm_i915_gem_object *obj = NULL;
struct drm_mode_fb_cmd2 mode_cmd = { 0 };
u32 base = plane_config->base;
if (plane_config->size == 0)
return false;
obj = i915_gem_object_create_stolen_for_preallocated(dev, base, base,
plane_config->size);
if (!obj)
return false;
if (plane_config->tiled) {
obj->tiling_mode = I915_TILING_X;
obj->stride = crtc->base.primary->fb->pitches[0];
}
mode_cmd.pixel_format = crtc->base.primary->fb->pixel_format;
mode_cmd.width = crtc->base.primary->fb->width;
mode_cmd.height = crtc->base.primary->fb->height;
mode_cmd.pitches[0] = crtc->base.primary->fb->pitches[0];
mutex_lock(&dev->struct_mutex);
if (intel_framebuffer_init(dev, to_intel_framebuffer(crtc->base.primary->fb),
&mode_cmd, obj)) {
DRM_DEBUG_KMS("intel fb init failed\n");
goto out_unref_obj;
}
mutex_unlock(&dev->struct_mutex);
DRM_DEBUG_KMS("plane fb obj %p\n", obj);
return true;
out_unref_obj:
drm_gem_object_unreference(&obj->base);
mutex_unlock(&dev->struct_mutex);
return false;
}
static void intel_find_plane_obj(struct intel_crtc *intel_crtc,
struct intel_plane_config *plane_config)
{
struct drm_device *dev = intel_crtc->base.dev;
struct drm_crtc *c;
struct intel_crtc *i;
struct intel_framebuffer *fb;
if (!intel_crtc->base.primary->fb)
return;
if (intel_alloc_plane_obj(intel_crtc, plane_config))
return;
kfree(intel_crtc->base.primary->fb);
intel_crtc->base.primary->fb = NULL;
list_for_each_entry(c, &dev->mode_config.crtc_list, head) {
i = to_intel_crtc(c);
if (c == &intel_crtc->base)
continue;
if (!i->active || !c->primary->fb)
continue;
fb = to_intel_framebuffer(c->primary->fb);
if (i915_gem_obj_ggtt_offset(fb->obj) == plane_config->base) {
drm_framebuffer_reference(c->primary->fb);
intel_crtc->base.primary->fb = c->primary->fb;
break;
}
}
}
static int i9xx_update_primary_plane(struct drm_crtc *crtc,
struct drm_framebuffer *fb,
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
DRM_ERROR("Can't update plane %c in SAREA\n", plane_name(plane));
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
BUG();
}
if (INTEL_INFO(dev)->gen >= 4) {
if (obj->tiling_mode != I915_TILING_NONE)
dspcntr |= DISPPLANE_TILED;
else
dspcntr &= ~DISPPLANE_TILED;
}
if (IS_G4X(dev))
dspcntr |= DISPPLANE_TRICKLE_FEED_DISABLE;
I915_WRITE(reg, dspcntr);
linear_offset = y * fb->pitches[0] + x * (fb->bits_per_pixel / 8);
if (INTEL_INFO(dev)->gen >= 4) {
intel_crtc->dspaddr_offset =
intel_gen4_compute_page_offset(&x, &y, obj->tiling_mode,
fb->bits_per_pixel / 8,
fb->pitches[0]);
linear_offset -= intel_crtc->dspaddr_offset;
} else {
intel_crtc->dspaddr_offset = linear_offset;
}
DRM_DEBUG_KMS("Writing base %08lX %08lX %d %d %d\n",
i915_gem_obj_ggtt_offset(obj), linear_offset, x, y,
fb->pitches[0]);
I915_WRITE(DSPSTRIDE(plane), fb->pitches[0]);
if (INTEL_INFO(dev)->gen >= 4) {
I915_WRITE(DSPSURF(plane),
i915_gem_obj_ggtt_offset(obj) + intel_crtc->dspaddr_offset);
I915_WRITE(DSPTILEOFF(plane), (y << 16) | x);
I915_WRITE(DSPLINOFF(plane), linear_offset);
} else
I915_WRITE(DSPADDR(plane), i915_gem_obj_ggtt_offset(obj) + linear_offset);
POSTING_READ(reg);
return 0;
}
static int ironlake_update_primary_plane(struct drm_crtc *crtc,
struct drm_framebuffer *fb,
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
case 2:
break;
default:
DRM_ERROR("Can't update plane %c in SAREA\n", plane_name(plane));
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
BUG();
}
if (obj->tiling_mode != I915_TILING_NONE)
dspcntr |= DISPPLANE_TILED;
else
dspcntr &= ~DISPPLANE_TILED;
if (IS_HASWELL(dev) || IS_BROADWELL(dev))
dspcntr &= ~DISPPLANE_TRICKLE_FEED_DISABLE;
else
dspcntr |= DISPPLANE_TRICKLE_FEED_DISABLE;
I915_WRITE(reg, dspcntr);
linear_offset = y * fb->pitches[0] + x * (fb->bits_per_pixel / 8);
intel_crtc->dspaddr_offset =
intel_gen4_compute_page_offset(&x, &y, obj->tiling_mode,
fb->bits_per_pixel / 8,
fb->pitches[0]);
linear_offset -= intel_crtc->dspaddr_offset;
DRM_DEBUG_KMS("Writing base %08lX %08lX %d %d %d\n",
i915_gem_obj_ggtt_offset(obj), linear_offset, x, y,
fb->pitches[0]);
I915_WRITE(DSPSTRIDE(plane), fb->pitches[0]);
I915_WRITE(DSPSURF(plane),
i915_gem_obj_ggtt_offset(obj) + intel_crtc->dspaddr_offset);
if (IS_HASWELL(dev) || IS_BROADWELL(dev)) {
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
return dev_priv->display.update_primary_plane(crtc, fb, x, y);
}
void intel_display_handle_reset(struct drm_device *dev)
{
struct drm_i915_private *dev_priv = dev->dev_private;
struct drm_crtc *crtc;
list_for_each_entry(crtc, &dev->mode_config.crtc_list, head) {
struct intel_crtc *intel_crtc = to_intel_crtc(crtc);
enum plane plane = intel_crtc->plane;
intel_prepare_page_flip(dev, plane);
intel_finish_page_flip_plane(dev, plane);
}
list_for_each_entry(crtc, &dev->mode_config.crtc_list, head) {
struct intel_crtc *intel_crtc = to_intel_crtc(crtc);
mutex_lock(&crtc->mutex);
if (intel_crtc->active && crtc->primary->fb)
dev_priv->display.update_primary_plane(crtc,
crtc->primary->fb,
crtc->x,
crtc->y);
mutex_unlock(&crtc->mutex);
}
}
static int
intel_finish_fb(struct drm_framebuffer *old_fb)
{
struct drm_i915_gem_object *obj = to_intel_framebuffer(old_fb)->obj;
struct drm_i915_private *dev_priv = obj->base.dev->dev_private;
bool was_interruptible = dev_priv->mm.interruptible;
int ret;
dev_priv->mm.interruptible = false;
ret = i915_gem_object_finish_gpu(obj);
dev_priv->mm.interruptible = was_interruptible;
return ret;
}
static bool intel_crtc_has_pending_flip(struct drm_crtc *crtc)
{
struct drm_device *dev = crtc->dev;
struct drm_i915_private *dev_priv = dev->dev_private;
struct intel_crtc *intel_crtc = to_intel_crtc(crtc);
unsigned long flags;
bool pending;
if (i915_reset_in_progress(&dev_priv->gpu_error) ||
intel_crtc->reset_counter != atomic_read(&dev_priv->gpu_error.reset_counter))
return false;
spin_lock_irqsave(&dev->event_lock, flags);
pending = to_intel_crtc(crtc)->unpin_work != NULL;
spin_unlock_irqrestore(&dev->event_lock, flags);
return pending;
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
if (intel_crtc_has_pending_flip(crtc)) {
DRM_ERROR("pipe is still busy with an old pageflip\n");
return -EBUSY;
}
if (!fb) {
DRM_ERROR("No FB bound\n");
return 0;
}
if (intel_crtc->plane > INTEL_INFO(dev)->num_pipes) {
DRM_ERROR("no plane for crtc: plane %c, num_pipes %d\n",
plane_name(intel_crtc->plane),
INTEL_INFO(dev)->num_pipes);
return -EINVAL;
}
mutex_lock(&dev->struct_mutex);
ret = intel_pin_and_fence_fb_obj(dev,
to_intel_framebuffer(fb)->obj,
NULL);
mutex_unlock(&dev->struct_mutex);
if (ret != 0) {
DRM_ERROR("pin & fence failed\n");
return ret;
}
if (i915.fastboot) {
const struct drm_display_mode *adjusted_mode =
&intel_crtc->config.adjusted_mode;
I915_WRITE(PIPESRC(intel_crtc->pipe),
((adjusted_mode->crtc_hdisplay - 1) << 16) |
(adjusted_mode->crtc_vdisplay - 1));
if (!intel_crtc->config.pch_pfit.enabled &&
(intel_pipe_has_type(crtc, INTEL_OUTPUT_LVDS) ||
intel_pipe_has_type(crtc, INTEL_OUTPUT_EDP))) {
I915_WRITE(PF_CTL(intel_crtc->pipe), 0);
I915_WRITE(PF_WIN_POS(intel_crtc->pipe), 0);
I915_WRITE(PF_WIN_SZ(intel_crtc->pipe), 0);
}
intel_crtc->config.pipe_src_w = adjusted_mode->crtc_hdisplay;
intel_crtc->config.pipe_src_h = adjusted_mode->crtc_vdisplay;
}
ret = dev_priv->display.update_primary_plane(crtc, fb, x, y);
if (ret) {
mutex_lock(&dev->struct_mutex);
intel_unpin_fb_obj(to_intel_framebuffer(fb)->obj);
mutex_unlock(&dev->struct_mutex);
DRM_ERROR("failed to update base address\n");
return ret;
}
old_fb = crtc->primary->fb;
crtc->primary->fb = fb;
crtc->x = x;
crtc->y = y;
if (old_fb) {
if (intel_crtc->active && old_fb != fb)
intel_wait_for_vblank(dev, intel_crtc->pipe);
mutex_lock(&dev->struct_mutex);
intel_unpin_fb_obj(to_intel_framebuffer(old_fb)->obj);
mutex_unlock(&dev->struct_mutex);
}
mutex_lock(&dev->struct_mutex);
intel_update_fbc(dev);
intel_edp_psr_update(dev);
mutex_unlock(&dev->struct_mutex);
return 0;
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
static bool pipe_has_enabled_pch(struct intel_crtc *crtc)
{
return crtc->base.enabled && crtc->active &&
crtc->config.has_pch_encoder;
}
static void ivb_modeset_global_resources(struct drm_device *dev)
{
struct drm_i915_private *dev_priv = dev->dev_private;
struct intel_crtc *pipe_B_crtc =
to_intel_crtc(dev_priv->pipe_to_crtc_mapping[PIPE_B]);
struct intel_crtc *pipe_C_crtc =
to_intel_crtc(dev_priv->pipe_to_crtc_mapping[PIPE_C]);
uint32_t temp;
if (!pipe_has_enabled_pch(pipe_B_crtc) &&
!pipe_has_enabled_pch(pipe_C_crtc)) {
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
temp &= ~FDI_DP_PORT_WIDTH_MASK;
temp |= FDI_DP_PORT_WIDTH(intel_crtc->config.fdi_lanes);
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
temp &= ~FDI_DP_PORT_WIDTH_MASK;
temp |= FDI_DP_PORT_WIDTH(intel_crtc->config.fdi_lanes);
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
u32 reg, temp, i, j;
reg = FDI_RX_IMR(pipe);
temp = I915_READ(reg);
temp &= ~FDI_RX_SYMBOL_LOCK;
temp &= ~FDI_RX_BIT_LOCK;
I915_WRITE(reg, temp);
POSTING_READ(reg);
udelay(150);
DRM_DEBUG_KMS("FDI_RX_IIR before link train 0x%x\n",
I915_READ(FDI_RX_IIR(pipe)));
for (j = 0; j < ARRAY_SIZE(snb_b_fdi_train_param) * 2; j++) {
reg = FDI_TX_CTL(pipe);
temp = I915_READ(reg);
temp &= ~(FDI_LINK_TRAIN_AUTO | FDI_LINK_TRAIN_NONE_IVB);
temp &= ~FDI_TX_ENABLE;
I915_WRITE(reg, temp);
reg = FDI_RX_CTL(pipe);
temp = I915_READ(reg);
temp &= ~FDI_LINK_TRAIN_AUTO;
temp &= ~FDI_LINK_TRAIN_PATTERN_MASK_CPT;
temp &= ~FDI_RX_ENABLE;
I915_WRITE(reg, temp);
reg = FDI_TX_CTL(pipe);
temp = I915_READ(reg);
temp &= ~FDI_DP_PORT_WIDTH_MASK;
temp |= FDI_DP_PORT_WIDTH(intel_crtc->config.fdi_lanes);
temp |= FDI_LINK_TRAIN_PATTERN_1_IVB;
temp &= ~FDI_LINK_TRAIN_VOL_EMP_MASK;
temp |= snb_b_fdi_train_param[j/2];
temp |= FDI_COMPOSITE_SYNC;
I915_WRITE(reg, temp | FDI_TX_ENABLE);
I915_WRITE(FDI_RX_MISC(pipe),
FDI_RX_TP1_TO_TP2_48 | FDI_RX_FDI_DELAY_90);
reg = FDI_RX_CTL(pipe);
temp = I915_READ(reg);
temp |= FDI_LINK_TRAIN_PATTERN_1_CPT;
temp |= FDI_COMPOSITE_SYNC;
I915_WRITE(reg, temp | FDI_RX_ENABLE);
POSTING_READ(reg);
udelay(1);
for (i = 0; i < 4; i++) {
reg = FDI_RX_IIR(pipe);
temp = I915_READ(reg);
DRM_DEBUG_KMS("FDI_RX_IIR 0x%x\n", temp);
if (temp & FDI_RX_BIT_LOCK ||
(I915_READ(reg) & FDI_RX_BIT_LOCK)) {
I915_WRITE(reg, temp | FDI_RX_BIT_LOCK);
DRM_DEBUG_KMS("FDI train 1 done, level %i.\n",
i);
break;
}
udelay(1);
}
if (i == 4) {
DRM_DEBUG_KMS("FDI train 1 fail on vswing %d\n", j / 2);
continue;
}
reg = FDI_TX_CTL(pipe);
temp = I915_READ(reg);
temp &= ~FDI_LINK_TRAIN_NONE_IVB;
temp |= FDI_LINK_TRAIN_PATTERN_2_IVB;
I915_WRITE(reg, temp);
reg = FDI_RX_CTL(pipe);
temp = I915_READ(reg);
temp &= ~FDI_LINK_TRAIN_PATTERN_MASK_CPT;
temp |= FDI_LINK_TRAIN_PATTERN_2_CPT;
I915_WRITE(reg, temp);
POSTING_READ(reg);
udelay(2);
for (i = 0; i < 4; i++) {
reg = FDI_RX_IIR(pipe);
temp = I915_READ(reg);
DRM_DEBUG_KMS("FDI_RX_IIR 0x%x\n", temp);
if (temp & FDI_RX_SYMBOL_LOCK ||
(I915_READ(reg) & FDI_RX_SYMBOL_LOCK)) {
I915_WRITE(reg, temp | FDI_RX_SYMBOL_LOCK);
DRM_DEBUG_KMS("FDI train 2 done, level %i.\n",
i);
goto train_done;
}
udelay(2);
}
if (i == 4)
DRM_DEBUG_KMS("FDI train 2 fail on vswing %d\n", j / 2);
}
train_done:
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
temp &= ~(FDI_DP_PORT_WIDTH_MASK | (0x7 << 16));
temp |= FDI_DP_PORT_WIDTH(intel_crtc->config.fdi_lanes);
temp |= (I915_READ(PIPECONF(pipe)) & PIPECONF_BPC_MASK) << 11;
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
temp |= (I915_READ(PIPECONF(pipe)) & PIPECONF_BPC_MASK) << 11;
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
temp |= (I915_READ(PIPECONF(pipe)) & PIPECONF_BPC_MASK) << 11;
I915_WRITE(reg, temp);
POSTING_READ(reg);
udelay(100);
}
bool intel_has_pending_fb_unpin(struct drm_device *dev)
{
struct intel_crtc *crtc;
list_for_each_entry(crtc, &dev->mode_config.crtc_list, base.head) {
if (atomic_read(&crtc->unpin_work_count) == 0)
continue;
if (crtc->unpin_work)
intel_wait_for_vblank(dev, crtc->pipe);
return true;
}
return false;
}
static void intel_crtc_wait_for_pending_flips(struct drm_crtc *crtc)
{
struct drm_device *dev = crtc->dev;
struct drm_i915_private *dev_priv = dev->dev_private;
if (crtc->primary->fb == NULL)
return;
WARN_ON(waitqueue_active(&dev_priv->pending_flip_queue));
wait_event(dev_priv->pending_flip_queue,
!intel_crtc_has_pending_flip(crtc));
mutex_lock(&dev->struct_mutex);
intel_finish_fb(crtc->primary->fb);
mutex_unlock(&dev->struct_mutex);
}
static void lpt_program_iclkip(struct drm_crtc *crtc)
{
struct drm_device *dev = crtc->dev;
struct drm_i915_private *dev_priv = dev->dev_private;
int clock = to_intel_crtc(crtc)->config.adjusted_mode.crtc_clock;
u32 divsel, phaseinc, auxdiv, phasedir = 0;
u32 temp;
mutex_lock(&dev_priv->dpio_lock);
I915_WRITE(PIXCLK_GATE, PIXCLK_GATE_GATE);
intel_sbi_write(dev_priv, SBI_SSCCTL6,
intel_sbi_read(dev_priv, SBI_SSCCTL6, SBI_ICLK) |
SBI_SSCCTL_DISABLE,
SBI_ICLK);
if (clock == 20000) {
auxdiv = 1;
divsel = 0x41;
phaseinc = 0x20;
} else {
u32 iclk_virtual_root_freq = 172800 * 1000;
u32 iclk_pi_range = 64;
u32 desired_divisor, msb_divisor_value, pi_value;
desired_divisor = (iclk_virtual_root_freq / clock);
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
clock,
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
mutex_unlock(&dev_priv->dpio_lock);
}
static void ironlake_pch_transcoder_set_timings(struct intel_crtc *crtc,
enum pipe pch_transcoder)
{
struct drm_device *dev = crtc->base.dev;
struct drm_i915_private *dev_priv = dev->dev_private;
enum transcoder cpu_transcoder = crtc->config.cpu_transcoder;
I915_WRITE(PCH_TRANS_HTOTAL(pch_transcoder),
I915_READ(HTOTAL(cpu_transcoder)));
I915_WRITE(PCH_TRANS_HBLANK(pch_transcoder),
I915_READ(HBLANK(cpu_transcoder)));
I915_WRITE(PCH_TRANS_HSYNC(pch_transcoder),
I915_READ(HSYNC(cpu_transcoder)));
I915_WRITE(PCH_TRANS_VTOTAL(pch_transcoder),
I915_READ(VTOTAL(cpu_transcoder)));
I915_WRITE(PCH_TRANS_VBLANK(pch_transcoder),
I915_READ(VBLANK(cpu_transcoder)));
I915_WRITE(PCH_TRANS_VSYNC(pch_transcoder),
I915_READ(VSYNC(cpu_transcoder)));
I915_WRITE(PCH_TRANS_VSYNCSHIFT(pch_transcoder),
I915_READ(VSYNCSHIFT(cpu_transcoder)));
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
static void ivybridge_update_fdi_bc_bifurcation(struct intel_crtc *intel_crtc)
{
struct drm_device *dev = intel_crtc->base.dev;
struct drm_i915_private *dev_priv = dev->dev_private;
switch (intel_crtc->pipe) {
case PIPE_A:
break;
case PIPE_B:
if (intel_crtc->config.fdi_lanes > 2)
WARN_ON(I915_READ(SOUTH_CHICKEN1) & FDI_BC_BIFURCATION_SELECT);
else
cpt_enable_fdi_bc_bifurcation(dev);
break;
case PIPE_C:
cpt_enable_fdi_bc_bifurcation(dev);
break;
default:
BUG();
}
}
static void ironlake_pch_enable(struct drm_crtc *crtc)
{
struct drm_device *dev = crtc->dev;
struct drm_i915_private *dev_priv = dev->dev_private;
struct intel_crtc *intel_crtc = to_intel_crtc(crtc);
int pipe = intel_crtc->pipe;
u32 reg, temp;
assert_pch_transcoder_disabled(dev_priv, pipe);
if (IS_IVYBRIDGE(dev))
ivybridge_update_fdi_bc_bifurcation(intel_crtc);
I915_WRITE(FDI_RX_TUSIZE1(pipe),
I915_READ(PIPE_DATA_M1(pipe)) & TU_SIZE_MASK);
dev_priv->display.fdi_link_train(crtc);
if (HAS_PCH_CPT(dev)) {
u32 sel;
temp = I915_READ(PCH_DPLL_SEL);
temp |= TRANS_DPLL_ENABLE(pipe);
sel = TRANS_DPLLB_SEL(pipe);
if (intel_crtc->config.shared_dpll == DPLL_ID_PCH_PLL_B)
temp |= sel;
else
temp &= ~sel;
I915_WRITE(PCH_DPLL_SEL, temp);
}
ironlake_enable_shared_dpll(intel_crtc);
assert_panel_unlocked(dev_priv, pipe);
ironlake_pch_transcoder_set_timings(intel_crtc, pipe);
intel_fdi_normal_train(crtc);
if (HAS_PCH_CPT(dev) &&
(intel_pipe_has_type(crtc, INTEL_OUTPUT_DISPLAYPORT) ||
intel_pipe_has_type(crtc, INTEL_OUTPUT_EDP))) {
u32 bpc = (I915_READ(PIPECONF(pipe)) & PIPECONF_BPC_MASK) >> 5;
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
enum transcoder cpu_transcoder = intel_crtc->config.cpu_transcoder;
assert_pch_transcoder_disabled(dev_priv, TRANSCODER_A);
lpt_program_iclkip(crtc);
ironlake_pch_transcoder_set_timings(intel_crtc, PIPE_A);
lpt_enable_pch_transcoder(dev_priv, cpu_transcoder);
}
static void intel_put_shared_dpll(struct intel_crtc *crtc)
{
struct intel_shared_dpll *pll = intel_crtc_to_shared_dpll(crtc);
if (pll == NULL)
return;
if (pll->refcount == 0) {
WARN(1, "bad %s refcount\n", pll->name);
return;
}
if (--pll->refcount == 0) {
WARN_ON(pll->on);
WARN_ON(pll->active);
}
crtc->config.shared_dpll = DPLL_ID_PRIVATE;
}
static struct intel_shared_dpll *intel_get_shared_dpll(struct intel_crtc *crtc)
{
struct drm_i915_private *dev_priv = crtc->base.dev->dev_private;
struct intel_shared_dpll *pll = intel_crtc_to_shared_dpll(crtc);
enum intel_dpll_id i;
if (pll) {
DRM_DEBUG_KMS("CRTC:%d dropping existing %s\n",
crtc->base.base.id, pll->name);
intel_put_shared_dpll(crtc);
}
if (HAS_PCH_IBX(dev_priv->dev)) {
i = (enum intel_dpll_id) crtc->pipe;
pll = &dev_priv->shared_dplls[i];
DRM_DEBUG_KMS("CRTC:%d using pre-allocated %s\n",
crtc->base.base.id, pll->name);
goto found;
}
for (i = 0; i < dev_priv->num_shared_dpll; i++) {
pll = &dev_priv->shared_dplls[i];
if (pll->refcount == 0)
continue;
if (memcmp(&crtc->config.dpll_hw_state, &pll->hw_state,
sizeof(pll->hw_state)) == 0) {
DRM_DEBUG_KMS("CRTC:%d sharing existing %s (refcount %d, ative %d)\n",
crtc->base.base.id,
pll->name, pll->refcount, pll->active);
goto found;
}
}
for (i = 0; i < dev_priv->num_shared_dpll; i++) {
pll = &dev_priv->shared_dplls[i];
if (pll->refcount == 0) {
DRM_DEBUG_KMS("CRTC:%d allocated %s\n",
crtc->base.base.id, pll->name);
goto found;
}
}
return NULL;
found:
crtc->config.shared_dpll = i;
DRM_DEBUG_DRIVER("using %s for pipe %c\n", pll->name,
pipe_name(crtc->pipe));
if (pll->active == 0) {
memcpy(&pll->hw_state, &crtc->config.dpll_hw_state,
sizeof(pll->hw_state));
DRM_DEBUG_DRIVER("setting up %s\n", pll->name);
WARN_ON(pll->on);
assert_shared_dpll_disabled(dev_priv, pll);
pll->mode_set(dev_priv, pll);
}
pll->refcount++;
return pll;
}
static void cpt_verify_modeset(struct drm_device *dev, int pipe)
{
struct drm_i915_private *dev_priv = dev->dev_private;
int dslreg = PIPEDSL(pipe);
u32 temp;
temp = I915_READ(dslreg);
udelay(500);
if (wait_for(I915_READ(dslreg) != temp, 5)) {
if (wait_for(I915_READ(dslreg) != temp, 5))
DRM_ERROR("mode set failed: pipe %c stuck\n", pipe_name(pipe));
}
}
static void ironlake_pfit_enable(struct intel_crtc *crtc)
{
struct drm_device *dev = crtc->base.dev;
struct drm_i915_private *dev_priv = dev->dev_private;
int pipe = crtc->pipe;
if (crtc->config.pch_pfit.enabled) {
if (IS_IVYBRIDGE(dev) || IS_HASWELL(dev))
I915_WRITE(PF_CTL(pipe), PF_ENABLE | PF_FILTER_MED_3x3 |
PF_PIPE_SEL_IVB(pipe));
else
I915_WRITE(PF_CTL(pipe), PF_ENABLE | PF_FILTER_MED_3x3);
I915_WRITE(PF_WIN_POS(pipe), crtc->config.pch_pfit.pos);
I915_WRITE(PF_WIN_SZ(pipe), crtc->config.pch_pfit.size);
}
}
static void intel_enable_planes(struct drm_crtc *crtc)
{
struct drm_device *dev = crtc->dev;
enum pipe pipe = to_intel_crtc(crtc)->pipe;
struct drm_plane *plane;
struct intel_plane *intel_plane;
drm_for_each_legacy_plane(plane, &dev->mode_config.plane_list) {
intel_plane = to_intel_plane(plane);
if (intel_plane->pipe == pipe)
intel_plane_restore(&intel_plane->base);
}
}
static void intel_disable_planes(struct drm_crtc *crtc)
{
struct drm_device *dev = crtc->dev;
enum pipe pipe = to_intel_crtc(crtc)->pipe;
struct drm_plane *plane;
struct intel_plane *intel_plane;
drm_for_each_legacy_plane(plane, &dev->mode_config.plane_list) {
intel_plane = to_intel_plane(plane);
if (intel_plane->pipe == pipe)
intel_plane_disable(&intel_plane->base);
}
}
void hsw_enable_ips(struct intel_crtc *crtc)
{
struct drm_i915_private *dev_priv = crtc->base.dev->dev_private;
if (!crtc->config.ips_enabled)
return;
assert_plane_enabled(dev_priv, crtc->plane);
if (IS_BROADWELL(crtc->base.dev)) {
mutex_lock(&dev_priv->rps.hw_lock);
WARN_ON(sandybridge_pcode_write(dev_priv, DISPLAY_IPS_CONTROL, 0xc0000000));
mutex_unlock(&dev_priv->rps.hw_lock);
} else {
I915_WRITE(IPS_CTL, IPS_ENABLE);
if (wait_for(I915_READ_NOTRACE(IPS_CTL) & IPS_ENABLE, 50))
DRM_ERROR("Timed out waiting for IPS enable\n");
}
}
void hsw_disable_ips(struct intel_crtc *crtc)
{
struct drm_device *dev = crtc->base.dev;
struct drm_i915_private *dev_priv = dev->dev_private;
if (!crtc->config.ips_enabled)
return;
assert_plane_enabled(dev_priv, crtc->plane);
if (IS_BROADWELL(crtc->base.dev)) {
mutex_lock(&dev_priv->rps.hw_lock);
WARN_ON(sandybridge_pcode_write(dev_priv, DISPLAY_IPS_CONTROL, 0));
mutex_unlock(&dev_priv->rps.hw_lock);
} else {
I915_WRITE(IPS_CTL, 0);
POSTING_READ(IPS_CTL);
}
intel_wait_for_vblank(dev, crtc->pipe);
}
static void intel_crtc_load_lut(struct drm_crtc *crtc)
{
struct drm_device *dev = crtc->dev;
struct drm_i915_private *dev_priv = dev->dev_private;
struct intel_crtc *intel_crtc = to_intel_crtc(crtc);
enum pipe pipe = intel_crtc->pipe;
int palreg = PALETTE(pipe);
int i;
bool reenable_ips = false;
if (!crtc->enabled || !intel_crtc->active)
return;
if (!HAS_PCH_SPLIT(dev_priv->dev)) {
if (intel_pipe_has_type(crtc, INTEL_OUTPUT_DSI))
assert_dsi_pll_enabled(dev_priv);
else
assert_pll_enabled(dev_priv, pipe);
}
if (HAS_PCH_SPLIT(dev))
palreg = LGC_PALETTE(pipe);
if (IS_HASWELL(dev) && intel_crtc->config.ips_enabled &&
((I915_READ(GAMMA_MODE(pipe)) & GAMMA_MODE_MODE_MASK) ==
GAMMA_MODE_MODE_SPLIT)) {
hsw_disable_ips(intel_crtc);
reenable_ips = true;
}
for (i = 0; i < 256; i++) {
I915_WRITE(palreg + 4 * i,
(intel_crtc->lut_r[i] << 16) |
(intel_crtc->lut_g[i] << 8) |
intel_crtc->lut_b[i]);
}
if (reenable_ips)
hsw_enable_ips(intel_crtc);
}
static void ironlake_crtc_enable(struct drm_crtc *crtc)
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
intel_set_cpu_fifo_underrun_reporting(dev, pipe, true);
intel_set_pch_fifo_underrun_reporting(dev, pipe, true);
for_each_encoder_on_crtc(dev, crtc, encoder)
if (encoder->pre_enable)
encoder->pre_enable(encoder);
if (intel_crtc->config.has_pch_encoder) {
ironlake_fdi_pll_enable(intel_crtc);
} else {
assert_fdi_tx_disabled(dev_priv, pipe);
assert_fdi_rx_disabled(dev_priv, pipe);
}
ironlake_pfit_enable(intel_crtc);
intel_crtc_load_lut(crtc);
intel_update_watermarks(crtc);
intel_enable_pipe(intel_crtc);
intel_enable_primary_hw_plane(dev_priv, plane, pipe);
intel_enable_planes(crtc);
intel_crtc_update_cursor(crtc, true);
if (intel_crtc->config.has_pch_encoder)
ironlake_pch_enable(crtc);
mutex_lock(&dev->struct_mutex);
intel_update_fbc(dev);
mutex_unlock(&dev->struct_mutex);
for_each_encoder_on_crtc(dev, crtc, encoder)
encoder->enable(encoder);
if (HAS_PCH_CPT(dev))
cpt_verify_modeset(dev, intel_crtc->pipe);
intel_wait_for_vblank(dev, intel_crtc->pipe);
}
static bool hsw_crtc_supports_ips(struct intel_crtc *crtc)
{
return HAS_IPS(crtc->base.dev) && crtc->pipe == PIPE_A;
}
static void haswell_crtc_enable_planes(struct drm_crtc *crtc)
{
struct drm_device *dev = crtc->dev;
struct drm_i915_private *dev_priv = dev->dev_private;
struct intel_crtc *intel_crtc = to_intel_crtc(crtc);
int pipe = intel_crtc->pipe;
int plane = intel_crtc->plane;
intel_enable_primary_hw_plane(dev_priv, plane, pipe);
intel_enable_planes(crtc);
intel_crtc_update_cursor(crtc, true);
hsw_enable_ips(intel_crtc);
mutex_lock(&dev->struct_mutex);
intel_update_fbc(dev);
mutex_unlock(&dev->struct_mutex);
}
static void haswell_crtc_disable_planes(struct drm_crtc *crtc)
{
struct drm_device *dev = crtc->dev;
struct drm_i915_private *dev_priv = dev->dev_private;
struct intel_crtc *intel_crtc = to_intel_crtc(crtc);
int pipe = intel_crtc->pipe;
int plane = intel_crtc->plane;
intel_crtc_wait_for_pending_flips(crtc);
drm_vblank_off(dev, pipe);
if (dev_priv->fbc.plane == plane)
intel_disable_fbc(dev);
hsw_disable_ips(intel_crtc);
intel_crtc_update_cursor(crtc, false);
intel_disable_planes(crtc);
intel_disable_primary_hw_plane(dev_priv, plane, pipe);
}
static void haswell_mode_set_planes_workaround(struct intel_crtc *crtc)
{
struct drm_device *dev = crtc->base.dev;
struct intel_crtc *crtc_it, *other_active_crtc = NULL;
list_for_each_entry(crtc_it, &dev->mode_config.crtc_list, base.head) {
if (!crtc_it->active || crtc_it == crtc)
continue;
if (other_active_crtc)
return;
other_active_crtc = crtc_it;
}
if (!other_active_crtc)
return;
intel_wait_for_vblank(dev, other_active_crtc->pipe);
intel_wait_for_vblank(dev, other_active_crtc->pipe);
}
static void haswell_crtc_enable(struct drm_crtc *crtc)
{
struct drm_device *dev = crtc->dev;
struct drm_i915_private *dev_priv = dev->dev_private;
struct intel_crtc *intel_crtc = to_intel_crtc(crtc);
struct intel_encoder *encoder;
int pipe = intel_crtc->pipe;
WARN_ON(!crtc->enabled);
if (intel_crtc->active)
return;
intel_crtc->active = true;
intel_set_cpu_fifo_underrun_reporting(dev, pipe, true);
if (intel_crtc->config.has_pch_encoder)
intel_set_pch_fifo_underrun_reporting(dev, TRANSCODER_A, true);
if (intel_crtc->config.has_pch_encoder)
dev_priv->display.fdi_link_train(crtc);
for_each_encoder_on_crtc(dev, crtc, encoder)
if (encoder->pre_enable)
encoder->pre_enable(encoder);
intel_ddi_enable_pipe_clock(intel_crtc);
ironlake_pfit_enable(intel_crtc);
intel_crtc_load_lut(crtc);
intel_ddi_set_pipe_settings(crtc);
intel_ddi_enable_transcoder_func(crtc);
intel_update_watermarks(crtc);
intel_enable_pipe(intel_crtc);
if (intel_crtc->config.has_pch_encoder)
lpt_pch_enable(crtc);
for_each_encoder_on_crtc(dev, crtc, encoder) {
encoder->enable(encoder);
intel_opregion_notify_encoder(encoder, true);
}
haswell_mode_set_planes_workaround(intel_crtc);
haswell_crtc_enable_planes(crtc);
}
static void ironlake_pfit_disable(struct intel_crtc *crtc)
{
struct drm_device *dev = crtc->base.dev;
struct drm_i915_private *dev_priv = dev->dev_private;
int pipe = crtc->pipe;
if (crtc->config.pch_pfit.enabled) {
I915_WRITE(PF_CTL(pipe), 0);
I915_WRITE(PF_WIN_POS(pipe), 0);
I915_WRITE(PF_WIN_SZ(pipe), 0);
}
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
if (dev_priv->fbc.plane == plane)
intel_disable_fbc(dev);
intel_crtc_update_cursor(crtc, false);
intel_disable_planes(crtc);
intel_disable_primary_hw_plane(dev_priv, plane, pipe);
if (intel_crtc->config.has_pch_encoder)
intel_set_pch_fifo_underrun_reporting(dev, pipe, false);
intel_disable_pipe(dev_priv, pipe);
ironlake_pfit_disable(intel_crtc);
for_each_encoder_on_crtc(dev, crtc, encoder)
if (encoder->post_disable)
encoder->post_disable(encoder);
if (intel_crtc->config.has_pch_encoder) {
ironlake_fdi_disable(crtc);
ironlake_disable_pch_transcoder(dev_priv, pipe);
intel_set_pch_fifo_underrun_reporting(dev, pipe, true);
if (HAS_PCH_CPT(dev)) {
reg = TRANS_DP_CTL(pipe);
temp = I915_READ(reg);
temp &= ~(TRANS_DP_OUTPUT_ENABLE |
TRANS_DP_PORT_SEL_MASK);
temp |= TRANS_DP_PORT_SEL_NONE;
I915_WRITE(reg, temp);
temp = I915_READ(PCH_DPLL_SEL);
temp &= ~(TRANS_DPLL_ENABLE(pipe) | TRANS_DPLLB_SEL(pipe));
I915_WRITE(PCH_DPLL_SEL, temp);
}
intel_disable_shared_dpll(intel_crtc);
ironlake_fdi_pll_disable(intel_crtc);
}
intel_crtc->active = false;
intel_update_watermarks(crtc);
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
enum transcoder cpu_transcoder = intel_crtc->config.cpu_transcoder;
if (!intel_crtc->active)
return;
haswell_crtc_disable_planes(crtc);
for_each_encoder_on_crtc(dev, crtc, encoder) {
intel_opregion_notify_encoder(encoder, false);
encoder->disable(encoder);
}
if (intel_crtc->config.has_pch_encoder)
intel_set_pch_fifo_underrun_reporting(dev, TRANSCODER_A, false);
intel_disable_pipe(dev_priv, pipe);
intel_ddi_disable_transcoder_func(dev_priv, cpu_transcoder);
ironlake_pfit_disable(intel_crtc);
intel_ddi_disable_pipe_clock(intel_crtc);
for_each_encoder_on_crtc(dev, crtc, encoder)
if (encoder->post_disable)
encoder->post_disable(encoder);
if (intel_crtc->config.has_pch_encoder) {
lpt_disable_pch_transcoder(dev_priv);
intel_set_pch_fifo_underrun_reporting(dev, TRANSCODER_A, true);
intel_ddi_fdi_disable(crtc);
}
intel_crtc->active = false;
intel_update_watermarks(crtc);
mutex_lock(&dev->struct_mutex);
intel_update_fbc(dev);
mutex_unlock(&dev->struct_mutex);
}
static void ironlake_crtc_off(struct drm_crtc *crtc)
{
struct intel_crtc *intel_crtc = to_intel_crtc(crtc);
intel_put_shared_dpll(intel_crtc);
}
static void haswell_crtc_off(struct drm_crtc *crtc)
{
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
static void
g4x_fixup_plane(struct drm_i915_private *dev_priv, enum pipe pipe)
{
u32 cntl = I915_READ(CURCNTR(pipe));
if ((cntl & CURSOR_MODE) == 0) {
u32 fw_bcl_self = I915_READ(FW_BLC_SELF);
I915_WRITE(FW_BLC_SELF, fw_bcl_self & ~FW_BLC_SELF_EN);
I915_WRITE(CURCNTR(pipe), CURSOR_MODE_64_ARGB_AX);
intel_wait_for_vblank(dev_priv->dev, pipe);
I915_WRITE(CURCNTR(pipe), cntl);
I915_WRITE(CURBASE(pipe), I915_READ(CURBASE(pipe)));
I915_WRITE(FW_BLC_SELF, fw_bcl_self);
}
}
static void i9xx_pfit_enable(struct intel_crtc *crtc)
{
struct drm_device *dev = crtc->base.dev;
struct drm_i915_private *dev_priv = dev->dev_private;
struct intel_crtc_config *pipe_config = &crtc->config;
if (!crtc->config.gmch_pfit.control)
return;
WARN_ON(I915_READ(PFIT_CONTROL) & PFIT_ENABLE);
assert_pipe_disabled(dev_priv, crtc->pipe);
I915_WRITE(PFIT_PGM_RATIOS, pipe_config->gmch_pfit.pgm_ratios);
I915_WRITE(PFIT_CONTROL, pipe_config->gmch_pfit.control);
I915_WRITE(BCLRPAT(crtc->pipe), 0);
}
enum intel_display_power_domain
intel_display_port_power_domain(struct intel_encoder *intel_encoder)
{
struct drm_device *dev = intel_encoder->base.dev;
struct intel_digital_port *intel_dig_port;
switch (intel_encoder->type) {
case INTEL_OUTPUT_UNKNOWN:
WARN_ON_ONCE(!HAS_DDI(dev));
case INTEL_OUTPUT_DISPLAYPORT:
case INTEL_OUTPUT_HDMI:
case INTEL_OUTPUT_EDP:
intel_dig_port = enc_to_dig_port(&intel_encoder->base);
switch (intel_dig_port->port) {
case PORT_A:
return POWER_DOMAIN_PORT_DDI_A_4_LANES;
case PORT_B:
return POWER_DOMAIN_PORT_DDI_B_4_LANES;
case PORT_C:
return POWER_DOMAIN_PORT_DDI_C_4_LANES;
case PORT_D:
return POWER_DOMAIN_PORT_DDI_D_4_LANES;
default:
WARN_ON_ONCE(1);
return POWER_DOMAIN_PORT_OTHER;
}
case INTEL_OUTPUT_ANALOG:
return POWER_DOMAIN_PORT_CRT;
case INTEL_OUTPUT_DSI:
return POWER_DOMAIN_PORT_DSI;
default:
return POWER_DOMAIN_PORT_OTHER;
}
}
static unsigned long get_crtc_power_domains(struct drm_crtc *crtc)
{
struct drm_device *dev = crtc->dev;
struct intel_encoder *intel_encoder;
struct intel_crtc *intel_crtc = to_intel_crtc(crtc);
enum pipe pipe = intel_crtc->pipe;
bool pfit_enabled = intel_crtc->config.pch_pfit.enabled;
unsigned long mask;
enum transcoder transcoder;
transcoder = intel_pipe_to_cpu_transcoder(dev->dev_private, pipe);
mask = BIT(POWER_DOMAIN_PIPE(pipe));
mask |= BIT(POWER_DOMAIN_TRANSCODER(transcoder));
if (pfit_enabled)
mask |= BIT(POWER_DOMAIN_PIPE_PANEL_FITTER(pipe));
for_each_encoder_on_crtc(dev, crtc, intel_encoder)
mask |= BIT(intel_display_port_power_domain(intel_encoder));
return mask;
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
static void modeset_update_crtc_power_domains(struct drm_device *dev)
{
struct drm_i915_private *dev_priv = dev->dev_private;
unsigned long pipe_domains[I915_MAX_PIPES] = { 0, };
struct intel_crtc *crtc;
list_for_each_entry(crtc, &dev->mode_config.crtc_list, base.head) {
enum intel_display_power_domain domain;
if (!crtc->base.enabled)
continue;
pipe_domains[crtc->pipe] = get_crtc_power_domains(&crtc->base);
for_each_power_domain(domain, pipe_domains[crtc->pipe])
intel_display_power_get(dev_priv, domain);
}
list_for_each_entry(crtc, &dev->mode_config.crtc_list, base.head) {
enum intel_display_power_domain domain;
for_each_power_domain(domain, crtc->enabled_power_domains)
intel_display_power_put(dev_priv, domain);
crtc->enabled_power_domains = pipe_domains[crtc->pipe];
}
intel_display_set_init_power(dev_priv, false);
}
int valleyview_get_vco(struct drm_i915_private *dev_priv)
{
int hpll_freq, vco_freq[] = { 800, 1600, 2000, 2400 };
mutex_lock(&dev_priv->dpio_lock);
hpll_freq = vlv_cck_read(dev_priv, CCK_FUSE_REG) &
CCK_FUSE_HPLL_FREQ_MASK;
mutex_unlock(&dev_priv->dpio_lock);
return vco_freq[hpll_freq];
}
static void valleyview_set_cdclk(struct drm_device *dev, int cdclk)
{
struct drm_i915_private *dev_priv = dev->dev_private;
u32 val, cmd;
if (cdclk >= 320)
cmd = 2;
else if (cdclk == 266)
cmd = 1;
else
cmd = 0;
mutex_lock(&dev_priv->rps.hw_lock);
val = vlv_punit_read(dev_priv, PUNIT_REG_DSPFREQ);
val &= ~DSPFREQGUAR_MASK;
val |= (cmd << DSPFREQGUAR_SHIFT);
vlv_punit_write(dev_priv, PUNIT_REG_DSPFREQ, val);
if (wait_for((vlv_punit_read(dev_priv, PUNIT_REG_DSPFREQ) &
DSPFREQSTAT_MASK) == (cmd << DSPFREQSTAT_SHIFT),
50)) {
DRM_ERROR("timed out waiting for CDclk change\n");
}
mutex_unlock(&dev_priv->rps.hw_lock);
if (cdclk == 400) {
u32 divider, vco;
vco = valleyview_get_vco(dev_priv);
divider = ((vco << 1) / cdclk) - 1;
mutex_lock(&dev_priv->dpio_lock);
val = vlv_cck_read(dev_priv, CCK_DISPLAY_CLOCK_CONTROL);
val &= ~0xf;
val |= divider;
vlv_cck_write(dev_priv, CCK_DISPLAY_CLOCK_CONTROL, val);
mutex_unlock(&dev_priv->dpio_lock);
}
mutex_lock(&dev_priv->dpio_lock);
val = vlv_bunit_read(dev_priv, BUNIT_REG_BISOC);
val &= ~0x7f;
if (cdclk == 400)
val |= 4500 / 250;
else
val |= 3000 / 250;
vlv_bunit_write(dev_priv, BUNIT_REG_BISOC, val);
mutex_unlock(&dev_priv->dpio_lock);
intel_i2c_reset(dev);
}
static int valleyview_cur_cdclk(struct drm_i915_private *dev_priv)
{
int cur_cdclk, vco;
int divider;
vco = valleyview_get_vco(dev_priv);
mutex_lock(&dev_priv->dpio_lock);
divider = vlv_cck_read(dev_priv, CCK_DISPLAY_CLOCK_CONTROL);
mutex_unlock(&dev_priv->dpio_lock);
divider &= 0xf;
cur_cdclk = (vco << 1) / (divider + 1);
return cur_cdclk;
}
static int valleyview_calc_cdclk(struct drm_i915_private *dev_priv,
int max_pixclk)
{
int cur_cdclk;
cur_cdclk = valleyview_cur_cdclk(dev_priv);
if (max_pixclk > 288000) {
return 400;
} else if (max_pixclk > 240000) {
return 320;
} else
return 266;
}
static int intel_mode_max_pixclk(struct drm_i915_private *dev_priv)
{
struct drm_device *dev = dev_priv->dev;
struct intel_crtc *intel_crtc;
int max_pixclk = 0;
list_for_each_entry(intel_crtc, &dev->mode_config.crtc_list,
base.head) {
if (intel_crtc->new_enabled)
max_pixclk = max(max_pixclk,
intel_crtc->new_config->adjusted_mode.crtc_clock);
}
return max_pixclk;
}
static void valleyview_modeset_global_pipes(struct drm_device *dev,
unsigned *prepare_pipes)
{
struct drm_i915_private *dev_priv = dev->dev_private;
struct intel_crtc *intel_crtc;
int max_pixclk = intel_mode_max_pixclk(dev_priv);
int cur_cdclk = valleyview_cur_cdclk(dev_priv);
if (valleyview_calc_cdclk(dev_priv, max_pixclk) == cur_cdclk)
return;
list_for_each_entry(intel_crtc, &dev->mode_config.crtc_list,
base.head)
if (intel_crtc->base.enabled)
*prepare_pipes |= (1 << intel_crtc->pipe);
}
static void valleyview_modeset_global_resources(struct drm_device *dev)
{
struct drm_i915_private *dev_priv = dev->dev_private;
int max_pixclk = intel_mode_max_pixclk(dev_priv);
int cur_cdclk = valleyview_cur_cdclk(dev_priv);
int req_cdclk = valleyview_calc_cdclk(dev_priv, max_pixclk);
if (req_cdclk != cur_cdclk)
valleyview_set_cdclk(dev, req_cdclk);
modeset_update_crtc_power_domains(dev);
}
static void valleyview_crtc_enable(struct drm_crtc *crtc)
{
struct drm_device *dev = crtc->dev;
struct drm_i915_private *dev_priv = dev->dev_private;
struct intel_crtc *intel_crtc = to_intel_crtc(crtc);
struct intel_encoder *encoder;
int pipe = intel_crtc->pipe;
int plane = intel_crtc->plane;
bool is_dsi;
WARN_ON(!crtc->enabled);
if (intel_crtc->active)
return;
intel_crtc->active = true;
for_each_encoder_on_crtc(dev, crtc, encoder)
if (encoder->pre_pll_enable)
encoder->pre_pll_enable(encoder);
is_dsi = intel_pipe_has_type(crtc, INTEL_OUTPUT_DSI);
if (!is_dsi)
vlv_enable_pll(intel_crtc);
for_each_encoder_on_crtc(dev, crtc, encoder)
if (encoder->pre_enable)
encoder->pre_enable(encoder);
i9xx_pfit_enable(intel_crtc);
intel_crtc_load_lut(crtc);
intel_update_watermarks(crtc);
intel_enable_pipe(intel_crtc);
intel_set_cpu_fifo_underrun_reporting(dev, pipe, true);
intel_enable_primary_hw_plane(dev_priv, plane, pipe);
intel_enable_planes(crtc);
intel_crtc_update_cursor(crtc, true);
intel_update_fbc(dev);
for_each_encoder_on_crtc(dev, crtc, encoder)
encoder->enable(encoder);
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
for_each_encoder_on_crtc(dev, crtc, encoder)
if (encoder->pre_enable)
encoder->pre_enable(encoder);
i9xx_enable_pll(intel_crtc);
i9xx_pfit_enable(intel_crtc);
intel_crtc_load_lut(crtc);
intel_update_watermarks(crtc);
intel_enable_pipe(intel_crtc);
intel_set_cpu_fifo_underrun_reporting(dev, pipe, true);
intel_enable_primary_hw_plane(dev_priv, plane, pipe);
intel_enable_planes(crtc);
if (IS_G4X(dev))
g4x_fixup_plane(dev_priv, pipe);
intel_crtc_update_cursor(crtc, true);
intel_crtc_dpms_overlay(intel_crtc, true);
intel_update_fbc(dev);
for_each_encoder_on_crtc(dev, crtc, encoder)
encoder->enable(encoder);
}
static void i9xx_pfit_disable(struct intel_crtc *crtc)
{
struct drm_device *dev = crtc->base.dev;
struct drm_i915_private *dev_priv = dev->dev_private;
if (!crtc->config.gmch_pfit.control)
return;
assert_pipe_disabled(dev_priv, crtc->pipe);
DRM_DEBUG_DRIVER("disabling pfit, current: 0x%08x\n",
I915_READ(PFIT_CONTROL));
I915_WRITE(PFIT_CONTROL, 0);
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
if (dev_priv->fbc.plane == plane)
intel_disable_fbc(dev);
intel_crtc_dpms_overlay(intel_crtc, false);
intel_crtc_update_cursor(crtc, false);
intel_disable_planes(crtc);
intel_disable_primary_hw_plane(dev_priv, plane, pipe);
intel_set_cpu_fifo_underrun_reporting(dev, pipe, false);
intel_disable_pipe(dev_priv, pipe);
i9xx_pfit_disable(intel_crtc);
for_each_encoder_on_crtc(dev, crtc, encoder)
if (encoder->post_disable)
encoder->post_disable(encoder);
if (IS_VALLEYVIEW(dev) && !intel_pipe_has_type(crtc, INTEL_OUTPUT_DSI))
vlv_disable_pll(dev_priv, pipe);
else if (!IS_VALLEYVIEW(dev))
i9xx_disable_pll(dev_priv, pipe);
intel_crtc->active = false;
intel_update_watermarks(crtc);
intel_update_fbc(dev);
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
static void intel_crtc_disable(struct drm_crtc *crtc)
{
struct drm_device *dev = crtc->dev;
struct drm_connector *connector;
struct drm_i915_private *dev_priv = dev->dev_private;
struct intel_crtc *intel_crtc = to_intel_crtc(crtc);
WARN_ON(!crtc->enabled);
dev_priv->display.crtc_disable(crtc);
intel_crtc->eld_vld = false;
intel_crtc_update_sarea(crtc, false);
dev_priv->display.off(crtc);
assert_plane_disabled(dev->dev_private, to_intel_crtc(crtc)->plane);
assert_cursor_disabled(dev_priv, to_intel_crtc(crtc)->pipe);
assert_pipe_disabled(dev->dev_private, to_intel_crtc(crtc)->pipe);
if (crtc->primary->fb) {
mutex_lock(&dev->struct_mutex);
intel_unpin_fb_obj(to_intel_framebuffer(crtc->primary->fb)->obj);
mutex_unlock(&dev->struct_mutex);
crtc->primary->fb = NULL;
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
void intel_encoder_destroy(struct drm_encoder *encoder)
{
struct intel_encoder *intel_encoder = to_intel_encoder(encoder);
drm_encoder_cleanup(encoder);
kfree(intel_encoder);
}
static void intel_encoder_dpms(struct intel_encoder *encoder, int mode)
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
if (mode != DRM_MODE_DPMS_ON)
mode = DRM_MODE_DPMS_OFF;
if (mode == connector->dpms)
return;
connector->dpms = mode;
if (connector->encoder)
intel_encoder_dpms(to_intel_encoder(connector->encoder), mode);
intel_modeset_check_state(connector->dev);
}
bool intel_connector_get_hw_state(struct intel_connector *connector)
{
enum pipe pipe = 0;
struct intel_encoder *encoder = connector->encoder;
return encoder->get_hw_state(encoder, &pipe);
}
static bool ironlake_check_fdi_lanes(struct drm_device *dev, enum pipe pipe,
struct intel_crtc_config *pipe_config)
{
struct drm_i915_private *dev_priv = dev->dev_private;
struct intel_crtc *pipe_B_crtc =
to_intel_crtc(dev_priv->pipe_to_crtc_mapping[PIPE_B]);
DRM_DEBUG_KMS("checking fdi config on pipe %c, lanes %i\n",
pipe_name(pipe), pipe_config->fdi_lanes);
if (pipe_config->fdi_lanes > 4) {
DRM_DEBUG_KMS("invalid fdi lane config on pipe %c: %i lanes\n",
pipe_name(pipe), pipe_config->fdi_lanes);
return false;
}
if (IS_HASWELL(dev) || IS_BROADWELL(dev)) {
if (pipe_config->fdi_lanes > 2) {
DRM_DEBUG_KMS("only 2 lanes on haswell, required: %i lanes\n",
pipe_config->fdi_lanes);
return false;
} else {
return true;
}
}
if (INTEL_INFO(dev)->num_pipes == 2)
return true;
switch (pipe) {
case PIPE_A:
return true;
case PIPE_B:
if (dev_priv->pipe_to_crtc_mapping[PIPE_C]->enabled &&
pipe_config->fdi_lanes > 2) {
DRM_DEBUG_KMS("invalid shared fdi lane config on pipe %c: %i lanes\n",
pipe_name(pipe), pipe_config->fdi_lanes);
return false;
}
return true;
case PIPE_C:
if (!pipe_has_enabled_pch(pipe_B_crtc) ||
pipe_B_crtc->config.fdi_lanes <= 2) {
if (pipe_config->fdi_lanes > 2) {
DRM_DEBUG_KMS("invalid shared fdi lane config on pipe %c: %i lanes\n",
pipe_name(pipe), pipe_config->fdi_lanes);
return false;
}
} else {
DRM_DEBUG_KMS("fdi link B uses too many lanes to enable link C\n");
return false;
}
return true;
default:
BUG();
}
}
static int ironlake_fdi_compute_config(struct intel_crtc *intel_crtc,
struct intel_crtc_config *pipe_config)
{
struct drm_device *dev = intel_crtc->base.dev;
struct drm_display_mode *adjusted_mode = &pipe_config->adjusted_mode;
int lane, link_bw, fdi_dotclock;
bool setup_ok, needs_recompute = false;
retry:
link_bw = intel_fdi_link_freq(dev) * MHz(100)/KHz(1)/10;
fdi_dotclock = adjusted_mode->crtc_clock;
lane = ironlake_get_lanes_required(fdi_dotclock, link_bw,
pipe_config->pipe_bpp);
pipe_config->fdi_lanes = lane;
intel_link_compute_m_n(pipe_config->pipe_bpp, lane, fdi_dotclock,
link_bw, &pipe_config->fdi_m_n);
setup_ok = ironlake_check_fdi_lanes(intel_crtc->base.dev,
intel_crtc->pipe, pipe_config);
if (!setup_ok && pipe_config->pipe_bpp > 6*3) {
pipe_config->pipe_bpp -= 2*3;
DRM_DEBUG_KMS("fdi link bw constraint, reducing pipe bpp to %i\n",
pipe_config->pipe_bpp);
needs_recompute = true;
pipe_config->bw_constrained = true;
goto retry;
}
if (needs_recompute)
return RETRY;
return setup_ok ? 0 : -EINVAL;
}
static void hsw_compute_ips_config(struct intel_crtc *crtc,
struct intel_crtc_config *pipe_config)
{
pipe_config->ips_enabled = i915.enable_ips &&
hsw_crtc_supports_ips(crtc) &&
pipe_config->pipe_bpp <= 24;
}
static int intel_crtc_compute_config(struct intel_crtc *crtc,
struct intel_crtc_config *pipe_config)
{
struct drm_device *dev = crtc->base.dev;
struct drm_display_mode *adjusted_mode = &pipe_config->adjusted_mode;
if (INTEL_INFO(dev)->gen < 4) {
struct drm_i915_private *dev_priv = dev->dev_private;
int clock_limit =
dev_priv->display.get_display_clock_speed(dev);
if ((crtc->pipe == PIPE_A || IS_I915G(dev)) &&
adjusted_mode->crtc_clock > clock_limit * 9 / 10) {
clock_limit *= 2;
pipe_config->double_wide = true;
}
if (adjusted_mode->crtc_clock > clock_limit * 9 / 10)
return -EINVAL;
}
if ((intel_pipe_has_type(&crtc->base, INTEL_OUTPUT_LVDS) &&
intel_is_dual_link_lvds(dev)) || pipe_config->double_wide)
pipe_config->pipe_src_w &= ~1;
if ((INTEL_INFO(dev)->gen > 4 || IS_G4X(dev)) &&
adjusted_mode->hsync_start == adjusted_mode->hdisplay)
return -EINVAL;
if ((IS_G4X(dev) || IS_VALLEYVIEW(dev)) && pipe_config->pipe_bpp > 10*3) {
pipe_config->pipe_bpp = 10*3;
} else if (INTEL_INFO(dev)->gen <= 4 && pipe_config->pipe_bpp > 8*3) {
pipe_config->pipe_bpp = 8*3;
}
if (HAS_IPS(dev))
hsw_compute_ips_config(crtc, pipe_config);
if (HAS_PCH_IBX(dev) || HAS_PCH_CPT(dev))
pipe_config->shared_dpll = crtc->config.shared_dpll;
if (pipe_config->has_pch_encoder)
return ironlake_fdi_compute_config(crtc, pipe_config);
return 0;
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
static int pnv_get_display_clock_speed(struct drm_device *dev)
{
u16 gcfgc = 0;
pci_read_config_word(dev->pdev, GCFGC, &gcfgc);
switch (gcfgc & GC_DISPLAY_CLOCK_MASK) {
case GC_DISPLAY_CLOCK_267_MHZ_PNV:
return 267000;
case GC_DISPLAY_CLOCK_333_MHZ_PNV:
return 333000;
case GC_DISPLAY_CLOCK_444_MHZ_PNV:
return 444000;
case GC_DISPLAY_CLOCK_200_MHZ_PNV:
return 200000;
default:
DRM_ERROR("Unknown pnv display core clock 0x%04x\n", gcfgc);
case GC_DISPLAY_CLOCK_133_MHZ_PNV:
return 133000;
case GC_DISPLAY_CLOCK_167_MHZ_PNV:
return 167000;
}
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
intel_reduce_m_n_ratio(uint32_t *num, uint32_t *den)
{
while (*num > DATA_LINK_M_N_MASK ||
*den > DATA_LINK_M_N_MASK) {
*num >>= 1;
*den >>= 1;
}
}
static void compute_m_n(unsigned int m, unsigned int n,
uint32_t *ret_m, uint32_t *ret_n)
{
*ret_n = min_t(unsigned int, roundup_pow_of_two(n), DATA_LINK_N_MAX);
*ret_m = div_u64((uint64_t) m * *ret_n, n);
intel_reduce_m_n_ratio(ret_m, ret_n);
}
void
intel_link_compute_m_n(int bits_per_pixel, int nlanes,
int pixel_clock, int link_clock,
struct intel_link_m_n *m_n)
{
m_n->tu = 64;
compute_m_n(bits_per_pixel * pixel_clock,
link_clock * nlanes * 8,
&m_n->gmch_m, &m_n->gmch_n);
compute_m_n(pixel_clock, link_clock,
&m_n->link_m, &m_n->link_n);
}
static inline bool intel_panel_use_ssc(struct drm_i915_private *dev_priv)
{
if (i915.panel_use_ssc >= 0)
return i915.panel_use_ssc != 0;
return dev_priv->vbt.lvds_use_ssc
&& !(dev_priv->quirks & QUIRK_LVDS_SSC_DISABLE);
}
static int i9xx_get_refclk(struct drm_crtc *crtc, int num_connectors)
{
struct drm_device *dev = crtc->dev;
struct drm_i915_private *dev_priv = dev->dev_private;
int refclk;
if (IS_VALLEYVIEW(dev)) {
refclk = 100000;
} else if (intel_pipe_has_type(crtc, INTEL_OUTPUT_LVDS) &&
intel_panel_use_ssc(dev_priv) && num_connectors < 2) {
refclk = dev_priv->vbt.lvds_ssc_freq;
DRM_DEBUG_KMS("using SSC reference clock of %d kHz\n", refclk);
} else if (!IS_GEN2(dev)) {
refclk = 96000;
} else {
refclk = 48000;
}
return refclk;
}
static uint32_t pnv_dpll_compute_fp(struct dpll *dpll)
{
return (1 << dpll->n) << 16 | dpll->m2;
}
static uint32_t i9xx_dpll_compute_fp(struct dpll *dpll)
{
return dpll->n << 16 | dpll->m1 << 8 | dpll->m2;
}
static void i9xx_update_pll_dividers(struct intel_crtc *crtc,
intel_clock_t *reduced_clock)
{
struct drm_device *dev = crtc->base.dev;
struct drm_i915_private *dev_priv = dev->dev_private;
int pipe = crtc->pipe;
u32 fp, fp2 = 0;
if (IS_PINEVIEW(dev)) {
fp = pnv_dpll_compute_fp(&crtc->config.dpll);
if (reduced_clock)
fp2 = pnv_dpll_compute_fp(reduced_clock);
} else {
fp = i9xx_dpll_compute_fp(&crtc->config.dpll);
if (reduced_clock)
fp2 = i9xx_dpll_compute_fp(reduced_clock);
}
I915_WRITE(FP0(pipe), fp);
crtc->config.dpll_hw_state.fp0 = fp;
crtc->lowfreq_avail = false;
if (intel_pipe_has_type(&crtc->base, INTEL_OUTPUT_LVDS) &&
reduced_clock && i915.powersave) {
I915_WRITE(FP1(pipe), fp2);
crtc->config.dpll_hw_state.fp1 = fp2;
crtc->lowfreq_avail = true;
} else {
I915_WRITE(FP1(pipe), fp);
crtc->config.dpll_hw_state.fp1 = fp;
}
}
static void vlv_pllb_recal_opamp(struct drm_i915_private *dev_priv, enum pipe
pipe)
{
u32 reg_val;
reg_val = vlv_dpio_read(dev_priv, pipe, VLV_PLL_DW9(1));
reg_val &= 0xffffff00;
reg_val |= 0x00000030;
vlv_dpio_write(dev_priv, pipe, VLV_PLL_DW9(1), reg_val);
reg_val = vlv_dpio_read(dev_priv, pipe, VLV_REF_DW13);
reg_val &= 0x8cffffff;
reg_val = 0x8c000000;
vlv_dpio_write(dev_priv, pipe, VLV_REF_DW13, reg_val);
reg_val = vlv_dpio_read(dev_priv, pipe, VLV_PLL_DW9(1));
reg_val &= 0xffffff00;
vlv_dpio_write(dev_priv, pipe, VLV_PLL_DW9(1), reg_val);
reg_val = vlv_dpio_read(dev_priv, pipe, VLV_REF_DW13);
reg_val &= 0x00ffffff;
reg_val |= 0xb0000000;
vlv_dpio_write(dev_priv, pipe, VLV_REF_DW13, reg_val);
}
static void intel_pch_transcoder_set_m_n(struct intel_crtc *crtc,
struct intel_link_m_n *m_n)
{
struct drm_device *dev = crtc->base.dev;
struct drm_i915_private *dev_priv = dev->dev_private;
int pipe = crtc->pipe;
I915_WRITE(PCH_TRANS_DATA_M1(pipe), TU_SIZE(m_n->tu) | m_n->gmch_m);
I915_WRITE(PCH_TRANS_DATA_N1(pipe), m_n->gmch_n);
I915_WRITE(PCH_TRANS_LINK_M1(pipe), m_n->link_m);
I915_WRITE(PCH_TRANS_LINK_N1(pipe), m_n->link_n);
}
static void intel_cpu_transcoder_set_m_n(struct intel_crtc *crtc,
struct intel_link_m_n *m_n)
{
struct drm_device *dev = crtc->base.dev;
struct drm_i915_private *dev_priv = dev->dev_private;
int pipe = crtc->pipe;
enum transcoder transcoder = crtc->config.cpu_transcoder;
if (INTEL_INFO(dev)->gen >= 5) {
I915_WRITE(PIPE_DATA_M1(transcoder), TU_SIZE(m_n->tu) | m_n->gmch_m);
I915_WRITE(PIPE_DATA_N1(transcoder), m_n->gmch_n);
I915_WRITE(PIPE_LINK_M1(transcoder), m_n->link_m);
I915_WRITE(PIPE_LINK_N1(transcoder), m_n->link_n);
} else {
I915_WRITE(PIPE_DATA_M_G4X(pipe), TU_SIZE(m_n->tu) | m_n->gmch_m);
I915_WRITE(PIPE_DATA_N_G4X(pipe), m_n->gmch_n);
I915_WRITE(PIPE_LINK_M_G4X(pipe), m_n->link_m);
I915_WRITE(PIPE_LINK_N_G4X(pipe), m_n->link_n);
}
}
static void intel_dp_set_m_n(struct intel_crtc *crtc)
{
if (crtc->config.has_pch_encoder)
intel_pch_transcoder_set_m_n(crtc, &crtc->config.dp_m_n);
else
intel_cpu_transcoder_set_m_n(crtc, &crtc->config.dp_m_n);
}
static void vlv_update_pll(struct intel_crtc *crtc)
{
struct drm_device *dev = crtc->base.dev;
struct drm_i915_private *dev_priv = dev->dev_private;
int pipe = crtc->pipe;
u32 dpll, mdiv;
u32 bestn, bestm1, bestm2, bestp1, bestp2;
u32 coreclk, reg_val, dpll_md;
mutex_lock(&dev_priv->dpio_lock);
bestn = crtc->config.dpll.n;
bestm1 = crtc->config.dpll.m1;
bestm2 = crtc->config.dpll.m2;
bestp1 = crtc->config.dpll.p1;
bestp2 = crtc->config.dpll.p2;
if (pipe)
vlv_pllb_recal_opamp(dev_priv, pipe);
vlv_dpio_write(dev_priv, pipe, VLV_PLL_DW9_BCAST, 0x0100000f);
reg_val = vlv_dpio_read(dev_priv, pipe, VLV_PLL_DW8(pipe));
reg_val &= 0x00ffffff;
vlv_dpio_write(dev_priv, pipe, VLV_PLL_DW8(pipe), reg_val);
vlv_dpio_write(dev_priv, pipe, VLV_CMN_DW0, 0x610);
mdiv = ((bestm1 << DPIO_M1DIV_SHIFT) | (bestm2 & DPIO_M2DIV_MASK));
mdiv |= ((bestp1 << DPIO_P1_SHIFT) | (bestp2 << DPIO_P2_SHIFT));
mdiv |= ((bestn << DPIO_N_SHIFT));
mdiv |= (1 << DPIO_K_SHIFT);
mdiv |= (DPIO_POST_DIV_HDMIDP << DPIO_POST_DIV_SHIFT);
vlv_dpio_write(dev_priv, pipe, VLV_PLL_DW3(pipe), mdiv);
mdiv |= DPIO_ENABLE_CALIBRATION;
vlv_dpio_write(dev_priv, pipe, VLV_PLL_DW3(pipe), mdiv);
if (crtc->config.port_clock == 162000 ||
intel_pipe_has_type(&crtc->base, INTEL_OUTPUT_ANALOG) ||
intel_pipe_has_type(&crtc->base, INTEL_OUTPUT_HDMI))
vlv_dpio_write(dev_priv, pipe, VLV_PLL_DW10(pipe),
0x009f0003);
else
vlv_dpio_write(dev_priv, pipe, VLV_PLL_DW10(pipe),
0x00d0000f);
if (intel_pipe_has_type(&crtc->base, INTEL_OUTPUT_EDP) ||
intel_pipe_has_type(&crtc->base, INTEL_OUTPUT_DISPLAYPORT)) {
if (!pipe)
vlv_dpio_write(dev_priv, pipe, VLV_PLL_DW5(pipe),
0x0df40000);
else
vlv_dpio_write(dev_priv, pipe, VLV_PLL_DW5(pipe),
0x0df70000);
} else {
if (!pipe)
vlv_dpio_write(dev_priv, pipe, VLV_PLL_DW5(pipe),
0x0df70000);
else
vlv_dpio_write(dev_priv, pipe, VLV_PLL_DW5(pipe),
0x0df40000);
}
coreclk = vlv_dpio_read(dev_priv, pipe, VLV_PLL_DW7(pipe));
coreclk = (coreclk & 0x0000ff00) | 0x01c00000;
if (intel_pipe_has_type(&crtc->base, INTEL_OUTPUT_DISPLAYPORT) ||
intel_pipe_has_type(&crtc->base, INTEL_OUTPUT_EDP))
coreclk |= 0x01000000;
vlv_dpio_write(dev_priv, pipe, VLV_PLL_DW7(pipe), coreclk);
vlv_dpio_write(dev_priv, pipe, VLV_PLL_DW11(pipe), 0x87871000);
dpll = DPLL_EXT_BUFFER_ENABLE_VLV | DPLL_REFA_CLK_ENABLE_VLV |
DPLL_VGA_MODE_DIS | DPLL_INTEGRATED_CLOCK_VLV;
if (pipe == PIPE_B)
dpll |= DPLL_INTEGRATED_CRI_CLK_VLV;
dpll |= DPLL_VCO_ENABLE;
crtc->config.dpll_hw_state.dpll = dpll;
dpll_md = (crtc->config.pixel_multiplier - 1)
<< DPLL_MD_UDI_MULTIPLIER_SHIFT;
crtc->config.dpll_hw_state.dpll_md = dpll_md;
if (crtc->config.has_dp_encoder)
intel_dp_set_m_n(crtc);
mutex_unlock(&dev_priv->dpio_lock);
}
static void i9xx_update_pll(struct intel_crtc *crtc,
intel_clock_t *reduced_clock,
int num_connectors)
{
struct drm_device *dev = crtc->base.dev;
struct drm_i915_private *dev_priv = dev->dev_private;
u32 dpll;
bool is_sdvo;
struct dpll *clock = &crtc->config.dpll;
i9xx_update_pll_dividers(crtc, reduced_clock);
is_sdvo = intel_pipe_has_type(&crtc->base, INTEL_OUTPUT_SDVO) ||
intel_pipe_has_type(&crtc->base, INTEL_OUTPUT_HDMI);
dpll = DPLL_VGA_MODE_DIS;
if (intel_pipe_has_type(&crtc->base, INTEL_OUTPUT_LVDS))
dpll |= DPLLB_MODE_LVDS;
else
dpll |= DPLLB_MODE_DAC_SERIAL;
if (IS_I945G(dev) || IS_I945GM(dev) || IS_G33(dev)) {
dpll |= (crtc->config.pixel_multiplier - 1)
<< SDVO_MULTIPLIER_SHIFT_HIRES;
}
if (is_sdvo)
dpll |= DPLL_SDVO_HIGH_SPEED;
if (intel_pipe_has_type(&crtc->base, INTEL_OUTPUT_DISPLAYPORT))
dpll |= DPLL_SDVO_HIGH_SPEED;
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
if (crtc->config.sdvo_tv_clock)
dpll |= PLL_REF_INPUT_TVCLKINBC;
else if (intel_pipe_has_type(&crtc->base, INTEL_OUTPUT_LVDS) &&
intel_panel_use_ssc(dev_priv) && num_connectors < 2)
dpll |= PLLB_REF_INPUT_SPREADSPECTRUMIN;
else
dpll |= PLL_REF_INPUT_DREFCLK;
dpll |= DPLL_VCO_ENABLE;
crtc->config.dpll_hw_state.dpll = dpll;
if (INTEL_INFO(dev)->gen >= 4) {
u32 dpll_md = (crtc->config.pixel_multiplier - 1)
<< DPLL_MD_UDI_MULTIPLIER_SHIFT;
crtc->config.dpll_hw_state.dpll_md = dpll_md;
}
if (crtc->config.has_dp_encoder)
intel_dp_set_m_n(crtc);
}
static void i8xx_update_pll(struct intel_crtc *crtc,
intel_clock_t *reduced_clock,
int num_connectors)
{
struct drm_device *dev = crtc->base.dev;
struct drm_i915_private *dev_priv = dev->dev_private;
u32 dpll;
struct dpll *clock = &crtc->config.dpll;
i9xx_update_pll_dividers(crtc, reduced_clock);
dpll = DPLL_VGA_MODE_DIS;
if (intel_pipe_has_type(&crtc->base, INTEL_OUTPUT_LVDS)) {
dpll |= (1 << (clock->p1 - 1)) << DPLL_FPA01_P1_POST_DIV_SHIFT;
} else {
if (clock->p1 == 2)
dpll |= PLL_P1_DIVIDE_BY_TWO;
else
dpll |= (clock->p1 - 2) << DPLL_FPA01_P1_POST_DIV_SHIFT;
if (clock->p2 == 4)
dpll |= PLL_P2_DIVIDE_BY_4;
}
if (intel_pipe_has_type(&crtc->base, INTEL_OUTPUT_DVO))
dpll |= DPLL_DVO_2X_MODE;
if (intel_pipe_has_type(&crtc->base, INTEL_OUTPUT_LVDS) &&
intel_panel_use_ssc(dev_priv) && num_connectors < 2)
dpll |= PLLB_REF_INPUT_SPREADSPECTRUMIN;
else
dpll |= PLL_REF_INPUT_DREFCLK;
dpll |= DPLL_VCO_ENABLE;
crtc->config.dpll_hw_state.dpll = dpll;
}
static void intel_set_pipe_timings(struct intel_crtc *intel_crtc)
{
struct drm_device *dev = intel_crtc->base.dev;
struct drm_i915_private *dev_priv = dev->dev_private;
enum pipe pipe = intel_crtc->pipe;
enum transcoder cpu_transcoder = intel_crtc->config.cpu_transcoder;
struct drm_display_mode *adjusted_mode =
&intel_crtc->config.adjusted_mode;
uint32_t crtc_vtotal, crtc_vblank_end;
int vsyncshift = 0;
crtc_vtotal = adjusted_mode->crtc_vtotal;
crtc_vblank_end = adjusted_mode->crtc_vblank_end;
if (adjusted_mode->flags & DRM_MODE_FLAG_INTERLACE) {
crtc_vtotal -= 1;
crtc_vblank_end -= 1;
if (intel_pipe_has_type(&intel_crtc->base, INTEL_OUTPUT_SDVO))
vsyncshift = (adjusted_mode->crtc_htotal - 1) / 2;
else
vsyncshift = adjusted_mode->crtc_hsync_start -
adjusted_mode->crtc_htotal / 2;
if (vsyncshift < 0)
vsyncshift += adjusted_mode->crtc_htotal;
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
((crtc_vtotal - 1) << 16));
I915_WRITE(VBLANK(cpu_transcoder),
(adjusted_mode->crtc_vblank_start - 1) |
((crtc_vblank_end - 1) << 16));
I915_WRITE(VSYNC(cpu_transcoder),
(adjusted_mode->crtc_vsync_start - 1) |
((adjusted_mode->crtc_vsync_end - 1) << 16));
if (IS_HASWELL(dev) && cpu_transcoder == TRANSCODER_EDP &&
(pipe == PIPE_B || pipe == PIPE_C))
I915_WRITE(VTOTAL(pipe), I915_READ(VTOTAL(cpu_transcoder)));
I915_WRITE(PIPESRC(pipe),
((intel_crtc->config.pipe_src_w - 1) << 16) |
(intel_crtc->config.pipe_src_h - 1));
}
static void intel_get_pipe_timings(struct intel_crtc *crtc,
struct intel_crtc_config *pipe_config)
{
struct drm_device *dev = crtc->base.dev;
struct drm_i915_private *dev_priv = dev->dev_private;
enum transcoder cpu_transcoder = pipe_config->cpu_transcoder;
uint32_t tmp;
tmp = I915_READ(HTOTAL(cpu_transcoder));
pipe_config->adjusted_mode.crtc_hdisplay = (tmp & 0xffff) + 1;
pipe_config->adjusted_mode.crtc_htotal = ((tmp >> 16) & 0xffff) + 1;
tmp = I915_READ(HBLANK(cpu_transcoder));
pipe_config->adjusted_mode.crtc_hblank_start = (tmp & 0xffff) + 1;
pipe_config->adjusted_mode.crtc_hblank_end = ((tmp >> 16) & 0xffff) + 1;
tmp = I915_READ(HSYNC(cpu_transcoder));
pipe_config->adjusted_mode.crtc_hsync_start = (tmp & 0xffff) + 1;
pipe_config->adjusted_mode.crtc_hsync_end = ((tmp >> 16) & 0xffff) + 1;
tmp = I915_READ(VTOTAL(cpu_transcoder));
pipe_config->adjusted_mode.crtc_vdisplay = (tmp & 0xffff) + 1;
pipe_config->adjusted_mode.crtc_vtotal = ((tmp >> 16) & 0xffff) + 1;
tmp = I915_READ(VBLANK(cpu_transcoder));
pipe_config->adjusted_mode.crtc_vblank_start = (tmp & 0xffff) + 1;
pipe_config->adjusted_mode.crtc_vblank_end = ((tmp >> 16) & 0xffff) + 1;
tmp = I915_READ(VSYNC(cpu_transcoder));
pipe_config->adjusted_mode.crtc_vsync_start = (tmp & 0xffff) + 1;
pipe_config->adjusted_mode.crtc_vsync_end = ((tmp >> 16) & 0xffff) + 1;
if (I915_READ(PIPECONF(cpu_transcoder)) & PIPECONF_INTERLACE_MASK) {
pipe_config->adjusted_mode.flags |= DRM_MODE_FLAG_INTERLACE;
pipe_config->adjusted_mode.crtc_vtotal += 1;
pipe_config->adjusted_mode.crtc_vblank_end += 1;
}
tmp = I915_READ(PIPESRC(crtc->pipe));
pipe_config->pipe_src_h = (tmp & 0xffff) + 1;
pipe_config->pipe_src_w = ((tmp >> 16) & 0xffff) + 1;
pipe_config->requested_mode.vdisplay = pipe_config->pipe_src_h;
pipe_config->requested_mode.hdisplay = pipe_config->pipe_src_w;
}
void intel_mode_from_pipe_config(struct drm_display_mode *mode,
struct intel_crtc_config *pipe_config)
{
mode->hdisplay = pipe_config->adjusted_mode.crtc_hdisplay;
mode->htotal = pipe_config->adjusted_mode.crtc_htotal;
mode->hsync_start = pipe_config->adjusted_mode.crtc_hsync_start;
mode->hsync_end = pipe_config->adjusted_mode.crtc_hsync_end;
mode->vdisplay = pipe_config->adjusted_mode.crtc_vdisplay;
mode->vtotal = pipe_config->adjusted_mode.crtc_vtotal;
mode->vsync_start = pipe_config->adjusted_mode.crtc_vsync_start;
mode->vsync_end = pipe_config->adjusted_mode.crtc_vsync_end;
mode->flags = pipe_config->adjusted_mode.flags;
mode->clock = pipe_config->adjusted_mode.crtc_clock;
mode->flags |= pipe_config->adjusted_mode.flags;
}
static void i9xx_set_pipeconf(struct intel_crtc *intel_crtc)
{
struct drm_device *dev = intel_crtc->base.dev;
struct drm_i915_private *dev_priv = dev->dev_private;
uint32_t pipeconf;
pipeconf = 0;
if (dev_priv->quirks & QUIRK_PIPEA_FORCE &&
I915_READ(PIPECONF(intel_crtc->pipe)) & PIPECONF_ENABLE)
pipeconf |= PIPECONF_ENABLE;
if (intel_crtc->config.double_wide)
pipeconf |= PIPECONF_DOUBLE_WIDE;
if (IS_G4X(dev) || IS_VALLEYVIEW(dev)) {
if (intel_crtc->config.dither && intel_crtc->config.pipe_bpp != 30)
pipeconf |= PIPECONF_DITHER_EN |
PIPECONF_DITHER_TYPE_SP;
switch (intel_crtc->config.pipe_bpp) {
case 18:
pipeconf |= PIPECONF_6BPC;
break;
case 24:
pipeconf |= PIPECONF_8BPC;
break;
case 30:
pipeconf |= PIPECONF_10BPC;
break;
default:
BUG();
}
}
if (HAS_PIPE_CXSR(dev)) {
if (intel_crtc->lowfreq_avail) {
DRM_DEBUG_KMS("enabling CxSR downclocking\n");
pipeconf |= PIPECONF_CXSR_DOWNCLOCK;
} else {
DRM_DEBUG_KMS("disabling CxSR downclocking\n");
}
}
if (intel_crtc->config.adjusted_mode.flags & DRM_MODE_FLAG_INTERLACE) {
if (INTEL_INFO(dev)->gen < 4 ||
intel_pipe_has_type(&intel_crtc->base, INTEL_OUTPUT_SDVO))
pipeconf |= PIPECONF_INTERLACE_W_FIELD_INDICATION;
else
pipeconf |= PIPECONF_INTERLACE_W_SYNC_SHIFT;
} else
pipeconf |= PIPECONF_PROGRESSIVE;
if (IS_VALLEYVIEW(dev) && intel_crtc->config.limited_color_range)
pipeconf |= PIPECONF_COLOR_RANGE_SELECT;
I915_WRITE(PIPECONF(intel_crtc->pipe), pipeconf);
POSTING_READ(PIPECONF(intel_crtc->pipe));
}
static int i9xx_crtc_mode_set(struct drm_crtc *crtc,
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
u32 dspcntr;
bool ok, has_reduced_clock = false;
bool is_lvds = false, is_dsi = false;
struct intel_encoder *encoder;
const intel_limit_t *limit;
int ret;
for_each_encoder_on_crtc(dev, crtc, encoder) {
switch (encoder->type) {
case INTEL_OUTPUT_LVDS:
is_lvds = true;
break;
case INTEL_OUTPUT_DSI:
is_dsi = true;
break;
}
num_connectors++;
}
if (is_dsi)
goto skip_dpll;
if (!intel_crtc->config.clock_set) {
refclk = i9xx_get_refclk(crtc, num_connectors);
limit = intel_limit(crtc, refclk);
ok = dev_priv->display.find_dpll(limit, crtc,
intel_crtc->config.port_clock,
refclk, NULL, &clock);
if (!ok) {
DRM_ERROR("Couldn't find PLL settings for mode!\n");
return -EINVAL;
}
if (is_lvds && dev_priv->lvds_downclock_avail) {
has_reduced_clock =
dev_priv->display.find_dpll(limit, crtc,
dev_priv->lvds_downclock,
refclk, &clock,
&reduced_clock);
}
intel_crtc->config.dpll.n = clock.n;
intel_crtc->config.dpll.m1 = clock.m1;
intel_crtc->config.dpll.m2 = clock.m2;
intel_crtc->config.dpll.p1 = clock.p1;
intel_crtc->config.dpll.p2 = clock.p2;
}
if (IS_GEN2(dev)) {
i8xx_update_pll(intel_crtc,
has_reduced_clock ? &reduced_clock : NULL,
num_connectors);
} else if (IS_VALLEYVIEW(dev)) {
vlv_update_pll(intel_crtc);
} else {
i9xx_update_pll(intel_crtc,
has_reduced_clock ? &reduced_clock : NULL,
num_connectors);
}
skip_dpll:
dspcntr = DISPPLANE_GAMMA_ENABLE;
if (!IS_VALLEYVIEW(dev)) {
if (pipe == 0)
dspcntr &= ~DISPPLANE_SEL_PIPE_MASK;
else
dspcntr |= DISPPLANE_SEL_PIPE_B;
}
intel_set_pipe_timings(intel_crtc);
I915_WRITE(DSPSIZE(plane),
((intel_crtc->config.pipe_src_h - 1) << 16) |
(intel_crtc->config.pipe_src_w - 1));
I915_WRITE(DSPPOS(plane), 0);
i9xx_set_pipeconf(intel_crtc);
I915_WRITE(DSPCNTR(plane), dspcntr);
POSTING_READ(DSPCNTR(plane));
ret = intel_pipe_set_base(crtc, x, y, fb);
return ret;
}
static void i9xx_get_pfit_config(struct intel_crtc *crtc,
struct intel_crtc_config *pipe_config)
{
struct drm_device *dev = crtc->base.dev;
struct drm_i915_private *dev_priv = dev->dev_private;
uint32_t tmp;
if (INTEL_INFO(dev)->gen <= 3 && (IS_I830(dev) || !IS_MOBILE(dev)))
return;
tmp = I915_READ(PFIT_CONTROL);
if (!(tmp & PFIT_ENABLE))
return;
if (INTEL_INFO(dev)->gen < 4) {
if (crtc->pipe != PIPE_B)
return;
} else {
if ((tmp & PFIT_PIPE_MASK) != (crtc->pipe << PFIT_PIPE_SHIFT))
return;
}
pipe_config->gmch_pfit.control = tmp;
pipe_config->gmch_pfit.pgm_ratios = I915_READ(PFIT_PGM_RATIOS);
if (INTEL_INFO(dev)->gen < 5)
pipe_config->gmch_pfit.lvds_border_bits =
I915_READ(LVDS) & LVDS_BORDER_ENABLE;
}
static void vlv_crtc_clock_get(struct intel_crtc *crtc,
struct intel_crtc_config *pipe_config)
{
struct drm_device *dev = crtc->base.dev;
struct drm_i915_private *dev_priv = dev->dev_private;
int pipe = pipe_config->cpu_transcoder;
intel_clock_t clock;
u32 mdiv;
int refclk = 100000;
mutex_lock(&dev_priv->dpio_lock);
mdiv = vlv_dpio_read(dev_priv, pipe, VLV_PLL_DW3(pipe));
mutex_unlock(&dev_priv->dpio_lock);
clock.m1 = (mdiv >> DPIO_M1DIV_SHIFT) & 7;
clock.m2 = mdiv & DPIO_M2DIV_MASK;
clock.n = (mdiv >> DPIO_N_SHIFT) & 0xf;
clock.p1 = (mdiv >> DPIO_P1_SHIFT) & 7;
clock.p2 = (mdiv >> DPIO_P2_SHIFT) & 0x1f;
vlv_clock(refclk, &clock);
pipe_config->port_clock = clock.dot / 5;
}
static void i9xx_get_plane_config(struct intel_crtc *crtc,
struct intel_plane_config *plane_config)
{
struct drm_device *dev = crtc->base.dev;
struct drm_i915_private *dev_priv = dev->dev_private;
u32 val, base, offset;
int pipe = crtc->pipe, plane = crtc->plane;
int fourcc, pixel_format;
int aligned_height;
crtc->base.primary->fb = kzalloc(sizeof(struct intel_framebuffer), GFP_KERNEL);
if (!crtc->base.primary->fb) {
DRM_DEBUG_KMS("failed to alloc fb\n");
return;
}
val = I915_READ(DSPCNTR(plane));
if (INTEL_INFO(dev)->gen >= 4)
if (val & DISPPLANE_TILED)
plane_config->tiled = true;
pixel_format = val & DISPPLANE_PIXFORMAT_MASK;
fourcc = intel_format_to_fourcc(pixel_format);
crtc->base.primary->fb->pixel_format = fourcc;
crtc->base.primary->fb->bits_per_pixel =
drm_format_plane_cpp(fourcc, 0) * 8;
if (INTEL_INFO(dev)->gen >= 4) {
if (plane_config->tiled)
offset = I915_READ(DSPTILEOFF(plane));
else
offset = I915_READ(DSPLINOFF(plane));
base = I915_READ(DSPSURF(plane)) & 0xfffff000;
} else {
base = I915_READ(DSPADDR(plane));
}
plane_config->base = base;
val = I915_READ(PIPESRC(pipe));
crtc->base.primary->fb->width = ((val >> 16) & 0xfff) + 1;
crtc->base.primary->fb->height = ((val >> 0) & 0xfff) + 1;
val = I915_READ(DSPSTRIDE(pipe));
crtc->base.primary->fb->pitches[0] = val & 0xffffff80;
aligned_height = intel_align_height(dev, crtc->base.primary->fb->height,
plane_config->tiled);
plane_config->size = ALIGN(crtc->base.primary->fb->pitches[0] *
aligned_height, PAGE_SIZE);
DRM_DEBUG_KMS("pipe/plane %d/%d with fb: size=%dx%d@%d, offset=%x, pitch %d, size 0x%x\n",
pipe, plane, crtc->base.primary->fb->width,
crtc->base.primary->fb->height,
crtc->base.primary->fb->bits_per_pixel, base,
crtc->base.primary->fb->pitches[0],
plane_config->size);
}
static bool i9xx_get_pipe_config(struct intel_crtc *crtc,
struct intel_crtc_config *pipe_config)
{
struct drm_device *dev = crtc->base.dev;
struct drm_i915_private *dev_priv = dev->dev_private;
uint32_t tmp;
if (!intel_display_power_enabled(dev_priv,
POWER_DOMAIN_PIPE(crtc->pipe)))
return false;
pipe_config->cpu_transcoder = (enum transcoder) crtc->pipe;
pipe_config->shared_dpll = DPLL_ID_PRIVATE;
tmp = I915_READ(PIPECONF(crtc->pipe));
if (!(tmp & PIPECONF_ENABLE))
return false;
if (IS_G4X(dev) || IS_VALLEYVIEW(dev)) {
switch (tmp & PIPECONF_BPC_MASK) {
case PIPECONF_6BPC:
pipe_config->pipe_bpp = 18;
break;
case PIPECONF_8BPC:
pipe_config->pipe_bpp = 24;
break;
case PIPECONF_10BPC:
pipe_config->pipe_bpp = 30;
break;
default:
break;
}
}
if (INTEL_INFO(dev)->gen < 4)
pipe_config->double_wide = tmp & PIPECONF_DOUBLE_WIDE;
intel_get_pipe_timings(crtc, pipe_config);
i9xx_get_pfit_config(crtc, pipe_config);
if (INTEL_INFO(dev)->gen >= 4) {
tmp = I915_READ(DPLL_MD(crtc->pipe));
pipe_config->pixel_multiplier =
((tmp & DPLL_MD_UDI_MULTIPLIER_MASK)
>> DPLL_MD_UDI_MULTIPLIER_SHIFT) + 1;
pipe_config->dpll_hw_state.dpll_md = tmp;
} else if (IS_I945G(dev) || IS_I945GM(dev) || IS_G33(dev)) {
tmp = I915_READ(DPLL(crtc->pipe));
pipe_config->pixel_multiplier =
((tmp & SDVO_MULTIPLIER_MASK)
>> SDVO_MULTIPLIER_SHIFT_HIRES) + 1;
} else {
pipe_config->pixel_multiplier = 1;
}
pipe_config->dpll_hw_state.dpll = I915_READ(DPLL(crtc->pipe));
if (!IS_VALLEYVIEW(dev)) {
pipe_config->dpll_hw_state.fp0 = I915_READ(FP0(crtc->pipe));
pipe_config->dpll_hw_state.fp1 = I915_READ(FP1(crtc->pipe));
} else {
pipe_config->dpll_hw_state.dpll &= ~(DPLL_LOCK_VLV |
DPLL_PORTC_READY_MASK |
DPLL_PORTB_READY_MASK);
}
if (IS_VALLEYVIEW(dev))
vlv_crtc_clock_get(crtc, pipe_config);
else
i9xx_crtc_clock_get(crtc, pipe_config);
return true;
}
static void ironlake_init_pch_refclk(struct drm_device *dev)
{
struct drm_i915_private *dev_priv = dev->dev_private;
struct drm_mode_config *mode_config = &dev->mode_config;
struct intel_encoder *encoder;
u32 val, final;
bool has_lvds = false;
bool has_cpu_edp = false;
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
if (enc_to_dig_port(&encoder->base)->port == PORT_A)
has_cpu_edp = true;
break;
}
}
if (HAS_PCH_IBX(dev)) {
has_ck505 = dev_priv->vbt.display_clock_mode;
can_ssc = has_ck505;
} else {
has_ck505 = false;
can_ssc = true;
}
DRM_DEBUG_KMS("has_panel %d has_lvds %d has_ck505 %d\n",
has_panel, has_lvds, has_ck505);
val = I915_READ(PCH_DREF_CONTROL);
final = val;
final &= ~DREF_NONSPREAD_SOURCE_MASK;
if (has_ck505)
final |= DREF_NONSPREAD_CK505_ENABLE;
else
final |= DREF_NONSPREAD_SOURCE_ENABLE;
final &= ~DREF_SSC_SOURCE_MASK;
final &= ~DREF_CPU_SOURCE_OUTPUT_MASK;
final &= ~DREF_SSC1_ENABLE;
if (has_panel) {
final |= DREF_SSC_SOURCE_ENABLE;
if (intel_panel_use_ssc(dev_priv) && can_ssc)
final |= DREF_SSC1_ENABLE;
if (has_cpu_edp) {
if (intel_panel_use_ssc(dev_priv) && can_ssc)
final |= DREF_CPU_SOURCE_OUTPUT_DOWNSPREAD;
else
final |= DREF_CPU_SOURCE_OUTPUT_NONSPREAD;
} else
final |= DREF_CPU_SOURCE_OUTPUT_DISABLE;
} else {
final |= DREF_SSC_SOURCE_DISABLE;
final |= DREF_CPU_SOURCE_OUTPUT_DISABLE;
}
if (final == val)
return;
val &= ~DREF_NONSPREAD_SOURCE_MASK;
if (has_ck505)
val |= DREF_NONSPREAD_CK505_ENABLE;
else
val |= DREF_NONSPREAD_SOURCE_ENABLE;
if (has_panel) {
val &= ~DREF_SSC_SOURCE_MASK;
val |= DREF_SSC_SOURCE_ENABLE;
if (intel_panel_use_ssc(dev_priv) && can_ssc) {
DRM_DEBUG_KMS("Using SSC on panel\n");
val |= DREF_SSC1_ENABLE;
} else
val &= ~DREF_SSC1_ENABLE;
I915_WRITE(PCH_DREF_CONTROL, val);
POSTING_READ(PCH_DREF_CONTROL);
udelay(200);
val &= ~DREF_CPU_SOURCE_OUTPUT_MASK;
if (has_cpu_edp) {
if (intel_panel_use_ssc(dev_priv) && can_ssc) {
DRM_DEBUG_KMS("Using SSC on eDP\n");
val |= DREF_CPU_SOURCE_OUTPUT_DOWNSPREAD;
}
else
val |= DREF_CPU_SOURCE_OUTPUT_NONSPREAD;
} else
val |= DREF_CPU_SOURCE_OUTPUT_DISABLE;
I915_WRITE(PCH_DREF_CONTROL, val);
POSTING_READ(PCH_DREF_CONTROL);
udelay(200);
} else {
DRM_DEBUG_KMS("Disabling SSC entirely\n");
val &= ~DREF_CPU_SOURCE_OUTPUT_MASK;
val |= DREF_CPU_SOURCE_OUTPUT_DISABLE;
I915_WRITE(PCH_DREF_CONTROL, val);
POSTING_READ(PCH_DREF_CONTROL);
udelay(200);
val &= ~DREF_SSC_SOURCE_MASK;
val |= DREF_SSC_SOURCE_DISABLE;
val &= ~DREF_SSC1_ENABLE;
I915_WRITE(PCH_DREF_CONTROL, val);
POSTING_READ(PCH_DREF_CONTROL);
udelay(200);
}
BUG_ON(val != final);
}
static void lpt_reset_fdi_mphy(struct drm_i915_private *dev_priv)
{
uint32_t tmp;
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
FDI_MPHY_IOSFSB_RESET_STATUS) == 0, 100))
DRM_ERROR("FDI mPHY reset de-assert timeout\n");
}
static void lpt_program_fdi_mphy(struct drm_i915_private *dev_priv)
{
uint32_t tmp;
tmp = intel_sbi_read(dev_priv, 0x8008, SBI_MPHY);
tmp &= ~(0xFF << 24);
tmp |= (0x12 << 24);
intel_sbi_write(dev_priv, 0x8008, tmp, SBI_MPHY);
tmp = intel_sbi_read(dev_priv, 0x2008, SBI_MPHY);
tmp |= (1 << 11);
intel_sbi_write(dev_priv, 0x2008, tmp, SBI_MPHY);
tmp = intel_sbi_read(dev_priv, 0x2108, SBI_MPHY);
tmp |= (1 << 11);
intel_sbi_write(dev_priv, 0x2108, tmp, SBI_MPHY);
tmp = intel_sbi_read(dev_priv, 0x206C, SBI_MPHY);
tmp |= (1 << 24) | (1 << 21) | (1 << 18);
intel_sbi_write(dev_priv, 0x206C, tmp, SBI_MPHY);
tmp = intel_sbi_read(dev_priv, 0x216C, SBI_MPHY);
tmp |= (1 << 24) | (1 << 21) | (1 << 18);
intel_sbi_write(dev_priv, 0x216C, tmp, SBI_MPHY);
tmp = intel_sbi_read(dev_priv, 0x2080, SBI_MPHY);
tmp &= ~(7 << 13);
tmp |= (5 << 13);
intel_sbi_write(dev_priv, 0x2080, tmp, SBI_MPHY);
tmp = intel_sbi_read(dev_priv, 0x2180, SBI_MPHY);
tmp &= ~(7 << 13);
tmp |= (5 << 13);
intel_sbi_write(dev_priv, 0x2180, tmp, SBI_MPHY);
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
static void lpt_enable_clkout_dp(struct drm_device *dev, bool with_spread,
bool with_fdi)
{
struct drm_i915_private *dev_priv = dev->dev_private;
uint32_t reg, tmp;
if (WARN(with_fdi && !with_spread, "FDI requires downspread\n"))
with_spread = true;
if (WARN(dev_priv->pch_id == INTEL_PCH_LPT_LP_DEVICE_ID_TYPE &&
with_fdi, "LP PCH doesn't have FDI\n"))
with_fdi = false;
mutex_lock(&dev_priv->dpio_lock);
tmp = intel_sbi_read(dev_priv, SBI_SSCCTL, SBI_ICLK);
tmp &= ~SBI_SSCCTL_DISABLE;
tmp |= SBI_SSCCTL_PATHALT;
intel_sbi_write(dev_priv, SBI_SSCCTL, tmp, SBI_ICLK);
udelay(24);
if (with_spread) {
tmp = intel_sbi_read(dev_priv, SBI_SSCCTL, SBI_ICLK);
tmp &= ~SBI_SSCCTL_PATHALT;
intel_sbi_write(dev_priv, SBI_SSCCTL, tmp, SBI_ICLK);
if (with_fdi) {
lpt_reset_fdi_mphy(dev_priv);
lpt_program_fdi_mphy(dev_priv);
}
}
reg = (dev_priv->pch_id == INTEL_PCH_LPT_LP_DEVICE_ID_TYPE) ?
SBI_GEN0 : SBI_DBUFF0;
tmp = intel_sbi_read(dev_priv, reg, SBI_ICLK);
tmp |= SBI_GEN0_CFG_BUFFENABLE_DISABLE;
intel_sbi_write(dev_priv, reg, tmp, SBI_ICLK);
mutex_unlock(&dev_priv->dpio_lock);
}
static void lpt_disable_clkout_dp(struct drm_device *dev)
{
struct drm_i915_private *dev_priv = dev->dev_private;
uint32_t reg, tmp;
mutex_lock(&dev_priv->dpio_lock);
reg = (dev_priv->pch_id == INTEL_PCH_LPT_LP_DEVICE_ID_TYPE) ?
SBI_GEN0 : SBI_DBUFF0;
tmp = intel_sbi_read(dev_priv, reg, SBI_ICLK);
tmp &= ~SBI_GEN0_CFG_BUFFENABLE_DISABLE;
intel_sbi_write(dev_priv, reg, tmp, SBI_ICLK);
tmp = intel_sbi_read(dev_priv, SBI_SSCCTL, SBI_ICLK);
if (!(tmp & SBI_SSCCTL_DISABLE)) {
if (!(tmp & SBI_SSCCTL_PATHALT)) {
tmp |= SBI_SSCCTL_PATHALT;
intel_sbi_write(dev_priv, SBI_SSCCTL, tmp, SBI_ICLK);
udelay(32);
}
tmp |= SBI_SSCCTL_DISABLE;
intel_sbi_write(dev_priv, SBI_SSCCTL, tmp, SBI_ICLK);
}
mutex_unlock(&dev_priv->dpio_lock);
}
static void lpt_init_pch_refclk(struct drm_device *dev)
{
struct drm_mode_config *mode_config = &dev->mode_config;
struct intel_encoder *encoder;
bool has_vga = false;
list_for_each_entry(encoder, &mode_config->encoder_list, base.head) {
switch (encoder->type) {
case INTEL_OUTPUT_ANALOG:
has_vga = true;
break;
}
}
if (has_vga)
lpt_enable_clkout_dp(dev, true, true);
else
lpt_disable_clkout_dp(dev);
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
int num_connectors = 0;
bool is_lvds = false;
for_each_encoder_on_crtc(dev, crtc, encoder) {
switch (encoder->type) {
case INTEL_OUTPUT_LVDS:
is_lvds = true;
break;
}
num_connectors++;
}
if (is_lvds && intel_panel_use_ssc(dev_priv) && num_connectors < 2) {
DRM_DEBUG_KMS("using SSC reference clock of %d kHz\n",
dev_priv->vbt.lvds_ssc_freq);
return dev_priv->vbt.lvds_ssc_freq;
}
return 120000;
}
static void ironlake_set_pipeconf(struct drm_crtc *crtc)
{
struct drm_i915_private *dev_priv = crtc->dev->dev_private;
struct intel_crtc *intel_crtc = to_intel_crtc(crtc);
int pipe = intel_crtc->pipe;
uint32_t val;
val = 0;
switch (intel_crtc->config.pipe_bpp) {
case 18:
val |= PIPECONF_6BPC;
break;
case 24:
val |= PIPECONF_8BPC;
break;
case 30:
val |= PIPECONF_10BPC;
break;
case 36:
val |= PIPECONF_12BPC;
break;
default:
BUG();
}
if (intel_crtc->config.dither)
val |= (PIPECONF_DITHER_EN | PIPECONF_DITHER_TYPE_SP);
if (intel_crtc->config.adjusted_mode.flags & DRM_MODE_FLAG_INTERLACE)
val |= PIPECONF_INTERLACED_ILK;
else
val |= PIPECONF_PROGRESSIVE;
if (intel_crtc->config.limited_color_range)
val |= PIPECONF_COLOR_RANGE_SELECT;
I915_WRITE(PIPECONF(pipe), val);
POSTING_READ(PIPECONF(pipe));
}
static void intel_set_pipe_csc(struct drm_crtc *crtc)
{
struct drm_device *dev = crtc->dev;
struct drm_i915_private *dev_priv = dev->dev_private;
struct intel_crtc *intel_crtc = to_intel_crtc(crtc);
int pipe = intel_crtc->pipe;
uint16_t coeff = 0x7800;
if (intel_crtc->config.limited_color_range)
coeff = ((235 - 16) * (1 << 12) / 255) & 0xff8;
I915_WRITE(PIPE_CSC_COEFF_RY_GY(pipe), coeff << 16);
I915_WRITE(PIPE_CSC_COEFF_BY(pipe), 0);
I915_WRITE(PIPE_CSC_COEFF_RU_GU(pipe), coeff);
I915_WRITE(PIPE_CSC_COEFF_BU(pipe), 0);
I915_WRITE(PIPE_CSC_COEFF_RV_GV(pipe), 0);
I915_WRITE(PIPE_CSC_COEFF_BV(pipe), coeff << 16);
I915_WRITE(PIPE_CSC_PREOFF_HI(pipe), 0);
I915_WRITE(PIPE_CSC_PREOFF_ME(pipe), 0);
I915_WRITE(PIPE_CSC_PREOFF_LO(pipe), 0);
if (INTEL_INFO(dev)->gen > 6) {
uint16_t postoff = 0;
if (intel_crtc->config.limited_color_range)
postoff = (16 * (1 << 12) / 255) & 0x1fff;
I915_WRITE(PIPE_CSC_POSTOFF_HI(pipe), postoff);
I915_WRITE(PIPE_CSC_POSTOFF_ME(pipe), postoff);
I915_WRITE(PIPE_CSC_POSTOFF_LO(pipe), postoff);
I915_WRITE(PIPE_CSC_MODE(pipe), 0);
} else {
uint32_t mode = CSC_MODE_YUV_TO_RGB;
if (intel_crtc->config.limited_color_range)
mode |= CSC_BLACK_SCREEN_OFFSET;
I915_WRITE(PIPE_CSC_MODE(pipe), mode);
}
}
static void haswell_set_pipeconf(struct drm_crtc *crtc)
{
struct drm_device *dev = crtc->dev;
struct drm_i915_private *dev_priv = dev->dev_private;
struct intel_crtc *intel_crtc = to_intel_crtc(crtc);
enum pipe pipe = intel_crtc->pipe;
enum transcoder cpu_transcoder = intel_crtc->config.cpu_transcoder;
uint32_t val;
val = 0;
if (IS_HASWELL(dev) && intel_crtc->config.dither)
val |= (PIPECONF_DITHER_EN | PIPECONF_DITHER_TYPE_SP);
if (intel_crtc->config.adjusted_mode.flags & DRM_MODE_FLAG_INTERLACE)
val |= PIPECONF_INTERLACED_ILK;
else
val |= PIPECONF_PROGRESSIVE;
I915_WRITE(PIPECONF(cpu_transcoder), val);
POSTING_READ(PIPECONF(cpu_transcoder));
I915_WRITE(GAMMA_MODE(intel_crtc->pipe), GAMMA_MODE_MODE_8BIT);
POSTING_READ(GAMMA_MODE(intel_crtc->pipe));
if (IS_BROADWELL(dev)) {
val = 0;
switch (intel_crtc->config.pipe_bpp) {
case 18:
val |= PIPEMISC_DITHER_6_BPC;
break;
case 24:
val |= PIPEMISC_DITHER_8_BPC;
break;
case 30:
val |= PIPEMISC_DITHER_10_BPC;
break;
case 36:
val |= PIPEMISC_DITHER_12_BPC;
break;
default:
BUG();
}
if (intel_crtc->config.dither)
val |= PIPEMISC_DITHER_ENABLE | PIPEMISC_DITHER_TYPE_SP;
I915_WRITE(PIPEMISC(pipe), val);
}
}
static bool ironlake_compute_clocks(struct drm_crtc *crtc,
intel_clock_t *clock,
bool *has_reduced_clock,
intel_clock_t *reduced_clock)
{
struct drm_device *dev = crtc->dev;
struct drm_i915_private *dev_priv = dev->dev_private;
struct intel_encoder *intel_encoder;
int refclk;
const intel_limit_t *limit;
bool ret, is_lvds = false;
for_each_encoder_on_crtc(dev, crtc, intel_encoder) {
switch (intel_encoder->type) {
case INTEL_OUTPUT_LVDS:
is_lvds = true;
break;
}
}
refclk = ironlake_get_refclk(crtc);
limit = intel_limit(crtc, refclk);
ret = dev_priv->display.find_dpll(limit, crtc,
to_intel_crtc(crtc)->config.port_clock,
refclk, NULL, clock);
if (!ret)
return false;
if (is_lvds && dev_priv->lvds_downclock_avail) {
*has_reduced_clock =
dev_priv->display.find_dpll(limit, crtc,
dev_priv->lvds_downclock,
refclk, clock,
reduced_clock);
}
return true;
}
int ironlake_get_lanes_required(int target_clock, int link_bw, int bpp)
{
u32 bps = target_clock * bpp * 21 / 20;
return DIV_ROUND_UP(bps, link_bw * 8);
}
static bool ironlake_needs_fb_cb_tune(struct dpll *dpll, int factor)
{
return i9xx_dpll_compute_m(dpll) < factor * dpll->n;
}
static uint32_t ironlake_compute_dpll(struct intel_crtc *intel_crtc,
u32 *fp,
intel_clock_t *reduced_clock, u32 *fp2)
{
struct drm_crtc *crtc = &intel_crtc->base;
struct drm_device *dev = crtc->dev;
struct drm_i915_private *dev_priv = dev->dev_private;
struct intel_encoder *intel_encoder;
uint32_t dpll;
int factor, num_connectors = 0;
bool is_lvds = false, is_sdvo = false;
for_each_encoder_on_crtc(dev, crtc, intel_encoder) {
switch (intel_encoder->type) {
case INTEL_OUTPUT_LVDS:
is_lvds = true;
break;
case INTEL_OUTPUT_SDVO:
case INTEL_OUTPUT_HDMI:
is_sdvo = true;
break;
}
num_connectors++;
}
factor = 21;
if (is_lvds) {
if ((intel_panel_use_ssc(dev_priv) &&
dev_priv->vbt.lvds_ssc_freq == 100000) ||
(HAS_PCH_IBX(dev) && intel_is_dual_link_lvds(dev)))
factor = 25;
} else if (intel_crtc->config.sdvo_tv_clock)
factor = 20;
if (ironlake_needs_fb_cb_tune(&intel_crtc->config.dpll, factor))
*fp |= FP_CB_TUNE;
if (fp2 && (reduced_clock->m < factor * reduced_clock->n))
*fp2 |= FP_CB_TUNE;
dpll = 0;
if (is_lvds)
dpll |= DPLLB_MODE_LVDS;
else
dpll |= DPLLB_MODE_DAC_SERIAL;
dpll |= (intel_crtc->config.pixel_multiplier - 1)
<< PLL_REF_SDVO_HDMI_MULTIPLIER_SHIFT;
if (is_sdvo)
dpll |= DPLL_SDVO_HIGH_SPEED;
if (intel_crtc->config.has_dp_encoder)
dpll |= DPLL_SDVO_HIGH_SPEED;
dpll |= (1 << (intel_crtc->config.dpll.p1 - 1)) << DPLL_FPA01_P1_POST_DIV_SHIFT;
dpll |= (1 << (intel_crtc->config.dpll.p1 - 1)) << DPLL_FPA1_P1_POST_DIV_SHIFT;
switch (intel_crtc->config.dpll.p2) {
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
if (is_lvds && intel_panel_use_ssc(dev_priv) && num_connectors < 2)
dpll |= PLLB_REF_INPUT_SPREADSPECTRUMIN;
else
dpll |= PLL_REF_INPUT_DREFCLK;
return dpll | DPLL_VCO_ENABLE;
}
static int ironlake_crtc_mode_set(struct drm_crtc *crtc,
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
bool is_lvds = false;
struct intel_encoder *encoder;
struct intel_shared_dpll *pll;
int ret;
for_each_encoder_on_crtc(dev, crtc, encoder) {
switch (encoder->type) {
case INTEL_OUTPUT_LVDS:
is_lvds = true;
break;
}
num_connectors++;
}
WARN(!(HAS_PCH_IBX(dev) || HAS_PCH_CPT(dev)),
"Unexpected PCH type %d\n", INTEL_PCH_TYPE(dev));
ok = ironlake_compute_clocks(crtc, &clock,
&has_reduced_clock, &reduced_clock);
if (!ok && !intel_crtc->config.clock_set) {
DRM_ERROR("Couldn't find PLL settings for mode!\n");
return -EINVAL;
}
if (!intel_crtc->config.clock_set) {
intel_crtc->config.dpll.n = clock.n;
intel_crtc->config.dpll.m1 = clock.m1;
intel_crtc->config.dpll.m2 = clock.m2;
intel_crtc->config.dpll.p1 = clock.p1;
intel_crtc->config.dpll.p2 = clock.p2;
}
if (intel_crtc->config.has_pch_encoder) {
fp = i9xx_dpll_compute_fp(&intel_crtc->config.dpll);
if (has_reduced_clock)
fp2 = i9xx_dpll_compute_fp(&reduced_clock);
dpll = ironlake_compute_dpll(intel_crtc,
&fp, &reduced_clock,
has_reduced_clock ? &fp2 : NULL);
intel_crtc->config.dpll_hw_state.dpll = dpll;
intel_crtc->config.dpll_hw_state.fp0 = fp;
if (has_reduced_clock)
intel_crtc->config.dpll_hw_state.fp1 = fp2;
else
intel_crtc->config.dpll_hw_state.fp1 = fp;
pll = intel_get_shared_dpll(intel_crtc);
if (pll == NULL) {
DRM_DEBUG_DRIVER("failed to find PLL for pipe %c\n",
pipe_name(pipe));
return -EINVAL;
}
} else
intel_put_shared_dpll(intel_crtc);
if (intel_crtc->config.has_dp_encoder)
intel_dp_set_m_n(intel_crtc);
if (is_lvds && has_reduced_clock && i915.powersave)
intel_crtc->lowfreq_avail = true;
else
intel_crtc->lowfreq_avail = false;
intel_set_pipe_timings(intel_crtc);
if (intel_crtc->config.has_pch_encoder) {
intel_cpu_transcoder_set_m_n(intel_crtc,
&intel_crtc->config.fdi_m_n);
}
ironlake_set_pipeconf(crtc);
I915_WRITE(DSPCNTR(plane), DISPPLANE_GAMMA_ENABLE);
POSTING_READ(DSPCNTR(plane));
ret = intel_pipe_set_base(crtc, x, y, fb);
return ret;
}
static void intel_pch_transcoder_get_m_n(struct intel_crtc *crtc,
struct intel_link_m_n *m_n)
{
struct drm_device *dev = crtc->base.dev;
struct drm_i915_private *dev_priv = dev->dev_private;
enum pipe pipe = crtc->pipe;
m_n->link_m = I915_READ(PCH_TRANS_LINK_M1(pipe));
m_n->link_n = I915_READ(PCH_TRANS_LINK_N1(pipe));
m_n->gmch_m = I915_READ(PCH_TRANS_DATA_M1(pipe))
& ~TU_SIZE_MASK;
m_n->gmch_n = I915_READ(PCH_TRANS_DATA_N1(pipe));
m_n->tu = ((I915_READ(PCH_TRANS_DATA_M1(pipe))
& TU_SIZE_MASK) >> TU_SIZE_SHIFT) + 1;
}
static void intel_cpu_transcoder_get_m_n(struct intel_crtc *crtc,
enum transcoder transcoder,
struct intel_link_m_n *m_n)
{
struct drm_device *dev = crtc->base.dev;
struct drm_i915_private *dev_priv = dev->dev_private;
enum pipe pipe = crtc->pipe;
if (INTEL_INFO(dev)->gen >= 5) {
m_n->link_m = I915_READ(PIPE_LINK_M1(transcoder));
m_n->link_n = I915_READ(PIPE_LINK_N1(transcoder));
m_n->gmch_m = I915_READ(PIPE_DATA_M1(transcoder))
& ~TU_SIZE_MASK;
m_n->gmch_n = I915_READ(PIPE_DATA_N1(transcoder));
m_n->tu = ((I915_READ(PIPE_DATA_M1(transcoder))
& TU_SIZE_MASK) >> TU_SIZE_SHIFT) + 1;
} else {
m_n->link_m = I915_READ(PIPE_LINK_M_G4X(pipe));
m_n->link_n = I915_READ(PIPE_LINK_N_G4X(pipe));
m_n->gmch_m = I915_READ(PIPE_DATA_M_G4X(pipe))
& ~TU_SIZE_MASK;
m_n->gmch_n = I915_READ(PIPE_DATA_N_G4X(pipe));
m_n->tu = ((I915_READ(PIPE_DATA_M_G4X(pipe))
& TU_SIZE_MASK) >> TU_SIZE_SHIFT) + 1;
}
}
void intel_dp_get_m_n(struct intel_crtc *crtc,
struct intel_crtc_config *pipe_config)
{
if (crtc->config.has_pch_encoder)
intel_pch_transcoder_get_m_n(crtc, &pipe_config->dp_m_n);
else
intel_cpu_transcoder_get_m_n(crtc, pipe_config->cpu_transcoder,
&pipe_config->dp_m_n);
}
static void ironlake_get_fdi_m_n_config(struct intel_crtc *crtc,
struct intel_crtc_config *pipe_config)
{
intel_cpu_transcoder_get_m_n(crtc, pipe_config->cpu_transcoder,
&pipe_config->fdi_m_n);
}
static void ironlake_get_pfit_config(struct intel_crtc *crtc,
struct intel_crtc_config *pipe_config)
{
struct drm_device *dev = crtc->base.dev;
struct drm_i915_private *dev_priv = dev->dev_private;
uint32_t tmp;
tmp = I915_READ(PF_CTL(crtc->pipe));
if (tmp & PF_ENABLE) {
pipe_config->pch_pfit.enabled = true;
pipe_config->pch_pfit.pos = I915_READ(PF_WIN_POS(crtc->pipe));
pipe_config->pch_pfit.size = I915_READ(PF_WIN_SZ(crtc->pipe));
if (IS_GEN7(dev)) {
WARN_ON((tmp & PF_PIPE_SEL_MASK_IVB) !=
PF_PIPE_SEL_IVB(crtc->pipe));
}
}
}
static void ironlake_get_plane_config(struct intel_crtc *crtc,
struct intel_plane_config *plane_config)
{
struct drm_device *dev = crtc->base.dev;
struct drm_i915_private *dev_priv = dev->dev_private;
u32 val, base, offset;
int pipe = crtc->pipe, plane = crtc->plane;
int fourcc, pixel_format;
int aligned_height;
crtc->base.primary->fb = kzalloc(sizeof(struct intel_framebuffer), GFP_KERNEL);
if (!crtc->base.primary->fb) {
DRM_DEBUG_KMS("failed to alloc fb\n");
return;
}
val = I915_READ(DSPCNTR(plane));
if (INTEL_INFO(dev)->gen >= 4)
if (val & DISPPLANE_TILED)
plane_config->tiled = true;
pixel_format = val & DISPPLANE_PIXFORMAT_MASK;
fourcc = intel_format_to_fourcc(pixel_format);
crtc->base.primary->fb->pixel_format = fourcc;
crtc->base.primary->fb->bits_per_pixel =
drm_format_plane_cpp(fourcc, 0) * 8;
base = I915_READ(DSPSURF(plane)) & 0xfffff000;
if (IS_HASWELL(dev) || IS_BROADWELL(dev)) {
offset = I915_READ(DSPOFFSET(plane));
} else {
if (plane_config->tiled)
offset = I915_READ(DSPTILEOFF(plane));
else
offset = I915_READ(DSPLINOFF(plane));
}
plane_config->base = base;
val = I915_READ(PIPESRC(pipe));
crtc->base.primary->fb->width = ((val >> 16) & 0xfff) + 1;
crtc->base.primary->fb->height = ((val >> 0) & 0xfff) + 1;
val = I915_READ(DSPSTRIDE(pipe));
crtc->base.primary->fb->pitches[0] = val & 0xffffff80;
aligned_height = intel_align_height(dev, crtc->base.primary->fb->height,
plane_config->tiled);
plane_config->size = ALIGN(crtc->base.primary->fb->pitches[0] *
aligned_height, PAGE_SIZE);
DRM_DEBUG_KMS("pipe/plane %d/%d with fb: size=%dx%d@%d, offset=%x, pitch %d, size 0x%x\n",
pipe, plane, crtc->base.primary->fb->width,
crtc->base.primary->fb->height,
crtc->base.primary->fb->bits_per_pixel, base,
crtc->base.primary->fb->pitches[0],
plane_config->size);
}
static bool ironlake_get_pipe_config(struct intel_crtc *crtc,
struct intel_crtc_config *pipe_config)
{
struct drm_device *dev = crtc->base.dev;
struct drm_i915_private *dev_priv = dev->dev_private;
uint32_t tmp;
pipe_config->cpu_transcoder = (enum transcoder) crtc->pipe;
pipe_config->shared_dpll = DPLL_ID_PRIVATE;
tmp = I915_READ(PIPECONF(crtc->pipe));
if (!(tmp & PIPECONF_ENABLE))
return false;
switch (tmp & PIPECONF_BPC_MASK) {
case PIPECONF_6BPC:
pipe_config->pipe_bpp = 18;
break;
case PIPECONF_8BPC:
pipe_config->pipe_bpp = 24;
break;
case PIPECONF_10BPC:
pipe_config->pipe_bpp = 30;
break;
case PIPECONF_12BPC:
pipe_config->pipe_bpp = 36;
break;
default:
break;
}
if (I915_READ(PCH_TRANSCONF(crtc->pipe)) & TRANS_ENABLE) {
struct intel_shared_dpll *pll;
pipe_config->has_pch_encoder = true;
tmp = I915_READ(FDI_RX_CTL(crtc->pipe));
pipe_config->fdi_lanes = ((FDI_DP_PORT_WIDTH_MASK & tmp) >>
FDI_DP_PORT_WIDTH_SHIFT) + 1;
ironlake_get_fdi_m_n_config(crtc, pipe_config);
if (HAS_PCH_IBX(dev_priv->dev)) {
pipe_config->shared_dpll =
(enum intel_dpll_id) crtc->pipe;
} else {
tmp = I915_READ(PCH_DPLL_SEL);
if (tmp & TRANS_DPLLB_SEL(crtc->pipe))
pipe_config->shared_dpll = DPLL_ID_PCH_PLL_B;
else
pipe_config->shared_dpll = DPLL_ID_PCH_PLL_A;
}
pll = &dev_priv->shared_dplls[pipe_config->shared_dpll];
WARN_ON(!pll->get_hw_state(dev_priv, pll,
&pipe_config->dpll_hw_state));
tmp = pipe_config->dpll_hw_state.dpll;
pipe_config->pixel_multiplier =
((tmp & PLL_REF_SDVO_HDMI_MULTIPLIER_MASK)
>> PLL_REF_SDVO_HDMI_MULTIPLIER_SHIFT) + 1;
ironlake_pch_clock_get(crtc, pipe_config);
} else {
pipe_config->pixel_multiplier = 1;
}
intel_get_pipe_timings(crtc, pipe_config);
ironlake_get_pfit_config(crtc, pipe_config);
return true;
}
static void assert_can_disable_lcpll(struct drm_i915_private *dev_priv)
{
struct drm_device *dev = dev_priv->dev;
struct intel_ddi_plls *plls = &dev_priv->ddi_plls;
struct intel_crtc *crtc;
unsigned long irqflags;
uint32_t val;
list_for_each_entry(crtc, &dev->mode_config.crtc_list, base.head)
WARN(crtc->active, "CRTC for pipe %c enabled\n",
pipe_name(crtc->pipe));
WARN(I915_READ(HSW_PWR_WELL_DRIVER), "Power well on\n");
WARN(plls->spll_refcount, "SPLL enabled\n");
WARN(plls->wrpll1_refcount, "WRPLL1 enabled\n");
WARN(plls->wrpll2_refcount, "WRPLL2 enabled\n");
WARN(I915_READ(PCH_PP_STATUS) & PP_ON, "Panel power on\n");
WARN(I915_READ(BLC_PWM_CPU_CTL2) & BLM_PWM_ENABLE,
"CPU PWM1 enabled\n");
WARN(I915_READ(HSW_BLC_PWM2_CTL) & BLM_PWM_ENABLE,
"CPU PWM2 enabled\n");
WARN(I915_READ(BLC_PWM_PCH_CTL1) & BLM_PCH_PWM_ENABLE,
"PCH PWM1 enabled\n");
WARN(I915_READ(UTIL_PIN_CTL) & UTIL_PIN_ENABLE,
"Utility pin enabled\n");
WARN(I915_READ(PCH_GTC_CTL) & PCH_GTC_ENABLE, "PCH GTC enabled\n");
spin_lock_irqsave(&dev_priv->irq_lock, irqflags);
val = I915_READ(DEIMR);
WARN((val | DE_PCH_EVENT_IVB) != 0xffffffff,
"Unexpected DEIMR bits enabled: 0x%x\n", val);
val = I915_READ(SDEIMR);
WARN((val | SDE_HOTPLUG_MASK_CPT) != 0xffffffff,
"Unexpected SDEIMR bits enabled: 0x%x\n", val);
spin_unlock_irqrestore(&dev_priv->irq_lock, irqflags);
}
static void hsw_disable_lcpll(struct drm_i915_private *dev_priv,
bool switch_to_fclk, bool allow_power_down)
{
uint32_t val;
assert_can_disable_lcpll(dev_priv);
val = I915_READ(LCPLL_CTL);
if (switch_to_fclk) {
val |= LCPLL_CD_SOURCE_FCLK;
I915_WRITE(LCPLL_CTL, val);
if (wait_for_atomic_us(I915_READ(LCPLL_CTL) &
LCPLL_CD_SOURCE_FCLK_DONE, 1))
DRM_ERROR("Switching to FCLK failed\n");
val = I915_READ(LCPLL_CTL);
}
val |= LCPLL_PLL_DISABLE;
I915_WRITE(LCPLL_CTL, val);
POSTING_READ(LCPLL_CTL);
if (wait_for((I915_READ(LCPLL_CTL) & LCPLL_PLL_LOCK) == 0, 1))
DRM_ERROR("LCPLL still locked\n");
val = I915_READ(D_COMP);
val |= D_COMP_COMP_DISABLE;
mutex_lock(&dev_priv->rps.hw_lock);
if (sandybridge_pcode_write(dev_priv, GEN6_PCODE_WRITE_D_COMP, val))
DRM_ERROR("Failed to disable D_COMP\n");
mutex_unlock(&dev_priv->rps.hw_lock);
POSTING_READ(D_COMP);
ndelay(100);
if (wait_for((I915_READ(D_COMP) & D_COMP_RCOMP_IN_PROGRESS) == 0, 1))
DRM_ERROR("D_COMP RCOMP still in progress\n");
if (allow_power_down) {
val = I915_READ(LCPLL_CTL);
val |= LCPLL_POWER_DOWN_ALLOW;
I915_WRITE(LCPLL_CTL, val);
POSTING_READ(LCPLL_CTL);
}
}
static void hsw_restore_lcpll(struct drm_i915_private *dev_priv)
{
uint32_t val;
unsigned long irqflags;
val = I915_READ(LCPLL_CTL);
if ((val & (LCPLL_PLL_LOCK | LCPLL_PLL_DISABLE | LCPLL_CD_SOURCE_FCLK |
LCPLL_POWER_DOWN_ALLOW)) == LCPLL_PLL_LOCK)
return;
spin_lock_irqsave(&dev_priv->uncore.lock, irqflags);
if (dev_priv->uncore.forcewake_count++ == 0)
dev_priv->uncore.funcs.force_wake_get(dev_priv, FORCEWAKE_ALL);
spin_unlock_irqrestore(&dev_priv->uncore.lock, irqflags);
if (val & LCPLL_POWER_DOWN_ALLOW) {
val &= ~LCPLL_POWER_DOWN_ALLOW;
I915_WRITE(LCPLL_CTL, val);
POSTING_READ(LCPLL_CTL);
}
val = I915_READ(D_COMP);
val |= D_COMP_COMP_FORCE;
val &= ~D_COMP_COMP_DISABLE;
mutex_lock(&dev_priv->rps.hw_lock);
if (sandybridge_pcode_write(dev_priv, GEN6_PCODE_WRITE_D_COMP, val))
DRM_ERROR("Failed to enable D_COMP\n");
mutex_unlock(&dev_priv->rps.hw_lock);
POSTING_READ(D_COMP);
val = I915_READ(LCPLL_CTL);
val &= ~LCPLL_PLL_DISABLE;
I915_WRITE(LCPLL_CTL, val);
if (wait_for(I915_READ(LCPLL_CTL) & LCPLL_PLL_LOCK, 5))
DRM_ERROR("LCPLL not locked yet\n");
if (val & LCPLL_CD_SOURCE_FCLK) {
val = I915_READ(LCPLL_CTL);
val &= ~LCPLL_CD_SOURCE_FCLK;
I915_WRITE(LCPLL_CTL, val);
if (wait_for_atomic_us((I915_READ(LCPLL_CTL) &
LCPLL_CD_SOURCE_FCLK_DONE) == 0, 1))
DRM_ERROR("Switching back to LCPLL failed\n");
}
spin_lock_irqsave(&dev_priv->uncore.lock, irqflags);
if (--dev_priv->uncore.forcewake_count == 0)
dev_priv->uncore.funcs.force_wake_put(dev_priv, FORCEWAKE_ALL);
spin_unlock_irqrestore(&dev_priv->uncore.lock, irqflags);
}
void hsw_enable_pc8(struct drm_i915_private *dev_priv)
{
struct drm_device *dev = dev_priv->dev;
uint32_t val;
WARN_ON(!HAS_PC8(dev));
DRM_DEBUG_KMS("Enabling package C8+\n");
if (dev_priv->pch_id == INTEL_PCH_LPT_LP_DEVICE_ID_TYPE) {
val = I915_READ(SOUTH_DSPCLK_GATE_D);
val &= ~PCH_LP_PARTITION_LEVEL_DISABLE;
I915_WRITE(SOUTH_DSPCLK_GATE_D, val);
}
lpt_disable_clkout_dp(dev);
hsw_runtime_pm_disable_interrupts(dev);
hsw_disable_lcpll(dev_priv, true, true);
}
void hsw_disable_pc8(struct drm_i915_private *dev_priv)
{
struct drm_device *dev = dev_priv->dev;
uint32_t val;
WARN_ON(!HAS_PC8(dev));
DRM_DEBUG_KMS("Disabling package C8+\n");
hsw_restore_lcpll(dev_priv);
hsw_runtime_pm_restore_interrupts(dev);
lpt_init_pch_refclk(dev);
if (dev_priv->pch_id == INTEL_PCH_LPT_LP_DEVICE_ID_TYPE) {
val = I915_READ(SOUTH_DSPCLK_GATE_D);
val |= PCH_LP_PARTITION_LEVEL_DISABLE;
I915_WRITE(SOUTH_DSPCLK_GATE_D, val);
}
intel_prepare_ddi(dev);
i915_gem_init_swizzling(dev);
mutex_lock(&dev_priv->rps.hw_lock);
gen6_update_ring_freq(dev);
mutex_unlock(&dev_priv->rps.hw_lock);
}
static void haswell_modeset_global_resources(struct drm_device *dev)
{
modeset_update_crtc_power_domains(dev);
}
static int haswell_crtc_mode_set(struct drm_crtc *crtc,
int x, int y,
struct drm_framebuffer *fb)
{
struct drm_device *dev = crtc->dev;
struct drm_i915_private *dev_priv = dev->dev_private;
struct intel_crtc *intel_crtc = to_intel_crtc(crtc);
int plane = intel_crtc->plane;
int ret;
if (!intel_ddi_pll_select(intel_crtc))
return -EINVAL;
intel_ddi_pll_enable(intel_crtc);
if (intel_crtc->config.has_dp_encoder)
intel_dp_set_m_n(intel_crtc);
intel_crtc->lowfreq_avail = false;
intel_set_pipe_timings(intel_crtc);
if (intel_crtc->config.has_pch_encoder) {
intel_cpu_transcoder_set_m_n(intel_crtc,
&intel_crtc->config.fdi_m_n);
}
haswell_set_pipeconf(crtc);
intel_set_pipe_csc(crtc);
I915_WRITE(DSPCNTR(plane), DISPPLANE_GAMMA_ENABLE | DISPPLANE_PIPE_CSC_ENABLE);
POSTING_READ(DSPCNTR(plane));
ret = intel_pipe_set_base(crtc, x, y, fb);
return ret;
}
static bool haswell_get_pipe_config(struct intel_crtc *crtc,
struct intel_crtc_config *pipe_config)
{
struct drm_device *dev = crtc->base.dev;
struct drm_i915_private *dev_priv = dev->dev_private;
enum intel_display_power_domain pfit_domain;
uint32_t tmp;
if (!intel_display_power_enabled(dev_priv,
POWER_DOMAIN_PIPE(crtc->pipe)))
return false;
pipe_config->cpu_transcoder = (enum transcoder) crtc->pipe;
pipe_config->shared_dpll = DPLL_ID_PRIVATE;
tmp = I915_READ(TRANS_DDI_FUNC_CTL(TRANSCODER_EDP));
if (tmp & TRANS_DDI_FUNC_ENABLE) {
enum pipe trans_edp_pipe;
switch (tmp & TRANS_DDI_EDP_INPUT_MASK) {
default:
WARN(1, "unknown pipe linked to edp transcoder\n");
case TRANS_DDI_EDP_INPUT_A_ONOFF:
case TRANS_DDI_EDP_INPUT_A_ON:
trans_edp_pipe = PIPE_A;
break;
case TRANS_DDI_EDP_INPUT_B_ONOFF:
trans_edp_pipe = PIPE_B;
break;
case TRANS_DDI_EDP_INPUT_C_ONOFF:
trans_edp_pipe = PIPE_C;
break;
}
if (trans_edp_pipe == crtc->pipe)
pipe_config->cpu_transcoder = TRANSCODER_EDP;
}
if (!intel_display_power_enabled(dev_priv,
POWER_DOMAIN_TRANSCODER(pipe_config->cpu_transcoder)))
return false;
tmp = I915_READ(PIPECONF(pipe_config->cpu_transcoder));
if (!(tmp & PIPECONF_ENABLE))
return false;
tmp = I915_READ(TRANS_DDI_FUNC_CTL(pipe_config->cpu_transcoder));
if ((tmp & TRANS_DDI_PORT_MASK) == TRANS_DDI_SELECT_PORT(PORT_E) &&
I915_READ(LPT_TRANSCONF) & TRANS_ENABLE) {
pipe_config->has_pch_encoder = true;
tmp = I915_READ(FDI_RX_CTL(PIPE_A));
pipe_config->fdi_lanes = ((FDI_DP_PORT_WIDTH_MASK & tmp) >>
FDI_DP_PORT_WIDTH_SHIFT) + 1;
ironlake_get_fdi_m_n_config(crtc, pipe_config);
}
intel_get_pipe_timings(crtc, pipe_config);
pfit_domain = POWER_DOMAIN_PIPE_PANEL_FITTER(crtc->pipe);
if (intel_display_power_enabled(dev_priv, pfit_domain))
ironlake_get_pfit_config(crtc, pipe_config);
if (IS_HASWELL(dev))
pipe_config->ips_enabled = hsw_crtc_supports_ips(crtc) &&
(I915_READ(IPS_CTL) & IPS_ENABLE);
pipe_config->pixel_multiplier = 1;
return true;
}
static int intel_crtc_mode_set(struct drm_crtc *crtc,
int x, int y,
struct drm_framebuffer *fb)
{
struct drm_device *dev = crtc->dev;
struct drm_i915_private *dev_priv = dev->dev_private;
struct intel_encoder *encoder;
struct intel_crtc *intel_crtc = to_intel_crtc(crtc);
struct drm_display_mode *mode = &intel_crtc->config.requested_mode;
int pipe = intel_crtc->pipe;
int ret;
drm_vblank_pre_modeset(dev, pipe);
ret = dev_priv->display.crtc_mode_set(crtc, x, y, fb);
drm_vblank_post_modeset(dev, pipe);
if (ret != 0)
return ret;
for_each_encoder_on_crtc(dev, crtc, encoder) {
DRM_DEBUG_KMS("[ENCODER:%d:%s] set [MODE:%d:%s]\n",
encoder->base.base.id,
drm_get_encoder_name(&encoder->base),
mode->base.id, mode->name);
encoder->mode_set(encoder);
}
return 0;
}
static u32 audio_config_hdmi_pixel_clock(struct drm_display_mode *mode)
{
int i;
for (i = 0; i < ARRAY_SIZE(hdmi_audio_clock); i++) {
if (mode->clock == hdmi_audio_clock[i].clock)
break;
}
if (i == ARRAY_SIZE(hdmi_audio_clock)) {
DRM_DEBUG_KMS("HDMI audio pixel clock setting for %d not found, falling back to defaults\n", mode->clock);
i = 1;
}
DRM_DEBUG_KMS("Configuring HDMI audio for pixel clock %d (0x%08x)\n",
hdmi_audio_clock[i].clock,
hdmi_audio_clock[i].config);
return hdmi_audio_clock[i].config;
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
struct drm_crtc *crtc,
struct drm_display_mode *mode)
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
struct drm_crtc *crtc,
struct drm_display_mode *mode)
{
struct drm_i915_private *dev_priv = connector->dev->dev_private;
uint8_t *eld = connector->eld;
struct drm_device *dev = crtc->dev;
struct intel_crtc *intel_crtc = to_intel_crtc(crtc);
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
DRM_DEBUG_DRIVER("HDMI audio: pin eld vld status=0x%08x\n", tmp);
tmp |= (AUDIO_ELD_VALID_A << (pipe * 4));
I915_WRITE(aud_cntrl_st2, tmp);
tmp = I915_READ(aud_cntrl_st2);
DRM_DEBUG_DRIVER("HDMI audio: eld vld status=0x%08x\n", tmp);
tmp = I915_READ(aud_config);
DRM_DEBUG_DRIVER("HDMI audio: audio conf: 0x%08x\n", tmp);
tmp &= ~(AUD_CONFIG_N_VALUE_INDEX | AUD_CONFIG_N_PROG_ENABLE);
I915_WRITE(aud_config, tmp);
DRM_DEBUG_DRIVER("ELD on pipe %c\n", pipe_name(pipe));
eldv = AUDIO_ELD_VALID_A << (pipe * 4);
intel_crtc->eld_vld = true;
if (intel_pipe_has_type(crtc, INTEL_OUTPUT_DISPLAYPORT)) {
DRM_DEBUG_DRIVER("ELD: DisplayPort detected\n");
eld[5] |= (1 << 2);
I915_WRITE(aud_config, AUD_CONFIG_N_VALUE_INDEX);
} else {
I915_WRITE(aud_config, audio_config_hdmi_pixel_clock(mode));
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
struct drm_crtc *crtc,
struct drm_display_mode *mode)
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
} else if (IS_VALLEYVIEW(connector->dev)) {
hdmiw_hdmiedid = VLV_HDMIW_HDMIEDID(pipe);
aud_config = VLV_AUD_CFG(pipe);
aud_cntl_st = VLV_AUD_CNTL_ST(pipe);
aud_cntrl_st2 = VLV_AUD_CNTL_ST2;
} else {
hdmiw_hdmiedid = CPT_HDMIW_HDMIEDID(pipe);
aud_config = CPT_AUD_CFG(pipe);
aud_cntl_st = CPT_AUD_CNTL_ST(pipe);
aud_cntrl_st2 = CPT_AUD_CNTRL_ST2;
}
DRM_DEBUG_DRIVER("ELD on pipe %c\n", pipe_name(pipe));
if (IS_VALLEYVIEW(connector->dev)) {
struct intel_encoder *intel_encoder;
struct intel_digital_port *intel_dig_port;
intel_encoder = intel_attached_encoder(connector);
intel_dig_port = enc_to_dig_port(&intel_encoder->base);
i = intel_dig_port->port;
} else {
i = I915_READ(aud_cntl_st);
i = (i >> 29) & DIP_PORT_SEL_MASK;
}
if (!i) {
DRM_DEBUG_DRIVER("Audio directed to unknown port\n");
eldv = IBX_ELD_VALIDB;
eldv |= IBX_ELD_VALIDB << 4;
eldv |= IBX_ELD_VALIDB << 8;
} else {
DRM_DEBUG_DRIVER("ELD on port %c\n", port_name(i));
eldv = IBX_ELD_VALIDB << ((i - 1) * 4);
}
if (intel_pipe_has_type(crtc, INTEL_OUTPUT_DISPLAYPORT)) {
DRM_DEBUG_DRIVER("ELD: DisplayPort detected\n");
eld[5] |= (1 << 2);
I915_WRITE(aud_config, AUD_CONFIG_N_VALUE_INDEX);
} else {
I915_WRITE(aud_config, audio_config_hdmi_pixel_clock(mode));
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
dev_priv->display.write_eld(connector, crtc, mode);
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
int16_t width = intel_crtc->cursor_width;
uint32_t cntl = I915_READ(CURCNTR(pipe));
if (base) {
cntl &= ~(CURSOR_MODE | MCURSOR_PIPE_SELECT);
cntl |= MCURSOR_GAMMA_ENABLE;
switch (width) {
case 64:
cntl |= CURSOR_MODE_64_ARGB_AX;
break;
case 128:
cntl |= CURSOR_MODE_128_ARGB_AX;
break;
case 256:
cntl |= CURSOR_MODE_256_ARGB_AX;
break;
default:
WARN_ON(1);
return;
}
cntl |= pipe << 28;
} else {
cntl &= ~(CURSOR_MODE | MCURSOR_GAMMA_ENABLE);
cntl |= CURSOR_MODE_DISABLE;
}
I915_WRITE(CURCNTR(pipe), cntl);
intel_crtc->cursor_visible = visible;
}
POSTING_READ(CURCNTR(pipe));
I915_WRITE(CURBASE(pipe), base);
POSTING_READ(CURBASE(pipe));
}
static void ivb_update_cursor(struct drm_crtc *crtc, u32 base)
{
struct drm_device *dev = crtc->dev;
struct drm_i915_private *dev_priv = dev->dev_private;
struct intel_crtc *intel_crtc = to_intel_crtc(crtc);
int pipe = intel_crtc->pipe;
bool visible = base != 0;
if (intel_crtc->cursor_visible != visible) {
int16_t width = intel_crtc->cursor_width;
uint32_t cntl = I915_READ(CURCNTR_IVB(pipe));
if (base) {
cntl &= ~CURSOR_MODE;
cntl |= MCURSOR_GAMMA_ENABLE;
switch (width) {
case 64:
cntl |= CURSOR_MODE_64_ARGB_AX;
break;
case 128:
cntl |= CURSOR_MODE_128_ARGB_AX;
break;
case 256:
cntl |= CURSOR_MODE_256_ARGB_AX;
break;
default:
WARN_ON(1);
return;
}
} else {
cntl &= ~(CURSOR_MODE | MCURSOR_GAMMA_ENABLE);
cntl |= CURSOR_MODE_DISABLE;
}
if (IS_HASWELL(dev) || IS_BROADWELL(dev)) {
cntl |= CURSOR_PIPE_CSC_ENABLE;
cntl &= ~CURSOR_TRICKLE_FEED_DISABLE;
}
I915_WRITE(CURCNTR_IVB(pipe), cntl);
intel_crtc->cursor_visible = visible;
}
POSTING_READ(CURCNTR_IVB(pipe));
I915_WRITE(CURBASE_IVB(pipe), base);
POSTING_READ(CURBASE_IVB(pipe));
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
u32 base = 0, pos = 0;
bool visible;
if (on)
base = intel_crtc->cursor_addr;
if (x >= intel_crtc->config.pipe_src_w)
base = 0;
if (y >= intel_crtc->config.pipe_src_h)
base = 0;
if (x < 0) {
if (x + intel_crtc->cursor_width <= 0)
base = 0;
pos |= CURSOR_POS_SIGN << CURSOR_X_SHIFT;
x = -x;
}
pos |= x << CURSOR_X_SHIFT;
if (y < 0) {
if (y + intel_crtc->cursor_height <= 0)
base = 0;
pos |= CURSOR_POS_SIGN << CURSOR_Y_SHIFT;
y = -y;
}
pos |= y << CURSOR_Y_SHIFT;
visible = base != 0;
if (!visible && !intel_crtc->cursor_visible)
return;
if (IS_IVYBRIDGE(dev) || IS_HASWELL(dev) || IS_BROADWELL(dev)) {
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
unsigned old_width;
uint32_t addr;
int ret;
if (!handle) {
DRM_DEBUG_KMS("cursor off\n");
addr = 0;
obj = NULL;
mutex_lock(&dev->struct_mutex);
goto finish;
}
if (!((width == 64 && height == 64) ||
(width == 128 && height == 128 && !IS_GEN2(dev)) ||
(width == 256 && height == 256 && !IS_GEN2(dev)))) {
DRM_DEBUG("Cursor dimension not supported\n");
return -EINVAL;
}
obj = to_intel_bo(drm_gem_object_lookup(dev, file, handle));
if (&obj->base == NULL)
return -ENOENT;
if (obj->base.size < width * height * 4) {
DRM_DEBUG_KMS("buffer is to small\n");
ret = -ENOMEM;
goto fail;
}
mutex_lock(&dev->struct_mutex);
if (!INTEL_INFO(dev)->cursor_needs_physical) {
unsigned alignment;
if (obj->tiling_mode) {
DRM_DEBUG_KMS("cursor cannot be tiled\n");
ret = -EINVAL;
goto fail_locked;
}
alignment = 0;
if (need_vtd_wa(dev))
alignment = 64*1024;
ret = i915_gem_object_pin_to_display_plane(obj, alignment, NULL);
if (ret) {
DRM_DEBUG_KMS("failed to move cursor bo into the GTT\n");
goto fail_locked;
}
ret = i915_gem_object_put_fence(obj);
if (ret) {
DRM_DEBUG_KMS("failed to release fence for cursor");
goto fail_unpin;
}
addr = i915_gem_obj_ggtt_offset(obj);
} else {
int align = IS_I830(dev) ? 16 * 1024 : 256;
ret = i915_gem_object_attach_phys(obj, align);
if (ret) {
DRM_DEBUG_KMS("failed to attach phys object\n");
goto fail_locked;
}
addr = obj->phys_handle->busaddr;
}
if (IS_GEN2(dev))
I915_WRITE(CURSIZE, (height << 12) | width);
finish:
if (intel_crtc->cursor_bo) {
if (!INTEL_INFO(dev)->cursor_needs_physical)
i915_gem_object_unpin_from_display_plane(intel_crtc->cursor_bo);
drm_gem_object_unreference(&intel_crtc->cursor_bo->base);
}
mutex_unlock(&dev->struct_mutex);
old_width = intel_crtc->cursor_width;
intel_crtc->cursor_addr = addr;
intel_crtc->cursor_bo = obj;
intel_crtc->cursor_width = width;
intel_crtc->cursor_height = height;
if (intel_crtc->active) {
if (old_width != width)
intel_update_watermarks(crtc);
intel_crtc_update_cursor(crtc, intel_crtc->cursor_bo != NULL);
}
return 0;
fail_unpin:
i915_gem_object_unpin_from_display_plane(obj);
fail_locked:
mutex_unlock(&dev->struct_mutex);
fail:
drm_gem_object_unreference_unlocked(&obj->base);
return ret;
}
static int intel_crtc_cursor_move(struct drm_crtc *crtc, int x, int y)
{
struct intel_crtc *intel_crtc = to_intel_crtc(crtc);
intel_crtc->cursor_x = clamp_t(int, x, SHRT_MIN, SHRT_MAX);
intel_crtc->cursor_y = clamp_t(int, y, SHRT_MIN, SHRT_MAX);
if (intel_crtc->active)
intel_crtc_update_cursor(crtc, intel_crtc->cursor_bo != NULL);
return 0;
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
struct drm_framebuffer *
__intel_framebuffer_create(struct drm_device *dev,
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
if (ret)
goto err;
return &intel_fb->base;
err:
drm_gem_object_unreference_unlocked(&obj->base);
kfree(intel_fb);
return ERR_PTR(ret);
}
static struct drm_framebuffer *
intel_framebuffer_create(struct drm_device *dev,
struct drm_mode_fb_cmd2 *mode_cmd,
struct drm_i915_gem_object *obj)
{
struct drm_framebuffer *fb;
int ret;
ret = i915_mutex_lock_interruptible(dev);
if (ret)
return ERR_PTR(ret);
fb = __intel_framebuffer_create(dev, mode_cmd, obj);
mutex_unlock(&dev->struct_mutex);
return fb;
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
#ifdef CONFIG_DRM_I915_FBDEV
struct drm_i915_private *dev_priv = dev->dev_private;
struct drm_i915_gem_object *obj;
struct drm_framebuffer *fb;
if (!dev_priv->fbdev)
return NULL;
if (!dev_priv->fbdev->fb)
return NULL;
obj = dev_priv->fbdev->fb->obj;
BUG_ON(!obj);
fb = &dev_priv->fbdev->fb->base;
if (fb->pitches[0] < intel_framebuffer_pitch_for_width(mode->hdisplay,
fb->bits_per_pixel))
return NULL;
if (obj->base.size < mode->vdisplay * fb->pitches[0])
return NULL;
return fb;
#else
return NULL;
#endif
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
mutex_lock(&crtc->mutex);
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
mutex_lock(&crtc->mutex);
intel_encoder->new_crtc = to_intel_crtc(crtc);
to_intel_connector(connector)->new_encoder = intel_encoder;
intel_crtc = to_intel_crtc(crtc);
intel_crtc->new_enabled = true;
intel_crtc->new_config = &intel_crtc->config;
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
goto fail;
}
if (intel_set_mode(crtc, mode, 0, 0, fb)) {
DRM_DEBUG_KMS("failed to set mode on load-detect pipe\n");
if (old->release_fb)
old->release_fb->funcs->destroy(old->release_fb);
goto fail;
}
intel_wait_for_vblank(dev, intel_crtc->pipe);
return true;
fail:
intel_crtc->new_enabled = crtc->enabled;
if (intel_crtc->new_enabled)
intel_crtc->new_config = &intel_crtc->config;
else
intel_crtc->new_config = NULL;
mutex_unlock(&crtc->mutex);
return false;
}
void intel_release_load_detect_pipe(struct drm_connector *connector,
struct intel_load_detect_pipe *old)
{
struct intel_encoder *intel_encoder =
intel_attached_encoder(connector);
struct drm_encoder *encoder = &intel_encoder->base;
struct drm_crtc *crtc = encoder->crtc;
struct intel_crtc *intel_crtc = to_intel_crtc(crtc);
DRM_DEBUG_KMS("[CONNECTOR:%d:%s], [ENCODER:%d:%s]\n",
connector->base.id, drm_get_connector_name(connector),
encoder->base.id, drm_get_encoder_name(encoder));
if (old->load_detect_temp) {
to_intel_connector(connector)->new_encoder = NULL;
intel_encoder->new_crtc = NULL;
intel_crtc->new_enabled = false;
intel_crtc->new_config = NULL;
intel_set_mode(crtc, NULL, 0, 0, NULL);
if (old->release_fb) {
drm_framebuffer_unregister_private(old->release_fb);
drm_framebuffer_unreference(old->release_fb);
}
mutex_unlock(&crtc->mutex);
return;
}
if (old->dpms_mode != DRM_MODE_DPMS_ON)
connector->funcs->dpms(connector, old->dpms_mode);
mutex_unlock(&crtc->mutex);
}
static int i9xx_pll_refclk(struct drm_device *dev,
const struct intel_crtc_config *pipe_config)
{
struct drm_i915_private *dev_priv = dev->dev_private;
u32 dpll = pipe_config->dpll_hw_state.dpll;
if ((dpll & PLL_REF_INPUT_MASK) == PLLB_REF_INPUT_SPREADSPECTRUMIN)
return dev_priv->vbt.lvds_ssc_freq;
else if (HAS_PCH_SPLIT(dev))
return 120000;
else if (!IS_GEN2(dev))
return 96000;
else
return 48000;
}
static void i9xx_crtc_clock_get(struct intel_crtc *crtc,
struct intel_crtc_config *pipe_config)
{
struct drm_device *dev = crtc->base.dev;
struct drm_i915_private *dev_priv = dev->dev_private;
int pipe = pipe_config->cpu_transcoder;
u32 dpll = pipe_config->dpll_hw_state.dpll;
u32 fp;
intel_clock_t clock;
int refclk = i9xx_pll_refclk(dev, pipe_config);
if ((dpll & DISPLAY_RATE_SELECT_FPA1) == 0)
fp = pipe_config->dpll_hw_state.fp0;
else
fp = pipe_config->dpll_hw_state.fp1;
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
return;
}
if (IS_PINEVIEW(dev))
pineview_clock(refclk, &clock);
else
i9xx_clock(refclk, &clock);
} else {
u32 lvds = IS_I830(dev) ? 0 : I915_READ(LVDS);
bool is_lvds = (pipe == 1) && (lvds & LVDS_PORT_EN);
if (is_lvds) {
clock.p1 = ffs((dpll & DPLL_FPA01_P1_POST_DIV_MASK_I830_LVDS) >>
DPLL_FPA01_P1_POST_DIV_SHIFT);
if (lvds & LVDS_CLKB_POWER_UP)
clock.p2 = 7;
else
clock.p2 = 14;
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
}
i9xx_clock(refclk, &clock);
}
pipe_config->port_clock = clock.dot;
}
int intel_dotclock_calculate(int link_freq,
const struct intel_link_m_n *m_n)
{
if (!m_n->link_n)
return 0;
return div_u64((u64)m_n->link_m * link_freq, m_n->link_n);
}
static void ironlake_pch_clock_get(struct intel_crtc *crtc,
struct intel_crtc_config *pipe_config)
{
struct drm_device *dev = crtc->base.dev;
i9xx_crtc_clock_get(crtc, pipe_config);
pipe_config->adjusted_mode.crtc_clock =
intel_dotclock_calculate(intel_fdi_link_freq(dev) * 10000,
&pipe_config->fdi_m_n);
}
struct drm_display_mode *intel_crtc_mode_get(struct drm_device *dev,
struct drm_crtc *crtc)
{
struct drm_i915_private *dev_priv = dev->dev_private;
struct intel_crtc *intel_crtc = to_intel_crtc(crtc);
enum transcoder cpu_transcoder = intel_crtc->config.cpu_transcoder;
struct drm_display_mode *mode;
struct intel_crtc_config pipe_config;
int htot = I915_READ(HTOTAL(cpu_transcoder));
int hsync = I915_READ(HSYNC(cpu_transcoder));
int vtot = I915_READ(VTOTAL(cpu_transcoder));
int vsync = I915_READ(VSYNC(cpu_transcoder));
enum pipe pipe = intel_crtc->pipe;
mode = kzalloc(sizeof(*mode), GFP_KERNEL);
if (!mode)
return NULL;
pipe_config.cpu_transcoder = (enum transcoder) pipe;
pipe_config.pixel_multiplier = 1;
pipe_config.dpll_hw_state.dpll = I915_READ(DPLL(pipe));
pipe_config.dpll_hw_state.fp0 = I915_READ(FP0(pipe));
pipe_config.dpll_hw_state.fp1 = I915_READ(FP1(pipe));
i9xx_crtc_clock_get(intel_crtc, &pipe_config);
mode->clock = pipe_config.port_clock / pipe_config.pixel_multiplier;
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
struct drm_i915_private *dev_priv = dev->dev_private;
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
struct drm_i915_private *dev_priv = dev->dev_private;
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
struct drm_i915_private *dev_priv = dev->dev_private;
if (dev_priv->mm.busy)
return;
intel_runtime_pm_get(dev_priv);
i915_update_gfx_val(dev_priv);
dev_priv->mm.busy = true;
}
void intel_mark_idle(struct drm_device *dev)
{
struct drm_i915_private *dev_priv = dev->dev_private;
struct drm_crtc *crtc;
if (!dev_priv->mm.busy)
return;
dev_priv->mm.busy = false;
if (!i915.powersave)
goto out;
list_for_each_entry(crtc, &dev->mode_config.crtc_list, head) {
if (!crtc->primary->fb)
continue;
intel_decrease_pllclock(crtc);
}
if (INTEL_INFO(dev)->gen >= 6)
gen6_rps_idle(dev->dev_private);
out:
intel_runtime_pm_put(dev_priv);
}
void intel_mark_fb_busy(struct drm_i915_gem_object *obj,
struct intel_ring_buffer *ring)
{
struct drm_device *dev = obj->base.dev;
struct drm_crtc *crtc;
if (!i915.powersave)
return;
list_for_each_entry(crtc, &dev->mode_config.crtc_list, head) {
if (!crtc->primary->fb)
continue;
if (to_intel_framebuffer(crtc->primary->fb)->obj != obj)
continue;
intel_increase_pllclock(crtc);
if (ring && intel_fbc_enabled(dev))
ring->fbc_dirty = true;
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
intel_crtc_cursor_set(crtc, NULL, 0, 0, 0);
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
struct drm_i915_private *dev_priv = dev->dev_private;
struct intel_crtc *intel_crtc = to_intel_crtc(crtc);
struct intel_unpin_work *work;
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
wake_up_all(&dev_priv->pending_flip_queue);
queue_work(dev_priv->wq, &work->work);
trace_i915_flip_complete(intel_crtc->plane, work->pending_flip_obj);
}
void intel_finish_page_flip(struct drm_device *dev, int pipe)
{
struct drm_i915_private *dev_priv = dev->dev_private;
struct drm_crtc *crtc = dev_priv->pipe_to_crtc_mapping[pipe];
do_intel_finish_page_flip(dev, crtc);
}
void intel_finish_page_flip_plane(struct drm_device *dev, int plane)
{
struct drm_i915_private *dev_priv = dev->dev_private;
struct drm_crtc *crtc = dev_priv->plane_to_crtc_mapping[plane];
do_intel_finish_page_flip(dev, crtc);
}
void intel_prepare_page_flip(struct drm_device *dev, int plane)
{
struct drm_i915_private *dev_priv = dev->dev_private;
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
struct drm_i915_gem_object *obj,
uint32_t flags)
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
intel_ring_emit(ring, i915_gem_obj_ggtt_offset(obj) + intel_crtc->dspaddr_offset);
intel_ring_emit(ring, 0);
intel_mark_page_flip_active(intel_crtc);
__intel_ring_advance(ring);
return 0;
err_unpin:
intel_unpin_fb_obj(obj);
err:
return ret;
}
static int intel_gen3_queue_flip(struct drm_device *dev,
struct drm_crtc *crtc,
struct drm_framebuffer *fb,
struct drm_i915_gem_object *obj,
uint32_t flags)
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
intel_ring_emit(ring, i915_gem_obj_ggtt_offset(obj) + intel_crtc->dspaddr_offset);
intel_ring_emit(ring, MI_NOOP);
intel_mark_page_flip_active(intel_crtc);
__intel_ring_advance(ring);
return 0;
err_unpin:
intel_unpin_fb_obj(obj);
err:
return ret;
}
static int intel_gen4_queue_flip(struct drm_device *dev,
struct drm_crtc *crtc,
struct drm_framebuffer *fb,
struct drm_i915_gem_object *obj,
uint32_t flags)
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
(i915_gem_obj_ggtt_offset(obj) + intel_crtc->dspaddr_offset) |
obj->tiling_mode);
pf = 0;
pipesrc = I915_READ(PIPESRC(intel_crtc->pipe)) & 0x0fff0fff;
intel_ring_emit(ring, pf | pipesrc);
intel_mark_page_flip_active(intel_crtc);
__intel_ring_advance(ring);
return 0;
err_unpin:
intel_unpin_fb_obj(obj);
err:
return ret;
}
static int intel_gen6_queue_flip(struct drm_device *dev,
struct drm_crtc *crtc,
struct drm_framebuffer *fb,
struct drm_i915_gem_object *obj,
uint32_t flags)
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
intel_ring_emit(ring, i915_gem_obj_ggtt_offset(obj) + intel_crtc->dspaddr_offset);
pf = 0;
pipesrc = I915_READ(PIPESRC(intel_crtc->pipe)) & 0x0fff0fff;
intel_ring_emit(ring, pf | pipesrc);
intel_mark_page_flip_active(intel_crtc);
__intel_ring_advance(ring);
return 0;
err_unpin:
intel_unpin_fb_obj(obj);
err:
return ret;
}
static int intel_gen7_queue_flip(struct drm_device *dev,
struct drm_crtc *crtc,
struct drm_framebuffer *fb,
struct drm_i915_gem_object *obj,
uint32_t flags)
{
struct drm_i915_private *dev_priv = dev->dev_private;
struct intel_crtc *intel_crtc = to_intel_crtc(crtc);
struct intel_ring_buffer *ring;
uint32_t plane_bit = 0;
int len, ret;
ring = obj->ring;
if (IS_VALLEYVIEW(dev) || ring == NULL || ring->id != RCS)
ring = &dev_priv->ring[BCS];
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
len = 4;
if (ring->id == RCS)
len += 6;
ret = intel_ring_cacheline_align(ring);
if (ret)
goto err_unpin;
ret = intel_ring_begin(ring, len);
if (ret)
goto err_unpin;
if (ring->id == RCS) {
intel_ring_emit(ring, MI_LOAD_REGISTER_IMM(1));
intel_ring_emit(ring, DERRMR);
intel_ring_emit(ring, ~(DERRMR_PIPEA_PRI_FLIP_DONE |
DERRMR_PIPEB_PRI_FLIP_DONE |
DERRMR_PIPEC_PRI_FLIP_DONE));
intel_ring_emit(ring, MI_STORE_REGISTER_MEM(1) |
MI_SRM_LRM_GLOBAL_GTT);
intel_ring_emit(ring, DERRMR);
intel_ring_emit(ring, ring->scratch.gtt_offset + 256);
}
intel_ring_emit(ring, MI_DISPLAY_FLIP_I915 | plane_bit);
intel_ring_emit(ring, (fb->pitches[0] | obj->tiling_mode));
intel_ring_emit(ring, i915_gem_obj_ggtt_offset(obj) + intel_crtc->dspaddr_offset);
intel_ring_emit(ring, (MI_NOOP));
intel_mark_page_flip_active(intel_crtc);
__intel_ring_advance(ring);
return 0;
err_unpin:
intel_unpin_fb_obj(obj);
err:
return ret;
}
static int intel_default_queue_flip(struct drm_device *dev,
struct drm_crtc *crtc,
struct drm_framebuffer *fb,
struct drm_i915_gem_object *obj,
uint32_t flags)
{
return -ENODEV;
}
static int intel_crtc_page_flip(struct drm_crtc *crtc,
struct drm_framebuffer *fb,
struct drm_pending_vblank_event *event,
uint32_t page_flip_flags)
{
struct drm_device *dev = crtc->dev;
struct drm_i915_private *dev_priv = dev->dev_private;
struct drm_framebuffer *old_fb = crtc->primary->fb;
struct drm_i915_gem_object *obj = to_intel_framebuffer(fb)->obj;
struct intel_crtc *intel_crtc = to_intel_crtc(crtc);
struct intel_unpin_work *work;
unsigned long flags;
int ret;
if (fb->pixel_format != crtc->primary->fb->pixel_format)
return -EINVAL;
if (INTEL_INFO(dev)->gen > 3 &&
(fb->offsets[0] != crtc->primary->fb->offsets[0] ||
fb->pitches[0] != crtc->primary->fb->pitches[0]))
return -EINVAL;
if (i915_terminally_wedged(&dev_priv->gpu_error))
goto out_hang;
work = kzalloc(sizeof(*work), GFP_KERNEL);
if (work == NULL)
return -ENOMEM;
work->event = event;
work->crtc = crtc;
work->old_fb_obj = to_intel_framebuffer(old_fb)->obj;
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
if (atomic_read(&intel_crtc->unpin_work_count) >= 2)
flush_workqueue(dev_priv->wq);
ret = i915_mutex_lock_interruptible(dev);
if (ret)
goto cleanup;
drm_gem_object_reference(&work->old_fb_obj->base);
drm_gem_object_reference(&obj->base);
crtc->primary->fb = fb;
work->pending_flip_obj = obj;
work->enable_stall_check = true;
atomic_inc(&intel_crtc->unpin_work_count);
intel_crtc->reset_counter = atomic_read(&dev_priv->gpu_error.reset_counter);
ret = dev_priv->display.queue_flip(dev, crtc, fb, obj, page_flip_flags);
if (ret)
goto cleanup_pending;
intel_disable_fbc(dev);
intel_mark_fb_busy(obj, NULL);
mutex_unlock(&dev->struct_mutex);
trace_i915_flip_request(intel_crtc->plane, obj);
return 0;
cleanup_pending:
atomic_dec(&intel_crtc->unpin_work_count);
crtc->primary->fb = old_fb;
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
if (ret == -EIO) {
out_hang:
intel_crtc_wait_for_pending_flips(crtc);
ret = intel_pipe_set_base(crtc, crtc->x, crtc->y, fb);
if (ret == 0 && event)
drm_send_vblank_event(dev, intel_crtc->pipe, event);
}
return ret;
}
static void intel_modeset_update_staged_output_state(struct drm_device *dev)
{
struct intel_crtc *crtc;
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
list_for_each_entry(crtc, &dev->mode_config.crtc_list,
base.head) {
crtc->new_enabled = crtc->base.enabled;
if (crtc->new_enabled)
crtc->new_config = &crtc->config;
else
crtc->new_config = NULL;
}
}
static void intel_modeset_commit_output_state(struct drm_device *dev)
{
struct intel_crtc *crtc;
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
list_for_each_entry(crtc, &dev->mode_config.crtc_list,
base.head) {
crtc->base.enabled = crtc->new_enabled;
}
}
static void
connected_sink_compute_bpp(struct intel_connector * connector,
struct intel_crtc_config *pipe_config)
{
int bpp = pipe_config->pipe_bpp;
DRM_DEBUG_KMS("[CONNECTOR:%d:%s] checking for sink bpp constrains\n",
connector->base.base.id,
drm_get_connector_name(&connector->base));
if (connector->base.display_info.bpc &&
connector->base.display_info.bpc * 3 < bpp) {
DRM_DEBUG_KMS("clamping display bpp (was %d) to EDID reported max of %d\n",
bpp, connector->base.display_info.bpc*3);
pipe_config->pipe_bpp = connector->base.display_info.bpc*3;
}
if (connector->base.display_info.bpc == 0 && bpp > 24) {
DRM_DEBUG_KMS("clamping display bpp (was %d) to default limit of 24\n",
bpp);
pipe_config->pipe_bpp = 24;
}
}
static int
compute_baseline_pipe_bpp(struct intel_crtc *crtc,
struct drm_framebuffer *fb,
struct intel_crtc_config *pipe_config)
{
struct drm_device *dev = crtc->base.dev;
struct intel_connector *connector;
int bpp;
switch (fb->pixel_format) {
case DRM_FORMAT_C8:
bpp = 8*3;
break;
case DRM_FORMAT_XRGB1555:
case DRM_FORMAT_ARGB1555:
if (WARN_ON(INTEL_INFO(dev)->gen > 3))
return -EINVAL;
case DRM_FORMAT_RGB565:
bpp = 6*3;
break;
case DRM_FORMAT_XBGR8888:
case DRM_FORMAT_ABGR8888:
if (WARN_ON(INTEL_INFO(dev)->gen < 4))
return -EINVAL;
case DRM_FORMAT_XRGB8888:
case DRM_FORMAT_ARGB8888:
bpp = 8*3;
break;
case DRM_FORMAT_XRGB2101010:
case DRM_FORMAT_ARGB2101010:
case DRM_FORMAT_XBGR2101010:
case DRM_FORMAT_ABGR2101010:
if (WARN_ON(INTEL_INFO(dev)->gen < 4))
return -EINVAL;
bpp = 10*3;
break;
default:
DRM_DEBUG_KMS("unsupported depth\n");
return -EINVAL;
}
pipe_config->pipe_bpp = bpp;
list_for_each_entry(connector, &dev->mode_config.connector_list,
base.head) {
if (!connector->new_encoder ||
connector->new_encoder->new_crtc != crtc)
continue;
connected_sink_compute_bpp(connector, pipe_config);
}
return bpp;
}
static void intel_dump_crtc_timings(const struct drm_display_mode *mode)
{
DRM_DEBUG_KMS("crtc timings: %d %d %d %d %d %d %d %d %d, "
"type: 0x%x flags: 0x%x\n",
mode->crtc_clock,
mode->crtc_hdisplay, mode->crtc_hsync_start,
mode->crtc_hsync_end, mode->crtc_htotal,
mode->crtc_vdisplay, mode->crtc_vsync_start,
mode->crtc_vsync_end, mode->crtc_vtotal, mode->type, mode->flags);
}
static void intel_dump_pipe_config(struct intel_crtc *crtc,
struct intel_crtc_config *pipe_config,
const char *context)
{
DRM_DEBUG_KMS("[CRTC:%d]%s config for pipe %c\n", crtc->base.base.id,
context, pipe_name(crtc->pipe));
DRM_DEBUG_KMS("cpu_transcoder: %c\n", transcoder_name(pipe_config->cpu_transcoder));
DRM_DEBUG_KMS("pipe bpp: %i, dithering: %i\n",
pipe_config->pipe_bpp, pipe_config->dither);
DRM_DEBUG_KMS("fdi/pch: %i, lanes: %i, gmch_m: %u, gmch_n: %u, link_m: %u, link_n: %u, tu: %u\n",
pipe_config->has_pch_encoder,
pipe_config->fdi_lanes,
pipe_config->fdi_m_n.gmch_m, pipe_config->fdi_m_n.gmch_n,
pipe_config->fdi_m_n.link_m, pipe_config->fdi_m_n.link_n,
pipe_config->fdi_m_n.tu);
DRM_DEBUG_KMS("dp: %i, gmch_m: %u, gmch_n: %u, link_m: %u, link_n: %u, tu: %u\n",
pipe_config->has_dp_encoder,
pipe_config->dp_m_n.gmch_m, pipe_config->dp_m_n.gmch_n,
pipe_config->dp_m_n.link_m, pipe_config->dp_m_n.link_n,
pipe_config->dp_m_n.tu);
DRM_DEBUG_KMS("requested mode:\n");
drm_mode_debug_printmodeline(&pipe_config->requested_mode);
DRM_DEBUG_KMS("adjusted mode:\n");
drm_mode_debug_printmodeline(&pipe_config->adjusted_mode);
intel_dump_crtc_timings(&pipe_config->adjusted_mode);
DRM_DEBUG_KMS("port clock: %d\n", pipe_config->port_clock);
DRM_DEBUG_KMS("pipe src size: %dx%d\n",
pipe_config->pipe_src_w, pipe_config->pipe_src_h);
DRM_DEBUG_KMS("gmch pfit: control: 0x%08x, ratios: 0x%08x, lvds border: 0x%08x\n",
pipe_config->gmch_pfit.control,
pipe_config->gmch_pfit.pgm_ratios,
pipe_config->gmch_pfit.lvds_border_bits);
DRM_DEBUG_KMS("pch pfit: pos: 0x%08x, size: 0x%08x, %s\n",
pipe_config->pch_pfit.pos,
pipe_config->pch_pfit.size,
pipe_config->pch_pfit.enabled ? "enabled" : "disabled");
DRM_DEBUG_KMS("ips: %i\n", pipe_config->ips_enabled);
DRM_DEBUG_KMS("double wide: %i\n", pipe_config->double_wide);
}
static bool encoders_cloneable(const struct intel_encoder *a,
const struct intel_encoder *b)
{
return a == b || (a->cloneable & (1 << b->type) &&
b->cloneable & (1 << a->type));
}
static bool check_single_encoder_cloning(struct intel_crtc *crtc,
struct intel_encoder *encoder)
{
struct drm_device *dev = crtc->base.dev;
struct intel_encoder *source_encoder;
list_for_each_entry(source_encoder,
&dev->mode_config.encoder_list, base.head) {
if (source_encoder->new_crtc != crtc)
continue;
if (!encoders_cloneable(encoder, source_encoder))
return false;
}
return true;
}
static bool check_encoder_cloning(struct intel_crtc *crtc)
{
struct drm_device *dev = crtc->base.dev;
struct intel_encoder *encoder;
list_for_each_entry(encoder,
&dev->mode_config.encoder_list, base.head) {
if (encoder->new_crtc != crtc)
continue;
if (!check_single_encoder_cloning(crtc, encoder))
return false;
}
return true;
}
static struct intel_crtc_config *
intel_modeset_pipe_config(struct drm_crtc *crtc,
struct drm_framebuffer *fb,
struct drm_display_mode *mode)
{
struct drm_device *dev = crtc->dev;
struct intel_encoder *encoder;
struct intel_crtc_config *pipe_config;
int plane_bpp, ret = -EINVAL;
bool retry = true;
if (!check_encoder_cloning(to_intel_crtc(crtc))) {
DRM_DEBUG_KMS("rejecting invalid cloning configuration\n");
return ERR_PTR(-EINVAL);
}
pipe_config = kzalloc(sizeof(*pipe_config), GFP_KERNEL);
if (!pipe_config)
return ERR_PTR(-ENOMEM);
drm_mode_copy(&pipe_config->adjusted_mode, mode);
drm_mode_copy(&pipe_config->requested_mode, mode);
pipe_config->cpu_transcoder =
(enum transcoder) to_intel_crtc(crtc)->pipe;
pipe_config->shared_dpll = DPLL_ID_PRIVATE;
if (!(pipe_config->adjusted_mode.flags &
(DRM_MODE_FLAG_PHSYNC | DRM_MODE_FLAG_NHSYNC)))
pipe_config->adjusted_mode.flags |= DRM_MODE_FLAG_NHSYNC;
if (!(pipe_config->adjusted_mode.flags &
(DRM_MODE_FLAG_PVSYNC | DRM_MODE_FLAG_NVSYNC)))
pipe_config->adjusted_mode.flags |= DRM_MODE_FLAG_NVSYNC;
plane_bpp = compute_baseline_pipe_bpp(to_intel_crtc(crtc),
fb, pipe_config);
if (plane_bpp < 0)
goto fail;
drm_mode_set_crtcinfo(&pipe_config->requested_mode, CRTC_STEREO_DOUBLE);
pipe_config->pipe_src_w = pipe_config->requested_mode.crtc_hdisplay;
pipe_config->pipe_src_h = pipe_config->requested_mode.crtc_vdisplay;
encoder_retry:
pipe_config->port_clock = 0;
pipe_config->pixel_multiplier = 1;
drm_mode_set_crtcinfo(&pipe_config->adjusted_mode, CRTC_STEREO_DOUBLE);
list_for_each_entry(encoder, &dev->mode_config.encoder_list,
base.head) {
if (&encoder->new_crtc->base != crtc)
continue;
if (!(encoder->compute_config(encoder, pipe_config))) {
DRM_DEBUG_KMS("Encoder config failure\n");
goto fail;
}
}
if (!pipe_config->port_clock)
pipe_config->port_clock = pipe_config->adjusted_mode.crtc_clock
* pipe_config->pixel_multiplier;
ret = intel_crtc_compute_config(to_intel_crtc(crtc), pipe_config);
if (ret < 0) {
DRM_DEBUG_KMS("CRTC fixup failed\n");
goto fail;
}
if (ret == RETRY) {
if (WARN(!retry, "loop in pipe configuration computation\n")) {
ret = -EINVAL;
goto fail;
}
DRM_DEBUG_KMS("CRTC bw constrained, retrying\n");
retry = false;
goto encoder_retry;
}
pipe_config->dither = pipe_config->pipe_bpp != plane_bpp;
DRM_DEBUG_KMS("plane bpp: %i, pipe bpp: %i, dithering: %i\n",
plane_bpp, pipe_config->pipe_bpp, pipe_config->dither);
return pipe_config;
fail:
kfree(pipe_config);
return ERR_PTR(ret);
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
if (intel_crtc->base.enabled == intel_crtc->new_enabled)
continue;
if (!intel_crtc->new_enabled)
*disable_pipes |= 1 << intel_crtc->pipe;
else
*prepare_pipes |= 1 << intel_crtc->pipe;
}
intel_crtc = to_intel_crtc(crtc);
if (intel_crtc->new_enabled)
*prepare_pipes |= 1 << intel_crtc->pipe;
if (*prepare_pipes)
*modeset_pipes = *prepare_pipes;
*modeset_pipes &= ~(*disable_pipes);
*prepare_pipes &= ~(*disable_pipes);
*modeset_pipes &= 1 << intel_crtc->pipe;
*prepare_pipes &= 1 << intel_crtc->pipe;
DRM_DEBUG_KMS("set mode pipe masks: modeset: %x, prepare: %x, disable: %x\n",
*modeset_pipes, *prepare_pipes, *disable_pipes);
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
WARN_ON(intel_crtc->base.enabled != intel_crtc_in_use(&intel_crtc->base));
WARN_ON(intel_crtc->new_config &&
intel_crtc->new_config != &intel_crtc->config);
WARN_ON(intel_crtc->base.enabled != !!intel_crtc->new_config);
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
static bool intel_fuzzy_clock_check(int clock1, int clock2)
{
int diff;
if (clock1 == clock2)
return true;
if (!clock1 || !clock2)
return false;
diff = abs(clock1 - clock2);
if (((((diff + clock1 + clock2) * 100)) / (clock1 + clock2)) < 105)
return true;
return false;
}
static bool
intel_pipe_config_compare(struct drm_device *dev,
struct intel_crtc_config *current_config,
struct intel_crtc_config *pipe_config)
{
#define PIPE_CONF_CHECK_X(name) \
if (current_config->name != pipe_config->name) { \
DRM_ERROR("mismatch in " #name " " \
"(expected 0x%08x, found 0x%08x)\n", \
current_config->name, \
pipe_config->name); \
return false; \
}
#define PIPE_CONF_CHECK_I(name) \
if (current_config->name != pipe_config->name) { \
DRM_ERROR("mismatch in " #name " " \
"(expected %i, found %i)\n", \
current_config->name, \
pipe_config->name); \
return false; \
}
#define PIPE_CONF_CHECK_FLAGS(name, mask) \
if ((current_config->name ^ pipe_config->name) & (mask)) { \
DRM_ERROR("mismatch in " #name "(" #mask ") " \
"(expected %i, found %i)\n", \
current_config->name & (mask), \
pipe_config->name & (mask)); \
return false; \
}
#define PIPE_CONF_CHECK_CLOCK_FUZZY(name) \
if (!intel_fuzzy_clock_check(current_config->name, pipe_config->name)) { \
DRM_ERROR("mismatch in " #name " " \
"(expected %i, found %i)\n", \
current_config->name, \
pipe_config->name); \
return false; \
}
#define PIPE_CONF_QUIRK(quirk) \
((current_config->quirks | pipe_config->quirks) & (quirk))
PIPE_CONF_CHECK_I(cpu_transcoder);
PIPE_CONF_CHECK_I(has_pch_encoder);
PIPE_CONF_CHECK_I(fdi_lanes);
PIPE_CONF_CHECK_I(fdi_m_n.gmch_m);
PIPE_CONF_CHECK_I(fdi_m_n.gmch_n);
PIPE_CONF_CHECK_I(fdi_m_n.link_m);
PIPE_CONF_CHECK_I(fdi_m_n.link_n);
PIPE_CONF_CHECK_I(fdi_m_n.tu);
PIPE_CONF_CHECK_I(has_dp_encoder);
PIPE_CONF_CHECK_I(dp_m_n.gmch_m);
PIPE_CONF_CHECK_I(dp_m_n.gmch_n);
PIPE_CONF_CHECK_I(dp_m_n.link_m);
PIPE_CONF_CHECK_I(dp_m_n.link_n);
PIPE_CONF_CHECK_I(dp_m_n.tu);
PIPE_CONF_CHECK_I(adjusted_mode.crtc_hdisplay);
PIPE_CONF_CHECK_I(adjusted_mode.crtc_htotal);
PIPE_CONF_CHECK_I(adjusted_mode.crtc_hblank_start);
PIPE_CONF_CHECK_I(adjusted_mode.crtc_hblank_end);
PIPE_CONF_CHECK_I(adjusted_mode.crtc_hsync_start);
PIPE_CONF_CHECK_I(adjusted_mode.crtc_hsync_end);
PIPE_CONF_CHECK_I(adjusted_mode.crtc_vdisplay);
PIPE_CONF_CHECK_I(adjusted_mode.crtc_vtotal);
PIPE_CONF_CHECK_I(adjusted_mode.crtc_vblank_start);
PIPE_CONF_CHECK_I(adjusted_mode.crtc_vblank_end);
PIPE_CONF_CHECK_I(adjusted_mode.crtc_vsync_start);
PIPE_CONF_CHECK_I(adjusted_mode.crtc_vsync_end);
PIPE_CONF_CHECK_I(pixel_multiplier);
PIPE_CONF_CHECK_FLAGS(adjusted_mode.flags,
DRM_MODE_FLAG_INTERLACE);
if (!PIPE_CONF_QUIRK(PIPE_CONFIG_QUIRK_MODE_SYNC_FLAGS)) {
PIPE_CONF_CHECK_FLAGS(adjusted_mode.flags,
DRM_MODE_FLAG_PHSYNC);
PIPE_CONF_CHECK_FLAGS(adjusted_mode.flags,
DRM_MODE_FLAG_NHSYNC);
PIPE_CONF_CHECK_FLAGS(adjusted_mode.flags,
DRM_MODE_FLAG_PVSYNC);
PIPE_CONF_CHECK_FLAGS(adjusted_mode.flags,
DRM_MODE_FLAG_NVSYNC);
}
PIPE_CONF_CHECK_I(pipe_src_w);
PIPE_CONF_CHECK_I(pipe_src_h);
if (!PIPE_CONF_QUIRK(PIPE_CONFIG_QUIRK_INHERITED_MODE)) {
PIPE_CONF_CHECK_I(gmch_pfit.control);
if (INTEL_INFO(dev)->gen < 4)
PIPE_CONF_CHECK_I(gmch_pfit.pgm_ratios);
PIPE_CONF_CHECK_I(gmch_pfit.lvds_border_bits);
}
PIPE_CONF_CHECK_I(pch_pfit.enabled);
if (current_config->pch_pfit.enabled) {
PIPE_CONF_CHECK_I(pch_pfit.pos);
PIPE_CONF_CHECK_I(pch_pfit.size);
}
if (IS_HASWELL(dev))
PIPE_CONF_CHECK_I(ips_enabled);
PIPE_CONF_CHECK_I(double_wide);
PIPE_CONF_CHECK_I(shared_dpll);
PIPE_CONF_CHECK_X(dpll_hw_state.dpll);
PIPE_CONF_CHECK_X(dpll_hw_state.dpll_md);
PIPE_CONF_CHECK_X(dpll_hw_state.fp0);
PIPE_CONF_CHECK_X(dpll_hw_state.fp1);
if (IS_G4X(dev) || INTEL_INFO(dev)->gen >= 5)
PIPE_CONF_CHECK_I(pipe_bpp);
PIPE_CONF_CHECK_CLOCK_FUZZY(adjusted_mode.crtc_clock);
PIPE_CONF_CHECK_CLOCK_FUZZY(port_clock);
#undef PIPE_CONF_CHECK_X
#undef PIPE_CONF_CHECK_I
#undef PIPE_CONF_CHECK_FLAGS
#undef PIPE_CONF_CHECK_CLOCK_FUZZY
#undef PIPE_CONF_QUIRK
return true;
}
static void
check_connector_state(struct drm_device *dev)
{
struct intel_connector *connector;
list_for_each_entry(connector, &dev->mode_config.connector_list,
base.head) {
intel_connector_check_state(connector);
WARN(&connector->new_encoder->base != connector->base.encoder,
"connector's staged encoder doesn't match current encoder\n");
}
}
static void
check_encoder_state(struct drm_device *dev)
{
struct intel_encoder *encoder;
struct intel_connector *connector;
list_for_each_entry(encoder, &dev->mode_config.encoder_list,
base.head) {
bool enabled = false;
bool active = false;
enum pipe pipe, tracked_pipe;
DRM_DEBUG_KMS("[ENCODER:%d:%s]\n",
encoder->base.base.id,
drm_get_encoder_name(&encoder->base));
WARN(&encoder->new_crtc->base != encoder->base.crtc,
"encoder's stage crtc doesn't match current crtc\n");
WARN(encoder->connectors_active && !encoder->base.crtc,
"encoder's active_connectors set, but no crtc\n");
list_for_each_entry(connector, &dev->mode_config.connector_list,
base.head) {
if (connector->base.encoder != &encoder->base)
continue;
enabled = true;
if (connector->base.dpms != DRM_MODE_DPMS_OFF)
active = true;
}
WARN(!!encoder->base.crtc != enabled,
"encoder's enabled state mismatch "
"(expected %i, found %i)\n",
!!encoder->base.crtc, enabled);
WARN(active && !encoder->base.crtc,
"active encoder with no crtc\n");
WARN(encoder->connectors_active != active,
"encoder's computed active state doesn't match tracked active state "
"(expected %i, found %i)\n", active, encoder->connectors_active);
active = encoder->get_hw_state(encoder, &pipe);
WARN(active != encoder->connectors_active,
"encoder's hw state doesn't match sw tracking "
"(expected %i, found %i)\n",
encoder->connectors_active, active);
if (!encoder->base.crtc)
continue;
tracked_pipe = to_intel_crtc(encoder->base.crtc)->pipe;
WARN(active && pipe != tracked_pipe,
"active encoder's pipe doesn't match"
"(expected %i, found %i)\n",
tracked_pipe, pipe);
}
}
static void
check_crtc_state(struct drm_device *dev)
{
struct drm_i915_private *dev_priv = dev->dev_private;
struct intel_crtc *crtc;
struct intel_encoder *encoder;
struct intel_crtc_config pipe_config;
list_for_each_entry(crtc, &dev->mode_config.crtc_list,
base.head) {
bool enabled = false;
bool active = false;
memset(&pipe_config, 0, sizeof(pipe_config));
DRM_DEBUG_KMS("[CRTC:%d]\n",
crtc->base.base.id);
WARN(crtc->active && !crtc->base.enabled,
"active crtc, but not enabled in sw tracking\n");
list_for_each_entry(encoder, &dev->mode_config.encoder_list,
base.head) {
if (encoder->base.crtc != &crtc->base)
continue;
enabled = true;
if (encoder->connectors_active)
active = true;
}
WARN(active != crtc->active,
"crtc's computed active state doesn't match tracked active state "
"(expected %i, found %i)\n", active, crtc->active);
WARN(enabled != crtc->base.enabled,
"crtc's computed enabled state doesn't match tracked enabled state "
"(expected %i, found %i)\n", enabled, crtc->base.enabled);
active = dev_priv->display.get_pipe_config(crtc,
&pipe_config);
if (crtc->pipe == PIPE_A && dev_priv->quirks & QUIRK_PIPEA_FORCE)
active = crtc->active;
list_for_each_entry(encoder, &dev->mode_config.encoder_list,
base.head) {
enum pipe pipe;
if (encoder->base.crtc != &crtc->base)
continue;
if (encoder->get_hw_state(encoder, &pipe))
encoder->get_config(encoder, &pipe_config);
}
WARN(crtc->active != active,
"crtc active state doesn't match with hw state "
"(expected %i, found %i)\n", crtc->active, active);
if (active &&
!intel_pipe_config_compare(dev, &crtc->config, &pipe_config)) {
WARN(1, "pipe state doesn't match!\n");
intel_dump_pipe_config(crtc, &pipe_config,
"[hw state]");
intel_dump_pipe_config(crtc, &crtc->config,
"[sw state]");
}
}
}
static void
check_shared_dpll_state(struct drm_device *dev)
{
struct drm_i915_private *dev_priv = dev->dev_private;
struct intel_crtc *crtc;
struct intel_dpll_hw_state dpll_hw_state;
int i;
for (i = 0; i < dev_priv->num_shared_dpll; i++) {
struct intel_shared_dpll *pll = &dev_priv->shared_dplls[i];
int enabled_crtcs = 0, active_crtcs = 0;
bool active;
memset(&dpll_hw_state, 0, sizeof(dpll_hw_state));
DRM_DEBUG_KMS("%s\n", pll->name);
active = pll->get_hw_state(dev_priv, pll, &dpll_hw_state);
WARN(pll->active > pll->refcount,
"more active pll users than references: %i vs %i\n",
pll->active, pll->refcount);
WARN(pll->active && !pll->on,
"pll in active use but not on in sw tracking\n");
WARN(pll->on && !pll->active,
"pll in on but not on in use in sw tracking\n");
WARN(pll->on != active,
"pll on state mismatch (expected %i, found %i)\n",
pll->on, active);
list_for_each_entry(crtc, &dev->mode_config.crtc_list,
base.head) {
if (crtc->base.enabled && intel_crtc_to_shared_dpll(crtc) == pll)
enabled_crtcs++;
if (crtc->active && intel_crtc_to_shared_dpll(crtc) == pll)
active_crtcs++;
}
WARN(pll->active != active_crtcs,
"pll active crtcs mismatch (expected %i, found %i)\n",
pll->active, active_crtcs);
WARN(pll->refcount != enabled_crtcs,
"pll enabled crtcs mismatch (expected %i, found %i)\n",
pll->refcount, enabled_crtcs);
WARN(pll->on && memcmp(&pll->hw_state, &dpll_hw_state,
sizeof(dpll_hw_state)),
"pll hw state mismatch\n");
}
}
void
intel_modeset_check_state(struct drm_device *dev)
{
check_connector_state(dev);
check_encoder_state(dev);
check_crtc_state(dev);
check_shared_dpll_state(dev);
}
void ironlake_check_encoder_dotclock(const struct intel_crtc_config *pipe_config,
int dotclock)
{
WARN(!intel_fuzzy_clock_check(pipe_config->adjusted_mode.crtc_clock, dotclock),
"FDI dotclock and encoder dotclock mismatch, fdi: %i, encoder: %i\n",
pipe_config->adjusted_mode.crtc_clock, dotclock);
}
static int __intel_set_mode(struct drm_crtc *crtc,
struct drm_display_mode *mode,
int x, int y, struct drm_framebuffer *fb)
{
struct drm_device *dev = crtc->dev;
struct drm_i915_private *dev_priv = dev->dev_private;
struct drm_display_mode *saved_mode;
struct intel_crtc_config *pipe_config = NULL;
struct intel_crtc *intel_crtc;
unsigned disable_pipes, prepare_pipes, modeset_pipes;
int ret = 0;
saved_mode = kmalloc(sizeof(*saved_mode), GFP_KERNEL);
if (!saved_mode)
return -ENOMEM;
intel_modeset_affected_pipes(crtc, &modeset_pipes,
&prepare_pipes, &disable_pipes);
*saved_mode = crtc->mode;
if (modeset_pipes) {
pipe_config = intel_modeset_pipe_config(crtc, fb, mode);
if (IS_ERR(pipe_config)) {
ret = PTR_ERR(pipe_config);
pipe_config = NULL;
goto out;
}
intel_dump_pipe_config(to_intel_crtc(crtc), pipe_config,
"[modeset]");
to_intel_crtc(crtc)->new_config = pipe_config;
}
if (IS_VALLEYVIEW(dev)) {
valleyview_modeset_global_pipes(dev, &prepare_pipes);
prepare_pipes &= ~disable_pipes;
}
for_each_intel_crtc_masked(dev, disable_pipes, intel_crtc)
intel_crtc_disable(&intel_crtc->base);
for_each_intel_crtc_masked(dev, prepare_pipes, intel_crtc) {
if (intel_crtc->base.enabled)
dev_priv->display.crtc_disable(&intel_crtc->base);
}
if (modeset_pipes) {
crtc->mode = *mode;
to_intel_crtc(crtc)->config = *pipe_config;
to_intel_crtc(crtc)->new_config = &to_intel_crtc(crtc)->config;
drm_calc_timestamping_constants(crtc,
&pipe_config->adjusted_mode);
}
intel_modeset_update_state(dev, prepare_pipes);
if (dev_priv->display.modeset_global_resources)
dev_priv->display.modeset_global_resources(dev);
for_each_intel_crtc_masked(dev, modeset_pipes, intel_crtc) {
ret = intel_crtc_mode_set(&intel_crtc->base,
x, y, fb);
if (ret)
goto done;
}
for_each_intel_crtc_masked(dev, prepare_pipes, intel_crtc)
dev_priv->display.crtc_enable(&intel_crtc->base);
done:
if (ret && crtc->enabled)
crtc->mode = *saved_mode;
out:
kfree(pipe_config);
kfree(saved_mode);
return ret;
}
static int intel_set_mode(struct drm_crtc *crtc,
struct drm_display_mode *mode,
int x, int y, struct drm_framebuffer *fb)
{
int ret;
ret = __intel_set_mode(crtc, mode, x, y, fb);
if (ret == 0)
intel_modeset_check_state(crtc->dev);
return ret;
}
void intel_crtc_restore_mode(struct drm_crtc *crtc)
{
intel_set_mode(crtc, &crtc->mode, crtc->x, crtc->y, crtc->primary->fb);
}
static void intel_set_config_free(struct intel_set_config *config)
{
if (!config)
return;
kfree(config->save_connector_encoders);
kfree(config->save_encoder_crtcs);
kfree(config->save_crtc_enabled);
kfree(config);
}
static int intel_set_config_save_state(struct drm_device *dev,
struct intel_set_config *config)
{
struct drm_crtc *crtc;
struct drm_encoder *encoder;
struct drm_connector *connector;
int count;
config->save_crtc_enabled =
kcalloc(dev->mode_config.num_crtc,
sizeof(bool), GFP_KERNEL);
if (!config->save_crtc_enabled)
return -ENOMEM;
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
list_for_each_entry(crtc, &dev->mode_config.crtc_list, head) {
config->save_crtc_enabled[count++] = crtc->enabled;
}
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
struct intel_crtc *crtc;
struct intel_encoder *encoder;
struct intel_connector *connector;
int count;
count = 0;
list_for_each_entry(crtc, &dev->mode_config.crtc_list, base.head) {
crtc->new_enabled = config->save_crtc_enabled[count++];
if (crtc->new_enabled)
crtc->new_config = &crtc->config;
else
crtc->new_config = NULL;
}
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
static bool
is_crtc_connector_off(struct drm_mode_set *set)
{
int i;
if (set->num_connectors == 0)
return false;
if (WARN_ON(set->connectors == NULL))
return false;
for (i = 0; i < set->num_connectors; i++)
if (set->connectors[i]->encoder &&
set->connectors[i]->encoder->crtc == set->crtc &&
set->connectors[i]->dpms != DRM_MODE_DPMS_ON)
return true;
return false;
}
static void
intel_set_config_compute_mode_changes(struct drm_mode_set *set,
struct intel_set_config *config)
{
if (is_crtc_connector_off(set)) {
config->mode_changed = true;
} else if (set->crtc->primary->fb != set->fb) {
if (set->crtc->primary->fb == NULL) {
struct intel_crtc *intel_crtc =
to_intel_crtc(set->crtc);
if (intel_crtc->active && i915.fastboot) {
DRM_DEBUG_KMS("crtc has no fb, will flip\n");
config->fb_changed = true;
} else {
DRM_DEBUG_KMS("inactive crtc, full mode set\n");
config->mode_changed = true;
}
} else if (set->fb == NULL) {
config->mode_changed = true;
} else if (set->fb->pixel_format !=
set->crtc->primary->fb->pixel_format) {
config->mode_changed = true;
} else {
config->fb_changed = true;
}
}
if (set->fb && (set->x != set->crtc->x || set->y != set->crtc->y))
config->fb_changed = true;
if (set->mode && !drm_mode_equal(set->mode, &set->crtc->mode)) {
DRM_DEBUG_KMS("modes are different, full mode set\n");
drm_mode_debug_printmodeline(&set->crtc->mode);
drm_mode_debug_printmodeline(set->mode);
config->mode_changed = true;
}
DRM_DEBUG_KMS("computed changes for [CRTC:%d], mode_changed=%d, fb_changed=%d\n",
set->crtc->base.id, config->mode_changed, config->fb_changed);
}
static int
intel_modeset_stage_output_state(struct drm_device *dev,
struct drm_mode_set *set,
struct intel_set_config *config)
{
struct intel_connector *connector;
struct intel_encoder *encoder;
struct intel_crtc *crtc;
int ro;
WARN_ON(!set->fb && (set->num_connectors != 0));
WARN_ON(set->fb && (set->num_connectors == 0));
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
list_for_each_entry(connector, &dev->mode_config.connector_list,
base.head) {
struct drm_crtc *new_crtc;
if (!connector->new_encoder)
continue;
new_crtc = connector->new_encoder->base.crtc;
for (ro = 0; ro < set->num_connectors; ro++) {
if (set->connectors[ro] == &connector->base)
new_crtc = set->crtc;
}
if (!drm_encoder_crtc_ok(&connector->new_encoder->base,
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
int num_connectors = 0;
list_for_each_entry(connector,
&dev->mode_config.connector_list,
base.head) {
if (connector->new_encoder == encoder) {
WARN_ON(!connector->new_encoder->new_crtc);
num_connectors++;
}
}
if (num_connectors == 0)
encoder->new_crtc = NULL;
else if (num_connectors > 1)
return -EINVAL;
if (&encoder->new_crtc->base != encoder->base.crtc) {
DRM_DEBUG_KMS("crtc changed, full mode switch\n");
config->mode_changed = true;
}
}
list_for_each_entry(crtc, &dev->mode_config.crtc_list,
base.head) {
crtc->new_enabled = false;
list_for_each_entry(encoder,
&dev->mode_config.encoder_list,
base.head) {
if (encoder->new_crtc == crtc) {
crtc->new_enabled = true;
break;
}
}
if (crtc->new_enabled != crtc->base.enabled) {
DRM_DEBUG_KMS("crtc %sabled, full mode switch\n",
crtc->new_enabled ? "en" : "dis");
config->mode_changed = true;
}
if (crtc->new_enabled)
crtc->new_config = &crtc->config;
else
crtc->new_config = NULL;
}
return 0;
}
static void disable_crtc_nofb(struct intel_crtc *crtc)
{
struct drm_device *dev = crtc->base.dev;
struct intel_encoder *encoder;
struct intel_connector *connector;
DRM_DEBUG_KMS("Trying to restore without FB -> disabling pipe %c\n",
pipe_name(crtc->pipe));
list_for_each_entry(connector, &dev->mode_config.connector_list, base.head) {
if (connector->new_encoder &&
connector->new_encoder->new_crtc == crtc)
connector->new_encoder = NULL;
}
list_for_each_entry(encoder, &dev->mode_config.encoder_list, base.head) {
if (encoder->new_crtc == crtc)
encoder->new_crtc = NULL;
}
crtc->new_enabled = false;
crtc->new_config = NULL;
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
BUG_ON(!set->mode && set->fb);
BUG_ON(set->fb && set->num_connectors == 0);
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
save_set.fb = set->crtc->primary->fb;
intel_set_config_compute_mode_changes(set, config);
ret = intel_modeset_stage_output_state(dev, set, config);
if (ret)
goto fail;
if (config->mode_changed) {
ret = intel_set_mode(set->crtc, set->mode,
set->x, set->y, set->fb);
} else if (config->fb_changed) {
intel_crtc_wait_for_pending_flips(set->crtc);
ret = intel_pipe_set_base(set->crtc,
set->x, set->y, set->fb);
if (i915.fastboot && ret == 0)
intel_modeset_check_state(set->crtc->dev);
}
if (ret) {
DRM_DEBUG_KMS("failed to set mode on [CRTC:%d], err = %d\n",
set->crtc->base.id, ret);
fail:
intel_set_config_restore_state(dev, config);
if (to_intel_crtc(save_set.crtc)->new_enabled && !save_set.fb)
disable_crtc_nofb(to_intel_crtc(save_set.crtc));
if (config->mode_changed &&
intel_set_mode(save_set.crtc, save_set.mode,
save_set.x, save_set.y, save_set.fb))
DRM_ERROR("failed to restore config after modeset failure\n");
}
out_config:
intel_set_config_free(config);
return ret;
}
static void intel_cpu_pll_init(struct drm_device *dev)
{
if (HAS_DDI(dev))
intel_ddi_pll_init(dev);
}
static bool ibx_pch_dpll_get_hw_state(struct drm_i915_private *dev_priv,
struct intel_shared_dpll *pll,
struct intel_dpll_hw_state *hw_state)
{
uint32_t val;
val = I915_READ(PCH_DPLL(pll->id));
hw_state->dpll = val;
hw_state->fp0 = I915_READ(PCH_FP0(pll->id));
hw_state->fp1 = I915_READ(PCH_FP1(pll->id));
return val & DPLL_VCO_ENABLE;
}
static void ibx_pch_dpll_mode_set(struct drm_i915_private *dev_priv,
struct intel_shared_dpll *pll)
{
I915_WRITE(PCH_FP0(pll->id), pll->hw_state.fp0);
I915_WRITE(PCH_FP1(pll->id), pll->hw_state.fp1);
}
static void ibx_pch_dpll_enable(struct drm_i915_private *dev_priv,
struct intel_shared_dpll *pll)
{
ibx_assert_pch_refclk_enabled(dev_priv);
I915_WRITE(PCH_DPLL(pll->id), pll->hw_state.dpll);
POSTING_READ(PCH_DPLL(pll->id));
udelay(150);
I915_WRITE(PCH_DPLL(pll->id), pll->hw_state.dpll);
POSTING_READ(PCH_DPLL(pll->id));
udelay(200);
}
static void ibx_pch_dpll_disable(struct drm_i915_private *dev_priv,
struct intel_shared_dpll *pll)
{
struct drm_device *dev = dev_priv->dev;
struct intel_crtc *crtc;
list_for_each_entry(crtc, &dev->mode_config.crtc_list, base.head) {
if (intel_crtc_to_shared_dpll(crtc) == pll)
assert_pch_transcoder_disabled(dev_priv, crtc->pipe);
}
I915_WRITE(PCH_DPLL(pll->id), 0);
POSTING_READ(PCH_DPLL(pll->id));
udelay(200);
}
static void ibx_pch_dpll_init(struct drm_device *dev)
{
struct drm_i915_private *dev_priv = dev->dev_private;
int i;
dev_priv->num_shared_dpll = 2;
for (i = 0; i < dev_priv->num_shared_dpll; i++) {
dev_priv->shared_dplls[i].id = i;
dev_priv->shared_dplls[i].name = ibx_pch_dpll_names[i];
dev_priv->shared_dplls[i].mode_set = ibx_pch_dpll_mode_set;
dev_priv->shared_dplls[i].enable = ibx_pch_dpll_enable;
dev_priv->shared_dplls[i].disable = ibx_pch_dpll_disable;
dev_priv->shared_dplls[i].get_hw_state =
ibx_pch_dpll_get_hw_state;
}
}
static void intel_shared_dpll_init(struct drm_device *dev)
{
struct drm_i915_private *dev_priv = dev->dev_private;
if (HAS_PCH_IBX(dev) || HAS_PCH_CPT(dev))
ibx_pch_dpll_init(dev);
else
dev_priv->num_shared_dpll = 0;
BUG_ON(dev_priv->num_shared_dpll > I915_NUM_PLLS);
}
static void intel_crtc_init(struct drm_device *dev, int pipe)
{
struct drm_i915_private *dev_priv = dev->dev_private;
struct intel_crtc *intel_crtc;
int i;
intel_crtc = kzalloc(sizeof(*intel_crtc), GFP_KERNEL);
if (intel_crtc == NULL)
return;
drm_crtc_init(dev, &intel_crtc->base, &intel_crtc_funcs);
if (IS_GEN2(dev)) {
intel_crtc->max_cursor_width = GEN2_CURSOR_WIDTH;
intel_crtc->max_cursor_height = GEN2_CURSOR_HEIGHT;
} else {
intel_crtc->max_cursor_width = CURSOR_WIDTH;
intel_crtc->max_cursor_height = CURSOR_HEIGHT;
}
dev->mode_config.cursor_width = intel_crtc->max_cursor_width;
dev->mode_config.cursor_height = intel_crtc->max_cursor_height;
drm_mode_crtc_set_gamma_size(&intel_crtc->base, 256);
for (i = 0; i < 256; i++) {
intel_crtc->lut_r[i] = i;
intel_crtc->lut_g[i] = i;
intel_crtc->lut_b[i] = i;
}
intel_crtc->pipe = pipe;
intel_crtc->plane = pipe;
if (HAS_FBC(dev) && INTEL_INFO(dev)->gen < 4) {
DRM_DEBUG_KMS("swapping pipes & planes for FBC\n");
intel_crtc->plane = !pipe;
}
BUG_ON(pipe >= ARRAY_SIZE(dev_priv->plane_to_crtc_mapping) ||
dev_priv->plane_to_crtc_mapping[intel_crtc->plane] != NULL);
dev_priv->plane_to_crtc_mapping[intel_crtc->plane] = &intel_crtc->base;
dev_priv->pipe_to_crtc_mapping[intel_crtc->pipe] = &intel_crtc->base;
drm_crtc_helper_add(&intel_crtc->base, &intel_helper_funcs);
}
enum pipe intel_get_pipe_from_connector(struct intel_connector *connector)
{
struct drm_encoder *encoder = connector->base.encoder;
WARN_ON(!mutex_is_locked(&connector->base.dev->mode_config.mutex));
if (!encoder)
return INVALID_PIPE;
return to_intel_crtc(encoder->crtc)->pipe;
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
return -ENOENT;
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
if (encoders_cloneable(encoder, source_encoder))
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
if (IS_GEN5(dev) && (I915_READ(FUSE_STRAP) & ILK_eDP_A_DISABLE))
return false;
return true;
}
const char *intel_output_name(int output)
{
static const char *names[] = {
[INTEL_OUTPUT_UNUSED] = "Unused",
[INTEL_OUTPUT_ANALOG] = "Analog",
[INTEL_OUTPUT_DVO] = "DVO",
[INTEL_OUTPUT_SDVO] = "SDVO",
[INTEL_OUTPUT_LVDS] = "LVDS",
[INTEL_OUTPUT_TVOUT] = "TV",
[INTEL_OUTPUT_HDMI] = "HDMI",
[INTEL_OUTPUT_DISPLAYPORT] = "DisplayPort",
[INTEL_OUTPUT_EDP] = "eDP",
[INTEL_OUTPUT_DSI] = "DSI",
[INTEL_OUTPUT_UNKNOWN] = "Unknown",
};
if (output < 0 || output >= ARRAY_SIZE(names) || !names[output])
return "Invalid";
return names[output];
}
static void intel_setup_outputs(struct drm_device *dev)
{
struct drm_i915_private *dev_priv = dev->dev_private;
struct intel_encoder *encoder;
bool dpd_is_edp = false;
intel_lvds_init(dev);
if (!IS_ULT(dev))
intel_crt_init(dev);
if (HAS_DDI(dev)) {
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
dpd_is_edp = intel_dp_is_edp(dev, PORT_D);
if (has_edp_a(dev))
intel_dp_init(dev, DP_A, PORT_A);
if (I915_READ(PCH_HDMIB) & SDVO_DETECTED) {
found = intel_sdvo_init(dev, PCH_SDVOB, true);
if (!found)
intel_hdmi_init(dev, PCH_HDMIB, PORT_B);
if (!found && (I915_READ(PCH_DP_B) & DP_DETECTED))
intel_dp_init(dev, PCH_DP_B, PORT_B);
}
if (I915_READ(PCH_HDMIC) & SDVO_DETECTED)
intel_hdmi_init(dev, PCH_HDMIC, PORT_C);
if (!dpd_is_edp && I915_READ(PCH_HDMID) & SDVO_DETECTED)
intel_hdmi_init(dev, PCH_HDMID, PORT_D);
if (I915_READ(PCH_DP_C) & DP_DETECTED)
intel_dp_init(dev, PCH_DP_C, PORT_C);
if (I915_READ(PCH_DP_D) & DP_DETECTED)
intel_dp_init(dev, PCH_DP_D, PORT_D);
} else if (IS_VALLEYVIEW(dev)) {
if (I915_READ(VLV_DISPLAY_BASE + GEN4_HDMIB) & SDVO_DETECTED) {
intel_hdmi_init(dev, VLV_DISPLAY_BASE + GEN4_HDMIB,
PORT_B);
if (I915_READ(VLV_DISPLAY_BASE + DP_B) & DP_DETECTED)
intel_dp_init(dev, VLV_DISPLAY_BASE + DP_B, PORT_B);
}
if (I915_READ(VLV_DISPLAY_BASE + GEN4_HDMIC) & SDVO_DETECTED) {
intel_hdmi_init(dev, VLV_DISPLAY_BASE + GEN4_HDMIC,
PORT_C);
if (I915_READ(VLV_DISPLAY_BASE + DP_C) & DP_DETECTED)
intel_dp_init(dev, VLV_DISPLAY_BASE + DP_C, PORT_C);
}
intel_dsi_init(dev);
} else if (SUPPORTS_DIGITAL_OUTPUTS(dev)) {
bool found = false;
if (I915_READ(GEN3_SDVOB) & SDVO_DETECTED) {
DRM_DEBUG_KMS("probing SDVOB\n");
found = intel_sdvo_init(dev, GEN3_SDVOB, true);
if (!found && SUPPORTS_INTEGRATED_HDMI(dev)) {
DRM_DEBUG_KMS("probing HDMI on SDVOB\n");
intel_hdmi_init(dev, GEN4_HDMIB, PORT_B);
}
if (!found && SUPPORTS_INTEGRATED_DP(dev))
intel_dp_init(dev, DP_B, PORT_B);
}
if (I915_READ(GEN3_SDVOB) & SDVO_DETECTED) {
DRM_DEBUG_KMS("probing SDVOC\n");
found = intel_sdvo_init(dev, GEN3_SDVOC, false);
}
if (!found && (I915_READ(GEN3_SDVOC) & SDVO_DETECTED)) {
if (SUPPORTS_INTEGRATED_HDMI(dev)) {
DRM_DEBUG_KMS("probing HDMI on SDVOC\n");
intel_hdmi_init(dev, GEN4_HDMIC, PORT_C);
}
if (SUPPORTS_INTEGRATED_DP(dev))
intel_dp_init(dev, DP_C, PORT_C);
}
if (SUPPORTS_INTEGRATED_DP(dev) &&
(I915_READ(DP_D) & DP_DETECTED))
intel_dp_init(dev, DP_D, PORT_D);
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
WARN_ON(!intel_fb->obj->framebuffer_references--);
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
static int intel_framebuffer_init(struct drm_device *dev,
struct intel_framebuffer *intel_fb,
struct drm_mode_fb_cmd2 *mode_cmd,
struct drm_i915_gem_object *obj)
{
int aligned_height;
int pitch_limit;
int ret;
WARN_ON(!mutex_is_locked(&dev->struct_mutex));
if (obj->tiling_mode == I915_TILING_Y) {
DRM_DEBUG("hardware does not support tiling Y\n");
return -EINVAL;
}
if (mode_cmd->pitches[0] & 63) {
DRM_DEBUG("pitch (%d) must be at least 64 byte aligned\n",
mode_cmd->pitches[0]);
return -EINVAL;
}
if (INTEL_INFO(dev)->gen >= 5 && !IS_VALLEYVIEW(dev)) {
pitch_limit = 32*1024;
} else if (INTEL_INFO(dev)->gen >= 4) {
if (obj->tiling_mode)
pitch_limit = 16*1024;
else
pitch_limit = 32*1024;
} else if (INTEL_INFO(dev)->gen >= 3) {
if (obj->tiling_mode)
pitch_limit = 8*1024;
else
pitch_limit = 16*1024;
} else
pitch_limit = 8*1024;
if (mode_cmd->pitches[0] > pitch_limit) {
DRM_DEBUG("%s pitch (%d) must be at less than %d\n",
obj->tiling_mode ? "tiled" : "linear",
mode_cmd->pitches[0], pitch_limit);
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
DRM_DEBUG("unsupported pixel format: %s\n",
drm_get_format_name(mode_cmd->pixel_format));
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
DRM_DEBUG("unsupported pixel format: %s\n",
drm_get_format_name(mode_cmd->pixel_format));
return -EINVAL;
}
break;
case DRM_FORMAT_YUYV:
case DRM_FORMAT_UYVY:
case DRM_FORMAT_YVYU:
case DRM_FORMAT_VYUY:
if (INTEL_INFO(dev)->gen < 5) {
DRM_DEBUG("unsupported pixel format: %s\n",
drm_get_format_name(mode_cmd->pixel_format));
return -EINVAL;
}
break;
default:
DRM_DEBUG("unsupported pixel format: %s\n",
drm_get_format_name(mode_cmd->pixel_format));
return -EINVAL;
}
if (mode_cmd->offsets[0] != 0)
return -EINVAL;
aligned_height = intel_align_height(dev, mode_cmd->height,
obj->tiling_mode);
if (obj->base.size < aligned_height * mode_cmd->pitches[0])
return -EINVAL;
drm_helper_mode_fill_fb_struct(&intel_fb->base, mode_cmd);
intel_fb->obj = obj;
intel_fb->obj->framebuffer_references++;
ret = drm_framebuffer_init(dev, &intel_fb->base, &intel_fb_funcs);
if (ret) {
DRM_ERROR("framebuffer init failed %d\n", ret);
return ret;
}
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
static inline void intel_fbdev_output_poll_changed(struct drm_device *dev)
{
}
static void intel_init_display(struct drm_device *dev)
{
struct drm_i915_private *dev_priv = dev->dev_private;
if (HAS_PCH_SPLIT(dev) || IS_G4X(dev))
dev_priv->display.find_dpll = g4x_find_best_dpll;
else if (IS_VALLEYVIEW(dev))
dev_priv->display.find_dpll = vlv_find_best_dpll;
else if (IS_PINEVIEW(dev))
dev_priv->display.find_dpll = pnv_find_best_dpll;
else
dev_priv->display.find_dpll = i9xx_find_best_dpll;
if (HAS_DDI(dev)) {
dev_priv->display.get_pipe_config = haswell_get_pipe_config;
dev_priv->display.get_plane_config = ironlake_get_plane_config;
dev_priv->display.crtc_mode_set = haswell_crtc_mode_set;
dev_priv->display.crtc_enable = haswell_crtc_enable;
dev_priv->display.crtc_disable = haswell_crtc_disable;
dev_priv->display.off = haswell_crtc_off;
dev_priv->display.update_primary_plane =
ironlake_update_primary_plane;
} else if (HAS_PCH_SPLIT(dev)) {
dev_priv->display.get_pipe_config = ironlake_get_pipe_config;
dev_priv->display.get_plane_config = ironlake_get_plane_config;
dev_priv->display.crtc_mode_set = ironlake_crtc_mode_set;
dev_priv->display.crtc_enable = ironlake_crtc_enable;
dev_priv->display.crtc_disable = ironlake_crtc_disable;
dev_priv->display.off = ironlake_crtc_off;
dev_priv->display.update_primary_plane =
ironlake_update_primary_plane;
} else if (IS_VALLEYVIEW(dev)) {
dev_priv->display.get_pipe_config = i9xx_get_pipe_config;
dev_priv->display.get_plane_config = i9xx_get_plane_config;
dev_priv->display.crtc_mode_set = i9xx_crtc_mode_set;
dev_priv->display.crtc_enable = valleyview_crtc_enable;
dev_priv->display.crtc_disable = i9xx_crtc_disable;
dev_priv->display.off = i9xx_crtc_off;
dev_priv->display.update_primary_plane =
i9xx_update_primary_plane;
} else {
dev_priv->display.get_pipe_config = i9xx_get_pipe_config;
dev_priv->display.get_plane_config = i9xx_get_plane_config;
dev_priv->display.crtc_mode_set = i9xx_crtc_mode_set;
dev_priv->display.crtc_enable = i9xx_crtc_enable;
dev_priv->display.crtc_disable = i9xx_crtc_disable;
dev_priv->display.off = i9xx_crtc_off;
dev_priv->display.update_primary_plane =
i9xx_update_primary_plane;
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
else if (IS_I945GM(dev) || IS_845G(dev))
dev_priv->display.get_display_clock_speed =
i9xx_misc_get_display_clock_speed;
else if (IS_PINEVIEW(dev))
dev_priv->display.get_display_clock_speed =
pnv_get_display_clock_speed;
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
} else if (IS_HASWELL(dev) || IS_GEN8(dev)) {
dev_priv->display.fdi_link_train = hsw_fdi_link_train;
dev_priv->display.write_eld = haswell_write_eld;
dev_priv->display.modeset_global_resources =
haswell_modeset_global_resources;
}
} else if (IS_G4X(dev)) {
dev_priv->display.write_eld = g4x_write_eld;
} else if (IS_VALLEYVIEW(dev)) {
dev_priv->display.modeset_global_resources =
valleyview_modeset_global_resources;
dev_priv->display.write_eld = ironlake_write_eld;
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
case 8:
dev_priv->display.queue_flip = intel_gen7_queue_flip;
break;
}
intel_panel_init_backlight_funcs(dev);
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
u32 vga_reg = i915_vgacntrl_reg(dev);
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
intel_prepare_ddi(dev);
intel_init_clock_gating(dev);
intel_reset_dpio(dev);
mutex_lock(&dev->struct_mutex);
intel_enable_gt_powersave(dev);
mutex_unlock(&dev->struct_mutex);
}
void intel_modeset_suspend_hw(struct drm_device *dev)
{
intel_suspend_hw(dev);
}
void intel_modeset_init(struct drm_device *dev)
{
struct drm_i915_private *dev_priv = dev->dev_private;
int sprite, ret;
enum pipe pipe;
struct intel_crtc *crtc;
drm_mode_config_init(dev);
dev->mode_config.min_width = 0;
dev->mode_config.min_height = 0;
dev->mode_config.preferred_depth = 24;
dev->mode_config.prefer_shadow = 1;
dev->mode_config.funcs = &intel_mode_funcs;
intel_init_quirks(dev);
intel_init_pm(dev);
if (INTEL_INFO(dev)->num_pipes == 0)
return;
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
dev->mode_config.fb_base = dev_priv->gtt.mappable_base;
DRM_DEBUG_KMS("%d display pipe%s available.\n",
INTEL_INFO(dev)->num_pipes,
INTEL_INFO(dev)->num_pipes > 1 ? "s" : "");
for_each_pipe(pipe) {
intel_crtc_init(dev, pipe);
for_each_sprite(pipe, sprite) {
ret = intel_plane_init(dev, pipe, sprite);
if (ret)
DRM_DEBUG_KMS("pipe %c sprite %c init failed: %d\n",
pipe_name(pipe), sprite_name(pipe, sprite), ret);
}
}
intel_init_dpio(dev);
intel_reset_dpio(dev);
intel_cpu_pll_init(dev);
intel_shared_dpll_init(dev);
i915_disable_vga(dev);
intel_setup_outputs(dev);
intel_disable_fbc(dev);
mutex_lock(&dev->mode_config.mutex);
intel_modeset_setup_hw_state(dev, false);
mutex_unlock(&dev->mode_config.mutex);
list_for_each_entry(crtc, &dev->mode_config.crtc_list,
base.head) {
if (!crtc->active)
continue;
if (dev_priv->display.get_plane_config) {
dev_priv->display.get_plane_config(crtc,
&crtc->plane_config);
intel_find_plane_obj(crtc, &crtc->plane_config);
}
}
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
struct drm_device *dev = crtc->base.dev;
struct drm_i915_private *dev_priv = dev->dev_private;
u32 reg, val;
if (INTEL_INFO(dev)->num_pipes == 1)
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
reg = PIPECONF(crtc->config.cpu_transcoder);
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
connector->base.dpms = DRM_MODE_DPMS_OFF;
connector->base.encoder = NULL;
}
list_for_each_entry(connector, &dev->mode_config.connector_list,
base.head)
if (connector->encoder->base.crtc == &crtc->base) {
connector->encoder->base.crtc = NULL;
connector->encoder->connectors_active = false;
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
if (crtc->active) {
crtc->cpu_fifo_underrun_disabled = true;
crtc->pch_fifo_underrun_disabled = true;
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
encoder->base.crtc = NULL;
encoder->connectors_active = false;
list_for_each_entry(connector,
&dev->mode_config.connector_list,
base.head) {
if (connector->encoder != encoder)
continue;
connector->base.dpms = DRM_MODE_DPMS_OFF;
connector->base.encoder = NULL;
}
}
}
void i915_redisable_vga_power_on(struct drm_device *dev)
{
struct drm_i915_private *dev_priv = dev->dev_private;
u32 vga_reg = i915_vgacntrl_reg(dev);
if (!(I915_READ(vga_reg) & VGA_DISP_DISABLE)) {
DRM_DEBUG_KMS("Something enabled VGA plane, disabling it\n");
i915_disable_vga(dev);
}
}
void i915_redisable_vga(struct drm_device *dev)
{
struct drm_i915_private *dev_priv = dev->dev_private;
if (!intel_display_power_enabled(dev_priv, POWER_DOMAIN_VGA))
return;
i915_redisable_vga_power_on(dev);
}
static void intel_modeset_readout_hw_state(struct drm_device *dev)
{
struct drm_i915_private *dev_priv = dev->dev_private;
enum pipe pipe;
struct intel_crtc *crtc;
struct intel_encoder *encoder;
struct intel_connector *connector;
int i;
list_for_each_entry(crtc, &dev->mode_config.crtc_list,
base.head) {
memset(&crtc->config, 0, sizeof(crtc->config));
crtc->config.quirks |= PIPE_CONFIG_QUIRK_INHERITED_MODE;
crtc->active = dev_priv->display.get_pipe_config(crtc,
&crtc->config);
crtc->base.enabled = crtc->active;
crtc->primary_enabled = crtc->active;
DRM_DEBUG_KMS("[CRTC:%d] hw state readout: %s\n",
crtc->base.base.id,
crtc->active ? "enabled" : "disabled");
}
if (HAS_DDI(dev))
intel_ddi_setup_hw_pll_state(dev);
for (i = 0; i < dev_priv->num_shared_dpll; i++) {
struct intel_shared_dpll *pll = &dev_priv->shared_dplls[i];
pll->on = pll->get_hw_state(dev_priv, pll, &pll->hw_state);
pll->active = 0;
list_for_each_entry(crtc, &dev->mode_config.crtc_list,
base.head) {
if (crtc->active && intel_crtc_to_shared_dpll(crtc) == pll)
pll->active++;
}
pll->refcount = pll->active;
DRM_DEBUG_KMS("%s hw state readout: refcount %i, on %i\n",
pll->name, pll->refcount, pll->on);
}
list_for_each_entry(encoder, &dev->mode_config.encoder_list,
base.head) {
pipe = 0;
if (encoder->get_hw_state(encoder, &pipe)) {
crtc = to_intel_crtc(dev_priv->pipe_to_crtc_mapping[pipe]);
encoder->base.crtc = &crtc->base;
encoder->get_config(encoder, &crtc->config);
} else {
encoder->base.crtc = NULL;
}
encoder->connectors_active = false;
DRM_DEBUG_KMS("[ENCODER:%d:%s] hw state readout: %s, pipe %c\n",
encoder->base.base.id,
drm_get_encoder_name(&encoder->base),
encoder->base.crtc ? "enabled" : "disabled",
pipe_name(pipe));
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
}
void intel_modeset_setup_hw_state(struct drm_device *dev,
bool force_restore)
{
struct drm_i915_private *dev_priv = dev->dev_private;
enum pipe pipe;
struct intel_crtc *crtc;
struct intel_encoder *encoder;
int i;
intel_modeset_readout_hw_state(dev);
list_for_each_entry(crtc, &dev->mode_config.crtc_list,
base.head) {
if (crtc->active && i915.fastboot) {
intel_mode_from_pipe_config(&crtc->base.mode, &crtc->config);
DRM_DEBUG_KMS("[CRTC:%d] found active mode: ",
crtc->base.base.id);
drm_mode_debug_printmodeline(&crtc->base.mode);
}
}
list_for_each_entry(encoder, &dev->mode_config.encoder_list,
base.head) {
intel_sanitize_encoder(encoder);
}
for_each_pipe(pipe) {
crtc = to_intel_crtc(dev_priv->pipe_to_crtc_mapping[pipe]);
intel_sanitize_crtc(crtc);
intel_dump_pipe_config(crtc, &crtc->config, "[setup_hw_state]");
}
for (i = 0; i < dev_priv->num_shared_dpll; i++) {
struct intel_shared_dpll *pll = &dev_priv->shared_dplls[i];
if (!pll->on || pll->active)
continue;
DRM_DEBUG_KMS("%s enabled but not in use, disabling\n", pll->name);
pll->disable(dev_priv, pll);
pll->on = false;
}
if (HAS_PCH_SPLIT(dev))
ilk_wm_get_hw_state(dev);
if (force_restore) {
i915_redisable_vga(dev);
for_each_pipe(pipe) {
struct drm_crtc *crtc =
dev_priv->pipe_to_crtc_mapping[pipe];
__intel_set_mode(crtc, &crtc->mode, crtc->x, crtc->y,
crtc->primary->fb);
}
} else {
intel_modeset_update_staged_output_state(dev);
}
intel_modeset_check_state(dev);
}
void intel_modeset_gem_init(struct drm_device *dev)
{
struct drm_crtc *c;
struct intel_framebuffer *fb;
mutex_lock(&dev->struct_mutex);
intel_init_gt_powersave(dev);
mutex_unlock(&dev->struct_mutex);
intel_modeset_init_hw(dev);
intel_setup_overlay(dev);
mutex_lock(&dev->struct_mutex);
list_for_each_entry(c, &dev->mode_config.crtc_list, head) {
if (!c->primary->fb)
continue;
fb = to_intel_framebuffer(c->primary->fb);
if (intel_pin_and_fence_fb_obj(dev, fb->obj, NULL)) {
DRM_ERROR("failed to pin boot fb on pipe %d\n",
to_intel_crtc(c)->pipe);
drm_framebuffer_unreference(c->primary->fb);
c->primary->fb = NULL;
}
}
mutex_unlock(&dev->struct_mutex);
}
void intel_connector_unregister(struct intel_connector *intel_connector)
{
struct drm_connector *connector = &intel_connector->base;
intel_panel_destroy_backlight(connector);
drm_sysfs_connector_remove(connector);
}
void intel_modeset_cleanup(struct drm_device *dev)
{
struct drm_i915_private *dev_priv = dev->dev_private;
struct drm_crtc *crtc;
struct drm_connector *connector;
drm_irq_uninstall(dev);
cancel_work_sync(&dev_priv->hotplug_work);
drm_kms_helper_poll_fini(dev);
mutex_lock(&dev->struct_mutex);
intel_unregister_dsm_handler();
list_for_each_entry(crtc, &dev->mode_config.crtc_list, head) {
if (!crtc->primary->fb)
continue;
intel_increase_pllclock(crtc);
}
intel_disable_fbc(dev);
intel_disable_gt_powersave(dev);
ironlake_teardown_rc6(dev);
mutex_unlock(&dev->struct_mutex);
flush_scheduled_work();
list_for_each_entry(connector, &dev->mode_config.connector_list, head) {
struct intel_connector *intel_connector;
intel_connector = to_intel_connector(connector);
intel_connector->unregister(intel_connector);
}
drm_mode_config_cleanup(dev);
intel_cleanup_overlay(dev);
mutex_lock(&dev->struct_mutex);
intel_cleanup_gt_powersave(dev);
mutex_unlock(&dev->struct_mutex);
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
unsigned reg = INTEL_INFO(dev)->gen >= 6 ? SNB_GMCH_CTRL : INTEL_GMCH_CTRL;
u16 gmch_ctrl;
if (pci_read_config_word(dev_priv->bridge_dev, reg, &gmch_ctrl)) {
DRM_ERROR("failed to read control word\n");
return -EIO;
}
if (!!(gmch_ctrl & INTEL_GMCH_VGA_DISABLE) == !state)
return 0;
if (state)
gmch_ctrl &= ~INTEL_GMCH_VGA_DISABLE;
else
gmch_ctrl |= INTEL_GMCH_VGA_DISABLE;
if (pci_write_config_word(dev_priv->bridge_dev, reg, gmch_ctrl)) {
DRM_ERROR("failed to write control word\n");
return -EIO;
}
return 0;
}
struct intel_display_error_state *
intel_display_capture_error_state(struct drm_device *dev)
{
struct drm_i915_private *dev_priv = dev->dev_private;
struct intel_display_error_state *error;
int transcoders[] = {
TRANSCODER_A,
TRANSCODER_B,
TRANSCODER_C,
TRANSCODER_EDP,
};
int i;
if (INTEL_INFO(dev)->num_pipes == 0)
return NULL;
error = kzalloc(sizeof(*error), GFP_ATOMIC);
if (error == NULL)
return NULL;
if (IS_HASWELL(dev) || IS_BROADWELL(dev))
error->power_well_driver = I915_READ(HSW_PWR_WELL_DRIVER);
for_each_pipe(i) {
error->pipe[i].power_domain_on =
intel_display_power_enabled_sw(dev_priv,
POWER_DOMAIN_PIPE(i));
if (!error->pipe[i].power_domain_on)
continue;
if (INTEL_INFO(dev)->gen <= 6 || IS_VALLEYVIEW(dev)) {
error->cursor[i].control = I915_READ(CURCNTR(i));
error->cursor[i].position = I915_READ(CURPOS(i));
error->cursor[i].base = I915_READ(CURBASE(i));
} else {
error->cursor[i].control = I915_READ(CURCNTR_IVB(i));
error->cursor[i].position = I915_READ(CURPOS_IVB(i));
error->cursor[i].base = I915_READ(CURBASE_IVB(i));
}
error->plane[i].control = I915_READ(DSPCNTR(i));
error->plane[i].stride = I915_READ(DSPSTRIDE(i));
if (INTEL_INFO(dev)->gen <= 3) {
error->plane[i].size = I915_READ(DSPSIZE(i));
error->plane[i].pos = I915_READ(DSPPOS(i));
}
if (INTEL_INFO(dev)->gen <= 7 && !IS_HASWELL(dev))
error->plane[i].addr = I915_READ(DSPADDR(i));
if (INTEL_INFO(dev)->gen >= 4) {
error->plane[i].surface = I915_READ(DSPSURF(i));
error->plane[i].tile_offset = I915_READ(DSPTILEOFF(i));
}
error->pipe[i].source = I915_READ(PIPESRC(i));
}
error->num_transcoders = INTEL_INFO(dev)->num_pipes;
if (HAS_DDI(dev_priv->dev))
error->num_transcoders++;
for (i = 0; i < error->num_transcoders; i++) {
enum transcoder cpu_transcoder = transcoders[i];
error->transcoder[i].power_domain_on =
intel_display_power_enabled_sw(dev_priv,
POWER_DOMAIN_TRANSCODER(cpu_transcoder));
if (!error->transcoder[i].power_domain_on)
continue;
error->transcoder[i].cpu_transcoder = cpu_transcoder;
error->transcoder[i].conf = I915_READ(PIPECONF(cpu_transcoder));
error->transcoder[i].htotal = I915_READ(HTOTAL(cpu_transcoder));
error->transcoder[i].hblank = I915_READ(HBLANK(cpu_transcoder));
error->transcoder[i].hsync = I915_READ(HSYNC(cpu_transcoder));
error->transcoder[i].vtotal = I915_READ(VTOTAL(cpu_transcoder));
error->transcoder[i].vblank = I915_READ(VBLANK(cpu_transcoder));
error->transcoder[i].vsync = I915_READ(VSYNC(cpu_transcoder));
}
return error;
}
void
intel_display_print_error_state(struct drm_i915_error_state_buf *m,
struct drm_device *dev,
struct intel_display_error_state *error)
{
int i;
if (!error)
return;
err_printf(m, "Num Pipes: %d\n", INTEL_INFO(dev)->num_pipes);
if (IS_HASWELL(dev) || IS_BROADWELL(dev))
err_printf(m, "PWR_WELL_CTL2: %08x\n",
error->power_well_driver);
for_each_pipe(i) {
err_printf(m, "Pipe [%d]:\n", i);
err_printf(m, " Power: %s\n",
error->pipe[i].power_domain_on ? "on" : "off");
err_printf(m, " SRC: %08x\n", error->pipe[i].source);
err_printf(m, "Plane [%d]:\n", i);
err_printf(m, " CNTR: %08x\n", error->plane[i].control);
err_printf(m, " STRIDE: %08x\n", error->plane[i].stride);
if (INTEL_INFO(dev)->gen <= 3) {
err_printf(m, " SIZE: %08x\n", error->plane[i].size);
err_printf(m, " POS: %08x\n", error->plane[i].pos);
}
if (INTEL_INFO(dev)->gen <= 7 && !IS_HASWELL(dev))
err_printf(m, " ADDR: %08x\n", error->plane[i].addr);
if (INTEL_INFO(dev)->gen >= 4) {
err_printf(m, " SURF: %08x\n", error->plane[i].surface);
err_printf(m, " TILEOFF: %08x\n", error->plane[i].tile_offset);
}
err_printf(m, "Cursor [%d]:\n", i);
err_printf(m, " CNTR: %08x\n", error->cursor[i].control);
err_printf(m, " POS: %08x\n", error->cursor[i].position);
err_printf(m, " BASE: %08x\n", error->cursor[i].base);
}
for (i = 0; i < error->num_transcoders; i++) {
err_printf(m, "CPU transcoder: %c\n",
transcoder_name(error->transcoder[i].cpu_transcoder));
err_printf(m, " Power: %s\n",
error->transcoder[i].power_domain_on ? "on" : "off");
err_printf(m, " CONF: %08x\n", error->transcoder[i].conf);
err_printf(m, " HTOTAL: %08x\n", error->transcoder[i].htotal);
err_printf(m, " HBLANK: %08x\n", error->transcoder[i].hblank);
err_printf(m, " HSYNC: %08x\n", error->transcoder[i].hsync);
err_printf(m, " VTOTAL: %08x\n", error->transcoder[i].vtotal);
err_printf(m, " VBLANK: %08x\n", error->transcoder[i].vblank);
err_printf(m, " VSYNC: %08x\n", error->transcoder[i].vsync);
}
}
