int reservation_object_reserve_shared(struct reservation_object *obj)
{
struct reservation_object_list *fobj, *old;
u32 max;
old = reservation_object_get_list(obj);
if (old && old->shared_max) {
if (old->shared_count < old->shared_max) {
kfree(obj->staged);
obj->staged = NULL;
return 0;
} else
max = old->shared_max * 2;
} else
max = 4;
fobj = krealloc(obj->staged, offsetof(typeof(*fobj), shared[max]),
GFP_KERNEL);
if (!fobj)
return -ENOMEM;
obj->staged = fobj;
fobj->shared_max = max;
return 0;
}
static void
reservation_object_add_shared_inplace(struct reservation_object *obj,
struct reservation_object_list *fobj,
struct fence *fence)
{
u32 i;
fence_get(fence);
preempt_disable();
write_seqcount_begin(&obj->seq);
for (i = 0; i < fobj->shared_count; ++i) {
struct fence *old_fence;
old_fence = rcu_dereference_protected(fobj->shared[i],
reservation_object_held(obj));
if (old_fence->context == fence->context) {
RCU_INIT_POINTER(fobj->shared[i], fence);
write_seqcount_end(&obj->seq);
preempt_enable();
fence_put(old_fence);
return;
}
}
RCU_INIT_POINTER(fobj->shared[fobj->shared_count], fence);
fobj->shared_count++;
write_seqcount_end(&obj->seq);
preempt_enable();
}
static void
reservation_object_add_shared_replace(struct reservation_object *obj,
struct reservation_object_list *old,
struct reservation_object_list *fobj,
struct fence *fence)
{
unsigned i;
struct fence *old_fence = NULL;
fence_get(fence);
if (!old) {
RCU_INIT_POINTER(fobj->shared[0], fence);
fobj->shared_count = 1;
goto done;
}
fobj->shared_count = old->shared_count;
for (i = 0; i < old->shared_count; ++i) {
struct fence *check;
check = rcu_dereference_protected(old->shared[i],
reservation_object_held(obj));
if (!old_fence && check->context == fence->context) {
old_fence = check;
RCU_INIT_POINTER(fobj->shared[i], fence);
} else
RCU_INIT_POINTER(fobj->shared[i], check);
}
if (!old_fence) {
RCU_INIT_POINTER(fobj->shared[fobj->shared_count], fence);
fobj->shared_count++;
}
done:
preempt_disable();
write_seqcount_begin(&obj->seq);
RCU_INIT_POINTER(obj->fence, fobj);
write_seqcount_end(&obj->seq);
preempt_enable();
if (old)
kfree_rcu(old, rcu);
if (old_fence)
fence_put(old_fence);
}
void reservation_object_add_shared_fence(struct reservation_object *obj,
struct fence *fence)
{
struct reservation_object_list *old, *fobj = obj->staged;
old = reservation_object_get_list(obj);
obj->staged = NULL;
if (!fobj) {
BUG_ON(old->shared_count >= old->shared_max);
reservation_object_add_shared_inplace(obj, old, fence);
} else
reservation_object_add_shared_replace(obj, old, fobj, fence);
}
void reservation_object_add_excl_fence(struct reservation_object *obj,
struct fence *fence)
{
struct fence *old_fence = reservation_object_get_excl(obj);
struct reservation_object_list *old;
u32 i = 0;
old = reservation_object_get_list(obj);
if (old)
i = old->shared_count;
if (fence)
fence_get(fence);
preempt_disable();
write_seqcount_begin(&obj->seq);
RCU_INIT_POINTER(obj->fence_excl, fence);
if (old)
old->shared_count = 0;
write_seqcount_end(&obj->seq);
preempt_enable();
while (i--)
fence_put(rcu_dereference_protected(old->shared[i],
reservation_object_held(obj)));
if (old_fence)
fence_put(old_fence);
}
int reservation_object_get_fences_rcu(struct reservation_object *obj,
struct fence **pfence_excl,
unsigned *pshared_count,
struct fence ***pshared)
{
unsigned shared_count = 0;
unsigned retry = 1;
struct fence **shared = NULL, *fence_excl = NULL;
int ret = 0;
while (retry) {
struct reservation_object_list *fobj;
unsigned seq;
seq = read_seqcount_begin(&obj->seq);
rcu_read_lock();
fobj = rcu_dereference(obj->fence);
if (fobj) {
struct fence **nshared;
size_t sz = sizeof(*shared) * fobj->shared_max;
nshared = krealloc(shared, sz,
GFP_NOWAIT | __GFP_NOWARN);
if (!nshared) {
rcu_read_unlock();
nshared = krealloc(shared, sz, GFP_KERNEL);
if (nshared) {
shared = nshared;
continue;
}
ret = -ENOMEM;
shared_count = 0;
break;
}
shared = nshared;
memcpy(shared, fobj->shared, sz);
shared_count = fobj->shared_count;
} else
shared_count = 0;
fence_excl = rcu_dereference(obj->fence_excl);
retry = read_seqcount_retry(&obj->seq, seq);
if (retry)
goto unlock;
if (!fence_excl || fence_get_rcu(fence_excl)) {
unsigned i;
for (i = 0; i < shared_count; ++i) {
if (fence_get_rcu(shared[i]))
continue;
while (i--)
fence_put(shared[i]);
if (fence_excl) {
fence_put(fence_excl);
fence_excl = NULL;
}
retry = 1;
break;
}
} else
retry = 1;
unlock:
rcu_read_unlock();
}
*pshared_count = shared_count;
if (shared_count)
*pshared = shared;
else {
*pshared = NULL;
kfree(shared);
}
*pfence_excl = fence_excl;
return ret;
}
long reservation_object_wait_timeout_rcu(struct reservation_object *obj,
bool wait_all, bool intr,
unsigned long timeout)
{
struct fence *fence;
unsigned seq, shared_count, i = 0;
long ret = timeout;
retry:
fence = NULL;
shared_count = 0;
seq = read_seqcount_begin(&obj->seq);
rcu_read_lock();
if (wait_all) {
struct reservation_object_list *fobj = rcu_dereference(obj->fence);
if (fobj)
shared_count = fobj->shared_count;
if (read_seqcount_retry(&obj->seq, seq))
goto unlock_retry;
for (i = 0; i < shared_count; ++i) {
struct fence *lfence = rcu_dereference(fobj->shared[i]);
if (test_bit(FENCE_FLAG_SIGNALED_BIT, &lfence->flags))
continue;
if (!fence_get_rcu(lfence))
goto unlock_retry;
if (fence_is_signaled(lfence)) {
fence_put(lfence);
continue;
}
fence = lfence;
break;
}
}
if (!shared_count) {
struct fence *fence_excl = rcu_dereference(obj->fence_excl);
if (read_seqcount_retry(&obj->seq, seq))
goto unlock_retry;
if (fence_excl &&
!test_bit(FENCE_FLAG_SIGNALED_BIT, &fence_excl->flags)) {
if (!fence_get_rcu(fence_excl))
goto unlock_retry;
if (fence_is_signaled(fence_excl))
fence_put(fence_excl);
else
fence = fence_excl;
}
}
rcu_read_unlock();
if (fence) {
ret = fence_wait_timeout(fence, intr, ret);
fence_put(fence);
if (ret > 0 && wait_all && (i + 1 < shared_count))
goto retry;
}
return ret;
unlock_retry:
rcu_read_unlock();
goto retry;
}
static inline int
reservation_object_test_signaled_single(struct fence *passed_fence)
{
struct fence *fence, *lfence = passed_fence;
int ret = 1;
if (!test_bit(FENCE_FLAG_SIGNALED_BIT, &lfence->flags)) {
int ret;
fence = fence_get_rcu(lfence);
if (!fence)
return -1;
ret = !!fence_is_signaled(fence);
fence_put(fence);
}
return ret;
}
bool reservation_object_test_signaled_rcu(struct reservation_object *obj,
bool test_all)
{
unsigned seq, shared_count;
int ret = true;
retry:
shared_count = 0;
seq = read_seqcount_begin(&obj->seq);
rcu_read_lock();
if (test_all) {
unsigned i;
struct reservation_object_list *fobj = rcu_dereference(obj->fence);
if (fobj)
shared_count = fobj->shared_count;
if (read_seqcount_retry(&obj->seq, seq))
goto unlock_retry;
for (i = 0; i < shared_count; ++i) {
struct fence *fence = rcu_dereference(fobj->shared[i]);
ret = reservation_object_test_signaled_single(fence);
if (ret < 0)
goto unlock_retry;
else if (!ret)
break;
}
}
if (!shared_count) {
struct fence *fence_excl = rcu_dereference(obj->fence_excl);
if (read_seqcount_retry(&obj->seq, seq))
goto unlock_retry;
if (fence_excl) {
ret = reservation_object_test_signaled_single(fence_excl);
if (ret < 0)
goto unlock_retry;
}
}
rcu_read_unlock();
return ret;
unlock_retry:
rcu_read_unlock();
goto retry;
}
