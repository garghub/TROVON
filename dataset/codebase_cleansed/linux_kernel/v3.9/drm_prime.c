static struct sg_table *drm_gem_map_dma_buf(struct dma_buf_attachment *attach,
enum dma_data_direction dir)
{
struct drm_gem_object *obj = attach->dmabuf->priv;
struct sg_table *sgt;
mutex_lock(&obj->dev->struct_mutex);
sgt = obj->dev->driver->gem_prime_get_sg_table(obj);
if (!IS_ERR_OR_NULL(sgt))
dma_map_sg(attach->dev, sgt->sgl, sgt->nents, dir);
mutex_unlock(&obj->dev->struct_mutex);
return sgt;
}
static void drm_gem_unmap_dma_buf(struct dma_buf_attachment *attach,
struct sg_table *sgt, enum dma_data_direction dir)
{
dma_unmap_sg(attach->dev, sgt->sgl, sgt->nents, dir);
sg_free_table(sgt);
kfree(sgt);
}
static void drm_gem_dmabuf_release(struct dma_buf *dma_buf)
{
struct drm_gem_object *obj = dma_buf->priv;
if (obj->export_dma_buf == dma_buf) {
obj->export_dma_buf = NULL;
drm_gem_object_unreference_unlocked(obj);
}
}
static void *drm_gem_dmabuf_vmap(struct dma_buf *dma_buf)
{
struct drm_gem_object *obj = dma_buf->priv;
struct drm_device *dev = obj->dev;
return dev->driver->gem_prime_vmap(obj);
}
static void drm_gem_dmabuf_vunmap(struct dma_buf *dma_buf, void *vaddr)
{
struct drm_gem_object *obj = dma_buf->priv;
struct drm_device *dev = obj->dev;
dev->driver->gem_prime_vunmap(obj, vaddr);
}
static void *drm_gem_dmabuf_kmap_atomic(struct dma_buf *dma_buf,
unsigned long page_num)
{
return NULL;
}
static void drm_gem_dmabuf_kunmap_atomic(struct dma_buf *dma_buf,
unsigned long page_num, void *addr)
{
}
static void *drm_gem_dmabuf_kmap(struct dma_buf *dma_buf,
unsigned long page_num)
{
return NULL;
}
static void drm_gem_dmabuf_kunmap(struct dma_buf *dma_buf,
unsigned long page_num, void *addr)
{
}
static int drm_gem_dmabuf_mmap(struct dma_buf *dma_buf,
struct vm_area_struct *vma)
{
return -EINVAL;
}
struct dma_buf *drm_gem_prime_export(struct drm_device *dev,
struct drm_gem_object *obj, int flags)
{
if (dev->driver->gem_prime_pin) {
int ret = dev->driver->gem_prime_pin(obj);
if (ret)
return ERR_PTR(ret);
}
return dma_buf_export(obj, &drm_gem_prime_dmabuf_ops, obj->size,
0600);
}
int drm_gem_prime_handle_to_fd(struct drm_device *dev,
struct drm_file *file_priv, uint32_t handle, uint32_t flags,
int *prime_fd)
{
struct drm_gem_object *obj;
void *buf;
int ret;
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
ret = drm_prime_add_imported_buf_handle(&file_priv->prime,
obj->export_dma_buf, handle);
if (ret) {
drm_gem_object_unreference_unlocked(obj);
mutex_unlock(&file_priv->prime.lock);
return ret;
}
mutex_unlock(&file_priv->prime.lock);
return 0;
}
struct drm_gem_object *drm_gem_prime_import(struct drm_device *dev,
struct dma_buf *dma_buf)
{
struct dma_buf_attachment *attach;
struct sg_table *sgt;
struct drm_gem_object *obj;
int ret;
if (!dev->driver->gem_prime_import_sg_table)
return ERR_PTR(-EINVAL);
if (dma_buf->ops == &drm_gem_prime_dmabuf_ops) {
obj = dma_buf->priv;
if (obj->dev == dev) {
drm_gem_object_reference(obj);
dma_buf_put(dma_buf);
return obj;
}
}
attach = dma_buf_attach(dma_buf, dev->dev);
if (IS_ERR(attach))
return ERR_PTR(PTR_ERR(attach));
sgt = dma_buf_map_attachment(attach, DMA_BIDIRECTIONAL);
if (IS_ERR_OR_NULL(sgt)) {
ret = PTR_ERR(sgt);
goto fail_detach;
}
obj = dev->driver->gem_prime_import_sg_table(dev, dma_buf->size, sgt);
if (IS_ERR(obj)) {
ret = PTR_ERR(obj);
goto fail_unmap;
}
obj->import_attach = attach;
return obj;
fail_unmap:
dma_buf_unmap_attachment(attach, sgt, DMA_BIDIRECTIONAL);
fail_detach:
dma_buf_detach(dma_buf, attach);
return ERR_PTR(ret);
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
int drm_prime_sg_to_page_addr_arrays(struct sg_table *sgt, struct page **pages,
dma_addr_t *addrs, int max_pages)
{
unsigned count;
struct scatterlist *sg;
struct page *page;
u32 len, offset;
int pg_index;
dma_addr_t addr;
pg_index = 0;
for_each_sg(sgt->sgl, sg, sgt->nents, count) {
len = sg->length;
offset = sg->offset;
page = sg_page(sg);
addr = sg_dma_address(sg);
while (len > 0) {
if (WARN_ON(pg_index >= max_pages))
return -1;
pages[pg_index] = page;
if (addrs)
addrs[pg_index] = addr;
page++;
addr += PAGE_SIZE;
len -= PAGE_SIZE;
pg_index++;
}
}
return 0;
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
