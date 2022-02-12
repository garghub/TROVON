static inline struct task_struct *dl_task_of(struct sched_dl_entity *dl_se)
{
return container_of(dl_se, struct task_struct, dl);
}
static inline struct rq *rq_of_dl_rq(struct dl_rq *dl_rq)
{
return container_of(dl_rq, struct rq, dl);
}
static inline struct dl_rq *dl_rq_of_se(struct sched_dl_entity *dl_se)
{
struct task_struct *p = dl_task_of(dl_se);
struct rq *rq = task_rq(p);
return &rq->dl;
}
static inline int on_dl_rq(struct sched_dl_entity *dl_se)
{
return !RB_EMPTY_NODE(&dl_se->rb_node);
}
static inline int is_leftmost(struct task_struct *p, struct dl_rq *dl_rq)
{
struct sched_dl_entity *dl_se = &p->dl;
return dl_rq->rb_leftmost == &dl_se->rb_node;
}
void init_dl_bandwidth(struct dl_bandwidth *dl_b, u64 period, u64 runtime)
{
raw_spin_lock_init(&dl_b->dl_runtime_lock);
dl_b->dl_period = period;
dl_b->dl_runtime = runtime;
}
void init_dl_bw(struct dl_bw *dl_b)
{
raw_spin_lock_init(&dl_b->lock);
raw_spin_lock(&def_dl_bandwidth.dl_runtime_lock);
if (global_rt_runtime() == RUNTIME_INF)
dl_b->bw = -1;
else
dl_b->bw = to_ratio(global_rt_period(), global_rt_runtime());
raw_spin_unlock(&def_dl_bandwidth.dl_runtime_lock);
dl_b->total_bw = 0;
}
void init_dl_rq(struct dl_rq *dl_rq)
{
dl_rq->rb_root = RB_ROOT;
#ifdef CONFIG_SMP
dl_rq->earliest_dl.curr = dl_rq->earliest_dl.next = 0;
dl_rq->dl_nr_migratory = 0;
dl_rq->overloaded = 0;
dl_rq->pushable_dl_tasks_root = RB_ROOT;
#else
init_dl_bw(&dl_rq->dl_bw);
#endif
}
static inline int dl_overloaded(struct rq *rq)
{
return atomic_read(&rq->rd->dlo_count);
}
static inline void dl_set_overload(struct rq *rq)
{
if (!rq->online)
return;
cpumask_set_cpu(rq->cpu, rq->rd->dlo_mask);
smp_wmb();
atomic_inc(&rq->rd->dlo_count);
}
static inline void dl_clear_overload(struct rq *rq)
{
if (!rq->online)
return;
atomic_dec(&rq->rd->dlo_count);
cpumask_clear_cpu(rq->cpu, rq->rd->dlo_mask);
}
static void update_dl_migration(struct dl_rq *dl_rq)
{
if (dl_rq->dl_nr_migratory && dl_rq->dl_nr_running > 1) {
if (!dl_rq->overloaded) {
dl_set_overload(rq_of_dl_rq(dl_rq));
dl_rq->overloaded = 1;
}
} else if (dl_rq->overloaded) {
dl_clear_overload(rq_of_dl_rq(dl_rq));
dl_rq->overloaded = 0;
}
}
static void inc_dl_migration(struct sched_dl_entity *dl_se, struct dl_rq *dl_rq)
{
struct task_struct *p = dl_task_of(dl_se);
if (p->nr_cpus_allowed > 1)
dl_rq->dl_nr_migratory++;
update_dl_migration(dl_rq);
}
static void dec_dl_migration(struct sched_dl_entity *dl_se, struct dl_rq *dl_rq)
{
struct task_struct *p = dl_task_of(dl_se);
if (p->nr_cpus_allowed > 1)
dl_rq->dl_nr_migratory--;
update_dl_migration(dl_rq);
}
static void enqueue_pushable_dl_task(struct rq *rq, struct task_struct *p)
{
struct dl_rq *dl_rq = &rq->dl;
struct rb_node **link = &dl_rq->pushable_dl_tasks_root.rb_node;
struct rb_node *parent = NULL;
struct task_struct *entry;
int leftmost = 1;
BUG_ON(!RB_EMPTY_NODE(&p->pushable_dl_tasks));
while (*link) {
parent = *link;
entry = rb_entry(parent, struct task_struct,
pushable_dl_tasks);
if (dl_entity_preempt(&p->dl, &entry->dl))
link = &parent->rb_left;
else {
link = &parent->rb_right;
leftmost = 0;
}
}
if (leftmost)
dl_rq->pushable_dl_tasks_leftmost = &p->pushable_dl_tasks;
rb_link_node(&p->pushable_dl_tasks, parent, link);
rb_insert_color(&p->pushable_dl_tasks, &dl_rq->pushable_dl_tasks_root);
}
static void dequeue_pushable_dl_task(struct rq *rq, struct task_struct *p)
{
struct dl_rq *dl_rq = &rq->dl;
if (RB_EMPTY_NODE(&p->pushable_dl_tasks))
return;
if (dl_rq->pushable_dl_tasks_leftmost == &p->pushable_dl_tasks) {
struct rb_node *next_node;
next_node = rb_next(&p->pushable_dl_tasks);
dl_rq->pushable_dl_tasks_leftmost = next_node;
}
rb_erase(&p->pushable_dl_tasks, &dl_rq->pushable_dl_tasks_root);
RB_CLEAR_NODE(&p->pushable_dl_tasks);
}
static inline int has_pushable_dl_tasks(struct rq *rq)
{
return !RB_EMPTY_ROOT(&rq->dl.pushable_dl_tasks_root);
}
static inline bool need_pull_dl_task(struct rq *rq, struct task_struct *prev)
{
return dl_task(prev);
}
static inline void queue_push_tasks(struct rq *rq)
{
if (!has_pushable_dl_tasks(rq))
return;
queue_balance_callback(rq, &per_cpu(dl_push_head, rq->cpu), push_dl_tasks);
}
static inline void queue_pull_task(struct rq *rq)
{
queue_balance_callback(rq, &per_cpu(dl_pull_head, rq->cpu), pull_dl_task);
}
static struct rq *dl_task_offline_migration(struct rq *rq, struct task_struct *p)
{
struct rq *later_rq = NULL;
bool fallback = false;
later_rq = find_lock_later_rq(p, rq);
if (!later_rq) {
int cpu;
fallback = true;
cpu = cpumask_any_and(cpu_active_mask, tsk_cpus_allowed(p));
if (cpu >= nr_cpu_ids) {
BUG_ON(dl_bandwidth_enabled());
cpu = cpumask_any(cpu_active_mask);
}
later_rq = cpu_rq(cpu);
double_lock_balance(rq, later_rq);
}
deactivate_task(rq, p, 0);
set_task_cpu(p, later_rq->cpu);
activate_task(later_rq, p, 0);
if (!fallback)
resched_curr(later_rq);
double_unlock_balance(later_rq, rq);
return later_rq;
}
static inline
void enqueue_pushable_dl_task(struct rq *rq, struct task_struct *p)
{
}
static inline
void dequeue_pushable_dl_task(struct rq *rq, struct task_struct *p)
{
}
static inline
void inc_dl_migration(struct sched_dl_entity *dl_se, struct dl_rq *dl_rq)
{
}
static inline
void dec_dl_migration(struct sched_dl_entity *dl_se, struct dl_rq *dl_rq)
{
}
static inline bool need_pull_dl_task(struct rq *rq, struct task_struct *prev)
{
return false;
}
static inline void pull_dl_task(struct rq *rq)
{
}
static inline void queue_push_tasks(struct rq *rq)
{
}
static inline void queue_pull_task(struct rq *rq)
{
}
static inline void setup_new_dl_entity(struct sched_dl_entity *dl_se,
struct sched_dl_entity *pi_se)
{
struct dl_rq *dl_rq = dl_rq_of_se(dl_se);
struct rq *rq = rq_of_dl_rq(dl_rq);
WARN_ON(!dl_se->dl_new || dl_se->dl_throttled);
dl_se->deadline = rq_clock(rq) + pi_se->dl_deadline;
dl_se->runtime = pi_se->dl_runtime;
dl_se->dl_new = 0;
}
static void replenish_dl_entity(struct sched_dl_entity *dl_se,
struct sched_dl_entity *pi_se)
{
struct dl_rq *dl_rq = dl_rq_of_se(dl_se);
struct rq *rq = rq_of_dl_rq(dl_rq);
BUG_ON(pi_se->dl_runtime <= 0);
if (dl_se->dl_deadline == 0) {
dl_se->deadline = rq_clock(rq) + pi_se->dl_deadline;
dl_se->runtime = pi_se->dl_runtime;
}
while (dl_se->runtime <= 0) {
dl_se->deadline += pi_se->dl_period;
dl_se->runtime += pi_se->dl_runtime;
}
if (dl_time_before(dl_se->deadline, rq_clock(rq))) {
printk_deferred_once("sched: DL replenish lagged to much\n");
dl_se->deadline = rq_clock(rq) + pi_se->dl_deadline;
dl_se->runtime = pi_se->dl_runtime;
}
if (dl_se->dl_yielded)
dl_se->dl_yielded = 0;
if (dl_se->dl_throttled)
dl_se->dl_throttled = 0;
}
static bool dl_entity_overflow(struct sched_dl_entity *dl_se,
struct sched_dl_entity *pi_se, u64 t)
{
u64 left, right;
left = (pi_se->dl_period >> DL_SCALE) * (dl_se->runtime >> DL_SCALE);
right = ((dl_se->deadline - t) >> DL_SCALE) *
(pi_se->dl_runtime >> DL_SCALE);
return dl_time_before(right, left);
}
static void update_dl_entity(struct sched_dl_entity *dl_se,
struct sched_dl_entity *pi_se)
{
struct dl_rq *dl_rq = dl_rq_of_se(dl_se);
struct rq *rq = rq_of_dl_rq(dl_rq);
if (dl_se->dl_new) {
setup_new_dl_entity(dl_se, pi_se);
return;
}
if (dl_time_before(dl_se->deadline, rq_clock(rq)) ||
dl_entity_overflow(dl_se, pi_se, rq_clock(rq))) {
dl_se->deadline = rq_clock(rq) + pi_se->dl_deadline;
dl_se->runtime = pi_se->dl_runtime;
}
}
static int start_dl_timer(struct task_struct *p)
{
struct sched_dl_entity *dl_se = &p->dl;
struct hrtimer *timer = &dl_se->dl_timer;
struct rq *rq = task_rq(p);
ktime_t now, act;
s64 delta;
lockdep_assert_held(&rq->lock);
act = ns_to_ktime(dl_se->deadline);
now = hrtimer_cb_get_time(timer);
delta = ktime_to_ns(now) - rq_clock(rq);
act = ktime_add_ns(act, delta);
if (ktime_us_delta(act, now) < 0)
return 0;
if (!hrtimer_is_queued(timer)) {
get_task_struct(p);
hrtimer_start(timer, act, HRTIMER_MODE_ABS);
}
return 1;
}
static enum hrtimer_restart dl_task_timer(struct hrtimer *timer)
{
struct sched_dl_entity *dl_se = container_of(timer,
struct sched_dl_entity,
dl_timer);
struct task_struct *p = dl_task_of(dl_se);
unsigned long flags;
struct rq *rq;
rq = task_rq_lock(p, &flags);
if (!dl_task(p)) {
__dl_clear_params(p);
goto unlock;
}
if (dl_se->dl_new)
goto unlock;
if (dl_se->dl_boosted)
goto unlock;
if (!dl_se->dl_throttled)
goto unlock;
sched_clock_tick();
update_rq_clock(rq);
if (!task_on_rq_queued(p)) {
replenish_dl_entity(dl_se, dl_se);
goto unlock;
}
enqueue_task_dl(rq, p, ENQUEUE_REPLENISH);
if (dl_task(rq->curr))
check_preempt_curr_dl(rq, p, 0);
else
resched_curr(rq);
#ifdef CONFIG_SMP
if (unlikely(!rq->online))
rq = dl_task_offline_migration(rq, p);
if (has_pushable_dl_tasks(rq)) {
lockdep_unpin_lock(&rq->lock);
push_dl_task(rq);
lockdep_pin_lock(&rq->lock);
}
#endif
unlock:
task_rq_unlock(rq, p, &flags);
put_task_struct(p);
return HRTIMER_NORESTART;
}
void init_dl_task_timer(struct sched_dl_entity *dl_se)
{
struct hrtimer *timer = &dl_se->dl_timer;
hrtimer_init(timer, CLOCK_MONOTONIC, HRTIMER_MODE_REL);
timer->function = dl_task_timer;
}
static
int dl_runtime_exceeded(struct sched_dl_entity *dl_se)
{
return (dl_se->runtime <= 0);
}
static void update_curr_dl(struct rq *rq)
{
struct task_struct *curr = rq->curr;
struct sched_dl_entity *dl_se = &curr->dl;
u64 delta_exec;
if (!dl_task(curr) || !on_dl_rq(dl_se))
return;
delta_exec = rq_clock_task(rq) - curr->se.exec_start;
if (unlikely((s64)delta_exec <= 0))
return;
schedstat_set(curr->se.statistics.exec_max,
max(curr->se.statistics.exec_max, delta_exec));
curr->se.sum_exec_runtime += delta_exec;
account_group_exec_runtime(curr, delta_exec);
curr->se.exec_start = rq_clock_task(rq);
cpuacct_charge(curr, delta_exec);
sched_rt_avg_update(rq, delta_exec);
dl_se->runtime -= dl_se->dl_yielded ? 0 : delta_exec;
if (dl_runtime_exceeded(dl_se)) {
dl_se->dl_throttled = 1;
__dequeue_task_dl(rq, curr, 0);
if (unlikely(dl_se->dl_boosted || !start_dl_timer(curr)))
enqueue_task_dl(rq, curr, ENQUEUE_REPLENISH);
if (!is_leftmost(curr, &rq->dl))
resched_curr(rq);
}
if (rt_bandwidth_enabled()) {
struct rt_rq *rt_rq = &rq->rt;
raw_spin_lock(&rt_rq->rt_runtime_lock);
if (sched_rt_bandwidth_account(rt_rq))
rt_rq->rt_time += delta_exec;
raw_spin_unlock(&rt_rq->rt_runtime_lock);
}
}
static inline u64 next_deadline(struct rq *rq)
{
struct task_struct *next = pick_next_earliest_dl_task(rq, rq->cpu);
if (next && dl_prio(next->prio))
return next->dl.deadline;
else
return 0;
}
static void inc_dl_deadline(struct dl_rq *dl_rq, u64 deadline)
{
struct rq *rq = rq_of_dl_rq(dl_rq);
if (dl_rq->earliest_dl.curr == 0 ||
dl_time_before(deadline, dl_rq->earliest_dl.curr)) {
dl_rq->earliest_dl.next = dl_rq->earliest_dl.curr;
dl_rq->earliest_dl.curr = deadline;
cpudl_set(&rq->rd->cpudl, rq->cpu, deadline, 1);
} else if (dl_rq->earliest_dl.next == 0 ||
dl_time_before(deadline, dl_rq->earliest_dl.next)) {
dl_rq->earliest_dl.next = next_deadline(rq);
}
}
static void dec_dl_deadline(struct dl_rq *dl_rq, u64 deadline)
{
struct rq *rq = rq_of_dl_rq(dl_rq);
if (!dl_rq->dl_nr_running) {
dl_rq->earliest_dl.curr = 0;
dl_rq->earliest_dl.next = 0;
cpudl_set(&rq->rd->cpudl, rq->cpu, 0, 0);
} else {
struct rb_node *leftmost = dl_rq->rb_leftmost;
struct sched_dl_entity *entry;
entry = rb_entry(leftmost, struct sched_dl_entity, rb_node);
dl_rq->earliest_dl.curr = entry->deadline;
dl_rq->earliest_dl.next = next_deadline(rq);
cpudl_set(&rq->rd->cpudl, rq->cpu, entry->deadline, 1);
}
}
static inline void inc_dl_deadline(struct dl_rq *dl_rq, u64 deadline) {}
static inline void dec_dl_deadline(struct dl_rq *dl_rq, u64 deadline) {}
static inline
void inc_dl_tasks(struct sched_dl_entity *dl_se, struct dl_rq *dl_rq)
{
int prio = dl_task_of(dl_se)->prio;
u64 deadline = dl_se->deadline;
WARN_ON(!dl_prio(prio));
dl_rq->dl_nr_running++;
add_nr_running(rq_of_dl_rq(dl_rq), 1);
inc_dl_deadline(dl_rq, deadline);
inc_dl_migration(dl_se, dl_rq);
}
static inline
void dec_dl_tasks(struct sched_dl_entity *dl_se, struct dl_rq *dl_rq)
{
int prio = dl_task_of(dl_se)->prio;
WARN_ON(!dl_prio(prio));
WARN_ON(!dl_rq->dl_nr_running);
dl_rq->dl_nr_running--;
sub_nr_running(rq_of_dl_rq(dl_rq), 1);
dec_dl_deadline(dl_rq, dl_se->deadline);
dec_dl_migration(dl_se, dl_rq);
}
static void __enqueue_dl_entity(struct sched_dl_entity *dl_se)
{
struct dl_rq *dl_rq = dl_rq_of_se(dl_se);
struct rb_node **link = &dl_rq->rb_root.rb_node;
struct rb_node *parent = NULL;
struct sched_dl_entity *entry;
int leftmost = 1;
BUG_ON(!RB_EMPTY_NODE(&dl_se->rb_node));
while (*link) {
parent = *link;
entry = rb_entry(parent, struct sched_dl_entity, rb_node);
if (dl_time_before(dl_se->deadline, entry->deadline))
link = &parent->rb_left;
else {
link = &parent->rb_right;
leftmost = 0;
}
}
if (leftmost)
dl_rq->rb_leftmost = &dl_se->rb_node;
rb_link_node(&dl_se->rb_node, parent, link);
rb_insert_color(&dl_se->rb_node, &dl_rq->rb_root);
inc_dl_tasks(dl_se, dl_rq);
}
static void __dequeue_dl_entity(struct sched_dl_entity *dl_se)
{
struct dl_rq *dl_rq = dl_rq_of_se(dl_se);
if (RB_EMPTY_NODE(&dl_se->rb_node))
return;
if (dl_rq->rb_leftmost == &dl_se->rb_node) {
struct rb_node *next_node;
next_node = rb_next(&dl_se->rb_node);
dl_rq->rb_leftmost = next_node;
}
rb_erase(&dl_se->rb_node, &dl_rq->rb_root);
RB_CLEAR_NODE(&dl_se->rb_node);
dec_dl_tasks(dl_se, dl_rq);
}
static void
enqueue_dl_entity(struct sched_dl_entity *dl_se,
struct sched_dl_entity *pi_se, int flags)
{
BUG_ON(on_dl_rq(dl_se));
if (dl_se->dl_new || flags & ENQUEUE_WAKEUP)
update_dl_entity(dl_se, pi_se);
else if (flags & ENQUEUE_REPLENISH)
replenish_dl_entity(dl_se, pi_se);
__enqueue_dl_entity(dl_se);
}
static void dequeue_dl_entity(struct sched_dl_entity *dl_se)
{
__dequeue_dl_entity(dl_se);
}
static void enqueue_task_dl(struct rq *rq, struct task_struct *p, int flags)
{
struct task_struct *pi_task = rt_mutex_get_top_task(p);
struct sched_dl_entity *pi_se = &p->dl;
if (pi_task && p->dl.dl_boosted && dl_prio(pi_task->normal_prio)) {
pi_se = &pi_task->dl;
} else if (!dl_prio(p->normal_prio)) {
BUG_ON(!p->dl.dl_boosted || flags != ENQUEUE_REPLENISH);
return;
}
if (p->dl.dl_throttled && !(flags & ENQUEUE_REPLENISH))
return;
enqueue_dl_entity(&p->dl, pi_se, flags);
if (!task_current(rq, p) && p->nr_cpus_allowed > 1)
enqueue_pushable_dl_task(rq, p);
}
static void __dequeue_task_dl(struct rq *rq, struct task_struct *p, int flags)
{
dequeue_dl_entity(&p->dl);
dequeue_pushable_dl_task(rq, p);
}
static void dequeue_task_dl(struct rq *rq, struct task_struct *p, int flags)
{
update_curr_dl(rq);
__dequeue_task_dl(rq, p, flags);
}
static void yield_task_dl(struct rq *rq)
{
struct task_struct *p = rq->curr;
if (p->dl.runtime > 0) {
rq->curr->dl.dl_yielded = 1;
p->dl.runtime = 0;
}
update_rq_clock(rq);
update_curr_dl(rq);
rq_clock_skip_update(rq, true);
}
static int
select_task_rq_dl(struct task_struct *p, int cpu, int sd_flag, int flags)
{
struct task_struct *curr;
struct rq *rq;
if (sd_flag != SD_BALANCE_WAKE)
goto out;
rq = cpu_rq(cpu);
rcu_read_lock();
curr = READ_ONCE(rq->curr);
if (unlikely(dl_task(curr)) &&
(curr->nr_cpus_allowed < 2 ||
!dl_entity_preempt(&p->dl, &curr->dl)) &&
(p->nr_cpus_allowed > 1)) {
int target = find_later_rq(p);
if (target != -1 &&
(dl_time_before(p->dl.deadline,
cpu_rq(target)->dl.earliest_dl.curr) ||
(cpu_rq(target)->dl.dl_nr_running == 0)))
cpu = target;
}
rcu_read_unlock();
out:
return cpu;
}
static void check_preempt_equal_dl(struct rq *rq, struct task_struct *p)
{
if (rq->curr->nr_cpus_allowed == 1 ||
cpudl_find(&rq->rd->cpudl, rq->curr, NULL) == -1)
return;
if (p->nr_cpus_allowed != 1 &&
cpudl_find(&rq->rd->cpudl, p, NULL) != -1)
return;
resched_curr(rq);
}
static void check_preempt_curr_dl(struct rq *rq, struct task_struct *p,
int flags)
{
if (dl_entity_preempt(&p->dl, &rq->curr->dl)) {
resched_curr(rq);
return;
}
#ifdef CONFIG_SMP
if ((p->dl.deadline == rq->curr->dl.deadline) &&
!test_tsk_need_resched(rq->curr))
check_preempt_equal_dl(rq, p);
#endif
}
static void start_hrtick_dl(struct rq *rq, struct task_struct *p)
{
hrtick_start(rq, p->dl.runtime);
}
static void start_hrtick_dl(struct rq *rq, struct task_struct *p)
{
}
static struct sched_dl_entity *pick_next_dl_entity(struct rq *rq,
struct dl_rq *dl_rq)
{
struct rb_node *left = dl_rq->rb_leftmost;
if (!left)
return NULL;
return rb_entry(left, struct sched_dl_entity, rb_node);
}
struct task_struct *pick_next_task_dl(struct rq *rq, struct task_struct *prev)
{
struct sched_dl_entity *dl_se;
struct task_struct *p;
struct dl_rq *dl_rq;
dl_rq = &rq->dl;
if (need_pull_dl_task(rq, prev)) {
lockdep_unpin_lock(&rq->lock);
pull_dl_task(rq);
lockdep_pin_lock(&rq->lock);
if (rq->stop && task_on_rq_queued(rq->stop))
return RETRY_TASK;
}
if (prev->sched_class == &dl_sched_class)
update_curr_dl(rq);
if (unlikely(!dl_rq->dl_nr_running))
return NULL;
put_prev_task(rq, prev);
dl_se = pick_next_dl_entity(rq, dl_rq);
BUG_ON(!dl_se);
p = dl_task_of(dl_se);
p->se.exec_start = rq_clock_task(rq);
dequeue_pushable_dl_task(rq, p);
if (hrtick_enabled(rq))
start_hrtick_dl(rq, p);
queue_push_tasks(rq);
return p;
}
static void put_prev_task_dl(struct rq *rq, struct task_struct *p)
{
update_curr_dl(rq);
if (on_dl_rq(&p->dl) && p->nr_cpus_allowed > 1)
enqueue_pushable_dl_task(rq, p);
}
static void task_tick_dl(struct rq *rq, struct task_struct *p, int queued)
{
update_curr_dl(rq);
if (hrtick_enabled(rq) && queued && p->dl.runtime > 0 &&
is_leftmost(p, &rq->dl))
start_hrtick_dl(rq, p);
}
static void task_fork_dl(struct task_struct *p)
{
}
static void task_dead_dl(struct task_struct *p)
{
struct dl_bw *dl_b = dl_bw_of(task_cpu(p));
raw_spin_lock_irq(&dl_b->lock);
dl_b->total_bw -= p->dl.dl_bw;
raw_spin_unlock_irq(&dl_b->lock);
}
static void set_curr_task_dl(struct rq *rq)
{
struct task_struct *p = rq->curr;
p->se.exec_start = rq_clock_task(rq);
dequeue_pushable_dl_task(rq, p);
}
static int pick_dl_task(struct rq *rq, struct task_struct *p, int cpu)
{
if (!task_running(rq, p) &&
cpumask_test_cpu(cpu, tsk_cpus_allowed(p)))
return 1;
return 0;
}
static struct task_struct *pick_next_earliest_dl_task(struct rq *rq, int cpu)
{
struct rb_node *next_node = rq->dl.rb_leftmost;
struct sched_dl_entity *dl_se;
struct task_struct *p = NULL;
next_node:
next_node = rb_next(next_node);
if (next_node) {
dl_se = rb_entry(next_node, struct sched_dl_entity, rb_node);
p = dl_task_of(dl_se);
if (pick_dl_task(rq, p, cpu))
return p;
goto next_node;
}
return NULL;
}
static struct task_struct *pick_earliest_pushable_dl_task(struct rq *rq, int cpu)
{
struct rb_node *next_node = rq->dl.pushable_dl_tasks_leftmost;
struct task_struct *p = NULL;
if (!has_pushable_dl_tasks(rq))
return NULL;
next_node:
if (next_node) {
p = rb_entry(next_node, struct task_struct, pushable_dl_tasks);
if (pick_dl_task(rq, p, cpu))
return p;
next_node = rb_next(next_node);
goto next_node;
}
return NULL;
}
static int find_later_rq(struct task_struct *task)
{
struct sched_domain *sd;
struct cpumask *later_mask = this_cpu_cpumask_var_ptr(local_cpu_mask_dl);
int this_cpu = smp_processor_id();
int best_cpu, cpu = task_cpu(task);
if (unlikely(!later_mask))
return -1;
if (task->nr_cpus_allowed == 1)
return -1;
best_cpu = cpudl_find(&task_rq(task)->rd->cpudl,
task, later_mask);
if (best_cpu == -1)
return -1;
if (cpumask_test_cpu(cpu, later_mask))
return cpu;
if (!cpumask_test_cpu(this_cpu, later_mask))
this_cpu = -1;
rcu_read_lock();
for_each_domain(cpu, sd) {
if (sd->flags & SD_WAKE_AFFINE) {
if (this_cpu != -1 &&
cpumask_test_cpu(this_cpu, sched_domain_span(sd))) {
rcu_read_unlock();
return this_cpu;
}
if (best_cpu < nr_cpu_ids &&
cpumask_test_cpu(best_cpu, sched_domain_span(sd))) {
rcu_read_unlock();
return best_cpu;
}
}
}
rcu_read_unlock();
if (this_cpu != -1)
return this_cpu;
cpu = cpumask_any(later_mask);
if (cpu < nr_cpu_ids)
return cpu;
return -1;
}
static struct rq *find_lock_later_rq(struct task_struct *task, struct rq *rq)
{
struct rq *later_rq = NULL;
int tries;
int cpu;
for (tries = 0; tries < DL_MAX_TRIES; tries++) {
cpu = find_later_rq(task);
if ((cpu == -1) || (cpu == rq->cpu))
break;
later_rq = cpu_rq(cpu);
if (later_rq->dl.dl_nr_running &&
!dl_time_before(task->dl.deadline,
later_rq->dl.earliest_dl.curr)) {
later_rq = NULL;
break;
}
if (double_lock_balance(rq, later_rq)) {
if (unlikely(task_rq(task) != rq ||
!cpumask_test_cpu(later_rq->cpu,
&task->cpus_allowed) ||
task_running(rq, task) ||
!task_on_rq_queued(task))) {
double_unlock_balance(rq, later_rq);
later_rq = NULL;
break;
}
}
if (!later_rq->dl.dl_nr_running ||
dl_time_before(task->dl.deadline,
later_rq->dl.earliest_dl.curr))
break;
double_unlock_balance(rq, later_rq);
later_rq = NULL;
}
return later_rq;
}
static struct task_struct *pick_next_pushable_dl_task(struct rq *rq)
{
struct task_struct *p;
if (!has_pushable_dl_tasks(rq))
return NULL;
p = rb_entry(rq->dl.pushable_dl_tasks_leftmost,
struct task_struct, pushable_dl_tasks);
BUG_ON(rq->cpu != task_cpu(p));
BUG_ON(task_current(rq, p));
BUG_ON(p->nr_cpus_allowed <= 1);
BUG_ON(!task_on_rq_queued(p));
BUG_ON(!dl_task(p));
return p;
}
static int push_dl_task(struct rq *rq)
{
struct task_struct *next_task;
struct rq *later_rq;
int ret = 0;
if (!rq->dl.overloaded)
return 0;
next_task = pick_next_pushable_dl_task(rq);
if (!next_task)
return 0;
retry:
if (unlikely(next_task == rq->curr)) {
WARN_ON(1);
return 0;
}
if (dl_task(rq->curr) &&
dl_time_before(next_task->dl.deadline, rq->curr->dl.deadline) &&
rq->curr->nr_cpus_allowed > 1) {
resched_curr(rq);
return 0;
}
get_task_struct(next_task);
later_rq = find_lock_later_rq(next_task, rq);
if (!later_rq) {
struct task_struct *task;
task = pick_next_pushable_dl_task(rq);
if (task_cpu(next_task) == rq->cpu && task == next_task) {
goto out;
}
if (!task)
goto out;
put_task_struct(next_task);
next_task = task;
goto retry;
}
deactivate_task(rq, next_task, 0);
set_task_cpu(next_task, later_rq->cpu);
activate_task(later_rq, next_task, 0);
ret = 1;
resched_curr(later_rq);
double_unlock_balance(rq, later_rq);
out:
put_task_struct(next_task);
return ret;
}
static void push_dl_tasks(struct rq *rq)
{
while (push_dl_task(rq))
;
}
static void pull_dl_task(struct rq *this_rq)
{
int this_cpu = this_rq->cpu, cpu;
struct task_struct *p;
bool resched = false;
struct rq *src_rq;
u64 dmin = LONG_MAX;
if (likely(!dl_overloaded(this_rq)))
return;
smp_rmb();
for_each_cpu(cpu, this_rq->rd->dlo_mask) {
if (this_cpu == cpu)
continue;
src_rq = cpu_rq(cpu);
if (this_rq->dl.dl_nr_running &&
dl_time_before(this_rq->dl.earliest_dl.curr,
src_rq->dl.earliest_dl.next))
continue;
double_lock_balance(this_rq, src_rq);
if (src_rq->dl.dl_nr_running <= 1)
goto skip;
p = pick_earliest_pushable_dl_task(src_rq, this_cpu);
if (p && dl_time_before(p->dl.deadline, dmin) &&
(!this_rq->dl.dl_nr_running ||
dl_time_before(p->dl.deadline,
this_rq->dl.earliest_dl.curr))) {
WARN_ON(p == src_rq->curr);
WARN_ON(!task_on_rq_queued(p));
if (dl_time_before(p->dl.deadline,
src_rq->curr->dl.deadline))
goto skip;
resched = true;
deactivate_task(src_rq, p, 0);
set_task_cpu(p, this_cpu);
activate_task(this_rq, p, 0);
dmin = p->dl.deadline;
}
skip:
double_unlock_balance(this_rq, src_rq);
}
if (resched)
resched_curr(this_rq);
}
static void task_woken_dl(struct rq *rq, struct task_struct *p)
{
if (!task_running(rq, p) &&
!test_tsk_need_resched(rq->curr) &&
p->nr_cpus_allowed > 1 &&
dl_task(rq->curr) &&
(rq->curr->nr_cpus_allowed < 2 ||
!dl_entity_preempt(&p->dl, &rq->curr->dl))) {
push_dl_tasks(rq);
}
}
static void set_cpus_allowed_dl(struct task_struct *p,
const struct cpumask *new_mask)
{
struct root_domain *src_rd;
struct rq *rq;
BUG_ON(!dl_task(p));
rq = task_rq(p);
src_rd = rq->rd;
if (!cpumask_intersects(src_rd->span, new_mask)) {
struct dl_bw *src_dl_b;
src_dl_b = dl_bw_of(cpu_of(rq));
raw_spin_lock(&src_dl_b->lock);
__dl_clear(src_dl_b, p->dl.dl_bw);
raw_spin_unlock(&src_dl_b->lock);
}
set_cpus_allowed_common(p, new_mask);
}
static void rq_online_dl(struct rq *rq)
{
if (rq->dl.overloaded)
dl_set_overload(rq);
cpudl_set_freecpu(&rq->rd->cpudl, rq->cpu);
if (rq->dl.dl_nr_running > 0)
cpudl_set(&rq->rd->cpudl, rq->cpu, rq->dl.earliest_dl.curr, 1);
}
static void rq_offline_dl(struct rq *rq)
{
if (rq->dl.overloaded)
dl_clear_overload(rq);
cpudl_set(&rq->rd->cpudl, rq->cpu, 0, 0);
cpudl_clear_freecpu(&rq->rd->cpudl, rq->cpu);
}
void __init init_sched_dl_class(void)
{
unsigned int i;
for_each_possible_cpu(i)
zalloc_cpumask_var_node(&per_cpu(local_cpu_mask_dl, i),
GFP_KERNEL, cpu_to_node(i));
}
static void switched_from_dl(struct rq *rq, struct task_struct *p)
{
if (!start_dl_timer(p))
__dl_clear_params(p);
if (!task_on_rq_queued(p) || rq->dl.dl_nr_running)
return;
queue_pull_task(rq);
}
static void switched_to_dl(struct rq *rq, struct task_struct *p)
{
if (task_on_rq_queued(p) && rq->curr != p) {
#ifdef CONFIG_SMP
if (p->nr_cpus_allowed > 1 && rq->dl.overloaded)
queue_push_tasks(rq);
#else
if (dl_task(rq->curr))
check_preempt_curr_dl(rq, p, 0);
else
resched_curr(rq);
#endif
}
}
static void prio_changed_dl(struct rq *rq, struct task_struct *p,
int oldprio)
{
if (task_on_rq_queued(p) || rq->curr == p) {
#ifdef CONFIG_SMP
if (!rq->dl.overloaded)
queue_pull_task(rq);
if (dl_time_before(rq->dl.earliest_dl.curr, p->dl.deadline))
resched_curr(rq);
#else
resched_curr(rq);
#endif
} else
switched_to_dl(rq, p);
}
void print_dl_stats(struct seq_file *m, int cpu)
{
print_dl_rq(m, cpu, &cpu_rq(cpu)->dl);
}
