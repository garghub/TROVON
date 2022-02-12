static void malidp_de_plane_destroy(struct drm_plane *plane)
{
struct malidp_plane *mp = to_malidp_plane(plane);
if (mp->base.fb)
drm_framebuffer_unreference(mp->base.fb);
drm_plane_helper_disable(plane);
drm_plane_cleanup(plane);
devm_kfree(plane->dev->dev, mp);
}
struct drm_plane_state *malidp_duplicate_plane_state(struct drm_plane *plane)
{
struct malidp_plane_state *state, *m_state;
if (!plane->state)
return NULL;
state = kmalloc(sizeof(*state), GFP_KERNEL);
if (state) {
m_state = to_malidp_plane_state(plane->state);
__drm_atomic_helper_plane_duplicate_state(plane, &state->base);
state->rotmem_size = m_state->rotmem_size;
}
return &state->base;
}
void malidp_destroy_plane_state(struct drm_plane *plane,
struct drm_plane_state *state)
{
struct malidp_plane_state *m_state = to_malidp_plane_state(state);
__drm_atomic_helper_plane_destroy_state(state);
kfree(m_state);
}
static int malidp_de_plane_check(struct drm_plane *plane,
struct drm_plane_state *state)
{
struct malidp_plane *mp = to_malidp_plane(plane);
struct malidp_plane_state *ms = to_malidp_plane_state(state);
u8 format_id;
u32 src_w, src_h;
if (!state->crtc || !state->fb)
return 0;
format_id = malidp_hw_get_format_id(&mp->hwdev->map, mp->layer->id,
state->fb->pixel_format);
if (format_id == MALIDP_INVALID_FORMAT_ID)
return -EINVAL;
src_w = state->src_w >> 16;
src_h = state->src_h >> 16;
if ((state->crtc_w > mp->hwdev->max_line_size) ||
(state->crtc_h > mp->hwdev->max_line_size) ||
(state->crtc_w < mp->hwdev->min_line_size) ||
(state->crtc_h < mp->hwdev->min_line_size) ||
(state->crtc_w != src_w) || (state->crtc_h != src_h))
return -EINVAL;
if (state->rotation != BIT(DRM_ROTATE_0) &&
(state->fb->pixel_format == DRM_FORMAT_RGB888 ||
state->fb->pixel_format == DRM_FORMAT_BGR888))
return -EINVAL;
ms->rotmem_size = 0;
if (state->rotation & MALIDP_ROTATED_MASK) {
int val;
val = mp->hwdev->rotmem_required(mp->hwdev, state->crtc_h,
state->crtc_w,
state->fb->pixel_format);
if (val < 0)
return val;
ms->rotmem_size = val;
}
return 0;
}
static void malidp_de_plane_update(struct drm_plane *plane,
struct drm_plane_state *old_state)
{
struct drm_gem_cma_object *obj;
struct malidp_plane *mp;
const struct malidp_hw_regmap *map;
u8 format_id;
u16 ptr;
u32 format, src_w, src_h, dest_w, dest_h, val = 0;
int num_planes, i;
mp = to_malidp_plane(plane);
map = &mp->hwdev->map;
format = plane->state->fb->pixel_format;
format_id = malidp_hw_get_format_id(map, mp->layer->id, format);
num_planes = drm_format_num_planes(format);
src_w = plane->state->src_w >> 16;
src_h = plane->state->src_h >> 16;
if (plane->state->rotation & MALIDP_ROTATED_MASK) {
dest_w = plane->state->crtc_h;
dest_h = plane->state->crtc_w;
} else {
dest_w = plane->state->crtc_w;
dest_h = plane->state->crtc_h;
}
malidp_hw_write(mp->hwdev, format_id, mp->layer->base);
for (i = 0; i < num_planes; i++) {
ptr = mp->layer->ptr + (i << 4);
obj = drm_fb_cma_get_gem_obj(plane->state->fb, i);
malidp_hw_write(mp->hwdev, lower_32_bits(obj->paddr), ptr);
malidp_hw_write(mp->hwdev, upper_32_bits(obj->paddr), ptr + 4);
malidp_hw_write(mp->hwdev, plane->state->fb->pitches[i],
mp->layer->base + MALIDP_LAYER_STRIDE);
}
malidp_hw_write(mp->hwdev, LAYER_H_VAL(src_w) | LAYER_V_VAL(src_h),
mp->layer->base + MALIDP_LAYER_SIZE);
malidp_hw_write(mp->hwdev, LAYER_H_VAL(dest_w) | LAYER_V_VAL(dest_h),
mp->layer->base + MALIDP_LAYER_COMP_SIZE);
malidp_hw_write(mp->hwdev, LAYER_H_VAL(plane->state->crtc_x) |
LAYER_V_VAL(plane->state->crtc_y),
mp->layer->base + MALIDP_LAYER_OFFSET);
malidp_hw_clearbits(mp->hwdev, LAYER_ROT_MASK,
mp->layer->base + MALIDP_LAYER_CONTROL);
if (plane->state->rotation & DRM_ROTATE_MASK)
val = ilog2(plane->state->rotation & DRM_ROTATE_MASK) << LAYER_ROT_OFFSET;
if (plane->state->rotation & BIT(DRM_REFLECT_X))
val |= LAYER_V_FLIP;
if (plane->state->rotation & BIT(DRM_REFLECT_Y))
val |= LAYER_H_FLIP;
val |= LAYER_ENABLE;
malidp_hw_setbits(mp->hwdev, val,
mp->layer->base + MALIDP_LAYER_CONTROL);
}
static void malidp_de_plane_disable(struct drm_plane *plane,
struct drm_plane_state *state)
{
struct malidp_plane *mp = to_malidp_plane(plane);
malidp_hw_clearbits(mp->hwdev, LAYER_ENABLE,
mp->layer->base + MALIDP_LAYER_CONTROL);
}
int malidp_de_planes_init(struct drm_device *drm)
{
struct malidp_drm *malidp = drm->dev_private;
const struct malidp_hw_regmap *map = &malidp->dev->map;
struct malidp_plane *plane = NULL;
enum drm_plane_type plane_type;
unsigned long crtcs = 1 << drm->mode_config.num_crtc;
u32 *formats;
int ret, i, j, n;
formats = kcalloc(map->n_input_formats, sizeof(*formats), GFP_KERNEL);
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
for (n = 0, j = 0; j < map->n_input_formats; j++) {
if ((map->input_formats[j].layer & id) == id)
formats[n++] = map->input_formats[j].format;
}
plane_type = (i == 0) ? DRM_PLANE_TYPE_PRIMARY :
DRM_PLANE_TYPE_OVERLAY;
ret = drm_universal_plane_init(drm, &plane->base, crtcs,
&malidp_de_plane_funcs, formats,
n, plane_type, NULL);
if (ret < 0)
goto cleanup;
if (!drm->mode_config.rotation_property) {
unsigned long flags = BIT(DRM_ROTATE_0) |
BIT(DRM_ROTATE_90) |
BIT(DRM_ROTATE_180) |
BIT(DRM_ROTATE_270) |
BIT(DRM_REFLECT_X) |
BIT(DRM_REFLECT_Y);
drm->mode_config.rotation_property =
drm_mode_create_rotation_property(drm, flags);
}
if (drm->mode_config.rotation_property && (id != DE_SMART))
drm_object_attach_property(&plane->base.base,
drm->mode_config.rotation_property,
BIT(DRM_ROTATE_0));
drm_plane_helper_add(&plane->base,
&malidp_de_plane_helper_funcs);
plane->hwdev = malidp->dev;
plane->layer = &map->layers[i];
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
