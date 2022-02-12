void exynos_drm_display_ops_register(struct exynos_hdmi_display_ops
*display_ops)
{
DRM_DEBUG_KMS("%s\n", __FILE__);
if (display_ops)
hdmi_display_ops = display_ops;
}
void exynos_drm_manager_ops_register(struct exynos_hdmi_manager_ops
*manager_ops)
{
DRM_DEBUG_KMS("%s\n", __FILE__);
if (manager_ops)
hdmi_manager_ops = manager_ops;
}
void exynos_drm_overlay_ops_register(struct exynos_hdmi_overlay_ops
*overlay_ops)
{
DRM_DEBUG_KMS("%s\n", __FILE__);
if (overlay_ops)
hdmi_overlay_ops = overlay_ops;
}
static bool drm_hdmi_is_connected(struct device *dev)
{
struct drm_hdmi_context *ctx = to_context(dev);
DRM_DEBUG_KMS("%s\n", __FILE__);
if (hdmi_display_ops && hdmi_display_ops->is_connected)
return hdmi_display_ops->is_connected(ctx->hdmi_ctx->ctx);
return false;
}
static int drm_hdmi_get_edid(struct device *dev,
struct drm_connector *connector, u8 *edid, int len)
{
struct drm_hdmi_context *ctx = to_context(dev);
DRM_DEBUG_KMS("%s\n", __FILE__);
if (hdmi_display_ops && hdmi_display_ops->get_edid)
return hdmi_display_ops->get_edid(ctx->hdmi_ctx->ctx,
connector, edid, len);
return 0;
}
static int drm_hdmi_check_timing(struct device *dev, void *timing)
{
struct drm_hdmi_context *ctx = to_context(dev);
DRM_DEBUG_KMS("%s\n", __FILE__);
if (hdmi_display_ops && hdmi_display_ops->check_timing)
return hdmi_display_ops->check_timing(ctx->hdmi_ctx->ctx,
timing);
return 0;
}
static int drm_hdmi_power_on(struct device *dev, int mode)
{
struct drm_hdmi_context *ctx = to_context(dev);
DRM_DEBUG_KMS("%s\n", __FILE__);
if (hdmi_display_ops && hdmi_display_ops->power_on)
return hdmi_display_ops->power_on(ctx->hdmi_ctx->ctx, mode);
return 0;
}
static int drm_hdmi_enable_vblank(struct device *subdrv_dev)
{
struct drm_hdmi_context *ctx = to_context(subdrv_dev);
struct exynos_drm_subdrv *subdrv = &ctx->subdrv;
struct exynos_drm_manager *manager = &subdrv->manager;
DRM_DEBUG_KMS("%s\n", __FILE__);
if (hdmi_overlay_ops && hdmi_overlay_ops->enable_vblank)
return hdmi_overlay_ops->enable_vblank(ctx->mixer_ctx->ctx,
manager->pipe);
return 0;
}
static void drm_hdmi_disable_vblank(struct device *subdrv_dev)
{
struct drm_hdmi_context *ctx = to_context(subdrv_dev);
DRM_DEBUG_KMS("%s\n", __FILE__);
if (hdmi_overlay_ops && hdmi_overlay_ops->disable_vblank)
return hdmi_overlay_ops->disable_vblank(ctx->mixer_ctx->ctx);
}
static void drm_hdmi_mode_set(struct device *subdrv_dev, void *mode)
{
struct drm_hdmi_context *ctx = to_context(subdrv_dev);
DRM_DEBUG_KMS("%s\n", __FILE__);
if (hdmi_manager_ops && hdmi_manager_ops->mode_set)
hdmi_manager_ops->mode_set(ctx->hdmi_ctx->ctx, mode);
}
static void drm_hdmi_commit(struct device *subdrv_dev)
{
struct drm_hdmi_context *ctx = to_context(subdrv_dev);
DRM_DEBUG_KMS("%s\n", __FILE__);
if (hdmi_manager_ops && hdmi_manager_ops->commit)
hdmi_manager_ops->commit(ctx->hdmi_ctx->ctx);
}
static void drm_hdmi_dpms(struct device *subdrv_dev, int mode)
{
struct drm_hdmi_context *ctx = to_context(subdrv_dev);
DRM_DEBUG_KMS("%s\n", __FILE__);
switch (mode) {
case DRM_MODE_DPMS_ON:
break;
case DRM_MODE_DPMS_STANDBY:
case DRM_MODE_DPMS_SUSPEND:
case DRM_MODE_DPMS_OFF:
if (hdmi_manager_ops && hdmi_manager_ops->disable)
hdmi_manager_ops->disable(ctx->hdmi_ctx->ctx);
break;
default:
DRM_DEBUG_KMS("unkown dps mode: %d\n", mode);
break;
}
}
static void drm_mixer_mode_set(struct device *subdrv_dev,
struct exynos_drm_overlay *overlay)
{
struct drm_hdmi_context *ctx = to_context(subdrv_dev);
DRM_DEBUG_KMS("%s\n", __FILE__);
if (hdmi_overlay_ops && hdmi_overlay_ops->win_mode_set)
hdmi_overlay_ops->win_mode_set(ctx->mixer_ctx->ctx, overlay);
}
static void drm_mixer_commit(struct device *subdrv_dev, int zpos)
{
struct drm_hdmi_context *ctx = to_context(subdrv_dev);
DRM_DEBUG_KMS("%s\n", __FILE__);
if (hdmi_overlay_ops && hdmi_overlay_ops->win_commit)
hdmi_overlay_ops->win_commit(ctx->mixer_ctx->ctx, zpos);
}
static void drm_mixer_disable(struct device *subdrv_dev, int zpos)
{
struct drm_hdmi_context *ctx = to_context(subdrv_dev);
DRM_DEBUG_KMS("%s\n", __FILE__);
if (hdmi_overlay_ops && hdmi_overlay_ops->win_disable)
hdmi_overlay_ops->win_disable(ctx->mixer_ctx->ctx, zpos);
}
static int hdmi_subdrv_probe(struct drm_device *drm_dev,
struct device *dev)
{
struct exynos_drm_subdrv *subdrv = to_subdrv(dev);
struct drm_hdmi_context *ctx;
struct platform_device *pdev = to_platform_device(dev);
struct exynos_drm_common_hdmi_pd *pd;
int ret;
DRM_DEBUG_KMS("%s\n", __FILE__);
pd = pdev->dev.platform_data;
if (!pd) {
DRM_DEBUG_KMS("platform data is null.\n");
return -EFAULT;
}
if (!pd->hdmi_dev) {
DRM_DEBUG_KMS("hdmi device is null.\n");
return -EFAULT;
}
if (!pd->mixer_dev) {
DRM_DEBUG_KMS("mixer device is null.\n");
return -EFAULT;
}
ret = platform_driver_register(&hdmi_driver);
if (ret) {
DRM_DEBUG_KMS("failed to register hdmi driver.\n");
return ret;
}
ret = platform_driver_register(&mixer_driver);
if (ret) {
DRM_DEBUG_KMS("failed to register mixer driver.\n");
goto err_hdmidrv;
}
ctx = get_ctx_from_subdrv(subdrv);
ctx->hdmi_ctx = (struct exynos_drm_hdmi_context *)
to_context(pd->hdmi_dev);
if (!ctx->hdmi_ctx) {
DRM_DEBUG_KMS("hdmi context is null.\n");
ret = -EFAULT;
goto err_mixerdrv;
}
ctx->hdmi_ctx->drm_dev = drm_dev;
ctx->mixer_ctx = (struct exynos_drm_hdmi_context *)
to_context(pd->mixer_dev);
if (!ctx->mixer_ctx) {
DRM_DEBUG_KMS("mixer context is null.\n");
ret = -EFAULT;
goto err_mixerdrv;
}
ctx->mixer_ctx->drm_dev = drm_dev;
return 0;
err_mixerdrv:
platform_driver_unregister(&mixer_driver);
err_hdmidrv:
platform_driver_unregister(&hdmi_driver);
return ret;
}
static void hdmi_subdrv_remove(struct drm_device *drm_dev)
{
DRM_DEBUG_KMS("%s\n", __FILE__);
platform_driver_unregister(&hdmi_driver);
platform_driver_unregister(&mixer_driver);
}
static void exynos_drm_hdmi_late_probe(struct work_struct *work)
{
struct drm_hdmi_context *ctx = container_of(work,
struct drm_hdmi_context, work);
exynos_drm_subdrv_register(&ctx->subdrv);
}
static int __devinit exynos_drm_hdmi_probe(struct platform_device *pdev)
{
struct device *dev = &pdev->dev;
struct exynos_drm_subdrv *subdrv;
struct drm_hdmi_context *ctx;
DRM_DEBUG_KMS("%s\n", __FILE__);
ctx = kzalloc(sizeof(*ctx), GFP_KERNEL);
if (!ctx) {
DRM_LOG_KMS("failed to alloc common hdmi context.\n");
return -ENOMEM;
}
subdrv = &ctx->subdrv;
subdrv->probe = hdmi_subdrv_probe;
subdrv->remove = hdmi_subdrv_remove;
subdrv->manager.pipe = -1;
subdrv->manager.ops = &drm_hdmi_manager_ops;
subdrv->manager.overlay_ops = &drm_hdmi_overlay_ops;
subdrv->manager.display_ops = &drm_hdmi_display_ops;
subdrv->manager.dev = dev;
platform_set_drvdata(pdev, subdrv);
INIT_WORK(&ctx->work, exynos_drm_hdmi_late_probe);
schedule_work(&ctx->work);
return 0;
}
static int hdmi_runtime_suspend(struct device *dev)
{
DRM_DEBUG_KMS("%s\n", __FILE__);
return 0;
}
static int hdmi_runtime_resume(struct device *dev)
{
DRM_DEBUG_KMS("%s\n", __FILE__);
return 0;
}
static int __devexit exynos_drm_hdmi_remove(struct platform_device *pdev)
{
struct drm_hdmi_context *ctx = platform_get_drvdata(pdev);
DRM_DEBUG_KMS("%s\n", __FILE__);
exynos_drm_subdrv_unregister(&ctx->subdrv);
kfree(ctx);
return 0;
}
static int __init exynos_drm_hdmi_init(void)
{
int ret;
DRM_DEBUG_KMS("%s\n", __FILE__);
ret = platform_driver_register(&exynos_drm_common_hdmi_driver);
if (ret) {
DRM_DEBUG_KMS("failed to register hdmi common driver.\n");
return ret;
}
return ret;
}
static void __exit exynos_drm_hdmi_exit(void)
{
platform_driver_unregister(&exynos_drm_common_hdmi_driver);
}
