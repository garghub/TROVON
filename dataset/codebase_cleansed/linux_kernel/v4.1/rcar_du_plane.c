static u32 rcar_du_plane_read(struct rcar_du_group *rgrp,
unsigned int index, u32 reg)
{
return rcar_du_read(rgrp->dev,
rgrp->mmio_offset + index * PLANE_OFF + reg);
}
static void rcar_du_plane_write(struct rcar_du_group *rgrp,
unsigned int index, u32 reg, u32 data)
{
rcar_du_write(rgrp->dev, rgrp->mmio_offset + index * PLANE_OFF + reg,
data);
}
static void rcar_du_plane_setup_fb(struct rcar_du_plane *plane)
{
struct rcar_du_plane_state *state =
to_rcar_du_plane_state(plane->plane.state);
struct drm_framebuffer *fb = plane->plane.state->fb;
struct rcar_du_group *rgrp = plane->group;
unsigned int src_x = state->state.src_x >> 16;
unsigned int src_y = state->state.src_y >> 16;
unsigned int index = state->hwindex;
struct drm_gem_cma_object *gem;
bool interlaced;
u32 mwr;
interlaced = state->state.crtc->state->adjusted_mode.flags
& DRM_MODE_FLAG_INTERLACE;
if (state->format->planes == 2)
mwr = fb->pitches[0];
else
mwr = fb->pitches[0] * 8 / state->format->bpp;
if (interlaced && state->format->bpp == 32)
mwr *= 2;
rcar_du_plane_write(rgrp, index, PnMWR, mwr);
rcar_du_plane_write(rgrp, index, PnSPXR, src_x);
rcar_du_plane_write(rgrp, index, PnSPYR, src_y *
(!interlaced && state->format->bpp == 32 ? 2 : 1));
gem = drm_fb_cma_get_gem_obj(fb, 0);
rcar_du_plane_write(rgrp, index, PnDSA0R, gem->paddr + fb->offsets[0]);
if (state->format->planes == 2) {
index = (index + 1) % 8;
rcar_du_plane_write(rgrp, index, PnMWR, fb->pitches[0]);
rcar_du_plane_write(rgrp, index, PnSPXR, src_x);
rcar_du_plane_write(rgrp, index, PnSPYR, src_y *
(state->format->bpp == 16 ? 2 : 1) / 2);
gem = drm_fb_cma_get_gem_obj(fb, 1);
rcar_du_plane_write(rgrp, index, PnDSA0R,
gem->paddr + fb->offsets[1]);
}
}
static void rcar_du_plane_setup_mode(struct rcar_du_plane *plane,
unsigned int index)
{
struct rcar_du_plane_state *state =
to_rcar_du_plane_state(plane->plane.state);
struct rcar_du_group *rgrp = plane->group;
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
static void __rcar_du_plane_setup(struct rcar_du_plane *plane,
unsigned int index)
{
struct rcar_du_plane_state *state =
to_rcar_du_plane_state(plane->plane.state);
struct rcar_du_group *rgrp = plane->group;
u32 ddcr2 = PnDDCR2_CODE;
u32 ddcr4;
ddcr4 = rcar_du_plane_read(rgrp, index, PnDDCR4);
ddcr4 &= ~PnDDCR4_EDF_MASK;
ddcr4 |= state->format->edf | PnDDCR4_CODE;
rcar_du_plane_setup_mode(plane, index);
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
rcar_du_plane_write(rgrp, index, PnDDCR4, ddcr4);
rcar_du_plane_write(rgrp, index, PnDSXR, plane->plane.state->crtc_w);
rcar_du_plane_write(rgrp, index, PnDSYR, plane->plane.state->crtc_h);
rcar_du_plane_write(rgrp, index, PnDPXR, plane->plane.state->crtc_x);
rcar_du_plane_write(rgrp, index, PnDPYR, plane->plane.state->crtc_y);
rcar_du_plane_write(rgrp, index, PnWASPR, 0);
rcar_du_plane_write(rgrp, index, PnWAMWR, 4095);
rcar_du_plane_write(rgrp, index, PnBTR, 0);
rcar_du_plane_write(rgrp, index, PnMLR, 0);
}
void rcar_du_plane_setup(struct rcar_du_plane *plane)
{
struct rcar_du_plane_state *state =
to_rcar_du_plane_state(plane->plane.state);
__rcar_du_plane_setup(plane, state->hwindex);
if (state->format->planes == 2)
__rcar_du_plane_setup(plane, (state->hwindex + 1) % 8);
rcar_du_plane_setup_fb(plane);
}
static int rcar_du_plane_atomic_check(struct drm_plane *plane,
struct drm_plane_state *state)
{
struct rcar_du_plane_state *rstate = to_rcar_du_plane_state(state);
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
if (plane->state->crtc)
rcar_du_plane_setup(rplane);
}
static void rcar_du_plane_reset(struct drm_plane *plane)
{
struct rcar_du_plane_state *state;
if (plane->state && plane->state->fb)
drm_framebuffer_unreference(plane->state->fb);
kfree(plane->state);
plane->state = NULL;
state = kzalloc(sizeof(*state), GFP_KERNEL);
if (state == NULL)
return;
state->hwindex = -1;
state->alpha = 255;
state->colorkey = RCAR_DU_COLORKEY_NONE;
state->zpos = plane->type == DRM_PLANE_TYPE_PRIMARY ? 0 : 1;
plane->state = &state->state;
plane->state->plane = plane;
}
static struct drm_plane_state *
rcar_du_plane_atomic_duplicate_state(struct drm_plane *plane)
{
struct rcar_du_plane_state *state;
struct rcar_du_plane_state *copy;
state = to_rcar_du_plane_state(plane->state);
copy = kmemdup(state, sizeof(*state), GFP_KERNEL);
if (copy == NULL)
return NULL;
if (copy->state.fb)
drm_framebuffer_reference(copy->state.fb);
return &copy->state;
}
static void rcar_du_plane_atomic_destroy_state(struct drm_plane *plane,
struct drm_plane_state *state)
{
if (state->fb)
drm_framebuffer_unreference(state->fb);
kfree(to_rcar_du_plane_state(state));
}
static int rcar_du_plane_atomic_set_property(struct drm_plane *plane,
struct drm_plane_state *state,
struct drm_property *property,
uint64_t val)
{
struct rcar_du_plane_state *rstate = to_rcar_du_plane_state(state);
struct rcar_du_plane *rplane = to_rcar_plane(plane);
struct rcar_du_group *rgrp = rplane->group;
if (property == rgrp->planes.alpha)
rstate->alpha = val;
else if (property == rgrp->planes.colorkey)
rstate->colorkey = val;
else if (property == rgrp->planes.zpos)
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
struct rcar_du_plane *rplane = to_rcar_plane(plane);
struct rcar_du_group *rgrp = rplane->group;
if (property == rgrp->planes.alpha)
*val = rstate->alpha;
else if (property == rgrp->planes.colorkey)
*val = rstate->colorkey;
else if (property == rgrp->planes.zpos)
*val = rstate->zpos;
else
return -EINVAL;
return 0;
}
int rcar_du_planes_init(struct rcar_du_group *rgrp)
{
struct rcar_du_planes *planes = &rgrp->planes;
struct rcar_du_device *rcdu = rgrp->dev;
unsigned int num_planes;
unsigned int num_crtcs;
unsigned int crtcs;
unsigned int i;
int ret;
planes->alpha =
drm_property_create_range(rcdu->ddev, 0, "alpha", 0, 255);
if (planes->alpha == NULL)
return -ENOMEM;
planes->colorkey =
drm_property_create_range(rcdu->ddev, 0, "colorkey",
0, 0x01ffffff);
if (planes->colorkey == NULL)
return -ENOMEM;
planes->zpos =
drm_property_create_range(rcdu->ddev, 0, "zpos", 1, 7);
if (planes->zpos == NULL)
return -ENOMEM;
num_crtcs = min(rcdu->num_crtcs - 2 * rgrp->index, 2U);
num_planes = num_crtcs + 7;
crtcs = ((1 << rcdu->num_crtcs) - 1) & (3 << (2 * rgrp->index));
for (i = 0; i < num_planes; ++i) {
enum drm_plane_type type = i < num_crtcs
? DRM_PLANE_TYPE_PRIMARY
: DRM_PLANE_TYPE_OVERLAY;
struct rcar_du_plane *plane = &planes->planes[i];
plane->group = rgrp;
ret = drm_universal_plane_init(rcdu->ddev, &plane->plane, crtcs,
&rcar_du_plane_funcs, formats,
ARRAY_SIZE(formats), type);
if (ret < 0)
return ret;
drm_plane_helper_add(&plane->plane,
&rcar_du_plane_helper_funcs);
if (type == DRM_PLANE_TYPE_PRIMARY)
continue;
drm_object_attach_property(&plane->plane.base,
planes->alpha, 255);
drm_object_attach_property(&plane->plane.base,
planes->colorkey,
RCAR_DU_COLORKEY_NONE);
drm_object_attach_property(&plane->plane.base,
planes->zpos, 1);
}
return 0;
}
