static struct overlay_registers *
intel_overlay_map_regs(struct intel_overlay *overlay)
{
drm_i915_private_t *dev_priv = overlay->dev->dev_private;
struct overlay_registers *regs;
if (OVERLAY_NEEDS_PHYSICAL(overlay->dev))
regs = overlay->reg_bo->phys_obj->handle->vaddr;
else
regs = io_mapping_map_wc(dev_priv->mm.gtt_mapping,
overlay->reg_bo->gtt_offset);
return regs;
}
static void intel_overlay_unmap_regs(struct intel_overlay *overlay,
struct overlay_registers *regs)
{
if (!OVERLAY_NEEDS_PHYSICAL(overlay->dev))
io_mapping_unmap(regs);
}
static int intel_overlay_do_wait_request(struct intel_overlay *overlay,
struct drm_i915_gem_request *request,
void (*tail)(struct intel_overlay *))
{
struct drm_device *dev = overlay->dev;
drm_i915_private_t *dev_priv = dev->dev_private;
int ret;
BUG_ON(overlay->last_flip_req);
ret = i915_add_request(LP_RING(dev_priv), NULL, request);
if (ret) {
kfree(request);
return ret;
}
overlay->last_flip_req = request->seqno;
overlay->flip_tail = tail;
ret = i915_wait_request(LP_RING(dev_priv), overlay->last_flip_req);
if (ret)
return ret;
overlay->last_flip_req = 0;
return 0;
}
static int
i830_activate_pipe_a(struct drm_device *dev)
{
drm_i915_private_t *dev_priv = dev->dev_private;
struct intel_crtc *crtc;
struct drm_crtc_helper_funcs *crtc_funcs;
struct drm_display_mode vesa_640x480 = {
DRM_MODE("640x480", DRM_MODE_TYPE_DRIVER, 25175, 640, 656,
752, 800, 0, 480, 489, 492, 525, 0,
DRM_MODE_FLAG_NHSYNC | DRM_MODE_FLAG_NVSYNC)
}, *mode;
crtc = to_intel_crtc(dev_priv->pipe_to_crtc_mapping[0]);
if (crtc->dpms_mode == DRM_MODE_DPMS_ON)
return 0;
if (I915_READ(_PIPEACONF) & PIPECONF_ENABLE)
return 0;
crtc_funcs = crtc->base.helper_private;
if (crtc_funcs->dpms == NULL)
return 0;
DRM_DEBUG_DRIVER("Enabling pipe A in order to enable overlay\n");
mode = drm_mode_duplicate(dev, &vesa_640x480);
drm_mode_set_crtcinfo(mode, CRTC_INTERLACE_HALVE_V);
if(!drm_crtc_helper_set_mode(&crtc->base, mode,
crtc->base.x, crtc->base.y,
crtc->base.fb))
return 0;
crtc_funcs->dpms(&crtc->base, DRM_MODE_DPMS_ON);
return 1;
}
static void
i830_deactivate_pipe_a(struct drm_device *dev)
{
drm_i915_private_t *dev_priv = dev->dev_private;
struct drm_crtc *crtc = dev_priv->pipe_to_crtc_mapping[0];
struct drm_crtc_helper_funcs *crtc_funcs = crtc->helper_private;
crtc_funcs->dpms(crtc, DRM_MODE_DPMS_OFF);
}
static int intel_overlay_on(struct intel_overlay *overlay)
{
struct drm_device *dev = overlay->dev;
struct drm_i915_private *dev_priv = dev->dev_private;
struct drm_i915_gem_request *request;
int pipe_a_quirk = 0;
int ret;
BUG_ON(overlay->active);
overlay->active = 1;
if (IS_I830(dev)) {
pipe_a_quirk = i830_activate_pipe_a(dev);
if (pipe_a_quirk < 0)
return pipe_a_quirk;
}
request = kzalloc(sizeof(*request), GFP_KERNEL);
if (request == NULL) {
ret = -ENOMEM;
goto out;
}
ret = BEGIN_LP_RING(4);
if (ret) {
kfree(request);
goto out;
}
OUT_RING(MI_OVERLAY_FLIP | MI_OVERLAY_ON);
OUT_RING(overlay->flip_addr | OFC_UPDATE);
OUT_RING(MI_WAIT_FOR_EVENT | MI_WAIT_FOR_OVERLAY_FLIP);
OUT_RING(MI_NOOP);
ADVANCE_LP_RING();
ret = intel_overlay_do_wait_request(overlay, request, NULL);
out:
if (pipe_a_quirk)
i830_deactivate_pipe_a(dev);
return ret;
}
static int intel_overlay_continue(struct intel_overlay *overlay,
bool load_polyphase_filter)
{
struct drm_device *dev = overlay->dev;
drm_i915_private_t *dev_priv = dev->dev_private;
struct drm_i915_gem_request *request;
u32 flip_addr = overlay->flip_addr;
u32 tmp;
int ret;
BUG_ON(!overlay->active);
request = kzalloc(sizeof(*request), GFP_KERNEL);
if (request == NULL)
return -ENOMEM;
if (load_polyphase_filter)
flip_addr |= OFC_UPDATE;
tmp = I915_READ(DOVSTA);
if (tmp & (1 << 17))
DRM_DEBUG("overlay underrun, DOVSTA: %x\n", tmp);
ret = BEGIN_LP_RING(2);
if (ret) {
kfree(request);
return ret;
}
OUT_RING(MI_OVERLAY_FLIP | MI_OVERLAY_CONTINUE);
OUT_RING(flip_addr);
ADVANCE_LP_RING();
ret = i915_add_request(LP_RING(dev_priv), NULL, request);
if (ret) {
kfree(request);
return ret;
}
overlay->last_flip_req = request->seqno;
return 0;
}
static void intel_overlay_release_old_vid_tail(struct intel_overlay *overlay)
{
struct drm_i915_gem_object *obj = overlay->old_vid_bo;
i915_gem_object_unpin(obj);
drm_gem_object_unreference(&obj->base);
overlay->old_vid_bo = NULL;
}
static void intel_overlay_off_tail(struct intel_overlay *overlay)
{
struct drm_i915_gem_object *obj = overlay->vid_bo;
BUG_ON(!overlay->vid_bo);
i915_gem_object_unpin(obj);
drm_gem_object_unreference(&obj->base);
overlay->vid_bo = NULL;
overlay->crtc->overlay = NULL;
overlay->crtc = NULL;
overlay->active = 0;
}
static int intel_overlay_off(struct intel_overlay *overlay)
{
struct drm_device *dev = overlay->dev;
struct drm_i915_private *dev_priv = dev->dev_private;
u32 flip_addr = overlay->flip_addr;
struct drm_i915_gem_request *request;
int ret;
BUG_ON(!overlay->active);
request = kzalloc(sizeof(*request), GFP_KERNEL);
if (request == NULL)
return -ENOMEM;
flip_addr |= OFC_UPDATE;
ret = BEGIN_LP_RING(6);
if (ret) {
kfree(request);
return ret;
}
OUT_RING(MI_OVERLAY_FLIP | MI_OVERLAY_CONTINUE);
OUT_RING(flip_addr);
OUT_RING(MI_WAIT_FOR_EVENT | MI_WAIT_FOR_OVERLAY_FLIP);
OUT_RING(MI_OVERLAY_FLIP | MI_OVERLAY_OFF);
OUT_RING(flip_addr);
OUT_RING(MI_WAIT_FOR_EVENT | MI_WAIT_FOR_OVERLAY_FLIP);
ADVANCE_LP_RING();
return intel_overlay_do_wait_request(overlay, request,
intel_overlay_off_tail);
}
static int intel_overlay_recover_from_interrupt(struct intel_overlay *overlay)
{
struct drm_device *dev = overlay->dev;
drm_i915_private_t *dev_priv = dev->dev_private;
int ret;
if (overlay->last_flip_req == 0)
return 0;
ret = i915_wait_request(LP_RING(dev_priv), overlay->last_flip_req);
if (ret)
return ret;
if (overlay->flip_tail)
overlay->flip_tail(overlay);
overlay->last_flip_req = 0;
return 0;
}
static int intel_overlay_release_old_vid(struct intel_overlay *overlay)
{
struct drm_device *dev = overlay->dev;
drm_i915_private_t *dev_priv = dev->dev_private;
int ret;
if (!overlay->old_vid_bo)
return 0;
if (I915_READ(ISR) & I915_OVERLAY_PLANE_FLIP_PENDING_INTERRUPT) {
struct drm_i915_gem_request *request;
request = kzalloc(sizeof(*request), GFP_KERNEL);
if (request == NULL)
return -ENOMEM;
ret = BEGIN_LP_RING(2);
if (ret) {
kfree(request);
return ret;
}
OUT_RING(MI_WAIT_FOR_EVENT | MI_WAIT_FOR_OVERLAY_FLIP);
OUT_RING(MI_NOOP);
ADVANCE_LP_RING();
ret = intel_overlay_do_wait_request(overlay, request,
intel_overlay_release_old_vid_tail);
if (ret)
return ret;
}
intel_overlay_release_old_vid_tail(overlay);
return 0;
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
ret -=1;
return ret << 2;
}
static void update_polyphase_filter(struct overlay_registers *regs)
{
memcpy(regs->Y_HCOEFS, y_static_hcoeffs, sizeof(y_static_hcoeffs));
memcpy(regs->UV_HCOEFS, uv_static_hcoeffs, sizeof(uv_static_hcoeffs));
}
static bool update_scaling_factors(struct intel_overlay *overlay,
struct overlay_registers *regs,
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
regs->YRGBSCALE = (((yscale & FRACT_MASK) << 20) |
((xscale >> FP_SHIFT) << 16) |
((xscale & FRACT_MASK) << 3));
regs->UVSCALE = (((yscale_UV & FRACT_MASK) << 20) |
((xscale_UV >> FP_SHIFT) << 16) |
((xscale_UV & FRACT_MASK) << 3));
regs->UVSCALEV = ((((yscale >> FP_SHIFT) << 16) |
((yscale_UV >> FP_SHIFT) << 0)));
if (scale_changed)
update_polyphase_filter(regs);
return scale_changed;
}
static void update_colorkey(struct intel_overlay *overlay,
struct overlay_registers *regs)
{
u32 key = overlay->color_key;
switch (overlay->crtc->base.fb->bits_per_pixel) {
case 8:
regs->DCLRKV = 0;
regs->DCLRKM = CLK_RGB8I_MASK | DST_KEY_ENABLE;
break;
case 16:
if (overlay->crtc->base.fb->depth == 15) {
regs->DCLRKV = RGB15_TO_COLORKEY(key);
regs->DCLRKM = CLK_RGB15_MASK | DST_KEY_ENABLE;
} else {
regs->DCLRKV = RGB16_TO_COLORKEY(key);
regs->DCLRKM = CLK_RGB16_MASK | DST_KEY_ENABLE;
}
break;
case 24:
case 32:
regs->DCLRKV = key;
regs->DCLRKM = CLK_RGB24_MASK | DST_KEY_ENABLE;
break;
}
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
struct overlay_registers *regs;
bool scale_changed = false;
struct drm_device *dev = overlay->dev;
BUG_ON(!mutex_is_locked(&dev->struct_mutex));
BUG_ON(!mutex_is_locked(&dev->mode_config.mutex));
BUG_ON(!overlay);
ret = intel_overlay_release_old_vid(overlay);
if (ret != 0)
return ret;
ret = i915_gem_object_pin(new_bo, PAGE_SIZE, true);
if (ret != 0)
return ret;
ret = i915_gem_object_set_to_gtt_domain(new_bo, 0);
if (ret != 0)
goto out_unpin;
ret = i915_gem_object_put_fence(new_bo);
if (ret)
goto out_unpin;
if (!overlay->active) {
regs = intel_overlay_map_regs(overlay);
if (!regs) {
ret = -ENOMEM;
goto out_unpin;
}
regs->OCONFIG = OCONF_CC_OUT_8BIT;
if (IS_GEN4(overlay->dev))
regs->OCONFIG |= OCONF_CSC_MODE_BT709;
regs->OCONFIG |= overlay->crtc->pipe == 0 ?
OCONF_PIPE_A : OCONF_PIPE_B;
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
regs->DWINPOS = (params->dst_y << 16) | params->dst_x;
regs->DWINSZ = (params->dst_h << 16) | params->dst_w;
if (params->format & I915_OVERLAY_YUV_PACKED)
tmp_width = packed_width_bytes(params->format, params->src_w);
else
tmp_width = params->src_w;
regs->SWIDTH = params->src_w;
regs->SWIDTHSW = calc_swidthsw(overlay->dev,
params->offset_Y, tmp_width);
regs->SHEIGHT = params->src_h;
regs->OBUF_0Y = new_bo->gtt_offset + params-> offset_Y;
regs->OSTRIDE = params->stride_Y;
if (params->format & I915_OVERLAY_YUV_PLANAR) {
int uv_hscale = uv_hsubsampling(params->format);
int uv_vscale = uv_vsubsampling(params->format);
u32 tmp_U, tmp_V;
regs->SWIDTH |= (params->src_w/uv_hscale) << 16;
tmp_U = calc_swidthsw(overlay->dev, params->offset_U,
params->src_w/uv_hscale);
tmp_V = calc_swidthsw(overlay->dev, params->offset_V,
params->src_w/uv_hscale);
regs->SWIDTHSW |= max_t(u32, tmp_U, tmp_V) << 16;
regs->SHEIGHT |= (params->src_h/uv_vscale) << 16;
regs->OBUF_0U = new_bo->gtt_offset + params->offset_U;
regs->OBUF_0V = new_bo->gtt_offset + params->offset_V;
regs->OSTRIDE |= params->stride_UV << 16;
}
scale_changed = update_scaling_factors(overlay, regs, params);
update_colorkey(overlay, regs);
regs->OCMD = overlay_cmd_reg(params);
intel_overlay_unmap_regs(overlay, regs);
ret = intel_overlay_continue(overlay, scale_changed);
if (ret)
goto out_unpin;
overlay->old_vid_bo = overlay->vid_bo;
overlay->vid_bo = new_bo;
return 0;
out_unpin:
i915_gem_object_unpin(new_bo);
return ret;
}
int intel_overlay_switch_off(struct intel_overlay *overlay)
{
struct overlay_registers *regs;
struct drm_device *dev = overlay->dev;
int ret;
BUG_ON(!mutex_is_locked(&dev->struct_mutex));
BUG_ON(!mutex_is_locked(&dev->mode_config.mutex));
ret = intel_overlay_recover_from_interrupt(overlay);
if (ret != 0)
return ret;
if (!overlay->active)
return 0;
ret = intel_overlay_release_old_vid(overlay);
if (ret != 0)
return ret;
regs = intel_overlay_map_regs(overlay);
regs->OCMD = 0;
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
drm_i915_private_t *dev_priv = overlay->dev->dev_private;
if (!crtc->active)
return -EINVAL;
if (INTEL_INFO(overlay->dev)->gen < 4 &&
(I915_READ(PIPECONF(crtc->pipe)) & (PIPECONF_DOUBLE_WIDE | PIPECONF_ENABLE)) != PIPECONF_ENABLE)
return -EINVAL;
return 0;
}
static void update_pfit_vscale_ratio(struct intel_overlay *overlay)
{
struct drm_device *dev = overlay->dev;
drm_i915_private_t *dev_priv = dev->dev_private;
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
if (rec->dst_x < mode->crtc_hdisplay &&
rec->dst_x + rec->dst_width <= mode->crtc_hdisplay &&
rec->dst_y < mode->crtc_vdisplay &&
rec->dst_y + rec->dst_height <= mode->crtc_vdisplay)
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
if (IS_I830(dev))
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
drm_i915_private_t *dev_priv = dev->dev_private;
struct intel_overlay *overlay;
struct drm_mode_object *drmmode_obj;
struct intel_crtc *crtc;
struct drm_i915_gem_object *new_bo;
struct put_image_params *params;
int ret;
if (!dev_priv) {
DRM_ERROR("called with no initialization\n");
return -EINVAL;
}
overlay = dev_priv->overlay;
if (!overlay) {
DRM_DEBUG("userspace bug: no overlay\n");
return -ENODEV;
}
if (!(put_image_rec->flags & I915_OVERLAY_ENABLE)) {
mutex_lock(&dev->mode_config.mutex);
mutex_lock(&dev->struct_mutex);
ret = intel_overlay_switch_off(overlay);
mutex_unlock(&dev->struct_mutex);
mutex_unlock(&dev->mode_config.mutex);
return ret;
}
params = kmalloc(sizeof(struct put_image_params), GFP_KERNEL);
if (!params)
return -ENOMEM;
drmmode_obj = drm_mode_object_find(dev, put_image_rec->crtc_id,
DRM_MODE_OBJECT_CRTC);
if (!drmmode_obj) {
ret = -ENOENT;
goto out_free;
}
crtc = to_intel_crtc(obj_to_crtc(drmmode_obj));
new_bo = to_intel_bo(drm_gem_object_lookup(dev, file_priv,
put_image_rec->bo_handle));
if (&new_bo->base == NULL) {
ret = -ENOENT;
goto out_free;
}
mutex_lock(&dev->mode_config.mutex);
mutex_lock(&dev->struct_mutex);
if (new_bo->tiling_mode) {
DRM_ERROR("buffer used for overlay image can not be tiled\n");
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
overlay->pfit_active = 1;
update_pfit_vscale_ratio(overlay);
} else
overlay->pfit_active = 0;
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
mutex_unlock(&dev->mode_config.mutex);
kfree(params);
return 0;
out_unlock:
mutex_unlock(&dev->struct_mutex);
mutex_unlock(&dev->mode_config.mutex);
drm_gem_object_unreference_unlocked(&new_bo->base);
out_free:
kfree(params);
return ret;
}
static void update_reg_attrs(struct intel_overlay *overlay,
struct overlay_registers *regs)
{
regs->OCLRC0 = (overlay->contrast << 18) | (overlay->brightness & 0xff);
regs->OCLRC1 = overlay->saturation;
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
drm_i915_private_t *dev_priv = dev->dev_private;
struct intel_overlay *overlay;
struct overlay_registers *regs;
int ret;
if (!dev_priv) {
DRM_ERROR("called with no initialization\n");
return -EINVAL;
}
overlay = dev_priv->overlay;
if (!overlay) {
DRM_DEBUG("userspace bug: no overlay\n");
return -ENODEV;
}
mutex_lock(&dev->mode_config.mutex);
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
ret = 0;
out_unlock:
mutex_unlock(&dev->struct_mutex);
mutex_unlock(&dev->mode_config.mutex);
return ret;
}
void intel_setup_overlay(struct drm_device *dev)
{
drm_i915_private_t *dev_priv = dev->dev_private;
struct intel_overlay *overlay;
struct drm_i915_gem_object *reg_bo;
struct overlay_registers *regs;
int ret;
if (!HAS_OVERLAY(dev))
return;
overlay = kzalloc(sizeof(struct intel_overlay), GFP_KERNEL);
if (!overlay)
return;
mutex_lock(&dev->struct_mutex);
if (WARN_ON(dev_priv->overlay))
goto out_free;
overlay->dev = dev;
reg_bo = i915_gem_alloc_object(dev, PAGE_SIZE);
if (!reg_bo)
goto out_free;
overlay->reg_bo = reg_bo;
if (OVERLAY_NEEDS_PHYSICAL(dev)) {
ret = i915_gem_attach_phys_object(dev, reg_bo,
I915_GEM_PHYS_OVERLAY_REGS,
PAGE_SIZE);
if (ret) {
DRM_ERROR("failed to attach phys overlay regs\n");
goto out_free_bo;
}
overlay->flip_addr = reg_bo->phys_obj->handle->busaddr;
} else {
ret = i915_gem_object_pin(reg_bo, PAGE_SIZE, true);
if (ret) {
DRM_ERROR("failed to pin overlay register bo\n");
goto out_free_bo;
}
overlay->flip_addr = reg_bo->gtt_offset;
ret = i915_gem_object_set_to_gtt_domain(reg_bo, true);
if (ret) {
DRM_ERROR("failed to move overlay register bo into the GTT\n");
goto out_unpin_bo;
}
}
overlay->color_key = 0x0101fe;
overlay->brightness = -19;
overlay->contrast = 75;
overlay->saturation = 146;
regs = intel_overlay_map_regs(overlay);
if (!regs)
goto out_unpin_bo;
memset(regs, 0, sizeof(struct overlay_registers));
update_polyphase_filter(regs);
update_reg_attrs(overlay, regs);
intel_overlay_unmap_regs(overlay, regs);
dev_priv->overlay = overlay;
mutex_unlock(&dev->struct_mutex);
DRM_INFO("initialized overlay support\n");
return;
out_unpin_bo:
if (!OVERLAY_NEEDS_PHYSICAL(dev))
i915_gem_object_unpin(reg_bo);
out_free_bo:
drm_gem_object_unreference(&reg_bo->base);
out_free:
mutex_unlock(&dev->struct_mutex);
kfree(overlay);
return;
}
void intel_cleanup_overlay(struct drm_device *dev)
{
drm_i915_private_t *dev_priv = dev->dev_private;
if (!dev_priv->overlay)
return;
BUG_ON(dev_priv->overlay->active);
drm_gem_object_unreference_unlocked(&dev_priv->overlay->reg_bo->base);
kfree(dev_priv->overlay);
}
static struct overlay_registers *
intel_overlay_map_regs_atomic(struct intel_overlay *overlay)
{
drm_i915_private_t *dev_priv = overlay->dev->dev_private;
struct overlay_registers *regs;
if (OVERLAY_NEEDS_PHYSICAL(overlay->dev))
regs = overlay->reg_bo->phys_obj->handle->vaddr;
else
regs = io_mapping_map_atomic_wc(dev_priv->mm.gtt_mapping,
overlay->reg_bo->gtt_offset);
return regs;
}
static void intel_overlay_unmap_regs_atomic(struct intel_overlay *overlay,
struct overlay_registers *regs)
{
if (!OVERLAY_NEEDS_PHYSICAL(overlay->dev))
io_mapping_unmap_atomic(regs);
}
struct intel_overlay_error_state *
intel_overlay_capture_error_state(struct drm_device *dev)
{
drm_i915_private_t *dev_priv = dev->dev_private;
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
error->base = (long) overlay->reg_bo->phys_obj->handle->vaddr;
else
error->base = (long) overlay->reg_bo->gtt_offset;
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
intel_overlay_print_error_state(struct seq_file *m, struct intel_overlay_error_state *error)
{
seq_printf(m, "Overlay, status: 0x%08x, interrupt: 0x%08x\n",
error->dovsta, error->isr);
seq_printf(m, " Register file at 0x%08lx:\n",
error->base);
#define P(x) seq_printf(m, " " #x ": 0x%08x\n", error->regs.x)
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
