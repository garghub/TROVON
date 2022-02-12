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
struct mem_cgroup *mem;
struct cgroup_subsys_state *css;
unsigned long ino;
if (!hwpoison_filter_memcg)
return 0;
mem = try_get_mem_cgroup_from_page(p);
if (!mem)
return -EINVAL;
css = mem_cgroup_css(mem);
if (!css->cgroup->dentry)
return -EINVAL;
ino = css->cgroup->dentry->d_inode->i_ino;
css_put(css);
if (ino != hwpoison_filter_memcg)
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
printk(KERN_ERR
"MCE %#lx: Killing %s:%d due to hardware memory corruption\n",
pfn, t->comm, t->pid);
si.si_signo = SIGBUS;
si.si_errno = 0;
si.si_addr = (void *)addr;
#ifdef __ARCH_SI_TRAPNO
si.si_trapno = trapno;
#endif
si.si_addr_lsb = compound_trans_order(compound_head(page)) + PAGE_SHIFT;
if ((flags & MF_ACTION_REQUIRED) && t == current) {
si.si_code = BUS_MCEERR_AR;
ret = force_sig_info(SIGBUS, &si, t);
} else {
si.si_code = BUS_MCEERR_AO;
ret = send_sig_info(SIGBUS, &si, t);
}
if (ret < 0)
printk(KERN_INFO "MCE: Error sending signal to %s:%d: %d\n",
t->comm, t->pid, ret);
return ret;
}
void shake_page(struct page *p, int access)
{
if (!PageSlab(p)) {
lru_add_drain_all();
if (PageLRU(p))
return;
drain_all_pages();
if (PageLRU(p) || is_free_buddy_page(p))
return;
}
if (access) {
int nr;
do {
struct shrink_control shrink = {
.gfp_mask = GFP_KERNEL,
};
nr = shrink_slab(&shrink, 1000, 1000);
if (page_count(p) == 1)
break;
} while (nr > 10);
}
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
printk(KERN_ERR
"MCE: Out of memory while machine check handling\n");
return;
}
}
tk->addr = page_address_in_vma(p, vma);
tk->addr_valid = 1;
if (tk->addr == -EFAULT) {
pr_info("MCE: Unable to find user space address %lx in %s\n",
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
printk(KERN_ERR
"MCE %#lx: forcibly killing %s:%d because of failure to unmap corrupted page\n",
pfn, tk->tsk->comm, tk->tsk->pid);
force_sig(SIGKILL, tk->tsk);
}
else if (kill_proc(tk->tsk, tk->addr, trapno,
pfn, page, flags) < 0)
printk(KERN_ERR
"MCE %#lx: Cannot send advisory machine check signal to %s:%d\n",
pfn, tk->tsk->comm, tk->tsk->pid);
}
put_task_struct(tk->tsk);
kfree(tk);
}
}
static int task_early_kill(struct task_struct *tsk)
{
if (!tsk->mm)
return 0;
if (tsk->flags & PF_MCE_PROCESS)
return !!(tsk->flags & PF_MCE_EARLY);
return sysctl_memory_failure_early_kill;
}
static void collect_procs_anon(struct page *page, struct list_head *to_kill,
struct to_kill **tkc)
{
struct vm_area_struct *vma;
struct task_struct *tsk;
struct anon_vma *av;
pgoff_t pgoff;
av = page_lock_anon_vma(page);
if (av == NULL)
return;
pgoff = page->index << (PAGE_CACHE_SHIFT - PAGE_SHIFT);
read_lock(&tasklist_lock);
for_each_process (tsk) {
struct anon_vma_chain *vmac;
if (!task_early_kill(tsk))
continue;
anon_vma_interval_tree_foreach(vmac, &av->rb_root,
pgoff, pgoff) {
vma = vmac->vma;
if (!page_mapped_in_vma(page, vma))
continue;
if (vma->vm_mm == tsk->mm)
add_to_kill(tsk, page, vma, to_kill, tkc);
}
}
read_unlock(&tasklist_lock);
page_unlock_anon_vma(av);
}
static void collect_procs_file(struct page *page, struct list_head *to_kill,
struct to_kill **tkc)
{
struct vm_area_struct *vma;
struct task_struct *tsk;
struct address_space *mapping = page->mapping;
mutex_lock(&mapping->i_mmap_mutex);
read_lock(&tasklist_lock);
for_each_process(tsk) {
pgoff_t pgoff = page->index << (PAGE_CACHE_SHIFT - PAGE_SHIFT);
if (!task_early_kill(tsk))
continue;
vma_interval_tree_foreach(vma, &mapping->i_mmap, pgoff,
pgoff) {
if (vma->vm_mm == tsk->mm)
add_to_kill(tsk, page, vma, to_kill, tkc);
}
}
read_unlock(&tasklist_lock);
mutex_unlock(&mapping->i_mmap_mutex);
}
static void collect_procs(struct page *page, struct list_head *tokill)
{
struct to_kill *tk;
if (!page->mapping)
return;
tk = kmalloc(sizeof(struct to_kill), GFP_NOIO);
if (!tk)
return;
if (PageAnon(page))
collect_procs_anon(page, tokill, &tk);
else
collect_procs_file(page, tokill, &tk);
kfree(tk);
}
static int delete_from_lru_cache(struct page *p)
{
if (!isolate_lru_page(p)) {
ClearPageActive(p);
ClearPageUnevictable(p);
page_cache_release(p);
return 0;
}
return -EIO;
}
static int me_kernel(struct page *p, unsigned long pfn)
{
return IGNORED;
}
static int me_unknown(struct page *p, unsigned long pfn)
{
printk(KERN_ERR "MCE %#lx: Unknown page state\n", pfn);
return FAILED;
}
static int me_pagecache_clean(struct page *p, unsigned long pfn)
{
int err;
int ret = FAILED;
struct address_space *mapping;
delete_from_lru_cache(p);
if (PageAnon(p))
return RECOVERED;
mapping = page_mapping(p);
if (!mapping) {
return FAILED;
}
if (mapping->a_ops->error_remove_page) {
err = mapping->a_ops->error_remove_page(mapping, p);
if (err != 0) {
printk(KERN_INFO "MCE %#lx: Failed to punch page: %d\n",
pfn, err);
} else if (page_has_private(p) &&
!try_to_release_page(p, GFP_NOIO)) {
pr_info("MCE %#lx: failed to release buffers\n", pfn);
} else {
ret = RECOVERED;
}
} else {
if (invalidate_inode_page(p))
ret = RECOVERED;
else
printk(KERN_INFO "MCE %#lx: Failed to invalidate\n",
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
return DELAYED;
else
return FAILED;
}
static int me_swapcache_clean(struct page *p, unsigned long pfn)
{
delete_from_swap_cache(p);
if (!delete_from_lru_cache(p))
return RECOVERED;
else
return FAILED;
}
static int me_huge_page(struct page *p, unsigned long pfn)
{
int res = 0;
struct page *hpage = compound_head(p);
if (!(page_mapping(hpage) || PageAnon(hpage))) {
res = dequeue_hwpoisoned_huge_page(hpage);
if (!res)
return RECOVERED;
}
return DELAYED;
}
static void action_result(unsigned long pfn, char *msg, int result)
{
struct page *page = pfn_to_page(pfn);
printk(KERN_ERR "MCE %#lx: %s%s page recovery: %s\n",
pfn,
PageDirty(page) ? "dirty " : "",
msg, action_name[result]);
}
static int page_action(struct page_state *ps, struct page *p,
unsigned long pfn)
{
int result;
int count;
result = ps->action(p, pfn);
action_result(pfn, ps->msg, result);
count = page_count(p) - 1;
if (ps->action == me_swapcache_dirty && result == DELAYED)
count--;
if (count != 0) {
printk(KERN_ERR
"MCE %#lx: %s page still referenced by %d users\n",
pfn, ps->msg, count);
result = FAILED;
}
return (result == RECOVERED || result == DELAYED) ? 0 : -EBUSY;
}
static int hwpoison_user_mappings(struct page *p, unsigned long pfn,
int trapno, int flags)
{
enum ttu_flags ttu = TTU_UNMAP | TTU_IGNORE_MLOCK | TTU_IGNORE_ACCESS;
struct address_space *mapping;
LIST_HEAD(tokill);
int ret;
int kill = 1, forcekill;
struct page *hpage = compound_head(p);
struct page *ppage;
if (PageReserved(p) || PageSlab(p))
return SWAP_SUCCESS;
if (!page_mapped(hpage))
return SWAP_SUCCESS;
if (PageKsm(p))
return SWAP_FAIL;
if (PageSwapCache(p)) {
printk(KERN_ERR
"MCE %#lx: keeping poisoned page in swap cache\n", pfn);
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
printk(KERN_INFO
"MCE %#lx: corrupted page was clean: dropped without side effects\n",
pfn);
}
}
ppage = hpage;
if (PageTransHuge(hpage)) {
if (!PageHuge(hpage) && PageAnon(hpage)) {
if (unlikely(split_huge_page(hpage))) {
printk(KERN_INFO
"MCE %#lx: failed to split THP\n", pfn);
BUG_ON(!PageHWPoison(p));
return SWAP_FAIL;
}
ppage = p;
}
}
if (kill)
collect_procs(ppage, &tokill);
if (hpage != ppage)
lock_page(ppage);
ret = try_to_unmap(ppage, ttu);
if (ret != SWAP_SUCCESS)
printk(KERN_ERR "MCE %#lx: failed to unmap page (mapcount=%d)\n",
pfn, page_mapcount(ppage));
if (hpage != ppage)
unlock_page(ppage);
forcekill = PageDirty(ppage) || (flags & MF_MUST_KILL);
kill_procs(&tokill, forcekill, trapno,
ret != SWAP_SUCCESS, p, pfn, flags);
return ret;
}
static void set_page_hwpoison_huge_page(struct page *hpage)
{
int i;
int nr_pages = 1 << compound_trans_order(hpage);
for (i = 0; i < nr_pages; i++)
SetPageHWPoison(hpage + i);
}
static void clear_page_hwpoison_huge_page(struct page *hpage)
{
int i;
int nr_pages = 1 << compound_trans_order(hpage);
for (i = 0; i < nr_pages; i++)
ClearPageHWPoison(hpage + i);
}
int memory_failure(unsigned long pfn, int trapno, int flags)
{
struct page_state *ps;
struct page *p;
struct page *hpage;
int res;
unsigned int nr_pages;
if (!sysctl_memory_failure_recovery)
panic("Memory failure from trap %d on page %lx", trapno, pfn);
if (!pfn_valid(pfn)) {
printk(KERN_ERR
"MCE %#lx: memory outside kernel control\n",
pfn);
return -ENXIO;
}
p = pfn_to_page(pfn);
hpage = compound_head(p);
if (TestSetPageHWPoison(p)) {
printk(KERN_ERR "MCE %#lx: already hardware poisoned\n", pfn);
return 0;
}
nr_pages = 1 << compound_trans_order(hpage);
atomic_long_add(nr_pages, &mce_bad_pages);
if (!(flags & MF_COUNT_INCREASED) &&
!get_page_unless_zero(hpage)) {
if (is_free_buddy_page(p)) {
action_result(pfn, "free buddy", DELAYED);
return 0;
} else if (PageHuge(hpage)) {
lock_page(hpage);
if (!PageHWPoison(hpage)
|| (hwpoison_filter(p) && TestClearPageHWPoison(p))
|| (p != hpage && TestSetPageHWPoison(hpage))) {
atomic_long_sub(nr_pages, &mce_bad_pages);
return 0;
}
set_page_hwpoison_huge_page(hpage);
res = dequeue_hwpoisoned_huge_page(hpage);
action_result(pfn, "free huge",
res ? IGNORED : DELAYED);
unlock_page(hpage);
return res;
} else {
action_result(pfn, "high order kernel", IGNORED);
return -EBUSY;
}
}
if (!PageHuge(p) && !PageTransTail(p)) {
if (!PageLRU(p))
shake_page(p, 0);
if (!PageLRU(p)) {
if (is_free_buddy_page(p)) {
action_result(pfn, "free buddy, 2nd try",
DELAYED);
return 0;
}
action_result(pfn, "non LRU", IGNORED);
put_page(p);
return -EBUSY;
}
}
lock_page(hpage);
if (!PageHWPoison(p)) {
printk(KERN_ERR "MCE %#lx: just unpoisoned\n", pfn);
res = 0;
goto out;
}
if (hwpoison_filter(p)) {
if (TestClearPageHWPoison(p))
atomic_long_sub(nr_pages, &mce_bad_pages);
unlock_page(hpage);
put_page(hpage);
return 0;
}
if (PageHuge(p) && PageTail(p) && TestSetPageHWPoison(hpage)) {
action_result(pfn, "hugepage already hardware poisoned",
IGNORED);
unlock_page(hpage);
put_page(hpage);
return 0;
}
if (PageHuge(p))
set_page_hwpoison_huge_page(hpage);
wait_on_page_writeback(p);
if (hwpoison_user_mappings(p, pfn, trapno, flags) != SWAP_SUCCESS) {
printk(KERN_ERR "MCE %#lx: cannot unmap page, give up\n", pfn);
res = -EBUSY;
goto out;
}
if (PageLRU(p) && !PageSwapCache(p) && p->mapping == NULL) {
action_result(pfn, "already truncated LRU", IGNORED);
res = -EBUSY;
goto out;
}
res = -EBUSY;
for (ps = error_states;; ps++) {
if ((p->flags & ps->mask) == ps->res) {
res = page_action(ps, p, pfn);
break;
}
}
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
if (kfifo_put(&mf_cpu->fifo, &entry))
schedule_work_on(smp_processor_id(), &mf_cpu->work);
else
pr_err("Memory failure: buffer overflow when queuing memory failure at 0x%#lx\n",
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
mf_cpu = &__get_cpu_var(memory_failure_cpu);
for (;;) {
spin_lock_irqsave(&mf_cpu->lock, proc_flags);
gotten = kfifo_get(&mf_cpu->fifo, &entry);
spin_unlock_irqrestore(&mf_cpu->lock, proc_flags);
if (!gotten)
break;
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
if (!pfn_valid(pfn))
return -ENXIO;
p = pfn_to_page(pfn);
page = compound_head(p);
if (!PageHWPoison(p)) {
pr_info("MCE: Page was already unpoisoned %#lx\n", pfn);
return 0;
}
nr_pages = 1 << compound_trans_order(page);
if (!get_page_unless_zero(page)) {
if (PageHuge(page)) {
pr_info("MCE: Memory failure is now running on free hugepage %#lx\n", pfn);
return 0;
}
if (TestClearPageHWPoison(p))
atomic_long_sub(nr_pages, &mce_bad_pages);
pr_info("MCE: Software-unpoisoned free page %#lx\n", pfn);
return 0;
}
lock_page(page);
if (TestClearPageHWPoison(page)) {
pr_info("MCE: Software-unpoisoned page %#lx\n", pfn);
atomic_long_sub(nr_pages, &mce_bad_pages);
freeit = 1;
if (PageHuge(page))
clear_page_hwpoison_huge_page(page);
}
unlock_page(page);
put_page(page);
if (freeit)
put_page(page);
return 0;
}
static struct page *new_page(struct page *p, unsigned long private, int **x)
{
int nid = page_to_nid(p);
if (PageHuge(p))
return alloc_huge_page_node(page_hstate(compound_head(p)),
nid);
else
return alloc_pages_exact_node(nid, GFP_HIGHUSER_MOVABLE, 0);
}
static int get_any_page(struct page *p, unsigned long pfn, int flags)
{
int ret;
if (flags & MF_COUNT_INCREASED)
return 1;
lock_memory_hotplug();
set_migratetype_isolate(p);
if (!get_page_unless_zero(compound_head(p))) {
if (PageHuge(p)) {
pr_info("%s: %#lx free huge page\n", __func__, pfn);
ret = dequeue_hwpoisoned_huge_page(compound_head(p));
} else if (is_free_buddy_page(p)) {
pr_info("%s: %#lx free buddy page\n", __func__, pfn);
SetPageHWPoison(p);
ret = 0;
} else {
pr_info("%s: %#lx: unknown zero refcount page type %lx\n",
__func__, pfn, p->flags);
ret = -EIO;
}
} else {
ret = 1;
}
unset_migratetype_isolate(p, MIGRATE_MOVABLE);
unlock_memory_hotplug();
return ret;
}
static int soft_offline_huge_page(struct page *page, int flags)
{
int ret;
unsigned long pfn = page_to_pfn(page);
struct page *hpage = compound_head(page);
ret = get_any_page(page, pfn, flags);
if (ret < 0)
return ret;
if (ret == 0)
goto done;
if (PageHWPoison(hpage)) {
put_page(hpage);
pr_info("soft offline: %#lx hugepage already poisoned\n", pfn);
return -EBUSY;
}
ret = migrate_huge_page(hpage, new_page, MPOL_MF_MOVE_ALL, false,
MIGRATE_SYNC);
put_page(hpage);
if (ret) {
pr_info("soft offline: %#lx: migration failed %d, type %lx\n",
pfn, ret, page->flags);
return ret;
}
done:
if (!PageHWPoison(hpage))
atomic_long_add(1 << compound_trans_order(hpage),
&mce_bad_pages);
set_page_hwpoison_huge_page(hpage);
dequeue_hwpoisoned_huge_page(hpage);
return ret;
}
int soft_offline_page(struct page *page, int flags)
{
int ret;
unsigned long pfn = page_to_pfn(page);
struct page *hpage = compound_trans_head(page);
if (PageHuge(page))
return soft_offline_huge_page(page, flags);
if (PageTransHuge(hpage)) {
if (PageAnon(hpage) && unlikely(split_huge_page(hpage))) {
pr_info("soft offline: %#lx: failed to split THP\n",
pfn);
return -EBUSY;
}
}
ret = get_any_page(page, pfn, flags);
if (ret < 0)
return ret;
if (ret == 0)
goto done;
if (!PageLRU(page)) {
put_page(page);
shake_page(page, 1);
ret = get_any_page(page, pfn, 0);
if (ret < 0)
return ret;
if (ret == 0)
goto done;
}
if (!PageLRU(page)) {
pr_info("soft_offline: %#lx: unknown non LRU page type %lx\n",
pfn, page->flags);
return -EIO;
}
lock_page(page);
wait_on_page_writeback(page);
if (PageHWPoison(page)) {
unlock_page(page);
put_page(page);
pr_info("soft offline: %#lx page already poisoned\n", pfn);
return -EBUSY;
}
ret = invalidate_inode_page(page);
unlock_page(page);
if (ret == 1) {
put_page(page);
ret = 0;
pr_info("soft_offline: %#lx: invalidated\n", pfn);
goto done;
}
ret = isolate_lru_page(page);
put_page(page);
if (!ret) {
LIST_HEAD(pagelist);
inc_zone_page_state(page, NR_ISOLATED_ANON +
page_is_file_cache(page));
list_add(&page->lru, &pagelist);
ret = migrate_pages(&pagelist, new_page, MPOL_MF_MOVE_ALL,
false, MIGRATE_SYNC);
if (ret) {
putback_lru_pages(&pagelist);
pr_info("soft offline: %#lx: migration failed %d, type %lx\n",
pfn, ret, page->flags);
if (ret > 0)
ret = -EIO;
}
} else {
pr_info("soft offline: %#lx: isolation failed: %d, page count %d, type %lx\n",
pfn, ret, page_count(page), page->flags);
}
if (ret)
return ret;
done:
atomic_long_add(1, &mce_bad_pages);
SetPageHWPoison(page);
return ret;
}
