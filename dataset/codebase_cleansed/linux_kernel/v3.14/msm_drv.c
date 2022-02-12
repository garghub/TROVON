static void msm_fb_output_poll_changed(struct drm_device *dev)
{
struct msm_drm_private *priv = dev->dev_private;
if (priv->fbdev)
drm_fb_helper_hotplug_event(priv->fbdev);
}
int msm_register_mmu(struct drm_device *dev, struct msm_mmu *mmu)
{
struct msm_drm_private *priv = dev->dev_private;
int idx = priv->num_mmus++;
if (WARN_ON(idx >= ARRAY_SIZE(priv->mmus)))
return -EINVAL;
priv->mmus[idx] = mmu;
return idx;
}
void __iomem *msm_ioremap(struct platform_device *pdev, const char *name,
const char *dbgname)
{
struct resource *res;
unsigned long size;
void __iomem *ptr;
if (name)
res = platform_get_resource_byname(pdev, IORESOURCE_MEM, name);
else
res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
if (!res) {
dev_err(&pdev->dev, "failed to get memory resource: %s\n", name);
return ERR_PTR(-EINVAL);
}
size = resource_size(res);
ptr = devm_ioremap_nocache(&pdev->dev, res->start, size);
if (!ptr) {
dev_err(&pdev->dev, "failed to ioremap: %s\n", name);
return ERR_PTR(-ENOMEM);
}
if (reglog)
printk(KERN_DEBUG "IO:region %s %08x %08lx\n", dbgname, (u32)ptr, size);
return ptr;
}
void msm_writel(u32 data, void __iomem *addr)
{
if (reglog)
printk(KERN_DEBUG "IO:W %08x %08x\n", (u32)addr, data);
writel(data, addr);
}
u32 msm_readl(const void __iomem *addr)
{
u32 val = readl(addr);
if (reglog)
printk(KERN_ERR "IO:R %08x %08x\n", (u32)addr, val);
return val;
}
static int msm_unload(struct drm_device *dev)
{
struct msm_drm_private *priv = dev->dev_private;
struct msm_kms *kms = priv->kms;
struct msm_gpu *gpu = priv->gpu;
drm_kms_helper_poll_fini(dev);
drm_mode_config_cleanup(dev);
drm_vblank_cleanup(dev);
pm_runtime_get_sync(dev->dev);
drm_irq_uninstall(dev);
pm_runtime_put_sync(dev->dev);
flush_workqueue(priv->wq);
destroy_workqueue(priv->wq);
if (kms) {
pm_runtime_disable(dev->dev);
kms->funcs->destroy(kms);
}
if (gpu) {
mutex_lock(&dev->struct_mutex);
gpu->funcs->pm_suspend(gpu);
gpu->funcs->destroy(gpu);
mutex_unlock(&dev->struct_mutex);
}
if (priv->vram.paddr) {
DEFINE_DMA_ATTRS(attrs);
dma_set_attr(DMA_ATTR_NO_KERNEL_MAPPING, &attrs);
drm_mm_takedown(&priv->vram.mm);
dma_free_attrs(dev->dev, priv->vram.size, NULL,
priv->vram.paddr, &attrs);
}
dev->dev_private = NULL;
kfree(priv);
return 0;
}
static int get_mdp_ver(struct platform_device *pdev)
{
#ifdef CONFIG_OF
const static struct of_device_id match_types[] = { {
.compatible = "qcom,mdss_mdp",
.data = (void *)5,
}, {
} };
struct device *dev = &pdev->dev;
const struct of_device_id *match;
match = of_match_node(match_types, dev->of_node);
if (match)
return (int)match->data;
#endif
return 4;
}
static int msm_load(struct drm_device *dev, unsigned long flags)
{
struct platform_device *pdev = dev->platformdev;
struct msm_drm_private *priv;
struct msm_kms *kms;
int ret;
priv = kzalloc(sizeof(*priv), GFP_KERNEL);
if (!priv) {
dev_err(dev->dev, "failed to allocate private data\n");
return -ENOMEM;
}
dev->dev_private = priv;
priv->wq = alloc_ordered_workqueue("msm", 0);
init_waitqueue_head(&priv->fence_event);
INIT_LIST_HEAD(&priv->inactive_list);
INIT_LIST_HEAD(&priv->fence_cbs);
drm_mode_config_init(dev);
if (!iommu_present(&platform_bus_type)) {
DEFINE_DMA_ATTRS(attrs);
unsigned long size;
void *p;
DBG("using %s VRAM carveout", vram);
size = memparse(vram, NULL);
priv->vram.size = size;
drm_mm_init(&priv->vram.mm, 0, (size >> PAGE_SHIFT) - 1);
dma_set_attr(DMA_ATTR_NO_KERNEL_MAPPING, &attrs);
dma_set_attr(DMA_ATTR_WRITE_COMBINE, &attrs);
p = dma_alloc_attrs(dev->dev, size,
&priv->vram.paddr, 0, &attrs);
if (!p) {
dev_err(dev->dev, "failed to allocate VRAM\n");
priv->vram.paddr = 0;
ret = -ENOMEM;
goto fail;
}
dev_info(dev->dev, "VRAM: %08x->%08x\n",
(uint32_t)priv->vram.paddr,
(uint32_t)(priv->vram.paddr + size));
}
switch (get_mdp_ver(pdev)) {
case 4:
kms = mdp4_kms_init(dev);
break;
case 5:
kms = mdp5_kms_init(dev);
break;
default:
kms = ERR_PTR(-ENODEV);
break;
}
if (IS_ERR(kms)) {
dev_err(dev->dev, "failed to load kms\n");
ret = PTR_ERR(kms);
goto fail;
}
priv->kms = kms;
if (kms) {
pm_runtime_enable(dev->dev);
ret = kms->funcs->hw_init(kms);
if (ret) {
dev_err(dev->dev, "kms hw init failed: %d\n", ret);
goto fail;
}
}
dev->mode_config.min_width = 0;
dev->mode_config.min_height = 0;
dev->mode_config.max_width = 2048;
dev->mode_config.max_height = 2048;
dev->mode_config.funcs = &mode_config_funcs;
ret = drm_vblank_init(dev, 1);
if (ret < 0) {
dev_err(dev->dev, "failed to initialize vblank\n");
goto fail;
}
pm_runtime_get_sync(dev->dev);
ret = drm_irq_install(dev);
pm_runtime_put_sync(dev->dev);
if (ret < 0) {
dev_err(dev->dev, "failed to install IRQ handler\n");
goto fail;
}
platform_set_drvdata(pdev, dev);
#ifdef CONFIG_DRM_MSM_FBDEV
priv->fbdev = msm_fbdev_init(dev);
#endif
drm_kms_helper_poll_init(dev);
return 0;
fail:
msm_unload(dev);
return ret;
}
static void load_gpu(struct drm_device *dev)
{
struct msm_drm_private *priv = dev->dev_private;
struct msm_gpu *gpu;
if (priv->gpu)
return;
mutex_lock(&dev->struct_mutex);
gpu = a3xx_gpu_init(dev);
if (IS_ERR(gpu)) {
dev_warn(dev->dev, "failed to load a3xx gpu\n");
gpu = NULL;
}
mutex_unlock(&dev->struct_mutex);
if (gpu) {
int ret;
gpu->funcs->pm_resume(gpu);
ret = gpu->funcs->hw_init(gpu);
if (ret) {
dev_err(dev->dev, "gpu hw init failed: %d\n", ret);
gpu->funcs->destroy(gpu);
gpu = NULL;
}
}
priv->gpu = gpu;
}
static int msm_open(struct drm_device *dev, struct drm_file *file)
{
struct msm_file_private *ctx;
load_gpu(dev);
ctx = kzalloc(sizeof(*ctx), GFP_KERNEL);
if (!ctx)
return -ENOMEM;
file->driver_priv = ctx;
return 0;
}
static void msm_preclose(struct drm_device *dev, struct drm_file *file)
{
struct msm_drm_private *priv = dev->dev_private;
struct msm_file_private *ctx = file->driver_priv;
struct msm_kms *kms = priv->kms;
if (kms)
kms->funcs->preclose(kms, file);
mutex_lock(&dev->struct_mutex);
if (ctx == priv->lastctx)
priv->lastctx = NULL;
mutex_unlock(&dev->struct_mutex);
kfree(ctx);
}
static void msm_lastclose(struct drm_device *dev)
{
struct msm_drm_private *priv = dev->dev_private;
if (priv->fbdev) {
drm_modeset_lock_all(dev);
drm_fb_helper_restore_fbdev_mode(priv->fbdev);
drm_modeset_unlock_all(dev);
}
}
static irqreturn_t msm_irq(int irq, void *arg)
{
struct drm_device *dev = arg;
struct msm_drm_private *priv = dev->dev_private;
struct msm_kms *kms = priv->kms;
BUG_ON(!kms);
return kms->funcs->irq(kms);
}
static void msm_irq_preinstall(struct drm_device *dev)
{
struct msm_drm_private *priv = dev->dev_private;
struct msm_kms *kms = priv->kms;
BUG_ON(!kms);
kms->funcs->irq_preinstall(kms);
}
static int msm_irq_postinstall(struct drm_device *dev)
{
struct msm_drm_private *priv = dev->dev_private;
struct msm_kms *kms = priv->kms;
BUG_ON(!kms);
return kms->funcs->irq_postinstall(kms);
}
static void msm_irq_uninstall(struct drm_device *dev)
{
struct msm_drm_private *priv = dev->dev_private;
struct msm_kms *kms = priv->kms;
BUG_ON(!kms);
kms->funcs->irq_uninstall(kms);
}
static int msm_enable_vblank(struct drm_device *dev, int crtc_id)
{
struct msm_drm_private *priv = dev->dev_private;
struct msm_kms *kms = priv->kms;
if (!kms)
return -ENXIO;
DBG("dev=%p, crtc=%d", dev, crtc_id);
return kms->funcs->enable_vblank(kms, priv->crtcs[crtc_id]);
}
static void msm_disable_vblank(struct drm_device *dev, int crtc_id)
{
struct msm_drm_private *priv = dev->dev_private;
struct msm_kms *kms = priv->kms;
if (!kms)
return;
DBG("dev=%p, crtc=%d", dev, crtc_id);
kms->funcs->disable_vblank(kms, priv->crtcs[crtc_id]);
}
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
static int msm_debugfs_init(struct drm_minor *minor)
{
struct drm_device *dev = minor->dev;
int ret;
ret = drm_debugfs_create_files(msm_debugfs_list,
ARRAY_SIZE(msm_debugfs_list),
minor->debugfs_root, minor);
if (ret) {
dev_err(dev->dev, "could not install msm_debugfs_list\n");
return ret;
}
return ret;
}
static void msm_debugfs_cleanup(struct drm_minor *minor)
{
drm_debugfs_remove_files(msm_debugfs_list,
ARRAY_SIZE(msm_debugfs_list), minor);
}
int msm_wait_fence_interruptable(struct drm_device *dev, uint32_t fence,
struct timespec *timeout)
{
struct msm_drm_private *priv = dev->dev_private;
int ret;
if (!priv->gpu)
return 0;
if (fence > priv->gpu->submitted_fence) {
DRM_ERROR("waiting on invalid fence: %u (of %u)\n",
fence, priv->gpu->submitted_fence);
return -EINVAL;
}
if (!timeout) {
ret = fence_completed(dev, fence) ? 0 : -EBUSY;
} else {
unsigned long timeout_jiffies = timespec_to_jiffies(timeout);
unsigned long start_jiffies = jiffies;
unsigned long remaining_jiffies;
if (time_after(start_jiffies, timeout_jiffies))
remaining_jiffies = 0;
else
remaining_jiffies = timeout_jiffies - start_jiffies;
ret = wait_event_interruptible_timeout(priv->fence_event,
fence_completed(dev, fence),
remaining_jiffies);
if (ret == 0) {
DBG("timeout waiting for fence: %u (completed: %u)",
fence, priv->completed_fence);
ret = -ETIMEDOUT;
} else if (ret != -ERESTARTSYS) {
ret = 0;
}
}
return ret;
}
void msm_update_fence(struct drm_device *dev, uint32_t fence)
{
struct msm_drm_private *priv = dev->dev_private;
mutex_lock(&dev->struct_mutex);
priv->completed_fence = max(fence, priv->completed_fence);
while (!list_empty(&priv->fence_cbs)) {
struct msm_fence_cb *cb;
cb = list_first_entry(&priv->fence_cbs,
struct msm_fence_cb, work.entry);
if (cb->fence > priv->completed_fence)
break;
list_del_init(&cb->work.entry);
queue_work(priv->wq, &cb->work);
}
mutex_unlock(&dev->struct_mutex);
wake_up_all(&priv->fence_event);
}
void __msm_fence_worker(struct work_struct *work)
{
struct msm_fence_cb *cb = container_of(work, struct msm_fence_cb, work);
cb->func(cb);
}
static int msm_ioctl_get_param(struct drm_device *dev, void *data,
struct drm_file *file)
{
struct msm_drm_private *priv = dev->dev_private;
struct drm_msm_param *args = data;
struct msm_gpu *gpu;
if (args->pipe != MSM_PIPE_3D0)
return -EINVAL;
gpu = priv->gpu;
if (!gpu)
return -ENXIO;
return gpu->funcs->get_param(gpu, args->param, &args->value);
}
static int msm_ioctl_gem_new(struct drm_device *dev, void *data,
struct drm_file *file)
{
struct drm_msm_gem_new *args = data;
return msm_gem_new_handle(dev, file, args->size,
args->flags, &args->handle);
}
static int msm_ioctl_gem_cpu_prep(struct drm_device *dev, void *data,
struct drm_file *file)
{
struct drm_msm_gem_cpu_prep *args = data;
struct drm_gem_object *obj;
int ret;
obj = drm_gem_object_lookup(dev, file, args->handle);
if (!obj)
return -ENOENT;
ret = msm_gem_cpu_prep(obj, args->op, &TS(args->timeout));
drm_gem_object_unreference_unlocked(obj);
return ret;
}
static int msm_ioctl_gem_cpu_fini(struct drm_device *dev, void *data,
struct drm_file *file)
{
struct drm_msm_gem_cpu_fini *args = data;
struct drm_gem_object *obj;
int ret;
obj = drm_gem_object_lookup(dev, file, args->handle);
if (!obj)
return -ENOENT;
ret = msm_gem_cpu_fini(obj);
drm_gem_object_unreference_unlocked(obj);
return ret;
}
static int msm_ioctl_gem_info(struct drm_device *dev, void *data,
struct drm_file *file)
{
struct drm_msm_gem_info *args = data;
struct drm_gem_object *obj;
int ret = 0;
if (args->pad)
return -EINVAL;
obj = drm_gem_object_lookup(dev, file, args->handle);
if (!obj)
return -ENOENT;
args->offset = msm_gem_mmap_offset(obj);
drm_gem_object_unreference_unlocked(obj);
return ret;
}
static int msm_ioctl_wait_fence(struct drm_device *dev, void *data,
struct drm_file *file)
{
struct drm_msm_wait_fence *args = data;
return msm_wait_fence_interruptable(dev, args->fence, &TS(args->timeout));
}
static int msm_pm_suspend(struct device *dev)
{
struct drm_device *ddev = dev_get_drvdata(dev);
drm_kms_helper_poll_disable(ddev);
return 0;
}
static int msm_pm_resume(struct device *dev)
{
struct drm_device *ddev = dev_get_drvdata(dev);
drm_kms_helper_poll_enable(ddev);
return 0;
}
static int msm_pdev_probe(struct platform_device *pdev)
{
pdev->dev.coherent_dma_mask = DMA_BIT_MASK(32);
return drm_platform_init(&msm_driver, pdev);
}
static int msm_pdev_remove(struct platform_device *pdev)
{
drm_put_dev(platform_get_drvdata(pdev));
return 0;
}
static int __init msm_drm_register(void)
{
DBG("init");
hdmi_register();
a3xx_register();
return platform_driver_register(&msm_platform_driver);
}
static void __exit msm_drm_unregister(void)
{
DBG("fini");
platform_driver_unregister(&msm_platform_driver);
hdmi_unregister();
a3xx_unregister();
}
