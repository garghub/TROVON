static inline struct vmw_dma_buffer *
vmw_dma_buffer(struct ttm_buffer_object *bo)
{
return container_of(bo, struct vmw_dma_buffer, base);
}
static inline struct vmw_user_dma_buffer *
vmw_user_dma_buffer(struct ttm_buffer_object *bo)
{
struct vmw_dma_buffer *vmw_bo = vmw_dma_buffer(bo);
return container_of(vmw_bo, struct vmw_user_dma_buffer, dma);
}
struct vmw_resource *vmw_resource_reference(struct vmw_resource *res)
{
kref_get(&res->kref);
return res;
}
struct vmw_resource *
vmw_resource_reference_unless_doomed(struct vmw_resource *res)
{
return kref_get_unless_zero(&res->kref) ? res : NULL;
}
void vmw_resource_release_id(struct vmw_resource *res)
{
struct vmw_private *dev_priv = res->dev_priv;
struct idr *idr = &dev_priv->res_idr[res->func->res_type];
write_lock(&dev_priv->resource_lock);
if (res->id != -1)
idr_remove(idr, res->id);
res->id = -1;
write_unlock(&dev_priv->resource_lock);
}
static void vmw_resource_release(struct kref *kref)
{
struct vmw_resource *res =
container_of(kref, struct vmw_resource, kref);
struct vmw_private *dev_priv = res->dev_priv;
int id;
struct idr *idr = &dev_priv->res_idr[res->func->res_type];
write_lock(&dev_priv->resource_lock);
res->avail = false;
list_del_init(&res->lru_head);
write_unlock(&dev_priv->resource_lock);
if (res->backup) {
struct ttm_buffer_object *bo = &res->backup->base;
ttm_bo_reserve(bo, false, false, NULL);
if (!list_empty(&res->mob_head) &&
res->func->unbind != NULL) {
struct ttm_validate_buffer val_buf;
val_buf.bo = bo;
val_buf.shared = false;
res->func->unbind(res, false, &val_buf);
}
res->backup_dirty = false;
list_del_init(&res->mob_head);
ttm_bo_unreserve(bo);
vmw_dmabuf_unreference(&res->backup);
}
if (likely(res->hw_destroy != NULL)) {
mutex_lock(&dev_priv->binding_mutex);
vmw_binding_res_list_kill(&res->binding_head);
mutex_unlock(&dev_priv->binding_mutex);
res->hw_destroy(res);
}
id = res->id;
if (res->res_free != NULL)
res->res_free(res);
else
kfree(res);
write_lock(&dev_priv->resource_lock);
if (id != -1)
idr_remove(idr, id);
write_unlock(&dev_priv->resource_lock);
}
void vmw_resource_unreference(struct vmw_resource **p_res)
{
struct vmw_resource *res = *p_res;
*p_res = NULL;
kref_put(&res->kref, vmw_resource_release);
}
int vmw_resource_alloc_id(struct vmw_resource *res)
{
struct vmw_private *dev_priv = res->dev_priv;
int ret;
struct idr *idr = &dev_priv->res_idr[res->func->res_type];
BUG_ON(res->id != -1);
idr_preload(GFP_KERNEL);
write_lock(&dev_priv->resource_lock);
ret = idr_alloc(idr, res, 1, 0, GFP_NOWAIT);
if (ret >= 0)
res->id = ret;
write_unlock(&dev_priv->resource_lock);
idr_preload_end();
return ret < 0 ? ret : 0;
}
int vmw_resource_init(struct vmw_private *dev_priv, struct vmw_resource *res,
bool delay_id,
void (*res_free) (struct vmw_resource *res),
const struct vmw_res_func *func)
{
kref_init(&res->kref);
res->hw_destroy = NULL;
res->res_free = res_free;
res->avail = false;
res->dev_priv = dev_priv;
res->func = func;
INIT_LIST_HEAD(&res->lru_head);
INIT_LIST_HEAD(&res->mob_head);
INIT_LIST_HEAD(&res->binding_head);
res->id = -1;
res->backup = NULL;
res->backup_offset = 0;
res->backup_dirty = false;
res->res_dirty = false;
if (delay_id)
return 0;
else
return vmw_resource_alloc_id(res);
}
void vmw_resource_activate(struct vmw_resource *res,
void (*hw_destroy) (struct vmw_resource *))
{
struct vmw_private *dev_priv = res->dev_priv;
write_lock(&dev_priv->resource_lock);
res->avail = true;
res->hw_destroy = hw_destroy;
write_unlock(&dev_priv->resource_lock);
}
static struct vmw_resource *vmw_resource_lookup(struct vmw_private *dev_priv,
struct idr *idr, int id)
{
struct vmw_resource *res;
read_lock(&dev_priv->resource_lock);
res = idr_find(idr, id);
if (!res || !res->avail || !kref_get_unless_zero(&res->kref))
res = NULL;
read_unlock(&dev_priv->resource_lock);
if (unlikely(res == NULL))
return NULL;
return res;
}
int vmw_user_resource_lookup_handle(struct vmw_private *dev_priv,
struct ttm_object_file *tfile,
uint32_t handle,
const struct vmw_user_resource_conv
*converter,
struct vmw_resource **p_res)
{
struct ttm_base_object *base;
struct vmw_resource *res;
int ret = -EINVAL;
base = ttm_base_object_lookup(tfile, handle);
if (unlikely(base == NULL))
return -EINVAL;
if (unlikely(ttm_base_object_type(base) != converter->object_type))
goto out_bad_resource;
res = converter->base_obj_to_res(base);
read_lock(&dev_priv->resource_lock);
if (!res->avail || res->res_free != converter->res_free) {
read_unlock(&dev_priv->resource_lock);
goto out_bad_resource;
}
kref_get(&res->kref);
read_unlock(&dev_priv->resource_lock);
*p_res = res;
ret = 0;
out_bad_resource:
ttm_base_object_unref(&base);
return ret;
}
int vmw_user_lookup_handle(struct vmw_private *dev_priv,
struct ttm_object_file *tfile,
uint32_t handle,
struct vmw_surface **out_surf,
struct vmw_dma_buffer **out_buf)
{
struct vmw_resource *res;
int ret;
BUG_ON(*out_surf || *out_buf);
ret = vmw_user_resource_lookup_handle(dev_priv, tfile, handle,
user_surface_converter,
&res);
if (!ret) {
*out_surf = vmw_res_to_srf(res);
return 0;
}
*out_surf = NULL;
ret = vmw_user_dmabuf_lookup(tfile, handle, out_buf, NULL);
return ret;
}
static size_t vmw_dmabuf_acc_size(struct vmw_private *dev_priv, size_t size,
bool user)
{
static size_t struct_size, user_struct_size;
size_t num_pages = PAGE_ALIGN(size) >> PAGE_SHIFT;
size_t page_array_size = ttm_round_pot(num_pages * sizeof(void *));
if (unlikely(struct_size == 0)) {
size_t backend_size = ttm_round_pot(vmw_tt_size);
struct_size = backend_size +
ttm_round_pot(sizeof(struct vmw_dma_buffer));
user_struct_size = backend_size +
ttm_round_pot(sizeof(struct vmw_user_dma_buffer));
}
if (dev_priv->map_mode == vmw_dma_alloc_coherent)
page_array_size +=
ttm_round_pot(num_pages * sizeof(dma_addr_t));
return ((user) ? user_struct_size : struct_size) +
page_array_size;
}
void vmw_dmabuf_bo_free(struct ttm_buffer_object *bo)
{
struct vmw_dma_buffer *vmw_bo = vmw_dma_buffer(bo);
kfree(vmw_bo);
}
static void vmw_user_dmabuf_destroy(struct ttm_buffer_object *bo)
{
struct vmw_user_dma_buffer *vmw_user_bo = vmw_user_dma_buffer(bo);
ttm_prime_object_kfree(vmw_user_bo, prime);
}
int vmw_dmabuf_init(struct vmw_private *dev_priv,
struct vmw_dma_buffer *vmw_bo,
size_t size, struct ttm_placement *placement,
bool interruptible,
void (*bo_free) (struct ttm_buffer_object *bo))
{
struct ttm_bo_device *bdev = &dev_priv->bdev;
size_t acc_size;
int ret;
bool user = (bo_free == &vmw_user_dmabuf_destroy);
BUG_ON(!bo_free && (!user && (bo_free != vmw_dmabuf_bo_free)));
acc_size = vmw_dmabuf_acc_size(dev_priv, size, user);
memset(vmw_bo, 0, sizeof(*vmw_bo));
INIT_LIST_HEAD(&vmw_bo->res_list);
ret = ttm_bo_init(bdev, &vmw_bo->base, size,
ttm_bo_type_device, placement,
0, interruptible,
NULL, acc_size, NULL, NULL, bo_free);
return ret;
}
static void vmw_user_dmabuf_release(struct ttm_base_object **p_base)
{
struct vmw_user_dma_buffer *vmw_user_bo;
struct ttm_base_object *base = *p_base;
struct ttm_buffer_object *bo;
*p_base = NULL;
if (unlikely(base == NULL))
return;
vmw_user_bo = container_of(base, struct vmw_user_dma_buffer,
prime.base);
bo = &vmw_user_bo->dma.base;
ttm_bo_unref(&bo);
}
static void vmw_user_dmabuf_ref_obj_release(struct ttm_base_object *base,
enum ttm_ref_type ref_type)
{
struct vmw_user_dma_buffer *user_bo;
user_bo = container_of(base, struct vmw_user_dma_buffer, prime.base);
switch (ref_type) {
case TTM_REF_SYNCCPU_WRITE:
ttm_bo_synccpu_write_release(&user_bo->dma.base);
break;
default:
BUG();
}
}
int vmw_user_dmabuf_alloc(struct vmw_private *dev_priv,
struct ttm_object_file *tfile,
uint32_t size,
bool shareable,
uint32_t *handle,
struct vmw_dma_buffer **p_dma_buf,
struct ttm_base_object **p_base)
{
struct vmw_user_dma_buffer *user_bo;
struct ttm_buffer_object *tmp;
int ret;
user_bo = kzalloc(sizeof(*user_bo), GFP_KERNEL);
if (unlikely(user_bo == NULL)) {
DRM_ERROR("Failed to allocate a buffer.\n");
return -ENOMEM;
}
ret = vmw_dmabuf_init(dev_priv, &user_bo->dma, size,
(dev_priv->has_mob) ?
&vmw_sys_placement :
&vmw_vram_sys_placement, true,
&vmw_user_dmabuf_destroy);
if (unlikely(ret != 0))
return ret;
tmp = ttm_bo_reference(&user_bo->dma.base);
ret = ttm_prime_object_init(tfile,
size,
&user_bo->prime,
shareable,
ttm_buffer_type,
&vmw_user_dmabuf_release,
&vmw_user_dmabuf_ref_obj_release);
if (unlikely(ret != 0)) {
ttm_bo_unref(&tmp);
goto out_no_base_object;
}
*p_dma_buf = &user_bo->dma;
if (p_base) {
*p_base = &user_bo->prime.base;
kref_get(&(*p_base)->refcount);
}
*handle = user_bo->prime.base.hash.key;
out_no_base_object:
return ret;
}
int vmw_user_dmabuf_verify_access(struct ttm_buffer_object *bo,
struct ttm_object_file *tfile)
{
struct vmw_user_dma_buffer *vmw_user_bo;
if (unlikely(bo->destroy != vmw_user_dmabuf_destroy))
return -EPERM;
vmw_user_bo = vmw_user_dma_buffer(bo);
if (likely(ttm_ref_object_exists(tfile, &vmw_user_bo->prime.base)))
return 0;
DRM_ERROR("Could not grant buffer access.\n");
return -EPERM;
}
static int vmw_user_dmabuf_synccpu_grab(struct vmw_user_dma_buffer *user_bo,
struct ttm_object_file *tfile,
uint32_t flags)
{
struct ttm_buffer_object *bo = &user_bo->dma.base;
bool existed;
int ret;
if (flags & drm_vmw_synccpu_allow_cs) {
bool nonblock = !!(flags & drm_vmw_synccpu_dontblock);
long lret;
lret = reservation_object_wait_timeout_rcu(bo->resv, true, true,
nonblock ? 0 : MAX_SCHEDULE_TIMEOUT);
if (!lret)
return -EBUSY;
else if (lret < 0)
return lret;
return 0;
}
ret = ttm_bo_synccpu_write_grab
(bo, !!(flags & drm_vmw_synccpu_dontblock));
if (unlikely(ret != 0))
return ret;
ret = ttm_ref_object_add(tfile, &user_bo->prime.base,
TTM_REF_SYNCCPU_WRITE, &existed);
if (ret != 0 || existed)
ttm_bo_synccpu_write_release(&user_bo->dma.base);
return ret;
}
static int vmw_user_dmabuf_synccpu_release(uint32_t handle,
struct ttm_object_file *tfile,
uint32_t flags)
{
if (!(flags & drm_vmw_synccpu_allow_cs))
return ttm_ref_object_base_unref(tfile, handle,
TTM_REF_SYNCCPU_WRITE);
return 0;
}
int vmw_user_dmabuf_synccpu_ioctl(struct drm_device *dev, void *data,
struct drm_file *file_priv)
{
struct drm_vmw_synccpu_arg *arg =
(struct drm_vmw_synccpu_arg *) data;
struct vmw_dma_buffer *dma_buf;
struct vmw_user_dma_buffer *user_bo;
struct ttm_object_file *tfile = vmw_fpriv(file_priv)->tfile;
struct ttm_base_object *buffer_base;
int ret;
if ((arg->flags & (drm_vmw_synccpu_read | drm_vmw_synccpu_write)) == 0
|| (arg->flags & ~(drm_vmw_synccpu_read | drm_vmw_synccpu_write |
drm_vmw_synccpu_dontblock |
drm_vmw_synccpu_allow_cs)) != 0) {
DRM_ERROR("Illegal synccpu flags.\n");
return -EINVAL;
}
switch (arg->op) {
case drm_vmw_synccpu_grab:
ret = vmw_user_dmabuf_lookup(tfile, arg->handle, &dma_buf,
&buffer_base);
if (unlikely(ret != 0))
return ret;
user_bo = container_of(dma_buf, struct vmw_user_dma_buffer,
dma);
ret = vmw_user_dmabuf_synccpu_grab(user_bo, tfile, arg->flags);
vmw_dmabuf_unreference(&dma_buf);
ttm_base_object_unref(&buffer_base);
if (unlikely(ret != 0 && ret != -ERESTARTSYS &&
ret != -EBUSY)) {
DRM_ERROR("Failed synccpu grab on handle 0x%08x.\n",
(unsigned int) arg->handle);
return ret;
}
break;
case drm_vmw_synccpu_release:
ret = vmw_user_dmabuf_synccpu_release(arg->handle, tfile,
arg->flags);
if (unlikely(ret != 0)) {
DRM_ERROR("Failed synccpu release on handle 0x%08x.\n",
(unsigned int) arg->handle);
return ret;
}
break;
default:
DRM_ERROR("Invalid synccpu operation.\n");
return -EINVAL;
}
return 0;
}
int vmw_dmabuf_alloc_ioctl(struct drm_device *dev, void *data,
struct drm_file *file_priv)
{
struct vmw_private *dev_priv = vmw_priv(dev);
union drm_vmw_alloc_dmabuf_arg *arg =
(union drm_vmw_alloc_dmabuf_arg *)data;
struct drm_vmw_alloc_dmabuf_req *req = &arg->req;
struct drm_vmw_dmabuf_rep *rep = &arg->rep;
struct vmw_dma_buffer *dma_buf;
uint32_t handle;
int ret;
ret = ttm_read_lock(&dev_priv->reservation_sem, true);
if (unlikely(ret != 0))
return ret;
ret = vmw_user_dmabuf_alloc(dev_priv, vmw_fpriv(file_priv)->tfile,
req->size, false, &handle, &dma_buf,
NULL);
if (unlikely(ret != 0))
goto out_no_dmabuf;
rep->handle = handle;
rep->map_handle = drm_vma_node_offset_addr(&dma_buf->base.vma_node);
rep->cur_gmr_id = handle;
rep->cur_gmr_offset = 0;
vmw_dmabuf_unreference(&dma_buf);
out_no_dmabuf:
ttm_read_unlock(&dev_priv->reservation_sem);
return ret;
}
int vmw_dmabuf_unref_ioctl(struct drm_device *dev, void *data,
struct drm_file *file_priv)
{
struct drm_vmw_unref_dmabuf_arg *arg =
(struct drm_vmw_unref_dmabuf_arg *)data;
return ttm_ref_object_base_unref(vmw_fpriv(file_priv)->tfile,
arg->handle,
TTM_REF_USAGE);
}
int vmw_user_dmabuf_lookup(struct ttm_object_file *tfile,
uint32_t handle, struct vmw_dma_buffer **out,
struct ttm_base_object **p_base)
{
struct vmw_user_dma_buffer *vmw_user_bo;
struct ttm_base_object *base;
base = ttm_base_object_lookup(tfile, handle);
if (unlikely(base == NULL)) {
printk(KERN_ERR "Invalid buffer object handle 0x%08lx.\n",
(unsigned long)handle);
return -ESRCH;
}
if (unlikely(ttm_base_object_type(base) != ttm_buffer_type)) {
ttm_base_object_unref(&base);
printk(KERN_ERR "Invalid buffer object handle 0x%08lx.\n",
(unsigned long)handle);
return -EINVAL;
}
vmw_user_bo = container_of(base, struct vmw_user_dma_buffer,
prime.base);
(void)ttm_bo_reference(&vmw_user_bo->dma.base);
if (p_base)
*p_base = base;
else
ttm_base_object_unref(&base);
*out = &vmw_user_bo->dma;
return 0;
}
int vmw_user_dmabuf_reference(struct ttm_object_file *tfile,
struct vmw_dma_buffer *dma_buf,
uint32_t *handle)
{
struct vmw_user_dma_buffer *user_bo;
if (dma_buf->base.destroy != vmw_user_dmabuf_destroy)
return -EINVAL;
user_bo = container_of(dma_buf, struct vmw_user_dma_buffer, dma);
*handle = user_bo->prime.base.hash.key;
return ttm_ref_object_add(tfile, &user_bo->prime.base,
TTM_REF_USAGE, NULL);
}
static void vmw_stream_destroy(struct vmw_resource *res)
{
struct vmw_private *dev_priv = res->dev_priv;
struct vmw_stream *stream;
int ret;
DRM_INFO("%s: unref\n", __func__);
stream = container_of(res, struct vmw_stream, res);
ret = vmw_overlay_unref(dev_priv, stream->stream_id);
WARN_ON(ret != 0);
}
static int vmw_stream_init(struct vmw_private *dev_priv,
struct vmw_stream *stream,
void (*res_free) (struct vmw_resource *res))
{
struct vmw_resource *res = &stream->res;
int ret;
ret = vmw_resource_init(dev_priv, res, false, res_free,
&vmw_stream_func);
if (unlikely(ret != 0)) {
if (res_free == NULL)
kfree(stream);
else
res_free(&stream->res);
return ret;
}
ret = vmw_overlay_claim(dev_priv, &stream->stream_id);
if (ret) {
vmw_resource_unreference(&res);
return ret;
}
DRM_INFO("%s: claimed\n", __func__);
vmw_resource_activate(&stream->res, vmw_stream_destroy);
return 0;
}
static void vmw_user_stream_free(struct vmw_resource *res)
{
struct vmw_user_stream *stream =
container_of(res, struct vmw_user_stream, stream.res);
struct vmw_private *dev_priv = res->dev_priv;
ttm_base_object_kfree(stream, base);
ttm_mem_global_free(vmw_mem_glob(dev_priv),
vmw_user_stream_size);
}
static void vmw_user_stream_base_release(struct ttm_base_object **p_base)
{
struct ttm_base_object *base = *p_base;
struct vmw_user_stream *stream =
container_of(base, struct vmw_user_stream, base);
struct vmw_resource *res = &stream->stream.res;
*p_base = NULL;
vmw_resource_unreference(&res);
}
int vmw_stream_unref_ioctl(struct drm_device *dev, void *data,
struct drm_file *file_priv)
{
struct vmw_private *dev_priv = vmw_priv(dev);
struct vmw_resource *res;
struct vmw_user_stream *stream;
struct drm_vmw_stream_arg *arg = (struct drm_vmw_stream_arg *)data;
struct ttm_object_file *tfile = vmw_fpriv(file_priv)->tfile;
struct idr *idr = &dev_priv->res_idr[vmw_res_stream];
int ret = 0;
res = vmw_resource_lookup(dev_priv, idr, arg->stream_id);
if (unlikely(res == NULL))
return -EINVAL;
if (res->res_free != &vmw_user_stream_free) {
ret = -EINVAL;
goto out;
}
stream = container_of(res, struct vmw_user_stream, stream.res);
if (stream->base.tfile != tfile) {
ret = -EINVAL;
goto out;
}
ttm_ref_object_base_unref(tfile, stream->base.hash.key, TTM_REF_USAGE);
out:
vmw_resource_unreference(&res);
return ret;
}
int vmw_stream_claim_ioctl(struct drm_device *dev, void *data,
struct drm_file *file_priv)
{
struct vmw_private *dev_priv = vmw_priv(dev);
struct vmw_user_stream *stream;
struct vmw_resource *res;
struct vmw_resource *tmp;
struct drm_vmw_stream_arg *arg = (struct drm_vmw_stream_arg *)data;
struct ttm_object_file *tfile = vmw_fpriv(file_priv)->tfile;
int ret;
if (unlikely(vmw_user_stream_size == 0))
vmw_user_stream_size = ttm_round_pot(sizeof(*stream)) + 128;
ret = ttm_read_lock(&dev_priv->reservation_sem, true);
if (unlikely(ret != 0))
return ret;
ret = ttm_mem_global_alloc(vmw_mem_glob(dev_priv),
vmw_user_stream_size,
false, true);
ttm_read_unlock(&dev_priv->reservation_sem);
if (unlikely(ret != 0)) {
if (ret != -ERESTARTSYS)
DRM_ERROR("Out of graphics memory for stream"
" creation.\n");
goto out_ret;
}
stream = kmalloc(sizeof(*stream), GFP_KERNEL);
if (unlikely(stream == NULL)) {
ttm_mem_global_free(vmw_mem_glob(dev_priv),
vmw_user_stream_size);
ret = -ENOMEM;
goto out_ret;
}
res = &stream->stream.res;
stream->base.shareable = false;
stream->base.tfile = NULL;
ret = vmw_stream_init(dev_priv, &stream->stream, vmw_user_stream_free);
if (unlikely(ret != 0))
goto out_ret;
tmp = vmw_resource_reference(res);
ret = ttm_base_object_init(tfile, &stream->base, false, VMW_RES_STREAM,
&vmw_user_stream_base_release, NULL);
if (unlikely(ret != 0)) {
vmw_resource_unreference(&tmp);
goto out_err;
}
arg->stream_id = res->id;
out_err:
vmw_resource_unreference(&res);
out_ret:
return ret;
}
int vmw_user_stream_lookup(struct vmw_private *dev_priv,
struct ttm_object_file *tfile,
uint32_t *inout_id, struct vmw_resource **out)
{
struct vmw_user_stream *stream;
struct vmw_resource *res;
int ret;
res = vmw_resource_lookup(dev_priv, &dev_priv->res_idr[vmw_res_stream],
*inout_id);
if (unlikely(res == NULL))
return -EINVAL;
if (res->res_free != &vmw_user_stream_free) {
ret = -EINVAL;
goto err_ref;
}
stream = container_of(res, struct vmw_user_stream, stream.res);
if (stream->base.tfile != tfile) {
ret = -EPERM;
goto err_ref;
}
*inout_id = stream->stream.stream_id;
*out = res;
return 0;
err_ref:
vmw_resource_unreference(&res);
return ret;
}
int vmw_dumb_create(struct drm_file *file_priv,
struct drm_device *dev,
struct drm_mode_create_dumb *args)
{
struct vmw_private *dev_priv = vmw_priv(dev);
struct vmw_dma_buffer *dma_buf;
int ret;
args->pitch = args->width * ((args->bpp + 7) / 8);
args->size = args->pitch * args->height;
ret = ttm_read_lock(&dev_priv->reservation_sem, true);
if (unlikely(ret != 0))
return ret;
ret = vmw_user_dmabuf_alloc(dev_priv, vmw_fpriv(file_priv)->tfile,
args->size, false, &args->handle,
&dma_buf, NULL);
if (unlikely(ret != 0))
goto out_no_dmabuf;
vmw_dmabuf_unreference(&dma_buf);
out_no_dmabuf:
ttm_read_unlock(&dev_priv->reservation_sem);
return ret;
}
int vmw_dumb_map_offset(struct drm_file *file_priv,
struct drm_device *dev, uint32_t handle,
uint64_t *offset)
{
struct ttm_object_file *tfile = vmw_fpriv(file_priv)->tfile;
struct vmw_dma_buffer *out_buf;
int ret;
ret = vmw_user_dmabuf_lookup(tfile, handle, &out_buf, NULL);
if (ret != 0)
return -EINVAL;
*offset = drm_vma_node_offset_addr(&out_buf->base.vma_node);
vmw_dmabuf_unreference(&out_buf);
return 0;
}
int vmw_dumb_destroy(struct drm_file *file_priv,
struct drm_device *dev,
uint32_t handle)
{
return ttm_ref_object_base_unref(vmw_fpriv(file_priv)->tfile,
handle, TTM_REF_USAGE);
}
static int vmw_resource_buf_alloc(struct vmw_resource *res,
bool interruptible)
{
unsigned long size =
(res->backup_size + PAGE_SIZE - 1) & PAGE_MASK;
struct vmw_dma_buffer *backup;
int ret;
if (likely(res->backup)) {
BUG_ON(res->backup->base.num_pages * PAGE_SIZE < size);
return 0;
}
backup = kzalloc(sizeof(*backup), GFP_KERNEL);
if (unlikely(backup == NULL))
return -ENOMEM;
ret = vmw_dmabuf_init(res->dev_priv, backup, res->backup_size,
res->func->backup_placement,
interruptible,
&vmw_dmabuf_bo_free);
if (unlikely(ret != 0))
goto out_no_dmabuf;
res->backup = backup;
out_no_dmabuf:
return ret;
}
static int vmw_resource_do_validate(struct vmw_resource *res,
struct ttm_validate_buffer *val_buf)
{
int ret = 0;
const struct vmw_res_func *func = res->func;
if (unlikely(res->id == -1)) {
ret = func->create(res);
if (unlikely(ret != 0))
return ret;
}
if (func->bind &&
((func->needs_backup && list_empty(&res->mob_head) &&
val_buf->bo != NULL) ||
(!func->needs_backup && val_buf->bo != NULL))) {
ret = func->bind(res, val_buf);
if (unlikely(ret != 0))
goto out_bind_failed;
if (func->needs_backup)
list_add_tail(&res->mob_head, &res->backup->res_list);
}
res->res_dirty = true;
return 0;
out_bind_failed:
func->destroy(res);
return ret;
}
void vmw_resource_unreserve(struct vmw_resource *res,
bool switch_backup,
struct vmw_dma_buffer *new_backup,
unsigned long new_backup_offset)
{
struct vmw_private *dev_priv = res->dev_priv;
if (!list_empty(&res->lru_head))
return;
if (switch_backup && new_backup != res->backup) {
if (res->backup) {
lockdep_assert_held(&res->backup->base.resv->lock.base);
list_del_init(&res->mob_head);
vmw_dmabuf_unreference(&res->backup);
}
if (new_backup) {
res->backup = vmw_dmabuf_reference(new_backup);
lockdep_assert_held(&new_backup->base.resv->lock.base);
list_add_tail(&res->mob_head, &new_backup->res_list);
} else {
res->backup = NULL;
}
}
if (switch_backup)
res->backup_offset = new_backup_offset;
if (!res->func->may_evict || res->id == -1 || res->pin_count)
return;
write_lock(&dev_priv->resource_lock);
list_add_tail(&res->lru_head,
&res->dev_priv->res_lru[res->func->res_type]);
write_unlock(&dev_priv->resource_lock);
}
static int
vmw_resource_check_buffer(struct vmw_resource *res,
bool interruptible,
struct ttm_validate_buffer *val_buf)
{
struct list_head val_list;
bool backup_dirty = false;
int ret;
if (unlikely(res->backup == NULL)) {
ret = vmw_resource_buf_alloc(res, interruptible);
if (unlikely(ret != 0))
return ret;
}
INIT_LIST_HEAD(&val_list);
val_buf->bo = ttm_bo_reference(&res->backup->base);
val_buf->shared = false;
list_add_tail(&val_buf->head, &val_list);
ret = ttm_eu_reserve_buffers(NULL, &val_list, interruptible, NULL);
if (unlikely(ret != 0))
goto out_no_reserve;
if (res->func->needs_backup && list_empty(&res->mob_head))
return 0;
backup_dirty = res->backup_dirty;
ret = ttm_bo_validate(&res->backup->base,
res->func->backup_placement,
true, false);
if (unlikely(ret != 0))
goto out_no_validate;
return 0;
out_no_validate:
ttm_eu_backoff_reservation(NULL, &val_list);
out_no_reserve:
ttm_bo_unref(&val_buf->bo);
if (backup_dirty)
vmw_dmabuf_unreference(&res->backup);
return ret;
}
int vmw_resource_reserve(struct vmw_resource *res, bool interruptible,
bool no_backup)
{
struct vmw_private *dev_priv = res->dev_priv;
int ret;
write_lock(&dev_priv->resource_lock);
list_del_init(&res->lru_head);
write_unlock(&dev_priv->resource_lock);
if (res->func->needs_backup && res->backup == NULL &&
!no_backup) {
ret = vmw_resource_buf_alloc(res, interruptible);
if (unlikely(ret != 0)) {
DRM_ERROR("Failed to allocate a backup buffer "
"of size %lu. bytes\n",
(unsigned long) res->backup_size);
return ret;
}
}
return 0;
}
static void
vmw_resource_backoff_reservation(struct ttm_validate_buffer *val_buf)
{
struct list_head val_list;
if (likely(val_buf->bo == NULL))
return;
INIT_LIST_HEAD(&val_list);
list_add_tail(&val_buf->head, &val_list);
ttm_eu_backoff_reservation(NULL, &val_list);
ttm_bo_unref(&val_buf->bo);
}
static int vmw_resource_do_evict(struct vmw_resource *res, bool interruptible)
{
struct ttm_validate_buffer val_buf;
const struct vmw_res_func *func = res->func;
int ret;
BUG_ON(!func->may_evict);
val_buf.bo = NULL;
val_buf.shared = false;
ret = vmw_resource_check_buffer(res, interruptible, &val_buf);
if (unlikely(ret != 0))
return ret;
if (unlikely(func->unbind != NULL &&
(!func->needs_backup || !list_empty(&res->mob_head)))) {
ret = func->unbind(res, res->res_dirty, &val_buf);
if (unlikely(ret != 0))
goto out_no_unbind;
list_del_init(&res->mob_head);
}
ret = func->destroy(res);
res->backup_dirty = true;
res->res_dirty = false;
out_no_unbind:
vmw_resource_backoff_reservation(&val_buf);
return ret;
}
int vmw_resource_validate(struct vmw_resource *res)
{
int ret;
struct vmw_resource *evict_res;
struct vmw_private *dev_priv = res->dev_priv;
struct list_head *lru_list = &dev_priv->res_lru[res->func->res_type];
struct ttm_validate_buffer val_buf;
unsigned err_count = 0;
if (!res->func->create)
return 0;
val_buf.bo = NULL;
val_buf.shared = false;
if (res->backup)
val_buf.bo = &res->backup->base;
do {
ret = vmw_resource_do_validate(res, &val_buf);
if (likely(ret != -EBUSY))
break;
write_lock(&dev_priv->resource_lock);
if (list_empty(lru_list) || !res->func->may_evict) {
DRM_ERROR("Out of device device resources "
"for %s.\n", res->func->type_name);
ret = -EBUSY;
write_unlock(&dev_priv->resource_lock);
break;
}
evict_res = vmw_resource_reference
(list_first_entry(lru_list, struct vmw_resource,
lru_head));
list_del_init(&evict_res->lru_head);
write_unlock(&dev_priv->resource_lock);
ret = vmw_resource_do_evict(evict_res, true);
if (unlikely(ret != 0)) {
write_lock(&dev_priv->resource_lock);
list_add_tail(&evict_res->lru_head, lru_list);
write_unlock(&dev_priv->resource_lock);
if (ret == -ERESTARTSYS ||
++err_count > VMW_RES_EVICT_ERR_COUNT) {
vmw_resource_unreference(&evict_res);
goto out_no_validate;
}
}
vmw_resource_unreference(&evict_res);
} while (1);
if (unlikely(ret != 0))
goto out_no_validate;
else if (!res->func->needs_backup && res->backup) {
list_del_init(&res->mob_head);
vmw_dmabuf_unreference(&res->backup);
}
return 0;
out_no_validate:
return ret;
}
void vmw_fence_single_bo(struct ttm_buffer_object *bo,
struct vmw_fence_obj *fence)
{
struct ttm_bo_device *bdev = bo->bdev;
struct vmw_private *dev_priv =
container_of(bdev, struct vmw_private, bdev);
if (fence == NULL) {
vmw_execbuf_fence_commands(NULL, dev_priv, &fence, NULL);
reservation_object_add_excl_fence(bo->resv, &fence->base);
dma_fence_put(&fence->base);
} else
reservation_object_add_excl_fence(bo->resv, &fence->base);
}
void vmw_resource_move_notify(struct ttm_buffer_object *bo,
struct ttm_mem_reg *mem)
{
struct vmw_dma_buffer *dma_buf;
if (mem == NULL)
return;
if (bo->destroy != vmw_dmabuf_bo_free &&
bo->destroy != vmw_user_dmabuf_destroy)
return;
dma_buf = container_of(bo, struct vmw_dma_buffer, base);
if (mem->mem_type != VMW_PL_MOB) {
struct vmw_resource *res, *n;
struct ttm_validate_buffer val_buf;
val_buf.bo = bo;
val_buf.shared = false;
list_for_each_entry_safe(res, n, &dma_buf->res_list, mob_head) {
if (unlikely(res->func->unbind == NULL))
continue;
(void) res->func->unbind(res, true, &val_buf);
res->backup_dirty = true;
res->res_dirty = false;
list_del_init(&res->mob_head);
}
(void) ttm_bo_wait(bo, false, false);
}
}
int vmw_query_readback_all(struct vmw_dma_buffer *dx_query_mob)
{
struct vmw_resource *dx_query_ctx;
struct vmw_private *dev_priv;
struct {
SVGA3dCmdHeader header;
SVGA3dCmdDXReadbackAllQuery body;
} *cmd;
if (!dx_query_mob || !dx_query_mob->dx_query_ctx)
return 0;
dx_query_ctx = dx_query_mob->dx_query_ctx;
dev_priv = dx_query_ctx->dev_priv;
cmd = vmw_fifo_reserve_dx(dev_priv, sizeof(*cmd), dx_query_ctx->id);
if (unlikely(cmd == NULL)) {
DRM_ERROR("Failed reserving FIFO space for "
"query MOB read back.\n");
return -ENOMEM;
}
cmd->header.id = SVGA_3D_CMD_DX_READBACK_ALL_QUERY;
cmd->header.size = sizeof(cmd->body);
cmd->body.cid = dx_query_ctx->id;
vmw_fifo_commit(dev_priv, sizeof(*cmd));
dx_query_mob->dx_query_ctx = NULL;
return 0;
}
void vmw_query_move_notify(struct ttm_buffer_object *bo,
struct ttm_mem_reg *mem)
{
struct vmw_dma_buffer *dx_query_mob;
struct ttm_bo_device *bdev = bo->bdev;
struct vmw_private *dev_priv;
dev_priv = container_of(bdev, struct vmw_private, bdev);
mutex_lock(&dev_priv->binding_mutex);
dx_query_mob = container_of(bo, struct vmw_dma_buffer, base);
if (mem == NULL || !dx_query_mob || !dx_query_mob->dx_query_ctx) {
mutex_unlock(&dev_priv->binding_mutex);
return;
}
if (mem->mem_type == TTM_PL_SYSTEM && bo->mem.mem_type == VMW_PL_MOB) {
struct vmw_fence_obj *fence;
(void) vmw_query_readback_all(dx_query_mob);
mutex_unlock(&dev_priv->binding_mutex);
(void) vmw_execbuf_fence_commands(NULL, dev_priv, &fence, NULL);
vmw_fence_single_bo(bo, fence);
if (fence != NULL)
vmw_fence_obj_unreference(&fence);
(void) ttm_bo_wait(bo, false, false);
} else
mutex_unlock(&dev_priv->binding_mutex);
}
bool vmw_resource_needs_backup(const struct vmw_resource *res)
{
return res->func->needs_backup;
}
static void vmw_resource_evict_type(struct vmw_private *dev_priv,
enum vmw_res_type type)
{
struct list_head *lru_list = &dev_priv->res_lru[type];
struct vmw_resource *evict_res;
unsigned err_count = 0;
int ret;
do {
write_lock(&dev_priv->resource_lock);
if (list_empty(lru_list))
goto out_unlock;
evict_res = vmw_resource_reference(
list_first_entry(lru_list, struct vmw_resource,
lru_head));
list_del_init(&evict_res->lru_head);
write_unlock(&dev_priv->resource_lock);
ret = vmw_resource_do_evict(evict_res, false);
if (unlikely(ret != 0)) {
write_lock(&dev_priv->resource_lock);
list_add_tail(&evict_res->lru_head, lru_list);
write_unlock(&dev_priv->resource_lock);
if (++err_count > VMW_RES_EVICT_ERR_COUNT) {
vmw_resource_unreference(&evict_res);
return;
}
}
vmw_resource_unreference(&evict_res);
} while (1);
out_unlock:
write_unlock(&dev_priv->resource_lock);
}
void vmw_resource_evict_all(struct vmw_private *dev_priv)
{
enum vmw_res_type type;
mutex_lock(&dev_priv->cmdbuf_mutex);
for (type = 0; type < vmw_res_max; ++type)
vmw_resource_evict_type(dev_priv, type);
mutex_unlock(&dev_priv->cmdbuf_mutex);
}
int vmw_resource_pin(struct vmw_resource *res, bool interruptible)
{
struct vmw_private *dev_priv = res->dev_priv;
int ret;
ttm_write_lock(&dev_priv->reservation_sem, interruptible);
mutex_lock(&dev_priv->cmdbuf_mutex);
ret = vmw_resource_reserve(res, interruptible, false);
if (ret)
goto out_no_reserve;
if (res->pin_count == 0) {
struct vmw_dma_buffer *vbo = NULL;
if (res->backup) {
vbo = res->backup;
ttm_bo_reserve(&vbo->base, interruptible, false, NULL);
if (!vbo->pin_count) {
ret = ttm_bo_validate
(&vbo->base,
res->func->backup_placement,
interruptible, false);
if (ret) {
ttm_bo_unreserve(&vbo->base);
goto out_no_validate;
}
}
vmw_bo_pin_reserved(vbo, true);
}
ret = vmw_resource_validate(res);
if (vbo)
ttm_bo_unreserve(&vbo->base);
if (ret)
goto out_no_validate;
}
res->pin_count++;
out_no_validate:
vmw_resource_unreserve(res, false, NULL, 0UL);
out_no_reserve:
mutex_unlock(&dev_priv->cmdbuf_mutex);
ttm_write_unlock(&dev_priv->reservation_sem);
return ret;
}
void vmw_resource_unpin(struct vmw_resource *res)
{
struct vmw_private *dev_priv = res->dev_priv;
int ret;
ttm_read_lock(&dev_priv->reservation_sem, false);
mutex_lock(&dev_priv->cmdbuf_mutex);
ret = vmw_resource_reserve(res, false, true);
WARN_ON(ret);
WARN_ON(res->pin_count == 0);
if (--res->pin_count == 0 && res->backup) {
struct vmw_dma_buffer *vbo = res->backup;
ttm_bo_reserve(&vbo->base, false, false, NULL);
vmw_bo_pin_reserved(vbo, false);
ttm_bo_unreserve(&vbo->base);
}
vmw_resource_unreserve(res, false, NULL, 0UL);
mutex_unlock(&dev_priv->cmdbuf_mutex);
ttm_read_unlock(&dev_priv->reservation_sem);
}
enum vmw_res_type vmw_res_type(const struct vmw_resource *res)
{
return res->func->res_type;
}
