struct drm_property *drm_mode_create_rotation_property(struct drm_device *dev,
unsigned int supported_rotations)
{
static const struct drm_prop_enum_list props[] = {
{ __builtin_ffs(DRM_ROTATE_0) - 1, "rotate-0" },
{ __builtin_ffs(DRM_ROTATE_90) - 1, "rotate-90" },
{ __builtin_ffs(DRM_ROTATE_180) - 1, "rotate-180" },
{ __builtin_ffs(DRM_ROTATE_270) - 1, "rotate-270" },
{ __builtin_ffs(DRM_REFLECT_X) - 1, "reflect-x" },
{ __builtin_ffs(DRM_REFLECT_Y) - 1, "reflect-y" },
};
return drm_property_create_bitmask(dev, 0, "rotation",
props, ARRAY_SIZE(props),
supported_rotations);
}
unsigned int drm_rotation_simplify(unsigned int rotation,
unsigned int supported_rotations)
{
if (rotation & ~supported_rotations) {
rotation ^= DRM_REFLECT_X | DRM_REFLECT_Y;
rotation = (rotation & DRM_REFLECT_MASK) |
BIT((ffs(rotation & DRM_ROTATE_MASK) + 1) % 4);
}
return rotation;
}
int drm_plane_create_zpos_property(struct drm_plane *plane,
unsigned int zpos,
unsigned int min, unsigned int max)
{
struct drm_property *prop;
prop = drm_property_create_range(plane->dev, 0, "zpos", min, max);
if (!prop)
return -ENOMEM;
drm_object_attach_property(&plane->base, prop, zpos);
plane->zpos_property = prop;
if (plane->state) {
plane->state->zpos = zpos;
plane->state->normalized_zpos = zpos;
}
return 0;
}
int drm_plane_create_zpos_immutable_property(struct drm_plane *plane,
unsigned int zpos)
{
struct drm_property *prop;
prop = drm_property_create_range(plane->dev, DRM_MODE_PROP_IMMUTABLE,
"zpos", zpos, zpos);
if (!prop)
return -ENOMEM;
drm_object_attach_property(&plane->base, prop, zpos);
plane->zpos_property = prop;
if (plane->state) {
plane->state->zpos = zpos;
plane->state->normalized_zpos = zpos;
}
return 0;
}
static int drm_atomic_state_zpos_cmp(const void *a, const void *b)
{
const struct drm_plane_state *sa = *(struct drm_plane_state **)a;
const struct drm_plane_state *sb = *(struct drm_plane_state **)b;
if (sa->zpos != sb->zpos)
return sa->zpos - sb->zpos;
else
return sa->plane->base.id - sb->plane->base.id;
}
static int drm_atomic_helper_crtc_normalize_zpos(struct drm_crtc *crtc,
struct drm_crtc_state *crtc_state)
{
struct drm_atomic_state *state = crtc_state->state;
struct drm_device *dev = crtc->dev;
int total_planes = dev->mode_config.num_total_plane;
struct drm_plane_state **states;
struct drm_plane *plane;
int i, n = 0;
int ret = 0;
DRM_DEBUG_ATOMIC("[CRTC:%d:%s] calculating normalized zpos values\n",
crtc->base.id, crtc->name);
states = kmalloc_array(total_planes, sizeof(*states), GFP_TEMPORARY);
if (!states)
return -ENOMEM;
drm_for_each_plane_mask(plane, dev, crtc_state->plane_mask) {
struct drm_plane_state *plane_state =
drm_atomic_get_plane_state(state, plane);
if (IS_ERR(plane_state)) {
ret = PTR_ERR(plane_state);
goto done;
}
states[n++] = plane_state;
DRM_DEBUG_ATOMIC("[PLANE:%d:%s] processing zpos value %d\n",
plane->base.id, plane->name,
plane_state->zpos);
}
sort(states, n, sizeof(*states), drm_atomic_state_zpos_cmp, NULL);
for (i = 0; i < n; i++) {
plane = states[i]->plane;
states[i]->normalized_zpos = i;
DRM_DEBUG_ATOMIC("[PLANE:%d:%s] normalized zpos value %d\n",
plane->base.id, plane->name, i);
}
crtc_state->zpos_changed = true;
done:
kfree(states);
return ret;
}
int drm_atomic_normalize_zpos(struct drm_device *dev,
struct drm_atomic_state *state)
{
struct drm_crtc *crtc;
struct drm_crtc_state *crtc_state;
struct drm_plane *plane;
struct drm_plane_state *plane_state;
int i, ret = 0;
for_each_plane_in_state(state, plane, plane_state, i) {
crtc = plane_state->crtc;
if (!crtc)
continue;
if (plane->state->zpos != plane_state->zpos) {
crtc_state =
drm_atomic_get_existing_crtc_state(state, crtc);
crtc_state->zpos_changed = true;
}
}
for_each_crtc_in_state(state, crtc, crtc_state, i) {
if (crtc_state->plane_mask != crtc->state->plane_mask ||
crtc_state->zpos_changed) {
ret = drm_atomic_helper_crtc_normalize_zpos(crtc,
crtc_state);
if (ret)
return ret;
}
}
return 0;
}
