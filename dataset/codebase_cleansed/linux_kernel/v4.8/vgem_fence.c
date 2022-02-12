static const char *vgem_fence_get_driver_name(struct fence *fence)
{
return "vgem";
}
static const char *vgem_fence_get_timeline_name(struct fence *fence)
{
return "unbound";
}
static bool vgem_fence_signaled(struct fence *fence)
{
return false;
}
static bool vgem_fence_enable_signaling(struct fence *fence)
{
return true;
}
static void vgem_fence_release(struct fence *base)
{
struct vgem_fence *fence = container_of(base, typeof(*fence), base);
del_timer_sync(&fence->timer);
fence_free(&fence->base);
}
static void vgem_fence_value_str(struct fence *fence, char *str, int size)
{
snprintf(str, size, "%u", fence->seqno);
}
static void vgem_fence_timeline_value_str(struct fence *fence, char *str,
int size)
{
snprintf(str, size, "%u", fence_is_signaled(fence) ? fence->seqno : 0);
}
static void vgem_fence_timeout(unsigned long data)
{
struct vgem_fence *fence = (struct vgem_fence *)data;
fence_signal(&fence->base);
}
static struct fence *vgem_fence_create(struct vgem_file *vfile,
unsigned int flags)
{
struct vgem_fence *fence;
fence = kzalloc(sizeof(*fence), GFP_KERNEL);
if (!fence)
return NULL;
spin_lock_init(&fence->lock);
fence_init(&fence->base, &vgem_fence_ops, &fence->lock,
fence_context_alloc(1), 1);
setup_timer(&fence->timer, vgem_fence_timeout, (unsigned long)fence);
mod_timer(&fence->timer, jiffies + VGEM_FENCE_TIMEOUT);
return &fence->base;
}
static int attach_dmabuf(struct drm_device *dev,
struct drm_gem_object *obj)
{
struct dma_buf *dmabuf;
if (obj->dma_buf)
return 0;
dmabuf = dev->driver->gem_prime_export(dev, obj, 0);
if (IS_ERR(dmabuf))
return PTR_ERR(dmabuf);
obj->dma_buf = dmabuf;
drm_gem_object_reference(obj);
return 0;
}
int vgem_fence_attach_ioctl(struct drm_device *dev,
void *data,
struct drm_file *file)
{
struct drm_vgem_fence_attach *arg = data;
struct vgem_file *vfile = file->driver_priv;
struct reservation_object *resv;
struct drm_gem_object *obj;
struct fence *fence;
int ret;
if (arg->flags & ~VGEM_FENCE_WRITE)
return -EINVAL;
if (arg->pad)
return -EINVAL;
obj = drm_gem_object_lookup(file, arg->handle);
if (!obj)
return -ENOENT;
ret = attach_dmabuf(dev, obj);
if (ret)
goto err;
fence = vgem_fence_create(vfile, arg->flags);
if (!fence) {
ret = -ENOMEM;
goto err;
}
resv = obj->dma_buf->resv;
if (!reservation_object_test_signaled_rcu(resv,
arg->flags & VGEM_FENCE_WRITE)) {
ret = -EBUSY;
goto err_fence;
}
ret = 0;
mutex_lock(&resv->lock.base);
if (arg->flags & VGEM_FENCE_WRITE)
reservation_object_add_excl_fence(resv, fence);
else if ((ret = reservation_object_reserve_shared(resv)) == 0)
reservation_object_add_shared_fence(resv, fence);
mutex_unlock(&resv->lock.base);
if (ret == 0) {
mutex_lock(&vfile->fence_mutex);
ret = idr_alloc(&vfile->fence_idr, fence, 1, 0, GFP_KERNEL);
mutex_unlock(&vfile->fence_mutex);
if (ret > 0) {
arg->out_fence = ret;
ret = 0;
}
}
err_fence:
if (ret) {
fence_signal(fence);
fence_put(fence);
}
err:
drm_gem_object_unreference_unlocked(obj);
return ret;
}
int vgem_fence_signal_ioctl(struct drm_device *dev,
void *data,
struct drm_file *file)
{
struct vgem_file *vfile = file->driver_priv;
struct drm_vgem_fence_signal *arg = data;
struct fence *fence;
int ret = 0;
if (arg->flags)
return -EINVAL;
mutex_lock(&vfile->fence_mutex);
fence = idr_replace(&vfile->fence_idr, NULL, arg->fence);
mutex_unlock(&vfile->fence_mutex);
if (!fence)
return -ENOENT;
if (IS_ERR(fence))
return PTR_ERR(fence);
if (fence_is_signaled(fence))
ret = -ETIMEDOUT;
fence_signal(fence);
fence_put(fence);
return ret;
}
int vgem_fence_open(struct vgem_file *vfile)
{
mutex_init(&vfile->fence_mutex);
idr_init(&vfile->fence_idr);
return 0;
}
static int __vgem_fence_idr_fini(int id, void *p, void *data)
{
fence_signal(p);
fence_put(p);
return 0;
}
void vgem_fence_close(struct vgem_file *vfile)
{
idr_for_each(&vfile->fence_idr, __vgem_fence_idr_fini, vfile);
idr_destroy(&vfile->fence_idr);
}
