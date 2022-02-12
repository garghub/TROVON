static const struct oaktrail_limit_t *oaktrail_limit(struct drm_crtc *crtc)
{
const struct oaktrail_limit_t *limit = NULL;
struct drm_device *dev = crtc->dev;
struct drm_psb_private *dev_priv = dev->dev_private;
if (psb_intel_pipe_has_type(crtc, INTEL_OUTPUT_LVDS)
|| psb_intel_pipe_has_type(crtc, INTEL_OUTPUT_MIPI)) {
switch (dev_priv->core_freq) {
case 100:
limit = &oaktrail_limits[MRST_LIMIT_LVDS_100L];
break;
case 166:
limit = &oaktrail_limits[MRST_LIMIT_LVDS_83];
break;
case 200:
limit = &oaktrail_limits[MRST_LIMIT_LVDS_100];
break;
}
} else {
limit = NULL;
dev_err(dev->dev, "oaktrail_limit Wrong display type.\n");
}
return limit;
}
static void oaktrail_clock(int refclk, struct oaktrail_clock_t *clock)
{
clock->dot = (refclk * clock->m) / (14 * clock->p1);
}
static void mrstPrintPll(char *prefix, struct oaktrail_clock_t *clock)
{
pr_debug("%s: dotclock = %d, m = %d, p1 = %d.\n",
prefix, clock->dot, clock->m, clock->p1);
}
static bool
mrstFindBestPLL(struct drm_crtc *crtc, int target, int refclk,
struct oaktrail_clock_t *best_clock)
{
struct oaktrail_clock_t clock;
const struct oaktrail_limit_t *limit = oaktrail_limit(crtc);
int err = target;
memset(best_clock, 0, sizeof(*best_clock));
for (clock.m = limit->m.min; clock.m <= limit->m.max; clock.m++) {
for (clock.p1 = limit->p1.min; clock.p1 <= limit->p1.max;
clock.p1++) {
int this_err;
oaktrail_clock(refclk, &clock);
this_err = abs(clock.dot - target);
if (this_err < err) {
*best_clock = clock;
err = this_err;
}
}
}
dev_dbg(crtc->dev->dev, "mrstFindBestPLL err = %d.\n", err);
return err != target;
}
static void oaktrail_crtc_dpms(struct drm_crtc *crtc, int mode)
{
struct drm_device *dev = crtc->dev;
struct drm_psb_private *dev_priv = dev->dev_private;
struct psb_intel_crtc *psb_intel_crtc = to_psb_intel_crtc(crtc);
int pipe = psb_intel_crtc->pipe;
const struct psb_offset *map = &dev_priv->regmap[pipe];
u32 temp;
if (!gma_power_begin(dev, true))
return;
switch (mode) {
case DRM_MODE_DPMS_ON:
case DRM_MODE_DPMS_STANDBY:
case DRM_MODE_DPMS_SUSPEND:
temp = REG_READ(map->dpll);
if ((temp & DPLL_VCO_ENABLE) == 0) {
REG_WRITE(map->dpll, temp);
REG_READ(map->dpll);
udelay(150);
REG_WRITE(map->dpll, temp | DPLL_VCO_ENABLE);
REG_READ(map->dpll);
udelay(150);
REG_WRITE(map->dpll, temp | DPLL_VCO_ENABLE);
REG_READ(map->dpll);
udelay(150);
}
temp = REG_READ(map->conf);
if ((temp & PIPEACONF_ENABLE) == 0)
REG_WRITE(map->conf, temp | PIPEACONF_ENABLE);
temp = REG_READ(map->cntr);
if ((temp & DISPLAY_PLANE_ENABLE) == 0) {
REG_WRITE(map->cntr,
temp | DISPLAY_PLANE_ENABLE);
REG_WRITE(map->base, REG_READ(map->base));
}
psb_intel_crtc_load_lut(crtc);
break;
case DRM_MODE_DPMS_OFF:
REG_WRITE(VGACNTRL, VGA_DISP_DISABLE);
temp = REG_READ(map->cntr);
if ((temp & DISPLAY_PLANE_ENABLE) != 0) {
REG_WRITE(map->cntr,
temp & ~DISPLAY_PLANE_ENABLE);
REG_WRITE(map->base, REG_READ(map->base));
REG_READ(map->base);
}
temp = REG_READ(map->conf);
if ((temp & PIPEACONF_ENABLE) != 0) {
REG_WRITE(map->conf, temp & ~PIPEACONF_ENABLE);
REG_READ(map->conf);
}
psb_intel_wait_for_vblank(dev);
temp = REG_READ(map->dpll);
if ((temp & DPLL_VCO_ENABLE) != 0) {
REG_WRITE(map->dpll, temp & ~DPLL_VCO_ENABLE);
REG_READ(map->dpll);
}
udelay(150);
break;
}
REG_WRITE(DSPARB, 0x3FFF);
REG_WRITE(DSPFW1, 0x3F88080A);
REG_WRITE(DSPFW2, 0x0b060808);
REG_WRITE(DSPFW3, 0x0);
REG_WRITE(DSPFW4, 0x08030404);
REG_WRITE(DSPFW5, 0x04040404);
REG_WRITE(DSPFW6, 0x78);
REG_WRITE(0x70400, REG_READ(0x70400) | 0x4000);
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
struct psb_intel_crtc *psb_intel_crtc = to_psb_intel_crtc(crtc);
struct drm_psb_private *dev_priv = dev->dev_private;
int pipe = psb_intel_crtc->pipe;
const struct psb_offset *map = &dev_priv->regmap[pipe];
int refclk = 0;
struct oaktrail_clock_t clock;
u32 dpll = 0, fp = 0, dspcntr, pipeconf;
bool ok, is_sdvo = false;
bool is_lvds = false;
bool is_mipi = false;
struct drm_mode_config *mode_config = &dev->mode_config;
struct psb_intel_encoder *psb_intel_encoder = NULL;
uint64_t scalingType = DRM_MODE_SCALE_FULLSCREEN;
struct drm_connector *connector;
if (!gma_power_begin(dev, true))
return 0;
memcpy(&psb_intel_crtc->saved_mode,
mode,
sizeof(struct drm_display_mode));
memcpy(&psb_intel_crtc->saved_adjusted_mode,
adjusted_mode,
sizeof(struct drm_display_mode));
list_for_each_entry(connector, &mode_config->connector_list, head) {
if (!connector->encoder || connector->encoder->crtc != crtc)
continue;
psb_intel_encoder = psb_intel_attached_encoder(connector);
switch (psb_intel_encoder->type) {
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
REG_WRITE(VGACNTRL, VGA_DISP_DISABLE);
if (oaktrail_panel_fitter_pipe(dev) == pipe)
REG_WRITE(PFIT_CONTROL, 0);
REG_WRITE(map->src,
((mode->crtc_hdisplay - 1) << 16) |
(mode->crtc_vdisplay - 1));
if (psb_intel_encoder)
drm_connector_property_get_value(connector,
dev->mode_config.scaling_mode_property, &scalingType);
if (scalingType == DRM_MODE_SCALE_NO_SCALE) {
int offsetX = 0, offsetY = 0;
offsetX = (adjusted_mode->crtc_hdisplay -
mode->crtc_hdisplay) / 2;
offsetY = (adjusted_mode->crtc_vdisplay -
mode->crtc_vdisplay) / 2;
REG_WRITE(map->htotal, (mode->crtc_hdisplay - 1) |
((adjusted_mode->crtc_htotal - 1) << 16));
REG_WRITE(map->vtotal, (mode->crtc_vdisplay - 1) |
((adjusted_mode->crtc_vtotal - 1) << 16));
REG_WRITE(map->hblank,
(adjusted_mode->crtc_hblank_start - offsetX - 1) |
((adjusted_mode->crtc_hblank_end - offsetX - 1) << 16));
REG_WRITE(map->hsync,
(adjusted_mode->crtc_hsync_start - offsetX - 1) |
((adjusted_mode->crtc_hsync_end - offsetX - 1) << 16));
REG_WRITE(map->vblank,
(adjusted_mode->crtc_vblank_start - offsetY - 1) |
((adjusted_mode->crtc_vblank_end - offsetY - 1) << 16));
REG_WRITE(map->vsync,
(adjusted_mode->crtc_vsync_start - offsetY - 1) |
((adjusted_mode->crtc_vsync_end - offsetY - 1) << 16));
} else {
REG_WRITE(map->htotal, (adjusted_mode->crtc_hdisplay - 1) |
((adjusted_mode->crtc_htotal - 1) << 16));
REG_WRITE(map->vtotal, (adjusted_mode->crtc_vdisplay - 1) |
((adjusted_mode->crtc_vtotal - 1) << 16));
REG_WRITE(map->hblank, (adjusted_mode->crtc_hblank_start - 1) |
((adjusted_mode->crtc_hblank_end - 1) << 16));
REG_WRITE(map->hsync, (adjusted_mode->crtc_hsync_start - 1) |
((adjusted_mode->crtc_hsync_end - 1) << 16));
REG_WRITE(map->vblank, (adjusted_mode->crtc_vblank_start - 1) |
((adjusted_mode->crtc_vblank_end - 1) << 16));
REG_WRITE(map->vsync, (adjusted_mode->crtc_vsync_start - 1) |
((adjusted_mode->crtc_vsync_end - 1) << 16));
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
refclk = dev_priv->core_freq * 1000;
dpll = 0;
ok = mrstFindBestPLL(crtc, adjusted_mode->clock, refclk, &clock);
if (!ok) {
dev_dbg(dev->dev, "mrstFindBestPLL fail in oaktrail_crtc_mode_set.\n");
} else {
dev_dbg(dev->dev, "oaktrail_crtc_mode_set pixel clock = %d,"
"m = %x, p1 = %x.\n", clock.dot, clock.m,
clock.p1);
}
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
dpll |= (1 << (clock.p1 - 2)) << 17;
dpll |= DPLL_VCO_ENABLE;
mrstPrintPll("chosen", &clock);
if (dpll & DPLL_VCO_ENABLE) {
REG_WRITE(map->fp0, fp);
REG_WRITE(map->dpll, dpll & ~DPLL_VCO_ENABLE);
REG_READ(map->dpll);
udelay(150);
}
REG_WRITE(map->fp0, fp);
REG_WRITE(map->dpll, dpll);
REG_READ(map->dpll);
udelay(150);
REG_WRITE(map->dpll, dpll);
REG_READ(map->dpll);
udelay(150);
REG_WRITE(map->conf, pipeconf);
REG_READ(map->conf);
psb_intel_wait_for_vblank(dev);
REG_WRITE(map->cntr, dspcntr);
psb_intel_wait_for_vblank(dev);
oaktrail_crtc_mode_set_exit:
gma_power_end(dev);
return 0;
}
static bool oaktrail_crtc_mode_fixup(struct drm_crtc *crtc,
const struct drm_display_mode *mode,
struct drm_display_mode *adjusted_mode)
{
return true;
}
static int oaktrail_pipe_set_base(struct drm_crtc *crtc,
int x, int y, struct drm_framebuffer *old_fb)
{
struct drm_device *dev = crtc->dev;
struct drm_psb_private *dev_priv = dev->dev_private;
struct psb_intel_crtc *psb_intel_crtc = to_psb_intel_crtc(crtc);
struct psb_framebuffer *psbfb = to_psb_fb(crtc->fb);
int pipe = psb_intel_crtc->pipe;
const struct psb_offset *map = &dev_priv->regmap[pipe];
unsigned long start, offset;
u32 dspcntr;
int ret = 0;
if (!crtc->fb) {
dev_dbg(dev->dev, "No FB bound\n");
return 0;
}
if (!gma_power_begin(dev, true))
return 0;
start = psbfb->gtt->offset;
offset = y * crtc->fb->pitches[0] + x * (crtc->fb->bits_per_pixel / 8);
REG_WRITE(map->stride, crtc->fb->pitches[0]);
dspcntr = REG_READ(map->cntr);
dspcntr &= ~DISPPLANE_PIXFORMAT_MASK;
switch (crtc->fb->bits_per_pixel) {
case 8:
dspcntr |= DISPPLANE_8BPP;
break;
case 16:
if (crtc->fb->depth == 15)
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
static void oaktrail_crtc_prepare(struct drm_crtc *crtc)
{
struct drm_crtc_helper_funcs *crtc_funcs = crtc->helper_private;
crtc_funcs->dpms(crtc, DRM_MODE_DPMS_OFF);
}
static void oaktrail_crtc_commit(struct drm_crtc *crtc)
{
struct drm_crtc_helper_funcs *crtc_funcs = crtc->helper_private;
crtc_funcs->dpms(crtc, DRM_MODE_DPMS_ON);
}
