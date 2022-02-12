void __drm_crtc_commit_free(struct kref *kref)
{
struct drm_crtc_commit *commit =
container_of(kref, struct drm_crtc_commit, ref);
kfree(commit);
}
void drm_atomic_state_default_release(struct drm_atomic_state *state)
{
kfree(state->connectors);
kfree(state->crtcs);
kfree(state->planes);
}
int
drm_atomic_state_init(struct drm_device *dev, struct drm_atomic_state *state)
{
kref_init(&state->ref);
state->allow_modeset = true;
state->crtcs = kcalloc(dev->mode_config.num_crtc,
sizeof(*state->crtcs), GFP_KERNEL);
if (!state->crtcs)
goto fail;
state->planes = kcalloc(dev->mode_config.num_total_plane,
sizeof(*state->planes), GFP_KERNEL);
if (!state->planes)
goto fail;
state->dev = dev;
DRM_DEBUG_ATOMIC("Allocated atomic state %p\n", state);
return 0;
fail:
drm_atomic_state_default_release(state);
return -ENOMEM;
}
struct drm_atomic_state *
drm_atomic_state_alloc(struct drm_device *dev)
{
struct drm_mode_config *config = &dev->mode_config;
struct drm_atomic_state *state;
if (!config->funcs->atomic_state_alloc) {
state = kzalloc(sizeof(*state), GFP_KERNEL);
if (!state)
return NULL;
if (drm_atomic_state_init(dev, state) < 0) {
kfree(state);
return NULL;
}
return state;
}
return config->funcs->atomic_state_alloc(dev);
}
void drm_atomic_state_default_clear(struct drm_atomic_state *state)
{
struct drm_device *dev = state->dev;
struct drm_mode_config *config = &dev->mode_config;
int i;
DRM_DEBUG_ATOMIC("Clearing atomic state %p\n", state);
for (i = 0; i < state->num_connector; i++) {
struct drm_connector *connector = state->connectors[i].ptr;
if (!connector)
continue;
connector->funcs->atomic_destroy_state(connector,
state->connectors[i].state);
state->connectors[i].ptr = NULL;
state->connectors[i].state = NULL;
drm_connector_put(connector);
}
for (i = 0; i < config->num_crtc; i++) {
struct drm_crtc *crtc = state->crtcs[i].ptr;
if (!crtc)
continue;
crtc->funcs->atomic_destroy_state(crtc,
state->crtcs[i].state);
if (state->crtcs[i].commit) {
kfree(state->crtcs[i].commit->event);
state->crtcs[i].commit->event = NULL;
drm_crtc_commit_put(state->crtcs[i].commit);
}
state->crtcs[i].commit = NULL;
state->crtcs[i].ptr = NULL;
state->crtcs[i].state = NULL;
}
for (i = 0; i < config->num_total_plane; i++) {
struct drm_plane *plane = state->planes[i].ptr;
if (!plane)
continue;
plane->funcs->atomic_destroy_state(plane,
state->planes[i].state);
state->planes[i].ptr = NULL;
state->planes[i].state = NULL;
}
}
void drm_atomic_state_clear(struct drm_atomic_state *state)
{
struct drm_device *dev = state->dev;
struct drm_mode_config *config = &dev->mode_config;
if (config->funcs->atomic_state_clear)
config->funcs->atomic_state_clear(state);
else
drm_atomic_state_default_clear(state);
}
void __drm_atomic_state_free(struct kref *ref)
{
struct drm_atomic_state *state = container_of(ref, typeof(*state), ref);
struct drm_mode_config *config = &state->dev->mode_config;
drm_atomic_state_clear(state);
DRM_DEBUG_ATOMIC("Freeing atomic state %p\n", state);
if (config->funcs->atomic_state_free) {
config->funcs->atomic_state_free(state);
} else {
drm_atomic_state_default_release(state);
kfree(state);
}
}
struct drm_crtc_state *
drm_atomic_get_crtc_state(struct drm_atomic_state *state,
struct drm_crtc *crtc)
{
int ret, index = drm_crtc_index(crtc);
struct drm_crtc_state *crtc_state;
WARN_ON(!state->acquire_ctx);
crtc_state = drm_atomic_get_existing_crtc_state(state, crtc);
if (crtc_state)
return crtc_state;
ret = drm_modeset_lock(&crtc->mutex, state->acquire_ctx);
if (ret)
return ERR_PTR(ret);
crtc_state = crtc->funcs->atomic_duplicate_state(crtc);
if (!crtc_state)
return ERR_PTR(-ENOMEM);
state->crtcs[index].state = crtc_state;
state->crtcs[index].old_state = crtc->state;
state->crtcs[index].new_state = crtc_state;
state->crtcs[index].ptr = crtc;
crtc_state->state = state;
DRM_DEBUG_ATOMIC("Added [CRTC:%d:%s] %p state to %p\n",
crtc->base.id, crtc->name, crtc_state, state);
return crtc_state;
}
static void set_out_fence_for_crtc(struct drm_atomic_state *state,
struct drm_crtc *crtc, s32 __user *fence_ptr)
{
state->crtcs[drm_crtc_index(crtc)].out_fence_ptr = fence_ptr;
}
static s32 __user *get_out_fence_for_crtc(struct drm_atomic_state *state,
struct drm_crtc *crtc)
{
s32 __user *fence_ptr;
fence_ptr = state->crtcs[drm_crtc_index(crtc)].out_fence_ptr;
state->crtcs[drm_crtc_index(crtc)].out_fence_ptr = NULL;
return fence_ptr;
}
int drm_atomic_set_mode_for_crtc(struct drm_crtc_state *state,
struct drm_display_mode *mode)
{
struct drm_mode_modeinfo umode;
if (mode && memcmp(&state->mode, mode, sizeof(*mode)) == 0)
return 0;
drm_property_blob_put(state->mode_blob);
state->mode_blob = NULL;
if (mode) {
drm_mode_convert_to_umode(&umode, mode);
state->mode_blob =
drm_property_create_blob(state->crtc->dev,
sizeof(umode),
&umode);
if (IS_ERR(state->mode_blob))
return PTR_ERR(state->mode_blob);
drm_mode_copy(&state->mode, mode);
state->enable = true;
DRM_DEBUG_ATOMIC("Set [MODE:%s] for CRTC state %p\n",
mode->name, state);
} else {
memset(&state->mode, 0, sizeof(state->mode));
state->enable = false;
DRM_DEBUG_ATOMIC("Set [NOMODE] for CRTC state %p\n",
state);
}
return 0;
}
int drm_atomic_set_mode_prop_for_crtc(struct drm_crtc_state *state,
struct drm_property_blob *blob)
{
if (blob == state->mode_blob)
return 0;
drm_property_blob_put(state->mode_blob);
state->mode_blob = NULL;
memset(&state->mode, 0, sizeof(state->mode));
if (blob) {
if (blob->length != sizeof(struct drm_mode_modeinfo) ||
drm_mode_convert_umode(&state->mode,
(const struct drm_mode_modeinfo *)
blob->data))
return -EINVAL;
state->mode_blob = drm_property_blob_get(blob);
state->enable = true;
DRM_DEBUG_ATOMIC("Set [MODE:%s] for CRTC state %p\n",
state->mode.name, state);
} else {
state->enable = false;
DRM_DEBUG_ATOMIC("Set [NOMODE] for CRTC state %p\n",
state);
}
return 0;
}
static void
drm_atomic_replace_property_blob(struct drm_property_blob **blob,
struct drm_property_blob *new_blob,
bool *replaced)
{
struct drm_property_blob *old_blob = *blob;
if (old_blob == new_blob)
return;
drm_property_blob_put(old_blob);
if (new_blob)
drm_property_blob_get(new_blob);
*blob = new_blob;
*replaced = true;
return;
}
static int
drm_atomic_replace_property_blob_from_id(struct drm_crtc *crtc,
struct drm_property_blob **blob,
uint64_t blob_id,
ssize_t expected_size,
bool *replaced)
{
struct drm_property_blob *new_blob = NULL;
if (blob_id != 0) {
new_blob = drm_property_lookup_blob(crtc->dev, blob_id);
if (new_blob == NULL)
return -EINVAL;
if (expected_size > 0 && expected_size != new_blob->length) {
drm_property_blob_put(new_blob);
return -EINVAL;
}
}
drm_atomic_replace_property_blob(blob, new_blob, replaced);
drm_property_blob_put(new_blob);
return 0;
}
int drm_atomic_crtc_set_property(struct drm_crtc *crtc,
struct drm_crtc_state *state, struct drm_property *property,
uint64_t val)
{
struct drm_device *dev = crtc->dev;
struct drm_mode_config *config = &dev->mode_config;
bool replaced = false;
int ret;
if (property == config->prop_active)
state->active = val;
else if (property == config->prop_mode_id) {
struct drm_property_blob *mode =
drm_property_lookup_blob(dev, val);
ret = drm_atomic_set_mode_prop_for_crtc(state, mode);
drm_property_blob_put(mode);
return ret;
} else if (property == config->degamma_lut_property) {
ret = drm_atomic_replace_property_blob_from_id(crtc,
&state->degamma_lut,
val,
-1,
&replaced);
state->color_mgmt_changed |= replaced;
return ret;
} else if (property == config->ctm_property) {
ret = drm_atomic_replace_property_blob_from_id(crtc,
&state->ctm,
val,
sizeof(struct drm_color_ctm),
&replaced);
state->color_mgmt_changed |= replaced;
return ret;
} else if (property == config->gamma_lut_property) {
ret = drm_atomic_replace_property_blob_from_id(crtc,
&state->gamma_lut,
val,
-1,
&replaced);
state->color_mgmt_changed |= replaced;
return ret;
} else if (property == config->prop_out_fence_ptr) {
s32 __user *fence_ptr = u64_to_user_ptr(val);
if (!fence_ptr)
return 0;
if (put_user(-1, fence_ptr))
return -EFAULT;
set_out_fence_for_crtc(state->state, crtc, fence_ptr);
} else if (crtc->funcs->atomic_set_property)
return crtc->funcs->atomic_set_property(crtc, state, property, val);
else
return -EINVAL;
return 0;
}
static int
drm_atomic_crtc_get_property(struct drm_crtc *crtc,
const struct drm_crtc_state *state,
struct drm_property *property, uint64_t *val)
{
struct drm_device *dev = crtc->dev;
struct drm_mode_config *config = &dev->mode_config;
if (property == config->prop_active)
*val = state->active;
else if (property == config->prop_mode_id)
*val = (state->mode_blob) ? state->mode_blob->base.id : 0;
else if (property == config->degamma_lut_property)
*val = (state->degamma_lut) ? state->degamma_lut->base.id : 0;
else if (property == config->ctm_property)
*val = (state->ctm) ? state->ctm->base.id : 0;
else if (property == config->gamma_lut_property)
*val = (state->gamma_lut) ? state->gamma_lut->base.id : 0;
else if (property == config->prop_out_fence_ptr)
*val = 0;
else if (crtc->funcs->atomic_get_property)
return crtc->funcs->atomic_get_property(crtc, state, property, val);
else
return -EINVAL;
return 0;
}
static int drm_atomic_crtc_check(struct drm_crtc *crtc,
struct drm_crtc_state *state)
{
if (state->active && !state->enable) {
DRM_DEBUG_ATOMIC("[CRTC:%d:%s] active without enabled\n",
crtc->base.id, crtc->name);
return -EINVAL;
}
if (drm_core_check_feature(crtc->dev, DRIVER_ATOMIC) &&
WARN_ON(state->enable && !state->mode_blob)) {
DRM_DEBUG_ATOMIC("[CRTC:%d:%s] enabled without mode blob\n",
crtc->base.id, crtc->name);
return -EINVAL;
}
if (drm_core_check_feature(crtc->dev, DRIVER_ATOMIC) &&
WARN_ON(!state->enable && state->mode_blob)) {
DRM_DEBUG_ATOMIC("[CRTC:%d:%s] disabled with mode blob\n",
crtc->base.id, crtc->name);
return -EINVAL;
}
if (state->event && !state->active && !crtc->state->active) {
DRM_DEBUG_ATOMIC("[CRTC:%d:%s] requesting event but off\n",
crtc->base.id, crtc->name);
return -EINVAL;
}
return 0;
}
static void drm_atomic_crtc_print_state(struct drm_printer *p,
const struct drm_crtc_state *state)
{
struct drm_crtc *crtc = state->crtc;
drm_printf(p, "crtc[%u]: %s\n", crtc->base.id, crtc->name);
drm_printf(p, "\tenable=%d\n", state->enable);
drm_printf(p, "\tactive=%d\n", state->active);
drm_printf(p, "\tplanes_changed=%d\n", state->planes_changed);
drm_printf(p, "\tmode_changed=%d\n", state->mode_changed);
drm_printf(p, "\tactive_changed=%d\n", state->active_changed);
drm_printf(p, "\tconnectors_changed=%d\n", state->connectors_changed);
drm_printf(p, "\tcolor_mgmt_changed=%d\n", state->color_mgmt_changed);
drm_printf(p, "\tplane_mask=%x\n", state->plane_mask);
drm_printf(p, "\tconnector_mask=%x\n", state->connector_mask);
drm_printf(p, "\tencoder_mask=%x\n", state->encoder_mask);
drm_printf(p, "\tmode: " DRM_MODE_FMT "\n", DRM_MODE_ARG(&state->mode));
if (crtc->funcs->atomic_print_state)
crtc->funcs->atomic_print_state(p, state);
}
struct drm_plane_state *
drm_atomic_get_plane_state(struct drm_atomic_state *state,
struct drm_plane *plane)
{
int ret, index = drm_plane_index(plane);
struct drm_plane_state *plane_state;
WARN_ON(!state->acquire_ctx);
plane_state = drm_atomic_get_existing_plane_state(state, plane);
if (plane_state)
return plane_state;
ret = drm_modeset_lock(&plane->mutex, state->acquire_ctx);
if (ret)
return ERR_PTR(ret);
plane_state = plane->funcs->atomic_duplicate_state(plane);
if (!plane_state)
return ERR_PTR(-ENOMEM);
state->planes[index].state = plane_state;
state->planes[index].ptr = plane;
state->planes[index].old_state = plane->state;
state->planes[index].new_state = plane_state;
plane_state->state = state;
DRM_DEBUG_ATOMIC("Added [PLANE:%d:%s] %p state to %p\n",
plane->base.id, plane->name, plane_state, state);
if (plane_state->crtc) {
struct drm_crtc_state *crtc_state;
crtc_state = drm_atomic_get_crtc_state(state,
plane_state->crtc);
if (IS_ERR(crtc_state))
return ERR_CAST(crtc_state);
}
return plane_state;
}
int drm_atomic_plane_set_property(struct drm_plane *plane,
struct drm_plane_state *state, struct drm_property *property,
uint64_t val)
{
struct drm_device *dev = plane->dev;
struct drm_mode_config *config = &dev->mode_config;
if (property == config->prop_fb_id) {
struct drm_framebuffer *fb = drm_framebuffer_lookup(dev, val);
drm_atomic_set_fb_for_plane(state, fb);
if (fb)
drm_framebuffer_put(fb);
} else if (property == config->prop_in_fence_fd) {
if (state->fence)
return -EINVAL;
if (U642I64(val) == -1)
return 0;
state->fence = sync_file_get_fence(val);
if (!state->fence)
return -EINVAL;
} else if (property == config->prop_crtc_id) {
struct drm_crtc *crtc = drm_crtc_find(dev, val);
return drm_atomic_set_crtc_for_plane(state, crtc);
} else if (property == config->prop_crtc_x) {
state->crtc_x = U642I64(val);
} else if (property == config->prop_crtc_y) {
state->crtc_y = U642I64(val);
} else if (property == config->prop_crtc_w) {
state->crtc_w = val;
} else if (property == config->prop_crtc_h) {
state->crtc_h = val;
} else if (property == config->prop_src_x) {
state->src_x = val;
} else if (property == config->prop_src_y) {
state->src_y = val;
} else if (property == config->prop_src_w) {
state->src_w = val;
} else if (property == config->prop_src_h) {
state->src_h = val;
} else if (property == plane->rotation_property) {
if (!is_power_of_2(val & DRM_ROTATE_MASK))
return -EINVAL;
state->rotation = val;
} else if (property == plane->zpos_property) {
state->zpos = val;
} else if (plane->funcs->atomic_set_property) {
return plane->funcs->atomic_set_property(plane, state,
property, val);
} else {
return -EINVAL;
}
return 0;
}
static int
drm_atomic_plane_get_property(struct drm_plane *plane,
const struct drm_plane_state *state,
struct drm_property *property, uint64_t *val)
{
struct drm_device *dev = plane->dev;
struct drm_mode_config *config = &dev->mode_config;
if (property == config->prop_fb_id) {
*val = (state->fb) ? state->fb->base.id : 0;
} else if (property == config->prop_in_fence_fd) {
*val = -1;
} else if (property == config->prop_crtc_id) {
*val = (state->crtc) ? state->crtc->base.id : 0;
} else if (property == config->prop_crtc_x) {
*val = I642U64(state->crtc_x);
} else if (property == config->prop_crtc_y) {
*val = I642U64(state->crtc_y);
} else if (property == config->prop_crtc_w) {
*val = state->crtc_w;
} else if (property == config->prop_crtc_h) {
*val = state->crtc_h;
} else if (property == config->prop_src_x) {
*val = state->src_x;
} else if (property == config->prop_src_y) {
*val = state->src_y;
} else if (property == config->prop_src_w) {
*val = state->src_w;
} else if (property == config->prop_src_h) {
*val = state->src_h;
} else if (property == plane->rotation_property) {
*val = state->rotation;
} else if (property == plane->zpos_property) {
*val = state->zpos;
} else if (plane->funcs->atomic_get_property) {
return plane->funcs->atomic_get_property(plane, state, property, val);
} else {
return -EINVAL;
}
return 0;
}
static bool
plane_switching_crtc(struct drm_atomic_state *state,
struct drm_plane *plane,
struct drm_plane_state *plane_state)
{
if (!plane->state->crtc || !plane_state->crtc)
return false;
if (plane->state->crtc == plane_state->crtc)
return false;
return true;
}
static int drm_atomic_plane_check(struct drm_plane *plane,
struct drm_plane_state *state)
{
unsigned int fb_width, fb_height;
int ret;
if (WARN_ON(state->crtc && !state->fb)) {
DRM_DEBUG_ATOMIC("CRTC set but no FB\n");
return -EINVAL;
} else if (WARN_ON(state->fb && !state->crtc)) {
DRM_DEBUG_ATOMIC("FB set but no CRTC\n");
return -EINVAL;
}
if (!state->crtc)
return 0;
if (!(plane->possible_crtcs & drm_crtc_mask(state->crtc))) {
DRM_DEBUG_ATOMIC("Invalid crtc for plane\n");
return -EINVAL;
}
ret = drm_plane_check_pixel_format(plane, state->fb->format->format);
if (ret) {
struct drm_format_name_buf format_name;
DRM_DEBUG_ATOMIC("Invalid pixel format %s\n",
drm_get_format_name(state->fb->format->format,
&format_name));
return ret;
}
if (state->crtc_w > INT_MAX ||
state->crtc_x > INT_MAX - (int32_t) state->crtc_w ||
state->crtc_h > INT_MAX ||
state->crtc_y > INT_MAX - (int32_t) state->crtc_h) {
DRM_DEBUG_ATOMIC("Invalid CRTC coordinates %ux%u+%d+%d\n",
state->crtc_w, state->crtc_h,
state->crtc_x, state->crtc_y);
return -ERANGE;
}
fb_width = state->fb->width << 16;
fb_height = state->fb->height << 16;
if (state->src_w > fb_width ||
state->src_x > fb_width - state->src_w ||
state->src_h > fb_height ||
state->src_y > fb_height - state->src_h) {
DRM_DEBUG_ATOMIC("Invalid source coordinates "
"%u.%06ux%u.%06u+%u.%06u+%u.%06u\n",
state->src_w >> 16, ((state->src_w & 0xffff) * 15625) >> 10,
state->src_h >> 16, ((state->src_h & 0xffff) * 15625) >> 10,
state->src_x >> 16, ((state->src_x & 0xffff) * 15625) >> 10,
state->src_y >> 16, ((state->src_y & 0xffff) * 15625) >> 10);
return -ENOSPC;
}
if (plane_switching_crtc(state->state, plane, state)) {
DRM_DEBUG_ATOMIC("[PLANE:%d:%s] switching CRTC directly\n",
plane->base.id, plane->name);
return -EINVAL;
}
return 0;
}
static void drm_atomic_plane_print_state(struct drm_printer *p,
const struct drm_plane_state *state)
{
struct drm_plane *plane = state->plane;
struct drm_rect src = drm_plane_state_src(state);
struct drm_rect dest = drm_plane_state_dest(state);
drm_printf(p, "plane[%u]: %s\n", plane->base.id, plane->name);
drm_printf(p, "\tcrtc=%s\n", state->crtc ? state->crtc->name : "(null)");
drm_printf(p, "\tfb=%u\n", state->fb ? state->fb->base.id : 0);
if (state->fb) {
struct drm_framebuffer *fb = state->fb;
int i, n = fb->format->num_planes;
struct drm_format_name_buf format_name;
drm_printf(p, "\t\tformat=%s\n",
drm_get_format_name(fb->format->format, &format_name));
drm_printf(p, "\t\t\tmodifier=0x%llx\n", fb->modifier);
drm_printf(p, "\t\tsize=%dx%d\n", fb->width, fb->height);
drm_printf(p, "\t\tlayers:\n");
for (i = 0; i < n; i++) {
drm_printf(p, "\t\t\tpitch[%d]=%u\n", i, fb->pitches[i]);
drm_printf(p, "\t\t\toffset[%d]=%u\n", i, fb->offsets[i]);
}
}
drm_printf(p, "\tcrtc-pos=" DRM_RECT_FMT "\n", DRM_RECT_ARG(&dest));
drm_printf(p, "\tsrc-pos=" DRM_RECT_FP_FMT "\n", DRM_RECT_FP_ARG(&src));
drm_printf(p, "\trotation=%x\n", state->rotation);
if (plane->funcs->atomic_print_state)
plane->funcs->atomic_print_state(p, state);
}
struct drm_connector_state *
drm_atomic_get_connector_state(struct drm_atomic_state *state,
struct drm_connector *connector)
{
int ret, index;
struct drm_mode_config *config = &connector->dev->mode_config;
struct drm_connector_state *connector_state;
WARN_ON(!state->acquire_ctx);
ret = drm_modeset_lock(&config->connection_mutex, state->acquire_ctx);
if (ret)
return ERR_PTR(ret);
index = drm_connector_index(connector);
if (index >= state->num_connector) {
struct __drm_connnectors_state *c;
int alloc = max(index + 1, config->num_connector);
c = krealloc(state->connectors, alloc * sizeof(*state->connectors), GFP_KERNEL);
if (!c)
return ERR_PTR(-ENOMEM);
state->connectors = c;
memset(&state->connectors[state->num_connector], 0,
sizeof(*state->connectors) * (alloc - state->num_connector));
state->num_connector = alloc;
}
if (state->connectors[index].state)
return state->connectors[index].state;
connector_state = connector->funcs->atomic_duplicate_state(connector);
if (!connector_state)
return ERR_PTR(-ENOMEM);
drm_connector_get(connector);
state->connectors[index].state = connector_state;
state->connectors[index].old_state = connector->state;
state->connectors[index].new_state = connector_state;
state->connectors[index].ptr = connector;
connector_state->state = state;
DRM_DEBUG_ATOMIC("Added [CONNECTOR:%d:%s] %p state to %p\n",
connector->base.id, connector->name,
connector_state, state);
if (connector_state->crtc) {
struct drm_crtc_state *crtc_state;
crtc_state = drm_atomic_get_crtc_state(state,
connector_state->crtc);
if (IS_ERR(crtc_state))
return ERR_CAST(crtc_state);
}
return connector_state;
}
int drm_atomic_connector_set_property(struct drm_connector *connector,
struct drm_connector_state *state, struct drm_property *property,
uint64_t val)
{
struct drm_device *dev = connector->dev;
struct drm_mode_config *config = &dev->mode_config;
if (property == config->prop_crtc_id) {
struct drm_crtc *crtc = drm_crtc_find(dev, val);
return drm_atomic_set_crtc_for_connector(state, crtc);
} else if (property == config->dpms_property) {
return -EINVAL;
} else if (property == config->tv_select_subconnector_property) {
state->tv.subconnector = val;
} else if (property == config->tv_left_margin_property) {
state->tv.margins.left = val;
} else if (property == config->tv_right_margin_property) {
state->tv.margins.right = val;
} else if (property == config->tv_top_margin_property) {
state->tv.margins.top = val;
} else if (property == config->tv_bottom_margin_property) {
state->tv.margins.bottom = val;
} else if (property == config->tv_mode_property) {
state->tv.mode = val;
} else if (property == config->tv_brightness_property) {
state->tv.brightness = val;
} else if (property == config->tv_contrast_property) {
state->tv.contrast = val;
} else if (property == config->tv_flicker_reduction_property) {
state->tv.flicker_reduction = val;
} else if (property == config->tv_overscan_property) {
state->tv.overscan = val;
} else if (property == config->tv_saturation_property) {
state->tv.saturation = val;
} else if (property == config->tv_hue_property) {
state->tv.hue = val;
} else if (property == config->link_status_property) {
if (state->link_status != DRM_LINK_STATUS_GOOD)
state->link_status = val;
} else if (connector->funcs->atomic_set_property) {
return connector->funcs->atomic_set_property(connector,
state, property, val);
} else {
return -EINVAL;
}
return 0;
}
static void drm_atomic_connector_print_state(struct drm_printer *p,
const struct drm_connector_state *state)
{
struct drm_connector *connector = state->connector;
drm_printf(p, "connector[%u]: %s\n", connector->base.id, connector->name);
drm_printf(p, "\tcrtc=%s\n", state->crtc ? state->crtc->name : "(null)");
if (connector->funcs->atomic_print_state)
connector->funcs->atomic_print_state(p, state);
}
static int
drm_atomic_connector_get_property(struct drm_connector *connector,
const struct drm_connector_state *state,
struct drm_property *property, uint64_t *val)
{
struct drm_device *dev = connector->dev;
struct drm_mode_config *config = &dev->mode_config;
if (property == config->prop_crtc_id) {
*val = (state->crtc) ? state->crtc->base.id : 0;
} else if (property == config->dpms_property) {
*val = connector->dpms;
} else if (property == config->tv_select_subconnector_property) {
*val = state->tv.subconnector;
} else if (property == config->tv_left_margin_property) {
*val = state->tv.margins.left;
} else if (property == config->tv_right_margin_property) {
*val = state->tv.margins.right;
} else if (property == config->tv_top_margin_property) {
*val = state->tv.margins.top;
} else if (property == config->tv_bottom_margin_property) {
*val = state->tv.margins.bottom;
} else if (property == config->tv_mode_property) {
*val = state->tv.mode;
} else if (property == config->tv_brightness_property) {
*val = state->tv.brightness;
} else if (property == config->tv_contrast_property) {
*val = state->tv.contrast;
} else if (property == config->tv_flicker_reduction_property) {
*val = state->tv.flicker_reduction;
} else if (property == config->tv_overscan_property) {
*val = state->tv.overscan;
} else if (property == config->tv_saturation_property) {
*val = state->tv.saturation;
} else if (property == config->tv_hue_property) {
*val = state->tv.hue;
} else if (property == config->link_status_property) {
*val = state->link_status;
} else if (connector->funcs->atomic_get_property) {
return connector->funcs->atomic_get_property(connector,
state, property, val);
} else {
return -EINVAL;
}
return 0;
}
int drm_atomic_get_property(struct drm_mode_object *obj,
struct drm_property *property, uint64_t *val)
{
struct drm_device *dev = property->dev;
int ret;
switch (obj->type) {
case DRM_MODE_OBJECT_CONNECTOR: {
struct drm_connector *connector = obj_to_connector(obj);
WARN_ON(!drm_modeset_is_locked(&dev->mode_config.connection_mutex));
ret = drm_atomic_connector_get_property(connector,
connector->state, property, val);
break;
}
case DRM_MODE_OBJECT_CRTC: {
struct drm_crtc *crtc = obj_to_crtc(obj);
WARN_ON(!drm_modeset_is_locked(&crtc->mutex));
ret = drm_atomic_crtc_get_property(crtc,
crtc->state, property, val);
break;
}
case DRM_MODE_OBJECT_PLANE: {
struct drm_plane *plane = obj_to_plane(obj);
WARN_ON(!drm_modeset_is_locked(&plane->mutex));
ret = drm_atomic_plane_get_property(plane,
plane->state, property, val);
break;
}
default:
ret = -EINVAL;
break;
}
return ret;
}
int
drm_atomic_set_crtc_for_plane(struct drm_plane_state *plane_state,
struct drm_crtc *crtc)
{
struct drm_plane *plane = plane_state->plane;
struct drm_crtc_state *crtc_state;
if (plane_state->crtc) {
crtc_state = drm_atomic_get_crtc_state(plane_state->state,
plane_state->crtc);
if (WARN_ON(IS_ERR(crtc_state)))
return PTR_ERR(crtc_state);
crtc_state->plane_mask &= ~(1 << drm_plane_index(plane));
}
plane_state->crtc = crtc;
if (crtc) {
crtc_state = drm_atomic_get_crtc_state(plane_state->state,
crtc);
if (IS_ERR(crtc_state))
return PTR_ERR(crtc_state);
crtc_state->plane_mask |= (1 << drm_plane_index(plane));
}
if (crtc)
DRM_DEBUG_ATOMIC("Link plane state %p to [CRTC:%d:%s]\n",
plane_state, crtc->base.id, crtc->name);
else
DRM_DEBUG_ATOMIC("Link plane state %p to [NOCRTC]\n",
plane_state);
return 0;
}
void
drm_atomic_set_fb_for_plane(struct drm_plane_state *plane_state,
struct drm_framebuffer *fb)
{
if (fb)
DRM_DEBUG_ATOMIC("Set [FB:%d] for plane state %p\n",
fb->base.id, plane_state);
else
DRM_DEBUG_ATOMIC("Set [NOFB] for plane state %p\n",
plane_state);
drm_framebuffer_assign(&plane_state->fb, fb);
}
void
drm_atomic_set_fence_for_plane(struct drm_plane_state *plane_state,
struct dma_fence *fence)
{
if (plane_state->fence) {
dma_fence_put(fence);
return;
}
plane_state->fence = fence;
}
int
drm_atomic_set_crtc_for_connector(struct drm_connector_state *conn_state,
struct drm_crtc *crtc)
{
struct drm_crtc_state *crtc_state;
if (conn_state->crtc == crtc)
return 0;
if (conn_state->crtc) {
crtc_state = drm_atomic_get_new_crtc_state(conn_state->state,
conn_state->crtc);
crtc_state->connector_mask &=
~(1 << drm_connector_index(conn_state->connector));
drm_connector_put(conn_state->connector);
conn_state->crtc = NULL;
}
if (crtc) {
crtc_state = drm_atomic_get_crtc_state(conn_state->state, crtc);
if (IS_ERR(crtc_state))
return PTR_ERR(crtc_state);
crtc_state->connector_mask |=
1 << drm_connector_index(conn_state->connector);
drm_connector_get(conn_state->connector);
conn_state->crtc = crtc;
DRM_DEBUG_ATOMIC("Link connector state %p to [CRTC:%d:%s]\n",
conn_state, crtc->base.id, crtc->name);
} else {
DRM_DEBUG_ATOMIC("Link connector state %p to [NOCRTC]\n",
conn_state);
}
return 0;
}
int
drm_atomic_add_affected_connectors(struct drm_atomic_state *state,
struct drm_crtc *crtc)
{
struct drm_mode_config *config = &state->dev->mode_config;
struct drm_connector *connector;
struct drm_connector_state *conn_state;
struct drm_connector_list_iter conn_iter;
struct drm_crtc_state *crtc_state;
int ret;
crtc_state = drm_atomic_get_crtc_state(state, crtc);
if (IS_ERR(crtc_state))
return PTR_ERR(crtc_state);
ret = drm_modeset_lock(&config->connection_mutex, state->acquire_ctx);
if (ret)
return ret;
DRM_DEBUG_ATOMIC("Adding all current connectors for [CRTC:%d:%s] to %p\n",
crtc->base.id, crtc->name, state);
drm_connector_list_iter_begin(state->dev, &conn_iter);
drm_for_each_connector_iter(connector, &conn_iter) {
if (!(crtc_state->connector_mask & (1 << drm_connector_index(connector))))
continue;
conn_state = drm_atomic_get_connector_state(state, connector);
if (IS_ERR(conn_state)) {
drm_connector_list_iter_end(&conn_iter);
return PTR_ERR(conn_state);
}
}
drm_connector_list_iter_end(&conn_iter);
return 0;
}
int
drm_atomic_add_affected_planes(struct drm_atomic_state *state,
struct drm_crtc *crtc)
{
struct drm_plane *plane;
WARN_ON(!drm_atomic_get_new_crtc_state(state, crtc));
drm_for_each_plane_mask(plane, state->dev, crtc->state->plane_mask) {
struct drm_plane_state *plane_state =
drm_atomic_get_plane_state(state, plane);
if (IS_ERR(plane_state))
return PTR_ERR(plane_state);
}
return 0;
}
void drm_atomic_legacy_backoff(struct drm_atomic_state *state)
{
struct drm_device *dev = state->dev;
int ret;
bool global = false;
if (WARN_ON(dev->mode_config.acquire_ctx == state->acquire_ctx)) {
global = true;
dev->mode_config.acquire_ctx = NULL;
}
retry:
drm_modeset_backoff(state->acquire_ctx);
ret = drm_modeset_lock_all_ctx(dev, state->acquire_ctx);
if (ret)
goto retry;
if (global)
dev->mode_config.acquire_ctx = state->acquire_ctx;
}
int drm_atomic_check_only(struct drm_atomic_state *state)
{
struct drm_device *dev = state->dev;
struct drm_mode_config *config = &dev->mode_config;
struct drm_plane *plane;
struct drm_plane_state *plane_state;
struct drm_crtc *crtc;
struct drm_crtc_state *crtc_state;
int i, ret = 0;
DRM_DEBUG_ATOMIC("checking %p\n", state);
for_each_new_plane_in_state(state, plane, plane_state, i) {
ret = drm_atomic_plane_check(plane, plane_state);
if (ret) {
DRM_DEBUG_ATOMIC("[PLANE:%d:%s] atomic core check failed\n",
plane->base.id, plane->name);
return ret;
}
}
for_each_new_crtc_in_state(state, crtc, crtc_state, i) {
ret = drm_atomic_crtc_check(crtc, crtc_state);
if (ret) {
DRM_DEBUG_ATOMIC("[CRTC:%d:%s] atomic core check failed\n",
crtc->base.id, crtc->name);
return ret;
}
}
if (config->funcs->atomic_check)
ret = config->funcs->atomic_check(state->dev, state);
if (!state->allow_modeset) {
for_each_new_crtc_in_state(state, crtc, crtc_state, i) {
if (drm_atomic_crtc_needs_modeset(crtc_state)) {
DRM_DEBUG_ATOMIC("[CRTC:%d:%s] requires full modeset\n",
crtc->base.id, crtc->name);
return -EINVAL;
}
}
}
return ret;
}
int drm_atomic_commit(struct drm_atomic_state *state)
{
struct drm_mode_config *config = &state->dev->mode_config;
int ret;
ret = drm_atomic_check_only(state);
if (ret)
return ret;
DRM_DEBUG_ATOMIC("commiting %p\n", state);
return config->funcs->atomic_commit(state->dev, state, false);
}
int drm_atomic_nonblocking_commit(struct drm_atomic_state *state)
{
struct drm_mode_config *config = &state->dev->mode_config;
int ret;
ret = drm_atomic_check_only(state);
if (ret)
return ret;
DRM_DEBUG_ATOMIC("commiting %p nonblocking\n", state);
return config->funcs->atomic_commit(state->dev, state, true);
}
static void drm_atomic_print_state(const struct drm_atomic_state *state)
{
struct drm_printer p = drm_info_printer(state->dev->dev);
struct drm_plane *plane;
struct drm_plane_state *plane_state;
struct drm_crtc *crtc;
struct drm_crtc_state *crtc_state;
struct drm_connector *connector;
struct drm_connector_state *connector_state;
int i;
DRM_DEBUG_ATOMIC("checking %p\n", state);
for_each_new_plane_in_state(state, plane, plane_state, i)
drm_atomic_plane_print_state(&p, plane_state);
for_each_new_crtc_in_state(state, crtc, crtc_state, i)
drm_atomic_crtc_print_state(&p, crtc_state);
for_each_new_connector_in_state(state, connector, connector_state, i)
drm_atomic_connector_print_state(&p, connector_state);
}
static void __drm_state_dump(struct drm_device *dev, struct drm_printer *p,
bool take_locks)
{
struct drm_mode_config *config = &dev->mode_config;
struct drm_plane *plane;
struct drm_crtc *crtc;
struct drm_connector *connector;
struct drm_connector_list_iter conn_iter;
if (!drm_core_check_feature(dev, DRIVER_ATOMIC))
return;
list_for_each_entry(plane, &config->plane_list, head) {
if (take_locks)
drm_modeset_lock(&plane->mutex, NULL);
drm_atomic_plane_print_state(p, plane->state);
if (take_locks)
drm_modeset_unlock(&plane->mutex);
}
list_for_each_entry(crtc, &config->crtc_list, head) {
if (take_locks)
drm_modeset_lock(&crtc->mutex, NULL);
drm_atomic_crtc_print_state(p, crtc->state);
if (take_locks)
drm_modeset_unlock(&crtc->mutex);
}
drm_connector_list_iter_begin(dev, &conn_iter);
if (take_locks)
drm_modeset_lock(&dev->mode_config.connection_mutex, NULL);
drm_for_each_connector_iter(connector, &conn_iter)
drm_atomic_connector_print_state(p, connector->state);
if (take_locks)
drm_modeset_unlock(&dev->mode_config.connection_mutex);
drm_connector_list_iter_end(&conn_iter);
}
void drm_state_dump(struct drm_device *dev, struct drm_printer *p)
{
__drm_state_dump(dev, p, false);
}
static int drm_state_info(struct seq_file *m, void *data)
{
struct drm_info_node *node = (struct drm_info_node *) m->private;
struct drm_device *dev = node->minor->dev;
struct drm_printer p = drm_seq_file_printer(m);
__drm_state_dump(dev, &p, true);
return 0;
}
int drm_atomic_debugfs_init(struct drm_minor *minor)
{
return drm_debugfs_create_files(drm_atomic_debugfs_list,
ARRAY_SIZE(drm_atomic_debugfs_list),
minor->debugfs_root, minor);
}
static struct drm_pending_vblank_event *create_vblank_event(
struct drm_device *dev, uint64_t user_data)
{
struct drm_pending_vblank_event *e = NULL;
e = kzalloc(sizeof *e, GFP_KERNEL);
if (!e)
return NULL;
e->event.base.type = DRM_EVENT_FLIP_COMPLETE;
e->event.base.length = sizeof(e->event);
e->event.user_data = user_data;
return e;
}
static int atomic_set_prop(struct drm_atomic_state *state,
struct drm_mode_object *obj, struct drm_property *prop,
uint64_t prop_value)
{
struct drm_mode_object *ref;
int ret;
if (!drm_property_change_valid_get(prop, prop_value, &ref))
return -EINVAL;
switch (obj->type) {
case DRM_MODE_OBJECT_CONNECTOR: {
struct drm_connector *connector = obj_to_connector(obj);
struct drm_connector_state *connector_state;
connector_state = drm_atomic_get_connector_state(state, connector);
if (IS_ERR(connector_state)) {
ret = PTR_ERR(connector_state);
break;
}
ret = drm_atomic_connector_set_property(connector,
connector_state, prop, prop_value);
break;
}
case DRM_MODE_OBJECT_CRTC: {
struct drm_crtc *crtc = obj_to_crtc(obj);
struct drm_crtc_state *crtc_state;
crtc_state = drm_atomic_get_crtc_state(state, crtc);
if (IS_ERR(crtc_state)) {
ret = PTR_ERR(crtc_state);
break;
}
ret = drm_atomic_crtc_set_property(crtc,
crtc_state, prop, prop_value);
break;
}
case DRM_MODE_OBJECT_PLANE: {
struct drm_plane *plane = obj_to_plane(obj);
struct drm_plane_state *plane_state;
plane_state = drm_atomic_get_plane_state(state, plane);
if (IS_ERR(plane_state)) {
ret = PTR_ERR(plane_state);
break;
}
ret = drm_atomic_plane_set_property(plane,
plane_state, prop, prop_value);
break;
}
default:
ret = -EINVAL;
break;
}
drm_property_change_valid_put(prop, ref);
return ret;
}
void drm_atomic_clean_old_fb(struct drm_device *dev,
unsigned plane_mask,
int ret)
{
struct drm_plane *plane;
drm_for_each_plane_mask(plane, dev, plane_mask) {
if (ret == 0) {
struct drm_framebuffer *new_fb = plane->state->fb;
if (new_fb)
drm_framebuffer_get(new_fb);
plane->fb = new_fb;
plane->crtc = plane->state->crtc;
if (plane->old_fb)
drm_framebuffer_put(plane->old_fb);
}
plane->old_fb = NULL;
}
}
static int setup_out_fence(struct drm_out_fence_state *fence_state,
struct dma_fence *fence)
{
fence_state->fd = get_unused_fd_flags(O_CLOEXEC);
if (fence_state->fd < 0)
return fence_state->fd;
if (put_user(fence_state->fd, fence_state->out_fence_ptr))
return -EFAULT;
fence_state->sync_file = sync_file_create(fence);
if (!fence_state->sync_file)
return -ENOMEM;
return 0;
}
static int prepare_crtc_signaling(struct drm_device *dev,
struct drm_atomic_state *state,
struct drm_mode_atomic *arg,
struct drm_file *file_priv,
struct drm_out_fence_state **fence_state,
unsigned int *num_fences)
{
struct drm_crtc *crtc;
struct drm_crtc_state *crtc_state;
int i, ret;
if (arg->flags & DRM_MODE_ATOMIC_TEST_ONLY)
return 0;
for_each_new_crtc_in_state(state, crtc, crtc_state, i) {
s32 __user *fence_ptr;
fence_ptr = get_out_fence_for_crtc(crtc_state->state, crtc);
if (arg->flags & DRM_MODE_PAGE_FLIP_EVENT || fence_ptr) {
struct drm_pending_vblank_event *e;
e = create_vblank_event(dev, arg->user_data);
if (!e)
return -ENOMEM;
crtc_state->event = e;
}
if (arg->flags & DRM_MODE_PAGE_FLIP_EVENT) {
struct drm_pending_vblank_event *e = crtc_state->event;
if (!file_priv)
continue;
ret = drm_event_reserve_init(dev, file_priv, &e->base,
&e->event.base);
if (ret) {
kfree(e);
crtc_state->event = NULL;
return ret;
}
}
if (fence_ptr) {
struct dma_fence *fence;
struct drm_out_fence_state *f;
f = krealloc(*fence_state, sizeof(**fence_state) *
(*num_fences + 1), GFP_KERNEL);
if (!f)
return -ENOMEM;
memset(&f[*num_fences], 0, sizeof(*f));
f[*num_fences].out_fence_ptr = fence_ptr;
*fence_state = f;
fence = drm_crtc_create_fence(crtc);
if (!fence)
return -ENOMEM;
ret = setup_out_fence(&f[(*num_fences)++], fence);
if (ret) {
dma_fence_put(fence);
return ret;
}
crtc_state->event->base.fence = fence;
}
}
return 0;
}
static void complete_crtc_signaling(struct drm_device *dev,
struct drm_atomic_state *state,
struct drm_out_fence_state *fence_state,
unsigned int num_fences,
bool install_fds)
{
struct drm_crtc *crtc;
struct drm_crtc_state *crtc_state;
int i;
if (install_fds) {
for (i = 0; i < num_fences; i++)
fd_install(fence_state[i].fd,
fence_state[i].sync_file->file);
kfree(fence_state);
return;
}
for_each_new_crtc_in_state(state, crtc, crtc_state, i) {
struct drm_pending_vblank_event *event = crtc_state->event;
if (event && (event->base.fence || event->base.file_priv)) {
drm_event_cancel_free(dev, &event->base);
crtc_state->event = NULL;
}
}
if (!fence_state)
return;
for (i = 0; i < num_fences; i++) {
if (fence_state[i].sync_file)
fput(fence_state[i].sync_file->file);
if (fence_state[i].fd >= 0)
put_unused_fd(fence_state[i].fd);
if (fence_state[i].out_fence_ptr &&
put_user(-1, fence_state[i].out_fence_ptr))
DRM_DEBUG_ATOMIC("Couldn't clear out_fence_ptr\n");
}
kfree(fence_state);
}
int drm_mode_atomic_ioctl(struct drm_device *dev,
void *data, struct drm_file *file_priv)
{
struct drm_mode_atomic *arg = data;
uint32_t __user *objs_ptr = (uint32_t __user *)(unsigned long)(arg->objs_ptr);
uint32_t __user *count_props_ptr = (uint32_t __user *)(unsigned long)(arg->count_props_ptr);
uint32_t __user *props_ptr = (uint32_t __user *)(unsigned long)(arg->props_ptr);
uint64_t __user *prop_values_ptr = (uint64_t __user *)(unsigned long)(arg->prop_values_ptr);
unsigned int copied_objs, copied_props;
struct drm_atomic_state *state;
struct drm_modeset_acquire_ctx ctx;
struct drm_plane *plane;
struct drm_out_fence_state *fence_state = NULL;
unsigned plane_mask;
int ret = 0;
unsigned int i, j, num_fences = 0;
if (!drm_core_check_feature(dev, DRIVER_ATOMIC))
return -EINVAL;
if (!file_priv->atomic)
return -EINVAL;
if (arg->flags & ~DRM_MODE_ATOMIC_FLAGS)
return -EINVAL;
if (arg->reserved)
return -EINVAL;
if ((arg->flags & DRM_MODE_PAGE_FLIP_ASYNC) &&
!dev->mode_config.async_page_flip)
return -EINVAL;
if ((arg->flags & DRM_MODE_ATOMIC_TEST_ONLY) &&
(arg->flags & DRM_MODE_PAGE_FLIP_EVENT))
return -EINVAL;
drm_modeset_acquire_init(&ctx, 0);
state = drm_atomic_state_alloc(dev);
if (!state)
return -ENOMEM;
state->acquire_ctx = &ctx;
state->allow_modeset = !!(arg->flags & DRM_MODE_ATOMIC_ALLOW_MODESET);
retry:
plane_mask = 0;
copied_objs = 0;
copied_props = 0;
for (i = 0; i < arg->count_objs; i++) {
uint32_t obj_id, count_props;
struct drm_mode_object *obj;
if (get_user(obj_id, objs_ptr + copied_objs)) {
ret = -EFAULT;
goto out;
}
obj = drm_mode_object_find(dev, obj_id, DRM_MODE_OBJECT_ANY);
if (!obj) {
ret = -ENOENT;
goto out;
}
if (!obj->properties) {
drm_mode_object_put(obj);
ret = -ENOENT;
goto out;
}
if (get_user(count_props, count_props_ptr + copied_objs)) {
drm_mode_object_put(obj);
ret = -EFAULT;
goto out;
}
copied_objs++;
for (j = 0; j < count_props; j++) {
uint32_t prop_id;
uint64_t prop_value;
struct drm_property *prop;
if (get_user(prop_id, props_ptr + copied_props)) {
drm_mode_object_put(obj);
ret = -EFAULT;
goto out;
}
prop = drm_mode_obj_find_prop_id(obj, prop_id);
if (!prop) {
drm_mode_object_put(obj);
ret = -ENOENT;
goto out;
}
if (copy_from_user(&prop_value,
prop_values_ptr + copied_props,
sizeof(prop_value))) {
drm_mode_object_put(obj);
ret = -EFAULT;
goto out;
}
ret = atomic_set_prop(state, obj, prop, prop_value);
if (ret) {
drm_mode_object_put(obj);
goto out;
}
copied_props++;
}
if (obj->type == DRM_MODE_OBJECT_PLANE && count_props &&
!(arg->flags & DRM_MODE_ATOMIC_TEST_ONLY)) {
plane = obj_to_plane(obj);
plane_mask |= (1 << drm_plane_index(plane));
plane->old_fb = plane->fb;
}
drm_mode_object_put(obj);
}
ret = prepare_crtc_signaling(dev, state, arg, file_priv, &fence_state,
&num_fences);
if (ret)
goto out;
if (arg->flags & DRM_MODE_ATOMIC_TEST_ONLY) {
ret = drm_atomic_check_only(state);
} else if (arg->flags & DRM_MODE_ATOMIC_NONBLOCK) {
ret = drm_atomic_nonblocking_commit(state);
} else {
if (unlikely(drm_debug & DRM_UT_STATE))
drm_atomic_print_state(state);
ret = drm_atomic_commit(state);
}
out:
drm_atomic_clean_old_fb(dev, plane_mask, ret);
complete_crtc_signaling(dev, state, fence_state, num_fences, !ret);
if (ret == -EDEADLK) {
drm_atomic_state_clear(state);
drm_modeset_backoff(&ctx);
goto retry;
}
drm_atomic_state_put(state);
drm_modeset_drop_locks(&ctx);
drm_modeset_acquire_fini(&ctx);
return ret;
}
