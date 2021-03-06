static void vgem_gem_free_object(struct drm_gem_object *obj)
{
struct drm_vgem_gem_object *vgem_obj = to_vgem_bo(obj);
kvfree(vgem_obj->pages);
if (obj->import_attach)
drm_prime_gem_destroy(obj, vgem_obj->table);
drm_gem_object_release(obj);
kfree(vgem_obj);
}
static int vgem_gem_fault(struct vm_fault *vmf)
{
struct vm_area_struct *vma = vmf->vma;
struct drm_vgem_gem_object *obj = vma->vm_private_data;
unsigned long vaddr = vmf->address;
int ret;
loff_t num_pages;
pgoff_t page_offset;
page_offset = (vaddr - vma->vm_start) >> PAGE_SHIFT;
num_pages = DIV_ROUND_UP(obj->base.size, PAGE_SIZE);
if (page_offset > num_pages)
return VM_FAULT_SIGBUS;
if (obj->pages) {
get_page(obj->pages[page_offset]);
vmf->page = obj->pages[page_offset];
ret = 0;
} else {
struct page *page;
page = shmem_read_mapping_page(
file_inode(obj->base.filp)->i_mapping,
page_offset);
if (!IS_ERR(page)) {
vmf->page = page;
ret = 0;
} else switch (PTR_ERR(page)) {
case -ENOSPC:
case -ENOMEM:
ret = VM_FAULT_OOM;
break;
case -EBUSY:
ret = VM_FAULT_RETRY;
break;
case -EFAULT:
case -EINVAL:
ret = VM_FAULT_SIGBUS;
break;
default:
WARN_ON(PTR_ERR(page));
ret = VM_FAULT_SIGBUS;
break;
}
}
return ret;
}
static int vgem_open(struct drm_device *dev, struct drm_file *file)
{
struct vgem_file *vfile;
int ret;
vfile = kzalloc(sizeof(*vfile), GFP_KERNEL);
if (!vfile)
return -ENOMEM;
file->driver_priv = vfile;
ret = vgem_fence_open(vfile);
if (ret) {
kfree(vfile);
return ret;
}
return 0;
}
static void vgem_postclose(struct drm_device *dev, struct drm_file *file)
{
struct vgem_file *vfile = file->driver_priv;
vgem_fence_close(vfile);
kfree(vfile);
}
static struct drm_vgem_gem_object *__vgem_gem_create(struct drm_device *dev,
unsigned long size)
{
struct drm_vgem_gem_object *obj;
int ret;
obj = kzalloc(sizeof(*obj), GFP_KERNEL);
if (!obj)
return ERR_PTR(-ENOMEM);
ret = drm_gem_object_init(dev, &obj->base, roundup(size, PAGE_SIZE));
if (ret) {
kfree(obj);
return ERR_PTR(ret);
}
return obj;
}
static void __vgem_gem_destroy(struct drm_vgem_gem_object *obj)
{
drm_gem_object_release(&obj->base);
kfree(obj);
}
static struct drm_gem_object *vgem_gem_create(struct drm_device *dev,
struct drm_file *file,
unsigned int *handle,
unsigned long size)
{
struct drm_vgem_gem_object *obj;
int ret;
obj = __vgem_gem_create(dev, size);
if (IS_ERR(obj))
return ERR_CAST(obj);
ret = drm_gem_handle_create(file, &obj->base, handle);
drm_gem_object_unreference_unlocked(&obj->base);
if (ret)
goto err;
return &obj->base;
err:
__vgem_gem_destroy(obj);
return ERR_PTR(ret);
}
static int vgem_gem_dumb_create(struct drm_file *file, struct drm_device *dev,
struct drm_mode_create_dumb *args)
{
struct drm_gem_object *gem_object;
u64 pitch, size;
pitch = args->width * DIV_ROUND_UP(args->bpp, 8);
size = args->height * pitch;
if (size == 0)
return -EINVAL;
gem_object = vgem_gem_create(dev, file, &args->handle, size);
if (IS_ERR(gem_object))
return PTR_ERR(gem_object);
args->size = gem_object->size;
args->pitch = pitch;
DRM_DEBUG_DRIVER("Created object of size %lld\n", size);
return 0;
}
static int vgem_gem_dumb_map(struct drm_file *file, struct drm_device *dev,
uint32_t handle, uint64_t *offset)
{
struct drm_gem_object *obj;
int ret;
obj = drm_gem_object_lookup(file, handle);
if (!obj)
return -ENOENT;
if (!obj->filp) {
ret = -EINVAL;
goto unref;
}
ret = drm_gem_create_mmap_offset(obj);
if (ret)
goto unref;
*offset = drm_vma_node_offset_addr(&obj->vma_node);
unref:
drm_gem_object_unreference_unlocked(obj);
return ret;
}
static int vgem_mmap(struct file *filp, struct vm_area_struct *vma)
{
unsigned long flags = vma->vm_flags;
int ret;
ret = drm_gem_mmap(filp, vma);
if (ret)
return ret;
vma->vm_flags = flags | VM_DONTEXPAND | VM_DONTDUMP;
return 0;
}
static int vgem_prime_pin(struct drm_gem_object *obj)
{
long n_pages = obj->size >> PAGE_SHIFT;
struct page **pages;
pages = drm_gem_get_pages(obj);
if (IS_ERR(pages))
return PTR_ERR(pages);
drm_clflush_pages(pages, n_pages);
drm_gem_put_pages(obj, pages, true, false);
return 0;
}
static struct sg_table *vgem_prime_get_sg_table(struct drm_gem_object *obj)
{
struct sg_table *st;
struct page **pages;
pages = drm_gem_get_pages(obj);
if (IS_ERR(pages))
return ERR_CAST(pages);
st = drm_prime_pages_to_sg(pages, obj->size >> PAGE_SHIFT);
drm_gem_put_pages(obj, pages, false, false);
return st;
}
static struct drm_gem_object* vgem_prime_import(struct drm_device *dev,
struct dma_buf *dma_buf)
{
struct vgem_device *vgem = container_of(dev, typeof(*vgem), drm);
return drm_gem_prime_import_dev(dev, dma_buf, &vgem->platform->dev);
}
static struct drm_gem_object *vgem_prime_import_sg_table(struct drm_device *dev,
struct dma_buf_attachment *attach, struct sg_table *sg)
{
struct drm_vgem_gem_object *obj;
int npages;
obj = __vgem_gem_create(dev, attach->dmabuf->size);
if (IS_ERR(obj))
return ERR_CAST(obj);
npages = PAGE_ALIGN(attach->dmabuf->size) / PAGE_SIZE;
obj->table = sg;
obj->pages = kvmalloc_array(npages, sizeof(struct page *), GFP_KERNEL);
if (!obj->pages) {
__vgem_gem_destroy(obj);
return ERR_PTR(-ENOMEM);
}
drm_prime_sg_to_page_addr_arrays(obj->table, obj->pages, NULL,
npages);
return &obj->base;
}
static void *vgem_prime_vmap(struct drm_gem_object *obj)
{
long n_pages = obj->size >> PAGE_SHIFT;
struct page **pages;
void *addr;
pages = drm_gem_get_pages(obj);
if (IS_ERR(pages))
return NULL;
addr = vmap(pages, n_pages, 0, pgprot_writecombine(PAGE_KERNEL));
drm_gem_put_pages(obj, pages, false, false);
return addr;
}
static void vgem_prime_vunmap(struct drm_gem_object *obj, void *vaddr)
{
vunmap(vaddr);
}
static int vgem_prime_mmap(struct drm_gem_object *obj,
struct vm_area_struct *vma)
{
int ret;
if (obj->size < vma->vm_end - vma->vm_start)
return -EINVAL;
if (!obj->filp)
return -ENODEV;
ret = call_mmap(obj->filp, vma);
if (ret)
return ret;
fput(vma->vm_file);
vma->vm_file = get_file(obj->filp);
vma->vm_flags |= VM_DONTEXPAND | VM_DONTDUMP;
vma->vm_page_prot = pgprot_writecombine(vm_get_page_prot(vma->vm_flags));
return 0;
}
static void vgem_release(struct drm_device *dev)
{
struct vgem_device *vgem = container_of(dev, typeof(*vgem), drm);
platform_device_unregister(vgem->platform);
drm_dev_fini(&vgem->drm);
kfree(vgem);
}
static int __init vgem_init(void)
{
int ret;
vgem_device = kzalloc(sizeof(*vgem_device), GFP_KERNEL);
if (!vgem_device)
return -ENOMEM;
ret = drm_dev_init(&vgem_device->drm, &vgem_driver, NULL);
if (ret)
goto out_free;
vgem_device->platform =
platform_device_register_simple("vgem", -1, NULL, 0);
if (IS_ERR(vgem_device->platform)) {
ret = PTR_ERR(vgem_device->platform);
goto out_fini;
}
dma_coerce_mask_and_coherent(&vgem_device->platform->dev,
DMA_BIT_MASK(64));
ret = drm_dev_register(&vgem_device->drm, 0);
if (ret)
goto out_unregister;
return 0;
out_unregister:
platform_device_unregister(vgem_device->platform);
out_fini:
drm_dev_fini(&vgem_device->drm);
out_free:
kfree(vgem_device);
return ret;
}
static void __exit vgem_exit(void)
{
drm_dev_unregister(&vgem_device->drm);
drm_dev_unref(&vgem_device->drm);
}
