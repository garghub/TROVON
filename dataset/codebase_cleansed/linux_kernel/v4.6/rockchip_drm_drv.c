int rockchip_drm_dma_attach_device(struct drm_device *drm_dev,
struct device *dev)
{
struct dma_iommu_mapping *mapping = drm_dev->dev->archdata.mapping;
int ret;
ret = dma_set_coherent_mask(dev, DMA_BIT_MASK(32));
if (ret)
return ret;
dma_set_max_seg_size(dev, DMA_BIT_MASK(32));
return arm_iommu_attach_device(dev, mapping);
}
void rockchip_drm_dma_detach_device(struct drm_device *drm_dev,
struct device *dev)
{
arm_iommu_detach_device(dev);
}
int rockchip_register_crtc_funcs(struct drm_crtc *crtc,
const struct rockchip_crtc_funcs *crtc_funcs)
{
int pipe = drm_crtc_index(crtc);
struct rockchip_drm_private *priv = crtc->dev->dev_private;
if (pipe > ROCKCHIP_MAX_CRTC)
return -EINVAL;
priv->crtc_funcs[pipe] = crtc_funcs;
return 0;
}
void rockchip_unregister_crtc_funcs(struct drm_crtc *crtc)
{
int pipe = drm_crtc_index(crtc);
struct rockchip_drm_private *priv = crtc->dev->dev_private;
if (pipe > ROCKCHIP_MAX_CRTC)
return;
priv->crtc_funcs[pipe] = NULL;
}
static struct drm_crtc *rockchip_crtc_from_pipe(struct drm_device *drm,
int pipe)
{
struct drm_crtc *crtc;
int i = 0;
list_for_each_entry(crtc, &drm->mode_config.crtc_list, head)
if (i++ == pipe)
return crtc;
return NULL;
}
static int rockchip_drm_crtc_enable_vblank(struct drm_device *dev,
unsigned int pipe)
{
struct rockchip_drm_private *priv = dev->dev_private;
struct drm_crtc *crtc = rockchip_crtc_from_pipe(dev, pipe);
if (crtc && priv->crtc_funcs[pipe] &&
priv->crtc_funcs[pipe]->enable_vblank)
return priv->crtc_funcs[pipe]->enable_vblank(crtc);
return 0;
}
static void rockchip_drm_crtc_disable_vblank(struct drm_device *dev,
unsigned int pipe)
{
struct rockchip_drm_private *priv = dev->dev_private;
struct drm_crtc *crtc = rockchip_crtc_from_pipe(dev, pipe);
if (crtc && priv->crtc_funcs[pipe] &&
priv->crtc_funcs[pipe]->enable_vblank)
priv->crtc_funcs[pipe]->disable_vblank(crtc);
}
static int rockchip_drm_load(struct drm_device *drm_dev, unsigned long flags)
{
struct rockchip_drm_private *private;
struct dma_iommu_mapping *mapping;
struct device *dev = drm_dev->dev;
struct drm_connector *connector;
int ret;
private = devm_kzalloc(drm_dev->dev, sizeof(*private), GFP_KERNEL);
if (!private)
return -ENOMEM;
mutex_init(&private->commit.lock);
INIT_WORK(&private->commit.work, rockchip_drm_atomic_work);
drm_dev->dev_private = private;
drm_mode_config_init(drm_dev);
rockchip_drm_mode_config_init(drm_dev);
dev->dma_parms = devm_kzalloc(dev, sizeof(*dev->dma_parms),
GFP_KERNEL);
if (!dev->dma_parms) {
ret = -ENOMEM;
goto err_config_cleanup;
}
mapping = arm_iommu_create_mapping(&platform_bus_type, 0x00000000,
SZ_2G);
if (IS_ERR(mapping)) {
ret = PTR_ERR(mapping);
goto err_config_cleanup;
}
ret = dma_set_mask_and_coherent(dev, DMA_BIT_MASK(32));
if (ret)
goto err_release_mapping;
dma_set_max_seg_size(dev, DMA_BIT_MASK(32));
ret = arm_iommu_attach_device(dev, mapping);
if (ret)
goto err_release_mapping;
ret = component_bind_all(dev, drm_dev);
if (ret)
goto err_detach_device;
list_for_each_entry(connector, &drm_dev->mode_config.connector_list,
head) {
ret = drm_connector_register(connector);
if (ret) {
dev_err(drm_dev->dev,
"[CONNECTOR:%d:%s] drm_connector_register failed: %d\n",
connector->base.id,
connector->name, ret);
goto err_unbind;
}
}
drm_kms_helper_poll_init(drm_dev);
drm_dev->irq_enabled = true;
ret = drm_vblank_init(drm_dev, ROCKCHIP_MAX_CRTC);
if (ret)
goto err_kms_helper_poll_fini;
drm_dev->vblank_disable_allowed = true;
drm_mode_config_reset(drm_dev);
ret = rockchip_drm_fbdev_init(drm_dev);
if (ret)
goto err_vblank_cleanup;
return 0;
err_vblank_cleanup:
drm_vblank_cleanup(drm_dev);
err_kms_helper_poll_fini:
drm_kms_helper_poll_fini(drm_dev);
err_unbind:
component_unbind_all(dev, drm_dev);
err_detach_device:
arm_iommu_detach_device(dev);
err_release_mapping:
arm_iommu_release_mapping(dev->archdata.mapping);
err_config_cleanup:
drm_mode_config_cleanup(drm_dev);
drm_dev->dev_private = NULL;
return ret;
}
static int rockchip_drm_unload(struct drm_device *drm_dev)
{
struct device *dev = drm_dev->dev;
rockchip_drm_fbdev_fini(drm_dev);
drm_vblank_cleanup(drm_dev);
drm_kms_helper_poll_fini(drm_dev);
component_unbind_all(dev, drm_dev);
arm_iommu_detach_device(dev);
arm_iommu_release_mapping(dev->archdata.mapping);
drm_mode_config_cleanup(drm_dev);
drm_dev->dev_private = NULL;
return 0;
}
static void rockchip_drm_crtc_cancel_pending_vblank(struct drm_crtc *crtc,
struct drm_file *file_priv)
{
struct rockchip_drm_private *priv = crtc->dev->dev_private;
int pipe = drm_crtc_index(crtc);
if (pipe < ROCKCHIP_MAX_CRTC &&
priv->crtc_funcs[pipe] &&
priv->crtc_funcs[pipe]->cancel_pending_vblank)
priv->crtc_funcs[pipe]->cancel_pending_vblank(crtc, file_priv);
}
static void rockchip_drm_preclose(struct drm_device *dev,
struct drm_file *file_priv)
{
struct drm_crtc *crtc;
list_for_each_entry(crtc, &dev->mode_config.crtc_list, head)
rockchip_drm_crtc_cancel_pending_vblank(crtc, file_priv);
}
void rockchip_drm_lastclose(struct drm_device *dev)
{
struct rockchip_drm_private *priv = dev->dev_private;
drm_fb_helper_restore_fbdev_mode_unlocked(&priv->fbdev_helper);
}
static int rockchip_drm_sys_suspend(struct device *dev)
{
struct drm_device *drm = dev_get_drvdata(dev);
struct drm_connector *connector;
if (!drm)
return 0;
drm_modeset_lock_all(drm);
list_for_each_entry(connector, &drm->mode_config.connector_list, head) {
int old_dpms = connector->dpms;
if (connector->funcs->dpms)
connector->funcs->dpms(connector, DRM_MODE_DPMS_OFF);
connector->dpms = old_dpms;
}
drm_modeset_unlock_all(drm);
return 0;
}
static int rockchip_drm_sys_resume(struct device *dev)
{
struct drm_device *drm = dev_get_drvdata(dev);
struct drm_connector *connector;
enum drm_connector_status status;
bool changed = false;
if (!drm)
return 0;
drm_modeset_lock_all(drm);
list_for_each_entry(connector, &drm->mode_config.connector_list, head) {
int desired_mode = connector->dpms;
connector->dpms = DRM_MODE_DPMS_OFF;
if (desired_mode == DRM_MODE_DPMS_ON) {
status = connector->funcs->detect(connector, true);
if (status == connector_status_disconnected) {
connector->encoder = NULL;
connector->status = status;
changed = true;
continue;
}
}
if (connector->funcs->dpms)
connector->funcs->dpms(connector, desired_mode);
}
drm_modeset_unlock_all(drm);
drm_helper_resume_force_mode(drm);
if (changed)
drm_kms_helper_hotplug_event(drm);
return 0;
}
static int compare_of(struct device *dev, void *data)
{
struct device_node *np = data;
return dev->of_node == np;
}
static void rockchip_add_endpoints(struct device *dev,
struct component_match **match,
struct device_node *port)
{
struct device_node *ep, *remote;
for_each_child_of_node(port, ep) {
remote = of_graph_get_remote_port_parent(ep);
if (!remote || !of_device_is_available(remote)) {
of_node_put(remote);
continue;
} else if (!of_device_is_available(remote->parent)) {
dev_warn(dev, "parent device of %s is not available\n",
remote->full_name);
of_node_put(remote);
continue;
}
component_match_add(dev, match, compare_of, remote);
of_node_put(remote);
}
}
static int rockchip_drm_bind(struct device *dev)
{
struct drm_device *drm;
int ret;
drm = drm_dev_alloc(&rockchip_drm_driver, dev);
if (!drm)
return -ENOMEM;
ret = drm_dev_register(drm, 0);
if (ret)
goto err_free;
dev_set_drvdata(dev, drm);
return 0;
err_free:
drm_dev_unref(drm);
return ret;
}
static void rockchip_drm_unbind(struct device *dev)
{
struct drm_device *drm = dev_get_drvdata(dev);
drm_dev_unregister(drm);
drm_dev_unref(drm);
dev_set_drvdata(dev, NULL);
}
static int rockchip_drm_platform_probe(struct platform_device *pdev)
{
struct device *dev = &pdev->dev;
struct component_match *match = NULL;
struct device_node *np = dev->of_node;
struct device_node *port;
int i;
if (!np)
return -ENODEV;
for (i = 0;; i++) {
port = of_parse_phandle(np, "ports", i);
if (!port)
break;
if (!of_device_is_available(port->parent)) {
of_node_put(port);
continue;
}
component_match_add(dev, &match, compare_of, port->parent);
of_node_put(port);
}
if (i == 0) {
dev_err(dev, "missing 'ports' property\n");
return -ENODEV;
}
if (!match) {
dev_err(dev, "No available vop found for display-subsystem.\n");
return -ENODEV;
}
for (i = 0;; i++) {
port = of_parse_phandle(np, "ports", i);
if (!port)
break;
if (!of_device_is_available(port->parent)) {
of_node_put(port);
continue;
}
rockchip_add_endpoints(dev, &match, port);
of_node_put(port);
}
return component_master_add_with_match(dev, &rockchip_drm_ops, match);
}
static int rockchip_drm_platform_remove(struct platform_device *pdev)
{
component_master_del(&pdev->dev, &rockchip_drm_ops);
return 0;
}
