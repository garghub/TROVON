static bool vidi_display_is_connected(struct device *dev)
{
struct vidi_context *ctx = get_vidi_context(dev);
DRM_DEBUG_KMS("%s\n", __FILE__);
return ctx->connected ? true : false;
}
static struct edid *vidi_get_edid(struct device *dev,
struct drm_connector *connector)
{
struct vidi_context *ctx = get_vidi_context(dev);
struct edid *edid;
int edid_len;
DRM_DEBUG_KMS("%s\n", __FILE__);
if (!ctx->raw_edid) {
DRM_DEBUG_KMS("raw_edid is null.\n");
return ERR_PTR(-EFAULT);
}
edid_len = (1 + ctx->raw_edid->extensions) * EDID_LENGTH;
edid = kzalloc(edid_len, GFP_KERNEL);
if (!edid) {
DRM_DEBUG_KMS("failed to allocate edid\n");
return ERR_PTR(-ENOMEM);
}
memcpy(edid, ctx->raw_edid, edid_len);
return edid;
}
static void *vidi_get_panel(struct device *dev)
{
DRM_DEBUG_KMS("%s\n", __FILE__);
return NULL;
}
static int vidi_check_timing(struct device *dev, void *timing)
{
DRM_DEBUG_KMS("%s\n", __FILE__);
return 0;
}
static int vidi_display_power_on(struct device *dev, int mode)
{
DRM_DEBUG_KMS("%s\n", __FILE__);
return 0;
}
static void vidi_dpms(struct device *subdrv_dev, int mode)
{
struct vidi_context *ctx = get_vidi_context(subdrv_dev);
DRM_DEBUG_KMS("%s, %d\n", __FILE__, mode);
mutex_lock(&ctx->lock);
switch (mode) {
case DRM_MODE_DPMS_ON:
break;
case DRM_MODE_DPMS_STANDBY:
case DRM_MODE_DPMS_SUSPEND:
case DRM_MODE_DPMS_OFF:
break;
default:
DRM_DEBUG_KMS("unspecified mode %d\n", mode);
break;
}
mutex_unlock(&ctx->lock);
}
static void vidi_apply(struct device *subdrv_dev)
{
struct vidi_context *ctx = get_vidi_context(subdrv_dev);
struct exynos_drm_manager *mgr = ctx->subdrv.manager;
struct exynos_drm_manager_ops *mgr_ops = mgr->ops;
struct exynos_drm_overlay_ops *ovl_ops = mgr->overlay_ops;
struct vidi_win_data *win_data;
int i;
DRM_DEBUG_KMS("%s\n", __FILE__);
for (i = 0; i < WINDOWS_NR; i++) {
win_data = &ctx->win_data[i];
if (win_data->enabled && (ovl_ops && ovl_ops->commit))
ovl_ops->commit(subdrv_dev, i);
}
if (mgr_ops && mgr_ops->commit)
mgr_ops->commit(subdrv_dev);
}
static void vidi_commit(struct device *dev)
{
struct vidi_context *ctx = get_vidi_context(dev);
DRM_DEBUG_KMS("%s\n", __FILE__);
if (ctx->suspended)
return;
}
static int vidi_enable_vblank(struct device *dev)
{
struct vidi_context *ctx = get_vidi_context(dev);
DRM_DEBUG_KMS("%s\n", __FILE__);
if (ctx->suspended)
return -EPERM;
if (!test_and_set_bit(0, &ctx->irq_flags))
ctx->vblank_on = true;
ctx->direct_vblank = true;
schedule_work(&ctx->work);
return 0;
}
static void vidi_disable_vblank(struct device *dev)
{
struct vidi_context *ctx = get_vidi_context(dev);
DRM_DEBUG_KMS("%s\n", __FILE__);
if (ctx->suspended)
return;
if (test_and_clear_bit(0, &ctx->irq_flags))
ctx->vblank_on = false;
}
static void vidi_win_mode_set(struct device *dev,
struct exynos_drm_overlay *overlay)
{
struct vidi_context *ctx = get_vidi_context(dev);
struct vidi_win_data *win_data;
int win;
unsigned long offset;
DRM_DEBUG_KMS("%s\n", __FILE__);
if (!overlay) {
dev_err(dev, "overlay is NULL\n");
return;
}
win = overlay->zpos;
if (win == DEFAULT_ZPOS)
win = ctx->default_win;
if (win < 0 || win > WINDOWS_NR)
return;
offset = overlay->fb_x * (overlay->bpp >> 3);
offset += overlay->fb_y * overlay->pitch;
DRM_DEBUG_KMS("offset = 0x%lx, pitch = %x\n", offset, overlay->pitch);
win_data = &ctx->win_data[win];
win_data->offset_x = overlay->crtc_x;
win_data->offset_y = overlay->crtc_y;
win_data->ovl_width = overlay->crtc_width;
win_data->ovl_height = overlay->crtc_height;
win_data->fb_width = overlay->fb_width;
win_data->fb_height = overlay->fb_height;
win_data->dma_addr = overlay->dma_addr[0] + offset;
win_data->bpp = overlay->bpp;
win_data->buf_offsize = (overlay->fb_width - overlay->crtc_width) *
(overlay->bpp >> 3);
win_data->line_size = overlay->crtc_width * (overlay->bpp >> 3);
DRM_DEBUG_KMS("offset_x = %d, offset_y = %d\n",
win_data->offset_x, win_data->offset_y);
DRM_DEBUG_KMS("ovl_width = %d, ovl_height = %d\n",
win_data->ovl_width, win_data->ovl_height);
DRM_DEBUG_KMS("paddr = 0x%lx\n", (unsigned long)win_data->dma_addr);
DRM_DEBUG_KMS("fb_width = %d, crtc_width = %d\n",
overlay->fb_width, overlay->crtc_width);
}
static void vidi_win_commit(struct device *dev, int zpos)
{
struct vidi_context *ctx = get_vidi_context(dev);
struct vidi_win_data *win_data;
int win = zpos;
DRM_DEBUG_KMS("%s\n", __FILE__);
if (ctx->suspended)
return;
if (win == DEFAULT_ZPOS)
win = ctx->default_win;
if (win < 0 || win > WINDOWS_NR)
return;
win_data = &ctx->win_data[win];
win_data->enabled = true;
DRM_DEBUG_KMS("dma_addr = 0x%x\n", win_data->dma_addr);
if (ctx->vblank_on)
schedule_work(&ctx->work);
}
static void vidi_win_disable(struct device *dev, int zpos)
{
struct vidi_context *ctx = get_vidi_context(dev);
struct vidi_win_data *win_data;
int win = zpos;
DRM_DEBUG_KMS("%s\n", __FILE__);
if (win == DEFAULT_ZPOS)
win = ctx->default_win;
if (win < 0 || win > WINDOWS_NR)
return;
win_data = &ctx->win_data[win];
win_data->enabled = false;
}
static void vidi_fake_vblank_handler(struct work_struct *work)
{
struct vidi_context *ctx = container_of(work, struct vidi_context,
work);
struct exynos_drm_subdrv *subdrv = &ctx->subdrv;
struct exynos_drm_manager *manager = subdrv->manager;
if (manager->pipe < 0)
return;
usleep_range(16000, 20000);
mutex_lock(&ctx->lock);
if (ctx->direct_vblank) {
drm_handle_vblank(subdrv->drm_dev, manager->pipe);
ctx->direct_vblank = false;
mutex_unlock(&ctx->lock);
return;
}
mutex_unlock(&ctx->lock);
exynos_drm_crtc_finish_pageflip(subdrv->drm_dev, manager->pipe);
}
static int vidi_subdrv_probe(struct drm_device *drm_dev, struct device *dev)
{
DRM_DEBUG_KMS("%s\n", __FILE__);
drm_dev->irq_enabled = 1;
drm_dev->vblank_disable_allowed = 1;
return 0;
}
static void vidi_subdrv_remove(struct drm_device *drm_dev, struct device *dev)
{
DRM_DEBUG_KMS("%s\n", __FILE__);
}
static int vidi_power_on(struct vidi_context *ctx, bool enable)
{
struct exynos_drm_subdrv *subdrv = &ctx->subdrv;
struct device *dev = subdrv->dev;
DRM_DEBUG_KMS("%s\n", __FILE__);
if (enable != false && enable != true)
return -EINVAL;
if (enable) {
ctx->suspended = false;
if (test_and_clear_bit(0, &ctx->irq_flags))
vidi_enable_vblank(dev);
vidi_apply(dev);
} else {
ctx->suspended = true;
}
return 0;
}
static int vidi_show_connection(struct device *dev,
struct device_attribute *attr, char *buf)
{
int rc;
struct vidi_context *ctx = get_vidi_context(dev);
mutex_lock(&ctx->lock);
rc = sprintf(buf, "%d\n", ctx->connected);
mutex_unlock(&ctx->lock);
return rc;
}
static int vidi_store_connection(struct device *dev,
struct device_attribute *attr,
const char *buf, size_t len)
{
struct vidi_context *ctx = get_vidi_context(dev);
int ret;
DRM_DEBUG_KMS("%s\n", __FILE__);
ret = kstrtoint(buf, 0, &ctx->connected);
if (ret)
return ret;
if (ctx->connected > 1)
return -EINVAL;
if (!ctx->raw_edid)
ctx->raw_edid = (struct edid *)fake_edid_info;
if (ctx->raw_edid != (struct edid *)fake_edid_info) {
DRM_DEBUG_KMS("edid data is not fake data.\n");
return -EINVAL;
}
DRM_DEBUG_KMS("requested connection.\n");
drm_helper_hpd_irq_event(ctx->subdrv.drm_dev);
return len;
}
int vidi_connection_ioctl(struct drm_device *drm_dev, void *data,
struct drm_file *file_priv)
{
struct vidi_context *ctx = NULL;
struct drm_encoder *encoder;
struct exynos_drm_manager *manager;
struct exynos_drm_display_ops *display_ops;
struct drm_exynos_vidi_connection *vidi = data;
int edid_len;
DRM_DEBUG_KMS("%s\n", __FILE__);
if (!vidi) {
DRM_DEBUG_KMS("user data for vidi is null.\n");
return -EINVAL;
}
if (vidi->connection > 1) {
DRM_DEBUG_KMS("connection should be 0 or 1.\n");
return -EINVAL;
}
list_for_each_entry(encoder, &drm_dev->mode_config.encoder_list,
head) {
manager = exynos_drm_get_manager(encoder);
display_ops = manager->display_ops;
if (display_ops->type == EXYNOS_DISPLAY_TYPE_VIDI) {
ctx = get_vidi_context(manager->dev);
break;
}
}
if (!ctx) {
DRM_DEBUG_KMS("not found virtual device type encoder.\n");
return -EINVAL;
}
if (ctx->connected == vidi->connection) {
DRM_DEBUG_KMS("same connection request.\n");
return -EINVAL;
}
if (vidi->connection) {
struct edid *raw_edid = (struct edid *)(uint32_t)vidi->edid;
if (!drm_edid_is_valid(raw_edid)) {
DRM_DEBUG_KMS("edid data is invalid.\n");
return -EINVAL;
}
edid_len = (1 + raw_edid->extensions) * EDID_LENGTH;
ctx->raw_edid = kzalloc(edid_len, GFP_KERNEL);
if (!ctx->raw_edid) {
DRM_DEBUG_KMS("failed to allocate raw_edid.\n");
return -ENOMEM;
}
memcpy(ctx->raw_edid, raw_edid, edid_len);
} else {
if (ctx->raw_edid && ctx->raw_edid !=
(struct edid *)fake_edid_info) {
kfree(ctx->raw_edid);
ctx->raw_edid = NULL;
}
}
ctx->connected = vidi->connection;
drm_helper_hpd_irq_event(ctx->subdrv.drm_dev);
return 0;
}
static int vidi_probe(struct platform_device *pdev)
{
struct device *dev = &pdev->dev;
struct vidi_context *ctx;
struct exynos_drm_subdrv *subdrv;
int ret;
DRM_DEBUG_KMS("%s\n", __FILE__);
ctx = devm_kzalloc(&pdev->dev, sizeof(*ctx), GFP_KERNEL);
if (!ctx)
return -ENOMEM;
ctx->default_win = 0;
INIT_WORK(&ctx->work, vidi_fake_vblank_handler);
subdrv = &ctx->subdrv;
subdrv->dev = dev;
subdrv->manager = &vidi_manager;
subdrv->probe = vidi_subdrv_probe;
subdrv->remove = vidi_subdrv_remove;
mutex_init(&ctx->lock);
platform_set_drvdata(pdev, ctx);
ret = device_create_file(&pdev->dev, &dev_attr_connection);
if (ret < 0)
DRM_INFO("failed to create connection sysfs.\n");
exynos_drm_subdrv_register(subdrv);
return 0;
}
static int vidi_remove(struct platform_device *pdev)
{
struct vidi_context *ctx = platform_get_drvdata(pdev);
DRM_DEBUG_KMS("%s\n", __FILE__);
exynos_drm_subdrv_unregister(&ctx->subdrv);
if (ctx->raw_edid != (struct edid *)fake_edid_info) {
kfree(ctx->raw_edid);
ctx->raw_edid = NULL;
}
return 0;
}
static int vidi_suspend(struct device *dev)
{
struct vidi_context *ctx = get_vidi_context(dev);
return vidi_power_on(ctx, false);
}
static int vidi_resume(struct device *dev)
{
struct vidi_context *ctx = get_vidi_context(dev);
return vidi_power_on(ctx, true);
}
