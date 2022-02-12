void task_mem(struct seq_file *m, struct mm_struct *mm)
{
unsigned long text, lib, swap, ptes, pmds, anon, file, shmem;
unsigned long hiwater_vm, total_vm, hiwater_rss, total_rss;
anon = get_mm_counter(mm, MM_ANONPAGES);
file = get_mm_counter(mm, MM_FILEPAGES);
shmem = get_mm_counter(mm, MM_SHMEMPAGES);
hiwater_vm = total_vm = mm->total_vm;
if (hiwater_vm < mm->hiwater_vm)
hiwater_vm = mm->hiwater_vm;
hiwater_rss = total_rss = anon + file + shmem;
if (hiwater_rss < mm->hiwater_rss)
hiwater_rss = mm->hiwater_rss;
text = (PAGE_ALIGN(mm->end_code) - (mm->start_code & PAGE_MASK)) >> 10;
lib = (mm->exec_vm << (PAGE_SHIFT-10)) - text;
swap = get_mm_counter(mm, MM_SWAPENTS);
ptes = PTRS_PER_PTE * sizeof(pte_t) * atomic_long_read(&mm->nr_ptes);
pmds = PTRS_PER_PMD * sizeof(pmd_t) * mm_nr_pmds(mm);
seq_printf(m,
"VmPeak:\t%8lu kB\n"
"VmSize:\t%8lu kB\n"
"VmLck:\t%8lu kB\n"
"VmPin:\t%8lu kB\n"
"VmHWM:\t%8lu kB\n"
"VmRSS:\t%8lu kB\n"
"RssAnon:\t%8lu kB\n"
"RssFile:\t%8lu kB\n"
"RssShmem:\t%8lu kB\n"
"VmData:\t%8lu kB\n"
"VmStk:\t%8lu kB\n"
"VmExe:\t%8lu kB\n"
"VmLib:\t%8lu kB\n"
"VmPTE:\t%8lu kB\n"
"VmPMD:\t%8lu kB\n"
"VmSwap:\t%8lu kB\n",
hiwater_vm << (PAGE_SHIFT-10),
total_vm << (PAGE_SHIFT-10),
mm->locked_vm << (PAGE_SHIFT-10),
mm->pinned_vm << (PAGE_SHIFT-10),
hiwater_rss << (PAGE_SHIFT-10),
total_rss << (PAGE_SHIFT-10),
anon << (PAGE_SHIFT-10),
file << (PAGE_SHIFT-10),
shmem << (PAGE_SHIFT-10),
mm->data_vm << (PAGE_SHIFT-10),
mm->stack_vm << (PAGE_SHIFT-10), text, lib,
ptes >> 10,
pmds >> 10,
swap << (PAGE_SHIFT-10));
hugetlb_report_usage(m, mm);
}
unsigned long task_vsize(struct mm_struct *mm)
{
return PAGE_SIZE * mm->total_vm;
}
unsigned long task_statm(struct mm_struct *mm,
unsigned long *shared, unsigned long *text,
unsigned long *data, unsigned long *resident)
{
*shared = get_mm_counter(mm, MM_FILEPAGES) +
get_mm_counter(mm, MM_SHMEMPAGES);
*text = (PAGE_ALIGN(mm->end_code) - (mm->start_code & PAGE_MASK))
>> PAGE_SHIFT;
*data = mm->data_vm + mm->stack_vm;
*resident = *shared + get_mm_counter(mm, MM_ANONPAGES);
return mm->total_vm;
}
static void hold_task_mempolicy(struct proc_maps_private *priv)
{
struct task_struct *task = priv->task;
task_lock(task);
priv->task_mempolicy = get_task_policy(task);
mpol_get(priv->task_mempolicy);
task_unlock(task);
}
static void release_task_mempolicy(struct proc_maps_private *priv)
{
mpol_put(priv->task_mempolicy);
}
static void hold_task_mempolicy(struct proc_maps_private *priv)
{
}
static void release_task_mempolicy(struct proc_maps_private *priv)
{
}
static void vma_stop(struct proc_maps_private *priv)
{
struct mm_struct *mm = priv->mm;
release_task_mempolicy(priv);
up_read(&mm->mmap_sem);
mmput(mm);
}
static struct vm_area_struct *
m_next_vma(struct proc_maps_private *priv, struct vm_area_struct *vma)
{
if (vma == priv->tail_vma)
return NULL;
return vma->vm_next ?: priv->tail_vma;
}
static void m_cache_vma(struct seq_file *m, struct vm_area_struct *vma)
{
if (m->count < m->size)
m->version = m_next_vma(m->private, vma) ? vma->vm_start : -1UL;
}
static void *m_start(struct seq_file *m, loff_t *ppos)
{
struct proc_maps_private *priv = m->private;
unsigned long last_addr = m->version;
struct mm_struct *mm;
struct vm_area_struct *vma;
unsigned int pos = *ppos;
if (last_addr == -1UL)
return NULL;
priv->task = get_proc_task(priv->inode);
if (!priv->task)
return ERR_PTR(-ESRCH);
mm = priv->mm;
if (!mm || !atomic_inc_not_zero(&mm->mm_users))
return NULL;
down_read(&mm->mmap_sem);
hold_task_mempolicy(priv);
priv->tail_vma = get_gate_vma(mm);
if (last_addr) {
vma = find_vma(mm, last_addr);
if (vma && (vma = m_next_vma(priv, vma)))
return vma;
}
m->version = 0;
if (pos < mm->map_count) {
for (vma = mm->mmap; pos; pos--) {
m->version = vma->vm_start;
vma = vma->vm_next;
}
return vma;
}
if (pos == mm->map_count && priv->tail_vma)
return priv->tail_vma;
vma_stop(priv);
return NULL;
}
static void *m_next(struct seq_file *m, void *v, loff_t *pos)
{
struct proc_maps_private *priv = m->private;
struct vm_area_struct *next;
(*pos)++;
next = m_next_vma(priv, v);
if (!next)
vma_stop(priv);
return next;
}
static void m_stop(struct seq_file *m, void *v)
{
struct proc_maps_private *priv = m->private;
if (!IS_ERR_OR_NULL(v))
vma_stop(priv);
if (priv->task) {
put_task_struct(priv->task);
priv->task = NULL;
}
}
static int proc_maps_open(struct inode *inode, struct file *file,
const struct seq_operations *ops, int psize)
{
struct proc_maps_private *priv = __seq_open_private(file, ops, psize);
if (!priv)
return -ENOMEM;
priv->inode = inode;
priv->mm = proc_mem_open(inode, PTRACE_MODE_READ);
if (IS_ERR(priv->mm)) {
int err = PTR_ERR(priv->mm);
seq_release_private(inode, file);
return err;
}
return 0;
}
static int proc_map_release(struct inode *inode, struct file *file)
{
struct seq_file *seq = file->private_data;
struct proc_maps_private *priv = seq->private;
if (priv->mm)
mmdrop(priv->mm);
return seq_release_private(inode, file);
}
static int do_maps_open(struct inode *inode, struct file *file,
const struct seq_operations *ops)
{
return proc_maps_open(inode, file, ops,
sizeof(struct proc_maps_private));
}
static int is_stack(struct proc_maps_private *priv,
struct vm_area_struct *vma, int is_pid)
{
int stack = 0;
if (is_pid) {
stack = vma->vm_start <= vma->vm_mm->start_stack &&
vma->vm_end >= vma->vm_mm->start_stack;
} else {
struct inode *inode = priv->inode;
struct task_struct *task;
rcu_read_lock();
task = pid_task(proc_pid(inode), PIDTYPE_PID);
if (task)
stack = vma_is_stack_for_task(vma, task);
rcu_read_unlock();
}
return stack;
}
static void
show_map_vma(struct seq_file *m, struct vm_area_struct *vma, int is_pid)
{
struct mm_struct *mm = vma->vm_mm;
struct file *file = vma->vm_file;
struct proc_maps_private *priv = m->private;
vm_flags_t flags = vma->vm_flags;
unsigned long ino = 0;
unsigned long long pgoff = 0;
unsigned long start, end;
dev_t dev = 0;
const char *name = NULL;
if (file) {
struct inode *inode = file_inode(vma->vm_file);
dev = inode->i_sb->s_dev;
ino = inode->i_ino;
pgoff = ((loff_t)vma->vm_pgoff) << PAGE_SHIFT;
}
start = vma->vm_start;
if (stack_guard_page_start(vma, start))
start += PAGE_SIZE;
end = vma->vm_end;
if (stack_guard_page_end(vma, end))
end -= PAGE_SIZE;
seq_setwidth(m, 25 + sizeof(void *) * 6 - 1);
seq_printf(m, "%08lx-%08lx %c%c%c%c %08llx %02x:%02x %lu ",
start,
end,
flags & VM_READ ? 'r' : '-',
flags & VM_WRITE ? 'w' : '-',
flags & VM_EXEC ? 'x' : '-',
flags & VM_MAYSHARE ? 's' : 'p',
pgoff,
MAJOR(dev), MINOR(dev), ino);
if (file) {
seq_pad(m, ' ');
seq_file_path(m, file, "\n");
goto done;
}
if (vma->vm_ops && vma->vm_ops->name) {
name = vma->vm_ops->name(vma);
if (name)
goto done;
}
name = arch_vma_name(vma);
if (!name) {
if (!mm) {
name = "[vdso]";
goto done;
}
if (vma->vm_start <= mm->brk &&
vma->vm_end >= mm->start_brk) {
name = "[heap]";
goto done;
}
if (is_stack(priv, vma, is_pid))
name = "[stack]";
}
done:
if (name) {
seq_pad(m, ' ');
seq_puts(m, name);
}
seq_putc(m, '\n');
}
static int show_map(struct seq_file *m, void *v, int is_pid)
{
show_map_vma(m, v, is_pid);
m_cache_vma(m, v);
return 0;
}
static int show_pid_map(struct seq_file *m, void *v)
{
return show_map(m, v, 1);
}
static int show_tid_map(struct seq_file *m, void *v)
{
return show_map(m, v, 0);
}
static int pid_maps_open(struct inode *inode, struct file *file)
{
return do_maps_open(inode, file, &proc_pid_maps_op);
}
static int tid_maps_open(struct inode *inode, struct file *file)
{
return do_maps_open(inode, file, &proc_tid_maps_op);
}
static void smaps_account(struct mem_size_stats *mss, struct page *page,
bool compound, bool young, bool dirty)
{
int i, nr = compound ? 1 << compound_order(page) : 1;
unsigned long size = nr * PAGE_SIZE;
if (PageAnon(page))
mss->anonymous += size;
mss->resident += size;
if (young || page_is_young(page) || PageReferenced(page))
mss->referenced += size;
if (page_count(page) == 1) {
if (dirty || PageDirty(page))
mss->private_dirty += size;
else
mss->private_clean += size;
mss->pss += (u64)size << PSS_SHIFT;
return;
}
for (i = 0; i < nr; i++, page++) {
int mapcount = page_mapcount(page);
if (mapcount >= 2) {
if (dirty || PageDirty(page))
mss->shared_dirty += PAGE_SIZE;
else
mss->shared_clean += PAGE_SIZE;
mss->pss += (PAGE_SIZE << PSS_SHIFT) / mapcount;
} else {
if (dirty || PageDirty(page))
mss->private_dirty += PAGE_SIZE;
else
mss->private_clean += PAGE_SIZE;
mss->pss += PAGE_SIZE << PSS_SHIFT;
}
}
}
static int smaps_pte_hole(unsigned long addr, unsigned long end,
struct mm_walk *walk)
{
struct mem_size_stats *mss = walk->private;
mss->swap += shmem_partial_swap_usage(
walk->vma->vm_file->f_mapping, addr, end);
return 0;
}
static void smaps_pte_entry(pte_t *pte, unsigned long addr,
struct mm_walk *walk)
{
struct mem_size_stats *mss = walk->private;
struct vm_area_struct *vma = walk->vma;
struct page *page = NULL;
if (pte_present(*pte)) {
page = vm_normal_page(vma, addr, *pte);
} else if (is_swap_pte(*pte)) {
swp_entry_t swpent = pte_to_swp_entry(*pte);
if (!non_swap_entry(swpent)) {
int mapcount;
mss->swap += PAGE_SIZE;
mapcount = swp_swapcount(swpent);
if (mapcount >= 2) {
u64 pss_delta = (u64)PAGE_SIZE << PSS_SHIFT;
do_div(pss_delta, mapcount);
mss->swap_pss += pss_delta;
} else {
mss->swap_pss += (u64)PAGE_SIZE << PSS_SHIFT;
}
} else if (is_migration_entry(swpent))
page = migration_entry_to_page(swpent);
} else if (unlikely(IS_ENABLED(CONFIG_SHMEM) && mss->check_shmem_swap
&& pte_none(*pte))) {
page = find_get_entry(vma->vm_file->f_mapping,
linear_page_index(vma, addr));
if (!page)
return;
if (radix_tree_exceptional_entry(page))
mss->swap += PAGE_SIZE;
else
page_cache_release(page);
return;
}
if (!page)
return;
smaps_account(mss, page, false, pte_young(*pte), pte_dirty(*pte));
}
static void smaps_pmd_entry(pmd_t *pmd, unsigned long addr,
struct mm_walk *walk)
{
struct mem_size_stats *mss = walk->private;
struct vm_area_struct *vma = walk->vma;
struct page *page;
page = follow_trans_huge_pmd(vma, addr, pmd, FOLL_DUMP);
if (IS_ERR_OR_NULL(page))
return;
mss->anonymous_thp += HPAGE_PMD_SIZE;
smaps_account(mss, page, true, pmd_young(*pmd), pmd_dirty(*pmd));
}
static void smaps_pmd_entry(pmd_t *pmd, unsigned long addr,
struct mm_walk *walk)
{
}
static int smaps_pte_range(pmd_t *pmd, unsigned long addr, unsigned long end,
struct mm_walk *walk)
{
struct vm_area_struct *vma = walk->vma;
pte_t *pte;
spinlock_t *ptl;
ptl = pmd_trans_huge_lock(pmd, vma);
if (ptl) {
smaps_pmd_entry(pmd, addr, walk);
spin_unlock(ptl);
return 0;
}
if (pmd_trans_unstable(pmd))
return 0;
pte = pte_offset_map_lock(vma->vm_mm, pmd, addr, &ptl);
for (; addr != end; pte++, addr += PAGE_SIZE)
smaps_pte_entry(pte, addr, walk);
pte_unmap_unlock(pte - 1, ptl);
cond_resched();
return 0;
}
static void show_smap_vma_flags(struct seq_file *m, struct vm_area_struct *vma)
{
static const char mnemonics[BITS_PER_LONG][2] = {
[0 ... (BITS_PER_LONG-1)] = "??",
[ilog2(VM_READ)] = "rd",
[ilog2(VM_WRITE)] = "wr",
[ilog2(VM_EXEC)] = "ex",
[ilog2(VM_SHARED)] = "sh",
[ilog2(VM_MAYREAD)] = "mr",
[ilog2(VM_MAYWRITE)] = "mw",
[ilog2(VM_MAYEXEC)] = "me",
[ilog2(VM_MAYSHARE)] = "ms",
[ilog2(VM_GROWSDOWN)] = "gd",
[ilog2(VM_PFNMAP)] = "pf",
[ilog2(VM_DENYWRITE)] = "dw",
#ifdef CONFIG_X86_INTEL_MPX
[ilog2(VM_MPX)] = "mp",
#endif
[ilog2(VM_LOCKED)] = "lo",
[ilog2(VM_IO)] = "io",
[ilog2(VM_SEQ_READ)] = "sr",
[ilog2(VM_RAND_READ)] = "rr",
[ilog2(VM_DONTCOPY)] = "dc",
[ilog2(VM_DONTEXPAND)] = "de",
[ilog2(VM_ACCOUNT)] = "ac",
[ilog2(VM_NORESERVE)] = "nr",
[ilog2(VM_HUGETLB)] = "ht",
[ilog2(VM_ARCH_1)] = "ar",
[ilog2(VM_DONTDUMP)] = "dd",
#ifdef CONFIG_MEM_SOFT_DIRTY
[ilog2(VM_SOFTDIRTY)] = "sd",
#endif
[ilog2(VM_MIXEDMAP)] = "mm",
[ilog2(VM_HUGEPAGE)] = "hg",
[ilog2(VM_NOHUGEPAGE)] = "nh",
[ilog2(VM_MERGEABLE)] = "mg",
[ilog2(VM_UFFD_MISSING)]= "um",
[ilog2(VM_UFFD_WP)] = "uw",
};
size_t i;
seq_puts(m, "VmFlags: ");
for (i = 0; i < BITS_PER_LONG; i++) {
if (vma->vm_flags & (1UL << i)) {
seq_printf(m, "%c%c ",
mnemonics[i][0], mnemonics[i][1]);
}
}
seq_putc(m, '\n');
}
static int smaps_hugetlb_range(pte_t *pte, unsigned long hmask,
unsigned long addr, unsigned long end,
struct mm_walk *walk)
{
struct mem_size_stats *mss = walk->private;
struct vm_area_struct *vma = walk->vma;
struct page *page = NULL;
if (pte_present(*pte)) {
page = vm_normal_page(vma, addr, *pte);
} else if (is_swap_pte(*pte)) {
swp_entry_t swpent = pte_to_swp_entry(*pte);
if (is_migration_entry(swpent))
page = migration_entry_to_page(swpent);
}
if (page) {
int mapcount = page_mapcount(page);
if (mapcount >= 2)
mss->shared_hugetlb += huge_page_size(hstate_vma(vma));
else
mss->private_hugetlb += huge_page_size(hstate_vma(vma));
}
return 0;
}
static int show_smap(struct seq_file *m, void *v, int is_pid)
{
struct vm_area_struct *vma = v;
struct mem_size_stats mss;
struct mm_walk smaps_walk = {
.pmd_entry = smaps_pte_range,
#ifdef CONFIG_HUGETLB_PAGE
.hugetlb_entry = smaps_hugetlb_range,
#endif
.mm = vma->vm_mm,
.private = &mss,
};
memset(&mss, 0, sizeof mss);
#ifdef CONFIG_SHMEM
if (vma->vm_file && shmem_mapping(vma->vm_file->f_mapping)) {
unsigned long shmem_swapped = shmem_swap_usage(vma);
if (!shmem_swapped || (vma->vm_flags & VM_SHARED) ||
!(vma->vm_flags & VM_WRITE)) {
mss.swap = shmem_swapped;
} else {
mss.check_shmem_swap = true;
smaps_walk.pte_hole = smaps_pte_hole;
}
}
#endif
walk_page_vma(vma, &smaps_walk);
show_map_vma(m, vma, is_pid);
seq_printf(m,
"Size: %8lu kB\n"
"Rss: %8lu kB\n"
"Pss: %8lu kB\n"
"Shared_Clean: %8lu kB\n"
"Shared_Dirty: %8lu kB\n"
"Private_Clean: %8lu kB\n"
"Private_Dirty: %8lu kB\n"
"Referenced: %8lu kB\n"
"Anonymous: %8lu kB\n"
"AnonHugePages: %8lu kB\n"
"Shared_Hugetlb: %8lu kB\n"
"Private_Hugetlb: %7lu kB\n"
"Swap: %8lu kB\n"
"SwapPss: %8lu kB\n"
"KernelPageSize: %8lu kB\n"
"MMUPageSize: %8lu kB\n"
"Locked: %8lu kB\n",
(vma->vm_end - vma->vm_start) >> 10,
mss.resident >> 10,
(unsigned long)(mss.pss >> (10 + PSS_SHIFT)),
mss.shared_clean >> 10,
mss.shared_dirty >> 10,
mss.private_clean >> 10,
mss.private_dirty >> 10,
mss.referenced >> 10,
mss.anonymous >> 10,
mss.anonymous_thp >> 10,
mss.shared_hugetlb >> 10,
mss.private_hugetlb >> 10,
mss.swap >> 10,
(unsigned long)(mss.swap_pss >> (10 + PSS_SHIFT)),
vma_kernel_pagesize(vma) >> 10,
vma_mmu_pagesize(vma) >> 10,
(vma->vm_flags & VM_LOCKED) ?
(unsigned long)(mss.pss >> (10 + PSS_SHIFT)) : 0);
show_smap_vma_flags(m, vma);
m_cache_vma(m, vma);
return 0;
}
static int show_pid_smap(struct seq_file *m, void *v)
{
return show_smap(m, v, 1);
}
static int show_tid_smap(struct seq_file *m, void *v)
{
return show_smap(m, v, 0);
}
static int pid_smaps_open(struct inode *inode, struct file *file)
{
return do_maps_open(inode, file, &proc_pid_smaps_op);
}
static int tid_smaps_open(struct inode *inode, struct file *file)
{
return do_maps_open(inode, file, &proc_tid_smaps_op);
}
static inline void clear_soft_dirty(struct vm_area_struct *vma,
unsigned long addr, pte_t *pte)
{
pte_t ptent = *pte;
if (pte_present(ptent)) {
ptent = ptep_modify_prot_start(vma->vm_mm, addr, pte);
ptent = pte_wrprotect(ptent);
ptent = pte_clear_soft_dirty(ptent);
ptep_modify_prot_commit(vma->vm_mm, addr, pte, ptent);
} else if (is_swap_pte(ptent)) {
ptent = pte_swp_clear_soft_dirty(ptent);
set_pte_at(vma->vm_mm, addr, pte, ptent);
}
}
static inline void clear_soft_dirty(struct vm_area_struct *vma,
unsigned long addr, pte_t *pte)
{
}
static inline void clear_soft_dirty_pmd(struct vm_area_struct *vma,
unsigned long addr, pmd_t *pmdp)
{
pmd_t pmd = pmdp_huge_get_and_clear(vma->vm_mm, addr, pmdp);
pmd = pmd_wrprotect(pmd);
pmd = pmd_clear_soft_dirty(pmd);
set_pmd_at(vma->vm_mm, addr, pmdp, pmd);
}
static inline void clear_soft_dirty_pmd(struct vm_area_struct *vma,
unsigned long addr, pmd_t *pmdp)
{
}
static int clear_refs_pte_range(pmd_t *pmd, unsigned long addr,
unsigned long end, struct mm_walk *walk)
{
struct clear_refs_private *cp = walk->private;
struct vm_area_struct *vma = walk->vma;
pte_t *pte, ptent;
spinlock_t *ptl;
struct page *page;
ptl = pmd_trans_huge_lock(pmd, vma);
if (ptl) {
if (cp->type == CLEAR_REFS_SOFT_DIRTY) {
clear_soft_dirty_pmd(vma, addr, pmd);
goto out;
}
page = pmd_page(*pmd);
pmdp_test_and_clear_young(vma, addr, pmd);
test_and_clear_page_young(page);
ClearPageReferenced(page);
out:
spin_unlock(ptl);
return 0;
}
if (pmd_trans_unstable(pmd))
return 0;
pte = pte_offset_map_lock(vma->vm_mm, pmd, addr, &ptl);
for (; addr != end; pte++, addr += PAGE_SIZE) {
ptent = *pte;
if (cp->type == CLEAR_REFS_SOFT_DIRTY) {
clear_soft_dirty(vma, addr, pte);
continue;
}
if (!pte_present(ptent))
continue;
page = vm_normal_page(vma, addr, ptent);
if (!page)
continue;
ptep_test_and_clear_young(vma, addr, pte);
test_and_clear_page_young(page);
ClearPageReferenced(page);
}
pte_unmap_unlock(pte - 1, ptl);
cond_resched();
return 0;
}
static int clear_refs_test_walk(unsigned long start, unsigned long end,
struct mm_walk *walk)
{
struct clear_refs_private *cp = walk->private;
struct vm_area_struct *vma = walk->vma;
if (vma->vm_flags & VM_PFNMAP)
return 1;
if (cp->type == CLEAR_REFS_ANON && vma->vm_file)
return 1;
if (cp->type == CLEAR_REFS_MAPPED && !vma->vm_file)
return 1;
return 0;
}
static ssize_t clear_refs_write(struct file *file, const char __user *buf,
size_t count, loff_t *ppos)
{
struct task_struct *task;
char buffer[PROC_NUMBUF];
struct mm_struct *mm;
struct vm_area_struct *vma;
enum clear_refs_types type;
int itype;
int rv;
memset(buffer, 0, sizeof(buffer));
if (count > sizeof(buffer) - 1)
count = sizeof(buffer) - 1;
if (copy_from_user(buffer, buf, count))
return -EFAULT;
rv = kstrtoint(strstrip(buffer), 10, &itype);
if (rv < 0)
return rv;
type = (enum clear_refs_types)itype;
if (type < CLEAR_REFS_ALL || type >= CLEAR_REFS_LAST)
return -EINVAL;
task = get_proc_task(file_inode(file));
if (!task)
return -ESRCH;
mm = get_task_mm(task);
if (mm) {
struct clear_refs_private cp = {
.type = type,
};
struct mm_walk clear_refs_walk = {
.pmd_entry = clear_refs_pte_range,
.test_walk = clear_refs_test_walk,
.mm = mm,
.private = &cp,
};
if (type == CLEAR_REFS_MM_HIWATER_RSS) {
down_write(&mm->mmap_sem);
reset_mm_hiwater_rss(mm);
up_write(&mm->mmap_sem);
goto out_mm;
}
down_read(&mm->mmap_sem);
if (type == CLEAR_REFS_SOFT_DIRTY) {
for (vma = mm->mmap; vma; vma = vma->vm_next) {
if (!(vma->vm_flags & VM_SOFTDIRTY))
continue;
up_read(&mm->mmap_sem);
down_write(&mm->mmap_sem);
for (vma = mm->mmap; vma; vma = vma->vm_next) {
vma->vm_flags &= ~VM_SOFTDIRTY;
vma_set_page_prot(vma);
}
downgrade_write(&mm->mmap_sem);
break;
}
mmu_notifier_invalidate_range_start(mm, 0, -1);
}
walk_page_range(0, ~0UL, &clear_refs_walk);
if (type == CLEAR_REFS_SOFT_DIRTY)
mmu_notifier_invalidate_range_end(mm, 0, -1);
flush_tlb_mm(mm);
up_read(&mm->mmap_sem);
out_mm:
mmput(mm);
}
put_task_struct(task);
return count;
}
static inline pagemap_entry_t make_pme(u64 frame, u64 flags)
{
return (pagemap_entry_t) { .pme = (frame & PM_PFRAME_MASK) | flags };
}
static int add_to_pagemap(unsigned long addr, pagemap_entry_t *pme,
struct pagemapread *pm)
{
pm->buffer[pm->pos++] = *pme;
if (pm->pos >= pm->len)
return PM_END_OF_BUFFER;
return 0;
}
static int pagemap_pte_hole(unsigned long start, unsigned long end,
struct mm_walk *walk)
{
struct pagemapread *pm = walk->private;
unsigned long addr = start;
int err = 0;
while (addr < end) {
struct vm_area_struct *vma = find_vma(walk->mm, addr);
pagemap_entry_t pme = make_pme(0, 0);
unsigned long hole_end;
if (vma)
hole_end = min(end, vma->vm_start);
else
hole_end = end;
for (; addr < hole_end; addr += PAGE_SIZE) {
err = add_to_pagemap(addr, &pme, pm);
if (err)
goto out;
}
if (!vma)
break;
if (vma->vm_flags & VM_SOFTDIRTY)
pme = make_pme(0, PM_SOFT_DIRTY);
for (; addr < min(end, vma->vm_end); addr += PAGE_SIZE) {
err = add_to_pagemap(addr, &pme, pm);
if (err)
goto out;
}
}
out:
return err;
}
static pagemap_entry_t pte_to_pagemap_entry(struct pagemapread *pm,
struct vm_area_struct *vma, unsigned long addr, pte_t pte)
{
u64 frame = 0, flags = 0;
struct page *page = NULL;
if (pte_present(pte)) {
if (pm->show_pfn)
frame = pte_pfn(pte);
flags |= PM_PRESENT;
page = vm_normal_page(vma, addr, pte);
if (pte_soft_dirty(pte))
flags |= PM_SOFT_DIRTY;
} else if (is_swap_pte(pte)) {
swp_entry_t entry;
if (pte_swp_soft_dirty(pte))
flags |= PM_SOFT_DIRTY;
entry = pte_to_swp_entry(pte);
frame = swp_type(entry) |
(swp_offset(entry) << MAX_SWAPFILES_SHIFT);
flags |= PM_SWAP;
if (is_migration_entry(entry))
page = migration_entry_to_page(entry);
}
if (page && !PageAnon(page))
flags |= PM_FILE;
if (page && page_mapcount(page) == 1)
flags |= PM_MMAP_EXCLUSIVE;
if (vma->vm_flags & VM_SOFTDIRTY)
flags |= PM_SOFT_DIRTY;
return make_pme(frame, flags);
}
static int pagemap_pmd_range(pmd_t *pmdp, unsigned long addr, unsigned long end,
struct mm_walk *walk)
{
struct vm_area_struct *vma = walk->vma;
struct pagemapread *pm = walk->private;
spinlock_t *ptl;
pte_t *pte, *orig_pte;
int err = 0;
#ifdef CONFIG_TRANSPARENT_HUGEPAGE
ptl = pmd_trans_huge_lock(pmdp, vma);
if (ptl) {
u64 flags = 0, frame = 0;
pmd_t pmd = *pmdp;
if ((vma->vm_flags & VM_SOFTDIRTY) || pmd_soft_dirty(pmd))
flags |= PM_SOFT_DIRTY;
if (pmd_present(pmd)) {
struct page *page = pmd_page(pmd);
if (page_mapcount(page) == 1)
flags |= PM_MMAP_EXCLUSIVE;
flags |= PM_PRESENT;
if (pm->show_pfn)
frame = pmd_pfn(pmd) +
((addr & ~PMD_MASK) >> PAGE_SHIFT);
}
for (; addr != end; addr += PAGE_SIZE) {
pagemap_entry_t pme = make_pme(frame, flags);
err = add_to_pagemap(addr, &pme, pm);
if (err)
break;
if (pm->show_pfn && (flags & PM_PRESENT))
frame++;
}
spin_unlock(ptl);
return err;
}
if (pmd_trans_unstable(pmdp))
return 0;
#endif
orig_pte = pte = pte_offset_map_lock(walk->mm, pmdp, addr, &ptl);
for (; addr < end; pte++, addr += PAGE_SIZE) {
pagemap_entry_t pme;
pme = pte_to_pagemap_entry(pm, vma, addr, *pte);
err = add_to_pagemap(addr, &pme, pm);
if (err)
break;
}
pte_unmap_unlock(orig_pte, ptl);
cond_resched();
return err;
}
static int pagemap_hugetlb_range(pte_t *ptep, unsigned long hmask,
unsigned long addr, unsigned long end,
struct mm_walk *walk)
{
struct pagemapread *pm = walk->private;
struct vm_area_struct *vma = walk->vma;
u64 flags = 0, frame = 0;
int err = 0;
pte_t pte;
if (vma->vm_flags & VM_SOFTDIRTY)
flags |= PM_SOFT_DIRTY;
pte = huge_ptep_get(ptep);
if (pte_present(pte)) {
struct page *page = pte_page(pte);
if (!PageAnon(page))
flags |= PM_FILE;
if (page_mapcount(page) == 1)
flags |= PM_MMAP_EXCLUSIVE;
flags |= PM_PRESENT;
if (pm->show_pfn)
frame = pte_pfn(pte) +
((addr & ~hmask) >> PAGE_SHIFT);
}
for (; addr != end; addr += PAGE_SIZE) {
pagemap_entry_t pme = make_pme(frame, flags);
err = add_to_pagemap(addr, &pme, pm);
if (err)
return err;
if (pm->show_pfn && (flags & PM_PRESENT))
frame++;
}
cond_resched();
return err;
}
static ssize_t pagemap_read(struct file *file, char __user *buf,
size_t count, loff_t *ppos)
{
struct mm_struct *mm = file->private_data;
struct pagemapread pm;
struct mm_walk pagemap_walk = {};
unsigned long src;
unsigned long svpfn;
unsigned long start_vaddr;
unsigned long end_vaddr;
int ret = 0, copied = 0;
if (!mm || !atomic_inc_not_zero(&mm->mm_users))
goto out;
ret = -EINVAL;
if ((*ppos % PM_ENTRY_BYTES) || (count % PM_ENTRY_BYTES))
goto out_mm;
ret = 0;
if (!count)
goto out_mm;
pm.show_pfn = file_ns_capable(file, &init_user_ns, CAP_SYS_ADMIN);
pm.len = (PAGEMAP_WALK_SIZE >> PAGE_SHIFT);
pm.buffer = kmalloc(pm.len * PM_ENTRY_BYTES, GFP_TEMPORARY);
ret = -ENOMEM;
if (!pm.buffer)
goto out_mm;
pagemap_walk.pmd_entry = pagemap_pmd_range;
pagemap_walk.pte_hole = pagemap_pte_hole;
#ifdef CONFIG_HUGETLB_PAGE
pagemap_walk.hugetlb_entry = pagemap_hugetlb_range;
#endif
pagemap_walk.mm = mm;
pagemap_walk.private = &pm;
src = *ppos;
svpfn = src / PM_ENTRY_BYTES;
start_vaddr = svpfn << PAGE_SHIFT;
end_vaddr = mm->task_size;
if (svpfn > mm->task_size >> PAGE_SHIFT)
start_vaddr = end_vaddr;
ret = 0;
while (count && (start_vaddr < end_vaddr)) {
int len;
unsigned long end;
pm.pos = 0;
end = (start_vaddr + PAGEMAP_WALK_SIZE) & PAGEMAP_WALK_MASK;
if (end < start_vaddr || end > end_vaddr)
end = end_vaddr;
down_read(&mm->mmap_sem);
ret = walk_page_range(start_vaddr, end, &pagemap_walk);
up_read(&mm->mmap_sem);
start_vaddr = end;
len = min(count, PM_ENTRY_BYTES * pm.pos);
if (copy_to_user(buf, pm.buffer, len)) {
ret = -EFAULT;
goto out_free;
}
copied += len;
buf += len;
count -= len;
}
*ppos += copied;
if (!ret || ret == PM_END_OF_BUFFER)
ret = copied;
out_free:
kfree(pm.buffer);
out_mm:
mmput(mm);
out:
return ret;
}
static int pagemap_open(struct inode *inode, struct file *file)
{
struct mm_struct *mm;
mm = proc_mem_open(inode, PTRACE_MODE_READ);
if (IS_ERR(mm))
return PTR_ERR(mm);
file->private_data = mm;
return 0;
}
static int pagemap_release(struct inode *inode, struct file *file)
{
struct mm_struct *mm = file->private_data;
if (mm)
mmdrop(mm);
return 0;
}
static void gather_stats(struct page *page, struct numa_maps *md, int pte_dirty,
unsigned long nr_pages)
{
int count = page_mapcount(page);
md->pages += nr_pages;
if (pte_dirty || PageDirty(page))
md->dirty += nr_pages;
if (PageSwapCache(page))
md->swapcache += nr_pages;
if (PageActive(page) || PageUnevictable(page))
md->active += nr_pages;
if (PageWriteback(page))
md->writeback += nr_pages;
if (PageAnon(page))
md->anon += nr_pages;
if (count > md->mapcount_max)
md->mapcount_max = count;
md->node[page_to_nid(page)] += nr_pages;
}
static struct page *can_gather_numa_stats(pte_t pte, struct vm_area_struct *vma,
unsigned long addr)
{
struct page *page;
int nid;
if (!pte_present(pte))
return NULL;
page = vm_normal_page(vma, addr, pte);
if (!page)
return NULL;
if (PageReserved(page))
return NULL;
nid = page_to_nid(page);
if (!node_isset(nid, node_states[N_MEMORY]))
return NULL;
return page;
}
static int gather_pte_stats(pmd_t *pmd, unsigned long addr,
unsigned long end, struct mm_walk *walk)
{
struct numa_maps *md = walk->private;
struct vm_area_struct *vma = walk->vma;
spinlock_t *ptl;
pte_t *orig_pte;
pte_t *pte;
ptl = pmd_trans_huge_lock(pmd, vma);
if (ptl) {
pte_t huge_pte = *(pte_t *)pmd;
struct page *page;
page = can_gather_numa_stats(huge_pte, vma, addr);
if (page)
gather_stats(page, md, pte_dirty(huge_pte),
HPAGE_PMD_SIZE/PAGE_SIZE);
spin_unlock(ptl);
return 0;
}
if (pmd_trans_unstable(pmd))
return 0;
orig_pte = pte = pte_offset_map_lock(walk->mm, pmd, addr, &ptl);
do {
struct page *page = can_gather_numa_stats(*pte, vma, addr);
if (!page)
continue;
gather_stats(page, md, pte_dirty(*pte), 1);
} while (pte++, addr += PAGE_SIZE, addr != end);
pte_unmap_unlock(orig_pte, ptl);
return 0;
}
static int gather_hugetlb_stats(pte_t *pte, unsigned long hmask,
unsigned long addr, unsigned long end, struct mm_walk *walk)
{
pte_t huge_pte = huge_ptep_get(pte);
struct numa_maps *md;
struct page *page;
if (!pte_present(huge_pte))
return 0;
page = pte_page(huge_pte);
if (!page)
return 0;
md = walk->private;
gather_stats(page, md, pte_dirty(huge_pte), 1);
return 0;
}
static int gather_hugetlb_stats(pte_t *pte, unsigned long hmask,
unsigned long addr, unsigned long end, struct mm_walk *walk)
{
return 0;
}
static int show_numa_map(struct seq_file *m, void *v, int is_pid)
{
struct numa_maps_private *numa_priv = m->private;
struct proc_maps_private *proc_priv = &numa_priv->proc_maps;
struct vm_area_struct *vma = v;
struct numa_maps *md = &numa_priv->md;
struct file *file = vma->vm_file;
struct mm_struct *mm = vma->vm_mm;
struct mm_walk walk = {
.hugetlb_entry = gather_hugetlb_stats,
.pmd_entry = gather_pte_stats,
.private = md,
.mm = mm,
};
struct mempolicy *pol;
char buffer[64];
int nid;
if (!mm)
return 0;
memset(md, 0, sizeof(*md));
pol = __get_vma_policy(vma, vma->vm_start);
if (pol) {
mpol_to_str(buffer, sizeof(buffer), pol);
mpol_cond_put(pol);
} else {
mpol_to_str(buffer, sizeof(buffer), proc_priv->task_mempolicy);
}
seq_printf(m, "%08lx %s", vma->vm_start, buffer);
if (file) {
seq_puts(m, " file=");
seq_file_path(m, file, "\n\t= ");
} else if (vma->vm_start <= mm->brk && vma->vm_end >= mm->start_brk) {
seq_puts(m, " heap");
} else if (is_stack(proc_priv, vma, is_pid)) {
seq_puts(m, " stack");
}
if (is_vm_hugetlb_page(vma))
seq_puts(m, " huge");
walk_page_vma(vma, &walk);
if (!md->pages)
goto out;
if (md->anon)
seq_printf(m, " anon=%lu", md->anon);
if (md->dirty)
seq_printf(m, " dirty=%lu", md->dirty);
if (md->pages != md->anon && md->pages != md->dirty)
seq_printf(m, " mapped=%lu", md->pages);
if (md->mapcount_max > 1)
seq_printf(m, " mapmax=%lu", md->mapcount_max);
if (md->swapcache)
seq_printf(m, " swapcache=%lu", md->swapcache);
if (md->active < md->pages && !is_vm_hugetlb_page(vma))
seq_printf(m, " active=%lu", md->active);
if (md->writeback)
seq_printf(m, " writeback=%lu", md->writeback);
for_each_node_state(nid, N_MEMORY)
if (md->node[nid])
seq_printf(m, " N%d=%lu", nid, md->node[nid]);
seq_printf(m, " kernelpagesize_kB=%lu", vma_kernel_pagesize(vma) >> 10);
out:
seq_putc(m, '\n');
m_cache_vma(m, vma);
return 0;
}
static int show_pid_numa_map(struct seq_file *m, void *v)
{
return show_numa_map(m, v, 1);
}
static int show_tid_numa_map(struct seq_file *m, void *v)
{
return show_numa_map(m, v, 0);
}
static int numa_maps_open(struct inode *inode, struct file *file,
const struct seq_operations *ops)
{
return proc_maps_open(inode, file, ops,
sizeof(struct numa_maps_private));
}
static int pid_numa_maps_open(struct inode *inode, struct file *file)
{
return numa_maps_open(inode, file, &proc_pid_numa_maps_op);
}
static int tid_numa_maps_open(struct inode *inode, struct file *file)
{
return numa_maps_open(inode, file, &proc_tid_numa_maps_op);
}
