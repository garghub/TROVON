static const char *i915_fence_get_driver_name(struct dma_fence *fence)
{
return "i915";
}
static const char *i915_fence_get_timeline_name(struct dma_fence *fence)
{
if (test_bit(DMA_FENCE_FLAG_SIGNALED_BIT, &fence->flags))
return "signaled";
return to_request(fence)->timeline->common->name;
}
static bool i915_fence_signaled(struct dma_fence *fence)
{
return i915_gem_request_completed(to_request(fence));
}
static bool i915_fence_enable_signaling(struct dma_fence *fence)
{
if (i915_fence_signaled(fence))
return false;
intel_engine_enable_signaling(to_request(fence));
return true;
}
static signed long i915_fence_wait(struct dma_fence *fence,
bool interruptible,
signed long timeout)
{
return i915_wait_request(to_request(fence), interruptible, timeout);
}
static void i915_fence_release(struct dma_fence *fence)
{
struct drm_i915_gem_request *req = to_request(fence);
i915_sw_fence_fini(&req->submit);
i915_sw_fence_fini(&req->execute);
kmem_cache_free(req->i915->requests, req);
}
int i915_gem_request_add_to_client(struct drm_i915_gem_request *req,
struct drm_file *file)
{
struct drm_i915_private *dev_private;
struct drm_i915_file_private *file_priv;
WARN_ON(!req || !file || req->file_priv);
if (!req || !file)
return -EINVAL;
if (req->file_priv)
return -EINVAL;
dev_private = req->i915;
file_priv = file->driver_priv;
spin_lock(&file_priv->mm.lock);
req->file_priv = file_priv;
list_add_tail(&req->client_list, &file_priv->mm.request_list);
spin_unlock(&file_priv->mm.lock);
return 0;
}
static inline void
i915_gem_request_remove_from_client(struct drm_i915_gem_request *request)
{
struct drm_i915_file_private *file_priv = request->file_priv;
if (!file_priv)
return;
spin_lock(&file_priv->mm.lock);
list_del(&request->client_list);
request->file_priv = NULL;
spin_unlock(&file_priv->mm.lock);
}
static struct i915_dependency *
i915_dependency_alloc(struct drm_i915_private *i915)
{
return kmem_cache_alloc(i915->dependencies, GFP_KERNEL);
}
static void
i915_dependency_free(struct drm_i915_private *i915,
struct i915_dependency *dep)
{
kmem_cache_free(i915->dependencies, dep);
}
static void
__i915_priotree_add_dependency(struct i915_priotree *pt,
struct i915_priotree *signal,
struct i915_dependency *dep,
unsigned long flags)
{
INIT_LIST_HEAD(&dep->dfs_link);
list_add(&dep->wait_link, &signal->waiters_list);
list_add(&dep->signal_link, &pt->signalers_list);
dep->signaler = signal;
dep->flags = flags;
}
static int
i915_priotree_add_dependency(struct drm_i915_private *i915,
struct i915_priotree *pt,
struct i915_priotree *signal)
{
struct i915_dependency *dep;
dep = i915_dependency_alloc(i915);
if (!dep)
return -ENOMEM;
__i915_priotree_add_dependency(pt, signal, dep, I915_DEPENDENCY_ALLOC);
return 0;
}
static void
i915_priotree_fini(struct drm_i915_private *i915, struct i915_priotree *pt)
{
struct i915_dependency *dep, *next;
GEM_BUG_ON(!RB_EMPTY_NODE(&pt->node));
list_for_each_entry_safe(dep, next, &pt->signalers_list, signal_link) {
list_del(&dep->wait_link);
if (dep->flags & I915_DEPENDENCY_ALLOC)
i915_dependency_free(i915, dep);
}
list_for_each_entry_safe(dep, next, &pt->waiters_list, wait_link) {
list_del(&dep->signal_link);
if (dep->flags & I915_DEPENDENCY_ALLOC)
i915_dependency_free(i915, dep);
}
}
static void
i915_priotree_init(struct i915_priotree *pt)
{
INIT_LIST_HEAD(&pt->signalers_list);
INIT_LIST_HEAD(&pt->waiters_list);
RB_CLEAR_NODE(&pt->node);
pt->priority = INT_MIN;
}
void i915_gem_retire_noop(struct i915_gem_active *active,
struct drm_i915_gem_request *request)
{
}
static void i915_gem_request_retire(struct drm_i915_gem_request *request)
{
struct intel_engine_cs *engine = request->engine;
struct i915_gem_active *active, *next;
lockdep_assert_held(&request->i915->drm.struct_mutex);
GEM_BUG_ON(!i915_sw_fence_signaled(&request->submit));
GEM_BUG_ON(!i915_sw_fence_signaled(&request->execute));
GEM_BUG_ON(!i915_gem_request_completed(request));
GEM_BUG_ON(!request->i915->gt.active_requests);
trace_i915_gem_request_retire(request);
spin_lock_irq(&engine->timeline->lock);
list_del_init(&request->link);
spin_unlock_irq(&engine->timeline->lock);
list_del(&request->ring_link);
request->ring->last_retired_head = request->postfix;
if (!--request->i915->gt.active_requests) {
GEM_BUG_ON(!request->i915->gt.awake);
mod_delayed_work(request->i915->wq,
&request->i915->gt.idle_work,
msecs_to_jiffies(100));
}
list_for_each_entry_safe(active, next, &request->active_list, link) {
prefetchw(next);
INIT_LIST_HEAD(&active->link);
RCU_INIT_POINTER(active->request, NULL);
active->retire(active, request);
}
i915_gem_request_remove_from_client(request);
if (request->ctx->ban_score > 0)
request->ctx->ban_score--;
if (engine->last_retired_context)
engine->context_unpin(engine, engine->last_retired_context);
engine->last_retired_context = request->ctx;
dma_fence_signal(&request->fence);
i915_priotree_fini(request->i915, &request->priotree);
i915_gem_request_put(request);
}
void i915_gem_request_retire_upto(struct drm_i915_gem_request *req)
{
struct intel_engine_cs *engine = req->engine;
struct drm_i915_gem_request *tmp;
lockdep_assert_held(&req->i915->drm.struct_mutex);
GEM_BUG_ON(!i915_gem_request_completed(req));
if (list_empty(&req->link))
return;
do {
tmp = list_first_entry(&engine->timeline->requests,
typeof(*tmp), link);
i915_gem_request_retire(tmp);
} while (tmp != req);
}
static int i915_gem_init_global_seqno(struct drm_i915_private *i915, u32 seqno)
{
struct i915_gem_timeline *timeline = &i915->gt.global_timeline;
struct intel_engine_cs *engine;
enum intel_engine_id id;
int ret;
ret = i915_gem_wait_for_idle(i915,
I915_WAIT_INTERRUPTIBLE |
I915_WAIT_LOCKED);
if (ret)
return ret;
i915_gem_retire_requests(i915);
GEM_BUG_ON(i915->gt.active_requests > 1);
if (!i915_seqno_passed(seqno, atomic_read(&timeline->seqno))) {
while (intel_breadcrumbs_busy(i915))
cond_resched();
}
atomic_set(&timeline->seqno, seqno);
for_each_engine(engine, i915, id)
intel_engine_init_global_seqno(engine, seqno);
list_for_each_entry(timeline, &i915->gt.timelines, link) {
for_each_engine(engine, i915, id) {
struct intel_timeline *tl = &timeline->engine[id];
memset(tl->sync_seqno, 0, sizeof(tl->sync_seqno));
}
}
return 0;
}
int i915_gem_set_global_seqno(struct drm_device *dev, u32 seqno)
{
struct drm_i915_private *dev_priv = to_i915(dev);
lockdep_assert_held(&dev_priv->drm.struct_mutex);
if (seqno == 0)
return -EINVAL;
return i915_gem_init_global_seqno(dev_priv, seqno - 1);
}
static int reserve_global_seqno(struct drm_i915_private *i915)
{
u32 active_requests = ++i915->gt.active_requests;
u32 seqno = atomic_read(&i915->gt.global_timeline.seqno);
int ret;
if (likely(seqno + active_requests > seqno))
return 0;
ret = i915_gem_init_global_seqno(i915, 0);
if (ret) {
i915->gt.active_requests--;
return ret;
}
return 0;
}
static u32 __timeline_get_seqno(struct i915_gem_timeline *tl)
{
return ++tl->seqno.counter;
}
static u32 timeline_get_seqno(struct i915_gem_timeline *tl)
{
return atomic_inc_return(&tl->seqno);
}
void __i915_gem_request_submit(struct drm_i915_gem_request *request)
{
struct intel_engine_cs *engine = request->engine;
struct intel_timeline *timeline;
u32 seqno;
timeline = engine->timeline;
GEM_BUG_ON(timeline == request->timeline);
assert_spin_locked(&timeline->lock);
seqno = timeline_get_seqno(timeline->common);
GEM_BUG_ON(!seqno);
GEM_BUG_ON(i915_seqno_passed(intel_engine_get_seqno(engine), seqno));
GEM_BUG_ON(i915_seqno_passed(timeline->last_submitted_seqno, seqno));
request->previous_seqno = timeline->last_submitted_seqno;
timeline->last_submitted_seqno = seqno;
spin_lock_nested(&request->lock, SINGLE_DEPTH_NESTING);
request->global_seqno = seqno;
if (test_bit(DMA_FENCE_FLAG_ENABLE_SIGNAL_BIT, &request->fence.flags))
intel_engine_enable_signaling(request);
spin_unlock(&request->lock);
GEM_BUG_ON(!request->global_seqno);
engine->emit_breadcrumb(request,
request->ring->vaddr + request->postfix);
spin_lock(&request->timeline->lock);
list_move_tail(&request->link, &timeline->requests);
spin_unlock(&request->timeline->lock);
i915_sw_fence_commit(&request->execute);
}
void i915_gem_request_submit(struct drm_i915_gem_request *request)
{
struct intel_engine_cs *engine = request->engine;
unsigned long flags;
spin_lock_irqsave(&engine->timeline->lock, flags);
__i915_gem_request_submit(request);
spin_unlock_irqrestore(&engine->timeline->lock, flags);
}
static int __i915_sw_fence_call
submit_notify(struct i915_sw_fence *fence, enum i915_sw_fence_notify state)
{
struct drm_i915_gem_request *request =
container_of(fence, typeof(*request), submit);
switch (state) {
case FENCE_COMPLETE:
request->engine->submit_request(request);
break;
case FENCE_FREE:
i915_gem_request_put(request);
break;
}
return NOTIFY_DONE;
}
static int __i915_sw_fence_call
execute_notify(struct i915_sw_fence *fence, enum i915_sw_fence_notify state)
{
struct drm_i915_gem_request *request =
container_of(fence, typeof(*request), execute);
switch (state) {
case FENCE_COMPLETE:
break;
case FENCE_FREE:
i915_gem_request_put(request);
break;
}
return NOTIFY_DONE;
}
struct drm_i915_gem_request *
i915_gem_request_alloc(struct intel_engine_cs *engine,
struct i915_gem_context *ctx)
{
struct drm_i915_private *dev_priv = engine->i915;
struct drm_i915_gem_request *req;
int ret;
lockdep_assert_held(&dev_priv->drm.struct_mutex);
if (i915_terminally_wedged(&dev_priv->gpu_error))
return ERR_PTR(-EIO);
ret = engine->context_pin(engine, ctx);
if (ret)
return ERR_PTR(ret);
ret = reserve_global_seqno(dev_priv);
if (ret)
goto err_unpin;
req = list_first_entry_or_null(&engine->timeline->requests,
typeof(*req), link);
if (req && __i915_gem_request_completed(req))
i915_gem_request_retire(req);
req = kmem_cache_alloc(dev_priv->requests, GFP_KERNEL);
if (!req) {
ret = -ENOMEM;
goto err_unreserve;
}
req->timeline = i915_gem_context_lookup_timeline(ctx, engine);
GEM_BUG_ON(req->timeline == engine->timeline);
spin_lock_init(&req->lock);
dma_fence_init(&req->fence,
&i915_fence_ops,
&req->lock,
req->timeline->fence_context,
__timeline_get_seqno(req->timeline->common));
i915_sw_fence_init(&i915_gem_request_get(req)->submit, submit_notify);
i915_sw_fence_init(&i915_gem_request_get(req)->execute, execute_notify);
i915_sw_fence_await_sw_fence(&req->execute, &req->submit, &req->execq);
i915_priotree_init(&req->priotree);
INIT_LIST_HEAD(&req->active_list);
req->i915 = dev_priv;
req->engine = engine;
req->ctx = ctx;
req->global_seqno = 0;
req->file_priv = NULL;
req->batch = NULL;
req->reserved_space = MIN_SPACE_FOR_ADD_REQUEST;
GEM_BUG_ON(req->reserved_space < engine->emit_breadcrumb_sz);
ret = engine->request_alloc(req);
if (ret)
goto err_ctx;
req->head = req->ring->tail;
return req;
err_ctx:
GEM_BUG_ON(!list_empty(&req->active_list));
GEM_BUG_ON(!list_empty(&req->priotree.signalers_list));
GEM_BUG_ON(!list_empty(&req->priotree.waiters_list));
kmem_cache_free(dev_priv->requests, req);
err_unreserve:
dev_priv->gt.active_requests--;
err_unpin:
engine->context_unpin(engine, ctx);
return ERR_PTR(ret);
}
static int
i915_gem_request_await_request(struct drm_i915_gem_request *to,
struct drm_i915_gem_request *from)
{
int ret;
GEM_BUG_ON(to == from);
if (to->engine->schedule) {
ret = i915_priotree_add_dependency(to->i915,
&to->priotree,
&from->priotree);
if (ret < 0)
return ret;
}
if (to->timeline == from->timeline)
return 0;
if (to->engine == from->engine) {
ret = i915_sw_fence_await_sw_fence_gfp(&to->submit,
&from->submit,
GFP_KERNEL);
return ret < 0 ? ret : 0;
}
if (!from->global_seqno) {
ret = i915_sw_fence_await_dma_fence(&to->submit,
&from->fence, 0,
GFP_KERNEL);
return ret < 0 ? ret : 0;
}
if (from->global_seqno <= to->timeline->sync_seqno[from->engine->id])
return 0;
trace_i915_gem_ring_sync_to(to, from);
if (!i915.semaphores) {
if (!i915_spin_request(from, TASK_INTERRUPTIBLE, 2)) {
ret = i915_sw_fence_await_dma_fence(&to->submit,
&from->fence, 0,
GFP_KERNEL);
if (ret < 0)
return ret;
}
} else {
ret = to->engine->semaphore.sync_to(to, from);
if (ret)
return ret;
}
to->timeline->sync_seqno[from->engine->id] = from->global_seqno;
return 0;
}
int
i915_gem_request_await_dma_fence(struct drm_i915_gem_request *req,
struct dma_fence *fence)
{
struct dma_fence_array *array;
int ret;
int i;
if (test_bit(DMA_FENCE_FLAG_SIGNALED_BIT, &fence->flags))
return 0;
if (dma_fence_is_i915(fence))
return i915_gem_request_await_request(req, to_request(fence));
if (!dma_fence_is_array(fence)) {
ret = i915_sw_fence_await_dma_fence(&req->submit,
fence, I915_FENCE_TIMEOUT,
GFP_KERNEL);
return ret < 0 ? ret : 0;
}
array = to_dma_fence_array(fence);
for (i = 0; i < array->num_fences; i++) {
struct dma_fence *child = array->fences[i];
if (dma_fence_is_i915(child))
ret = i915_gem_request_await_request(req,
to_request(child));
else
ret = i915_sw_fence_await_dma_fence(&req->submit,
child, I915_FENCE_TIMEOUT,
GFP_KERNEL);
if (ret < 0)
return ret;
}
return 0;
}
int
i915_gem_request_await_object(struct drm_i915_gem_request *to,
struct drm_i915_gem_object *obj,
bool write)
{
struct dma_fence *excl;
int ret = 0;
if (write) {
struct dma_fence **shared;
unsigned int count, i;
ret = reservation_object_get_fences_rcu(obj->resv,
&excl, &count, &shared);
if (ret)
return ret;
for (i = 0; i < count; i++) {
ret = i915_gem_request_await_dma_fence(to, shared[i]);
if (ret)
break;
dma_fence_put(shared[i]);
}
for (; i < count; i++)
dma_fence_put(shared[i]);
kfree(shared);
} else {
excl = reservation_object_get_excl_rcu(obj->resv);
}
if (excl) {
if (ret == 0)
ret = i915_gem_request_await_dma_fence(to, excl);
dma_fence_put(excl);
}
return ret;
}
static void i915_gem_mark_busy(const struct intel_engine_cs *engine)
{
struct drm_i915_private *dev_priv = engine->i915;
if (dev_priv->gt.awake)
return;
GEM_BUG_ON(!dev_priv->gt.active_requests);
intel_runtime_pm_get_noresume(dev_priv);
dev_priv->gt.awake = true;
intel_enable_gt_powersave(dev_priv);
i915_update_gfx_val(dev_priv);
if (INTEL_GEN(dev_priv) >= 6)
gen6_rps_busy(dev_priv);
queue_delayed_work(dev_priv->wq,
&dev_priv->gt.retire_work,
round_jiffies_up_relative(HZ));
}
void __i915_add_request(struct drm_i915_gem_request *request, bool flush_caches)
{
struct intel_engine_cs *engine = request->engine;
struct intel_ring *ring = request->ring;
struct intel_timeline *timeline = request->timeline;
struct drm_i915_gem_request *prev;
int err;
lockdep_assert_held(&request->i915->drm.struct_mutex);
trace_i915_gem_request_add(request);
GEM_BUG_ON(i915_seqno_passed(timeline->last_submitted_seqno,
request->fence.seqno));
request->reserved_space = 0;
if (flush_caches) {
err = engine->emit_flush(request, EMIT_FLUSH);
WARN(err, "engine->emit_flush() failed: %d!\n", err);
}
err = intel_ring_begin(request, engine->emit_breadcrumb_sz);
GEM_BUG_ON(err);
request->postfix = ring->tail;
ring->tail += engine->emit_breadcrumb_sz * sizeof(u32);
prev = i915_gem_active_raw(&timeline->last_request,
&request->i915->drm.struct_mutex);
if (prev) {
i915_sw_fence_await_sw_fence(&request->submit, &prev->submit,
&request->submitq);
if (engine->schedule)
__i915_priotree_add_dependency(&request->priotree,
&prev->priotree,
&request->dep,
0);
}
spin_lock_irq(&timeline->lock);
list_add_tail(&request->link, &timeline->requests);
spin_unlock_irq(&timeline->lock);
GEM_BUG_ON(i915_seqno_passed(timeline->last_submitted_seqno,
request->fence.seqno));
timeline->last_submitted_seqno = request->fence.seqno;
i915_gem_active_set(&timeline->last_request, request);
list_add_tail(&request->ring_link, &ring->request_list);
request->emitted_jiffies = jiffies;
i915_gem_mark_busy(engine);
if (engine->schedule)
engine->schedule(request, request->ctx->priority);
local_bh_disable();
i915_sw_fence_commit(&request->submit);
local_bh_enable();
}
static void reset_wait_queue(wait_queue_head_t *q, wait_queue_t *wait)
{
unsigned long flags;
spin_lock_irqsave(&q->lock, flags);
if (list_empty(&wait->task_list))
__add_wait_queue(q, wait);
spin_unlock_irqrestore(&q->lock, flags);
}
static unsigned long local_clock_us(unsigned int *cpu)
{
unsigned long t;
*cpu = get_cpu();
t = local_clock() >> 10;
put_cpu();
return t;
}
static bool busywait_stop(unsigned long timeout, unsigned int cpu)
{
unsigned int this_cpu;
if (time_after(local_clock_us(&this_cpu), timeout))
return true;
return this_cpu != cpu;
}
bool __i915_spin_request(const struct drm_i915_gem_request *req,
int state, unsigned long timeout_us)
{
unsigned int cpu;
timeout_us += local_clock_us(&cpu);
do {
if (__i915_gem_request_completed(req))
return true;
if (signal_pending_state(state, current))
break;
if (busywait_stop(timeout_us, cpu))
break;
cpu_relax();
} while (!need_resched());
return false;
}
static long
__i915_request_wait_for_execute(struct drm_i915_gem_request *request,
unsigned int flags,
long timeout)
{
const int state = flags & I915_WAIT_INTERRUPTIBLE ?
TASK_INTERRUPTIBLE : TASK_UNINTERRUPTIBLE;
wait_queue_head_t *q = &request->i915->gpu_error.wait_queue;
DEFINE_WAIT(reset);
DEFINE_WAIT(wait);
if (flags & I915_WAIT_LOCKED)
add_wait_queue(q, &reset);
do {
prepare_to_wait(&request->execute.wait, &wait, state);
if (i915_sw_fence_done(&request->execute))
break;
if (flags & I915_WAIT_LOCKED &&
i915_reset_in_progress(&request->i915->gpu_error)) {
__set_current_state(TASK_RUNNING);
i915_reset(request->i915);
reset_wait_queue(q, &reset);
continue;
}
if (signal_pending_state(state, current)) {
timeout = -ERESTARTSYS;
break;
}
if (!timeout) {
timeout = -ETIME;
break;
}
timeout = io_schedule_timeout(timeout);
} while (1);
finish_wait(&request->execute.wait, &wait);
if (flags & I915_WAIT_LOCKED)
remove_wait_queue(q, &reset);
return timeout;
}
long i915_wait_request(struct drm_i915_gem_request *req,
unsigned int flags,
long timeout)
{
const int state = flags & I915_WAIT_INTERRUPTIBLE ?
TASK_INTERRUPTIBLE : TASK_UNINTERRUPTIBLE;
DEFINE_WAIT(reset);
struct intel_wait wait;
might_sleep();
#if IS_ENABLED(CONFIG_LOCKDEP)
GEM_BUG_ON(debug_locks &&
!!lockdep_is_held(&req->i915->drm.struct_mutex) !=
!!(flags & I915_WAIT_LOCKED));
#endif
GEM_BUG_ON(timeout < 0);
if (i915_gem_request_completed(req))
return timeout;
if (!timeout)
return -ETIME;
trace_i915_gem_request_wait_begin(req);
if (!i915_sw_fence_done(&req->execute)) {
timeout = __i915_request_wait_for_execute(req, flags, timeout);
if (timeout < 0)
goto complete;
GEM_BUG_ON(!i915_sw_fence_done(&req->execute));
}
GEM_BUG_ON(!i915_sw_fence_done(&req->submit));
GEM_BUG_ON(!req->global_seqno);
if (i915_spin_request(req, state, 5))
goto complete;
set_current_state(state);
if (flags & I915_WAIT_LOCKED)
add_wait_queue(&req->i915->gpu_error.wait_queue, &reset);
intel_wait_init(&wait, req->global_seqno);
if (intel_engine_add_wait(req->engine, &wait))
goto wakeup;
for (;;) {
if (signal_pending_state(state, current)) {
timeout = -ERESTARTSYS;
break;
}
if (!timeout) {
timeout = -ETIME;
break;
}
timeout = io_schedule_timeout(timeout);
if (intel_wait_complete(&wait))
break;
set_current_state(state);
wakeup:
if (__i915_request_irq_complete(req))
break;
if (flags & I915_WAIT_LOCKED &&
i915_reset_in_progress(&req->i915->gpu_error)) {
__set_current_state(TASK_RUNNING);
i915_reset(req->i915);
reset_wait_queue(&req->i915->gpu_error.wait_queue,
&reset);
continue;
}
if (i915_spin_request(req, state, 2))
break;
}
intel_engine_remove_wait(req->engine, &wait);
if (flags & I915_WAIT_LOCKED)
remove_wait_queue(&req->i915->gpu_error.wait_queue, &reset);
__set_current_state(TASK_RUNNING);
complete:
trace_i915_gem_request_wait_end(req);
return timeout;
}
static void engine_retire_requests(struct intel_engine_cs *engine)
{
struct drm_i915_gem_request *request, *next;
list_for_each_entry_safe(request, next,
&engine->timeline->requests, link) {
if (!__i915_gem_request_completed(request))
return;
i915_gem_request_retire(request);
}
}
void i915_gem_retire_requests(struct drm_i915_private *dev_priv)
{
struct intel_engine_cs *engine;
enum intel_engine_id id;
lockdep_assert_held(&dev_priv->drm.struct_mutex);
if (!dev_priv->gt.active_requests)
return;
for_each_engine(engine, dev_priv, id)
engine_retire_requests(engine);
}
