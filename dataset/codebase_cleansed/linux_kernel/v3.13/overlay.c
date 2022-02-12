static inline int
sin_mul(int degrees, int factor)
{
if (degrees > 180) {
degrees -= 180;
factor *= -1;
}
return factor * 4 * degrees * (180 - degrees) /
(40500 - degrees * (180 - degrees));
}
static inline int
cos_mul(int degrees, int factor)
{
return sin_mul((degrees + 90) % 360, factor);
}
static int
nv10_update_plane(struct drm_plane *plane, struct drm_crtc *crtc,
struct drm_framebuffer *fb, int crtc_x, int crtc_y,
unsigned int crtc_w, unsigned int crtc_h,
uint32_t src_x, uint32_t src_y,
uint32_t src_w, uint32_t src_h)
{
struct nouveau_device *dev = nouveau_dev(plane->dev);
struct nouveau_plane *nv_plane = (struct nouveau_plane *)plane;
struct nouveau_framebuffer *nv_fb = nouveau_framebuffer(fb);
struct nouveau_crtc *nv_crtc = nouveau_crtc(crtc);
struct nouveau_bo *cur = nv_plane->cur;
bool flip = nv_plane->flip;
int soff = NV_PCRTC0_SIZE * nv_crtc->index;
int soff2 = NV_PCRTC0_SIZE * !nv_crtc->index;
int format, ret;
src_x >>= 16;
src_y >>= 16;
src_w >>= 16;
src_h >>= 16;
format = ALIGN(src_w * 4, 0x100);
if (format > 0xffff)
return -ERANGE;
if (dev->chipset >= 0x30) {
if (crtc_w < (src_w >> 1) || crtc_h < (src_h >> 1))
return -ERANGE;
} else {
if (crtc_w < (src_w >> 3) || crtc_h < (src_h >> 3))
return -ERANGE;
}
ret = nouveau_bo_pin(nv_fb->nvbo, TTM_PL_FLAG_VRAM);
if (ret)
return ret;
nv_plane->cur = nv_fb->nvbo;
nv_mask(dev, NV_PCRTC_ENGINE_CTRL + soff, NV_CRTC_FSEL_OVERLAY, NV_CRTC_FSEL_OVERLAY);
nv_mask(dev, NV_PCRTC_ENGINE_CTRL + soff2, NV_CRTC_FSEL_OVERLAY, 0);
nv_wr32(dev, NV_PVIDEO_BASE(flip), 0);
nv_wr32(dev, NV_PVIDEO_OFFSET_BUFF(flip), nv_fb->nvbo->bo.offset);
nv_wr32(dev, NV_PVIDEO_SIZE_IN(flip), src_h << 16 | src_w);
nv_wr32(dev, NV_PVIDEO_POINT_IN(flip), src_y << 16 | src_x);
nv_wr32(dev, NV_PVIDEO_DS_DX(flip), (src_w << 20) / crtc_w);
nv_wr32(dev, NV_PVIDEO_DT_DY(flip), (src_h << 20) / crtc_h);
nv_wr32(dev, NV_PVIDEO_POINT_OUT(flip), crtc_y << 16 | crtc_x);
nv_wr32(dev, NV_PVIDEO_SIZE_OUT(flip), crtc_h << 16 | crtc_w);
if (fb->pixel_format == DRM_FORMAT_NV12) {
format |= NV_PVIDEO_FORMAT_COLOR_LE_CR8YB8CB8YA8;
format |= NV_PVIDEO_FORMAT_PLANAR;
}
if (nv_plane->iturbt_709)
format |= NV_PVIDEO_FORMAT_MATRIX_ITURBT709;
if (nv_plane->colorkey & (1 << 24))
format |= NV_PVIDEO_FORMAT_DISPLAY_COLOR_KEY;
if (fb->pixel_format == DRM_FORMAT_NV12) {
nv_wr32(dev, NV_PVIDEO_UVPLANE_BASE(flip), 0);
nv_wr32(dev, NV_PVIDEO_UVPLANE_OFFSET_BUFF(flip),
nv_fb->nvbo->bo.offset + fb->offsets[1]);
}
nv_wr32(dev, NV_PVIDEO_FORMAT(flip), format);
nv_wr32(dev, NV_PVIDEO_STOP, 0);
nv_wr32(dev, NV_PVIDEO_BUFFER, flip ? 0x10 : 0x1);
nv_plane->flip = !flip;
if (cur)
nouveau_bo_unpin(cur);
return 0;
}
static int
nv10_disable_plane(struct drm_plane *plane)
{
struct nouveau_device *dev = nouveau_dev(plane->dev);
struct nouveau_plane *nv_plane = (struct nouveau_plane *)plane;
nv_wr32(dev, NV_PVIDEO_STOP, 1);
if (nv_plane->cur) {
nouveau_bo_unpin(nv_plane->cur);
nv_plane->cur = NULL;
}
return 0;
}
static void
nv10_destroy_plane(struct drm_plane *plane)
{
nv10_disable_plane(plane);
drm_plane_cleanup(plane);
kfree(plane);
}
static void
nv10_set_params(struct nouveau_plane *plane)
{
struct nouveau_device *dev = nouveau_dev(plane->base.dev);
u32 luma = (plane->brightness - 512) << 16 | plane->contrast;
u32 chroma = ((sin_mul(plane->hue, plane->saturation) & 0xffff) << 16) |
(cos_mul(plane->hue, plane->saturation) & 0xffff);
u32 format = 0;
nv_wr32(dev, NV_PVIDEO_LUMINANCE(0), luma);
nv_wr32(dev, NV_PVIDEO_LUMINANCE(1), luma);
nv_wr32(dev, NV_PVIDEO_CHROMINANCE(0), chroma);
nv_wr32(dev, NV_PVIDEO_CHROMINANCE(1), chroma);
nv_wr32(dev, NV_PVIDEO_COLOR_KEY, plane->colorkey & 0xffffff);
if (plane->cur) {
if (plane->iturbt_709)
format |= NV_PVIDEO_FORMAT_MATRIX_ITURBT709;
if (plane->colorkey & (1 << 24))
format |= NV_PVIDEO_FORMAT_DISPLAY_COLOR_KEY;
nv_mask(dev, NV_PVIDEO_FORMAT(plane->flip),
NV_PVIDEO_FORMAT_MATRIX_ITURBT709 |
NV_PVIDEO_FORMAT_DISPLAY_COLOR_KEY,
format);
}
}
static int
nv10_set_property(struct drm_plane *plane,
struct drm_property *property,
uint64_t value)
{
struct nouveau_plane *nv_plane = (struct nouveau_plane *)plane;
if (property == nv_plane->props.colorkey)
nv_plane->colorkey = value;
else if (property == nv_plane->props.contrast)
nv_plane->contrast = value;
else if (property == nv_plane->props.brightness)
nv_plane->brightness = value;
else if (property == nv_plane->props.hue)
nv_plane->hue = value;
else if (property == nv_plane->props.saturation)
nv_plane->saturation = value;
else if (property == nv_plane->props.iturbt_709)
nv_plane->iturbt_709 = value;
else
return -EINVAL;
nv10_set_params(nv_plane);
return 0;
}
static void
nv10_overlay_init(struct drm_device *device)
{
struct nouveau_device *dev = nouveau_dev(device);
struct nouveau_plane *plane = kzalloc(sizeof(struct nouveau_plane), GFP_KERNEL);
int num_formats = ARRAY_SIZE(formats);
int ret;
if (!plane)
return;
switch (dev->chipset) {
case 0x10:
case 0x11:
case 0x15:
case 0x1a:
case 0x20:
num_formats = 1;
break;
}
ret = drm_plane_init(device, &plane->base, 3 ,
&nv10_plane_funcs,
formats, num_formats, false);
if (ret)
goto err;
plane->props.colorkey = drm_property_create_range(
device, 0, "colorkey", 0, 0x01ffffff);
plane->props.contrast = drm_property_create_range(
device, 0, "contrast", 0, 8192 - 1);
plane->props.brightness = drm_property_create_range(
device, 0, "brightness", 0, 1024);
plane->props.hue = drm_property_create_range(
device, 0, "hue", 0, 359);
plane->props.saturation = drm_property_create_range(
device, 0, "saturation", 0, 8192 - 1);
plane->props.iturbt_709 = drm_property_create_range(
device, 0, "iturbt_709", 0, 1);
if (!plane->props.colorkey ||
!plane->props.contrast ||
!plane->props.brightness ||
!plane->props.hue ||
!plane->props.saturation ||
!plane->props.iturbt_709)
goto cleanup;
plane->colorkey = 0;
drm_object_attach_property(&plane->base.base,
plane->props.colorkey, plane->colorkey);
plane->contrast = 0x1000;
drm_object_attach_property(&plane->base.base,
plane->props.contrast, plane->contrast);
plane->brightness = 512;
drm_object_attach_property(&plane->base.base,
plane->props.brightness, plane->brightness);
plane->hue = 0;
drm_object_attach_property(&plane->base.base,
plane->props.hue, plane->hue);
plane->saturation = 0x1000;
drm_object_attach_property(&plane->base.base,
plane->props.saturation, plane->saturation);
plane->iturbt_709 = 0;
drm_object_attach_property(&plane->base.base,
plane->props.iturbt_709, plane->iturbt_709);
nv10_set_params(plane);
nv_wr32(dev, NV_PVIDEO_STOP, 1);
return;
cleanup:
drm_plane_cleanup(&plane->base);
err:
kfree(plane);
nv_error(dev, "Failed to create plane\n");
}
void
nouveau_overlay_init(struct drm_device *device)
{
struct nouveau_device *dev = nouveau_dev(device);
if (dev->chipset >= 0x10 && dev->chipset <= 0x40)
nv10_overlay_init(device);
}
