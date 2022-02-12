static unsigned int __intel_breadcrumbs_wakeup(struct intel_breadcrumbs *b)
{
struct intel_wait *wait;
unsigned int result = 0;
lockdep_assert_held(&b->irq_lock);
wait = b->irq_wait;
if (wait) {
result = ENGINE_WAKEUP_WAITER;
if (wake_up_process(wait->tsk))
result |= ENGINE_WAKEUP_ASLEEP;
}
return result;
}
unsigned int intel_engine_wakeup(struct intel_engine_cs *engine)
{
struct intel_breadcrumbs *b = &engine->breadcrumbs;
unsigned long flags;
unsigned int result;
spin_lock_irqsave(&b->irq_lock, flags);
result = __intel_breadcrumbs_wakeup(b);
spin_unlock_irqrestore(&b->irq_lock, flags);
return result;
}
static unsigned long wait_timeout(void)
{
return round_jiffies_up(jiffies + DRM_I915_HANGCHECK_JIFFIES);
}
static noinline void missed_breadcrumb(struct intel_engine_cs *engine)
{
DRM_DEBUG_DRIVER("%s missed breadcrumb at %pF, irq posted? %s\n",
engine->name, __builtin_return_address(0),
yesno(test_bit(ENGINE_IRQ_BREADCRUMB,
&engine->irq_posted)));
set_bit(engine->id, &engine->i915->gpu_error.missed_irq_rings);
}
static void intel_breadcrumbs_hangcheck(unsigned long data)
{
struct intel_engine_cs *engine = (struct intel_engine_cs *)data;
struct intel_breadcrumbs *b = &engine->breadcrumbs;
if (!b->irq_armed)
return;
if (b->hangcheck_interrupts != atomic_read(&engine->irq_count)) {
b->hangcheck_interrupts = atomic_read(&engine->irq_count);
mod_timer(&b->hangcheck, wait_timeout());
return;
}
if (intel_engine_wakeup(engine) & ENGINE_WAKEUP_ASLEEP) {
missed_breadcrumb(engine);
mod_timer(&engine->breadcrumbs.fake_irq, jiffies + 1);
} else {
mod_timer(&b->hangcheck, wait_timeout());
}
}
static void intel_breadcrumbs_fake_irq(unsigned long data)
{
struct intel_engine_cs *engine = (struct intel_engine_cs *)data;
struct intel_breadcrumbs *b = &engine->breadcrumbs;
spin_lock_irq(&b->irq_lock);
if (!__intel_breadcrumbs_wakeup(b))
__intel_engine_disarm_breadcrumbs(engine);
spin_unlock_irq(&b->irq_lock);
if (!b->irq_armed)
return;
mod_timer(&b->fake_irq, jiffies + 1);
i915_queue_hangcheck(engine->i915);
}
static void irq_enable(struct intel_engine_cs *engine)
{
set_bit(ENGINE_IRQ_BREADCRUMB, &engine->irq_posted);
spin_lock(&engine->i915->irq_lock);
engine->irq_enable(engine);
spin_unlock(&engine->i915->irq_lock);
}
static void irq_disable(struct intel_engine_cs *engine)
{
spin_lock(&engine->i915->irq_lock);
engine->irq_disable(engine);
spin_unlock(&engine->i915->irq_lock);
}
void __intel_engine_disarm_breadcrumbs(struct intel_engine_cs *engine)
{
struct intel_breadcrumbs *b = &engine->breadcrumbs;
lockdep_assert_held(&b->irq_lock);
GEM_BUG_ON(b->irq_wait);
if (b->irq_enabled) {
irq_disable(engine);
b->irq_enabled = false;
}
b->irq_armed = false;
}
void intel_engine_disarm_breadcrumbs(struct intel_engine_cs *engine)
{
struct intel_breadcrumbs *b = &engine->breadcrumbs;
struct intel_wait *wait, *n, *first;
if (!b->irq_armed)
return;
spin_lock_irq(&b->rb_lock);
spin_lock(&b->irq_lock);
first = fetch_and_zero(&b->irq_wait);
__intel_engine_disarm_breadcrumbs(engine);
spin_unlock(&b->irq_lock);
rbtree_postorder_for_each_entry_safe(wait, n, &b->waiters, node) {
RB_CLEAR_NODE(&wait->node);
if (wake_up_process(wait->tsk) && wait == first)
missed_breadcrumb(engine);
}
b->waiters = RB_ROOT;
spin_unlock_irq(&b->rb_lock);
}
static bool use_fake_irq(const struct intel_breadcrumbs *b)
{
const struct intel_engine_cs *engine =
container_of(b, struct intel_engine_cs, breadcrumbs);
if (!test_bit(engine->id, &engine->i915->gpu_error.missed_irq_rings))
return false;
return atomic_read(&engine->irq_count) == b->hangcheck_interrupts;
}
static void enable_fake_irq(struct intel_breadcrumbs *b)
{
if (!b->irq_enabled || use_fake_irq(b))
mod_timer(&b->fake_irq, jiffies + 1);
else
mod_timer(&b->hangcheck, wait_timeout());
}
static void __intel_breadcrumbs_enable_irq(struct intel_breadcrumbs *b)
{
struct intel_engine_cs *engine =
container_of(b, struct intel_engine_cs, breadcrumbs);
struct drm_i915_private *i915 = engine->i915;
lockdep_assert_held(&b->irq_lock);
if (b->irq_armed)
return;
b->irq_armed = true;
GEM_BUG_ON(b->irq_enabled);
if (I915_SELFTEST_ONLY(b->mock)) {
return;
}
if (intel_irqs_enabled(i915)) {
if (!test_bit(engine->id, &i915->gpu_error.test_irq_rings))
irq_enable(engine);
b->irq_enabled = true;
}
enable_fake_irq(b);
}
static inline struct intel_wait *to_wait(struct rb_node *node)
{
return rb_entry(node, struct intel_wait, node);
}
static inline void __intel_breadcrumbs_finish(struct intel_breadcrumbs *b,
struct intel_wait *wait)
{
lockdep_assert_held(&b->rb_lock);
GEM_BUG_ON(b->irq_wait == wait);
rb_erase(&wait->node, &b->waiters);
RB_CLEAR_NODE(&wait->node);
wake_up_process(wait->tsk);
}
static inline void __intel_breadcrumbs_next(struct intel_engine_cs *engine,
struct rb_node *next)
{
struct intel_breadcrumbs *b = &engine->breadcrumbs;
spin_lock(&b->irq_lock);
GEM_BUG_ON(!b->irq_armed);
GEM_BUG_ON(!b->irq_wait);
b->irq_wait = to_wait(next);
spin_unlock(&b->irq_lock);
if (next)
wake_up_process(to_wait(next)->tsk);
}
static bool __intel_engine_add_wait(struct intel_engine_cs *engine,
struct intel_wait *wait)
{
struct intel_breadcrumbs *b = &engine->breadcrumbs;
struct rb_node **p, *parent, *completed;
bool first;
u32 seqno;
first = true;
parent = NULL;
completed = NULL;
seqno = intel_engine_get_seqno(engine);
if (i915_seqno_passed(seqno, wait->seqno)) {
RB_CLEAR_NODE(&wait->node);
return first;
}
p = &b->waiters.rb_node;
while (*p) {
parent = *p;
if (wait->seqno == to_wait(parent)->seqno) {
if (wait->tsk->prio > to_wait(parent)->tsk->prio) {
p = &parent->rb_right;
first = false;
} else {
p = &parent->rb_left;
}
} else if (i915_seqno_passed(wait->seqno,
to_wait(parent)->seqno)) {
p = &parent->rb_right;
if (i915_seqno_passed(seqno, to_wait(parent)->seqno))
completed = parent;
else
first = false;
} else {
p = &parent->rb_left;
}
}
rb_link_node(&wait->node, parent, p);
rb_insert_color(&wait->node, &b->waiters);
if (first) {
spin_lock(&b->irq_lock);
b->irq_wait = wait;
__intel_breadcrumbs_enable_irq(b);
spin_unlock(&b->irq_lock);
}
if (completed) {
if (!first) {
struct rb_node *next = rb_next(completed);
GEM_BUG_ON(next == &wait->node);
__intel_breadcrumbs_next(engine, next);
}
do {
struct intel_wait *crumb = to_wait(completed);
completed = rb_prev(completed);
__intel_breadcrumbs_finish(b, crumb);
} while (completed);
}
GEM_BUG_ON(!b->irq_wait);
GEM_BUG_ON(!b->irq_armed);
GEM_BUG_ON(rb_first(&b->waiters) != &b->irq_wait->node);
return first;
}
bool intel_engine_add_wait(struct intel_engine_cs *engine,
struct intel_wait *wait)
{
struct intel_breadcrumbs *b = &engine->breadcrumbs;
bool first;
spin_lock_irq(&b->rb_lock);
first = __intel_engine_add_wait(engine, wait);
spin_unlock_irq(&b->rb_lock);
return first;
}
static inline bool chain_wakeup(struct rb_node *rb, int priority)
{
return rb && to_wait(rb)->tsk->prio <= priority;
}
static inline int wakeup_priority(struct intel_breadcrumbs *b,
struct task_struct *tsk)
{
if (tsk == b->signaler)
return INT_MIN;
else
return tsk->prio;
}
static void __intel_engine_remove_wait(struct intel_engine_cs *engine,
struct intel_wait *wait)
{
struct intel_breadcrumbs *b = &engine->breadcrumbs;
lockdep_assert_held(&b->rb_lock);
if (RB_EMPTY_NODE(&wait->node))
goto out;
if (b->irq_wait == wait) {
const int priority = wakeup_priority(b, wait->tsk);
struct rb_node *next;
next = rb_next(&wait->node);
if (chain_wakeup(next, priority)) {
u32 seqno = intel_engine_get_seqno(engine);
while (i915_seqno_passed(seqno, to_wait(next)->seqno)) {
struct rb_node *n = rb_next(next);
__intel_breadcrumbs_finish(b, to_wait(next));
next = n;
if (!chain_wakeup(next, priority))
break;
}
}
__intel_breadcrumbs_next(engine, next);
} else {
GEM_BUG_ON(rb_first(&b->waiters) == &wait->node);
}
GEM_BUG_ON(RB_EMPTY_NODE(&wait->node));
rb_erase(&wait->node, &b->waiters);
out:
GEM_BUG_ON(b->irq_wait == wait);
GEM_BUG_ON(rb_first(&b->waiters) !=
(b->irq_wait ? &b->irq_wait->node : NULL));
}
void intel_engine_remove_wait(struct intel_engine_cs *engine,
struct intel_wait *wait)
{
struct intel_breadcrumbs *b = &engine->breadcrumbs;
if (RB_EMPTY_NODE(&wait->node)) {
GEM_BUG_ON(READ_ONCE(b->irq_wait) == wait);
return;
}
spin_lock_irq(&b->rb_lock);
__intel_engine_remove_wait(engine, wait);
spin_unlock_irq(&b->rb_lock);
}
static bool signal_valid(const struct drm_i915_gem_request *request)
{
return intel_wait_check_request(&request->signaling.wait, request);
}
static bool signal_complete(const struct drm_i915_gem_request *request)
{
if (!request)
return false;
if (intel_wait_complete(&request->signaling.wait))
return signal_valid(request);
if (__i915_request_irq_complete(request))
return true;
return false;
}
static struct drm_i915_gem_request *to_signaler(struct rb_node *rb)
{
return rb_entry(rb, struct drm_i915_gem_request, signaling.node);
}
static void signaler_set_rtpriority(void)
{
struct sched_param param = { .sched_priority = 1 };
sched_setscheduler_nocheck(current, SCHED_FIFO, &param);
}
static int intel_breadcrumbs_signaler(void *arg)
{
struct intel_engine_cs *engine = arg;
struct intel_breadcrumbs *b = &engine->breadcrumbs;
struct drm_i915_gem_request *request;
signaler_set_rtpriority();
do {
bool do_schedule = true;
set_current_state(TASK_INTERRUPTIBLE);
rcu_read_lock();
request = rcu_dereference(b->first_signal);
if (request)
request = i915_gem_request_get_rcu(request);
rcu_read_unlock();
if (signal_complete(request)) {
local_bh_disable();
dma_fence_signal(&request->fence);
local_bh_enable();
spin_lock_irq(&b->rb_lock);
__intel_engine_remove_wait(engine,
&request->signaling.wait);
if (request == rcu_access_pointer(b->first_signal)) {
struct rb_node *rb =
rb_next(&request->signaling.node);
rcu_assign_pointer(b->first_signal,
rb ? to_signaler(rb) : NULL);
}
rb_erase(&request->signaling.node, &b->signals);
RB_CLEAR_NODE(&request->signaling.node);
spin_unlock_irq(&b->rb_lock);
i915_gem_request_put(request);
do_schedule = need_resched();
}
if (unlikely(do_schedule)) {
DEFINE_WAIT(exec);
if (kthread_should_park())
kthread_parkme();
if (kthread_should_stop()) {
GEM_BUG_ON(request);
break;
}
if (request)
add_wait_queue(&request->execute, &exec);
schedule();
if (request)
remove_wait_queue(&request->execute, &exec);
}
i915_gem_request_put(request);
} while (1);
__set_current_state(TASK_RUNNING);
return 0;
}
void intel_engine_enable_signaling(struct drm_i915_gem_request *request)
{
struct intel_engine_cs *engine = request->engine;
struct intel_breadcrumbs *b = &engine->breadcrumbs;
struct rb_node *parent, **p;
bool first, wakeup;
u32 seqno;
GEM_BUG_ON(!irqs_disabled());
lockdep_assert_held(&request->lock);
seqno = i915_gem_request_global_seqno(request);
if (!seqno)
return;
request->signaling.wait.tsk = b->signaler;
request->signaling.wait.request = request;
request->signaling.wait.seqno = seqno;
i915_gem_request_get(request);
spin_lock(&b->rb_lock);
wakeup = __intel_engine_add_wait(engine, &request->signaling.wait);
parent = NULL;
first = true;
p = &b->signals.rb_node;
while (*p) {
parent = *p;
if (i915_seqno_passed(seqno,
to_signaler(parent)->signaling.wait.seqno)) {
p = &parent->rb_right;
first = false;
} else {
p = &parent->rb_left;
}
}
rb_link_node(&request->signaling.node, parent, p);
rb_insert_color(&request->signaling.node, &b->signals);
if (first)
rcu_assign_pointer(b->first_signal, request);
spin_unlock(&b->rb_lock);
if (wakeup)
wake_up_process(b->signaler);
}
void intel_engine_cancel_signaling(struct drm_i915_gem_request *request)
{
struct intel_engine_cs *engine = request->engine;
struct intel_breadcrumbs *b = &engine->breadcrumbs;
GEM_BUG_ON(!irqs_disabled());
lockdep_assert_held(&request->lock);
GEM_BUG_ON(!request->signaling.wait.seqno);
spin_lock(&b->rb_lock);
if (!RB_EMPTY_NODE(&request->signaling.node)) {
if (request == rcu_access_pointer(b->first_signal)) {
struct rb_node *rb =
rb_next(&request->signaling.node);
rcu_assign_pointer(b->first_signal,
rb ? to_signaler(rb) : NULL);
}
rb_erase(&request->signaling.node, &b->signals);
RB_CLEAR_NODE(&request->signaling.node);
i915_gem_request_put(request);
}
__intel_engine_remove_wait(engine, &request->signaling.wait);
spin_unlock(&b->rb_lock);
request->signaling.wait.seqno = 0;
}
int intel_engine_init_breadcrumbs(struct intel_engine_cs *engine)
{
struct intel_breadcrumbs *b = &engine->breadcrumbs;
struct task_struct *tsk;
spin_lock_init(&b->rb_lock);
spin_lock_init(&b->irq_lock);
setup_timer(&b->fake_irq,
intel_breadcrumbs_fake_irq,
(unsigned long)engine);
setup_timer(&b->hangcheck,
intel_breadcrumbs_hangcheck,
(unsigned long)engine);
tsk = kthread_run(intel_breadcrumbs_signaler, engine,
"i915/signal:%d", engine->id);
if (IS_ERR(tsk))
return PTR_ERR(tsk);
b->signaler = tsk;
return 0;
}
static void cancel_fake_irq(struct intel_engine_cs *engine)
{
struct intel_breadcrumbs *b = &engine->breadcrumbs;
del_timer_sync(&b->hangcheck);
del_timer_sync(&b->fake_irq);
clear_bit(engine->id, &engine->i915->gpu_error.missed_irq_rings);
}
void intel_engine_reset_breadcrumbs(struct intel_engine_cs *engine)
{
struct intel_breadcrumbs *b = &engine->breadcrumbs;
cancel_fake_irq(engine);
spin_lock_irq(&b->irq_lock);
if (b->irq_enabled)
irq_enable(engine);
else
irq_disable(engine);
clear_bit(ENGINE_IRQ_BREADCRUMB, &engine->irq_posted);
if (b->irq_armed)
enable_fake_irq(b);
spin_unlock_irq(&b->irq_lock);
}
void intel_engine_fini_breadcrumbs(struct intel_engine_cs *engine)
{
struct intel_breadcrumbs *b = &engine->breadcrumbs;
WARN_ON(READ_ONCE(b->irq_wait));
WARN_ON(!RB_EMPTY_ROOT(&b->waiters));
WARN_ON(rcu_access_pointer(b->first_signal));
WARN_ON(!RB_EMPTY_ROOT(&b->signals));
if (!IS_ERR_OR_NULL(b->signaler))
kthread_stop(b->signaler);
cancel_fake_irq(engine);
}
bool intel_breadcrumbs_busy(struct intel_engine_cs *engine)
{
struct intel_breadcrumbs *b = &engine->breadcrumbs;
bool busy = false;
spin_lock_irq(&b->rb_lock);
if (b->irq_wait) {
wake_up_process(b->irq_wait->tsk);
busy = true;
}
if (rcu_access_pointer(b->first_signal)) {
wake_up_process(b->signaler);
busy = true;
}
spin_unlock_irq(&b->rb_lock);
return busy;
}
