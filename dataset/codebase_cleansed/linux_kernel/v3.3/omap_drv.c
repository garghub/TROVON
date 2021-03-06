static void omap_fb_output_poll_changed(struct drm_device *dev)
{
struct omap_drm_private *priv = dev->dev_private;
DBG("dev=%p", dev);
if (priv->fbdev) {
drm_fb_helper_hotplug_event(priv->fbdev);
}
}
static int get_connector_type(struct omap_dss_device *dssdev)
{
switch (dssdev->type) {
case OMAP_DISPLAY_TYPE_HDMI:
return DRM_MODE_CONNECTOR_HDMIA;
case OMAP_DISPLAY_TYPE_DPI:
if (!strcmp(dssdev->name, "dvi"))
return DRM_MODE_CONNECTOR_DVID;
default:
return DRM_MODE_CONNECTOR_Unknown;
}
}
static void dump_video_chains(void)
{
int i;
DBG("dumping video chains: ");
for (i = 0; i < omap_dss_get_num_overlays(); i++) {
struct omap_overlay *ovl = omap_dss_get_overlay(i);
struct omap_overlay_manager *mgr = ovl->manager;
struct omap_dss_device *dssdev = mgr ? mgr->device : NULL;
if (dssdev) {
DBG("%d: %s -> %s -> %s", i, ovl->name, mgr->name,
dssdev->name);
} else if (mgr) {
DBG("%d: %s -> %s", i, ovl->name, mgr->name);
} else {
DBG("%d: %s", i, ovl->name);
}
}
}
static int create_encoder(struct drm_device *dev,
struct omap_overlay_manager *mgr)
{
struct omap_drm_private *priv = dev->dev_private;
struct drm_encoder *encoder = omap_encoder_init(dev, mgr);
if (!encoder) {
dev_err(dev->dev, "could not create encoder: %s\n",
mgr->name);
return -ENOMEM;
}
BUG_ON(priv->num_encoders >= ARRAY_SIZE(priv->encoders));
priv->encoders[priv->num_encoders++] = encoder;
return 0;
}
static int create_connector(struct drm_device *dev,
struct omap_dss_device *dssdev)
{
struct omap_drm_private *priv = dev->dev_private;
static struct notifier_block *notifier;
struct drm_connector *connector;
int j;
if (!dssdev->driver) {
dev_warn(dev->dev, "%s has no driver.. skipping it\n",
dssdev->name);
return 0;
}
if (!(dssdev->driver->get_timings ||
dssdev->driver->read_edid)) {
dev_warn(dev->dev, "%s driver does not support "
"get_timings or read_edid.. skipping it!\n",
dssdev->name);
return 0;
}
connector = omap_connector_init(dev,
get_connector_type(dssdev), dssdev);
if (!connector) {
dev_err(dev->dev, "could not create connector: %s\n",
dssdev->name);
return -ENOMEM;
}
BUG_ON(priv->num_connectors >= ARRAY_SIZE(priv->connectors));
priv->connectors[priv->num_connectors++] = connector;
#if 0
notifier = kzalloc(sizeof(struct notifier_block), GFP_KERNEL);
notifier->notifier_call = omap_drm_notifier;
omap_dss_add_notify(dssdev, notifier);
#else
notifier = NULL;
#endif
for (j = 0; j < priv->num_encoders; j++) {
struct omap_overlay_manager *mgr =
omap_encoder_get_manager(priv->encoders[j]);
if (mgr->device == dssdev) {
drm_mode_connector_attach_encoder(connector,
priv->encoders[j]);
}
}
return 0;
}
static int create_crtc(struct drm_device *dev, struct omap_overlay *ovl,
int *j, unsigned int connected_connectors)
{
struct omap_drm_private *priv = dev->dev_private;
struct omap_overlay_manager *mgr = NULL;
struct drm_crtc *crtc;
while (*j < priv->num_connectors && !mgr) {
if (connected_connectors & (1 << *j)) {
struct drm_encoder *encoder =
omap_connector_attached_encoder(
priv->connectors[*j]);
if (encoder) {
mgr = omap_encoder_get_manager(encoder);
}
}
(*j)++;
}
while (*j < 2 * priv->num_connectors && !mgr) {
int idx = *j - priv->num_connectors;
if (!(connected_connectors & (1 << idx))) {
struct drm_encoder *encoder =
omap_connector_attached_encoder(
priv->connectors[idx]);
if (encoder) {
mgr = omap_encoder_get_manager(encoder);
}
}
(*j)++;
}
crtc = omap_crtc_init(dev, ovl, priv->num_crtcs);
if (!crtc) {
dev_err(dev->dev, "could not create CRTC: %s\n",
ovl->name);
return -ENOMEM;
}
BUG_ON(priv->num_crtcs >= ARRAY_SIZE(priv->crtcs));
priv->crtcs[priv->num_crtcs++] = crtc;
return 0;
}
static int create_plane(struct drm_device *dev, struct omap_overlay *ovl,
unsigned int possible_crtcs)
{
struct omap_drm_private *priv = dev->dev_private;
struct drm_plane *plane =
omap_plane_init(dev, ovl, possible_crtcs, false);
if (!plane) {
dev_err(dev->dev, "could not create plane: %s\n",
ovl->name);
return -ENOMEM;
}
BUG_ON(priv->num_planes >= ARRAY_SIZE(priv->planes));
priv->planes[priv->num_planes++] = plane;
return 0;
}
static int match_dev_name(struct omap_dss_device *dssdev, void *data)
{
return !strcmp(dssdev->name, data);
}
static unsigned int detect_connectors(struct drm_device *dev)
{
struct omap_drm_private *priv = dev->dev_private;
unsigned int connected_connectors = 0;
int i;
for (i = 0; i < priv->num_connectors; i++) {
struct drm_connector *connector = priv->connectors[i];
if (omap_connector_detect(connector, true) ==
connector_status_connected) {
connected_connectors |= (1 << i);
}
}
return connected_connectors;
}
static int omap_modeset_init(struct drm_device *dev)
{
const struct omap_drm_platform_data *pdata = dev->dev->platform_data;
struct omap_kms_platform_data *kms_pdata = NULL;
struct omap_drm_private *priv = dev->dev_private;
struct omap_dss_device *dssdev = NULL;
int i, j;
unsigned int connected_connectors = 0;
drm_mode_config_init(dev);
if (pdata && pdata->kms_pdata) {
kms_pdata = pdata->kms_pdata;
for (i = 0; i < kms_pdata->mgr_cnt; i++) {
struct omap_overlay_manager *mgr =
omap_dss_get_overlay_manager(
kms_pdata->mgr_ids[i]);
create_encoder(dev, mgr);
}
for (i = 0; i < kms_pdata->dev_cnt; i++) {
struct omap_dss_device *dssdev =
omap_dss_find_device(
(void *)kms_pdata->dev_names[i],
match_dev_name);
if (!dssdev) {
dev_warn(dev->dev, "no such dssdev: %s\n",
kms_pdata->dev_names[i]);
continue;
}
create_connector(dev, dssdev);
}
connected_connectors = detect_connectors(dev);
j = 0;
for (i = 0; i < kms_pdata->ovl_cnt; i++) {
struct omap_overlay *ovl =
omap_dss_get_overlay(kms_pdata->ovl_ids[i]);
create_crtc(dev, ovl, &j, connected_connectors);
}
for (i = 0; i < kms_pdata->pln_cnt; i++) {
struct omap_overlay *ovl =
omap_dss_get_overlay(kms_pdata->pln_ids[i]);
create_plane(dev, ovl, (1 << priv->num_crtcs) - 1);
}
} else {
int max_overlays = min(omap_dss_get_num_overlays(), num_crtc);
for (i = 0; i < omap_dss_get_num_overlay_managers(); i++) {
create_encoder(dev, omap_dss_get_overlay_manager(i));
}
for_each_dss_dev(dssdev) {
create_connector(dev, dssdev);
}
connected_connectors = detect_connectors(dev);
j = 0;
for (i = 0; i < max_overlays; i++) {
create_crtc(dev, omap_dss_get_overlay(i),
&j, connected_connectors);
}
for (; i < omap_dss_get_num_overlays(); i++) {
struct omap_overlay *ovl = omap_dss_get_overlay(i);
create_plane(dev, ovl, (1 << priv->num_crtcs) - 1);
}
}
for (i = 0; i < priv->num_encoders; i++) {
struct drm_encoder *encoder = priv->encoders[i];
struct omap_overlay_manager *mgr =
omap_encoder_get_manager(encoder);
encoder->possible_crtcs = (1 << priv->num_crtcs) - 1;
DBG("%s: possible_crtcs=%08x", mgr->name,
encoder->possible_crtcs);
}
dump_video_chains();
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
struct drm_omap_param *args = data;
DBG("%p: param=%llu", dev, args->param);
switch (args->param) {
case OMAP_PARAM_CHIPSET_ID:
args->value = GET_OMAP_TYPE;
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
DBG("%p:%p: size=0x%08x, flags=%08x", dev, file_priv,
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
if (!obj) {
return -ENOENT;
}
ret = omap_gem_op_sync(obj, args->op);
if (!ret) {
ret = omap_gem_op_start(obj, args->op);
}
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
if (!obj) {
return -ENOENT;
}
ret = 0;
if (!ret) {
ret = omap_gem_op_finish(obj, args->op);
}
drm_gem_object_unreference_unlocked(obj);
return ret;
}
static int ioctl_gem_info(struct drm_device *dev, void *data,
struct drm_file *file_priv)
{
struct drm_omap_gem_info *args = data;
struct drm_gem_object *obj;
int ret = 0;
DBG("%p:%p: handle=%d", dev, file_priv, args->handle);
obj = drm_gem_object_lookup(dev, file_priv, args->handle);
if (!obj) {
return -ENOENT;
}
args->size = omap_gem_mmap_size(obj);
args->offset = omap_gem_mmap_offset(obj);
drm_gem_object_unreference_unlocked(obj);
return ret;
}
static int dev_load(struct drm_device *dev, unsigned long flags)
{
struct omap_drm_private *priv;
int ret;
DBG("load: dev=%p", dev);
drm_device = dev;
priv = kzalloc(sizeof(*priv), GFP_KERNEL);
if (!priv) {
dev_err(dev->dev, "could not allocate priv\n");
return -ENOMEM;
}
dev->dev_private = priv;
omap_gem_init(dev);
ret = omap_modeset_init(dev);
if (ret) {
dev_err(dev->dev, "omap_modeset_init failed: ret=%d\n", ret);
dev->dev_private = NULL;
kfree(priv);
return ret;
}
priv->fbdev = omap_fbdev_init(dev);
if (!priv->fbdev) {
dev_warn(dev->dev, "omap_fbdev_init failed\n");
}
drm_kms_helper_poll_init(dev);
ret = drm_vblank_init(dev, priv->num_crtcs);
if (ret) {
dev_warn(dev->dev, "could not init vblank\n");
}
return 0;
}
static int dev_unload(struct drm_device *dev)
{
DBG("unload: dev=%p", dev);
drm_vblank_cleanup(dev);
drm_kms_helper_poll_fini(dev);
omap_fbdev_free(dev);
omap_modeset_free(dev);
omap_gem_deinit(dev);
kfree(dev->dev_private);
dev->dev_private = NULL;
return 0;
}
static int dev_open(struct drm_device *dev, struct drm_file *file)
{
file->driver_priv = NULL;
DBG("open: dev=%p, file=%p", dev, file);
return 0;
}
static int dev_firstopen(struct drm_device *dev)
{
DBG("firstopen: dev=%p", dev);
return 0;
}
static void dev_lastclose(struct drm_device *dev)
{
struct omap_drm_private *priv = dev->dev_private;
int ret;
DBG("lastclose: dev=%p", dev);
ret = drm_fb_helper_restore_fbdev_mode(priv->fbdev);
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
static int dev_enable_vblank(struct drm_device *dev, int crtc)
{
DBG("enable_vblank: dev=%p, crtc=%d", dev, crtc);
return 0;
}
static void dev_disable_vblank(struct drm_device *dev, int crtc)
{
DBG("disable_vblank: dev=%p, crtc=%d", dev, crtc);
}
static irqreturn_t dev_irq_handler(DRM_IRQ_ARGS)
{
return IRQ_HANDLED;
}
static void dev_irq_preinstall(struct drm_device *dev)
{
DBG("irq_preinstall: dev=%p", dev);
}
static int dev_irq_postinstall(struct drm_device *dev)
{
DBG("irq_postinstall: dev=%p", dev);
return 0;
}
static void dev_irq_uninstall(struct drm_device *dev)
{
DBG("irq_uninstall: dev=%p", dev);
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
DBG("%s", device->name);
return drm_platform_init(&omap_drm_driver, device);
}
static int pdev_remove(struct platform_device *device)
{
DBG("");
drm_platform_exit(&omap_drm_driver, device);
return 0;
}
static int __init omap_drm_init(void)
{
DBG("init");
return platform_driver_register(&pdev);
}
static void __exit omap_drm_fini(void)
{
DBG("fini");
platform_driver_unregister(&pdev);
}
