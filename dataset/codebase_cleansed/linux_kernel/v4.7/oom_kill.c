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
static inline bool is_sysrq_oom(struct oom_control *oc)
{
return oc->order == -1;
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
if (adj == OOM_SCORE_ADJ_MIN ||
test_bit(MMF_OOM_REAPED, &p->mm->flags)) {
task_unlock(p);
return 0;
}
points = get_mm_rss(p->mm) + get_mm_counter(p->mm, MM_SWAPENTS) +
atomic_long_read(&p->mm->nr_ptes) + mm_nr_pmds(p->mm);
task_unlock(p);
if (has_capability_noaudit(p, CAP_SYS_ADMIN))
points -= (points * 3) / 100;
adj *= totalpages / 1000;
points += adj;
return points > 0 ? points : 1;
}
static enum oom_constraint constrained_alloc(struct oom_control *oc,
unsigned long *totalpages)
{
struct zone *zone;
struct zoneref *z;
enum zone_type high_zoneidx = gfp_zone(oc->gfp_mask);
bool cpuset_limited = false;
int nid;
*totalpages = totalram_pages + total_swap_pages;
if (!oc->zonelist)
return CONSTRAINT_NONE;
if (oc->gfp_mask & __GFP_THISNODE)
return CONSTRAINT_NONE;
if (oc->nodemask &&
!nodes_subset(node_states[N_MEMORY], *oc->nodemask)) {
*totalpages = total_swap_pages;
for_each_node_mask(nid, *oc->nodemask)
*totalpages += node_spanned_pages(nid);
return CONSTRAINT_MEMORY_POLICY;
}
for_each_zone_zonelist_nodemask(zone, z, oc->zonelist,
high_zoneidx, oc->nodemask)
if (!cpuset_zone_allowed(zone, oc->gfp_mask))
cpuset_limited = true;
if (cpuset_limited) {
*totalpages = total_swap_pages;
for_each_node_mask(nid, cpuset_current_mems_allowed)
*totalpages += node_spanned_pages(nid);
return CONSTRAINT_CPUSET;
}
return CONSTRAINT_NONE;
}
static enum oom_constraint constrained_alloc(struct oom_control *oc,
unsigned long *totalpages)
{
*totalpages = totalram_pages + total_swap_pages;
return CONSTRAINT_NONE;
}
enum oom_scan_t oom_scan_process_thread(struct oom_control *oc,
struct task_struct *task, unsigned long totalpages)
{
if (oom_unkillable_task(task, NULL, oc->nodemask))
return OOM_SCAN_CONTINUE;
if (!is_sysrq_oom(oc) && atomic_read(&task->signal->oom_victims))
return OOM_SCAN_ABORT;
if (oom_task_origin(task))
return OOM_SCAN_SELECT;
return OOM_SCAN_OK;
}
static struct task_struct *select_bad_process(struct oom_control *oc,
unsigned int *ppoints, unsigned long totalpages)
{
struct task_struct *p;
struct task_struct *chosen = NULL;
unsigned long chosen_points = 0;
rcu_read_lock();
for_each_process(p) {
unsigned int points;
switch (oom_scan_process_thread(oc, p, totalpages)) {
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
points = oom_badness(p, NULL, oc->nodemask, totalpages);
if (!points || points < chosen_points)
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
pr_info("[ pid ] uid tgid total_vm rss nr_ptes nr_pmds swapents oom_score_adj name\n");
rcu_read_lock();
for_each_process(p) {
if (oom_unkillable_task(p, memcg, nodemask))
continue;
task = find_lock_task_mm(p);
if (!task) {
continue;
}
pr_info("[%5d] %5d %5d %8lu %8lu %7ld %7ld %8lu %5hd %s\n",
task->pid, from_kuid(&init_user_ns, task_uid(task)),
task->tgid, task->mm->total_vm, get_mm_rss(task->mm),
atomic_long_read(&task->mm->nr_ptes),
mm_nr_pmds(task->mm),
get_mm_counter(task->mm, MM_SWAPENTS),
task->signal->oom_score_adj, task->comm);
task_unlock(task);
}
rcu_read_unlock();
}
static void dump_header(struct oom_control *oc, struct task_struct *p,
struct mem_cgroup *memcg)
{
pr_warn("%s invoked oom-killer: gfp_mask=%#x(%pGg), order=%d, oom_score_adj=%hd\n",
current->comm, oc->gfp_mask, &oc->gfp_mask, oc->order,
current->signal->oom_score_adj);
cpuset_print_current_mems_allowed();
dump_stack();
if (memcg)
mem_cgroup_print_oom_info(memcg, p);
else
show_mem(SHOW_MEM_FILTER_NODES);
if (sysctl_oom_dump_tasks)
dump_tasks(memcg, oc->nodemask);
}
static bool process_shares_mm(struct task_struct *p, struct mm_struct *mm)
{
struct task_struct *t;
for_each_thread(p, t) {
struct mm_struct *t_mm = READ_ONCE(t->mm);
if (t_mm)
return t_mm == mm;
}
return false;
}
static bool __oom_reap_task(struct task_struct *tsk)
{
struct mmu_gather tlb;
struct vm_area_struct *vma;
struct mm_struct *mm = NULL;
struct task_struct *p;
struct zap_details details = {.check_swap_entries = true,
.ignore_dirty = true};
bool ret = true;
mutex_lock(&oom_lock);
p = find_lock_task_mm(tsk);
if (!p)
goto unlock_oom;
mm = p->mm;
atomic_inc(&mm->mm_users);
task_unlock(p);
if (!down_read_trylock(&mm->mmap_sem)) {
ret = false;
goto unlock_oom;
}
tlb_gather_mmu(&tlb, mm, 0, -1);
for (vma = mm->mmap ; vma; vma = vma->vm_next) {
if (is_vm_hugetlb_page(vma))
continue;
if (vma->vm_flags & VM_LOCKED)
continue;
if (vma_is_anonymous(vma) || !(vma->vm_flags & VM_SHARED))
unmap_page_range(&tlb, vma, vma->vm_start, vma->vm_end,
&details);
}
tlb_finish_mmu(&tlb, 0, -1);
pr_info("oom_reaper: reaped process %d (%s), now anon-rss:%lukB, file-rss:%lukB, shmem-rss:%lukB\n",
task_pid_nr(tsk), tsk->comm,
K(get_mm_counter(mm, MM_ANONPAGES)),
K(get_mm_counter(mm, MM_FILEPAGES)),
K(get_mm_counter(mm, MM_SHMEMPAGES)));
up_read(&mm->mmap_sem);
set_bit(MMF_OOM_REAPED, &mm->flags);
unlock_oom:
mutex_unlock(&oom_lock);
if (mm)
mmput_async(mm);
return ret;
}
static void oom_reap_task(struct task_struct *tsk)
{
int attempts = 0;
while (attempts++ < MAX_OOM_REAP_RETRIES && !__oom_reap_task(tsk))
schedule_timeout_idle(HZ/10);
if (attempts > MAX_OOM_REAP_RETRIES) {
pr_info("oom_reaper: unable to reap pid:%d (%s)\n",
task_pid_nr(tsk), tsk->comm);
debug_show_all_locks();
}
tsk->oom_reaper_list = NULL;
exit_oom_victim(tsk);
put_task_struct(tsk);
}
static int oom_reaper(void *unused)
{
set_freezable();
while (true) {
struct task_struct *tsk = NULL;
wait_event_freezable(oom_reaper_wait, oom_reaper_list != NULL);
spin_lock(&oom_reaper_lock);
if (oom_reaper_list != NULL) {
tsk = oom_reaper_list;
oom_reaper_list = tsk->oom_reaper_list;
}
spin_unlock(&oom_reaper_lock);
if (tsk)
oom_reap_task(tsk);
}
return 0;
}
static void wake_oom_reaper(struct task_struct *tsk)
{
if (!oom_reaper_th)
return;
if (tsk == oom_reaper_list || tsk->oom_reaper_list)
return;
get_task_struct(tsk);
spin_lock(&oom_reaper_lock);
tsk->oom_reaper_list = oom_reaper_list;
oom_reaper_list = tsk;
spin_unlock(&oom_reaper_lock);
wake_up(&oom_reaper_wait);
}
void try_oom_reaper(struct task_struct *tsk)
{
struct mm_struct *mm = tsk->mm;
struct task_struct *p;
if (!mm)
return;
if (atomic_read(&mm->mm_users) > 1) {
rcu_read_lock();
for_each_process(p) {
if (!process_shares_mm(p, mm))
continue;
if (fatal_signal_pending(p))
continue;
if (signal_group_exit(p->signal))
continue;
rcu_read_unlock();
return;
}
rcu_read_unlock();
}
wake_oom_reaper(tsk);
}
static int __init oom_init(void)
{
oom_reaper_th = kthread_run(oom_reaper, NULL, "oom_reaper");
if (IS_ERR(oom_reaper_th)) {
pr_err("Unable to start OOM reaper %ld. Continuing regardless\n",
PTR_ERR(oom_reaper_th));
oom_reaper_th = NULL;
}
return 0;
}
static void wake_oom_reaper(struct task_struct *tsk)
{
}
void mark_oom_victim(struct task_struct *tsk)
{
WARN_ON(oom_killer_disabled);
if (test_and_set_tsk_thread_flag(tsk, TIF_MEMDIE))
return;
atomic_inc(&tsk->signal->oom_victims);
__thaw_task(tsk);
atomic_inc(&oom_victims);
}
void exit_oom_victim(struct task_struct *tsk)
{
if (!test_and_clear_tsk_thread_flag(tsk, TIF_MEMDIE))
return;
atomic_dec(&tsk->signal->oom_victims);
if (!atomic_dec_return(&oom_victims))
wake_up_all(&oom_victims_wait);
}
bool oom_killer_disable(void)
{
if (mutex_lock_killable(&oom_lock))
return false;
oom_killer_disabled = true;
mutex_unlock(&oom_lock);
wait_event(oom_victims_wait, !atomic_read(&oom_victims));
return true;
}
void oom_killer_enable(void)
{
oom_killer_disabled = false;
}
void oom_kill_process(struct oom_control *oc, struct task_struct *p,
unsigned int points, unsigned long totalpages,
struct mem_cgroup *memcg, const char *message)
{
struct task_struct *victim = p;
struct task_struct *child;
struct task_struct *t;
struct mm_struct *mm;
unsigned int victim_points = 0;
static DEFINE_RATELIMIT_STATE(oom_rs, DEFAULT_RATELIMIT_INTERVAL,
DEFAULT_RATELIMIT_BURST);
bool can_oom_reap = true;
task_lock(p);
if (p->mm && task_will_free_mem(p)) {
mark_oom_victim(p);
try_oom_reaper(p);
task_unlock(p);
put_task_struct(p);
return;
}
task_unlock(p);
if (__ratelimit(&oom_rs))
dump_header(oc, p, memcg);
pr_err("%s: Kill process %d (%s) score %u or sacrifice child\n",
message, task_pid_nr(p), p->comm, points);
read_lock(&tasklist_lock);
for_each_thread(p, t) {
list_for_each_entry(child, &t->children, sibling) {
unsigned int child_points;
if (process_shares_mm(child, p->mm))
continue;
child_points = oom_badness(child, memcg, oc->nodemask,
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
atomic_inc(&mm->mm_count);
do_send_sig_info(SIGKILL, SEND_SIG_FORCED, victim, true);
mark_oom_victim(victim);
pr_err("Killed process %d (%s) total-vm:%lukB, anon-rss:%lukB, file-rss:%lukB, shmem-rss:%lukB\n",
task_pid_nr(victim), victim->comm, K(victim->mm->total_vm),
K(get_mm_counter(victim->mm, MM_ANONPAGES)),
K(get_mm_counter(victim->mm, MM_FILEPAGES)),
K(get_mm_counter(victim->mm, MM_SHMEMPAGES)));
task_unlock(victim);
rcu_read_lock();
for_each_process(p) {
if (!process_shares_mm(p, mm))
continue;
if (same_thread_group(p, victim))
continue;
if (unlikely(p->flags & PF_KTHREAD) || is_global_init(p) ||
p->signal->oom_score_adj == OOM_SCORE_ADJ_MIN) {
can_oom_reap = false;
continue;
}
do_send_sig_info(SIGKILL, SEND_SIG_FORCED, p, true);
}
rcu_read_unlock();
if (can_oom_reap)
wake_oom_reaper(victim);
mmdrop(mm);
put_task_struct(victim);
}
void check_panic_on_oom(struct oom_control *oc, enum oom_constraint constraint,
struct mem_cgroup *memcg)
{
if (likely(!sysctl_panic_on_oom))
return;
if (sysctl_panic_on_oom != 2) {
if (constraint != CONSTRAINT_NONE)
return;
}
if (is_sysrq_oom(oc))
return;
dump_header(oc, NULL, memcg);
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
bool out_of_memory(struct oom_control *oc)
{
struct task_struct *p;
unsigned long totalpages;
unsigned long freed = 0;
unsigned int uninitialized_var(points);
enum oom_constraint constraint = CONSTRAINT_NONE;
if (oom_killer_disabled)
return false;
blocking_notifier_call_chain(&oom_notify_list, 0, &freed);
if (freed > 0)
return true;
if (current->mm &&
(fatal_signal_pending(current) || task_will_free_mem(current))) {
mark_oom_victim(current);
try_oom_reaper(current);
return true;
}
if (oc->gfp_mask && !(oc->gfp_mask & (__GFP_FS|__GFP_NOFAIL)))
return true;
constraint = constrained_alloc(oc, &totalpages);
if (constraint != CONSTRAINT_MEMORY_POLICY)
oc->nodemask = NULL;
check_panic_on_oom(oc, constraint, NULL);
if (sysctl_oom_kill_allocating_task && current->mm &&
!oom_unkillable_task(current, NULL, oc->nodemask) &&
current->signal->oom_score_adj != OOM_SCORE_ADJ_MIN) {
get_task_struct(current);
oom_kill_process(oc, current, 0, totalpages, NULL,
"Out of memory (oom_kill_allocating_task)");
return true;
}
p = select_bad_process(oc, &points, totalpages);
if (!p && !is_sysrq_oom(oc)) {
dump_header(oc, NULL, NULL);
panic("Out of memory and no killable processes...\n");
}
if (p && p != (void *)-1UL) {
oom_kill_process(oc, p, points, totalpages, NULL,
"Out of memory");
schedule_timeout_killable(1);
}
return true;
}
void pagefault_out_of_memory(void)
{
struct oom_control oc = {
.zonelist = NULL,
.nodemask = NULL,
.gfp_mask = 0,
.order = 0,
};
if (mem_cgroup_oom_synchronize(true))
return;
if (!mutex_trylock(&oom_lock))
return;
if (!out_of_memory(&oc)) {
WARN_ON(test_thread_flag(TIF_MEMDIE));
}
mutex_unlock(&oom_lock);
}
