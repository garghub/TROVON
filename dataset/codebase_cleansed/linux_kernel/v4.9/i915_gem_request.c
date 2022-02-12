static const char *i915_fence_get_driver_name(struct fence *fence)
{
return "i915";
}
static const char *i915_fence_get_timeline_name(struct fence *fence)
{
return "global";
}
static bool i915_fence_signaled(struct fence *fence)
{
return i915_gem_request_completed(to_request(fence));
}
static bool i915_fence_enable_signaling(struct fence *fence)
{
if (i915_fence_signaled(fence))
return false;
intel_engine_enable_signaling(to_request(fence));
return true;
}
static signed long i915_fence_wait(struct fence *fence,
bool interruptible,
signed long timeout_jiffies)
{
s64 timeout_ns, *timeout;
int ret;
if (timeout_jiffies != MAX_SCHEDULE_TIMEOUT) {
timeout_ns = jiffies_to_nsecs(timeout_jiffies);
timeout = &timeout_ns;
} else {
timeout = NULL;
}
ret = i915_wait_request(to_request(fence),
interruptible, timeout,
NO_WAITBOOST);
if (ret == -ETIME)
return 0;
if (ret < 0)
return ret;
if (timeout_jiffies != MAX_SCHEDULE_TIMEOUT)
timeout_jiffies = nsecs_to_jiffies(timeout_ns);
return timeout_jiffies;
}
static void i915_fence_value_str(struct fence *fence, char *str, int size)
{
snprintf(str, size, "%u", fence->seqno);
}
static void i915_fence_timeline_value_str(struct fence *fence, char *str,
int size)
{
snprintf(str, size, "%u",
intel_engine_get_seqno(to_request(fence)->engine));
}
static void i915_fence_release(struct fence *fence)
{
struct drm_i915_gem_request *req = to_request(fence);
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
void i915_gem_retire_noop(struct i915_gem_active *active,
struct drm_i915_gem_request *request)
{
}
static void i915_gem_request_retire(struct drm_i915_gem_request *request)
{
struct i915_gem_active *active, *next;
trace_i915_gem_request_retire(request);
list_del(&request->link);
list_del(&request->ring_link);
request->ring->last_retired_head = request->postfix;
list_for_each_entry_safe(active, next, &request->active_list, link) {
prefetchw(next);
INIT_LIST_HEAD(&active->link);
RCU_INIT_POINTER(active->request, NULL);
active->retire(active, request);
}
i915_gem_request_remove_from_client(request);
if (request->previous_context) {
if (i915.enable_execlists)
intel_lr_context_unpin(request->previous_context,
request->engine);
}
i915_gem_context_put(request->ctx);
i915_gem_request_put(request);
}
void i915_gem_request_retire_upto(struct drm_i915_gem_request *req)
{
struct intel_engine_cs *engine = req->engine;
struct drm_i915_gem_request *tmp;
lockdep_assert_held(&req->i915->drm.struct_mutex);
GEM_BUG_ON(list_empty(&req->link));
do {
tmp = list_first_entry(&engine->request_list,
typeof(*tmp), link);
i915_gem_request_retire(tmp);
} while (tmp != req);
}
static int i915_gem_check_wedge(struct drm_i915_private *dev_priv)
{
struct i915_gpu_error *error = &dev_priv->gpu_error;
if (i915_terminally_wedged(error))
return -EIO;
if (i915_reset_in_progress(error)) {
if (!dev_priv->mm.interruptible)
return -EIO;
return -EAGAIN;
}
return 0;
}
static int i915_gem_init_seqno(struct drm_i915_private *dev_priv, u32 seqno)
{
struct intel_engine_cs *engine;
int ret;
for_each_engine(engine, dev_priv) {
ret = intel_engine_idle(engine,
I915_WAIT_INTERRUPTIBLE |
I915_WAIT_LOCKED);
if (ret)
return ret;
}
i915_gem_retire_requests(dev_priv);
if (!i915_seqno_passed(seqno, dev_priv->next_seqno)) {
while (intel_kick_waiters(dev_priv) ||
intel_kick_signalers(dev_priv))
yield();
}
for_each_engine(engine, dev_priv)
intel_engine_init_seqno(engine, seqno);
return 0;
}
int i915_gem_set_seqno(struct drm_device *dev, u32 seqno)
{
struct drm_i915_private *dev_priv = to_i915(dev);
int ret;
if (seqno == 0)
return -EINVAL;
ret = i915_gem_init_seqno(dev_priv, seqno - 1);
if (ret)
return ret;
dev_priv->next_seqno = seqno;
return 0;
}
static int i915_gem_get_seqno(struct drm_i915_private *dev_priv, u32 *seqno)
{
if (unlikely(dev_priv->next_seqno == 0)) {
int ret;
ret = i915_gem_init_seqno(dev_priv, 0);
if (ret)
return ret;
dev_priv->next_seqno = 1;
}
*seqno = dev_priv->next_seqno++;
return 0;
}
static int __i915_sw_fence_call
submit_notify(struct i915_sw_fence *fence, enum i915_sw_fence_notify state)
{
struct drm_i915_gem_request *request =
container_of(fence, typeof(*request), submit);
switch (state) {
case FENCE_COMPLETE:
request->engine->last_submitted_seqno = request->fence.seqno;
request->engine->submit_request(request);
break;
case FENCE_FREE:
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
u32 seqno;
int ret;
ret = i915_gem_check_wedge(dev_priv);
if (ret)
return ERR_PTR(ret);
req = list_first_entry_or_null(&engine->request_list,
typeof(*req), link);
if (req && i915_gem_request_completed(req))
i915_gem_request_retire(req);
req = kmem_cache_alloc(dev_priv->requests, GFP_KERNEL);
if (!req)
return ERR_PTR(-ENOMEM);
ret = i915_gem_get_seqno(dev_priv, &seqno);
if (ret)
goto err;
spin_lock_init(&req->lock);
fence_init(&req->fence,
&i915_fence_ops,
&req->lock,
engine->fence_context,
seqno);
i915_sw_fence_init(&req->submit, submit_notify);
INIT_LIST_HEAD(&req->active_list);
req->i915 = dev_priv;
req->engine = engine;
req->ctx = i915_gem_context_get(ctx);
req->previous_context = NULL;
req->file_priv = NULL;
req->batch = NULL;
req->reserved_space = MIN_SPACE_FOR_ADD_REQUEST;
if (i915.enable_execlists)
ret = intel_logical_ring_alloc_request_extras(req);
else
ret = intel_ring_alloc_request_extras(req);
if (ret)
goto err_ctx;
req->head = req->ring->tail;
return req;
err_ctx:
i915_gem_context_put(ctx);
err:
kmem_cache_free(dev_priv->requests, req);
return ERR_PTR(ret);
}
static int
i915_gem_request_await_request(struct drm_i915_gem_request *to,
struct drm_i915_gem_request *from)
{
int idx, ret;
GEM_BUG_ON(to == from);
if (to->engine == from->engine)
return 0;
idx = intel_engine_sync_index(from->engine, to->engine);
if (from->fence.seqno <= from->engine->semaphore.sync_seqno[idx])
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
from->engine->semaphore.sync_seqno[idx] = from->fence.seqno;
return 0;
}
int
i915_gem_request_await_object(struct drm_i915_gem_request *to,
struct drm_i915_gem_object *obj,
bool write)
{
struct i915_gem_active *active;
unsigned long active_mask;
int idx;
if (write) {
active_mask = i915_gem_object_get_active(obj);
active = obj->last_read;
} else {
active_mask = 1;
active = &obj->last_write;
}
for_each_active(active_mask, idx) {
struct drm_i915_gem_request *request;
int ret;
request = i915_gem_active_peek(&active[idx],
&obj->base.dev->struct_mutex);
if (!request)
continue;
ret = i915_gem_request_await_request(to, request);
if (ret)
return ret;
}
return 0;
}
static void i915_gem_mark_busy(const struct intel_engine_cs *engine)
{
struct drm_i915_private *dev_priv = engine->i915;
dev_priv->gt.active_engines |= intel_engine_flag(engine);
if (dev_priv->gt.awake)
return;
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
struct drm_i915_gem_request *prev;
u32 request_start;
u32 reserved_tail;
int ret;
trace_i915_gem_request_add(request);
request_start = ring->tail;
reserved_tail = request->reserved_space;
request->reserved_space = 0;
if (flush_caches) {
ret = engine->emit_flush(request, EMIT_FLUSH);
WARN(ret, "engine->emit_flush() failed: %d!\n", ret);
}
request->postfix = ring->tail;
ret = engine->emit_request(request);
WARN(ret, "(%s)->emit_request failed: %d!\n", engine->name, ret);
ret = ring->tail - request_start;
if (ret < 0)
ret += ring->size;
WARN_ONCE(ret > reserved_tail,
"Not enough space reserved (%d bytes) "
"for adding the request (%d bytes)\n",
reserved_tail, ret);
prev = i915_gem_active_raw(&engine->last_request,
&request->i915->drm.struct_mutex);
if (prev)
i915_sw_fence_await_sw_fence(&request->submit, &prev->submit,
&request->submitq);
request->emitted_jiffies = jiffies;
request->previous_seqno = engine->last_pending_seqno;
engine->last_pending_seqno = request->fence.seqno;
i915_gem_active_set(&engine->last_request, request);
list_add_tail(&request->link, &engine->request_list);
list_add_tail(&request->ring_link, &ring->request_list);
i915_gem_mark_busy(engine);
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
if (i915_gem_request_completed(req))
return true;
if (signal_pending_state(state, current))
break;
if (busywait_stop(timeout_us, cpu))
break;
cpu_relax_lowlatency();
} while (!need_resched());
return false;
}
int i915_wait_request(struct drm_i915_gem_request *req,
unsigned int flags,
s64 *timeout,
struct intel_rps_client *rps)
{
const int state = flags & I915_WAIT_INTERRUPTIBLE ?
TASK_INTERRUPTIBLE : TASK_UNINTERRUPTIBLE;
DEFINE_WAIT(reset);
struct intel_wait wait;
unsigned long timeout_remain;
int ret = 0;
might_sleep();
#if IS_ENABLED(CONFIG_LOCKDEP)
GEM_BUG_ON(!!lockdep_is_held(&req->i915->drm.struct_mutex) !=
!!(flags & I915_WAIT_LOCKED));
#endif
if (i915_gem_request_completed(req))
return 0;
timeout_remain = MAX_SCHEDULE_TIMEOUT;
if (timeout) {
if (WARN_ON(*timeout < 0))
return -EINVAL;
if (*timeout == 0)
return -ETIME;
timeout_remain = nsecs_to_jiffies_timeout(*timeout);
*timeout += ktime_get_raw_ns();
}
trace_i915_gem_request_wait_begin(req);
if (IS_RPS_CLIENT(rps) && INTEL_GEN(req->i915) >= 6)
gen6_rps_boost(req->i915, rps, req->emitted_jiffies);
if (i915_spin_request(req, state, 5))
goto complete;
set_current_state(state);
if (flags & I915_WAIT_LOCKED)
add_wait_queue(&req->i915->gpu_error.wait_queue, &reset);
intel_wait_init(&wait, req->fence.seqno);
if (intel_engine_add_wait(req->engine, &wait))
goto wakeup;
for (;;) {
if (signal_pending_state(state, current)) {
ret = -ERESTARTSYS;
break;
}
timeout_remain = io_schedule_timeout(timeout_remain);
if (timeout_remain == 0) {
ret = -ETIME;
break;
}
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
if (timeout) {
*timeout -= ktime_get_raw_ns();
if (*timeout < 0)
*timeout = 0;
if (ret == -ETIME && *timeout < jiffies_to_usecs(1)*1000)
*timeout = 0;
}
if (IS_RPS_USER(rps) &&
req->fence.seqno == req->engine->last_submitted_seqno) {
spin_lock(&req->i915->rps.client_lock);
list_del_init(&rps->link);
spin_unlock(&req->i915->rps.client_lock);
}
return ret;
}
static bool engine_retire_requests(struct intel_engine_cs *engine)
{
struct drm_i915_gem_request *request, *next;
list_for_each_entry_safe(request, next, &engine->request_list, link) {
if (!i915_gem_request_completed(request))
return false;
i915_gem_request_retire(request);
}
return true;
}
void i915_gem_retire_requests(struct drm_i915_private *dev_priv)
{
struct intel_engine_cs *engine;
unsigned int tmp;
lockdep_assert_held(&dev_priv->drm.struct_mutex);
if (dev_priv->gt.active_engines == 0)
return;
GEM_BUG_ON(!dev_priv->gt.awake);
for_each_engine_masked(engine, dev_priv, dev_priv->gt.active_engines, tmp)
if (engine_retire_requests(engine))
dev_priv->gt.active_engines &= ~intel_engine_flag(engine);
if (dev_priv->gt.active_engines == 0)
queue_delayed_work(dev_priv->wq,
&dev_priv->gt.idle_work,
msecs_to_jiffies(100));
}
