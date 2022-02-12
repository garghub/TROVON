int cdv_sb_read(struct drm_device *dev, u32 reg, u32 *val)
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
int cdv_sb_write(struct drm_device *dev, u32 reg, u32 val)
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
void cdv_sb_reset(struct drm_device *dev)
{
REG_WRITE(DPIO_CFG, 0);
REG_READ(DPIO_CFG);
REG_WRITE(DPIO_CFG, DPIO_MODE_SELECT_0 | DPIO_CMN_RESET_N);
}
static int
cdv_dpll_set_clock_cdv(struct drm_device *dev, struct drm_crtc *crtc,
struct gma_clock_t *clock, bool is_lvds, u32 ddi_select)
{
struct gma_crtc *gma_crtc = to_gma_crtc(crtc);
int pipe = gma_crtc->pipe;
u32 m, n_vco, p;
int ret = 0;
int dpll_reg = (pipe == 0) ? DPLL_A : DPLL_B;
int ref_sfr = (pipe == 0) ? SB_REF_DPLLA : SB_REF_DPLLB;
u32 ref_value;
u32 lane_reg, lane_value;
cdv_sb_reset(dev);
REG_WRITE(dpll_reg, DPLL_SYNCLOCK_ENABLE | DPLL_VGA_MODE_DIS);
udelay(100);
ref_value = 0x68A701;
cdv_sb_write(dev, SB_REF_SFR(pipe), ref_value);
ret = cdv_sb_read(dev, ref_sfr, &ref_value);
if (ret)
return ret;
ref_value &= ~(REF_CLK_MASK);
if (pipe == 1 && !is_lvds && !(ddi_select & DP_MASK)) {
DRM_DEBUG_KMS("use DPLLA for pipe B\n");
ref_value |= REF_CLK_DPLLA;
} else {
DRM_DEBUG_KMS("use their DPLL for pipe A/B\n");
ref_value |= REF_CLK_DPLL;
}
ret = cdv_sb_write(dev, ref_sfr, ref_value);
if (ret)
return ret;
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
if (ddi_select) {
if ((ddi_select & DDI_MASK) == DDI0_SELECT) {
lane_reg = PSB_LANE0;
cdv_sb_read(dev, lane_reg, &lane_value);
lane_value &= ~(LANE_PLL_MASK);
lane_value |= LANE_PLL_ENABLE | LANE_PLL_PIPE(pipe);
cdv_sb_write(dev, lane_reg, lane_value);
lane_reg = PSB_LANE1;
cdv_sb_read(dev, lane_reg, &lane_value);
lane_value &= ~(LANE_PLL_MASK);
lane_value |= LANE_PLL_ENABLE | LANE_PLL_PIPE(pipe);
cdv_sb_write(dev, lane_reg, lane_value);
} else {
lane_reg = PSB_LANE2;
cdv_sb_read(dev, lane_reg, &lane_value);
lane_value &= ~(LANE_PLL_MASK);
lane_value |= LANE_PLL_ENABLE | LANE_PLL_PIPE(pipe);
cdv_sb_write(dev, lane_reg, lane_value);
lane_reg = PSB_LANE3;
cdv_sb_read(dev, lane_reg, &lane_value);
lane_value &= ~(LANE_PLL_MASK);
lane_value |= LANE_PLL_ENABLE | LANE_PLL_PIPE(pipe);
cdv_sb_write(dev, lane_reg, lane_value);
}
}
return 0;
}
static const struct gma_limit_t *cdv_intel_limit(struct drm_crtc *crtc,
int refclk)
{
const struct gma_limit_t *limit;
if (gma_pipe_has_type(crtc, INTEL_OUTPUT_LVDS)) {
if (refclk == 96000)
limit = &cdv_intel_limits[CDV_LIMIT_SINGLE_LVDS_96];
else
limit = &cdv_intel_limits[CDV_LIMIT_SINGLE_LVDS_100];
} else if (gma_pipe_has_type(crtc, INTEL_OUTPUT_DISPLAYPORT) ||
gma_pipe_has_type(crtc, INTEL_OUTPUT_EDP)) {
if (refclk == 27000)
limit = &cdv_intel_limits[CDV_LIMIT_DP_27];
else
limit = &cdv_intel_limits[CDV_LIMIT_DP_100];
} else {
if (refclk == 27000)
limit = &cdv_intel_limits[CDV_LIMIT_DAC_HDMI_27];
else
limit = &cdv_intel_limits[CDV_LIMIT_DAC_HDMI_96];
}
return limit;
}
static void cdv_intel_clock(int refclk, struct gma_clock_t *clock)
{
clock->m = clock->m2 + 2;
clock->p = clock->p1 * clock->p2;
clock->vco = (refclk * clock->m) / clock->n;
clock->dot = clock->vco / clock->p;
}
static bool cdv_intel_find_dp_pll(const struct gma_limit_t *limit,
struct drm_crtc *crtc, int target,
int refclk,
struct gma_clock_t *best_clock)
{
struct gma_crtc *gma_crtc = to_gma_crtc(crtc);
struct gma_clock_t clock;
switch (refclk) {
case 27000:
if (target < 200000) {
clock.p1 = 2;
clock.p2 = 10;
clock.n = 1;
clock.m1 = 0;
clock.m2 = 118;
} else {
clock.p1 = 1;
clock.p2 = 10;
clock.n = 1;
clock.m1 = 0;
clock.m2 = 98;
}
break;
case 100000:
if (target < 200000) {
clock.p1 = 2;
clock.p2 = 10;
clock.n = 5;
clock.m1 = 0;
clock.m2 = 160;
} else {
clock.p1 = 1;
clock.p2 = 10;
clock.n = 5;
clock.m1 = 0;
clock.m2 = 133;
}
break;
default:
return false;
}
gma_crtc->clock_funcs->clock(refclk, &clock);
memcpy(best_clock, &clock, sizeof(struct gma_clock_t));
return true;
}
static bool cdv_intel_pipe_enabled(struct drm_device *dev, int pipe)
{
struct drm_crtc *crtc;
struct drm_psb_private *dev_priv = dev->dev_private;
struct gma_crtc *gma_crtc = NULL;
crtc = dev_priv->pipe_to_crtc_mapping[pipe];
gma_crtc = to_gma_crtc(crtc);
if (crtc->primary->fb == NULL || !gma_crtc->active)
return false;
return true;
}
void cdv_disable_sr(struct drm_device *dev)
{
if (REG_READ(FW_BLC_SELF) & FW_BLC_SELF_EN) {
REG_WRITE(FW_BLC_SELF, (REG_READ(FW_BLC_SELF) & ~FW_BLC_SELF_EN));
REG_READ(FW_BLC_SELF);
gma_wait_for_vblank(dev);
REG_WRITE(OV_OVADD, 0);
REG_READ(OV_OVADD);
gma_wait_for_vblank(dev);
}
}
void cdv_update_wm(struct drm_device *dev, struct drm_crtc *crtc)
{
struct drm_psb_private *dev_priv = dev->dev_private;
struct gma_crtc *gma_crtc = to_gma_crtc(crtc);
if (cdv_intel_pipe_enabled(dev, 0) ^ cdv_intel_pipe_enabled(dev, 1)) {
u32 fw;
fw = REG_READ(DSPFW1);
fw &= ~DSP_FIFO_SR_WM_MASK;
fw |= (0x7e << DSP_FIFO_SR_WM_SHIFT);
fw &= ~CURSOR_B_FIFO_WM_MASK;
fw |= (0x4 << CURSOR_B_FIFO_WM_SHIFT);
REG_WRITE(DSPFW1, fw);
fw = REG_READ(DSPFW2);
fw &= ~CURSOR_A_FIFO_WM_MASK;
fw |= (0x6 << CURSOR_A_FIFO_WM_SHIFT);
fw &= ~DSP_PLANE_C_FIFO_WM_MASK;
fw |= (0x8 << DSP_PLANE_C_FIFO_WM_SHIFT);
REG_WRITE(DSPFW2, fw);
REG_WRITE(DSPFW3, 0x36000000);
if (gma_crtc->pipe == 1 &&
gma_pipe_has_type(crtc, INTEL_OUTPUT_LVDS)) {
REG_WRITE(DSPFW5, 0x00040330);
} else {
fw = (3 << DSP_PLANE_B_FIFO_WM1_SHIFT) |
(4 << DSP_PLANE_A_FIFO_WM1_SHIFT) |
(3 << CURSOR_B_FIFO_WM1_SHIFT) |
(4 << CURSOR_FIFO_SR_WM1_SHIFT);
REG_WRITE(DSPFW5, fw);
}
REG_WRITE(DSPFW6, 0x10);
gma_wait_for_vblank(dev);
REG_WRITE(FW_BLC_SELF, FW_BLC_SELF_EN);
REG_READ(FW_BLC_SELF);
gma_wait_for_vblank(dev);
} else {
REG_WRITE(DSPFW1, 0x3f880808);
REG_WRITE(DSPFW2, 0x0b020202);
REG_WRITE(DSPFW3, 0x24000000);
REG_WRITE(DSPFW4, 0x08030202);
REG_WRITE(DSPFW5, 0x01010101);
REG_WRITE(DSPFW6, 0x1d0);
gma_wait_for_vblank(dev);
dev_priv->ops->disable_sr(dev);
}
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
struct drm_psb_private *dev_priv = dev->dev_private;
struct gma_crtc *gma_crtc = to_gma_crtc(crtc);
int pipe = gma_crtc->pipe;
const struct psb_offset *map = &dev_priv->regmap[pipe];
int refclk;
struct gma_clock_t clock;
u32 dpll = 0, dspcntr, pipeconf;
bool ok;
bool is_crt = false, is_lvds = false, is_tv = false;
bool is_hdmi = false, is_dp = false;
struct drm_mode_config *mode_config = &dev->mode_config;
struct drm_connector *connector;
const struct gma_limit_t *limit;
u32 ddi_select = 0;
bool is_edp = false;
list_for_each_entry(connector, &mode_config->connector_list, head) {
struct gma_encoder *gma_encoder =
gma_attached_encoder(connector);
if (!connector->encoder
|| connector->encoder->crtc != crtc)
continue;
ddi_select = gma_encoder->ddi_select;
switch (gma_encoder->type) {
case INTEL_OUTPUT_LVDS:
is_lvds = true;
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
case INTEL_OUTPUT_DISPLAYPORT:
is_dp = true;
break;
case INTEL_OUTPUT_EDP:
is_edp = true;
break;
default:
DRM_ERROR("invalid output type.\n");
return 0;
}
}
if (dev_priv->dplla_96mhz)
refclk = 96000;
else
refclk = 27000;
if (is_dp || is_edp) {
if (pipe == 0)
refclk = 27000;
else
refclk = 100000;
}
if (is_lvds && dev_priv->lvds_use_ssc) {
refclk = dev_priv->lvds_ssc_freq * 1000;
DRM_DEBUG_KMS("Use SSC reference clock %d Mhz\n", dev_priv->lvds_ssc_freq);
}
drm_mode_debug_printmodeline(adjusted_mode);
limit = gma_crtc->clock_funcs->limit(crtc, refclk);
ok = limit->find_pll(limit, crtc, adjusted_mode->clock, refclk,
&clock);
if (!ok) {
DRM_ERROR("Couldn't find PLL settings for mode! target: %d, actual: %d",
adjusted_mode->clock, clock.dot);
return 0;
}
dpll = DPLL_VGA_MODE_DIS;
if (is_tv) {
dpll |= 3;
}
if (is_dp || is_edp) {
cdv_intel_dp_set_m_n(crtc, mode, adjusted_mode);
} else {
REG_WRITE(PIPE_GMCH_DATA_M(pipe), 0);
REG_WRITE(PIPE_GMCH_DATA_N(pipe), 0);
REG_WRITE(PIPE_DP_LINK_M(pipe), 0);
REG_WRITE(PIPE_DP_LINK_N(pipe), 0);
}
dpll |= DPLL_SYNCLOCK_ENABLE;
pipeconf = REG_READ(map->conf);
pipeconf &= ~(PIPE_BPC_MASK);
if (is_edp) {
switch (dev_priv->edp.bpp) {
case 24:
pipeconf |= PIPE_8BPC;
break;
case 18:
pipeconf |= PIPE_6BPC;
break;
case 30:
pipeconf |= PIPE_10BPC;
break;
default:
pipeconf |= PIPE_8BPC;
break;
}
} else if (is_lvds) {
if ((REG_READ(LVDS) & LVDS_A3_POWER_MASK) == LVDS_A3_POWER_UP)
pipeconf |= PIPE_8BPC;
else
pipeconf |= PIPE_6BPC;
} else
pipeconf |= PIPE_8BPC;
dspcntr = DISPPLANE_GAMMA_ENABLE;
if (pipe == 0)
dspcntr |= DISPPLANE_SEL_PIPE_A;
else
dspcntr |= DISPPLANE_SEL_PIPE_B;
dspcntr |= DISPLAY_PLANE_ENABLE;
pipeconf |= PIPEACONF_ENABLE;
REG_WRITE(map->dpll, dpll | DPLL_VGA_MODE_DIS | DPLL_SYNCLOCK_ENABLE);
REG_READ(map->dpll);
cdv_dpll_set_clock_cdv(dev, crtc, &clock, is_lvds, ddi_select);
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
REG_WRITE(map->dpll,
(REG_READ(map->dpll) & ~DPLL_LOCK) | DPLL_VCO_ENABLE);
REG_READ(map->dpll);
udelay(150);
if (!(REG_READ(map->dpll) & DPLL_LOCK)) {
dev_err(dev->dev, "Failed to get DPLL lock\n");
return -EBUSY;
}
{
int sdvo_pixel_multiply = adjusted_mode->clock / mode->clock;
REG_WRITE(map->dpll_md, (0 << DPLL_MD_UDI_DIVIDER_SHIFT) | ((sdvo_pixel_multiply - 1) << DPLL_MD_UDI_MULTIPLIER_SHIFT));
}
REG_WRITE(map->htotal, (adjusted_mode->crtc_hdisplay - 1) |
((adjusted_mode->crtc_htotal - 1) << 16));
REG_WRITE(map->hblank, (adjusted_mode->crtc_hblank_start - 1) |
((adjusted_mode->crtc_hblank_end - 1) << 16));
REG_WRITE(map->hsync, (adjusted_mode->crtc_hsync_start - 1) |
((adjusted_mode->crtc_hsync_end - 1) << 16));
REG_WRITE(map->vtotal, (adjusted_mode->crtc_vdisplay - 1) |
((adjusted_mode->crtc_vtotal - 1) << 16));
REG_WRITE(map->vblank, (adjusted_mode->crtc_vblank_start - 1) |
((adjusted_mode->crtc_vblank_end - 1) << 16));
REG_WRITE(map->vsync, (adjusted_mode->crtc_vsync_start - 1) |
((adjusted_mode->crtc_vsync_end - 1) << 16));
REG_WRITE(map->size,
((mode->vdisplay - 1) << 16) | (mode->hdisplay - 1));
REG_WRITE(map->pos, 0);
REG_WRITE(map->src,
((mode->hdisplay - 1) << 16) | (mode->vdisplay - 1));
REG_WRITE(map->conf, pipeconf);
REG_READ(map->conf);
gma_wait_for_vblank(dev);
REG_WRITE(map->cntr, dspcntr);
{
const struct drm_crtc_helper_funcs *crtc_funcs =
crtc->helper_private;
crtc_funcs->mode_set_base(crtc, x, y, old_fb);
}
gma_wait_for_vblank(dev);
return 0;
}
static void i8xx_clock(int refclk, struct gma_clock_t *clock)
{
clock->m = 5 * (clock->m1 + 2) + (clock->m2 + 2);
clock->p = clock->p1 * clock->p2;
clock->vco = refclk * clock->m / (clock->n + 2);
clock->dot = clock->vco / clock->p;
}
static int cdv_intel_crtc_clock_get(struct drm_device *dev,
struct drm_crtc *crtc)
{
struct drm_psb_private *dev_priv = dev->dev_private;
struct gma_crtc *gma_crtc = to_gma_crtc(crtc);
int pipe = gma_crtc->pipe;
const struct psb_offset *map = &dev_priv->regmap[pipe];
u32 dpll;
u32 fp;
struct gma_clock_t clock;
bool is_lvds;
struct psb_pipe *p = &dev_priv->regs.pipe[pipe];
if (gma_power_begin(dev, false)) {
dpll = REG_READ(map->dpll);
if ((dpll & DISPLAY_RATE_SELECT_FPA1) == 0)
fp = REG_READ(map->fp0);
else
fp = REG_READ(map->fp1);
is_lvds = (pipe == 1) && (REG_READ(LVDS) & LVDS_PORT_EN);
gma_power_end(dev);
} else {
dpll = p->dpll;
if ((dpll & DISPLAY_RATE_SELECT_FPA1) == 0)
fp = p->fp0;
else
fp = p->fp1;
is_lvds = (pipe == 1) &&
(dev_priv->regs.psb.saveLVDS & LVDS_PORT_EN);
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
struct gma_crtc *gma_crtc = to_gma_crtc(crtc);
int pipe = gma_crtc->pipe;
struct drm_psb_private *dev_priv = dev->dev_private;
struct psb_pipe *p = &dev_priv->regs.pipe[pipe];
const struct psb_offset *map = &dev_priv->regmap[pipe];
struct drm_display_mode *mode;
int htot;
int hsync;
int vtot;
int vsync;
if (gma_power_begin(dev, false)) {
htot = REG_READ(map->htotal);
hsync = REG_READ(map->hsync);
vtot = REG_READ(map->vtotal);
vsync = REG_READ(map->vsync);
gma_power_end(dev);
} else {
htot = p->htotal;
hsync = p->hsync;
vtot = p->vtotal;
vsync = p->vsync;
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
