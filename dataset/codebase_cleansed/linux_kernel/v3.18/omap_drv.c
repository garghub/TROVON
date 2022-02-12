static void omap_fb_output_poll_changed(struct drm_device *dev)
{
struct omap_drm_private *priv = dev->dev_private;
DBG("dev=%p", dev);
if (priv->fbdev)
drm_fb_helper_hotplug_event(priv->fbdev);
}
static int get_connector_type(struct omap_dss_device *dssdev)
{
switch (dssdev->type) {
case OMAP_DISPLAY_TYPE_HDMI:
return DRM_MODE_CONNECTOR_HDMIA;
case OMAP_DISPLAY_TYPE_DVI:
return DRM_MODE_CONNECTOR_DVID;
default:
return DRM_MODE_CONNECTOR_Unknown;
}
}
static bool channel_used(struct drm_device *dev, enum omap_channel channel)
{
struct omap_drm_private *priv = dev->dev_private;
int i;
for (i = 0; i < priv->num_crtcs; i++) {
struct drm_crtc *crtc = priv->crtcs[i];
if (omap_crtc_channel(crtc) == channel)
return true;
}
return false;
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
bool no_displays = true;
for_each_dss_dev(dssdev) {
r = dssdev->driver->connect(dssdev);
if (r == -EPROBE_DEFER) {
omap_dss_put_device(dssdev);
goto cleanup;
} else if (r) {
dev_warn(dssdev->dev, "could not connect display: %s\n",
dssdev->name);
} else {
no_displays = false;
}
}
if (no_displays)
return -EPROBE_DEFER;
return 0;
cleanup:
omap_disconnect_dssdevs();
return r;
}
static int omap_modeset_init(struct drm_device *dev)
{
struct omap_drm_private *priv = dev->dev_private;
struct omap_dss_device *dssdev = NULL;
int num_ovls = dss_feat_get_num_ovls();
int num_mgrs = dss_feat_get_num_mgrs();
int num_crtcs;
int i, id = 0;
drm_mode_config_init(dev);
omap_drm_irq_install(dev);
num_crtcs = min3(num_crtc, num_mgrs, num_ovls);
dssdev = NULL;
for_each_dss_dev(dssdev) {
struct drm_connector *connector;
struct drm_encoder *encoder;
enum omap_channel channel;
struct omap_overlay_manager *mgr;
if (!omapdss_device_is_connected(dssdev))
continue;
encoder = omap_encoder_init(dev, dssdev);
if (!encoder) {
dev_err(dev->dev, "could not create encoder: %s\n",
dssdev->name);
return -ENOMEM;
}
connector = omap_connector_init(dev,
get_connector_type(dssdev), dssdev, encoder);
if (!connector) {
dev_err(dev->dev, "could not create connector: %s\n",
dssdev->name);
return -ENOMEM;
}
BUG_ON(priv->num_encoders >= ARRAY_SIZE(priv->encoders));
BUG_ON(priv->num_connectors >= ARRAY_SIZE(priv->connectors));
priv->encoders[priv->num_encoders++] = encoder;
priv->connectors[priv->num_connectors++] = connector;
drm_mode_connector_attach_encoder(connector, encoder);
if (id == num_crtcs)
continue;
mgr = omapdss_find_mgr_from_display(dssdev);
channel = mgr->id;
if (!channel_used(dev, channel)) {
struct drm_plane *plane;
struct drm_crtc *crtc;
plane = omap_plane_init(dev, id, true);
crtc = omap_crtc_init(dev, plane, channel, id);
BUG_ON(priv->num_crtcs >= ARRAY_SIZE(priv->crtcs));
priv->crtcs[id] = crtc;
priv->num_crtcs++;
priv->planes[id] = plane;
priv->num_planes++;
id++;
}
}
for (; id < num_crtcs; id++) {
for (i = 0; i < num_mgrs; i++) {
if (!channel_used(dev, i)) {
struct drm_plane *plane;
struct drm_crtc *crtc;
plane = omap_plane_init(dev, id, true);
crtc = omap_crtc_init(dev, plane, i, id);
BUG_ON(priv->num_crtcs >=
ARRAY_SIZE(priv->crtcs));
priv->crtcs[id] = crtc;
priv->num_crtcs++;
priv->planes[id] = plane;
priv->num_planes++;
break;
} else {
continue;
}
}
if (i == num_mgrs) {
dev_err(dev->dev, "no managers left for crtc\n");
return -ENOMEM;
}
}
for (; id < num_ovls; id++) {
struct drm_plane *plane = omap_plane_init(dev, id, false);
BUG_ON(priv->num_planes >= ARRAY_SIZE(priv->planes));
priv->planes[priv->num_planes++] = plane;
}
for (i = 0; i < priv->num_encoders; i++) {
struct drm_encoder *encoder = priv->encoders[i];
struct omap_dss_device *dssdev =
omap_encoder_get_dssdev(encoder);
struct omap_dss_device *output;
output = omapdss_find_output_from_display(dssdev);
encoder->possible_crtcs = 0;
for (id = 0; id < priv->num_crtcs; id++) {
struct drm_crtc *crtc = priv->crtcs[id];
enum omap_channel crtc_channel;
enum omap_dss_output_id supported_outputs;
crtc_channel = omap_crtc_channel(crtc);
supported_outputs =
dss_feat_get_supported_outputs(crtc_channel);
if (supported_outputs & output->id)
encoder->possible_crtcs |= (1 << id);
}
omap_dss_put_device(output);
}
DBG("registered %d planes, %d crtcs, %d encoders and %d connectors\n",
priv->num_planes, priv->num_crtcs, priv->num_encoders,
priv->num_connectors);
dev->mode_config.min_width = 32;
dev->mode_config.min_height = 32;
dev->mode_config.max_width = 2048;
dev->mode_config.max_height = 2048;
dev->mode_config.funcs = &omap_mode_config_funcs;
return 0;
}
static void omap_modeset_free(struct drm_device *dev)
{
drm_mode_config_cleanup(dev);
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
VERB("%p:%p: size=0x%08x, flags=%08x", dev, file_priv,
args->size.bytes, args->flags);
return omap_gem_new_handle(dev, file_priv, args->size,
args->flags, &args->handle);
}
static int ioctl_gem_cpu_prep(struct drm_device *dev, void *data,
struct drm_file *file_priv)
{
struct drm_omap_gem_cpu_prep *args = data;
struct drm_gem_object *obj;
int ret;
VERB("%p:%p: handle=%d, op=%x", dev, file_priv, args->handle, args->op);
obj = drm_gem_object_lookup(dev, file_priv, args->handle);
if (!obj)
return -ENOENT;
ret = omap_gem_op_sync(obj, args->op);
if (!ret)
ret = omap_gem_op_start(obj, args->op);
drm_gem_object_unreference_unlocked(obj);
return ret;
}
static int ioctl_gem_cpu_fini(struct drm_device *dev, void *data,
struct drm_file *file_priv)
{
struct drm_omap_gem_cpu_fini *args = data;
struct drm_gem_object *obj;
int ret;
VERB("%p:%p: handle=%d", dev, file_priv, args->handle);
obj = drm_gem_object_lookup(dev, file_priv, args->handle);
if (!obj)
return -ENOENT;
ret = 0;
if (!ret)
ret = omap_gem_op_finish(obj, args->op);
drm_gem_object_unreference_unlocked(obj);
return ret;
}
static int ioctl_gem_info(struct drm_device *dev, void *data,
struct drm_file *file_priv)
{
struct drm_omap_gem_info *args = data;
struct drm_gem_object *obj;
int ret = 0;
VERB("%p:%p: handle=%d", dev, file_priv, args->handle);
obj = drm_gem_object_lookup(dev, file_priv, args->handle);
if (!obj)
return -ENOENT;
args->size = omap_gem_mmap_size(obj);
args->offset = omap_gem_mmap_offset(obj);
drm_gem_object_unreference_unlocked(obj);
return ret;
}
static int dev_load(struct drm_device *dev, unsigned long flags)
{
struct omap_drm_platform_data *pdata = dev->dev->platform_data;
struct omap_drm_private *priv;
int ret;
DBG("load: dev=%p", dev);
priv = kzalloc(sizeof(*priv), GFP_KERNEL);
if (!priv)
return -ENOMEM;
priv->omaprev = pdata->omaprev;
dev->dev_private = priv;
priv->wq = alloc_ordered_workqueue("omapdrm", 0);
INIT_LIST_HEAD(&priv->obj_list);
omap_gem_init(dev);
ret = omap_modeset_init(dev);
if (ret) {
dev_err(dev->dev, "omap_modeset_init failed: ret=%d\n", ret);
dev->dev_private = NULL;
kfree(priv);
return ret;
}
ret = drm_vblank_init(dev, priv->num_crtcs);
if (ret)
dev_warn(dev->dev, "could not init vblank\n");
priv->fbdev = omap_fbdev_init(dev);
if (!priv->fbdev) {
dev_warn(dev->dev, "omap_fbdev_init failed\n");
}
dev_set_drvdata(dev->dev, dev);
drm_kms_helper_poll_init(dev);
return 0;
}
static int dev_unload(struct drm_device *dev)
{
struct omap_drm_private *priv = dev->dev_private;
int i;
DBG("unload: dev=%p", dev);
drm_kms_helper_poll_fini(dev);
omap_fbdev_free(dev);
for (i = 0; i < priv->num_crtcs; i++)
omap_crtc_flush(priv->crtcs[i]);
omap_modeset_free(dev);
omap_gem_deinit(dev);
destroy_workqueue(priv->wq);
drm_vblank_cleanup(dev);
omap_drm_irq_uninstall(dev);
kfree(dev->dev_private);
dev->dev_private = NULL;
dev_set_drvdata(dev->dev, NULL);
return 0;
}
static int dev_open(struct drm_device *dev, struct drm_file *file)
{
file->driver_priv = NULL;
DBG("open: dev=%p, file=%p", dev, file);
return 0;
}
static void dev_lastclose(struct drm_device *dev)
{
int i;
struct omap_drm_private *priv = dev->dev_private;
int ret;
DBG("lastclose: dev=%p", dev);
if (priv->rotation_prop) {
for (i = 0; i < priv->num_crtcs; i++) {
drm_object_property_set_value(&priv->crtcs[i]->base,
priv->rotation_prop, 0);
}
for (i = 0; i < priv->num_planes; i++) {
drm_object_property_set_value(&priv->planes[i]->base,
priv->rotation_prop, 0);
}
}
ret = drm_fb_helper_restore_fbdev_mode_unlocked(priv->fbdev);
if (ret)
DBG("failed to restore crtc mode");
}
static void dev_preclose(struct drm_device *dev, struct drm_file *file)
{
DBG("preclose: dev=%p", dev);
}
static void dev_postclose(struct drm_device *dev, struct drm_file *file)
{
DBG("postclose: dev=%p, file=%p", dev, file);
}
static int pdev_suspend(struct platform_device *pDevice, pm_message_t state)
{
DBG("");
return 0;
}
static int pdev_resume(struct platform_device *device)
{
DBG("");
return 0;
}
static void pdev_shutdown(struct platform_device *device)
{
DBG("");
}
static int pdev_probe(struct platform_device *device)
{
int r;
if (omapdss_is_initialized() == false)
return -EPROBE_DEFER;
omap_crtc_pre_init();
r = omap_connect_dssdevs();
if (r) {
omap_crtc_pre_uninit();
return r;
}
DBG("%s", device->name);
return drm_platform_init(&omap_drm_driver, device);
}
static int pdev_remove(struct platform_device *device)
{
DBG("");
drm_put_dev(platform_get_drvdata(device));
omap_disconnect_dssdevs();
omap_crtc_pre_uninit();
return 0;
}
static int __init omap_drm_init(void)
{
int r;
DBG("init");
r = platform_driver_register(&omap_dmm_driver);
if (r) {
pr_err("DMM driver registration failed\n");
return r;
}
r = platform_driver_register(&pdev);
if (r) {
pr_err("omapdrm driver registration failed\n");
platform_driver_unregister(&omap_dmm_driver);
return r;
}
return 0;
}
static void __exit omap_drm_fini(void)
{
DBG("fini");
platform_driver_unregister(&pdev);
platform_driver_unregister(&omap_dmm_driver);
}
