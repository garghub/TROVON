void drm_modeset_lock_all(struct drm_device *dev)
{
struct drm_mode_config *config = &dev->mode_config;
struct drm_modeset_acquire_ctx *ctx;
int ret;
ctx = kzalloc(sizeof(*ctx), GFP_KERNEL);
if (WARN_ON(!ctx))
return;
mutex_lock(&config->mutex);
drm_modeset_acquire_init(ctx, 0);
retry:
ret = drm_modeset_lock_all_ctx(dev, ctx);
if (ret < 0) {
if (ret == -EDEADLK) {
drm_modeset_backoff(ctx);
goto retry;
}
drm_modeset_acquire_fini(ctx);
kfree(ctx);
return;
}
WARN_ON(config->acquire_ctx);
config->acquire_ctx = ctx;
drm_warn_on_modeset_not_all_locked(dev);
}
void drm_modeset_unlock_all(struct drm_device *dev)
{
struct drm_mode_config *config = &dev->mode_config;
struct drm_modeset_acquire_ctx *ctx = config->acquire_ctx;
if (WARN_ON(!ctx))
return;
config->acquire_ctx = NULL;
drm_modeset_drop_locks(ctx);
drm_modeset_acquire_fini(ctx);
kfree(ctx);
mutex_unlock(&dev->mode_config.mutex);
}
void drm_modeset_lock_crtc(struct drm_crtc *crtc,
struct drm_plane *plane)
{
struct drm_modeset_acquire_ctx *ctx;
int ret;
ctx = kzalloc(sizeof(*ctx), GFP_KERNEL);
if (WARN_ON(!ctx))
return;
drm_modeset_acquire_init(ctx, 0);
retry:
ret = drm_modeset_lock(&crtc->mutex, ctx);
if (ret)
goto fail;
if (plane) {
ret = drm_modeset_lock(&plane->mutex, ctx);
if (ret)
goto fail;
if (plane->crtc) {
ret = drm_modeset_lock(&plane->crtc->mutex, ctx);
if (ret)
goto fail;
}
}
WARN_ON(crtc->acquire_ctx);
crtc->acquire_ctx = ctx;
return;
fail:
if (ret == -EDEADLK) {
drm_modeset_backoff(ctx);
goto retry;
}
}
struct drm_modeset_acquire_ctx *
drm_modeset_legacy_acquire_ctx(struct drm_crtc *crtc)
{
if (crtc->acquire_ctx)
return crtc->acquire_ctx;
WARN_ON(!crtc->dev->mode_config.acquire_ctx);
return crtc->dev->mode_config.acquire_ctx;
}
void drm_modeset_unlock_crtc(struct drm_crtc *crtc)
{
struct drm_modeset_acquire_ctx *ctx = crtc->acquire_ctx;
if (WARN_ON(!ctx))
return;
crtc->acquire_ctx = NULL;
drm_modeset_drop_locks(ctx);
drm_modeset_acquire_fini(ctx);
kfree(ctx);
}
void drm_warn_on_modeset_not_all_locked(struct drm_device *dev)
{
struct drm_crtc *crtc;
if (oops_in_progress)
return;
drm_for_each_crtc(crtc, dev)
WARN_ON(!drm_modeset_is_locked(&crtc->mutex));
WARN_ON(!drm_modeset_is_locked(&dev->mode_config.connection_mutex));
WARN_ON(!mutex_is_locked(&dev->mode_config.mutex));
}
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
if (ctx->trylock_only) {
lockdep_assert_held(&ctx->ww_ctx);
if (!ww_mutex_trylock(&lock->mutex))
return -EBUSY;
else
return 0;
} else if (interruptible && slow) {
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
int drm_modeset_lock_all_ctx(struct drm_device *dev,
struct drm_modeset_acquire_ctx *ctx)
{
struct drm_crtc *crtc;
struct drm_plane *plane;
int ret;
ret = drm_modeset_lock(&dev->mode_config.connection_mutex, ctx);
if (ret)
return ret;
drm_for_each_crtc(crtc, dev) {
ret = drm_modeset_lock(&crtc->mutex, ctx);
if (ret)
return ret;
}
drm_for_each_plane(plane, dev) {
ret = drm_modeset_lock(&plane->mutex, ctx);
if (ret)
return ret;
}
return 0;
}
