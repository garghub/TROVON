bool memcg_kmem_is_active(struct mem_cgroup *memcg)
{
return memcg->kmem_acct_active;
}
struct mem_cgroup *mem_cgroup_from_css(struct cgroup_subsys_state *s)
{
return s ? container_of(s, struct mem_cgroup, css) : NULL;
}
struct vmpressure *memcg_to_vmpressure(struct mem_cgroup *memcg)
{
if (!memcg)
memcg = root_mem_cgroup;
return &memcg->vmpressure;
}
struct cgroup_subsys_state *vmpressure_to_css(struct vmpressure *vmpr)
{
return &container_of(vmpr, struct mem_cgroup, vmpressure)->css;
}
static inline bool mem_cgroup_is_root(struct mem_cgroup *memcg)
{
return (memcg == root_mem_cgroup);
}
static inline unsigned short mem_cgroup_id(struct mem_cgroup *memcg)
{
return memcg->css.id;
}
static inline struct mem_cgroup *mem_cgroup_from_id(unsigned short id)
{
struct cgroup_subsys_state *css;
css = css_from_id(id, &memory_cgrp_subsys);
return mem_cgroup_from_css(css);
}
void sock_update_memcg(struct sock *sk)
{
if (mem_cgroup_sockets_enabled) {
struct mem_cgroup *memcg;
struct cg_proto *cg_proto;
BUG_ON(!sk->sk_prot->proto_cgroup);
if (sk->sk_cgrp) {
BUG_ON(mem_cgroup_is_root(sk->sk_cgrp->memcg));
css_get(&sk->sk_cgrp->memcg->css);
return;
}
rcu_read_lock();
memcg = mem_cgroup_from_task(current);
cg_proto = sk->sk_prot->proto_cgroup(memcg);
if (!mem_cgroup_is_root(memcg) &&
memcg_proto_active(cg_proto) &&
css_tryget_online(&memcg->css)) {
sk->sk_cgrp = cg_proto;
}
rcu_read_unlock();
}
}
void sock_release_memcg(struct sock *sk)
{
if (mem_cgroup_sockets_enabled && sk->sk_cgrp) {
struct mem_cgroup *memcg;
WARN_ON(!sk->sk_cgrp->memcg);
memcg = sk->sk_cgrp->memcg;
css_put(&sk->sk_cgrp->memcg->css);
}
}
struct cg_proto *tcp_proto_cgroup(struct mem_cgroup *memcg)
{
if (!memcg || mem_cgroup_is_root(memcg))
return NULL;
return &memcg->tcp_mem;
}
void memcg_get_cache_ids(void)
{
down_read(&memcg_cache_ids_sem);
}
void memcg_put_cache_ids(void)
{
up_read(&memcg_cache_ids_sem);
}
static struct mem_cgroup_per_zone *
mem_cgroup_zone_zoneinfo(struct mem_cgroup *memcg, struct zone *zone)
{
int nid = zone_to_nid(zone);
int zid = zone_idx(zone);
return &memcg->nodeinfo[nid]->zoneinfo[zid];
}
struct cgroup_subsys_state *mem_cgroup_css(struct mem_cgroup *memcg)
{
return &memcg->css;
}
static struct mem_cgroup_per_zone *
mem_cgroup_page_zoneinfo(struct mem_cgroup *memcg, struct page *page)
{
int nid = page_to_nid(page);
int zid = page_zonenum(page);
return &memcg->nodeinfo[nid]->zoneinfo[zid];
}
static struct mem_cgroup_tree_per_zone *
soft_limit_tree_node_zone(int nid, int zid)
{
return &soft_limit_tree.rb_tree_per_node[nid]->rb_tree_per_zone[zid];
}
static struct mem_cgroup_tree_per_zone *
soft_limit_tree_from_page(struct page *page)
{
int nid = page_to_nid(page);
int zid = page_zonenum(page);
return &soft_limit_tree.rb_tree_per_node[nid]->rb_tree_per_zone[zid];
}
static void __mem_cgroup_insert_exceeded(struct mem_cgroup_per_zone *mz,
struct mem_cgroup_tree_per_zone *mctz,
unsigned long new_usage_in_excess)
{
struct rb_node **p = &mctz->rb_root.rb_node;
struct rb_node *parent = NULL;
struct mem_cgroup_per_zone *mz_node;
if (mz->on_tree)
return;
mz->usage_in_excess = new_usage_in_excess;
if (!mz->usage_in_excess)
return;
while (*p) {
parent = *p;
mz_node = rb_entry(parent, struct mem_cgroup_per_zone,
tree_node);
if (mz->usage_in_excess < mz_node->usage_in_excess)
p = &(*p)->rb_left;
else if (mz->usage_in_excess >= mz_node->usage_in_excess)
p = &(*p)->rb_right;
}
rb_link_node(&mz->tree_node, parent, p);
rb_insert_color(&mz->tree_node, &mctz->rb_root);
mz->on_tree = true;
}
static void __mem_cgroup_remove_exceeded(struct mem_cgroup_per_zone *mz,
struct mem_cgroup_tree_per_zone *mctz)
{
if (!mz->on_tree)
return;
rb_erase(&mz->tree_node, &mctz->rb_root);
mz->on_tree = false;
}
static void mem_cgroup_remove_exceeded(struct mem_cgroup_per_zone *mz,
struct mem_cgroup_tree_per_zone *mctz)
{
unsigned long flags;
spin_lock_irqsave(&mctz->lock, flags);
__mem_cgroup_remove_exceeded(mz, mctz);
spin_unlock_irqrestore(&mctz->lock, flags);
}
static unsigned long soft_limit_excess(struct mem_cgroup *memcg)
{
unsigned long nr_pages = page_counter_read(&memcg->memory);
unsigned long soft_limit = READ_ONCE(memcg->soft_limit);
unsigned long excess = 0;
if (nr_pages > soft_limit)
excess = nr_pages - soft_limit;
return excess;
}
static void mem_cgroup_update_tree(struct mem_cgroup *memcg, struct page *page)
{
unsigned long excess;
struct mem_cgroup_per_zone *mz;
struct mem_cgroup_tree_per_zone *mctz;
mctz = soft_limit_tree_from_page(page);
for (; memcg; memcg = parent_mem_cgroup(memcg)) {
mz = mem_cgroup_page_zoneinfo(memcg, page);
excess = soft_limit_excess(memcg);
if (excess || mz->on_tree) {
unsigned long flags;
spin_lock_irqsave(&mctz->lock, flags);
if (mz->on_tree)
__mem_cgroup_remove_exceeded(mz, mctz);
__mem_cgroup_insert_exceeded(mz, mctz, excess);
spin_unlock_irqrestore(&mctz->lock, flags);
}
}
}
static void mem_cgroup_remove_from_trees(struct mem_cgroup *memcg)
{
struct mem_cgroup_tree_per_zone *mctz;
struct mem_cgroup_per_zone *mz;
int nid, zid;
for_each_node(nid) {
for (zid = 0; zid < MAX_NR_ZONES; zid++) {
mz = &memcg->nodeinfo[nid]->zoneinfo[zid];
mctz = soft_limit_tree_node_zone(nid, zid);
mem_cgroup_remove_exceeded(mz, mctz);
}
}
}
static struct mem_cgroup_per_zone *
__mem_cgroup_largest_soft_limit_node(struct mem_cgroup_tree_per_zone *mctz)
{
struct rb_node *rightmost = NULL;
struct mem_cgroup_per_zone *mz;
retry:
mz = NULL;
rightmost = rb_last(&mctz->rb_root);
if (!rightmost)
goto done;
mz = rb_entry(rightmost, struct mem_cgroup_per_zone, tree_node);
__mem_cgroup_remove_exceeded(mz, mctz);
if (!soft_limit_excess(mz->memcg) ||
!css_tryget_online(&mz->memcg->css))
goto retry;
done:
return mz;
}
static struct mem_cgroup_per_zone *
mem_cgroup_largest_soft_limit_node(struct mem_cgroup_tree_per_zone *mctz)
{
struct mem_cgroup_per_zone *mz;
spin_lock_irq(&mctz->lock);
mz = __mem_cgroup_largest_soft_limit_node(mctz);
spin_unlock_irq(&mctz->lock);
return mz;
}
static long mem_cgroup_read_stat(struct mem_cgroup *memcg,
enum mem_cgroup_stat_index idx)
{
long val = 0;
int cpu;
get_online_cpus();
for_each_online_cpu(cpu)
val += per_cpu(memcg->stat->count[idx], cpu);
#ifdef CONFIG_HOTPLUG_CPU
spin_lock(&memcg->pcp_counter_lock);
val += memcg->nocpu_base.count[idx];
spin_unlock(&memcg->pcp_counter_lock);
#endif
put_online_cpus();
return val;
}
static unsigned long mem_cgroup_read_events(struct mem_cgroup *memcg,
enum mem_cgroup_events_index idx)
{
unsigned long val = 0;
int cpu;
get_online_cpus();
for_each_online_cpu(cpu)
val += per_cpu(memcg->stat->events[idx], cpu);
#ifdef CONFIG_HOTPLUG_CPU
spin_lock(&memcg->pcp_counter_lock);
val += memcg->nocpu_base.events[idx];
spin_unlock(&memcg->pcp_counter_lock);
#endif
put_online_cpus();
return val;
}
static void mem_cgroup_charge_statistics(struct mem_cgroup *memcg,
struct page *page,
int nr_pages)
{
if (PageAnon(page))
__this_cpu_add(memcg->stat->count[MEM_CGROUP_STAT_RSS],
nr_pages);
else
__this_cpu_add(memcg->stat->count[MEM_CGROUP_STAT_CACHE],
nr_pages);
if (PageTransHuge(page))
__this_cpu_add(memcg->stat->count[MEM_CGROUP_STAT_RSS_HUGE],
nr_pages);
if (nr_pages > 0)
__this_cpu_inc(memcg->stat->events[MEM_CGROUP_EVENTS_PGPGIN]);
else {
__this_cpu_inc(memcg->stat->events[MEM_CGROUP_EVENTS_PGPGOUT]);
nr_pages = -nr_pages;
}
__this_cpu_add(memcg->stat->nr_page_events, nr_pages);
}
unsigned long mem_cgroup_get_lru_size(struct lruvec *lruvec, enum lru_list lru)
{
struct mem_cgroup_per_zone *mz;
mz = container_of(lruvec, struct mem_cgroup_per_zone, lruvec);
return mz->lru_size[lru];
}
static unsigned long mem_cgroup_node_nr_lru_pages(struct mem_cgroup *memcg,
int nid,
unsigned int lru_mask)
{
unsigned long nr = 0;
int zid;
VM_BUG_ON((unsigned)nid >= nr_node_ids);
for (zid = 0; zid < MAX_NR_ZONES; zid++) {
struct mem_cgroup_per_zone *mz;
enum lru_list lru;
for_each_lru(lru) {
if (!(BIT(lru) & lru_mask))
continue;
mz = &memcg->nodeinfo[nid]->zoneinfo[zid];
nr += mz->lru_size[lru];
}
}
return nr;
}
static unsigned long mem_cgroup_nr_lru_pages(struct mem_cgroup *memcg,
unsigned int lru_mask)
{
unsigned long nr = 0;
int nid;
for_each_node_state(nid, N_MEMORY)
nr += mem_cgroup_node_nr_lru_pages(memcg, nid, lru_mask);
return nr;
}
static bool mem_cgroup_event_ratelimit(struct mem_cgroup *memcg,
enum mem_cgroup_events_target target)
{
unsigned long val, next;
val = __this_cpu_read(memcg->stat->nr_page_events);
next = __this_cpu_read(memcg->stat->targets[target]);
if ((long)next - (long)val < 0) {
switch (target) {
case MEM_CGROUP_TARGET_THRESH:
next = val + THRESHOLDS_EVENTS_TARGET;
break;
case MEM_CGROUP_TARGET_SOFTLIMIT:
next = val + SOFTLIMIT_EVENTS_TARGET;
break;
case MEM_CGROUP_TARGET_NUMAINFO:
next = val + NUMAINFO_EVENTS_TARGET;
break;
default:
break;
}
__this_cpu_write(memcg->stat->targets[target], next);
return true;
}
return false;
}
static void memcg_check_events(struct mem_cgroup *memcg, struct page *page)
{
if (unlikely(mem_cgroup_event_ratelimit(memcg,
MEM_CGROUP_TARGET_THRESH))) {
bool do_softlimit;
bool do_numainfo __maybe_unused;
do_softlimit = mem_cgroup_event_ratelimit(memcg,
MEM_CGROUP_TARGET_SOFTLIMIT);
#if MAX_NUMNODES > 1
do_numainfo = mem_cgroup_event_ratelimit(memcg,
MEM_CGROUP_TARGET_NUMAINFO);
#endif
mem_cgroup_threshold(memcg);
if (unlikely(do_softlimit))
mem_cgroup_update_tree(memcg, page);
#if MAX_NUMNODES > 1
if (unlikely(do_numainfo))
atomic_inc(&memcg->numainfo_events);
#endif
}
}
struct mem_cgroup *mem_cgroup_from_task(struct task_struct *p)
{
if (unlikely(!p))
return NULL;
return mem_cgroup_from_css(task_css(p, memory_cgrp_id));
}
static struct mem_cgroup *get_mem_cgroup_from_mm(struct mm_struct *mm)
{
struct mem_cgroup *memcg = NULL;
rcu_read_lock();
do {
if (unlikely(!mm))
memcg = root_mem_cgroup;
else {
memcg = mem_cgroup_from_task(rcu_dereference(mm->owner));
if (unlikely(!memcg))
memcg = root_mem_cgroup;
}
} while (!css_tryget_online(&memcg->css));
rcu_read_unlock();
return memcg;
}
struct mem_cgroup *mem_cgroup_iter(struct mem_cgroup *root,
struct mem_cgroup *prev,
struct mem_cgroup_reclaim_cookie *reclaim)
{
struct reclaim_iter *uninitialized_var(iter);
struct cgroup_subsys_state *css = NULL;
struct mem_cgroup *memcg = NULL;
struct mem_cgroup *pos = NULL;
if (mem_cgroup_disabled())
return NULL;
if (!root)
root = root_mem_cgroup;
if (prev && !reclaim)
pos = prev;
if (!root->use_hierarchy && root != root_mem_cgroup) {
if (prev)
goto out;
return root;
}
rcu_read_lock();
if (reclaim) {
struct mem_cgroup_per_zone *mz;
mz = mem_cgroup_zone_zoneinfo(root, reclaim->zone);
iter = &mz->iter[reclaim->priority];
if (prev && reclaim->generation != iter->generation)
goto out_unlock;
do {
pos = READ_ONCE(iter->position);
} while (pos && !css_tryget(&pos->css));
}
if (pos)
css = &pos->css;
for (;;) {
css = css_next_descendant_pre(css, &root->css);
if (!css) {
if (!prev)
continue;
break;
}
memcg = mem_cgroup_from_css(css);
if (css == &root->css)
break;
if (css_tryget(css)) {
if (smp_load_acquire(&memcg->initialized))
break;
css_put(css);
}
memcg = NULL;
}
if (reclaim) {
if (cmpxchg(&iter->position, pos, memcg) == pos) {
if (memcg)
css_get(&memcg->css);
if (pos)
css_put(&pos->css);
}
if (pos)
css_put(&pos->css);
if (!memcg)
iter->generation++;
else if (!prev)
reclaim->generation = iter->generation;
}
out_unlock:
rcu_read_unlock();
out:
if (prev && prev != root)
css_put(&prev->css);
return memcg;
}
void mem_cgroup_iter_break(struct mem_cgroup *root,
struct mem_cgroup *prev)
{
if (!root)
root = root_mem_cgroup;
if (prev && prev != root)
css_put(&prev->css);
}
void __mem_cgroup_count_vm_event(struct mm_struct *mm, enum vm_event_item idx)
{
struct mem_cgroup *memcg;
rcu_read_lock();
memcg = mem_cgroup_from_task(rcu_dereference(mm->owner));
if (unlikely(!memcg))
goto out;
switch (idx) {
case PGFAULT:
this_cpu_inc(memcg->stat->events[MEM_CGROUP_EVENTS_PGFAULT]);
break;
case PGMAJFAULT:
this_cpu_inc(memcg->stat->events[MEM_CGROUP_EVENTS_PGMAJFAULT]);
break;
default:
BUG();
}
out:
rcu_read_unlock();
}
struct lruvec *mem_cgroup_zone_lruvec(struct zone *zone,
struct mem_cgroup *memcg)
{
struct mem_cgroup_per_zone *mz;
struct lruvec *lruvec;
if (mem_cgroup_disabled()) {
lruvec = &zone->lruvec;
goto out;
}
mz = mem_cgroup_zone_zoneinfo(memcg, zone);
lruvec = &mz->lruvec;
out:
if (unlikely(lruvec->zone != zone))
lruvec->zone = zone;
return lruvec;
}
struct lruvec *mem_cgroup_page_lruvec(struct page *page, struct zone *zone)
{
struct mem_cgroup_per_zone *mz;
struct mem_cgroup *memcg;
struct lruvec *lruvec;
if (mem_cgroup_disabled()) {
lruvec = &zone->lruvec;
goto out;
}
memcg = page->mem_cgroup;
if (!memcg)
memcg = root_mem_cgroup;
mz = mem_cgroup_page_zoneinfo(memcg, page);
lruvec = &mz->lruvec;
out:
if (unlikely(lruvec->zone != zone))
lruvec->zone = zone;
return lruvec;
}
void mem_cgroup_update_lru_size(struct lruvec *lruvec, enum lru_list lru,
int nr_pages)
{
struct mem_cgroup_per_zone *mz;
unsigned long *lru_size;
if (mem_cgroup_disabled())
return;
mz = container_of(lruvec, struct mem_cgroup_per_zone, lruvec);
lru_size = mz->lru_size + lru;
*lru_size += nr_pages;
VM_BUG_ON((long)(*lru_size) < 0);
}
bool mem_cgroup_is_descendant(struct mem_cgroup *memcg, struct mem_cgroup *root)
{
if (root == memcg)
return true;
if (!root->use_hierarchy)
return false;
return cgroup_is_descendant(memcg->css.cgroup, root->css.cgroup);
}
bool task_in_mem_cgroup(struct task_struct *task, struct mem_cgroup *memcg)
{
struct mem_cgroup *task_memcg;
struct task_struct *p;
bool ret;
p = find_lock_task_mm(task);
if (p) {
task_memcg = get_mem_cgroup_from_mm(p->mm);
task_unlock(p);
} else {
rcu_read_lock();
task_memcg = mem_cgroup_from_task(task);
css_get(&task_memcg->css);
rcu_read_unlock();
}
ret = mem_cgroup_is_descendant(task_memcg, memcg);
css_put(&task_memcg->css);
return ret;
}
int mem_cgroup_inactive_anon_is_low(struct lruvec *lruvec)
{
unsigned long inactive_ratio;
unsigned long inactive;
unsigned long active;
unsigned long gb;
inactive = mem_cgroup_get_lru_size(lruvec, LRU_INACTIVE_ANON);
active = mem_cgroup_get_lru_size(lruvec, LRU_ACTIVE_ANON);
gb = (inactive + active) >> (30 - PAGE_SHIFT);
if (gb)
inactive_ratio = int_sqrt(10 * gb);
else
inactive_ratio = 1;
return inactive * inactive_ratio < active;
}
bool mem_cgroup_lruvec_online(struct lruvec *lruvec)
{
struct mem_cgroup_per_zone *mz;
struct mem_cgroup *memcg;
if (mem_cgroup_disabled())
return true;
mz = container_of(lruvec, struct mem_cgroup_per_zone, lruvec);
memcg = mz->memcg;
return !!(memcg->css.flags & CSS_ONLINE);
}
static unsigned long mem_cgroup_margin(struct mem_cgroup *memcg)
{
unsigned long margin = 0;
unsigned long count;
unsigned long limit;
count = page_counter_read(&memcg->memory);
limit = READ_ONCE(memcg->memory.limit);
if (count < limit)
margin = limit - count;
if (do_swap_account) {
count = page_counter_read(&memcg->memsw);
limit = READ_ONCE(memcg->memsw.limit);
if (count <= limit)
margin = min(margin, limit - count);
}
return margin;
}
int mem_cgroup_swappiness(struct mem_cgroup *memcg)
{
if (mem_cgroup_disabled() || !memcg->css.parent)
return vm_swappiness;
return memcg->swappiness;
}
static bool mem_cgroup_under_move(struct mem_cgroup *memcg)
{
struct mem_cgroup *from;
struct mem_cgroup *to;
bool ret = false;
spin_lock(&mc.lock);
from = mc.from;
to = mc.to;
if (!from)
goto unlock;
ret = mem_cgroup_is_descendant(from, memcg) ||
mem_cgroup_is_descendant(to, memcg);
unlock:
spin_unlock(&mc.lock);
return ret;
}
static bool mem_cgroup_wait_acct_move(struct mem_cgroup *memcg)
{
if (mc.moving_task && current != mc.moving_task) {
if (mem_cgroup_under_move(memcg)) {
DEFINE_WAIT(wait);
prepare_to_wait(&mc.waitq, &wait, TASK_INTERRUPTIBLE);
if (mc.moving_task)
schedule();
finish_wait(&mc.waitq, &wait);
return true;
}
}
return false;
}
void mem_cgroup_print_oom_info(struct mem_cgroup *memcg, struct task_struct *p)
{
static DEFINE_MUTEX(oom_info_lock);
struct mem_cgroup *iter;
unsigned int i;
mutex_lock(&oom_info_lock);
rcu_read_lock();
if (p) {
pr_info("Task in ");
pr_cont_cgroup_path(task_cgroup(p, memory_cgrp_id));
pr_cont(" killed as a result of limit of ");
} else {
pr_info("Memory limit reached of cgroup ");
}
pr_cont_cgroup_path(memcg->css.cgroup);
pr_cont("\n");
rcu_read_unlock();
pr_info("memory: usage %llukB, limit %llukB, failcnt %lu\n",
K((u64)page_counter_read(&memcg->memory)),
K((u64)memcg->memory.limit), memcg->memory.failcnt);
pr_info("memory+swap: usage %llukB, limit %llukB, failcnt %lu\n",
K((u64)page_counter_read(&memcg->memsw)),
K((u64)memcg->memsw.limit), memcg->memsw.failcnt);
pr_info("kmem: usage %llukB, limit %llukB, failcnt %lu\n",
K((u64)page_counter_read(&memcg->kmem)),
K((u64)memcg->kmem.limit), memcg->kmem.failcnt);
for_each_mem_cgroup_tree(iter, memcg) {
pr_info("Memory cgroup stats for ");
pr_cont_cgroup_path(iter->css.cgroup);
pr_cont(":");
for (i = 0; i < MEM_CGROUP_STAT_NSTATS; i++) {
if (i == MEM_CGROUP_STAT_SWAP && !do_swap_account)
continue;
pr_cont(" %s:%ldKB", mem_cgroup_stat_names[i],
K(mem_cgroup_read_stat(iter, i)));
}
for (i = 0; i < NR_LRU_LISTS; i++)
pr_cont(" %s:%luKB", mem_cgroup_lru_names[i],
K(mem_cgroup_nr_lru_pages(iter, BIT(i))));
pr_cont("\n");
}
mutex_unlock(&oom_info_lock);
}
static int mem_cgroup_count_children(struct mem_cgroup *memcg)
{
int num = 0;
struct mem_cgroup *iter;
for_each_mem_cgroup_tree(iter, memcg)
num++;
return num;
}
static unsigned long mem_cgroup_get_limit(struct mem_cgroup *memcg)
{
unsigned long limit;
limit = memcg->memory.limit;
if (mem_cgroup_swappiness(memcg)) {
unsigned long memsw_limit;
memsw_limit = memcg->memsw.limit;
limit = min(limit + total_swap_pages, memsw_limit);
}
return limit;
}
static void mem_cgroup_out_of_memory(struct mem_cgroup *memcg, gfp_t gfp_mask,
int order)
{
struct mem_cgroup *iter;
unsigned long chosen_points = 0;
unsigned long totalpages;
unsigned int points = 0;
struct task_struct *chosen = NULL;
if (fatal_signal_pending(current) || task_will_free_mem(current)) {
mark_tsk_oom_victim(current);
return;
}
check_panic_on_oom(CONSTRAINT_MEMCG, gfp_mask, order, NULL, memcg);
totalpages = mem_cgroup_get_limit(memcg) ? : 1;
for_each_mem_cgroup_tree(iter, memcg) {
struct css_task_iter it;
struct task_struct *task;
css_task_iter_start(&iter->css, &it);
while ((task = css_task_iter_next(&it))) {
switch (oom_scan_process_thread(task, totalpages, NULL,
false)) {
case OOM_SCAN_SELECT:
if (chosen)
put_task_struct(chosen);
chosen = task;
chosen_points = ULONG_MAX;
get_task_struct(chosen);
case OOM_SCAN_CONTINUE:
continue;
case OOM_SCAN_ABORT:
css_task_iter_end(&it);
mem_cgroup_iter_break(memcg, iter);
if (chosen)
put_task_struct(chosen);
return;
case OOM_SCAN_OK:
break;
};
points = oom_badness(task, memcg, NULL, totalpages);
if (!points || points < chosen_points)
continue;
if (points == chosen_points &&
thread_group_leader(chosen))
continue;
if (chosen)
put_task_struct(chosen);
chosen = task;
chosen_points = points;
get_task_struct(chosen);
}
css_task_iter_end(&it);
}
if (!chosen)
return;
points = chosen_points * 1000 / totalpages;
oom_kill_process(chosen, gfp_mask, order, points, totalpages, memcg,
NULL, "Memory cgroup out of memory");
}
static bool test_mem_cgroup_node_reclaimable(struct mem_cgroup *memcg,
int nid, bool noswap)
{
if (mem_cgroup_node_nr_lru_pages(memcg, nid, LRU_ALL_FILE))
return true;
if (noswap || !total_swap_pages)
return false;
if (mem_cgroup_node_nr_lru_pages(memcg, nid, LRU_ALL_ANON))
return true;
return false;
}
static void mem_cgroup_may_update_nodemask(struct mem_cgroup *memcg)
{
int nid;
if (!atomic_read(&memcg->numainfo_events))
return;
if (atomic_inc_return(&memcg->numainfo_updating) > 1)
return;
memcg->scan_nodes = node_states[N_MEMORY];
for_each_node_mask(nid, node_states[N_MEMORY]) {
if (!test_mem_cgroup_node_reclaimable(memcg, nid, false))
node_clear(nid, memcg->scan_nodes);
}
atomic_set(&memcg->numainfo_events, 0);
atomic_set(&memcg->numainfo_updating, 0);
}
int mem_cgroup_select_victim_node(struct mem_cgroup *memcg)
{
int node;
mem_cgroup_may_update_nodemask(memcg);
node = memcg->last_scanned_node;
node = next_node(node, memcg->scan_nodes);
if (node == MAX_NUMNODES)
node = first_node(memcg->scan_nodes);
if (unlikely(node == MAX_NUMNODES))
node = numa_node_id();
memcg->last_scanned_node = node;
return node;
}
int mem_cgroup_select_victim_node(struct mem_cgroup *memcg)
{
return 0;
}
static int mem_cgroup_soft_reclaim(struct mem_cgroup *root_memcg,
struct zone *zone,
gfp_t gfp_mask,
unsigned long *total_scanned)
{
struct mem_cgroup *victim = NULL;
int total = 0;
int loop = 0;
unsigned long excess;
unsigned long nr_scanned;
struct mem_cgroup_reclaim_cookie reclaim = {
.zone = zone,
.priority = 0,
};
excess = soft_limit_excess(root_memcg);
while (1) {
victim = mem_cgroup_iter(root_memcg, victim, &reclaim);
if (!victim) {
loop++;
if (loop >= 2) {
if (!total)
break;
if (total >= (excess >> 2) ||
(loop > MEM_CGROUP_MAX_RECLAIM_LOOPS))
break;
}
continue;
}
total += mem_cgroup_shrink_node_zone(victim, gfp_mask, false,
zone, &nr_scanned);
*total_scanned += nr_scanned;
if (!soft_limit_excess(root_memcg))
break;
}
mem_cgroup_iter_break(root_memcg, victim);
return total;
}
static bool mem_cgroup_oom_trylock(struct mem_cgroup *memcg)
{
struct mem_cgroup *iter, *failed = NULL;
spin_lock(&memcg_oom_lock);
for_each_mem_cgroup_tree(iter, memcg) {
if (iter->oom_lock) {
failed = iter;
mem_cgroup_iter_break(memcg, iter);
break;
} else
iter->oom_lock = true;
}
if (failed) {
for_each_mem_cgroup_tree(iter, memcg) {
if (iter == failed) {
mem_cgroup_iter_break(memcg, iter);
break;
}
iter->oom_lock = false;
}
} else
mutex_acquire(&memcg_oom_lock_dep_map, 0, 1, _RET_IP_);
spin_unlock(&memcg_oom_lock);
return !failed;
}
static void mem_cgroup_oom_unlock(struct mem_cgroup *memcg)
{
struct mem_cgroup *iter;
spin_lock(&memcg_oom_lock);
mutex_release(&memcg_oom_lock_dep_map, 1, _RET_IP_);
for_each_mem_cgroup_tree(iter, memcg)
iter->oom_lock = false;
spin_unlock(&memcg_oom_lock);
}
static void mem_cgroup_mark_under_oom(struct mem_cgroup *memcg)
{
struct mem_cgroup *iter;
for_each_mem_cgroup_tree(iter, memcg)
atomic_inc(&iter->under_oom);
}
static void mem_cgroup_unmark_under_oom(struct mem_cgroup *memcg)
{
struct mem_cgroup *iter;
for_each_mem_cgroup_tree(iter, memcg)
atomic_add_unless(&iter->under_oom, -1, 0);
}
static int memcg_oom_wake_function(wait_queue_t *wait,
unsigned mode, int sync, void *arg)
{
struct mem_cgroup *wake_memcg = (struct mem_cgroup *)arg;
struct mem_cgroup *oom_wait_memcg;
struct oom_wait_info *oom_wait_info;
oom_wait_info = container_of(wait, struct oom_wait_info, wait);
oom_wait_memcg = oom_wait_info->memcg;
if (!mem_cgroup_is_descendant(wake_memcg, oom_wait_memcg) &&
!mem_cgroup_is_descendant(oom_wait_memcg, wake_memcg))
return 0;
return autoremove_wake_function(wait, mode, sync, arg);
}
static void memcg_wakeup_oom(struct mem_cgroup *memcg)
{
atomic_inc(&memcg->oom_wakeups);
__wake_up(&memcg_oom_waitq, TASK_NORMAL, 0, memcg);
}
static void memcg_oom_recover(struct mem_cgroup *memcg)
{
if (memcg && atomic_read(&memcg->under_oom))
memcg_wakeup_oom(memcg);
}
static void mem_cgroup_oom(struct mem_cgroup *memcg, gfp_t mask, int order)
{
if (!current->memcg_oom.may_oom)
return;
css_get(&memcg->css);
current->memcg_oom.memcg = memcg;
current->memcg_oom.gfp_mask = mask;
current->memcg_oom.order = order;
}
bool mem_cgroup_oom_synchronize(bool handle)
{
struct mem_cgroup *memcg = current->memcg_oom.memcg;
struct oom_wait_info owait;
bool locked;
if (!memcg)
return false;
if (!handle || oom_killer_disabled)
goto cleanup;
owait.memcg = memcg;
owait.wait.flags = 0;
owait.wait.func = memcg_oom_wake_function;
owait.wait.private = current;
INIT_LIST_HEAD(&owait.wait.task_list);
prepare_to_wait(&memcg_oom_waitq, &owait.wait, TASK_KILLABLE);
mem_cgroup_mark_under_oom(memcg);
locked = mem_cgroup_oom_trylock(memcg);
if (locked)
mem_cgroup_oom_notify(memcg);
if (locked && !memcg->oom_kill_disable) {
mem_cgroup_unmark_under_oom(memcg);
finish_wait(&memcg_oom_waitq, &owait.wait);
mem_cgroup_out_of_memory(memcg, current->memcg_oom.gfp_mask,
current->memcg_oom.order);
} else {
schedule();
mem_cgroup_unmark_under_oom(memcg);
finish_wait(&memcg_oom_waitq, &owait.wait);
}
if (locked) {
mem_cgroup_oom_unlock(memcg);
memcg_oom_recover(memcg);
}
cleanup:
current->memcg_oom.memcg = NULL;
css_put(&memcg->css);
return true;
}
struct mem_cgroup *mem_cgroup_begin_page_stat(struct page *page)
{
struct mem_cgroup *memcg;
unsigned long flags;
rcu_read_lock();
if (mem_cgroup_disabled())
return NULL;
again:
memcg = page->mem_cgroup;
if (unlikely(!memcg))
return NULL;
if (atomic_read(&memcg->moving_account) <= 0)
return memcg;
spin_lock_irqsave(&memcg->move_lock, flags);
if (memcg != page->mem_cgroup) {
spin_unlock_irqrestore(&memcg->move_lock, flags);
goto again;
}
memcg->move_lock_task = current;
memcg->move_lock_flags = flags;
return memcg;
}
void mem_cgroup_end_page_stat(struct mem_cgroup *memcg)
{
if (memcg && memcg->move_lock_task == current) {
unsigned long flags = memcg->move_lock_flags;
memcg->move_lock_task = NULL;
memcg->move_lock_flags = 0;
spin_unlock_irqrestore(&memcg->move_lock, flags);
}
rcu_read_unlock();
}
void mem_cgroup_update_page_stat(struct mem_cgroup *memcg,
enum mem_cgroup_stat_index idx, int val)
{
VM_BUG_ON(!rcu_read_lock_held());
if (memcg)
this_cpu_add(memcg->stat->count[idx], val);
}
static bool consume_stock(struct mem_cgroup *memcg, unsigned int nr_pages)
{
struct memcg_stock_pcp *stock;
bool ret = false;
if (nr_pages > CHARGE_BATCH)
return ret;
stock = &get_cpu_var(memcg_stock);
if (memcg == stock->cached && stock->nr_pages >= nr_pages) {
stock->nr_pages -= nr_pages;
ret = true;
}
put_cpu_var(memcg_stock);
return ret;
}
static void drain_stock(struct memcg_stock_pcp *stock)
{
struct mem_cgroup *old = stock->cached;
if (stock->nr_pages) {
page_counter_uncharge(&old->memory, stock->nr_pages);
if (do_swap_account)
page_counter_uncharge(&old->memsw, stock->nr_pages);
css_put_many(&old->css, stock->nr_pages);
stock->nr_pages = 0;
}
stock->cached = NULL;
}
static void drain_local_stock(struct work_struct *dummy)
{
struct memcg_stock_pcp *stock = this_cpu_ptr(&memcg_stock);
drain_stock(stock);
clear_bit(FLUSHING_CACHED_CHARGE, &stock->flags);
}
static void refill_stock(struct mem_cgroup *memcg, unsigned int nr_pages)
{
struct memcg_stock_pcp *stock = &get_cpu_var(memcg_stock);
if (stock->cached != memcg) {
drain_stock(stock);
stock->cached = memcg;
}
stock->nr_pages += nr_pages;
put_cpu_var(memcg_stock);
}
static void drain_all_stock(struct mem_cgroup *root_memcg)
{
int cpu, curcpu;
if (!mutex_trylock(&percpu_charge_mutex))
return;
get_online_cpus();
curcpu = get_cpu();
for_each_online_cpu(cpu) {
struct memcg_stock_pcp *stock = &per_cpu(memcg_stock, cpu);
struct mem_cgroup *memcg;
memcg = stock->cached;
if (!memcg || !stock->nr_pages)
continue;
if (!mem_cgroup_is_descendant(memcg, root_memcg))
continue;
if (!test_and_set_bit(FLUSHING_CACHED_CHARGE, &stock->flags)) {
if (cpu == curcpu)
drain_local_stock(&stock->work);
else
schedule_work_on(cpu, &stock->work);
}
}
put_cpu();
put_online_cpus();
mutex_unlock(&percpu_charge_mutex);
}
static void mem_cgroup_drain_pcp_counter(struct mem_cgroup *memcg, int cpu)
{
int i;
spin_lock(&memcg->pcp_counter_lock);
for (i = 0; i < MEM_CGROUP_STAT_NSTATS; i++) {
long x = per_cpu(memcg->stat->count[i], cpu);
per_cpu(memcg->stat->count[i], cpu) = 0;
memcg->nocpu_base.count[i] += x;
}
for (i = 0; i < MEM_CGROUP_EVENTS_NSTATS; i++) {
unsigned long x = per_cpu(memcg->stat->events[i], cpu);
per_cpu(memcg->stat->events[i], cpu) = 0;
memcg->nocpu_base.events[i] += x;
}
spin_unlock(&memcg->pcp_counter_lock);
}
static int memcg_cpu_hotplug_callback(struct notifier_block *nb,
unsigned long action,
void *hcpu)
{
int cpu = (unsigned long)hcpu;
struct memcg_stock_pcp *stock;
struct mem_cgroup *iter;
if (action == CPU_ONLINE)
return NOTIFY_OK;
if (action != CPU_DEAD && action != CPU_DEAD_FROZEN)
return NOTIFY_OK;
for_each_mem_cgroup(iter)
mem_cgroup_drain_pcp_counter(iter, cpu);
stock = &per_cpu(memcg_stock, cpu);
drain_stock(stock);
return NOTIFY_OK;
}
static int try_charge(struct mem_cgroup *memcg, gfp_t gfp_mask,
unsigned int nr_pages)
{
unsigned int batch = max(CHARGE_BATCH, nr_pages);
int nr_retries = MEM_CGROUP_RECLAIM_RETRIES;
struct mem_cgroup *mem_over_limit;
struct page_counter *counter;
unsigned long nr_reclaimed;
bool may_swap = true;
bool drained = false;
int ret = 0;
if (mem_cgroup_is_root(memcg))
goto done;
retry:
if (consume_stock(memcg, nr_pages))
goto done;
if (!do_swap_account ||
!page_counter_try_charge(&memcg->memsw, batch, &counter)) {
if (!page_counter_try_charge(&memcg->memory, batch, &counter))
goto done_restock;
if (do_swap_account)
page_counter_uncharge(&memcg->memsw, batch);
mem_over_limit = mem_cgroup_from_counter(counter, memory);
} else {
mem_over_limit = mem_cgroup_from_counter(counter, memsw);
may_swap = false;
}
if (batch > nr_pages) {
batch = nr_pages;
goto retry;
}
if (unlikely(test_thread_flag(TIF_MEMDIE) ||
fatal_signal_pending(current) ||
current->flags & PF_EXITING))
goto bypass;
if (unlikely(task_in_memcg_oom(current)))
goto nomem;
if (!(gfp_mask & __GFP_WAIT))
goto nomem;
mem_cgroup_events(mem_over_limit, MEMCG_MAX, 1);
nr_reclaimed = try_to_free_mem_cgroup_pages(mem_over_limit, nr_pages,
gfp_mask, may_swap);
if (mem_cgroup_margin(mem_over_limit) >= nr_pages)
goto retry;
if (!drained) {
drain_all_stock(mem_over_limit);
drained = true;
goto retry;
}
if (gfp_mask & __GFP_NORETRY)
goto nomem;
if (nr_reclaimed && nr_pages <= (1 << PAGE_ALLOC_COSTLY_ORDER))
goto retry;
if (mem_cgroup_wait_acct_move(mem_over_limit))
goto retry;
if (nr_retries--)
goto retry;
if (gfp_mask & __GFP_NOFAIL)
goto bypass;
if (fatal_signal_pending(current))
goto bypass;
mem_cgroup_events(mem_over_limit, MEMCG_OOM, 1);
mem_cgroup_oom(mem_over_limit, gfp_mask, get_order(nr_pages));
nomem:
if (!(gfp_mask & __GFP_NOFAIL))
return -ENOMEM;
bypass:
return -EINTR;
done_restock:
css_get_many(&memcg->css, batch);
if (batch > nr_pages)
refill_stock(memcg, batch - nr_pages);
if (!(gfp_mask & __GFP_WAIT))
goto done;
do {
if (page_counter_read(&memcg->memory) <= memcg->high)
continue;
mem_cgroup_events(memcg, MEMCG_HIGH, 1);
try_to_free_mem_cgroup_pages(memcg, nr_pages, gfp_mask, true);
} while ((memcg = parent_mem_cgroup(memcg)));
done:
return ret;
}
static void cancel_charge(struct mem_cgroup *memcg, unsigned int nr_pages)
{
if (mem_cgroup_is_root(memcg))
return;
page_counter_uncharge(&memcg->memory, nr_pages);
if (do_swap_account)
page_counter_uncharge(&memcg->memsw, nr_pages);
css_put_many(&memcg->css, nr_pages);
}
struct mem_cgroup *try_get_mem_cgroup_from_page(struct page *page)
{
struct mem_cgroup *memcg;
unsigned short id;
swp_entry_t ent;
VM_BUG_ON_PAGE(!PageLocked(page), page);
memcg = page->mem_cgroup;
if (memcg) {
if (!css_tryget_online(&memcg->css))
memcg = NULL;
} else if (PageSwapCache(page)) {
ent.val = page_private(page);
id = lookup_swap_cgroup_id(ent);
rcu_read_lock();
memcg = mem_cgroup_from_id(id);
if (memcg && !css_tryget_online(&memcg->css))
memcg = NULL;
rcu_read_unlock();
}
return memcg;
}
static void lock_page_lru(struct page *page, int *isolated)
{
struct zone *zone = page_zone(page);
spin_lock_irq(&zone->lru_lock);
if (PageLRU(page)) {
struct lruvec *lruvec;
lruvec = mem_cgroup_page_lruvec(page, zone);
ClearPageLRU(page);
del_page_from_lru_list(page, lruvec, page_lru(page));
*isolated = 1;
} else
*isolated = 0;
}
static void unlock_page_lru(struct page *page, int isolated)
{
struct zone *zone = page_zone(page);
if (isolated) {
struct lruvec *lruvec;
lruvec = mem_cgroup_page_lruvec(page, zone);
VM_BUG_ON_PAGE(PageLRU(page), page);
SetPageLRU(page);
add_page_to_lru_list(page, lruvec, page_lru(page));
}
spin_unlock_irq(&zone->lru_lock);
}
static void commit_charge(struct page *page, struct mem_cgroup *memcg,
bool lrucare)
{
int isolated;
VM_BUG_ON_PAGE(page->mem_cgroup, page);
if (lrucare)
lock_page_lru(page, &isolated);
page->mem_cgroup = memcg;
if (lrucare)
unlock_page_lru(page, isolated);
}
int memcg_charge_kmem(struct mem_cgroup *memcg, gfp_t gfp,
unsigned long nr_pages)
{
struct page_counter *counter;
int ret = 0;
ret = page_counter_try_charge(&memcg->kmem, nr_pages, &counter);
if (ret < 0)
return ret;
ret = try_charge(memcg, gfp, nr_pages);
if (ret == -EINTR) {
page_counter_charge(&memcg->memory, nr_pages);
if (do_swap_account)
page_counter_charge(&memcg->memsw, nr_pages);
css_get_many(&memcg->css, nr_pages);
ret = 0;
} else if (ret)
page_counter_uncharge(&memcg->kmem, nr_pages);
return ret;
}
void memcg_uncharge_kmem(struct mem_cgroup *memcg, unsigned long nr_pages)
{
page_counter_uncharge(&memcg->memory, nr_pages);
if (do_swap_account)
page_counter_uncharge(&memcg->memsw, nr_pages);
page_counter_uncharge(&memcg->kmem, nr_pages);
css_put_many(&memcg->css, nr_pages);
}
int memcg_cache_id(struct mem_cgroup *memcg)
{
return memcg ? memcg->kmemcg_id : -1;
}
static int memcg_alloc_cache_id(void)
{
int id, size;
int err;
id = ida_simple_get(&memcg_cache_ida,
0, MEMCG_CACHES_MAX_SIZE, GFP_KERNEL);
if (id < 0)
return id;
if (id < memcg_nr_cache_ids)
return id;
down_write(&memcg_cache_ids_sem);
size = 2 * (id + 1);
if (size < MEMCG_CACHES_MIN_SIZE)
size = MEMCG_CACHES_MIN_SIZE;
else if (size > MEMCG_CACHES_MAX_SIZE)
size = MEMCG_CACHES_MAX_SIZE;
err = memcg_update_all_caches(size);
if (!err)
err = memcg_update_all_list_lrus(size);
if (!err)
memcg_nr_cache_ids = size;
up_write(&memcg_cache_ids_sem);
if (err) {
ida_simple_remove(&memcg_cache_ida, id);
return err;
}
return id;
}
static void memcg_free_cache_id(int id)
{
ida_simple_remove(&memcg_cache_ida, id);
}
static void memcg_kmem_cache_create_func(struct work_struct *w)
{
struct memcg_kmem_cache_create_work *cw =
container_of(w, struct memcg_kmem_cache_create_work, work);
struct mem_cgroup *memcg = cw->memcg;
struct kmem_cache *cachep = cw->cachep;
memcg_create_kmem_cache(memcg, cachep);
css_put(&memcg->css);
kfree(cw);
}
static void __memcg_schedule_kmem_cache_create(struct mem_cgroup *memcg,
struct kmem_cache *cachep)
{
struct memcg_kmem_cache_create_work *cw;
cw = kmalloc(sizeof(*cw), GFP_NOWAIT);
if (!cw)
return;
css_get(&memcg->css);
cw->memcg = memcg;
cw->cachep = cachep;
INIT_WORK(&cw->work, memcg_kmem_cache_create_func);
schedule_work(&cw->work);
}
static void memcg_schedule_kmem_cache_create(struct mem_cgroup *memcg,
struct kmem_cache *cachep)
{
current->memcg_kmem_skip_account = 1;
__memcg_schedule_kmem_cache_create(memcg, cachep);
current->memcg_kmem_skip_account = 0;
}
struct kmem_cache *__memcg_kmem_get_cache(struct kmem_cache *cachep)
{
struct mem_cgroup *memcg;
struct kmem_cache *memcg_cachep;
int kmemcg_id;
VM_BUG_ON(!is_root_cache(cachep));
if (current->memcg_kmem_skip_account)
return cachep;
memcg = get_mem_cgroup_from_mm(current->mm);
kmemcg_id = READ_ONCE(memcg->kmemcg_id);
if (kmemcg_id < 0)
goto out;
memcg_cachep = cache_from_memcg_idx(cachep, kmemcg_id);
if (likely(memcg_cachep))
return memcg_cachep;
memcg_schedule_kmem_cache_create(memcg, cachep);
out:
css_put(&memcg->css);
return cachep;
}
void __memcg_kmem_put_cache(struct kmem_cache *cachep)
{
if (!is_root_cache(cachep))
css_put(&cachep->memcg_params.memcg->css);
}
bool
__memcg_kmem_newpage_charge(gfp_t gfp, struct mem_cgroup **_memcg, int order)
{
struct mem_cgroup *memcg;
int ret;
*_memcg = NULL;
memcg = get_mem_cgroup_from_mm(current->mm);
if (!memcg_kmem_is_active(memcg)) {
css_put(&memcg->css);
return true;
}
ret = memcg_charge_kmem(memcg, gfp, 1 << order);
if (!ret)
*_memcg = memcg;
css_put(&memcg->css);
return (ret == 0);
}
void __memcg_kmem_commit_charge(struct page *page, struct mem_cgroup *memcg,
int order)
{
VM_BUG_ON(mem_cgroup_is_root(memcg));
if (!page) {
memcg_uncharge_kmem(memcg, 1 << order);
return;
}
page->mem_cgroup = memcg;
}
void __memcg_kmem_uncharge_pages(struct page *page, int order)
{
struct mem_cgroup *memcg = page->mem_cgroup;
if (!memcg)
return;
VM_BUG_ON_PAGE(mem_cgroup_is_root(memcg), page);
memcg_uncharge_kmem(memcg, 1 << order);
page->mem_cgroup = NULL;
}
struct mem_cgroup *__mem_cgroup_from_kmem(void *ptr)
{
struct mem_cgroup *memcg = NULL;
struct kmem_cache *cachep;
struct page *page;
page = virt_to_head_page(ptr);
if (PageSlab(page)) {
cachep = page->slab_cache;
if (!is_root_cache(cachep))
memcg = cachep->memcg_params.memcg;
} else
memcg = page->mem_cgroup;
return memcg;
}
void mem_cgroup_split_huge_fixup(struct page *head)
{
int i;
if (mem_cgroup_disabled())
return;
for (i = 1; i < HPAGE_PMD_NR; i++)
head[i].mem_cgroup = head->mem_cgroup;
__this_cpu_sub(head->mem_cgroup->stat->count[MEM_CGROUP_STAT_RSS_HUGE],
HPAGE_PMD_NR);
}
static void mem_cgroup_swap_statistics(struct mem_cgroup *memcg,
bool charge)
{
int val = (charge) ? 1 : -1;
this_cpu_add(memcg->stat->count[MEM_CGROUP_STAT_SWAP], val);
}
static int mem_cgroup_move_swap_account(swp_entry_t entry,
struct mem_cgroup *from, struct mem_cgroup *to)
{
unsigned short old_id, new_id;
old_id = mem_cgroup_id(from);
new_id = mem_cgroup_id(to);
if (swap_cgroup_cmpxchg(entry, old_id, new_id) == old_id) {
mem_cgroup_swap_statistics(from, false);
mem_cgroup_swap_statistics(to, true);
return 0;
}
return -EINVAL;
}
static inline int mem_cgroup_move_swap_account(swp_entry_t entry,
struct mem_cgroup *from, struct mem_cgroup *to)
{
return -EINVAL;
}
static int mem_cgroup_resize_limit(struct mem_cgroup *memcg,
unsigned long limit)
{
unsigned long curusage;
unsigned long oldusage;
bool enlarge = false;
int retry_count;
int ret;
retry_count = MEM_CGROUP_RECLAIM_RETRIES *
mem_cgroup_count_children(memcg);
oldusage = page_counter_read(&memcg->memory);
do {
if (signal_pending(current)) {
ret = -EINTR;
break;
}
mutex_lock(&memcg_limit_mutex);
if (limit > memcg->memsw.limit) {
mutex_unlock(&memcg_limit_mutex);
ret = -EINVAL;
break;
}
if (limit > memcg->memory.limit)
enlarge = true;
ret = page_counter_limit(&memcg->memory, limit);
mutex_unlock(&memcg_limit_mutex);
if (!ret)
break;
try_to_free_mem_cgroup_pages(memcg, 1, GFP_KERNEL, true);
curusage = page_counter_read(&memcg->memory);
if (curusage >= oldusage)
retry_count--;
else
oldusage = curusage;
} while (retry_count);
if (!ret && enlarge)
memcg_oom_recover(memcg);
return ret;
}
static int mem_cgroup_resize_memsw_limit(struct mem_cgroup *memcg,
unsigned long limit)
{
unsigned long curusage;
unsigned long oldusage;
bool enlarge = false;
int retry_count;
int ret;
retry_count = MEM_CGROUP_RECLAIM_RETRIES *
mem_cgroup_count_children(memcg);
oldusage = page_counter_read(&memcg->memsw);
do {
if (signal_pending(current)) {
ret = -EINTR;
break;
}
mutex_lock(&memcg_limit_mutex);
if (limit < memcg->memory.limit) {
mutex_unlock(&memcg_limit_mutex);
ret = -EINVAL;
break;
}
if (limit > memcg->memsw.limit)
enlarge = true;
ret = page_counter_limit(&memcg->memsw, limit);
mutex_unlock(&memcg_limit_mutex);
if (!ret)
break;
try_to_free_mem_cgroup_pages(memcg, 1, GFP_KERNEL, false);
curusage = page_counter_read(&memcg->memsw);
if (curusage >= oldusage)
retry_count--;
else
oldusage = curusage;
} while (retry_count);
if (!ret && enlarge)
memcg_oom_recover(memcg);
return ret;
}
unsigned long mem_cgroup_soft_limit_reclaim(struct zone *zone, int order,
gfp_t gfp_mask,
unsigned long *total_scanned)
{
unsigned long nr_reclaimed = 0;
struct mem_cgroup_per_zone *mz, *next_mz = NULL;
unsigned long reclaimed;
int loop = 0;
struct mem_cgroup_tree_per_zone *mctz;
unsigned long excess;
unsigned long nr_scanned;
if (order > 0)
return 0;
mctz = soft_limit_tree_node_zone(zone_to_nid(zone), zone_idx(zone));
do {
if (next_mz)
mz = next_mz;
else
mz = mem_cgroup_largest_soft_limit_node(mctz);
if (!mz)
break;
nr_scanned = 0;
reclaimed = mem_cgroup_soft_reclaim(mz->memcg, zone,
gfp_mask, &nr_scanned);
nr_reclaimed += reclaimed;
*total_scanned += nr_scanned;
spin_lock_irq(&mctz->lock);
__mem_cgroup_remove_exceeded(mz, mctz);
next_mz = NULL;
if (!reclaimed)
next_mz = __mem_cgroup_largest_soft_limit_node(mctz);
excess = soft_limit_excess(mz->memcg);
__mem_cgroup_insert_exceeded(mz, mctz, excess);
spin_unlock_irq(&mctz->lock);
css_put(&mz->memcg->css);
loop++;
if (!nr_reclaimed &&
(next_mz == NULL ||
loop > MEM_CGROUP_MAX_SOFT_LIMIT_RECLAIM_LOOPS))
break;
} while (!nr_reclaimed);
if (next_mz)
css_put(&next_mz->memcg->css);
return nr_reclaimed;
}
static inline bool memcg_has_children(struct mem_cgroup *memcg)
{
bool ret;
lockdep_assert_held(&memcg_create_mutex);
rcu_read_lock();
ret = css_next_child(NULL, &memcg->css);
rcu_read_unlock();
return ret;
}
static int mem_cgroup_force_empty(struct mem_cgroup *memcg)
{
int nr_retries = MEM_CGROUP_RECLAIM_RETRIES;
lru_add_drain_all();
while (nr_retries && page_counter_read(&memcg->memory)) {
int progress;
if (signal_pending(current))
return -EINTR;
progress = try_to_free_mem_cgroup_pages(memcg, 1,
GFP_KERNEL, true);
if (!progress) {
nr_retries--;
congestion_wait(BLK_RW_ASYNC, HZ/10);
}
}
return 0;
}
static ssize_t mem_cgroup_force_empty_write(struct kernfs_open_file *of,
char *buf, size_t nbytes,
loff_t off)
{
struct mem_cgroup *memcg = mem_cgroup_from_css(of_css(of));
if (mem_cgroup_is_root(memcg))
return -EINVAL;
return mem_cgroup_force_empty(memcg) ?: nbytes;
}
static u64 mem_cgroup_hierarchy_read(struct cgroup_subsys_state *css,
struct cftype *cft)
{
return mem_cgroup_from_css(css)->use_hierarchy;
}
static int mem_cgroup_hierarchy_write(struct cgroup_subsys_state *css,
struct cftype *cft, u64 val)
{
int retval = 0;
struct mem_cgroup *memcg = mem_cgroup_from_css(css);
struct mem_cgroup *parent_memcg = mem_cgroup_from_css(memcg->css.parent);
mutex_lock(&memcg_create_mutex);
if (memcg->use_hierarchy == val)
goto out;
if ((!parent_memcg || !parent_memcg->use_hierarchy) &&
(val == 1 || val == 0)) {
if (!memcg_has_children(memcg))
memcg->use_hierarchy = val;
else
retval = -EBUSY;
} else
retval = -EINVAL;
out:
mutex_unlock(&memcg_create_mutex);
return retval;
}
static unsigned long tree_stat(struct mem_cgroup *memcg,
enum mem_cgroup_stat_index idx)
{
struct mem_cgroup *iter;
long val = 0;
for_each_mem_cgroup_tree(iter, memcg)
val += mem_cgroup_read_stat(iter, idx);
if (val < 0)
val = 0;
return val;
}
static inline u64 mem_cgroup_usage(struct mem_cgroup *memcg, bool swap)
{
u64 val;
if (mem_cgroup_is_root(memcg)) {
val = tree_stat(memcg, MEM_CGROUP_STAT_CACHE);
val += tree_stat(memcg, MEM_CGROUP_STAT_RSS);
if (swap)
val += tree_stat(memcg, MEM_CGROUP_STAT_SWAP);
} else {
if (!swap)
val = page_counter_read(&memcg->memory);
else
val = page_counter_read(&memcg->memsw);
}
return val << PAGE_SHIFT;
}
static u64 mem_cgroup_read_u64(struct cgroup_subsys_state *css,
struct cftype *cft)
{
struct mem_cgroup *memcg = mem_cgroup_from_css(css);
struct page_counter *counter;
switch (MEMFILE_TYPE(cft->private)) {
case _MEM:
counter = &memcg->memory;
break;
case _MEMSWAP:
counter = &memcg->memsw;
break;
case _KMEM:
counter = &memcg->kmem;
break;
default:
BUG();
}
switch (MEMFILE_ATTR(cft->private)) {
case RES_USAGE:
if (counter == &memcg->memory)
return mem_cgroup_usage(memcg, false);
if (counter == &memcg->memsw)
return mem_cgroup_usage(memcg, true);
return (u64)page_counter_read(counter) * PAGE_SIZE;
case RES_LIMIT:
return (u64)counter->limit * PAGE_SIZE;
case RES_MAX_USAGE:
return (u64)counter->watermark * PAGE_SIZE;
case RES_FAILCNT:
return counter->failcnt;
case RES_SOFT_LIMIT:
return (u64)memcg->soft_limit * PAGE_SIZE;
default:
BUG();
}
}
static int memcg_activate_kmem(struct mem_cgroup *memcg,
unsigned long nr_pages)
{
int err = 0;
int memcg_id;
BUG_ON(memcg->kmemcg_id >= 0);
BUG_ON(memcg->kmem_acct_activated);
BUG_ON(memcg->kmem_acct_active);
mutex_lock(&memcg_create_mutex);
if (cgroup_has_tasks(memcg->css.cgroup) ||
(memcg->use_hierarchy && memcg_has_children(memcg)))
err = -EBUSY;
mutex_unlock(&memcg_create_mutex);
if (err)
goto out;
memcg_id = memcg_alloc_cache_id();
if (memcg_id < 0) {
err = memcg_id;
goto out;
}
err = page_counter_limit(&memcg->kmem, nr_pages);
VM_BUG_ON(err);
static_key_slow_inc(&memcg_kmem_enabled_key);
memcg->kmemcg_id = memcg_id;
memcg->kmem_acct_activated = true;
memcg->kmem_acct_active = true;
out:
return err;
}
static int memcg_update_kmem_limit(struct mem_cgroup *memcg,
unsigned long limit)
{
int ret;
mutex_lock(&memcg_limit_mutex);
if (!memcg_kmem_is_active(memcg))
ret = memcg_activate_kmem(memcg, limit);
else
ret = page_counter_limit(&memcg->kmem, limit);
mutex_unlock(&memcg_limit_mutex);
return ret;
}
static int memcg_propagate_kmem(struct mem_cgroup *memcg)
{
int ret = 0;
struct mem_cgroup *parent = parent_mem_cgroup(memcg);
if (!parent)
return 0;
mutex_lock(&memcg_limit_mutex);
if (memcg_kmem_is_active(parent))
ret = memcg_activate_kmem(memcg, PAGE_COUNTER_MAX);
mutex_unlock(&memcg_limit_mutex);
return ret;
}
static int memcg_update_kmem_limit(struct mem_cgroup *memcg,
unsigned long limit)
{
return -EINVAL;
}
static ssize_t mem_cgroup_write(struct kernfs_open_file *of,
char *buf, size_t nbytes, loff_t off)
{
struct mem_cgroup *memcg = mem_cgroup_from_css(of_css(of));
unsigned long nr_pages;
int ret;
buf = strstrip(buf);
ret = page_counter_memparse(buf, "-1", &nr_pages);
if (ret)
return ret;
switch (MEMFILE_ATTR(of_cft(of)->private)) {
case RES_LIMIT:
if (mem_cgroup_is_root(memcg)) {
ret = -EINVAL;
break;
}
switch (MEMFILE_TYPE(of_cft(of)->private)) {
case _MEM:
ret = mem_cgroup_resize_limit(memcg, nr_pages);
break;
case _MEMSWAP:
ret = mem_cgroup_resize_memsw_limit(memcg, nr_pages);
break;
case _KMEM:
ret = memcg_update_kmem_limit(memcg, nr_pages);
break;
}
break;
case RES_SOFT_LIMIT:
memcg->soft_limit = nr_pages;
ret = 0;
break;
}
return ret ?: nbytes;
}
static ssize_t mem_cgroup_reset(struct kernfs_open_file *of, char *buf,
size_t nbytes, loff_t off)
{
struct mem_cgroup *memcg = mem_cgroup_from_css(of_css(of));
struct page_counter *counter;
switch (MEMFILE_TYPE(of_cft(of)->private)) {
case _MEM:
counter = &memcg->memory;
break;
case _MEMSWAP:
counter = &memcg->memsw;
break;
case _KMEM:
counter = &memcg->kmem;
break;
default:
BUG();
}
switch (MEMFILE_ATTR(of_cft(of)->private)) {
case RES_MAX_USAGE:
page_counter_reset_watermark(counter);
break;
case RES_FAILCNT:
counter->failcnt = 0;
break;
default:
BUG();
}
return nbytes;
}
static u64 mem_cgroup_move_charge_read(struct cgroup_subsys_state *css,
struct cftype *cft)
{
return mem_cgroup_from_css(css)->move_charge_at_immigrate;
}
static int mem_cgroup_move_charge_write(struct cgroup_subsys_state *css,
struct cftype *cft, u64 val)
{
struct mem_cgroup *memcg = mem_cgroup_from_css(css);
if (val & ~MOVE_MASK)
return -EINVAL;
memcg->move_charge_at_immigrate = val;
return 0;
}
static int mem_cgroup_move_charge_write(struct cgroup_subsys_state *css,
struct cftype *cft, u64 val)
{
return -ENOSYS;
}
static int memcg_numa_stat_show(struct seq_file *m, void *v)
{
struct numa_stat {
const char *name;
unsigned int lru_mask;
};
static const struct numa_stat stats[] = {
{ "total", LRU_ALL },
{ "file", LRU_ALL_FILE },
{ "anon", LRU_ALL_ANON },
{ "unevictable", BIT(LRU_UNEVICTABLE) },
};
const struct numa_stat *stat;
int nid;
unsigned long nr;
struct mem_cgroup *memcg = mem_cgroup_from_css(seq_css(m));
for (stat = stats; stat < stats + ARRAY_SIZE(stats); stat++) {
nr = mem_cgroup_nr_lru_pages(memcg, stat->lru_mask);
seq_printf(m, "%s=%lu", stat->name, nr);
for_each_node_state(nid, N_MEMORY) {
nr = mem_cgroup_node_nr_lru_pages(memcg, nid,
stat->lru_mask);
seq_printf(m, " N%d=%lu", nid, nr);
}
seq_putc(m, '\n');
}
for (stat = stats; stat < stats + ARRAY_SIZE(stats); stat++) {
struct mem_cgroup *iter;
nr = 0;
for_each_mem_cgroup_tree(iter, memcg)
nr += mem_cgroup_nr_lru_pages(iter, stat->lru_mask);
seq_printf(m, "hierarchical_%s=%lu", stat->name, nr);
for_each_node_state(nid, N_MEMORY) {
nr = 0;
for_each_mem_cgroup_tree(iter, memcg)
nr += mem_cgroup_node_nr_lru_pages(
iter, nid, stat->lru_mask);
seq_printf(m, " N%d=%lu", nid, nr);
}
seq_putc(m, '\n');
}
return 0;
}
static int memcg_stat_show(struct seq_file *m, void *v)
{
struct mem_cgroup *memcg = mem_cgroup_from_css(seq_css(m));
unsigned long memory, memsw;
struct mem_cgroup *mi;
unsigned int i;
BUILD_BUG_ON(ARRAY_SIZE(mem_cgroup_stat_names) !=
MEM_CGROUP_STAT_NSTATS);
BUILD_BUG_ON(ARRAY_SIZE(mem_cgroup_events_names) !=
MEM_CGROUP_EVENTS_NSTATS);
BUILD_BUG_ON(ARRAY_SIZE(mem_cgroup_lru_names) != NR_LRU_LISTS);
for (i = 0; i < MEM_CGROUP_STAT_NSTATS; i++) {
if (i == MEM_CGROUP_STAT_SWAP && !do_swap_account)
continue;
seq_printf(m, "%s %ld\n", mem_cgroup_stat_names[i],
mem_cgroup_read_stat(memcg, i) * PAGE_SIZE);
}
for (i = 0; i < MEM_CGROUP_EVENTS_NSTATS; i++)
seq_printf(m, "%s %lu\n", mem_cgroup_events_names[i],
mem_cgroup_read_events(memcg, i));
for (i = 0; i < NR_LRU_LISTS; i++)
seq_printf(m, "%s %lu\n", mem_cgroup_lru_names[i],
mem_cgroup_nr_lru_pages(memcg, BIT(i)) * PAGE_SIZE);
memory = memsw = PAGE_COUNTER_MAX;
for (mi = memcg; mi; mi = parent_mem_cgroup(mi)) {
memory = min(memory, mi->memory.limit);
memsw = min(memsw, mi->memsw.limit);
}
seq_printf(m, "hierarchical_memory_limit %llu\n",
(u64)memory * PAGE_SIZE);
if (do_swap_account)
seq_printf(m, "hierarchical_memsw_limit %llu\n",
(u64)memsw * PAGE_SIZE);
for (i = 0; i < MEM_CGROUP_STAT_NSTATS; i++) {
long long val = 0;
if (i == MEM_CGROUP_STAT_SWAP && !do_swap_account)
continue;
for_each_mem_cgroup_tree(mi, memcg)
val += mem_cgroup_read_stat(mi, i) * PAGE_SIZE;
seq_printf(m, "total_%s %lld\n", mem_cgroup_stat_names[i], val);
}
for (i = 0; i < MEM_CGROUP_EVENTS_NSTATS; i++) {
unsigned long long val = 0;
for_each_mem_cgroup_tree(mi, memcg)
val += mem_cgroup_read_events(mi, i);
seq_printf(m, "total_%s %llu\n",
mem_cgroup_events_names[i], val);
}
for (i = 0; i < NR_LRU_LISTS; i++) {
unsigned long long val = 0;
for_each_mem_cgroup_tree(mi, memcg)
val += mem_cgroup_nr_lru_pages(mi, BIT(i)) * PAGE_SIZE;
seq_printf(m, "total_%s %llu\n", mem_cgroup_lru_names[i], val);
}
#ifdef CONFIG_DEBUG_VM
{
int nid, zid;
struct mem_cgroup_per_zone *mz;
struct zone_reclaim_stat *rstat;
unsigned long recent_rotated[2] = {0, 0};
unsigned long recent_scanned[2] = {0, 0};
for_each_online_node(nid)
for (zid = 0; zid < MAX_NR_ZONES; zid++) {
mz = &memcg->nodeinfo[nid]->zoneinfo[zid];
rstat = &mz->lruvec.reclaim_stat;
recent_rotated[0] += rstat->recent_rotated[0];
recent_rotated[1] += rstat->recent_rotated[1];
recent_scanned[0] += rstat->recent_scanned[0];
recent_scanned[1] += rstat->recent_scanned[1];
}
seq_printf(m, "recent_rotated_anon %lu\n", recent_rotated[0]);
seq_printf(m, "recent_rotated_file %lu\n", recent_rotated[1]);
seq_printf(m, "recent_scanned_anon %lu\n", recent_scanned[0]);
seq_printf(m, "recent_scanned_file %lu\n", recent_scanned[1]);
}
#endif
return 0;
}
static u64 mem_cgroup_swappiness_read(struct cgroup_subsys_state *css,
struct cftype *cft)
{
struct mem_cgroup *memcg = mem_cgroup_from_css(css);
return mem_cgroup_swappiness(memcg);
}
static int mem_cgroup_swappiness_write(struct cgroup_subsys_state *css,
struct cftype *cft, u64 val)
{
struct mem_cgroup *memcg = mem_cgroup_from_css(css);
if (val > 100)
return -EINVAL;
if (css->parent)
memcg->swappiness = val;
else
vm_swappiness = val;
return 0;
}
static void __mem_cgroup_threshold(struct mem_cgroup *memcg, bool swap)
{
struct mem_cgroup_threshold_ary *t;
unsigned long usage;
int i;
rcu_read_lock();
if (!swap)
t = rcu_dereference(memcg->thresholds.primary);
else
t = rcu_dereference(memcg->memsw_thresholds.primary);
if (!t)
goto unlock;
usage = mem_cgroup_usage(memcg, swap);
i = t->current_threshold;
for (; i >= 0 && unlikely(t->entries[i].threshold > usage); i--)
eventfd_signal(t->entries[i].eventfd, 1);
i++;
for (; i < t->size && unlikely(t->entries[i].threshold <= usage); i++)
eventfd_signal(t->entries[i].eventfd, 1);
t->current_threshold = i - 1;
unlock:
rcu_read_unlock();
}
static void mem_cgroup_threshold(struct mem_cgroup *memcg)
{
while (memcg) {
__mem_cgroup_threshold(memcg, false);
if (do_swap_account)
__mem_cgroup_threshold(memcg, true);
memcg = parent_mem_cgroup(memcg);
}
}
static int compare_thresholds(const void *a, const void *b)
{
const struct mem_cgroup_threshold *_a = a;
const struct mem_cgroup_threshold *_b = b;
if (_a->threshold > _b->threshold)
return 1;
if (_a->threshold < _b->threshold)
return -1;
return 0;
}
static int mem_cgroup_oom_notify_cb(struct mem_cgroup *memcg)
{
struct mem_cgroup_eventfd_list *ev;
spin_lock(&memcg_oom_lock);
list_for_each_entry(ev, &memcg->oom_notify, list)
eventfd_signal(ev->eventfd, 1);
spin_unlock(&memcg_oom_lock);
return 0;
}
static void mem_cgroup_oom_notify(struct mem_cgroup *memcg)
{
struct mem_cgroup *iter;
for_each_mem_cgroup_tree(iter, memcg)
mem_cgroup_oom_notify_cb(iter);
}
static int __mem_cgroup_usage_register_event(struct mem_cgroup *memcg,
struct eventfd_ctx *eventfd, const char *args, enum res_type type)
{
struct mem_cgroup_thresholds *thresholds;
struct mem_cgroup_threshold_ary *new;
unsigned long threshold;
unsigned long usage;
int i, size, ret;
ret = page_counter_memparse(args, "-1", &threshold);
if (ret)
return ret;
mutex_lock(&memcg->thresholds_lock);
if (type == _MEM) {
thresholds = &memcg->thresholds;
usage = mem_cgroup_usage(memcg, false);
} else if (type == _MEMSWAP) {
thresholds = &memcg->memsw_thresholds;
usage = mem_cgroup_usage(memcg, true);
} else
BUG();
if (thresholds->primary)
__mem_cgroup_threshold(memcg, type == _MEMSWAP);
size = thresholds->primary ? thresholds->primary->size + 1 : 1;
new = kmalloc(sizeof(*new) + size * sizeof(struct mem_cgroup_threshold),
GFP_KERNEL);
if (!new) {
ret = -ENOMEM;
goto unlock;
}
new->size = size;
if (thresholds->primary) {
memcpy(new->entries, thresholds->primary->entries, (size - 1) *
sizeof(struct mem_cgroup_threshold));
}
new->entries[size - 1].eventfd = eventfd;
new->entries[size - 1].threshold = threshold;
sort(new->entries, size, sizeof(struct mem_cgroup_threshold),
compare_thresholds, NULL);
new->current_threshold = -1;
for (i = 0; i < size; i++) {
if (new->entries[i].threshold <= usage) {
++new->current_threshold;
} else
break;
}
kfree(thresholds->spare);
thresholds->spare = thresholds->primary;
rcu_assign_pointer(thresholds->primary, new);
synchronize_rcu();
unlock:
mutex_unlock(&memcg->thresholds_lock);
return ret;
}
static int mem_cgroup_usage_register_event(struct mem_cgroup *memcg,
struct eventfd_ctx *eventfd, const char *args)
{
return __mem_cgroup_usage_register_event(memcg, eventfd, args, _MEM);
}
static int memsw_cgroup_usage_register_event(struct mem_cgroup *memcg,
struct eventfd_ctx *eventfd, const char *args)
{
return __mem_cgroup_usage_register_event(memcg, eventfd, args, _MEMSWAP);
}
static void __mem_cgroup_usage_unregister_event(struct mem_cgroup *memcg,
struct eventfd_ctx *eventfd, enum res_type type)
{
struct mem_cgroup_thresholds *thresholds;
struct mem_cgroup_threshold_ary *new;
unsigned long usage;
int i, j, size;
mutex_lock(&memcg->thresholds_lock);
if (type == _MEM) {
thresholds = &memcg->thresholds;
usage = mem_cgroup_usage(memcg, false);
} else if (type == _MEMSWAP) {
thresholds = &memcg->memsw_thresholds;
usage = mem_cgroup_usage(memcg, true);
} else
BUG();
if (!thresholds->primary)
goto unlock;
__mem_cgroup_threshold(memcg, type == _MEMSWAP);
size = 0;
for (i = 0; i < thresholds->primary->size; i++) {
if (thresholds->primary->entries[i].eventfd != eventfd)
size++;
}
new = thresholds->spare;
if (!size) {
kfree(new);
new = NULL;
goto swap_buffers;
}
new->size = size;
new->current_threshold = -1;
for (i = 0, j = 0; i < thresholds->primary->size; i++) {
if (thresholds->primary->entries[i].eventfd == eventfd)
continue;
new->entries[j] = thresholds->primary->entries[i];
if (new->entries[j].threshold <= usage) {
++new->current_threshold;
}
j++;
}
swap_buffers:
thresholds->spare = thresholds->primary;
if (!new) {
kfree(thresholds->spare);
thresholds->spare = NULL;
}
rcu_assign_pointer(thresholds->primary, new);
synchronize_rcu();
unlock:
mutex_unlock(&memcg->thresholds_lock);
}
static void mem_cgroup_usage_unregister_event(struct mem_cgroup *memcg,
struct eventfd_ctx *eventfd)
{
return __mem_cgroup_usage_unregister_event(memcg, eventfd, _MEM);
}
static void memsw_cgroup_usage_unregister_event(struct mem_cgroup *memcg,
struct eventfd_ctx *eventfd)
{
return __mem_cgroup_usage_unregister_event(memcg, eventfd, _MEMSWAP);
}
static int mem_cgroup_oom_register_event(struct mem_cgroup *memcg,
struct eventfd_ctx *eventfd, const char *args)
{
struct mem_cgroup_eventfd_list *event;
event = kmalloc(sizeof(*event), GFP_KERNEL);
if (!event)
return -ENOMEM;
spin_lock(&memcg_oom_lock);
event->eventfd = eventfd;
list_add(&event->list, &memcg->oom_notify);
if (atomic_read(&memcg->under_oom))
eventfd_signal(eventfd, 1);
spin_unlock(&memcg_oom_lock);
return 0;
}
static void mem_cgroup_oom_unregister_event(struct mem_cgroup *memcg,
struct eventfd_ctx *eventfd)
{
struct mem_cgroup_eventfd_list *ev, *tmp;
spin_lock(&memcg_oom_lock);
list_for_each_entry_safe(ev, tmp, &memcg->oom_notify, list) {
if (ev->eventfd == eventfd) {
list_del(&ev->list);
kfree(ev);
}
}
spin_unlock(&memcg_oom_lock);
}
static int mem_cgroup_oom_control_read(struct seq_file *sf, void *v)
{
struct mem_cgroup *memcg = mem_cgroup_from_css(seq_css(sf));
seq_printf(sf, "oom_kill_disable %d\n", memcg->oom_kill_disable);
seq_printf(sf, "under_oom %d\n", (bool)atomic_read(&memcg->under_oom));
return 0;
}
static int mem_cgroup_oom_control_write(struct cgroup_subsys_state *css,
struct cftype *cft, u64 val)
{
struct mem_cgroup *memcg = mem_cgroup_from_css(css);
if (!css->parent || !((val == 0) || (val == 1)))
return -EINVAL;
memcg->oom_kill_disable = val;
if (!val)
memcg_oom_recover(memcg);
return 0;
}
static int memcg_init_kmem(struct mem_cgroup *memcg, struct cgroup_subsys *ss)
{
int ret;
ret = memcg_propagate_kmem(memcg);
if (ret)
return ret;
return mem_cgroup_sockets_init(memcg, ss);
}
static void memcg_deactivate_kmem(struct mem_cgroup *memcg)
{
struct cgroup_subsys_state *css;
struct mem_cgroup *parent, *child;
int kmemcg_id;
if (!memcg->kmem_acct_active)
return;
memcg->kmem_acct_active = false;
memcg_deactivate_kmem_caches(memcg);
kmemcg_id = memcg->kmemcg_id;
BUG_ON(kmemcg_id < 0);
parent = parent_mem_cgroup(memcg);
if (!parent)
parent = root_mem_cgroup;
css_for_each_descendant_pre(css, &memcg->css) {
child = mem_cgroup_from_css(css);
BUG_ON(child->kmemcg_id != kmemcg_id);
child->kmemcg_id = parent->kmemcg_id;
if (!memcg->use_hierarchy)
break;
}
memcg_drain_all_list_lrus(kmemcg_id, parent->kmemcg_id);
memcg_free_cache_id(kmemcg_id);
}
static void memcg_destroy_kmem(struct mem_cgroup *memcg)
{
if (memcg->kmem_acct_activated) {
memcg_destroy_kmem_caches(memcg);
static_key_slow_dec(&memcg_kmem_enabled_key);
WARN_ON(page_counter_read(&memcg->kmem));
}
mem_cgroup_sockets_destroy(memcg);
}
static int memcg_init_kmem(struct mem_cgroup *memcg, struct cgroup_subsys *ss)
{
return 0;
}
static void memcg_deactivate_kmem(struct mem_cgroup *memcg)
{
}
static void memcg_destroy_kmem(struct mem_cgroup *memcg)
{
}
static void memcg_event_remove(struct work_struct *work)
{
struct mem_cgroup_event *event =
container_of(work, struct mem_cgroup_event, remove);
struct mem_cgroup *memcg = event->memcg;
remove_wait_queue(event->wqh, &event->wait);
event->unregister_event(memcg, event->eventfd);
eventfd_signal(event->eventfd, 1);
eventfd_ctx_put(event->eventfd);
kfree(event);
css_put(&memcg->css);
}
static int memcg_event_wake(wait_queue_t *wait, unsigned mode,
int sync, void *key)
{
struct mem_cgroup_event *event =
container_of(wait, struct mem_cgroup_event, wait);
struct mem_cgroup *memcg = event->memcg;
unsigned long flags = (unsigned long)key;
if (flags & POLLHUP) {
spin_lock(&memcg->event_list_lock);
if (!list_empty(&event->list)) {
list_del_init(&event->list);
schedule_work(&event->remove);
}
spin_unlock(&memcg->event_list_lock);
}
return 0;
}
static void memcg_event_ptable_queue_proc(struct file *file,
wait_queue_head_t *wqh, poll_table *pt)
{
struct mem_cgroup_event *event =
container_of(pt, struct mem_cgroup_event, pt);
event->wqh = wqh;
add_wait_queue(wqh, &event->wait);
}
static ssize_t memcg_write_event_control(struct kernfs_open_file *of,
char *buf, size_t nbytes, loff_t off)
{
struct cgroup_subsys_state *css = of_css(of);
struct mem_cgroup *memcg = mem_cgroup_from_css(css);
struct mem_cgroup_event *event;
struct cgroup_subsys_state *cfile_css;
unsigned int efd, cfd;
struct fd efile;
struct fd cfile;
const char *name;
char *endp;
int ret;
buf = strstrip(buf);
efd = simple_strtoul(buf, &endp, 10);
if (*endp != ' ')
return -EINVAL;
buf = endp + 1;
cfd = simple_strtoul(buf, &endp, 10);
if ((*endp != ' ') && (*endp != '\0'))
return -EINVAL;
buf = endp + 1;
event = kzalloc(sizeof(*event), GFP_KERNEL);
if (!event)
return -ENOMEM;
event->memcg = memcg;
INIT_LIST_HEAD(&event->list);
init_poll_funcptr(&event->pt, memcg_event_ptable_queue_proc);
init_waitqueue_func_entry(&event->wait, memcg_event_wake);
INIT_WORK(&event->remove, memcg_event_remove);
efile = fdget(efd);
if (!efile.file) {
ret = -EBADF;
goto out_kfree;
}
event->eventfd = eventfd_ctx_fileget(efile.file);
if (IS_ERR(event->eventfd)) {
ret = PTR_ERR(event->eventfd);
goto out_put_efile;
}
cfile = fdget(cfd);
if (!cfile.file) {
ret = -EBADF;
goto out_put_eventfd;
}
ret = inode_permission(file_inode(cfile.file), MAY_READ);
if (ret < 0)
goto out_put_cfile;
name = cfile.file->f_path.dentry->d_name.name;
if (!strcmp(name, "memory.usage_in_bytes")) {
event->register_event = mem_cgroup_usage_register_event;
event->unregister_event = mem_cgroup_usage_unregister_event;
} else if (!strcmp(name, "memory.oom_control")) {
event->register_event = mem_cgroup_oom_register_event;
event->unregister_event = mem_cgroup_oom_unregister_event;
} else if (!strcmp(name, "memory.pressure_level")) {
event->register_event = vmpressure_register_event;
event->unregister_event = vmpressure_unregister_event;
} else if (!strcmp(name, "memory.memsw.usage_in_bytes")) {
event->register_event = memsw_cgroup_usage_register_event;
event->unregister_event = memsw_cgroup_usage_unregister_event;
} else {
ret = -EINVAL;
goto out_put_cfile;
}
cfile_css = css_tryget_online_from_dir(cfile.file->f_path.dentry->d_parent,
&memory_cgrp_subsys);
ret = -EINVAL;
if (IS_ERR(cfile_css))
goto out_put_cfile;
if (cfile_css != css) {
css_put(cfile_css);
goto out_put_cfile;
}
ret = event->register_event(memcg, event->eventfd, buf);
if (ret)
goto out_put_css;
efile.file->f_op->poll(efile.file, &event->pt);
spin_lock(&memcg->event_list_lock);
list_add(&event->list, &memcg->event_list);
spin_unlock(&memcg->event_list_lock);
fdput(cfile);
fdput(efile);
return nbytes;
out_put_css:
css_put(css);
out_put_cfile:
fdput(cfile);
out_put_eventfd:
eventfd_ctx_put(event->eventfd);
out_put_efile:
fdput(efile);
out_kfree:
kfree(event);
return ret;
}
static int alloc_mem_cgroup_per_zone_info(struct mem_cgroup *memcg, int node)
{
struct mem_cgroup_per_node *pn;
struct mem_cgroup_per_zone *mz;
int zone, tmp = node;
if (!node_state(node, N_NORMAL_MEMORY))
tmp = -1;
pn = kzalloc_node(sizeof(*pn), GFP_KERNEL, tmp);
if (!pn)
return 1;
for (zone = 0; zone < MAX_NR_ZONES; zone++) {
mz = &pn->zoneinfo[zone];
lruvec_init(&mz->lruvec);
mz->usage_in_excess = 0;
mz->on_tree = false;
mz->memcg = memcg;
}
memcg->nodeinfo[node] = pn;
return 0;
}
static void free_mem_cgroup_per_zone_info(struct mem_cgroup *memcg, int node)
{
kfree(memcg->nodeinfo[node]);
}
static struct mem_cgroup *mem_cgroup_alloc(void)
{
struct mem_cgroup *memcg;
size_t size;
size = sizeof(struct mem_cgroup);
size += nr_node_ids * sizeof(struct mem_cgroup_per_node *);
memcg = kzalloc(size, GFP_KERNEL);
if (!memcg)
return NULL;
memcg->stat = alloc_percpu(struct mem_cgroup_stat_cpu);
if (!memcg->stat)
goto out_free;
spin_lock_init(&memcg->pcp_counter_lock);
return memcg;
out_free:
kfree(memcg);
return NULL;
}
static void __mem_cgroup_free(struct mem_cgroup *memcg)
{
int node;
mem_cgroup_remove_from_trees(memcg);
for_each_node(node)
free_mem_cgroup_per_zone_info(memcg, node);
free_percpu(memcg->stat);
kfree(memcg);
}
struct mem_cgroup *parent_mem_cgroup(struct mem_cgroup *memcg)
{
if (!memcg->memory.parent)
return NULL;
return mem_cgroup_from_counter(memcg->memory.parent, memory);
}
static struct cgroup_subsys_state * __ref
mem_cgroup_css_alloc(struct cgroup_subsys_state *parent_css)
{
struct mem_cgroup *memcg;
long error = -ENOMEM;
int node;
memcg = mem_cgroup_alloc();
if (!memcg)
return ERR_PTR(error);
for_each_node(node)
if (alloc_mem_cgroup_per_zone_info(memcg, node))
goto free_out;
if (parent_css == NULL) {
root_mem_cgroup = memcg;
page_counter_init(&memcg->memory, NULL);
memcg->high = PAGE_COUNTER_MAX;
memcg->soft_limit = PAGE_COUNTER_MAX;
page_counter_init(&memcg->memsw, NULL);
page_counter_init(&memcg->kmem, NULL);
}
memcg->last_scanned_node = MAX_NUMNODES;
INIT_LIST_HEAD(&memcg->oom_notify);
memcg->move_charge_at_immigrate = 0;
mutex_init(&memcg->thresholds_lock);
spin_lock_init(&memcg->move_lock);
vmpressure_init(&memcg->vmpressure);
INIT_LIST_HEAD(&memcg->event_list);
spin_lock_init(&memcg->event_list_lock);
#ifdef CONFIG_MEMCG_KMEM
memcg->kmemcg_id = -1;
#endif
return &memcg->css;
free_out:
__mem_cgroup_free(memcg);
return ERR_PTR(error);
}
static int
mem_cgroup_css_online(struct cgroup_subsys_state *css)
{
struct mem_cgroup *memcg = mem_cgroup_from_css(css);
struct mem_cgroup *parent = mem_cgroup_from_css(css->parent);
int ret;
if (css->id > MEM_CGROUP_ID_MAX)
return -ENOSPC;
if (!parent)
return 0;
mutex_lock(&memcg_create_mutex);
memcg->use_hierarchy = parent->use_hierarchy;
memcg->oom_kill_disable = parent->oom_kill_disable;
memcg->swappiness = mem_cgroup_swappiness(parent);
if (parent->use_hierarchy) {
page_counter_init(&memcg->memory, &parent->memory);
memcg->high = PAGE_COUNTER_MAX;
memcg->soft_limit = PAGE_COUNTER_MAX;
page_counter_init(&memcg->memsw, &parent->memsw);
page_counter_init(&memcg->kmem, &parent->kmem);
} else {
page_counter_init(&memcg->memory, NULL);
memcg->high = PAGE_COUNTER_MAX;
memcg->soft_limit = PAGE_COUNTER_MAX;
page_counter_init(&memcg->memsw, NULL);
page_counter_init(&memcg->kmem, NULL);
if (parent != root_mem_cgroup)
memory_cgrp_subsys.broken_hierarchy = true;
}
mutex_unlock(&memcg_create_mutex);
ret = memcg_init_kmem(memcg, &memory_cgrp_subsys);
if (ret)
return ret;
smp_store_release(&memcg->initialized, 1);
return 0;
}
static void mem_cgroup_css_offline(struct cgroup_subsys_state *css)
{
struct mem_cgroup *memcg = mem_cgroup_from_css(css);
struct mem_cgroup_event *event, *tmp;
spin_lock(&memcg->event_list_lock);
list_for_each_entry_safe(event, tmp, &memcg->event_list, list) {
list_del_init(&event->list);
schedule_work(&event->remove);
}
spin_unlock(&memcg->event_list_lock);
vmpressure_cleanup(&memcg->vmpressure);
memcg_deactivate_kmem(memcg);
}
static void mem_cgroup_css_free(struct cgroup_subsys_state *css)
{
struct mem_cgroup *memcg = mem_cgroup_from_css(css);
memcg_destroy_kmem(memcg);
__mem_cgroup_free(memcg);
}
static void mem_cgroup_css_reset(struct cgroup_subsys_state *css)
{
struct mem_cgroup *memcg = mem_cgroup_from_css(css);
mem_cgroup_resize_limit(memcg, PAGE_COUNTER_MAX);
mem_cgroup_resize_memsw_limit(memcg, PAGE_COUNTER_MAX);
memcg_update_kmem_limit(memcg, PAGE_COUNTER_MAX);
memcg->low = 0;
memcg->high = PAGE_COUNTER_MAX;
memcg->soft_limit = PAGE_COUNTER_MAX;
}
static int mem_cgroup_do_precharge(unsigned long count)
{
int ret;
ret = try_charge(mc.to, GFP_KERNEL & ~__GFP_WAIT, count);
if (!ret) {
mc.precharge += count;
return ret;
}
if (ret == -EINTR) {
cancel_charge(root_mem_cgroup, count);
return ret;
}
while (count--) {
ret = try_charge(mc.to, GFP_KERNEL & ~__GFP_NORETRY, 1);
if (ret == -EINTR)
cancel_charge(root_mem_cgroup, 1);
if (ret)
return ret;
mc.precharge++;
cond_resched();
}
return 0;
}
static struct page *mc_handle_present_pte(struct vm_area_struct *vma,
unsigned long addr, pte_t ptent)
{
struct page *page = vm_normal_page(vma, addr, ptent);
if (!page || !page_mapped(page))
return NULL;
if (PageAnon(page)) {
if (!(mc.flags & MOVE_ANON))
return NULL;
} else {
if (!(mc.flags & MOVE_FILE))
return NULL;
}
if (!get_page_unless_zero(page))
return NULL;
return page;
}
static struct page *mc_handle_swap_pte(struct vm_area_struct *vma,
unsigned long addr, pte_t ptent, swp_entry_t *entry)
{
struct page *page = NULL;
swp_entry_t ent = pte_to_swp_entry(ptent);
if (!(mc.flags & MOVE_ANON) || non_swap_entry(ent))
return NULL;
page = find_get_page(swap_address_space(ent), ent.val);
if (do_swap_account)
entry->val = ent.val;
return page;
}
static struct page *mc_handle_swap_pte(struct vm_area_struct *vma,
unsigned long addr, pte_t ptent, swp_entry_t *entry)
{
return NULL;
}
static struct page *mc_handle_file_pte(struct vm_area_struct *vma,
unsigned long addr, pte_t ptent, swp_entry_t *entry)
{
struct page *page = NULL;
struct address_space *mapping;
pgoff_t pgoff;
if (!vma->vm_file)
return NULL;
if (!(mc.flags & MOVE_FILE))
return NULL;
mapping = vma->vm_file->f_mapping;
pgoff = linear_page_index(vma, addr);
#ifdef CONFIG_SWAP
if (shmem_mapping(mapping)) {
page = find_get_entry(mapping, pgoff);
if (radix_tree_exceptional_entry(page)) {
swp_entry_t swp = radix_to_swp_entry(page);
if (do_swap_account)
*entry = swp;
page = find_get_page(swap_address_space(swp), swp.val);
}
} else
page = find_get_page(mapping, pgoff);
#else
page = find_get_page(mapping, pgoff);
#endif
return page;
}
static int mem_cgroup_move_account(struct page *page,
unsigned int nr_pages,
struct mem_cgroup *from,
struct mem_cgroup *to)
{
unsigned long flags;
int ret;
VM_BUG_ON(from == to);
VM_BUG_ON_PAGE(PageLRU(page), page);
ret = -EBUSY;
if (nr_pages > 1 && !PageTransHuge(page))
goto out;
if (!trylock_page(page))
goto out;
ret = -EINVAL;
if (page->mem_cgroup != from)
goto out_unlock;
spin_lock_irqsave(&from->move_lock, flags);
if (!PageAnon(page) && page_mapped(page)) {
__this_cpu_sub(from->stat->count[MEM_CGROUP_STAT_FILE_MAPPED],
nr_pages);
__this_cpu_add(to->stat->count[MEM_CGROUP_STAT_FILE_MAPPED],
nr_pages);
}
if (PageWriteback(page)) {
__this_cpu_sub(from->stat->count[MEM_CGROUP_STAT_WRITEBACK],
nr_pages);
__this_cpu_add(to->stat->count[MEM_CGROUP_STAT_WRITEBACK],
nr_pages);
}
page->mem_cgroup = to;
spin_unlock_irqrestore(&from->move_lock, flags);
ret = 0;
local_irq_disable();
mem_cgroup_charge_statistics(to, page, nr_pages);
memcg_check_events(to, page);
mem_cgroup_charge_statistics(from, page, -nr_pages);
memcg_check_events(from, page);
local_irq_enable();
out_unlock:
unlock_page(page);
out:
return ret;
}
static enum mc_target_type get_mctgt_type(struct vm_area_struct *vma,
unsigned long addr, pte_t ptent, union mc_target *target)
{
struct page *page = NULL;
enum mc_target_type ret = MC_TARGET_NONE;
swp_entry_t ent = { .val = 0 };
if (pte_present(ptent))
page = mc_handle_present_pte(vma, addr, ptent);
else if (is_swap_pte(ptent))
page = mc_handle_swap_pte(vma, addr, ptent, &ent);
else if (pte_none(ptent))
page = mc_handle_file_pte(vma, addr, ptent, &ent);
if (!page && !ent.val)
return ret;
if (page) {
if (page->mem_cgroup == mc.from) {
ret = MC_TARGET_PAGE;
if (target)
target->page = page;
}
if (!ret || !target)
put_page(page);
}
if (ent.val && !ret &&
mem_cgroup_id(mc.from) == lookup_swap_cgroup_id(ent)) {
ret = MC_TARGET_SWAP;
if (target)
target->ent = ent;
}
return ret;
}
static enum mc_target_type get_mctgt_type_thp(struct vm_area_struct *vma,
unsigned long addr, pmd_t pmd, union mc_target *target)
{
struct page *page = NULL;
enum mc_target_type ret = MC_TARGET_NONE;
page = pmd_page(pmd);
VM_BUG_ON_PAGE(!page || !PageHead(page), page);
if (!(mc.flags & MOVE_ANON))
return ret;
if (page->mem_cgroup == mc.from) {
ret = MC_TARGET_PAGE;
if (target) {
get_page(page);
target->page = page;
}
}
return ret;
}
static inline enum mc_target_type get_mctgt_type_thp(struct vm_area_struct *vma,
unsigned long addr, pmd_t pmd, union mc_target *target)
{
return MC_TARGET_NONE;
}
static int mem_cgroup_count_precharge_pte_range(pmd_t *pmd,
unsigned long addr, unsigned long end,
struct mm_walk *walk)
{
struct vm_area_struct *vma = walk->vma;
pte_t *pte;
spinlock_t *ptl;
if (pmd_trans_huge_lock(pmd, vma, &ptl) == 1) {
if (get_mctgt_type_thp(vma, addr, *pmd, NULL) == MC_TARGET_PAGE)
mc.precharge += HPAGE_PMD_NR;
spin_unlock(ptl);
return 0;
}
if (pmd_trans_unstable(pmd))
return 0;
pte = pte_offset_map_lock(vma->vm_mm, pmd, addr, &ptl);
for (; addr != end; pte++, addr += PAGE_SIZE)
if (get_mctgt_type(vma, addr, *pte, NULL))
mc.precharge++;
pte_unmap_unlock(pte - 1, ptl);
cond_resched();
return 0;
}
static unsigned long mem_cgroup_count_precharge(struct mm_struct *mm)
{
unsigned long precharge;
struct mm_walk mem_cgroup_count_precharge_walk = {
.pmd_entry = mem_cgroup_count_precharge_pte_range,
.mm = mm,
};
down_read(&mm->mmap_sem);
walk_page_range(0, ~0UL, &mem_cgroup_count_precharge_walk);
up_read(&mm->mmap_sem);
precharge = mc.precharge;
mc.precharge = 0;
return precharge;
}
static int mem_cgroup_precharge_mc(struct mm_struct *mm)
{
unsigned long precharge = mem_cgroup_count_precharge(mm);
VM_BUG_ON(mc.moving_task);
mc.moving_task = current;
return mem_cgroup_do_precharge(precharge);
}
static void __mem_cgroup_clear_mc(void)
{
struct mem_cgroup *from = mc.from;
struct mem_cgroup *to = mc.to;
if (mc.precharge) {
cancel_charge(mc.to, mc.precharge);
mc.precharge = 0;
}
if (mc.moved_charge) {
cancel_charge(mc.from, mc.moved_charge);
mc.moved_charge = 0;
}
if (mc.moved_swap) {
if (!mem_cgroup_is_root(mc.from))
page_counter_uncharge(&mc.from->memsw, mc.moved_swap);
if (!mem_cgroup_is_root(mc.to))
page_counter_uncharge(&mc.to->memory, mc.moved_swap);
css_put_many(&mc.from->css, mc.moved_swap);
mc.moved_swap = 0;
}
memcg_oom_recover(from);
memcg_oom_recover(to);
wake_up_all(&mc.waitq);
}
static void mem_cgroup_clear_mc(void)
{
mc.moving_task = NULL;
__mem_cgroup_clear_mc();
spin_lock(&mc.lock);
mc.from = NULL;
mc.to = NULL;
spin_unlock(&mc.lock);
}
static int mem_cgroup_can_attach(struct cgroup_subsys_state *css,
struct cgroup_taskset *tset)
{
struct task_struct *p = cgroup_taskset_first(tset);
int ret = 0;
struct mem_cgroup *memcg = mem_cgroup_from_css(css);
unsigned long move_flags;
move_flags = READ_ONCE(memcg->move_charge_at_immigrate);
if (move_flags) {
struct mm_struct *mm;
struct mem_cgroup *from = mem_cgroup_from_task(p);
VM_BUG_ON(from == memcg);
mm = get_task_mm(p);
if (!mm)
return 0;
if (mm->owner == p) {
VM_BUG_ON(mc.from);
VM_BUG_ON(mc.to);
VM_BUG_ON(mc.precharge);
VM_BUG_ON(mc.moved_charge);
VM_BUG_ON(mc.moved_swap);
spin_lock(&mc.lock);
mc.from = from;
mc.to = memcg;
mc.flags = move_flags;
spin_unlock(&mc.lock);
ret = mem_cgroup_precharge_mc(mm);
if (ret)
mem_cgroup_clear_mc();
}
mmput(mm);
}
return ret;
}
static void mem_cgroup_cancel_attach(struct cgroup_subsys_state *css,
struct cgroup_taskset *tset)
{
if (mc.to)
mem_cgroup_clear_mc();
}
static int mem_cgroup_move_charge_pte_range(pmd_t *pmd,
unsigned long addr, unsigned long end,
struct mm_walk *walk)
{
int ret = 0;
struct vm_area_struct *vma = walk->vma;
pte_t *pte;
spinlock_t *ptl;
enum mc_target_type target_type;
union mc_target target;
struct page *page;
if (pmd_trans_huge_lock(pmd, vma, &ptl) == 1) {
if (mc.precharge < HPAGE_PMD_NR) {
spin_unlock(ptl);
return 0;
}
target_type = get_mctgt_type_thp(vma, addr, *pmd, &target);
if (target_type == MC_TARGET_PAGE) {
page = target.page;
if (!isolate_lru_page(page)) {
if (!mem_cgroup_move_account(page, HPAGE_PMD_NR,
mc.from, mc.to)) {
mc.precharge -= HPAGE_PMD_NR;
mc.moved_charge += HPAGE_PMD_NR;
}
putback_lru_page(page);
}
put_page(page);
}
spin_unlock(ptl);
return 0;
}
if (pmd_trans_unstable(pmd))
return 0;
retry:
pte = pte_offset_map_lock(vma->vm_mm, pmd, addr, &ptl);
for (; addr != end; addr += PAGE_SIZE) {
pte_t ptent = *(pte++);
swp_entry_t ent;
if (!mc.precharge)
break;
switch (get_mctgt_type(vma, addr, ptent, &target)) {
case MC_TARGET_PAGE:
page = target.page;
if (isolate_lru_page(page))
goto put;
if (!mem_cgroup_move_account(page, 1, mc.from, mc.to)) {
mc.precharge--;
mc.moved_charge++;
}
putback_lru_page(page);
put:
put_page(page);
break;
case MC_TARGET_SWAP:
ent = target.ent;
if (!mem_cgroup_move_swap_account(ent, mc.from, mc.to)) {
mc.precharge--;
mc.moved_swap++;
}
break;
default:
break;
}
}
pte_unmap_unlock(pte - 1, ptl);
cond_resched();
if (addr != end) {
ret = mem_cgroup_do_precharge(1);
if (!ret)
goto retry;
}
return ret;
}
static void mem_cgroup_move_charge(struct mm_struct *mm)
{
struct mm_walk mem_cgroup_move_charge_walk = {
.pmd_entry = mem_cgroup_move_charge_pte_range,
.mm = mm,
};
lru_add_drain_all();
atomic_inc(&mc.from->moving_account);
synchronize_rcu();
retry:
if (unlikely(!down_read_trylock(&mm->mmap_sem))) {
__mem_cgroup_clear_mc();
cond_resched();
goto retry;
}
walk_page_range(0, ~0UL, &mem_cgroup_move_charge_walk);
up_read(&mm->mmap_sem);
atomic_dec(&mc.from->moving_account);
}
static void mem_cgroup_move_task(struct cgroup_subsys_state *css,
struct cgroup_taskset *tset)
{
struct task_struct *p = cgroup_taskset_first(tset);
struct mm_struct *mm = get_task_mm(p);
if (mm) {
if (mc.to)
mem_cgroup_move_charge(mm);
mmput(mm);
}
if (mc.to)
mem_cgroup_clear_mc();
}
static int mem_cgroup_can_attach(struct cgroup_subsys_state *css,
struct cgroup_taskset *tset)
{
return 0;
}
static void mem_cgroup_cancel_attach(struct cgroup_subsys_state *css,
struct cgroup_taskset *tset)
{
}
static void mem_cgroup_move_task(struct cgroup_subsys_state *css,
struct cgroup_taskset *tset)
{
}
static void mem_cgroup_bind(struct cgroup_subsys_state *root_css)
{
if (cgroup_on_dfl(root_css->cgroup))
root_mem_cgroup->use_hierarchy = true;
else
root_mem_cgroup->use_hierarchy = false;
}
static u64 memory_current_read(struct cgroup_subsys_state *css,
struct cftype *cft)
{
return mem_cgroup_usage(mem_cgroup_from_css(css), false);
}
static int memory_low_show(struct seq_file *m, void *v)
{
struct mem_cgroup *memcg = mem_cgroup_from_css(seq_css(m));
unsigned long low = READ_ONCE(memcg->low);
if (low == PAGE_COUNTER_MAX)
seq_puts(m, "max\n");
else
seq_printf(m, "%llu\n", (u64)low * PAGE_SIZE);
return 0;
}
static ssize_t memory_low_write(struct kernfs_open_file *of,
char *buf, size_t nbytes, loff_t off)
{
struct mem_cgroup *memcg = mem_cgroup_from_css(of_css(of));
unsigned long low;
int err;
buf = strstrip(buf);
err = page_counter_memparse(buf, "max", &low);
if (err)
return err;
memcg->low = low;
return nbytes;
}
static int memory_high_show(struct seq_file *m, void *v)
{
struct mem_cgroup *memcg = mem_cgroup_from_css(seq_css(m));
unsigned long high = READ_ONCE(memcg->high);
if (high == PAGE_COUNTER_MAX)
seq_puts(m, "max\n");
else
seq_printf(m, "%llu\n", (u64)high * PAGE_SIZE);
return 0;
}
static ssize_t memory_high_write(struct kernfs_open_file *of,
char *buf, size_t nbytes, loff_t off)
{
struct mem_cgroup *memcg = mem_cgroup_from_css(of_css(of));
unsigned long high;
int err;
buf = strstrip(buf);
err = page_counter_memparse(buf, "max", &high);
if (err)
return err;
memcg->high = high;
return nbytes;
}
static int memory_max_show(struct seq_file *m, void *v)
{
struct mem_cgroup *memcg = mem_cgroup_from_css(seq_css(m));
unsigned long max = READ_ONCE(memcg->memory.limit);
if (max == PAGE_COUNTER_MAX)
seq_puts(m, "max\n");
else
seq_printf(m, "%llu\n", (u64)max * PAGE_SIZE);
return 0;
}
static ssize_t memory_max_write(struct kernfs_open_file *of,
char *buf, size_t nbytes, loff_t off)
{
struct mem_cgroup *memcg = mem_cgroup_from_css(of_css(of));
unsigned long max;
int err;
buf = strstrip(buf);
err = page_counter_memparse(buf, "max", &max);
if (err)
return err;
err = mem_cgroup_resize_limit(memcg, max);
if (err)
return err;
return nbytes;
}
static int memory_events_show(struct seq_file *m, void *v)
{
struct mem_cgroup *memcg = mem_cgroup_from_css(seq_css(m));
seq_printf(m, "low %lu\n", mem_cgroup_read_events(memcg, MEMCG_LOW));
seq_printf(m, "high %lu\n", mem_cgroup_read_events(memcg, MEMCG_HIGH));
seq_printf(m, "max %lu\n", mem_cgroup_read_events(memcg, MEMCG_MAX));
seq_printf(m, "oom %lu\n", mem_cgroup_read_events(memcg, MEMCG_OOM));
return 0;
}
void mem_cgroup_events(struct mem_cgroup *memcg,
enum mem_cgroup_events_index idx,
unsigned int nr)
{
this_cpu_add(memcg->stat->events[idx], nr);
}
bool mem_cgroup_low(struct mem_cgroup *root, struct mem_cgroup *memcg)
{
if (mem_cgroup_disabled())
return false;
if (memcg == root_mem_cgroup)
return false;
if (page_counter_read(&memcg->memory) >= memcg->low)
return false;
while (memcg != root) {
memcg = parent_mem_cgroup(memcg);
if (memcg == root_mem_cgroup)
break;
if (page_counter_read(&memcg->memory) >= memcg->low)
return false;
}
return true;
}
int mem_cgroup_try_charge(struct page *page, struct mm_struct *mm,
gfp_t gfp_mask, struct mem_cgroup **memcgp)
{
struct mem_cgroup *memcg = NULL;
unsigned int nr_pages = 1;
int ret = 0;
if (mem_cgroup_disabled())
goto out;
if (PageSwapCache(page)) {
if (page->mem_cgroup)
goto out;
}
if (PageTransHuge(page)) {
nr_pages <<= compound_order(page);
VM_BUG_ON_PAGE(!PageTransHuge(page), page);
}
if (do_swap_account && PageSwapCache(page))
memcg = try_get_mem_cgroup_from_page(page);
if (!memcg)
memcg = get_mem_cgroup_from_mm(mm);
ret = try_charge(memcg, gfp_mask, nr_pages);
css_put(&memcg->css);
if (ret == -EINTR) {
memcg = root_mem_cgroup;
ret = 0;
}
out:
*memcgp = memcg;
return ret;
}
void mem_cgroup_commit_charge(struct page *page, struct mem_cgroup *memcg,
bool lrucare)
{
unsigned int nr_pages = 1;
VM_BUG_ON_PAGE(!page->mapping, page);
VM_BUG_ON_PAGE(PageLRU(page) && !lrucare, page);
if (mem_cgroup_disabled())
return;
if (!memcg)
return;
commit_charge(page, memcg, lrucare);
if (PageTransHuge(page)) {
nr_pages <<= compound_order(page);
VM_BUG_ON_PAGE(!PageTransHuge(page), page);
}
local_irq_disable();
mem_cgroup_charge_statistics(memcg, page, nr_pages);
memcg_check_events(memcg, page);
local_irq_enable();
if (do_swap_account && PageSwapCache(page)) {
swp_entry_t entry = { .val = page_private(page) };
mem_cgroup_uncharge_swap(entry);
}
}
void mem_cgroup_cancel_charge(struct page *page, struct mem_cgroup *memcg)
{
unsigned int nr_pages = 1;
if (mem_cgroup_disabled())
return;
if (!memcg)
return;
if (PageTransHuge(page)) {
nr_pages <<= compound_order(page);
VM_BUG_ON_PAGE(!PageTransHuge(page), page);
}
cancel_charge(memcg, nr_pages);
}
static void uncharge_batch(struct mem_cgroup *memcg, unsigned long pgpgout,
unsigned long nr_anon, unsigned long nr_file,
unsigned long nr_huge, struct page *dummy_page)
{
unsigned long nr_pages = nr_anon + nr_file;
unsigned long flags;
if (!mem_cgroup_is_root(memcg)) {
page_counter_uncharge(&memcg->memory, nr_pages);
if (do_swap_account)
page_counter_uncharge(&memcg->memsw, nr_pages);
memcg_oom_recover(memcg);
}
local_irq_save(flags);
__this_cpu_sub(memcg->stat->count[MEM_CGROUP_STAT_RSS], nr_anon);
__this_cpu_sub(memcg->stat->count[MEM_CGROUP_STAT_CACHE], nr_file);
__this_cpu_sub(memcg->stat->count[MEM_CGROUP_STAT_RSS_HUGE], nr_huge);
__this_cpu_add(memcg->stat->events[MEM_CGROUP_EVENTS_PGPGOUT], pgpgout);
__this_cpu_add(memcg->stat->nr_page_events, nr_pages);
memcg_check_events(memcg, dummy_page);
local_irq_restore(flags);
if (!mem_cgroup_is_root(memcg))
css_put_many(&memcg->css, nr_pages);
}
static void uncharge_list(struct list_head *page_list)
{
struct mem_cgroup *memcg = NULL;
unsigned long nr_anon = 0;
unsigned long nr_file = 0;
unsigned long nr_huge = 0;
unsigned long pgpgout = 0;
struct list_head *next;
struct page *page;
next = page_list->next;
do {
unsigned int nr_pages = 1;
page = list_entry(next, struct page, lru);
next = page->lru.next;
VM_BUG_ON_PAGE(PageLRU(page), page);
VM_BUG_ON_PAGE(page_count(page), page);
if (!page->mem_cgroup)
continue;
if (memcg != page->mem_cgroup) {
if (memcg) {
uncharge_batch(memcg, pgpgout, nr_anon, nr_file,
nr_huge, page);
pgpgout = nr_anon = nr_file = nr_huge = 0;
}
memcg = page->mem_cgroup;
}
if (PageTransHuge(page)) {
nr_pages <<= compound_order(page);
VM_BUG_ON_PAGE(!PageTransHuge(page), page);
nr_huge += nr_pages;
}
if (PageAnon(page))
nr_anon += nr_pages;
else
nr_file += nr_pages;
page->mem_cgroup = NULL;
pgpgout++;
} while (next != page_list);
if (memcg)
uncharge_batch(memcg, pgpgout, nr_anon, nr_file,
nr_huge, page);
}
void mem_cgroup_uncharge(struct page *page)
{
if (mem_cgroup_disabled())
return;
if (!page->mem_cgroup)
return;
INIT_LIST_HEAD(&page->lru);
uncharge_list(&page->lru);
}
void mem_cgroup_uncharge_list(struct list_head *page_list)
{
if (mem_cgroup_disabled())
return;
if (!list_empty(page_list))
uncharge_list(page_list);
}
void mem_cgroup_migrate(struct page *oldpage, struct page *newpage,
bool lrucare)
{
struct mem_cgroup *memcg;
int isolated;
VM_BUG_ON_PAGE(!PageLocked(oldpage), oldpage);
VM_BUG_ON_PAGE(!PageLocked(newpage), newpage);
VM_BUG_ON_PAGE(!lrucare && PageLRU(oldpage), oldpage);
VM_BUG_ON_PAGE(!lrucare && PageLRU(newpage), newpage);
VM_BUG_ON_PAGE(PageAnon(oldpage) != PageAnon(newpage), newpage);
VM_BUG_ON_PAGE(PageTransHuge(oldpage) != PageTransHuge(newpage),
newpage);
if (mem_cgroup_disabled())
return;
if (newpage->mem_cgroup)
return;
memcg = oldpage->mem_cgroup;
if (!memcg)
return;
if (lrucare)
lock_page_lru(oldpage, &isolated);
oldpage->mem_cgroup = NULL;
if (lrucare)
unlock_page_lru(oldpage, isolated);
commit_charge(newpage, memcg, lrucare);
}
static int __init mem_cgroup_init(void)
{
int cpu, node;
hotcpu_notifier(memcg_cpu_hotplug_callback, 0);
for_each_possible_cpu(cpu)
INIT_WORK(&per_cpu_ptr(&memcg_stock, cpu)->work,
drain_local_stock);
for_each_node(node) {
struct mem_cgroup_tree_per_node *rtpn;
int zone;
rtpn = kzalloc_node(sizeof(*rtpn), GFP_KERNEL,
node_online(node) ? node : NUMA_NO_NODE);
for (zone = 0; zone < MAX_NR_ZONES; zone++) {
struct mem_cgroup_tree_per_zone *rtpz;
rtpz = &rtpn->rb_tree_per_zone[zone];
rtpz->rb_root = RB_ROOT;
spin_lock_init(&rtpz->lock);
}
soft_limit_tree.rb_tree_per_node[node] = rtpn;
}
return 0;
}
void mem_cgroup_swapout(struct page *page, swp_entry_t entry)
{
struct mem_cgroup *memcg;
unsigned short oldid;
VM_BUG_ON_PAGE(PageLRU(page), page);
VM_BUG_ON_PAGE(page_count(page), page);
if (!do_swap_account)
return;
memcg = page->mem_cgroup;
if (!memcg)
return;
oldid = swap_cgroup_record(entry, mem_cgroup_id(memcg));
VM_BUG_ON_PAGE(oldid, page);
mem_cgroup_swap_statistics(memcg, true);
page->mem_cgroup = NULL;
if (!mem_cgroup_is_root(memcg))
page_counter_uncharge(&memcg->memory, 1);
mem_cgroup_charge_statistics(memcg, page, -1);
memcg_check_events(memcg, page);
}
void mem_cgroup_uncharge_swap(swp_entry_t entry)
{
struct mem_cgroup *memcg;
unsigned short id;
if (!do_swap_account)
return;
id = swap_cgroup_record(entry, 0);
rcu_read_lock();
memcg = mem_cgroup_from_id(id);
if (memcg) {
if (!mem_cgroup_is_root(memcg))
page_counter_uncharge(&memcg->memsw, 1);
mem_cgroup_swap_statistics(memcg, false);
css_put(&memcg->css);
}
rcu_read_unlock();
}
static int __init enable_swap_account(char *s)
{
if (!strcmp(s, "1"))
really_do_swap_account = 1;
else if (!strcmp(s, "0"))
really_do_swap_account = 0;
return 1;
}
static int __init mem_cgroup_swap_init(void)
{
if (!mem_cgroup_disabled() && really_do_swap_account) {
do_swap_account = 1;
WARN_ON(cgroup_add_legacy_cftypes(&memory_cgrp_subsys,
memsw_cgroup_files));
}
return 0;
}
