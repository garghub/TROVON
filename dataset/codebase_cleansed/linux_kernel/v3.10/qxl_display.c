static void qxl_crtc_set_to_mode(struct qxl_device *qdev,
struct drm_connector *connector,
struct qxl_head *head)
{
struct drm_device *dev = connector->dev;
struct drm_display_mode *mode, *t;
int width = head->width;
int height = head->height;
if (width < 320 || height < 240) {
qxl_io_log(qdev, "%s: bad head: %dx%d", width, height);
width = 1024;
height = 768;
}
if (width * height * 4 > 16*1024*1024) {
width = 1024;
height = 768;
}
list_for_each_entry_safe(mode, t, &connector->probed_modes, head)
drm_mode_remove(connector, mode);
mode = drm_cvt_mode(dev, width, height, 60, false, false, false);
mode->type |= DRM_MODE_TYPE_PREFERRED;
mode->status = MODE_OK;
drm_mode_probed_add(connector, mode);
qxl_io_log(qdev, "%s: %d x %d\n", __func__, width, height);
}
void qxl_crtc_set_from_monitors_config(struct qxl_device *qdev)
{
struct drm_connector *connector;
int i;
struct drm_device *dev = qdev->ddev;
i = 0;
qxl_io_log(qdev, "%s: %d, %d\n", __func__,
dev->mode_config.num_connector,
qdev->monitors_config->count);
list_for_each_entry(connector, &dev->mode_config.connector_list, head) {
if (i > qdev->monitors_config->count) {
continue;
}
qxl_crtc_set_to_mode(qdev, connector,
&qdev->monitors_config->heads[i]);
++i;
}
}
void qxl_alloc_client_monitors_config(struct qxl_device *qdev, unsigned count)
{
if (qdev->client_monitors_config &&
count > qdev->client_monitors_config->count) {
kfree(qdev->client_monitors_config);
qdev->client_monitors_config = NULL;
}
if (!qdev->client_monitors_config) {
qdev->client_monitors_config = kzalloc(
sizeof(struct qxl_monitors_config) +
sizeof(struct qxl_head) * count, GFP_KERNEL);
if (!qdev->client_monitors_config) {
qxl_io_log(qdev,
"%s: allocation failure for %u heads\n",
__func__, count);
return;
}
}
qdev->client_monitors_config->count = count;
}
static int qxl_display_copy_rom_client_monitors_config(struct qxl_device *qdev)
{
int i;
int num_monitors;
uint32_t crc;
BUG_ON(!qdev->monitors_config);
num_monitors = qdev->rom->client_monitors_config.count;
crc = crc32(0, (const uint8_t *)&qdev->rom->client_monitors_config,
sizeof(qdev->rom->client_monitors_config));
if (crc != qdev->rom->client_monitors_config_crc) {
qxl_io_log(qdev, "crc mismatch: have %X (%d) != %X\n", crc,
sizeof(qdev->rom->client_monitors_config),
qdev->rom->client_monitors_config_crc);
return 1;
}
if (num_monitors > qdev->monitors_config->max_allowed) {
DRM_INFO("client monitors list will be truncated: %d < %d\n",
qdev->monitors_config->max_allowed, num_monitors);
num_monitors = qdev->monitors_config->max_allowed;
} else {
num_monitors = qdev->rom->client_monitors_config.count;
}
qxl_alloc_client_monitors_config(qdev, num_monitors);
qdev->client_monitors_config->max_allowed =
qdev->monitors_config->max_allowed;
for (i = 0 ; i < qdev->client_monitors_config->count ; ++i) {
struct qxl_urect *c_rect =
&qdev->rom->client_monitors_config.heads[i];
struct qxl_head *client_head =
&qdev->client_monitors_config->heads[i];
struct qxl_head *head = &qdev->monitors_config->heads[i];
client_head->x = head->x = c_rect->left;
client_head->y = head->y = c_rect->top;
client_head->width = head->width =
c_rect->right - c_rect->left;
client_head->height = head->height =
c_rect->bottom - c_rect->top;
client_head->surface_id = head->surface_id = 0;
client_head->id = head->id = i;
client_head->flags = head->flags = 0;
QXL_DEBUG(qdev, "read %dx%d+%d+%d\n", head->width, head->height,
head->x, head->y);
}
return 0;
}
void qxl_display_read_client_monitors_config(struct qxl_device *qdev)
{
while (qxl_display_copy_rom_client_monitors_config(qdev)) {
qxl_io_log(qdev, "failed crc check for client_monitors_config,"
" retrying\n");
}
qxl_crtc_set_from_monitors_config(qdev);
qxl_io_log(qdev, "calling drm_sysfs_hotplug_event\n");
drm_sysfs_hotplug_event(qdev->ddev);
}
static int qxl_add_monitors_config_modes(struct drm_connector *connector)
{
struct drm_device *dev = connector->dev;
struct qxl_device *qdev = dev->dev_private;
struct qxl_output *output = drm_connector_to_qxl_output(connector);
int h = output->index;
struct drm_display_mode *mode = NULL;
struct qxl_head *head;
if (!qdev->monitors_config)
return 0;
head = &qdev->monitors_config->heads[h];
mode = drm_cvt_mode(dev, head->width, head->height, 60, false, false,
false);
mode->type |= DRM_MODE_TYPE_PREFERRED;
drm_mode_probed_add(connector, mode);
return 1;
}
static int qxl_add_common_modes(struct drm_connector *connector)
{
struct drm_device *dev = connector->dev;
struct drm_display_mode *mode = NULL;
int i;
struct mode_size {
int w;
int h;
} common_modes[] = {
{ 640, 480},
{ 720, 480},
{ 800, 600},
{ 848, 480},
{1024, 768},
{1152, 768},
{1280, 720},
{1280, 800},
{1280, 854},
{1280, 960},
{1280, 1024},
{1440, 900},
{1400, 1050},
{1680, 1050},
{1600, 1200},
{1920, 1080},
{1920, 1200}
};
for (i = 0; i < ARRAY_SIZE(common_modes); i++) {
if (common_modes[i].w < 320 || common_modes[i].h < 200)
continue;
mode = drm_cvt_mode(dev, common_modes[i].w, common_modes[i].h,
60, false, false, false);
if (common_modes[i].w == 1024 && common_modes[i].h == 768)
mode->type |= DRM_MODE_TYPE_PREFERRED;
drm_mode_probed_add(connector, mode);
}
return i - 1;
}
static void qxl_crtc_gamma_set(struct drm_crtc *crtc, u16 *red, u16 *green,
u16 *blue, uint32_t start, uint32_t size)
{
}
static void qxl_crtc_destroy(struct drm_crtc *crtc)
{
struct qxl_crtc *qxl_crtc = to_qxl_crtc(crtc);
drm_crtc_cleanup(crtc);
kfree(qxl_crtc);
}
static void
qxl_hide_cursor(struct qxl_device *qdev)
{
struct qxl_release *release;
struct qxl_cursor_cmd *cmd;
int ret;
ret = qxl_alloc_release_reserved(qdev, sizeof(*cmd), QXL_RELEASE_CURSOR_CMD,
&release, NULL);
cmd = (struct qxl_cursor_cmd *)qxl_release_map(qdev, release);
cmd->type = QXL_CURSOR_HIDE;
qxl_release_unmap(qdev, release, &cmd->release_info);
qxl_fence_releaseable(qdev, release);
qxl_push_cursor_ring_release(qdev, release, QXL_CMD_CURSOR, false);
qxl_release_unreserve(qdev, release);
}
static int qxl_crtc_cursor_set(struct drm_crtc *crtc,
struct drm_file *file_priv,
uint32_t handle,
uint32_t width,
uint32_t height)
{
struct drm_device *dev = crtc->dev;
struct qxl_device *qdev = dev->dev_private;
struct qxl_crtc *qcrtc = to_qxl_crtc(crtc);
struct drm_gem_object *obj;
struct qxl_cursor *cursor;
struct qxl_cursor_cmd *cmd;
struct qxl_bo *cursor_bo, *user_bo;
struct qxl_release *release;
void *user_ptr;
int size = 64*64*4;
int ret = 0;
if (!handle) {
qxl_hide_cursor(qdev);
return 0;
}
obj = drm_gem_object_lookup(crtc->dev, file_priv, handle);
if (!obj) {
DRM_ERROR("cannot find cursor object\n");
return -ENOENT;
}
user_bo = gem_to_qxl_bo(obj);
ret = qxl_bo_reserve(user_bo, false);
if (ret)
goto out_unref;
ret = qxl_bo_pin(user_bo, QXL_GEM_DOMAIN_CPU, NULL);
if (ret)
goto out_unreserve;
ret = qxl_bo_kmap(user_bo, &user_ptr);
if (ret)
goto out_unpin;
ret = qxl_alloc_release_reserved(qdev, sizeof(*cmd),
QXL_RELEASE_CURSOR_CMD,
&release, NULL);
if (ret)
goto out_kunmap;
ret = qxl_alloc_bo_reserved(qdev, sizeof(struct qxl_cursor) + size,
&cursor_bo);
if (ret)
goto out_free_release;
ret = qxl_bo_kmap(cursor_bo, (void **)&cursor);
if (ret)
goto out_free_bo;
cursor->header.unique = 0;
cursor->header.type = SPICE_CURSOR_TYPE_ALPHA;
cursor->header.width = 64;
cursor->header.height = 64;
cursor->header.hot_spot_x = 0;
cursor->header.hot_spot_y = 0;
cursor->data_size = size;
cursor->chunk.next_chunk = 0;
cursor->chunk.prev_chunk = 0;
cursor->chunk.data_size = size;
memcpy(cursor->chunk.data, user_ptr, size);
qxl_bo_kunmap(cursor_bo);
qxl_bo_kunmap(user_bo);
qxl_bo_unpin(user_bo);
qxl_bo_unreserve(user_bo);
drm_gem_object_unreference_unlocked(obj);
cmd = (struct qxl_cursor_cmd *)qxl_release_map(qdev, release);
cmd->type = QXL_CURSOR_SET;
cmd->u.set.position.x = qcrtc->cur_x;
cmd->u.set.position.y = qcrtc->cur_y;
cmd->u.set.shape = qxl_bo_physical_address(qdev, cursor_bo, 0);
qxl_release_add_res(qdev, release, cursor_bo);
cmd->u.set.visible = 1;
qxl_release_unmap(qdev, release, &cmd->release_info);
qxl_fence_releaseable(qdev, release);
qxl_push_cursor_ring_release(qdev, release, QXL_CMD_CURSOR, false);
qxl_release_unreserve(qdev, release);
qxl_bo_unreserve(cursor_bo);
qxl_bo_unref(&cursor_bo);
return ret;
out_free_bo:
qxl_bo_unref(&cursor_bo);
out_free_release:
qxl_release_unreserve(qdev, release);
qxl_release_free(qdev, release);
out_kunmap:
qxl_bo_kunmap(user_bo);
out_unpin:
qxl_bo_unpin(user_bo);
out_unreserve:
qxl_bo_unreserve(user_bo);
out_unref:
drm_gem_object_unreference_unlocked(obj);
return ret;
}
static int qxl_crtc_cursor_move(struct drm_crtc *crtc,
int x, int y)
{
struct drm_device *dev = crtc->dev;
struct qxl_device *qdev = dev->dev_private;
struct qxl_crtc *qcrtc = to_qxl_crtc(crtc);
struct qxl_release *release;
struct qxl_cursor_cmd *cmd;
int ret;
ret = qxl_alloc_release_reserved(qdev, sizeof(*cmd), QXL_RELEASE_CURSOR_CMD,
&release, NULL);
qcrtc->cur_x = x;
qcrtc->cur_y = y;
cmd = (struct qxl_cursor_cmd *)qxl_release_map(qdev, release);
cmd->type = QXL_CURSOR_MOVE;
cmd->u.position.x = qcrtc->cur_x;
cmd->u.position.y = qcrtc->cur_y;
qxl_release_unmap(qdev, release, &cmd->release_info);
qxl_fence_releaseable(qdev, release);
qxl_push_cursor_ring_release(qdev, release, QXL_CMD_CURSOR, false);
qxl_release_unreserve(qdev, release);
return 0;
}
static void qxl_user_framebuffer_destroy(struct drm_framebuffer *fb)
{
struct qxl_framebuffer *qxl_fb = to_qxl_framebuffer(fb);
if (qxl_fb->obj)
drm_gem_object_unreference_unlocked(qxl_fb->obj);
drm_framebuffer_cleanup(fb);
kfree(qxl_fb);
}
static int qxl_framebuffer_surface_dirty(struct drm_framebuffer *fb,
struct drm_file *file_priv,
unsigned flags, unsigned color,
struct drm_clip_rect *clips,
unsigned num_clips)
{
struct qxl_framebuffer *qxl_fb = to_qxl_framebuffer(fb);
struct qxl_device *qdev = qxl_fb->base.dev->dev_private;
struct drm_clip_rect norect;
struct qxl_bo *qobj;
int inc = 1;
qobj = gem_to_qxl_bo(qxl_fb->obj);
if (!qobj->is_primary)
return 0;
if (!num_clips) {
num_clips = 1;
clips = &norect;
norect.x1 = norect.y1 = 0;
norect.x2 = fb->width;
norect.y2 = fb->height;
} else if (flags & DRM_MODE_FB_DIRTY_ANNOTATE_COPY) {
num_clips /= 2;
inc = 2;
}
qxl_draw_dirty_fb(qdev, qxl_fb, qobj, flags, color,
clips, num_clips, inc);
return 0;
}
int
qxl_framebuffer_init(struct drm_device *dev,
struct qxl_framebuffer *qfb,
struct drm_mode_fb_cmd2 *mode_cmd,
struct drm_gem_object *obj)
{
int ret;
qfb->obj = obj;
ret = drm_framebuffer_init(dev, &qfb->base, &qxl_fb_funcs);
if (ret) {
qfb->obj = NULL;
return ret;
}
drm_helper_mode_fill_fb_struct(&qfb->base, mode_cmd);
return 0;
}
static void qxl_crtc_dpms(struct drm_crtc *crtc, int mode)
{
}
static bool qxl_crtc_mode_fixup(struct drm_crtc *crtc,
const struct drm_display_mode *mode,
struct drm_display_mode *adjusted_mode)
{
struct drm_device *dev = crtc->dev;
struct qxl_device *qdev = dev->dev_private;
qxl_io_log(qdev, "%s: (%d,%d) => (%d,%d)\n",
__func__,
mode->hdisplay, mode->vdisplay,
adjusted_mode->hdisplay,
adjusted_mode->vdisplay);
return true;
}
void
qxl_send_monitors_config(struct qxl_device *qdev)
{
int i;
BUG_ON(!qdev->ram_header->monitors_config);
if (qdev->monitors_config->count == 0) {
qxl_io_log(qdev, "%s: 0 monitors??\n", __func__);
return;
}
for (i = 0 ; i < qdev->monitors_config->count ; ++i) {
struct qxl_head *head = &qdev->monitors_config->heads[i];
if (head->y > 8192 || head->y < head->x ||
head->width > 8192 || head->height > 8192) {
DRM_ERROR("head %d wrong: %dx%d+%d+%d\n",
i, head->width, head->height,
head->x, head->y);
return;
}
}
qxl_io_monitors_config(qdev);
}
static void qxl_monitors_config_set_single(struct qxl_device *qdev,
unsigned x, unsigned y,
unsigned width, unsigned height)
{
DRM_DEBUG("%dx%d+%d+%d\n", width, height, x, y);
qdev->monitors_config->count = 1;
qdev->monitors_config->heads[0].x = x;
qdev->monitors_config->heads[0].y = y;
qdev->monitors_config->heads[0].width = width;
qdev->monitors_config->heads[0].height = height;
}
static int qxl_crtc_mode_set(struct drm_crtc *crtc,
struct drm_display_mode *mode,
struct drm_display_mode *adjusted_mode,
int x, int y,
struct drm_framebuffer *old_fb)
{
struct drm_device *dev = crtc->dev;
struct qxl_device *qdev = dev->dev_private;
struct qxl_mode *m = (void *)mode->private;
struct qxl_framebuffer *qfb;
struct qxl_bo *bo, *old_bo = NULL;
uint32_t width, height, base_offset;
bool recreate_primary = false;
int ret;
if (!crtc->fb) {
DRM_DEBUG_KMS("No FB bound\n");
return 0;
}
if (old_fb) {
qfb = to_qxl_framebuffer(old_fb);
old_bo = gem_to_qxl_bo(qfb->obj);
}
qfb = to_qxl_framebuffer(crtc->fb);
bo = gem_to_qxl_bo(qfb->obj);
if (!m)
DRM_DEBUG("%dx%d: not a native mode\n", x, y);
else
DRM_DEBUG("%dx%d: qxl id %d\n",
mode->hdisplay, mode->vdisplay, m->id);
DRM_DEBUG("+%d+%d (%d,%d) => (%d,%d)\n",
x, y,
mode->hdisplay, mode->vdisplay,
adjusted_mode->hdisplay,
adjusted_mode->vdisplay);
recreate_primary = true;
width = mode->hdisplay;
height = mode->vdisplay;
base_offset = 0;
ret = qxl_bo_reserve(bo, false);
if (ret != 0)
return ret;
ret = qxl_bo_pin(bo, bo->type, NULL);
if (ret != 0) {
qxl_bo_unreserve(bo);
return -EINVAL;
}
qxl_bo_unreserve(bo);
if (recreate_primary) {
qxl_io_destroy_primary(qdev);
qxl_io_log(qdev,
"recreate primary: %dx%d (was %dx%d,%d,%d)\n",
width, height, bo->surf.width,
bo->surf.height, bo->surf.stride, bo->surf.format);
qxl_io_create_primary(qdev, width, height, base_offset, bo);
bo->is_primary = true;
}
if (old_bo && old_bo != bo) {
old_bo->is_primary = false;
ret = qxl_bo_reserve(old_bo, false);
qxl_bo_unpin(old_bo);
qxl_bo_unreserve(old_bo);
}
if (qdev->monitors_config->count == 0) {
qxl_monitors_config_set_single(qdev, x, y,
mode->hdisplay,
mode->vdisplay);
}
return 0;
}
static void qxl_crtc_prepare(struct drm_crtc *crtc)
{
DRM_DEBUG("current: %dx%d+%d+%d (%d).\n",
crtc->mode.hdisplay, crtc->mode.vdisplay,
crtc->x, crtc->y, crtc->enabled);
}
static void qxl_crtc_commit(struct drm_crtc *crtc)
{
DRM_DEBUG("\n");
}
static void qxl_crtc_load_lut(struct drm_crtc *crtc)
{
DRM_DEBUG("\n");
}
static int qdev_crtc_init(struct drm_device *dev, int num_crtc)
{
struct qxl_crtc *qxl_crtc;
qxl_crtc = kzalloc(sizeof(struct qxl_crtc), GFP_KERNEL);
if (!qxl_crtc)
return -ENOMEM;
drm_crtc_init(dev, &qxl_crtc->base, &qxl_crtc_funcs);
drm_mode_crtc_set_gamma_size(&qxl_crtc->base, 256);
drm_crtc_helper_add(&qxl_crtc->base, &qxl_crtc_helper_funcs);
return 0;
}
static void qxl_enc_dpms(struct drm_encoder *encoder, int mode)
{
DRM_DEBUG("\n");
}
static bool qxl_enc_mode_fixup(struct drm_encoder *encoder,
const struct drm_display_mode *mode,
struct drm_display_mode *adjusted_mode)
{
DRM_DEBUG("\n");
return true;
}
static void qxl_enc_prepare(struct drm_encoder *encoder)
{
DRM_DEBUG("\n");
}
static void qxl_write_monitors_config_for_encoder(struct qxl_device *qdev,
struct drm_encoder *encoder)
{
int i;
struct qxl_head *head;
struct drm_display_mode *mode;
BUG_ON(!encoder);
for (i = 0 ; (encoder->possible_crtcs != (1 << i)) && i < 32; ++i)
;
if (encoder->possible_crtcs != (1 << i)) {
DRM_ERROR("encoder has wrong possible_crtcs: %x\n",
encoder->possible_crtcs);
return;
}
if (!qdev->monitors_config ||
qdev->monitors_config->max_allowed <= i) {
DRM_ERROR(
"head number too large or missing monitors config: %p, %d",
qdev->monitors_config,
qdev->monitors_config ?
qdev->monitors_config->max_allowed : -1);
return;
}
if (!encoder->crtc) {
DRM_ERROR("missing crtc on encoder %p\n", encoder);
return;
}
if (i != 0)
DRM_DEBUG("missing for multiple monitors: no head holes\n");
head = &qdev->monitors_config->heads[i];
head->id = i;
head->surface_id = 0;
if (encoder->crtc->enabled) {
mode = &encoder->crtc->mode;
head->width = mode->hdisplay;
head->height = mode->vdisplay;
head->x = encoder->crtc->x;
head->y = encoder->crtc->y;
if (qdev->monitors_config->count < i + 1)
qdev->monitors_config->count = i + 1;
} else {
head->width = 0;
head->height = 0;
head->x = 0;
head->y = 0;
}
DRM_DEBUG("setting head %d to +%d+%d %dx%d\n",
i, head->x, head->y, head->width, head->height);
head->flags = 0;
qxl_send_monitors_config(qdev);
}
static void qxl_enc_commit(struct drm_encoder *encoder)
{
struct qxl_device *qdev = encoder->dev->dev_private;
qxl_write_monitors_config_for_encoder(qdev, encoder);
DRM_DEBUG("\n");
}
static void qxl_enc_mode_set(struct drm_encoder *encoder,
struct drm_display_mode *mode,
struct drm_display_mode *adjusted_mode)
{
DRM_DEBUG("\n");
}
static int qxl_conn_get_modes(struct drm_connector *connector)
{
int ret = 0;
struct qxl_device *qdev = connector->dev->dev_private;
DRM_DEBUG_KMS("monitors_config=%p\n", qdev->monitors_config);
if (qdev->monitors_config && qdev->monitors_config->count) {
ret = qxl_add_monitors_config_modes(connector);
if (ret < 0)
return ret;
}
ret += qxl_add_common_modes(connector);
return ret;
}
static int qxl_conn_mode_valid(struct drm_connector *connector,
struct drm_display_mode *mode)
{
DRM_DEBUG("%s: %dx%d status=%d\n", mode->name, mode->hdisplay,
mode->vdisplay, mode->status);
return MODE_OK;
}
static struct drm_encoder *qxl_best_encoder(struct drm_connector *connector)
{
struct qxl_output *qxl_output =
drm_connector_to_qxl_output(connector);
DRM_DEBUG("\n");
return &qxl_output->enc;
}
static void qxl_conn_save(struct drm_connector *connector)
{
DRM_DEBUG("\n");
}
static void qxl_conn_restore(struct drm_connector *connector)
{
DRM_DEBUG("\n");
}
static enum drm_connector_status qxl_conn_detect(
struct drm_connector *connector,
bool force)
{
struct qxl_output *output =
drm_connector_to_qxl_output(connector);
struct drm_device *ddev = connector->dev;
struct qxl_device *qdev = ddev->dev_private;
int connected;
connected = (output->index == 0) ||
(qdev->monitors_config &&
qdev->monitors_config->count > output->index);
DRM_DEBUG("\n");
return connected ? connector_status_connected
: connector_status_disconnected;
}
static int qxl_conn_set_property(struct drm_connector *connector,
struct drm_property *property,
uint64_t value)
{
DRM_DEBUG("\n");
return 0;
}
static void qxl_conn_destroy(struct drm_connector *connector)
{
struct qxl_output *qxl_output =
drm_connector_to_qxl_output(connector);
drm_sysfs_connector_remove(connector);
drm_connector_cleanup(connector);
kfree(qxl_output);
}
static void qxl_enc_destroy(struct drm_encoder *encoder)
{
drm_encoder_cleanup(encoder);
}
static int qdev_output_init(struct drm_device *dev, int num_output)
{
struct qxl_output *qxl_output;
struct drm_connector *connector;
struct drm_encoder *encoder;
qxl_output = kzalloc(sizeof(struct qxl_output), GFP_KERNEL);
if (!qxl_output)
return -ENOMEM;
qxl_output->index = num_output;
connector = &qxl_output->base;
encoder = &qxl_output->enc;
drm_connector_init(dev, &qxl_output->base,
&qxl_connector_funcs, DRM_MODE_CONNECTOR_VIRTUAL);
drm_encoder_init(dev, &qxl_output->enc, &qxl_enc_funcs,
DRM_MODE_ENCODER_VIRTUAL);
encoder->possible_crtcs = 1 << num_output;
drm_mode_connector_attach_encoder(&qxl_output->base,
&qxl_output->enc);
drm_encoder_helper_add(encoder, &qxl_enc_helper_funcs);
drm_connector_helper_add(connector, &qxl_connector_helper_funcs);
drm_sysfs_connector_add(connector);
return 0;
}
static struct drm_framebuffer *
qxl_user_framebuffer_create(struct drm_device *dev,
struct drm_file *file_priv,
struct drm_mode_fb_cmd2 *mode_cmd)
{
struct drm_gem_object *obj;
struct qxl_framebuffer *qxl_fb;
int ret;
obj = drm_gem_object_lookup(dev, file_priv, mode_cmd->handles[0]);
qxl_fb = kzalloc(sizeof(*qxl_fb), GFP_KERNEL);
if (qxl_fb == NULL)
return NULL;
ret = qxl_framebuffer_init(dev, qxl_fb, mode_cmd, obj);
if (ret) {
kfree(qxl_fb);
drm_gem_object_unreference_unlocked(obj);
return NULL;
}
return &qxl_fb->base;
}
int qxl_modeset_init(struct qxl_device *qdev)
{
int i;
int ret;
struct drm_gem_object *gobj;
int max_allowed = QXL_NUM_OUTPUTS;
int monitors_config_size = sizeof(struct qxl_monitors_config) +
max_allowed * sizeof(struct qxl_head);
drm_mode_config_init(qdev->ddev);
ret = qxl_gem_object_create(qdev, monitors_config_size, 0,
QXL_GEM_DOMAIN_VRAM,
false, false, NULL, &gobj);
if (ret) {
DRM_ERROR("%s: failed to create gem ret=%d\n", __func__, ret);
return -ENOMEM;
}
qdev->monitors_config_bo = gem_to_qxl_bo(gobj);
qxl_bo_kmap(qdev->monitors_config_bo, NULL);
qdev->monitors_config = qdev->monitors_config_bo->kptr;
qdev->ram_header->monitors_config =
qxl_bo_physical_address(qdev, qdev->monitors_config_bo, 0);
memset(qdev->monitors_config, 0, monitors_config_size);
qdev->monitors_config->max_allowed = max_allowed;
qdev->ddev->mode_config.funcs = (void *)&qxl_mode_funcs;
qdev->ddev->mode_config.min_width = 320;
qdev->ddev->mode_config.min_height = 200;
qdev->ddev->mode_config.max_width = 8192;
qdev->ddev->mode_config.max_height = 8192;
qdev->ddev->mode_config.fb_base = qdev->vram_base;
for (i = 0 ; i < QXL_NUM_OUTPUTS; ++i) {
qdev_crtc_init(qdev->ddev, i);
qdev_output_init(qdev->ddev, i);
}
qdev->mode_info.mode_config_initialized = true;
qxl_fbdev_init(qdev);
return 0;
}
void qxl_modeset_fini(struct qxl_device *qdev)
{
qxl_fbdev_fini(qdev);
if (qdev->mode_info.mode_config_initialized) {
drm_mode_config_cleanup(qdev->ddev);
qdev->mode_info.mode_config_initialized = false;
}
}
