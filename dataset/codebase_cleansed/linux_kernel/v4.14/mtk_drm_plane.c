static void mtk_plane_reset(struct drm_plane *plane)
{
struct mtk_plane_state *state;
if (plane->state) {
__drm_atomic_helper_plane_destroy_state(plane->state);
state = to_mtk_plane_state(plane->state);
memset(state, 0, sizeof(*state));
} else {
state = kzalloc(sizeof(*state), GFP_KERNEL);
if (!state)
return;
plane->state = &state->base;
}
state->base.plane = plane;
state->pending.format = DRM_FORMAT_RGB565;
}
static struct drm_plane_state *mtk_plane_duplicate_state(struct drm_plane *plane)
{
struct mtk_plane_state *old_state = to_mtk_plane_state(plane->state);
struct mtk_plane_state *state;
state = kzalloc(sizeof(*state), GFP_KERNEL);
if (!state)
return NULL;
__drm_atomic_helper_plane_duplicate_state(plane, &state->base);
WARN_ON(state->base.plane != plane);
state->pending = old_state->pending;
return &state->base;
}
static void mtk_drm_plane_destroy_state(struct drm_plane *plane,
struct drm_plane_state *state)
{
__drm_atomic_helper_plane_destroy_state(state);
kfree(to_mtk_plane_state(state));
}
static int mtk_plane_atomic_check(struct drm_plane *plane,
struct drm_plane_state *state)
{
struct drm_framebuffer *fb = state->fb;
struct drm_crtc_state *crtc_state;
struct drm_rect clip = { 0, };
if (!fb)
return 0;
if (!mtk_fb_get_gem_obj(fb)) {
DRM_DEBUG_KMS("buffer is null\n");
return -EFAULT;
}
if (!state->crtc)
return 0;
crtc_state = drm_atomic_get_crtc_state(state->state, state->crtc);
if (IS_ERR(crtc_state))
return PTR_ERR(crtc_state);
clip.x2 = crtc_state->mode.hdisplay;
clip.y2 = crtc_state->mode.vdisplay;
return drm_plane_helper_check_state(state, &clip,
DRM_PLANE_HELPER_NO_SCALING,
DRM_PLANE_HELPER_NO_SCALING,
true, true);
}
static void mtk_plane_atomic_update(struct drm_plane *plane,
struct drm_plane_state *old_state)
{
struct mtk_plane_state *state = to_mtk_plane_state(plane->state);
struct drm_crtc *crtc = plane->state->crtc;
struct drm_framebuffer *fb = plane->state->fb;
struct drm_gem_object *gem;
struct mtk_drm_gem_obj *mtk_gem;
unsigned int pitch, format;
dma_addr_t addr;
if (!crtc || WARN_ON(!fb))
return;
gem = mtk_fb_get_gem_obj(fb);
mtk_gem = to_mtk_gem_obj(gem);
addr = mtk_gem->dma_addr;
pitch = fb->pitches[0];
format = fb->format->format;
addr += (plane->state->src.x1 >> 16) * fb->format->cpp[0];
addr += (plane->state->src.y1 >> 16) * pitch;
state->pending.enable = true;
state->pending.pitch = pitch;
state->pending.format = format;
state->pending.addr = addr;
state->pending.x = plane->state->dst.x1;
state->pending.y = plane->state->dst.y1;
state->pending.width = drm_rect_width(&plane->state->dst);
state->pending.height = drm_rect_height(&plane->state->dst);
wmb();
state->pending.dirty = true;
}
static void mtk_plane_atomic_disable(struct drm_plane *plane,
struct drm_plane_state *old_state)
{
struct mtk_plane_state *state = to_mtk_plane_state(plane->state);
state->pending.enable = false;
wmb();
state->pending.dirty = true;
}
int mtk_plane_init(struct drm_device *dev, struct drm_plane *plane,
unsigned long possible_crtcs, enum drm_plane_type type)
{
int err;
err = drm_universal_plane_init(dev, plane, possible_crtcs,
&mtk_plane_funcs, formats,
ARRAY_SIZE(formats), NULL, type, NULL);
if (err) {
DRM_ERROR("failed to initialize plane\n");
return err;
}
drm_plane_helper_add(plane, &mtk_plane_helper_funcs);
return 0;
}
