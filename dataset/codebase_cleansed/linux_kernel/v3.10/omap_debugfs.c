static int gem_show(struct seq_file *m, void *arg)
{
struct drm_info_node *node = (struct drm_info_node *) m->private;
struct drm_device *dev = node->minor->dev;
struct omap_drm_private *priv = dev->dev_private;
int ret;
ret = mutex_lock_interruptible(&dev->struct_mutex);
if (ret)
return ret;
seq_printf(m, "All Objects:\n");
omap_gem_describe_objects(&priv->obj_list, m);
mutex_unlock(&dev->struct_mutex);
return 0;
}
static int mm_show(struct seq_file *m, void *arg)
{
struct drm_info_node *node = (struct drm_info_node *) m->private;
struct drm_device *dev = node->minor->dev;
return drm_mm_dump_table(m, dev->mm_private);
}
static int fb_show(struct seq_file *m, void *arg)
{
struct drm_info_node *node = (struct drm_info_node *) m->private;
struct drm_device *dev = node->minor->dev;
struct omap_drm_private *priv = dev->dev_private;
struct drm_framebuffer *fb;
seq_printf(m, "fbcon ");
omap_framebuffer_describe(priv->fbdev->fb, m);
mutex_lock(&dev->mode_config.fb_lock);
list_for_each_entry(fb, &dev->mode_config.fb_list, head) {
if (fb == priv->fbdev->fb)
continue;
seq_printf(m, "user ");
omap_framebuffer_describe(fb, m);
}
mutex_unlock(&dev->mode_config.fb_lock);
return 0;
}
int omap_debugfs_init(struct drm_minor *minor)
{
struct drm_device *dev = minor->dev;
int ret;
ret = drm_debugfs_create_files(omap_debugfs_list,
ARRAY_SIZE(omap_debugfs_list),
minor->debugfs_root, minor);
if (ret) {
dev_err(dev->dev, "could not install omap_debugfs_list\n");
return ret;
}
if (dmm_is_available())
ret = drm_debugfs_create_files(omap_dmm_debugfs_list,
ARRAY_SIZE(omap_dmm_debugfs_list),
minor->debugfs_root, minor);
if (ret) {
dev_err(dev->dev, "could not install omap_dmm_debugfs_list\n");
return ret;
}
return ret;
}
void omap_debugfs_cleanup(struct drm_minor *minor)
{
drm_debugfs_remove_files(omap_debugfs_list,
ARRAY_SIZE(omap_debugfs_list), minor);
if (dmm_is_available())
drm_debugfs_remove_files(omap_dmm_debugfs_list,
ARRAY_SIZE(omap_dmm_debugfs_list), minor);
}
