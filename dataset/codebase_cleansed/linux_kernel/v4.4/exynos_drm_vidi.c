static inline struct vidi_context *encoder_to_vidi(struct drm_encoder *e)
{
return container_of(e, struct vidi_context, encoder);
}
static int vidi_enable_vblank(struct exynos_drm_crtc *crtc)
{
struct vidi_context *ctx = crtc->ctx;
if (ctx->suspended)
return -EPERM;
if (!test_and_set_bit(0, &ctx->irq_flags))
ctx->vblank_on = true;
ctx->direct_vblank = true;
schedule_work(&ctx->work);
return 0;
}
static void vidi_disable_vblank(struct exynos_drm_crtc *crtc)
{
struct vidi_context *ctx = crtc->ctx;
if (ctx->suspended)
return;
if (test_and_clear_bit(0, &ctx->irq_flags))
ctx->vblank_on = false;
}
static void vidi_update_plane(struct exynos_drm_crtc *crtc,
struct exynos_drm_plane *plane)
{
struct vidi_context *ctx = crtc->ctx;
if (ctx->suspended)
return;
DRM_DEBUG_KMS("dma_addr = %pad\n", plane->dma_addr);
if (ctx->vblank_on)
schedule_work(&ctx->work);
}
static void vidi_enable(struct exynos_drm_crtc *crtc)
{
struct vidi_context *ctx = crtc->ctx;
mutex_lock(&ctx->lock);
ctx->suspended = false;
if (test_and_clear_bit(0, &ctx->irq_flags))
vidi_enable_vblank(ctx->crtc);
mutex_unlock(&ctx->lock);
}
static void vidi_disable(struct exynos_drm_crtc *crtc)
{
struct vidi_context *ctx = crtc->ctx;
mutex_lock(&ctx->lock);
ctx->suspended = true;
mutex_unlock(&ctx->lock);
}
static int vidi_ctx_initialize(struct vidi_context *ctx,
struct drm_device *drm_dev)
{
struct exynos_drm_private *priv = drm_dev->dev_private;
ctx->drm_dev = drm_dev;
ctx->pipe = priv->pipe++;
return 0;
}
static void vidi_fake_vblank_handler(struct work_struct *work)
{
struct vidi_context *ctx = container_of(work, struct vidi_context,
work);
int win;
if (ctx->pipe < 0)
return;
usleep_range(16000, 20000);
mutex_lock(&ctx->lock);
if (ctx->direct_vblank) {
drm_crtc_handle_vblank(&ctx->crtc->base);
ctx->direct_vblank = false;
mutex_unlock(&ctx->lock);
return;
}
mutex_unlock(&ctx->lock);
for (win = 0 ; win < WINDOWS_NR ; win++) {
struct exynos_drm_plane *plane = &ctx->planes[win];
if (!plane->pending_fb)
continue;
exynos_drm_crtc_finish_update(ctx->crtc, plane);
}
}
static int vidi_show_connection(struct device *dev,
struct device_attribute *attr, char *buf)
{
struct vidi_context *ctx = dev_get_drvdata(dev);
int rc;
mutex_lock(&ctx->lock);
rc = sprintf(buf, "%d\n", ctx->connected);
mutex_unlock(&ctx->lock);
return rc;
}
static int vidi_store_connection(struct device *dev,
struct device_attribute *attr,
const char *buf, size_t len)
{
struct vidi_context *ctx = dev_get_drvdata(dev);
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
struct vidi_context *ctx = dev_get_drvdata(drm_dev->dev);
struct drm_exynos_vidi_connection *vidi = data;
if (!vidi) {
DRM_DEBUG_KMS("user data for vidi is null.\n");
return -EINVAL;
}
if (vidi->connection > 1) {
DRM_DEBUG_KMS("connection should be 0 or 1.\n");
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
return &ctx->encoder;
}
static int vidi_create_connector(struct drm_encoder *encoder)
{
struct vidi_context *ctx = encoder_to_vidi(encoder);
struct drm_connector *connector = &ctx->connector;
int ret;
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
static bool exynos_vidi_mode_fixup(struct drm_encoder *encoder,
const struct drm_display_mode *mode,
struct drm_display_mode *adjusted_mode)
{
return true;
}
static void exynos_vidi_mode_set(struct drm_encoder *encoder,
struct drm_display_mode *mode,
struct drm_display_mode *adjusted_mode)
{
}
static void exynos_vidi_enable(struct drm_encoder *encoder)
{
}
static void exynos_vidi_disable(struct drm_encoder *encoder)
{
}
static int vidi_bind(struct device *dev, struct device *master, void *data)
{
struct vidi_context *ctx = dev_get_drvdata(dev);
struct drm_device *drm_dev = data;
struct drm_encoder *encoder = &ctx->encoder;
struct exynos_drm_plane *exynos_plane;
enum drm_plane_type type;
unsigned int zpos;
int pipe, ret;
vidi_ctx_initialize(ctx, drm_dev);
for (zpos = 0; zpos < WINDOWS_NR; zpos++) {
type = exynos_plane_get_type(zpos, CURSOR_WIN);
ret = exynos_plane_init(drm_dev, &ctx->planes[zpos],
1 << ctx->pipe, type, formats,
ARRAY_SIZE(formats), zpos);
if (ret)
return ret;
}
exynos_plane = &ctx->planes[DEFAULT_WIN];
ctx->crtc = exynos_drm_crtc_create(drm_dev, &exynos_plane->base,
ctx->pipe, EXYNOS_DISPLAY_TYPE_VIDI,
&vidi_crtc_ops, ctx);
if (IS_ERR(ctx->crtc)) {
DRM_ERROR("failed to create crtc.\n");
return PTR_ERR(ctx->crtc);
}
pipe = exynos_drm_crtc_get_pipe_from_type(drm_dev,
EXYNOS_DISPLAY_TYPE_VIDI);
if (pipe < 0)
return pipe;
encoder->possible_crtcs = 1 << pipe;
DRM_DEBUG_KMS("possible_crtcs = 0x%x\n", encoder->possible_crtcs);
drm_encoder_init(drm_dev, encoder, &exynos_vidi_encoder_funcs,
DRM_MODE_ENCODER_TMDS);
drm_encoder_helper_add(encoder, &exynos_vidi_encoder_helper_funcs);
ret = vidi_create_connector(encoder);
if (ret) {
DRM_ERROR("failed to create connector ret = %d\n", ret);
drm_encoder_cleanup(encoder);
return ret;
}
return 0;
}
static void vidi_unbind(struct device *dev, struct device *master, void *data)
{
}
static int vidi_probe(struct platform_device *pdev)
{
struct vidi_context *ctx;
int ret;
ctx = devm_kzalloc(&pdev->dev, sizeof(*ctx), GFP_KERNEL);
if (!ctx)
return -ENOMEM;
ctx->pdev = pdev;
INIT_WORK(&ctx->work, vidi_fake_vblank_handler);
mutex_init(&ctx->lock);
platform_set_drvdata(pdev, ctx);
ret = device_create_file(&pdev->dev, &dev_attr_connection);
if (ret < 0) {
DRM_ERROR("failed to create connection sysfs.\n");
return ret;
}
ret = component_add(&pdev->dev, &vidi_component_ops);
if (ret)
goto err_remove_file;
return ret;
err_remove_file:
device_remove_file(&pdev->dev, &dev_attr_connection);
return ret;
}
static int vidi_remove(struct platform_device *pdev)
{
struct vidi_context *ctx = platform_get_drvdata(pdev);
if (ctx->raw_edid != (struct edid *)fake_edid_info) {
kfree(ctx->raw_edid);
ctx->raw_edid = NULL;
return -EINVAL;
}
component_del(&pdev->dev, &vidi_component_ops);
return 0;
}
