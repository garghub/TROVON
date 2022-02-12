static inline int __next_wq_cpu(int cpu, const struct cpumask *mask,
unsigned int sw)
{
if (cpu < nr_cpu_ids) {
if (sw & 1) {
cpu = cpumask_next(cpu, mask);
if (cpu < nr_cpu_ids)
return cpu;
}
if (sw & 2)
return WORK_CPU_UNBOUND;
}
return WORK_CPU_END;
}
static inline int __next_pwq_cpu(int cpu, const struct cpumask *mask,
struct workqueue_struct *wq)
{
return __next_wq_cpu(cpu, mask, !(wq->flags & WQ_UNBOUND) ? 1 : 2);
}
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
static inline void debug_work_activate(struct work_struct *work) { }
static inline void debug_work_deactivate(struct work_struct *work) { }
static struct worker_pool *std_worker_pools(int cpu)
{
if (cpu != WORK_CPU_UNBOUND)
return per_cpu(cpu_std_worker_pools, cpu);
else
return unbound_std_worker_pools;
}
static int std_worker_pool_pri(struct worker_pool *pool)
{
return pool - std_worker_pools(pool->cpu);
}
static int worker_pool_assign_id(struct worker_pool *pool)
{
int ret;
mutex_lock(&worker_pool_idr_mutex);
ret = idr_alloc(&worker_pool_idr, pool, 0, 0, GFP_KERNEL);
if (ret >= 0)
pool->id = ret;
mutex_unlock(&worker_pool_idr_mutex);
return ret < 0 ? ret : 0;
}
static struct worker_pool *worker_pool_by_id(int pool_id)
{
return idr_find(&worker_pool_idr, pool_id);
}
static struct worker_pool *get_std_worker_pool(int cpu, bool highpri)
{
struct worker_pool *pools = std_worker_pools(cpu);
return &pools[highpri];
}
static struct pool_workqueue *get_pwq(unsigned int cpu,
struct workqueue_struct *wq)
{
if (!(wq->flags & WQ_UNBOUND)) {
if (likely(cpu < nr_cpu_ids))
return per_cpu_ptr(wq->pool_wq.pcpu, cpu);
} else if (likely(cpu == WORK_CPU_UNBOUND))
return wq->pool_wq.single;
return NULL;
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
BUG_ON(!work_pending(work));
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
struct worker_pool *pool;
int pool_id;
if (data & WORK_STRUCT_PWQ)
return ((struct pool_workqueue *)
(data & WORK_STRUCT_WQ_DATA_MASK))->pool;
pool_id = data >> WORK_OFFQ_POOL_SHIFT;
if (pool_id == WORK_OFFQ_POOL_NONE)
return NULL;
pool = worker_pool_by_id(pool_id);
WARN_ON_ONCE(!pool);
return pool;
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
static bool need_to_manage_workers(struct worker_pool *pool)
{
return need_to_create_worker(pool) ||
(pool->flags & POOL_MANAGE_WORKERS);
}
static bool too_many_workers(struct worker_pool *pool)
{
bool managing = pool->flags & POOL_MANAGING_WORKERS;
int nr_idle = pool->nr_idle + managing;
int nr_busy = pool->nr_workers - nr_idle;
if (list_empty(&pool->idle_list))
return false;
return nr_idle > 2 && (nr_idle - 2) * MAX_IDLE_WORKERS_RATIO >= nr_busy;
}
static struct worker *first_worker(struct worker_pool *pool)
{
if (unlikely(list_empty(&pool->idle_list)))
return NULL;
return list_first_entry(&pool->idle_list, struct worker, entry);
}
static void wake_up_worker(struct worker_pool *pool)
{
struct worker *worker = first_worker(pool);
if (likely(worker))
wake_up_process(worker->task);
}
void wq_worker_waking_up(struct task_struct *task, unsigned int cpu)
{
struct worker *worker = kthread_data(task);
if (!(worker->flags & WORKER_NOT_RUNNING)) {
WARN_ON_ONCE(worker->pool->cpu != cpu);
atomic_inc(&worker->pool->nr_running);
}
}
struct task_struct *wq_worker_sleeping(struct task_struct *task,
unsigned int cpu)
{
struct worker *worker = kthread_data(task), *to_wakeup = NULL;
struct worker_pool *pool;
if (worker->flags & WORKER_NOT_RUNNING)
return NULL;
pool = worker->pool;
BUG_ON(cpu != raw_smp_processor_id());
if (atomic_dec_and_test(&pool->nr_running) &&
!list_empty(&pool->worklist))
to_wakeup = first_worker(pool);
return to_wakeup ? to_wakeup->task : NULL;
}
static inline void worker_set_flags(struct worker *worker, unsigned int flags,
bool wakeup)
{
struct worker_pool *pool = worker->pool;
WARN_ON_ONCE(worker->task != current);
if ((flags & WORKER_NOT_RUNNING) &&
!(worker->flags & WORKER_NOT_RUNNING)) {
if (wakeup) {
if (atomic_dec_and_test(&pool->nr_running) &&
!list_empty(&pool->worklist))
wake_up_worker(pool);
} else
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
return;
pwq->nr_in_flight[color]--;
pwq->nr_active--;
if (!list_empty(&pwq->delayed_works)) {
if (pwq->nr_active < pwq->max_active)
pwq_activate_first_delayed(pwq);
}
if (likely(pwq->flush_color != color))
return;
if (pwq->nr_in_flight[color])
return;
pwq->flush_color = -1;
if (atomic_dec_and_test(&pwq->wq->nr_pwqs_to_flush))
complete(&pwq->wq->first_flusher->done);
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
pwq_dec_nr_in_flight(get_work_pwq(work), get_work_color(work));
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
static void __queue_work(unsigned int cpu, struct workqueue_struct *wq,
struct work_struct *work)
{
struct pool_workqueue *pwq;
struct list_head *worklist;
unsigned int work_flags;
unsigned int req_cpu = cpu;
WARN_ON_ONCE(!irqs_disabled());
debug_work_activate(work);
if (unlikely(wq->flags & WQ_DRAINING) &&
WARN_ON_ONCE(!is_chained_work(wq)))
return;
if (!(wq->flags & WQ_UNBOUND)) {
struct worker_pool *last_pool;
if (cpu == WORK_CPU_UNBOUND)
cpu = raw_smp_processor_id();
pwq = get_pwq(cpu, wq);
last_pool = get_work_pool(work);
if (last_pool && last_pool != pwq->pool) {
struct worker *worker;
spin_lock(&last_pool->lock);
worker = find_worker_executing_work(last_pool, work);
if (worker && worker->current_pwq->wq == wq) {
pwq = get_pwq(last_pool->cpu, wq);
} else {
spin_unlock(&last_pool->lock);
spin_lock(&pwq->pool->lock);
}
} else {
spin_lock(&pwq->pool->lock);
}
} else {
pwq = get_pwq(WORK_CPU_UNBOUND, wq);
spin_lock(&pwq->pool->lock);
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
bool queue_work(struct workqueue_struct *wq, struct work_struct *work)
{
return queue_work_on(WORK_CPU_UNBOUND, wq, work);
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
bool queue_delayed_work(struct workqueue_struct *wq,
struct delayed_work *dwork, unsigned long delay)
{
return queue_delayed_work_on(WORK_CPU_UNBOUND, wq, dwork, delay);
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
bool mod_delayed_work(struct workqueue_struct *wq, struct delayed_work *dwork,
unsigned long delay)
{
return mod_delayed_work_on(WORK_CPU_UNBOUND, wq, dwork, delay);
}
static void worker_enter_idle(struct worker *worker)
{
struct worker_pool *pool = worker->pool;
BUG_ON(worker->flags & WORKER_IDLE);
BUG_ON(!list_empty(&worker->entry) &&
(worker->hentry.next || worker->hentry.pprev));
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
BUG_ON(!(worker->flags & WORKER_IDLE));
worker_clr_flags(worker, WORKER_IDLE);
pool->nr_idle--;
list_del_init(&worker->entry);
}
static bool worker_maybe_bind_and_lock(struct worker *worker)
__acquires(&pool->lock
static void idle_worker_rebind(struct worker *worker)
{
if (worker_maybe_bind_and_lock(worker))
worker_clr_flags(worker, WORKER_UNBOUND);
list_add(&worker->entry, &worker->pool->idle_list);
spin_unlock_irq(&worker->pool->lock);
}
static void busy_worker_rebind_fn(struct work_struct *work)
{
struct worker *worker = container_of(work, struct worker, rebind_work);
if (worker_maybe_bind_and_lock(worker))
worker_clr_flags(worker, WORKER_UNBOUND);
spin_unlock_irq(&worker->pool->lock);
}
static void rebind_workers(struct worker_pool *pool)
{
struct worker *worker, *n;
int i;
lockdep_assert_held(&pool->assoc_mutex);
lockdep_assert_held(&pool->lock);
list_for_each_entry_safe(worker, n, &pool->idle_list, entry) {
list_del_init(&worker->entry);
wake_up_process(worker->task);
}
for_each_busy_worker(worker, i, pool) {
struct work_struct *rebind_work = &worker->rebind_work;
struct workqueue_struct *wq;
if (test_and_set_bit(WORK_STRUCT_PENDING_BIT,
work_data_bits(rebind_work)))
continue;
debug_work_activate(rebind_work);
if (std_worker_pool_pri(worker->pool))
wq = system_highpri_wq;
else
wq = system_wq;
insert_work(get_pwq(pool->cpu, wq), rebind_work,
worker->scheduled.next,
work_color_to_flags(WORK_NO_COLOR));
}
}
static struct worker *alloc_worker(void)
{
struct worker *worker;
worker = kzalloc(sizeof(*worker), GFP_KERNEL);
if (worker) {
INIT_LIST_HEAD(&worker->entry);
INIT_LIST_HEAD(&worker->scheduled);
INIT_WORK(&worker->rebind_work, busy_worker_rebind_fn);
worker->flags = WORKER_PREP;
}
return worker;
}
static struct worker *create_worker(struct worker_pool *pool)
{
const char *pri = std_worker_pool_pri(pool) ? "H" : "";
struct worker *worker = NULL;
int id = -1;
spin_lock_irq(&pool->lock);
while (ida_get_new(&pool->worker_ida, &id)) {
spin_unlock_irq(&pool->lock);
if (!ida_pre_get(&pool->worker_ida, GFP_KERNEL))
goto fail;
spin_lock_irq(&pool->lock);
}
spin_unlock_irq(&pool->lock);
worker = alloc_worker();
if (!worker)
goto fail;
worker->pool = pool;
worker->id = id;
if (pool->cpu != WORK_CPU_UNBOUND)
worker->task = kthread_create_on_node(worker_thread,
worker, cpu_to_node(pool->cpu),
"kworker/%u:%d%s", pool->cpu, id, pri);
else
worker->task = kthread_create(worker_thread, worker,
"kworker/u:%d%s", id, pri);
if (IS_ERR(worker->task))
goto fail;
if (std_worker_pool_pri(pool))
set_user_nice(worker->task, HIGHPRI_NICE_LEVEL);
if (!(pool->flags & POOL_DISASSOCIATED)) {
kthread_bind(worker->task, pool->cpu);
} else {
worker->task->flags |= PF_THREAD_BOUND;
worker->flags |= WORKER_UNBOUND;
}
return worker;
fail:
if (id >= 0) {
spin_lock_irq(&pool->lock);
ida_remove(&pool->worker_ida, id);
spin_unlock_irq(&pool->lock);
}
kfree(worker);
return NULL;
}
static void start_worker(struct worker *worker)
{
worker->flags |= WORKER_STARTED;
worker->pool->nr_workers++;
worker_enter_idle(worker);
wake_up_process(worker->task);
}
static void destroy_worker(struct worker *worker)
{
struct worker_pool *pool = worker->pool;
int id = worker->id;
BUG_ON(worker->current_work);
BUG_ON(!list_empty(&worker->scheduled));
if (worker->flags & WORKER_STARTED)
pool->nr_workers--;
if (worker->flags & WORKER_IDLE)
pool->nr_idle--;
list_del_init(&worker->entry);
worker->flags |= WORKER_DIE;
spin_unlock_irq(&pool->lock);
kthread_stop(worker->task);
kfree(worker);
spin_lock_irq(&pool->lock);
ida_remove(&pool->worker_ida, id);
}
static void idle_worker_timeout(unsigned long __pool)
{
struct worker_pool *pool = (void *)__pool;
spin_lock_irq(&pool->lock);
if (too_many_workers(pool)) {
struct worker *worker;
unsigned long expires;
worker = list_entry(pool->idle_list.prev, struct worker, entry);
expires = worker->last_active + IDLE_WORKER_TIMEOUT;
if (time_before(jiffies, expires))
mod_timer(&pool->idle_timer, expires);
else {
pool->flags |= POOL_MANAGE_WORKERS;
wake_up_worker(pool);
}
}
spin_unlock_irq(&pool->lock);
}
static bool send_mayday(struct work_struct *work)
{
struct pool_workqueue *pwq = get_work_pwq(work);
struct workqueue_struct *wq = pwq->wq;
unsigned int cpu;
if (!(wq->flags & WQ_RESCUER))
return false;
cpu = pwq->pool->cpu;
if (cpu == WORK_CPU_UNBOUND)
cpu = 0;
if (!mayday_test_and_set_cpu(cpu, wq->mayday_mask))
wake_up_process(wq->rescuer->task);
return true;
}
static void pool_mayday_timeout(unsigned long __pool)
{
struct worker_pool *pool = (void *)__pool;
struct work_struct *work;
spin_lock_irq(&pool->lock);
if (need_to_create_worker(pool)) {
list_for_each_entry(work, &pool->worklist, entry)
send_mayday(work);
}
spin_unlock_irq(&pool->lock);
mod_timer(&pool->mayday_timer, jiffies + MAYDAY_INTERVAL);
}
static bool maybe_create_worker(struct worker_pool *pool)
__releases(&pool->lock
static bool maybe_destroy_workers(struct worker_pool *pool)
{
bool ret = false;
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
ret = true;
}
return ret;
}
static bool manage_workers(struct worker *worker)
{
struct worker_pool *pool = worker->pool;
bool ret = false;
if (pool->flags & POOL_MANAGING_WORKERS)
return ret;
pool->flags |= POOL_MANAGING_WORKERS;
if (unlikely(!mutex_trylock(&pool->assoc_mutex))) {
spin_unlock_irq(&pool->lock);
mutex_lock(&pool->assoc_mutex);
if (worker_maybe_bind_and_lock(worker))
worker->flags &= ~WORKER_UNBOUND;
else
worker->flags |= WORKER_UNBOUND;
ret = true;
}
pool->flags &= ~POOL_MANAGE_WORKERS;
ret |= maybe_destroy_workers(pool);
ret |= maybe_create_worker(pool);
pool->flags &= ~POOL_MANAGING_WORKERS;
mutex_unlock(&pool->assoc_mutex);
return ret;
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
if (unlikely(list_empty(&worker->entry))) {
spin_unlock_irq(&pool->lock);
if (worker->flags & WORKER_DIE) {
worker->task->flags &= ~PF_WQ_WORKER;
return 0;
}
idle_worker_rebind(worker);
goto woke_up;
}
worker_leave_idle(worker);
recheck:
if (!need_more_worker(pool))
goto sleep;
if (unlikely(!may_start_working(pool)) && manage_workers(worker))
goto recheck;
BUG_ON(!list_empty(&worker->scheduled));
worker_clr_flags(worker, WORKER_PREP);
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
worker_set_flags(worker, WORKER_PREP, false);
sleep:
if (unlikely(need_to_manage_workers(pool)) && manage_workers(worker))
goto recheck;
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
bool is_unbound = wq->flags & WQ_UNBOUND;
unsigned int cpu;
set_user_nice(current, RESCUER_NICE_LEVEL);
rescuer->task->flags |= PF_WQ_WORKER;
repeat:
set_current_state(TASK_INTERRUPTIBLE);
if (kthread_should_stop()) {
__set_current_state(TASK_RUNNING);
rescuer->task->flags &= ~PF_WQ_WORKER;
return 0;
}
for_each_mayday_cpu(cpu, wq->mayday_mask) {
unsigned int tcpu = is_unbound ? WORK_CPU_UNBOUND : cpu;
struct pool_workqueue *pwq = get_pwq(tcpu, wq);
struct worker_pool *pool = pwq->pool;
struct work_struct *work, *n;
__set_current_state(TASK_RUNNING);
mayday_clear_cpu(cpu, wq->mayday_mask);
rescuer->pool = pool;
worker_maybe_bind_and_lock(rescuer);
BUG_ON(!list_empty(&rescuer->scheduled));
list_for_each_entry_safe(work, n, &pool->worklist, entry)
if (get_work_pwq(work) == pwq)
move_linked_works(work, scheduled, &n);
process_scheduled_works(rescuer);
if (keep_working(pool))
wake_up_worker(pool);
spin_unlock_irq(&pool->lock);
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
unsigned int cpu;
if (flush_color >= 0) {
BUG_ON(atomic_read(&wq->nr_pwqs_to_flush));
atomic_set(&wq->nr_pwqs_to_flush, 1);
}
for_each_pwq_cpu(cpu, wq) {
struct pool_workqueue *pwq = get_pwq(cpu, wq);
struct worker_pool *pool = pwq->pool;
spin_lock_irq(&pool->lock);
if (flush_color >= 0) {
BUG_ON(pwq->flush_color != -1);
if (pwq->nr_in_flight[flush_color]) {
pwq->flush_color = flush_color;
atomic_inc(&wq->nr_pwqs_to_flush);
wait = true;
}
}
if (work_color >= 0) {
BUG_ON(work_color != work_next_color(pwq->work_color));
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
mutex_lock(&wq->flush_mutex);
next_color = work_next_color(wq->work_color);
if (next_color != wq->flush_color) {
BUG_ON(!list_empty(&wq->flusher_overflow));
this_flusher.flush_color = wq->work_color;
wq->work_color = next_color;
if (!wq->first_flusher) {
BUG_ON(wq->flush_color != this_flusher.flush_color);
wq->first_flusher = &this_flusher;
if (!flush_workqueue_prep_pwqs(wq, wq->flush_color,
wq->work_color)) {
wq->flush_color = next_color;
wq->first_flusher = NULL;
goto out_unlock;
}
} else {
BUG_ON(wq->flush_color == this_flusher.flush_color);
list_add_tail(&this_flusher.list, &wq->flusher_queue);
flush_workqueue_prep_pwqs(wq, -1, wq->work_color);
}
} else {
list_add_tail(&this_flusher.list, &wq->flusher_overflow);
}
mutex_unlock(&wq->flush_mutex);
wait_for_completion(&this_flusher.done);
if (wq->first_flusher != &this_flusher)
return;
mutex_lock(&wq->flush_mutex);
if (wq->first_flusher != &this_flusher)
goto out_unlock;
wq->first_flusher = NULL;
BUG_ON(!list_empty(&this_flusher.list));
BUG_ON(wq->flush_color != this_flusher.flush_color);
while (true) {
struct wq_flusher *next, *tmp;
list_for_each_entry_safe(next, tmp, &wq->flusher_queue, list) {
if (next->flush_color != wq->flush_color)
break;
list_del_init(&next->list);
complete(&next->done);
}
BUG_ON(!list_empty(&wq->flusher_overflow) &&
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
BUG_ON(wq->flush_color != wq->work_color);
break;
}
BUG_ON(wq->flush_color == wq->work_color);
BUG_ON(wq->flush_color != next->flush_color);
list_del_init(&next->list);
wq->first_flusher = next;
if (flush_workqueue_prep_pwqs(wq, wq->flush_color, -1))
break;
wq->first_flusher = NULL;
}
out_unlock:
mutex_unlock(&wq->flush_mutex);
}
void drain_workqueue(struct workqueue_struct *wq)
{
unsigned int flush_cnt = 0;
unsigned int cpu;
spin_lock(&workqueue_lock);
if (!wq->nr_drainers++)
wq->flags |= WQ_DRAINING;
spin_unlock(&workqueue_lock);
reflush:
flush_workqueue(wq);
for_each_pwq_cpu(cpu, wq) {
struct pool_workqueue *pwq = get_pwq(cpu, wq);
bool drained;
spin_lock_irq(&pwq->pool->lock);
drained = !pwq->nr_active && list_empty(&pwq->delayed_works);
spin_unlock_irq(&pwq->pool->lock);
if (drained)
continue;
if (++flush_cnt == 10 ||
(flush_cnt % 100 == 0 && flush_cnt <= 1000))
pr_warn("workqueue %s: flush on destruction isn't complete after %u tries\n",
wq->name, flush_cnt);
goto reflush;
}
spin_lock(&workqueue_lock);
if (!--wq->nr_drainers)
wq->flags &= ~WQ_DRAINING;
spin_unlock(&workqueue_lock);
}
static bool start_flush_work(struct work_struct *work, struct wq_barrier *barr)
{
struct worker *worker = NULL;
struct worker_pool *pool;
struct pool_workqueue *pwq;
might_sleep();
pool = get_work_pool(work);
if (!pool)
return false;
spin_lock_irq(&pool->lock);
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
if (pwq->wq->saved_max_active == 1 || pwq->wq->flags & WQ_RESCUER)
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
bool schedule_work_on(int cpu, struct work_struct *work)
{
return queue_work_on(cpu, system_wq, work);
}
bool schedule_work(struct work_struct *work)
{
return queue_work(system_wq, work);
}
bool schedule_delayed_work_on(int cpu, struct delayed_work *dwork,
unsigned long delay)
{
return queue_delayed_work_on(cpu, system_wq, dwork, delay);
}
bool schedule_delayed_work(struct delayed_work *dwork, unsigned long delay)
{
return queue_delayed_work(system_wq, dwork, delay);
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
int keventd_up(void)
{
return system_wq != NULL;
}
static int alloc_pwqs(struct workqueue_struct *wq)
{
const size_t size = sizeof(struct pool_workqueue);
const size_t align = max_t(size_t, 1 << WORK_STRUCT_FLAG_BITS,
__alignof__(unsigned long long));
if (!(wq->flags & WQ_UNBOUND))
wq->pool_wq.pcpu = __alloc_percpu(size, align);
else {
void *ptr;
ptr = kzalloc(size + align + sizeof(void *), GFP_KERNEL);
if (ptr) {
wq->pool_wq.single = PTR_ALIGN(ptr, align);
*(void **)(wq->pool_wq.single + 1) = ptr;
}
}
BUG_ON(!IS_ALIGNED(wq->pool_wq.v, align));
return wq->pool_wq.v ? 0 : -ENOMEM;
}
static void free_pwqs(struct workqueue_struct *wq)
{
if (!(wq->flags & WQ_UNBOUND))
free_percpu(wq->pool_wq.pcpu);
else if (wq->pool_wq.single) {
kfree(*(void **)(wq->pool_wq.single + 1));
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
va_list args, args1;
struct workqueue_struct *wq;
unsigned int cpu;
size_t namelen;
va_start(args, lock_name);
va_copy(args1, args);
namelen = vsnprintf(NULL, 0, fmt, args) + 1;
wq = kzalloc(sizeof(*wq) + namelen, GFP_KERNEL);
if (!wq)
goto err;
vsnprintf(wq->name, namelen, fmt, args1);
va_end(args);
va_end(args1);
if (flags & WQ_MEM_RECLAIM)
flags |= WQ_RESCUER;
max_active = max_active ?: WQ_DFL_ACTIVE;
max_active = wq_clamp_max_active(max_active, flags, wq->name);
wq->flags = flags;
wq->saved_max_active = max_active;
mutex_init(&wq->flush_mutex);
atomic_set(&wq->nr_pwqs_to_flush, 0);
INIT_LIST_HEAD(&wq->flusher_queue);
INIT_LIST_HEAD(&wq->flusher_overflow);
lockdep_init_map(&wq->lockdep_map, lock_name, key, 0);
INIT_LIST_HEAD(&wq->list);
if (alloc_pwqs(wq) < 0)
goto err;
for_each_pwq_cpu(cpu, wq) {
struct pool_workqueue *pwq = get_pwq(cpu, wq);
BUG_ON((unsigned long)pwq & WORK_STRUCT_FLAG_MASK);
pwq->pool = get_std_worker_pool(cpu, flags & WQ_HIGHPRI);
pwq->wq = wq;
pwq->flush_color = -1;
pwq->max_active = max_active;
INIT_LIST_HEAD(&pwq->delayed_works);
}
if (flags & WQ_RESCUER) {
struct worker *rescuer;
if (!alloc_mayday_mask(&wq->mayday_mask, GFP_KERNEL))
goto err;
wq->rescuer = rescuer = alloc_worker();
if (!rescuer)
goto err;
rescuer->rescue_wq = wq;
rescuer->task = kthread_create(rescuer_thread, rescuer, "%s",
wq->name);
if (IS_ERR(rescuer->task))
goto err;
rescuer->task->flags |= PF_THREAD_BOUND;
wake_up_process(rescuer->task);
}
spin_lock(&workqueue_lock);
if (workqueue_freezing && wq->flags & WQ_FREEZABLE)
for_each_pwq_cpu(cpu, wq)
get_pwq(cpu, wq)->max_active = 0;
list_add(&wq->list, &workqueues);
spin_unlock(&workqueue_lock);
return wq;
err:
if (wq) {
free_pwqs(wq);
free_mayday_mask(wq->mayday_mask);
kfree(wq->rescuer);
kfree(wq);
}
return NULL;
}
void destroy_workqueue(struct workqueue_struct *wq)
{
unsigned int cpu;
drain_workqueue(wq);
spin_lock(&workqueue_lock);
list_del(&wq->list);
spin_unlock(&workqueue_lock);
for_each_pwq_cpu(cpu, wq) {
struct pool_workqueue *pwq = get_pwq(cpu, wq);
int i;
for (i = 0; i < WORK_NR_COLORS; i++)
BUG_ON(pwq->nr_in_flight[i]);
BUG_ON(pwq->nr_active);
BUG_ON(!list_empty(&pwq->delayed_works));
}
if (wq->flags & WQ_RESCUER) {
kthread_stop(wq->rescuer->task);
free_mayday_mask(wq->mayday_mask);
kfree(wq->rescuer);
}
free_pwqs(wq);
kfree(wq);
}
static void pwq_set_max_active(struct pool_workqueue *pwq, int max_active)
{
pwq->max_active = max_active;
while (!list_empty(&pwq->delayed_works) &&
pwq->nr_active < pwq->max_active)
pwq_activate_first_delayed(pwq);
}
void workqueue_set_max_active(struct workqueue_struct *wq, int max_active)
{
unsigned int cpu;
max_active = wq_clamp_max_active(max_active, wq->flags, wq->name);
spin_lock(&workqueue_lock);
wq->saved_max_active = max_active;
for_each_pwq_cpu(cpu, wq) {
struct pool_workqueue *pwq = get_pwq(cpu, wq);
struct worker_pool *pool = pwq->pool;
spin_lock_irq(&pool->lock);
if (!(wq->flags & WQ_FREEZABLE) ||
!(pool->flags & POOL_FREEZING))
pwq_set_max_active(pwq, max_active);
spin_unlock_irq(&pool->lock);
}
spin_unlock(&workqueue_lock);
}
bool workqueue_congested(unsigned int cpu, struct workqueue_struct *wq)
{
struct pool_workqueue *pwq = get_pwq(cpu, wq);
return !list_empty(&pwq->delayed_works);
}
unsigned int work_busy(struct work_struct *work)
{
struct worker_pool *pool = get_work_pool(work);
unsigned long flags;
unsigned int ret = 0;
if (work_pending(work))
ret |= WORK_BUSY_PENDING;
if (pool) {
spin_lock_irqsave(&pool->lock, flags);
if (find_worker_executing_work(pool, work))
ret |= WORK_BUSY_RUNNING;
spin_unlock_irqrestore(&pool->lock, flags);
}
return ret;
}
static void wq_unbind_fn(struct work_struct *work)
{
int cpu = smp_processor_id();
struct worker_pool *pool;
struct worker *worker;
int i;
for_each_std_worker_pool(pool, cpu) {
BUG_ON(cpu != smp_processor_id());
mutex_lock(&pool->assoc_mutex);
spin_lock_irq(&pool->lock);
list_for_each_entry(worker, &pool->idle_list, entry)
worker->flags |= WORKER_UNBOUND;
for_each_busy_worker(worker, i, pool)
worker->flags |= WORKER_UNBOUND;
pool->flags |= POOL_DISASSOCIATED;
spin_unlock_irq(&pool->lock);
mutex_unlock(&pool->assoc_mutex);
schedule();
atomic_set(&pool->nr_running, 0);
spin_lock_irq(&pool->lock);
wake_up_worker(pool);
spin_unlock_irq(&pool->lock);
}
}
static int __cpuinit workqueue_cpu_up_callback(struct notifier_block *nfb,
unsigned long action,
void *hcpu)
{
unsigned int cpu = (unsigned long)hcpu;
struct worker_pool *pool;
switch (action & ~CPU_TASKS_FROZEN) {
case CPU_UP_PREPARE:
for_each_std_worker_pool(pool, cpu) {
struct worker *worker;
if (pool->nr_workers)
continue;
worker = create_worker(pool);
if (!worker)
return NOTIFY_BAD;
spin_lock_irq(&pool->lock);
start_worker(worker);
spin_unlock_irq(&pool->lock);
}
break;
case CPU_DOWN_FAILED:
case CPU_ONLINE:
for_each_std_worker_pool(pool, cpu) {
mutex_lock(&pool->assoc_mutex);
spin_lock_irq(&pool->lock);
pool->flags &= ~POOL_DISASSOCIATED;
rebind_workers(pool);
spin_unlock_irq(&pool->lock);
mutex_unlock(&pool->assoc_mutex);
}
break;
}
return NOTIFY_OK;
}
static int __cpuinit workqueue_cpu_down_callback(struct notifier_block *nfb,
unsigned long action,
void *hcpu)
{
unsigned int cpu = (unsigned long)hcpu;
struct work_struct unbind_work;
switch (action & ~CPU_TASKS_FROZEN) {
case CPU_DOWN_PREPARE:
INIT_WORK_ONSTACK(&unbind_work, wq_unbind_fn);
queue_work_on(cpu, system_highpri_wq, &unbind_work);
flush_work(&unbind_work);
break;
}
return NOTIFY_OK;
}
static void work_for_cpu_fn(struct work_struct *work)
{
struct work_for_cpu *wfc = container_of(work, struct work_for_cpu, work);
wfc->ret = wfc->fn(wfc->arg);
}
long work_on_cpu(unsigned int cpu, long (*fn)(void *), void *arg)
{
struct work_for_cpu wfc = { .fn = fn, .arg = arg };
INIT_WORK_ONSTACK(&wfc.work, work_for_cpu_fn);
schedule_work_on(cpu, &wfc.work);
flush_work(&wfc.work);
return wfc.ret;
}
void freeze_workqueues_begin(void)
{
unsigned int cpu;
spin_lock(&workqueue_lock);
BUG_ON(workqueue_freezing);
workqueue_freezing = true;
for_each_wq_cpu(cpu) {
struct worker_pool *pool;
struct workqueue_struct *wq;
for_each_std_worker_pool(pool, cpu) {
spin_lock_irq(&pool->lock);
WARN_ON_ONCE(pool->flags & POOL_FREEZING);
pool->flags |= POOL_FREEZING;
list_for_each_entry(wq, &workqueues, list) {
struct pool_workqueue *pwq = get_pwq(cpu, wq);
if (pwq && pwq->pool == pool &&
(wq->flags & WQ_FREEZABLE))
pwq->max_active = 0;
}
spin_unlock_irq(&pool->lock);
}
}
spin_unlock(&workqueue_lock);
}
bool freeze_workqueues_busy(void)
{
unsigned int cpu;
bool busy = false;
spin_lock(&workqueue_lock);
BUG_ON(!workqueue_freezing);
for_each_wq_cpu(cpu) {
struct workqueue_struct *wq;
list_for_each_entry(wq, &workqueues, list) {
struct pool_workqueue *pwq = get_pwq(cpu, wq);
if (!pwq || !(wq->flags & WQ_FREEZABLE))
continue;
BUG_ON(pwq->nr_active < 0);
if (pwq->nr_active) {
busy = true;
goto out_unlock;
}
}
}
out_unlock:
spin_unlock(&workqueue_lock);
return busy;
}
void thaw_workqueues(void)
{
unsigned int cpu;
spin_lock(&workqueue_lock);
if (!workqueue_freezing)
goto out_unlock;
for_each_wq_cpu(cpu) {
struct worker_pool *pool;
struct workqueue_struct *wq;
for_each_std_worker_pool(pool, cpu) {
spin_lock_irq(&pool->lock);
WARN_ON_ONCE(!(pool->flags & POOL_FREEZING));
pool->flags &= ~POOL_FREEZING;
list_for_each_entry(wq, &workqueues, list) {
struct pool_workqueue *pwq = get_pwq(cpu, wq);
if (!pwq || pwq->pool != pool ||
!(wq->flags & WQ_FREEZABLE))
continue;
pwq_set_max_active(pwq, wq->saved_max_active);
}
wake_up_worker(pool);
spin_unlock_irq(&pool->lock);
}
}
workqueue_freezing = false;
out_unlock:
spin_unlock(&workqueue_lock);
}
static int __init init_workqueues(void)
{
unsigned int cpu;
BUILD_BUG_ON((1LU << (BITS_PER_LONG - WORK_OFFQ_POOL_SHIFT)) <
WORK_CPU_END * NR_STD_WORKER_POOLS);
cpu_notifier(workqueue_cpu_up_callback, CPU_PRI_WORKQUEUE_UP);
hotcpu_notifier(workqueue_cpu_down_callback, CPU_PRI_WORKQUEUE_DOWN);
for_each_wq_cpu(cpu) {
struct worker_pool *pool;
for_each_std_worker_pool(pool, cpu) {
spin_lock_init(&pool->lock);
pool->cpu = cpu;
pool->flags |= POOL_DISASSOCIATED;
INIT_LIST_HEAD(&pool->worklist);
INIT_LIST_HEAD(&pool->idle_list);
hash_init(pool->busy_hash);
init_timer_deferrable(&pool->idle_timer);
pool->idle_timer.function = idle_worker_timeout;
pool->idle_timer.data = (unsigned long)pool;
setup_timer(&pool->mayday_timer, pool_mayday_timeout,
(unsigned long)pool);
mutex_init(&pool->assoc_mutex);
ida_init(&pool->worker_ida);
BUG_ON(worker_pool_assign_id(pool));
}
}
for_each_online_wq_cpu(cpu) {
struct worker_pool *pool;
for_each_std_worker_pool(pool, cpu) {
struct worker *worker;
if (cpu != WORK_CPU_UNBOUND)
pool->flags &= ~POOL_DISASSOCIATED;
worker = create_worker(pool);
BUG_ON(!worker);
spin_lock_irq(&pool->lock);
start_worker(worker);
spin_unlock_irq(&pool->lock);
}
}
system_wq = alloc_workqueue("events", 0, 0);
system_highpri_wq = alloc_workqueue("events_highpri", WQ_HIGHPRI, 0);
system_long_wq = alloc_workqueue("events_long", 0, 0);
system_unbound_wq = alloc_workqueue("events_unbound", WQ_UNBOUND,
WQ_UNBOUND_MAX_ACTIVE);
system_freezable_wq = alloc_workqueue("events_freezable",
WQ_FREEZABLE, 0);
BUG_ON(!system_wq || !system_highpri_wq || !system_long_wq ||
!system_unbound_wq || !system_freezable_wq);
return 0;
}
