static void armada_drm_unref_work(struct work_struct *work)
{
struct armada_private *priv =
container_of(work, struct armada_private, fb_unref_work);
struct drm_framebuffer *fb;
while (kfifo_get(&priv->fb_unref, &fb))
drm_framebuffer_unreference(fb);
}
void __armada_drm_queue_unref_work(struct drm_device *dev,
struct drm_framebuffer *fb)
{
struct armada_private *priv = dev->dev_private;
WARN_ON(!kfifo_put(&priv->fb_unref, fb));
schedule_work(&priv->fb_unref_work);
}
void armada_drm_queue_unref_work(struct drm_device *dev,
struct drm_framebuffer *fb)
{
unsigned long flags;
spin_lock_irqsave(&dev->event_lock, flags);
__armada_drm_queue_unref_work(dev, fb);
spin_unlock_irqrestore(&dev->event_lock, flags);
}
static int armada_drm_enable_vblank(struct drm_device *dev, unsigned int pipe)
{
struct armada_private *priv = dev->dev_private;
armada_drm_crtc_enable_irq(priv->dcrtc[pipe], VSYNC_IRQ_ENA);
return 0;
}
static void armada_drm_disable_vblank(struct drm_device *dev, unsigned int pipe)
{
struct armada_private *priv = dev->dev_private;
armada_drm_crtc_disable_irq(priv->dcrtc[pipe], VSYNC_IRQ_ENA);
}
static void armada_drm_lastclose(struct drm_device *dev)
{
armada_fbdev_lastclose(dev);
}
static int armada_drm_bind(struct device *dev)
{
struct armada_private *priv;
struct resource *mem = NULL;
int ret, n;
for (n = 0; ; n++) {
struct resource *r = platform_get_resource(to_platform_device(dev),
IORESOURCE_MEM, n);
if (!r)
break;
if (resource_size(r) > SZ_64K)
mem = r;
else
return -EINVAL;
}
if (!mem)
return -ENXIO;
if (!devm_request_mem_region(dev, mem->start, resource_size(mem),
"armada-drm"))
return -EBUSY;
priv = kzalloc(sizeof(*priv), GFP_KERNEL);
if (!priv)
return -ENOMEM;
BUILD_BUG_ON(offsetof(struct armada_private, drm) != 0);
ret = drm_dev_init(&priv->drm, &armada_drm_driver, dev);
if (ret) {
dev_err(dev, "[" DRM_NAME ":%s] drm_dev_init failed: %d\n",
__func__, ret);
kfree(priv);
return ret;
}
priv->drm.platformdev = to_platform_device(dev);
priv->drm.dev_private = priv;
platform_set_drvdata(priv->drm.platformdev, &priv->drm);
INIT_WORK(&priv->fb_unref_work, armada_drm_unref_work);
INIT_KFIFO(priv->fb_unref);
drm_mode_config_init(&priv->drm);
priv->drm.mode_config.min_width = 320;
priv->drm.mode_config.min_height = 200;
priv->drm.mode_config.max_width = 1920;
priv->drm.mode_config.max_height = 2048;
priv->drm.mode_config.preferred_depth = 24;
priv->drm.mode_config.funcs = &armada_drm_mode_config_funcs;
drm_mm_init(&priv->linear, mem->start, resource_size(mem));
mutex_init(&priv->linear_lock);
ret = component_bind_all(dev, &priv->drm);
if (ret)
goto err_kms;
ret = drm_vblank_init(&priv->drm, priv->drm.mode_config.num_crtc);
if (ret)
goto err_comp;
priv->drm.irq_enabled = true;
ret = armada_fbdev_init(&priv->drm);
if (ret)
goto err_comp;
drm_kms_helper_poll_init(&priv->drm);
ret = drm_dev_register(&priv->drm, 0);
if (ret)
goto err_poll;
#ifdef CONFIG_DEBUG_FS
armada_drm_debugfs_init(priv->drm.primary);
#endif
return 0;
err_poll:
drm_kms_helper_poll_fini(&priv->drm);
armada_fbdev_fini(&priv->drm);
err_comp:
component_unbind_all(dev, &priv->drm);
err_kms:
drm_mode_config_cleanup(&priv->drm);
drm_mm_takedown(&priv->linear);
flush_work(&priv->fb_unref_work);
drm_dev_unref(&priv->drm);
return ret;
}
static void armada_drm_unbind(struct device *dev)
{
struct drm_device *drm = dev_get_drvdata(dev);
struct armada_private *priv = drm->dev_private;
drm_kms_helper_poll_fini(&priv->drm);
armada_fbdev_fini(&priv->drm);
#ifdef CONFIG_DEBUG_FS
armada_drm_debugfs_cleanup(priv->drm.primary);
#endif
drm_dev_unregister(&priv->drm);
component_unbind_all(dev, &priv->drm);
drm_mode_config_cleanup(&priv->drm);
drm_mm_takedown(&priv->linear);
flush_work(&priv->fb_unref_work);
drm_dev_unref(&priv->drm);
}
static int compare_of(struct device *dev, void *data)
{
return dev->of_node == data;
}
static int compare_dev_name(struct device *dev, void *data)
{
const char *name = data;
return !strcmp(dev_name(dev), name);
}
static void armada_add_endpoints(struct device *dev,
struct component_match **match, struct device_node *port)
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
drm_of_component_match_add(dev, match, compare_of, remote);
of_node_put(remote);
}
}
static int armada_drm_probe(struct platform_device *pdev)
{
struct component_match *match = NULL;
struct device *dev = &pdev->dev;
int ret;
ret = drm_of_component_probe(dev, compare_dev_name, &armada_master_ops);
if (ret != -EINVAL)
return ret;
if (dev->platform_data) {
char **devices = dev->platform_data;
struct device_node *port;
struct device *d;
int i;
for (i = 0; devices[i]; i++)
component_match_add(dev, &match, compare_dev_name,
devices[i]);
if (i == 0) {
dev_err(dev, "missing 'ports' property\n");
return -ENODEV;
}
for (i = 0; devices[i]; i++) {
d = bus_find_device_by_name(&platform_bus_type, NULL,
devices[i]);
if (d && d->of_node) {
for_each_child_of_node(d->of_node, port)
armada_add_endpoints(dev, &match, port);
}
put_device(d);
}
}
return component_master_add_with_match(&pdev->dev, &armada_master_ops,
match);
}
static int armada_drm_remove(struct platform_device *pdev)
{
component_master_del(&pdev->dev, &armada_master_ops);
return 0;
}
static int __init armada_drm_init(void)
{
int ret;
armada_drm_driver.num_ioctls = ARRAY_SIZE(armada_ioctls);
ret = platform_driver_register(&armada_lcd_platform_driver);
if (ret)
return ret;
ret = platform_driver_register(&armada_drm_platform_driver);
if (ret)
platform_driver_unregister(&armada_lcd_platform_driver);
return ret;
}
static void __exit armada_drm_exit(void)
{
platform_driver_unregister(&armada_drm_platform_driver);
platform_driver_unregister(&armada_lcd_platform_driver);
}
