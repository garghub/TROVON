void mdfldWaitForPipeDisable(struct drm_device *dev, int pipe)
{
int count, temp;
u32 pipeconf_reg = PIPEACONF;
switch (pipe) {
case 0:
break;
case 1:
pipeconf_reg = PIPEBCONF;
break;
case 2:
pipeconf_reg = PIPECCONF;
break;
default:
DRM_ERROR("Illegal Pipe Number. \n");
return;
}
psb_intel_wait_for_vblank(dev);
return;
for (count = 0; count < COUNT_MAX; count++) {
temp = REG_READ(pipeconf_reg);
if ((temp & PIPEACONF_PIPE_STATE) == 0)
break;
}
}
void mdfldWaitForPipeEnable(struct drm_device *dev, int pipe)
{
int count, temp;
u32 pipeconf_reg = PIPEACONF;
switch (pipe) {
case 0:
break;
case 1:
pipeconf_reg = PIPEBCONF;
break;
case 2:
pipeconf_reg = PIPECCONF;
break;
default:
dev_err(dev->dev, "Illegal Pipe Number.\n");
return;
}
psb_intel_wait_for_vblank(dev);
return;
for (count = 0; count < COUNT_MAX; count++) {
temp = REG_READ(pipeconf_reg);
if ((temp & PIPEACONF_PIPE_STATE) == 1)
break;
}
}
static int mdfld_intel_crtc_cursor_set(struct drm_crtc *crtc,
struct drm_file *file_priv,
uint32_t handle,
uint32_t width, uint32_t height)
{
struct drm_device *dev = crtc->dev;
struct psb_intel_crtc *psb_intel_crtc = to_psb_intel_crtc(crtc);
int pipe = psb_intel_crtc->pipe;
uint32_t control = CURACNTR;
uint32_t base = CURABASE;
uint32_t temp;
size_t addr = 0;
struct gtt_range *gt;
struct drm_gem_object *obj;
int ret;
switch (pipe) {
case 0:
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
dev_err(dev->dev, "Illegal Pipe Number. \n");
return -EINVAL;
}
#if 1
if (pipe != 0)
return 0;
#endif
if (!handle) {
dev_dbg(dev->dev, "cursor off\n");
temp = 0;
temp |= CURSOR_MODE_DISABLE;
if (gma_power_begin(dev, true)) {
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
DRM_ERROR("we currently only support 64x64 cursors\n");
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
if (gma_power_begin(dev, true)) {
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
static int mdfld_intel_crtc_cursor_move(struct drm_crtc *crtc, int x, int y)
{
struct drm_device *dev = crtc->dev;
struct drm_psb_private * dev_priv = (struct drm_psb_private *)dev->dev_private;
struct mdfld_dbi_dpu_info *dpu_info = dev_priv->dbi_dpu_info;
struct psb_drm_dpu_rect rect;
struct psb_intel_crtc *psb_intel_crtc = to_psb_intel_crtc(crtc);
int pipe = psb_intel_crtc->pipe;
uint32_t pos = CURAPOS;
uint32_t base = CURABASE;
uint32_t temp = 0;
uint32_t addr;
switch (pipe) {
case 0:
if (dpu_info) {
rect.x = x;
rect.y = y;
mdfld_dbi_dpu_report_damage(dev, MDFLD_CURSORA, &rect);
mdfld_dpu_exit_dsr(dev);
} else if (!(dev_priv->dsr_fb_update & MDFLD_DSR_CURSOR_0))
mdfld_dsi_dbi_exit_dsr(dev, MDFLD_DSR_CURSOR_0);
break;
case 1:
pos = CURBPOS;
base = CURBBASE;
break;
case 2:
if (dpu_info) {
mdfld_dbi_dpu_report_damage(dev, MDFLD_CURSORC, &rect);
mdfld_dpu_exit_dsr(dev);
} else if (!(dev_priv->dsr_fb_update & MDFLD_DSR_CURSOR_2))
mdfld_dsi_dbi_exit_dsr(dev, MDFLD_DSR_CURSOR_2);
pos = CURCPOS;
base = CURCBASE;
break;
default:
DRM_ERROR("Illegal Pipe Number. \n");
return -EINVAL;
}
#if 1
if (pipe != 0)
return 0;
#endif
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
if (gma_power_begin(dev, true)) {
REG_WRITE(pos, temp);
REG_WRITE(base, addr);
gma_power_end(dev);
}
return 0;
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
int mdfld__intel_pipe_set_base(struct drm_crtc *crtc, int x, int y, struct drm_framebuffer *old_fb)
{
struct drm_device *dev = crtc->dev;
struct psb_intel_crtc *psb_intel_crtc = to_psb_intel_crtc(crtc);
struct psb_framebuffer *psbfb = to_psb_fb(crtc->fb);
int pipe = psb_intel_crtc->pipe;
unsigned long start, offset;
int dsplinoff = DSPALINOFF;
int dspsurf = DSPASURF;
int dspstride = DSPASTRIDE;
int dspcntr_reg = DSPACNTR;
u32 dspcntr;
int ret = 0;
memcpy(&globle_dev, dev, sizeof(struct drm_device));
if (!gma_power_begin(dev, true))
return 0;
if (!crtc->fb) {
dev_err(dev->dev, "No FB bound\n");
goto psb_intel_pipe_cleaner;
}
switch (pipe) {
case 0:
dsplinoff = DSPALINOFF;
break;
case 1:
dsplinoff = DSPBLINOFF;
dspsurf = DSPBSURF;
dspstride = DSPBSTRIDE;
dspcntr_reg = DSPBCNTR;
break;
case 2:
dsplinoff = DSPCLINOFF;
dspsurf = DSPCSURF;
dspstride = DSPCSTRIDE;
dspcntr_reg = DSPCCNTR;
break;
default:
dev_err(dev->dev, "Illegal Pipe Number.\n");
return -EINVAL;
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
dev_dbg(dev->dev, "Writing base %08lX %08lX %d %d\n",
start, offset, x, y);
REG_WRITE(dsplinoff, offset);
REG_READ(dsplinoff);
REG_WRITE(dspsurf, start);
REG_READ(dspsurf);
psb_intel_pipe_cleaner:
if (old_fb)
psb_gtt_unpin(to_psb_fb(old_fb)->gtt);
psb_intel_pipe_set_base_exit:
gma_power_end(dev);
return ret;
}
void mdfld_disable_crtc (struct drm_device *dev, int pipe)
{
int dpll_reg = MRST_DPLL_A;
int dspcntr_reg = DSPACNTR;
int dspbase_reg = MRST_DSPABASE;
int pipeconf_reg = PIPEACONF;
u32 gen_fifo_stat_reg = GEN_FIFO_STAT_REG;
u32 temp;
switch (pipe) {
case 0:
break;
case 1:
dpll_reg = MDFLD_DPLL_B;
dspcntr_reg = DSPBCNTR;
dspbase_reg = DSPBSURF;
pipeconf_reg = PIPEBCONF;
break;
case 2:
dpll_reg = MRST_DPLL_A;
dspcntr_reg = DSPCCNTR;
dspbase_reg = MDFLD_DSPCBASE;
pipeconf_reg = PIPECCONF;
gen_fifo_stat_reg = GEN_FIFO_STAT_REG + MIPIC_REG_OFFSET;
break;
default:
dev_err(dev->dev, "Illegal Pipe Number. \n");
return;
}
if (pipe != 1)
mdfld_dsi_gen_fifo_ready (dev, gen_fifo_stat_reg, HS_CTRL_FIFO_EMPTY | HS_DATA_FIFO_EMPTY);
temp = REG_READ(dspcntr_reg);
if ((temp & DISPLAY_PLANE_ENABLE) != 0) {
REG_WRITE(dspcntr_reg,
temp & ~DISPLAY_PLANE_ENABLE);
REG_WRITE(dspbase_reg, REG_READ(dspbase_reg));
REG_READ(dspbase_reg);
}
temp = REG_READ(pipeconf_reg);
if ((temp & PIPEACONF_ENABLE) != 0) {
temp &= ~PIPEACONF_ENABLE;
temp |= PIPECONF_PLANE_OFF | PIPECONF_CURSOR_OFF;
REG_WRITE(pipeconf_reg, temp);
REG_READ(pipeconf_reg);
mdfldWaitForPipeDisable(dev, pipe);
}
temp = REG_READ(dpll_reg);
if (temp & DPLL_VCO_ENABLE) {
if (((pipe != 1) && !((REG_READ(PIPEACONF) | REG_READ(PIPECCONF)) & PIPEACONF_ENABLE))
|| (pipe == 1)){
temp &= ~(DPLL_VCO_ENABLE);
REG_WRITE(dpll_reg, temp);
REG_READ(dpll_reg);
udelay(500);
if (!(temp & MDFLD_PWR_GATE_EN)) {
REG_WRITE(dpll_reg, temp | MDFLD_PWR_GATE_EN);
udelay(5000);
}
}
}
}
static void mdfld_crtc_dpms(struct drm_crtc *crtc, int mode)
{
struct drm_device *dev = crtc->dev;
struct drm_psb_private *dev_priv = dev->dev_private;
struct psb_intel_crtc *psb_intel_crtc = to_psb_intel_crtc(crtc);
int pipe = psb_intel_crtc->pipe;
int dpll_reg = MRST_DPLL_A;
int dspcntr_reg = DSPACNTR;
int dspbase_reg = MRST_DSPABASE;
int pipeconf_reg = PIPEACONF;
u32 pipestat_reg = PIPEASTAT;
u32 gen_fifo_stat_reg = GEN_FIFO_STAT_REG;
u32 pipeconf = dev_priv->pipeconf;
u32 dspcntr = dev_priv->dspcntr;
u32 mipi_enable_reg = MIPIA_DEVICE_READY_REG;
u32 temp;
bool enabled;
int timeout = 0;
if (!gma_power_begin(dev, true))
return;
if(0 && dev_priv->dispstatus == false && mode == 3){
if(dev_priv->rpm_enabled && pipe == 1){
pm_request_idle(&dev->pdev->dev);
}
return;
}else if(mode == 0) {
}
switch (pipe) {
case 0:
break;
case 1:
dpll_reg = DPLL_B;
dspcntr_reg = DSPBCNTR;
dspbase_reg = MRST_DSPBBASE;
pipeconf_reg = PIPEBCONF;
pipeconf = dev_priv->pipeconf1;
dspcntr = dev_priv->dspcntr1;
dpll_reg = MDFLD_DPLL_B;
break;
case 2:
dpll_reg = MRST_DPLL_A;
dspcntr_reg = DSPCCNTR;
dspbase_reg = MDFLD_DSPCBASE;
pipeconf_reg = PIPECCONF;
pipestat_reg = PIPECSTAT;
pipeconf = dev_priv->pipeconf2;
dspcntr = dev_priv->dspcntr2;
gen_fifo_stat_reg = GEN_FIFO_STAT_REG + MIPIC_REG_OFFSET;
mipi_enable_reg = MIPIA_DEVICE_READY_REG + MIPIC_REG_OFFSET;
break;
default:
dev_err(dev->dev, "Illegal Pipe Number.\n");
return;
}
switch (mode) {
case DRM_MODE_DPMS_ON:
case DRM_MODE_DPMS_STANDBY:
case DRM_MODE_DPMS_SUSPEND:
temp = REG_READ(dpll_reg);
if ((temp & DPLL_VCO_ENABLE) == 0) {
if (temp & MDFLD_PWR_GATE_EN) {
temp &= ~MDFLD_PWR_GATE_EN;
REG_WRITE(dpll_reg, temp);
udelay(500);
}
REG_WRITE(dpll_reg, temp);
REG_READ(dpll_reg);
udelay(500);
REG_WRITE(dpll_reg, temp | DPLL_VCO_ENABLE);
REG_READ(dpll_reg);
while ((pipe != 2) && (timeout < 20000) && !(REG_READ(pipeconf_reg) & PIPECONF_DSIPLL_LOCK)) {
udelay(150);
timeout ++;
}
}
temp = REG_READ(dspcntr_reg);
if ((temp & DISPLAY_PLANE_ENABLE) == 0) {
REG_WRITE(dspcntr_reg,
temp | DISPLAY_PLANE_ENABLE);
REG_WRITE(dspbase_reg, REG_READ(dspbase_reg));
}
temp = REG_READ(pipeconf_reg);
if ((temp & PIPEACONF_ENABLE) == 0) {
REG_WRITE(pipeconf_reg, pipeconf);
mdfldWaitForPipeEnable(dev, pipe);
}
if ((pipe == 0 || pipe == 2) &&
(mdfld_panel_dpi(dev) == true)) {
REG_WRITE(pipestat_reg, REG_READ(pipestat_reg));
msleep(100);
if(PIPE_VBLANK_STATUS & REG_READ(pipestat_reg)) {
printk(KERN_ALERT "OK");
} else {
printk(KERN_ALERT "STUCK!!!!");
temp = REG_READ(dspcntr_reg);
REG_WRITE(dspcntr_reg, temp & ~DISPLAY_PLANE_ENABLE);
REG_WRITE(dspbase_reg, REG_READ(dspbase_reg));
REG_WRITE(0xb048, 1);
msleep(100);
temp = REG_READ(pipeconf_reg);
temp &= ~PIPEACONF_ENABLE;
REG_WRITE(pipeconf_reg, temp);
msleep(100);
REG_WRITE(mipi_enable_reg, 0);
msleep(100);
printk(KERN_ALERT "70008 is %x\n", REG_READ(0x70008));
printk(KERN_ALERT "b074 is %x\n", REG_READ(0xb074));
REG_WRITE(0xb004, REG_READ(0xb004));
REG_WRITE(mipi_enable_reg, 1);
temp = REG_READ(dspcntr_reg);
REG_WRITE(dspcntr_reg, temp | DISPLAY_PLANE_ENABLE);
REG_WRITE(dspbase_reg, REG_READ(dspbase_reg));
REG_WRITE(0xb048, 2);
msleep(100);
temp = REG_READ(pipeconf_reg);
temp |= PIPEACONF_ENABLE;
REG_WRITE(pipeconf_reg, temp);
}
}
psb_intel_crtc_load_lut(crtc);
break;
case DRM_MODE_DPMS_OFF:
if (pipe != 1)
mdfld_dsi_gen_fifo_ready (dev, gen_fifo_stat_reg, HS_CTRL_FIFO_EMPTY | HS_DATA_FIFO_EMPTY);
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
temp &= ~PIPEACONF_ENABLE;
temp |= PIPECONF_PLANE_OFF | PIPECONF_CURSOR_OFF;
REG_WRITE(pipeconf_reg, temp);
REG_READ(pipeconf_reg);
mdfldWaitForPipeDisable(dev, pipe);
}
temp = REG_READ(dpll_reg);
if (temp & DPLL_VCO_ENABLE) {
if (((pipe != 1) && !((REG_READ(PIPEACONF) | REG_READ(PIPECCONF)) & PIPEACONF_ENABLE))
|| (pipe == 1)){
temp &= ~(DPLL_VCO_ENABLE);
REG_WRITE(dpll_reg, temp);
REG_READ(dpll_reg);
udelay(500);
#if 0
if (!(temp & MDFLD_PWR_GATE_EN)) {
REG_WRITE(dpll_reg, temp | MDFLD_PWR_GATE_EN);
udelay(5000);
}
#endif
}
}
break;
}
enabled = crtc->enabled && mode != DRM_MODE_DPMS_OFF;
#if 0
if (enabled)
dev_priv->vblank_pipe |= (1 << pipe);
else
dev_priv->vblank_pipe &= ~(1 << pipe);
#endif
gma_power_end(dev);
}
static const struct mdfld_limit_t *mdfld_limit(struct drm_crtc *crtc)
{
const struct mdfld_limit_t *limit = NULL;
struct drm_device *dev = crtc->dev;
struct drm_psb_private *dev_priv = dev->dev_private;
if (psb_intel_pipe_has_type(crtc, INTEL_OUTPUT_MIPI)
|| psb_intel_pipe_has_type(crtc, INTEL_OUTPUT_MIPI2)) {
if ((ksel == KSEL_CRYSTAL_19) || (ksel == KSEL_BYPASS_19))
limit = &mdfld_limits[MDFLD_LIMT_DSIPLL_19];
else if (ksel == KSEL_BYPASS_25)
limit = &mdfld_limits[MDFLD_LIMT_DSIPLL_25];
else if ((ksel == KSEL_BYPASS_83_100) && (dev_priv->core_freq == 166))
limit = &mdfld_limits[MDFLD_LIMT_DSIPLL_83];
else if ((ksel == KSEL_BYPASS_83_100) &&
(dev_priv->core_freq == 100 || dev_priv->core_freq == 200))
limit = &mdfld_limits[MDFLD_LIMT_DSIPLL_100];
} else if (psb_intel_pipe_has_type(crtc, INTEL_OUTPUT_HDMI)) {
if ((ksel == KSEL_CRYSTAL_19) || (ksel == KSEL_BYPASS_19))
limit = &mdfld_limits[MDFLD_LIMT_DPLL_19];
else if (ksel == KSEL_BYPASS_25)
limit = &mdfld_limits[MDFLD_LIMT_DPLL_25];
else if ((ksel == KSEL_BYPASS_83_100) && (dev_priv->core_freq == 166))
limit = &mdfld_limits[MDFLD_LIMT_DPLL_83];
else if ((ksel == KSEL_BYPASS_83_100) &&
(dev_priv->core_freq == 100 || dev_priv->core_freq == 200))
limit = &mdfld_limits[MDFLD_LIMT_DPLL_100];
} else {
limit = NULL;
dev_err(dev->dev, "mdfld_limit Wrong display type.\n");
}
return limit;
}
static void mdfld_clock(int refclk, struct mdfld_intel_clock_t *clock)
{
clock->dot = (refclk * clock->m) / clock->p1;
}
static bool
mdfldFindBestPLL(struct drm_crtc *crtc, int target, int refclk,
struct mdfld_intel_clock_t *best_clock)
{
struct mdfld_intel_clock_t clock;
const struct mdfld_limit_t *limit = mdfld_limit(crtc);
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
static int mdfld_panel_fitter_pipe(struct drm_device *dev)
{
u32 pfit_control;
pfit_control = REG_READ(PFIT_CONTROL);
if ((pfit_control & PFIT_ENABLE) == 0)
return -1;
return (pfit_control >> 29) & 3;
}
static int mdfld_crtc_mode_set(struct drm_crtc *crtc,
struct drm_display_mode *mode,
struct drm_display_mode *adjusted_mode,
int x, int y,
struct drm_framebuffer *old_fb)
{
struct drm_device *dev = crtc->dev;
struct psb_intel_crtc *psb_intel_crtc = to_psb_intel_crtc(crtc);
struct drm_psb_private *dev_priv = dev->dev_private;
int pipe = psb_intel_crtc->pipe;
int fp_reg = MRST_FPA0;
int dpll_reg = MRST_DPLL_A;
int dspcntr_reg = DSPACNTR;
int pipeconf_reg = PIPEACONF;
int htot_reg = HTOTAL_A;
int hblank_reg = HBLANK_A;
int hsync_reg = HSYNC_A;
int vtot_reg = VTOTAL_A;
int vblank_reg = VBLANK_A;
int vsync_reg = VSYNC_A;
int dspsize_reg = DSPASIZE;
int dsppos_reg = DSPAPOS;
int pipesrc_reg = PIPEASRC;
u32 *pipeconf = &dev_priv->pipeconf;
u32 *dspcntr = &dev_priv->dspcntr;
int refclk = 0;
int clk_n = 0, clk_p2 = 0, clk_byte = 1, clk = 0, m_conv = 0, clk_tmp = 0;
struct mdfld_intel_clock_t clock;
bool ok;
u32 dpll = 0, fp = 0;
bool is_crt = false, is_lvds = false, is_tv = false;
bool is_mipi = false, is_mipi2 = false, is_hdmi = false;
struct drm_mode_config *mode_config = &dev->mode_config;
struct psb_intel_output *psb_intel_output = NULL;
uint64_t scalingType = DRM_MODE_SCALE_FULLSCREEN;
struct drm_encoder *encoder;
struct drm_connector *connector;
int timeout = 0;
dev_dbg(dev->dev, "pipe = 0x%x \n", pipe);
switch (pipe) {
case 0:
break;
case 1:
fp_reg = FPB0;
dpll_reg = DPLL_B;
dspcntr_reg = DSPBCNTR;
pipeconf_reg = PIPEBCONF;
htot_reg = HTOTAL_B;
hblank_reg = HBLANK_B;
hsync_reg = HSYNC_B;
vtot_reg = VTOTAL_B;
vblank_reg = VBLANK_B;
vsync_reg = VSYNC_B;
dspsize_reg = DSPBSIZE;
dsppos_reg = DSPBPOS;
pipesrc_reg = PIPEBSRC;
pipeconf = &dev_priv->pipeconf1;
dspcntr = &dev_priv->dspcntr1;
fp_reg = MDFLD_DPLL_DIV0;
dpll_reg = MDFLD_DPLL_B;
break;
case 2:
dpll_reg = MRST_DPLL_A;
dspcntr_reg = DSPCCNTR;
pipeconf_reg = PIPECCONF;
htot_reg = HTOTAL_C;
hblank_reg = HBLANK_C;
hsync_reg = HSYNC_C;
vtot_reg = VTOTAL_C;
vblank_reg = VBLANK_C;
vsync_reg = VSYNC_C;
dspsize_reg = DSPCSIZE;
dsppos_reg = DSPCPOS;
pipesrc_reg = PIPECSRC;
pipeconf = &dev_priv->pipeconf2;
dspcntr = &dev_priv->dspcntr2;
break;
default:
DRM_ERROR("Illegal Pipe Number. \n");
return 0;
}
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
memcpy(&psb_intel_crtc->saved_mode, mode, sizeof(struct drm_display_mode));
memcpy(&psb_intel_crtc->saved_adjusted_mode, adjusted_mode, sizeof(struct drm_display_mode));
list_for_each_entry(connector, &mode_config->connector_list, head) {
encoder = connector->encoder;
if(!encoder)
continue;
if (encoder->crtc != crtc)
continue;
psb_intel_output = to_psb_intel_output(connector);
dev_dbg(dev->dev, "output->type = 0x%x \n", psb_intel_output->type);
switch (psb_intel_output->type) {
case INTEL_OUTPUT_LVDS:
is_lvds = true;
break;
case INTEL_OUTPUT_TVOUT:
is_tv = true;
break;
case INTEL_OUTPUT_ANALOG:
is_crt = true;
break;
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
if (mdfld_panel_fitter_pipe(dev) == pipe)
REG_WRITE(PFIT_CONTROL, 0);
if (pipe == 1) {
REG_WRITE(dspsize_reg, ((MIN(mode->crtc_vdisplay, adjusted_mode->crtc_vdisplay) - 1) << 16)
| (MIN(mode->crtc_hdisplay, adjusted_mode->crtc_hdisplay) - 1));
REG_WRITE(pipesrc_reg, ((mode->crtc_hdisplay - 1) << 16)
| (mode->crtc_vdisplay - 1));
} else {
REG_WRITE(dspsize_reg, ((mode->crtc_vdisplay - 1) << 16) | (mode->crtc_hdisplay - 1));
REG_WRITE(pipesrc_reg, ((mode->crtc_hdisplay - 1) << 16) | (mode->crtc_vdisplay - 1));
}
REG_WRITE(dsppos_reg, 0);
if (psb_intel_output)
drm_connector_property_get_value(&psb_intel_output->base,
dev->mode_config.scaling_mode_property, &scalingType);
if (scalingType == DRM_MODE_SCALE_NO_SCALE) {
int offsetX = 0, offsetY = 0;
offsetX = (adjusted_mode->crtc_hdisplay - mode->crtc_hdisplay) / 2;
offsetY = (adjusted_mode->crtc_vdisplay - mode->crtc_vdisplay) / 2;
REG_WRITE(htot_reg, (mode->crtc_hdisplay - 1) |
((adjusted_mode->crtc_htotal - 1) << 16));
REG_WRITE(vtot_reg, (mode->crtc_vdisplay - 1) |
((adjusted_mode->crtc_vtotal - 1) << 16));
REG_WRITE(hblank_reg, (adjusted_mode->crtc_hblank_start - offsetX - 1) |
((adjusted_mode->crtc_hblank_end - offsetX - 1) << 16));
REG_WRITE(hsync_reg, (adjusted_mode->crtc_hsync_start - offsetX - 1) |
((adjusted_mode->crtc_hsync_end - offsetX - 1) << 16));
REG_WRITE(vblank_reg, (adjusted_mode->crtc_vblank_start - offsetY - 1) |
((adjusted_mode->crtc_vblank_end - offsetY - 1) << 16));
REG_WRITE(vsync_reg, (adjusted_mode->crtc_vsync_start - offsetY - 1) |
((adjusted_mode->crtc_vsync_end - offsetY - 1) << 16));
} else {
REG_WRITE(htot_reg, (adjusted_mode->crtc_hdisplay - 1) |
((adjusted_mode->crtc_htotal - 1) << 16));
REG_WRITE(vtot_reg, (adjusted_mode->crtc_vdisplay - 1) |
((adjusted_mode->crtc_vtotal - 1) << 16));
REG_WRITE(hblank_reg, (adjusted_mode->crtc_hblank_start - 1) |
((adjusted_mode->crtc_hblank_end - 1) << 16));
REG_WRITE(hsync_reg, (adjusted_mode->crtc_hsync_start - 1) |
((adjusted_mode->crtc_hsync_end - 1) << 16));
REG_WRITE(vblank_reg, (adjusted_mode->crtc_vblank_start - 1) |
((adjusted_mode->crtc_vblank_end - 1) << 16));
REG_WRITE(vsync_reg, (adjusted_mode->crtc_vsync_start - 1) |
((adjusted_mode->crtc_vsync_end - 1) << 16));
}
{
struct drm_crtc_helper_funcs *crtc_funcs =
crtc->helper_private;
crtc_funcs->mode_set_base(crtc, x, y, old_fb);
}
*pipeconf = PIPEACONF_ENABLE;
*dspcntr = REG_READ(dspcntr_reg);
*dspcntr |= pipe << DISPPLANE_SEL_PIPE_POS;
*dspcntr |= DISPLAY_PLANE_ENABLE;
if (is_mipi2)
{
goto mrst_crtc_mode_set_exit;
}
clk = adjusted_mode->clock;
if (is_hdmi) {
if ((ksel == KSEL_CRYSTAL_19) || (ksel == KSEL_BYPASS_19))
{
refclk = 19200;
if (is_mipi || is_mipi2)
{
clk_n = 1, clk_p2 = 8;
} else if (is_hdmi) {
clk_n = 1, clk_p2 = 10;
}
} else if (ksel == KSEL_BYPASS_25) {
refclk = 25000;
if (is_mipi || is_mipi2)
{
clk_n = 1, clk_p2 = 8;
} else if (is_hdmi) {
clk_n = 1, clk_p2 = 10;
}
} else if ((ksel == KSEL_BYPASS_83_100) && (dev_priv->core_freq == 166)) {
refclk = 83000;
if (is_mipi || is_mipi2)
{
clk_n = 4, clk_p2 = 8;
} else if (is_hdmi) {
clk_n = 4, clk_p2 = 10;
}
} else if ((ksel == KSEL_BYPASS_83_100) &&
(dev_priv->core_freq == 100 || dev_priv->core_freq == 200)) {
refclk = 100000;
if (is_mipi || is_mipi2)
{
clk_n = 4, clk_p2 = 8;
} else if (is_hdmi) {
clk_n = 4, clk_p2 = 10;
}
}
if (is_mipi)
clk_byte = dev_priv->bpp / 8;
else if (is_mipi2)
clk_byte = dev_priv->bpp2 / 8;
clk_tmp = clk * clk_n * clk_p2 * clk_byte;
dev_dbg(dev->dev, "clk = %d, clk_n = %d, clk_p2 = %d. \n", clk, clk_n, clk_p2);
dev_dbg(dev->dev, "adjusted_mode->clock = %d, clk_tmp = %d. \n", adjusted_mode->clock, clk_tmp);
ok = mdfldFindBestPLL(crtc, clk_tmp, refclk, &clock);
if (!ok) {
dev_err(dev->dev,
"mdfldFindBestPLL fail in mdfld_crtc_mode_set. \n");
} else {
m_conv = mdfld_m_converts[(clock.m - MDFLD_M_MIN)];
dev_dbg(dev->dev, "dot clock = %d,"
"m = %d, p1 = %d, m_conv = %d. \n", clock.dot, clock.m,
clock.p1, m_conv);
}
dpll = REG_READ(dpll_reg);
if (dpll & DPLL_VCO_ENABLE) {
dpll &= ~DPLL_VCO_ENABLE;
REG_WRITE(dpll_reg, dpll);
REG_READ(dpll_reg);
udelay(500);
REG_WRITE(fp_reg, 0);
dpll &= ~MDFLD_P1_MASK;
REG_WRITE(dpll_reg, dpll);
udelay(500);
}
if (dpll & MDFLD_PWR_GATE_EN) {
dpll &= ~MDFLD_PWR_GATE_EN;
REG_WRITE(dpll_reg, dpll);
udelay(500);
}
dpll = 0;
#if 0
if ((ksel == KSEL_CRYSTAL_19) || (ksel == KSEL_BYPASS_19) || (ksel == KSEL_BYPASS_25)) {
dpll &= ~MDFLD_INPUT_REF_SEL;
} else if (ksel == KSEL_BYPASS_83_100) {
dpll |= MDFLD_INPUT_REF_SEL;
}
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
REG_WRITE(fp_reg, fp);
REG_WRITE(dpll_reg, dpll);
udelay(500);
dpll |= DPLL_VCO_ENABLE;
REG_WRITE(dpll_reg, dpll);
REG_READ(dpll_reg);
while ((timeout < 20000) && !(REG_READ(pipeconf_reg) & PIPECONF_DSIPLL_LOCK)) {
udelay(150);
timeout ++;
}
if (is_mipi)
goto mrst_crtc_mode_set_exit;
dev_dbg(dev->dev, "is_mipi = 0x%x \n", is_mipi);
REG_WRITE(pipeconf_reg, *pipeconf);
REG_READ(pipeconf_reg);
REG_WRITE(dspcntr_reg, *dspcntr);
psb_intel_wait_for_vblank(dev);
mrst_crtc_mode_set_exit:
gma_power_end(dev);
return 0;
}
static void mdfld_crtc_prepare(struct drm_crtc *crtc)
{
struct drm_crtc_helper_funcs *crtc_funcs = crtc->helper_private;
crtc_funcs->dpms(crtc, DRM_MODE_DPMS_OFF);
}
static void mdfld_crtc_commit(struct drm_crtc *crtc)
{
struct drm_crtc_helper_funcs *crtc_funcs = crtc->helper_private;
crtc_funcs->dpms(crtc, DRM_MODE_DPMS_ON);
}
static bool mdfld_crtc_mode_fixup(struct drm_crtc *crtc,
struct drm_display_mode *mode,
struct drm_display_mode *adjusted_mode)
{
return true;
}
