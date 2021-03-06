static int cdv_sb_read(struct drm_device *dev, u32 reg, u32 *val)
{
int ret;
ret = wait_for((REG_READ(SB_PCKT) & SB_BUSY) == 0, 1000);
if (ret) {
DRM_ERROR("timeout waiting for SB to idle before read\n");
return ret;
}
REG_WRITE(SB_ADDR, reg);
REG_WRITE(SB_PCKT,
SET_FIELD(SB_OPCODE_READ, SB_OPCODE) |
SET_FIELD(SB_DEST_DPLL, SB_DEST) |
SET_FIELD(0xf, SB_BYTE_ENABLE));
ret = wait_for((REG_READ(SB_PCKT) & SB_BUSY) == 0, 1000);
if (ret) {
DRM_ERROR("timeout waiting for SB to idle after read\n");
return ret;
}
*val = REG_READ(SB_DATA);
return 0;
}
static int cdv_sb_write(struct drm_device *dev, u32 reg, u32 val)
{
int ret;
static bool dpio_debug = true;
u32 temp;
if (dpio_debug) {
if (cdv_sb_read(dev, reg, &temp) == 0)
DRM_DEBUG_KMS("0x%08x: 0x%08x (before)\n", reg, temp);
DRM_DEBUG_KMS("0x%08x: 0x%08x\n", reg, val);
}
ret = wait_for((REG_READ(SB_PCKT) & SB_BUSY) == 0, 1000);
if (ret) {
DRM_ERROR("timeout waiting for SB to idle before write\n");
return ret;
}
REG_WRITE(SB_ADDR, reg);
REG_WRITE(SB_DATA, val);
REG_WRITE(SB_PCKT,
SET_FIELD(SB_OPCODE_WRITE, SB_OPCODE) |
SET_FIELD(SB_DEST_DPLL, SB_DEST) |
SET_FIELD(0xf, SB_BYTE_ENABLE));
ret = wait_for((REG_READ(SB_PCKT) & SB_BUSY) == 0, 1000);
if (ret) {
DRM_ERROR("timeout waiting for SB to idle after write\n");
return ret;
}
if (dpio_debug) {
if (cdv_sb_read(dev, reg, &temp) == 0)
DRM_DEBUG_KMS("0x%08x: 0x%08x (after)\n", reg, temp);
}
return 0;
}
static void cdv_sb_reset(struct drm_device *dev)
{
REG_WRITE(DPIO_CFG, 0);
REG_READ(DPIO_CFG);
REG_WRITE(DPIO_CFG, DPIO_MODE_SELECT_0 | DPIO_CMN_RESET_N);
}
static int
cdv_dpll_set_clock_cdv(struct drm_device *dev, struct drm_crtc *crtc,
struct cdv_intel_clock_t *clock)
{
struct psb_intel_crtc *psb_crtc =
to_psb_intel_crtc(crtc);
int pipe = psb_crtc->pipe;
u32 m, n_vco, p;
int ret = 0;
int dpll_reg = (pipe == 0) ? DPLL_A : DPLL_B;
u32 ref_value;
cdv_sb_reset(dev);
if ((REG_READ(dpll_reg) & DPLL_SYNCLOCK_ENABLE) == 0) {
DRM_ERROR("Attempting to set DPLL with refclk disabled\n");
return -EBUSY;
}
ref_value = 0x68A701;
cdv_sb_write(dev, SB_REF_SFR(pipe), ref_value);
ret = cdv_sb_read(dev, SB_M(pipe), &m);
if (ret)
return ret;
m &= ~SB_M_DIVIDER_MASK;
m |= ((clock->m2) << SB_M_DIVIDER_SHIFT);
ret = cdv_sb_write(dev, SB_M(pipe), m);
if (ret)
return ret;
ret = cdv_sb_read(dev, SB_N_VCO(pipe), &n_vco);
if (ret)
return ret;
n_vco &= 0xFFFF;
n_vco |= 0x107;
n_vco &= ~(SB_N_VCO_SEL_MASK |
SB_N_DIVIDER_MASK |
SB_N_CB_TUNE_MASK);
n_vco |= ((clock->n) << SB_N_DIVIDER_SHIFT);
if (clock->vco < 2250000) {
n_vco |= (2 << SB_N_CB_TUNE_SHIFT);
n_vco |= (0 << SB_N_VCO_SEL_SHIFT);
} else if (clock->vco < 2750000) {
n_vco |= (1 << SB_N_CB_TUNE_SHIFT);
n_vco |= (1 << SB_N_VCO_SEL_SHIFT);
} else if (clock->vco < 3300000) {
n_vco |= (0 << SB_N_CB_TUNE_SHIFT);
n_vco |= (2 << SB_N_VCO_SEL_SHIFT);
} else {
n_vco |= (0 << SB_N_CB_TUNE_SHIFT);
n_vco |= (3 << SB_N_VCO_SEL_SHIFT);
}
ret = cdv_sb_write(dev, SB_N_VCO(pipe), n_vco);
if (ret)
return ret;
ret = cdv_sb_read(dev, SB_P(pipe), &p);
if (ret)
return ret;
p &= ~(SB_P2_DIVIDER_MASK | SB_P1_DIVIDER_MASK);
p |= SET_FIELD(clock->p1, SB_P1_DIVIDER);
switch (clock->p2) {
case 5:
p |= SET_FIELD(SB_P2_5, SB_P2_DIVIDER);
break;
case 10:
p |= SET_FIELD(SB_P2_10, SB_P2_DIVIDER);
break;
case 14:
p |= SET_FIELD(SB_P2_14, SB_P2_DIVIDER);
break;
case 7:
p |= SET_FIELD(SB_P2_7, SB_P2_DIVIDER);
break;
default:
DRM_ERROR("Bad P2 clock: %d\n", clock->p2);
return -EINVAL;
}
ret = cdv_sb_write(dev, SB_P(pipe), p);
if (ret)
return ret;
if (pipe == 0) {
u32 lane_reg, lane_value;
lane_reg = PSB_LANE0;
cdv_sb_read(dev, lane_reg, &lane_value);
lane_value &= ~(LANE_PLL_MASK);
lane_value |= LANE_PLL_ENABLE;
cdv_sb_write(dev, lane_reg, lane_value);
lane_reg = PSB_LANE1;
cdv_sb_read(dev, lane_reg, &lane_value);
lane_value &= ~(LANE_PLL_MASK);
lane_value |= LANE_PLL_ENABLE;
cdv_sb_write(dev, lane_reg, lane_value);
lane_reg = PSB_LANE2;
cdv_sb_read(dev, lane_reg, &lane_value);
lane_value &= ~(LANE_PLL_MASK);
lane_value |= LANE_PLL_ENABLE;
cdv_sb_write(dev, lane_reg, lane_value);
lane_reg = PSB_LANE3;
cdv_sb_read(dev, lane_reg, &lane_value);
lane_value &= ~(LANE_PLL_MASK);
lane_value |= LANE_PLL_ENABLE;
cdv_sb_write(dev, lane_reg, lane_value);
}
return 0;
}
bool cdv_intel_pipe_has_type(struct drm_crtc *crtc, int type)
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
static const struct cdv_intel_limit_t *cdv_intel_limit(struct drm_crtc *crtc,
int refclk)
{
const struct cdv_intel_limit_t *limit;
if (cdv_intel_pipe_has_type(crtc, INTEL_OUTPUT_LVDS)) {
if (refclk == 96000)
limit = &cdv_intel_limits[CDV_LIMIT_SINGLE_LVDS_96];
else
limit = &cdv_intel_limits[CDV_LIMIT_SINGLE_LVDS_100];
} else {
if (refclk == 27000)
limit = &cdv_intel_limits[CDV_LIMIT_DAC_HDMI_27];
else
limit = &cdv_intel_limits[CDV_LIMIT_DAC_HDMI_96];
}
return limit;
}
static void cdv_intel_clock(struct drm_device *dev,
int refclk, struct cdv_intel_clock_t *clock)
{
clock->m = clock->m2 + 2;
clock->p = clock->p1 * clock->p2;
clock->vco = (refclk * clock->m) / clock->n;
clock->dot = clock->vco / clock->p;
}
static bool cdv_intel_PLL_is_valid(struct drm_crtc *crtc,
const struct cdv_intel_limit_t *limit,
struct cdv_intel_clock_t *clock)
{
if (clock->p1 < limit->p1.min || limit->p1.max < clock->p1)
INTELPllInvalid("p1 out of range\n");
if (clock->p < limit->p.min || limit->p.max < clock->p)
INTELPllInvalid("p out of range\n");
if (clock->vco < limit->vco.min || limit->vco.max < clock->vco)
INTELPllInvalid("vco out of range\n");
if (clock->dot < limit->dot.min || limit->dot.max < clock->dot)
INTELPllInvalid("dot out of range\n");
return true;
}
static bool cdv_intel_find_best_PLL(struct drm_crtc *crtc, int target,
int refclk,
struct cdv_intel_clock_t *best_clock)
{
struct drm_device *dev = crtc->dev;
struct cdv_intel_clock_t clock;
const struct cdv_intel_limit_t *limit = cdv_intel_limit(crtc, refclk);
int err = target;
if (cdv_intel_pipe_has_type(crtc, INTEL_OUTPUT_LVDS) &&
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
clock.m1 = 0;
for (clock.n = limit->n.min; clock.n <= limit->n.max; clock.n++) {
for (clock.m2 = limit->m2.min; clock.m2 <= limit->m2.max;
clock.m2++) {
for (clock.p1 = limit->p1.min;
clock.p1 <= limit->p1.max;
clock.p1++) {
int this_err;
cdv_intel_clock(dev, refclk, &clock);
if (!cdv_intel_PLL_is_valid(crtc,
limit, &clock))
continue;
this_err = abs(clock.dot - target);
if (this_err < err) {
*best_clock = clock;
err = this_err;
}
}
}
}
return err != target;
}
int cdv_intel_pipe_set_base(struct drm_crtc *crtc,
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
dev_err(dev->dev, "No FB bound\n");
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
goto psb_intel_pipe_set_base_exit;
}
REG_WRITE(dspcntr_reg, dspcntr);
dev_dbg(dev->dev,
"Writing base %08lX %08lX %d %d\n", start, offset, x, y);
REG_WRITE(dspbase, offset);
REG_READ(dspbase);
REG_WRITE(dspsurf, start);
REG_READ(dspsurf);
psb_intel_pipe_cleaner:
if (old_fb)
psb_gtt_unpin(to_psb_fb(old_fb)->gtt);
psb_intel_pipe_set_base_exit:
gma_power_end(dev);
return ret;
}
static void cdv_intel_crtc_dpms(struct drm_crtc *crtc, int mode)
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
temp = REG_READ(dspcntr_reg);
if ((temp & DISPLAY_PLANE_ENABLE) == 0) {
REG_WRITE(dspcntr_reg,
temp | DISPLAY_PLANE_ENABLE);
REG_WRITE(dspbase_reg, REG_READ(dspbase_reg));
}
udelay(150);
temp = REG_READ(pipeconf_reg);
if ((temp & PIPEACONF_ENABLE) == 0)
REG_WRITE(pipeconf_reg, temp | PIPEACONF_ENABLE);
psb_intel_crtc_load_lut(crtc);
break;
case DRM_MODE_DPMS_OFF:
REG_WRITE(VGACNTRL, VGA_DISP_DISABLE);
cdv_intel_wait_for_vblank(dev);
temp = REG_READ(pipeconf_reg);
if ((temp & PIPEACONF_ENABLE) != 0) {
REG_WRITE(pipeconf_reg, temp & ~PIPEACONF_ENABLE);
REG_READ(pipeconf_reg);
}
cdv_intel_wait_for_vblank(dev);
udelay(150);
temp = REG_READ(dspcntr_reg);
if ((temp & DISPLAY_PLANE_ENABLE) != 0) {
REG_WRITE(dspcntr_reg,
temp & ~DISPLAY_PLANE_ENABLE);
REG_WRITE(dspbase_reg, REG_READ(dspbase_reg));
REG_READ(dspbase_reg);
}
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
static void cdv_intel_crtc_prepare(struct drm_crtc *crtc)
{
struct drm_crtc_helper_funcs *crtc_funcs = crtc->helper_private;
crtc_funcs->dpms(crtc, DRM_MODE_DPMS_OFF);
}
static void cdv_intel_crtc_commit(struct drm_crtc *crtc)
{
struct drm_crtc_helper_funcs *crtc_funcs = crtc->helper_private;
crtc_funcs->dpms(crtc, DRM_MODE_DPMS_ON);
}
void cdv_intel_encoder_prepare(struct drm_encoder *encoder)
{
struct drm_encoder_helper_funcs *encoder_funcs =
encoder->helper_private;
encoder_funcs->dpms(encoder, DRM_MODE_DPMS_OFF);
}
void cdv_intel_encoder_commit(struct drm_encoder *encoder)
{
struct drm_encoder_helper_funcs *encoder_funcs =
encoder->helper_private;
encoder_funcs->dpms(encoder, DRM_MODE_DPMS_ON);
}
static bool cdv_intel_crtc_mode_fixup(struct drm_crtc *crtc,
struct drm_display_mode *mode,
struct drm_display_mode *adjusted_mode)
{
return true;
}
static int cdv_intel_panel_fitter_pipe(struct drm_device *dev)
{
u32 pfit_control;
pfit_control = REG_READ(PFIT_CONTROL);
if ((pfit_control & PFIT_ENABLE) == 0)
return -1;
return (pfit_control >> 29) & 0x3;
}
static int cdv_intel_crtc_mode_set(struct drm_crtc *crtc,
struct drm_display_mode *mode,
struct drm_display_mode *adjusted_mode,
int x, int y,
struct drm_framebuffer *old_fb)
{
struct drm_device *dev = crtc->dev;
struct psb_intel_crtc *psb_intel_crtc = to_psb_intel_crtc(crtc);
int pipe = psb_intel_crtc->pipe;
int dpll_reg = (pipe == 0) ? DPLL_A : DPLL_B;
int dpll_md_reg = (psb_intel_crtc->pipe == 0) ? DPLL_A_MD : DPLL_B_MD;
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
struct cdv_intel_clock_t clock;
u32 dpll = 0, dspcntr, pipeconf;
bool ok, is_sdvo = false, is_dvo = false;
bool is_crt = false, is_lvds = false, is_tv = false;
bool is_hdmi = false;
struct drm_mode_config *mode_config = &dev->mode_config;
struct drm_connector *connector;
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
case INTEL_OUTPUT_HDMI:
is_hdmi = true;
break;
}
}
refclk = 96000;
if (is_crt || is_hdmi)
refclk = 27000;
drm_mode_debug_printmodeline(adjusted_mode);
ok = cdv_intel_find_best_PLL(crtc, adjusted_mode->clock, refclk,
&clock);
if (!ok) {
dev_err(dev->dev, "Couldn't find PLL settings for mode!\n");
return 0;
}
dpll = DPLL_VGA_MODE_DIS;
if (is_tv) {
dpll |= 3;
}
dpll |= PLL_REF_INPUT_DREFCLK;
dpll |= DPLL_SYNCLOCK_ENABLE;
dpll |= DPLL_VGA_MODE_DIS;
if (is_lvds)
dpll |= DPLLB_MODE_LVDS;
else
dpll |= DPLLB_MODE_DAC_SERIAL;
pipeconf = REG_READ(pipeconf_reg);
dspcntr = DISPPLANE_GAMMA_ENABLE;
if (pipe == 0)
dspcntr |= DISPPLANE_SEL_PIPE_A;
else
dspcntr |= DISPPLANE_SEL_PIPE_B;
dspcntr |= DISPLAY_PLANE_ENABLE;
pipeconf |= PIPEACONF_ENABLE;
REG_WRITE(dpll_reg, dpll | DPLL_VGA_MODE_DIS | DPLL_SYNCLOCK_ENABLE);
REG_READ(dpll_reg);
cdv_dpll_set_clock_cdv(dev, crtc, &clock);
udelay(150);
if (is_lvds) {
u32 lvds = REG_READ(LVDS);
lvds |=
LVDS_PORT_EN | LVDS_A0A2_CLKA_POWER_UP |
LVDS_PIPEB_SELECT;
if (clock.p2 == 7)
lvds |= LVDS_B0B3_POWER_UP | LVDS_CLKB_POWER_UP;
else
lvds &= ~(LVDS_B0B3_POWER_UP | LVDS_CLKB_POWER_UP);
REG_WRITE(LVDS, lvds);
REG_READ(LVDS);
}
dpll |= DPLL_VCO_ENABLE;
if (cdv_intel_panel_fitter_pipe(dev) == pipe)
REG_WRITE(PFIT_CONTROL, 0);
DRM_DEBUG_KMS("Mode for pipe %c:\n", pipe == 0 ? 'A' : 'B');
drm_mode_debug_printmodeline(mode);
REG_WRITE(dpll_reg,
(REG_READ(dpll_reg) & ~DPLL_LOCK) | DPLL_VCO_ENABLE);
REG_READ(dpll_reg);
udelay(150);
if (!(REG_READ(dpll_reg) & DPLL_LOCK)) {
dev_err(dev->dev, "Failed to get DPLL lock\n");
return -EBUSY;
}
{
int sdvo_pixel_multiply = adjusted_mode->clock / mode->clock;
REG_WRITE(dpll_md_reg, (0 << DPLL_MD_UDI_DIVIDER_SHIFT) | ((sdvo_pixel_multiply - 1) << DPLL_MD_UDI_MULTIPLIER_SHIFT));
}
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
cdv_intel_wait_for_vblank(dev);
REG_WRITE(dspcntr_reg, dspcntr);
{
struct drm_crtc_helper_funcs *crtc_funcs =
crtc->helper_private;
crtc_funcs->mode_set_base(crtc, x, y, old_fb);
}
cdv_intel_wait_for_vblank(dev);
return 0;
}
void cdv_intel_crtc_load_lut(struct drm_crtc *crtc)
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
static void cdv_intel_crtc_save(struct drm_crtc *crtc)
{
struct drm_device *dev = crtc->dev;
struct psb_intel_crtc *psb_intel_crtc = to_psb_intel_crtc(crtc);
struct psb_intel_crtc_state *crtc_state = psb_intel_crtc->crtc_state;
int pipeA = (psb_intel_crtc->pipe == 0);
uint32_t paletteReg;
int i;
if (!crtc_state) {
dev_dbg(dev->dev, "No CRTC state found\n");
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
DRM_DEBUG("(%x %x %x %x %x %x %x %x %x %x %x %x %x %x %x %x)\n",
crtc_state->saveDSPCNTR,
crtc_state->savePIPECONF,
crtc_state->savePIPESRC,
crtc_state->saveFP0,
crtc_state->saveFP1,
crtc_state->saveDPLL,
crtc_state->saveHTOTAL,
crtc_state->saveHBLANK,
crtc_state->saveHSYNC,
crtc_state->saveVTOTAL,
crtc_state->saveVBLANK,
crtc_state->saveVSYNC,
crtc_state->saveDSPSTRIDE,
crtc_state->saveDSPSIZE,
crtc_state->saveDSPPOS,
crtc_state->saveDSPBASE
);
paletteReg = pipeA ? PALETTE_A : PALETTE_B;
for (i = 0; i < 256; ++i)
crtc_state->savePalette[i] = REG_READ(paletteReg + (i << 2));
}
static void cdv_intel_crtc_restore(struct drm_crtc *crtc)
{
struct drm_device *dev = crtc->dev;
struct psb_intel_crtc *psb_intel_crtc = to_psb_intel_crtc(crtc);
struct psb_intel_crtc_state *crtc_state = psb_intel_crtc->crtc_state;
int pipeA = (psb_intel_crtc->pipe == 0);
uint32_t paletteReg;
int i;
if (!crtc_state) {
dev_dbg(dev->dev, "No crtc state\n");
return;
}
DRM_DEBUG(
"current:(%x %x %x %x %x %x %x %x %x %x %x %x %x %x %x %x)\n",
REG_READ(pipeA ? DSPACNTR : DSPBCNTR),
REG_READ(pipeA ? PIPEACONF : PIPEBCONF),
REG_READ(pipeA ? PIPEASRC : PIPEBSRC),
REG_READ(pipeA ? FPA0 : FPB0),
REG_READ(pipeA ? FPA1 : FPB1),
REG_READ(pipeA ? DPLL_A : DPLL_B),
REG_READ(pipeA ? HTOTAL_A : HTOTAL_B),
REG_READ(pipeA ? HBLANK_A : HBLANK_B),
REG_READ(pipeA ? HSYNC_A : HSYNC_B),
REG_READ(pipeA ? VTOTAL_A : VTOTAL_B),
REG_READ(pipeA ? VBLANK_A : VBLANK_B),
REG_READ(pipeA ? VSYNC_A : VSYNC_B),
REG_READ(pipeA ? DSPASTRIDE : DSPBSTRIDE),
REG_READ(pipeA ? DSPASIZE : DSPBSIZE),
REG_READ(pipeA ? DSPAPOS : DSPBPOS),
REG_READ(pipeA ? DSPABASE : DSPBBASE)
);
DRM_DEBUG(
"saved: (%x %x %x %x %x %x %x %x %x %x %x %x %x %x %x %x)\n",
crtc_state->saveDSPCNTR,
crtc_state->savePIPECONF,
crtc_state->savePIPESRC,
crtc_state->saveFP0,
crtc_state->saveFP1,
crtc_state->saveDPLL,
crtc_state->saveHTOTAL,
crtc_state->saveHBLANK,
crtc_state->saveHSYNC,
crtc_state->saveVTOTAL,
crtc_state->saveVBLANK,
crtc_state->saveVSYNC,
crtc_state->saveDSPSTRIDE,
crtc_state->saveDSPSIZE,
crtc_state->saveDSPPOS,
crtc_state->saveDSPBASE
);
if (crtc_state->saveDPLL & DPLL_VCO_ENABLE) {
REG_WRITE(pipeA ? DPLL_A : DPLL_B,
crtc_state->saveDPLL & ~DPLL_VCO_ENABLE);
REG_READ(pipeA ? DPLL_A : DPLL_B);
DRM_DEBUG("write dpll: %x\n",
REG_READ(pipeA ? DPLL_A : DPLL_B));
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
cdv_intel_wait_for_vblank(dev);
REG_WRITE(pipeA ? DSPACNTR : DSPBCNTR, crtc_state->saveDSPCNTR);
REG_WRITE(pipeA ? DSPABASE : DSPBBASE, crtc_state->saveDSPBASE);
cdv_intel_wait_for_vblank(dev);
paletteReg = pipeA ? PALETTE_A : PALETTE_B;
for (i = 0; i < 256; ++i)
REG_WRITE(paletteReg + (i << 2), crtc_state->savePalette[i]);
}
static int cdv_intel_crtc_cursor_set(struct drm_crtc *crtc,
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
static int cdv_intel_crtc_cursor_move(struct drm_crtc *crtc, int x, int y)
{
struct drm_device *dev = crtc->dev;
struct psb_intel_crtc *psb_intel_crtc = to_psb_intel_crtc(crtc);
int pipe = psb_intel_crtc->pipe;
uint32_t temp = 0;
uint32_t adder;
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
adder = psb_intel_crtc->cursor_addr;
if (gma_power_begin(dev, false)) {
REG_WRITE((pipe == 0) ? CURAPOS : CURBPOS, temp);
REG_WRITE((pipe == 0) ? CURABASE : CURBBASE, adder);
gma_power_end(dev);
}
return 0;
}
static void cdv_intel_crtc_gamma_set(struct drm_crtc *crtc, u16 *red,
u16 *green, u16 *blue, uint32_t start, uint32_t size)
{
struct psb_intel_crtc *psb_intel_crtc = to_psb_intel_crtc(crtc);
int i;
int end = (start + size > 256) ? 256 : start + size;
for (i = start; i < end; i++) {
psb_intel_crtc->lut_r[i] = red[i] >> 8;
psb_intel_crtc->lut_g[i] = green[i] >> 8;
psb_intel_crtc->lut_b[i] = blue[i] >> 8;
}
cdv_intel_crtc_load_lut(crtc);
}
static int cdv_crtc_set_config(struct drm_mode_set *set)
{
int ret = 0;
struct drm_device *dev = set->crtc->dev;
struct drm_psb_private *dev_priv = dev->dev_private;
if (!dev_priv->rpm_enabled)
return drm_crtc_helper_set_config(set);
pm_runtime_forbid(&dev->pdev->dev);
ret = drm_crtc_helper_set_config(set);
pm_runtime_allow(&dev->pdev->dev);
return ret;
}
static void i8xx_clock(int refclk, struct cdv_intel_clock_t *clock)
{
clock->m = 5 * (clock->m1 + 2) + (clock->m2 + 2);
clock->p = clock->p1 * clock->p2;
clock->vco = refclk * clock->m / (clock->n + 2);
clock->dot = clock->vco / clock->p;
}
static int cdv_intel_crtc_clock_get(struct drm_device *dev,
struct drm_crtc *crtc)
{
struct psb_intel_crtc *psb_intel_crtc = to_psb_intel_crtc(crtc);
int pipe = psb_intel_crtc->pipe;
u32 dpll;
u32 fp;
struct cdv_intel_clock_t clock;
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
if (clock.p1 == 0) {
clock.p1 = 4;
dev_err(dev->dev, "PLL %d\n", dpll);
}
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
struct drm_display_mode *cdv_intel_crtc_mode_get(struct drm_device *dev,
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
mode->clock = cdv_intel_crtc_clock_get(dev, crtc);
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
static void cdv_intel_crtc_destroy(struct drm_crtc *crtc)
{
struct psb_intel_crtc *psb_intel_crtc = to_psb_intel_crtc(crtc);
kfree(psb_intel_crtc->crtc_state);
drm_crtc_cleanup(crtc);
kfree(psb_intel_crtc);
}
void cdv_intel_cursor_init(struct drm_device *dev, int pipe)
{
uint32_t control;
uint32_t base;
switch (pipe) {
case 0:
control = CURACNTR;
base = CURABASE;
break;
case 1:
control = CURBCNTR;
base = CURBBASE;
break;
case 2:
control = CURCCNTR;
base = CURCBASE;
break;
default:
return;
}
REG_WRITE(control, 0);
REG_WRITE(base, 0);
}
