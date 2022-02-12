int
drm_gem_init(struct drm_device *dev)
{
struct drm_vma_offset_manager *vma_offset_manager;
mutex_init(&dev->object_name_lock);
idr_init(&dev->object_name_idr);
vma_offset_manager = kzalloc(sizeof(*vma_offset_manager), GFP_KERNEL);
if (!vma_offset_manager) {
DRM_ERROR("out of memory\n");
return -ENOMEM;
}
dev->vma_offset_manager = vma_offset_manager;
drm_vma_offset_manager_init(vma_offset_manager,
DRM_FILE_PAGE_OFFSET_START,
DRM_FILE_PAGE_OFFSET_SIZE);
return 0;
}
void
drm_gem_destroy(struct drm_device *dev)
{
drm_vma_offset_manager_destroy(dev->vma_offset_manager);
kfree(dev->vma_offset_manager);
dev->vma_offset_manager = NULL;
}
int drm_gem_object_init(struct drm_device *dev,
struct drm_gem_object *obj, size_t size)
{
struct file *filp;
drm_gem_private_object_init(dev, obj, size);
filp = shmem_file_setup("drm mm object", size, VM_NORESERVE);
if (IS_ERR(filp))
return PTR_ERR(filp);
obj->filp = filp;
return 0;
}
void drm_gem_private_object_init(struct drm_device *dev,
struct drm_gem_object *obj, size_t size)
{
BUG_ON((size & (PAGE_SIZE - 1)) != 0);
obj->dev = dev;
obj->filp = NULL;
kref_init(&obj->refcount);
obj->handle_count = 0;
obj->size = size;
drm_vma_node_reset(&obj->vma_node);
}
static void
drm_gem_remove_prime_handles(struct drm_gem_object *obj, struct drm_file *filp)
{
mutex_lock(&filp->prime.lock);
if (obj->dma_buf) {
drm_prime_remove_buf_handle_locked(&filp->prime,
obj->dma_buf);
}
mutex_unlock(&filp->prime.lock);
}
static void drm_gem_object_handle_free(struct drm_gem_object *obj)
{
struct drm_device *dev = obj->dev;
if (obj->name) {
idr_remove(&dev->object_name_idr, obj->name);
obj->name = 0;
}
}
static void drm_gem_object_exported_dma_buf_free(struct drm_gem_object *obj)
{
if (obj->dma_buf) {
dma_buf_put(obj->dma_buf);
obj->dma_buf = NULL;
}
}
static void
drm_gem_object_handle_unreference_unlocked(struct drm_gem_object *obj)
{
if (WARN_ON(obj->handle_count == 0))
return;
mutex_lock(&obj->dev->object_name_lock);
if (--obj->handle_count == 0) {
drm_gem_object_handle_free(obj);
drm_gem_object_exported_dma_buf_free(obj);
}
mutex_unlock(&obj->dev->object_name_lock);
drm_gem_object_unreference_unlocked(obj);
}
int
drm_gem_handle_delete(struct drm_file *filp, u32 handle)
{
struct drm_device *dev;
struct drm_gem_object *obj;
spin_lock(&filp->table_lock);
obj = idr_find(&filp->object_idr, handle);
if (obj == NULL) {
spin_unlock(&filp->table_lock);
return -EINVAL;
}
dev = obj->dev;
idr_remove(&filp->object_idr, handle);
spin_unlock(&filp->table_lock);
if (drm_core_check_feature(dev, DRIVER_PRIME))
drm_gem_remove_prime_handles(obj, filp);
drm_vma_node_revoke(&obj->vma_node, filp->filp);
if (dev->driver->gem_close_object)
dev->driver->gem_close_object(obj, filp);
drm_gem_object_handle_unreference_unlocked(obj);
return 0;
}
int drm_gem_dumb_destroy(struct drm_file *file,
struct drm_device *dev,
uint32_t handle)
{
return drm_gem_handle_delete(file, handle);
}
int
drm_gem_handle_create_tail(struct drm_file *file_priv,
struct drm_gem_object *obj,
u32 *handlep)
{
struct drm_device *dev = obj->dev;
int ret;
WARN_ON(!mutex_is_locked(&dev->object_name_lock));
idr_preload(GFP_KERNEL);
spin_lock(&file_priv->table_lock);
ret = idr_alloc(&file_priv->object_idr, obj, 1, 0, GFP_NOWAIT);
drm_gem_object_reference(obj);
obj->handle_count++;
spin_unlock(&file_priv->table_lock);
idr_preload_end();
mutex_unlock(&dev->object_name_lock);
if (ret < 0) {
drm_gem_object_handle_unreference_unlocked(obj);
return ret;
}
*handlep = ret;
ret = drm_vma_node_allow(&obj->vma_node, file_priv->filp);
if (ret) {
drm_gem_handle_delete(file_priv, *handlep);
return ret;
}
if (dev->driver->gem_open_object) {
ret = dev->driver->gem_open_object(obj, file_priv);
if (ret) {
drm_gem_handle_delete(file_priv, *handlep);
return ret;
}
}
return 0;
}
int
drm_gem_handle_create(struct drm_file *file_priv,
struct drm_gem_object *obj,
u32 *handlep)
{
mutex_lock(&obj->dev->object_name_lock);
return drm_gem_handle_create_tail(file_priv, obj, handlep);
}
void
drm_gem_free_mmap_offset(struct drm_gem_object *obj)
{
struct drm_device *dev = obj->dev;
drm_vma_offset_remove(dev->vma_offset_manager, &obj->vma_node);
}
int
drm_gem_create_mmap_offset_size(struct drm_gem_object *obj, size_t size)
{
struct drm_device *dev = obj->dev;
return drm_vma_offset_add(dev->vma_offset_manager, &obj->vma_node,
size / PAGE_SIZE);
}
int drm_gem_create_mmap_offset(struct drm_gem_object *obj)
{
return drm_gem_create_mmap_offset_size(obj, obj->size);
}
struct page **drm_gem_get_pages(struct drm_gem_object *obj)
{
struct address_space *mapping;
struct page *p, **pages;
int i, npages;
mapping = file_inode(obj->filp)->i_mapping;
WARN_ON((obj->size & (PAGE_SIZE - 1)) != 0);
npages = obj->size >> PAGE_SHIFT;
pages = drm_malloc_ab(npages, sizeof(struct page *));
if (pages == NULL)
return ERR_PTR(-ENOMEM);
for (i = 0; i < npages; i++) {
p = shmem_read_mapping_page(mapping, i);
if (IS_ERR(p))
goto fail;
pages[i] = p;
BUG_ON((mapping_gfp_mask(mapping) & __GFP_DMA32) &&
(page_to_pfn(p) >= 0x00100000UL));
}
return pages;
fail:
while (i--)
page_cache_release(pages[i]);
drm_free_large(pages);
return ERR_CAST(p);
}
void drm_gem_put_pages(struct drm_gem_object *obj, struct page **pages,
bool dirty, bool accessed)
{
int i, npages;
WARN_ON((obj->size & (PAGE_SIZE - 1)) != 0);
npages = obj->size >> PAGE_SHIFT;
for (i = 0; i < npages; i++) {
if (dirty)
set_page_dirty(pages[i]);
if (accessed)
mark_page_accessed(pages[i]);
page_cache_release(pages[i]);
}
drm_free_large(pages);
}
struct drm_gem_object *
drm_gem_object_lookup(struct drm_device *dev, struct drm_file *filp,
u32 handle)
{
struct drm_gem_object *obj;
spin_lock(&filp->table_lock);
obj = idr_find(&filp->object_idr, handle);
if (obj == NULL) {
spin_unlock(&filp->table_lock);
return NULL;
}
drm_gem_object_reference(obj);
spin_unlock(&filp->table_lock);
return obj;
}
int
drm_gem_close_ioctl(struct drm_device *dev, void *data,
struct drm_file *file_priv)
{
struct drm_gem_close *args = data;
int ret;
if (!drm_core_check_feature(dev, DRIVER_GEM))
return -ENODEV;
ret = drm_gem_handle_delete(file_priv, args->handle);
return ret;
}
int
drm_gem_flink_ioctl(struct drm_device *dev, void *data,
struct drm_file *file_priv)
{
struct drm_gem_flink *args = data;
struct drm_gem_object *obj;
int ret;
if (!drm_core_check_feature(dev, DRIVER_GEM))
return -ENODEV;
obj = drm_gem_object_lookup(dev, file_priv, args->handle);
if (obj == NULL)
return -ENOENT;
mutex_lock(&dev->object_name_lock);
idr_preload(GFP_KERNEL);
if (obj->handle_count == 0) {
ret = -ENOENT;
goto err;
}
if (!obj->name) {
ret = idr_alloc(&dev->object_name_idr, obj, 1, 0, GFP_NOWAIT);
if (ret < 0)
goto err;
obj->name = ret;
}
args->name = (uint64_t) obj->name;
ret = 0;
err:
idr_preload_end();
mutex_unlock(&dev->object_name_lock);
drm_gem_object_unreference_unlocked(obj);
return ret;
}
int
drm_gem_open_ioctl(struct drm_device *dev, void *data,
struct drm_file *file_priv)
{
struct drm_gem_open *args = data;
struct drm_gem_object *obj;
int ret;
u32 handle;
if (!drm_core_check_feature(dev, DRIVER_GEM))
return -ENODEV;
mutex_lock(&dev->object_name_lock);
obj = idr_find(&dev->object_name_idr, (int) args->name);
if (obj) {
drm_gem_object_reference(obj);
} else {
mutex_unlock(&dev->object_name_lock);
return -ENOENT;
}
ret = drm_gem_handle_create_tail(file_priv, obj, &handle);
drm_gem_object_unreference_unlocked(obj);
if (ret)
return ret;
args->handle = handle;
args->size = obj->size;
return 0;
}
void
drm_gem_open(struct drm_device *dev, struct drm_file *file_private)
{
idr_init(&file_private->object_idr);
spin_lock_init(&file_private->table_lock);
}
static int
drm_gem_object_release_handle(int id, void *ptr, void *data)
{
struct drm_file *file_priv = data;
struct drm_gem_object *obj = ptr;
struct drm_device *dev = obj->dev;
if (drm_core_check_feature(dev, DRIVER_PRIME))
drm_gem_remove_prime_handles(obj, file_priv);
drm_vma_node_revoke(&obj->vma_node, file_priv->filp);
if (dev->driver->gem_close_object)
dev->driver->gem_close_object(obj, file_priv);
drm_gem_object_handle_unreference_unlocked(obj);
return 0;
}
void
drm_gem_release(struct drm_device *dev, struct drm_file *file_private)
{
idr_for_each(&file_private->object_idr,
&drm_gem_object_release_handle, file_private);
idr_destroy(&file_private->object_idr);
}
void
drm_gem_object_release(struct drm_gem_object *obj)
{
WARN_ON(obj->dma_buf);
if (obj->filp)
fput(obj->filp);
drm_gem_free_mmap_offset(obj);
}
void
drm_gem_object_free(struct kref *kref)
{
struct drm_gem_object *obj = (struct drm_gem_object *) kref;
struct drm_device *dev = obj->dev;
BUG_ON(!mutex_is_locked(&dev->struct_mutex));
if (dev->driver->gem_free_object != NULL)
dev->driver->gem_free_object(obj);
}
void drm_gem_vm_open(struct vm_area_struct *vma)
{
struct drm_gem_object *obj = vma->vm_private_data;
drm_gem_object_reference(obj);
mutex_lock(&obj->dev->struct_mutex);
drm_vm_open_locked(obj->dev, vma);
mutex_unlock(&obj->dev->struct_mutex);
}
void drm_gem_vm_close(struct vm_area_struct *vma)
{
struct drm_gem_object *obj = vma->vm_private_data;
struct drm_device *dev = obj->dev;
mutex_lock(&dev->struct_mutex);
drm_vm_close_locked(obj->dev, vma);
drm_gem_object_unreference(obj);
mutex_unlock(&dev->struct_mutex);
}
int drm_gem_mmap_obj(struct drm_gem_object *obj, unsigned long obj_size,
struct vm_area_struct *vma)
{
struct drm_device *dev = obj->dev;
lockdep_assert_held(&dev->struct_mutex);
if (obj_size < vma->vm_end - vma->vm_start)
return -EINVAL;
if (!dev->driver->gem_vm_ops)
return -EINVAL;
vma->vm_flags |= VM_IO | VM_PFNMAP | VM_DONTEXPAND | VM_DONTDUMP;
vma->vm_ops = dev->driver->gem_vm_ops;
vma->vm_private_data = obj;
vma->vm_page_prot = pgprot_writecombine(vm_get_page_prot(vma->vm_flags));
drm_gem_object_reference(obj);
drm_vm_open_locked(dev, vma);
return 0;
}
int drm_gem_mmap(struct file *filp, struct vm_area_struct *vma)
{
struct drm_file *priv = filp->private_data;
struct drm_device *dev = priv->minor->dev;
struct drm_gem_object *obj;
struct drm_vma_offset_node *node;
int ret;
if (drm_device_is_unplugged(dev))
return -ENODEV;
mutex_lock(&dev->struct_mutex);
node = drm_vma_offset_exact_lookup(dev->vma_offset_manager,
vma->vm_pgoff,
vma_pages(vma));
if (!node) {
mutex_unlock(&dev->struct_mutex);
return -EINVAL;
} else if (!drm_vma_node_is_allowed(node, filp)) {
mutex_unlock(&dev->struct_mutex);
return -EACCES;
}
obj = container_of(node, struct drm_gem_object, vma_node);
ret = drm_gem_mmap_obj(obj, drm_vma_node_size(node) << PAGE_SHIFT, vma);
mutex_unlock(&dev->struct_mutex);
return ret;
}
