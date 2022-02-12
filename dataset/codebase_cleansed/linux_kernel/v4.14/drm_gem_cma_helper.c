static struct drm_gem_cma_object *
__drm_gem_cma_create(struct drm_device *drm, size_t size)
{
struct drm_gem_cma_object *cma_obj;
struct drm_gem_object *gem_obj;
int ret;
if (drm->driver->gem_create_object)
gem_obj = drm->driver->gem_create_object(drm, size);
else
gem_obj = kzalloc(sizeof(*cma_obj), GFP_KERNEL);
if (!gem_obj)
return ERR_PTR(-ENOMEM);
cma_obj = container_of(gem_obj, struct drm_gem_cma_object, base);
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
size_t size)
{
struct drm_gem_cma_object *cma_obj;
int ret;
size = round_up(size, PAGE_SIZE);
cma_obj = __drm_gem_cma_create(drm, size);
if (IS_ERR(cma_obj))
return cma_obj;
cma_obj->vaddr = dma_alloc_wc(drm->dev, size, &cma_obj->paddr,
GFP_KERNEL | __GFP_NOWARN);
if (!cma_obj->vaddr) {
dev_err(drm->dev, "failed to allocate buffer with size %zu\n",
size);
ret = -ENOMEM;
goto error;
}
return cma_obj;
error:
drm_gem_object_put_unlocked(&cma_obj->base);
return ERR_PTR(ret);
}
static struct drm_gem_cma_object *
drm_gem_cma_create_with_handle(struct drm_file *file_priv,
struct drm_device *drm, size_t size,
uint32_t *handle)
{
struct drm_gem_cma_object *cma_obj;
struct drm_gem_object *gem_obj;
int ret;
cma_obj = drm_gem_cma_create(drm, size);
if (IS_ERR(cma_obj))
return cma_obj;
gem_obj = &cma_obj->base;
ret = drm_gem_handle_create(file_priv, gem_obj, handle);
drm_gem_object_put_unlocked(gem_obj);
if (ret)
return ERR_PTR(ret);
return cma_obj;
}
void drm_gem_cma_free_object(struct drm_gem_object *gem_obj)
{
struct drm_gem_cma_object *cma_obj;
cma_obj = to_drm_gem_cma_obj(gem_obj);
if (cma_obj->vaddr) {
dma_free_wc(gem_obj->dev->dev, cma_obj->base.size,
cma_obj->vaddr, cma_obj->paddr);
} else if (gem_obj->import_attach) {
drm_prime_gem_destroy(gem_obj, cma_obj->sgt);
}
drm_gem_object_release(gem_obj);
kfree(cma_obj);
}
int drm_gem_cma_dumb_create_internal(struct drm_file *file_priv,
struct drm_device *drm,
struct drm_mode_create_dumb *args)
{
unsigned int min_pitch = DIV_ROUND_UP(args->width * args->bpp, 8);
struct drm_gem_cma_object *cma_obj;
if (args->pitch < min_pitch)
args->pitch = min_pitch;
if (args->size < args->pitch * args->height)
args->size = args->pitch * args->height;
cma_obj = drm_gem_cma_create_with_handle(file_priv, drm, args->size,
&args->handle);
return PTR_ERR_OR_ZERO(cma_obj);
}
int drm_gem_cma_dumb_create(struct drm_file *file_priv,
struct drm_device *drm,
struct drm_mode_create_dumb *args)
{
struct drm_gem_cma_object *cma_obj;
args->pitch = DIV_ROUND_UP(args->width * args->bpp, 8);
args->size = args->pitch * args->height;
cma_obj = drm_gem_cma_create_with_handle(file_priv, drm, args->size,
&args->handle);
return PTR_ERR_OR_ZERO(cma_obj);
}
static int drm_gem_cma_mmap_obj(struct drm_gem_cma_object *cma_obj,
struct vm_area_struct *vma)
{
int ret;
vma->vm_flags &= ~VM_PFNMAP;
vma->vm_pgoff = 0;
ret = dma_mmap_wc(cma_obj->base.dev->dev, vma, cma_obj->vaddr,
cma_obj->paddr, vma->vm_end - vma->vm_start);
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
unsigned long drm_gem_cma_get_unmapped_area(struct file *filp,
unsigned long addr,
unsigned long len,
unsigned long pgoff,
unsigned long flags)
{
struct drm_gem_cma_object *cma_obj;
struct drm_gem_object *obj = NULL;
struct drm_file *priv = filp->private_data;
struct drm_device *dev = priv->minor->dev;
struct drm_vma_offset_node *node;
if (drm_dev_is_unplugged(dev))
return -ENODEV;
drm_vma_offset_lock_lookup(dev->vma_offset_manager);
node = drm_vma_offset_exact_lookup_locked(dev->vma_offset_manager,
pgoff,
len >> PAGE_SHIFT);
if (likely(node)) {
obj = container_of(node, struct drm_gem_object, vma_node);
if (!kref_get_unless_zero(&obj->refcount))
obj = NULL;
}
drm_vma_offset_unlock_lookup(dev->vma_offset_manager);
if (!obj)
return -EINVAL;
if (!drm_vma_node_is_allowed(node, priv)) {
drm_gem_object_put_unlocked(obj);
return -EACCES;
}
cma_obj = to_drm_gem_cma_obj(obj);
drm_gem_object_put_unlocked(obj);
return cma_obj->vaddr ? (unsigned long)cma_obj->vaddr : -EINVAL;
}
void drm_gem_cma_describe(struct drm_gem_cma_object *cma_obj,
struct seq_file *m)
{
struct drm_gem_object *obj = &cma_obj->base;
uint64_t off;
off = drm_vma_node_start(&obj->vma_node);
seq_printf(m, "%2d (%2d) %08llx %pad %p %zu",
obj->name, kref_read(&obj->refcount),
off, &cma_obj->paddr, cma_obj->vaddr, obj->size);
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
drm_gem_cma_prime_import_sg_table(struct drm_device *dev,
struct dma_buf_attachment *attach,
struct sg_table *sgt)
{
struct drm_gem_cma_object *cma_obj;
if (sgt->nents != 1)
return ERR_PTR(-EINVAL);
cma_obj = __drm_gem_cma_create(dev, attach->dmabuf->size);
if (IS_ERR(cma_obj))
return ERR_CAST(cma_obj);
cma_obj->paddr = sg_dma_address(sgt->sgl);
cma_obj->sgt = sgt;
DRM_DEBUG_PRIME("dma_addr = %pad, size = %zu\n", &cma_obj->paddr, attach->dmabuf->size);
return &cma_obj->base;
}
int drm_gem_cma_prime_mmap(struct drm_gem_object *obj,
struct vm_area_struct *vma)
{
struct drm_gem_cma_object *cma_obj;
int ret;
ret = drm_gem_mmap_obj(obj, obj->size, vma);
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
