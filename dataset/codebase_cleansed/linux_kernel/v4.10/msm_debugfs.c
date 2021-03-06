static int msm_gpu_show(struct drm_device *dev, struct seq_file *m)
{
struct msm_drm_private *priv = dev->dev_private;
struct msm_gpu *gpu = priv->gpu;
if (gpu) {
seq_printf(m, "%s Status:\n", gpu->name);
gpu->funcs->show(gpu, m);
}
return 0;
}
static int msm_gem_show(struct drm_device *dev, struct seq_file *m)
{
struct msm_drm_private *priv = dev->dev_private;
struct msm_gpu *gpu = priv->gpu;
if (gpu) {
seq_printf(m, "Active Objects (%s):\n", gpu->name);
msm_gem_describe_objects(&gpu->active_list, m);
}
seq_printf(m, "Inactive Objects:\n");
msm_gem_describe_objects(&priv->inactive_list, m);
return 0;
}
static int msm_mm_show(struct drm_device *dev, struct seq_file *m)
{
return drm_mm_dump_table(m, &dev->vma_offset_manager->vm_addr_space_mm);
}
static int msm_fb_show(struct drm_device *dev, struct seq_file *m)
{
struct msm_drm_private *priv = dev->dev_private;
struct drm_framebuffer *fb, *fbdev_fb = NULL;
if (priv->fbdev) {
seq_printf(m, "fbcon ");
fbdev_fb = priv->fbdev->fb;
msm_framebuffer_describe(fbdev_fb, m);
}
mutex_lock(&dev->mode_config.fb_lock);
list_for_each_entry(fb, &dev->mode_config.fb_list, head) {
if (fb == fbdev_fb)
continue;
seq_printf(m, "user ");
msm_framebuffer_describe(fb, m);
}
mutex_unlock(&dev->mode_config.fb_lock);
return 0;
}
static int show_locked(struct seq_file *m, void *arg)
{
struct drm_info_node *node = (struct drm_info_node *) m->private;
struct drm_device *dev = node->minor->dev;
int (*show)(struct drm_device *dev, struct seq_file *m) =
node->info_ent->data;
int ret;
ret = mutex_lock_interruptible(&dev->struct_mutex);
if (ret)
return ret;
ret = show(dev, m);
mutex_unlock(&dev->struct_mutex);
return ret;
}
static int late_init_minor(struct drm_minor *minor)
{
int ret;
if (!minor)
return 0;
ret = msm_rd_debugfs_init(minor);
if (ret) {
dev_err(minor->dev->dev, "could not install rd debugfs\n");
return ret;
}
ret = msm_perf_debugfs_init(minor);
if (ret) {
dev_err(minor->dev->dev, "could not install perf debugfs\n");
return ret;
}
return 0;
}
int msm_debugfs_late_init(struct drm_device *dev)
{
int ret;
ret = late_init_minor(dev->primary);
if (ret)
return ret;
ret = late_init_minor(dev->render);
if (ret)
return ret;
ret = late_init_minor(dev->control);
return ret;
}
int msm_debugfs_init(struct drm_minor *minor)
{
struct drm_device *dev = minor->dev;
struct msm_drm_private *priv = dev->dev_private;
int ret;
ret = drm_debugfs_create_files(msm_debugfs_list,
ARRAY_SIZE(msm_debugfs_list),
minor->debugfs_root, minor);
if (ret) {
dev_err(dev->dev, "could not install msm_debugfs_list\n");
return ret;
}
if (priv->kms->funcs->debugfs_init)
ret = priv->kms->funcs->debugfs_init(priv->kms, minor);
return ret;
}
void msm_debugfs_cleanup(struct drm_minor *minor)
{
struct drm_device *dev = minor->dev;
struct msm_drm_private *priv = dev->dev_private;
drm_debugfs_remove_files(msm_debugfs_list,
ARRAY_SIZE(msm_debugfs_list), minor);
if (!priv)
return;
if (priv->kms->funcs->debugfs_cleanup)
priv->kms->funcs->debugfs_cleanup(priv->kms, minor);
msm_rd_debugfs_cleanup(minor);
msm_perf_debugfs_cleanup(minor);
}
