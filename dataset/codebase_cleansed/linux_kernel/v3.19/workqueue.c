static void *work_debug_hint(void *addr)
{
return ((struct work_struct *) addr)->func;
}
static int work_fixup_init(void *addr, enum debug_obj_state state)
{
struct work_struct *work = addr;
switch (state) {
case ODEBUG_STATE_ACTIVE:
cancel_work_sync(work);
debug_object_init(work, &work_debug_descr);
return 1;
default:
return 0;
}
}
static int work_fixup_activate(void *addr, enum debug_obj_state state)
{
struct work_struct *work = addr;
switch (state) {
case ODEBUG_STATE_NOTAVAILABLE:
if (test_bit(WORK_STRUCT_STATIC_BIT, work_data_bits(work))) {
debug_object_init(work, &work_debug_descr);
debug_object_activate(work, &work_debug_descr);
return 0;
}
WARN_ON_ONCE(1);
return 0;
case ODEBUG_STATE_ACTIVE:
WARN_ON(1);
default:
return 0;
}
}
static int work_fixup_free(void *addr, enum debug_obj_state state)
{
struct work_struct *work = addr;
switch (state) {
case ODEBUG_STATE_ACTIVE:
cancel_work_sync(work);
debug_object_free(work, &work_debug_descr);
return 1;
default:
return 0;
}
}
static inline void debug_work_activate(struct work_struct *work)
{
debug_object_activate(work, &work_debug_descr);
}
static inline void debug_work_deactivate(struct work_struct *work)
{
debug_object_deactivate(work, &work_debug_descr);
}
void __init_work(struct work_struct *work, int onstack)
{
if (onstack)
debug_object_init_on_stack(work, &work_debug_descr);
else
debug_object_init(work, &work_debug_descr);
}
void destroy_work_on_stack(struct work_struct *work)
{
debug_object_free(work, &work_debug_descr);
}
void destroy_delayed_work_on_stack(struct delayed_work *work)
{
destroy_timer_on_stack(&work->timer);
debug_object_free(&work->work, &work_debug_descr);
}
static inline void debug_work_activate(struct work_struct *work) { }
static inline void debug_work_deactivate(struct work_struct *work) { }
static int worker_pool_assign_id(struct worker_pool *pool)
{
int ret;
lockdep_assert_held(&wq_pool_mutex);
ret = idr_alloc(&worker_pool_idr, pool, 0, WORK_OFFQ_POOL_NONE,
GFP_KERNEL);
if (ret >= 0) {
pool->id = ret;
return 0;
}
return ret;
}
static struct pool_workqueue *unbound_pwq_by_node(struct workqueue_struct *wq,
int node)
{
assert_rcu_or_wq_mutex(wq);
return rcu_dereference_raw(wq->numa_pwq_tbl[node]);
}
static unsigned int work_color_to_flags(int color)
{
return color << WORK_STRUCT_COLOR_SHIFT;
}
static int get_work_color(struct work_struct *work)
{
return (*work_data_bits(work) >> WORK_STRUCT_COLOR_SHIFT) &
((1 << WORK_STRUCT_COLOR_BITS) - 1);
}
static int work_next_color(int color)
{
return (color + 1) % WORK_NR_COLORS;
}
static inline void set_work_data(struct work_struct *work, unsigned long data,
unsigned long flags)
{
WARN_ON_ONCE(!work_pending(work));
atomic_long_set(&work->data, data | flags | work_static(work));
}
static void set_work_pwq(struct work_struct *work, struct pool_workqueue *pwq,
unsigned long extra_flags)
{
set_work_data(work, (unsigned long)pwq,
WORK_STRUCT_PENDING | WORK_STRUCT_PWQ | extra_flags);
}
static void set_work_pool_and_keep_pending(struct work_struct *work,
int pool_id)
{
set_work_data(work, (unsigned long)pool_id << WORK_OFFQ_POOL_SHIFT,
WORK_STRUCT_PENDING);
}
static void set_work_pool_and_clear_pending(struct work_struct *work,
int pool_id)
{
smp_wmb();
set_work_data(work, (unsigned long)pool_id << WORK_OFFQ_POOL_SHIFT, 0);
}
static void clear_work_data(struct work_struct *work)
{
smp_wmb();
set_work_data(work, WORK_STRUCT_NO_POOL, 0);
}
static struct pool_workqueue *get_work_pwq(struct work_struct *work)
{
unsigned long data = atomic_long_read(&work->data);
if (data & WORK_STRUCT_PWQ)
return (void *)(data & WORK_STRUCT_WQ_DATA_MASK);
else
return NULL;
}
static struct worker_pool *get_work_pool(struct work_struct *work)
{
unsigned long data = atomic_long_read(&work->data);
int pool_id;
assert_rcu_or_pool_mutex();
if (data & WORK_STRUCT_PWQ)
return ((struct pool_workqueue *)
(data & WORK_STRUCT_WQ_DATA_MASK))->pool;
pool_id = data >> WORK_OFFQ_POOL_SHIFT;
if (pool_id == WORK_OFFQ_POOL_NONE)
return NULL;
return idr_find(&worker_pool_idr, pool_id);
}
static int get_work_pool_id(struct work_struct *work)
{
unsigned long data = atomic_long_read(&work->data);
if (data & WORK_STRUCT_PWQ)
return ((struct pool_workqueue *)
(data & WORK_STRUCT_WQ_DATA_MASK))->pool->id;
return data >> WORK_OFFQ_POOL_SHIFT;
}
static void mark_work_canceling(struct work_struct *work)
{
unsigned long pool_id = get_work_pool_id(work);
pool_id <<= WORK_OFFQ_POOL_SHIFT;
set_work_data(work, pool_id | WORK_OFFQ_CANCELING, WORK_STRUCT_PENDING);
}
static bool work_is_canceling(struct work_struct *work)
{
unsigned long data = atomic_long_read(&work->data);
return !(data & WORK_STRUCT_PWQ) && (data & WORK_OFFQ_CANCELING);
}
static bool __need_more_worker(struct worker_pool *pool)
{
return !atomic_read(&pool->nr_running);
}
static bool need_more_worker(struct worker_pool *pool)
{
return !list_empty(&pool->worklist) && __need_more_worker(pool);
}
static bool may_start_working(struct worker_pool *pool)
{
return pool->nr_idle;
}
static bool keep_working(struct worker_pool *pool)
{
return !list_empty(&pool->worklist) &&
atomic_read(&pool->nr_running) <= 1;
}
static bool need_to_create_worker(struct worker_pool *pool)
{
return need_more_worker(pool) && !may_start_working(pool);
}
static bool too_many_workers(struct worker_pool *pool)
{
bool managing = mutex_is_locked(&pool->manager_arb);
int nr_idle = pool->nr_idle + managing;
int nr_busy = pool->nr_workers - nr_idle;
return nr_idle > 2 && (nr_idle - 2) * MAX_IDLE_WORKERS_RATIO >= nr_busy;
}
static struct worker *first_idle_worker(struct worker_pool *pool)
{
if (unlikely(list_empty(&pool->idle_list)))
return NULL;
return list_first_entry(&pool->idle_list, struct worker, entry);
}
static void wake_up_worker(struct worker_pool *pool)
{
struct worker *worker = first_idle_worker(pool);
if (likely(worker))
wake_up_process(worker->task);
}
void wq_worker_waking_up(struct task_struct *task, int cpu)
{
struct worker *worker = kthread_data(task);
if (!(worker->flags & WORKER_NOT_RUNNING)) {
WARN_ON_ONCE(worker->pool->cpu != cpu);
atomic_inc(&worker->pool->nr_running);
}
}
struct task_struct *wq_worker_sleeping(struct task_struct *task, int cpu)
{
struct worker *worker = kthread_data(task), *to_wakeup = NULL;
struct worker_pool *pool;
if (worker->flags & WORKER_NOT_RUNNING)
return NULL;
pool = worker->pool;
if (WARN_ON_ONCE(cpu != raw_smp_processor_id() || pool->cpu != cpu))
return NULL;
if (atomic_dec_and_test(&pool->nr_running) &&
!list_empty(&pool->worklist))
to_wakeup = first_idle_worker(pool);
return to_wakeup ? to_wakeup->task : NULL;
}
static inline void worker_set_flags(struct worker *worker, unsigned int flags)
{
struct worker_pool *pool = worker->pool;
WARN_ON_ONCE(worker->task != current);
if ((flags & WORKER_NOT_RUNNING) &&
!(worker->flags & WORKER_NOT_RUNNING)) {
atomic_dec(&pool->nr_running);
}
worker->flags |= flags;
}
static inline void worker_clr_flags(struct worker *worker, unsigned int flags)
{
struct worker_pool *pool = worker->pool;
unsigned int oflags = worker->flags;
WARN_ON_ONCE(worker->task != current);
worker->flags &= ~flags;
if ((flags & WORKER_NOT_RUNNING) && (oflags & WORKER_NOT_RUNNING))
if (!(worker->flags & WORKER_NOT_RUNNING))
atomic_inc(&pool->nr_running);
}
static struct worker *find_worker_executing_work(struct worker_pool *pool,
struct work_struct *work)
{
struct worker *worker;
hash_for_each_possible(pool->busy_hash, worker, hentry,
(unsigned long)work)
if (worker->current_work == work &&
worker->current_func == work->func)
return worker;
return NULL;
}
static void move_linked_works(struct work_struct *work, struct list_head *head,
struct work_struct **nextp)
{
struct work_struct *n;
list_for_each_entry_safe_from(work, n, NULL, entry) {
list_move_tail(&work->entry, head);
if (!(*work_data_bits(work) & WORK_STRUCT_LINKED))
break;
}
if (nextp)
*nextp = n;
}
static void get_pwq(struct pool_workqueue *pwq)
{
lockdep_assert_held(&pwq->pool->lock);
WARN_ON_ONCE(pwq->refcnt <= 0);
pwq->refcnt++;
}
static void put_pwq(struct pool_workqueue *pwq)
{
lockdep_assert_held(&pwq->pool->lock);
if (likely(--pwq->refcnt))
return;
if (WARN_ON_ONCE(!(pwq->wq->flags & WQ_UNBOUND)))
return;
schedule_work(&pwq->unbound_release_work);
}
static void put_pwq_unlocked(struct pool_workqueue *pwq)
{
if (pwq) {
spin_lock_irq(&pwq->pool->lock);
put_pwq(pwq);
spin_unlock_irq(&pwq->pool->lock);
}
}
static void pwq_activate_delayed_work(struct work_struct *work)
{
struct pool_workqueue *pwq = get_work_pwq(work);
trace_workqueue_activate_work(work);
move_linked_works(work, &pwq->pool->worklist, NULL);
__clear_bit(WORK_STRUCT_DELAYED_BIT, work_data_bits(work));
pwq->nr_active++;
}
static void pwq_activate_first_delayed(struct pool_workqueue *pwq)
{
struct work_struct *work = list_first_entry(&pwq->delayed_works,
struct work_struct, entry);
pwq_activate_delayed_work(work);
}
static void pwq_dec_nr_in_flight(struct pool_workqueue *pwq, int color)
{
if (color == WORK_NO_COLOR)
goto out_put;
pwq->nr_in_flight[color]--;
pwq->nr_active--;
if (!list_empty(&pwq->delayed_works)) {
if (pwq->nr_active < pwq->max_active)
pwq_activate_first_delayed(pwq);
}
if (likely(pwq->flush_color != color))
goto out_put;
if (pwq->nr_in_flight[color])
goto out_put;
pwq->flush_color = -1;
if (atomic_dec_and_test(&pwq->wq->nr_pwqs_to_flush))
complete(&pwq->wq->first_flusher->done);
out_put:
put_pwq(pwq);
}
static int try_to_grab_pending(struct work_struct *work, bool is_dwork,
unsigned long *flags)
{
struct worker_pool *pool;
struct pool_workqueue *pwq;
local_irq_save(*flags);
if (is_dwork) {
struct delayed_work *dwork = to_delayed_work(work);
if (likely(del_timer(&dwork->timer)))
return 1;
}
if (!test_and_set_bit(WORK_STRUCT_PENDING_BIT, work_data_bits(work)))
return 0;
pool = get_work_pool(work);
if (!pool)
goto fail;
spin_lock(&pool->lock);
pwq = get_work_pwq(work);
if (pwq && pwq->pool == pool) {
debug_work_deactivate(work);
if (*work_data_bits(work) & WORK_STRUCT_DELAYED)
pwq_activate_delayed_work(work);
list_del_init(&work->entry);
pwq_dec_nr_in_flight(pwq, get_work_color(work));
set_work_pool_and_keep_pending(work, pool->id);
spin_unlock(&pool->lock);
return 1;
}
spin_unlock(&pool->lock);
fail:
local_irq_restore(*flags);
if (work_is_canceling(work))
return -ENOENT;
cpu_relax();
return -EAGAIN;
}
static void insert_work(struct pool_workqueue *pwq, struct work_struct *work,
struct list_head *head, unsigned int extra_flags)
{
struct worker_pool *pool = pwq->pool;
set_work_pwq(work, pwq, extra_flags);
list_add_tail(&work->entry, head);
get_pwq(pwq);
smp_mb();
if (__need_more_worker(pool))
wake_up_worker(pool);
}
static bool is_chained_work(struct workqueue_struct *wq)
{
struct worker *worker;
worker = current_wq_worker();
return worker && worker->current_pwq->wq == wq;
}
static void __queue_work(int cpu, struct workqueue_struct *wq,
struct work_struct *work)
{
struct pool_workqueue *pwq;
struct worker_pool *last_pool;
struct list_head *worklist;
unsigned int work_flags;
unsigned int req_cpu = cpu;
WARN_ON_ONCE(!irqs_disabled());
debug_work_activate(work);
if (unlikely(wq->flags & __WQ_DRAINING) &&
WARN_ON_ONCE(!is_chained_work(wq)))
return;
retry:
if (req_cpu == WORK_CPU_UNBOUND)
cpu = raw_smp_processor_id();
if (!(wq->flags & WQ_UNBOUND))
pwq = per_cpu_ptr(wq->cpu_pwqs, cpu);
else
pwq = unbound_pwq_by_node(wq, cpu_to_node(cpu));
last_pool = get_work_pool(work);
if (last_pool && last_pool != pwq->pool) {
struct worker *worker;
spin_lock(&last_pool->lock);
worker = find_worker_executing_work(last_pool, work);
if (worker && worker->current_pwq->wq == wq) {
pwq = worker->current_pwq;
} else {
spin_unlock(&last_pool->lock);
spin_lock(&pwq->pool->lock);
}
} else {
spin_lock(&pwq->pool->lock);
}
if (unlikely(!pwq->refcnt)) {
if (wq->flags & WQ_UNBOUND) {
spin_unlock(&pwq->pool->lock);
cpu_relax();
goto retry;
}
WARN_ONCE(true, "workqueue: per-cpu pwq for %s on cpu%d has 0 refcnt",
wq->name, cpu);
}
trace_workqueue_queue_work(req_cpu, pwq, work);
if (WARN_ON(!list_empty(&work->entry))) {
spin_unlock(&pwq->pool->lock);
return;
}
pwq->nr_in_flight[pwq->work_color]++;
work_flags = work_color_to_flags(pwq->work_color);
if (likely(pwq->nr_active < pwq->max_active)) {
trace_workqueue_activate_work(work);
pwq->nr_active++;
worklist = &pwq->pool->worklist;
} else {
work_flags |= WORK_STRUCT_DELAYED;
worklist = &pwq->delayed_works;
}
insert_work(pwq, work, worklist, work_flags);
spin_unlock(&pwq->pool->lock);
}
bool queue_work_on(int cpu, struct workqueue_struct *wq,
struct work_struct *work)
{
bool ret = false;
unsigned long flags;
local_irq_save(flags);
if (!test_and_set_bit(WORK_STRUCT_PENDING_BIT, work_data_bits(work))) {
__queue_work(cpu, wq, work);
ret = true;
}
local_irq_restore(flags);
return ret;
}
void delayed_work_timer_fn(unsigned long __data)
{
struct delayed_work *dwork = (struct delayed_work *)__data;
__queue_work(dwork->cpu, dwork->wq, &dwork->work);
}
static void __queue_delayed_work(int cpu, struct workqueue_struct *wq,
struct delayed_work *dwork, unsigned long delay)
{
struct timer_list *timer = &dwork->timer;
struct work_struct *work = &dwork->work;
WARN_ON_ONCE(timer->function != delayed_work_timer_fn ||
timer->data != (unsigned long)dwork);
WARN_ON_ONCE(timer_pending(timer));
WARN_ON_ONCE(!list_empty(&work->entry));
if (!delay) {
__queue_work(cpu, wq, &dwork->work);
return;
}
timer_stats_timer_set_start_info(&dwork->timer);
dwork->wq = wq;
dwork->cpu = cpu;
timer->expires = jiffies + delay;
if (unlikely(cpu != WORK_CPU_UNBOUND))
add_timer_on(timer, cpu);
else
add_timer(timer);
}
bool queue_delayed_work_on(int cpu, struct workqueue_struct *wq,
struct delayed_work *dwork, unsigned long delay)
{
struct work_struct *work = &dwork->work;
bool ret = false;
unsigned long flags;
local_irq_save(flags);
if (!test_and_set_bit(WORK_STRUCT_PENDING_BIT, work_data_bits(work))) {
__queue_delayed_work(cpu, wq, dwork, delay);
ret = true;
}
local_irq_restore(flags);
return ret;
}
bool mod_delayed_work_on(int cpu, struct workqueue_struct *wq,
struct delayed_work *dwork, unsigned long delay)
{
unsigned long flags;
int ret;
do {
ret = try_to_grab_pending(&dwork->work, true, &flags);
} while (unlikely(ret == -EAGAIN));
if (likely(ret >= 0)) {
__queue_delayed_work(cpu, wq, dwork, delay);
local_irq_restore(flags);
}
return ret;
}
static void worker_enter_idle(struct worker *worker)
{
struct worker_pool *pool = worker->pool;
if (WARN_ON_ONCE(worker->flags & WORKER_IDLE) ||
WARN_ON_ONCE(!list_empty(&worker->entry) &&
(worker->hentry.next || worker->hentry.pprev)))
return;
worker->flags |= WORKER_IDLE;
pool->nr_idle++;
worker->last_active = jiffies;
list_add(&worker->entry, &pool->idle_list);
if (too_many_workers(pool) && !timer_pending(&pool->idle_timer))
mod_timer(&pool->idle_timer, jiffies + IDLE_WORKER_TIMEOUT);
WARN_ON_ONCE(!(pool->flags & POOL_DISASSOCIATED) &&
pool->nr_workers == pool->nr_idle &&
atomic_read(&pool->nr_running));
}
static void worker_leave_idle(struct worker *worker)
{
struct worker_pool *pool = worker->pool;
if (WARN_ON_ONCE(!(worker->flags & WORKER_IDLE)))
return;
worker_clr_flags(worker, WORKER_IDLE);
pool->nr_idle--;
list_del_init(&worker->entry);
}
static struct worker *alloc_worker(int node)
{
struct worker *worker;
worker = kzalloc_node(sizeof(*worker), GFP_KERNEL, node);
if (worker) {
INIT_LIST_HEAD(&worker->entry);
INIT_LIST_HEAD(&worker->scheduled);
INIT_LIST_HEAD(&worker->node);
worker->flags = WORKER_PREP;
}
return worker;
}
static void worker_attach_to_pool(struct worker *worker,
struct worker_pool *pool)
{
mutex_lock(&pool->attach_mutex);
set_cpus_allowed_ptr(worker->task, pool->attrs->cpumask);
if (pool->flags & POOL_DISASSOCIATED)
worker->flags |= WORKER_UNBOUND;
list_add_tail(&worker->node, &pool->workers);
mutex_unlock(&pool->attach_mutex);
}
static void worker_detach_from_pool(struct worker *worker,
struct worker_pool *pool)
{
struct completion *detach_completion = NULL;
mutex_lock(&pool->attach_mutex);
list_del(&worker->node);
if (list_empty(&pool->workers))
detach_completion = pool->detach_completion;
mutex_unlock(&pool->attach_mutex);
worker->flags &= ~(WORKER_UNBOUND | WORKER_REBOUND);
if (detach_completion)
complete(detach_completion);
}
static struct worker *create_worker(struct worker_pool *pool)
{
struct worker *worker = NULL;
int id = -1;
char id_buf[16];
id = ida_simple_get(&pool->worker_ida, 0, 0, GFP_KERNEL);
if (id < 0)
goto fail;
worker = alloc_worker(pool->node);
if (!worker)
goto fail;
worker->pool = pool;
worker->id = id;
if (pool->cpu >= 0)
snprintf(id_buf, sizeof(id_buf), "%d:%d%s", pool->cpu, id,
pool->attrs->nice < 0 ? "H" : "");
else
snprintf(id_buf, sizeof(id_buf), "u%d:%d", pool->id, id);
worker->task = kthread_create_on_node(worker_thread, worker, pool->node,
"kworker/%s", id_buf);
if (IS_ERR(worker->task))
goto fail;
set_user_nice(worker->task, pool->attrs->nice);
worker->task->flags |= PF_NO_SETAFFINITY;
worker_attach_to_pool(worker, pool);
spin_lock_irq(&pool->lock);
worker->pool->nr_workers++;
worker_enter_idle(worker);
wake_up_process(worker->task);
spin_unlock_irq(&pool->lock);
return worker;
fail:
if (id >= 0)
ida_simple_remove(&pool->worker_ida, id);
kfree(worker);
return NULL;
}
static void destroy_worker(struct worker *worker)
{
struct worker_pool *pool = worker->pool;
lockdep_assert_held(&pool->lock);
if (WARN_ON(worker->current_work) ||
WARN_ON(!list_empty(&worker->scheduled)) ||
WARN_ON(!(worker->flags & WORKER_IDLE)))
return;
pool->nr_workers--;
pool->nr_idle--;
list_del_init(&worker->entry);
worker->flags |= WORKER_DIE;
wake_up_process(worker->task);
}
static void idle_worker_timeout(unsigned long __pool)
{
struct worker_pool *pool = (void *)__pool;
spin_lock_irq(&pool->lock);
while (too_many_workers(pool)) {
struct worker *worker;
unsigned long expires;
worker = list_entry(pool->idle_list.prev, struct worker, entry);
expires = worker->last_active + IDLE_WORKER_TIMEOUT;
if (time_before(jiffies, expires)) {
mod_timer(&pool->idle_timer, expires);
break;
}
destroy_worker(worker);
}
spin_unlock_irq(&pool->lock);
}
static void send_mayday(struct work_struct *work)
{
struct pool_workqueue *pwq = get_work_pwq(work);
struct workqueue_struct *wq = pwq->wq;
lockdep_assert_held(&wq_mayday_lock);
if (!wq->rescuer)
return;
if (list_empty(&pwq->mayday_node)) {
get_pwq(pwq);
list_add_tail(&pwq->mayday_node, &wq->maydays);
wake_up_process(wq->rescuer->task);
}
}
static void pool_mayday_timeout(unsigned long __pool)
{
struct worker_pool *pool = (void *)__pool;
struct work_struct *work;
spin_lock_irq(&pool->lock);
spin_lock(&wq_mayday_lock);
if (need_to_create_worker(pool)) {
list_for_each_entry(work, &pool->worklist, entry)
send_mayday(work);
}
spin_unlock(&wq_mayday_lock);
spin_unlock_irq(&pool->lock);
mod_timer(&pool->mayday_timer, jiffies + MAYDAY_INTERVAL);
}
static void maybe_create_worker(struct worker_pool *pool)
__releases(&pool->lock
static bool manage_workers(struct worker *worker)
{
struct worker_pool *pool = worker->pool;
if (!mutex_trylock(&pool->manager_arb))
return false;
maybe_create_worker(pool);
mutex_unlock(&pool->manager_arb);
return true;
}
static void process_one_work(struct worker *worker, struct work_struct *work)
__releases(&pool->lock
static void process_scheduled_works(struct worker *worker)
{
while (!list_empty(&worker->scheduled)) {
struct work_struct *work = list_first_entry(&worker->scheduled,
struct work_struct, entry);
process_one_work(worker, work);
}
}
static int worker_thread(void *__worker)
{
struct worker *worker = __worker;
struct worker_pool *pool = worker->pool;
worker->task->flags |= PF_WQ_WORKER;
woke_up:
spin_lock_irq(&pool->lock);
if (unlikely(worker->flags & WORKER_DIE)) {
spin_unlock_irq(&pool->lock);
WARN_ON_ONCE(!list_empty(&worker->entry));
worker->task->flags &= ~PF_WQ_WORKER;
set_task_comm(worker->task, "kworker/dying");
ida_simple_remove(&pool->worker_ida, worker->id);
worker_detach_from_pool(worker, pool);
kfree(worker);
return 0;
}
worker_leave_idle(worker);
recheck:
if (!need_more_worker(pool))
goto sleep;
if (unlikely(!may_start_working(pool)) && manage_workers(worker))
goto recheck;
WARN_ON_ONCE(!list_empty(&worker->scheduled));
worker_clr_flags(worker, WORKER_PREP | WORKER_REBOUND);
do {
struct work_struct *work =
list_first_entry(&pool->worklist,
struct work_struct, entry);
if (likely(!(*work_data_bits(work) & WORK_STRUCT_LINKED))) {
process_one_work(worker, work);
if (unlikely(!list_empty(&worker->scheduled)))
process_scheduled_works(worker);
} else {
move_linked_works(work, &worker->scheduled, NULL);
process_scheduled_works(worker);
}
} while (keep_working(pool));
worker_set_flags(worker, WORKER_PREP);
sleep:
worker_enter_idle(worker);
__set_current_state(TASK_INTERRUPTIBLE);
spin_unlock_irq(&pool->lock);
schedule();
goto woke_up;
}
static int rescuer_thread(void *__rescuer)
{
struct worker *rescuer = __rescuer;
struct workqueue_struct *wq = rescuer->rescue_wq;
struct list_head *scheduled = &rescuer->scheduled;
bool should_stop;
set_user_nice(current, RESCUER_NICE_LEVEL);
rescuer->task->flags |= PF_WQ_WORKER;
repeat:
set_current_state(TASK_INTERRUPTIBLE);
should_stop = kthread_should_stop();
spin_lock_irq(&wq_mayday_lock);
while (!list_empty(&wq->maydays)) {
struct pool_workqueue *pwq = list_first_entry(&wq->maydays,
struct pool_workqueue, mayday_node);
struct worker_pool *pool = pwq->pool;
struct work_struct *work, *n;
__set_current_state(TASK_RUNNING);
list_del_init(&pwq->mayday_node);
spin_unlock_irq(&wq_mayday_lock);
worker_attach_to_pool(rescuer, pool);
spin_lock_irq(&pool->lock);
rescuer->pool = pool;
WARN_ON_ONCE(!list_empty(scheduled));
list_for_each_entry_safe(work, n, &pool->worklist, entry)
if (get_work_pwq(work) == pwq)
move_linked_works(work, scheduled, &n);
if (!list_empty(scheduled)) {
process_scheduled_works(rescuer);
if (need_to_create_worker(pool)) {
spin_lock(&wq_mayday_lock);
get_pwq(pwq);
list_move_tail(&pwq->mayday_node, &wq->maydays);
spin_unlock(&wq_mayday_lock);
}
}
put_pwq(pwq);
if (need_more_worker(pool))
wake_up_worker(pool);
rescuer->pool = NULL;
spin_unlock_irq(&pool->lock);
worker_detach_from_pool(rescuer, pool);
spin_lock_irq(&wq_mayday_lock);
}
spin_unlock_irq(&wq_mayday_lock);
if (should_stop) {
__set_current_state(TASK_RUNNING);
rescuer->task->flags &= ~PF_WQ_WORKER;
return 0;
}
WARN_ON_ONCE(!(rescuer->flags & WORKER_NOT_RUNNING));
schedule();
goto repeat;
}
static void wq_barrier_func(struct work_struct *work)
{
struct wq_barrier *barr = container_of(work, struct wq_barrier, work);
complete(&barr->done);
}
static void insert_wq_barrier(struct pool_workqueue *pwq,
struct wq_barrier *barr,
struct work_struct *target, struct worker *worker)
{
struct list_head *head;
unsigned int linked = 0;
INIT_WORK_ONSTACK(&barr->work, wq_barrier_func);
__set_bit(WORK_STRUCT_PENDING_BIT, work_data_bits(&barr->work));
init_completion(&barr->done);
if (worker)
head = worker->scheduled.next;
else {
unsigned long *bits = work_data_bits(target);
head = target->entry.next;
linked = *bits & WORK_STRUCT_LINKED;
__set_bit(WORK_STRUCT_LINKED_BIT, bits);
}
debug_work_activate(&barr->work);
insert_work(pwq, &barr->work, head,
work_color_to_flags(WORK_NO_COLOR) | linked);
}
static bool flush_workqueue_prep_pwqs(struct workqueue_struct *wq,
int flush_color, int work_color)
{
bool wait = false;
struct pool_workqueue *pwq;
if (flush_color >= 0) {
WARN_ON_ONCE(atomic_read(&wq->nr_pwqs_to_flush));
atomic_set(&wq->nr_pwqs_to_flush, 1);
}
for_each_pwq(pwq, wq) {
struct worker_pool *pool = pwq->pool;
spin_lock_irq(&pool->lock);
if (flush_color >= 0) {
WARN_ON_ONCE(pwq->flush_color != -1);
if (pwq->nr_in_flight[flush_color]) {
pwq->flush_color = flush_color;
atomic_inc(&wq->nr_pwqs_to_flush);
wait = true;
}
}
if (work_color >= 0) {
WARN_ON_ONCE(work_color != work_next_color(pwq->work_color));
pwq->work_color = work_color;
}
spin_unlock_irq(&pool->lock);
}
if (flush_color >= 0 && atomic_dec_and_test(&wq->nr_pwqs_to_flush))
complete(&wq->first_flusher->done);
return wait;
}
void flush_workqueue(struct workqueue_struct *wq)
{
struct wq_flusher this_flusher = {
.list = LIST_HEAD_INIT(this_flusher.list),
.flush_color = -1,
.done = COMPLETION_INITIALIZER_ONSTACK(this_flusher.done),
};
int next_color;
lock_map_acquire(&wq->lockdep_map);
lock_map_release(&wq->lockdep_map);
mutex_lock(&wq->mutex);
next_color = work_next_color(wq->work_color);
if (next_color != wq->flush_color) {
WARN_ON_ONCE(!list_empty(&wq->flusher_overflow));
this_flusher.flush_color = wq->work_color;
wq->work_color = next_color;
if (!wq->first_flusher) {
WARN_ON_ONCE(wq->flush_color != this_flusher.flush_color);
wq->first_flusher = &this_flusher;
if (!flush_workqueue_prep_pwqs(wq, wq->flush_color,
wq->work_color)) {
wq->flush_color = next_color;
wq->first_flusher = NULL;
goto out_unlock;
}
} else {
WARN_ON_ONCE(wq->flush_color == this_flusher.flush_color);
list_add_tail(&this_flusher.list, &wq->flusher_queue);
flush_workqueue_prep_pwqs(wq, -1, wq->work_color);
}
} else {
list_add_tail(&this_flusher.list, &wq->flusher_overflow);
}
mutex_unlock(&wq->mutex);
wait_for_completion(&this_flusher.done);
if (wq->first_flusher != &this_flusher)
return;
mutex_lock(&wq->mutex);
if (wq->first_flusher != &this_flusher)
goto out_unlock;
wq->first_flusher = NULL;
WARN_ON_ONCE(!list_empty(&this_flusher.list));
WARN_ON_ONCE(wq->flush_color != this_flusher.flush_color);
while (true) {
struct wq_flusher *next, *tmp;
list_for_each_entry_safe(next, tmp, &wq->flusher_queue, list) {
if (next->flush_color != wq->flush_color)
break;
list_del_init(&next->list);
complete(&next->done);
}
WARN_ON_ONCE(!list_empty(&wq->flusher_overflow) &&
wq->flush_color != work_next_color(wq->work_color));
wq->flush_color = work_next_color(wq->flush_color);
if (!list_empty(&wq->flusher_overflow)) {
list_for_each_entry(tmp, &wq->flusher_overflow, list)
tmp->flush_color = wq->work_color;
wq->work_color = work_next_color(wq->work_color);
list_splice_tail_init(&wq->flusher_overflow,
&wq->flusher_queue);
flush_workqueue_prep_pwqs(wq, -1, wq->work_color);
}
if (list_empty(&wq->flusher_queue)) {
WARN_ON_ONCE(wq->flush_color != wq->work_color);
break;
}
WARN_ON_ONCE(wq->flush_color == wq->work_color);
WARN_ON_ONCE(wq->flush_color != next->flush_color);
list_del_init(&next->list);
wq->first_flusher = next;
if (flush_workqueue_prep_pwqs(wq, wq->flush_color, -1))
break;
wq->first_flusher = NULL;
}
out_unlock:
mutex_unlock(&wq->mutex);
}
void drain_workqueue(struct workqueue_struct *wq)
{
unsigned int flush_cnt = 0;
struct pool_workqueue *pwq;
mutex_lock(&wq->mutex);
if (!wq->nr_drainers++)
wq->flags |= __WQ_DRAINING;
mutex_unlock(&wq->mutex);
reflush:
flush_workqueue(wq);
mutex_lock(&wq->mutex);
for_each_pwq(pwq, wq) {
bool drained;
spin_lock_irq(&pwq->pool->lock);
drained = !pwq->nr_active && list_empty(&pwq->delayed_works);
spin_unlock_irq(&pwq->pool->lock);
if (drained)
continue;
if (++flush_cnt == 10 ||
(flush_cnt % 100 == 0 && flush_cnt <= 1000))
pr_warn("workqueue %s: drain_workqueue() isn't complete after %u tries\n",
wq->name, flush_cnt);
mutex_unlock(&wq->mutex);
goto reflush;
}
if (!--wq->nr_drainers)
wq->flags &= ~__WQ_DRAINING;
mutex_unlock(&wq->mutex);
}
static bool start_flush_work(struct work_struct *work, struct wq_barrier *barr)
{
struct worker *worker = NULL;
struct worker_pool *pool;
struct pool_workqueue *pwq;
might_sleep();
local_irq_disable();
pool = get_work_pool(work);
if (!pool) {
local_irq_enable();
return false;
}
spin_lock(&pool->lock);
pwq = get_work_pwq(work);
if (pwq) {
if (unlikely(pwq->pool != pool))
goto already_gone;
} else {
worker = find_worker_executing_work(pool, work);
if (!worker)
goto already_gone;
pwq = worker->current_pwq;
}
insert_wq_barrier(pwq, barr, work, worker);
spin_unlock_irq(&pool->lock);
if (pwq->wq->saved_max_active == 1 || pwq->wq->rescuer)
lock_map_acquire(&pwq->wq->lockdep_map);
else
lock_map_acquire_read(&pwq->wq->lockdep_map);
lock_map_release(&pwq->wq->lockdep_map);
return true;
already_gone:
spin_unlock_irq(&pool->lock);
return false;
}
bool flush_work(struct work_struct *work)
{
struct wq_barrier barr;
lock_map_acquire(&work->lockdep_map);
lock_map_release(&work->lockdep_map);
if (start_flush_work(work, &barr)) {
wait_for_completion(&barr.done);
destroy_work_on_stack(&barr.work);
return true;
} else {
return false;
}
}
static bool __cancel_work_timer(struct work_struct *work, bool is_dwork)
{
unsigned long flags;
int ret;
do {
ret = try_to_grab_pending(work, is_dwork, &flags);
if (unlikely(ret == -ENOENT))
flush_work(work);
} while (unlikely(ret < 0));
mark_work_canceling(work);
local_irq_restore(flags);
flush_work(work);
clear_work_data(work);
return ret;
}
bool cancel_work_sync(struct work_struct *work)
{
return __cancel_work_timer(work, false);
}
bool flush_delayed_work(struct delayed_work *dwork)
{
local_irq_disable();
if (del_timer_sync(&dwork->timer))
__queue_work(dwork->cpu, dwork->wq, &dwork->work);
local_irq_enable();
return flush_work(&dwork->work);
}
bool cancel_delayed_work(struct delayed_work *dwork)
{
unsigned long flags;
int ret;
do {
ret = try_to_grab_pending(&dwork->work, true, &flags);
} while (unlikely(ret == -EAGAIN));
if (unlikely(ret < 0))
return false;
set_work_pool_and_clear_pending(&dwork->work,
get_work_pool_id(&dwork->work));
local_irq_restore(flags);
return ret;
}
bool cancel_delayed_work_sync(struct delayed_work *dwork)
{
return __cancel_work_timer(&dwork->work, true);
}
int schedule_on_each_cpu(work_func_t func)
{
int cpu;
struct work_struct __percpu *works;
works = alloc_percpu(struct work_struct);
if (!works)
return -ENOMEM;
get_online_cpus();
for_each_online_cpu(cpu) {
struct work_struct *work = per_cpu_ptr(works, cpu);
INIT_WORK(work, func);
schedule_work_on(cpu, work);
}
for_each_online_cpu(cpu)
flush_work(per_cpu_ptr(works, cpu));
put_online_cpus();
free_percpu(works);
return 0;
}
void flush_scheduled_work(void)
{
flush_workqueue(system_wq);
}
int execute_in_process_context(work_func_t fn, struct execute_work *ew)
{
if (!in_interrupt()) {
fn(&ew->work);
return 0;
}
INIT_WORK(&ew->work, fn);
schedule_work(&ew->work);
return 1;
}
static struct workqueue_struct *dev_to_wq(struct device *dev)
{
struct wq_device *wq_dev = container_of(dev, struct wq_device, dev);
return wq_dev->wq;
}
static ssize_t per_cpu_show(struct device *dev, struct device_attribute *attr,
char *buf)
{
struct workqueue_struct *wq = dev_to_wq(dev);
return scnprintf(buf, PAGE_SIZE, "%d\n", (bool)!(wq->flags & WQ_UNBOUND));
}
static ssize_t max_active_show(struct device *dev,
struct device_attribute *attr, char *buf)
{
struct workqueue_struct *wq = dev_to_wq(dev);
return scnprintf(buf, PAGE_SIZE, "%d\n", wq->saved_max_active);
}
static ssize_t max_active_store(struct device *dev,
struct device_attribute *attr, const char *buf,
size_t count)
{
struct workqueue_struct *wq = dev_to_wq(dev);
int val;
if (sscanf(buf, "%d", &val) != 1 || val <= 0)
return -EINVAL;
workqueue_set_max_active(wq, val);
return count;
}
static ssize_t wq_pool_ids_show(struct device *dev,
struct device_attribute *attr, char *buf)
{
struct workqueue_struct *wq = dev_to_wq(dev);
const char *delim = "";
int node, written = 0;
rcu_read_lock_sched();
for_each_node(node) {
written += scnprintf(buf + written, PAGE_SIZE - written,
"%s%d:%d", delim, node,
unbound_pwq_by_node(wq, node)->pool->id);
delim = " ";
}
written += scnprintf(buf + written, PAGE_SIZE - written, "\n");
rcu_read_unlock_sched();
return written;
}
static ssize_t wq_nice_show(struct device *dev, struct device_attribute *attr,
char *buf)
{
struct workqueue_struct *wq = dev_to_wq(dev);
int written;
mutex_lock(&wq->mutex);
written = scnprintf(buf, PAGE_SIZE, "%d\n", wq->unbound_attrs->nice);
mutex_unlock(&wq->mutex);
return written;
}
static struct workqueue_attrs *wq_sysfs_prep_attrs(struct workqueue_struct *wq)
{
struct workqueue_attrs *attrs;
attrs = alloc_workqueue_attrs(GFP_KERNEL);
if (!attrs)
return NULL;
mutex_lock(&wq->mutex);
copy_workqueue_attrs(attrs, wq->unbound_attrs);
mutex_unlock(&wq->mutex);
return attrs;
}
static ssize_t wq_nice_store(struct device *dev, struct device_attribute *attr,
const char *buf, size_t count)
{
struct workqueue_struct *wq = dev_to_wq(dev);
struct workqueue_attrs *attrs;
int ret;
attrs = wq_sysfs_prep_attrs(wq);
if (!attrs)
return -ENOMEM;
if (sscanf(buf, "%d", &attrs->nice) == 1 &&
attrs->nice >= MIN_NICE && attrs->nice <= MAX_NICE)
ret = apply_workqueue_attrs(wq, attrs);
else
ret = -EINVAL;
free_workqueue_attrs(attrs);
return ret ?: count;
}
static ssize_t wq_cpumask_show(struct device *dev,
struct device_attribute *attr, char *buf)
{
struct workqueue_struct *wq = dev_to_wq(dev);
int written;
mutex_lock(&wq->mutex);
written = cpumask_scnprintf(buf, PAGE_SIZE, wq->unbound_attrs->cpumask);
mutex_unlock(&wq->mutex);
written += scnprintf(buf + written, PAGE_SIZE - written, "\n");
return written;
}
static ssize_t wq_cpumask_store(struct device *dev,
struct device_attribute *attr,
const char *buf, size_t count)
{
struct workqueue_struct *wq = dev_to_wq(dev);
struct workqueue_attrs *attrs;
int ret;
attrs = wq_sysfs_prep_attrs(wq);
if (!attrs)
return -ENOMEM;
ret = cpumask_parse(buf, attrs->cpumask);
if (!ret)
ret = apply_workqueue_attrs(wq, attrs);
free_workqueue_attrs(attrs);
return ret ?: count;
}
static ssize_t wq_numa_show(struct device *dev, struct device_attribute *attr,
char *buf)
{
struct workqueue_struct *wq = dev_to_wq(dev);
int written;
mutex_lock(&wq->mutex);
written = scnprintf(buf, PAGE_SIZE, "%d\n",
!wq->unbound_attrs->no_numa);
mutex_unlock(&wq->mutex);
return written;
}
static ssize_t wq_numa_store(struct device *dev, struct device_attribute *attr,
const char *buf, size_t count)
{
struct workqueue_struct *wq = dev_to_wq(dev);
struct workqueue_attrs *attrs;
int v, ret;
attrs = wq_sysfs_prep_attrs(wq);
if (!attrs)
return -ENOMEM;
ret = -EINVAL;
if (sscanf(buf, "%d", &v) == 1) {
attrs->no_numa = !v;
ret = apply_workqueue_attrs(wq, attrs);
}
free_workqueue_attrs(attrs);
return ret ?: count;
}
static int __init wq_sysfs_init(void)
{
return subsys_virtual_register(&wq_subsys, NULL);
}
static void wq_device_release(struct device *dev)
{
struct wq_device *wq_dev = container_of(dev, struct wq_device, dev);
kfree(wq_dev);
}
int workqueue_sysfs_register(struct workqueue_struct *wq)
{
struct wq_device *wq_dev;
int ret;
if (WARN_ON(wq->flags & __WQ_ORDERED))
return -EINVAL;
wq->wq_dev = wq_dev = kzalloc(sizeof(*wq_dev), GFP_KERNEL);
if (!wq_dev)
return -ENOMEM;
wq_dev->wq = wq;
wq_dev->dev.bus = &wq_subsys;
wq_dev->dev.init_name = wq->name;
wq_dev->dev.release = wq_device_release;
dev_set_uevent_suppress(&wq_dev->dev, true);
ret = device_register(&wq_dev->dev);
if (ret) {
kfree(wq_dev);
wq->wq_dev = NULL;
return ret;
}
if (wq->flags & WQ_UNBOUND) {
struct device_attribute *attr;
for (attr = wq_sysfs_unbound_attrs; attr->attr.name; attr++) {
ret = device_create_file(&wq_dev->dev, attr);
if (ret) {
device_unregister(&wq_dev->dev);
wq->wq_dev = NULL;
return ret;
}
}
}
dev_set_uevent_suppress(&wq_dev->dev, false);
kobject_uevent(&wq_dev->dev.kobj, KOBJ_ADD);
return 0;
}
static void workqueue_sysfs_unregister(struct workqueue_struct *wq)
{
struct wq_device *wq_dev = wq->wq_dev;
if (!wq->wq_dev)
return;
wq->wq_dev = NULL;
device_unregister(&wq_dev->dev);
}
static void workqueue_sysfs_unregister(struct workqueue_struct *wq) { }
void free_workqueue_attrs(struct workqueue_attrs *attrs)
{
if (attrs) {
free_cpumask_var(attrs->cpumask);
kfree(attrs);
}
}
struct workqueue_attrs *alloc_workqueue_attrs(gfp_t gfp_mask)
{
struct workqueue_attrs *attrs;
attrs = kzalloc(sizeof(*attrs), gfp_mask);
if (!attrs)
goto fail;
if (!alloc_cpumask_var(&attrs->cpumask, gfp_mask))
goto fail;
cpumask_copy(attrs->cpumask, cpu_possible_mask);
return attrs;
fail:
free_workqueue_attrs(attrs);
return NULL;
}
static void copy_workqueue_attrs(struct workqueue_attrs *to,
const struct workqueue_attrs *from)
{
to->nice = from->nice;
cpumask_copy(to->cpumask, from->cpumask);
to->no_numa = from->no_numa;
}
static u32 wqattrs_hash(const struct workqueue_attrs *attrs)
{
u32 hash = 0;
hash = jhash_1word(attrs->nice, hash);
hash = jhash(cpumask_bits(attrs->cpumask),
BITS_TO_LONGS(nr_cpumask_bits) * sizeof(long), hash);
return hash;
}
static bool wqattrs_equal(const struct workqueue_attrs *a,
const struct workqueue_attrs *b)
{
if (a->nice != b->nice)
return false;
if (!cpumask_equal(a->cpumask, b->cpumask))
return false;
return true;
}
static int init_worker_pool(struct worker_pool *pool)
{
spin_lock_init(&pool->lock);
pool->id = -1;
pool->cpu = -1;
pool->node = NUMA_NO_NODE;
pool->flags |= POOL_DISASSOCIATED;
INIT_LIST_HEAD(&pool->worklist);
INIT_LIST_HEAD(&pool->idle_list);
hash_init(pool->busy_hash);
init_timer_deferrable(&pool->idle_timer);
pool->idle_timer.function = idle_worker_timeout;
pool->idle_timer.data = (unsigned long)pool;
setup_timer(&pool->mayday_timer, pool_mayday_timeout,
(unsigned long)pool);
mutex_init(&pool->manager_arb);
mutex_init(&pool->attach_mutex);
INIT_LIST_HEAD(&pool->workers);
ida_init(&pool->worker_ida);
INIT_HLIST_NODE(&pool->hash_node);
pool->refcnt = 1;
pool->attrs = alloc_workqueue_attrs(GFP_KERNEL);
if (!pool->attrs)
return -ENOMEM;
return 0;
}
static void rcu_free_pool(struct rcu_head *rcu)
{
struct worker_pool *pool = container_of(rcu, struct worker_pool, rcu);
ida_destroy(&pool->worker_ida);
free_workqueue_attrs(pool->attrs);
kfree(pool);
}
static void put_unbound_pool(struct worker_pool *pool)
{
DECLARE_COMPLETION_ONSTACK(detach_completion);
struct worker *worker;
lockdep_assert_held(&wq_pool_mutex);
if (--pool->refcnt)
return;
if (WARN_ON(!(pool->cpu < 0)) ||
WARN_ON(!list_empty(&pool->worklist)))
return;
if (pool->id >= 0)
idr_remove(&worker_pool_idr, pool->id);
hash_del(&pool->hash_node);
mutex_lock(&pool->manager_arb);
spin_lock_irq(&pool->lock);
while ((worker = first_idle_worker(pool)))
destroy_worker(worker);
WARN_ON(pool->nr_workers || pool->nr_idle);
spin_unlock_irq(&pool->lock);
mutex_lock(&pool->attach_mutex);
if (!list_empty(&pool->workers))
pool->detach_completion = &detach_completion;
mutex_unlock(&pool->attach_mutex);
if (pool->detach_completion)
wait_for_completion(pool->detach_completion);
mutex_unlock(&pool->manager_arb);
del_timer_sync(&pool->idle_timer);
del_timer_sync(&pool->mayday_timer);
call_rcu_sched(&pool->rcu, rcu_free_pool);
}
static struct worker_pool *get_unbound_pool(const struct workqueue_attrs *attrs)
{
u32 hash = wqattrs_hash(attrs);
struct worker_pool *pool;
int node;
lockdep_assert_held(&wq_pool_mutex);
hash_for_each_possible(unbound_pool_hash, pool, hash_node, hash) {
if (wqattrs_equal(pool->attrs, attrs)) {
pool->refcnt++;
return pool;
}
}
pool = kzalloc(sizeof(*pool), GFP_KERNEL);
if (!pool || init_worker_pool(pool) < 0)
goto fail;
lockdep_set_subclass(&pool->lock, 1);
copy_workqueue_attrs(pool->attrs, attrs);
pool->attrs->no_numa = false;
if (wq_numa_enabled) {
for_each_node(node) {
if (cpumask_subset(pool->attrs->cpumask,
wq_numa_possible_cpumask[node])) {
pool->node = node;
break;
}
}
}
if (worker_pool_assign_id(pool) < 0)
goto fail;
if (!create_worker(pool))
goto fail;
hash_add(unbound_pool_hash, &pool->hash_node, hash);
return pool;
fail:
if (pool)
put_unbound_pool(pool);
return NULL;
}
static void rcu_free_pwq(struct rcu_head *rcu)
{
kmem_cache_free(pwq_cache,
container_of(rcu, struct pool_workqueue, rcu));
}
static void pwq_unbound_release_workfn(struct work_struct *work)
{
struct pool_workqueue *pwq = container_of(work, struct pool_workqueue,
unbound_release_work);
struct workqueue_struct *wq = pwq->wq;
struct worker_pool *pool = pwq->pool;
bool is_last;
if (WARN_ON_ONCE(!(wq->flags & WQ_UNBOUND)))
return;
mutex_lock(&wq->mutex);
list_del_rcu(&pwq->pwqs_node);
is_last = list_empty(&wq->pwqs);
mutex_unlock(&wq->mutex);
mutex_lock(&wq_pool_mutex);
put_unbound_pool(pool);
mutex_unlock(&wq_pool_mutex);
call_rcu_sched(&pwq->rcu, rcu_free_pwq);
if (is_last) {
free_workqueue_attrs(wq->unbound_attrs);
kfree(wq);
}
}
static void pwq_adjust_max_active(struct pool_workqueue *pwq)
{
struct workqueue_struct *wq = pwq->wq;
bool freezable = wq->flags & WQ_FREEZABLE;
lockdep_assert_held(&wq->mutex);
if (!freezable && pwq->max_active == wq->saved_max_active)
return;
spin_lock_irq(&pwq->pool->lock);
if (!freezable || !workqueue_freezing) {
pwq->max_active = wq->saved_max_active;
while (!list_empty(&pwq->delayed_works) &&
pwq->nr_active < pwq->max_active)
pwq_activate_first_delayed(pwq);
wake_up_worker(pwq->pool);
} else {
pwq->max_active = 0;
}
spin_unlock_irq(&pwq->pool->lock);
}
static void init_pwq(struct pool_workqueue *pwq, struct workqueue_struct *wq,
struct worker_pool *pool)
{
BUG_ON((unsigned long)pwq & WORK_STRUCT_FLAG_MASK);
memset(pwq, 0, sizeof(*pwq));
pwq->pool = pool;
pwq->wq = wq;
pwq->flush_color = -1;
pwq->refcnt = 1;
INIT_LIST_HEAD(&pwq->delayed_works);
INIT_LIST_HEAD(&pwq->pwqs_node);
INIT_LIST_HEAD(&pwq->mayday_node);
INIT_WORK(&pwq->unbound_release_work, pwq_unbound_release_workfn);
}
static void link_pwq(struct pool_workqueue *pwq)
{
struct workqueue_struct *wq = pwq->wq;
lockdep_assert_held(&wq->mutex);
if (!list_empty(&pwq->pwqs_node))
return;
pwq->work_color = wq->work_color;
pwq_adjust_max_active(pwq);
list_add_rcu(&pwq->pwqs_node, &wq->pwqs);
}
static struct pool_workqueue *alloc_unbound_pwq(struct workqueue_struct *wq,
const struct workqueue_attrs *attrs)
{
struct worker_pool *pool;
struct pool_workqueue *pwq;
lockdep_assert_held(&wq_pool_mutex);
pool = get_unbound_pool(attrs);
if (!pool)
return NULL;
pwq = kmem_cache_alloc_node(pwq_cache, GFP_KERNEL, pool->node);
if (!pwq) {
put_unbound_pool(pool);
return NULL;
}
init_pwq(pwq, wq, pool);
return pwq;
}
static void free_unbound_pwq(struct pool_workqueue *pwq)
{
lockdep_assert_held(&wq_pool_mutex);
if (pwq) {
put_unbound_pool(pwq->pool);
kmem_cache_free(pwq_cache, pwq);
}
}
static bool wq_calc_node_cpumask(const struct workqueue_attrs *attrs, int node,
int cpu_going_down, cpumask_t *cpumask)
{
if (!wq_numa_enabled || attrs->no_numa)
goto use_dfl;
cpumask_and(cpumask, cpumask_of_node(node), attrs->cpumask);
if (cpu_going_down >= 0)
cpumask_clear_cpu(cpu_going_down, cpumask);
if (cpumask_empty(cpumask))
goto use_dfl;
cpumask_and(cpumask, attrs->cpumask, wq_numa_possible_cpumask[node]);
return !cpumask_equal(cpumask, attrs->cpumask);
use_dfl:
cpumask_copy(cpumask, attrs->cpumask);
return false;
}
static struct pool_workqueue *numa_pwq_tbl_install(struct workqueue_struct *wq,
int node,
struct pool_workqueue *pwq)
{
struct pool_workqueue *old_pwq;
lockdep_assert_held(&wq->mutex);
link_pwq(pwq);
old_pwq = rcu_access_pointer(wq->numa_pwq_tbl[node]);
rcu_assign_pointer(wq->numa_pwq_tbl[node], pwq);
return old_pwq;
}
int apply_workqueue_attrs(struct workqueue_struct *wq,
const struct workqueue_attrs *attrs)
{
struct workqueue_attrs *new_attrs, *tmp_attrs;
struct pool_workqueue **pwq_tbl, *dfl_pwq;
int node, ret;
if (WARN_ON(!(wq->flags & WQ_UNBOUND)))
return -EINVAL;
if (WARN_ON((wq->flags & __WQ_ORDERED) && !list_empty(&wq->pwqs)))
return -EINVAL;
pwq_tbl = kzalloc(nr_node_ids * sizeof(pwq_tbl[0]), GFP_KERNEL);
new_attrs = alloc_workqueue_attrs(GFP_KERNEL);
tmp_attrs = alloc_workqueue_attrs(GFP_KERNEL);
if (!pwq_tbl || !new_attrs || !tmp_attrs)
goto enomem;
copy_workqueue_attrs(new_attrs, attrs);
cpumask_and(new_attrs->cpumask, new_attrs->cpumask, cpu_possible_mask);
copy_workqueue_attrs(tmp_attrs, new_attrs);
get_online_cpus();
mutex_lock(&wq_pool_mutex);
dfl_pwq = alloc_unbound_pwq(wq, new_attrs);
if (!dfl_pwq)
goto enomem_pwq;
for_each_node(node) {
if (wq_calc_node_cpumask(attrs, node, -1, tmp_attrs->cpumask)) {
pwq_tbl[node] = alloc_unbound_pwq(wq, tmp_attrs);
if (!pwq_tbl[node])
goto enomem_pwq;
} else {
dfl_pwq->refcnt++;
pwq_tbl[node] = dfl_pwq;
}
}
mutex_unlock(&wq_pool_mutex);
mutex_lock(&wq->mutex);
copy_workqueue_attrs(wq->unbound_attrs, new_attrs);
for_each_node(node)
pwq_tbl[node] = numa_pwq_tbl_install(wq, node, pwq_tbl[node]);
link_pwq(dfl_pwq);
swap(wq->dfl_pwq, dfl_pwq);
mutex_unlock(&wq->mutex);
for_each_node(node)
put_pwq_unlocked(pwq_tbl[node]);
put_pwq_unlocked(dfl_pwq);
put_online_cpus();
ret = 0;
out_free:
free_workqueue_attrs(tmp_attrs);
free_workqueue_attrs(new_attrs);
kfree(pwq_tbl);
return ret;
enomem_pwq:
free_unbound_pwq(dfl_pwq);
for_each_node(node)
if (pwq_tbl && pwq_tbl[node] != dfl_pwq)
free_unbound_pwq(pwq_tbl[node]);
mutex_unlock(&wq_pool_mutex);
put_online_cpus();
enomem:
ret = -ENOMEM;
goto out_free;
}
static void wq_update_unbound_numa(struct workqueue_struct *wq, int cpu,
bool online)
{
int node = cpu_to_node(cpu);
int cpu_off = online ? -1 : cpu;
struct pool_workqueue *old_pwq = NULL, *pwq;
struct workqueue_attrs *target_attrs;
cpumask_t *cpumask;
lockdep_assert_held(&wq_pool_mutex);
if (!wq_numa_enabled || !(wq->flags & WQ_UNBOUND))
return;
target_attrs = wq_update_unbound_numa_attrs_buf;
cpumask = target_attrs->cpumask;
mutex_lock(&wq->mutex);
if (wq->unbound_attrs->no_numa)
goto out_unlock;
copy_workqueue_attrs(target_attrs, wq->unbound_attrs);
pwq = unbound_pwq_by_node(wq, node);
if (wq_calc_node_cpumask(wq->unbound_attrs, node, cpu_off, cpumask)) {
if (cpumask_equal(cpumask, pwq->pool->attrs->cpumask))
goto out_unlock;
} else {
goto use_dfl_pwq;
}
mutex_unlock(&wq->mutex);
pwq = alloc_unbound_pwq(wq, target_attrs);
if (!pwq) {
pr_warn("workqueue: allocation failed while updating NUMA affinity of \"%s\"\n",
wq->name);
mutex_lock(&wq->mutex);
goto use_dfl_pwq;
}
mutex_lock(&wq->mutex);
old_pwq = numa_pwq_tbl_install(wq, node, pwq);
goto out_unlock;
use_dfl_pwq:
spin_lock_irq(&wq->dfl_pwq->pool->lock);
get_pwq(wq->dfl_pwq);
spin_unlock_irq(&wq->dfl_pwq->pool->lock);
old_pwq = numa_pwq_tbl_install(wq, node, wq->dfl_pwq);
out_unlock:
mutex_unlock(&wq->mutex);
put_pwq_unlocked(old_pwq);
}
static int alloc_and_link_pwqs(struct workqueue_struct *wq)
{
bool highpri = wq->flags & WQ_HIGHPRI;
int cpu, ret;
if (!(wq->flags & WQ_UNBOUND)) {
wq->cpu_pwqs = alloc_percpu(struct pool_workqueue);
if (!wq->cpu_pwqs)
return -ENOMEM;
for_each_possible_cpu(cpu) {
struct pool_workqueue *pwq =
per_cpu_ptr(wq->cpu_pwqs, cpu);
struct worker_pool *cpu_pools =
per_cpu(cpu_worker_pools, cpu);
init_pwq(pwq, wq, &cpu_pools[highpri]);
mutex_lock(&wq->mutex);
link_pwq(pwq);
mutex_unlock(&wq->mutex);
}
return 0;
} else if (wq->flags & __WQ_ORDERED) {
ret = apply_workqueue_attrs(wq, ordered_wq_attrs[highpri]);
WARN(!ret && (wq->pwqs.next != &wq->dfl_pwq->pwqs_node ||
wq->pwqs.prev != &wq->dfl_pwq->pwqs_node),
"ordering guarantee broken for workqueue %s\n", wq->name);
return ret;
} else {
return apply_workqueue_attrs(wq, unbound_std_wq_attrs[highpri]);
}
}
static int wq_clamp_max_active(int max_active, unsigned int flags,
const char *name)
{
int lim = flags & WQ_UNBOUND ? WQ_UNBOUND_MAX_ACTIVE : WQ_MAX_ACTIVE;
if (max_active < 1 || max_active > lim)
pr_warn("workqueue: max_active %d requested for %s is out of range, clamping between %d and %d\n",
max_active, name, 1, lim);
return clamp_val(max_active, 1, lim);
}
struct workqueue_struct *__alloc_workqueue_key(const char *fmt,
unsigned int flags,
int max_active,
struct lock_class_key *key,
const char *lock_name, ...)
{
size_t tbl_size = 0;
va_list args;
struct workqueue_struct *wq;
struct pool_workqueue *pwq;
if ((flags & WQ_POWER_EFFICIENT) && wq_power_efficient)
flags |= WQ_UNBOUND;
if (flags & WQ_UNBOUND)
tbl_size = nr_node_ids * sizeof(wq->numa_pwq_tbl[0]);
wq = kzalloc(sizeof(*wq) + tbl_size, GFP_KERNEL);
if (!wq)
return NULL;
if (flags & WQ_UNBOUND) {
wq->unbound_attrs = alloc_workqueue_attrs(GFP_KERNEL);
if (!wq->unbound_attrs)
goto err_free_wq;
}
va_start(args, lock_name);
vsnprintf(wq->name, sizeof(wq->name), fmt, args);
va_end(args);
max_active = max_active ?: WQ_DFL_ACTIVE;
max_active = wq_clamp_max_active(max_active, flags, wq->name);
wq->flags = flags;
wq->saved_max_active = max_active;
mutex_init(&wq->mutex);
atomic_set(&wq->nr_pwqs_to_flush, 0);
INIT_LIST_HEAD(&wq->pwqs);
INIT_LIST_HEAD(&wq->flusher_queue);
INIT_LIST_HEAD(&wq->flusher_overflow);
INIT_LIST_HEAD(&wq->maydays);
lockdep_init_map(&wq->lockdep_map, lock_name, key, 0);
INIT_LIST_HEAD(&wq->list);
if (alloc_and_link_pwqs(wq) < 0)
goto err_free_wq;
if (flags & WQ_MEM_RECLAIM) {
struct worker *rescuer;
rescuer = alloc_worker(NUMA_NO_NODE);
if (!rescuer)
goto err_destroy;
rescuer->rescue_wq = wq;
rescuer->task = kthread_create(rescuer_thread, rescuer, "%s",
wq->name);
if (IS_ERR(rescuer->task)) {
kfree(rescuer);
goto err_destroy;
}
wq->rescuer = rescuer;
rescuer->task->flags |= PF_NO_SETAFFINITY;
wake_up_process(rescuer->task);
}
if ((wq->flags & WQ_SYSFS) && workqueue_sysfs_register(wq))
goto err_destroy;
mutex_lock(&wq_pool_mutex);
mutex_lock(&wq->mutex);
for_each_pwq(pwq, wq)
pwq_adjust_max_active(pwq);
mutex_unlock(&wq->mutex);
list_add(&wq->list, &workqueues);
mutex_unlock(&wq_pool_mutex);
return wq;
err_free_wq:
free_workqueue_attrs(wq->unbound_attrs);
kfree(wq);
return NULL;
err_destroy:
destroy_workqueue(wq);
return NULL;
}
void destroy_workqueue(struct workqueue_struct *wq)
{
struct pool_workqueue *pwq;
int node;
drain_workqueue(wq);
mutex_lock(&wq->mutex);
for_each_pwq(pwq, wq) {
int i;
for (i = 0; i < WORK_NR_COLORS; i++) {
if (WARN_ON(pwq->nr_in_flight[i])) {
mutex_unlock(&wq->mutex);
return;
}
}
if (WARN_ON((pwq != wq->dfl_pwq) && (pwq->refcnt > 1)) ||
WARN_ON(pwq->nr_active) ||
WARN_ON(!list_empty(&pwq->delayed_works))) {
mutex_unlock(&wq->mutex);
return;
}
}
mutex_unlock(&wq->mutex);
mutex_lock(&wq_pool_mutex);
list_del_init(&wq->list);
mutex_unlock(&wq_pool_mutex);
workqueue_sysfs_unregister(wq);
if (wq->rescuer) {
kthread_stop(wq->rescuer->task);
kfree(wq->rescuer);
wq->rescuer = NULL;
}
if (!(wq->flags & WQ_UNBOUND)) {
free_percpu(wq->cpu_pwqs);
kfree(wq);
} else {
for_each_node(node) {
pwq = rcu_access_pointer(wq->numa_pwq_tbl[node]);
RCU_INIT_POINTER(wq->numa_pwq_tbl[node], NULL);
put_pwq_unlocked(pwq);
}
pwq = wq->dfl_pwq;
wq->dfl_pwq = NULL;
put_pwq_unlocked(pwq);
}
}
void workqueue_set_max_active(struct workqueue_struct *wq, int max_active)
{
struct pool_workqueue *pwq;
if (WARN_ON(wq->flags & __WQ_ORDERED))
return;
max_active = wq_clamp_max_active(max_active, wq->flags, wq->name);
mutex_lock(&wq->mutex);
wq->saved_max_active = max_active;
for_each_pwq(pwq, wq)
pwq_adjust_max_active(pwq);
mutex_unlock(&wq->mutex);
}
bool current_is_workqueue_rescuer(void)
{
struct worker *worker = current_wq_worker();
return worker && worker->rescue_wq;
}
bool workqueue_congested(int cpu, struct workqueue_struct *wq)
{
struct pool_workqueue *pwq;
bool ret;
rcu_read_lock_sched();
if (cpu == WORK_CPU_UNBOUND)
cpu = smp_processor_id();
if (!(wq->flags & WQ_UNBOUND))
pwq = per_cpu_ptr(wq->cpu_pwqs, cpu);
else
pwq = unbound_pwq_by_node(wq, cpu_to_node(cpu));
ret = !list_empty(&pwq->delayed_works);
rcu_read_unlock_sched();
return ret;
}
unsigned int work_busy(struct work_struct *work)
{
struct worker_pool *pool;
unsigned long flags;
unsigned int ret = 0;
if (work_pending(work))
ret |= WORK_BUSY_PENDING;
local_irq_save(flags);
pool = get_work_pool(work);
if (pool) {
spin_lock(&pool->lock);
if (find_worker_executing_work(pool, work))
ret |= WORK_BUSY_RUNNING;
spin_unlock(&pool->lock);
}
local_irq_restore(flags);
return ret;
}
void set_worker_desc(const char *fmt, ...)
{
struct worker *worker = current_wq_worker();
va_list args;
if (worker) {
va_start(args, fmt);
vsnprintf(worker->desc, sizeof(worker->desc), fmt, args);
va_end(args);
worker->desc_valid = true;
}
}
void print_worker_info(const char *log_lvl, struct task_struct *task)
{
work_func_t *fn = NULL;
char name[WQ_NAME_LEN] = { };
char desc[WORKER_DESC_LEN] = { };
struct pool_workqueue *pwq = NULL;
struct workqueue_struct *wq = NULL;
bool desc_valid = false;
struct worker *worker;
if (!(task->flags & PF_WQ_WORKER))
return;
worker = probe_kthread_data(task);
probe_kernel_read(&fn, &worker->current_func, sizeof(fn));
probe_kernel_read(&pwq, &worker->current_pwq, sizeof(pwq));
probe_kernel_read(&wq, &pwq->wq, sizeof(wq));
probe_kernel_read(name, wq->name, sizeof(name) - 1);
probe_kernel_read(&desc_valid, &worker->desc_valid, sizeof(desc_valid));
if (desc_valid)
probe_kernel_read(desc, worker->desc, sizeof(desc) - 1);
if (fn || name[0] || desc[0]) {
printk("%sWorkqueue: %s %pf", log_lvl, name, fn);
if (desc[0])
pr_cont(" (%s)", desc);
pr_cont("\n");
}
}
static void wq_unbind_fn(struct work_struct *work)
{
int cpu = smp_processor_id();
struct worker_pool *pool;
struct worker *worker;
for_each_cpu_worker_pool(pool, cpu) {
mutex_lock(&pool->attach_mutex);
spin_lock_irq(&pool->lock);
for_each_pool_worker(worker, pool)
worker->flags |= WORKER_UNBOUND;
pool->flags |= POOL_DISASSOCIATED;
spin_unlock_irq(&pool->lock);
mutex_unlock(&pool->attach_mutex);
schedule();
atomic_set(&pool->nr_running, 0);
spin_lock_irq(&pool->lock);
wake_up_worker(pool);
spin_unlock_irq(&pool->lock);
}
}
static void rebind_workers(struct worker_pool *pool)
{
struct worker *worker;
lockdep_assert_held(&pool->attach_mutex);
for_each_pool_worker(worker, pool)
WARN_ON_ONCE(set_cpus_allowed_ptr(worker->task,
pool->attrs->cpumask) < 0);
spin_lock_irq(&pool->lock);
pool->flags &= ~POOL_DISASSOCIATED;
for_each_pool_worker(worker, pool) {
unsigned int worker_flags = worker->flags;
if (worker_flags & WORKER_IDLE)
wake_up_process(worker->task);
WARN_ON_ONCE(!(worker_flags & WORKER_UNBOUND));
worker_flags |= WORKER_REBOUND;
worker_flags &= ~WORKER_UNBOUND;
ACCESS_ONCE(worker->flags) = worker_flags;
}
spin_unlock_irq(&pool->lock);
}
static void restore_unbound_workers_cpumask(struct worker_pool *pool, int cpu)
{
static cpumask_t cpumask;
struct worker *worker;
lockdep_assert_held(&pool->attach_mutex);
if (!cpumask_test_cpu(cpu, pool->attrs->cpumask))
return;
cpumask_and(&cpumask, pool->attrs->cpumask, cpu_online_mask);
if (cpumask_weight(&cpumask) != 1)
return;
for_each_pool_worker(worker, pool)
WARN_ON_ONCE(set_cpus_allowed_ptr(worker->task,
pool->attrs->cpumask) < 0);
}
static int workqueue_cpu_up_callback(struct notifier_block *nfb,
unsigned long action,
void *hcpu)
{
int cpu = (unsigned long)hcpu;
struct worker_pool *pool;
struct workqueue_struct *wq;
int pi;
switch (action & ~CPU_TASKS_FROZEN) {
case CPU_UP_PREPARE:
for_each_cpu_worker_pool(pool, cpu) {
if (pool->nr_workers)
continue;
if (!create_worker(pool))
return NOTIFY_BAD;
}
break;
case CPU_DOWN_FAILED:
case CPU_ONLINE:
mutex_lock(&wq_pool_mutex);
for_each_pool(pool, pi) {
mutex_lock(&pool->attach_mutex);
if (pool->cpu == cpu)
rebind_workers(pool);
else if (pool->cpu < 0)
restore_unbound_workers_cpumask(pool, cpu);
mutex_unlock(&pool->attach_mutex);
}
list_for_each_entry(wq, &workqueues, list)
wq_update_unbound_numa(wq, cpu, true);
mutex_unlock(&wq_pool_mutex);
break;
}
return NOTIFY_OK;
}
static int workqueue_cpu_down_callback(struct notifier_block *nfb,
unsigned long action,
void *hcpu)
{
int cpu = (unsigned long)hcpu;
struct work_struct unbind_work;
struct workqueue_struct *wq;
switch (action & ~CPU_TASKS_FROZEN) {
case CPU_DOWN_PREPARE:
INIT_WORK_ONSTACK(&unbind_work, wq_unbind_fn);
queue_work_on(cpu, system_highpri_wq, &unbind_work);
mutex_lock(&wq_pool_mutex);
list_for_each_entry(wq, &workqueues, list)
wq_update_unbound_numa(wq, cpu, false);
mutex_unlock(&wq_pool_mutex);
flush_work(&unbind_work);
destroy_work_on_stack(&unbind_work);
break;
}
return NOTIFY_OK;
}
static void work_for_cpu_fn(struct work_struct *work)
{
struct work_for_cpu *wfc = container_of(work, struct work_for_cpu, work);
wfc->ret = wfc->fn(wfc->arg);
}
long work_on_cpu(int cpu, long (*fn)(void *), void *arg)
{
struct work_for_cpu wfc = { .fn = fn, .arg = arg };
INIT_WORK_ONSTACK(&wfc.work, work_for_cpu_fn);
schedule_work_on(cpu, &wfc.work);
flush_work(&wfc.work);
destroy_work_on_stack(&wfc.work);
return wfc.ret;
}
void freeze_workqueues_begin(void)
{
struct workqueue_struct *wq;
struct pool_workqueue *pwq;
mutex_lock(&wq_pool_mutex);
WARN_ON_ONCE(workqueue_freezing);
workqueue_freezing = true;
list_for_each_entry(wq, &workqueues, list) {
mutex_lock(&wq->mutex);
for_each_pwq(pwq, wq)
pwq_adjust_max_active(pwq);
mutex_unlock(&wq->mutex);
}
mutex_unlock(&wq_pool_mutex);
}
bool freeze_workqueues_busy(void)
{
bool busy = false;
struct workqueue_struct *wq;
struct pool_workqueue *pwq;
mutex_lock(&wq_pool_mutex);
WARN_ON_ONCE(!workqueue_freezing);
list_for_each_entry(wq, &workqueues, list) {
if (!(wq->flags & WQ_FREEZABLE))
continue;
rcu_read_lock_sched();
for_each_pwq(pwq, wq) {
WARN_ON_ONCE(pwq->nr_active < 0);
if (pwq->nr_active) {
busy = true;
rcu_read_unlock_sched();
goto out_unlock;
}
}
rcu_read_unlock_sched();
}
out_unlock:
mutex_unlock(&wq_pool_mutex);
return busy;
}
void thaw_workqueues(void)
{
struct workqueue_struct *wq;
struct pool_workqueue *pwq;
mutex_lock(&wq_pool_mutex);
if (!workqueue_freezing)
goto out_unlock;
workqueue_freezing = false;
list_for_each_entry(wq, &workqueues, list) {
mutex_lock(&wq->mutex);
for_each_pwq(pwq, wq)
pwq_adjust_max_active(pwq);
mutex_unlock(&wq->mutex);
}
out_unlock:
mutex_unlock(&wq_pool_mutex);
}
static void __init wq_numa_init(void)
{
cpumask_var_t *tbl;
int node, cpu;
if (num_possible_nodes() <= 1)
return;
if (wq_disable_numa) {
pr_info("workqueue: NUMA affinity support disabled\n");
return;
}
wq_update_unbound_numa_attrs_buf = alloc_workqueue_attrs(GFP_KERNEL);
BUG_ON(!wq_update_unbound_numa_attrs_buf);
tbl = kzalloc(nr_node_ids * sizeof(tbl[0]), GFP_KERNEL);
BUG_ON(!tbl);
for_each_node(node)
BUG_ON(!zalloc_cpumask_var_node(&tbl[node], GFP_KERNEL,
node_online(node) ? node : NUMA_NO_NODE));
for_each_possible_cpu(cpu) {
node = cpu_to_node(cpu);
if (WARN_ON(node == NUMA_NO_NODE)) {
pr_warn("workqueue: NUMA node mapping not available for cpu%d, disabling NUMA support\n", cpu);
return;
}
cpumask_set_cpu(cpu, tbl[node]);
}
wq_numa_possible_cpumask = tbl;
wq_numa_enabled = true;
}
static int __init init_workqueues(void)
{
int std_nice[NR_STD_WORKER_POOLS] = { 0, HIGHPRI_NICE_LEVEL };
int i, cpu;
WARN_ON(__alignof__(struct pool_workqueue) < __alignof__(long long));
pwq_cache = KMEM_CACHE(pool_workqueue, SLAB_PANIC);
cpu_notifier(workqueue_cpu_up_callback, CPU_PRI_WORKQUEUE_UP);
hotcpu_notifier(workqueue_cpu_down_callback, CPU_PRI_WORKQUEUE_DOWN);
wq_numa_init();
for_each_possible_cpu(cpu) {
struct worker_pool *pool;
i = 0;
for_each_cpu_worker_pool(pool, cpu) {
BUG_ON(init_worker_pool(pool));
pool->cpu = cpu;
cpumask_copy(pool->attrs->cpumask, cpumask_of(cpu));
pool->attrs->nice = std_nice[i++];
pool->node = cpu_to_node(cpu);
mutex_lock(&wq_pool_mutex);
BUG_ON(worker_pool_assign_id(pool));
mutex_unlock(&wq_pool_mutex);
}
}
for_each_online_cpu(cpu) {
struct worker_pool *pool;
for_each_cpu_worker_pool(pool, cpu) {
pool->flags &= ~POOL_DISASSOCIATED;
BUG_ON(!create_worker(pool));
}
}
for (i = 0; i < NR_STD_WORKER_POOLS; i++) {
struct workqueue_attrs *attrs;
BUG_ON(!(attrs = alloc_workqueue_attrs(GFP_KERNEL)));
attrs->nice = std_nice[i];
unbound_std_wq_attrs[i] = attrs;
BUG_ON(!(attrs = alloc_workqueue_attrs(GFP_KERNEL)));
attrs->nice = std_nice[i];
attrs->no_numa = true;
ordered_wq_attrs[i] = attrs;
}
system_wq = alloc_workqueue("events", 0, 0);
system_highpri_wq = alloc_workqueue("events_highpri", WQ_HIGHPRI, 0);
system_long_wq = alloc_workqueue("events_long", 0, 0);
system_unbound_wq = alloc_workqueue("events_unbound", WQ_UNBOUND,
WQ_UNBOUND_MAX_ACTIVE);
system_freezable_wq = alloc_workqueue("events_freezable",
WQ_FREEZABLE, 0);
system_power_efficient_wq = alloc_workqueue("events_power_efficient",
WQ_POWER_EFFICIENT, 0);
system_freezable_power_efficient_wq = alloc_workqueue("events_freezable_power_efficient",
WQ_FREEZABLE | WQ_POWER_EFFICIENT,
0);
BUG_ON(!system_wq || !system_highpri_wq || !system_long_wq ||
!system_unbound_wq || !system_freezable_wq ||
!system_power_efficient_wq ||
!system_freezable_power_efficient_wq);
return 0;
}
