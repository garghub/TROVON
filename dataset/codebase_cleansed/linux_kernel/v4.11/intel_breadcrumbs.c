static void intel_breadcrumbs_hangcheck(unsigned long data)
{
struct intel_engine_cs *engine = (struct intel_engine_cs *)data;
struct intel_breadcrumbs *b = &engine->breadcrumbs;
if (!b->irq_enabled)
return;
if (time_before(jiffies, b->timeout)) {
mod_timer(&b->hangcheck, b->timeout);
return;
}
DRM_DEBUG("Hangcheck timer elapsed... %s idle\n", engine->name);
set_bit(engine->id, &engine->i915->gpu_error.missed_irq_rings);
mod_timer(&engine->breadcrumbs.fake_irq, jiffies + 1);
i915_queue_hangcheck(engine->i915);
}
static unsigned long wait_timeout(void)
{
return round_jiffies_up(jiffies + DRM_I915_HANGCHECK_JIFFIES);
}
static void intel_breadcrumbs_fake_irq(unsigned long data)
{
struct intel_engine_cs *engine = (struct intel_engine_cs *)data;
if (intel_engine_wakeup(engine))
mod_timer(&engine->breadcrumbs.fake_irq, jiffies + 1);
}
static void irq_enable(struct intel_engine_cs *engine)
{
engine->breadcrumbs.irq_posted = true;
spin_lock(&engine->i915->irq_lock);
engine->irq_enable(engine);
spin_unlock(&engine->i915->irq_lock);
}
static void irq_disable(struct intel_engine_cs *engine)
{
spin_lock(&engine->i915->irq_lock);
engine->irq_disable(engine);
spin_unlock(&engine->i915->irq_lock);
engine->breadcrumbs.irq_posted = false;
}
static void __intel_breadcrumbs_enable_irq(struct intel_breadcrumbs *b)
{
struct intel_engine_cs *engine =
container_of(b, struct intel_engine_cs, breadcrumbs);
struct drm_i915_private *i915 = engine->i915;
assert_spin_locked(&b->lock);
if (b->rpm_wakelock)
return;
intel_runtime_pm_get_noresume(i915);
b->rpm_wakelock = true;
if (intel_irqs_enabled(i915)) {
if (!test_bit(engine->id, &i915->gpu_error.test_irq_rings))
irq_enable(engine);
b->irq_enabled = true;
}
if (!b->irq_enabled ||
test_bit(engine->id, &i915->gpu_error.missed_irq_rings)) {
mod_timer(&b->fake_irq, jiffies + 1);
} else {
GEM_BUG_ON(!time_after(b->timeout, jiffies));
mod_timer(&b->hangcheck, b->timeout);
}
}
static void __intel_breadcrumbs_disable_irq(struct intel_breadcrumbs *b)
{
struct intel_engine_cs *engine =
container_of(b, struct intel_engine_cs, breadcrumbs);
assert_spin_locked(&b->lock);
if (!b->rpm_wakelock)
return;
if (b->irq_enabled) {
irq_disable(engine);
b->irq_enabled = false;
}
intel_runtime_pm_put(engine->i915);
b->rpm_wakelock = false;
}
static inline struct intel_wait *to_wait(struct rb_node *node)
{
return rb_entry(node, struct intel_wait, node);
}
static inline void __intel_breadcrumbs_finish(struct intel_breadcrumbs *b,
struct intel_wait *wait)
{
assert_spin_locked(&b->lock);
rb_erase(&wait->node, &b->waiters);
RB_CLEAR_NODE(&wait->node);
wake_up_process(wait->tsk);
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
GEM_BUG_ON(!first && !rcu_access_pointer(b->irq_seqno_bh));
if (completed) {
struct rb_node *next = rb_next(completed);
GEM_BUG_ON(!next && !first);
if (next && next != &wait->node) {
GEM_BUG_ON(first);
b->timeout = wait_timeout();
b->first_wait = to_wait(next);
rcu_assign_pointer(b->irq_seqno_bh, b->first_wait->tsk);
__intel_breadcrumbs_enable_irq(b);
if (READ_ONCE(b->irq_posted))
wake_up_process(to_wait(next)->tsk);
}
do {
struct intel_wait *crumb = to_wait(completed);
completed = rb_prev(completed);
__intel_breadcrumbs_finish(b, crumb);
} while (completed);
}
if (first) {
GEM_BUG_ON(rb_first(&b->waiters) != &wait->node);
b->timeout = wait_timeout();
b->first_wait = wait;
rcu_assign_pointer(b->irq_seqno_bh, wait->tsk);
__intel_breadcrumbs_enable_irq(b);
}
GEM_BUG_ON(!rcu_access_pointer(b->irq_seqno_bh));
GEM_BUG_ON(!b->first_wait);
GEM_BUG_ON(rb_first(&b->waiters) != &b->first_wait->node);
return first;
}
bool intel_engine_add_wait(struct intel_engine_cs *engine,
struct intel_wait *wait)
{
struct intel_breadcrumbs *b = &engine->breadcrumbs;
bool first;
spin_lock_irq(&b->lock);
first = __intel_engine_add_wait(engine, wait);
spin_unlock_irq(&b->lock);
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
void intel_engine_remove_wait(struct intel_engine_cs *engine,
struct intel_wait *wait)
{
struct intel_breadcrumbs *b = &engine->breadcrumbs;
if (RB_EMPTY_NODE(&wait->node))
return;
spin_lock_irq(&b->lock);
if (RB_EMPTY_NODE(&wait->node))
goto out_unlock;
if (b->first_wait == wait) {
const int priority = wakeup_priority(b, wait->tsk);
struct rb_node *next;
GEM_BUG_ON(rcu_access_pointer(b->irq_seqno_bh) != wait->tsk);
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
if (next) {
b->timeout = wait_timeout();
b->first_wait = to_wait(next);
rcu_assign_pointer(b->irq_seqno_bh, b->first_wait->tsk);
if (b->first_wait->seqno != wait->seqno)
__intel_breadcrumbs_enable_irq(b);
wake_up_process(b->first_wait->tsk);
} else {
b->first_wait = NULL;
rcu_assign_pointer(b->irq_seqno_bh, NULL);
__intel_breadcrumbs_disable_irq(b);
}
} else {
GEM_BUG_ON(rb_first(&b->waiters) == &wait->node);
}
GEM_BUG_ON(RB_EMPTY_NODE(&wait->node));
rb_erase(&wait->node, &b->waiters);
out_unlock:
GEM_BUG_ON(b->first_wait == wait);
GEM_BUG_ON(rb_first(&b->waiters) !=
(b->first_wait ? &b->first_wait->node : NULL));
GEM_BUG_ON(!rcu_access_pointer(b->irq_seqno_bh) ^ RB_EMPTY_ROOT(&b->waiters));
spin_unlock_irq(&b->lock);
}
static bool signal_complete(struct drm_i915_gem_request *request)
{
if (!request)
return false;
if (intel_wait_complete(&request->signaling.wait))
return true;
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
set_current_state(TASK_INTERRUPTIBLE);
request = READ_ONCE(b->first_signal);
if (signal_complete(request)) {
intel_engine_remove_wait(engine,
&request->signaling.wait);
local_bh_disable();
dma_fence_signal(&request->fence);
local_bh_enable();
spin_lock_irq(&b->lock);
if (request == b->first_signal) {
struct rb_node *rb =
rb_next(&request->signaling.node);
b->first_signal = rb ? to_signaler(rb) : NULL;
}
rb_erase(&request->signaling.node, &b->signals);
spin_unlock_irq(&b->lock);
i915_gem_request_put(request);
} else {
if (kthread_should_stop())
break;
schedule();
}
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
assert_spin_locked(&request->lock);
if (!request->global_seqno)
return;
request->signaling.wait.tsk = b->signaler;
request->signaling.wait.seqno = request->global_seqno;
i915_gem_request_get(request);
spin_lock(&b->lock);
wakeup = __intel_engine_add_wait(engine, &request->signaling.wait);
parent = NULL;
first = true;
p = &b->signals.rb_node;
while (*p) {
parent = *p;
if (i915_seqno_passed(request->global_seqno,
to_signaler(parent)->global_seqno)) {
p = &parent->rb_right;
first = false;
} else {
p = &parent->rb_left;
}
}
rb_link_node(&request->signaling.node, parent, p);
rb_insert_color(&request->signaling.node, &b->signals);
if (first)
smp_store_mb(b->first_signal, request);
spin_unlock(&b->lock);
if (wakeup)
wake_up_process(b->signaler);
}
int intel_engine_init_breadcrumbs(struct intel_engine_cs *engine)
{
struct intel_breadcrumbs *b = &engine->breadcrumbs;
struct task_struct *tsk;
spin_lock_init(&b->lock);
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
spin_lock_irq(&b->lock);
__intel_breadcrumbs_disable_irq(b);
if (intel_engine_has_waiter(engine)) {
b->timeout = wait_timeout();
__intel_breadcrumbs_enable_irq(b);
if (READ_ONCE(b->irq_posted))
wake_up_process(b->first_wait->tsk);
} else {
irq_disable(engine);
}
spin_unlock_irq(&b->lock);
}
void intel_engine_fini_breadcrumbs(struct intel_engine_cs *engine)
{
struct intel_breadcrumbs *b = &engine->breadcrumbs;
WARN_ON(READ_ONCE(b->first_wait));
WARN_ON(!RB_EMPTY_ROOT(&b->waiters));
WARN_ON(READ_ONCE(b->first_signal));
WARN_ON(!RB_EMPTY_ROOT(&b->signals));
if (!IS_ERR_OR_NULL(b->signaler))
kthread_stop(b->signaler);
cancel_fake_irq(engine);
}
unsigned int intel_breadcrumbs_busy(struct drm_i915_private *i915)
{
struct intel_engine_cs *engine;
enum intel_engine_id id;
unsigned int mask = 0;
for_each_engine(engine, i915, id) {
struct intel_breadcrumbs *b = &engine->breadcrumbs;
spin_lock_irq(&b->lock);
if (b->first_wait) {
wake_up_process(b->first_wait->tsk);
mask |= intel_engine_flag(engine);
}
if (b->first_signal) {
wake_up_process(b->signaler);
mask |= intel_engine_flag(engine);
}
spin_unlock_irq(&b->lock);
}
return mask;
}
