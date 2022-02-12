static bool malidp_crtc_mode_fixup(struct drm_crtc *crtc,
const struct drm_display_mode *mode,
struct drm_display_mode *adjusted_mode)
{
struct malidp_drm *malidp = crtc_to_malidp_device(crtc);
struct malidp_hw_device *hwdev = malidp->dev;
long rate, req_rate = mode->crtc_clock * 1000;
if (req_rate) {
rate = clk_round_rate(hwdev->mclk, req_rate);
if (rate < req_rate) {
DRM_DEBUG_DRIVER("mclk clock unable to reach %d kHz\n",
mode->crtc_clock);
return false;
}
rate = clk_round_rate(hwdev->pxlclk, req_rate);
if (rate != req_rate) {
DRM_DEBUG_DRIVER("pxlclk doesn't support %ld Hz\n",
req_rate);
return false;
}
}
return true;
}
static void malidp_crtc_enable(struct drm_crtc *crtc)
{
struct malidp_drm *malidp = crtc_to_malidp_device(crtc);
struct malidp_hw_device *hwdev = malidp->dev;
struct videomode vm;
drm_display_mode_to_videomode(&crtc->state->adjusted_mode, &vm);
clk_prepare_enable(hwdev->pxlclk);
clk_set_rate(hwdev->pxlclk, crtc->state->adjusted_mode.crtc_clock * 1000);
hwdev->modeset(hwdev, &vm);
hwdev->leave_config_mode(hwdev);
drm_crtc_vblank_on(crtc);
}
static void malidp_crtc_disable(struct drm_crtc *crtc)
{
struct malidp_drm *malidp = crtc_to_malidp_device(crtc);
struct malidp_hw_device *hwdev = malidp->dev;
drm_crtc_vblank_off(crtc);
hwdev->enter_config_mode(hwdev);
clk_disable_unprepare(hwdev->pxlclk);
}
static int malidp_crtc_atomic_check(struct drm_crtc *crtc,
struct drm_crtc_state *state)
{
struct malidp_drm *malidp = crtc_to_malidp_device(crtc);
struct malidp_hw_device *hwdev = malidp->dev;
struct drm_plane *plane;
const struct drm_plane_state *pstate;
u32 rot_mem_free, rot_mem_usable;
int rotated_planes = 0;
drm_atomic_crtc_state_for_each_plane_state(plane, pstate, state) {
if (pstate->rotation & MALIDP_ROTATED_MASK)
rotated_planes++;
}
rot_mem_free = hwdev->rotation_memory[0];
if (rotated_planes > 1)
rot_mem_free += hwdev->rotation_memory[1];
drm_atomic_crtc_state_for_each_plane_state(plane, pstate, state) {
struct malidp_plane *mp = to_malidp_plane(plane);
struct malidp_plane_state *ms = to_malidp_plane_state(pstate);
if (pstate->rotation & MALIDP_ROTATED_MASK) {
rotated_planes--;
if (!rotated_planes) {
rot_mem_usable = rot_mem_free;
} else {
if ((mp->layer->id != DE_VIDEO1) ||
(hwdev->rotation_memory[1] == 0))
rot_mem_usable = rot_mem_free / 2;
else
rot_mem_usable = hwdev->rotation_memory[0];
}
rot_mem_free -= rot_mem_usable;
if (ms->rotmem_size > rot_mem_usable)
return -EINVAL;
}
}
return 0;
}
int malidp_crtc_init(struct drm_device *drm)
{
struct malidp_drm *malidp = drm->dev_private;
struct drm_plane *primary = NULL, *plane;
int ret;
ret = malidp_de_planes_init(drm);
if (ret < 0) {
DRM_ERROR("Failed to initialise planes\n");
return ret;
}
drm_for_each_plane(plane, drm) {
if (plane->type == DRM_PLANE_TYPE_PRIMARY) {
primary = plane;
break;
}
}
if (!primary) {
DRM_ERROR("no primary plane found\n");
ret = -EINVAL;
goto crtc_cleanup_planes;
}
ret = drm_crtc_init_with_planes(drm, &malidp->crtc, primary, NULL,
&malidp_crtc_funcs, NULL);
if (!ret) {
drm_crtc_helper_add(&malidp->crtc, &malidp_crtc_helper_funcs);
return 0;
}
crtc_cleanup_planes:
malidp_de_planes_destroy(drm);
return ret;
}
