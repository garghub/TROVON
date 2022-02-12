static u32 set_hsync_pulse_width(struct mxsfb_drm_private *mxsfb, u32 val)
{
return (val & mxsfb->devdata->hs_wdth_mask) <<
mxsfb->devdata->hs_wdth_shift;
}
static int mxsfb_set_pixel_fmt(struct mxsfb_drm_private *mxsfb)
{
struct drm_crtc *crtc = &mxsfb->pipe.crtc;
struct drm_device *drm = crtc->dev;
const u32 format = crtc->primary->state->fb->pixel_format;
u32 ctrl, ctrl1;
ctrl = CTRL_BYPASS_COUNT | CTRL_MASTER;
ctrl1 = readl(mxsfb->base + LCDC_CTRL1);
ctrl1 &= CTRL1_CUR_FRAME_DONE_IRQ_EN | CTRL1_CUR_FRAME_DONE_IRQ;
switch (format) {
case DRM_FORMAT_RGB565:
dev_dbg(drm->dev, "Setting up RGB565 mode\n");
ctrl |= CTRL_SET_BUS_WIDTH(STMLCDIF_16BIT);
ctrl |= CTRL_SET_WORD_LENGTH(0);
ctrl1 |= CTRL1_SET_BYTE_PACKAGING(0xf);
break;
case DRM_FORMAT_XRGB8888:
dev_dbg(drm->dev, "Setting up XRGB8888 mode\n");
ctrl |= CTRL_SET_BUS_WIDTH(STMLCDIF_24BIT);
ctrl |= CTRL_SET_WORD_LENGTH(3);
ctrl1 |= CTRL1_SET_BYTE_PACKAGING(0x7);
break;
default:
dev_err(drm->dev, "Unhandled pixel format %08x\n", format);
return -EINVAL;
}
writel(ctrl1, mxsfb->base + LCDC_CTRL1);
writel(ctrl, mxsfb->base + LCDC_CTRL);
return 0;
}
static void mxsfb_enable_controller(struct mxsfb_drm_private *mxsfb)
{
u32 reg;
if (mxsfb->clk_disp_axi)
clk_prepare_enable(mxsfb->clk_disp_axi);
clk_prepare_enable(mxsfb->clk);
mxsfb_enable_axi_clk(mxsfb);
writel(CTRL_DOTCLK_MODE, mxsfb->base + LCDC_CTRL + REG_SET);
reg = readl(mxsfb->base + LCDC_VDCTRL4);
reg |= VDCTRL4_SYNC_SIGNALS_ON;
writel(reg, mxsfb->base + LCDC_VDCTRL4);
writel(CTRL_RUN, mxsfb->base + LCDC_CTRL + REG_SET);
}
static void mxsfb_disable_controller(struct mxsfb_drm_private *mxsfb)
{
u32 reg;
writel(CTRL_DOTCLK_MODE, mxsfb->base + LCDC_CTRL + REG_CLR);
readl_poll_timeout(mxsfb->base + LCDC_CTRL, reg, !(reg & CTRL_RUN),
0, 1000);
reg = readl(mxsfb->base + LCDC_VDCTRL4);
reg &= ~VDCTRL4_SYNC_SIGNALS_ON;
writel(reg, mxsfb->base + LCDC_VDCTRL4);
mxsfb_disable_axi_clk(mxsfb);
clk_disable_unprepare(mxsfb->clk);
if (mxsfb->clk_disp_axi)
clk_disable_unprepare(mxsfb->clk_disp_axi);
}
static void mxsfb_crtc_mode_set_nofb(struct mxsfb_drm_private *mxsfb)
{
struct drm_display_mode *m = &mxsfb->pipe.crtc.state->adjusted_mode;
const u32 bus_flags = mxsfb->connector.display_info.bus_flags;
u32 vdctrl0, vsync_pulse_len, hsync_pulse_len;
int err;
mxsfb_enable_axi_clk(mxsfb);
writel(CTRL1_FIFO_CLEAR, mxsfb->base + LCDC_CTRL1 + REG_SET);
err = mxsfb_set_pixel_fmt(mxsfb);
if (err)
return;
clk_set_rate(mxsfb->clk, m->crtc_clock * 1000);
writel(TRANSFER_COUNT_SET_VCOUNT(m->crtc_vdisplay) |
TRANSFER_COUNT_SET_HCOUNT(m->crtc_hdisplay),
mxsfb->base + mxsfb->devdata->transfer_count);
vsync_pulse_len = m->crtc_vsync_end - m->crtc_vsync_start;
vdctrl0 = VDCTRL0_ENABLE_PRESENT |
VDCTRL0_VSYNC_PERIOD_UNIT |
VDCTRL0_VSYNC_PULSE_WIDTH_UNIT |
VDCTRL0_SET_VSYNC_PULSE_WIDTH(vsync_pulse_len);
if (m->flags & DRM_MODE_FLAG_PHSYNC)
vdctrl0 |= VDCTRL0_HSYNC_ACT_HIGH;
if (m->flags & DRM_MODE_FLAG_PVSYNC)
vdctrl0 |= VDCTRL0_VSYNC_ACT_HIGH;
if (bus_flags & DRM_BUS_FLAG_DE_HIGH)
vdctrl0 |= VDCTRL0_ENABLE_ACT_HIGH;
if (bus_flags & DRM_BUS_FLAG_PIXDATA_NEGEDGE)
vdctrl0 |= VDCTRL0_DOTCLK_ACT_FALLING;
writel(vdctrl0, mxsfb->base + LCDC_VDCTRL0);
writel(m->crtc_vtotal, mxsfb->base + LCDC_VDCTRL1);
hsync_pulse_len = m->crtc_hsync_end - m->crtc_hsync_start;
writel(set_hsync_pulse_width(mxsfb, hsync_pulse_len) |
VDCTRL2_SET_HSYNC_PERIOD(m->crtc_htotal),
mxsfb->base + LCDC_VDCTRL2);
writel(SET_HOR_WAIT_CNT(m->crtc_hblank_end - m->crtc_hsync_end) |
SET_VERT_WAIT_CNT(m->crtc_vblank_end - m->crtc_vsync_end),
mxsfb->base + LCDC_VDCTRL3);
writel(SET_DOTCLK_H_VALID_DATA_CNT(m->hdisplay),
mxsfb->base + LCDC_VDCTRL4);
mxsfb_disable_axi_clk(mxsfb);
}
void mxsfb_crtc_enable(struct mxsfb_drm_private *mxsfb)
{
mxsfb_crtc_mode_set_nofb(mxsfb);
mxsfb_enable_controller(mxsfb);
}
void mxsfb_crtc_disable(struct mxsfb_drm_private *mxsfb)
{
mxsfb_disable_controller(mxsfb);
}
void mxsfb_plane_atomic_update(struct mxsfb_drm_private *mxsfb,
struct drm_plane_state *state)
{
struct drm_simple_display_pipe *pipe = &mxsfb->pipe;
struct drm_crtc *crtc = &pipe->crtc;
struct drm_framebuffer *fb = pipe->plane.state->fb;
struct drm_pending_vblank_event *event;
struct drm_gem_cma_object *gem;
if (!crtc)
return;
spin_lock_irq(&crtc->dev->event_lock);
event = crtc->state->event;
if (event) {
crtc->state->event = NULL;
if (drm_crtc_vblank_get(crtc) == 0) {
drm_crtc_arm_vblank_event(crtc, event);
} else {
drm_crtc_send_vblank_event(crtc, event);
}
}
spin_unlock_irq(&crtc->dev->event_lock);
if (!fb)
return;
gem = drm_fb_cma_get_gem_obj(fb, 0);
mxsfb_enable_axi_clk(mxsfb);
writel(gem->paddr, mxsfb->base + mxsfb->devdata->next_buf);
mxsfb_disable_axi_clk(mxsfb);
}
