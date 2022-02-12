static bool move_anon(void)
{
return test_bit(MOVE_CHARGE_TYPE_ANON,
&mc.to->move_charge_at_immigrate);
}
static bool move_file(void)
{
return test_bit(MOVE_CHARGE_TYPE_FILE,
&mc.to->move_charge_at_immigrate);
}
static struct mem_cgroup_per_zone *
mem_cgroup_zoneinfo(struct mem_cgroup *mem, int nid, int zid)
{
return &mem->info.nodeinfo[nid]->zoneinfo[zid];
}
struct cgroup_subsys_state *mem_cgroup_css(struct mem_cgroup *mem)
{
return &mem->css;
}
static struct mem_cgroup_per_zone *
page_cgroup_zoneinfo(struct mem_cgroup *mem, struct page *page)
{
int nid = page_to_nid(page);
int zid = page_zonenum(page);
return mem_cgroup_zoneinfo(mem, nid, zid);
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
static void
__mem_cgroup_insert_exceeded(struct mem_cgroup *mem,
struct mem_cgroup_per_zone *mz,
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
static void
__mem_cgroup_remove_exceeded(struct mem_cgroup *mem,
struct mem_cgroup_per_zone *mz,
struct mem_cgroup_tree_per_zone *mctz)
{
if (!mz->on_tree)
return;
rb_erase(&mz->tree_node, &mctz->rb_root);
mz->on_tree = false;
}
static void
mem_cgroup_remove_exceeded(struct mem_cgroup *mem,
struct mem_cgroup_per_zone *mz,
struct mem_cgroup_tree_per_zone *mctz)
{
spin_lock(&mctz->lock);
__mem_cgroup_remove_exceeded(mem, mz, mctz);
spin_unlock(&mctz->lock);
}
static void mem_cgroup_update_tree(struct mem_cgroup *mem, struct page *page)
{
unsigned long long excess;
struct mem_cgroup_per_zone *mz;
struct mem_cgroup_tree_per_zone *mctz;
int nid = page_to_nid(page);
int zid = page_zonenum(page);
mctz = soft_limit_tree_from_page(page);
for (; mem; mem = parent_mem_cgroup(mem)) {
mz = mem_cgroup_zoneinfo(mem, nid, zid);
excess = res_counter_soft_limit_excess(&mem->res);
if (excess || mz->on_tree) {
spin_lock(&mctz->lock);
if (mz->on_tree)
__mem_cgroup_remove_exceeded(mem, mz, mctz);
__mem_cgroup_insert_exceeded(mem, mz, mctz, excess);
spin_unlock(&mctz->lock);
}
}
}
static void mem_cgroup_remove_from_trees(struct mem_cgroup *mem)
{
int node, zone;
struct mem_cgroup_per_zone *mz;
struct mem_cgroup_tree_per_zone *mctz;
for_each_node_state(node, N_POSSIBLE) {
for (zone = 0; zone < MAX_NR_ZONES; zone++) {
mz = mem_cgroup_zoneinfo(mem, node, zone);
mctz = soft_limit_tree_node_zone(node, zone);
mem_cgroup_remove_exceeded(mem, mz, mctz);
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
__mem_cgroup_remove_exceeded(mz->mem, mz, mctz);
if (!res_counter_soft_limit_excess(&mz->mem->res) ||
!css_tryget(&mz->mem->css))
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
static long mem_cgroup_read_stat(struct mem_cgroup *mem,
enum mem_cgroup_stat_index idx)
{
long val = 0;
int cpu;
get_online_cpus();
for_each_online_cpu(cpu)
val += per_cpu(mem->stat->count[idx], cpu);
#ifdef CONFIG_HOTPLUG_CPU
spin_lock(&mem->pcp_counter_lock);
val += mem->nocpu_base.count[idx];
spin_unlock(&mem->pcp_counter_lock);
#endif
put_online_cpus();
return val;
}
static void mem_cgroup_swap_statistics(struct mem_cgroup *mem,
bool charge)
{
int val = (charge) ? 1 : -1;
this_cpu_add(mem->stat->count[MEM_CGROUP_STAT_SWAPOUT], val);
}
void mem_cgroup_pgfault(struct mem_cgroup *mem, int val)
{
this_cpu_add(mem->stat->events[MEM_CGROUP_EVENTS_PGFAULT], val);
}
void mem_cgroup_pgmajfault(struct mem_cgroup *mem, int val)
{
this_cpu_add(mem->stat->events[MEM_CGROUP_EVENTS_PGMAJFAULT], val);
}
static unsigned long mem_cgroup_read_events(struct mem_cgroup *mem,
enum mem_cgroup_events_index idx)
{
unsigned long val = 0;
int cpu;
for_each_online_cpu(cpu)
val += per_cpu(mem->stat->events[idx], cpu);
#ifdef CONFIG_HOTPLUG_CPU
spin_lock(&mem->pcp_counter_lock);
val += mem->nocpu_base.events[idx];
spin_unlock(&mem->pcp_counter_lock);
#endif
return val;
}
static void mem_cgroup_charge_statistics(struct mem_cgroup *mem,
bool file, int nr_pages)
{
preempt_disable();
if (file)
__this_cpu_add(mem->stat->count[MEM_CGROUP_STAT_CACHE], nr_pages);
else
__this_cpu_add(mem->stat->count[MEM_CGROUP_STAT_RSS], nr_pages);
if (nr_pages > 0)
__this_cpu_inc(mem->stat->events[MEM_CGROUP_EVENTS_PGPGIN]);
else {
__this_cpu_inc(mem->stat->events[MEM_CGROUP_EVENTS_PGPGOUT]);
nr_pages = -nr_pages;
}
__this_cpu_add(mem->stat->events[MEM_CGROUP_EVENTS_COUNT], nr_pages);
preempt_enable();
}
unsigned long
mem_cgroup_zone_nr_lru_pages(struct mem_cgroup *mem, int nid, int zid,
unsigned int lru_mask)
{
struct mem_cgroup_per_zone *mz;
enum lru_list l;
unsigned long ret = 0;
mz = mem_cgroup_zoneinfo(mem, nid, zid);
for_each_lru(l) {
if (BIT(l) & lru_mask)
ret += MEM_CGROUP_ZSTAT(mz, l);
}
return ret;
}
static unsigned long
mem_cgroup_node_nr_lru_pages(struct mem_cgroup *mem,
int nid, unsigned int lru_mask)
{
u64 total = 0;
int zid;
for (zid = 0; zid < MAX_NR_ZONES; zid++)
total += mem_cgroup_zone_nr_lru_pages(mem, nid, zid, lru_mask);
return total;
}
static unsigned long mem_cgroup_nr_lru_pages(struct mem_cgroup *mem,
unsigned int lru_mask)
{
int nid;
u64 total = 0;
for_each_node_state(nid, N_HIGH_MEMORY)
total += mem_cgroup_node_nr_lru_pages(mem, nid, lru_mask);
return total;
}
static bool __memcg_event_check(struct mem_cgroup *mem, int target)
{
unsigned long val, next;
val = this_cpu_read(mem->stat->events[MEM_CGROUP_EVENTS_COUNT]);
next = this_cpu_read(mem->stat->targets[target]);
return ((long)next - (long)val < 0);
}
static void __mem_cgroup_target_update(struct mem_cgroup *mem, int target)
{
unsigned long val, next;
val = this_cpu_read(mem->stat->events[MEM_CGROUP_EVENTS_COUNT]);
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
return;
}
this_cpu_write(mem->stat->targets[target], next);
}
static void memcg_check_events(struct mem_cgroup *mem, struct page *page)
{
if (unlikely(__memcg_event_check(mem, MEM_CGROUP_TARGET_THRESH))) {
mem_cgroup_threshold(mem);
__mem_cgroup_target_update(mem, MEM_CGROUP_TARGET_THRESH);
if (unlikely(__memcg_event_check(mem,
MEM_CGROUP_TARGET_SOFTLIMIT))) {
mem_cgroup_update_tree(mem, page);
__mem_cgroup_target_update(mem,
MEM_CGROUP_TARGET_SOFTLIMIT);
}
#if MAX_NUMNODES > 1
if (unlikely(__memcg_event_check(mem,
MEM_CGROUP_TARGET_NUMAINFO))) {
atomic_inc(&mem->numainfo_events);
__mem_cgroup_target_update(mem,
MEM_CGROUP_TARGET_NUMAINFO);
}
#endif
}
}
static struct mem_cgroup *mem_cgroup_from_cont(struct cgroup *cont)
{
return container_of(cgroup_subsys_state(cont,
mem_cgroup_subsys_id), struct mem_cgroup,
css);
}
struct mem_cgroup *mem_cgroup_from_task(struct task_struct *p)
{
if (unlikely(!p))
return NULL;
return container_of(task_subsys_state(p, mem_cgroup_subsys_id),
struct mem_cgroup, css);
}
struct mem_cgroup *try_get_mem_cgroup_from_mm(struct mm_struct *mm)
{
struct mem_cgroup *mem = NULL;
if (!mm)
return NULL;
rcu_read_lock();
do {
mem = mem_cgroup_from_task(rcu_dereference(mm->owner));
if (unlikely(!mem))
break;
} while (!css_tryget(&mem->css));
rcu_read_unlock();
return mem;
}
static struct mem_cgroup *mem_cgroup_start_loop(struct mem_cgroup *mem)
{
struct cgroup_subsys_state *css;
int found;
if (!mem)
return root_mem_cgroup;
if (!mem->use_hierarchy) {
if (css_tryget(&mem->css))
return mem;
return NULL;
}
rcu_read_lock();
css = css_get_next(&mem_cgroup_subsys, 1, &mem->css, &found);
if (css && css_tryget(css))
mem = container_of(css, struct mem_cgroup, css);
else
mem = NULL;
rcu_read_unlock();
return mem;
}
static struct mem_cgroup *mem_cgroup_get_next(struct mem_cgroup *iter,
struct mem_cgroup *root,
bool cond)
{
int nextid = css_id(&iter->css) + 1;
int found;
int hierarchy_used;
struct cgroup_subsys_state *css;
hierarchy_used = iter->use_hierarchy;
css_put(&iter->css);
if (!cond || (root && !hierarchy_used))
return NULL;
if (!root)
root = root_mem_cgroup;
do {
iter = NULL;
rcu_read_lock();
css = css_get_next(&mem_cgroup_subsys, nextid,
&root->css, &found);
if (css && css_tryget(css))
iter = container_of(css, struct mem_cgroup, css);
rcu_read_unlock();
nextid = found + 1;
} while (css && !iter);
return iter;
}
static inline bool mem_cgroup_is_root(struct mem_cgroup *mem)
{
return (mem == root_mem_cgroup);
}
void mem_cgroup_count_vm_event(struct mm_struct *mm, enum vm_event_item idx)
{
struct mem_cgroup *mem;
if (!mm)
return;
rcu_read_lock();
mem = mem_cgroup_from_task(rcu_dereference(mm->owner));
if (unlikely(!mem))
goto out;
switch (idx) {
case PGMAJFAULT:
mem_cgroup_pgmajfault(mem, 1);
break;
case PGFAULT:
mem_cgroup_pgfault(mem, 1);
break;
default:
BUG();
}
out:
rcu_read_unlock();
}
void mem_cgroup_del_lru_list(struct page *page, enum lru_list lru)
{
struct page_cgroup *pc;
struct mem_cgroup_per_zone *mz;
if (mem_cgroup_disabled())
return;
pc = lookup_page_cgroup(page);
if (!TestClearPageCgroupAcctLRU(pc))
return;
VM_BUG_ON(!pc->mem_cgroup);
mz = page_cgroup_zoneinfo(pc->mem_cgroup, page);
MEM_CGROUP_ZSTAT(mz, lru) -= 1 << compound_order(page);
if (mem_cgroup_is_root(pc->mem_cgroup))
return;
VM_BUG_ON(list_empty(&pc->lru));
list_del_init(&pc->lru);
}
void mem_cgroup_del_lru(struct page *page)
{
mem_cgroup_del_lru_list(page, page_lru(page));
}
void mem_cgroup_rotate_reclaimable_page(struct page *page)
{
struct mem_cgroup_per_zone *mz;
struct page_cgroup *pc;
enum lru_list lru = page_lru(page);
if (mem_cgroup_disabled())
return;
pc = lookup_page_cgroup(page);
if (!PageCgroupUsed(pc))
return;
smp_rmb();
if (mem_cgroup_is_root(pc->mem_cgroup))
return;
mz = page_cgroup_zoneinfo(pc->mem_cgroup, page);
list_move_tail(&pc->lru, &mz->lists[lru]);
}
void mem_cgroup_rotate_lru_list(struct page *page, enum lru_list lru)
{
struct mem_cgroup_per_zone *mz;
struct page_cgroup *pc;
if (mem_cgroup_disabled())
return;
pc = lookup_page_cgroup(page);
if (!PageCgroupUsed(pc))
return;
smp_rmb();
if (mem_cgroup_is_root(pc->mem_cgroup))
return;
mz = page_cgroup_zoneinfo(pc->mem_cgroup, page);
list_move(&pc->lru, &mz->lists[lru]);
}
void mem_cgroup_add_lru_list(struct page *page, enum lru_list lru)
{
struct page_cgroup *pc;
struct mem_cgroup_per_zone *mz;
if (mem_cgroup_disabled())
return;
pc = lookup_page_cgroup(page);
VM_BUG_ON(PageCgroupAcctLRU(pc));
if (!PageCgroupUsed(pc))
return;
smp_rmb();
mz = page_cgroup_zoneinfo(pc->mem_cgroup, page);
MEM_CGROUP_ZSTAT(mz, lru) += 1 << compound_order(page);
SetPageCgroupAcctLRU(pc);
if (mem_cgroup_is_root(pc->mem_cgroup))
return;
list_add(&pc->lru, &mz->lists[lru]);
}
static void mem_cgroup_lru_del_before_commit(struct page *page)
{
unsigned long flags;
struct zone *zone = page_zone(page);
struct page_cgroup *pc = lookup_page_cgroup(page);
if (likely(!PageLRU(page)))
return;
spin_lock_irqsave(&zone->lru_lock, flags);
if (!PageCgroupUsed(pc))
mem_cgroup_del_lru_list(page, page_lru(page));
spin_unlock_irqrestore(&zone->lru_lock, flags);
}
static void mem_cgroup_lru_add_after_commit(struct page *page)
{
unsigned long flags;
struct zone *zone = page_zone(page);
struct page_cgroup *pc = lookup_page_cgroup(page);
if (likely(!PageLRU(page)))
return;
spin_lock_irqsave(&zone->lru_lock, flags);
if (PageLRU(page) && !PageCgroupAcctLRU(pc))
mem_cgroup_add_lru_list(page, page_lru(page));
spin_unlock_irqrestore(&zone->lru_lock, flags);
}
void mem_cgroup_move_lists(struct page *page,
enum lru_list from, enum lru_list to)
{
if (mem_cgroup_disabled())
return;
mem_cgroup_del_lru_list(page, from);
mem_cgroup_add_lru_list(page, to);
}
static bool mem_cgroup_same_or_subtree(const struct mem_cgroup *root_mem,
struct mem_cgroup *mem)
{
if (root_mem != mem) {
return (root_mem->use_hierarchy &&
css_is_ancestor(&mem->css, &root_mem->css));
}
return true;
}
int task_in_mem_cgroup(struct task_struct *task, const struct mem_cgroup *mem)
{
int ret;
struct mem_cgroup *curr = NULL;
struct task_struct *p;
p = find_lock_task_mm(task);
if (!p)
return 0;
curr = try_get_mem_cgroup_from_mm(p->mm);
task_unlock(p);
if (!curr)
return 0;
ret = mem_cgroup_same_or_subtree(mem, curr);
css_put(&curr->css);
return ret;
}
static int calc_inactive_ratio(struct mem_cgroup *memcg, unsigned long *present_pages)
{
unsigned long active;
unsigned long inactive;
unsigned long gb;
unsigned long inactive_ratio;
inactive = mem_cgroup_nr_lru_pages(memcg, BIT(LRU_INACTIVE_ANON));
active = mem_cgroup_nr_lru_pages(memcg, BIT(LRU_ACTIVE_ANON));
gb = (inactive + active) >> (30 - PAGE_SHIFT);
if (gb)
inactive_ratio = int_sqrt(10 * gb);
else
inactive_ratio = 1;
if (present_pages) {
present_pages[0] = inactive;
present_pages[1] = active;
}
return inactive_ratio;
}
int mem_cgroup_inactive_anon_is_low(struct mem_cgroup *memcg)
{
unsigned long active;
unsigned long inactive;
unsigned long present_pages[2];
unsigned long inactive_ratio;
inactive_ratio = calc_inactive_ratio(memcg, present_pages);
inactive = present_pages[0];
active = present_pages[1];
if (inactive * inactive_ratio < active)
return 1;
return 0;
}
int mem_cgroup_inactive_file_is_low(struct mem_cgroup *memcg)
{
unsigned long active;
unsigned long inactive;
inactive = mem_cgroup_nr_lru_pages(memcg, BIT(LRU_INACTIVE_FILE));
active = mem_cgroup_nr_lru_pages(memcg, BIT(LRU_ACTIVE_FILE));
return (active > inactive);
}
struct zone_reclaim_stat *mem_cgroup_get_reclaim_stat(struct mem_cgroup *memcg,
struct zone *zone)
{
int nid = zone_to_nid(zone);
int zid = zone_idx(zone);
struct mem_cgroup_per_zone *mz = mem_cgroup_zoneinfo(memcg, nid, zid);
return &mz->reclaim_stat;
}
struct zone_reclaim_stat *
mem_cgroup_get_reclaim_stat_from_page(struct page *page)
{
struct page_cgroup *pc;
struct mem_cgroup_per_zone *mz;
if (mem_cgroup_disabled())
return NULL;
pc = lookup_page_cgroup(page);
if (!PageCgroupUsed(pc))
return NULL;
smp_rmb();
mz = page_cgroup_zoneinfo(pc->mem_cgroup, page);
return &mz->reclaim_stat;
}
unsigned long mem_cgroup_isolate_pages(unsigned long nr_to_scan,
struct list_head *dst,
unsigned long *scanned, int order,
int mode, struct zone *z,
struct mem_cgroup *mem_cont,
int active, int file)
{
unsigned long nr_taken = 0;
struct page *page;
unsigned long scan;
LIST_HEAD(pc_list);
struct list_head *src;
struct page_cgroup *pc, *tmp;
int nid = zone_to_nid(z);
int zid = zone_idx(z);
struct mem_cgroup_per_zone *mz;
int lru = LRU_FILE * file + active;
int ret;
BUG_ON(!mem_cont);
mz = mem_cgroup_zoneinfo(mem_cont, nid, zid);
src = &mz->lists[lru];
scan = 0;
list_for_each_entry_safe_reverse(pc, tmp, src, lru) {
if (scan >= nr_to_scan)
break;
if (unlikely(!PageCgroupUsed(pc)))
continue;
page = lookup_cgroup_page(pc);
if (unlikely(!PageLRU(page)))
continue;
scan++;
ret = __isolate_lru_page(page, mode, file);
switch (ret) {
case 0:
list_move(&page->lru, dst);
mem_cgroup_del_lru(page);
nr_taken += hpage_nr_pages(page);
break;
case -EBUSY:
mem_cgroup_rotate_lru_list(page, page_lru(page));
break;
default:
break;
}
}
*scanned = scan;
trace_mm_vmscan_memcg_isolate(0, nr_to_scan, scan, nr_taken,
0, 0, 0, mode);
return nr_taken;
}
static unsigned long mem_cgroup_margin(struct mem_cgroup *mem)
{
unsigned long long margin;
margin = res_counter_margin(&mem->res);
if (do_swap_account)
margin = min(margin, res_counter_margin(&mem->memsw));
return margin >> PAGE_SHIFT;
}
int mem_cgroup_swappiness(struct mem_cgroup *memcg)
{
struct cgroup *cgrp = memcg->css.cgroup;
if (cgrp->parent == NULL)
return vm_swappiness;
return memcg->swappiness;
}
static void mem_cgroup_start_move(struct mem_cgroup *mem)
{
int cpu;
get_online_cpus();
spin_lock(&mem->pcp_counter_lock);
for_each_online_cpu(cpu)
per_cpu(mem->stat->count[MEM_CGROUP_ON_MOVE], cpu) += 1;
mem->nocpu_base.count[MEM_CGROUP_ON_MOVE] += 1;
spin_unlock(&mem->pcp_counter_lock);
put_online_cpus();
synchronize_rcu();
}
static void mem_cgroup_end_move(struct mem_cgroup *mem)
{
int cpu;
if (!mem)
return;
get_online_cpus();
spin_lock(&mem->pcp_counter_lock);
for_each_online_cpu(cpu)
per_cpu(mem->stat->count[MEM_CGROUP_ON_MOVE], cpu) -= 1;
mem->nocpu_base.count[MEM_CGROUP_ON_MOVE] -= 1;
spin_unlock(&mem->pcp_counter_lock);
put_online_cpus();
}
static bool mem_cgroup_stealed(struct mem_cgroup *mem)
{
VM_BUG_ON(!rcu_read_lock_held());
return this_cpu_read(mem->stat->count[MEM_CGROUP_ON_MOVE]) > 0;
}
static bool mem_cgroup_under_move(struct mem_cgroup *mem)
{
struct mem_cgroup *from;
struct mem_cgroup *to;
bool ret = false;
spin_lock(&mc.lock);
from = mc.from;
to = mc.to;
if (!from)
goto unlock;
ret = mem_cgroup_same_or_subtree(mem, from)
|| mem_cgroup_same_or_subtree(mem, to);
unlock:
spin_unlock(&mc.lock);
return ret;
}
static bool mem_cgroup_wait_acct_move(struct mem_cgroup *mem)
{
if (mc.moving_task && current != mc.moving_task) {
if (mem_cgroup_under_move(mem)) {
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
struct cgroup *task_cgrp;
struct cgroup *mem_cgrp;
static char memcg_name[PATH_MAX];
int ret;
if (!memcg || !p)
return;
rcu_read_lock();
mem_cgrp = memcg->css.cgroup;
task_cgrp = task_cgroup(p, mem_cgroup_subsys_id);
ret = cgroup_path(task_cgrp, memcg_name, PATH_MAX);
if (ret < 0) {
rcu_read_unlock();
goto done;
}
rcu_read_unlock();
printk(KERN_INFO "Task in %s killed", memcg_name);
rcu_read_lock();
ret = cgroup_path(mem_cgrp, memcg_name, PATH_MAX);
if (ret < 0) {
rcu_read_unlock();
goto done;
}
rcu_read_unlock();
printk(KERN_CONT " as a result of limit of %s\n", memcg_name);
done:
printk(KERN_INFO "memory: usage %llukB, limit %llukB, failcnt %llu\n",
res_counter_read_u64(&memcg->res, RES_USAGE) >> 10,
res_counter_read_u64(&memcg->res, RES_LIMIT) >> 10,
res_counter_read_u64(&memcg->res, RES_FAILCNT));
printk(KERN_INFO "memory+swap: usage %llukB, limit %llukB, "
"failcnt %llu\n",
res_counter_read_u64(&memcg->memsw, RES_USAGE) >> 10,
res_counter_read_u64(&memcg->memsw, RES_LIMIT) >> 10,
res_counter_read_u64(&memcg->memsw, RES_FAILCNT));
}
static int mem_cgroup_count_children(struct mem_cgroup *mem)
{
int num = 0;
struct mem_cgroup *iter;
for_each_mem_cgroup_tree(iter, mem)
num++;
return num;
}
u64 mem_cgroup_get_limit(struct mem_cgroup *memcg)
{
u64 limit;
u64 memsw;
limit = res_counter_read_u64(&memcg->res, RES_LIMIT);
limit += total_swap_pages << PAGE_SHIFT;
memsw = res_counter_read_u64(&memcg->memsw, RES_LIMIT);
return min(limit, memsw);
}
static struct mem_cgroup *
mem_cgroup_select_victim(struct mem_cgroup *root_mem)
{
struct mem_cgroup *ret = NULL;
struct cgroup_subsys_state *css;
int nextid, found;
if (!root_mem->use_hierarchy) {
css_get(&root_mem->css);
ret = root_mem;
}
while (!ret) {
rcu_read_lock();
nextid = root_mem->last_scanned_child + 1;
css = css_get_next(&mem_cgroup_subsys, nextid, &root_mem->css,
&found);
if (css && css_tryget(css))
ret = container_of(css, struct mem_cgroup, css);
rcu_read_unlock();
if (!css) {
root_mem->last_scanned_child = 0;
} else
root_mem->last_scanned_child = found;
}
return ret;
}
static bool test_mem_cgroup_node_reclaimable(struct mem_cgroup *mem,
int nid, bool noswap)
{
if (mem_cgroup_node_nr_lru_pages(mem, nid, LRU_ALL_FILE))
return true;
if (noswap || !total_swap_pages)
return false;
if (mem_cgroup_node_nr_lru_pages(mem, nid, LRU_ALL_ANON))
return true;
return false;
}
static void mem_cgroup_may_update_nodemask(struct mem_cgroup *mem)
{
int nid;
if (!atomic_read(&mem->numainfo_events))
return;
if (atomic_inc_return(&mem->numainfo_updating) > 1)
return;
mem->scan_nodes = node_states[N_HIGH_MEMORY];
for_each_node_mask(nid, node_states[N_HIGH_MEMORY]) {
if (!test_mem_cgroup_node_reclaimable(mem, nid, false))
node_clear(nid, mem->scan_nodes);
}
atomic_set(&mem->numainfo_events, 0);
atomic_set(&mem->numainfo_updating, 0);
}
int mem_cgroup_select_victim_node(struct mem_cgroup *mem)
{
int node;
mem_cgroup_may_update_nodemask(mem);
node = mem->last_scanned_node;
node = next_node(node, mem->scan_nodes);
if (node == MAX_NUMNODES)
node = first_node(mem->scan_nodes);
if (unlikely(node == MAX_NUMNODES))
node = numa_node_id();
mem->last_scanned_node = node;
return node;
}
bool mem_cgroup_reclaimable(struct mem_cgroup *mem, bool noswap)
{
int nid;
if (!nodes_empty(mem->scan_nodes)) {
for (nid = first_node(mem->scan_nodes);
nid < MAX_NUMNODES;
nid = next_node(nid, mem->scan_nodes)) {
if (test_mem_cgroup_node_reclaimable(mem, nid, noswap))
return true;
}
}
for_each_node_state(nid, N_HIGH_MEMORY) {
if (node_isset(nid, mem->scan_nodes))
continue;
if (test_mem_cgroup_node_reclaimable(mem, nid, noswap))
return true;
}
return false;
}
int mem_cgroup_select_victim_node(struct mem_cgroup *mem)
{
return 0;
}
bool mem_cgroup_reclaimable(struct mem_cgroup *mem, bool noswap)
{
return test_mem_cgroup_node_reclaimable(mem, 0, noswap);
}
static int mem_cgroup_hierarchical_reclaim(struct mem_cgroup *root_mem,
struct zone *zone,
gfp_t gfp_mask,
unsigned long reclaim_options,
unsigned long *total_scanned)
{
struct mem_cgroup *victim;
int ret, total = 0;
int loop = 0;
bool noswap = reclaim_options & MEM_CGROUP_RECLAIM_NOSWAP;
bool shrink = reclaim_options & MEM_CGROUP_RECLAIM_SHRINK;
bool check_soft = reclaim_options & MEM_CGROUP_RECLAIM_SOFT;
unsigned long excess;
unsigned long nr_scanned;
excess = res_counter_soft_limit_excess(&root_mem->res) >> PAGE_SHIFT;
if (!check_soft && !shrink && root_mem->memsw_is_minimum)
noswap = true;
while (1) {
victim = mem_cgroup_select_victim(root_mem);
if (victim == root_mem) {
loop++;
if (!check_soft && loop >= 1)
drain_all_stock_async(root_mem);
if (loop >= 2) {
if (!check_soft || !total) {
css_put(&victim->css);
break;
}
if (total >= (excess >> 2) ||
(loop > MEM_CGROUP_MAX_RECLAIM_LOOPS)) {
css_put(&victim->css);
break;
}
}
}
if (!mem_cgroup_reclaimable(victim, noswap)) {
css_put(&victim->css);
continue;
}
if (check_soft) {
ret = mem_cgroup_shrink_node_zone(victim, gfp_mask,
noswap, zone, &nr_scanned);
*total_scanned += nr_scanned;
} else
ret = try_to_free_mem_cgroup_pages(victim, gfp_mask,
noswap);
css_put(&victim->css);
if (shrink)
return ret;
total += ret;
if (check_soft) {
if (!res_counter_soft_limit_excess(&root_mem->res))
return total;
} else if (mem_cgroup_margin(root_mem))
return total;
}
return total;
}
static bool mem_cgroup_oom_lock(struct mem_cgroup *mem)
{
struct mem_cgroup *iter, *failed = NULL;
bool cond = true;
for_each_mem_cgroup_tree_cond(iter, mem, cond) {
if (iter->oom_lock) {
failed = iter;
cond = false;
} else
iter->oom_lock = true;
}
if (!failed)
return true;
cond = true;
for_each_mem_cgroup_tree_cond(iter, mem, cond) {
if (iter == failed) {
cond = false;
continue;
}
iter->oom_lock = false;
}
return false;
}
static int mem_cgroup_oom_unlock(struct mem_cgroup *mem)
{
struct mem_cgroup *iter;
for_each_mem_cgroup_tree(iter, mem)
iter->oom_lock = false;
return 0;
}
static void mem_cgroup_mark_under_oom(struct mem_cgroup *mem)
{
struct mem_cgroup *iter;
for_each_mem_cgroup_tree(iter, mem)
atomic_inc(&iter->under_oom);
}
static void mem_cgroup_unmark_under_oom(struct mem_cgroup *mem)
{
struct mem_cgroup *iter;
for_each_mem_cgroup_tree(iter, mem)
atomic_add_unless(&iter->under_oom, -1, 0);
}
static int memcg_oom_wake_function(wait_queue_t *wait,
unsigned mode, int sync, void *arg)
{
struct mem_cgroup *wake_mem = (struct mem_cgroup *)arg,
*oom_wait_mem;
struct oom_wait_info *oom_wait_info;
oom_wait_info = container_of(wait, struct oom_wait_info, wait);
oom_wait_mem = oom_wait_info->mem;
if (!mem_cgroup_same_or_subtree(oom_wait_mem, wake_mem)
&& !mem_cgroup_same_or_subtree(wake_mem, oom_wait_mem))
return 0;
return autoremove_wake_function(wait, mode, sync, arg);
}
static void memcg_wakeup_oom(struct mem_cgroup *mem)
{
__wake_up(&memcg_oom_waitq, TASK_NORMAL, 0, mem);
}
static void memcg_oom_recover(struct mem_cgroup *mem)
{
if (mem && atomic_read(&mem->under_oom))
memcg_wakeup_oom(mem);
}
bool mem_cgroup_handle_oom(struct mem_cgroup *mem, gfp_t mask)
{
struct oom_wait_info owait;
bool locked, need_to_kill;
owait.mem = mem;
owait.wait.flags = 0;
owait.wait.func = memcg_oom_wake_function;
owait.wait.private = current;
INIT_LIST_HEAD(&owait.wait.task_list);
need_to_kill = true;
mem_cgroup_mark_under_oom(mem);
spin_lock(&memcg_oom_lock);
locked = mem_cgroup_oom_lock(mem);
prepare_to_wait(&memcg_oom_waitq, &owait.wait, TASK_KILLABLE);
if (!locked || mem->oom_kill_disable)
need_to_kill = false;
if (locked)
mem_cgroup_oom_notify(mem);
spin_unlock(&memcg_oom_lock);
if (need_to_kill) {
finish_wait(&memcg_oom_waitq, &owait.wait);
mem_cgroup_out_of_memory(mem, mask);
} else {
schedule();
finish_wait(&memcg_oom_waitq, &owait.wait);
}
spin_lock(&memcg_oom_lock);
if (locked)
mem_cgroup_oom_unlock(mem);
memcg_wakeup_oom(mem);
spin_unlock(&memcg_oom_lock);
mem_cgroup_unmark_under_oom(mem);
if (test_thread_flag(TIF_MEMDIE) || fatal_signal_pending(current))
return false;
schedule_timeout(1);
return true;
}
void mem_cgroup_update_page_stat(struct page *page,
enum mem_cgroup_page_stat_item idx, int val)
{
struct mem_cgroup *mem;
struct page_cgroup *pc = lookup_page_cgroup(page);
bool need_unlock = false;
unsigned long uninitialized_var(flags);
if (unlikely(!pc))
return;
rcu_read_lock();
mem = pc->mem_cgroup;
if (unlikely(!mem || !PageCgroupUsed(pc)))
goto out;
if (unlikely(mem_cgroup_stealed(mem)) || PageTransHuge(page)) {
move_lock_page_cgroup(pc, &flags);
need_unlock = true;
mem = pc->mem_cgroup;
if (!mem || !PageCgroupUsed(pc))
goto out;
}
switch (idx) {
case MEMCG_NR_FILE_MAPPED:
if (val > 0)
SetPageCgroupFileMapped(pc);
else if (!page_mapped(page))
ClearPageCgroupFileMapped(pc);
idx = MEM_CGROUP_STAT_FILE_MAPPED;
break;
default:
BUG();
}
this_cpu_add(mem->stat->count[idx], val);
out:
if (unlikely(need_unlock))
move_unlock_page_cgroup(pc, &flags);
rcu_read_unlock();
return;
}
static bool consume_stock(struct mem_cgroup *mem)
{
struct memcg_stock_pcp *stock;
bool ret = true;
stock = &get_cpu_var(memcg_stock);
if (mem == stock->cached && stock->nr_pages)
stock->nr_pages--;
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
struct memcg_stock_pcp *stock = &__get_cpu_var(memcg_stock);
drain_stock(stock);
clear_bit(FLUSHING_CACHED_CHARGE, &stock->flags);
}
static void refill_stock(struct mem_cgroup *mem, unsigned int nr_pages)
{
struct memcg_stock_pcp *stock = &get_cpu_var(memcg_stock);
if (stock->cached != mem) {
drain_stock(stock);
stock->cached = mem;
}
stock->nr_pages += nr_pages;
put_cpu_var(memcg_stock);
}
static void drain_all_stock(struct mem_cgroup *root_mem, bool sync)
{
int cpu, curcpu;
get_online_cpus();
curcpu = get_cpu();
for_each_online_cpu(cpu) {
struct memcg_stock_pcp *stock = &per_cpu(memcg_stock, cpu);
struct mem_cgroup *mem;
mem = stock->cached;
if (!mem || !stock->nr_pages)
continue;
if (!mem_cgroup_same_or_subtree(root_mem, mem))
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
static void drain_all_stock_async(struct mem_cgroup *root_mem)
{
if (!mutex_trylock(&percpu_charge_mutex))
return;
drain_all_stock(root_mem, false);
mutex_unlock(&percpu_charge_mutex);
}
static void drain_all_stock_sync(struct mem_cgroup *root_mem)
{
mutex_lock(&percpu_charge_mutex);
drain_all_stock(root_mem, true);
mutex_unlock(&percpu_charge_mutex);
}
static void mem_cgroup_drain_pcp_counter(struct mem_cgroup *mem, int cpu)
{
int i;
spin_lock(&mem->pcp_counter_lock);
for (i = 0; i < MEM_CGROUP_STAT_DATA; i++) {
long x = per_cpu(mem->stat->count[i], cpu);
per_cpu(mem->stat->count[i], cpu) = 0;
mem->nocpu_base.count[i] += x;
}
for (i = 0; i < MEM_CGROUP_EVENTS_NSTATS; i++) {
unsigned long x = per_cpu(mem->stat->events[i], cpu);
per_cpu(mem->stat->events[i], cpu) = 0;
mem->nocpu_base.events[i] += x;
}
per_cpu(mem->stat->count[MEM_CGROUP_ON_MOVE], cpu) = 0;
spin_unlock(&mem->pcp_counter_lock);
}
static void synchronize_mem_cgroup_on_move(struct mem_cgroup *mem, int cpu)
{
int idx = MEM_CGROUP_ON_MOVE;
spin_lock(&mem->pcp_counter_lock);
per_cpu(mem->stat->count[idx], cpu) = mem->nocpu_base.count[idx];
spin_unlock(&mem->pcp_counter_lock);
}
static int __cpuinit memcg_cpu_hotplug_callback(struct notifier_block *nb,
unsigned long action,
void *hcpu)
{
int cpu = (unsigned long)hcpu;
struct memcg_stock_pcp *stock;
struct mem_cgroup *iter;
if ((action == CPU_ONLINE)) {
for_each_mem_cgroup_all(iter)
synchronize_mem_cgroup_on_move(iter, cpu);
return NOTIFY_OK;
}
if ((action != CPU_DEAD) || action != CPU_DEAD_FROZEN)
return NOTIFY_OK;
for_each_mem_cgroup_all(iter)
mem_cgroup_drain_pcp_counter(iter, cpu);
stock = &per_cpu(memcg_stock, cpu);
drain_stock(stock);
return NOTIFY_OK;
}
static int mem_cgroup_do_charge(struct mem_cgroup *mem, gfp_t gfp_mask,
unsigned int nr_pages, bool oom_check)
{
unsigned long csize = nr_pages * PAGE_SIZE;
struct mem_cgroup *mem_over_limit;
struct res_counter *fail_res;
unsigned long flags = 0;
int ret;
ret = res_counter_charge(&mem->res, csize, &fail_res);
if (likely(!ret)) {
if (!do_swap_account)
return CHARGE_OK;
ret = res_counter_charge(&mem->memsw, csize, &fail_res);
if (likely(!ret))
return CHARGE_OK;
res_counter_uncharge(&mem->res, csize);
mem_over_limit = mem_cgroup_from_res_counter(fail_res, memsw);
flags |= MEM_CGROUP_RECLAIM_NOSWAP;
} else
mem_over_limit = mem_cgroup_from_res_counter(fail_res, res);
if (nr_pages == CHARGE_BATCH)
return CHARGE_RETRY;
if (!(gfp_mask & __GFP_WAIT))
return CHARGE_WOULDBLOCK;
ret = mem_cgroup_hierarchical_reclaim(mem_over_limit, NULL,
gfp_mask, flags, NULL);
if (mem_cgroup_margin(mem_over_limit) >= nr_pages)
return CHARGE_RETRY;
if (nr_pages == 1 && ret)
return CHARGE_RETRY;
if (mem_cgroup_wait_acct_move(mem_over_limit))
return CHARGE_RETRY;
if (!oom_check)
return CHARGE_NOMEM;
if (!mem_cgroup_handle_oom(mem_over_limit, gfp_mask))
return CHARGE_OOM_DIE;
return CHARGE_RETRY;
}
static int __mem_cgroup_try_charge(struct mm_struct *mm,
gfp_t gfp_mask,
unsigned int nr_pages,
struct mem_cgroup **memcg,
bool oom)
{
unsigned int batch = max(CHARGE_BATCH, nr_pages);
int nr_oom_retries = MEM_CGROUP_RECLAIM_RETRIES;
struct mem_cgroup *mem = NULL;
int ret;
if (unlikely(test_thread_flag(TIF_MEMDIE)
|| fatal_signal_pending(current)))
goto bypass;
if (!*memcg && !mm)
goto bypass;
again:
if (*memcg) {
mem = *memcg;
VM_BUG_ON(css_is_removed(&mem->css));
if (mem_cgroup_is_root(mem))
goto done;
if (nr_pages == 1 && consume_stock(mem))
goto done;
css_get(&mem->css);
} else {
struct task_struct *p;
rcu_read_lock();
p = rcu_dereference(mm->owner);
mem = mem_cgroup_from_task(p);
if (!mem || mem_cgroup_is_root(mem)) {
rcu_read_unlock();
goto done;
}
if (nr_pages == 1 && consume_stock(mem)) {
rcu_read_unlock();
goto done;
}
if (!css_tryget(&mem->css)) {
rcu_read_unlock();
goto again;
}
rcu_read_unlock();
}
do {
bool oom_check;
if (fatal_signal_pending(current)) {
css_put(&mem->css);
goto bypass;
}
oom_check = false;
if (oom && !nr_oom_retries) {
oom_check = true;
nr_oom_retries = MEM_CGROUP_RECLAIM_RETRIES;
}
ret = mem_cgroup_do_charge(mem, gfp_mask, batch, oom_check);
switch (ret) {
case CHARGE_OK:
break;
case CHARGE_RETRY:
batch = nr_pages;
css_put(&mem->css);
mem = NULL;
goto again;
case CHARGE_WOULDBLOCK:
css_put(&mem->css);
goto nomem;
case CHARGE_NOMEM:
if (!oom) {
css_put(&mem->css);
goto nomem;
}
nr_oom_retries--;
break;
case CHARGE_OOM_DIE:
css_put(&mem->css);
goto bypass;
}
} while (ret != CHARGE_OK);
if (batch > nr_pages)
refill_stock(mem, batch - nr_pages);
css_put(&mem->css);
done:
*memcg = mem;
return 0;
nomem:
*memcg = NULL;
return -ENOMEM;
bypass:
*memcg = NULL;
return 0;
}
static void __mem_cgroup_cancel_charge(struct mem_cgroup *mem,
unsigned int nr_pages)
{
if (!mem_cgroup_is_root(mem)) {
unsigned long bytes = nr_pages * PAGE_SIZE;
res_counter_uncharge(&mem->res, bytes);
if (do_swap_account)
res_counter_uncharge(&mem->memsw, bytes);
}
}
static struct mem_cgroup *mem_cgroup_lookup(unsigned short id)
{
struct cgroup_subsys_state *css;
if (!id)
return NULL;
css = css_lookup(&mem_cgroup_subsys, id);
if (!css)
return NULL;
return container_of(css, struct mem_cgroup, css);
}
struct mem_cgroup *try_get_mem_cgroup_from_page(struct page *page)
{
struct mem_cgroup *mem = NULL;
struct page_cgroup *pc;
unsigned short id;
swp_entry_t ent;
VM_BUG_ON(!PageLocked(page));
pc = lookup_page_cgroup(page);
lock_page_cgroup(pc);
if (PageCgroupUsed(pc)) {
mem = pc->mem_cgroup;
if (mem && !css_tryget(&mem->css))
mem = NULL;
} else if (PageSwapCache(page)) {
ent.val = page_private(page);
id = lookup_swap_cgroup(ent);
rcu_read_lock();
mem = mem_cgroup_lookup(id);
if (mem && !css_tryget(&mem->css))
mem = NULL;
rcu_read_unlock();
}
unlock_page_cgroup(pc);
return mem;
}
static void __mem_cgroup_commit_charge(struct mem_cgroup *mem,
struct page *page,
unsigned int nr_pages,
struct page_cgroup *pc,
enum charge_type ctype)
{
lock_page_cgroup(pc);
if (unlikely(PageCgroupUsed(pc))) {
unlock_page_cgroup(pc);
__mem_cgroup_cancel_charge(mem, nr_pages);
return;
}
pc->mem_cgroup = mem;
smp_wmb();
switch (ctype) {
case MEM_CGROUP_CHARGE_TYPE_CACHE:
case MEM_CGROUP_CHARGE_TYPE_SHMEM:
SetPageCgroupCache(pc);
SetPageCgroupUsed(pc);
break;
case MEM_CGROUP_CHARGE_TYPE_MAPPED:
ClearPageCgroupCache(pc);
SetPageCgroupUsed(pc);
break;
default:
break;
}
mem_cgroup_charge_statistics(mem, PageCgroupCache(pc), nr_pages);
unlock_page_cgroup(pc);
memcg_check_events(mem, page);
}
void mem_cgroup_split_huge_fixup(struct page *head, struct page *tail)
{
struct page_cgroup *head_pc = lookup_page_cgroup(head);
struct page_cgroup *tail_pc = lookup_page_cgroup(tail);
unsigned long flags;
if (mem_cgroup_disabled())
return;
move_lock_page_cgroup(head_pc, &flags);
tail_pc->mem_cgroup = head_pc->mem_cgroup;
smp_wmb();
if (PageCgroupAcctLRU(head_pc)) {
enum lru_list lru;
struct mem_cgroup_per_zone *mz;
lru = page_lru(head);
mz = page_cgroup_zoneinfo(head_pc->mem_cgroup, head);
MEM_CGROUP_ZSTAT(mz, lru) -= 1;
}
tail_pc->flags = head_pc->flags & ~PCGF_NOCOPY_AT_SPLIT;
move_unlock_page_cgroup(head_pc, &flags);
}
static int mem_cgroup_move_account(struct page *page,
unsigned int nr_pages,
struct page_cgroup *pc,
struct mem_cgroup *from,
struct mem_cgroup *to,
bool uncharge)
{
unsigned long flags;
int ret;
VM_BUG_ON(from == to);
VM_BUG_ON(PageLRU(page));
ret = -EBUSY;
if (nr_pages > 1 && !PageTransHuge(page))
goto out;
lock_page_cgroup(pc);
ret = -EINVAL;
if (!PageCgroupUsed(pc) || pc->mem_cgroup != from)
goto unlock;
move_lock_page_cgroup(pc, &flags);
if (PageCgroupFileMapped(pc)) {
preempt_disable();
__this_cpu_dec(from->stat->count[MEM_CGROUP_STAT_FILE_MAPPED]);
__this_cpu_inc(to->stat->count[MEM_CGROUP_STAT_FILE_MAPPED]);
preempt_enable();
}
mem_cgroup_charge_statistics(from, PageCgroupCache(pc), -nr_pages);
if (uncharge)
__mem_cgroup_cancel_charge(from, nr_pages);
pc->mem_cgroup = to;
mem_cgroup_charge_statistics(to, PageCgroupCache(pc), nr_pages);
move_unlock_page_cgroup(pc, &flags);
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
struct mem_cgroup *child,
gfp_t gfp_mask)
{
struct cgroup *cg = child->css.cgroup;
struct cgroup *pcg = cg->parent;
struct mem_cgroup *parent;
unsigned int nr_pages;
unsigned long uninitialized_var(flags);
int ret;
if (!pcg)
return -EINVAL;
ret = -EBUSY;
if (!get_page_unless_zero(page))
goto out;
if (isolate_lru_page(page))
goto put;
nr_pages = hpage_nr_pages(page);
parent = mem_cgroup_from_cont(pcg);
ret = __mem_cgroup_try_charge(NULL, gfp_mask, nr_pages, &parent, false);
if (ret || !parent)
goto put_back;
if (nr_pages > 1)
flags = compound_lock_irqsave(page);
ret = mem_cgroup_move_account(page, nr_pages, pc, child, parent, true);
if (ret)
__mem_cgroup_cancel_charge(parent, nr_pages);
if (nr_pages > 1)
compound_unlock_irqrestore(page, flags);
put_back:
putback_lru_page(page);
put:
put_page(page);
out:
return ret;
}
static int mem_cgroup_charge_common(struct page *page, struct mm_struct *mm,
gfp_t gfp_mask, enum charge_type ctype)
{
struct mem_cgroup *mem = NULL;
unsigned int nr_pages = 1;
struct page_cgroup *pc;
bool oom = true;
int ret;
if (PageTransHuge(page)) {
nr_pages <<= compound_order(page);
VM_BUG_ON(!PageTransHuge(page));
oom = false;
}
pc = lookup_page_cgroup(page);
BUG_ON(!pc);
ret = __mem_cgroup_try_charge(mm, gfp_mask, nr_pages, &mem, oom);
if (ret || !mem)
return ret;
__mem_cgroup_commit_charge(mem, page, nr_pages, pc, ctype);
return 0;
}
int mem_cgroup_newpage_charge(struct page *page,
struct mm_struct *mm, gfp_t gfp_mask)
{
if (mem_cgroup_disabled())
return 0;
if (page_mapped(page) || (page->mapping && !PageAnon(page)))
return 0;
if (unlikely(!mm))
mm = &init_mm;
return mem_cgroup_charge_common(page, mm, gfp_mask,
MEM_CGROUP_CHARGE_TYPE_MAPPED);
}
static void
__mem_cgroup_commit_charge_lrucare(struct page *page, struct mem_cgroup *mem,
enum charge_type ctype)
{
struct page_cgroup *pc = lookup_page_cgroup(page);
mem_cgroup_lru_del_before_commit(page);
__mem_cgroup_commit_charge(mem, page, 1, pc, ctype);
mem_cgroup_lru_add_after_commit(page);
return;
}
int mem_cgroup_cache_charge(struct page *page, struct mm_struct *mm,
gfp_t gfp_mask)
{
struct mem_cgroup *mem = NULL;
int ret;
if (mem_cgroup_disabled())
return 0;
if (PageCompound(page))
return 0;
if (unlikely(!mm))
mm = &init_mm;
if (page_is_file_cache(page)) {
ret = __mem_cgroup_try_charge(mm, gfp_mask, 1, &mem, true);
if (ret || !mem)
return ret;
__mem_cgroup_commit_charge_lrucare(page, mem,
MEM_CGROUP_CHARGE_TYPE_CACHE);
return ret;
}
if (PageSwapCache(page)) {
ret = mem_cgroup_try_charge_swapin(mm, page, gfp_mask, &mem);
if (!ret)
__mem_cgroup_commit_charge_swapin(page, mem,
MEM_CGROUP_CHARGE_TYPE_SHMEM);
} else
ret = mem_cgroup_charge_common(page, mm, gfp_mask,
MEM_CGROUP_CHARGE_TYPE_SHMEM);
return ret;
}
int mem_cgroup_try_charge_swapin(struct mm_struct *mm,
struct page *page,
gfp_t mask, struct mem_cgroup **ptr)
{
struct mem_cgroup *mem;
int ret;
*ptr = NULL;
if (mem_cgroup_disabled())
return 0;
if (!do_swap_account)
goto charge_cur_mm;
if (!PageSwapCache(page))
goto charge_cur_mm;
mem = try_get_mem_cgroup_from_page(page);
if (!mem)
goto charge_cur_mm;
*ptr = mem;
ret = __mem_cgroup_try_charge(NULL, mask, 1, ptr, true);
css_put(&mem->css);
return ret;
charge_cur_mm:
if (unlikely(!mm))
mm = &init_mm;
return __mem_cgroup_try_charge(mm, mask, 1, ptr, true);
}
static void
__mem_cgroup_commit_charge_swapin(struct page *page, struct mem_cgroup *ptr,
enum charge_type ctype)
{
if (mem_cgroup_disabled())
return;
if (!ptr)
return;
cgroup_exclude_rmdir(&ptr->css);
__mem_cgroup_commit_charge_lrucare(page, ptr, ctype);
if (do_swap_account && PageSwapCache(page)) {
swp_entry_t ent = {.val = page_private(page)};
unsigned short id;
struct mem_cgroup *memcg;
id = swap_cgroup_record(ent, 0);
rcu_read_lock();
memcg = mem_cgroup_lookup(id);
if (memcg) {
if (!mem_cgroup_is_root(memcg))
res_counter_uncharge(&memcg->memsw, PAGE_SIZE);
mem_cgroup_swap_statistics(memcg, false);
mem_cgroup_put(memcg);
}
rcu_read_unlock();
}
cgroup_release_and_wakeup_rmdir(&ptr->css);
}
void mem_cgroup_commit_charge_swapin(struct page *page, struct mem_cgroup *ptr)
{
__mem_cgroup_commit_charge_swapin(page, ptr,
MEM_CGROUP_CHARGE_TYPE_MAPPED);
}
void mem_cgroup_cancel_charge_swapin(struct mem_cgroup *mem)
{
if (mem_cgroup_disabled())
return;
if (!mem)
return;
__mem_cgroup_cancel_charge(mem, 1);
}
static void mem_cgroup_do_uncharge(struct mem_cgroup *mem,
unsigned int nr_pages,
const enum charge_type ctype)
{
struct memcg_batch_info *batch = NULL;
bool uncharge_memsw = true;
if (!do_swap_account || ctype == MEM_CGROUP_CHARGE_TYPE_SWAPOUT)
uncharge_memsw = false;
batch = &current->memcg_batch;
if (!batch->memcg)
batch->memcg = mem;
if (!batch->do_batch || test_thread_flag(TIF_MEMDIE))
goto direct_uncharge;
if (nr_pages > 1)
goto direct_uncharge;
if (batch->memcg != mem)
goto direct_uncharge;
batch->nr_pages++;
if (uncharge_memsw)
batch->memsw_nr_pages++;
return;
direct_uncharge:
res_counter_uncharge(&mem->res, nr_pages * PAGE_SIZE);
if (uncharge_memsw)
res_counter_uncharge(&mem->memsw, nr_pages * PAGE_SIZE);
if (unlikely(batch->memcg != mem))
memcg_oom_recover(mem);
return;
}
static struct mem_cgroup *
__mem_cgroup_uncharge_common(struct page *page, enum charge_type ctype)
{
struct mem_cgroup *mem = NULL;
unsigned int nr_pages = 1;
struct page_cgroup *pc;
if (mem_cgroup_disabled())
return NULL;
if (PageSwapCache(page))
return NULL;
if (PageTransHuge(page)) {
nr_pages <<= compound_order(page);
VM_BUG_ON(!PageTransHuge(page));
}
pc = lookup_page_cgroup(page);
if (unlikely(!pc || !PageCgroupUsed(pc)))
return NULL;
lock_page_cgroup(pc);
mem = pc->mem_cgroup;
if (!PageCgroupUsed(pc))
goto unlock_out;
switch (ctype) {
case MEM_CGROUP_CHARGE_TYPE_MAPPED:
case MEM_CGROUP_CHARGE_TYPE_DROP:
if (page_mapped(page) || PageCgroupMigration(pc))
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
mem_cgroup_charge_statistics(mem, PageCgroupCache(pc), -nr_pages);
ClearPageCgroupUsed(pc);
unlock_page_cgroup(pc);
memcg_check_events(mem, page);
if (do_swap_account && ctype == MEM_CGROUP_CHARGE_TYPE_SWAPOUT) {
mem_cgroup_swap_statistics(mem, true);
mem_cgroup_get(mem);
}
if (!mem_cgroup_is_root(mem))
mem_cgroup_do_uncharge(mem, nr_pages, ctype);
return mem;
unlock_out:
unlock_page_cgroup(pc);
return NULL;
}
void mem_cgroup_uncharge_page(struct page *page)
{
if (page_mapped(page))
return;
if (page->mapping && !PageAnon(page))
return;
__mem_cgroup_uncharge_common(page, MEM_CGROUP_CHARGE_TYPE_MAPPED);
}
void mem_cgroup_uncharge_cache_page(struct page *page)
{
VM_BUG_ON(page_mapped(page));
VM_BUG_ON(page->mapping);
__mem_cgroup_uncharge_common(page, MEM_CGROUP_CHARGE_TYPE_CACHE);
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
memcg = __mem_cgroup_uncharge_common(page, ctype);
if (do_swap_account && swapout && memcg)
swap_cgroup_record(ent, css_id(&memcg->css));
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
mem_cgroup_put(memcg);
}
rcu_read_unlock();
}
static int mem_cgroup_move_swap_account(swp_entry_t entry,
struct mem_cgroup *from, struct mem_cgroup *to, bool need_fixup)
{
unsigned short old_id, new_id;
old_id = css_id(&from->css);
new_id = css_id(&to->css);
if (swap_cgroup_cmpxchg(entry, old_id, new_id) == old_id) {
mem_cgroup_swap_statistics(from, false);
mem_cgroup_swap_statistics(to, true);
mem_cgroup_get(to);
if (need_fixup) {
if (!mem_cgroup_is_root(from))
res_counter_uncharge(&from->memsw, PAGE_SIZE);
mem_cgroup_put(from);
if (!mem_cgroup_is_root(to))
res_counter_uncharge(&to->res, PAGE_SIZE);
}
return 0;
}
return -EINVAL;
}
static inline int mem_cgroup_move_swap_account(swp_entry_t entry,
struct mem_cgroup *from, struct mem_cgroup *to, bool need_fixup)
{
return -EINVAL;
}
int mem_cgroup_prepare_migration(struct page *page,
struct page *newpage, struct mem_cgroup **ptr, gfp_t gfp_mask)
{
struct mem_cgroup *mem = NULL;
struct page_cgroup *pc;
enum charge_type ctype;
int ret = 0;
*ptr = NULL;
VM_BUG_ON(PageTransHuge(page));
if (mem_cgroup_disabled())
return 0;
pc = lookup_page_cgroup(page);
lock_page_cgroup(pc);
if (PageCgroupUsed(pc)) {
mem = pc->mem_cgroup;
css_get(&mem->css);
if (PageAnon(page))
SetPageCgroupMigration(pc);
}
unlock_page_cgroup(pc);
if (!mem)
return 0;
*ptr = mem;
ret = __mem_cgroup_try_charge(NULL, gfp_mask, 1, ptr, false);
css_put(&mem->css);
if (ret || *ptr == NULL) {
if (PageAnon(page)) {
lock_page_cgroup(pc);
ClearPageCgroupMigration(pc);
unlock_page_cgroup(pc);
mem_cgroup_uncharge_page(page);
}
return -ENOMEM;
}
pc = lookup_page_cgroup(newpage);
if (PageAnon(page))
ctype = MEM_CGROUP_CHARGE_TYPE_MAPPED;
else if (page_is_file_cache(page))
ctype = MEM_CGROUP_CHARGE_TYPE_CACHE;
else
ctype = MEM_CGROUP_CHARGE_TYPE_SHMEM;
__mem_cgroup_commit_charge(mem, page, 1, pc, ctype);
return ret;
}
void mem_cgroup_end_migration(struct mem_cgroup *mem,
struct page *oldpage, struct page *newpage, bool migration_ok)
{
struct page *used, *unused;
struct page_cgroup *pc;
if (!mem)
return;
cgroup_exclude_rmdir(&mem->css);
if (!migration_ok) {
used = oldpage;
unused = newpage;
} else {
used = newpage;
unused = oldpage;
}
pc = lookup_page_cgroup(oldpage);
lock_page_cgroup(pc);
ClearPageCgroupMigration(pc);
unlock_page_cgroup(pc);
__mem_cgroup_uncharge_common(unused, MEM_CGROUP_CHARGE_TYPE_FORCE);
if (PageAnon(used))
mem_cgroup_uncharge_page(used);
cgroup_release_and_wakeup_rmdir(&mem->css);
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
int ret = -1;
char *path;
printk(KERN_ALERT "pc:%p pc->flags:%lx pc->mem_cgroup:%p",
pc, pc->flags, pc->mem_cgroup);
path = kmalloc(PATH_MAX, GFP_KERNEL);
if (path) {
rcu_read_lock();
ret = cgroup_path(pc->mem_cgroup->css.cgroup,
path, PATH_MAX);
rcu_read_unlock();
}
printk(KERN_CONT "(%s)\n",
(ret < 0) ? "cannot get the path" : path);
kfree(path);
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
mem_cgroup_hierarchical_reclaim(memcg, NULL, GFP_KERNEL,
MEM_CGROUP_RECLAIM_SHRINK,
NULL);
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
mem_cgroup_hierarchical_reclaim(memcg, NULL, GFP_KERNEL,
MEM_CGROUP_RECLAIM_NOSWAP |
MEM_CGROUP_RECLAIM_SHRINK,
NULL);
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
reclaimed = mem_cgroup_hierarchical_reclaim(mz->mem, zone,
gfp_mask,
MEM_CGROUP_RECLAIM_SOFT,
&nr_scanned);
nr_reclaimed += reclaimed;
*total_scanned += nr_scanned;
spin_lock(&mctz->lock);
next_mz = NULL;
if (!reclaimed) {
do {
next_mz =
__mem_cgroup_largest_soft_limit_node(mctz);
if (next_mz == mz)
css_put(&next_mz->mem->css);
else
break;
} while (1);
}
__mem_cgroup_remove_exceeded(mz->mem, mz, mctz);
excess = res_counter_soft_limit_excess(&mz->mem->res);
__mem_cgroup_insert_exceeded(mz->mem, mz, mctz, excess);
spin_unlock(&mctz->lock);
css_put(&mz->mem->css);
loop++;
if (!nr_reclaimed &&
(next_mz == NULL ||
loop > MEM_CGROUP_MAX_SOFT_LIMIT_RECLAIM_LOOPS))
break;
} while (!nr_reclaimed);
if (next_mz)
css_put(&next_mz->mem->css);
return nr_reclaimed;
}
static int mem_cgroup_force_empty_list(struct mem_cgroup *mem,
int node, int zid, enum lru_list lru)
{
struct zone *zone;
struct mem_cgroup_per_zone *mz;
struct page_cgroup *pc, *busy;
unsigned long flags, loop;
struct list_head *list;
int ret = 0;
zone = &NODE_DATA(node)->node_zones[zid];
mz = mem_cgroup_zoneinfo(mem, node, zid);
list = &mz->lists[lru];
loop = MEM_CGROUP_ZSTAT(mz, lru);
loop += 256;
busy = NULL;
while (loop--) {
struct page *page;
ret = 0;
spin_lock_irqsave(&zone->lru_lock, flags);
if (list_empty(list)) {
spin_unlock_irqrestore(&zone->lru_lock, flags);
break;
}
pc = list_entry(list->prev, struct page_cgroup, lru);
if (busy == pc) {
list_move(&pc->lru, list);
busy = NULL;
spin_unlock_irqrestore(&zone->lru_lock, flags);
continue;
}
spin_unlock_irqrestore(&zone->lru_lock, flags);
page = lookup_cgroup_page(pc);
ret = mem_cgroup_move_parent(page, pc, mem, GFP_KERNEL);
if (ret == -ENOMEM)
break;
if (ret == -EBUSY || ret == -EINVAL) {
busy = pc;
cond_resched();
} else
busy = NULL;
}
if (!ret && !list_empty(list))
return -EBUSY;
return ret;
}
static int mem_cgroup_force_empty(struct mem_cgroup *mem, bool free_all)
{
int ret;
int node, zid, shrink;
int nr_retries = MEM_CGROUP_RECLAIM_RETRIES;
struct cgroup *cgrp = mem->css.cgroup;
css_get(&mem->css);
shrink = 0;
if (free_all)
goto try_to_free;
move_account:
do {
ret = -EBUSY;
if (cgroup_task_count(cgrp) || !list_empty(&cgrp->children))
goto out;
ret = -EINTR;
if (signal_pending(current))
goto out;
lru_add_drain_all();
drain_all_stock_sync(mem);
ret = 0;
mem_cgroup_start_move(mem);
for_each_node_state(node, N_HIGH_MEMORY) {
for (zid = 0; !ret && zid < MAX_NR_ZONES; zid++) {
enum lru_list l;
for_each_lru(l) {
ret = mem_cgroup_force_empty_list(mem,
node, zid, l);
if (ret)
break;
}
}
if (ret)
break;
}
mem_cgroup_end_move(mem);
memcg_oom_recover(mem);
if (ret == -ENOMEM)
goto try_to_free;
cond_resched();
} while (mem->res.usage > 0 || ret);
out:
css_put(&mem->css);
return ret;
try_to_free:
if (cgroup_task_count(cgrp) || !list_empty(&cgrp->children) || shrink) {
ret = -EBUSY;
goto out;
}
lru_add_drain_all();
shrink = 1;
while (nr_retries && mem->res.usage > 0) {
int progress;
if (signal_pending(current)) {
ret = -EINTR;
goto out;
}
progress = try_to_free_mem_cgroup_pages(mem, GFP_KERNEL,
false);
if (!progress) {
nr_retries--;
congestion_wait(BLK_RW_ASYNC, HZ/10);
}
}
lru_add_drain();
goto move_account;
}
int mem_cgroup_force_empty_write(struct cgroup *cont, unsigned int event)
{
return mem_cgroup_force_empty(mem_cgroup_from_cont(cont), true);
}
static u64 mem_cgroup_hierarchy_read(struct cgroup *cont, struct cftype *cft)
{
return mem_cgroup_from_cont(cont)->use_hierarchy;
}
static int mem_cgroup_hierarchy_write(struct cgroup *cont, struct cftype *cft,
u64 val)
{
int retval = 0;
struct mem_cgroup *mem = mem_cgroup_from_cont(cont);
struct cgroup *parent = cont->parent;
struct mem_cgroup *parent_mem = NULL;
if (parent)
parent_mem = mem_cgroup_from_cont(parent);
cgroup_lock();
if ((!parent_mem || !parent_mem->use_hierarchy) &&
(val == 1 || val == 0)) {
if (list_empty(&cont->children))
mem->use_hierarchy = val;
else
retval = -EBUSY;
} else
retval = -EINVAL;
cgroup_unlock();
return retval;
}
static unsigned long mem_cgroup_recursive_stat(struct mem_cgroup *mem,
enum mem_cgroup_stat_index idx)
{
struct mem_cgroup *iter;
long val = 0;
for_each_mem_cgroup_tree(iter, mem)
val += mem_cgroup_read_stat(iter, idx);
if (val < 0)
val = 0;
return val;
}
static inline u64 mem_cgroup_usage(struct mem_cgroup *mem, bool swap)
{
u64 val;
if (!mem_cgroup_is_root(mem)) {
if (!swap)
return res_counter_read_u64(&mem->res, RES_USAGE);
else
return res_counter_read_u64(&mem->memsw, RES_USAGE);
}
val = mem_cgroup_recursive_stat(mem, MEM_CGROUP_STAT_CACHE);
val += mem_cgroup_recursive_stat(mem, MEM_CGROUP_STAT_RSS);
if (swap)
val += mem_cgroup_recursive_stat(mem, MEM_CGROUP_STAT_SWAPOUT);
return val << PAGE_SHIFT;
}
static u64 mem_cgroup_read(struct cgroup *cont, struct cftype *cft)
{
struct mem_cgroup *mem = mem_cgroup_from_cont(cont);
u64 val;
int type, name;
type = MEMFILE_TYPE(cft->private);
name = MEMFILE_ATTR(cft->private);
switch (type) {
case _MEM:
if (name == RES_USAGE)
val = mem_cgroup_usage(mem, false);
else
val = res_counter_read_u64(&mem->res, name);
break;
case _MEMSWAP:
if (name == RES_USAGE)
val = mem_cgroup_usage(mem, true);
else
val = res_counter_read_u64(&mem->memsw, name);
break;
default:
BUG();
break;
}
return val;
}
static int mem_cgroup_write(struct cgroup *cont, struct cftype *cft,
const char *buffer)
{
struct mem_cgroup *memcg = mem_cgroup_from_cont(cont);
int type, name;
unsigned long long val;
int ret;
type = MEMFILE_TYPE(cft->private);
name = MEMFILE_ATTR(cft->private);
switch (name) {
case RES_LIMIT:
if (mem_cgroup_is_root(memcg)) {
ret = -EINVAL;
break;
}
ret = res_counter_memparse_write_strategy(buffer, &val);
if (ret)
break;
if (type == _MEM)
ret = mem_cgroup_resize_limit(memcg, val);
else
ret = mem_cgroup_resize_memsw_limit(memcg, val);
break;
case RES_SOFT_LIMIT:
ret = res_counter_memparse_write_strategy(buffer, &val);
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
return ret;
}
static void memcg_get_hierarchical_limit(struct mem_cgroup *memcg,
unsigned long long *mem_limit, unsigned long long *memsw_limit)
{
struct cgroup *cgroup;
unsigned long long min_limit, min_memsw_limit, tmp;
min_limit = res_counter_read_u64(&memcg->res, RES_LIMIT);
min_memsw_limit = res_counter_read_u64(&memcg->memsw, RES_LIMIT);
cgroup = memcg->css.cgroup;
if (!memcg->use_hierarchy)
goto out;
while (cgroup->parent) {
cgroup = cgroup->parent;
memcg = mem_cgroup_from_cont(cgroup);
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
return;
}
static int mem_cgroup_reset(struct cgroup *cont, unsigned int event)
{
struct mem_cgroup *mem;
int type, name;
mem = mem_cgroup_from_cont(cont);
type = MEMFILE_TYPE(event);
name = MEMFILE_ATTR(event);
switch (name) {
case RES_MAX_USAGE:
if (type == _MEM)
res_counter_reset_max(&mem->res);
else
res_counter_reset_max(&mem->memsw);
break;
case RES_FAILCNT:
if (type == _MEM)
res_counter_reset_failcnt(&mem->res);
else
res_counter_reset_failcnt(&mem->memsw);
break;
}
return 0;
}
static u64 mem_cgroup_move_charge_read(struct cgroup *cgrp,
struct cftype *cft)
{
return mem_cgroup_from_cont(cgrp)->move_charge_at_immigrate;
}
static int mem_cgroup_move_charge_write(struct cgroup *cgrp,
struct cftype *cft, u64 val)
{
struct mem_cgroup *mem = mem_cgroup_from_cont(cgrp);
if (val >= (1 << NR_MOVE_TYPE))
return -EINVAL;
cgroup_lock();
mem->move_charge_at_immigrate = val;
cgroup_unlock();
return 0;
}
static int mem_cgroup_move_charge_write(struct cgroup *cgrp,
struct cftype *cft, u64 val)
{
return -ENOSYS;
}
static void
mem_cgroup_get_local_stat(struct mem_cgroup *mem, struct mcs_total_stat *s)
{
s64 val;
val = mem_cgroup_read_stat(mem, MEM_CGROUP_STAT_CACHE);
s->stat[MCS_CACHE] += val * PAGE_SIZE;
val = mem_cgroup_read_stat(mem, MEM_CGROUP_STAT_RSS);
s->stat[MCS_RSS] += val * PAGE_SIZE;
val = mem_cgroup_read_stat(mem, MEM_CGROUP_STAT_FILE_MAPPED);
s->stat[MCS_FILE_MAPPED] += val * PAGE_SIZE;
val = mem_cgroup_read_events(mem, MEM_CGROUP_EVENTS_PGPGIN);
s->stat[MCS_PGPGIN] += val;
val = mem_cgroup_read_events(mem, MEM_CGROUP_EVENTS_PGPGOUT);
s->stat[MCS_PGPGOUT] += val;
if (do_swap_account) {
val = mem_cgroup_read_stat(mem, MEM_CGROUP_STAT_SWAPOUT);
s->stat[MCS_SWAP] += val * PAGE_SIZE;
}
val = mem_cgroup_read_events(mem, MEM_CGROUP_EVENTS_PGFAULT);
s->stat[MCS_PGFAULT] += val;
val = mem_cgroup_read_events(mem, MEM_CGROUP_EVENTS_PGMAJFAULT);
s->stat[MCS_PGMAJFAULT] += val;
val = mem_cgroup_nr_lru_pages(mem, BIT(LRU_INACTIVE_ANON));
s->stat[MCS_INACTIVE_ANON] += val * PAGE_SIZE;
val = mem_cgroup_nr_lru_pages(mem, BIT(LRU_ACTIVE_ANON));
s->stat[MCS_ACTIVE_ANON] += val * PAGE_SIZE;
val = mem_cgroup_nr_lru_pages(mem, BIT(LRU_INACTIVE_FILE));
s->stat[MCS_INACTIVE_FILE] += val * PAGE_SIZE;
val = mem_cgroup_nr_lru_pages(mem, BIT(LRU_ACTIVE_FILE));
s->stat[MCS_ACTIVE_FILE] += val * PAGE_SIZE;
val = mem_cgroup_nr_lru_pages(mem, BIT(LRU_UNEVICTABLE));
s->stat[MCS_UNEVICTABLE] += val * PAGE_SIZE;
}
static void
mem_cgroup_get_total_stat(struct mem_cgroup *mem, struct mcs_total_stat *s)
{
struct mem_cgroup *iter;
for_each_mem_cgroup_tree(iter, mem)
mem_cgroup_get_local_stat(iter, s);
}
static int mem_control_numa_stat_show(struct seq_file *m, void *arg)
{
int nid;
unsigned long total_nr, file_nr, anon_nr, unevictable_nr;
unsigned long node_nr;
struct cgroup *cont = m->private;
struct mem_cgroup *mem_cont = mem_cgroup_from_cont(cont);
total_nr = mem_cgroup_nr_lru_pages(mem_cont, LRU_ALL);
seq_printf(m, "total=%lu", total_nr);
for_each_node_state(nid, N_HIGH_MEMORY) {
node_nr = mem_cgroup_node_nr_lru_pages(mem_cont, nid, LRU_ALL);
seq_printf(m, " N%d=%lu", nid, node_nr);
}
seq_putc(m, '\n');
file_nr = mem_cgroup_nr_lru_pages(mem_cont, LRU_ALL_FILE);
seq_printf(m, "file=%lu", file_nr);
for_each_node_state(nid, N_HIGH_MEMORY) {
node_nr = mem_cgroup_node_nr_lru_pages(mem_cont, nid,
LRU_ALL_FILE);
seq_printf(m, " N%d=%lu", nid, node_nr);
}
seq_putc(m, '\n');
anon_nr = mem_cgroup_nr_lru_pages(mem_cont, LRU_ALL_ANON);
seq_printf(m, "anon=%lu", anon_nr);
for_each_node_state(nid, N_HIGH_MEMORY) {
node_nr = mem_cgroup_node_nr_lru_pages(mem_cont, nid,
LRU_ALL_ANON);
seq_printf(m, " N%d=%lu", nid, node_nr);
}
seq_putc(m, '\n');
unevictable_nr = mem_cgroup_nr_lru_pages(mem_cont, BIT(LRU_UNEVICTABLE));
seq_printf(m, "unevictable=%lu", unevictable_nr);
for_each_node_state(nid, N_HIGH_MEMORY) {
node_nr = mem_cgroup_node_nr_lru_pages(mem_cont, nid,
BIT(LRU_UNEVICTABLE));
seq_printf(m, " N%d=%lu", nid, node_nr);
}
seq_putc(m, '\n');
return 0;
}
static int mem_control_stat_show(struct cgroup *cont, struct cftype *cft,
struct cgroup_map_cb *cb)
{
struct mem_cgroup *mem_cont = mem_cgroup_from_cont(cont);
struct mcs_total_stat mystat;
int i;
memset(&mystat, 0, sizeof(mystat));
mem_cgroup_get_local_stat(mem_cont, &mystat);
for (i = 0; i < NR_MCS_STAT; i++) {
if (i == MCS_SWAP && !do_swap_account)
continue;
cb->fill(cb, memcg_stat_strings[i].local_name, mystat.stat[i]);
}
{
unsigned long long limit, memsw_limit;
memcg_get_hierarchical_limit(mem_cont, &limit, &memsw_limit);
cb->fill(cb, "hierarchical_memory_limit", limit);
if (do_swap_account)
cb->fill(cb, "hierarchical_memsw_limit", memsw_limit);
}
memset(&mystat, 0, sizeof(mystat));
mem_cgroup_get_total_stat(mem_cont, &mystat);
for (i = 0; i < NR_MCS_STAT; i++) {
if (i == MCS_SWAP && !do_swap_account)
continue;
cb->fill(cb, memcg_stat_strings[i].total_name, mystat.stat[i]);
}
#ifdef CONFIG_DEBUG_VM
cb->fill(cb, "inactive_ratio", calc_inactive_ratio(mem_cont, NULL));
{
int nid, zid;
struct mem_cgroup_per_zone *mz;
unsigned long recent_rotated[2] = {0, 0};
unsigned long recent_scanned[2] = {0, 0};
for_each_online_node(nid)
for (zid = 0; zid < MAX_NR_ZONES; zid++) {
mz = mem_cgroup_zoneinfo(mem_cont, nid, zid);
recent_rotated[0] +=
mz->reclaim_stat.recent_rotated[0];
recent_rotated[1] +=
mz->reclaim_stat.recent_rotated[1];
recent_scanned[0] +=
mz->reclaim_stat.recent_scanned[0];
recent_scanned[1] +=
mz->reclaim_stat.recent_scanned[1];
}
cb->fill(cb, "recent_rotated_anon", recent_rotated[0]);
cb->fill(cb, "recent_rotated_file", recent_rotated[1]);
cb->fill(cb, "recent_scanned_anon", recent_scanned[0]);
cb->fill(cb, "recent_scanned_file", recent_scanned[1]);
}
#endif
return 0;
}
static u64 mem_cgroup_swappiness_read(struct cgroup *cgrp, struct cftype *cft)
{
struct mem_cgroup *memcg = mem_cgroup_from_cont(cgrp);
return mem_cgroup_swappiness(memcg);
}
static int mem_cgroup_swappiness_write(struct cgroup *cgrp, struct cftype *cft,
u64 val)
{
struct mem_cgroup *memcg = mem_cgroup_from_cont(cgrp);
struct mem_cgroup *parent;
if (val > 100)
return -EINVAL;
if (cgrp->parent == NULL)
return -EINVAL;
parent = mem_cgroup_from_cont(cgrp->parent);
cgroup_lock();
if ((parent->use_hierarchy) ||
(memcg->use_hierarchy && !list_empty(&cgrp->children))) {
cgroup_unlock();
return -EINVAL;
}
memcg->swappiness = val;
cgroup_unlock();
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
return _a->threshold - _b->threshold;
}
static int mem_cgroup_oom_notify_cb(struct mem_cgroup *mem)
{
struct mem_cgroup_eventfd_list *ev;
list_for_each_entry(ev, &mem->oom_notify, list)
eventfd_signal(ev->eventfd, 1);
return 0;
}
static void mem_cgroup_oom_notify(struct mem_cgroup *mem)
{
struct mem_cgroup *iter;
for_each_mem_cgroup_tree(iter, mem)
mem_cgroup_oom_notify_cb(iter);
}
static int mem_cgroup_usage_register_event(struct cgroup *cgrp,
struct cftype *cft, struct eventfd_ctx *eventfd, const char *args)
{
struct mem_cgroup *memcg = mem_cgroup_from_cont(cgrp);
struct mem_cgroup_thresholds *thresholds;
struct mem_cgroup_threshold_ary *new;
int type = MEMFILE_TYPE(cft->private);
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
if (new->entries[i].threshold < usage) {
++new->current_threshold;
}
}
kfree(thresholds->spare);
thresholds->spare = thresholds->primary;
rcu_assign_pointer(thresholds->primary, new);
synchronize_rcu();
unlock:
mutex_unlock(&memcg->thresholds_lock);
return ret;
}
static void mem_cgroup_usage_unregister_event(struct cgroup *cgrp,
struct cftype *cft, struct eventfd_ctx *eventfd)
{
struct mem_cgroup *memcg = mem_cgroup_from_cont(cgrp);
struct mem_cgroup_thresholds *thresholds;
struct mem_cgroup_threshold_ary *new;
int type = MEMFILE_TYPE(cft->private);
u64 usage;
int i, j, size;
mutex_lock(&memcg->thresholds_lock);
if (type == _MEM)
thresholds = &memcg->thresholds;
else if (type == _MEMSWAP)
thresholds = &memcg->memsw_thresholds;
else
BUG();
BUG_ON(!thresholds);
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
if (new->entries[j].threshold < usage) {
++new->current_threshold;
}
j++;
}
swap_buffers:
thresholds->spare = thresholds->primary;
rcu_assign_pointer(thresholds->primary, new);
synchronize_rcu();
mutex_unlock(&memcg->thresholds_lock);
}
static int mem_cgroup_oom_register_event(struct cgroup *cgrp,
struct cftype *cft, struct eventfd_ctx *eventfd, const char *args)
{
struct mem_cgroup *memcg = mem_cgroup_from_cont(cgrp);
struct mem_cgroup_eventfd_list *event;
int type = MEMFILE_TYPE(cft->private);
BUG_ON(type != _OOM_TYPE);
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
static void mem_cgroup_oom_unregister_event(struct cgroup *cgrp,
struct cftype *cft, struct eventfd_ctx *eventfd)
{
struct mem_cgroup *mem = mem_cgroup_from_cont(cgrp);
struct mem_cgroup_eventfd_list *ev, *tmp;
int type = MEMFILE_TYPE(cft->private);
BUG_ON(type != _OOM_TYPE);
spin_lock(&memcg_oom_lock);
list_for_each_entry_safe(ev, tmp, &mem->oom_notify, list) {
if (ev->eventfd == eventfd) {
list_del(&ev->list);
kfree(ev);
}
}
spin_unlock(&memcg_oom_lock);
}
static int mem_cgroup_oom_control_read(struct cgroup *cgrp,
struct cftype *cft, struct cgroup_map_cb *cb)
{
struct mem_cgroup *mem = mem_cgroup_from_cont(cgrp);
cb->fill(cb, "oom_kill_disable", mem->oom_kill_disable);
if (atomic_read(&mem->under_oom))
cb->fill(cb, "under_oom", 1);
else
cb->fill(cb, "under_oom", 0);
return 0;
}
static int mem_cgroup_oom_control_write(struct cgroup *cgrp,
struct cftype *cft, u64 val)
{
struct mem_cgroup *mem = mem_cgroup_from_cont(cgrp);
struct mem_cgroup *parent;
if (!cgrp->parent || !((val == 0) || (val == 1)))
return -EINVAL;
parent = mem_cgroup_from_cont(cgrp->parent);
cgroup_lock();
if ((parent->use_hierarchy) ||
(mem->use_hierarchy && !list_empty(&cgrp->children))) {
cgroup_unlock();
return -EINVAL;
}
mem->oom_kill_disable = val;
if (!val)
memcg_oom_recover(mem);
cgroup_unlock();
return 0;
}
static int mem_control_numa_stat_open(struct inode *unused, struct file *file)
{
struct cgroup *cont = file->f_dentry->d_parent->d_fsdata;
file->f_op = &mem_control_numa_stat_file_operations;
return single_open(file, mem_control_numa_stat_show, cont);
}
static int register_memsw_files(struct cgroup *cont, struct cgroup_subsys *ss)
{
if (!do_swap_account)
return 0;
return cgroup_add_files(cont, ss, memsw_cgroup_files,
ARRAY_SIZE(memsw_cgroup_files));
}
static int register_memsw_files(struct cgroup *cont, struct cgroup_subsys *ss)
{
return 0;
}
static int alloc_mem_cgroup_per_zone_info(struct mem_cgroup *mem, int node)
{
struct mem_cgroup_per_node *pn;
struct mem_cgroup_per_zone *mz;
enum lru_list l;
int zone, tmp = node;
if (!node_state(node, N_NORMAL_MEMORY))
tmp = -1;
pn = kzalloc_node(sizeof(*pn), GFP_KERNEL, tmp);
if (!pn)
return 1;
mem->info.nodeinfo[node] = pn;
for (zone = 0; zone < MAX_NR_ZONES; zone++) {
mz = &pn->zoneinfo[zone];
for_each_lru(l)
INIT_LIST_HEAD(&mz->lists[l]);
mz->usage_in_excess = 0;
mz->on_tree = false;
mz->mem = mem;
}
return 0;
}
static void free_mem_cgroup_per_zone_info(struct mem_cgroup *mem, int node)
{
kfree(mem->info.nodeinfo[node]);
}
static struct mem_cgroup *mem_cgroup_alloc(void)
{
struct mem_cgroup *mem;
int size = sizeof(struct mem_cgroup);
if (size < PAGE_SIZE)
mem = kzalloc(size, GFP_KERNEL);
else
mem = vzalloc(size);
if (!mem)
return NULL;
mem->stat = alloc_percpu(struct mem_cgroup_stat_cpu);
if (!mem->stat)
goto out_free;
spin_lock_init(&mem->pcp_counter_lock);
return mem;
out_free:
if (size < PAGE_SIZE)
kfree(mem);
else
vfree(mem);
return NULL;
}
static void __mem_cgroup_free(struct mem_cgroup *mem)
{
int node;
mem_cgroup_remove_from_trees(mem);
free_css_id(&mem_cgroup_subsys, &mem->css);
for_each_node_state(node, N_POSSIBLE)
free_mem_cgroup_per_zone_info(mem, node);
free_percpu(mem->stat);
if (sizeof(struct mem_cgroup) < PAGE_SIZE)
kfree(mem);
else
vfree(mem);
}
static void mem_cgroup_get(struct mem_cgroup *mem)
{
atomic_inc(&mem->refcnt);
}
static void __mem_cgroup_put(struct mem_cgroup *mem, int count)
{
if (atomic_sub_and_test(count, &mem->refcnt)) {
struct mem_cgroup *parent = parent_mem_cgroup(mem);
__mem_cgroup_free(mem);
if (parent)
mem_cgroup_put(parent);
}
}
static void mem_cgroup_put(struct mem_cgroup *mem)
{
__mem_cgroup_put(mem, 1);
}
static struct mem_cgroup *parent_mem_cgroup(struct mem_cgroup *mem)
{
if (!mem->res.parent)
return NULL;
return mem_cgroup_from_res_counter(mem->res.parent, res);
}
static void __init enable_swap_cgroup(void)
{
if (!mem_cgroup_disabled() && really_do_swap_account)
do_swap_account = 1;
}
static void __init enable_swap_cgroup(void)
{
}
static int mem_cgroup_soft_limit_tree_init(void)
{
struct mem_cgroup_tree_per_node *rtpn;
struct mem_cgroup_tree_per_zone *rtpz;
int tmp, node, zone;
for_each_node_state(node, N_POSSIBLE) {
tmp = node;
if (!node_state(node, N_NORMAL_MEMORY))
tmp = -1;
rtpn = kzalloc_node(sizeof(*rtpn), GFP_KERNEL, tmp);
if (!rtpn)
return 1;
soft_limit_tree.rb_tree_per_node[node] = rtpn;
for (zone = 0; zone < MAX_NR_ZONES; zone++) {
rtpz = &rtpn->rb_tree_per_zone[zone];
rtpz->rb_root = RB_ROOT;
spin_lock_init(&rtpz->lock);
}
}
return 0;
}
static struct cgroup_subsys_state * __ref
mem_cgroup_create(struct cgroup_subsys *ss, struct cgroup *cont)
{
struct mem_cgroup *mem, *parent;
long error = -ENOMEM;
int node;
mem = mem_cgroup_alloc();
if (!mem)
return ERR_PTR(error);
for_each_node_state(node, N_POSSIBLE)
if (alloc_mem_cgroup_per_zone_info(mem, node))
goto free_out;
if (cont->parent == NULL) {
int cpu;
enable_swap_cgroup();
parent = NULL;
root_mem_cgroup = mem;
if (mem_cgroup_soft_limit_tree_init())
goto free_out;
for_each_possible_cpu(cpu) {
struct memcg_stock_pcp *stock =
&per_cpu(memcg_stock, cpu);
INIT_WORK(&stock->work, drain_local_stock);
}
hotcpu_notifier(memcg_cpu_hotplug_callback, 0);
} else {
parent = mem_cgroup_from_cont(cont->parent);
mem->use_hierarchy = parent->use_hierarchy;
mem->oom_kill_disable = parent->oom_kill_disable;
}
if (parent && parent->use_hierarchy) {
res_counter_init(&mem->res, &parent->res);
res_counter_init(&mem->memsw, &parent->memsw);
mem_cgroup_get(parent);
} else {
res_counter_init(&mem->res, NULL);
res_counter_init(&mem->memsw, NULL);
}
mem->last_scanned_child = 0;
mem->last_scanned_node = MAX_NUMNODES;
INIT_LIST_HEAD(&mem->oom_notify);
if (parent)
mem->swappiness = mem_cgroup_swappiness(parent);
atomic_set(&mem->refcnt, 1);
mem->move_charge_at_immigrate = 0;
mutex_init(&mem->thresholds_lock);
return &mem->css;
free_out:
__mem_cgroup_free(mem);
root_mem_cgroup = NULL;
return ERR_PTR(error);
}
static int mem_cgroup_pre_destroy(struct cgroup_subsys *ss,
struct cgroup *cont)
{
struct mem_cgroup *mem = mem_cgroup_from_cont(cont);
return mem_cgroup_force_empty(mem, false);
}
static void mem_cgroup_destroy(struct cgroup_subsys *ss,
struct cgroup *cont)
{
struct mem_cgroup *mem = mem_cgroup_from_cont(cont);
mem_cgroup_put(mem);
}
static int mem_cgroup_populate(struct cgroup_subsys *ss,
struct cgroup *cont)
{
int ret;
ret = cgroup_add_files(cont, ss, mem_cgroup_files,
ARRAY_SIZE(mem_cgroup_files));
if (!ret)
ret = register_memsw_files(cont, ss);
return ret;
}
static int mem_cgroup_do_precharge(unsigned long count)
{
int ret = 0;
int batch_count = PRECHARGE_COUNT_AT_ONCE;
struct mem_cgroup *mem = mc.to;
if (mem_cgroup_is_root(mem)) {
mc.precharge += count;
return ret;
}
if (count > 1) {
struct res_counter *dummy;
if (res_counter_charge(&mem->res, PAGE_SIZE * count, &dummy))
goto one_by_one;
if (do_swap_account && res_counter_charge(&mem->memsw,
PAGE_SIZE * count, &dummy)) {
res_counter_uncharge(&mem->res, PAGE_SIZE * count);
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
ret = __mem_cgroup_try_charge(NULL, GFP_KERNEL, 1, &mem, false);
if (ret || !mem)
return -ENOMEM;
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
if (!move_anon() || page_mapcount(page) > 2)
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
int usage_count;
struct page *page = NULL;
swp_entry_t ent = pte_to_swp_entry(ptent);
if (!move_anon() || non_swap_entry(ent))
return NULL;
usage_count = mem_cgroup_count_swap_user(ent, &page);
if (usage_count > 1) {
if (page)
put_page(page);
return NULL;
}
if (do_swap_account)
entry->val = ent.val;
return page;
}
static struct page *mc_handle_file_pte(struct vm_area_struct *vma,
unsigned long addr, pte_t ptent, swp_entry_t *entry)
{
struct page *page = NULL;
struct inode *inode;
struct address_space *mapping;
pgoff_t pgoff;
if (!vma->vm_file)
return NULL;
if (!move_file())
return NULL;
inode = vma->vm_file->f_path.dentry->d_inode;
mapping = vma->vm_file->f_mapping;
if (pte_none(ptent))
pgoff = linear_page_index(vma, addr);
else
pgoff = pte_to_pgoff(ptent);
page = find_get_page(mapping, pgoff);
#ifdef CONFIG_SWAP
if (radix_tree_exceptional_entry(page)) {
swp_entry_t swap = radix_to_swp_entry(page);
if (do_swap_account)
*entry = swap;
page = find_get_page(&swapper_space, swap.val);
}
#endif
return page;
}
static int is_target_pte_for_mc(struct vm_area_struct *vma,
unsigned long addr, pte_t ptent, union mc_target *target)
{
struct page *page = NULL;
struct page_cgroup *pc;
int ret = 0;
swp_entry_t ent = { .val = 0 };
if (pte_present(ptent))
page = mc_handle_present_pte(vma, addr, ptent);
else if (is_swap_pte(ptent))
page = mc_handle_swap_pte(vma, addr, ptent, &ent);
else if (pte_none(ptent) || pte_file(ptent))
page = mc_handle_file_pte(vma, addr, ptent, &ent);
if (!page && !ent.val)
return 0;
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
css_id(&mc.from->css) == lookup_swap_cgroup(ent)) {
ret = MC_TARGET_SWAP;
if (target)
target->ent = ent;
}
return ret;
}
static int mem_cgroup_count_precharge_pte_range(pmd_t *pmd,
unsigned long addr, unsigned long end,
struct mm_walk *walk)
{
struct vm_area_struct *vma = walk->private;
pte_t *pte;
spinlock_t *ptl;
split_huge_page_pmd(walk->mm, pmd);
pte = pte_offset_map_lock(vma->vm_mm, pmd, addr, &ptl);
for (; addr != end; pte++, addr += PAGE_SIZE)
if (is_target_pte_for_mc(vma, addr, *pte, NULL))
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
__mem_cgroup_put(mc.from, mc.moved_swap);
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
static int mem_cgroup_can_attach(struct cgroup_subsys *ss,
struct cgroup *cgroup,
struct task_struct *p)
{
int ret = 0;
struct mem_cgroup *mem = mem_cgroup_from_cont(cgroup);
if (mem->move_charge_at_immigrate) {
struct mm_struct *mm;
struct mem_cgroup *from = mem_cgroup_from_task(p);
VM_BUG_ON(from == mem);
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
mc.to = mem;
spin_unlock(&mc.lock);
ret = mem_cgroup_precharge_mc(mm);
if (ret)
mem_cgroup_clear_mc();
}
mmput(mm);
}
return ret;
}
static void mem_cgroup_cancel_attach(struct cgroup_subsys *ss,
struct cgroup *cgroup,
struct task_struct *p)
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
split_huge_page_pmd(walk->mm, pmd);
retry:
pte = pte_offset_map_lock(vma->vm_mm, pmd, addr, &ptl);
for (; addr != end; addr += PAGE_SIZE) {
pte_t ptent = *(pte++);
union mc_target target;
int type;
struct page *page;
struct page_cgroup *pc;
swp_entry_t ent;
if (!mc.precharge)
break;
type = is_target_pte_for_mc(vma, addr, ptent, &target);
switch (type) {
case MC_TARGET_PAGE:
page = target.page;
if (isolate_lru_page(page))
goto put;
pc = lookup_page_cgroup(page);
if (!mem_cgroup_move_account(page, 1, pc,
mc.from, mc.to, false)) {
mc.precharge--;
mc.moved_charge++;
}
putback_lru_page(page);
put:
put_page(page);
break;
case MC_TARGET_SWAP:
ent = target.ent;
if (!mem_cgroup_move_swap_account(ent,
mc.from, mc.to, false)) {
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
static void mem_cgroup_move_task(struct cgroup_subsys *ss,
struct cgroup *cont,
struct cgroup *old_cont,
struct task_struct *p)
{
struct mm_struct *mm = get_task_mm(p);
if (mm) {
if (mc.to)
mem_cgroup_move_charge(mm);
put_swap_token(mm);
mmput(mm);
}
if (mc.to)
mem_cgroup_clear_mc();
}
static int mem_cgroup_can_attach(struct cgroup_subsys *ss,
struct cgroup *cgroup,
struct task_struct *p)
{
return 0;
}
static void mem_cgroup_cancel_attach(struct cgroup_subsys *ss,
struct cgroup *cgroup,
struct task_struct *p)
{
}
static void mem_cgroup_move_task(struct cgroup_subsys *ss,
struct cgroup *cont,
struct cgroup *old_cont,
struct task_struct *p)
{
}
static int __init enable_swap_account(char *s)
{
if (!strcmp(s, "1"))
really_do_swap_account = 1;
else if (!strcmp(s, "0"))
really_do_swap_account = 0;
return 1;
}
