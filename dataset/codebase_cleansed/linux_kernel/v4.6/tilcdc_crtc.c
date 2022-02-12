static void unref_worker(struct drm_flip_work *work, void *val)
{
struct tilcdc_crtc *tilcdc_crtc =
container_of(work, struct tilcdc_crtc, unref_work);
struct drm_device *dev = tilcdc_crtc->base.dev;
mutex_lock(&dev->mode_config.mutex);
drm_framebuffer_unreference(val);
mutex_unlock(&dev->mode_config.mutex);
}
static void set_scanout(struct drm_crtc *crtc, struct drm_framebuffer *fb)
{
struct tilcdc_crtc *tilcdc_crtc = to_tilcdc_crtc(crtc);
struct drm_device *dev = crtc->dev;
struct drm_gem_cma_object *gem;
unsigned int depth, bpp;
dma_addr_t start, end;
drm_fb_get_bpp_depth(fb->pixel_format, &depth, &bpp);
gem = drm_fb_cma_get_gem_obj(fb, 0);
start = gem->paddr + fb->offsets[0] +
crtc->y * fb->pitches[0] +
crtc->x * bpp / 8;
end = start + (crtc->mode.vdisplay * fb->pitches[0]);
tilcdc_write(dev, LCDC_DMA_FB_BASE_ADDR_0_REG, start);
tilcdc_write(dev, LCDC_DMA_FB_CEILING_ADDR_0_REG, end);
if (tilcdc_crtc->curr_fb)
drm_flip_work_queue(&tilcdc_crtc->unref_work,
tilcdc_crtc->curr_fb);
tilcdc_crtc->curr_fb = fb;
}
static void reset(struct drm_crtc *crtc)
{
struct drm_device *dev = crtc->dev;
struct tilcdc_drm_private *priv = dev->dev_private;
if (priv->rev != 2)
return;
tilcdc_set(dev, LCDC_CLK_RESET_REG, LCDC_CLK_MAIN_RESET);
usleep_range(250, 1000);
tilcdc_clear(dev, LCDC_CLK_RESET_REG, LCDC_CLK_MAIN_RESET);
}
static void start(struct drm_crtc *crtc)
{
struct drm_device *dev = crtc->dev;
reset(crtc);
tilcdc_clear(dev, LCDC_DMA_CTRL_REG, LCDC_DUAL_FRAME_BUFFER_ENABLE);
tilcdc_set(dev, LCDC_RASTER_CTRL_REG, LCDC_PALETTE_LOAD_MODE(DATA_ONLY));
tilcdc_set(dev, LCDC_RASTER_CTRL_REG, LCDC_RASTER_ENABLE);
}
static void stop(struct drm_crtc *crtc)
{
struct drm_device *dev = crtc->dev;
tilcdc_clear(dev, LCDC_RASTER_CTRL_REG, LCDC_RASTER_ENABLE);
}
static void tilcdc_crtc_destroy(struct drm_crtc *crtc)
{
struct tilcdc_crtc *tilcdc_crtc = to_tilcdc_crtc(crtc);
tilcdc_crtc_dpms(crtc, DRM_MODE_DPMS_OFF);
of_node_put(crtc->port);
drm_crtc_cleanup(crtc);
drm_flip_work_cleanup(&tilcdc_crtc->unref_work);
}
static int tilcdc_verify_fb(struct drm_crtc *crtc, struct drm_framebuffer *fb)
{
struct drm_device *dev = crtc->dev;
unsigned int depth, bpp;
drm_fb_get_bpp_depth(fb->pixel_format, &depth, &bpp);
if (fb->pitches[0] != crtc->mode.hdisplay * bpp / 8) {
dev_err(dev->dev,
"Invalid pitch: fb and crtc widths must be the same");
return -EINVAL;
}
return 0;
}
static int tilcdc_crtc_page_flip(struct drm_crtc *crtc,
struct drm_framebuffer *fb,
struct drm_pending_vblank_event *event,
uint32_t page_flip_flags)
{
struct tilcdc_crtc *tilcdc_crtc = to_tilcdc_crtc(crtc);
struct drm_device *dev = crtc->dev;
int r;
unsigned long flags;
s64 tdiff;
ktime_t next_vblank;
r = tilcdc_verify_fb(crtc, fb);
if (r)
return r;
if (tilcdc_crtc->event) {
dev_err(dev->dev, "already pending page flip!\n");
return -EBUSY;
}
drm_framebuffer_reference(fb);
crtc->primary->fb = fb;
pm_runtime_get_sync(dev->dev);
spin_lock_irqsave(&tilcdc_crtc->irq_lock, flags);
next_vblank = ktime_add_us(tilcdc_crtc->last_vblank,
1000000 / crtc->hwmode.vrefresh);
tdiff = ktime_to_us(ktime_sub(next_vblank, ktime_get()));
if (tdiff >= TILCDC_VBLANK_SAFETY_THRESHOLD_US)
set_scanout(crtc, fb);
else
tilcdc_crtc->next_fb = fb;
tilcdc_crtc->event = event;
spin_unlock_irqrestore(&tilcdc_crtc->irq_lock, flags);
pm_runtime_put_sync(dev->dev);
return 0;
}
void tilcdc_crtc_dpms(struct drm_crtc *crtc, int mode)
{
struct tilcdc_crtc *tilcdc_crtc = to_tilcdc_crtc(crtc);
struct drm_device *dev = crtc->dev;
struct tilcdc_drm_private *priv = dev->dev_private;
if (mode != DRM_MODE_DPMS_ON)
mode = DRM_MODE_DPMS_OFF;
if (tilcdc_crtc->dpms == mode)
return;
tilcdc_crtc->dpms = mode;
if (mode == DRM_MODE_DPMS_ON) {
pm_runtime_get_sync(dev->dev);
start(crtc);
} else {
tilcdc_crtc->frame_done = false;
stop(crtc);
if (priv->rev == 2) {
int ret = wait_event_timeout(
tilcdc_crtc->frame_done_wq,
tilcdc_crtc->frame_done,
msecs_to_jiffies(50));
if (ret == 0)
dev_err(dev->dev, "timeout waiting for framedone\n");
}
pm_runtime_put_sync(dev->dev);
if (tilcdc_crtc->next_fb) {
drm_flip_work_queue(&tilcdc_crtc->unref_work,
tilcdc_crtc->next_fb);
tilcdc_crtc->next_fb = NULL;
}
if (tilcdc_crtc->curr_fb) {
drm_flip_work_queue(&tilcdc_crtc->unref_work,
tilcdc_crtc->curr_fb);
tilcdc_crtc->curr_fb = NULL;
}
drm_flip_work_commit(&tilcdc_crtc->unref_work, priv->wq);
}
}
static bool tilcdc_crtc_mode_fixup(struct drm_crtc *crtc,
const struct drm_display_mode *mode,
struct drm_display_mode *adjusted_mode)
{
struct tilcdc_crtc *tilcdc_crtc = to_tilcdc_crtc(crtc);
if (!tilcdc_crtc->simulate_vesa_sync)
return true;
adjusted_mode->hskew = mode->hsync_end - mode->hsync_start;
adjusted_mode->flags |= DRM_MODE_FLAG_HSKEW;
if (mode->flags & DRM_MODE_FLAG_NHSYNC) {
adjusted_mode->flags |= DRM_MODE_FLAG_PHSYNC;
adjusted_mode->flags &= ~DRM_MODE_FLAG_NHSYNC;
} else {
adjusted_mode->flags |= DRM_MODE_FLAG_NHSYNC;
adjusted_mode->flags &= ~DRM_MODE_FLAG_PHSYNC;
}
return true;
}
static void tilcdc_crtc_prepare(struct drm_crtc *crtc)
{
tilcdc_crtc_dpms(crtc, DRM_MODE_DPMS_OFF);
}
static void tilcdc_crtc_commit(struct drm_crtc *crtc)
{
tilcdc_crtc_dpms(crtc, DRM_MODE_DPMS_ON);
}
static int tilcdc_crtc_mode_set(struct drm_crtc *crtc,
struct drm_display_mode *mode,
struct drm_display_mode *adjusted_mode,
int x, int y,
struct drm_framebuffer *old_fb)
{
struct tilcdc_crtc *tilcdc_crtc = to_tilcdc_crtc(crtc);
struct drm_device *dev = crtc->dev;
struct tilcdc_drm_private *priv = dev->dev_private;
const struct tilcdc_panel_info *info = tilcdc_crtc->info;
uint32_t reg, hbp, hfp, hsw, vbp, vfp, vsw;
int ret;
ret = tilcdc_crtc_mode_valid(crtc, mode);
if (WARN_ON(ret))
return ret;
if (WARN_ON(!info))
return -EINVAL;
ret = tilcdc_verify_fb(crtc, crtc->primary->fb);
if (ret)
return ret;
pm_runtime_get_sync(dev->dev);
reg = tilcdc_read(dev, LCDC_DMA_CTRL_REG) & ~0x00000770;
switch (info->dma_burst_sz) {
case 1:
reg |= LCDC_DMA_BURST_SIZE(LCDC_DMA_BURST_1);
break;
case 2:
reg |= LCDC_DMA_BURST_SIZE(LCDC_DMA_BURST_2);
break;
case 4:
reg |= LCDC_DMA_BURST_SIZE(LCDC_DMA_BURST_4);
break;
case 8:
reg |= LCDC_DMA_BURST_SIZE(LCDC_DMA_BURST_8);
break;
case 16:
reg |= LCDC_DMA_BURST_SIZE(LCDC_DMA_BURST_16);
break;
default:
return -EINVAL;
}
reg |= (info->fifo_th << 8);
tilcdc_write(dev, LCDC_DMA_CTRL_REG, reg);
hbp = mode->htotal - mode->hsync_end;
hfp = mode->hsync_start - mode->hdisplay;
hsw = mode->hsync_end - mode->hsync_start;
vbp = mode->vtotal - mode->vsync_end;
vfp = mode->vsync_start - mode->vdisplay;
vsw = mode->vsync_end - mode->vsync_start;
DBG("%dx%d, hbp=%u, hfp=%u, hsw=%u, vbp=%u, vfp=%u, vsw=%u",
mode->hdisplay, mode->vdisplay, hbp, hfp, hsw, vbp, vfp, vsw);
reg = tilcdc_read(dev, LCDC_RASTER_TIMING_2_REG) & ~0x000fff00;
reg |= LCDC_AC_BIAS_FREQUENCY(info->ac_bias) |
LCDC_AC_BIAS_TRANSITIONS_PER_INT(info->ac_bias_intrpt);
if (priv->rev == 2) {
reg &= ~0x78000033;
reg |= ((hfp-1) & 0x300) >> 8;
reg |= ((hbp-1) & 0x300) >> 4;
reg |= ((hsw-1) & 0x3c0) << 21;
}
tilcdc_write(dev, LCDC_RASTER_TIMING_2_REG, reg);
reg = (((mode->hdisplay >> 4) - 1) << 4) |
(((hbp-1) & 0xff) << 24) |
(((hfp-1) & 0xff) << 16) |
(((hsw-1) & 0x3f) << 10);
if (priv->rev == 2)
reg |= (((mode->hdisplay >> 4) - 1) & 0x40) >> 3;
tilcdc_write(dev, LCDC_RASTER_TIMING_0_REG, reg);
reg = ((mode->vdisplay - 1) & 0x3ff) |
((vbp & 0xff) << 24) |
((vfp & 0xff) << 16) |
(((vsw-1) & 0x3f) << 10);
tilcdc_write(dev, LCDC_RASTER_TIMING_1_REG, reg);
if (priv->rev == 2) {
if ((mode->vdisplay - 1) & 0x400) {
tilcdc_set(dev, LCDC_RASTER_TIMING_2_REG,
LCDC_LPP_B10);
} else {
tilcdc_clear(dev, LCDC_RASTER_TIMING_2_REG,
LCDC_LPP_B10);
}
}
reg = tilcdc_read(dev, LCDC_RASTER_CTRL_REG) &
~(LCDC_TFT_MODE | LCDC_MONO_8BIT_MODE | LCDC_MONOCHROME_MODE |
LCDC_V2_TFT_24BPP_MODE | LCDC_V2_TFT_24BPP_UNPACK | 0x000ff000);
reg |= LCDC_TFT_MODE;
if (info->tft_alt_mode)
reg |= LCDC_TFT_ALT_ENABLE;
if (priv->rev == 2) {
unsigned int depth, bpp;
drm_fb_get_bpp_depth(crtc->primary->fb->pixel_format, &depth, &bpp);
switch (bpp) {
case 16:
break;
case 32:
reg |= LCDC_V2_TFT_24BPP_UNPACK;
case 24:
reg |= LCDC_V2_TFT_24BPP_MODE;
break;
default:
dev_err(dev->dev, "invalid pixel format\n");
return -EINVAL;
}
}
reg |= info->fdd < 12;
tilcdc_write(dev, LCDC_RASTER_CTRL_REG, reg);
if (info->invert_pxl_clk)
tilcdc_set(dev, LCDC_RASTER_TIMING_2_REG, LCDC_INVERT_PIXEL_CLOCK);
else
tilcdc_clear(dev, LCDC_RASTER_TIMING_2_REG, LCDC_INVERT_PIXEL_CLOCK);
if (info->sync_ctrl)
tilcdc_set(dev, LCDC_RASTER_TIMING_2_REG, LCDC_SYNC_CTRL);
else
tilcdc_clear(dev, LCDC_RASTER_TIMING_2_REG, LCDC_SYNC_CTRL);
if (info->sync_edge)
tilcdc_set(dev, LCDC_RASTER_TIMING_2_REG, LCDC_SYNC_EDGE);
else
tilcdc_clear(dev, LCDC_RASTER_TIMING_2_REG, LCDC_SYNC_EDGE);
if (adjusted_mode->flags & DRM_MODE_FLAG_NHSYNC)
tilcdc_set(dev, LCDC_RASTER_TIMING_2_REG, LCDC_INVERT_HSYNC);
else
tilcdc_clear(dev, LCDC_RASTER_TIMING_2_REG, LCDC_INVERT_HSYNC);
if (mode->flags & DRM_MODE_FLAG_NVSYNC)
tilcdc_set(dev, LCDC_RASTER_TIMING_2_REG, LCDC_INVERT_VSYNC);
else
tilcdc_clear(dev, LCDC_RASTER_TIMING_2_REG, LCDC_INVERT_VSYNC);
if (info->raster_order)
tilcdc_set(dev, LCDC_RASTER_CTRL_REG, LCDC_RASTER_ORDER);
else
tilcdc_clear(dev, LCDC_RASTER_CTRL_REG, LCDC_RASTER_ORDER);
drm_framebuffer_reference(crtc->primary->fb);
set_scanout(crtc, crtc->primary->fb);
tilcdc_crtc_update_clk(crtc);
pm_runtime_put_sync(dev->dev);
return 0;
}
static int tilcdc_crtc_mode_set_base(struct drm_crtc *crtc, int x, int y,
struct drm_framebuffer *old_fb)
{
struct drm_device *dev = crtc->dev;
int r;
r = tilcdc_verify_fb(crtc, crtc->primary->fb);
if (r)
return r;
drm_framebuffer_reference(crtc->primary->fb);
pm_runtime_get_sync(dev->dev);
set_scanout(crtc, crtc->primary->fb);
pm_runtime_put_sync(dev->dev);
return 0;
}
int tilcdc_crtc_max_width(struct drm_crtc *crtc)
{
struct drm_device *dev = crtc->dev;
struct tilcdc_drm_private *priv = dev->dev_private;
int max_width = 0;
if (priv->rev == 1)
max_width = 1024;
else if (priv->rev == 2)
max_width = 2048;
return max_width;
}
int tilcdc_crtc_mode_valid(struct drm_crtc *crtc, struct drm_display_mode *mode)
{
struct tilcdc_drm_private *priv = crtc->dev->dev_private;
unsigned int bandwidth;
uint32_t hbp, hfp, hsw, vbp, vfp, vsw;
if (mode->hdisplay > tilcdc_crtc_max_width(crtc))
return MODE_VIRTUAL_X;
if (mode->hdisplay & 0xf)
return MODE_VIRTUAL_X;
if (mode->vdisplay > 2048)
return MODE_VIRTUAL_Y;
DBG("Processing mode %dx%d@%d with pixel clock %d",
mode->hdisplay, mode->vdisplay,
drm_mode_vrefresh(mode), mode->clock);
hbp = mode->htotal - mode->hsync_end;
hfp = mode->hsync_start - mode->hdisplay;
hsw = mode->hsync_end - mode->hsync_start;
vbp = mode->vtotal - mode->vsync_end;
vfp = mode->vsync_start - mode->vdisplay;
vsw = mode->vsync_end - mode->vsync_start;
if ((hbp-1) & ~0x3ff) {
DBG("Pruning mode: Horizontal Back Porch out of range");
return MODE_HBLANK_WIDE;
}
if ((hfp-1) & ~0x3ff) {
DBG("Pruning mode: Horizontal Front Porch out of range");
return MODE_HBLANK_WIDE;
}
if ((hsw-1) & ~0x3ff) {
DBG("Pruning mode: Horizontal Sync Width out of range");
return MODE_HSYNC_WIDE;
}
if (vbp & ~0xff) {
DBG("Pruning mode: Vertical Back Porch out of range");
return MODE_VBLANK_WIDE;
}
if (vfp & ~0xff) {
DBG("Pruning mode: Vertical Front Porch out of range");
return MODE_VBLANK_WIDE;
}
if ((vsw-1) & ~0x3f) {
DBG("Pruning mode: Vertical Sync Width out of range");
return MODE_VSYNC_WIDE;
}
if (mode->clock > priv->max_pixelclock) {
DBG("Pruning mode: pixel clock too high");
return MODE_CLOCK_HIGH;
}
if (mode->hdisplay > priv->max_width)
return MODE_BAD_WIDTH;
bandwidth = mode->hdisplay * mode->vdisplay *
drm_mode_vrefresh(mode);
if (bandwidth > priv->max_bandwidth) {
DBG("Pruning mode: exceeds defined bandwidth limit");
return MODE_BAD;
}
return MODE_OK;
}
void tilcdc_crtc_set_panel_info(struct drm_crtc *crtc,
const struct tilcdc_panel_info *info)
{
struct tilcdc_crtc *tilcdc_crtc = to_tilcdc_crtc(crtc);
tilcdc_crtc->info = info;
}
void tilcdc_crtc_set_simulate_vesa_sync(struct drm_crtc *crtc,
bool simulate_vesa_sync)
{
struct tilcdc_crtc *tilcdc_crtc = to_tilcdc_crtc(crtc);
tilcdc_crtc->simulate_vesa_sync = simulate_vesa_sync;
}
void tilcdc_crtc_update_clk(struct drm_crtc *crtc)
{
struct tilcdc_crtc *tilcdc_crtc = to_tilcdc_crtc(crtc);
struct drm_device *dev = crtc->dev;
struct tilcdc_drm_private *priv = dev->dev_private;
int dpms = tilcdc_crtc->dpms;
unsigned long lcd_clk;
const unsigned clkdiv = 2;
int ret;
pm_runtime_get_sync(dev->dev);
if (dpms == DRM_MODE_DPMS_ON)
tilcdc_crtc_dpms(crtc, DRM_MODE_DPMS_OFF);
ret = clk_set_rate(priv->clk, crtc->mode.clock * 1000 * clkdiv);
if (ret < 0) {
dev_err(dev->dev, "failed to set display clock rate to: %d\n",
crtc->mode.clock);
goto out;
}
lcd_clk = clk_get_rate(priv->clk);
DBG("lcd_clk=%lu, mode clock=%d, div=%u",
lcd_clk, crtc->mode.clock, clkdiv);
tilcdc_write(dev, LCDC_CTRL_REG, LCDC_CLK_DIVISOR(clkdiv) |
LCDC_RASTER_MODE);
if (priv->rev == 2)
tilcdc_set(dev, LCDC_CLK_ENABLE_REG,
LCDC_V2_DMA_CLK_EN | LCDC_V2_LIDD_CLK_EN |
LCDC_V2_CORE_CLK_EN);
if (dpms == DRM_MODE_DPMS_ON)
tilcdc_crtc_dpms(crtc, DRM_MODE_DPMS_ON);
out:
pm_runtime_put_sync(dev->dev);
}
irqreturn_t tilcdc_crtc_irq(struct drm_crtc *crtc)
{
struct tilcdc_crtc *tilcdc_crtc = to_tilcdc_crtc(crtc);
struct drm_device *dev = crtc->dev;
struct tilcdc_drm_private *priv = dev->dev_private;
uint32_t stat;
stat = tilcdc_read_irqstatus(dev);
tilcdc_clear_irqstatus(dev, stat);
if (stat & LCDC_END_OF_FRAME0) {
unsigned long flags;
bool skip_event = false;
ktime_t now;
now = ktime_get();
drm_flip_work_commit(&tilcdc_crtc->unref_work, priv->wq);
spin_lock_irqsave(&tilcdc_crtc->irq_lock, flags);
tilcdc_crtc->last_vblank = now;
if (tilcdc_crtc->next_fb) {
set_scanout(crtc, tilcdc_crtc->next_fb);
tilcdc_crtc->next_fb = NULL;
skip_event = true;
}
spin_unlock_irqrestore(&tilcdc_crtc->irq_lock, flags);
drm_handle_vblank(dev, 0);
if (!skip_event) {
struct drm_pending_vblank_event *event;
spin_lock_irqsave(&dev->event_lock, flags);
event = tilcdc_crtc->event;
tilcdc_crtc->event = NULL;
if (event)
drm_send_vblank_event(dev, 0, event);
spin_unlock_irqrestore(&dev->event_lock, flags);
}
if (tilcdc_crtc->frame_intact)
tilcdc_crtc->sync_lost_count = 0;
else
tilcdc_crtc->frame_intact = true;
}
if (priv->rev == 2) {
if (stat & LCDC_FRAME_DONE) {
tilcdc_crtc->frame_done = true;
wake_up(&tilcdc_crtc->frame_done_wq);
}
tilcdc_write(dev, LCDC_END_OF_INT_IND_REG, 0);
}
if (stat & LCDC_SYNC_LOST) {
dev_err_ratelimited(dev->dev, "%s(0x%08x): Sync lost",
__func__, stat);
tilcdc_crtc->frame_intact = false;
if (tilcdc_crtc->sync_lost_count++ > SYNC_LOST_COUNT_LIMIT) {
dev_err(dev->dev,
"%s(0x%08x): Sync lost flood detected, disabling the interrupt",
__func__, stat);
tilcdc_write(dev, LCDC_INT_ENABLE_CLR_REG,
LCDC_SYNC_LOST);
}
}
if (stat & LCDC_FIFO_UNDERFLOW)
dev_err_ratelimited(dev->dev, "%s(0x%08x): FIFO underfow",
__func__, stat);
return IRQ_HANDLED;
}
struct drm_crtc *tilcdc_crtc_create(struct drm_device *dev)
{
struct tilcdc_drm_private *priv = dev->dev_private;
struct tilcdc_crtc *tilcdc_crtc;
struct drm_crtc *crtc;
int ret;
tilcdc_crtc = devm_kzalloc(dev->dev, sizeof(*tilcdc_crtc), GFP_KERNEL);
if (!tilcdc_crtc) {
dev_err(dev->dev, "allocation failed\n");
return NULL;
}
crtc = &tilcdc_crtc->base;
tilcdc_crtc->dpms = DRM_MODE_DPMS_OFF;
init_waitqueue_head(&tilcdc_crtc->frame_done_wq);
drm_flip_work_init(&tilcdc_crtc->unref_work,
"unref", unref_worker);
spin_lock_init(&tilcdc_crtc->irq_lock);
ret = drm_crtc_init(dev, crtc, &tilcdc_crtc_funcs);
if (ret < 0)
goto fail;
drm_crtc_helper_add(crtc, &tilcdc_crtc_helper_funcs);
if (priv->is_componentized) {
struct device_node *ports =
of_get_child_by_name(dev->dev->of_node, "ports");
if (ports) {
crtc->port = of_get_child_by_name(ports, "port");
of_node_put(ports);
} else {
crtc->port =
of_get_child_by_name(dev->dev->of_node, "port");
}
if (!crtc->port) {
dev_err(dev->dev, "Port node not found in %s\n",
dev->dev->of_node->full_name);
goto fail;
}
}
return crtc;
fail:
tilcdc_crtc_destroy(crtc);
return NULL;
}
