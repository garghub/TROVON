static unsigned int get_gem_mmap_offset(struct drm_gem_object *obj)
{
return (unsigned int)obj->map_list.hash.key << PAGE_SHIFT;
}
static void drm_gem_cma_buf_destroy(struct drm_device *drm,
struct drm_gem_cma_object *cma_obj)
{
dma_free_writecombine(drm->dev, cma_obj->base.size, cma_obj->vaddr,
cma_obj->paddr);
}
struct drm_gem_cma_object *drm_gem_cma_create(struct drm_device *drm,
unsigned int size)
{
struct drm_gem_cma_object *cma_obj;
struct drm_gem_object *gem_obj;
int ret;
size = round_up(size, PAGE_SIZE);
cma_obj = kzalloc(sizeof(*cma_obj), GFP_KERNEL);
if (!cma_obj)
return ERR_PTR(-ENOMEM);
cma_obj->vaddr = dma_alloc_writecombine(drm->dev, size,
&cma_obj->paddr, GFP_KERNEL | __GFP_NOWARN);
if (!cma_obj->vaddr) {
dev_err(drm->dev, "failed to allocate buffer with size %d\n", size);
ret = -ENOMEM;
goto err_dma_alloc;
}
gem_obj = &cma_obj->base;
ret = drm_gem_object_init(drm, gem_obj, size);
if (ret)
goto err_obj_init;
ret = drm_gem_create_mmap_offset(gem_obj);
if (ret)
goto err_create_mmap_offset;
return cma_obj;
err_create_mmap_offset:
drm_gem_object_release(gem_obj);
err_obj_init:
drm_gem_cma_buf_destroy(drm, cma_obj);
err_dma_alloc:
kfree(cma_obj);
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
drm_gem_object_release(gem_obj);
cma_obj = to_drm_gem_cma_obj(gem_obj);
drm_gem_cma_buf_destroy(gem_obj->dev, cma_obj);
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
if (IS_ERR(cma_obj))
return PTR_ERR(cma_obj);
return 0;
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
int drm_gem_cma_mmap(struct file *filp, struct vm_area_struct *vma)
{
struct drm_gem_object *gem_obj;
struct drm_gem_cma_object *cma_obj;
int ret;
ret = drm_gem_mmap(filp, vma);
if (ret)
return ret;
gem_obj = vma->vm_private_data;
cma_obj = to_drm_gem_cma_obj(gem_obj);
ret = remap_pfn_range(vma, vma->vm_start, cma_obj->paddr >> PAGE_SHIFT,
vma->vm_end - vma->vm_start, vma->vm_page_prot);
if (ret)
drm_gem_vm_close(vma);
return ret;
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
