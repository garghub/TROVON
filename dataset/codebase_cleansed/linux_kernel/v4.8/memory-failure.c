static int hwpoison_filter_dev(struct page *p)
{
struct address_space *mapping;
dev_t dev;
if (hwpoison_filter_dev_major == ~0U &&
hwpoison_filter_dev_minor == ~0U)
return 0;
if (PageSlab(p))
return -EINVAL;
mapping = page_mapping(p);
if (mapping == NULL || mapping->host == NULL)
return -EINVAL;
dev = mapping->host->i_sb->s_dev;
if (hwpoison_filter_dev_major != ~0U &&
hwpoison_filter_dev_major != MAJOR(dev))
return -EINVAL;
if (hwpoison_filter_dev_minor != ~0U &&
hwpoison_filter_dev_minor != MINOR(dev))
return -EINVAL;
return 0;
}
static int hwpoison_filter_flags(struct page *p)
{
if (!hwpoison_filter_flags_mask)
return 0;
if ((stable_page_flags(p) & hwpoison_filter_flags_mask) ==
hwpoison_filter_flags_value)
return 0;
else
return -EINVAL;
}
static int hwpoison_filter_task(struct page *p)
{
if (!hwpoison_filter_memcg)
return 0;
if (page_cgroup_ino(p) != hwpoison_filter_memcg)
return -EINVAL;
return 0;
}
static int hwpoison_filter_task(struct page *p) { return 0; }
int hwpoison_filter(struct page *p)
{
if (!hwpoison_filter_enable)
return 0;
if (hwpoison_filter_dev(p))
return -EINVAL;
if (hwpoison_filter_flags(p))
return -EINVAL;
if (hwpoison_filter_task(p))
return -EINVAL;
return 0;
}
int hwpoison_filter(struct page *p)
{
return 0;
}
static int kill_proc(struct task_struct *t, unsigned long addr, int trapno,
unsigned long pfn, struct page *page, int flags)
{
struct siginfo si;
int ret;
pr_err("Memory failure: %#lx: Killing %s:%d due to hardware memory corruption\n",
pfn, t->comm, t->pid);
si.si_signo = SIGBUS;
si.si_errno = 0;
si.si_addr = (void *)addr;
#ifdef __ARCH_SI_TRAPNO
si.si_trapno = trapno;
#endif
si.si_addr_lsb = compound_order(compound_head(page)) + PAGE_SHIFT;
if ((flags & MF_ACTION_REQUIRED) && t->mm == current->mm) {
si.si_code = BUS_MCEERR_AR;
ret = force_sig_info(SIGBUS, &si, current);
} else {
si.si_code = BUS_MCEERR_AO;
ret = send_sig_info(SIGBUS, &si, t);
}
if (ret < 0)
pr_info("Memory failure: Error sending signal to %s:%d: %d\n",
t->comm, t->pid, ret);
return ret;
}
void shake_page(struct page *p, int access)
{
if (!PageSlab(p)) {
lru_add_drain_all();
if (PageLRU(p))
return;
drain_all_pages(page_zone(p));
if (PageLRU(p) || is_free_buddy_page(p))
return;
}
if (access)
drop_slab_node(page_to_nid(p));
}
static void add_to_kill(struct task_struct *tsk, struct page *p,
struct vm_area_struct *vma,
struct list_head *to_kill,
struct to_kill **tkc)
{
struct to_kill *tk;
if (*tkc) {
tk = *tkc;
*tkc = NULL;
} else {
tk = kmalloc(sizeof(struct to_kill), GFP_ATOMIC);
if (!tk) {
pr_err("Memory failure: Out of memory while machine check handling\n");
return;
}
}
tk->addr = page_address_in_vma(p, vma);
tk->addr_valid = 1;
if (tk->addr == -EFAULT) {
pr_info("Memory failure: Unable to find user space address %lx in %s\n",
page_to_pfn(p), tsk->comm);
tk->addr_valid = 0;
}
get_task_struct(tsk);
tk->tsk = tsk;
list_add_tail(&tk->nd, to_kill);
}
static void kill_procs(struct list_head *to_kill, int forcekill, int trapno,
int fail, struct page *page, unsigned long pfn,
int flags)
{
struct to_kill *tk, *next;
list_for_each_entry_safe (tk, next, to_kill, nd) {
if (forcekill) {
if (fail || tk->addr_valid == 0) {
pr_err("Memory failure: %#lx: forcibly killing %s:%d because of failure to unmap corrupted page\n",
pfn, tk->tsk->comm, tk->tsk->pid);
force_sig(SIGKILL, tk->tsk);
}
else if (kill_proc(tk->tsk, tk->addr, trapno,
pfn, page, flags) < 0)
pr_err("Memory failure: %#lx: Cannot send advisory machine check signal to %s:%d\n",
pfn, tk->tsk->comm, tk->tsk->pid);
}
put_task_struct(tk->tsk);
kfree(tk);
}
}
static struct task_struct *find_early_kill_thread(struct task_struct *tsk)
{
struct task_struct *t;
for_each_thread(tsk, t)
if ((t->flags & PF_MCE_PROCESS) && (t->flags & PF_MCE_EARLY))
return t;
return NULL;
}
static struct task_struct *task_early_kill(struct task_struct *tsk,
int force_early)
{
struct task_struct *t;
if (!tsk->mm)
return NULL;
if (force_early)
return tsk;
t = find_early_kill_thread(tsk);
if (t)
return t;
if (sysctl_memory_failure_early_kill)
return tsk;
return NULL;
}
static void collect_procs_anon(struct page *page, struct list_head *to_kill,
struct to_kill **tkc, int force_early)
{
struct vm_area_struct *vma;
struct task_struct *tsk;
struct anon_vma *av;
pgoff_t pgoff;
av = page_lock_anon_vma_read(page);
if (av == NULL)
return;
pgoff = page_to_pgoff(page);
read_lock(&tasklist_lock);
for_each_process (tsk) {
struct anon_vma_chain *vmac;
struct task_struct *t = task_early_kill(tsk, force_early);
if (!t)
continue;
anon_vma_interval_tree_foreach(vmac, &av->rb_root,
pgoff, pgoff) {
vma = vmac->vma;
if (!page_mapped_in_vma(page, vma))
continue;
if (vma->vm_mm == t->mm)
add_to_kill(t, page, vma, to_kill, tkc);
}
}
read_unlock(&tasklist_lock);
page_unlock_anon_vma_read(av);
}
static void collect_procs_file(struct page *page, struct list_head *to_kill,
struct to_kill **tkc, int force_early)
{
struct vm_area_struct *vma;
struct task_struct *tsk;
struct address_space *mapping = page->mapping;
i_mmap_lock_read(mapping);
read_lock(&tasklist_lock);
for_each_process(tsk) {
pgoff_t pgoff = page_to_pgoff(page);
struct task_struct *t = task_early_kill(tsk, force_early);
if (!t)
continue;
vma_interval_tree_foreach(vma, &mapping->i_mmap, pgoff,
pgoff) {
if (vma->vm_mm == t->mm)
add_to_kill(t, page, vma, to_kill, tkc);
}
}
read_unlock(&tasklist_lock);
i_mmap_unlock_read(mapping);
}
static void collect_procs(struct page *page, struct list_head *tokill,
int force_early)
{
struct to_kill *tk;
if (!page->mapping)
return;
tk = kmalloc(sizeof(struct to_kill), GFP_NOIO);
if (!tk)
return;
if (PageAnon(page))
collect_procs_anon(page, tokill, &tk, force_early);
else
collect_procs_file(page, tokill, &tk, force_early);
kfree(tk);
}
static int delete_from_lru_cache(struct page *p)
{
if (!isolate_lru_page(p)) {
ClearPageActive(p);
ClearPageUnevictable(p);
put_page(p);
return 0;
}
return -EIO;
}
static int me_kernel(struct page *p, unsigned long pfn)
{
return MF_IGNORED;
}
static int me_unknown(struct page *p, unsigned long pfn)
{
pr_err("Memory failure: %#lx: Unknown page state\n", pfn);
return MF_FAILED;
}
static int me_pagecache_clean(struct page *p, unsigned long pfn)
{
int err;
int ret = MF_FAILED;
struct address_space *mapping;
delete_from_lru_cache(p);
if (PageAnon(p))
return MF_RECOVERED;
mapping = page_mapping(p);
if (!mapping) {
return MF_FAILED;
}
if (mapping->a_ops->error_remove_page) {
err = mapping->a_ops->error_remove_page(mapping, p);
if (err != 0) {
pr_info("Memory failure: %#lx: Failed to punch page: %d\n",
pfn, err);
} else if (page_has_private(p) &&
!try_to_release_page(p, GFP_NOIO)) {
pr_info("Memory failure: %#lx: failed to release buffers\n",
pfn);
} else {
ret = MF_RECOVERED;
}
} else {
if (invalidate_inode_page(p))
ret = MF_RECOVERED;
else
pr_info("Memory failure: %#lx: Failed to invalidate\n",
pfn);
}
return ret;
}
static int me_pagecache_dirty(struct page *p, unsigned long pfn)
{
struct address_space *mapping = page_mapping(p);
SetPageError(p);
if (mapping) {
mapping_set_error(mapping, EIO);
}
return me_pagecache_clean(p, pfn);
}
static int me_swapcache_dirty(struct page *p, unsigned long pfn)
{
ClearPageDirty(p);
ClearPageUptodate(p);
if (!delete_from_lru_cache(p))
return MF_DELAYED;
else
return MF_FAILED;
}
static int me_swapcache_clean(struct page *p, unsigned long pfn)
{
delete_from_swap_cache(p);
if (!delete_from_lru_cache(p))
return MF_RECOVERED;
else
return MF_FAILED;
}
static int me_huge_page(struct page *p, unsigned long pfn)
{
int res = 0;
struct page *hpage = compound_head(p);
if (!PageHuge(hpage))
return MF_DELAYED;
if (!(page_mapping(hpage) || PageAnon(hpage))) {
res = dequeue_hwpoisoned_huge_page(hpage);
if (!res)
return MF_RECOVERED;
}
return MF_DELAYED;
}
static void action_result(unsigned long pfn, enum mf_action_page_type type,
enum mf_result result)
{
trace_memory_failure_event(pfn, type, result);
pr_err("Memory failure: %#lx: recovery action for %s: %s\n",
pfn, action_page_types[type], action_name[result]);
}
static int page_action(struct page_state *ps, struct page *p,
unsigned long pfn)
{
int result;
int count;
result = ps->action(p, pfn);
count = page_count(p) - 1;
if (ps->action == me_swapcache_dirty && result == MF_DELAYED)
count--;
if (count != 0) {
pr_err("Memory failure: %#lx: %s still referenced by %d users\n",
pfn, action_page_types[ps->type], count);
result = MF_FAILED;
}
action_result(pfn, ps->type, result);
return (result == MF_RECOVERED || result == MF_DELAYED) ? 0 : -EBUSY;
}
int get_hwpoison_page(struct page *page)
{
struct page *head = compound_head(page);
if (!PageHuge(head) && PageTransHuge(head)) {
if (!PageAnon(head)) {
pr_err("Memory failure: %#lx: non anonymous thp\n",
page_to_pfn(page));
return 0;
}
}
if (get_page_unless_zero(head)) {
if (head == compound_head(page))
return 1;
pr_info("Memory failure: %#lx cannot catch tail\n",
page_to_pfn(page));
put_page(head);
}
return 0;
}
static int hwpoison_user_mappings(struct page *p, unsigned long pfn,
int trapno, int flags, struct page **hpagep)
{
enum ttu_flags ttu = TTU_UNMAP | TTU_IGNORE_MLOCK | TTU_IGNORE_ACCESS;
struct address_space *mapping;
LIST_HEAD(tokill);
int ret;
int kill = 1, forcekill;
struct page *hpage = *hpagep;
if (PageReserved(p) || PageSlab(p))
return SWAP_SUCCESS;
if (!(PageLRU(hpage) || PageHuge(p)))
return SWAP_SUCCESS;
if (!page_mapped(hpage))
return SWAP_SUCCESS;
if (PageKsm(p)) {
pr_err("Memory failure: %#lx: can't handle KSM pages.\n", pfn);
return SWAP_FAIL;
}
if (PageSwapCache(p)) {
pr_err("Memory failure: %#lx: keeping poisoned page in swap cache\n",
pfn);
ttu |= TTU_IGNORE_HWPOISON;
}
mapping = page_mapping(hpage);
if (!(flags & MF_MUST_KILL) && !PageDirty(hpage) && mapping &&
mapping_cap_writeback_dirty(mapping)) {
if (page_mkclean(hpage)) {
SetPageDirty(hpage);
} else {
kill = 0;
ttu |= TTU_IGNORE_HWPOISON;
pr_info("Memory failure: %#lx: corrupted page was clean: dropped without side effects\n",
pfn);
}
}
if (kill)
collect_procs(hpage, &tokill, flags & MF_ACTION_REQUIRED);
ret = try_to_unmap(hpage, ttu);
if (ret != SWAP_SUCCESS)
pr_err("Memory failure: %#lx: failed to unmap page (mapcount=%d)\n",
pfn, page_mapcount(hpage));
forcekill = PageDirty(hpage) || (flags & MF_MUST_KILL);
kill_procs(&tokill, forcekill, trapno,
ret != SWAP_SUCCESS, p, pfn, flags);
return ret;
}
static void set_page_hwpoison_huge_page(struct page *hpage)
{
int i;
int nr_pages = 1 << compound_order(hpage);
for (i = 0; i < nr_pages; i++)
SetPageHWPoison(hpage + i);
}
static void clear_page_hwpoison_huge_page(struct page *hpage)
{
int i;
int nr_pages = 1 << compound_order(hpage);
for (i = 0; i < nr_pages; i++)
ClearPageHWPoison(hpage + i);
}
int memory_failure(unsigned long pfn, int trapno, int flags)
{
struct page_state *ps;
struct page *p;
struct page *hpage;
struct page *orig_head;
int res;
unsigned int nr_pages;
unsigned long page_flags;
if (!sysctl_memory_failure_recovery)
panic("Memory failure from trap %d on page %lx", trapno, pfn);
if (!pfn_valid(pfn)) {
pr_err("Memory failure: %#lx: memory outside kernel control\n",
pfn);
return -ENXIO;
}
p = pfn_to_page(pfn);
orig_head = hpage = compound_head(p);
if (TestSetPageHWPoison(p)) {
pr_err("Memory failure: %#lx: already hardware poisoned\n",
pfn);
return 0;
}
if (PageHuge(p))
nr_pages = 1 << compound_order(hpage);
else
nr_pages = 1;
num_poisoned_pages_add(nr_pages);
if (!(flags & MF_COUNT_INCREASED) && !get_hwpoison_page(p)) {
if (is_free_buddy_page(p)) {
action_result(pfn, MF_MSG_BUDDY, MF_DELAYED);
return 0;
} else if (PageHuge(hpage)) {
lock_page(hpage);
if (PageHWPoison(hpage)) {
if ((hwpoison_filter(p) && TestClearPageHWPoison(p))
|| (p != hpage && TestSetPageHWPoison(hpage))) {
num_poisoned_pages_sub(nr_pages);
unlock_page(hpage);
return 0;
}
}
set_page_hwpoison_huge_page(hpage);
res = dequeue_hwpoisoned_huge_page(hpage);
action_result(pfn, MF_MSG_FREE_HUGE,
res ? MF_IGNORED : MF_DELAYED);
unlock_page(hpage);
return res;
} else {
action_result(pfn, MF_MSG_KERNEL_HIGH_ORDER, MF_IGNORED);
return -EBUSY;
}
}
if (!PageHuge(p) && PageTransHuge(hpage)) {
lock_page(hpage);
if (!PageAnon(hpage) || unlikely(split_huge_page(hpage))) {
unlock_page(hpage);
if (!PageAnon(hpage))
pr_err("Memory failure: %#lx: non anonymous thp\n",
pfn);
else
pr_err("Memory failure: %#lx: thp split failed\n",
pfn);
if (TestClearPageHWPoison(p))
num_poisoned_pages_sub(nr_pages);
put_hwpoison_page(p);
return -EBUSY;
}
unlock_page(hpage);
get_hwpoison_page(p);
put_hwpoison_page(hpage);
VM_BUG_ON_PAGE(!page_count(p), p);
hpage = compound_head(p);
}
if (!PageHuge(p)) {
if (!PageLRU(p))
shake_page(p, 0);
if (!PageLRU(p)) {
if (is_free_buddy_page(p)) {
if (flags & MF_COUNT_INCREASED)
action_result(pfn, MF_MSG_BUDDY, MF_DELAYED);
else
action_result(pfn, MF_MSG_BUDDY_2ND,
MF_DELAYED);
return 0;
}
}
}
lock_page(hpage);
if (PageCompound(p) && compound_head(p) != orig_head) {
action_result(pfn, MF_MSG_DIFFERENT_COMPOUND, MF_IGNORED);
res = -EBUSY;
goto out;
}
page_flags = p->flags;
if (!PageHWPoison(p)) {
pr_err("Memory failure: %#lx: just unpoisoned\n", pfn);
num_poisoned_pages_sub(nr_pages);
unlock_page(hpage);
put_hwpoison_page(hpage);
return 0;
}
if (hwpoison_filter(p)) {
if (TestClearPageHWPoison(p))
num_poisoned_pages_sub(nr_pages);
unlock_page(hpage);
put_hwpoison_page(hpage);
return 0;
}
if (!PageHuge(p) && !PageTransTail(p) && !PageLRU(p))
goto identify_page_state;
if (PageHuge(p) && PageTail(p) && TestSetPageHWPoison(hpage)) {
action_result(pfn, MF_MSG_POISONED_HUGE, MF_IGNORED);
unlock_page(hpage);
put_hwpoison_page(hpage);
return 0;
}
if (PageHuge(p))
set_page_hwpoison_huge_page(hpage);
wait_on_page_writeback(p);
if (hwpoison_user_mappings(p, pfn, trapno, flags, &hpage)
!= SWAP_SUCCESS) {
action_result(pfn, MF_MSG_UNMAP_FAILED, MF_IGNORED);
res = -EBUSY;
goto out;
}
if (PageLRU(p) && !PageSwapCache(p) && p->mapping == NULL) {
action_result(pfn, MF_MSG_TRUNCATED_LRU, MF_IGNORED);
res = -EBUSY;
goto out;
}
identify_page_state:
res = -EBUSY;
for (ps = error_states;; ps++)
if ((p->flags & ps->mask) == ps->res)
break;
page_flags |= (p->flags & (1UL << PG_dirty));
if (!ps->mask)
for (ps = error_states;; ps++)
if ((page_flags & ps->mask) == ps->res)
break;
res = page_action(ps, p, pfn);
out:
unlock_page(hpage);
return res;
}
void memory_failure_queue(unsigned long pfn, int trapno, int flags)
{
struct memory_failure_cpu *mf_cpu;
unsigned long proc_flags;
struct memory_failure_entry entry = {
.pfn = pfn,
.trapno = trapno,
.flags = flags,
};
mf_cpu = &get_cpu_var(memory_failure_cpu);
spin_lock_irqsave(&mf_cpu->lock, proc_flags);
if (kfifo_put(&mf_cpu->fifo, entry))
schedule_work_on(smp_processor_id(), &mf_cpu->work);
else
pr_err("Memory failure: buffer overflow when queuing memory failure at %#lx\n",
pfn);
spin_unlock_irqrestore(&mf_cpu->lock, proc_flags);
put_cpu_var(memory_failure_cpu);
}
static void memory_failure_work_func(struct work_struct *work)
{
struct memory_failure_cpu *mf_cpu;
struct memory_failure_entry entry = { 0, };
unsigned long proc_flags;
int gotten;
mf_cpu = this_cpu_ptr(&memory_failure_cpu);
for (;;) {
spin_lock_irqsave(&mf_cpu->lock, proc_flags);
gotten = kfifo_get(&mf_cpu->fifo, &entry);
spin_unlock_irqrestore(&mf_cpu->lock, proc_flags);
if (!gotten)
break;
if (entry.flags & MF_SOFT_OFFLINE)
soft_offline_page(pfn_to_page(entry.pfn), entry.flags);
else
memory_failure(entry.pfn, entry.trapno, entry.flags);
}
}
static int __init memory_failure_init(void)
{
struct memory_failure_cpu *mf_cpu;
int cpu;
for_each_possible_cpu(cpu) {
mf_cpu = &per_cpu(memory_failure_cpu, cpu);
spin_lock_init(&mf_cpu->lock);
INIT_KFIFO(mf_cpu->fifo);
INIT_WORK(&mf_cpu->work, memory_failure_work_func);
}
return 0;
}
int unpoison_memory(unsigned long pfn)
{
struct page *page;
struct page *p;
int freeit = 0;
unsigned int nr_pages;
static DEFINE_RATELIMIT_STATE(unpoison_rs, DEFAULT_RATELIMIT_INTERVAL,
DEFAULT_RATELIMIT_BURST);
if (!pfn_valid(pfn))
return -ENXIO;
p = pfn_to_page(pfn);
page = compound_head(p);
if (!PageHWPoison(p)) {
unpoison_pr_info("Unpoison: Page was already unpoisoned %#lx\n",
pfn, &unpoison_rs);
return 0;
}
if (page_count(page) > 1) {
unpoison_pr_info("Unpoison: Someone grabs the hwpoison page %#lx\n",
pfn, &unpoison_rs);
return 0;
}
if (page_mapped(page)) {
unpoison_pr_info("Unpoison: Someone maps the hwpoison page %#lx\n",
pfn, &unpoison_rs);
return 0;
}
if (page_mapping(page)) {
unpoison_pr_info("Unpoison: the hwpoison page has non-NULL mapping %#lx\n",
pfn, &unpoison_rs);
return 0;
}
if (!PageHuge(page) && PageTransHuge(page)) {
unpoison_pr_info("Unpoison: Memory failure is now running on %#lx\n",
pfn, &unpoison_rs);
return 0;
}
nr_pages = 1 << compound_order(page);
if (!get_hwpoison_page(p)) {
if (PageHuge(page)) {
unpoison_pr_info("Unpoison: Memory failure is now running on free hugepage %#lx\n",
pfn, &unpoison_rs);
return 0;
}
if (TestClearPageHWPoison(p))
num_poisoned_pages_dec();
unpoison_pr_info("Unpoison: Software-unpoisoned free page %#lx\n",
pfn, &unpoison_rs);
return 0;
}
lock_page(page);
if (TestClearPageHWPoison(page)) {
unpoison_pr_info("Unpoison: Software-unpoisoned page %#lx\n",
pfn, &unpoison_rs);
num_poisoned_pages_sub(nr_pages);
freeit = 1;
if (PageHuge(page))
clear_page_hwpoison_huge_page(page);
}
unlock_page(page);
put_hwpoison_page(page);
if (freeit && !(pfn == my_zero_pfn(0) && page_count(p) == 1))
put_hwpoison_page(page);
return 0;
}
static struct page *new_page(struct page *p, unsigned long private, int **x)
{
int nid = page_to_nid(p);
if (PageHuge(p))
return alloc_huge_page_node(page_hstate(compound_head(p)),
nid);
else
return __alloc_pages_node(nid, GFP_HIGHUSER_MOVABLE, 0);
}
static int __get_any_page(struct page *p, unsigned long pfn, int flags)
{
int ret;
if (flags & MF_COUNT_INCREASED)
return 1;
if (!get_hwpoison_page(p)) {
if (PageHuge(p)) {
pr_info("%s: %#lx free huge page\n", __func__, pfn);
ret = 0;
} else if (is_free_buddy_page(p)) {
pr_info("%s: %#lx free buddy page\n", __func__, pfn);
ret = 0;
} else {
pr_info("%s: %#lx: unknown zero refcount page type %lx\n",
__func__, pfn, p->flags);
ret = -EIO;
}
} else {
ret = 1;
}
return ret;
}
static int get_any_page(struct page *page, unsigned long pfn, int flags)
{
int ret = __get_any_page(page, pfn, flags);
if (ret == 1 && !PageHuge(page) && !PageLRU(page)) {
put_hwpoison_page(page);
shake_page(page, 1);
ret = __get_any_page(page, pfn, 0);
if (ret == 1 && !PageLRU(page)) {
put_hwpoison_page(page);
pr_info("soft_offline: %#lx: unknown non LRU page type %lx\n",
pfn, page->flags);
return -EIO;
}
}
return ret;
}
static int soft_offline_huge_page(struct page *page, int flags)
{
int ret;
unsigned long pfn = page_to_pfn(page);
struct page *hpage = compound_head(page);
LIST_HEAD(pagelist);
lock_page(hpage);
if (PageHWPoison(hpage)) {
unlock_page(hpage);
put_hwpoison_page(hpage);
pr_info("soft offline: %#lx hugepage already poisoned\n", pfn);
return -EBUSY;
}
unlock_page(hpage);
ret = isolate_huge_page(hpage, &pagelist);
put_hwpoison_page(hpage);
if (!ret) {
pr_info("soft offline: %#lx hugepage failed to isolate\n", pfn);
return -EBUSY;
}
ret = migrate_pages(&pagelist, new_page, NULL, MPOL_MF_MOVE_ALL,
MIGRATE_SYNC, MR_MEMORY_FAILURE);
if (ret) {
pr_info("soft offline: %#lx: migration failed %d, type %lx\n",
pfn, ret, page->flags);
putback_active_hugepage(hpage);
if (ret > 0)
ret = -EIO;
} else {
if (PageHuge(page)) {
set_page_hwpoison_huge_page(hpage);
dequeue_hwpoisoned_huge_page(hpage);
num_poisoned_pages_add(1 << compound_order(hpage));
} else {
SetPageHWPoison(page);
num_poisoned_pages_inc();
}
}
return ret;
}
static int __soft_offline_page(struct page *page, int flags)
{
int ret;
unsigned long pfn = page_to_pfn(page);
lock_page(page);
wait_on_page_writeback(page);
if (PageHWPoison(page)) {
unlock_page(page);
put_hwpoison_page(page);
pr_info("soft offline: %#lx page already poisoned\n", pfn);
return -EBUSY;
}
ret = invalidate_inode_page(page);
unlock_page(page);
if (ret == 1) {
put_hwpoison_page(page);
pr_info("soft_offline: %#lx: invalidated\n", pfn);
SetPageHWPoison(page);
num_poisoned_pages_inc();
return 0;
}
ret = isolate_lru_page(page);
put_hwpoison_page(page);
if (!ret) {
LIST_HEAD(pagelist);
inc_node_page_state(page, NR_ISOLATED_ANON +
page_is_file_cache(page));
list_add(&page->lru, &pagelist);
ret = migrate_pages(&pagelist, new_page, NULL, MPOL_MF_MOVE_ALL,
MIGRATE_SYNC, MR_MEMORY_FAILURE);
if (ret) {
if (!list_empty(&pagelist)) {
list_del(&page->lru);
dec_node_page_state(page, NR_ISOLATED_ANON +
page_is_file_cache(page));
putback_lru_page(page);
}
pr_info("soft offline: %#lx: migration failed %d, type %lx\n",
pfn, ret, page->flags);
if (ret > 0)
ret = -EIO;
}
} else {
pr_info("soft offline: %#lx: isolation failed: %d, page count %d, type %lx\n",
pfn, ret, page_count(page), page->flags);
}
return ret;
}
static int soft_offline_in_use_page(struct page *page, int flags)
{
int ret;
struct page *hpage = compound_head(page);
if (!PageHuge(page) && PageTransHuge(hpage)) {
lock_page(hpage);
if (!PageAnon(hpage) || unlikely(split_huge_page(hpage))) {
unlock_page(hpage);
if (!PageAnon(hpage))
pr_info("soft offline: %#lx: non anonymous thp\n", page_to_pfn(page));
else
pr_info("soft offline: %#lx: thp split failed\n", page_to_pfn(page));
put_hwpoison_page(hpage);
return -EBUSY;
}
unlock_page(hpage);
get_hwpoison_page(page);
put_hwpoison_page(hpage);
}
if (PageHuge(page))
ret = soft_offline_huge_page(page, flags);
else
ret = __soft_offline_page(page, flags);
return ret;
}
static void soft_offline_free_page(struct page *page)
{
if (PageHuge(page)) {
struct page *hpage = compound_head(page);
set_page_hwpoison_huge_page(hpage);
if (!dequeue_hwpoisoned_huge_page(hpage))
num_poisoned_pages_add(1 << compound_order(hpage));
} else {
if (!TestSetPageHWPoison(page))
num_poisoned_pages_inc();
}
}
int soft_offline_page(struct page *page, int flags)
{
int ret;
unsigned long pfn = page_to_pfn(page);
if (PageHWPoison(page)) {
pr_info("soft offline: %#lx page already poisoned\n", pfn);
if (flags & MF_COUNT_INCREASED)
put_hwpoison_page(page);
return -EBUSY;
}
get_online_mems();
ret = get_any_page(page, pfn, flags);
put_online_mems();
if (ret > 0)
ret = soft_offline_in_use_page(page, flags);
else if (ret == 0)
soft_offline_free_page(page);
return ret;
}
