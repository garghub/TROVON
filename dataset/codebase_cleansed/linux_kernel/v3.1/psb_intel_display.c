static const struct psb_intel_limit_t *psb_intel_limit(struct drm_crtc *crtc)
{
const struct psb_intel_limit_t *limit;
if (psb_intel_pipe_has_type(crtc, INTEL_OUTPUT_LVDS))
limit = &psb_intel_limits[INTEL_LIMIT_I9XX_LVDS];
else
limit = &psb_intel_limits[INTEL_LIMIT_I9XX_SDVO_DAC];
return limit;
}
static void i8xx_clock(int refclk, struct psb_intel_clock_t *clock)
{
clock->m = 5 * (clock->m1 + 2) + (clock->m2 + 2);
clock->p = clock->p1 * clock->p2;
clock->vco = refclk * clock->m / (clock->n + 2);
clock->dot = clock->vco / clock->p;
}
static void i9xx_clock(int refclk, struct psb_intel_clock_t *clock)
{
clock->m = 5 * (clock->m1 + 2) + (clock->m2 + 2);
clock->p = clock->p1 * clock->p2;
clock->vco = refclk * clock->m / (clock->n + 2);
clock->dot = clock->vco / clock->p;
}
static void psb_intel_clock(struct drm_device *dev, int refclk,
struct psb_intel_clock_t *clock)
{
return i9xx_clock(refclk, clock);
}
bool psb_intel_pipe_has_type(struct drm_crtc *crtc, int type)
{
struct drm_device *dev = crtc->dev;
struct drm_mode_config *mode_config = &dev->mode_config;
struct drm_connector *l_entry;
list_for_each_entry(l_entry, &mode_config->connector_list, head) {
if (l_entry->encoder && l_entry->encoder->crtc == crtc) {
struct psb_intel_output *psb_intel_output =
to_psb_intel_output(l_entry);
if (psb_intel_output->type == type)
return true;
}
}
return false;
}
static bool psb_intel_PLL_is_valid(struct drm_crtc *crtc,
struct psb_intel_clock_t *clock)
{
const struct psb_intel_limit_t *limit = psb_intel_limit(crtc);
if (clock->p1 < limit->p1.min || limit->p1.max < clock->p1)
INTELPllInvalid("p1 out of range\n");
if (clock->p < limit->p.min || limit->p.max < clock->p)
INTELPllInvalid("p out of range\n");
if (clock->m2 < limit->m2.min || limit->m2.max < clock->m2)
INTELPllInvalid("m2 out of range\n");
if (clock->m1 < limit->m1.min || limit->m1.max < clock->m1)
INTELPllInvalid("m1 out of range\n");
if (clock->m1 <= clock->m2)
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
static bool psb_intel_find_best_PLL(struct drm_crtc *crtc, int target,
int refclk,
struct psb_intel_clock_t *best_clock)
{
struct drm_device *dev = crtc->dev;
struct psb_intel_clock_t clock;
const struct psb_intel_limit_t *limit = psb_intel_limit(crtc);
int err = target;
if (psb_intel_pipe_has_type(crtc, INTEL_OUTPUT_LVDS) &&
(REG_READ(LVDS) & LVDS_PORT_EN) != 0) {
if ((REG_READ(LVDS) & LVDS_CLKB_POWER_MASK) ==
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
clock.m2 < clock.m1 && clock.m2 <= limit->m2.max;
clock.m2++) {
for (clock.n = limit->n.min;
clock.n <= limit->n.max; clock.n++) {
for (clock.p1 = limit->p1.min;
clock.p1 <= limit->p1.max;
clock.p1++) {
int this_err;
psb_intel_clock(dev, refclk, &clock);
if (!psb_intel_PLL_is_valid
(crtc, &clock))
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
return err != target;
}
void psb_intel_wait_for_vblank(struct drm_device *dev)
{
mdelay(20);
}
int psb_intel_pipe_set_base(struct drm_crtc *crtc,
int x, int y, struct drm_framebuffer *old_fb)
{
struct drm_device *dev = crtc->dev;
struct psb_intel_crtc *psb_intel_crtc = to_psb_intel_crtc(crtc);
struct psb_framebuffer *psbfb = to_psb_fb(crtc->fb);
int pipe = psb_intel_crtc->pipe;
unsigned long start, offset;
int dspbase = (pipe == 0 ? DSPABASE : DSPBBASE);
int dspsurf = (pipe == 0 ? DSPASURF : DSPBSURF);
int dspstride = (pipe == 0) ? DSPASTRIDE : DSPBSTRIDE;
int dspcntr_reg = (pipe == 0) ? DSPACNTR : DSPBCNTR;
u32 dspcntr;
int ret = 0;
if (!gma_power_begin(dev, true))
return 0;
if (!crtc->fb) {
dev_dbg(dev->dev, "No FB bound\n");
goto psb_intel_pipe_cleaner;
}
ret = psb_gtt_pin(psbfb->gtt);
if (ret < 0)
goto psb_intel_pipe_set_base_exit;
start = psbfb->gtt->offset;
offset = y * crtc->fb->pitch + x * (crtc->fb->bits_per_pixel / 8);
REG_WRITE(dspstride, crtc->fb->pitch);
dspcntr = REG_READ(dspcntr_reg);
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
psb_gtt_unpin(psbfb->gtt);
goto psb_intel_pipe_set_base_exit;
}
REG_WRITE(dspcntr_reg, dspcntr);
if (0 ) {
REG_WRITE(dspbase, offset);
REG_READ(dspbase);
REG_WRITE(dspsurf, start);
REG_READ(dspsurf);
} else {
REG_WRITE(dspbase, start + offset);
REG_READ(dspbase);
}
psb_intel_pipe_cleaner:
if (old_fb)
psb_gtt_unpin(to_psb_fb(old_fb)->gtt);
psb_intel_pipe_set_base_exit:
gma_power_end(dev);
return ret;
}
static void psb_intel_crtc_dpms(struct drm_crtc *crtc, int mode)
{
struct drm_device *dev = crtc->dev;
struct psb_intel_crtc *psb_intel_crtc = to_psb_intel_crtc(crtc);
int pipe = psb_intel_crtc->pipe;
int dpll_reg = (pipe == 0) ? DPLL_A : DPLL_B;
int dspcntr_reg = (pipe == 0) ? DSPACNTR : DSPBCNTR;
int dspbase_reg = (pipe == 0) ? DSPABASE : DSPBBASE;
int pipeconf_reg = (pipe == 0) ? PIPEACONF : PIPEBCONF;
u32 temp;
bool enabled;
switch (mode) {
case DRM_MODE_DPMS_ON:
case DRM_MODE_DPMS_STANDBY:
case DRM_MODE_DPMS_SUSPEND:
temp = REG_READ(dpll_reg);
if ((temp & DPLL_VCO_ENABLE) == 0) {
REG_WRITE(dpll_reg, temp);
REG_READ(dpll_reg);
udelay(150);
REG_WRITE(dpll_reg, temp | DPLL_VCO_ENABLE);
REG_READ(dpll_reg);
udelay(150);
REG_WRITE(dpll_reg, temp | DPLL_VCO_ENABLE);
REG_READ(dpll_reg);
udelay(150);
}
temp = REG_READ(pipeconf_reg);
if ((temp & PIPEACONF_ENABLE) == 0)
REG_WRITE(pipeconf_reg, temp | PIPEACONF_ENABLE);
temp = REG_READ(dspcntr_reg);
if ((temp & DISPLAY_PLANE_ENABLE) == 0) {
REG_WRITE(dspcntr_reg,
temp | DISPLAY_PLANE_ENABLE);
REG_WRITE(dspbase_reg, REG_READ(dspbase_reg));
}
psb_intel_crtc_load_lut(crtc);
break;
case DRM_MODE_DPMS_OFF:
REG_WRITE(VGACNTRL, VGA_DISP_DISABLE);
temp = REG_READ(dspcntr_reg);
if ((temp & DISPLAY_PLANE_ENABLE) != 0) {
REG_WRITE(dspcntr_reg,
temp & ~DISPLAY_PLANE_ENABLE);
REG_WRITE(dspbase_reg, REG_READ(dspbase_reg));
REG_READ(dspbase_reg);
}
temp = REG_READ(pipeconf_reg);
if ((temp & PIPEACONF_ENABLE) != 0) {
REG_WRITE(pipeconf_reg, temp & ~PIPEACONF_ENABLE);
REG_READ(pipeconf_reg);
}
psb_intel_wait_for_vblank(dev);
temp = REG_READ(dpll_reg);
if ((temp & DPLL_VCO_ENABLE) != 0) {
REG_WRITE(dpll_reg, temp & ~DPLL_VCO_ENABLE);
REG_READ(dpll_reg);
}
udelay(150);
break;
}
enabled = crtc->enabled && mode != DRM_MODE_DPMS_OFF;
REG_WRITE(DSPARB, 0x3F3E);
}
static void psb_intel_crtc_prepare(struct drm_crtc *crtc)
{
struct drm_crtc_helper_funcs *crtc_funcs = crtc->helper_private;
crtc_funcs->dpms(crtc, DRM_MODE_DPMS_OFF);
}
static void psb_intel_crtc_commit(struct drm_crtc *crtc)
{
struct drm_crtc_helper_funcs *crtc_funcs = crtc->helper_private;
crtc_funcs->dpms(crtc, DRM_MODE_DPMS_ON);
}
void psb_intel_encoder_prepare(struct drm_encoder *encoder)
{
struct drm_encoder_helper_funcs *encoder_funcs =
encoder->helper_private;
encoder_funcs->dpms(encoder, DRM_MODE_DPMS_OFF);
}
void psb_intel_encoder_commit(struct drm_encoder *encoder)
{
struct drm_encoder_helper_funcs *encoder_funcs =
encoder->helper_private;
encoder_funcs->dpms(encoder, DRM_MODE_DPMS_ON);
}
static bool psb_intel_crtc_mode_fixup(struct drm_crtc *crtc,
struct drm_display_mode *mode,
struct drm_display_mode *adjusted_mode)
{
return true;
}
static int psb_intel_panel_fitter_pipe(struct drm_device *dev)
{
u32 pfit_control;
pfit_control = REG_READ(PFIT_CONTROL);
if ((pfit_control & PFIT_ENABLE) == 0)
return -1;
return 1;
}
static int psb_intel_crtc_mode_set(struct drm_crtc *crtc,
struct drm_display_mode *mode,
struct drm_display_mode *adjusted_mode,
int x, int y,
struct drm_framebuffer *old_fb)
{
struct drm_device *dev = crtc->dev;
struct psb_intel_crtc *psb_intel_crtc = to_psb_intel_crtc(crtc);
struct drm_crtc_helper_funcs *crtc_funcs = crtc->helper_private;
int pipe = psb_intel_crtc->pipe;
int fp_reg = (pipe == 0) ? FPA0 : FPB0;
int dpll_reg = (pipe == 0) ? DPLL_A : DPLL_B;
int dspcntr_reg = (pipe == 0) ? DSPACNTR : DSPBCNTR;
int pipeconf_reg = (pipe == 0) ? PIPEACONF : PIPEBCONF;
int htot_reg = (pipe == 0) ? HTOTAL_A : HTOTAL_B;
int hblank_reg = (pipe == 0) ? HBLANK_A : HBLANK_B;
int hsync_reg = (pipe == 0) ? HSYNC_A : HSYNC_B;
int vtot_reg = (pipe == 0) ? VTOTAL_A : VTOTAL_B;
int vblank_reg = (pipe == 0) ? VBLANK_A : VBLANK_B;
int vsync_reg = (pipe == 0) ? VSYNC_A : VSYNC_B;
int dspsize_reg = (pipe == 0) ? DSPASIZE : DSPBSIZE;
int dsppos_reg = (pipe == 0) ? DSPAPOS : DSPBPOS;
int pipesrc_reg = (pipe == 0) ? PIPEASRC : PIPEBSRC;
int refclk;
struct psb_intel_clock_t clock;
u32 dpll = 0, fp = 0, dspcntr, pipeconf;
bool ok, is_sdvo = false, is_dvo = false;
bool is_crt = false, is_lvds = false, is_tv = false;
struct drm_mode_config *mode_config = &dev->mode_config;
struct drm_connector *connector;
if (crtc->fb == NULL) {
crtc_funcs->mode_set_base(crtc, x, y, old_fb);
return 0;
}
list_for_each_entry(connector, &mode_config->connector_list, head) {
struct psb_intel_output *psb_intel_output =
to_psb_intel_output(connector);
if (!connector->encoder
|| connector->encoder->crtc != crtc)
continue;
switch (psb_intel_output->type) {
case INTEL_OUTPUT_LVDS:
is_lvds = true;
break;
case INTEL_OUTPUT_SDVO:
is_sdvo = true;
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
}
}
refclk = 96000;
ok = psb_intel_find_best_PLL(crtc, adjusted_mode->clock, refclk,
&clock);
if (!ok) {
dev_err(dev->dev, "Couldn't find PLL settings for mode!\n");
return 0;
}
fp = clock.n << 16 | clock.m1 << 8 | clock.m2;
dpll = DPLL_VGA_MODE_DIS;
if (is_lvds) {
dpll |= DPLLB_MODE_LVDS;
dpll |= DPLL_DVO_HIGH_SPEED;
} else
dpll |= DPLLB_MODE_DAC_SERIAL;
if (is_sdvo) {
int sdvo_pixel_multiply =
adjusted_mode->clock / mode->clock;
dpll |= DPLL_DVO_HIGH_SPEED;
dpll |=
(sdvo_pixel_multiply - 1) << SDVO_MULTIPLIER_SHIFT_HIRES;
}
dpll |= (1 << (clock.p1 - 1)) << 16;
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
if (is_tv) {
dpll |= 3;
}
dpll |= PLL_REF_INPUT_DREFCLK;
pipeconf = REG_READ(pipeconf_reg);
dspcntr = DISPPLANE_GAMMA_ENABLE;
if (pipe == 0)
dspcntr |= DISPPLANE_SEL_PIPE_A;
else
dspcntr |= DISPPLANE_SEL_PIPE_B;
dspcntr |= DISPLAY_PLANE_ENABLE;
pipeconf |= PIPEACONF_ENABLE;
dpll |= DPLL_VCO_ENABLE;
if (psb_intel_panel_fitter_pipe(dev) == pipe)
REG_WRITE(PFIT_CONTROL, 0);
drm_mode_debug_printmodeline(mode);
if (dpll & DPLL_VCO_ENABLE) {
REG_WRITE(fp_reg, fp);
REG_WRITE(dpll_reg, dpll & ~DPLL_VCO_ENABLE);
REG_READ(dpll_reg);
udelay(150);
}
if (is_lvds) {
u32 lvds = REG_READ(LVDS);
lvds &= ~LVDS_PIPEB_SELECT;
if (pipe == 1)
lvds |= LVDS_PIPEB_SELECT;
lvds |= LVDS_PORT_EN | LVDS_A0A2_CLKA_POWER_UP;
lvds &= ~(LVDS_B0B3_POWER_UP | LVDS_CLKB_POWER_UP);
if (clock.p2 == 7)
lvds |= LVDS_B0B3_POWER_UP | LVDS_CLKB_POWER_UP;
REG_WRITE(LVDS, lvds);
REG_READ(LVDS);
}
REG_WRITE(fp_reg, fp);
REG_WRITE(dpll_reg, dpll);
REG_READ(dpll_reg);
udelay(150);
REG_WRITE(dpll_reg, dpll);
REG_READ(dpll_reg);
udelay(150);
REG_WRITE(htot_reg, (adjusted_mode->crtc_hdisplay - 1) |
((adjusted_mode->crtc_htotal - 1) << 16));
REG_WRITE(hblank_reg, (adjusted_mode->crtc_hblank_start - 1) |
((adjusted_mode->crtc_hblank_end - 1) << 16));
REG_WRITE(hsync_reg, (adjusted_mode->crtc_hsync_start - 1) |
((adjusted_mode->crtc_hsync_end - 1) << 16));
REG_WRITE(vtot_reg, (adjusted_mode->crtc_vdisplay - 1) |
((adjusted_mode->crtc_vtotal - 1) << 16));
REG_WRITE(vblank_reg, (adjusted_mode->crtc_vblank_start - 1) |
((adjusted_mode->crtc_vblank_end - 1) << 16));
REG_WRITE(vsync_reg, (adjusted_mode->crtc_vsync_start - 1) |
((adjusted_mode->crtc_vsync_end - 1) << 16));
REG_WRITE(dspsize_reg,
((mode->vdisplay - 1) << 16) | (mode->hdisplay - 1));
REG_WRITE(dsppos_reg, 0);
REG_WRITE(pipesrc_reg,
((mode->hdisplay - 1) << 16) | (mode->vdisplay - 1));
REG_WRITE(pipeconf_reg, pipeconf);
REG_READ(pipeconf_reg);
psb_intel_wait_for_vblank(dev);
REG_WRITE(dspcntr_reg, dspcntr);
crtc_funcs->mode_set_base(crtc, x, y, old_fb);
psb_intel_wait_for_vblank(dev);
return 0;
}
void psb_intel_crtc_load_lut(struct drm_crtc *crtc)
{
struct drm_device *dev = crtc->dev;
struct drm_psb_private *dev_priv =
(struct drm_psb_private *)dev->dev_private;
struct psb_intel_crtc *psb_intel_crtc = to_psb_intel_crtc(crtc);
int palreg = PALETTE_A;
int i;
if (!crtc->enabled)
return;
switch (psb_intel_crtc->pipe) {
case 0:
break;
case 1:
palreg = PALETTE_B;
break;
case 2:
palreg = PALETTE_C;
break;
default:
dev_err(dev->dev, "Illegal Pipe Number.\n");
return;
}
if (gma_power_begin(dev, false)) {
for (i = 0; i < 256; i++) {
REG_WRITE(palreg + 4 * i,
((psb_intel_crtc->lut_r[i] +
psb_intel_crtc->lut_adj[i]) << 16) |
((psb_intel_crtc->lut_g[i] +
psb_intel_crtc->lut_adj[i]) << 8) |
(psb_intel_crtc->lut_b[i] +
psb_intel_crtc->lut_adj[i]));
}
gma_power_end(dev);
} else {
for (i = 0; i < 256; i++) {
dev_priv->save_palette_a[i] =
((psb_intel_crtc->lut_r[i] +
psb_intel_crtc->lut_adj[i]) << 16) |
((psb_intel_crtc->lut_g[i] +
psb_intel_crtc->lut_adj[i]) << 8) |
(psb_intel_crtc->lut_b[i] +
psb_intel_crtc->lut_adj[i]);
}
}
}
static void psb_intel_crtc_save(struct drm_crtc *crtc)
{
struct drm_device *dev = crtc->dev;
struct psb_intel_crtc *psb_intel_crtc = to_psb_intel_crtc(crtc);
struct psb_intel_crtc_state *crtc_state = psb_intel_crtc->crtc_state;
int pipeA = (psb_intel_crtc->pipe == 0);
uint32_t paletteReg;
int i;
if (!crtc_state) {
dev_err(dev->dev, "No CRTC state found\n");
return;
}
crtc_state->saveDSPCNTR = REG_READ(pipeA ? DSPACNTR : DSPBCNTR);
crtc_state->savePIPECONF = REG_READ(pipeA ? PIPEACONF : PIPEBCONF);
crtc_state->savePIPESRC = REG_READ(pipeA ? PIPEASRC : PIPEBSRC);
crtc_state->saveFP0 = REG_READ(pipeA ? FPA0 : FPB0);
crtc_state->saveFP1 = REG_READ(pipeA ? FPA1 : FPB1);
crtc_state->saveDPLL = REG_READ(pipeA ? DPLL_A : DPLL_B);
crtc_state->saveHTOTAL = REG_READ(pipeA ? HTOTAL_A : HTOTAL_B);
crtc_state->saveHBLANK = REG_READ(pipeA ? HBLANK_A : HBLANK_B);
crtc_state->saveHSYNC = REG_READ(pipeA ? HSYNC_A : HSYNC_B);
crtc_state->saveVTOTAL = REG_READ(pipeA ? VTOTAL_A : VTOTAL_B);
crtc_state->saveVBLANK = REG_READ(pipeA ? VBLANK_A : VBLANK_B);
crtc_state->saveVSYNC = REG_READ(pipeA ? VSYNC_A : VSYNC_B);
crtc_state->saveDSPSTRIDE = REG_READ(pipeA ? DSPASTRIDE : DSPBSTRIDE);
crtc_state->saveDSPSIZE = REG_READ(pipeA ? DSPASIZE : DSPBSIZE);
crtc_state->saveDSPPOS = REG_READ(pipeA ? DSPAPOS : DSPBPOS);
crtc_state->saveDSPBASE = REG_READ(pipeA ? DSPABASE : DSPBBASE);
paletteReg = pipeA ? PALETTE_A : PALETTE_B;
for (i = 0; i < 256; ++i)
crtc_state->savePalette[i] = REG_READ(paletteReg + (i << 2));
}
static void psb_intel_crtc_restore(struct drm_crtc *crtc)
{
struct drm_device *dev = crtc->dev;
struct psb_intel_crtc *psb_intel_crtc = to_psb_intel_crtc(crtc);
struct psb_intel_crtc_state *crtc_state = psb_intel_crtc->crtc_state;
int pipeA = (psb_intel_crtc->pipe == 0);
uint32_t paletteReg;
int i;
if (!crtc_state) {
dev_err(dev->dev, "No crtc state\n");
return;
}
if (crtc_state->saveDPLL & DPLL_VCO_ENABLE) {
REG_WRITE(pipeA ? DPLL_A : DPLL_B,
crtc_state->saveDPLL & ~DPLL_VCO_ENABLE);
REG_READ(pipeA ? DPLL_A : DPLL_B);
udelay(150);
}
REG_WRITE(pipeA ? FPA0 : FPB0, crtc_state->saveFP0);
REG_READ(pipeA ? FPA0 : FPB0);
REG_WRITE(pipeA ? FPA1 : FPB1, crtc_state->saveFP1);
REG_READ(pipeA ? FPA1 : FPB1);
REG_WRITE(pipeA ? DPLL_A : DPLL_B, crtc_state->saveDPLL);
REG_READ(pipeA ? DPLL_A : DPLL_B);
udelay(150);
REG_WRITE(pipeA ? HTOTAL_A : HTOTAL_B, crtc_state->saveHTOTAL);
REG_WRITE(pipeA ? HBLANK_A : HBLANK_B, crtc_state->saveHBLANK);
REG_WRITE(pipeA ? HSYNC_A : HSYNC_B, crtc_state->saveHSYNC);
REG_WRITE(pipeA ? VTOTAL_A : VTOTAL_B, crtc_state->saveVTOTAL);
REG_WRITE(pipeA ? VBLANK_A : VBLANK_B, crtc_state->saveVBLANK);
REG_WRITE(pipeA ? VSYNC_A : VSYNC_B, crtc_state->saveVSYNC);
REG_WRITE(pipeA ? DSPASTRIDE : DSPBSTRIDE, crtc_state->saveDSPSTRIDE);
REG_WRITE(pipeA ? DSPASIZE : DSPBSIZE, crtc_state->saveDSPSIZE);
REG_WRITE(pipeA ? DSPAPOS : DSPBPOS, crtc_state->saveDSPPOS);
REG_WRITE(pipeA ? PIPEASRC : PIPEBSRC, crtc_state->savePIPESRC);
REG_WRITE(pipeA ? DSPABASE : DSPBBASE, crtc_state->saveDSPBASE);
REG_WRITE(pipeA ? PIPEACONF : PIPEBCONF, crtc_state->savePIPECONF);
psb_intel_wait_for_vblank(dev);
REG_WRITE(pipeA ? DSPACNTR : DSPBCNTR, crtc_state->saveDSPCNTR);
REG_WRITE(pipeA ? DSPABASE : DSPBBASE, crtc_state->saveDSPBASE);
psb_intel_wait_for_vblank(dev);
paletteReg = pipeA ? PALETTE_A : PALETTE_B;
for (i = 0; i < 256; ++i)
REG_WRITE(paletteReg + (i << 2), crtc_state->savePalette[i]);
}
static int psb_intel_crtc_cursor_set(struct drm_crtc *crtc,
struct drm_file *file_priv,
uint32_t handle,
uint32_t width, uint32_t height)
{
struct drm_device *dev = crtc->dev;
struct psb_intel_crtc *psb_intel_crtc = to_psb_intel_crtc(crtc);
int pipe = psb_intel_crtc->pipe;
uint32_t control = (pipe == 0) ? CURACNTR : CURBCNTR;
uint32_t base = (pipe == 0) ? CURABASE : CURBBASE;
uint32_t temp;
size_t addr = 0;
struct gtt_range *gt;
struct drm_gem_object *obj;
int ret;
if (!handle) {
temp = CURSOR_MODE_DISABLE;
if (gma_power_begin(dev, false)) {
REG_WRITE(control, temp);
REG_WRITE(base, 0);
gma_power_end(dev);
}
if (psb_intel_crtc->cursor_obj) {
gt = container_of(psb_intel_crtc->cursor_obj,
struct gtt_range, gem);
psb_gtt_unpin(gt);
drm_gem_object_unreference(psb_intel_crtc->cursor_obj);
psb_intel_crtc->cursor_obj = NULL;
}
return 0;
}
if (width != 64 || height != 64) {
dev_dbg(dev->dev, "we currently only support 64x64 cursors\n");
return -EINVAL;
}
obj = drm_gem_object_lookup(dev, file_priv, handle);
if (!obj)
return -ENOENT;
if (obj->size < width * height * 4) {
dev_dbg(dev->dev, "buffer is to small\n");
return -ENOMEM;
}
gt = container_of(obj, struct gtt_range, gem);
ret = psb_gtt_pin(gt);
if (ret) {
dev_err(dev->dev, "Can not pin down handle 0x%x\n", handle);
return ret;
}
addr = gt->offset;
psb_intel_crtc->cursor_addr = addr;
temp = 0;
temp |= (pipe << 28);
temp |= CURSOR_MODE_64_ARGB_AX | MCURSOR_GAMMA_ENABLE;
if (gma_power_begin(dev, false)) {
REG_WRITE(control, temp);
REG_WRITE(base, addr);
gma_power_end(dev);
}
if (psb_intel_crtc->cursor_obj) {
gt = container_of(psb_intel_crtc->cursor_obj,
struct gtt_range, gem);
psb_gtt_unpin(gt);
drm_gem_object_unreference(psb_intel_crtc->cursor_obj);
psb_intel_crtc->cursor_obj = obj;
}
return 0;
}
static int psb_intel_crtc_cursor_move(struct drm_crtc *crtc, int x, int y)
{
struct drm_device *dev = crtc->dev;
struct psb_intel_crtc *psb_intel_crtc = to_psb_intel_crtc(crtc);
int pipe = psb_intel_crtc->pipe;
uint32_t temp = 0;
uint32_t addr;
if (x < 0) {
temp |= (CURSOR_POS_SIGN << CURSOR_X_SHIFT);
x = -x;
}
if (y < 0) {
temp |= (CURSOR_POS_SIGN << CURSOR_Y_SHIFT);
y = -y;
}
temp |= ((x & CURSOR_POS_MASK) << CURSOR_X_SHIFT);
temp |= ((y & CURSOR_POS_MASK) << CURSOR_Y_SHIFT);
addr = psb_intel_crtc->cursor_addr;
if (gma_power_begin(dev, false)) {
REG_WRITE((pipe == 0) ? CURAPOS : CURBPOS, temp);
REG_WRITE((pipe == 0) ? CURABASE : CURBBASE, addr);
gma_power_end(dev);
}
return 0;
}
void psb_intel_crtc_gamma_set(struct drm_crtc *crtc, u16 *red,
u16 *green, u16 *blue, uint32_t type, uint32_t size)
{
struct psb_intel_crtc *psb_intel_crtc = to_psb_intel_crtc(crtc);
int i;
if (size != 256)
return;
for (i = 0; i < 256; i++) {
psb_intel_crtc->lut_r[i] = red[i] >> 8;
psb_intel_crtc->lut_g[i] = green[i] >> 8;
psb_intel_crtc->lut_b[i] = blue[i] >> 8;
}
psb_intel_crtc_load_lut(crtc);
}
static int psb_crtc_set_config(struct drm_mode_set *set)
{
int ret;
struct drm_device *dev = set->crtc->dev;
struct drm_psb_private *dev_priv = dev->dev_private;
if (!dev_priv->rpm_enabled)
return drm_crtc_helper_set_config(set);
pm_runtime_forbid(&dev->pdev->dev);
ret = drm_crtc_helper_set_config(set);
pm_runtime_allow(&dev->pdev->dev);
return ret;
}
static int psb_intel_crtc_clock_get(struct drm_device *dev,
struct drm_crtc *crtc)
{
struct psb_intel_crtc *psb_intel_crtc = to_psb_intel_crtc(crtc);
int pipe = psb_intel_crtc->pipe;
u32 dpll;
u32 fp;
struct psb_intel_clock_t clock;
bool is_lvds;
struct drm_psb_private *dev_priv = dev->dev_private;
if (gma_power_begin(dev, false)) {
dpll = REG_READ((pipe == 0) ? DPLL_A : DPLL_B);
if ((dpll & DISPLAY_RATE_SELECT_FPA1) == 0)
fp = REG_READ((pipe == 0) ? FPA0 : FPB0);
else
fp = REG_READ((pipe == 0) ? FPA1 : FPB1);
is_lvds = (pipe == 1) && (REG_READ(LVDS) & LVDS_PORT_EN);
gma_power_end(dev);
} else {
dpll = (pipe == 0) ?
dev_priv->saveDPLL_A : dev_priv->saveDPLL_B;
if ((dpll & DISPLAY_RATE_SELECT_FPA1) == 0)
fp = (pipe == 0) ?
dev_priv->saveFPA0 :
dev_priv->saveFPB0;
else
fp = (pipe == 0) ?
dev_priv->saveFPA1 :
dev_priv->saveFPB1;
is_lvds = (pipe == 1) && (dev_priv->saveLVDS & LVDS_PORT_EN);
}
clock.m1 = (fp & FP_M1_DIV_MASK) >> FP_M1_DIV_SHIFT;
clock.m2 = (fp & FP_M2_DIV_MASK) >> FP_M2_DIV_SHIFT;
clock.n = (fp & FP_N_DIV_MASK) >> FP_N_DIV_SHIFT;
if (is_lvds) {
clock.p1 =
ffs((dpll &
DPLL_FPA01_P1_POST_DIV_MASK_I830_LVDS) >>
DPLL_FPA01_P1_POST_DIV_SHIFT);
clock.p2 = 14;
if ((dpll & PLL_REF_INPUT_MASK) ==
PLLB_REF_INPUT_SPREADSPECTRUMIN) {
i8xx_clock(66000, &clock);
} else
i8xx_clock(48000, &clock);
} else {
if (dpll & PLL_P1_DIVIDE_BY_TWO)
clock.p1 = 2;
else {
clock.p1 =
((dpll &
DPLL_FPA01_P1_POST_DIV_MASK_I830) >>
DPLL_FPA01_P1_POST_DIV_SHIFT) + 2;
}
if (dpll & PLL_P2_DIVIDE_BY_4)
clock.p2 = 4;
else
clock.p2 = 2;
i8xx_clock(48000, &clock);
}
return clock.dot;
}
struct drm_display_mode *psb_intel_crtc_mode_get(struct drm_device *dev,
struct drm_crtc *crtc)
{
struct psb_intel_crtc *psb_intel_crtc = to_psb_intel_crtc(crtc);
int pipe = psb_intel_crtc->pipe;
struct drm_display_mode *mode;
int htot;
int hsync;
int vtot;
int vsync;
struct drm_psb_private *dev_priv = dev->dev_private;
if (gma_power_begin(dev, false)) {
htot = REG_READ((pipe == 0) ? HTOTAL_A : HTOTAL_B);
hsync = REG_READ((pipe == 0) ? HSYNC_A : HSYNC_B);
vtot = REG_READ((pipe == 0) ? VTOTAL_A : VTOTAL_B);
vsync = REG_READ((pipe == 0) ? VSYNC_A : VSYNC_B);
gma_power_end(dev);
} else {
htot = (pipe == 0) ?
dev_priv->saveHTOTAL_A : dev_priv->saveHTOTAL_B;
hsync = (pipe == 0) ?
dev_priv->saveHSYNC_A : dev_priv->saveHSYNC_B;
vtot = (pipe == 0) ?
dev_priv->saveVTOTAL_A : dev_priv->saveVTOTAL_B;
vsync = (pipe == 0) ?
dev_priv->saveVSYNC_A : dev_priv->saveVSYNC_B;
}
mode = kzalloc(sizeof(*mode), GFP_KERNEL);
if (!mode)
return NULL;
mode->clock = psb_intel_crtc_clock_get(dev, crtc);
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
void psb_intel_crtc_destroy(struct drm_crtc *crtc)
{
struct psb_intel_crtc *psb_intel_crtc = to_psb_intel_crtc(crtc);
struct gtt_range *gt;
if (psb_intel_crtc->cursor_obj) {
gt = container_of(psb_intel_crtc->cursor_obj,
struct gtt_range, gem);
psb_gtt_unpin(gt);
drm_gem_object_unreference(psb_intel_crtc->cursor_obj);
psb_intel_crtc->cursor_obj = NULL;
}
kfree(psb_intel_crtc->crtc_state);
drm_crtc_cleanup(crtc);
kfree(psb_intel_crtc);
}
static void psb_intel_cursor_init(struct drm_device *dev, int pipe)
{
u32 control[3] = { CURACNTR, CURBCNTR, CURCCNTR };
u32 base[3] = { CURABASE, CURBBASE, CURCBASE };
REG_WRITE(control[pipe], 0);
REG_WRITE(base[pipe], 0);
}
void psb_intel_crtc_init(struct drm_device *dev, int pipe,
struct psb_intel_mode_device *mode_dev)
{
struct drm_psb_private *dev_priv = dev->dev_private;
struct psb_intel_crtc *psb_intel_crtc;
int i;
uint16_t *r_base, *g_base, *b_base;
psb_intel_crtc =
kzalloc(sizeof(struct psb_intel_crtc) +
(INTELFB_CONN_LIMIT * sizeof(struct drm_connector *)),
GFP_KERNEL);
if (psb_intel_crtc == NULL)
return;
psb_intel_crtc->crtc_state =
kzalloc(sizeof(struct psb_intel_crtc_state), GFP_KERNEL);
if (!psb_intel_crtc->crtc_state) {
dev_err(dev->dev, "Crtc state error: No memory\n");
kfree(psb_intel_crtc);
return;
}
drm_crtc_init(dev, &psb_intel_crtc->base, dev_priv->ops->crtc_funcs);
drm_mode_crtc_set_gamma_size(&psb_intel_crtc->base, 256);
psb_intel_crtc->pipe = pipe;
psb_intel_crtc->plane = pipe;
r_base = psb_intel_crtc->base.gamma_store;
g_base = r_base + 256;
b_base = g_base + 256;
for (i = 0; i < 256; i++) {
psb_intel_crtc->lut_r[i] = i;
psb_intel_crtc->lut_g[i] = i;
psb_intel_crtc->lut_b[i] = i;
r_base[i] = i << 8;
g_base[i] = i << 8;
b_base[i] = i << 8;
psb_intel_crtc->lut_adj[i] = 0;
}
psb_intel_crtc->mode_dev = mode_dev;
psb_intel_crtc->cursor_addr = 0;
drm_crtc_helper_add(&psb_intel_crtc->base,
dev_priv->ops->crtc_helper);
psb_intel_crtc->mode_set.crtc = &psb_intel_crtc->base;
BUG_ON(pipe >= ARRAY_SIZE(dev_priv->plane_to_crtc_mapping) ||
dev_priv->plane_to_crtc_mapping[psb_intel_crtc->plane] != NULL);
dev_priv->plane_to_crtc_mapping[psb_intel_crtc->plane] =
&psb_intel_crtc->base;
dev_priv->pipe_to_crtc_mapping[psb_intel_crtc->pipe] =
&psb_intel_crtc->base;
psb_intel_crtc->mode_set.connectors =
(struct drm_connector **) (psb_intel_crtc + 1);
psb_intel_crtc->mode_set.num_connectors = 0;
psb_intel_cursor_init(dev, pipe);
}
int psb_intel_get_pipe_from_crtc_id(struct drm_device *dev, void *data,
struct drm_file *file_priv)
{
struct drm_psb_private *dev_priv = dev->dev_private;
struct drm_psb_get_pipe_from_crtc_id_arg *pipe_from_crtc_id = data;
struct drm_mode_object *drmmode_obj;
struct psb_intel_crtc *crtc;
if (!dev_priv) {
dev_err(dev->dev, "called with no initialization\n");
return -EINVAL;
}
drmmode_obj = drm_mode_object_find(dev, pipe_from_crtc_id->crtc_id,
DRM_MODE_OBJECT_CRTC);
if (!drmmode_obj) {
dev_err(dev->dev, "no such CRTC id\n");
return -EINVAL;
}
crtc = to_psb_intel_crtc(obj_to_crtc(drmmode_obj));
pipe_from_crtc_id->pipe = crtc->pipe;
return 0;
}
struct drm_crtc *psb_intel_get_crtc_from_pipe(struct drm_device *dev, int pipe)
{
struct drm_crtc *crtc = NULL;
list_for_each_entry(crtc, &dev->mode_config.crtc_list, head) {
struct psb_intel_crtc *psb_intel_crtc = to_psb_intel_crtc(crtc);
if (psb_intel_crtc->pipe == pipe)
break;
}
return crtc;
}
int psb_intel_connector_clones(struct drm_device *dev, int type_mask)
{
int index_mask = 0;
struct drm_connector *connector;
int entry = 0;
list_for_each_entry(connector, &dev->mode_config.connector_list,
head) {
struct psb_intel_output *psb_intel_output =
to_psb_intel_output(connector);
if (type_mask & (1 << psb_intel_output->type))
index_mask |= (1 << entry);
entry++;
}
return index_mask;
}
void psb_intel_modeset_cleanup(struct drm_device *dev)
{
drm_mode_config_cleanup(dev);
}
struct drm_encoder *psb_intel_best_encoder(struct drm_connector *connector)
{
struct psb_intel_output *psb_intel_output =
to_psb_intel_output(connector);
return &psb_intel_output->enc;
}
