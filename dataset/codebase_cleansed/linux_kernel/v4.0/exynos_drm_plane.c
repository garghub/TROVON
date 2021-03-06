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
int exynos_check_plane(struct drm_plane *plane, struct drm_framebuffer *fb)
{
struct exynos_drm_plane *exynos_plane = to_exynos_plane(plane);
int nr;
int i;
nr = exynos_drm_fb_get_buf_cnt(fb);
for (i = 0; i < nr; i++) {
struct exynos_drm_gem_buf *buffer = exynos_drm_fb_buffer(fb, i);
if (!buffer) {
DRM_DEBUG_KMS("buffer is null\n");
return -EFAULT;
}
exynos_plane->dma_addr[i] = buffer->dma_addr;
DRM_DEBUG_KMS("buffer: %d, dma_addr = 0x%lx\n",
i, (unsigned long)exynos_plane->dma_addr[i]);
}
return 0;
}
void exynos_plane_mode_set(struct drm_plane *plane, struct drm_crtc *crtc,
struct drm_framebuffer *fb, int crtc_x, int crtc_y,
unsigned int crtc_w, unsigned int crtc_h,
uint32_t src_x, uint32_t src_y,
uint32_t src_w, uint32_t src_h)
{
struct exynos_drm_plane *exynos_plane = to_exynos_plane(plane);
struct exynos_drm_crtc *exynos_crtc = to_exynos_crtc(crtc);
unsigned int actual_w;
unsigned int actual_h;
actual_w = exynos_plane_get_size(crtc_x, crtc_w, crtc->mode.hdisplay);
actual_h = exynos_plane_get_size(crtc_y, crtc_h, crtc->mode.vdisplay);
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
exynos_plane->fb_x = src_x;
exynos_plane->fb_y = src_y;
exynos_plane->fb_width = fb->width;
exynos_plane->fb_height = fb->height;
exynos_plane->src_width = src_w;
exynos_plane->src_height = src_h;
exynos_plane->bpp = fb->bits_per_pixel;
exynos_plane->pitch = fb->pitches[0];
exynos_plane->pixel_format = fb->pixel_format;
exynos_plane->crtc_x = crtc_x;
exynos_plane->crtc_y = crtc_y;
exynos_plane->crtc_width = actual_w;
exynos_plane->crtc_height = actual_h;
exynos_plane->mode_width = crtc->mode.hdisplay;
exynos_plane->mode_height = crtc->mode.vdisplay;
exynos_plane->refresh = crtc->mode.vrefresh;
exynos_plane->scan_flag = crtc->mode.flags;
DRM_DEBUG_KMS("plane : offset_x/y(%d,%d), width/height(%d,%d)",
exynos_plane->crtc_x, exynos_plane->crtc_y,
exynos_plane->crtc_width, exynos_plane->crtc_height);
plane->crtc = crtc;
if (exynos_crtc->ops->win_mode_set)
exynos_crtc->ops->win_mode_set(exynos_crtc, exynos_plane);
}
int
exynos_update_plane(struct drm_plane *plane, struct drm_crtc *crtc,
struct drm_framebuffer *fb, int crtc_x, int crtc_y,
unsigned int crtc_w, unsigned int crtc_h,
uint32_t src_x, uint32_t src_y,
uint32_t src_w, uint32_t src_h)
{
struct exynos_drm_crtc *exynos_crtc = to_exynos_crtc(crtc);
struct exynos_drm_plane *exynos_plane = to_exynos_plane(plane);
int ret;
ret = exynos_check_plane(plane, fb);
if (ret < 0)
return ret;
exynos_plane_mode_set(plane, crtc, fb, crtc_x, crtc_y,
crtc_w, crtc_h, src_x >> 16, src_y >> 16,
src_w >> 16, src_h >> 16);
if (exynos_crtc->ops->win_commit)
exynos_crtc->ops->win_commit(exynos_crtc, exynos_plane->zpos);
return 0;
}
static int exynos_disable_plane(struct drm_plane *plane)
{
struct exynos_drm_plane *exynos_plane = to_exynos_plane(plane);
struct exynos_drm_crtc *exynos_crtc = to_exynos_crtc(plane->crtc);
if (exynos_crtc && exynos_crtc->ops->win_disable)
exynos_crtc->ops->win_disable(exynos_crtc,
exynos_plane->zpos);
return 0;
}
static void exynos_plane_destroy(struct drm_plane *plane)
{
struct exynos_drm_plane *exynos_plane = to_exynos_plane(plane);
exynos_disable_plane(plane);
drm_plane_cleanup(plane);
kfree(exynos_plane);
}
static int exynos_plane_set_property(struct drm_plane *plane,
struct drm_property *property,
uint64_t val)
{
struct drm_device *dev = plane->dev;
struct exynos_drm_plane *exynos_plane = to_exynos_plane(plane);
struct exynos_drm_private *dev_priv = dev->dev_private;
if (property == dev_priv->plane_zpos_property) {
exynos_plane->zpos = val;
return 0;
}
return -EINVAL;
}
static void exynos_plane_attach_zpos_property(struct drm_plane *plane)
{
struct drm_device *dev = plane->dev;
struct exynos_drm_private *dev_priv = dev->dev_private;
struct drm_property *prop;
prop = dev_priv->plane_zpos_property;
if (!prop) {
prop = drm_property_create_range(dev, 0, "zpos", 0,
MAX_PLANE - 1);
if (!prop)
return;
dev_priv->plane_zpos_property = prop;
}
drm_object_attach_property(&plane->base, prop, 0);
}
struct drm_plane *exynos_plane_init(struct drm_device *dev,
unsigned long possible_crtcs,
enum drm_plane_type type)
{
struct exynos_drm_plane *exynos_plane;
int err;
exynos_plane = kzalloc(sizeof(struct exynos_drm_plane), GFP_KERNEL);
if (!exynos_plane)
return ERR_PTR(-ENOMEM);
err = drm_universal_plane_init(dev, &exynos_plane->base, possible_crtcs,
&exynos_plane_funcs, formats,
ARRAY_SIZE(formats), type);
if (err) {
DRM_ERROR("failed to initialize plane\n");
kfree(exynos_plane);
return ERR_PTR(err);
}
if (type == DRM_PLANE_TYPE_PRIMARY)
exynos_plane->zpos = DEFAULT_ZPOS;
else
exynos_plane_attach_zpos_property(&exynos_plane->base);
return &exynos_plane->base;
}
