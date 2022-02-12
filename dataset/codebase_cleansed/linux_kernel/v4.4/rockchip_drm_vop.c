static inline void vop_writel(struct vop *vop, uint32_t offset, uint32_t v)
{
writel(v, vop->regs + offset);
vop->regsbak[offset >> 2] = v;
}
static inline uint32_t vop_readl(struct vop *vop, uint32_t offset)
{
return readl(vop->regs + offset);
}
static inline uint32_t vop_read_reg(struct vop *vop, uint32_t base,
const struct vop_reg *reg)
{
return (vop_readl(vop, base + reg->offset) >> reg->shift) & reg->mask;
}
static inline void vop_cfg_done(struct vop *vop)
{
writel(0x01, vop->regs + REG_CFG_DONE);
}
static inline void vop_mask_write(struct vop *vop, uint32_t offset,
uint32_t mask, uint32_t v)
{
if (mask) {
uint32_t cached_val = vop->regsbak[offset >> 2];
cached_val = (cached_val & ~mask) | v;
writel(cached_val, vop->regs + offset);
vop->regsbak[offset >> 2] = cached_val;
}
}
static inline void vop_mask_write_relaxed(struct vop *vop, uint32_t offset,
uint32_t mask, uint32_t v)
{
if (mask) {
uint32_t cached_val = vop->regsbak[offset >> 2];
cached_val = (cached_val & ~mask) | v;
writel_relaxed(cached_val, vop->regs + offset);
vop->regsbak[offset >> 2] = cached_val;
}
}
static bool has_rb_swapped(uint32_t format)
{
switch (format) {
case DRM_FORMAT_XBGR8888:
case DRM_FORMAT_ABGR8888:
case DRM_FORMAT_BGR888:
case DRM_FORMAT_BGR565:
return true;
default:
return false;
}
}
static enum vop_data_format vop_convert_format(uint32_t format)
{
switch (format) {
case DRM_FORMAT_XRGB8888:
case DRM_FORMAT_ARGB8888:
case DRM_FORMAT_XBGR8888:
case DRM_FORMAT_ABGR8888:
return VOP_FMT_ARGB8888;
case DRM_FORMAT_RGB888:
case DRM_FORMAT_BGR888:
return VOP_FMT_RGB888;
case DRM_FORMAT_RGB565:
case DRM_FORMAT_BGR565:
return VOP_FMT_RGB565;
case DRM_FORMAT_NV12:
return VOP_FMT_YUV420SP;
case DRM_FORMAT_NV16:
return VOP_FMT_YUV422SP;
case DRM_FORMAT_NV24:
return VOP_FMT_YUV444SP;
default:
DRM_ERROR("unsupport format[%08x]\n", format);
return -EINVAL;
}
}
static bool is_yuv_support(uint32_t format)
{
switch (format) {
case DRM_FORMAT_NV12:
case DRM_FORMAT_NV16:
case DRM_FORMAT_NV24:
return true;
default:
return false;
}
}
static bool is_alpha_support(uint32_t format)
{
switch (format) {
case DRM_FORMAT_ARGB8888:
case DRM_FORMAT_ABGR8888:
return true;
default:
return false;
}
}
static uint16_t scl_vop_cal_scale(enum scale_mode mode, uint32_t src,
uint32_t dst, bool is_horizontal,
int vsu_mode, int *vskiplines)
{
uint16_t val = 1 << SCL_FT_DEFAULT_FIXPOINT_SHIFT;
if (is_horizontal) {
if (mode == SCALE_UP)
val = GET_SCL_FT_BIC(src, dst);
else if (mode == SCALE_DOWN)
val = GET_SCL_FT_BILI_DN(src, dst);
} else {
if (mode == SCALE_UP) {
if (vsu_mode == SCALE_UP_BIL)
val = GET_SCL_FT_BILI_UP(src, dst);
else
val = GET_SCL_FT_BIC(src, dst);
} else if (mode == SCALE_DOWN) {
if (vskiplines) {
*vskiplines = scl_get_vskiplines(src, dst);
val = scl_get_bili_dn_vskip(src, dst,
*vskiplines);
} else {
val = GET_SCL_FT_BILI_DN(src, dst);
}
}
}
return val;
}
static void scl_vop_cal_scl_fac(struct vop *vop, const struct vop_win_data *win,
uint32_t src_w, uint32_t src_h, uint32_t dst_w,
uint32_t dst_h, uint32_t pixel_format)
{
uint16_t yrgb_hor_scl_mode, yrgb_ver_scl_mode;
uint16_t cbcr_hor_scl_mode = SCALE_NONE;
uint16_t cbcr_ver_scl_mode = SCALE_NONE;
int hsub = drm_format_horz_chroma_subsampling(pixel_format);
int vsub = drm_format_vert_chroma_subsampling(pixel_format);
bool is_yuv = is_yuv_support(pixel_format);
uint16_t cbcr_src_w = src_w / hsub;
uint16_t cbcr_src_h = src_h / vsub;
uint16_t vsu_mode;
uint16_t lb_mode;
uint32_t val;
int vskiplines;
if (dst_w > 3840) {
DRM_ERROR("Maximum destination width (3840) exceeded\n");
return;
}
yrgb_hor_scl_mode = scl_get_scl_mode(src_w, dst_w);
yrgb_ver_scl_mode = scl_get_scl_mode(src_h, dst_h);
if (is_yuv) {
cbcr_hor_scl_mode = scl_get_scl_mode(cbcr_src_w, dst_w);
cbcr_ver_scl_mode = scl_get_scl_mode(cbcr_src_h, dst_h);
if (cbcr_hor_scl_mode == SCALE_DOWN)
lb_mode = scl_vop_cal_lb_mode(dst_w, true);
else
lb_mode = scl_vop_cal_lb_mode(cbcr_src_w, true);
} else {
if (yrgb_hor_scl_mode == SCALE_DOWN)
lb_mode = scl_vop_cal_lb_mode(dst_w, false);
else
lb_mode = scl_vop_cal_lb_mode(src_w, false);
}
VOP_SCL_SET(vop, win, lb_mode, lb_mode);
if (lb_mode == LB_RGB_3840X2) {
if (yrgb_ver_scl_mode != SCALE_NONE) {
DRM_ERROR("ERROR : not allow yrgb ver scale\n");
return;
}
if (cbcr_ver_scl_mode != SCALE_NONE) {
DRM_ERROR("ERROR : not allow cbcr ver scale\n");
return;
}
vsu_mode = SCALE_UP_BIL;
} else if (lb_mode == LB_RGB_2560X4) {
vsu_mode = SCALE_UP_BIL;
} else {
vsu_mode = SCALE_UP_BIC;
}
val = scl_vop_cal_scale(yrgb_hor_scl_mode, src_w, dst_w,
true, 0, NULL);
VOP_SCL_SET(vop, win, scale_yrgb_x, val);
val = scl_vop_cal_scale(yrgb_ver_scl_mode, src_h, dst_h,
false, vsu_mode, &vskiplines);
VOP_SCL_SET(vop, win, scale_yrgb_y, val);
VOP_SCL_SET(vop, win, vsd_yrgb_gt4, vskiplines == 4);
VOP_SCL_SET(vop, win, vsd_yrgb_gt2, vskiplines == 2);
VOP_SCL_SET(vop, win, yrgb_hor_scl_mode, yrgb_hor_scl_mode);
VOP_SCL_SET(vop, win, yrgb_ver_scl_mode, yrgb_ver_scl_mode);
VOP_SCL_SET(vop, win, yrgb_hsd_mode, SCALE_DOWN_BIL);
VOP_SCL_SET(vop, win, yrgb_vsd_mode, SCALE_DOWN_BIL);
VOP_SCL_SET(vop, win, yrgb_vsu_mode, vsu_mode);
if (is_yuv) {
val = scl_vop_cal_scale(cbcr_hor_scl_mode, cbcr_src_w,
dst_w, true, 0, NULL);
VOP_SCL_SET(vop, win, scale_cbcr_x, val);
val = scl_vop_cal_scale(cbcr_ver_scl_mode, cbcr_src_h,
dst_h, false, vsu_mode, &vskiplines);
VOP_SCL_SET(vop, win, scale_cbcr_y, val);
VOP_SCL_SET(vop, win, vsd_cbcr_gt4, vskiplines == 4);
VOP_SCL_SET(vop, win, vsd_cbcr_gt2, vskiplines == 2);
VOP_SCL_SET(vop, win, cbcr_hor_scl_mode, cbcr_hor_scl_mode);
VOP_SCL_SET(vop, win, cbcr_ver_scl_mode, cbcr_ver_scl_mode);
VOP_SCL_SET(vop, win, cbcr_hsd_mode, SCALE_DOWN_BIL);
VOP_SCL_SET(vop, win, cbcr_vsd_mode, SCALE_DOWN_BIL);
VOP_SCL_SET(vop, win, cbcr_vsu_mode, vsu_mode);
}
}
static void vop_dsp_hold_valid_irq_enable(struct vop *vop)
{
unsigned long flags;
if (WARN_ON(!vop->is_enabled))
return;
spin_lock_irqsave(&vop->irq_lock, flags);
vop_mask_write(vop, INTR_CTRL0, DSP_HOLD_VALID_INTR_MASK,
DSP_HOLD_VALID_INTR_EN(1));
spin_unlock_irqrestore(&vop->irq_lock, flags);
}
static void vop_dsp_hold_valid_irq_disable(struct vop *vop)
{
unsigned long flags;
if (WARN_ON(!vop->is_enabled))
return;
spin_lock_irqsave(&vop->irq_lock, flags);
vop_mask_write(vop, INTR_CTRL0, DSP_HOLD_VALID_INTR_MASK,
DSP_HOLD_VALID_INTR_EN(0));
spin_unlock_irqrestore(&vop->irq_lock, flags);
}
static void vop_enable(struct drm_crtc *crtc)
{
struct vop *vop = to_vop(crtc);
int ret;
if (vop->is_enabled)
return;
ret = pm_runtime_get_sync(vop->dev);
if (ret < 0) {
dev_err(vop->dev, "failed to get pm runtime: %d\n", ret);
return;
}
ret = clk_enable(vop->hclk);
if (ret < 0) {
dev_err(vop->dev, "failed to enable hclk - %d\n", ret);
return;
}
ret = clk_enable(vop->dclk);
if (ret < 0) {
dev_err(vop->dev, "failed to enable dclk - %d\n", ret);
goto err_disable_hclk;
}
ret = clk_enable(vop->aclk);
if (ret < 0) {
dev_err(vop->dev, "failed to enable aclk - %d\n", ret);
goto err_disable_dclk;
}
ret = rockchip_drm_dma_attach_device(vop->drm_dev, vop->dev);
if (ret) {
dev_err(vop->dev, "failed to attach dma mapping, %d\n", ret);
goto err_disable_aclk;
}
memcpy(vop->regs, vop->regsbak, vop->len);
vop->is_enabled = true;
spin_lock(&vop->reg_lock);
VOP_CTRL_SET(vop, standby, 0);
spin_unlock(&vop->reg_lock);
enable_irq(vop->irq);
drm_vblank_on(vop->drm_dev, vop->pipe);
return;
err_disable_aclk:
clk_disable(vop->aclk);
err_disable_dclk:
clk_disable(vop->dclk);
err_disable_hclk:
clk_disable(vop->hclk);
}
static void vop_disable(struct drm_crtc *crtc)
{
struct vop *vop = to_vop(crtc);
if (!vop->is_enabled)
return;
drm_vblank_off(crtc->dev, vop->pipe);
reinit_completion(&vop->dsp_hold_completion);
vop_dsp_hold_valid_irq_enable(vop);
spin_lock(&vop->reg_lock);
VOP_CTRL_SET(vop, standby, 1);
spin_unlock(&vop->reg_lock);
wait_for_completion(&vop->dsp_hold_completion);
vop_dsp_hold_valid_irq_disable(vop);
disable_irq(vop->irq);
vop->is_enabled = false;
rockchip_drm_dma_detach_device(vop->drm_dev, vop->dev);
clk_disable(vop->dclk);
clk_disable(vop->aclk);
clk_disable(vop->hclk);
pm_runtime_put(vop->dev);
}
static struct drm_framebuffer *vop_win_last_pending_fb(struct vop_win *vop_win)
{
struct vop_win_state *last;
struct vop_win_state *active = vop_win->active;
if (list_empty(&vop_win->pending))
return active ? active->fb : NULL;
last = list_last_entry(&vop_win->pending, struct vop_win_state, head);
return last ? last->fb : NULL;
}
static int vop_win_queue_fb(struct vop_win *vop_win,
struct drm_framebuffer *fb, dma_addr_t yrgb_mst,
struct drm_pending_vblank_event *event)
{
struct vop_win_state *state;
state = kzalloc(sizeof(*state), GFP_KERNEL);
if (!state)
return -ENOMEM;
state->fb = fb;
state->yrgb_mst = yrgb_mst;
state->event = event;
list_add_tail(&state->head, &vop_win->pending);
return 0;
}
static int vop_update_plane_event(struct drm_plane *plane,
struct drm_crtc *crtc,
struct drm_framebuffer *fb, int crtc_x,
int crtc_y, unsigned int crtc_w,
unsigned int crtc_h, uint32_t src_x,
uint32_t src_y, uint32_t src_w,
uint32_t src_h,
struct drm_pending_vblank_event *event)
{
struct vop_win *vop_win = to_vop_win(plane);
const struct vop_win_data *win = vop_win->data;
struct vop *vop = to_vop(crtc);
struct drm_gem_object *obj;
struct rockchip_gem_object *rk_obj;
struct drm_gem_object *uv_obj;
struct rockchip_gem_object *rk_uv_obj;
unsigned long offset;
unsigned int actual_w;
unsigned int actual_h;
unsigned int dsp_stx;
unsigned int dsp_sty;
unsigned int y_vir_stride;
unsigned int uv_vir_stride = 0;
dma_addr_t yrgb_mst;
dma_addr_t uv_mst = 0;
enum vop_data_format format;
uint32_t val;
bool is_alpha;
bool rb_swap;
bool is_yuv;
bool visible;
int ret;
struct drm_rect dest = {
.x1 = crtc_x,
.y1 = crtc_y,
.x2 = crtc_x + crtc_w,
.y2 = crtc_y + crtc_h,
};
struct drm_rect src = {
.x1 = src_x,
.y1 = src_y,
.x2 = src_x + src_w,
.y2 = src_y + src_h,
};
const struct drm_rect clip = {
.x2 = crtc->mode.hdisplay,
.y2 = crtc->mode.vdisplay,
};
bool can_position = plane->type != DRM_PLANE_TYPE_PRIMARY;
int min_scale = win->phy->scl ? FRAC_16_16(1, 8) :
DRM_PLANE_HELPER_NO_SCALING;
int max_scale = win->phy->scl ? FRAC_16_16(8, 1) :
DRM_PLANE_HELPER_NO_SCALING;
ret = drm_plane_helper_check_update(plane, crtc, fb,
&src, &dest, &clip,
min_scale,
max_scale,
can_position, false, &visible);
if (ret)
return ret;
if (!visible)
return 0;
is_alpha = is_alpha_support(fb->pixel_format);
rb_swap = has_rb_swapped(fb->pixel_format);
is_yuv = is_yuv_support(fb->pixel_format);
format = vop_convert_format(fb->pixel_format);
if (format < 0)
return format;
obj = rockchip_fb_get_gem_obj(fb, 0);
if (!obj) {
DRM_ERROR("fail to get rockchip gem object from framebuffer\n");
return -EINVAL;
}
rk_obj = to_rockchip_obj(obj);
if (is_yuv) {
val = (src.x1 >> 16) % 2;
src.x1 += val << 16;
src.x2 += val << 16;
}
actual_w = (src.x2 - src.x1) >> 16;
actual_h = (src.y2 - src.y1) >> 16;
dsp_stx = dest.x1 + crtc->mode.htotal - crtc->mode.hsync_start;
dsp_sty = dest.y1 + crtc->mode.vtotal - crtc->mode.vsync_start;
offset = (src.x1 >> 16) * drm_format_plane_cpp(fb->pixel_format, 0);
offset += (src.y1 >> 16) * fb->pitches[0];
yrgb_mst = rk_obj->dma_addr + offset + fb->offsets[0];
y_vir_stride = fb->pitches[0] >> 2;
if (is_yuv) {
int hsub = drm_format_horz_chroma_subsampling(fb->pixel_format);
int vsub = drm_format_vert_chroma_subsampling(fb->pixel_format);
int bpp = drm_format_plane_cpp(fb->pixel_format, 1);
uv_obj = rockchip_fb_get_gem_obj(fb, 1);
if (!uv_obj) {
DRM_ERROR("fail to get uv object from framebuffer\n");
return -EINVAL;
}
rk_uv_obj = to_rockchip_obj(uv_obj);
uv_vir_stride = fb->pitches[1] >> 2;
offset = (src.x1 >> 16) * bpp / hsub;
offset += (src.y1 >> 16) * fb->pitches[1] / vsub;
uv_mst = rk_uv_obj->dma_addr + offset + fb->offsets[1];
}
mutex_lock(&vop->vsync_mutex);
if (fb != vop_win_last_pending_fb(vop_win)) {
ret = drm_vblank_get(plane->dev, vop->pipe);
if (ret) {
DRM_ERROR("failed to get vblank, %d\n", ret);
mutex_unlock(&vop->vsync_mutex);
return ret;
}
drm_framebuffer_reference(fb);
ret = vop_win_queue_fb(vop_win, fb, yrgb_mst, event);
if (ret) {
drm_vblank_put(plane->dev, vop->pipe);
mutex_unlock(&vop->vsync_mutex);
return ret;
}
vop->vsync_work_pending = true;
}
mutex_unlock(&vop->vsync_mutex);
spin_lock(&vop->reg_lock);
VOP_WIN_SET(vop, win, format, format);
VOP_WIN_SET(vop, win, yrgb_vir, y_vir_stride);
VOP_WIN_SET(vop, win, yrgb_mst, yrgb_mst);
if (is_yuv) {
VOP_WIN_SET(vop, win, uv_vir, uv_vir_stride);
VOP_WIN_SET(vop, win, uv_mst, uv_mst);
}
if (win->phy->scl)
scl_vop_cal_scl_fac(vop, win, actual_w, actual_h,
dest.x2 - dest.x1, dest.y2 - dest.y1,
fb->pixel_format);
val = (actual_h - 1) << 16;
val |= (actual_w - 1) & 0xffff;
VOP_WIN_SET(vop, win, act_info, val);
val = (dest.y2 - dest.y1 - 1) << 16;
val |= (dest.x2 - dest.x1 - 1) & 0xffff;
VOP_WIN_SET(vop, win, dsp_info, val);
val = dsp_sty << 16;
val |= dsp_stx & 0xffff;
VOP_WIN_SET(vop, win, dsp_st, val);
VOP_WIN_SET(vop, win, rb_swap, rb_swap);
if (is_alpha) {
VOP_WIN_SET(vop, win, dst_alpha_ctl,
DST_FACTOR_M0(ALPHA_SRC_INVERSE));
val = SRC_ALPHA_EN(1) | SRC_COLOR_M0(ALPHA_SRC_PRE_MUL) |
SRC_ALPHA_M0(ALPHA_STRAIGHT) |
SRC_BLEND_M0(ALPHA_PER_PIX) |
SRC_ALPHA_CAL_M0(ALPHA_NO_SATURATION) |
SRC_FACTOR_M0(ALPHA_ONE);
VOP_WIN_SET(vop, win, src_alpha_ctl, val);
} else {
VOP_WIN_SET(vop, win, src_alpha_ctl, SRC_ALPHA_EN(0));
}
VOP_WIN_SET(vop, win, enable, 1);
vop_cfg_done(vop);
spin_unlock(&vop->reg_lock);
return 0;
}
static int vop_update_plane(struct drm_plane *plane, struct drm_crtc *crtc,
struct drm_framebuffer *fb, int crtc_x, int crtc_y,
unsigned int crtc_w, unsigned int crtc_h,
uint32_t src_x, uint32_t src_y, uint32_t src_w,
uint32_t src_h)
{
return vop_update_plane_event(plane, crtc, fb, crtc_x, crtc_y, crtc_w,
crtc_h, src_x, src_y, src_w, src_h,
NULL);
}
static int vop_update_primary_plane(struct drm_crtc *crtc,
struct drm_pending_vblank_event *event)
{
unsigned int crtc_w, crtc_h;
crtc_w = crtc->primary->fb->width - crtc->x;
crtc_h = crtc->primary->fb->height - crtc->y;
return vop_update_plane_event(crtc->primary, crtc, crtc->primary->fb,
0, 0, crtc_w, crtc_h, crtc->x << 16,
crtc->y << 16, crtc_w << 16,
crtc_h << 16, event);
}
static int vop_disable_plane(struct drm_plane *plane)
{
struct vop_win *vop_win = to_vop_win(plane);
const struct vop_win_data *win = vop_win->data;
struct vop *vop;
int ret;
if (!plane->crtc)
return 0;
vop = to_vop(plane->crtc);
ret = drm_vblank_get(plane->dev, vop->pipe);
if (ret) {
DRM_ERROR("failed to get vblank, %d\n", ret);
return ret;
}
mutex_lock(&vop->vsync_mutex);
ret = vop_win_queue_fb(vop_win, NULL, 0, NULL);
if (ret) {
drm_vblank_put(plane->dev, vop->pipe);
mutex_unlock(&vop->vsync_mutex);
return ret;
}
vop->vsync_work_pending = true;
mutex_unlock(&vop->vsync_mutex);
spin_lock(&vop->reg_lock);
VOP_WIN_SET(vop, win, enable, 0);
vop_cfg_done(vop);
spin_unlock(&vop->reg_lock);
return 0;
}
static void vop_plane_destroy(struct drm_plane *plane)
{
vop_disable_plane(plane);
drm_plane_cleanup(plane);
}
int rockchip_drm_crtc_mode_config(struct drm_crtc *crtc,
int connector_type,
int out_mode)
{
struct vop *vop = to_vop(crtc);
vop->connector_type = connector_type;
vop->connector_out_mode = out_mode;
return 0;
}
static int vop_crtc_enable_vblank(struct drm_crtc *crtc)
{
struct vop *vop = to_vop(crtc);
unsigned long flags;
if (!vop->is_enabled)
return -EPERM;
spin_lock_irqsave(&vop->irq_lock, flags);
vop_mask_write(vop, INTR_CTRL0, FS_INTR_MASK, FS_INTR_EN(1));
spin_unlock_irqrestore(&vop->irq_lock, flags);
return 0;
}
static void vop_crtc_disable_vblank(struct drm_crtc *crtc)
{
struct vop *vop = to_vop(crtc);
unsigned long flags;
if (!vop->is_enabled)
return;
spin_lock_irqsave(&vop->irq_lock, flags);
vop_mask_write(vop, INTR_CTRL0, FS_INTR_MASK, FS_INTR_EN(0));
spin_unlock_irqrestore(&vop->irq_lock, flags);
}
static void vop_crtc_dpms(struct drm_crtc *crtc, int mode)
{
DRM_DEBUG_KMS("crtc[%d] mode[%d]\n", crtc->base.id, mode);
switch (mode) {
case DRM_MODE_DPMS_ON:
vop_enable(crtc);
break;
case DRM_MODE_DPMS_STANDBY:
case DRM_MODE_DPMS_SUSPEND:
case DRM_MODE_DPMS_OFF:
vop_disable(crtc);
break;
default:
DRM_DEBUG_KMS("unspecified mode %d\n", mode);
break;
}
}
static void vop_crtc_prepare(struct drm_crtc *crtc)
{
vop_crtc_dpms(crtc, DRM_MODE_DPMS_ON);
}
static bool vop_crtc_mode_fixup(struct drm_crtc *crtc,
const struct drm_display_mode *mode,
struct drm_display_mode *adjusted_mode)
{
if (adjusted_mode->htotal == 0 || adjusted_mode->vtotal == 0)
return false;
return true;
}
static int vop_crtc_mode_set_base(struct drm_crtc *crtc, int x, int y,
struct drm_framebuffer *old_fb)
{
int ret;
crtc->x = x;
crtc->y = y;
ret = vop_update_primary_plane(crtc, NULL);
if (ret < 0) {
DRM_ERROR("fail to update plane\n");
return ret;
}
return 0;
}
static int vop_crtc_mode_set(struct drm_crtc *crtc,
struct drm_display_mode *mode,
struct drm_display_mode *adjusted_mode,
int x, int y, struct drm_framebuffer *fb)
{
struct vop *vop = to_vop(crtc);
u16 hsync_len = adjusted_mode->hsync_end - adjusted_mode->hsync_start;
u16 hdisplay = adjusted_mode->hdisplay;
u16 htotal = adjusted_mode->htotal;
u16 hact_st = adjusted_mode->htotal - adjusted_mode->hsync_start;
u16 hact_end = hact_st + hdisplay;
u16 vdisplay = adjusted_mode->vdisplay;
u16 vtotal = adjusted_mode->vtotal;
u16 vsync_len = adjusted_mode->vsync_end - adjusted_mode->vsync_start;
u16 vact_st = adjusted_mode->vtotal - adjusted_mode->vsync_start;
u16 vact_end = vact_st + vdisplay;
int ret, ret_clk;
uint32_t val;
clk_disable(vop->dclk);
switch (vop->connector_type) {
case DRM_MODE_CONNECTOR_LVDS:
VOP_CTRL_SET(vop, rgb_en, 1);
break;
case DRM_MODE_CONNECTOR_eDP:
VOP_CTRL_SET(vop, edp_en, 1);
break;
case DRM_MODE_CONNECTOR_HDMIA:
VOP_CTRL_SET(vop, hdmi_en, 1);
break;
default:
DRM_ERROR("unsupport connector_type[%d]\n",
vop->connector_type);
ret = -EINVAL;
goto out;
};
VOP_CTRL_SET(vop, out_mode, vop->connector_out_mode);
val = 0x8;
val |= (adjusted_mode->flags & DRM_MODE_FLAG_NHSYNC) ? 0 : 1;
val |= (adjusted_mode->flags & DRM_MODE_FLAG_NVSYNC) ? 0 : (1 << 1);
VOP_CTRL_SET(vop, pin_pol, val);
VOP_CTRL_SET(vop, htotal_pw, (htotal << 16) | hsync_len);
val = hact_st << 16;
val |= hact_end;
VOP_CTRL_SET(vop, hact_st_end, val);
VOP_CTRL_SET(vop, hpost_st_end, val);
VOP_CTRL_SET(vop, vtotal_pw, (vtotal << 16) | vsync_len);
val = vact_st << 16;
val |= vact_end;
VOP_CTRL_SET(vop, vact_st_end, val);
VOP_CTRL_SET(vop, vpost_st_end, val);
ret = vop_crtc_mode_set_base(crtc, x, y, fb);
if (ret)
goto out;
reset_control_assert(vop->dclk_rst);
usleep_range(10, 20);
reset_control_deassert(vop->dclk_rst);
clk_set_rate(vop->dclk, adjusted_mode->clock * 1000);
out:
ret_clk = clk_enable(vop->dclk);
if (ret_clk < 0) {
dev_err(vop->dev, "failed to enable dclk - %d\n", ret_clk);
return ret_clk;
}
return ret;
}
static void vop_crtc_commit(struct drm_crtc *crtc)
{
}
static int vop_crtc_page_flip(struct drm_crtc *crtc,
struct drm_framebuffer *fb,
struct drm_pending_vblank_event *event,
uint32_t page_flip_flags)
{
struct vop *vop = to_vop(crtc);
struct drm_framebuffer *old_fb = crtc->primary->fb;
int ret;
if (!vop->is_enabled) {
DRM_DEBUG("page flip request rejected because crtc is off.\n");
return 0;
}
crtc->primary->fb = fb;
ret = vop_update_primary_plane(crtc, event);
if (ret)
crtc->primary->fb = old_fb;
return ret;
}
static void vop_win_state_complete(struct vop_win *vop_win,
struct vop_win_state *state)
{
struct vop *vop = vop_win->vop;
struct drm_crtc *crtc = &vop->crtc;
struct drm_device *drm = crtc->dev;
unsigned long flags;
if (state->event) {
spin_lock_irqsave(&drm->event_lock, flags);
drm_crtc_send_vblank_event(crtc, state->event);
spin_unlock_irqrestore(&drm->event_lock, flags);
}
list_del(&state->head);
drm_vblank_put(crtc->dev, vop->pipe);
}
static void vop_crtc_destroy(struct drm_crtc *crtc)
{
drm_crtc_cleanup(crtc);
}
static bool vop_win_state_is_active(struct vop_win *vop_win,
struct vop_win_state *state)
{
bool active = false;
if (state->fb) {
dma_addr_t yrgb_mst;
yrgb_mst = VOP_WIN_GET_YRGBADDR(vop_win->vop, vop_win->data);
active = (yrgb_mst == state->yrgb_mst);
} else {
bool enabled;
enabled = VOP_WIN_GET(vop_win->vop, vop_win->data, enable);
active = (enabled == 0);
}
return active;
}
static void vop_win_state_destroy(struct vop_win_state *state)
{
struct drm_framebuffer *fb = state->fb;
if (fb)
drm_framebuffer_unreference(fb);
kfree(state);
}
static void vop_win_update_state(struct vop_win *vop_win)
{
struct vop_win_state *state, *n, *new_active = NULL;
list_for_each_entry(state, &vop_win->pending, head)
if (vop_win_state_is_active(vop_win, state)) {
new_active = state;
break;
}
if (!new_active)
return;
list_for_each_entry_safe(state, n, &vop_win->pending, head) {
if (state == new_active)
break;
vop_win_state_complete(vop_win, state);
vop_win_state_destroy(state);
}
vop_win_state_complete(vop_win, new_active);
if (vop_win->active)
vop_win_state_destroy(vop_win->active);
vop_win->active = new_active;
}
static bool vop_win_has_pending_state(struct vop_win *vop_win)
{
return !list_empty(&vop_win->pending);
}
static irqreturn_t vop_isr_thread(int irq, void *data)
{
struct vop *vop = data;
const struct vop_data *vop_data = vop->data;
unsigned int i;
mutex_lock(&vop->vsync_mutex);
if (!vop->vsync_work_pending)
goto done;
vop->vsync_work_pending = false;
for (i = 0; i < vop_data->win_size; i++) {
struct vop_win *vop_win = &vop->win[i];
vop_win_update_state(vop_win);
if (vop_win_has_pending_state(vop_win))
vop->vsync_work_pending = true;
}
done:
mutex_unlock(&vop->vsync_mutex);
return IRQ_HANDLED;
}
static irqreturn_t vop_isr(int irq, void *data)
{
struct vop *vop = data;
uint32_t intr0_reg, active_irqs;
unsigned long flags;
int ret = IRQ_NONE;
spin_lock_irqsave(&vop->irq_lock, flags);
intr0_reg = vop_readl(vop, INTR_CTRL0);
active_irqs = intr0_reg & INTR_MASK;
if (active_irqs)
vop_writel(vop, INTR_CTRL0,
intr0_reg | (active_irqs << INTR_CLR_SHIFT));
spin_unlock_irqrestore(&vop->irq_lock, flags);
if (!active_irqs)
return IRQ_NONE;
if (active_irqs & DSP_HOLD_VALID_INTR) {
complete(&vop->dsp_hold_completion);
active_irqs &= ~DSP_HOLD_VALID_INTR;
ret = IRQ_HANDLED;
}
if (active_irqs & FS_INTR) {
drm_handle_vblank(vop->drm_dev, vop->pipe);
active_irqs &= ~FS_INTR;
ret = (vop->vsync_work_pending) ? IRQ_WAKE_THREAD : IRQ_HANDLED;
}
if (active_irqs)
DRM_ERROR("Unknown VOP IRQs: %#02x\n", active_irqs);
return ret;
}
static int vop_create_crtc(struct vop *vop)
{
const struct vop_data *vop_data = vop->data;
struct device *dev = vop->dev;
struct drm_device *drm_dev = vop->drm_dev;
struct drm_plane *primary = NULL, *cursor = NULL, *plane;
struct drm_crtc *crtc = &vop->crtc;
struct device_node *port;
int ret;
int i;
for (i = 0; i < vop_data->win_size; i++) {
struct vop_win *vop_win = &vop->win[i];
const struct vop_win_data *win_data = vop_win->data;
if (win_data->type != DRM_PLANE_TYPE_PRIMARY &&
win_data->type != DRM_PLANE_TYPE_CURSOR)
continue;
ret = drm_universal_plane_init(vop->drm_dev, &vop_win->base,
0, &vop_plane_funcs,
win_data->phy->data_formats,
win_data->phy->nformats,
win_data->type);
if (ret) {
DRM_ERROR("failed to initialize plane\n");
goto err_cleanup_planes;
}
plane = &vop_win->base;
if (plane->type == DRM_PLANE_TYPE_PRIMARY)
primary = plane;
else if (plane->type == DRM_PLANE_TYPE_CURSOR)
cursor = plane;
}
ret = drm_crtc_init_with_planes(drm_dev, crtc, primary, cursor,
&vop_crtc_funcs);
if (ret)
return ret;
drm_crtc_helper_add(crtc, &vop_crtc_helper_funcs);
for (i = 0; i < vop_data->win_size; i++) {
struct vop_win *vop_win = &vop->win[i];
const struct vop_win_data *win_data = vop_win->data;
unsigned long possible_crtcs = 1 << drm_crtc_index(crtc);
if (win_data->type != DRM_PLANE_TYPE_OVERLAY)
continue;
ret = drm_universal_plane_init(vop->drm_dev, &vop_win->base,
possible_crtcs,
&vop_plane_funcs,
win_data->phy->data_formats,
win_data->phy->nformats,
win_data->type);
if (ret) {
DRM_ERROR("failed to initialize overlay plane\n");
goto err_cleanup_crtc;
}
}
port = of_get_child_by_name(dev->of_node, "port");
if (!port) {
DRM_ERROR("no port node found in %s\n",
dev->of_node->full_name);
goto err_cleanup_crtc;
}
init_completion(&vop->dsp_hold_completion);
crtc->port = port;
vop->pipe = drm_crtc_index(crtc);
rockchip_register_crtc_funcs(drm_dev, &private_crtc_funcs, vop->pipe);
return 0;
err_cleanup_crtc:
drm_crtc_cleanup(crtc);
err_cleanup_planes:
list_for_each_entry(plane, &drm_dev->mode_config.plane_list, head)
drm_plane_cleanup(plane);
return ret;
}
static void vop_destroy_crtc(struct vop *vop)
{
struct drm_crtc *crtc = &vop->crtc;
rockchip_unregister_crtc_funcs(vop->drm_dev, vop->pipe);
of_node_put(crtc->port);
drm_crtc_cleanup(crtc);
}
static int vop_initial(struct vop *vop)
{
const struct vop_data *vop_data = vop->data;
const struct vop_reg_data *init_table = vop_data->init_table;
struct reset_control *ahb_rst;
int i, ret;
vop->hclk = devm_clk_get(vop->dev, "hclk_vop");
if (IS_ERR(vop->hclk)) {
dev_err(vop->dev, "failed to get hclk source\n");
return PTR_ERR(vop->hclk);
}
vop->aclk = devm_clk_get(vop->dev, "aclk_vop");
if (IS_ERR(vop->aclk)) {
dev_err(vop->dev, "failed to get aclk source\n");
return PTR_ERR(vop->aclk);
}
vop->dclk = devm_clk_get(vop->dev, "dclk_vop");
if (IS_ERR(vop->dclk)) {
dev_err(vop->dev, "failed to get dclk source\n");
return PTR_ERR(vop->dclk);
}
ret = clk_prepare(vop->dclk);
if (ret < 0) {
dev_err(vop->dev, "failed to prepare dclk\n");
return ret;
}
ret = clk_prepare_enable(vop->hclk);
if (ret < 0) {
dev_err(vop->dev, "failed to prepare/enable hclk\n");
goto err_unprepare_dclk;
}
ret = clk_prepare_enable(vop->aclk);
if (ret < 0) {
dev_err(vop->dev, "failed to prepare/enable aclk\n");
goto err_disable_hclk;
}
ahb_rst = devm_reset_control_get(vop->dev, "ahb");
if (IS_ERR(ahb_rst)) {
dev_err(vop->dev, "failed to get ahb reset\n");
ret = PTR_ERR(ahb_rst);
goto err_disable_aclk;
}
reset_control_assert(ahb_rst);
usleep_range(10, 20);
reset_control_deassert(ahb_rst);
memcpy(vop->regsbak, vop->regs, vop->len);
for (i = 0; i < vop_data->table_size; i++)
vop_writel(vop, init_table[i].offset, init_table[i].value);
for (i = 0; i < vop_data->win_size; i++) {
const struct vop_win_data *win = &vop_data->win[i];
VOP_WIN_SET(vop, win, enable, 0);
}
vop_cfg_done(vop);
vop->dclk_rst = devm_reset_control_get(vop->dev, "dclk");
if (IS_ERR(vop->dclk_rst)) {
dev_err(vop->dev, "failed to get dclk reset\n");
ret = PTR_ERR(vop->dclk_rst);
goto err_disable_aclk;
}
reset_control_assert(vop->dclk_rst);
usleep_range(10, 20);
reset_control_deassert(vop->dclk_rst);
clk_disable(vop->hclk);
clk_disable(vop->aclk);
vop->is_enabled = false;
return 0;
err_disable_aclk:
clk_disable_unprepare(vop->aclk);
err_disable_hclk:
clk_disable_unprepare(vop->hclk);
err_unprepare_dclk:
clk_unprepare(vop->dclk);
return ret;
}
static void vop_win_init(struct vop *vop)
{
const struct vop_data *vop_data = vop->data;
unsigned int i;
for (i = 0; i < vop_data->win_size; i++) {
struct vop_win *vop_win = &vop->win[i];
const struct vop_win_data *win_data = &vop_data->win[i];
vop_win->data = win_data;
vop_win->vop = vop;
INIT_LIST_HEAD(&vop_win->pending);
}
}
static int vop_bind(struct device *dev, struct device *master, void *data)
{
struct platform_device *pdev = to_platform_device(dev);
const struct of_device_id *of_id;
const struct vop_data *vop_data;
struct drm_device *drm_dev = data;
struct vop *vop;
struct resource *res;
size_t alloc_size;
int ret, irq;
of_id = of_match_device(vop_driver_dt_match, dev);
vop_data = of_id->data;
if (!vop_data)
return -ENODEV;
alloc_size = sizeof(*vop) + sizeof(*vop->win) * vop_data->win_size;
vop = devm_kzalloc(dev, alloc_size, GFP_KERNEL);
if (!vop)
return -ENOMEM;
vop->dev = dev;
vop->data = vop_data;
vop->drm_dev = drm_dev;
dev_set_drvdata(dev, vop);
vop_win_init(vop);
res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
vop->len = resource_size(res);
vop->regs = devm_ioremap_resource(dev, res);
if (IS_ERR(vop->regs))
return PTR_ERR(vop->regs);
vop->regsbak = devm_kzalloc(dev, vop->len, GFP_KERNEL);
if (!vop->regsbak)
return -ENOMEM;
ret = vop_initial(vop);
if (ret < 0) {
dev_err(&pdev->dev, "cannot initial vop dev - err %d\n", ret);
return ret;
}
irq = platform_get_irq(pdev, 0);
if (irq < 0) {
dev_err(dev, "cannot find irq for vop\n");
return irq;
}
vop->irq = (unsigned int)irq;
spin_lock_init(&vop->reg_lock);
spin_lock_init(&vop->irq_lock);
mutex_init(&vop->vsync_mutex);
ret = devm_request_threaded_irq(dev, vop->irq, vop_isr, vop_isr_thread,
IRQF_SHARED, dev_name(dev), vop);
if (ret)
return ret;
disable_irq(vop->irq);
ret = vop_create_crtc(vop);
if (ret)
return ret;
pm_runtime_enable(&pdev->dev);
return 0;
}
static void vop_unbind(struct device *dev, struct device *master, void *data)
{
struct vop *vop = dev_get_drvdata(dev);
pm_runtime_disable(dev);
vop_destroy_crtc(vop);
}
static int vop_probe(struct platform_device *pdev)
{
struct device *dev = &pdev->dev;
if (!dev->of_node) {
dev_err(dev, "can't find vop devices\n");
return -ENODEV;
}
return component_add(dev, &vop_component_ops);
}
static int vop_remove(struct platform_device *pdev)
{
component_del(&pdev->dev, &vop_component_ops);
return 0;
}
