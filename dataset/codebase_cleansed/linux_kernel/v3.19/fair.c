static inline void update_load_add(struct load_weight *lw, unsigned long inc)
{
lw->weight += inc;
lw->inv_weight = 0;
}
static inline void update_load_sub(struct load_weight *lw, unsigned long dec)
{
lw->weight -= dec;
lw->inv_weight = 0;
}
static inline void update_load_set(struct load_weight *lw, unsigned long w)
{
lw->weight = w;
lw->inv_weight = 0;
}
static int get_update_sysctl_factor(void)
{
unsigned int cpus = min_t(int, num_online_cpus(), 8);
unsigned int factor;
switch (sysctl_sched_tunable_scaling) {
case SCHED_TUNABLESCALING_NONE:
factor = 1;
break;
case SCHED_TUNABLESCALING_LINEAR:
factor = cpus;
break;
case SCHED_TUNABLESCALING_LOG:
default:
factor = 1 + ilog2(cpus);
break;
}
return factor;
}
static void update_sysctl(void)
{
unsigned int factor = get_update_sysctl_factor();
#define SET_SYSCTL(name) \
(sysctl_##name = (factor) * normalized_sysctl_##name)
SET_SYSCTL(sched_min_granularity);
SET_SYSCTL(sched_latency);
SET_SYSCTL(sched_wakeup_granularity);
#undef SET_SYSCTL
}
void sched_init_granularity(void)
{
update_sysctl();
}
static void __update_inv_weight(struct load_weight *lw)
{
unsigned long w;
if (likely(lw->inv_weight))
return;
w = scale_load_down(lw->weight);
if (BITS_PER_LONG > 32 && unlikely(w >= WMULT_CONST))
lw->inv_weight = 1;
else if (unlikely(!w))
lw->inv_weight = WMULT_CONST;
else
lw->inv_weight = WMULT_CONST / w;
}
static u64 __calc_delta(u64 delta_exec, unsigned long weight, struct load_weight *lw)
{
u64 fact = scale_load_down(weight);
int shift = WMULT_SHIFT;
__update_inv_weight(lw);
if (unlikely(fact >> 32)) {
while (fact >> 32) {
fact >>= 1;
shift--;
}
}
fact = (u64)(u32)fact * lw->inv_weight;
while (fact >> 32) {
fact >>= 1;
shift--;
}
return mul_u64_u32_shr(delta_exec, fact, shift);
}
static inline struct rq *rq_of(struct cfs_rq *cfs_rq)
{
return cfs_rq->rq;
}
static inline struct task_struct *task_of(struct sched_entity *se)
{
#ifdef CONFIG_SCHED_DEBUG
WARN_ON_ONCE(!entity_is_task(se));
#endif
return container_of(se, struct task_struct, se);
}
static inline struct cfs_rq *task_cfs_rq(struct task_struct *p)
{
return p->se.cfs_rq;
}
static inline struct cfs_rq *cfs_rq_of(struct sched_entity *se)
{
return se->cfs_rq;
}
static inline struct cfs_rq *group_cfs_rq(struct sched_entity *grp)
{
return grp->my_q;
}
static inline void list_add_leaf_cfs_rq(struct cfs_rq *cfs_rq)
{
if (!cfs_rq->on_list) {
if (cfs_rq->tg->parent &&
cfs_rq->tg->parent->cfs_rq[cpu_of(rq_of(cfs_rq))]->on_list) {
list_add_rcu(&cfs_rq->leaf_cfs_rq_list,
&rq_of(cfs_rq)->leaf_cfs_rq_list);
} else {
list_add_tail_rcu(&cfs_rq->leaf_cfs_rq_list,
&rq_of(cfs_rq)->leaf_cfs_rq_list);
}
cfs_rq->on_list = 1;
update_cfs_rq_blocked_load(cfs_rq, 0);
}
}
static inline void list_del_leaf_cfs_rq(struct cfs_rq *cfs_rq)
{
if (cfs_rq->on_list) {
list_del_rcu(&cfs_rq->leaf_cfs_rq_list);
cfs_rq->on_list = 0;
}
}
static inline struct cfs_rq *
is_same_group(struct sched_entity *se, struct sched_entity *pse)
{
if (se->cfs_rq == pse->cfs_rq)
return se->cfs_rq;
return NULL;
}
static inline struct sched_entity *parent_entity(struct sched_entity *se)
{
return se->parent;
}
static void
find_matching_se(struct sched_entity **se, struct sched_entity **pse)
{
int se_depth, pse_depth;
se_depth = (*se)->depth;
pse_depth = (*pse)->depth;
while (se_depth > pse_depth) {
se_depth--;
*se = parent_entity(*se);
}
while (pse_depth > se_depth) {
pse_depth--;
*pse = parent_entity(*pse);
}
while (!is_same_group(*se, *pse)) {
*se = parent_entity(*se);
*pse = parent_entity(*pse);
}
}
static inline struct task_struct *task_of(struct sched_entity *se)
{
return container_of(se, struct task_struct, se);
}
static inline struct rq *rq_of(struct cfs_rq *cfs_rq)
{
return container_of(cfs_rq, struct rq, cfs);
}
static inline struct cfs_rq *task_cfs_rq(struct task_struct *p)
{
return &task_rq(p)->cfs;
}
static inline struct cfs_rq *cfs_rq_of(struct sched_entity *se)
{
struct task_struct *p = task_of(se);
struct rq *rq = task_rq(p);
return &rq->cfs;
}
static inline struct cfs_rq *group_cfs_rq(struct sched_entity *grp)
{
return NULL;
}
static inline void list_add_leaf_cfs_rq(struct cfs_rq *cfs_rq)
{
}
static inline void list_del_leaf_cfs_rq(struct cfs_rq *cfs_rq)
{
}
static inline struct sched_entity *parent_entity(struct sched_entity *se)
{
return NULL;
}
static inline void
find_matching_se(struct sched_entity **se, struct sched_entity **pse)
{
}
static inline u64 max_vruntime(u64 max_vruntime, u64 vruntime)
{
s64 delta = (s64)(vruntime - max_vruntime);
if (delta > 0)
max_vruntime = vruntime;
return max_vruntime;
}
static inline u64 min_vruntime(u64 min_vruntime, u64 vruntime)
{
s64 delta = (s64)(vruntime - min_vruntime);
if (delta < 0)
min_vruntime = vruntime;
return min_vruntime;
}
static inline int entity_before(struct sched_entity *a,
struct sched_entity *b)
{
return (s64)(a->vruntime - b->vruntime) < 0;
}
static void update_min_vruntime(struct cfs_rq *cfs_rq)
{
u64 vruntime = cfs_rq->min_vruntime;
if (cfs_rq->curr)
vruntime = cfs_rq->curr->vruntime;
if (cfs_rq->rb_leftmost) {
struct sched_entity *se = rb_entry(cfs_rq->rb_leftmost,
struct sched_entity,
run_node);
if (!cfs_rq->curr)
vruntime = se->vruntime;
else
vruntime = min_vruntime(vruntime, se->vruntime);
}
cfs_rq->min_vruntime = max_vruntime(cfs_rq->min_vruntime, vruntime);
#ifndef CONFIG_64BIT
smp_wmb();
cfs_rq->min_vruntime_copy = cfs_rq->min_vruntime;
#endif
}
static void __enqueue_entity(struct cfs_rq *cfs_rq, struct sched_entity *se)
{
struct rb_node **link = &cfs_rq->tasks_timeline.rb_node;
struct rb_node *parent = NULL;
struct sched_entity *entry;
int leftmost = 1;
while (*link) {
parent = *link;
entry = rb_entry(parent, struct sched_entity, run_node);
if (entity_before(se, entry)) {
link = &parent->rb_left;
} else {
link = &parent->rb_right;
leftmost = 0;
}
}
if (leftmost)
cfs_rq->rb_leftmost = &se->run_node;
rb_link_node(&se->run_node, parent, link);
rb_insert_color(&se->run_node, &cfs_rq->tasks_timeline);
}
static void __dequeue_entity(struct cfs_rq *cfs_rq, struct sched_entity *se)
{
if (cfs_rq->rb_leftmost == &se->run_node) {
struct rb_node *next_node;
next_node = rb_next(&se->run_node);
cfs_rq->rb_leftmost = next_node;
}
rb_erase(&se->run_node, &cfs_rq->tasks_timeline);
}
struct sched_entity *__pick_first_entity(struct cfs_rq *cfs_rq)
{
struct rb_node *left = cfs_rq->rb_leftmost;
if (!left)
return NULL;
return rb_entry(left, struct sched_entity, run_node);
}
static struct sched_entity *__pick_next_entity(struct sched_entity *se)
{
struct rb_node *next = rb_next(&se->run_node);
if (!next)
return NULL;
return rb_entry(next, struct sched_entity, run_node);
}
struct sched_entity *__pick_last_entity(struct cfs_rq *cfs_rq)
{
struct rb_node *last = rb_last(&cfs_rq->tasks_timeline);
if (!last)
return NULL;
return rb_entry(last, struct sched_entity, run_node);
}
int sched_proc_update_handler(struct ctl_table *table, int write,
void __user *buffer, size_t *lenp,
loff_t *ppos)
{
int ret = proc_dointvec_minmax(table, write, buffer, lenp, ppos);
int factor = get_update_sysctl_factor();
if (ret || !write)
return ret;
sched_nr_latency = DIV_ROUND_UP(sysctl_sched_latency,
sysctl_sched_min_granularity);
#define WRT_SYSCTL(name) \
(normalized_sysctl_##name = sysctl_##name / (factor))
WRT_SYSCTL(sched_min_granularity);
WRT_SYSCTL(sched_latency);
WRT_SYSCTL(sched_wakeup_granularity);
#undef WRT_SYSCTL
return 0;
}
static inline u64 calc_delta_fair(u64 delta, struct sched_entity *se)
{
if (unlikely(se->load.weight != NICE_0_LOAD))
delta = __calc_delta(delta, NICE_0_LOAD, &se->load);
return delta;
}
static u64 __sched_period(unsigned long nr_running)
{
u64 period = sysctl_sched_latency;
unsigned long nr_latency = sched_nr_latency;
if (unlikely(nr_running > nr_latency)) {
period = sysctl_sched_min_granularity;
period *= nr_running;
}
return period;
}
static u64 sched_slice(struct cfs_rq *cfs_rq, struct sched_entity *se)
{
u64 slice = __sched_period(cfs_rq->nr_running + !se->on_rq);
for_each_sched_entity(se) {
struct load_weight *load;
struct load_weight lw;
cfs_rq = cfs_rq_of(se);
load = &cfs_rq->load;
if (unlikely(!se->on_rq)) {
lw = cfs_rq->load;
update_load_add(&lw, se->load.weight);
load = &lw;
}
slice = __calc_delta(slice, se->load.weight, load);
}
return slice;
}
static u64 sched_vslice(struct cfs_rq *cfs_rq, struct sched_entity *se)
{
return calc_delta_fair(sched_slice(cfs_rq, se), se);
}
void init_task_runnable_average(struct task_struct *p)
{
u32 slice;
p->se.avg.decay_count = 0;
slice = sched_slice(task_cfs_rq(p), &p->se) >> 10;
p->se.avg.runnable_avg_sum = slice;
p->se.avg.runnable_avg_period = slice;
__update_task_entity_contrib(&p->se);
}
void init_task_runnable_average(struct task_struct *p)
{
}
static void update_curr(struct cfs_rq *cfs_rq)
{
struct sched_entity *curr = cfs_rq->curr;
u64 now = rq_clock_task(rq_of(cfs_rq));
u64 delta_exec;
if (unlikely(!curr))
return;
delta_exec = now - curr->exec_start;
if (unlikely((s64)delta_exec <= 0))
return;
curr->exec_start = now;
schedstat_set(curr->statistics.exec_max,
max(delta_exec, curr->statistics.exec_max));
curr->sum_exec_runtime += delta_exec;
schedstat_add(cfs_rq, exec_clock, delta_exec);
curr->vruntime += calc_delta_fair(delta_exec, curr);
update_min_vruntime(cfs_rq);
if (entity_is_task(curr)) {
struct task_struct *curtask = task_of(curr);
trace_sched_stat_runtime(curtask, delta_exec, curr->vruntime);
cpuacct_charge(curtask, delta_exec);
account_group_exec_runtime(curtask, delta_exec);
}
account_cfs_rq_runtime(cfs_rq, delta_exec);
}
static void update_curr_fair(struct rq *rq)
{
update_curr(cfs_rq_of(&rq->curr->se));
}
static inline void
update_stats_wait_start(struct cfs_rq *cfs_rq, struct sched_entity *se)
{
schedstat_set(se->statistics.wait_start, rq_clock(rq_of(cfs_rq)));
}
static void update_stats_enqueue(struct cfs_rq *cfs_rq, struct sched_entity *se)
{
if (se != cfs_rq->curr)
update_stats_wait_start(cfs_rq, se);
}
static void
update_stats_wait_end(struct cfs_rq *cfs_rq, struct sched_entity *se)
{
schedstat_set(se->statistics.wait_max, max(se->statistics.wait_max,
rq_clock(rq_of(cfs_rq)) - se->statistics.wait_start));
schedstat_set(se->statistics.wait_count, se->statistics.wait_count + 1);
schedstat_set(se->statistics.wait_sum, se->statistics.wait_sum +
rq_clock(rq_of(cfs_rq)) - se->statistics.wait_start);
#ifdef CONFIG_SCHEDSTATS
if (entity_is_task(se)) {
trace_sched_stat_wait(task_of(se),
rq_clock(rq_of(cfs_rq)) - se->statistics.wait_start);
}
#endif
schedstat_set(se->statistics.wait_start, 0);
}
static inline void
update_stats_dequeue(struct cfs_rq *cfs_rq, struct sched_entity *se)
{
if (se != cfs_rq->curr)
update_stats_wait_end(cfs_rq, se);
}
static inline void
update_stats_curr_start(struct cfs_rq *cfs_rq, struct sched_entity *se)
{
se->exec_start = rq_clock_task(rq_of(cfs_rq));
}
static unsigned int task_nr_scan_windows(struct task_struct *p)
{
unsigned long rss = 0;
unsigned long nr_scan_pages;
nr_scan_pages = sysctl_numa_balancing_scan_size << (20 - PAGE_SHIFT);
rss = get_mm_rss(p->mm);
if (!rss)
rss = nr_scan_pages;
rss = round_up(rss, nr_scan_pages);
return rss / nr_scan_pages;
}
static unsigned int task_scan_min(struct task_struct *p)
{
unsigned int scan_size = ACCESS_ONCE(sysctl_numa_balancing_scan_size);
unsigned int scan, floor;
unsigned int windows = 1;
if (scan_size < MAX_SCAN_WINDOW)
windows = MAX_SCAN_WINDOW / scan_size;
floor = 1000 / windows;
scan = sysctl_numa_balancing_scan_period_min / task_nr_scan_windows(p);
return max_t(unsigned int, floor, scan);
}
static unsigned int task_scan_max(struct task_struct *p)
{
unsigned int smin = task_scan_min(p);
unsigned int smax;
smax = sysctl_numa_balancing_scan_period_max / task_nr_scan_windows(p);
return max(smin, smax);
}
static void account_numa_enqueue(struct rq *rq, struct task_struct *p)
{
rq->nr_numa_running += (p->numa_preferred_nid != -1);
rq->nr_preferred_running += (p->numa_preferred_nid == task_node(p));
}
static void account_numa_dequeue(struct rq *rq, struct task_struct *p)
{
rq->nr_numa_running -= (p->numa_preferred_nid != -1);
rq->nr_preferred_running -= (p->numa_preferred_nid == task_node(p));
}
pid_t task_numa_group_id(struct task_struct *p)
{
return p->numa_group ? p->numa_group->gid : 0;
}
static inline int task_faults_idx(enum numa_faults_stats s, int nid, int priv)
{
return NR_NUMA_HINT_FAULT_TYPES * (s * nr_node_ids + nid) + priv;
}
static inline unsigned long task_faults(struct task_struct *p, int nid)
{
if (!p->numa_faults)
return 0;
return p->numa_faults[task_faults_idx(NUMA_MEM, nid, 0)] +
p->numa_faults[task_faults_idx(NUMA_MEM, nid, 1)];
}
static inline unsigned long group_faults(struct task_struct *p, int nid)
{
if (!p->numa_group)
return 0;
return p->numa_group->faults[task_faults_idx(NUMA_MEM, nid, 0)] +
p->numa_group->faults[task_faults_idx(NUMA_MEM, nid, 1)];
}
static inline unsigned long group_faults_cpu(struct numa_group *group, int nid)
{
return group->faults_cpu[task_faults_idx(NUMA_MEM, nid, 0)] +
group->faults_cpu[task_faults_idx(NUMA_MEM, nid, 1)];
}
static unsigned long score_nearby_nodes(struct task_struct *p, int nid,
int maxdist, bool task)
{
unsigned long score = 0;
int node;
if (sched_numa_topology_type == NUMA_DIRECT)
return 0;
for_each_online_node(node) {
unsigned long faults;
int dist = node_distance(nid, node);
if (dist == sched_max_numa_distance || node == nid)
continue;
if (sched_numa_topology_type == NUMA_BACKPLANE &&
dist > maxdist)
continue;
if (task)
faults = task_faults(p, node);
else
faults = group_faults(p, node);
if (sched_numa_topology_type == NUMA_GLUELESS_MESH) {
faults *= (sched_max_numa_distance - dist);
faults /= (sched_max_numa_distance - LOCAL_DISTANCE);
}
score += faults;
}
return score;
}
static inline unsigned long task_weight(struct task_struct *p, int nid,
int dist)
{
unsigned long faults, total_faults;
if (!p->numa_faults)
return 0;
total_faults = p->total_numa_faults;
if (!total_faults)
return 0;
faults = task_faults(p, nid);
faults += score_nearby_nodes(p, nid, dist, true);
return 1000 * faults / total_faults;
}
static inline unsigned long group_weight(struct task_struct *p, int nid,
int dist)
{
unsigned long faults, total_faults;
if (!p->numa_group)
return 0;
total_faults = p->numa_group->total_faults;
if (!total_faults)
return 0;
faults = group_faults(p, nid);
faults += score_nearby_nodes(p, nid, dist, false);
return 1000 * faults / total_faults;
}
bool should_numa_migrate_memory(struct task_struct *p, struct page * page,
int src_nid, int dst_cpu)
{
struct numa_group *ng = p->numa_group;
int dst_nid = cpu_to_node(dst_cpu);
int last_cpupid, this_cpupid;
this_cpupid = cpu_pid_to_cpupid(dst_cpu, current->pid);
last_cpupid = page_cpupid_xchg_last(page, this_cpupid);
if (!cpupid_pid_unset(last_cpupid) &&
cpupid_to_nid(last_cpupid) != dst_nid)
return false;
if (cpupid_match_pid(p, last_cpupid))
return true;
if (!ng)
return true;
if (!node_isset(dst_nid, ng->active_nodes))
return false;
if (!node_isset(src_nid, ng->active_nodes))
return true;
return group_faults(p, dst_nid) < (group_faults(p, src_nid) * 3 / 4);
}
static void update_numa_stats(struct numa_stats *ns, int nid)
{
int smt, cpu, cpus = 0;
unsigned long capacity;
memset(ns, 0, sizeof(*ns));
for_each_cpu(cpu, cpumask_of_node(nid)) {
struct rq *rq = cpu_rq(cpu);
ns->nr_running += rq->nr_running;
ns->load += weighted_cpuload(cpu);
ns->compute_capacity += capacity_of(cpu);
cpus++;
}
if (!cpus)
return;
smt = DIV_ROUND_UP(SCHED_CAPACITY_SCALE * cpus, ns->compute_capacity);
capacity = cpus / smt;
ns->task_capacity = min_t(unsigned, capacity,
DIV_ROUND_CLOSEST(ns->compute_capacity, SCHED_CAPACITY_SCALE));
ns->has_free_capacity = (ns->nr_running < ns->task_capacity);
}
static void task_numa_assign(struct task_numa_env *env,
struct task_struct *p, long imp)
{
if (env->best_task)
put_task_struct(env->best_task);
if (p)
get_task_struct(p);
env->best_task = p;
env->best_imp = imp;
env->best_cpu = env->dst_cpu;
}
static bool load_too_imbalanced(long src_load, long dst_load,
struct task_numa_env *env)
{
long imb, old_imb;
long orig_src_load, orig_dst_load;
long src_capacity, dst_capacity;
src_capacity = env->src_stats.compute_capacity;
dst_capacity = env->dst_stats.compute_capacity;
if (dst_load < src_load)
swap(dst_load, src_load);
imb = dst_load * src_capacity * 100 -
src_load * dst_capacity * env->imbalance_pct;
if (imb <= 0)
return false;
orig_src_load = env->src_stats.load;
orig_dst_load = env->dst_stats.load;
if (orig_dst_load < orig_src_load)
swap(orig_dst_load, orig_src_load);
old_imb = orig_dst_load * src_capacity * 100 -
orig_src_load * dst_capacity * env->imbalance_pct;
return (imb > old_imb);
}
static void task_numa_compare(struct task_numa_env *env,
long taskimp, long groupimp)
{
struct rq *src_rq = cpu_rq(env->src_cpu);
struct rq *dst_rq = cpu_rq(env->dst_cpu);
struct task_struct *cur;
long src_load, dst_load;
long load;
long imp = env->p->numa_group ? groupimp : taskimp;
long moveimp = imp;
int dist = env->dist;
rcu_read_lock();
raw_spin_lock_irq(&dst_rq->lock);
cur = dst_rq->curr;
if ((cur->flags & PF_EXITING) || is_idle_task(cur))
cur = NULL;
raw_spin_unlock_irq(&dst_rq->lock);
if (cur == env->p)
goto unlock;
if (cur) {
if (!cpumask_test_cpu(env->src_cpu, tsk_cpus_allowed(cur)))
goto unlock;
if (cur->numa_group == env->p->numa_group) {
imp = taskimp + task_weight(cur, env->src_nid, dist) -
task_weight(cur, env->dst_nid, dist);
if (cur->numa_group)
imp -= imp/16;
} else {
if (cur->numa_group)
imp += group_weight(cur, env->src_nid, dist) -
group_weight(cur, env->dst_nid, dist);
else
imp += task_weight(cur, env->src_nid, dist) -
task_weight(cur, env->dst_nid, dist);
}
}
if (imp <= env->best_imp && moveimp <= env->best_imp)
goto unlock;
if (!cur) {
if (env->src_stats.nr_running <= env->src_stats.task_capacity &&
!env->dst_stats.has_free_capacity)
goto unlock;
goto balance;
}
if (imp > env->best_imp && src_rq->nr_running == 1 &&
dst_rq->nr_running == 1)
goto assign;
balance:
load = task_h_load(env->p);
dst_load = env->dst_stats.load + load;
src_load = env->src_stats.load - load;
if (moveimp > imp && moveimp > env->best_imp) {
if (!load_too_imbalanced(src_load, dst_load, env)) {
imp = moveimp - 1;
cur = NULL;
goto assign;
}
}
if (imp <= env->best_imp)
goto unlock;
if (cur) {
load = task_h_load(cur);
dst_load -= load;
src_load += load;
}
if (load_too_imbalanced(src_load, dst_load, env))
goto unlock;
if (!cur)
env->dst_cpu = select_idle_sibling(env->p, env->dst_cpu);
assign:
task_numa_assign(env, cur, imp);
unlock:
rcu_read_unlock();
}
static void task_numa_find_cpu(struct task_numa_env *env,
long taskimp, long groupimp)
{
int cpu;
for_each_cpu(cpu, cpumask_of_node(env->dst_nid)) {
if (!cpumask_test_cpu(cpu, tsk_cpus_allowed(env->p)))
continue;
env->dst_cpu = cpu;
task_numa_compare(env, taskimp, groupimp);
}
}
static int task_numa_migrate(struct task_struct *p)
{
struct task_numa_env env = {
.p = p,
.src_cpu = task_cpu(p),
.src_nid = task_node(p),
.imbalance_pct = 112,
.best_task = NULL,
.best_imp = 0,
.best_cpu = -1
};
struct sched_domain *sd;
unsigned long taskweight, groupweight;
int nid, ret, dist;
long taskimp, groupimp;
rcu_read_lock();
sd = rcu_dereference(per_cpu(sd_numa, env.src_cpu));
if (sd)
env.imbalance_pct = 100 + (sd->imbalance_pct - 100) / 2;
rcu_read_unlock();
if (unlikely(!sd)) {
p->numa_preferred_nid = task_node(p);
return -EINVAL;
}
env.dst_nid = p->numa_preferred_nid;
dist = env.dist = node_distance(env.src_nid, env.dst_nid);
taskweight = task_weight(p, env.src_nid, dist);
groupweight = group_weight(p, env.src_nid, dist);
update_numa_stats(&env.src_stats, env.src_nid);
taskimp = task_weight(p, env.dst_nid, dist) - taskweight;
groupimp = group_weight(p, env.dst_nid, dist) - groupweight;
update_numa_stats(&env.dst_stats, env.dst_nid);
task_numa_find_cpu(&env, taskimp, groupimp);
if (env.best_cpu == -1 || (p->numa_group &&
nodes_weight(p->numa_group->active_nodes) > 1)) {
for_each_online_node(nid) {
if (nid == env.src_nid || nid == p->numa_preferred_nid)
continue;
dist = node_distance(env.src_nid, env.dst_nid);
if (sched_numa_topology_type == NUMA_BACKPLANE &&
dist != env.dist) {
taskweight = task_weight(p, env.src_nid, dist);
groupweight = group_weight(p, env.src_nid, dist);
}
taskimp = task_weight(p, nid, dist) - taskweight;
groupimp = group_weight(p, nid, dist) - groupweight;
if (taskimp < 0 && groupimp < 0)
continue;
env.dist = dist;
env.dst_nid = nid;
update_numa_stats(&env.dst_stats, env.dst_nid);
task_numa_find_cpu(&env, taskimp, groupimp);
}
}
if (p->numa_group) {
if (env.best_cpu == -1)
nid = env.src_nid;
else
nid = env.dst_nid;
if (node_isset(nid, p->numa_group->active_nodes))
sched_setnuma(p, env.dst_nid);
}
if (env.best_cpu == -1)
return -EAGAIN;
p->numa_scan_period = task_scan_min(p);
if (env.best_task == NULL) {
ret = migrate_task_to(p, env.best_cpu);
if (ret != 0)
trace_sched_stick_numa(p, env.src_cpu, env.best_cpu);
return ret;
}
ret = migrate_swap(p, env.best_task);
if (ret != 0)
trace_sched_stick_numa(p, env.src_cpu, task_cpu(env.best_task));
put_task_struct(env.best_task);
return ret;
}
static void numa_migrate_preferred(struct task_struct *p)
{
unsigned long interval = HZ;
if (unlikely(p->numa_preferred_nid == -1 || !p->numa_faults))
return;
interval = min(interval, msecs_to_jiffies(p->numa_scan_period) / 16);
p->numa_migrate_retry = jiffies + interval;
if (task_node(p) == p->numa_preferred_nid)
return;
task_numa_migrate(p);
}
static void update_numa_active_node_mask(struct numa_group *numa_group)
{
unsigned long faults, max_faults = 0;
int nid;
for_each_online_node(nid) {
faults = group_faults_cpu(numa_group, nid);
if (faults > max_faults)
max_faults = faults;
}
for_each_online_node(nid) {
faults = group_faults_cpu(numa_group, nid);
if (!node_isset(nid, numa_group->active_nodes)) {
if (faults > max_faults * 6 / 16)
node_set(nid, numa_group->active_nodes);
} else if (faults < max_faults * 3 / 16)
node_clear(nid, numa_group->active_nodes);
}
}
static void update_task_scan_period(struct task_struct *p,
unsigned long shared, unsigned long private)
{
unsigned int period_slot;
int ratio;
int diff;
unsigned long remote = p->numa_faults_locality[0];
unsigned long local = p->numa_faults_locality[1];
if (local + shared == 0) {
p->numa_scan_period = min(p->numa_scan_period_max,
p->numa_scan_period << 1);
p->mm->numa_next_scan = jiffies +
msecs_to_jiffies(p->numa_scan_period);
return;
}
period_slot = DIV_ROUND_UP(p->numa_scan_period, NUMA_PERIOD_SLOTS);
ratio = (local * NUMA_PERIOD_SLOTS) / (local + remote);
if (ratio >= NUMA_PERIOD_THRESHOLD) {
int slot = ratio - NUMA_PERIOD_THRESHOLD;
if (!slot)
slot = 1;
diff = slot * period_slot;
} else {
diff = -(NUMA_PERIOD_THRESHOLD - ratio) * period_slot;
ratio = DIV_ROUND_UP(private * NUMA_PERIOD_SLOTS, (private + shared + 1));
diff = (diff * ratio) / NUMA_PERIOD_SLOTS;
}
p->numa_scan_period = clamp(p->numa_scan_period + diff,
task_scan_min(p), task_scan_max(p));
memset(p->numa_faults_locality, 0, sizeof(p->numa_faults_locality));
}
static u64 numa_get_avg_runtime(struct task_struct *p, u64 *period)
{
u64 runtime, delta, now;
now = p->se.exec_start;
runtime = p->se.sum_exec_runtime;
if (p->last_task_numa_placement) {
delta = runtime - p->last_sum_exec_runtime;
*period = now - p->last_task_numa_placement;
} else {
delta = p->se.avg.runnable_avg_sum;
*period = p->se.avg.runnable_avg_period;
}
p->last_sum_exec_runtime = runtime;
p->last_task_numa_placement = now;
return delta;
}
static int preferred_group_nid(struct task_struct *p, int nid)
{
nodemask_t nodes;
int dist;
if (sched_numa_topology_type == NUMA_DIRECT)
return nid;
if (sched_numa_topology_type == NUMA_GLUELESS_MESH) {
unsigned long score, max_score = 0;
int node, max_node = nid;
dist = sched_max_numa_distance;
for_each_online_node(node) {
score = group_weight(p, node, dist);
if (score > max_score) {
max_score = score;
max_node = node;
}
}
return max_node;
}
nodes = node_online_map;
for (dist = sched_max_numa_distance; dist > LOCAL_DISTANCE; dist--) {
unsigned long max_faults = 0;
nodemask_t max_group = NODE_MASK_NONE;
int a, b;
if (!find_numa_distance(dist))
continue;
for_each_node_mask(a, nodes) {
unsigned long faults = 0;
nodemask_t this_group;
nodes_clear(this_group);
for_each_node_mask(b, nodes) {
if (node_distance(a, b) < dist) {
faults += group_faults(p, b);
node_set(b, this_group);
node_clear(b, nodes);
}
}
if (faults > max_faults) {
max_faults = faults;
max_group = this_group;
nid = a;
}
}
nodes = max_group;
}
return nid;
}
static void task_numa_placement(struct task_struct *p)
{
int seq, nid, max_nid = -1, max_group_nid = -1;
unsigned long max_faults = 0, max_group_faults = 0;
unsigned long fault_types[2] = { 0, 0 };
unsigned long total_faults;
u64 runtime, period;
spinlock_t *group_lock = NULL;
seq = ACCESS_ONCE(p->mm->numa_scan_seq);
if (p->numa_scan_seq == seq)
return;
p->numa_scan_seq = seq;
p->numa_scan_period_max = task_scan_max(p);
total_faults = p->numa_faults_locality[0] +
p->numa_faults_locality[1];
runtime = numa_get_avg_runtime(p, &period);
if (p->numa_group) {
group_lock = &p->numa_group->lock;
spin_lock_irq(group_lock);
}
for_each_online_node(nid) {
int mem_idx, membuf_idx, cpu_idx, cpubuf_idx;
unsigned long faults = 0, group_faults = 0;
int priv;
for (priv = 0; priv < NR_NUMA_HINT_FAULT_TYPES; priv++) {
long diff, f_diff, f_weight;
mem_idx = task_faults_idx(NUMA_MEM, nid, priv);
membuf_idx = task_faults_idx(NUMA_MEMBUF, nid, priv);
cpu_idx = task_faults_idx(NUMA_CPU, nid, priv);
cpubuf_idx = task_faults_idx(NUMA_CPUBUF, nid, priv);
diff = p->numa_faults[membuf_idx] - p->numa_faults[mem_idx] / 2;
fault_types[priv] += p->numa_faults[membuf_idx];
p->numa_faults[membuf_idx] = 0;
f_weight = div64_u64(runtime << 16, period + 1);
f_weight = (f_weight * p->numa_faults[cpubuf_idx]) /
(total_faults + 1);
f_diff = f_weight - p->numa_faults[cpu_idx] / 2;
p->numa_faults[cpubuf_idx] = 0;
p->numa_faults[mem_idx] += diff;
p->numa_faults[cpu_idx] += f_diff;
faults += p->numa_faults[mem_idx];
p->total_numa_faults += diff;
if (p->numa_group) {
p->numa_group->faults[mem_idx] += diff;
p->numa_group->faults_cpu[mem_idx] += f_diff;
p->numa_group->total_faults += diff;
group_faults += p->numa_group->faults[mem_idx];
}
}
if (faults > max_faults) {
max_faults = faults;
max_nid = nid;
}
if (group_faults > max_group_faults) {
max_group_faults = group_faults;
max_group_nid = nid;
}
}
update_task_scan_period(p, fault_types[0], fault_types[1]);
if (p->numa_group) {
update_numa_active_node_mask(p->numa_group);
spin_unlock_irq(group_lock);
max_nid = preferred_group_nid(p, max_group_nid);
}
if (max_faults) {
if (max_nid != p->numa_preferred_nid)
sched_setnuma(p, max_nid);
if (task_node(p) != p->numa_preferred_nid)
numa_migrate_preferred(p);
}
}
static inline int get_numa_group(struct numa_group *grp)
{
return atomic_inc_not_zero(&grp->refcount);
}
static inline void put_numa_group(struct numa_group *grp)
{
if (atomic_dec_and_test(&grp->refcount))
kfree_rcu(grp, rcu);
}
static void task_numa_group(struct task_struct *p, int cpupid, int flags,
int *priv)
{
struct numa_group *grp, *my_grp;
struct task_struct *tsk;
bool join = false;
int cpu = cpupid_to_cpu(cpupid);
int i;
if (unlikely(!p->numa_group)) {
unsigned int size = sizeof(struct numa_group) +
4*nr_node_ids*sizeof(unsigned long);
grp = kzalloc(size, GFP_KERNEL | __GFP_NOWARN);
if (!grp)
return;
atomic_set(&grp->refcount, 1);
spin_lock_init(&grp->lock);
grp->gid = p->pid;
grp->faults_cpu = grp->faults + NR_NUMA_HINT_FAULT_TYPES *
nr_node_ids;
node_set(task_node(current), grp->active_nodes);
for (i = 0; i < NR_NUMA_HINT_FAULT_STATS * nr_node_ids; i++)
grp->faults[i] = p->numa_faults[i];
grp->total_faults = p->total_numa_faults;
grp->nr_tasks++;
rcu_assign_pointer(p->numa_group, grp);
}
rcu_read_lock();
tsk = ACCESS_ONCE(cpu_rq(cpu)->curr);
if (!cpupid_match_pid(tsk, cpupid))
goto no_join;
grp = rcu_dereference(tsk->numa_group);
if (!grp)
goto no_join;
my_grp = p->numa_group;
if (grp == my_grp)
goto no_join;
if (my_grp->nr_tasks > grp->nr_tasks)
goto no_join;
if (my_grp->nr_tasks == grp->nr_tasks && my_grp > grp)
goto no_join;
if (tsk->mm == current->mm)
join = true;
if (flags & TNF_SHARED)
join = true;
*priv = !join;
if (join && !get_numa_group(grp))
goto no_join;
rcu_read_unlock();
if (!join)
return;
BUG_ON(irqs_disabled());
double_lock_irq(&my_grp->lock, &grp->lock);
for (i = 0; i < NR_NUMA_HINT_FAULT_STATS * nr_node_ids; i++) {
my_grp->faults[i] -= p->numa_faults[i];
grp->faults[i] += p->numa_faults[i];
}
my_grp->total_faults -= p->total_numa_faults;
grp->total_faults += p->total_numa_faults;
my_grp->nr_tasks--;
grp->nr_tasks++;
spin_unlock(&my_grp->lock);
spin_unlock_irq(&grp->lock);
rcu_assign_pointer(p->numa_group, grp);
put_numa_group(my_grp);
return;
no_join:
rcu_read_unlock();
return;
}
void task_numa_free(struct task_struct *p)
{
struct numa_group *grp = p->numa_group;
void *numa_faults = p->numa_faults;
unsigned long flags;
int i;
if (grp) {
spin_lock_irqsave(&grp->lock, flags);
for (i = 0; i < NR_NUMA_HINT_FAULT_STATS * nr_node_ids; i++)
grp->faults[i] -= p->numa_faults[i];
grp->total_faults -= p->total_numa_faults;
grp->nr_tasks--;
spin_unlock_irqrestore(&grp->lock, flags);
RCU_INIT_POINTER(p->numa_group, NULL);
put_numa_group(grp);
}
p->numa_faults = NULL;
kfree(numa_faults);
}
void task_numa_fault(int last_cpupid, int mem_node, int pages, int flags)
{
struct task_struct *p = current;
bool migrated = flags & TNF_MIGRATED;
int cpu_node = task_node(current);
int local = !!(flags & TNF_FAULT_LOCAL);
int priv;
if (!numabalancing_enabled)
return;
if (!p->mm)
return;
if (unlikely(!p->numa_faults)) {
int size = sizeof(*p->numa_faults) *
NR_NUMA_HINT_FAULT_BUCKETS * nr_node_ids;
p->numa_faults = kzalloc(size, GFP_KERNEL|__GFP_NOWARN);
if (!p->numa_faults)
return;
p->total_numa_faults = 0;
memset(p->numa_faults_locality, 0, sizeof(p->numa_faults_locality));
}
if (unlikely(last_cpupid == (-1 & LAST_CPUPID_MASK))) {
priv = 1;
} else {
priv = cpupid_match_pid(p, last_cpupid);
if (!priv && !(flags & TNF_NO_GROUP))
task_numa_group(p, last_cpupid, flags, &priv);
}
if (!priv && !local && p->numa_group &&
node_isset(cpu_node, p->numa_group->active_nodes) &&
node_isset(mem_node, p->numa_group->active_nodes))
local = 1;
task_numa_placement(p);
if (time_after(jiffies, p->numa_migrate_retry))
numa_migrate_preferred(p);
if (migrated)
p->numa_pages_migrated += pages;
p->numa_faults[task_faults_idx(NUMA_MEMBUF, mem_node, priv)] += pages;
p->numa_faults[task_faults_idx(NUMA_CPUBUF, cpu_node, priv)] += pages;
p->numa_faults_locality[local] += pages;
}
static void reset_ptenuma_scan(struct task_struct *p)
{
ACCESS_ONCE(p->mm->numa_scan_seq)++;
p->mm->numa_scan_offset = 0;
}
void task_numa_work(struct callback_head *work)
{
unsigned long migrate, next_scan, now = jiffies;
struct task_struct *p = current;
struct mm_struct *mm = p->mm;
struct vm_area_struct *vma;
unsigned long start, end;
unsigned long nr_pte_updates = 0;
long pages;
WARN_ON_ONCE(p != container_of(work, struct task_struct, numa_work));
work->next = work;
if (p->flags & PF_EXITING)
return;
if (!mm->numa_next_scan) {
mm->numa_next_scan = now +
msecs_to_jiffies(sysctl_numa_balancing_scan_delay);
}
migrate = mm->numa_next_scan;
if (time_before(now, migrate))
return;
if (p->numa_scan_period == 0) {
p->numa_scan_period_max = task_scan_max(p);
p->numa_scan_period = task_scan_min(p);
}
next_scan = now + msecs_to_jiffies(p->numa_scan_period);
if (cmpxchg(&mm->numa_next_scan, migrate, next_scan) != migrate)
return;
p->node_stamp += 2 * TICK_NSEC;
start = mm->numa_scan_offset;
pages = sysctl_numa_balancing_scan_size;
pages <<= 20 - PAGE_SHIFT;
if (!pages)
return;
down_read(&mm->mmap_sem);
vma = find_vma(mm, start);
if (!vma) {
reset_ptenuma_scan(p);
start = 0;
vma = mm->mmap;
}
for (; vma; vma = vma->vm_next) {
if (!vma_migratable(vma) || !vma_policy_mof(vma))
continue;
if (!vma->vm_mm ||
(vma->vm_file && (vma->vm_flags & (VM_READ|VM_WRITE)) == (VM_READ)))
continue;
if (!(vma->vm_flags & (VM_READ | VM_EXEC | VM_WRITE)))
continue;
do {
start = max(start, vma->vm_start);
end = ALIGN(start + (pages << PAGE_SHIFT), HPAGE_SIZE);
end = min(end, vma->vm_end);
nr_pte_updates += change_prot_numa(vma, start, end);
if (nr_pte_updates)
pages -= (end - start) >> PAGE_SHIFT;
start = end;
if (pages <= 0)
goto out;
cond_resched();
} while (end != vma->vm_end);
}
out:
if (vma)
mm->numa_scan_offset = start;
else
reset_ptenuma_scan(p);
up_read(&mm->mmap_sem);
}
void task_tick_numa(struct rq *rq, struct task_struct *curr)
{
struct callback_head *work = &curr->numa_work;
u64 period, now;
if (!curr->mm || (curr->flags & PF_EXITING) || work->next != work)
return;
now = curr->se.sum_exec_runtime;
period = (u64)curr->numa_scan_period * NSEC_PER_MSEC;
if (now - curr->node_stamp > period) {
if (!curr->node_stamp)
curr->numa_scan_period = task_scan_min(curr);
curr->node_stamp += period;
if (!time_before(jiffies, curr->mm->numa_next_scan)) {
init_task_work(work, task_numa_work);
task_work_add(curr, work, true);
}
}
}
static void task_tick_numa(struct rq *rq, struct task_struct *curr)
{
}
static inline void account_numa_enqueue(struct rq *rq, struct task_struct *p)
{
}
static inline void account_numa_dequeue(struct rq *rq, struct task_struct *p)
{
}
static void
account_entity_enqueue(struct cfs_rq *cfs_rq, struct sched_entity *se)
{
update_load_add(&cfs_rq->load, se->load.weight);
if (!parent_entity(se))
update_load_add(&rq_of(cfs_rq)->load, se->load.weight);
#ifdef CONFIG_SMP
if (entity_is_task(se)) {
struct rq *rq = rq_of(cfs_rq);
account_numa_enqueue(rq, task_of(se));
list_add(&se->group_node, &rq->cfs_tasks);
}
#endif
cfs_rq->nr_running++;
}
static void
account_entity_dequeue(struct cfs_rq *cfs_rq, struct sched_entity *se)
{
update_load_sub(&cfs_rq->load, se->load.weight);
if (!parent_entity(se))
update_load_sub(&rq_of(cfs_rq)->load, se->load.weight);
if (entity_is_task(se)) {
account_numa_dequeue(rq_of(cfs_rq), task_of(se));
list_del_init(&se->group_node);
}
cfs_rq->nr_running--;
}
static inline long calc_tg_weight(struct task_group *tg, struct cfs_rq *cfs_rq)
{
long tg_weight;
tg_weight = atomic_long_read(&tg->load_avg);
tg_weight -= cfs_rq->tg_load_contrib;
tg_weight += cfs_rq->load.weight;
return tg_weight;
}
static long calc_cfs_shares(struct cfs_rq *cfs_rq, struct task_group *tg)
{
long tg_weight, load, shares;
tg_weight = calc_tg_weight(tg, cfs_rq);
load = cfs_rq->load.weight;
shares = (tg->shares * load);
if (tg_weight)
shares /= tg_weight;
if (shares < MIN_SHARES)
shares = MIN_SHARES;
if (shares > tg->shares)
shares = tg->shares;
return shares;
}
static inline long calc_cfs_shares(struct cfs_rq *cfs_rq, struct task_group *tg)
{
return tg->shares;
}
static void reweight_entity(struct cfs_rq *cfs_rq, struct sched_entity *se,
unsigned long weight)
{
if (se->on_rq) {
if (cfs_rq->curr == se)
update_curr(cfs_rq);
account_entity_dequeue(cfs_rq, se);
}
update_load_set(&se->load, weight);
if (se->on_rq)
account_entity_enqueue(cfs_rq, se);
}
static void update_cfs_shares(struct cfs_rq *cfs_rq)
{
struct task_group *tg;
struct sched_entity *se;
long shares;
tg = cfs_rq->tg;
se = tg->se[cpu_of(rq_of(cfs_rq))];
if (!se || throttled_hierarchy(cfs_rq))
return;
#ifndef CONFIG_SMP
if (likely(se->load.weight == tg->shares))
return;
#endif
shares = calc_cfs_shares(cfs_rq, tg);
reweight_entity(cfs_rq_of(se), se, shares);
}
static inline void update_cfs_shares(struct cfs_rq *cfs_rq)
{
}
static __always_inline u64 decay_load(u64 val, u64 n)
{
unsigned int local_n;
if (!n)
return val;
else if (unlikely(n > LOAD_AVG_PERIOD * 63))
return 0;
local_n = n;
if (unlikely(local_n >= LOAD_AVG_PERIOD)) {
val >>= local_n / LOAD_AVG_PERIOD;
local_n %= LOAD_AVG_PERIOD;
}
val *= runnable_avg_yN_inv[local_n];
return val >> 32;
}
static u32 __compute_runnable_contrib(u64 n)
{
u32 contrib = 0;
if (likely(n <= LOAD_AVG_PERIOD))
return runnable_avg_yN_sum[n];
else if (unlikely(n >= LOAD_AVG_MAX_N))
return LOAD_AVG_MAX;
do {
contrib /= 2;
contrib += runnable_avg_yN_sum[LOAD_AVG_PERIOD];
n -= LOAD_AVG_PERIOD;
} while (n > LOAD_AVG_PERIOD);
contrib = decay_load(contrib, n);
return contrib + runnable_avg_yN_sum[n];
}
static __always_inline int __update_entity_runnable_avg(u64 now,
struct sched_avg *sa,
int runnable)
{
u64 delta, periods;
u32 runnable_contrib;
int delta_w, decayed = 0;
delta = now - sa->last_runnable_update;
if ((s64)delta < 0) {
sa->last_runnable_update = now;
return 0;
}
delta >>= 10;
if (!delta)
return 0;
sa->last_runnable_update = now;
delta_w = sa->runnable_avg_period % 1024;
if (delta + delta_w >= 1024) {
decayed = 1;
delta_w = 1024 - delta_w;
if (runnable)
sa->runnable_avg_sum += delta_w;
sa->runnable_avg_period += delta_w;
delta -= delta_w;
periods = delta / 1024;
delta %= 1024;
sa->runnable_avg_sum = decay_load(sa->runnable_avg_sum,
periods + 1);
sa->runnable_avg_period = decay_load(sa->runnable_avg_period,
periods + 1);
runnable_contrib = __compute_runnable_contrib(periods);
if (runnable)
sa->runnable_avg_sum += runnable_contrib;
sa->runnable_avg_period += runnable_contrib;
}
if (runnable)
sa->runnable_avg_sum += delta;
sa->runnable_avg_period += delta;
return decayed;
}
static inline u64 __synchronize_entity_decay(struct sched_entity *se)
{
struct cfs_rq *cfs_rq = cfs_rq_of(se);
u64 decays = atomic64_read(&cfs_rq->decay_counter);
decays -= se->avg.decay_count;
if (!decays)
return 0;
se->avg.load_avg_contrib = decay_load(se->avg.load_avg_contrib, decays);
se->avg.decay_count = 0;
return decays;
}
static inline void __update_cfs_rq_tg_load_contrib(struct cfs_rq *cfs_rq,
int force_update)
{
struct task_group *tg = cfs_rq->tg;
long tg_contrib;
tg_contrib = cfs_rq->runnable_load_avg + cfs_rq->blocked_load_avg;
tg_contrib -= cfs_rq->tg_load_contrib;
if (!tg_contrib)
return;
if (force_update || abs(tg_contrib) > cfs_rq->tg_load_contrib / 8) {
atomic_long_add(tg_contrib, &tg->load_avg);
cfs_rq->tg_load_contrib += tg_contrib;
}
}
static inline void __update_tg_runnable_avg(struct sched_avg *sa,
struct cfs_rq *cfs_rq)
{
struct task_group *tg = cfs_rq->tg;
long contrib;
contrib = div_u64((u64)sa->runnable_avg_sum << NICE_0_SHIFT,
sa->runnable_avg_period + 1);
contrib -= cfs_rq->tg_runnable_contrib;
if (abs(contrib) > cfs_rq->tg_runnable_contrib / 64) {
atomic_add(contrib, &tg->runnable_avg);
cfs_rq->tg_runnable_contrib += contrib;
}
}
static inline void __update_group_entity_contrib(struct sched_entity *se)
{
struct cfs_rq *cfs_rq = group_cfs_rq(se);
struct task_group *tg = cfs_rq->tg;
int runnable_avg;
u64 contrib;
contrib = cfs_rq->tg_load_contrib * tg->shares;
se->avg.load_avg_contrib = div_u64(contrib,
atomic_long_read(&tg->load_avg) + 1);
runnable_avg = atomic_read(&tg->runnable_avg);
if (runnable_avg < NICE_0_LOAD) {
se->avg.load_avg_contrib *= runnable_avg;
se->avg.load_avg_contrib >>= NICE_0_SHIFT;
}
}
static inline void update_rq_runnable_avg(struct rq *rq, int runnable)
{
__update_entity_runnable_avg(rq_clock_task(rq), &rq->avg, runnable);
__update_tg_runnable_avg(&rq->avg, &rq->cfs);
}
static inline void __update_cfs_rq_tg_load_contrib(struct cfs_rq *cfs_rq,
int force_update) {}
static inline void __update_tg_runnable_avg(struct sched_avg *sa,
struct cfs_rq *cfs_rq) {}
static inline void __update_group_entity_contrib(struct sched_entity *se) {}
static inline void update_rq_runnable_avg(struct rq *rq, int runnable) {}
static inline void __update_task_entity_contrib(struct sched_entity *se)
{
u32 contrib;
contrib = se->avg.runnable_avg_sum * scale_load_down(se->load.weight);
contrib /= (se->avg.runnable_avg_period + 1);
se->avg.load_avg_contrib = scale_load(contrib);
}
static long __update_entity_load_avg_contrib(struct sched_entity *se)
{
long old_contrib = se->avg.load_avg_contrib;
if (entity_is_task(se)) {
__update_task_entity_contrib(se);
} else {
__update_tg_runnable_avg(&se->avg, group_cfs_rq(se));
__update_group_entity_contrib(se);
}
return se->avg.load_avg_contrib - old_contrib;
}
static inline void subtract_blocked_load_contrib(struct cfs_rq *cfs_rq,
long load_contrib)
{
if (likely(load_contrib < cfs_rq->blocked_load_avg))
cfs_rq->blocked_load_avg -= load_contrib;
else
cfs_rq->blocked_load_avg = 0;
}
static inline void update_entity_load_avg(struct sched_entity *se,
int update_cfs_rq)
{
struct cfs_rq *cfs_rq = cfs_rq_of(se);
long contrib_delta;
u64 now;
if (entity_is_task(se))
now = cfs_rq_clock_task(cfs_rq);
else
now = cfs_rq_clock_task(group_cfs_rq(se));
if (!__update_entity_runnable_avg(now, &se->avg, se->on_rq))
return;
contrib_delta = __update_entity_load_avg_contrib(se);
if (!update_cfs_rq)
return;
if (se->on_rq)
cfs_rq->runnable_load_avg += contrib_delta;
else
subtract_blocked_load_contrib(cfs_rq, -contrib_delta);
}
static void update_cfs_rq_blocked_load(struct cfs_rq *cfs_rq, int force_update)
{
u64 now = cfs_rq_clock_task(cfs_rq) >> 20;
u64 decays;
decays = now - cfs_rq->last_decay;
if (!decays && !force_update)
return;
if (atomic_long_read(&cfs_rq->removed_load)) {
unsigned long removed_load;
removed_load = atomic_long_xchg(&cfs_rq->removed_load, 0);
subtract_blocked_load_contrib(cfs_rq, removed_load);
}
if (decays) {
cfs_rq->blocked_load_avg = decay_load(cfs_rq->blocked_load_avg,
decays);
atomic64_add(decays, &cfs_rq->decay_counter);
cfs_rq->last_decay = now;
}
__update_cfs_rq_tg_load_contrib(cfs_rq, force_update);
}
static inline void enqueue_entity_load_avg(struct cfs_rq *cfs_rq,
struct sched_entity *se,
int wakeup)
{
if (unlikely(se->avg.decay_count <= 0)) {
se->avg.last_runnable_update = rq_clock_task(rq_of(cfs_rq));
if (se->avg.decay_count) {
se->avg.last_runnable_update -= (-se->avg.decay_count)
<< 20;
update_entity_load_avg(se, 0);
se->avg.decay_count = 0;
}
wakeup = 0;
} else {
__synchronize_entity_decay(se);
}
if (wakeup) {
subtract_blocked_load_contrib(cfs_rq, se->avg.load_avg_contrib);
update_entity_load_avg(se, 0);
}
cfs_rq->runnable_load_avg += se->avg.load_avg_contrib;
update_cfs_rq_blocked_load(cfs_rq, !wakeup);
}
static inline void dequeue_entity_load_avg(struct cfs_rq *cfs_rq,
struct sched_entity *se,
int sleep)
{
update_entity_load_avg(se, 1);
update_cfs_rq_blocked_load(cfs_rq, !sleep);
cfs_rq->runnable_load_avg -= se->avg.load_avg_contrib;
if (sleep) {
cfs_rq->blocked_load_avg += se->avg.load_avg_contrib;
se->avg.decay_count = atomic64_read(&cfs_rq->decay_counter);
}
}
void idle_enter_fair(struct rq *this_rq)
{
update_rq_runnable_avg(this_rq, 1);
}
void idle_exit_fair(struct rq *this_rq)
{
update_rq_runnable_avg(this_rq, 0);
}
static inline void update_entity_load_avg(struct sched_entity *se,
int update_cfs_rq) {}
static inline void update_rq_runnable_avg(struct rq *rq, int runnable) {}
static inline void enqueue_entity_load_avg(struct cfs_rq *cfs_rq,
struct sched_entity *se,
int wakeup) {}
static inline void dequeue_entity_load_avg(struct cfs_rq *cfs_rq,
struct sched_entity *se,
int sleep) {}
static inline void update_cfs_rq_blocked_load(struct cfs_rq *cfs_rq,
int force_update) {}
static inline int idle_balance(struct rq *rq)
{
return 0;
}
static void enqueue_sleeper(struct cfs_rq *cfs_rq, struct sched_entity *se)
{
#ifdef CONFIG_SCHEDSTATS
struct task_struct *tsk = NULL;
if (entity_is_task(se))
tsk = task_of(se);
if (se->statistics.sleep_start) {
u64 delta = rq_clock(rq_of(cfs_rq)) - se->statistics.sleep_start;
if ((s64)delta < 0)
delta = 0;
if (unlikely(delta > se->statistics.sleep_max))
se->statistics.sleep_max = delta;
se->statistics.sleep_start = 0;
se->statistics.sum_sleep_runtime += delta;
if (tsk) {
account_scheduler_latency(tsk, delta >> 10, 1);
trace_sched_stat_sleep(tsk, delta);
}
}
if (se->statistics.block_start) {
u64 delta = rq_clock(rq_of(cfs_rq)) - se->statistics.block_start;
if ((s64)delta < 0)
delta = 0;
if (unlikely(delta > se->statistics.block_max))
se->statistics.block_max = delta;
se->statistics.block_start = 0;
se->statistics.sum_sleep_runtime += delta;
if (tsk) {
if (tsk->in_iowait) {
se->statistics.iowait_sum += delta;
se->statistics.iowait_count++;
trace_sched_stat_iowait(tsk, delta);
}
trace_sched_stat_blocked(tsk, delta);
if (unlikely(prof_on == SLEEP_PROFILING)) {
profile_hits(SLEEP_PROFILING,
(void *)get_wchan(tsk),
delta >> 20);
}
account_scheduler_latency(tsk, delta >> 10, 0);
}
}
#endif
}
static void check_spread(struct cfs_rq *cfs_rq, struct sched_entity *se)
{
#ifdef CONFIG_SCHED_DEBUG
s64 d = se->vruntime - cfs_rq->min_vruntime;
if (d < 0)
d = -d;
if (d > 3*sysctl_sched_latency)
schedstat_inc(cfs_rq, nr_spread_over);
#endif
}
static void
place_entity(struct cfs_rq *cfs_rq, struct sched_entity *se, int initial)
{
u64 vruntime = cfs_rq->min_vruntime;
if (initial && sched_feat(START_DEBIT))
vruntime += sched_vslice(cfs_rq, se);
if (!initial) {
unsigned long thresh = sysctl_sched_latency;
if (sched_feat(GENTLE_FAIR_SLEEPERS))
thresh >>= 1;
vruntime -= thresh;
}
se->vruntime = max_vruntime(se->vruntime, vruntime);
}
static void
enqueue_entity(struct cfs_rq *cfs_rq, struct sched_entity *se, int flags)
{
if (!(flags & ENQUEUE_WAKEUP) || (flags & ENQUEUE_WAKING))
se->vruntime += cfs_rq->min_vruntime;
update_curr(cfs_rq);
enqueue_entity_load_avg(cfs_rq, se, flags & ENQUEUE_WAKEUP);
account_entity_enqueue(cfs_rq, se);
update_cfs_shares(cfs_rq);
if (flags & ENQUEUE_WAKEUP) {
place_entity(cfs_rq, se, 0);
enqueue_sleeper(cfs_rq, se);
}
update_stats_enqueue(cfs_rq, se);
check_spread(cfs_rq, se);
if (se != cfs_rq->curr)
__enqueue_entity(cfs_rq, se);
se->on_rq = 1;
if (cfs_rq->nr_running == 1) {
list_add_leaf_cfs_rq(cfs_rq);
check_enqueue_throttle(cfs_rq);
}
}
static void __clear_buddies_last(struct sched_entity *se)
{
for_each_sched_entity(se) {
struct cfs_rq *cfs_rq = cfs_rq_of(se);
if (cfs_rq->last != se)
break;
cfs_rq->last = NULL;
}
}
static void __clear_buddies_next(struct sched_entity *se)
{
for_each_sched_entity(se) {
struct cfs_rq *cfs_rq = cfs_rq_of(se);
if (cfs_rq->next != se)
break;
cfs_rq->next = NULL;
}
}
static void __clear_buddies_skip(struct sched_entity *se)
{
for_each_sched_entity(se) {
struct cfs_rq *cfs_rq = cfs_rq_of(se);
if (cfs_rq->skip != se)
break;
cfs_rq->skip = NULL;
}
}
static void clear_buddies(struct cfs_rq *cfs_rq, struct sched_entity *se)
{
if (cfs_rq->last == se)
__clear_buddies_last(se);
if (cfs_rq->next == se)
__clear_buddies_next(se);
if (cfs_rq->skip == se)
__clear_buddies_skip(se);
}
static void
dequeue_entity(struct cfs_rq *cfs_rq, struct sched_entity *se, int flags)
{
update_curr(cfs_rq);
dequeue_entity_load_avg(cfs_rq, se, flags & DEQUEUE_SLEEP);
update_stats_dequeue(cfs_rq, se);
if (flags & DEQUEUE_SLEEP) {
#ifdef CONFIG_SCHEDSTATS
if (entity_is_task(se)) {
struct task_struct *tsk = task_of(se);
if (tsk->state & TASK_INTERRUPTIBLE)
se->statistics.sleep_start = rq_clock(rq_of(cfs_rq));
if (tsk->state & TASK_UNINTERRUPTIBLE)
se->statistics.block_start = rq_clock(rq_of(cfs_rq));
}
#endif
}
clear_buddies(cfs_rq, se);
if (se != cfs_rq->curr)
__dequeue_entity(cfs_rq, se);
se->on_rq = 0;
account_entity_dequeue(cfs_rq, se);
if (!(flags & DEQUEUE_SLEEP))
se->vruntime -= cfs_rq->min_vruntime;
return_cfs_rq_runtime(cfs_rq);
update_min_vruntime(cfs_rq);
update_cfs_shares(cfs_rq);
}
static void
check_preempt_tick(struct cfs_rq *cfs_rq, struct sched_entity *curr)
{
unsigned long ideal_runtime, delta_exec;
struct sched_entity *se;
s64 delta;
ideal_runtime = sched_slice(cfs_rq, curr);
delta_exec = curr->sum_exec_runtime - curr->prev_sum_exec_runtime;
if (delta_exec > ideal_runtime) {
resched_curr(rq_of(cfs_rq));
clear_buddies(cfs_rq, curr);
return;
}
if (delta_exec < sysctl_sched_min_granularity)
return;
se = __pick_first_entity(cfs_rq);
delta = curr->vruntime - se->vruntime;
if (delta < 0)
return;
if (delta > ideal_runtime)
resched_curr(rq_of(cfs_rq));
}
static void
set_next_entity(struct cfs_rq *cfs_rq, struct sched_entity *se)
{
if (se->on_rq) {
update_stats_wait_end(cfs_rq, se);
__dequeue_entity(cfs_rq, se);
}
update_stats_curr_start(cfs_rq, se);
cfs_rq->curr = se;
#ifdef CONFIG_SCHEDSTATS
if (rq_of(cfs_rq)->load.weight >= 2*se->load.weight) {
se->statistics.slice_max = max(se->statistics.slice_max,
se->sum_exec_runtime - se->prev_sum_exec_runtime);
}
#endif
se->prev_sum_exec_runtime = se->sum_exec_runtime;
}
static struct sched_entity *
pick_next_entity(struct cfs_rq *cfs_rq, struct sched_entity *curr)
{
struct sched_entity *left = __pick_first_entity(cfs_rq);
struct sched_entity *se;
if (!left || (curr && entity_before(curr, left)))
left = curr;
se = left;
if (cfs_rq->skip == se) {
struct sched_entity *second;
if (se == curr) {
second = __pick_first_entity(cfs_rq);
} else {
second = __pick_next_entity(se);
if (!second || (curr && entity_before(curr, second)))
second = curr;
}
if (second && wakeup_preempt_entity(second, left) < 1)
se = second;
}
if (cfs_rq->last && wakeup_preempt_entity(cfs_rq->last, left) < 1)
se = cfs_rq->last;
if (cfs_rq->next && wakeup_preempt_entity(cfs_rq->next, left) < 1)
se = cfs_rq->next;
clear_buddies(cfs_rq, se);
return se;
}
static void put_prev_entity(struct cfs_rq *cfs_rq, struct sched_entity *prev)
{
if (prev->on_rq)
update_curr(cfs_rq);
check_cfs_rq_runtime(cfs_rq);
check_spread(cfs_rq, prev);
if (prev->on_rq) {
update_stats_wait_start(cfs_rq, prev);
__enqueue_entity(cfs_rq, prev);
update_entity_load_avg(prev, 1);
}
cfs_rq->curr = NULL;
}
static void
entity_tick(struct cfs_rq *cfs_rq, struct sched_entity *curr, int queued)
{
update_curr(cfs_rq);
update_entity_load_avg(curr, 1);
update_cfs_rq_blocked_load(cfs_rq, 1);
update_cfs_shares(cfs_rq);
#ifdef CONFIG_SCHED_HRTICK
if (queued) {
resched_curr(rq_of(cfs_rq));
return;
}
if (!sched_feat(DOUBLE_TICK) &&
hrtimer_active(&rq_of(cfs_rq)->hrtick_timer))
return;
#endif
if (cfs_rq->nr_running > 1)
check_preempt_tick(cfs_rq, curr);
}
static inline bool cfs_bandwidth_used(void)
{
return static_key_false(&__cfs_bandwidth_used);
}
void cfs_bandwidth_usage_inc(void)
{
static_key_slow_inc(&__cfs_bandwidth_used);
}
void cfs_bandwidth_usage_dec(void)
{
static_key_slow_dec(&__cfs_bandwidth_used);
}
static bool cfs_bandwidth_used(void)
{
return true;
}
void cfs_bandwidth_usage_inc(void) {}
void cfs_bandwidth_usage_dec(void) {}
static inline u64 default_cfs_period(void)
{
return 100000000ULL;
}
static inline u64 sched_cfs_bandwidth_slice(void)
{
return (u64)sysctl_sched_cfs_bandwidth_slice * NSEC_PER_USEC;
}
void __refill_cfs_bandwidth_runtime(struct cfs_bandwidth *cfs_b)
{
u64 now;
if (cfs_b->quota == RUNTIME_INF)
return;
now = sched_clock_cpu(smp_processor_id());
cfs_b->runtime = cfs_b->quota;
cfs_b->runtime_expires = now + ktime_to_ns(cfs_b->period);
}
static inline struct cfs_bandwidth *tg_cfs_bandwidth(struct task_group *tg)
{
return &tg->cfs_bandwidth;
}
static inline u64 cfs_rq_clock_task(struct cfs_rq *cfs_rq)
{
if (unlikely(cfs_rq->throttle_count))
return cfs_rq->throttled_clock_task;
return rq_clock_task(rq_of(cfs_rq)) - cfs_rq->throttled_clock_task_time;
}
static int assign_cfs_rq_runtime(struct cfs_rq *cfs_rq)
{
struct task_group *tg = cfs_rq->tg;
struct cfs_bandwidth *cfs_b = tg_cfs_bandwidth(tg);
u64 amount = 0, min_amount, expires;
min_amount = sched_cfs_bandwidth_slice() - cfs_rq->runtime_remaining;
raw_spin_lock(&cfs_b->lock);
if (cfs_b->quota == RUNTIME_INF)
amount = min_amount;
else {
if (!cfs_b->timer_active) {
__refill_cfs_bandwidth_runtime(cfs_b);
__start_cfs_bandwidth(cfs_b, false);
}
if (cfs_b->runtime > 0) {
amount = min(cfs_b->runtime, min_amount);
cfs_b->runtime -= amount;
cfs_b->idle = 0;
}
}
expires = cfs_b->runtime_expires;
raw_spin_unlock(&cfs_b->lock);
cfs_rq->runtime_remaining += amount;
if ((s64)(expires - cfs_rq->runtime_expires) > 0)
cfs_rq->runtime_expires = expires;
return cfs_rq->runtime_remaining > 0;
}
static void expire_cfs_rq_runtime(struct cfs_rq *cfs_rq)
{
struct cfs_bandwidth *cfs_b = tg_cfs_bandwidth(cfs_rq->tg);
if (likely((s64)(rq_clock(rq_of(cfs_rq)) - cfs_rq->runtime_expires) < 0))
return;
if (cfs_rq->runtime_remaining < 0)
return;
if (cfs_rq->runtime_expires != cfs_b->runtime_expires) {
cfs_rq->runtime_expires += TICK_NSEC;
} else {
cfs_rq->runtime_remaining = 0;
}
}
static void __account_cfs_rq_runtime(struct cfs_rq *cfs_rq, u64 delta_exec)
{
cfs_rq->runtime_remaining -= delta_exec;
expire_cfs_rq_runtime(cfs_rq);
if (likely(cfs_rq->runtime_remaining > 0))
return;
if (!assign_cfs_rq_runtime(cfs_rq) && likely(cfs_rq->curr))
resched_curr(rq_of(cfs_rq));
}
static __always_inline
void account_cfs_rq_runtime(struct cfs_rq *cfs_rq, u64 delta_exec)
{
if (!cfs_bandwidth_used() || !cfs_rq->runtime_enabled)
return;
__account_cfs_rq_runtime(cfs_rq, delta_exec);
}
static inline int cfs_rq_throttled(struct cfs_rq *cfs_rq)
{
return cfs_bandwidth_used() && cfs_rq->throttled;
}
static inline int throttled_hierarchy(struct cfs_rq *cfs_rq)
{
return cfs_bandwidth_used() && cfs_rq->throttle_count;
}
static inline int throttled_lb_pair(struct task_group *tg,
int src_cpu, int dest_cpu)
{
struct cfs_rq *src_cfs_rq, *dest_cfs_rq;
src_cfs_rq = tg->cfs_rq[src_cpu];
dest_cfs_rq = tg->cfs_rq[dest_cpu];
return throttled_hierarchy(src_cfs_rq) ||
throttled_hierarchy(dest_cfs_rq);
}
static int tg_unthrottle_up(struct task_group *tg, void *data)
{
struct rq *rq = data;
struct cfs_rq *cfs_rq = tg->cfs_rq[cpu_of(rq)];
cfs_rq->throttle_count--;
#ifdef CONFIG_SMP
if (!cfs_rq->throttle_count) {
cfs_rq->throttled_clock_task_time += rq_clock_task(rq) -
cfs_rq->throttled_clock_task;
}
#endif
return 0;
}
static int tg_throttle_down(struct task_group *tg, void *data)
{
struct rq *rq = data;
struct cfs_rq *cfs_rq = tg->cfs_rq[cpu_of(rq)];
if (!cfs_rq->throttle_count)
cfs_rq->throttled_clock_task = rq_clock_task(rq);
cfs_rq->throttle_count++;
return 0;
}
static void throttle_cfs_rq(struct cfs_rq *cfs_rq)
{
struct rq *rq = rq_of(cfs_rq);
struct cfs_bandwidth *cfs_b = tg_cfs_bandwidth(cfs_rq->tg);
struct sched_entity *se;
long task_delta, dequeue = 1;
se = cfs_rq->tg->se[cpu_of(rq_of(cfs_rq))];
rcu_read_lock();
walk_tg_tree_from(cfs_rq->tg, tg_throttle_down, tg_nop, (void *)rq);
rcu_read_unlock();
task_delta = cfs_rq->h_nr_running;
for_each_sched_entity(se) {
struct cfs_rq *qcfs_rq = cfs_rq_of(se);
if (!se->on_rq)
break;
if (dequeue)
dequeue_entity(qcfs_rq, se, DEQUEUE_SLEEP);
qcfs_rq->h_nr_running -= task_delta;
if (qcfs_rq->load.weight)
dequeue = 0;
}
if (!se)
sub_nr_running(rq, task_delta);
cfs_rq->throttled = 1;
cfs_rq->throttled_clock = rq_clock(rq);
raw_spin_lock(&cfs_b->lock);
list_add_rcu(&cfs_rq->throttled_list, &cfs_b->throttled_cfs_rq);
if (!cfs_b->timer_active)
__start_cfs_bandwidth(cfs_b, false);
raw_spin_unlock(&cfs_b->lock);
}
void unthrottle_cfs_rq(struct cfs_rq *cfs_rq)
{
struct rq *rq = rq_of(cfs_rq);
struct cfs_bandwidth *cfs_b = tg_cfs_bandwidth(cfs_rq->tg);
struct sched_entity *se;
int enqueue = 1;
long task_delta;
se = cfs_rq->tg->se[cpu_of(rq)];
cfs_rq->throttled = 0;
update_rq_clock(rq);
raw_spin_lock(&cfs_b->lock);
cfs_b->throttled_time += rq_clock(rq) - cfs_rq->throttled_clock;
list_del_rcu(&cfs_rq->throttled_list);
raw_spin_unlock(&cfs_b->lock);
walk_tg_tree_from(cfs_rq->tg, tg_nop, tg_unthrottle_up, (void *)rq);
if (!cfs_rq->load.weight)
return;
task_delta = cfs_rq->h_nr_running;
for_each_sched_entity(se) {
if (se->on_rq)
enqueue = 0;
cfs_rq = cfs_rq_of(se);
if (enqueue)
enqueue_entity(cfs_rq, se, ENQUEUE_WAKEUP);
cfs_rq->h_nr_running += task_delta;
if (cfs_rq_throttled(cfs_rq))
break;
}
if (!se)
add_nr_running(rq, task_delta);
if (rq->curr == rq->idle && rq->cfs.nr_running)
resched_curr(rq);
}
static u64 distribute_cfs_runtime(struct cfs_bandwidth *cfs_b,
u64 remaining, u64 expires)
{
struct cfs_rq *cfs_rq;
u64 runtime;
u64 starting_runtime = remaining;
rcu_read_lock();
list_for_each_entry_rcu(cfs_rq, &cfs_b->throttled_cfs_rq,
throttled_list) {
struct rq *rq = rq_of(cfs_rq);
raw_spin_lock(&rq->lock);
if (!cfs_rq_throttled(cfs_rq))
goto next;
runtime = -cfs_rq->runtime_remaining + 1;
if (runtime > remaining)
runtime = remaining;
remaining -= runtime;
cfs_rq->runtime_remaining += runtime;
cfs_rq->runtime_expires = expires;
if (cfs_rq->runtime_remaining > 0)
unthrottle_cfs_rq(cfs_rq);
next:
raw_spin_unlock(&rq->lock);
if (!remaining)
break;
}
rcu_read_unlock();
return starting_runtime - remaining;
}
static int do_sched_cfs_period_timer(struct cfs_bandwidth *cfs_b, int overrun)
{
u64 runtime, runtime_expires;
int throttled;
if (cfs_b->quota == RUNTIME_INF)
goto out_deactivate;
throttled = !list_empty(&cfs_b->throttled_cfs_rq);
cfs_b->nr_periods += overrun;
if (cfs_b->idle && !throttled)
goto out_deactivate;
cfs_b->timer_active = 1;
__refill_cfs_bandwidth_runtime(cfs_b);
if (!throttled) {
cfs_b->idle = 1;
return 0;
}
cfs_b->nr_throttled += overrun;
runtime_expires = cfs_b->runtime_expires;
while (throttled && cfs_b->runtime > 0) {
runtime = cfs_b->runtime;
raw_spin_unlock(&cfs_b->lock);
runtime = distribute_cfs_runtime(cfs_b, runtime,
runtime_expires);
raw_spin_lock(&cfs_b->lock);
throttled = !list_empty(&cfs_b->throttled_cfs_rq);
cfs_b->runtime -= min(runtime, cfs_b->runtime);
}
cfs_b->idle = 0;
return 0;
out_deactivate:
cfs_b->timer_active = 0;
return 1;
}
static int runtime_refresh_within(struct cfs_bandwidth *cfs_b, u64 min_expire)
{
struct hrtimer *refresh_timer = &cfs_b->period_timer;
u64 remaining;
if (hrtimer_callback_running(refresh_timer))
return 1;
remaining = ktime_to_ns(hrtimer_expires_remaining(refresh_timer));
if (remaining < min_expire)
return 1;
return 0;
}
static void start_cfs_slack_bandwidth(struct cfs_bandwidth *cfs_b)
{
u64 min_left = cfs_bandwidth_slack_period + min_bandwidth_expiration;
if (runtime_refresh_within(cfs_b, min_left))
return;
start_bandwidth_timer(&cfs_b->slack_timer,
ns_to_ktime(cfs_bandwidth_slack_period));
}
static void __return_cfs_rq_runtime(struct cfs_rq *cfs_rq)
{
struct cfs_bandwidth *cfs_b = tg_cfs_bandwidth(cfs_rq->tg);
s64 slack_runtime = cfs_rq->runtime_remaining - min_cfs_rq_runtime;
if (slack_runtime <= 0)
return;
raw_spin_lock(&cfs_b->lock);
if (cfs_b->quota != RUNTIME_INF &&
cfs_rq->runtime_expires == cfs_b->runtime_expires) {
cfs_b->runtime += slack_runtime;
if (cfs_b->runtime > sched_cfs_bandwidth_slice() &&
!list_empty(&cfs_b->throttled_cfs_rq))
start_cfs_slack_bandwidth(cfs_b);
}
raw_spin_unlock(&cfs_b->lock);
cfs_rq->runtime_remaining -= slack_runtime;
}
static __always_inline void return_cfs_rq_runtime(struct cfs_rq *cfs_rq)
{
if (!cfs_bandwidth_used())
return;
if (!cfs_rq->runtime_enabled || cfs_rq->nr_running)
return;
__return_cfs_rq_runtime(cfs_rq);
}
static void do_sched_cfs_slack_timer(struct cfs_bandwidth *cfs_b)
{
u64 runtime = 0, slice = sched_cfs_bandwidth_slice();
u64 expires;
raw_spin_lock(&cfs_b->lock);
if (runtime_refresh_within(cfs_b, min_bandwidth_expiration)) {
raw_spin_unlock(&cfs_b->lock);
return;
}
if (cfs_b->quota != RUNTIME_INF && cfs_b->runtime > slice)
runtime = cfs_b->runtime;
expires = cfs_b->runtime_expires;
raw_spin_unlock(&cfs_b->lock);
if (!runtime)
return;
runtime = distribute_cfs_runtime(cfs_b, runtime, expires);
raw_spin_lock(&cfs_b->lock);
if (expires == cfs_b->runtime_expires)
cfs_b->runtime -= min(runtime, cfs_b->runtime);
raw_spin_unlock(&cfs_b->lock);
}
static void check_enqueue_throttle(struct cfs_rq *cfs_rq)
{
if (!cfs_bandwidth_used())
return;
if (!cfs_rq->runtime_enabled || cfs_rq->curr)
return;
if (cfs_rq_throttled(cfs_rq))
return;
account_cfs_rq_runtime(cfs_rq, 0);
if (cfs_rq->runtime_remaining <= 0)
throttle_cfs_rq(cfs_rq);
}
static bool check_cfs_rq_runtime(struct cfs_rq *cfs_rq)
{
if (!cfs_bandwidth_used())
return false;
if (likely(!cfs_rq->runtime_enabled || cfs_rq->runtime_remaining > 0))
return false;
if (cfs_rq_throttled(cfs_rq))
return true;
throttle_cfs_rq(cfs_rq);
return true;
}
static enum hrtimer_restart sched_cfs_slack_timer(struct hrtimer *timer)
{
struct cfs_bandwidth *cfs_b =
container_of(timer, struct cfs_bandwidth, slack_timer);
do_sched_cfs_slack_timer(cfs_b);
return HRTIMER_NORESTART;
}
static enum hrtimer_restart sched_cfs_period_timer(struct hrtimer *timer)
{
struct cfs_bandwidth *cfs_b =
container_of(timer, struct cfs_bandwidth, period_timer);
ktime_t now;
int overrun;
int idle = 0;
raw_spin_lock(&cfs_b->lock);
for (;;) {
now = hrtimer_cb_get_time(timer);
overrun = hrtimer_forward(timer, now, cfs_b->period);
if (!overrun)
break;
idle = do_sched_cfs_period_timer(cfs_b, overrun);
}
raw_spin_unlock(&cfs_b->lock);
return idle ? HRTIMER_NORESTART : HRTIMER_RESTART;
}
void init_cfs_bandwidth(struct cfs_bandwidth *cfs_b)
{
raw_spin_lock_init(&cfs_b->lock);
cfs_b->runtime = 0;
cfs_b->quota = RUNTIME_INF;
cfs_b->period = ns_to_ktime(default_cfs_period());
INIT_LIST_HEAD(&cfs_b->throttled_cfs_rq);
hrtimer_init(&cfs_b->period_timer, CLOCK_MONOTONIC, HRTIMER_MODE_REL);
cfs_b->period_timer.function = sched_cfs_period_timer;
hrtimer_init(&cfs_b->slack_timer, CLOCK_MONOTONIC, HRTIMER_MODE_REL);
cfs_b->slack_timer.function = sched_cfs_slack_timer;
}
static void init_cfs_rq_runtime(struct cfs_rq *cfs_rq)
{
cfs_rq->runtime_enabled = 0;
INIT_LIST_HEAD(&cfs_rq->throttled_list);
}
void __start_cfs_bandwidth(struct cfs_bandwidth *cfs_b, bool force)
{
while (unlikely(hrtimer_active(&cfs_b->period_timer)) &&
hrtimer_try_to_cancel(&cfs_b->period_timer) < 0) {
raw_spin_unlock(&cfs_b->lock);
cpu_relax();
raw_spin_lock(&cfs_b->lock);
if (!force && cfs_b->timer_active)
return;
}
cfs_b->timer_active = 1;
start_bandwidth_timer(&cfs_b->period_timer, cfs_b->period);
}
static void destroy_cfs_bandwidth(struct cfs_bandwidth *cfs_b)
{
if (!cfs_b->throttled_cfs_rq.next)
return;
hrtimer_cancel(&cfs_b->period_timer);
hrtimer_cancel(&cfs_b->slack_timer);
}
static void __maybe_unused update_runtime_enabled(struct rq *rq)
{
struct cfs_rq *cfs_rq;
for_each_leaf_cfs_rq(rq, cfs_rq) {
struct cfs_bandwidth *cfs_b = &cfs_rq->tg->cfs_bandwidth;
raw_spin_lock(&cfs_b->lock);
cfs_rq->runtime_enabled = cfs_b->quota != RUNTIME_INF;
raw_spin_unlock(&cfs_b->lock);
}
}
static void __maybe_unused unthrottle_offline_cfs_rqs(struct rq *rq)
{
struct cfs_rq *cfs_rq;
for_each_leaf_cfs_rq(rq, cfs_rq) {
if (!cfs_rq->runtime_enabled)
continue;
cfs_rq->runtime_remaining = 1;
cfs_rq->runtime_enabled = 0;
if (cfs_rq_throttled(cfs_rq))
unthrottle_cfs_rq(cfs_rq);
}
}
static inline u64 cfs_rq_clock_task(struct cfs_rq *cfs_rq)
{
return rq_clock_task(rq_of(cfs_rq));
}
static void account_cfs_rq_runtime(struct cfs_rq *cfs_rq, u64 delta_exec) {}
static bool check_cfs_rq_runtime(struct cfs_rq *cfs_rq) { return false; }
static void check_enqueue_throttle(struct cfs_rq *cfs_rq) {}
static __always_inline void return_cfs_rq_runtime(struct cfs_rq *cfs_rq) {}
static inline int cfs_rq_throttled(struct cfs_rq *cfs_rq)
{
return 0;
}
static inline int throttled_hierarchy(struct cfs_rq *cfs_rq)
{
return 0;
}
static inline int throttled_lb_pair(struct task_group *tg,
int src_cpu, int dest_cpu)
{
return 0;
}
void init_cfs_bandwidth(struct cfs_bandwidth *cfs_b) {}
static void init_cfs_rq_runtime(struct cfs_rq *cfs_rq) {}
static inline struct cfs_bandwidth *tg_cfs_bandwidth(struct task_group *tg)
{
return NULL;
}
static inline void destroy_cfs_bandwidth(struct cfs_bandwidth *cfs_b) {}
static inline void update_runtime_enabled(struct rq *rq) {}
static inline void unthrottle_offline_cfs_rqs(struct rq *rq) {}
static void hrtick_start_fair(struct rq *rq, struct task_struct *p)
{
struct sched_entity *se = &p->se;
struct cfs_rq *cfs_rq = cfs_rq_of(se);
WARN_ON(task_rq(p) != rq);
if (cfs_rq->nr_running > 1) {
u64 slice = sched_slice(cfs_rq, se);
u64 ran = se->sum_exec_runtime - se->prev_sum_exec_runtime;
s64 delta = slice - ran;
if (delta < 0) {
if (rq->curr == p)
resched_curr(rq);
return;
}
hrtick_start(rq, delta);
}
}
static void hrtick_update(struct rq *rq)
{
struct task_struct *curr = rq->curr;
if (!hrtick_enabled(rq) || curr->sched_class != &fair_sched_class)
return;
if (cfs_rq_of(&curr->se)->nr_running < sched_nr_latency)
hrtick_start_fair(rq, curr);
}
static inline void
hrtick_start_fair(struct rq *rq, struct task_struct *p)
{
}
static inline void hrtick_update(struct rq *rq)
{
}
static void
enqueue_task_fair(struct rq *rq, struct task_struct *p, int flags)
{
struct cfs_rq *cfs_rq;
struct sched_entity *se = &p->se;
for_each_sched_entity(se) {
if (se->on_rq)
break;
cfs_rq = cfs_rq_of(se);
enqueue_entity(cfs_rq, se, flags);
if (cfs_rq_throttled(cfs_rq))
break;
cfs_rq->h_nr_running++;
flags = ENQUEUE_WAKEUP;
}
for_each_sched_entity(se) {
cfs_rq = cfs_rq_of(se);
cfs_rq->h_nr_running++;
if (cfs_rq_throttled(cfs_rq))
break;
update_cfs_shares(cfs_rq);
update_entity_load_avg(se, 1);
}
if (!se) {
update_rq_runnable_avg(rq, rq->nr_running);
add_nr_running(rq, 1);
}
hrtick_update(rq);
}
static void dequeue_task_fair(struct rq *rq, struct task_struct *p, int flags)
{
struct cfs_rq *cfs_rq;
struct sched_entity *se = &p->se;
int task_sleep = flags & DEQUEUE_SLEEP;
for_each_sched_entity(se) {
cfs_rq = cfs_rq_of(se);
dequeue_entity(cfs_rq, se, flags);
if (cfs_rq_throttled(cfs_rq))
break;
cfs_rq->h_nr_running--;
if (cfs_rq->load.weight) {
if (task_sleep && parent_entity(se))
set_next_buddy(parent_entity(se));
se = parent_entity(se);
break;
}
flags |= DEQUEUE_SLEEP;
}
for_each_sched_entity(se) {
cfs_rq = cfs_rq_of(se);
cfs_rq->h_nr_running--;
if (cfs_rq_throttled(cfs_rq))
break;
update_cfs_shares(cfs_rq);
update_entity_load_avg(se, 1);
}
if (!se) {
sub_nr_running(rq, 1);
update_rq_runnable_avg(rq, 1);
}
hrtick_update(rq);
}
static unsigned long weighted_cpuload(const int cpu)
{
return cpu_rq(cpu)->cfs.runnable_load_avg;
}
static unsigned long source_load(int cpu, int type)
{
struct rq *rq = cpu_rq(cpu);
unsigned long total = weighted_cpuload(cpu);
if (type == 0 || !sched_feat(LB_BIAS))
return total;
return min(rq->cpu_load[type-1], total);
}
static unsigned long target_load(int cpu, int type)
{
struct rq *rq = cpu_rq(cpu);
unsigned long total = weighted_cpuload(cpu);
if (type == 0 || !sched_feat(LB_BIAS))
return total;
return max(rq->cpu_load[type-1], total);
}
static unsigned long capacity_of(int cpu)
{
return cpu_rq(cpu)->cpu_capacity;
}
static unsigned long cpu_avg_load_per_task(int cpu)
{
struct rq *rq = cpu_rq(cpu);
unsigned long nr_running = ACCESS_ONCE(rq->cfs.h_nr_running);
unsigned long load_avg = rq->cfs.runnable_load_avg;
if (nr_running)
return load_avg / nr_running;
return 0;
}
static void record_wakee(struct task_struct *p)
{
if (time_after(jiffies, current->wakee_flip_decay_ts + HZ)) {
current->wakee_flips >>= 1;
current->wakee_flip_decay_ts = jiffies;
}
if (current->last_wakee != p) {
current->last_wakee = p;
current->wakee_flips++;
}
}
static void task_waking_fair(struct task_struct *p)
{
struct sched_entity *se = &p->se;
struct cfs_rq *cfs_rq = cfs_rq_of(se);
u64 min_vruntime;
#ifndef CONFIG_64BIT
u64 min_vruntime_copy;
do {
min_vruntime_copy = cfs_rq->min_vruntime_copy;
smp_rmb();
min_vruntime = cfs_rq->min_vruntime;
} while (min_vruntime != min_vruntime_copy);
#else
min_vruntime = cfs_rq->min_vruntime;
#endif
se->vruntime -= min_vruntime;
record_wakee(p);
}
static long effective_load(struct task_group *tg, int cpu, long wl, long wg)
{
struct sched_entity *se = tg->se[cpu];
if (!tg->parent)
return wl;
for_each_sched_entity(se) {
long w, W;
tg = se->my_q->tg;
W = wg + calc_tg_weight(tg, se->my_q);
w = se->my_q->load.weight + wl;
if (W > 0 && w < W)
wl = (w * (long)tg->shares) / W;
else
wl = tg->shares;
if (wl < MIN_SHARES)
wl = MIN_SHARES;
wl -= se->load.weight;
wg = 0;
}
return wl;
}
static long effective_load(struct task_group *tg, int cpu, long wl, long wg)
{
return wl;
}
static int wake_wide(struct task_struct *p)
{
int factor = this_cpu_read(sd_llc_size);
if (p->wakee_flips > factor) {
if (current->wakee_flips > (factor * p->wakee_flips))
return 1;
}
return 0;
}
static int wake_affine(struct sched_domain *sd, struct task_struct *p, int sync)
{
s64 this_load, load;
s64 this_eff_load, prev_eff_load;
int idx, this_cpu, prev_cpu;
struct task_group *tg;
unsigned long weight;
int balanced;
if (wake_wide(p))
return 0;
idx = sd->wake_idx;
this_cpu = smp_processor_id();
prev_cpu = task_cpu(p);
load = source_load(prev_cpu, idx);
this_load = target_load(this_cpu, idx);
if (sync) {
tg = task_group(current);
weight = current->se.load.weight;
this_load += effective_load(tg, this_cpu, -weight, -weight);
load += effective_load(tg, prev_cpu, 0, -weight);
}
tg = task_group(p);
weight = p->se.load.weight;
this_eff_load = 100;
this_eff_load *= capacity_of(prev_cpu);
prev_eff_load = 100 + (sd->imbalance_pct - 100) / 2;
prev_eff_load *= capacity_of(this_cpu);
if (this_load > 0) {
this_eff_load *= this_load +
effective_load(tg, this_cpu, weight, weight);
prev_eff_load *= load + effective_load(tg, prev_cpu, 0, weight);
}
balanced = this_eff_load <= prev_eff_load;
schedstat_inc(p, se.statistics.nr_wakeups_affine_attempts);
if (!balanced)
return 0;
schedstat_inc(sd, ttwu_move_affine);
schedstat_inc(p, se.statistics.nr_wakeups_affine);
return 1;
}
static struct sched_group *
find_idlest_group(struct sched_domain *sd, struct task_struct *p,
int this_cpu, int sd_flag)
{
struct sched_group *idlest = NULL, *group = sd->groups;
unsigned long min_load = ULONG_MAX, this_load = 0;
int load_idx = sd->forkexec_idx;
int imbalance = 100 + (sd->imbalance_pct-100)/2;
if (sd_flag & SD_BALANCE_WAKE)
load_idx = sd->wake_idx;
do {
unsigned long load, avg_load;
int local_group;
int i;
if (!cpumask_intersects(sched_group_cpus(group),
tsk_cpus_allowed(p)))
continue;
local_group = cpumask_test_cpu(this_cpu,
sched_group_cpus(group));
avg_load = 0;
for_each_cpu(i, sched_group_cpus(group)) {
if (local_group)
load = source_load(i, load_idx);
else
load = target_load(i, load_idx);
avg_load += load;
}
avg_load = (avg_load * SCHED_CAPACITY_SCALE) / group->sgc->capacity;
if (local_group) {
this_load = avg_load;
} else if (avg_load < min_load) {
min_load = avg_load;
idlest = group;
}
} while (group = group->next, group != sd->groups);
if (!idlest || 100*this_load < imbalance*min_load)
return NULL;
return idlest;
}
static int
find_idlest_cpu(struct sched_group *group, struct task_struct *p, int this_cpu)
{
unsigned long load, min_load = ULONG_MAX;
unsigned int min_exit_latency = UINT_MAX;
u64 latest_idle_timestamp = 0;
int least_loaded_cpu = this_cpu;
int shallowest_idle_cpu = -1;
int i;
for_each_cpu_and(i, sched_group_cpus(group), tsk_cpus_allowed(p)) {
if (idle_cpu(i)) {
struct rq *rq = cpu_rq(i);
struct cpuidle_state *idle = idle_get_state(rq);
if (idle && idle->exit_latency < min_exit_latency) {
min_exit_latency = idle->exit_latency;
latest_idle_timestamp = rq->idle_stamp;
shallowest_idle_cpu = i;
} else if ((!idle || idle->exit_latency == min_exit_latency) &&
rq->idle_stamp > latest_idle_timestamp) {
latest_idle_timestamp = rq->idle_stamp;
shallowest_idle_cpu = i;
}
} else if (shallowest_idle_cpu == -1) {
load = weighted_cpuload(i);
if (load < min_load || (load == min_load && i == this_cpu)) {
min_load = load;
least_loaded_cpu = i;
}
}
}
return shallowest_idle_cpu != -1 ? shallowest_idle_cpu : least_loaded_cpu;
}
static int select_idle_sibling(struct task_struct *p, int target)
{
struct sched_domain *sd;
struct sched_group *sg;
int i = task_cpu(p);
if (idle_cpu(target))
return target;
if (i != target && cpus_share_cache(i, target) && idle_cpu(i))
return i;
sd = rcu_dereference(per_cpu(sd_llc, target));
for_each_lower_domain(sd) {
sg = sd->groups;
do {
if (!cpumask_intersects(sched_group_cpus(sg),
tsk_cpus_allowed(p)))
goto next;
for_each_cpu(i, sched_group_cpus(sg)) {
if (i == target || !idle_cpu(i))
goto next;
}
target = cpumask_first_and(sched_group_cpus(sg),
tsk_cpus_allowed(p));
goto done;
next:
sg = sg->next;
} while (sg != sd->groups);
}
done:
return target;
}
static int
select_task_rq_fair(struct task_struct *p, int prev_cpu, int sd_flag, int wake_flags)
{
struct sched_domain *tmp, *affine_sd = NULL, *sd = NULL;
int cpu = smp_processor_id();
int new_cpu = cpu;
int want_affine = 0;
int sync = wake_flags & WF_SYNC;
if (sd_flag & SD_BALANCE_WAKE)
want_affine = cpumask_test_cpu(cpu, tsk_cpus_allowed(p));
rcu_read_lock();
for_each_domain(cpu, tmp) {
if (!(tmp->flags & SD_LOAD_BALANCE))
continue;
if (want_affine && (tmp->flags & SD_WAKE_AFFINE) &&
cpumask_test_cpu(prev_cpu, sched_domain_span(tmp))) {
affine_sd = tmp;
break;
}
if (tmp->flags & sd_flag)
sd = tmp;
}
if (affine_sd && cpu != prev_cpu && wake_affine(affine_sd, p, sync))
prev_cpu = cpu;
if (sd_flag & SD_BALANCE_WAKE) {
new_cpu = select_idle_sibling(p, prev_cpu);
goto unlock;
}
while (sd) {
struct sched_group *group;
int weight;
if (!(sd->flags & sd_flag)) {
sd = sd->child;
continue;
}
group = find_idlest_group(sd, p, cpu, sd_flag);
if (!group) {
sd = sd->child;
continue;
}
new_cpu = find_idlest_cpu(group, p, cpu);
if (new_cpu == -1 || new_cpu == cpu) {
sd = sd->child;
continue;
}
cpu = new_cpu;
weight = sd->span_weight;
sd = NULL;
for_each_domain(cpu, tmp) {
if (weight <= tmp->span_weight)
break;
if (tmp->flags & sd_flag)
sd = tmp;
}
}
unlock:
rcu_read_unlock();
return new_cpu;
}
static void
migrate_task_rq_fair(struct task_struct *p, int next_cpu)
{
struct sched_entity *se = &p->se;
struct cfs_rq *cfs_rq = cfs_rq_of(se);
if (se->avg.decay_count) {
se->avg.decay_count = -__synchronize_entity_decay(se);
atomic_long_add(se->avg.load_avg_contrib,
&cfs_rq->removed_load);
}
se->exec_start = 0;
}
static unsigned long
wakeup_gran(struct sched_entity *curr, struct sched_entity *se)
{
unsigned long gran = sysctl_sched_wakeup_granularity;
return calc_delta_fair(gran, se);
}
static int
wakeup_preempt_entity(struct sched_entity *curr, struct sched_entity *se)
{
s64 gran, vdiff = curr->vruntime - se->vruntime;
if (vdiff <= 0)
return -1;
gran = wakeup_gran(curr, se);
if (vdiff > gran)
return 1;
return 0;
}
static void set_last_buddy(struct sched_entity *se)
{
if (entity_is_task(se) && unlikely(task_of(se)->policy == SCHED_IDLE))
return;
for_each_sched_entity(se)
cfs_rq_of(se)->last = se;
}
static void set_next_buddy(struct sched_entity *se)
{
if (entity_is_task(se) && unlikely(task_of(se)->policy == SCHED_IDLE))
return;
for_each_sched_entity(se)
cfs_rq_of(se)->next = se;
}
static void set_skip_buddy(struct sched_entity *se)
{
for_each_sched_entity(se)
cfs_rq_of(se)->skip = se;
}
static void check_preempt_wakeup(struct rq *rq, struct task_struct *p, int wake_flags)
{
struct task_struct *curr = rq->curr;
struct sched_entity *se = &curr->se, *pse = &p->se;
struct cfs_rq *cfs_rq = task_cfs_rq(curr);
int scale = cfs_rq->nr_running >= sched_nr_latency;
int next_buddy_marked = 0;
if (unlikely(se == pse))
return;
if (unlikely(throttled_hierarchy(cfs_rq_of(pse))))
return;
if (sched_feat(NEXT_BUDDY) && scale && !(wake_flags & WF_FORK)) {
set_next_buddy(pse);
next_buddy_marked = 1;
}
if (test_tsk_need_resched(curr))
return;
if (unlikely(curr->policy == SCHED_IDLE) &&
likely(p->policy != SCHED_IDLE))
goto preempt;
if (unlikely(p->policy != SCHED_NORMAL) || !sched_feat(WAKEUP_PREEMPTION))
return;
find_matching_se(&se, &pse);
update_curr(cfs_rq_of(se));
BUG_ON(!pse);
if (wakeup_preempt_entity(se, pse) == 1) {
if (!next_buddy_marked)
set_next_buddy(pse);
goto preempt;
}
return;
preempt:
resched_curr(rq);
if (unlikely(!se->on_rq || curr == rq->idle))
return;
if (sched_feat(LAST_BUDDY) && scale && entity_is_task(se))
set_last_buddy(se);
}
static struct task_struct *
pick_next_task_fair(struct rq *rq, struct task_struct *prev)
{
struct cfs_rq *cfs_rq = &rq->cfs;
struct sched_entity *se;
struct task_struct *p;
int new_tasks;
again:
#ifdef CONFIG_FAIR_GROUP_SCHED
if (!cfs_rq->nr_running)
goto idle;
if (prev->sched_class != &fair_sched_class)
goto simple;
do {
struct sched_entity *curr = cfs_rq->curr;
if (curr && curr->on_rq)
update_curr(cfs_rq);
else
curr = NULL;
if (unlikely(check_cfs_rq_runtime(cfs_rq)))
goto simple;
se = pick_next_entity(cfs_rq, curr);
cfs_rq = group_cfs_rq(se);
} while (cfs_rq);
p = task_of(se);
if (prev != p) {
struct sched_entity *pse = &prev->se;
while (!(cfs_rq = is_same_group(se, pse))) {
int se_depth = se->depth;
int pse_depth = pse->depth;
if (se_depth <= pse_depth) {
put_prev_entity(cfs_rq_of(pse), pse);
pse = parent_entity(pse);
}
if (se_depth >= pse_depth) {
set_next_entity(cfs_rq_of(se), se);
se = parent_entity(se);
}
}
put_prev_entity(cfs_rq, pse);
set_next_entity(cfs_rq, se);
}
if (hrtick_enabled(rq))
hrtick_start_fair(rq, p);
return p;
simple:
cfs_rq = &rq->cfs;
#endif
if (!cfs_rq->nr_running)
goto idle;
put_prev_task(rq, prev);
do {
se = pick_next_entity(cfs_rq, NULL);
set_next_entity(cfs_rq, se);
cfs_rq = group_cfs_rq(se);
} while (cfs_rq);
p = task_of(se);
if (hrtick_enabled(rq))
hrtick_start_fair(rq, p);
return p;
idle:
new_tasks = idle_balance(rq);
if (new_tasks < 0)
return RETRY_TASK;
if (new_tasks > 0)
goto again;
return NULL;
}
static void put_prev_task_fair(struct rq *rq, struct task_struct *prev)
{
struct sched_entity *se = &prev->se;
struct cfs_rq *cfs_rq;
for_each_sched_entity(se) {
cfs_rq = cfs_rq_of(se);
put_prev_entity(cfs_rq, se);
}
}
static void yield_task_fair(struct rq *rq)
{
struct task_struct *curr = rq->curr;
struct cfs_rq *cfs_rq = task_cfs_rq(curr);
struct sched_entity *se = &curr->se;
if (unlikely(rq->nr_running == 1))
return;
clear_buddies(cfs_rq, se);
if (curr->policy != SCHED_BATCH) {
update_rq_clock(rq);
update_curr(cfs_rq);
rq->skip_clock_update = 1;
}
set_skip_buddy(se);
}
static bool yield_to_task_fair(struct rq *rq, struct task_struct *p, bool preempt)
{
struct sched_entity *se = &p->se;
if (!se->on_rq || throttled_hierarchy(cfs_rq_of(se)))
return false;
set_next_buddy(se);
yield_task_fair(rq);
return true;
}
static int task_hot(struct task_struct *p, struct lb_env *env)
{
s64 delta;
lockdep_assert_held(&env->src_rq->lock);
if (p->sched_class != &fair_sched_class)
return 0;
if (unlikely(p->policy == SCHED_IDLE))
return 0;
if (sched_feat(CACHE_HOT_BUDDY) && env->dst_rq->nr_running &&
(&p->se == cfs_rq_of(&p->se)->next ||
&p->se == cfs_rq_of(&p->se)->last))
return 1;
if (sysctl_sched_migration_cost == -1)
return 1;
if (sysctl_sched_migration_cost == 0)
return 0;
delta = rq_clock_task(env->src_rq) - p->se.exec_start;
return delta < (s64)sysctl_sched_migration_cost;
}
static bool migrate_improves_locality(struct task_struct *p, struct lb_env *env)
{
struct numa_group *numa_group = rcu_dereference(p->numa_group);
int src_nid, dst_nid;
if (!sched_feat(NUMA_FAVOUR_HIGHER) || !p->numa_faults ||
!(env->sd->flags & SD_NUMA)) {
return false;
}
src_nid = cpu_to_node(env->src_cpu);
dst_nid = cpu_to_node(env->dst_cpu);
if (src_nid == dst_nid)
return false;
if (numa_group) {
if (node_isset(src_nid, numa_group->active_nodes))
return false;
if (node_isset(dst_nid, numa_group->active_nodes))
return true;
return group_faults(p, dst_nid) > group_faults(p, src_nid);
}
if (dst_nid == p->numa_preferred_nid)
return true;
return task_faults(p, dst_nid) > task_faults(p, src_nid);
}
static bool migrate_degrades_locality(struct task_struct *p, struct lb_env *env)
{
struct numa_group *numa_group = rcu_dereference(p->numa_group);
int src_nid, dst_nid;
if (!sched_feat(NUMA) || !sched_feat(NUMA_RESIST_LOWER))
return false;
if (!p->numa_faults || !(env->sd->flags & SD_NUMA))
return false;
src_nid = cpu_to_node(env->src_cpu);
dst_nid = cpu_to_node(env->dst_cpu);
if (src_nid == dst_nid)
return false;
if (numa_group) {
if (node_isset(dst_nid, numa_group->active_nodes))
return false;
if (node_isset(src_nid, numa_group->active_nodes))
return true;
return group_faults(p, dst_nid) < group_faults(p, src_nid);
}
if (src_nid == p->numa_preferred_nid)
return true;
return task_faults(p, dst_nid) < task_faults(p, src_nid);
}
static inline bool migrate_improves_locality(struct task_struct *p,
struct lb_env *env)
{
return false;
}
static inline bool migrate_degrades_locality(struct task_struct *p,
struct lb_env *env)
{
return false;
}
static
int can_migrate_task(struct task_struct *p, struct lb_env *env)
{
int tsk_cache_hot = 0;
lockdep_assert_held(&env->src_rq->lock);
if (throttled_lb_pair(task_group(p), env->src_cpu, env->dst_cpu))
return 0;
if (!cpumask_test_cpu(env->dst_cpu, tsk_cpus_allowed(p))) {
int cpu;
schedstat_inc(p, se.statistics.nr_failed_migrations_affine);
env->flags |= LBF_SOME_PINNED;
if (!env->dst_grpmask || (env->flags & LBF_DST_PINNED))
return 0;
for_each_cpu_and(cpu, env->dst_grpmask, env->cpus) {
if (cpumask_test_cpu(cpu, tsk_cpus_allowed(p))) {
env->flags |= LBF_DST_PINNED;
env->new_dst_cpu = cpu;
break;
}
}
return 0;
}
env->flags &= ~LBF_ALL_PINNED;
if (task_running(env->src_rq, p)) {
schedstat_inc(p, se.statistics.nr_failed_migrations_running);
return 0;
}
tsk_cache_hot = task_hot(p, env);
if (!tsk_cache_hot)
tsk_cache_hot = migrate_degrades_locality(p, env);
if (migrate_improves_locality(p, env) || !tsk_cache_hot ||
env->sd->nr_balance_failed > env->sd->cache_nice_tries) {
if (tsk_cache_hot) {
schedstat_inc(env->sd, lb_hot_gained[env->idle]);
schedstat_inc(p, se.statistics.nr_forced_migrations);
}
return 1;
}
schedstat_inc(p, se.statistics.nr_failed_migrations_hot);
return 0;
}
static void detach_task(struct task_struct *p, struct lb_env *env)
{
lockdep_assert_held(&env->src_rq->lock);
deactivate_task(env->src_rq, p, 0);
p->on_rq = TASK_ON_RQ_MIGRATING;
set_task_cpu(p, env->dst_cpu);
}
static struct task_struct *detach_one_task(struct lb_env *env)
{
struct task_struct *p, *n;
lockdep_assert_held(&env->src_rq->lock);
list_for_each_entry_safe(p, n, &env->src_rq->cfs_tasks, se.group_node) {
if (!can_migrate_task(p, env))
continue;
detach_task(p, env);
schedstat_inc(env->sd, lb_gained[env->idle]);
return p;
}
return NULL;
}
static int detach_tasks(struct lb_env *env)
{
struct list_head *tasks = &env->src_rq->cfs_tasks;
struct task_struct *p;
unsigned long load;
int detached = 0;
lockdep_assert_held(&env->src_rq->lock);
if (env->imbalance <= 0)
return 0;
while (!list_empty(tasks)) {
p = list_first_entry(tasks, struct task_struct, se.group_node);
env->loop++;
if (env->loop > env->loop_max)
break;
if (env->loop > env->loop_break) {
env->loop_break += sched_nr_migrate_break;
env->flags |= LBF_NEED_BREAK;
break;
}
if (!can_migrate_task(p, env))
goto next;
load = task_h_load(p);
if (sched_feat(LB_MIN) && load < 16 && !env->sd->nr_balance_failed)
goto next;
if ((load / 2) > env->imbalance)
goto next;
detach_task(p, env);
list_add(&p->se.group_node, &env->tasks);
detached++;
env->imbalance -= load;
#ifdef CONFIG_PREEMPT
if (env->idle == CPU_NEWLY_IDLE)
break;
#endif
if (env->imbalance <= 0)
break;
continue;
next:
list_move_tail(&p->se.group_node, tasks);
}
schedstat_add(env->sd, lb_gained[env->idle], detached);
return detached;
}
static void attach_task(struct rq *rq, struct task_struct *p)
{
lockdep_assert_held(&rq->lock);
BUG_ON(task_rq(p) != rq);
p->on_rq = TASK_ON_RQ_QUEUED;
activate_task(rq, p, 0);
check_preempt_curr(rq, p, 0);
}
static void attach_one_task(struct rq *rq, struct task_struct *p)
{
raw_spin_lock(&rq->lock);
attach_task(rq, p);
raw_spin_unlock(&rq->lock);
}
static void attach_tasks(struct lb_env *env)
{
struct list_head *tasks = &env->tasks;
struct task_struct *p;
raw_spin_lock(&env->dst_rq->lock);
while (!list_empty(tasks)) {
p = list_first_entry(tasks, struct task_struct, se.group_node);
list_del_init(&p->se.group_node);
attach_task(env->dst_rq, p);
}
raw_spin_unlock(&env->dst_rq->lock);
}
static void __update_blocked_averages_cpu(struct task_group *tg, int cpu)
{
struct sched_entity *se = tg->se[cpu];
struct cfs_rq *cfs_rq = tg->cfs_rq[cpu];
if (throttled_hierarchy(cfs_rq))
return;
update_cfs_rq_blocked_load(cfs_rq, 1);
if (se) {
update_entity_load_avg(se, 1);
if (!se->avg.runnable_avg_sum && !cfs_rq->nr_running)
list_del_leaf_cfs_rq(cfs_rq);
} else {
struct rq *rq = rq_of(cfs_rq);
update_rq_runnable_avg(rq, rq->nr_running);
}
}
static void update_blocked_averages(int cpu)
{
struct rq *rq = cpu_rq(cpu);
struct cfs_rq *cfs_rq;
unsigned long flags;
raw_spin_lock_irqsave(&rq->lock, flags);
update_rq_clock(rq);
for_each_leaf_cfs_rq(rq, cfs_rq) {
__update_blocked_averages_cpu(cfs_rq->tg, rq->cpu);
}
raw_spin_unlock_irqrestore(&rq->lock, flags);
}
static void update_cfs_rq_h_load(struct cfs_rq *cfs_rq)
{
struct rq *rq = rq_of(cfs_rq);
struct sched_entity *se = cfs_rq->tg->se[cpu_of(rq)];
unsigned long now = jiffies;
unsigned long load;
if (cfs_rq->last_h_load_update == now)
return;
cfs_rq->h_load_next = NULL;
for_each_sched_entity(se) {
cfs_rq = cfs_rq_of(se);
cfs_rq->h_load_next = se;
if (cfs_rq->last_h_load_update == now)
break;
}
if (!se) {
cfs_rq->h_load = cfs_rq->runnable_load_avg;
cfs_rq->last_h_load_update = now;
}
while ((se = cfs_rq->h_load_next) != NULL) {
load = cfs_rq->h_load;
load = div64_ul(load * se->avg.load_avg_contrib,
cfs_rq->runnable_load_avg + 1);
cfs_rq = group_cfs_rq(se);
cfs_rq->h_load = load;
cfs_rq->last_h_load_update = now;
}
}
static unsigned long task_h_load(struct task_struct *p)
{
struct cfs_rq *cfs_rq = task_cfs_rq(p);
update_cfs_rq_h_load(cfs_rq);
return div64_ul(p->se.avg.load_avg_contrib * cfs_rq->h_load,
cfs_rq->runnable_load_avg + 1);
}
static inline void update_blocked_averages(int cpu)
{
}
static unsigned long task_h_load(struct task_struct *p)
{
return p->se.avg.load_avg_contrib;
}
static inline void init_sd_lb_stats(struct sd_lb_stats *sds)
{
*sds = (struct sd_lb_stats){
.busiest = NULL,
.local = NULL,
.total_load = 0UL,
.total_capacity = 0UL,
.busiest_stat = {
.avg_load = 0UL,
.sum_nr_running = 0,
.group_type = group_other,
},
};
}
static inline int get_sd_load_idx(struct sched_domain *sd,
enum cpu_idle_type idle)
{
int load_idx;
switch (idle) {
case CPU_NOT_IDLE:
load_idx = sd->busy_idx;
break;
case CPU_NEWLY_IDLE:
load_idx = sd->newidle_idx;
break;
default:
load_idx = sd->idle_idx;
break;
}
return load_idx;
}
static unsigned long default_scale_capacity(struct sched_domain *sd, int cpu)
{
return SCHED_CAPACITY_SCALE;
}
unsigned long __weak arch_scale_freq_capacity(struct sched_domain *sd, int cpu)
{
return default_scale_capacity(sd, cpu);
}
static unsigned long default_scale_cpu_capacity(struct sched_domain *sd, int cpu)
{
if ((sd->flags & SD_SHARE_CPUCAPACITY) && (sd->span_weight > 1))
return sd->smt_gain / sd->span_weight;
return SCHED_CAPACITY_SCALE;
}
unsigned long __weak arch_scale_cpu_capacity(struct sched_domain *sd, int cpu)
{
return default_scale_cpu_capacity(sd, cpu);
}
static unsigned long scale_rt_capacity(int cpu)
{
struct rq *rq = cpu_rq(cpu);
u64 total, available, age_stamp, avg;
s64 delta;
age_stamp = ACCESS_ONCE(rq->age_stamp);
avg = ACCESS_ONCE(rq->rt_avg);
delta = rq_clock(rq) - age_stamp;
if (unlikely(delta < 0))
delta = 0;
total = sched_avg_period() + delta;
if (unlikely(total < avg)) {
available = 0;
} else {
available = total - avg;
}
if (unlikely((s64)total < SCHED_CAPACITY_SCALE))
total = SCHED_CAPACITY_SCALE;
total >>= SCHED_CAPACITY_SHIFT;
return div_u64(available, total);
}
static void update_cpu_capacity(struct sched_domain *sd, int cpu)
{
unsigned long capacity = SCHED_CAPACITY_SCALE;
struct sched_group *sdg = sd->groups;
if (sched_feat(ARCH_CAPACITY))
capacity *= arch_scale_cpu_capacity(sd, cpu);
else
capacity *= default_scale_cpu_capacity(sd, cpu);
capacity >>= SCHED_CAPACITY_SHIFT;
sdg->sgc->capacity_orig = capacity;
if (sched_feat(ARCH_CAPACITY))
capacity *= arch_scale_freq_capacity(sd, cpu);
else
capacity *= default_scale_capacity(sd, cpu);
capacity >>= SCHED_CAPACITY_SHIFT;
capacity *= scale_rt_capacity(cpu);
capacity >>= SCHED_CAPACITY_SHIFT;
if (!capacity)
capacity = 1;
cpu_rq(cpu)->cpu_capacity = capacity;
sdg->sgc->capacity = capacity;
}
void update_group_capacity(struct sched_domain *sd, int cpu)
{
struct sched_domain *child = sd->child;
struct sched_group *group, *sdg = sd->groups;
unsigned long capacity, capacity_orig;
unsigned long interval;
interval = msecs_to_jiffies(sd->balance_interval);
interval = clamp(interval, 1UL, max_load_balance_interval);
sdg->sgc->next_update = jiffies + interval;
if (!child) {
update_cpu_capacity(sd, cpu);
return;
}
capacity_orig = capacity = 0;
if (child->flags & SD_OVERLAP) {
for_each_cpu(cpu, sched_group_cpus(sdg)) {
struct sched_group_capacity *sgc;
struct rq *rq = cpu_rq(cpu);
if (unlikely(!rq->sd)) {
capacity_orig += capacity_of(cpu);
capacity += capacity_of(cpu);
continue;
}
sgc = rq->sd->groups->sgc;
capacity_orig += sgc->capacity_orig;
capacity += sgc->capacity;
}
} else {
group = child->groups;
do {
capacity_orig += group->sgc->capacity_orig;
capacity += group->sgc->capacity;
group = group->next;
} while (group != child->groups);
}
sdg->sgc->capacity_orig = capacity_orig;
sdg->sgc->capacity = capacity;
}
static inline int
fix_small_capacity(struct sched_domain *sd, struct sched_group *group)
{
if (!(sd->flags & SD_SHARE_CPUCAPACITY))
return 0;
if (group->sgc->capacity * 32 > group->sgc->capacity_orig * 29)
return 1;
return 0;
}
static inline int sg_imbalanced(struct sched_group *group)
{
return group->sgc->imbalance;
}
static inline int sg_capacity_factor(struct lb_env *env, struct sched_group *group)
{
unsigned int capacity_factor, smt, cpus;
unsigned int capacity, capacity_orig;
capacity = group->sgc->capacity;
capacity_orig = group->sgc->capacity_orig;
cpus = group->group_weight;
smt = DIV_ROUND_UP(SCHED_CAPACITY_SCALE * cpus, capacity_orig);
capacity_factor = cpus / smt;
capacity_factor = min_t(unsigned,
capacity_factor, DIV_ROUND_CLOSEST(capacity, SCHED_CAPACITY_SCALE));
if (!capacity_factor)
capacity_factor = fix_small_capacity(env->sd, group);
return capacity_factor;
}
static enum group_type
group_classify(struct sched_group *group, struct sg_lb_stats *sgs)
{
if (sgs->sum_nr_running > sgs->group_capacity_factor)
return group_overloaded;
if (sg_imbalanced(group))
return group_imbalanced;
return group_other;
}
static inline void update_sg_lb_stats(struct lb_env *env,
struct sched_group *group, int load_idx,
int local_group, struct sg_lb_stats *sgs,
bool *overload)
{
unsigned long load;
int i;
memset(sgs, 0, sizeof(*sgs));
for_each_cpu_and(i, sched_group_cpus(group), env->cpus) {
struct rq *rq = cpu_rq(i);
if (local_group)
load = target_load(i, load_idx);
else
load = source_load(i, load_idx);
sgs->group_load += load;
sgs->sum_nr_running += rq->cfs.h_nr_running;
if (rq->nr_running > 1)
*overload = true;
#ifdef CONFIG_NUMA_BALANCING
sgs->nr_numa_running += rq->nr_numa_running;
sgs->nr_preferred_running += rq->nr_preferred_running;
#endif
sgs->sum_weighted_load += weighted_cpuload(i);
if (idle_cpu(i))
sgs->idle_cpus++;
}
sgs->group_capacity = group->sgc->capacity;
sgs->avg_load = (sgs->group_load*SCHED_CAPACITY_SCALE) / sgs->group_capacity;
if (sgs->sum_nr_running)
sgs->load_per_task = sgs->sum_weighted_load / sgs->sum_nr_running;
sgs->group_weight = group->group_weight;
sgs->group_capacity_factor = sg_capacity_factor(env, group);
sgs->group_type = group_classify(group, sgs);
if (sgs->group_capacity_factor > sgs->sum_nr_running)
sgs->group_has_free_capacity = 1;
}
static bool update_sd_pick_busiest(struct lb_env *env,
struct sd_lb_stats *sds,
struct sched_group *sg,
struct sg_lb_stats *sgs)
{
struct sg_lb_stats *busiest = &sds->busiest_stat;
if (sgs->group_type > busiest->group_type)
return true;
if (sgs->group_type < busiest->group_type)
return false;
if (sgs->avg_load <= busiest->avg_load)
return false;
if (!(env->sd->flags & SD_ASYM_PACKING))
return true;
if (sgs->sum_nr_running && env->dst_cpu < group_first_cpu(sg)) {
if (!sds->busiest)
return true;
if (group_first_cpu(sds->busiest) > group_first_cpu(sg))
return true;
}
return false;
}
static inline enum fbq_type fbq_classify_group(struct sg_lb_stats *sgs)
{
if (sgs->sum_nr_running > sgs->nr_numa_running)
return regular;
if (sgs->sum_nr_running > sgs->nr_preferred_running)
return remote;
return all;
}
static inline enum fbq_type fbq_classify_rq(struct rq *rq)
{
if (rq->nr_running > rq->nr_numa_running)
return regular;
if (rq->nr_running > rq->nr_preferred_running)
return remote;
return all;
}
static inline enum fbq_type fbq_classify_group(struct sg_lb_stats *sgs)
{
return all;
}
static inline enum fbq_type fbq_classify_rq(struct rq *rq)
{
return regular;
}
static inline void update_sd_lb_stats(struct lb_env *env, struct sd_lb_stats *sds)
{
struct sched_domain *child = env->sd->child;
struct sched_group *sg = env->sd->groups;
struct sg_lb_stats tmp_sgs;
int load_idx, prefer_sibling = 0;
bool overload = false;
if (child && child->flags & SD_PREFER_SIBLING)
prefer_sibling = 1;
load_idx = get_sd_load_idx(env->sd, env->idle);
do {
struct sg_lb_stats *sgs = &tmp_sgs;
int local_group;
local_group = cpumask_test_cpu(env->dst_cpu, sched_group_cpus(sg));
if (local_group) {
sds->local = sg;
sgs = &sds->local_stat;
if (env->idle != CPU_NEWLY_IDLE ||
time_after_eq(jiffies, sg->sgc->next_update))
update_group_capacity(env->sd, env->dst_cpu);
}
update_sg_lb_stats(env, sg, load_idx, local_group, sgs,
&overload);
if (local_group)
goto next_group;
if (prefer_sibling && sds->local &&
sds->local_stat.group_has_free_capacity) {
sgs->group_capacity_factor = min(sgs->group_capacity_factor, 1U);
sgs->group_type = group_classify(sg, sgs);
}
if (update_sd_pick_busiest(env, sds, sg, sgs)) {
sds->busiest = sg;
sds->busiest_stat = *sgs;
}
next_group:
sds->total_load += sgs->group_load;
sds->total_capacity += sgs->group_capacity;
sg = sg->next;
} while (sg != env->sd->groups);
if (env->sd->flags & SD_NUMA)
env->fbq_type = fbq_classify_group(&sds->busiest_stat);
if (!env->sd->parent) {
if (env->dst_rq->rd->overload != overload)
env->dst_rq->rd->overload = overload;
}
}
static int check_asym_packing(struct lb_env *env, struct sd_lb_stats *sds)
{
int busiest_cpu;
if (!(env->sd->flags & SD_ASYM_PACKING))
return 0;
if (!sds->busiest)
return 0;
busiest_cpu = group_first_cpu(sds->busiest);
if (env->dst_cpu > busiest_cpu)
return 0;
env->imbalance = DIV_ROUND_CLOSEST(
sds->busiest_stat.avg_load * sds->busiest_stat.group_capacity,
SCHED_CAPACITY_SCALE);
return 1;
}
static inline
void fix_small_imbalance(struct lb_env *env, struct sd_lb_stats *sds)
{
unsigned long tmp, capa_now = 0, capa_move = 0;
unsigned int imbn = 2;
unsigned long scaled_busy_load_per_task;
struct sg_lb_stats *local, *busiest;
local = &sds->local_stat;
busiest = &sds->busiest_stat;
if (!local->sum_nr_running)
local->load_per_task = cpu_avg_load_per_task(env->dst_cpu);
else if (busiest->load_per_task > local->load_per_task)
imbn = 1;
scaled_busy_load_per_task =
(busiest->load_per_task * SCHED_CAPACITY_SCALE) /
busiest->group_capacity;
if (busiest->avg_load + scaled_busy_load_per_task >=
local->avg_load + (scaled_busy_load_per_task * imbn)) {
env->imbalance = busiest->load_per_task;
return;
}
capa_now += busiest->group_capacity *
min(busiest->load_per_task, busiest->avg_load);
capa_now += local->group_capacity *
min(local->load_per_task, local->avg_load);
capa_now /= SCHED_CAPACITY_SCALE;
if (busiest->avg_load > scaled_busy_load_per_task) {
capa_move += busiest->group_capacity *
min(busiest->load_per_task,
busiest->avg_load - scaled_busy_load_per_task);
}
if (busiest->avg_load * busiest->group_capacity <
busiest->load_per_task * SCHED_CAPACITY_SCALE) {
tmp = (busiest->avg_load * busiest->group_capacity) /
local->group_capacity;
} else {
tmp = (busiest->load_per_task * SCHED_CAPACITY_SCALE) /
local->group_capacity;
}
capa_move += local->group_capacity *
min(local->load_per_task, local->avg_load + tmp);
capa_move /= SCHED_CAPACITY_SCALE;
if (capa_move > capa_now)
env->imbalance = busiest->load_per_task;
}
static inline void calculate_imbalance(struct lb_env *env, struct sd_lb_stats *sds)
{
unsigned long max_pull, load_above_capacity = ~0UL;
struct sg_lb_stats *local, *busiest;
local = &sds->local_stat;
busiest = &sds->busiest_stat;
if (busiest->group_type == group_imbalanced) {
busiest->load_per_task =
min(busiest->load_per_task, sds->avg_load);
}
if (busiest->avg_load <= sds->avg_load ||
local->avg_load >= sds->avg_load) {
env->imbalance = 0;
return fix_small_imbalance(env, sds);
}
if (busiest->group_type == group_overloaded &&
local->group_type == group_overloaded) {
load_above_capacity =
(busiest->sum_nr_running - busiest->group_capacity_factor);
load_above_capacity *= (SCHED_LOAD_SCALE * SCHED_CAPACITY_SCALE);
load_above_capacity /= busiest->group_capacity;
}
max_pull = min(busiest->avg_load - sds->avg_load, load_above_capacity);
env->imbalance = min(
max_pull * busiest->group_capacity,
(sds->avg_load - local->avg_load) * local->group_capacity
) / SCHED_CAPACITY_SCALE;
if (env->imbalance < busiest->load_per_task)
return fix_small_imbalance(env, sds);
}
static struct sched_group *find_busiest_group(struct lb_env *env)
{
struct sg_lb_stats *local, *busiest;
struct sd_lb_stats sds;
init_sd_lb_stats(&sds);
update_sd_lb_stats(env, &sds);
local = &sds.local_stat;
busiest = &sds.busiest_stat;
if ((env->idle == CPU_IDLE || env->idle == CPU_NEWLY_IDLE) &&
check_asym_packing(env, &sds))
return sds.busiest;
if (!sds.busiest || busiest->sum_nr_running == 0)
goto out_balanced;
sds.avg_load = (SCHED_CAPACITY_SCALE * sds.total_load)
/ sds.total_capacity;
if (busiest->group_type == group_imbalanced)
goto force_balance;
if (env->idle == CPU_NEWLY_IDLE && local->group_has_free_capacity &&
!busiest->group_has_free_capacity)
goto force_balance;
if (local->avg_load >= busiest->avg_load)
goto out_balanced;
if (local->avg_load >= sds.avg_load)
goto out_balanced;
if (env->idle == CPU_IDLE) {
if ((busiest->group_type != group_overloaded) &&
(local->idle_cpus <= (busiest->idle_cpus + 1)))
goto out_balanced;
} else {
if (100 * busiest->avg_load <=
env->sd->imbalance_pct * local->avg_load)
goto out_balanced;
}
force_balance:
calculate_imbalance(env, &sds);
return sds.busiest;
out_balanced:
env->imbalance = 0;
return NULL;
}
static struct rq *find_busiest_queue(struct lb_env *env,
struct sched_group *group)
{
struct rq *busiest = NULL, *rq;
unsigned long busiest_load = 0, busiest_capacity = 1;
int i;
for_each_cpu_and(i, sched_group_cpus(group), env->cpus) {
unsigned long capacity, capacity_factor, wl;
enum fbq_type rt;
rq = cpu_rq(i);
rt = fbq_classify_rq(rq);
if (rt > env->fbq_type)
continue;
capacity = capacity_of(i);
capacity_factor = DIV_ROUND_CLOSEST(capacity, SCHED_CAPACITY_SCALE);
if (!capacity_factor)
capacity_factor = fix_small_capacity(env->sd, group);
wl = weighted_cpuload(i);
if (capacity_factor && rq->nr_running == 1 && wl > env->imbalance)
continue;
if (wl * busiest_capacity > busiest_load * capacity) {
busiest_load = wl;
busiest_capacity = capacity;
busiest = rq;
}
}
return busiest;
}
static int need_active_balance(struct lb_env *env)
{
struct sched_domain *sd = env->sd;
if (env->idle == CPU_NEWLY_IDLE) {
if ((sd->flags & SD_ASYM_PACKING) && env->src_cpu > env->dst_cpu)
return 1;
}
return unlikely(sd->nr_balance_failed > sd->cache_nice_tries+2);
}
static int should_we_balance(struct lb_env *env)
{
struct sched_group *sg = env->sd->groups;
struct cpumask *sg_cpus, *sg_mask;
int cpu, balance_cpu = -1;
if (env->idle == CPU_NEWLY_IDLE)
return 1;
sg_cpus = sched_group_cpus(sg);
sg_mask = sched_group_mask(sg);
for_each_cpu_and(cpu, sg_cpus, env->cpus) {
if (!cpumask_test_cpu(cpu, sg_mask) || !idle_cpu(cpu))
continue;
balance_cpu = cpu;
break;
}
if (balance_cpu == -1)
balance_cpu = group_balance_cpu(sg);
return balance_cpu == env->dst_cpu;
}
static int load_balance(int this_cpu, struct rq *this_rq,
struct sched_domain *sd, enum cpu_idle_type idle,
int *continue_balancing)
{
int ld_moved, cur_ld_moved, active_balance = 0;
struct sched_domain *sd_parent = sd->parent;
struct sched_group *group;
struct rq *busiest;
unsigned long flags;
struct cpumask *cpus = this_cpu_cpumask_var_ptr(load_balance_mask);
struct lb_env env = {
.sd = sd,
.dst_cpu = this_cpu,
.dst_rq = this_rq,
.dst_grpmask = sched_group_cpus(sd->groups),
.idle = idle,
.loop_break = sched_nr_migrate_break,
.cpus = cpus,
.fbq_type = all,
.tasks = LIST_HEAD_INIT(env.tasks),
};
if (idle == CPU_NEWLY_IDLE)
env.dst_grpmask = NULL;
cpumask_copy(cpus, cpu_active_mask);
schedstat_inc(sd, lb_count[idle]);
redo:
if (!should_we_balance(&env)) {
*continue_balancing = 0;
goto out_balanced;
}
group = find_busiest_group(&env);
if (!group) {
schedstat_inc(sd, lb_nobusyg[idle]);
goto out_balanced;
}
busiest = find_busiest_queue(&env, group);
if (!busiest) {
schedstat_inc(sd, lb_nobusyq[idle]);
goto out_balanced;
}
BUG_ON(busiest == env.dst_rq);
schedstat_add(sd, lb_imbalance[idle], env.imbalance);
ld_moved = 0;
if (busiest->nr_running > 1) {
env.flags |= LBF_ALL_PINNED;
env.src_cpu = busiest->cpu;
env.src_rq = busiest;
env.loop_max = min(sysctl_sched_nr_migrate, busiest->nr_running);
more_balance:
raw_spin_lock_irqsave(&busiest->lock, flags);
cur_ld_moved = detach_tasks(&env);
raw_spin_unlock(&busiest->lock);
if (cur_ld_moved) {
attach_tasks(&env);
ld_moved += cur_ld_moved;
}
local_irq_restore(flags);
if (env.flags & LBF_NEED_BREAK) {
env.flags &= ~LBF_NEED_BREAK;
goto more_balance;
}
if ((env.flags & LBF_DST_PINNED) && env.imbalance > 0) {
cpumask_clear_cpu(env.dst_cpu, env.cpus);
env.dst_rq = cpu_rq(env.new_dst_cpu);
env.dst_cpu = env.new_dst_cpu;
env.flags &= ~LBF_DST_PINNED;
env.loop = 0;
env.loop_break = sched_nr_migrate_break;
goto more_balance;
}
if (sd_parent) {
int *group_imbalance = &sd_parent->groups->sgc->imbalance;
if ((env.flags & LBF_SOME_PINNED) && env.imbalance > 0)
*group_imbalance = 1;
}
if (unlikely(env.flags & LBF_ALL_PINNED)) {
cpumask_clear_cpu(cpu_of(busiest), cpus);
if (!cpumask_empty(cpus)) {
env.loop = 0;
env.loop_break = sched_nr_migrate_break;
goto redo;
}
goto out_all_pinned;
}
}
if (!ld_moved) {
schedstat_inc(sd, lb_failed[idle]);
if (idle != CPU_NEWLY_IDLE)
sd->nr_balance_failed++;
if (need_active_balance(&env)) {
raw_spin_lock_irqsave(&busiest->lock, flags);
if (!cpumask_test_cpu(this_cpu,
tsk_cpus_allowed(busiest->curr))) {
raw_spin_unlock_irqrestore(&busiest->lock,
flags);
env.flags |= LBF_ALL_PINNED;
goto out_one_pinned;
}
if (!busiest->active_balance) {
busiest->active_balance = 1;
busiest->push_cpu = this_cpu;
active_balance = 1;
}
raw_spin_unlock_irqrestore(&busiest->lock, flags);
if (active_balance) {
stop_one_cpu_nowait(cpu_of(busiest),
active_load_balance_cpu_stop, busiest,
&busiest->active_balance_work);
}
sd->nr_balance_failed = sd->cache_nice_tries+1;
}
} else
sd->nr_balance_failed = 0;
if (likely(!active_balance)) {
sd->balance_interval = sd->min_interval;
} else {
if (sd->balance_interval < sd->max_interval)
sd->balance_interval *= 2;
}
goto out;
out_balanced:
if (sd_parent) {
int *group_imbalance = &sd_parent->groups->sgc->imbalance;
if (*group_imbalance)
*group_imbalance = 0;
}
out_all_pinned:
schedstat_inc(sd, lb_balanced[idle]);
sd->nr_balance_failed = 0;
out_one_pinned:
if (((env.flags & LBF_ALL_PINNED) &&
sd->balance_interval < MAX_PINNED_INTERVAL) ||
(sd->balance_interval < sd->max_interval))
sd->balance_interval *= 2;
ld_moved = 0;
out:
return ld_moved;
}
static inline unsigned long
get_sd_balance_interval(struct sched_domain *sd, int cpu_busy)
{
unsigned long interval = sd->balance_interval;
if (cpu_busy)
interval *= sd->busy_factor;
interval = msecs_to_jiffies(interval);
interval = clamp(interval, 1UL, max_load_balance_interval);
return interval;
}
static inline void
update_next_balance(struct sched_domain *sd, int cpu_busy, unsigned long *next_balance)
{
unsigned long interval, next;
interval = get_sd_balance_interval(sd, cpu_busy);
next = sd->last_balance + interval;
if (time_after(*next_balance, next))
*next_balance = next;
}
static int idle_balance(struct rq *this_rq)
{
unsigned long next_balance = jiffies + HZ;
int this_cpu = this_rq->cpu;
struct sched_domain *sd;
int pulled_task = 0;
u64 curr_cost = 0;
idle_enter_fair(this_rq);
this_rq->idle_stamp = rq_clock(this_rq);
if (this_rq->avg_idle < sysctl_sched_migration_cost ||
!this_rq->rd->overload) {
rcu_read_lock();
sd = rcu_dereference_check_sched_domain(this_rq->sd);
if (sd)
update_next_balance(sd, 0, &next_balance);
rcu_read_unlock();
goto out;
}
raw_spin_unlock(&this_rq->lock);
update_blocked_averages(this_cpu);
rcu_read_lock();
for_each_domain(this_cpu, sd) {
int continue_balancing = 1;
u64 t0, domain_cost;
if (!(sd->flags & SD_LOAD_BALANCE))
continue;
if (this_rq->avg_idle < curr_cost + sd->max_newidle_lb_cost) {
update_next_balance(sd, 0, &next_balance);
break;
}
if (sd->flags & SD_BALANCE_NEWIDLE) {
t0 = sched_clock_cpu(this_cpu);
pulled_task = load_balance(this_cpu, this_rq,
sd, CPU_NEWLY_IDLE,
&continue_balancing);
domain_cost = sched_clock_cpu(this_cpu) - t0;
if (domain_cost > sd->max_newidle_lb_cost)
sd->max_newidle_lb_cost = domain_cost;
curr_cost += domain_cost;
}
update_next_balance(sd, 0, &next_balance);
if (pulled_task || this_rq->nr_running > 0)
break;
}
rcu_read_unlock();
raw_spin_lock(&this_rq->lock);
if (curr_cost > this_rq->max_idle_balance_cost)
this_rq->max_idle_balance_cost = curr_cost;
if (this_rq->cfs.h_nr_running && !pulled_task)
pulled_task = 1;
out:
if (time_after(this_rq->next_balance, next_balance))
this_rq->next_balance = next_balance;
if (this_rq->nr_running != this_rq->cfs.h_nr_running)
pulled_task = -1;
if (pulled_task) {
idle_exit_fair(this_rq);
this_rq->idle_stamp = 0;
}
return pulled_task;
}
static int active_load_balance_cpu_stop(void *data)
{
struct rq *busiest_rq = data;
int busiest_cpu = cpu_of(busiest_rq);
int target_cpu = busiest_rq->push_cpu;
struct rq *target_rq = cpu_rq(target_cpu);
struct sched_domain *sd;
struct task_struct *p = NULL;
raw_spin_lock_irq(&busiest_rq->lock);
if (unlikely(busiest_cpu != smp_processor_id() ||
!busiest_rq->active_balance))
goto out_unlock;
if (busiest_rq->nr_running <= 1)
goto out_unlock;
BUG_ON(busiest_rq == target_rq);
rcu_read_lock();
for_each_domain(target_cpu, sd) {
if ((sd->flags & SD_LOAD_BALANCE) &&
cpumask_test_cpu(busiest_cpu, sched_domain_span(sd)))
break;
}
if (likely(sd)) {
struct lb_env env = {
.sd = sd,
.dst_cpu = target_cpu,
.dst_rq = target_rq,
.src_cpu = busiest_rq->cpu,
.src_rq = busiest_rq,
.idle = CPU_IDLE,
};
schedstat_inc(sd, alb_count);
p = detach_one_task(&env);
if (p)
schedstat_inc(sd, alb_pushed);
else
schedstat_inc(sd, alb_failed);
}
rcu_read_unlock();
out_unlock:
busiest_rq->active_balance = 0;
raw_spin_unlock(&busiest_rq->lock);
if (p)
attach_one_task(target_rq, p);
local_irq_enable();
return 0;
}
static inline int on_null_domain(struct rq *rq)
{
return unlikely(!rcu_dereference_sched(rq->sd));
}
static inline int find_new_ilb(void)
{
int ilb = cpumask_first(nohz.idle_cpus_mask);
if (ilb < nr_cpu_ids && idle_cpu(ilb))
return ilb;
return nr_cpu_ids;
}
static void nohz_balancer_kick(void)
{
int ilb_cpu;
nohz.next_balance++;
ilb_cpu = find_new_ilb();
if (ilb_cpu >= nr_cpu_ids)
return;
if (test_and_set_bit(NOHZ_BALANCE_KICK, nohz_flags(ilb_cpu)))
return;
smp_send_reschedule(ilb_cpu);
return;
}
static inline void nohz_balance_exit_idle(int cpu)
{
if (unlikely(test_bit(NOHZ_TICK_STOPPED, nohz_flags(cpu)))) {
if (likely(cpumask_test_cpu(cpu, nohz.idle_cpus_mask))) {
cpumask_clear_cpu(cpu, nohz.idle_cpus_mask);
atomic_dec(&nohz.nr_cpus);
}
clear_bit(NOHZ_TICK_STOPPED, nohz_flags(cpu));
}
}
static inline void set_cpu_sd_state_busy(void)
{
struct sched_domain *sd;
int cpu = smp_processor_id();
rcu_read_lock();
sd = rcu_dereference(per_cpu(sd_busy, cpu));
if (!sd || !sd->nohz_idle)
goto unlock;
sd->nohz_idle = 0;
atomic_inc(&sd->groups->sgc->nr_busy_cpus);
unlock:
rcu_read_unlock();
}
void set_cpu_sd_state_idle(void)
{
struct sched_domain *sd;
int cpu = smp_processor_id();
rcu_read_lock();
sd = rcu_dereference(per_cpu(sd_busy, cpu));
if (!sd || sd->nohz_idle)
goto unlock;
sd->nohz_idle = 1;
atomic_dec(&sd->groups->sgc->nr_busy_cpus);
unlock:
rcu_read_unlock();
}
void nohz_balance_enter_idle(int cpu)
{
if (!cpu_active(cpu))
return;
if (test_bit(NOHZ_TICK_STOPPED, nohz_flags(cpu)))
return;
if (on_null_domain(cpu_rq(cpu)))
return;
cpumask_set_cpu(cpu, nohz.idle_cpus_mask);
atomic_inc(&nohz.nr_cpus);
set_bit(NOHZ_TICK_STOPPED, nohz_flags(cpu));
}
static int sched_ilb_notifier(struct notifier_block *nfb,
unsigned long action, void *hcpu)
{
switch (action & ~CPU_TASKS_FROZEN) {
case CPU_DYING:
nohz_balance_exit_idle(smp_processor_id());
return NOTIFY_OK;
default:
return NOTIFY_DONE;
}
}
void update_max_interval(void)
{
max_load_balance_interval = HZ*num_online_cpus()/10;
}
static void rebalance_domains(struct rq *rq, enum cpu_idle_type idle)
{
int continue_balancing = 1;
int cpu = rq->cpu;
unsigned long interval;
struct sched_domain *sd;
unsigned long next_balance = jiffies + 60*HZ;
int update_next_balance = 0;
int need_serialize, need_decay = 0;
u64 max_cost = 0;
update_blocked_averages(cpu);
rcu_read_lock();
for_each_domain(cpu, sd) {
if (time_after(jiffies, sd->next_decay_max_lb_cost)) {
sd->max_newidle_lb_cost =
(sd->max_newidle_lb_cost * 253) / 256;
sd->next_decay_max_lb_cost = jiffies + HZ;
need_decay = 1;
}
max_cost += sd->max_newidle_lb_cost;
if (!(sd->flags & SD_LOAD_BALANCE))
continue;
if (!continue_balancing) {
if (need_decay)
continue;
break;
}
interval = get_sd_balance_interval(sd, idle != CPU_IDLE);
need_serialize = sd->flags & SD_SERIALIZE;
if (need_serialize) {
if (!spin_trylock(&balancing))
goto out;
}
if (time_after_eq(jiffies, sd->last_balance + interval)) {
if (load_balance(cpu, rq, sd, idle, &continue_balancing)) {
idle = idle_cpu(cpu) ? CPU_IDLE : CPU_NOT_IDLE;
}
sd->last_balance = jiffies;
interval = get_sd_balance_interval(sd, idle != CPU_IDLE);
}
if (need_serialize)
spin_unlock(&balancing);
out:
if (time_after(next_balance, sd->last_balance + interval)) {
next_balance = sd->last_balance + interval;
update_next_balance = 1;
}
}
if (need_decay) {
rq->max_idle_balance_cost =
max((u64)sysctl_sched_migration_cost, max_cost);
}
rcu_read_unlock();
if (likely(update_next_balance))
rq->next_balance = next_balance;
}
static void nohz_idle_balance(struct rq *this_rq, enum cpu_idle_type idle)
{
int this_cpu = this_rq->cpu;
struct rq *rq;
int balance_cpu;
if (idle != CPU_IDLE ||
!test_bit(NOHZ_BALANCE_KICK, nohz_flags(this_cpu)))
goto end;
for_each_cpu(balance_cpu, nohz.idle_cpus_mask) {
if (balance_cpu == this_cpu || !idle_cpu(balance_cpu))
continue;
if (need_resched())
break;
rq = cpu_rq(balance_cpu);
if (time_after_eq(jiffies, rq->next_balance)) {
raw_spin_lock_irq(&rq->lock);
update_rq_clock(rq);
update_idle_cpu_load(rq);
raw_spin_unlock_irq(&rq->lock);
rebalance_domains(rq, CPU_IDLE);
}
if (time_after(this_rq->next_balance, rq->next_balance))
this_rq->next_balance = rq->next_balance;
}
nohz.next_balance = this_rq->next_balance;
end:
clear_bit(NOHZ_BALANCE_KICK, nohz_flags(this_cpu));
}
static inline int nohz_kick_needed(struct rq *rq)
{
unsigned long now = jiffies;
struct sched_domain *sd;
struct sched_group_capacity *sgc;
int nr_busy, cpu = rq->cpu;
if (unlikely(rq->idle_balance))
return 0;
set_cpu_sd_state_busy();
nohz_balance_exit_idle(cpu);
if (likely(!atomic_read(&nohz.nr_cpus)))
return 0;
if (time_before(now, nohz.next_balance))
return 0;
if (rq->nr_running >= 2)
goto need_kick;
rcu_read_lock();
sd = rcu_dereference(per_cpu(sd_busy, cpu));
if (sd) {
sgc = sd->groups->sgc;
nr_busy = atomic_read(&sgc->nr_busy_cpus);
if (nr_busy > 1)
goto need_kick_unlock;
}
sd = rcu_dereference(per_cpu(sd_asym, cpu));
if (sd && (cpumask_first_and(nohz.idle_cpus_mask,
sched_domain_span(sd)) < cpu))
goto need_kick_unlock;
rcu_read_unlock();
return 0;
need_kick_unlock:
rcu_read_unlock();
need_kick:
return 1;
}
static void nohz_idle_balance(struct rq *this_rq, enum cpu_idle_type idle) { }
static void run_rebalance_domains(struct softirq_action *h)
{
struct rq *this_rq = this_rq();
enum cpu_idle_type idle = this_rq->idle_balance ?
CPU_IDLE : CPU_NOT_IDLE;
rebalance_domains(this_rq, idle);
nohz_idle_balance(this_rq, idle);
}
void trigger_load_balance(struct rq *rq)
{
if (unlikely(on_null_domain(rq)))
return;
if (time_after_eq(jiffies, rq->next_balance))
raise_softirq(SCHED_SOFTIRQ);
#ifdef CONFIG_NO_HZ_COMMON
if (nohz_kick_needed(rq))
nohz_balancer_kick();
#endif
}
static void rq_online_fair(struct rq *rq)
{
update_sysctl();
update_runtime_enabled(rq);
}
static void rq_offline_fair(struct rq *rq)
{
update_sysctl();
unthrottle_offline_cfs_rqs(rq);
}
static void task_tick_fair(struct rq *rq, struct task_struct *curr, int queued)
{
struct cfs_rq *cfs_rq;
struct sched_entity *se = &curr->se;
for_each_sched_entity(se) {
cfs_rq = cfs_rq_of(se);
entity_tick(cfs_rq, se, queued);
}
if (numabalancing_enabled)
task_tick_numa(rq, curr);
update_rq_runnable_avg(rq, 1);
}
static void task_fork_fair(struct task_struct *p)
{
struct cfs_rq *cfs_rq;
struct sched_entity *se = &p->se, *curr;
int this_cpu = smp_processor_id();
struct rq *rq = this_rq();
unsigned long flags;
raw_spin_lock_irqsave(&rq->lock, flags);
update_rq_clock(rq);
cfs_rq = task_cfs_rq(current);
curr = cfs_rq->curr;
rcu_read_lock();
__set_task_cpu(p, this_cpu);
rcu_read_unlock();
update_curr(cfs_rq);
if (curr)
se->vruntime = curr->vruntime;
place_entity(cfs_rq, se, 1);
if (sysctl_sched_child_runs_first && curr && entity_before(curr, se)) {
swap(curr->vruntime, se->vruntime);
resched_curr(rq);
}
se->vruntime -= cfs_rq->min_vruntime;
raw_spin_unlock_irqrestore(&rq->lock, flags);
}
static void
prio_changed_fair(struct rq *rq, struct task_struct *p, int oldprio)
{
if (!task_on_rq_queued(p))
return;
if (rq->curr == p) {
if (p->prio > oldprio)
resched_curr(rq);
} else
check_preempt_curr(rq, p, 0);
}
static void switched_from_fair(struct rq *rq, struct task_struct *p)
{
struct sched_entity *se = &p->se;
struct cfs_rq *cfs_rq = cfs_rq_of(se);
if (!task_on_rq_queued(p) && p->state != TASK_RUNNING) {
place_entity(cfs_rq, se, 0);
se->vruntime -= cfs_rq->min_vruntime;
}
#ifdef CONFIG_SMP
if (se->avg.decay_count) {
__synchronize_entity_decay(se);
subtract_blocked_load_contrib(cfs_rq, se->avg.load_avg_contrib);
}
#endif
}
static void switched_to_fair(struct rq *rq, struct task_struct *p)
{
#ifdef CONFIG_FAIR_GROUP_SCHED
struct sched_entity *se = &p->se;
se->depth = se->parent ? se->parent->depth + 1 : 0;
#endif
if (!task_on_rq_queued(p))
return;
if (rq->curr == p)
resched_curr(rq);
else
check_preempt_curr(rq, p, 0);
}
static void set_curr_task_fair(struct rq *rq)
{
struct sched_entity *se = &rq->curr->se;
for_each_sched_entity(se) {
struct cfs_rq *cfs_rq = cfs_rq_of(se);
set_next_entity(cfs_rq, se);
account_cfs_rq_runtime(cfs_rq, 0);
}
}
void init_cfs_rq(struct cfs_rq *cfs_rq)
{
cfs_rq->tasks_timeline = RB_ROOT;
cfs_rq->min_vruntime = (u64)(-(1LL << 20));
#ifndef CONFIG_64BIT
cfs_rq->min_vruntime_copy = cfs_rq->min_vruntime;
#endif
#ifdef CONFIG_SMP
atomic64_set(&cfs_rq->decay_counter, 1);
atomic_long_set(&cfs_rq->removed_load, 0);
#endif
}
static void task_move_group_fair(struct task_struct *p, int queued)
{
struct sched_entity *se = &p->se;
struct cfs_rq *cfs_rq;
if (!queued && (!se->sum_exec_runtime || p->state == TASK_WAKING))
queued = 1;
if (!queued)
se->vruntime -= cfs_rq_of(se)->min_vruntime;
set_task_rq(p, task_cpu(p));
se->depth = se->parent ? se->parent->depth + 1 : 0;
if (!queued) {
cfs_rq = cfs_rq_of(se);
se->vruntime += cfs_rq->min_vruntime;
#ifdef CONFIG_SMP
se->avg.decay_count = atomic64_read(&cfs_rq->decay_counter);
cfs_rq->blocked_load_avg += se->avg.load_avg_contrib;
#endif
}
}
void free_fair_sched_group(struct task_group *tg)
{
int i;
destroy_cfs_bandwidth(tg_cfs_bandwidth(tg));
for_each_possible_cpu(i) {
if (tg->cfs_rq)
kfree(tg->cfs_rq[i]);
if (tg->se)
kfree(tg->se[i]);
}
kfree(tg->cfs_rq);
kfree(tg->se);
}
int alloc_fair_sched_group(struct task_group *tg, struct task_group *parent)
{
struct cfs_rq *cfs_rq;
struct sched_entity *se;
int i;
tg->cfs_rq = kzalloc(sizeof(cfs_rq) * nr_cpu_ids, GFP_KERNEL);
if (!tg->cfs_rq)
goto err;
tg->se = kzalloc(sizeof(se) * nr_cpu_ids, GFP_KERNEL);
if (!tg->se)
goto err;
tg->shares = NICE_0_LOAD;
init_cfs_bandwidth(tg_cfs_bandwidth(tg));
for_each_possible_cpu(i) {
cfs_rq = kzalloc_node(sizeof(struct cfs_rq),
GFP_KERNEL, cpu_to_node(i));
if (!cfs_rq)
goto err;
se = kzalloc_node(sizeof(struct sched_entity),
GFP_KERNEL, cpu_to_node(i));
if (!se)
goto err_free_rq;
init_cfs_rq(cfs_rq);
init_tg_cfs_entry(tg, cfs_rq, se, i, parent->se[i]);
}
return 1;
err_free_rq:
kfree(cfs_rq);
err:
return 0;
}
void unregister_fair_sched_group(struct task_group *tg, int cpu)
{
struct rq *rq = cpu_rq(cpu);
unsigned long flags;
if (!tg->cfs_rq[cpu]->on_list)
return;
raw_spin_lock_irqsave(&rq->lock, flags);
list_del_leaf_cfs_rq(tg->cfs_rq[cpu]);
raw_spin_unlock_irqrestore(&rq->lock, flags);
}
void init_tg_cfs_entry(struct task_group *tg, struct cfs_rq *cfs_rq,
struct sched_entity *se, int cpu,
struct sched_entity *parent)
{
struct rq *rq = cpu_rq(cpu);
cfs_rq->tg = tg;
cfs_rq->rq = rq;
init_cfs_rq_runtime(cfs_rq);
tg->cfs_rq[cpu] = cfs_rq;
tg->se[cpu] = se;
if (!se)
return;
if (!parent) {
se->cfs_rq = &rq->cfs;
se->depth = 0;
} else {
se->cfs_rq = parent->my_q;
se->depth = parent->depth + 1;
}
se->my_q = cfs_rq;
update_load_set(&se->load, NICE_0_LOAD);
se->parent = parent;
}
int sched_group_set_shares(struct task_group *tg, unsigned long shares)
{
int i;
unsigned long flags;
if (!tg->se[0])
return -EINVAL;
shares = clamp(shares, scale_load(MIN_SHARES), scale_load(MAX_SHARES));
mutex_lock(&shares_mutex);
if (tg->shares == shares)
goto done;
tg->shares = shares;
for_each_possible_cpu(i) {
struct rq *rq = cpu_rq(i);
struct sched_entity *se;
se = tg->se[i];
raw_spin_lock_irqsave(&rq->lock, flags);
update_rq_clock(rq);
for_each_sched_entity(se)
update_cfs_shares(group_cfs_rq(se));
raw_spin_unlock_irqrestore(&rq->lock, flags);
}
done:
mutex_unlock(&shares_mutex);
return 0;
}
void free_fair_sched_group(struct task_group *tg) { }
int alloc_fair_sched_group(struct task_group *tg, struct task_group *parent)
{
return 1;
}
void unregister_fair_sched_group(struct task_group *tg, int cpu) { }
static unsigned int get_rr_interval_fair(struct rq *rq, struct task_struct *task)
{
struct sched_entity *se = &task->se;
unsigned int rr_interval = 0;
if (rq->cfs.load.weight)
rr_interval = NS_TO_JIFFIES(sched_slice(cfs_rq_of(se), se));
return rr_interval;
}
void print_cfs_stats(struct seq_file *m, int cpu)
{
struct cfs_rq *cfs_rq;
rcu_read_lock();
for_each_leaf_cfs_rq(cpu_rq(cpu), cfs_rq)
print_cfs_rq(m, cpu, cfs_rq);
rcu_read_unlock();
}
__init void init_sched_fair_class(void)
{
#ifdef CONFIG_SMP
open_softirq(SCHED_SOFTIRQ, run_rebalance_domains);
#ifdef CONFIG_NO_HZ_COMMON
nohz.next_balance = jiffies;
zalloc_cpumask_var(&nohz.idle_cpus_mask, GFP_NOWAIT);
cpu_notifier(sched_ilb_notifier, 0);
#endif
#endif
}
