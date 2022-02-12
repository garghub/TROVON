void vgem_gem_put_pages(struct drm_vgem_gem_object *obj)
{
drm_gem_put_pages(&obj->base, obj->pages, false, false);
obj->pages = NULL;
}
static void vgem_gem_free_object(struct drm_gem_object *obj)
{
struct drm_vgem_gem_object *vgem_obj = to_vgem_bo(obj);
drm_gem_free_mmap_offset(obj);
if (vgem_obj->use_dma_buf && obj->dma_buf) {
dma_buf_put(obj->dma_buf);
obj->dma_buf = NULL;
}
drm_gem_object_release(obj);
if (vgem_obj->pages)
vgem_gem_put_pages(vgem_obj);
vgem_obj->pages = NULL;
kfree(vgem_obj);
}
int vgem_gem_get_pages(struct drm_vgem_gem_object *obj)
{
struct page **pages;
if (obj->pages || obj->use_dma_buf)
return 0;
pages = drm_gem_get_pages(&obj->base);
if (IS_ERR(pages)) {
return PTR_ERR(pages);
}
obj->pages = pages;
return 0;
}
static int vgem_gem_fault(struct vm_area_struct *vma, struct vm_fault *vmf)
{
struct drm_vgem_gem_object *obj = vma->vm_private_data;
struct drm_device *dev = obj->base.dev;
loff_t num_pages;
pgoff_t page_offset;
int ret;
page_offset = ((unsigned long)vmf->virtual_address - vma->vm_start) >>
PAGE_SHIFT;
num_pages = DIV_ROUND_UP(obj->base.size, PAGE_SIZE);
if (page_offset > num_pages)
return VM_FAULT_SIGBUS;
mutex_lock(&dev->struct_mutex);
ret = vm_insert_page(vma, (unsigned long)vmf->virtual_address,
obj->pages[page_offset]);
mutex_unlock(&dev->struct_mutex);
switch (ret) {
case 0:
return VM_FAULT_NOPAGE;
case -ENOMEM:
return VM_FAULT_OOM;
case -EBUSY:
return VM_FAULT_RETRY;
case -EFAULT:
case -EINVAL:
return VM_FAULT_SIGBUS;
default:
WARN_ON(1);
return VM_FAULT_SIGBUS;
}
}
static struct drm_gem_object *vgem_gem_create(struct drm_device *dev,
struct drm_file *file,
unsigned int *handle,
unsigned long size)
{
struct drm_vgem_gem_object *obj;
struct drm_gem_object *gem_object;
int err;
size = roundup(size, PAGE_SIZE);
obj = kzalloc(sizeof(*obj), GFP_KERNEL);
if (!obj)
return ERR_PTR(-ENOMEM);
gem_object = &obj->base;
err = drm_gem_object_init(dev, gem_object, size);
if (err)
goto out;
err = drm_gem_handle_create(file, gem_object, handle);
if (err)
goto handle_out;
drm_gem_object_unreference_unlocked(gem_object);
return gem_object;
handle_out:
drm_gem_object_release(gem_object);
out:
kfree(obj);
return ERR_PTR(err);
}
static int vgem_gem_dumb_create(struct drm_file *file, struct drm_device *dev,
struct drm_mode_create_dumb *args)
{
struct drm_gem_object *gem_object;
uint64_t size;
uint64_t pitch = args->width * DIV_ROUND_UP(args->bpp, 8);
size = args->height * pitch;
if (size == 0)
return -EINVAL;
gem_object = vgem_gem_create(dev, file, &args->handle, size);
if (IS_ERR(gem_object)) {
DRM_DEBUG_DRIVER("object creation failed\n");
return PTR_ERR(gem_object);
}
args->size = gem_object->size;
args->pitch = pitch;
DRM_DEBUG_DRIVER("Created object of size %lld\n", size);
return 0;
}
int vgem_gem_dumb_map(struct drm_file *file, struct drm_device *dev,
uint32_t handle, uint64_t *offset)
{
int ret = 0;
struct drm_gem_object *obj;
mutex_lock(&dev->struct_mutex);
obj = drm_gem_object_lookup(dev, file, handle);
if (!obj) {
ret = -ENOENT;
goto unlock;
}
if (!drm_vma_node_has_offset(&obj->vma_node)) {
ret = drm_gem_create_mmap_offset(obj);
if (ret)
goto unref;
}
BUG_ON(!obj->filp);
obj->filp->private_data = obj;
ret = vgem_gem_get_pages(to_vgem_bo(obj));
if (ret)
goto fail_get_pages;
*offset = drm_vma_node_offset_addr(&obj->vma_node);
goto unref;
fail_get_pages:
drm_gem_free_mmap_offset(obj);
unref:
drm_gem_object_unreference(obj);
unlock:
mutex_unlock(&dev->struct_mutex);
return ret;
}
int vgem_drm_gem_mmap(struct file *filp, struct vm_area_struct *vma)
{
struct drm_file *priv = filp->private_data;
struct drm_device *dev = priv->minor->dev;
struct drm_vma_offset_node *node;
struct drm_gem_object *obj;
struct drm_vgem_gem_object *vgem_obj;
int ret = 0;
mutex_lock(&dev->struct_mutex);
node = drm_vma_offset_exact_lookup(dev->vma_offset_manager,
vma->vm_pgoff,
vma_pages(vma));
if (!node) {
ret = -EINVAL;
goto out_unlock;
} else if (!drm_vma_node_is_allowed(node, filp)) {
ret = -EACCES;
goto out_unlock;
}
obj = container_of(node, struct drm_gem_object, vma_node);
vgem_obj = to_vgem_bo(obj);
if (obj->dma_buf && vgem_obj->use_dma_buf) {
ret = dma_buf_mmap(obj->dma_buf, vma, 0);
goto out_unlock;
}
if (!obj->dev->driver->gem_vm_ops) {
ret = -EINVAL;
goto out_unlock;
}
vma->vm_flags |= VM_IO | VM_MIXEDMAP | VM_DONTEXPAND | VM_DONTDUMP;
vma->vm_ops = obj->dev->driver->gem_vm_ops;
vma->vm_private_data = vgem_obj;
vma->vm_page_prot =
pgprot_writecombine(vm_get_page_prot(vma->vm_flags));
mutex_unlock(&dev->struct_mutex);
drm_gem_vm_open(vma);
return ret;
out_unlock:
mutex_unlock(&dev->struct_mutex);
return ret;
}
static int __init vgem_init(void)
{
int ret;
vgem_device = drm_dev_alloc(&vgem_driver, NULL);
if (!vgem_device) {
ret = -ENOMEM;
goto out;
}
ret = drm_dev_register(vgem_device, 0);
if (ret)
goto out_unref;
return 0;
out_unref:
drm_dev_unref(vgem_device);
out:
return ret;
}
static void __exit vgem_exit(void)
{
drm_dev_unregister(vgem_device);
drm_dev_unref(vgem_device);
}
