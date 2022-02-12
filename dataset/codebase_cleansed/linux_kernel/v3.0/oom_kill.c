int test_set_oom_score_adj(int new_val)
{
struct sighand_struct *sighand = current->sighand;
int old_val;
spin_lock_irq(&sighand->siglock);
old_val = current->signal->oom_score_adj;
if (new_val != old_val) {
if (new_val == OOM_SCORE_ADJ_MIN)
atomic_inc(&current->mm->oom_disable_count);
else if (old_val == OOM_SCORE_ADJ_MIN)
atomic_dec(&current->mm->oom_disable_count);
current->signal->oom_score_adj = new_val;
}
spin_unlock_irq(&sighand->siglock);
return old_val;
}
static bool has_intersects_mems_allowed(struct task_struct *tsk,
const nodemask_t *mask)
{
struct task_struct *start = tsk;
do {
if (mask) {
if (mempolicy_nodemask_intersects(tsk, mask))
return true;
} else {
if (cpuset_mems_allowed_intersects(current, tsk))
return true;
}
} while_each_thread(start, tsk);
bool has_intersects_mems_allowed(struct task_struct *tsk,
const nodemask_t *mask)
{
return true;
}
struct task_struct *find_lock_task_mm(struct task_struct *p)
{
struct task_struct *t = p;
do {
task_lock(t);
if (likely(t->mm))
return t;
task_unlock(t);
} while_each_thread(p, t);
bool oom_unkillable_task(struct task_struct *p,
const struct mem_cgroup *mem, const nodemask_t *nodemask)
{
if (is_global_init(p))
return true;
if (p->flags & PF_KTHREAD)
return true;
if (mem && !task_in_mem_cgroup(p, mem))
return true;
if (!has_intersects_mems_allowed(p, nodemask))
return true;
return false;
}
unsigned int oom_badness(struct task_struct *p, struct mem_cgroup *mem,
const nodemask_t *nodemask, unsigned long totalpages)
{
int points;
if (oom_unkillable_task(p, mem, nodemask))
return 0;
p = find_lock_task_mm(p);
if (!p)
return 0;
if (atomic_read(&p->mm->oom_disable_count)) {
task_unlock(p);
return 0;
}
if (!totalpages)
totalpages = 1;
points = get_mm_rss(p->mm) + p->mm->nr_ptes;
points += get_mm_counter(p->mm, MM_SWAPENTS);
points *= 1000;
points /= totalpages;
task_unlock(p);
if (has_capability_noaudit(p, CAP_SYS_ADMIN))
points -= 30;
points += p->signal->oom_score_adj;
if (points <= 0)
return 1;
return (points < 1000) ? points : 1000;
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
if (nodemask && !nodes_subset(node_states[N_HIGH_MEMORY], *nodemask)) {
*totalpages = total_swap_pages;
for_each_node_mask(nid, *nodemask)
*totalpages += node_spanned_pages(nid);
return CONSTRAINT_MEMORY_POLICY;
}
for_each_zone_zonelist_nodemask(zone, z, zonelist,
high_zoneidx, nodemask)
if (!cpuset_zone_allowed_softwall(zone, gfp_mask))
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
static struct task_struct *select_bad_process(unsigned int *ppoints,
unsigned long totalpages, struct mem_cgroup *mem,
const nodemask_t *nodemask)
{
struct task_struct *g, *p;
struct task_struct *chosen = NULL;
*ppoints = 0;
do_each_thread(g, p) {
unsigned int points;
if (!p->mm)
continue;
if (oom_unkillable_task(p, mem, nodemask))
continue;
if (test_tsk_thread_flag(p, TIF_MEMDIE))
return ERR_PTR(-1UL);
if (p->flags & PF_EXITING) {
if (p == current) {
chosen = p;
*ppoints = 1000;
} else {
if (!(task_ptrace(p->group_leader) &
PT_TRACE_EXIT))
return ERR_PTR(-1UL);
}
}
points = oom_badness(p, mem, nodemask, totalpages);
if (points > *ppoints) {
chosen = p;
*ppoints = points;
}
} while_each_thread(g, p);
return chosen;
}
static void dump_tasks(const struct mem_cgroup *mem, const nodemask_t *nodemask)
{
struct task_struct *p;
struct task_struct *task;
pr_info("[ pid ] uid tgid total_vm rss cpu oom_adj oom_score_adj name\n");
for_each_process(p) {
if (oom_unkillable_task(p, mem, nodemask))
continue;
task = find_lock_task_mm(p);
if (!task) {
continue;
}
pr_info("[%5d] %5d %5d %8lu %8lu %3u %3d %5d %s\n",
task->pid, task_uid(task), task->tgid,
task->mm->total_vm, get_mm_rss(task->mm),
task_cpu(task), task->signal->oom_adj,
task->signal->oom_score_adj, task->comm);
task_unlock(task);
}
}
static void dump_header(struct task_struct *p, gfp_t gfp_mask, int order,
struct mem_cgroup *mem, const nodemask_t *nodemask)
{
task_lock(current);
pr_warning("%s invoked oom-killer: gfp_mask=0x%x, order=%d, "
"oom_adj=%d, oom_score_adj=%d\n",
current->comm, gfp_mask, order, current->signal->oom_adj,
current->signal->oom_score_adj);
cpuset_print_task_mems_allowed(current);
task_unlock(current);
dump_stack();
mem_cgroup_print_oom_info(mem, p);
show_mem(SHOW_MEM_FILTER_NODES);
if (sysctl_oom_dump_tasks)
dump_tasks(mem, nodemask);
}
static int oom_kill_task(struct task_struct *p, struct mem_cgroup *mem)
{
struct task_struct *q;
struct mm_struct *mm;
p = find_lock_task_mm(p);
if (!p)
return 1;
mm = p->mm;
pr_err("Killed process %d (%s) total-vm:%lukB, anon-rss:%lukB, file-rss:%lukB\n",
task_pid_nr(p), p->comm, K(p->mm->total_vm),
K(get_mm_counter(p->mm, MM_ANONPAGES)),
K(get_mm_counter(p->mm, MM_FILEPAGES)));
task_unlock(p);
for_each_process(q)
if (q->mm == mm && !same_thread_group(q, p)) {
task_lock(q);
pr_err("Kill process %d (%s) sharing same memory\n",
task_pid_nr(q), q->comm);
task_unlock(q);
force_sig(SIGKILL, q);
}
set_tsk_thread_flag(p, TIF_MEMDIE);
force_sig(SIGKILL, p);
return 0;
}
static int oom_kill_process(struct task_struct *p, gfp_t gfp_mask, int order,
unsigned int points, unsigned long totalpages,
struct mem_cgroup *mem, nodemask_t *nodemask,
const char *message)
{
struct task_struct *victim = p;
struct task_struct *child;
struct task_struct *t = p;
unsigned int victim_points = 0;
if (printk_ratelimit())
dump_header(p, gfp_mask, order, mem, nodemask);
if (p->flags & PF_EXITING) {
set_tsk_thread_flag(p, TIF_MEMDIE);
return 0;
}
task_lock(p);
pr_err("%s: Kill process %d (%s) score %d or sacrifice child\n",
message, task_pid_nr(p), p->comm, points);
task_unlock(p);
do {
list_for_each_entry(child, &t->children, sibling) {
unsigned int child_points;
if (child->mm == p->mm)
continue;
child_points = oom_badness(child, mem, nodemask,
totalpages);
if (child_points > victim_points) {
victim = child;
victim_points = child_points;
}
}
} while_each_thread(p, t);
void check_panic_on_oom(enum oom_constraint constraint, gfp_t gfp_mask,
int order, const nodemask_t *nodemask)
{
if (likely(!sysctl_panic_on_oom))
return;
if (sysctl_panic_on_oom != 2) {
if (constraint != CONSTRAINT_NONE)
return;
}
read_lock(&tasklist_lock);
dump_header(NULL, gfp_mask, order, NULL, nodemask);
read_unlock(&tasklist_lock);
panic("Out of memory: %s panic_on_oom is enabled\n",
sysctl_panic_on_oom == 2 ? "compulsory" : "system-wide");
}
void mem_cgroup_out_of_memory(struct mem_cgroup *mem, gfp_t gfp_mask)
{
unsigned long limit;
unsigned int points = 0;
struct task_struct *p;
if (fatal_signal_pending(current)) {
set_thread_flag(TIF_MEMDIE);
return;
}
check_panic_on_oom(CONSTRAINT_MEMCG, gfp_mask, 0, NULL);
limit = mem_cgroup_get_limit(mem) >> PAGE_SHIFT;
read_lock(&tasklist_lock);
retry:
p = select_bad_process(&points, limit, mem, NULL);
if (!p || PTR_ERR(p) == -1UL)
goto out;
if (oom_kill_process(p, gfp_mask, 0, points, limit, mem, NULL,
"Memory cgroup out of memory"))
goto retry;
out:
read_unlock(&tasklist_lock);
}
int register_oom_notifier(struct notifier_block *nb)
{
return blocking_notifier_chain_register(&oom_notify_list, nb);
}
int unregister_oom_notifier(struct notifier_block *nb)
{
return blocking_notifier_chain_unregister(&oom_notify_list, nb);
}
int try_set_zonelist_oom(struct zonelist *zonelist, gfp_t gfp_mask)
{
struct zoneref *z;
struct zone *zone;
int ret = 1;
spin_lock(&zone_scan_lock);
for_each_zone_zonelist(zone, z, zonelist, gfp_zone(gfp_mask)) {
if (zone_is_oom_locked(zone)) {
ret = 0;
goto out;
}
}
for_each_zone_zonelist(zone, z, zonelist, gfp_zone(gfp_mask)) {
zone_set_flag(zone, ZONE_OOM_LOCKED);
}
out:
spin_unlock(&zone_scan_lock);
return ret;
}
void clear_zonelist_oom(struct zonelist *zonelist, gfp_t gfp_mask)
{
struct zoneref *z;
struct zone *zone;
spin_lock(&zone_scan_lock);
for_each_zone_zonelist(zone, z, zonelist, gfp_zone(gfp_mask)) {
zone_clear_flag(zone, ZONE_OOM_LOCKED);
}
spin_unlock(&zone_scan_lock);
}
static int try_set_system_oom(void)
{
struct zone *zone;
int ret = 1;
spin_lock(&zone_scan_lock);
for_each_populated_zone(zone)
if (zone_is_oom_locked(zone)) {
ret = 0;
goto out;
}
for_each_populated_zone(zone)
zone_set_flag(zone, ZONE_OOM_LOCKED);
out:
spin_unlock(&zone_scan_lock);
return ret;
}
static void clear_system_oom(void)
{
struct zone *zone;
spin_lock(&zone_scan_lock);
for_each_populated_zone(zone)
zone_clear_flag(zone, ZONE_OOM_LOCKED);
spin_unlock(&zone_scan_lock);
}
void out_of_memory(struct zonelist *zonelist, gfp_t gfp_mask,
int order, nodemask_t *nodemask)
{
const nodemask_t *mpol_mask;
struct task_struct *p;
unsigned long totalpages;
unsigned long freed = 0;
unsigned int points;
enum oom_constraint constraint = CONSTRAINT_NONE;
int killed = 0;
blocking_notifier_call_chain(&oom_notify_list, 0, &freed);
if (freed > 0)
return;
if (fatal_signal_pending(current)) {
set_thread_flag(TIF_MEMDIE);
return;
}
constraint = constrained_alloc(zonelist, gfp_mask, nodemask,
&totalpages);
mpol_mask = (constraint == CONSTRAINT_MEMORY_POLICY) ? nodemask : NULL;
check_panic_on_oom(constraint, gfp_mask, order, mpol_mask);
read_lock(&tasklist_lock);
if (sysctl_oom_kill_allocating_task &&
!oom_unkillable_task(current, NULL, nodemask) &&
current->mm && !atomic_read(&current->mm->oom_disable_count)) {
if (!oom_kill_process(current, gfp_mask, order, 0, totalpages,
NULL, nodemask,
"Out of memory (oom_kill_allocating_task)"))
goto out;
}
retry:
p = select_bad_process(&points, totalpages, NULL, mpol_mask);
if (PTR_ERR(p) == -1UL)
goto out;
if (!p) {
dump_header(NULL, gfp_mask, order, NULL, mpol_mask);
read_unlock(&tasklist_lock);
panic("Out of memory and no killable processes...\n");
}
if (oom_kill_process(p, gfp_mask, order, points, totalpages, NULL,
nodemask, "Out of memory"))
goto retry;
killed = 1;
out:
read_unlock(&tasklist_lock);
if (killed && !test_thread_flag(TIF_MEMDIE))
schedule_timeout_uninterruptible(1);
}
void pagefault_out_of_memory(void)
{
if (try_set_system_oom()) {
out_of_memory(NULL, 0, 0, NULL);
clear_system_oom();
}
if (!test_thread_flag(TIF_MEMDIE))
schedule_timeout_uninterruptible(1);
}
