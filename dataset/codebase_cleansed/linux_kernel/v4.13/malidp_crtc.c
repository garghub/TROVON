static enum drm_mode_status malidp_crtc_mode_valid(struct drm_crtc *crtc,
const struct drm_display_mode *mode)
{
struct malidp_drm *malidp = crtc_to_malidp_device(crtc);
struct malidp_hw_device *hwdev = malidp->dev;
long rate, req_rate = mode->crtc_clock * 1000;
if (req_rate) {
rate = clk_round_rate(hwdev->pxlclk, req_rate);
if (rate != req_rate) {
DRM_DEBUG_DRIVER("pxlclk doesn't support %ld Hz\n",
req_rate);
return MODE_NOCLOCK;
}
}
return MODE_OK;
}
static void malidp_crtc_enable(struct drm_crtc *crtc)
{
struct malidp_drm *malidp = crtc_to_malidp_device(crtc);
struct malidp_hw_device *hwdev = malidp->dev;
struct videomode vm;
int err = pm_runtime_get_sync(crtc->dev->dev);
if (err < 0) {
DRM_DEBUG_DRIVER("Failed to enable runtime power management: %d\n", err);
return;
}
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
int err;
drm_crtc_vblank_off(crtc);
hwdev->enter_config_mode(hwdev);
clk_disable_unprepare(hwdev->pxlclk);
err = pm_runtime_put(crtc->dev->dev);
if (err < 0) {
DRM_DEBUG_DRIVER("Failed to disable runtime power management: %d\n", err);
}
}
static void malidp_generate_gamma_table(struct drm_property_blob *lut_blob,
u32 coeffs[MALIDP_COEFFTAB_NUM_COEFFS])
{
struct drm_color_lut *lut = (struct drm_color_lut *)lut_blob->data;
int i;
for (i = 0; i < MALIDP_COEFFTAB_NUM_COEFFS; ++i) {
u32 a, b, delta_in, out_start, out_end;
delta_in = segments[i].end - segments[i].start;
out_start = drm_color_lut_extract(lut[segments[i].start].green,
12);
out_end = drm_color_lut_extract(lut[segments[i].end].green, 12);
a = (delta_in == 0) ? 0 : ((out_end - out_start) * 256) / delta_in;
b = out_start;
coeffs[i] = DE_COEFTAB_DATA(a, b);
}
}
static int malidp_crtc_atomic_check_gamma(struct drm_crtc *crtc,
struct drm_crtc_state *state)
{
struct malidp_crtc_state *mc = to_malidp_crtc_state(state);
struct drm_color_lut *lut;
size_t lut_size;
int i;
if (!state->color_mgmt_changed || !state->gamma_lut)
return 0;
if (crtc->state->gamma_lut &&
(crtc->state->gamma_lut->base.id == state->gamma_lut->base.id))
return 0;
if (state->gamma_lut->length % sizeof(struct drm_color_lut))
return -EINVAL;
lut_size = state->gamma_lut->length / sizeof(struct drm_color_lut);
if (lut_size != MALIDP_GAMMA_LUT_SIZE)
return -EINVAL;
lut = (struct drm_color_lut *)state->gamma_lut->data;
for (i = 0; i < lut_size; ++i)
if (!((lut[i].red == lut[i].green) &&
(lut[i].red == lut[i].blue)))
return -EINVAL;
if (!state->mode_changed) {
int ret;
state->mode_changed = true;
ret = drm_atomic_helper_check_modeset(crtc->dev, state->state);
if (ret)
return ret;
}
malidp_generate_gamma_table(state->gamma_lut, mc->gamma_coeffs);
return 0;
}
static int malidp_crtc_atomic_check_ctm(struct drm_crtc *crtc,
struct drm_crtc_state *state)
{
struct malidp_crtc_state *mc = to_malidp_crtc_state(state);
struct drm_color_ctm *ctm;
int i;
if (!state->color_mgmt_changed)
return 0;
if (!state->ctm)
return 0;
if (crtc->state->ctm && (crtc->state->ctm->base.id ==
state->ctm->base.id))
return 0;
ctm = (struct drm_color_ctm *)state->ctm->data;
for (i = 0; i < ARRAY_SIZE(ctm->matrix); ++i) {
s64 val = ctm->matrix[i];
u32 mag = ((((u64)val) & ~BIT_ULL(63)) >> 20) &
GENMASK_ULL(14, 0);
if (val & BIT_ULL(63))
mag = ~mag + 1;
if (!!(val & BIT_ULL(63)) != !!(mag & BIT(14)))
return -EINVAL;
mc->coloradj_coeffs[i] = mag;
}
return 0;
}
static int malidp_crtc_atomic_check_scaling(struct drm_crtc *crtc,
struct drm_crtc_state *state)
{
struct malidp_drm *malidp = crtc_to_malidp_device(crtc);
struct malidp_hw_device *hwdev = malidp->dev;
struct malidp_crtc_state *cs = to_malidp_crtc_state(state);
struct malidp_se_config *s = &cs->scaler_config;
struct drm_plane *plane;
struct videomode vm;
const struct drm_plane_state *pstate;
u32 h_upscale_factor = 0;
u32 v_upscale_factor = 0;
u8 scaling = cs->scaled_planes_mask;
int ret;
if (!scaling) {
s->scale_enable = false;
goto mclk_calc;
}
if (scaling & (scaling - 1))
return -EINVAL;
drm_atomic_crtc_state_for_each_plane_state(plane, pstate, state) {
struct malidp_plane *mp = to_malidp_plane(plane);
u32 phase;
if (!(mp->layer->id & scaling))
continue;
h_upscale_factor = div_u64((u64)pstate->crtc_w << 32,
pstate->src_w);
v_upscale_factor = div_u64((u64)pstate->crtc_h << 32,
pstate->src_h);
s->enhancer_enable = ((h_upscale_factor >> 16) >= 2 ||
(v_upscale_factor >> 16) >= 2);
s->input_w = pstate->src_w >> 16;
s->input_h = pstate->src_h >> 16;
s->output_w = pstate->crtc_w;
s->output_h = pstate->crtc_h;
#define SE_N_PHASE 4
#define SE_SHIFT_N_PHASE 12
phase = s->input_w;
s->h_init_phase =
((phase << SE_N_PHASE) / s->output_w + 1) / 2;
phase = s->input_w;
phase <<= (SE_SHIFT_N_PHASE + SE_N_PHASE);
s->h_delta_phase = phase / s->output_w;
phase = s->input_h;
s->v_init_phase =
((phase << SE_N_PHASE) / s->output_h + 1) / 2;
phase = s->input_h;
phase <<= (SE_SHIFT_N_PHASE + SE_N_PHASE);
s->v_delta_phase = phase / s->output_h;
#undef SE_N_PHASE
#undef SE_SHIFT_N_PHASE
s->plane_src_id = mp->layer->id;
}
s->scale_enable = true;
s->hcoeff = malidp_se_select_coeffs(h_upscale_factor);
s->vcoeff = malidp_se_select_coeffs(v_upscale_factor);
mclk_calc:
drm_display_mode_to_videomode(&state->adjusted_mode, &vm);
ret = hwdev->se_calc_mclk(hwdev, s, &vm);
if (ret < 0)
return -EINVAL;
return 0;
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
int ret;
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
ret = malidp_crtc_atomic_check_gamma(crtc, state);
ret = ret ? ret : malidp_crtc_atomic_check_ctm(crtc, state);
ret = ret ? ret : malidp_crtc_atomic_check_scaling(crtc, state);
return ret;
}
static struct drm_crtc_state *malidp_crtc_duplicate_state(struct drm_crtc *crtc)
{
struct malidp_crtc_state *state, *old_state;
if (WARN_ON(!crtc->state))
return NULL;
old_state = to_malidp_crtc_state(crtc->state);
state = kmalloc(sizeof(*state), GFP_KERNEL);
if (!state)
return NULL;
__drm_atomic_helper_crtc_duplicate_state(crtc, &state->base);
memcpy(state->gamma_coeffs, old_state->gamma_coeffs,
sizeof(state->gamma_coeffs));
memcpy(state->coloradj_coeffs, old_state->coloradj_coeffs,
sizeof(state->coloradj_coeffs));
memcpy(&state->scaler_config, &old_state->scaler_config,
sizeof(state->scaler_config));
state->scaled_planes_mask = 0;
return &state->base;
}
static void malidp_crtc_reset(struct drm_crtc *crtc)
{
struct malidp_crtc_state *state = NULL;
if (crtc->state) {
state = to_malidp_crtc_state(crtc->state);
__drm_atomic_helper_crtc_destroy_state(crtc->state);
}
kfree(state);
state = kzalloc(sizeof(*state), GFP_KERNEL);
if (state) {
crtc->state = &state->base;
crtc->state->crtc = crtc;
}
}
static void malidp_crtc_destroy_state(struct drm_crtc *crtc,
struct drm_crtc_state *state)
{
struct malidp_crtc_state *mali_state = NULL;
if (state) {
mali_state = to_malidp_crtc_state(state);
__drm_atomic_helper_crtc_destroy_state(state);
}
kfree(mali_state);
}
static int malidp_crtc_enable_vblank(struct drm_crtc *crtc)
{
struct malidp_drm *malidp = crtc_to_malidp_device(crtc);
struct malidp_hw_device *hwdev = malidp->dev;
malidp_hw_enable_irq(hwdev, MALIDP_DE_BLOCK,
hwdev->map.de_irq_map.vsync_irq);
return 0;
}
static void malidp_crtc_disable_vblank(struct drm_crtc *crtc)
{
struct malidp_drm *malidp = crtc_to_malidp_device(crtc);
struct malidp_hw_device *hwdev = malidp->dev;
malidp_hw_disable_irq(hwdev, MALIDP_DE_BLOCK,
hwdev->map.de_irq_map.vsync_irq);
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
if (ret)
goto crtc_cleanup_planes;
drm_crtc_helper_add(&malidp->crtc, &malidp_crtc_helper_funcs);
drm_mode_crtc_set_gamma_size(&malidp->crtc, MALIDP_GAMMA_LUT_SIZE);
drm_crtc_enable_color_mgmt(&malidp->crtc, 0, true, MALIDP_GAMMA_LUT_SIZE);
malidp_se_set_enh_coeffs(malidp->dev);
return 0;
crtc_cleanup_planes:
malidp_de_planes_destroy(drm);
return ret;
}
