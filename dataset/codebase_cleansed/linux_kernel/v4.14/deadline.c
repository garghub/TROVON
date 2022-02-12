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
static inline struct dl_bw *dl_bw_of(int i)
{
RCU_LOCKDEP_WARN(!rcu_read_lock_sched_held(),
"sched RCU must be held");
return &cpu_rq(i)->rd->dl_bw;
}
static inline int dl_bw_cpus(int i)
{
struct root_domain *rd = cpu_rq(i)->rd;
int cpus = 0;
RCU_LOCKDEP_WARN(!rcu_read_lock_sched_held(),
"sched RCU must be held");
for_each_cpu_and(i, rd->span, cpu_active_mask)
cpus++;
return cpus;
}
static inline struct dl_bw *dl_bw_of(int i)
{
return &cpu_rq(i)->dl.dl_bw;
}
static inline int dl_bw_cpus(int i)
{
return 1;
}
static inline
void add_running_bw(u64 dl_bw, struct dl_rq *dl_rq)
{
u64 old = dl_rq->running_bw;
lockdep_assert_held(&(rq_of_dl_rq(dl_rq))->lock);
dl_rq->running_bw += dl_bw;
SCHED_WARN_ON(dl_rq->running_bw < old);
SCHED_WARN_ON(dl_rq->running_bw > dl_rq->this_bw);
}
static inline
void sub_running_bw(u64 dl_bw, struct dl_rq *dl_rq)
{
u64 old = dl_rq->running_bw;
lockdep_assert_held(&(rq_of_dl_rq(dl_rq))->lock);
dl_rq->running_bw -= dl_bw;
SCHED_WARN_ON(dl_rq->running_bw > old);
if (dl_rq->running_bw > old)
dl_rq->running_bw = 0;
}
static inline
void add_rq_bw(u64 dl_bw, struct dl_rq *dl_rq)
{
u64 old = dl_rq->this_bw;
lockdep_assert_held(&(rq_of_dl_rq(dl_rq))->lock);
dl_rq->this_bw += dl_bw;
SCHED_WARN_ON(dl_rq->this_bw < old);
}
static inline
void sub_rq_bw(u64 dl_bw, struct dl_rq *dl_rq)
{
u64 old = dl_rq->this_bw;
lockdep_assert_held(&(rq_of_dl_rq(dl_rq))->lock);
dl_rq->this_bw -= dl_bw;
SCHED_WARN_ON(dl_rq->this_bw > old);
if (dl_rq->this_bw > old)
dl_rq->this_bw = 0;
SCHED_WARN_ON(dl_rq->running_bw > dl_rq->this_bw);
}
void dl_change_utilization(struct task_struct *p, u64 new_bw)
{
struct rq *rq;
if (task_on_rq_queued(p))
return;
rq = task_rq(p);
if (p->dl.dl_non_contending) {
sub_running_bw(p->dl.dl_bw, &rq->dl);
p->dl.dl_non_contending = 0;
if (hrtimer_try_to_cancel(&p->dl.inactive_timer) == 1)
put_task_struct(p);
}
sub_rq_bw(p->dl.dl_bw, &rq->dl);
add_rq_bw(new_bw, &rq->dl);
}
static void task_non_contending(struct task_struct *p)
{
struct sched_dl_entity *dl_se = &p->dl;
struct hrtimer *timer = &dl_se->inactive_timer;
struct dl_rq *dl_rq = dl_rq_of_se(dl_se);
struct rq *rq = rq_of_dl_rq(dl_rq);
s64 zerolag_time;
if (dl_se->dl_runtime == 0)
return;
WARN_ON(hrtimer_active(&dl_se->inactive_timer));
WARN_ON(dl_se->dl_non_contending);
zerolag_time = dl_se->deadline -
div64_long((dl_se->runtime * dl_se->dl_period),
dl_se->dl_runtime);
zerolag_time -= rq_clock(rq);
if (zerolag_time < 0) {
if (dl_task(p))
sub_running_bw(dl_se->dl_bw, dl_rq);
if (!dl_task(p) || p->state == TASK_DEAD) {
struct dl_bw *dl_b = dl_bw_of(task_cpu(p));
if (p->state == TASK_DEAD)
sub_rq_bw(p->dl.dl_bw, &rq->dl);
raw_spin_lock(&dl_b->lock);
__dl_clear(dl_b, p->dl.dl_bw, dl_bw_cpus(task_cpu(p)));
__dl_clear_params(p);
raw_spin_unlock(&dl_b->lock);
}
return;
}
dl_se->dl_non_contending = 1;
get_task_struct(p);
hrtimer_start(timer, ns_to_ktime(zerolag_time), HRTIMER_MODE_REL);
}
static void task_contending(struct sched_dl_entity *dl_se, int flags)
{
struct dl_rq *dl_rq = dl_rq_of_se(dl_se);
if (dl_se->dl_runtime == 0)
return;
if (flags & ENQUEUE_MIGRATED)
add_rq_bw(dl_se->dl_bw, dl_rq);
if (dl_se->dl_non_contending) {
dl_se->dl_non_contending = 0;
if (hrtimer_try_to_cancel(&dl_se->inactive_timer) == 1)
put_task_struct(dl_task_of(dl_se));
} else {
add_running_bw(dl_se->dl_bw, dl_rq);
}
}
static inline int is_leftmost(struct task_struct *p, struct dl_rq *dl_rq)
{
struct sched_dl_entity *dl_se = &p->dl;
return dl_rq->root.rb_leftmost == &dl_se->rb_node;
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
dl_rq->root = RB_ROOT_CACHED;
#ifdef CONFIG_SMP
dl_rq->earliest_dl.curr = dl_rq->earliest_dl.next = 0;
dl_rq->dl_nr_migratory = 0;
dl_rq->overloaded = 0;
dl_rq->pushable_dl_tasks_root = RB_ROOT_CACHED;
#else
init_dl_bw(&dl_rq->dl_bw);
#endif
dl_rq->running_bw = 0;
dl_rq->this_bw = 0;
init_dl_rq_bw_ratio(dl_rq);
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
struct rb_node **link = &dl_rq->pushable_dl_tasks_root.rb_root.rb_node;
struct rb_node *parent = NULL;
struct task_struct *entry;
bool leftmost = true;
BUG_ON(!RB_EMPTY_NODE(&p->pushable_dl_tasks));
while (*link) {
parent = *link;
entry = rb_entry(parent, struct task_struct,
pushable_dl_tasks);
if (dl_entity_preempt(&p->dl, &entry->dl))
link = &parent->rb_left;
else {
link = &parent->rb_right;
leftmost = false;
}
}
if (leftmost)
dl_rq->earliest_dl.next = p->dl.deadline;
rb_link_node(&p->pushable_dl_tasks, parent, link);
rb_insert_color_cached(&p->pushable_dl_tasks,
&dl_rq->pushable_dl_tasks_root, leftmost);
}
static void dequeue_pushable_dl_task(struct rq *rq, struct task_struct *p)
{
struct dl_rq *dl_rq = &rq->dl;
if (RB_EMPTY_NODE(&p->pushable_dl_tasks))
return;
if (dl_rq->pushable_dl_tasks_root.rb_leftmost == &p->pushable_dl_tasks) {
struct rb_node *next_node;
next_node = rb_next(&p->pushable_dl_tasks);
if (next_node) {
dl_rq->earliest_dl.next = rb_entry(next_node,
struct task_struct, pushable_dl_tasks)->dl.deadline;
}
}
rb_erase_cached(&p->pushable_dl_tasks, &dl_rq->pushable_dl_tasks_root);
RB_CLEAR_NODE(&p->pushable_dl_tasks);
}
static inline int has_pushable_dl_tasks(struct rq *rq)
{
return !RB_EMPTY_ROOT(&rq->dl.pushable_dl_tasks_root.rb_root);
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
later_rq = find_lock_later_rq(p, rq);
if (!later_rq) {
int cpu;
cpu = cpumask_any_and(cpu_active_mask, &p->cpus_allowed);
if (cpu >= nr_cpu_ids) {
BUG_ON(dl_bandwidth_enabled());
cpu = cpumask_any(cpu_active_mask);
}
later_rq = cpu_rq(cpu);
double_lock_balance(rq, later_rq);
}
set_task_cpu(p, later_rq->cpu);
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
static inline void setup_new_dl_entity(struct sched_dl_entity *dl_se)
{
struct dl_rq *dl_rq = dl_rq_of_se(dl_se);
struct rq *rq = rq_of_dl_rq(dl_rq);
WARN_ON(dl_se->dl_boosted);
WARN_ON(dl_time_before(rq_clock(rq), dl_se->deadline));
if (dl_se->dl_throttled)
return;
dl_se->deadline = rq_clock(rq) + dl_se->dl_deadline;
dl_se->runtime = dl_se->dl_runtime;
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
if (dl_se->dl_yielded && dl_se->runtime > 0)
dl_se->runtime = 0;
while (dl_se->runtime <= 0) {
dl_se->deadline += pi_se->dl_period;
dl_se->runtime += pi_se->dl_runtime;
}
if (dl_time_before(dl_se->deadline, rq_clock(rq))) {
printk_deferred_once("sched: DL replenish lagged too much\n");
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
left = (pi_se->dl_deadline >> DL_SCALE) * (dl_se->runtime >> DL_SCALE);
right = ((dl_se->deadline - t) >> DL_SCALE) *
(pi_se->dl_runtime >> DL_SCALE);
return dl_time_before(right, left);
}
static void
update_dl_revised_wakeup(struct sched_dl_entity *dl_se, struct rq *rq)
{
u64 laxity = dl_se->deadline - rq_clock(rq);
WARN_ON(dl_time_before(dl_se->deadline, rq_clock(rq)));
dl_se->runtime = (dl_se->dl_density * laxity) >> BW_SHIFT;
}
static inline bool dl_is_implicit(struct sched_dl_entity *dl_se)
{
return dl_se->dl_deadline == dl_se->dl_period;
}
static void update_dl_entity(struct sched_dl_entity *dl_se,
struct sched_dl_entity *pi_se)
{
struct dl_rq *dl_rq = dl_rq_of_se(dl_se);
struct rq *rq = rq_of_dl_rq(dl_rq);
if (dl_time_before(dl_se->deadline, rq_clock(rq)) ||
dl_entity_overflow(dl_se, pi_se, rq_clock(rq))) {
if (unlikely(!dl_is_implicit(dl_se) &&
!dl_time_before(dl_se->deadline, rq_clock(rq)) &&
!dl_se->dl_boosted)){
update_dl_revised_wakeup(dl_se, rq);
return;
}
dl_se->deadline = rq_clock(rq) + pi_se->dl_deadline;
dl_se->runtime = pi_se->dl_runtime;
}
}
static inline u64 dl_next_period(struct sched_dl_entity *dl_se)
{
return dl_se->deadline - dl_se->dl_deadline + dl_se->dl_period;
}
static int start_dl_timer(struct task_struct *p)
{
struct sched_dl_entity *dl_se = &p->dl;
struct hrtimer *timer = &dl_se->dl_timer;
struct rq *rq = task_rq(p);
ktime_t now, act;
s64 delta;
lockdep_assert_held(&rq->lock);
act = ns_to_ktime(dl_next_period(dl_se));
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
struct rq_flags rf;
struct rq *rq;
rq = task_rq_lock(p, &rf);
if (!dl_task(p))
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
#ifdef CONFIG_SMP
if (unlikely(!rq->online)) {
lockdep_unpin_lock(&rq->lock, rf.cookie);
rq = dl_task_offline_migration(rq, p);
rf.cookie = lockdep_pin_lock(&rq->lock);
update_rq_clock(rq);
}
#endif
enqueue_task_dl(rq, p, ENQUEUE_REPLENISH);
if (dl_task(rq->curr))
check_preempt_curr_dl(rq, p, 0);
else
resched_curr(rq);
#ifdef CONFIG_SMP
if (has_pushable_dl_tasks(rq)) {
rq_unpin_lock(rq, &rf);
push_dl_task(rq);
rq_repin_lock(rq, &rf);
}
#endif
unlock:
task_rq_unlock(rq, p, &rf);
put_task_struct(p);
return HRTIMER_NORESTART;
}
void init_dl_task_timer(struct sched_dl_entity *dl_se)
{
struct hrtimer *timer = &dl_se->dl_timer;
hrtimer_init(timer, CLOCK_MONOTONIC, HRTIMER_MODE_REL);
timer->function = dl_task_timer;
}
static inline void dl_check_constrained_dl(struct sched_dl_entity *dl_se)
{
struct task_struct *p = dl_task_of(dl_se);
struct rq *rq = rq_of_dl_rq(dl_rq_of_se(dl_se));
if (dl_time_before(dl_se->deadline, rq_clock(rq)) &&
dl_time_before(rq_clock(rq), dl_next_period(dl_se))) {
if (unlikely(dl_se->dl_boosted || !start_dl_timer(p)))
return;
dl_se->dl_throttled = 1;
if (dl_se->runtime > 0)
dl_se->runtime = 0;
}
}
static
int dl_runtime_exceeded(struct sched_dl_entity *dl_se)
{
return (dl_se->runtime <= 0);
}
u64 grub_reclaim(u64 delta, struct rq *rq, struct sched_dl_entity *dl_se)
{
u64 u_inact = rq->dl.this_bw - rq->dl.running_bw;
u64 u_act;
u64 u_act_min = (dl_se->dl_bw * rq->dl.bw_ratio) >> RATIO_SHIFT;
if (u_inact + rq->dl.extra_bw > BW_UNIT - u_act_min)
u_act = u_act_min;
else
u_act = BW_UNIT - u_inact - rq->dl.extra_bw;
return (delta * u_act) >> BW_SHIFT;
}
static void update_curr_dl(struct rq *rq)
{
struct task_struct *curr = rq->curr;
struct sched_dl_entity *dl_se = &curr->dl;
u64 delta_exec;
if (!dl_task(curr) || !on_dl_rq(dl_se))
return;
delta_exec = rq_clock_task(rq) - curr->se.exec_start;
if (unlikely((s64)delta_exec <= 0)) {
if (unlikely(dl_se->dl_yielded))
goto throttle;
return;
}
cpufreq_update_util(rq, SCHED_CPUFREQ_DL);
schedstat_set(curr->se.statistics.exec_max,
max(curr->se.statistics.exec_max, delta_exec));
curr->se.sum_exec_runtime += delta_exec;
account_group_exec_runtime(curr, delta_exec);
curr->se.exec_start = rq_clock_task(rq);
cpuacct_charge(curr, delta_exec);
sched_rt_avg_update(rq, delta_exec);
if (unlikely(dl_se->flags & SCHED_FLAG_RECLAIM))
delta_exec = grub_reclaim(delta_exec, rq, &curr->dl);
dl_se->runtime -= delta_exec;
throttle:
if (dl_runtime_exceeded(dl_se) || dl_se->dl_yielded) {
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
static enum hrtimer_restart inactive_task_timer(struct hrtimer *timer)
{
struct sched_dl_entity *dl_se = container_of(timer,
struct sched_dl_entity,
inactive_timer);
struct task_struct *p = dl_task_of(dl_se);
struct rq_flags rf;
struct rq *rq;
rq = task_rq_lock(p, &rf);
if (!dl_task(p) || p->state == TASK_DEAD) {
struct dl_bw *dl_b = dl_bw_of(task_cpu(p));
if (p->state == TASK_DEAD && dl_se->dl_non_contending) {
sub_running_bw(p->dl.dl_bw, dl_rq_of_se(&p->dl));
sub_rq_bw(p->dl.dl_bw, dl_rq_of_se(&p->dl));
dl_se->dl_non_contending = 0;
}
raw_spin_lock(&dl_b->lock);
__dl_clear(dl_b, p->dl.dl_bw, dl_bw_cpus(task_cpu(p)));
raw_spin_unlock(&dl_b->lock);
__dl_clear_params(p);
goto unlock;
}
if (dl_se->dl_non_contending == 0)
goto unlock;
sched_clock_tick();
update_rq_clock(rq);
sub_running_bw(dl_se->dl_bw, &rq->dl);
dl_se->dl_non_contending = 0;
unlock:
task_rq_unlock(rq, p, &rf);
put_task_struct(p);
return HRTIMER_NORESTART;
}
void init_dl_inactive_task_timer(struct sched_dl_entity *dl_se)
{
struct hrtimer *timer = &dl_se->inactive_timer;
hrtimer_init(timer, CLOCK_MONOTONIC, HRTIMER_MODE_REL);
timer->function = inactive_task_timer;
}
static void inc_dl_deadline(struct dl_rq *dl_rq, u64 deadline)
{
struct rq *rq = rq_of_dl_rq(dl_rq);
if (dl_rq->earliest_dl.curr == 0 ||
dl_time_before(deadline, dl_rq->earliest_dl.curr)) {
dl_rq->earliest_dl.curr = deadline;
cpudl_set(&rq->rd->cpudl, rq->cpu, deadline);
}
}
static void dec_dl_deadline(struct dl_rq *dl_rq, u64 deadline)
{
struct rq *rq = rq_of_dl_rq(dl_rq);
if (!dl_rq->dl_nr_running) {
dl_rq->earliest_dl.curr = 0;
dl_rq->earliest_dl.next = 0;
cpudl_clear(&rq->rd->cpudl, rq->cpu);
} else {
struct rb_node *leftmost = dl_rq->root.rb_leftmost;
struct sched_dl_entity *entry;
entry = rb_entry(leftmost, struct sched_dl_entity, rb_node);
dl_rq->earliest_dl.curr = entry->deadline;
cpudl_set(&rq->rd->cpudl, rq->cpu, entry->deadline);
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
struct rb_node **link = &dl_rq->root.rb_root.rb_node;
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
rb_link_node(&dl_se->rb_node, parent, link);
rb_insert_color_cached(&dl_se->rb_node, &dl_rq->root, leftmost);
inc_dl_tasks(dl_se, dl_rq);
}
static void __dequeue_dl_entity(struct sched_dl_entity *dl_se)
{
struct dl_rq *dl_rq = dl_rq_of_se(dl_se);
if (RB_EMPTY_NODE(&dl_se->rb_node))
return;
rb_erase_cached(&dl_se->rb_node, &dl_rq->root);
RB_CLEAR_NODE(&dl_se->rb_node);
dec_dl_tasks(dl_se, dl_rq);
}
static void
enqueue_dl_entity(struct sched_dl_entity *dl_se,
struct sched_dl_entity *pi_se, int flags)
{
BUG_ON(on_dl_rq(dl_se));
if (flags & ENQUEUE_WAKEUP) {
task_contending(dl_se, flags);
update_dl_entity(dl_se, pi_se);
} else if (flags & ENQUEUE_REPLENISH) {
replenish_dl_entity(dl_se, pi_se);
}
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
if (pi_task && dl_prio(pi_task->normal_prio) && p->dl.dl_boosted) {
pi_se = &pi_task->dl;
} else if (!dl_prio(p->normal_prio)) {
BUG_ON(!p->dl.dl_boosted || flags != ENQUEUE_REPLENISH);
return;
}
if (!p->dl.dl_throttled && !dl_is_implicit(&p->dl))
dl_check_constrained_dl(&p->dl);
if (p->on_rq == TASK_ON_RQ_MIGRATING || flags & ENQUEUE_RESTORE) {
add_rq_bw(p->dl.dl_bw, &rq->dl);
add_running_bw(p->dl.dl_bw, &rq->dl);
}
if (p->dl.dl_throttled && !(flags & ENQUEUE_REPLENISH)) {
if (flags & ENQUEUE_WAKEUP)
task_contending(&p->dl, flags);
return;
}
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
if (p->on_rq == TASK_ON_RQ_MIGRATING || flags & DEQUEUE_SAVE) {
sub_running_bw(p->dl.dl_bw, &rq->dl);
sub_rq_bw(p->dl.dl_bw, &rq->dl);
}
if (flags & DEQUEUE_SLEEP)
task_non_contending(p);
}
static void yield_task_dl(struct rq *rq)
{
rq->curr->dl.dl_yielded = 1;
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
static void migrate_task_rq_dl(struct task_struct *p)
{
struct rq *rq;
if (p->state != TASK_WAKING)
return;
rq = task_rq(p);
raw_spin_lock(&rq->lock);
if (p->dl.dl_non_contending) {
sub_running_bw(p->dl.dl_bw, &rq->dl);
p->dl.dl_non_contending = 0;
if (hrtimer_try_to_cancel(&p->dl.inactive_timer) == 1)
put_task_struct(p);
}
sub_rq_bw(p->dl.dl_bw, &rq->dl);
raw_spin_unlock(&rq->lock);
}
static void check_preempt_equal_dl(struct rq *rq, struct task_struct *p)
{
if (rq->curr->nr_cpus_allowed == 1 ||
!cpudl_find(&rq->rd->cpudl, rq->curr, NULL))
return;
if (p->nr_cpus_allowed != 1 &&
cpudl_find(&rq->rd->cpudl, p, NULL))
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
struct rb_node *left = rb_first_cached(&dl_rq->root);
if (!left)
return NULL;
return rb_entry(left, struct sched_dl_entity, rb_node);
}
static struct task_struct *
pick_next_task_dl(struct rq *rq, struct task_struct *prev, struct rq_flags *rf)
{
struct sched_dl_entity *dl_se;
struct task_struct *p;
struct dl_rq *dl_rq;
dl_rq = &rq->dl;
if (need_pull_dl_task(rq, prev)) {
rq_unpin_lock(rq, rf);
pull_dl_task(rq);
rq_repin_lock(rq, rf);
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
static void set_curr_task_dl(struct rq *rq)
{
struct task_struct *p = rq->curr;
p->se.exec_start = rq_clock_task(rq);
dequeue_pushable_dl_task(rq, p);
}
static int pick_dl_task(struct rq *rq, struct task_struct *p, int cpu)
{
if (!task_running(rq, p) &&
cpumask_test_cpu(cpu, &p->cpus_allowed))
return 1;
return 0;
}
static struct task_struct *pick_earliest_pushable_dl_task(struct rq *rq, int cpu)
{
struct rb_node *next_node = rq->dl.pushable_dl_tasks_root.rb_leftmost;
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
int cpu = task_cpu(task);
if (unlikely(!later_mask))
return -1;
if (task->nr_cpus_allowed == 1)
return -1;
if (!cpudl_find(&task_rq(task)->rd->cpudl, task, later_mask))
return -1;
if (cpumask_test_cpu(cpu, later_mask))
return cpu;
if (!cpumask_test_cpu(this_cpu, later_mask))
this_cpu = -1;
rcu_read_lock();
for_each_domain(cpu, sd) {
if (sd->flags & SD_WAKE_AFFINE) {
int best_cpu;
if (this_cpu != -1 &&
cpumask_test_cpu(this_cpu, sched_domain_span(sd))) {
rcu_read_unlock();
return this_cpu;
}
best_cpu = cpumask_first_and(later_mask,
sched_domain_span(sd));
if (best_cpu < nr_cpu_ids) {
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
!cpumask_test_cpu(later_rq->cpu, &task->cpus_allowed) ||
task_running(rq, task) ||
!dl_task(task) ||
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
p = rb_entry(rq->dl.pushable_dl_tasks_root.rb_leftmost,
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
if (task == next_task) {
goto out;
}
if (!task)
goto out;
put_task_struct(next_task);
next_task = task;
goto retry;
}
deactivate_task(rq, next_task, 0);
sub_running_bw(next_task->dl.dl_bw, &rq->dl);
sub_rq_bw(next_task->dl.dl_bw, &rq->dl);
set_task_cpu(next_task, later_rq->cpu);
add_rq_bw(next_task->dl.dl_bw, &later_rq->dl);
add_running_bw(next_task->dl.dl_bw, &later_rq->dl);
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
sub_running_bw(p->dl.dl_bw, &src_rq->dl);
sub_rq_bw(p->dl.dl_bw, &src_rq->dl);
set_task_cpu(p, this_cpu);
add_rq_bw(p->dl.dl_bw, &this_rq->dl);
add_running_bw(p->dl.dl_bw, &this_rq->dl);
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
__dl_clear(src_dl_b, p->dl.dl_bw, dl_bw_cpus(task_cpu(p)));
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
cpudl_set(&rq->rd->cpudl, rq->cpu, rq->dl.earliest_dl.curr);
}
static void rq_offline_dl(struct rq *rq)
{
if (rq->dl.overloaded)
dl_clear_overload(rq);
cpudl_clear(&rq->rd->cpudl, rq->cpu);
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
if (task_on_rq_queued(p) && p->dl.dl_runtime)
task_non_contending(p);
if (!task_on_rq_queued(p))
sub_rq_bw(p->dl.dl_bw, &rq->dl);
if (p->dl.dl_non_contending)
p->dl.dl_non_contending = 0;
if (!task_on_rq_queued(p) || rq->dl.dl_nr_running)
return;
queue_pull_task(rq);
}
static void switched_to_dl(struct rq *rq, struct task_struct *p)
{
if (hrtimer_try_to_cancel(&p->dl.inactive_timer) == 1)
put_task_struct(p);
if (!task_on_rq_queued(p)) {
add_rq_bw(p->dl.dl_bw, &rq->dl);
return;
}
if (dl_time_before(p->dl.deadline, rq_clock(rq)))
setup_new_dl_entity(&p->dl);
if (rq->curr != p) {
#ifdef CONFIG_SMP
if (p->nr_cpus_allowed > 1 && rq->dl.overloaded)
queue_push_tasks(rq);
#endif
if (dl_task(rq->curr))
check_preempt_curr_dl(rq, p, 0);
else
resched_curr(rq);
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
}
}
int sched_dl_global_validate(void)
{
u64 runtime = global_rt_runtime();
u64 period = global_rt_period();
u64 new_bw = to_ratio(period, runtime);
struct dl_bw *dl_b;
int cpu, ret = 0;
unsigned long flags;
for_each_possible_cpu(cpu) {
rcu_read_lock_sched();
dl_b = dl_bw_of(cpu);
raw_spin_lock_irqsave(&dl_b->lock, flags);
if (new_bw < dl_b->total_bw)
ret = -EBUSY;
raw_spin_unlock_irqrestore(&dl_b->lock, flags);
rcu_read_unlock_sched();
if (ret)
break;
}
return ret;
}
void init_dl_rq_bw_ratio(struct dl_rq *dl_rq)
{
if (global_rt_runtime() == RUNTIME_INF) {
dl_rq->bw_ratio = 1 << RATIO_SHIFT;
dl_rq->extra_bw = 1 << BW_SHIFT;
} else {
dl_rq->bw_ratio = to_ratio(global_rt_runtime(),
global_rt_period()) >> (BW_SHIFT - RATIO_SHIFT);
dl_rq->extra_bw = to_ratio(global_rt_period(),
global_rt_runtime());
}
}
void sched_dl_do_global(void)
{
u64 new_bw = -1;
struct dl_bw *dl_b;
int cpu;
unsigned long flags;
def_dl_bandwidth.dl_period = global_rt_period();
def_dl_bandwidth.dl_runtime = global_rt_runtime();
if (global_rt_runtime() != RUNTIME_INF)
new_bw = to_ratio(global_rt_period(), global_rt_runtime());
for_each_possible_cpu(cpu) {
rcu_read_lock_sched();
dl_b = dl_bw_of(cpu);
raw_spin_lock_irqsave(&dl_b->lock, flags);
dl_b->bw = new_bw;
raw_spin_unlock_irqrestore(&dl_b->lock, flags);
rcu_read_unlock_sched();
init_dl_rq_bw_ratio(&cpu_rq(cpu)->dl);
}
}
int sched_dl_overflow(struct task_struct *p, int policy,
const struct sched_attr *attr)
{
struct dl_bw *dl_b = dl_bw_of(task_cpu(p));
u64 period = attr->sched_period ?: attr->sched_deadline;
u64 runtime = attr->sched_runtime;
u64 new_bw = dl_policy(policy) ? to_ratio(period, runtime) : 0;
int cpus, err = -1;
if (new_bw == p->dl.dl_bw && task_has_dl_policy(p))
return 0;
raw_spin_lock(&dl_b->lock);
cpus = dl_bw_cpus(task_cpu(p));
if (dl_policy(policy) && !task_has_dl_policy(p) &&
!__dl_overflow(dl_b, cpus, 0, new_bw)) {
if (hrtimer_active(&p->dl.inactive_timer))
__dl_clear(dl_b, p->dl.dl_bw, cpus);
__dl_add(dl_b, new_bw, cpus);
err = 0;
} else if (dl_policy(policy) && task_has_dl_policy(p) &&
!__dl_overflow(dl_b, cpus, p->dl.dl_bw, new_bw)) {
__dl_clear(dl_b, p->dl.dl_bw, cpus);
__dl_add(dl_b, new_bw, cpus);
dl_change_utilization(p, new_bw);
err = 0;
} else if (!dl_policy(policy) && task_has_dl_policy(p)) {
err = 0;
}
raw_spin_unlock(&dl_b->lock);
return err;
}
void __setparam_dl(struct task_struct *p, const struct sched_attr *attr)
{
struct sched_dl_entity *dl_se = &p->dl;
dl_se->dl_runtime = attr->sched_runtime;
dl_se->dl_deadline = attr->sched_deadline;
dl_se->dl_period = attr->sched_period ?: dl_se->dl_deadline;
dl_se->flags = attr->sched_flags;
dl_se->dl_bw = to_ratio(dl_se->dl_period, dl_se->dl_runtime);
dl_se->dl_density = to_ratio(dl_se->dl_deadline, dl_se->dl_runtime);
}
void __getparam_dl(struct task_struct *p, struct sched_attr *attr)
{
struct sched_dl_entity *dl_se = &p->dl;
attr->sched_priority = p->rt_priority;
attr->sched_runtime = dl_se->dl_runtime;
attr->sched_deadline = dl_se->dl_deadline;
attr->sched_period = dl_se->dl_period;
attr->sched_flags = dl_se->flags;
}
bool __checkparam_dl(const struct sched_attr *attr)
{
if (attr->sched_deadline == 0)
return false;
if (attr->sched_runtime < (1ULL << DL_SCALE))
return false;
if (attr->sched_deadline & (1ULL << 63) ||
attr->sched_period & (1ULL << 63))
return false;
if ((attr->sched_period != 0 &&
attr->sched_period < attr->sched_deadline) ||
attr->sched_deadline < attr->sched_runtime)
return false;
return true;
}
void __dl_clear_params(struct task_struct *p)
{
struct sched_dl_entity *dl_se = &p->dl;
dl_se->dl_runtime = 0;
dl_se->dl_deadline = 0;
dl_se->dl_period = 0;
dl_se->flags = 0;
dl_se->dl_bw = 0;
dl_se->dl_density = 0;
dl_se->dl_throttled = 0;
dl_se->dl_yielded = 0;
dl_se->dl_non_contending = 0;
}
bool dl_param_changed(struct task_struct *p, const struct sched_attr *attr)
{
struct sched_dl_entity *dl_se = &p->dl;
if (dl_se->dl_runtime != attr->sched_runtime ||
dl_se->dl_deadline != attr->sched_deadline ||
dl_se->dl_period != attr->sched_period ||
dl_se->flags != attr->sched_flags)
return true;
return false;
}
int dl_task_can_attach(struct task_struct *p, const struct cpumask *cs_cpus_allowed)
{
unsigned int dest_cpu = cpumask_any_and(cpu_active_mask,
cs_cpus_allowed);
struct dl_bw *dl_b;
bool overflow;
int cpus, ret;
unsigned long flags;
rcu_read_lock_sched();
dl_b = dl_bw_of(dest_cpu);
raw_spin_lock_irqsave(&dl_b->lock, flags);
cpus = dl_bw_cpus(dest_cpu);
overflow = __dl_overflow(dl_b, cpus, 0, p->dl.dl_bw);
if (overflow)
ret = -EBUSY;
else {
__dl_add(dl_b, p->dl.dl_bw, cpus);
ret = 0;
}
raw_spin_unlock_irqrestore(&dl_b->lock, flags);
rcu_read_unlock_sched();
return ret;
}
int dl_cpuset_cpumask_can_shrink(const struct cpumask *cur,
const struct cpumask *trial)
{
int ret = 1, trial_cpus;
struct dl_bw *cur_dl_b;
unsigned long flags;
rcu_read_lock_sched();
cur_dl_b = dl_bw_of(cpumask_any(cur));
trial_cpus = cpumask_weight(trial);
raw_spin_lock_irqsave(&cur_dl_b->lock, flags);
if (cur_dl_b->bw != -1 &&
cur_dl_b->bw * trial_cpus < cur_dl_b->total_bw)
ret = 0;
raw_spin_unlock_irqrestore(&cur_dl_b->lock, flags);
rcu_read_unlock_sched();
return ret;
}
bool dl_cpu_busy(unsigned int cpu)
{
unsigned long flags;
struct dl_bw *dl_b;
bool overflow;
int cpus;
rcu_read_lock_sched();
dl_b = dl_bw_of(cpu);
raw_spin_lock_irqsave(&dl_b->lock, flags);
cpus = dl_bw_cpus(cpu);
overflow = __dl_overflow(dl_b, cpus, 0, 0);
raw_spin_unlock_irqrestore(&dl_b->lock, flags);
rcu_read_unlock_sched();
return overflow;
}
void print_dl_stats(struct seq_file *m, int cpu)
{
print_dl_rq(m, cpu, &cpu_rq(cpu)->dl);
}
