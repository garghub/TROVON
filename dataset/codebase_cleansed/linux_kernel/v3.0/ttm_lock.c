void ttm_lock_init(struct ttm_lock *lock)
{
spin_lock_init(&lock->lock);
init_waitqueue_head(&lock->queue);
lock->rw = 0;
lock->flags = 0;
lock->kill_takers = false;
lock->signal = SIGKILL;
}
void ttm_read_unlock(struct ttm_lock *lock)
{
spin_lock(&lock->lock);
if (--lock->rw == 0)
wake_up_all(&lock->queue);
spin_unlock(&lock->lock);
}
static bool __ttm_read_lock(struct ttm_lock *lock)
{
bool locked = false;
spin_lock(&lock->lock);
if (unlikely(lock->kill_takers)) {
send_sig(lock->signal, current, 0);
spin_unlock(&lock->lock);
return false;
}
if (lock->rw >= 0 && lock->flags == 0) {
++lock->rw;
locked = true;
}
spin_unlock(&lock->lock);
return locked;
}
int ttm_read_lock(struct ttm_lock *lock, bool interruptible)
{
int ret = 0;
if (interruptible)
ret = wait_event_interruptible(lock->queue,
__ttm_read_lock(lock));
else
wait_event(lock->queue, __ttm_read_lock(lock));
return ret;
}
static bool __ttm_read_trylock(struct ttm_lock *lock, bool *locked)
{
bool block = true;
*locked = false;
spin_lock(&lock->lock);
if (unlikely(lock->kill_takers)) {
send_sig(lock->signal, current, 0);
spin_unlock(&lock->lock);
return false;
}
if (lock->rw >= 0 && lock->flags == 0) {
++lock->rw;
block = false;
*locked = true;
} else if (lock->flags == 0) {
block = false;
}
spin_unlock(&lock->lock);
return !block;
}
int ttm_read_trylock(struct ttm_lock *lock, bool interruptible)
{
int ret = 0;
bool locked;
if (interruptible)
ret = wait_event_interruptible
(lock->queue, __ttm_read_trylock(lock, &locked));
else
wait_event(lock->queue, __ttm_read_trylock(lock, &locked));
if (unlikely(ret != 0)) {
BUG_ON(locked);
return ret;
}
return (locked) ? 0 : -EBUSY;
}
void ttm_write_unlock(struct ttm_lock *lock)
{
spin_lock(&lock->lock);
lock->rw = 0;
wake_up_all(&lock->queue);
spin_unlock(&lock->lock);
}
static bool __ttm_write_lock(struct ttm_lock *lock)
{
bool locked = false;
spin_lock(&lock->lock);
if (unlikely(lock->kill_takers)) {
send_sig(lock->signal, current, 0);
spin_unlock(&lock->lock);
return false;
}
if (lock->rw == 0 && ((lock->flags & ~TTM_WRITE_LOCK_PENDING) == 0)) {
lock->rw = -1;
lock->flags &= ~TTM_WRITE_LOCK_PENDING;
locked = true;
} else {
lock->flags |= TTM_WRITE_LOCK_PENDING;
}
spin_unlock(&lock->lock);
return locked;
}
int ttm_write_lock(struct ttm_lock *lock, bool interruptible)
{
int ret = 0;
if (interruptible) {
ret = wait_event_interruptible(lock->queue,
__ttm_write_lock(lock));
if (unlikely(ret != 0)) {
spin_lock(&lock->lock);
lock->flags &= ~TTM_WRITE_LOCK_PENDING;
wake_up_all(&lock->queue);
spin_unlock(&lock->lock);
}
} else
wait_event(lock->queue, __ttm_read_lock(lock));
return ret;
}
void ttm_write_lock_downgrade(struct ttm_lock *lock)
{
spin_lock(&lock->lock);
lock->rw = 1;
wake_up_all(&lock->queue);
spin_unlock(&lock->lock);
}
static int __ttm_vt_unlock(struct ttm_lock *lock)
{
int ret = 0;
spin_lock(&lock->lock);
if (unlikely(!(lock->flags & TTM_VT_LOCK)))
ret = -EINVAL;
lock->flags &= ~TTM_VT_LOCK;
wake_up_all(&lock->queue);
spin_unlock(&lock->lock);
return ret;
}
static void ttm_vt_lock_remove(struct ttm_base_object **p_base)
{
struct ttm_base_object *base = *p_base;
struct ttm_lock *lock = container_of(base, struct ttm_lock, base);
int ret;
*p_base = NULL;
ret = __ttm_vt_unlock(lock);
BUG_ON(ret != 0);
}
static bool __ttm_vt_lock(struct ttm_lock *lock)
{
bool locked = false;
spin_lock(&lock->lock);
if (lock->rw == 0) {
lock->flags &= ~TTM_VT_LOCK_PENDING;
lock->flags |= TTM_VT_LOCK;
locked = true;
} else {
lock->flags |= TTM_VT_LOCK_PENDING;
}
spin_unlock(&lock->lock);
return locked;
}
int ttm_vt_lock(struct ttm_lock *lock,
bool interruptible,
struct ttm_object_file *tfile)
{
int ret = 0;
if (interruptible) {
ret = wait_event_interruptible(lock->queue,
__ttm_vt_lock(lock));
if (unlikely(ret != 0)) {
spin_lock(&lock->lock);
lock->flags &= ~TTM_VT_LOCK_PENDING;
wake_up_all(&lock->queue);
spin_unlock(&lock->lock);
return ret;
}
} else
wait_event(lock->queue, __ttm_vt_lock(lock));
ret = ttm_base_object_init(tfile, &lock->base, false,
ttm_lock_type, &ttm_vt_lock_remove, NULL);
if (ret)
(void)__ttm_vt_unlock(lock);
else
lock->vt_holder = tfile;
return ret;
}
int ttm_vt_unlock(struct ttm_lock *lock)
{
return ttm_ref_object_base_unref(lock->vt_holder,
lock->base.hash.key, TTM_REF_USAGE);
}
void ttm_suspend_unlock(struct ttm_lock *lock)
{
spin_lock(&lock->lock);
lock->flags &= ~TTM_SUSPEND_LOCK;
wake_up_all(&lock->queue);
spin_unlock(&lock->lock);
}
static bool __ttm_suspend_lock(struct ttm_lock *lock)
{
bool locked = false;
spin_lock(&lock->lock);
if (lock->rw == 0) {
lock->flags &= ~TTM_SUSPEND_LOCK_PENDING;
lock->flags |= TTM_SUSPEND_LOCK;
locked = true;
} else {
lock->flags |= TTM_SUSPEND_LOCK_PENDING;
}
spin_unlock(&lock->lock);
return locked;
}
void ttm_suspend_lock(struct ttm_lock *lock)
{
wait_event(lock->queue, __ttm_suspend_lock(lock));
}
