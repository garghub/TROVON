static inline void memcg_kmem_set_active(struct mem_cgroup *memcg)
{
set_bit(KMEM_ACCOUNTED_ACTIVE, &memcg->kmem_account_flags);
}
static bool memcg_kmem_is_active(struct mem_cgroup *memcg)
{
return test_bit(KMEM_ACCOUNTED_ACTIVE, &memcg->kmem_account_flags);
}
static void memcg_kmem_mark_dead(struct mem_cgroup *memcg)
{
smp_wmb();
if (test_bit(KMEM_ACCOUNTED_ACTIVE, &memcg->kmem_account_flags))
set_bit(KMEM_ACCOUNTED_DEAD, &memcg->kmem_account_flags);
}
static bool memcg_kmem_test_and_clear_dead(struct mem_cgroup *memcg)
{
return test_and_clear_bit(KMEM_ACCOUNTED_DEAD,
&memcg->kmem_account_flags);
}
static bool move_anon(void)
{
return test_bit(MOVE_CHARGE_TYPE_ANON, &mc.immigrate_flags);
}
static bool move_file(void)
{
return test_bit(MOVE_CHARGE_TYPE_FILE, &mc.immigrate_flags);
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
static void disarm_sock_keys(struct mem_cgroup *memcg)
{
if (!memcg_proto_activated(&memcg->tcp_mem))
return;
static_key_slow_dec(&memcg_socket_limit_enabled);
}
static void disarm_sock_keys(struct mem_cgroup *memcg)
{
}
static void disarm_kmem_keys(struct mem_cgroup *memcg)
{
if (memcg_kmem_is_active(memcg)) {
static_key_slow_dec(&memcg_kmem_enabled_key);
ida_simple_remove(&kmem_limited_groups, memcg->kmemcg_id);
}
WARN_ON(res_counter_read_u64(&memcg->kmem, RES_USAGE) != 0);
}
static void disarm_kmem_keys(struct mem_cgroup *memcg)
{
}
static void disarm_static_keys(struct mem_cgroup *memcg)
{
disarm_sock_keys(memcg);
disarm_kmem_keys(memcg);
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
unsigned long long new_usage_in_excess)
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
spin_lock(&mctz->lock);
__mem_cgroup_remove_exceeded(mz, mctz);
spin_unlock(&mctz->lock);
}
static void mem_cgroup_update_tree(struct mem_cgroup *memcg, struct page *page)
{
unsigned long long excess;
struct mem_cgroup_per_zone *mz;
struct mem_cgroup_tree_per_zone *mctz;
mctz = soft_limit_tree_from_page(page);
for (; memcg; memcg = parent_mem_cgroup(memcg)) {
mz = mem_cgroup_page_zoneinfo(memcg, page);
excess = res_counter_soft_limit_excess(&memcg->res);
if (excess || mz->on_tree) {
spin_lock(&mctz->lock);
if (mz->on_tree)
__mem_cgroup_remove_exceeded(mz, mctz);
__mem_cgroup_insert_exceeded(mz, mctz, excess);
spin_unlock(&mctz->lock);
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
if (!res_counter_soft_limit_excess(&mz->memcg->res) ||
!css_tryget_online(&mz->memcg->css))
goto retry;
done:
return mz;
}
static struct mem_cgroup_per_zone *
mem_cgroup_largest_soft_limit_node(struct mem_cgroup_tree_per_zone *mctz)
{
struct mem_cgroup_per_zone *mz;
spin_lock(&mctz->lock);
mz = __mem_cgroup_largest_soft_limit_node(mctz);
spin_unlock(&mctz->lock);
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
static void mem_cgroup_swap_statistics(struct mem_cgroup *memcg,
bool charge)
{
int val = (charge) ? 1 : -1;
this_cpu_add(memcg->stat->count[MEM_CGROUP_STAT_SWAP], val);
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
bool anon, int nr_pages)
{
if (anon)
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
preempt_disable();
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
preempt_enable();
mem_cgroup_threshold(memcg);
if (unlikely(do_softlimit))
mem_cgroup_update_tree(memcg, page);
#if MAX_NUMNODES > 1
if (unlikely(do_numainfo))
atomic_inc(&memcg->numainfo_events);
#endif
} else
preempt_enable();
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
static struct mem_cgroup *__mem_cgroup_iter_next(struct mem_cgroup *root,
struct mem_cgroup *last_visited)
{
struct cgroup_subsys_state *prev_css, *next_css;
prev_css = last_visited ? &last_visited->css : NULL;
skip_node:
next_css = css_next_descendant_pre(prev_css, &root->css);
if (next_css) {
if ((next_css == &root->css) ||
((next_css->flags & CSS_ONLINE) &&
css_tryget_online(next_css)))
return mem_cgroup_from_css(next_css);
prev_css = next_css;
goto skip_node;
}
return NULL;
}
static void mem_cgroup_iter_invalidate(struct mem_cgroup *root)
{
atomic_inc(&root->dead_count);
}
static struct mem_cgroup *
mem_cgroup_iter_load(struct mem_cgroup_reclaim_iter *iter,
struct mem_cgroup *root,
int *sequence)
{
struct mem_cgroup *position = NULL;
*sequence = atomic_read(&root->dead_count);
if (iter->last_dead_count == *sequence) {
smp_rmb();
position = iter->last_visited;
if (position && position != root &&
!css_tryget_online(&position->css))
position = NULL;
}
return position;
}
static void mem_cgroup_iter_update(struct mem_cgroup_reclaim_iter *iter,
struct mem_cgroup *last_visited,
struct mem_cgroup *new_position,
struct mem_cgroup *root,
int sequence)
{
if (last_visited && last_visited != root)
css_put(&last_visited->css);
iter->last_visited = new_position;
smp_wmb();
iter->last_dead_count = sequence;
}
struct mem_cgroup *mem_cgroup_iter(struct mem_cgroup *root,
struct mem_cgroup *prev,
struct mem_cgroup_reclaim_cookie *reclaim)
{
struct mem_cgroup *memcg = NULL;
struct mem_cgroup *last_visited = NULL;
if (mem_cgroup_disabled())
return NULL;
if (!root)
root = root_mem_cgroup;
if (prev && !reclaim)
last_visited = prev;
if (!root->use_hierarchy && root != root_mem_cgroup) {
if (prev)
goto out_css_put;
return root;
}
rcu_read_lock();
while (!memcg) {
struct mem_cgroup_reclaim_iter *uninitialized_var(iter);
int uninitialized_var(seq);
if (reclaim) {
struct mem_cgroup_per_zone *mz;
mz = mem_cgroup_zone_zoneinfo(root, reclaim->zone);
iter = &mz->reclaim_iter[reclaim->priority];
if (prev && reclaim->generation != iter->generation) {
iter->last_visited = NULL;
goto out_unlock;
}
last_visited = mem_cgroup_iter_load(iter, root, &seq);
}
memcg = __mem_cgroup_iter_next(root, last_visited);
if (reclaim) {
mem_cgroup_iter_update(iter, last_visited, memcg, root,
seq);
if (!memcg)
iter->generation++;
else if (!prev && memcg)
reclaim->generation = iter->generation;
}
if (prev && !memcg)
goto out_unlock;
}
out_unlock:
rcu_read_unlock();
out_css_put:
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
struct page_cgroup *pc;
struct lruvec *lruvec;
if (mem_cgroup_disabled()) {
lruvec = &zone->lruvec;
goto out;
}
pc = lookup_page_cgroup(page);
memcg = pc->mem_cgroup;
if (!PageLRU(page) && !PageCgroupUsed(pc) && memcg != root_mem_cgroup)
pc->mem_cgroup = memcg = root_mem_cgroup;
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
bool __mem_cgroup_same_or_subtree(const struct mem_cgroup *root_memcg,
struct mem_cgroup *memcg)
{
if (root_memcg == memcg)
return true;
if (!root_memcg->use_hierarchy || !memcg)
return false;
return cgroup_is_descendant(memcg->css.cgroup, root_memcg->css.cgroup);
}
static bool mem_cgroup_same_or_subtree(const struct mem_cgroup *root_memcg,
struct mem_cgroup *memcg)
{
bool ret;
rcu_read_lock();
ret = __mem_cgroup_same_or_subtree(root_memcg, memcg);
rcu_read_unlock();
return ret;
}
bool task_in_mem_cgroup(struct task_struct *task,
const struct mem_cgroup *memcg)
{
struct mem_cgroup *curr = NULL;
struct task_struct *p;
bool ret;
p = find_lock_task_mm(task);
if (p) {
curr = get_mem_cgroup_from_mm(p->mm);
task_unlock(p);
} else {
rcu_read_lock();
curr = mem_cgroup_from_task(task);
if (curr)
css_get(&curr->css);
rcu_read_unlock();
}
ret = mem_cgroup_same_or_subtree(memcg, curr);
css_put(&curr->css);
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
static unsigned long mem_cgroup_margin(struct mem_cgroup *memcg)
{
unsigned long long margin;
margin = res_counter_margin(&memcg->res);
if (do_swap_account)
margin = min(margin, res_counter_margin(&memcg->memsw));
return margin >> PAGE_SHIFT;
}
int mem_cgroup_swappiness(struct mem_cgroup *memcg)
{
if (mem_cgroup_disabled() || !memcg->css.parent)
return vm_swappiness;
return memcg->swappiness;
}
static void mem_cgroup_start_move(struct mem_cgroup *memcg)
{
atomic_inc(&memcg_moving);
atomic_inc(&memcg->moving_account);
synchronize_rcu();
}
static void mem_cgroup_end_move(struct mem_cgroup *memcg)
{
if (memcg) {
atomic_dec(&memcg_moving);
atomic_dec(&memcg->moving_account);
}
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
ret = mem_cgroup_same_or_subtree(memcg, from)
|| mem_cgroup_same_or_subtree(memcg, to);
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
static void move_lock_mem_cgroup(struct mem_cgroup *memcg,
unsigned long *flags)
{
spin_lock_irqsave(&memcg->move_lock, *flags);
}
static void move_unlock_mem_cgroup(struct mem_cgroup *memcg,
unsigned long *flags)
{
spin_unlock_irqrestore(&memcg->move_lock, *flags);
}
void mem_cgroup_print_oom_info(struct mem_cgroup *memcg, struct task_struct *p)
{
static DEFINE_MUTEX(oom_info_lock);
struct mem_cgroup *iter;
unsigned int i;
if (!p)
return;
mutex_lock(&oom_info_lock);
rcu_read_lock();
pr_info("Task in ");
pr_cont_cgroup_path(task_cgroup(p, memory_cgrp_id));
pr_info(" killed as a result of limit of ");
pr_cont_cgroup_path(memcg->css.cgroup);
pr_info("\n");
rcu_read_unlock();
pr_info("memory: usage %llukB, limit %llukB, failcnt %llu\n",
res_counter_read_u64(&memcg->res, RES_USAGE) >> 10,
res_counter_read_u64(&memcg->res, RES_LIMIT) >> 10,
res_counter_read_u64(&memcg->res, RES_FAILCNT));
pr_info("memory+swap: usage %llukB, limit %llukB, failcnt %llu\n",
res_counter_read_u64(&memcg->memsw, RES_USAGE) >> 10,
res_counter_read_u64(&memcg->memsw, RES_LIMIT) >> 10,
res_counter_read_u64(&memcg->memsw, RES_FAILCNT));
pr_info("kmem: usage %llukB, limit %llukB, failcnt %llu\n",
res_counter_read_u64(&memcg->kmem, RES_USAGE) >> 10,
res_counter_read_u64(&memcg->kmem, RES_LIMIT) >> 10,
res_counter_read_u64(&memcg->kmem, RES_FAILCNT));
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
static u64 mem_cgroup_get_limit(struct mem_cgroup *memcg)
{
u64 limit;
limit = res_counter_read_u64(&memcg->res, RES_LIMIT);
if (mem_cgroup_swappiness(memcg)) {
u64 memsw;
limit += total_swap_pages << PAGE_SHIFT;
memsw = res_counter_read_u64(&memcg->memsw, RES_LIMIT);
limit = min(limit, memsw);
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
if (fatal_signal_pending(current) || current->flags & PF_EXITING) {
set_thread_flag(TIF_MEMDIE);
return;
}
check_panic_on_oom(CONSTRAINT_MEMCG, gfp_mask, order, NULL);
totalpages = mem_cgroup_get_limit(memcg) >> PAGE_SHIFT ? : 1;
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
static unsigned long mem_cgroup_reclaim(struct mem_cgroup *memcg,
gfp_t gfp_mask,
unsigned long flags)
{
unsigned long total = 0;
bool noswap = false;
int loop;
if (flags & MEM_CGROUP_RECLAIM_NOSWAP)
noswap = true;
if (!(flags & MEM_CGROUP_RECLAIM_SHRINK) && memcg->memsw_is_minimum)
noswap = true;
for (loop = 0; loop < MEM_CGROUP_MAX_RECLAIM_LOOPS; loop++) {
if (loop)
drain_all_stock_async(memcg);
total += try_to_free_mem_cgroup_pages(memcg, gfp_mask, noswap);
if (total && (flags & MEM_CGROUP_RECLAIM_SHRINK))
break;
if (mem_cgroup_margin(memcg))
break;
if (loop && !total)
break;
}
return total;
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
static bool mem_cgroup_reclaimable(struct mem_cgroup *memcg, bool noswap)
{
int nid;
if (!nodes_empty(memcg->scan_nodes)) {
for (nid = first_node(memcg->scan_nodes);
nid < MAX_NUMNODES;
nid = next_node(nid, memcg->scan_nodes)) {
if (test_mem_cgroup_node_reclaimable(memcg, nid, noswap))
return true;
}
}
for_each_node_state(nid, N_MEMORY) {
if (node_isset(nid, memcg->scan_nodes))
continue;
if (test_mem_cgroup_node_reclaimable(memcg, nid, noswap))
return true;
}
return false;
}
int mem_cgroup_select_victim_node(struct mem_cgroup *memcg)
{
return 0;
}
static bool mem_cgroup_reclaimable(struct mem_cgroup *memcg, bool noswap)
{
return test_mem_cgroup_node_reclaimable(memcg, 0, noswap);
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
excess = res_counter_soft_limit_excess(&root_memcg->res) >> PAGE_SHIFT;
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
if (!mem_cgroup_reclaimable(victim, false))
continue;
total += mem_cgroup_shrink_node_zone(victim, gfp_mask, false,
zone, &nr_scanned);
*total_scanned += nr_scanned;
if (!res_counter_soft_limit_excess(&root_memcg->res))
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
if (!mem_cgroup_same_or_subtree(oom_wait_memcg, wake_memcg)
&& !mem_cgroup_same_or_subtree(wake_memcg, oom_wait_memcg))
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
if (!handle)
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
void __mem_cgroup_begin_update_page_stat(struct page *page,
bool *locked, unsigned long *flags)
{
struct mem_cgroup *memcg;
struct page_cgroup *pc;
pc = lookup_page_cgroup(page);
again:
memcg = pc->mem_cgroup;
if (unlikely(!memcg || !PageCgroupUsed(pc)))
return;
VM_BUG_ON(!rcu_read_lock_held());
if (atomic_read(&memcg->moving_account) <= 0)
return;
move_lock_mem_cgroup(memcg, flags);
if (memcg != pc->mem_cgroup || !PageCgroupUsed(pc)) {
move_unlock_mem_cgroup(memcg, flags);
goto again;
}
*locked = true;
}
void __mem_cgroup_end_update_page_stat(struct page *page, unsigned long *flags)
{
struct page_cgroup *pc = lookup_page_cgroup(page);
move_unlock_mem_cgroup(pc->mem_cgroup, flags);
}
void mem_cgroup_update_page_stat(struct page *page,
enum mem_cgroup_stat_index idx, int val)
{
struct mem_cgroup *memcg;
struct page_cgroup *pc = lookup_page_cgroup(page);
unsigned long uninitialized_var(flags);
if (mem_cgroup_disabled())
return;
VM_BUG_ON(!rcu_read_lock_held());
memcg = pc->mem_cgroup;
if (unlikely(!memcg || !PageCgroupUsed(pc)))
return;
this_cpu_add(memcg->stat->count[idx], val);
}
static bool consume_stock(struct mem_cgroup *memcg, unsigned int nr_pages)
{
struct memcg_stock_pcp *stock;
bool ret = true;
if (nr_pages > CHARGE_BATCH)
return false;
stock = &get_cpu_var(memcg_stock);
if (memcg == stock->cached && stock->nr_pages >= nr_pages)
stock->nr_pages -= nr_pages;
else
ret = false;
put_cpu_var(memcg_stock);
return ret;
}
static void drain_stock(struct memcg_stock_pcp *stock)
{
struct mem_cgroup *old = stock->cached;
if (stock->nr_pages) {
unsigned long bytes = stock->nr_pages * PAGE_SIZE;
res_counter_uncharge(&old->res, bytes);
if (do_swap_account)
res_counter_uncharge(&old->memsw, bytes);
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
static void __init memcg_stock_init(void)
{
int cpu;
for_each_possible_cpu(cpu) {
struct memcg_stock_pcp *stock =
&per_cpu(memcg_stock, cpu);
INIT_WORK(&stock->work, drain_local_stock);
}
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
static void drain_all_stock(struct mem_cgroup *root_memcg, bool sync)
{
int cpu, curcpu;
get_online_cpus();
curcpu = get_cpu();
for_each_online_cpu(cpu) {
struct memcg_stock_pcp *stock = &per_cpu(memcg_stock, cpu);
struct mem_cgroup *memcg;
memcg = stock->cached;
if (!memcg || !stock->nr_pages)
continue;
if (!mem_cgroup_same_or_subtree(root_memcg, memcg))
continue;
if (!test_and_set_bit(FLUSHING_CACHED_CHARGE, &stock->flags)) {
if (cpu == curcpu)
drain_local_stock(&stock->work);
else
schedule_work_on(cpu, &stock->work);
}
}
put_cpu();
if (!sync)
goto out;
for_each_online_cpu(cpu) {
struct memcg_stock_pcp *stock = &per_cpu(memcg_stock, cpu);
if (test_bit(FLUSHING_CACHED_CHARGE, &stock->flags))
flush_work(&stock->work);
}
out:
put_online_cpus();
}
static void drain_all_stock_async(struct mem_cgroup *root_memcg)
{
if (!mutex_trylock(&percpu_charge_mutex))
return;
drain_all_stock(root_memcg, false);
mutex_unlock(&percpu_charge_mutex);
}
static void drain_all_stock_sync(struct mem_cgroup *root_memcg)
{
mutex_lock(&percpu_charge_mutex);
drain_all_stock(root_memcg, true);
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
static int mem_cgroup_do_charge(struct mem_cgroup *memcg, gfp_t gfp_mask,
unsigned int nr_pages, unsigned int min_pages,
bool invoke_oom)
{
unsigned long csize = nr_pages * PAGE_SIZE;
struct mem_cgroup *mem_over_limit;
struct res_counter *fail_res;
unsigned long flags = 0;
int ret;
ret = res_counter_charge(&memcg->res, csize, &fail_res);
if (likely(!ret)) {
if (!do_swap_account)
return CHARGE_OK;
ret = res_counter_charge(&memcg->memsw, csize, &fail_res);
if (likely(!ret))
return CHARGE_OK;
res_counter_uncharge(&memcg->res, csize);
mem_over_limit = mem_cgroup_from_res_counter(fail_res, memsw);
flags |= MEM_CGROUP_RECLAIM_NOSWAP;
} else
mem_over_limit = mem_cgroup_from_res_counter(fail_res, res);
if (nr_pages > min_pages)
return CHARGE_RETRY;
if (!(gfp_mask & __GFP_WAIT))
return CHARGE_WOULDBLOCK;
if (gfp_mask & __GFP_NORETRY)
return CHARGE_NOMEM;
ret = mem_cgroup_reclaim(mem_over_limit, gfp_mask, flags);
if (mem_cgroup_margin(mem_over_limit) >= nr_pages)
return CHARGE_RETRY;
if (nr_pages <= (1 << PAGE_ALLOC_COSTLY_ORDER) && ret)
return CHARGE_RETRY;
if (mem_cgroup_wait_acct_move(mem_over_limit))
return CHARGE_RETRY;
if (invoke_oom)
mem_cgroup_oom(mem_over_limit, gfp_mask, get_order(csize));
return CHARGE_NOMEM;
}
static int mem_cgroup_try_charge(struct mem_cgroup *memcg,
gfp_t gfp_mask,
unsigned int nr_pages,
bool oom)
{
unsigned int batch = max(CHARGE_BATCH, nr_pages);
int nr_oom_retries = MEM_CGROUP_RECLAIM_RETRIES;
int ret;
if (mem_cgroup_is_root(memcg))
goto done;
if (unlikely(test_thread_flag(TIF_MEMDIE) ||
fatal_signal_pending(current) ||
current->flags & PF_EXITING))
goto bypass;
if (unlikely(task_in_memcg_oom(current)))
goto nomem;
if (gfp_mask & __GFP_NOFAIL)
oom = false;
again:
if (consume_stock(memcg, nr_pages))
goto done;
do {
bool invoke_oom = oom && !nr_oom_retries;
if (fatal_signal_pending(current))
goto bypass;
ret = mem_cgroup_do_charge(memcg, gfp_mask, batch,
nr_pages, invoke_oom);
switch (ret) {
case CHARGE_OK:
break;
case CHARGE_RETRY:
batch = nr_pages;
goto again;
case CHARGE_WOULDBLOCK:
goto nomem;
case CHARGE_NOMEM:
if (!oom || invoke_oom)
goto nomem;
nr_oom_retries--;
break;
}
} while (ret != CHARGE_OK);
if (batch > nr_pages)
refill_stock(memcg, batch - nr_pages);
done:
return 0;
nomem:
if (!(gfp_mask & __GFP_NOFAIL))
return -ENOMEM;
bypass:
return -EINTR;
}
static struct mem_cgroup *mem_cgroup_try_charge_mm(struct mm_struct *mm,
gfp_t gfp_mask,
unsigned int nr_pages,
bool oom)
{
struct mem_cgroup *memcg;
int ret;
memcg = get_mem_cgroup_from_mm(mm);
ret = mem_cgroup_try_charge(memcg, gfp_mask, nr_pages, oom);
css_put(&memcg->css);
if (ret == -EINTR)
memcg = root_mem_cgroup;
else if (ret)
memcg = NULL;
return memcg;
}
static void __mem_cgroup_cancel_charge(struct mem_cgroup *memcg,
unsigned int nr_pages)
{
if (!mem_cgroup_is_root(memcg)) {
unsigned long bytes = nr_pages * PAGE_SIZE;
res_counter_uncharge(&memcg->res, bytes);
if (do_swap_account)
res_counter_uncharge(&memcg->memsw, bytes);
}
}
static void __mem_cgroup_cancel_local_charge(struct mem_cgroup *memcg,
unsigned int nr_pages)
{
unsigned long bytes = nr_pages * PAGE_SIZE;
if (mem_cgroup_is_root(memcg))
return;
res_counter_uncharge_until(&memcg->res, memcg->res.parent, bytes);
if (do_swap_account)
res_counter_uncharge_until(&memcg->memsw,
memcg->memsw.parent, bytes);
}
static struct mem_cgroup *mem_cgroup_lookup(unsigned short id)
{
if (!id)
return NULL;
return mem_cgroup_from_id(id);
}
struct mem_cgroup *try_get_mem_cgroup_from_page(struct page *page)
{
struct mem_cgroup *memcg = NULL;
struct page_cgroup *pc;
unsigned short id;
swp_entry_t ent;
VM_BUG_ON_PAGE(!PageLocked(page), page);
pc = lookup_page_cgroup(page);
lock_page_cgroup(pc);
if (PageCgroupUsed(pc)) {
memcg = pc->mem_cgroup;
if (memcg && !css_tryget_online(&memcg->css))
memcg = NULL;
} else if (PageSwapCache(page)) {
ent.val = page_private(page);
id = lookup_swap_cgroup_id(ent);
rcu_read_lock();
memcg = mem_cgroup_lookup(id);
if (memcg && !css_tryget_online(&memcg->css))
memcg = NULL;
rcu_read_unlock();
}
unlock_page_cgroup(pc);
return memcg;
}
static void __mem_cgroup_commit_charge(struct mem_cgroup *memcg,
struct page *page,
unsigned int nr_pages,
enum charge_type ctype,
bool lrucare)
{
struct page_cgroup *pc = lookup_page_cgroup(page);
struct zone *uninitialized_var(zone);
struct lruvec *lruvec;
bool was_on_lru = false;
bool anon;
lock_page_cgroup(pc);
VM_BUG_ON_PAGE(PageCgroupUsed(pc), page);
if (lrucare) {
zone = page_zone(page);
spin_lock_irq(&zone->lru_lock);
if (PageLRU(page)) {
lruvec = mem_cgroup_zone_lruvec(zone, pc->mem_cgroup);
ClearPageLRU(page);
del_page_from_lru_list(page, lruvec, page_lru(page));
was_on_lru = true;
}
}
pc->mem_cgroup = memcg;
smp_wmb();
SetPageCgroupUsed(pc);
if (lrucare) {
if (was_on_lru) {
lruvec = mem_cgroup_zone_lruvec(zone, pc->mem_cgroup);
VM_BUG_ON_PAGE(PageLRU(page), page);
SetPageLRU(page);
add_page_to_lru_list(page, lruvec, page_lru(page));
}
spin_unlock_irq(&zone->lru_lock);
}
if (ctype == MEM_CGROUP_CHARGE_TYPE_ANON)
anon = true;
else
anon = false;
mem_cgroup_charge_statistics(memcg, page, anon, nr_pages);
unlock_page_cgroup(pc);
memcg_check_events(memcg, page);
}
static inline bool memcg_can_account_kmem(struct mem_cgroup *memcg)
{
return !mem_cgroup_disabled() && !mem_cgroup_is_root(memcg) &&
memcg_kmem_is_active(memcg);
}
static struct kmem_cache *memcg_params_to_cache(struct memcg_cache_params *p)
{
struct kmem_cache *cachep;
VM_BUG_ON(p->is_root_cache);
cachep = p->root_cache;
return cache_from_memcg_idx(cachep, memcg_cache_id(p->memcg));
}
static int mem_cgroup_slabinfo_read(struct seq_file *m, void *v)
{
struct mem_cgroup *memcg = mem_cgroup_from_css(seq_css(m));
struct memcg_cache_params *params;
if (!memcg_can_account_kmem(memcg))
return -EIO;
print_slabinfo_header(m);
mutex_lock(&memcg_slab_mutex);
list_for_each_entry(params, &memcg->memcg_slab_caches, list)
cache_show(memcg_params_to_cache(params), m);
mutex_unlock(&memcg_slab_mutex);
return 0;
}
static int memcg_charge_kmem(struct mem_cgroup *memcg, gfp_t gfp, u64 size)
{
struct res_counter *fail_res;
int ret = 0;
ret = res_counter_charge(&memcg->kmem, size, &fail_res);
if (ret)
return ret;
ret = mem_cgroup_try_charge(memcg, gfp, size >> PAGE_SHIFT,
oom_gfp_allowed(gfp));
if (ret == -EINTR) {
res_counter_charge_nofail(&memcg->res, size, &fail_res);
if (do_swap_account)
res_counter_charge_nofail(&memcg->memsw, size,
&fail_res);
ret = 0;
} else if (ret)
res_counter_uncharge(&memcg->kmem, size);
return ret;
}
static void memcg_uncharge_kmem(struct mem_cgroup *memcg, u64 size)
{
res_counter_uncharge(&memcg->res, size);
if (do_swap_account)
res_counter_uncharge(&memcg->memsw, size);
if (res_counter_uncharge(&memcg->kmem, size))
return;
if (memcg_kmem_test_and_clear_dead(memcg))
css_put(&memcg->css);
}
int memcg_cache_id(struct mem_cgroup *memcg)
{
return memcg ? memcg->kmemcg_id : -1;
}
static size_t memcg_caches_array_size(int num_groups)
{
ssize_t size;
if (num_groups <= 0)
return 0;
size = 2 * num_groups;
if (size < MEMCG_CACHES_MIN_SIZE)
size = MEMCG_CACHES_MIN_SIZE;
else if (size > MEMCG_CACHES_MAX_SIZE)
size = MEMCG_CACHES_MAX_SIZE;
return size;
}
void memcg_update_array_size(int num)
{
if (num > memcg_limited_groups_array_size)
memcg_limited_groups_array_size = memcg_caches_array_size(num);
}
int memcg_update_cache_size(struct kmem_cache *s, int num_groups)
{
struct memcg_cache_params *cur_params = s->memcg_params;
VM_BUG_ON(!is_root_cache(s));
if (num_groups > memcg_limited_groups_array_size) {
int i;
struct memcg_cache_params *new_params;
ssize_t size = memcg_caches_array_size(num_groups);
size *= sizeof(void *);
size += offsetof(struct memcg_cache_params, memcg_caches);
new_params = kzalloc(size, GFP_KERNEL);
if (!new_params)
return -ENOMEM;
new_params->is_root_cache = true;
for (i = 0; i < memcg_limited_groups_array_size; i++) {
if (!cur_params->memcg_caches[i])
continue;
new_params->memcg_caches[i] =
cur_params->memcg_caches[i];
}
rcu_assign_pointer(s->memcg_params, new_params);
if (cur_params)
kfree_rcu(cur_params, rcu_head);
}
return 0;
}
int memcg_alloc_cache_params(struct mem_cgroup *memcg, struct kmem_cache *s,
struct kmem_cache *root_cache)
{
size_t size;
if (!memcg_kmem_enabled())
return 0;
if (!memcg) {
size = offsetof(struct memcg_cache_params, memcg_caches);
size += memcg_limited_groups_array_size * sizeof(void *);
} else
size = sizeof(struct memcg_cache_params);
s->memcg_params = kzalloc(size, GFP_KERNEL);
if (!s->memcg_params)
return -ENOMEM;
if (memcg) {
s->memcg_params->memcg = memcg;
s->memcg_params->root_cache = root_cache;
css_get(&memcg->css);
} else
s->memcg_params->is_root_cache = true;
return 0;
}
void memcg_free_cache_params(struct kmem_cache *s)
{
if (!s->memcg_params)
return;
if (!s->memcg_params->is_root_cache)
css_put(&s->memcg_params->memcg->css);
kfree(s->memcg_params);
}
static void memcg_register_cache(struct mem_cgroup *memcg,
struct kmem_cache *root_cache)
{
static char memcg_name_buf[NAME_MAX + 1];
struct kmem_cache *cachep;
int id;
lockdep_assert_held(&memcg_slab_mutex);
id = memcg_cache_id(memcg);
if (cache_from_memcg_idx(root_cache, id))
return;
cgroup_name(memcg->css.cgroup, memcg_name_buf, NAME_MAX + 1);
cachep = memcg_create_kmem_cache(memcg, root_cache, memcg_name_buf);
if (!cachep)
return;
list_add(&cachep->memcg_params->list, &memcg->memcg_slab_caches);
smp_wmb();
BUG_ON(root_cache->memcg_params->memcg_caches[id]);
root_cache->memcg_params->memcg_caches[id] = cachep;
}
static void memcg_unregister_cache(struct kmem_cache *cachep)
{
struct kmem_cache *root_cache;
struct mem_cgroup *memcg;
int id;
lockdep_assert_held(&memcg_slab_mutex);
BUG_ON(is_root_cache(cachep));
root_cache = cachep->memcg_params->root_cache;
memcg = cachep->memcg_params->memcg;
id = memcg_cache_id(memcg);
BUG_ON(root_cache->memcg_params->memcg_caches[id] != cachep);
root_cache->memcg_params->memcg_caches[id] = NULL;
list_del(&cachep->memcg_params->list);
kmem_cache_destroy(cachep);
}
static inline void memcg_stop_kmem_account(void)
{
VM_BUG_ON(!current->mm);
current->memcg_kmem_skip_account++;
}
static inline void memcg_resume_kmem_account(void)
{
VM_BUG_ON(!current->mm);
current->memcg_kmem_skip_account--;
}
int __memcg_cleanup_cache_params(struct kmem_cache *s)
{
struct kmem_cache *c;
int i, failed = 0;
mutex_lock(&memcg_slab_mutex);
for_each_memcg_cache_index(i) {
c = cache_from_memcg_idx(s, i);
if (!c)
continue;
memcg_unregister_cache(c);
if (cache_from_memcg_idx(s, i))
failed++;
}
mutex_unlock(&memcg_slab_mutex);
return failed;
}
static void memcg_unregister_all_caches(struct mem_cgroup *memcg)
{
struct kmem_cache *cachep;
struct memcg_cache_params *params, *tmp;
if (!memcg_kmem_is_active(memcg))
return;
mutex_lock(&memcg_slab_mutex);
list_for_each_entry_safe(params, tmp, &memcg->memcg_slab_caches, list) {
cachep = memcg_params_to_cache(params);
kmem_cache_shrink(cachep);
if (atomic_read(&cachep->memcg_params->nr_pages) == 0)
memcg_unregister_cache(cachep);
}
mutex_unlock(&memcg_slab_mutex);
}
static void memcg_register_cache_func(struct work_struct *w)
{
struct memcg_register_cache_work *cw =
container_of(w, struct memcg_register_cache_work, work);
struct mem_cgroup *memcg = cw->memcg;
struct kmem_cache *cachep = cw->cachep;
mutex_lock(&memcg_slab_mutex);
memcg_register_cache(memcg, cachep);
mutex_unlock(&memcg_slab_mutex);
css_put(&memcg->css);
kfree(cw);
}
static void __memcg_schedule_register_cache(struct mem_cgroup *memcg,
struct kmem_cache *cachep)
{
struct memcg_register_cache_work *cw;
cw = kmalloc(sizeof(*cw), GFP_NOWAIT);
if (cw == NULL) {
css_put(&memcg->css);
return;
}
cw->memcg = memcg;
cw->cachep = cachep;
INIT_WORK(&cw->work, memcg_register_cache_func);
schedule_work(&cw->work);
}
static void memcg_schedule_register_cache(struct mem_cgroup *memcg,
struct kmem_cache *cachep)
{
memcg_stop_kmem_account();
__memcg_schedule_register_cache(memcg, cachep);
memcg_resume_kmem_account();
}
int __memcg_charge_slab(struct kmem_cache *cachep, gfp_t gfp, int order)
{
int res;
res = memcg_charge_kmem(cachep->memcg_params->memcg, gfp,
PAGE_SIZE << order);
if (!res)
atomic_add(1 << order, &cachep->memcg_params->nr_pages);
return res;
}
void __memcg_uncharge_slab(struct kmem_cache *cachep, int order)
{
memcg_uncharge_kmem(cachep->memcg_params->memcg, PAGE_SIZE << order);
atomic_sub(1 << order, &cachep->memcg_params->nr_pages);
}
struct kmem_cache *__memcg_kmem_get_cache(struct kmem_cache *cachep,
gfp_t gfp)
{
struct mem_cgroup *memcg;
struct kmem_cache *memcg_cachep;
VM_BUG_ON(!cachep->memcg_params);
VM_BUG_ON(!cachep->memcg_params->is_root_cache);
if (!current->mm || current->memcg_kmem_skip_account)
return cachep;
rcu_read_lock();
memcg = mem_cgroup_from_task(rcu_dereference(current->mm->owner));
if (!memcg_can_account_kmem(memcg))
goto out;
memcg_cachep = cache_from_memcg_idx(cachep, memcg_cache_id(memcg));
if (likely(memcg_cachep)) {
cachep = memcg_cachep;
goto out;
}
if (!css_tryget_online(&memcg->css))
goto out;
rcu_read_unlock();
memcg_schedule_register_cache(memcg, cachep);
return cachep;
out:
rcu_read_unlock();
return cachep;
}
bool
__memcg_kmem_newpage_charge(gfp_t gfp, struct mem_cgroup **_memcg, int order)
{
struct mem_cgroup *memcg;
int ret;
*_memcg = NULL;
if (!current->mm || current->memcg_kmem_skip_account)
return true;
memcg = get_mem_cgroup_from_mm(current->mm);
if (!memcg_can_account_kmem(memcg)) {
css_put(&memcg->css);
return true;
}
ret = memcg_charge_kmem(memcg, gfp, PAGE_SIZE << order);
if (!ret)
*_memcg = memcg;
css_put(&memcg->css);
return (ret == 0);
}
void __memcg_kmem_commit_charge(struct page *page, struct mem_cgroup *memcg,
int order)
{
struct page_cgroup *pc;
VM_BUG_ON(mem_cgroup_is_root(memcg));
if (!page) {
memcg_uncharge_kmem(memcg, PAGE_SIZE << order);
return;
}
pc = lookup_page_cgroup(page);
lock_page_cgroup(pc);
pc->mem_cgroup = memcg;
SetPageCgroupUsed(pc);
unlock_page_cgroup(pc);
}
void __memcg_kmem_uncharge_pages(struct page *page, int order)
{
struct mem_cgroup *memcg = NULL;
struct page_cgroup *pc;
pc = lookup_page_cgroup(page);
if (!PageCgroupUsed(pc))
return;
lock_page_cgroup(pc);
if (PageCgroupUsed(pc)) {
memcg = pc->mem_cgroup;
ClearPageCgroupUsed(pc);
}
unlock_page_cgroup(pc);
if (!memcg)
return;
VM_BUG_ON_PAGE(mem_cgroup_is_root(memcg), page);
memcg_uncharge_kmem(memcg, PAGE_SIZE << order);
}
static inline void memcg_unregister_all_caches(struct mem_cgroup *memcg)
{
}
void mem_cgroup_split_huge_fixup(struct page *head)
{
struct page_cgroup *head_pc = lookup_page_cgroup(head);
struct page_cgroup *pc;
struct mem_cgroup *memcg;
int i;
if (mem_cgroup_disabled())
return;
memcg = head_pc->mem_cgroup;
for (i = 1; i < HPAGE_PMD_NR; i++) {
pc = head_pc + i;
pc->mem_cgroup = memcg;
smp_wmb();
pc->flags = head_pc->flags & ~PCGF_NOCOPY_AT_SPLIT;
}
__this_cpu_sub(memcg->stat->count[MEM_CGROUP_STAT_RSS_HUGE],
HPAGE_PMD_NR);
}
static int mem_cgroup_move_account(struct page *page,
unsigned int nr_pages,
struct page_cgroup *pc,
struct mem_cgroup *from,
struct mem_cgroup *to)
{
unsigned long flags;
int ret;
bool anon = PageAnon(page);
VM_BUG_ON(from == to);
VM_BUG_ON_PAGE(PageLRU(page), page);
ret = -EBUSY;
if (nr_pages > 1 && !PageTransHuge(page))
goto out;
lock_page_cgroup(pc);
ret = -EINVAL;
if (!PageCgroupUsed(pc) || pc->mem_cgroup != from)
goto unlock;
move_lock_mem_cgroup(from, &flags);
if (!anon && page_mapped(page)) {
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
mem_cgroup_charge_statistics(from, page, anon, -nr_pages);
pc->mem_cgroup = to;
mem_cgroup_charge_statistics(to, page, anon, nr_pages);
move_unlock_mem_cgroup(from, &flags);
ret = 0;
unlock:
unlock_page_cgroup(pc);
memcg_check_events(to, page);
memcg_check_events(from, page);
out:
return ret;
}
static int mem_cgroup_move_parent(struct page *page,
struct page_cgroup *pc,
struct mem_cgroup *child)
{
struct mem_cgroup *parent;
unsigned int nr_pages;
unsigned long uninitialized_var(flags);
int ret;
VM_BUG_ON(mem_cgroup_is_root(child));
ret = -EBUSY;
if (!get_page_unless_zero(page))
goto out;
if (isolate_lru_page(page))
goto put;
nr_pages = hpage_nr_pages(page);
parent = parent_mem_cgroup(child);
if (!parent)
parent = root_mem_cgroup;
if (nr_pages > 1) {
VM_BUG_ON_PAGE(!PageTransHuge(page), page);
flags = compound_lock_irqsave(page);
}
ret = mem_cgroup_move_account(page, nr_pages,
pc, child, parent);
if (!ret)
__mem_cgroup_cancel_local_charge(child, nr_pages);
if (nr_pages > 1)
compound_unlock_irqrestore(page, flags);
putback_lru_page(page);
put:
put_page(page);
out:
return ret;
}
int mem_cgroup_charge_anon(struct page *page,
struct mm_struct *mm, gfp_t gfp_mask)
{
unsigned int nr_pages = 1;
struct mem_cgroup *memcg;
bool oom = true;
if (mem_cgroup_disabled())
return 0;
VM_BUG_ON_PAGE(page_mapped(page), page);
VM_BUG_ON_PAGE(page->mapping && !PageAnon(page), page);
VM_BUG_ON(!mm);
if (PageTransHuge(page)) {
nr_pages <<= compound_order(page);
VM_BUG_ON_PAGE(!PageTransHuge(page), page);
oom = false;
}
memcg = mem_cgroup_try_charge_mm(mm, gfp_mask, nr_pages, oom);
if (!memcg)
return -ENOMEM;
__mem_cgroup_commit_charge(memcg, page, nr_pages,
MEM_CGROUP_CHARGE_TYPE_ANON, false);
return 0;
}
static int __mem_cgroup_try_charge_swapin(struct mm_struct *mm,
struct page *page,
gfp_t mask,
struct mem_cgroup **memcgp)
{
struct mem_cgroup *memcg = NULL;
struct page_cgroup *pc;
int ret;
pc = lookup_page_cgroup(page);
if (PageCgroupUsed(pc))
goto out;
if (do_swap_account)
memcg = try_get_mem_cgroup_from_page(page);
if (!memcg)
memcg = get_mem_cgroup_from_mm(mm);
ret = mem_cgroup_try_charge(memcg, mask, 1, true);
css_put(&memcg->css);
if (ret == -EINTR)
memcg = root_mem_cgroup;
else if (ret)
return ret;
out:
*memcgp = memcg;
return 0;
}
int mem_cgroup_try_charge_swapin(struct mm_struct *mm, struct page *page,
gfp_t gfp_mask, struct mem_cgroup **memcgp)
{
if (mem_cgroup_disabled()) {
*memcgp = NULL;
return 0;
}
if (!PageSwapCache(page)) {
struct mem_cgroup *memcg;
memcg = mem_cgroup_try_charge_mm(mm, gfp_mask, 1, true);
if (!memcg)
return -ENOMEM;
*memcgp = memcg;
return 0;
}
return __mem_cgroup_try_charge_swapin(mm, page, gfp_mask, memcgp);
}
void mem_cgroup_cancel_charge_swapin(struct mem_cgroup *memcg)
{
if (mem_cgroup_disabled())
return;
if (!memcg)
return;
__mem_cgroup_cancel_charge(memcg, 1);
}
static void
__mem_cgroup_commit_charge_swapin(struct page *page, struct mem_cgroup *memcg,
enum charge_type ctype)
{
if (mem_cgroup_disabled())
return;
if (!memcg)
return;
__mem_cgroup_commit_charge(memcg, page, 1, ctype, true);
if (do_swap_account && PageSwapCache(page)) {
swp_entry_t ent = {.val = page_private(page)};
mem_cgroup_uncharge_swap(ent);
}
}
void mem_cgroup_commit_charge_swapin(struct page *page,
struct mem_cgroup *memcg)
{
__mem_cgroup_commit_charge_swapin(page, memcg,
MEM_CGROUP_CHARGE_TYPE_ANON);
}
int mem_cgroup_charge_file(struct page *page, struct mm_struct *mm,
gfp_t gfp_mask)
{
enum charge_type type = MEM_CGROUP_CHARGE_TYPE_CACHE;
struct mem_cgroup *memcg;
int ret;
if (mem_cgroup_disabled())
return 0;
if (PageCompound(page))
return 0;
if (PageSwapCache(page)) {
ret = __mem_cgroup_try_charge_swapin(mm, page,
gfp_mask, &memcg);
if (ret)
return ret;
__mem_cgroup_commit_charge_swapin(page, memcg, type);
return 0;
}
memcg = mem_cgroup_try_charge_mm(mm, gfp_mask, 1, true);
if (!memcg)
return -ENOMEM;
__mem_cgroup_commit_charge(memcg, page, 1, type, false);
return 0;
}
static void mem_cgroup_do_uncharge(struct mem_cgroup *memcg,
unsigned int nr_pages,
const enum charge_type ctype)
{
struct memcg_batch_info *batch = NULL;
bool uncharge_memsw = true;
if (!do_swap_account || ctype == MEM_CGROUP_CHARGE_TYPE_SWAPOUT)
uncharge_memsw = false;
batch = &current->memcg_batch;
if (!batch->memcg)
batch->memcg = memcg;
if (!batch->do_batch || test_thread_flag(TIF_MEMDIE))
goto direct_uncharge;
if (nr_pages > 1)
goto direct_uncharge;
if (batch->memcg != memcg)
goto direct_uncharge;
batch->nr_pages++;
if (uncharge_memsw)
batch->memsw_nr_pages++;
return;
direct_uncharge:
res_counter_uncharge(&memcg->res, nr_pages * PAGE_SIZE);
if (uncharge_memsw)
res_counter_uncharge(&memcg->memsw, nr_pages * PAGE_SIZE);
if (unlikely(batch->memcg != memcg))
memcg_oom_recover(memcg);
}
static struct mem_cgroup *
__mem_cgroup_uncharge_common(struct page *page, enum charge_type ctype,
bool end_migration)
{
struct mem_cgroup *memcg = NULL;
unsigned int nr_pages = 1;
struct page_cgroup *pc;
bool anon;
if (mem_cgroup_disabled())
return NULL;
if (PageTransHuge(page)) {
nr_pages <<= compound_order(page);
VM_BUG_ON_PAGE(!PageTransHuge(page), page);
}
pc = lookup_page_cgroup(page);
if (unlikely(!PageCgroupUsed(pc)))
return NULL;
lock_page_cgroup(pc);
memcg = pc->mem_cgroup;
if (!PageCgroupUsed(pc))
goto unlock_out;
anon = PageAnon(page);
switch (ctype) {
case MEM_CGROUP_CHARGE_TYPE_ANON:
anon = true;
case MEM_CGROUP_CHARGE_TYPE_DROP:
if (page_mapped(page))
goto unlock_out;
if (!end_migration && PageCgroupMigration(pc))
goto unlock_out;
break;
case MEM_CGROUP_CHARGE_TYPE_SWAPOUT:
if (!PageAnon(page)) {
if (page->mapping && !page_is_file_cache(page))
goto unlock_out;
} else if (page_mapped(page))
goto unlock_out;
break;
default:
break;
}
mem_cgroup_charge_statistics(memcg, page, anon, -nr_pages);
ClearPageCgroupUsed(pc);
unlock_page_cgroup(pc);
memcg_check_events(memcg, page);
if (do_swap_account && ctype == MEM_CGROUP_CHARGE_TYPE_SWAPOUT) {
mem_cgroup_swap_statistics(memcg, true);
css_get(&memcg->css);
}
if (!end_migration && !mem_cgroup_is_root(memcg))
mem_cgroup_do_uncharge(memcg, nr_pages, ctype);
return memcg;
unlock_out:
unlock_page_cgroup(pc);
return NULL;
}
void mem_cgroup_uncharge_page(struct page *page)
{
if (page_mapped(page))
return;
VM_BUG_ON_PAGE(page->mapping && !PageAnon(page), page);
if (PageSwapCache(page))
return;
__mem_cgroup_uncharge_common(page, MEM_CGROUP_CHARGE_TYPE_ANON, false);
}
void mem_cgroup_uncharge_cache_page(struct page *page)
{
VM_BUG_ON_PAGE(page_mapped(page), page);
VM_BUG_ON_PAGE(page->mapping, page);
__mem_cgroup_uncharge_common(page, MEM_CGROUP_CHARGE_TYPE_CACHE, false);
}
void mem_cgroup_uncharge_start(void)
{
current->memcg_batch.do_batch++;
if (current->memcg_batch.do_batch == 1) {
current->memcg_batch.memcg = NULL;
current->memcg_batch.nr_pages = 0;
current->memcg_batch.memsw_nr_pages = 0;
}
}
void mem_cgroup_uncharge_end(void)
{
struct memcg_batch_info *batch = &current->memcg_batch;
if (!batch->do_batch)
return;
batch->do_batch--;
if (batch->do_batch)
return;
if (!batch->memcg)
return;
if (batch->nr_pages)
res_counter_uncharge(&batch->memcg->res,
batch->nr_pages * PAGE_SIZE);
if (batch->memsw_nr_pages)
res_counter_uncharge(&batch->memcg->memsw,
batch->memsw_nr_pages * PAGE_SIZE);
memcg_oom_recover(batch->memcg);
batch->memcg = NULL;
}
void
mem_cgroup_uncharge_swapcache(struct page *page, swp_entry_t ent, bool swapout)
{
struct mem_cgroup *memcg;
int ctype = MEM_CGROUP_CHARGE_TYPE_SWAPOUT;
if (!swapout)
ctype = MEM_CGROUP_CHARGE_TYPE_DROP;
memcg = __mem_cgroup_uncharge_common(page, ctype, false);
if (do_swap_account && swapout && memcg)
swap_cgroup_record(ent, mem_cgroup_id(memcg));
}
void mem_cgroup_uncharge_swap(swp_entry_t ent)
{
struct mem_cgroup *memcg;
unsigned short id;
if (!do_swap_account)
return;
id = swap_cgroup_record(ent, 0);
rcu_read_lock();
memcg = mem_cgroup_lookup(id);
if (memcg) {
if (!mem_cgroup_is_root(memcg))
res_counter_uncharge(&memcg->memsw, PAGE_SIZE);
mem_cgroup_swap_statistics(memcg, false);
css_put(&memcg->css);
}
rcu_read_unlock();
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
css_get(&to->css);
return 0;
}
return -EINVAL;
}
static inline int mem_cgroup_move_swap_account(swp_entry_t entry,
struct mem_cgroup *from, struct mem_cgroup *to)
{
return -EINVAL;
}
void mem_cgroup_prepare_migration(struct page *page, struct page *newpage,
struct mem_cgroup **memcgp)
{
struct mem_cgroup *memcg = NULL;
unsigned int nr_pages = 1;
struct page_cgroup *pc;
enum charge_type ctype;
*memcgp = NULL;
if (mem_cgroup_disabled())
return;
if (PageTransHuge(page))
nr_pages <<= compound_order(page);
pc = lookup_page_cgroup(page);
lock_page_cgroup(pc);
if (PageCgroupUsed(pc)) {
memcg = pc->mem_cgroup;
css_get(&memcg->css);
if (PageAnon(page))
SetPageCgroupMigration(pc);
}
unlock_page_cgroup(pc);
if (!memcg)
return;
*memcgp = memcg;
if (PageAnon(page))
ctype = MEM_CGROUP_CHARGE_TYPE_ANON;
else
ctype = MEM_CGROUP_CHARGE_TYPE_CACHE;
__mem_cgroup_commit_charge(memcg, newpage, nr_pages, ctype, false);
}
void mem_cgroup_end_migration(struct mem_cgroup *memcg,
struct page *oldpage, struct page *newpage, bool migration_ok)
{
struct page *used, *unused;
struct page_cgroup *pc;
bool anon;
if (!memcg)
return;
if (!migration_ok) {
used = oldpage;
unused = newpage;
} else {
used = newpage;
unused = oldpage;
}
anon = PageAnon(used);
__mem_cgroup_uncharge_common(unused,
anon ? MEM_CGROUP_CHARGE_TYPE_ANON
: MEM_CGROUP_CHARGE_TYPE_CACHE,
true);
css_put(&memcg->css);
pc = lookup_page_cgroup(oldpage);
lock_page_cgroup(pc);
ClearPageCgroupMigration(pc);
unlock_page_cgroup(pc);
if (anon)
mem_cgroup_uncharge_page(used);
}
void mem_cgroup_replace_page_cache(struct page *oldpage,
struct page *newpage)
{
struct mem_cgroup *memcg = NULL;
struct page_cgroup *pc;
enum charge_type type = MEM_CGROUP_CHARGE_TYPE_CACHE;
if (mem_cgroup_disabled())
return;
pc = lookup_page_cgroup(oldpage);
lock_page_cgroup(pc);
if (PageCgroupUsed(pc)) {
memcg = pc->mem_cgroup;
mem_cgroup_charge_statistics(memcg, oldpage, false, -1);
ClearPageCgroupUsed(pc);
}
unlock_page_cgroup(pc);
if (!memcg)
return;
__mem_cgroup_commit_charge(memcg, newpage, 1, type, true);
}
static struct page_cgroup *lookup_page_cgroup_used(struct page *page)
{
struct page_cgroup *pc;
pc = lookup_page_cgroup(page);
if (likely(pc) && PageCgroupUsed(pc))
return pc;
return NULL;
}
bool mem_cgroup_bad_page_check(struct page *page)
{
if (mem_cgroup_disabled())
return false;
return lookup_page_cgroup_used(page) != NULL;
}
void mem_cgroup_print_bad_page(struct page *page)
{
struct page_cgroup *pc;
pc = lookup_page_cgroup_used(page);
if (pc) {
pr_alert("pc:%p pc->flags:%lx pc->mem_cgroup:%p\n",
pc, pc->flags, pc->mem_cgroup);
}
}
static int mem_cgroup_resize_limit(struct mem_cgroup *memcg,
unsigned long long val)
{
int retry_count;
u64 memswlimit, memlimit;
int ret = 0;
int children = mem_cgroup_count_children(memcg);
u64 curusage, oldusage;
int enlarge;
retry_count = MEM_CGROUP_RECLAIM_RETRIES * children;
oldusage = res_counter_read_u64(&memcg->res, RES_USAGE);
enlarge = 0;
while (retry_count) {
if (signal_pending(current)) {
ret = -EINTR;
break;
}
mutex_lock(&set_limit_mutex);
memswlimit = res_counter_read_u64(&memcg->memsw, RES_LIMIT);
if (memswlimit < val) {
ret = -EINVAL;
mutex_unlock(&set_limit_mutex);
break;
}
memlimit = res_counter_read_u64(&memcg->res, RES_LIMIT);
if (memlimit < val)
enlarge = 1;
ret = res_counter_set_limit(&memcg->res, val);
if (!ret) {
if (memswlimit == val)
memcg->memsw_is_minimum = true;
else
memcg->memsw_is_minimum = false;
}
mutex_unlock(&set_limit_mutex);
if (!ret)
break;
mem_cgroup_reclaim(memcg, GFP_KERNEL,
MEM_CGROUP_RECLAIM_SHRINK);
curusage = res_counter_read_u64(&memcg->res, RES_USAGE);
if (curusage >= oldusage)
retry_count--;
else
oldusage = curusage;
}
if (!ret && enlarge)
memcg_oom_recover(memcg);
return ret;
}
static int mem_cgroup_resize_memsw_limit(struct mem_cgroup *memcg,
unsigned long long val)
{
int retry_count;
u64 memlimit, memswlimit, oldusage, curusage;
int children = mem_cgroup_count_children(memcg);
int ret = -EBUSY;
int enlarge = 0;
retry_count = children * MEM_CGROUP_RECLAIM_RETRIES;
oldusage = res_counter_read_u64(&memcg->memsw, RES_USAGE);
while (retry_count) {
if (signal_pending(current)) {
ret = -EINTR;
break;
}
mutex_lock(&set_limit_mutex);
memlimit = res_counter_read_u64(&memcg->res, RES_LIMIT);
if (memlimit > val) {
ret = -EINVAL;
mutex_unlock(&set_limit_mutex);
break;
}
memswlimit = res_counter_read_u64(&memcg->memsw, RES_LIMIT);
if (memswlimit < val)
enlarge = 1;
ret = res_counter_set_limit(&memcg->memsw, val);
if (!ret) {
if (memlimit == val)
memcg->memsw_is_minimum = true;
else
memcg->memsw_is_minimum = false;
}
mutex_unlock(&set_limit_mutex);
if (!ret)
break;
mem_cgroup_reclaim(memcg, GFP_KERNEL,
MEM_CGROUP_RECLAIM_NOSWAP |
MEM_CGROUP_RECLAIM_SHRINK);
curusage = res_counter_read_u64(&memcg->memsw, RES_USAGE);
if (curusage >= oldusage)
retry_count--;
else
oldusage = curusage;
}
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
unsigned long long excess;
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
spin_lock(&mctz->lock);
next_mz = NULL;
if (!reclaimed) {
do {
next_mz =
__mem_cgroup_largest_soft_limit_node(mctz);
if (next_mz == mz)
css_put(&next_mz->memcg->css);
else
break;
} while (1);
}
__mem_cgroup_remove_exceeded(mz, mctz);
excess = res_counter_soft_limit_excess(&mz->memcg->res);
__mem_cgroup_insert_exceeded(mz, mctz, excess);
spin_unlock(&mctz->lock);
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
static void mem_cgroup_force_empty_list(struct mem_cgroup *memcg,
int node, int zid, enum lru_list lru)
{
struct lruvec *lruvec;
unsigned long flags;
struct list_head *list;
struct page *busy;
struct zone *zone;
zone = &NODE_DATA(node)->node_zones[zid];
lruvec = mem_cgroup_zone_lruvec(zone, memcg);
list = &lruvec->lists[lru];
busy = NULL;
do {
struct page_cgroup *pc;
struct page *page;
spin_lock_irqsave(&zone->lru_lock, flags);
if (list_empty(list)) {
spin_unlock_irqrestore(&zone->lru_lock, flags);
break;
}
page = list_entry(list->prev, struct page, lru);
if (busy == page) {
list_move(&page->lru, list);
busy = NULL;
spin_unlock_irqrestore(&zone->lru_lock, flags);
continue;
}
spin_unlock_irqrestore(&zone->lru_lock, flags);
pc = lookup_page_cgroup(page);
if (mem_cgroup_move_parent(page, pc, memcg)) {
busy = page;
} else
busy = NULL;
cond_resched();
} while (!list_empty(list));
}
static void mem_cgroup_reparent_charges(struct mem_cgroup *memcg)
{
int node, zid;
u64 usage;
do {
lru_add_drain_all();
drain_all_stock_sync(memcg);
mem_cgroup_start_move(memcg);
for_each_node_state(node, N_MEMORY) {
for (zid = 0; zid < MAX_NR_ZONES; zid++) {
enum lru_list lru;
for_each_lru(lru) {
mem_cgroup_force_empty_list(memcg,
node, zid, lru);
}
}
}
mem_cgroup_end_move(memcg);
memcg_oom_recover(memcg);
cond_resched();
usage = res_counter_read_u64(&memcg->res, RES_USAGE) -
res_counter_read_u64(&memcg->kmem, RES_USAGE);
} while (usage > 0);
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
while (nr_retries && res_counter_read_u64(&memcg->res, RES_USAGE) > 0) {
int progress;
if (signal_pending(current))
return -EINTR;
progress = try_to_free_mem_cgroup_pages(memcg, GFP_KERNEL,
false);
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
static unsigned long mem_cgroup_recursive_stat(struct mem_cgroup *memcg,
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
if (!mem_cgroup_is_root(memcg)) {
if (!swap)
return res_counter_read_u64(&memcg->res, RES_USAGE);
else
return res_counter_read_u64(&memcg->memsw, RES_USAGE);
}
val = mem_cgroup_recursive_stat(memcg, MEM_CGROUP_STAT_CACHE);
val += mem_cgroup_recursive_stat(memcg, MEM_CGROUP_STAT_RSS);
if (swap)
val += mem_cgroup_recursive_stat(memcg, MEM_CGROUP_STAT_SWAP);
return val << PAGE_SHIFT;
}
static u64 mem_cgroup_read_u64(struct cgroup_subsys_state *css,
struct cftype *cft)
{
struct mem_cgroup *memcg = mem_cgroup_from_css(css);
u64 val;
int name;
enum res_type type;
type = MEMFILE_TYPE(cft->private);
name = MEMFILE_ATTR(cft->private);
switch (type) {
case _MEM:
if (name == RES_USAGE)
val = mem_cgroup_usage(memcg, false);
else
val = res_counter_read_u64(&memcg->res, name);
break;
case _MEMSWAP:
if (name == RES_USAGE)
val = mem_cgroup_usage(memcg, true);
else
val = res_counter_read_u64(&memcg->memsw, name);
break;
case _KMEM:
val = res_counter_read_u64(&memcg->kmem, name);
break;
default:
BUG();
}
return val;
}
static int __memcg_activate_kmem(struct mem_cgroup *memcg,
unsigned long long limit)
{
int err = 0;
int memcg_id;
if (memcg_kmem_is_active(memcg))
return 0;
memcg_stop_kmem_account();
mutex_lock(&memcg_create_mutex);
if (cgroup_has_tasks(memcg->css.cgroup) ||
(memcg->use_hierarchy && memcg_has_children(memcg)))
err = -EBUSY;
mutex_unlock(&memcg_create_mutex);
if (err)
goto out;
memcg_id = ida_simple_get(&kmem_limited_groups,
0, MEMCG_CACHES_MAX_SIZE, GFP_KERNEL);
if (memcg_id < 0) {
err = memcg_id;
goto out;
}
mutex_lock(&memcg_slab_mutex);
err = memcg_update_all_caches(memcg_id + 1);
mutex_unlock(&memcg_slab_mutex);
if (err)
goto out_rmid;
memcg->kmemcg_id = memcg_id;
INIT_LIST_HEAD(&memcg->memcg_slab_caches);
err = res_counter_set_limit(&memcg->kmem, limit);
VM_BUG_ON(err);
static_key_slow_inc(&memcg_kmem_enabled_key);
memcg_kmem_set_active(memcg);
out:
memcg_resume_kmem_account();
return err;
out_rmid:
ida_simple_remove(&kmem_limited_groups, memcg_id);
goto out;
}
static int memcg_activate_kmem(struct mem_cgroup *memcg,
unsigned long long limit)
{
int ret;
mutex_lock(&activate_kmem_mutex);
ret = __memcg_activate_kmem(memcg, limit);
mutex_unlock(&activate_kmem_mutex);
return ret;
}
static int memcg_update_kmem_limit(struct mem_cgroup *memcg,
unsigned long long val)
{
int ret;
if (!memcg_kmem_is_active(memcg))
ret = memcg_activate_kmem(memcg, val);
else
ret = res_counter_set_limit(&memcg->kmem, val);
return ret;
}
static int memcg_propagate_kmem(struct mem_cgroup *memcg)
{
int ret = 0;
struct mem_cgroup *parent = parent_mem_cgroup(memcg);
if (!parent)
return 0;
mutex_lock(&activate_kmem_mutex);
if (memcg_kmem_is_active(parent))
ret = __memcg_activate_kmem(memcg, RES_COUNTER_MAX);
mutex_unlock(&activate_kmem_mutex);
return ret;
}
static int memcg_update_kmem_limit(struct mem_cgroup *memcg,
unsigned long long val)
{
return -EINVAL;
}
static ssize_t mem_cgroup_write(struct kernfs_open_file *of,
char *buf, size_t nbytes, loff_t off)
{
struct mem_cgroup *memcg = mem_cgroup_from_css(of_css(of));
enum res_type type;
int name;
unsigned long long val;
int ret;
buf = strstrip(buf);
type = MEMFILE_TYPE(of_cft(of)->private);
name = MEMFILE_ATTR(of_cft(of)->private);
switch (name) {
case RES_LIMIT:
if (mem_cgroup_is_root(memcg)) {
ret = -EINVAL;
break;
}
ret = res_counter_memparse_write_strategy(buf, &val);
if (ret)
break;
if (type == _MEM)
ret = mem_cgroup_resize_limit(memcg, val);
else if (type == _MEMSWAP)
ret = mem_cgroup_resize_memsw_limit(memcg, val);
else if (type == _KMEM)
ret = memcg_update_kmem_limit(memcg, val);
else
return -EINVAL;
break;
case RES_SOFT_LIMIT:
ret = res_counter_memparse_write_strategy(buf, &val);
if (ret)
break;
if (type == _MEM)
ret = res_counter_set_soft_limit(&memcg->res, val);
else
ret = -EINVAL;
break;
default:
ret = -EINVAL;
break;
}
return ret ?: nbytes;
}
static void memcg_get_hierarchical_limit(struct mem_cgroup *memcg,
unsigned long long *mem_limit, unsigned long long *memsw_limit)
{
unsigned long long min_limit, min_memsw_limit, tmp;
min_limit = res_counter_read_u64(&memcg->res, RES_LIMIT);
min_memsw_limit = res_counter_read_u64(&memcg->memsw, RES_LIMIT);
if (!memcg->use_hierarchy)
goto out;
while (memcg->css.parent) {
memcg = mem_cgroup_from_css(memcg->css.parent);
if (!memcg->use_hierarchy)
break;
tmp = res_counter_read_u64(&memcg->res, RES_LIMIT);
min_limit = min(min_limit, tmp);
tmp = res_counter_read_u64(&memcg->memsw, RES_LIMIT);
min_memsw_limit = min(min_memsw_limit, tmp);
}
out:
*mem_limit = min_limit;
*memsw_limit = min_memsw_limit;
}
static ssize_t mem_cgroup_reset(struct kernfs_open_file *of, char *buf,
size_t nbytes, loff_t off)
{
struct mem_cgroup *memcg = mem_cgroup_from_css(of_css(of));
int name;
enum res_type type;
type = MEMFILE_TYPE(of_cft(of)->private);
name = MEMFILE_ATTR(of_cft(of)->private);
switch (name) {
case RES_MAX_USAGE:
if (type == _MEM)
res_counter_reset_max(&memcg->res);
else if (type == _MEMSWAP)
res_counter_reset_max(&memcg->memsw);
else if (type == _KMEM)
res_counter_reset_max(&memcg->kmem);
else
return -EINVAL;
break;
case RES_FAILCNT:
if (type == _MEM)
res_counter_reset_failcnt(&memcg->res);
else if (type == _MEMSWAP)
res_counter_reset_failcnt(&memcg->memsw);
else if (type == _KMEM)
res_counter_reset_failcnt(&memcg->kmem);
else
return -EINVAL;
break;
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
if (val >= (1 << NR_MOVE_TYPE))
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
static inline void mem_cgroup_lru_names_not_uptodate(void)
{
BUILD_BUG_ON(ARRAY_SIZE(mem_cgroup_lru_names) != NR_LRU_LISTS);
}
static int memcg_stat_show(struct seq_file *m, void *v)
{
struct mem_cgroup *memcg = mem_cgroup_from_css(seq_css(m));
struct mem_cgroup *mi;
unsigned int i;
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
{
unsigned long long limit, memsw_limit;
memcg_get_hierarchical_limit(memcg, &limit, &memsw_limit);
seq_printf(m, "hierarchical_memory_limit %llu\n", limit);
if (do_swap_account)
seq_printf(m, "hierarchical_memsw_limit %llu\n",
memsw_limit);
}
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
u64 usage;
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
u64 threshold, usage;
int i, size, ret;
ret = res_counter_memparse_write_strategy(args, &threshold);
if (ret)
return ret;
mutex_lock(&memcg->thresholds_lock);
if (type == _MEM)
thresholds = &memcg->thresholds;
else if (type == _MEMSWAP)
thresholds = &memcg->memsw_thresholds;
else
BUG();
usage = mem_cgroup_usage(memcg, type == _MEMSWAP);
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
u64 usage;
int i, j, size;
mutex_lock(&memcg->thresholds_lock);
if (type == _MEM)
thresholds = &memcg->thresholds;
else if (type == _MEMSWAP)
thresholds = &memcg->memsw_thresholds;
else
BUG();
if (!thresholds->primary)
goto unlock;
usage = mem_cgroup_usage(memcg, type == _MEMSWAP);
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
memcg->kmemcg_id = -1;
ret = memcg_propagate_kmem(memcg);
if (ret)
return ret;
return mem_cgroup_sockets_init(memcg, ss);
}
static void memcg_destroy_kmem(struct mem_cgroup *memcg)
{
mem_cgroup_sockets_destroy(memcg);
}
static void kmem_cgroup_css_offline(struct mem_cgroup *memcg)
{
if (!memcg_kmem_is_active(memcg))
return;
css_get(&memcg->css);
memcg_kmem_mark_dead(memcg);
if (res_counter_read_u64(&memcg->kmem, RES_USAGE) != 0)
return;
if (memcg_kmem_test_and_clear_dead(memcg))
css_put(&memcg->css);
}
static int memcg_init_kmem(struct mem_cgroup *memcg, struct cgroup_subsys *ss)
{
return 0;
}
static void memcg_destroy_kmem(struct mem_cgroup *memcg)
{
}
static void kmem_cgroup_css_offline(struct mem_cgroup *memcg)
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
name = cfile.file->f_dentry->d_name.name;
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
cfile_css = css_tryget_online_from_dir(cfile.file->f_dentry->d_parent,
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
disarm_static_keys(memcg);
kfree(memcg);
}
struct mem_cgroup *parent_mem_cgroup(struct mem_cgroup *memcg)
{
if (!memcg->res.parent)
return NULL;
return mem_cgroup_from_res_counter(memcg->res.parent, res);
}
static void __init mem_cgroup_soft_limit_tree_init(void)
{
struct mem_cgroup_tree_per_node *rtpn;
struct mem_cgroup_tree_per_zone *rtpz;
int tmp, node, zone;
for_each_node(node) {
tmp = node;
if (!node_state(node, N_NORMAL_MEMORY))
tmp = -1;
rtpn = kzalloc_node(sizeof(*rtpn), GFP_KERNEL, tmp);
BUG_ON(!rtpn);
soft_limit_tree.rb_tree_per_node[node] = rtpn;
for (zone = 0; zone < MAX_NR_ZONES; zone++) {
rtpz = &rtpn->rb_tree_per_zone[zone];
rtpz->rb_root = RB_ROOT;
spin_lock_init(&rtpz->lock);
}
}
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
res_counter_init(&memcg->res, NULL);
res_counter_init(&memcg->memsw, NULL);
res_counter_init(&memcg->kmem, NULL);
}
memcg->last_scanned_node = MAX_NUMNODES;
INIT_LIST_HEAD(&memcg->oom_notify);
memcg->move_charge_at_immigrate = 0;
mutex_init(&memcg->thresholds_lock);
spin_lock_init(&memcg->move_lock);
vmpressure_init(&memcg->vmpressure);
INIT_LIST_HEAD(&memcg->event_list);
spin_lock_init(&memcg->event_list_lock);
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
if (css->id > MEM_CGROUP_ID_MAX)
return -ENOSPC;
if (!parent)
return 0;
mutex_lock(&memcg_create_mutex);
memcg->use_hierarchy = parent->use_hierarchy;
memcg->oom_kill_disable = parent->oom_kill_disable;
memcg->swappiness = mem_cgroup_swappiness(parent);
if (parent->use_hierarchy) {
res_counter_init(&memcg->res, &parent->res);
res_counter_init(&memcg->memsw, &parent->memsw);
res_counter_init(&memcg->kmem, &parent->kmem);
} else {
res_counter_init(&memcg->res, NULL);
res_counter_init(&memcg->memsw, NULL);
res_counter_init(&memcg->kmem, NULL);
if (parent != root_mem_cgroup)
memory_cgrp_subsys.broken_hierarchy = true;
}
mutex_unlock(&memcg_create_mutex);
return memcg_init_kmem(memcg, &memory_cgrp_subsys);
}
static void mem_cgroup_invalidate_reclaim_iterators(struct mem_cgroup *memcg)
{
struct mem_cgroup *parent = memcg;
while ((parent = parent_mem_cgroup(parent)))
mem_cgroup_iter_invalidate(parent);
if (!root_mem_cgroup->use_hierarchy)
mem_cgroup_iter_invalidate(root_mem_cgroup);
}
static void mem_cgroup_css_offline(struct cgroup_subsys_state *css)
{
struct mem_cgroup *memcg = mem_cgroup_from_css(css);
struct mem_cgroup_event *event, *tmp;
struct cgroup_subsys_state *iter;
spin_lock(&memcg->event_list_lock);
list_for_each_entry_safe(event, tmp, &memcg->event_list, list) {
list_del_init(&event->list);
schedule_work(&event->remove);
}
spin_unlock(&memcg->event_list_lock);
kmem_cgroup_css_offline(memcg);
mem_cgroup_invalidate_reclaim_iterators(memcg);
css_for_each_descendant_post(iter, css)
mem_cgroup_reparent_charges(mem_cgroup_from_css(iter));
memcg_unregister_all_caches(memcg);
vmpressure_cleanup(&memcg->vmpressure);
}
static void mem_cgroup_css_free(struct cgroup_subsys_state *css)
{
struct mem_cgroup *memcg = mem_cgroup_from_css(css);
mem_cgroup_reparent_charges(memcg);
memcg_destroy_kmem(memcg);
__mem_cgroup_free(memcg);
}
static int mem_cgroup_do_precharge(unsigned long count)
{
int ret = 0;
int batch_count = PRECHARGE_COUNT_AT_ONCE;
struct mem_cgroup *memcg = mc.to;
if (mem_cgroup_is_root(memcg)) {
mc.precharge += count;
return ret;
}
if (count > 1) {
struct res_counter *dummy;
if (res_counter_charge(&memcg->res, PAGE_SIZE * count, &dummy))
goto one_by_one;
if (do_swap_account && res_counter_charge(&memcg->memsw,
PAGE_SIZE * count, &dummy)) {
res_counter_uncharge(&memcg->res, PAGE_SIZE * count);
goto one_by_one;
}
mc.precharge += count;
return ret;
}
one_by_one:
while (count--) {
if (signal_pending(current)) {
ret = -EINTR;
break;
}
if (!batch_count--) {
batch_count = PRECHARGE_COUNT_AT_ONCE;
cond_resched();
}
ret = mem_cgroup_try_charge(memcg, GFP_KERNEL, 1, false);
if (ret)
return ret;
mc.precharge++;
}
return ret;
}
static struct page *mc_handle_present_pte(struct vm_area_struct *vma,
unsigned long addr, pte_t ptent)
{
struct page *page = vm_normal_page(vma, addr, ptent);
if (!page || !page_mapped(page))
return NULL;
if (PageAnon(page)) {
if (!move_anon())
return NULL;
} else if (!move_file())
return NULL;
if (!get_page_unless_zero(page))
return NULL;
return page;
}
static struct page *mc_handle_swap_pte(struct vm_area_struct *vma,
unsigned long addr, pte_t ptent, swp_entry_t *entry)
{
struct page *page = NULL;
swp_entry_t ent = pte_to_swp_entry(ptent);
if (!move_anon() || non_swap_entry(ent))
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
if (!move_file())
return NULL;
mapping = vma->vm_file->f_mapping;
if (pte_none(ptent))
pgoff = linear_page_index(vma, addr);
else
pgoff = pte_to_pgoff(ptent);
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
static enum mc_target_type get_mctgt_type(struct vm_area_struct *vma,
unsigned long addr, pte_t ptent, union mc_target *target)
{
struct page *page = NULL;
struct page_cgroup *pc;
enum mc_target_type ret = MC_TARGET_NONE;
swp_entry_t ent = { .val = 0 };
if (pte_present(ptent))
page = mc_handle_present_pte(vma, addr, ptent);
else if (is_swap_pte(ptent))
page = mc_handle_swap_pte(vma, addr, ptent, &ent);
else if (pte_none(ptent) || pte_file(ptent))
page = mc_handle_file_pte(vma, addr, ptent, &ent);
if (!page && !ent.val)
return ret;
if (page) {
pc = lookup_page_cgroup(page);
if (PageCgroupUsed(pc) && pc->mem_cgroup == mc.from) {
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
struct page_cgroup *pc;
enum mc_target_type ret = MC_TARGET_NONE;
page = pmd_page(pmd);
VM_BUG_ON_PAGE(!page || !PageHead(page), page);
if (!move_anon())
return ret;
pc = lookup_page_cgroup(page);
if (PageCgroupUsed(pc) && pc->mem_cgroup == mc.from) {
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
struct vm_area_struct *vma = walk->private;
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
struct vm_area_struct *vma;
down_read(&mm->mmap_sem);
for (vma = mm->mmap; vma; vma = vma->vm_next) {
struct mm_walk mem_cgroup_count_precharge_walk = {
.pmd_entry = mem_cgroup_count_precharge_pte_range,
.mm = mm,
.private = vma,
};
if (is_vm_hugetlb_page(vma))
continue;
walk_page_range(vma->vm_start, vma->vm_end,
&mem_cgroup_count_precharge_walk);
}
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
int i;
if (mc.precharge) {
__mem_cgroup_cancel_charge(mc.to, mc.precharge);
mc.precharge = 0;
}
if (mc.moved_charge) {
__mem_cgroup_cancel_charge(mc.from, mc.moved_charge);
mc.moved_charge = 0;
}
if (mc.moved_swap) {
if (!mem_cgroup_is_root(mc.from))
res_counter_uncharge(&mc.from->memsw,
PAGE_SIZE * mc.moved_swap);
for (i = 0; i < mc.moved_swap; i++)
css_put(&mc.from->css);
if (!mem_cgroup_is_root(mc.to)) {
res_counter_uncharge(&mc.to->res,
PAGE_SIZE * mc.moved_swap);
}
mc.moved_swap = 0;
}
memcg_oom_recover(from);
memcg_oom_recover(to);
wake_up_all(&mc.waitq);
}
static void mem_cgroup_clear_mc(void)
{
struct mem_cgroup *from = mc.from;
mc.moving_task = NULL;
__mem_cgroup_clear_mc();
spin_lock(&mc.lock);
mc.from = NULL;
mc.to = NULL;
spin_unlock(&mc.lock);
mem_cgroup_end_move(from);
}
static int mem_cgroup_can_attach(struct cgroup_subsys_state *css,
struct cgroup_taskset *tset)
{
struct task_struct *p = cgroup_taskset_first(tset);
int ret = 0;
struct mem_cgroup *memcg = mem_cgroup_from_css(css);
unsigned long move_charge_at_immigrate;
move_charge_at_immigrate = memcg->move_charge_at_immigrate;
if (move_charge_at_immigrate) {
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
mem_cgroup_start_move(from);
spin_lock(&mc.lock);
mc.from = from;
mc.to = memcg;
mc.immigrate_flags = move_charge_at_immigrate;
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
mem_cgroup_clear_mc();
}
static int mem_cgroup_move_charge_pte_range(pmd_t *pmd,
unsigned long addr, unsigned long end,
struct mm_walk *walk)
{
int ret = 0;
struct vm_area_struct *vma = walk->private;
pte_t *pte;
spinlock_t *ptl;
enum mc_target_type target_type;
union mc_target target;
struct page *page;
struct page_cgroup *pc;
if (pmd_trans_huge_lock(pmd, vma, &ptl) == 1) {
if (mc.precharge < HPAGE_PMD_NR) {
spin_unlock(ptl);
return 0;
}
target_type = get_mctgt_type_thp(vma, addr, *pmd, &target);
if (target_type == MC_TARGET_PAGE) {
page = target.page;
if (!isolate_lru_page(page)) {
pc = lookup_page_cgroup(page);
if (!mem_cgroup_move_account(page, HPAGE_PMD_NR,
pc, mc.from, mc.to)) {
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
pc = lookup_page_cgroup(page);
if (!mem_cgroup_move_account(page, 1, pc,
mc.from, mc.to)) {
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
struct vm_area_struct *vma;
lru_add_drain_all();
retry:
if (unlikely(!down_read_trylock(&mm->mmap_sem))) {
__mem_cgroup_clear_mc();
cond_resched();
goto retry;
}
for (vma = mm->mmap; vma; vma = vma->vm_next) {
int ret;
struct mm_walk mem_cgroup_move_charge_walk = {
.pmd_entry = mem_cgroup_move_charge_pte_range,
.mm = mm,
.private = vma,
};
if (is_vm_hugetlb_page(vma))
continue;
ret = walk_page_range(vma->vm_start, vma->vm_end,
&mem_cgroup_move_charge_walk);
if (ret)
break;
}
up_read(&mm->mmap_sem);
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
if (cgroup_sane_behavior(root_css->cgroup))
mem_cgroup_from_css(root_css)->use_hierarchy = true;
}
static int __init enable_swap_account(char *s)
{
if (!strcmp(s, "1"))
really_do_swap_account = 1;
else if (!strcmp(s, "0"))
really_do_swap_account = 0;
return 1;
}
static void __init memsw_file_init(void)
{
WARN_ON(cgroup_add_cftypes(&memory_cgrp_subsys, memsw_cgroup_files));
}
static void __init enable_swap_cgroup(void)
{
if (!mem_cgroup_disabled() && really_do_swap_account) {
do_swap_account = 1;
memsw_file_init();
}
}
static void __init enable_swap_cgroup(void)
{
}
static int __init mem_cgroup_init(void)
{
hotcpu_notifier(memcg_cpu_hotplug_callback, 0);
enable_swap_cgroup();
mem_cgroup_soft_limit_tree_init();
memcg_stock_init();
return 0;
}
