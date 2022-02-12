static struct mdp5_kms *get_kms(struct drm_plane *plane)
{
struct msm_drm_private *priv = plane->dev->dev_private;
return to_mdp5_kms(to_mdp_kms(priv->kms));
}
static bool plane_enabled(struct drm_plane_state *state)
{
return state->fb && state->crtc;
}
static int mdp5_plane_disable(struct drm_plane *plane)
{
struct mdp5_plane *mdp5_plane = to_mdp5_plane(plane);
struct mdp5_kms *mdp5_kms = get_kms(plane);
enum mdp5_pipe pipe = mdp5_plane->pipe;
DBG("%s: disable", mdp5_plane->name);
if (mdp5_kms) {
mdp5_smp_release(mdp5_kms->smp, pipe);
}
return 0;
}
static void mdp5_plane_destroy(struct drm_plane *plane)
{
struct mdp5_plane *mdp5_plane = to_mdp5_plane(plane);
drm_plane_helper_disable(plane);
drm_plane_cleanup(plane);
kfree(mdp5_plane);
}
void mdp5_plane_install_properties(struct drm_plane *plane,
struct drm_mode_object *obj)
{
}
int mdp5_plane_set_property(struct drm_plane *plane,
struct drm_property *property, uint64_t val)
{
return -EINVAL;
}
static void mdp5_plane_reset(struct drm_plane *plane)
{
struct mdp5_plane_state *mdp5_state;
if (plane->state && plane->state->fb)
drm_framebuffer_unreference(plane->state->fb);
kfree(to_mdp5_plane_state(plane->state));
mdp5_state = kzalloc(sizeof(*mdp5_state), GFP_KERNEL);
if (plane->type == DRM_PLANE_TYPE_PRIMARY) {
mdp5_state->zpos = 0;
} else {
mdp5_state->zpos = 1 + drm_plane_index(plane);
}
plane->state = &mdp5_state->base;
}
static struct drm_plane_state *
mdp5_plane_duplicate_state(struct drm_plane *plane)
{
struct mdp5_plane_state *mdp5_state;
if (WARN_ON(!plane->state))
return NULL;
mdp5_state = kmemdup(to_mdp5_plane_state(plane->state),
sizeof(*mdp5_state), GFP_KERNEL);
if (mdp5_state && mdp5_state->base.fb)
drm_framebuffer_reference(mdp5_state->base.fb);
mdp5_state->mode_changed = false;
mdp5_state->pending = false;
return &mdp5_state->base;
}
static void mdp5_plane_destroy_state(struct drm_plane *plane,
struct drm_plane_state *state)
{
if (state->fb)
drm_framebuffer_unreference(state->fb);
kfree(to_mdp5_plane_state(state));
}
static int mdp5_plane_prepare_fb(struct drm_plane *plane,
struct drm_framebuffer *fb)
{
struct mdp5_plane *mdp5_plane = to_mdp5_plane(plane);
struct mdp5_kms *mdp5_kms = get_kms(plane);
DBG("%s: prepare: FB[%u]", mdp5_plane->name, fb->base.id);
return msm_framebuffer_prepare(fb, mdp5_kms->id);
}
static void mdp5_plane_cleanup_fb(struct drm_plane *plane,
struct drm_framebuffer *fb)
{
struct mdp5_plane *mdp5_plane = to_mdp5_plane(plane);
struct mdp5_kms *mdp5_kms = get_kms(plane);
DBG("%s: cleanup: FB[%u]", mdp5_plane->name, fb->base.id);
msm_framebuffer_cleanup(fb, mdp5_kms->id);
}
static int mdp5_plane_atomic_check(struct drm_plane *plane,
struct drm_plane_state *state)
{
struct mdp5_plane *mdp5_plane = to_mdp5_plane(plane);
struct drm_plane_state *old_state = plane->state;
DBG("%s: check (%d -> %d)", mdp5_plane->name,
plane_enabled(old_state), plane_enabled(state));
if (plane_enabled(state) && plane_enabled(old_state)) {
bool full_modeset = false;
if (state->fb->pixel_format != old_state->fb->pixel_format) {
DBG("%s: pixel_format change!", mdp5_plane->name);
full_modeset = true;
}
if (state->src_w != old_state->src_w) {
DBG("%s: src_w change!", mdp5_plane->name);
full_modeset = true;
}
if (to_mdp5_plane_state(old_state)->pending) {
DBG("%s: still pending!", mdp5_plane->name);
full_modeset = true;
}
if (full_modeset) {
struct drm_crtc_state *crtc_state =
drm_atomic_get_crtc_state(state->state, state->crtc);
crtc_state->mode_changed = true;
to_mdp5_plane_state(state)->mode_changed = true;
}
} else {
to_mdp5_plane_state(state)->mode_changed = true;
}
return 0;
}
static void mdp5_plane_atomic_update(struct drm_plane *plane,
struct drm_plane_state *old_state)
{
struct mdp5_plane *mdp5_plane = to_mdp5_plane(plane);
struct drm_plane_state *state = plane->state;
DBG("%s: update", mdp5_plane->name);
if (!plane_enabled(state)) {
to_mdp5_plane_state(state)->pending = true;
mdp5_plane_disable(plane);
} else if (to_mdp5_plane_state(state)->mode_changed) {
int ret;
to_mdp5_plane_state(state)->pending = true;
ret = mdp5_plane_mode_set(plane,
state->crtc, state->fb,
state->crtc_x, state->crtc_y,
state->crtc_w, state->crtc_h,
state->src_x, state->src_y,
state->src_w, state->src_h);
WARN_ON(ret < 0);
} else {
unsigned long flags;
spin_lock_irqsave(&mdp5_plane->pipe_lock, flags);
set_scanout_locked(plane, state->fb);
spin_unlock_irqrestore(&mdp5_plane->pipe_lock, flags);
}
}
static void set_scanout_locked(struct drm_plane *plane,
struct drm_framebuffer *fb)
{
struct mdp5_plane *mdp5_plane = to_mdp5_plane(plane);
struct mdp5_kms *mdp5_kms = get_kms(plane);
enum mdp5_pipe pipe = mdp5_plane->pipe;
mdp5_write(mdp5_kms, REG_MDP5_PIPE_SRC_STRIDE_A(pipe),
MDP5_PIPE_SRC_STRIDE_A_P0(fb->pitches[0]) |
MDP5_PIPE_SRC_STRIDE_A_P1(fb->pitches[1]));
mdp5_write(mdp5_kms, REG_MDP5_PIPE_SRC_STRIDE_B(pipe),
MDP5_PIPE_SRC_STRIDE_B_P2(fb->pitches[2]) |
MDP5_PIPE_SRC_STRIDE_B_P3(fb->pitches[3]));
mdp5_write(mdp5_kms, REG_MDP5_PIPE_SRC0_ADDR(pipe),
msm_framebuffer_iova(fb, mdp5_kms->id, 0));
mdp5_write(mdp5_kms, REG_MDP5_PIPE_SRC1_ADDR(pipe),
msm_framebuffer_iova(fb, mdp5_kms->id, 1));
mdp5_write(mdp5_kms, REG_MDP5_PIPE_SRC2_ADDR(pipe),
msm_framebuffer_iova(fb, mdp5_kms->id, 2));
mdp5_write(mdp5_kms, REG_MDP5_PIPE_SRC3_ADDR(pipe),
msm_framebuffer_iova(fb, mdp5_kms->id, 4));
plane->fb = fb;
}
static int mdp5_plane_mode_set(struct drm_plane *plane,
struct drm_crtc *crtc, struct drm_framebuffer *fb,
int crtc_x, int crtc_y,
unsigned int crtc_w, unsigned int crtc_h,
uint32_t src_x, uint32_t src_y,
uint32_t src_w, uint32_t src_h)
{
struct mdp5_plane *mdp5_plane = to_mdp5_plane(plane);
struct mdp5_kms *mdp5_kms = get_kms(plane);
enum mdp5_pipe pipe = mdp5_plane->pipe;
const struct mdp_format *format;
uint32_t nplanes, config = 0;
uint32_t phasex_step = 0, phasey_step = 0;
uint32_t hdecm = 0, vdecm = 0;
unsigned long flags;
int ret;
nplanes = drm_format_num_planes(fb->pixel_format);
if (WARN_ON(nplanes > pipe2nclients(pipe)))
return -EINVAL;
src_x = src_x >> 16;
src_y = src_y >> 16;
src_w = src_w >> 16;
src_h = src_h >> 16;
DBG("%s: FB[%u] %u,%u,%u,%u -> CRTC[%u] %d,%d,%u,%u", mdp5_plane->name,
fb->base.id, src_x, src_y, src_w, src_h,
crtc->base.id, crtc_x, crtc_y, crtc_w, crtc_h);
ret = mdp5_smp_request(mdp5_kms->smp,
mdp5_plane->pipe, fb->pixel_format, src_w);
if (ret)
return ret;
mdp5_smp_configure(mdp5_kms->smp, pipe);
if (src_w != crtc_w) {
config |= MDP5_PIPE_SCALE_CONFIG_SCALEX_EN;
}
if (src_h != crtc_h) {
config |= MDP5_PIPE_SCALE_CONFIG_SCALEY_EN;
}
spin_lock_irqsave(&mdp5_plane->pipe_lock, flags);
mdp5_write(mdp5_kms, REG_MDP5_PIPE_SRC_IMG_SIZE(pipe),
MDP5_PIPE_SRC_IMG_SIZE_WIDTH(src_w) |
MDP5_PIPE_SRC_IMG_SIZE_HEIGHT(src_h));
mdp5_write(mdp5_kms, REG_MDP5_PIPE_SRC_SIZE(pipe),
MDP5_PIPE_SRC_SIZE_WIDTH(src_w) |
MDP5_PIPE_SRC_SIZE_HEIGHT(src_h));
mdp5_write(mdp5_kms, REG_MDP5_PIPE_SRC_XY(pipe),
MDP5_PIPE_SRC_XY_X(src_x) |
MDP5_PIPE_SRC_XY_Y(src_y));
mdp5_write(mdp5_kms, REG_MDP5_PIPE_OUT_SIZE(pipe),
MDP5_PIPE_OUT_SIZE_WIDTH(crtc_w) |
MDP5_PIPE_OUT_SIZE_HEIGHT(crtc_h));
mdp5_write(mdp5_kms, REG_MDP5_PIPE_OUT_XY(pipe),
MDP5_PIPE_OUT_XY_X(crtc_x) |
MDP5_PIPE_OUT_XY_Y(crtc_y));
format = to_mdp_format(msm_framebuffer_format(fb));
mdp5_write(mdp5_kms, REG_MDP5_PIPE_SRC_FORMAT(pipe),
MDP5_PIPE_SRC_FORMAT_A_BPC(format->bpc_a) |
MDP5_PIPE_SRC_FORMAT_R_BPC(format->bpc_r) |
MDP5_PIPE_SRC_FORMAT_G_BPC(format->bpc_g) |
MDP5_PIPE_SRC_FORMAT_B_BPC(format->bpc_b) |
COND(format->alpha_enable, MDP5_PIPE_SRC_FORMAT_ALPHA_ENABLE) |
MDP5_PIPE_SRC_FORMAT_CPP(format->cpp - 1) |
MDP5_PIPE_SRC_FORMAT_UNPACK_COUNT(format->unpack_count - 1) |
COND(format->unpack_tight, MDP5_PIPE_SRC_FORMAT_UNPACK_TIGHT) |
MDP5_PIPE_SRC_FORMAT_NUM_PLANES(nplanes - 1) |
MDP5_PIPE_SRC_FORMAT_CHROMA_SAMP(CHROMA_RGB));
mdp5_write(mdp5_kms, REG_MDP5_PIPE_SRC_UNPACK(pipe),
MDP5_PIPE_SRC_UNPACK_ELEM0(format->unpack[0]) |
MDP5_PIPE_SRC_UNPACK_ELEM1(format->unpack[1]) |
MDP5_PIPE_SRC_UNPACK_ELEM2(format->unpack[2]) |
MDP5_PIPE_SRC_UNPACK_ELEM3(format->unpack[3]));
mdp5_write(mdp5_kms, REG_MDP5_PIPE_SRC_OP_MODE(pipe),
MDP5_PIPE_SRC_OP_MODE_BWC(BWC_LOSSLESS));
mdp5_write(mdp5_kms, REG_MDP5_PIPE_SRC_ADDR_SW_STATUS(pipe), 0);
mdp5_write(mdp5_kms, REG_MDP5_PIPE_SCALE_PHASE_STEP_X(pipe), phasex_step);
mdp5_write(mdp5_kms, REG_MDP5_PIPE_SCALE_PHASE_STEP_Y(pipe), phasey_step);
mdp5_write(mdp5_kms, REG_MDP5_PIPE_DECIMATION(pipe),
MDP5_PIPE_DECIMATION_VERT(vdecm) |
MDP5_PIPE_DECIMATION_HORZ(hdecm));
mdp5_write(mdp5_kms, REG_MDP5_PIPE_SCALE_CONFIG(pipe),
MDP5_PIPE_SCALE_CONFIG_SCALEX_MIN_FILTER(SCALE_FILTER_NEAREST) |
MDP5_PIPE_SCALE_CONFIG_SCALEY_MIN_FILTER(SCALE_FILTER_NEAREST) |
MDP5_PIPE_SCALE_CONFIG_SCALEX_CR_FILTER(SCALE_FILTER_NEAREST) |
MDP5_PIPE_SCALE_CONFIG_SCALEY_CR_FILTER(SCALE_FILTER_NEAREST) |
MDP5_PIPE_SCALE_CONFIG_SCALEX_MAX_FILTER(SCALE_FILTER_NEAREST) |
MDP5_PIPE_SCALE_CONFIG_SCALEY_MAX_FILTER(SCALE_FILTER_NEAREST));
set_scanout_locked(plane, fb);
spin_unlock_irqrestore(&mdp5_plane->pipe_lock, flags);
return ret;
}
void mdp5_plane_complete_flip(struct drm_plane *plane)
{
struct mdp5_kms *mdp5_kms = get_kms(plane);
struct mdp5_plane *mdp5_plane = to_mdp5_plane(plane);
enum mdp5_pipe pipe = mdp5_plane->pipe;
DBG("%s: complete flip", mdp5_plane->name);
mdp5_smp_commit(mdp5_kms->smp, pipe);
to_mdp5_plane_state(plane->state)->pending = false;
}
enum mdp5_pipe mdp5_plane_pipe(struct drm_plane *plane)
{
struct mdp5_plane *mdp5_plane = to_mdp5_plane(plane);
return mdp5_plane->pipe;
}
uint32_t mdp5_plane_get_flush(struct drm_plane *plane)
{
struct mdp5_plane *mdp5_plane = to_mdp5_plane(plane);
return mdp5_plane->flush_mask;
}
struct drm_plane *mdp5_plane_init(struct drm_device *dev,
enum mdp5_pipe pipe, bool private_plane, uint32_t reg_offset)
{
struct drm_plane *plane = NULL;
struct mdp5_plane *mdp5_plane;
int ret;
enum drm_plane_type type;
mdp5_plane = kzalloc(sizeof(*mdp5_plane), GFP_KERNEL);
if (!mdp5_plane) {
ret = -ENOMEM;
goto fail;
}
plane = &mdp5_plane->base;
mdp5_plane->pipe = pipe;
mdp5_plane->name = pipe2name(pipe);
mdp5_plane->nformats = mdp5_get_formats(pipe, mdp5_plane->formats,
ARRAY_SIZE(mdp5_plane->formats));
mdp5_plane->flush_mask = mdp_ctl_flush_mask_pipe(pipe);
mdp5_plane->reg_offset = reg_offset;
spin_lock_init(&mdp5_plane->pipe_lock);
type = private_plane ? DRM_PLANE_TYPE_PRIMARY : DRM_PLANE_TYPE_OVERLAY;
ret = drm_universal_plane_init(dev, plane, 0xff, &mdp5_plane_funcs,
mdp5_plane->formats, mdp5_plane->nformats,
type);
if (ret)
goto fail;
drm_plane_helper_add(plane, &mdp5_plane_helper_funcs);
mdp5_plane_install_properties(plane, &plane->base);
return plane;
fail:
if (plane)
mdp5_plane_destroy(plane);
return ERR_PTR(ret);
}
