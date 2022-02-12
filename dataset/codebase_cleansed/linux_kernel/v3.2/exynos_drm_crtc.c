static void exynos_drm_crtc_apply(struct drm_crtc *crtc)
{
struct exynos_drm_crtc *exynos_crtc = to_exynos_crtc(crtc);
struct exynos_drm_overlay *overlay = &exynos_crtc->overlay;
exynos_drm_fn_encoder(crtc, overlay,
exynos_drm_encoder_crtc_mode_set);
exynos_drm_fn_encoder(crtc, &exynos_crtc->pipe,
exynos_drm_encoder_crtc_commit);
}
int exynos_drm_overlay_update(struct exynos_drm_overlay *overlay,
struct drm_framebuffer *fb,
struct drm_display_mode *mode,
struct exynos_drm_crtc_pos *pos)
{
struct exynos_drm_gem_buf *buffer;
unsigned int actual_w;
unsigned int actual_h;
buffer = exynos_drm_fb_get_buf(fb);
if (!buffer) {
DRM_LOG_KMS("buffer is null.\n");
return -EFAULT;
}
overlay->dma_addr = buffer->dma_addr;
overlay->vaddr = buffer->kvaddr;
DRM_DEBUG_KMS("vaddr = 0x%lx, dma_addr = 0x%lx\n",
(unsigned long)overlay->vaddr,
(unsigned long)overlay->dma_addr);
actual_w = min((mode->hdisplay - pos->crtc_x), pos->crtc_w);
actual_h = min((mode->vdisplay - pos->crtc_y), pos->crtc_h);
overlay->fb_x = pos->fb_x;
overlay->fb_y = pos->fb_y;
overlay->fb_width = fb->width;
overlay->fb_height = fb->height;
overlay->bpp = fb->bits_per_pixel;
overlay->pitch = fb->pitch;
overlay->crtc_x = pos->crtc_x;
overlay->crtc_y = pos->crtc_y;
overlay->crtc_width = actual_w;
overlay->crtc_height = actual_h;
overlay->mode_width = mode->hdisplay;
overlay->mode_height = mode->vdisplay;
overlay->refresh = mode->vrefresh;
overlay->scan_flag = mode->flags;
DRM_DEBUG_KMS("overlay : offset_x/y(%d,%d), width/height(%d,%d)",
overlay->crtc_x, overlay->crtc_y,
overlay->crtc_width, overlay->crtc_height);
return 0;
}
static int exynos_drm_crtc_update(struct drm_crtc *crtc)
{
struct exynos_drm_crtc *exynos_crtc;
struct exynos_drm_overlay *overlay;
struct exynos_drm_crtc_pos pos;
struct drm_display_mode *mode = &crtc->mode;
struct drm_framebuffer *fb = crtc->fb;
if (!mode || !fb)
return -EINVAL;
exynos_crtc = to_exynos_crtc(crtc);
overlay = &exynos_crtc->overlay;
memset(&pos, 0, sizeof(struct exynos_drm_crtc_pos));
pos.fb_x = crtc->x;
pos.fb_y = crtc->y;
pos.crtc_x = 0;
pos.crtc_y = 0;
pos.crtc_w = fb->width - crtc->x;
pos.crtc_h = fb->height - crtc->y;
return exynos_drm_overlay_update(overlay, crtc->fb, mode, &pos);
}
static void exynos_drm_crtc_dpms(struct drm_crtc *crtc, int mode)
{
struct exynos_drm_crtc *exynos_crtc = to_exynos_crtc(crtc);
DRM_DEBUG_KMS("crtc[%d] mode[%d]\n", crtc->base.id, mode);
switch (mode) {
case DRM_MODE_DPMS_ON:
exynos_drm_fn_encoder(crtc, &exynos_crtc->pipe,
exynos_drm_encoder_crtc_commit);
break;
case DRM_MODE_DPMS_STANDBY:
case DRM_MODE_DPMS_SUSPEND:
case DRM_MODE_DPMS_OFF:
exynos_drm_fn_encoder(crtc, NULL,
exynos_drm_encoder_crtc_disable);
break;
default:
DRM_DEBUG_KMS("unspecified mode %d\n", mode);
break;
}
}
static void exynos_drm_crtc_prepare(struct drm_crtc *crtc)
{
DRM_DEBUG_KMS("%s\n", __FILE__);
}
static void exynos_drm_crtc_commit(struct drm_crtc *crtc)
{
struct exynos_drm_crtc *exynos_crtc = to_exynos_crtc(crtc);
DRM_DEBUG_KMS("%s\n", __FILE__);
exynos_drm_fn_encoder(crtc, &exynos_crtc->pipe,
exynos_drm_encoder_crtc_commit);
}
static bool
exynos_drm_crtc_mode_fixup(struct drm_crtc *crtc,
struct drm_display_mode *mode,
struct drm_display_mode *adjusted_mode)
{
DRM_DEBUG_KMS("%s\n", __FILE__);
return true;
}
static int
exynos_drm_crtc_mode_set(struct drm_crtc *crtc, struct drm_display_mode *mode,
struct drm_display_mode *adjusted_mode, int x, int y,
struct drm_framebuffer *old_fb)
{
DRM_DEBUG_KMS("%s\n", __FILE__);
mode = adjusted_mode;
return exynos_drm_crtc_update(crtc);
}
static int exynos_drm_crtc_mode_set_base(struct drm_crtc *crtc, int x, int y,
struct drm_framebuffer *old_fb)
{
int ret;
DRM_DEBUG_KMS("%s\n", __FILE__);
ret = exynos_drm_crtc_update(crtc);
if (ret)
return ret;
exynos_drm_crtc_apply(crtc);
return ret;
}
static void exynos_drm_crtc_load_lut(struct drm_crtc *crtc)
{
DRM_DEBUG_KMS("%s\n", __FILE__);
}
static int exynos_drm_crtc_page_flip(struct drm_crtc *crtc,
struct drm_framebuffer *fb,
struct drm_pending_vblank_event *event)
{
struct drm_device *dev = crtc->dev;
struct exynos_drm_private *dev_priv = dev->dev_private;
struct exynos_drm_crtc *exynos_crtc = to_exynos_crtc(crtc);
struct drm_framebuffer *old_fb = crtc->fb;
int ret = -EINVAL;
DRM_DEBUG_KMS("%s\n", __FILE__);
mutex_lock(&dev->struct_mutex);
if (event) {
event->pipe = exynos_crtc->pipe;
list_add_tail(&event->base.link,
&dev_priv->pageflip_event_list);
ret = drm_vblank_get(dev, exynos_crtc->pipe);
if (ret) {
DRM_DEBUG("failed to acquire vblank counter\n");
list_del(&event->base.link);
goto out;
}
crtc->fb = fb;
ret = exynos_drm_crtc_update(crtc);
if (ret) {
crtc->fb = old_fb;
drm_vblank_put(dev, exynos_crtc->pipe);
list_del(&event->base.link);
goto out;
}
exynos_drm_crtc_apply(crtc);
}
out:
mutex_unlock(&dev->struct_mutex);
return ret;
}
static void exynos_drm_crtc_destroy(struct drm_crtc *crtc)
{
struct exynos_drm_crtc *exynos_crtc = to_exynos_crtc(crtc);
struct exynos_drm_private *private = crtc->dev->dev_private;
DRM_DEBUG_KMS("%s\n", __FILE__);
private->crtc[exynos_crtc->pipe] = NULL;
drm_crtc_cleanup(crtc);
kfree(exynos_crtc);
}
struct exynos_drm_overlay *get_exynos_drm_overlay(struct drm_device *dev,
struct drm_crtc *crtc)
{
struct exynos_drm_crtc *exynos_crtc = to_exynos_crtc(crtc);
return &exynos_crtc->overlay;
}
int exynos_drm_crtc_create(struct drm_device *dev, unsigned int nr)
{
struct exynos_drm_crtc *exynos_crtc;
struct exynos_drm_private *private = dev->dev_private;
struct drm_crtc *crtc;
DRM_DEBUG_KMS("%s\n", __FILE__);
exynos_crtc = kzalloc(sizeof(*exynos_crtc), GFP_KERNEL);
if (!exynos_crtc) {
DRM_ERROR("failed to allocate exynos crtc\n");
return -ENOMEM;
}
exynos_crtc->pipe = nr;
crtc = &exynos_crtc->drm_crtc;
private->crtc[nr] = crtc;
drm_crtc_init(dev, crtc, &exynos_crtc_funcs);
drm_crtc_helper_add(crtc, &exynos_crtc_helper_funcs);
return 0;
}
int exynos_drm_crtc_enable_vblank(struct drm_device *dev, int crtc)
{
struct exynos_drm_private *private = dev->dev_private;
DRM_DEBUG_KMS("%s\n", __FILE__);
exynos_drm_fn_encoder(private->crtc[crtc], &crtc,
exynos_drm_enable_vblank);
return 0;
}
void exynos_drm_crtc_disable_vblank(struct drm_device *dev, int crtc)
{
struct exynos_drm_private *private = dev->dev_private;
DRM_DEBUG_KMS("%s\n", __FILE__);
exynos_drm_fn_encoder(private->crtc[crtc], &crtc,
exynos_drm_disable_vblank);
}
