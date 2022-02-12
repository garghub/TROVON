bool refcount_add_not_zero(unsigned int i, refcount_t *r)
{
unsigned int old, new, val = atomic_read(&r->refs);
for (;;) {
if (!val)
return false;
if (unlikely(val == UINT_MAX))
return true;
new = val + i;
if (new < val)
new = UINT_MAX;
old = atomic_cmpxchg_relaxed(&r->refs, val, new);
if (old == val)
break;
val = old;
}
WARN_ONCE(new == UINT_MAX, "refcount_t: saturated; leaking memory.\n");
return true;
}
void refcount_add(unsigned int i, refcount_t *r)
{
WARN_ONCE(!refcount_add_not_zero(i, r), "refcount_t: addition on 0; use-after-free.\n");
}
bool refcount_inc_not_zero(refcount_t *r)
{
unsigned int old, new, val = atomic_read(&r->refs);
for (;;) {
new = val + 1;
if (!val)
return false;
if (unlikely(!new))
return true;
old = atomic_cmpxchg_relaxed(&r->refs, val, new);
if (old == val)
break;
val = old;
}
WARN_ONCE(new == UINT_MAX, "refcount_t: saturated; leaking memory.\n");
return true;
}
void refcount_inc(refcount_t *r)
{
WARN_ONCE(!refcount_inc_not_zero(r), "refcount_t: increment on 0; use-after-free.\n");
}
bool refcount_sub_and_test(unsigned int i, refcount_t *r)
{
unsigned int old, new, val = atomic_read(&r->refs);
for (;;) {
if (unlikely(val == UINT_MAX))
return false;
new = val - i;
if (new > val) {
WARN_ONCE(new > val, "refcount_t: underflow; use-after-free.\n");
return false;
}
old = atomic_cmpxchg_release(&r->refs, val, new);
if (old == val)
break;
val = old;
}
return !new;
}
bool refcount_dec_and_test(refcount_t *r)
{
return refcount_sub_and_test(1, r);
}
void refcount_dec(refcount_t *r)
{
WARN_ONCE(refcount_dec_and_test(r), "refcount_t: decrement hit 0; leaking memory.\n");
}
bool refcount_dec_if_one(refcount_t *r)
{
return atomic_cmpxchg_release(&r->refs, 1, 0) == 1;
}
bool refcount_dec_not_one(refcount_t *r)
{
unsigned int old, new, val = atomic_read(&r->refs);
for (;;) {
if (unlikely(val == UINT_MAX))
return true;
if (val == 1)
return false;
new = val - 1;
if (new > val) {
WARN_ONCE(new > val, "refcount_t: underflow; use-after-free.\n");
return true;
}
old = atomic_cmpxchg_release(&r->refs, val, new);
if (old == val)
break;
val = old;
}
return true;
}
bool refcount_dec_and_mutex_lock(refcount_t *r, struct mutex *lock)
{
if (refcount_dec_not_one(r))
return false;
mutex_lock(lock);
if (!refcount_dec_and_test(r)) {
mutex_unlock(lock);
return false;
}
return true;
}
bool refcount_dec_and_lock(refcount_t *r, spinlock_t *lock)
{
if (refcount_dec_not_one(r))
return false;
spin_lock(lock);
if (!refcount_dec_and_test(r)) {
spin_unlock(lock);
return false;
}
return true;
}
