void __iomem *etnaviv_ioremap(struct platform_device *pdev, const char *name,
const char *dbgname)
{
struct resource *res;
void __iomem *ptr;
if (name)
res = platform_get_resource_byname(pdev, IORESOURCE_MEM, name);
else
res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
ptr = devm_ioremap_resource(&pdev->dev, res);
if (IS_ERR(ptr)) {
dev_err(&pdev->dev, "failed to ioremap %s: %ld\n", name,
PTR_ERR(ptr));
return ptr;
}
if (reglog)
dev_printk(KERN_DEBUG, &pdev->dev, "IO:region %s 0x%p %08zx\n",
dbgname, ptr, (size_t)resource_size(res));
return ptr;
}
void etnaviv_writel(u32 data, void __iomem *addr)
{
if (reglog)
printk(KERN_DEBUG "IO:W %p %08x\n", addr, data);
writel(data, addr);
}
u32 etnaviv_readl(const void __iomem *addr)
{
u32 val = readl(addr);
if (reglog)
printk(KERN_DEBUG "IO:R %p %08x\n", addr, val);
return val;
}
static void load_gpu(struct drm_device *dev)
{
struct etnaviv_drm_private *priv = dev->dev_private;
unsigned int i;
for (i = 0; i < ETNA_MAX_PIPES; i++) {
struct etnaviv_gpu *g = priv->gpu[i];
if (g) {
int ret;
ret = etnaviv_gpu_init(g);
if (ret)
priv->gpu[i] = NULL;
}
}
}
static int etnaviv_open(struct drm_device *dev, struct drm_file *file)
{
struct etnaviv_file_private *ctx;
ctx = kzalloc(sizeof(*ctx), GFP_KERNEL);
if (!ctx)
return -ENOMEM;
file->driver_priv = ctx;
return 0;
}
static void etnaviv_postclose(struct drm_device *dev, struct drm_file *file)
{
struct etnaviv_drm_private *priv = dev->dev_private;
struct etnaviv_file_private *ctx = file->driver_priv;
unsigned int i;
for (i = 0; i < ETNA_MAX_PIPES; i++) {
struct etnaviv_gpu *gpu = priv->gpu[i];
if (gpu) {
mutex_lock(&gpu->lock);
if (gpu->lastctx == ctx)
gpu->lastctx = NULL;
mutex_unlock(&gpu->lock);
}
}
kfree(ctx);
}
static int etnaviv_gem_show(struct drm_device *dev, struct seq_file *m)
{
struct etnaviv_drm_private *priv = dev->dev_private;
etnaviv_gem_describe_objects(priv, m);
return 0;
}
static int etnaviv_mm_show(struct drm_device *dev, struct seq_file *m)
{
struct drm_printer p = drm_seq_file_printer(m);
read_lock(&dev->vma_offset_manager->vm_lock);
drm_mm_print(&dev->vma_offset_manager->vm_addr_space_mm, &p);
read_unlock(&dev->vma_offset_manager->vm_lock);
return 0;
}
static int etnaviv_mmu_show(struct etnaviv_gpu *gpu, struct seq_file *m)
{
struct drm_printer p = drm_seq_file_printer(m);
seq_printf(m, "Active Objects (%s):\n", dev_name(gpu->dev));
mutex_lock(&gpu->mmu->lock);
drm_mm_print(&gpu->mmu->mm, &p);
mutex_unlock(&gpu->mmu->lock);
return 0;
}
static void etnaviv_buffer_dump(struct etnaviv_gpu *gpu, struct seq_file *m)
{
struct etnaviv_cmdbuf *buf = gpu->buffer;
u32 size = buf->size;
u32 *ptr = buf->vaddr;
u32 i;
seq_printf(m, "virt %p - phys 0x%llx - free 0x%08x\n",
buf->vaddr, (u64)etnaviv_cmdbuf_get_pa(buf),
size - buf->user_size);
for (i = 0; i < size / 4; i++) {
if (i && !(i % 4))
seq_puts(m, "\n");
if (i % 4 == 0)
seq_printf(m, "\t0x%p: ", ptr + i);
seq_printf(m, "%08x ", *(ptr + i));
}
seq_puts(m, "\n");
}
static int etnaviv_ring_show(struct etnaviv_gpu *gpu, struct seq_file *m)
{
seq_printf(m, "Ring Buffer (%s): ", dev_name(gpu->dev));
mutex_lock(&gpu->lock);
etnaviv_buffer_dump(gpu, m);
mutex_unlock(&gpu->lock);
return 0;
}
static int show_unlocked(struct seq_file *m, void *arg)
{
struct drm_info_node *node = (struct drm_info_node *) m->private;
struct drm_device *dev = node->minor->dev;
int (*show)(struct drm_device *dev, struct seq_file *m) =
node->info_ent->data;
return show(dev, m);
}
static int show_each_gpu(struct seq_file *m, void *arg)
{
struct drm_info_node *node = (struct drm_info_node *) m->private;
struct drm_device *dev = node->minor->dev;
struct etnaviv_drm_private *priv = dev->dev_private;
struct etnaviv_gpu *gpu;
int (*show)(struct etnaviv_gpu *gpu, struct seq_file *m) =
node->info_ent->data;
unsigned int i;
int ret = 0;
for (i = 0; i < ETNA_MAX_PIPES; i++) {
gpu = priv->gpu[i];
if (!gpu)
continue;
ret = show(gpu, m);
if (ret < 0)
break;
}
return ret;
}
static int etnaviv_debugfs_init(struct drm_minor *minor)
{
struct drm_device *dev = minor->dev;
int ret;
ret = drm_debugfs_create_files(etnaviv_debugfs_list,
ARRAY_SIZE(etnaviv_debugfs_list),
minor->debugfs_root, minor);
if (ret) {
dev_err(dev->dev, "could not install etnaviv_debugfs_list\n");
return ret;
}
return ret;
}
static int etnaviv_ioctl_get_param(struct drm_device *dev, void *data,
struct drm_file *file)
{
struct etnaviv_drm_private *priv = dev->dev_private;
struct drm_etnaviv_param *args = data;
struct etnaviv_gpu *gpu;
if (args->pipe >= ETNA_MAX_PIPES)
return -EINVAL;
gpu = priv->gpu[args->pipe];
if (!gpu)
return -ENXIO;
return etnaviv_gpu_get_param(gpu, args->param, &args->value);
}
static int etnaviv_ioctl_gem_new(struct drm_device *dev, void *data,
struct drm_file *file)
{
struct drm_etnaviv_gem_new *args = data;
if (args->flags & ~(ETNA_BO_CACHED | ETNA_BO_WC | ETNA_BO_UNCACHED |
ETNA_BO_FORCE_MMU))
return -EINVAL;
return etnaviv_gem_new_handle(dev, file, args->size,
args->flags, &args->handle);
}
static int etnaviv_ioctl_gem_cpu_prep(struct drm_device *dev, void *data,
struct drm_file *file)
{
struct drm_etnaviv_gem_cpu_prep *args = data;
struct drm_gem_object *obj;
int ret;
if (args->op & ~(ETNA_PREP_READ | ETNA_PREP_WRITE | ETNA_PREP_NOSYNC))
return -EINVAL;
obj = drm_gem_object_lookup(file, args->handle);
if (!obj)
return -ENOENT;
ret = etnaviv_gem_cpu_prep(obj, args->op, &TS(args->timeout));
drm_gem_object_unreference_unlocked(obj);
return ret;
}
static int etnaviv_ioctl_gem_cpu_fini(struct drm_device *dev, void *data,
struct drm_file *file)
{
struct drm_etnaviv_gem_cpu_fini *args = data;
struct drm_gem_object *obj;
int ret;
if (args->flags)
return -EINVAL;
obj = drm_gem_object_lookup(file, args->handle);
if (!obj)
return -ENOENT;
ret = etnaviv_gem_cpu_fini(obj);
drm_gem_object_unreference_unlocked(obj);
return ret;
}
static int etnaviv_ioctl_gem_info(struct drm_device *dev, void *data,
struct drm_file *file)
{
struct drm_etnaviv_gem_info *args = data;
struct drm_gem_object *obj;
int ret;
if (args->pad)
return -EINVAL;
obj = drm_gem_object_lookup(file, args->handle);
if (!obj)
return -ENOENT;
ret = etnaviv_gem_mmap_offset(obj, &args->offset);
drm_gem_object_unreference_unlocked(obj);
return ret;
}
static int etnaviv_ioctl_wait_fence(struct drm_device *dev, void *data,
struct drm_file *file)
{
struct drm_etnaviv_wait_fence *args = data;
struct etnaviv_drm_private *priv = dev->dev_private;
struct timespec *timeout = &TS(args->timeout);
struct etnaviv_gpu *gpu;
if (args->flags & ~(ETNA_WAIT_NONBLOCK))
return -EINVAL;
if (args->pipe >= ETNA_MAX_PIPES)
return -EINVAL;
gpu = priv->gpu[args->pipe];
if (!gpu)
return -ENXIO;
if (args->flags & ETNA_WAIT_NONBLOCK)
timeout = NULL;
return etnaviv_gpu_wait_fence_interruptible(gpu, args->fence,
timeout);
}
static int etnaviv_ioctl_gem_userptr(struct drm_device *dev, void *data,
struct drm_file *file)
{
struct drm_etnaviv_gem_userptr *args = data;
int access;
if (args->flags & ~(ETNA_USERPTR_READ|ETNA_USERPTR_WRITE) ||
args->flags == 0)
return -EINVAL;
if (offset_in_page(args->user_ptr | args->user_size) ||
(uintptr_t)args->user_ptr != args->user_ptr ||
(u32)args->user_size != args->user_size ||
args->user_ptr & ~PAGE_MASK)
return -EINVAL;
if (args->flags & ETNA_USERPTR_WRITE)
access = VERIFY_WRITE;
else
access = VERIFY_READ;
if (!access_ok(access, (void __user *)(unsigned long)args->user_ptr,
args->user_size))
return -EFAULT;
return etnaviv_gem_new_userptr(dev, file, args->user_ptr,
args->user_size, args->flags,
&args->handle);
}
static int etnaviv_ioctl_gem_wait(struct drm_device *dev, void *data,
struct drm_file *file)
{
struct etnaviv_drm_private *priv = dev->dev_private;
struct drm_etnaviv_gem_wait *args = data;
struct timespec *timeout = &TS(args->timeout);
struct drm_gem_object *obj;
struct etnaviv_gpu *gpu;
int ret;
if (args->flags & ~(ETNA_WAIT_NONBLOCK))
return -EINVAL;
if (args->pipe >= ETNA_MAX_PIPES)
return -EINVAL;
gpu = priv->gpu[args->pipe];
if (!gpu)
return -ENXIO;
obj = drm_gem_object_lookup(file, args->handle);
if (!obj)
return -ENOENT;
if (args->flags & ETNA_WAIT_NONBLOCK)
timeout = NULL;
ret = etnaviv_gem_wait_bo(gpu, obj, timeout);
drm_gem_object_unreference_unlocked(obj);
return ret;
}
static int etnaviv_bind(struct device *dev)
{
struct etnaviv_drm_private *priv;
struct drm_device *drm;
int ret;
drm = drm_dev_alloc(&etnaviv_drm_driver, dev);
if (IS_ERR(drm))
return PTR_ERR(drm);
priv = kzalloc(sizeof(*priv), GFP_KERNEL);
if (!priv) {
dev_err(dev, "failed to allocate private data\n");
ret = -ENOMEM;
goto out_unref;
}
drm->dev_private = priv;
priv->wq = alloc_ordered_workqueue("etnaviv", 0);
if (!priv->wq) {
ret = -ENOMEM;
goto out_wq;
}
mutex_init(&priv->gem_lock);
INIT_LIST_HEAD(&priv->gem_list);
priv->num_gpus = 0;
dev_set_drvdata(dev, drm);
ret = component_bind_all(dev, drm);
if (ret < 0)
goto out_bind;
load_gpu(drm);
ret = drm_dev_register(drm, 0);
if (ret)
goto out_register;
return 0;
out_register:
component_unbind_all(dev, drm);
out_bind:
flush_workqueue(priv->wq);
destroy_workqueue(priv->wq);
out_wq:
kfree(priv);
out_unref:
drm_dev_unref(drm);
return ret;
}
static void etnaviv_unbind(struct device *dev)
{
struct drm_device *drm = dev_get_drvdata(dev);
struct etnaviv_drm_private *priv = drm->dev_private;
drm_dev_unregister(drm);
flush_workqueue(priv->wq);
destroy_workqueue(priv->wq);
component_unbind_all(dev, drm);
drm->dev_private = NULL;
kfree(priv);
drm_dev_unref(drm);
}
static int compare_of(struct device *dev, void *data)
{
struct device_node *np = data;
return dev->of_node == np;
}
static int compare_str(struct device *dev, void *data)
{
return !strcmp(dev_name(dev), data);
}
static int etnaviv_pdev_probe(struct platform_device *pdev)
{
struct device *dev = &pdev->dev;
struct device_node *node = dev->of_node;
struct component_match *match = NULL;
dma_set_coherent_mask(&pdev->dev, DMA_BIT_MASK(32));
if (node) {
struct device_node *core_node;
int i;
for (i = 0; ; i++) {
core_node = of_parse_phandle(node, "cores", i);
if (!core_node)
break;
drm_of_component_match_add(&pdev->dev, &match,
compare_of, core_node);
of_node_put(core_node);
}
} else if (dev->platform_data) {
char **names = dev->platform_data;
unsigned i;
for (i = 0; names[i]; i++)
component_match_add(dev, &match, compare_str, names[i]);
}
return component_master_add_with_match(dev, &etnaviv_master_ops, match);
}
static int etnaviv_pdev_remove(struct platform_device *pdev)
{
component_master_del(&pdev->dev, &etnaviv_master_ops);
return 0;
}
static int __init etnaviv_init(void)
{
int ret;
etnaviv_validate_init();
ret = platform_driver_register(&etnaviv_gpu_driver);
if (ret != 0)
return ret;
ret = platform_driver_register(&etnaviv_platform_driver);
if (ret != 0)
platform_driver_unregister(&etnaviv_gpu_driver);
return ret;
}
static void __exit etnaviv_exit(void)
{
platform_driver_unregister(&etnaviv_gpu_driver);
platform_driver_unregister(&etnaviv_platform_driver);
}
