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
static int usecs_to_scanlines(const struct drm_display_mode *adjusted_mode,
int usecs)
{
if (!adjusted_mode->crtc_htotal)
return 1;
return DIV_ROUND_UP(usecs * adjusted_mode->crtc_clock,
1000 * adjusted_mode->crtc_htotal);
}
void intel_pipe_update_start(struct intel_crtc *crtc)
{
struct drm_device *dev = crtc->base.dev;
const struct drm_display_mode *adjusted_mode = &crtc->config->base.adjusted_mode;
enum pipe pipe = crtc->pipe;
long timeout = msecs_to_jiffies_timeout(1);
int scanline, min, max, vblank_start;
wait_queue_head_t *wq = drm_crtc_vblank_waitqueue(&crtc->base);
DEFINE_WAIT(wait);
vblank_start = adjusted_mode->crtc_vblank_start;
if (adjusted_mode->flags & DRM_MODE_FLAG_INTERLACE)
vblank_start = DIV_ROUND_UP(vblank_start, 2);
min = vblank_start - usecs_to_scanlines(adjusted_mode, 100);
max = vblank_start - 1;
local_irq_disable();
if (min <= 0 || max <= 0)
return;
if (WARN_ON(drm_crtc_vblank_get(&crtc->base)))
return;
crtc->debug.min_vbl = min;
crtc->debug.max_vbl = max;
trace_i915_pipe_update_start(crtc);
for (;;) {
prepare_to_wait(wq, &wait, TASK_UNINTERRUPTIBLE);
scanline = intel_get_crtc_scanline(crtc);
if (scanline < min || scanline > max)
break;
if (timeout <= 0) {
DRM_ERROR("Potential atomic update failure on pipe %c\n",
pipe_name(crtc->pipe));
break;
}
local_irq_enable();
timeout = schedule_timeout(timeout);
local_irq_disable();
}
finish_wait(wq, &wait);
drm_crtc_vblank_put(&crtc->base);
crtc->debug.scanline_start = scanline;
crtc->debug.start_vbl_time = ktime_get();
crtc->debug.start_vbl_count =
dev->driver->get_vblank_counter(dev, pipe);
trace_i915_pipe_update_vblank_evaded(crtc);
}
void intel_pipe_update_end(struct intel_crtc *crtc)
{
struct drm_device *dev = crtc->base.dev;
enum pipe pipe = crtc->pipe;
int scanline_end = intel_get_crtc_scanline(crtc);
u32 end_vbl_count = dev->driver->get_vblank_counter(dev, pipe);
ktime_t end_vbl_time = ktime_get();
trace_i915_pipe_update_end(crtc, end_vbl_count, scanline_end);
local_irq_enable();
if (crtc->debug.start_vbl_count &&
crtc->debug.start_vbl_count != end_vbl_count) {
DRM_ERROR("Atomic update failure on pipe %c (start=%u end=%u) time %lld us, min %d, max %d, scanline start %d, end %d\n",
pipe_name(pipe), crtc->debug.start_vbl_count,
end_vbl_count,
ktime_us_delta(end_vbl_time, crtc->debug.start_vbl_time),
crtc->debug.min_vbl, crtc->debug.max_vbl,
crtc->debug.scanline_start, scanline_end);
}
}
static void
skl_update_plane(struct drm_plane *drm_plane,
const struct intel_crtc_state *crtc_state,
const struct intel_plane_state *plane_state)
{
struct drm_device *dev = drm_plane->dev;
struct drm_i915_private *dev_priv = dev->dev_private;
struct intel_plane *intel_plane = to_intel_plane(drm_plane);
struct drm_framebuffer *fb = plane_state->base.fb;
struct drm_i915_gem_object *obj = intel_fb_obj(fb);
const int pipe = intel_plane->pipe;
const int plane = intel_plane->plane + 1;
u32 plane_ctl, stride_div, stride;
const struct drm_intel_sprite_colorkey *key = &plane_state->ckey;
u32 surf_addr;
u32 tile_height, plane_offset, plane_size;
unsigned int rotation = plane_state->base.rotation;
int x_offset, y_offset;
int crtc_x = plane_state->dst.x1;
int crtc_y = plane_state->dst.y1;
uint32_t crtc_w = drm_rect_width(&plane_state->dst);
uint32_t crtc_h = drm_rect_height(&plane_state->dst);
uint32_t x = plane_state->src.x1 >> 16;
uint32_t y = plane_state->src.y1 >> 16;
uint32_t src_w = drm_rect_width(&plane_state->src) >> 16;
uint32_t src_h = drm_rect_height(&plane_state->src) >> 16;
const struct intel_scaler *scaler =
&crtc_state->scaler_state.scalers[plane_state->scaler_id];
plane_ctl = PLANE_CTL_ENABLE |
PLANE_CTL_PIPE_GAMMA_ENABLE |
PLANE_CTL_PIPE_CSC_ENABLE;
plane_ctl |= skl_plane_ctl_format(fb->pixel_format);
plane_ctl |= skl_plane_ctl_tiling(fb->modifier[0]);
plane_ctl |= skl_plane_ctl_rotation(rotation);
stride_div = intel_fb_stride_alignment(dev_priv, fb->modifier[0],
fb->pixel_format);
src_w--;
src_h--;
crtc_w--;
crtc_h--;
if (key->flags) {
I915_WRITE(PLANE_KEYVAL(pipe, plane), key->min_value);
I915_WRITE(PLANE_KEYMAX(pipe, plane), key->max_value);
I915_WRITE(PLANE_KEYMSK(pipe, plane), key->channel_mask);
}
if (key->flags & I915_SET_COLORKEY_DESTINATION)
plane_ctl |= PLANE_CTL_KEY_ENABLE_DESTINATION;
else if (key->flags & I915_SET_COLORKEY_SOURCE)
plane_ctl |= PLANE_CTL_KEY_ENABLE_SOURCE;
surf_addr = intel_plane_obj_offset(intel_plane, obj, 0);
if (intel_rotation_90_or_270(rotation)) {
int cpp = drm_format_plane_cpp(fb->pixel_format, 0);
tile_height = intel_tile_height(dev_priv, fb->modifier[0], cpp);
stride = DIV_ROUND_UP(fb->height, tile_height);
plane_size = (src_w << 16) | src_h;
x_offset = stride * tile_height - y - (src_h + 1);
y_offset = x;
} else {
stride = fb->pitches[0] / stride_div;
plane_size = (src_h << 16) | src_w;
x_offset = x;
y_offset = y;
}
plane_offset = y_offset << 16 | x_offset;
I915_WRITE(PLANE_OFFSET(pipe, plane), plane_offset);
I915_WRITE(PLANE_STRIDE(pipe, plane), stride);
I915_WRITE(PLANE_SIZE(pipe, plane), plane_size);
if (plane_state->scaler_id >= 0) {
uint32_t ps_ctrl = 0;
int scaler_id = plane_state->scaler_id;
DRM_DEBUG_KMS("plane = %d PS_PLANE_SEL(plane) = 0x%x\n", plane,
PS_PLANE_SEL(plane));
ps_ctrl = PS_SCALER_EN | PS_PLANE_SEL(plane) | scaler->mode;
I915_WRITE(SKL_PS_CTRL(pipe, scaler_id), ps_ctrl);
I915_WRITE(SKL_PS_PWR_GATE(pipe, scaler_id), 0);
I915_WRITE(SKL_PS_WIN_POS(pipe, scaler_id), (crtc_x << 16) | crtc_y);
I915_WRITE(SKL_PS_WIN_SZ(pipe, scaler_id),
((crtc_w + 1) << 16)|(crtc_h + 1));
I915_WRITE(PLANE_POS(pipe, plane), 0);
} else {
I915_WRITE(PLANE_POS(pipe, plane), (crtc_y << 16) | crtc_x);
}
I915_WRITE(PLANE_CTL(pipe, plane), plane_ctl);
I915_WRITE(PLANE_SURF(pipe, plane), surf_addr);
POSTING_READ(PLANE_SURF(pipe, plane));
}
static void
skl_disable_plane(struct drm_plane *dplane, struct drm_crtc *crtc)
{
struct drm_device *dev = dplane->dev;
struct drm_i915_private *dev_priv = dev->dev_private;
struct intel_plane *intel_plane = to_intel_plane(dplane);
const int pipe = intel_plane->pipe;
const int plane = intel_plane->plane + 1;
I915_WRITE(PLANE_CTL(pipe, plane), 0);
I915_WRITE(PLANE_SURF(pipe, plane), 0);
POSTING_READ(PLANE_SURF(pipe, plane));
}
static void
chv_update_csc(struct intel_plane *intel_plane, uint32_t format)
{
struct drm_i915_private *dev_priv = intel_plane->base.dev->dev_private;
int plane = intel_plane->plane;
if (!format_is_yuv(format))
return;
I915_WRITE(SPCSCYGOFF(plane), SPCSC_OOFF(0) | SPCSC_IOFF(-64));
I915_WRITE(SPCSCCBOFF(plane), SPCSC_OOFF(0) | SPCSC_IOFF(0));
I915_WRITE(SPCSCCROFF(plane), SPCSC_OOFF(0) | SPCSC_IOFF(0));
I915_WRITE(SPCSCC01(plane), SPCSC_C1(4769) | SPCSC_C0(6537));
I915_WRITE(SPCSCC23(plane), SPCSC_C1(-3330) | SPCSC_C0(0));
I915_WRITE(SPCSCC45(plane), SPCSC_C1(-1605) | SPCSC_C0(4769));
I915_WRITE(SPCSCC67(plane), SPCSC_C1(4769) | SPCSC_C0(0));
I915_WRITE(SPCSCC8(plane), SPCSC_C0(8263));
I915_WRITE(SPCSCYGICLAMP(plane), SPCSC_IMAX(940) | SPCSC_IMIN(64));
I915_WRITE(SPCSCCBICLAMP(plane), SPCSC_IMAX(448) | SPCSC_IMIN(-448));
I915_WRITE(SPCSCCRICLAMP(plane), SPCSC_IMAX(448) | SPCSC_IMIN(-448));
I915_WRITE(SPCSCYGOCLAMP(plane), SPCSC_OMAX(1023) | SPCSC_OMIN(0));
I915_WRITE(SPCSCCBOCLAMP(plane), SPCSC_OMAX(1023) | SPCSC_OMIN(0));
I915_WRITE(SPCSCCROCLAMP(plane), SPCSC_OMAX(1023) | SPCSC_OMIN(0));
}
static void
vlv_update_plane(struct drm_plane *dplane,
const struct intel_crtc_state *crtc_state,
const struct intel_plane_state *plane_state)
{
struct drm_device *dev = dplane->dev;
struct drm_i915_private *dev_priv = dev->dev_private;
struct intel_plane *intel_plane = to_intel_plane(dplane);
struct drm_framebuffer *fb = plane_state->base.fb;
struct drm_i915_gem_object *obj = intel_fb_obj(fb);
int pipe = intel_plane->pipe;
int plane = intel_plane->plane;
u32 sprctl;
u32 sprsurf_offset, linear_offset;
unsigned int rotation = dplane->state->rotation;
int cpp = drm_format_plane_cpp(fb->pixel_format, 0);
const struct drm_intel_sprite_colorkey *key = &plane_state->ckey;
int crtc_x = plane_state->dst.x1;
int crtc_y = plane_state->dst.y1;
uint32_t crtc_w = drm_rect_width(&plane_state->dst);
uint32_t crtc_h = drm_rect_height(&plane_state->dst);
uint32_t x = plane_state->src.x1 >> 16;
uint32_t y = plane_state->src.y1 >> 16;
uint32_t src_w = drm_rect_width(&plane_state->src) >> 16;
uint32_t src_h = drm_rect_height(&plane_state->src) >> 16;
sprctl = SP_ENABLE;
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
sprctl |= SP_GAMMA_ENABLE;
if (obj->tiling_mode != I915_TILING_NONE)
sprctl |= SP_TILED;
src_w--;
src_h--;
crtc_w--;
crtc_h--;
linear_offset = y * fb->pitches[0] + x * cpp;
sprsurf_offset = intel_compute_tile_offset(&x, &y, fb, 0,
fb->pitches[0], rotation);
linear_offset -= sprsurf_offset;
if (rotation == BIT(DRM_ROTATE_180)) {
sprctl |= SP_ROTATE_180;
x += src_w;
y += src_h;
linear_offset += src_h * fb->pitches[0] + src_w * cpp;
}
if (key->flags) {
I915_WRITE(SPKEYMINVAL(pipe, plane), key->min_value);
I915_WRITE(SPKEYMAXVAL(pipe, plane), key->max_value);
I915_WRITE(SPKEYMSK(pipe, plane), key->channel_mask);
}
if (key->flags & I915_SET_COLORKEY_SOURCE)
sprctl |= SP_SOURCE_KEY;
if (IS_CHERRYVIEW(dev) && pipe == PIPE_B)
chv_update_csc(intel_plane, fb->pixel_format);
I915_WRITE(SPSTRIDE(pipe, plane), fb->pitches[0]);
I915_WRITE(SPPOS(pipe, plane), (crtc_y << 16) | crtc_x);
if (obj->tiling_mode != I915_TILING_NONE)
I915_WRITE(SPTILEOFF(pipe, plane), (y << 16) | x);
else
I915_WRITE(SPLINOFF(pipe, plane), linear_offset);
I915_WRITE(SPCONSTALPHA(pipe, plane), 0);
I915_WRITE(SPSIZE(pipe, plane), (crtc_h << 16) | crtc_w);
I915_WRITE(SPCNTR(pipe, plane), sprctl);
I915_WRITE(SPSURF(pipe, plane), i915_gem_obj_ggtt_offset(obj) +
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
I915_WRITE(SPCNTR(pipe, plane), 0);
I915_WRITE(SPSURF(pipe, plane), 0);
POSTING_READ(SPSURF(pipe, plane));
}
static void
ivb_update_plane(struct drm_plane *plane,
const struct intel_crtc_state *crtc_state,
const struct intel_plane_state *plane_state)
{
struct drm_device *dev = plane->dev;
struct drm_i915_private *dev_priv = dev->dev_private;
struct intel_plane *intel_plane = to_intel_plane(plane);
struct drm_framebuffer *fb = plane_state->base.fb;
struct drm_i915_gem_object *obj = intel_fb_obj(fb);
enum pipe pipe = intel_plane->pipe;
u32 sprctl, sprscale = 0;
u32 sprsurf_offset, linear_offset;
unsigned int rotation = plane_state->base.rotation;
int cpp = drm_format_plane_cpp(fb->pixel_format, 0);
const struct drm_intel_sprite_colorkey *key = &plane_state->ckey;
int crtc_x = plane_state->dst.x1;
int crtc_y = plane_state->dst.y1;
uint32_t crtc_w = drm_rect_width(&plane_state->dst);
uint32_t crtc_h = drm_rect_height(&plane_state->dst);
uint32_t x = plane_state->src.x1 >> 16;
uint32_t y = plane_state->src.y1 >> 16;
uint32_t src_w = drm_rect_width(&plane_state->src) >> 16;
uint32_t src_h = drm_rect_height(&plane_state->src) >> 16;
sprctl = SPRITE_ENABLE;
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
sprctl |= SPRITE_GAMMA_ENABLE;
if (obj->tiling_mode != I915_TILING_NONE)
sprctl |= SPRITE_TILED;
if (IS_HASWELL(dev) || IS_BROADWELL(dev))
sprctl &= ~SPRITE_TRICKLE_FEED_DISABLE;
else
sprctl |= SPRITE_TRICKLE_FEED_DISABLE;
if (IS_HASWELL(dev) || IS_BROADWELL(dev))
sprctl |= SPRITE_PIPE_CSC_ENABLE;
src_w--;
src_h--;
crtc_w--;
crtc_h--;
if (crtc_w != src_w || crtc_h != src_h)
sprscale = SPRITE_SCALE_ENABLE | (src_w << 16) | src_h;
linear_offset = y * fb->pitches[0] + x * cpp;
sprsurf_offset = intel_compute_tile_offset(&x, &y, fb, 0,
fb->pitches[0], rotation);
linear_offset -= sprsurf_offset;
if (rotation == BIT(DRM_ROTATE_180)) {
sprctl |= SPRITE_ROTATE_180;
if (!IS_HASWELL(dev) && !IS_BROADWELL(dev)) {
x += src_w;
y += src_h;
linear_offset += src_h * fb->pitches[0] + src_w * cpp;
}
}
if (key->flags) {
I915_WRITE(SPRKEYVAL(pipe), key->min_value);
I915_WRITE(SPRKEYMAX(pipe), key->max_value);
I915_WRITE(SPRKEYMSK(pipe), key->channel_mask);
}
if (key->flags & I915_SET_COLORKEY_DESTINATION)
sprctl |= SPRITE_DEST_KEY;
else if (key->flags & I915_SET_COLORKEY_SOURCE)
sprctl |= SPRITE_SOURCE_KEY;
I915_WRITE(SPRSTRIDE(pipe), fb->pitches[0]);
I915_WRITE(SPRPOS(pipe), (crtc_y << 16) | crtc_x);
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
I915_WRITE(SPRSURF(pipe),
i915_gem_obj_ggtt_offset(obj) + sprsurf_offset);
POSTING_READ(SPRSURF(pipe));
}
static void
ivb_disable_plane(struct drm_plane *plane, struct drm_crtc *crtc)
{
struct drm_device *dev = plane->dev;
struct drm_i915_private *dev_priv = dev->dev_private;
struct intel_plane *intel_plane = to_intel_plane(plane);
int pipe = intel_plane->pipe;
I915_WRITE(SPRCTL(pipe), 0);
if (intel_plane->can_scale)
I915_WRITE(SPRSCALE(pipe), 0);
I915_WRITE(SPRSURF(pipe), 0);
POSTING_READ(SPRSURF(pipe));
}
static void
ilk_update_plane(struct drm_plane *plane,
const struct intel_crtc_state *crtc_state,
const struct intel_plane_state *plane_state)
{
struct drm_device *dev = plane->dev;
struct drm_i915_private *dev_priv = dev->dev_private;
struct intel_plane *intel_plane = to_intel_plane(plane);
struct drm_framebuffer *fb = plane_state->base.fb;
struct drm_i915_gem_object *obj = intel_fb_obj(fb);
int pipe = intel_plane->pipe;
u32 dvscntr, dvsscale;
u32 dvssurf_offset, linear_offset;
unsigned int rotation = plane_state->base.rotation;
int cpp = drm_format_plane_cpp(fb->pixel_format, 0);
const struct drm_intel_sprite_colorkey *key = &plane_state->ckey;
int crtc_x = plane_state->dst.x1;
int crtc_y = plane_state->dst.y1;
uint32_t crtc_w = drm_rect_width(&plane_state->dst);
uint32_t crtc_h = drm_rect_height(&plane_state->dst);
uint32_t x = plane_state->src.x1 >> 16;
uint32_t y = plane_state->src.y1 >> 16;
uint32_t src_w = drm_rect_width(&plane_state->src) >> 16;
uint32_t src_h = drm_rect_height(&plane_state->src) >> 16;
dvscntr = DVS_ENABLE;
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
dvscntr |= DVS_GAMMA_ENABLE;
if (obj->tiling_mode != I915_TILING_NONE)
dvscntr |= DVS_TILED;
if (IS_GEN6(dev))
dvscntr |= DVS_TRICKLE_FEED_DISABLE;
src_w--;
src_h--;
crtc_w--;
crtc_h--;
dvsscale = 0;
if (crtc_w != src_w || crtc_h != src_h)
dvsscale = DVS_SCALE_ENABLE | (src_w << 16) | src_h;
linear_offset = y * fb->pitches[0] + x * cpp;
dvssurf_offset = intel_compute_tile_offset(&x, &y, fb, 0,
fb->pitches[0], rotation);
linear_offset -= dvssurf_offset;
if (rotation == BIT(DRM_ROTATE_180)) {
dvscntr |= DVS_ROTATE_180;
x += src_w;
y += src_h;
linear_offset += src_h * fb->pitches[0] + src_w * cpp;
}
if (key->flags) {
I915_WRITE(DVSKEYVAL(pipe), key->min_value);
I915_WRITE(DVSKEYMAX(pipe), key->max_value);
I915_WRITE(DVSKEYMSK(pipe), key->channel_mask);
}
if (key->flags & I915_SET_COLORKEY_DESTINATION)
dvscntr |= DVS_DEST_KEY;
else if (key->flags & I915_SET_COLORKEY_SOURCE)
dvscntr |= DVS_SOURCE_KEY;
I915_WRITE(DVSSTRIDE(pipe), fb->pitches[0]);
I915_WRITE(DVSPOS(pipe), (crtc_y << 16) | crtc_x);
if (obj->tiling_mode != I915_TILING_NONE)
I915_WRITE(DVSTILEOFF(pipe), (y << 16) | x);
else
I915_WRITE(DVSLINOFF(pipe), linear_offset);
I915_WRITE(DVSSIZE(pipe), (crtc_h << 16) | crtc_w);
I915_WRITE(DVSSCALE(pipe), dvsscale);
I915_WRITE(DVSCNTR(pipe), dvscntr);
I915_WRITE(DVSSURF(pipe),
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
I915_WRITE(DVSCNTR(pipe), 0);
I915_WRITE(DVSSCALE(pipe), 0);
I915_WRITE(DVSSURF(pipe), 0);
POSTING_READ(DVSSURF(pipe));
}
static int
intel_check_sprite_plane(struct drm_plane *plane,
struct intel_crtc_state *crtc_state,
struct intel_plane_state *state)
{
struct drm_device *dev = plane->dev;
struct drm_crtc *crtc = state->base.crtc;
struct intel_crtc *intel_crtc = to_intel_crtc(crtc);
struct intel_plane *intel_plane = to_intel_plane(plane);
struct drm_framebuffer *fb = state->base.fb;
int crtc_x, crtc_y;
unsigned int crtc_w, crtc_h;
uint32_t src_x, src_y, src_w, src_h;
struct drm_rect *src = &state->src;
struct drm_rect *dst = &state->dst;
const struct drm_rect *clip = &state->clip;
int hscale, vscale;
int max_scale, min_scale;
bool can_scale;
if (!fb) {
state->visible = false;
return 0;
}
if (intel_plane->pipe != intel_crtc->pipe) {
DRM_DEBUG_KMS("Wrong plane <-> crtc mapping\n");
return -EINVAL;
}
if (fb->width < 3 || fb->height < 3 || fb->pitches[0] > 16384) {
DRM_DEBUG_KMS("Unsuitable framebuffer for plane\n");
return -EINVAL;
}
if (INTEL_INFO(dev)->gen >= 9) {
if (state->ckey.flags == I915_SET_COLORKEY_NONE) {
can_scale = 1;
min_scale = 1;
max_scale = skl_max_scale(intel_crtc, crtc_state);
} else {
can_scale = 0;
min_scale = DRM_PLANE_HELPER_NO_SCALING;
max_scale = DRM_PLANE_HELPER_NO_SCALING;
}
} else {
can_scale = intel_plane->can_scale;
max_scale = intel_plane->max_downscale << 16;
min_scale = intel_plane->can_scale ? 1 : (1 << 16);
}
drm_rect_rotate(src, fb->width << 16, fb->height << 16,
state->base.rotation);
hscale = drm_rect_calc_hscale_relaxed(src, dst, min_scale, max_scale);
BUG_ON(hscale < 0);
vscale = drm_rect_calc_vscale_relaxed(src, dst, min_scale, max_scale);
BUG_ON(vscale < 0);
state->visible = drm_rect_clip_scaled(src, dst, clip, hscale, vscale);
crtc_x = dst->x1;
crtc_y = dst->y1;
crtc_w = drm_rect_width(dst);
crtc_h = drm_rect_height(dst);
if (state->visible) {
hscale = drm_rect_calc_hscale(src, dst, min_scale, max_scale);
if (hscale < 0) {
DRM_DEBUG_KMS("Horizontal scaling factor out of limits\n");
drm_rect_debug_print("src: ", src, true);
drm_rect_debug_print("dst: ", dst, false);
return hscale;
}
vscale = drm_rect_calc_vscale(src, dst, min_scale, max_scale);
if (vscale < 0) {
DRM_DEBUG_KMS("Vertical scaling factor out of limits\n");
drm_rect_debug_print("src: ", src, true);
drm_rect_debug_print("dst: ", dst, false);
return vscale;
}
drm_rect_adjust_size(src,
drm_rect_width(dst) * hscale - drm_rect_width(src),
drm_rect_height(dst) * vscale - drm_rect_height(src));
drm_rect_rotate_inv(src, fb->width << 16, fb->height << 16,
state->base.rotation);
WARN_ON(src->x1 < (int) state->base.src_x ||
src->y1 < (int) state->base.src_y ||
src->x2 > (int) state->base.src_x + state->base.src_w ||
src->y2 > (int) state->base.src_y + state->base.src_h);
src_x = src->x1 >> 16;
src_w = drm_rect_width(src) >> 16;
src_y = src->y1 >> 16;
src_h = drm_rect_height(src) >> 16;
if (format_is_yuv(fb->pixel_format)) {
src_x &= ~1;
src_w &= ~1;
if (!can_scale)
crtc_w &= ~1;
if (crtc_w == 0)
state->visible = false;
}
}
if (state->visible && (src_w != crtc_w || src_h != crtc_h)) {
unsigned int width_bytes;
int cpp = drm_format_plane_cpp(fb->pixel_format, 0);
WARN_ON(!can_scale);
if (crtc_w < 3 || crtc_h < 3)
state->visible = false;
if (src_w < 3 || src_h < 3)
state->visible = false;
width_bytes = ((src_x * cpp) & 63) + src_w * cpp;
if (INTEL_INFO(dev)->gen < 9 && (src_w > 2048 || src_h > 2048 ||
width_bytes > 4096 || fb->pitches[0] > 4096)) {
DRM_DEBUG_KMS("Source dimensions exceed hardware limits\n");
return -EINVAL;
}
}
if (state->visible) {
src->x1 = src_x << 16;
src->x2 = (src_x + src_w) << 16;
src->y1 = src_y << 16;
src->y2 = (src_y + src_h) << 16;
}
dst->x1 = crtc_x;
dst->x2 = crtc_x + crtc_w;
dst->y1 = crtc_y;
dst->y2 = crtc_y + crtc_h;
return 0;
}
int intel_sprite_set_colorkey(struct drm_device *dev, void *data,
struct drm_file *file_priv)
{
struct drm_intel_sprite_colorkey *set = data;
struct drm_plane *plane;
struct drm_plane_state *plane_state;
struct drm_atomic_state *state;
struct drm_modeset_acquire_ctx ctx;
int ret = 0;
if ((set->flags & (I915_SET_COLORKEY_DESTINATION | I915_SET_COLORKEY_SOURCE)) == (I915_SET_COLORKEY_DESTINATION | I915_SET_COLORKEY_SOURCE))
return -EINVAL;
if ((IS_VALLEYVIEW(dev) || IS_CHERRYVIEW(dev)) &&
set->flags & I915_SET_COLORKEY_DESTINATION)
return -EINVAL;
plane = drm_plane_find(dev, set->plane_id);
if (!plane || plane->type != DRM_PLANE_TYPE_OVERLAY)
return -ENOENT;
drm_modeset_acquire_init(&ctx, 0);
state = drm_atomic_state_alloc(plane->dev);
if (!state) {
ret = -ENOMEM;
goto out;
}
state->acquire_ctx = &ctx;
while (1) {
plane_state = drm_atomic_get_plane_state(state, plane);
ret = PTR_ERR_OR_ZERO(plane_state);
if (!ret) {
to_intel_plane_state(plane_state)->ckey = *set;
ret = drm_atomic_commit(state);
}
if (ret != -EDEADLK)
break;
drm_atomic_state_clear(state);
drm_modeset_backoff(&ctx);
}
if (ret)
drm_atomic_state_free(state);
out:
drm_modeset_drop_locks(&ctx);
drm_modeset_acquire_fini(&ctx);
return ret;
}
int
intel_plane_init(struct drm_device *dev, enum pipe pipe, int plane)
{
struct intel_plane *intel_plane = NULL;
struct intel_plane_state *state = NULL;
unsigned long possible_crtcs;
const uint32_t *plane_formats;
int num_plane_formats;
int ret;
if (INTEL_INFO(dev)->gen < 5)
return -ENODEV;
intel_plane = kzalloc(sizeof(*intel_plane), GFP_KERNEL);
if (!intel_plane) {
ret = -ENOMEM;
goto fail;
}
state = intel_create_plane_state(&intel_plane->base);
if (!state) {
ret = -ENOMEM;
goto fail;
}
intel_plane->base.state = &state->base;
switch (INTEL_INFO(dev)->gen) {
case 5:
case 6:
intel_plane->can_scale = true;
intel_plane->max_downscale = 16;
intel_plane->update_plane = ilk_update_plane;
intel_plane->disable_plane = ilk_disable_plane;
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
if (IS_VALLEYVIEW(dev) || IS_CHERRYVIEW(dev)) {
intel_plane->update_plane = vlv_update_plane;
intel_plane->disable_plane = vlv_disable_plane;
plane_formats = vlv_plane_formats;
num_plane_formats = ARRAY_SIZE(vlv_plane_formats);
} else {
intel_plane->update_plane = ivb_update_plane;
intel_plane->disable_plane = ivb_disable_plane;
plane_formats = snb_plane_formats;
num_plane_formats = ARRAY_SIZE(snb_plane_formats);
}
break;
case 9:
intel_plane->can_scale = true;
intel_plane->update_plane = skl_update_plane;
intel_plane->disable_plane = skl_disable_plane;
state->scaler_id = -1;
plane_formats = skl_plane_formats;
num_plane_formats = ARRAY_SIZE(skl_plane_formats);
break;
default:
MISSING_CASE(INTEL_INFO(dev)->gen);
ret = -ENODEV;
goto fail;
}
intel_plane->pipe = pipe;
intel_plane->plane = plane;
intel_plane->frontbuffer_bit = INTEL_FRONTBUFFER_SPRITE(pipe, plane);
intel_plane->check_plane = intel_check_sprite_plane;
possible_crtcs = (1 << pipe);
ret = drm_universal_plane_init(dev, &intel_plane->base, possible_crtcs,
&intel_plane_funcs,
plane_formats, num_plane_formats,
DRM_PLANE_TYPE_OVERLAY, NULL);
if (ret)
goto fail;
intel_create_rotation_property(dev, intel_plane);
drm_plane_helper_add(&intel_plane->base, &intel_plane_helper_funcs);
return 0;
fail:
kfree(state);
kfree(intel_plane);
return ret;
}
