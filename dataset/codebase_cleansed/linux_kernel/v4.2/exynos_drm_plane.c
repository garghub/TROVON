static int exynos_plane_get_size(int start, unsigned length, unsigned last)
{
int end = start + length;
int size = 0;
if (start <= 0) {
if (end > 0)
size = min_t(unsigned, end, last);
} else if (start <= last) {
size = min_t(unsigned, last - start, length);
}
return size;
}
static void exynos_plane_mode_set(struct drm_plane *plane,
struct drm_crtc *crtc,
struct drm_framebuffer *fb,
int crtc_x, int crtc_y,
unsigned int crtc_w, unsigned int crtc_h,
uint32_t src_x, uint32_t src_y,
uint32_t src_w, uint32_t src_h)
{
struct exynos_drm_plane *exynos_plane = to_exynos_plane(plane);
struct drm_display_mode *mode = &crtc->state->adjusted_mode;
unsigned int actual_w;
unsigned int actual_h;
actual_w = exynos_plane_get_size(crtc_x, crtc_w, mode->hdisplay);
actual_h = exynos_plane_get_size(crtc_y, crtc_h, mode->vdisplay);
if (crtc_x < 0) {
if (actual_w)
src_x -= crtc_x;
crtc_x = 0;
}
if (crtc_y < 0) {
if (actual_h)
src_y -= crtc_y;
crtc_y = 0;
}
exynos_plane->h_ratio = (src_w << 16) / crtc_w;
exynos_plane->v_ratio = (src_h << 16) / crtc_h;
exynos_plane->src_x = src_x;
exynos_plane->src_y = src_y;
exynos_plane->src_width = (actual_w * exynos_plane->h_ratio) >> 16;
exynos_plane->src_height = (actual_h * exynos_plane->v_ratio) >> 16;
exynos_plane->fb_width = fb->width;
exynos_plane->fb_height = fb->height;
exynos_plane->bpp = fb->bits_per_pixel;
exynos_plane->pitch = fb->pitches[0];
exynos_plane->pixel_format = fb->pixel_format;
exynos_plane->crtc_x = crtc_x;
exynos_plane->crtc_y = crtc_y;
exynos_plane->crtc_width = actual_w;
exynos_plane->crtc_height = actual_h;
exynos_plane->mode_width = mode->hdisplay;
exynos_plane->mode_height = mode->vdisplay;
exynos_plane->refresh = mode->vrefresh;
exynos_plane->scan_flag = mode->flags;
DRM_DEBUG_KMS("plane : offset_x/y(%d,%d), width/height(%d,%d)",
exynos_plane->crtc_x, exynos_plane->crtc_y,
exynos_plane->crtc_width, exynos_plane->crtc_height);
plane->crtc = crtc;
}
static int exynos_plane_atomic_check(struct drm_plane *plane,
struct drm_plane_state *state)
{
struct exynos_drm_plane *exynos_plane = to_exynos_plane(plane);
int nr;
int i;
if (!state->fb)
return 0;
nr = exynos_drm_fb_get_buf_cnt(state->fb);
for (i = 0; i < nr; i++) {
struct exynos_drm_gem_buf *buffer =
exynos_drm_fb_buffer(state->fb, i);
if (!buffer) {
DRM_DEBUG_KMS("buffer is null\n");
return -EFAULT;
}
exynos_plane->dma_addr[i] = buffer->dma_addr +
state->fb->offsets[i];
DRM_DEBUG_KMS("buffer: %d, dma_addr = 0x%lx\n",
i, (unsigned long)exynos_plane->dma_addr[i]);
}
return 0;
}
static void exynos_plane_atomic_update(struct drm_plane *plane,
struct drm_plane_state *old_state)
{
struct drm_plane_state *state = plane->state;
struct exynos_drm_crtc *exynos_crtc = to_exynos_crtc(state->crtc);
struct exynos_drm_plane *exynos_plane = to_exynos_plane(plane);
if (!state->crtc)
return;
exynos_plane_mode_set(plane, state->crtc, state->fb,
state->crtc_x, state->crtc_y,
state->crtc_w, state->crtc_h,
state->src_x >> 16, state->src_y >> 16,
state->src_w >> 16, state->src_h >> 16);
if (exynos_crtc->ops->win_commit)
exynos_crtc->ops->win_commit(exynos_crtc, exynos_plane->zpos);
}
static void exynos_plane_atomic_disable(struct drm_plane *plane,
struct drm_plane_state *old_state)
{
struct exynos_drm_plane *exynos_plane = to_exynos_plane(plane);
struct exynos_drm_crtc *exynos_crtc = to_exynos_crtc(old_state->crtc);
if (!old_state->crtc)
return;
if (exynos_crtc->ops->win_disable)
exynos_crtc->ops->win_disable(exynos_crtc,
exynos_plane->zpos);
}
static void exynos_plane_attach_zpos_property(struct drm_plane *plane,
unsigned int zpos)
{
struct drm_device *dev = plane->dev;
struct exynos_drm_private *dev_priv = dev->dev_private;
struct drm_property *prop;
prop = dev_priv->plane_zpos_property;
if (!prop) {
prop = drm_property_create_range(dev, DRM_MODE_PROP_IMMUTABLE,
"zpos", 0, MAX_PLANE - 1);
if (!prop)
return;
dev_priv->plane_zpos_property = prop;
}
drm_object_attach_property(&plane->base, prop, zpos);
}
int exynos_plane_init(struct drm_device *dev,
struct exynos_drm_plane *exynos_plane,
unsigned long possible_crtcs, enum drm_plane_type type,
unsigned int zpos)
{
int err;
err = drm_universal_plane_init(dev, &exynos_plane->base, possible_crtcs,
&exynos_plane_funcs, formats,
ARRAY_SIZE(formats), type);
if (err) {
DRM_ERROR("failed to initialize plane\n");
return err;
}
drm_plane_helper_add(&exynos_plane->base, &plane_helper_funcs);
exynos_plane->zpos = zpos;
if (type == DRM_PLANE_TYPE_OVERLAY)
exynos_plane_attach_zpos_property(&exynos_plane->base, zpos);
return 0;
}
