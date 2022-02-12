void
armada_drm_crtc_update_regs(struct armada_crtc *dcrtc, struct armada_regs *regs)
{
while (regs->offset != ~0) {
void __iomem *reg = dcrtc->base + regs->offset;
uint32_t val;
val = regs->mask;
if (val != 0)
val &= readl_relaxed(reg);
writel_relaxed(val | regs->val, reg);
++regs;
}
}
static void armada_drm_crtc_update(struct armada_crtc *dcrtc)
{
uint32_t dumb_ctrl;
dumb_ctrl = dcrtc->cfg_dumb_ctrl;
if (!dpms_blanked(dcrtc->dpms))
dumb_ctrl |= CFG_DUMB_ENA;
if (dpms_blanked(dcrtc->dpms) &&
(dumb_ctrl & DUMB_MASK) == DUMB24_RGB888_0) {
dumb_ctrl &= ~DUMB_MASK;
dumb_ctrl |= DUMB_BLANK;
}
if (dcrtc->crtc.mode.flags & DRM_MODE_FLAG_NCSYNC)
dumb_ctrl |= CFG_INV_CSYNC;
if (dcrtc->crtc.mode.flags & DRM_MODE_FLAG_NHSYNC)
dumb_ctrl |= CFG_INV_HSYNC;
if (dcrtc->crtc.mode.flags & DRM_MODE_FLAG_NVSYNC)
dumb_ctrl |= CFG_INV_VSYNC;
if (dcrtc->dumb_ctrl != dumb_ctrl) {
dcrtc->dumb_ctrl = dumb_ctrl;
writel_relaxed(dumb_ctrl, dcrtc->base + LCD_SPU_DUMB_CTRL);
}
}
static unsigned armada_drm_crtc_calc_fb(struct drm_framebuffer *fb,
int x, int y, struct armada_regs *regs, bool interlaced)
{
struct armada_gem_object *obj = drm_fb_obj(fb);
unsigned pitch = fb->pitches[0];
unsigned offset = y * pitch + x * fb->bits_per_pixel / 8;
uint32_t addr_odd, addr_even;
unsigned i = 0;
DRM_DEBUG_DRIVER("pitch %u x %d y %d bpp %d\n",
pitch, x, y, fb->bits_per_pixel);
addr_odd = addr_even = obj->dev_addr + offset;
if (interlaced) {
addr_even += pitch;
pitch *= 2;
}
armada_reg_queue_set(regs, i, addr_odd, LCD_CFG_GRA_START_ADDR0);
armada_reg_queue_set(regs, i, addr_even, LCD_CFG_GRA_START_ADDR1);
armada_reg_queue_mod(regs, i, pitch, 0xffff, LCD_CFG_GRA_PITCH);
return i;
}
static void armada_drm_plane_work_run(struct armada_crtc *dcrtc,
struct armada_plane *plane)
{
struct armada_plane_work *work = xchg(&plane->work, NULL);
if (work) {
work->fn(dcrtc, plane, work);
drm_vblank_put(dcrtc->crtc.dev, dcrtc->num);
}
wake_up(&plane->frame_wait);
}
int armada_drm_plane_work_queue(struct armada_crtc *dcrtc,
struct armada_plane *plane, struct armada_plane_work *work)
{
int ret;
ret = drm_vblank_get(dcrtc->crtc.dev, dcrtc->num);
if (ret) {
DRM_ERROR("failed to acquire vblank counter\n");
return ret;
}
ret = cmpxchg(&plane->work, NULL, work) ? -EBUSY : 0;
if (ret)
drm_vblank_put(dcrtc->crtc.dev, dcrtc->num);
return ret;
}
int armada_drm_plane_work_wait(struct armada_plane *plane, long timeout)
{
return wait_event_timeout(plane->frame_wait, !plane->work, timeout);
}
struct armada_plane_work *armada_drm_plane_work_cancel(
struct armada_crtc *dcrtc, struct armada_plane *plane)
{
struct armada_plane_work *work = xchg(&plane->work, NULL);
if (work)
drm_vblank_put(dcrtc->crtc.dev, dcrtc->num);
return work;
}
static int armada_drm_crtc_queue_frame_work(struct armada_crtc *dcrtc,
struct armada_frame_work *work)
{
struct armada_plane *plane = drm_to_armada_plane(dcrtc->crtc.primary);
return armada_drm_plane_work_queue(dcrtc, plane, &work->work);
}
static void armada_drm_crtc_complete_frame_work(struct armada_crtc *dcrtc,
struct armada_plane *plane, struct armada_plane_work *work)
{
struct armada_frame_work *fwork = container_of(work, struct armada_frame_work, work);
struct drm_device *dev = dcrtc->crtc.dev;
unsigned long flags;
spin_lock_irqsave(&dcrtc->irq_lock, flags);
armada_drm_crtc_update_regs(dcrtc, fwork->regs);
spin_unlock_irqrestore(&dcrtc->irq_lock, flags);
if (fwork->event) {
spin_lock_irqsave(&dev->event_lock, flags);
drm_send_vblank_event(dev, dcrtc->num, fwork->event);
spin_unlock_irqrestore(&dev->event_lock, flags);
}
__armada_drm_queue_unref_work(dcrtc->crtc.dev, fwork->old_fb);
kfree(fwork);
}
static void armada_drm_crtc_finish_fb(struct armada_crtc *dcrtc,
struct drm_framebuffer *fb, bool force)
{
struct armada_frame_work *work;
if (!fb)
return;
if (force) {
drm_framebuffer_unreference(fb);
return;
}
work = kmalloc(sizeof(*work), GFP_KERNEL);
if (work) {
int i = 0;
work->work.fn = armada_drm_crtc_complete_frame_work;
work->event = NULL;
work->old_fb = fb;
armada_reg_queue_end(work->regs, i);
if (armada_drm_crtc_queue_frame_work(dcrtc, work) == 0)
return;
kfree(work);
}
drm_framebuffer_unreference(fb);
}
static void armada_drm_vblank_off(struct armada_crtc *dcrtc)
{
struct armada_plane *plane = drm_to_armada_plane(dcrtc->crtc.primary);
drm_crtc_vblank_off(&dcrtc->crtc);
armada_drm_plane_work_run(dcrtc, plane);
}
void armada_drm_crtc_gamma_set(struct drm_crtc *crtc, u16 r, u16 g, u16 b,
int idx)
{
}
void armada_drm_crtc_gamma_get(struct drm_crtc *crtc, u16 *r, u16 *g, u16 *b,
int idx)
{
}
static void armada_drm_crtc_dpms(struct drm_crtc *crtc, int dpms)
{
struct armada_crtc *dcrtc = drm_to_armada_crtc(crtc);
if (dcrtc->dpms != dpms) {
dcrtc->dpms = dpms;
if (!IS_ERR(dcrtc->clk) && !dpms_blanked(dpms))
WARN_ON(clk_prepare_enable(dcrtc->clk));
armada_drm_crtc_update(dcrtc);
if (!IS_ERR(dcrtc->clk) && dpms_blanked(dpms))
clk_disable_unprepare(dcrtc->clk);
if (dpms_blanked(dpms))
armada_drm_vblank_off(dcrtc);
else
drm_crtc_vblank_on(&dcrtc->crtc);
}
}
static void armada_drm_crtc_prepare(struct drm_crtc *crtc)
{
struct armada_crtc *dcrtc = drm_to_armada_crtc(crtc);
struct drm_plane *plane;
plane = dcrtc->plane;
if (plane)
drm_plane_force_disable(plane);
}
static void armada_drm_crtc_commit(struct drm_crtc *crtc)
{
struct armada_crtc *dcrtc = drm_to_armada_crtc(crtc);
if (dcrtc->dpms != DRM_MODE_DPMS_ON) {
dcrtc->dpms = DRM_MODE_DPMS_ON;
armada_drm_crtc_update(dcrtc);
}
}
static bool armada_drm_crtc_mode_fixup(struct drm_crtc *crtc,
const struct drm_display_mode *mode, struct drm_display_mode *adj)
{
struct armada_crtc *dcrtc = drm_to_armada_crtc(crtc);
int ret;
if (!dcrtc->variant->has_spu_adv_reg &&
adj->flags & DRM_MODE_FLAG_INTERLACE)
return false;
ret = dcrtc->variant->compute_clock(dcrtc, adj, NULL);
if (ret)
return false;
return true;
}
static void armada_drm_crtc_irq(struct armada_crtc *dcrtc, u32 stat)
{
void __iomem *base = dcrtc->base;
struct drm_plane *ovl_plane;
if (stat & DMA_FF_UNDERFLOW)
DRM_ERROR("video underflow on crtc %u\n", dcrtc->num);
if (stat & GRA_FF_UNDERFLOW)
DRM_ERROR("graphics underflow on crtc %u\n", dcrtc->num);
if (stat & VSYNC_IRQ)
drm_handle_vblank(dcrtc->crtc.dev, dcrtc->num);
spin_lock(&dcrtc->irq_lock);
ovl_plane = dcrtc->plane;
if (ovl_plane) {
struct armada_plane *plane = drm_to_armada_plane(ovl_plane);
armada_drm_plane_work_run(dcrtc, plane);
}
if (stat & GRA_FRAME_IRQ && dcrtc->interlaced) {
int i = stat & GRA_FRAME_IRQ0 ? 0 : 1;
uint32_t val;
writel_relaxed(dcrtc->v[i].spu_v_porch, base + LCD_SPU_V_PORCH);
writel_relaxed(dcrtc->v[i].spu_v_h_total,
base + LCD_SPUT_V_H_TOTAL);
val = readl_relaxed(base + LCD_SPU_ADV_REG);
val &= ~(ADV_VSYNC_L_OFF | ADV_VSYNC_H_OFF | ADV_VSYNCOFFEN);
val |= dcrtc->v[i].spu_adv_reg;
writel_relaxed(val, base + LCD_SPU_ADV_REG);
}
if (stat & DUMB_FRAMEDONE && dcrtc->cursor_update) {
writel_relaxed(dcrtc->cursor_hw_pos,
base + LCD_SPU_HWC_OVSA_HPXL_VLN);
writel_relaxed(dcrtc->cursor_hw_sz,
base + LCD_SPU_HWC_HPXL_VLN);
armada_updatel(CFG_HWC_ENA,
CFG_HWC_ENA | CFG_HWC_1BITMOD | CFG_HWC_1BITENA,
base + LCD_SPU_DMA_CTRL0);
dcrtc->cursor_update = false;
armada_drm_crtc_disable_irq(dcrtc, DUMB_FRAMEDONE_ENA);
}
spin_unlock(&dcrtc->irq_lock);
if (stat & GRA_FRAME_IRQ) {
struct armada_plane *plane = drm_to_armada_plane(dcrtc->crtc.primary);
armada_drm_plane_work_run(dcrtc, plane);
}
}
static irqreturn_t armada_drm_irq(int irq, void *arg)
{
struct armada_crtc *dcrtc = arg;
u32 v, stat = readl_relaxed(dcrtc->base + LCD_SPU_IRQ_ISR);
writel_relaxed(0, dcrtc->base + LCD_SPU_IRQ_ISR);
v = stat & dcrtc->irq_ena;
if (v & (VSYNC_IRQ|GRA_FRAME_IRQ|DUMB_FRAMEDONE)) {
armada_drm_crtc_irq(dcrtc, stat);
return IRQ_HANDLED;
}
return IRQ_NONE;
}
void armada_drm_crtc_disable_irq(struct armada_crtc *dcrtc, u32 mask)
{
if (dcrtc->irq_ena & mask) {
dcrtc->irq_ena &= ~mask;
writel(dcrtc->irq_ena, dcrtc->base + LCD_SPU_IRQ_ENA);
}
}
void armada_drm_crtc_enable_irq(struct armada_crtc *dcrtc, u32 mask)
{
if ((dcrtc->irq_ena & mask) != mask) {
dcrtc->irq_ena |= mask;
writel(dcrtc->irq_ena, dcrtc->base + LCD_SPU_IRQ_ENA);
if (readl_relaxed(dcrtc->base + LCD_SPU_IRQ_ISR) & mask)
writel(0, dcrtc->base + LCD_SPU_IRQ_ISR);
}
}
static uint32_t armada_drm_crtc_calculate_csc(struct armada_crtc *dcrtc)
{
struct drm_display_mode *adj = &dcrtc->crtc.mode;
uint32_t val = 0;
if (dcrtc->csc_yuv_mode == CSC_YUV_CCIR709)
val |= CFG_CSC_YUV_CCIR709;
if (dcrtc->csc_rgb_mode == CSC_RGB_STUDIO)
val |= CFG_CSC_RGB_STUDIO;
if ((adj->hdisplay == 1280 && adj->vdisplay == 720 &&
!(adj->flags & DRM_MODE_FLAG_INTERLACE)) ||
(adj->hdisplay == 1920 && adj->vdisplay == 1080)) {
if (dcrtc->csc_yuv_mode == CSC_AUTO)
val |= CFG_CSC_YUV_CCIR709;
}
if (dcrtc->csc_rgb_mode == CSC_AUTO)
val |= CFG_CSC_RGB_STUDIO;
return val;
}
static int armada_drm_crtc_mode_set(struct drm_crtc *crtc,
struct drm_display_mode *mode, struct drm_display_mode *adj,
int x, int y, struct drm_framebuffer *old_fb)
{
struct armada_crtc *dcrtc = drm_to_armada_crtc(crtc);
struct armada_regs regs[17];
uint32_t lm, rm, tm, bm, val, sclk;
unsigned long flags;
unsigned i;
bool interlaced;
drm_framebuffer_reference(crtc->primary->fb);
interlaced = !!(adj->flags & DRM_MODE_FLAG_INTERLACE);
i = armada_drm_crtc_calc_fb(dcrtc->crtc.primary->fb,
x, y, regs, interlaced);
rm = adj->crtc_hsync_start - adj->crtc_hdisplay;
lm = adj->crtc_htotal - adj->crtc_hsync_end;
bm = adj->crtc_vsync_start - adj->crtc_vdisplay;
tm = adj->crtc_vtotal - adj->crtc_vsync_end;
DRM_DEBUG_DRIVER("H: %d %d %d %d lm %d rm %d\n",
adj->crtc_hdisplay,
adj->crtc_hsync_start,
adj->crtc_hsync_end,
adj->crtc_htotal, lm, rm);
DRM_DEBUG_DRIVER("V: %d %d %d %d tm %d bm %d\n",
adj->crtc_vdisplay,
adj->crtc_vsync_start,
adj->crtc_vsync_end,
adj->crtc_vtotal, tm, bm);
armada_drm_plane_work_wait(drm_to_armada_plane(dcrtc->crtc.primary),
MAX_SCHEDULE_TIMEOUT);
drm_crtc_vblank_off(crtc);
val = dcrtc->dumb_ctrl & ~CFG_DUMB_ENA;
if (val != dcrtc->dumb_ctrl) {
dcrtc->dumb_ctrl = val;
writel_relaxed(val, dcrtc->base + LCD_SPU_DUMB_CTRL);
}
if (!IS_ERR(dcrtc->clk) && dpms_blanked(dcrtc->dpms))
WARN_ON(clk_prepare_enable(dcrtc->clk));
dcrtc->variant->compute_clock(dcrtc, adj, &sclk);
armada_reg_queue_mod(regs, i, 0, CFG_PDWN64x66, LCD_SPU_SRAM_PARA1);
armada_reg_queue_set(regs, i, sclk, LCD_CFG_SCLK_DIV);
if (interlaced ^ dcrtc->interlaced) {
if (adj->flags & DRM_MODE_FLAG_INTERLACE)
drm_vblank_get(dcrtc->crtc.dev, dcrtc->num);
else
drm_vblank_put(dcrtc->crtc.dev, dcrtc->num);
dcrtc->interlaced = interlaced;
}
spin_lock_irqsave(&dcrtc->irq_lock, flags);
dcrtc->v[1].spu_v_h_total = adj->crtc_vtotal << 16 |
adj->crtc_htotal;
dcrtc->v[1].spu_v_porch = tm << 16 | bm;
val = adj->crtc_hsync_start;
dcrtc->v[1].spu_adv_reg = val << 20 | val | ADV_VSYNCOFFEN |
dcrtc->variant->spu_adv_reg;
if (interlaced) {
dcrtc->v[0].spu_v_h_total = dcrtc->v[1].spu_v_h_total +
(1 << 16);
dcrtc->v[0].spu_v_porch = dcrtc->v[1].spu_v_porch + 1;
val = adj->crtc_hsync_start - adj->crtc_htotal / 2;
dcrtc->v[0].spu_adv_reg = val << 20 | val | ADV_VSYNCOFFEN |
dcrtc->variant->spu_adv_reg;
} else {
dcrtc->v[0] = dcrtc->v[1];
}
val = adj->crtc_vdisplay << 16 | adj->crtc_hdisplay;
armada_reg_queue_set(regs, i, val, LCD_SPU_V_H_ACTIVE);
armada_reg_queue_set(regs, i, val, LCD_SPU_GRA_HPXL_VLN);
armada_reg_queue_set(regs, i, val, LCD_SPU_GZM_HPXL_VLN);
armada_reg_queue_set(regs, i, (lm << 16) | rm, LCD_SPU_H_PORCH);
armada_reg_queue_set(regs, i, dcrtc->v[0].spu_v_porch, LCD_SPU_V_PORCH);
armada_reg_queue_set(regs, i, dcrtc->v[0].spu_v_h_total,
LCD_SPUT_V_H_TOTAL);
if (dcrtc->variant->has_spu_adv_reg) {
armada_reg_queue_mod(regs, i, dcrtc->v[0].spu_adv_reg,
ADV_VSYNC_L_OFF | ADV_VSYNC_H_OFF |
ADV_VSYNCOFFEN, LCD_SPU_ADV_REG);
}
val = CFG_GRA_ENA | CFG_GRA_HSMOOTH;
val |= CFG_GRA_FMT(drm_fb_to_armada_fb(dcrtc->crtc.primary->fb)->fmt);
val |= CFG_GRA_MOD(drm_fb_to_armada_fb(dcrtc->crtc.primary->fb)->mod);
if (drm_fb_to_armada_fb(dcrtc->crtc.primary->fb)->fmt > CFG_420)
val |= CFG_PALETTE_ENA;
if (interlaced)
val |= CFG_GRA_FTOGGLE;
armada_reg_queue_mod(regs, i, val, CFG_GRAFORMAT |
CFG_GRA_MOD(CFG_SWAPRB | CFG_SWAPUV |
CFG_SWAPYU | CFG_YUV2RGB) |
CFG_PALETTE_ENA | CFG_GRA_FTOGGLE,
LCD_SPU_DMA_CTRL0);
val = adj->flags & DRM_MODE_FLAG_NVSYNC ? CFG_VSYNC_INV : 0;
armada_reg_queue_mod(regs, i, val, CFG_VSYNC_INV, LCD_SPU_DMA_CTRL1);
val = dcrtc->spu_iopad_ctrl | armada_drm_crtc_calculate_csc(dcrtc);
armada_reg_queue_set(regs, i, val, LCD_SPU_IOPAD_CONTROL);
armada_reg_queue_end(regs, i);
armada_drm_crtc_update_regs(dcrtc, regs);
spin_unlock_irqrestore(&dcrtc->irq_lock, flags);
armada_drm_crtc_update(dcrtc);
drm_crtc_vblank_on(crtc);
armada_drm_crtc_finish_fb(dcrtc, old_fb, dpms_blanked(dcrtc->dpms));
return 0;
}
static int armada_drm_crtc_mode_set_base(struct drm_crtc *crtc, int x, int y,
struct drm_framebuffer *old_fb)
{
struct armada_crtc *dcrtc = drm_to_armada_crtc(crtc);
struct armada_regs regs[4];
unsigned i;
i = armada_drm_crtc_calc_fb(crtc->primary->fb, crtc->x, crtc->y, regs,
dcrtc->interlaced);
armada_reg_queue_end(regs, i);
armada_drm_plane_work_wait(drm_to_armada_plane(dcrtc->crtc.primary),
MAX_SCHEDULE_TIMEOUT);
drm_framebuffer_reference(crtc->primary->fb);
armada_drm_crtc_update_regs(dcrtc, regs);
armada_drm_crtc_finish_fb(dcrtc, old_fb, dpms_blanked(dcrtc->dpms));
return 0;
}
void armada_drm_crtc_plane_disable(struct armada_crtc *dcrtc,
struct drm_plane *plane)
{
u32 sram_para1, dma_ctrl0_mask;
if (plane->fb)
drm_framebuffer_unreference(plane->fb);
sram_para1 = CFG_PDWN16x66 | CFG_PDWN32x66;
if (plane->type == DRM_PLANE_TYPE_PRIMARY) {
sram_para1 |= CFG_PDWN256x32 | CFG_PDWN256x24 | CFG_PDWN256x8 |
CFG_PDWN32x32 | CFG_PDWN64x66;
dma_ctrl0_mask = CFG_GRA_ENA;
} else {
dma_ctrl0_mask = CFG_DMA_ENA;
}
spin_lock_irq(&dcrtc->irq_lock);
armada_updatel(0, dma_ctrl0_mask, dcrtc->base + LCD_SPU_DMA_CTRL0);
spin_unlock_irq(&dcrtc->irq_lock);
armada_updatel(sram_para1, 0, dcrtc->base + LCD_SPU_SRAM_PARA1);
}
static void armada_drm_crtc_disable(struct drm_crtc *crtc)
{
struct armada_crtc *dcrtc = drm_to_armada_crtc(crtc);
armada_drm_crtc_dpms(crtc, DRM_MODE_DPMS_OFF);
armada_drm_crtc_plane_disable(dcrtc, crtc->primary);
}
static void armada_load_cursor_argb(void __iomem *base, uint32_t *pix,
unsigned stride, unsigned width, unsigned height)
{
uint32_t addr;
unsigned y;
addr = SRAM_HWC32_RAM1;
for (y = 0; y < height; y++) {
uint32_t *p = &pix[y * stride];
unsigned x;
for (x = 0; x < width; x++, p++) {
uint32_t val = *p;
val = (val & 0xff00ff00) |
(val & 0x000000ff) << 16 |
(val & 0x00ff0000) >> 16;
writel_relaxed(val,
base + LCD_SPU_SRAM_WRDAT);
writel_relaxed(addr | SRAM_WRITE,
base + LCD_SPU_SRAM_CTRL);
readl_relaxed(base + LCD_SPU_HWC_OVSA_HPXL_VLN);
addr += 1;
if ((addr & 0x00ff) == 0)
addr += 0xf00;
if ((addr & 0x30ff) == 0)
addr = SRAM_HWC32_RAM2;
}
}
}
static void armada_drm_crtc_cursor_tran(void __iomem *base)
{
unsigned addr;
for (addr = 0; addr < 256; addr++) {
writel_relaxed(0x55555555, base + LCD_SPU_SRAM_WRDAT);
writel_relaxed(addr | SRAM_WRITE | SRAM_HWC32_TRAN,
base + LCD_SPU_SRAM_CTRL);
}
}
static int armada_drm_crtc_cursor_update(struct armada_crtc *dcrtc, bool reload)
{
uint32_t xoff, xscr, w = dcrtc->cursor_w, s;
uint32_t yoff, yscr, h = dcrtc->cursor_h;
uint32_t para1;
if (dcrtc->cursor_x < 0) {
xoff = -dcrtc->cursor_x;
xscr = 0;
w -= min(xoff, w);
} else if (dcrtc->cursor_x + w > dcrtc->crtc.mode.hdisplay) {
xoff = 0;
xscr = dcrtc->cursor_x;
w = max_t(int, dcrtc->crtc.mode.hdisplay - dcrtc->cursor_x, 0);
} else {
xoff = 0;
xscr = dcrtc->cursor_x;
}
if (dcrtc->cursor_y < 0) {
yoff = -dcrtc->cursor_y;
yscr = 0;
h -= min(yoff, h);
} else if (dcrtc->cursor_y + h > dcrtc->crtc.mode.vdisplay) {
yoff = 0;
yscr = dcrtc->cursor_y;
h = max_t(int, dcrtc->crtc.mode.vdisplay - dcrtc->cursor_y, 0);
} else {
yoff = 0;
yscr = dcrtc->cursor_y;
}
s = dcrtc->cursor_w;
if (dcrtc->interlaced) {
s *= 2;
yscr /= 2;
h /= 2;
}
if (!dcrtc->cursor_obj || !h || !w) {
spin_lock_irq(&dcrtc->irq_lock);
armada_drm_crtc_disable_irq(dcrtc, DUMB_FRAMEDONE_ENA);
dcrtc->cursor_update = false;
armada_updatel(0, CFG_HWC_ENA, dcrtc->base + LCD_SPU_DMA_CTRL0);
spin_unlock_irq(&dcrtc->irq_lock);
return 0;
}
para1 = readl_relaxed(dcrtc->base + LCD_SPU_SRAM_PARA1);
armada_updatel(CFG_CSB_256x32, CFG_CSB_256x32 | CFG_PDWN256x32,
dcrtc->base + LCD_SPU_SRAM_PARA1);
if (!(para1 & CFG_CSB_256x32)) {
armada_drm_crtc_cursor_tran(dcrtc->base);
reload = true;
}
if (dcrtc->cursor_hw_sz != (h << 16 | w)) {
spin_lock_irq(&dcrtc->irq_lock);
armada_drm_crtc_disable_irq(dcrtc, DUMB_FRAMEDONE_ENA);
dcrtc->cursor_update = false;
armada_updatel(0, CFG_HWC_ENA, dcrtc->base + LCD_SPU_DMA_CTRL0);
spin_unlock_irq(&dcrtc->irq_lock);
reload = true;
}
if (reload) {
struct armada_gem_object *obj = dcrtc->cursor_obj;
uint32_t *pix;
pix = obj->addr;
pix += yoff * s + xoff;
armada_load_cursor_argb(dcrtc->base, pix, s, w, h);
}
spin_lock_irq(&dcrtc->irq_lock);
dcrtc->cursor_hw_pos = yscr << 16 | xscr;
dcrtc->cursor_hw_sz = h << 16 | w;
dcrtc->cursor_update = true;
armada_drm_crtc_enable_irq(dcrtc, DUMB_FRAMEDONE_ENA);
spin_unlock_irq(&dcrtc->irq_lock);
return 0;
}
static void cursor_update(void *data)
{
armada_drm_crtc_cursor_update(data, true);
}
static int armada_drm_crtc_cursor_set(struct drm_crtc *crtc,
struct drm_file *file, uint32_t handle, uint32_t w, uint32_t h)
{
struct drm_device *dev = crtc->dev;
struct armada_crtc *dcrtc = drm_to_armada_crtc(crtc);
struct armada_gem_object *obj = NULL;
int ret;
if (!dcrtc->variant->has_spu_adv_reg)
return -ENXIO;
if (handle && w > 0 && h > 0) {
if (w > 64 || h > 64 || (w > 32 && h > 32))
return -ENOMEM;
obj = armada_gem_object_lookup(dev, file, handle);
if (!obj)
return -ENOENT;
if (!obj->addr) {
drm_gem_object_unreference_unlocked(&obj->obj);
return -EINVAL;
}
if (obj->obj.size < w * h * 4) {
DRM_ERROR("buffer is too small\n");
drm_gem_object_unreference_unlocked(&obj->obj);
return -ENOMEM;
}
}
if (dcrtc->cursor_obj) {
dcrtc->cursor_obj->update = NULL;
dcrtc->cursor_obj->update_data = NULL;
drm_gem_object_unreference_unlocked(&dcrtc->cursor_obj->obj);
}
dcrtc->cursor_obj = obj;
dcrtc->cursor_w = w;
dcrtc->cursor_h = h;
ret = armada_drm_crtc_cursor_update(dcrtc, true);
if (obj) {
obj->update_data = dcrtc;
obj->update = cursor_update;
}
return ret;
}
static int armada_drm_crtc_cursor_move(struct drm_crtc *crtc, int x, int y)
{
struct armada_crtc *dcrtc = drm_to_armada_crtc(crtc);
int ret;
if (!dcrtc->variant->has_spu_adv_reg)
return -EFAULT;
dcrtc->cursor_x = x;
dcrtc->cursor_y = y;
ret = armada_drm_crtc_cursor_update(dcrtc, false);
return ret;
}
static void armada_drm_crtc_destroy(struct drm_crtc *crtc)
{
struct armada_crtc *dcrtc = drm_to_armada_crtc(crtc);
struct armada_private *priv = crtc->dev->dev_private;
if (dcrtc->cursor_obj)
drm_gem_object_unreference_unlocked(&dcrtc->cursor_obj->obj);
priv->dcrtc[dcrtc->num] = NULL;
drm_crtc_cleanup(&dcrtc->crtc);
if (!IS_ERR(dcrtc->clk))
clk_disable_unprepare(dcrtc->clk);
writel_relaxed(0, dcrtc->base + LCD_SPU_IRQ_ENA);
of_node_put(dcrtc->crtc.port);
kfree(dcrtc);
}
static int armada_drm_crtc_page_flip(struct drm_crtc *crtc,
struct drm_framebuffer *fb, struct drm_pending_vblank_event *event, uint32_t page_flip_flags)
{
struct armada_crtc *dcrtc = drm_to_armada_crtc(crtc);
struct armada_frame_work *work;
unsigned i;
int ret;
if (fb->pixel_format != crtc->primary->fb->pixel_format)
return -EINVAL;
work = kmalloc(sizeof(*work), GFP_KERNEL);
if (!work)
return -ENOMEM;
work->work.fn = armada_drm_crtc_complete_frame_work;
work->event = event;
work->old_fb = dcrtc->crtc.primary->fb;
i = armada_drm_crtc_calc_fb(fb, crtc->x, crtc->y, work->regs,
dcrtc->interlaced);
armada_reg_queue_end(work->regs, i);
drm_framebuffer_reference(fb);
ret = armada_drm_crtc_queue_frame_work(dcrtc, work);
if (ret) {
drm_framebuffer_unreference(fb);
kfree(work);
return ret;
}
dcrtc->crtc.primary->fb = fb;
if (dpms_blanked(dcrtc->dpms))
armada_drm_plane_work_run(dcrtc, drm_to_armada_plane(dcrtc->crtc.primary));
return 0;
}
static int
armada_drm_crtc_set_property(struct drm_crtc *crtc,
struct drm_property *property, uint64_t val)
{
struct armada_private *priv = crtc->dev->dev_private;
struct armada_crtc *dcrtc = drm_to_armada_crtc(crtc);
bool update_csc = false;
if (property == priv->csc_yuv_prop) {
dcrtc->csc_yuv_mode = val;
update_csc = true;
} else if (property == priv->csc_rgb_prop) {
dcrtc->csc_rgb_mode = val;
update_csc = true;
}
if (update_csc) {
uint32_t val;
val = dcrtc->spu_iopad_ctrl |
armada_drm_crtc_calculate_csc(dcrtc);
writel_relaxed(val, dcrtc->base + LCD_SPU_IOPAD_CONTROL);
}
return 0;
}
int armada_drm_plane_init(struct armada_plane *plane)
{
init_waitqueue_head(&plane->frame_wait);
return 0;
}
static int armada_drm_crtc_create_properties(struct drm_device *dev)
{
struct armada_private *priv = dev->dev_private;
if (priv->csc_yuv_prop)
return 0;
priv->csc_yuv_prop = drm_property_create_enum(dev, 0,
"CSC_YUV", armada_drm_csc_yuv_enum_list,
ARRAY_SIZE(armada_drm_csc_yuv_enum_list));
priv->csc_rgb_prop = drm_property_create_enum(dev, 0,
"CSC_RGB", armada_drm_csc_rgb_enum_list,
ARRAY_SIZE(armada_drm_csc_rgb_enum_list));
if (!priv->csc_yuv_prop || !priv->csc_rgb_prop)
return -ENOMEM;
return 0;
}
static int armada_drm_crtc_create(struct drm_device *drm, struct device *dev,
struct resource *res, int irq, const struct armada_variant *variant,
struct device_node *port)
{
struct armada_private *priv = drm->dev_private;
struct armada_crtc *dcrtc;
struct armada_plane *primary;
void __iomem *base;
int ret;
ret = armada_drm_crtc_create_properties(drm);
if (ret)
return ret;
base = devm_ioremap_resource(dev, res);
if (IS_ERR(base))
return PTR_ERR(base);
dcrtc = kzalloc(sizeof(*dcrtc), GFP_KERNEL);
if (!dcrtc) {
DRM_ERROR("failed to allocate Armada crtc\n");
return -ENOMEM;
}
if (dev != drm->dev)
dev_set_drvdata(dev, dcrtc);
dcrtc->variant = variant;
dcrtc->base = base;
dcrtc->num = drm->mode_config.num_crtc;
dcrtc->clk = ERR_PTR(-EINVAL);
dcrtc->csc_yuv_mode = CSC_AUTO;
dcrtc->csc_rgb_mode = CSC_AUTO;
dcrtc->cfg_dumb_ctrl = DUMB24_RGB888_0;
dcrtc->spu_iopad_ctrl = CFG_VSCALE_LN_EN | CFG_IOPAD_DUMB24;
spin_lock_init(&dcrtc->irq_lock);
dcrtc->irq_ena = CLEAN_SPU_IRQ_ISR;
writel_relaxed(0x00000001, dcrtc->base + LCD_CFG_SCLK_DIV);
writel_relaxed(0x00000000, dcrtc->base + LCD_SPU_BLANKCOLOR);
writel_relaxed(dcrtc->spu_iopad_ctrl,
dcrtc->base + LCD_SPU_IOPAD_CONTROL);
writel_relaxed(0x00000000, dcrtc->base + LCD_SPU_SRAM_PARA0);
writel_relaxed(CFG_PDWN256x32 | CFG_PDWN256x24 | CFG_PDWN256x8 |
CFG_PDWN32x32 | CFG_PDWN16x66 | CFG_PDWN32x66 |
CFG_PDWN64x66, dcrtc->base + LCD_SPU_SRAM_PARA1);
writel_relaxed(0x2032ff81, dcrtc->base + LCD_SPU_DMA_CTRL1);
writel_relaxed(0x00000000, dcrtc->base + LCD_SPU_GRA_OVSA_HPXL_VLN);
writel_relaxed(dcrtc->irq_ena, dcrtc->base + LCD_SPU_IRQ_ENA);
writel_relaxed(0, dcrtc->base + LCD_SPU_IRQ_ISR);
ret = devm_request_irq(dev, irq, armada_drm_irq, 0, "armada_drm_crtc",
dcrtc);
if (ret < 0) {
kfree(dcrtc);
return ret;
}
if (dcrtc->variant->init) {
ret = dcrtc->variant->init(dcrtc, dev);
if (ret) {
kfree(dcrtc);
return ret;
}
}
armada_updatel(CFG_ARBFAST_ENA, 0, dcrtc->base + LCD_SPU_DMA_CTRL0);
priv->dcrtc[dcrtc->num] = dcrtc;
dcrtc->crtc.port = port;
primary = kzalloc(sizeof(*primary), GFP_KERNEL);
if (!primary)
return -ENOMEM;
ret = armada_drm_plane_init(primary);
if (ret) {
kfree(primary);
return ret;
}
ret = drm_universal_plane_init(drm, &primary->base, 0,
&armada_primary_plane_funcs,
armada_primary_formats,
ARRAY_SIZE(armada_primary_formats),
DRM_PLANE_TYPE_PRIMARY, NULL);
if (ret) {
kfree(primary);
return ret;
}
ret = drm_crtc_init_with_planes(drm, &dcrtc->crtc, &primary->base, NULL,
&armada_crtc_funcs, NULL);
if (ret)
goto err_crtc_init;
drm_crtc_helper_add(&dcrtc->crtc, &armada_crtc_helper_funcs);
drm_object_attach_property(&dcrtc->crtc.base, priv->csc_yuv_prop,
dcrtc->csc_yuv_mode);
drm_object_attach_property(&dcrtc->crtc.base, priv->csc_rgb_prop,
dcrtc->csc_rgb_mode);
return armada_overlay_plane_create(drm, 1 << dcrtc->num);
err_crtc_init:
primary->base.funcs->destroy(&primary->base);
return ret;
}
static int
armada_lcd_bind(struct device *dev, struct device *master, void *data)
{
struct platform_device *pdev = to_platform_device(dev);
struct drm_device *drm = data;
struct resource *res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
int irq = platform_get_irq(pdev, 0);
const struct armada_variant *variant;
struct device_node *port = NULL;
if (irq < 0)
return irq;
if (!dev->of_node) {
const struct platform_device_id *id;
id = platform_get_device_id(pdev);
if (!id)
return -ENXIO;
variant = (const struct armada_variant *)id->driver_data;
} else {
const struct of_device_id *match;
struct device_node *np, *parent = dev->of_node;
match = of_match_device(dev->driver->of_match_table, dev);
if (!match)
return -ENXIO;
np = of_get_child_by_name(parent, "ports");
if (np)
parent = np;
port = of_get_child_by_name(parent, "port");
of_node_put(np);
if (!port) {
dev_err(dev, "no port node found in %s\n",
parent->full_name);
return -ENXIO;
}
variant = match->data;
}
return armada_drm_crtc_create(drm, dev, res, irq, variant, port);
}
static void
armada_lcd_unbind(struct device *dev, struct device *master, void *data)
{
struct armada_crtc *dcrtc = dev_get_drvdata(dev);
armada_drm_crtc_destroy(&dcrtc->crtc);
}
static int armada_lcd_probe(struct platform_device *pdev)
{
return component_add(&pdev->dev, &armada_lcd_ops);
}
static int armada_lcd_remove(struct platform_device *pdev)
{
component_del(&pdev->dev, &armada_lcd_ops);
return 0;
}
