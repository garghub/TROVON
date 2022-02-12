static void omap_fb_output_poll_changed(struct drm_device *dev)
{
struct omap_drm_private *priv = dev->dev_private;
DBG("dev=%p", dev);
if (priv->fbdev)
drm_fb_helper_hotplug_event(priv->fbdev);
}
static void omap_atomic_wait_for_completion(struct drm_device *dev,
struct drm_atomic_state *old_state)
{
struct drm_crtc_state *new_crtc_state;
struct drm_crtc *crtc;
unsigned int i;
int ret;
for_each_new_crtc_in_state(old_state, crtc, new_crtc_state, i) {
if (!new_crtc_state->active)
continue;
ret = omap_crtc_wait_pending(crtc);
if (!ret)
dev_warn(dev->dev,
"atomic complete timeout (pipe %u)!\n", i);
}
}
static void omap_atomic_commit_tail(struct drm_atomic_state *old_state)
{
struct drm_device *dev = old_state->dev;
struct omap_drm_private *priv = dev->dev_private;
priv->dispc_ops->runtime_get();
drm_atomic_helper_commit_modeset_disables(dev, old_state);
if (priv->omaprev != 0x3430) {
drm_atomic_helper_commit_modeset_enables(dev, old_state);
omap_atomic_wait_for_completion(dev, old_state);
drm_atomic_helper_commit_planes(dev, old_state, 0);
drm_atomic_helper_commit_hw_done(old_state);
} else {
drm_atomic_helper_commit_planes(dev, old_state, 0);
drm_atomic_helper_commit_modeset_enables(dev, old_state);
drm_atomic_helper_commit_hw_done(old_state);
}
omap_atomic_wait_for_completion(dev, old_state);
drm_atomic_helper_cleanup_planes(dev, old_state);
priv->dispc_ops->runtime_put();
}
static int get_connector_type(struct omap_dss_device *dssdev)
{
switch (dssdev->type) {
case OMAP_DISPLAY_TYPE_HDMI:
return DRM_MODE_CONNECTOR_HDMIA;
case OMAP_DISPLAY_TYPE_DVI:
return DRM_MODE_CONNECTOR_DVID;
case OMAP_DISPLAY_TYPE_DSI:
return DRM_MODE_CONNECTOR_DSI;
case OMAP_DISPLAY_TYPE_DPI:
case OMAP_DISPLAY_TYPE_DBI:
return DRM_MODE_CONNECTOR_DPI;
case OMAP_DISPLAY_TYPE_VENC:
return DRM_MODE_CONNECTOR_SVIDEO;
case OMAP_DISPLAY_TYPE_SDI:
return DRM_MODE_CONNECTOR_LVDS;
default:
return DRM_MODE_CONNECTOR_Unknown;
}
}
static void omap_disconnect_dssdevs(void)
{
struct omap_dss_device *dssdev = NULL;
for_each_dss_dev(dssdev)
dssdev->driver->disconnect(dssdev);
}
static int omap_connect_dssdevs(void)
{
int r;
struct omap_dss_device *dssdev = NULL;
if (!omapdss_stack_is_ready())
return -EPROBE_DEFER;
for_each_dss_dev(dssdev) {
r = dssdev->driver->connect(dssdev);
if (r == -EPROBE_DEFER) {
omap_dss_put_device(dssdev);
goto cleanup;
} else if (r) {
dev_warn(dssdev->dev, "could not connect display: %s\n",
dssdev->name);
}
}
return 0;
cleanup:
omap_disconnect_dssdevs();
return r;
}
static int omap_modeset_init_properties(struct drm_device *dev)
{
struct omap_drm_private *priv = dev->dev_private;
unsigned int num_planes = priv->dispc_ops->get_num_ovls();
priv->zorder_prop = drm_property_create_range(dev, 0, "zorder", 0,
num_planes - 1);
if (!priv->zorder_prop)
return -ENOMEM;
return 0;
}
static int omap_modeset_init(struct drm_device *dev)
{
struct omap_drm_private *priv = dev->dev_private;
struct omap_dss_device *dssdev = NULL;
int num_ovls = priv->dispc_ops->get_num_ovls();
int num_mgrs = priv->dispc_ops->get_num_mgrs();
int num_crtcs, crtc_idx, plane_idx;
int ret;
u32 plane_crtc_mask;
drm_mode_config_init(dev);
ret = omap_modeset_init_properties(dev);
if (ret < 0)
return ret;
num_crtcs = 0;
for_each_dss_dev(dssdev)
if (omapdss_device_is_connected(dssdev))
num_crtcs++;
if (num_crtcs > num_mgrs || num_crtcs > num_ovls ||
num_crtcs > ARRAY_SIZE(priv->crtcs) ||
num_crtcs > ARRAY_SIZE(priv->planes) ||
num_crtcs > ARRAY_SIZE(priv->encoders) ||
num_crtcs > ARRAY_SIZE(priv->connectors)) {
dev_err(dev->dev, "%s(): Too many connected displays\n",
__func__);
return -EINVAL;
}
plane_crtc_mask = (1 << num_crtcs) - 1;
dssdev = NULL;
crtc_idx = 0;
plane_idx = 0;
for_each_dss_dev(dssdev) {
struct drm_connector *connector;
struct drm_encoder *encoder;
struct drm_plane *plane;
struct drm_crtc *crtc;
if (!omapdss_device_is_connected(dssdev))
continue;
encoder = omap_encoder_init(dev, dssdev);
if (!encoder)
return -ENOMEM;
connector = omap_connector_init(dev,
get_connector_type(dssdev), dssdev, encoder);
if (!connector)
return -ENOMEM;
plane = omap_plane_init(dev, plane_idx, DRM_PLANE_TYPE_PRIMARY,
plane_crtc_mask);
if (IS_ERR(plane))
return PTR_ERR(plane);
crtc = omap_crtc_init(dev, plane, dssdev);
if (IS_ERR(crtc))
return PTR_ERR(crtc);
drm_mode_connector_attach_encoder(connector, encoder);
encoder->possible_crtcs = (1 << crtc_idx);
priv->crtcs[priv->num_crtcs++] = crtc;
priv->planes[priv->num_planes++] = plane;
priv->encoders[priv->num_encoders++] = encoder;
priv->connectors[priv->num_connectors++] = connector;
plane_idx++;
crtc_idx++;
}
for (; plane_idx < num_ovls; plane_idx++) {
struct drm_plane *plane;
if (WARN_ON(priv->num_planes >= ARRAY_SIZE(priv->planes)))
return -EINVAL;
plane = omap_plane_init(dev, plane_idx, DRM_PLANE_TYPE_OVERLAY,
plane_crtc_mask);
if (IS_ERR(plane))
return PTR_ERR(plane);
priv->planes[priv->num_planes++] = plane;
}
DBG("registered %d planes, %d crtcs, %d encoders and %d connectors\n",
priv->num_planes, priv->num_crtcs, priv->num_encoders,
priv->num_connectors);
dev->mode_config.min_width = 8;
dev->mode_config.min_height = 2;
dev->mode_config.max_width = 2048;
dev->mode_config.max_height = 2048;
dev->mode_config.funcs = &omap_mode_config_funcs;
dev->mode_config.helper_private = &omap_mode_config_helper_funcs;
drm_mode_config_reset(dev);
omap_drm_irq_install(dev);
return 0;
}
static void omap_modeset_enable_external_hpd(void)
{
struct omap_dss_device *dssdev = NULL;
for_each_dss_dev(dssdev) {
if (dssdev->driver->enable_hpd)
dssdev->driver->enable_hpd(dssdev);
}
}
static void omap_modeset_disable_external_hpd(void)
{
struct omap_dss_device *dssdev = NULL;
for_each_dss_dev(dssdev) {
if (dssdev->driver->disable_hpd)
dssdev->driver->disable_hpd(dssdev);
}
}
static int ioctl_get_param(struct drm_device *dev, void *data,
struct drm_file *file_priv)
{
struct omap_drm_private *priv = dev->dev_private;
struct drm_omap_param *args = data;
DBG("%p: param=%llu", dev, args->param);
switch (args->param) {
case OMAP_PARAM_CHIPSET_ID:
args->value = priv->omaprev;
break;
default:
DBG("unknown parameter %lld", args->param);
return -EINVAL;
}
return 0;
}
static int ioctl_set_param(struct drm_device *dev, void *data,
struct drm_file *file_priv)
{
struct drm_omap_param *args = data;
switch (args->param) {
default:
DBG("unknown parameter %lld", args->param);
return -EINVAL;
}
return 0;
}
static int ioctl_gem_new(struct drm_device *dev, void *data,
struct drm_file *file_priv)
{
struct drm_omap_gem_new *args = data;
u32 flags = args->flags & OMAP_BO_USER_MASK;
VERB("%p:%p: size=0x%08x, flags=%08x", dev, file_priv,
args->size.bytes, flags);
return omap_gem_new_handle(dev, file_priv, args->size, flags,
&args->handle);
}
static int ioctl_gem_info(struct drm_device *dev, void *data,
struct drm_file *file_priv)
{
struct drm_omap_gem_info *args = data;
struct drm_gem_object *obj;
int ret = 0;
VERB("%p:%p: handle=%d", dev, file_priv, args->handle);
obj = drm_gem_object_lookup(file_priv, args->handle);
if (!obj)
return -ENOENT;
args->size = omap_gem_mmap_size(obj);
args->offset = omap_gem_mmap_offset(obj);
drm_gem_object_unreference_unlocked(obj);
return ret;
}
static int dev_open(struct drm_device *dev, struct drm_file *file)
{
file->driver_priv = NULL;
DBG("open: dev=%p, file=%p", dev, file);
return 0;
}
static void dev_lastclose(struct drm_device *dev)
{
struct omap_drm_private *priv = dev->dev_private;
int ret;
DBG("lastclose: dev=%p", dev);
if (priv->fbdev) {
ret = drm_fb_helper_restore_fbdev_mode_unlocked(priv->fbdev);
if (ret)
DBG("failed to restore crtc mode");
}
}
static int pdev_probe(struct platform_device *pdev)
{
const struct soc_device_attribute *soc;
struct omap_drm_private *priv;
struct drm_device *ddev;
unsigned int i;
int ret;
DBG("%s", pdev->name);
if (omapdss_is_initialized() == false)
return -EPROBE_DEFER;
ret = dma_set_coherent_mask(&pdev->dev, DMA_BIT_MASK(32));
if (ret) {
dev_err(&pdev->dev, "Failed to set the DMA mask\n");
return ret;
}
omap_crtc_pre_init();
ret = omap_connect_dssdevs();
if (ret)
goto err_crtc_uninit;
priv = kzalloc(sizeof(*priv), GFP_KERNEL);
if (!priv) {
ret = -ENOMEM;
goto err_disconnect_dssdevs;
}
priv->dispc_ops = dispc_get_ops();
soc = soc_device_match(omapdrm_soc_devices);
priv->omaprev = soc ? (unsigned int)soc->data : 0;
priv->wq = alloc_ordered_workqueue("omapdrm", 0);
spin_lock_init(&priv->list_lock);
INIT_LIST_HEAD(&priv->obj_list);
ddev = drm_dev_alloc(&omap_drm_driver, &pdev->dev);
if (IS_ERR(ddev)) {
ret = PTR_ERR(ddev);
goto err_free_priv;
}
ddev->dev_private = priv;
platform_set_drvdata(pdev, ddev);
omap_gem_init(ddev);
ret = omap_modeset_init(ddev);
if (ret) {
dev_err(&pdev->dev, "omap_modeset_init failed: ret=%d\n", ret);
goto err_free_drm_dev;
}
ret = drm_vblank_init(ddev, priv->num_crtcs);
if (ret) {
dev_err(&pdev->dev, "could not init vblank\n");
goto err_cleanup_modeset;
}
for (i = 0; i < priv->num_crtcs; i++)
drm_crtc_vblank_off(priv->crtcs[i]);
priv->fbdev = omap_fbdev_init(ddev);
drm_kms_helper_poll_init(ddev);
omap_modeset_enable_external_hpd();
ret = drm_dev_register(ddev, 0);
if (ret)
goto err_cleanup_helpers;
return 0;
err_cleanup_helpers:
omap_modeset_disable_external_hpd();
drm_kms_helper_poll_fini(ddev);
if (priv->fbdev)
omap_fbdev_free(ddev);
err_cleanup_modeset:
drm_mode_config_cleanup(ddev);
omap_drm_irq_uninstall(ddev);
err_free_drm_dev:
omap_gem_deinit(ddev);
drm_dev_unref(ddev);
err_free_priv:
destroy_workqueue(priv->wq);
kfree(priv);
err_disconnect_dssdevs:
omap_disconnect_dssdevs();
err_crtc_uninit:
omap_crtc_pre_uninit();
return ret;
}
static int pdev_remove(struct platform_device *pdev)
{
struct drm_device *ddev = platform_get_drvdata(pdev);
struct omap_drm_private *priv = ddev->dev_private;
DBG("");
drm_dev_unregister(ddev);
omap_modeset_disable_external_hpd();
drm_kms_helper_poll_fini(ddev);
if (priv->fbdev)
omap_fbdev_free(ddev);
drm_atomic_helper_shutdown(ddev);
drm_mode_config_cleanup(ddev);
omap_drm_irq_uninstall(ddev);
omap_gem_deinit(ddev);
drm_dev_unref(ddev);
destroy_workqueue(priv->wq);
kfree(priv);
omap_disconnect_dssdevs();
omap_crtc_pre_uninit();
return 0;
}
static int omap_drm_suspend_all_displays(void)
{
struct omap_dss_device *dssdev = NULL;
for_each_dss_dev(dssdev) {
if (!dssdev->driver)
continue;
if (dssdev->state == OMAP_DSS_DISPLAY_ACTIVE) {
dssdev->driver->disable(dssdev);
dssdev->activate_after_resume = true;
} else {
dssdev->activate_after_resume = false;
}
}
return 0;
}
static int omap_drm_resume_all_displays(void)
{
struct omap_dss_device *dssdev = NULL;
for_each_dss_dev(dssdev) {
if (!dssdev->driver)
continue;
if (dssdev->activate_after_resume) {
dssdev->driver->enable(dssdev);
dssdev->activate_after_resume = false;
}
}
return 0;
}
static int omap_drm_suspend(struct device *dev)
{
struct drm_device *drm_dev = dev_get_drvdata(dev);
drm_kms_helper_poll_disable(drm_dev);
drm_modeset_lock_all(drm_dev);
omap_drm_suspend_all_displays();
drm_modeset_unlock_all(drm_dev);
return 0;
}
static int omap_drm_resume(struct device *dev)
{
struct drm_device *drm_dev = dev_get_drvdata(dev);
drm_modeset_lock_all(drm_dev);
omap_drm_resume_all_displays();
drm_modeset_unlock_all(drm_dev);
drm_kms_helper_poll_enable(drm_dev);
return omap_gem_resume(dev);
}
static int __init omap_drm_init(void)
{
DBG("init");
return platform_register_drivers(drivers, ARRAY_SIZE(drivers));
}
static void __exit omap_drm_fini(void)
{
DBG("fini");
platform_unregister_drivers(drivers, ARRAY_SIZE(drivers));
}
