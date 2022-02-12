static bool do_memsw_account(void)
{
return !cgroup_subsys_on_dfl(memory_cgrp_subsys) && do_swap_account;
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
void memcg_get_cache_ids(void)
{
down_read(&memcg_cache_ids_sem);
}
void memcg_put_cache_ids(void)
{
up_read(&memcg_cache_ids_sem);
}
struct cgroup_subsys_state *mem_cgroup_css_from_page(struct page *page)
{
struct mem_cgroup *memcg;
memcg = page->mem_cgroup;
if (!memcg || !cgroup_subsys_on_dfl(memory_cgrp_subsys))
memcg = root_mem_cgroup;
return &memcg->css;
}
ino_t page_cgroup_ino(struct page *page)
{
struct mem_cgroup *memcg;
unsigned long ino = 0;
rcu_read_lock();
memcg = READ_ONCE(page->mem_cgroup);
while (memcg && !(memcg->css.flags & CSS_ONLINE))
memcg = parent_mem_cgroup(memcg);
if (memcg)
ino = cgroup_ino(memcg->css.cgroup);
rcu_read_unlock();
return ino;
}
static struct mem_cgroup_per_node *
mem_cgroup_page_nodeinfo(struct mem_cgroup *memcg, struct page *page)
{
int nid = page_to_nid(page);
return memcg->nodeinfo[nid];
}
static struct mem_cgroup_tree_per_node *
soft_limit_tree_node(int nid)
{
return soft_limit_tree.rb_tree_per_node[nid];
}
static struct mem_cgroup_tree_per_node *
soft_limit_tree_from_page(struct page *page)
{
int nid = page_to_nid(page);
return soft_limit_tree.rb_tree_per_node[nid];
}
static void __mem_cgroup_insert_exceeded(struct mem_cgroup_per_node *mz,
struct mem_cgroup_tree_per_node *mctz,
unsigned long new_usage_in_excess)
{
struct rb_node **p = &mctz->rb_root.rb_node;
struct rb_node *parent = NULL;
struct mem_cgroup_per_node *mz_node;
if (mz->on_tree)
return;
mz->usage_in_excess = new_usage_in_excess;
if (!mz->usage_in_excess)
return;
while (*p) {
parent = *p;
mz_node = rb_entry(parent, struct mem_cgroup_per_node,
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
static void __mem_cgroup_remove_exceeded(struct mem_cgroup_per_node *mz,
struct mem_cgroup_tree_per_node *mctz)
{
if (!mz->on_tree)
return;
rb_erase(&mz->tree_node, &mctz->rb_root);
mz->on_tree = false;
}
static void mem_cgroup_remove_exceeded(struct mem_cgroup_per_node *mz,
struct mem_cgroup_tree_per_node *mctz)
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
struct mem_cgroup_per_node *mz;
struct mem_cgroup_tree_per_node *mctz;
mctz = soft_limit_tree_from_page(page);
for (; memcg; memcg = parent_mem_cgroup(memcg)) {
mz = mem_cgroup_page_nodeinfo(memcg, page);
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
struct mem_cgroup_tree_per_node *mctz;
struct mem_cgroup_per_node *mz;
int nid;
for_each_node(nid) {
mz = mem_cgroup_nodeinfo(memcg, nid);
mctz = soft_limit_tree_node(nid);
mem_cgroup_remove_exceeded(mz, mctz);
}
}
static struct mem_cgroup_per_node *
__mem_cgroup_largest_soft_limit_node(struct mem_cgroup_tree_per_node *mctz)
{
struct rb_node *rightmost = NULL;
struct mem_cgroup_per_node *mz;
retry:
mz = NULL;
rightmost = rb_last(&mctz->rb_root);
if (!rightmost)
goto done;
mz = rb_entry(rightmost, struct mem_cgroup_per_node, tree_node);
__mem_cgroup_remove_exceeded(mz, mctz);
if (!soft_limit_excess(mz->memcg) ||
!css_tryget_online(&mz->memcg->css))
goto retry;
done:
return mz;
}
static struct mem_cgroup_per_node *
mem_cgroup_largest_soft_limit_node(struct mem_cgroup_tree_per_node *mctz)
{
struct mem_cgroup_per_node *mz;
spin_lock_irq(&mctz->lock);
mz = __mem_cgroup_largest_soft_limit_node(mctz);
spin_unlock_irq(&mctz->lock);
return mz;
}
static unsigned long
mem_cgroup_read_stat(struct mem_cgroup *memcg, enum mem_cgroup_stat_index idx)
{
long val = 0;
int cpu;
for_each_possible_cpu(cpu)
val += per_cpu(memcg->stat->count[idx], cpu);
if (val < 0)
val = 0;
return val;
}
static unsigned long mem_cgroup_read_events(struct mem_cgroup *memcg,
enum mem_cgroup_events_index idx)
{
unsigned long val = 0;
int cpu;
for_each_possible_cpu(cpu)
val += per_cpu(memcg->stat->events[idx], cpu);
return val;
}
static void mem_cgroup_charge_statistics(struct mem_cgroup *memcg,
struct page *page,
bool compound, int nr_pages)
{
if (PageAnon(page))
__this_cpu_add(memcg->stat->count[MEM_CGROUP_STAT_RSS],
nr_pages);
else
__this_cpu_add(memcg->stat->count[MEM_CGROUP_STAT_CACHE],
nr_pages);
if (compound) {
VM_BUG_ON_PAGE(!PageTransHuge(page), page);
__this_cpu_add(memcg->stat->count[MEM_CGROUP_STAT_RSS_HUGE],
nr_pages);
}
if (nr_pages > 0)
__this_cpu_inc(memcg->stat->events[MEM_CGROUP_EVENTS_PGPGIN]);
else {
__this_cpu_inc(memcg->stat->events[MEM_CGROUP_EVENTS_PGPGOUT]);
nr_pages = -nr_pages;
}
__this_cpu_add(memcg->stat->nr_page_events, nr_pages);
}
unsigned long mem_cgroup_node_nr_lru_pages(struct mem_cgroup *memcg,
int nid, unsigned int lru_mask)
{
unsigned long nr = 0;
struct mem_cgroup_per_node *mz;
enum lru_list lru;
VM_BUG_ON((unsigned)nid >= nr_node_ids);
for_each_lru(lru) {
if (!(BIT(lru) & lru_mask))
continue;
mz = mem_cgroup_nodeinfo(memcg, nid);
nr += mz->lru_size[lru];
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
struct mem_cgroup_reclaim_iter *uninitialized_var(iter);
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
struct mem_cgroup_per_node *mz;
mz = mem_cgroup_nodeinfo(root, reclaim->pgdat->node_id);
iter = &mz->iter[reclaim->priority];
if (prev && reclaim->generation != iter->generation)
goto out_unlock;
while (1) {
pos = READ_ONCE(iter->position);
if (!pos || css_tryget(&pos->css))
break;
(void)cmpxchg(&iter->position, pos, NULL);
}
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
if (css_tryget(css))
break;
memcg = NULL;
}
if (reclaim) {
(void)cmpxchg(&iter->position, pos, memcg);
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
static void invalidate_reclaim_iterators(struct mem_cgroup *dead_memcg)
{
struct mem_cgroup *memcg = dead_memcg;
struct mem_cgroup_reclaim_iter *iter;
struct mem_cgroup_per_node *mz;
int nid;
int i;
while ((memcg = parent_mem_cgroup(memcg))) {
for_each_node(nid) {
mz = mem_cgroup_nodeinfo(memcg, nid);
for (i = 0; i <= DEF_PRIORITY; i++) {
iter = &mz->iter[i];
cmpxchg(&iter->position,
dead_memcg, NULL);
}
}
}
}
int mem_cgroup_scan_tasks(struct mem_cgroup *memcg,
int (*fn)(struct task_struct *, void *), void *arg)
{
struct mem_cgroup *iter;
int ret = 0;
BUG_ON(memcg == root_mem_cgroup);
for_each_mem_cgroup_tree(iter, memcg) {
struct css_task_iter it;
struct task_struct *task;
css_task_iter_start(&iter->css, &it);
while (!ret && (task = css_task_iter_next(&it)))
ret = fn(task, arg);
css_task_iter_end(&it);
if (ret) {
mem_cgroup_iter_break(memcg, iter);
break;
}
}
return ret;
}
struct lruvec *mem_cgroup_page_lruvec(struct page *page, struct pglist_data *pgdat)
{
struct mem_cgroup_per_node *mz;
struct mem_cgroup *memcg;
struct lruvec *lruvec;
if (mem_cgroup_disabled()) {
lruvec = &pgdat->lruvec;
goto out;
}
memcg = page->mem_cgroup;
if (!memcg)
memcg = root_mem_cgroup;
mz = mem_cgroup_page_nodeinfo(memcg, page);
lruvec = &mz->lruvec;
out:
if (unlikely(lruvec->pgdat != pgdat))
lruvec->pgdat = pgdat;
return lruvec;
}
void mem_cgroup_update_lru_size(struct lruvec *lruvec, enum lru_list lru,
int nr_pages)
{
struct mem_cgroup_per_node *mz;
unsigned long *lru_size;
long size;
bool empty;
if (mem_cgroup_disabled())
return;
mz = container_of(lruvec, struct mem_cgroup_per_node, lruvec);
lru_size = mz->lru_size + lru;
empty = list_empty(lruvec->lists + lru);
if (nr_pages < 0)
*lru_size += nr_pages;
size = *lru_size;
if (WARN_ONCE(size < 0 || empty != !size,
"%s(%p, %d, %d): lru_size %ld but %sempty\n",
__func__, lruvec, lru, nr_pages, size, empty ? "" : "not ")) {
VM_BUG_ON(1);
*lru_size = 0;
}
if (nr_pages > 0)
*lru_size += nr_pages;
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
static unsigned long mem_cgroup_margin(struct mem_cgroup *memcg)
{
unsigned long margin = 0;
unsigned long count;
unsigned long limit;
count = page_counter_read(&memcg->memory);
limit = READ_ONCE(memcg->memory.limit);
if (count < limit)
margin = limit - count;
if (do_memsw_account()) {
count = page_counter_read(&memcg->memsw);
limit = READ_ONCE(memcg->memsw.limit);
if (count <= limit)
margin = min(margin, limit - count);
else
margin = 0;
}
return margin;
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
struct mem_cgroup *iter;
unsigned int i;
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
pr_cont(" %s:%luKB", mem_cgroup_stat_names[i],
K(mem_cgroup_read_stat(iter, i)));
}
for (i = 0; i < NR_LRU_LISTS; i++)
pr_cont(" %s:%luKB", mem_cgroup_lru_names[i],
K(mem_cgroup_nr_lru_pages(iter, BIT(i))));
pr_cont("\n");
}
}
static int mem_cgroup_count_children(struct mem_cgroup *memcg)
{
int num = 0;
struct mem_cgroup *iter;
for_each_mem_cgroup_tree(iter, memcg)
num++;
return num;
}
unsigned long mem_cgroup_get_limit(struct mem_cgroup *memcg)
{
unsigned long limit;
limit = memcg->memory.limit;
if (mem_cgroup_swappiness(memcg)) {
unsigned long memsw_limit;
unsigned long swap_limit;
memsw_limit = memcg->memsw.limit;
swap_limit = memcg->swap.limit;
swap_limit = min(swap_limit, (unsigned long)total_swap_pages);
limit = min(limit + swap_limit, memsw_limit);
}
return limit;
}
static bool mem_cgroup_out_of_memory(struct mem_cgroup *memcg, gfp_t gfp_mask,
int order)
{
struct oom_control oc = {
.zonelist = NULL,
.nodemask = NULL,
.memcg = memcg,
.gfp_mask = gfp_mask,
.order = order,
};
bool ret;
mutex_lock(&oom_lock);
ret = out_of_memory(&oc);
mutex_unlock(&oom_lock);
return ret;
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
node = next_node_in(node, memcg->scan_nodes);
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
pg_data_t *pgdat,
gfp_t gfp_mask,
unsigned long *total_scanned)
{
struct mem_cgroup *victim = NULL;
int total = 0;
int loop = 0;
unsigned long excess;
unsigned long nr_scanned;
struct mem_cgroup_reclaim_cookie reclaim = {
.pgdat = pgdat,
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
total += mem_cgroup_shrink_node(victim, gfp_mask, false,
pgdat, &nr_scanned);
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
spin_lock(&memcg_oom_lock);
for_each_mem_cgroup_tree(iter, memcg)
iter->under_oom++;
spin_unlock(&memcg_oom_lock);
}
static void mem_cgroup_unmark_under_oom(struct mem_cgroup *memcg)
{
struct mem_cgroup *iter;
spin_lock(&memcg_oom_lock);
for_each_mem_cgroup_tree(iter, memcg)
if (iter->under_oom > 0)
iter->under_oom--;
spin_unlock(&memcg_oom_lock);
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
static void memcg_oom_recover(struct mem_cgroup *memcg)
{
if (memcg && memcg->under_oom)
__wake_up(&memcg_oom_waitq, TASK_NORMAL, 0, memcg);
}
static void mem_cgroup_oom(struct mem_cgroup *memcg, gfp_t mask, int order)
{
if (!current->memcg_may_oom)
return;
css_get(&memcg->css);
current->memcg_in_oom = memcg;
current->memcg_oom_gfp_mask = mask;
current->memcg_oom_order = order;
}
bool mem_cgroup_oom_synchronize(bool handle)
{
struct mem_cgroup *memcg = current->memcg_in_oom;
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
mem_cgroup_out_of_memory(memcg, current->memcg_oom_gfp_mask,
current->memcg_oom_order);
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
current->memcg_in_oom = NULL;
css_put(&memcg->css);
return true;
}
void lock_page_memcg(struct page *page)
{
struct mem_cgroup *memcg;
unsigned long flags;
rcu_read_lock();
if (mem_cgroup_disabled())
return;
again:
memcg = page->mem_cgroup;
if (unlikely(!memcg))
return;
if (atomic_read(&memcg->moving_account) <= 0)
return;
spin_lock_irqsave(&memcg->move_lock, flags);
if (memcg != page->mem_cgroup) {
spin_unlock_irqrestore(&memcg->move_lock, flags);
goto again;
}
memcg->move_lock_task = current;
memcg->move_lock_flags = flags;
return;
}
void unlock_page_memcg(struct page *page)
{
struct mem_cgroup *memcg = page->mem_cgroup;
if (memcg && memcg->move_lock_task == current) {
unsigned long flags = memcg->move_lock_flags;
memcg->move_lock_task = NULL;
memcg->move_lock_flags = 0;
spin_unlock_irqrestore(&memcg->move_lock, flags);
}
rcu_read_unlock();
}
static bool consume_stock(struct mem_cgroup *memcg, unsigned int nr_pages)
{
struct memcg_stock_pcp *stock;
unsigned long flags;
bool ret = false;
if (nr_pages > CHARGE_BATCH)
return ret;
local_irq_save(flags);
stock = this_cpu_ptr(&memcg_stock);
if (memcg == stock->cached && stock->nr_pages >= nr_pages) {
stock->nr_pages -= nr_pages;
ret = true;
}
local_irq_restore(flags);
return ret;
}
static void drain_stock(struct memcg_stock_pcp *stock)
{
struct mem_cgroup *old = stock->cached;
if (stock->nr_pages) {
page_counter_uncharge(&old->memory, stock->nr_pages);
if (do_memsw_account())
page_counter_uncharge(&old->memsw, stock->nr_pages);
css_put_many(&old->css, stock->nr_pages);
stock->nr_pages = 0;
}
stock->cached = NULL;
}
static void drain_local_stock(struct work_struct *dummy)
{
struct memcg_stock_pcp *stock;
unsigned long flags;
local_irq_save(flags);
stock = this_cpu_ptr(&memcg_stock);
drain_stock(stock);
clear_bit(FLUSHING_CACHED_CHARGE, &stock->flags);
local_irq_restore(flags);
}
static void refill_stock(struct mem_cgroup *memcg, unsigned int nr_pages)
{
struct memcg_stock_pcp *stock;
unsigned long flags;
local_irq_save(flags);
stock = this_cpu_ptr(&memcg_stock);
if (stock->cached != memcg) {
drain_stock(stock);
stock->cached = memcg;
}
stock->nr_pages += nr_pages;
local_irq_restore(flags);
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
static int memcg_cpu_hotplug_callback(struct notifier_block *nb,
unsigned long action,
void *hcpu)
{
int cpu = (unsigned long)hcpu;
struct memcg_stock_pcp *stock;
if (action == CPU_ONLINE)
return NOTIFY_OK;
if (action != CPU_DEAD && action != CPU_DEAD_FROZEN)
return NOTIFY_OK;
stock = &per_cpu(memcg_stock, cpu);
drain_stock(stock);
return NOTIFY_OK;
}
static void reclaim_high(struct mem_cgroup *memcg,
unsigned int nr_pages,
gfp_t gfp_mask)
{
do {
if (page_counter_read(&memcg->memory) <= memcg->high)
continue;
mem_cgroup_events(memcg, MEMCG_HIGH, 1);
try_to_free_mem_cgroup_pages(memcg, nr_pages, gfp_mask, true);
} while ((memcg = parent_mem_cgroup(memcg)));
}
static void high_work_func(struct work_struct *work)
{
struct mem_cgroup *memcg;
memcg = container_of(work, struct mem_cgroup, high_work);
reclaim_high(memcg, CHARGE_BATCH, GFP_KERNEL);
}
void mem_cgroup_handle_over_high(void)
{
unsigned int nr_pages = current->memcg_nr_pages_over_high;
struct mem_cgroup *memcg;
if (likely(!nr_pages))
return;
memcg = get_mem_cgroup_from_mm(current->mm);
reclaim_high(memcg, nr_pages, GFP_KERNEL);
css_put(&memcg->css);
current->memcg_nr_pages_over_high = 0;
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
if (mem_cgroup_is_root(memcg))
return 0;
retry:
if (consume_stock(memcg, nr_pages))
return 0;
if (!do_memsw_account() ||
page_counter_try_charge(&memcg->memsw, batch, &counter)) {
if (page_counter_try_charge(&memcg->memory, batch, &counter))
goto done_restock;
if (do_memsw_account())
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
goto force;
if (unlikely(current->flags & PF_MEMALLOC))
goto force;
if (unlikely(task_in_memcg_oom(current)))
goto nomem;
if (!gfpflags_allow_blocking(gfp_mask))
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
goto force;
if (fatal_signal_pending(current))
goto force;
mem_cgroup_events(mem_over_limit, MEMCG_OOM, 1);
mem_cgroup_oom(mem_over_limit, gfp_mask,
get_order(nr_pages * PAGE_SIZE));
nomem:
if (!(gfp_mask & __GFP_NOFAIL))
return -ENOMEM;
force:
page_counter_charge(&memcg->memory, nr_pages);
if (do_memsw_account())
page_counter_charge(&memcg->memsw, nr_pages);
css_get_many(&memcg->css, nr_pages);
return 0;
done_restock:
css_get_many(&memcg->css, batch);
if (batch > nr_pages)
refill_stock(memcg, batch - nr_pages);
do {
if (page_counter_read(&memcg->memory) > memcg->high) {
if (in_interrupt()) {
schedule_work(&memcg->high_work);
break;
}
current->memcg_nr_pages_over_high += batch;
set_notify_resume(current);
break;
}
} while ((memcg = parent_mem_cgroup(memcg)));
return 0;
}
static void cancel_charge(struct mem_cgroup *memcg, unsigned int nr_pages)
{
if (mem_cgroup_is_root(memcg))
return;
page_counter_uncharge(&memcg->memory, nr_pages);
if (do_memsw_account())
page_counter_uncharge(&memcg->memsw, nr_pages);
css_put_many(&memcg->css, nr_pages);
}
static void lock_page_lru(struct page *page, int *isolated)
{
struct zone *zone = page_zone(page);
spin_lock_irq(zone_lru_lock(zone));
if (PageLRU(page)) {
struct lruvec *lruvec;
lruvec = mem_cgroup_page_lruvec(page, zone->zone_pgdat);
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
lruvec = mem_cgroup_page_lruvec(page, zone->zone_pgdat);
VM_BUG_ON_PAGE(PageLRU(page), page);
SetPageLRU(page);
add_page_to_lru_list(page, lruvec, page_lru(page));
}
spin_unlock_irq(zone_lru_lock(zone));
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
static inline bool memcg_kmem_bypass(void)
{
if (in_interrupt() || !current->mm || (current->flags & PF_KTHREAD))
return true;
return false;
}
struct kmem_cache *memcg_kmem_get_cache(struct kmem_cache *cachep)
{
struct mem_cgroup *memcg;
struct kmem_cache *memcg_cachep;
int kmemcg_id;
VM_BUG_ON(!is_root_cache(cachep));
if (memcg_kmem_bypass())
return cachep;
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
void memcg_kmem_put_cache(struct kmem_cache *cachep)
{
if (!is_root_cache(cachep))
css_put(&cachep->memcg_params.memcg->css);
}
int memcg_kmem_charge_memcg(struct page *page, gfp_t gfp, int order,
struct mem_cgroup *memcg)
{
unsigned int nr_pages = 1 << order;
struct page_counter *counter;
int ret;
ret = try_charge(memcg, gfp, nr_pages);
if (ret)
return ret;
if (!cgroup_subsys_on_dfl(memory_cgrp_subsys) &&
!page_counter_try_charge(&memcg->kmem, nr_pages, &counter)) {
cancel_charge(memcg, nr_pages);
return -ENOMEM;
}
page->mem_cgroup = memcg;
return 0;
}
int memcg_kmem_charge(struct page *page, gfp_t gfp, int order)
{
struct mem_cgroup *memcg;
int ret = 0;
if (memcg_kmem_bypass())
return 0;
memcg = get_mem_cgroup_from_mm(current->mm);
if (!mem_cgroup_is_root(memcg)) {
ret = memcg_kmem_charge_memcg(page, gfp, order, memcg);
if (!ret)
__SetPageKmemcg(page);
}
css_put(&memcg->css);
return ret;
}
void memcg_kmem_uncharge(struct page *page, int order)
{
struct mem_cgroup *memcg = page->mem_cgroup;
unsigned int nr_pages = 1 << order;
if (!memcg)
return;
VM_BUG_ON_PAGE(mem_cgroup_is_root(memcg), page);
if (!cgroup_subsys_on_dfl(memory_cgrp_subsys))
page_counter_uncharge(&memcg->kmem, nr_pages);
page_counter_uncharge(&memcg->memory, nr_pages);
if (do_memsw_account())
page_counter_uncharge(&memcg->memsw, nr_pages);
page->mem_cgroup = NULL;
if (PageKmemcg(page))
__ClearPageKmemcg(page);
css_put_many(&memcg->css, nr_pages);
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
unsigned long mem_cgroup_soft_limit_reclaim(pg_data_t *pgdat, int order,
gfp_t gfp_mask,
unsigned long *total_scanned)
{
unsigned long nr_reclaimed = 0;
struct mem_cgroup_per_node *mz, *next_mz = NULL;
unsigned long reclaimed;
int loop = 0;
struct mem_cgroup_tree_per_node *mctz;
unsigned long excess;
unsigned long nr_scanned;
if (order > 0)
return 0;
mctz = soft_limit_tree_node(pgdat->node_id);
if (RB_EMPTY_ROOT(&mctz->rb_root))
return 0;
do {
if (next_mz)
mz = next_mz;
else
mz = mem_cgroup_largest_soft_limit_node(mctz);
if (!mz)
break;
nr_scanned = 0;
reclaimed = mem_cgroup_soft_reclaim(mz->memcg, pgdat,
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
if (memcg->use_hierarchy == val)
return 0;
if ((!parent_memcg || !parent_memcg->use_hierarchy) &&
(val == 1 || val == 0)) {
if (!memcg_has_children(memcg))
memcg->use_hierarchy = val;
else
retval = -EBUSY;
} else
retval = -EINVAL;
return retval;
}
static void tree_stat(struct mem_cgroup *memcg, unsigned long *stat)
{
struct mem_cgroup *iter;
int i;
memset(stat, 0, sizeof(*stat) * MEMCG_NR_STAT);
for_each_mem_cgroup_tree(iter, memcg) {
for (i = 0; i < MEMCG_NR_STAT; i++)
stat[i] += mem_cgroup_read_stat(iter, i);
}
}
static void tree_events(struct mem_cgroup *memcg, unsigned long *events)
{
struct mem_cgroup *iter;
int i;
memset(events, 0, sizeof(*events) * MEMCG_NR_EVENTS);
for_each_mem_cgroup_tree(iter, memcg) {
for (i = 0; i < MEMCG_NR_EVENTS; i++)
events[i] += mem_cgroup_read_events(iter, i);
}
}
static unsigned long mem_cgroup_usage(struct mem_cgroup *memcg, bool swap)
{
unsigned long val = 0;
if (mem_cgroup_is_root(memcg)) {
struct mem_cgroup *iter;
for_each_mem_cgroup_tree(iter, memcg) {
val += mem_cgroup_read_stat(iter,
MEM_CGROUP_STAT_CACHE);
val += mem_cgroup_read_stat(iter,
MEM_CGROUP_STAT_RSS);
if (swap)
val += mem_cgroup_read_stat(iter,
MEM_CGROUP_STAT_SWAP);
}
} else {
if (!swap)
val = page_counter_read(&memcg->memory);
else
val = page_counter_read(&memcg->memsw);
}
return val;
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
case _TCP:
counter = &memcg->tcpmem;
break;
default:
BUG();
}
switch (MEMFILE_ATTR(cft->private)) {
case RES_USAGE:
if (counter == &memcg->memory)
return (u64)mem_cgroup_usage(memcg, false) * PAGE_SIZE;
if (counter == &memcg->memsw)
return (u64)mem_cgroup_usage(memcg, true) * PAGE_SIZE;
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
static int memcg_online_kmem(struct mem_cgroup *memcg)
{
int memcg_id;
if (cgroup_memory_nokmem)
return 0;
BUG_ON(memcg->kmemcg_id >= 0);
BUG_ON(memcg->kmem_state);
memcg_id = memcg_alloc_cache_id();
if (memcg_id < 0)
return memcg_id;
static_branch_inc(&memcg_kmem_enabled_key);
memcg->kmemcg_id = memcg_id;
memcg->kmem_state = KMEM_ONLINE;
return 0;
}
static void memcg_offline_kmem(struct mem_cgroup *memcg)
{
struct cgroup_subsys_state *css;
struct mem_cgroup *parent, *child;
int kmemcg_id;
if (memcg->kmem_state != KMEM_ONLINE)
return;
memcg->kmem_state = KMEM_ALLOCATED;
memcg_deactivate_kmem_caches(memcg);
kmemcg_id = memcg->kmemcg_id;
BUG_ON(kmemcg_id < 0);
parent = parent_mem_cgroup(memcg);
if (!parent)
parent = root_mem_cgroup;
rcu_read_lock();
css_for_each_descendant_pre(css, &memcg->css) {
child = mem_cgroup_from_css(css);
BUG_ON(child->kmemcg_id != kmemcg_id);
child->kmemcg_id = parent->kmemcg_id;
if (!memcg->use_hierarchy)
break;
}
rcu_read_unlock();
memcg_drain_all_list_lrus(kmemcg_id, parent->kmemcg_id);
memcg_free_cache_id(kmemcg_id);
}
static void memcg_free_kmem(struct mem_cgroup *memcg)
{
if (unlikely(memcg->kmem_state == KMEM_ONLINE))
memcg_offline_kmem(memcg);
if (memcg->kmem_state == KMEM_ALLOCATED) {
memcg_destroy_kmem_caches(memcg);
static_branch_dec(&memcg_kmem_enabled_key);
WARN_ON(page_counter_read(&memcg->kmem));
}
}
static int memcg_online_kmem(struct mem_cgroup *memcg)
{
return 0;
}
static void memcg_offline_kmem(struct mem_cgroup *memcg)
{
}
static void memcg_free_kmem(struct mem_cgroup *memcg)
{
}
static int memcg_update_kmem_limit(struct mem_cgroup *memcg,
unsigned long limit)
{
int ret;
mutex_lock(&memcg_limit_mutex);
ret = page_counter_limit(&memcg->kmem, limit);
mutex_unlock(&memcg_limit_mutex);
return ret;
}
static int memcg_update_tcp_limit(struct mem_cgroup *memcg, unsigned long limit)
{
int ret;
mutex_lock(&memcg_limit_mutex);
ret = page_counter_limit(&memcg->tcpmem, limit);
if (ret)
goto out;
if (!memcg->tcpmem_active) {
static_branch_inc(&memcg_sockets_enabled_key);
memcg->tcpmem_active = true;
}
out:
mutex_unlock(&memcg_limit_mutex);
return ret;
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
case _TCP:
ret = memcg_update_tcp_limit(memcg, nr_pages);
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
case _TCP:
counter = &memcg->tcpmem;
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
if (i == MEM_CGROUP_STAT_SWAP && !do_memsw_account())
continue;
seq_printf(m, "%s %lu\n", mem_cgroup_stat_names[i],
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
if (do_memsw_account())
seq_printf(m, "hierarchical_memsw_limit %llu\n",
(u64)memsw * PAGE_SIZE);
for (i = 0; i < MEM_CGROUP_STAT_NSTATS; i++) {
unsigned long long val = 0;
if (i == MEM_CGROUP_STAT_SWAP && !do_memsw_account())
continue;
for_each_mem_cgroup_tree(mi, memcg)
val += mem_cgroup_read_stat(mi, i) * PAGE_SIZE;
seq_printf(m, "total_%s %llu\n", mem_cgroup_stat_names[i], val);
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
pg_data_t *pgdat;
struct mem_cgroup_per_node *mz;
struct zone_reclaim_stat *rstat;
unsigned long recent_rotated[2] = {0, 0};
unsigned long recent_scanned[2] = {0, 0};
for_each_online_pgdat(pgdat) {
mz = mem_cgroup_nodeinfo(memcg, pgdat->node_id);
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
if (do_memsw_account())
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
rcu_assign_pointer(thresholds->primary, new);
synchronize_rcu();
if (!new) {
kfree(thresholds->spare);
thresholds->spare = NULL;
}
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
if (memcg->under_oom)
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
seq_printf(sf, "under_oom %d\n", (bool)memcg->under_oom);
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
struct list_head *mem_cgroup_cgwb_list(struct mem_cgroup *memcg)
{
return &memcg->cgwb_list;
}
static int memcg_wb_domain_init(struct mem_cgroup *memcg, gfp_t gfp)
{
return wb_domain_init(&memcg->cgwb_domain, gfp);
}
static void memcg_wb_domain_exit(struct mem_cgroup *memcg)
{
wb_domain_exit(&memcg->cgwb_domain);
}
static void memcg_wb_domain_size_changed(struct mem_cgroup *memcg)
{
wb_domain_size_changed(&memcg->cgwb_domain);
}
struct wb_domain *mem_cgroup_wb_domain(struct bdi_writeback *wb)
{
struct mem_cgroup *memcg = mem_cgroup_from_css(wb->memcg_css);
if (!memcg->css.parent)
return NULL;
return &memcg->cgwb_domain;
}
void mem_cgroup_wb_stats(struct bdi_writeback *wb, unsigned long *pfilepages,
unsigned long *pheadroom, unsigned long *pdirty,
unsigned long *pwriteback)
{
struct mem_cgroup *memcg = mem_cgroup_from_css(wb->memcg_css);
struct mem_cgroup *parent;
*pdirty = mem_cgroup_read_stat(memcg, MEM_CGROUP_STAT_DIRTY);
*pwriteback = mem_cgroup_read_stat(memcg, MEM_CGROUP_STAT_WRITEBACK);
*pfilepages = mem_cgroup_nr_lru_pages(memcg, (1 << LRU_INACTIVE_FILE) |
(1 << LRU_ACTIVE_FILE));
*pheadroom = PAGE_COUNTER_MAX;
while ((parent = parent_mem_cgroup(memcg))) {
unsigned long ceiling = min(memcg->memory.limit, memcg->high);
unsigned long used = page_counter_read(&memcg->memory);
*pheadroom = min(*pheadroom, ceiling - min(ceiling, used));
memcg = parent;
}
}
static int memcg_wb_domain_init(struct mem_cgroup *memcg, gfp_t gfp)
{
return 0;
}
static void memcg_wb_domain_exit(struct mem_cgroup *memcg)
{
}
static void memcg_wb_domain_size_changed(struct mem_cgroup *memcg)
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
static void mem_cgroup_id_get_many(struct mem_cgroup *memcg, unsigned int n)
{
VM_BUG_ON(atomic_read(&memcg->id.ref) <= 0);
atomic_add(n, &memcg->id.ref);
}
static void mem_cgroup_id_put_many(struct mem_cgroup *memcg, unsigned int n)
{
VM_BUG_ON(atomic_read(&memcg->id.ref) < n);
if (atomic_sub_and_test(n, &memcg->id.ref)) {
idr_remove(&mem_cgroup_idr, memcg->id.id);
memcg->id.id = 0;
css_put(&memcg->css);
}
}
static inline void mem_cgroup_id_get(struct mem_cgroup *memcg)
{
mem_cgroup_id_get_many(memcg, 1);
}
static inline void mem_cgroup_id_put(struct mem_cgroup *memcg)
{
mem_cgroup_id_put_many(memcg, 1);
}
struct mem_cgroup *mem_cgroup_from_id(unsigned short id)
{
WARN_ON_ONCE(!rcu_read_lock_held());
return idr_find(&mem_cgroup_idr, id);
}
static int alloc_mem_cgroup_per_node_info(struct mem_cgroup *memcg, int node)
{
struct mem_cgroup_per_node *pn;
int tmp = node;
if (!node_state(node, N_NORMAL_MEMORY))
tmp = -1;
pn = kzalloc_node(sizeof(*pn), GFP_KERNEL, tmp);
if (!pn)
return 1;
lruvec_init(&pn->lruvec);
pn->usage_in_excess = 0;
pn->on_tree = false;
pn->memcg = memcg;
memcg->nodeinfo[node] = pn;
return 0;
}
static void free_mem_cgroup_per_node_info(struct mem_cgroup *memcg, int node)
{
kfree(memcg->nodeinfo[node]);
}
static void mem_cgroup_free(struct mem_cgroup *memcg)
{
int node;
memcg_wb_domain_exit(memcg);
for_each_node(node)
free_mem_cgroup_per_node_info(memcg, node);
free_percpu(memcg->stat);
kfree(memcg);
}
static struct mem_cgroup *mem_cgroup_alloc(void)
{
struct mem_cgroup *memcg;
size_t size;
int node;
size = sizeof(struct mem_cgroup);
size += nr_node_ids * sizeof(struct mem_cgroup_per_node *);
memcg = kzalloc(size, GFP_KERNEL);
if (!memcg)
return NULL;
memcg->id.id = idr_alloc(&mem_cgroup_idr, NULL,
1, MEM_CGROUP_ID_MAX,
GFP_KERNEL);
if (memcg->id.id < 0)
goto fail;
memcg->stat = alloc_percpu(struct mem_cgroup_stat_cpu);
if (!memcg->stat)
goto fail;
for_each_node(node)
if (alloc_mem_cgroup_per_node_info(memcg, node))
goto fail;
if (memcg_wb_domain_init(memcg, GFP_KERNEL))
goto fail;
INIT_WORK(&memcg->high_work, high_work_func);
memcg->last_scanned_node = MAX_NUMNODES;
INIT_LIST_HEAD(&memcg->oom_notify);
mutex_init(&memcg->thresholds_lock);
spin_lock_init(&memcg->move_lock);
vmpressure_init(&memcg->vmpressure);
INIT_LIST_HEAD(&memcg->event_list);
spin_lock_init(&memcg->event_list_lock);
memcg->socket_pressure = jiffies;
#ifndef CONFIG_SLOB
memcg->kmemcg_id = -1;
#endif
#ifdef CONFIG_CGROUP_WRITEBACK
INIT_LIST_HEAD(&memcg->cgwb_list);
#endif
idr_replace(&mem_cgroup_idr, memcg, memcg->id.id);
return memcg;
fail:
if (memcg->id.id > 0)
idr_remove(&mem_cgroup_idr, memcg->id.id);
mem_cgroup_free(memcg);
return NULL;
}
static struct cgroup_subsys_state * __ref
mem_cgroup_css_alloc(struct cgroup_subsys_state *parent_css)
{
struct mem_cgroup *parent = mem_cgroup_from_css(parent_css);
struct mem_cgroup *memcg;
long error = -ENOMEM;
memcg = mem_cgroup_alloc();
if (!memcg)
return ERR_PTR(error);
memcg->high = PAGE_COUNTER_MAX;
memcg->soft_limit = PAGE_COUNTER_MAX;
if (parent) {
memcg->swappiness = mem_cgroup_swappiness(parent);
memcg->oom_kill_disable = parent->oom_kill_disable;
}
if (parent && parent->use_hierarchy) {
memcg->use_hierarchy = true;
page_counter_init(&memcg->memory, &parent->memory);
page_counter_init(&memcg->swap, &parent->swap);
page_counter_init(&memcg->memsw, &parent->memsw);
page_counter_init(&memcg->kmem, &parent->kmem);
page_counter_init(&memcg->tcpmem, &parent->tcpmem);
} else {
page_counter_init(&memcg->memory, NULL);
page_counter_init(&memcg->swap, NULL);
page_counter_init(&memcg->memsw, NULL);
page_counter_init(&memcg->kmem, NULL);
page_counter_init(&memcg->tcpmem, NULL);
if (parent != root_mem_cgroup)
memory_cgrp_subsys.broken_hierarchy = true;
}
if (!parent) {
root_mem_cgroup = memcg;
return &memcg->css;
}
error = memcg_online_kmem(memcg);
if (error)
goto fail;
if (cgroup_subsys_on_dfl(memory_cgrp_subsys) && !cgroup_memory_nosocket)
static_branch_inc(&memcg_sockets_enabled_key);
return &memcg->css;
fail:
mem_cgroup_free(memcg);
return ERR_PTR(-ENOMEM);
}
static int mem_cgroup_css_online(struct cgroup_subsys_state *css)
{
struct mem_cgroup *memcg = mem_cgroup_from_css(css);
atomic_set(&memcg->id.ref, 1);
css_get(css);
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
memcg_offline_kmem(memcg);
wb_memcg_offline(memcg);
mem_cgroup_id_put(memcg);
}
static void mem_cgroup_css_released(struct cgroup_subsys_state *css)
{
struct mem_cgroup *memcg = mem_cgroup_from_css(css);
invalidate_reclaim_iterators(memcg);
}
static void mem_cgroup_css_free(struct cgroup_subsys_state *css)
{
struct mem_cgroup *memcg = mem_cgroup_from_css(css);
if (cgroup_subsys_on_dfl(memory_cgrp_subsys) && !cgroup_memory_nosocket)
static_branch_dec(&memcg_sockets_enabled_key);
if (!cgroup_subsys_on_dfl(memory_cgrp_subsys) && memcg->tcpmem_active)
static_branch_dec(&memcg_sockets_enabled_key);
vmpressure_cleanup(&memcg->vmpressure);
cancel_work_sync(&memcg->high_work);
mem_cgroup_remove_from_trees(memcg);
memcg_free_kmem(memcg);
mem_cgroup_free(memcg);
}
static void mem_cgroup_css_reset(struct cgroup_subsys_state *css)
{
struct mem_cgroup *memcg = mem_cgroup_from_css(css);
page_counter_limit(&memcg->memory, PAGE_COUNTER_MAX);
page_counter_limit(&memcg->swap, PAGE_COUNTER_MAX);
page_counter_limit(&memcg->memsw, PAGE_COUNTER_MAX);
page_counter_limit(&memcg->kmem, PAGE_COUNTER_MAX);
page_counter_limit(&memcg->tcpmem, PAGE_COUNTER_MAX);
memcg->low = 0;
memcg->high = PAGE_COUNTER_MAX;
memcg->soft_limit = PAGE_COUNTER_MAX;
memcg_wb_domain_size_changed(memcg);
}
static int mem_cgroup_do_precharge(unsigned long count)
{
int ret;
ret = try_charge(mc.to, GFP_KERNEL & ~__GFP_DIRECT_RECLAIM, count);
if (!ret) {
mc.precharge += count;
return ret;
}
while (count--) {
ret = try_charge(mc.to, GFP_KERNEL & ~__GFP_NORETRY, 1);
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
pte_t ptent, swp_entry_t *entry)
{
struct page *page = NULL;
swp_entry_t ent = pte_to_swp_entry(ptent);
if (!(mc.flags & MOVE_ANON) || non_swap_entry(ent))
return NULL;
page = find_get_page(swap_address_space(ent), swp_offset(ent));
if (do_memsw_account())
entry->val = ent.val;
return page;
}
static struct page *mc_handle_swap_pte(struct vm_area_struct *vma,
pte_t ptent, swp_entry_t *entry)
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
if (do_memsw_account())
*entry = swp;
page = find_get_page(swap_address_space(swp),
swp_offset(swp));
}
} else
page = find_get_page(mapping, pgoff);
#else
page = find_get_page(mapping, pgoff);
#endif
return page;
}
static int mem_cgroup_move_account(struct page *page,
bool compound,
struct mem_cgroup *from,
struct mem_cgroup *to)
{
unsigned long flags;
unsigned int nr_pages = compound ? hpage_nr_pages(page) : 1;
int ret;
bool anon;
VM_BUG_ON(from == to);
VM_BUG_ON_PAGE(PageLRU(page), page);
VM_BUG_ON(compound && !PageTransHuge(page));
ret = -EBUSY;
if (!trylock_page(page))
goto out;
ret = -EINVAL;
if (page->mem_cgroup != from)
goto out_unlock;
anon = PageAnon(page);
spin_lock_irqsave(&from->move_lock, flags);
if (!anon && page_mapped(page)) {
__this_cpu_sub(from->stat->count[MEM_CGROUP_STAT_FILE_MAPPED],
nr_pages);
__this_cpu_add(to->stat->count[MEM_CGROUP_STAT_FILE_MAPPED],
nr_pages);
}
if (!anon && PageDirty(page)) {
struct address_space *mapping = page_mapping(page);
if (mapping_cap_account_dirty(mapping)) {
__this_cpu_sub(from->stat->count[MEM_CGROUP_STAT_DIRTY],
nr_pages);
__this_cpu_add(to->stat->count[MEM_CGROUP_STAT_DIRTY],
nr_pages);
}
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
mem_cgroup_charge_statistics(to, page, compound, nr_pages);
memcg_check_events(to, page);
mem_cgroup_charge_statistics(from, page, compound, -nr_pages);
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
page = mc_handle_swap_pte(vma, ptent, &ent);
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
ptl = pmd_trans_huge_lock(pmd, vma);
if (ptl) {
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
walk_page_range(0, mm->highest_vm_end,
&mem_cgroup_count_precharge_walk);
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
mem_cgroup_id_put_many(mc.from, mc.moved_swap);
if (!mem_cgroup_is_root(mc.to))
page_counter_uncharge(&mc.to->memory, mc.moved_swap);
mem_cgroup_id_get_many(mc.to, mc.moved_swap);
css_put_many(&mc.to->css, mc.moved_swap);
mc.moved_swap = 0;
}
memcg_oom_recover(from);
memcg_oom_recover(to);
wake_up_all(&mc.waitq);
}
static void mem_cgroup_clear_mc(void)
{
struct mm_struct *mm = mc.mm;
mc.moving_task = NULL;
__mem_cgroup_clear_mc();
spin_lock(&mc.lock);
mc.from = NULL;
mc.to = NULL;
mc.mm = NULL;
spin_unlock(&mc.lock);
mmput(mm);
}
static int mem_cgroup_can_attach(struct cgroup_taskset *tset)
{
struct cgroup_subsys_state *css;
struct mem_cgroup *memcg = NULL;
struct mem_cgroup *from;
struct task_struct *leader, *p;
struct mm_struct *mm;
unsigned long move_flags;
int ret = 0;
if (cgroup_subsys_on_dfl(memory_cgrp_subsys))
return 0;
p = NULL;
cgroup_taskset_for_each_leader(leader, css, tset) {
WARN_ON_ONCE(p);
p = leader;
memcg = mem_cgroup_from_css(css);
}
if (!p)
return 0;
move_flags = READ_ONCE(memcg->move_charge_at_immigrate);
if (!move_flags)
return 0;
from = mem_cgroup_from_task(p);
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
mc.mm = mm;
mc.from = from;
mc.to = memcg;
mc.flags = move_flags;
spin_unlock(&mc.lock);
ret = mem_cgroup_precharge_mc(mm);
if (ret)
mem_cgroup_clear_mc();
} else {
mmput(mm);
}
return ret;
}
static void mem_cgroup_cancel_attach(struct cgroup_taskset *tset)
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
ptl = pmd_trans_huge_lock(pmd, vma);
if (ptl) {
if (mc.precharge < HPAGE_PMD_NR) {
spin_unlock(ptl);
return 0;
}
target_type = get_mctgt_type_thp(vma, addr, *pmd, &target);
if (target_type == MC_TARGET_PAGE) {
page = target.page;
if (!isolate_lru_page(page)) {
if (!mem_cgroup_move_account(page, true,
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
if (PageTransCompound(page))
goto put;
if (isolate_lru_page(page))
goto put;
if (!mem_cgroup_move_account(page, false,
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
static void mem_cgroup_move_charge(void)
{
struct mm_walk mem_cgroup_move_charge_walk = {
.pmd_entry = mem_cgroup_move_charge_pte_range,
.mm = mc.mm,
};
lru_add_drain_all();
atomic_inc(&mc.from->moving_account);
synchronize_rcu();
retry:
if (unlikely(!down_read_trylock(&mc.mm->mmap_sem))) {
__mem_cgroup_clear_mc();
cond_resched();
goto retry;
}
walk_page_range(0, mc.mm->highest_vm_end, &mem_cgroup_move_charge_walk);
up_read(&mc.mm->mmap_sem);
atomic_dec(&mc.from->moving_account);
}
static void mem_cgroup_move_task(void)
{
if (mc.to) {
mem_cgroup_move_charge();
mem_cgroup_clear_mc();
}
}
static int mem_cgroup_can_attach(struct cgroup_taskset *tset)
{
return 0;
}
static void mem_cgroup_cancel_attach(struct cgroup_taskset *tset)
{
}
static void mem_cgroup_move_task(void)
{
}
static void mem_cgroup_bind(struct cgroup_subsys_state *root_css)
{
if (cgroup_subsys_on_dfl(memory_cgrp_subsys))
root_mem_cgroup->use_hierarchy = true;
else
root_mem_cgroup->use_hierarchy = false;
}
static u64 memory_current_read(struct cgroup_subsys_state *css,
struct cftype *cft)
{
struct mem_cgroup *memcg = mem_cgroup_from_css(css);
return (u64)page_counter_read(&memcg->memory) * PAGE_SIZE;
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
unsigned long nr_pages;
unsigned long high;
int err;
buf = strstrip(buf);
err = page_counter_memparse(buf, "max", &high);
if (err)
return err;
memcg->high = high;
nr_pages = page_counter_read(&memcg->memory);
if (nr_pages > high)
try_to_free_mem_cgroup_pages(memcg, nr_pages - high,
GFP_KERNEL, true);
memcg_wb_domain_size_changed(memcg);
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
unsigned int nr_reclaims = MEM_CGROUP_RECLAIM_RETRIES;
bool drained = false;
unsigned long max;
int err;
buf = strstrip(buf);
err = page_counter_memparse(buf, "max", &max);
if (err)
return err;
xchg(&memcg->memory.limit, max);
for (;;) {
unsigned long nr_pages = page_counter_read(&memcg->memory);
if (nr_pages <= max)
break;
if (signal_pending(current)) {
err = -EINTR;
break;
}
if (!drained) {
drain_all_stock(memcg);
drained = true;
continue;
}
if (nr_reclaims) {
if (!try_to_free_mem_cgroup_pages(memcg, nr_pages - max,
GFP_KERNEL, true))
nr_reclaims--;
continue;
}
mem_cgroup_events(memcg, MEMCG_OOM, 1);
if (!mem_cgroup_out_of_memory(memcg, GFP_KERNEL, 0))
break;
}
memcg_wb_domain_size_changed(memcg);
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
static int memory_stat_show(struct seq_file *m, void *v)
{
struct mem_cgroup *memcg = mem_cgroup_from_css(seq_css(m));
unsigned long stat[MEMCG_NR_STAT];
unsigned long events[MEMCG_NR_EVENTS];
int i;
tree_stat(memcg, stat);
tree_events(memcg, events);
seq_printf(m, "anon %llu\n",
(u64)stat[MEM_CGROUP_STAT_RSS] * PAGE_SIZE);
seq_printf(m, "file %llu\n",
(u64)stat[MEM_CGROUP_STAT_CACHE] * PAGE_SIZE);
seq_printf(m, "kernel_stack %llu\n",
(u64)stat[MEMCG_KERNEL_STACK_KB] * 1024);
seq_printf(m, "slab %llu\n",
(u64)(stat[MEMCG_SLAB_RECLAIMABLE] +
stat[MEMCG_SLAB_UNRECLAIMABLE]) * PAGE_SIZE);
seq_printf(m, "sock %llu\n",
(u64)stat[MEMCG_SOCK] * PAGE_SIZE);
seq_printf(m, "file_mapped %llu\n",
(u64)stat[MEM_CGROUP_STAT_FILE_MAPPED] * PAGE_SIZE);
seq_printf(m, "file_dirty %llu\n",
(u64)stat[MEM_CGROUP_STAT_DIRTY] * PAGE_SIZE);
seq_printf(m, "file_writeback %llu\n",
(u64)stat[MEM_CGROUP_STAT_WRITEBACK] * PAGE_SIZE);
for (i = 0; i < NR_LRU_LISTS; i++) {
struct mem_cgroup *mi;
unsigned long val = 0;
for_each_mem_cgroup_tree(mi, memcg)
val += mem_cgroup_nr_lru_pages(mi, BIT(i));
seq_printf(m, "%s %llu\n",
mem_cgroup_lru_names[i], (u64)val * PAGE_SIZE);
}
seq_printf(m, "slab_reclaimable %llu\n",
(u64)stat[MEMCG_SLAB_RECLAIMABLE] * PAGE_SIZE);
seq_printf(m, "slab_unreclaimable %llu\n",
(u64)stat[MEMCG_SLAB_UNRECLAIMABLE] * PAGE_SIZE);
seq_printf(m, "pgfault %lu\n",
events[MEM_CGROUP_EVENTS_PGFAULT]);
seq_printf(m, "pgmajfault %lu\n",
events[MEM_CGROUP_EVENTS_PGMAJFAULT]);
return 0;
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
gfp_t gfp_mask, struct mem_cgroup **memcgp,
bool compound)
{
struct mem_cgroup *memcg = NULL;
unsigned int nr_pages = compound ? hpage_nr_pages(page) : 1;
int ret = 0;
if (mem_cgroup_disabled())
goto out;
if (PageSwapCache(page)) {
VM_BUG_ON_PAGE(!PageLocked(page), page);
if (page->mem_cgroup)
goto out;
if (do_swap_account) {
swp_entry_t ent = { .val = page_private(page), };
unsigned short id = lookup_swap_cgroup_id(ent);
rcu_read_lock();
memcg = mem_cgroup_from_id(id);
if (memcg && !css_tryget_online(&memcg->css))
memcg = NULL;
rcu_read_unlock();
}
}
if (!memcg)
memcg = get_mem_cgroup_from_mm(mm);
ret = try_charge(memcg, gfp_mask, nr_pages);
css_put(&memcg->css);
out:
*memcgp = memcg;
return ret;
}
void mem_cgroup_commit_charge(struct page *page, struct mem_cgroup *memcg,
bool lrucare, bool compound)
{
unsigned int nr_pages = compound ? hpage_nr_pages(page) : 1;
VM_BUG_ON_PAGE(!page->mapping, page);
VM_BUG_ON_PAGE(PageLRU(page) && !lrucare, page);
if (mem_cgroup_disabled())
return;
if (!memcg)
return;
commit_charge(page, memcg, lrucare);
local_irq_disable();
mem_cgroup_charge_statistics(memcg, page, compound, nr_pages);
memcg_check_events(memcg, page);
local_irq_enable();
if (do_memsw_account() && PageSwapCache(page)) {
swp_entry_t entry = { .val = page_private(page) };
mem_cgroup_uncharge_swap(entry);
}
}
void mem_cgroup_cancel_charge(struct page *page, struct mem_cgroup *memcg,
bool compound)
{
unsigned int nr_pages = compound ? hpage_nr_pages(page) : 1;
if (mem_cgroup_disabled())
return;
if (!memcg)
return;
cancel_charge(memcg, nr_pages);
}
static void uncharge_batch(struct mem_cgroup *memcg, unsigned long pgpgout,
unsigned long nr_anon, unsigned long nr_file,
unsigned long nr_huge, unsigned long nr_kmem,
struct page *dummy_page)
{
unsigned long nr_pages = nr_anon + nr_file + nr_kmem;
unsigned long flags;
if (!mem_cgroup_is_root(memcg)) {
page_counter_uncharge(&memcg->memory, nr_pages);
if (do_memsw_account())
page_counter_uncharge(&memcg->memsw, nr_pages);
if (!cgroup_subsys_on_dfl(memory_cgrp_subsys) && nr_kmem)
page_counter_uncharge(&memcg->kmem, nr_kmem);
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
unsigned long nr_kmem = 0;
unsigned long pgpgout = 0;
struct list_head *next;
struct page *page;
next = page_list->next;
do {
page = list_entry(next, struct page, lru);
next = page->lru.next;
VM_BUG_ON_PAGE(PageLRU(page), page);
VM_BUG_ON_PAGE(page_count(page), page);
if (!page->mem_cgroup)
continue;
if (memcg != page->mem_cgroup) {
if (memcg) {
uncharge_batch(memcg, pgpgout, nr_anon, nr_file,
nr_huge, nr_kmem, page);
pgpgout = nr_anon = nr_file =
nr_huge = nr_kmem = 0;
}
memcg = page->mem_cgroup;
}
if (!PageKmemcg(page)) {
unsigned int nr_pages = 1;
if (PageTransHuge(page)) {
nr_pages <<= compound_order(page);
nr_huge += nr_pages;
}
if (PageAnon(page))
nr_anon += nr_pages;
else
nr_file += nr_pages;
pgpgout++;
} else {
nr_kmem += 1 << compound_order(page);
__ClearPageKmemcg(page);
}
page->mem_cgroup = NULL;
} while (next != page_list);
if (memcg)
uncharge_batch(memcg, pgpgout, nr_anon, nr_file,
nr_huge, nr_kmem, page);
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
void mem_cgroup_migrate(struct page *oldpage, struct page *newpage)
{
struct mem_cgroup *memcg;
unsigned int nr_pages;
bool compound;
unsigned long flags;
VM_BUG_ON_PAGE(!PageLocked(oldpage), oldpage);
VM_BUG_ON_PAGE(!PageLocked(newpage), newpage);
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
compound = PageTransHuge(newpage);
nr_pages = compound ? hpage_nr_pages(newpage) : 1;
page_counter_charge(&memcg->memory, nr_pages);
if (do_memsw_account())
page_counter_charge(&memcg->memsw, nr_pages);
css_get_many(&memcg->css, nr_pages);
commit_charge(newpage, memcg, false);
local_irq_save(flags);
mem_cgroup_charge_statistics(memcg, newpage, compound, nr_pages);
memcg_check_events(memcg, newpage);
local_irq_restore(flags);
}
void mem_cgroup_sk_alloc(struct sock *sk)
{
struct mem_cgroup *memcg;
if (!mem_cgroup_sockets_enabled)
return;
if (sk->sk_memcg) {
BUG_ON(mem_cgroup_is_root(sk->sk_memcg));
css_get(&sk->sk_memcg->css);
return;
}
rcu_read_lock();
memcg = mem_cgroup_from_task(current);
if (memcg == root_mem_cgroup)
goto out;
if (!cgroup_subsys_on_dfl(memory_cgrp_subsys) && !memcg->tcpmem_active)
goto out;
if (css_tryget_online(&memcg->css))
sk->sk_memcg = memcg;
out:
rcu_read_unlock();
}
void mem_cgroup_sk_free(struct sock *sk)
{
if (sk->sk_memcg)
css_put(&sk->sk_memcg->css);
}
bool mem_cgroup_charge_skmem(struct mem_cgroup *memcg, unsigned int nr_pages)
{
gfp_t gfp_mask = GFP_KERNEL;
if (!cgroup_subsys_on_dfl(memory_cgrp_subsys)) {
struct page_counter *fail;
if (page_counter_try_charge(&memcg->tcpmem, nr_pages, &fail)) {
memcg->tcpmem_pressure = 0;
return true;
}
page_counter_charge(&memcg->tcpmem, nr_pages);
memcg->tcpmem_pressure = 1;
return false;
}
if (in_softirq())
gfp_mask = GFP_NOWAIT;
this_cpu_add(memcg->stat->count[MEMCG_SOCK], nr_pages);
if (try_charge(memcg, gfp_mask, nr_pages) == 0)
return true;
try_charge(memcg, gfp_mask|__GFP_NOFAIL, nr_pages);
return false;
}
void mem_cgroup_uncharge_skmem(struct mem_cgroup *memcg, unsigned int nr_pages)
{
if (!cgroup_subsys_on_dfl(memory_cgrp_subsys)) {
page_counter_uncharge(&memcg->tcpmem, nr_pages);
return;
}
this_cpu_sub(memcg->stat->count[MEMCG_SOCK], nr_pages);
page_counter_uncharge(&memcg->memory, nr_pages);
css_put_many(&memcg->css, nr_pages);
}
static int __init cgroup_memory(char *s)
{
char *token;
while ((token = strsep(&s, ",")) != NULL) {
if (!*token)
continue;
if (!strcmp(token, "nosocket"))
cgroup_memory_nosocket = true;
if (!strcmp(token, "nokmem"))
cgroup_memory_nokmem = true;
}
return 0;
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
rtpn = kzalloc_node(sizeof(*rtpn), GFP_KERNEL,
node_online(node) ? node : NUMA_NO_NODE);
rtpn->rb_root = RB_ROOT;
spin_lock_init(&rtpn->lock);
soft_limit_tree.rb_tree_per_node[node] = rtpn;
}
return 0;
}
static struct mem_cgroup *mem_cgroup_id_get_online(struct mem_cgroup *memcg)
{
while (!atomic_inc_not_zero(&memcg->id.ref)) {
if (WARN_ON_ONCE(memcg == root_mem_cgroup)) {
VM_BUG_ON(1);
break;
}
memcg = parent_mem_cgroup(memcg);
if (!memcg)
memcg = root_mem_cgroup;
}
return memcg;
}
void mem_cgroup_swapout(struct page *page, swp_entry_t entry)
{
struct mem_cgroup *memcg, *swap_memcg;
unsigned short oldid;
VM_BUG_ON_PAGE(PageLRU(page), page);
VM_BUG_ON_PAGE(page_count(page), page);
if (!do_memsw_account())
return;
memcg = page->mem_cgroup;
if (!memcg)
return;
swap_memcg = mem_cgroup_id_get_online(memcg);
oldid = swap_cgroup_record(entry, mem_cgroup_id(swap_memcg));
VM_BUG_ON_PAGE(oldid, page);
mem_cgroup_swap_statistics(swap_memcg, true);
page->mem_cgroup = NULL;
if (!mem_cgroup_is_root(memcg))
page_counter_uncharge(&memcg->memory, 1);
if (memcg != swap_memcg) {
if (!mem_cgroup_is_root(swap_memcg))
page_counter_charge(&swap_memcg->memsw, 1);
page_counter_uncharge(&memcg->memsw, 1);
}
VM_BUG_ON(!irqs_disabled());
mem_cgroup_charge_statistics(memcg, page, false, -1);
memcg_check_events(memcg, page);
if (!mem_cgroup_is_root(memcg))
css_put(&memcg->css);
}
int mem_cgroup_try_charge_swap(struct page *page, swp_entry_t entry)
{
struct mem_cgroup *memcg;
struct page_counter *counter;
unsigned short oldid;
if (!cgroup_subsys_on_dfl(memory_cgrp_subsys) || !do_swap_account)
return 0;
memcg = page->mem_cgroup;
if (!memcg)
return 0;
memcg = mem_cgroup_id_get_online(memcg);
if (!mem_cgroup_is_root(memcg) &&
!page_counter_try_charge(&memcg->swap, 1, &counter)) {
mem_cgroup_id_put(memcg);
return -ENOMEM;
}
oldid = swap_cgroup_record(entry, mem_cgroup_id(memcg));
VM_BUG_ON_PAGE(oldid, page);
mem_cgroup_swap_statistics(memcg, true);
return 0;
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
if (!mem_cgroup_is_root(memcg)) {
if (cgroup_subsys_on_dfl(memory_cgrp_subsys))
page_counter_uncharge(&memcg->swap, 1);
else
page_counter_uncharge(&memcg->memsw, 1);
}
mem_cgroup_swap_statistics(memcg, false);
mem_cgroup_id_put(memcg);
}
rcu_read_unlock();
}
long mem_cgroup_get_nr_swap_pages(struct mem_cgroup *memcg)
{
long nr_swap_pages = get_nr_swap_pages();
if (!do_swap_account || !cgroup_subsys_on_dfl(memory_cgrp_subsys))
return nr_swap_pages;
for (; memcg != root_mem_cgroup; memcg = parent_mem_cgroup(memcg))
nr_swap_pages = min_t(long, nr_swap_pages,
READ_ONCE(memcg->swap.limit) -
page_counter_read(&memcg->swap));
return nr_swap_pages;
}
bool mem_cgroup_swap_full(struct page *page)
{
struct mem_cgroup *memcg;
VM_BUG_ON_PAGE(!PageLocked(page), page);
if (vm_swap_full())
return true;
if (!do_swap_account || !cgroup_subsys_on_dfl(memory_cgrp_subsys))
return false;
memcg = page->mem_cgroup;
if (!memcg)
return false;
for (; memcg != root_mem_cgroup; memcg = parent_mem_cgroup(memcg))
if (page_counter_read(&memcg->swap) * 2 >= memcg->swap.limit)
return true;
return false;
}
static int __init enable_swap_account(char *s)
{
if (!strcmp(s, "1"))
really_do_swap_account = 1;
else if (!strcmp(s, "0"))
really_do_swap_account = 0;
return 1;
}
static u64 swap_current_read(struct cgroup_subsys_state *css,
struct cftype *cft)
{
struct mem_cgroup *memcg = mem_cgroup_from_css(css);
return (u64)page_counter_read(&memcg->swap) * PAGE_SIZE;
}
static int swap_max_show(struct seq_file *m, void *v)
{
struct mem_cgroup *memcg = mem_cgroup_from_css(seq_css(m));
unsigned long max = READ_ONCE(memcg->swap.limit);
if (max == PAGE_COUNTER_MAX)
seq_puts(m, "max\n");
else
seq_printf(m, "%llu\n", (u64)max * PAGE_SIZE);
return 0;
}
static ssize_t swap_max_write(struct kernfs_open_file *of,
char *buf, size_t nbytes, loff_t off)
{
struct mem_cgroup *memcg = mem_cgroup_from_css(of_css(of));
unsigned long max;
int err;
buf = strstrip(buf);
err = page_counter_memparse(buf, "max", &max);
if (err)
return err;
mutex_lock(&memcg_limit_mutex);
err = page_counter_limit(&memcg->swap, max);
mutex_unlock(&memcg_limit_mutex);
if (err)
return err;
return nbytes;
}
static int __init mem_cgroup_swap_init(void)
{
if (!mem_cgroup_disabled() && really_do_swap_account) {
do_swap_account = 1;
WARN_ON(cgroup_add_dfl_cftypes(&memory_cgrp_subsys,
swap_files));
WARN_ON(cgroup_add_legacy_cftypes(&memory_cgrp_subsys,
memsw_cgroup_files));
}
return 0;
}
