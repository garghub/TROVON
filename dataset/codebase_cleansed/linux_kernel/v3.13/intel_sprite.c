static void
vlv_update_plane(struct drm_plane *dplane, struct drm_crtc *crtc,
struct drm_framebuffer *fb,
struct drm_i915_gem_object *obj, int crtc_x, int crtc_y,
unsigned int crtc_w, unsigned int crtc_h,
uint32_t x, uint32_t y,
uint32_t src_w, uint32_t src_h)
{
struct drm_device *dev = dplane->dev;
struct drm_i915_private *dev_priv = dev->dev_private;
struct intel_plane *intel_plane = to_intel_plane(dplane);
int pipe = intel_plane->pipe;
int plane = intel_plane->plane;
u32 sprctl;
unsigned long sprsurf_offset, linear_offset;
int pixel_size = drm_format_plane_cpp(fb->pixel_format, 0);
sprctl = I915_READ(SPCNTR(pipe, plane));
sprctl &= ~SP_PIXFORMAT_MASK;
sprctl &= ~SP_YUV_BYTE_ORDER_MASK;
sprctl &= ~SP_TILED;
switch (fb->pixel_format) {
case DRM_FORMAT_YUYV:
sprctl |= SP_FORMAT_YUV422 | SP_YUV_ORDER_YUYV;
break;
case DRM_FORMAT_YVYU:
sprctl |= SP_FORMAT_YUV422 | SP_YUV_ORDER_YVYU;
break;
case DRM_FORMAT_UYVY:
sprctl |= SP_FORMAT_YUV422 | SP_YUV_ORDER_UYVY;
break;
case DRM_FORMAT_VYUY:
sprctl |= SP_FORMAT_YUV422 | SP_YUV_ORDER_VYUY;
break;
case DRM_FORMAT_RGB565:
sprctl |= SP_FORMAT_BGR565;
break;
case DRM_FORMAT_XRGB8888:
sprctl |= SP_FORMAT_BGRX8888;
break;
case DRM_FORMAT_ARGB8888:
sprctl |= SP_FORMAT_BGRA8888;
break;
case DRM_FORMAT_XBGR2101010:
sprctl |= SP_FORMAT_RGBX1010102;
break;
case DRM_FORMAT_ABGR2101010:
sprctl |= SP_FORMAT_RGBA1010102;
break;
case DRM_FORMAT_XBGR8888:
sprctl |= SP_FORMAT_RGBX8888;
break;
case DRM_FORMAT_ABGR8888:
sprctl |= SP_FORMAT_RGBA8888;
break;
default:
BUG();
break;
}
if (obj->tiling_mode != I915_TILING_NONE)
sprctl |= SP_TILED;
sprctl |= SP_ENABLE;
intel_update_sprite_watermarks(dplane, crtc, src_w, pixel_size, true,
src_w != crtc_w || src_h != crtc_h);
src_w--;
src_h--;
crtc_w--;
crtc_h--;
I915_WRITE(SPSTRIDE(pipe, plane), fb->pitches[0]);
I915_WRITE(SPPOS(pipe, plane), (crtc_y << 16) | crtc_x);
linear_offset = y * fb->pitches[0] + x * pixel_size;
sprsurf_offset = intel_gen4_compute_page_offset(&x, &y,
obj->tiling_mode,
pixel_size,
fb->pitches[0]);
linear_offset -= sprsurf_offset;
if (obj->tiling_mode != I915_TILING_NONE)
I915_WRITE(SPTILEOFF(pipe, plane), (y << 16) | x);
else
I915_WRITE(SPLINOFF(pipe, plane), linear_offset);
I915_WRITE(SPSIZE(pipe, plane), (crtc_h << 16) | crtc_w);
I915_WRITE(SPCNTR(pipe, plane), sprctl);
I915_MODIFY_DISPBASE(SPSURF(pipe, plane), i915_gem_obj_ggtt_offset(obj) +
sprsurf_offset);
POSTING_READ(SPSURF(pipe, plane));
}
static void
vlv_disable_plane(struct drm_plane *dplane, struct drm_crtc *crtc)
{
struct drm_device *dev = dplane->dev;
struct drm_i915_private *dev_priv = dev->dev_private;
struct intel_plane *intel_plane = to_intel_plane(dplane);
int pipe = intel_plane->pipe;
int plane = intel_plane->plane;
I915_WRITE(SPCNTR(pipe, plane), I915_READ(SPCNTR(pipe, plane)) &
~SP_ENABLE);
I915_MODIFY_DISPBASE(SPSURF(pipe, plane), 0);
POSTING_READ(SPSURF(pipe, plane));
intel_update_sprite_watermarks(dplane, crtc, 0, 0, false, false);
}
static int
vlv_update_colorkey(struct drm_plane *dplane,
struct drm_intel_sprite_colorkey *key)
{
struct drm_device *dev = dplane->dev;
struct drm_i915_private *dev_priv = dev->dev_private;
struct intel_plane *intel_plane = to_intel_plane(dplane);
int pipe = intel_plane->pipe;
int plane = intel_plane->plane;
u32 sprctl;
if (key->flags & I915_SET_COLORKEY_DESTINATION)
return -EINVAL;
I915_WRITE(SPKEYMINVAL(pipe, plane), key->min_value);
I915_WRITE(SPKEYMAXVAL(pipe, plane), key->max_value);
I915_WRITE(SPKEYMSK(pipe, plane), key->channel_mask);
sprctl = I915_READ(SPCNTR(pipe, plane));
sprctl &= ~SP_SOURCE_KEY;
if (key->flags & I915_SET_COLORKEY_SOURCE)
sprctl |= SP_SOURCE_KEY;
I915_WRITE(SPCNTR(pipe, plane), sprctl);
POSTING_READ(SPKEYMSK(pipe, plane));
return 0;
}
static void
vlv_get_colorkey(struct drm_plane *dplane,
struct drm_intel_sprite_colorkey *key)
{
struct drm_device *dev = dplane->dev;
struct drm_i915_private *dev_priv = dev->dev_private;
struct intel_plane *intel_plane = to_intel_plane(dplane);
int pipe = intel_plane->pipe;
int plane = intel_plane->plane;
u32 sprctl;
key->min_value = I915_READ(SPKEYMINVAL(pipe, plane));
key->max_value = I915_READ(SPKEYMAXVAL(pipe, plane));
key->channel_mask = I915_READ(SPKEYMSK(pipe, plane));
sprctl = I915_READ(SPCNTR(pipe, plane));
if (sprctl & SP_SOURCE_KEY)
key->flags = I915_SET_COLORKEY_SOURCE;
else
key->flags = I915_SET_COLORKEY_NONE;
}
static void
ivb_update_plane(struct drm_plane *plane, struct drm_crtc *crtc,
struct drm_framebuffer *fb,
struct drm_i915_gem_object *obj, int crtc_x, int crtc_y,
unsigned int crtc_w, unsigned int crtc_h,
uint32_t x, uint32_t y,
uint32_t src_w, uint32_t src_h)
{
struct drm_device *dev = plane->dev;
struct drm_i915_private *dev_priv = dev->dev_private;
struct intel_plane *intel_plane = to_intel_plane(plane);
int pipe = intel_plane->pipe;
u32 sprctl, sprscale = 0;
unsigned long sprsurf_offset, linear_offset;
int pixel_size = drm_format_plane_cpp(fb->pixel_format, 0);
bool scaling_was_enabled = dev_priv->sprite_scaling_enabled;
sprctl = I915_READ(SPRCTL(pipe));
sprctl &= ~SPRITE_PIXFORMAT_MASK;
sprctl &= ~SPRITE_RGB_ORDER_RGBX;
sprctl &= ~SPRITE_YUV_BYTE_ORDER_MASK;
sprctl &= ~SPRITE_TILED;
switch (fb->pixel_format) {
case DRM_FORMAT_XBGR8888:
sprctl |= SPRITE_FORMAT_RGBX888 | SPRITE_RGB_ORDER_RGBX;
break;
case DRM_FORMAT_XRGB8888:
sprctl |= SPRITE_FORMAT_RGBX888;
break;
case DRM_FORMAT_YUYV:
sprctl |= SPRITE_FORMAT_YUV422 | SPRITE_YUV_ORDER_YUYV;
break;
case DRM_FORMAT_YVYU:
sprctl |= SPRITE_FORMAT_YUV422 | SPRITE_YUV_ORDER_YVYU;
break;
case DRM_FORMAT_UYVY:
sprctl |= SPRITE_FORMAT_YUV422 | SPRITE_YUV_ORDER_UYVY;
break;
case DRM_FORMAT_VYUY:
sprctl |= SPRITE_FORMAT_YUV422 | SPRITE_YUV_ORDER_VYUY;
break;
default:
BUG();
}
if (obj->tiling_mode != I915_TILING_NONE)
sprctl |= SPRITE_TILED;
if (IS_HASWELL(dev) || IS_BROADWELL(dev))
sprctl &= ~SPRITE_TRICKLE_FEED_DISABLE;
else
sprctl |= SPRITE_TRICKLE_FEED_DISABLE;
sprctl |= SPRITE_ENABLE;
if (IS_HASWELL(dev) || IS_BROADWELL(dev))
sprctl |= SPRITE_PIPE_CSC_ENABLE;
intel_update_sprite_watermarks(plane, crtc, src_w, pixel_size, true,
src_w != crtc_w || src_h != crtc_h);
src_w--;
src_h--;
crtc_w--;
crtc_h--;
if (crtc_w != src_w || crtc_h != src_h) {
dev_priv->sprite_scaling_enabled |= 1 << pipe;
if (!scaling_was_enabled) {
intel_update_watermarks(crtc);
intel_wait_for_vblank(dev, pipe);
}
sprscale = SPRITE_SCALE_ENABLE | (src_w << 16) | src_h;
} else
dev_priv->sprite_scaling_enabled &= ~(1 << pipe);
I915_WRITE(SPRSTRIDE(pipe), fb->pitches[0]);
I915_WRITE(SPRPOS(pipe), (crtc_y << 16) | crtc_x);
linear_offset = y * fb->pitches[0] + x * pixel_size;
sprsurf_offset =
intel_gen4_compute_page_offset(&x, &y, obj->tiling_mode,
pixel_size, fb->pitches[0]);
linear_offset -= sprsurf_offset;
if (IS_HASWELL(dev) || IS_BROADWELL(dev))
I915_WRITE(SPROFFSET(pipe), (y << 16) | x);
else if (obj->tiling_mode != I915_TILING_NONE)
I915_WRITE(SPRTILEOFF(pipe), (y << 16) | x);
else
I915_WRITE(SPRLINOFF(pipe), linear_offset);
I915_WRITE(SPRSIZE(pipe), (crtc_h << 16) | crtc_w);
if (intel_plane->can_scale)
I915_WRITE(SPRSCALE(pipe), sprscale);
I915_WRITE(SPRCTL(pipe), sprctl);
I915_MODIFY_DISPBASE(SPRSURF(pipe),
i915_gem_obj_ggtt_offset(obj) + sprsurf_offset);
POSTING_READ(SPRSURF(pipe));
if (scaling_was_enabled && !dev_priv->sprite_scaling_enabled)
intel_update_watermarks(crtc);
}
static void
ivb_disable_plane(struct drm_plane *plane, struct drm_crtc *crtc)
{
struct drm_device *dev = plane->dev;
struct drm_i915_private *dev_priv = dev->dev_private;
struct intel_plane *intel_plane = to_intel_plane(plane);
int pipe = intel_plane->pipe;
bool scaling_was_enabled = dev_priv->sprite_scaling_enabled;
I915_WRITE(SPRCTL(pipe), I915_READ(SPRCTL(pipe)) & ~SPRITE_ENABLE);
if (intel_plane->can_scale)
I915_WRITE(SPRSCALE(pipe), 0);
I915_MODIFY_DISPBASE(SPRSURF(pipe), 0);
POSTING_READ(SPRSURF(pipe));
dev_priv->sprite_scaling_enabled &= ~(1 << pipe);
intel_update_sprite_watermarks(plane, crtc, 0, 0, false, false);
if (scaling_was_enabled && !dev_priv->sprite_scaling_enabled)
intel_update_watermarks(crtc);
}
static int
ivb_update_colorkey(struct drm_plane *plane,
struct drm_intel_sprite_colorkey *key)
{
struct drm_device *dev = plane->dev;
struct drm_i915_private *dev_priv = dev->dev_private;
struct intel_plane *intel_plane;
u32 sprctl;
int ret = 0;
intel_plane = to_intel_plane(plane);
I915_WRITE(SPRKEYVAL(intel_plane->pipe), key->min_value);
I915_WRITE(SPRKEYMAX(intel_plane->pipe), key->max_value);
I915_WRITE(SPRKEYMSK(intel_plane->pipe), key->channel_mask);
sprctl = I915_READ(SPRCTL(intel_plane->pipe));
sprctl &= ~(SPRITE_SOURCE_KEY | SPRITE_DEST_KEY);
if (key->flags & I915_SET_COLORKEY_DESTINATION)
sprctl |= SPRITE_DEST_KEY;
else if (key->flags & I915_SET_COLORKEY_SOURCE)
sprctl |= SPRITE_SOURCE_KEY;
I915_WRITE(SPRCTL(intel_plane->pipe), sprctl);
POSTING_READ(SPRKEYMSK(intel_plane->pipe));
return ret;
}
static void
ivb_get_colorkey(struct drm_plane *plane, struct drm_intel_sprite_colorkey *key)
{
struct drm_device *dev = plane->dev;
struct drm_i915_private *dev_priv = dev->dev_private;
struct intel_plane *intel_plane;
u32 sprctl;
intel_plane = to_intel_plane(plane);
key->min_value = I915_READ(SPRKEYVAL(intel_plane->pipe));
key->max_value = I915_READ(SPRKEYMAX(intel_plane->pipe));
key->channel_mask = I915_READ(SPRKEYMSK(intel_plane->pipe));
key->flags = 0;
sprctl = I915_READ(SPRCTL(intel_plane->pipe));
if (sprctl & SPRITE_DEST_KEY)
key->flags = I915_SET_COLORKEY_DESTINATION;
else if (sprctl & SPRITE_SOURCE_KEY)
key->flags = I915_SET_COLORKEY_SOURCE;
else
key->flags = I915_SET_COLORKEY_NONE;
}
static void
ilk_update_plane(struct drm_plane *plane, struct drm_crtc *crtc,
struct drm_framebuffer *fb,
struct drm_i915_gem_object *obj, int crtc_x, int crtc_y,
unsigned int crtc_w, unsigned int crtc_h,
uint32_t x, uint32_t y,
uint32_t src_w, uint32_t src_h)
{
struct drm_device *dev = plane->dev;
struct drm_i915_private *dev_priv = dev->dev_private;
struct intel_plane *intel_plane = to_intel_plane(plane);
int pipe = intel_plane->pipe;
unsigned long dvssurf_offset, linear_offset;
u32 dvscntr, dvsscale;
int pixel_size = drm_format_plane_cpp(fb->pixel_format, 0);
dvscntr = I915_READ(DVSCNTR(pipe));
dvscntr &= ~DVS_PIXFORMAT_MASK;
dvscntr &= ~DVS_RGB_ORDER_XBGR;
dvscntr &= ~DVS_YUV_BYTE_ORDER_MASK;
dvscntr &= ~DVS_TILED;
switch (fb->pixel_format) {
case DRM_FORMAT_XBGR8888:
dvscntr |= DVS_FORMAT_RGBX888 | DVS_RGB_ORDER_XBGR;
break;
case DRM_FORMAT_XRGB8888:
dvscntr |= DVS_FORMAT_RGBX888;
break;
case DRM_FORMAT_YUYV:
dvscntr |= DVS_FORMAT_YUV422 | DVS_YUV_ORDER_YUYV;
break;
case DRM_FORMAT_YVYU:
dvscntr |= DVS_FORMAT_YUV422 | DVS_YUV_ORDER_YVYU;
break;
case DRM_FORMAT_UYVY:
dvscntr |= DVS_FORMAT_YUV422 | DVS_YUV_ORDER_UYVY;
break;
case DRM_FORMAT_VYUY:
dvscntr |= DVS_FORMAT_YUV422 | DVS_YUV_ORDER_VYUY;
break;
default:
BUG();
}
if (obj->tiling_mode != I915_TILING_NONE)
dvscntr |= DVS_TILED;
if (IS_GEN6(dev))
dvscntr |= DVS_TRICKLE_FEED_DISABLE;
dvscntr |= DVS_ENABLE;
intel_update_sprite_watermarks(plane, crtc, src_w, pixel_size, true,
src_w != crtc_w || src_h != crtc_h);
src_w--;
src_h--;
crtc_w--;
crtc_h--;
dvsscale = 0;
if (IS_GEN5(dev) || crtc_w != src_w || crtc_h != src_h)
dvsscale = DVS_SCALE_ENABLE | (src_w << 16) | src_h;
I915_WRITE(DVSSTRIDE(pipe), fb->pitches[0]);
I915_WRITE(DVSPOS(pipe), (crtc_y << 16) | crtc_x);
linear_offset = y * fb->pitches[0] + x * pixel_size;
dvssurf_offset =
intel_gen4_compute_page_offset(&x, &y, obj->tiling_mode,
pixel_size, fb->pitches[0]);
linear_offset -= dvssurf_offset;
if (obj->tiling_mode != I915_TILING_NONE)
I915_WRITE(DVSTILEOFF(pipe), (y << 16) | x);
else
I915_WRITE(DVSLINOFF(pipe), linear_offset);
I915_WRITE(DVSSIZE(pipe), (crtc_h << 16) | crtc_w);
I915_WRITE(DVSSCALE(pipe), dvsscale);
I915_WRITE(DVSCNTR(pipe), dvscntr);
I915_MODIFY_DISPBASE(DVSSURF(pipe),
i915_gem_obj_ggtt_offset(obj) + dvssurf_offset);
POSTING_READ(DVSSURF(pipe));
}
static void
ilk_disable_plane(struct drm_plane *plane, struct drm_crtc *crtc)
{
struct drm_device *dev = plane->dev;
struct drm_i915_private *dev_priv = dev->dev_private;
struct intel_plane *intel_plane = to_intel_plane(plane);
int pipe = intel_plane->pipe;
I915_WRITE(DVSCNTR(pipe), I915_READ(DVSCNTR(pipe)) & ~DVS_ENABLE);
I915_WRITE(DVSSCALE(pipe), 0);
I915_MODIFY_DISPBASE(DVSSURF(pipe), 0);
POSTING_READ(DVSSURF(pipe));
intel_update_sprite_watermarks(plane, crtc, 0, 0, false, false);
}
static void
intel_enable_primary(struct drm_crtc *crtc)
{
struct drm_device *dev = crtc->dev;
struct drm_i915_private *dev_priv = dev->dev_private;
struct intel_crtc *intel_crtc = to_intel_crtc(crtc);
int reg = DSPCNTR(intel_crtc->plane);
if (intel_crtc->primary_enabled)
return;
intel_crtc->primary_enabled = true;
I915_WRITE(reg, I915_READ(reg) | DISPLAY_PLANE_ENABLE);
intel_flush_primary_plane(dev_priv, intel_crtc->plane);
if (intel_crtc->config.ips_enabled) {
intel_wait_for_vblank(dev, intel_crtc->pipe);
hsw_enable_ips(intel_crtc);
}
mutex_lock(&dev->struct_mutex);
intel_update_fbc(dev);
mutex_unlock(&dev->struct_mutex);
}
static void
intel_disable_primary(struct drm_crtc *crtc)
{
struct drm_device *dev = crtc->dev;
struct drm_i915_private *dev_priv = dev->dev_private;
struct intel_crtc *intel_crtc = to_intel_crtc(crtc);
int reg = DSPCNTR(intel_crtc->plane);
if (!intel_crtc->primary_enabled)
return;
intel_crtc->primary_enabled = false;
mutex_lock(&dev->struct_mutex);
if (dev_priv->fbc.plane == intel_crtc->plane)
intel_disable_fbc(dev);
mutex_unlock(&dev->struct_mutex);
hsw_disable_ips(intel_crtc);
I915_WRITE(reg, I915_READ(reg) & ~DISPLAY_PLANE_ENABLE);
intel_flush_primary_plane(dev_priv, intel_crtc->plane);
}
static int
ilk_update_colorkey(struct drm_plane *plane,
struct drm_intel_sprite_colorkey *key)
{
struct drm_device *dev = plane->dev;
struct drm_i915_private *dev_priv = dev->dev_private;
struct intel_plane *intel_plane;
u32 dvscntr;
int ret = 0;
intel_plane = to_intel_plane(plane);
I915_WRITE(DVSKEYVAL(intel_plane->pipe), key->min_value);
I915_WRITE(DVSKEYMAX(intel_plane->pipe), key->max_value);
I915_WRITE(DVSKEYMSK(intel_plane->pipe), key->channel_mask);
dvscntr = I915_READ(DVSCNTR(intel_plane->pipe));
dvscntr &= ~(DVS_SOURCE_KEY | DVS_DEST_KEY);
if (key->flags & I915_SET_COLORKEY_DESTINATION)
dvscntr |= DVS_DEST_KEY;
else if (key->flags & I915_SET_COLORKEY_SOURCE)
dvscntr |= DVS_SOURCE_KEY;
I915_WRITE(DVSCNTR(intel_plane->pipe), dvscntr);
POSTING_READ(DVSKEYMSK(intel_plane->pipe));
return ret;
}
static void
ilk_get_colorkey(struct drm_plane *plane, struct drm_intel_sprite_colorkey *key)
{
struct drm_device *dev = plane->dev;
struct drm_i915_private *dev_priv = dev->dev_private;
struct intel_plane *intel_plane;
u32 dvscntr;
intel_plane = to_intel_plane(plane);
key->min_value = I915_READ(DVSKEYVAL(intel_plane->pipe));
key->max_value = I915_READ(DVSKEYMAX(intel_plane->pipe));
key->channel_mask = I915_READ(DVSKEYMSK(intel_plane->pipe));
key->flags = 0;
dvscntr = I915_READ(DVSCNTR(intel_plane->pipe));
if (dvscntr & DVS_DEST_KEY)
key->flags = I915_SET_COLORKEY_DESTINATION;
else if (dvscntr & DVS_SOURCE_KEY)
key->flags = I915_SET_COLORKEY_SOURCE;
else
key->flags = I915_SET_COLORKEY_NONE;
}
static bool
format_is_yuv(uint32_t format)
{
switch (format) {
case DRM_FORMAT_YUYV:
case DRM_FORMAT_UYVY:
case DRM_FORMAT_VYUY:
case DRM_FORMAT_YVYU:
return true;
default:
return false;
}
}
static int
intel_update_plane(struct drm_plane *plane, struct drm_crtc *crtc,
struct drm_framebuffer *fb, int crtc_x, int crtc_y,
unsigned int crtc_w, unsigned int crtc_h,
uint32_t src_x, uint32_t src_y,
uint32_t src_w, uint32_t src_h)
{
struct drm_device *dev = plane->dev;
struct intel_crtc *intel_crtc = to_intel_crtc(crtc);
struct intel_plane *intel_plane = to_intel_plane(plane);
struct intel_framebuffer *intel_fb = to_intel_framebuffer(fb);
struct drm_i915_gem_object *obj = intel_fb->obj;
struct drm_i915_gem_object *old_obj = intel_plane->obj;
int ret;
bool disable_primary = false;
bool visible;
int hscale, vscale;
int max_scale, min_scale;
int pixel_size = drm_format_plane_cpp(fb->pixel_format, 0);
struct drm_rect src = {
.x1 = src_x,
.x2 = src_x + src_w,
.y1 = src_y,
.y2 = src_y + src_h,
};
struct drm_rect dst = {
.x1 = crtc_x,
.x2 = crtc_x + crtc_w,
.y1 = crtc_y,
.y2 = crtc_y + crtc_h,
};
const struct drm_rect clip = {
.x2 = intel_crtc->active ? intel_crtc->config.pipe_src_w : 0,
.y2 = intel_crtc->active ? intel_crtc->config.pipe_src_h : 0,
};
const struct {
int crtc_x, crtc_y;
unsigned int crtc_w, crtc_h;
uint32_t src_x, src_y, src_w, src_h;
} orig = {
.crtc_x = crtc_x,
.crtc_y = crtc_y,
.crtc_w = crtc_w,
.crtc_h = crtc_h,
.src_x = src_x,
.src_y = src_y,
.src_w = src_w,
.src_h = src_h,
};
if (intel_plane->pipe != intel_crtc->pipe) {
DRM_DEBUG_KMS("Wrong plane <-> crtc mapping\n");
return -EINVAL;
}
if (fb->width < 3 || fb->height < 3 || fb->pitches[0] > 16384) {
DRM_DEBUG_KMS("Unsuitable framebuffer for plane\n");
return -EINVAL;
}
switch (obj->tiling_mode) {
case I915_TILING_NONE:
case I915_TILING_X:
break;
default:
DRM_DEBUG_KMS("Unsupported tiling mode\n");
return -EINVAL;
}
max_scale = intel_plane->max_downscale << 16;
min_scale = intel_plane->can_scale ? 1 : (1 << 16);
hscale = drm_rect_calc_hscale_relaxed(&src, &dst, min_scale, max_scale);
BUG_ON(hscale < 0);
vscale = drm_rect_calc_vscale_relaxed(&src, &dst, min_scale, max_scale);
BUG_ON(vscale < 0);
visible = drm_rect_clip_scaled(&src, &dst, &clip, hscale, vscale);
crtc_x = dst.x1;
crtc_y = dst.y1;
crtc_w = drm_rect_width(&dst);
crtc_h = drm_rect_height(&dst);
if (visible) {
hscale = drm_rect_calc_hscale(&src, &dst, min_scale, max_scale);
if (hscale < 0) {
DRM_DEBUG_KMS("Horizontal scaling factor out of limits\n");
drm_rect_debug_print(&src, true);
drm_rect_debug_print(&dst, false);
return hscale;
}
vscale = drm_rect_calc_vscale(&src, &dst, min_scale, max_scale);
if (vscale < 0) {
DRM_DEBUG_KMS("Vertical scaling factor out of limits\n");
drm_rect_debug_print(&src, true);
drm_rect_debug_print(&dst, false);
return vscale;
}
drm_rect_adjust_size(&src,
drm_rect_width(&dst) * hscale - drm_rect_width(&src),
drm_rect_height(&dst) * vscale - drm_rect_height(&src));
WARN_ON(src.x1 < (int) src_x ||
src.y1 < (int) src_y ||
src.x2 > (int) (src_x + src_w) ||
src.y2 > (int) (src_y + src_h));
src_x = src.x1 >> 16;
src_w = drm_rect_width(&src) >> 16;
src_y = src.y1 >> 16;
src_h = drm_rect_height(&src) >> 16;
if (format_is_yuv(fb->pixel_format)) {
src_x &= ~1;
src_w &= ~1;
if (!intel_plane->can_scale)
crtc_w &= ~1;
if (crtc_w == 0)
visible = false;
}
}
if (visible && (src_w != crtc_w || src_h != crtc_h)) {
unsigned int width_bytes;
WARN_ON(!intel_plane->can_scale);
if (crtc_w < 3 || crtc_h < 3)
visible = false;
if (src_w < 3 || src_h < 3)
visible = false;
width_bytes = ((src_x * pixel_size) & 63) + src_w * pixel_size;
if (src_w > 2048 || src_h > 2048 ||
width_bytes > 4096 || fb->pitches[0] > 4096) {
DRM_DEBUG_KMS("Source dimensions exceed hardware limits\n");
return -EINVAL;
}
}
dst.x1 = crtc_x;
dst.x2 = crtc_x + crtc_w;
dst.y1 = crtc_y;
dst.y2 = crtc_y + crtc_h;
disable_primary = drm_rect_equals(&dst, &clip);
WARN_ON(disable_primary && !visible && intel_crtc->active);
mutex_lock(&dev->struct_mutex);
ret = intel_pin_and_fence_fb_obj(dev, obj, NULL);
mutex_unlock(&dev->struct_mutex);
if (ret)
return ret;
intel_plane->crtc_x = orig.crtc_x;
intel_plane->crtc_y = orig.crtc_y;
intel_plane->crtc_w = orig.crtc_w;
intel_plane->crtc_h = orig.crtc_h;
intel_plane->src_x = orig.src_x;
intel_plane->src_y = orig.src_y;
intel_plane->src_w = orig.src_w;
intel_plane->src_h = orig.src_h;
intel_plane->obj = obj;
if (intel_crtc->active) {
if (!disable_primary)
intel_enable_primary(crtc);
if (visible)
intel_plane->update_plane(plane, crtc, fb, obj,
crtc_x, crtc_y, crtc_w, crtc_h,
src_x, src_y, src_w, src_h);
else
intel_plane->disable_plane(plane, crtc);
if (disable_primary)
intel_disable_primary(crtc);
}
if (old_obj) {
if (old_obj != obj && intel_crtc->active)
intel_wait_for_vblank(dev, intel_crtc->pipe);
mutex_lock(&dev->struct_mutex);
intel_unpin_fb_obj(old_obj);
mutex_unlock(&dev->struct_mutex);
}
return 0;
}
static int
intel_disable_plane(struct drm_plane *plane)
{
struct drm_device *dev = plane->dev;
struct intel_plane *intel_plane = to_intel_plane(plane);
struct intel_crtc *intel_crtc;
if (!plane->fb)
return 0;
if (WARN_ON(!plane->crtc))
return -EINVAL;
intel_crtc = to_intel_crtc(plane->crtc);
if (intel_crtc->active) {
intel_enable_primary(plane->crtc);
intel_plane->disable_plane(plane, plane->crtc);
}
if (intel_plane->obj) {
if (intel_crtc->active)
intel_wait_for_vblank(dev, intel_plane->pipe);
mutex_lock(&dev->struct_mutex);
intel_unpin_fb_obj(intel_plane->obj);
mutex_unlock(&dev->struct_mutex);
intel_plane->obj = NULL;
}
return 0;
}
static void intel_destroy_plane(struct drm_plane *plane)
{
struct intel_plane *intel_plane = to_intel_plane(plane);
intel_disable_plane(plane);
drm_plane_cleanup(plane);
kfree(intel_plane);
}
int intel_sprite_set_colorkey(struct drm_device *dev, void *data,
struct drm_file *file_priv)
{
struct drm_intel_sprite_colorkey *set = data;
struct drm_mode_object *obj;
struct drm_plane *plane;
struct intel_plane *intel_plane;
int ret = 0;
if (!drm_core_check_feature(dev, DRIVER_MODESET))
return -ENODEV;
if ((set->flags & (I915_SET_COLORKEY_DESTINATION | I915_SET_COLORKEY_SOURCE)) == (I915_SET_COLORKEY_DESTINATION | I915_SET_COLORKEY_SOURCE))
return -EINVAL;
drm_modeset_lock_all(dev);
obj = drm_mode_object_find(dev, set->plane_id, DRM_MODE_OBJECT_PLANE);
if (!obj) {
ret = -ENOENT;
goto out_unlock;
}
plane = obj_to_plane(obj);
intel_plane = to_intel_plane(plane);
ret = intel_plane->update_colorkey(plane, set);
out_unlock:
drm_modeset_unlock_all(dev);
return ret;
}
int intel_sprite_get_colorkey(struct drm_device *dev, void *data,
struct drm_file *file_priv)
{
struct drm_intel_sprite_colorkey *get = data;
struct drm_mode_object *obj;
struct drm_plane *plane;
struct intel_plane *intel_plane;
int ret = 0;
if (!drm_core_check_feature(dev, DRIVER_MODESET))
return -ENODEV;
drm_modeset_lock_all(dev);
obj = drm_mode_object_find(dev, get->plane_id, DRM_MODE_OBJECT_PLANE);
if (!obj) {
ret = -ENOENT;
goto out_unlock;
}
plane = obj_to_plane(obj);
intel_plane = to_intel_plane(plane);
intel_plane->get_colorkey(plane, get);
out_unlock:
drm_modeset_unlock_all(dev);
return ret;
}
void intel_plane_restore(struct drm_plane *plane)
{
struct intel_plane *intel_plane = to_intel_plane(plane);
if (!plane->crtc || !plane->fb)
return;
intel_update_plane(plane, plane->crtc, plane->fb,
intel_plane->crtc_x, intel_plane->crtc_y,
intel_plane->crtc_w, intel_plane->crtc_h,
intel_plane->src_x, intel_plane->src_y,
intel_plane->src_w, intel_plane->src_h);
}
void intel_plane_disable(struct drm_plane *plane)
{
if (!plane->crtc || !plane->fb)
return;
intel_disable_plane(plane);
}
int
intel_plane_init(struct drm_device *dev, enum pipe pipe, int plane)
{
struct intel_plane *intel_plane;
unsigned long possible_crtcs;
const uint32_t *plane_formats;
int num_plane_formats;
int ret;
if (INTEL_INFO(dev)->gen < 5)
return -ENODEV;
intel_plane = kzalloc(sizeof(*intel_plane), GFP_KERNEL);
if (!intel_plane)
return -ENOMEM;
switch (INTEL_INFO(dev)->gen) {
case 5:
case 6:
intel_plane->can_scale = true;
intel_plane->max_downscale = 16;
intel_plane->update_plane = ilk_update_plane;
intel_plane->disable_plane = ilk_disable_plane;
intel_plane->update_colorkey = ilk_update_colorkey;
intel_plane->get_colorkey = ilk_get_colorkey;
if (IS_GEN6(dev)) {
plane_formats = snb_plane_formats;
num_plane_formats = ARRAY_SIZE(snb_plane_formats);
} else {
plane_formats = ilk_plane_formats;
num_plane_formats = ARRAY_SIZE(ilk_plane_formats);
}
break;
case 7:
case 8:
if (IS_IVYBRIDGE(dev)) {
intel_plane->can_scale = true;
intel_plane->max_downscale = 2;
} else {
intel_plane->can_scale = false;
intel_plane->max_downscale = 1;
}
if (IS_VALLEYVIEW(dev)) {
intel_plane->update_plane = vlv_update_plane;
intel_plane->disable_plane = vlv_disable_plane;
intel_plane->update_colorkey = vlv_update_colorkey;
intel_plane->get_colorkey = vlv_get_colorkey;
plane_formats = vlv_plane_formats;
num_plane_formats = ARRAY_SIZE(vlv_plane_formats);
} else {
intel_plane->update_plane = ivb_update_plane;
intel_plane->disable_plane = ivb_disable_plane;
intel_plane->update_colorkey = ivb_update_colorkey;
intel_plane->get_colorkey = ivb_get_colorkey;
plane_formats = snb_plane_formats;
num_plane_formats = ARRAY_SIZE(snb_plane_formats);
}
break;
default:
kfree(intel_plane);
return -ENODEV;
}
intel_plane->pipe = pipe;
intel_plane->plane = plane;
possible_crtcs = (1 << pipe);
ret = drm_plane_init(dev, &intel_plane->base, possible_crtcs,
&intel_plane_funcs,
plane_formats, num_plane_formats,
false);
if (ret)
kfree(intel_plane);
return ret;
}
