int drm_gem_prime_handle_to_fd(struct drm_device *dev,
struct drm_file *file_priv, uint32_t handle, uint32_t flags,
int *prime_fd)
{
struct drm_gem_object *obj;
void *buf;
obj = drm_gem_object_lookup(dev, file_priv, handle);
if (!obj)
return -ENOENT;
mutex_lock(&file_priv->prime.lock);
if (obj->import_attach) {
get_dma_buf(obj->import_attach->dmabuf);
*prime_fd = dma_buf_fd(obj->import_attach->dmabuf, flags);
drm_gem_object_unreference_unlocked(obj);
mutex_unlock(&file_priv->prime.lock);
return 0;
}
if (obj->export_dma_buf) {
get_dma_buf(obj->export_dma_buf);
*prime_fd = dma_buf_fd(obj->export_dma_buf, flags);
drm_gem_object_unreference_unlocked(obj);
} else {
buf = dev->driver->gem_prime_export(dev, obj, flags);
if (IS_ERR(buf)) {
drm_gem_object_unreference_unlocked(obj);
mutex_unlock(&file_priv->prime.lock);
return PTR_ERR(buf);
}
obj->export_dma_buf = buf;
*prime_fd = dma_buf_fd(buf, flags);
}
mutex_unlock(&file_priv->prime.lock);
return 0;
}
int drm_gem_prime_fd_to_handle(struct drm_device *dev,
struct drm_file *file_priv, int prime_fd, uint32_t *handle)
{
struct dma_buf *dma_buf;
struct drm_gem_object *obj;
int ret;
dma_buf = dma_buf_get(prime_fd);
if (IS_ERR(dma_buf))
return PTR_ERR(dma_buf);
mutex_lock(&file_priv->prime.lock);
ret = drm_prime_lookup_imported_buf_handle(&file_priv->prime,
dma_buf, handle);
if (!ret) {
ret = 0;
goto out_put;
}
obj = dev->driver->gem_prime_import(dev, dma_buf);
if (IS_ERR(obj)) {
ret = PTR_ERR(obj);
goto out_put;
}
ret = drm_gem_handle_create(file_priv, obj, handle);
drm_gem_object_unreference_unlocked(obj);
if (ret)
goto out_put;
ret = drm_prime_add_imported_buf_handle(&file_priv->prime,
dma_buf, *handle);
if (ret)
goto fail;
mutex_unlock(&file_priv->prime.lock);
return 0;
fail:
drm_gem_object_handle_unreference_unlocked(obj);
out_put:
dma_buf_put(dma_buf);
mutex_unlock(&file_priv->prime.lock);
return ret;
}
int drm_prime_handle_to_fd_ioctl(struct drm_device *dev, void *data,
struct drm_file *file_priv)
{
struct drm_prime_handle *args = data;
uint32_t flags;
if (!drm_core_check_feature(dev, DRIVER_PRIME))
return -EINVAL;
if (!dev->driver->prime_handle_to_fd)
return -ENOSYS;
if (args->flags & ~DRM_CLOEXEC)
return -EINVAL;
flags = args->flags & DRM_CLOEXEC;
return dev->driver->prime_handle_to_fd(dev, file_priv,
args->handle, flags, &args->fd);
}
int drm_prime_fd_to_handle_ioctl(struct drm_device *dev, void *data,
struct drm_file *file_priv)
{
struct drm_prime_handle *args = data;
if (!drm_core_check_feature(dev, DRIVER_PRIME))
return -EINVAL;
if (!dev->driver->prime_fd_to_handle)
return -ENOSYS;
return dev->driver->prime_fd_to_handle(dev, file_priv,
args->fd, &args->handle);
}
struct sg_table *drm_prime_pages_to_sg(struct page **pages, int nr_pages)
{
struct sg_table *sg = NULL;
struct scatterlist *iter;
int i;
int ret;
sg = kmalloc(sizeof(struct sg_table), GFP_KERNEL);
if (!sg)
goto out;
ret = sg_alloc_table(sg, nr_pages, GFP_KERNEL);
if (ret)
goto out;
for_each_sg(sg->sgl, iter, nr_pages, i)
sg_set_page(iter, pages[i], PAGE_SIZE, 0);
return sg;
out:
kfree(sg);
return NULL;
}
void drm_prime_gem_destroy(struct drm_gem_object *obj, struct sg_table *sg)
{
struct dma_buf_attachment *attach;
struct dma_buf *dma_buf;
attach = obj->import_attach;
if (sg)
dma_buf_unmap_attachment(attach, sg, DMA_BIDIRECTIONAL);
dma_buf = attach->dmabuf;
dma_buf_detach(attach->dmabuf, attach);
dma_buf_put(dma_buf);
}
void drm_prime_init_file_private(struct drm_prime_file_private *prime_fpriv)
{
INIT_LIST_HEAD(&prime_fpriv->head);
mutex_init(&prime_fpriv->lock);
}
void drm_prime_destroy_file_private(struct drm_prime_file_private *prime_fpriv)
{
struct drm_prime_member *member, *safe;
list_for_each_entry_safe(member, safe, &prime_fpriv->head, entry) {
list_del(&member->entry);
kfree(member);
}
}
int drm_prime_add_imported_buf_handle(struct drm_prime_file_private *prime_fpriv, struct dma_buf *dma_buf, uint32_t handle)
{
struct drm_prime_member *member;
member = kmalloc(sizeof(*member), GFP_KERNEL);
if (!member)
return -ENOMEM;
member->dma_buf = dma_buf;
member->handle = handle;
list_add(&member->entry, &prime_fpriv->head);
return 0;
}
int drm_prime_lookup_imported_buf_handle(struct drm_prime_file_private *prime_fpriv, struct dma_buf *dma_buf, uint32_t *handle)
{
struct drm_prime_member *member;
list_for_each_entry(member, &prime_fpriv->head, entry) {
if (member->dma_buf == dma_buf) {
*handle = member->handle;
return 0;
}
}
return -ENOENT;
}
void drm_prime_remove_imported_buf_handle(struct drm_prime_file_private *prime_fpriv, struct dma_buf *dma_buf)
{
struct drm_prime_member *member, *safe;
mutex_lock(&prime_fpriv->lock);
list_for_each_entry_safe(member, safe, &prime_fpriv->head, entry) {
if (member->dma_buf == dma_buf) {
list_del(&member->entry);
kfree(member);
}
}
mutex_unlock(&prime_fpriv->lock);
}
