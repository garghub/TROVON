static void
virtio_gpu_hide_cursor(struct virtio_gpu_device *vgdev,
struct virtio_gpu_output *output)
{
output->cursor.hdr.type = cpu_to_le32(VIRTIO_GPU_CMD_UPDATE_CURSOR);
output->cursor.resource_id = 0;
virtio_gpu_cursor_ping(vgdev, output);
}
static int virtio_gpu_crtc_cursor_set(struct drm_crtc *crtc,
struct drm_file *file_priv,
uint32_t handle,
uint32_t width,
uint32_t height,
int32_t hot_x, int32_t hot_y)
{
struct virtio_gpu_device *vgdev = crtc->dev->dev_private;
struct virtio_gpu_output *output =
container_of(crtc, struct virtio_gpu_output, crtc);
struct drm_gem_object *gobj = NULL;
struct virtio_gpu_object *qobj = NULL;
struct virtio_gpu_fence *fence = NULL;
int ret = 0;
if (handle == 0) {
virtio_gpu_hide_cursor(vgdev, output);
return 0;
}
gobj = drm_gem_object_lookup(file_priv, handle);
if (gobj == NULL)
return -ENOENT;
qobj = gem_to_virtio_gpu_obj(gobj);
if (!qobj->hw_res_handle) {
ret = -EINVAL;
goto out;
}
virtio_gpu_cmd_transfer_to_host_2d(vgdev, qobj->hw_res_handle, 0,
cpu_to_le32(64),
cpu_to_le32(64),
0, 0, &fence);
ret = virtio_gpu_object_reserve(qobj, false);
if (!ret) {
reservation_object_add_excl_fence(qobj->tbo.resv,
&fence->f);
fence_put(&fence->f);
virtio_gpu_object_unreserve(qobj);
virtio_gpu_object_wait(qobj, false);
}
output->cursor.hdr.type = cpu_to_le32(VIRTIO_GPU_CMD_UPDATE_CURSOR);
output->cursor.resource_id = cpu_to_le32(qobj->hw_res_handle);
output->cursor.hot_x = cpu_to_le32(hot_x);
output->cursor.hot_y = cpu_to_le32(hot_y);
virtio_gpu_cursor_ping(vgdev, output);
ret = 0;
out:
drm_gem_object_unreference_unlocked(gobj);
return ret;
}
static int virtio_gpu_crtc_cursor_move(struct drm_crtc *crtc,
int x, int y)
{
struct virtio_gpu_device *vgdev = crtc->dev->dev_private;
struct virtio_gpu_output *output =
container_of(crtc, struct virtio_gpu_output, crtc);
output->cursor.hdr.type = cpu_to_le32(VIRTIO_GPU_CMD_MOVE_CURSOR);
output->cursor.pos.x = cpu_to_le32(x);
output->cursor.pos.y = cpu_to_le32(y);
virtio_gpu_cursor_ping(vgdev, output);
return 0;
}
static int virtio_gpu_page_flip(struct drm_crtc *crtc,
struct drm_framebuffer *fb,
struct drm_pending_vblank_event *event,
uint32_t flags)
{
struct virtio_gpu_device *vgdev = crtc->dev->dev_private;
struct virtio_gpu_output *output =
container_of(crtc, struct virtio_gpu_output, crtc);
struct drm_plane *plane = crtc->primary;
struct virtio_gpu_framebuffer *vgfb;
struct virtio_gpu_object *bo;
unsigned long irqflags;
uint32_t handle;
plane->fb = fb;
vgfb = to_virtio_gpu_framebuffer(plane->fb);
bo = gem_to_virtio_gpu_obj(vgfb->obj);
handle = bo->hw_res_handle;
DRM_DEBUG("handle 0x%x%s, crtc %dx%d\n", handle,
bo->dumb ? ", dumb" : "",
crtc->mode.hdisplay, crtc->mode.vdisplay);
if (bo->dumb) {
virtio_gpu_cmd_transfer_to_host_2d
(vgdev, handle, 0,
cpu_to_le32(crtc->mode.hdisplay),
cpu_to_le32(crtc->mode.vdisplay),
0, 0, NULL);
}
virtio_gpu_cmd_set_scanout(vgdev, output->index, handle,
crtc->mode.hdisplay,
crtc->mode.vdisplay, 0, 0);
virtio_gpu_cmd_resource_flush(vgdev, handle, 0, 0,
crtc->mode.hdisplay,
crtc->mode.vdisplay);
if (event) {
spin_lock_irqsave(&crtc->dev->event_lock, irqflags);
drm_send_vblank_event(crtc->dev, -1, event);
spin_unlock_irqrestore(&crtc->dev->event_lock, irqflags);
}
return 0;
}
static void virtio_gpu_user_framebuffer_destroy(struct drm_framebuffer *fb)
{
struct virtio_gpu_framebuffer *virtio_gpu_fb
= to_virtio_gpu_framebuffer(fb);
if (virtio_gpu_fb->obj)
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
static struct drm_encoder*
virtio_gpu_best_encoder(struct drm_connector *connector)
{
struct virtio_gpu_output *virtio_gpu_output =
drm_connector_to_virtio_gpu_output(connector);
return &virtio_gpu_output->enc;
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
struct drm_plane *plane;
output->index = index;
if (index == 0) {
output->info.enabled = cpu_to_le32(true);
output->info.r.width = cpu_to_le32(XRES_DEF);
output->info.r.height = cpu_to_le32(YRES_DEF);
}
plane = virtio_gpu_plane_init(vgdev, index);
if (IS_ERR(plane))
return PTR_ERR(plane);
drm_crtc_init_with_planes(dev, crtc, plane, NULL,
&virtio_gpu_crtc_funcs, NULL);
drm_crtc_helper_add(crtc, &virtio_gpu_crtc_helper_funcs);
plane->crtc = crtc;
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
if (obj)
drm_gem_object_unreference_unlocked(obj);
return NULL;
}
return &virtio_gpu_fb->base;
}
int virtio_gpu_modeset_init(struct virtio_gpu_device *vgdev)
{
int i;
drm_mode_config_init(vgdev->ddev);
vgdev->ddev->mode_config.funcs = (void *)&virtio_gpu_mode_funcs;
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
