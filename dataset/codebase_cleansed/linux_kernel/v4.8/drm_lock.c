static
int drm_lock_take(struct drm_lock_data *lock_data,
unsigned int context)
{
unsigned int old, new, prev;
volatile unsigned int *lock = &lock_data->hw_lock->lock;
spin_lock_bh(&lock_data->spinlock);
do {
old = *lock;
if (old & _DRM_LOCK_HELD)
new = old | _DRM_LOCK_CONT;
else {
new = context | _DRM_LOCK_HELD |
((lock_data->user_waiters + lock_data->kernel_waiters > 1) ?
_DRM_LOCK_CONT : 0);
}
prev = cmpxchg(lock, old, new);
} while (prev != old);
spin_unlock_bh(&lock_data->spinlock);
if (_DRM_LOCKING_CONTEXT(old) == context) {
if (old & _DRM_LOCK_HELD) {
if (context != DRM_KERNEL_CONTEXT) {
DRM_ERROR("%d holds heavyweight lock\n",
context);
}
return 0;
}
}
if ((_DRM_LOCKING_CONTEXT(new)) == context && (new & _DRM_LOCK_HELD)) {
return 1;
}
return 0;
}
static int drm_lock_transfer(struct drm_lock_data *lock_data,
unsigned int context)
{
unsigned int old, new, prev;
volatile unsigned int *lock = &lock_data->hw_lock->lock;
lock_data->file_priv = NULL;
do {
old = *lock;
new = context | _DRM_LOCK_HELD;
prev = cmpxchg(lock, old, new);
} while (prev != old);
return 1;
}
static int drm_legacy_lock_free(struct drm_lock_data *lock_data,
unsigned int context)
{
unsigned int old, new, prev;
volatile unsigned int *lock = &lock_data->hw_lock->lock;
spin_lock_bh(&lock_data->spinlock);
if (lock_data->kernel_waiters != 0) {
drm_lock_transfer(lock_data, 0);
lock_data->idle_has_lock = 1;
spin_unlock_bh(&lock_data->spinlock);
return 1;
}
spin_unlock_bh(&lock_data->spinlock);
do {
old = *lock;
new = _DRM_LOCKING_CONTEXT(old);
prev = cmpxchg(lock, old, new);
} while (prev != old);
if (_DRM_LOCK_IS_HELD(old) && _DRM_LOCKING_CONTEXT(old) != context) {
DRM_ERROR("%d freed heavyweight lock held by %d\n",
context, _DRM_LOCKING_CONTEXT(old));
return 1;
}
wake_up_interruptible(&lock_data->lock_queue);
return 0;
}
int drm_legacy_lock(struct drm_device *dev, void *data,
struct drm_file *file_priv)
{
DECLARE_WAITQUEUE(entry, current);
struct drm_lock *lock = data;
struct drm_master *master = file_priv->master;
int ret = 0;
if (drm_core_check_feature(dev, DRIVER_MODESET))
return -EINVAL;
++file_priv->lock_count;
if (lock->context == DRM_KERNEL_CONTEXT) {
DRM_ERROR("Process %d using kernel context %d\n",
task_pid_nr(current), lock->context);
return -EINVAL;
}
DRM_DEBUG("%d (pid %d) requests lock (0x%08x), flags = 0x%08x\n",
lock->context, task_pid_nr(current),
master->lock.hw_lock->lock, lock->flags);
add_wait_queue(&master->lock.lock_queue, &entry);
spin_lock_bh(&master->lock.spinlock);
master->lock.user_waiters++;
spin_unlock_bh(&master->lock.spinlock);
for (;;) {
__set_current_state(TASK_INTERRUPTIBLE);
if (!master->lock.hw_lock) {
send_sig(SIGTERM, current, 0);
ret = -EINTR;
break;
}
if (drm_lock_take(&master->lock, lock->context)) {
master->lock.file_priv = file_priv;
master->lock.lock_time = jiffies;
break;
}
mutex_unlock(&drm_global_mutex);
schedule();
mutex_lock(&drm_global_mutex);
if (signal_pending(current)) {
ret = -EINTR;
break;
}
}
spin_lock_bh(&master->lock.spinlock);
master->lock.user_waiters--;
spin_unlock_bh(&master->lock.spinlock);
__set_current_state(TASK_RUNNING);
remove_wait_queue(&master->lock.lock_queue, &entry);
DRM_DEBUG("%d %s\n", lock->context,
ret ? "interrupted" : "has lock");
if (ret) return ret;
if (!drm_is_current_master(file_priv)) {
dev->sigdata.context = lock->context;
dev->sigdata.lock = master->lock.hw_lock;
}
if (dev->driver->dma_quiescent && (lock->flags & _DRM_LOCK_QUIESCENT))
{
if (dev->driver->dma_quiescent(dev)) {
DRM_DEBUG("%d waiting for DMA quiescent\n",
lock->context);
return -EBUSY;
}
}
return 0;
}
int drm_legacy_unlock(struct drm_device *dev, void *data, struct drm_file *file_priv)
{
struct drm_lock *lock = data;
struct drm_master *master = file_priv->master;
if (drm_core_check_feature(dev, DRIVER_MODESET))
return -EINVAL;
if (lock->context == DRM_KERNEL_CONTEXT) {
DRM_ERROR("Process %d using kernel context %d\n",
task_pid_nr(current), lock->context);
return -EINVAL;
}
if (drm_legacy_lock_free(&master->lock, lock->context)) {
}
return 0;
}
void drm_legacy_idlelock_take(struct drm_lock_data *lock_data)
{
int ret;
spin_lock_bh(&lock_data->spinlock);
lock_data->kernel_waiters++;
if (!lock_data->idle_has_lock) {
spin_unlock_bh(&lock_data->spinlock);
ret = drm_lock_take(lock_data, DRM_KERNEL_CONTEXT);
spin_lock_bh(&lock_data->spinlock);
if (ret == 1)
lock_data->idle_has_lock = 1;
}
spin_unlock_bh(&lock_data->spinlock);
}
void drm_legacy_idlelock_release(struct drm_lock_data *lock_data)
{
unsigned int old, prev;
volatile unsigned int *lock = &lock_data->hw_lock->lock;
spin_lock_bh(&lock_data->spinlock);
if (--lock_data->kernel_waiters == 0) {
if (lock_data->idle_has_lock) {
do {
old = *lock;
prev = cmpxchg(lock, old, DRM_KERNEL_CONTEXT);
} while (prev != old);
wake_up_interruptible(&lock_data->lock_queue);
lock_data->idle_has_lock = 0;
}
}
spin_unlock_bh(&lock_data->spinlock);
}
static int drm_legacy_i_have_hw_lock(struct drm_device *dev,
struct drm_file *file_priv)
{
struct drm_master *master = file_priv->master;
return (file_priv->lock_count && master->lock.hw_lock &&
_DRM_LOCK_IS_HELD(master->lock.hw_lock->lock) &&
master->lock.file_priv == file_priv);
}
void drm_legacy_lock_release(struct drm_device *dev, struct file *filp)
{
struct drm_file *file_priv = filp->private_data;
if (!dev->master)
return;
if (drm_legacy_i_have_hw_lock(dev, file_priv)) {
DRM_DEBUG("File %p released, freeing lock for context %d\n",
filp, _DRM_LOCKING_CONTEXT(file_priv->master->lock.hw_lock->lock));
drm_legacy_lock_free(&file_priv->master->lock,
_DRM_LOCKING_CONTEXT(file_priv->master->lock.hw_lock->lock));
}
}
