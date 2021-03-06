static void
ivb_update_plane(struct drm_plane *plane, struct drm_framebuffer *fb,
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
int pixel_size;
sprctl = I915_READ(SPRCTL(pipe));
sprctl &= ~SPRITE_PIXFORMAT_MASK;
sprctl &= ~SPRITE_RGB_ORDER_RGBX;
sprctl &= ~SPRITE_YUV_BYTE_ORDER_MASK;
switch (fb->pixel_format) {
case DRM_FORMAT_XBGR8888:
sprctl |= SPRITE_FORMAT_RGBX888;
pixel_size = 4;
break;
case DRM_FORMAT_XRGB8888:
sprctl |= SPRITE_FORMAT_RGBX888 | SPRITE_RGB_ORDER_RGBX;
pixel_size = 4;
break;
case DRM_FORMAT_YUYV:
sprctl |= SPRITE_FORMAT_YUV422 | SPRITE_YUV_ORDER_YUYV;
pixel_size = 2;
break;
case DRM_FORMAT_YVYU:
sprctl |= SPRITE_FORMAT_YUV422 | SPRITE_YUV_ORDER_YVYU;
pixel_size = 2;
break;
case DRM_FORMAT_UYVY:
sprctl |= SPRITE_FORMAT_YUV422 | SPRITE_YUV_ORDER_UYVY;
pixel_size = 2;
break;
case DRM_FORMAT_VYUY:
sprctl |= SPRITE_FORMAT_YUV422 | SPRITE_YUV_ORDER_VYUY;
pixel_size = 2;
break;
default:
DRM_DEBUG_DRIVER("bad pixel format, assuming RGBX888\n");
sprctl |= DVS_FORMAT_RGBX888;
pixel_size = 4;
break;
}
if (obj->tiling_mode != I915_TILING_NONE)
sprctl |= SPRITE_TILED;
sprctl |= SPRITE_TRICKLE_FEED_DISABLE;
sprctl |= SPRITE_ENABLE;
src_w--;
src_h--;
crtc_w--;
crtc_h--;
intel_update_sprite_watermarks(dev, pipe, crtc_w, pixel_size);
if (crtc_w != src_w || crtc_h != src_h) {
if (!dev_priv->sprite_scaling_enabled) {
dev_priv->sprite_scaling_enabled = true;
intel_update_watermarks(dev);
intel_wait_for_vblank(dev, pipe);
}
sprscale = SPRITE_SCALE_ENABLE | (src_w << 16) | src_h;
} else {
if (dev_priv->sprite_scaling_enabled) {
dev_priv->sprite_scaling_enabled = false;
intel_update_watermarks(dev);
}
}
I915_WRITE(SPRSTRIDE(pipe), fb->pitches[0]);
I915_WRITE(SPRPOS(pipe), (crtc_y << 16) | crtc_x);
if (obj->tiling_mode != I915_TILING_NONE) {
I915_WRITE(SPRTILEOFF(pipe), (y << 16) | x);
} else {
unsigned long offset;
offset = y * fb->pitches[0] + x * (fb->bits_per_pixel / 8);
I915_WRITE(SPRLINOFF(pipe), offset);
}
I915_WRITE(SPRSIZE(pipe), (crtc_h << 16) | crtc_w);
I915_WRITE(SPRSCALE(pipe), sprscale);
I915_WRITE(SPRCTL(pipe), sprctl);
I915_MODIFY_DISPBASE(SPRSURF(pipe), obj->gtt_offset);
POSTING_READ(SPRSURF(pipe));
}
static void
ivb_disable_plane(struct drm_plane *plane)
{
struct drm_device *dev = plane->dev;
struct drm_i915_private *dev_priv = dev->dev_private;
struct intel_plane *intel_plane = to_intel_plane(plane);
int pipe = intel_plane->pipe;
I915_WRITE(SPRCTL(pipe), I915_READ(SPRCTL(pipe)) & ~SPRITE_ENABLE);
I915_WRITE(SPRSCALE(pipe), 0);
I915_MODIFY_DISPBASE(SPRSURF(pipe), 0);
POSTING_READ(SPRSURF(pipe));
dev_priv->sprite_scaling_enabled = false;
intel_update_watermarks(dev);
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
ilk_update_plane(struct drm_plane *plane, struct drm_framebuffer *fb,
struct drm_i915_gem_object *obj, int crtc_x, int crtc_y,
unsigned int crtc_w, unsigned int crtc_h,
uint32_t x, uint32_t y,
uint32_t src_w, uint32_t src_h)
{
struct drm_device *dev = plane->dev;
struct drm_i915_private *dev_priv = dev->dev_private;
struct intel_plane *intel_plane = to_intel_plane(plane);
int pipe = intel_plane->pipe, pixel_size;
u32 dvscntr, dvsscale;
dvscntr = I915_READ(DVSCNTR(pipe));
dvscntr &= ~DVS_PIXFORMAT_MASK;
dvscntr &= ~DVS_RGB_ORDER_XBGR;
dvscntr &= ~DVS_YUV_BYTE_ORDER_MASK;
switch (fb->pixel_format) {
case DRM_FORMAT_XBGR8888:
dvscntr |= DVS_FORMAT_RGBX888 | DVS_RGB_ORDER_XBGR;
pixel_size = 4;
break;
case DRM_FORMAT_XRGB8888:
dvscntr |= DVS_FORMAT_RGBX888;
pixel_size = 4;
break;
case DRM_FORMAT_YUYV:
dvscntr |= DVS_FORMAT_YUV422 | DVS_YUV_ORDER_YUYV;
pixel_size = 2;
break;
case DRM_FORMAT_YVYU:
dvscntr |= DVS_FORMAT_YUV422 | DVS_YUV_ORDER_YVYU;
pixel_size = 2;
break;
case DRM_FORMAT_UYVY:
dvscntr |= DVS_FORMAT_YUV422 | DVS_YUV_ORDER_UYVY;
pixel_size = 2;
break;
case DRM_FORMAT_VYUY:
dvscntr |= DVS_FORMAT_YUV422 | DVS_YUV_ORDER_VYUY;
pixel_size = 2;
break;
default:
DRM_DEBUG_DRIVER("bad pixel format, assuming RGBX888\n");
dvscntr |= DVS_FORMAT_RGBX888;
pixel_size = 4;
break;
}
if (obj->tiling_mode != I915_TILING_NONE)
dvscntr |= DVS_TILED;
if (IS_GEN6(dev))
dvscntr |= DVS_TRICKLE_FEED_DISABLE;
dvscntr |= DVS_ENABLE;
src_w--;
src_h--;
crtc_w--;
crtc_h--;
intel_update_sprite_watermarks(dev, pipe, crtc_w, pixel_size);
dvsscale = 0;
if (IS_GEN5(dev) || crtc_w != src_w || crtc_h != src_h)
dvsscale = DVS_SCALE_ENABLE | (src_w << 16) | src_h;
I915_WRITE(DVSSTRIDE(pipe), fb->pitches[0]);
I915_WRITE(DVSPOS(pipe), (crtc_y << 16) | crtc_x);
if (obj->tiling_mode != I915_TILING_NONE) {
I915_WRITE(DVSTILEOFF(pipe), (y << 16) | x);
} else {
unsigned long offset;
offset = y * fb->pitches[0] + x * (fb->bits_per_pixel / 8);
I915_WRITE(DVSLINOFF(pipe), offset);
}
I915_WRITE(DVSSIZE(pipe), (crtc_h << 16) | crtc_w);
I915_WRITE(DVSSCALE(pipe), dvsscale);
I915_WRITE(DVSCNTR(pipe), dvscntr);
I915_MODIFY_DISPBASE(DVSSURF(pipe), obj->gtt_offset);
POSTING_READ(DVSSURF(pipe));
}
static void
ilk_disable_plane(struct drm_plane *plane)
{
struct drm_device *dev = plane->dev;
struct drm_i915_private *dev_priv = dev->dev_private;
struct intel_plane *intel_plane = to_intel_plane(plane);
int pipe = intel_plane->pipe;
I915_WRITE(DVSCNTR(pipe), I915_READ(DVSCNTR(pipe)) & ~DVS_ENABLE);
I915_WRITE(DVSSCALE(pipe), 0);
I915_MODIFY_DISPBASE(DVSSURF(pipe), 0);
POSTING_READ(DVSSURF(pipe));
}
static void
intel_enable_primary(struct drm_crtc *crtc)
{
struct drm_device *dev = crtc->dev;
struct drm_i915_private *dev_priv = dev->dev_private;
struct intel_crtc *intel_crtc = to_intel_crtc(crtc);
int reg = DSPCNTR(intel_crtc->plane);
I915_WRITE(reg, I915_READ(reg) | DISPLAY_PLANE_ENABLE);
}
static void
intel_disable_primary(struct drm_crtc *crtc)
{
struct drm_device *dev = crtc->dev;
struct drm_i915_private *dev_priv = dev->dev_private;
struct intel_crtc *intel_crtc = to_intel_crtc(crtc);
int reg = DSPCNTR(intel_crtc->plane);
I915_WRITE(reg, I915_READ(reg) & ~DISPLAY_PLANE_ENABLE);
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
static int
intel_update_plane(struct drm_plane *plane, struct drm_crtc *crtc,
struct drm_framebuffer *fb, int crtc_x, int crtc_y,
unsigned int crtc_w, unsigned int crtc_h,
uint32_t src_x, uint32_t src_y,
uint32_t src_w, uint32_t src_h)
{
struct drm_device *dev = plane->dev;
struct drm_i915_private *dev_priv = dev->dev_private;
struct intel_crtc *intel_crtc = to_intel_crtc(crtc);
struct intel_plane *intel_plane = to_intel_plane(plane);
struct intel_framebuffer *intel_fb;
struct drm_i915_gem_object *obj, *old_obj;
int pipe = intel_plane->pipe;
int ret = 0;
int x = src_x >> 16, y = src_y >> 16;
int primary_w = crtc->mode.hdisplay, primary_h = crtc->mode.vdisplay;
bool disable_primary = false;
intel_fb = to_intel_framebuffer(fb);
obj = intel_fb->obj;
old_obj = intel_plane->obj;
src_w = src_w >> 16;
src_h = src_h >> 16;
if (!(I915_READ(PIPECONF(pipe)) & PIPECONF_ENABLE))
return -EINVAL;
if (crtc_x >= primary_w || crtc_y >= primary_h)
return -EINVAL;
if (intel_plane->pipe != intel_crtc->pipe)
return -EINVAL;
if ((crtc_x < 0) && ((crtc_x + crtc_w) > 0)) {
crtc_w += crtc_x;
crtc_x = 0;
}
if ((crtc_x + crtc_w) <= 0)
goto out;
if ((crtc_x + crtc_w) > primary_w)
crtc_w = primary_w - crtc_x;
if ((crtc_y < 0) && ((crtc_y + crtc_h) > 0)) {
crtc_h += crtc_y;
crtc_y = 0;
}
if ((crtc_y + crtc_h) <= 0)
goto out;
if (crtc_y + crtc_h > primary_h)
crtc_h = primary_h - crtc_y;
if (!crtc_w || !crtc_h)
goto out;
if (((src_w * src_h) / (crtc_w * crtc_h)) > intel_plane->max_downscale)
return -EINVAL;
if ((crtc_x == 0) && (crtc_y == 0) &&
(crtc_w == primary_w) && (crtc_h == primary_h))
disable_primary = true;
mutex_lock(&dev->struct_mutex);
ret = intel_pin_and_fence_fb_obj(dev, obj, NULL);
if (ret)
goto out_unlock;
intel_plane->obj = obj;
if (!disable_primary && intel_plane->primary_disabled) {
intel_enable_primary(crtc);
intel_plane->primary_disabled = false;
}
intel_plane->update_plane(plane, fb, obj, crtc_x, crtc_y,
crtc_w, crtc_h, x, y, src_w, src_h);
if (disable_primary) {
intel_disable_primary(crtc);
intel_plane->primary_disabled = true;
}
if (old_obj) {
if (old_obj != obj) {
mutex_unlock(&dev->struct_mutex);
intel_wait_for_vblank(dev, to_intel_crtc(crtc)->pipe);
mutex_lock(&dev->struct_mutex);
}
intel_unpin_fb_obj(old_obj);
}
out_unlock:
mutex_unlock(&dev->struct_mutex);
out:
return ret;
}
static int
intel_disable_plane(struct drm_plane *plane)
{
struct drm_device *dev = plane->dev;
struct intel_plane *intel_plane = to_intel_plane(plane);
int ret = 0;
if (intel_plane->primary_disabled) {
intel_enable_primary(plane->crtc);
intel_plane->primary_disabled = false;
}
intel_plane->disable_plane(plane);
if (!intel_plane->obj)
goto out;
mutex_lock(&dev->struct_mutex);
intel_unpin_fb_obj(intel_plane->obj);
intel_plane->obj = NULL;
mutex_unlock(&dev->struct_mutex);
out:
return ret;
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
mutex_lock(&dev->mode_config.mutex);
obj = drm_mode_object_find(dev, set->plane_id, DRM_MODE_OBJECT_PLANE);
if (!obj) {
ret = -EINVAL;
goto out_unlock;
}
plane = obj_to_plane(obj);
intel_plane = to_intel_plane(plane);
ret = intel_plane->update_colorkey(plane, set);
out_unlock:
mutex_unlock(&dev->mode_config.mutex);
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
mutex_lock(&dev->mode_config.mutex);
obj = drm_mode_object_find(dev, get->plane_id, DRM_MODE_OBJECT_PLANE);
if (!obj) {
ret = -EINVAL;
goto out_unlock;
}
plane = obj_to_plane(obj);
intel_plane = to_intel_plane(plane);
intel_plane->get_colorkey(plane, get);
out_unlock:
mutex_unlock(&dev->mode_config.mutex);
return ret;
}
int
intel_plane_init(struct drm_device *dev, enum pipe pipe)
{
struct intel_plane *intel_plane;
unsigned long possible_crtcs;
const uint32_t *plane_formats;
int num_plane_formats;
int ret;
if (INTEL_INFO(dev)->gen < 5)
return -ENODEV;
intel_plane = kzalloc(sizeof(struct intel_plane), GFP_KERNEL);
if (!intel_plane)
return -ENOMEM;
switch (INTEL_INFO(dev)->gen) {
case 5:
case 6:
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
intel_plane->max_downscale = 2;
intel_plane->update_plane = ivb_update_plane;
intel_plane->disable_plane = ivb_disable_plane;
intel_plane->update_colorkey = ivb_update_colorkey;
intel_plane->get_colorkey = ivb_get_colorkey;
plane_formats = snb_plane_formats;
num_plane_formats = ARRAY_SIZE(snb_plane_formats);
break;
default:
return -ENODEV;
}
intel_plane->pipe = pipe;
possible_crtcs = (1 << pipe);
ret = drm_plane_init(dev, &intel_plane->base, possible_crtcs,
&intel_plane_funcs,
plane_formats, num_plane_formats,
false);
if (ret)
kfree(intel_plane);
return ret;
}
