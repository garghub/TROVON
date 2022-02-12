static void malidp_de_plane_destroy(struct drm_plane *plane)
{
struct malidp_plane *mp = to_malidp_plane(plane);
if (mp->base.fb)
drm_framebuffer_unreference(mp->base.fb);
drm_plane_helper_disable(plane);
drm_plane_cleanup(plane);
devm_kfree(plane->dev->dev, mp);
}
static void malidp_plane_reset(struct drm_plane *plane)
{
struct malidp_plane_state *state = to_malidp_plane_state(plane->state);
if (state)
__drm_atomic_helper_plane_destroy_state(&state->base);
kfree(state);
plane->state = NULL;
state = kzalloc(sizeof(*state), GFP_KERNEL);
if (state) {
state->base.plane = plane;
state->base.rotation = DRM_ROTATE_0;
plane->state = &state->base;
}
}
static struct
drm_plane_state *malidp_duplicate_plane_state(struct drm_plane *plane)
{
struct malidp_plane_state *state, *m_state;
if (!plane->state)
return NULL;
state = kmalloc(sizeof(*state), GFP_KERNEL);
if (!state)
return NULL;
m_state = to_malidp_plane_state(plane->state);
__drm_atomic_helper_plane_duplicate_state(plane, &state->base);
state->rotmem_size = m_state->rotmem_size;
state->format = m_state->format;
state->n_planes = m_state->n_planes;
return &state->base;
}
static void malidp_destroy_plane_state(struct drm_plane *plane,
struct drm_plane_state *state)
{
struct malidp_plane_state *m_state = to_malidp_plane_state(state);
__drm_atomic_helper_plane_destroy_state(state);
kfree(m_state);
}
static void malidp_plane_atomic_print_state(struct drm_printer *p,
const struct drm_plane_state *state)
{
struct malidp_plane_state *ms = to_malidp_plane_state(state);
drm_printf(p, "\trotmem_size=%u\n", ms->rotmem_size);
drm_printf(p, "\tformat_id=%u\n", ms->format);
drm_printf(p, "\tn_planes=%u\n", ms->n_planes);
}
static int malidp_se_check_scaling(struct malidp_plane *mp,
struct drm_plane_state *state)
{
struct drm_crtc_state *crtc_state =
drm_atomic_get_existing_crtc_state(state->state, state->crtc);
struct malidp_crtc_state *mc;
struct drm_rect clip = { 0 };
u32 src_w, src_h;
int ret;
if (!crtc_state)
return -EINVAL;
clip.x2 = crtc_state->adjusted_mode.hdisplay;
clip.y2 = crtc_state->adjusted_mode.vdisplay;
ret = drm_plane_helper_check_state(state, &clip, 0, INT_MAX, true, true);
if (ret)
return ret;
src_w = state->src_w >> 16;
src_h = state->src_h >> 16;
if ((state->crtc_w == src_w) && (state->crtc_h == src_h)) {
mc->scaled_planes_mask &= ~(mp->layer->id);
return 0;
}
if (mp->layer->id & (DE_SMART | DE_GRAPHICS2))
return -EINVAL;
mc = to_malidp_crtc_state(crtc_state);
mc->scaled_planes_mask |= mp->layer->id;
return 0;
}
static int malidp_de_plane_check(struct drm_plane *plane,
struct drm_plane_state *state)
{
struct malidp_plane *mp = to_malidp_plane(plane);
struct malidp_plane_state *ms = to_malidp_plane_state(state);
struct drm_framebuffer *fb;
int i, ret;
if (!state->crtc || !state->fb)
return 0;
fb = state->fb;
ms->format = malidp_hw_get_format_id(&mp->hwdev->map, mp->layer->id,
fb->format->format);
if (ms->format == MALIDP_INVALID_FORMAT_ID)
return -EINVAL;
ms->n_planes = fb->format->num_planes;
for (i = 0; i < ms->n_planes; i++) {
if (!malidp_hw_pitch_valid(mp->hwdev, fb->pitches[i])) {
DRM_DEBUG_KMS("Invalid pitch %u for plane %d\n",
fb->pitches[i], i);
return -EINVAL;
}
}
if ((state->crtc_w > mp->hwdev->max_line_size) ||
(state->crtc_h > mp->hwdev->max_line_size) ||
(state->crtc_w < mp->hwdev->min_line_size) ||
(state->crtc_h < mp->hwdev->min_line_size))
return -EINVAL;
if (ms->n_planes == 3 &&
!(mp->hwdev->features & MALIDP_DEVICE_LV_HAS_3_STRIDES) &&
(state->fb->pitches[1] != state->fb->pitches[2]))
return -EINVAL;
ret = malidp_se_check_scaling(mp, state);
if (ret)
return ret;
if (state->rotation != DRM_ROTATE_0 &&
(fb->format->format == DRM_FORMAT_RGB888 ||
fb->format->format == DRM_FORMAT_BGR888))
return -EINVAL;
ms->rotmem_size = 0;
if (state->rotation & MALIDP_ROTATED_MASK) {
int val;
val = mp->hwdev->rotmem_required(mp->hwdev, state->crtc_h,
state->crtc_w,
fb->format->format);
if (val < 0)
return val;
ms->rotmem_size = val;
}
return 0;
}
static void malidp_de_set_plane_pitches(struct malidp_plane *mp,
int num_planes, unsigned int pitches[3])
{
int i;
int num_strides = num_planes;
if (!mp->layer->stride_offset)
return;
if (num_planes == 3)
num_strides = (mp->hwdev->features &
MALIDP_DEVICE_LV_HAS_3_STRIDES) ? 3 : 2;
for (i = 0; i < num_strides; ++i)
malidp_hw_write(mp->hwdev, pitches[i],
mp->layer->base +
mp->layer->stride_offset + i * 4);
}
static void malidp_de_plane_update(struct drm_plane *plane,
struct drm_plane_state *old_state)
{
struct drm_gem_cma_object *obj;
struct malidp_plane *mp;
const struct malidp_hw_regmap *map;
struct malidp_plane_state *ms = to_malidp_plane_state(plane->state);
u16 ptr;
u32 src_w, src_h, dest_w, dest_h, val;
int i;
mp = to_malidp_plane(plane);
map = &mp->hwdev->map;
src_w = plane->state->src_w >> 16;
src_h = plane->state->src_h >> 16;
dest_w = plane->state->crtc_w;
dest_h = plane->state->crtc_h;
malidp_hw_write(mp->hwdev, ms->format, mp->layer->base);
for (i = 0; i < ms->n_planes; i++) {
ptr = mp->layer->ptr + (i << 4);
obj = drm_fb_cma_get_gem_obj(plane->state->fb, i);
obj->paddr += plane->state->fb->offsets[i];
malidp_hw_write(mp->hwdev, lower_32_bits(obj->paddr), ptr);
malidp_hw_write(mp->hwdev, upper_32_bits(obj->paddr), ptr + 4);
}
malidp_de_set_plane_pitches(mp, ms->n_planes,
plane->state->fb->pitches);
malidp_hw_write(mp->hwdev, LAYER_H_VAL(src_w) | LAYER_V_VAL(src_h),
mp->layer->base + MALIDP_LAYER_SIZE);
malidp_hw_write(mp->hwdev, LAYER_H_VAL(dest_w) | LAYER_V_VAL(dest_h),
mp->layer->base + MALIDP_LAYER_COMP_SIZE);
malidp_hw_write(mp->hwdev, LAYER_H_VAL(plane->state->crtc_x) |
LAYER_V_VAL(plane->state->crtc_y),
mp->layer->base + MALIDP_LAYER_OFFSET);
if (mp->layer->id == DE_SMART)
malidp_hw_write(mp->hwdev,
LAYER_H_VAL(src_w) | LAYER_V_VAL(src_h),
mp->layer->base + MALIDP550_LS_R1_IN_SIZE);
val = malidp_hw_read(mp->hwdev, mp->layer->base + MALIDP_LAYER_CONTROL);
val &= ~LAYER_ROT_MASK;
if (plane->state->rotation & DRM_ROTATE_MASK)
val |= ilog2(plane->state->rotation & DRM_ROTATE_MASK) <<
LAYER_ROT_OFFSET;
if (plane->state->rotation & DRM_REFLECT_X)
val |= LAYER_H_FLIP;
if (plane->state->rotation & DRM_REFLECT_Y)
val |= LAYER_V_FLIP;
val &= ~LAYER_COMP_MASK;
val |= LAYER_COMP_PIXEL;
val &= ~LAYER_FLOWCFG(LAYER_FLOWCFG_MASK);
if (plane->state->crtc) {
struct malidp_crtc_state *m =
to_malidp_crtc_state(plane->state->crtc->state);
if (m->scaler_config.scale_enable &&
m->scaler_config.plane_src_id == mp->layer->id)
val |= LAYER_FLOWCFG(LAYER_FLOWCFG_SCALE_SE);
}
val |= LAYER_ENABLE;
malidp_hw_write(mp->hwdev, val,
mp->layer->base + MALIDP_LAYER_CONTROL);
}
static void malidp_de_plane_disable(struct drm_plane *plane,
struct drm_plane_state *state)
{
struct malidp_plane *mp = to_malidp_plane(plane);
malidp_hw_clearbits(mp->hwdev,
LAYER_ENABLE | LAYER_FLOWCFG(LAYER_FLOWCFG_MASK),
mp->layer->base + MALIDP_LAYER_CONTROL);
}
int malidp_de_planes_init(struct drm_device *drm)
{
struct malidp_drm *malidp = drm->dev_private;
const struct malidp_hw_regmap *map = &malidp->dev->map;
struct malidp_plane *plane = NULL;
enum drm_plane_type plane_type;
unsigned long crtcs = 1 << drm->mode_config.num_crtc;
unsigned long flags = DRM_ROTATE_0 | DRM_ROTATE_90 | DRM_ROTATE_180 |
DRM_ROTATE_270 | DRM_REFLECT_X | DRM_REFLECT_Y;
u32 *formats;
int ret, i, j, n;
formats = kcalloc(map->n_pixel_formats, sizeof(*formats), GFP_KERNEL);
if (!formats) {
ret = -ENOMEM;
goto cleanup;
}
for (i = 0; i < map->n_layers; i++) {
u8 id = map->layers[i].id;
plane = kzalloc(sizeof(*plane), GFP_KERNEL);
if (!plane) {
ret = -ENOMEM;
goto cleanup;
}
for (n = 0, j = 0; j < map->n_pixel_formats; j++) {
if ((map->pixel_formats[j].layer & id) == id)
formats[n++] = map->pixel_formats[j].format;
}
plane_type = (i == 0) ? DRM_PLANE_TYPE_PRIMARY :
DRM_PLANE_TYPE_OVERLAY;
ret = drm_universal_plane_init(drm, &plane->base, crtcs,
&malidp_de_plane_funcs, formats,
n, plane_type, NULL);
if (ret < 0)
goto cleanup;
drm_plane_helper_add(&plane->base,
&malidp_de_plane_helper_funcs);
plane->hwdev = malidp->dev;
plane->layer = &map->layers[i];
if (id == DE_SMART) {
malidp_hw_write(malidp->dev, 1,
plane->layer->base + MALIDP550_LS_ENABLE);
continue;
}
drm_plane_create_rotation_property(&plane->base, DRM_ROTATE_0, flags);
malidp_hw_write(malidp->dev, MALIDP_ALPHA_LUT,
plane->layer->base + MALIDP_LAYER_COMPOSE);
}
kfree(formats);
return 0;
cleanup:
malidp_de_planes_destroy(drm);
kfree(formats);
return ret;
}
void malidp_de_planes_destroy(struct drm_device *drm)
{
struct drm_plane *p, *pt;
list_for_each_entry_safe(p, pt, &drm->mode_config.plane_list, head) {
drm_plane_cleanup(p);
kfree(p);
}
}
