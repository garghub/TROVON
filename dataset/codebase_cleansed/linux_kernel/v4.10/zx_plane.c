static int zx_gl_plane_atomic_check(struct drm_plane *plane,
struct drm_plane_state *plane_state)
{
struct drm_framebuffer *fb = plane_state->fb;
struct drm_crtc *crtc = plane_state->crtc;
struct drm_crtc_state *crtc_state;
struct drm_rect clip;
if (!crtc || !fb)
return 0;
crtc_state = drm_atomic_get_existing_crtc_state(plane_state->state,
crtc);
if (WARN_ON(!crtc_state))
return -EINVAL;
if (!crtc_state->enable)
return 0;
if (!plane_state->crtc)
return -EINVAL;
clip.x1 = 0;
clip.y1 = 0;
clip.x2 = crtc_state->adjusted_mode.hdisplay;
clip.y2 = crtc_state->adjusted_mode.vdisplay;
return drm_plane_helper_check_state(plane_state, &clip,
DRM_PLANE_HELPER_NO_SCALING,
DRM_PLANE_HELPER_NO_SCALING,
false, true);
}
static int zx_gl_get_fmt(uint32_t format)
{
switch (format) {
case DRM_FORMAT_ARGB8888:
case DRM_FORMAT_XRGB8888:
return GL_FMT_ARGB8888;
case DRM_FORMAT_RGB888:
return GL_FMT_RGB888;
case DRM_FORMAT_RGB565:
return GL_FMT_RGB565;
case DRM_FORMAT_ARGB1555:
return GL_FMT_ARGB1555;
case DRM_FORMAT_ARGB4444:
return GL_FMT_ARGB4444;
default:
WARN_ONCE(1, "invalid pixel format %d\n", format);
return -EINVAL;
}
}
static inline void zx_gl_set_update(struct zx_plane *zplane)
{
void __iomem *layer = zplane->layer;
zx_writel_mask(layer + GL_CTRL0, GL_UPDATE, GL_UPDATE);
}
static inline void zx_gl_rsz_set_update(struct zx_plane *zplane)
{
zx_writel(zplane->rsz + RSZ_ENABLE_CFG, 1);
}
void zx_plane_set_update(struct drm_plane *plane)
{
struct zx_plane *zplane = to_zx_plane(plane);
zx_gl_rsz_set_update(zplane);
zx_gl_set_update(zplane);
}
static void zx_gl_rsz_setup(struct zx_plane *zplane, u32 src_w, u32 src_h,
u32 dst_w, u32 dst_h)
{
void __iomem *rsz = zplane->rsz;
zx_writel(rsz + RSZ_SRC_CFG, RSZ_VER(src_h - 1) | RSZ_HOR(src_w - 1));
zx_writel(rsz + RSZ_DEST_CFG, RSZ_VER(dst_h - 1) | RSZ_HOR(dst_w - 1));
zx_gl_rsz_set_update(zplane);
}
static void zx_gl_plane_atomic_update(struct drm_plane *plane,
struct drm_plane_state *old_state)
{
struct zx_plane *zplane = to_zx_plane(plane);
struct drm_framebuffer *fb = plane->state->fb;
struct drm_gem_cma_object *cma_obj;
void __iomem *layer = zplane->layer;
void __iomem *csc = zplane->csc;
void __iomem *hbsc = zplane->hbsc;
u32 src_x, src_y, src_w, src_h;
u32 dst_x, dst_y, dst_w, dst_h;
unsigned int bpp;
uint32_t format;
dma_addr_t paddr;
u32 stride;
int fmt;
if (!fb)
return;
format = fb->pixel_format;
stride = fb->pitches[0];
src_x = plane->state->src_x >> 16;
src_y = plane->state->src_y >> 16;
src_w = plane->state->src_w >> 16;
src_h = plane->state->src_h >> 16;
dst_x = plane->state->crtc_x;
dst_y = plane->state->crtc_y;
dst_w = plane->state->crtc_w;
dst_h = plane->state->crtc_h;
bpp = drm_format_plane_cpp(format, 0);
cma_obj = drm_fb_cma_get_gem_obj(fb, 0);
paddr = cma_obj->paddr + fb->offsets[0];
paddr += src_y * stride + src_x * bpp / 8;
zx_writel(layer + GL_ADDR, paddr);
zx_writel(layer + GL_SRC_SIZE, GL_SRC_W(src_w) | GL_SRC_H(src_h));
zx_writel(layer + GL_POS_START, GL_POS_X(dst_x) | GL_POS_Y(dst_y));
zx_writel(layer + GL_POS_END,
GL_POS_X(dst_x + dst_w) | GL_POS_Y(dst_y + dst_h));
zx_writel(layer + GL_STRIDE, stride & 0xffff);
fmt = zx_gl_get_fmt(format);
if (fmt >= 0)
zx_writel_mask(layer + GL_CTRL1, GL_DATA_FMT_MASK,
fmt << GL_DATA_FMT_SHIFT);
zx_writel_mask(layer + GL_CTRL2, GL_GLOBAL_ALPHA_MASK,
0xff << GL_GLOBAL_ALPHA_SHIFT);
if (dst_h > 720)
zx_writel_mask(csc + CSC_CTRL0, CSC_COV_MODE_MASK,
CSC_BT709_IMAGE_RGB2YCBCR << CSC_COV_MODE_SHIFT);
else
zx_writel_mask(csc + CSC_CTRL0, CSC_COV_MODE_MASK,
CSC_BT601_IMAGE_RGB2YCBCR << CSC_COV_MODE_SHIFT);
zx_writel_mask(csc + CSC_CTRL0, CSC_WORK_ENABLE, CSC_WORK_ENABLE);
zx_writel_mask(layer + GL_CTRL3, GL_SCALER_BYPASS_MODE,
GL_SCALER_BYPASS_MODE);
zx_gl_rsz_setup(zplane, src_w, src_h, dst_w, dst_h);
zx_writel_mask(hbsc + HBSC_CTRL0, HBSC_CTRL_EN, HBSC_CTRL_EN);
zx_gl_set_update(zplane);
}
static void zx_plane_destroy(struct drm_plane *plane)
{
drm_plane_helper_disable(plane);
drm_plane_cleanup(plane);
}
static void zx_plane_hbsc_init(struct zx_plane *zplane)
{
void __iomem *hbsc = zplane->hbsc;
zx_writel(hbsc + HBSC_SATURATION, 0x200);
zx_writel(hbsc + HBSC_HUE, 0x0);
zx_writel(hbsc + HBSC_BRIGHT, 0x0);
zx_writel(hbsc + HBSC_CONTRAST, 0x200);
zx_writel(hbsc + HBSC_THRESHOLD_COL1, (0x3ac << 16) | 0x40);
zx_writel(hbsc + HBSC_THRESHOLD_COL2, (0x3c0 << 16) | 0x40);
zx_writel(hbsc + HBSC_THRESHOLD_COL3, (0x3c0 << 16) | 0x40);
}
struct drm_plane *zx_plane_init(struct drm_device *drm, struct device *dev,
struct zx_layer_data *data,
enum drm_plane_type type)
{
const struct drm_plane_helper_funcs *helper;
struct zx_plane *zplane;
struct drm_plane *plane;
const uint32_t *formats;
unsigned int format_count;
int ret;
zplane = devm_kzalloc(dev, sizeof(*zplane), GFP_KERNEL);
if (!zplane)
return ERR_PTR(-ENOMEM);
plane = &zplane->plane;
zplane->layer = data->layer;
zplane->hbsc = data->hbsc;
zplane->csc = data->csc;
zplane->rsz = data->rsz;
zx_plane_hbsc_init(zplane);
switch (type) {
case DRM_PLANE_TYPE_PRIMARY:
helper = &zx_gl_plane_helper_funcs;
formats = gl_formats;
format_count = ARRAY_SIZE(gl_formats);
break;
case DRM_PLANE_TYPE_OVERLAY:
break;
default:
return ERR_PTR(-ENODEV);
}
ret = drm_universal_plane_init(drm, plane, VOU_CRTC_MASK,
&zx_plane_funcs, formats, format_count,
type, NULL);
if (ret) {
DRM_DEV_ERROR(dev, "failed to init universal plane: %d\n", ret);
return ERR_PTR(ret);
}
drm_plane_helper_add(plane, helper);
return plane;
}
