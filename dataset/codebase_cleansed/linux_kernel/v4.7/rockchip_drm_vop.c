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
static inline uint32_t vop_get_intr_type(struct vop *vop,
const struct vop_reg *reg, int type)
{
uint32_t i, ret = 0;
uint32_t regs = vop_read_reg(vop, 0, reg);
for (i = 0; i < vop->data->intr->nintrs; i++) {
if ((type & vop->data->intr->intrs[i]) && (regs & 1 << i))
ret |= vop->data->intr->intrs[i];
}
return ret;
}
static inline void vop_cfg_done(struct vop *vop)
{
VOP_CTRL_SET(vop, cfg_done, 1);
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
int vskiplines = 0;
if (dst_w > 3840) {
DRM_ERROR("Maximum destination width (3840) exceeded\n");
return;
}
if (!win->phy->scl->ext) {
VOP_SCL_SET(vop, win, scale_yrgb_x,
scl_cal_scale2(src_w, dst_w));
VOP_SCL_SET(vop, win, scale_yrgb_y,
scl_cal_scale2(src_h, dst_h));
if (is_yuv) {
VOP_SCL_SET(vop, win, scale_cbcr_x,
scl_cal_scale2(src_w, dst_w));
VOP_SCL_SET(vop, win, scale_cbcr_y,
scl_cal_scale2(src_h, dst_h));
}
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
VOP_SCL_SET_EXT(vop, win, lb_mode, lb_mode);
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
VOP_SCL_SET_EXT(vop, win, vsd_yrgb_gt4, vskiplines == 4);
VOP_SCL_SET_EXT(vop, win, vsd_yrgb_gt2, vskiplines == 2);
VOP_SCL_SET_EXT(vop, win, yrgb_hor_scl_mode, yrgb_hor_scl_mode);
VOP_SCL_SET_EXT(vop, win, yrgb_ver_scl_mode, yrgb_ver_scl_mode);
VOP_SCL_SET_EXT(vop, win, yrgb_hsd_mode, SCALE_DOWN_BIL);
VOP_SCL_SET_EXT(vop, win, yrgb_vsd_mode, SCALE_DOWN_BIL);
VOP_SCL_SET_EXT(vop, win, yrgb_vsu_mode, vsu_mode);
if (is_yuv) {
val = scl_vop_cal_scale(cbcr_hor_scl_mode, cbcr_src_w,
dst_w, true, 0, NULL);
VOP_SCL_SET(vop, win, scale_cbcr_x, val);
val = scl_vop_cal_scale(cbcr_ver_scl_mode, cbcr_src_h,
dst_h, false, vsu_mode, &vskiplines);
VOP_SCL_SET(vop, win, scale_cbcr_y, val);
VOP_SCL_SET_EXT(vop, win, vsd_cbcr_gt4, vskiplines == 4);
VOP_SCL_SET_EXT(vop, win, vsd_cbcr_gt2, vskiplines == 2);
VOP_SCL_SET_EXT(vop, win, cbcr_hor_scl_mode, cbcr_hor_scl_mode);
VOP_SCL_SET_EXT(vop, win, cbcr_ver_scl_mode, cbcr_ver_scl_mode);
VOP_SCL_SET_EXT(vop, win, cbcr_hsd_mode, SCALE_DOWN_BIL);
VOP_SCL_SET_EXT(vop, win, cbcr_vsd_mode, SCALE_DOWN_BIL);
VOP_SCL_SET_EXT(vop, win, cbcr_vsu_mode, vsu_mode);
}
}
static void vop_dsp_hold_valid_irq_enable(struct vop *vop)
{
unsigned long flags;
if (WARN_ON(!vop->is_enabled))
return;
spin_lock_irqsave(&vop->irq_lock, flags);
VOP_INTR_SET_TYPE(vop, enable, DSP_HOLD_VALID_INTR, 1);
spin_unlock_irqrestore(&vop->irq_lock, flags);
}
static void vop_dsp_hold_valid_irq_disable(struct vop *vop)
{
unsigned long flags;
if (WARN_ON(!vop->is_enabled))
return;
spin_lock_irqsave(&vop->irq_lock, flags);
VOP_INTR_SET_TYPE(vop, enable, DSP_HOLD_VALID_INTR, 0);
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
drm_crtc_vblank_on(crtc);
return;
err_disable_aclk:
clk_disable(vop->aclk);
err_disable_dclk:
clk_disable(vop->dclk);
err_disable_hclk:
clk_disable(vop->hclk);
}
static void vop_crtc_disable(struct drm_crtc *crtc)
{
struct vop *vop = to_vop(crtc);
int i;
if (!vop->is_enabled)
return;
for (i = 0; i < vop->data->win_size; i++) {
struct vop_win *vop_win = &vop->win[i];
const struct vop_win_data *win = vop_win->data;
spin_lock(&vop->reg_lock);
VOP_WIN_SET(vop, win, enable, 0);
spin_unlock(&vop->reg_lock);
}
drm_crtc_vblank_off(crtc);
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
static void vop_plane_destroy(struct drm_plane *plane)
{
drm_plane_cleanup(plane);
}
static int vop_plane_prepare_fb(struct drm_plane *plane,
const struct drm_plane_state *new_state)
{
if (plane->state->fb)
drm_framebuffer_reference(plane->state->fb);
return 0;
}
static void vop_plane_cleanup_fb(struct drm_plane *plane,
const struct drm_plane_state *old_state)
{
if (old_state->fb)
drm_framebuffer_unreference(old_state->fb);
}
static int vop_plane_atomic_check(struct drm_plane *plane,
struct drm_plane_state *state)
{
struct drm_crtc *crtc = state->crtc;
struct drm_crtc_state *crtc_state;
struct drm_framebuffer *fb = state->fb;
struct vop_win *vop_win = to_vop_win(plane);
struct vop_plane_state *vop_plane_state = to_vop_plane_state(state);
const struct vop_win_data *win = vop_win->data;
bool visible;
int ret;
struct drm_rect *dest = &vop_plane_state->dest;
struct drm_rect *src = &vop_plane_state->src;
struct drm_rect clip;
int min_scale = win->phy->scl ? FRAC_16_16(1, 8) :
DRM_PLANE_HELPER_NO_SCALING;
int max_scale = win->phy->scl ? FRAC_16_16(8, 1) :
DRM_PLANE_HELPER_NO_SCALING;
if (!crtc || !fb)
goto out_disable;
crtc_state = drm_atomic_get_existing_crtc_state(state->state, crtc);
if (WARN_ON(!crtc_state))
return -EINVAL;
src->x1 = state->src_x;
src->y1 = state->src_y;
src->x2 = state->src_x + state->src_w;
src->y2 = state->src_y + state->src_h;
dest->x1 = state->crtc_x;
dest->y1 = state->crtc_y;
dest->x2 = state->crtc_x + state->crtc_w;
dest->y2 = state->crtc_y + state->crtc_h;
clip.x1 = 0;
clip.y1 = 0;
clip.x2 = crtc_state->adjusted_mode.hdisplay;
clip.y2 = crtc_state->adjusted_mode.vdisplay;
ret = drm_plane_helper_check_update(plane, crtc, state->fb,
src, dest, &clip,
min_scale,
max_scale,
true, true, &visible);
if (ret)
return ret;
if (!visible)
goto out_disable;
vop_plane_state->format = vop_convert_format(fb->pixel_format);
if (vop_plane_state->format < 0)
return vop_plane_state->format;
if (is_yuv_support(fb->pixel_format) && ((src->x1 >> 16) % 2))
return -EINVAL;
vop_plane_state->enable = true;
return 0;
out_disable:
vop_plane_state->enable = false;
return 0;
}
static void vop_plane_atomic_disable(struct drm_plane *plane,
struct drm_plane_state *old_state)
{
struct vop_plane_state *vop_plane_state = to_vop_plane_state(old_state);
struct vop_win *vop_win = to_vop_win(plane);
const struct vop_win_data *win = vop_win->data;
struct vop *vop = to_vop(old_state->crtc);
if (!old_state->crtc)
return;
spin_lock(&vop->reg_lock);
VOP_WIN_SET(vop, win, enable, 0);
spin_unlock(&vop->reg_lock);
vop_plane_state->enable = false;
}
static void vop_plane_atomic_update(struct drm_plane *plane,
struct drm_plane_state *old_state)
{
struct drm_plane_state *state = plane->state;
struct drm_crtc *crtc = state->crtc;
struct vop_win *vop_win = to_vop_win(plane);
struct vop_plane_state *vop_plane_state = to_vop_plane_state(state);
const struct vop_win_data *win = vop_win->data;
struct vop *vop = to_vop(state->crtc);
struct drm_framebuffer *fb = state->fb;
unsigned int actual_w, actual_h;
unsigned int dsp_stx, dsp_sty;
uint32_t act_info, dsp_info, dsp_st;
struct drm_rect *src = &vop_plane_state->src;
struct drm_rect *dest = &vop_plane_state->dest;
struct drm_gem_object *obj, *uv_obj;
struct rockchip_gem_object *rk_obj, *rk_uv_obj;
unsigned long offset;
dma_addr_t dma_addr;
uint32_t val;
bool rb_swap;
if (!crtc)
return;
if (WARN_ON(!vop->is_enabled))
return;
if (!vop_plane_state->enable) {
vop_plane_atomic_disable(plane, old_state);
return;
}
obj = rockchip_fb_get_gem_obj(fb, 0);
rk_obj = to_rockchip_obj(obj);
actual_w = drm_rect_width(src) >> 16;
actual_h = drm_rect_height(src) >> 16;
act_info = (actual_h - 1) << 16 | ((actual_w - 1) & 0xffff);
dsp_info = (drm_rect_height(dest) - 1) << 16;
dsp_info |= (drm_rect_width(dest) - 1) & 0xffff;
dsp_stx = dest->x1 + crtc->mode.htotal - crtc->mode.hsync_start;
dsp_sty = dest->y1 + crtc->mode.vtotal - crtc->mode.vsync_start;
dsp_st = dsp_sty << 16 | (dsp_stx & 0xffff);
offset = (src->x1 >> 16) * drm_format_plane_cpp(fb->pixel_format, 0);
offset += (src->y1 >> 16) * fb->pitches[0];
vop_plane_state->yrgb_mst = rk_obj->dma_addr + offset + fb->offsets[0];
spin_lock(&vop->reg_lock);
VOP_WIN_SET(vop, win, format, vop_plane_state->format);
VOP_WIN_SET(vop, win, yrgb_vir, fb->pitches[0] >> 2);
VOP_WIN_SET(vop, win, yrgb_mst, vop_plane_state->yrgb_mst);
if (is_yuv_support(fb->pixel_format)) {
int hsub = drm_format_horz_chroma_subsampling(fb->pixel_format);
int vsub = drm_format_vert_chroma_subsampling(fb->pixel_format);
int bpp = drm_format_plane_cpp(fb->pixel_format, 1);
uv_obj = rockchip_fb_get_gem_obj(fb, 1);
rk_uv_obj = to_rockchip_obj(uv_obj);
offset = (src->x1 >> 16) * bpp / hsub;
offset += (src->y1 >> 16) * fb->pitches[1] / vsub;
dma_addr = rk_uv_obj->dma_addr + offset + fb->offsets[1];
VOP_WIN_SET(vop, win, uv_vir, fb->pitches[1] >> 2);
VOP_WIN_SET(vop, win, uv_mst, dma_addr);
}
if (win->phy->scl)
scl_vop_cal_scl_fac(vop, win, actual_w, actual_h,
drm_rect_width(dest), drm_rect_height(dest),
fb->pixel_format);
VOP_WIN_SET(vop, win, act_info, act_info);
VOP_WIN_SET(vop, win, dsp_info, dsp_info);
VOP_WIN_SET(vop, win, dsp_st, dsp_st);
rb_swap = has_rb_swapped(fb->pixel_format);
VOP_WIN_SET(vop, win, rb_swap, rb_swap);
if (is_alpha_support(fb->pixel_format)) {
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
spin_unlock(&vop->reg_lock);
}
void vop_atomic_plane_reset(struct drm_plane *plane)
{
struct vop_plane_state *vop_plane_state =
to_vop_plane_state(plane->state);
if (plane->state && plane->state->fb)
drm_framebuffer_unreference(plane->state->fb);
kfree(vop_plane_state);
vop_plane_state = kzalloc(sizeof(*vop_plane_state), GFP_KERNEL);
if (!vop_plane_state)
return;
plane->state = &vop_plane_state->base;
plane->state->plane = plane;
}
struct drm_plane_state *
vop_atomic_plane_duplicate_state(struct drm_plane *plane)
{
struct vop_plane_state *old_vop_plane_state;
struct vop_plane_state *vop_plane_state;
if (WARN_ON(!plane->state))
return NULL;
old_vop_plane_state = to_vop_plane_state(plane->state);
vop_plane_state = kmemdup(old_vop_plane_state,
sizeof(*vop_plane_state), GFP_KERNEL);
if (!vop_plane_state)
return NULL;
__drm_atomic_helper_plane_duplicate_state(plane,
&vop_plane_state->base);
return &vop_plane_state->base;
}
static void vop_atomic_plane_destroy_state(struct drm_plane *plane,
struct drm_plane_state *state)
{
struct vop_plane_state *vop_state = to_vop_plane_state(state);
__drm_atomic_helper_plane_destroy_state(state);
kfree(vop_state);
}
static int vop_crtc_enable_vblank(struct drm_crtc *crtc)
{
struct vop *vop = to_vop(crtc);
unsigned long flags;
if (WARN_ON(!vop->is_enabled))
return -EPERM;
spin_lock_irqsave(&vop->irq_lock, flags);
VOP_INTR_SET_TYPE(vop, enable, FS_INTR, 1);
spin_unlock_irqrestore(&vop->irq_lock, flags);
return 0;
}
static void vop_crtc_disable_vblank(struct drm_crtc *crtc)
{
struct vop *vop = to_vop(crtc);
unsigned long flags;
if (WARN_ON(!vop->is_enabled))
return;
spin_lock_irqsave(&vop->irq_lock, flags);
VOP_INTR_SET_TYPE(vop, enable, FS_INTR, 0);
spin_unlock_irqrestore(&vop->irq_lock, flags);
}
static void vop_crtc_wait_for_update(struct drm_crtc *crtc)
{
struct vop *vop = to_vop(crtc);
reinit_completion(&vop->wait_update_complete);
WARN_ON(!wait_for_completion_timeout(&vop->wait_update_complete, 100));
}
static void vop_crtc_cancel_pending_vblank(struct drm_crtc *crtc,
struct drm_file *file_priv)
{
struct drm_device *drm = crtc->dev;
struct vop *vop = to_vop(crtc);
struct drm_pending_vblank_event *e;
unsigned long flags;
spin_lock_irqsave(&drm->event_lock, flags);
e = vop->event;
if (e && e->base.file_priv == file_priv) {
vop->event = NULL;
e->base.destroy(&e->base);
file_priv->event_space += sizeof(e->event);
}
spin_unlock_irqrestore(&drm->event_lock, flags);
}
static bool vop_crtc_mode_fixup(struct drm_crtc *crtc,
const struct drm_display_mode *mode,
struct drm_display_mode *adjusted_mode)
{
struct vop *vop = to_vop(crtc);
adjusted_mode->clock =
clk_round_rate(vop->dclk, mode->clock * 1000) / 1000;
return true;
}
static void vop_crtc_enable(struct drm_crtc *crtc)
{
struct vop *vop = to_vop(crtc);
struct rockchip_crtc_state *s = to_rockchip_crtc_state(crtc->state);
struct drm_display_mode *adjusted_mode = &crtc->state->adjusted_mode;
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
uint32_t val;
vop_enable(crtc);
if (clk_get_rate(vop->dclk)) {
reinit_completion(&vop->dsp_hold_completion);
vop_dsp_hold_valid_irq_enable(vop);
spin_lock(&vop->reg_lock);
VOP_CTRL_SET(vop, standby, 1);
spin_unlock(&vop->reg_lock);
wait_for_completion(&vop->dsp_hold_completion);
vop_dsp_hold_valid_irq_disable(vop);
}
val = 0x8;
val |= (adjusted_mode->flags & DRM_MODE_FLAG_NHSYNC) ? 0 : 1;
val |= (adjusted_mode->flags & DRM_MODE_FLAG_NVSYNC) ? 0 : (1 << 1);
VOP_CTRL_SET(vop, pin_pol, val);
switch (s->output_type) {
case DRM_MODE_CONNECTOR_LVDS:
VOP_CTRL_SET(vop, rgb_en, 1);
break;
case DRM_MODE_CONNECTOR_eDP:
VOP_CTRL_SET(vop, edp_en, 1);
break;
case DRM_MODE_CONNECTOR_HDMIA:
VOP_CTRL_SET(vop, hdmi_en, 1);
break;
case DRM_MODE_CONNECTOR_DSI:
VOP_CTRL_SET(vop, mipi_en, 1);
break;
default:
DRM_ERROR("unsupport connector_type[%d]\n", s->output_type);
}
VOP_CTRL_SET(vop, out_mode, s->output_mode);
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
clk_set_rate(vop->dclk, adjusted_mode->clock * 1000);
VOP_CTRL_SET(vop, standby, 0);
}
static void vop_crtc_atomic_flush(struct drm_crtc *crtc,
struct drm_crtc_state *old_crtc_state)
{
struct vop *vop = to_vop(crtc);
if (WARN_ON(!vop->is_enabled))
return;
spin_lock(&vop->reg_lock);
vop_cfg_done(vop);
spin_unlock(&vop->reg_lock);
}
static void vop_crtc_atomic_begin(struct drm_crtc *crtc,
struct drm_crtc_state *old_crtc_state)
{
struct vop *vop = to_vop(crtc);
if (crtc->state->event) {
WARN_ON(drm_crtc_vblank_get(crtc) != 0);
vop->event = crtc->state->event;
crtc->state->event = NULL;
}
}
static void vop_crtc_destroy(struct drm_crtc *crtc)
{
drm_crtc_cleanup(crtc);
}
static struct drm_crtc_state *vop_crtc_duplicate_state(struct drm_crtc *crtc)
{
struct rockchip_crtc_state *rockchip_state;
rockchip_state = kzalloc(sizeof(*rockchip_state), GFP_KERNEL);
if (!rockchip_state)
return NULL;
__drm_atomic_helper_crtc_duplicate_state(crtc, &rockchip_state->base);
return &rockchip_state->base;
}
static void vop_crtc_destroy_state(struct drm_crtc *crtc,
struct drm_crtc_state *state)
{
struct rockchip_crtc_state *s = to_rockchip_crtc_state(state);
__drm_atomic_helper_crtc_destroy_state(&s->base);
kfree(s);
}
static bool vop_win_pending_is_complete(struct vop_win *vop_win)
{
struct drm_plane *plane = &vop_win->base;
struct vop_plane_state *state = to_vop_plane_state(plane->state);
dma_addr_t yrgb_mst;
if (!state->enable)
return VOP_WIN_GET(vop_win->vop, vop_win->data, enable) == 0;
yrgb_mst = VOP_WIN_GET_YRGBADDR(vop_win->vop, vop_win->data);
return yrgb_mst == state->yrgb_mst;
}
static void vop_handle_vblank(struct vop *vop)
{
struct drm_device *drm = vop->drm_dev;
struct drm_crtc *crtc = &vop->crtc;
unsigned long flags;
int i;
for (i = 0; i < vop->data->win_size; i++) {
if (!vop_win_pending_is_complete(&vop->win[i]))
return;
}
if (vop->event) {
spin_lock_irqsave(&drm->event_lock, flags);
drm_crtc_send_vblank_event(crtc, vop->event);
drm_crtc_vblank_put(crtc);
vop->event = NULL;
spin_unlock_irqrestore(&drm->event_lock, flags);
}
if (!completion_done(&vop->wait_update_complete))
complete(&vop->wait_update_complete);
}
static irqreturn_t vop_isr(int irq, void *data)
{
struct vop *vop = data;
struct drm_crtc *crtc = &vop->crtc;
uint32_t active_irqs;
unsigned long flags;
int ret = IRQ_NONE;
spin_lock_irqsave(&vop->irq_lock, flags);
active_irqs = VOP_INTR_GET_TYPE(vop, status, INTR_MASK);
if (active_irqs)
VOP_INTR_SET_TYPE(vop, clear, active_irqs, 1);
spin_unlock_irqrestore(&vop->irq_lock, flags);
if (!active_irqs)
return IRQ_NONE;
if (active_irqs & DSP_HOLD_VALID_INTR) {
complete(&vop->dsp_hold_completion);
active_irqs &= ~DSP_HOLD_VALID_INTR;
ret = IRQ_HANDLED;
}
if (active_irqs & FS_INTR) {
drm_crtc_handle_vblank(crtc);
vop_handle_vblank(vop);
active_irqs &= ~FS_INTR;
ret = IRQ_HANDLED;
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
struct drm_plane *primary = NULL, *cursor = NULL, *plane, *tmp;
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
win_data->type, NULL);
if (ret) {
DRM_ERROR("failed to initialize plane\n");
goto err_cleanup_planes;
}
plane = &vop_win->base;
drm_plane_helper_add(plane, &plane_helper_funcs);
if (plane->type == DRM_PLANE_TYPE_PRIMARY)
primary = plane;
else if (plane->type == DRM_PLANE_TYPE_CURSOR)
cursor = plane;
}
ret = drm_crtc_init_with_planes(drm_dev, crtc, primary, cursor,
&vop_crtc_funcs, NULL);
if (ret)
goto err_cleanup_planes;
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
win_data->type, NULL);
if (ret) {
DRM_ERROR("failed to initialize overlay plane\n");
goto err_cleanup_crtc;
}
drm_plane_helper_add(&vop_win->base, &plane_helper_funcs);
}
port = of_get_child_by_name(dev->of_node, "port");
if (!port) {
DRM_ERROR("no port node found in %s\n",
dev->of_node->full_name);
ret = -ENOENT;
goto err_cleanup_crtc;
}
init_completion(&vop->dsp_hold_completion);
init_completion(&vop->wait_update_complete);
crtc->port = port;
rockchip_register_crtc_funcs(crtc, &private_crtc_funcs);
return 0;
err_cleanup_crtc:
drm_crtc_cleanup(crtc);
err_cleanup_planes:
list_for_each_entry_safe(plane, tmp, &drm_dev->mode_config.plane_list,
head)
drm_plane_cleanup(plane);
return ret;
}
static void vop_destroy_crtc(struct vop *vop)
{
struct drm_crtc *crtc = &vop->crtc;
struct drm_device *drm_dev = vop->drm_dev;
struct drm_plane *plane, *tmp;
rockchip_unregister_crtc_funcs(crtc);
of_node_put(crtc->port);
list_for_each_entry_safe(plane, tmp, &drm_dev->mode_config.plane_list,
head)
vop_plane_destroy(plane);
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
}
}
static int vop_bind(struct device *dev, struct device *master, void *data)
{
struct platform_device *pdev = to_platform_device(dev);
const struct vop_data *vop_data;
struct drm_device *drm_dev = data;
struct vop *vop;
struct resource *res;
size_t alloc_size;
int ret, irq;
vop_data = of_device_get_match_data(dev);
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
ret = devm_request_irq(dev, vop->irq, vop_isr,
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
