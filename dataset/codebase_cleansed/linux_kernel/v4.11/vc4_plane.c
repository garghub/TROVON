static inline struct vc4_plane_state *
to_vc4_plane_state(struct drm_plane_state *state)
{
return (struct vc4_plane_state *)state;
}
static const struct hvs_format *vc4_get_hvs_format(u32 drm_format)
{
unsigned i;
for (i = 0; i < ARRAY_SIZE(hvs_formats); i++) {
if (hvs_formats[i].drm == drm_format)
return &hvs_formats[i];
}
return NULL;
}
static enum vc4_scaling_mode vc4_get_scaling_mode(u32 src, u32 dst)
{
if (dst > src)
return VC4_SCALING_PPF;
else if (dst < src)
return VC4_SCALING_TPZ;
else
return VC4_SCALING_NONE;
}
static bool plane_enabled(struct drm_plane_state *state)
{
return state->fb && state->crtc;
}
static struct drm_plane_state *vc4_plane_duplicate_state(struct drm_plane *plane)
{
struct vc4_plane_state *vc4_state;
if (WARN_ON(!plane->state))
return NULL;
vc4_state = kmemdup(plane->state, sizeof(*vc4_state), GFP_KERNEL);
if (!vc4_state)
return NULL;
memset(&vc4_state->lbm, 0, sizeof(vc4_state->lbm));
__drm_atomic_helper_plane_duplicate_state(plane, &vc4_state->base);
if (vc4_state->dlist) {
vc4_state->dlist = kmemdup(vc4_state->dlist,
vc4_state->dlist_count * 4,
GFP_KERNEL);
if (!vc4_state->dlist) {
kfree(vc4_state);
return NULL;
}
vc4_state->dlist_size = vc4_state->dlist_count;
}
return &vc4_state->base;
}
static void vc4_plane_destroy_state(struct drm_plane *plane,
struct drm_plane_state *state)
{
struct vc4_dev *vc4 = to_vc4_dev(plane->dev);
struct vc4_plane_state *vc4_state = to_vc4_plane_state(state);
if (vc4_state->lbm.allocated) {
unsigned long irqflags;
spin_lock_irqsave(&vc4->hvs->mm_lock, irqflags);
drm_mm_remove_node(&vc4_state->lbm);
spin_unlock_irqrestore(&vc4->hvs->mm_lock, irqflags);
}
kfree(vc4_state->dlist);
__drm_atomic_helper_plane_destroy_state(&vc4_state->base);
kfree(state);
}
static void vc4_plane_reset(struct drm_plane *plane)
{
struct vc4_plane_state *vc4_state;
WARN_ON(plane->state);
vc4_state = kzalloc(sizeof(*vc4_state), GFP_KERNEL);
if (!vc4_state)
return;
plane->state = &vc4_state->base;
vc4_state->base.plane = plane;
}
static void vc4_dlist_write(struct vc4_plane_state *vc4_state, u32 val)
{
if (vc4_state->dlist_count == vc4_state->dlist_size) {
u32 new_size = max(4u, vc4_state->dlist_count * 2);
u32 *new_dlist = kmalloc(new_size * 4, GFP_KERNEL);
if (!new_dlist)
return;
memcpy(new_dlist, vc4_state->dlist, vc4_state->dlist_count * 4);
kfree(vc4_state->dlist);
vc4_state->dlist = new_dlist;
vc4_state->dlist_size = new_size;
}
vc4_state->dlist[vc4_state->dlist_count++] = val;
}
static u32 vc4_get_scl_field(struct drm_plane_state *state, int plane)
{
struct vc4_plane_state *vc4_state = to_vc4_plane_state(state);
switch (vc4_state->x_scaling[plane] << 2 | vc4_state->y_scaling[plane]) {
case VC4_SCALING_PPF << 2 | VC4_SCALING_PPF:
return SCALER_CTL0_SCL_H_PPF_V_PPF;
case VC4_SCALING_TPZ << 2 | VC4_SCALING_PPF:
return SCALER_CTL0_SCL_H_TPZ_V_PPF;
case VC4_SCALING_PPF << 2 | VC4_SCALING_TPZ:
return SCALER_CTL0_SCL_H_PPF_V_TPZ;
case VC4_SCALING_TPZ << 2 | VC4_SCALING_TPZ:
return SCALER_CTL0_SCL_H_TPZ_V_TPZ;
case VC4_SCALING_PPF << 2 | VC4_SCALING_NONE:
return SCALER_CTL0_SCL_H_PPF_V_NONE;
case VC4_SCALING_NONE << 2 | VC4_SCALING_PPF:
return SCALER_CTL0_SCL_H_NONE_V_PPF;
case VC4_SCALING_NONE << 2 | VC4_SCALING_TPZ:
return SCALER_CTL0_SCL_H_NONE_V_TPZ;
case VC4_SCALING_TPZ << 2 | VC4_SCALING_NONE:
return SCALER_CTL0_SCL_H_TPZ_V_NONE;
default:
case VC4_SCALING_NONE << 2 | VC4_SCALING_NONE:
return 0;
}
}
static int vc4_plane_setup_clipping_and_scaling(struct drm_plane_state *state)
{
struct drm_plane *plane = state->plane;
struct vc4_plane_state *vc4_state = to_vc4_plane_state(state);
struct drm_framebuffer *fb = state->fb;
struct drm_gem_cma_object *bo = drm_fb_cma_get_gem_obj(fb, 0);
u32 subpixel_src_mask = (1 << 16) - 1;
u32 format = fb->format->format;
int num_planes = fb->format->num_planes;
u32 h_subsample = 1;
u32 v_subsample = 1;
int i;
for (i = 0; i < num_planes; i++)
vc4_state->offsets[i] = bo->paddr + fb->offsets[i];
if ((state->src_x & subpixel_src_mask) ||
(state->src_y & subpixel_src_mask) ||
(state->src_w & subpixel_src_mask) ||
(state->src_h & subpixel_src_mask)) {
return -EINVAL;
}
vc4_state->src_x = state->src_x >> 16;
vc4_state->src_y = state->src_y >> 16;
vc4_state->src_w[0] = state->src_w >> 16;
vc4_state->src_h[0] = state->src_h >> 16;
vc4_state->crtc_x = state->crtc_x;
vc4_state->crtc_y = state->crtc_y;
vc4_state->crtc_w = state->crtc_w;
vc4_state->crtc_h = state->crtc_h;
vc4_state->x_scaling[0] = vc4_get_scaling_mode(vc4_state->src_w[0],
vc4_state->crtc_w);
vc4_state->y_scaling[0] = vc4_get_scaling_mode(vc4_state->src_h[0],
vc4_state->crtc_h);
if (num_planes > 1) {
vc4_state->is_yuv = true;
h_subsample = drm_format_horz_chroma_subsampling(format);
v_subsample = drm_format_vert_chroma_subsampling(format);
vc4_state->src_w[1] = vc4_state->src_w[0] / h_subsample;
vc4_state->src_h[1] = vc4_state->src_h[0] / v_subsample;
vc4_state->x_scaling[1] =
vc4_get_scaling_mode(vc4_state->src_w[1],
vc4_state->crtc_w);
vc4_state->y_scaling[1] =
vc4_get_scaling_mode(vc4_state->src_h[1],
vc4_state->crtc_h);
if (vc4_state->x_scaling[0] == VC4_SCALING_NONE)
vc4_state->x_scaling[0] = VC4_SCALING_TPZ;
if (vc4_state->y_scaling[0] == VC4_SCALING_NONE)
vc4_state->y_scaling[0] = VC4_SCALING_TPZ;
}
vc4_state->is_unity = (vc4_state->x_scaling[0] == VC4_SCALING_NONE &&
vc4_state->y_scaling[0] == VC4_SCALING_NONE &&
vc4_state->x_scaling[1] == VC4_SCALING_NONE &&
vc4_state->y_scaling[1] == VC4_SCALING_NONE);
if (plane->type == DRM_PLANE_TYPE_CURSOR && !vc4_state->is_unity)
return -EINVAL;
if (vc4_state->crtc_x < 0) {
for (i = 0; i < num_planes; i++) {
u32 cpp = fb->format->cpp[i];
u32 subs = ((i == 0) ? 1 : h_subsample);
vc4_state->offsets[i] += (cpp *
(-vc4_state->crtc_x) / subs);
}
vc4_state->src_w[0] += vc4_state->crtc_x;
vc4_state->src_w[1] += vc4_state->crtc_x / h_subsample;
vc4_state->crtc_x = 0;
}
if (vc4_state->crtc_y < 0) {
for (i = 0; i < num_planes; i++) {
u32 subs = ((i == 0) ? 1 : v_subsample);
vc4_state->offsets[i] += (fb->pitches[i] *
(-vc4_state->crtc_y) / subs);
}
vc4_state->src_h[0] += vc4_state->crtc_y;
vc4_state->src_h[1] += vc4_state->crtc_y / v_subsample;
vc4_state->crtc_y = 0;
}
return 0;
}
static void vc4_write_tpz(struct vc4_plane_state *vc4_state, u32 src, u32 dst)
{
u32 scale, recip;
scale = (1 << 16) * src / dst;
recip = ~0 / scale;
vc4_dlist_write(vc4_state,
VC4_SET_FIELD(scale, SCALER_TPZ0_SCALE) |
VC4_SET_FIELD(0, SCALER_TPZ0_IPHASE));
vc4_dlist_write(vc4_state,
VC4_SET_FIELD(recip, SCALER_TPZ1_RECIP));
}
static void vc4_write_ppf(struct vc4_plane_state *vc4_state, u32 src, u32 dst)
{
u32 scale = (1 << 16) * src / dst;
vc4_dlist_write(vc4_state,
SCALER_PPF_AGC |
VC4_SET_FIELD(scale, SCALER_PPF_SCALE) |
VC4_SET_FIELD(0, SCALER_PPF_IPHASE));
}
static u32 vc4_lbm_size(struct drm_plane_state *state)
{
struct vc4_plane_state *vc4_state = to_vc4_plane_state(state);
u32 pix_per_line = max(vc4_state->src_w[0], (u32)vc4_state->crtc_w);
u32 lbm;
if (!vc4_state->is_yuv) {
if (vc4_state->is_unity)
return 0;
else if (vc4_state->y_scaling[0] == VC4_SCALING_TPZ)
lbm = pix_per_line * 8;
else {
lbm = pix_per_line * 16;
}
} else {
lbm = pix_per_line * 16;
}
lbm = roundup(lbm, 32);
return lbm;
}
static void vc4_write_scaling_parameters(struct drm_plane_state *state,
int channel)
{
struct vc4_plane_state *vc4_state = to_vc4_plane_state(state);
if (vc4_state->x_scaling[channel] == VC4_SCALING_PPF) {
vc4_write_ppf(vc4_state,
vc4_state->src_w[channel], vc4_state->crtc_w);
}
if (vc4_state->y_scaling[channel] == VC4_SCALING_PPF) {
vc4_write_ppf(vc4_state,
vc4_state->src_h[channel], vc4_state->crtc_h);
vc4_dlist_write(vc4_state, 0xc0c0c0c0);
}
if (vc4_state->x_scaling[channel] == VC4_SCALING_TPZ) {
vc4_write_tpz(vc4_state,
vc4_state->src_w[channel], vc4_state->crtc_w);
}
if (vc4_state->y_scaling[channel] == VC4_SCALING_TPZ) {
vc4_write_tpz(vc4_state,
vc4_state->src_h[channel], vc4_state->crtc_h);
vc4_dlist_write(vc4_state, 0xc0c0c0c0);
}
}
static int vc4_plane_mode_set(struct drm_plane *plane,
struct drm_plane_state *state)
{
struct vc4_dev *vc4 = to_vc4_dev(plane->dev);
struct vc4_plane_state *vc4_state = to_vc4_plane_state(state);
struct drm_framebuffer *fb = state->fb;
u32 ctl0_offset = vc4_state->dlist_count;
const struct hvs_format *format = vc4_get_hvs_format(fb->format->format);
int num_planes = drm_format_num_planes(format->drm);
u32 scl0, scl1;
u32 lbm_size;
unsigned long irqflags;
int ret, i;
ret = vc4_plane_setup_clipping_and_scaling(state);
if (ret)
return ret;
lbm_size = vc4_lbm_size(state);
if (lbm_size) {
if (!vc4_state->lbm.allocated) {
spin_lock_irqsave(&vc4->hvs->mm_lock, irqflags);
ret = drm_mm_insert_node_generic(&vc4->hvs->lbm_mm,
&vc4_state->lbm,
lbm_size, 32, 0, 0);
spin_unlock_irqrestore(&vc4->hvs->mm_lock, irqflags);
} else {
WARN_ON_ONCE(lbm_size != vc4_state->lbm.size);
}
}
if (ret)
return ret;
if (num_planes == 1) {
scl0 = vc4_get_scl_field(state, 1);
scl1 = scl0;
} else {
scl0 = vc4_get_scl_field(state, 1);
scl1 = vc4_get_scl_field(state, 0);
}
vc4_dlist_write(vc4_state,
SCALER_CTL0_VALID |
(format->pixel_order << SCALER_CTL0_ORDER_SHIFT) |
(format->hvs << SCALER_CTL0_PIXEL_FORMAT_SHIFT) |
(vc4_state->is_unity ? SCALER_CTL0_UNITY : 0) |
VC4_SET_FIELD(scl0, SCALER_CTL0_SCL0) |
VC4_SET_FIELD(scl1, SCALER_CTL0_SCL1));
vc4_state->pos0_offset = vc4_state->dlist_count;
vc4_dlist_write(vc4_state,
VC4_SET_FIELD(0xff, SCALER_POS0_FIXED_ALPHA) |
VC4_SET_FIELD(vc4_state->crtc_x, SCALER_POS0_START_X) |
VC4_SET_FIELD(vc4_state->crtc_y, SCALER_POS0_START_Y));
if (!vc4_state->is_unity) {
vc4_dlist_write(vc4_state,
VC4_SET_FIELD(vc4_state->crtc_w,
SCALER_POS1_SCL_WIDTH) |
VC4_SET_FIELD(vc4_state->crtc_h,
SCALER_POS1_SCL_HEIGHT));
}
vc4_state->pos2_offset = vc4_state->dlist_count;
vc4_dlist_write(vc4_state,
VC4_SET_FIELD(format->has_alpha ?
SCALER_POS2_ALPHA_MODE_PIPELINE :
SCALER_POS2_ALPHA_MODE_FIXED,
SCALER_POS2_ALPHA_MODE) |
VC4_SET_FIELD(vc4_state->src_w[0], SCALER_POS2_WIDTH) |
VC4_SET_FIELD(vc4_state->src_h[0], SCALER_POS2_HEIGHT));
vc4_dlist_write(vc4_state, 0xc0c0c0c0);
vc4_state->ptr0_offset = vc4_state->dlist_count;
if (!format->flip_cbcr) {
for (i = 0; i < num_planes; i++)
vc4_dlist_write(vc4_state, vc4_state->offsets[i]);
} else {
WARN_ON_ONCE(num_planes != 3);
vc4_dlist_write(vc4_state, vc4_state->offsets[0]);
vc4_dlist_write(vc4_state, vc4_state->offsets[2]);
vc4_dlist_write(vc4_state, vc4_state->offsets[1]);
}
for (i = 0; i < num_planes; i++)
vc4_dlist_write(vc4_state, 0xc0c0c0c0);
for (i = 0; i < num_planes; i++) {
vc4_dlist_write(vc4_state,
VC4_SET_FIELD(fb->pitches[i], SCALER_SRC_PITCH));
}
if (vc4_state->is_yuv) {
vc4_dlist_write(vc4_state, SCALER_CSC0_ITR_R_601_5);
vc4_dlist_write(vc4_state, SCALER_CSC1_ITR_R_601_5);
vc4_dlist_write(vc4_state, SCALER_CSC2_ITR_R_601_5);
}
if (!vc4_state->is_unity) {
if (vc4_state->y_scaling[0] != VC4_SCALING_NONE ||
vc4_state->y_scaling[1] != VC4_SCALING_NONE) {
vc4_dlist_write(vc4_state, vc4_state->lbm.start);
}
if (num_planes > 1) {
vc4_write_scaling_parameters(state, 1);
}
vc4_write_scaling_parameters(state, 0);
if (vc4_state->x_scaling[0] == VC4_SCALING_PPF ||
vc4_state->y_scaling[0] == VC4_SCALING_PPF ||
vc4_state->x_scaling[1] == VC4_SCALING_PPF ||
vc4_state->y_scaling[1] == VC4_SCALING_PPF) {
u32 kernel = VC4_SET_FIELD(vc4->hvs->mitchell_netravali_filter.start,
SCALER_PPF_KERNEL_OFFSET);
vc4_dlist_write(vc4_state, kernel);
vc4_dlist_write(vc4_state, kernel);
vc4_dlist_write(vc4_state, kernel);
vc4_dlist_write(vc4_state, kernel);
}
}
vc4_state->dlist[ctl0_offset] |=
VC4_SET_FIELD(vc4_state->dlist_count, SCALER_CTL0_SIZE);
return 0;
}
static int vc4_plane_atomic_check(struct drm_plane *plane,
struct drm_plane_state *state)
{
struct vc4_plane_state *vc4_state = to_vc4_plane_state(state);
vc4_state->dlist_count = 0;
if (plane_enabled(state))
return vc4_plane_mode_set(plane, state);
else
return 0;
}
static void vc4_plane_atomic_update(struct drm_plane *plane,
struct drm_plane_state *old_state)
{
}
u32 vc4_plane_write_dlist(struct drm_plane *plane, u32 __iomem *dlist)
{
struct vc4_plane_state *vc4_state = to_vc4_plane_state(plane->state);
int i;
vc4_state->hw_dlist = dlist;
for (i = 0; i < vc4_state->dlist_count; i++)
writel(vc4_state->dlist[i], &dlist[i]);
return vc4_state->dlist_count;
}
u32 vc4_plane_dlist_size(const struct drm_plane_state *state)
{
const struct vc4_plane_state *vc4_state =
container_of(state, typeof(*vc4_state), base);
return vc4_state->dlist_count;
}
void vc4_plane_async_set_fb(struct drm_plane *plane, struct drm_framebuffer *fb)
{
struct vc4_plane_state *vc4_state = to_vc4_plane_state(plane->state);
struct drm_gem_cma_object *bo = drm_fb_cma_get_gem_obj(fb, 0);
uint32_t addr;
WARN_ON_ONCE(plane->state->crtc_x < 0 || plane->state->crtc_y < 0);
addr = bo->paddr + fb->offsets[0];
writel(addr, &vc4_state->hw_dlist[vc4_state->ptr0_offset]);
vc4_state->dlist[vc4_state->ptr0_offset] = addr;
}
static void vc4_plane_destroy(struct drm_plane *plane)
{
drm_plane_helper_disable(plane);
drm_plane_cleanup(plane);
}
static int
vc4_update_plane(struct drm_plane *plane,
struct drm_crtc *crtc,
struct drm_framebuffer *fb,
int crtc_x, int crtc_y,
unsigned int crtc_w, unsigned int crtc_h,
uint32_t src_x, uint32_t src_y,
uint32_t src_w, uint32_t src_h)
{
struct drm_plane_state *plane_state;
struct vc4_plane_state *vc4_state;
if (plane != crtc->cursor)
goto out;
plane_state = plane->state;
vc4_state = to_vc4_plane_state(plane_state);
if (!plane_state)
goto out;
if (fb != plane_state->fb)
goto out;
if (crtc_w != plane_state->crtc_w ||
crtc_h != plane_state->crtc_h ||
src_w != plane_state->src_w ||
src_h != plane_state->src_h) {
goto out;
}
plane_state->crtc_x = crtc_x;
plane_state->crtc_y = crtc_y;
plane_state->src_x = src_x;
plane_state->src_y = src_y;
vc4_plane_atomic_check(plane, plane_state);
writel(vc4_state->dlist[vc4_state->pos0_offset],
&vc4_state->hw_dlist[vc4_state->pos0_offset]);
writel(vc4_state->dlist[vc4_state->pos2_offset],
&vc4_state->hw_dlist[vc4_state->pos2_offset]);
writel(vc4_state->dlist[vc4_state->ptr0_offset],
&vc4_state->hw_dlist[vc4_state->ptr0_offset]);
return 0;
out:
return drm_atomic_helper_update_plane(plane, crtc, fb,
crtc_x, crtc_y,
crtc_w, crtc_h,
src_x, src_y,
src_w, src_h);
}
struct drm_plane *vc4_plane_init(struct drm_device *dev,
enum drm_plane_type type)
{
struct drm_plane *plane = NULL;
struct vc4_plane *vc4_plane;
u32 formats[ARRAY_SIZE(hvs_formats)];
u32 num_formats = 0;
int ret = 0;
unsigned i;
vc4_plane = devm_kzalloc(dev->dev, sizeof(*vc4_plane),
GFP_KERNEL);
if (!vc4_plane) {
ret = -ENOMEM;
goto fail;
}
for (i = 0; i < ARRAY_SIZE(hvs_formats); i++) {
if (type != DRM_PLANE_TYPE_CURSOR ||
hvs_formats[i].hvs < HVS_PIXEL_FORMAT_YCBCR_YUV420_3PLANE) {
formats[num_formats++] = hvs_formats[i].drm;
}
}
plane = &vc4_plane->base;
ret = drm_universal_plane_init(dev, plane, 0,
&vc4_plane_funcs,
formats, num_formats,
type, NULL);
drm_plane_helper_add(plane, &vc4_plane_helper_funcs);
return plane;
fail:
if (plane)
vc4_plane_destroy(plane);
return ERR_PTR(ret);
}
