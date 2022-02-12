void drm_modeset_acquire_init(struct drm_modeset_acquire_ctx *ctx,
uint32_t flags)
{
memset(ctx, 0, sizeof(*ctx));
ww_acquire_init(&ctx->ww_ctx, &crtc_ww_class);
INIT_LIST_HEAD(&ctx->locked);
}
void drm_modeset_acquire_fini(struct drm_modeset_acquire_ctx *ctx)
{
ww_acquire_fini(&ctx->ww_ctx);
}
void drm_modeset_drop_locks(struct drm_modeset_acquire_ctx *ctx)
{
WARN_ON(ctx->contended);
while (!list_empty(&ctx->locked)) {
struct drm_modeset_lock *lock;
lock = list_first_entry(&ctx->locked,
struct drm_modeset_lock, head);
drm_modeset_unlock(lock);
}
}
static inline int modeset_lock(struct drm_modeset_lock *lock,
struct drm_modeset_acquire_ctx *ctx,
bool interruptible, bool slow)
{
int ret;
WARN_ON(ctx->contended);
if (interruptible && slow) {
ret = ww_mutex_lock_slow_interruptible(&lock->mutex, &ctx->ww_ctx);
} else if (interruptible) {
ret = ww_mutex_lock_interruptible(&lock->mutex, &ctx->ww_ctx);
} else if (slow) {
ww_mutex_lock_slow(&lock->mutex, &ctx->ww_ctx);
ret = 0;
} else {
ret = ww_mutex_lock(&lock->mutex, &ctx->ww_ctx);
}
if (!ret) {
WARN_ON(!list_empty(&lock->head));
list_add(&lock->head, &ctx->locked);
} else if (ret == -EALREADY) {
ret = 0;
} else if (ret == -EDEADLK) {
ctx->contended = lock;
}
return ret;
}
static int modeset_backoff(struct drm_modeset_acquire_ctx *ctx,
bool interruptible)
{
struct drm_modeset_lock *contended = ctx->contended;
ctx->contended = NULL;
if (WARN_ON(!contended))
return 0;
drm_modeset_drop_locks(ctx);
return modeset_lock(contended, ctx, interruptible, true);
}
void drm_modeset_backoff(struct drm_modeset_acquire_ctx *ctx)
{
modeset_backoff(ctx, false);
}
int drm_modeset_backoff_interruptible(struct drm_modeset_acquire_ctx *ctx)
{
return modeset_backoff(ctx, true);
}
int drm_modeset_lock(struct drm_modeset_lock *lock,
struct drm_modeset_acquire_ctx *ctx)
{
if (ctx)
return modeset_lock(lock, ctx, false, false);
ww_mutex_lock(&lock->mutex, NULL);
return 0;
}
int drm_modeset_lock_interruptible(struct drm_modeset_lock *lock,
struct drm_modeset_acquire_ctx *ctx)
{
if (ctx)
return modeset_lock(lock, ctx, true, false);
return ww_mutex_lock_interruptible(&lock->mutex, NULL);
}
void drm_modeset_unlock(struct drm_modeset_lock *lock)
{
list_del_init(&lock->head);
ww_mutex_unlock(&lock->mutex);
}
int drm_modeset_lock_all_crtcs(struct drm_device *dev,
struct drm_modeset_acquire_ctx *ctx)
{
struct drm_mode_config *config = &dev->mode_config;
struct drm_crtc *crtc;
int ret = 0;
list_for_each_entry(crtc, &config->crtc_list, head) {
ret = drm_modeset_lock(&crtc->mutex, ctx);
if (ret)
return ret;
}
return 0;
}
