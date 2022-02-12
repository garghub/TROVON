static bool rcar_du_plane_needs_realloc(struct rcar_du_plane *plane,
struct rcar_du_plane_state *new_state)
{
struct rcar_du_plane_state *cur_state;
cur_state = to_rcar_plane_state(plane->plane.state);
if (!cur_state->format ||
cur_state->format->planes != new_state->format->planes)
return true;
if (cur_state->source != new_state->source)
return true;
return false;
}
static unsigned int rcar_du_plane_hwmask(struct rcar_du_plane_state *state)
{
unsigned int mask;
if (state->hwindex == -1)
return 0;
mask = 1 << state->hwindex;
if (state->format->planes == 2)
mask |= 1 << ((state->hwindex + 1) % 8);
return mask;
}
static int rcar_du_plane_hwalloc(struct rcar_du_plane *plane,
struct rcar_du_plane_state *state,
unsigned int free)
{
unsigned int num_planes = state->format->planes;
int fixed = -1;
int i;
if (state->source == RCAR_DU_PLANE_VSPD0) {
if (plane->group->index != 0)
return -EINVAL;
fixed = 0;
} else if (state->source == RCAR_DU_PLANE_VSPD1) {
fixed = plane->group->index == 0 ? 1 : 0;
}
if (fixed >= 0)
return free & (1 << fixed) ? fixed : -EBUSY;
for (i = RCAR_DU_NUM_HW_PLANES - 1; i >= 0; --i) {
if (!(free & (1 << i)))
continue;
if (num_planes == 1 || free & (1 << ((i + 1) % 8)))
break;
}
return i < 0 ? -EBUSY : i;
}
int rcar_du_atomic_check_planes(struct drm_device *dev,
struct drm_atomic_state *state)
{
struct rcar_du_device *rcdu = dev->dev_private;
unsigned int group_freed_planes[RCAR_DU_MAX_GROUPS] = { 0, };
unsigned int group_free_planes[RCAR_DU_MAX_GROUPS] = { 0, };
bool needs_realloc = false;
unsigned int groups = 0;
unsigned int i;
for (i = 0; i < dev->mode_config.num_total_plane; ++i) {
struct rcar_du_plane_state *plane_state;
struct rcar_du_plane *plane;
unsigned int index;
if (!state->planes[i])
continue;
plane = to_rcar_plane(state->planes[i]);
plane_state = to_rcar_plane_state(state->plane_states[i]);
dev_dbg(rcdu->dev, "%s: checking plane (%u,%tu)\n", __func__,
plane->group->index, plane - plane->group->planes);
if (!plane_state->format) {
dev_dbg(rcdu->dev, "%s: plane is being disabled\n",
__func__);
index = plane - plane->group->planes;
group_freed_planes[plane->group->index] |= 1 << index;
plane_state->hwindex = -1;
continue;
}
if (rcar_du_plane_needs_realloc(plane, plane_state)) {
dev_dbg(rcdu->dev, "%s: plane needs reallocation\n",
__func__);
groups |= 1 << plane->group->index;
needs_realloc = true;
index = plane - plane->group->planes;
group_freed_planes[plane->group->index] |= 1 << index;
plane_state->hwindex = -1;
}
}
if (!needs_realloc)
return 0;
while (groups) {
unsigned int index = ffs(groups) - 1;
struct rcar_du_group *group = &rcdu->groups[index];
unsigned int used_planes = 0;
dev_dbg(rcdu->dev, "%s: finding free planes for group %u\n",
__func__, index);
for (i = 0; i < group->num_planes; ++i) {
struct rcar_du_plane *plane = &group->planes[i];
struct rcar_du_plane_state *plane_state;
struct drm_plane_state *s;
s = drm_atomic_get_plane_state(state, &plane->plane);
if (IS_ERR(s))
return PTR_ERR(s);
if (group_freed_planes[index] & (1 << i)) {
dev_dbg(rcdu->dev,
"%s: plane (%u,%tu) has been freed, skipping\n",
__func__, plane->group->index,
plane - plane->group->planes);
continue;
}
plane_state = to_rcar_plane_state(plane->plane.state);
used_planes |= rcar_du_plane_hwmask(plane_state);
dev_dbg(rcdu->dev,
"%s: plane (%u,%tu) uses %u hwplanes (index %d)\n",
__func__, plane->group->index,
plane - plane->group->planes,
plane_state->format ?
plane_state->format->planes : 0,
plane_state->hwindex);
}
group_free_planes[index] = 0xff & ~used_planes;
groups &= ~(1 << index);
dev_dbg(rcdu->dev, "%s: group %u free planes mask 0x%02x\n",
__func__, index, group_free_planes[index]);
}
for (i = 0; i < dev->mode_config.num_total_plane; ++i) {
struct rcar_du_plane_state *plane_state;
struct rcar_du_plane *plane;
unsigned int crtc_planes;
unsigned int free;
int idx;
if (!state->planes[i])
continue;
plane = to_rcar_plane(state->planes[i]);
plane_state = to_rcar_plane_state(state->plane_states[i]);
dev_dbg(rcdu->dev, "%s: allocating plane (%u,%tu)\n", __func__,
plane->group->index, plane - plane->group->planes);
if (!plane_state->format ||
!rcar_du_plane_needs_realloc(plane, plane_state))
continue;
crtc_planes = to_rcar_crtc(plane_state->state.crtc)->index % 2
? plane->group->dptsr_planes
: ~plane->group->dptsr_planes;
free = group_free_planes[plane->group->index];
idx = rcar_du_plane_hwalloc(plane, plane_state,
free & crtc_planes);
if (idx < 0)
idx = rcar_du_plane_hwalloc(plane, plane_state,
free);
if (idx < 0) {
dev_dbg(rcdu->dev, "%s: no available hardware plane\n",
__func__);
return idx;
}
dev_dbg(rcdu->dev, "%s: allocated %u hwplanes (index %u)\n",
__func__, plane_state->format->planes, idx);
plane_state->hwindex = idx;
group_free_planes[plane->group->index] &=
~rcar_du_plane_hwmask(plane_state);
dev_dbg(rcdu->dev, "%s: group %u free planes mask 0x%02x\n",
__func__, plane->group->index,
group_free_planes[plane->group->index]);
}
return 0;
}
static void rcar_du_plane_write(struct rcar_du_group *rgrp,
unsigned int index, u32 reg, u32 data)
{
rcar_du_write(rgrp->dev, rgrp->mmio_offset + index * PLANE_OFF + reg,
data);
}
static void rcar_du_plane_setup_scanout(struct rcar_du_group *rgrp,
const struct rcar_du_plane_state *state)
{
unsigned int src_x = state->state.src_x >> 16;
unsigned int src_y = state->state.src_y >> 16;
unsigned int index = state->hwindex;
unsigned int pitch;
bool interlaced;
u32 dma[2];
interlaced = state->state.crtc->state->adjusted_mode.flags
& DRM_MODE_FLAG_INTERLACE;
if (state->source == RCAR_DU_PLANE_MEMORY) {
struct drm_framebuffer *fb = state->state.fb;
struct drm_gem_cma_object *gem;
unsigned int i;
if (state->format->planes == 2)
pitch = fb->pitches[0];
else
pitch = fb->pitches[0] * 8 / state->format->bpp;
for (i = 0; i < state->format->planes; ++i) {
gem = drm_fb_cma_get_gem_obj(fb, i);
dma[i] = gem->paddr + fb->offsets[i];
}
} else {
pitch = state->state.src_w >> 16;
dma[0] = 0;
dma[1] = 0;
}
rcar_du_plane_write(rgrp, index, PnMWR,
(interlaced && state->format->bpp == 32) ?
pitch * 2 : pitch);
rcar_du_plane_write(rgrp, index, PnSPXR, src_x);
rcar_du_plane_write(rgrp, index, PnSPYR, src_y *
(!interlaced && state->format->bpp == 32 ? 2 : 1));
rcar_du_plane_write(rgrp, index, PnDSA0R, dma[0]);
if (state->format->planes == 2) {
index = (index + 1) % 8;
rcar_du_plane_write(rgrp, index, PnMWR, pitch);
rcar_du_plane_write(rgrp, index, PnSPXR, src_x);
rcar_du_plane_write(rgrp, index, PnSPYR, src_y *
(state->format->bpp == 16 ? 2 : 1) / 2);
rcar_du_plane_write(rgrp, index, PnDSA0R, dma[1]);
}
}
static void rcar_du_plane_setup_mode(struct rcar_du_group *rgrp,
unsigned int index,
const struct rcar_du_plane_state *state)
{
u32 colorkey;
u32 pnmr;
if (state->format->fourcc != DRM_FORMAT_XRGB1555)
rcar_du_plane_write(rgrp, index, PnALPHAR, PnALPHAR_ABIT_0);
else
rcar_du_plane_write(rgrp, index, PnALPHAR,
PnALPHAR_ABIT_X | state->alpha);
pnmr = PnMR_BM_MD | state->format->pnmr;
if ((state->colorkey & RCAR_DU_COLORKEY_MASK) == RCAR_DU_COLORKEY_NONE)
pnmr |= PnMR_SPIM_TP_OFF;
if (state->format->fourcc == DRM_FORMAT_YUYV)
pnmr |= PnMR_YCDF_YUYV;
rcar_du_plane_write(rgrp, index, PnMR, pnmr);
switch (state->format->fourcc) {
case DRM_FORMAT_RGB565:
colorkey = ((state->colorkey & 0xf80000) >> 8)
| ((state->colorkey & 0x00fc00) >> 5)
| ((state->colorkey & 0x0000f8) >> 3);
rcar_du_plane_write(rgrp, index, PnTC2R, colorkey);
break;
case DRM_FORMAT_ARGB1555:
case DRM_FORMAT_XRGB1555:
colorkey = ((state->colorkey & 0xf80000) >> 9)
| ((state->colorkey & 0x00f800) >> 6)
| ((state->colorkey & 0x0000f8) >> 3);
rcar_du_plane_write(rgrp, index, PnTC2R, colorkey);
break;
case DRM_FORMAT_XRGB8888:
case DRM_FORMAT_ARGB8888:
rcar_du_plane_write(rgrp, index, PnTC3R,
PnTC3R_CODE | (state->colorkey & 0xffffff));
break;
}
}
static void rcar_du_plane_setup_format_gen2(struct rcar_du_group *rgrp,
unsigned int index,
const struct rcar_du_plane_state *state)
{
u32 ddcr2 = PnDDCR2_CODE;
u32 ddcr4;
rcar_du_plane_setup_mode(rgrp, index, state);
if (state->format->planes == 2) {
if (state->hwindex != index) {
if (state->format->fourcc == DRM_FORMAT_NV12 ||
state->format->fourcc == DRM_FORMAT_NV21)
ddcr2 |= PnDDCR2_Y420;
if (state->format->fourcc == DRM_FORMAT_NV21)
ddcr2 |= PnDDCR2_NV21;
ddcr2 |= PnDDCR2_DIVU;
} else {
ddcr2 |= PnDDCR2_DIVY;
}
}
rcar_du_plane_write(rgrp, index, PnDDCR2, ddcr2);
ddcr4 = state->format->edf | PnDDCR4_CODE;
if (state->source != RCAR_DU_PLANE_MEMORY)
ddcr4 |= PnDDCR4_VSPS;
rcar_du_plane_write(rgrp, index, PnDDCR4, ddcr4);
}
static void rcar_du_plane_setup_format_gen3(struct rcar_du_group *rgrp,
unsigned int index,
const struct rcar_du_plane_state *state)
{
rcar_du_plane_write(rgrp, index, PnMR,
PnMR_SPIM_TP_OFF | state->format->pnmr);
rcar_du_plane_write(rgrp, index, PnDDCR4,
state->format->edf | PnDDCR4_CODE);
}
static void rcar_du_plane_setup_format(struct rcar_du_group *rgrp,
unsigned int index,
const struct rcar_du_plane_state *state)
{
struct rcar_du_device *rcdu = rgrp->dev;
if (rcdu->info->gen < 3)
rcar_du_plane_setup_format_gen2(rgrp, index, state);
else
rcar_du_plane_setup_format_gen3(rgrp, index, state);
rcar_du_plane_write(rgrp, index, PnDSXR, state->state.crtc_w);
rcar_du_plane_write(rgrp, index, PnDSYR, state->state.crtc_h);
rcar_du_plane_write(rgrp, index, PnDPXR, state->state.crtc_x);
rcar_du_plane_write(rgrp, index, PnDPYR, state->state.crtc_y);
if (rcdu->info->gen < 3) {
rcar_du_plane_write(rgrp, index, PnWASPR, 0);
rcar_du_plane_write(rgrp, index, PnWAMWR, 4095);
rcar_du_plane_write(rgrp, index, PnBTR, 0);
rcar_du_plane_write(rgrp, index, PnMLR, 0);
}
}
void __rcar_du_plane_setup(struct rcar_du_group *rgrp,
const struct rcar_du_plane_state *state)
{
struct rcar_du_device *rcdu = rgrp->dev;
rcar_du_plane_setup_format(rgrp, state->hwindex, state);
if (state->format->planes == 2)
rcar_du_plane_setup_format(rgrp, (state->hwindex + 1) % 8,
state);
if (rcdu->info->gen < 3)
rcar_du_plane_setup_scanout(rgrp, state);
if (state->source == RCAR_DU_PLANE_VSPD1) {
unsigned int vspd1_sink = rgrp->index ? 2 : 0;
if (rcdu->vspd1_sink != vspd1_sink) {
rcdu->vspd1_sink = vspd1_sink;
rcar_du_set_dpad0_vsp1_routing(rcdu);
}
}
}
static int rcar_du_plane_atomic_check(struct drm_plane *plane,
struct drm_plane_state *state)
{
struct rcar_du_plane_state *rstate = to_rcar_plane_state(state);
struct rcar_du_plane *rplane = to_rcar_plane(plane);
struct rcar_du_device *rcdu = rplane->group->dev;
if (!state->fb || !state->crtc) {
rstate->format = NULL;
return 0;
}
if (state->src_w >> 16 != state->crtc_w ||
state->src_h >> 16 != state->crtc_h) {
dev_dbg(rcdu->dev, "%s: scaling not supported\n", __func__);
return -EINVAL;
}
rstate->format = rcar_du_format_info(state->fb->pixel_format);
if (rstate->format == NULL) {
dev_dbg(rcdu->dev, "%s: unsupported format %08x\n", __func__,
state->fb->pixel_format);
return -EINVAL;
}
return 0;
}
static void rcar_du_plane_atomic_update(struct drm_plane *plane,
struct drm_plane_state *old_state)
{
struct rcar_du_plane *rplane = to_rcar_plane(plane);
struct rcar_du_plane_state *old_rstate;
struct rcar_du_plane_state *new_rstate;
if (!plane->state->crtc)
return;
rcar_du_plane_setup(rplane);
old_rstate = to_rcar_plane_state(old_state);
new_rstate = to_rcar_plane_state(plane->state);
if ((old_rstate->source == RCAR_DU_PLANE_MEMORY) !=
(new_rstate->source == RCAR_DU_PLANE_MEMORY))
rplane->group->need_restart = true;
}
static struct drm_plane_state *
rcar_du_plane_atomic_duplicate_state(struct drm_plane *plane)
{
struct rcar_du_plane_state *state;
struct rcar_du_plane_state *copy;
if (WARN_ON(!plane->state))
return NULL;
state = to_rcar_plane_state(plane->state);
copy = kmemdup(state, sizeof(*state), GFP_KERNEL);
if (copy == NULL)
return NULL;
__drm_atomic_helper_plane_duplicate_state(plane, &copy->state);
return &copy->state;
}
static void rcar_du_plane_atomic_destroy_state(struct drm_plane *plane,
struct drm_plane_state *state)
{
__drm_atomic_helper_plane_destroy_state(plane, state);
kfree(to_rcar_plane_state(state));
}
static void rcar_du_plane_reset(struct drm_plane *plane)
{
struct rcar_du_plane_state *state;
if (plane->state) {
rcar_du_plane_atomic_destroy_state(plane, plane->state);
plane->state = NULL;
}
state = kzalloc(sizeof(*state), GFP_KERNEL);
if (state == NULL)
return;
state->hwindex = -1;
state->source = RCAR_DU_PLANE_MEMORY;
state->alpha = 255;
state->colorkey = RCAR_DU_COLORKEY_NONE;
state->zpos = plane->type == DRM_PLANE_TYPE_PRIMARY ? 0 : 1;
plane->state = &state->state;
plane->state->plane = plane;
}
static int rcar_du_plane_atomic_set_property(struct drm_plane *plane,
struct drm_plane_state *state,
struct drm_property *property,
uint64_t val)
{
struct rcar_du_plane_state *rstate = to_rcar_plane_state(state);
struct rcar_du_device *rcdu = to_rcar_plane(plane)->group->dev;
if (property == rcdu->props.alpha)
rstate->alpha = val;
else if (property == rcdu->props.colorkey)
rstate->colorkey = val;
else if (property == rcdu->props.zpos)
rstate->zpos = val;
else
return -EINVAL;
return 0;
}
static int rcar_du_plane_atomic_get_property(struct drm_plane *plane,
const struct drm_plane_state *state, struct drm_property *property,
uint64_t *val)
{
const struct rcar_du_plane_state *rstate =
container_of(state, const struct rcar_du_plane_state, state);
struct rcar_du_device *rcdu = to_rcar_plane(plane)->group->dev;
if (property == rcdu->props.alpha)
*val = rstate->alpha;
else if (property == rcdu->props.colorkey)
*val = rstate->colorkey;
else if (property == rcdu->props.zpos)
*val = rstate->zpos;
else
return -EINVAL;
return 0;
}
int rcar_du_planes_init(struct rcar_du_group *rgrp)
{
struct rcar_du_device *rcdu = rgrp->dev;
unsigned int crtcs;
unsigned int i;
int ret;
rgrp->num_planes = rgrp->num_crtcs + 7;
crtcs = ((1 << rcdu->num_crtcs) - 1) & (3 << (2 * rgrp->index));
for (i = 0; i < rgrp->num_planes; ++i) {
enum drm_plane_type type = i < rgrp->num_crtcs
? DRM_PLANE_TYPE_PRIMARY
: DRM_PLANE_TYPE_OVERLAY;
struct rcar_du_plane *plane = &rgrp->planes[i];
plane->group = rgrp;
ret = drm_universal_plane_init(rcdu->ddev, &plane->plane, crtcs,
&rcar_du_plane_funcs, formats,
ARRAY_SIZE(formats), type,
NULL);
if (ret < 0)
return ret;
drm_plane_helper_add(&plane->plane,
&rcar_du_plane_helper_funcs);
if (type == DRM_PLANE_TYPE_PRIMARY)
continue;
drm_object_attach_property(&plane->plane.base,
rcdu->props.alpha, 255);
drm_object_attach_property(&plane->plane.base,
rcdu->props.colorkey,
RCAR_DU_COLORKEY_NONE);
drm_object_attach_property(&plane->plane.base,
rcdu->props.zpos, 1);
}
return 0;
}
