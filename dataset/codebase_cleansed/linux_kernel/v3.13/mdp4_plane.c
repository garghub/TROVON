static struct mdp4_kms *get_kms(struct drm_plane *plane)
{
struct msm_drm_private *priv = plane->dev->dev_private;
return to_mdp4_kms(priv->kms);
}
static int mdp4_plane_update(struct drm_plane *plane,
struct drm_crtc *crtc, struct drm_framebuffer *fb,
int crtc_x, int crtc_y,
unsigned int crtc_w, unsigned int crtc_h,
uint32_t src_x, uint32_t src_y,
uint32_t src_w, uint32_t src_h)
{
struct mdp4_plane *mdp4_plane = to_mdp4_plane(plane);
mdp4_plane->enabled = true;
if (plane->fb)
drm_framebuffer_unreference(plane->fb);
drm_framebuffer_reference(fb);
return mdp4_plane_mode_set(plane, crtc, fb,
crtc_x, crtc_y, crtc_w, crtc_h,
src_x, src_y, src_w, src_h);
}
static int mdp4_plane_disable(struct drm_plane *plane)
{
struct mdp4_plane *mdp4_plane = to_mdp4_plane(plane);
DBG("%s: disable", mdp4_plane->name);
if (plane->crtc)
mdp4_crtc_detach(plane->crtc, plane);
return 0;
}
static void mdp4_plane_destroy(struct drm_plane *plane)
{
struct mdp4_plane *mdp4_plane = to_mdp4_plane(plane);
mdp4_plane_disable(plane);
drm_plane_cleanup(plane);
kfree(mdp4_plane);
}
void mdp4_plane_install_properties(struct drm_plane *plane,
struct drm_mode_object *obj)
{
}
int mdp4_plane_set_property(struct drm_plane *plane,
struct drm_property *property, uint64_t val)
{
return -EINVAL;
}
void mdp4_plane_set_scanout(struct drm_plane *plane,
struct drm_framebuffer *fb)
{
struct mdp4_plane *mdp4_plane = to_mdp4_plane(plane);
struct mdp4_kms *mdp4_kms = get_kms(plane);
enum mdp4_pipe pipe = mdp4_plane->pipe;
uint32_t iova;
mdp4_write(mdp4_kms, REG_MDP4_PIPE_SRC_STRIDE_A(pipe),
MDP4_PIPE_SRC_STRIDE_A_P0(fb->pitches[0]) |
MDP4_PIPE_SRC_STRIDE_A_P1(fb->pitches[1]));
mdp4_write(mdp4_kms, REG_MDP4_PIPE_SRC_STRIDE_B(pipe),
MDP4_PIPE_SRC_STRIDE_B_P2(fb->pitches[2]) |
MDP4_PIPE_SRC_STRIDE_B_P3(fb->pitches[3]));
msm_gem_get_iova(msm_framebuffer_bo(fb, 0), mdp4_kms->id, &iova);
mdp4_write(mdp4_kms, REG_MDP4_PIPE_SRCP0_BASE(pipe), iova);
plane->fb = fb;
}
int mdp4_plane_mode_set(struct drm_plane *plane,
struct drm_crtc *crtc, struct drm_framebuffer *fb,
int crtc_x, int crtc_y,
unsigned int crtc_w, unsigned int crtc_h,
uint32_t src_x, uint32_t src_y,
uint32_t src_w, uint32_t src_h)
{
struct mdp4_plane *mdp4_plane = to_mdp4_plane(plane);
struct mdp4_kms *mdp4_kms = get_kms(plane);
enum mdp4_pipe pipe = mdp4_plane->pipe;
const struct mdp4_format *format;
uint32_t op_mode = 0;
uint32_t phasex_step = MDP4_VG_PHASE_STEP_DEFAULT;
uint32_t phasey_step = MDP4_VG_PHASE_STEP_DEFAULT;
src_x = src_x >> 16;
src_y = src_y >> 16;
src_w = src_w >> 16;
src_h = src_h >> 16;
DBG("%s: FB[%u] %u,%u,%u,%u -> CRTC[%u] %d,%d,%u,%u", mdp4_plane->name,
fb->base.id, src_x, src_y, src_w, src_h,
crtc->base.id, crtc_x, crtc_y, crtc_w, crtc_h);
if (src_w != crtc_w) {
op_mode |= MDP4_PIPE_OP_MODE_SCALEX_EN;
}
if (src_h != crtc_h) {
op_mode |= MDP4_PIPE_OP_MODE_SCALEY_EN;
}
mdp4_write(mdp4_kms, REG_MDP4_PIPE_SRC_SIZE(pipe),
MDP4_PIPE_SRC_SIZE_WIDTH(src_w) |
MDP4_PIPE_SRC_SIZE_HEIGHT(src_h));
mdp4_write(mdp4_kms, REG_MDP4_PIPE_SRC_XY(pipe),
MDP4_PIPE_SRC_XY_X(src_x) |
MDP4_PIPE_SRC_XY_Y(src_y));
mdp4_write(mdp4_kms, REG_MDP4_PIPE_DST_SIZE(pipe),
MDP4_PIPE_DST_SIZE_WIDTH(crtc_w) |
MDP4_PIPE_DST_SIZE_HEIGHT(crtc_h));
mdp4_write(mdp4_kms, REG_MDP4_PIPE_DST_XY(pipe),
MDP4_PIPE_SRC_XY_X(crtc_x) |
MDP4_PIPE_SRC_XY_Y(crtc_y));
mdp4_plane_set_scanout(plane, fb);
format = to_mdp4_format(msm_framebuffer_format(fb));
mdp4_write(mdp4_kms, REG_MDP4_PIPE_SRC_FORMAT(pipe),
MDP4_PIPE_SRC_FORMAT_A_BPC(format->bpc_a) |
MDP4_PIPE_SRC_FORMAT_R_BPC(format->bpc_r) |
MDP4_PIPE_SRC_FORMAT_G_BPC(format->bpc_g) |
MDP4_PIPE_SRC_FORMAT_B_BPC(format->bpc_b) |
COND(format->alpha_enable, MDP4_PIPE_SRC_FORMAT_ALPHA_ENABLE) |
MDP4_PIPE_SRC_FORMAT_CPP(format->cpp - 1) |
MDP4_PIPE_SRC_FORMAT_UNPACK_COUNT(format->unpack_count - 1) |
COND(format->unpack_tight, MDP4_PIPE_SRC_FORMAT_UNPACK_TIGHT));
mdp4_write(mdp4_kms, REG_MDP4_PIPE_SRC_UNPACK(pipe),
MDP4_PIPE_SRC_UNPACK_ELEM0(format->unpack[0]) |
MDP4_PIPE_SRC_UNPACK_ELEM1(format->unpack[1]) |
MDP4_PIPE_SRC_UNPACK_ELEM2(format->unpack[2]) |
MDP4_PIPE_SRC_UNPACK_ELEM3(format->unpack[3]));
mdp4_write(mdp4_kms, REG_MDP4_PIPE_OP_MODE(pipe), op_mode);
mdp4_write(mdp4_kms, REG_MDP4_PIPE_PHASEX_STEP(pipe), phasex_step);
mdp4_write(mdp4_kms, REG_MDP4_PIPE_PHASEY_STEP(pipe), phasey_step);
mdp4_crtc_attach(crtc, plane);
return 0;
}
enum mdp4_pipe mdp4_plane_pipe(struct drm_plane *plane)
{
struct mdp4_plane *mdp4_plane = to_mdp4_plane(plane);
return mdp4_plane->pipe;
}
struct drm_plane *mdp4_plane_init(struct drm_device *dev,
enum mdp4_pipe pipe_id, bool private_plane)
{
struct drm_plane *plane = NULL;
struct mdp4_plane *mdp4_plane;
int ret;
mdp4_plane = kzalloc(sizeof(*mdp4_plane), GFP_KERNEL);
if (!mdp4_plane) {
ret = -ENOMEM;
goto fail;
}
plane = &mdp4_plane->base;
mdp4_plane->pipe = pipe_id;
mdp4_plane->name = pipe_names[pipe_id];
mdp4_plane->nformats = mdp4_get_formats(pipe_id, mdp4_plane->formats,
ARRAY_SIZE(mdp4_plane->formats));
drm_plane_init(dev, plane, 0xff, &mdp4_plane_funcs,
mdp4_plane->formats, mdp4_plane->nformats,
private_plane);
mdp4_plane_install_properties(plane, &plane->base);
return plane;
fail:
if (plane)
mdp4_plane_destroy(plane);
return ERR_PTR(ret);
}
