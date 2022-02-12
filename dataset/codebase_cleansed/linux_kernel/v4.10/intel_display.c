static bool is_mmio_work(struct intel_flip_work *work)
{
return work->mmio_work.func;
}
static int valleyview_get_vco(struct drm_i915_private *dev_priv)
{
int hpll_freq, vco_freq[] = { 800, 1600, 2000, 2400 };
mutex_lock(&dev_priv->sb_lock);
hpll_freq = vlv_cck_read(dev_priv, CCK_FUSE_REG) &
CCK_FUSE_HPLL_FREQ_MASK;
mutex_unlock(&dev_priv->sb_lock);
return vco_freq[hpll_freq] * 1000;
}
int vlv_get_cck_clock(struct drm_i915_private *dev_priv,
const char *name, u32 reg, int ref_freq)
{
u32 val;
int divider;
mutex_lock(&dev_priv->sb_lock);
val = vlv_cck_read(dev_priv, reg);
mutex_unlock(&dev_priv->sb_lock);
divider = val & CCK_FREQUENCY_VALUES;
WARN((val & CCK_FREQUENCY_STATUS) !=
(divider << CCK_FREQUENCY_STATUS_SHIFT),
"%s change in progress\n", name);
return DIV_ROUND_CLOSEST(ref_freq << 1, divider + 1);
}
static int vlv_get_cck_clock_hpll(struct drm_i915_private *dev_priv,
const char *name, u32 reg)
{
if (dev_priv->hpll_freq == 0)
dev_priv->hpll_freq = valleyview_get_vco(dev_priv);
return vlv_get_cck_clock(dev_priv, name, reg,
dev_priv->hpll_freq);
}
static int
intel_pch_rawclk(struct drm_i915_private *dev_priv)
{
return (I915_READ(PCH_RAWCLK_FREQ) & RAWCLK_FREQ_MASK) * 1000;
}
static int
intel_vlv_hrawclk(struct drm_i915_private *dev_priv)
{
return vlv_get_cck_clock_hpll(dev_priv, "hrawclk",
CCK_DISPLAY_REF_CLOCK_CONTROL);
}
static int
intel_g4x_hrawclk(struct drm_i915_private *dev_priv)
{
uint32_t clkcfg;
clkcfg = I915_READ(CLKCFG);
switch (clkcfg & CLKCFG_FSB_MASK) {
case CLKCFG_FSB_400:
return 100000;
case CLKCFG_FSB_533:
return 133333;
case CLKCFG_FSB_667:
return 166667;
case CLKCFG_FSB_800:
return 200000;
case CLKCFG_FSB_1067:
return 266667;
case CLKCFG_FSB_1333:
return 333333;
case CLKCFG_FSB_1600:
case CLKCFG_FSB_1600_ALT:
return 400000;
default:
return 133333;
}
}
void intel_update_rawclk(struct drm_i915_private *dev_priv)
{
if (HAS_PCH_SPLIT(dev_priv))
dev_priv->rawclk_freq = intel_pch_rawclk(dev_priv);
else if (IS_VALLEYVIEW(dev_priv) || IS_CHERRYVIEW(dev_priv))
dev_priv->rawclk_freq = intel_vlv_hrawclk(dev_priv);
else if (IS_G4X(dev_priv) || IS_PINEVIEW(dev_priv))
dev_priv->rawclk_freq = intel_g4x_hrawclk(dev_priv);
else
return;
DRM_DEBUG_DRIVER("rawclk rate: %d kHz\n", dev_priv->rawclk_freq);
}
static void intel_update_czclk(struct drm_i915_private *dev_priv)
{
if (!(IS_VALLEYVIEW(dev_priv) || IS_CHERRYVIEW(dev_priv)))
return;
dev_priv->czclk_freq = vlv_get_cck_clock_hpll(dev_priv, "czclk",
CCK_CZ_CLOCK_CONTROL);
DRM_DEBUG_DRIVER("CZ clock rate: %d kHz\n", dev_priv->czclk_freq);
}
static inline u32
intel_fdi_link_freq(struct drm_i915_private *dev_priv,
const struct intel_crtc_state *pipe_config)
{
if (HAS_DDI(dev_priv))
return pipe_config->port_clock;
else if (IS_GEN5(dev_priv))
return ((I915_READ(FDI_PLL_BIOS_0) & FDI_PLL_FB_CLOCK_MASK) + 2) * 10000;
else
return 270000;
}
static bool
needs_modeset(struct drm_crtc_state *state)
{
return drm_atomic_crtc_needs_modeset(state);
}
static int pnv_calc_dpll_params(int refclk, struct dpll *clock)
{
clock->m = clock->m2 + 2;
clock->p = clock->p1 * clock->p2;
if (WARN_ON(clock->n == 0 || clock->p == 0))
return 0;
clock->vco = DIV_ROUND_CLOSEST(refclk * clock->m, clock->n);
clock->dot = DIV_ROUND_CLOSEST(clock->vco, clock->p);
return clock->dot;
}
static uint32_t i9xx_dpll_compute_m(struct dpll *dpll)
{
return 5 * (dpll->m1 + 2) + (dpll->m2 + 2);
}
static int i9xx_calc_dpll_params(int refclk, struct dpll *clock)
{
clock->m = i9xx_dpll_compute_m(clock);
clock->p = clock->p1 * clock->p2;
if (WARN_ON(clock->n + 2 == 0 || clock->p == 0))
return 0;
clock->vco = DIV_ROUND_CLOSEST(refclk * clock->m, clock->n + 2);
clock->dot = DIV_ROUND_CLOSEST(clock->vco, clock->p);
return clock->dot;
}
static int vlv_calc_dpll_params(int refclk, struct dpll *clock)
{
clock->m = clock->m1 * clock->m2;
clock->p = clock->p1 * clock->p2;
if (WARN_ON(clock->n == 0 || clock->p == 0))
return 0;
clock->vco = DIV_ROUND_CLOSEST(refclk * clock->m, clock->n);
clock->dot = DIV_ROUND_CLOSEST(clock->vco, clock->p);
return clock->dot / 5;
}
int chv_calc_dpll_params(int refclk, struct dpll *clock)
{
clock->m = clock->m1 * clock->m2;
clock->p = clock->p1 * clock->p2;
if (WARN_ON(clock->n == 0 || clock->p == 0))
return 0;
clock->vco = DIV_ROUND_CLOSEST_ULL((uint64_t)refclk * clock->m,
clock->n << 22);
clock->dot = DIV_ROUND_CLOSEST(clock->vco, clock->p);
return clock->dot / 5;
}
static bool intel_PLL_is_valid(struct drm_i915_private *dev_priv,
const struct intel_limit *limit,
const struct dpll *clock)
{
if (clock->n < limit->n.min || limit->n.max < clock->n)
INTELPllInvalid("n out of range\n");
if (clock->p1 < limit->p1.min || limit->p1.max < clock->p1)
INTELPllInvalid("p1 out of range\n");
if (clock->m2 < limit->m2.min || limit->m2.max < clock->m2)
INTELPllInvalid("m2 out of range\n");
if (clock->m1 < limit->m1.min || limit->m1.max < clock->m1)
INTELPllInvalid("m1 out of range\n");
if (!IS_PINEVIEW(dev_priv) && !IS_VALLEYVIEW(dev_priv) &&
!IS_CHERRYVIEW(dev_priv) && !IS_BROXTON(dev_priv))
if (clock->m1 <= clock->m2)
INTELPllInvalid("m1 <= m2\n");
if (!IS_VALLEYVIEW(dev_priv) && !IS_CHERRYVIEW(dev_priv) &&
!IS_BROXTON(dev_priv)) {
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
static int
i9xx_select_p2_div(const struct intel_limit *limit,
const struct intel_crtc_state *crtc_state,
int target)
{
struct drm_device *dev = crtc_state->base.crtc->dev;
if (intel_crtc_has_type(crtc_state, INTEL_OUTPUT_LVDS)) {
if (intel_is_dual_link_lvds(dev))
return limit->p2.p2_fast;
else
return limit->p2.p2_slow;
} else {
if (target < limit->p2.dot_limit)
return limit->p2.p2_slow;
else
return limit->p2.p2_fast;
}
}
static bool
i9xx_find_best_dpll(const struct intel_limit *limit,
struct intel_crtc_state *crtc_state,
int target, int refclk, struct dpll *match_clock,
struct dpll *best_clock)
{
struct drm_device *dev = crtc_state->base.crtc->dev;
struct dpll clock;
int err = target;
memset(best_clock, 0, sizeof(*best_clock));
clock.p2 = i9xx_select_p2_div(limit, crtc_state, target);
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
i9xx_calc_dpll_params(refclk, &clock);
if (!intel_PLL_is_valid(to_i915(dev),
limit,
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
pnv_find_best_dpll(const struct intel_limit *limit,
struct intel_crtc_state *crtc_state,
int target, int refclk, struct dpll *match_clock,
struct dpll *best_clock)
{
struct drm_device *dev = crtc_state->base.crtc->dev;
struct dpll clock;
int err = target;
memset(best_clock, 0, sizeof(*best_clock));
clock.p2 = i9xx_select_p2_div(limit, crtc_state, target);
for (clock.m1 = limit->m1.min; clock.m1 <= limit->m1.max;
clock.m1++) {
for (clock.m2 = limit->m2.min;
clock.m2 <= limit->m2.max; clock.m2++) {
for (clock.n = limit->n.min;
clock.n <= limit->n.max; clock.n++) {
for (clock.p1 = limit->p1.min;
clock.p1 <= limit->p1.max; clock.p1++) {
int this_err;
pnv_calc_dpll_params(refclk, &clock);
if (!intel_PLL_is_valid(to_i915(dev),
limit,
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
g4x_find_best_dpll(const struct intel_limit *limit,
struct intel_crtc_state *crtc_state,
int target, int refclk, struct dpll *match_clock,
struct dpll *best_clock)
{
struct drm_device *dev = crtc_state->base.crtc->dev;
struct dpll clock;
int max_n;
bool found = false;
int err_most = (target >> 8) + (target >> 9);
memset(best_clock, 0, sizeof(*best_clock));
clock.p2 = i9xx_select_p2_div(limit, crtc_state, target);
max_n = limit->n.max;
for (clock.n = limit->n.min; clock.n <= max_n; clock.n++) {
for (clock.m1 = limit->m1.max;
clock.m1 >= limit->m1.min; clock.m1--) {
for (clock.m2 = limit->m2.max;
clock.m2 >= limit->m2.min; clock.m2--) {
for (clock.p1 = limit->p1.max;
clock.p1 >= limit->p1.min; clock.p1--) {
int this_err;
i9xx_calc_dpll_params(refclk, &clock);
if (!intel_PLL_is_valid(to_i915(dev),
limit,
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
static bool vlv_PLL_is_optimal(struct drm_device *dev, int target_freq,
const struct dpll *calculated_clock,
const struct dpll *best_clock,
unsigned int best_error_ppm,
unsigned int *error_ppm)
{
if (IS_CHERRYVIEW(to_i915(dev))) {
*error_ppm = 0;
return calculated_clock->p > best_clock->p;
}
if (WARN_ON_ONCE(!target_freq))
return false;
*error_ppm = div_u64(1000000ULL *
abs(target_freq - calculated_clock->dot),
target_freq);
if (*error_ppm < 100 && calculated_clock->p > best_clock->p) {
*error_ppm = 0;
return true;
}
return *error_ppm + 10 < best_error_ppm;
}
static bool
vlv_find_best_dpll(const struct intel_limit *limit,
struct intel_crtc_state *crtc_state,
int target, int refclk, struct dpll *match_clock,
struct dpll *best_clock)
{
struct intel_crtc *crtc = to_intel_crtc(crtc_state->base.crtc);
struct drm_device *dev = crtc->base.dev;
struct dpll clock;
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
unsigned int ppm;
clock.m2 = DIV_ROUND_CLOSEST(target * clock.p * clock.n,
refclk * clock.m1);
vlv_calc_dpll_params(refclk, &clock);
if (!intel_PLL_is_valid(to_i915(dev),
limit,
&clock))
continue;
if (!vlv_PLL_is_optimal(dev, target,
&clock,
best_clock,
bestppm, &ppm))
continue;
*best_clock = clock;
bestppm = ppm;
found = true;
}
}
}
}
return found;
}
static bool
chv_find_best_dpll(const struct intel_limit *limit,
struct intel_crtc_state *crtc_state,
int target, int refclk, struct dpll *match_clock,
struct dpll *best_clock)
{
struct intel_crtc *crtc = to_intel_crtc(crtc_state->base.crtc);
struct drm_device *dev = crtc->base.dev;
unsigned int best_error_ppm;
struct dpll clock;
uint64_t m2;
int found = false;
memset(best_clock, 0, sizeof(*best_clock));
best_error_ppm = 1000000;
clock.n = 1, clock.m1 = 2;
target *= 5;
for (clock.p1 = limit->p1.max; clock.p1 >= limit->p1.min; clock.p1--) {
for (clock.p2 = limit->p2.p2_fast;
clock.p2 >= limit->p2.p2_slow;
clock.p2 -= clock.p2 > 10 ? 2 : 1) {
unsigned int error_ppm;
clock.p = clock.p1 * clock.p2;
m2 = DIV_ROUND_CLOSEST_ULL(((uint64_t)target * clock.p *
clock.n) << 22, refclk * clock.m1);
if (m2 > INT_MAX/clock.m1)
continue;
clock.m2 = m2;
chv_calc_dpll_params(refclk, &clock);
if (!intel_PLL_is_valid(to_i915(dev), limit, &clock))
continue;
if (!vlv_PLL_is_optimal(dev, target, &clock, best_clock,
best_error_ppm, &error_ppm))
continue;
*best_clock = clock;
best_error_ppm = error_ppm;
found = true;
}
}
return found;
}
bool bxt_find_best_dpll(struct intel_crtc_state *crtc_state, int target_clock,
struct dpll *best_clock)
{
int refclk = 100000;
const struct intel_limit *limit = &intel_limits_bxt;
return chv_find_best_dpll(limit, crtc_state,
target_clock, refclk, NULL, best_clock);
}
bool intel_crtc_active(struct intel_crtc *crtc)
{
return crtc->active && crtc->base.primary->state->fb &&
crtc->config->base.adjusted_mode.crtc_clock;
}
enum transcoder intel_pipe_to_cpu_transcoder(struct drm_i915_private *dev_priv,
enum pipe pipe)
{
struct intel_crtc *crtc = intel_get_crtc_for_pipe(dev_priv, pipe);
return crtc->config->cpu_transcoder;
}
static bool pipe_dsl_stopped(struct drm_i915_private *dev_priv, enum pipe pipe)
{
i915_reg_t reg = PIPEDSL(pipe);
u32 line1, line2;
u32 line_mask;
if (IS_GEN2(dev_priv))
line_mask = DSL_LINEMASK_GEN2;
else
line_mask = DSL_LINEMASK_GEN3;
line1 = I915_READ(reg) & line_mask;
msleep(5);
line2 = I915_READ(reg) & line_mask;
return line1 == line2;
}
static void intel_wait_for_pipe_off(struct intel_crtc *crtc)
{
struct drm_i915_private *dev_priv = to_i915(crtc->base.dev);
enum transcoder cpu_transcoder = crtc->config->cpu_transcoder;
enum pipe pipe = crtc->pipe;
if (INTEL_GEN(dev_priv) >= 4) {
i915_reg_t reg = PIPECONF(cpu_transcoder);
if (intel_wait_for_register(dev_priv,
reg, I965_PIPECONF_ACTIVE, 0,
100))
WARN(1, "pipe_off wait timed out\n");
} else {
if (wait_for(pipe_dsl_stopped(dev_priv, pipe), 100))
WARN(1, "pipe_off wait timed out\n");
}
}
void assert_pll(struct drm_i915_private *dev_priv,
enum pipe pipe, bool state)
{
u32 val;
bool cur_state;
val = I915_READ(DPLL(pipe));
cur_state = !!(val & DPLL_VCO_ENABLE);
I915_STATE_WARN(cur_state != state,
"PLL state assertion failure (expected %s, current %s)\n",
onoff(state), onoff(cur_state));
}
void assert_dsi_pll(struct drm_i915_private *dev_priv, bool state)
{
u32 val;
bool cur_state;
mutex_lock(&dev_priv->sb_lock);
val = vlv_cck_read(dev_priv, CCK_REG_DSI_PLL_CONTROL);
mutex_unlock(&dev_priv->sb_lock);
cur_state = val & DSI_PLL_VCO_EN;
I915_STATE_WARN(cur_state != state,
"DSI PLL state assertion failure (expected %s, current %s)\n",
onoff(state), onoff(cur_state));
}
static void assert_fdi_tx(struct drm_i915_private *dev_priv,
enum pipe pipe, bool state)
{
bool cur_state;
enum transcoder cpu_transcoder = intel_pipe_to_cpu_transcoder(dev_priv,
pipe);
if (HAS_DDI(dev_priv)) {
u32 val = I915_READ(TRANS_DDI_FUNC_CTL(cpu_transcoder));
cur_state = !!(val & TRANS_DDI_FUNC_ENABLE);
} else {
u32 val = I915_READ(FDI_TX_CTL(pipe));
cur_state = !!(val & FDI_TX_ENABLE);
}
I915_STATE_WARN(cur_state != state,
"FDI TX state assertion failure (expected %s, current %s)\n",
onoff(state), onoff(cur_state));
}
static void assert_fdi_rx(struct drm_i915_private *dev_priv,
enum pipe pipe, bool state)
{
u32 val;
bool cur_state;
val = I915_READ(FDI_RX_CTL(pipe));
cur_state = !!(val & FDI_RX_ENABLE);
I915_STATE_WARN(cur_state != state,
"FDI RX state assertion failure (expected %s, current %s)\n",
onoff(state), onoff(cur_state));
}
static void assert_fdi_tx_pll_enabled(struct drm_i915_private *dev_priv,
enum pipe pipe)
{
u32 val;
if (IS_GEN5(dev_priv))
return;
if (HAS_DDI(dev_priv))
return;
val = I915_READ(FDI_TX_CTL(pipe));
I915_STATE_WARN(!(val & FDI_TX_PLL_ENABLE), "FDI TX PLL assertion failure, should be active but is disabled\n");
}
void assert_fdi_rx_pll(struct drm_i915_private *dev_priv,
enum pipe pipe, bool state)
{
u32 val;
bool cur_state;
val = I915_READ(FDI_RX_CTL(pipe));
cur_state = !!(val & FDI_RX_PLL_ENABLE);
I915_STATE_WARN(cur_state != state,
"FDI RX PLL assertion failure (expected %s, current %s)\n",
onoff(state), onoff(cur_state));
}
void assert_panel_unlocked(struct drm_i915_private *dev_priv, enum pipe pipe)
{
i915_reg_t pp_reg;
u32 val;
enum pipe panel_pipe = PIPE_A;
bool locked = true;
if (WARN_ON(HAS_DDI(dev_priv)))
return;
if (HAS_PCH_SPLIT(dev_priv)) {
u32 port_sel;
pp_reg = PP_CONTROL(0);
port_sel = I915_READ(PP_ON_DELAYS(0)) & PANEL_PORT_SELECT_MASK;
if (port_sel == PANEL_PORT_SELECT_LVDS &&
I915_READ(PCH_LVDS) & LVDS_PIPEB_SELECT)
panel_pipe = PIPE_B;
} else if (IS_VALLEYVIEW(dev_priv) || IS_CHERRYVIEW(dev_priv)) {
pp_reg = PP_CONTROL(pipe);
panel_pipe = pipe;
} else {
pp_reg = PP_CONTROL(0);
if (I915_READ(LVDS) & LVDS_PIPEB_SELECT)
panel_pipe = PIPE_B;
}
val = I915_READ(pp_reg);
if (!(val & PANEL_POWER_ON) ||
((val & PANEL_UNLOCK_MASK) == PANEL_UNLOCK_REGS))
locked = false;
I915_STATE_WARN(panel_pipe == pipe && locked,
"panel assertion failure, pipe %c regs locked\n",
pipe_name(pipe));
}
static void assert_cursor(struct drm_i915_private *dev_priv,
enum pipe pipe, bool state)
{
bool cur_state;
if (IS_845G(dev_priv) || IS_I865G(dev_priv))
cur_state = I915_READ(CURCNTR(PIPE_A)) & CURSOR_ENABLE;
else
cur_state = I915_READ(CURCNTR(pipe)) & CURSOR_MODE;
I915_STATE_WARN(cur_state != state,
"cursor on pipe %c assertion failure (expected %s, current %s)\n",
pipe_name(pipe), onoff(state), onoff(cur_state));
}
void assert_pipe(struct drm_i915_private *dev_priv,
enum pipe pipe, bool state)
{
bool cur_state;
enum transcoder cpu_transcoder = intel_pipe_to_cpu_transcoder(dev_priv,
pipe);
enum intel_display_power_domain power_domain;
if ((pipe == PIPE_A && dev_priv->quirks & QUIRK_PIPEA_FORCE) ||
(pipe == PIPE_B && dev_priv->quirks & QUIRK_PIPEB_FORCE))
state = true;
power_domain = POWER_DOMAIN_TRANSCODER(cpu_transcoder);
if (intel_display_power_get_if_enabled(dev_priv, power_domain)) {
u32 val = I915_READ(PIPECONF(cpu_transcoder));
cur_state = !!(val & PIPECONF_ENABLE);
intel_display_power_put(dev_priv, power_domain);
} else {
cur_state = false;
}
I915_STATE_WARN(cur_state != state,
"pipe %c assertion failure (expected %s, current %s)\n",
pipe_name(pipe), onoff(state), onoff(cur_state));
}
static void assert_plane(struct drm_i915_private *dev_priv,
enum plane plane, bool state)
{
u32 val;
bool cur_state;
val = I915_READ(DSPCNTR(plane));
cur_state = !!(val & DISPLAY_PLANE_ENABLE);
I915_STATE_WARN(cur_state != state,
"plane %c assertion failure (expected %s, current %s)\n",
plane_name(plane), onoff(state), onoff(cur_state));
}
static void assert_planes_disabled(struct drm_i915_private *dev_priv,
enum pipe pipe)
{
int i;
if (INTEL_GEN(dev_priv) >= 4) {
u32 val = I915_READ(DSPCNTR(pipe));
I915_STATE_WARN(val & DISPLAY_PLANE_ENABLE,
"plane %c assertion failure, should be disabled but not\n",
plane_name(pipe));
return;
}
for_each_pipe(dev_priv, i) {
u32 val = I915_READ(DSPCNTR(i));
enum pipe cur_pipe = (val & DISPPLANE_SEL_PIPE_MASK) >>
DISPPLANE_SEL_PIPE_SHIFT;
I915_STATE_WARN((val & DISPLAY_PLANE_ENABLE) && pipe == cur_pipe,
"plane %c assertion failure, should be off on pipe %c but is still active\n",
plane_name(i), pipe_name(pipe));
}
}
static void assert_sprites_disabled(struct drm_i915_private *dev_priv,
enum pipe pipe)
{
int sprite;
if (INTEL_GEN(dev_priv) >= 9) {
for_each_sprite(dev_priv, pipe, sprite) {
u32 val = I915_READ(PLANE_CTL(pipe, sprite));
I915_STATE_WARN(val & PLANE_CTL_ENABLE,
"plane %d assertion failure, should be off on pipe %c but is still active\n",
sprite, pipe_name(pipe));
}
} else if (IS_VALLEYVIEW(dev_priv) || IS_CHERRYVIEW(dev_priv)) {
for_each_sprite(dev_priv, pipe, sprite) {
u32 val = I915_READ(SPCNTR(pipe, sprite));
I915_STATE_WARN(val & SP_ENABLE,
"sprite %c assertion failure, should be off on pipe %c but is still active\n",
sprite_name(pipe, sprite), pipe_name(pipe));
}
} else if (INTEL_GEN(dev_priv) >= 7) {
u32 val = I915_READ(SPRCTL(pipe));
I915_STATE_WARN(val & SPRITE_ENABLE,
"sprite %c assertion failure, should be off on pipe %c but is still active\n",
plane_name(pipe), pipe_name(pipe));
} else if (INTEL_GEN(dev_priv) >= 5) {
u32 val = I915_READ(DVSCNTR(pipe));
I915_STATE_WARN(val & DVS_ENABLE,
"sprite %c assertion failure, should be off on pipe %c but is still active\n",
plane_name(pipe), pipe_name(pipe));
}
}
static void assert_vblank_disabled(struct drm_crtc *crtc)
{
if (I915_STATE_WARN_ON(drm_crtc_vblank_get(crtc) == 0))
drm_crtc_vblank_put(crtc);
}
void assert_pch_transcoder_disabled(struct drm_i915_private *dev_priv,
enum pipe pipe)
{
u32 val;
bool enabled;
val = I915_READ(PCH_TRANSCONF(pipe));
enabled = !!(val & TRANS_ENABLE);
I915_STATE_WARN(enabled,
"transcoder assertion failed, should be off on pipe %c but is still active\n",
pipe_name(pipe));
}
static bool dp_pipe_enabled(struct drm_i915_private *dev_priv,
enum pipe pipe, u32 port_sel, u32 val)
{
if ((val & DP_PORT_EN) == 0)
return false;
if (HAS_PCH_CPT(dev_priv)) {
u32 trans_dp_ctl = I915_READ(TRANS_DP_CTL(pipe));
if ((trans_dp_ctl & TRANS_DP_PORT_SEL_MASK) != port_sel)
return false;
} else if (IS_CHERRYVIEW(dev_priv)) {
if ((val & DP_PIPE_MASK_CHV) != DP_PIPE_SELECT_CHV(pipe))
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
if (HAS_PCH_CPT(dev_priv)) {
if ((val & SDVO_PIPE_SEL_MASK_CPT) != SDVO_PIPE_SEL_CPT(pipe))
return false;
} else if (IS_CHERRYVIEW(dev_priv)) {
if ((val & SDVO_PIPE_SEL_MASK_CHV) != SDVO_PIPE_SEL_CHV(pipe))
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
if (HAS_PCH_CPT(dev_priv)) {
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
if (HAS_PCH_CPT(dev_priv)) {
if ((val & PORT_TRANS_SEL_MASK) != PORT_TRANS_SEL_CPT(pipe))
return false;
} else {
if ((val & ADPA_PIPE_SELECT_MASK) != ADPA_PIPE_SELECT(pipe))
return false;
}
return true;
}
static void assert_pch_dp_disabled(struct drm_i915_private *dev_priv,
enum pipe pipe, i915_reg_t reg,
u32 port_sel)
{
u32 val = I915_READ(reg);
I915_STATE_WARN(dp_pipe_enabled(dev_priv, pipe, port_sel, val),
"PCH DP (0x%08x) enabled on transcoder %c, should be disabled\n",
i915_mmio_reg_offset(reg), pipe_name(pipe));
I915_STATE_WARN(HAS_PCH_IBX(dev_priv) && (val & DP_PORT_EN) == 0
&& (val & DP_PIPEB_SELECT),
"IBX PCH dp port still using transcoder B\n");
}
static void assert_pch_hdmi_disabled(struct drm_i915_private *dev_priv,
enum pipe pipe, i915_reg_t reg)
{
u32 val = I915_READ(reg);
I915_STATE_WARN(hdmi_pipe_enabled(dev_priv, pipe, val),
"PCH HDMI (0x%08x) enabled on transcoder %c, should be disabled\n",
i915_mmio_reg_offset(reg), pipe_name(pipe));
I915_STATE_WARN(HAS_PCH_IBX(dev_priv) && (val & SDVO_ENABLE) == 0
&& (val & SDVO_PIPE_B_SELECT),
"IBX PCH hdmi port still using transcoder B\n");
}
static void assert_pch_ports_disabled(struct drm_i915_private *dev_priv,
enum pipe pipe)
{
u32 val;
assert_pch_dp_disabled(dev_priv, pipe, PCH_DP_B, TRANS_DP_PORT_SEL_B);
assert_pch_dp_disabled(dev_priv, pipe, PCH_DP_C, TRANS_DP_PORT_SEL_C);
assert_pch_dp_disabled(dev_priv, pipe, PCH_DP_D, TRANS_DP_PORT_SEL_D);
val = I915_READ(PCH_ADPA);
I915_STATE_WARN(adpa_pipe_enabled(dev_priv, pipe, val),
"PCH VGA enabled on transcoder %c, should be disabled\n",
pipe_name(pipe));
val = I915_READ(PCH_LVDS);
I915_STATE_WARN(lvds_pipe_enabled(dev_priv, pipe, val),
"PCH LVDS enabled on transcoder %c, should be disabled\n",
pipe_name(pipe));
assert_pch_hdmi_disabled(dev_priv, pipe, PCH_HDMIB);
assert_pch_hdmi_disabled(dev_priv, pipe, PCH_HDMIC);
assert_pch_hdmi_disabled(dev_priv, pipe, PCH_HDMID);
}
static void _vlv_enable_pll(struct intel_crtc *crtc,
const struct intel_crtc_state *pipe_config)
{
struct drm_i915_private *dev_priv = to_i915(crtc->base.dev);
enum pipe pipe = crtc->pipe;
I915_WRITE(DPLL(pipe), pipe_config->dpll_hw_state.dpll);
POSTING_READ(DPLL(pipe));
udelay(150);
if (intel_wait_for_register(dev_priv,
DPLL(pipe),
DPLL_LOCK_VLV,
DPLL_LOCK_VLV,
1))
DRM_ERROR("DPLL %d failed to lock\n", pipe);
}
static void vlv_enable_pll(struct intel_crtc *crtc,
const struct intel_crtc_state *pipe_config)
{
struct drm_i915_private *dev_priv = to_i915(crtc->base.dev);
enum pipe pipe = crtc->pipe;
assert_pipe_disabled(dev_priv, pipe);
assert_panel_unlocked(dev_priv, pipe);
if (pipe_config->dpll_hw_state.dpll & DPLL_VCO_ENABLE)
_vlv_enable_pll(crtc, pipe_config);
I915_WRITE(DPLL_MD(pipe), pipe_config->dpll_hw_state.dpll_md);
POSTING_READ(DPLL_MD(pipe));
}
static void _chv_enable_pll(struct intel_crtc *crtc,
const struct intel_crtc_state *pipe_config)
{
struct drm_i915_private *dev_priv = to_i915(crtc->base.dev);
enum pipe pipe = crtc->pipe;
enum dpio_channel port = vlv_pipe_to_channel(pipe);
u32 tmp;
mutex_lock(&dev_priv->sb_lock);
tmp = vlv_dpio_read(dev_priv, pipe, CHV_CMN_DW14(port));
tmp |= DPIO_DCLKP_EN;
vlv_dpio_write(dev_priv, pipe, CHV_CMN_DW14(port), tmp);
mutex_unlock(&dev_priv->sb_lock);
udelay(1);
I915_WRITE(DPLL(pipe), pipe_config->dpll_hw_state.dpll);
if (intel_wait_for_register(dev_priv,
DPLL(pipe), DPLL_LOCK_VLV, DPLL_LOCK_VLV,
1))
DRM_ERROR("PLL %d failed to lock\n", pipe);
}
static void chv_enable_pll(struct intel_crtc *crtc,
const struct intel_crtc_state *pipe_config)
{
struct drm_i915_private *dev_priv = to_i915(crtc->base.dev);
enum pipe pipe = crtc->pipe;
assert_pipe_disabled(dev_priv, pipe);
assert_panel_unlocked(dev_priv, pipe);
if (pipe_config->dpll_hw_state.dpll & DPLL_VCO_ENABLE)
_chv_enable_pll(crtc, pipe_config);
if (pipe != PIPE_A) {
I915_WRITE(CBR4_VLV, pipe == PIPE_B ? CBR_DPLLBMD_PIPE_B : CBR_DPLLBMD_PIPE_C);
I915_WRITE(DPLL_MD(PIPE_B), pipe_config->dpll_hw_state.dpll_md);
I915_WRITE(CBR4_VLV, 0);
dev_priv->chv_dpll_md[pipe] = pipe_config->dpll_hw_state.dpll_md;
WARN_ON((I915_READ(DPLL(PIPE_B)) & DPLL_VGA_MODE_DIS) == 0);
} else {
I915_WRITE(DPLL_MD(pipe), pipe_config->dpll_hw_state.dpll_md);
POSTING_READ(DPLL_MD(pipe));
}
}
static int intel_num_dvo_pipes(struct drm_i915_private *dev_priv)
{
struct intel_crtc *crtc;
int count = 0;
for_each_intel_crtc(&dev_priv->drm, crtc) {
count += crtc->base.state->active &&
intel_crtc_has_type(crtc->config, INTEL_OUTPUT_DVO);
}
return count;
}
static void i9xx_enable_pll(struct intel_crtc *crtc)
{
struct drm_i915_private *dev_priv = to_i915(crtc->base.dev);
i915_reg_t reg = DPLL(crtc->pipe);
u32 dpll = crtc->config->dpll_hw_state.dpll;
assert_pipe_disabled(dev_priv, crtc->pipe);
if (IS_MOBILE(dev_priv) && !IS_I830(dev_priv))
assert_panel_unlocked(dev_priv, crtc->pipe);
if (IS_I830(dev_priv) && intel_num_dvo_pipes(dev_priv) > 0) {
dpll |= DPLL_DVO_2X_MODE;
I915_WRITE(DPLL(!crtc->pipe),
I915_READ(DPLL(!crtc->pipe)) | DPLL_DVO_2X_MODE);
}
I915_WRITE(reg, 0);
I915_WRITE(reg, dpll);
POSTING_READ(reg);
udelay(150);
if (INTEL_GEN(dev_priv) >= 4) {
I915_WRITE(DPLL_MD(crtc->pipe),
crtc->config->dpll_hw_state.dpll_md);
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
static void i9xx_disable_pll(struct intel_crtc *crtc)
{
struct drm_i915_private *dev_priv = to_i915(crtc->base.dev);
enum pipe pipe = crtc->pipe;
if (IS_I830(dev_priv) &&
intel_crtc_has_type(crtc->config, INTEL_OUTPUT_DVO) &&
!intel_num_dvo_pipes(dev_priv)) {
I915_WRITE(DPLL(PIPE_B),
I915_READ(DPLL(PIPE_B)) & ~DPLL_DVO_2X_MODE);
I915_WRITE(DPLL(PIPE_A),
I915_READ(DPLL(PIPE_A)) & ~DPLL_DVO_2X_MODE);
}
if ((pipe == PIPE_A && dev_priv->quirks & QUIRK_PIPEA_FORCE) ||
(pipe == PIPE_B && dev_priv->quirks & QUIRK_PIPEB_FORCE))
return;
assert_pipe_disabled(dev_priv, pipe);
I915_WRITE(DPLL(pipe), DPLL_VGA_MODE_DIS);
POSTING_READ(DPLL(pipe));
}
static void vlv_disable_pll(struct drm_i915_private *dev_priv, enum pipe pipe)
{
u32 val;
assert_pipe_disabled(dev_priv, pipe);
val = DPLL_INTEGRATED_REF_CLK_VLV |
DPLL_REF_CLK_ENABLE_VLV | DPLL_VGA_MODE_DIS;
if (pipe != PIPE_A)
val |= DPLL_INTEGRATED_CRI_CLK_VLV;
I915_WRITE(DPLL(pipe), val);
POSTING_READ(DPLL(pipe));
}
static void chv_disable_pll(struct drm_i915_private *dev_priv, enum pipe pipe)
{
enum dpio_channel port = vlv_pipe_to_channel(pipe);
u32 val;
assert_pipe_disabled(dev_priv, pipe);
val = DPLL_SSC_REF_CLK_CHV |
DPLL_REF_CLK_ENABLE_VLV | DPLL_VGA_MODE_DIS;
if (pipe != PIPE_A)
val |= DPLL_INTEGRATED_CRI_CLK_VLV;
I915_WRITE(DPLL(pipe), val);
POSTING_READ(DPLL(pipe));
mutex_lock(&dev_priv->sb_lock);
val = vlv_dpio_read(dev_priv, pipe, CHV_CMN_DW14(port));
val &= ~DPIO_DCLKP_EN;
vlv_dpio_write(dev_priv, pipe, CHV_CMN_DW14(port), val);
mutex_unlock(&dev_priv->sb_lock);
}
void vlv_wait_port_ready(struct drm_i915_private *dev_priv,
struct intel_digital_port *dport,
unsigned int expected_mask)
{
u32 port_mask;
i915_reg_t dpll_reg;
switch (dport->port) {
case PORT_B:
port_mask = DPLL_PORTB_READY_MASK;
dpll_reg = DPLL(0);
break;
case PORT_C:
port_mask = DPLL_PORTC_READY_MASK;
dpll_reg = DPLL(0);
expected_mask <<= 4;
break;
case PORT_D:
port_mask = DPLL_PORTD_READY_MASK;
dpll_reg = DPIO_PHY_STATUS;
break;
default:
BUG();
}
if (intel_wait_for_register(dev_priv,
dpll_reg, port_mask, expected_mask,
1000))
WARN(1, "timed out waiting for port %c ready: got 0x%x, expected 0x%x\n",
port_name(dport->port), I915_READ(dpll_reg) & port_mask, expected_mask);
}
static void ironlake_enable_pch_transcoder(struct drm_i915_private *dev_priv,
enum pipe pipe)
{
struct intel_crtc *intel_crtc = intel_get_crtc_for_pipe(dev_priv,
pipe);
i915_reg_t reg;
uint32_t val, pipeconf_val;
assert_shared_dpll_enabled(dev_priv, intel_crtc->config->shared_dpll);
assert_fdi_tx_enabled(dev_priv, pipe);
assert_fdi_rx_enabled(dev_priv, pipe);
if (HAS_PCH_CPT(dev_priv)) {
reg = TRANS_CHICKEN2(pipe);
val = I915_READ(reg);
val |= TRANS_CHICKEN2_TIMING_OVERRIDE;
I915_WRITE(reg, val);
}
reg = PCH_TRANSCONF(pipe);
val = I915_READ(reg);
pipeconf_val = I915_READ(PIPECONF(pipe));
if (HAS_PCH_IBX(dev_priv)) {
val &= ~PIPECONF_BPC_MASK;
if (intel_crtc_has_type(intel_crtc->config, INTEL_OUTPUT_HDMI))
val |= PIPECONF_8BPC;
else
val |= pipeconf_val & PIPECONF_BPC_MASK;
}
val &= ~TRANS_INTERLACE_MASK;
if ((pipeconf_val & PIPECONF_INTERLACE_MASK) == PIPECONF_INTERLACED_ILK)
if (HAS_PCH_IBX(dev_priv) &&
intel_crtc_has_type(intel_crtc->config, INTEL_OUTPUT_SDVO))
val |= TRANS_LEGACY_INTERLACED_ILK;
else
val |= TRANS_INTERLACED;
else
val |= TRANS_PROGRESSIVE;
I915_WRITE(reg, val | TRANS_ENABLE);
if (intel_wait_for_register(dev_priv,
reg, TRANS_STATE_ENABLE, TRANS_STATE_ENABLE,
100))
DRM_ERROR("failed to enable transcoder %c\n", pipe_name(pipe));
}
static void lpt_enable_pch_transcoder(struct drm_i915_private *dev_priv,
enum transcoder cpu_transcoder)
{
u32 val, pipeconf_val;
assert_fdi_tx_enabled(dev_priv, (enum pipe) cpu_transcoder);
assert_fdi_rx_enabled(dev_priv, TRANSCODER_A);
val = I915_READ(TRANS_CHICKEN2(PIPE_A));
val |= TRANS_CHICKEN2_TIMING_OVERRIDE;
I915_WRITE(TRANS_CHICKEN2(PIPE_A), val);
val = TRANS_ENABLE;
pipeconf_val = I915_READ(PIPECONF(cpu_transcoder));
if ((pipeconf_val & PIPECONF_INTERLACE_MASK_HSW) ==
PIPECONF_INTERLACED_ILK)
val |= TRANS_INTERLACED;
else
val |= TRANS_PROGRESSIVE;
I915_WRITE(LPT_TRANSCONF, val);
if (intel_wait_for_register(dev_priv,
LPT_TRANSCONF,
TRANS_STATE_ENABLE,
TRANS_STATE_ENABLE,
100))
DRM_ERROR("Failed to enable PCH transcoder\n");
}
static void ironlake_disable_pch_transcoder(struct drm_i915_private *dev_priv,
enum pipe pipe)
{
i915_reg_t reg;
uint32_t val;
assert_fdi_tx_disabled(dev_priv, pipe);
assert_fdi_rx_disabled(dev_priv, pipe);
assert_pch_ports_disabled(dev_priv, pipe);
reg = PCH_TRANSCONF(pipe);
val = I915_READ(reg);
val &= ~TRANS_ENABLE;
I915_WRITE(reg, val);
if (intel_wait_for_register(dev_priv,
reg, TRANS_STATE_ENABLE, 0,
50))
DRM_ERROR("failed to disable transcoder %c\n", pipe_name(pipe));
if (HAS_PCH_CPT(dev_priv)) {
reg = TRANS_CHICKEN2(pipe);
val = I915_READ(reg);
val &= ~TRANS_CHICKEN2_TIMING_OVERRIDE;
I915_WRITE(reg, val);
}
}
void lpt_disable_pch_transcoder(struct drm_i915_private *dev_priv)
{
u32 val;
val = I915_READ(LPT_TRANSCONF);
val &= ~TRANS_ENABLE;
I915_WRITE(LPT_TRANSCONF, val);
if (intel_wait_for_register(dev_priv,
LPT_TRANSCONF, TRANS_STATE_ENABLE, 0,
50))
DRM_ERROR("Failed to disable PCH transcoder\n");
val = I915_READ(TRANS_CHICKEN2(PIPE_A));
val &= ~TRANS_CHICKEN2_TIMING_OVERRIDE;
I915_WRITE(TRANS_CHICKEN2(PIPE_A), val);
}
enum transcoder intel_crtc_pch_transcoder(struct intel_crtc *crtc)
{
struct drm_i915_private *dev_priv = to_i915(crtc->base.dev);
WARN_ON(!crtc->config->has_pch_encoder);
if (HAS_PCH_LPT(dev_priv))
return TRANSCODER_A;
else
return (enum transcoder) crtc->pipe;
}
static void intel_enable_pipe(struct intel_crtc *crtc)
{
struct drm_device *dev = crtc->base.dev;
struct drm_i915_private *dev_priv = to_i915(dev);
enum pipe pipe = crtc->pipe;
enum transcoder cpu_transcoder = crtc->config->cpu_transcoder;
i915_reg_t reg;
u32 val;
DRM_DEBUG_KMS("enabling pipe %c\n", pipe_name(pipe));
assert_planes_disabled(dev_priv, pipe);
assert_cursor_disabled(dev_priv, pipe);
assert_sprites_disabled(dev_priv, pipe);
if (HAS_GMCH_DISPLAY(dev_priv)) {
if (intel_crtc_has_type(crtc->config, INTEL_OUTPUT_DSI))
assert_dsi_pll_enabled(dev_priv);
else
assert_pll_enabled(dev_priv, pipe);
} else {
if (crtc->config->has_pch_encoder) {
assert_fdi_rx_pll_enabled(dev_priv,
(enum pipe) intel_crtc_pch_transcoder(crtc));
assert_fdi_tx_pll_enabled(dev_priv,
(enum pipe) cpu_transcoder);
}
}
reg = PIPECONF(cpu_transcoder);
val = I915_READ(reg);
if (val & PIPECONF_ENABLE) {
WARN_ON(!((pipe == PIPE_A && dev_priv->quirks & QUIRK_PIPEA_FORCE) ||
(pipe == PIPE_B && dev_priv->quirks & QUIRK_PIPEB_FORCE)));
return;
}
I915_WRITE(reg, val | PIPECONF_ENABLE);
POSTING_READ(reg);
if (dev->max_vblank_count == 0 &&
wait_for(intel_get_crtc_scanline(crtc) != crtc->scanline_offset, 50))
DRM_ERROR("pipe %c didn't start\n", pipe_name(pipe));
}
static void intel_disable_pipe(struct intel_crtc *crtc)
{
struct drm_i915_private *dev_priv = to_i915(crtc->base.dev);
enum transcoder cpu_transcoder = crtc->config->cpu_transcoder;
enum pipe pipe = crtc->pipe;
i915_reg_t reg;
u32 val;
DRM_DEBUG_KMS("disabling pipe %c\n", pipe_name(pipe));
assert_planes_disabled(dev_priv, pipe);
assert_cursor_disabled(dev_priv, pipe);
assert_sprites_disabled(dev_priv, pipe);
reg = PIPECONF(cpu_transcoder);
val = I915_READ(reg);
if ((val & PIPECONF_ENABLE) == 0)
return;
if (crtc->config->double_wide)
val &= ~PIPECONF_DOUBLE_WIDE;
if (!(pipe == PIPE_A && dev_priv->quirks & QUIRK_PIPEA_FORCE) &&
!(pipe == PIPE_B && dev_priv->quirks & QUIRK_PIPEB_FORCE))
val &= ~PIPECONF_ENABLE;
I915_WRITE(reg, val);
if ((val & PIPECONF_ENABLE) == 0)
intel_wait_for_pipe_off(crtc);
}
static unsigned int intel_tile_size(const struct drm_i915_private *dev_priv)
{
return IS_GEN2(dev_priv) ? 2048 : 4096;
}
static unsigned int intel_tile_width_bytes(const struct drm_i915_private *dev_priv,
uint64_t fb_modifier, unsigned int cpp)
{
switch (fb_modifier) {
case DRM_FORMAT_MOD_NONE:
return cpp;
case I915_FORMAT_MOD_X_TILED:
if (IS_GEN2(dev_priv))
return 128;
else
return 512;
case I915_FORMAT_MOD_Y_TILED:
if (IS_GEN2(dev_priv) || HAS_128_BYTE_Y_TILING(dev_priv))
return 128;
else
return 512;
case I915_FORMAT_MOD_Yf_TILED:
switch (cpp) {
case 1:
return 64;
case 2:
case 4:
return 128;
case 8:
case 16:
return 256;
default:
MISSING_CASE(cpp);
return cpp;
}
break;
default:
MISSING_CASE(fb_modifier);
return cpp;
}
}
unsigned int intel_tile_height(const struct drm_i915_private *dev_priv,
uint64_t fb_modifier, unsigned int cpp)
{
if (fb_modifier == DRM_FORMAT_MOD_NONE)
return 1;
else
return intel_tile_size(dev_priv) /
intel_tile_width_bytes(dev_priv, fb_modifier, cpp);
}
static void intel_tile_dims(const struct drm_i915_private *dev_priv,
unsigned int *tile_width,
unsigned int *tile_height,
uint64_t fb_modifier,
unsigned int cpp)
{
unsigned int tile_width_bytes =
intel_tile_width_bytes(dev_priv, fb_modifier, cpp);
*tile_width = tile_width_bytes / cpp;
*tile_height = intel_tile_size(dev_priv) / tile_width_bytes;
}
unsigned int
intel_fb_align_height(struct drm_device *dev, unsigned int height,
uint32_t pixel_format, uint64_t fb_modifier)
{
unsigned int cpp = drm_format_plane_cpp(pixel_format, 0);
unsigned int tile_height = intel_tile_height(to_i915(dev), fb_modifier, cpp);
return ALIGN(height, tile_height);
}
unsigned int intel_rotation_info_size(const struct intel_rotation_info *rot_info)
{
unsigned int size = 0;
int i;
for (i = 0 ; i < ARRAY_SIZE(rot_info->plane); i++)
size += rot_info->plane[i].width * rot_info->plane[i].height;
return size;
}
static void
intel_fill_fb_ggtt_view(struct i915_ggtt_view *view,
const struct drm_framebuffer *fb,
unsigned int rotation)
{
if (drm_rotation_90_or_270(rotation)) {
*view = i915_ggtt_view_rotated;
view->params.rotated = to_intel_framebuffer(fb)->rot_info;
} else {
*view = i915_ggtt_view_normal;
}
}
static unsigned int intel_linear_alignment(const struct drm_i915_private *dev_priv)
{
if (INTEL_INFO(dev_priv)->gen >= 9)
return 256 * 1024;
else if (IS_BROADWATER(dev_priv) || IS_CRESTLINE(dev_priv) ||
IS_VALLEYVIEW(dev_priv) || IS_CHERRYVIEW(dev_priv))
return 128 * 1024;
else if (INTEL_INFO(dev_priv)->gen >= 4)
return 4 * 1024;
else
return 0;
}
static unsigned int intel_surf_alignment(const struct drm_i915_private *dev_priv,
uint64_t fb_modifier)
{
switch (fb_modifier) {
case DRM_FORMAT_MOD_NONE:
return intel_linear_alignment(dev_priv);
case I915_FORMAT_MOD_X_TILED:
if (INTEL_INFO(dev_priv)->gen >= 9)
return 256 * 1024;
return 0;
case I915_FORMAT_MOD_Y_TILED:
case I915_FORMAT_MOD_Yf_TILED:
return 1 * 1024 * 1024;
default:
MISSING_CASE(fb_modifier);
return 0;
}
}
struct i915_vma *
intel_pin_and_fence_fb_obj(struct drm_framebuffer *fb, unsigned int rotation)
{
struct drm_device *dev = fb->dev;
struct drm_i915_private *dev_priv = to_i915(dev);
struct drm_i915_gem_object *obj = intel_fb_obj(fb);
struct i915_ggtt_view view;
struct i915_vma *vma;
u32 alignment;
WARN_ON(!mutex_is_locked(&dev->struct_mutex));
alignment = intel_surf_alignment(dev_priv, fb->modifier);
intel_fill_fb_ggtt_view(&view, fb, rotation);
if (intel_scanout_needs_vtd_wa(dev_priv) && alignment < 256 * 1024)
alignment = 256 * 1024;
intel_runtime_pm_get(dev_priv);
vma = i915_gem_object_pin_to_display_plane(obj, alignment, &view);
if (IS_ERR(vma))
goto err;
if (i915_vma_is_map_and_fenceable(vma)) {
if (i915_vma_get_fence(vma) == 0)
i915_vma_pin_fence(vma);
}
i915_vma_get(vma);
err:
intel_runtime_pm_put(dev_priv);
return vma;
}
void intel_unpin_fb_vma(struct i915_vma *vma)
{
lockdep_assert_held(&vma->vm->dev->struct_mutex);
if (WARN_ON_ONCE(!vma))
return;
i915_vma_unpin_fence(vma);
i915_gem_object_unpin_from_display_plane(vma);
i915_vma_put(vma);
}
static int intel_fb_pitch(const struct drm_framebuffer *fb, int plane,
unsigned int rotation)
{
if (drm_rotation_90_or_270(rotation))
return to_intel_framebuffer(fb)->rotated[plane].pitch;
else
return fb->pitches[plane];
}
u32 intel_fb_xy_to_linear(int x, int y,
const struct intel_plane_state *state,
int plane)
{
const struct drm_framebuffer *fb = state->base.fb;
unsigned int cpp = drm_format_plane_cpp(fb->pixel_format, plane);
unsigned int pitch = fb->pitches[plane];
return y * pitch + x * cpp;
}
void intel_add_fb_offsets(int *x, int *y,
const struct intel_plane_state *state,
int plane)
{
const struct intel_framebuffer *intel_fb = to_intel_framebuffer(state->base.fb);
unsigned int rotation = state->base.rotation;
if (drm_rotation_90_or_270(rotation)) {
*x += intel_fb->rotated[plane].x;
*y += intel_fb->rotated[plane].y;
} else {
*x += intel_fb->normal[plane].x;
*y += intel_fb->normal[plane].y;
}
}
static u32 _intel_adjust_tile_offset(int *x, int *y,
unsigned int tile_width,
unsigned int tile_height,
unsigned int tile_size,
unsigned int pitch_tiles,
u32 old_offset,
u32 new_offset)
{
unsigned int pitch_pixels = pitch_tiles * tile_width;
unsigned int tiles;
WARN_ON(old_offset & (tile_size - 1));
WARN_ON(new_offset & (tile_size - 1));
WARN_ON(new_offset > old_offset);
tiles = (old_offset - new_offset) / tile_size;
*y += tiles / pitch_tiles * tile_height;
*x += tiles % pitch_tiles * tile_width;
*y += *x / pitch_pixels * tile_height;
*x %= pitch_pixels;
return new_offset;
}
static u32 intel_adjust_tile_offset(int *x, int *y,
const struct intel_plane_state *state, int plane,
u32 old_offset, u32 new_offset)
{
const struct drm_i915_private *dev_priv = to_i915(state->base.plane->dev);
const struct drm_framebuffer *fb = state->base.fb;
unsigned int cpp = drm_format_plane_cpp(fb->pixel_format, plane);
unsigned int rotation = state->base.rotation;
unsigned int pitch = intel_fb_pitch(fb, plane, rotation);
WARN_ON(new_offset > old_offset);
if (fb->modifier != DRM_FORMAT_MOD_NONE) {
unsigned int tile_size, tile_width, tile_height;
unsigned int pitch_tiles;
tile_size = intel_tile_size(dev_priv);
intel_tile_dims(dev_priv, &tile_width, &tile_height,
fb->modifier, cpp);
if (drm_rotation_90_or_270(rotation)) {
pitch_tiles = pitch / tile_height;
swap(tile_width, tile_height);
} else {
pitch_tiles = pitch / (tile_width * cpp);
}
_intel_adjust_tile_offset(x, y, tile_width, tile_height,
tile_size, pitch_tiles,
old_offset, new_offset);
} else {
old_offset += *y * pitch + *x * cpp;
*y = (old_offset - new_offset) / pitch;
*x = ((old_offset - new_offset) - *y * pitch) / cpp;
}
return new_offset;
}
static u32 _intel_compute_tile_offset(const struct drm_i915_private *dev_priv,
int *x, int *y,
const struct drm_framebuffer *fb, int plane,
unsigned int pitch,
unsigned int rotation,
u32 alignment)
{
uint64_t fb_modifier = fb->modifier;
unsigned int cpp = drm_format_plane_cpp(fb->pixel_format, plane);
u32 offset, offset_aligned;
if (alignment)
alignment--;
if (fb_modifier != DRM_FORMAT_MOD_NONE) {
unsigned int tile_size, tile_width, tile_height;
unsigned int tile_rows, tiles, pitch_tiles;
tile_size = intel_tile_size(dev_priv);
intel_tile_dims(dev_priv, &tile_width, &tile_height,
fb_modifier, cpp);
if (drm_rotation_90_or_270(rotation)) {
pitch_tiles = pitch / tile_height;
swap(tile_width, tile_height);
} else {
pitch_tiles = pitch / (tile_width * cpp);
}
tile_rows = *y / tile_height;
*y %= tile_height;
tiles = *x / tile_width;
*x %= tile_width;
offset = (tile_rows * pitch_tiles + tiles) * tile_size;
offset_aligned = offset & ~alignment;
_intel_adjust_tile_offset(x, y, tile_width, tile_height,
tile_size, pitch_tiles,
offset, offset_aligned);
} else {
offset = *y * pitch + *x * cpp;
offset_aligned = offset & ~alignment;
*y = (offset & alignment) / pitch;
*x = ((offset & alignment) - *y * pitch) / cpp;
}
return offset_aligned;
}
u32 intel_compute_tile_offset(int *x, int *y,
const struct intel_plane_state *state,
int plane)
{
const struct drm_i915_private *dev_priv = to_i915(state->base.plane->dev);
const struct drm_framebuffer *fb = state->base.fb;
unsigned int rotation = state->base.rotation;
int pitch = intel_fb_pitch(fb, plane, rotation);
u32 alignment;
if (fb->pixel_format == DRM_FORMAT_NV12 && plane == 1)
alignment = 4096;
else
alignment = intel_surf_alignment(dev_priv, fb->modifier);
return _intel_compute_tile_offset(dev_priv, x, y, fb, plane, pitch,
rotation, alignment);
}
static void intel_fb_offset_to_xy(int *x, int *y,
const struct drm_framebuffer *fb, int plane)
{
unsigned int cpp = drm_format_plane_cpp(fb->pixel_format, plane);
unsigned int pitch = fb->pitches[plane];
u32 linear_offset = fb->offsets[plane];
*y = linear_offset / pitch;
*x = linear_offset % pitch / cpp;
}
static unsigned int intel_fb_modifier_to_tiling(uint64_t fb_modifier)
{
switch (fb_modifier) {
case I915_FORMAT_MOD_X_TILED:
return I915_TILING_X;
case I915_FORMAT_MOD_Y_TILED:
return I915_TILING_Y;
default:
return I915_TILING_NONE;
}
}
static int
intel_fill_fb_info(struct drm_i915_private *dev_priv,
struct drm_framebuffer *fb)
{
struct intel_framebuffer *intel_fb = to_intel_framebuffer(fb);
struct intel_rotation_info *rot_info = &intel_fb->rot_info;
u32 gtt_offset_rotated = 0;
unsigned int max_size = 0;
uint32_t format = fb->pixel_format;
int i, num_planes = drm_format_num_planes(format);
unsigned int tile_size = intel_tile_size(dev_priv);
for (i = 0; i < num_planes; i++) {
unsigned int width, height;
unsigned int cpp, size;
u32 offset;
int x, y;
cpp = drm_format_plane_cpp(format, i);
width = drm_format_plane_width(fb->width, format, i);
height = drm_format_plane_height(fb->height, format, i);
intel_fb_offset_to_xy(&x, &y, fb, i);
if (i915_gem_object_is_tiled(intel_fb->obj) &&
(x + width) * cpp > fb->pitches[i]) {
DRM_DEBUG("bad fb plane %d offset: 0x%x\n",
i, fb->offsets[i]);
return -EINVAL;
}
intel_fb->normal[i].x = x;
intel_fb->normal[i].y = y;
offset = _intel_compute_tile_offset(dev_priv, &x, &y,
fb, 0, fb->pitches[i],
DRM_ROTATE_0, tile_size);
offset /= tile_size;
if (fb->modifier != DRM_FORMAT_MOD_NONE) {
unsigned int tile_width, tile_height;
unsigned int pitch_tiles;
struct drm_rect r;
intel_tile_dims(dev_priv, &tile_width, &tile_height,
fb->modifier, cpp);
rot_info->plane[i].offset = offset;
rot_info->plane[i].stride = DIV_ROUND_UP(fb->pitches[i], tile_width * cpp);
rot_info->plane[i].width = DIV_ROUND_UP(x + width, tile_width);
rot_info->plane[i].height = DIV_ROUND_UP(y + height, tile_height);
intel_fb->rotated[i].pitch =
rot_info->plane[i].height * tile_height;
size = rot_info->plane[i].stride * rot_info->plane[i].height;
if (x != 0)
size++;
r.x1 = x;
r.y1 = y;
r.x2 = x + width;
r.y2 = y + height;
drm_rect_rotate(&r,
rot_info->plane[i].width * tile_width,
rot_info->plane[i].height * tile_height,
DRM_ROTATE_270);
x = r.x1;
y = r.y1;
pitch_tiles = intel_fb->rotated[i].pitch / tile_height;
swap(tile_width, tile_height);
_intel_adjust_tile_offset(&x, &y,
tile_width, tile_height,
tile_size, pitch_tiles,
gtt_offset_rotated * tile_size, 0);
gtt_offset_rotated += rot_info->plane[i].width * rot_info->plane[i].height;
intel_fb->rotated[i].x = x;
intel_fb->rotated[i].y = y;
} else {
size = DIV_ROUND_UP((y + height) * fb->pitches[i] +
x * cpp, tile_size);
}
max_size = max(max_size, offset + size);
}
if (max_size * tile_size > to_intel_framebuffer(fb)->obj->base.size) {
DRM_DEBUG("fb too big for bo (need %u bytes, have %zu bytes)\n",
max_size * tile_size, to_intel_framebuffer(fb)->obj->base.size);
return -EINVAL;
}
return 0;
}
static int i9xx_format_to_fourcc(int format)
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
static int skl_format_to_fourcc(int format, bool rgb_order, bool alpha)
{
switch (format) {
case PLANE_CTL_FORMAT_RGB_565:
return DRM_FORMAT_RGB565;
default:
case PLANE_CTL_FORMAT_XRGB_8888:
if (rgb_order) {
if (alpha)
return DRM_FORMAT_ABGR8888;
else
return DRM_FORMAT_XBGR8888;
} else {
if (alpha)
return DRM_FORMAT_ARGB8888;
else
return DRM_FORMAT_XRGB8888;
}
case PLANE_CTL_FORMAT_XRGB_2101010:
if (rgb_order)
return DRM_FORMAT_XBGR2101010;
else
return DRM_FORMAT_XRGB2101010;
}
}
static bool
intel_alloc_initial_plane_obj(struct intel_crtc *crtc,
struct intel_initial_plane_config *plane_config)
{
struct drm_device *dev = crtc->base.dev;
struct drm_i915_private *dev_priv = to_i915(dev);
struct i915_ggtt *ggtt = &dev_priv->ggtt;
struct drm_i915_gem_object *obj = NULL;
struct drm_mode_fb_cmd2 mode_cmd = { 0 };
struct drm_framebuffer *fb = &plane_config->fb->base;
u32 base_aligned = round_down(plane_config->base, PAGE_SIZE);
u32 size_aligned = round_up(plane_config->base + plane_config->size,
PAGE_SIZE);
size_aligned -= base_aligned;
if (plane_config->size == 0)
return false;
if (size_aligned * 2 > ggtt->stolen_usable_size)
return false;
mutex_lock(&dev->struct_mutex);
obj = i915_gem_object_create_stolen_for_preallocated(dev,
base_aligned,
base_aligned,
size_aligned);
if (!obj) {
mutex_unlock(&dev->struct_mutex);
return false;
}
if (plane_config->tiling == I915_TILING_X)
obj->tiling_and_stride = fb->pitches[0] | I915_TILING_X;
mode_cmd.pixel_format = fb->pixel_format;
mode_cmd.width = fb->width;
mode_cmd.height = fb->height;
mode_cmd.pitches[0] = fb->pitches[0];
mode_cmd.modifier[0] = fb->modifier;
mode_cmd.flags = DRM_MODE_FB_MODIFIERS;
if (intel_framebuffer_init(dev, to_intel_framebuffer(fb),
&mode_cmd, obj)) {
DRM_DEBUG_KMS("intel fb init failed\n");
goto out_unref_obj;
}
mutex_unlock(&dev->struct_mutex);
DRM_DEBUG_KMS("initial plane fb obj %p\n", obj);
return true;
out_unref_obj:
i915_gem_object_put(obj);
mutex_unlock(&dev->struct_mutex);
return false;
}
static void
update_state_fb(struct drm_plane *plane)
{
if (plane->fb == plane->state->fb)
return;
if (plane->state->fb)
drm_framebuffer_unreference(plane->state->fb);
plane->state->fb = plane->fb;
if (plane->state->fb)
drm_framebuffer_reference(plane->state->fb);
}
static void
intel_find_initial_plane_obj(struct intel_crtc *intel_crtc,
struct intel_initial_plane_config *plane_config)
{
struct drm_device *dev = intel_crtc->base.dev;
struct drm_i915_private *dev_priv = to_i915(dev);
struct drm_crtc *c;
struct drm_i915_gem_object *obj;
struct drm_plane *primary = intel_crtc->base.primary;
struct drm_plane_state *plane_state = primary->state;
struct drm_crtc_state *crtc_state = intel_crtc->base.state;
struct intel_plane *intel_plane = to_intel_plane(primary);
struct intel_plane_state *intel_state =
to_intel_plane_state(plane_state);
struct drm_framebuffer *fb;
if (!plane_config->fb)
return;
if (intel_alloc_initial_plane_obj(intel_crtc, plane_config)) {
fb = &plane_config->fb->base;
goto valid_fb;
}
kfree(plane_config->fb);
for_each_crtc(dev, c) {
struct intel_plane_state *state;
if (c == &intel_crtc->base)
continue;
if (!to_intel_crtc(c)->active)
continue;
state = to_intel_plane_state(c->primary->state);
if (!state->vma)
continue;
if (intel_plane_ggtt_offset(state) == plane_config->base) {
fb = c->primary->fb;
drm_framebuffer_reference(fb);
goto valid_fb;
}
}
to_intel_plane_state(plane_state)->base.visible = false;
crtc_state->plane_mask &= ~(1 << drm_plane_index(primary));
intel_pre_disable_primary_noatomic(&intel_crtc->base);
intel_plane->disable_plane(primary, &intel_crtc->base);
return;
valid_fb:
mutex_lock(&dev->struct_mutex);
intel_state->vma =
intel_pin_and_fence_fb_obj(fb, primary->state->rotation);
mutex_unlock(&dev->struct_mutex);
if (IS_ERR(intel_state->vma)) {
DRM_ERROR("failed to pin boot fb on pipe %d: %li\n",
intel_crtc->pipe, PTR_ERR(intel_state->vma));
intel_state->vma = NULL;
drm_framebuffer_unreference(fb);
return;
}
plane_state->src_x = 0;
plane_state->src_y = 0;
plane_state->src_w = fb->width << 16;
plane_state->src_h = fb->height << 16;
plane_state->crtc_x = 0;
plane_state->crtc_y = 0;
plane_state->crtc_w = fb->width;
plane_state->crtc_h = fb->height;
intel_state->base.src = drm_plane_state_src(plane_state);
intel_state->base.dst = drm_plane_state_dest(plane_state);
obj = intel_fb_obj(fb);
if (i915_gem_object_is_tiled(obj))
dev_priv->preserve_bios_swizzle = true;
drm_framebuffer_reference(fb);
primary->fb = primary->state->fb = fb;
primary->crtc = primary->state->crtc = &intel_crtc->base;
intel_crtc->base.state->plane_mask |= (1 << drm_plane_index(primary));
atomic_or(to_intel_plane(primary)->frontbuffer_bit,
&obj->frontbuffer_bits);
}
static int skl_max_plane_width(const struct drm_framebuffer *fb, int plane,
unsigned int rotation)
{
int cpp = drm_format_plane_cpp(fb->pixel_format, plane);
switch (fb->modifier) {
case DRM_FORMAT_MOD_NONE:
case I915_FORMAT_MOD_X_TILED:
switch (cpp) {
case 8:
return 4096;
case 4:
case 2:
case 1:
return 8192;
default:
MISSING_CASE(cpp);
break;
}
break;
case I915_FORMAT_MOD_Y_TILED:
case I915_FORMAT_MOD_Yf_TILED:
switch (cpp) {
case 8:
return 2048;
case 4:
return 4096;
case 2:
case 1:
return 8192;
default:
MISSING_CASE(cpp);
break;
}
break;
default:
MISSING_CASE(fb->modifier);
}
return 2048;
}
static int skl_check_main_surface(struct intel_plane_state *plane_state)
{
const struct drm_i915_private *dev_priv = to_i915(plane_state->base.plane->dev);
const struct drm_framebuffer *fb = plane_state->base.fb;
unsigned int rotation = plane_state->base.rotation;
int x = plane_state->base.src.x1 >> 16;
int y = plane_state->base.src.y1 >> 16;
int w = drm_rect_width(&plane_state->base.src) >> 16;
int h = drm_rect_height(&plane_state->base.src) >> 16;
int max_width = skl_max_plane_width(fb, 0, rotation);
int max_height = 4096;
u32 alignment, offset, aux_offset = plane_state->aux.offset;
if (w > max_width || h > max_height) {
DRM_DEBUG_KMS("requested Y/RGB source size %dx%d too big (limit %dx%d)\n",
w, h, max_width, max_height);
return -EINVAL;
}
intel_add_fb_offsets(&x, &y, plane_state, 0);
offset = intel_compute_tile_offset(&x, &y, plane_state, 0);
alignment = intel_surf_alignment(dev_priv, fb->modifier);
if (offset > aux_offset)
offset = intel_adjust_tile_offset(&x, &y, plane_state, 0,
offset, aux_offset & ~(alignment - 1));
if (fb->modifier == I915_FORMAT_MOD_X_TILED) {
int cpp = drm_format_plane_cpp(fb->pixel_format, 0);
while ((x + w) * cpp > fb->pitches[0]) {
if (offset == 0) {
DRM_DEBUG_KMS("Unable to find suitable display surface offset\n");
return -EINVAL;
}
offset = intel_adjust_tile_offset(&x, &y, plane_state, 0,
offset, offset - alignment);
}
}
plane_state->main.offset = offset;
plane_state->main.x = x;
plane_state->main.y = y;
return 0;
}
static int skl_check_nv12_aux_surface(struct intel_plane_state *plane_state)
{
const struct drm_framebuffer *fb = plane_state->base.fb;
unsigned int rotation = plane_state->base.rotation;
int max_width = skl_max_plane_width(fb, 1, rotation);
int max_height = 4096;
int x = plane_state->base.src.x1 >> 17;
int y = plane_state->base.src.y1 >> 17;
int w = drm_rect_width(&plane_state->base.src) >> 17;
int h = drm_rect_height(&plane_state->base.src) >> 17;
u32 offset;
intel_add_fb_offsets(&x, &y, plane_state, 1);
offset = intel_compute_tile_offset(&x, &y, plane_state, 1);
if (w > max_width || h > max_height) {
DRM_DEBUG_KMS("CbCr source size %dx%d too big (limit %dx%d)\n",
w, h, max_width, max_height);
return -EINVAL;
}
plane_state->aux.offset = offset;
plane_state->aux.x = x;
plane_state->aux.y = y;
return 0;
}
int skl_check_plane_surface(struct intel_plane_state *plane_state)
{
const struct drm_framebuffer *fb = plane_state->base.fb;
unsigned int rotation = plane_state->base.rotation;
int ret;
if (!plane_state->base.visible)
return 0;
if (drm_rotation_90_or_270(rotation))
drm_rect_rotate(&plane_state->base.src,
fb->width << 16, fb->height << 16,
DRM_ROTATE_270);
if (fb->pixel_format == DRM_FORMAT_NV12) {
ret = skl_check_nv12_aux_surface(plane_state);
if (ret)
return ret;
} else {
plane_state->aux.offset = ~0xfff;
plane_state->aux.x = 0;
plane_state->aux.y = 0;
}
ret = skl_check_main_surface(plane_state);
if (ret)
return ret;
return 0;
}
static void i9xx_update_primary_plane(struct drm_plane *primary,
const struct intel_crtc_state *crtc_state,
const struct intel_plane_state *plane_state)
{
struct drm_i915_private *dev_priv = to_i915(primary->dev);
struct intel_crtc *intel_crtc = to_intel_crtc(crtc_state->base.crtc);
struct drm_framebuffer *fb = plane_state->base.fb;
int plane = intel_crtc->plane;
u32 linear_offset;
u32 dspcntr;
i915_reg_t reg = DSPCNTR(plane);
unsigned int rotation = plane_state->base.rotation;
int x = plane_state->base.src.x1 >> 16;
int y = plane_state->base.src.y1 >> 16;
dspcntr = DISPPLANE_GAMMA_ENABLE;
dspcntr |= DISPLAY_PLANE_ENABLE;
if (INTEL_GEN(dev_priv) < 4) {
if (intel_crtc->pipe == PIPE_B)
dspcntr |= DISPPLANE_SEL_PIPE_B;
I915_WRITE(DSPSIZE(plane),
((crtc_state->pipe_src_h - 1) << 16) |
(crtc_state->pipe_src_w - 1));
I915_WRITE(DSPPOS(plane), 0);
} else if (IS_CHERRYVIEW(dev_priv) && plane == PLANE_B) {
I915_WRITE(PRIMSIZE(plane),
((crtc_state->pipe_src_h - 1) << 16) |
(crtc_state->pipe_src_w - 1));
I915_WRITE(PRIMPOS(plane), 0);
I915_WRITE(PRIMCNSTALPHA(plane), 0);
}
switch (fb->pixel_format) {
case DRM_FORMAT_C8:
dspcntr |= DISPPLANE_8BPP;
break;
case DRM_FORMAT_XRGB1555:
dspcntr |= DISPPLANE_BGRX555;
break;
case DRM_FORMAT_RGB565:
dspcntr |= DISPPLANE_BGRX565;
break;
case DRM_FORMAT_XRGB8888:
dspcntr |= DISPPLANE_BGRX888;
break;
case DRM_FORMAT_XBGR8888:
dspcntr |= DISPPLANE_RGBX888;
break;
case DRM_FORMAT_XRGB2101010:
dspcntr |= DISPPLANE_BGRX101010;
break;
case DRM_FORMAT_XBGR2101010:
dspcntr |= DISPPLANE_RGBX101010;
break;
default:
BUG();
}
if (INTEL_GEN(dev_priv) >= 4 &&
fb->modifier == I915_FORMAT_MOD_X_TILED)
dspcntr |= DISPPLANE_TILED;
if (rotation & DRM_ROTATE_180)
dspcntr |= DISPPLANE_ROTATE_180;
if (rotation & DRM_REFLECT_X)
dspcntr |= DISPPLANE_MIRROR;
if (IS_G4X(dev_priv))
dspcntr |= DISPPLANE_TRICKLE_FEED_DISABLE;
intel_add_fb_offsets(&x, &y, plane_state, 0);
if (INTEL_GEN(dev_priv) >= 4)
intel_crtc->dspaddr_offset =
intel_compute_tile_offset(&x, &y, plane_state, 0);
if (rotation & DRM_ROTATE_180) {
x += crtc_state->pipe_src_w - 1;
y += crtc_state->pipe_src_h - 1;
} else if (rotation & DRM_REFLECT_X) {
x += crtc_state->pipe_src_w - 1;
}
linear_offset = intel_fb_xy_to_linear(x, y, plane_state, 0);
if (INTEL_GEN(dev_priv) < 4)
intel_crtc->dspaddr_offset = linear_offset;
intel_crtc->adjusted_x = x;
intel_crtc->adjusted_y = y;
I915_WRITE(reg, dspcntr);
I915_WRITE(DSPSTRIDE(plane), fb->pitches[0]);
if (INTEL_GEN(dev_priv) >= 4) {
I915_WRITE(DSPSURF(plane),
intel_plane_ggtt_offset(plane_state) +
intel_crtc->dspaddr_offset);
I915_WRITE(DSPTILEOFF(plane), (y << 16) | x);
I915_WRITE(DSPLINOFF(plane), linear_offset);
} else {
I915_WRITE(DSPADDR(plane),
intel_plane_ggtt_offset(plane_state) +
intel_crtc->dspaddr_offset);
}
POSTING_READ(reg);
}
static void i9xx_disable_primary_plane(struct drm_plane *primary,
struct drm_crtc *crtc)
{
struct drm_device *dev = crtc->dev;
struct drm_i915_private *dev_priv = to_i915(dev);
struct intel_crtc *intel_crtc = to_intel_crtc(crtc);
int plane = intel_crtc->plane;
I915_WRITE(DSPCNTR(plane), 0);
if (INTEL_INFO(dev_priv)->gen >= 4)
I915_WRITE(DSPSURF(plane), 0);
else
I915_WRITE(DSPADDR(plane), 0);
POSTING_READ(DSPCNTR(plane));
}
static void ironlake_update_primary_plane(struct drm_plane *primary,
const struct intel_crtc_state *crtc_state,
const struct intel_plane_state *plane_state)
{
struct drm_device *dev = primary->dev;
struct drm_i915_private *dev_priv = to_i915(dev);
struct intel_crtc *intel_crtc = to_intel_crtc(crtc_state->base.crtc);
struct drm_framebuffer *fb = plane_state->base.fb;
int plane = intel_crtc->plane;
u32 linear_offset;
u32 dspcntr;
i915_reg_t reg = DSPCNTR(plane);
unsigned int rotation = plane_state->base.rotation;
int x = plane_state->base.src.x1 >> 16;
int y = plane_state->base.src.y1 >> 16;
dspcntr = DISPPLANE_GAMMA_ENABLE;
dspcntr |= DISPLAY_PLANE_ENABLE;
if (IS_HASWELL(dev_priv) || IS_BROADWELL(dev_priv))
dspcntr |= DISPPLANE_PIPE_CSC_ENABLE;
switch (fb->pixel_format) {
case DRM_FORMAT_C8:
dspcntr |= DISPPLANE_8BPP;
break;
case DRM_FORMAT_RGB565:
dspcntr |= DISPPLANE_BGRX565;
break;
case DRM_FORMAT_XRGB8888:
dspcntr |= DISPPLANE_BGRX888;
break;
case DRM_FORMAT_XBGR8888:
dspcntr |= DISPPLANE_RGBX888;
break;
case DRM_FORMAT_XRGB2101010:
dspcntr |= DISPPLANE_BGRX101010;
break;
case DRM_FORMAT_XBGR2101010:
dspcntr |= DISPPLANE_RGBX101010;
break;
default:
BUG();
}
if (fb->modifier == I915_FORMAT_MOD_X_TILED)
dspcntr |= DISPPLANE_TILED;
if (rotation & DRM_ROTATE_180)
dspcntr |= DISPPLANE_ROTATE_180;
if (!IS_HASWELL(dev_priv) && !IS_BROADWELL(dev_priv))
dspcntr |= DISPPLANE_TRICKLE_FEED_DISABLE;
intel_add_fb_offsets(&x, &y, plane_state, 0);
intel_crtc->dspaddr_offset =
intel_compute_tile_offset(&x, &y, plane_state, 0);
if (!IS_HASWELL(dev_priv) && !IS_BROADWELL(dev_priv) &&
rotation & DRM_ROTATE_180) {
x += crtc_state->pipe_src_w - 1;
y += crtc_state->pipe_src_h - 1;
}
linear_offset = intel_fb_xy_to_linear(x, y, plane_state, 0);
intel_crtc->adjusted_x = x;
intel_crtc->adjusted_y = y;
I915_WRITE(reg, dspcntr);
I915_WRITE(DSPSTRIDE(plane), fb->pitches[0]);
I915_WRITE(DSPSURF(plane),
intel_plane_ggtt_offset(plane_state) +
intel_crtc->dspaddr_offset);
if (IS_HASWELL(dev_priv) || IS_BROADWELL(dev_priv)) {
I915_WRITE(DSPOFFSET(plane), (y << 16) | x);
} else {
I915_WRITE(DSPTILEOFF(plane), (y << 16) | x);
I915_WRITE(DSPLINOFF(plane), linear_offset);
}
POSTING_READ(reg);
}
u32 intel_fb_stride_alignment(const struct drm_i915_private *dev_priv,
uint64_t fb_modifier, uint32_t pixel_format)
{
if (fb_modifier == DRM_FORMAT_MOD_NONE) {
return 64;
} else {
int cpp = drm_format_plane_cpp(pixel_format, 0);
return intel_tile_width_bytes(dev_priv, fb_modifier, cpp);
}
}
static void skl_detach_scaler(struct intel_crtc *intel_crtc, int id)
{
struct drm_device *dev = intel_crtc->base.dev;
struct drm_i915_private *dev_priv = to_i915(dev);
I915_WRITE(SKL_PS_CTRL(intel_crtc->pipe, id), 0);
I915_WRITE(SKL_PS_WIN_POS(intel_crtc->pipe, id), 0);
I915_WRITE(SKL_PS_WIN_SZ(intel_crtc->pipe, id), 0);
}
static void skl_detach_scalers(struct intel_crtc *intel_crtc)
{
struct intel_crtc_scaler_state *scaler_state;
int i;
scaler_state = &intel_crtc->config->scaler_state;
for (i = 0; i < intel_crtc->num_scalers; i++) {
if (!scaler_state->scalers[i].in_use)
skl_detach_scaler(intel_crtc, i);
}
}
u32 skl_plane_stride(const struct drm_framebuffer *fb, int plane,
unsigned int rotation)
{
const struct drm_i915_private *dev_priv = to_i915(fb->dev);
u32 stride = intel_fb_pitch(fb, plane, rotation);
if (drm_rotation_90_or_270(rotation)) {
int cpp = drm_format_plane_cpp(fb->pixel_format, plane);
stride /= intel_tile_height(dev_priv, fb->modifier, cpp);
} else {
stride /= intel_fb_stride_alignment(dev_priv, fb->modifier,
fb->pixel_format);
}
return stride;
}
u32 skl_plane_ctl_format(uint32_t pixel_format)
{
switch (pixel_format) {
case DRM_FORMAT_C8:
return PLANE_CTL_FORMAT_INDEXED;
case DRM_FORMAT_RGB565:
return PLANE_CTL_FORMAT_RGB_565;
case DRM_FORMAT_XBGR8888:
return PLANE_CTL_FORMAT_XRGB_8888 | PLANE_CTL_ORDER_RGBX;
case DRM_FORMAT_XRGB8888:
return PLANE_CTL_FORMAT_XRGB_8888;
case DRM_FORMAT_ABGR8888:
return PLANE_CTL_FORMAT_XRGB_8888 | PLANE_CTL_ORDER_RGBX |
PLANE_CTL_ALPHA_SW_PREMULTIPLY;
case DRM_FORMAT_ARGB8888:
return PLANE_CTL_FORMAT_XRGB_8888 |
PLANE_CTL_ALPHA_SW_PREMULTIPLY;
case DRM_FORMAT_XRGB2101010:
return PLANE_CTL_FORMAT_XRGB_2101010;
case DRM_FORMAT_XBGR2101010:
return PLANE_CTL_ORDER_RGBX | PLANE_CTL_FORMAT_XRGB_2101010;
case DRM_FORMAT_YUYV:
return PLANE_CTL_FORMAT_YUV422 | PLANE_CTL_YUV422_YUYV;
case DRM_FORMAT_YVYU:
return PLANE_CTL_FORMAT_YUV422 | PLANE_CTL_YUV422_YVYU;
case DRM_FORMAT_UYVY:
return PLANE_CTL_FORMAT_YUV422 | PLANE_CTL_YUV422_UYVY;
case DRM_FORMAT_VYUY:
return PLANE_CTL_FORMAT_YUV422 | PLANE_CTL_YUV422_VYUY;
default:
MISSING_CASE(pixel_format);
}
return 0;
}
u32 skl_plane_ctl_tiling(uint64_t fb_modifier)
{
switch (fb_modifier) {
case DRM_FORMAT_MOD_NONE:
break;
case I915_FORMAT_MOD_X_TILED:
return PLANE_CTL_TILED_X;
case I915_FORMAT_MOD_Y_TILED:
return PLANE_CTL_TILED_Y;
case I915_FORMAT_MOD_Yf_TILED:
return PLANE_CTL_TILED_YF;
default:
MISSING_CASE(fb_modifier);
}
return 0;
}
u32 skl_plane_ctl_rotation(unsigned int rotation)
{
switch (rotation) {
case DRM_ROTATE_0:
break;
case DRM_ROTATE_90:
return PLANE_CTL_ROTATE_270;
case DRM_ROTATE_180:
return PLANE_CTL_ROTATE_180;
case DRM_ROTATE_270:
return PLANE_CTL_ROTATE_90;
default:
MISSING_CASE(rotation);
}
return 0;
}
static void skylake_update_primary_plane(struct drm_plane *plane,
const struct intel_crtc_state *crtc_state,
const struct intel_plane_state *plane_state)
{
struct drm_device *dev = plane->dev;
struct drm_i915_private *dev_priv = to_i915(dev);
struct intel_crtc *intel_crtc = to_intel_crtc(crtc_state->base.crtc);
struct drm_framebuffer *fb = plane_state->base.fb;
int pipe = intel_crtc->pipe;
u32 plane_ctl;
unsigned int rotation = plane_state->base.rotation;
u32 stride = skl_plane_stride(fb, 0, rotation);
u32 surf_addr = plane_state->main.offset;
int scaler_id = plane_state->scaler_id;
int src_x = plane_state->main.x;
int src_y = plane_state->main.y;
int src_w = drm_rect_width(&plane_state->base.src) >> 16;
int src_h = drm_rect_height(&plane_state->base.src) >> 16;
int dst_x = plane_state->base.dst.x1;
int dst_y = plane_state->base.dst.y1;
int dst_w = drm_rect_width(&plane_state->base.dst);
int dst_h = drm_rect_height(&plane_state->base.dst);
plane_ctl = PLANE_CTL_ENABLE |
PLANE_CTL_PIPE_GAMMA_ENABLE |
PLANE_CTL_PIPE_CSC_ENABLE;
plane_ctl |= skl_plane_ctl_format(fb->pixel_format);
plane_ctl |= skl_plane_ctl_tiling(fb->modifier);
plane_ctl |= PLANE_CTL_PLANE_GAMMA_DISABLE;
plane_ctl |= skl_plane_ctl_rotation(rotation);
src_w--;
src_h--;
dst_w--;
dst_h--;
intel_crtc->dspaddr_offset = surf_addr;
intel_crtc->adjusted_x = src_x;
intel_crtc->adjusted_y = src_y;
I915_WRITE(PLANE_CTL(pipe, 0), plane_ctl);
I915_WRITE(PLANE_OFFSET(pipe, 0), (src_y << 16) | src_x);
I915_WRITE(PLANE_STRIDE(pipe, 0), stride);
I915_WRITE(PLANE_SIZE(pipe, 0), (src_h << 16) | src_w);
if (scaler_id >= 0) {
uint32_t ps_ctrl = 0;
WARN_ON(!dst_w || !dst_h);
ps_ctrl = PS_SCALER_EN | PS_PLANE_SEL(0) |
crtc_state->scaler_state.scalers[scaler_id].mode;
I915_WRITE(SKL_PS_CTRL(pipe, scaler_id), ps_ctrl);
I915_WRITE(SKL_PS_PWR_GATE(pipe, scaler_id), 0);
I915_WRITE(SKL_PS_WIN_POS(pipe, scaler_id), (dst_x << 16) | dst_y);
I915_WRITE(SKL_PS_WIN_SZ(pipe, scaler_id), (dst_w << 16) | dst_h);
I915_WRITE(PLANE_POS(pipe, 0), 0);
} else {
I915_WRITE(PLANE_POS(pipe, 0), (dst_y << 16) | dst_x);
}
I915_WRITE(PLANE_SURF(pipe, 0),
intel_plane_ggtt_offset(plane_state) + surf_addr);
POSTING_READ(PLANE_SURF(pipe, 0));
}
static void skylake_disable_primary_plane(struct drm_plane *primary,
struct drm_crtc *crtc)
{
struct drm_device *dev = crtc->dev;
struct drm_i915_private *dev_priv = to_i915(dev);
struct intel_crtc *intel_crtc = to_intel_crtc(crtc);
int pipe = intel_crtc->pipe;
I915_WRITE(PLANE_CTL(pipe, 0), 0);
I915_WRITE(PLANE_SURF(pipe, 0), 0);
POSTING_READ(PLANE_SURF(pipe, 0));
}
static int
intel_pipe_set_base_atomic(struct drm_crtc *crtc, struct drm_framebuffer *fb,
int x, int y, enum mode_set_atomic state)
{
DRM_ERROR("legacy panic handler not supported any more.\n");
return -ENODEV;
}
static void intel_complete_page_flips(struct drm_i915_private *dev_priv)
{
struct intel_crtc *crtc;
for_each_intel_crtc(&dev_priv->drm, crtc)
intel_finish_page_flip_cs(dev_priv, crtc->pipe);
}
static void intel_update_primary_planes(struct drm_device *dev)
{
struct drm_crtc *crtc;
for_each_crtc(dev, crtc) {
struct intel_plane *plane = to_intel_plane(crtc->primary);
struct intel_plane_state *plane_state =
to_intel_plane_state(plane->base.state);
if (plane_state->base.visible)
plane->update_plane(&plane->base,
to_intel_crtc_state(crtc->state),
plane_state);
}
}
static int
__intel_display_resume(struct drm_device *dev,
struct drm_atomic_state *state)
{
struct drm_crtc_state *crtc_state;
struct drm_crtc *crtc;
int i, ret;
intel_modeset_setup_hw_state(dev);
i915_redisable_vga(to_i915(dev));
if (!state)
return 0;
for_each_crtc_in_state(state, crtc, crtc_state, i) {
crtc_state->mode_changed = true;
}
to_intel_atomic_state(state)->skip_intermediate_wm = true;
ret = drm_atomic_commit(state);
WARN_ON(ret == -EDEADLK);
return ret;
}
static bool gpu_reset_clobbers_display(struct drm_i915_private *dev_priv)
{
return intel_has_gpu_reset(dev_priv) &&
INTEL_GEN(dev_priv) < 5 && !IS_G4X(dev_priv);
}
void intel_prepare_reset(struct drm_i915_private *dev_priv)
{
struct drm_device *dev = &dev_priv->drm;
struct drm_modeset_acquire_ctx *ctx = &dev_priv->reset_ctx;
struct drm_atomic_state *state;
int ret;
mutex_lock(&dev->mode_config.mutex);
drm_modeset_acquire_init(ctx, 0);
while (1) {
ret = drm_modeset_lock_all_ctx(dev, ctx);
if (ret != -EDEADLK)
break;
drm_modeset_backoff(ctx);
}
if (!i915.force_reset_modeset_test &&
!gpu_reset_clobbers_display(dev_priv))
return;
state = drm_atomic_helper_duplicate_state(dev, ctx);
if (IS_ERR(state)) {
ret = PTR_ERR(state);
state = NULL;
DRM_ERROR("Duplicating state failed with %i\n", ret);
goto err;
}
ret = drm_atomic_helper_disable_all(dev, ctx);
if (ret) {
DRM_ERROR("Suspending crtc's failed with %i\n", ret);
goto err;
}
dev_priv->modeset_restore_state = state;
state->acquire_ctx = ctx;
return;
err:
drm_atomic_state_put(state);
}
void intel_finish_reset(struct drm_i915_private *dev_priv)
{
struct drm_device *dev = &dev_priv->drm;
struct drm_modeset_acquire_ctx *ctx = &dev_priv->reset_ctx;
struct drm_atomic_state *state = dev_priv->modeset_restore_state;
int ret;
intel_complete_page_flips(dev_priv);
dev_priv->modeset_restore_state = NULL;
if (!gpu_reset_clobbers_display(dev_priv)) {
if (!state) {
intel_update_primary_planes(dev);
} else {
ret = __intel_display_resume(dev, state);
if (ret)
DRM_ERROR("Restoring old state failed with %i\n", ret);
}
} else {
intel_runtime_pm_disable_interrupts(dev_priv);
intel_runtime_pm_enable_interrupts(dev_priv);
intel_pps_unlock_regs_wa(dev_priv);
intel_modeset_init_hw(dev);
spin_lock_irq(&dev_priv->irq_lock);
if (dev_priv->display.hpd_irq_setup)
dev_priv->display.hpd_irq_setup(dev_priv);
spin_unlock_irq(&dev_priv->irq_lock);
ret = __intel_display_resume(dev, state);
if (ret)
DRM_ERROR("Restoring old state failed with %i\n", ret);
intel_hpd_init(dev_priv);
}
if (state)
drm_atomic_state_put(state);
drm_modeset_drop_locks(ctx);
drm_modeset_acquire_fini(ctx);
mutex_unlock(&dev->mode_config.mutex);
}
static bool abort_flip_on_reset(struct intel_crtc *crtc)
{
struct i915_gpu_error *error = &to_i915(crtc->base.dev)->gpu_error;
if (i915_reset_in_progress(error))
return true;
if (crtc->reset_count != i915_reset_count(error))
return true;
return false;
}
static bool intel_crtc_has_pending_flip(struct drm_crtc *crtc)
{
struct drm_device *dev = crtc->dev;
struct intel_crtc *intel_crtc = to_intel_crtc(crtc);
bool pending;
if (abort_flip_on_reset(intel_crtc))
return false;
spin_lock_irq(&dev->event_lock);
pending = to_intel_crtc(crtc)->flip_work != NULL;
spin_unlock_irq(&dev->event_lock);
return pending;
}
static void intel_update_pipe_config(struct intel_crtc *crtc,
struct intel_crtc_state *old_crtc_state)
{
struct drm_i915_private *dev_priv = to_i915(crtc->base.dev);
struct intel_crtc_state *pipe_config =
to_intel_crtc_state(crtc->base.state);
crtc->base.mode = crtc->base.state->mode;
DRM_DEBUG_KMS("Updating pipe size %ix%i -> %ix%i\n",
old_crtc_state->pipe_src_w, old_crtc_state->pipe_src_h,
pipe_config->pipe_src_w, pipe_config->pipe_src_h);
I915_WRITE(PIPESRC(crtc->pipe),
((pipe_config->pipe_src_w - 1) << 16) |
(pipe_config->pipe_src_h - 1));
if (INTEL_GEN(dev_priv) >= 9) {
skl_detach_scalers(crtc);
if (pipe_config->pch_pfit.enabled)
skylake_pfit_enable(crtc);
} else if (HAS_PCH_SPLIT(dev_priv)) {
if (pipe_config->pch_pfit.enabled)
ironlake_pfit_enable(crtc);
else if (old_crtc_state->pch_pfit.enabled)
ironlake_pfit_disable(crtc, true);
}
}
static void intel_fdi_normal_train(struct drm_crtc *crtc)
{
struct drm_device *dev = crtc->dev;
struct drm_i915_private *dev_priv = to_i915(dev);
struct intel_crtc *intel_crtc = to_intel_crtc(crtc);
int pipe = intel_crtc->pipe;
i915_reg_t reg;
u32 temp;
reg = FDI_TX_CTL(pipe);
temp = I915_READ(reg);
if (IS_IVYBRIDGE(dev_priv)) {
temp &= ~FDI_LINK_TRAIN_NONE_IVB;
temp |= FDI_LINK_TRAIN_NONE_IVB | FDI_TX_ENHANCE_FRAME_ENABLE;
} else {
temp &= ~FDI_LINK_TRAIN_NONE;
temp |= FDI_LINK_TRAIN_NONE | FDI_TX_ENHANCE_FRAME_ENABLE;
}
I915_WRITE(reg, temp);
reg = FDI_RX_CTL(pipe);
temp = I915_READ(reg);
if (HAS_PCH_CPT(dev_priv)) {
temp &= ~FDI_LINK_TRAIN_PATTERN_MASK_CPT;
temp |= FDI_LINK_TRAIN_NORMAL_CPT;
} else {
temp &= ~FDI_LINK_TRAIN_NONE;
temp |= FDI_LINK_TRAIN_NONE;
}
I915_WRITE(reg, temp | FDI_RX_ENHANCE_FRAME_ENABLE);
POSTING_READ(reg);
udelay(1000);
if (IS_IVYBRIDGE(dev_priv))
I915_WRITE(reg, I915_READ(reg) | FDI_FS_ERRC_ENABLE |
FDI_FE_ERRC_ENABLE);
}
static void ironlake_fdi_link_train(struct drm_crtc *crtc)
{
struct drm_device *dev = crtc->dev;
struct drm_i915_private *dev_priv = to_i915(dev);
struct intel_crtc *intel_crtc = to_intel_crtc(crtc);
int pipe = intel_crtc->pipe;
i915_reg_t reg;
u32 temp, tries;
assert_pipe_enabled(dev_priv, pipe);
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
temp |= FDI_DP_PORT_WIDTH(intel_crtc->config->fdi_lanes);
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
struct drm_i915_private *dev_priv = to_i915(dev);
struct intel_crtc *intel_crtc = to_intel_crtc(crtc);
int pipe = intel_crtc->pipe;
i915_reg_t reg;
u32 temp, i, retry;
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
temp |= FDI_DP_PORT_WIDTH(intel_crtc->config->fdi_lanes);
temp &= ~FDI_LINK_TRAIN_NONE;
temp |= FDI_LINK_TRAIN_PATTERN_1;
temp &= ~FDI_LINK_TRAIN_VOL_EMP_MASK;
temp |= FDI_LINK_TRAIN_400MV_0DB_SNB_B;
I915_WRITE(reg, temp | FDI_TX_ENABLE);
I915_WRITE(FDI_RX_MISC(pipe),
FDI_RX_TP1_TO_TP2_48 | FDI_RX_FDI_DELAY_90);
reg = FDI_RX_CTL(pipe);
temp = I915_READ(reg);
if (HAS_PCH_CPT(dev_priv)) {
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
if (IS_GEN6(dev_priv)) {
temp &= ~FDI_LINK_TRAIN_VOL_EMP_MASK;
temp |= FDI_LINK_TRAIN_400MV_0DB_SNB_B;
}
I915_WRITE(reg, temp);
reg = FDI_RX_CTL(pipe);
temp = I915_READ(reg);
if (HAS_PCH_CPT(dev_priv)) {
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
struct drm_i915_private *dev_priv = to_i915(dev);
struct intel_crtc *intel_crtc = to_intel_crtc(crtc);
int pipe = intel_crtc->pipe;
i915_reg_t reg;
u32 temp, i, j;
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
temp |= FDI_DP_PORT_WIDTH(intel_crtc->config->fdi_lanes);
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
struct drm_i915_private *dev_priv = to_i915(dev);
int pipe = intel_crtc->pipe;
i915_reg_t reg;
u32 temp;
reg = FDI_RX_CTL(pipe);
temp = I915_READ(reg);
temp &= ~(FDI_DP_PORT_WIDTH_MASK | (0x7 << 16));
temp |= FDI_DP_PORT_WIDTH(intel_crtc->config->fdi_lanes);
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
struct drm_i915_private *dev_priv = to_i915(dev);
int pipe = intel_crtc->pipe;
i915_reg_t reg;
u32 temp;
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
struct drm_i915_private *dev_priv = to_i915(dev);
struct intel_crtc *intel_crtc = to_intel_crtc(crtc);
int pipe = intel_crtc->pipe;
i915_reg_t reg;
u32 temp;
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
if (HAS_PCH_IBX(dev_priv))
I915_WRITE(FDI_RX_CHICKEN(pipe), FDI_RX_PHASE_SYNC_POINTER_OVR);
reg = FDI_TX_CTL(pipe);
temp = I915_READ(reg);
temp &= ~FDI_LINK_TRAIN_NONE;
temp |= FDI_LINK_TRAIN_PATTERN_1;
I915_WRITE(reg, temp);
reg = FDI_RX_CTL(pipe);
temp = I915_READ(reg);
if (HAS_PCH_CPT(dev_priv)) {
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
struct drm_i915_private *dev_priv = to_i915(dev);
struct intel_crtc *crtc;
for_each_intel_crtc(dev, crtc) {
if (atomic_read(&crtc->unpin_work_count) == 0)
continue;
if (crtc->flip_work)
intel_wait_for_vblank(dev_priv, crtc->pipe);
return true;
}
return false;
}
static void page_flip_completed(struct intel_crtc *intel_crtc)
{
struct drm_i915_private *dev_priv = to_i915(intel_crtc->base.dev);
struct intel_flip_work *work = intel_crtc->flip_work;
intel_crtc->flip_work = NULL;
if (work->event)
drm_crtc_send_vblank_event(&intel_crtc->base, work->event);
drm_crtc_vblank_put(&intel_crtc->base);
wake_up_all(&dev_priv->pending_flip_queue);
trace_i915_flip_complete(intel_crtc->plane,
work->pending_flip_obj);
queue_work(dev_priv->wq, &work->unpin_work);
}
static int intel_crtc_wait_for_pending_flips(struct drm_crtc *crtc)
{
struct drm_device *dev = crtc->dev;
struct drm_i915_private *dev_priv = to_i915(dev);
long ret;
WARN_ON(waitqueue_active(&dev_priv->pending_flip_queue));
ret = wait_event_interruptible_timeout(
dev_priv->pending_flip_queue,
!intel_crtc_has_pending_flip(crtc),
60*HZ);
if (ret < 0)
return ret;
if (ret == 0) {
struct intel_crtc *intel_crtc = to_intel_crtc(crtc);
struct intel_flip_work *work;
spin_lock_irq(&dev->event_lock);
work = intel_crtc->flip_work;
if (work && !is_mmio_work(work)) {
WARN_ONCE(1, "Removing stuck page flip\n");
page_flip_completed(intel_crtc);
}
spin_unlock_irq(&dev->event_lock);
}
return 0;
}
void lpt_disable_iclkip(struct drm_i915_private *dev_priv)
{
u32 temp;
I915_WRITE(PIXCLK_GATE, PIXCLK_GATE_GATE);
mutex_lock(&dev_priv->sb_lock);
temp = intel_sbi_read(dev_priv, SBI_SSCCTL6, SBI_ICLK);
temp |= SBI_SSCCTL_DISABLE;
intel_sbi_write(dev_priv, SBI_SSCCTL6, temp, SBI_ICLK);
mutex_unlock(&dev_priv->sb_lock);
}
static void lpt_program_iclkip(struct drm_crtc *crtc)
{
struct drm_i915_private *dev_priv = to_i915(crtc->dev);
int clock = to_intel_crtc(crtc)->config->base.adjusted_mode.crtc_clock;
u32 divsel, phaseinc, auxdiv, phasedir = 0;
u32 temp;
lpt_disable_iclkip(dev_priv);
for (auxdiv = 0; auxdiv < 2; auxdiv++) {
u32 iclk_virtual_root_freq = 172800 * 1000;
u32 iclk_pi_range = 64;
u32 desired_divisor;
desired_divisor = DIV_ROUND_CLOSEST(iclk_virtual_root_freq,
clock << auxdiv);
divsel = (desired_divisor / iclk_pi_range) - 2;
phaseinc = desired_divisor % iclk_pi_range;
if (divsel <= 0x7f)
break;
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
mutex_lock(&dev_priv->sb_lock);
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
mutex_unlock(&dev_priv->sb_lock);
udelay(24);
I915_WRITE(PIXCLK_GATE, PIXCLK_GATE_UNGATE);
}
int lpt_get_iclkip(struct drm_i915_private *dev_priv)
{
u32 divsel, phaseinc, auxdiv;
u32 iclk_virtual_root_freq = 172800 * 1000;
u32 iclk_pi_range = 64;
u32 desired_divisor;
u32 temp;
if ((I915_READ(PIXCLK_GATE) & PIXCLK_GATE_UNGATE) == 0)
return 0;
mutex_lock(&dev_priv->sb_lock);
temp = intel_sbi_read(dev_priv, SBI_SSCCTL6, SBI_ICLK);
if (temp & SBI_SSCCTL_DISABLE) {
mutex_unlock(&dev_priv->sb_lock);
return 0;
}
temp = intel_sbi_read(dev_priv, SBI_SSCDIVINTPHASE6, SBI_ICLK);
divsel = (temp & SBI_SSCDIVINTPHASE_DIVSEL_MASK) >>
SBI_SSCDIVINTPHASE_DIVSEL_SHIFT;
phaseinc = (temp & SBI_SSCDIVINTPHASE_INCVAL_MASK) >>
SBI_SSCDIVINTPHASE_INCVAL_SHIFT;
temp = intel_sbi_read(dev_priv, SBI_SSCAUXDIV6, SBI_ICLK);
auxdiv = (temp & SBI_SSCAUXDIV_FINALDIV2SEL_MASK) >>
SBI_SSCAUXDIV_FINALDIV2SEL_SHIFT;
mutex_unlock(&dev_priv->sb_lock);
desired_divisor = (divsel + 2) * iclk_pi_range + phaseinc;
return DIV_ROUND_CLOSEST(iclk_virtual_root_freq,
desired_divisor << auxdiv);
}
static void ironlake_pch_transcoder_set_timings(struct intel_crtc *crtc,
enum pipe pch_transcoder)
{
struct drm_device *dev = crtc->base.dev;
struct drm_i915_private *dev_priv = to_i915(dev);
enum transcoder cpu_transcoder = crtc->config->cpu_transcoder;
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
static void cpt_set_fdi_bc_bifurcation(struct drm_device *dev, bool enable)
{
struct drm_i915_private *dev_priv = to_i915(dev);
uint32_t temp;
temp = I915_READ(SOUTH_CHICKEN1);
if (!!(temp & FDI_BC_BIFURCATION_SELECT) == enable)
return;
WARN_ON(I915_READ(FDI_RX_CTL(PIPE_B)) & FDI_RX_ENABLE);
WARN_ON(I915_READ(FDI_RX_CTL(PIPE_C)) & FDI_RX_ENABLE);
temp &= ~FDI_BC_BIFURCATION_SELECT;
if (enable)
temp |= FDI_BC_BIFURCATION_SELECT;
DRM_DEBUG_KMS("%sabling fdi C rx\n", enable ? "en" : "dis");
I915_WRITE(SOUTH_CHICKEN1, temp);
POSTING_READ(SOUTH_CHICKEN1);
}
static void ivybridge_update_fdi_bc_bifurcation(struct intel_crtc *intel_crtc)
{
struct drm_device *dev = intel_crtc->base.dev;
switch (intel_crtc->pipe) {
case PIPE_A:
break;
case PIPE_B:
if (intel_crtc->config->fdi_lanes > 2)
cpt_set_fdi_bc_bifurcation(dev, false);
else
cpt_set_fdi_bc_bifurcation(dev, true);
break;
case PIPE_C:
cpt_set_fdi_bc_bifurcation(dev, true);
break;
default:
BUG();
}
}
static enum port
intel_trans_dp_port_sel(struct drm_crtc *crtc)
{
struct drm_device *dev = crtc->dev;
struct intel_encoder *encoder;
for_each_encoder_on_crtc(dev, crtc, encoder) {
if (encoder->type == INTEL_OUTPUT_DP ||
encoder->type == INTEL_OUTPUT_EDP)
return enc_to_dig_port(&encoder->base)->port;
}
return -1;
}
static void ironlake_pch_enable(struct drm_crtc *crtc)
{
struct drm_device *dev = crtc->dev;
struct drm_i915_private *dev_priv = to_i915(dev);
struct intel_crtc *intel_crtc = to_intel_crtc(crtc);
int pipe = intel_crtc->pipe;
u32 temp;
assert_pch_transcoder_disabled(dev_priv, pipe);
if (IS_IVYBRIDGE(dev_priv))
ivybridge_update_fdi_bc_bifurcation(intel_crtc);
I915_WRITE(FDI_RX_TUSIZE1(pipe),
I915_READ(PIPE_DATA_M1(pipe)) & TU_SIZE_MASK);
dev_priv->display.fdi_link_train(crtc);
if (HAS_PCH_CPT(dev_priv)) {
u32 sel;
temp = I915_READ(PCH_DPLL_SEL);
temp |= TRANS_DPLL_ENABLE(pipe);
sel = TRANS_DPLLB_SEL(pipe);
if (intel_crtc->config->shared_dpll ==
intel_get_shared_dpll_by_id(dev_priv, DPLL_ID_PCH_PLL_B))
temp |= sel;
else
temp &= ~sel;
I915_WRITE(PCH_DPLL_SEL, temp);
}
intel_enable_shared_dpll(intel_crtc);
assert_panel_unlocked(dev_priv, pipe);
ironlake_pch_transcoder_set_timings(intel_crtc, pipe);
intel_fdi_normal_train(crtc);
if (HAS_PCH_CPT(dev_priv) &&
intel_crtc_has_dp_encoder(intel_crtc->config)) {
const struct drm_display_mode *adjusted_mode =
&intel_crtc->config->base.adjusted_mode;
u32 bpc = (I915_READ(PIPECONF(pipe)) & PIPECONF_BPC_MASK) >> 5;
i915_reg_t reg = TRANS_DP_CTL(pipe);
temp = I915_READ(reg);
temp &= ~(TRANS_DP_PORT_SEL_MASK |
TRANS_DP_SYNC_MASK |
TRANS_DP_BPC_MASK);
temp |= TRANS_DP_OUTPUT_ENABLE;
temp |= bpc << 9;
if (adjusted_mode->flags & DRM_MODE_FLAG_PHSYNC)
temp |= TRANS_DP_HSYNC_ACTIVE_HIGH;
if (adjusted_mode->flags & DRM_MODE_FLAG_PVSYNC)
temp |= TRANS_DP_VSYNC_ACTIVE_HIGH;
switch (intel_trans_dp_port_sel(crtc)) {
case PORT_B:
temp |= TRANS_DP_PORT_SEL_B;
break;
case PORT_C:
temp |= TRANS_DP_PORT_SEL_C;
break;
case PORT_D:
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
struct drm_i915_private *dev_priv = to_i915(dev);
struct intel_crtc *intel_crtc = to_intel_crtc(crtc);
enum transcoder cpu_transcoder = intel_crtc->config->cpu_transcoder;
assert_pch_transcoder_disabled(dev_priv, TRANSCODER_A);
lpt_program_iclkip(crtc);
ironlake_pch_transcoder_set_timings(intel_crtc, PIPE_A);
lpt_enable_pch_transcoder(dev_priv, cpu_transcoder);
}
static void cpt_verify_modeset(struct drm_device *dev, int pipe)
{
struct drm_i915_private *dev_priv = to_i915(dev);
i915_reg_t dslreg = PIPEDSL(pipe);
u32 temp;
temp = I915_READ(dslreg);
udelay(500);
if (wait_for(I915_READ(dslreg) != temp, 5)) {
if (wait_for(I915_READ(dslreg) != temp, 5))
DRM_ERROR("mode set failed: pipe %c stuck\n", pipe_name(pipe));
}
}
static int
skl_update_scaler(struct intel_crtc_state *crtc_state, bool force_detach,
unsigned scaler_user, int *scaler_id, unsigned int rotation,
int src_w, int src_h, int dst_w, int dst_h)
{
struct intel_crtc_scaler_state *scaler_state =
&crtc_state->scaler_state;
struct intel_crtc *intel_crtc =
to_intel_crtc(crtc_state->base.crtc);
int need_scaling;
need_scaling = drm_rotation_90_or_270(rotation) ?
(src_h != dst_w || src_w != dst_h):
(src_w != dst_w || src_h != dst_h);
if (force_detach || !need_scaling) {
if (*scaler_id >= 0) {
scaler_state->scaler_users &= ~(1 << scaler_user);
scaler_state->scalers[*scaler_id].in_use = 0;
DRM_DEBUG_KMS("scaler_user index %u.%u: "
"Staged freeing scaler id %d scaler_users = 0x%x\n",
intel_crtc->pipe, scaler_user, *scaler_id,
scaler_state->scaler_users);
*scaler_id = -1;
}
return 0;
}
if (src_w < SKL_MIN_SRC_W || src_h < SKL_MIN_SRC_H ||
dst_w < SKL_MIN_DST_W || dst_h < SKL_MIN_DST_H ||
src_w > SKL_MAX_SRC_W || src_h > SKL_MAX_SRC_H ||
dst_w > SKL_MAX_DST_W || dst_h > SKL_MAX_DST_H) {
DRM_DEBUG_KMS("scaler_user index %u.%u: src %ux%u dst %ux%u "
"size is out of scaler range\n",
intel_crtc->pipe, scaler_user, src_w, src_h, dst_w, dst_h);
return -EINVAL;
}
scaler_state->scaler_users |= (1 << scaler_user);
DRM_DEBUG_KMS("scaler_user index %u.%u: "
"staged scaling request for %ux%u->%ux%u scaler_users = 0x%x\n",
intel_crtc->pipe, scaler_user, src_w, src_h, dst_w, dst_h,
scaler_state->scaler_users);
return 0;
}
int skl_update_scaler_crtc(struct intel_crtc_state *state)
{
const struct drm_display_mode *adjusted_mode = &state->base.adjusted_mode;
return skl_update_scaler(state, !state->base.active, SKL_CRTC_INDEX,
&state->scaler_state.scaler_id, DRM_ROTATE_0,
state->pipe_src_w, state->pipe_src_h,
adjusted_mode->crtc_hdisplay, adjusted_mode->crtc_vdisplay);
}
static int skl_update_scaler_plane(struct intel_crtc_state *crtc_state,
struct intel_plane_state *plane_state)
{
struct intel_plane *intel_plane =
to_intel_plane(plane_state->base.plane);
struct drm_framebuffer *fb = plane_state->base.fb;
int ret;
bool force_detach = !fb || !plane_state->base.visible;
ret = skl_update_scaler(crtc_state, force_detach,
drm_plane_index(&intel_plane->base),
&plane_state->scaler_id,
plane_state->base.rotation,
drm_rect_width(&plane_state->base.src) >> 16,
drm_rect_height(&plane_state->base.src) >> 16,
drm_rect_width(&plane_state->base.dst),
drm_rect_height(&plane_state->base.dst));
if (ret || plane_state->scaler_id < 0)
return ret;
if (plane_state->ckey.flags != I915_SET_COLORKEY_NONE) {
DRM_DEBUG_KMS("[PLANE:%d:%s] scaling with color key not allowed",
intel_plane->base.base.id,
intel_plane->base.name);
return -EINVAL;
}
switch (fb->pixel_format) {
case DRM_FORMAT_RGB565:
case DRM_FORMAT_XBGR8888:
case DRM_FORMAT_XRGB8888:
case DRM_FORMAT_ABGR8888:
case DRM_FORMAT_ARGB8888:
case DRM_FORMAT_XRGB2101010:
case DRM_FORMAT_XBGR2101010:
case DRM_FORMAT_YUYV:
case DRM_FORMAT_YVYU:
case DRM_FORMAT_UYVY:
case DRM_FORMAT_VYUY:
break;
default:
DRM_DEBUG_KMS("[PLANE:%d:%s] FB:%d unsupported scaling format 0x%x\n",
intel_plane->base.base.id, intel_plane->base.name,
fb->base.id, fb->pixel_format);
return -EINVAL;
}
return 0;
}
static void skylake_scaler_disable(struct intel_crtc *crtc)
{
int i;
for (i = 0; i < crtc->num_scalers; i++)
skl_detach_scaler(crtc, i);
}
static void skylake_pfit_enable(struct intel_crtc *crtc)
{
struct drm_device *dev = crtc->base.dev;
struct drm_i915_private *dev_priv = to_i915(dev);
int pipe = crtc->pipe;
struct intel_crtc_scaler_state *scaler_state =
&crtc->config->scaler_state;
DRM_DEBUG_KMS("for crtc_state = %p\n", crtc->config);
if (crtc->config->pch_pfit.enabled) {
int id;
if (WARN_ON(crtc->config->scaler_state.scaler_id < 0)) {
DRM_ERROR("Requesting pfit without getting a scaler first\n");
return;
}
id = scaler_state->scaler_id;
I915_WRITE(SKL_PS_CTRL(pipe, id), PS_SCALER_EN |
PS_FILTER_MEDIUM | scaler_state->scalers[id].mode);
I915_WRITE(SKL_PS_WIN_POS(pipe, id), crtc->config->pch_pfit.pos);
I915_WRITE(SKL_PS_WIN_SZ(pipe, id), crtc->config->pch_pfit.size);
DRM_DEBUG_KMS("for crtc_state = %p scaler_id = %d\n", crtc->config, id);
}
}
static void ironlake_pfit_enable(struct intel_crtc *crtc)
{
struct drm_device *dev = crtc->base.dev;
struct drm_i915_private *dev_priv = to_i915(dev);
int pipe = crtc->pipe;
if (crtc->config->pch_pfit.enabled) {
if (IS_IVYBRIDGE(dev_priv) || IS_HASWELL(dev_priv))
I915_WRITE(PF_CTL(pipe), PF_ENABLE | PF_FILTER_MED_3x3 |
PF_PIPE_SEL_IVB(pipe));
else
I915_WRITE(PF_CTL(pipe), PF_ENABLE | PF_FILTER_MED_3x3);
I915_WRITE(PF_WIN_POS(pipe), crtc->config->pch_pfit.pos);
I915_WRITE(PF_WIN_SZ(pipe), crtc->config->pch_pfit.size);
}
}
void hsw_enable_ips(struct intel_crtc *crtc)
{
struct drm_device *dev = crtc->base.dev;
struct drm_i915_private *dev_priv = to_i915(dev);
if (!crtc->config->ips_enabled)
return;
assert_plane_enabled(dev_priv, crtc->plane);
if (IS_BROADWELL(dev_priv)) {
mutex_lock(&dev_priv->rps.hw_lock);
WARN_ON(sandybridge_pcode_write(dev_priv, DISPLAY_IPS_CONTROL, 0xc0000000));
mutex_unlock(&dev_priv->rps.hw_lock);
} else {
I915_WRITE(IPS_CTL, IPS_ENABLE);
if (intel_wait_for_register(dev_priv,
IPS_CTL, IPS_ENABLE, IPS_ENABLE,
50))
DRM_ERROR("Timed out waiting for IPS enable\n");
}
}
void hsw_disable_ips(struct intel_crtc *crtc)
{
struct drm_device *dev = crtc->base.dev;
struct drm_i915_private *dev_priv = to_i915(dev);
if (!crtc->config->ips_enabled)
return;
assert_plane_enabled(dev_priv, crtc->plane);
if (IS_BROADWELL(dev_priv)) {
mutex_lock(&dev_priv->rps.hw_lock);
WARN_ON(sandybridge_pcode_write(dev_priv, DISPLAY_IPS_CONTROL, 0));
mutex_unlock(&dev_priv->rps.hw_lock);
if (intel_wait_for_register(dev_priv,
IPS_CTL, IPS_ENABLE, 0,
42))
DRM_ERROR("Timed out waiting for IPS disable\n");
} else {
I915_WRITE(IPS_CTL, 0);
POSTING_READ(IPS_CTL);
}
intel_wait_for_vblank(dev_priv, crtc->pipe);
}
static void intel_crtc_dpms_overlay_disable(struct intel_crtc *intel_crtc)
{
if (intel_crtc->overlay) {
struct drm_device *dev = intel_crtc->base.dev;
struct drm_i915_private *dev_priv = to_i915(dev);
mutex_lock(&dev->struct_mutex);
dev_priv->mm.interruptible = false;
(void) intel_overlay_switch_off(intel_crtc->overlay);
dev_priv->mm.interruptible = true;
mutex_unlock(&dev->struct_mutex);
}
}
static void
intel_post_enable_primary(struct drm_crtc *crtc)
{
struct drm_device *dev = crtc->dev;
struct drm_i915_private *dev_priv = to_i915(dev);
struct intel_crtc *intel_crtc = to_intel_crtc(crtc);
int pipe = intel_crtc->pipe;
hsw_enable_ips(intel_crtc);
if (IS_GEN2(dev_priv))
intel_set_cpu_fifo_underrun_reporting(dev_priv, pipe, true);
intel_check_cpu_fifo_underruns(dev_priv);
intel_check_pch_fifo_underruns(dev_priv);
}
static void
intel_pre_disable_primary(struct drm_crtc *crtc)
{
struct drm_device *dev = crtc->dev;
struct drm_i915_private *dev_priv = to_i915(dev);
struct intel_crtc *intel_crtc = to_intel_crtc(crtc);
int pipe = intel_crtc->pipe;
if (IS_GEN2(dev_priv))
intel_set_cpu_fifo_underrun_reporting(dev_priv, pipe, false);
hsw_disable_ips(intel_crtc);
}
static void
intel_pre_disable_primary_noatomic(struct drm_crtc *crtc)
{
struct drm_device *dev = crtc->dev;
struct drm_i915_private *dev_priv = to_i915(dev);
struct intel_crtc *intel_crtc = to_intel_crtc(crtc);
int pipe = intel_crtc->pipe;
intel_pre_disable_primary(crtc);
if (HAS_GMCH_DISPLAY(dev_priv)) {
intel_set_memory_cxsr(dev_priv, false);
dev_priv->wm.vlv.cxsr = false;
intel_wait_for_vblank(dev_priv, pipe);
}
}
static void intel_post_plane_update(struct intel_crtc_state *old_crtc_state)
{
struct intel_crtc *crtc = to_intel_crtc(old_crtc_state->base.crtc);
struct drm_atomic_state *old_state = old_crtc_state->base.state;
struct intel_crtc_state *pipe_config =
to_intel_crtc_state(crtc->base.state);
struct drm_plane *primary = crtc->base.primary;
struct drm_plane_state *old_pri_state =
drm_atomic_get_existing_plane_state(old_state, primary);
intel_frontbuffer_flip(to_i915(crtc->base.dev), pipe_config->fb_bits);
crtc->wm.cxsr_allowed = true;
if (pipe_config->update_wm_post && pipe_config->base.active)
intel_update_watermarks(crtc);
if (old_pri_state) {
struct intel_plane_state *primary_state =
to_intel_plane_state(primary->state);
struct intel_plane_state *old_primary_state =
to_intel_plane_state(old_pri_state);
intel_fbc_post_update(crtc);
if (primary_state->base.visible &&
(needs_modeset(&pipe_config->base) ||
!old_primary_state->base.visible))
intel_post_enable_primary(&crtc->base);
}
}
static void intel_pre_plane_update(struct intel_crtc_state *old_crtc_state)
{
struct intel_crtc *crtc = to_intel_crtc(old_crtc_state->base.crtc);
struct drm_device *dev = crtc->base.dev;
struct drm_i915_private *dev_priv = to_i915(dev);
struct intel_crtc_state *pipe_config =
to_intel_crtc_state(crtc->base.state);
struct drm_atomic_state *old_state = old_crtc_state->base.state;
struct drm_plane *primary = crtc->base.primary;
struct drm_plane_state *old_pri_state =
drm_atomic_get_existing_plane_state(old_state, primary);
bool modeset = needs_modeset(&pipe_config->base);
struct intel_atomic_state *old_intel_state =
to_intel_atomic_state(old_state);
if (old_pri_state) {
struct intel_plane_state *primary_state =
to_intel_plane_state(primary->state);
struct intel_plane_state *old_primary_state =
to_intel_plane_state(old_pri_state);
intel_fbc_pre_update(crtc, pipe_config, primary_state);
if (old_primary_state->base.visible &&
(modeset || !primary_state->base.visible))
intel_pre_disable_primary(&crtc->base);
}
if (pipe_config->disable_cxsr && HAS_GMCH_DISPLAY(dev_priv)) {
crtc->wm.cxsr_allowed = false;
if (old_crtc_state->base.active) {
intel_set_memory_cxsr(dev_priv, false);
dev_priv->wm.vlv.cxsr = false;
intel_wait_for_vblank(dev_priv, crtc->pipe);
}
}
if (pipe_config->disable_lp_wm) {
ilk_disable_lp_wm(dev);
intel_wait_for_vblank(dev_priv, crtc->pipe);
}
if (needs_modeset(&pipe_config->base))
return;
if (dev_priv->display.initial_watermarks != NULL)
dev_priv->display.initial_watermarks(old_intel_state,
pipe_config);
else if (pipe_config->update_wm_pre)
intel_update_watermarks(crtc);
}
static void intel_crtc_disable_planes(struct drm_crtc *crtc, unsigned plane_mask)
{
struct drm_device *dev = crtc->dev;
struct intel_crtc *intel_crtc = to_intel_crtc(crtc);
struct drm_plane *p;
int pipe = intel_crtc->pipe;
intel_crtc_dpms_overlay_disable(intel_crtc);
drm_for_each_plane_mask(p, dev, plane_mask)
to_intel_plane(p)->disable_plane(p, crtc);
intel_frontbuffer_flip(to_i915(dev), INTEL_FRONTBUFFER_ALL_MASK(pipe));
}
static void intel_encoders_pre_pll_enable(struct drm_crtc *crtc,
struct intel_crtc_state *crtc_state,
struct drm_atomic_state *old_state)
{
struct drm_connector_state *old_conn_state;
struct drm_connector *conn;
int i;
for_each_connector_in_state(old_state, conn, old_conn_state, i) {
struct drm_connector_state *conn_state = conn->state;
struct intel_encoder *encoder =
to_intel_encoder(conn_state->best_encoder);
if (conn_state->crtc != crtc)
continue;
if (encoder->pre_pll_enable)
encoder->pre_pll_enable(encoder, crtc_state, conn_state);
}
}
static void intel_encoders_pre_enable(struct drm_crtc *crtc,
struct intel_crtc_state *crtc_state,
struct drm_atomic_state *old_state)
{
struct drm_connector_state *old_conn_state;
struct drm_connector *conn;
int i;
for_each_connector_in_state(old_state, conn, old_conn_state, i) {
struct drm_connector_state *conn_state = conn->state;
struct intel_encoder *encoder =
to_intel_encoder(conn_state->best_encoder);
if (conn_state->crtc != crtc)
continue;
if (encoder->pre_enable)
encoder->pre_enable(encoder, crtc_state, conn_state);
}
}
static void intel_encoders_enable(struct drm_crtc *crtc,
struct intel_crtc_state *crtc_state,
struct drm_atomic_state *old_state)
{
struct drm_connector_state *old_conn_state;
struct drm_connector *conn;
int i;
for_each_connector_in_state(old_state, conn, old_conn_state, i) {
struct drm_connector_state *conn_state = conn->state;
struct intel_encoder *encoder =
to_intel_encoder(conn_state->best_encoder);
if (conn_state->crtc != crtc)
continue;
encoder->enable(encoder, crtc_state, conn_state);
intel_opregion_notify_encoder(encoder, true);
}
}
static void intel_encoders_disable(struct drm_crtc *crtc,
struct intel_crtc_state *old_crtc_state,
struct drm_atomic_state *old_state)
{
struct drm_connector_state *old_conn_state;
struct drm_connector *conn;
int i;
for_each_connector_in_state(old_state, conn, old_conn_state, i) {
struct intel_encoder *encoder =
to_intel_encoder(old_conn_state->best_encoder);
if (old_conn_state->crtc != crtc)
continue;
intel_opregion_notify_encoder(encoder, false);
encoder->disable(encoder, old_crtc_state, old_conn_state);
}
}
static void intel_encoders_post_disable(struct drm_crtc *crtc,
struct intel_crtc_state *old_crtc_state,
struct drm_atomic_state *old_state)
{
struct drm_connector_state *old_conn_state;
struct drm_connector *conn;
int i;
for_each_connector_in_state(old_state, conn, old_conn_state, i) {
struct intel_encoder *encoder =
to_intel_encoder(old_conn_state->best_encoder);
if (old_conn_state->crtc != crtc)
continue;
if (encoder->post_disable)
encoder->post_disable(encoder, old_crtc_state, old_conn_state);
}
}
static void intel_encoders_post_pll_disable(struct drm_crtc *crtc,
struct intel_crtc_state *old_crtc_state,
struct drm_atomic_state *old_state)
{
struct drm_connector_state *old_conn_state;
struct drm_connector *conn;
int i;
for_each_connector_in_state(old_state, conn, old_conn_state, i) {
struct intel_encoder *encoder =
to_intel_encoder(old_conn_state->best_encoder);
if (old_conn_state->crtc != crtc)
continue;
if (encoder->post_pll_disable)
encoder->post_pll_disable(encoder, old_crtc_state, old_conn_state);
}
}
static void ironlake_crtc_enable(struct intel_crtc_state *pipe_config,
struct drm_atomic_state *old_state)
{
struct drm_crtc *crtc = pipe_config->base.crtc;
struct drm_device *dev = crtc->dev;
struct drm_i915_private *dev_priv = to_i915(dev);
struct intel_crtc *intel_crtc = to_intel_crtc(crtc);
int pipe = intel_crtc->pipe;
struct intel_atomic_state *old_intel_state =
to_intel_atomic_state(old_state);
if (WARN_ON(intel_crtc->active))
return;
if (intel_crtc->config->has_pch_encoder || IS_GEN5(dev_priv))
intel_set_cpu_fifo_underrun_reporting(dev_priv, pipe, false);
if (intel_crtc->config->has_pch_encoder)
intel_set_pch_fifo_underrun_reporting(dev_priv, pipe, false);
if (intel_crtc->config->has_pch_encoder)
intel_prepare_shared_dpll(intel_crtc);
if (intel_crtc_has_dp_encoder(intel_crtc->config))
intel_dp_set_m_n(intel_crtc, M1_N1);
intel_set_pipe_timings(intel_crtc);
intel_set_pipe_src_size(intel_crtc);
if (intel_crtc->config->has_pch_encoder) {
intel_cpu_transcoder_set_m_n(intel_crtc,
&intel_crtc->config->fdi_m_n, NULL);
}
ironlake_set_pipeconf(crtc);
intel_crtc->active = true;
intel_encoders_pre_enable(crtc, pipe_config, old_state);
if (intel_crtc->config->has_pch_encoder) {
ironlake_fdi_pll_enable(intel_crtc);
} else {
assert_fdi_tx_disabled(dev_priv, pipe);
assert_fdi_rx_disabled(dev_priv, pipe);
}
ironlake_pfit_enable(intel_crtc);
intel_color_load_luts(&pipe_config->base);
if (dev_priv->display.initial_watermarks != NULL)
dev_priv->display.initial_watermarks(old_intel_state, intel_crtc->config);
intel_enable_pipe(intel_crtc);
if (intel_crtc->config->has_pch_encoder)
ironlake_pch_enable(crtc);
assert_vblank_disabled(crtc);
drm_crtc_vblank_on(crtc);
intel_encoders_enable(crtc, pipe_config, old_state);
if (HAS_PCH_CPT(dev_priv))
cpt_verify_modeset(dev, intel_crtc->pipe);
if (intel_crtc->config->has_pch_encoder)
intel_wait_for_vblank(dev_priv, pipe);
intel_set_cpu_fifo_underrun_reporting(dev_priv, pipe, true);
intel_set_pch_fifo_underrun_reporting(dev_priv, pipe, true);
}
static bool hsw_crtc_supports_ips(struct intel_crtc *crtc)
{
return HAS_IPS(to_i915(crtc->base.dev)) && crtc->pipe == PIPE_A;
}
static void haswell_crtc_enable(struct intel_crtc_state *pipe_config,
struct drm_atomic_state *old_state)
{
struct drm_crtc *crtc = pipe_config->base.crtc;
struct drm_i915_private *dev_priv = to_i915(crtc->dev);
struct intel_crtc *intel_crtc = to_intel_crtc(crtc);
int pipe = intel_crtc->pipe, hsw_workaround_pipe;
enum transcoder cpu_transcoder = intel_crtc->config->cpu_transcoder;
struct intel_atomic_state *old_intel_state =
to_intel_atomic_state(old_state);
if (WARN_ON(intel_crtc->active))
return;
if (intel_crtc->config->has_pch_encoder)
intel_set_pch_fifo_underrun_reporting(dev_priv, TRANSCODER_A,
false);
intel_encoders_pre_pll_enable(crtc, pipe_config, old_state);
if (intel_crtc->config->shared_dpll)
intel_enable_shared_dpll(intel_crtc);
if (intel_crtc_has_dp_encoder(intel_crtc->config))
intel_dp_set_m_n(intel_crtc, M1_N1);
if (!transcoder_is_dsi(cpu_transcoder))
intel_set_pipe_timings(intel_crtc);
intel_set_pipe_src_size(intel_crtc);
if (cpu_transcoder != TRANSCODER_EDP &&
!transcoder_is_dsi(cpu_transcoder)) {
I915_WRITE(PIPE_MULT(cpu_transcoder),
intel_crtc->config->pixel_multiplier - 1);
}
if (intel_crtc->config->has_pch_encoder) {
intel_cpu_transcoder_set_m_n(intel_crtc,
&intel_crtc->config->fdi_m_n, NULL);
}
if (!transcoder_is_dsi(cpu_transcoder))
haswell_set_pipeconf(crtc);
haswell_set_pipemisc(crtc);
intel_color_set_csc(&pipe_config->base);
intel_crtc->active = true;
if (intel_crtc->config->has_pch_encoder)
intel_set_cpu_fifo_underrun_reporting(dev_priv, pipe, false);
else
intel_set_cpu_fifo_underrun_reporting(dev_priv, pipe, true);
intel_encoders_pre_enable(crtc, pipe_config, old_state);
if (intel_crtc->config->has_pch_encoder)
dev_priv->display.fdi_link_train(crtc);
if (!transcoder_is_dsi(cpu_transcoder))
intel_ddi_enable_pipe_clock(intel_crtc);
if (INTEL_GEN(dev_priv) >= 9)
skylake_pfit_enable(intel_crtc);
else
ironlake_pfit_enable(intel_crtc);
intel_color_load_luts(&pipe_config->base);
intel_ddi_set_pipe_settings(crtc);
if (!transcoder_is_dsi(cpu_transcoder))
intel_ddi_enable_transcoder_func(crtc);
if (dev_priv->display.initial_watermarks != NULL)
dev_priv->display.initial_watermarks(old_intel_state,
pipe_config);
else
intel_update_watermarks(intel_crtc);
if (!transcoder_is_dsi(cpu_transcoder))
intel_enable_pipe(intel_crtc);
if (intel_crtc->config->has_pch_encoder)
lpt_pch_enable(crtc);
if (intel_crtc_has_type(intel_crtc->config, INTEL_OUTPUT_DP_MST))
intel_ddi_set_vc_payload_alloc(crtc, true);
assert_vblank_disabled(crtc);
drm_crtc_vblank_on(crtc);
intel_encoders_enable(crtc, pipe_config, old_state);
if (intel_crtc->config->has_pch_encoder) {
intel_wait_for_vblank(dev_priv, pipe);
intel_wait_for_vblank(dev_priv, pipe);
intel_set_cpu_fifo_underrun_reporting(dev_priv, pipe, true);
intel_set_pch_fifo_underrun_reporting(dev_priv, TRANSCODER_A,
true);
}
hsw_workaround_pipe = pipe_config->hsw_workaround_pipe;
if (IS_HASWELL(dev_priv) && hsw_workaround_pipe != INVALID_PIPE) {
intel_wait_for_vblank(dev_priv, hsw_workaround_pipe);
intel_wait_for_vblank(dev_priv, hsw_workaround_pipe);
}
}
static void ironlake_pfit_disable(struct intel_crtc *crtc, bool force)
{
struct drm_device *dev = crtc->base.dev;
struct drm_i915_private *dev_priv = to_i915(dev);
int pipe = crtc->pipe;
if (force || crtc->config->pch_pfit.enabled) {
I915_WRITE(PF_CTL(pipe), 0);
I915_WRITE(PF_WIN_POS(pipe), 0);
I915_WRITE(PF_WIN_SZ(pipe), 0);
}
}
static void ironlake_crtc_disable(struct intel_crtc_state *old_crtc_state,
struct drm_atomic_state *old_state)
{
struct drm_crtc *crtc = old_crtc_state->base.crtc;
struct drm_device *dev = crtc->dev;
struct drm_i915_private *dev_priv = to_i915(dev);
struct intel_crtc *intel_crtc = to_intel_crtc(crtc);
int pipe = intel_crtc->pipe;
if (intel_crtc->config->has_pch_encoder) {
intel_set_cpu_fifo_underrun_reporting(dev_priv, pipe, false);
intel_set_pch_fifo_underrun_reporting(dev_priv, pipe, false);
}
intel_encoders_disable(crtc, old_crtc_state, old_state);
drm_crtc_vblank_off(crtc);
assert_vblank_disabled(crtc);
intel_disable_pipe(intel_crtc);
ironlake_pfit_disable(intel_crtc, false);
if (intel_crtc->config->has_pch_encoder)
ironlake_fdi_disable(crtc);
intel_encoders_post_disable(crtc, old_crtc_state, old_state);
if (intel_crtc->config->has_pch_encoder) {
ironlake_disable_pch_transcoder(dev_priv, pipe);
if (HAS_PCH_CPT(dev_priv)) {
i915_reg_t reg;
u32 temp;
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
ironlake_fdi_pll_disable(intel_crtc);
}
intel_set_cpu_fifo_underrun_reporting(dev_priv, pipe, true);
intel_set_pch_fifo_underrun_reporting(dev_priv, pipe, true);
}
static void haswell_crtc_disable(struct intel_crtc_state *old_crtc_state,
struct drm_atomic_state *old_state)
{
struct drm_crtc *crtc = old_crtc_state->base.crtc;
struct drm_i915_private *dev_priv = to_i915(crtc->dev);
struct intel_crtc *intel_crtc = to_intel_crtc(crtc);
enum transcoder cpu_transcoder = intel_crtc->config->cpu_transcoder;
if (intel_crtc->config->has_pch_encoder)
intel_set_pch_fifo_underrun_reporting(dev_priv, TRANSCODER_A,
false);
intel_encoders_disable(crtc, old_crtc_state, old_state);
drm_crtc_vblank_off(crtc);
assert_vblank_disabled(crtc);
if (!transcoder_is_dsi(cpu_transcoder))
intel_disable_pipe(intel_crtc);
if (intel_crtc_has_type(intel_crtc->config, INTEL_OUTPUT_DP_MST))
intel_ddi_set_vc_payload_alloc(crtc, false);
if (!transcoder_is_dsi(cpu_transcoder))
intel_ddi_disable_transcoder_func(dev_priv, cpu_transcoder);
if (INTEL_GEN(dev_priv) >= 9)
skylake_scaler_disable(intel_crtc);
else
ironlake_pfit_disable(intel_crtc, false);
if (!transcoder_is_dsi(cpu_transcoder))
intel_ddi_disable_pipe_clock(intel_crtc);
intel_encoders_post_disable(crtc, old_crtc_state, old_state);
if (old_crtc_state->has_pch_encoder)
intel_set_pch_fifo_underrun_reporting(dev_priv, TRANSCODER_A,
true);
}
static void i9xx_pfit_enable(struct intel_crtc *crtc)
{
struct drm_device *dev = crtc->base.dev;
struct drm_i915_private *dev_priv = to_i915(dev);
struct intel_crtc_state *pipe_config = crtc->config;
if (!pipe_config->gmch_pfit.control)
return;
WARN_ON(I915_READ(PFIT_CONTROL) & PFIT_ENABLE);
assert_pipe_disabled(dev_priv, crtc->pipe);
I915_WRITE(PFIT_PGM_RATIOS, pipe_config->gmch_pfit.pgm_ratios);
I915_WRITE(PFIT_CONTROL, pipe_config->gmch_pfit.control);
I915_WRITE(BCLRPAT(crtc->pipe), 0);
}
static enum intel_display_power_domain port_to_power_domain(enum port port)
{
switch (port) {
case PORT_A:
return POWER_DOMAIN_PORT_DDI_A_LANES;
case PORT_B:
return POWER_DOMAIN_PORT_DDI_B_LANES;
case PORT_C:
return POWER_DOMAIN_PORT_DDI_C_LANES;
case PORT_D:
return POWER_DOMAIN_PORT_DDI_D_LANES;
case PORT_E:
return POWER_DOMAIN_PORT_DDI_E_LANES;
default:
MISSING_CASE(port);
return POWER_DOMAIN_PORT_OTHER;
}
}
static enum intel_display_power_domain port_to_aux_power_domain(enum port port)
{
switch (port) {
case PORT_A:
return POWER_DOMAIN_AUX_A;
case PORT_B:
return POWER_DOMAIN_AUX_B;
case PORT_C:
return POWER_DOMAIN_AUX_C;
case PORT_D:
return POWER_DOMAIN_AUX_D;
case PORT_E:
return POWER_DOMAIN_AUX_D;
default:
MISSING_CASE(port);
return POWER_DOMAIN_AUX_A;
}
}
enum intel_display_power_domain
intel_display_port_power_domain(struct intel_encoder *intel_encoder)
{
struct drm_i915_private *dev_priv = to_i915(intel_encoder->base.dev);
struct intel_digital_port *intel_dig_port;
switch (intel_encoder->type) {
case INTEL_OUTPUT_UNKNOWN:
WARN_ON_ONCE(!HAS_DDI(dev_priv));
case INTEL_OUTPUT_DP:
case INTEL_OUTPUT_HDMI:
case INTEL_OUTPUT_EDP:
intel_dig_port = enc_to_dig_port(&intel_encoder->base);
return port_to_power_domain(intel_dig_port->port);
case INTEL_OUTPUT_DP_MST:
intel_dig_port = enc_to_mst(&intel_encoder->base)->primary;
return port_to_power_domain(intel_dig_port->port);
case INTEL_OUTPUT_ANALOG:
return POWER_DOMAIN_PORT_CRT;
case INTEL_OUTPUT_DSI:
return POWER_DOMAIN_PORT_DSI;
default:
return POWER_DOMAIN_PORT_OTHER;
}
}
enum intel_display_power_domain
intel_display_port_aux_power_domain(struct intel_encoder *intel_encoder)
{
struct drm_i915_private *dev_priv = to_i915(intel_encoder->base.dev);
struct intel_digital_port *intel_dig_port;
switch (intel_encoder->type) {
case INTEL_OUTPUT_UNKNOWN:
case INTEL_OUTPUT_HDMI:
WARN_ON_ONCE(!HAS_DDI(dev_priv));
case INTEL_OUTPUT_DP:
case INTEL_OUTPUT_EDP:
intel_dig_port = enc_to_dig_port(&intel_encoder->base);
return port_to_aux_power_domain(intel_dig_port->port);
case INTEL_OUTPUT_DP_MST:
intel_dig_port = enc_to_mst(&intel_encoder->base)->primary;
return port_to_aux_power_domain(intel_dig_port->port);
default:
MISSING_CASE(intel_encoder->type);
return POWER_DOMAIN_AUX_A;
}
}
static unsigned long get_crtc_power_domains(struct drm_crtc *crtc,
struct intel_crtc_state *crtc_state)
{
struct drm_device *dev = crtc->dev;
struct drm_encoder *encoder;
struct intel_crtc *intel_crtc = to_intel_crtc(crtc);
enum pipe pipe = intel_crtc->pipe;
unsigned long mask;
enum transcoder transcoder = crtc_state->cpu_transcoder;
if (!crtc_state->base.active)
return 0;
mask = BIT(POWER_DOMAIN_PIPE(pipe));
mask |= BIT(POWER_DOMAIN_TRANSCODER(transcoder));
if (crtc_state->pch_pfit.enabled ||
crtc_state->pch_pfit.force_thru)
mask |= BIT(POWER_DOMAIN_PIPE_PANEL_FITTER(pipe));
drm_for_each_encoder_mask(encoder, dev, crtc_state->base.encoder_mask) {
struct intel_encoder *intel_encoder = to_intel_encoder(encoder);
mask |= BIT(intel_display_port_power_domain(intel_encoder));
}
if (crtc_state->shared_dpll)
mask |= BIT(POWER_DOMAIN_PLLS);
return mask;
}
static unsigned long
modeset_get_crtc_power_domains(struct drm_crtc *crtc,
struct intel_crtc_state *crtc_state)
{
struct drm_i915_private *dev_priv = to_i915(crtc->dev);
struct intel_crtc *intel_crtc = to_intel_crtc(crtc);
enum intel_display_power_domain domain;
unsigned long domains, new_domains, old_domains;
old_domains = intel_crtc->enabled_power_domains;
intel_crtc->enabled_power_domains = new_domains =
get_crtc_power_domains(crtc, crtc_state);
domains = new_domains & ~old_domains;
for_each_power_domain(domain, domains)
intel_display_power_get(dev_priv, domain);
return old_domains & ~new_domains;
}
static void modeset_put_power_domains(struct drm_i915_private *dev_priv,
unsigned long domains)
{
enum intel_display_power_domain domain;
for_each_power_domain(domain, domains)
intel_display_power_put(dev_priv, domain);
}
static int intel_compute_max_dotclk(struct drm_i915_private *dev_priv)
{
int max_cdclk_freq = dev_priv->max_cdclk_freq;
if (INTEL_INFO(dev_priv)->gen >= 9 ||
IS_HASWELL(dev_priv) || IS_BROADWELL(dev_priv))
return max_cdclk_freq;
else if (IS_CHERRYVIEW(dev_priv))
return max_cdclk_freq*95/100;
else if (INTEL_INFO(dev_priv)->gen < 4)
return 2*max_cdclk_freq*90/100;
else
return max_cdclk_freq*90/100;
}
static void intel_update_max_cdclk(struct drm_i915_private *dev_priv)
{
if (IS_SKYLAKE(dev_priv) || IS_KABYLAKE(dev_priv)) {
u32 limit = I915_READ(SKL_DFSM) & SKL_DFSM_CDCLK_LIMIT_MASK;
int max_cdclk, vco;
vco = dev_priv->skl_preferred_vco_freq;
WARN_ON(vco != 8100000 && vco != 8640000);
if (limit == SKL_DFSM_CDCLK_LIMIT_675)
max_cdclk = 617143;
else if (limit == SKL_DFSM_CDCLK_LIMIT_540)
max_cdclk = 540000;
else if (limit == SKL_DFSM_CDCLK_LIMIT_450)
max_cdclk = 432000;
else
max_cdclk = 308571;
dev_priv->max_cdclk_freq = skl_calc_cdclk(max_cdclk, vco);
} else if (IS_BROXTON(dev_priv)) {
dev_priv->max_cdclk_freq = 624000;
} else if (IS_BROADWELL(dev_priv)) {
if (I915_READ(FUSE_STRAP) & HSW_CDCLK_LIMIT)
dev_priv->max_cdclk_freq = 450000;
else if (IS_BDW_ULX(dev_priv))
dev_priv->max_cdclk_freq = 450000;
else if (IS_BDW_ULT(dev_priv))
dev_priv->max_cdclk_freq = 540000;
else
dev_priv->max_cdclk_freq = 675000;
} else if (IS_CHERRYVIEW(dev_priv)) {
dev_priv->max_cdclk_freq = 320000;
} else if (IS_VALLEYVIEW(dev_priv)) {
dev_priv->max_cdclk_freq = 400000;
} else {
dev_priv->max_cdclk_freq = dev_priv->cdclk_freq;
}
dev_priv->max_dotclk_freq = intel_compute_max_dotclk(dev_priv);
DRM_DEBUG_DRIVER("Max CD clock rate: %d kHz\n",
dev_priv->max_cdclk_freq);
DRM_DEBUG_DRIVER("Max dotclock rate: %d kHz\n",
dev_priv->max_dotclk_freq);
}
static void intel_update_cdclk(struct drm_i915_private *dev_priv)
{
dev_priv->cdclk_freq = dev_priv->display.get_display_clock_speed(dev_priv);
if (INTEL_GEN(dev_priv) >= 9)
DRM_DEBUG_DRIVER("Current CD clock rate: %d kHz, VCO: %d kHz, ref: %d kHz\n",
dev_priv->cdclk_freq, dev_priv->cdclk_pll.vco,
dev_priv->cdclk_pll.ref);
else
DRM_DEBUG_DRIVER("Current CD clock rate: %d kHz\n",
dev_priv->cdclk_freq);
if (IS_VALLEYVIEW(dev_priv) || IS_CHERRYVIEW(dev_priv))
I915_WRITE(GMBUSFREQ_VLV, DIV_ROUND_UP(dev_priv->cdclk_freq, 1000));
}
static int skl_cdclk_decimal(int cdclk)
{
return DIV_ROUND_CLOSEST(cdclk - 1000, 500);
}
static int bxt_de_pll_vco(struct drm_i915_private *dev_priv, int cdclk)
{
int ratio;
if (cdclk == dev_priv->cdclk_pll.ref)
return 0;
switch (cdclk) {
default:
MISSING_CASE(cdclk);
case 144000:
case 288000:
case 384000:
case 576000:
ratio = 60;
break;
case 624000:
ratio = 65;
break;
}
return dev_priv->cdclk_pll.ref * ratio;
}
static void bxt_de_pll_disable(struct drm_i915_private *dev_priv)
{
I915_WRITE(BXT_DE_PLL_ENABLE, 0);
if (intel_wait_for_register(dev_priv,
BXT_DE_PLL_ENABLE, BXT_DE_PLL_LOCK, 0,
1))
DRM_ERROR("timeout waiting for DE PLL unlock\n");
dev_priv->cdclk_pll.vco = 0;
}
static void bxt_de_pll_enable(struct drm_i915_private *dev_priv, int vco)
{
int ratio = DIV_ROUND_CLOSEST(vco, dev_priv->cdclk_pll.ref);
u32 val;
val = I915_READ(BXT_DE_PLL_CTL);
val &= ~BXT_DE_PLL_RATIO_MASK;
val |= BXT_DE_PLL_RATIO(ratio);
I915_WRITE(BXT_DE_PLL_CTL, val);
I915_WRITE(BXT_DE_PLL_ENABLE, BXT_DE_PLL_PLL_ENABLE);
if (intel_wait_for_register(dev_priv,
BXT_DE_PLL_ENABLE,
BXT_DE_PLL_LOCK,
BXT_DE_PLL_LOCK,
1))
DRM_ERROR("timeout waiting for DE PLL lock\n");
dev_priv->cdclk_pll.vco = vco;
}
static void bxt_set_cdclk(struct drm_i915_private *dev_priv, int cdclk)
{
u32 val, divider;
int vco, ret;
vco = bxt_de_pll_vco(dev_priv, cdclk);
DRM_DEBUG_DRIVER("Changing CDCLK to %d kHz (VCO %d kHz)\n", cdclk, vco);
switch (DIV_ROUND_CLOSEST(vco, cdclk)) {
case 8:
divider = BXT_CDCLK_CD2X_DIV_SEL_4;
break;
case 4:
divider = BXT_CDCLK_CD2X_DIV_SEL_2;
break;
case 3:
divider = BXT_CDCLK_CD2X_DIV_SEL_1_5;
break;
case 2:
divider = BXT_CDCLK_CD2X_DIV_SEL_1;
break;
default:
WARN_ON(cdclk != dev_priv->cdclk_pll.ref);
WARN_ON(vco != 0);
divider = BXT_CDCLK_CD2X_DIV_SEL_1;
break;
}
mutex_lock(&dev_priv->rps.hw_lock);
ret = sandybridge_pcode_write(dev_priv, HSW_PCODE_DE_WRITE_FREQ_REQ,
0x80000000);
mutex_unlock(&dev_priv->rps.hw_lock);
if (ret) {
DRM_ERROR("PCode CDCLK freq change notify failed (err %d, freq %d)\n",
ret, cdclk);
return;
}
if (dev_priv->cdclk_pll.vco != 0 &&
dev_priv->cdclk_pll.vco != vco)
bxt_de_pll_disable(dev_priv);
if (dev_priv->cdclk_pll.vco != vco)
bxt_de_pll_enable(dev_priv, vco);
val = divider | skl_cdclk_decimal(cdclk);
val |= BXT_CDCLK_CD2X_PIPE_NONE;
if (cdclk >= 500000)
val |= BXT_CDCLK_SSA_PRECHARGE_ENABLE;
I915_WRITE(CDCLK_CTL, val);
mutex_lock(&dev_priv->rps.hw_lock);
ret = sandybridge_pcode_write(dev_priv, HSW_PCODE_DE_WRITE_FREQ_REQ,
DIV_ROUND_UP(cdclk, 25000));
mutex_unlock(&dev_priv->rps.hw_lock);
if (ret) {
DRM_ERROR("PCode CDCLK freq set failed, (err %d, freq %d)\n",
ret, cdclk);
return;
}
intel_update_cdclk(dev_priv);
}
static void bxt_sanitize_cdclk(struct drm_i915_private *dev_priv)
{
u32 cdctl, expected;
intel_update_cdclk(dev_priv);
if (dev_priv->cdclk_pll.vco == 0 ||
dev_priv->cdclk_freq == dev_priv->cdclk_pll.ref)
goto sanitize;
cdctl = I915_READ(CDCLK_CTL);
cdctl &= ~BXT_CDCLK_CD2X_PIPE_NONE;
expected = (cdctl & BXT_CDCLK_CD2X_DIV_SEL_MASK) |
skl_cdclk_decimal(dev_priv->cdclk_freq);
if (dev_priv->cdclk_freq >= 500000)
expected |= BXT_CDCLK_SSA_PRECHARGE_ENABLE;
if (cdctl == expected)
return;
sanitize:
DRM_DEBUG_KMS("Sanitizing cdclk programmed by pre-os\n");
dev_priv->cdclk_freq = 0;
dev_priv->cdclk_pll.vco = -1;
}
void bxt_init_cdclk(struct drm_i915_private *dev_priv)
{
bxt_sanitize_cdclk(dev_priv);
if (dev_priv->cdclk_freq != 0 && dev_priv->cdclk_pll.vco != 0)
return;
bxt_set_cdclk(dev_priv, bxt_calc_cdclk(0));
}
void bxt_uninit_cdclk(struct drm_i915_private *dev_priv)
{
bxt_set_cdclk(dev_priv, dev_priv->cdclk_pll.ref);
}
static int skl_calc_cdclk(int max_pixclk, int vco)
{
if (vco == 8640000) {
if (max_pixclk > 540000)
return 617143;
else if (max_pixclk > 432000)
return 540000;
else if (max_pixclk > 308571)
return 432000;
else
return 308571;
} else {
if (max_pixclk > 540000)
return 675000;
else if (max_pixclk > 450000)
return 540000;
else if (max_pixclk > 337500)
return 450000;
else
return 337500;
}
}
static void
skl_dpll0_update(struct drm_i915_private *dev_priv)
{
u32 val;
dev_priv->cdclk_pll.ref = 24000;
dev_priv->cdclk_pll.vco = 0;
val = I915_READ(LCPLL1_CTL);
if ((val & LCPLL_PLL_ENABLE) == 0)
return;
if (WARN_ON((val & LCPLL_PLL_LOCK) == 0))
return;
val = I915_READ(DPLL_CTRL1);
if (WARN_ON((val & (DPLL_CTRL1_HDMI_MODE(SKL_DPLL0) |
DPLL_CTRL1_SSC(SKL_DPLL0) |
DPLL_CTRL1_OVERRIDE(SKL_DPLL0))) !=
DPLL_CTRL1_OVERRIDE(SKL_DPLL0)))
return;
switch (val & DPLL_CTRL1_LINK_RATE_MASK(SKL_DPLL0)) {
case DPLL_CTRL1_LINK_RATE(DPLL_CTRL1_LINK_RATE_810, SKL_DPLL0):
case DPLL_CTRL1_LINK_RATE(DPLL_CTRL1_LINK_RATE_1350, SKL_DPLL0):
case DPLL_CTRL1_LINK_RATE(DPLL_CTRL1_LINK_RATE_1620, SKL_DPLL0):
case DPLL_CTRL1_LINK_RATE(DPLL_CTRL1_LINK_RATE_2700, SKL_DPLL0):
dev_priv->cdclk_pll.vco = 8100000;
break;
case DPLL_CTRL1_LINK_RATE(DPLL_CTRL1_LINK_RATE_1080, SKL_DPLL0):
case DPLL_CTRL1_LINK_RATE(DPLL_CTRL1_LINK_RATE_2160, SKL_DPLL0):
dev_priv->cdclk_pll.vco = 8640000;
break;
default:
MISSING_CASE(val & DPLL_CTRL1_LINK_RATE_MASK(SKL_DPLL0));
break;
}
}
void skl_set_preferred_cdclk_vco(struct drm_i915_private *dev_priv, int vco)
{
bool changed = dev_priv->skl_preferred_vco_freq != vco;
dev_priv->skl_preferred_vco_freq = vco;
if (changed)
intel_update_max_cdclk(dev_priv);
}
static void
skl_dpll0_enable(struct drm_i915_private *dev_priv, int vco)
{
int min_cdclk = skl_calc_cdclk(0, vco);
u32 val;
WARN_ON(vco != 8100000 && vco != 8640000);
val = CDCLK_FREQ_337_308 | skl_cdclk_decimal(min_cdclk);
I915_WRITE(CDCLK_CTL, val);
POSTING_READ(CDCLK_CTL);
val = I915_READ(DPLL_CTRL1);
val &= ~(DPLL_CTRL1_HDMI_MODE(SKL_DPLL0) | DPLL_CTRL1_SSC(SKL_DPLL0) |
DPLL_CTRL1_LINK_RATE_MASK(SKL_DPLL0));
val |= DPLL_CTRL1_OVERRIDE(SKL_DPLL0);
if (vco == 8640000)
val |= DPLL_CTRL1_LINK_RATE(DPLL_CTRL1_LINK_RATE_1080,
SKL_DPLL0);
else
val |= DPLL_CTRL1_LINK_RATE(DPLL_CTRL1_LINK_RATE_810,
SKL_DPLL0);
I915_WRITE(DPLL_CTRL1, val);
POSTING_READ(DPLL_CTRL1);
I915_WRITE(LCPLL1_CTL, I915_READ(LCPLL1_CTL) | LCPLL_PLL_ENABLE);
if (intel_wait_for_register(dev_priv,
LCPLL1_CTL, LCPLL_PLL_LOCK, LCPLL_PLL_LOCK,
5))
DRM_ERROR("DPLL0 not locked\n");
dev_priv->cdclk_pll.vco = vco;
skl_set_preferred_cdclk_vco(dev_priv, vco);
}
static void
skl_dpll0_disable(struct drm_i915_private *dev_priv)
{
I915_WRITE(LCPLL1_CTL, I915_READ(LCPLL1_CTL) & ~LCPLL_PLL_ENABLE);
if (intel_wait_for_register(dev_priv,
LCPLL1_CTL, LCPLL_PLL_LOCK, 0,
1))
DRM_ERROR("Couldn't disable DPLL0\n");
dev_priv->cdclk_pll.vco = 0;
}
static void skl_set_cdclk(struct drm_i915_private *dev_priv, int cdclk, int vco)
{
u32 freq_select, pcu_ack;
int ret;
WARN_ON((cdclk == 24000) != (vco == 0));
DRM_DEBUG_DRIVER("Changing CDCLK to %d kHz (VCO %d kHz)\n", cdclk, vco);
mutex_lock(&dev_priv->rps.hw_lock);
ret = skl_pcode_request(dev_priv, SKL_PCODE_CDCLK_CONTROL,
SKL_CDCLK_PREPARE_FOR_CHANGE,
SKL_CDCLK_READY_FOR_CHANGE,
SKL_CDCLK_READY_FOR_CHANGE, 3);
mutex_unlock(&dev_priv->rps.hw_lock);
if (ret) {
DRM_ERROR("Failed to inform PCU about cdclk change (%d)\n",
ret);
return;
}
switch (cdclk) {
case 450000:
case 432000:
freq_select = CDCLK_FREQ_450_432;
pcu_ack = 1;
break;
case 540000:
freq_select = CDCLK_FREQ_540;
pcu_ack = 2;
break;
case 308571:
case 337500:
default:
freq_select = CDCLK_FREQ_337_308;
pcu_ack = 0;
break;
case 617143:
case 675000:
freq_select = CDCLK_FREQ_675_617;
pcu_ack = 3;
break;
}
if (dev_priv->cdclk_pll.vco != 0 &&
dev_priv->cdclk_pll.vco != vco)
skl_dpll0_disable(dev_priv);
if (dev_priv->cdclk_pll.vco != vco)
skl_dpll0_enable(dev_priv, vco);
I915_WRITE(CDCLK_CTL, freq_select | skl_cdclk_decimal(cdclk));
POSTING_READ(CDCLK_CTL);
mutex_lock(&dev_priv->rps.hw_lock);
sandybridge_pcode_write(dev_priv, SKL_PCODE_CDCLK_CONTROL, pcu_ack);
mutex_unlock(&dev_priv->rps.hw_lock);
intel_update_cdclk(dev_priv);
}
void skl_uninit_cdclk(struct drm_i915_private *dev_priv)
{
skl_set_cdclk(dev_priv, dev_priv->cdclk_pll.ref, 0);
}
void skl_init_cdclk(struct drm_i915_private *dev_priv)
{
int cdclk, vco;
skl_sanitize_cdclk(dev_priv);
if (dev_priv->cdclk_freq != 0 && dev_priv->cdclk_pll.vco != 0) {
if (dev_priv->skl_preferred_vco_freq == 0)
skl_set_preferred_cdclk_vco(dev_priv,
dev_priv->cdclk_pll.vco);
return;
}
vco = dev_priv->skl_preferred_vco_freq;
if (vco == 0)
vco = 8100000;
cdclk = skl_calc_cdclk(0, vco);
skl_set_cdclk(dev_priv, cdclk, vco);
}
static void skl_sanitize_cdclk(struct drm_i915_private *dev_priv)
{
uint32_t cdctl, expected;
if ((I915_READ(SWF_ILK(0x18)) & 0x00FFFFFF) == 0)
goto sanitize;
intel_update_cdclk(dev_priv);
if (dev_priv->cdclk_pll.vco == 0 ||
dev_priv->cdclk_freq == dev_priv->cdclk_pll.ref)
goto sanitize;
cdctl = I915_READ(CDCLK_CTL);
expected = (cdctl & CDCLK_FREQ_SEL_MASK) |
skl_cdclk_decimal(dev_priv->cdclk_freq);
if (cdctl == expected)
return;
sanitize:
DRM_DEBUG_KMS("Sanitizing cdclk programmed by pre-os\n");
dev_priv->cdclk_freq = 0;
dev_priv->cdclk_pll.vco = -1;
}
static void valleyview_set_cdclk(struct drm_device *dev, int cdclk)
{
struct drm_i915_private *dev_priv = to_i915(dev);
u32 val, cmd;
WARN_ON(dev_priv->display.get_display_clock_speed(dev_priv)
!= dev_priv->cdclk_freq);
if (cdclk >= 320000)
cmd = 2;
else if (cdclk == 266667)
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
mutex_lock(&dev_priv->sb_lock);
if (cdclk == 400000) {
u32 divider;
divider = DIV_ROUND_CLOSEST(dev_priv->hpll_freq << 1, cdclk) - 1;
val = vlv_cck_read(dev_priv, CCK_DISPLAY_CLOCK_CONTROL);
val &= ~CCK_FREQUENCY_VALUES;
val |= divider;
vlv_cck_write(dev_priv, CCK_DISPLAY_CLOCK_CONTROL, val);
if (wait_for((vlv_cck_read(dev_priv, CCK_DISPLAY_CLOCK_CONTROL) &
CCK_FREQUENCY_STATUS) == (divider << CCK_FREQUENCY_STATUS_SHIFT),
50))
DRM_ERROR("timed out waiting for CDclk change\n");
}
val = vlv_bunit_read(dev_priv, BUNIT_REG_BISOC);
val &= ~0x7f;
if (cdclk == 400000)
val |= 4500 / 250;
else
val |= 3000 / 250;
vlv_bunit_write(dev_priv, BUNIT_REG_BISOC, val);
mutex_unlock(&dev_priv->sb_lock);
intel_update_cdclk(dev_priv);
}
static void cherryview_set_cdclk(struct drm_device *dev, int cdclk)
{
struct drm_i915_private *dev_priv = to_i915(dev);
u32 val, cmd;
WARN_ON(dev_priv->display.get_display_clock_speed(dev_priv)
!= dev_priv->cdclk_freq);
switch (cdclk) {
case 333333:
case 320000:
case 266667:
case 200000:
break;
default:
MISSING_CASE(cdclk);
return;
}
cmd = DIV_ROUND_CLOSEST(dev_priv->hpll_freq << 1, cdclk) - 1;
mutex_lock(&dev_priv->rps.hw_lock);
val = vlv_punit_read(dev_priv, PUNIT_REG_DSPFREQ);
val &= ~DSPFREQGUAR_MASK_CHV;
val |= (cmd << DSPFREQGUAR_SHIFT_CHV);
vlv_punit_write(dev_priv, PUNIT_REG_DSPFREQ, val);
if (wait_for((vlv_punit_read(dev_priv, PUNIT_REG_DSPFREQ) &
DSPFREQSTAT_MASK_CHV) == (cmd << DSPFREQSTAT_SHIFT_CHV),
50)) {
DRM_ERROR("timed out waiting for CDclk change\n");
}
mutex_unlock(&dev_priv->rps.hw_lock);
intel_update_cdclk(dev_priv);
}
static int valleyview_calc_cdclk(struct drm_i915_private *dev_priv,
int max_pixclk)
{
int freq_320 = (dev_priv->hpll_freq << 1) % 320000 != 0 ? 333333 : 320000;
int limit = IS_CHERRYVIEW(dev_priv) ? 95 : 90;
if (!IS_CHERRYVIEW(dev_priv) &&
max_pixclk > freq_320*limit/100)
return 400000;
else if (max_pixclk > 266667*limit/100)
return freq_320;
else if (max_pixclk > 0)
return 266667;
else
return 200000;
}
static int bxt_calc_cdclk(int max_pixclk)
{
if (max_pixclk > 576000)
return 624000;
else if (max_pixclk > 384000)
return 576000;
else if (max_pixclk > 288000)
return 384000;
else if (max_pixclk > 144000)
return 288000;
else
return 144000;
}
static int intel_mode_max_pixclk(struct drm_device *dev,
struct drm_atomic_state *state)
{
struct intel_atomic_state *intel_state = to_intel_atomic_state(state);
struct drm_i915_private *dev_priv = to_i915(dev);
struct drm_crtc *crtc;
struct drm_crtc_state *crtc_state;
unsigned max_pixclk = 0, i;
enum pipe pipe;
memcpy(intel_state->min_pixclk, dev_priv->min_pixclk,
sizeof(intel_state->min_pixclk));
for_each_crtc_in_state(state, crtc, crtc_state, i) {
int pixclk = 0;
if (crtc_state->enable)
pixclk = crtc_state->adjusted_mode.crtc_clock;
intel_state->min_pixclk[i] = pixclk;
}
for_each_pipe(dev_priv, pipe)
max_pixclk = max(intel_state->min_pixclk[pipe], max_pixclk);
return max_pixclk;
}
static int valleyview_modeset_calc_cdclk(struct drm_atomic_state *state)
{
struct drm_device *dev = state->dev;
struct drm_i915_private *dev_priv = to_i915(dev);
int max_pixclk = intel_mode_max_pixclk(dev, state);
struct intel_atomic_state *intel_state =
to_intel_atomic_state(state);
intel_state->cdclk = intel_state->dev_cdclk =
valleyview_calc_cdclk(dev_priv, max_pixclk);
if (!intel_state->active_crtcs)
intel_state->dev_cdclk = valleyview_calc_cdclk(dev_priv, 0);
return 0;
}
static int bxt_modeset_calc_cdclk(struct drm_atomic_state *state)
{
int max_pixclk = ilk_max_pixel_rate(state);
struct intel_atomic_state *intel_state =
to_intel_atomic_state(state);
intel_state->cdclk = intel_state->dev_cdclk =
bxt_calc_cdclk(max_pixclk);
if (!intel_state->active_crtcs)
intel_state->dev_cdclk = bxt_calc_cdclk(0);
return 0;
}
static void vlv_program_pfi_credits(struct drm_i915_private *dev_priv)
{
unsigned int credits, default_credits;
if (IS_CHERRYVIEW(dev_priv))
default_credits = PFI_CREDIT(12);
else
default_credits = PFI_CREDIT(8);
if (dev_priv->cdclk_freq >= dev_priv->czclk_freq) {
if (IS_CHERRYVIEW(dev_priv))
credits = PFI_CREDIT_63;
else
credits = PFI_CREDIT(15);
} else {
credits = default_credits;
}
I915_WRITE(GCI_CONTROL, VGA_FAST_MODE_DISABLE |
default_credits);
I915_WRITE(GCI_CONTROL, VGA_FAST_MODE_DISABLE |
credits | PFI_CREDIT_RESEND);
WARN_ON(I915_READ(GCI_CONTROL) & PFI_CREDIT_RESEND);
}
static void valleyview_modeset_commit_cdclk(struct drm_atomic_state *old_state)
{
struct drm_device *dev = old_state->dev;
struct drm_i915_private *dev_priv = to_i915(dev);
struct intel_atomic_state *old_intel_state =
to_intel_atomic_state(old_state);
unsigned req_cdclk = old_intel_state->dev_cdclk;
intel_display_power_get(dev_priv, POWER_DOMAIN_PIPE_A);
if (IS_CHERRYVIEW(dev_priv))
cherryview_set_cdclk(dev, req_cdclk);
else
valleyview_set_cdclk(dev, req_cdclk);
vlv_program_pfi_credits(dev_priv);
intel_display_power_put(dev_priv, POWER_DOMAIN_PIPE_A);
}
static void valleyview_crtc_enable(struct intel_crtc_state *pipe_config,
struct drm_atomic_state *old_state)
{
struct drm_crtc *crtc = pipe_config->base.crtc;
struct drm_device *dev = crtc->dev;
struct drm_i915_private *dev_priv = to_i915(dev);
struct intel_crtc *intel_crtc = to_intel_crtc(crtc);
int pipe = intel_crtc->pipe;
if (WARN_ON(intel_crtc->active))
return;
if (intel_crtc_has_dp_encoder(intel_crtc->config))
intel_dp_set_m_n(intel_crtc, M1_N1);
intel_set_pipe_timings(intel_crtc);
intel_set_pipe_src_size(intel_crtc);
if (IS_CHERRYVIEW(dev_priv) && pipe == PIPE_B) {
struct drm_i915_private *dev_priv = to_i915(dev);
I915_WRITE(CHV_BLEND(pipe), CHV_BLEND_LEGACY);
I915_WRITE(CHV_CANVAS(pipe), 0);
}
i9xx_set_pipeconf(intel_crtc);
intel_crtc->active = true;
intel_set_cpu_fifo_underrun_reporting(dev_priv, pipe, true);
intel_encoders_pre_pll_enable(crtc, pipe_config, old_state);
if (IS_CHERRYVIEW(dev_priv)) {
chv_prepare_pll(intel_crtc, intel_crtc->config);
chv_enable_pll(intel_crtc, intel_crtc->config);
} else {
vlv_prepare_pll(intel_crtc, intel_crtc->config);
vlv_enable_pll(intel_crtc, intel_crtc->config);
}
intel_encoders_pre_enable(crtc, pipe_config, old_state);
i9xx_pfit_enable(intel_crtc);
intel_color_load_luts(&pipe_config->base);
intel_update_watermarks(intel_crtc);
intel_enable_pipe(intel_crtc);
assert_vblank_disabled(crtc);
drm_crtc_vblank_on(crtc);
intel_encoders_enable(crtc, pipe_config, old_state);
}
static void i9xx_set_pll_dividers(struct intel_crtc *crtc)
{
struct drm_device *dev = crtc->base.dev;
struct drm_i915_private *dev_priv = to_i915(dev);
I915_WRITE(FP0(crtc->pipe), crtc->config->dpll_hw_state.fp0);
I915_WRITE(FP1(crtc->pipe), crtc->config->dpll_hw_state.fp1);
}
static void i9xx_crtc_enable(struct intel_crtc_state *pipe_config,
struct drm_atomic_state *old_state)
{
struct drm_crtc *crtc = pipe_config->base.crtc;
struct drm_device *dev = crtc->dev;
struct drm_i915_private *dev_priv = to_i915(dev);
struct intel_crtc *intel_crtc = to_intel_crtc(crtc);
enum pipe pipe = intel_crtc->pipe;
if (WARN_ON(intel_crtc->active))
return;
i9xx_set_pll_dividers(intel_crtc);
if (intel_crtc_has_dp_encoder(intel_crtc->config))
intel_dp_set_m_n(intel_crtc, M1_N1);
intel_set_pipe_timings(intel_crtc);
intel_set_pipe_src_size(intel_crtc);
i9xx_set_pipeconf(intel_crtc);
intel_crtc->active = true;
if (!IS_GEN2(dev_priv))
intel_set_cpu_fifo_underrun_reporting(dev_priv, pipe, true);
intel_encoders_pre_enable(crtc, pipe_config, old_state);
i9xx_enable_pll(intel_crtc);
i9xx_pfit_enable(intel_crtc);
intel_color_load_luts(&pipe_config->base);
intel_update_watermarks(intel_crtc);
intel_enable_pipe(intel_crtc);
assert_vblank_disabled(crtc);
drm_crtc_vblank_on(crtc);
intel_encoders_enable(crtc, pipe_config, old_state);
}
static void i9xx_pfit_disable(struct intel_crtc *crtc)
{
struct drm_device *dev = crtc->base.dev;
struct drm_i915_private *dev_priv = to_i915(dev);
if (!crtc->config->gmch_pfit.control)
return;
assert_pipe_disabled(dev_priv, crtc->pipe);
DRM_DEBUG_DRIVER("disabling pfit, current: 0x%08x\n",
I915_READ(PFIT_CONTROL));
I915_WRITE(PFIT_CONTROL, 0);
}
static void i9xx_crtc_disable(struct intel_crtc_state *old_crtc_state,
struct drm_atomic_state *old_state)
{
struct drm_crtc *crtc = old_crtc_state->base.crtc;
struct drm_device *dev = crtc->dev;
struct drm_i915_private *dev_priv = to_i915(dev);
struct intel_crtc *intel_crtc = to_intel_crtc(crtc);
int pipe = intel_crtc->pipe;
if (IS_GEN2(dev_priv))
intel_wait_for_vblank(dev_priv, pipe);
intel_encoders_disable(crtc, old_crtc_state, old_state);
drm_crtc_vblank_off(crtc);
assert_vblank_disabled(crtc);
intel_disable_pipe(intel_crtc);
i9xx_pfit_disable(intel_crtc);
intel_encoders_post_disable(crtc, old_crtc_state, old_state);
if (!intel_crtc_has_type(intel_crtc->config, INTEL_OUTPUT_DSI)) {
if (IS_CHERRYVIEW(dev_priv))
chv_disable_pll(dev_priv, pipe);
else if (IS_VALLEYVIEW(dev_priv))
vlv_disable_pll(dev_priv, pipe);
else
i9xx_disable_pll(intel_crtc);
}
intel_encoders_post_pll_disable(crtc, old_crtc_state, old_state);
if (!IS_GEN2(dev_priv))
intel_set_cpu_fifo_underrun_reporting(dev_priv, pipe, false);
}
static void intel_crtc_disable_noatomic(struct drm_crtc *crtc)
{
struct intel_encoder *encoder;
struct intel_crtc *intel_crtc = to_intel_crtc(crtc);
struct drm_i915_private *dev_priv = to_i915(crtc->dev);
enum intel_display_power_domain domain;
unsigned long domains;
struct drm_atomic_state *state;
struct intel_crtc_state *crtc_state;
int ret;
if (!intel_crtc->active)
return;
if (to_intel_plane_state(crtc->primary->state)->base.visible) {
WARN_ON(intel_crtc->flip_work);
intel_pre_disable_primary_noatomic(crtc);
intel_crtc_disable_planes(crtc, 1 << drm_plane_index(crtc->primary));
to_intel_plane_state(crtc->primary->state)->base.visible = false;
}
state = drm_atomic_state_alloc(crtc->dev);
if (!state) {
DRM_DEBUG_KMS("failed to disable [CRTC:%d:%s], out of memory",
crtc->base.id, crtc->name);
return;
}
state->acquire_ctx = crtc->dev->mode_config.acquire_ctx;
crtc_state = intel_atomic_get_crtc_state(state, intel_crtc);
ret = drm_atomic_add_affected_connectors(state, crtc);
WARN_ON(IS_ERR(crtc_state) || ret);
dev_priv->display.crtc_disable(crtc_state, state);
drm_atomic_state_put(state);
DRM_DEBUG_KMS("[CRTC:%d:%s] hw state adjusted, was enabled, now disabled\n",
crtc->base.id, crtc->name);
WARN_ON(drm_atomic_set_mode_for_crtc(crtc->state, NULL) < 0);
crtc->state->active = false;
intel_crtc->active = false;
crtc->enabled = false;
crtc->state->connector_mask = 0;
crtc->state->encoder_mask = 0;
for_each_encoder_on_crtc(crtc->dev, crtc, encoder)
encoder->base.crtc = NULL;
intel_fbc_disable(intel_crtc);
intel_update_watermarks(intel_crtc);
intel_disable_shared_dpll(intel_crtc);
domains = intel_crtc->enabled_power_domains;
for_each_power_domain(domain, domains)
intel_display_power_put(dev_priv, domain);
intel_crtc->enabled_power_domains = 0;
dev_priv->active_crtcs &= ~(1 << intel_crtc->pipe);
dev_priv->min_pixclk[intel_crtc->pipe] = 0;
}
int intel_display_suspend(struct drm_device *dev)
{
struct drm_i915_private *dev_priv = to_i915(dev);
struct drm_atomic_state *state;
int ret;
state = drm_atomic_helper_suspend(dev);
ret = PTR_ERR_OR_ZERO(state);
if (ret)
DRM_ERROR("Suspending crtc's failed with %i\n", ret);
else
dev_priv->modeset_restore_state = state;
return ret;
}
void intel_encoder_destroy(struct drm_encoder *encoder)
{
struct intel_encoder *intel_encoder = to_intel_encoder(encoder);
drm_encoder_cleanup(encoder);
kfree(intel_encoder);
}
static void intel_connector_verify_state(struct intel_connector *connector)
{
struct drm_crtc *crtc = connector->base.state->crtc;
DRM_DEBUG_KMS("[CONNECTOR:%d:%s]\n",
connector->base.base.id,
connector->base.name);
if (connector->get_hw_state(connector)) {
struct intel_encoder *encoder = connector->encoder;
struct drm_connector_state *conn_state = connector->base.state;
I915_STATE_WARN(!crtc,
"connector enabled without attached crtc\n");
if (!crtc)
return;
I915_STATE_WARN(!crtc->state->active,
"connector is active, but attached crtc isn't\n");
if (!encoder || encoder->type == INTEL_OUTPUT_DP_MST)
return;
I915_STATE_WARN(conn_state->best_encoder != &encoder->base,
"atomic encoder doesn't match attached encoder\n");
I915_STATE_WARN(conn_state->crtc != encoder->base.crtc,
"attached encoder crtc differs from connector crtc\n");
} else {
I915_STATE_WARN(crtc && crtc->state->active,
"attached crtc is active, but connector isn't\n");
I915_STATE_WARN(!crtc && connector->base.state->best_encoder,
"best encoder set without crtc!\n");
}
}
int intel_connector_init(struct intel_connector *connector)
{
drm_atomic_helper_connector_reset(&connector->base);
if (!connector->base.state)
return -ENOMEM;
return 0;
}
struct intel_connector *intel_connector_alloc(void)
{
struct intel_connector *connector;
connector = kzalloc(sizeof *connector, GFP_KERNEL);
if (!connector)
return NULL;
if (intel_connector_init(connector) < 0) {
kfree(connector);
return NULL;
}
return connector;
}
bool intel_connector_get_hw_state(struct intel_connector *connector)
{
enum pipe pipe = 0;
struct intel_encoder *encoder = connector->encoder;
return encoder->get_hw_state(encoder, &pipe);
}
static int pipe_required_fdi_lanes(struct intel_crtc_state *crtc_state)
{
if (crtc_state->base.enable && crtc_state->has_pch_encoder)
return crtc_state->fdi_lanes;
return 0;
}
static int ironlake_check_fdi_lanes(struct drm_device *dev, enum pipe pipe,
struct intel_crtc_state *pipe_config)
{
struct drm_i915_private *dev_priv = to_i915(dev);
struct drm_atomic_state *state = pipe_config->base.state;
struct intel_crtc *other_crtc;
struct intel_crtc_state *other_crtc_state;
DRM_DEBUG_KMS("checking fdi config on pipe %c, lanes %i\n",
pipe_name(pipe), pipe_config->fdi_lanes);
if (pipe_config->fdi_lanes > 4) {
DRM_DEBUG_KMS("invalid fdi lane config on pipe %c: %i lanes\n",
pipe_name(pipe), pipe_config->fdi_lanes);
return -EINVAL;
}
if (IS_HASWELL(dev_priv) || IS_BROADWELL(dev_priv)) {
if (pipe_config->fdi_lanes > 2) {
DRM_DEBUG_KMS("only 2 lanes on haswell, required: %i lanes\n",
pipe_config->fdi_lanes);
return -EINVAL;
} else {
return 0;
}
}
if (INTEL_INFO(dev_priv)->num_pipes == 2)
return 0;
switch (pipe) {
case PIPE_A:
return 0;
case PIPE_B:
if (pipe_config->fdi_lanes <= 2)
return 0;
other_crtc = intel_get_crtc_for_pipe(dev_priv, PIPE_C);
other_crtc_state =
intel_atomic_get_crtc_state(state, other_crtc);
if (IS_ERR(other_crtc_state))
return PTR_ERR(other_crtc_state);
if (pipe_required_fdi_lanes(other_crtc_state) > 0) {
DRM_DEBUG_KMS("invalid shared fdi lane config on pipe %c: %i lanes\n",
pipe_name(pipe), pipe_config->fdi_lanes);
return -EINVAL;
}
return 0;
case PIPE_C:
if (pipe_config->fdi_lanes > 2) {
DRM_DEBUG_KMS("only 2 lanes on pipe %c: required %i lanes\n",
pipe_name(pipe), pipe_config->fdi_lanes);
return -EINVAL;
}
other_crtc = intel_get_crtc_for_pipe(dev_priv, PIPE_B);
other_crtc_state =
intel_atomic_get_crtc_state(state, other_crtc);
if (IS_ERR(other_crtc_state))
return PTR_ERR(other_crtc_state);
if (pipe_required_fdi_lanes(other_crtc_state) > 2) {
DRM_DEBUG_KMS("fdi link B uses too many lanes to enable link C\n");
return -EINVAL;
}
return 0;
default:
BUG();
}
}
static int ironlake_fdi_compute_config(struct intel_crtc *intel_crtc,
struct intel_crtc_state *pipe_config)
{
struct drm_device *dev = intel_crtc->base.dev;
const struct drm_display_mode *adjusted_mode = &pipe_config->base.adjusted_mode;
int lane, link_bw, fdi_dotclock, ret;
bool needs_recompute = false;
retry:
link_bw = intel_fdi_link_freq(to_i915(dev), pipe_config);
fdi_dotclock = adjusted_mode->crtc_clock;
lane = ironlake_get_lanes_required(fdi_dotclock, link_bw,
pipe_config->pipe_bpp);
pipe_config->fdi_lanes = lane;
intel_link_compute_m_n(pipe_config->pipe_bpp, lane, fdi_dotclock,
link_bw, &pipe_config->fdi_m_n);
ret = ironlake_check_fdi_lanes(dev, intel_crtc->pipe, pipe_config);
if (ret == -EINVAL && pipe_config->pipe_bpp > 6*3) {
pipe_config->pipe_bpp -= 2*3;
DRM_DEBUG_KMS("fdi link bw constraint, reducing pipe bpp to %i\n",
pipe_config->pipe_bpp);
needs_recompute = true;
pipe_config->bw_constrained = true;
goto retry;
}
if (needs_recompute)
return RETRY;
return ret;
}
static bool pipe_config_supports_ips(struct drm_i915_private *dev_priv,
struct intel_crtc_state *pipe_config)
{
if (pipe_config->pipe_bpp > 24)
return false;
if (IS_HASWELL(dev_priv))
return true;
return ilk_pipe_pixel_rate(pipe_config) <=
dev_priv->max_cdclk_freq * 95 / 100;
}
static void hsw_compute_ips_config(struct intel_crtc *crtc,
struct intel_crtc_state *pipe_config)
{
struct drm_device *dev = crtc->base.dev;
struct drm_i915_private *dev_priv = to_i915(dev);
pipe_config->ips_enabled = i915.enable_ips &&
hsw_crtc_supports_ips(crtc) &&
pipe_config_supports_ips(dev_priv, pipe_config);
}
static bool intel_crtc_supports_double_wide(const struct intel_crtc *crtc)
{
const struct drm_i915_private *dev_priv = to_i915(crtc->base.dev);
return INTEL_INFO(dev_priv)->gen < 4 &&
(crtc->pipe == PIPE_A || IS_I915G(dev_priv));
}
static int intel_crtc_compute_config(struct intel_crtc *crtc,
struct intel_crtc_state *pipe_config)
{
struct drm_device *dev = crtc->base.dev;
struct drm_i915_private *dev_priv = to_i915(dev);
const struct drm_display_mode *adjusted_mode = &pipe_config->base.adjusted_mode;
int clock_limit = dev_priv->max_dotclk_freq;
if (INTEL_GEN(dev_priv) < 4) {
clock_limit = dev_priv->max_cdclk_freq * 9 / 10;
if (intel_crtc_supports_double_wide(crtc) &&
adjusted_mode->crtc_clock > clock_limit) {
clock_limit = dev_priv->max_dotclk_freq;
pipe_config->double_wide = true;
}
}
if (adjusted_mode->crtc_clock > clock_limit) {
DRM_DEBUG_KMS("requested pixel clock (%d kHz) too high (max: %d kHz, double wide: %s)\n",
adjusted_mode->crtc_clock, clock_limit,
yesno(pipe_config->double_wide));
return -EINVAL;
}
if ((intel_crtc_has_type(pipe_config, INTEL_OUTPUT_LVDS) &&
intel_is_dual_link_lvds(dev)) || pipe_config->double_wide)
pipe_config->pipe_src_w &= ~1;
if ((INTEL_GEN(dev_priv) > 4 || IS_G4X(dev_priv)) &&
adjusted_mode->crtc_hsync_start == adjusted_mode->crtc_hdisplay)
return -EINVAL;
if (HAS_IPS(dev_priv))
hsw_compute_ips_config(crtc, pipe_config);
if (pipe_config->has_pch_encoder)
return ironlake_fdi_compute_config(crtc, pipe_config);
return 0;
}
static int skylake_get_display_clock_speed(struct drm_i915_private *dev_priv)
{
u32 cdctl;
skl_dpll0_update(dev_priv);
if (dev_priv->cdclk_pll.vco == 0)
return dev_priv->cdclk_pll.ref;
cdctl = I915_READ(CDCLK_CTL);
if (dev_priv->cdclk_pll.vco == 8640000) {
switch (cdctl & CDCLK_FREQ_SEL_MASK) {
case CDCLK_FREQ_450_432:
return 432000;
case CDCLK_FREQ_337_308:
return 308571;
case CDCLK_FREQ_540:
return 540000;
case CDCLK_FREQ_675_617:
return 617143;
default:
MISSING_CASE(cdctl & CDCLK_FREQ_SEL_MASK);
}
} else {
switch (cdctl & CDCLK_FREQ_SEL_MASK) {
case CDCLK_FREQ_450_432:
return 450000;
case CDCLK_FREQ_337_308:
return 337500;
case CDCLK_FREQ_540:
return 540000;
case CDCLK_FREQ_675_617:
return 675000;
default:
MISSING_CASE(cdctl & CDCLK_FREQ_SEL_MASK);
}
}
return dev_priv->cdclk_pll.ref;
}
static void bxt_de_pll_update(struct drm_i915_private *dev_priv)
{
u32 val;
dev_priv->cdclk_pll.ref = 19200;
dev_priv->cdclk_pll.vco = 0;
val = I915_READ(BXT_DE_PLL_ENABLE);
if ((val & BXT_DE_PLL_PLL_ENABLE) == 0)
return;
if (WARN_ON((val & BXT_DE_PLL_LOCK) == 0))
return;
val = I915_READ(BXT_DE_PLL_CTL);
dev_priv->cdclk_pll.vco = (val & BXT_DE_PLL_RATIO_MASK) *
dev_priv->cdclk_pll.ref;
}
static int broxton_get_display_clock_speed(struct drm_i915_private *dev_priv)
{
u32 divider;
int div, vco;
bxt_de_pll_update(dev_priv);
vco = dev_priv->cdclk_pll.vco;
if (vco == 0)
return dev_priv->cdclk_pll.ref;
divider = I915_READ(CDCLK_CTL) & BXT_CDCLK_CD2X_DIV_SEL_MASK;
switch (divider) {
case BXT_CDCLK_CD2X_DIV_SEL_1:
div = 2;
break;
case BXT_CDCLK_CD2X_DIV_SEL_1_5:
div = 3;
break;
case BXT_CDCLK_CD2X_DIV_SEL_2:
div = 4;
break;
case BXT_CDCLK_CD2X_DIV_SEL_4:
div = 8;
break;
default:
MISSING_CASE(divider);
return dev_priv->cdclk_pll.ref;
}
return DIV_ROUND_CLOSEST(vco, div);
}
static int broadwell_get_display_clock_speed(struct drm_i915_private *dev_priv)
{
uint32_t lcpll = I915_READ(LCPLL_CTL);
uint32_t freq = lcpll & LCPLL_CLK_FREQ_MASK;
if (lcpll & LCPLL_CD_SOURCE_FCLK)
return 800000;
else if (I915_READ(FUSE_STRAP) & HSW_CDCLK_LIMIT)
return 450000;
else if (freq == LCPLL_CLK_FREQ_450)
return 450000;
else if (freq == LCPLL_CLK_FREQ_54O_BDW)
return 540000;
else if (freq == LCPLL_CLK_FREQ_337_5_BDW)
return 337500;
else
return 675000;
}
static int haswell_get_display_clock_speed(struct drm_i915_private *dev_priv)
{
uint32_t lcpll = I915_READ(LCPLL_CTL);
uint32_t freq = lcpll & LCPLL_CLK_FREQ_MASK;
if (lcpll & LCPLL_CD_SOURCE_FCLK)
return 800000;
else if (I915_READ(FUSE_STRAP) & HSW_CDCLK_LIMIT)
return 450000;
else if (freq == LCPLL_CLK_FREQ_450)
return 450000;
else if (IS_HSW_ULT(dev_priv))
return 337500;
else
return 540000;
}
static int valleyview_get_display_clock_speed(struct drm_i915_private *dev_priv)
{
return vlv_get_cck_clock_hpll(dev_priv, "cdclk",
CCK_DISPLAY_CLOCK_CONTROL);
}
static int ilk_get_display_clock_speed(struct drm_i915_private *dev_priv)
{
return 450000;
}
static int i945_get_display_clock_speed(struct drm_i915_private *dev_priv)
{
return 400000;
}
static int i915_get_display_clock_speed(struct drm_i915_private *dev_priv)
{
return 333333;
}
static int i9xx_misc_get_display_clock_speed(struct drm_i915_private *dev_priv)
{
return 200000;
}
static int pnv_get_display_clock_speed(struct drm_i915_private *dev_priv)
{
struct pci_dev *pdev = dev_priv->drm.pdev;
u16 gcfgc = 0;
pci_read_config_word(pdev, GCFGC, &gcfgc);
switch (gcfgc & GC_DISPLAY_CLOCK_MASK) {
case GC_DISPLAY_CLOCK_267_MHZ_PNV:
return 266667;
case GC_DISPLAY_CLOCK_333_MHZ_PNV:
return 333333;
case GC_DISPLAY_CLOCK_444_MHZ_PNV:
return 444444;
case GC_DISPLAY_CLOCK_200_MHZ_PNV:
return 200000;
default:
DRM_ERROR("Unknown pnv display core clock 0x%04x\n", gcfgc);
case GC_DISPLAY_CLOCK_133_MHZ_PNV:
return 133333;
case GC_DISPLAY_CLOCK_167_MHZ_PNV:
return 166667;
}
}
static int i915gm_get_display_clock_speed(struct drm_i915_private *dev_priv)
{
struct pci_dev *pdev = dev_priv->drm.pdev;
u16 gcfgc = 0;
pci_read_config_word(pdev, GCFGC, &gcfgc);
if (gcfgc & GC_LOW_FREQUENCY_ENABLE)
return 133333;
else {
switch (gcfgc & GC_DISPLAY_CLOCK_MASK) {
case GC_DISPLAY_CLOCK_333_MHZ:
return 333333;
default:
case GC_DISPLAY_CLOCK_190_200_MHZ:
return 190000;
}
}
}
static int i865_get_display_clock_speed(struct drm_i915_private *dev_priv)
{
return 266667;
}
static int i85x_get_display_clock_speed(struct drm_i915_private *dev_priv)
{
struct pci_dev *pdev = dev_priv->drm.pdev;
u16 hpllcc = 0;
if (pdev->revision == 0x1)
return 133333;
pci_bus_read_config_word(pdev->bus,
PCI_DEVFN(0, 3), HPLLCC, &hpllcc);
switch (hpllcc & GC_CLOCK_CONTROL_MASK) {
case GC_CLOCK_133_200:
case GC_CLOCK_133_200_2:
case GC_CLOCK_100_200:
return 200000;
case GC_CLOCK_166_250:
return 250000;
case GC_CLOCK_100_133:
return 133333;
case GC_CLOCK_133_266:
case GC_CLOCK_133_266_2:
case GC_CLOCK_166_266:
return 266667;
}
return 0;
}
static int i830_get_display_clock_speed(struct drm_i915_private *dev_priv)
{
return 133333;
}
static unsigned int intel_hpll_vco(struct drm_i915_private *dev_priv)
{
static const unsigned int blb_vco[8] = {
[0] = 3200000,
[1] = 4000000,
[2] = 5333333,
[3] = 4800000,
[4] = 6400000,
};
static const unsigned int pnv_vco[8] = {
[0] = 3200000,
[1] = 4000000,
[2] = 5333333,
[3] = 4800000,
[4] = 2666667,
};
static const unsigned int cl_vco[8] = {
[0] = 3200000,
[1] = 4000000,
[2] = 5333333,
[3] = 6400000,
[4] = 3333333,
[5] = 3566667,
[6] = 4266667,
};
static const unsigned int elk_vco[8] = {
[0] = 3200000,
[1] = 4000000,
[2] = 5333333,
[3] = 4800000,
};
static const unsigned int ctg_vco[8] = {
[0] = 3200000,
[1] = 4000000,
[2] = 5333333,
[3] = 6400000,
[4] = 2666667,
[5] = 4266667,
};
const unsigned int *vco_table;
unsigned int vco;
uint8_t tmp = 0;
if (IS_GM45(dev_priv))
vco_table = ctg_vco;
else if (IS_G4X(dev_priv))
vco_table = elk_vco;
else if (IS_CRESTLINE(dev_priv))
vco_table = cl_vco;
else if (IS_PINEVIEW(dev_priv))
vco_table = pnv_vco;
else if (IS_G33(dev_priv))
vco_table = blb_vco;
else
return 0;
tmp = I915_READ(IS_MOBILE(dev_priv) ? HPLLVCO_MOBILE : HPLLVCO);
vco = vco_table[tmp & 0x7];
if (vco == 0)
DRM_ERROR("Bad HPLL VCO (HPLLVCO=0x%02x)\n", tmp);
else
DRM_DEBUG_KMS("HPLL VCO %u kHz\n", vco);
return vco;
}
static int gm45_get_display_clock_speed(struct drm_i915_private *dev_priv)
{
struct pci_dev *pdev = dev_priv->drm.pdev;
unsigned int cdclk_sel, vco = intel_hpll_vco(dev_priv);
uint16_t tmp = 0;
pci_read_config_word(pdev, GCFGC, &tmp);
cdclk_sel = (tmp >> 12) & 0x1;
switch (vco) {
case 2666667:
case 4000000:
case 5333333:
return cdclk_sel ? 333333 : 222222;
case 3200000:
return cdclk_sel ? 320000 : 228571;
default:
DRM_ERROR("Unable to determine CDCLK. HPLL VCO=%u, CFGC=0x%04x\n", vco, tmp);
return 222222;
}
}
static int i965gm_get_display_clock_speed(struct drm_i915_private *dev_priv)
{
struct pci_dev *pdev = dev_priv->drm.pdev;
static const uint8_t div_3200[] = { 16, 10, 8 };
static const uint8_t div_4000[] = { 20, 12, 10 };
static const uint8_t div_5333[] = { 24, 16, 14 };
const uint8_t *div_table;
unsigned int cdclk_sel, vco = intel_hpll_vco(dev_priv);
uint16_t tmp = 0;
pci_read_config_word(pdev, GCFGC, &tmp);
cdclk_sel = ((tmp >> 8) & 0x1f) - 1;
if (cdclk_sel >= ARRAY_SIZE(div_3200))
goto fail;
switch (vco) {
case 3200000:
div_table = div_3200;
break;
case 4000000:
div_table = div_4000;
break;
case 5333333:
div_table = div_5333;
break;
default:
goto fail;
}
return DIV_ROUND_CLOSEST(vco, div_table[cdclk_sel]);
fail:
DRM_ERROR("Unable to determine CDCLK. HPLL VCO=%u kHz, CFGC=0x%04x\n", vco, tmp);
return 200000;
}
static int g33_get_display_clock_speed(struct drm_i915_private *dev_priv)
{
struct pci_dev *pdev = dev_priv->drm.pdev;
static const uint8_t div_3200[] = { 12, 10, 8, 7, 5, 16 };
static const uint8_t div_4000[] = { 14, 12, 10, 8, 6, 20 };
static const uint8_t div_4800[] = { 20, 14, 12, 10, 8, 24 };
static const uint8_t div_5333[] = { 20, 16, 12, 12, 8, 28 };
const uint8_t *div_table;
unsigned int cdclk_sel, vco = intel_hpll_vco(dev_priv);
uint16_t tmp = 0;
pci_read_config_word(pdev, GCFGC, &tmp);
cdclk_sel = (tmp >> 4) & 0x7;
if (cdclk_sel >= ARRAY_SIZE(div_3200))
goto fail;
switch (vco) {
case 3200000:
div_table = div_3200;
break;
case 4000000:
div_table = div_4000;
break;
case 4800000:
div_table = div_4800;
break;
case 5333333:
div_table = div_5333;
break;
default:
goto fail;
}
return DIV_ROUND_CLOSEST(vco, div_table[cdclk_sel]);
fail:
DRM_ERROR("Unable to determine CDCLK. HPLL VCO=%u kHz, CFGC=0x%08x\n", vco, tmp);
return 190476;
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
static uint32_t pnv_dpll_compute_fp(struct dpll *dpll)
{
return (1 << dpll->n) << 16 | dpll->m2;
}
static uint32_t i9xx_dpll_compute_fp(struct dpll *dpll)
{
return dpll->n << 16 | dpll->m1 << 8 | dpll->m2;
}
static void i9xx_update_pll_dividers(struct intel_crtc *crtc,
struct intel_crtc_state *crtc_state,
struct dpll *reduced_clock)
{
struct drm_i915_private *dev_priv = to_i915(crtc->base.dev);
u32 fp, fp2 = 0;
if (IS_PINEVIEW(dev_priv)) {
fp = pnv_dpll_compute_fp(&crtc_state->dpll);
if (reduced_clock)
fp2 = pnv_dpll_compute_fp(reduced_clock);
} else {
fp = i9xx_dpll_compute_fp(&crtc_state->dpll);
if (reduced_clock)
fp2 = i9xx_dpll_compute_fp(reduced_clock);
}
crtc_state->dpll_hw_state.fp0 = fp;
crtc->lowfreq_avail = false;
if (intel_crtc_has_type(crtc_state, INTEL_OUTPUT_LVDS) &&
reduced_clock) {
crtc_state->dpll_hw_state.fp1 = fp2;
crtc->lowfreq_avail = true;
} else {
crtc_state->dpll_hw_state.fp1 = fp;
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
struct drm_i915_private *dev_priv = to_i915(dev);
int pipe = crtc->pipe;
I915_WRITE(PCH_TRANS_DATA_M1(pipe), TU_SIZE(m_n->tu) | m_n->gmch_m);
I915_WRITE(PCH_TRANS_DATA_N1(pipe), m_n->gmch_n);
I915_WRITE(PCH_TRANS_LINK_M1(pipe), m_n->link_m);
I915_WRITE(PCH_TRANS_LINK_N1(pipe), m_n->link_n);
}
static void intel_cpu_transcoder_set_m_n(struct intel_crtc *crtc,
struct intel_link_m_n *m_n,
struct intel_link_m_n *m2_n2)
{
struct drm_i915_private *dev_priv = to_i915(crtc->base.dev);
int pipe = crtc->pipe;
enum transcoder transcoder = crtc->config->cpu_transcoder;
if (INTEL_GEN(dev_priv) >= 5) {
I915_WRITE(PIPE_DATA_M1(transcoder), TU_SIZE(m_n->tu) | m_n->gmch_m);
I915_WRITE(PIPE_DATA_N1(transcoder), m_n->gmch_n);
I915_WRITE(PIPE_LINK_M1(transcoder), m_n->link_m);
I915_WRITE(PIPE_LINK_N1(transcoder), m_n->link_n);
if (m2_n2 && (IS_CHERRYVIEW(dev_priv) ||
INTEL_GEN(dev_priv) < 8) && crtc->config->has_drrs) {
I915_WRITE(PIPE_DATA_M2(transcoder),
TU_SIZE(m2_n2->tu) | m2_n2->gmch_m);
I915_WRITE(PIPE_DATA_N2(transcoder), m2_n2->gmch_n);
I915_WRITE(PIPE_LINK_M2(transcoder), m2_n2->link_m);
I915_WRITE(PIPE_LINK_N2(transcoder), m2_n2->link_n);
}
} else {
I915_WRITE(PIPE_DATA_M_G4X(pipe), TU_SIZE(m_n->tu) | m_n->gmch_m);
I915_WRITE(PIPE_DATA_N_G4X(pipe), m_n->gmch_n);
I915_WRITE(PIPE_LINK_M_G4X(pipe), m_n->link_m);
I915_WRITE(PIPE_LINK_N_G4X(pipe), m_n->link_n);
}
}
void intel_dp_set_m_n(struct intel_crtc *crtc, enum link_m_n_set m_n)
{
struct intel_link_m_n *dp_m_n, *dp_m2_n2 = NULL;
if (m_n == M1_N1) {
dp_m_n = &crtc->config->dp_m_n;
dp_m2_n2 = &crtc->config->dp_m2_n2;
} else if (m_n == M2_N2) {
dp_m_n = &crtc->config->dp_m2_n2;
} else {
DRM_ERROR("Unsupported divider value\n");
return;
}
if (crtc->config->has_pch_encoder)
intel_pch_transcoder_set_m_n(crtc, &crtc->config->dp_m_n);
else
intel_cpu_transcoder_set_m_n(crtc, dp_m_n, dp_m2_n2);
}
static void vlv_compute_dpll(struct intel_crtc *crtc,
struct intel_crtc_state *pipe_config)
{
pipe_config->dpll_hw_state.dpll = DPLL_INTEGRATED_REF_CLK_VLV |
DPLL_REF_CLK_ENABLE_VLV | DPLL_VGA_MODE_DIS;
if (crtc->pipe != PIPE_A)
pipe_config->dpll_hw_state.dpll |= DPLL_INTEGRATED_CRI_CLK_VLV;
if (!intel_crtc_has_type(pipe_config, INTEL_OUTPUT_DSI))
pipe_config->dpll_hw_state.dpll |= DPLL_VCO_ENABLE |
DPLL_EXT_BUFFER_ENABLE_VLV;
pipe_config->dpll_hw_state.dpll_md =
(pipe_config->pixel_multiplier - 1) << DPLL_MD_UDI_MULTIPLIER_SHIFT;
}
static void chv_compute_dpll(struct intel_crtc *crtc,
struct intel_crtc_state *pipe_config)
{
pipe_config->dpll_hw_state.dpll = DPLL_SSC_REF_CLK_CHV |
DPLL_REF_CLK_ENABLE_VLV | DPLL_VGA_MODE_DIS;
if (crtc->pipe != PIPE_A)
pipe_config->dpll_hw_state.dpll |= DPLL_INTEGRATED_CRI_CLK_VLV;
if (!intel_crtc_has_type(pipe_config, INTEL_OUTPUT_DSI))
pipe_config->dpll_hw_state.dpll |= DPLL_VCO_ENABLE;
pipe_config->dpll_hw_state.dpll_md =
(pipe_config->pixel_multiplier - 1) << DPLL_MD_UDI_MULTIPLIER_SHIFT;
}
static void vlv_prepare_pll(struct intel_crtc *crtc,
const struct intel_crtc_state *pipe_config)
{
struct drm_device *dev = crtc->base.dev;
struct drm_i915_private *dev_priv = to_i915(dev);
enum pipe pipe = crtc->pipe;
u32 mdiv;
u32 bestn, bestm1, bestm2, bestp1, bestp2;
u32 coreclk, reg_val;
I915_WRITE(DPLL(pipe),
pipe_config->dpll_hw_state.dpll &
~(DPLL_VCO_ENABLE | DPLL_EXT_BUFFER_ENABLE_VLV));
if ((pipe_config->dpll_hw_state.dpll & DPLL_VCO_ENABLE) == 0)
return;
mutex_lock(&dev_priv->sb_lock);
bestn = pipe_config->dpll.n;
bestm1 = pipe_config->dpll.m1;
bestm2 = pipe_config->dpll.m2;
bestp1 = pipe_config->dpll.p1;
bestp2 = pipe_config->dpll.p2;
if (pipe == PIPE_B)
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
if (pipe_config->port_clock == 162000 ||
intel_crtc_has_type(crtc->config, INTEL_OUTPUT_ANALOG) ||
intel_crtc_has_type(crtc->config, INTEL_OUTPUT_HDMI))
vlv_dpio_write(dev_priv, pipe, VLV_PLL_DW10(pipe),
0x009f0003);
else
vlv_dpio_write(dev_priv, pipe, VLV_PLL_DW10(pipe),
0x00d0000f);
if (intel_crtc_has_dp_encoder(pipe_config)) {
if (pipe == PIPE_A)
vlv_dpio_write(dev_priv, pipe, VLV_PLL_DW5(pipe),
0x0df40000);
else
vlv_dpio_write(dev_priv, pipe, VLV_PLL_DW5(pipe),
0x0df70000);
} else {
if (pipe == PIPE_A)
vlv_dpio_write(dev_priv, pipe, VLV_PLL_DW5(pipe),
0x0df70000);
else
vlv_dpio_write(dev_priv, pipe, VLV_PLL_DW5(pipe),
0x0df40000);
}
coreclk = vlv_dpio_read(dev_priv, pipe, VLV_PLL_DW7(pipe));
coreclk = (coreclk & 0x0000ff00) | 0x01c00000;
if (intel_crtc_has_dp_encoder(crtc->config))
coreclk |= 0x01000000;
vlv_dpio_write(dev_priv, pipe, VLV_PLL_DW7(pipe), coreclk);
vlv_dpio_write(dev_priv, pipe, VLV_PLL_DW11(pipe), 0x87871000);
mutex_unlock(&dev_priv->sb_lock);
}
static void chv_prepare_pll(struct intel_crtc *crtc,
const struct intel_crtc_state *pipe_config)
{
struct drm_device *dev = crtc->base.dev;
struct drm_i915_private *dev_priv = to_i915(dev);
enum pipe pipe = crtc->pipe;
enum dpio_channel port = vlv_pipe_to_channel(pipe);
u32 loopfilter, tribuf_calcntr;
u32 bestn, bestm1, bestm2, bestp1, bestp2, bestm2_frac;
u32 dpio_val;
int vco;
I915_WRITE(DPLL(pipe),
pipe_config->dpll_hw_state.dpll & ~DPLL_VCO_ENABLE);
if ((pipe_config->dpll_hw_state.dpll & DPLL_VCO_ENABLE) == 0)
return;
bestn = pipe_config->dpll.n;
bestm2_frac = pipe_config->dpll.m2 & 0x3fffff;
bestm1 = pipe_config->dpll.m1;
bestm2 = pipe_config->dpll.m2 >> 22;
bestp1 = pipe_config->dpll.p1;
bestp2 = pipe_config->dpll.p2;
vco = pipe_config->dpll.vco;
dpio_val = 0;
loopfilter = 0;
mutex_lock(&dev_priv->sb_lock);
vlv_dpio_write(dev_priv, pipe, CHV_CMN_DW13(port),
5 << DPIO_CHV_S1_DIV_SHIFT |
bestp1 << DPIO_CHV_P1_DIV_SHIFT |
bestp2 << DPIO_CHV_P2_DIV_SHIFT |
1 << DPIO_CHV_K_DIV_SHIFT);
vlv_dpio_write(dev_priv, pipe, CHV_PLL_DW0(port), bestm2);
vlv_dpio_write(dev_priv, pipe, CHV_PLL_DW1(port),
DPIO_CHV_M1_DIV_BY_2 |
1 << DPIO_CHV_N_DIV_SHIFT);
vlv_dpio_write(dev_priv, pipe, CHV_PLL_DW2(port), bestm2_frac);
dpio_val = vlv_dpio_read(dev_priv, pipe, CHV_PLL_DW3(port));
dpio_val &= ~(DPIO_CHV_FEEDFWD_GAIN_MASK | DPIO_CHV_FRAC_DIV_EN);
dpio_val |= (2 << DPIO_CHV_FEEDFWD_GAIN_SHIFT);
if (bestm2_frac)
dpio_val |= DPIO_CHV_FRAC_DIV_EN;
vlv_dpio_write(dev_priv, pipe, CHV_PLL_DW3(port), dpio_val);
dpio_val = vlv_dpio_read(dev_priv, pipe, CHV_PLL_DW9(port));
dpio_val &= ~(DPIO_CHV_INT_LOCK_THRESHOLD_MASK |
DPIO_CHV_INT_LOCK_THRESHOLD_SEL_COARSE);
dpio_val |= (0x5 << DPIO_CHV_INT_LOCK_THRESHOLD_SHIFT);
if (!bestm2_frac)
dpio_val |= DPIO_CHV_INT_LOCK_THRESHOLD_SEL_COARSE;
vlv_dpio_write(dev_priv, pipe, CHV_PLL_DW9(port), dpio_val);
if (vco == 5400000) {
loopfilter |= (0x3 << DPIO_CHV_PROP_COEFF_SHIFT);
loopfilter |= (0x8 << DPIO_CHV_INT_COEFF_SHIFT);
loopfilter |= (0x1 << DPIO_CHV_GAIN_CTRL_SHIFT);
tribuf_calcntr = 0x9;
} else if (vco <= 6200000) {
loopfilter |= (0x5 << DPIO_CHV_PROP_COEFF_SHIFT);
loopfilter |= (0xB << DPIO_CHV_INT_COEFF_SHIFT);
loopfilter |= (0x3 << DPIO_CHV_GAIN_CTRL_SHIFT);
tribuf_calcntr = 0x9;
} else if (vco <= 6480000) {
loopfilter |= (0x4 << DPIO_CHV_PROP_COEFF_SHIFT);
loopfilter |= (0x9 << DPIO_CHV_INT_COEFF_SHIFT);
loopfilter |= (0x3 << DPIO_CHV_GAIN_CTRL_SHIFT);
tribuf_calcntr = 0x8;
} else {
loopfilter |= (0x4 << DPIO_CHV_PROP_COEFF_SHIFT);
loopfilter |= (0x9 << DPIO_CHV_INT_COEFF_SHIFT);
loopfilter |= (0x3 << DPIO_CHV_GAIN_CTRL_SHIFT);
tribuf_calcntr = 0;
}
vlv_dpio_write(dev_priv, pipe, CHV_PLL_DW6(port), loopfilter);
dpio_val = vlv_dpio_read(dev_priv, pipe, CHV_PLL_DW8(port));
dpio_val &= ~DPIO_CHV_TDC_TARGET_CNT_MASK;
dpio_val |= (tribuf_calcntr << DPIO_CHV_TDC_TARGET_CNT_SHIFT);
vlv_dpio_write(dev_priv, pipe, CHV_PLL_DW8(port), dpio_val);
vlv_dpio_write(dev_priv, pipe, CHV_CMN_DW14(port),
vlv_dpio_read(dev_priv, pipe, CHV_CMN_DW14(port)) |
DPIO_AFC_RECAL);
mutex_unlock(&dev_priv->sb_lock);
}
int vlv_force_pll_on(struct drm_i915_private *dev_priv, enum pipe pipe,
const struct dpll *dpll)
{
struct intel_crtc *crtc = intel_get_crtc_for_pipe(dev_priv, pipe);
struct intel_crtc_state *pipe_config;
pipe_config = kzalloc(sizeof(*pipe_config), GFP_KERNEL);
if (!pipe_config)
return -ENOMEM;
pipe_config->base.crtc = &crtc->base;
pipe_config->pixel_multiplier = 1;
pipe_config->dpll = *dpll;
if (IS_CHERRYVIEW(dev_priv)) {
chv_compute_dpll(crtc, pipe_config);
chv_prepare_pll(crtc, pipe_config);
chv_enable_pll(crtc, pipe_config);
} else {
vlv_compute_dpll(crtc, pipe_config);
vlv_prepare_pll(crtc, pipe_config);
vlv_enable_pll(crtc, pipe_config);
}
kfree(pipe_config);
return 0;
}
void vlv_force_pll_off(struct drm_i915_private *dev_priv, enum pipe pipe)
{
if (IS_CHERRYVIEW(dev_priv))
chv_disable_pll(dev_priv, pipe);
else
vlv_disable_pll(dev_priv, pipe);
}
static void i9xx_compute_dpll(struct intel_crtc *crtc,
struct intel_crtc_state *crtc_state,
struct dpll *reduced_clock)
{
struct drm_i915_private *dev_priv = to_i915(crtc->base.dev);
u32 dpll;
struct dpll *clock = &crtc_state->dpll;
i9xx_update_pll_dividers(crtc, crtc_state, reduced_clock);
dpll = DPLL_VGA_MODE_DIS;
if (intel_crtc_has_type(crtc_state, INTEL_OUTPUT_LVDS))
dpll |= DPLLB_MODE_LVDS;
else
dpll |= DPLLB_MODE_DAC_SERIAL;
if (IS_I945G(dev_priv) || IS_I945GM(dev_priv) || IS_G33(dev_priv)) {
dpll |= (crtc_state->pixel_multiplier - 1)
<< SDVO_MULTIPLIER_SHIFT_HIRES;
}
if (intel_crtc_has_type(crtc_state, INTEL_OUTPUT_SDVO) ||
intel_crtc_has_type(crtc_state, INTEL_OUTPUT_HDMI))
dpll |= DPLL_SDVO_HIGH_SPEED;
if (intel_crtc_has_dp_encoder(crtc_state))
dpll |= DPLL_SDVO_HIGH_SPEED;
if (IS_PINEVIEW(dev_priv))
dpll |= (1 << (clock->p1 - 1)) << DPLL_FPA01_P1_POST_DIV_SHIFT_PINEVIEW;
else {
dpll |= (1 << (clock->p1 - 1)) << DPLL_FPA01_P1_POST_DIV_SHIFT;
if (IS_G4X(dev_priv) && reduced_clock)
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
if (INTEL_GEN(dev_priv) >= 4)
dpll |= (6 << PLL_LOAD_PULSE_PHASE_SHIFT);
if (crtc_state->sdvo_tv_clock)
dpll |= PLL_REF_INPUT_TVCLKINBC;
else if (intel_crtc_has_type(crtc_state, INTEL_OUTPUT_LVDS) &&
intel_panel_use_ssc(dev_priv))
dpll |= PLLB_REF_INPUT_SPREADSPECTRUMIN;
else
dpll |= PLL_REF_INPUT_DREFCLK;
dpll |= DPLL_VCO_ENABLE;
crtc_state->dpll_hw_state.dpll = dpll;
if (INTEL_GEN(dev_priv) >= 4) {
u32 dpll_md = (crtc_state->pixel_multiplier - 1)
<< DPLL_MD_UDI_MULTIPLIER_SHIFT;
crtc_state->dpll_hw_state.dpll_md = dpll_md;
}
}
static void i8xx_compute_dpll(struct intel_crtc *crtc,
struct intel_crtc_state *crtc_state,
struct dpll *reduced_clock)
{
struct drm_device *dev = crtc->base.dev;
struct drm_i915_private *dev_priv = to_i915(dev);
u32 dpll;
struct dpll *clock = &crtc_state->dpll;
i9xx_update_pll_dividers(crtc, crtc_state, reduced_clock);
dpll = DPLL_VGA_MODE_DIS;
if (intel_crtc_has_type(crtc_state, INTEL_OUTPUT_LVDS)) {
dpll |= (1 << (clock->p1 - 1)) << DPLL_FPA01_P1_POST_DIV_SHIFT;
} else {
if (clock->p1 == 2)
dpll |= PLL_P1_DIVIDE_BY_TWO;
else
dpll |= (clock->p1 - 2) << DPLL_FPA01_P1_POST_DIV_SHIFT;
if (clock->p2 == 4)
dpll |= PLL_P2_DIVIDE_BY_4;
}
if (!IS_I830(dev_priv) &&
intel_crtc_has_type(crtc_state, INTEL_OUTPUT_DVO))
dpll |= DPLL_DVO_2X_MODE;
if (intel_crtc_has_type(crtc_state, INTEL_OUTPUT_LVDS) &&
intel_panel_use_ssc(dev_priv))
dpll |= PLLB_REF_INPUT_SPREADSPECTRUMIN;
else
dpll |= PLL_REF_INPUT_DREFCLK;
dpll |= DPLL_VCO_ENABLE;
crtc_state->dpll_hw_state.dpll = dpll;
}
static void intel_set_pipe_timings(struct intel_crtc *intel_crtc)
{
struct drm_i915_private *dev_priv = to_i915(intel_crtc->base.dev);
enum pipe pipe = intel_crtc->pipe;
enum transcoder cpu_transcoder = intel_crtc->config->cpu_transcoder;
const struct drm_display_mode *adjusted_mode = &intel_crtc->config->base.adjusted_mode;
uint32_t crtc_vtotal, crtc_vblank_end;
int vsyncshift = 0;
crtc_vtotal = adjusted_mode->crtc_vtotal;
crtc_vblank_end = adjusted_mode->crtc_vblank_end;
if (adjusted_mode->flags & DRM_MODE_FLAG_INTERLACE) {
crtc_vtotal -= 1;
crtc_vblank_end -= 1;
if (intel_crtc_has_type(intel_crtc->config, INTEL_OUTPUT_SDVO))
vsyncshift = (adjusted_mode->crtc_htotal - 1) / 2;
else
vsyncshift = adjusted_mode->crtc_hsync_start -
adjusted_mode->crtc_htotal / 2;
if (vsyncshift < 0)
vsyncshift += adjusted_mode->crtc_htotal;
}
if (INTEL_GEN(dev_priv) > 3)
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
if (IS_HASWELL(dev_priv) && cpu_transcoder == TRANSCODER_EDP &&
(pipe == PIPE_B || pipe == PIPE_C))
I915_WRITE(VTOTAL(pipe), I915_READ(VTOTAL(cpu_transcoder)));
}
static void intel_set_pipe_src_size(struct intel_crtc *intel_crtc)
{
struct drm_device *dev = intel_crtc->base.dev;
struct drm_i915_private *dev_priv = to_i915(dev);
enum pipe pipe = intel_crtc->pipe;
I915_WRITE(PIPESRC(pipe),
((intel_crtc->config->pipe_src_w - 1) << 16) |
(intel_crtc->config->pipe_src_h - 1));
}
static void intel_get_pipe_timings(struct intel_crtc *crtc,
struct intel_crtc_state *pipe_config)
{
struct drm_device *dev = crtc->base.dev;
struct drm_i915_private *dev_priv = to_i915(dev);
enum transcoder cpu_transcoder = pipe_config->cpu_transcoder;
uint32_t tmp;
tmp = I915_READ(HTOTAL(cpu_transcoder));
pipe_config->base.adjusted_mode.crtc_hdisplay = (tmp & 0xffff) + 1;
pipe_config->base.adjusted_mode.crtc_htotal = ((tmp >> 16) & 0xffff) + 1;
tmp = I915_READ(HBLANK(cpu_transcoder));
pipe_config->base.adjusted_mode.crtc_hblank_start = (tmp & 0xffff) + 1;
pipe_config->base.adjusted_mode.crtc_hblank_end = ((tmp >> 16) & 0xffff) + 1;
tmp = I915_READ(HSYNC(cpu_transcoder));
pipe_config->base.adjusted_mode.crtc_hsync_start = (tmp & 0xffff) + 1;
pipe_config->base.adjusted_mode.crtc_hsync_end = ((tmp >> 16) & 0xffff) + 1;
tmp = I915_READ(VTOTAL(cpu_transcoder));
pipe_config->base.adjusted_mode.crtc_vdisplay = (tmp & 0xffff) + 1;
pipe_config->base.adjusted_mode.crtc_vtotal = ((tmp >> 16) & 0xffff) + 1;
tmp = I915_READ(VBLANK(cpu_transcoder));
pipe_config->base.adjusted_mode.crtc_vblank_start = (tmp & 0xffff) + 1;
pipe_config->base.adjusted_mode.crtc_vblank_end = ((tmp >> 16) & 0xffff) + 1;
tmp = I915_READ(VSYNC(cpu_transcoder));
pipe_config->base.adjusted_mode.crtc_vsync_start = (tmp & 0xffff) + 1;
pipe_config->base.adjusted_mode.crtc_vsync_end = ((tmp >> 16) & 0xffff) + 1;
if (I915_READ(PIPECONF(cpu_transcoder)) & PIPECONF_INTERLACE_MASK) {
pipe_config->base.adjusted_mode.flags |= DRM_MODE_FLAG_INTERLACE;
pipe_config->base.adjusted_mode.crtc_vtotal += 1;
pipe_config->base.adjusted_mode.crtc_vblank_end += 1;
}
}
static void intel_get_pipe_src_size(struct intel_crtc *crtc,
struct intel_crtc_state *pipe_config)
{
struct drm_device *dev = crtc->base.dev;
struct drm_i915_private *dev_priv = to_i915(dev);
u32 tmp;
tmp = I915_READ(PIPESRC(crtc->pipe));
pipe_config->pipe_src_h = (tmp & 0xffff) + 1;
pipe_config->pipe_src_w = ((tmp >> 16) & 0xffff) + 1;
pipe_config->base.mode.vdisplay = pipe_config->pipe_src_h;
pipe_config->base.mode.hdisplay = pipe_config->pipe_src_w;
}
void intel_mode_from_pipe_config(struct drm_display_mode *mode,
struct intel_crtc_state *pipe_config)
{
mode->hdisplay = pipe_config->base.adjusted_mode.crtc_hdisplay;
mode->htotal = pipe_config->base.adjusted_mode.crtc_htotal;
mode->hsync_start = pipe_config->base.adjusted_mode.crtc_hsync_start;
mode->hsync_end = pipe_config->base.adjusted_mode.crtc_hsync_end;
mode->vdisplay = pipe_config->base.adjusted_mode.crtc_vdisplay;
mode->vtotal = pipe_config->base.adjusted_mode.crtc_vtotal;
mode->vsync_start = pipe_config->base.adjusted_mode.crtc_vsync_start;
mode->vsync_end = pipe_config->base.adjusted_mode.crtc_vsync_end;
mode->flags = pipe_config->base.adjusted_mode.flags;
mode->type = DRM_MODE_TYPE_DRIVER;
mode->clock = pipe_config->base.adjusted_mode.crtc_clock;
mode->flags |= pipe_config->base.adjusted_mode.flags;
mode->hsync = drm_mode_hsync(mode);
mode->vrefresh = drm_mode_vrefresh(mode);
drm_mode_set_name(mode);
}
static void i9xx_set_pipeconf(struct intel_crtc *intel_crtc)
{
struct drm_i915_private *dev_priv = to_i915(intel_crtc->base.dev);
uint32_t pipeconf;
pipeconf = 0;
if ((intel_crtc->pipe == PIPE_A && dev_priv->quirks & QUIRK_PIPEA_FORCE) ||
(intel_crtc->pipe == PIPE_B && dev_priv->quirks & QUIRK_PIPEB_FORCE))
pipeconf |= I915_READ(PIPECONF(intel_crtc->pipe)) & PIPECONF_ENABLE;
if (intel_crtc->config->double_wide)
pipeconf |= PIPECONF_DOUBLE_WIDE;
if (IS_G4X(dev_priv) || IS_VALLEYVIEW(dev_priv) ||
IS_CHERRYVIEW(dev_priv)) {
if (intel_crtc->config->dither && intel_crtc->config->pipe_bpp != 30)
pipeconf |= PIPECONF_DITHER_EN |
PIPECONF_DITHER_TYPE_SP;
switch (intel_crtc->config->pipe_bpp) {
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
if (HAS_PIPE_CXSR(dev_priv)) {
if (intel_crtc->lowfreq_avail) {
DRM_DEBUG_KMS("enabling CxSR downclocking\n");
pipeconf |= PIPECONF_CXSR_DOWNCLOCK;
} else {
DRM_DEBUG_KMS("disabling CxSR downclocking\n");
}
}
if (intel_crtc->config->base.adjusted_mode.flags & DRM_MODE_FLAG_INTERLACE) {
if (INTEL_GEN(dev_priv) < 4 ||
intel_crtc_has_type(intel_crtc->config, INTEL_OUTPUT_SDVO))
pipeconf |= PIPECONF_INTERLACE_W_FIELD_INDICATION;
else
pipeconf |= PIPECONF_INTERLACE_W_SYNC_SHIFT;
} else
pipeconf |= PIPECONF_PROGRESSIVE;
if ((IS_VALLEYVIEW(dev_priv) || IS_CHERRYVIEW(dev_priv)) &&
intel_crtc->config->limited_color_range)
pipeconf |= PIPECONF_COLOR_RANGE_SELECT;
I915_WRITE(PIPECONF(intel_crtc->pipe), pipeconf);
POSTING_READ(PIPECONF(intel_crtc->pipe));
}
static int i8xx_crtc_compute_clock(struct intel_crtc *crtc,
struct intel_crtc_state *crtc_state)
{
struct drm_device *dev = crtc->base.dev;
struct drm_i915_private *dev_priv = to_i915(dev);
const struct intel_limit *limit;
int refclk = 48000;
memset(&crtc_state->dpll_hw_state, 0,
sizeof(crtc_state->dpll_hw_state));
if (intel_crtc_has_type(crtc_state, INTEL_OUTPUT_LVDS)) {
if (intel_panel_use_ssc(dev_priv)) {
refclk = dev_priv->vbt.lvds_ssc_freq;
DRM_DEBUG_KMS("using SSC reference clock of %d kHz\n", refclk);
}
limit = &intel_limits_i8xx_lvds;
} else if (intel_crtc_has_type(crtc_state, INTEL_OUTPUT_DVO)) {
limit = &intel_limits_i8xx_dvo;
} else {
limit = &intel_limits_i8xx_dac;
}
if (!crtc_state->clock_set &&
!i9xx_find_best_dpll(limit, crtc_state, crtc_state->port_clock,
refclk, NULL, &crtc_state->dpll)) {
DRM_ERROR("Couldn't find PLL settings for mode!\n");
return -EINVAL;
}
i8xx_compute_dpll(crtc, crtc_state, NULL);
return 0;
}
static int g4x_crtc_compute_clock(struct intel_crtc *crtc,
struct intel_crtc_state *crtc_state)
{
struct drm_device *dev = crtc->base.dev;
struct drm_i915_private *dev_priv = to_i915(dev);
const struct intel_limit *limit;
int refclk = 96000;
memset(&crtc_state->dpll_hw_state, 0,
sizeof(crtc_state->dpll_hw_state));
if (intel_crtc_has_type(crtc_state, INTEL_OUTPUT_LVDS)) {
if (intel_panel_use_ssc(dev_priv)) {
refclk = dev_priv->vbt.lvds_ssc_freq;
DRM_DEBUG_KMS("using SSC reference clock of %d kHz\n", refclk);
}
if (intel_is_dual_link_lvds(dev))
limit = &intel_limits_g4x_dual_channel_lvds;
else
limit = &intel_limits_g4x_single_channel_lvds;
} else if (intel_crtc_has_type(crtc_state, INTEL_OUTPUT_HDMI) ||
intel_crtc_has_type(crtc_state, INTEL_OUTPUT_ANALOG)) {
limit = &intel_limits_g4x_hdmi;
} else if (intel_crtc_has_type(crtc_state, INTEL_OUTPUT_SDVO)) {
limit = &intel_limits_g4x_sdvo;
} else {
limit = &intel_limits_i9xx_sdvo;
}
if (!crtc_state->clock_set &&
!g4x_find_best_dpll(limit, crtc_state, crtc_state->port_clock,
refclk, NULL, &crtc_state->dpll)) {
DRM_ERROR("Couldn't find PLL settings for mode!\n");
return -EINVAL;
}
i9xx_compute_dpll(crtc, crtc_state, NULL);
return 0;
}
static int pnv_crtc_compute_clock(struct intel_crtc *crtc,
struct intel_crtc_state *crtc_state)
{
struct drm_device *dev = crtc->base.dev;
struct drm_i915_private *dev_priv = to_i915(dev);
const struct intel_limit *limit;
int refclk = 96000;
memset(&crtc_state->dpll_hw_state, 0,
sizeof(crtc_state->dpll_hw_state));
if (intel_crtc_has_type(crtc_state, INTEL_OUTPUT_LVDS)) {
if (intel_panel_use_ssc(dev_priv)) {
refclk = dev_priv->vbt.lvds_ssc_freq;
DRM_DEBUG_KMS("using SSC reference clock of %d kHz\n", refclk);
}
limit = &intel_limits_pineview_lvds;
} else {
limit = &intel_limits_pineview_sdvo;
}
if (!crtc_state->clock_set &&
!pnv_find_best_dpll(limit, crtc_state, crtc_state->port_clock,
refclk, NULL, &crtc_state->dpll)) {
DRM_ERROR("Couldn't find PLL settings for mode!\n");
return -EINVAL;
}
i9xx_compute_dpll(crtc, crtc_state, NULL);
return 0;
}
static int i9xx_crtc_compute_clock(struct intel_crtc *crtc,
struct intel_crtc_state *crtc_state)
{
struct drm_device *dev = crtc->base.dev;
struct drm_i915_private *dev_priv = to_i915(dev);
const struct intel_limit *limit;
int refclk = 96000;
memset(&crtc_state->dpll_hw_state, 0,
sizeof(crtc_state->dpll_hw_state));
if (intel_crtc_has_type(crtc_state, INTEL_OUTPUT_LVDS)) {
if (intel_panel_use_ssc(dev_priv)) {
refclk = dev_priv->vbt.lvds_ssc_freq;
DRM_DEBUG_KMS("using SSC reference clock of %d kHz\n", refclk);
}
limit = &intel_limits_i9xx_lvds;
} else {
limit = &intel_limits_i9xx_sdvo;
}
if (!crtc_state->clock_set &&
!i9xx_find_best_dpll(limit, crtc_state, crtc_state->port_clock,
refclk, NULL, &crtc_state->dpll)) {
DRM_ERROR("Couldn't find PLL settings for mode!\n");
return -EINVAL;
}
i9xx_compute_dpll(crtc, crtc_state, NULL);
return 0;
}
static int chv_crtc_compute_clock(struct intel_crtc *crtc,
struct intel_crtc_state *crtc_state)
{
int refclk = 100000;
const struct intel_limit *limit = &intel_limits_chv;
memset(&crtc_state->dpll_hw_state, 0,
sizeof(crtc_state->dpll_hw_state));
if (!crtc_state->clock_set &&
!chv_find_best_dpll(limit, crtc_state, crtc_state->port_clock,
refclk, NULL, &crtc_state->dpll)) {
DRM_ERROR("Couldn't find PLL settings for mode!\n");
return -EINVAL;
}
chv_compute_dpll(crtc, crtc_state);
return 0;
}
static int vlv_crtc_compute_clock(struct intel_crtc *crtc,
struct intel_crtc_state *crtc_state)
{
int refclk = 100000;
const struct intel_limit *limit = &intel_limits_vlv;
memset(&crtc_state->dpll_hw_state, 0,
sizeof(crtc_state->dpll_hw_state));
if (!crtc_state->clock_set &&
!vlv_find_best_dpll(limit, crtc_state, crtc_state->port_clock,
refclk, NULL, &crtc_state->dpll)) {
DRM_ERROR("Couldn't find PLL settings for mode!\n");
return -EINVAL;
}
vlv_compute_dpll(crtc, crtc_state);
return 0;
}
static void i9xx_get_pfit_config(struct intel_crtc *crtc,
struct intel_crtc_state *pipe_config)
{
struct drm_i915_private *dev_priv = to_i915(crtc->base.dev);
uint32_t tmp;
if (INTEL_GEN(dev_priv) <= 3 &&
(IS_I830(dev_priv) || !IS_MOBILE(dev_priv)))
return;
tmp = I915_READ(PFIT_CONTROL);
if (!(tmp & PFIT_ENABLE))
return;
if (INTEL_GEN(dev_priv) < 4) {
if (crtc->pipe != PIPE_B)
return;
} else {
if ((tmp & PFIT_PIPE_MASK) != (crtc->pipe << PFIT_PIPE_SHIFT))
return;
}
pipe_config->gmch_pfit.control = tmp;
pipe_config->gmch_pfit.pgm_ratios = I915_READ(PFIT_PGM_RATIOS);
}
static void vlv_crtc_clock_get(struct intel_crtc *crtc,
struct intel_crtc_state *pipe_config)
{
struct drm_device *dev = crtc->base.dev;
struct drm_i915_private *dev_priv = to_i915(dev);
int pipe = pipe_config->cpu_transcoder;
struct dpll clock;
u32 mdiv;
int refclk = 100000;
if ((pipe_config->dpll_hw_state.dpll & DPLL_VCO_ENABLE) == 0)
return;
mutex_lock(&dev_priv->sb_lock);
mdiv = vlv_dpio_read(dev_priv, pipe, VLV_PLL_DW3(pipe));
mutex_unlock(&dev_priv->sb_lock);
clock.m1 = (mdiv >> DPIO_M1DIV_SHIFT) & 7;
clock.m2 = mdiv & DPIO_M2DIV_MASK;
clock.n = (mdiv >> DPIO_N_SHIFT) & 0xf;
clock.p1 = (mdiv >> DPIO_P1_SHIFT) & 7;
clock.p2 = (mdiv >> DPIO_P2_SHIFT) & 0x1f;
pipe_config->port_clock = vlv_calc_dpll_params(refclk, &clock);
}
static void
i9xx_get_initial_plane_config(struct intel_crtc *crtc,
struct intel_initial_plane_config *plane_config)
{
struct drm_device *dev = crtc->base.dev;
struct drm_i915_private *dev_priv = to_i915(dev);
u32 val, base, offset;
int pipe = crtc->pipe, plane = crtc->plane;
int fourcc, pixel_format;
unsigned int aligned_height;
struct drm_framebuffer *fb;
struct intel_framebuffer *intel_fb;
val = I915_READ(DSPCNTR(plane));
if (!(val & DISPLAY_PLANE_ENABLE))
return;
intel_fb = kzalloc(sizeof(*intel_fb), GFP_KERNEL);
if (!intel_fb) {
DRM_DEBUG_KMS("failed to alloc fb\n");
return;
}
fb = &intel_fb->base;
if (INTEL_GEN(dev_priv) >= 4) {
if (val & DISPPLANE_TILED) {
plane_config->tiling = I915_TILING_X;
fb->modifier = I915_FORMAT_MOD_X_TILED;
}
}
pixel_format = val & DISPPLANE_PIXFORMAT_MASK;
fourcc = i9xx_format_to_fourcc(pixel_format);
fb->pixel_format = fourcc;
fb->bits_per_pixel = drm_format_plane_cpp(fourcc, 0) * 8;
if (INTEL_GEN(dev_priv) >= 4) {
if (plane_config->tiling)
offset = I915_READ(DSPTILEOFF(plane));
else
offset = I915_READ(DSPLINOFF(plane));
base = I915_READ(DSPSURF(plane)) & 0xfffff000;
} else {
base = I915_READ(DSPADDR(plane));
}
plane_config->base = base;
val = I915_READ(PIPESRC(pipe));
fb->width = ((val >> 16) & 0xfff) + 1;
fb->height = ((val >> 0) & 0xfff) + 1;
val = I915_READ(DSPSTRIDE(pipe));
fb->pitches[0] = val & 0xffffffc0;
aligned_height = intel_fb_align_height(dev, fb->height,
fb->pixel_format,
fb->modifier);
plane_config->size = fb->pitches[0] * aligned_height;
DRM_DEBUG_KMS("pipe/plane %c/%d with fb: size=%dx%d@%d, offset=%x, pitch %d, size 0x%x\n",
pipe_name(pipe), plane, fb->width, fb->height,
fb->bits_per_pixel, base, fb->pitches[0],
plane_config->size);
plane_config->fb = intel_fb;
}
static void chv_crtc_clock_get(struct intel_crtc *crtc,
struct intel_crtc_state *pipe_config)
{
struct drm_device *dev = crtc->base.dev;
struct drm_i915_private *dev_priv = to_i915(dev);
int pipe = pipe_config->cpu_transcoder;
enum dpio_channel port = vlv_pipe_to_channel(pipe);
struct dpll clock;
u32 cmn_dw13, pll_dw0, pll_dw1, pll_dw2, pll_dw3;
int refclk = 100000;
if ((pipe_config->dpll_hw_state.dpll & DPLL_VCO_ENABLE) == 0)
return;
mutex_lock(&dev_priv->sb_lock);
cmn_dw13 = vlv_dpio_read(dev_priv, pipe, CHV_CMN_DW13(port));
pll_dw0 = vlv_dpio_read(dev_priv, pipe, CHV_PLL_DW0(port));
pll_dw1 = vlv_dpio_read(dev_priv, pipe, CHV_PLL_DW1(port));
pll_dw2 = vlv_dpio_read(dev_priv, pipe, CHV_PLL_DW2(port));
pll_dw3 = vlv_dpio_read(dev_priv, pipe, CHV_PLL_DW3(port));
mutex_unlock(&dev_priv->sb_lock);
clock.m1 = (pll_dw1 & 0x7) == DPIO_CHV_M1_DIV_BY_2 ? 2 : 0;
clock.m2 = (pll_dw0 & 0xff) << 22;
if (pll_dw3 & DPIO_CHV_FRAC_DIV_EN)
clock.m2 |= pll_dw2 & 0x3fffff;
clock.n = (pll_dw1 >> DPIO_CHV_N_DIV_SHIFT) & 0xf;
clock.p1 = (cmn_dw13 >> DPIO_CHV_P1_DIV_SHIFT) & 0x7;
clock.p2 = (cmn_dw13 >> DPIO_CHV_P2_DIV_SHIFT) & 0x1f;
pipe_config->port_clock = chv_calc_dpll_params(refclk, &clock);
}
static bool i9xx_get_pipe_config(struct intel_crtc *crtc,
struct intel_crtc_state *pipe_config)
{
struct drm_i915_private *dev_priv = to_i915(crtc->base.dev);
enum intel_display_power_domain power_domain;
uint32_t tmp;
bool ret;
power_domain = POWER_DOMAIN_PIPE(crtc->pipe);
if (!intel_display_power_get_if_enabled(dev_priv, power_domain))
return false;
pipe_config->cpu_transcoder = (enum transcoder) crtc->pipe;
pipe_config->shared_dpll = NULL;
ret = false;
tmp = I915_READ(PIPECONF(crtc->pipe));
if (!(tmp & PIPECONF_ENABLE))
goto out;
if (IS_G4X(dev_priv) || IS_VALLEYVIEW(dev_priv) ||
IS_CHERRYVIEW(dev_priv)) {
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
if ((IS_VALLEYVIEW(dev_priv) || IS_CHERRYVIEW(dev_priv)) &&
(tmp & PIPECONF_COLOR_RANGE_SELECT))
pipe_config->limited_color_range = true;
if (INTEL_GEN(dev_priv) < 4)
pipe_config->double_wide = tmp & PIPECONF_DOUBLE_WIDE;
intel_get_pipe_timings(crtc, pipe_config);
intel_get_pipe_src_size(crtc, pipe_config);
i9xx_get_pfit_config(crtc, pipe_config);
if (INTEL_GEN(dev_priv) >= 4) {
if (IS_CHERRYVIEW(dev_priv) && crtc->pipe != PIPE_A)
tmp = dev_priv->chv_dpll_md[crtc->pipe];
else
tmp = I915_READ(DPLL_MD(crtc->pipe));
pipe_config->pixel_multiplier =
((tmp & DPLL_MD_UDI_MULTIPLIER_MASK)
>> DPLL_MD_UDI_MULTIPLIER_SHIFT) + 1;
pipe_config->dpll_hw_state.dpll_md = tmp;
} else if (IS_I945G(dev_priv) || IS_I945GM(dev_priv) ||
IS_G33(dev_priv)) {
tmp = I915_READ(DPLL(crtc->pipe));
pipe_config->pixel_multiplier =
((tmp & SDVO_MULTIPLIER_MASK)
>> SDVO_MULTIPLIER_SHIFT_HIRES) + 1;
} else {
pipe_config->pixel_multiplier = 1;
}
pipe_config->dpll_hw_state.dpll = I915_READ(DPLL(crtc->pipe));
if (!IS_VALLEYVIEW(dev_priv) && !IS_CHERRYVIEW(dev_priv)) {
if (IS_I830(dev_priv))
pipe_config->dpll_hw_state.dpll &= ~DPLL_DVO_2X_MODE;
pipe_config->dpll_hw_state.fp0 = I915_READ(FP0(crtc->pipe));
pipe_config->dpll_hw_state.fp1 = I915_READ(FP1(crtc->pipe));
} else {
pipe_config->dpll_hw_state.dpll &= ~(DPLL_LOCK_VLV |
DPLL_PORTC_READY_MASK |
DPLL_PORTB_READY_MASK);
}
if (IS_CHERRYVIEW(dev_priv))
chv_crtc_clock_get(crtc, pipe_config);
else if (IS_VALLEYVIEW(dev_priv))
vlv_crtc_clock_get(crtc, pipe_config);
else
i9xx_crtc_clock_get(crtc, pipe_config);
pipe_config->base.adjusted_mode.crtc_clock =
pipe_config->port_clock / pipe_config->pixel_multiplier;
ret = true;
out:
intel_display_power_put(dev_priv, power_domain);
return ret;
}
static void ironlake_init_pch_refclk(struct drm_device *dev)
{
struct drm_i915_private *dev_priv = to_i915(dev);
struct intel_encoder *encoder;
int i;
u32 val, final;
bool has_lvds = false;
bool has_cpu_edp = false;
bool has_panel = false;
bool has_ck505 = false;
bool can_ssc = false;
bool using_ssc_source = false;
for_each_intel_encoder(dev, encoder) {
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
default:
break;
}
}
if (HAS_PCH_IBX(dev_priv)) {
has_ck505 = dev_priv->vbt.display_clock_mode;
can_ssc = has_ck505;
} else {
has_ck505 = false;
can_ssc = true;
}
for (i = 0; i < dev_priv->num_shared_dpll; i++) {
u32 temp = I915_READ(PCH_DPLL(i));
if (!(temp & DPLL_VCO_ENABLE))
continue;
if ((temp & PLL_REF_INPUT_MASK) ==
PLLB_REF_INPUT_SPREADSPECTRUMIN) {
using_ssc_source = true;
break;
}
}
DRM_DEBUG_KMS("has_panel %d has_lvds %d has_ck505 %d using_ssc_source %d\n",
has_panel, has_lvds, has_ck505, using_ssc_source);
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
} else if (using_ssc_source) {
final |= DREF_SSC_SOURCE_ENABLE;
final |= DREF_SSC1_ENABLE;
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
} else
val |= DREF_CPU_SOURCE_OUTPUT_NONSPREAD;
} else
val |= DREF_CPU_SOURCE_OUTPUT_DISABLE;
I915_WRITE(PCH_DREF_CONTROL, val);
POSTING_READ(PCH_DREF_CONTROL);
udelay(200);
} else {
DRM_DEBUG_KMS("Disabling CPU source output\n");
val &= ~DREF_CPU_SOURCE_OUTPUT_MASK;
val |= DREF_CPU_SOURCE_OUTPUT_DISABLE;
I915_WRITE(PCH_DREF_CONTROL, val);
POSTING_READ(PCH_DREF_CONTROL);
udelay(200);
if (!using_ssc_source) {
DRM_DEBUG_KMS("Disabling SSC source\n");
val &= ~DREF_SSC_SOURCE_MASK;
val |= DREF_SSC_SOURCE_DISABLE;
val &= ~DREF_SSC1_ENABLE;
I915_WRITE(PCH_DREF_CONTROL, val);
POSTING_READ(PCH_DREF_CONTROL);
udelay(200);
}
}
BUG_ON(val != final);
}
static void lpt_reset_fdi_mphy(struct drm_i915_private *dev_priv)
{
uint32_t tmp;
tmp = I915_READ(SOUTH_CHICKEN2);
tmp |= FDI_MPHY_IOSFSB_RESET_CTL;
I915_WRITE(SOUTH_CHICKEN2, tmp);
if (wait_for_us(I915_READ(SOUTH_CHICKEN2) &
FDI_MPHY_IOSFSB_RESET_STATUS, 100))
DRM_ERROR("FDI mPHY reset assert timeout\n");
tmp = I915_READ(SOUTH_CHICKEN2);
tmp &= ~FDI_MPHY_IOSFSB_RESET_CTL;
I915_WRITE(SOUTH_CHICKEN2, tmp);
if (wait_for_us((I915_READ(SOUTH_CHICKEN2) &
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
struct drm_i915_private *dev_priv = to_i915(dev);
uint32_t reg, tmp;
if (WARN(with_fdi && !with_spread, "FDI requires downspread\n"))
with_spread = true;
if (WARN(HAS_PCH_LPT_LP(dev_priv) &&
with_fdi, "LP PCH doesn't have FDI\n"))
with_fdi = false;
mutex_lock(&dev_priv->sb_lock);
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
reg = HAS_PCH_LPT_LP(dev_priv) ? SBI_GEN0 : SBI_DBUFF0;
tmp = intel_sbi_read(dev_priv, reg, SBI_ICLK);
tmp |= SBI_GEN0_CFG_BUFFENABLE_DISABLE;
intel_sbi_write(dev_priv, reg, tmp, SBI_ICLK);
mutex_unlock(&dev_priv->sb_lock);
}
static void lpt_disable_clkout_dp(struct drm_device *dev)
{
struct drm_i915_private *dev_priv = to_i915(dev);
uint32_t reg, tmp;
mutex_lock(&dev_priv->sb_lock);
reg = HAS_PCH_LPT_LP(dev_priv) ? SBI_GEN0 : SBI_DBUFF0;
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
mutex_unlock(&dev_priv->sb_lock);
}
static void lpt_bend_clkout_dp(struct drm_i915_private *dev_priv, int steps)
{
uint32_t tmp;
int idx = BEND_IDX(steps);
if (WARN_ON(steps % 5 != 0))
return;
if (WARN_ON(idx >= ARRAY_SIZE(sscdivintphase)))
return;
mutex_lock(&dev_priv->sb_lock);
if (steps % 10 != 0)
tmp = 0xAAAAAAAB;
else
tmp = 0x00000000;
intel_sbi_write(dev_priv, SBI_SSCDITHPHASE, tmp, SBI_ICLK);
tmp = intel_sbi_read(dev_priv, SBI_SSCDIVINTPHASE, SBI_ICLK);
tmp &= 0xffff0000;
tmp |= sscdivintphase[idx];
intel_sbi_write(dev_priv, SBI_SSCDIVINTPHASE, tmp, SBI_ICLK);
mutex_unlock(&dev_priv->sb_lock);
}
static void lpt_init_pch_refclk(struct drm_device *dev)
{
struct intel_encoder *encoder;
bool has_vga = false;
for_each_intel_encoder(dev, encoder) {
switch (encoder->type) {
case INTEL_OUTPUT_ANALOG:
has_vga = true;
break;
default:
break;
}
}
if (has_vga) {
lpt_bend_clkout_dp(to_i915(dev), 0);
lpt_enable_clkout_dp(dev, true, true);
} else {
lpt_disable_clkout_dp(dev);
}
}
void intel_init_pch_refclk(struct drm_device *dev)
{
struct drm_i915_private *dev_priv = to_i915(dev);
if (HAS_PCH_IBX(dev_priv) || HAS_PCH_CPT(dev_priv))
ironlake_init_pch_refclk(dev);
else if (HAS_PCH_LPT(dev_priv))
lpt_init_pch_refclk(dev);
}
static void ironlake_set_pipeconf(struct drm_crtc *crtc)
{
struct drm_i915_private *dev_priv = to_i915(crtc->dev);
struct intel_crtc *intel_crtc = to_intel_crtc(crtc);
int pipe = intel_crtc->pipe;
uint32_t val;
val = 0;
switch (intel_crtc->config->pipe_bpp) {
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
if (intel_crtc->config->dither)
val |= (PIPECONF_DITHER_EN | PIPECONF_DITHER_TYPE_SP);
if (intel_crtc->config->base.adjusted_mode.flags & DRM_MODE_FLAG_INTERLACE)
val |= PIPECONF_INTERLACED_ILK;
else
val |= PIPECONF_PROGRESSIVE;
if (intel_crtc->config->limited_color_range)
val |= PIPECONF_COLOR_RANGE_SELECT;
I915_WRITE(PIPECONF(pipe), val);
POSTING_READ(PIPECONF(pipe));
}
static void haswell_set_pipeconf(struct drm_crtc *crtc)
{
struct drm_i915_private *dev_priv = to_i915(crtc->dev);
struct intel_crtc *intel_crtc = to_intel_crtc(crtc);
enum transcoder cpu_transcoder = intel_crtc->config->cpu_transcoder;
u32 val = 0;
if (IS_HASWELL(dev_priv) && intel_crtc->config->dither)
val |= (PIPECONF_DITHER_EN | PIPECONF_DITHER_TYPE_SP);
if (intel_crtc->config->base.adjusted_mode.flags & DRM_MODE_FLAG_INTERLACE)
val |= PIPECONF_INTERLACED_ILK;
else
val |= PIPECONF_PROGRESSIVE;
I915_WRITE(PIPECONF(cpu_transcoder), val);
POSTING_READ(PIPECONF(cpu_transcoder));
}
static void haswell_set_pipemisc(struct drm_crtc *crtc)
{
struct drm_i915_private *dev_priv = to_i915(crtc->dev);
struct intel_crtc *intel_crtc = to_intel_crtc(crtc);
if (IS_BROADWELL(dev_priv) || INTEL_INFO(dev_priv)->gen >= 9) {
u32 val = 0;
switch (intel_crtc->config->pipe_bpp) {
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
if (intel_crtc->config->dither)
val |= PIPEMISC_DITHER_ENABLE | PIPEMISC_DITHER_TYPE_SP;
I915_WRITE(PIPEMISC(intel_crtc->pipe), val);
}
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
static void ironlake_compute_dpll(struct intel_crtc *intel_crtc,
struct intel_crtc_state *crtc_state,
struct dpll *reduced_clock)
{
struct drm_crtc *crtc = &intel_crtc->base;
struct drm_device *dev = crtc->dev;
struct drm_i915_private *dev_priv = to_i915(dev);
u32 dpll, fp, fp2;
int factor;
factor = 21;
if (intel_crtc_has_type(crtc_state, INTEL_OUTPUT_LVDS)) {
if ((intel_panel_use_ssc(dev_priv) &&
dev_priv->vbt.lvds_ssc_freq == 100000) ||
(HAS_PCH_IBX(dev_priv) && intel_is_dual_link_lvds(dev)))
factor = 25;
} else if (crtc_state->sdvo_tv_clock)
factor = 20;
fp = i9xx_dpll_compute_fp(&crtc_state->dpll);
if (ironlake_needs_fb_cb_tune(&crtc_state->dpll, factor))
fp |= FP_CB_TUNE;
if (reduced_clock) {
fp2 = i9xx_dpll_compute_fp(reduced_clock);
if (reduced_clock->m < factor * reduced_clock->n)
fp2 |= FP_CB_TUNE;
} else {
fp2 = fp;
}
dpll = 0;
if (intel_crtc_has_type(crtc_state, INTEL_OUTPUT_LVDS))
dpll |= DPLLB_MODE_LVDS;
else
dpll |= DPLLB_MODE_DAC_SERIAL;
dpll |= (crtc_state->pixel_multiplier - 1)
<< PLL_REF_SDVO_HDMI_MULTIPLIER_SHIFT;
if (intel_crtc_has_type(crtc_state, INTEL_OUTPUT_SDVO) ||
intel_crtc_has_type(crtc_state, INTEL_OUTPUT_HDMI))
dpll |= DPLL_SDVO_HIGH_SPEED;
if (intel_crtc_has_dp_encoder(crtc_state))
dpll |= DPLL_SDVO_HIGH_SPEED;
if (INTEL_INFO(dev_priv)->num_pipes == 3 &&
intel_crtc_has_type(crtc_state, INTEL_OUTPUT_ANALOG))
dpll |= DPLL_SDVO_HIGH_SPEED;
dpll |= (1 << (crtc_state->dpll.p1 - 1)) << DPLL_FPA01_P1_POST_DIV_SHIFT;
dpll |= (1 << (crtc_state->dpll.p1 - 1)) << DPLL_FPA1_P1_POST_DIV_SHIFT;
switch (crtc_state->dpll.p2) {
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
if (intel_crtc_has_type(crtc_state, INTEL_OUTPUT_LVDS) &&
intel_panel_use_ssc(dev_priv))
dpll |= PLLB_REF_INPUT_SPREADSPECTRUMIN;
else
dpll |= PLL_REF_INPUT_DREFCLK;
dpll |= DPLL_VCO_ENABLE;
crtc_state->dpll_hw_state.dpll = dpll;
crtc_state->dpll_hw_state.fp0 = fp;
crtc_state->dpll_hw_state.fp1 = fp2;
}
static int ironlake_crtc_compute_clock(struct intel_crtc *crtc,
struct intel_crtc_state *crtc_state)
{
struct drm_device *dev = crtc->base.dev;
struct drm_i915_private *dev_priv = to_i915(dev);
struct dpll reduced_clock;
bool has_reduced_clock = false;
struct intel_shared_dpll *pll;
const struct intel_limit *limit;
int refclk = 120000;
memset(&crtc_state->dpll_hw_state, 0,
sizeof(crtc_state->dpll_hw_state));
crtc->lowfreq_avail = false;
if (!crtc_state->has_pch_encoder)
return 0;
if (intel_crtc_has_type(crtc_state, INTEL_OUTPUT_LVDS)) {
if (intel_panel_use_ssc(dev_priv)) {
DRM_DEBUG_KMS("using SSC reference clock of %d kHz\n",
dev_priv->vbt.lvds_ssc_freq);
refclk = dev_priv->vbt.lvds_ssc_freq;
}
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
} else {
limit = &intel_limits_ironlake_dac;
}
if (!crtc_state->clock_set &&
!g4x_find_best_dpll(limit, crtc_state, crtc_state->port_clock,
refclk, NULL, &crtc_state->dpll)) {
DRM_ERROR("Couldn't find PLL settings for mode!\n");
return -EINVAL;
}
ironlake_compute_dpll(crtc, crtc_state,
has_reduced_clock ? &reduced_clock : NULL);
pll = intel_get_shared_dpll(crtc, crtc_state, NULL);
if (pll == NULL) {
DRM_DEBUG_DRIVER("failed to find PLL for pipe %c\n",
pipe_name(crtc->pipe));
return -EINVAL;
}
if (intel_crtc_has_type(crtc_state, INTEL_OUTPUT_LVDS) &&
has_reduced_clock)
crtc->lowfreq_avail = true;
return 0;
}
static void intel_pch_transcoder_get_m_n(struct intel_crtc *crtc,
struct intel_link_m_n *m_n)
{
struct drm_device *dev = crtc->base.dev;
struct drm_i915_private *dev_priv = to_i915(dev);
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
struct intel_link_m_n *m_n,
struct intel_link_m_n *m2_n2)
{
struct drm_i915_private *dev_priv = to_i915(crtc->base.dev);
enum pipe pipe = crtc->pipe;
if (INTEL_GEN(dev_priv) >= 5) {
m_n->link_m = I915_READ(PIPE_LINK_M1(transcoder));
m_n->link_n = I915_READ(PIPE_LINK_N1(transcoder));
m_n->gmch_m = I915_READ(PIPE_DATA_M1(transcoder))
& ~TU_SIZE_MASK;
m_n->gmch_n = I915_READ(PIPE_DATA_N1(transcoder));
m_n->tu = ((I915_READ(PIPE_DATA_M1(transcoder))
& TU_SIZE_MASK) >> TU_SIZE_SHIFT) + 1;
if (m2_n2 && INTEL_GEN(dev_priv) < 8 &&
crtc->config->has_drrs) {
m2_n2->link_m = I915_READ(PIPE_LINK_M2(transcoder));
m2_n2->link_n = I915_READ(PIPE_LINK_N2(transcoder));
m2_n2->gmch_m = I915_READ(PIPE_DATA_M2(transcoder))
& ~TU_SIZE_MASK;
m2_n2->gmch_n = I915_READ(PIPE_DATA_N2(transcoder));
m2_n2->tu = ((I915_READ(PIPE_DATA_M2(transcoder))
& TU_SIZE_MASK) >> TU_SIZE_SHIFT) + 1;
}
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
struct intel_crtc_state *pipe_config)
{
if (pipe_config->has_pch_encoder)
intel_pch_transcoder_get_m_n(crtc, &pipe_config->dp_m_n);
else
intel_cpu_transcoder_get_m_n(crtc, pipe_config->cpu_transcoder,
&pipe_config->dp_m_n,
&pipe_config->dp_m2_n2);
}
static void ironlake_get_fdi_m_n_config(struct intel_crtc *crtc,
struct intel_crtc_state *pipe_config)
{
intel_cpu_transcoder_get_m_n(crtc, pipe_config->cpu_transcoder,
&pipe_config->fdi_m_n, NULL);
}
static void skylake_get_pfit_config(struct intel_crtc *crtc,
struct intel_crtc_state *pipe_config)
{
struct drm_device *dev = crtc->base.dev;
struct drm_i915_private *dev_priv = to_i915(dev);
struct intel_crtc_scaler_state *scaler_state = &pipe_config->scaler_state;
uint32_t ps_ctrl = 0;
int id = -1;
int i;
for (i = 0; i < crtc->num_scalers; i++) {
ps_ctrl = I915_READ(SKL_PS_CTRL(crtc->pipe, i));
if (ps_ctrl & PS_SCALER_EN && !(ps_ctrl & PS_PLANE_SEL_MASK)) {
id = i;
pipe_config->pch_pfit.enabled = true;
pipe_config->pch_pfit.pos = I915_READ(SKL_PS_WIN_POS(crtc->pipe, i));
pipe_config->pch_pfit.size = I915_READ(SKL_PS_WIN_SZ(crtc->pipe, i));
break;
}
}
scaler_state->scaler_id = id;
if (id >= 0) {
scaler_state->scaler_users |= (1 << SKL_CRTC_INDEX);
} else {
scaler_state->scaler_users &= ~(1 << SKL_CRTC_INDEX);
}
}
static void
skylake_get_initial_plane_config(struct intel_crtc *crtc,
struct intel_initial_plane_config *plane_config)
{
struct drm_device *dev = crtc->base.dev;
struct drm_i915_private *dev_priv = to_i915(dev);
u32 val, base, offset, stride_mult, tiling;
int pipe = crtc->pipe;
int fourcc, pixel_format;
unsigned int aligned_height;
struct drm_framebuffer *fb;
struct intel_framebuffer *intel_fb;
intel_fb = kzalloc(sizeof(*intel_fb), GFP_KERNEL);
if (!intel_fb) {
DRM_DEBUG_KMS("failed to alloc fb\n");
return;
}
fb = &intel_fb->base;
val = I915_READ(PLANE_CTL(pipe, 0));
if (!(val & PLANE_CTL_ENABLE))
goto error;
pixel_format = val & PLANE_CTL_FORMAT_MASK;
fourcc = skl_format_to_fourcc(pixel_format,
val & PLANE_CTL_ORDER_RGBX,
val & PLANE_CTL_ALPHA_MASK);
fb->pixel_format = fourcc;
fb->bits_per_pixel = drm_format_plane_cpp(fourcc, 0) * 8;
tiling = val & PLANE_CTL_TILED_MASK;
switch (tiling) {
case PLANE_CTL_TILED_LINEAR:
fb->modifier = DRM_FORMAT_MOD_NONE;
break;
case PLANE_CTL_TILED_X:
plane_config->tiling = I915_TILING_X;
fb->modifier = I915_FORMAT_MOD_X_TILED;
break;
case PLANE_CTL_TILED_Y:
fb->modifier = I915_FORMAT_MOD_Y_TILED;
break;
case PLANE_CTL_TILED_YF:
fb->modifier = I915_FORMAT_MOD_Yf_TILED;
break;
default:
MISSING_CASE(tiling);
goto error;
}
base = I915_READ(PLANE_SURF(pipe, 0)) & 0xfffff000;
plane_config->base = base;
offset = I915_READ(PLANE_OFFSET(pipe, 0));
val = I915_READ(PLANE_SIZE(pipe, 0));
fb->height = ((val >> 16) & 0xfff) + 1;
fb->width = ((val >> 0) & 0x1fff) + 1;
val = I915_READ(PLANE_STRIDE(pipe, 0));
stride_mult = intel_fb_stride_alignment(dev_priv, fb->modifier,
fb->pixel_format);
fb->pitches[0] = (val & 0x3ff) * stride_mult;
aligned_height = intel_fb_align_height(dev, fb->height,
fb->pixel_format,
fb->modifier);
plane_config->size = fb->pitches[0] * aligned_height;
DRM_DEBUG_KMS("pipe %c with fb: size=%dx%d@%d, offset=%x, pitch %d, size 0x%x\n",
pipe_name(pipe), fb->width, fb->height,
fb->bits_per_pixel, base, fb->pitches[0],
plane_config->size);
plane_config->fb = intel_fb;
return;
error:
kfree(intel_fb);
}
static void ironlake_get_pfit_config(struct intel_crtc *crtc,
struct intel_crtc_state *pipe_config)
{
struct drm_device *dev = crtc->base.dev;
struct drm_i915_private *dev_priv = to_i915(dev);
uint32_t tmp;
tmp = I915_READ(PF_CTL(crtc->pipe));
if (tmp & PF_ENABLE) {
pipe_config->pch_pfit.enabled = true;
pipe_config->pch_pfit.pos = I915_READ(PF_WIN_POS(crtc->pipe));
pipe_config->pch_pfit.size = I915_READ(PF_WIN_SZ(crtc->pipe));
if (IS_GEN7(dev_priv)) {
WARN_ON((tmp & PF_PIPE_SEL_MASK_IVB) !=
PF_PIPE_SEL_IVB(crtc->pipe));
}
}
}
static void
ironlake_get_initial_plane_config(struct intel_crtc *crtc,
struct intel_initial_plane_config *plane_config)
{
struct drm_device *dev = crtc->base.dev;
struct drm_i915_private *dev_priv = to_i915(dev);
u32 val, base, offset;
int pipe = crtc->pipe;
int fourcc, pixel_format;
unsigned int aligned_height;
struct drm_framebuffer *fb;
struct intel_framebuffer *intel_fb;
val = I915_READ(DSPCNTR(pipe));
if (!(val & DISPLAY_PLANE_ENABLE))
return;
intel_fb = kzalloc(sizeof(*intel_fb), GFP_KERNEL);
if (!intel_fb) {
DRM_DEBUG_KMS("failed to alloc fb\n");
return;
}
fb = &intel_fb->base;
if (INTEL_GEN(dev_priv) >= 4) {
if (val & DISPPLANE_TILED) {
plane_config->tiling = I915_TILING_X;
fb->modifier = I915_FORMAT_MOD_X_TILED;
}
}
pixel_format = val & DISPPLANE_PIXFORMAT_MASK;
fourcc = i9xx_format_to_fourcc(pixel_format);
fb->pixel_format = fourcc;
fb->bits_per_pixel = drm_format_plane_cpp(fourcc, 0) * 8;
base = I915_READ(DSPSURF(pipe)) & 0xfffff000;
if (IS_HASWELL(dev_priv) || IS_BROADWELL(dev_priv)) {
offset = I915_READ(DSPOFFSET(pipe));
} else {
if (plane_config->tiling)
offset = I915_READ(DSPTILEOFF(pipe));
else
offset = I915_READ(DSPLINOFF(pipe));
}
plane_config->base = base;
val = I915_READ(PIPESRC(pipe));
fb->width = ((val >> 16) & 0xfff) + 1;
fb->height = ((val >> 0) & 0xfff) + 1;
val = I915_READ(DSPSTRIDE(pipe));
fb->pitches[0] = val & 0xffffffc0;
aligned_height = intel_fb_align_height(dev, fb->height,
fb->pixel_format,
fb->modifier);
plane_config->size = fb->pitches[0] * aligned_height;
DRM_DEBUG_KMS("pipe %c with fb: size=%dx%d@%d, offset=%x, pitch %d, size 0x%x\n",
pipe_name(pipe), fb->width, fb->height,
fb->bits_per_pixel, base, fb->pitches[0],
plane_config->size);
plane_config->fb = intel_fb;
}
static bool ironlake_get_pipe_config(struct intel_crtc *crtc,
struct intel_crtc_state *pipe_config)
{
struct drm_device *dev = crtc->base.dev;
struct drm_i915_private *dev_priv = to_i915(dev);
enum intel_display_power_domain power_domain;
uint32_t tmp;
bool ret;
power_domain = POWER_DOMAIN_PIPE(crtc->pipe);
if (!intel_display_power_get_if_enabled(dev_priv, power_domain))
return false;
pipe_config->cpu_transcoder = (enum transcoder) crtc->pipe;
pipe_config->shared_dpll = NULL;
ret = false;
tmp = I915_READ(PIPECONF(crtc->pipe));
if (!(tmp & PIPECONF_ENABLE))
goto out;
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
if (tmp & PIPECONF_COLOR_RANGE_SELECT)
pipe_config->limited_color_range = true;
if (I915_READ(PCH_TRANSCONF(crtc->pipe)) & TRANS_ENABLE) {
struct intel_shared_dpll *pll;
enum intel_dpll_id pll_id;
pipe_config->has_pch_encoder = true;
tmp = I915_READ(FDI_RX_CTL(crtc->pipe));
pipe_config->fdi_lanes = ((FDI_DP_PORT_WIDTH_MASK & tmp) >>
FDI_DP_PORT_WIDTH_SHIFT) + 1;
ironlake_get_fdi_m_n_config(crtc, pipe_config);
if (HAS_PCH_IBX(dev_priv)) {
pll_id = (enum intel_dpll_id) crtc->pipe;
} else {
tmp = I915_READ(PCH_DPLL_SEL);
if (tmp & TRANS_DPLLB_SEL(crtc->pipe))
pll_id = DPLL_ID_PCH_PLL_B;
else
pll_id= DPLL_ID_PCH_PLL_A;
}
pipe_config->shared_dpll =
intel_get_shared_dpll_by_id(dev_priv, pll_id);
pll = pipe_config->shared_dpll;
WARN_ON(!pll->funcs.get_hw_state(dev_priv, pll,
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
intel_get_pipe_src_size(crtc, pipe_config);
ironlake_get_pfit_config(crtc, pipe_config);
ret = true;
out:
intel_display_power_put(dev_priv, power_domain);
return ret;
}
static void assert_can_disable_lcpll(struct drm_i915_private *dev_priv)
{
struct drm_device *dev = &dev_priv->drm;
struct intel_crtc *crtc;
for_each_intel_crtc(dev, crtc)
I915_STATE_WARN(crtc->active, "CRTC for pipe %c enabled\n",
pipe_name(crtc->pipe));
I915_STATE_WARN(I915_READ(HSW_PWR_WELL_DRIVER), "Power well on\n");
I915_STATE_WARN(I915_READ(SPLL_CTL) & SPLL_PLL_ENABLE, "SPLL enabled\n");
I915_STATE_WARN(I915_READ(WRPLL_CTL(0)) & WRPLL_PLL_ENABLE, "WRPLL1 enabled\n");
I915_STATE_WARN(I915_READ(WRPLL_CTL(1)) & WRPLL_PLL_ENABLE, "WRPLL2 enabled\n");
I915_STATE_WARN(I915_READ(PP_STATUS(0)) & PP_ON, "Panel power on\n");
I915_STATE_WARN(I915_READ(BLC_PWM_CPU_CTL2) & BLM_PWM_ENABLE,
"CPU PWM1 enabled\n");
if (IS_HASWELL(dev_priv))
I915_STATE_WARN(I915_READ(HSW_BLC_PWM2_CTL) & BLM_PWM_ENABLE,
"CPU PWM2 enabled\n");
I915_STATE_WARN(I915_READ(BLC_PWM_PCH_CTL1) & BLM_PCH_PWM_ENABLE,
"PCH PWM1 enabled\n");
I915_STATE_WARN(I915_READ(UTIL_PIN_CTL) & UTIL_PIN_ENABLE,
"Utility pin enabled\n");
I915_STATE_WARN(I915_READ(PCH_GTC_CTL) & PCH_GTC_ENABLE, "PCH GTC enabled\n");
I915_STATE_WARN(intel_irqs_enabled(dev_priv), "IRQs enabled\n");
}
static uint32_t hsw_read_dcomp(struct drm_i915_private *dev_priv)
{
if (IS_HASWELL(dev_priv))
return I915_READ(D_COMP_HSW);
else
return I915_READ(D_COMP_BDW);
}
static void hsw_write_dcomp(struct drm_i915_private *dev_priv, uint32_t val)
{
if (IS_HASWELL(dev_priv)) {
mutex_lock(&dev_priv->rps.hw_lock);
if (sandybridge_pcode_write(dev_priv, GEN6_PCODE_WRITE_D_COMP,
val))
DRM_DEBUG_KMS("Failed to write to D_COMP\n");
mutex_unlock(&dev_priv->rps.hw_lock);
} else {
I915_WRITE(D_COMP_BDW, val);
POSTING_READ(D_COMP_BDW);
}
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
if (wait_for_us(I915_READ(LCPLL_CTL) &
LCPLL_CD_SOURCE_FCLK_DONE, 1))
DRM_ERROR("Switching to FCLK failed\n");
val = I915_READ(LCPLL_CTL);
}
val |= LCPLL_PLL_DISABLE;
I915_WRITE(LCPLL_CTL, val);
POSTING_READ(LCPLL_CTL);
if (intel_wait_for_register(dev_priv, LCPLL_CTL, LCPLL_PLL_LOCK, 0, 1))
DRM_ERROR("LCPLL still locked\n");
val = hsw_read_dcomp(dev_priv);
val |= D_COMP_COMP_DISABLE;
hsw_write_dcomp(dev_priv, val);
ndelay(100);
if (wait_for((hsw_read_dcomp(dev_priv) & D_COMP_RCOMP_IN_PROGRESS) == 0,
1))
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
val = I915_READ(LCPLL_CTL);
if ((val & (LCPLL_PLL_LOCK | LCPLL_PLL_DISABLE | LCPLL_CD_SOURCE_FCLK |
LCPLL_POWER_DOWN_ALLOW)) == LCPLL_PLL_LOCK)
return;
intel_uncore_forcewake_get(dev_priv, FORCEWAKE_ALL);
if (val & LCPLL_POWER_DOWN_ALLOW) {
val &= ~LCPLL_POWER_DOWN_ALLOW;
I915_WRITE(LCPLL_CTL, val);
POSTING_READ(LCPLL_CTL);
}
val = hsw_read_dcomp(dev_priv);
val |= D_COMP_COMP_FORCE;
val &= ~D_COMP_COMP_DISABLE;
hsw_write_dcomp(dev_priv, val);
val = I915_READ(LCPLL_CTL);
val &= ~LCPLL_PLL_DISABLE;
I915_WRITE(LCPLL_CTL, val);
if (intel_wait_for_register(dev_priv,
LCPLL_CTL, LCPLL_PLL_LOCK, LCPLL_PLL_LOCK,
5))
DRM_ERROR("LCPLL not locked yet\n");
if (val & LCPLL_CD_SOURCE_FCLK) {
val = I915_READ(LCPLL_CTL);
val &= ~LCPLL_CD_SOURCE_FCLK;
I915_WRITE(LCPLL_CTL, val);
if (wait_for_us((I915_READ(LCPLL_CTL) &
LCPLL_CD_SOURCE_FCLK_DONE) == 0, 1))
DRM_ERROR("Switching back to LCPLL failed\n");
}
intel_uncore_forcewake_put(dev_priv, FORCEWAKE_ALL);
intel_update_cdclk(dev_priv);
}
void hsw_enable_pc8(struct drm_i915_private *dev_priv)
{
struct drm_device *dev = &dev_priv->drm;
uint32_t val;
DRM_DEBUG_KMS("Enabling package C8+\n");
if (HAS_PCH_LPT_LP(dev_priv)) {
val = I915_READ(SOUTH_DSPCLK_GATE_D);
val &= ~PCH_LP_PARTITION_LEVEL_DISABLE;
I915_WRITE(SOUTH_DSPCLK_GATE_D, val);
}
lpt_disable_clkout_dp(dev);
hsw_disable_lcpll(dev_priv, true, true);
}
void hsw_disable_pc8(struct drm_i915_private *dev_priv)
{
struct drm_device *dev = &dev_priv->drm;
uint32_t val;
DRM_DEBUG_KMS("Disabling package C8+\n");
hsw_restore_lcpll(dev_priv);
lpt_init_pch_refclk(dev);
if (HAS_PCH_LPT_LP(dev_priv)) {
val = I915_READ(SOUTH_DSPCLK_GATE_D);
val |= PCH_LP_PARTITION_LEVEL_DISABLE;
I915_WRITE(SOUTH_DSPCLK_GATE_D, val);
}
}
static void bxt_modeset_commit_cdclk(struct drm_atomic_state *old_state)
{
struct drm_device *dev = old_state->dev;
struct intel_atomic_state *old_intel_state =
to_intel_atomic_state(old_state);
unsigned int req_cdclk = old_intel_state->dev_cdclk;
bxt_set_cdclk(to_i915(dev), req_cdclk);
}
static int bdw_adjust_min_pipe_pixel_rate(struct intel_crtc_state *crtc_state,
int pixel_rate)
{
struct drm_i915_private *dev_priv = to_i915(crtc_state->base.crtc->dev);
if (IS_BROADWELL(dev_priv) && crtc_state->ips_enabled)
pixel_rate = DIV_ROUND_UP(pixel_rate * 100, 95);
if (intel_crtc_has_dp_encoder(crtc_state) &&
crtc_state->has_audio &&
crtc_state->port_clock >= 540000 &&
crtc_state->lane_count == 4)
pixel_rate = max(432000, pixel_rate);
return pixel_rate;
}
static int ilk_max_pixel_rate(struct drm_atomic_state *state)
{
struct intel_atomic_state *intel_state = to_intel_atomic_state(state);
struct drm_i915_private *dev_priv = to_i915(state->dev);
struct drm_crtc *crtc;
struct drm_crtc_state *cstate;
struct intel_crtc_state *crtc_state;
unsigned max_pixel_rate = 0, i;
enum pipe pipe;
memcpy(intel_state->min_pixclk, dev_priv->min_pixclk,
sizeof(intel_state->min_pixclk));
for_each_crtc_in_state(state, crtc, cstate, i) {
int pixel_rate;
crtc_state = to_intel_crtc_state(cstate);
if (!crtc_state->base.enable) {
intel_state->min_pixclk[i] = 0;
continue;
}
pixel_rate = ilk_pipe_pixel_rate(crtc_state);
if (IS_BROADWELL(dev_priv) || IS_GEN9(dev_priv))
pixel_rate = bdw_adjust_min_pipe_pixel_rate(crtc_state,
pixel_rate);
intel_state->min_pixclk[i] = pixel_rate;
}
for_each_pipe(dev_priv, pipe)
max_pixel_rate = max(intel_state->min_pixclk[pipe], max_pixel_rate);
return max_pixel_rate;
}
static void broadwell_set_cdclk(struct drm_device *dev, int cdclk)
{
struct drm_i915_private *dev_priv = to_i915(dev);
uint32_t val, data;
int ret;
if (WARN((I915_READ(LCPLL_CTL) &
(LCPLL_PLL_DISABLE | LCPLL_PLL_LOCK |
LCPLL_CD_CLOCK_DISABLE | LCPLL_ROOT_CD_CLOCK_DISABLE |
LCPLL_CD2X_CLOCK_DISABLE | LCPLL_POWER_DOWN_ALLOW |
LCPLL_CD_SOURCE_FCLK)) != LCPLL_PLL_LOCK,
"trying to change cdclk frequency with cdclk not enabled\n"))
return;
mutex_lock(&dev_priv->rps.hw_lock);
ret = sandybridge_pcode_write(dev_priv,
BDW_PCODE_DISPLAY_FREQ_CHANGE_REQ, 0x0);
mutex_unlock(&dev_priv->rps.hw_lock);
if (ret) {
DRM_ERROR("failed to inform pcode about cdclk change\n");
return;
}
val = I915_READ(LCPLL_CTL);
val |= LCPLL_CD_SOURCE_FCLK;
I915_WRITE(LCPLL_CTL, val);
if (wait_for_us(I915_READ(LCPLL_CTL) &
LCPLL_CD_SOURCE_FCLK_DONE, 1))
DRM_ERROR("Switching to FCLK failed\n");
val = I915_READ(LCPLL_CTL);
val &= ~LCPLL_CLK_FREQ_MASK;
switch (cdclk) {
case 450000:
val |= LCPLL_CLK_FREQ_450;
data = 0;
break;
case 540000:
val |= LCPLL_CLK_FREQ_54O_BDW;
data = 1;
break;
case 337500:
val |= LCPLL_CLK_FREQ_337_5_BDW;
data = 2;
break;
case 675000:
val |= LCPLL_CLK_FREQ_675_BDW;
data = 3;
break;
default:
WARN(1, "invalid cdclk frequency\n");
return;
}
I915_WRITE(LCPLL_CTL, val);
val = I915_READ(LCPLL_CTL);
val &= ~LCPLL_CD_SOURCE_FCLK;
I915_WRITE(LCPLL_CTL, val);
if (wait_for_us((I915_READ(LCPLL_CTL) &
LCPLL_CD_SOURCE_FCLK_DONE) == 0, 1))
DRM_ERROR("Switching back to LCPLL failed\n");
mutex_lock(&dev_priv->rps.hw_lock);
sandybridge_pcode_write(dev_priv, HSW_PCODE_DE_WRITE_FREQ_REQ, data);
mutex_unlock(&dev_priv->rps.hw_lock);
I915_WRITE(CDCLK_FREQ, DIV_ROUND_CLOSEST(cdclk, 1000) - 1);
intel_update_cdclk(dev_priv);
WARN(cdclk != dev_priv->cdclk_freq,
"cdclk requested %d kHz but got %d kHz\n",
cdclk, dev_priv->cdclk_freq);
}
static int broadwell_calc_cdclk(int max_pixclk)
{
if (max_pixclk > 540000)
return 675000;
else if (max_pixclk > 450000)
return 540000;
else if (max_pixclk > 337500)
return 450000;
else
return 337500;
}
static int broadwell_modeset_calc_cdclk(struct drm_atomic_state *state)
{
struct drm_i915_private *dev_priv = to_i915(state->dev);
struct intel_atomic_state *intel_state = to_intel_atomic_state(state);
int max_pixclk = ilk_max_pixel_rate(state);
int cdclk;
cdclk = broadwell_calc_cdclk(max_pixclk);
if (cdclk > dev_priv->max_cdclk_freq) {
DRM_DEBUG_KMS("requested cdclk (%d kHz) exceeds max (%d kHz)\n",
cdclk, dev_priv->max_cdclk_freq);
return -EINVAL;
}
intel_state->cdclk = intel_state->dev_cdclk = cdclk;
if (!intel_state->active_crtcs)
intel_state->dev_cdclk = broadwell_calc_cdclk(0);
return 0;
}
static void broadwell_modeset_commit_cdclk(struct drm_atomic_state *old_state)
{
struct drm_device *dev = old_state->dev;
struct intel_atomic_state *old_intel_state =
to_intel_atomic_state(old_state);
unsigned req_cdclk = old_intel_state->dev_cdclk;
broadwell_set_cdclk(dev, req_cdclk);
}
static int skl_modeset_calc_cdclk(struct drm_atomic_state *state)
{
struct intel_atomic_state *intel_state = to_intel_atomic_state(state);
struct drm_i915_private *dev_priv = to_i915(state->dev);
const int max_pixclk = ilk_max_pixel_rate(state);
int vco = intel_state->cdclk_pll_vco;
int cdclk;
cdclk = skl_calc_cdclk(max_pixclk, vco);
if (cdclk > dev_priv->max_cdclk_freq) {
DRM_ERROR("requested cdclk (%d kHz) exceeds max (%d kHz)\n",
cdclk, dev_priv->max_cdclk_freq);
cdclk = dev_priv->max_cdclk_freq;
}
intel_state->cdclk = intel_state->dev_cdclk = cdclk;
if (!intel_state->active_crtcs)
intel_state->dev_cdclk = skl_calc_cdclk(0, vco);
return 0;
}
static void skl_modeset_commit_cdclk(struct drm_atomic_state *old_state)
{
struct drm_i915_private *dev_priv = to_i915(old_state->dev);
struct intel_atomic_state *intel_state = to_intel_atomic_state(old_state);
unsigned int req_cdclk = intel_state->dev_cdclk;
unsigned int req_vco = intel_state->cdclk_pll_vco;
skl_set_cdclk(dev_priv, req_cdclk, req_vco);
}
static int haswell_crtc_compute_clock(struct intel_crtc *crtc,
struct intel_crtc_state *crtc_state)
{
if (!intel_crtc_has_type(crtc_state, INTEL_OUTPUT_DSI)) {
if (!intel_ddi_pll_select(crtc, crtc_state))
return -EINVAL;
}
crtc->lowfreq_avail = false;
return 0;
}
static void bxt_get_ddi_pll(struct drm_i915_private *dev_priv,
enum port port,
struct intel_crtc_state *pipe_config)
{
enum intel_dpll_id id;
switch (port) {
case PORT_A:
id = DPLL_ID_SKL_DPLL0;
break;
case PORT_B:
id = DPLL_ID_SKL_DPLL1;
break;
case PORT_C:
id = DPLL_ID_SKL_DPLL2;
break;
default:
DRM_ERROR("Incorrect port type\n");
return;
}
pipe_config->shared_dpll = intel_get_shared_dpll_by_id(dev_priv, id);
}
static void skylake_get_ddi_pll(struct drm_i915_private *dev_priv,
enum port port,
struct intel_crtc_state *pipe_config)
{
enum intel_dpll_id id;
u32 temp;
temp = I915_READ(DPLL_CTRL2) & DPLL_CTRL2_DDI_CLK_SEL_MASK(port);
id = temp >> (port * 3 + 1);
if (WARN_ON(id < SKL_DPLL0 || id > SKL_DPLL3))
return;
pipe_config->shared_dpll = intel_get_shared_dpll_by_id(dev_priv, id);
}
static void haswell_get_ddi_pll(struct drm_i915_private *dev_priv,
enum port port,
struct intel_crtc_state *pipe_config)
{
enum intel_dpll_id id;
uint32_t ddi_pll_sel = I915_READ(PORT_CLK_SEL(port));
switch (ddi_pll_sel) {
case PORT_CLK_SEL_WRPLL1:
id = DPLL_ID_WRPLL1;
break;
case PORT_CLK_SEL_WRPLL2:
id = DPLL_ID_WRPLL2;
break;
case PORT_CLK_SEL_SPLL:
id = DPLL_ID_SPLL;
break;
case PORT_CLK_SEL_LCPLL_810:
id = DPLL_ID_LCPLL_810;
break;
case PORT_CLK_SEL_LCPLL_1350:
id = DPLL_ID_LCPLL_1350;
break;
case PORT_CLK_SEL_LCPLL_2700:
id = DPLL_ID_LCPLL_2700;
break;
default:
MISSING_CASE(ddi_pll_sel);
case PORT_CLK_SEL_NONE:
return;
}
pipe_config->shared_dpll = intel_get_shared_dpll_by_id(dev_priv, id);
}
static bool hsw_get_transcoder_state(struct intel_crtc *crtc,
struct intel_crtc_state *pipe_config,
unsigned long *power_domain_mask)
{
struct drm_device *dev = crtc->base.dev;
struct drm_i915_private *dev_priv = to_i915(dev);
enum intel_display_power_domain power_domain;
u32 tmp;
pipe_config->cpu_transcoder = (enum transcoder) crtc->pipe;
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
power_domain = POWER_DOMAIN_TRANSCODER(pipe_config->cpu_transcoder);
if (!intel_display_power_get_if_enabled(dev_priv, power_domain))
return false;
*power_domain_mask |= BIT(power_domain);
tmp = I915_READ(PIPECONF(pipe_config->cpu_transcoder));
return tmp & PIPECONF_ENABLE;
}
static bool bxt_get_dsi_transcoder_state(struct intel_crtc *crtc,
struct intel_crtc_state *pipe_config,
unsigned long *power_domain_mask)
{
struct drm_device *dev = crtc->base.dev;
struct drm_i915_private *dev_priv = to_i915(dev);
enum intel_display_power_domain power_domain;
enum port port;
enum transcoder cpu_transcoder;
u32 tmp;
for_each_port_masked(port, BIT(PORT_A) | BIT(PORT_C)) {
if (port == PORT_A)
cpu_transcoder = TRANSCODER_DSI_A;
else
cpu_transcoder = TRANSCODER_DSI_C;
power_domain = POWER_DOMAIN_TRANSCODER(cpu_transcoder);
if (!intel_display_power_get_if_enabled(dev_priv, power_domain))
continue;
*power_domain_mask |= BIT(power_domain);
if (!intel_dsi_pll_is_enabled(dev_priv))
break;
tmp = I915_READ(BXT_MIPI_PORT_CTRL(port));
if (!(tmp & DPI_ENABLE))
continue;
tmp = I915_READ(MIPI_CTRL(port));
if ((tmp & BXT_PIPE_SELECT_MASK) != BXT_PIPE_SELECT(crtc->pipe))
continue;
pipe_config->cpu_transcoder = cpu_transcoder;
break;
}
return transcoder_is_dsi(pipe_config->cpu_transcoder);
}
static void haswell_get_ddi_port_state(struct intel_crtc *crtc,
struct intel_crtc_state *pipe_config)
{
struct drm_i915_private *dev_priv = to_i915(crtc->base.dev);
struct intel_shared_dpll *pll;
enum port port;
uint32_t tmp;
tmp = I915_READ(TRANS_DDI_FUNC_CTL(pipe_config->cpu_transcoder));
port = (tmp & TRANS_DDI_PORT_MASK) >> TRANS_DDI_PORT_SHIFT;
if (IS_SKYLAKE(dev_priv) || IS_KABYLAKE(dev_priv))
skylake_get_ddi_pll(dev_priv, port, pipe_config);
else if (IS_BROXTON(dev_priv))
bxt_get_ddi_pll(dev_priv, port, pipe_config);
else
haswell_get_ddi_pll(dev_priv, port, pipe_config);
pll = pipe_config->shared_dpll;
if (pll) {
WARN_ON(!pll->funcs.get_hw_state(dev_priv, pll,
&pipe_config->dpll_hw_state));
}
if (INTEL_GEN(dev_priv) < 9 &&
(port == PORT_E) && I915_READ(LPT_TRANSCONF) & TRANS_ENABLE) {
pipe_config->has_pch_encoder = true;
tmp = I915_READ(FDI_RX_CTL(PIPE_A));
pipe_config->fdi_lanes = ((FDI_DP_PORT_WIDTH_MASK & tmp) >>
FDI_DP_PORT_WIDTH_SHIFT) + 1;
ironlake_get_fdi_m_n_config(crtc, pipe_config);
}
}
static bool haswell_get_pipe_config(struct intel_crtc *crtc,
struct intel_crtc_state *pipe_config)
{
struct drm_i915_private *dev_priv = to_i915(crtc->base.dev);
enum intel_display_power_domain power_domain;
unsigned long power_domain_mask;
bool active;
power_domain = POWER_DOMAIN_PIPE(crtc->pipe);
if (!intel_display_power_get_if_enabled(dev_priv, power_domain))
return false;
power_domain_mask = BIT(power_domain);
pipe_config->shared_dpll = NULL;
active = hsw_get_transcoder_state(crtc, pipe_config, &power_domain_mask);
if (IS_BROXTON(dev_priv) &&
bxt_get_dsi_transcoder_state(crtc, pipe_config, &power_domain_mask)) {
WARN_ON(active);
active = true;
}
if (!active)
goto out;
if (!transcoder_is_dsi(pipe_config->cpu_transcoder)) {
haswell_get_ddi_port_state(crtc, pipe_config);
intel_get_pipe_timings(crtc, pipe_config);
}
intel_get_pipe_src_size(crtc, pipe_config);
pipe_config->gamma_mode =
I915_READ(GAMMA_MODE(crtc->pipe)) & GAMMA_MODE_MODE_MASK;
if (INTEL_GEN(dev_priv) >= 9) {
skl_init_scalers(dev_priv, crtc, pipe_config);
pipe_config->scaler_state.scaler_id = -1;
pipe_config->scaler_state.scaler_users &= ~(1 << SKL_CRTC_INDEX);
}
power_domain = POWER_DOMAIN_PIPE_PANEL_FITTER(crtc->pipe);
if (intel_display_power_get_if_enabled(dev_priv, power_domain)) {
power_domain_mask |= BIT(power_domain);
if (INTEL_GEN(dev_priv) >= 9)
skylake_get_pfit_config(crtc, pipe_config);
else
ironlake_get_pfit_config(crtc, pipe_config);
}
if (IS_HASWELL(dev_priv))
pipe_config->ips_enabled = hsw_crtc_supports_ips(crtc) &&
(I915_READ(IPS_CTL) & IPS_ENABLE);
if (pipe_config->cpu_transcoder != TRANSCODER_EDP &&
!transcoder_is_dsi(pipe_config->cpu_transcoder)) {
pipe_config->pixel_multiplier =
I915_READ(PIPE_MULT(pipe_config->cpu_transcoder)) + 1;
} else {
pipe_config->pixel_multiplier = 1;
}
out:
for_each_power_domain(power_domain, power_domain_mask)
intel_display_power_put(dev_priv, power_domain);
return active;
}
static void i845_update_cursor(struct drm_crtc *crtc, u32 base,
const struct intel_plane_state *plane_state)
{
struct drm_device *dev = crtc->dev;
struct drm_i915_private *dev_priv = to_i915(dev);
struct intel_crtc *intel_crtc = to_intel_crtc(crtc);
uint32_t cntl = 0, size = 0;
if (plane_state && plane_state->base.visible) {
unsigned int width = plane_state->base.crtc_w;
unsigned int height = plane_state->base.crtc_h;
unsigned int stride = roundup_pow_of_two(width) * 4;
switch (stride) {
default:
WARN_ONCE(1, "Invalid cursor width/stride, width=%u, stride=%u\n",
width, stride);
stride = 256;
case 256:
case 512:
case 1024:
case 2048:
break;
}
cntl |= CURSOR_ENABLE |
CURSOR_GAMMA_ENABLE |
CURSOR_FORMAT_ARGB |
CURSOR_STRIDE(stride);
size = (height << 12) | width;
}
if (intel_crtc->cursor_cntl != 0 &&
(intel_crtc->cursor_base != base ||
intel_crtc->cursor_size != size ||
intel_crtc->cursor_cntl != cntl)) {
I915_WRITE(CURCNTR(PIPE_A), 0);
POSTING_READ(CURCNTR(PIPE_A));
intel_crtc->cursor_cntl = 0;
}
if (intel_crtc->cursor_base != base) {
I915_WRITE(CURBASE(PIPE_A), base);
intel_crtc->cursor_base = base;
}
if (intel_crtc->cursor_size != size) {
I915_WRITE(CURSIZE, size);
intel_crtc->cursor_size = size;
}
if (intel_crtc->cursor_cntl != cntl) {
I915_WRITE(CURCNTR(PIPE_A), cntl);
POSTING_READ(CURCNTR(PIPE_A));
intel_crtc->cursor_cntl = cntl;
}
}
static void i9xx_update_cursor(struct drm_crtc *crtc, u32 base,
const struct intel_plane_state *plane_state)
{
struct drm_device *dev = crtc->dev;
struct drm_i915_private *dev_priv = to_i915(dev);
struct intel_crtc *intel_crtc = to_intel_crtc(crtc);
int pipe = intel_crtc->pipe;
uint32_t cntl = 0;
if (plane_state && plane_state->base.visible) {
cntl = MCURSOR_GAMMA_ENABLE;
switch (plane_state->base.crtc_w) {
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
MISSING_CASE(plane_state->base.crtc_w);
return;
}
cntl |= pipe << 28;
if (HAS_DDI(dev_priv))
cntl |= CURSOR_PIPE_CSC_ENABLE;
if (plane_state->base.rotation & DRM_ROTATE_180)
cntl |= CURSOR_ROTATE_180;
}
if (intel_crtc->cursor_cntl != cntl) {
I915_WRITE(CURCNTR(pipe), cntl);
POSTING_READ(CURCNTR(pipe));
intel_crtc->cursor_cntl = cntl;
}
I915_WRITE(CURBASE(pipe), base);
POSTING_READ(CURBASE(pipe));
intel_crtc->cursor_base = base;
}
static void intel_crtc_update_cursor(struct drm_crtc *crtc,
const struct intel_plane_state *plane_state)
{
struct drm_device *dev = crtc->dev;
struct drm_i915_private *dev_priv = to_i915(dev);
struct intel_crtc *intel_crtc = to_intel_crtc(crtc);
int pipe = intel_crtc->pipe;
u32 base = intel_crtc->cursor_addr;
u32 pos = 0;
if (plane_state) {
int x = plane_state->base.crtc_x;
int y = plane_state->base.crtc_y;
if (x < 0) {
pos |= CURSOR_POS_SIGN << CURSOR_X_SHIFT;
x = -x;
}
pos |= x << CURSOR_X_SHIFT;
if (y < 0) {
pos |= CURSOR_POS_SIGN << CURSOR_Y_SHIFT;
y = -y;
}
pos |= y << CURSOR_Y_SHIFT;
if (HAS_GMCH_DISPLAY(dev_priv) &&
plane_state->base.rotation & DRM_ROTATE_180) {
base += (plane_state->base.crtc_h *
plane_state->base.crtc_w - 1) * 4;
}
}
I915_WRITE(CURPOS(pipe), pos);
if (IS_845G(dev_priv) || IS_I865G(dev_priv))
i845_update_cursor(crtc, base, plane_state);
else
i9xx_update_cursor(crtc, base, plane_state);
}
static bool cursor_size_ok(struct drm_i915_private *dev_priv,
uint32_t width, uint32_t height)
{
if (width == 0 || height == 0)
return false;
if (IS_845G(dev_priv) || IS_I865G(dev_priv)) {
if ((width & 63) != 0)
return false;
if (width > (IS_845G(dev_priv) ? 64 : 512))
return false;
if (height > 1023)
return false;
} else {
switch (width | height) {
case 256:
case 128:
if (IS_GEN2(dev_priv))
return false;
case 64:
break;
default:
return false;
}
}
return true;
}
struct drm_framebuffer *
__intel_framebuffer_create(struct drm_device *dev,
struct drm_mode_fb_cmd2 *mode_cmd,
struct drm_i915_gem_object *obj)
{
struct intel_framebuffer *intel_fb;
int ret;
intel_fb = kzalloc(sizeof(*intel_fb), GFP_KERNEL);
if (!intel_fb)
return ERR_PTR(-ENOMEM);
ret = intel_framebuffer_init(dev, intel_fb, mode_cmd, obj);
if (ret)
goto err;
return &intel_fb->base;
err:
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
return PAGE_ALIGN(pitch * mode->vdisplay);
}
static struct drm_framebuffer *
intel_framebuffer_create_for_mode(struct drm_device *dev,
struct drm_display_mode *mode,
int depth, int bpp)
{
struct drm_framebuffer *fb;
struct drm_i915_gem_object *obj;
struct drm_mode_fb_cmd2 mode_cmd = { 0 };
obj = i915_gem_object_create(dev,
intel_framebuffer_size_for_mode(mode, bpp));
if (IS_ERR(obj))
return ERR_CAST(obj);
mode_cmd.width = mode->hdisplay;
mode_cmd.height = mode->vdisplay;
mode_cmd.pitches[0] = intel_framebuffer_pitch_for_width(mode_cmd.width,
bpp);
mode_cmd.pixel_format = drm_mode_legacy_fb_format(bpp, depth);
fb = intel_framebuffer_create(dev, &mode_cmd, obj);
if (IS_ERR(fb))
i915_gem_object_put(obj);
return fb;
}
static struct drm_framebuffer *
mode_fits_in_fbdev(struct drm_device *dev,
struct drm_display_mode *mode)
{
#ifdef CONFIG_DRM_FBDEV_EMULATION
struct drm_i915_private *dev_priv = to_i915(dev);
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
drm_framebuffer_reference(fb);
return fb;
#else
return NULL;
#endif
}
static int intel_modeset_setup_plane_state(struct drm_atomic_state *state,
struct drm_crtc *crtc,
struct drm_display_mode *mode,
struct drm_framebuffer *fb,
int x, int y)
{
struct drm_plane_state *plane_state;
int hdisplay, vdisplay;
int ret;
plane_state = drm_atomic_get_plane_state(state, crtc->primary);
if (IS_ERR(plane_state))
return PTR_ERR(plane_state);
if (mode)
drm_crtc_get_hv_timing(mode, &hdisplay, &vdisplay);
else
hdisplay = vdisplay = 0;
ret = drm_atomic_set_crtc_for_plane(plane_state, fb ? crtc : NULL);
if (ret)
return ret;
drm_atomic_set_fb_for_plane(plane_state, fb);
plane_state->crtc_x = 0;
plane_state->crtc_y = 0;
plane_state->crtc_w = hdisplay;
plane_state->crtc_h = vdisplay;
plane_state->src_x = x << 16;
plane_state->src_y = y << 16;
plane_state->src_w = hdisplay << 16;
plane_state->src_h = vdisplay << 16;
return 0;
}
bool intel_get_load_detect_pipe(struct drm_connector *connector,
struct drm_display_mode *mode,
struct intel_load_detect_pipe *old,
struct drm_modeset_acquire_ctx *ctx)
{
struct intel_crtc *intel_crtc;
struct intel_encoder *intel_encoder =
intel_attached_encoder(connector);
struct drm_crtc *possible_crtc;
struct drm_encoder *encoder = &intel_encoder->base;
struct drm_crtc *crtc = NULL;
struct drm_device *dev = encoder->dev;
struct drm_i915_private *dev_priv = to_i915(dev);
struct drm_framebuffer *fb;
struct drm_mode_config *config = &dev->mode_config;
struct drm_atomic_state *state = NULL, *restore_state = NULL;
struct drm_connector_state *connector_state;
struct intel_crtc_state *crtc_state;
int ret, i = -1;
DRM_DEBUG_KMS("[CONNECTOR:%d:%s], [ENCODER:%d:%s]\n",
connector->base.id, connector->name,
encoder->base.id, encoder->name);
old->restore_state = NULL;
retry:
ret = drm_modeset_lock(&config->connection_mutex, ctx);
if (ret)
goto fail;
if (connector->state->crtc) {
crtc = connector->state->crtc;
ret = drm_modeset_lock(&crtc->mutex, ctx);
if (ret)
goto fail;
goto found;
}
for_each_crtc(dev, possible_crtc) {
i++;
if (!(encoder->possible_crtcs & (1 << i)))
continue;
ret = drm_modeset_lock(&possible_crtc->mutex, ctx);
if (ret)
goto fail;
if (possible_crtc->state->enable) {
drm_modeset_unlock(&possible_crtc->mutex);
continue;
}
crtc = possible_crtc;
break;
}
if (!crtc) {
DRM_DEBUG_KMS("no pipe available for load-detect\n");
goto fail;
}
found:
intel_crtc = to_intel_crtc(crtc);
ret = drm_modeset_lock(&crtc->primary->mutex, ctx);
if (ret)
goto fail;
state = drm_atomic_state_alloc(dev);
restore_state = drm_atomic_state_alloc(dev);
if (!state || !restore_state) {
ret = -ENOMEM;
goto fail;
}
state->acquire_ctx = ctx;
restore_state->acquire_ctx = ctx;
connector_state = drm_atomic_get_connector_state(state, connector);
if (IS_ERR(connector_state)) {
ret = PTR_ERR(connector_state);
goto fail;
}
ret = drm_atomic_set_crtc_for_connector(connector_state, crtc);
if (ret)
goto fail;
crtc_state = intel_atomic_get_crtc_state(state, intel_crtc);
if (IS_ERR(crtc_state)) {
ret = PTR_ERR(crtc_state);
goto fail;
}
crtc_state->base.active = crtc_state->base.enable = true;
if (!mode)
mode = &load_detect_mode;
fb = mode_fits_in_fbdev(dev, mode);
if (fb == NULL) {
DRM_DEBUG_KMS("creating tmp fb for load-detection\n");
fb = intel_framebuffer_create_for_mode(dev, mode, 24, 32);
} else
DRM_DEBUG_KMS("reusing fbdev for load-detection framebuffer\n");
if (IS_ERR(fb)) {
DRM_DEBUG_KMS("failed to allocate framebuffer for load-detection\n");
goto fail;
}
ret = intel_modeset_setup_plane_state(state, crtc, mode, fb, 0, 0);
if (ret)
goto fail;
drm_framebuffer_unreference(fb);
ret = drm_atomic_set_mode_for_crtc(&crtc_state->base, mode);
if (ret)
goto fail;
ret = PTR_ERR_OR_ZERO(drm_atomic_get_connector_state(restore_state, connector));
if (!ret)
ret = PTR_ERR_OR_ZERO(drm_atomic_get_crtc_state(restore_state, crtc));
if (!ret)
ret = PTR_ERR_OR_ZERO(drm_atomic_get_plane_state(restore_state, crtc->primary));
if (ret) {
DRM_DEBUG_KMS("Failed to create a copy of old state to restore: %i\n", ret);
goto fail;
}
ret = drm_atomic_commit(state);
if (ret) {
DRM_DEBUG_KMS("failed to set mode on load-detect pipe\n");
goto fail;
}
old->restore_state = restore_state;
drm_atomic_state_put(state);
intel_wait_for_vblank(dev_priv, intel_crtc->pipe);
return true;
fail:
if (state) {
drm_atomic_state_put(state);
state = NULL;
}
if (restore_state) {
drm_atomic_state_put(restore_state);
restore_state = NULL;
}
if (ret == -EDEADLK) {
drm_modeset_backoff(ctx);
goto retry;
}
return false;
}
void intel_release_load_detect_pipe(struct drm_connector *connector,
struct intel_load_detect_pipe *old,
struct drm_modeset_acquire_ctx *ctx)
{
struct intel_encoder *intel_encoder =
intel_attached_encoder(connector);
struct drm_encoder *encoder = &intel_encoder->base;
struct drm_atomic_state *state = old->restore_state;
int ret;
DRM_DEBUG_KMS("[CONNECTOR:%d:%s], [ENCODER:%d:%s]\n",
connector->base.id, connector->name,
encoder->base.id, encoder->name);
if (!state)
return;
ret = drm_atomic_commit(state);
if (ret)
DRM_DEBUG_KMS("Couldn't release load detect pipe: %i\n", ret);
drm_atomic_state_put(state);
}
static int i9xx_pll_refclk(struct drm_device *dev,
const struct intel_crtc_state *pipe_config)
{
struct drm_i915_private *dev_priv = to_i915(dev);
u32 dpll = pipe_config->dpll_hw_state.dpll;
if ((dpll & PLL_REF_INPUT_MASK) == PLLB_REF_INPUT_SPREADSPECTRUMIN)
return dev_priv->vbt.lvds_ssc_freq;
else if (HAS_PCH_SPLIT(dev_priv))
return 120000;
else if (!IS_GEN2(dev_priv))
return 96000;
else
return 48000;
}
static void i9xx_crtc_clock_get(struct intel_crtc *crtc,
struct intel_crtc_state *pipe_config)
{
struct drm_device *dev = crtc->base.dev;
struct drm_i915_private *dev_priv = to_i915(dev);
int pipe = pipe_config->cpu_transcoder;
u32 dpll = pipe_config->dpll_hw_state.dpll;
u32 fp;
struct dpll clock;
int port_clock;
int refclk = i9xx_pll_refclk(dev, pipe_config);
if ((dpll & DISPLAY_RATE_SELECT_FPA1) == 0)
fp = pipe_config->dpll_hw_state.fp0;
else
fp = pipe_config->dpll_hw_state.fp1;
clock.m1 = (fp & FP_M1_DIV_MASK) >> FP_M1_DIV_SHIFT;
if (IS_PINEVIEW(dev_priv)) {
clock.n = ffs((fp & FP_N_PINEVIEW_DIV_MASK) >> FP_N_DIV_SHIFT) - 1;
clock.m2 = (fp & FP_M2_PINEVIEW_DIV_MASK) >> FP_M2_DIV_SHIFT;
} else {
clock.n = (fp & FP_N_DIV_MASK) >> FP_N_DIV_SHIFT;
clock.m2 = (fp & FP_M2_DIV_MASK) >> FP_M2_DIV_SHIFT;
}
if (!IS_GEN2(dev_priv)) {
if (IS_PINEVIEW(dev_priv))
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
if (IS_PINEVIEW(dev_priv))
port_clock = pnv_calc_dpll_params(refclk, &clock);
else
port_clock = i9xx_calc_dpll_params(refclk, &clock);
} else {
u32 lvds = IS_I830(dev_priv) ? 0 : I915_READ(LVDS);
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
port_clock = i9xx_calc_dpll_params(refclk, &clock);
}
pipe_config->port_clock = port_clock;
}
int intel_dotclock_calculate(int link_freq,
const struct intel_link_m_n *m_n)
{
if (!m_n->link_n)
return 0;
return div_u64((u64)m_n->link_m * link_freq, m_n->link_n);
}
static void ironlake_pch_clock_get(struct intel_crtc *crtc,
struct intel_crtc_state *pipe_config)
{
struct drm_i915_private *dev_priv = to_i915(crtc->base.dev);
i9xx_crtc_clock_get(crtc, pipe_config);
pipe_config->base.adjusted_mode.crtc_clock =
intel_dotclock_calculate(intel_fdi_link_freq(dev_priv, pipe_config),
&pipe_config->fdi_m_n);
}
struct drm_display_mode *intel_crtc_mode_get(struct drm_device *dev,
struct drm_crtc *crtc)
{
struct drm_i915_private *dev_priv = to_i915(dev);
struct intel_crtc *intel_crtc = to_intel_crtc(crtc);
enum transcoder cpu_transcoder = intel_crtc->config->cpu_transcoder;
struct drm_display_mode *mode;
struct intel_crtc_state *pipe_config;
int htot = I915_READ(HTOTAL(cpu_transcoder));
int hsync = I915_READ(HSYNC(cpu_transcoder));
int vtot = I915_READ(VTOTAL(cpu_transcoder));
int vsync = I915_READ(VSYNC(cpu_transcoder));
enum pipe pipe = intel_crtc->pipe;
mode = kzalloc(sizeof(*mode), GFP_KERNEL);
if (!mode)
return NULL;
pipe_config = kzalloc(sizeof(*pipe_config), GFP_KERNEL);
if (!pipe_config) {
kfree(mode);
return NULL;
}
pipe_config->cpu_transcoder = (enum transcoder) pipe;
pipe_config->pixel_multiplier = 1;
pipe_config->dpll_hw_state.dpll = I915_READ(DPLL(pipe));
pipe_config->dpll_hw_state.fp0 = I915_READ(FP0(pipe));
pipe_config->dpll_hw_state.fp1 = I915_READ(FP1(pipe));
i9xx_crtc_clock_get(intel_crtc, pipe_config);
mode->clock = pipe_config->port_clock / pipe_config->pixel_multiplier;
mode->hdisplay = (htot & 0xffff) + 1;
mode->htotal = ((htot & 0xffff0000) >> 16) + 1;
mode->hsync_start = (hsync & 0xffff) + 1;
mode->hsync_end = ((hsync & 0xffff0000) >> 16) + 1;
mode->vdisplay = (vtot & 0xffff) + 1;
mode->vtotal = ((vtot & 0xffff0000) >> 16) + 1;
mode->vsync_start = (vsync & 0xffff) + 1;
mode->vsync_end = ((vsync & 0xffff0000) >> 16) + 1;
drm_mode_set_name(mode);
kfree(pipe_config);
return mode;
}
static void intel_crtc_destroy(struct drm_crtc *crtc)
{
struct intel_crtc *intel_crtc = to_intel_crtc(crtc);
struct drm_device *dev = crtc->dev;
struct intel_flip_work *work;
spin_lock_irq(&dev->event_lock);
work = intel_crtc->flip_work;
intel_crtc->flip_work = NULL;
spin_unlock_irq(&dev->event_lock);
if (work) {
cancel_work_sync(&work->mmio_work);
cancel_work_sync(&work->unpin_work);
kfree(work);
}
drm_crtc_cleanup(crtc);
kfree(intel_crtc);
}
static void intel_unpin_work_fn(struct work_struct *__work)
{
struct intel_flip_work *work =
container_of(__work, struct intel_flip_work, unpin_work);
struct intel_crtc *crtc = to_intel_crtc(work->crtc);
struct drm_device *dev = crtc->base.dev;
struct drm_plane *primary = crtc->base.primary;
if (is_mmio_work(work))
flush_work(&work->mmio_work);
mutex_lock(&dev->struct_mutex);
intel_unpin_fb_vma(work->old_vma);
i915_gem_object_put(work->pending_flip_obj);
mutex_unlock(&dev->struct_mutex);
i915_gem_request_put(work->flip_queued_req);
intel_frontbuffer_flip_complete(to_i915(dev),
to_intel_plane(primary)->frontbuffer_bit);
intel_fbc_post_update(crtc);
drm_framebuffer_unreference(work->old_fb);
BUG_ON(atomic_read(&crtc->unpin_work_count) == 0);
atomic_dec(&crtc->unpin_work_count);
kfree(work);
}
static bool g4x_flip_count_after_eq(u32 a, u32 b)
{
return !((a - b) & 0x80000000);
}
static bool __pageflip_finished_cs(struct intel_crtc *crtc,
struct intel_flip_work *work)
{
struct drm_device *dev = crtc->base.dev;
struct drm_i915_private *dev_priv = to_i915(dev);
if (abort_flip_on_reset(crtc))
return true;
if (INTEL_GEN(dev_priv) < 5 && !IS_G4X(dev_priv))
return true;
return (I915_READ(DSPSURFLIVE(crtc->plane)) & ~0xfff) ==
crtc->flip_work->gtt_offset &&
g4x_flip_count_after_eq(I915_READ(PIPE_FLIPCOUNT_G4X(crtc->pipe)),
crtc->flip_work->flip_count);
}
static bool
__pageflip_finished_mmio(struct intel_crtc *crtc,
struct intel_flip_work *work)
{
return intel_crtc_get_vblank_counter(crtc) != work->flip_queued_vblank;
}
static bool pageflip_finished(struct intel_crtc *crtc,
struct intel_flip_work *work)
{
if (!atomic_read(&work->pending))
return false;
smp_rmb();
if (is_mmio_work(work))
return __pageflip_finished_mmio(crtc, work);
else
return __pageflip_finished_cs(crtc, work);
}
void intel_finish_page_flip_cs(struct drm_i915_private *dev_priv, int pipe)
{
struct drm_device *dev = &dev_priv->drm;
struct intel_crtc *crtc = intel_get_crtc_for_pipe(dev_priv, pipe);
struct intel_flip_work *work;
unsigned long flags;
if (!crtc)
return;
spin_lock_irqsave(&dev->event_lock, flags);
work = crtc->flip_work;
if (work != NULL &&
!is_mmio_work(work) &&
pageflip_finished(crtc, work))
page_flip_completed(crtc);
spin_unlock_irqrestore(&dev->event_lock, flags);
}
void intel_finish_page_flip_mmio(struct drm_i915_private *dev_priv, int pipe)
{
struct drm_device *dev = &dev_priv->drm;
struct intel_crtc *crtc = intel_get_crtc_for_pipe(dev_priv, pipe);
struct intel_flip_work *work;
unsigned long flags;
if (!crtc)
return;
spin_lock_irqsave(&dev->event_lock, flags);
work = crtc->flip_work;
if (work != NULL &&
is_mmio_work(work) &&
pageflip_finished(crtc, work))
page_flip_completed(crtc);
spin_unlock_irqrestore(&dev->event_lock, flags);
}
static inline void intel_mark_page_flip_active(struct intel_crtc *crtc,
struct intel_flip_work *work)
{
work->flip_queued_vblank = intel_crtc_get_vblank_counter(crtc);
smp_mb__before_atomic();
atomic_set(&work->pending, 1);
}
static int intel_gen2_queue_flip(struct drm_device *dev,
struct drm_crtc *crtc,
struct drm_framebuffer *fb,
struct drm_i915_gem_object *obj,
struct drm_i915_gem_request *req,
uint32_t flags)
{
struct intel_ring *ring = req->ring;
struct intel_crtc *intel_crtc = to_intel_crtc(crtc);
u32 flip_mask;
int ret;
ret = intel_ring_begin(req, 6);
if (ret)
return ret;
if (intel_crtc->plane)
flip_mask = MI_WAIT_FOR_PLANE_B_FLIP;
else
flip_mask = MI_WAIT_FOR_PLANE_A_FLIP;
intel_ring_emit(ring, MI_WAIT_FOR_EVENT | flip_mask);
intel_ring_emit(ring, MI_NOOP);
intel_ring_emit(ring, MI_DISPLAY_FLIP |
MI_DISPLAY_FLIP_PLANE(intel_crtc->plane));
intel_ring_emit(ring, fb->pitches[0]);
intel_ring_emit(ring, intel_crtc->flip_work->gtt_offset);
intel_ring_emit(ring, 0);
return 0;
}
static int intel_gen3_queue_flip(struct drm_device *dev,
struct drm_crtc *crtc,
struct drm_framebuffer *fb,
struct drm_i915_gem_object *obj,
struct drm_i915_gem_request *req,
uint32_t flags)
{
struct intel_ring *ring = req->ring;
struct intel_crtc *intel_crtc = to_intel_crtc(crtc);
u32 flip_mask;
int ret;
ret = intel_ring_begin(req, 6);
if (ret)
return ret;
if (intel_crtc->plane)
flip_mask = MI_WAIT_FOR_PLANE_B_FLIP;
else
flip_mask = MI_WAIT_FOR_PLANE_A_FLIP;
intel_ring_emit(ring, MI_WAIT_FOR_EVENT | flip_mask);
intel_ring_emit(ring, MI_NOOP);
intel_ring_emit(ring, MI_DISPLAY_FLIP_I915 |
MI_DISPLAY_FLIP_PLANE(intel_crtc->plane));
intel_ring_emit(ring, fb->pitches[0]);
intel_ring_emit(ring, intel_crtc->flip_work->gtt_offset);
intel_ring_emit(ring, MI_NOOP);
return 0;
}
static int intel_gen4_queue_flip(struct drm_device *dev,
struct drm_crtc *crtc,
struct drm_framebuffer *fb,
struct drm_i915_gem_object *obj,
struct drm_i915_gem_request *req,
uint32_t flags)
{
struct intel_ring *ring = req->ring;
struct drm_i915_private *dev_priv = to_i915(dev);
struct intel_crtc *intel_crtc = to_intel_crtc(crtc);
uint32_t pf, pipesrc;
int ret;
ret = intel_ring_begin(req, 4);
if (ret)
return ret;
intel_ring_emit(ring, MI_DISPLAY_FLIP |
MI_DISPLAY_FLIP_PLANE(intel_crtc->plane));
intel_ring_emit(ring, fb->pitches[0]);
intel_ring_emit(ring, intel_crtc->flip_work->gtt_offset |
intel_fb_modifier_to_tiling(fb->modifier));
pf = 0;
pipesrc = I915_READ(PIPESRC(intel_crtc->pipe)) & 0x0fff0fff;
intel_ring_emit(ring, pf | pipesrc);
return 0;
}
static int intel_gen6_queue_flip(struct drm_device *dev,
struct drm_crtc *crtc,
struct drm_framebuffer *fb,
struct drm_i915_gem_object *obj,
struct drm_i915_gem_request *req,
uint32_t flags)
{
struct intel_ring *ring = req->ring;
struct drm_i915_private *dev_priv = to_i915(dev);
struct intel_crtc *intel_crtc = to_intel_crtc(crtc);
uint32_t pf, pipesrc;
int ret;
ret = intel_ring_begin(req, 4);
if (ret)
return ret;
intel_ring_emit(ring, MI_DISPLAY_FLIP |
MI_DISPLAY_FLIP_PLANE(intel_crtc->plane));
intel_ring_emit(ring, fb->pitches[0] |
intel_fb_modifier_to_tiling(fb->modifier));
intel_ring_emit(ring, intel_crtc->flip_work->gtt_offset);
pf = 0;
pipesrc = I915_READ(PIPESRC(intel_crtc->pipe)) & 0x0fff0fff;
intel_ring_emit(ring, pf | pipesrc);
return 0;
}
static int intel_gen7_queue_flip(struct drm_device *dev,
struct drm_crtc *crtc,
struct drm_framebuffer *fb,
struct drm_i915_gem_object *obj,
struct drm_i915_gem_request *req,
uint32_t flags)
{
struct drm_i915_private *dev_priv = to_i915(dev);
struct intel_ring *ring = req->ring;
struct intel_crtc *intel_crtc = to_intel_crtc(crtc);
uint32_t plane_bit = 0;
int len, ret;
switch (intel_crtc->plane) {
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
return -ENODEV;
}
len = 4;
if (req->engine->id == RCS) {
len += 6;
if (IS_GEN8(dev_priv))
len += 2;
}
ret = intel_ring_cacheline_align(req);
if (ret)
return ret;
ret = intel_ring_begin(req, len);
if (ret)
return ret;
if (req->engine->id == RCS) {
intel_ring_emit(ring, MI_LOAD_REGISTER_IMM(1));
intel_ring_emit_reg(ring, DERRMR);
intel_ring_emit(ring, ~(DERRMR_PIPEA_PRI_FLIP_DONE |
DERRMR_PIPEB_PRI_FLIP_DONE |
DERRMR_PIPEC_PRI_FLIP_DONE));
if (IS_GEN8(dev_priv))
intel_ring_emit(ring, MI_STORE_REGISTER_MEM_GEN8 |
MI_SRM_LRM_GLOBAL_GTT);
else
intel_ring_emit(ring, MI_STORE_REGISTER_MEM |
MI_SRM_LRM_GLOBAL_GTT);
intel_ring_emit_reg(ring, DERRMR);
intel_ring_emit(ring,
i915_ggtt_offset(req->engine->scratch) + 256);
if (IS_GEN8(dev_priv)) {
intel_ring_emit(ring, 0);
intel_ring_emit(ring, MI_NOOP);
}
}
intel_ring_emit(ring, MI_DISPLAY_FLIP_I915 | plane_bit);
intel_ring_emit(ring, fb->pitches[0] |
intel_fb_modifier_to_tiling(fb->modifier));
intel_ring_emit(ring, intel_crtc->flip_work->gtt_offset);
intel_ring_emit(ring, (MI_NOOP));
return 0;
}
static bool use_mmio_flip(struct intel_engine_cs *engine,
struct drm_i915_gem_object *obj)
{
if (engine == NULL)
return true;
if (INTEL_GEN(engine->i915) < 5)
return false;
if (i915.use_mmio_flip < 0)
return false;
else if (i915.use_mmio_flip > 0)
return true;
else if (i915.enable_execlists)
return true;
return engine != i915_gem_object_last_write_engine(obj);
}
static void skl_do_mmio_flip(struct intel_crtc *intel_crtc,
unsigned int rotation,
struct intel_flip_work *work)
{
struct drm_device *dev = intel_crtc->base.dev;
struct drm_i915_private *dev_priv = to_i915(dev);
struct drm_framebuffer *fb = intel_crtc->base.primary->fb;
const enum pipe pipe = intel_crtc->pipe;
u32 ctl, stride = skl_plane_stride(fb, 0, rotation);
ctl = I915_READ(PLANE_CTL(pipe, 0));
ctl &= ~PLANE_CTL_TILED_MASK;
switch (fb->modifier) {
case DRM_FORMAT_MOD_NONE:
break;
case I915_FORMAT_MOD_X_TILED:
ctl |= PLANE_CTL_TILED_X;
break;
case I915_FORMAT_MOD_Y_TILED:
ctl |= PLANE_CTL_TILED_Y;
break;
case I915_FORMAT_MOD_Yf_TILED:
ctl |= PLANE_CTL_TILED_YF;
break;
default:
MISSING_CASE(fb->modifier);
}
I915_WRITE(PLANE_CTL(pipe, 0), ctl);
I915_WRITE(PLANE_STRIDE(pipe, 0), stride);
I915_WRITE(PLANE_SURF(pipe, 0), work->gtt_offset);
POSTING_READ(PLANE_SURF(pipe, 0));
}
static void ilk_do_mmio_flip(struct intel_crtc *intel_crtc,
struct intel_flip_work *work)
{
struct drm_device *dev = intel_crtc->base.dev;
struct drm_i915_private *dev_priv = to_i915(dev);
struct drm_framebuffer *fb = intel_crtc->base.primary->fb;
i915_reg_t reg = DSPCNTR(intel_crtc->plane);
u32 dspcntr;
dspcntr = I915_READ(reg);
if (fb->modifier == I915_FORMAT_MOD_X_TILED)
dspcntr |= DISPPLANE_TILED;
else
dspcntr &= ~DISPPLANE_TILED;
I915_WRITE(reg, dspcntr);
I915_WRITE(DSPSURF(intel_crtc->plane), work->gtt_offset);
POSTING_READ(DSPSURF(intel_crtc->plane));
}
static void intel_mmio_flip_work_func(struct work_struct *w)
{
struct intel_flip_work *work =
container_of(w, struct intel_flip_work, mmio_work);
struct intel_crtc *crtc = to_intel_crtc(work->crtc);
struct drm_i915_private *dev_priv = to_i915(crtc->base.dev);
struct intel_framebuffer *intel_fb =
to_intel_framebuffer(crtc->base.primary->fb);
struct drm_i915_gem_object *obj = intel_fb->obj;
WARN_ON(i915_gem_object_wait(obj, 0, MAX_SCHEDULE_TIMEOUT, NULL) < 0);
intel_pipe_update_start(crtc);
if (INTEL_GEN(dev_priv) >= 9)
skl_do_mmio_flip(crtc, work->rotation, work);
else
ilk_do_mmio_flip(crtc, work);
intel_pipe_update_end(crtc, work);
}
static int intel_default_queue_flip(struct drm_device *dev,
struct drm_crtc *crtc,
struct drm_framebuffer *fb,
struct drm_i915_gem_object *obj,
struct drm_i915_gem_request *req,
uint32_t flags)
{
return -ENODEV;
}
static bool __pageflip_stall_check_cs(struct drm_i915_private *dev_priv,
struct intel_crtc *intel_crtc,
struct intel_flip_work *work)
{
u32 addr, vblank;
if (!atomic_read(&work->pending))
return false;
smp_rmb();
vblank = intel_crtc_get_vblank_counter(intel_crtc);
if (work->flip_ready_vblank == 0) {
if (work->flip_queued_req &&
!i915_gem_request_completed(work->flip_queued_req))
return false;
work->flip_ready_vblank = vblank;
}
if (vblank - work->flip_ready_vblank < 3)
return false;
if (INTEL_GEN(dev_priv) >= 4)
addr = I915_HI_DISPBASE(I915_READ(DSPSURF(intel_crtc->plane)));
else
addr = I915_READ(DSPADDR(intel_crtc->plane));
return addr == work->gtt_offset;
}
void intel_check_page_flip(struct drm_i915_private *dev_priv, int pipe)
{
struct drm_device *dev = &dev_priv->drm;
struct intel_crtc *crtc = intel_get_crtc_for_pipe(dev_priv, pipe);
struct intel_flip_work *work;
WARN_ON(!in_interrupt());
if (crtc == NULL)
return;
spin_lock(&dev->event_lock);
work = crtc->flip_work;
if (work != NULL && !is_mmio_work(work) &&
__pageflip_stall_check_cs(dev_priv, crtc, work)) {
WARN_ONCE(1,
"Kicking stuck page flip: queued at %d, now %d\n",
work->flip_queued_vblank, intel_crtc_get_vblank_counter(crtc));
page_flip_completed(crtc);
work = NULL;
}
if (work != NULL && !is_mmio_work(work) &&
intel_crtc_get_vblank_counter(crtc) - work->flip_queued_vblank > 1)
intel_queue_rps_boost_for_request(work->flip_queued_req);
spin_unlock(&dev->event_lock);
}
static int intel_crtc_page_flip(struct drm_crtc *crtc,
struct drm_framebuffer *fb,
struct drm_pending_vblank_event *event,
uint32_t page_flip_flags)
{
struct drm_device *dev = crtc->dev;
struct drm_i915_private *dev_priv = to_i915(dev);
struct drm_framebuffer *old_fb = crtc->primary->fb;
struct drm_i915_gem_object *obj = intel_fb_obj(fb);
struct intel_crtc *intel_crtc = to_intel_crtc(crtc);
struct drm_plane *primary = crtc->primary;
enum pipe pipe = intel_crtc->pipe;
struct intel_flip_work *work;
struct intel_engine_cs *engine;
bool mmio_flip;
struct drm_i915_gem_request *request;
struct i915_vma *vma;
int ret;
if (WARN_ON(intel_fb_obj(old_fb) == NULL))
return -EBUSY;
if (fb->pixel_format != crtc->primary->fb->pixel_format)
return -EINVAL;
if (INTEL_GEN(dev_priv) > 3 &&
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
work->old_fb = old_fb;
INIT_WORK(&work->unpin_work, intel_unpin_work_fn);
ret = drm_crtc_vblank_get(crtc);
if (ret)
goto free_work;
spin_lock_irq(&dev->event_lock);
if (intel_crtc->flip_work) {
if (pageflip_finished(intel_crtc, intel_crtc->flip_work)) {
DRM_DEBUG_DRIVER("flip queue: previous flip completed, continuing\n");
page_flip_completed(intel_crtc);
} else {
DRM_DEBUG_DRIVER("flip queue: crtc already busy\n");
spin_unlock_irq(&dev->event_lock);
drm_crtc_vblank_put(crtc);
kfree(work);
return -EBUSY;
}
}
intel_crtc->flip_work = work;
spin_unlock_irq(&dev->event_lock);
if (atomic_read(&intel_crtc->unpin_work_count) >= 2)
flush_workqueue(dev_priv->wq);
drm_framebuffer_reference(work->old_fb);
crtc->primary->fb = fb;
update_state_fb(crtc->primary);
work->pending_flip_obj = i915_gem_object_get(obj);
ret = i915_mutex_lock_interruptible(dev);
if (ret)
goto cleanup;
intel_crtc->reset_count = i915_reset_count(&dev_priv->gpu_error);
if (i915_reset_in_progress_or_wedged(&dev_priv->gpu_error)) {
ret = -EIO;
goto unlock;
}
atomic_inc(&intel_crtc->unpin_work_count);
if (INTEL_GEN(dev_priv) >= 5 || IS_G4X(dev_priv))
work->flip_count = I915_READ(PIPE_FLIPCOUNT_G4X(pipe)) + 1;
if (IS_VALLEYVIEW(dev_priv) || IS_CHERRYVIEW(dev_priv)) {
engine = dev_priv->engine[BCS];
if (fb->modifier != old_fb->modifier)
engine = NULL;
} else if (IS_IVYBRIDGE(dev_priv) || IS_HASWELL(dev_priv)) {
engine = dev_priv->engine[BCS];
} else if (INTEL_GEN(dev_priv) >= 7) {
engine = i915_gem_object_last_write_engine(obj);
if (engine == NULL || engine->id != RCS)
engine = dev_priv->engine[BCS];
} else {
engine = dev_priv->engine[RCS];
}
mmio_flip = use_mmio_flip(engine, obj);
vma = intel_pin_and_fence_fb_obj(fb, primary->state->rotation);
if (IS_ERR(vma)) {
ret = PTR_ERR(vma);
goto cleanup_pending;
}
work->old_vma = to_intel_plane_state(primary->state)->vma;
to_intel_plane_state(primary->state)->vma = vma;
work->gtt_offset = i915_ggtt_offset(vma) + intel_crtc->dspaddr_offset;
work->rotation = crtc->primary->state->rotation;
intel_fbc_pre_update(intel_crtc, intel_crtc->config,
to_intel_plane_state(primary->state));
if (mmio_flip) {
INIT_WORK(&work->mmio_work, intel_mmio_flip_work_func);
queue_work(system_unbound_wq, &work->mmio_work);
} else {
request = i915_gem_request_alloc(engine, engine->last_context);
if (IS_ERR(request)) {
ret = PTR_ERR(request);
goto cleanup_unpin;
}
ret = i915_gem_request_await_object(request, obj, false);
if (ret)
goto cleanup_request;
ret = dev_priv->display.queue_flip(dev, crtc, fb, obj, request,
page_flip_flags);
if (ret)
goto cleanup_request;
intel_mark_page_flip_active(intel_crtc, work);
work->flip_queued_req = i915_gem_request_get(request);
i915_add_request_no_flush(request);
}
i915_gem_object_wait_priority(obj, 0, I915_PRIORITY_DISPLAY);
i915_gem_track_fb(intel_fb_obj(old_fb), obj,
to_intel_plane(primary)->frontbuffer_bit);
mutex_unlock(&dev->struct_mutex);
intel_frontbuffer_flip_prepare(to_i915(dev),
to_intel_plane(primary)->frontbuffer_bit);
trace_i915_flip_request(intel_crtc->plane, obj);
return 0;
cleanup_request:
i915_add_request_no_flush(request);
cleanup_unpin:
to_intel_plane_state(primary->state)->vma = work->old_vma;
intel_unpin_fb_vma(vma);
cleanup_pending:
atomic_dec(&intel_crtc->unpin_work_count);
unlock:
mutex_unlock(&dev->struct_mutex);
cleanup:
crtc->primary->fb = old_fb;
update_state_fb(crtc->primary);
i915_gem_object_put(obj);
drm_framebuffer_unreference(work->old_fb);
spin_lock_irq(&dev->event_lock);
intel_crtc->flip_work = NULL;
spin_unlock_irq(&dev->event_lock);
drm_crtc_vblank_put(crtc);
free_work:
kfree(work);
if (ret == -EIO) {
struct drm_atomic_state *state;
struct drm_plane_state *plane_state;
out_hang:
state = drm_atomic_state_alloc(dev);
if (!state)
return -ENOMEM;
state->acquire_ctx = drm_modeset_legacy_acquire_ctx(crtc);
retry:
plane_state = drm_atomic_get_plane_state(state, primary);
ret = PTR_ERR_OR_ZERO(plane_state);
if (!ret) {
drm_atomic_set_fb_for_plane(plane_state, fb);
ret = drm_atomic_set_crtc_for_plane(plane_state, crtc);
if (!ret)
ret = drm_atomic_commit(state);
}
if (ret == -EDEADLK) {
drm_modeset_backoff(state->acquire_ctx);
drm_atomic_state_clear(state);
goto retry;
}
drm_atomic_state_put(state);
if (ret == 0 && event) {
spin_lock_irq(&dev->event_lock);
drm_crtc_send_vblank_event(crtc, event);
spin_unlock_irq(&dev->event_lock);
}
}
return ret;
}
static bool intel_wm_need_update(struct drm_plane *plane,
struct drm_plane_state *state)
{
struct intel_plane_state *new = to_intel_plane_state(state);
struct intel_plane_state *cur = to_intel_plane_state(plane->state);
if (new->base.visible != cur->base.visible)
return true;
if (!cur->base.fb || !new->base.fb)
return false;
if (cur->base.fb->modifier != new->base.fb->modifier ||
cur->base.rotation != new->base.rotation ||
drm_rect_width(&new->base.src) != drm_rect_width(&cur->base.src) ||
drm_rect_height(&new->base.src) != drm_rect_height(&cur->base.src) ||
drm_rect_width(&new->base.dst) != drm_rect_width(&cur->base.dst) ||
drm_rect_height(&new->base.dst) != drm_rect_height(&cur->base.dst))
return true;
return false;
}
static bool needs_scaling(struct intel_plane_state *state)
{
int src_w = drm_rect_width(&state->base.src) >> 16;
int src_h = drm_rect_height(&state->base.src) >> 16;
int dst_w = drm_rect_width(&state->base.dst);
int dst_h = drm_rect_height(&state->base.dst);
return (src_w != dst_w || src_h != dst_h);
}
int intel_plane_atomic_calc_changes(struct drm_crtc_state *crtc_state,
struct drm_plane_state *plane_state)
{
struct intel_crtc_state *pipe_config = to_intel_crtc_state(crtc_state);
struct drm_crtc *crtc = crtc_state->crtc;
struct intel_crtc *intel_crtc = to_intel_crtc(crtc);
struct drm_plane *plane = plane_state->plane;
struct drm_device *dev = crtc->dev;
struct drm_i915_private *dev_priv = to_i915(dev);
struct intel_plane_state *old_plane_state =
to_intel_plane_state(plane->state);
bool mode_changed = needs_modeset(crtc_state);
bool was_crtc_enabled = crtc->state->active;
bool is_crtc_enabled = crtc_state->active;
bool turn_off, turn_on, visible, was_visible;
struct drm_framebuffer *fb = plane_state->fb;
int ret;
if (INTEL_GEN(dev_priv) >= 9 && plane->type != DRM_PLANE_TYPE_CURSOR) {
ret = skl_update_scaler_plane(
to_intel_crtc_state(crtc_state),
to_intel_plane_state(plane_state));
if (ret)
return ret;
}
was_visible = old_plane_state->base.visible;
visible = to_intel_plane_state(plane_state)->base.visible;
if (!was_crtc_enabled && WARN_ON(was_visible))
was_visible = false;
if (!is_crtc_enabled)
to_intel_plane_state(plane_state)->base.visible = visible = false;
if (!was_visible && !visible)
return 0;
if (fb != old_plane_state->base.fb)
pipe_config->fb_changed = true;
turn_off = was_visible && (!visible || mode_changed);
turn_on = visible && (!was_visible || mode_changed);
DRM_DEBUG_ATOMIC("[CRTC:%d:%s] has [PLANE:%d:%s] with fb %i\n",
intel_crtc->base.base.id,
intel_crtc->base.name,
plane->base.id, plane->name,
fb ? fb->base.id : -1);
DRM_DEBUG_ATOMIC("[PLANE:%d:%s] visible %i -> %i, off %i, on %i, ms %i\n",
plane->base.id, plane->name,
was_visible, visible,
turn_off, turn_on, mode_changed);
if (turn_on) {
pipe_config->update_wm_pre = true;
if (plane->type != DRM_PLANE_TYPE_CURSOR)
pipe_config->disable_cxsr = true;
} else if (turn_off) {
pipe_config->update_wm_post = true;
if (plane->type != DRM_PLANE_TYPE_CURSOR)
pipe_config->disable_cxsr = true;
} else if (intel_wm_need_update(plane, plane_state)) {
pipe_config->update_wm_pre = true;
pipe_config->update_wm_post = true;
}
if ((pipe_config->update_wm_pre || pipe_config->update_wm_post) &&
INTEL_GEN(dev_priv) < 9 && dev_priv->display.optimize_watermarks)
to_intel_crtc_state(crtc_state)->wm.need_postvbl_update = true;
if (visible || was_visible)
pipe_config->fb_bits |= to_intel_plane(plane)->frontbuffer_bit;
if (plane->type == DRM_PLANE_TYPE_OVERLAY && IS_IVYBRIDGE(dev_priv) &&
needs_scaling(to_intel_plane_state(plane_state)) &&
!needs_scaling(old_plane_state))
pipe_config->disable_lp_wm = true;
return 0;
}
static bool encoders_cloneable(const struct intel_encoder *a,
const struct intel_encoder *b)
{
return a == b || (a->cloneable & (1 << b->type) &&
b->cloneable & (1 << a->type));
}
static bool check_single_encoder_cloning(struct drm_atomic_state *state,
struct intel_crtc *crtc,
struct intel_encoder *encoder)
{
struct intel_encoder *source_encoder;
struct drm_connector *connector;
struct drm_connector_state *connector_state;
int i;
for_each_connector_in_state(state, connector, connector_state, i) {
if (connector_state->crtc != &crtc->base)
continue;
source_encoder =
to_intel_encoder(connector_state->best_encoder);
if (!encoders_cloneable(encoder, source_encoder))
return false;
}
return true;
}
static int intel_crtc_atomic_check(struct drm_crtc *crtc,
struct drm_crtc_state *crtc_state)
{
struct drm_device *dev = crtc->dev;
struct drm_i915_private *dev_priv = to_i915(dev);
struct intel_crtc *intel_crtc = to_intel_crtc(crtc);
struct intel_crtc_state *pipe_config =
to_intel_crtc_state(crtc_state);
struct drm_atomic_state *state = crtc_state->state;
int ret;
bool mode_changed = needs_modeset(crtc_state);
if (mode_changed && !crtc_state->active)
pipe_config->update_wm_post = true;
if (mode_changed && crtc_state->enable &&
dev_priv->display.crtc_compute_clock &&
!WARN_ON(pipe_config->shared_dpll)) {
ret = dev_priv->display.crtc_compute_clock(intel_crtc,
pipe_config);
if (ret)
return ret;
}
if (crtc_state->color_mgmt_changed) {
ret = intel_color_check(crtc, crtc_state);
if (ret)
return ret;
crtc_state->planes_changed = true;
}
ret = 0;
if (dev_priv->display.compute_pipe_wm) {
ret = dev_priv->display.compute_pipe_wm(pipe_config);
if (ret) {
DRM_DEBUG_KMS("Target pipe watermarks are invalid\n");
return ret;
}
}
if (dev_priv->display.compute_intermediate_wm &&
!to_intel_atomic_state(state)->skip_intermediate_wm) {
if (WARN_ON(!dev_priv->display.compute_pipe_wm))
return 0;
ret = dev_priv->display.compute_intermediate_wm(dev,
intel_crtc,
pipe_config);
if (ret) {
DRM_DEBUG_KMS("No valid intermediate pipe watermarks are possible\n");
return ret;
}
} else if (dev_priv->display.compute_intermediate_wm) {
if (HAS_PCH_SPLIT(dev_priv) && INTEL_GEN(dev_priv) < 9)
pipe_config->wm.ilk.intermediate = pipe_config->wm.ilk.optimal;
}
if (INTEL_GEN(dev_priv) >= 9) {
if (mode_changed)
ret = skl_update_scaler_crtc(pipe_config);
if (!ret)
ret = intel_atomic_setup_scalers(dev, intel_crtc,
pipe_config);
}
return ret;
}
static void intel_modeset_update_connector_atomic_state(struct drm_device *dev)
{
struct intel_connector *connector;
for_each_intel_connector(dev, connector) {
if (connector->base.state->crtc)
drm_connector_unreference(&connector->base);
if (connector->base.encoder) {
connector->base.state->best_encoder =
connector->base.encoder;
connector->base.state->crtc =
connector->base.encoder->crtc;
drm_connector_reference(&connector->base);
} else {
connector->base.state->best_encoder = NULL;
connector->base.state->crtc = NULL;
}
}
}
static void
connected_sink_compute_bpp(struct intel_connector *connector,
struct intel_crtc_state *pipe_config)
{
const struct drm_display_info *info = &connector->base.display_info;
int bpp = pipe_config->pipe_bpp;
DRM_DEBUG_KMS("[CONNECTOR:%d:%s] checking for sink bpp constrains\n",
connector->base.base.id,
connector->base.name);
if (info->bpc != 0 && info->bpc * 3 < bpp) {
DRM_DEBUG_KMS("clamping display bpp (was %d) to EDID reported max of %d\n",
bpp, info->bpc * 3);
pipe_config->pipe_bpp = info->bpc * 3;
}
if (info->bpc == 0 && bpp > 24) {
DRM_DEBUG_KMS("clamping display bpp (was %d) to default limit of 24\n",
bpp);
pipe_config->pipe_bpp = 24;
}
}
static int
compute_baseline_pipe_bpp(struct intel_crtc *crtc,
struct intel_crtc_state *pipe_config)
{
struct drm_i915_private *dev_priv = to_i915(crtc->base.dev);
struct drm_atomic_state *state;
struct drm_connector *connector;
struct drm_connector_state *connector_state;
int bpp, i;
if ((IS_G4X(dev_priv) || IS_VALLEYVIEW(dev_priv) ||
IS_CHERRYVIEW(dev_priv)))
bpp = 10*3;
else if (INTEL_GEN(dev_priv) >= 5)
bpp = 12*3;
else
bpp = 8*3;
pipe_config->pipe_bpp = bpp;
state = pipe_config->base.state;
for_each_connector_in_state(state, connector, connector_state, i) {
if (connector_state->crtc != &crtc->base)
continue;
connected_sink_compute_bpp(to_intel_connector(connector),
pipe_config);
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
static inline void
intel_dump_m_n_config(struct intel_crtc_state *pipe_config, char *id,
unsigned int lane_count, struct intel_link_m_n *m_n)
{
DRM_DEBUG_KMS("%s: lanes: %i; gmch_m: %u, gmch_n: %u, link_m: %u, link_n: %u, tu: %u\n",
id, lane_count,
m_n->gmch_m, m_n->gmch_n,
m_n->link_m, m_n->link_n, m_n->tu);
}
static void intel_dump_pipe_config(struct intel_crtc *crtc,
struct intel_crtc_state *pipe_config,
const char *context)
{
struct drm_device *dev = crtc->base.dev;
struct drm_i915_private *dev_priv = to_i915(dev);
struct drm_plane *plane;
struct intel_plane *intel_plane;
struct intel_plane_state *state;
struct drm_framebuffer *fb;
DRM_DEBUG_KMS("[CRTC:%d:%s]%s\n",
crtc->base.base.id, crtc->base.name, context);
DRM_DEBUG_KMS("cpu_transcoder: %s, pipe bpp: %i, dithering: %i\n",
transcoder_name(pipe_config->cpu_transcoder),
pipe_config->pipe_bpp, pipe_config->dither);
if (pipe_config->has_pch_encoder)
intel_dump_m_n_config(pipe_config, "fdi",
pipe_config->fdi_lanes,
&pipe_config->fdi_m_n);
if (intel_crtc_has_dp_encoder(pipe_config)) {
intel_dump_m_n_config(pipe_config, "dp m_n",
pipe_config->lane_count, &pipe_config->dp_m_n);
if (pipe_config->has_drrs)
intel_dump_m_n_config(pipe_config, "dp m2_n2",
pipe_config->lane_count,
&pipe_config->dp_m2_n2);
}
DRM_DEBUG_KMS("audio: %i, infoframes: %i\n",
pipe_config->has_audio, pipe_config->has_infoframe);
DRM_DEBUG_KMS("requested mode:\n");
drm_mode_debug_printmodeline(&pipe_config->base.mode);
DRM_DEBUG_KMS("adjusted mode:\n");
drm_mode_debug_printmodeline(&pipe_config->base.adjusted_mode);
intel_dump_crtc_timings(&pipe_config->base.adjusted_mode);
DRM_DEBUG_KMS("port clock: %d, pipe src size: %dx%d\n",
pipe_config->port_clock,
pipe_config->pipe_src_w, pipe_config->pipe_src_h);
if (INTEL_GEN(dev_priv) >= 9)
DRM_DEBUG_KMS("num_scalers: %d, scaler_users: 0x%x, scaler_id: %d\n",
crtc->num_scalers,
pipe_config->scaler_state.scaler_users,
pipe_config->scaler_state.scaler_id);
if (HAS_GMCH_DISPLAY(dev_priv))
DRM_DEBUG_KMS("gmch pfit: control: 0x%08x, ratios: 0x%08x, lvds border: 0x%08x\n",
pipe_config->gmch_pfit.control,
pipe_config->gmch_pfit.pgm_ratios,
pipe_config->gmch_pfit.lvds_border_bits);
else
DRM_DEBUG_KMS("pch pfit: pos: 0x%08x, size: 0x%08x, %s\n",
pipe_config->pch_pfit.pos,
pipe_config->pch_pfit.size,
enableddisabled(pipe_config->pch_pfit.enabled));
DRM_DEBUG_KMS("ips: %i, double wide: %i\n",
pipe_config->ips_enabled, pipe_config->double_wide);
if (IS_BROXTON(dev_priv)) {
DRM_DEBUG_KMS("dpll_hw_state: ebb0: 0x%x, ebb4: 0x%x,"
"pll0: 0x%x, pll1: 0x%x, pll2: 0x%x, pll3: 0x%x, "
"pll6: 0x%x, pll8: 0x%x, pll9: 0x%x, pll10: 0x%x, pcsdw12: 0x%x\n",
pipe_config->dpll_hw_state.ebb0,
pipe_config->dpll_hw_state.ebb4,
pipe_config->dpll_hw_state.pll0,
pipe_config->dpll_hw_state.pll1,
pipe_config->dpll_hw_state.pll2,
pipe_config->dpll_hw_state.pll3,
pipe_config->dpll_hw_state.pll6,
pipe_config->dpll_hw_state.pll8,
pipe_config->dpll_hw_state.pll9,
pipe_config->dpll_hw_state.pll10,
pipe_config->dpll_hw_state.pcsdw12);
} else if (IS_SKYLAKE(dev_priv) || IS_KABYLAKE(dev_priv)) {
DRM_DEBUG_KMS("dpll_hw_state: "
"ctrl1: 0x%x, cfgcr1: 0x%x, cfgcr2: 0x%x\n",
pipe_config->dpll_hw_state.ctrl1,
pipe_config->dpll_hw_state.cfgcr1,
pipe_config->dpll_hw_state.cfgcr2);
} else if (HAS_DDI(dev_priv)) {
DRM_DEBUG_KMS("dpll_hw_state: wrpll: 0x%x spll: 0x%x\n",
pipe_config->dpll_hw_state.wrpll,
pipe_config->dpll_hw_state.spll);
} else {
DRM_DEBUG_KMS("dpll_hw_state: dpll: 0x%x, dpll_md: 0x%x, "
"fp0: 0x%x, fp1: 0x%x\n",
pipe_config->dpll_hw_state.dpll,
pipe_config->dpll_hw_state.dpll_md,
pipe_config->dpll_hw_state.fp0,
pipe_config->dpll_hw_state.fp1);
}
DRM_DEBUG_KMS("planes on this crtc\n");
list_for_each_entry(plane, &dev->mode_config.plane_list, head) {
struct drm_format_name_buf format_name;
intel_plane = to_intel_plane(plane);
if (intel_plane->pipe != crtc->pipe)
continue;
state = to_intel_plane_state(plane->state);
fb = state->base.fb;
if (!fb) {
DRM_DEBUG_KMS("[PLANE:%d:%s] disabled, scaler_id = %d\n",
plane->base.id, plane->name, state->scaler_id);
continue;
}
DRM_DEBUG_KMS("[PLANE:%d:%s] FB:%d, fb = %ux%u format = %s\n",
plane->base.id, plane->name,
fb->base.id, fb->width, fb->height,
drm_get_format_name(fb->pixel_format, &format_name));
if (INTEL_GEN(dev_priv) >= 9)
DRM_DEBUG_KMS("\tscaler:%d src %dx%d+%d+%d dst %dx%d+%d+%d\n",
state->scaler_id,
state->base.src.x1 >> 16,
state->base.src.y1 >> 16,
drm_rect_width(&state->base.src) >> 16,
drm_rect_height(&state->base.src) >> 16,
state->base.dst.x1, state->base.dst.y1,
drm_rect_width(&state->base.dst),
drm_rect_height(&state->base.dst));
}
}
static bool check_digital_port_conflicts(struct drm_atomic_state *state)
{
struct drm_device *dev = state->dev;
struct drm_connector *connector;
unsigned int used_ports = 0;
unsigned int used_mst_ports = 0;
drm_for_each_connector(connector, dev) {
struct drm_connector_state *connector_state;
struct intel_encoder *encoder;
connector_state = drm_atomic_get_existing_connector_state(state, connector);
if (!connector_state)
connector_state = connector->state;
if (!connector_state->best_encoder)
continue;
encoder = to_intel_encoder(connector_state->best_encoder);
WARN_ON(!connector_state->crtc);
switch (encoder->type) {
unsigned int port_mask;
case INTEL_OUTPUT_UNKNOWN:
if (WARN_ON(!HAS_DDI(to_i915(dev))))
break;
case INTEL_OUTPUT_DP:
case INTEL_OUTPUT_HDMI:
case INTEL_OUTPUT_EDP:
port_mask = 1 << enc_to_dig_port(&encoder->base)->port;
if (used_ports & port_mask)
return false;
used_ports |= port_mask;
break;
case INTEL_OUTPUT_DP_MST:
used_mst_ports |=
1 << enc_to_mst(&encoder->base)->primary->port;
break;
default:
break;
}
}
if (used_ports & used_mst_ports)
return false;
return true;
}
static void
clear_intel_crtc_state(struct intel_crtc_state *crtc_state)
{
struct drm_crtc_state tmp_state;
struct intel_crtc_scaler_state scaler_state;
struct intel_dpll_hw_state dpll_hw_state;
struct intel_shared_dpll *shared_dpll;
bool force_thru;
tmp_state = crtc_state->base;
scaler_state = crtc_state->scaler_state;
shared_dpll = crtc_state->shared_dpll;
dpll_hw_state = crtc_state->dpll_hw_state;
force_thru = crtc_state->pch_pfit.force_thru;
memset(crtc_state, 0, sizeof *crtc_state);
crtc_state->base = tmp_state;
crtc_state->scaler_state = scaler_state;
crtc_state->shared_dpll = shared_dpll;
crtc_state->dpll_hw_state = dpll_hw_state;
crtc_state->pch_pfit.force_thru = force_thru;
}
static int
intel_modeset_pipe_config(struct drm_crtc *crtc,
struct intel_crtc_state *pipe_config)
{
struct drm_atomic_state *state = pipe_config->base.state;
struct intel_encoder *encoder;
struct drm_connector *connector;
struct drm_connector_state *connector_state;
int base_bpp, ret = -EINVAL;
int i;
bool retry = true;
clear_intel_crtc_state(pipe_config);
pipe_config->cpu_transcoder =
(enum transcoder) to_intel_crtc(crtc)->pipe;
if (!(pipe_config->base.adjusted_mode.flags &
(DRM_MODE_FLAG_PHSYNC | DRM_MODE_FLAG_NHSYNC)))
pipe_config->base.adjusted_mode.flags |= DRM_MODE_FLAG_NHSYNC;
if (!(pipe_config->base.adjusted_mode.flags &
(DRM_MODE_FLAG_PVSYNC | DRM_MODE_FLAG_NVSYNC)))
pipe_config->base.adjusted_mode.flags |= DRM_MODE_FLAG_NVSYNC;
base_bpp = compute_baseline_pipe_bpp(to_intel_crtc(crtc),
pipe_config);
if (base_bpp < 0)
goto fail;
drm_crtc_get_hv_timing(&pipe_config->base.mode,
&pipe_config->pipe_src_w,
&pipe_config->pipe_src_h);
for_each_connector_in_state(state, connector, connector_state, i) {
if (connector_state->crtc != crtc)
continue;
encoder = to_intel_encoder(connector_state->best_encoder);
if (!check_single_encoder_cloning(state, to_intel_crtc(crtc), encoder)) {
DRM_DEBUG_KMS("rejecting invalid cloning configuration\n");
goto fail;
}
pipe_config->output_types |= 1 << encoder->type;
}
encoder_retry:
pipe_config->port_clock = 0;
pipe_config->pixel_multiplier = 1;
drm_mode_set_crtcinfo(&pipe_config->base.adjusted_mode,
CRTC_STEREO_DOUBLE);
for_each_connector_in_state(state, connector, connector_state, i) {
if (connector_state->crtc != crtc)
continue;
encoder = to_intel_encoder(connector_state->best_encoder);
if (!(encoder->compute_config(encoder, pipe_config, connector_state))) {
DRM_DEBUG_KMS("Encoder config failure\n");
goto fail;
}
}
if (!pipe_config->port_clock)
pipe_config->port_clock = pipe_config->base.adjusted_mode.crtc_clock
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
pipe_config->dither = pipe_config->pipe_bpp == 6*3;
DRM_DEBUG_KMS("hw max bpp: %i, pipe bpp: %i, dithering: %i\n",
base_bpp, pipe_config->pipe_bpp, pipe_config->dither);
fail:
return ret;
}
static void
intel_modeset_update_crtc_state(struct drm_atomic_state *state)
{
struct drm_crtc *crtc;
struct drm_crtc_state *crtc_state;
int i;
for_each_crtc_in_state(state, crtc, crtc_state, i) {
to_intel_crtc(crtc)->config = to_intel_crtc_state(crtc->state);
if (crtc->state->active)
crtc->hwmode = crtc->state->adjusted_mode;
else
crtc->hwmode.crtc_clock = 0;
if (drm_atomic_get_existing_plane_state(state, crtc->primary)) {
struct drm_plane_state *plane_state = crtc->primary->state;
crtc->primary->fb = plane_state->fb;
crtc->x = plane_state->src_x >> 16;
crtc->y = plane_state->src_y >> 16;
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
intel_compare_m_n(unsigned int m, unsigned int n,
unsigned int m2, unsigned int n2,
bool exact)
{
if (m == m2 && n == n2)
return true;
if (exact || !m || !n || !m2 || !n2)
return false;
BUILD_BUG_ON(DATA_LINK_M_N_MASK > INT_MAX);
if (n > n2) {
while (n > n2) {
m2 <<= 1;
n2 <<= 1;
}
} else if (n < n2) {
while (n < n2) {
m <<= 1;
n <<= 1;
}
}
if (n != n2)
return false;
return intel_fuzzy_clock_check(m, m2);
}
static bool
intel_compare_link_m_n(const struct intel_link_m_n *m_n,
struct intel_link_m_n *m2_n2,
bool adjust)
{
if (m_n->tu == m2_n2->tu &&
intel_compare_m_n(m_n->gmch_m, m_n->gmch_n,
m2_n2->gmch_m, m2_n2->gmch_n, !adjust) &&
intel_compare_m_n(m_n->link_m, m_n->link_n,
m2_n2->link_m, m2_n2->link_n, !adjust)) {
if (adjust)
*m2_n2 = *m_n;
return true;
}
return false;
}
static bool
intel_pipe_config_compare(struct drm_i915_private *dev_priv,
struct intel_crtc_state *current_config,
struct intel_crtc_state *pipe_config,
bool adjust)
{
bool ret = true;
#define INTEL_ERR_OR_DBG_KMS(fmt, ...) \
do { \
if (!adjust) \
DRM_ERROR(fmt, ##__VA_ARGS__); \
else \
DRM_DEBUG_KMS(fmt, ##__VA_ARGS__); \
} while (0)
#define PIPE_CONF_CHECK_X(name) \
if (current_config->name != pipe_config->name) { \
INTEL_ERR_OR_DBG_KMS("mismatch in " #name " " \
"(expected 0x%08x, found 0x%08x)\n", \
current_config->name, \
pipe_config->name); \
ret = false; \
}
#define PIPE_CONF_CHECK_I(name) \
if (current_config->name != pipe_config->name) { \
INTEL_ERR_OR_DBG_KMS("mismatch in " #name " " \
"(expected %i, found %i)\n", \
current_config->name, \
pipe_config->name); \
ret = false; \
}
#define PIPE_CONF_CHECK_P(name) \
if (current_config->name != pipe_config->name) { \
INTEL_ERR_OR_DBG_KMS("mismatch in " #name " " \
"(expected %p, found %p)\n", \
current_config->name, \
pipe_config->name); \
ret = false; \
}
#define PIPE_CONF_CHECK_M_N(name) \
if (!intel_compare_link_m_n(&current_config->name, \
&pipe_config->name,\
adjust)) { \
INTEL_ERR_OR_DBG_KMS("mismatch in " #name " " \
"(expected tu %i gmch %i/%i link %i/%i, " \
"found tu %i, gmch %i/%i link %i/%i)\n", \
current_config->name.tu, \
current_config->name.gmch_m, \
current_config->name.gmch_n, \
current_config->name.link_m, \
current_config->name.link_n, \
pipe_config->name.tu, \
pipe_config->name.gmch_m, \
pipe_config->name.gmch_n, \
pipe_config->name.link_m, \
pipe_config->name.link_n); \
ret = false; \
}
#define PIPE_CONF_CHECK_M_N_ALT(name, alt_name) \
if (!intel_compare_link_m_n(&current_config->name, \
&pipe_config->name, adjust) && \
!intel_compare_link_m_n(&current_config->alt_name, \
&pipe_config->name, adjust)) { \
INTEL_ERR_OR_DBG_KMS("mismatch in " #name " " \
"(expected tu %i gmch %i/%i link %i/%i, " \
"or tu %i gmch %i/%i link %i/%i, " \
"found tu %i, gmch %i/%i link %i/%i)\n", \
current_config->name.tu, \
current_config->name.gmch_m, \
current_config->name.gmch_n, \
current_config->name.link_m, \
current_config->name.link_n, \
current_config->alt_name.tu, \
current_config->alt_name.gmch_m, \
current_config->alt_name.gmch_n, \
current_config->alt_name.link_m, \
current_config->alt_name.link_n, \
pipe_config->name.tu, \
pipe_config->name.gmch_m, \
pipe_config->name.gmch_n, \
pipe_config->name.link_m, \
pipe_config->name.link_n); \
ret = false; \
}
#define PIPE_CONF_CHECK_FLAGS(name, mask) \
if ((current_config->name ^ pipe_config->name) & (mask)) { \
INTEL_ERR_OR_DBG_KMS("mismatch in " #name "(" #mask ") " \
"(expected %i, found %i)\n", \
current_config->name & (mask), \
pipe_config->name & (mask)); \
ret = false; \
}
#define PIPE_CONF_CHECK_CLOCK_FUZZY(name) \
if (!intel_fuzzy_clock_check(current_config->name, pipe_config->name)) { \
INTEL_ERR_OR_DBG_KMS("mismatch in " #name " " \
"(expected %i, found %i)\n", \
current_config->name, \
pipe_config->name); \
ret = false; \
}
#define PIPE_CONF_QUIRK(quirk) \
((current_config->quirks | pipe_config->quirks) & (quirk))
PIPE_CONF_CHECK_I(cpu_transcoder);
PIPE_CONF_CHECK_I(has_pch_encoder);
PIPE_CONF_CHECK_I(fdi_lanes);
PIPE_CONF_CHECK_M_N(fdi_m_n);
PIPE_CONF_CHECK_I(lane_count);
PIPE_CONF_CHECK_X(lane_lat_optim_mask);
if (INTEL_GEN(dev_priv) < 8) {
PIPE_CONF_CHECK_M_N(dp_m_n);
if (current_config->has_drrs)
PIPE_CONF_CHECK_M_N(dp_m2_n2);
} else
PIPE_CONF_CHECK_M_N_ALT(dp_m_n, dp_m2_n2);
PIPE_CONF_CHECK_X(output_types);
PIPE_CONF_CHECK_I(base.adjusted_mode.crtc_hdisplay);
PIPE_CONF_CHECK_I(base.adjusted_mode.crtc_htotal);
PIPE_CONF_CHECK_I(base.adjusted_mode.crtc_hblank_start);
PIPE_CONF_CHECK_I(base.adjusted_mode.crtc_hblank_end);
PIPE_CONF_CHECK_I(base.adjusted_mode.crtc_hsync_start);
PIPE_CONF_CHECK_I(base.adjusted_mode.crtc_hsync_end);
PIPE_CONF_CHECK_I(base.adjusted_mode.crtc_vdisplay);
PIPE_CONF_CHECK_I(base.adjusted_mode.crtc_vtotal);
PIPE_CONF_CHECK_I(base.adjusted_mode.crtc_vblank_start);
PIPE_CONF_CHECK_I(base.adjusted_mode.crtc_vblank_end);
PIPE_CONF_CHECK_I(base.adjusted_mode.crtc_vsync_start);
PIPE_CONF_CHECK_I(base.adjusted_mode.crtc_vsync_end);
PIPE_CONF_CHECK_I(pixel_multiplier);
PIPE_CONF_CHECK_I(has_hdmi_sink);
if ((INTEL_GEN(dev_priv) < 8 && !IS_HASWELL(dev_priv)) ||
IS_VALLEYVIEW(dev_priv) || IS_CHERRYVIEW(dev_priv))
PIPE_CONF_CHECK_I(limited_color_range);
PIPE_CONF_CHECK_I(has_infoframe);
PIPE_CONF_CHECK_I(has_audio);
PIPE_CONF_CHECK_FLAGS(base.adjusted_mode.flags,
DRM_MODE_FLAG_INTERLACE);
if (!PIPE_CONF_QUIRK(PIPE_CONFIG_QUIRK_MODE_SYNC_FLAGS)) {
PIPE_CONF_CHECK_FLAGS(base.adjusted_mode.flags,
DRM_MODE_FLAG_PHSYNC);
PIPE_CONF_CHECK_FLAGS(base.adjusted_mode.flags,
DRM_MODE_FLAG_NHSYNC);
PIPE_CONF_CHECK_FLAGS(base.adjusted_mode.flags,
DRM_MODE_FLAG_PVSYNC);
PIPE_CONF_CHECK_FLAGS(base.adjusted_mode.flags,
DRM_MODE_FLAG_NVSYNC);
}
PIPE_CONF_CHECK_X(gmch_pfit.control);
if (INTEL_GEN(dev_priv) < 4)
PIPE_CONF_CHECK_X(gmch_pfit.pgm_ratios);
PIPE_CONF_CHECK_X(gmch_pfit.lvds_border_bits);
if (!adjust) {
PIPE_CONF_CHECK_I(pipe_src_w);
PIPE_CONF_CHECK_I(pipe_src_h);
PIPE_CONF_CHECK_I(pch_pfit.enabled);
if (current_config->pch_pfit.enabled) {
PIPE_CONF_CHECK_X(pch_pfit.pos);
PIPE_CONF_CHECK_X(pch_pfit.size);
}
PIPE_CONF_CHECK_I(scaler_state.scaler_id);
}
if (IS_HASWELL(dev_priv))
PIPE_CONF_CHECK_I(ips_enabled);
PIPE_CONF_CHECK_I(double_wide);
PIPE_CONF_CHECK_P(shared_dpll);
PIPE_CONF_CHECK_X(dpll_hw_state.dpll);
PIPE_CONF_CHECK_X(dpll_hw_state.dpll_md);
PIPE_CONF_CHECK_X(dpll_hw_state.fp0);
PIPE_CONF_CHECK_X(dpll_hw_state.fp1);
PIPE_CONF_CHECK_X(dpll_hw_state.wrpll);
PIPE_CONF_CHECK_X(dpll_hw_state.spll);
PIPE_CONF_CHECK_X(dpll_hw_state.ctrl1);
PIPE_CONF_CHECK_X(dpll_hw_state.cfgcr1);
PIPE_CONF_CHECK_X(dpll_hw_state.cfgcr2);
PIPE_CONF_CHECK_X(dsi_pll.ctrl);
PIPE_CONF_CHECK_X(dsi_pll.div);
if (IS_G4X(dev_priv) || INTEL_GEN(dev_priv) >= 5)
PIPE_CONF_CHECK_I(pipe_bpp);
PIPE_CONF_CHECK_CLOCK_FUZZY(base.adjusted_mode.crtc_clock);
PIPE_CONF_CHECK_CLOCK_FUZZY(port_clock);
#undef PIPE_CONF_CHECK_X
#undef PIPE_CONF_CHECK_I
#undef PIPE_CONF_CHECK_P
#undef PIPE_CONF_CHECK_FLAGS
#undef PIPE_CONF_CHECK_CLOCK_FUZZY
#undef PIPE_CONF_QUIRK
#undef INTEL_ERR_OR_DBG_KMS
return ret;
}
static void intel_pipe_config_sanity_check(struct drm_i915_private *dev_priv,
const struct intel_crtc_state *pipe_config)
{
if (pipe_config->has_pch_encoder) {
int fdi_dotclock = intel_dotclock_calculate(intel_fdi_link_freq(dev_priv, pipe_config),
&pipe_config->fdi_m_n);
int dotclock = pipe_config->base.adjusted_mode.crtc_clock;
WARN(!intel_fuzzy_clock_check(fdi_dotclock, dotclock),
"FDI dotclock and encoder dotclock mismatch, fdi: %i, encoder: %i\n",
fdi_dotclock, dotclock);
}
}
static void verify_wm_state(struct drm_crtc *crtc,
struct drm_crtc_state *new_state)
{
struct drm_i915_private *dev_priv = to_i915(crtc->dev);
struct skl_ddb_allocation hw_ddb, *sw_ddb;
struct skl_pipe_wm hw_wm, *sw_wm;
struct skl_plane_wm *hw_plane_wm, *sw_plane_wm;
struct skl_ddb_entry *hw_ddb_entry, *sw_ddb_entry;
struct intel_crtc *intel_crtc = to_intel_crtc(crtc);
const enum pipe pipe = intel_crtc->pipe;
int plane, level, max_level = ilk_wm_max_level(dev_priv);
if (INTEL_GEN(dev_priv) < 9 || !new_state->active)
return;
skl_pipe_wm_get_hw_state(crtc, &hw_wm);
sw_wm = &to_intel_crtc_state(new_state)->wm.skl.optimal;
skl_ddb_get_hw_state(dev_priv, &hw_ddb);
sw_ddb = &dev_priv->wm.skl_hw.ddb;
for_each_universal_plane(dev_priv, pipe, plane) {
hw_plane_wm = &hw_wm.planes[plane];
sw_plane_wm = &sw_wm->planes[plane];
for (level = 0; level <= max_level; level++) {
if (skl_wm_level_equals(&hw_plane_wm->wm[level],
&sw_plane_wm->wm[level]))
continue;
DRM_ERROR("mismatch in WM pipe %c plane %d level %d (expected e=%d b=%u l=%u, got e=%d b=%u l=%u)\n",
pipe_name(pipe), plane + 1, level,
sw_plane_wm->wm[level].plane_en,
sw_plane_wm->wm[level].plane_res_b,
sw_plane_wm->wm[level].plane_res_l,
hw_plane_wm->wm[level].plane_en,
hw_plane_wm->wm[level].plane_res_b,
hw_plane_wm->wm[level].plane_res_l);
}
if (!skl_wm_level_equals(&hw_plane_wm->trans_wm,
&sw_plane_wm->trans_wm)) {
DRM_ERROR("mismatch in trans WM pipe %c plane %d (expected e=%d b=%u l=%u, got e=%d b=%u l=%u)\n",
pipe_name(pipe), plane + 1,
sw_plane_wm->trans_wm.plane_en,
sw_plane_wm->trans_wm.plane_res_b,
sw_plane_wm->trans_wm.plane_res_l,
hw_plane_wm->trans_wm.plane_en,
hw_plane_wm->trans_wm.plane_res_b,
hw_plane_wm->trans_wm.plane_res_l);
}
hw_ddb_entry = &hw_ddb.plane[pipe][plane];
sw_ddb_entry = &sw_ddb->plane[pipe][plane];
if (!skl_ddb_entry_equal(hw_ddb_entry, sw_ddb_entry)) {
DRM_ERROR("mismatch in DDB state pipe %c plane %d (expected (%u,%u), found (%u,%u))\n",
pipe_name(pipe), plane + 1,
sw_ddb_entry->start, sw_ddb_entry->end,
hw_ddb_entry->start, hw_ddb_entry->end);
}
}
if (intel_crtc->cursor_addr) {
hw_plane_wm = &hw_wm.planes[PLANE_CURSOR];
sw_plane_wm = &sw_wm->planes[PLANE_CURSOR];
for (level = 0; level <= max_level; level++) {
if (skl_wm_level_equals(&hw_plane_wm->wm[level],
&sw_plane_wm->wm[level]))
continue;
DRM_ERROR("mismatch in WM pipe %c cursor level %d (expected e=%d b=%u l=%u, got e=%d b=%u l=%u)\n",
pipe_name(pipe), level,
sw_plane_wm->wm[level].plane_en,
sw_plane_wm->wm[level].plane_res_b,
sw_plane_wm->wm[level].plane_res_l,
hw_plane_wm->wm[level].plane_en,
hw_plane_wm->wm[level].plane_res_b,
hw_plane_wm->wm[level].plane_res_l);
}
if (!skl_wm_level_equals(&hw_plane_wm->trans_wm,
&sw_plane_wm->trans_wm)) {
DRM_ERROR("mismatch in trans WM pipe %c cursor (expected e=%d b=%u l=%u, got e=%d b=%u l=%u)\n",
pipe_name(pipe),
sw_plane_wm->trans_wm.plane_en,
sw_plane_wm->trans_wm.plane_res_b,
sw_plane_wm->trans_wm.plane_res_l,
hw_plane_wm->trans_wm.plane_en,
hw_plane_wm->trans_wm.plane_res_b,
hw_plane_wm->trans_wm.plane_res_l);
}
hw_ddb_entry = &hw_ddb.plane[pipe][PLANE_CURSOR];
sw_ddb_entry = &sw_ddb->plane[pipe][PLANE_CURSOR];
if (!skl_ddb_entry_equal(hw_ddb_entry, sw_ddb_entry)) {
DRM_ERROR("mismatch in DDB state pipe %c cursor (expected (%u,%u), found (%u,%u))\n",
pipe_name(pipe),
sw_ddb_entry->start, sw_ddb_entry->end,
hw_ddb_entry->start, hw_ddb_entry->end);
}
}
}
static void
verify_connector_state(struct drm_device *dev,
struct drm_atomic_state *state,
struct drm_crtc *crtc)
{
struct drm_connector *connector;
struct drm_connector_state *old_conn_state;
int i;
for_each_connector_in_state(state, connector, old_conn_state, i) {
struct drm_encoder *encoder = connector->encoder;
struct drm_connector_state *state = connector->state;
if (state->crtc != crtc)
continue;
intel_connector_verify_state(to_intel_connector(connector));
I915_STATE_WARN(state->best_encoder != encoder,
"connector's atomic encoder doesn't match legacy encoder\n");
}
}
static void
verify_encoder_state(struct drm_device *dev)
{
struct intel_encoder *encoder;
struct intel_connector *connector;
for_each_intel_encoder(dev, encoder) {
bool enabled = false;
enum pipe pipe;
DRM_DEBUG_KMS("[ENCODER:%d:%s]\n",
encoder->base.base.id,
encoder->base.name);
for_each_intel_connector(dev, connector) {
if (connector->base.state->best_encoder != &encoder->base)
continue;
enabled = true;
I915_STATE_WARN(connector->base.state->crtc !=
encoder->base.crtc,
"connector's crtc doesn't match encoder crtc\n");
}
I915_STATE_WARN(!!encoder->base.crtc != enabled,
"encoder's enabled state mismatch "
"(expected %i, found %i)\n",
!!encoder->base.crtc, enabled);
if (!encoder->base.crtc) {
bool active;
active = encoder->get_hw_state(encoder, &pipe);
I915_STATE_WARN(active,
"encoder detached but still enabled on pipe %c.\n",
pipe_name(pipe));
}
}
}
static void
verify_crtc_state(struct drm_crtc *crtc,
struct drm_crtc_state *old_crtc_state,
struct drm_crtc_state *new_crtc_state)
{
struct drm_device *dev = crtc->dev;
struct drm_i915_private *dev_priv = to_i915(dev);
struct intel_encoder *encoder;
struct intel_crtc *intel_crtc = to_intel_crtc(crtc);
struct intel_crtc_state *pipe_config, *sw_config;
struct drm_atomic_state *old_state;
bool active;
old_state = old_crtc_state->state;
__drm_atomic_helper_crtc_destroy_state(old_crtc_state);
pipe_config = to_intel_crtc_state(old_crtc_state);
memset(pipe_config, 0, sizeof(*pipe_config));
pipe_config->base.crtc = crtc;
pipe_config->base.state = old_state;
DRM_DEBUG_KMS("[CRTC:%d:%s]\n", crtc->base.id, crtc->name);
active = dev_priv->display.get_pipe_config(intel_crtc, pipe_config);
if ((intel_crtc->pipe == PIPE_A && dev_priv->quirks & QUIRK_PIPEA_FORCE) ||
(intel_crtc->pipe == PIPE_B && dev_priv->quirks & QUIRK_PIPEB_FORCE))
active = new_crtc_state->active;
I915_STATE_WARN(new_crtc_state->active != active,
"crtc active state doesn't match with hw state "
"(expected %i, found %i)\n", new_crtc_state->active, active);
I915_STATE_WARN(intel_crtc->active != new_crtc_state->active,
"transitional active state does not match atomic hw state "
"(expected %i, found %i)\n", new_crtc_state->active, intel_crtc->active);
for_each_encoder_on_crtc(dev, crtc, encoder) {
enum pipe pipe;
active = encoder->get_hw_state(encoder, &pipe);
I915_STATE_WARN(active != new_crtc_state->active,
"[ENCODER:%i] active %i with crtc active %i\n",
encoder->base.base.id, active, new_crtc_state->active);
I915_STATE_WARN(active && intel_crtc->pipe != pipe,
"Encoder connected to wrong pipe %c\n",
pipe_name(pipe));
if (active) {
pipe_config->output_types |= 1 << encoder->type;
encoder->get_config(encoder, pipe_config);
}
}
if (!new_crtc_state->active)
return;
intel_pipe_config_sanity_check(dev_priv, pipe_config);
sw_config = to_intel_crtc_state(crtc->state);
if (!intel_pipe_config_compare(dev_priv, sw_config,
pipe_config, false)) {
I915_STATE_WARN(1, "pipe state doesn't match!\n");
intel_dump_pipe_config(intel_crtc, pipe_config,
"[hw state]");
intel_dump_pipe_config(intel_crtc, sw_config,
"[sw state]");
}
}
static void
verify_single_dpll_state(struct drm_i915_private *dev_priv,
struct intel_shared_dpll *pll,
struct drm_crtc *crtc,
struct drm_crtc_state *new_state)
{
struct intel_dpll_hw_state dpll_hw_state;
unsigned crtc_mask;
bool active;
memset(&dpll_hw_state, 0, sizeof(dpll_hw_state));
DRM_DEBUG_KMS("%s\n", pll->name);
active = pll->funcs.get_hw_state(dev_priv, pll, &dpll_hw_state);
if (!(pll->flags & INTEL_DPLL_ALWAYS_ON)) {
I915_STATE_WARN(!pll->on && pll->active_mask,
"pll in active use but not on in sw tracking\n");
I915_STATE_WARN(pll->on && !pll->active_mask,
"pll is on but not used by any active crtc\n");
I915_STATE_WARN(pll->on != active,
"pll on state mismatch (expected %i, found %i)\n",
pll->on, active);
}
if (!crtc) {
I915_STATE_WARN(pll->active_mask & ~pll->config.crtc_mask,
"more active pll users than references: %x vs %x\n",
pll->active_mask, pll->config.crtc_mask);
return;
}
crtc_mask = 1 << drm_crtc_index(crtc);
if (new_state->active)
I915_STATE_WARN(!(pll->active_mask & crtc_mask),
"pll active mismatch (expected pipe %c in active mask 0x%02x)\n",
pipe_name(drm_crtc_index(crtc)), pll->active_mask);
else
I915_STATE_WARN(pll->active_mask & crtc_mask,
"pll active mismatch (didn't expect pipe %c in active mask 0x%02x)\n",
pipe_name(drm_crtc_index(crtc)), pll->active_mask);
I915_STATE_WARN(!(pll->config.crtc_mask & crtc_mask),
"pll enabled crtcs mismatch (expected 0x%x in 0x%02x)\n",
crtc_mask, pll->config.crtc_mask);
I915_STATE_WARN(pll->on && memcmp(&pll->config.hw_state,
&dpll_hw_state,
sizeof(dpll_hw_state)),
"pll hw state mismatch\n");
}
static void
verify_shared_dpll_state(struct drm_device *dev, struct drm_crtc *crtc,
struct drm_crtc_state *old_crtc_state,
struct drm_crtc_state *new_crtc_state)
{
struct drm_i915_private *dev_priv = to_i915(dev);
struct intel_crtc_state *old_state = to_intel_crtc_state(old_crtc_state);
struct intel_crtc_state *new_state = to_intel_crtc_state(new_crtc_state);
if (new_state->shared_dpll)
verify_single_dpll_state(dev_priv, new_state->shared_dpll, crtc, new_crtc_state);
if (old_state->shared_dpll &&
old_state->shared_dpll != new_state->shared_dpll) {
unsigned crtc_mask = 1 << drm_crtc_index(crtc);
struct intel_shared_dpll *pll = old_state->shared_dpll;
I915_STATE_WARN(pll->active_mask & crtc_mask,
"pll active mismatch (didn't expect pipe %c in active mask)\n",
pipe_name(drm_crtc_index(crtc)));
I915_STATE_WARN(pll->config.crtc_mask & crtc_mask,
"pll enabled crtcs mismatch (found %x in enabled mask)\n",
pipe_name(drm_crtc_index(crtc)));
}
}
static void
intel_modeset_verify_crtc(struct drm_crtc *crtc,
struct drm_atomic_state *state,
struct drm_crtc_state *old_state,
struct drm_crtc_state *new_state)
{
if (!needs_modeset(new_state) &&
!to_intel_crtc_state(new_state)->update_pipe)
return;
verify_wm_state(crtc, new_state);
verify_connector_state(crtc->dev, state, crtc);
verify_crtc_state(crtc, old_state, new_state);
verify_shared_dpll_state(crtc->dev, crtc, old_state, new_state);
}
static void
verify_disabled_dpll_state(struct drm_device *dev)
{
struct drm_i915_private *dev_priv = to_i915(dev);
int i;
for (i = 0; i < dev_priv->num_shared_dpll; i++)
verify_single_dpll_state(dev_priv, &dev_priv->shared_dplls[i], NULL, NULL);
}
static void
intel_modeset_verify_disabled(struct drm_device *dev,
struct drm_atomic_state *state)
{
verify_encoder_state(dev);
verify_connector_state(dev, state, NULL);
verify_disabled_dpll_state(dev);
}
static void update_scanline_offset(struct intel_crtc *crtc)
{
struct drm_i915_private *dev_priv = to_i915(crtc->base.dev);
if (IS_GEN2(dev_priv)) {
const struct drm_display_mode *adjusted_mode = &crtc->config->base.adjusted_mode;
int vtotal;
vtotal = adjusted_mode->crtc_vtotal;
if (adjusted_mode->flags & DRM_MODE_FLAG_INTERLACE)
vtotal /= 2;
crtc->scanline_offset = vtotal - 1;
} else if (HAS_DDI(dev_priv) &&
intel_crtc_has_type(crtc->config, INTEL_OUTPUT_HDMI)) {
crtc->scanline_offset = 2;
} else
crtc->scanline_offset = 1;
}
static void intel_modeset_clear_plls(struct drm_atomic_state *state)
{
struct drm_device *dev = state->dev;
struct drm_i915_private *dev_priv = to_i915(dev);
struct intel_shared_dpll_config *shared_dpll = NULL;
struct drm_crtc *crtc;
struct drm_crtc_state *crtc_state;
int i;
if (!dev_priv->display.crtc_compute_clock)
return;
for_each_crtc_in_state(state, crtc, crtc_state, i) {
struct intel_crtc *intel_crtc = to_intel_crtc(crtc);
struct intel_shared_dpll *old_dpll =
to_intel_crtc_state(crtc->state)->shared_dpll;
if (!needs_modeset(crtc_state))
continue;
to_intel_crtc_state(crtc_state)->shared_dpll = NULL;
if (!old_dpll)
continue;
if (!shared_dpll)
shared_dpll = intel_atomic_get_shared_dpll_state(state);
intel_shared_dpll_config_put(shared_dpll, old_dpll, intel_crtc);
}
}
static int haswell_mode_set_planes_workaround(struct drm_atomic_state *state)
{
struct drm_crtc_state *crtc_state;
struct intel_crtc *intel_crtc;
struct drm_crtc *crtc;
struct intel_crtc_state *first_crtc_state = NULL;
struct intel_crtc_state *other_crtc_state = NULL;
enum pipe first_pipe = INVALID_PIPE, enabled_pipe = INVALID_PIPE;
int i;
for_each_crtc_in_state(state, crtc, crtc_state, i) {
intel_crtc = to_intel_crtc(crtc);
if (!crtc_state->active || !needs_modeset(crtc_state))
continue;
if (first_crtc_state) {
other_crtc_state = to_intel_crtc_state(crtc_state);
break;
} else {
first_crtc_state = to_intel_crtc_state(crtc_state);
first_pipe = intel_crtc->pipe;
}
}
if (!first_crtc_state)
return 0;
for_each_intel_crtc(state->dev, intel_crtc) {
struct intel_crtc_state *pipe_config;
pipe_config = intel_atomic_get_crtc_state(state, intel_crtc);
if (IS_ERR(pipe_config))
return PTR_ERR(pipe_config);
pipe_config->hsw_workaround_pipe = INVALID_PIPE;
if (!pipe_config->base.active ||
needs_modeset(&pipe_config->base))
continue;
if (enabled_pipe != INVALID_PIPE)
return 0;
enabled_pipe = intel_crtc->pipe;
}
if (enabled_pipe != INVALID_PIPE)
first_crtc_state->hsw_workaround_pipe = enabled_pipe;
else if (other_crtc_state)
other_crtc_state->hsw_workaround_pipe = first_pipe;
return 0;
}
static int intel_modeset_all_pipes(struct drm_atomic_state *state)
{
struct drm_crtc *crtc;
struct drm_crtc_state *crtc_state;
int ret = 0;
for_each_crtc(state->dev, crtc) {
crtc_state = drm_atomic_get_crtc_state(state, crtc);
if (IS_ERR(crtc_state))
return PTR_ERR(crtc_state);
if (!crtc_state->active || needs_modeset(crtc_state))
continue;
crtc_state->mode_changed = true;
ret = drm_atomic_add_affected_connectors(state, crtc);
if (ret)
break;
ret = drm_atomic_add_affected_planes(state, crtc);
if (ret)
break;
}
return ret;
}
static int intel_modeset_checks(struct drm_atomic_state *state)
{
struct intel_atomic_state *intel_state = to_intel_atomic_state(state);
struct drm_i915_private *dev_priv = to_i915(state->dev);
struct drm_crtc *crtc;
struct drm_crtc_state *crtc_state;
int ret = 0, i;
if (!check_digital_port_conflicts(state)) {
DRM_DEBUG_KMS("rejecting conflicting digital port configuration\n");
return -EINVAL;
}
intel_state->modeset = true;
intel_state->active_crtcs = dev_priv->active_crtcs;
for_each_crtc_in_state(state, crtc, crtc_state, i) {
if (crtc_state->active)
intel_state->active_crtcs |= 1 << i;
else
intel_state->active_crtcs &= ~(1 << i);
if (crtc_state->active != crtc->state->active)
intel_state->active_pipe_changes |= drm_crtc_mask(crtc);
}
if (dev_priv->display.modeset_calc_cdclk) {
if (!intel_state->cdclk_pll_vco)
intel_state->cdclk_pll_vco = dev_priv->cdclk_pll.vco;
if (!intel_state->cdclk_pll_vco)
intel_state->cdclk_pll_vco = dev_priv->skl_preferred_vco_freq;
ret = dev_priv->display.modeset_calc_cdclk(state);
if (ret < 0)
return ret;
if (intel_state->dev_cdclk != dev_priv->cdclk_freq ||
intel_state->cdclk_pll_vco != dev_priv->cdclk_pll.vco)
ret = intel_modeset_all_pipes(state);
if (ret < 0)
return ret;
DRM_DEBUG_KMS("New cdclk calculated to be atomic %u, actual %u\n",
intel_state->cdclk, intel_state->dev_cdclk);
} else {
to_intel_atomic_state(state)->cdclk = dev_priv->atomic_cdclk_freq;
}
intel_modeset_clear_plls(state);
if (IS_HASWELL(dev_priv))
return haswell_mode_set_planes_workaround(state);
return 0;
}
static int calc_watermark_data(struct drm_atomic_state *state)
{
struct drm_device *dev = state->dev;
struct drm_i915_private *dev_priv = to_i915(dev);
if (dev_priv->display.compute_global_watermarks)
return dev_priv->display.compute_global_watermarks(state);
return 0;
}
static int intel_atomic_check(struct drm_device *dev,
struct drm_atomic_state *state)
{
struct drm_i915_private *dev_priv = to_i915(dev);
struct intel_atomic_state *intel_state = to_intel_atomic_state(state);
struct drm_crtc *crtc;
struct drm_crtc_state *crtc_state;
int ret, i;
bool any_ms = false;
ret = drm_atomic_helper_check_modeset(dev, state);
if (ret)
return ret;
for_each_crtc_in_state(state, crtc, crtc_state, i) {
struct intel_crtc_state *pipe_config =
to_intel_crtc_state(crtc_state);
if (crtc_state->mode.private_flags != crtc->state->mode.private_flags)
crtc_state->mode_changed = true;
if (!needs_modeset(crtc_state))
continue;
if (!crtc_state->enable) {
any_ms = true;
continue;
}
ret = drm_atomic_add_affected_connectors(state, crtc);
if (ret)
return ret;
ret = intel_modeset_pipe_config(crtc, pipe_config);
if (ret) {
intel_dump_pipe_config(to_intel_crtc(crtc),
pipe_config, "[failed]");
return ret;
}
if (i915.fastboot &&
intel_pipe_config_compare(dev_priv,
to_intel_crtc_state(crtc->state),
pipe_config, true)) {
crtc_state->mode_changed = false;
to_intel_crtc_state(crtc_state)->update_pipe = true;
}
if (needs_modeset(crtc_state))
any_ms = true;
ret = drm_atomic_add_affected_planes(state, crtc);
if (ret)
return ret;
intel_dump_pipe_config(to_intel_crtc(crtc), pipe_config,
needs_modeset(crtc_state) ?
"[modeset]" : "[fastset]");
}
if (any_ms) {
ret = intel_modeset_checks(state);
if (ret)
return ret;
} else {
intel_state->cdclk = dev_priv->atomic_cdclk_freq;
}
ret = drm_atomic_helper_check_planes(dev, state);
if (ret)
return ret;
intel_fbc_choose_crtc(dev_priv, state);
return calc_watermark_data(state);
}
static int intel_atomic_prepare_commit(struct drm_device *dev,
struct drm_atomic_state *state)
{
struct drm_i915_private *dev_priv = to_i915(dev);
struct drm_crtc_state *crtc_state;
struct drm_crtc *crtc;
int i, ret;
for_each_crtc_in_state(state, crtc, crtc_state, i) {
if (state->legacy_cursor_update)
continue;
ret = intel_crtc_wait_for_pending_flips(crtc);
if (ret)
return ret;
if (atomic_read(&to_intel_crtc(crtc)->unpin_work_count) >= 2)
flush_workqueue(dev_priv->wq);
}
ret = mutex_lock_interruptible(&dev->struct_mutex);
if (ret)
return ret;
ret = drm_atomic_helper_prepare_planes(dev, state);
mutex_unlock(&dev->struct_mutex);
return ret;
}
u32 intel_crtc_get_vblank_counter(struct intel_crtc *crtc)
{
struct drm_device *dev = crtc->base.dev;
if (!dev->max_vblank_count)
return drm_accurate_vblank_count(&crtc->base);
return dev->driver->get_vblank_counter(dev, crtc->pipe);
}
static void intel_atomic_wait_for_vblanks(struct drm_device *dev,
struct drm_i915_private *dev_priv,
unsigned crtc_mask)
{
unsigned last_vblank_count[I915_MAX_PIPES];
enum pipe pipe;
int ret;
if (!crtc_mask)
return;
for_each_pipe(dev_priv, pipe) {
struct intel_crtc *crtc = intel_get_crtc_for_pipe(dev_priv,
pipe);
if (!((1 << pipe) & crtc_mask))
continue;
ret = drm_crtc_vblank_get(&crtc->base);
if (WARN_ON(ret != 0)) {
crtc_mask &= ~(1 << pipe);
continue;
}
last_vblank_count[pipe] = drm_crtc_vblank_count(&crtc->base);
}
for_each_pipe(dev_priv, pipe) {
struct intel_crtc *crtc = intel_get_crtc_for_pipe(dev_priv,
pipe);
long lret;
if (!((1 << pipe) & crtc_mask))
continue;
lret = wait_event_timeout(dev->vblank[pipe].queue,
last_vblank_count[pipe] !=
drm_crtc_vblank_count(&crtc->base),
msecs_to_jiffies(50));
WARN(!lret, "pipe %c vblank wait timed out\n", pipe_name(pipe));
drm_crtc_vblank_put(&crtc->base);
}
}
static bool needs_vblank_wait(struct intel_crtc_state *crtc_state)
{
if (crtc_state->fb_changed)
return true;
if (crtc_state->update_wm_post)
return true;
if (crtc_state->disable_cxsr)
return true;
return false;
}
static void intel_update_crtc(struct drm_crtc *crtc,
struct drm_atomic_state *state,
struct drm_crtc_state *old_crtc_state,
unsigned int *crtc_vblank_mask)
{
struct drm_device *dev = crtc->dev;
struct drm_i915_private *dev_priv = to_i915(dev);
struct intel_crtc *intel_crtc = to_intel_crtc(crtc);
struct intel_crtc_state *pipe_config = to_intel_crtc_state(crtc->state);
bool modeset = needs_modeset(crtc->state);
if (modeset) {
update_scanline_offset(intel_crtc);
dev_priv->display.crtc_enable(pipe_config, state);
} else {
intel_pre_plane_update(to_intel_crtc_state(old_crtc_state));
}
if (drm_atomic_get_existing_plane_state(state, crtc->primary)) {
intel_fbc_enable(
intel_crtc, pipe_config,
to_intel_plane_state(crtc->primary->state));
}
drm_atomic_helper_commit_planes_on_crtc(old_crtc_state);
if (needs_vblank_wait(pipe_config))
*crtc_vblank_mask |= drm_crtc_mask(crtc);
}
static void intel_update_crtcs(struct drm_atomic_state *state,
unsigned int *crtc_vblank_mask)
{
struct drm_crtc *crtc;
struct drm_crtc_state *old_crtc_state;
int i;
for_each_crtc_in_state(state, crtc, old_crtc_state, i) {
if (!crtc->state->active)
continue;
intel_update_crtc(crtc, state, old_crtc_state,
crtc_vblank_mask);
}
}
static void skl_update_crtcs(struct drm_atomic_state *state,
unsigned int *crtc_vblank_mask)
{
struct drm_i915_private *dev_priv = to_i915(state->dev);
struct intel_atomic_state *intel_state = to_intel_atomic_state(state);
struct drm_crtc *crtc;
struct intel_crtc *intel_crtc;
struct drm_crtc_state *old_crtc_state;
struct intel_crtc_state *cstate;
unsigned int updated = 0;
bool progress;
enum pipe pipe;
int i;
const struct skl_ddb_entry *entries[I915_MAX_PIPES] = {};
for_each_crtc_in_state(state, crtc, old_crtc_state, i)
if (crtc->state->active)
entries[i] = &to_intel_crtc_state(old_crtc_state)->wm.skl.ddb;
do {
progress = false;
for_each_crtc_in_state(state, crtc, old_crtc_state, i) {
bool vbl_wait = false;
unsigned int cmask = drm_crtc_mask(crtc);
intel_crtc = to_intel_crtc(crtc);
cstate = to_intel_crtc_state(crtc->state);
pipe = intel_crtc->pipe;
if (updated & cmask || !cstate->base.active)
continue;
if (skl_ddb_allocation_overlaps(entries, &cstate->wm.skl.ddb, i))
continue;
updated |= cmask;
entries[i] = &cstate->wm.skl.ddb;
if (!skl_ddb_entry_equal(&cstate->wm.skl.ddb,
&to_intel_crtc_state(old_crtc_state)->wm.skl.ddb) &&
!crtc->state->active_changed &&
intel_state->wm_results.dirty_pipes != updated)
vbl_wait = true;
intel_update_crtc(crtc, state, old_crtc_state,
crtc_vblank_mask);
if (vbl_wait)
intel_wait_for_vblank(dev_priv, pipe);
progress = true;
}
} while (progress);
}
static void intel_atomic_commit_tail(struct drm_atomic_state *state)
{
struct drm_device *dev = state->dev;
struct intel_atomic_state *intel_state = to_intel_atomic_state(state);
struct drm_i915_private *dev_priv = to_i915(dev);
struct drm_crtc_state *old_crtc_state;
struct drm_crtc *crtc;
struct intel_crtc_state *intel_cstate;
bool hw_check = intel_state->modeset;
unsigned long put_domains[I915_MAX_PIPES] = {};
unsigned crtc_vblank_mask = 0;
int i;
drm_atomic_helper_wait_for_dependencies(state);
if (intel_state->modeset)
intel_display_power_get(dev_priv, POWER_DOMAIN_MODESET);
for_each_crtc_in_state(state, crtc, old_crtc_state, i) {
struct intel_crtc *intel_crtc = to_intel_crtc(crtc);
if (needs_modeset(crtc->state) ||
to_intel_crtc_state(crtc->state)->update_pipe) {
hw_check = true;
put_domains[to_intel_crtc(crtc)->pipe] =
modeset_get_crtc_power_domains(crtc,
to_intel_crtc_state(crtc->state));
}
if (!needs_modeset(crtc->state))
continue;
intel_pre_plane_update(to_intel_crtc_state(old_crtc_state));
if (old_crtc_state->active) {
intel_crtc_disable_planes(crtc, old_crtc_state->plane_mask);
dev_priv->display.crtc_disable(to_intel_crtc_state(old_crtc_state), state);
intel_crtc->active = false;
intel_fbc_disable(intel_crtc);
intel_disable_shared_dpll(intel_crtc);
intel_check_cpu_fifo_underruns(dev_priv);
intel_check_pch_fifo_underruns(dev_priv);
if (!crtc->state->active) {
if (dev_priv->display.atomic_update_watermarks)
dev_priv->display.initial_watermarks(intel_state,
to_intel_crtc_state(crtc->state));
else
intel_update_watermarks(intel_crtc);
}
}
}
intel_modeset_update_crtc_state(state);
if (intel_state->modeset) {
drm_atomic_helper_update_legacy_modeset_state(state->dev, state);
if (dev_priv->display.modeset_commit_cdclk &&
(intel_state->dev_cdclk != dev_priv->cdclk_freq ||
intel_state->cdclk_pll_vco != dev_priv->cdclk_pll.vco))
dev_priv->display.modeset_commit_cdclk(state);
if (!intel_can_enable_sagv(state))
intel_disable_sagv(dev_priv);
intel_modeset_verify_disabled(dev, state);
}
for_each_crtc_in_state(state, crtc, old_crtc_state, i) {
bool modeset = needs_modeset(crtc->state);
if (modeset && !crtc->state->active && crtc->state->event) {
spin_lock_irq(&dev->event_lock);
drm_crtc_send_vblank_event(crtc, crtc->state->event);
spin_unlock_irq(&dev->event_lock);
crtc->state->event = NULL;
}
}
dev_priv->display.update_crtcs(state, &crtc_vblank_mask);
if (!state->legacy_cursor_update)
intel_atomic_wait_for_vblanks(dev, dev_priv, crtc_vblank_mask);
for_each_crtc_in_state(state, crtc, old_crtc_state, i) {
intel_cstate = to_intel_crtc_state(crtc->state);
if (dev_priv->display.optimize_watermarks)
dev_priv->display.optimize_watermarks(intel_state,
intel_cstate);
}
for_each_crtc_in_state(state, crtc, old_crtc_state, i) {
intel_post_plane_update(to_intel_crtc_state(old_crtc_state));
if (put_domains[i])
modeset_put_power_domains(dev_priv, put_domains[i]);
intel_modeset_verify_crtc(crtc, state, old_crtc_state, crtc->state);
}
if (intel_state->modeset && intel_can_enable_sagv(state))
intel_enable_sagv(dev_priv);
drm_atomic_helper_commit_hw_done(state);
if (intel_state->modeset)
intel_display_power_put(dev_priv, POWER_DOMAIN_MODESET);
mutex_lock(&dev->struct_mutex);
drm_atomic_helper_cleanup_planes(dev, state);
mutex_unlock(&dev->struct_mutex);
drm_atomic_helper_commit_cleanup_done(state);
drm_atomic_state_put(state);
intel_uncore_arm_unclaimed_mmio_detection(dev_priv);
}
static void intel_atomic_commit_work(struct work_struct *work)
{
struct drm_atomic_state *state =
container_of(work, struct drm_atomic_state, commit_work);
intel_atomic_commit_tail(state);
}
static int __i915_sw_fence_call
intel_atomic_commit_ready(struct i915_sw_fence *fence,
enum i915_sw_fence_notify notify)
{
struct intel_atomic_state *state =
container_of(fence, struct intel_atomic_state, commit_ready);
switch (notify) {
case FENCE_COMPLETE:
if (state->base.commit_work.func)
queue_work(system_unbound_wq, &state->base.commit_work);
break;
case FENCE_FREE:
{
struct intel_atomic_helper *helper =
&to_i915(state->base.dev)->atomic_helper;
if (llist_add(&state->freed, &helper->free_list))
schedule_work(&helper->free_work);
break;
}
}
return NOTIFY_DONE;
}
static void intel_atomic_track_fbs(struct drm_atomic_state *state)
{
struct drm_plane_state *old_plane_state;
struct drm_plane *plane;
int i;
for_each_plane_in_state(state, plane, old_plane_state, i)
i915_gem_track_fb(intel_fb_obj(old_plane_state->fb),
intel_fb_obj(plane->state->fb),
to_intel_plane(plane)->frontbuffer_bit);
}
static int intel_atomic_commit(struct drm_device *dev,
struct drm_atomic_state *state,
bool nonblock)
{
struct intel_atomic_state *intel_state = to_intel_atomic_state(state);
struct drm_i915_private *dev_priv = to_i915(dev);
int ret = 0;
ret = drm_atomic_helper_setup_commit(state, nonblock);
if (ret)
return ret;
drm_atomic_state_get(state);
i915_sw_fence_init(&intel_state->commit_ready,
intel_atomic_commit_ready);
ret = intel_atomic_prepare_commit(dev, state);
if (ret) {
DRM_DEBUG_ATOMIC("Preparing state failed with %i\n", ret);
i915_sw_fence_commit(&intel_state->commit_ready);
return ret;
}
drm_atomic_helper_swap_state(state, true);
dev_priv->wm.distrust_bios_wm = false;
intel_shared_dpll_commit(state);
intel_atomic_track_fbs(state);
if (intel_state->modeset) {
memcpy(dev_priv->min_pixclk, intel_state->min_pixclk,
sizeof(intel_state->min_pixclk));
dev_priv->active_crtcs = intel_state->active_crtcs;
dev_priv->atomic_cdclk_freq = intel_state->cdclk;
}
drm_atomic_state_get(state);
INIT_WORK(&state->commit_work,
nonblock ? intel_atomic_commit_work : NULL);
i915_sw_fence_commit(&intel_state->commit_ready);
if (!nonblock) {
i915_sw_fence_wait(&intel_state->commit_ready);
intel_atomic_commit_tail(state);
}
return 0;
}
void intel_crtc_restore_mode(struct drm_crtc *crtc)
{
struct drm_device *dev = crtc->dev;
struct drm_atomic_state *state;
struct drm_crtc_state *crtc_state;
int ret;
state = drm_atomic_state_alloc(dev);
if (!state) {
DRM_DEBUG_KMS("[CRTC:%d:%s] crtc restore failed, out of memory",
crtc->base.id, crtc->name);
return;
}
state->acquire_ctx = drm_modeset_legacy_acquire_ctx(crtc);
retry:
crtc_state = drm_atomic_get_crtc_state(state, crtc);
ret = PTR_ERR_OR_ZERO(crtc_state);
if (!ret) {
if (!crtc_state->active)
goto out;
crtc_state->mode_changed = true;
ret = drm_atomic_commit(state);
}
if (ret == -EDEADLK) {
drm_atomic_state_clear(state);
drm_modeset_backoff(state->acquire_ctx);
goto retry;
}
out:
drm_atomic_state_put(state);
}
static int intel_atomic_legacy_gamma_set(struct drm_crtc *crtc,
u16 *red, u16 *green, u16 *blue,
uint32_t size)
{
struct drm_device *dev = crtc->dev;
struct drm_mode_config *config = &dev->mode_config;
struct drm_crtc_state *state;
int ret;
ret = drm_atomic_helper_legacy_gamma_set(crtc, red, green, blue, size);
if (ret)
return ret;
state = crtc->state;
drm_object_property_set_value(&crtc->base,
config->degamma_lut_property,
(state->degamma_lut) ?
state->degamma_lut->base.id : 0);
drm_object_property_set_value(&crtc->base,
config->ctm_property,
(state->ctm) ?
state->ctm->base.id : 0);
drm_object_property_set_value(&crtc->base,
config->gamma_lut_property,
(state->gamma_lut) ?
state->gamma_lut->base.id : 0);
return 0;
}
int
intel_prepare_plane_fb(struct drm_plane *plane,
struct drm_plane_state *new_state)
{
struct intel_atomic_state *intel_state =
to_intel_atomic_state(new_state->state);
struct drm_i915_private *dev_priv = to_i915(plane->dev);
struct drm_framebuffer *fb = new_state->fb;
struct drm_i915_gem_object *obj = intel_fb_obj(fb);
struct drm_i915_gem_object *old_obj = intel_fb_obj(plane->state->fb);
int ret;
if (!obj && !old_obj)
return 0;
if (old_obj) {
struct drm_crtc_state *crtc_state =
drm_atomic_get_existing_crtc_state(new_state->state,
plane->state->crtc);
if (needs_modeset(crtc_state)) {
ret = i915_sw_fence_await_reservation(&intel_state->commit_ready,
old_obj->resv, NULL,
false, 0,
GFP_KERNEL);
if (ret < 0)
return ret;
}
}
if (new_state->fence) {
ret = i915_sw_fence_await_dma_fence(&intel_state->commit_ready,
new_state->fence,
I915_FENCE_TIMEOUT,
GFP_KERNEL);
if (ret < 0)
return ret;
}
if (!obj)
return 0;
if (!new_state->fence) {
ret = i915_sw_fence_await_reservation(&intel_state->commit_ready,
obj->resv, NULL,
false, I915_FENCE_TIMEOUT,
GFP_KERNEL);
if (ret < 0)
return ret;
i915_gem_object_wait_priority(obj, 0, I915_PRIORITY_DISPLAY);
}
if (plane->type == DRM_PLANE_TYPE_CURSOR &&
INTEL_INFO(dev_priv)->cursor_needs_physical) {
int align = IS_I830(dev_priv) ? 16 * 1024 : 256;
ret = i915_gem_object_attach_phys(obj, align);
if (ret) {
DRM_DEBUG_KMS("failed to attach phys object\n");
return ret;
}
} else {
struct i915_vma *vma;
vma = intel_pin_and_fence_fb_obj(fb, new_state->rotation);
if (IS_ERR(vma)) {
DRM_DEBUG_KMS("failed to pin object\n");
return PTR_ERR(vma);
}
to_intel_plane_state(new_state)->vma = vma;
}
return 0;
}
void
intel_cleanup_plane_fb(struct drm_plane *plane,
struct drm_plane_state *old_state)
{
struct i915_vma *vma;
vma = fetch_and_zero(&to_intel_plane_state(old_state)->vma);
if (vma)
intel_unpin_fb_vma(vma);
}
int
skl_max_scale(struct intel_crtc *intel_crtc, struct intel_crtc_state *crtc_state)
{
int max_scale;
int crtc_clock, cdclk;
if (!intel_crtc || !crtc_state->base.enable)
return DRM_PLANE_HELPER_NO_SCALING;
crtc_clock = crtc_state->base.adjusted_mode.crtc_clock;
cdclk = to_intel_atomic_state(crtc_state->base.state)->cdclk;
if (WARN_ON_ONCE(!crtc_clock || cdclk < crtc_clock))
return DRM_PLANE_HELPER_NO_SCALING;
max_scale = min((1 << 16) * 3 - 1, (1 << 8) * ((cdclk << 8) / crtc_clock));
return max_scale;
}
static int
intel_check_primary_plane(struct drm_plane *plane,
struct intel_crtc_state *crtc_state,
struct intel_plane_state *state)
{
struct drm_i915_private *dev_priv = to_i915(plane->dev);
struct drm_crtc *crtc = state->base.crtc;
int min_scale = DRM_PLANE_HELPER_NO_SCALING;
int max_scale = DRM_PLANE_HELPER_NO_SCALING;
bool can_position = false;
int ret;
if (INTEL_GEN(dev_priv) >= 9) {
if (state->ckey.flags == I915_SET_COLORKEY_NONE) {
min_scale = 1;
max_scale = skl_max_scale(to_intel_crtc(crtc), crtc_state);
}
can_position = true;
}
ret = drm_plane_helper_check_state(&state->base,
&state->clip,
min_scale, max_scale,
can_position, true);
if (ret)
return ret;
if (!state->base.fb)
return 0;
if (INTEL_GEN(dev_priv) >= 9) {
ret = skl_check_plane_surface(state);
if (ret)
return ret;
}
return 0;
}
static void intel_begin_crtc_commit(struct drm_crtc *crtc,
struct drm_crtc_state *old_crtc_state)
{
struct drm_device *dev = crtc->dev;
struct drm_i915_private *dev_priv = to_i915(dev);
struct intel_crtc *intel_crtc = to_intel_crtc(crtc);
struct intel_crtc_state *intel_cstate =
to_intel_crtc_state(crtc->state);
struct intel_crtc_state *old_intel_cstate =
to_intel_crtc_state(old_crtc_state);
struct intel_atomic_state *old_intel_state =
to_intel_atomic_state(old_crtc_state->state);
bool modeset = needs_modeset(crtc->state);
intel_pipe_update_start(intel_crtc);
if (modeset)
goto out;
if (crtc->state->color_mgmt_changed || to_intel_crtc_state(crtc->state)->update_pipe) {
intel_color_set_csc(crtc->state);
intel_color_load_luts(crtc->state);
}
if (intel_cstate->update_pipe)
intel_update_pipe_config(intel_crtc, old_intel_cstate);
else if (INTEL_GEN(dev_priv) >= 9)
skl_detach_scalers(intel_crtc);
out:
if (dev_priv->display.atomic_update_watermarks)
dev_priv->display.atomic_update_watermarks(old_intel_state,
intel_cstate);
}
static void intel_finish_crtc_commit(struct drm_crtc *crtc,
struct drm_crtc_state *old_crtc_state)
{
struct intel_crtc *intel_crtc = to_intel_crtc(crtc);
intel_pipe_update_end(intel_crtc, NULL);
}
void intel_plane_destroy(struct drm_plane *plane)
{
drm_plane_cleanup(plane);
kfree(to_intel_plane(plane));
}
static struct intel_plane *
intel_primary_plane_create(struct drm_i915_private *dev_priv, enum pipe pipe)
{
struct intel_plane *primary = NULL;
struct intel_plane_state *state = NULL;
const uint32_t *intel_primary_formats;
unsigned int supported_rotations;
unsigned int num_formats;
int ret;
primary = kzalloc(sizeof(*primary), GFP_KERNEL);
if (!primary) {
ret = -ENOMEM;
goto fail;
}
state = intel_create_plane_state(&primary->base);
if (!state) {
ret = -ENOMEM;
goto fail;
}
primary->base.state = &state->base;
primary->can_scale = false;
primary->max_downscale = 1;
if (INTEL_GEN(dev_priv) >= 9) {
primary->can_scale = true;
state->scaler_id = -1;
}
primary->pipe = pipe;
if (HAS_FBC(dev_priv) && INTEL_GEN(dev_priv) < 4)
primary->plane = (enum plane) !pipe;
else
primary->plane = (enum plane) pipe;
primary->frontbuffer_bit = INTEL_FRONTBUFFER_PRIMARY(pipe);
primary->check_plane = intel_check_primary_plane;
if (INTEL_GEN(dev_priv) >= 9) {
intel_primary_formats = skl_primary_formats;
num_formats = ARRAY_SIZE(skl_primary_formats);
primary->update_plane = skylake_update_primary_plane;
primary->disable_plane = skylake_disable_primary_plane;
} else if (HAS_PCH_SPLIT(dev_priv)) {
intel_primary_formats = i965_primary_formats;
num_formats = ARRAY_SIZE(i965_primary_formats);
primary->update_plane = ironlake_update_primary_plane;
primary->disable_plane = i9xx_disable_primary_plane;
} else if (INTEL_GEN(dev_priv) >= 4) {
intel_primary_formats = i965_primary_formats;
num_formats = ARRAY_SIZE(i965_primary_formats);
primary->update_plane = i9xx_update_primary_plane;
primary->disable_plane = i9xx_disable_primary_plane;
} else {
intel_primary_formats = i8xx_primary_formats;
num_formats = ARRAY_SIZE(i8xx_primary_formats);
primary->update_plane = i9xx_update_primary_plane;
primary->disable_plane = i9xx_disable_primary_plane;
}
if (INTEL_GEN(dev_priv) >= 9)
ret = drm_universal_plane_init(&dev_priv->drm, &primary->base,
0, &intel_plane_funcs,
intel_primary_formats, num_formats,
DRM_PLANE_TYPE_PRIMARY,
"plane 1%c", pipe_name(pipe));
else if (INTEL_GEN(dev_priv) >= 5 || IS_G4X(dev_priv))
ret = drm_universal_plane_init(&dev_priv->drm, &primary->base,
0, &intel_plane_funcs,
intel_primary_formats, num_formats,
DRM_PLANE_TYPE_PRIMARY,
"primary %c", pipe_name(pipe));
else
ret = drm_universal_plane_init(&dev_priv->drm, &primary->base,
0, &intel_plane_funcs,
intel_primary_formats, num_formats,
DRM_PLANE_TYPE_PRIMARY,
"plane %c", plane_name(primary->plane));
if (ret)
goto fail;
if (INTEL_GEN(dev_priv) >= 9) {
supported_rotations =
DRM_ROTATE_0 | DRM_ROTATE_90 |
DRM_ROTATE_180 | DRM_ROTATE_270;
} else if (IS_CHERRYVIEW(dev_priv) && pipe == PIPE_B) {
supported_rotations =
DRM_ROTATE_0 | DRM_ROTATE_180 |
DRM_REFLECT_X;
} else if (INTEL_GEN(dev_priv) >= 4) {
supported_rotations =
DRM_ROTATE_0 | DRM_ROTATE_180;
} else {
supported_rotations = DRM_ROTATE_0;
}
if (INTEL_GEN(dev_priv) >= 4)
drm_plane_create_rotation_property(&primary->base,
DRM_ROTATE_0,
supported_rotations);
drm_plane_helper_add(&primary->base, &intel_plane_helper_funcs);
return primary;
fail:
kfree(state);
kfree(primary);
return ERR_PTR(ret);
}
static int
intel_check_cursor_plane(struct drm_plane *plane,
struct intel_crtc_state *crtc_state,
struct intel_plane_state *state)
{
struct drm_framebuffer *fb = state->base.fb;
struct drm_i915_gem_object *obj = intel_fb_obj(fb);
enum pipe pipe = to_intel_plane(plane)->pipe;
unsigned stride;
int ret;
ret = drm_plane_helper_check_state(&state->base,
&state->clip,
DRM_PLANE_HELPER_NO_SCALING,
DRM_PLANE_HELPER_NO_SCALING,
true, true);
if (ret)
return ret;
if (!obj)
return 0;
if (!cursor_size_ok(to_i915(plane->dev), state->base.crtc_w,
state->base.crtc_h)) {
DRM_DEBUG("Cursor dimension %dx%d not supported\n",
state->base.crtc_w, state->base.crtc_h);
return -EINVAL;
}
stride = roundup_pow_of_two(state->base.crtc_w) * 4;
if (obj->base.size < stride * state->base.crtc_h) {
DRM_DEBUG_KMS("buffer is too small\n");
return -ENOMEM;
}
if (fb->modifier != DRM_FORMAT_MOD_NONE) {
DRM_DEBUG_KMS("cursor cannot be tiled\n");
return -EINVAL;
}
if (IS_CHERRYVIEW(to_i915(plane->dev)) && pipe == PIPE_C &&
state->base.visible && state->base.crtc_x < 0) {
DRM_DEBUG_KMS("CHV cursor C not allowed to straddle the left screen edge\n");
return -EINVAL;
}
return 0;
}
static void
intel_disable_cursor_plane(struct drm_plane *plane,
struct drm_crtc *crtc)
{
struct intel_crtc *intel_crtc = to_intel_crtc(crtc);
intel_crtc->cursor_addr = 0;
intel_crtc_update_cursor(crtc, NULL);
}
static void
intel_update_cursor_plane(struct drm_plane *plane,
const struct intel_crtc_state *crtc_state,
const struct intel_plane_state *state)
{
struct drm_crtc *crtc = crtc_state->base.crtc;
struct intel_crtc *intel_crtc = to_intel_crtc(crtc);
struct drm_i915_private *dev_priv = to_i915(plane->dev);
struct drm_i915_gem_object *obj = intel_fb_obj(state->base.fb);
uint32_t addr;
if (!obj)
addr = 0;
else if (!INTEL_INFO(dev_priv)->cursor_needs_physical)
addr = intel_plane_ggtt_offset(state);
else
addr = obj->phys_handle->busaddr;
intel_crtc->cursor_addr = addr;
intel_crtc_update_cursor(crtc, state);
}
static struct intel_plane *
intel_cursor_plane_create(struct drm_i915_private *dev_priv, enum pipe pipe)
{
struct intel_plane *cursor = NULL;
struct intel_plane_state *state = NULL;
int ret;
cursor = kzalloc(sizeof(*cursor), GFP_KERNEL);
if (!cursor) {
ret = -ENOMEM;
goto fail;
}
state = intel_create_plane_state(&cursor->base);
if (!state) {
ret = -ENOMEM;
goto fail;
}
cursor->base.state = &state->base;
cursor->can_scale = false;
cursor->max_downscale = 1;
cursor->pipe = pipe;
cursor->plane = pipe;
cursor->frontbuffer_bit = INTEL_FRONTBUFFER_CURSOR(pipe);
cursor->check_plane = intel_check_cursor_plane;
cursor->update_plane = intel_update_cursor_plane;
cursor->disable_plane = intel_disable_cursor_plane;
ret = drm_universal_plane_init(&dev_priv->drm, &cursor->base,
0, &intel_plane_funcs,
intel_cursor_formats,
ARRAY_SIZE(intel_cursor_formats),
DRM_PLANE_TYPE_CURSOR,
"cursor %c", pipe_name(pipe));
if (ret)
goto fail;
if (INTEL_GEN(dev_priv) >= 4)
drm_plane_create_rotation_property(&cursor->base,
DRM_ROTATE_0,
DRM_ROTATE_0 |
DRM_ROTATE_180);
if (INTEL_GEN(dev_priv) >= 9)
state->scaler_id = -1;
drm_plane_helper_add(&cursor->base, &intel_plane_helper_funcs);
return cursor;
fail:
kfree(state);
kfree(cursor);
return ERR_PTR(ret);
}
static void skl_init_scalers(struct drm_i915_private *dev_priv,
struct intel_crtc *crtc,
struct intel_crtc_state *crtc_state)
{
struct intel_crtc_scaler_state *scaler_state =
&crtc_state->scaler_state;
int i;
for (i = 0; i < crtc->num_scalers; i++) {
struct intel_scaler *scaler = &scaler_state->scalers[i];
scaler->in_use = 0;
scaler->mode = PS_SCALER_MODE_DYN;
}
scaler_state->scaler_id = -1;
}
static int intel_crtc_init(struct drm_i915_private *dev_priv, enum pipe pipe)
{
struct intel_crtc *intel_crtc;
struct intel_crtc_state *crtc_state = NULL;
struct intel_plane *primary = NULL;
struct intel_plane *cursor = NULL;
int sprite, ret;
intel_crtc = kzalloc(sizeof(*intel_crtc), GFP_KERNEL);
if (!intel_crtc)
return -ENOMEM;
crtc_state = kzalloc(sizeof(*crtc_state), GFP_KERNEL);
if (!crtc_state) {
ret = -ENOMEM;
goto fail;
}
intel_crtc->config = crtc_state;
intel_crtc->base.state = &crtc_state->base;
crtc_state->base.crtc = &intel_crtc->base;
if (INTEL_GEN(dev_priv) >= 9) {
if (pipe == PIPE_C)
intel_crtc->num_scalers = 1;
else
intel_crtc->num_scalers = SKL_NUM_SCALERS;
skl_init_scalers(dev_priv, intel_crtc, crtc_state);
}
primary = intel_primary_plane_create(dev_priv, pipe);
if (IS_ERR(primary)) {
ret = PTR_ERR(primary);
goto fail;
}
for_each_sprite(dev_priv, pipe, sprite) {
struct intel_plane *plane;
plane = intel_sprite_plane_create(dev_priv, pipe, sprite);
if (IS_ERR(plane)) {
ret = PTR_ERR(plane);
goto fail;
}
}
cursor = intel_cursor_plane_create(dev_priv, pipe);
if (IS_ERR(cursor)) {
ret = PTR_ERR(cursor);
goto fail;
}
ret = drm_crtc_init_with_planes(&dev_priv->drm, &intel_crtc->base,
&primary->base, &cursor->base,
&intel_crtc_funcs,
"pipe %c", pipe_name(pipe));
if (ret)
goto fail;
intel_crtc->pipe = pipe;
intel_crtc->plane = primary->plane;
intel_crtc->cursor_base = ~0;
intel_crtc->cursor_cntl = ~0;
intel_crtc->cursor_size = ~0;
intel_crtc->wm.cxsr_allowed = true;
BUG_ON(pipe >= ARRAY_SIZE(dev_priv->plane_to_crtc_mapping) ||
dev_priv->plane_to_crtc_mapping[intel_crtc->plane] != NULL);
dev_priv->plane_to_crtc_mapping[intel_crtc->plane] = intel_crtc;
dev_priv->pipe_to_crtc_mapping[intel_crtc->pipe] = intel_crtc;
drm_crtc_helper_add(&intel_crtc->base, &intel_helper_funcs);
intel_color_init(&intel_crtc->base);
WARN_ON(drm_crtc_index(&intel_crtc->base) != intel_crtc->pipe);
return 0;
fail:
kfree(crtc_state);
kfree(intel_crtc);
return ret;
}
enum pipe intel_get_pipe_from_connector(struct intel_connector *connector)
{
struct drm_encoder *encoder = connector->base.encoder;
struct drm_device *dev = connector->base.dev;
WARN_ON(!drm_modeset_is_locked(&dev->mode_config.connection_mutex));
if (!encoder || WARN_ON(!encoder->crtc))
return INVALID_PIPE;
return to_intel_crtc(encoder->crtc)->pipe;
}
int intel_get_pipe_from_crtc_id(struct drm_device *dev, void *data,
struct drm_file *file)
{
struct drm_i915_get_pipe_from_crtc_id *pipe_from_crtc_id = data;
struct drm_crtc *drmmode_crtc;
struct intel_crtc *crtc;
drmmode_crtc = drm_crtc_find(dev, pipe_from_crtc_id->crtc_id);
if (!drmmode_crtc)
return -ENOENT;
crtc = to_intel_crtc(drmmode_crtc);
pipe_from_crtc_id->pipe = crtc->pipe;
return 0;
}
static int intel_encoder_clones(struct intel_encoder *encoder)
{
struct drm_device *dev = encoder->base.dev;
struct intel_encoder *source_encoder;
int index_mask = 0;
int entry = 0;
for_each_intel_encoder(dev, source_encoder) {
if (encoders_cloneable(encoder, source_encoder))
index_mask |= (1 << entry);
entry++;
}
return index_mask;
}
static bool has_edp_a(struct drm_i915_private *dev_priv)
{
if (!IS_MOBILE(dev_priv))
return false;
if ((I915_READ(DP_A) & DP_DETECTED) == 0)
return false;
if (IS_GEN5(dev_priv) && (I915_READ(FUSE_STRAP) & ILK_eDP_A_DISABLE))
return false;
return true;
}
static bool intel_crt_present(struct drm_i915_private *dev_priv)
{
if (INTEL_GEN(dev_priv) >= 9)
return false;
if (IS_HSW_ULT(dev_priv) || IS_BDW_ULT(dev_priv))
return false;
if (IS_CHERRYVIEW(dev_priv))
return false;
if (HAS_PCH_LPT_H(dev_priv) &&
I915_READ(SFUSE_STRAP) & SFUSE_STRAP_CRT_DISABLED)
return false;
if (HAS_DDI(dev_priv) && I915_READ(DDI_BUF_CTL(PORT_A)) & DDI_A_4_LANES)
return false;
if (!dev_priv->vbt.int_crt_support)
return false;
return true;
}
void intel_pps_unlock_regs_wa(struct drm_i915_private *dev_priv)
{
int pps_num;
int pps_idx;
if (HAS_DDI(dev_priv))
return;
if (IS_VALLEYVIEW(dev_priv) || IS_CHERRYVIEW(dev_priv))
pps_num = 2;
else
pps_num = 1;
for (pps_idx = 0; pps_idx < pps_num; pps_idx++) {
u32 val = I915_READ(PP_CONTROL(pps_idx));
val = (val & ~PANEL_UNLOCK_MASK) | PANEL_UNLOCK_REGS;
I915_WRITE(PP_CONTROL(pps_idx), val);
}
}
static void intel_pps_init(struct drm_i915_private *dev_priv)
{
if (HAS_PCH_SPLIT(dev_priv) || IS_BROXTON(dev_priv))
dev_priv->pps_mmio_base = PCH_PPS_BASE;
else if (IS_VALLEYVIEW(dev_priv) || IS_CHERRYVIEW(dev_priv))
dev_priv->pps_mmio_base = VLV_PPS_BASE;
else
dev_priv->pps_mmio_base = PPS_BASE;
intel_pps_unlock_regs_wa(dev_priv);
}
static void intel_setup_outputs(struct drm_device *dev)
{
struct drm_i915_private *dev_priv = to_i915(dev);
struct intel_encoder *encoder;
bool dpd_is_edp = false;
intel_pps_init(dev_priv);
intel_lvds_init(dev);
if (intel_crt_present(dev_priv))
intel_crt_init(dev);
if (IS_BROXTON(dev_priv)) {
intel_ddi_init(dev, PORT_A);
intel_ddi_init(dev, PORT_B);
intel_ddi_init(dev, PORT_C);
intel_dsi_init(dev);
} else if (HAS_DDI(dev_priv)) {
int found;
found = I915_READ(DDI_BUF_CTL(PORT_A)) & DDI_INIT_DISPLAY_DETECTED;
if (found || IS_SKYLAKE(dev_priv) || IS_KABYLAKE(dev_priv))
intel_ddi_init(dev, PORT_A);
found = I915_READ(SFUSE_STRAP);
if (found & SFUSE_STRAP_DDIB_DETECTED)
intel_ddi_init(dev, PORT_B);
if (found & SFUSE_STRAP_DDIC_DETECTED)
intel_ddi_init(dev, PORT_C);
if (found & SFUSE_STRAP_DDID_DETECTED)
intel_ddi_init(dev, PORT_D);
if ((IS_SKYLAKE(dev_priv) || IS_KABYLAKE(dev_priv)) &&
(dev_priv->vbt.ddi_port_info[PORT_E].supports_dp ||
dev_priv->vbt.ddi_port_info[PORT_E].supports_dvi ||
dev_priv->vbt.ddi_port_info[PORT_E].supports_hdmi))
intel_ddi_init(dev, PORT_E);
} else if (HAS_PCH_SPLIT(dev_priv)) {
int found;
dpd_is_edp = intel_dp_is_edp(dev_priv, PORT_D);
if (has_edp_a(dev_priv))
intel_dp_init(dev, DP_A, PORT_A);
if (I915_READ(PCH_HDMIB) & SDVO_DETECTED) {
found = intel_sdvo_init(dev, PCH_SDVOB, PORT_B);
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
} else if (IS_VALLEYVIEW(dev_priv) || IS_CHERRYVIEW(dev_priv)) {
bool has_edp, has_port;
has_edp = intel_dp_is_edp(dev_priv, PORT_B);
has_port = intel_bios_is_port_present(dev_priv, PORT_B);
if (I915_READ(VLV_DP_B) & DP_DETECTED || has_port)
has_edp &= intel_dp_init(dev, VLV_DP_B, PORT_B);
if ((I915_READ(VLV_HDMIB) & SDVO_DETECTED || has_port) && !has_edp)
intel_hdmi_init(dev, VLV_HDMIB, PORT_B);
has_edp = intel_dp_is_edp(dev_priv, PORT_C);
has_port = intel_bios_is_port_present(dev_priv, PORT_C);
if (I915_READ(VLV_DP_C) & DP_DETECTED || has_port)
has_edp &= intel_dp_init(dev, VLV_DP_C, PORT_C);
if ((I915_READ(VLV_HDMIC) & SDVO_DETECTED || has_port) && !has_edp)
intel_hdmi_init(dev, VLV_HDMIC, PORT_C);
if (IS_CHERRYVIEW(dev_priv)) {
has_port = intel_bios_is_port_present(dev_priv, PORT_D);
if (I915_READ(CHV_DP_D) & DP_DETECTED || has_port)
intel_dp_init(dev, CHV_DP_D, PORT_D);
if (I915_READ(CHV_HDMID) & SDVO_DETECTED || has_port)
intel_hdmi_init(dev, CHV_HDMID, PORT_D);
}
intel_dsi_init(dev);
} else if (!IS_GEN2(dev_priv) && !IS_PINEVIEW(dev_priv)) {
bool found = false;
if (I915_READ(GEN3_SDVOB) & SDVO_DETECTED) {
DRM_DEBUG_KMS("probing SDVOB\n");
found = intel_sdvo_init(dev, GEN3_SDVOB, PORT_B);
if (!found && IS_G4X(dev_priv)) {
DRM_DEBUG_KMS("probing HDMI on SDVOB\n");
intel_hdmi_init(dev, GEN4_HDMIB, PORT_B);
}
if (!found && IS_G4X(dev_priv))
intel_dp_init(dev, DP_B, PORT_B);
}
if (I915_READ(GEN3_SDVOB) & SDVO_DETECTED) {
DRM_DEBUG_KMS("probing SDVOC\n");
found = intel_sdvo_init(dev, GEN3_SDVOC, PORT_C);
}
if (!found && (I915_READ(GEN3_SDVOC) & SDVO_DETECTED)) {
if (IS_G4X(dev_priv)) {
DRM_DEBUG_KMS("probing HDMI on SDVOC\n");
intel_hdmi_init(dev, GEN4_HDMIC, PORT_C);
}
if (IS_G4X(dev_priv))
intel_dp_init(dev, DP_C, PORT_C);
}
if (IS_G4X(dev_priv) && (I915_READ(DP_D) & DP_DETECTED))
intel_dp_init(dev, DP_D, PORT_D);
} else if (IS_GEN2(dev_priv))
intel_dvo_init(dev);
if (SUPPORTS_TV(dev_priv))
intel_tv_init(dev);
intel_psr_init(dev);
for_each_intel_encoder(dev, encoder) {
encoder->base.possible_crtcs = encoder->crtc_mask;
encoder->base.possible_clones =
intel_encoder_clones(encoder);
}
intel_init_pch_refclk(dev);
drm_helper_move_panel_connectors_to_head(dev);
}
static void intel_user_framebuffer_destroy(struct drm_framebuffer *fb)
{
struct drm_device *dev = fb->dev;
struct intel_framebuffer *intel_fb = to_intel_framebuffer(fb);
drm_framebuffer_cleanup(fb);
mutex_lock(&dev->struct_mutex);
WARN_ON(!intel_fb->obj->framebuffer_references--);
i915_gem_object_put(intel_fb->obj);
mutex_unlock(&dev->struct_mutex);
kfree(intel_fb);
}
static int intel_user_framebuffer_create_handle(struct drm_framebuffer *fb,
struct drm_file *file,
unsigned int *handle)
{
struct intel_framebuffer *intel_fb = to_intel_framebuffer(fb);
struct drm_i915_gem_object *obj = intel_fb->obj;
if (obj->userptr.mm) {
DRM_DEBUG("attempting to use a userptr for a framebuffer, denied\n");
return -EINVAL;
}
return drm_gem_handle_create(file, &obj->base, handle);
}
static int intel_user_framebuffer_dirty(struct drm_framebuffer *fb,
struct drm_file *file,
unsigned flags, unsigned color,
struct drm_clip_rect *clips,
unsigned num_clips)
{
struct drm_device *dev = fb->dev;
struct intel_framebuffer *intel_fb = to_intel_framebuffer(fb);
struct drm_i915_gem_object *obj = intel_fb->obj;
mutex_lock(&dev->struct_mutex);
if (obj->pin_display && obj->cache_dirty)
i915_gem_clflush_object(obj, true);
intel_fb_obj_flush(obj, false, ORIGIN_DIRTYFB);
mutex_unlock(&dev->struct_mutex);
return 0;
}
static
u32 intel_fb_pitch_limit(struct drm_i915_private *dev_priv,
uint64_t fb_modifier, uint32_t pixel_format)
{
u32 gen = INTEL_INFO(dev_priv)->gen;
if (gen >= 9) {
int cpp = drm_format_plane_cpp(pixel_format, 0);
return min(8192 * cpp, 32768);
} else if (gen >= 5 && !IS_VALLEYVIEW(dev_priv) &&
!IS_CHERRYVIEW(dev_priv)) {
return 32*1024;
} else if (gen >= 4) {
if (fb_modifier == I915_FORMAT_MOD_X_TILED)
return 16*1024;
else
return 32*1024;
} else if (gen >= 3) {
if (fb_modifier == I915_FORMAT_MOD_X_TILED)
return 8*1024;
else
return 16*1024;
} else {
return 8*1024;
}
}
static int intel_framebuffer_init(struct drm_device *dev,
struct intel_framebuffer *intel_fb,
struct drm_mode_fb_cmd2 *mode_cmd,
struct drm_i915_gem_object *obj)
{
struct drm_i915_private *dev_priv = to_i915(dev);
unsigned int tiling = i915_gem_object_get_tiling(obj);
int ret;
u32 pitch_limit, stride_alignment;
struct drm_format_name_buf format_name;
WARN_ON(!mutex_is_locked(&dev->struct_mutex));
if (mode_cmd->flags & DRM_MODE_FB_MODIFIERS) {
if (tiling != I915_TILING_NONE &&
tiling != intel_fb_modifier_to_tiling(mode_cmd->modifier[0])) {
DRM_DEBUG("tiling_mode doesn't match fb modifier\n");
return -EINVAL;
}
} else {
if (tiling == I915_TILING_X) {
mode_cmd->modifier[0] = I915_FORMAT_MOD_X_TILED;
} else if (tiling == I915_TILING_Y) {
DRM_DEBUG("No Y tiling for legacy addfb\n");
return -EINVAL;
}
}
switch (mode_cmd->modifier[0]) {
case I915_FORMAT_MOD_Y_TILED:
case I915_FORMAT_MOD_Yf_TILED:
if (INTEL_GEN(dev_priv) < 9) {
DRM_DEBUG("Unsupported tiling 0x%llx!\n",
mode_cmd->modifier[0]);
return -EINVAL;
}
case DRM_FORMAT_MOD_NONE:
case I915_FORMAT_MOD_X_TILED:
break;
default:
DRM_DEBUG("Unsupported fb modifier 0x%llx!\n",
mode_cmd->modifier[0]);
return -EINVAL;
}
if (INTEL_INFO(dev_priv)->gen < 4 &&
tiling != intel_fb_modifier_to_tiling(mode_cmd->modifier[0])) {
DRM_DEBUG("tiling_mode must match fb modifier exactly on gen2/3\n");
return -EINVAL;
}
stride_alignment = intel_fb_stride_alignment(dev_priv,
mode_cmd->modifier[0],
mode_cmd->pixel_format);
if (mode_cmd->pitches[0] & (stride_alignment - 1)) {
DRM_DEBUG("pitch (%d) must be at least %u byte aligned\n",
mode_cmd->pitches[0], stride_alignment);
return -EINVAL;
}
pitch_limit = intel_fb_pitch_limit(dev_priv, mode_cmd->modifier[0],
mode_cmd->pixel_format);
if (mode_cmd->pitches[0] > pitch_limit) {
DRM_DEBUG("%s pitch (%u) must be at less than %d\n",
mode_cmd->modifier[0] != DRM_FORMAT_MOD_NONE ?
"tiled" : "linear",
mode_cmd->pitches[0], pitch_limit);
return -EINVAL;
}
if (tiling != I915_TILING_NONE &&
mode_cmd->pitches[0] != i915_gem_object_get_stride(obj)) {
DRM_DEBUG("pitch (%d) must match tiling stride (%d)\n",
mode_cmd->pitches[0],
i915_gem_object_get_stride(obj));
return -EINVAL;
}
switch (mode_cmd->pixel_format) {
case DRM_FORMAT_C8:
case DRM_FORMAT_RGB565:
case DRM_FORMAT_XRGB8888:
case DRM_FORMAT_ARGB8888:
break;
case DRM_FORMAT_XRGB1555:
if (INTEL_GEN(dev_priv) > 3) {
DRM_DEBUG("unsupported pixel format: %s\n",
drm_get_format_name(mode_cmd->pixel_format, &format_name));
return -EINVAL;
}
break;
case DRM_FORMAT_ABGR8888:
if (!IS_VALLEYVIEW(dev_priv) && !IS_CHERRYVIEW(dev_priv) &&
INTEL_GEN(dev_priv) < 9) {
DRM_DEBUG("unsupported pixel format: %s\n",
drm_get_format_name(mode_cmd->pixel_format, &format_name));
return -EINVAL;
}
break;
case DRM_FORMAT_XBGR8888:
case DRM_FORMAT_XRGB2101010:
case DRM_FORMAT_XBGR2101010:
if (INTEL_GEN(dev_priv) < 4) {
DRM_DEBUG("unsupported pixel format: %s\n",
drm_get_format_name(mode_cmd->pixel_format, &format_name));
return -EINVAL;
}
break;
case DRM_FORMAT_ABGR2101010:
if (!IS_VALLEYVIEW(dev_priv) && !IS_CHERRYVIEW(dev_priv)) {
DRM_DEBUG("unsupported pixel format: %s\n",
drm_get_format_name(mode_cmd->pixel_format, &format_name));
return -EINVAL;
}
break;
case DRM_FORMAT_YUYV:
case DRM_FORMAT_UYVY:
case DRM_FORMAT_YVYU:
case DRM_FORMAT_VYUY:
if (INTEL_GEN(dev_priv) < 5) {
DRM_DEBUG("unsupported pixel format: %s\n",
drm_get_format_name(mode_cmd->pixel_format, &format_name));
return -EINVAL;
}
break;
default:
DRM_DEBUG("unsupported pixel format: %s\n",
drm_get_format_name(mode_cmd->pixel_format, &format_name));
return -EINVAL;
}
if (mode_cmd->offsets[0] != 0)
return -EINVAL;
drm_helper_mode_fill_fb_struct(&intel_fb->base, mode_cmd);
intel_fb->obj = obj;
ret = intel_fill_fb_info(dev_priv, &intel_fb->base);
if (ret)
return ret;
ret = drm_framebuffer_init(dev, &intel_fb->base, &intel_fb_funcs);
if (ret) {
DRM_ERROR("framebuffer init failed %d\n", ret);
return ret;
}
intel_fb->obj->framebuffer_references++;
return 0;
}
static struct drm_framebuffer *
intel_user_framebuffer_create(struct drm_device *dev,
struct drm_file *filp,
const struct drm_mode_fb_cmd2 *user_mode_cmd)
{
struct drm_framebuffer *fb;
struct drm_i915_gem_object *obj;
struct drm_mode_fb_cmd2 mode_cmd = *user_mode_cmd;
obj = i915_gem_object_lookup(filp, mode_cmd.handles[0]);
if (!obj)
return ERR_PTR(-ENOENT);
fb = intel_framebuffer_create(dev, &mode_cmd, obj);
if (IS_ERR(fb))
i915_gem_object_put(obj);
return fb;
}
void intel_init_display_hooks(struct drm_i915_private *dev_priv)
{
if (INTEL_INFO(dev_priv)->gen >= 9) {
dev_priv->display.get_pipe_config = haswell_get_pipe_config;
dev_priv->display.get_initial_plane_config =
skylake_get_initial_plane_config;
dev_priv->display.crtc_compute_clock =
haswell_crtc_compute_clock;
dev_priv->display.crtc_enable = haswell_crtc_enable;
dev_priv->display.crtc_disable = haswell_crtc_disable;
} else if (HAS_DDI(dev_priv)) {
dev_priv->display.get_pipe_config = haswell_get_pipe_config;
dev_priv->display.get_initial_plane_config =
ironlake_get_initial_plane_config;
dev_priv->display.crtc_compute_clock =
haswell_crtc_compute_clock;
dev_priv->display.crtc_enable = haswell_crtc_enable;
dev_priv->display.crtc_disable = haswell_crtc_disable;
} else if (HAS_PCH_SPLIT(dev_priv)) {
dev_priv->display.get_pipe_config = ironlake_get_pipe_config;
dev_priv->display.get_initial_plane_config =
ironlake_get_initial_plane_config;
dev_priv->display.crtc_compute_clock =
ironlake_crtc_compute_clock;
dev_priv->display.crtc_enable = ironlake_crtc_enable;
dev_priv->display.crtc_disable = ironlake_crtc_disable;
} else if (IS_CHERRYVIEW(dev_priv)) {
dev_priv->display.get_pipe_config = i9xx_get_pipe_config;
dev_priv->display.get_initial_plane_config =
i9xx_get_initial_plane_config;
dev_priv->display.crtc_compute_clock = chv_crtc_compute_clock;
dev_priv->display.crtc_enable = valleyview_crtc_enable;
dev_priv->display.crtc_disable = i9xx_crtc_disable;
} else if (IS_VALLEYVIEW(dev_priv)) {
dev_priv->display.get_pipe_config = i9xx_get_pipe_config;
dev_priv->display.get_initial_plane_config =
i9xx_get_initial_plane_config;
dev_priv->display.crtc_compute_clock = vlv_crtc_compute_clock;
dev_priv->display.crtc_enable = valleyview_crtc_enable;
dev_priv->display.crtc_disable = i9xx_crtc_disable;
} else if (IS_G4X(dev_priv)) {
dev_priv->display.get_pipe_config = i9xx_get_pipe_config;
dev_priv->display.get_initial_plane_config =
i9xx_get_initial_plane_config;
dev_priv->display.crtc_compute_clock = g4x_crtc_compute_clock;
dev_priv->display.crtc_enable = i9xx_crtc_enable;
dev_priv->display.crtc_disable = i9xx_crtc_disable;
} else if (IS_PINEVIEW(dev_priv)) {
dev_priv->display.get_pipe_config = i9xx_get_pipe_config;
dev_priv->display.get_initial_plane_config =
i9xx_get_initial_plane_config;
dev_priv->display.crtc_compute_clock = pnv_crtc_compute_clock;
dev_priv->display.crtc_enable = i9xx_crtc_enable;
dev_priv->display.crtc_disable = i9xx_crtc_disable;
} else if (!IS_GEN2(dev_priv)) {
dev_priv->display.get_pipe_config = i9xx_get_pipe_config;
dev_priv->display.get_initial_plane_config =
i9xx_get_initial_plane_config;
dev_priv->display.crtc_compute_clock = i9xx_crtc_compute_clock;
dev_priv->display.crtc_enable = i9xx_crtc_enable;
dev_priv->display.crtc_disable = i9xx_crtc_disable;
} else {
dev_priv->display.get_pipe_config = i9xx_get_pipe_config;
dev_priv->display.get_initial_plane_config =
i9xx_get_initial_plane_config;
dev_priv->display.crtc_compute_clock = i8xx_crtc_compute_clock;
dev_priv->display.crtc_enable = i9xx_crtc_enable;
dev_priv->display.crtc_disable = i9xx_crtc_disable;
}
if (IS_SKYLAKE(dev_priv) || IS_KABYLAKE(dev_priv))
dev_priv->display.get_display_clock_speed =
skylake_get_display_clock_speed;
else if (IS_BROXTON(dev_priv))
dev_priv->display.get_display_clock_speed =
broxton_get_display_clock_speed;
else if (IS_BROADWELL(dev_priv))
dev_priv->display.get_display_clock_speed =
broadwell_get_display_clock_speed;
else if (IS_HASWELL(dev_priv))
dev_priv->display.get_display_clock_speed =
haswell_get_display_clock_speed;
else if (IS_VALLEYVIEW(dev_priv) || IS_CHERRYVIEW(dev_priv))
dev_priv->display.get_display_clock_speed =
valleyview_get_display_clock_speed;
else if (IS_GEN5(dev_priv))
dev_priv->display.get_display_clock_speed =
ilk_get_display_clock_speed;
else if (IS_I945G(dev_priv) || IS_BROADWATER(dev_priv) ||
IS_GEN6(dev_priv) || IS_IVYBRIDGE(dev_priv))
dev_priv->display.get_display_clock_speed =
i945_get_display_clock_speed;
else if (IS_GM45(dev_priv))
dev_priv->display.get_display_clock_speed =
gm45_get_display_clock_speed;
else if (IS_CRESTLINE(dev_priv))
dev_priv->display.get_display_clock_speed =
i965gm_get_display_clock_speed;
else if (IS_PINEVIEW(dev_priv))
dev_priv->display.get_display_clock_speed =
pnv_get_display_clock_speed;
else if (IS_G33(dev_priv) || IS_G4X(dev_priv))
dev_priv->display.get_display_clock_speed =
g33_get_display_clock_speed;
else if (IS_I915G(dev_priv))
dev_priv->display.get_display_clock_speed =
i915_get_display_clock_speed;
else if (IS_I945GM(dev_priv) || IS_845G(dev_priv))
dev_priv->display.get_display_clock_speed =
i9xx_misc_get_display_clock_speed;
else if (IS_I915GM(dev_priv))
dev_priv->display.get_display_clock_speed =
i915gm_get_display_clock_speed;
else if (IS_I865G(dev_priv))
dev_priv->display.get_display_clock_speed =
i865_get_display_clock_speed;
else if (IS_I85X(dev_priv))
dev_priv->display.get_display_clock_speed =
i85x_get_display_clock_speed;
else {
WARN(!IS_I830(dev_priv), "Unknown platform. Assuming 133 MHz CDCLK\n");
dev_priv->display.get_display_clock_speed =
i830_get_display_clock_speed;
}
if (IS_GEN5(dev_priv)) {
dev_priv->display.fdi_link_train = ironlake_fdi_link_train;
} else if (IS_GEN6(dev_priv)) {
dev_priv->display.fdi_link_train = gen6_fdi_link_train;
} else if (IS_IVYBRIDGE(dev_priv)) {
dev_priv->display.fdi_link_train = ivb_manual_fdi_link_train;
} else if (IS_HASWELL(dev_priv) || IS_BROADWELL(dev_priv)) {
dev_priv->display.fdi_link_train = hsw_fdi_link_train;
}
if (IS_BROADWELL(dev_priv)) {
dev_priv->display.modeset_commit_cdclk =
broadwell_modeset_commit_cdclk;
dev_priv->display.modeset_calc_cdclk =
broadwell_modeset_calc_cdclk;
} else if (IS_VALLEYVIEW(dev_priv) || IS_CHERRYVIEW(dev_priv)) {
dev_priv->display.modeset_commit_cdclk =
valleyview_modeset_commit_cdclk;
dev_priv->display.modeset_calc_cdclk =
valleyview_modeset_calc_cdclk;
} else if (IS_BROXTON(dev_priv)) {
dev_priv->display.modeset_commit_cdclk =
bxt_modeset_commit_cdclk;
dev_priv->display.modeset_calc_cdclk =
bxt_modeset_calc_cdclk;
} else if (IS_SKYLAKE(dev_priv) || IS_KABYLAKE(dev_priv)) {
dev_priv->display.modeset_commit_cdclk =
skl_modeset_commit_cdclk;
dev_priv->display.modeset_calc_cdclk =
skl_modeset_calc_cdclk;
}
if (dev_priv->info.gen >= 9)
dev_priv->display.update_crtcs = skl_update_crtcs;
else
dev_priv->display.update_crtcs = intel_update_crtcs;
switch (INTEL_INFO(dev_priv)->gen) {
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
case 9:
default:
dev_priv->display.queue_flip = intel_default_queue_flip;
}
}
static void quirk_pipea_force(struct drm_device *dev)
{
struct drm_i915_private *dev_priv = to_i915(dev);
dev_priv->quirks |= QUIRK_PIPEA_FORCE;
DRM_INFO("applying pipe a force quirk\n");
}
static void quirk_pipeb_force(struct drm_device *dev)
{
struct drm_i915_private *dev_priv = to_i915(dev);
dev_priv->quirks |= QUIRK_PIPEB_FORCE;
DRM_INFO("applying pipe b force quirk\n");
}
static void quirk_ssc_force_disable(struct drm_device *dev)
{
struct drm_i915_private *dev_priv = to_i915(dev);
dev_priv->quirks |= QUIRK_LVDS_SSC_DISABLE;
DRM_INFO("applying lvds SSC disable quirk\n");
}
static void quirk_invert_brightness(struct drm_device *dev)
{
struct drm_i915_private *dev_priv = to_i915(dev);
dev_priv->quirks |= QUIRK_INVERT_BRIGHTNESS;
DRM_INFO("applying inverted panel brightness quirk\n");
}
static void quirk_backlight_present(struct drm_device *dev)
{
struct drm_i915_private *dev_priv = to_i915(dev);
dev_priv->quirks |= QUIRK_BACKLIGHT_PRESENT;
DRM_INFO("applying backlight present quirk\n");
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
static void i915_disable_vga(struct drm_i915_private *dev_priv)
{
struct pci_dev *pdev = dev_priv->drm.pdev;
u8 sr1;
i915_reg_t vga_reg = i915_vgacntrl_reg(dev_priv);
vga_get_uninterruptible(pdev, VGA_RSRC_LEGACY_IO);
outb(SR01, VGA_SR_INDEX);
sr1 = inb(VGA_SR_DATA);
outb(sr1 | 1<<5, VGA_SR_DATA);
vga_put(pdev, VGA_RSRC_LEGACY_IO);
udelay(300);
I915_WRITE(vga_reg, VGA_DISP_DISABLE);
POSTING_READ(vga_reg);
}
void intel_modeset_init_hw(struct drm_device *dev)
{
struct drm_i915_private *dev_priv = to_i915(dev);
intel_update_cdclk(dev_priv);
dev_priv->atomic_cdclk_freq = dev_priv->cdclk_freq;
intel_init_clock_gating(dev_priv);
}
static void sanitize_watermarks(struct drm_device *dev)
{
struct drm_i915_private *dev_priv = to_i915(dev);
struct drm_atomic_state *state;
struct intel_atomic_state *intel_state;
struct drm_crtc *crtc;
struct drm_crtc_state *cstate;
struct drm_modeset_acquire_ctx ctx;
int ret;
int i;
if (!dev_priv->display.optimize_watermarks)
return;
drm_modeset_acquire_init(&ctx, 0);
retry:
ret = drm_modeset_lock_all_ctx(dev, &ctx);
if (ret == -EDEADLK) {
drm_modeset_backoff(&ctx);
goto retry;
} else if (WARN_ON(ret)) {
goto fail;
}
state = drm_atomic_helper_duplicate_state(dev, &ctx);
if (WARN_ON(IS_ERR(state)))
goto fail;
intel_state = to_intel_atomic_state(state);
intel_state->skip_intermediate_wm = true;
ret = intel_atomic_check(dev, state);
if (ret) {
WARN(true, "Could not determine valid watermarks for inherited state\n");
goto put_state;
}
for_each_crtc_in_state(state, crtc, cstate, i) {
struct intel_crtc_state *cs = to_intel_crtc_state(cstate);
cs->wm.need_postvbl_update = true;
dev_priv->display.optimize_watermarks(intel_state, cs);
}
put_state:
drm_atomic_state_put(state);
fail:
drm_modeset_drop_locks(&ctx);
drm_modeset_acquire_fini(&ctx);
}
static void intel_atomic_helper_free_state(struct work_struct *work)
{
struct drm_i915_private *dev_priv =
container_of(work, typeof(*dev_priv), atomic_helper.free_work);
struct intel_atomic_state *state, *next;
struct llist_node *freed;
freed = llist_del_all(&dev_priv->atomic_helper.free_list);
llist_for_each_entry_safe(state, next, freed, freed)
drm_atomic_state_put(&state->base);
}
int intel_modeset_init(struct drm_device *dev)
{
struct drm_i915_private *dev_priv = to_i915(dev);
struct i915_ggtt *ggtt = &dev_priv->ggtt;
enum pipe pipe;
struct intel_crtc *crtc;
drm_mode_config_init(dev);
dev->mode_config.min_width = 0;
dev->mode_config.min_height = 0;
dev->mode_config.preferred_depth = 24;
dev->mode_config.prefer_shadow = 1;
dev->mode_config.allow_fb_modifiers = true;
dev->mode_config.funcs = &intel_mode_funcs;
INIT_WORK(&dev_priv->atomic_helper.free_work,
intel_atomic_helper_free_state);
intel_init_quirks(dev);
intel_init_pm(dev_priv);
if (INTEL_INFO(dev_priv)->num_pipes == 0)
return 0;
if (HAS_PCH_IBX(dev_priv) || HAS_PCH_CPT(dev_priv)) {
bool bios_lvds_use_ssc = !!(I915_READ(PCH_DREF_CONTROL) &
DREF_SSC1_ENABLE);
if (dev_priv->vbt.lvds_use_ssc != bios_lvds_use_ssc) {
DRM_DEBUG_KMS("SSC %sabled by BIOS, overriding VBT which says %sabled\n",
bios_lvds_use_ssc ? "en" : "dis",
dev_priv->vbt.lvds_use_ssc ? "en" : "dis");
dev_priv->vbt.lvds_use_ssc = bios_lvds_use_ssc;
}
}
if (IS_GEN2(dev_priv)) {
dev->mode_config.max_width = 2048;
dev->mode_config.max_height = 2048;
} else if (IS_GEN3(dev_priv)) {
dev->mode_config.max_width = 4096;
dev->mode_config.max_height = 4096;
} else {
dev->mode_config.max_width = 8192;
dev->mode_config.max_height = 8192;
}
if (IS_845G(dev_priv) || IS_I865G(dev_priv)) {
dev->mode_config.cursor_width = IS_845G(dev_priv) ? 64 : 512;
dev->mode_config.cursor_height = 1023;
} else if (IS_GEN2(dev_priv)) {
dev->mode_config.cursor_width = GEN2_CURSOR_WIDTH;
dev->mode_config.cursor_height = GEN2_CURSOR_HEIGHT;
} else {
dev->mode_config.cursor_width = MAX_CURSOR_WIDTH;
dev->mode_config.cursor_height = MAX_CURSOR_HEIGHT;
}
dev->mode_config.fb_base = ggtt->mappable_base;
DRM_DEBUG_KMS("%d display pipe%s available.\n",
INTEL_INFO(dev_priv)->num_pipes,
INTEL_INFO(dev_priv)->num_pipes > 1 ? "s" : "");
for_each_pipe(dev_priv, pipe) {
int ret;
ret = intel_crtc_init(dev_priv, pipe);
if (ret) {
drm_mode_config_cleanup(dev);
return ret;
}
}
intel_update_czclk(dev_priv);
intel_update_cdclk(dev_priv);
dev_priv->atomic_cdclk_freq = dev_priv->cdclk_freq;
intel_shared_dpll_init(dev);
if (dev_priv->max_cdclk_freq == 0)
intel_update_max_cdclk(dev_priv);
i915_disable_vga(dev_priv);
intel_setup_outputs(dev);
drm_modeset_lock_all(dev);
intel_modeset_setup_hw_state(dev);
drm_modeset_unlock_all(dev);
for_each_intel_crtc(dev, crtc) {
struct intel_initial_plane_config plane_config = {};
if (!crtc->active)
continue;
dev_priv->display.get_initial_plane_config(crtc,
&plane_config);
intel_find_initial_plane_obj(crtc, &plane_config);
}
sanitize_watermarks(dev);
return 0;
}
static void intel_enable_pipe_a(struct drm_device *dev)
{
struct intel_connector *connector;
struct drm_connector *crt = NULL;
struct intel_load_detect_pipe load_detect_temp;
struct drm_modeset_acquire_ctx *ctx = dev->mode_config.acquire_ctx;
for_each_intel_connector(dev, connector) {
if (connector->encoder->type == INTEL_OUTPUT_ANALOG) {
crt = &connector->base;
break;
}
}
if (!crt)
return;
if (intel_get_load_detect_pipe(crt, NULL, &load_detect_temp, ctx))
intel_release_load_detect_pipe(crt, &load_detect_temp, ctx);
}
static bool
intel_check_plane_mapping(struct intel_crtc *crtc)
{
struct drm_i915_private *dev_priv = to_i915(crtc->base.dev);
u32 val;
if (INTEL_INFO(dev_priv)->num_pipes == 1)
return true;
val = I915_READ(DSPCNTR(!crtc->plane));
if ((val & DISPLAY_PLANE_ENABLE) &&
(!!(val & DISPPLANE_SEL_PIPE_MASK) == crtc->pipe))
return false;
return true;
}
static bool intel_crtc_has_encoders(struct intel_crtc *crtc)
{
struct drm_device *dev = crtc->base.dev;
struct intel_encoder *encoder;
for_each_encoder_on_crtc(dev, &crtc->base, encoder)
return true;
return false;
}
static struct intel_connector *intel_encoder_find_connector(struct intel_encoder *encoder)
{
struct drm_device *dev = encoder->base.dev;
struct intel_connector *connector;
for_each_connector_on_encoder(dev, &encoder->base, connector)
return connector;
return NULL;
}
static bool has_pch_trancoder(struct drm_i915_private *dev_priv,
enum transcoder pch_transcoder)
{
return HAS_PCH_IBX(dev_priv) || HAS_PCH_CPT(dev_priv) ||
(HAS_PCH_LPT_H(dev_priv) && pch_transcoder == TRANSCODER_A);
}
static void intel_sanitize_crtc(struct intel_crtc *crtc)
{
struct drm_device *dev = crtc->base.dev;
struct drm_i915_private *dev_priv = to_i915(dev);
enum transcoder cpu_transcoder = crtc->config->cpu_transcoder;
if (!transcoder_is_dsi(cpu_transcoder)) {
i915_reg_t reg = PIPECONF(cpu_transcoder);
I915_WRITE(reg,
I915_READ(reg) & ~PIPECONF_FRAME_START_DELAY_MASK);
}
drm_crtc_vblank_reset(&crtc->base);
if (crtc->active) {
struct intel_plane *plane;
drm_crtc_vblank_on(&crtc->base);
for_each_intel_plane_on_crtc(dev, crtc, plane) {
if (plane->base.type == DRM_PLANE_TYPE_PRIMARY)
continue;
plane->disable_plane(&plane->base, &crtc->base);
}
}
if (INTEL_GEN(dev_priv) < 4 && !intel_check_plane_mapping(crtc)) {
bool plane;
DRM_DEBUG_KMS("[CRTC:%d:%s] wrong plane connection detected!\n",
crtc->base.base.id, crtc->base.name);
plane = crtc->plane;
to_intel_plane_state(crtc->base.primary->state)->base.visible = true;
crtc->plane = !plane;
intel_crtc_disable_noatomic(&crtc->base);
crtc->plane = plane;
}
if (dev_priv->quirks & QUIRK_PIPEA_FORCE &&
crtc->pipe == PIPE_A && !crtc->active) {
intel_enable_pipe_a(dev);
}
if (crtc->active && !intel_crtc_has_encoders(crtc))
intel_crtc_disable_noatomic(&crtc->base);
if (crtc->active || HAS_GMCH_DISPLAY(dev_priv)) {
crtc->cpu_fifo_underrun_disabled = true;
if (has_pch_trancoder(dev_priv, (enum transcoder)crtc->pipe))
crtc->pch_fifo_underrun_disabled = true;
}
}
static void intel_sanitize_encoder(struct intel_encoder *encoder)
{
struct intel_connector *connector;
bool has_active_crtc = encoder->base.crtc &&
to_intel_crtc(encoder->base.crtc)->active;
connector = intel_encoder_find_connector(encoder);
if (connector && !has_active_crtc) {
DRM_DEBUG_KMS("[ENCODER:%d:%s] has active connectors but no active pipe!\n",
encoder->base.base.id,
encoder->base.name);
if (encoder->base.crtc) {
struct drm_crtc_state *crtc_state = encoder->base.crtc->state;
DRM_DEBUG_KMS("[ENCODER:%d:%s] manually disabled\n",
encoder->base.base.id,
encoder->base.name);
encoder->disable(encoder, to_intel_crtc_state(crtc_state), connector->base.state);
if (encoder->post_disable)
encoder->post_disable(encoder, to_intel_crtc_state(crtc_state), connector->base.state);
}
encoder->base.crtc = NULL;
connector->base.dpms = DRM_MODE_DPMS_OFF;
connector->base.encoder = NULL;
}
}
void i915_redisable_vga_power_on(struct drm_i915_private *dev_priv)
{
i915_reg_t vga_reg = i915_vgacntrl_reg(dev_priv);
if (!(I915_READ(vga_reg) & VGA_DISP_DISABLE)) {
DRM_DEBUG_KMS("Something enabled VGA plane, disabling it\n");
i915_disable_vga(dev_priv);
}
}
void i915_redisable_vga(struct drm_i915_private *dev_priv)
{
if (!intel_display_power_get_if_enabled(dev_priv, POWER_DOMAIN_VGA))
return;
i915_redisable_vga_power_on(dev_priv);
intel_display_power_put(dev_priv, POWER_DOMAIN_VGA);
}
static bool primary_get_hw_state(struct intel_plane *plane)
{
struct drm_i915_private *dev_priv = to_i915(plane->base.dev);
return I915_READ(DSPCNTR(plane->plane)) & DISPLAY_PLANE_ENABLE;
}
static void readout_plane_state(struct intel_crtc *crtc)
{
struct drm_plane *primary = crtc->base.primary;
struct intel_plane_state *plane_state =
to_intel_plane_state(primary->state);
plane_state->base.visible = crtc->active &&
primary_get_hw_state(to_intel_plane(primary));
if (plane_state->base.visible)
crtc->base.state->plane_mask |= 1 << drm_plane_index(primary);
}
static void intel_modeset_readout_hw_state(struct drm_device *dev)
{
struct drm_i915_private *dev_priv = to_i915(dev);
enum pipe pipe;
struct intel_crtc *crtc;
struct intel_encoder *encoder;
struct intel_connector *connector;
int i;
dev_priv->active_crtcs = 0;
for_each_intel_crtc(dev, crtc) {
struct intel_crtc_state *crtc_state = crtc->config;
__drm_atomic_helper_crtc_destroy_state(&crtc_state->base);
memset(crtc_state, 0, sizeof(*crtc_state));
crtc_state->base.crtc = &crtc->base;
crtc_state->base.active = crtc_state->base.enable =
dev_priv->display.get_pipe_config(crtc, crtc_state);
crtc->base.enabled = crtc_state->base.enable;
crtc->active = crtc_state->base.active;
if (crtc_state->base.active)
dev_priv->active_crtcs |= 1 << crtc->pipe;
readout_plane_state(crtc);
DRM_DEBUG_KMS("[CRTC:%d:%s] hw state readout: %s\n",
crtc->base.base.id, crtc->base.name,
enableddisabled(crtc->active));
}
for (i = 0; i < dev_priv->num_shared_dpll; i++) {
struct intel_shared_dpll *pll = &dev_priv->shared_dplls[i];
pll->on = pll->funcs.get_hw_state(dev_priv, pll,
&pll->config.hw_state);
pll->config.crtc_mask = 0;
for_each_intel_crtc(dev, crtc) {
if (crtc->active && crtc->config->shared_dpll == pll)
pll->config.crtc_mask |= 1 << crtc->pipe;
}
pll->active_mask = pll->config.crtc_mask;
DRM_DEBUG_KMS("%s hw state readout: crtc_mask 0x%08x, on %i\n",
pll->name, pll->config.crtc_mask, pll->on);
}
for_each_intel_encoder(dev, encoder) {
pipe = 0;
if (encoder->get_hw_state(encoder, &pipe)) {
crtc = intel_get_crtc_for_pipe(dev_priv, pipe);
encoder->base.crtc = &crtc->base;
crtc->config->output_types |= 1 << encoder->type;
encoder->get_config(encoder, crtc->config);
} else {
encoder->base.crtc = NULL;
}
DRM_DEBUG_KMS("[ENCODER:%d:%s] hw state readout: %s, pipe %c\n",
encoder->base.base.id, encoder->base.name,
enableddisabled(encoder->base.crtc),
pipe_name(pipe));
}
for_each_intel_connector(dev, connector) {
if (connector->get_hw_state(connector)) {
connector->base.dpms = DRM_MODE_DPMS_ON;
encoder = connector->encoder;
connector->base.encoder = &encoder->base;
if (encoder->base.crtc &&
encoder->base.crtc->state->active) {
encoder->base.crtc->state->connector_mask |=
1 << drm_connector_index(&connector->base);
encoder->base.crtc->state->encoder_mask |=
1 << drm_encoder_index(&encoder->base);
}
} else {
connector->base.dpms = DRM_MODE_DPMS_OFF;
connector->base.encoder = NULL;
}
DRM_DEBUG_KMS("[CONNECTOR:%d:%s] hw state readout: %s\n",
connector->base.base.id, connector->base.name,
enableddisabled(connector->base.encoder));
}
for_each_intel_crtc(dev, crtc) {
int pixclk = 0;
crtc->base.hwmode = crtc->config->base.adjusted_mode;
memset(&crtc->base.mode, 0, sizeof(crtc->base.mode));
if (crtc->base.state->active) {
intel_mode_from_pipe_config(&crtc->base.mode, crtc->config);
intel_mode_from_pipe_config(&crtc->base.state->adjusted_mode, crtc->config);
WARN_ON(drm_atomic_set_mode_for_crtc(crtc->base.state, &crtc->base.mode));
crtc->base.state->mode.private_flags = I915_MODE_FLAG_INHERITED;
if (INTEL_GEN(dev_priv) >= 9 || IS_BROADWELL(dev_priv))
pixclk = ilk_pipe_pixel_rate(crtc->config);
else if (IS_VALLEYVIEW(dev_priv) || IS_CHERRYVIEW(dev_priv))
pixclk = crtc->config->base.adjusted_mode.crtc_clock;
else
WARN_ON(dev_priv->display.modeset_calc_cdclk);
if (IS_BROADWELL(dev_priv) && crtc->config->ips_enabled)
pixclk = DIV_ROUND_UP(pixclk * 100, 95);
drm_calc_timestamping_constants(&crtc->base, &crtc->base.hwmode);
update_scanline_offset(crtc);
}
dev_priv->min_pixclk[crtc->pipe] = pixclk;
intel_pipe_config_sanity_check(dev_priv, crtc->config);
}
}
static void
intel_modeset_setup_hw_state(struct drm_device *dev)
{
struct drm_i915_private *dev_priv = to_i915(dev);
enum pipe pipe;
struct intel_crtc *crtc;
struct intel_encoder *encoder;
int i;
intel_modeset_readout_hw_state(dev);
for_each_intel_encoder(dev, encoder) {
intel_sanitize_encoder(encoder);
}
for_each_pipe(dev_priv, pipe) {
crtc = intel_get_crtc_for_pipe(dev_priv, pipe);
intel_sanitize_crtc(crtc);
intel_dump_pipe_config(crtc, crtc->config,
"[setup_hw_state]");
}
intel_modeset_update_connector_atomic_state(dev);
for (i = 0; i < dev_priv->num_shared_dpll; i++) {
struct intel_shared_dpll *pll = &dev_priv->shared_dplls[i];
if (!pll->on || pll->active_mask)
continue;
DRM_DEBUG_KMS("%s enabled but not in use, disabling\n", pll->name);
pll->funcs.disable(dev_priv, pll);
pll->on = false;
}
if (IS_VALLEYVIEW(dev_priv) || IS_CHERRYVIEW(dev_priv))
vlv_wm_get_hw_state(dev);
else if (IS_GEN9(dev_priv))
skl_wm_get_hw_state(dev);
else if (HAS_PCH_SPLIT(dev_priv))
ilk_wm_get_hw_state(dev);
for_each_intel_crtc(dev, crtc) {
unsigned long put_domains;
put_domains = modeset_get_crtc_power_domains(&crtc->base, crtc->config);
if (WARN_ON(put_domains))
modeset_put_power_domains(dev_priv, put_domains);
}
intel_display_set_init_power(dev_priv, false);
intel_fbc_init_pipe_state(dev_priv);
}
void intel_display_resume(struct drm_device *dev)
{
struct drm_i915_private *dev_priv = to_i915(dev);
struct drm_atomic_state *state = dev_priv->modeset_restore_state;
struct drm_modeset_acquire_ctx ctx;
int ret;
dev_priv->modeset_restore_state = NULL;
if (state)
state->acquire_ctx = &ctx;
mutex_lock(&dev->mode_config.mutex);
drm_modeset_acquire_init(&ctx, 0);
while (1) {
ret = drm_modeset_lock_all_ctx(dev, &ctx);
if (ret != -EDEADLK)
break;
drm_modeset_backoff(&ctx);
}
if (!ret)
ret = __intel_display_resume(dev, state);
drm_modeset_drop_locks(&ctx);
drm_modeset_acquire_fini(&ctx);
mutex_unlock(&dev->mode_config.mutex);
if (ret)
DRM_ERROR("Restoring old state failed with %i\n", ret);
if (state)
drm_atomic_state_put(state);
}
void intel_modeset_gem_init(struct drm_device *dev)
{
struct drm_i915_private *dev_priv = to_i915(dev);
intel_init_gt_powersave(dev_priv);
intel_modeset_init_hw(dev);
intel_setup_overlay(dev_priv);
}
int intel_connector_register(struct drm_connector *connector)
{
struct intel_connector *intel_connector = to_intel_connector(connector);
int ret;
ret = intel_backlight_device_register(intel_connector);
if (ret)
goto err;
return 0;
err:
return ret;
}
void intel_connector_unregister(struct drm_connector *connector)
{
struct intel_connector *intel_connector = to_intel_connector(connector);
intel_backlight_device_unregister(intel_connector);
intel_panel_destroy_backlight(connector);
}
void intel_modeset_cleanup(struct drm_device *dev)
{
struct drm_i915_private *dev_priv = to_i915(dev);
flush_work(&dev_priv->atomic_helper.free_work);
WARN_ON(!llist_empty(&dev_priv->atomic_helper.free_list));
intel_disable_gt_powersave(dev_priv);
intel_irq_uninstall(dev_priv);
drm_kms_helper_poll_fini(dev);
intel_unregister_dsm_handler();
intel_fbc_global_disable(dev_priv);
flush_scheduled_work();
drm_mode_config_cleanup(dev);
intel_cleanup_overlay(dev_priv);
intel_cleanup_gt_powersave(dev_priv);
intel_teardown_gmbus(dev);
}
void intel_connector_attach_encoder(struct intel_connector *connector,
struct intel_encoder *encoder)
{
connector->encoder = encoder;
drm_mode_connector_attach_encoder(&connector->base,
&encoder->base);
}
int intel_modeset_vga_set_state(struct drm_i915_private *dev_priv, bool state)
{
unsigned reg = INTEL_GEN(dev_priv) >= 6 ? SNB_GMCH_CTRL : INTEL_GMCH_CTRL;
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
intel_display_capture_error_state(struct drm_i915_private *dev_priv)
{
struct intel_display_error_state *error;
int transcoders[] = {
TRANSCODER_A,
TRANSCODER_B,
TRANSCODER_C,
TRANSCODER_EDP,
};
int i;
if (INTEL_INFO(dev_priv)->num_pipes == 0)
return NULL;
error = kzalloc(sizeof(*error), GFP_ATOMIC);
if (error == NULL)
return NULL;
if (IS_HASWELL(dev_priv) || IS_BROADWELL(dev_priv))
error->power_well_driver = I915_READ(HSW_PWR_WELL_DRIVER);
for_each_pipe(dev_priv, i) {
error->pipe[i].power_domain_on =
__intel_display_power_is_enabled(dev_priv,
POWER_DOMAIN_PIPE(i));
if (!error->pipe[i].power_domain_on)
continue;
error->cursor[i].control = I915_READ(CURCNTR(i));
error->cursor[i].position = I915_READ(CURPOS(i));
error->cursor[i].base = I915_READ(CURBASE(i));
error->plane[i].control = I915_READ(DSPCNTR(i));
error->plane[i].stride = I915_READ(DSPSTRIDE(i));
if (INTEL_GEN(dev_priv) <= 3) {
error->plane[i].size = I915_READ(DSPSIZE(i));
error->plane[i].pos = I915_READ(DSPPOS(i));
}
if (INTEL_GEN(dev_priv) <= 7 && !IS_HASWELL(dev_priv))
error->plane[i].addr = I915_READ(DSPADDR(i));
if (INTEL_GEN(dev_priv) >= 4) {
error->plane[i].surface = I915_READ(DSPSURF(i));
error->plane[i].tile_offset = I915_READ(DSPTILEOFF(i));
}
error->pipe[i].source = I915_READ(PIPESRC(i));
if (HAS_GMCH_DISPLAY(dev_priv))
error->pipe[i].stat = I915_READ(PIPESTAT(i));
}
error->num_transcoders = INTEL_INFO(dev_priv)->num_pipes;
if (HAS_DDI(dev_priv))
error->num_transcoders++;
for (i = 0; i < error->num_transcoders; i++) {
enum transcoder cpu_transcoder = transcoders[i];
error->transcoder[i].power_domain_on =
__intel_display_power_is_enabled(dev_priv,
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
struct drm_i915_private *dev_priv,
struct intel_display_error_state *error)
{
int i;
if (!error)
return;
err_printf(m, "Num Pipes: %d\n", INTEL_INFO(dev_priv)->num_pipes);
if (IS_HASWELL(dev_priv) || IS_BROADWELL(dev_priv))
err_printf(m, "PWR_WELL_CTL2: %08x\n",
error->power_well_driver);
for_each_pipe(dev_priv, i) {
err_printf(m, "Pipe [%d]:\n", i);
err_printf(m, " Power: %s\n",
onoff(error->pipe[i].power_domain_on));
err_printf(m, " SRC: %08x\n", error->pipe[i].source);
err_printf(m, " STAT: %08x\n", error->pipe[i].stat);
err_printf(m, "Plane [%d]:\n", i);
err_printf(m, " CNTR: %08x\n", error->plane[i].control);
err_printf(m, " STRIDE: %08x\n", error->plane[i].stride);
if (INTEL_GEN(dev_priv) <= 3) {
err_printf(m, " SIZE: %08x\n", error->plane[i].size);
err_printf(m, " POS: %08x\n", error->plane[i].pos);
}
if (INTEL_GEN(dev_priv) <= 7 && !IS_HASWELL(dev_priv))
err_printf(m, " ADDR: %08x\n", error->plane[i].addr);
if (INTEL_GEN(dev_priv) >= 4) {
err_printf(m, " SURF: %08x\n", error->plane[i].surface);
err_printf(m, " TILEOFF: %08x\n", error->plane[i].tile_offset);
}
err_printf(m, "Cursor [%d]:\n", i);
err_printf(m, " CNTR: %08x\n", error->cursor[i].control);
err_printf(m, " POS: %08x\n", error->cursor[i].position);
err_printf(m, " BASE: %08x\n", error->cursor[i].base);
}
for (i = 0; i < error->num_transcoders; i++) {
err_printf(m, "CPU transcoder: %s\n",
transcoder_name(error->transcoder[i].cpu_transcoder));
err_printf(m, " Power: %s\n",
onoff(error->transcoder[i].power_domain_on));
err_printf(m, " CONF: %08x\n", error->transcoder[i].conf);
err_printf(m, " HTOTAL: %08x\n", error->transcoder[i].htotal);
err_printf(m, " HBLANK: %08x\n", error->transcoder[i].hblank);
err_printf(m, " HSYNC: %08x\n", error->transcoder[i].hsync);
err_printf(m, " VTOTAL: %08x\n", error->transcoder[i].vtotal);
err_printf(m, " VBLANK: %08x\n", error->transcoder[i].vblank);
err_printf(m, " VSYNC: %08x\n", error->transcoder[i].vsync);
}
}
