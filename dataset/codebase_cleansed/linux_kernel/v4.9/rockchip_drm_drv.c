int rockchip_drm_dma_attach_device(struct drm_device *drm_dev,
struct device *dev)
{
struct dma_iommu_mapping *mapping = drm_dev->dev->archdata.mapping;
int ret;
if (!is_support_iommu)
return 0;
ret = dma_set_coherent_mask(dev, DMA_BIT_MASK(32));
if (ret)
return ret;
dma_set_max_seg_size(dev, DMA_BIT_MASK(32));
return arm_iommu_attach_device(dev, mapping);
}
void rockchip_drm_dma_detach_device(struct drm_device *drm_dev,
struct device *dev)
{
if (!is_support_iommu)
return;
arm_iommu_detach_device(dev);
}
int rockchip_register_crtc_funcs(struct drm_crtc *crtc,
const struct rockchip_crtc_funcs *crtc_funcs)
{
int pipe = drm_crtc_index(crtc);
struct rockchip_drm_private *priv = crtc->dev->dev_private;
if (pipe >= ROCKCHIP_MAX_CRTC)
return -EINVAL;
priv->crtc_funcs[pipe] = crtc_funcs;
return 0;
}
void rockchip_unregister_crtc_funcs(struct drm_crtc *crtc)
{
int pipe = drm_crtc_index(crtc);
struct rockchip_drm_private *priv = crtc->dev->dev_private;
if (pipe >= ROCKCHIP_MAX_CRTC)
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
static int rockchip_drm_bind(struct device *dev)
{
struct drm_device *drm_dev;
struct rockchip_drm_private *private;
struct dma_iommu_mapping *mapping = NULL;
int ret;
drm_dev = drm_dev_alloc(&rockchip_drm_driver, dev);
if (IS_ERR(drm_dev))
return PTR_ERR(drm_dev);
dev_set_drvdata(dev, drm_dev);
private = devm_kzalloc(drm_dev->dev, sizeof(*private), GFP_KERNEL);
if (!private) {
ret = -ENOMEM;
goto err_free;
}
drm_dev->dev_private = private;
INIT_LIST_HEAD(&private->psr_list);
spin_lock_init(&private->psr_list_lock);
drm_mode_config_init(drm_dev);
rockchip_drm_mode_config_init(drm_dev);
dev->dma_parms = devm_kzalloc(dev, sizeof(*dev->dma_parms),
GFP_KERNEL);
if (!dev->dma_parms) {
ret = -ENOMEM;
goto err_config_cleanup;
}
if (is_support_iommu) {
mapping = arm_iommu_create_mapping(&platform_bus_type,
0x00000000,
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
}
ret = component_bind_all(dev, drm_dev);
if (ret)
goto err_detach_device;
drm_kms_helper_poll_init(drm_dev);
drm_dev->irq_enabled = true;
ret = drm_vblank_init(drm_dev, ROCKCHIP_MAX_CRTC);
if (ret)
goto err_kms_helper_poll_fini;
drm_mode_config_reset(drm_dev);
ret = rockchip_drm_fbdev_init(drm_dev);
if (ret)
goto err_vblank_cleanup;
ret = drm_dev_register(drm_dev, 0);
if (ret)
goto err_fbdev_fini;
if (is_support_iommu)
arm_iommu_release_mapping(mapping);
return 0;
err_fbdev_fini:
rockchip_drm_fbdev_fini(drm_dev);
err_vblank_cleanup:
drm_vblank_cleanup(drm_dev);
err_kms_helper_poll_fini:
drm_kms_helper_poll_fini(drm_dev);
component_unbind_all(dev, drm_dev);
err_detach_device:
if (is_support_iommu)
arm_iommu_detach_device(dev);
err_release_mapping:
if (is_support_iommu)
arm_iommu_release_mapping(mapping);
err_config_cleanup:
drm_mode_config_cleanup(drm_dev);
drm_dev->dev_private = NULL;
err_free:
drm_dev_unref(drm_dev);
return ret;
}
static void rockchip_drm_unbind(struct device *dev)
{
struct drm_device *drm_dev = dev_get_drvdata(dev);
rockchip_drm_fbdev_fini(drm_dev);
drm_vblank_cleanup(drm_dev);
drm_kms_helper_poll_fini(drm_dev);
component_unbind_all(dev, drm_dev);
if (is_support_iommu)
arm_iommu_detach_device(dev);
drm_mode_config_cleanup(drm_dev);
drm_dev->dev_private = NULL;
drm_dev_unregister(drm_dev);
drm_dev_unref(drm_dev);
dev_set_drvdata(dev, NULL);
}
static void rockchip_drm_lastclose(struct drm_device *dev)
{
struct rockchip_drm_private *priv = dev->dev_private;
drm_fb_helper_restore_fbdev_mode_unlocked(&priv->fbdev_helper);
}
static void rockchip_drm_fb_suspend(struct drm_device *drm)
{
struct rockchip_drm_private *priv = drm->dev_private;
console_lock();
drm_fb_helper_set_suspend(&priv->fbdev_helper, 1);
console_unlock();
}
static void rockchip_drm_fb_resume(struct drm_device *drm)
{
struct rockchip_drm_private *priv = drm->dev_private;
console_lock();
drm_fb_helper_set_suspend(&priv->fbdev_helper, 0);
console_unlock();
}
static int rockchip_drm_sys_suspend(struct device *dev)
{
struct drm_device *drm = dev_get_drvdata(dev);
struct rockchip_drm_private *priv = drm->dev_private;
drm_kms_helper_poll_disable(drm);
rockchip_drm_fb_suspend(drm);
priv->state = drm_atomic_helper_suspend(drm);
if (IS_ERR(priv->state)) {
rockchip_drm_fb_resume(drm);
drm_kms_helper_poll_enable(drm);
return PTR_ERR(priv->state);
}
return 0;
}
static int rockchip_drm_sys_resume(struct device *dev)
{
struct drm_device *drm = dev_get_drvdata(dev);
struct rockchip_drm_private *priv = drm->dev_private;
drm_atomic_helper_resume(drm, priv->state);
rockchip_drm_fb_resume(drm);
drm_kms_helper_poll_enable(drm);
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
struct device_node *iommu;
port = of_parse_phandle(np, "ports", i);
if (!port)
break;
if (!of_device_is_available(port->parent)) {
of_node_put(port);
continue;
}
iommu = of_parse_phandle(port->parent, "iommus", 0);
if (!iommu || !of_device_is_available(iommu->parent)) {
dev_dbg(dev, "no iommu attached for %s, using non-iommu buffers\n",
port->parent->full_name);
is_support_iommu = false;
}
of_node_put(iommu);
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
