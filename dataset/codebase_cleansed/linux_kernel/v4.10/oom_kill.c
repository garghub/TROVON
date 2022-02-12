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
static inline bool is_memcg_oom(struct oom_control *oc)
{
return oc->memcg != NULL;
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
test_bit(MMF_OOM_SKIP, &p->mm->flags) ||
in_vfork(p)) {
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
static enum oom_constraint constrained_alloc(struct oom_control *oc)
{
struct zone *zone;
struct zoneref *z;
enum zone_type high_zoneidx = gfp_zone(oc->gfp_mask);
bool cpuset_limited = false;
int nid;
if (is_memcg_oom(oc)) {
oc->totalpages = mem_cgroup_get_limit(oc->memcg) ?: 1;
return CONSTRAINT_MEMCG;
}
oc->totalpages = totalram_pages + total_swap_pages;
if (!IS_ENABLED(CONFIG_NUMA))
return CONSTRAINT_NONE;
if (!oc->zonelist)
return CONSTRAINT_NONE;
if (oc->gfp_mask & __GFP_THISNODE)
return CONSTRAINT_NONE;
if (oc->nodemask &&
!nodes_subset(node_states[N_MEMORY], *oc->nodemask)) {
oc->totalpages = total_swap_pages;
for_each_node_mask(nid, *oc->nodemask)
oc->totalpages += node_spanned_pages(nid);
return CONSTRAINT_MEMORY_POLICY;
}
for_each_zone_zonelist_nodemask(zone, z, oc->zonelist,
high_zoneidx, oc->nodemask)
if (!cpuset_zone_allowed(zone, oc->gfp_mask))
cpuset_limited = true;
if (cpuset_limited) {
oc->totalpages = total_swap_pages;
for_each_node_mask(nid, cpuset_current_mems_allowed)
oc->totalpages += node_spanned_pages(nid);
return CONSTRAINT_CPUSET;
}
return CONSTRAINT_NONE;
}
static int oom_evaluate_task(struct task_struct *task, void *arg)
{
struct oom_control *oc = arg;
unsigned long points;
if (oom_unkillable_task(task, NULL, oc->nodemask))
goto next;
if (!is_sysrq_oom(oc) && tsk_is_oom_victim(task)) {
if (test_bit(MMF_OOM_SKIP, &task->signal->oom_mm->flags))
goto next;
goto abort;
}
if (oom_task_origin(task)) {
points = ULONG_MAX;
goto select;
}
points = oom_badness(task, NULL, oc->nodemask, oc->totalpages);
if (!points || points < oc->chosen_points)
goto next;
if (points == oc->chosen_points && thread_group_leader(oc->chosen))
goto next;
select:
if (oc->chosen)
put_task_struct(oc->chosen);
get_task_struct(task);
oc->chosen = task;
oc->chosen_points = points;
next:
return 0;
abort:
if (oc->chosen)
put_task_struct(oc->chosen);
oc->chosen = (void *)-1UL;
return 1;
}
static void select_bad_process(struct oom_control *oc)
{
if (is_memcg_oom(oc))
mem_cgroup_scan_tasks(oc->memcg, oom_evaluate_task, oc);
else {
struct task_struct *p;
rcu_read_lock();
for_each_process(p)
if (oom_evaluate_task(p, oc))
break;
rcu_read_unlock();
}
oc->chosen_points = oc->chosen_points * 1000 / oc->totalpages;
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
static void dump_header(struct oom_control *oc, struct task_struct *p)
{
nodemask_t *nm = (oc->nodemask) ? oc->nodemask : &cpuset_current_mems_allowed;
pr_warn("%s invoked oom-killer: gfp_mask=%#x(%pGg), nodemask=%*pbl, order=%d, oom_score_adj=%hd\n",
current->comm, oc->gfp_mask, &oc->gfp_mask,
nodemask_pr_args(nm), oc->order,
current->signal->oom_score_adj);
if (!IS_ENABLED(CONFIG_COMPACTION) && oc->order)
pr_warn("COMPACTION is disabled!!!\n");
cpuset_print_current_mems_allowed();
dump_stack();
if (oc->memcg)
mem_cgroup_print_oom_info(oc->memcg, p);
else
show_mem(SHOW_MEM_FILTER_NODES);
if (sysctl_oom_dump_tasks)
dump_tasks(oc->memcg, oc->nodemask);
}
bool process_shares_mm(struct task_struct *p, struct mm_struct *mm)
{
struct task_struct *t;
for_each_thread(p, t) {
struct mm_struct *t_mm = READ_ONCE(t->mm);
if (t_mm)
return t_mm == mm;
}
return false;
}
static bool __oom_reap_task_mm(struct task_struct *tsk, struct mm_struct *mm)
{
struct mmu_gather tlb;
struct vm_area_struct *vma;
struct zap_details details = {.check_swap_entries = true,
.ignore_dirty = true};
bool ret = true;
mutex_lock(&oom_lock);
if (!down_read_trylock(&mm->mmap_sem)) {
ret = false;
goto unlock_oom;
}
if (!mmget_not_zero(mm)) {
up_read(&mm->mmap_sem);
goto unlock_oom;
}
set_bit(MMF_UNSTABLE, &mm->flags);
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
mmput_async(mm);
unlock_oom:
mutex_unlock(&oom_lock);
return ret;
}
static void oom_reap_task(struct task_struct *tsk)
{
int attempts = 0;
struct mm_struct *mm = tsk->signal->oom_mm;
while (attempts++ < MAX_OOM_REAP_RETRIES && !__oom_reap_task_mm(tsk, mm))
schedule_timeout_idle(HZ/10);
if (attempts <= MAX_OOM_REAP_RETRIES)
goto done;
pr_info("oom_reaper: unable to reap pid:%d (%s)\n",
task_pid_nr(tsk), tsk->comm);
debug_show_all_locks();
done:
tsk->oom_reaper_list = NULL;
set_bit(MMF_OOM_SKIP, &mm->flags);
put_task_struct(tsk);
}
static int oom_reaper(void *unused)
{
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
static inline void wake_oom_reaper(struct task_struct *tsk)
{
}
static void mark_oom_victim(struct task_struct *tsk)
{
struct mm_struct *mm = tsk->mm;
WARN_ON(oom_killer_disabled);
if (test_and_set_tsk_thread_flag(tsk, TIF_MEMDIE))
return;
if (!cmpxchg(&tsk->signal->oom_mm, NULL, mm))
atomic_inc(&tsk->signal->oom_mm->mm_count);
__thaw_task(tsk);
atomic_inc(&oom_victims);
}
void exit_oom_victim(void)
{
clear_thread_flag(TIF_MEMDIE);
if (!atomic_dec_return(&oom_victims))
wake_up_all(&oom_victims_wait);
}
void oom_killer_enable(void)
{
oom_killer_disabled = false;
}
bool oom_killer_disable(signed long timeout)
{
signed long ret;
if (mutex_lock_killable(&oom_lock))
return false;
oom_killer_disabled = true;
mutex_unlock(&oom_lock);
ret = wait_event_interruptible_timeout(oom_victims_wait,
!atomic_read(&oom_victims), timeout);
if (ret <= 0) {
oom_killer_enable();
return false;
}
return true;
}
static inline bool __task_will_free_mem(struct task_struct *task)
{
struct signal_struct *sig = task->signal;
if (sig->flags & SIGNAL_GROUP_COREDUMP)
return false;
if (sig->flags & SIGNAL_GROUP_EXIT)
return true;
if (thread_group_empty(task) && (task->flags & PF_EXITING))
return true;
return false;
}
static bool task_will_free_mem(struct task_struct *task)
{
struct mm_struct *mm = task->mm;
struct task_struct *p;
bool ret = true;
if (!mm)
return false;
if (!__task_will_free_mem(task))
return false;
if (test_bit(MMF_OOM_SKIP, &mm->flags))
return false;
if (atomic_read(&mm->mm_users) <= 1)
return true;
rcu_read_lock();
for_each_process(p) {
if (!process_shares_mm(p, mm))
continue;
if (same_thread_group(task, p))
continue;
ret = __task_will_free_mem(p);
if (!ret)
break;
}
rcu_read_unlock();
return ret;
}
static void oom_kill_process(struct oom_control *oc, const char *message)
{
struct task_struct *p = oc->chosen;
unsigned int points = oc->chosen_points;
struct task_struct *victim = p;
struct task_struct *child;
struct task_struct *t;
struct mm_struct *mm;
unsigned int victim_points = 0;
static DEFINE_RATELIMIT_STATE(oom_rs, DEFAULT_RATELIMIT_INTERVAL,
DEFAULT_RATELIMIT_BURST);
bool can_oom_reap = true;
task_lock(p);
if (task_will_free_mem(p)) {
mark_oom_victim(p);
wake_oom_reaper(p);
task_unlock(p);
put_task_struct(p);
return;
}
task_unlock(p);
if (__ratelimit(&oom_rs))
dump_header(oc, p);
pr_err("%s: Kill process %d (%s) score %u or sacrifice child\n",
message, task_pid_nr(p), p->comm, points);
read_lock(&tasklist_lock);
for_each_thread(p, t) {
list_for_each_entry(child, &t->children, sibling) {
unsigned int child_points;
if (process_shares_mm(child, p->mm))
continue;
child_points = oom_badness(child,
oc->memcg, oc->nodemask, oc->totalpages);
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
if (is_global_init(p)) {
can_oom_reap = false;
set_bit(MMF_OOM_SKIP, &mm->flags);
pr_info("oom killer %d (%s) has mm pinned by %d (%s)\n",
task_pid_nr(victim), victim->comm,
task_pid_nr(p), p->comm);
continue;
}
if (unlikely(p->flags & PF_KTHREAD))
continue;
do_send_sig_info(SIGKILL, SEND_SIG_FORCED, p, true);
}
rcu_read_unlock();
if (can_oom_reap)
wake_oom_reaper(victim);
mmdrop(mm);
put_task_struct(victim);
}
static void check_panic_on_oom(struct oom_control *oc,
enum oom_constraint constraint)
{
if (likely(!sysctl_panic_on_oom))
return;
if (sysctl_panic_on_oom != 2) {
if (constraint != CONSTRAINT_NONE)
return;
}
if (is_sysrq_oom(oc))
return;
dump_header(oc, NULL);
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
unsigned long freed = 0;
enum oom_constraint constraint = CONSTRAINT_NONE;
if (oom_killer_disabled)
return false;
if (!is_memcg_oom(oc)) {
blocking_notifier_call_chain(&oom_notify_list, 0, &freed);
if (freed > 0)
return true;
}
if (task_will_free_mem(current)) {
mark_oom_victim(current);
wake_oom_reaper(current);
return true;
}
if (oc->gfp_mask && !(oc->gfp_mask & (__GFP_FS|__GFP_NOFAIL)))
return true;
constraint = constrained_alloc(oc);
if (constraint != CONSTRAINT_MEMORY_POLICY)
oc->nodemask = NULL;
check_panic_on_oom(oc, constraint);
if (!is_memcg_oom(oc) && sysctl_oom_kill_allocating_task &&
current->mm && !oom_unkillable_task(current, NULL, oc->nodemask) &&
current->signal->oom_score_adj != OOM_SCORE_ADJ_MIN) {
get_task_struct(current);
oc->chosen = current;
oom_kill_process(oc, "Out of memory (oom_kill_allocating_task)");
return true;
}
select_bad_process(oc);
if (!oc->chosen && !is_sysrq_oom(oc) && !is_memcg_oom(oc)) {
dump_header(oc, NULL);
panic("Out of memory and no killable processes...\n");
}
if (oc->chosen && oc->chosen != (void *)-1UL) {
oom_kill_process(oc, !is_memcg_oom(oc) ? "Out of memory" :
"Memory cgroup out of memory");
schedule_timeout_killable(1);
}
return !!oc->chosen;
}
void pagefault_out_of_memory(void)
{
struct oom_control oc = {
.zonelist = NULL,
.nodemask = NULL,
.memcg = NULL,
.gfp_mask = 0,
.order = 0,
};
if (mem_cgroup_oom_synchronize(true))
return;
if (!mutex_trylock(&oom_lock))
return;
out_of_memory(&oc);
mutex_unlock(&oom_lock);
}
