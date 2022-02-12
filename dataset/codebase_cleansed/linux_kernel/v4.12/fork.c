int lockdep_tasklist_lock_is_held(void)
{
return lockdep_is_held(&tasklist_lock);
}
int nr_processes(void)
{
int cpu;
int total = 0;
for_each_possible_cpu(cpu)
total += per_cpu(process_counts, cpu);
return total;
}
void __weak arch_release_task_struct(struct task_struct *tsk)
{
}
static inline struct task_struct *alloc_task_struct_node(int node)
{
return kmem_cache_alloc_node(task_struct_cachep, GFP_KERNEL, node);
}
static inline void free_task_struct(struct task_struct *tsk)
{
kmem_cache_free(task_struct_cachep, tsk);
}
void __weak arch_release_thread_stack(unsigned long *stack)
{
}
static int free_vm_stack_cache(unsigned int cpu)
{
struct vm_struct **cached_vm_stacks = per_cpu_ptr(cached_stacks, cpu);
int i;
for (i = 0; i < NR_CACHED_STACKS; i++) {
struct vm_struct *vm_stack = cached_vm_stacks[i];
if (!vm_stack)
continue;
vfree(vm_stack->addr);
cached_vm_stacks[i] = NULL;
}
return 0;
}
static unsigned long *alloc_thread_stack_node(struct task_struct *tsk, int node)
{
#ifdef CONFIG_VMAP_STACK
void *stack;
int i;
local_irq_disable();
for (i = 0; i < NR_CACHED_STACKS; i++) {
struct vm_struct *s = this_cpu_read(cached_stacks[i]);
if (!s)
continue;
this_cpu_write(cached_stacks[i], NULL);
tsk->stack_vm_area = s;
local_irq_enable();
return s->addr;
}
local_irq_enable();
stack = __vmalloc_node_range(THREAD_SIZE, THREAD_SIZE,
VMALLOC_START, VMALLOC_END,
THREADINFO_GFP,
PAGE_KERNEL,
0, node, __builtin_return_address(0));
if (stack)
tsk->stack_vm_area = find_vm_area(stack);
return stack;
#else
struct page *page = alloc_pages_node(node, THREADINFO_GFP,
THREAD_SIZE_ORDER);
return page ? page_address(page) : NULL;
#endif
}
static inline void free_thread_stack(struct task_struct *tsk)
{
#ifdef CONFIG_VMAP_STACK
if (task_stack_vm_area(tsk)) {
unsigned long flags;
int i;
local_irq_save(flags);
for (i = 0; i < NR_CACHED_STACKS; i++) {
if (this_cpu_read(cached_stacks[i]))
continue;
this_cpu_write(cached_stacks[i], tsk->stack_vm_area);
local_irq_restore(flags);
return;
}
local_irq_restore(flags);
vfree_atomic(tsk->stack);
return;
}
#endif
__free_pages(virt_to_page(tsk->stack), THREAD_SIZE_ORDER);
}
static unsigned long *alloc_thread_stack_node(struct task_struct *tsk,
int node)
{
return kmem_cache_alloc_node(thread_stack_cache, THREADINFO_GFP, node);
}
static void free_thread_stack(struct task_struct *tsk)
{
kmem_cache_free(thread_stack_cache, tsk->stack);
}
void thread_stack_cache_init(void)
{
thread_stack_cache = kmem_cache_create("thread_stack", THREAD_SIZE,
THREAD_SIZE, 0, NULL);
BUG_ON(thread_stack_cache == NULL);
}
static void account_kernel_stack(struct task_struct *tsk, int account)
{
void *stack = task_stack_page(tsk);
struct vm_struct *vm = task_stack_vm_area(tsk);
BUILD_BUG_ON(IS_ENABLED(CONFIG_VMAP_STACK) && PAGE_SIZE % 1024 != 0);
if (vm) {
int i;
BUG_ON(vm->nr_pages != THREAD_SIZE / PAGE_SIZE);
for (i = 0; i < THREAD_SIZE / PAGE_SIZE; i++) {
mod_zone_page_state(page_zone(vm->pages[i]),
NR_KERNEL_STACK_KB,
PAGE_SIZE / 1024 * account);
}
memcg_kmem_update_page_stat(vm->pages[0], MEMCG_KERNEL_STACK_KB,
account * (THREAD_SIZE / 1024));
} else {
struct page *first_page = virt_to_page(stack);
mod_zone_page_state(page_zone(first_page), NR_KERNEL_STACK_KB,
THREAD_SIZE / 1024 * account);
memcg_kmem_update_page_stat(first_page, MEMCG_KERNEL_STACK_KB,
account * (THREAD_SIZE / 1024));
}
}
static void release_task_stack(struct task_struct *tsk)
{
if (WARN_ON(tsk->state != TASK_DEAD))
return;
account_kernel_stack(tsk, -1);
arch_release_thread_stack(tsk->stack);
free_thread_stack(tsk);
tsk->stack = NULL;
#ifdef CONFIG_VMAP_STACK
tsk->stack_vm_area = NULL;
#endif
}
void put_task_stack(struct task_struct *tsk)
{
if (atomic_dec_and_test(&tsk->stack_refcount))
release_task_stack(tsk);
}
void free_task(struct task_struct *tsk)
{
#ifndef CONFIG_THREAD_INFO_IN_TASK
release_task_stack(tsk);
#else
WARN_ON_ONCE(atomic_read(&tsk->stack_refcount) != 0);
#endif
rt_mutex_debug_task_free(tsk);
ftrace_graph_exit_task(tsk);
put_seccomp_filter(tsk);
arch_release_task_struct(tsk);
if (tsk->flags & PF_KTHREAD)
free_kthread_struct(tsk);
free_task_struct(tsk);
}
static inline void free_signal_struct(struct signal_struct *sig)
{
taskstats_tgid_free(sig);
sched_autogroup_exit(sig);
if (sig->oom_mm)
mmdrop_async(sig->oom_mm);
kmem_cache_free(signal_cachep, sig);
}
static inline void put_signal_struct(struct signal_struct *sig)
{
if (atomic_dec_and_test(&sig->sigcnt))
free_signal_struct(sig);
}
void __put_task_struct(struct task_struct *tsk)
{
WARN_ON(!tsk->exit_state);
WARN_ON(atomic_read(&tsk->usage));
WARN_ON(tsk == current);
cgroup_free(tsk);
task_numa_free(tsk);
security_task_free(tsk);
exit_creds(tsk);
delayacct_tsk_free(tsk);
put_signal_struct(tsk->signal);
if (!profile_handoff_task(tsk))
free_task(tsk);
}
void __init __weak arch_task_cache_init(void) { }
static void set_max_threads(unsigned int max_threads_suggested)
{
u64 threads;
if (fls64(totalram_pages) + fls64(PAGE_SIZE) > 64)
threads = MAX_THREADS;
else
threads = div64_u64((u64) totalram_pages * (u64) PAGE_SIZE,
(u64) THREAD_SIZE * 8UL);
if (threads > max_threads_suggested)
threads = max_threads_suggested;
max_threads = clamp_t(u64, threads, MIN_THREADS, MAX_THREADS);
}
void __init fork_init(void)
{
int i;
#ifndef CONFIG_ARCH_TASK_STRUCT_ALLOCATOR
#ifndef ARCH_MIN_TASKALIGN
#define ARCH_MIN_TASKALIGN 0
#endif
int align = max_t(int, L1_CACHE_BYTES, ARCH_MIN_TASKALIGN);
task_struct_cachep = kmem_cache_create("task_struct",
arch_task_struct_size, align,
SLAB_PANIC|SLAB_NOTRACK|SLAB_ACCOUNT, NULL);
#endif
arch_task_cache_init();
set_max_threads(MAX_THREADS);
init_task.signal->rlim[RLIMIT_NPROC].rlim_cur = max_threads/2;
init_task.signal->rlim[RLIMIT_NPROC].rlim_max = max_threads/2;
init_task.signal->rlim[RLIMIT_SIGPENDING] =
init_task.signal->rlim[RLIMIT_NPROC];
for (i = 0; i < UCOUNT_COUNTS; i++) {
init_user_ns.ucount_max[i] = max_threads/2;
}
#ifdef CONFIG_VMAP_STACK
cpuhp_setup_state(CPUHP_BP_PREPARE_DYN, "fork:vm_stack_cache",
NULL, free_vm_stack_cache);
#endif
}
int __weak arch_dup_task_struct(struct task_struct *dst,
struct task_struct *src)
{
*dst = *src;
return 0;
}
void set_task_stack_end_magic(struct task_struct *tsk)
{
unsigned long *stackend;
stackend = end_of_stack(tsk);
*stackend = STACK_END_MAGIC;
}
static struct task_struct *dup_task_struct(struct task_struct *orig, int node)
{
struct task_struct *tsk;
unsigned long *stack;
struct vm_struct *stack_vm_area;
int err;
if (node == NUMA_NO_NODE)
node = tsk_fork_get_node(orig);
tsk = alloc_task_struct_node(node);
if (!tsk)
return NULL;
stack = alloc_thread_stack_node(tsk, node);
if (!stack)
goto free_tsk;
stack_vm_area = task_stack_vm_area(tsk);
err = arch_dup_task_struct(tsk, orig);
tsk->stack = stack;
#ifdef CONFIG_VMAP_STACK
tsk->stack_vm_area = stack_vm_area;
#endif
#ifdef CONFIG_THREAD_INFO_IN_TASK
atomic_set(&tsk->stack_refcount, 1);
#endif
if (err)
goto free_stack;
#ifdef CONFIG_SECCOMP
tsk->seccomp.filter = NULL;
#endif
setup_thread_stack(tsk, orig);
clear_user_return_notifier(tsk);
clear_tsk_need_resched(tsk);
set_task_stack_end_magic(tsk);
#ifdef CONFIG_CC_STACKPROTECTOR
tsk->stack_canary = get_random_long();
#endif
atomic_set(&tsk->usage, 2);
#ifdef CONFIG_BLK_DEV_IO_TRACE
tsk->btrace_seq = 0;
#endif
tsk->splice_pipe = NULL;
tsk->task_frag.page = NULL;
tsk->wake_q.next = NULL;
account_kernel_stack(tsk, 1);
kcov_task_init(tsk);
return tsk;
free_stack:
free_thread_stack(tsk);
free_tsk:
free_task_struct(tsk);
return NULL;
}
static __latent_entropy int dup_mmap(struct mm_struct *mm,
struct mm_struct *oldmm)
{
struct vm_area_struct *mpnt, *tmp, *prev, **pprev;
struct rb_node **rb_link, *rb_parent;
int retval;
unsigned long charge;
LIST_HEAD(uf);
uprobe_start_dup_mmap();
if (down_write_killable(&oldmm->mmap_sem)) {
retval = -EINTR;
goto fail_uprobe_end;
}
flush_cache_dup_mm(oldmm);
uprobe_dup_mmap(oldmm, mm);
down_write_nested(&mm->mmap_sem, SINGLE_DEPTH_NESTING);
RCU_INIT_POINTER(mm->exe_file, get_mm_exe_file(oldmm));
mm->total_vm = oldmm->total_vm;
mm->data_vm = oldmm->data_vm;
mm->exec_vm = oldmm->exec_vm;
mm->stack_vm = oldmm->stack_vm;
rb_link = &mm->mm_rb.rb_node;
rb_parent = NULL;
pprev = &mm->mmap;
retval = ksm_fork(mm, oldmm);
if (retval)
goto out;
retval = khugepaged_fork(mm, oldmm);
if (retval)
goto out;
prev = NULL;
for (mpnt = oldmm->mmap; mpnt; mpnt = mpnt->vm_next) {
struct file *file;
if (mpnt->vm_flags & VM_DONTCOPY) {
vm_stat_account(mm, mpnt->vm_flags, -vma_pages(mpnt));
continue;
}
charge = 0;
if (mpnt->vm_flags & VM_ACCOUNT) {
unsigned long len = vma_pages(mpnt);
if (security_vm_enough_memory_mm(oldmm, len))
goto fail_nomem;
charge = len;
}
tmp = kmem_cache_alloc(vm_area_cachep, GFP_KERNEL);
if (!tmp)
goto fail_nomem;
*tmp = *mpnt;
INIT_LIST_HEAD(&tmp->anon_vma_chain);
retval = vma_dup_policy(mpnt, tmp);
if (retval)
goto fail_nomem_policy;
tmp->vm_mm = mm;
retval = dup_userfaultfd(tmp, &uf);
if (retval)
goto fail_nomem_anon_vma_fork;
if (anon_vma_fork(tmp, mpnt))
goto fail_nomem_anon_vma_fork;
tmp->vm_flags &= ~(VM_LOCKED | VM_LOCKONFAULT);
tmp->vm_next = tmp->vm_prev = NULL;
file = tmp->vm_file;
if (file) {
struct inode *inode = file_inode(file);
struct address_space *mapping = file->f_mapping;
get_file(file);
if (tmp->vm_flags & VM_DENYWRITE)
atomic_dec(&inode->i_writecount);
i_mmap_lock_write(mapping);
if (tmp->vm_flags & VM_SHARED)
atomic_inc(&mapping->i_mmap_writable);
flush_dcache_mmap_lock(mapping);
vma_interval_tree_insert_after(tmp, mpnt,
&mapping->i_mmap);
flush_dcache_mmap_unlock(mapping);
i_mmap_unlock_write(mapping);
}
if (is_vm_hugetlb_page(tmp))
reset_vma_resv_huge_pages(tmp);
*pprev = tmp;
pprev = &tmp->vm_next;
tmp->vm_prev = prev;
prev = tmp;
__vma_link_rb(mm, tmp, rb_link, rb_parent);
rb_link = &tmp->vm_rb.rb_right;
rb_parent = &tmp->vm_rb;
mm->map_count++;
retval = copy_page_range(mm, oldmm, mpnt);
if (tmp->vm_ops && tmp->vm_ops->open)
tmp->vm_ops->open(tmp);
if (retval)
goto out;
}
arch_dup_mmap(oldmm, mm);
retval = 0;
out:
up_write(&mm->mmap_sem);
flush_tlb_mm(oldmm);
up_write(&oldmm->mmap_sem);
dup_userfaultfd_complete(&uf);
fail_uprobe_end:
uprobe_end_dup_mmap();
return retval;
fail_nomem_anon_vma_fork:
mpol_put(vma_policy(tmp));
fail_nomem_policy:
kmem_cache_free(vm_area_cachep, tmp);
fail_nomem:
retval = -ENOMEM;
vm_unacct_memory(charge);
goto out;
}
static inline int mm_alloc_pgd(struct mm_struct *mm)
{
mm->pgd = pgd_alloc(mm);
if (unlikely(!mm->pgd))
return -ENOMEM;
return 0;
}
static inline void mm_free_pgd(struct mm_struct *mm)
{
pgd_free(mm, mm->pgd);
}
static int dup_mmap(struct mm_struct *mm, struct mm_struct *oldmm)
{
down_write(&oldmm->mmap_sem);
RCU_INIT_POINTER(mm->exe_file, get_mm_exe_file(oldmm));
up_write(&oldmm->mmap_sem);
return 0;
}
static int __init coredump_filter_setup(char *s)
{
default_dump_filter =
(simple_strtoul(s, NULL, 0) << MMF_DUMP_FILTER_SHIFT) &
MMF_DUMP_FILTER_MASK;
return 1;
}
static void mm_init_aio(struct mm_struct *mm)
{
#ifdef CONFIG_AIO
spin_lock_init(&mm->ioctx_lock);
mm->ioctx_table = NULL;
#endif
}
static void mm_init_owner(struct mm_struct *mm, struct task_struct *p)
{
#ifdef CONFIG_MEMCG
mm->owner = p;
#endif
}
static struct mm_struct *mm_init(struct mm_struct *mm, struct task_struct *p,
struct user_namespace *user_ns)
{
mm->mmap = NULL;
mm->mm_rb = RB_ROOT;
mm->vmacache_seqnum = 0;
atomic_set(&mm->mm_users, 1);
atomic_set(&mm->mm_count, 1);
init_rwsem(&mm->mmap_sem);
INIT_LIST_HEAD(&mm->mmlist);
mm->core_state = NULL;
atomic_long_set(&mm->nr_ptes, 0);
mm_nr_pmds_init(mm);
mm->map_count = 0;
mm->locked_vm = 0;
mm->pinned_vm = 0;
memset(&mm->rss_stat, 0, sizeof(mm->rss_stat));
spin_lock_init(&mm->page_table_lock);
mm_init_cpumask(mm);
mm_init_aio(mm);
mm_init_owner(mm, p);
mmu_notifier_mm_init(mm);
clear_tlb_flush_pending(mm);
#if defined(CONFIG_TRANSPARENT_HUGEPAGE) && !USE_SPLIT_PMD_PTLOCKS
mm->pmd_huge_pte = NULL;
#endif
if (current->mm) {
mm->flags = current->mm->flags & MMF_INIT_MASK;
mm->def_flags = current->mm->def_flags & VM_INIT_DEF_MASK;
} else {
mm->flags = default_dump_filter;
mm->def_flags = 0;
}
if (mm_alloc_pgd(mm))
goto fail_nopgd;
if (init_new_context(p, mm))
goto fail_nocontext;
mm->user_ns = get_user_ns(user_ns);
return mm;
fail_nocontext:
mm_free_pgd(mm);
fail_nopgd:
free_mm(mm);
return NULL;
}
static void check_mm(struct mm_struct *mm)
{
int i;
for (i = 0; i < NR_MM_COUNTERS; i++) {
long x = atomic_long_read(&mm->rss_stat.count[i]);
if (unlikely(x))
printk(KERN_ALERT "BUG: Bad rss-counter state "
"mm:%p idx:%d val:%ld\n", mm, i, x);
}
if (atomic_long_read(&mm->nr_ptes))
pr_alert("BUG: non-zero nr_ptes on freeing mm: %ld\n",
atomic_long_read(&mm->nr_ptes));
if (mm_nr_pmds(mm))
pr_alert("BUG: non-zero nr_pmds on freeing mm: %ld\n",
mm_nr_pmds(mm));
#if defined(CONFIG_TRANSPARENT_HUGEPAGE) && !USE_SPLIT_PMD_PTLOCKS
VM_BUG_ON_MM(mm->pmd_huge_pte, mm);
#endif
}
struct mm_struct *mm_alloc(void)
{
struct mm_struct *mm;
mm = allocate_mm();
if (!mm)
return NULL;
memset(mm, 0, sizeof(*mm));
return mm_init(mm, current, current_user_ns());
}
void __mmdrop(struct mm_struct *mm)
{
BUG_ON(mm == &init_mm);
mm_free_pgd(mm);
destroy_context(mm);
mmu_notifier_mm_destroy(mm);
check_mm(mm);
put_user_ns(mm->user_ns);
free_mm(mm);
}
static inline void __mmput(struct mm_struct *mm)
{
VM_BUG_ON(atomic_read(&mm->mm_users));
uprobe_clear_state(mm);
exit_aio(mm);
ksm_exit(mm);
khugepaged_exit(mm);
exit_mmap(mm);
mm_put_huge_zero_page(mm);
set_mm_exe_file(mm, NULL);
if (!list_empty(&mm->mmlist)) {
spin_lock(&mmlist_lock);
list_del(&mm->mmlist);
spin_unlock(&mmlist_lock);
}
if (mm->binfmt)
module_put(mm->binfmt->module);
set_bit(MMF_OOM_SKIP, &mm->flags);
mmdrop(mm);
}
void mmput(struct mm_struct *mm)
{
might_sleep();
if (atomic_dec_and_test(&mm->mm_users))
__mmput(mm);
}
static void mmput_async_fn(struct work_struct *work)
{
struct mm_struct *mm = container_of(work, struct mm_struct, async_put_work);
__mmput(mm);
}
void mmput_async(struct mm_struct *mm)
{
if (atomic_dec_and_test(&mm->mm_users)) {
INIT_WORK(&mm->async_put_work, mmput_async_fn);
schedule_work(&mm->async_put_work);
}
}
void set_mm_exe_file(struct mm_struct *mm, struct file *new_exe_file)
{
struct file *old_exe_file;
old_exe_file = rcu_dereference_raw(mm->exe_file);
if (new_exe_file)
get_file(new_exe_file);
rcu_assign_pointer(mm->exe_file, new_exe_file);
if (old_exe_file)
fput(old_exe_file);
}
struct file *get_mm_exe_file(struct mm_struct *mm)
{
struct file *exe_file;
rcu_read_lock();
exe_file = rcu_dereference(mm->exe_file);
if (exe_file && !get_file_rcu(exe_file))
exe_file = NULL;
rcu_read_unlock();
return exe_file;
}
struct file *get_task_exe_file(struct task_struct *task)
{
struct file *exe_file = NULL;
struct mm_struct *mm;
task_lock(task);
mm = task->mm;
if (mm) {
if (!(task->flags & PF_KTHREAD))
exe_file = get_mm_exe_file(mm);
}
task_unlock(task);
return exe_file;
}
struct mm_struct *get_task_mm(struct task_struct *task)
{
struct mm_struct *mm;
task_lock(task);
mm = task->mm;
if (mm) {
if (task->flags & PF_KTHREAD)
mm = NULL;
else
mmget(mm);
}
task_unlock(task);
return mm;
}
struct mm_struct *mm_access(struct task_struct *task, unsigned int mode)
{
struct mm_struct *mm;
int err;
err = mutex_lock_killable(&task->signal->cred_guard_mutex);
if (err)
return ERR_PTR(err);
mm = get_task_mm(task);
if (mm && mm != current->mm &&
!ptrace_may_access(task, mode)) {
mmput(mm);
mm = ERR_PTR(-EACCES);
}
mutex_unlock(&task->signal->cred_guard_mutex);
return mm;
}
static void complete_vfork_done(struct task_struct *tsk)
{
struct completion *vfork;
task_lock(tsk);
vfork = tsk->vfork_done;
if (likely(vfork)) {
tsk->vfork_done = NULL;
complete(vfork);
}
task_unlock(tsk);
}
static int wait_for_vfork_done(struct task_struct *child,
struct completion *vfork)
{
int killed;
freezer_do_not_count();
killed = wait_for_completion_killable(vfork);
freezer_count();
if (killed) {
task_lock(child);
child->vfork_done = NULL;
task_unlock(child);
}
put_task_struct(child);
return killed;
}
void mm_release(struct task_struct *tsk, struct mm_struct *mm)
{
#ifdef CONFIG_FUTEX
if (unlikely(tsk->robust_list)) {
exit_robust_list(tsk);
tsk->robust_list = NULL;
}
#ifdef CONFIG_COMPAT
if (unlikely(tsk->compat_robust_list)) {
compat_exit_robust_list(tsk);
tsk->compat_robust_list = NULL;
}
#endif
if (unlikely(!list_empty(&tsk->pi_state_list)))
exit_pi_state_list(tsk);
#endif
uprobe_free_utask(tsk);
deactivate_mm(tsk, mm);
if (tsk->clear_child_tid) {
if (!(tsk->signal->flags & SIGNAL_GROUP_COREDUMP) &&
atomic_read(&mm->mm_users) > 1) {
put_user(0, tsk->clear_child_tid);
sys_futex(tsk->clear_child_tid, FUTEX_WAKE,
1, NULL, NULL, 0);
}
tsk->clear_child_tid = NULL;
}
if (tsk->vfork_done)
complete_vfork_done(tsk);
}
static struct mm_struct *dup_mm(struct task_struct *tsk)
{
struct mm_struct *mm, *oldmm = current->mm;
int err;
mm = allocate_mm();
if (!mm)
goto fail_nomem;
memcpy(mm, oldmm, sizeof(*mm));
if (!mm_init(mm, tsk, mm->user_ns))
goto fail_nomem;
err = dup_mmap(mm, oldmm);
if (err)
goto free_pt;
mm->hiwater_rss = get_mm_rss(mm);
mm->hiwater_vm = mm->total_vm;
if (mm->binfmt && !try_module_get(mm->binfmt->module))
goto free_pt;
return mm;
free_pt:
mm->binfmt = NULL;
mmput(mm);
fail_nomem:
return NULL;
}
static int copy_mm(unsigned long clone_flags, struct task_struct *tsk)
{
struct mm_struct *mm, *oldmm;
int retval;
tsk->min_flt = tsk->maj_flt = 0;
tsk->nvcsw = tsk->nivcsw = 0;
#ifdef CONFIG_DETECT_HUNG_TASK
tsk->last_switch_count = tsk->nvcsw + tsk->nivcsw;
#endif
tsk->mm = NULL;
tsk->active_mm = NULL;
oldmm = current->mm;
if (!oldmm)
return 0;
vmacache_flush(tsk);
if (clone_flags & CLONE_VM) {
mmget(oldmm);
mm = oldmm;
goto good_mm;
}
retval = -ENOMEM;
mm = dup_mm(tsk);
if (!mm)
goto fail_nomem;
good_mm:
tsk->mm = mm;
tsk->active_mm = mm;
return 0;
fail_nomem:
return retval;
}
static int copy_fs(unsigned long clone_flags, struct task_struct *tsk)
{
struct fs_struct *fs = current->fs;
if (clone_flags & CLONE_FS) {
spin_lock(&fs->lock);
if (fs->in_exec) {
spin_unlock(&fs->lock);
return -EAGAIN;
}
fs->users++;
spin_unlock(&fs->lock);
return 0;
}
tsk->fs = copy_fs_struct(fs);
if (!tsk->fs)
return -ENOMEM;
return 0;
}
static int copy_files(unsigned long clone_flags, struct task_struct *tsk)
{
struct files_struct *oldf, *newf;
int error = 0;
oldf = current->files;
if (!oldf)
goto out;
if (clone_flags & CLONE_FILES) {
atomic_inc(&oldf->count);
goto out;
}
newf = dup_fd(oldf, &error);
if (!newf)
goto out;
tsk->files = newf;
error = 0;
out:
return error;
}
static int copy_io(unsigned long clone_flags, struct task_struct *tsk)
{
#ifdef CONFIG_BLOCK
struct io_context *ioc = current->io_context;
struct io_context *new_ioc;
if (!ioc)
return 0;
if (clone_flags & CLONE_IO) {
ioc_task_link(ioc);
tsk->io_context = ioc;
} else if (ioprio_valid(ioc->ioprio)) {
new_ioc = get_task_io_context(tsk, GFP_KERNEL, NUMA_NO_NODE);
if (unlikely(!new_ioc))
return -ENOMEM;
new_ioc->ioprio = ioc->ioprio;
put_io_context(new_ioc);
}
#endif
return 0;
}
static int copy_sighand(unsigned long clone_flags, struct task_struct *tsk)
{
struct sighand_struct *sig;
if (clone_flags & CLONE_SIGHAND) {
atomic_inc(&current->sighand->count);
return 0;
}
sig = kmem_cache_alloc(sighand_cachep, GFP_KERNEL);
rcu_assign_pointer(tsk->sighand, sig);
if (!sig)
return -ENOMEM;
atomic_set(&sig->count, 1);
memcpy(sig->action, current->sighand->action, sizeof(sig->action));
return 0;
}
void __cleanup_sighand(struct sighand_struct *sighand)
{
if (atomic_dec_and_test(&sighand->count)) {
signalfd_cleanup(sighand);
kmem_cache_free(sighand_cachep, sighand);
}
}
static void posix_cpu_timers_init_group(struct signal_struct *sig)
{
unsigned long cpu_limit;
cpu_limit = READ_ONCE(sig->rlim[RLIMIT_CPU].rlim_cur);
if (cpu_limit != RLIM_INFINITY) {
sig->cputime_expires.prof_exp = cpu_limit * NSEC_PER_SEC;
sig->cputimer.running = true;
}
INIT_LIST_HEAD(&sig->cpu_timers[0]);
INIT_LIST_HEAD(&sig->cpu_timers[1]);
INIT_LIST_HEAD(&sig->cpu_timers[2]);
}
static inline void posix_cpu_timers_init_group(struct signal_struct *sig) { }
static int copy_signal(unsigned long clone_flags, struct task_struct *tsk)
{
struct signal_struct *sig;
if (clone_flags & CLONE_THREAD)
return 0;
sig = kmem_cache_zalloc(signal_cachep, GFP_KERNEL);
tsk->signal = sig;
if (!sig)
return -ENOMEM;
sig->nr_threads = 1;
atomic_set(&sig->live, 1);
atomic_set(&sig->sigcnt, 1);
sig->thread_head = (struct list_head)LIST_HEAD_INIT(tsk->thread_node);
tsk->thread_node = (struct list_head)LIST_HEAD_INIT(sig->thread_head);
init_waitqueue_head(&sig->wait_chldexit);
sig->curr_target = tsk;
init_sigpending(&sig->shared_pending);
seqlock_init(&sig->stats_lock);
prev_cputime_init(&sig->prev_cputime);
#ifdef CONFIG_POSIX_TIMERS
INIT_LIST_HEAD(&sig->posix_timers);
hrtimer_init(&sig->real_timer, CLOCK_MONOTONIC, HRTIMER_MODE_REL);
sig->real_timer.function = it_real_fn;
#endif
task_lock(current->group_leader);
memcpy(sig->rlim, current->signal->rlim, sizeof sig->rlim);
task_unlock(current->group_leader);
posix_cpu_timers_init_group(sig);
tty_audit_fork(sig);
sched_autogroup_fork(sig);
sig->oom_score_adj = current->signal->oom_score_adj;
sig->oom_score_adj_min = current->signal->oom_score_adj_min;
mutex_init(&sig->cred_guard_mutex);
return 0;
}
static void copy_seccomp(struct task_struct *p)
{
#ifdef CONFIG_SECCOMP
assert_spin_locked(&current->sighand->siglock);
get_seccomp_filter(current);
p->seccomp = current->seccomp;
if (task_no_new_privs(current))
task_set_no_new_privs(p);
if (p->seccomp.mode != SECCOMP_MODE_DISABLED)
set_tsk_thread_flag(p, TIF_SECCOMP);
#endif
}
static void rt_mutex_init_task(struct task_struct *p)
{
raw_spin_lock_init(&p->pi_lock);
#ifdef CONFIG_RT_MUTEXES
p->pi_waiters = RB_ROOT;
p->pi_waiters_leftmost = NULL;
p->pi_top_task = NULL;
p->pi_blocked_on = NULL;
#endif
}
static void posix_cpu_timers_init(struct task_struct *tsk)
{
tsk->cputime_expires.prof_exp = 0;
tsk->cputime_expires.virt_exp = 0;
tsk->cputime_expires.sched_exp = 0;
INIT_LIST_HEAD(&tsk->cpu_timers[0]);
INIT_LIST_HEAD(&tsk->cpu_timers[1]);
INIT_LIST_HEAD(&tsk->cpu_timers[2]);
}
static inline void posix_cpu_timers_init(struct task_struct *tsk) { }
static inline void
init_task_pid(struct task_struct *task, enum pid_type type, struct pid *pid)
{
task->pids[type].pid = pid;
}
static inline void rcu_copy_process(struct task_struct *p)
{
#ifdef CONFIG_PREEMPT_RCU
p->rcu_read_lock_nesting = 0;
p->rcu_read_unlock_special.s = 0;
p->rcu_blocked_node = NULL;
INIT_LIST_HEAD(&p->rcu_node_entry);
#endif
#ifdef CONFIG_TASKS_RCU
p->rcu_tasks_holdout = false;
INIT_LIST_HEAD(&p->rcu_tasks_holdout_list);
p->rcu_tasks_idle_cpu = -1;
#endif
}
inline void init_idle_pids(struct pid_link *links)
{
enum pid_type type;
for (type = PIDTYPE_PID; type < PIDTYPE_MAX; ++type) {
INIT_HLIST_NODE(&links[type].node);
links[type].pid = &init_struct_pid;
}
}
struct task_struct *fork_idle(int cpu)
{
struct task_struct *task;
task = copy_process(CLONE_VM, 0, 0, NULL, &init_struct_pid, 0, 0,
cpu_to_node(cpu));
if (!IS_ERR(task)) {
init_idle_pids(task->pids);
init_idle(task, cpu);
}
return task;
}
long _do_fork(unsigned long clone_flags,
unsigned long stack_start,
unsigned long stack_size,
int __user *parent_tidptr,
int __user *child_tidptr,
unsigned long tls)
{
struct task_struct *p;
int trace = 0;
long nr;
if (!(clone_flags & CLONE_UNTRACED)) {
if (clone_flags & CLONE_VFORK)
trace = PTRACE_EVENT_VFORK;
else if ((clone_flags & CSIGNAL) != SIGCHLD)
trace = PTRACE_EVENT_CLONE;
else
trace = PTRACE_EVENT_FORK;
if (likely(!ptrace_event_enabled(current, trace)))
trace = 0;
}
p = copy_process(clone_flags, stack_start, stack_size,
child_tidptr, NULL, trace, tls, NUMA_NO_NODE);
add_latent_entropy();
if (!IS_ERR(p)) {
struct completion vfork;
struct pid *pid;
trace_sched_process_fork(current, p);
pid = get_task_pid(p, PIDTYPE_PID);
nr = pid_vnr(pid);
if (clone_flags & CLONE_PARENT_SETTID)
put_user(nr, parent_tidptr);
if (clone_flags & CLONE_VFORK) {
p->vfork_done = &vfork;
init_completion(&vfork);
get_task_struct(p);
}
wake_up_new_task(p);
if (unlikely(trace))
ptrace_event_pid(trace, pid);
if (clone_flags & CLONE_VFORK) {
if (!wait_for_vfork_done(p, &vfork))
ptrace_event_pid(PTRACE_EVENT_VFORK_DONE, pid);
}
put_pid(pid);
} else {
nr = PTR_ERR(p);
}
return nr;
}
long do_fork(unsigned long clone_flags,
unsigned long stack_start,
unsigned long stack_size,
int __user *parent_tidptr,
int __user *child_tidptr)
{
return _do_fork(clone_flags, stack_start, stack_size,
parent_tidptr, child_tidptr, 0);
}
pid_t kernel_thread(int (*fn)(void *), void *arg, unsigned long flags)
{
return _do_fork(flags|CLONE_VM|CLONE_UNTRACED, (unsigned long)fn,
(unsigned long)arg, NULL, NULL, 0);
}
void walk_process_tree(struct task_struct *top, proc_visitor visitor, void *data)
{
struct task_struct *leader, *parent, *child;
int res;
read_lock(&tasklist_lock);
leader = top = top->group_leader;
down:
for_each_thread(leader, parent) {
list_for_each_entry(child, &parent->children, sibling) {
res = visitor(child, data);
if (res) {
if (res < 0)
goto out;
leader = child;
goto down;
}
up:
;
}
}
if (leader != top) {
child = leader;
parent = child->real_parent;
leader = parent->group_leader;
goto up;
}
out:
read_unlock(&tasklist_lock);
}
static void sighand_ctor(void *data)
{
struct sighand_struct *sighand = data;
spin_lock_init(&sighand->siglock);
init_waitqueue_head(&sighand->signalfd_wqh);
}
void __init proc_caches_init(void)
{
sighand_cachep = kmem_cache_create("sighand_cache",
sizeof(struct sighand_struct), 0,
SLAB_HWCACHE_ALIGN|SLAB_PANIC|SLAB_TYPESAFE_BY_RCU|
SLAB_NOTRACK|SLAB_ACCOUNT, sighand_ctor);
signal_cachep = kmem_cache_create("signal_cache",
sizeof(struct signal_struct), 0,
SLAB_HWCACHE_ALIGN|SLAB_PANIC|SLAB_NOTRACK|SLAB_ACCOUNT,
NULL);
files_cachep = kmem_cache_create("files_cache",
sizeof(struct files_struct), 0,
SLAB_HWCACHE_ALIGN|SLAB_PANIC|SLAB_NOTRACK|SLAB_ACCOUNT,
NULL);
fs_cachep = kmem_cache_create("fs_cache",
sizeof(struct fs_struct), 0,
SLAB_HWCACHE_ALIGN|SLAB_PANIC|SLAB_NOTRACK|SLAB_ACCOUNT,
NULL);
mm_cachep = kmem_cache_create("mm_struct",
sizeof(struct mm_struct), ARCH_MIN_MMSTRUCT_ALIGN,
SLAB_HWCACHE_ALIGN|SLAB_PANIC|SLAB_NOTRACK|SLAB_ACCOUNT,
NULL);
vm_area_cachep = KMEM_CACHE(vm_area_struct, SLAB_PANIC|SLAB_ACCOUNT);
mmap_init();
nsproxy_cache_init();
}
static int check_unshare_flags(unsigned long unshare_flags)
{
if (unshare_flags & ~(CLONE_THREAD|CLONE_FS|CLONE_NEWNS|CLONE_SIGHAND|
CLONE_VM|CLONE_FILES|CLONE_SYSVSEM|
CLONE_NEWUTS|CLONE_NEWIPC|CLONE_NEWNET|
CLONE_NEWUSER|CLONE_NEWPID|CLONE_NEWCGROUP))
return -EINVAL;
if (unshare_flags & (CLONE_THREAD | CLONE_SIGHAND | CLONE_VM)) {
if (!thread_group_empty(current))
return -EINVAL;
}
if (unshare_flags & (CLONE_SIGHAND | CLONE_VM)) {
if (atomic_read(&current->sighand->count) > 1)
return -EINVAL;
}
if (unshare_flags & CLONE_VM) {
if (!current_is_single_threaded())
return -EINVAL;
}
return 0;
}
static int unshare_fs(unsigned long unshare_flags, struct fs_struct **new_fsp)
{
struct fs_struct *fs = current->fs;
if (!(unshare_flags & CLONE_FS) || !fs)
return 0;
if (fs->users == 1)
return 0;
*new_fsp = copy_fs_struct(fs);
if (!*new_fsp)
return -ENOMEM;
return 0;
}
static int unshare_fd(unsigned long unshare_flags, struct files_struct **new_fdp)
{
struct files_struct *fd = current->files;
int error = 0;
if ((unshare_flags & CLONE_FILES) &&
(fd && atomic_read(&fd->count) > 1)) {
*new_fdp = dup_fd(fd, &error);
if (!*new_fdp)
return error;
}
return 0;
}
int unshare_files(struct files_struct **displaced)
{
struct task_struct *task = current;
struct files_struct *copy = NULL;
int error;
error = unshare_fd(CLONE_FILES, &copy);
if (error || !copy) {
*displaced = NULL;
return error;
}
*displaced = task->files;
task_lock(task);
task->files = copy;
task_unlock(task);
return 0;
}
int sysctl_max_threads(struct ctl_table *table, int write,
void __user *buffer, size_t *lenp, loff_t *ppos)
{
struct ctl_table t;
int ret;
int threads = max_threads;
int min = MIN_THREADS;
int max = MAX_THREADS;
t = *table;
t.data = &threads;
t.extra1 = &min;
t.extra2 = &max;
ret = proc_dointvec_minmax(&t, write, buffer, lenp, ppos);
if (ret || !write)
return ret;
set_max_threads(threads);
return 0;
}
