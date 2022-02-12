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
struct drm_crtc_state *old_crtc_state;
struct drm_crtc *crtc;
unsigned int i;
int ret;
for_each_crtc_in_state(old_state, crtc, old_crtc_state, i) {
if (!crtc->state->enable)
continue;
ret = omap_crtc_wait_pending(crtc);
if (!ret)
dev_warn(dev->dev,
"atomic complete timeout (pipe %u)!\n", i);
}
}
static void omap_atomic_complete(struct omap_atomic_state_commit *commit)
{
struct drm_device *dev = commit->dev;
struct omap_drm_private *priv = dev->dev_private;
struct drm_atomic_state *old_state = commit->state;
dispc_runtime_get();
drm_atomic_helper_commit_modeset_disables(dev, old_state);
drm_atomic_helper_commit_planes(dev, old_state, false);
drm_atomic_helper_commit_modeset_enables(dev, old_state);
omap_atomic_wait_for_completion(dev, old_state);
drm_atomic_helper_cleanup_planes(dev, old_state);
dispc_runtime_put();
drm_atomic_state_free(old_state);
spin_lock(&priv->commit.lock);
priv->commit.pending &= ~commit->crtcs;
spin_unlock(&priv->commit.lock);
wake_up_all(&priv->commit.wait);
kfree(commit);
}
static void omap_atomic_work(struct work_struct *work)
{
struct omap_atomic_state_commit *commit =
container_of(work, struct omap_atomic_state_commit, work);
omap_atomic_complete(commit);
}
static bool omap_atomic_is_pending(struct omap_drm_private *priv,
struct omap_atomic_state_commit *commit)
{
bool pending;
spin_lock(&priv->commit.lock);
pending = priv->commit.pending & commit->crtcs;
spin_unlock(&priv->commit.lock);
return pending;
}
static int omap_atomic_commit(struct drm_device *dev,
struct drm_atomic_state *state, bool nonblock)
{
struct omap_drm_private *priv = dev->dev_private;
struct omap_atomic_state_commit *commit;
struct drm_crtc *crtc;
struct drm_crtc_state *crtc_state;
int i, ret;
ret = drm_atomic_helper_prepare_planes(dev, state);
if (ret)
return ret;
commit = kzalloc(sizeof(*commit), GFP_KERNEL);
if (commit == NULL) {
ret = -ENOMEM;
goto error;
}
INIT_WORK(&commit->work, omap_atomic_work);
commit->dev = dev;
commit->state = state;
for_each_crtc_in_state(state, crtc, crtc_state, i)
commit->crtcs |= drm_crtc_mask(crtc);
wait_event(priv->commit.wait, !omap_atomic_is_pending(priv, commit));
spin_lock(&priv->commit.lock);
priv->commit.pending |= commit->crtcs;
spin_unlock(&priv->commit.lock);
drm_atomic_helper_swap_state(state, true);
if (nonblock)
schedule_work(&commit->work);
else
omap_atomic_complete(commit);
return 0;
error:
drm_atomic_helper_cleanup_planes(dev, state);
return ret;
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
static int omap_modeset_create_crtc(struct drm_device *dev, int id,
enum omap_channel channel)
{
struct omap_drm_private *priv = dev->dev_private;
struct drm_plane *plane;
struct drm_crtc *crtc;
plane = omap_plane_init(dev, id, DRM_PLANE_TYPE_PRIMARY);
if (IS_ERR(plane))
return PTR_ERR(plane);
crtc = omap_crtc_init(dev, plane, channel, id);
BUG_ON(priv->num_crtcs >= ARRAY_SIZE(priv->crtcs));
priv->crtcs[id] = crtc;
priv->num_crtcs++;
priv->planes[id] = plane;
priv->num_planes++;
return 0;
}
static int omap_modeset_init_properties(struct drm_device *dev)
{
struct omap_drm_private *priv = dev->dev_private;
if (priv->has_dmm) {
dev->mode_config.rotation_property =
drm_mode_create_rotation_property(dev,
BIT(DRM_ROTATE_0) | BIT(DRM_ROTATE_90) |
BIT(DRM_ROTATE_180) | BIT(DRM_ROTATE_270) |
BIT(DRM_REFLECT_X) | BIT(DRM_REFLECT_Y));
if (!dev->mode_config.rotation_property)
return -ENOMEM;
}
priv->zorder_prop = drm_property_create_range(dev, 0, "zorder", 0, 3);
if (!priv->zorder_prop)
return -ENOMEM;
return 0;
}
static int omap_modeset_init(struct drm_device *dev)
{
struct omap_drm_private *priv = dev->dev_private;
struct omap_dss_device *dssdev = NULL;
int num_ovls = dss_feat_get_num_ovls();
int num_mgrs = dss_feat_get_num_mgrs();
int num_crtcs;
int i, id = 0;
int ret;
drm_mode_config_init(dev);
omap_drm_irq_install(dev);
ret = omap_modeset_init_properties(dev);
if (ret < 0)
return ret;
num_crtcs = min3(num_crtc, num_mgrs, num_ovls);
dssdev = NULL;
for_each_dss_dev(dssdev) {
struct drm_connector *connector;
struct drm_encoder *encoder;
enum omap_channel channel;
struct omap_dss_device *out;
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
out = omapdss_find_output_from_display(dssdev);
channel = out->dispc_channel;
omap_dss_put_device(out);
if (!channel_used(dev, channel)) {
ret = omap_modeset_create_crtc(dev, id, channel);
if (ret < 0) {
dev_err(dev->dev,
"could not create CRTC (channel %u)\n",
channel);
return ret;
}
id++;
}
}
for (; id < num_crtcs; id++) {
for (i = 0; i < num_mgrs; i++) {
if (!channel_used(dev, i))
break;
}
if (i == num_mgrs) {
dev_err(dev->dev, "no managers left for crtc\n");
return -ENOMEM;
}
ret = omap_modeset_create_crtc(dev, id, i);
if (ret < 0) {
dev_err(dev->dev,
"could not create CRTC (channel %u)\n", i);
return ret;
}
}
for (; id < num_ovls; id++) {
struct drm_plane *plane;
plane = omap_plane_init(dev, id, DRM_PLANE_TYPE_OVERLAY);
if (IS_ERR(plane))
return PTR_ERR(plane);
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
crtc_channel = omap_crtc_channel(crtc);
if (output->dispc_channel == crtc_channel) {
encoder->possible_crtcs |= (1 << id);
break;
}
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
drm_mode_config_reset(dev);
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
u32 flags = args->flags & OMAP_BO_USER_MASK;
VERB("%p:%p: size=0x%08x, flags=%08x", dev, file_priv,
args->size.bytes, flags);
return omap_gem_new_handle(dev, file_priv, args->size, flags,
&args->handle);
}
static int ioctl_gem_cpu_prep(struct drm_device *dev, void *data,
struct drm_file *file_priv)
{
struct drm_omap_gem_cpu_prep *args = data;
struct drm_gem_object *obj;
int ret;
VERB("%p:%p: handle=%d, op=%x", dev, file_priv, args->handle, args->op);
obj = drm_gem_object_lookup(file_priv, args->handle);
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
obj = drm_gem_object_lookup(file_priv, args->handle);
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
obj = drm_gem_object_lookup(file_priv, args->handle);
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
unsigned int i;
int ret;
DBG("load: dev=%p", dev);
priv = kzalloc(sizeof(*priv), GFP_KERNEL);
if (!priv)
return -ENOMEM;
priv->omaprev = pdata->omaprev;
dev->dev_private = priv;
priv->wq = alloc_ordered_workqueue("omapdrm", 0);
init_waitqueue_head(&priv->commit.wait);
spin_lock_init(&priv->commit.lock);
spin_lock_init(&priv->list_lock);
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
for (i = 0; i < priv->num_crtcs; i++)
drm_crtc_vblank_off(priv->crtcs[i]);
priv->fbdev = omap_fbdev_init(dev);
dev_set_drvdata(dev->dev, dev);
drm_kms_helper_poll_init(dev);
return 0;
}
static int dev_unload(struct drm_device *dev)
{
struct omap_drm_private *priv = dev->dev_private;
DBG("unload: dev=%p", dev);
drm_kms_helper_poll_fini(dev);
if (priv->fbdev)
omap_fbdev_free(dev);
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
if (dev->mode_config.rotation_property) {
for (i = 0; i < priv->num_crtcs; i++) {
drm_object_property_set_value(&priv->crtcs[i]->base,
dev->mode_config.rotation_property, 0);
}
for (i = 0; i < priv->num_planes; i++) {
drm_object_property_set_value(&priv->planes[i]->base,
dev->mode_config.rotation_property, 0);
}
}
if (priv->fbdev) {
ret = drm_fb_helper_restore_fbdev_mode_unlocked(priv->fbdev);
if (ret)
DBG("failed to restore crtc mode");
}
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
