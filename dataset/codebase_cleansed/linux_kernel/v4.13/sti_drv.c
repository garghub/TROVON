static int sti_drm_fps_get(void *data, u64 *val)
{
struct drm_device *drm_dev = data;
struct drm_plane *p;
unsigned int i = 0;
*val = 0;
list_for_each_entry(p, &drm_dev->mode_config.plane_list, head) {
struct sti_plane *plane = to_sti_plane(p);
*val |= plane->fps_info.output << i;
i++;
}
return 0;
}
static int sti_drm_fps_set(void *data, u64 val)
{
struct drm_device *drm_dev = data;
struct drm_plane *p;
unsigned int i = 0;
list_for_each_entry(p, &drm_dev->mode_config.plane_list, head) {
struct sti_plane *plane = to_sti_plane(p);
memset(&plane->fps_info, 0, sizeof(plane->fps_info));
plane->fps_info.output = (val >> i) & 1;
i++;
}
return 0;
}
static int sti_drm_fps_dbg_show(struct seq_file *s, void *data)
{
struct drm_info_node *node = s->private;
struct drm_device *dev = node->minor->dev;
struct drm_plane *p;
list_for_each_entry(p, &dev->mode_config.plane_list, head) {
struct sti_plane *plane = to_sti_plane(p);
seq_printf(s, "%s%s\n",
plane->fps_info.fps_str,
plane->fps_info.fips_str);
}
return 0;
}
static int sti_drm_dbg_init(struct drm_minor *minor)
{
struct dentry *dentry;
int ret;
ret = drm_debugfs_create_files(sti_drm_dbg_list,
ARRAY_SIZE(sti_drm_dbg_list),
minor->debugfs_root, minor);
if (ret)
goto err;
dentry = debugfs_create_file("fps_show", S_IRUGO | S_IWUSR,
minor->debugfs_root, minor->dev,
&sti_drm_fps_fops);
if (!dentry) {
ret = -ENOMEM;
goto err;
}
DRM_INFO("%s: debugfs installed\n", DRIVER_NAME);
return 0;
err:
DRM_ERROR("%s: cannot install debugfs\n", DRIVER_NAME);
return ret;
}
static int sti_atomic_check(struct drm_device *dev,
struct drm_atomic_state *state)
{
int ret;
ret = drm_atomic_helper_check_modeset(dev, state);
if (ret)
return ret;
ret = drm_atomic_normalize_zpos(dev, state);
if (ret)
return ret;
ret = drm_atomic_helper_check_planes(dev, state);
if (ret)
return ret;
return ret;
}
static void sti_output_poll_changed(struct drm_device *ddev)
{
struct sti_private *private = ddev->dev_private;
drm_fbdev_cma_hotplug_event(private->fbdev);
}
static void sti_mode_config_init(struct drm_device *dev)
{
dev->mode_config.min_width = 0;
dev->mode_config.min_height = 0;
dev->mode_config.max_width = STI_MAX_FB_WIDTH;
dev->mode_config.max_height = STI_MAX_FB_HEIGHT;
dev->mode_config.funcs = &sti_mode_config_funcs;
}
static int compare_of(struct device *dev, void *data)
{
return dev->of_node == data;
}
static int sti_init(struct drm_device *ddev)
{
struct sti_private *private;
private = kzalloc(sizeof(*private), GFP_KERNEL);
if (!private)
return -ENOMEM;
ddev->dev_private = (void *)private;
dev_set_drvdata(ddev->dev, ddev);
private->drm_dev = ddev;
drm_mode_config_init(ddev);
sti_mode_config_init(ddev);
drm_kms_helper_poll_init(ddev);
return 0;
}
static void sti_cleanup(struct drm_device *ddev)
{
struct sti_private *private = ddev->dev_private;
if (private->fbdev) {
drm_fbdev_cma_fini(private->fbdev);
private->fbdev = NULL;
}
drm_kms_helper_poll_fini(ddev);
drm_vblank_cleanup(ddev);
component_unbind_all(ddev->dev, ddev);
kfree(private);
ddev->dev_private = NULL;
}
static int sti_bind(struct device *dev)
{
struct drm_device *ddev;
struct sti_private *private;
struct drm_fbdev_cma *fbdev;
int ret;
ddev = drm_dev_alloc(&sti_driver, dev);
if (IS_ERR(ddev))
return PTR_ERR(ddev);
ret = sti_init(ddev);
if (ret)
goto err_drm_dev_unref;
ret = component_bind_all(ddev->dev, ddev);
if (ret)
goto err_cleanup;
ret = drm_dev_register(ddev, 0);
if (ret)
goto err_register;
drm_mode_config_reset(ddev);
private = ddev->dev_private;
if (ddev->mode_config.num_connector) {
fbdev = drm_fbdev_cma_init(ddev, 32,
ddev->mode_config.num_connector);
if (IS_ERR(fbdev)) {
DRM_DEBUG_DRIVER("Warning: fails to create fbdev\n");
fbdev = NULL;
}
private->fbdev = fbdev;
}
return 0;
err_register:
drm_mode_config_cleanup(ddev);
err_cleanup:
sti_cleanup(ddev);
err_drm_dev_unref:
drm_dev_unref(ddev);
return ret;
}
static void sti_unbind(struct device *dev)
{
struct drm_device *ddev = dev_get_drvdata(dev);
drm_dev_unregister(ddev);
sti_cleanup(ddev);
drm_dev_unref(ddev);
}
static int sti_platform_probe(struct platform_device *pdev)
{
struct device *dev = &pdev->dev;
struct device_node *node = dev->of_node;
struct device_node *child_np;
struct component_match *match = NULL;
dma_set_coherent_mask(dev, DMA_BIT_MASK(32));
devm_of_platform_populate(dev);
child_np = of_get_next_available_child(node, NULL);
while (child_np) {
drm_of_component_match_add(dev, &match, compare_of,
child_np);
child_np = of_get_next_available_child(node, child_np);
}
return component_master_add_with_match(dev, &sti_ops, match);
}
static int sti_platform_remove(struct platform_device *pdev)
{
component_master_del(&pdev->dev, &sti_ops);
return 0;
}
static int sti_drm_init(void)
{
return platform_register_drivers(drivers, ARRAY_SIZE(drivers));
}
static void sti_drm_exit(void)
{
platform_unregister_drivers(drivers, ARRAY_SIZE(drivers));
}
