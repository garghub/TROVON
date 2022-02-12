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
static int sti_drm_debugfs_create(struct dentry *root,
struct drm_minor *minor,
const char *name,
const struct file_operations *fops)
{
struct drm_device *dev = minor->dev;
struct drm_info_node *node;
struct dentry *ent;
ent = debugfs_create_file(name, S_IRUGO | S_IWUSR, root, dev, fops);
if (IS_ERR(ent))
return PTR_ERR(ent);
node = kmalloc(sizeof(*node), GFP_KERNEL);
if (!node) {
debugfs_remove(ent);
return -ENOMEM;
}
node->minor = minor;
node->dent = ent;
node->info_ent = (void *)fops;
mutex_lock(&minor->debugfs_lock);
list_add(&node->list, &minor->debugfs_list);
mutex_unlock(&minor->debugfs_lock);
return 0;
}
static int sti_drm_dbg_init(struct drm_minor *minor)
{
int ret;
ret = drm_debugfs_create_files(sti_drm_dbg_list,
ARRAY_SIZE(sti_drm_dbg_list),
minor->debugfs_root, minor);
if (ret)
goto err;
ret = sti_drm_debugfs_create(minor->debugfs_root, minor, "fps_show",
&sti_drm_fps_fops);
if (ret)
goto err;
DRM_INFO("%s: debugfs installed\n", DRIVER_NAME);
return 0;
err:
DRM_ERROR("%s: cannot install debugfs\n", DRIVER_NAME);
return ret;
}
static void sti_drm_dbg_cleanup(struct drm_minor *minor)
{
drm_debugfs_remove_files(sti_drm_dbg_list,
ARRAY_SIZE(sti_drm_dbg_list), minor);
drm_debugfs_remove_files((struct drm_info_list *)&sti_drm_fps_fops,
1, minor);
}
static void sti_atomic_schedule(struct sti_private *private,
struct drm_atomic_state *state)
{
private->commit.state = state;
schedule_work(&private->commit.work);
}
static void sti_atomic_complete(struct sti_private *private,
struct drm_atomic_state *state)
{
struct drm_device *drm = private->drm_dev;
drm_atomic_helper_commit_modeset_disables(drm, state);
drm_atomic_helper_commit_planes(drm, state, 0);
drm_atomic_helper_commit_modeset_enables(drm, state);
drm_atomic_helper_wait_for_vblanks(drm, state);
drm_atomic_helper_cleanup_planes(drm, state);
drm_atomic_state_put(state);
}
static void sti_atomic_work(struct work_struct *work)
{
struct sti_private *private = container_of(work,
struct sti_private, commit.work);
sti_atomic_complete(private, private->commit.state);
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
static int sti_atomic_commit(struct drm_device *drm,
struct drm_atomic_state *state, bool nonblock)
{
struct sti_private *private = drm->dev_private;
int err;
err = drm_atomic_helper_prepare_planes(drm, state);
if (err)
return err;
mutex_lock(&private->commit.lock);
flush_work(&private->commit.work);
drm_atomic_helper_swap_state(state, true);
drm_atomic_state_get(state);
if (nonblock)
sti_atomic_schedule(private, state);
else
sti_atomic_complete(private, state);
mutex_unlock(&private->commit.lock);
return 0;
}
static void sti_output_poll_changed(struct drm_device *ddev)
{
struct sti_private *private = ddev->dev_private;
if (!ddev->mode_config.num_connector)
return;
if (private->fbdev) {
drm_fbdev_cma_hotplug_event(private->fbdev);
return;
}
private->fbdev = drm_fbdev_cma_init(ddev, 32,
ddev->mode_config.num_crtc,
ddev->mode_config.num_connector);
if (IS_ERR(private->fbdev))
private->fbdev = NULL;
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
mutex_init(&private->commit.lock);
INIT_WORK(&private->commit.work, sti_atomic_work);
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
kfree(private);
ddev->dev_private = NULL;
}
static int sti_bind(struct device *dev)
{
struct drm_device *ddev;
int ret;
ddev = drm_dev_alloc(&sti_driver, dev);
if (IS_ERR(ddev))
return PTR_ERR(ddev);
ddev->platformdev = to_platform_device(dev);
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
of_platform_populate(node, NULL, NULL, dev);
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
of_platform_depopulate(&pdev->dev);
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
