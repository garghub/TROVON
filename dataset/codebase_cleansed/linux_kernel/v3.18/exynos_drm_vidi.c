static void vidi_apply(struct exynos_drm_manager *mgr)
{
struct vidi_context *ctx = mgr->ctx;
struct exynos_drm_manager_ops *mgr_ops = mgr->ops;
struct vidi_win_data *win_data;
int i;
for (i = 0; i < WINDOWS_NR; i++) {
win_data = &ctx->win_data[i];
if (win_data->enabled && (mgr_ops && mgr_ops->win_commit))
mgr_ops->win_commit(mgr, i);
}
if (mgr_ops && mgr_ops->commit)
mgr_ops->commit(mgr);
}
static void vidi_commit(struct exynos_drm_manager *mgr)
{
struct vidi_context *ctx = mgr->ctx;
if (ctx->suspended)
return;
}
static int vidi_enable_vblank(struct exynos_drm_manager *mgr)
{
struct vidi_context *ctx = mgr->ctx;
if (ctx->suspended)
return -EPERM;
if (!test_and_set_bit(0, &ctx->irq_flags))
ctx->vblank_on = true;
ctx->direct_vblank = true;
schedule_work(&ctx->work);
return 0;
}
static void vidi_disable_vblank(struct exynos_drm_manager *mgr)
{
struct vidi_context *ctx = mgr->ctx;
if (ctx->suspended)
return;
if (test_and_clear_bit(0, &ctx->irq_flags))
ctx->vblank_on = false;
}
static void vidi_win_mode_set(struct exynos_drm_manager *mgr,
struct exynos_drm_overlay *overlay)
{
struct vidi_context *ctx = mgr->ctx;
struct vidi_win_data *win_data;
int win;
unsigned long offset;
if (!overlay) {
DRM_ERROR("overlay is NULL\n");
return;
}
win = overlay->zpos;
if (win == DEFAULT_ZPOS)
win = ctx->default_win;
if (win < 0 || win >= WINDOWS_NR)
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
static void vidi_win_commit(struct exynos_drm_manager *mgr, int zpos)
{
struct vidi_context *ctx = mgr->ctx;
struct vidi_win_data *win_data;
int win = zpos;
if (ctx->suspended)
return;
if (win == DEFAULT_ZPOS)
win = ctx->default_win;
if (win < 0 || win >= WINDOWS_NR)
return;
win_data = &ctx->win_data[win];
win_data->enabled = true;
DRM_DEBUG_KMS("dma_addr = %pad\n", &win_data->dma_addr);
if (ctx->vblank_on)
schedule_work(&ctx->work);
}
static void vidi_win_disable(struct exynos_drm_manager *mgr, int zpos)
{
struct vidi_context *ctx = mgr->ctx;
struct vidi_win_data *win_data;
int win = zpos;
if (win == DEFAULT_ZPOS)
win = ctx->default_win;
if (win < 0 || win >= WINDOWS_NR)
return;
win_data = &ctx->win_data[win];
win_data->enabled = false;
}
static int vidi_power_on(struct exynos_drm_manager *mgr, bool enable)
{
struct vidi_context *ctx = mgr->ctx;
DRM_DEBUG_KMS("%s\n", __FILE__);
if (enable != false && enable != true)
return -EINVAL;
if (enable) {
ctx->suspended = false;
if (test_and_clear_bit(0, &ctx->irq_flags))
vidi_enable_vblank(mgr);
vidi_apply(mgr);
} else {
ctx->suspended = true;
}
return 0;
}
static void vidi_dpms(struct exynos_drm_manager *mgr, int mode)
{
struct vidi_context *ctx = mgr->ctx;
DRM_DEBUG_KMS("%d\n", mode);
mutex_lock(&ctx->lock);
switch (mode) {
case DRM_MODE_DPMS_ON:
vidi_power_on(mgr, true);
break;
case DRM_MODE_DPMS_STANDBY:
case DRM_MODE_DPMS_SUSPEND:
case DRM_MODE_DPMS_OFF:
vidi_power_on(mgr, false);
break;
default:
DRM_DEBUG_KMS("unspecified mode %d\n", mode);
break;
}
mutex_unlock(&ctx->lock);
}
static int vidi_mgr_initialize(struct exynos_drm_manager *mgr,
struct drm_device *drm_dev)
{
struct vidi_context *ctx = mgr->ctx;
struct exynos_drm_private *priv = drm_dev->dev_private;
mgr->drm_dev = ctx->drm_dev = drm_dev;
mgr->pipe = ctx->pipe = priv->pipe++;
return 0;
}
static void vidi_fake_vblank_handler(struct work_struct *work)
{
struct vidi_context *ctx = container_of(work, struct vidi_context,
work);
if (ctx->pipe < 0)
return;
usleep_range(16000, 20000);
mutex_lock(&ctx->lock);
if (ctx->direct_vblank) {
drm_handle_vblank(ctx->drm_dev, ctx->pipe);
ctx->direct_vblank = false;
mutex_unlock(&ctx->lock);
return;
}
mutex_unlock(&ctx->lock);
exynos_drm_crtc_finish_pageflip(ctx->drm_dev, ctx->pipe);
}
static int vidi_show_connection(struct device *dev,
struct device_attribute *attr, char *buf)
{
int rc;
struct exynos_drm_manager *mgr = get_vidi_mgr(dev);
struct vidi_context *ctx = mgr->ctx;
mutex_lock(&ctx->lock);
rc = sprintf(buf, "%d\n", ctx->connected);
mutex_unlock(&ctx->lock);
return rc;
}
static int vidi_store_connection(struct device *dev,
struct device_attribute *attr,
const char *buf, size_t len)
{
struct exynos_drm_manager *mgr = get_vidi_mgr(dev);
struct vidi_context *ctx = mgr->ctx;
int ret;
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
drm_helper_hpd_irq_event(ctx->drm_dev);
return len;
}
int vidi_connection_ioctl(struct drm_device *drm_dev, void *data,
struct drm_file *file_priv)
{
struct vidi_context *ctx = NULL;
struct drm_encoder *encoder;
struct exynos_drm_display *display;
struct drm_exynos_vidi_connection *vidi = data;
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
display = exynos_drm_get_display(encoder);
if (display->type == EXYNOS_DISPLAY_TYPE_VIDI) {
ctx = display->ctx;
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
ctx->raw_edid = drm_edid_duplicate(raw_edid);
if (!ctx->raw_edid) {
DRM_DEBUG_KMS("failed to allocate raw_edid.\n");
return -ENOMEM;
}
} else {
if (ctx->raw_edid && ctx->raw_edid !=
(struct edid *)fake_edid_info) {
kfree(ctx->raw_edid);
ctx->raw_edid = NULL;
}
}
ctx->connected = vidi->connection;
drm_helper_hpd_irq_event(ctx->drm_dev);
return 0;
}
static enum drm_connector_status vidi_detect(struct drm_connector *connector,
bool force)
{
struct vidi_context *ctx = ctx_from_connector(connector);
return ctx->connected ? connector_status_connected :
connector_status_disconnected;
}
static void vidi_connector_destroy(struct drm_connector *connector)
{
}
static int vidi_get_modes(struct drm_connector *connector)
{
struct vidi_context *ctx = ctx_from_connector(connector);
struct edid *edid;
int edid_len;
if (!ctx->raw_edid) {
DRM_DEBUG_KMS("raw_edid is null.\n");
return -EFAULT;
}
edid_len = (1 + ctx->raw_edid->extensions) * EDID_LENGTH;
edid = kmemdup(ctx->raw_edid, edid_len, GFP_KERNEL);
if (!edid) {
DRM_DEBUG_KMS("failed to allocate edid\n");
return -ENOMEM;
}
drm_mode_connector_update_edid_property(connector, edid);
return drm_add_edid_modes(connector, edid);
}
static struct drm_encoder *vidi_best_encoder(struct drm_connector *connector)
{
struct vidi_context *ctx = ctx_from_connector(connector);
return ctx->encoder;
}
static int vidi_create_connector(struct exynos_drm_display *display,
struct drm_encoder *encoder)
{
struct vidi_context *ctx = display->ctx;
struct drm_connector *connector = &ctx->connector;
int ret;
ctx->encoder = encoder;
connector->polled = DRM_CONNECTOR_POLL_HPD;
ret = drm_connector_init(ctx->drm_dev, connector,
&vidi_connector_funcs, DRM_MODE_CONNECTOR_VIRTUAL);
if (ret) {
DRM_ERROR("Failed to initialize connector with drm\n");
return ret;
}
drm_connector_helper_add(connector, &vidi_connector_helper_funcs);
drm_connector_register(connector);
drm_mode_connector_attach_encoder(connector, encoder);
return 0;
}
static int vidi_subdrv_probe(struct drm_device *drm_dev, struct device *dev)
{
struct exynos_drm_manager *mgr = get_vidi_mgr(dev);
struct vidi_context *ctx = mgr->ctx;
struct drm_crtc *crtc = ctx->crtc;
int ret;
vidi_mgr_initialize(mgr, drm_dev);
ret = exynos_drm_crtc_create(&vidi_manager);
if (ret) {
DRM_ERROR("failed to create crtc.\n");
return ret;
}
ret = exynos_drm_create_enc_conn(drm_dev, &vidi_display);
if (ret) {
crtc->funcs->destroy(crtc);
DRM_ERROR("failed to create encoder and connector.\n");
return ret;
}
return 0;
}
static int vidi_probe(struct platform_device *pdev)
{
struct exynos_drm_subdrv *subdrv;
struct vidi_context *ctx;
int ret;
ctx = devm_kzalloc(&pdev->dev, sizeof(*ctx), GFP_KERNEL);
if (!ctx)
return -ENOMEM;
ctx->default_win = 0;
INIT_WORK(&ctx->work, vidi_fake_vblank_handler);
vidi_manager.ctx = ctx;
vidi_display.ctx = ctx;
mutex_init(&ctx->lock);
platform_set_drvdata(pdev, &vidi_manager);
subdrv = &ctx->subdrv;
subdrv->dev = &pdev->dev;
subdrv->probe = vidi_subdrv_probe;
ret = exynos_drm_subdrv_register(subdrv);
if (ret < 0) {
dev_err(&pdev->dev, "failed to register drm vidi device\n");
return ret;
}
ret = device_create_file(&pdev->dev, &dev_attr_connection);
if (ret < 0) {
exynos_drm_subdrv_unregister(subdrv);
DRM_INFO("failed to create connection sysfs.\n");
}
return 0;
}
static int vidi_remove(struct platform_device *pdev)
{
struct exynos_drm_manager *mgr = platform_get_drvdata(pdev);
struct vidi_context *ctx = mgr->ctx;
if (ctx->raw_edid != (struct edid *)fake_edid_info) {
kfree(ctx->raw_edid);
ctx->raw_edid = NULL;
return -EINVAL;
}
return 0;
}
int exynos_drm_probe_vidi(void)
{
struct platform_device *pdev;
int ret;
pdev = platform_device_register_simple("exynos-drm-vidi", -1, NULL, 0);
if (IS_ERR(pdev))
return PTR_ERR(pdev);
ret = platform_driver_register(&vidi_driver);
if (ret) {
platform_device_unregister(pdev);
return ret;
}
return ret;
}
void exynos_drm_remove_vidi(void)
{
struct vidi_context *ctx = vidi_manager.ctx;
struct exynos_drm_subdrv *subdrv = &ctx->subdrv;
struct platform_device *pdev = to_platform_device(subdrv->dev);
platform_driver_unregister(&vidi_driver);
platform_device_unregister(pdev);
}
