struct msm_fence_context *
msm_fence_context_alloc(struct drm_device *dev, const char *name)
{
struct msm_fence_context *fctx;
fctx = kzalloc(sizeof(*fctx), GFP_KERNEL);
if (!fctx)
return ERR_PTR(-ENOMEM);
fctx->dev = dev;
fctx->name = name;
fctx->context = fence_context_alloc(1);
init_waitqueue_head(&fctx->event);
spin_lock_init(&fctx->spinlock);
return fctx;
}
void msm_fence_context_free(struct msm_fence_context *fctx)
{
kfree(fctx);
}
static inline bool fence_completed(struct msm_fence_context *fctx, uint32_t fence)
{
return (int32_t)(fctx->completed_fence - fence) >= 0;
}
int msm_wait_fence(struct msm_fence_context *fctx, uint32_t fence,
ktime_t *timeout, bool interruptible)
{
int ret;
if (fence > fctx->last_fence) {
DRM_ERROR("%s: waiting on invalid fence: %u (of %u)\n",
fctx->name, fence, fctx->last_fence);
return -EINVAL;
}
if (!timeout) {
ret = fence_completed(fctx, fence) ? 0 : -EBUSY;
} else {
unsigned long remaining_jiffies = timeout_to_jiffies(timeout);
if (interruptible)
ret = wait_event_interruptible_timeout(fctx->event,
fence_completed(fctx, fence),
remaining_jiffies);
else
ret = wait_event_timeout(fctx->event,
fence_completed(fctx, fence),
remaining_jiffies);
if (ret == 0) {
DBG("timeout waiting for fence: %u (completed: %u)",
fence, fctx->completed_fence);
ret = -ETIMEDOUT;
} else if (ret != -ERESTARTSYS) {
ret = 0;
}
}
return ret;
}
void msm_update_fence(struct msm_fence_context *fctx, uint32_t fence)
{
spin_lock(&fctx->spinlock);
fctx->completed_fence = max(fence, fctx->completed_fence);
spin_unlock(&fctx->spinlock);
wake_up_all(&fctx->event);
}
static inline struct msm_fence *to_msm_fence(struct fence *fence)
{
return container_of(fence, struct msm_fence, base);
}
static const char *msm_fence_get_driver_name(struct fence *fence)
{
return "msm";
}
static const char *msm_fence_get_timeline_name(struct fence *fence)
{
struct msm_fence *f = to_msm_fence(fence);
return f->fctx->name;
}
static bool msm_fence_enable_signaling(struct fence *fence)
{
return true;
}
static bool msm_fence_signaled(struct fence *fence)
{
struct msm_fence *f = to_msm_fence(fence);
return fence_completed(f->fctx, f->base.seqno);
}
static void msm_fence_release(struct fence *fence)
{
struct msm_fence *f = to_msm_fence(fence);
kfree_rcu(f, base.rcu);
}
struct fence *
msm_fence_alloc(struct msm_fence_context *fctx)
{
struct msm_fence *f;
f = kzalloc(sizeof(*f), GFP_KERNEL);
if (!f)
return ERR_PTR(-ENOMEM);
f->fctx = fctx;
fence_init(&f->base, &msm_fence_ops, &fctx->spinlock,
fctx->context, ++fctx->last_fence);
return &f->base;
}
