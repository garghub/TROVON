static inline struct atmel_hlcdc_crtc *
drm_crtc_to_atmel_hlcdc_crtc(struct drm_crtc *crtc)
{
return container_of(crtc, struct atmel_hlcdc_crtc, base);
}
static void atmel_hlcdc_crtc_mode_set_nofb(struct drm_crtc *c)
{
struct atmel_hlcdc_crtc *crtc = drm_crtc_to_atmel_hlcdc_crtc(c);
struct regmap *regmap = crtc->dc->hlcdc->regmap;
struct drm_display_mode *adj = &c->state->adjusted_mode;
unsigned long mode_rate;
struct videomode vm;
unsigned long prate;
unsigned int cfg;
int div;
vm.vfront_porch = adj->crtc_vsync_start - adj->crtc_vdisplay;
vm.vback_porch = adj->crtc_vtotal - adj->crtc_vsync_end;
vm.vsync_len = adj->crtc_vsync_end - adj->crtc_vsync_start;
vm.hfront_porch = adj->crtc_hsync_start - adj->crtc_hdisplay;
vm.hback_porch = adj->crtc_htotal - adj->crtc_hsync_end;
vm.hsync_len = adj->crtc_hsync_end - adj->crtc_hsync_start;
regmap_write(regmap, ATMEL_HLCDC_CFG(1),
(vm.hsync_len - 1) | ((vm.vsync_len - 1) << 16));
regmap_write(regmap, ATMEL_HLCDC_CFG(2),
(vm.vfront_porch - 1) | (vm.vback_porch << 16));
regmap_write(regmap, ATMEL_HLCDC_CFG(3),
(vm.hfront_porch - 1) | ((vm.hback_porch - 1) << 16));
regmap_write(regmap, ATMEL_HLCDC_CFG(4),
(adj->crtc_hdisplay - 1) |
((adj->crtc_vdisplay - 1) << 16));
cfg = 0;
prate = clk_get_rate(crtc->dc->hlcdc->sys_clk);
mode_rate = adj->crtc_clock * 1000;
if ((prate / 2) < mode_rate) {
prate *= 2;
cfg |= ATMEL_HLCDC_CLKSEL;
}
div = DIV_ROUND_UP(prate, mode_rate);
if (div < 2)
div = 2;
cfg |= ATMEL_HLCDC_CLKDIV(div);
regmap_update_bits(regmap, ATMEL_HLCDC_CFG(0),
ATMEL_HLCDC_CLKSEL | ATMEL_HLCDC_CLKDIV_MASK |
ATMEL_HLCDC_CLKPOL, cfg);
cfg = 0;
if (adj->flags & DRM_MODE_FLAG_NVSYNC)
cfg |= ATMEL_HLCDC_VSPOL;
if (adj->flags & DRM_MODE_FLAG_NHSYNC)
cfg |= ATMEL_HLCDC_HSPOL;
regmap_update_bits(regmap, ATMEL_HLCDC_CFG(5),
ATMEL_HLCDC_HSPOL | ATMEL_HLCDC_VSPOL |
ATMEL_HLCDC_VSPDLYS | ATMEL_HLCDC_VSPDLYE |
ATMEL_HLCDC_DISPPOL | ATMEL_HLCDC_DISPDLY |
ATMEL_HLCDC_VSPSU | ATMEL_HLCDC_VSPHO |
ATMEL_HLCDC_GUARDTIME_MASK,
cfg);
}
static bool atmel_hlcdc_crtc_mode_fixup(struct drm_crtc *crtc,
const struct drm_display_mode *mode,
struct drm_display_mode *adjusted_mode)
{
return true;
}
static void atmel_hlcdc_crtc_disable(struct drm_crtc *c)
{
struct drm_device *dev = c->dev;
struct atmel_hlcdc_crtc *crtc = drm_crtc_to_atmel_hlcdc_crtc(c);
struct regmap *regmap = crtc->dc->hlcdc->regmap;
unsigned int status;
if (!crtc->enabled)
return;
drm_crtc_vblank_off(c);
pm_runtime_get_sync(dev->dev);
regmap_write(regmap, ATMEL_HLCDC_DIS, ATMEL_HLCDC_DISP);
while (!regmap_read(regmap, ATMEL_HLCDC_SR, &status) &&
(status & ATMEL_HLCDC_DISP))
cpu_relax();
regmap_write(regmap, ATMEL_HLCDC_DIS, ATMEL_HLCDC_SYNC);
while (!regmap_read(regmap, ATMEL_HLCDC_SR, &status) &&
(status & ATMEL_HLCDC_SYNC))
cpu_relax();
regmap_write(regmap, ATMEL_HLCDC_DIS, ATMEL_HLCDC_PIXEL_CLK);
while (!regmap_read(regmap, ATMEL_HLCDC_SR, &status) &&
(status & ATMEL_HLCDC_PIXEL_CLK))
cpu_relax();
clk_disable_unprepare(crtc->dc->hlcdc->sys_clk);
pinctrl_pm_select_sleep_state(dev->dev);
pm_runtime_allow(dev->dev);
pm_runtime_put_sync(dev->dev);
crtc->enabled = false;
}
static void atmel_hlcdc_crtc_enable(struct drm_crtc *c)
{
struct drm_device *dev = c->dev;
struct atmel_hlcdc_crtc *crtc = drm_crtc_to_atmel_hlcdc_crtc(c);
struct regmap *regmap = crtc->dc->hlcdc->regmap;
unsigned int status;
if (crtc->enabled)
return;
pm_runtime_get_sync(dev->dev);
pm_runtime_forbid(dev->dev);
pinctrl_pm_select_default_state(dev->dev);
clk_prepare_enable(crtc->dc->hlcdc->sys_clk);
regmap_write(regmap, ATMEL_HLCDC_EN, ATMEL_HLCDC_PIXEL_CLK);
while (!regmap_read(regmap, ATMEL_HLCDC_SR, &status) &&
!(status & ATMEL_HLCDC_PIXEL_CLK))
cpu_relax();
regmap_write(regmap, ATMEL_HLCDC_EN, ATMEL_HLCDC_SYNC);
while (!regmap_read(regmap, ATMEL_HLCDC_SR, &status) &&
!(status & ATMEL_HLCDC_SYNC))
cpu_relax();
regmap_write(regmap, ATMEL_HLCDC_EN, ATMEL_HLCDC_DISP);
while (!regmap_read(regmap, ATMEL_HLCDC_SR, &status) &&
!(status & ATMEL_HLCDC_DISP))
cpu_relax();
pm_runtime_put_sync(dev->dev);
drm_crtc_vblank_on(c);
crtc->enabled = true;
}
void atmel_hlcdc_crtc_suspend(struct drm_crtc *c)
{
struct atmel_hlcdc_crtc *crtc = drm_crtc_to_atmel_hlcdc_crtc(c);
if (crtc->enabled) {
atmel_hlcdc_crtc_disable(c);
crtc->enabled = true;
}
}
void atmel_hlcdc_crtc_resume(struct drm_crtc *c)
{
struct atmel_hlcdc_crtc *crtc = drm_crtc_to_atmel_hlcdc_crtc(c);
if (crtc->enabled) {
crtc->enabled = false;
atmel_hlcdc_crtc_enable(c);
}
}
static int atmel_hlcdc_crtc_atomic_check(struct drm_crtc *c,
struct drm_crtc_state *s)
{
struct atmel_hlcdc_crtc *crtc = drm_crtc_to_atmel_hlcdc_crtc(c);
if (atmel_hlcdc_dc_mode_valid(crtc->dc, &s->adjusted_mode) != MODE_OK)
return -EINVAL;
return atmel_hlcdc_plane_prepare_disc_area(s);
}
static void atmel_hlcdc_crtc_atomic_begin(struct drm_crtc *c)
{
struct atmel_hlcdc_crtc *crtc = drm_crtc_to_atmel_hlcdc_crtc(c);
if (c->state->event) {
c->state->event->pipe = drm_crtc_index(c);
WARN_ON(drm_crtc_vblank_get(c) != 0);
crtc->event = c->state->event;
c->state->event = NULL;
}
}
static void atmel_hlcdc_crtc_atomic_flush(struct drm_crtc *crtc)
{
}
static void atmel_hlcdc_crtc_destroy(struct drm_crtc *c)
{
struct atmel_hlcdc_crtc *crtc = drm_crtc_to_atmel_hlcdc_crtc(c);
drm_crtc_cleanup(c);
kfree(crtc);
}
void atmel_hlcdc_crtc_cancel_page_flip(struct drm_crtc *c,
struct drm_file *file)
{
struct atmel_hlcdc_crtc *crtc = drm_crtc_to_atmel_hlcdc_crtc(c);
struct drm_pending_vblank_event *event;
struct drm_device *dev = c->dev;
unsigned long flags;
spin_lock_irqsave(&dev->event_lock, flags);
event = crtc->event;
if (event && event->base.file_priv == file) {
event->base.destroy(&event->base);
drm_vblank_put(dev, crtc->id);
crtc->event = NULL;
}
spin_unlock_irqrestore(&dev->event_lock, flags);
}
static void atmel_hlcdc_crtc_finish_page_flip(struct atmel_hlcdc_crtc *crtc)
{
struct drm_device *dev = crtc->base.dev;
unsigned long flags;
spin_lock_irqsave(&dev->event_lock, flags);
if (crtc->event) {
drm_send_vblank_event(dev, crtc->id, crtc->event);
drm_vblank_put(dev, crtc->id);
crtc->event = NULL;
}
spin_unlock_irqrestore(&dev->event_lock, flags);
}
void atmel_hlcdc_crtc_irq(struct drm_crtc *c)
{
drm_handle_vblank(c->dev, 0);
atmel_hlcdc_crtc_finish_page_flip(drm_crtc_to_atmel_hlcdc_crtc(c));
}
int atmel_hlcdc_crtc_create(struct drm_device *dev)
{
struct atmel_hlcdc_dc *dc = dev->dev_private;
struct atmel_hlcdc_planes *planes = dc->planes;
struct atmel_hlcdc_crtc *crtc;
int ret;
int i;
crtc = kzalloc(sizeof(*crtc), GFP_KERNEL);
if (!crtc)
return -ENOMEM;
crtc->dc = dc;
ret = drm_crtc_init_with_planes(dev, &crtc->base,
&planes->primary->base,
planes->cursor ? &planes->cursor->base : NULL,
&atmel_hlcdc_crtc_funcs);
if (ret < 0)
goto fail;
crtc->id = drm_crtc_index(&crtc->base);
if (planes->cursor)
planes->cursor->base.possible_crtcs = 1 << crtc->id;
for (i = 0; i < planes->noverlays; i++)
planes->overlays[i]->base.possible_crtcs = 1 << crtc->id;
drm_crtc_helper_add(&crtc->base, &lcdc_crtc_helper_funcs);
dc->crtc = &crtc->base;
return 0;
fail:
atmel_hlcdc_crtc_destroy(&crtc->base);
return ret;
}
