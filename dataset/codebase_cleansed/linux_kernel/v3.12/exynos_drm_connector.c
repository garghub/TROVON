static int exynos_drm_connector_get_modes(struct drm_connector *connector)
{
struct exynos_drm_connector *exynos_connector =
to_exynos_connector(connector);
struct exynos_drm_manager *manager = exynos_connector->manager;
struct exynos_drm_display_ops *display_ops = manager->display_ops;
struct edid *edid = NULL;
unsigned int count = 0;
int ret;
if (!display_ops) {
DRM_DEBUG_KMS("display_ops is null.\n");
return 0;
}
if (display_ops->get_edid) {
edid = display_ops->get_edid(manager->dev, connector);
if (IS_ERR_OR_NULL(edid)) {
ret = PTR_ERR(edid);
edid = NULL;
DRM_ERROR("Panel operation get_edid failed %d\n", ret);
goto out;
}
count = drm_add_edid_modes(connector, edid);
if (!count) {
DRM_ERROR("Add edid modes failed %d\n", count);
goto out;
}
drm_mode_connector_update_edid_property(connector, edid);
} else {
struct exynos_drm_panel_info *panel;
struct drm_display_mode *mode = drm_mode_create(connector->dev);
if (!mode) {
DRM_ERROR("failed to create a new display mode.\n");
return 0;
}
if (display_ops->get_panel)
panel = display_ops->get_panel(manager->dev);
else {
drm_mode_destroy(connector->dev, mode);
return 0;
}
drm_display_mode_from_videomode(&panel->vm, mode);
mode->width_mm = panel->width_mm;
mode->height_mm = panel->height_mm;
connector->display_info.width_mm = mode->width_mm;
connector->display_info.height_mm = mode->height_mm;
mode->type = DRM_MODE_TYPE_DRIVER | DRM_MODE_TYPE_PREFERRED;
drm_mode_set_name(mode);
drm_mode_probed_add(connector, mode);
count = 1;
}
out:
kfree(edid);
return count;
}
static int exynos_drm_connector_mode_valid(struct drm_connector *connector,
struct drm_display_mode *mode)
{
struct exynos_drm_connector *exynos_connector =
to_exynos_connector(connector);
struct exynos_drm_manager *manager = exynos_connector->manager;
struct exynos_drm_display_ops *display_ops = manager->display_ops;
int ret = MODE_BAD;
DRM_DEBUG_KMS("%s\n", __FILE__);
if (display_ops && display_ops->check_mode)
if (!display_ops->check_mode(manager->dev, mode))
ret = MODE_OK;
return ret;
}
struct drm_encoder *exynos_drm_best_encoder(struct drm_connector *connector)
{
struct drm_device *dev = connector->dev;
struct exynos_drm_connector *exynos_connector =
to_exynos_connector(connector);
struct drm_mode_object *obj;
struct drm_encoder *encoder;
obj = drm_mode_object_find(dev, exynos_connector->encoder_id,
DRM_MODE_OBJECT_ENCODER);
if (!obj) {
DRM_DEBUG_KMS("Unknown ENCODER ID %d\n",
exynos_connector->encoder_id);
return NULL;
}
encoder = obj_to_encoder(obj);
return encoder;
}
void exynos_drm_display_power(struct drm_connector *connector, int mode)
{
struct drm_encoder *encoder = exynos_drm_best_encoder(connector);
struct exynos_drm_connector *exynos_connector;
struct exynos_drm_manager *manager = exynos_drm_get_manager(encoder);
struct exynos_drm_display_ops *display_ops = manager->display_ops;
exynos_connector = to_exynos_connector(connector);
if (exynos_connector->dpms == mode) {
DRM_DEBUG_KMS("desired dpms mode is same as previous one.\n");
return;
}
if (display_ops && display_ops->power_on)
display_ops->power_on(manager->dev, mode);
exynos_connector->dpms = mode;
}
static void exynos_drm_connector_dpms(struct drm_connector *connector,
int mode)
{
drm_helper_connector_dpms(connector, mode);
exynos_drm_display_power(connector, mode);
}
static int exynos_drm_connector_fill_modes(struct drm_connector *connector,
unsigned int max_width, unsigned int max_height)
{
struct exynos_drm_connector *exynos_connector =
to_exynos_connector(connector);
struct exynos_drm_manager *manager = exynos_connector->manager;
struct exynos_drm_manager_ops *ops = manager->ops;
unsigned int width, height;
width = max_width;
height = max_height;
if (ops && ops->get_max_resol)
ops->get_max_resol(manager->dev, &width, &height);
return drm_helper_probe_single_connector_modes(connector, width,
height);
}
static enum drm_connector_status
exynos_drm_connector_detect(struct drm_connector *connector, bool force)
{
struct exynos_drm_connector *exynos_connector =
to_exynos_connector(connector);
struct exynos_drm_manager *manager = exynos_connector->manager;
struct exynos_drm_display_ops *display_ops =
manager->display_ops;
enum drm_connector_status status = connector_status_disconnected;
if (display_ops && display_ops->is_connected) {
if (display_ops->is_connected(manager->dev))
status = connector_status_connected;
else
status = connector_status_disconnected;
}
return status;
}
static void exynos_drm_connector_destroy(struct drm_connector *connector)
{
struct exynos_drm_connector *exynos_connector =
to_exynos_connector(connector);
drm_sysfs_connector_remove(connector);
drm_connector_cleanup(connector);
kfree(exynos_connector);
}
struct drm_connector *exynos_drm_connector_create(struct drm_device *dev,
struct drm_encoder *encoder)
{
struct exynos_drm_connector *exynos_connector;
struct exynos_drm_manager *manager = exynos_drm_get_manager(encoder);
struct drm_connector *connector;
int type;
int err;
exynos_connector = kzalloc(sizeof(*exynos_connector), GFP_KERNEL);
if (!exynos_connector)
return NULL;
connector = &exynos_connector->drm_connector;
switch (manager->display_ops->type) {
case EXYNOS_DISPLAY_TYPE_HDMI:
type = DRM_MODE_CONNECTOR_HDMIA;
connector->interlace_allowed = true;
connector->polled = DRM_CONNECTOR_POLL_HPD;
break;
case EXYNOS_DISPLAY_TYPE_VIDI:
type = DRM_MODE_CONNECTOR_VIRTUAL;
connector->polled = DRM_CONNECTOR_POLL_HPD;
break;
default:
type = DRM_MODE_CONNECTOR_Unknown;
break;
}
drm_connector_init(dev, connector, &exynos_connector_funcs, type);
drm_connector_helper_add(connector, &exynos_connector_helper_funcs);
err = drm_sysfs_connector_add(connector);
if (err)
goto err_connector;
exynos_connector->encoder_id = encoder->base.id;
exynos_connector->manager = manager;
exynos_connector->dpms = DRM_MODE_DPMS_OFF;
connector->dpms = DRM_MODE_DPMS_OFF;
connector->encoder = encoder;
err = drm_mode_connector_attach_encoder(connector, encoder);
if (err) {
DRM_ERROR("failed to attach a connector to a encoder\n");
goto err_sysfs;
}
DRM_DEBUG_KMS("connector has been created\n");
return connector;
err_sysfs:
drm_sysfs_connector_remove(connector);
err_connector:
drm_connector_cleanup(connector);
kfree(exynos_connector);
return NULL;
}
