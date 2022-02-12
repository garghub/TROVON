static enum hrtimer_restart sched_rt_period_timer(struct hrtimer *timer)
{
struct rt_bandwidth *rt_b =
container_of(timer, struct rt_bandwidth, rt_period_timer);
ktime_t now;
int overrun;
int idle = 0;
for (;;) {
now = hrtimer_cb_get_time(timer);
overrun = hrtimer_forward(timer, now, rt_b->rt_period);
if (!overrun)
break;
idle = do_sched_rt_period_timer(rt_b, overrun);
}
return idle ? HRTIMER_NORESTART : HRTIMER_RESTART;
}
void init_rt_bandwidth(struct rt_bandwidth *rt_b, u64 period, u64 runtime)
{
rt_b->rt_period = ns_to_ktime(period);
rt_b->rt_runtime = runtime;
raw_spin_lock_init(&rt_b->rt_runtime_lock);
hrtimer_init(&rt_b->rt_period_timer,
CLOCK_MONOTONIC, HRTIMER_MODE_REL);
rt_b->rt_period_timer.function = sched_rt_period_timer;
}
static void start_rt_bandwidth(struct rt_bandwidth *rt_b)
{
if (!rt_bandwidth_enabled() || rt_b->rt_runtime == RUNTIME_INF)
return;
if (hrtimer_active(&rt_b->rt_period_timer))
return;
raw_spin_lock(&rt_b->rt_runtime_lock);
start_bandwidth_timer(&rt_b->rt_period_timer, rt_b->rt_period);
raw_spin_unlock(&rt_b->rt_runtime_lock);
}
void init_rt_rq(struct rt_rq *rt_rq, struct rq *rq)
{
struct rt_prio_array *array;
int i;
array = &rt_rq->active;
for (i = 0; i < MAX_RT_PRIO; i++) {
INIT_LIST_HEAD(array->queue + i);
__clear_bit(i, array->bitmap);
}
__set_bit(MAX_RT_PRIO, array->bitmap);
#if defined CONFIG_SMP
rt_rq->highest_prio.curr = MAX_RT_PRIO;
rt_rq->highest_prio.next = MAX_RT_PRIO;
rt_rq->rt_nr_migratory = 0;
rt_rq->overloaded = 0;
plist_head_init(&rt_rq->pushable_tasks);
#endif
rt_rq->rt_queued = 0;
rt_rq->rt_time = 0;
rt_rq->rt_throttled = 0;
rt_rq->rt_runtime = 0;
raw_spin_lock_init(&rt_rq->rt_runtime_lock);
}
static void destroy_rt_bandwidth(struct rt_bandwidth *rt_b)
{
hrtimer_cancel(&rt_b->rt_period_timer);
}
static inline struct task_struct *rt_task_of(struct sched_rt_entity *rt_se)
{
#ifdef CONFIG_SCHED_DEBUG
WARN_ON_ONCE(!rt_entity_is_task(rt_se));
#endif
return container_of(rt_se, struct task_struct, rt);
}
static inline struct rq *rq_of_rt_rq(struct rt_rq *rt_rq)
{
return rt_rq->rq;
}
static inline struct rt_rq *rt_rq_of_se(struct sched_rt_entity *rt_se)
{
return rt_se->rt_rq;
}
static inline struct rq *rq_of_rt_se(struct sched_rt_entity *rt_se)
{
struct rt_rq *rt_rq = rt_se->rt_rq;
return rt_rq->rq;
}
void free_rt_sched_group(struct task_group *tg)
{
int i;
if (tg->rt_se)
destroy_rt_bandwidth(&tg->rt_bandwidth);
for_each_possible_cpu(i) {
if (tg->rt_rq)
kfree(tg->rt_rq[i]);
if (tg->rt_se)
kfree(tg->rt_se[i]);
}
kfree(tg->rt_rq);
kfree(tg->rt_se);
}
void init_tg_rt_entry(struct task_group *tg, struct rt_rq *rt_rq,
struct sched_rt_entity *rt_se, int cpu,
struct sched_rt_entity *parent)
{
struct rq *rq = cpu_rq(cpu);
rt_rq->highest_prio.curr = MAX_RT_PRIO;
rt_rq->rt_nr_boosted = 0;
rt_rq->rq = rq;
rt_rq->tg = tg;
tg->rt_rq[cpu] = rt_rq;
tg->rt_se[cpu] = rt_se;
if (!rt_se)
return;
if (!parent)
rt_se->rt_rq = &rq->rt;
else
rt_se->rt_rq = parent->my_q;
rt_se->my_q = rt_rq;
rt_se->parent = parent;
INIT_LIST_HEAD(&rt_se->run_list);
}
int alloc_rt_sched_group(struct task_group *tg, struct task_group *parent)
{
struct rt_rq *rt_rq;
struct sched_rt_entity *rt_se;
int i;
tg->rt_rq = kzalloc(sizeof(rt_rq) * nr_cpu_ids, GFP_KERNEL);
if (!tg->rt_rq)
goto err;
tg->rt_se = kzalloc(sizeof(rt_se) * nr_cpu_ids, GFP_KERNEL);
if (!tg->rt_se)
goto err;
init_rt_bandwidth(&tg->rt_bandwidth,
ktime_to_ns(def_rt_bandwidth.rt_period), 0);
for_each_possible_cpu(i) {
rt_rq = kzalloc_node(sizeof(struct rt_rq),
GFP_KERNEL, cpu_to_node(i));
if (!rt_rq)
goto err;
rt_se = kzalloc_node(sizeof(struct sched_rt_entity),
GFP_KERNEL, cpu_to_node(i));
if (!rt_se)
goto err_free_rq;
init_rt_rq(rt_rq, cpu_rq(i));
rt_rq->rt_runtime = tg->rt_bandwidth.rt_runtime;
init_tg_rt_entry(tg, rt_rq, rt_se, i, parent->rt_se[i]);
}
return 1;
err_free_rq:
kfree(rt_rq);
err:
return 0;
}
static inline struct task_struct *rt_task_of(struct sched_rt_entity *rt_se)
{
return container_of(rt_se, struct task_struct, rt);
}
static inline struct rq *rq_of_rt_rq(struct rt_rq *rt_rq)
{
return container_of(rt_rq, struct rq, rt);
}
static inline struct rq *rq_of_rt_se(struct sched_rt_entity *rt_se)
{
struct task_struct *p = rt_task_of(rt_se);
return task_rq(p);
}
static inline struct rt_rq *rt_rq_of_se(struct sched_rt_entity *rt_se)
{
struct rq *rq = rq_of_rt_se(rt_se);
return &rq->rt;
}
void free_rt_sched_group(struct task_group *tg) { }
int alloc_rt_sched_group(struct task_group *tg, struct task_group *parent)
{
return 1;
}
static inline bool need_pull_rt_task(struct rq *rq, struct task_struct *prev)
{
return rq->rt.highest_prio.curr > prev->prio;
}
static inline int rt_overloaded(struct rq *rq)
{
return atomic_read(&rq->rd->rto_count);
}
static inline void rt_set_overload(struct rq *rq)
{
if (!rq->online)
return;
cpumask_set_cpu(rq->cpu, rq->rd->rto_mask);
smp_wmb();
atomic_inc(&rq->rd->rto_count);
}
static inline void rt_clear_overload(struct rq *rq)
{
if (!rq->online)
return;
atomic_dec(&rq->rd->rto_count);
cpumask_clear_cpu(rq->cpu, rq->rd->rto_mask);
}
static void update_rt_migration(struct rt_rq *rt_rq)
{
if (rt_rq->rt_nr_migratory && rt_rq->rt_nr_total > 1) {
if (!rt_rq->overloaded) {
rt_set_overload(rq_of_rt_rq(rt_rq));
rt_rq->overloaded = 1;
}
} else if (rt_rq->overloaded) {
rt_clear_overload(rq_of_rt_rq(rt_rq));
rt_rq->overloaded = 0;
}
}
static void inc_rt_migration(struct sched_rt_entity *rt_se, struct rt_rq *rt_rq)
{
struct task_struct *p;
if (!rt_entity_is_task(rt_se))
return;
p = rt_task_of(rt_se);
rt_rq = &rq_of_rt_rq(rt_rq)->rt;
rt_rq->rt_nr_total++;
if (p->nr_cpus_allowed > 1)
rt_rq->rt_nr_migratory++;
update_rt_migration(rt_rq);
}
static void dec_rt_migration(struct sched_rt_entity *rt_se, struct rt_rq *rt_rq)
{
struct task_struct *p;
if (!rt_entity_is_task(rt_se))
return;
p = rt_task_of(rt_se);
rt_rq = &rq_of_rt_rq(rt_rq)->rt;
rt_rq->rt_nr_total--;
if (p->nr_cpus_allowed > 1)
rt_rq->rt_nr_migratory--;
update_rt_migration(rt_rq);
}
static inline int has_pushable_tasks(struct rq *rq)
{
return !plist_head_empty(&rq->rt.pushable_tasks);
}
static inline void set_post_schedule(struct rq *rq)
{
rq->post_schedule = has_pushable_tasks(rq);
}
static void enqueue_pushable_task(struct rq *rq, struct task_struct *p)
{
plist_del(&p->pushable_tasks, &rq->rt.pushable_tasks);
plist_node_init(&p->pushable_tasks, p->prio);
plist_add(&p->pushable_tasks, &rq->rt.pushable_tasks);
if (p->prio < rq->rt.highest_prio.next)
rq->rt.highest_prio.next = p->prio;
}
static void dequeue_pushable_task(struct rq *rq, struct task_struct *p)
{
plist_del(&p->pushable_tasks, &rq->rt.pushable_tasks);
if (has_pushable_tasks(rq)) {
p = plist_first_entry(&rq->rt.pushable_tasks,
struct task_struct, pushable_tasks);
rq->rt.highest_prio.next = p->prio;
} else
rq->rt.highest_prio.next = MAX_RT_PRIO;
}
static inline void enqueue_pushable_task(struct rq *rq, struct task_struct *p)
{
}
static inline void dequeue_pushable_task(struct rq *rq, struct task_struct *p)
{
}
static inline
void inc_rt_migration(struct sched_rt_entity *rt_se, struct rt_rq *rt_rq)
{
}
static inline
void dec_rt_migration(struct sched_rt_entity *rt_se, struct rt_rq *rt_rq)
{
}
static inline bool need_pull_rt_task(struct rq *rq, struct task_struct *prev)
{
return false;
}
static inline int pull_rt_task(struct rq *this_rq)
{
return 0;
}
static inline void set_post_schedule(struct rq *rq)
{
}
static inline int on_rt_rq(struct sched_rt_entity *rt_se)
{
return !list_empty(&rt_se->run_list);
}
static inline u64 sched_rt_runtime(struct rt_rq *rt_rq)
{
if (!rt_rq->tg)
return RUNTIME_INF;
return rt_rq->rt_runtime;
}
static inline u64 sched_rt_period(struct rt_rq *rt_rq)
{
return ktime_to_ns(rt_rq->tg->rt_bandwidth.rt_period);
}
static inline struct task_group *next_task_group(struct task_group *tg)
{
do {
tg = list_entry_rcu(tg->list.next,
typeof(struct task_group), list);
} while (&tg->list != &task_groups && task_group_is_autogroup(tg));
if (&tg->list == &task_groups)
tg = NULL;
return tg;
}
static inline struct rt_rq *group_rt_rq(struct sched_rt_entity *rt_se)
{
return rt_se->my_q;
}
static void sched_rt_rq_enqueue(struct rt_rq *rt_rq)
{
struct task_struct *curr = rq_of_rt_rq(rt_rq)->curr;
struct rq *rq = rq_of_rt_rq(rt_rq);
struct sched_rt_entity *rt_se;
int cpu = cpu_of(rq);
rt_se = rt_rq->tg->rt_se[cpu];
if (rt_rq->rt_nr_running) {
if (!rt_se)
enqueue_top_rt_rq(rt_rq);
else if (!on_rt_rq(rt_se))
enqueue_rt_entity(rt_se, false);
if (rt_rq->highest_prio.curr < curr->prio)
resched_curr(rq);
}
}
static void sched_rt_rq_dequeue(struct rt_rq *rt_rq)
{
struct sched_rt_entity *rt_se;
int cpu = cpu_of(rq_of_rt_rq(rt_rq));
rt_se = rt_rq->tg->rt_se[cpu];
if (!rt_se)
dequeue_top_rt_rq(rt_rq);
else if (on_rt_rq(rt_se))
dequeue_rt_entity(rt_se);
}
static inline int rt_rq_throttled(struct rt_rq *rt_rq)
{
return rt_rq->rt_throttled && !rt_rq->rt_nr_boosted;
}
static int rt_se_boosted(struct sched_rt_entity *rt_se)
{
struct rt_rq *rt_rq = group_rt_rq(rt_se);
struct task_struct *p;
if (rt_rq)
return !!rt_rq->rt_nr_boosted;
p = rt_task_of(rt_se);
return p->prio != p->normal_prio;
}
static inline const struct cpumask *sched_rt_period_mask(void)
{
return this_rq()->rd->span;
}
static inline const struct cpumask *sched_rt_period_mask(void)
{
return cpu_online_mask;
}
static inline
struct rt_rq *sched_rt_period_rt_rq(struct rt_bandwidth *rt_b, int cpu)
{
return container_of(rt_b, struct task_group, rt_bandwidth)->rt_rq[cpu];
}
static inline struct rt_bandwidth *sched_rt_bandwidth(struct rt_rq *rt_rq)
{
return &rt_rq->tg->rt_bandwidth;
}
static inline u64 sched_rt_runtime(struct rt_rq *rt_rq)
{
return rt_rq->rt_runtime;
}
static inline u64 sched_rt_period(struct rt_rq *rt_rq)
{
return ktime_to_ns(def_rt_bandwidth.rt_period);
}
static inline struct rt_rq *group_rt_rq(struct sched_rt_entity *rt_se)
{
return NULL;
}
static inline void sched_rt_rq_enqueue(struct rt_rq *rt_rq)
{
struct rq *rq = rq_of_rt_rq(rt_rq);
if (!rt_rq->rt_nr_running)
return;
enqueue_top_rt_rq(rt_rq);
resched_curr(rq);
}
static inline void sched_rt_rq_dequeue(struct rt_rq *rt_rq)
{
dequeue_top_rt_rq(rt_rq);
}
static inline int rt_rq_throttled(struct rt_rq *rt_rq)
{
return rt_rq->rt_throttled;
}
static inline const struct cpumask *sched_rt_period_mask(void)
{
return cpu_online_mask;
}
static inline
struct rt_rq *sched_rt_period_rt_rq(struct rt_bandwidth *rt_b, int cpu)
{
return &cpu_rq(cpu)->rt;
}
static inline struct rt_bandwidth *sched_rt_bandwidth(struct rt_rq *rt_rq)
{
return &def_rt_bandwidth;
}
bool sched_rt_bandwidth_account(struct rt_rq *rt_rq)
{
struct rt_bandwidth *rt_b = sched_rt_bandwidth(rt_rq);
return (hrtimer_active(&rt_b->rt_period_timer) ||
rt_rq->rt_time < rt_b->rt_runtime);
}
static int do_balance_runtime(struct rt_rq *rt_rq)
{
struct rt_bandwidth *rt_b = sched_rt_bandwidth(rt_rq);
struct root_domain *rd = rq_of_rt_rq(rt_rq)->rd;
int i, weight, more = 0;
u64 rt_period;
weight = cpumask_weight(rd->span);
raw_spin_lock(&rt_b->rt_runtime_lock);
rt_period = ktime_to_ns(rt_b->rt_period);
for_each_cpu(i, rd->span) {
struct rt_rq *iter = sched_rt_period_rt_rq(rt_b, i);
s64 diff;
if (iter == rt_rq)
continue;
raw_spin_lock(&iter->rt_runtime_lock);
if (iter->rt_runtime == RUNTIME_INF)
goto next;
diff = iter->rt_runtime - iter->rt_time;
if (diff > 0) {
diff = div_u64((u64)diff, weight);
if (rt_rq->rt_runtime + diff > rt_period)
diff = rt_period - rt_rq->rt_runtime;
iter->rt_runtime -= diff;
rt_rq->rt_runtime += diff;
more = 1;
if (rt_rq->rt_runtime == rt_period) {
raw_spin_unlock(&iter->rt_runtime_lock);
break;
}
}
next:
raw_spin_unlock(&iter->rt_runtime_lock);
}
raw_spin_unlock(&rt_b->rt_runtime_lock);
return more;
}
static void __disable_runtime(struct rq *rq)
{
struct root_domain *rd = rq->rd;
rt_rq_iter_t iter;
struct rt_rq *rt_rq;
if (unlikely(!scheduler_running))
return;
for_each_rt_rq(rt_rq, iter, rq) {
struct rt_bandwidth *rt_b = sched_rt_bandwidth(rt_rq);
s64 want;
int i;
raw_spin_lock(&rt_b->rt_runtime_lock);
raw_spin_lock(&rt_rq->rt_runtime_lock);
if (rt_rq->rt_runtime == RUNTIME_INF ||
rt_rq->rt_runtime == rt_b->rt_runtime)
goto balanced;
raw_spin_unlock(&rt_rq->rt_runtime_lock);
want = rt_b->rt_runtime - rt_rq->rt_runtime;
for_each_cpu(i, rd->span) {
struct rt_rq *iter = sched_rt_period_rt_rq(rt_b, i);
s64 diff;
if (iter == rt_rq || iter->rt_runtime == RUNTIME_INF)
continue;
raw_spin_lock(&iter->rt_runtime_lock);
if (want > 0) {
diff = min_t(s64, iter->rt_runtime, want);
iter->rt_runtime -= diff;
want -= diff;
} else {
iter->rt_runtime -= want;
want -= want;
}
raw_spin_unlock(&iter->rt_runtime_lock);
if (!want)
break;
}
raw_spin_lock(&rt_rq->rt_runtime_lock);
BUG_ON(want);
balanced:
rt_rq->rt_runtime = RUNTIME_INF;
rt_rq->rt_throttled = 0;
raw_spin_unlock(&rt_rq->rt_runtime_lock);
raw_spin_unlock(&rt_b->rt_runtime_lock);
sched_rt_rq_enqueue(rt_rq);
}
}
static void __enable_runtime(struct rq *rq)
{
rt_rq_iter_t iter;
struct rt_rq *rt_rq;
if (unlikely(!scheduler_running))
return;
for_each_rt_rq(rt_rq, iter, rq) {
struct rt_bandwidth *rt_b = sched_rt_bandwidth(rt_rq);
raw_spin_lock(&rt_b->rt_runtime_lock);
raw_spin_lock(&rt_rq->rt_runtime_lock);
rt_rq->rt_runtime = rt_b->rt_runtime;
rt_rq->rt_time = 0;
rt_rq->rt_throttled = 0;
raw_spin_unlock(&rt_rq->rt_runtime_lock);
raw_spin_unlock(&rt_b->rt_runtime_lock);
}
}
static int balance_runtime(struct rt_rq *rt_rq)
{
int more = 0;
if (!sched_feat(RT_RUNTIME_SHARE))
return more;
if (rt_rq->rt_time > rt_rq->rt_runtime) {
raw_spin_unlock(&rt_rq->rt_runtime_lock);
more = do_balance_runtime(rt_rq);
raw_spin_lock(&rt_rq->rt_runtime_lock);
}
return more;
}
static inline int balance_runtime(struct rt_rq *rt_rq)
{
return 0;
}
static int do_sched_rt_period_timer(struct rt_bandwidth *rt_b, int overrun)
{
int i, idle = 1, throttled = 0;
const struct cpumask *span;
span = sched_rt_period_mask();
#ifdef CONFIG_RT_GROUP_SCHED
if (rt_b == &root_task_group.rt_bandwidth)
span = cpu_online_mask;
#endif
for_each_cpu(i, span) {
int enqueue = 0;
struct rt_rq *rt_rq = sched_rt_period_rt_rq(rt_b, i);
struct rq *rq = rq_of_rt_rq(rt_rq);
raw_spin_lock(&rq->lock);
if (rt_rq->rt_time) {
u64 runtime;
raw_spin_lock(&rt_rq->rt_runtime_lock);
if (rt_rq->rt_throttled)
balance_runtime(rt_rq);
runtime = rt_rq->rt_runtime;
rt_rq->rt_time -= min(rt_rq->rt_time, overrun*runtime);
if (rt_rq->rt_throttled && rt_rq->rt_time < runtime) {
rt_rq->rt_throttled = 0;
enqueue = 1;
if (rt_rq->rt_nr_running && rq->curr == rq->idle)
rq_clock_skip_update(rq, false);
}
if (rt_rq->rt_time || rt_rq->rt_nr_running)
idle = 0;
raw_spin_unlock(&rt_rq->rt_runtime_lock);
} else if (rt_rq->rt_nr_running) {
idle = 0;
if (!rt_rq_throttled(rt_rq))
enqueue = 1;
}
if (rt_rq->rt_throttled)
throttled = 1;
if (enqueue)
sched_rt_rq_enqueue(rt_rq);
raw_spin_unlock(&rq->lock);
}
if (!throttled && (!rt_bandwidth_enabled() || rt_b->rt_runtime == RUNTIME_INF))
return 1;
return idle;
}
static inline int rt_se_prio(struct sched_rt_entity *rt_se)
{
#ifdef CONFIG_RT_GROUP_SCHED
struct rt_rq *rt_rq = group_rt_rq(rt_se);
if (rt_rq)
return rt_rq->highest_prio.curr;
#endif
return rt_task_of(rt_se)->prio;
}
static int sched_rt_runtime_exceeded(struct rt_rq *rt_rq)
{
u64 runtime = sched_rt_runtime(rt_rq);
if (rt_rq->rt_throttled)
return rt_rq_throttled(rt_rq);
if (runtime >= sched_rt_period(rt_rq))
return 0;
balance_runtime(rt_rq);
runtime = sched_rt_runtime(rt_rq);
if (runtime == RUNTIME_INF)
return 0;
if (rt_rq->rt_time > runtime) {
struct rt_bandwidth *rt_b = sched_rt_bandwidth(rt_rq);
if (likely(rt_b->rt_runtime)) {
rt_rq->rt_throttled = 1;
printk_deferred_once("sched: RT throttling activated\n");
} else {
rt_rq->rt_time = 0;
}
if (rt_rq_throttled(rt_rq)) {
sched_rt_rq_dequeue(rt_rq);
return 1;
}
}
return 0;
}
static void update_curr_rt(struct rq *rq)
{
struct task_struct *curr = rq->curr;
struct sched_rt_entity *rt_se = &curr->rt;
u64 delta_exec;
if (curr->sched_class != &rt_sched_class)
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
if (!rt_bandwidth_enabled())
return;
for_each_sched_rt_entity(rt_se) {
struct rt_rq *rt_rq = rt_rq_of_se(rt_se);
if (sched_rt_runtime(rt_rq) != RUNTIME_INF) {
raw_spin_lock(&rt_rq->rt_runtime_lock);
rt_rq->rt_time += delta_exec;
if (sched_rt_runtime_exceeded(rt_rq))
resched_curr(rq);
raw_spin_unlock(&rt_rq->rt_runtime_lock);
}
}
}
static void
dequeue_top_rt_rq(struct rt_rq *rt_rq)
{
struct rq *rq = rq_of_rt_rq(rt_rq);
BUG_ON(&rq->rt != rt_rq);
if (!rt_rq->rt_queued)
return;
BUG_ON(!rq->nr_running);
sub_nr_running(rq, rt_rq->rt_nr_running);
rt_rq->rt_queued = 0;
}
static void
enqueue_top_rt_rq(struct rt_rq *rt_rq)
{
struct rq *rq = rq_of_rt_rq(rt_rq);
BUG_ON(&rq->rt != rt_rq);
if (rt_rq->rt_queued)
return;
if (rt_rq_throttled(rt_rq) || !rt_rq->rt_nr_running)
return;
add_nr_running(rq, rt_rq->rt_nr_running);
rt_rq->rt_queued = 1;
}
static void
inc_rt_prio_smp(struct rt_rq *rt_rq, int prio, int prev_prio)
{
struct rq *rq = rq_of_rt_rq(rt_rq);
#ifdef CONFIG_RT_GROUP_SCHED
if (&rq->rt != rt_rq)
return;
#endif
if (rq->online && prio < prev_prio)
cpupri_set(&rq->rd->cpupri, rq->cpu, prio);
}
static void
dec_rt_prio_smp(struct rt_rq *rt_rq, int prio, int prev_prio)
{
struct rq *rq = rq_of_rt_rq(rt_rq);
#ifdef CONFIG_RT_GROUP_SCHED
if (&rq->rt != rt_rq)
return;
#endif
if (rq->online && rt_rq->highest_prio.curr != prev_prio)
cpupri_set(&rq->rd->cpupri, rq->cpu, rt_rq->highest_prio.curr);
}
static inline
void inc_rt_prio_smp(struct rt_rq *rt_rq, int prio, int prev_prio) {}
static inline
void dec_rt_prio_smp(struct rt_rq *rt_rq, int prio, int prev_prio) {}
static void
inc_rt_prio(struct rt_rq *rt_rq, int prio)
{
int prev_prio = rt_rq->highest_prio.curr;
if (prio < prev_prio)
rt_rq->highest_prio.curr = prio;
inc_rt_prio_smp(rt_rq, prio, prev_prio);
}
static void
dec_rt_prio(struct rt_rq *rt_rq, int prio)
{
int prev_prio = rt_rq->highest_prio.curr;
if (rt_rq->rt_nr_running) {
WARN_ON(prio < prev_prio);
if (prio == prev_prio) {
struct rt_prio_array *array = &rt_rq->active;
rt_rq->highest_prio.curr =
sched_find_first_bit(array->bitmap);
}
} else
rt_rq->highest_prio.curr = MAX_RT_PRIO;
dec_rt_prio_smp(rt_rq, prio, prev_prio);
}
static inline void inc_rt_prio(struct rt_rq *rt_rq, int prio) {}
static inline void dec_rt_prio(struct rt_rq *rt_rq, int prio) {}
static void
inc_rt_group(struct sched_rt_entity *rt_se, struct rt_rq *rt_rq)
{
if (rt_se_boosted(rt_se))
rt_rq->rt_nr_boosted++;
if (rt_rq->tg)
start_rt_bandwidth(&rt_rq->tg->rt_bandwidth);
}
static void
dec_rt_group(struct sched_rt_entity *rt_se, struct rt_rq *rt_rq)
{
if (rt_se_boosted(rt_se))
rt_rq->rt_nr_boosted--;
WARN_ON(!rt_rq->rt_nr_running && rt_rq->rt_nr_boosted);
}
static void
inc_rt_group(struct sched_rt_entity *rt_se, struct rt_rq *rt_rq)
{
start_rt_bandwidth(&def_rt_bandwidth);
}
static inline
void dec_rt_group(struct sched_rt_entity *rt_se, struct rt_rq *rt_rq) {}
static inline
unsigned int rt_se_nr_running(struct sched_rt_entity *rt_se)
{
struct rt_rq *group_rq = group_rt_rq(rt_se);
if (group_rq)
return group_rq->rt_nr_running;
else
return 1;
}
static inline
void inc_rt_tasks(struct sched_rt_entity *rt_se, struct rt_rq *rt_rq)
{
int prio = rt_se_prio(rt_se);
WARN_ON(!rt_prio(prio));
rt_rq->rt_nr_running += rt_se_nr_running(rt_se);
inc_rt_prio(rt_rq, prio);
inc_rt_migration(rt_se, rt_rq);
inc_rt_group(rt_se, rt_rq);
}
static inline
void dec_rt_tasks(struct sched_rt_entity *rt_se, struct rt_rq *rt_rq)
{
WARN_ON(!rt_prio(rt_se_prio(rt_se)));
WARN_ON(!rt_rq->rt_nr_running);
rt_rq->rt_nr_running -= rt_se_nr_running(rt_se);
dec_rt_prio(rt_rq, rt_se_prio(rt_se));
dec_rt_migration(rt_se, rt_rq);
dec_rt_group(rt_se, rt_rq);
}
static void __enqueue_rt_entity(struct sched_rt_entity *rt_se, bool head)
{
struct rt_rq *rt_rq = rt_rq_of_se(rt_se);
struct rt_prio_array *array = &rt_rq->active;
struct rt_rq *group_rq = group_rt_rq(rt_se);
struct list_head *queue = array->queue + rt_se_prio(rt_se);
if (group_rq && (rt_rq_throttled(group_rq) || !group_rq->rt_nr_running))
return;
if (head)
list_add(&rt_se->run_list, queue);
else
list_add_tail(&rt_se->run_list, queue);
__set_bit(rt_se_prio(rt_se), array->bitmap);
inc_rt_tasks(rt_se, rt_rq);
}
static void __dequeue_rt_entity(struct sched_rt_entity *rt_se)
{
struct rt_rq *rt_rq = rt_rq_of_se(rt_se);
struct rt_prio_array *array = &rt_rq->active;
list_del_init(&rt_se->run_list);
if (list_empty(array->queue + rt_se_prio(rt_se)))
__clear_bit(rt_se_prio(rt_se), array->bitmap);
dec_rt_tasks(rt_se, rt_rq);
}
static void dequeue_rt_stack(struct sched_rt_entity *rt_se)
{
struct sched_rt_entity *back = NULL;
for_each_sched_rt_entity(rt_se) {
rt_se->back = back;
back = rt_se;
}
dequeue_top_rt_rq(rt_rq_of_se(back));
for (rt_se = back; rt_se; rt_se = rt_se->back) {
if (on_rt_rq(rt_se))
__dequeue_rt_entity(rt_se);
}
}
static void enqueue_rt_entity(struct sched_rt_entity *rt_se, bool head)
{
struct rq *rq = rq_of_rt_se(rt_se);
dequeue_rt_stack(rt_se);
for_each_sched_rt_entity(rt_se)
__enqueue_rt_entity(rt_se, head);
enqueue_top_rt_rq(&rq->rt);
}
static void dequeue_rt_entity(struct sched_rt_entity *rt_se)
{
struct rq *rq = rq_of_rt_se(rt_se);
dequeue_rt_stack(rt_se);
for_each_sched_rt_entity(rt_se) {
struct rt_rq *rt_rq = group_rt_rq(rt_se);
if (rt_rq && rt_rq->rt_nr_running)
__enqueue_rt_entity(rt_se, false);
}
enqueue_top_rt_rq(&rq->rt);
}
static void
enqueue_task_rt(struct rq *rq, struct task_struct *p, int flags)
{
struct sched_rt_entity *rt_se = &p->rt;
if (flags & ENQUEUE_WAKEUP)
rt_se->timeout = 0;
enqueue_rt_entity(rt_se, flags & ENQUEUE_HEAD);
if (!task_current(rq, p) && p->nr_cpus_allowed > 1)
enqueue_pushable_task(rq, p);
}
static void dequeue_task_rt(struct rq *rq, struct task_struct *p, int flags)
{
struct sched_rt_entity *rt_se = &p->rt;
update_curr_rt(rq);
dequeue_rt_entity(rt_se);
dequeue_pushable_task(rq, p);
}
static void
requeue_rt_entity(struct rt_rq *rt_rq, struct sched_rt_entity *rt_se, int head)
{
if (on_rt_rq(rt_se)) {
struct rt_prio_array *array = &rt_rq->active;
struct list_head *queue = array->queue + rt_se_prio(rt_se);
if (head)
list_move(&rt_se->run_list, queue);
else
list_move_tail(&rt_se->run_list, queue);
}
}
static void requeue_task_rt(struct rq *rq, struct task_struct *p, int head)
{
struct sched_rt_entity *rt_se = &p->rt;
struct rt_rq *rt_rq;
for_each_sched_rt_entity(rt_se) {
rt_rq = rt_rq_of_se(rt_se);
requeue_rt_entity(rt_rq, rt_se, head);
}
}
static void yield_task_rt(struct rq *rq)
{
requeue_task_rt(rq, rq->curr, 0);
}
static int
select_task_rq_rt(struct task_struct *p, int cpu, int sd_flag, int flags)
{
struct task_struct *curr;
struct rq *rq;
if (sd_flag != SD_BALANCE_WAKE && sd_flag != SD_BALANCE_FORK)
goto out;
rq = cpu_rq(cpu);
rcu_read_lock();
curr = ACCESS_ONCE(rq->curr);
if (curr && unlikely(rt_task(curr)) &&
(curr->nr_cpus_allowed < 2 ||
curr->prio <= p->prio)) {
int target = find_lowest_rq(p);
if (target != -1 &&
p->prio < cpu_rq(target)->rt.highest_prio.curr)
cpu = target;
}
rcu_read_unlock();
out:
return cpu;
}
static void check_preempt_equal_prio(struct rq *rq, struct task_struct *p)
{
if (rq->curr->nr_cpus_allowed == 1 ||
!cpupri_find(&rq->rd->cpupri, rq->curr, NULL))
return;
if (p->nr_cpus_allowed != 1
&& cpupri_find(&rq->rd->cpupri, p, NULL))
return;
requeue_task_rt(rq, p, 1);
resched_curr(rq);
}
static void check_preempt_curr_rt(struct rq *rq, struct task_struct *p, int flags)
{
if (p->prio < rq->curr->prio) {
resched_curr(rq);
return;
}
#ifdef CONFIG_SMP
if (p->prio == rq->curr->prio && !test_tsk_need_resched(rq->curr))
check_preempt_equal_prio(rq, p);
#endif
}
static struct sched_rt_entity *pick_next_rt_entity(struct rq *rq,
struct rt_rq *rt_rq)
{
struct rt_prio_array *array = &rt_rq->active;
struct sched_rt_entity *next = NULL;
struct list_head *queue;
int idx;
idx = sched_find_first_bit(array->bitmap);
BUG_ON(idx >= MAX_RT_PRIO);
queue = array->queue + idx;
next = list_entry(queue->next, struct sched_rt_entity, run_list);
return next;
}
static struct task_struct *_pick_next_task_rt(struct rq *rq)
{
struct sched_rt_entity *rt_se;
struct task_struct *p;
struct rt_rq *rt_rq = &rq->rt;
do {
rt_se = pick_next_rt_entity(rq, rt_rq);
BUG_ON(!rt_se);
rt_rq = group_rt_rq(rt_se);
} while (rt_rq);
p = rt_task_of(rt_se);
p->se.exec_start = rq_clock_task(rq);
return p;
}
static struct task_struct *
pick_next_task_rt(struct rq *rq, struct task_struct *prev)
{
struct task_struct *p;
struct rt_rq *rt_rq = &rq->rt;
if (need_pull_rt_task(rq, prev)) {
pull_rt_task(rq);
if (unlikely((rq->stop && task_on_rq_queued(rq->stop)) ||
rq->dl.dl_nr_running))
return RETRY_TASK;
}
if (prev->sched_class == &rt_sched_class)
update_curr_rt(rq);
if (!rt_rq->rt_queued)
return NULL;
put_prev_task(rq, prev);
p = _pick_next_task_rt(rq);
dequeue_pushable_task(rq, p);
set_post_schedule(rq);
return p;
}
static void put_prev_task_rt(struct rq *rq, struct task_struct *p)
{
update_curr_rt(rq);
if (on_rt_rq(&p->rt) && p->nr_cpus_allowed > 1)
enqueue_pushable_task(rq, p);
}
static int pick_rt_task(struct rq *rq, struct task_struct *p, int cpu)
{
if (!task_running(rq, p) &&
cpumask_test_cpu(cpu, tsk_cpus_allowed(p)))
return 1;
return 0;
}
static struct task_struct *pick_highest_pushable_task(struct rq *rq, int cpu)
{
struct plist_head *head = &rq->rt.pushable_tasks;
struct task_struct *p;
if (!has_pushable_tasks(rq))
return NULL;
plist_for_each_entry(p, head, pushable_tasks) {
if (pick_rt_task(rq, p, cpu))
return p;
}
return NULL;
}
static int find_lowest_rq(struct task_struct *task)
{
struct sched_domain *sd;
struct cpumask *lowest_mask = this_cpu_cpumask_var_ptr(local_cpu_mask);
int this_cpu = smp_processor_id();
int cpu = task_cpu(task);
if (unlikely(!lowest_mask))
return -1;
if (task->nr_cpus_allowed == 1)
return -1;
if (!cpupri_find(&task_rq(task)->rd->cpupri, task, lowest_mask))
return -1;
if (cpumask_test_cpu(cpu, lowest_mask))
return cpu;
if (!cpumask_test_cpu(this_cpu, lowest_mask))
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
best_cpu = cpumask_first_and(lowest_mask,
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
cpu = cpumask_any(lowest_mask);
if (cpu < nr_cpu_ids)
return cpu;
return -1;
}
static struct rq *find_lock_lowest_rq(struct task_struct *task, struct rq *rq)
{
struct rq *lowest_rq = NULL;
int tries;
int cpu;
for (tries = 0; tries < RT_MAX_TRIES; tries++) {
cpu = find_lowest_rq(task);
if ((cpu == -1) || (cpu == rq->cpu))
break;
lowest_rq = cpu_rq(cpu);
if (lowest_rq->rt.highest_prio.curr <= task->prio) {
lowest_rq = NULL;
break;
}
if (double_lock_balance(rq, lowest_rq)) {
if (unlikely(task_rq(task) != rq ||
!cpumask_test_cpu(lowest_rq->cpu,
tsk_cpus_allowed(task)) ||
task_running(rq, task) ||
!task_on_rq_queued(task))) {
double_unlock_balance(rq, lowest_rq);
lowest_rq = NULL;
break;
}
}
if (lowest_rq->rt.highest_prio.curr > task->prio)
break;
double_unlock_balance(rq, lowest_rq);
lowest_rq = NULL;
}
return lowest_rq;
}
static struct task_struct *pick_next_pushable_task(struct rq *rq)
{
struct task_struct *p;
if (!has_pushable_tasks(rq))
return NULL;
p = plist_first_entry(&rq->rt.pushable_tasks,
struct task_struct, pushable_tasks);
BUG_ON(rq->cpu != task_cpu(p));
BUG_ON(task_current(rq, p));
BUG_ON(p->nr_cpus_allowed <= 1);
BUG_ON(!task_on_rq_queued(p));
BUG_ON(!rt_task(p));
return p;
}
static int push_rt_task(struct rq *rq)
{
struct task_struct *next_task;
struct rq *lowest_rq;
int ret = 0;
if (!rq->rt.overloaded)
return 0;
next_task = pick_next_pushable_task(rq);
if (!next_task)
return 0;
retry:
if (unlikely(next_task == rq->curr)) {
WARN_ON(1);
return 0;
}
if (unlikely(next_task->prio < rq->curr->prio)) {
resched_curr(rq);
return 0;
}
get_task_struct(next_task);
lowest_rq = find_lock_lowest_rq(next_task, rq);
if (!lowest_rq) {
struct task_struct *task;
task = pick_next_pushable_task(rq);
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
set_task_cpu(next_task, lowest_rq->cpu);
activate_task(lowest_rq, next_task, 0);
ret = 1;
resched_curr(lowest_rq);
double_unlock_balance(rq, lowest_rq);
out:
put_task_struct(next_task);
return ret;
}
static void push_rt_tasks(struct rq *rq)
{
while (push_rt_task(rq))
;
}
static int pull_rt_task(struct rq *this_rq)
{
int this_cpu = this_rq->cpu, ret = 0, cpu;
struct task_struct *p;
struct rq *src_rq;
if (likely(!rt_overloaded(this_rq)))
return 0;
smp_rmb();
for_each_cpu(cpu, this_rq->rd->rto_mask) {
if (this_cpu == cpu)
continue;
src_rq = cpu_rq(cpu);
if (src_rq->rt.highest_prio.next >=
this_rq->rt.highest_prio.curr)
continue;
double_lock_balance(this_rq, src_rq);
p = pick_highest_pushable_task(src_rq, this_cpu);
if (p && (p->prio < this_rq->rt.highest_prio.curr)) {
WARN_ON(p == src_rq->curr);
WARN_ON(!task_on_rq_queued(p));
if (p->prio < src_rq->curr->prio)
goto skip;
ret = 1;
deactivate_task(src_rq, p, 0);
set_task_cpu(p, this_cpu);
activate_task(this_rq, p, 0);
}
skip:
double_unlock_balance(this_rq, src_rq);
}
return ret;
}
static void post_schedule_rt(struct rq *rq)
{
push_rt_tasks(rq);
}
static void task_woken_rt(struct rq *rq, struct task_struct *p)
{
if (!task_running(rq, p) &&
!test_tsk_need_resched(rq->curr) &&
has_pushable_tasks(rq) &&
p->nr_cpus_allowed > 1 &&
(dl_task(rq->curr) || rt_task(rq->curr)) &&
(rq->curr->nr_cpus_allowed < 2 ||
rq->curr->prio <= p->prio))
push_rt_tasks(rq);
}
static void set_cpus_allowed_rt(struct task_struct *p,
const struct cpumask *new_mask)
{
struct rq *rq;
int weight;
BUG_ON(!rt_task(p));
if (!task_on_rq_queued(p))
return;
weight = cpumask_weight(new_mask);
if ((p->nr_cpus_allowed > 1) == (weight > 1))
return;
rq = task_rq(p);
if (weight <= 1) {
if (!task_current(rq, p))
dequeue_pushable_task(rq, p);
BUG_ON(!rq->rt.rt_nr_migratory);
rq->rt.rt_nr_migratory--;
} else {
if (!task_current(rq, p))
enqueue_pushable_task(rq, p);
rq->rt.rt_nr_migratory++;
}
update_rt_migration(&rq->rt);
}
static void rq_online_rt(struct rq *rq)
{
if (rq->rt.overloaded)
rt_set_overload(rq);
__enable_runtime(rq);
cpupri_set(&rq->rd->cpupri, rq->cpu, rq->rt.highest_prio.curr);
}
static void rq_offline_rt(struct rq *rq)
{
if (rq->rt.overloaded)
rt_clear_overload(rq);
__disable_runtime(rq);
cpupri_set(&rq->rd->cpupri, rq->cpu, CPUPRI_INVALID);
}
static void switched_from_rt(struct rq *rq, struct task_struct *p)
{
if (!task_on_rq_queued(p) || rq->rt.rt_nr_running)
return;
if (pull_rt_task(rq))
resched_curr(rq);
}
void __init init_sched_rt_class(void)
{
unsigned int i;
for_each_possible_cpu(i) {
zalloc_cpumask_var_node(&per_cpu(local_cpu_mask, i),
GFP_KERNEL, cpu_to_node(i));
}
}
static void switched_to_rt(struct rq *rq, struct task_struct *p)
{
int check_resched = 1;
if (task_on_rq_queued(p) && rq->curr != p) {
#ifdef CONFIG_SMP
if (p->nr_cpus_allowed > 1 && rq->rt.overloaded &&
push_rt_task(rq) && rq != task_rq(p))
check_resched = 0;
#endif
if (check_resched && p->prio < rq->curr->prio)
resched_curr(rq);
}
}
static void
prio_changed_rt(struct rq *rq, struct task_struct *p, int oldprio)
{
if (!task_on_rq_queued(p))
return;
if (rq->curr == p) {
#ifdef CONFIG_SMP
if (oldprio < p->prio)
pull_rt_task(rq);
if (p->prio > rq->rt.highest_prio.curr && rq->curr == p)
resched_curr(rq);
#else
if (oldprio < p->prio)
resched_curr(rq);
#endif
} else {
if (p->prio < rq->curr->prio)
resched_curr(rq);
}
}
static void watchdog(struct rq *rq, struct task_struct *p)
{
unsigned long soft, hard;
soft = task_rlimit(p, RLIMIT_RTTIME);
hard = task_rlimit_max(p, RLIMIT_RTTIME);
if (soft != RLIM_INFINITY) {
unsigned long next;
if (p->rt.watchdog_stamp != jiffies) {
p->rt.timeout++;
p->rt.watchdog_stamp = jiffies;
}
next = DIV_ROUND_UP(min(soft, hard), USEC_PER_SEC/HZ);
if (p->rt.timeout > next)
p->cputime_expires.sched_exp = p->se.sum_exec_runtime;
}
}
static void task_tick_rt(struct rq *rq, struct task_struct *p, int queued)
{
struct sched_rt_entity *rt_se = &p->rt;
update_curr_rt(rq);
watchdog(rq, p);
if (p->policy != SCHED_RR)
return;
if (--p->rt.time_slice)
return;
p->rt.time_slice = sched_rr_timeslice;
for_each_sched_rt_entity(rt_se) {
if (rt_se->run_list.prev != rt_se->run_list.next) {
requeue_task_rt(rq, p, 0);
resched_curr(rq);
return;
}
}
}
static void set_curr_task_rt(struct rq *rq)
{
struct task_struct *p = rq->curr;
p->se.exec_start = rq_clock_task(rq);
dequeue_pushable_task(rq, p);
}
static unsigned int get_rr_interval_rt(struct rq *rq, struct task_struct *task)
{
if (task->policy == SCHED_RR)
return sched_rr_timeslice;
else
return 0;
}
void print_rt_stats(struct seq_file *m, int cpu)
{
rt_rq_iter_t iter;
struct rt_rq *rt_rq;
rcu_read_lock();
for_each_rt_rq(rt_rq, iter, cpu_rq(cpu))
print_rt_rq(m, cpu, rt_rq);
rcu_read_unlock();
}
