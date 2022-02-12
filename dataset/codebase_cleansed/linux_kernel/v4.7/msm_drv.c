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
printk(KERN_DEBUG "IO:region %s %p %08lx\n", dbgname, ptr, size);
return ptr;
}
void msm_writel(u32 data, void __iomem *addr)
{
if (reglog)
printk(KERN_DEBUG "IO:W %p %08x\n", addr, data);
writel(data, addr);
}
u32 msm_readl(const void __iomem *addr)
{
u32 val = readl(addr);
if (reglog)
printk(KERN_ERR "IO:R %p %08x\n", addr, val);
return val;
}
static void vblank_ctrl_worker(struct work_struct *work)
{
struct msm_vblank_ctrl *vbl_ctrl = container_of(work,
struct msm_vblank_ctrl, work);
struct msm_drm_private *priv = container_of(vbl_ctrl,
struct msm_drm_private, vblank_ctrl);
struct msm_kms *kms = priv->kms;
struct vblank_event *vbl_ev, *tmp;
unsigned long flags;
spin_lock_irqsave(&vbl_ctrl->lock, flags);
list_for_each_entry_safe(vbl_ev, tmp, &vbl_ctrl->event_list, node) {
list_del(&vbl_ev->node);
spin_unlock_irqrestore(&vbl_ctrl->lock, flags);
if (vbl_ev->enable)
kms->funcs->enable_vblank(kms,
priv->crtcs[vbl_ev->crtc_id]);
else
kms->funcs->disable_vblank(kms,
priv->crtcs[vbl_ev->crtc_id]);
kfree(vbl_ev);
spin_lock_irqsave(&vbl_ctrl->lock, flags);
}
spin_unlock_irqrestore(&vbl_ctrl->lock, flags);
}
static int vblank_ctrl_queue_work(struct msm_drm_private *priv,
int crtc_id, bool enable)
{
struct msm_vblank_ctrl *vbl_ctrl = &priv->vblank_ctrl;
struct vblank_event *vbl_ev;
unsigned long flags;
vbl_ev = kzalloc(sizeof(*vbl_ev), GFP_ATOMIC);
if (!vbl_ev)
return -ENOMEM;
vbl_ev->crtc_id = crtc_id;
vbl_ev->enable = enable;
spin_lock_irqsave(&vbl_ctrl->lock, flags);
list_add_tail(&vbl_ev->node, &vbl_ctrl->event_list);
spin_unlock_irqrestore(&vbl_ctrl->lock, flags);
queue_work(priv->wq, &vbl_ctrl->work);
return 0;
}
static int msm_drm_uninit(struct device *dev)
{
struct platform_device *pdev = to_platform_device(dev);
struct drm_device *ddev = platform_get_drvdata(pdev);
struct msm_drm_private *priv = ddev->dev_private;
struct msm_kms *kms = priv->kms;
struct msm_gpu *gpu = priv->gpu;
struct msm_vblank_ctrl *vbl_ctrl = &priv->vblank_ctrl;
struct vblank_event *vbl_ev, *tmp;
cancel_work_sync(&vbl_ctrl->work);
list_for_each_entry_safe(vbl_ev, tmp, &vbl_ctrl->event_list, node) {
list_del(&vbl_ev->node);
kfree(vbl_ev);
}
drm_kms_helper_poll_fini(ddev);
drm_connector_unregister_all(ddev);
drm_dev_unregister(ddev);
#ifdef CONFIG_DRM_FBDEV_EMULATION
if (fbdev && priv->fbdev)
msm_fbdev_free(ddev);
#endif
drm_mode_config_cleanup(ddev);
pm_runtime_get_sync(dev);
drm_irq_uninstall(ddev);
pm_runtime_put_sync(dev);
flush_workqueue(priv->wq);
destroy_workqueue(priv->wq);
flush_workqueue(priv->atomic_wq);
destroy_workqueue(priv->atomic_wq);
if (kms) {
pm_runtime_disable(dev);
kms->funcs->destroy(kms);
}
if (gpu) {
mutex_lock(&ddev->struct_mutex);
gpu->funcs->pm_suspend(gpu);
mutex_unlock(&ddev->struct_mutex);
gpu->funcs->destroy(gpu);
}
if (priv->vram.paddr) {
DEFINE_DMA_ATTRS(attrs);
dma_set_attr(DMA_ATTR_NO_KERNEL_MAPPING, &attrs);
drm_mm_takedown(&priv->vram.mm);
dma_free_attrs(dev, priv->vram.size, NULL,
priv->vram.paddr, &attrs);
}
component_unbind_all(dev, ddev);
ddev->dev_private = NULL;
drm_dev_unref(ddev);
kfree(priv);
return 0;
}
static int get_mdp_ver(struct platform_device *pdev)
{
struct device *dev = &pdev->dev;
return (int) (unsigned long) of_device_get_match_data(dev);
}
static int msm_init_vram(struct drm_device *dev)
{
struct msm_drm_private *priv = dev->dev_private;
struct device_node *node;
unsigned long size = 0;
int ret = 0;
node = of_parse_phandle(dev->dev->of_node, "memory-region", 0);
if (node) {
struct resource r;
ret = of_address_to_resource(node, 0, &r);
if (ret)
return ret;
size = r.end - r.start;
DRM_INFO("using VRAM carveout: %lx@%pa\n", size, &r.start);
} else if (!iommu_present(&platform_bus_type)) {
DRM_INFO("using %s VRAM carveout\n", vram);
size = memparse(vram, NULL);
}
if (size) {
DEFINE_DMA_ATTRS(attrs);
void *p;
priv->vram.size = size;
drm_mm_init(&priv->vram.mm, 0, (size >> PAGE_SHIFT) - 1);
dma_set_attr(DMA_ATTR_NO_KERNEL_MAPPING, &attrs);
dma_set_attr(DMA_ATTR_WRITE_COMBINE, &attrs);
p = dma_alloc_attrs(dev->dev, size,
&priv->vram.paddr, GFP_KERNEL, &attrs);
if (!p) {
dev_err(dev->dev, "failed to allocate VRAM\n");
priv->vram.paddr = 0;
return -ENOMEM;
}
dev_info(dev->dev, "VRAM: %08x->%08x\n",
(uint32_t)priv->vram.paddr,
(uint32_t)(priv->vram.paddr + size));
}
return ret;
}
static int msm_drm_init(struct device *dev, struct drm_driver *drv)
{
struct platform_device *pdev = to_platform_device(dev);
struct drm_device *ddev;
struct msm_drm_private *priv;
struct msm_kms *kms;
int ret;
ddev = drm_dev_alloc(drv, dev);
if (!ddev) {
dev_err(dev, "failed to allocate drm_device\n");
return -ENOMEM;
}
platform_set_drvdata(pdev, ddev);
ddev->platformdev = pdev;
priv = kzalloc(sizeof(*priv), GFP_KERNEL);
if (!priv) {
drm_dev_unref(ddev);
return -ENOMEM;
}
ddev->dev_private = priv;
priv->wq = alloc_ordered_workqueue("msm", 0);
priv->atomic_wq = alloc_ordered_workqueue("msm:atomic", 0);
init_waitqueue_head(&priv->pending_crtcs_event);
INIT_LIST_HEAD(&priv->inactive_list);
INIT_LIST_HEAD(&priv->vblank_ctrl.event_list);
INIT_WORK(&priv->vblank_ctrl.work, vblank_ctrl_worker);
spin_lock_init(&priv->vblank_ctrl.lock);
drm_mode_config_init(ddev);
ret = component_bind_all(dev, ddev);
if (ret) {
kfree(priv);
drm_dev_unref(ddev);
return ret;
}
ret = msm_init_vram(ddev);
if (ret)
goto fail;
switch (get_mdp_ver(pdev)) {
case 4:
kms = mdp4_kms_init(ddev);
break;
case 5:
kms = mdp5_kms_init(ddev);
break;
default:
kms = ERR_PTR(-ENODEV);
break;
}
if (IS_ERR(kms)) {
dev_err(dev, "failed to load kms\n");
ret = PTR_ERR(kms);
goto fail;
}
priv->kms = kms;
if (kms) {
pm_runtime_enable(dev);
ret = kms->funcs->hw_init(kms);
if (ret) {
dev_err(dev, "kms hw init failed: %d\n", ret);
goto fail;
}
}
ddev->mode_config.funcs = &mode_config_funcs;
ret = drm_vblank_init(ddev, priv->num_crtcs);
if (ret < 0) {
dev_err(dev, "failed to initialize vblank\n");
goto fail;
}
pm_runtime_get_sync(dev);
ret = drm_irq_install(ddev, platform_get_irq(pdev, 0));
pm_runtime_put_sync(dev);
if (ret < 0) {
dev_err(dev, "failed to install IRQ handler\n");
goto fail;
}
ret = drm_dev_register(ddev, 0);
if (ret)
goto fail;
ret = drm_connector_register_all(ddev);
if (ret) {
dev_err(dev, "failed to register connectors\n");
goto fail;
}
drm_mode_config_reset(ddev);
#ifdef CONFIG_DRM_FBDEV_EMULATION
if (fbdev)
priv->fbdev = msm_fbdev_init(ddev);
#endif
ret = msm_debugfs_late_init(ddev);
if (ret)
goto fail;
drm_kms_helper_poll_init(ddev);
return 0;
fail:
msm_drm_uninit(dev);
return ret;
}
static void load_gpu(struct drm_device *dev)
{
static DEFINE_MUTEX(init_lock);
struct msm_drm_private *priv = dev->dev_private;
mutex_lock(&init_lock);
if (!priv->gpu)
priv->gpu = adreno_load_gpu(dev);
mutex_unlock(&init_lock);
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
mutex_lock(&dev->struct_mutex);
if (ctx == priv->lastctx)
priv->lastctx = NULL;
mutex_unlock(&dev->struct_mutex);
kfree(ctx);
}
static void msm_lastclose(struct drm_device *dev)
{
struct msm_drm_private *priv = dev->dev_private;
if (priv->fbdev)
drm_fb_helper_restore_fbdev_mode_unlocked(priv->fbdev);
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
static int msm_enable_vblank(struct drm_device *dev, unsigned int pipe)
{
struct msm_drm_private *priv = dev->dev_private;
struct msm_kms *kms = priv->kms;
if (!kms)
return -ENXIO;
DBG("dev=%p, crtc=%u", dev, pipe);
return vblank_ctrl_queue_work(priv, pipe, true);
}
static void msm_disable_vblank(struct drm_device *dev, unsigned int pipe)
{
struct msm_drm_private *priv = dev->dev_private;
struct msm_kms *kms = priv->kms;
if (!kms)
return;
DBG("dev=%p, crtc=%u", dev, pipe);
vblank_ctrl_queue_work(priv, pipe, false);
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
if (args->flags & ~MSM_BO_FLAGS) {
DRM_ERROR("invalid flags: %08x\n", args->flags);
return -EINVAL;
}
return msm_gem_new_handle(dev, file, args->size,
args->flags, &args->handle);
}
static inline ktime_t to_ktime(struct drm_msm_timespec timeout)
{
return ktime_set(timeout.tv_sec, timeout.tv_nsec);
}
static int msm_ioctl_gem_cpu_prep(struct drm_device *dev, void *data,
struct drm_file *file)
{
struct drm_msm_gem_cpu_prep *args = data;
struct drm_gem_object *obj;
ktime_t timeout = to_ktime(args->timeout);
int ret;
if (args->op & ~MSM_PREP_FLAGS) {
DRM_ERROR("invalid op: %08x\n", args->op);
return -EINVAL;
}
obj = drm_gem_object_lookup(file, args->handle);
if (!obj)
return -ENOENT;
ret = msm_gem_cpu_prep(obj, args->op, &timeout);
drm_gem_object_unreference_unlocked(obj);
return ret;
}
static int msm_ioctl_gem_cpu_fini(struct drm_device *dev, void *data,
struct drm_file *file)
{
struct drm_msm_gem_cpu_fini *args = data;
struct drm_gem_object *obj;
int ret;
obj = drm_gem_object_lookup(file, args->handle);
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
obj = drm_gem_object_lookup(file, args->handle);
if (!obj)
return -ENOENT;
args->offset = msm_gem_mmap_offset(obj);
drm_gem_object_unreference_unlocked(obj);
return ret;
}
static int msm_ioctl_wait_fence(struct drm_device *dev, void *data,
struct drm_file *file)
{
struct msm_drm_private *priv = dev->dev_private;
struct drm_msm_wait_fence *args = data;
ktime_t timeout = to_ktime(args->timeout);
if (args->pad) {
DRM_ERROR("invalid pad: %08x\n", args->pad);
return -EINVAL;
}
if (!priv->gpu)
return 0;
return msm_wait_fence(priv->gpu->fctx, args->fence, &timeout, true);
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
static int compare_of(struct device *dev, void *data)
{
return dev->of_node == data;
}
static int add_components(struct device *dev, struct component_match **matchptr,
const char *name)
{
struct device_node *np = dev->of_node;
unsigned i;
for (i = 0; ; i++) {
struct device_node *node;
node = of_parse_phandle(np, name, i);
if (!node)
break;
component_match_add(dev, matchptr, compare_of, node);
}
return 0;
}
static int msm_drm_bind(struct device *dev)
{
return msm_drm_init(dev, &msm_driver);
}
static void msm_drm_unbind(struct device *dev)
{
msm_drm_uninit(dev);
}
static int msm_pdev_probe(struct platform_device *pdev)
{
struct component_match *match = NULL;
add_components(&pdev->dev, &match, "connectors");
add_components(&pdev->dev, &match, "gpus");
pdev->dev.coherent_dma_mask = DMA_BIT_MASK(32);
return component_master_add_with_match(&pdev->dev, &msm_drm_ops, match);
}
static int msm_pdev_remove(struct platform_device *pdev)
{
component_master_del(&pdev->dev, &msm_drm_ops);
return 0;
}
static int __init msm_drm_register(void)
{
DBG("init");
msm_dsi_register();
msm_edp_register();
msm_hdmi_register();
adreno_register();
return platform_driver_register(&msm_platform_driver);
}
static void __exit msm_drm_unregister(void)
{
DBG("fini");
platform_driver_unregister(&msm_platform_driver);
msm_hdmi_unregister();
adreno_unregister();
msm_edp_unregister();
msm_dsi_unregister();
}
