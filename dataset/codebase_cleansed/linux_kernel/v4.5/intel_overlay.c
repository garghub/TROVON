static struct overlay_registers __iomem *
intel_overlay_map_regs(struct intel_overlay *overlay)
{
struct drm_i915_private *dev_priv = overlay->dev->dev_private;
struct overlay_registers __iomem *regs;
if (OVERLAY_NEEDS_PHYSICAL(overlay->dev))
regs = (struct overlay_registers __iomem *)overlay->reg_bo->phys_handle->vaddr;
else
regs = io_mapping_map_wc(dev_priv->gtt.mappable,
i915_gem_obj_ggtt_offset(overlay->reg_bo));
return regs;
}
static void intel_overlay_unmap_regs(struct intel_overlay *overlay,
struct overlay_registers __iomem *regs)
{
if (!OVERLAY_NEEDS_PHYSICAL(overlay->dev))
io_mapping_unmap(regs);
}
static int intel_overlay_do_wait_request(struct intel_overlay *overlay,
struct drm_i915_gem_request *req,
void (*tail)(struct intel_overlay *))
{
int ret;
WARN_ON(overlay->last_flip_req);
i915_gem_request_assign(&overlay->last_flip_req, req);
i915_add_request(req);
overlay->flip_tail = tail;
ret = i915_wait_request(overlay->last_flip_req);
if (ret)
return ret;
i915_gem_request_assign(&overlay->last_flip_req, NULL);
return 0;
}
static int intel_overlay_on(struct intel_overlay *overlay)
{
struct drm_device *dev = overlay->dev;
struct drm_i915_private *dev_priv = dev->dev_private;
struct intel_engine_cs *ring = &dev_priv->ring[RCS];
struct drm_i915_gem_request *req;
int ret;
WARN_ON(overlay->active);
WARN_ON(IS_I830(dev) && !(dev_priv->quirks & QUIRK_PIPEA_FORCE));
ret = i915_gem_request_alloc(ring, ring->default_context, &req);
if (ret)
return ret;
ret = intel_ring_begin(req, 4);
if (ret) {
i915_gem_request_cancel(req);
return ret;
}
overlay->active = true;
intel_ring_emit(ring, MI_OVERLAY_FLIP | MI_OVERLAY_ON);
intel_ring_emit(ring, overlay->flip_addr | OFC_UPDATE);
intel_ring_emit(ring, MI_WAIT_FOR_EVENT | MI_WAIT_FOR_OVERLAY_FLIP);
intel_ring_emit(ring, MI_NOOP);
intel_ring_advance(ring);
return intel_overlay_do_wait_request(overlay, req, NULL);
}
static int intel_overlay_continue(struct intel_overlay *overlay,
bool load_polyphase_filter)
{
struct drm_device *dev = overlay->dev;
struct drm_i915_private *dev_priv = dev->dev_private;
struct intel_engine_cs *ring = &dev_priv->ring[RCS];
struct drm_i915_gem_request *req;
u32 flip_addr = overlay->flip_addr;
u32 tmp;
int ret;
WARN_ON(!overlay->active);
if (load_polyphase_filter)
flip_addr |= OFC_UPDATE;
tmp = I915_READ(DOVSTA);
if (tmp & (1 << 17))
DRM_DEBUG("overlay underrun, DOVSTA: %x\n", tmp);
ret = i915_gem_request_alloc(ring, ring->default_context, &req);
if (ret)
return ret;
ret = intel_ring_begin(req, 2);
if (ret) {
i915_gem_request_cancel(req);
return ret;
}
intel_ring_emit(ring, MI_OVERLAY_FLIP | MI_OVERLAY_CONTINUE);
intel_ring_emit(ring, flip_addr);
intel_ring_advance(ring);
WARN_ON(overlay->last_flip_req);
i915_gem_request_assign(&overlay->last_flip_req, req);
i915_add_request(req);
return 0;
}
static void intel_overlay_release_old_vid_tail(struct intel_overlay *overlay)
{
struct drm_i915_gem_object *obj = overlay->old_vid_bo;
i915_gem_object_ggtt_unpin(obj);
drm_gem_object_unreference(&obj->base);
overlay->old_vid_bo = NULL;
}
static void intel_overlay_off_tail(struct intel_overlay *overlay)
{
struct drm_i915_gem_object *obj = overlay->vid_bo;
if (WARN_ON(!obj))
return;
i915_gem_object_ggtt_unpin(obj);
drm_gem_object_unreference(&obj->base);
overlay->vid_bo = NULL;
overlay->crtc->overlay = NULL;
overlay->crtc = NULL;
overlay->active = false;
}
static int intel_overlay_off(struct intel_overlay *overlay)
{
struct drm_device *dev = overlay->dev;
struct drm_i915_private *dev_priv = dev->dev_private;
struct intel_engine_cs *ring = &dev_priv->ring[RCS];
struct drm_i915_gem_request *req;
u32 flip_addr = overlay->flip_addr;
int ret;
WARN_ON(!overlay->active);
flip_addr |= OFC_UPDATE;
ret = i915_gem_request_alloc(ring, ring->default_context, &req);
if (ret)
return ret;
ret = intel_ring_begin(req, 6);
if (ret) {
i915_gem_request_cancel(req);
return ret;
}
intel_ring_emit(ring, MI_OVERLAY_FLIP | MI_OVERLAY_CONTINUE);
intel_ring_emit(ring, flip_addr);
intel_ring_emit(ring, MI_WAIT_FOR_EVENT | MI_WAIT_FOR_OVERLAY_FLIP);
if (IS_I830(dev)) {
intel_ring_emit(ring, MI_NOOP);
intel_ring_emit(ring, MI_NOOP);
intel_ring_emit(ring, MI_NOOP);
} else {
intel_ring_emit(ring, MI_OVERLAY_FLIP | MI_OVERLAY_OFF);
intel_ring_emit(ring, flip_addr);
intel_ring_emit(ring, MI_WAIT_FOR_EVENT | MI_WAIT_FOR_OVERLAY_FLIP);
}
intel_ring_advance(ring);
return intel_overlay_do_wait_request(overlay, req, intel_overlay_off_tail);
}
static int intel_overlay_recover_from_interrupt(struct intel_overlay *overlay)
{
int ret;
if (overlay->last_flip_req == NULL)
return 0;
ret = i915_wait_request(overlay->last_flip_req);
if (ret)
return ret;
if (overlay->flip_tail)
overlay->flip_tail(overlay);
i915_gem_request_assign(&overlay->last_flip_req, NULL);
return 0;
}
static int intel_overlay_release_old_vid(struct intel_overlay *overlay)
{
struct drm_device *dev = overlay->dev;
struct drm_i915_private *dev_priv = dev->dev_private;
struct intel_engine_cs *ring = &dev_priv->ring[RCS];
int ret;
WARN_ON(!mutex_is_locked(&dev->struct_mutex));
if (!overlay->old_vid_bo)
return 0;
if (I915_READ(ISR) & I915_OVERLAY_PLANE_FLIP_PENDING_INTERRUPT) {
struct drm_i915_gem_request *req;
ret = i915_gem_request_alloc(ring, ring->default_context, &req);
if (ret)
return ret;
ret = intel_ring_begin(req, 2);
if (ret) {
i915_gem_request_cancel(req);
return ret;
}
intel_ring_emit(ring, MI_WAIT_FOR_EVENT | MI_WAIT_FOR_OVERLAY_FLIP);
intel_ring_emit(ring, MI_NOOP);
intel_ring_advance(ring);
ret = intel_overlay_do_wait_request(overlay, req,
intel_overlay_release_old_vid_tail);
if (ret)
return ret;
}
intel_overlay_release_old_vid_tail(overlay);
i915_gem_track_fb(overlay->old_vid_bo, NULL,
INTEL_FRONTBUFFER_OVERLAY(overlay->crtc->pipe));
return 0;
}
void intel_overlay_reset(struct drm_i915_private *dev_priv)
{
struct intel_overlay *overlay = dev_priv->overlay;
if (!overlay)
return;
intel_overlay_release_old_vid(overlay);
overlay->last_flip_req = NULL;
overlay->old_xscale = 0;
overlay->old_yscale = 0;
overlay->crtc = NULL;
overlay->active = false;
}
static int packed_depth_bytes(u32 format)
{
switch (format & I915_OVERLAY_DEPTH_MASK) {
case I915_OVERLAY_YUV422:
return 4;
case I915_OVERLAY_YUV411:
default:
return -EINVAL;
}
}
static int packed_width_bytes(u32 format, short width)
{
switch (format & I915_OVERLAY_DEPTH_MASK) {
case I915_OVERLAY_YUV422:
return width << 1;
default:
return -EINVAL;
}
}
static int uv_hsubsampling(u32 format)
{
switch (format & I915_OVERLAY_DEPTH_MASK) {
case I915_OVERLAY_YUV422:
case I915_OVERLAY_YUV420:
return 2;
case I915_OVERLAY_YUV411:
case I915_OVERLAY_YUV410:
return 4;
default:
return -EINVAL;
}
}
static int uv_vsubsampling(u32 format)
{
switch (format & I915_OVERLAY_DEPTH_MASK) {
case I915_OVERLAY_YUV420:
case I915_OVERLAY_YUV410:
return 2;
case I915_OVERLAY_YUV422:
case I915_OVERLAY_YUV411:
return 1;
default:
return -EINVAL;
}
}
static u32 calc_swidthsw(struct drm_device *dev, u32 offset, u32 width)
{
u32 mask, shift, ret;
if (IS_GEN2(dev)) {
mask = 0x1f;
shift = 5;
} else {
mask = 0x3f;
shift = 6;
}
ret = ((offset + width + mask) >> shift) - (offset >> shift);
if (!IS_GEN2(dev))
ret <<= 1;
ret -= 1;
return ret << 2;
}
static void update_polyphase_filter(struct overlay_registers __iomem *regs)
{
memcpy_toio(regs->Y_HCOEFS, y_static_hcoeffs, sizeof(y_static_hcoeffs));
memcpy_toio(regs->UV_HCOEFS, uv_static_hcoeffs,
sizeof(uv_static_hcoeffs));
}
static bool update_scaling_factors(struct intel_overlay *overlay,
struct overlay_registers __iomem *regs,
struct put_image_params *params)
{
u32 xscale, yscale, xscale_UV, yscale_UV;
#define FP_SHIFT 12
#define FRACT_MASK 0xfff
bool scale_changed = false;
int uv_hscale = uv_hsubsampling(params->format);
int uv_vscale = uv_vsubsampling(params->format);
if (params->dst_w > 1)
xscale = ((params->src_scan_w - 1) << FP_SHIFT)
/(params->dst_w);
else
xscale = 1 << FP_SHIFT;
if (params->dst_h > 1)
yscale = ((params->src_scan_h - 1) << FP_SHIFT)
/(params->dst_h);
else
yscale = 1 << FP_SHIFT;
xscale_UV = xscale/uv_hscale;
yscale_UV = yscale/uv_vscale;
xscale = xscale_UV * uv_hscale;
yscale = yscale_UV * uv_vscale;
if (xscale != overlay->old_xscale || yscale != overlay->old_yscale)
scale_changed = true;
overlay->old_xscale = xscale;
overlay->old_yscale = yscale;
iowrite32(((yscale & FRACT_MASK) << 20) |
((xscale >> FP_SHIFT) << 16) |
((xscale & FRACT_MASK) << 3),
&regs->YRGBSCALE);
iowrite32(((yscale_UV & FRACT_MASK) << 20) |
((xscale_UV >> FP_SHIFT) << 16) |
((xscale_UV & FRACT_MASK) << 3),
&regs->UVSCALE);
iowrite32((((yscale >> FP_SHIFT) << 16) |
((yscale_UV >> FP_SHIFT) << 0)),
&regs->UVSCALEV);
if (scale_changed)
update_polyphase_filter(regs);
return scale_changed;
}
static void update_colorkey(struct intel_overlay *overlay,
struct overlay_registers __iomem *regs)
{
u32 key = overlay->color_key;
u32 flags;
flags = 0;
if (overlay->color_key_enabled)
flags |= DST_KEY_ENABLE;
switch (overlay->crtc->base.primary->fb->bits_per_pixel) {
case 8:
key = 0;
flags |= CLK_RGB8I_MASK;
break;
case 16:
if (overlay->crtc->base.primary->fb->depth == 15) {
key = RGB15_TO_COLORKEY(key);
flags |= CLK_RGB15_MASK;
} else {
key = RGB16_TO_COLORKEY(key);
flags |= CLK_RGB16_MASK;
}
break;
case 24:
case 32:
flags |= CLK_RGB24_MASK;
break;
}
iowrite32(key, &regs->DCLRKV);
iowrite32(flags, &regs->DCLRKM);
}
static u32 overlay_cmd_reg(struct put_image_params *params)
{
u32 cmd = OCMD_ENABLE | OCMD_BUF_TYPE_FRAME | OCMD_BUFFER0;
if (params->format & I915_OVERLAY_YUV_PLANAR) {
switch (params->format & I915_OVERLAY_DEPTH_MASK) {
case I915_OVERLAY_YUV422:
cmd |= OCMD_YUV_422_PLANAR;
break;
case I915_OVERLAY_YUV420:
cmd |= OCMD_YUV_420_PLANAR;
break;
case I915_OVERLAY_YUV411:
case I915_OVERLAY_YUV410:
cmd |= OCMD_YUV_410_PLANAR;
break;
}
} else {
switch (params->format & I915_OVERLAY_DEPTH_MASK) {
case I915_OVERLAY_YUV422:
cmd |= OCMD_YUV_422_PACKED;
break;
case I915_OVERLAY_YUV411:
cmd |= OCMD_YUV_411_PACKED;
break;
}
switch (params->format & I915_OVERLAY_SWAP_MASK) {
case I915_OVERLAY_NO_SWAP:
break;
case I915_OVERLAY_UV_SWAP:
cmd |= OCMD_UV_SWAP;
break;
case I915_OVERLAY_Y_SWAP:
cmd |= OCMD_Y_SWAP;
break;
case I915_OVERLAY_Y_AND_UV_SWAP:
cmd |= OCMD_Y_AND_UV_SWAP;
break;
}
}
return cmd;
}
static int intel_overlay_do_put_image(struct intel_overlay *overlay,
struct drm_i915_gem_object *new_bo,
struct put_image_params *params)
{
int ret, tmp_width;
struct overlay_registers __iomem *regs;
bool scale_changed = false;
struct drm_device *dev = overlay->dev;
u32 swidth, swidthsw, sheight, ostride;
enum pipe pipe = overlay->crtc->pipe;
WARN_ON(!mutex_is_locked(&dev->struct_mutex));
WARN_ON(!drm_modeset_is_locked(&dev->mode_config.connection_mutex));
ret = intel_overlay_release_old_vid(overlay);
if (ret != 0)
return ret;
ret = i915_gem_object_pin_to_display_plane(new_bo, 0,
&i915_ggtt_view_normal);
if (ret != 0)
return ret;
ret = i915_gem_object_put_fence(new_bo);
if (ret)
goto out_unpin;
if (!overlay->active) {
u32 oconfig;
regs = intel_overlay_map_regs(overlay);
if (!regs) {
ret = -ENOMEM;
goto out_unpin;
}
oconfig = OCONF_CC_OUT_8BIT;
if (IS_GEN4(overlay->dev))
oconfig |= OCONF_CSC_MODE_BT709;
oconfig |= pipe == 0 ?
OCONF_PIPE_A : OCONF_PIPE_B;
iowrite32(oconfig, &regs->OCONFIG);
intel_overlay_unmap_regs(overlay, regs);
ret = intel_overlay_on(overlay);
if (ret != 0)
goto out_unpin;
}
regs = intel_overlay_map_regs(overlay);
if (!regs) {
ret = -ENOMEM;
goto out_unpin;
}
iowrite32((params->dst_y << 16) | params->dst_x, &regs->DWINPOS);
iowrite32((params->dst_h << 16) | params->dst_w, &regs->DWINSZ);
if (params->format & I915_OVERLAY_YUV_PACKED)
tmp_width = packed_width_bytes(params->format, params->src_w);
else
tmp_width = params->src_w;
swidth = params->src_w;
swidthsw = calc_swidthsw(overlay->dev, params->offset_Y, tmp_width);
sheight = params->src_h;
iowrite32(i915_gem_obj_ggtt_offset(new_bo) + params->offset_Y, &regs->OBUF_0Y);
ostride = params->stride_Y;
if (params->format & I915_OVERLAY_YUV_PLANAR) {
int uv_hscale = uv_hsubsampling(params->format);
int uv_vscale = uv_vsubsampling(params->format);
u32 tmp_U, tmp_V;
swidth |= (params->src_w/uv_hscale) << 16;
tmp_U = calc_swidthsw(overlay->dev, params->offset_U,
params->src_w/uv_hscale);
tmp_V = calc_swidthsw(overlay->dev, params->offset_V,
params->src_w/uv_hscale);
swidthsw |= max_t(u32, tmp_U, tmp_V) << 16;
sheight |= (params->src_h/uv_vscale) << 16;
iowrite32(i915_gem_obj_ggtt_offset(new_bo) + params->offset_U, &regs->OBUF_0U);
iowrite32(i915_gem_obj_ggtt_offset(new_bo) + params->offset_V, &regs->OBUF_0V);
ostride |= params->stride_UV << 16;
}
iowrite32(swidth, &regs->SWIDTH);
iowrite32(swidthsw, &regs->SWIDTHSW);
iowrite32(sheight, &regs->SHEIGHT);
iowrite32(ostride, &regs->OSTRIDE);
scale_changed = update_scaling_factors(overlay, regs, params);
update_colorkey(overlay, regs);
iowrite32(overlay_cmd_reg(params), &regs->OCMD);
intel_overlay_unmap_regs(overlay, regs);
ret = intel_overlay_continue(overlay, scale_changed);
if (ret)
goto out_unpin;
i915_gem_track_fb(overlay->vid_bo, new_bo,
INTEL_FRONTBUFFER_OVERLAY(pipe));
overlay->old_vid_bo = overlay->vid_bo;
overlay->vid_bo = new_bo;
intel_frontbuffer_flip(dev,
INTEL_FRONTBUFFER_OVERLAY(pipe));
return 0;
out_unpin:
i915_gem_object_ggtt_unpin(new_bo);
return ret;
}
int intel_overlay_switch_off(struct intel_overlay *overlay)
{
struct overlay_registers __iomem *regs;
struct drm_device *dev = overlay->dev;
int ret;
WARN_ON(!mutex_is_locked(&dev->struct_mutex));
WARN_ON(!drm_modeset_is_locked(&dev->mode_config.connection_mutex));
ret = intel_overlay_recover_from_interrupt(overlay);
if (ret != 0)
return ret;
if (!overlay->active)
return 0;
ret = intel_overlay_release_old_vid(overlay);
if (ret != 0)
return ret;
regs = intel_overlay_map_regs(overlay);
iowrite32(0, &regs->OCMD);
intel_overlay_unmap_regs(overlay, regs);
ret = intel_overlay_off(overlay);
if (ret != 0)
return ret;
intel_overlay_off_tail(overlay);
return 0;
}
static int check_overlay_possible_on_crtc(struct intel_overlay *overlay,
struct intel_crtc *crtc)
{
if (!crtc->active)
return -EINVAL;
if (crtc->config->double_wide)
return -EINVAL;
return 0;
}
static void update_pfit_vscale_ratio(struct intel_overlay *overlay)
{
struct drm_device *dev = overlay->dev;
struct drm_i915_private *dev_priv = dev->dev_private;
u32 pfit_control = I915_READ(PFIT_CONTROL);
u32 ratio;
if (INTEL_INFO(dev)->gen >= 4) {
ratio = I915_READ(PFIT_PGM_RATIOS) >> PFIT_VERT_SCALE_SHIFT_965;
} else {
if (pfit_control & VERT_AUTO_SCALE)
ratio = I915_READ(PFIT_AUTO_RATIOS);
else
ratio = I915_READ(PFIT_PGM_RATIOS);
ratio >>= PFIT_VERT_SCALE_SHIFT;
}
overlay->pfit_vscale_ratio = ratio;
}
static int check_overlay_dst(struct intel_overlay *overlay,
struct drm_intel_overlay_put_image *rec)
{
struct drm_display_mode *mode = &overlay->crtc->base.mode;
if (rec->dst_x < mode->hdisplay &&
rec->dst_x + rec->dst_width <= mode->hdisplay &&
rec->dst_y < mode->vdisplay &&
rec->dst_y + rec->dst_height <= mode->vdisplay)
return 0;
else
return -EINVAL;
}
static int check_overlay_scaling(struct put_image_params *rec)
{
u32 tmp;
tmp = ((rec->src_scan_h << 16) / rec->dst_h) >> 16;
if (tmp > 7)
return -EINVAL;
tmp = ((rec->src_scan_w << 16) / rec->dst_w) >> 16;
if (tmp > 7)
return -EINVAL;
return 0;
}
static int check_overlay_src(struct drm_device *dev,
struct drm_intel_overlay_put_image *rec,
struct drm_i915_gem_object *new_bo)
{
int uv_hscale = uv_hsubsampling(rec->flags);
int uv_vscale = uv_vsubsampling(rec->flags);
u32 stride_mask;
int depth;
u32 tmp;
if (IS_845G(dev) || IS_I830(dev)) {
if (rec->src_height > IMAGE_MAX_HEIGHT_LEGACY ||
rec->src_width > IMAGE_MAX_WIDTH_LEGACY)
return -EINVAL;
} else {
if (rec->src_height > IMAGE_MAX_HEIGHT ||
rec->src_width > IMAGE_MAX_WIDTH)
return -EINVAL;
}
if (rec->src_height < N_VERT_Y_TAPS*4 ||
rec->src_width < N_HORIZ_Y_TAPS*4)
return -EINVAL;
switch (rec->flags & I915_OVERLAY_TYPE_MASK) {
case I915_OVERLAY_RGB:
return -EINVAL;
case I915_OVERLAY_YUV_PACKED:
if (uv_vscale != 1)
return -EINVAL;
depth = packed_depth_bytes(rec->flags);
if (depth < 0)
return depth;
rec->stride_UV = 0;
rec->offset_U = 0;
rec->offset_V = 0;
if (rec->offset_Y % depth)
return -EINVAL;
break;
case I915_OVERLAY_YUV_PLANAR:
if (uv_vscale < 0 || uv_hscale < 0)
return -EINVAL;
break;
default:
return -EINVAL;
}
if (rec->src_width % uv_hscale)
return -EINVAL;
if (IS_I830(dev) || IS_845G(dev))
stride_mask = 255;
else
stride_mask = 63;
if (rec->stride_Y & stride_mask || rec->stride_UV & stride_mask)
return -EINVAL;
if (IS_GEN4(dev) && rec->stride_Y < 512)
return -EINVAL;
tmp = (rec->flags & I915_OVERLAY_TYPE_MASK) == I915_OVERLAY_YUV_PLANAR ?
4096 : 8192;
if (rec->stride_Y > tmp || rec->stride_UV > 2*1024)
return -EINVAL;
switch (rec->flags & I915_OVERLAY_TYPE_MASK) {
case I915_OVERLAY_RGB:
case I915_OVERLAY_YUV_PACKED:
if (packed_width_bytes(rec->flags, rec->src_width) > rec->stride_Y)
return -EINVAL;
tmp = rec->stride_Y*rec->src_height;
if (rec->offset_Y + tmp > new_bo->base.size)
return -EINVAL;
break;
case I915_OVERLAY_YUV_PLANAR:
if (rec->src_width > rec->stride_Y)
return -EINVAL;
if (rec->src_width/uv_hscale > rec->stride_UV)
return -EINVAL;
tmp = rec->stride_Y * rec->src_height;
if (rec->offset_Y + tmp > new_bo->base.size)
return -EINVAL;
tmp = rec->stride_UV * (rec->src_height / uv_vscale);
if (rec->offset_U + tmp > new_bo->base.size ||
rec->offset_V + tmp > new_bo->base.size)
return -EINVAL;
break;
}
return 0;
}
static int intel_panel_fitter_pipe(struct drm_device *dev)
{
struct drm_i915_private *dev_priv = dev->dev_private;
u32 pfit_control;
if (INTEL_INFO(dev)->gen <= 3 && (IS_I830(dev) || !IS_MOBILE(dev)))
return -1;
pfit_control = I915_READ(PFIT_CONTROL);
if ((pfit_control & PFIT_ENABLE) == 0)
return -1;
if (IS_GEN4(dev))
return (pfit_control >> 29) & 0x3;
return 1;
}
int intel_overlay_put_image(struct drm_device *dev, void *data,
struct drm_file *file_priv)
{
struct drm_intel_overlay_put_image *put_image_rec = data;
struct drm_i915_private *dev_priv = dev->dev_private;
struct intel_overlay *overlay;
struct drm_crtc *drmmode_crtc;
struct intel_crtc *crtc;
struct drm_i915_gem_object *new_bo;
struct put_image_params *params;
int ret;
overlay = dev_priv->overlay;
if (!overlay) {
DRM_DEBUG("userspace bug: no overlay\n");
return -ENODEV;
}
if (!(put_image_rec->flags & I915_OVERLAY_ENABLE)) {
drm_modeset_lock_all(dev);
mutex_lock(&dev->struct_mutex);
ret = intel_overlay_switch_off(overlay);
mutex_unlock(&dev->struct_mutex);
drm_modeset_unlock_all(dev);
return ret;
}
params = kmalloc(sizeof(*params), GFP_KERNEL);
if (!params)
return -ENOMEM;
drmmode_crtc = drm_crtc_find(dev, put_image_rec->crtc_id);
if (!drmmode_crtc) {
ret = -ENOENT;
goto out_free;
}
crtc = to_intel_crtc(drmmode_crtc);
new_bo = to_intel_bo(drm_gem_object_lookup(dev, file_priv,
put_image_rec->bo_handle));
if (&new_bo->base == NULL) {
ret = -ENOENT;
goto out_free;
}
drm_modeset_lock_all(dev);
mutex_lock(&dev->struct_mutex);
if (new_bo->tiling_mode) {
DRM_DEBUG_KMS("buffer used for overlay image can not be tiled\n");
ret = -EINVAL;
goto out_unlock;
}
ret = intel_overlay_recover_from_interrupt(overlay);
if (ret != 0)
goto out_unlock;
if (overlay->crtc != crtc) {
struct drm_display_mode *mode = &crtc->base.mode;
ret = intel_overlay_switch_off(overlay);
if (ret != 0)
goto out_unlock;
ret = check_overlay_possible_on_crtc(overlay, crtc);
if (ret != 0)
goto out_unlock;
overlay->crtc = crtc;
crtc->overlay = overlay;
if (mode->hdisplay > 1024 &&
intel_panel_fitter_pipe(dev) == crtc->pipe) {
overlay->pfit_active = true;
update_pfit_vscale_ratio(overlay);
} else
overlay->pfit_active = false;
}
ret = check_overlay_dst(overlay, put_image_rec);
if (ret != 0)
goto out_unlock;
if (overlay->pfit_active) {
params->dst_y = ((((u32)put_image_rec->dst_y) << 12) /
overlay->pfit_vscale_ratio);
params->dst_h = ((((u32)put_image_rec->dst_height) << 12) /
overlay->pfit_vscale_ratio) + 1;
} else {
params->dst_y = put_image_rec->dst_y;
params->dst_h = put_image_rec->dst_height;
}
params->dst_x = put_image_rec->dst_x;
params->dst_w = put_image_rec->dst_width;
params->src_w = put_image_rec->src_width;
params->src_h = put_image_rec->src_height;
params->src_scan_w = put_image_rec->src_scan_width;
params->src_scan_h = put_image_rec->src_scan_height;
if (params->src_scan_h > params->src_h ||
params->src_scan_w > params->src_w) {
ret = -EINVAL;
goto out_unlock;
}
ret = check_overlay_src(dev, put_image_rec, new_bo);
if (ret != 0)
goto out_unlock;
params->format = put_image_rec->flags & ~I915_OVERLAY_FLAGS_MASK;
params->stride_Y = put_image_rec->stride_Y;
params->stride_UV = put_image_rec->stride_UV;
params->offset_Y = put_image_rec->offset_Y;
params->offset_U = put_image_rec->offset_U;
params->offset_V = put_image_rec->offset_V;
ret = check_overlay_scaling(params);
if (ret != 0)
goto out_unlock;
ret = intel_overlay_do_put_image(overlay, new_bo, params);
if (ret != 0)
goto out_unlock;
mutex_unlock(&dev->struct_mutex);
drm_modeset_unlock_all(dev);
kfree(params);
return 0;
out_unlock:
mutex_unlock(&dev->struct_mutex);
drm_modeset_unlock_all(dev);
drm_gem_object_unreference_unlocked(&new_bo->base);
out_free:
kfree(params);
return ret;
}
static void update_reg_attrs(struct intel_overlay *overlay,
struct overlay_registers __iomem *regs)
{
iowrite32((overlay->contrast << 18) | (overlay->brightness & 0xff),
&regs->OCLRC0);
iowrite32(overlay->saturation, &regs->OCLRC1);
}
static bool check_gamma_bounds(u32 gamma1, u32 gamma2)
{
int i;
if (gamma1 & 0xff000000 || gamma2 & 0xff000000)
return false;
for (i = 0; i < 3; i++) {
if (((gamma1 >> i*8) & 0xff) >= ((gamma2 >> i*8) & 0xff))
return false;
}
return true;
}
static bool check_gamma5_errata(u32 gamma5)
{
int i;
for (i = 0; i < 3; i++) {
if (((gamma5 >> i*8) & 0xff) == 0x80)
return false;
}
return true;
}
static int check_gamma(struct drm_intel_overlay_attrs *attrs)
{
if (!check_gamma_bounds(0, attrs->gamma0) ||
!check_gamma_bounds(attrs->gamma0, attrs->gamma1) ||
!check_gamma_bounds(attrs->gamma1, attrs->gamma2) ||
!check_gamma_bounds(attrs->gamma2, attrs->gamma3) ||
!check_gamma_bounds(attrs->gamma3, attrs->gamma4) ||
!check_gamma_bounds(attrs->gamma4, attrs->gamma5) ||
!check_gamma_bounds(attrs->gamma5, 0x00ffffff))
return -EINVAL;
if (!check_gamma5_errata(attrs->gamma5))
return -EINVAL;
return 0;
}
int intel_overlay_attrs(struct drm_device *dev, void *data,
struct drm_file *file_priv)
{
struct drm_intel_overlay_attrs *attrs = data;
struct drm_i915_private *dev_priv = dev->dev_private;
struct intel_overlay *overlay;
struct overlay_registers __iomem *regs;
int ret;
overlay = dev_priv->overlay;
if (!overlay) {
DRM_DEBUG("userspace bug: no overlay\n");
return -ENODEV;
}
drm_modeset_lock_all(dev);
mutex_lock(&dev->struct_mutex);
ret = -EINVAL;
if (!(attrs->flags & I915_OVERLAY_UPDATE_ATTRS)) {
attrs->color_key = overlay->color_key;
attrs->brightness = overlay->brightness;
attrs->contrast = overlay->contrast;
attrs->saturation = overlay->saturation;
if (!IS_GEN2(dev)) {
attrs->gamma0 = I915_READ(OGAMC0);
attrs->gamma1 = I915_READ(OGAMC1);
attrs->gamma2 = I915_READ(OGAMC2);
attrs->gamma3 = I915_READ(OGAMC3);
attrs->gamma4 = I915_READ(OGAMC4);
attrs->gamma5 = I915_READ(OGAMC5);
}
} else {
if (attrs->brightness < -128 || attrs->brightness > 127)
goto out_unlock;
if (attrs->contrast > 255)
goto out_unlock;
if (attrs->saturation > 1023)
goto out_unlock;
overlay->color_key = attrs->color_key;
overlay->brightness = attrs->brightness;
overlay->contrast = attrs->contrast;
overlay->saturation = attrs->saturation;
regs = intel_overlay_map_regs(overlay);
if (!regs) {
ret = -ENOMEM;
goto out_unlock;
}
update_reg_attrs(overlay, regs);
intel_overlay_unmap_regs(overlay, regs);
if (attrs->flags & I915_OVERLAY_UPDATE_GAMMA) {
if (IS_GEN2(dev))
goto out_unlock;
if (overlay->active) {
ret = -EBUSY;
goto out_unlock;
}
ret = check_gamma(attrs);
if (ret)
goto out_unlock;
I915_WRITE(OGAMC0, attrs->gamma0);
I915_WRITE(OGAMC1, attrs->gamma1);
I915_WRITE(OGAMC2, attrs->gamma2);
I915_WRITE(OGAMC3, attrs->gamma3);
I915_WRITE(OGAMC4, attrs->gamma4);
I915_WRITE(OGAMC5, attrs->gamma5);
}
}
overlay->color_key_enabled = (attrs->flags & I915_OVERLAY_DISABLE_DEST_COLORKEY) == 0;
ret = 0;
out_unlock:
mutex_unlock(&dev->struct_mutex);
drm_modeset_unlock_all(dev);
return ret;
}
void intel_setup_overlay(struct drm_device *dev)
{
struct drm_i915_private *dev_priv = dev->dev_private;
struct intel_overlay *overlay;
struct drm_i915_gem_object *reg_bo;
struct overlay_registers __iomem *regs;
int ret;
if (!HAS_OVERLAY(dev))
return;
overlay = kzalloc(sizeof(*overlay), GFP_KERNEL);
if (!overlay)
return;
mutex_lock(&dev->struct_mutex);
if (WARN_ON(dev_priv->overlay))
goto out_free;
overlay->dev = dev;
reg_bo = NULL;
if (!OVERLAY_NEEDS_PHYSICAL(dev))
reg_bo = i915_gem_object_create_stolen(dev, PAGE_SIZE);
if (reg_bo == NULL)
reg_bo = i915_gem_alloc_object(dev, PAGE_SIZE);
if (reg_bo == NULL)
goto out_free;
overlay->reg_bo = reg_bo;
if (OVERLAY_NEEDS_PHYSICAL(dev)) {
ret = i915_gem_object_attach_phys(reg_bo, PAGE_SIZE);
if (ret) {
DRM_ERROR("failed to attach phys overlay regs\n");
goto out_free_bo;
}
overlay->flip_addr = reg_bo->phys_handle->busaddr;
} else {
ret = i915_gem_obj_ggtt_pin(reg_bo, PAGE_SIZE, PIN_MAPPABLE);
if (ret) {
DRM_ERROR("failed to pin overlay register bo\n");
goto out_free_bo;
}
overlay->flip_addr = i915_gem_obj_ggtt_offset(reg_bo);
ret = i915_gem_object_set_to_gtt_domain(reg_bo, true);
if (ret) {
DRM_ERROR("failed to move overlay register bo into the GTT\n");
goto out_unpin_bo;
}
}
overlay->color_key = 0x0101fe;
overlay->color_key_enabled = true;
overlay->brightness = -19;
overlay->contrast = 75;
overlay->saturation = 146;
regs = intel_overlay_map_regs(overlay);
if (!regs)
goto out_unpin_bo;
memset_io(regs, 0, sizeof(struct overlay_registers));
update_polyphase_filter(regs);
update_reg_attrs(overlay, regs);
intel_overlay_unmap_regs(overlay, regs);
dev_priv->overlay = overlay;
mutex_unlock(&dev->struct_mutex);
DRM_INFO("initialized overlay support\n");
return;
out_unpin_bo:
if (!OVERLAY_NEEDS_PHYSICAL(dev))
i915_gem_object_ggtt_unpin(reg_bo);
out_free_bo:
drm_gem_object_unreference(&reg_bo->base);
out_free:
mutex_unlock(&dev->struct_mutex);
kfree(overlay);
return;
}
void intel_cleanup_overlay(struct drm_device *dev)
{
struct drm_i915_private *dev_priv = dev->dev_private;
if (!dev_priv->overlay)
return;
WARN_ON(dev_priv->overlay->active);
drm_gem_object_unreference_unlocked(&dev_priv->overlay->reg_bo->base);
kfree(dev_priv->overlay);
}
static struct overlay_registers __iomem *
intel_overlay_map_regs_atomic(struct intel_overlay *overlay)
{
struct drm_i915_private *dev_priv = overlay->dev->dev_private;
struct overlay_registers __iomem *regs;
if (OVERLAY_NEEDS_PHYSICAL(overlay->dev))
regs = (struct overlay_registers __iomem *)
overlay->reg_bo->phys_handle->vaddr;
else
regs = io_mapping_map_atomic_wc(dev_priv->gtt.mappable,
i915_gem_obj_ggtt_offset(overlay->reg_bo));
return regs;
}
static void intel_overlay_unmap_regs_atomic(struct intel_overlay *overlay,
struct overlay_registers __iomem *regs)
{
if (!OVERLAY_NEEDS_PHYSICAL(overlay->dev))
io_mapping_unmap_atomic(regs);
}
struct intel_overlay_error_state *
intel_overlay_capture_error_state(struct drm_device *dev)
{
struct drm_i915_private *dev_priv = dev->dev_private;
struct intel_overlay *overlay = dev_priv->overlay;
struct intel_overlay_error_state *error;
struct overlay_registers __iomem *regs;
if (!overlay || !overlay->active)
return NULL;
error = kmalloc(sizeof(*error), GFP_ATOMIC);
if (error == NULL)
return NULL;
error->dovsta = I915_READ(DOVSTA);
error->isr = I915_READ(ISR);
if (OVERLAY_NEEDS_PHYSICAL(overlay->dev))
error->base = (__force long)overlay->reg_bo->phys_handle->vaddr;
else
error->base = i915_gem_obj_ggtt_offset(overlay->reg_bo);
regs = intel_overlay_map_regs_atomic(overlay);
if (!regs)
goto err;
memcpy_fromio(&error->regs, regs, sizeof(struct overlay_registers));
intel_overlay_unmap_regs_atomic(overlay, regs);
return error;
err:
kfree(error);
return NULL;
}
void
intel_overlay_print_error_state(struct drm_i915_error_state_buf *m,
struct intel_overlay_error_state *error)
{
i915_error_printf(m, "Overlay, status: 0x%08x, interrupt: 0x%08x\n",
error->dovsta, error->isr);
i915_error_printf(m, " Register file at 0x%08lx:\n",
error->base);
#define P(x) i915_error_printf(m, " " #x ": 0x%08x\n", error->regs.x)
P(OBUF_0Y);
P(OBUF_1Y);
P(OBUF_0U);
P(OBUF_0V);
P(OBUF_1U);
P(OBUF_1V);
P(OSTRIDE);
P(YRGB_VPH);
P(UV_VPH);
P(HORZ_PH);
P(INIT_PHS);
P(DWINPOS);
P(DWINSZ);
P(SWIDTH);
P(SWIDTHSW);
P(SHEIGHT);
P(YRGBSCALE);
P(UVSCALE);
P(OCLRC0);
P(OCLRC1);
P(DCLRKV);
P(DCLRKM);
P(SCLRKVH);
P(SCLRKVL);
P(SCLRKEN);
P(OCONFIG);
P(OCMD);
P(OSTART_0Y);
P(OSTART_1Y);
P(OSTART_0U);
P(OSTART_0V);
P(OSTART_1U);
P(OSTART_1V);
P(OTILEOFF_0Y);
P(OTILEOFF_1Y);
P(OTILEOFF_0U);
P(OTILEOFF_0V);
P(OTILEOFF_1U);
P(OTILEOFF_1V);
P(FASTHSCALE);
P(UVSCALEV);
#undef P
}
