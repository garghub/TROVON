static const struct gma_limit_t *mrst_limit(struct drm_crtc *crtc,
int refclk)
{
const struct gma_limit_t *limit = NULL;
struct drm_device *dev = crtc->dev;
struct drm_psb_private *dev_priv = dev->dev_private;
if (gma_pipe_has_type(crtc, INTEL_OUTPUT_LVDS)
|| gma_pipe_has_type(crtc, INTEL_OUTPUT_MIPI)) {
switch (dev_priv->core_freq) {
case 100:
limit = &mrst_limits[MRST_LIMIT_LVDS_100L];
break;
case 166:
limit = &mrst_limits[MRST_LIMIT_LVDS_83];
break;
case 200:
limit = &mrst_limits[MRST_LIMIT_LVDS_100];
break;
}
} else if (gma_pipe_has_type(crtc, INTEL_OUTPUT_SDVO)) {
limit = &mrst_limits[MRST_LIMIT_SDVO];
} else {
limit = NULL;
dev_err(dev->dev, "mrst_limit Wrong display type.\n");
}
return limit;
}
static void mrst_lvds_clock(int refclk, struct gma_clock_t *clock)
{
clock->dot = (refclk * clock->m) / (14 * clock->p1);
}
static void mrst_print_pll(struct gma_clock_t *clock)
{
DRM_DEBUG_DRIVER("dotclock=%d, m=%d, m1=%d, m2=%d, n=%d, p1=%d, p2=%d\n",
clock->dot, clock->m, clock->m1, clock->m2, clock->n,
clock->p1, clock->p2);
}
static bool mrst_sdvo_find_best_pll(const struct gma_limit_t *limit,
struct drm_crtc *crtc, int target,
int refclk, struct gma_clock_t *best_clock)
{
struct gma_clock_t clock;
u32 target_vco, actual_freq;
s32 freq_error, min_error = 100000;
memset(best_clock, 0, sizeof(*best_clock));
for (clock.m = limit->m.min; clock.m <= limit->m.max; clock.m++) {
for (clock.n = limit->n.min; clock.n <= limit->n.max;
clock.n++) {
for (clock.p1 = limit->p1.min;
clock.p1 <= limit->p1.max; clock.p1++) {
clock.p = clock.p1 * limit->p2.p2_slow;
target_vco = target * clock.p;
if (target_vco > limit->vco.max)
break;
if (target_vco < limit->vco.min)
continue;
actual_freq = (refclk * clock.m) /
(clock.n * clock.p);
freq_error = 10000 -
((target * 10000) / actual_freq);
if (freq_error < -min_error) {
break;
}
if (freq_error < 0)
freq_error = -freq_error;
if (freq_error < min_error) {
min_error = freq_error;
*best_clock = clock;
}
}
}
if (min_error == 0)
break;
}
return min_error == 0;
}
static bool mrst_lvds_find_best_pll(const struct gma_limit_t *limit,
struct drm_crtc *crtc, int target,
int refclk, struct gma_clock_t *best_clock)
{
struct gma_clock_t clock;
int err = target;
memset(best_clock, 0, sizeof(*best_clock));
for (clock.m = limit->m.min; clock.m <= limit->m.max; clock.m++) {
for (clock.p1 = limit->p1.min; clock.p1 <= limit->p1.max;
clock.p1++) {
int this_err;
mrst_lvds_clock(refclk, &clock);
this_err = abs(clock.dot - target);
if (this_err < err) {
*best_clock = clock;
err = this_err;
}
}
}
return err != target;
}
static void oaktrail_crtc_dpms(struct drm_crtc *crtc, int mode)
{
struct drm_device *dev = crtc->dev;
struct drm_psb_private *dev_priv = dev->dev_private;
struct gma_crtc *gma_crtc = to_gma_crtc(crtc);
int pipe = gma_crtc->pipe;
const struct psb_offset *map = &dev_priv->regmap[pipe];
u32 temp;
int i;
int need_aux = gma_pipe_has_type(crtc, INTEL_OUTPUT_SDVO) ? 1 : 0;
if (gma_pipe_has_type(crtc, INTEL_OUTPUT_HDMI)) {
oaktrail_crtc_hdmi_dpms(crtc, mode);
return;
}
if (!gma_power_begin(dev, true))
return;
switch (mode) {
case DRM_MODE_DPMS_ON:
case DRM_MODE_DPMS_STANDBY:
case DRM_MODE_DPMS_SUSPEND:
for (i = 0; i <= need_aux; i++) {
temp = REG_READ_WITH_AUX(map->dpll, i);
if ((temp & DPLL_VCO_ENABLE) == 0) {
REG_WRITE_WITH_AUX(map->dpll, temp, i);
REG_READ_WITH_AUX(map->dpll, i);
udelay(150);
REG_WRITE_WITH_AUX(map->dpll,
temp | DPLL_VCO_ENABLE, i);
REG_READ_WITH_AUX(map->dpll, i);
udelay(150);
REG_WRITE_WITH_AUX(map->dpll,
temp | DPLL_VCO_ENABLE, i);
REG_READ_WITH_AUX(map->dpll, i);
udelay(150);
}
temp = REG_READ_WITH_AUX(map->conf, i);
if ((temp & PIPEACONF_ENABLE) == 0) {
REG_WRITE_WITH_AUX(map->conf,
temp | PIPEACONF_ENABLE, i);
}
temp = REG_READ_WITH_AUX(map->cntr, i);
if ((temp & DISPLAY_PLANE_ENABLE) == 0) {
REG_WRITE_WITH_AUX(map->cntr,
temp | DISPLAY_PLANE_ENABLE,
i);
REG_WRITE_WITH_AUX(map->base,
REG_READ_WITH_AUX(map->base, i), i);
}
}
gma_crtc_load_lut(crtc);
break;
case DRM_MODE_DPMS_OFF:
for (i = 0; i <= need_aux; i++) {
REG_WRITE_WITH_AUX(VGACNTRL, VGA_DISP_DISABLE, i);
temp = REG_READ_WITH_AUX(map->cntr, i);
if ((temp & DISPLAY_PLANE_ENABLE) != 0) {
REG_WRITE_WITH_AUX(map->cntr,
temp & ~DISPLAY_PLANE_ENABLE, i);
REG_WRITE_WITH_AUX(map->base,
REG_READ(map->base), i);
REG_READ_WITH_AUX(map->base, i);
}
temp = REG_READ_WITH_AUX(map->conf, i);
if ((temp & PIPEACONF_ENABLE) != 0) {
REG_WRITE_WITH_AUX(map->conf,
temp & ~PIPEACONF_ENABLE, i);
REG_READ_WITH_AUX(map->conf, i);
}
gma_wait_for_vblank(dev);
temp = REG_READ_WITH_AUX(map->dpll, i);
if ((temp & DPLL_VCO_ENABLE) != 0) {
REG_WRITE_WITH_AUX(map->dpll,
temp & ~DPLL_VCO_ENABLE, i);
REG_READ_WITH_AUX(map->dpll, i);
}
udelay(150);
}
break;
}
REG_WRITE(DSPARB, 0x3f80);
REG_WRITE(DSPFW1, 0x3f8f0404);
REG_WRITE(DSPFW2, 0x04040f04);
REG_WRITE(DSPFW3, 0x0);
REG_WRITE(DSPFW4, 0x04040404);
REG_WRITE(DSPFW5, 0x04040404);
REG_WRITE(DSPFW6, 0x78);
REG_WRITE(DSPCHICKENBIT, REG_READ(DSPCHICKENBIT) | 0xc040);
gma_power_end(dev);
}
static int oaktrail_panel_fitter_pipe(struct drm_device *dev)
{
u32 pfit_control;
pfit_control = REG_READ(PFIT_CONTROL);
if ((pfit_control & PFIT_ENABLE) == 0)
return -1;
return (pfit_control >> 29) & 3;
}
static int oaktrail_crtc_mode_set(struct drm_crtc *crtc,
struct drm_display_mode *mode,
struct drm_display_mode *adjusted_mode,
int x, int y,
struct drm_framebuffer *old_fb)
{
struct drm_device *dev = crtc->dev;
struct gma_crtc *gma_crtc = to_gma_crtc(crtc);
struct drm_psb_private *dev_priv = dev->dev_private;
int pipe = gma_crtc->pipe;
const struct psb_offset *map = &dev_priv->regmap[pipe];
int refclk = 0;
struct gma_clock_t clock;
const struct gma_limit_t *limit;
u32 dpll = 0, fp = 0, dspcntr, pipeconf;
bool ok, is_sdvo = false;
bool is_lvds = false;
bool is_mipi = false;
struct drm_mode_config *mode_config = &dev->mode_config;
struct gma_encoder *gma_encoder = NULL;
uint64_t scalingType = DRM_MODE_SCALE_FULLSCREEN;
struct drm_connector *connector;
int i;
int need_aux = gma_pipe_has_type(crtc, INTEL_OUTPUT_SDVO) ? 1 : 0;
if (gma_pipe_has_type(crtc, INTEL_OUTPUT_HDMI))
return oaktrail_crtc_hdmi_mode_set(crtc, mode, adjusted_mode, x, y, old_fb);
if (!gma_power_begin(dev, true))
return 0;
memcpy(&gma_crtc->saved_mode,
mode,
sizeof(struct drm_display_mode));
memcpy(&gma_crtc->saved_adjusted_mode,
adjusted_mode,
sizeof(struct drm_display_mode));
list_for_each_entry(connector, &mode_config->connector_list, head) {
if (!connector->encoder || connector->encoder->crtc != crtc)
continue;
gma_encoder = gma_attached_encoder(connector);
switch (gma_encoder->type) {
case INTEL_OUTPUT_LVDS:
is_lvds = true;
break;
case INTEL_OUTPUT_SDVO:
is_sdvo = true;
break;
case INTEL_OUTPUT_MIPI:
is_mipi = true;
break;
}
}
for (i = 0; i <= need_aux; i++)
REG_WRITE_WITH_AUX(VGACNTRL, VGA_DISP_DISABLE, i);
if (oaktrail_panel_fitter_pipe(dev) == pipe)
REG_WRITE(PFIT_CONTROL, 0);
for (i = 0; i <= need_aux; i++) {
REG_WRITE_WITH_AUX(map->src, ((mode->crtc_hdisplay - 1) << 16) |
(mode->crtc_vdisplay - 1), i);
}
if (gma_encoder)
drm_object_property_get_value(&connector->base,
dev->mode_config.scaling_mode_property, &scalingType);
if (scalingType == DRM_MODE_SCALE_NO_SCALE) {
int offsetX = 0, offsetY = 0;
offsetX = (adjusted_mode->crtc_hdisplay -
mode->crtc_hdisplay) / 2;
offsetY = (adjusted_mode->crtc_vdisplay -
mode->crtc_vdisplay) / 2;
for (i = 0; i <= need_aux; i++) {
REG_WRITE_WITH_AUX(map->htotal, (mode->crtc_hdisplay - 1) |
((adjusted_mode->crtc_htotal - 1) << 16), i);
REG_WRITE_WITH_AUX(map->vtotal, (mode->crtc_vdisplay - 1) |
((adjusted_mode->crtc_vtotal - 1) << 16), i);
REG_WRITE_WITH_AUX(map->hblank,
(adjusted_mode->crtc_hblank_start - offsetX - 1) |
((adjusted_mode->crtc_hblank_end - offsetX - 1) << 16), i);
REG_WRITE_WITH_AUX(map->hsync,
(adjusted_mode->crtc_hsync_start - offsetX - 1) |
((adjusted_mode->crtc_hsync_end - offsetX - 1) << 16), i);
REG_WRITE_WITH_AUX(map->vblank,
(adjusted_mode->crtc_vblank_start - offsetY - 1) |
((adjusted_mode->crtc_vblank_end - offsetY - 1) << 16), i);
REG_WRITE_WITH_AUX(map->vsync,
(adjusted_mode->crtc_vsync_start - offsetY - 1) |
((adjusted_mode->crtc_vsync_end - offsetY - 1) << 16), i);
}
} else {
for (i = 0; i <= need_aux; i++) {
REG_WRITE_WITH_AUX(map->htotal, (adjusted_mode->crtc_hdisplay - 1) |
((adjusted_mode->crtc_htotal - 1) << 16), i);
REG_WRITE_WITH_AUX(map->vtotal, (adjusted_mode->crtc_vdisplay - 1) |
((adjusted_mode->crtc_vtotal - 1) << 16), i);
REG_WRITE_WITH_AUX(map->hblank, (adjusted_mode->crtc_hblank_start - 1) |
((adjusted_mode->crtc_hblank_end - 1) << 16), i);
REG_WRITE_WITH_AUX(map->hsync, (adjusted_mode->crtc_hsync_start - 1) |
((adjusted_mode->crtc_hsync_end - 1) << 16), i);
REG_WRITE_WITH_AUX(map->vblank, (adjusted_mode->crtc_vblank_start - 1) |
((adjusted_mode->crtc_vblank_end - 1) << 16), i);
REG_WRITE_WITH_AUX(map->vsync, (adjusted_mode->crtc_vsync_start - 1) |
((adjusted_mode->crtc_vsync_end - 1) << 16), i);
}
}
{
struct drm_crtc_helper_funcs *crtc_funcs =
crtc->helper_private;
crtc_funcs->mode_set_base(crtc, x, y, old_fb);
}
pipeconf = REG_READ(map->conf);
dspcntr = REG_READ(map->cntr);
dspcntr |= DISPPLANE_GAMMA_ENABLE;
if (pipe == 0)
dspcntr |= DISPPLANE_SEL_PIPE_A;
else
dspcntr |= DISPPLANE_SEL_PIPE_B;
if (is_mipi)
goto oaktrail_crtc_mode_set_exit;
dpll = 0;
refclk = is_sdvo ? 96000 : dev_priv->core_freq * 1000;
limit = mrst_limit(crtc, refclk);
ok = limit->find_pll(limit, crtc, adjusted_mode->clock,
refclk, &clock);
if (is_sdvo) {
clock.p1 = (1L << (clock.p1 - 1));
clock.m -= 2;
clock.n = (1L << (clock.n - 1));
}
if (!ok)
DRM_ERROR("Failed to find proper PLL settings");
mrst_print_pll(&clock);
if (is_sdvo)
fp = clock.n << 16 | clock.m;
else
fp = oaktrail_m_converts[(clock.m - MRST_M_MIN)] << 8;
dpll |= DPLL_VGA_MODE_DIS;
dpll |= DPLL_VCO_ENABLE;
if (is_lvds)
dpll |= DPLLA_MODE_LVDS;
else
dpll |= DPLLB_MODE_DAC_SERIAL;
if (is_sdvo) {
int sdvo_pixel_multiply =
adjusted_mode->clock / mode->clock;
dpll |= DPLL_DVO_HIGH_SPEED;
dpll |=
(sdvo_pixel_multiply -
1) << SDVO_MULTIPLIER_SHIFT_HIRES;
}
if (is_sdvo)
dpll |= clock.p1 << 16;
else
dpll |= (1 << (clock.p1 - 2)) << 17;
dpll |= DPLL_VCO_ENABLE;
if (dpll & DPLL_VCO_ENABLE) {
for (i = 0; i <= need_aux; i++) {
REG_WRITE_WITH_AUX(map->fp0, fp, i);
REG_WRITE_WITH_AUX(map->dpll, dpll & ~DPLL_VCO_ENABLE, i);
REG_READ_WITH_AUX(map->dpll, i);
udelay(150);
}
}
for (i = 0; i <= need_aux; i++) {
REG_WRITE_WITH_AUX(map->fp0, fp, i);
REG_WRITE_WITH_AUX(map->dpll, dpll, i);
REG_READ_WITH_AUX(map->dpll, i);
udelay(150);
REG_WRITE_WITH_AUX(map->dpll, dpll, i);
REG_READ_WITH_AUX(map->dpll, i);
udelay(150);
REG_WRITE_WITH_AUX(map->conf, pipeconf, i);
REG_READ_WITH_AUX(map->conf, i);
gma_wait_for_vblank(dev);
REG_WRITE_WITH_AUX(map->cntr, dspcntr, i);
gma_wait_for_vblank(dev);
}
oaktrail_crtc_mode_set_exit:
gma_power_end(dev);
return 0;
}
static int oaktrail_pipe_set_base(struct drm_crtc *crtc,
int x, int y, struct drm_framebuffer *old_fb)
{
struct drm_device *dev = crtc->dev;
struct drm_psb_private *dev_priv = dev->dev_private;
struct gma_crtc *gma_crtc = to_gma_crtc(crtc);
struct psb_framebuffer *psbfb = to_psb_fb(crtc->primary->fb);
int pipe = gma_crtc->pipe;
const struct psb_offset *map = &dev_priv->regmap[pipe];
unsigned long start, offset;
u32 dspcntr;
int ret = 0;
if (!crtc->primary->fb) {
dev_dbg(dev->dev, "No FB bound\n");
return 0;
}
if (!gma_power_begin(dev, true))
return 0;
start = psbfb->gtt->offset;
offset = y * crtc->primary->fb->pitches[0] + x * (crtc->primary->fb->bits_per_pixel / 8);
REG_WRITE(map->stride, crtc->primary->fb->pitches[0]);
dspcntr = REG_READ(map->cntr);
dspcntr &= ~DISPPLANE_PIXFORMAT_MASK;
switch (crtc->primary->fb->bits_per_pixel) {
case 8:
dspcntr |= DISPPLANE_8BPP;
break;
case 16:
if (crtc->primary->fb->depth == 15)
dspcntr |= DISPPLANE_15_16BPP;
else
dspcntr |= DISPPLANE_16BPP;
break;
case 24:
case 32:
dspcntr |= DISPPLANE_32BPP_NO_ALPHA;
break;
default:
dev_err(dev->dev, "Unknown color depth\n");
ret = -EINVAL;
goto pipe_set_base_exit;
}
REG_WRITE(map->cntr, dspcntr);
REG_WRITE(map->base, offset);
REG_READ(map->base);
REG_WRITE(map->surf, start);
REG_READ(map->surf);
pipe_set_base_exit:
gma_power_end(dev);
return ret;
}
