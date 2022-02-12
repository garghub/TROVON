void mdfldWaitForPipeDisable(struct drm_device *dev, int pipe)
{
struct drm_psb_private *dev_priv = dev->dev_private;
const struct psb_offset *map = &dev_priv->regmap[pipe];
int count, temp;
switch (pipe) {
case 0:
case 1:
case 2:
break;
default:
DRM_ERROR("Illegal Pipe Number.\n");
return;
}
gma_wait_for_vblank(dev);
return;
for (count = 0; count < COUNT_MAX; count++) {
temp = REG_READ(map->conf);
if ((temp & PIPEACONF_PIPE_STATE) == 0)
break;
}
}
void mdfldWaitForPipeEnable(struct drm_device *dev, int pipe)
{
struct drm_psb_private *dev_priv = dev->dev_private;
const struct psb_offset *map = &dev_priv->regmap[pipe];
int count, temp;
switch (pipe) {
case 0:
case 1:
case 2:
break;
default:
DRM_ERROR("Illegal Pipe Number.\n");
return;
}
gma_wait_for_vblank(dev);
return;
for (count = 0; count < COUNT_MAX; count++) {
temp = REG_READ(map->conf);
if ((temp & PIPEACONF_PIPE_STATE) == 1)
break;
}
}
static int psb_intel_panel_fitter_pipe(struct drm_device *dev)
{
u32 pfit_control;
pfit_control = REG_READ(PFIT_CONTROL);
if ((pfit_control & PFIT_ENABLE) == 0)
return -1;
return (pfit_control >> 29) & 0x3;
}
void mdfld__intel_plane_set_alpha(int enable)
{
struct drm_device *dev = &globle_dev;
int dspcntr_reg = DSPACNTR;
u32 dspcntr;
dspcntr = REG_READ(dspcntr_reg);
if (enable) {
dspcntr &= ~DISPPLANE_32BPP_NO_ALPHA;
dspcntr |= DISPPLANE_32BPP;
} else {
dspcntr &= ~DISPPLANE_32BPP;
dspcntr |= DISPPLANE_32BPP_NO_ALPHA;
}
REG_WRITE(dspcntr_reg, dspcntr);
}
static int check_fb(struct drm_framebuffer *fb)
{
if (!fb)
return 0;
switch (fb->bits_per_pixel) {
case 8:
case 16:
case 24:
case 32:
return 0;
default:
DRM_ERROR("Unknown color depth\n");
return -EINVAL;
}
}
static int mdfld__intel_pipe_set_base(struct drm_crtc *crtc, int x, int y,
struct drm_framebuffer *old_fb)
{
struct drm_device *dev = crtc->dev;
struct drm_psb_private *dev_priv = dev->dev_private;
struct gma_crtc *gma_crtc = to_gma_crtc(crtc);
struct psb_framebuffer *psbfb = to_psb_fb(crtc->primary->fb);
int pipe = gma_crtc->pipe;
const struct psb_offset *map = &dev_priv->regmap[pipe];
unsigned long start, offset;
u32 dspcntr;
int ret;
memcpy(&globle_dev, dev, sizeof(struct drm_device));
dev_dbg(dev->dev, "pipe = 0x%x.\n", pipe);
if (!crtc->primary->fb) {
dev_dbg(dev->dev, "No FB bound\n");
return 0;
}
ret = check_fb(crtc->primary->fb);
if (ret)
return ret;
if (pipe > 2) {
DRM_ERROR("Illegal Pipe Number.\n");
return -EINVAL;
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
}
REG_WRITE(map->cntr, dspcntr);
dev_dbg(dev->dev, "Writing base %08lX %08lX %d %d\n",
start, offset, x, y);
REG_WRITE(map->linoff, offset);
REG_READ(map->linoff);
REG_WRITE(map->surf, start);
REG_READ(map->surf);
gma_power_end(dev);
return 0;
}
void mdfld_disable_crtc(struct drm_device *dev, int pipe)
{
struct drm_psb_private *dev_priv = dev->dev_private;
const struct psb_offset *map = &dev_priv->regmap[pipe];
u32 temp;
dev_dbg(dev->dev, "pipe = %d\n", pipe);
if (pipe != 1)
mdfld_dsi_gen_fifo_ready(dev, MIPI_GEN_FIFO_STAT_REG(pipe),
HS_CTRL_FIFO_EMPTY | HS_DATA_FIFO_EMPTY);
temp = REG_READ(map->cntr);
if ((temp & DISPLAY_PLANE_ENABLE) != 0) {
REG_WRITE(map->cntr,
temp & ~DISPLAY_PLANE_ENABLE);
REG_WRITE(map->base, REG_READ(map->base));
REG_READ(map->base);
}
temp = REG_READ(map->conf);
if ((temp & PIPEACONF_ENABLE) != 0) {
temp &= ~PIPEACONF_ENABLE;
temp |= PIPECONF_PLANE_OFF | PIPECONF_CURSOR_OFF;
REG_WRITE(map->conf, temp);
REG_READ(map->conf);
mdfldWaitForPipeDisable(dev, pipe);
}
temp = REG_READ(map->dpll);
if (temp & DPLL_VCO_ENABLE) {
if ((pipe != 1 &&
!((REG_READ(PIPEACONF) | REG_READ(PIPECCONF))
& PIPEACONF_ENABLE)) || pipe == 1) {
temp &= ~(DPLL_VCO_ENABLE);
REG_WRITE(map->dpll, temp);
REG_READ(map->dpll);
udelay(500);
if (!(temp & MDFLD_PWR_GATE_EN)) {
REG_WRITE(map->dpll, temp | MDFLD_PWR_GATE_EN);
udelay(5000);
}
}
}
}
static void mdfld_crtc_dpms(struct drm_crtc *crtc, int mode)
{
struct drm_device *dev = crtc->dev;
struct drm_psb_private *dev_priv = dev->dev_private;
struct gma_crtc *gma_crtc = to_gma_crtc(crtc);
int pipe = gma_crtc->pipe;
const struct psb_offset *map = &dev_priv->regmap[pipe];
u32 pipeconf = dev_priv->pipeconf[pipe];
u32 temp;
int timeout = 0;
dev_dbg(dev->dev, "mode = %d, pipe = %d\n", mode, pipe);
if (!gma_power_begin(dev, true))
return;
switch (mode) {
case DRM_MODE_DPMS_ON:
case DRM_MODE_DPMS_STANDBY:
case DRM_MODE_DPMS_SUSPEND:
temp = REG_READ(map->dpll);
if ((temp & DPLL_VCO_ENABLE) == 0) {
if (temp & MDFLD_PWR_GATE_EN) {
temp &= ~MDFLD_PWR_GATE_EN;
REG_WRITE(map->dpll, temp);
udelay(500);
}
REG_WRITE(map->dpll, temp);
REG_READ(map->dpll);
udelay(500);
REG_WRITE(map->dpll, temp | DPLL_VCO_ENABLE);
REG_READ(map->dpll);
while ((pipe != 2) && (timeout < 20000) &&
!(REG_READ(map->conf) & PIPECONF_DSIPLL_LOCK)) {
udelay(150);
timeout++;
}
}
temp = REG_READ(map->cntr);
if ((temp & DISPLAY_PLANE_ENABLE) == 0) {
REG_WRITE(map->cntr,
temp | DISPLAY_PLANE_ENABLE);
REG_WRITE(map->base, REG_READ(map->base));
}
temp = REG_READ(map->conf);
if ((temp & PIPEACONF_ENABLE) == 0) {
REG_WRITE(map->conf, pipeconf);
mdfldWaitForPipeEnable(dev, pipe);
}
if (pipe == 0 || pipe == 2) {
REG_WRITE(map->status, REG_READ(map->status));
msleep(100);
if (PIPE_VBLANK_STATUS & REG_READ(map->status))
dev_dbg(dev->dev, "OK");
else {
dev_dbg(dev->dev, "STUCK!!!!");
temp = REG_READ(map->cntr);
REG_WRITE(map->cntr,
temp & ~DISPLAY_PLANE_ENABLE);
REG_WRITE(map->base, REG_READ(map->base));
REG_WRITE(0xb048, 1);
msleep(100);
temp = REG_READ(map->conf);
temp &= ~PIPEACONF_ENABLE;
REG_WRITE(map->conf, temp);
msleep(100);
REG_WRITE(MIPI_DEVICE_READY_REG(pipe), 0);
msleep(100);
REG_WRITE(0xb004, REG_READ(0xb004));
REG_WRITE(MIPI_DEVICE_READY_REG(pipe), 1);
temp = REG_READ(map->cntr);
REG_WRITE(map->cntr,
temp | DISPLAY_PLANE_ENABLE);
REG_WRITE(map->base, REG_READ(map->base));
REG_WRITE(0xb048, 2);
msleep(100);
temp = REG_READ(map->conf);
temp |= PIPEACONF_ENABLE;
REG_WRITE(map->conf, temp);
}
}
gma_crtc_load_lut(crtc);
break;
case DRM_MODE_DPMS_OFF:
if (pipe != 1)
mdfld_dsi_gen_fifo_ready(dev,
MIPI_GEN_FIFO_STAT_REG(pipe),
HS_CTRL_FIFO_EMPTY | HS_DATA_FIFO_EMPTY);
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
temp &= ~PIPEACONF_ENABLE;
temp |= PIPECONF_PLANE_OFF | PIPECONF_CURSOR_OFF;
REG_WRITE(map->conf, temp);
REG_READ(map->conf);
mdfldWaitForPipeDisable(dev, pipe);
}
temp = REG_READ(map->dpll);
if (temp & DPLL_VCO_ENABLE) {
if ((pipe != 1 && !((REG_READ(PIPEACONF)
| REG_READ(PIPECCONF)) & PIPEACONF_ENABLE))
|| pipe == 1) {
temp &= ~(DPLL_VCO_ENABLE);
REG_WRITE(map->dpll, temp);
REG_READ(map->dpll);
udelay(500);
}
}
break;
}
gma_power_end(dev);
}
static const struct mrst_limit_t *mdfld_limit(struct drm_crtc *crtc)
{
const struct mrst_limit_t *limit = NULL;
struct drm_device *dev = crtc->dev;
struct drm_psb_private *dev_priv = dev->dev_private;
if (gma_pipe_has_type(crtc, INTEL_OUTPUT_MIPI)
|| gma_pipe_has_type(crtc, INTEL_OUTPUT_MIPI2)) {
if ((ksel == KSEL_CRYSTAL_19) || (ksel == KSEL_BYPASS_19))
limit = &mdfld_limits[MDFLD_LIMT_DSIPLL_19];
else if (ksel == KSEL_BYPASS_25)
limit = &mdfld_limits[MDFLD_LIMT_DSIPLL_25];
else if ((ksel == KSEL_BYPASS_83_100) &&
(dev_priv->core_freq == 166))
limit = &mdfld_limits[MDFLD_LIMT_DSIPLL_83];
else if ((ksel == KSEL_BYPASS_83_100) &&
(dev_priv->core_freq == 100 ||
dev_priv->core_freq == 200))
limit = &mdfld_limits[MDFLD_LIMT_DSIPLL_100];
} else if (gma_pipe_has_type(crtc, INTEL_OUTPUT_HDMI)) {
if ((ksel == KSEL_CRYSTAL_19) || (ksel == KSEL_BYPASS_19))
limit = &mdfld_limits[MDFLD_LIMT_DPLL_19];
else if (ksel == KSEL_BYPASS_25)
limit = &mdfld_limits[MDFLD_LIMT_DPLL_25];
else if ((ksel == KSEL_BYPASS_83_100) &&
(dev_priv->core_freq == 166))
limit = &mdfld_limits[MDFLD_LIMT_DPLL_83];
else if ((ksel == KSEL_BYPASS_83_100) &&
(dev_priv->core_freq == 100 ||
dev_priv->core_freq == 200))
limit = &mdfld_limits[MDFLD_LIMT_DPLL_100];
} else {
limit = NULL;
dev_dbg(dev->dev, "mdfld_limit Wrong display type.\n");
}
return limit;
}
static void mdfld_clock(int refclk, struct mrst_clock_t *clock)
{
clock->dot = (refclk * clock->m) / clock->p1;
}
static bool
mdfldFindBestPLL(struct drm_crtc *crtc, int target, int refclk,
struct mrst_clock_t *best_clock)
{
struct mrst_clock_t clock;
const struct mrst_limit_t *limit = mdfld_limit(crtc);
int err = target;
memset(best_clock, 0, sizeof(*best_clock));
for (clock.m = limit->m.min; clock.m <= limit->m.max; clock.m++) {
for (clock.p1 = limit->p1.min; clock.p1 <= limit->p1.max;
clock.p1++) {
int this_err;
mdfld_clock(refclk, &clock);
this_err = abs(clock.dot - target);
if (this_err < err) {
*best_clock = clock;
err = this_err;
}
}
}
return err != target;
}
static int mdfld_crtc_mode_set(struct drm_crtc *crtc,
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
int clk_n = 0, clk_p2 = 0, clk_byte = 1, clk = 0, m_conv = 0,
clk_tmp = 0;
struct mrst_clock_t clock;
bool ok;
u32 dpll = 0, fp = 0;
bool is_mipi = false, is_mipi2 = false, is_hdmi = false;
struct drm_mode_config *mode_config = &dev->mode_config;
struct gma_encoder *gma_encoder = NULL;
uint64_t scalingType = DRM_MODE_SCALE_FULLSCREEN;
struct drm_encoder *encoder;
struct drm_connector *connector;
int timeout = 0;
int ret;
dev_dbg(dev->dev, "pipe = 0x%x\n", pipe);
#if 0
if (pipe == 1) {
if (!gma_power_begin(dev, true))
return 0;
android_hdmi_crtc_mode_set(crtc, mode, adjusted_mode,
x, y, old_fb);
goto mrst_crtc_mode_set_exit;
}
#endif
ret = check_fb(crtc->primary->fb);
if (ret)
return ret;
dev_dbg(dev->dev, "adjusted_hdisplay = %d\n",
adjusted_mode->hdisplay);
dev_dbg(dev->dev, "adjusted_vdisplay = %d\n",
adjusted_mode->vdisplay);
dev_dbg(dev->dev, "adjusted_hsync_start = %d\n",
adjusted_mode->hsync_start);
dev_dbg(dev->dev, "adjusted_hsync_end = %d\n",
adjusted_mode->hsync_end);
dev_dbg(dev->dev, "adjusted_htotal = %d\n",
adjusted_mode->htotal);
dev_dbg(dev->dev, "adjusted_vsync_start = %d\n",
adjusted_mode->vsync_start);
dev_dbg(dev->dev, "adjusted_vsync_end = %d\n",
adjusted_mode->vsync_end);
dev_dbg(dev->dev, "adjusted_vtotal = %d\n",
adjusted_mode->vtotal);
dev_dbg(dev->dev, "adjusted_clock = %d\n",
adjusted_mode->clock);
dev_dbg(dev->dev, "hdisplay = %d\n",
mode->hdisplay);
dev_dbg(dev->dev, "vdisplay = %d\n",
mode->vdisplay);
if (!gma_power_begin(dev, true))
return 0;
memcpy(&gma_crtc->saved_mode, mode,
sizeof(struct drm_display_mode));
memcpy(&gma_crtc->saved_adjusted_mode, adjusted_mode,
sizeof(struct drm_display_mode));
list_for_each_entry(connector, &mode_config->connector_list, head) {
if (!connector)
continue;
encoder = connector->encoder;
if (!encoder)
continue;
if (encoder->crtc != crtc)
continue;
gma_encoder = gma_attached_encoder(connector);
switch (gma_encoder->type) {
case INTEL_OUTPUT_MIPI:
is_mipi = true;
break;
case INTEL_OUTPUT_MIPI2:
is_mipi2 = true;
break;
case INTEL_OUTPUT_HDMI:
is_hdmi = true;
break;
}
}
REG_WRITE(VGACNTRL, VGA_DISP_DISABLE);
if (psb_intel_panel_fitter_pipe(dev) == pipe)
REG_WRITE(PFIT_CONTROL, 0);
if (pipe == 1) {
REG_WRITE(map->size, ((min(mode->crtc_vdisplay, adjusted_mode->crtc_vdisplay) - 1) << 16)
| (min(mode->crtc_hdisplay, adjusted_mode->crtc_hdisplay) - 1));
REG_WRITE(map->src, ((mode->crtc_hdisplay - 1) << 16)
| (mode->crtc_vdisplay - 1));
} else {
REG_WRITE(map->size,
((mode->crtc_vdisplay - 1) << 16) |
(mode->crtc_hdisplay - 1));
REG_WRITE(map->src,
((mode->crtc_hdisplay - 1) << 16) |
(mode->crtc_vdisplay - 1));
}
REG_WRITE(map->pos, 0);
if (gma_encoder)
drm_object_property_get_value(&connector->base,
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
REG_WRITE(map->hblank, (adjusted_mode->crtc_hblank_start -
offsetX - 1) |
((adjusted_mode->crtc_hblank_end - offsetX - 1) << 16));
REG_WRITE(map->hsync, (adjusted_mode->crtc_hsync_start -
offsetX - 1) |
((adjusted_mode->crtc_hsync_end - offsetX - 1) << 16));
REG_WRITE(map->vblank, (adjusted_mode->crtc_vblank_start -
offsetY - 1) |
((adjusted_mode->crtc_vblank_end - offsetY - 1) << 16));
REG_WRITE(map->vsync, (adjusted_mode->crtc_vsync_start -
offsetY - 1) |
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
const struct drm_crtc_helper_funcs *crtc_funcs =
crtc->helper_private;
crtc_funcs->mode_set_base(crtc, x, y, old_fb);
}
dev_priv->pipeconf[pipe] = PIPEACONF_ENABLE;
dev_priv->dspcntr[pipe] = REG_READ(map->cntr);
dev_priv->dspcntr[pipe] |= pipe << DISPPLANE_SEL_PIPE_POS;
dev_priv->dspcntr[pipe] |= DISPLAY_PLANE_ENABLE;
if (is_mipi2)
goto mrst_crtc_mode_set_exit;
clk = adjusted_mode->clock;
if (is_hdmi) {
if ((ksel == KSEL_CRYSTAL_19) || (ksel == KSEL_BYPASS_19)) {
refclk = 19200;
if (is_mipi || is_mipi2)
clk_n = 1, clk_p2 = 8;
else if (is_hdmi)
clk_n = 1, clk_p2 = 10;
} else if (ksel == KSEL_BYPASS_25) {
refclk = 25000;
if (is_mipi || is_mipi2)
clk_n = 1, clk_p2 = 8;
else if (is_hdmi)
clk_n = 1, clk_p2 = 10;
} else if ((ksel == KSEL_BYPASS_83_100) &&
dev_priv->core_freq == 166) {
refclk = 83000;
if (is_mipi || is_mipi2)
clk_n = 4, clk_p2 = 8;
else if (is_hdmi)
clk_n = 4, clk_p2 = 10;
} else if ((ksel == KSEL_BYPASS_83_100) &&
(dev_priv->core_freq == 100 ||
dev_priv->core_freq == 200)) {
refclk = 100000;
if (is_mipi || is_mipi2)
clk_n = 4, clk_p2 = 8;
else if (is_hdmi)
clk_n = 4, clk_p2 = 10;
}
if (is_mipi)
clk_byte = dev_priv->bpp / 8;
else if (is_mipi2)
clk_byte = dev_priv->bpp2 / 8;
clk_tmp = clk * clk_n * clk_p2 * clk_byte;
dev_dbg(dev->dev, "clk = %d, clk_n = %d, clk_p2 = %d.\n",
clk, clk_n, clk_p2);
dev_dbg(dev->dev, "adjusted_mode->clock = %d, clk_tmp = %d.\n",
adjusted_mode->clock, clk_tmp);
ok = mdfldFindBestPLL(crtc, clk_tmp, refclk, &clock);
if (!ok) {
DRM_ERROR
("mdfldFindBestPLL fail in mdfld_crtc_mode_set.\n");
} else {
m_conv = mdfld_m_converts[(clock.m - MDFLD_M_MIN)];
dev_dbg(dev->dev, "dot clock = %d,"
"m = %d, p1 = %d, m_conv = %d.\n",
clock.dot, clock.m,
clock.p1, m_conv);
}
dpll = REG_READ(map->dpll);
if (dpll & DPLL_VCO_ENABLE) {
dpll &= ~DPLL_VCO_ENABLE;
REG_WRITE(map->dpll, dpll);
REG_READ(map->dpll);
udelay(500);
REG_WRITE(map->fp0, 0);
dpll &= ~MDFLD_P1_MASK;
REG_WRITE(map->dpll, dpll);
udelay(500);
}
if (dpll & MDFLD_PWR_GATE_EN) {
dpll &= ~MDFLD_PWR_GATE_EN;
REG_WRITE(map->dpll, dpll);
udelay(500);
}
dpll = 0;
#if 0
if (ksel == KSEL_CRYSTAL_19 || ksel == KSEL_BYPASS_19 ||
ksel == KSEL_BYPASS_25)
dpll &= ~MDFLD_INPUT_REF_SEL;
else if (ksel == KSEL_BYPASS_83_100)
dpll |= MDFLD_INPUT_REF_SEL;
#endif
if (is_hdmi)
dpll |= MDFLD_VCO_SEL;
fp = (clk_n / 2) << 16;
fp |= m_conv;
dpll |= (1 << (clock.p1 - 2)) << 17;
#if 0
dpll = 0x00050000;
fp = 0x000001be;
#endif
#if 0
dpll = 0x02010000;
fp = 0x000000d2;
#endif
} else {
#if 0
dpll = 0x00020000;
fp = 0x00000156;
#endif
dpll = 0x00800000;
fp = 0x000000c1;
}
REG_WRITE(map->fp0, fp);
REG_WRITE(map->dpll, dpll);
udelay(500);
dpll |= DPLL_VCO_ENABLE;
REG_WRITE(map->dpll, dpll);
REG_READ(map->dpll);
while (timeout < 20000 &&
!(REG_READ(map->conf) & PIPECONF_DSIPLL_LOCK)) {
udelay(150);
timeout++;
}
if (is_mipi)
goto mrst_crtc_mode_set_exit;
dev_dbg(dev->dev, "is_mipi = 0x%x\n", is_mipi);
REG_WRITE(map->conf, dev_priv->pipeconf[pipe]);
REG_READ(map->conf);
REG_WRITE(map->cntr, dev_priv->dspcntr[pipe]);
gma_wait_for_vblank(dev);
mrst_crtc_mode_set_exit:
gma_power_end(dev);
return 0;
}
