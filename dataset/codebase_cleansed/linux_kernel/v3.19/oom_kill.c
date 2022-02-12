static bool has_intersects_mems_allowed(struct task_struct *start,
const nodemask_t *mask)
{
struct task_struct *tsk;
bool ret = false;
rcu_read_lock();
for_each_thread(start, tsk) {
if (mask) {
ret = mempolicy_nodemask_intersects(tsk, mask);
} else {
ret = cpuset_mems_allowed_intersects(current, tsk);
}
if (ret)
break;
}
rcu_read_unlock();
return ret;
}
static bool has_intersects_mems_allowed(struct task_struct *tsk,
const nodemask_t *mask)
{
return true;
}
struct task_struct *find_lock_task_mm(struct task_struct *p)
{
struct task_struct *t;
rcu_read_lock();
for_each_thread(p, t) {
task_lock(t);
if (likely(t->mm))
goto found;
task_unlock(t);
}
t = NULL;
found:
rcu_read_unlock();
return t;
}
static bool oom_unkillable_task(struct task_struct *p,
struct mem_cgroup *memcg, const nodemask_t *nodemask)
{
if (is_global_init(p))
return true;
if (p->flags & PF_KTHREAD)
return true;
if (memcg && !task_in_mem_cgroup(p, memcg))
return true;
if (!has_intersects_mems_allowed(p, nodemask))
return true;
return false;
}
unsigned long oom_badness(struct task_struct *p, struct mem_cgroup *memcg,
const nodemask_t *nodemask, unsigned long totalpages)
{
long points;
long adj;
if (oom_unkillable_task(p, memcg, nodemask))
return 0;
p = find_lock_task_mm(p);
if (!p)
return 0;
adj = (long)p->signal->oom_score_adj;
if (adj == OOM_SCORE_ADJ_MIN) {
task_unlock(p);
return 0;
}
points = get_mm_rss(p->mm) + atomic_long_read(&p->mm->nr_ptes) +
get_mm_counter(p->mm, MM_SWAPENTS);
task_unlock(p);
if (has_capability_noaudit(p, CAP_SYS_ADMIN))
points -= (points * 3) / 100;
adj *= totalpages / 1000;
points += adj;
return points > 0 ? points : 1;
}
static enum oom_constraint constrained_alloc(struct zonelist *zonelist,
gfp_t gfp_mask, nodemask_t *nodemask,
unsigned long *totalpages)
{
struct zone *zone;
struct zoneref *z;
enum zone_type high_zoneidx = gfp_zone(gfp_mask);
bool cpuset_limited = false;
int nid;
*totalpages = totalram_pages + total_swap_pages;
if (!zonelist)
return CONSTRAINT_NONE;
if (gfp_mask & __GFP_THISNODE)
return CONSTRAINT_NONE;
if (nodemask && !nodes_subset(node_states[N_MEMORY], *nodemask)) {
*totalpages = total_swap_pages;
for_each_node_mask(nid, *nodemask)
*totalpages += node_spanned_pages(nid);
return CONSTRAINT_MEMORY_POLICY;
}
for_each_zone_zonelist_nodemask(zone, z, zonelist,
high_zoneidx, nodemask)
if (!cpuset_zone_allowed(zone, gfp_mask))
cpuset_limited = true;
if (cpuset_limited) {
*totalpages = total_swap_pages;
for_each_node_mask(nid, cpuset_current_mems_allowed)
*totalpages += node_spanned_pages(nid);
return CONSTRAINT_CPUSET;
}
return CONSTRAINT_NONE;
}
static enum oom_constraint constrained_alloc(struct zonelist *zonelist,
gfp_t gfp_mask, nodemask_t *nodemask,
unsigned long *totalpages)
{
*totalpages = totalram_pages + total_swap_pages;
return CONSTRAINT_NONE;
}
enum oom_scan_t oom_scan_process_thread(struct task_struct *task,
unsigned long totalpages, const nodemask_t *nodemask,
bool force_kill)
{
if (oom_unkillable_task(task, NULL, nodemask))
return OOM_SCAN_CONTINUE;
if (test_tsk_thread_flag(task, TIF_MEMDIE)) {
if (unlikely(frozen(task)))
__thaw_task(task);
if (!force_kill)
return OOM_SCAN_ABORT;
}
if (!task->mm)
return OOM_SCAN_CONTINUE;
if (oom_task_origin(task))
return OOM_SCAN_SELECT;
if (task_will_free_mem(task) && !force_kill)
return OOM_SCAN_ABORT;
return OOM_SCAN_OK;
}
static struct task_struct *select_bad_process(unsigned int *ppoints,
unsigned long totalpages, const nodemask_t *nodemask,
bool force_kill)
{
struct task_struct *g, *p;
struct task_struct *chosen = NULL;
unsigned long chosen_points = 0;
rcu_read_lock();
for_each_process_thread(g, p) {
unsigned int points;
switch (oom_scan_process_thread(p, totalpages, nodemask,
force_kill)) {
case OOM_SCAN_SELECT:
chosen = p;
chosen_points = ULONG_MAX;
case OOM_SCAN_CONTINUE:
continue;
case OOM_SCAN_ABORT:
rcu_read_unlock();
return (struct task_struct *)(-1UL);
case OOM_SCAN_OK:
break;
};
points = oom_badness(p, NULL, nodemask, totalpages);
if (!points || points < chosen_points)
continue;
if (points == chosen_points && thread_group_leader(chosen))
continue;
chosen = p;
chosen_points = points;
}
if (chosen)
get_task_struct(chosen);
rcu_read_unlock();
*ppoints = chosen_points * 1000 / totalpages;
return chosen;
}
static void dump_tasks(struct mem_cgroup *memcg, const nodemask_t *nodemask)
{
struct task_struct *p;
struct task_struct *task;
pr_info("[ pid ] uid tgid total_vm rss nr_ptes swapents oom_score_adj name\n");
rcu_read_lock();
for_each_process(p) {
if (oom_unkillable_task(p, memcg, nodemask))
continue;
task = find_lock_task_mm(p);
if (!task) {
continue;
}
pr_info("[%5d] %5d %5d %8lu %8lu %7ld %8lu %5hd %s\n",
task->pid, from_kuid(&init_user_ns, task_uid(task)),
task->tgid, task->mm->total_vm, get_mm_rss(task->mm),
atomic_long_read(&task->mm->nr_ptes),
get_mm_counter(task->mm, MM_SWAPENTS),
task->signal->oom_score_adj, task->comm);
task_unlock(task);
}
rcu_read_unlock();
}
static void dump_header(struct task_struct *p, gfp_t gfp_mask, int order,
struct mem_cgroup *memcg, const nodemask_t *nodemask)
{
task_lock(current);
pr_warning("%s invoked oom-killer: gfp_mask=0x%x, order=%d, "
"oom_score_adj=%hd\n",
current->comm, gfp_mask, order,
current->signal->oom_score_adj);
cpuset_print_task_mems_allowed(current);
task_unlock(current);
dump_stack();
if (memcg)
mem_cgroup_print_oom_info(memcg, p);
else
show_mem(SHOW_MEM_FILTER_NODES);
if (sysctl_oom_dump_tasks)
dump_tasks(memcg, nodemask);
}
int oom_kills_count(void)
{
return atomic_read(&oom_kills);
}
void note_oom_kill(void)
{
atomic_inc(&oom_kills);
}
void oom_kill_process(struct task_struct *p, gfp_t gfp_mask, int order,
unsigned int points, unsigned long totalpages,
struct mem_cgroup *memcg, nodemask_t *nodemask,
const char *message)
{
struct task_struct *victim = p;
struct task_struct *child;
struct task_struct *t;
struct mm_struct *mm;
unsigned int victim_points = 0;
static DEFINE_RATELIMIT_STATE(oom_rs, DEFAULT_RATELIMIT_INTERVAL,
DEFAULT_RATELIMIT_BURST);
if (task_will_free_mem(p)) {
set_tsk_thread_flag(p, TIF_MEMDIE);
put_task_struct(p);
return;
}
if (__ratelimit(&oom_rs))
dump_header(p, gfp_mask, order, memcg, nodemask);
task_lock(p);
pr_err("%s: Kill process %d (%s) score %d or sacrifice child\n",
message, task_pid_nr(p), p->comm, points);
task_unlock(p);
read_lock(&tasklist_lock);
for_each_thread(p, t) {
list_for_each_entry(child, &t->children, sibling) {
unsigned int child_points;
if (child->mm == p->mm)
continue;
child_points = oom_badness(child, memcg, nodemask,
totalpages);
if (child_points > victim_points) {
put_task_struct(victim);
victim = child;
victim_points = child_points;
get_task_struct(victim);
}
}
}
read_unlock(&tasklist_lock);
p = find_lock_task_mm(victim);
if (!p) {
put_task_struct(victim);
return;
} else if (victim != p) {
get_task_struct(p);
put_task_struct(victim);
victim = p;
}
mm = victim->mm;
pr_err("Killed process %d (%s) total-vm:%lukB, anon-rss:%lukB, file-rss:%lukB\n",
task_pid_nr(victim), victim->comm, K(victim->mm->total_vm),
K(get_mm_counter(victim->mm, MM_ANONPAGES)),
K(get_mm_counter(victim->mm, MM_FILEPAGES)));
task_unlock(victim);
rcu_read_lock();
for_each_process(p)
if (p->mm == mm && !same_thread_group(p, victim) &&
!(p->flags & PF_KTHREAD)) {
if (p->signal->oom_score_adj == OOM_SCORE_ADJ_MIN)
continue;
task_lock(p);
pr_err("Kill process %d (%s) sharing same memory\n",
task_pid_nr(p), p->comm);
task_unlock(p);
do_send_sig_info(SIGKILL, SEND_SIG_FORCED, p, true);
}
rcu_read_unlock();
set_tsk_thread_flag(victim, TIF_MEMDIE);
do_send_sig_info(SIGKILL, SEND_SIG_FORCED, victim, true);
put_task_struct(victim);
}
void check_panic_on_oom(enum oom_constraint constraint, gfp_t gfp_mask,
int order, const nodemask_t *nodemask)
{
if (likely(!sysctl_panic_on_oom))
return;
if (sysctl_panic_on_oom != 2) {
if (constraint != CONSTRAINT_NONE)
return;
}
dump_header(NULL, gfp_mask, order, NULL, nodemask);
panic("Out of memory: %s panic_on_oom is enabled\n",
sysctl_panic_on_oom == 2 ? "compulsory" : "system-wide");
}
int register_oom_notifier(struct notifier_block *nb)
{
return blocking_notifier_chain_register(&oom_notify_list, nb);
}
int unregister_oom_notifier(struct notifier_block *nb)
{
return blocking_notifier_chain_unregister(&oom_notify_list, nb);
}
bool oom_zonelist_trylock(struct zonelist *zonelist, gfp_t gfp_mask)
{
struct zoneref *z;
struct zone *zone;
bool ret = true;
spin_lock(&zone_scan_lock);
for_each_zone_zonelist(zone, z, zonelist, gfp_zone(gfp_mask))
if (test_bit(ZONE_OOM_LOCKED, &zone->flags)) {
ret = false;
goto out;
}
for_each_zone_zonelist(zone, z, zonelist, gfp_zone(gfp_mask))
set_bit(ZONE_OOM_LOCKED, &zone->flags);
out:
spin_unlock(&zone_scan_lock);
return ret;
}
void oom_zonelist_unlock(struct zonelist *zonelist, gfp_t gfp_mask)
{
struct zoneref *z;
struct zone *zone;
spin_lock(&zone_scan_lock);
for_each_zone_zonelist(zone, z, zonelist, gfp_zone(gfp_mask))
clear_bit(ZONE_OOM_LOCKED, &zone->flags);
spin_unlock(&zone_scan_lock);
}
void out_of_memory(struct zonelist *zonelist, gfp_t gfp_mask,
int order, nodemask_t *nodemask, bool force_kill)
{
const nodemask_t *mpol_mask;
struct task_struct *p;
unsigned long totalpages;
unsigned long freed = 0;
unsigned int uninitialized_var(points);
enum oom_constraint constraint = CONSTRAINT_NONE;
int killed = 0;
blocking_notifier_call_chain(&oom_notify_list, 0, &freed);
if (freed > 0)
return;
if (fatal_signal_pending(current) || task_will_free_mem(current)) {
set_thread_flag(TIF_MEMDIE);
return;
}
constraint = constrained_alloc(zonelist, gfp_mask, nodemask,
&totalpages);
mpol_mask = (constraint == CONSTRAINT_MEMORY_POLICY) ? nodemask : NULL;
check_panic_on_oom(constraint, gfp_mask, order, mpol_mask);
if (sysctl_oom_kill_allocating_task && current->mm &&
!oom_unkillable_task(current, NULL, nodemask) &&
current->signal->oom_score_adj != OOM_SCORE_ADJ_MIN) {
get_task_struct(current);
oom_kill_process(current, gfp_mask, order, 0, totalpages, NULL,
nodemask,
"Out of memory (oom_kill_allocating_task)");
goto out;
}
p = select_bad_process(&points, totalpages, mpol_mask, force_kill);
if (!p) {
dump_header(NULL, gfp_mask, order, NULL, mpol_mask);
panic("Out of memory and no killable processes...\n");
}
if (p != (void *)-1UL) {
oom_kill_process(p, gfp_mask, order, points, totalpages, NULL,
nodemask, "Out of memory");
killed = 1;
}
out:
if (killed)
schedule_timeout_killable(1);
}
void pagefault_out_of_memory(void)
{
struct zonelist *zonelist;
if (mem_cgroup_oom_synchronize(true))
return;
zonelist = node_zonelist(first_memory_node, GFP_KERNEL);
if (oom_zonelist_trylock(zonelist, GFP_KERNEL)) {
out_of_memory(NULL, 0, 0, NULL, false);
oom_zonelist_unlock(zonelist, GFP_KERNEL);
}
}
