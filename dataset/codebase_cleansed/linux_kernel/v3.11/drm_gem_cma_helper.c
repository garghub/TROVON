static unsigned int get_gem_mmap_offset(struct drm_gem_object *obj)
{
return (unsigned int)obj->map_list.hash.key << PAGE_SHIFT;
}
static struct drm_gem_cma_object *
__drm_gem_cma_create(struct drm_device *drm, unsigned int size)
{
struct drm_gem_cma_object *cma_obj;
struct drm_gem_object *gem_obj;
int ret;
cma_obj = kzalloc(sizeof(*cma_obj), GFP_KERNEL);
if (!cma_obj)
return ERR_PTR(-ENOMEM);
gem_obj = &cma_obj->base;
ret = drm_gem_object_init(drm, gem_obj, size);
if (ret)
goto error;
ret = drm_gem_create_mmap_offset(gem_obj);
if (ret) {
drm_gem_object_release(gem_obj);
goto error;
}
return cma_obj;
error:
kfree(cma_obj);
return ERR_PTR(ret);
}
struct drm_gem_cma_object *drm_gem_cma_create(struct drm_device *drm,
unsigned int size)
{
struct drm_gem_cma_object *cma_obj;
struct sg_table *sgt = NULL;
int ret;
size = round_up(size, PAGE_SIZE);
cma_obj = __drm_gem_cma_create(drm, size);
if (IS_ERR(cma_obj))
return cma_obj;
cma_obj->vaddr = dma_alloc_writecombine(drm->dev, size,
&cma_obj->paddr, GFP_KERNEL | __GFP_NOWARN);
if (!cma_obj->vaddr) {
dev_err(drm->dev, "failed to allocate buffer with size %d\n",
size);
ret = -ENOMEM;
goto error;
}
sgt = kzalloc(sizeof(*cma_obj->sgt), GFP_KERNEL);
if (sgt == NULL) {
ret = -ENOMEM;
goto error;
}
ret = dma_get_sgtable(drm->dev, sgt, cma_obj->vaddr,
cma_obj->paddr, size);
if (ret < 0)
goto error;
cma_obj->sgt = sgt;
return cma_obj;
error:
kfree(sgt);
drm_gem_cma_free_object(&cma_obj->base);
return ERR_PTR(ret);
}
static struct drm_gem_cma_object *drm_gem_cma_create_with_handle(
struct drm_file *file_priv,
struct drm_device *drm, unsigned int size,
unsigned int *handle)
{
struct drm_gem_cma_object *cma_obj;
struct drm_gem_object *gem_obj;
int ret;
cma_obj = drm_gem_cma_create(drm, size);
if (IS_ERR(cma_obj))
return cma_obj;
gem_obj = &cma_obj->base;
ret = drm_gem_handle_create(file_priv, gem_obj, handle);
if (ret)
goto err_handle_create;
drm_gem_object_unreference_unlocked(gem_obj);
return cma_obj;
err_handle_create:
drm_gem_cma_free_object(gem_obj);
return ERR_PTR(ret);
}
void drm_gem_cma_free_object(struct drm_gem_object *gem_obj)
{
struct drm_gem_cma_object *cma_obj;
if (gem_obj->map_list.map)
drm_gem_free_mmap_offset(gem_obj);
cma_obj = to_drm_gem_cma_obj(gem_obj);
if (cma_obj->vaddr) {
dma_free_writecombine(gem_obj->dev->dev, cma_obj->base.size,
cma_obj->vaddr, cma_obj->paddr);
if (cma_obj->sgt) {
sg_free_table(cma_obj->sgt);
kfree(cma_obj->sgt);
}
} else if (gem_obj->import_attach) {
drm_prime_gem_destroy(gem_obj, cma_obj->sgt);
}
drm_gem_object_release(gem_obj);
kfree(cma_obj);
}
int drm_gem_cma_dumb_create(struct drm_file *file_priv,
struct drm_device *dev, struct drm_mode_create_dumb *args)
{
struct drm_gem_cma_object *cma_obj;
int min_pitch = DIV_ROUND_UP(args->width * args->bpp, 8);
if (args->pitch < min_pitch)
args->pitch = min_pitch;
if (args->size < args->pitch * args->height)
args->size = args->pitch * args->height;
cma_obj = drm_gem_cma_create_with_handle(file_priv, dev,
args->size, &args->handle);
return PTR_RET(cma_obj);
}
int drm_gem_cma_dumb_map_offset(struct drm_file *file_priv,
struct drm_device *drm, uint32_t handle, uint64_t *offset)
{
struct drm_gem_object *gem_obj;
mutex_lock(&drm->struct_mutex);
gem_obj = drm_gem_object_lookup(drm, file_priv, handle);
if (!gem_obj) {
dev_err(drm->dev, "failed to lookup gem object\n");
mutex_unlock(&drm->struct_mutex);
return -EINVAL;
}
*offset = get_gem_mmap_offset(gem_obj);
drm_gem_object_unreference(gem_obj);
mutex_unlock(&drm->struct_mutex);
return 0;
}
static int drm_gem_cma_mmap_obj(struct drm_gem_cma_object *cma_obj,
struct vm_area_struct *vma)
{
int ret;
ret = remap_pfn_range(vma, vma->vm_start, cma_obj->paddr >> PAGE_SHIFT,
vma->vm_end - vma->vm_start, vma->vm_page_prot);
if (ret)
drm_gem_vm_close(vma);
return ret;
}
int drm_gem_cma_mmap(struct file *filp, struct vm_area_struct *vma)
{
struct drm_gem_cma_object *cma_obj;
struct drm_gem_object *gem_obj;
int ret;
ret = drm_gem_mmap(filp, vma);
if (ret)
return ret;
gem_obj = vma->vm_private_data;
cma_obj = to_drm_gem_cma_obj(gem_obj);
return drm_gem_cma_mmap_obj(cma_obj, vma);
}
int drm_gem_cma_dumb_destroy(struct drm_file *file_priv,
struct drm_device *drm, unsigned int handle)
{
return drm_gem_handle_delete(file_priv, handle);
}
void drm_gem_cma_describe(struct drm_gem_cma_object *cma_obj, struct seq_file *m)
{
struct drm_gem_object *obj = &cma_obj->base;
struct drm_device *dev = obj->dev;
uint64_t off = 0;
WARN_ON(!mutex_is_locked(&dev->struct_mutex));
if (obj->map_list.map)
off = (uint64_t)obj->map_list.hash.key;
seq_printf(m, "%2d (%2d) %08llx %08Zx %p %d",
obj->name, obj->refcount.refcount.counter,
off, cma_obj->paddr, cma_obj->vaddr, obj->size);
seq_printf(m, "\n");
}
struct sg_table *drm_gem_cma_prime_get_sg_table(struct drm_gem_object *obj)
{
struct drm_gem_cma_object *cma_obj = to_drm_gem_cma_obj(obj);
struct sg_table *sgt;
int ret;
sgt = kzalloc(sizeof(*sgt), GFP_KERNEL);
if (!sgt)
return NULL;
ret = dma_get_sgtable(obj->dev->dev, sgt, cma_obj->vaddr,
cma_obj->paddr, obj->size);
if (ret < 0)
goto out;
return sgt;
out:
kfree(sgt);
return NULL;
}
struct drm_gem_object *
drm_gem_cma_prime_import_sg_table(struct drm_device *dev, size_t size,
struct sg_table *sgt)
{
struct drm_gem_cma_object *cma_obj;
if (sgt->nents != 1)
return ERR_PTR(-EINVAL);
cma_obj = __drm_gem_cma_create(dev, size);
if (IS_ERR(cma_obj))
return ERR_PTR(PTR_ERR(cma_obj));
cma_obj->paddr = sg_dma_address(sgt->sgl);
cma_obj->sgt = sgt;
DRM_DEBUG_PRIME("dma_addr = 0x%x, size = %zu\n", cma_obj->paddr, size);
return &cma_obj->base;
}
int drm_gem_cma_prime_mmap(struct drm_gem_object *obj,
struct vm_area_struct *vma)
{
struct drm_gem_cma_object *cma_obj;
struct drm_device *dev = obj->dev;
int ret;
mutex_lock(&dev->struct_mutex);
ret = drm_gem_mmap_obj(obj, obj->size, vma);
mutex_unlock(&dev->struct_mutex);
if (ret < 0)
return ret;
cma_obj = to_drm_gem_cma_obj(obj);
return drm_gem_cma_mmap_obj(cma_obj, vma);
}
void *drm_gem_cma_prime_vmap(struct drm_gem_object *obj)
{
struct drm_gem_cma_object *cma_obj = to_drm_gem_cma_obj(obj);
return cma_obj->vaddr;
}
void drm_gem_cma_prime_vunmap(struct drm_gem_object *obj, void *vaddr)
{
}
