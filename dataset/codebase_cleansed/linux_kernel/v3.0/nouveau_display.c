static void
nouveau_user_framebuffer_destroy(struct drm_framebuffer *drm_fb)
{
struct nouveau_framebuffer *fb = nouveau_framebuffer(drm_fb);
if (fb->nvbo)
drm_gem_object_unreference_unlocked(fb->nvbo->gem);
drm_framebuffer_cleanup(drm_fb);
kfree(fb);
}
static int
nouveau_user_framebuffer_create_handle(struct drm_framebuffer *drm_fb,
struct drm_file *file_priv,
unsigned int *handle)
{
struct nouveau_framebuffer *fb = nouveau_framebuffer(drm_fb);
return drm_gem_handle_create(file_priv, fb->nvbo->gem, handle);
}
int
nouveau_framebuffer_init(struct drm_device *dev,
struct nouveau_framebuffer *nv_fb,
struct drm_mode_fb_cmd *mode_cmd,
struct nouveau_bo *nvbo)
{
struct drm_nouveau_private *dev_priv = dev->dev_private;
struct drm_framebuffer *fb = &nv_fb->base;
int ret;
ret = drm_framebuffer_init(dev, fb, &nouveau_framebuffer_funcs);
if (ret) {
return ret;
}
drm_helper_mode_fill_fb_struct(fb, mode_cmd);
nv_fb->nvbo = nvbo;
if (dev_priv->card_type >= NV_50) {
u32 tile_flags = nouveau_bo_tile_layout(nvbo);
if (tile_flags == 0x7a00 ||
tile_flags == 0xfe00)
nv_fb->r_dma = NvEvoFB32;
else
if (tile_flags == 0x7000)
nv_fb->r_dma = NvEvoFB16;
else
nv_fb->r_dma = NvEvoVRAM_LP;
switch (fb->depth) {
case 8: nv_fb->r_format = NV50_EVO_CRTC_FB_DEPTH_8; break;
case 15: nv_fb->r_format = NV50_EVO_CRTC_FB_DEPTH_15; break;
case 16: nv_fb->r_format = NV50_EVO_CRTC_FB_DEPTH_16; break;
case 24:
case 32: nv_fb->r_format = NV50_EVO_CRTC_FB_DEPTH_24; break;
case 30: nv_fb->r_format = NV50_EVO_CRTC_FB_DEPTH_30; break;
default:
NV_ERROR(dev, "unknown depth %d\n", fb->depth);
return -EINVAL;
}
if (dev_priv->chipset == 0x50)
nv_fb->r_format |= (tile_flags << 8);
if (!tile_flags)
nv_fb->r_pitch = 0x00100000 | fb->pitch;
else {
u32 mode = nvbo->tile_mode;
if (dev_priv->card_type >= NV_C0)
mode >>= 4;
nv_fb->r_pitch = ((fb->pitch / 4) << 4) | mode;
}
}
return 0;
}
static struct drm_framebuffer *
nouveau_user_framebuffer_create(struct drm_device *dev,
struct drm_file *file_priv,
struct drm_mode_fb_cmd *mode_cmd)
{
struct nouveau_framebuffer *nouveau_fb;
struct drm_gem_object *gem;
int ret;
gem = drm_gem_object_lookup(dev, file_priv, mode_cmd->handle);
if (!gem)
return ERR_PTR(-ENOENT);
nouveau_fb = kzalloc(sizeof(struct nouveau_framebuffer), GFP_KERNEL);
if (!nouveau_fb)
return ERR_PTR(-ENOMEM);
ret = nouveau_framebuffer_init(dev, nouveau_fb, mode_cmd, nouveau_gem_object(gem));
if (ret) {
drm_gem_object_unreference(gem);
return ERR_PTR(ret);
}
return &nouveau_fb->base;
}
int
nouveau_vblank_enable(struct drm_device *dev, int crtc)
{
struct drm_nouveau_private *dev_priv = dev->dev_private;
if (dev_priv->card_type >= NV_50)
nv_mask(dev, NV50_PDISPLAY_INTR_EN_1, 0,
NV50_PDISPLAY_INTR_EN_1_VBLANK_CRTC_(crtc));
else
NVWriteCRTC(dev, crtc, NV_PCRTC_INTR_EN_0,
NV_PCRTC_INTR_0_VBLANK);
return 0;
}
void
nouveau_vblank_disable(struct drm_device *dev, int crtc)
{
struct drm_nouveau_private *dev_priv = dev->dev_private;
if (dev_priv->card_type >= NV_50)
nv_mask(dev, NV50_PDISPLAY_INTR_EN_1,
NV50_PDISPLAY_INTR_EN_1_VBLANK_CRTC_(crtc), 0);
else
NVWriteCRTC(dev, crtc, NV_PCRTC_INTR_EN_0, 0);
}
static int
nouveau_page_flip_reserve(struct nouveau_bo *old_bo,
struct nouveau_bo *new_bo)
{
int ret;
ret = nouveau_bo_pin(new_bo, TTM_PL_FLAG_VRAM);
if (ret)
return ret;
ret = ttm_bo_reserve(&new_bo->bo, false, false, false, 0);
if (ret)
goto fail;
ret = ttm_bo_reserve(&old_bo->bo, false, false, false, 0);
if (ret)
goto fail_unreserve;
return 0;
fail_unreserve:
ttm_bo_unreserve(&new_bo->bo);
fail:
nouveau_bo_unpin(new_bo);
return ret;
}
static void
nouveau_page_flip_unreserve(struct nouveau_bo *old_bo,
struct nouveau_bo *new_bo,
struct nouveau_fence *fence)
{
nouveau_bo_fence(new_bo, fence);
ttm_bo_unreserve(&new_bo->bo);
nouveau_bo_fence(old_bo, fence);
ttm_bo_unreserve(&old_bo->bo);
nouveau_bo_unpin(old_bo);
}
static int
nouveau_page_flip_emit(struct nouveau_channel *chan,
struct nouveau_bo *old_bo,
struct nouveau_bo *new_bo,
struct nouveau_page_flip_state *s,
struct nouveau_fence **pfence)
{
struct drm_nouveau_private *dev_priv = chan->dev->dev_private;
struct drm_device *dev = chan->dev;
unsigned long flags;
int ret;
spin_lock_irqsave(&dev->event_lock, flags);
list_add_tail(&s->head, &chan->nvsw.flip);
spin_unlock_irqrestore(&dev->event_lock, flags);
ret = nouveau_fence_sync(old_bo->bo.sync_obj, chan);
if (ret)
goto fail;
ret = RING_SPACE(chan, 2);
if (ret)
goto fail;
if (dev_priv->card_type < NV_C0)
BEGIN_RING(chan, NvSubSw, NV_SW_PAGE_FLIP, 1);
else
BEGIN_NVC0(chan, 2, NvSubM2MF, 0x0500, 1);
OUT_RING (chan, 0);
FIRE_RING (chan);
ret = nouveau_fence_new(chan, pfence, true);
if (ret)
goto fail;
return 0;
fail:
spin_lock_irqsave(&dev->event_lock, flags);
list_del(&s->head);
spin_unlock_irqrestore(&dev->event_lock, flags);
return ret;
}
int
nouveau_crtc_page_flip(struct drm_crtc *crtc, struct drm_framebuffer *fb,
struct drm_pending_vblank_event *event)
{
struct drm_device *dev = crtc->dev;
struct drm_nouveau_private *dev_priv = dev->dev_private;
struct nouveau_bo *old_bo = nouveau_framebuffer(crtc->fb)->nvbo;
struct nouveau_bo *new_bo = nouveau_framebuffer(fb)->nvbo;
struct nouveau_page_flip_state *s;
struct nouveau_channel *chan;
struct nouveau_fence *fence;
int ret;
if (!dev_priv->channel)
return -ENODEV;
s = kzalloc(sizeof(*s), GFP_KERNEL);
if (!s)
return -ENOMEM;
ret = nouveau_page_flip_reserve(old_bo, new_bo);
if (ret)
goto fail_free;
*s = (struct nouveau_page_flip_state)
{ { }, event, nouveau_crtc(crtc)->index,
fb->bits_per_pixel, fb->pitch, crtc->x, crtc->y,
new_bo->bo.offset };
chan = nouveau_fence_channel(new_bo->bo.sync_obj);
if (!chan)
chan = nouveau_channel_get_unlocked(dev_priv->channel);
mutex_lock(&chan->mutex);
if (dev_priv->card_type >= NV_50) {
ret = nv50_display_flip_next(crtc, fb, chan);
if (ret) {
nouveau_channel_put(&chan);
goto fail_unreserve;
}
}
ret = nouveau_page_flip_emit(chan, old_bo, new_bo, s, &fence);
nouveau_channel_put(&chan);
if (ret)
goto fail_unreserve;
crtc->fb = fb;
nouveau_page_flip_unreserve(old_bo, new_bo, fence);
nouveau_fence_unref(&fence);
return 0;
fail_unreserve:
nouveau_page_flip_unreserve(old_bo, new_bo, NULL);
fail_free:
kfree(s);
return ret;
}
int
nouveau_finish_page_flip(struct nouveau_channel *chan,
struct nouveau_page_flip_state *ps)
{
struct drm_device *dev = chan->dev;
struct nouveau_page_flip_state *s;
unsigned long flags;
spin_lock_irqsave(&dev->event_lock, flags);
if (list_empty(&chan->nvsw.flip)) {
NV_ERROR(dev, "Unexpected pageflip in channel %d.\n", chan->id);
spin_unlock_irqrestore(&dev->event_lock, flags);
return -EINVAL;
}
s = list_first_entry(&chan->nvsw.flip,
struct nouveau_page_flip_state, head);
if (s->event) {
struct drm_pending_vblank_event *e = s->event;
struct timeval now;
do_gettimeofday(&now);
e->event.sequence = 0;
e->event.tv_sec = now.tv_sec;
e->event.tv_usec = now.tv_usec;
list_add_tail(&e->base.link, &e->base.file_priv->event_list);
wake_up_interruptible(&e->base.file_priv->event_wait);
}
list_del(&s->head);
if (ps)
*ps = *s;
kfree(s);
spin_unlock_irqrestore(&dev->event_lock, flags);
return 0;
}
