static inline struct tinydrm_connector *
to_tinydrm_connector(struct drm_connector *connector)
{
return container_of(connector, struct tinydrm_connector, base);
}
static int tinydrm_connector_get_modes(struct drm_connector *connector)
{
struct tinydrm_connector *tconn = to_tinydrm_connector(connector);
struct drm_display_mode *mode;
mode = drm_mode_duplicate(connector->dev, tconn->mode);
if (!mode) {
DRM_ERROR("Failed to duplicate mode\n");
return 0;
}
if (mode->name[0] == '\0')
drm_mode_set_name(mode);
mode->type |= DRM_MODE_TYPE_PREFERRED;
drm_mode_probed_add(connector, mode);
if (mode->width_mm) {
connector->display_info.width_mm = mode->width_mm;
connector->display_info.height_mm = mode->height_mm;
}
return 1;
}
static enum drm_connector_status
tinydrm_connector_detect(struct drm_connector *connector, bool force)
{
if (drm_device_is_unplugged(connector->dev))
return connector_status_disconnected;
return connector->status;
}
static void tinydrm_connector_destroy(struct drm_connector *connector)
{
struct tinydrm_connector *tconn = to_tinydrm_connector(connector);
drm_connector_cleanup(connector);
kfree(tconn);
}
struct drm_connector *
tinydrm_connector_create(struct drm_device *drm,
const struct drm_display_mode *mode,
int connector_type)
{
struct tinydrm_connector *tconn;
struct drm_connector *connector;
int ret;
tconn = kzalloc(sizeof(*tconn), GFP_KERNEL);
if (!tconn)
return ERR_PTR(-ENOMEM);
tconn->mode = mode;
connector = &tconn->base;
drm_connector_helper_add(connector, &tinydrm_connector_hfuncs);
ret = drm_connector_init(drm, connector, &tinydrm_connector_funcs,
connector_type);
if (ret) {
kfree(tconn);
return ERR_PTR(ret);
}
connector->status = connector_status_connected;
return connector;
}
void tinydrm_display_pipe_update(struct drm_simple_display_pipe *pipe,
struct drm_plane_state *old_state)
{
struct tinydrm_device *tdev = pipe_to_tinydrm(pipe);
struct drm_framebuffer *fb = pipe->plane.state->fb;
struct drm_crtc *crtc = &tdev->pipe.crtc;
if (fb && (fb != old_state->fb)) {
pipe->plane.fb = fb;
if (fb->funcs->dirty)
fb->funcs->dirty(fb, NULL, 0, 0, NULL, 0);
}
if (crtc->state->event) {
spin_lock_irq(&crtc->dev->event_lock);
drm_crtc_send_vblank_event(crtc, crtc->state->event);
spin_unlock_irq(&crtc->dev->event_lock);
crtc->state->event = NULL;
}
}
int tinydrm_display_pipe_prepare_fb(struct drm_simple_display_pipe *pipe,
struct drm_plane_state *plane_state)
{
return drm_fb_cma_prepare_fb(&pipe->plane, plane_state);
}
static int tinydrm_rotate_mode(struct drm_display_mode *mode,
unsigned int rotation)
{
if (rotation == 0 || rotation == 180) {
return 0;
} else if (rotation == 90 || rotation == 270) {
swap(mode->hdisplay, mode->vdisplay);
swap(mode->hsync_start, mode->vsync_start);
swap(mode->hsync_end, mode->vsync_end);
swap(mode->htotal, mode->vtotal);
swap(mode->width_mm, mode->height_mm);
return 0;
} else {
return -EINVAL;
}
}
int
tinydrm_display_pipe_init(struct tinydrm_device *tdev,
const struct drm_simple_display_pipe_funcs *funcs,
int connector_type,
const uint32_t *formats,
unsigned int format_count,
const struct drm_display_mode *mode,
unsigned int rotation)
{
struct drm_device *drm = tdev->drm;
struct drm_display_mode *mode_copy;
struct drm_connector *connector;
int ret;
mode_copy = devm_kmalloc(drm->dev, sizeof(*mode_copy), GFP_KERNEL);
if (!mode_copy)
return -ENOMEM;
*mode_copy = *mode;
ret = tinydrm_rotate_mode(mode_copy, rotation);
if (ret) {
DRM_ERROR("Illegal rotation value %u\n", rotation);
return -EINVAL;
}
drm->mode_config.min_width = mode_copy->hdisplay;
drm->mode_config.max_width = mode_copy->hdisplay;
drm->mode_config.min_height = mode_copy->vdisplay;
drm->mode_config.max_height = mode_copy->vdisplay;
connector = tinydrm_connector_create(drm, mode_copy, connector_type);
if (IS_ERR(connector))
return PTR_ERR(connector);
ret = drm_simple_display_pipe_init(drm, &tdev->pipe, funcs, formats,
format_count, connector);
if (ret)
return ret;
return 0;
}
