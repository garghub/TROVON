static inline void __user *to_user_ptr(u64 address)
{
return (void __user *)(uintptr_t)address;
}
static struct etnaviv_gem_submit *submit_create(struct drm_device *dev,
struct etnaviv_gpu *gpu, size_t nr)
{
struct etnaviv_gem_submit *submit;
size_t sz = size_vstruct(nr, sizeof(submit->bos[0]), sizeof(*submit));
submit = kmalloc(sz, GFP_TEMPORARY | __GFP_NOWARN | __GFP_NORETRY);
if (submit) {
submit->dev = dev;
submit->gpu = gpu;
submit->nr_bos = 0;
ww_acquire_init(&submit->ticket, &reservation_ww_class);
}
return submit;
}
static int submit_lookup_objects(struct etnaviv_gem_submit *submit,
struct drm_file *file, struct drm_etnaviv_gem_submit_bo *submit_bos,
unsigned nr_bos)
{
struct drm_etnaviv_gem_submit_bo *bo;
unsigned i;
int ret = 0;
spin_lock(&file->table_lock);
for (i = 0, bo = submit_bos; i < nr_bos; i++, bo++) {
struct drm_gem_object *obj;
if (bo->flags & BO_INVALID_FLAGS) {
DRM_ERROR("invalid flags: %x\n", bo->flags);
ret = -EINVAL;
goto out_unlock;
}
submit->bos[i].flags = bo->flags;
obj = idr_find(&file->object_idr, bo->handle);
if (!obj) {
DRM_ERROR("invalid handle %u at index %u\n",
bo->handle, i);
ret = -EINVAL;
goto out_unlock;
}
drm_gem_object_reference(obj);
submit->bos[i].obj = to_etnaviv_bo(obj);
}
out_unlock:
submit->nr_bos = i;
spin_unlock(&file->table_lock);
return ret;
}
static void submit_unlock_object(struct etnaviv_gem_submit *submit, int i)
{
if (submit->bos[i].flags & BO_LOCKED) {
struct etnaviv_gem_object *etnaviv_obj = submit->bos[i].obj;
ww_mutex_unlock(&etnaviv_obj->resv->lock);
submit->bos[i].flags &= ~BO_LOCKED;
}
}
static int submit_lock_objects(struct etnaviv_gem_submit *submit)
{
int contended, slow_locked = -1, i, ret = 0;
retry:
for (i = 0; i < submit->nr_bos; i++) {
struct etnaviv_gem_object *etnaviv_obj = submit->bos[i].obj;
if (slow_locked == i)
slow_locked = -1;
contended = i;
if (!(submit->bos[i].flags & BO_LOCKED)) {
ret = ww_mutex_lock_interruptible(&etnaviv_obj->resv->lock,
&submit->ticket);
if (ret == -EALREADY)
DRM_ERROR("BO at index %u already on submit list\n",
i);
if (ret)
goto fail;
submit->bos[i].flags |= BO_LOCKED;
}
}
ww_acquire_done(&submit->ticket);
return 0;
fail:
for (; i >= 0; i--)
submit_unlock_object(submit, i);
if (slow_locked > 0)
submit_unlock_object(submit, slow_locked);
if (ret == -EDEADLK) {
struct etnaviv_gem_object *etnaviv_obj;
etnaviv_obj = submit->bos[contended].obj;
ret = ww_mutex_lock_slow_interruptible(&etnaviv_obj->resv->lock,
&submit->ticket);
if (!ret) {
submit->bos[contended].flags |= BO_LOCKED;
slow_locked = contended;
goto retry;
}
}
return ret;
}
static int submit_fence_sync(const struct etnaviv_gem_submit *submit)
{
unsigned int context = submit->gpu->fence_context;
int i, ret = 0;
for (i = 0; i < submit->nr_bos; i++) {
struct etnaviv_gem_object *etnaviv_obj = submit->bos[i].obj;
bool write = submit->bos[i].flags & ETNA_SUBMIT_BO_WRITE;
ret = etnaviv_gpu_fence_sync_obj(etnaviv_obj, context, write);
if (ret)
break;
}
return ret;
}
static void submit_unpin_objects(struct etnaviv_gem_submit *submit)
{
int i;
for (i = 0; i < submit->nr_bos; i++) {
struct etnaviv_gem_object *etnaviv_obj = submit->bos[i].obj;
if (submit->bos[i].flags & BO_PINNED)
etnaviv_gem_put_iova(submit->gpu, &etnaviv_obj->base);
submit->bos[i].iova = 0;
submit->bos[i].flags &= ~BO_PINNED;
}
}
static int submit_pin_objects(struct etnaviv_gem_submit *submit)
{
int i, ret = 0;
for (i = 0; i < submit->nr_bos; i++) {
struct etnaviv_gem_object *etnaviv_obj = submit->bos[i].obj;
u32 iova;
ret = etnaviv_gem_get_iova(submit->gpu, &etnaviv_obj->base,
&iova);
if (ret)
break;
submit->bos[i].flags |= BO_PINNED;
submit->bos[i].iova = iova;
}
return ret;
}
static int submit_bo(struct etnaviv_gem_submit *submit, u32 idx,
struct etnaviv_gem_object **obj, u32 *iova)
{
if (idx >= submit->nr_bos) {
DRM_ERROR("invalid buffer index: %u (out of %u)\n",
idx, submit->nr_bos);
return -EINVAL;
}
if (obj)
*obj = submit->bos[idx].obj;
if (iova)
*iova = submit->bos[idx].iova;
return 0;
}
static int submit_reloc(struct etnaviv_gem_submit *submit, void *stream,
u32 size, const struct drm_etnaviv_gem_submit_reloc *relocs,
u32 nr_relocs)
{
u32 i, last_offset = 0;
u32 *ptr = stream;
int ret;
for (i = 0; i < nr_relocs; i++) {
const struct drm_etnaviv_gem_submit_reloc *r = relocs + i;
struct etnaviv_gem_object *bobj;
u32 iova, off;
if (unlikely(r->flags)) {
DRM_ERROR("invalid reloc flags\n");
return -EINVAL;
}
if (r->submit_offset % 4) {
DRM_ERROR("non-aligned reloc offset: %u\n",
r->submit_offset);
return -EINVAL;
}
off = r->submit_offset / 4;
if ((off >= size ) ||
(off < last_offset)) {
DRM_ERROR("invalid offset %u at reloc %u\n", off, i);
return -EINVAL;
}
ret = submit_bo(submit, r->reloc_idx, &bobj, &iova);
if (ret)
return ret;
if (r->reloc_offset >=
bobj->base.size - sizeof(*ptr)) {
DRM_ERROR("relocation %u outside object", i);
return -EINVAL;
}
ptr[off] = iova + r->reloc_offset;
last_offset = off;
}
return 0;
}
static void submit_cleanup(struct etnaviv_gem_submit *submit)
{
unsigned i;
for (i = 0; i < submit->nr_bos; i++) {
struct etnaviv_gem_object *etnaviv_obj = submit->bos[i].obj;
submit_unlock_object(submit, i);
drm_gem_object_unreference_unlocked(&etnaviv_obj->base);
}
ww_acquire_fini(&submit->ticket);
kfree(submit);
}
int etnaviv_ioctl_gem_submit(struct drm_device *dev, void *data,
struct drm_file *file)
{
struct etnaviv_drm_private *priv = dev->dev_private;
struct drm_etnaviv_gem_submit *args = data;
struct drm_etnaviv_gem_submit_reloc *relocs;
struct drm_etnaviv_gem_submit_bo *bos;
struct etnaviv_gem_submit *submit;
struct etnaviv_cmdbuf *cmdbuf;
struct etnaviv_gpu *gpu;
void *stream;
int ret;
if (args->pipe >= ETNA_MAX_PIPES)
return -EINVAL;
gpu = priv->gpu[args->pipe];
if (!gpu)
return -ENXIO;
if (args->stream_size % 4) {
DRM_ERROR("non-aligned cmdstream buffer size: %u\n",
args->stream_size);
return -EINVAL;
}
if (args->exec_state != ETNA_PIPE_3D &&
args->exec_state != ETNA_PIPE_2D &&
args->exec_state != ETNA_PIPE_VG) {
DRM_ERROR("invalid exec_state: 0x%x\n", args->exec_state);
return -EINVAL;
}
bos = drm_malloc_ab(args->nr_bos, sizeof(*bos));
relocs = drm_malloc_ab(args->nr_relocs, sizeof(*relocs));
stream = drm_malloc_ab(1, args->stream_size);
cmdbuf = etnaviv_gpu_cmdbuf_new(gpu, ALIGN(args->stream_size, 8) + 8,
args->nr_bos);
if (!bos || !relocs || !stream || !cmdbuf) {
ret = -ENOMEM;
goto err_submit_cmds;
}
cmdbuf->exec_state = args->exec_state;
cmdbuf->ctx = file->driver_priv;
ret = copy_from_user(bos, to_user_ptr(args->bos),
args->nr_bos * sizeof(*bos));
if (ret) {
ret = -EFAULT;
goto err_submit_cmds;
}
ret = copy_from_user(relocs, to_user_ptr(args->relocs),
args->nr_relocs * sizeof(*relocs));
if (ret) {
ret = -EFAULT;
goto err_submit_cmds;
}
ret = copy_from_user(stream, to_user_ptr(args->stream),
args->stream_size);
if (ret) {
ret = -EFAULT;
goto err_submit_cmds;
}
submit = submit_create(dev, gpu, args->nr_bos);
if (!submit) {
ret = -ENOMEM;
goto err_submit_cmds;
}
ret = submit_lookup_objects(submit, file, bos, args->nr_bos);
if (ret)
goto err_submit_objects;
ret = submit_lock_objects(submit);
if (ret)
goto err_submit_objects;
if (!etnaviv_cmd_validate_one(gpu, stream, args->stream_size / 4,
relocs, args->nr_relocs)) {
ret = -EINVAL;
goto err_submit_objects;
}
ret = submit_fence_sync(submit);
if (ret)
goto err_submit_objects;
ret = submit_pin_objects(submit);
if (ret)
goto out;
ret = submit_reloc(submit, stream, args->stream_size / 4,
relocs, args->nr_relocs);
if (ret)
goto out;
memcpy(cmdbuf->vaddr, stream, args->stream_size);
cmdbuf->user_size = ALIGN(args->stream_size, 8);
ret = etnaviv_gpu_submit(gpu, submit, cmdbuf);
if (ret == 0)
cmdbuf = NULL;
args->fence = submit->fence;
out:
submit_unpin_objects(submit);
if (ret == -EAGAIN)
flush_workqueue(priv->wq);
err_submit_objects:
submit_cleanup(submit);
err_submit_cmds:
if (cmdbuf)
etnaviv_gpu_cmdbuf_free(cmdbuf);
if (stream)
drm_free_large(stream);
if (bos)
drm_free_large(bos);
if (relocs)
drm_free_large(relocs);
return ret;
}
