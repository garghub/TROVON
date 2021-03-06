static void virtio_gpu_user_framebuffer_destroy(struct drm_framebuffer *fb)
{
struct virtio_gpu_framebuffer *virtio_gpu_fb
= to_virtio_gpu_framebuffer(fb);
drm_gem_object_unreference_unlocked(virtio_gpu_fb->obj);
drm_framebuffer_cleanup(fb);
kfree(virtio_gpu_fb);
}
static int
virtio_gpu_framebuffer_surface_dirty(struct drm_framebuffer *fb,
struct drm_file *file_priv,
unsigned flags, unsigned color,
struct drm_clip_rect *clips,
unsigned num_clips)
{
struct virtio_gpu_framebuffer *virtio_gpu_fb
= to_virtio_gpu_framebuffer(fb);
return virtio_gpu_surface_dirty(virtio_gpu_fb, clips, num_clips);
}
int
virtio_gpu_framebuffer_init(struct drm_device *dev,
struct virtio_gpu_framebuffer *vgfb,
const struct drm_mode_fb_cmd2 *mode_cmd,
struct drm_gem_object *obj)
{
int ret;
struct virtio_gpu_object *bo;
vgfb->obj = obj;
bo = gem_to_virtio_gpu_obj(obj);
ret = drm_framebuffer_init(dev, &vgfb->base, &virtio_gpu_fb_funcs);
if (ret) {
vgfb->obj = NULL;
return ret;
}
drm_helper_mode_fill_fb_struct(&vgfb->base, mode_cmd);
spin_lock_init(&vgfb->dirty_lock);
vgfb->x1 = vgfb->y1 = INT_MAX;
vgfb->x2 = vgfb->y2 = 0;
return 0;
}
static void virtio_gpu_crtc_mode_set_nofb(struct drm_crtc *crtc)
{
struct drm_device *dev = crtc->dev;
struct virtio_gpu_device *vgdev = dev->dev_private;
struct virtio_gpu_output *output = drm_crtc_to_virtio_gpu_output(crtc);
virtio_gpu_cmd_set_scanout(vgdev, output->index, 0,
crtc->mode.hdisplay,
crtc->mode.vdisplay, 0, 0);
}
static void virtio_gpu_crtc_enable(struct drm_crtc *crtc)
{
}
static void virtio_gpu_crtc_disable(struct drm_crtc *crtc)
{
struct drm_device *dev = crtc->dev;
struct virtio_gpu_device *vgdev = dev->dev_private;
struct virtio_gpu_output *output = drm_crtc_to_virtio_gpu_output(crtc);
virtio_gpu_cmd_set_scanout(vgdev, output->index, 0, 0, 0, 0, 0);
}
static int virtio_gpu_crtc_atomic_check(struct drm_crtc *crtc,
struct drm_crtc_state *state)
{
return 0;
}
static void virtio_gpu_crtc_atomic_flush(struct drm_crtc *crtc,
struct drm_crtc_state *old_state)
{
unsigned long flags;
spin_lock_irqsave(&crtc->dev->event_lock, flags);
if (crtc->state->event)
drm_crtc_send_vblank_event(crtc, crtc->state->event);
crtc->state->event = NULL;
spin_unlock_irqrestore(&crtc->dev->event_lock, flags);
}
static void virtio_gpu_enc_mode_set(struct drm_encoder *encoder,
struct drm_display_mode *mode,
struct drm_display_mode *adjusted_mode)
{
}
static void virtio_gpu_enc_enable(struct drm_encoder *encoder)
{
}
static void virtio_gpu_enc_disable(struct drm_encoder *encoder)
{
}
static int virtio_gpu_conn_get_modes(struct drm_connector *connector)
{
struct virtio_gpu_output *output =
drm_connector_to_virtio_gpu_output(connector);
struct drm_display_mode *mode = NULL;
int count, width, height;
width = le32_to_cpu(output->info.r.width);
height = le32_to_cpu(output->info.r.height);
count = drm_add_modes_noedid(connector, XRES_MAX, YRES_MAX);
if (width == 0 || height == 0) {
width = XRES_DEF;
height = YRES_DEF;
drm_set_preferred_mode(connector, XRES_DEF, YRES_DEF);
} else {
DRM_DEBUG("add mode: %dx%d\n", width, height);
mode = drm_cvt_mode(connector->dev, width, height, 60,
false, false, false);
mode->type |= DRM_MODE_TYPE_PREFERRED;
drm_mode_probed_add(connector, mode);
count++;
}
return count;
}
static int virtio_gpu_conn_mode_valid(struct drm_connector *connector,
struct drm_display_mode *mode)
{
struct virtio_gpu_output *output =
drm_connector_to_virtio_gpu_output(connector);
int width, height;
width = le32_to_cpu(output->info.r.width);
height = le32_to_cpu(output->info.r.height);
if (!(mode->type & DRM_MODE_TYPE_PREFERRED))
return MODE_OK;
if (mode->hdisplay == XRES_DEF && mode->vdisplay == YRES_DEF)
return MODE_OK;
if (mode->hdisplay <= width && mode->hdisplay >= width - 16 &&
mode->vdisplay <= height && mode->vdisplay >= height - 16)
return MODE_OK;
DRM_DEBUG("del mode: %dx%d\n", mode->hdisplay, mode->vdisplay);
return MODE_BAD;
}
static enum drm_connector_status virtio_gpu_conn_detect(
struct drm_connector *connector,
bool force)
{
struct virtio_gpu_output *output =
drm_connector_to_virtio_gpu_output(connector);
if (output->info.enabled)
return connector_status_connected;
else
return connector_status_disconnected;
}
static void virtio_gpu_conn_destroy(struct drm_connector *connector)
{
struct virtio_gpu_output *virtio_gpu_output =
drm_connector_to_virtio_gpu_output(connector);
drm_connector_unregister(connector);
drm_connector_cleanup(connector);
kfree(virtio_gpu_output);
}
static int vgdev_output_init(struct virtio_gpu_device *vgdev, int index)
{
struct drm_device *dev = vgdev->ddev;
struct virtio_gpu_output *output = vgdev->outputs + index;
struct drm_connector *connector = &output->conn;
struct drm_encoder *encoder = &output->enc;
struct drm_crtc *crtc = &output->crtc;
struct drm_plane *primary, *cursor;
output->index = index;
if (index == 0) {
output->info.enabled = cpu_to_le32(true);
output->info.r.width = cpu_to_le32(XRES_DEF);
output->info.r.height = cpu_to_le32(YRES_DEF);
}
primary = virtio_gpu_plane_init(vgdev, DRM_PLANE_TYPE_PRIMARY, index);
if (IS_ERR(primary))
return PTR_ERR(primary);
cursor = virtio_gpu_plane_init(vgdev, DRM_PLANE_TYPE_CURSOR, index);
if (IS_ERR(cursor))
return PTR_ERR(cursor);
drm_crtc_init_with_planes(dev, crtc, primary, cursor,
&virtio_gpu_crtc_funcs, NULL);
drm_crtc_helper_add(crtc, &virtio_gpu_crtc_helper_funcs);
primary->crtc = crtc;
cursor->crtc = crtc;
drm_connector_init(dev, connector, &virtio_gpu_connector_funcs,
DRM_MODE_CONNECTOR_VIRTUAL);
drm_connector_helper_add(connector, &virtio_gpu_conn_helper_funcs);
drm_encoder_init(dev, encoder, &virtio_gpu_enc_funcs,
DRM_MODE_ENCODER_VIRTUAL, NULL);
drm_encoder_helper_add(encoder, &virtio_gpu_enc_helper_funcs);
encoder->possible_crtcs = 1 << index;
drm_mode_connector_attach_encoder(connector, encoder);
drm_connector_register(connector);
return 0;
}
static struct drm_framebuffer *
virtio_gpu_user_framebuffer_create(struct drm_device *dev,
struct drm_file *file_priv,
const struct drm_mode_fb_cmd2 *mode_cmd)
{
struct drm_gem_object *obj = NULL;
struct virtio_gpu_framebuffer *virtio_gpu_fb;
int ret;
obj = drm_gem_object_lookup(file_priv, mode_cmd->handles[0]);
if (!obj)
return ERR_PTR(-EINVAL);
virtio_gpu_fb = kzalloc(sizeof(*virtio_gpu_fb), GFP_KERNEL);
if (virtio_gpu_fb == NULL)
return ERR_PTR(-ENOMEM);
ret = virtio_gpu_framebuffer_init(dev, virtio_gpu_fb, mode_cmd, obj);
if (ret) {
kfree(virtio_gpu_fb);
drm_gem_object_unreference_unlocked(obj);
return NULL;
}
return &virtio_gpu_fb->base;
}
static void vgdev_atomic_commit_tail(struct drm_atomic_state *state)
{
struct drm_device *dev = state->dev;
drm_atomic_helper_commit_modeset_disables(dev, state);
drm_atomic_helper_commit_modeset_enables(dev, state);
drm_atomic_helper_commit_planes(dev, state, true);
drm_atomic_helper_commit_hw_done(state);
drm_atomic_helper_wait_for_vblanks(dev, state);
drm_atomic_helper_cleanup_planes(dev, state);
}
int virtio_gpu_modeset_init(struct virtio_gpu_device *vgdev)
{
int i;
drm_mode_config_init(vgdev->ddev);
vgdev->ddev->mode_config.funcs = &virtio_gpu_mode_funcs;
vgdev->ddev->mode_config.helper_private = &virtio_mode_config_helpers;
vgdev->ddev->mode_config.min_width = XRES_MIN;
vgdev->ddev->mode_config.min_height = YRES_MIN;
vgdev->ddev->mode_config.max_width = XRES_MAX;
vgdev->ddev->mode_config.max_height = YRES_MAX;
for (i = 0 ; i < vgdev->num_scanouts; ++i)
vgdev_output_init(vgdev, i);
drm_mode_config_reset(vgdev->ddev);
return 0;
}
void virtio_gpu_modeset_fini(struct virtio_gpu_device *vgdev)
{
virtio_gpu_fbdev_fini(vgdev);
drm_mode_config_cleanup(vgdev->ddev);
}
