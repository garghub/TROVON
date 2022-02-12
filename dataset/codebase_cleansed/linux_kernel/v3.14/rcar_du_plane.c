static inline struct rcar_du_plane *to_rcar_plane(struct drm_plane *plane)
{
return container_of(plane, struct rcar_du_kms_plane, plane)->hwplane;
}
static u32 rcar_du_plane_read(struct rcar_du_group *rgrp,
unsigned int index, u32 reg)
{
return rcar_du_read(rgrp->dev,
rgrp->mmio_offset + index * PLANE_OFF + reg);
}
static void rcar_du_plane_write(struct rcar_du_group *rgrp,
unsigned int index, u32 reg, u32 data)
{
rcar_du_write(rgrp->dev, rgrp->mmio_offset + index * PLANE_OFF + reg,
data);
}
int rcar_du_plane_reserve(struct rcar_du_plane *plane,
const struct rcar_du_format_info *format)
{
struct rcar_du_group *rgrp = plane->group;
unsigned int i;
int ret = -EBUSY;
mutex_lock(&rgrp->planes.lock);
for (i = 0; i < ARRAY_SIZE(rgrp->planes.planes); ++i) {
if (!(rgrp->planes.free & (1 << i)))
continue;
if (format->planes == 1 ||
rgrp->planes.free & (1 << ((i + 1) % 8)))
break;
}
if (i == ARRAY_SIZE(rgrp->planes.planes))
goto done;
rgrp->planes.free &= ~(1 << i);
if (format->planes == 2)
rgrp->planes.free &= ~(1 << ((i + 1) % 8));
plane->hwindex = i;
ret = 0;
done:
mutex_unlock(&rgrp->planes.lock);
return ret;
}
void rcar_du_plane_release(struct rcar_du_plane *plane)
{
struct rcar_du_group *rgrp = plane->group;
if (plane->hwindex == -1)
return;
mutex_lock(&rgrp->planes.lock);
rgrp->planes.free |= 1 << plane->hwindex;
if (plane->format->planes == 2)
rgrp->planes.free |= 1 << ((plane->hwindex + 1) % 8);
mutex_unlock(&rgrp->planes.lock);
plane->hwindex = -1;
}
void rcar_du_plane_update_base(struct rcar_du_plane *plane)
{
struct rcar_du_group *rgrp = plane->group;
unsigned int index = plane->hwindex;
u32 mwr;
if (plane->format->planes == 2)
mwr = plane->pitch;
else
mwr = plane->pitch * 8 / plane->format->bpp;
rcar_du_plane_write(rgrp, index, PnMWR, mwr);
rcar_du_plane_write(rgrp, index, PnSPXR, plane->src_x);
rcar_du_plane_write(rgrp, index, PnSPYR, plane->src_y *
(plane->format->bpp == 32 ? 2 : 1));
rcar_du_plane_write(rgrp, index, PnDSA0R, plane->dma[0]);
if (plane->format->planes == 2) {
index = (index + 1) % 8;
rcar_du_plane_write(rgrp, index, PnSPXR, plane->src_x);
rcar_du_plane_write(rgrp, index, PnSPYR, plane->src_y *
(plane->format->bpp == 16 ? 2 : 1) / 2);
rcar_du_plane_write(rgrp, index, PnDSA0R, plane->dma[1]);
}
}
void rcar_du_plane_compute_base(struct rcar_du_plane *plane,
struct drm_framebuffer *fb)
{
struct drm_gem_cma_object *gem;
plane->pitch = fb->pitches[0];
gem = drm_fb_cma_get_gem_obj(fb, 0);
plane->dma[0] = gem->paddr + fb->offsets[0];
if (plane->format->planes == 2) {
gem = drm_fb_cma_get_gem_obj(fb, 1);
plane->dma[1] = gem->paddr + fb->offsets[1];
}
}
static void rcar_du_plane_setup_mode(struct rcar_du_plane *plane,
unsigned int index)
{
struct rcar_du_group *rgrp = plane->group;
u32 colorkey;
u32 pnmr;
if (plane->format->fourcc != DRM_FORMAT_XRGB1555)
rcar_du_plane_write(rgrp, index, PnALPHAR, PnALPHAR_ABIT_0);
else
rcar_du_plane_write(rgrp, index, PnALPHAR,
PnALPHAR_ABIT_X | plane->alpha);
pnmr = PnMR_BM_MD | plane->format->pnmr;
if ((plane->colorkey & RCAR_DU_COLORKEY_MASK) == RCAR_DU_COLORKEY_NONE)
pnmr |= PnMR_SPIM_TP_OFF;
if (plane->format->fourcc == DRM_FORMAT_YUYV)
pnmr |= PnMR_YCDF_YUYV;
rcar_du_plane_write(rgrp, index, PnMR, pnmr);
switch (plane->format->fourcc) {
case DRM_FORMAT_RGB565:
colorkey = ((plane->colorkey & 0xf80000) >> 8)
| ((plane->colorkey & 0x00fc00) >> 5)
| ((plane->colorkey & 0x0000f8) >> 3);
rcar_du_plane_write(rgrp, index, PnTC2R, colorkey);
break;
case DRM_FORMAT_ARGB1555:
case DRM_FORMAT_XRGB1555:
colorkey = ((plane->colorkey & 0xf80000) >> 9)
| ((plane->colorkey & 0x00f800) >> 6)
| ((plane->colorkey & 0x0000f8) >> 3);
rcar_du_plane_write(rgrp, index, PnTC2R, colorkey);
break;
case DRM_FORMAT_XRGB8888:
case DRM_FORMAT_ARGB8888:
rcar_du_plane_write(rgrp, index, PnTC3R,
PnTC3R_CODE | (plane->colorkey & 0xffffff));
break;
}
}
static void __rcar_du_plane_setup(struct rcar_du_plane *plane,
unsigned int index)
{
struct rcar_du_group *rgrp = plane->group;
u32 ddcr2 = PnDDCR2_CODE;
u32 ddcr4;
ddcr4 = rcar_du_plane_read(rgrp, index, PnDDCR4);
ddcr4 &= ~PnDDCR4_EDF_MASK;
ddcr4 |= plane->format->edf | PnDDCR4_CODE;
rcar_du_plane_setup_mode(plane, index);
if (plane->format->planes == 2) {
if (plane->hwindex != index) {
if (plane->format->fourcc == DRM_FORMAT_NV12 ||
plane->format->fourcc == DRM_FORMAT_NV21)
ddcr2 |= PnDDCR2_Y420;
if (plane->format->fourcc == DRM_FORMAT_NV21)
ddcr2 |= PnDDCR2_NV21;
ddcr2 |= PnDDCR2_DIVU;
} else {
ddcr2 |= PnDDCR2_DIVY;
}
}
rcar_du_plane_write(rgrp, index, PnDDCR2, ddcr2);
rcar_du_plane_write(rgrp, index, PnDDCR4, ddcr4);
rcar_du_plane_write(rgrp, index, PnDSXR, plane->width);
rcar_du_plane_write(rgrp, index, PnDSYR, plane->height);
rcar_du_plane_write(rgrp, index, PnDPXR, plane->dst_x);
rcar_du_plane_write(rgrp, index, PnDPYR, plane->dst_y);
rcar_du_plane_write(rgrp, index, PnWASPR, 0);
rcar_du_plane_write(rgrp, index, PnWAMWR, 4095);
rcar_du_plane_write(rgrp, index, PnBTR, 0);
rcar_du_plane_write(rgrp, index, PnMLR, 0);
}
void rcar_du_plane_setup(struct rcar_du_plane *plane)
{
__rcar_du_plane_setup(plane, plane->hwindex);
if (plane->format->planes == 2)
__rcar_du_plane_setup(plane, (plane->hwindex + 1) % 8);
rcar_du_plane_update_base(plane);
}
static int
rcar_du_plane_update(struct drm_plane *plane, struct drm_crtc *crtc,
struct drm_framebuffer *fb, int crtc_x, int crtc_y,
unsigned int crtc_w, unsigned int crtc_h,
uint32_t src_x, uint32_t src_y,
uint32_t src_w, uint32_t src_h)
{
struct rcar_du_plane *rplane = to_rcar_plane(plane);
struct rcar_du_device *rcdu = rplane->group->dev;
const struct rcar_du_format_info *format;
unsigned int nplanes;
int ret;
format = rcar_du_format_info(fb->pixel_format);
if (format == NULL) {
dev_dbg(rcdu->dev, "%s: unsupported format %08x\n", __func__,
fb->pixel_format);
return -EINVAL;
}
if (src_w >> 16 != crtc_w || src_h >> 16 != crtc_h) {
dev_dbg(rcdu->dev, "%s: scaling not supported\n", __func__);
return -EINVAL;
}
nplanes = rplane->format ? rplane->format->planes : 0;
if (format->planes != nplanes) {
rcar_du_plane_release(rplane);
ret = rcar_du_plane_reserve(rplane, format);
if (ret < 0)
return ret;
}
rplane->crtc = crtc;
rplane->format = format;
rplane->src_x = src_x >> 16;
rplane->src_y = src_y >> 16;
rplane->dst_x = crtc_x;
rplane->dst_y = crtc_y;
rplane->width = crtc_w;
rplane->height = crtc_h;
rcar_du_plane_compute_base(rplane, fb);
rcar_du_plane_setup(rplane);
mutex_lock(&rplane->group->planes.lock);
rplane->enabled = true;
rcar_du_crtc_update_planes(rplane->crtc);
mutex_unlock(&rplane->group->planes.lock);
return 0;
}
static int rcar_du_plane_disable(struct drm_plane *plane)
{
struct rcar_du_plane *rplane = to_rcar_plane(plane);
if (!rplane->enabled)
return 0;
mutex_lock(&rplane->group->planes.lock);
rplane->enabled = false;
rcar_du_crtc_update_planes(rplane->crtc);
mutex_unlock(&rplane->group->planes.lock);
rcar_du_plane_release(rplane);
rplane->crtc = NULL;
rplane->format = NULL;
return 0;
}
static void rcar_du_plane_set_alpha(struct rcar_du_plane *plane, u32 alpha)
{
if (plane->alpha == alpha)
return;
plane->alpha = alpha;
if (!plane->enabled || plane->format->fourcc != DRM_FORMAT_XRGB1555)
return;
rcar_du_plane_setup_mode(plane, plane->hwindex);
}
static void rcar_du_plane_set_colorkey(struct rcar_du_plane *plane,
u32 colorkey)
{
if (plane->colorkey == colorkey)
return;
plane->colorkey = colorkey;
if (!plane->enabled)
return;
rcar_du_plane_setup_mode(plane, plane->hwindex);
}
static void rcar_du_plane_set_zpos(struct rcar_du_plane *plane,
unsigned int zpos)
{
mutex_lock(&plane->group->planes.lock);
if (plane->zpos == zpos)
goto done;
plane->zpos = zpos;
if (!plane->enabled)
goto done;
rcar_du_crtc_update_planes(plane->crtc);
done:
mutex_unlock(&plane->group->planes.lock);
}
static int rcar_du_plane_set_property(struct drm_plane *plane,
struct drm_property *property,
uint64_t value)
{
struct rcar_du_plane *rplane = to_rcar_plane(plane);
struct rcar_du_group *rgrp = rplane->group;
if (property == rgrp->planes.alpha)
rcar_du_plane_set_alpha(rplane, value);
else if (property == rgrp->planes.colorkey)
rcar_du_plane_set_colorkey(rplane, value);
else if (property == rgrp->planes.zpos)
rcar_du_plane_set_zpos(rplane, value);
else
return -EINVAL;
return 0;
}
int rcar_du_planes_init(struct rcar_du_group *rgrp)
{
struct rcar_du_planes *planes = &rgrp->planes;
struct rcar_du_device *rcdu = rgrp->dev;
unsigned int i;
mutex_init(&planes->lock);
planes->free = 0xff;
planes->alpha =
drm_property_create_range(rcdu->ddev, 0, "alpha", 0, 255);
if (planes->alpha == NULL)
return -ENOMEM;
planes->colorkey =
drm_property_create_range(rcdu->ddev, 0, "colorkey",
0, 0x01ffffff);
if (planes->colorkey == NULL)
return -ENOMEM;
planes->zpos =
drm_property_create_range(rcdu->ddev, 0, "zpos", 1, 7);
if (planes->zpos == NULL)
return -ENOMEM;
for (i = 0; i < ARRAY_SIZE(planes->planes); ++i) {
struct rcar_du_plane *plane = &planes->planes[i];
plane->group = rgrp;
plane->hwindex = -1;
plane->alpha = 255;
plane->colorkey = RCAR_DU_COLORKEY_NONE;
plane->zpos = 0;
}
return 0;
}
int rcar_du_planes_register(struct rcar_du_group *rgrp)
{
struct rcar_du_planes *planes = &rgrp->planes;
struct rcar_du_device *rcdu = rgrp->dev;
unsigned int crtcs;
unsigned int i;
int ret;
crtcs = ((1 << rcdu->num_crtcs) - 1) & (3 << (2 * rgrp->index));
for (i = 0; i < RCAR_DU_NUM_KMS_PLANES; ++i) {
struct rcar_du_kms_plane *plane;
plane = devm_kzalloc(rcdu->dev, sizeof(*plane), GFP_KERNEL);
if (plane == NULL)
return -ENOMEM;
plane->hwplane = &planes->planes[i + 2];
plane->hwplane->zpos = 1;
ret = drm_plane_init(rcdu->ddev, &plane->plane, crtcs,
&rcar_du_plane_funcs, formats,
ARRAY_SIZE(formats), false);
if (ret < 0)
return ret;
drm_object_attach_property(&plane->plane.base,
planes->alpha, 255);
drm_object_attach_property(&plane->plane.base,
planes->colorkey,
RCAR_DU_COLORKEY_NONE);
drm_object_attach_property(&plane->plane.base,
planes->zpos, 1);
}
return 0;
}
