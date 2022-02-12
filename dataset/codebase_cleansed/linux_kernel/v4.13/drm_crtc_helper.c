bool drm_helper_encoder_in_use(struct drm_encoder *encoder)
{
struct drm_connector *connector;
struct drm_connector_list_iter conn_iter;
struct drm_device *dev = encoder->dev;
if (!oops_in_progress) {
WARN_ON(!mutex_is_locked(&dev->mode_config.mutex));
WARN_ON(!drm_modeset_is_locked(&dev->mode_config.connection_mutex));
}
drm_connector_list_iter_begin(dev, &conn_iter);
drm_for_each_connector_iter(connector, &conn_iter) {
if (connector->encoder == encoder) {
drm_connector_list_iter_end(&conn_iter);
return true;
}
}
drm_connector_list_iter_end(&conn_iter);
return false;
}
bool drm_helper_crtc_in_use(struct drm_crtc *crtc)
{
struct drm_encoder *encoder;
struct drm_device *dev = crtc->dev;
if (!oops_in_progress)
WARN_ON(!mutex_is_locked(&dev->mode_config.mutex));
drm_for_each_encoder(encoder, dev)
if (encoder->crtc == crtc && drm_helper_encoder_in_use(encoder))
return true;
return false;
}
static void
drm_encoder_disable(struct drm_encoder *encoder)
{
const struct drm_encoder_helper_funcs *encoder_funcs = encoder->helper_private;
if (!encoder_funcs)
return;
drm_bridge_disable(encoder->bridge);
if (encoder_funcs->disable)
(*encoder_funcs->disable)(encoder);
else if (encoder_funcs->dpms)
(*encoder_funcs->dpms)(encoder, DRM_MODE_DPMS_OFF);
drm_bridge_post_disable(encoder->bridge);
}
static void __drm_helper_disable_unused_functions(struct drm_device *dev)
{
struct drm_encoder *encoder;
struct drm_crtc *crtc;
drm_warn_on_modeset_not_all_locked(dev);
drm_for_each_encoder(encoder, dev) {
if (!drm_helper_encoder_in_use(encoder)) {
drm_encoder_disable(encoder);
encoder->crtc = NULL;
}
}
drm_for_each_crtc(crtc, dev) {
const struct drm_crtc_helper_funcs *crtc_funcs = crtc->helper_private;
crtc->enabled = drm_helper_crtc_in_use(crtc);
if (!crtc->enabled) {
if (crtc_funcs->disable)
(*crtc_funcs->disable)(crtc);
else
(*crtc_funcs->dpms)(crtc, DRM_MODE_DPMS_OFF);
crtc->primary->fb = NULL;
}
}
}
void drm_helper_disable_unused_functions(struct drm_device *dev)
{
if (drm_core_check_feature(dev, DRIVER_ATOMIC))
DRM_ERROR("Called for atomic driver, this is not what you want.\n");
drm_modeset_lock_all(dev);
__drm_helper_disable_unused_functions(dev);
drm_modeset_unlock_all(dev);
}
static void
drm_crtc_prepare_encoders(struct drm_device *dev)
{
const struct drm_encoder_helper_funcs *encoder_funcs;
struct drm_encoder *encoder;
drm_for_each_encoder(encoder, dev) {
encoder_funcs = encoder->helper_private;
if (!encoder_funcs)
continue;
if (encoder->crtc == NULL)
drm_encoder_disable(encoder);
if (encoder_funcs->get_crtc &&
encoder->crtc != (*encoder_funcs->get_crtc)(encoder))
drm_encoder_disable(encoder);
}
}
bool drm_crtc_helper_set_mode(struct drm_crtc *crtc,
struct drm_display_mode *mode,
int x, int y,
struct drm_framebuffer *old_fb)
{
struct drm_device *dev = crtc->dev;
struct drm_display_mode *adjusted_mode, saved_mode, saved_hwmode;
const struct drm_crtc_helper_funcs *crtc_funcs = crtc->helper_private;
const struct drm_encoder_helper_funcs *encoder_funcs;
int saved_x, saved_y;
bool saved_enabled;
struct drm_encoder *encoder;
bool ret = true;
drm_warn_on_modeset_not_all_locked(dev);
saved_enabled = crtc->enabled;
crtc->enabled = drm_helper_crtc_in_use(crtc);
if (!crtc->enabled)
return true;
adjusted_mode = drm_mode_duplicate(dev, mode);
if (!adjusted_mode) {
crtc->enabled = saved_enabled;
return false;
}
saved_mode = crtc->mode;
saved_hwmode = crtc->hwmode;
saved_x = crtc->x;
saved_y = crtc->y;
crtc->mode = *mode;
crtc->x = x;
crtc->y = y;
drm_for_each_encoder(encoder, dev) {
if (encoder->crtc != crtc)
continue;
encoder_funcs = encoder->helper_private;
if (!encoder_funcs)
continue;
ret = drm_bridge_mode_fixup(encoder->bridge,
mode, adjusted_mode);
if (!ret) {
DRM_DEBUG_KMS("Bridge fixup failed\n");
goto done;
}
encoder_funcs = encoder->helper_private;
if (encoder_funcs->mode_fixup) {
if (!(ret = encoder_funcs->mode_fixup(encoder, mode,
adjusted_mode))) {
DRM_DEBUG_KMS("Encoder fixup failed\n");
goto done;
}
}
}
if (crtc_funcs->mode_fixup) {
if (!(ret = crtc_funcs->mode_fixup(crtc, mode,
adjusted_mode))) {
DRM_DEBUG_KMS("CRTC fixup failed\n");
goto done;
}
}
DRM_DEBUG_KMS("[CRTC:%d:%s]\n", crtc->base.id, crtc->name);
crtc->hwmode = *adjusted_mode;
drm_for_each_encoder(encoder, dev) {
if (encoder->crtc != crtc)
continue;
encoder_funcs = encoder->helper_private;
if (!encoder_funcs)
continue;
drm_bridge_disable(encoder->bridge);
if (encoder_funcs->prepare)
encoder_funcs->prepare(encoder);
drm_bridge_post_disable(encoder->bridge);
}
drm_crtc_prepare_encoders(dev);
crtc_funcs->prepare(crtc);
ret = !crtc_funcs->mode_set(crtc, mode, adjusted_mode, x, y, old_fb);
if (!ret)
goto done;
drm_for_each_encoder(encoder, dev) {
if (encoder->crtc != crtc)
continue;
encoder_funcs = encoder->helper_private;
if (!encoder_funcs)
continue;
DRM_DEBUG_KMS("[ENCODER:%d:%s] set [MODE:%d:%s]\n",
encoder->base.id, encoder->name,
mode->base.id, mode->name);
if (encoder_funcs->mode_set)
encoder_funcs->mode_set(encoder, mode, adjusted_mode);
drm_bridge_mode_set(encoder->bridge, mode, adjusted_mode);
}
crtc_funcs->commit(crtc);
drm_for_each_encoder(encoder, dev) {
if (encoder->crtc != crtc)
continue;
encoder_funcs = encoder->helper_private;
if (!encoder_funcs)
continue;
drm_bridge_pre_enable(encoder->bridge);
if (encoder_funcs->commit)
encoder_funcs->commit(encoder);
drm_bridge_enable(encoder->bridge);
}
drm_calc_timestamping_constants(crtc, &crtc->hwmode);
done:
drm_mode_destroy(dev, adjusted_mode);
if (!ret) {
crtc->enabled = saved_enabled;
crtc->mode = saved_mode;
crtc->hwmode = saved_hwmode;
crtc->x = saved_x;
crtc->y = saved_y;
}
return ret;
}
static void
drm_crtc_helper_disable(struct drm_crtc *crtc)
{
struct drm_device *dev = crtc->dev;
struct drm_connector *connector;
struct drm_encoder *encoder;
drm_for_each_encoder(encoder, dev) {
struct drm_connector_list_iter conn_iter;
if (encoder->crtc != crtc)
continue;
drm_connector_list_iter_begin(dev, &conn_iter);
drm_for_each_connector_iter(connector, &conn_iter) {
if (connector->encoder != encoder)
continue;
connector->encoder = NULL;
connector->dpms = DRM_MODE_DPMS_OFF;
drm_connector_put(connector);
}
drm_connector_list_iter_end(&conn_iter);
}
__drm_helper_disable_unused_functions(dev);
}
int drm_crtc_helper_set_config(struct drm_mode_set *set,
struct drm_modeset_acquire_ctx *ctx)
{
struct drm_device *dev;
struct drm_crtc **save_encoder_crtcs, *new_crtc;
struct drm_encoder **save_connector_encoders, *new_encoder, *encoder;
bool mode_changed = false;
bool fb_changed = false;
struct drm_connector *connector;
struct drm_connector_list_iter conn_iter;
int count = 0, ro, fail = 0;
const struct drm_crtc_helper_funcs *crtc_funcs;
struct drm_mode_set save_set;
int ret;
int i;
DRM_DEBUG_KMS("\n");
BUG_ON(!set);
BUG_ON(!set->crtc);
BUG_ON(!set->crtc->helper_private);
BUG_ON(!set->mode && set->fb);
BUG_ON(set->fb && set->num_connectors == 0);
crtc_funcs = set->crtc->helper_private;
if (!set->mode)
set->fb = NULL;
if (set->fb) {
DRM_DEBUG_KMS("[CRTC:%d:%s] [FB:%d] #connectors=%d (x y) (%i %i)\n",
set->crtc->base.id, set->crtc->name,
set->fb->base.id,
(int)set->num_connectors, set->x, set->y);
} else {
DRM_DEBUG_KMS("[CRTC:%d:%s] [NOFB]\n",
set->crtc->base.id, set->crtc->name);
drm_crtc_helper_disable(set->crtc);
return 0;
}
dev = set->crtc->dev;
drm_warn_on_modeset_not_all_locked(dev);
save_encoder_crtcs = kzalloc(dev->mode_config.num_encoder *
sizeof(struct drm_crtc *), GFP_KERNEL);
if (!save_encoder_crtcs)
return -ENOMEM;
save_connector_encoders = kzalloc(dev->mode_config.num_connector *
sizeof(struct drm_encoder *), GFP_KERNEL);
if (!save_connector_encoders) {
kfree(save_encoder_crtcs);
return -ENOMEM;
}
count = 0;
drm_for_each_encoder(encoder, dev) {
save_encoder_crtcs[count++] = encoder->crtc;
}
count = 0;
drm_connector_list_iter_begin(dev, &conn_iter);
drm_for_each_connector_iter(connector, &conn_iter)
save_connector_encoders[count++] = connector->encoder;
drm_connector_list_iter_end(&conn_iter);
save_set.crtc = set->crtc;
save_set.mode = &set->crtc->mode;
save_set.x = set->crtc->x;
save_set.y = set->crtc->y;
save_set.fb = set->crtc->primary->fb;
if (set->crtc->primary->fb != set->fb) {
if (set->crtc->primary->fb == NULL) {
DRM_DEBUG_KMS("crtc has no fb, full mode set\n");
mode_changed = true;
} else if (set->fb->format != set->crtc->primary->fb->format) {
mode_changed = true;
} else
fb_changed = true;
}
if (set->x != set->crtc->x || set->y != set->crtc->y)
fb_changed = true;
if (!drm_mode_equal(set->mode, &set->crtc->mode)) {
DRM_DEBUG_KMS("modes are different, full mode set\n");
drm_mode_debug_printmodeline(&set->crtc->mode);
drm_mode_debug_printmodeline(set->mode);
mode_changed = true;
}
for (ro = 0; ro < set->num_connectors; ro++) {
if (set->connectors[ro]->encoder)
continue;
drm_connector_get(set->connectors[ro]);
}
count = 0;
drm_connector_list_iter_begin(dev, &conn_iter);
drm_for_each_connector_iter(connector, &conn_iter) {
const struct drm_connector_helper_funcs *connector_funcs =
connector->helper_private;
new_encoder = connector->encoder;
for (ro = 0; ro < set->num_connectors; ro++) {
if (set->connectors[ro] == connector) {
new_encoder = connector_funcs->best_encoder(connector);
if (new_encoder == NULL)
fail = 1;
if (connector->dpms != DRM_MODE_DPMS_ON) {
DRM_DEBUG_KMS("connector dpms not on, full mode switch\n");
mode_changed = true;
}
break;
}
}
if (new_encoder != connector->encoder) {
DRM_DEBUG_KMS("encoder changed, full mode switch\n");
mode_changed = true;
if (connector->encoder)
connector->encoder->crtc = NULL;
connector->encoder = new_encoder;
}
}
drm_connector_list_iter_end(&conn_iter);
if (fail) {
ret = -EINVAL;
goto fail;
}
count = 0;
drm_connector_list_iter_begin(dev, &conn_iter);
drm_for_each_connector_iter(connector, &conn_iter) {
if (!connector->encoder)
continue;
if (connector->encoder->crtc == set->crtc)
new_crtc = NULL;
else
new_crtc = connector->encoder->crtc;
for (ro = 0; ro < set->num_connectors; ro++) {
if (set->connectors[ro] == connector)
new_crtc = set->crtc;
}
if (new_crtc &&
!drm_encoder_crtc_ok(connector->encoder, new_crtc)) {
ret = -EINVAL;
drm_connector_list_iter_end(&conn_iter);
goto fail;
}
if (new_crtc != connector->encoder->crtc) {
DRM_DEBUG_KMS("crtc changed, full mode switch\n");
mode_changed = true;
connector->encoder->crtc = new_crtc;
}
if (new_crtc) {
DRM_DEBUG_KMS("[CONNECTOR:%d:%s] to [CRTC:%d:%s]\n",
connector->base.id, connector->name,
new_crtc->base.id, new_crtc->name);
} else {
DRM_DEBUG_KMS("[CONNECTOR:%d:%s] to [NOCRTC]\n",
connector->base.id, connector->name);
}
}
drm_connector_list_iter_end(&conn_iter);
if (fb_changed && !crtc_funcs->mode_set_base)
mode_changed = true;
if (mode_changed) {
if (drm_helper_crtc_in_use(set->crtc)) {
DRM_DEBUG_KMS("attempting to set mode from"
" userspace\n");
drm_mode_debug_printmodeline(set->mode);
set->crtc->primary->fb = set->fb;
if (!drm_crtc_helper_set_mode(set->crtc, set->mode,
set->x, set->y,
save_set.fb)) {
DRM_ERROR("failed to set mode on [CRTC:%d:%s]\n",
set->crtc->base.id, set->crtc->name);
set->crtc->primary->fb = save_set.fb;
ret = -EINVAL;
goto fail;
}
DRM_DEBUG_KMS("Setting connector DPMS state to on\n");
for (i = 0; i < set->num_connectors; i++) {
DRM_DEBUG_KMS("\t[CONNECTOR:%d:%s] set DPMS on\n", set->connectors[i]->base.id,
set->connectors[i]->name);
set->connectors[i]->funcs->dpms(set->connectors[i], DRM_MODE_DPMS_ON);
}
}
__drm_helper_disable_unused_functions(dev);
} else if (fb_changed) {
set->crtc->x = set->x;
set->crtc->y = set->y;
set->crtc->primary->fb = set->fb;
ret = crtc_funcs->mode_set_base(set->crtc,
set->x, set->y, save_set.fb);
if (ret != 0) {
set->crtc->x = save_set.x;
set->crtc->y = save_set.y;
set->crtc->primary->fb = save_set.fb;
goto fail;
}
}
kfree(save_connector_encoders);
kfree(save_encoder_crtcs);
return 0;
fail:
count = 0;
drm_for_each_encoder(encoder, dev) {
encoder->crtc = save_encoder_crtcs[count++];
}
count = 0;
drm_connector_list_iter_begin(dev, &conn_iter);
drm_for_each_connector_iter(connector, &conn_iter)
connector->encoder = save_connector_encoders[count++];
drm_connector_list_iter_end(&conn_iter);
for (ro = 0; ro < set->num_connectors; ro++) {
if (set->connectors[ro]->encoder)
continue;
drm_connector_put(set->connectors[ro]);
}
if (mode_changed &&
!drm_crtc_helper_set_mode(save_set.crtc, save_set.mode, save_set.x,
save_set.y, save_set.fb))
DRM_ERROR("failed to restore config after modeset failure\n");
kfree(save_connector_encoders);
kfree(save_encoder_crtcs);
return ret;
}
static int drm_helper_choose_encoder_dpms(struct drm_encoder *encoder)
{
int dpms = DRM_MODE_DPMS_OFF;
struct drm_connector *connector;
struct drm_connector_list_iter conn_iter;
struct drm_device *dev = encoder->dev;
drm_connector_list_iter_begin(dev, &conn_iter);
drm_for_each_connector_iter(connector, &conn_iter)
if (connector->encoder == encoder)
if (connector->dpms < dpms)
dpms = connector->dpms;
drm_connector_list_iter_end(&conn_iter);
return dpms;
}
static void drm_helper_encoder_dpms(struct drm_encoder *encoder, int mode)
{
struct drm_bridge *bridge = encoder->bridge;
const struct drm_encoder_helper_funcs *encoder_funcs;
encoder_funcs = encoder->helper_private;
if (!encoder_funcs)
return;
if (mode == DRM_MODE_DPMS_ON)
drm_bridge_pre_enable(bridge);
else
drm_bridge_disable(bridge);
if (encoder_funcs->dpms)
encoder_funcs->dpms(encoder, mode);
if (mode == DRM_MODE_DPMS_ON)
drm_bridge_enable(bridge);
else
drm_bridge_post_disable(bridge);
}
static int drm_helper_choose_crtc_dpms(struct drm_crtc *crtc)
{
int dpms = DRM_MODE_DPMS_OFF;
struct drm_connector *connector;
struct drm_connector_list_iter conn_iter;
struct drm_device *dev = crtc->dev;
drm_connector_list_iter_begin(dev, &conn_iter);
drm_for_each_connector_iter(connector, &conn_iter)
if (connector->encoder && connector->encoder->crtc == crtc)
if (connector->dpms < dpms)
dpms = connector->dpms;
drm_connector_list_iter_end(&conn_iter);
return dpms;
}
int drm_helper_connector_dpms(struct drm_connector *connector, int mode)
{
struct drm_encoder *encoder = connector->encoder;
struct drm_crtc *crtc = encoder ? encoder->crtc : NULL;
int old_dpms, encoder_dpms = DRM_MODE_DPMS_OFF;
if (mode == connector->dpms)
return 0;
old_dpms = connector->dpms;
connector->dpms = mode;
if (encoder)
encoder_dpms = drm_helper_choose_encoder_dpms(encoder);
if (mode < old_dpms) {
if (crtc) {
const struct drm_crtc_helper_funcs *crtc_funcs = crtc->helper_private;
if (crtc_funcs->dpms)
(*crtc_funcs->dpms) (crtc,
drm_helper_choose_crtc_dpms(crtc));
}
if (encoder)
drm_helper_encoder_dpms(encoder, encoder_dpms);
}
if (mode > old_dpms) {
if (encoder)
drm_helper_encoder_dpms(encoder, encoder_dpms);
if (crtc) {
const struct drm_crtc_helper_funcs *crtc_funcs = crtc->helper_private;
if (crtc_funcs->dpms)
(*crtc_funcs->dpms) (crtc,
drm_helper_choose_crtc_dpms(crtc));
}
}
return 0;
}
void drm_helper_resume_force_mode(struct drm_device *dev)
{
struct drm_crtc *crtc;
struct drm_encoder *encoder;
const struct drm_crtc_helper_funcs *crtc_funcs;
int encoder_dpms;
bool ret;
drm_modeset_lock_all(dev);
drm_for_each_crtc(crtc, dev) {
if (!crtc->enabled)
continue;
ret = drm_crtc_helper_set_mode(crtc, &crtc->mode,
crtc->x, crtc->y, crtc->primary->fb);
if (ret == false)
DRM_ERROR("failed to set mode on crtc %p\n", crtc);
if (drm_helper_choose_crtc_dpms(crtc)) {
drm_for_each_encoder(encoder, dev) {
if(encoder->crtc != crtc)
continue;
encoder_dpms = drm_helper_choose_encoder_dpms(
encoder);
drm_helper_encoder_dpms(encoder, encoder_dpms);
}
crtc_funcs = crtc->helper_private;
if (crtc_funcs->dpms)
(*crtc_funcs->dpms) (crtc,
drm_helper_choose_crtc_dpms(crtc));
}
}
__drm_helper_disable_unused_functions(dev);
drm_modeset_unlock_all(dev);
}
int drm_helper_crtc_mode_set(struct drm_crtc *crtc, struct drm_display_mode *mode,
struct drm_display_mode *adjusted_mode, int x, int y,
struct drm_framebuffer *old_fb)
{
struct drm_crtc_state *crtc_state;
const struct drm_crtc_helper_funcs *crtc_funcs = crtc->helper_private;
int ret;
if (crtc->funcs->atomic_duplicate_state)
crtc_state = crtc->funcs->atomic_duplicate_state(crtc);
else {
if (!crtc->state)
drm_atomic_helper_crtc_reset(crtc);
crtc_state = drm_atomic_helper_crtc_duplicate_state(crtc);
}
if (!crtc_state)
return -ENOMEM;
crtc_state->planes_changed = true;
crtc_state->mode_changed = true;
ret = drm_atomic_set_mode_for_crtc(crtc_state, mode);
if (ret)
goto out;
drm_mode_copy(&crtc_state->adjusted_mode, adjusted_mode);
if (crtc_funcs->atomic_check) {
ret = crtc_funcs->atomic_check(crtc, crtc_state);
if (ret)
goto out;
}
swap(crtc->state, crtc_state);
crtc_funcs->mode_set_nofb(crtc);
ret = drm_helper_crtc_mode_set_base(crtc, x, y, old_fb);
out:
if (crtc_state) {
if (crtc->funcs->atomic_destroy_state)
crtc->funcs->atomic_destroy_state(crtc, crtc_state);
else
drm_atomic_helper_crtc_destroy_state(crtc, crtc_state);
}
return ret;
}
int drm_helper_crtc_mode_set_base(struct drm_crtc *crtc, int x, int y,
struct drm_framebuffer *old_fb)
{
struct drm_plane_state *plane_state;
struct drm_plane *plane = crtc->primary;
if (plane->funcs->atomic_duplicate_state)
plane_state = plane->funcs->atomic_duplicate_state(plane);
else {
if (!plane->state)
drm_atomic_helper_plane_reset(plane);
plane_state = drm_atomic_helper_plane_duplicate_state(plane);
}
if (!plane_state)
return -ENOMEM;
plane_state->plane = plane;
plane_state->crtc = crtc;
drm_atomic_set_fb_for_plane(plane_state, crtc->primary->fb);
plane_state->crtc_x = 0;
plane_state->crtc_y = 0;
plane_state->crtc_h = crtc->mode.vdisplay;
plane_state->crtc_w = crtc->mode.hdisplay;
plane_state->src_x = x << 16;
plane_state->src_y = y << 16;
plane_state->src_h = crtc->mode.vdisplay << 16;
plane_state->src_w = crtc->mode.hdisplay << 16;
return drm_plane_helper_commit(plane, plane_state, old_fb);
}
