static int set_recommended_min_free_kbytes(void)
{
struct zone *zone;
int nr_zones = 0;
unsigned long recommended_min;
extern int min_free_kbytes;
if (!test_bit(TRANSPARENT_HUGEPAGE_FLAG,
&transparent_hugepage_flags) &&
!test_bit(TRANSPARENT_HUGEPAGE_REQ_MADV_FLAG,
&transparent_hugepage_flags))
return 0;
for_each_populated_zone(zone)
nr_zones++;
recommended_min = pageblock_nr_pages * nr_zones * 2;
recommended_min += pageblock_nr_pages * nr_zones *
MIGRATE_PCPTYPES * MIGRATE_PCPTYPES;
recommended_min = min(recommended_min,
(unsigned long) nr_free_buffer_pages() / 20);
recommended_min <<= (PAGE_SHIFT-10);
if (recommended_min > min_free_kbytes)
min_free_kbytes = recommended_min;
setup_per_zone_wmarks();
return 0;
}
static int start_khugepaged(void)
{
int err = 0;
if (khugepaged_enabled()) {
int wakeup;
if (unlikely(!mm_slot_cache || !mm_slots_hash)) {
err = -ENOMEM;
goto out;
}
mutex_lock(&khugepaged_mutex);
if (!khugepaged_thread)
khugepaged_thread = kthread_run(khugepaged, NULL,
"khugepaged");
if (unlikely(IS_ERR(khugepaged_thread))) {
printk(KERN_ERR
"khugepaged: kthread_run(khugepaged) failed\n");
err = PTR_ERR(khugepaged_thread);
khugepaged_thread = NULL;
}
wakeup = !list_empty(&khugepaged_scan.mm_head);
mutex_unlock(&khugepaged_mutex);
if (wakeup)
wake_up_interruptible(&khugepaged_wait);
set_recommended_min_free_kbytes();
} else
wake_up_interruptible(&khugepaged_wait);
out:
return err;
}
static ssize_t double_flag_show(struct kobject *kobj,
struct kobj_attribute *attr, char *buf,
enum transparent_hugepage_flag enabled,
enum transparent_hugepage_flag req_madv)
{
if (test_bit(enabled, &transparent_hugepage_flags)) {
VM_BUG_ON(test_bit(req_madv, &transparent_hugepage_flags));
return sprintf(buf, "[always] madvise never\n");
} else if (test_bit(req_madv, &transparent_hugepage_flags))
return sprintf(buf, "always [madvise] never\n");
else
return sprintf(buf, "always madvise [never]\n");
}
static ssize_t double_flag_store(struct kobject *kobj,
struct kobj_attribute *attr,
const char *buf, size_t count,
enum transparent_hugepage_flag enabled,
enum transparent_hugepage_flag req_madv)
{
if (!memcmp("always", buf,
min(sizeof("always")-1, count))) {
set_bit(enabled, &transparent_hugepage_flags);
clear_bit(req_madv, &transparent_hugepage_flags);
} else if (!memcmp("madvise", buf,
min(sizeof("madvise")-1, count))) {
clear_bit(enabled, &transparent_hugepage_flags);
set_bit(req_madv, &transparent_hugepage_flags);
} else if (!memcmp("never", buf,
min(sizeof("never")-1, count))) {
clear_bit(enabled, &transparent_hugepage_flags);
clear_bit(req_madv, &transparent_hugepage_flags);
} else
return -EINVAL;
return count;
}
static ssize_t enabled_show(struct kobject *kobj,
struct kobj_attribute *attr, char *buf)
{
return double_flag_show(kobj, attr, buf,
TRANSPARENT_HUGEPAGE_FLAG,
TRANSPARENT_HUGEPAGE_REQ_MADV_FLAG);
}
static ssize_t enabled_store(struct kobject *kobj,
struct kobj_attribute *attr,
const char *buf, size_t count)
{
ssize_t ret;
ret = double_flag_store(kobj, attr, buf, count,
TRANSPARENT_HUGEPAGE_FLAG,
TRANSPARENT_HUGEPAGE_REQ_MADV_FLAG);
if (ret > 0) {
int err = start_khugepaged();
if (err)
ret = err;
}
if (ret > 0 &&
(test_bit(TRANSPARENT_HUGEPAGE_FLAG,
&transparent_hugepage_flags) ||
test_bit(TRANSPARENT_HUGEPAGE_REQ_MADV_FLAG,
&transparent_hugepage_flags)))
set_recommended_min_free_kbytes();
return ret;
}
static ssize_t single_flag_show(struct kobject *kobj,
struct kobj_attribute *attr, char *buf,
enum transparent_hugepage_flag flag)
{
return sprintf(buf, "%d\n",
!!test_bit(flag, &transparent_hugepage_flags));
}
static ssize_t single_flag_store(struct kobject *kobj,
struct kobj_attribute *attr,
const char *buf, size_t count,
enum transparent_hugepage_flag flag)
{
unsigned long value;
int ret;
ret = kstrtoul(buf, 10, &value);
if (ret < 0)
return ret;
if (value > 1)
return -EINVAL;
if (value)
set_bit(flag, &transparent_hugepage_flags);
else
clear_bit(flag, &transparent_hugepage_flags);
return count;
}
static ssize_t defrag_show(struct kobject *kobj,
struct kobj_attribute *attr, char *buf)
{
return double_flag_show(kobj, attr, buf,
TRANSPARENT_HUGEPAGE_DEFRAG_FLAG,
TRANSPARENT_HUGEPAGE_DEFRAG_REQ_MADV_FLAG);
}
static ssize_t defrag_store(struct kobject *kobj,
struct kobj_attribute *attr,
const char *buf, size_t count)
{
return double_flag_store(kobj, attr, buf, count,
TRANSPARENT_HUGEPAGE_DEFRAG_FLAG,
TRANSPARENT_HUGEPAGE_DEFRAG_REQ_MADV_FLAG);
}
static ssize_t debug_cow_show(struct kobject *kobj,
struct kobj_attribute *attr, char *buf)
{
return single_flag_show(kobj, attr, buf,
TRANSPARENT_HUGEPAGE_DEBUG_COW_FLAG);
}
static ssize_t debug_cow_store(struct kobject *kobj,
struct kobj_attribute *attr,
const char *buf, size_t count)
{
return single_flag_store(kobj, attr, buf, count,
TRANSPARENT_HUGEPAGE_DEBUG_COW_FLAG);
}
static ssize_t scan_sleep_millisecs_show(struct kobject *kobj,
struct kobj_attribute *attr,
char *buf)
{
return sprintf(buf, "%u\n", khugepaged_scan_sleep_millisecs);
}
static ssize_t scan_sleep_millisecs_store(struct kobject *kobj,
struct kobj_attribute *attr,
const char *buf, size_t count)
{
unsigned long msecs;
int err;
err = strict_strtoul(buf, 10, &msecs);
if (err || msecs > UINT_MAX)
return -EINVAL;
khugepaged_scan_sleep_millisecs = msecs;
wake_up_interruptible(&khugepaged_wait);
return count;
}
static ssize_t alloc_sleep_millisecs_show(struct kobject *kobj,
struct kobj_attribute *attr,
char *buf)
{
return sprintf(buf, "%u\n", khugepaged_alloc_sleep_millisecs);
}
static ssize_t alloc_sleep_millisecs_store(struct kobject *kobj,
struct kobj_attribute *attr,
const char *buf, size_t count)
{
unsigned long msecs;
int err;
err = strict_strtoul(buf, 10, &msecs);
if (err || msecs > UINT_MAX)
return -EINVAL;
khugepaged_alloc_sleep_millisecs = msecs;
wake_up_interruptible(&khugepaged_wait);
return count;
}
static ssize_t pages_to_scan_show(struct kobject *kobj,
struct kobj_attribute *attr,
char *buf)
{
return sprintf(buf, "%u\n", khugepaged_pages_to_scan);
}
static ssize_t pages_to_scan_store(struct kobject *kobj,
struct kobj_attribute *attr,
const char *buf, size_t count)
{
int err;
unsigned long pages;
err = strict_strtoul(buf, 10, &pages);
if (err || !pages || pages > UINT_MAX)
return -EINVAL;
khugepaged_pages_to_scan = pages;
return count;
}
static ssize_t pages_collapsed_show(struct kobject *kobj,
struct kobj_attribute *attr,
char *buf)
{
return sprintf(buf, "%u\n", khugepaged_pages_collapsed);
}
static ssize_t full_scans_show(struct kobject *kobj,
struct kobj_attribute *attr,
char *buf)
{
return sprintf(buf, "%u\n", khugepaged_full_scans);
}
static ssize_t khugepaged_defrag_show(struct kobject *kobj,
struct kobj_attribute *attr, char *buf)
{
return single_flag_show(kobj, attr, buf,
TRANSPARENT_HUGEPAGE_DEFRAG_KHUGEPAGED_FLAG);
}
static ssize_t khugepaged_defrag_store(struct kobject *kobj,
struct kobj_attribute *attr,
const char *buf, size_t count)
{
return single_flag_store(kobj, attr, buf, count,
TRANSPARENT_HUGEPAGE_DEFRAG_KHUGEPAGED_FLAG);
}
static ssize_t khugepaged_max_ptes_none_show(struct kobject *kobj,
struct kobj_attribute *attr,
char *buf)
{
return sprintf(buf, "%u\n", khugepaged_max_ptes_none);
}
static ssize_t khugepaged_max_ptes_none_store(struct kobject *kobj,
struct kobj_attribute *attr,
const char *buf, size_t count)
{
int err;
unsigned long max_ptes_none;
err = strict_strtoul(buf, 10, &max_ptes_none);
if (err || max_ptes_none > HPAGE_PMD_NR-1)
return -EINVAL;
khugepaged_max_ptes_none = max_ptes_none;
return count;
}
static int __init hugepage_init(void)
{
int err;
#ifdef CONFIG_SYSFS
static struct kobject *hugepage_kobj;
#endif
err = -EINVAL;
if (!has_transparent_hugepage()) {
transparent_hugepage_flags = 0;
goto out;
}
#ifdef CONFIG_SYSFS
err = -ENOMEM;
hugepage_kobj = kobject_create_and_add("transparent_hugepage", mm_kobj);
if (unlikely(!hugepage_kobj)) {
printk(KERN_ERR "hugepage: failed kobject create\n");
goto out;
}
err = sysfs_create_group(hugepage_kobj, &hugepage_attr_group);
if (err) {
printk(KERN_ERR "hugepage: failed register hugeage group\n");
goto out;
}
err = sysfs_create_group(hugepage_kobj, &khugepaged_attr_group);
if (err) {
printk(KERN_ERR "hugepage: failed register hugeage group\n");
goto out;
}
#endif
err = khugepaged_slab_init();
if (err)
goto out;
err = mm_slots_hash_init();
if (err) {
khugepaged_slab_free();
goto out;
}
if (totalram_pages < (512 << (20 - PAGE_SHIFT)))
transparent_hugepage_flags = 0;
start_khugepaged();
set_recommended_min_free_kbytes();
out:
return err;
}
static int __init setup_transparent_hugepage(char *str)
{
int ret = 0;
if (!str)
goto out;
if (!strcmp(str, "always")) {
set_bit(TRANSPARENT_HUGEPAGE_FLAG,
&transparent_hugepage_flags);
clear_bit(TRANSPARENT_HUGEPAGE_REQ_MADV_FLAG,
&transparent_hugepage_flags);
ret = 1;
} else if (!strcmp(str, "madvise")) {
clear_bit(TRANSPARENT_HUGEPAGE_FLAG,
&transparent_hugepage_flags);
set_bit(TRANSPARENT_HUGEPAGE_REQ_MADV_FLAG,
&transparent_hugepage_flags);
ret = 1;
} else if (!strcmp(str, "never")) {
clear_bit(TRANSPARENT_HUGEPAGE_FLAG,
&transparent_hugepage_flags);
clear_bit(TRANSPARENT_HUGEPAGE_REQ_MADV_FLAG,
&transparent_hugepage_flags);
ret = 1;
}
out:
if (!ret)
printk(KERN_WARNING
"transparent_hugepage= cannot parse, ignored\n");
return ret;
}
static void prepare_pmd_huge_pte(pgtable_t pgtable,
struct mm_struct *mm)
{
assert_spin_locked(&mm->page_table_lock);
if (!mm->pmd_huge_pte)
INIT_LIST_HEAD(&pgtable->lru);
else
list_add(&pgtable->lru, &mm->pmd_huge_pte->lru);
mm->pmd_huge_pte = pgtable;
}
static inline pmd_t maybe_pmd_mkwrite(pmd_t pmd, struct vm_area_struct *vma)
{
if (likely(vma->vm_flags & VM_WRITE))
pmd = pmd_mkwrite(pmd);
return pmd;
}
static int __do_huge_pmd_anonymous_page(struct mm_struct *mm,
struct vm_area_struct *vma,
unsigned long haddr, pmd_t *pmd,
struct page *page)
{
int ret = 0;
pgtable_t pgtable;
VM_BUG_ON(!PageCompound(page));
pgtable = pte_alloc_one(mm, haddr);
if (unlikely(!pgtable)) {
mem_cgroup_uncharge_page(page);
put_page(page);
return VM_FAULT_OOM;
}
clear_huge_page(page, haddr, HPAGE_PMD_NR);
__SetPageUptodate(page);
spin_lock(&mm->page_table_lock);
if (unlikely(!pmd_none(*pmd))) {
spin_unlock(&mm->page_table_lock);
mem_cgroup_uncharge_page(page);
put_page(page);
pte_free(mm, pgtable);
} else {
pmd_t entry;
entry = mk_pmd(page, vma->vm_page_prot);
entry = maybe_pmd_mkwrite(pmd_mkdirty(entry), vma);
entry = pmd_mkhuge(entry);
page_add_new_anon_rmap(page, vma, haddr);
set_pmd_at(mm, haddr, pmd, entry);
prepare_pmd_huge_pte(pgtable, mm);
add_mm_counter(mm, MM_ANONPAGES, HPAGE_PMD_NR);
spin_unlock(&mm->page_table_lock);
}
return ret;
}
static inline gfp_t alloc_hugepage_gfpmask(int defrag, gfp_t extra_gfp)
{
return (GFP_TRANSHUGE & ~(defrag ? 0 : __GFP_WAIT)) | extra_gfp;
}
static inline struct page *alloc_hugepage_vma(int defrag,
struct vm_area_struct *vma,
unsigned long haddr, int nd,
gfp_t extra_gfp)
{
return alloc_pages_vma(alloc_hugepage_gfpmask(defrag, extra_gfp),
HPAGE_PMD_ORDER, vma, haddr, nd);
}
static inline struct page *alloc_hugepage(int defrag)
{
return alloc_pages(alloc_hugepage_gfpmask(defrag, 0),
HPAGE_PMD_ORDER);
}
int do_huge_pmd_anonymous_page(struct mm_struct *mm, struct vm_area_struct *vma,
unsigned long address, pmd_t *pmd,
unsigned int flags)
{
struct page *page;
unsigned long haddr = address & HPAGE_PMD_MASK;
pte_t *pte;
if (haddr >= vma->vm_start && haddr + HPAGE_PMD_SIZE <= vma->vm_end) {
if (unlikely(anon_vma_prepare(vma)))
return VM_FAULT_OOM;
if (unlikely(khugepaged_enter(vma)))
return VM_FAULT_OOM;
page = alloc_hugepage_vma(transparent_hugepage_defrag(vma),
vma, haddr, numa_node_id(), 0);
if (unlikely(!page)) {
count_vm_event(THP_FAULT_FALLBACK);
goto out;
}
count_vm_event(THP_FAULT_ALLOC);
if (unlikely(mem_cgroup_newpage_charge(page, mm, GFP_KERNEL))) {
put_page(page);
goto out;
}
return __do_huge_pmd_anonymous_page(mm, vma, haddr, pmd, page);
}
out:
if (unlikely(__pte_alloc(mm, vma, pmd, address)))
return VM_FAULT_OOM;
if (unlikely(pmd_trans_huge(*pmd)))
return 0;
pte = pte_offset_map(pmd, address);
return handle_pte_fault(mm, vma, address, pte, pmd, flags);
}
int copy_huge_pmd(struct mm_struct *dst_mm, struct mm_struct *src_mm,
pmd_t *dst_pmd, pmd_t *src_pmd, unsigned long addr,
struct vm_area_struct *vma)
{
struct page *src_page;
pmd_t pmd;
pgtable_t pgtable;
int ret;
ret = -ENOMEM;
pgtable = pte_alloc_one(dst_mm, addr);
if (unlikely(!pgtable))
goto out;
spin_lock(&dst_mm->page_table_lock);
spin_lock_nested(&src_mm->page_table_lock, SINGLE_DEPTH_NESTING);
ret = -EAGAIN;
pmd = *src_pmd;
if (unlikely(!pmd_trans_huge(pmd))) {
pte_free(dst_mm, pgtable);
goto out_unlock;
}
if (unlikely(pmd_trans_splitting(pmd))) {
spin_unlock(&src_mm->page_table_lock);
spin_unlock(&dst_mm->page_table_lock);
pte_free(dst_mm, pgtable);
wait_split_huge_page(vma->anon_vma, src_pmd);
goto out;
}
src_page = pmd_page(pmd);
VM_BUG_ON(!PageHead(src_page));
get_page(src_page);
page_dup_rmap(src_page);
add_mm_counter(dst_mm, MM_ANONPAGES, HPAGE_PMD_NR);
pmdp_set_wrprotect(src_mm, addr, src_pmd);
pmd = pmd_mkold(pmd_wrprotect(pmd));
set_pmd_at(dst_mm, addr, dst_pmd, pmd);
prepare_pmd_huge_pte(pgtable, dst_mm);
ret = 0;
out_unlock:
spin_unlock(&src_mm->page_table_lock);
spin_unlock(&dst_mm->page_table_lock);
out:
return ret;
}
pgtable_t get_pmd_huge_pte(struct mm_struct *mm)
{
pgtable_t pgtable;
assert_spin_locked(&mm->page_table_lock);
pgtable = mm->pmd_huge_pte;
if (list_empty(&pgtable->lru))
mm->pmd_huge_pte = NULL;
else {
mm->pmd_huge_pte = list_entry(pgtable->lru.next,
struct page, lru);
list_del(&pgtable->lru);
}
return pgtable;
}
static int do_huge_pmd_wp_page_fallback(struct mm_struct *mm,
struct vm_area_struct *vma,
unsigned long address,
pmd_t *pmd, pmd_t orig_pmd,
struct page *page,
unsigned long haddr)
{
pgtable_t pgtable;
pmd_t _pmd;
int ret = 0, i;
struct page **pages;
pages = kmalloc(sizeof(struct page *) * HPAGE_PMD_NR,
GFP_KERNEL);
if (unlikely(!pages)) {
ret |= VM_FAULT_OOM;
goto out;
}
for (i = 0; i < HPAGE_PMD_NR; i++) {
pages[i] = alloc_page_vma_node(GFP_HIGHUSER_MOVABLE |
__GFP_OTHER_NODE,
vma, address, page_to_nid(page));
if (unlikely(!pages[i] ||
mem_cgroup_newpage_charge(pages[i], mm,
GFP_KERNEL))) {
if (pages[i])
put_page(pages[i]);
mem_cgroup_uncharge_start();
while (--i >= 0) {
mem_cgroup_uncharge_page(pages[i]);
put_page(pages[i]);
}
mem_cgroup_uncharge_end();
kfree(pages);
ret |= VM_FAULT_OOM;
goto out;
}
}
for (i = 0; i < HPAGE_PMD_NR; i++) {
copy_user_highpage(pages[i], page + i,
haddr + PAGE_SHIFT*i, vma);
__SetPageUptodate(pages[i]);
cond_resched();
}
spin_lock(&mm->page_table_lock);
if (unlikely(!pmd_same(*pmd, orig_pmd)))
goto out_free_pages;
VM_BUG_ON(!PageHead(page));
pmdp_clear_flush_notify(vma, haddr, pmd);
pgtable = get_pmd_huge_pte(mm);
pmd_populate(mm, &_pmd, pgtable);
for (i = 0; i < HPAGE_PMD_NR; i++, haddr += PAGE_SIZE) {
pte_t *pte, entry;
entry = mk_pte(pages[i], vma->vm_page_prot);
entry = maybe_mkwrite(pte_mkdirty(entry), vma);
page_add_new_anon_rmap(pages[i], vma, haddr);
pte = pte_offset_map(&_pmd, haddr);
VM_BUG_ON(!pte_none(*pte));
set_pte_at(mm, haddr, pte, entry);
pte_unmap(pte);
}
kfree(pages);
mm->nr_ptes++;
smp_wmb();
pmd_populate(mm, pmd, pgtable);
page_remove_rmap(page);
spin_unlock(&mm->page_table_lock);
ret |= VM_FAULT_WRITE;
put_page(page);
out:
return ret;
out_free_pages:
spin_unlock(&mm->page_table_lock);
mem_cgroup_uncharge_start();
for (i = 0; i < HPAGE_PMD_NR; i++) {
mem_cgroup_uncharge_page(pages[i]);
put_page(pages[i]);
}
mem_cgroup_uncharge_end();
kfree(pages);
goto out;
}
int do_huge_pmd_wp_page(struct mm_struct *mm, struct vm_area_struct *vma,
unsigned long address, pmd_t *pmd, pmd_t orig_pmd)
{
int ret = 0;
struct page *page, *new_page;
unsigned long haddr;
VM_BUG_ON(!vma->anon_vma);
spin_lock(&mm->page_table_lock);
if (unlikely(!pmd_same(*pmd, orig_pmd)))
goto out_unlock;
page = pmd_page(orig_pmd);
VM_BUG_ON(!PageCompound(page) || !PageHead(page));
haddr = address & HPAGE_PMD_MASK;
if (page_mapcount(page) == 1) {
pmd_t entry;
entry = pmd_mkyoung(orig_pmd);
entry = maybe_pmd_mkwrite(pmd_mkdirty(entry), vma);
if (pmdp_set_access_flags(vma, haddr, pmd, entry, 1))
update_mmu_cache(vma, address, entry);
ret |= VM_FAULT_WRITE;
goto out_unlock;
}
get_page(page);
spin_unlock(&mm->page_table_lock);
if (transparent_hugepage_enabled(vma) &&
!transparent_hugepage_debug_cow())
new_page = alloc_hugepage_vma(transparent_hugepage_defrag(vma),
vma, haddr, numa_node_id(), 0);
else
new_page = NULL;
if (unlikely(!new_page)) {
count_vm_event(THP_FAULT_FALLBACK);
ret = do_huge_pmd_wp_page_fallback(mm, vma, address,
pmd, orig_pmd, page, haddr);
put_page(page);
goto out;
}
count_vm_event(THP_FAULT_ALLOC);
if (unlikely(mem_cgroup_newpage_charge(new_page, mm, GFP_KERNEL))) {
put_page(new_page);
put_page(page);
ret |= VM_FAULT_OOM;
goto out;
}
copy_user_huge_page(new_page, page, haddr, vma, HPAGE_PMD_NR);
__SetPageUptodate(new_page);
spin_lock(&mm->page_table_lock);
put_page(page);
if (unlikely(!pmd_same(*pmd, orig_pmd))) {
mem_cgroup_uncharge_page(new_page);
put_page(new_page);
} else {
pmd_t entry;
VM_BUG_ON(!PageHead(page));
entry = mk_pmd(new_page, vma->vm_page_prot);
entry = maybe_pmd_mkwrite(pmd_mkdirty(entry), vma);
entry = pmd_mkhuge(entry);
pmdp_clear_flush_notify(vma, haddr, pmd);
page_add_new_anon_rmap(new_page, vma, haddr);
set_pmd_at(mm, haddr, pmd, entry);
update_mmu_cache(vma, address, entry);
page_remove_rmap(page);
put_page(page);
ret |= VM_FAULT_WRITE;
}
out_unlock:
spin_unlock(&mm->page_table_lock);
out:
return ret;
}
struct page *follow_trans_huge_pmd(struct mm_struct *mm,
unsigned long addr,
pmd_t *pmd,
unsigned int flags)
{
struct page *page = NULL;
assert_spin_locked(&mm->page_table_lock);
if (flags & FOLL_WRITE && !pmd_write(*pmd))
goto out;
page = pmd_page(*pmd);
VM_BUG_ON(!PageHead(page));
if (flags & FOLL_TOUCH) {
pmd_t _pmd;
_pmd = pmd_mkyoung(pmd_mkdirty(*pmd));
set_pmd_at(mm, addr & HPAGE_PMD_MASK, pmd, _pmd);
}
page += (addr & ~HPAGE_PMD_MASK) >> PAGE_SHIFT;
VM_BUG_ON(!PageCompound(page));
if (flags & FOLL_GET)
get_page(page);
out:
return page;
}
int zap_huge_pmd(struct mmu_gather *tlb, struct vm_area_struct *vma,
pmd_t *pmd)
{
int ret = 0;
spin_lock(&tlb->mm->page_table_lock);
if (likely(pmd_trans_huge(*pmd))) {
if (unlikely(pmd_trans_splitting(*pmd))) {
spin_unlock(&tlb->mm->page_table_lock);
wait_split_huge_page(vma->anon_vma,
pmd);
} else {
struct page *page;
pgtable_t pgtable;
pgtable = get_pmd_huge_pte(tlb->mm);
page = pmd_page(*pmd);
pmd_clear(pmd);
page_remove_rmap(page);
VM_BUG_ON(page_mapcount(page) < 0);
add_mm_counter(tlb->mm, MM_ANONPAGES, -HPAGE_PMD_NR);
VM_BUG_ON(!PageHead(page));
spin_unlock(&tlb->mm->page_table_lock);
tlb_remove_page(tlb, page);
pte_free(tlb->mm, pgtable);
ret = 1;
}
} else
spin_unlock(&tlb->mm->page_table_lock);
return ret;
}
int mincore_huge_pmd(struct vm_area_struct *vma, pmd_t *pmd,
unsigned long addr, unsigned long end,
unsigned char *vec)
{
int ret = 0;
spin_lock(&vma->vm_mm->page_table_lock);
if (likely(pmd_trans_huge(*pmd))) {
ret = !pmd_trans_splitting(*pmd);
spin_unlock(&vma->vm_mm->page_table_lock);
if (unlikely(!ret))
wait_split_huge_page(vma->anon_vma, pmd);
else {
memset(vec, 1, (end - addr) >> PAGE_SHIFT);
}
} else
spin_unlock(&vma->vm_mm->page_table_lock);
return ret;
}
int change_huge_pmd(struct vm_area_struct *vma, pmd_t *pmd,
unsigned long addr, pgprot_t newprot)
{
struct mm_struct *mm = vma->vm_mm;
int ret = 0;
spin_lock(&mm->page_table_lock);
if (likely(pmd_trans_huge(*pmd))) {
if (unlikely(pmd_trans_splitting(*pmd))) {
spin_unlock(&mm->page_table_lock);
wait_split_huge_page(vma->anon_vma, pmd);
} else {
pmd_t entry;
entry = pmdp_get_and_clear(mm, addr, pmd);
entry = pmd_modify(entry, newprot);
set_pmd_at(mm, addr, pmd, entry);
spin_unlock(&vma->vm_mm->page_table_lock);
flush_tlb_range(vma, addr, addr + HPAGE_PMD_SIZE);
ret = 1;
}
} else
spin_unlock(&vma->vm_mm->page_table_lock);
return ret;
}
pmd_t *page_check_address_pmd(struct page *page,
struct mm_struct *mm,
unsigned long address,
enum page_check_address_pmd_flag flag)
{
pgd_t *pgd;
pud_t *pud;
pmd_t *pmd, *ret = NULL;
if (address & ~HPAGE_PMD_MASK)
goto out;
pgd = pgd_offset(mm, address);
if (!pgd_present(*pgd))
goto out;
pud = pud_offset(pgd, address);
if (!pud_present(*pud))
goto out;
pmd = pmd_offset(pud, address);
if (pmd_none(*pmd))
goto out;
if (pmd_page(*pmd) != page)
goto out;
if (flag == PAGE_CHECK_ADDRESS_PMD_NOTSPLITTING_FLAG &&
pmd_trans_splitting(*pmd))
goto out;
if (pmd_trans_huge(*pmd)) {
VM_BUG_ON(flag == PAGE_CHECK_ADDRESS_PMD_SPLITTING_FLAG &&
!pmd_trans_splitting(*pmd));
ret = pmd;
}
out:
return ret;
}
static int __split_huge_page_splitting(struct page *page,
struct vm_area_struct *vma,
unsigned long address)
{
struct mm_struct *mm = vma->vm_mm;
pmd_t *pmd;
int ret = 0;
spin_lock(&mm->page_table_lock);
pmd = page_check_address_pmd(page, mm, address,
PAGE_CHECK_ADDRESS_PMD_NOTSPLITTING_FLAG);
if (pmd) {
pmdp_splitting_flush_notify(vma, address, pmd);
ret = 1;
}
spin_unlock(&mm->page_table_lock);
return ret;
}
static void __split_huge_page_refcount(struct page *page)
{
int i;
unsigned long head_index = page->index;
struct zone *zone = page_zone(page);
int zonestat;
spin_lock_irq(&zone->lru_lock);
compound_lock(page);
for (i = 1; i < HPAGE_PMD_NR; i++) {
struct page *page_tail = page + i;
atomic_sub(atomic_read(&page_tail->_count), &page->_count);
BUG_ON(page_count(page) <= 0);
atomic_add(page_mapcount(page) + 1, &page_tail->_count);
BUG_ON(atomic_read(&page_tail->_count) <= 0);
smp_mb();
page_tail->flags &= ~PAGE_FLAGS_CHECK_AT_PREP | __PG_HWPOISON;
page_tail->flags |= (page->flags &
((1L << PG_referenced) |
(1L << PG_swapbacked) |
(1L << PG_mlocked) |
(1L << PG_uptodate)));
page_tail->flags |= (1L << PG_dirty);
smp_wmb();
BUG_ON(page_mapcount(page_tail));
page_tail->_mapcount = page->_mapcount;
BUG_ON(page_tail->mapping);
page_tail->mapping = page->mapping;
page_tail->index = ++head_index;
BUG_ON(!PageAnon(page_tail));
BUG_ON(!PageUptodate(page_tail));
BUG_ON(!PageDirty(page_tail));
BUG_ON(!PageSwapBacked(page_tail));
mem_cgroup_split_huge_fixup(page, page_tail);
lru_add_page_tail(zone, page, page_tail);
}
__dec_zone_page_state(page, NR_ANON_TRANSPARENT_HUGEPAGES);
__mod_zone_page_state(zone, NR_ANON_PAGES, HPAGE_PMD_NR);
if (PageLRU(page)) {
zonestat = NR_LRU_BASE + page_lru(page);
__mod_zone_page_state(zone, zonestat, -(HPAGE_PMD_NR-1));
}
ClearPageCompound(page);
compound_unlock(page);
spin_unlock_irq(&zone->lru_lock);
for (i = 1; i < HPAGE_PMD_NR; i++) {
struct page *page_tail = page + i;
BUG_ON(page_count(page_tail) <= 0);
put_page(page_tail);
}
BUG_ON(page_count(page) <= 0);
}
static int __split_huge_page_map(struct page *page,
struct vm_area_struct *vma,
unsigned long address)
{
struct mm_struct *mm = vma->vm_mm;
pmd_t *pmd, _pmd;
int ret = 0, i;
pgtable_t pgtable;
unsigned long haddr;
spin_lock(&mm->page_table_lock);
pmd = page_check_address_pmd(page, mm, address,
PAGE_CHECK_ADDRESS_PMD_SPLITTING_FLAG);
if (pmd) {
pgtable = get_pmd_huge_pte(mm);
pmd_populate(mm, &_pmd, pgtable);
for (i = 0, haddr = address; i < HPAGE_PMD_NR;
i++, haddr += PAGE_SIZE) {
pte_t *pte, entry;
BUG_ON(PageCompound(page+i));
entry = mk_pte(page + i, vma->vm_page_prot);
entry = maybe_mkwrite(pte_mkdirty(entry), vma);
if (!pmd_write(*pmd))
entry = pte_wrprotect(entry);
else
BUG_ON(page_mapcount(page) != 1);
if (!pmd_young(*pmd))
entry = pte_mkold(entry);
pte = pte_offset_map(&_pmd, haddr);
BUG_ON(!pte_none(*pte));
set_pte_at(mm, haddr, pte, entry);
pte_unmap(pte);
}
mm->nr_ptes++;
smp_wmb();
set_pmd_at(mm, address, pmd, pmd_mknotpresent(*pmd));
flush_tlb_range(vma, address, address + HPAGE_PMD_SIZE);
pmd_populate(mm, pmd, pgtable);
ret = 1;
}
spin_unlock(&mm->page_table_lock);
return ret;
}
static void __split_huge_page(struct page *page,
struct anon_vma *anon_vma)
{
int mapcount, mapcount2;
struct anon_vma_chain *avc;
BUG_ON(!PageHead(page));
BUG_ON(PageTail(page));
mapcount = 0;
list_for_each_entry(avc, &anon_vma->head, same_anon_vma) {
struct vm_area_struct *vma = avc->vma;
unsigned long addr = vma_address(page, vma);
BUG_ON(is_vma_temporary_stack(vma));
if (addr == -EFAULT)
continue;
mapcount += __split_huge_page_splitting(page, vma, addr);
}
if (mapcount != page_mapcount(page))
printk(KERN_ERR "mapcount %d page_mapcount %d\n",
mapcount, page_mapcount(page));
BUG_ON(mapcount != page_mapcount(page));
__split_huge_page_refcount(page);
mapcount2 = 0;
list_for_each_entry(avc, &anon_vma->head, same_anon_vma) {
struct vm_area_struct *vma = avc->vma;
unsigned long addr = vma_address(page, vma);
BUG_ON(is_vma_temporary_stack(vma));
if (addr == -EFAULT)
continue;
mapcount2 += __split_huge_page_map(page, vma, addr);
}
if (mapcount != mapcount2)
printk(KERN_ERR "mapcount %d mapcount2 %d page_mapcount %d\n",
mapcount, mapcount2, page_mapcount(page));
BUG_ON(mapcount != mapcount2);
}
int split_huge_page(struct page *page)
{
struct anon_vma *anon_vma;
int ret = 1;
BUG_ON(!PageAnon(page));
anon_vma = page_lock_anon_vma(page);
if (!anon_vma)
goto out;
ret = 0;
if (!PageCompound(page))
goto out_unlock;
BUG_ON(!PageSwapBacked(page));
__split_huge_page(page, anon_vma);
count_vm_event(THP_SPLIT);
BUG_ON(PageCompound(page));
out_unlock:
page_unlock_anon_vma(anon_vma);
out:
return ret;
}
int hugepage_madvise(struct vm_area_struct *vma,
unsigned long *vm_flags, int advice)
{
switch (advice) {
case MADV_HUGEPAGE:
if (*vm_flags & (VM_HUGEPAGE | VM_NO_THP))
return -EINVAL;
*vm_flags &= ~VM_NOHUGEPAGE;
*vm_flags |= VM_HUGEPAGE;
if (unlikely(khugepaged_enter_vma_merge(vma)))
return -ENOMEM;
break;
case MADV_NOHUGEPAGE:
if (*vm_flags & (VM_NOHUGEPAGE | VM_NO_THP))
return -EINVAL;
*vm_flags &= ~VM_HUGEPAGE;
*vm_flags |= VM_NOHUGEPAGE;
break;
}
return 0;
}
static int __init khugepaged_slab_init(void)
{
mm_slot_cache = kmem_cache_create("khugepaged_mm_slot",
sizeof(struct mm_slot),
__alignof__(struct mm_slot), 0, NULL);
if (!mm_slot_cache)
return -ENOMEM;
return 0;
}
static void __init khugepaged_slab_free(void)
{
kmem_cache_destroy(mm_slot_cache);
mm_slot_cache = NULL;
}
static inline struct mm_slot *alloc_mm_slot(void)
{
if (!mm_slot_cache)
return NULL;
return kmem_cache_zalloc(mm_slot_cache, GFP_KERNEL);
}
static inline void free_mm_slot(struct mm_slot *mm_slot)
{
kmem_cache_free(mm_slot_cache, mm_slot);
}
static int __init mm_slots_hash_init(void)
{
mm_slots_hash = kzalloc(MM_SLOTS_HASH_HEADS * sizeof(struct hlist_head),
GFP_KERNEL);
if (!mm_slots_hash)
return -ENOMEM;
return 0;
}
static struct mm_slot *get_mm_slot(struct mm_struct *mm)
{
struct mm_slot *mm_slot;
struct hlist_head *bucket;
struct hlist_node *node;
bucket = &mm_slots_hash[((unsigned long)mm / sizeof(struct mm_struct))
% MM_SLOTS_HASH_HEADS];
hlist_for_each_entry(mm_slot, node, bucket, hash) {
if (mm == mm_slot->mm)
return mm_slot;
}
return NULL;
}
static void insert_to_mm_slots_hash(struct mm_struct *mm,
struct mm_slot *mm_slot)
{
struct hlist_head *bucket;
bucket = &mm_slots_hash[((unsigned long)mm / sizeof(struct mm_struct))
% MM_SLOTS_HASH_HEADS];
mm_slot->mm = mm;
hlist_add_head(&mm_slot->hash, bucket);
}
static inline int khugepaged_test_exit(struct mm_struct *mm)
{
return atomic_read(&mm->mm_users) == 0;
}
int __khugepaged_enter(struct mm_struct *mm)
{
struct mm_slot *mm_slot;
int wakeup;
mm_slot = alloc_mm_slot();
if (!mm_slot)
return -ENOMEM;
VM_BUG_ON(khugepaged_test_exit(mm));
if (unlikely(test_and_set_bit(MMF_VM_HUGEPAGE, &mm->flags))) {
free_mm_slot(mm_slot);
return 0;
}
spin_lock(&khugepaged_mm_lock);
insert_to_mm_slots_hash(mm, mm_slot);
wakeup = list_empty(&khugepaged_scan.mm_head);
list_add_tail(&mm_slot->mm_node, &khugepaged_scan.mm_head);
spin_unlock(&khugepaged_mm_lock);
atomic_inc(&mm->mm_count);
if (wakeup)
wake_up_interruptible(&khugepaged_wait);
return 0;
}
int khugepaged_enter_vma_merge(struct vm_area_struct *vma)
{
unsigned long hstart, hend;
if (!vma->anon_vma)
return 0;
if (vma->vm_ops)
return 0;
VM_BUG_ON(is_linear_pfn_mapping(vma) || vma->vm_flags & VM_NO_THP);
hstart = (vma->vm_start + ~HPAGE_PMD_MASK) & HPAGE_PMD_MASK;
hend = vma->vm_end & HPAGE_PMD_MASK;
if (hstart < hend)
return khugepaged_enter(vma);
return 0;
}
void __khugepaged_exit(struct mm_struct *mm)
{
struct mm_slot *mm_slot;
int free = 0;
spin_lock(&khugepaged_mm_lock);
mm_slot = get_mm_slot(mm);
if (mm_slot && khugepaged_scan.mm_slot != mm_slot) {
hlist_del(&mm_slot->hash);
list_del(&mm_slot->mm_node);
free = 1;
}
if (free) {
spin_unlock(&khugepaged_mm_lock);
clear_bit(MMF_VM_HUGEPAGE, &mm->flags);
free_mm_slot(mm_slot);
mmdrop(mm);
} else if (mm_slot) {
spin_unlock(&khugepaged_mm_lock);
down_write(&mm->mmap_sem);
up_write(&mm->mmap_sem);
} else
spin_unlock(&khugepaged_mm_lock);
}
static void release_pte_page(struct page *page)
{
dec_zone_page_state(page, NR_ISOLATED_ANON + 0);
unlock_page(page);
putback_lru_page(page);
}
static void release_pte_pages(pte_t *pte, pte_t *_pte)
{
while (--_pte >= pte) {
pte_t pteval = *_pte;
if (!pte_none(pteval))
release_pte_page(pte_page(pteval));
}
}
static void release_all_pte_pages(pte_t *pte)
{
release_pte_pages(pte, pte + HPAGE_PMD_NR);
}
static int __collapse_huge_page_isolate(struct vm_area_struct *vma,
unsigned long address,
pte_t *pte)
{
struct page *page;
pte_t *_pte;
int referenced = 0, isolated = 0, none = 0;
for (_pte = pte; _pte < pte+HPAGE_PMD_NR;
_pte++, address += PAGE_SIZE) {
pte_t pteval = *_pte;
if (pte_none(pteval)) {
if (++none <= khugepaged_max_ptes_none)
continue;
else {
release_pte_pages(pte, _pte);
goto out;
}
}
if (!pte_present(pteval) || !pte_write(pteval)) {
release_pte_pages(pte, _pte);
goto out;
}
page = vm_normal_page(vma, address, pteval);
if (unlikely(!page)) {
release_pte_pages(pte, _pte);
goto out;
}
VM_BUG_ON(PageCompound(page));
BUG_ON(!PageAnon(page));
VM_BUG_ON(!PageSwapBacked(page));
if (page_count(page) != 1) {
release_pte_pages(pte, _pte);
goto out;
}
if (!trylock_page(page)) {
release_pte_pages(pte, _pte);
goto out;
}
if (isolate_lru_page(page)) {
unlock_page(page);
release_pte_pages(pte, _pte);
goto out;
}
inc_zone_page_state(page, NR_ISOLATED_ANON + 0);
VM_BUG_ON(!PageLocked(page));
VM_BUG_ON(PageLRU(page));
if (pte_young(pteval) || PageReferenced(page) ||
mmu_notifier_test_young(vma->vm_mm, address))
referenced = 1;
}
if (unlikely(!referenced))
release_all_pte_pages(pte);
else
isolated = 1;
out:
return isolated;
}
static void __collapse_huge_page_copy(pte_t *pte, struct page *page,
struct vm_area_struct *vma,
unsigned long address,
spinlock_t *ptl)
{
pte_t *_pte;
for (_pte = pte; _pte < pte+HPAGE_PMD_NR; _pte++) {
pte_t pteval = *_pte;
struct page *src_page;
if (pte_none(pteval)) {
clear_user_highpage(page, address);
add_mm_counter(vma->vm_mm, MM_ANONPAGES, 1);
} else {
src_page = pte_page(pteval);
copy_user_highpage(page, src_page, address, vma);
VM_BUG_ON(page_mapcount(src_page) != 1);
VM_BUG_ON(page_count(src_page) != 2);
release_pte_page(src_page);
spin_lock(ptl);
pte_clear(vma->vm_mm, address, _pte);
page_remove_rmap(src_page);
spin_unlock(ptl);
free_page_and_swap_cache(src_page);
}
address += PAGE_SIZE;
page++;
}
}
static void collapse_huge_page(struct mm_struct *mm,
unsigned long address,
struct page **hpage,
struct vm_area_struct *vma,
int node)
{
pgd_t *pgd;
pud_t *pud;
pmd_t *pmd, _pmd;
pte_t *pte;
pgtable_t pgtable;
struct page *new_page;
spinlock_t *ptl;
int isolated;
unsigned long hstart, hend;
VM_BUG_ON(address & ~HPAGE_PMD_MASK);
#ifndef CONFIG_NUMA
up_read(&mm->mmap_sem);
VM_BUG_ON(!*hpage);
new_page = *hpage;
#else
VM_BUG_ON(*hpage);
new_page = alloc_hugepage_vma(khugepaged_defrag(), vma, address,
node, __GFP_OTHER_NODE);
up_read(&mm->mmap_sem);
if (unlikely(!new_page)) {
count_vm_event(THP_COLLAPSE_ALLOC_FAILED);
*hpage = ERR_PTR(-ENOMEM);
return;
}
#endif
count_vm_event(THP_COLLAPSE_ALLOC);
if (unlikely(mem_cgroup_newpage_charge(new_page, mm, GFP_KERNEL))) {
#ifdef CONFIG_NUMA
put_page(new_page);
#endif
return;
}
down_write(&mm->mmap_sem);
if (unlikely(khugepaged_test_exit(mm)))
goto out;
vma = find_vma(mm, address);
hstart = (vma->vm_start + ~HPAGE_PMD_MASK) & HPAGE_PMD_MASK;
hend = vma->vm_end & HPAGE_PMD_MASK;
if (address < hstart || address + HPAGE_PMD_SIZE > hend)
goto out;
if ((!(vma->vm_flags & VM_HUGEPAGE) && !khugepaged_always()) ||
(vma->vm_flags & VM_NOHUGEPAGE))
goto out;
if (!vma->anon_vma || vma->vm_ops)
goto out;
if (is_vma_temporary_stack(vma))
goto out;
VM_BUG_ON(is_linear_pfn_mapping(vma) || vma->vm_flags & VM_NO_THP);
pgd = pgd_offset(mm, address);
if (!pgd_present(*pgd))
goto out;
pud = pud_offset(pgd, address);
if (!pud_present(*pud))
goto out;
pmd = pmd_offset(pud, address);
if (!pmd_present(*pmd) || pmd_trans_huge(*pmd))
goto out;
anon_vma_lock(vma->anon_vma);
pte = pte_offset_map(pmd, address);
ptl = pte_lockptr(mm, pmd);
spin_lock(&mm->page_table_lock);
_pmd = pmdp_clear_flush_notify(vma, address, pmd);
spin_unlock(&mm->page_table_lock);
spin_lock(ptl);
isolated = __collapse_huge_page_isolate(vma, address, pte);
spin_unlock(ptl);
if (unlikely(!isolated)) {
pte_unmap(pte);
spin_lock(&mm->page_table_lock);
BUG_ON(!pmd_none(*pmd));
set_pmd_at(mm, address, pmd, _pmd);
spin_unlock(&mm->page_table_lock);
anon_vma_unlock(vma->anon_vma);
goto out;
}
anon_vma_unlock(vma->anon_vma);
__collapse_huge_page_copy(pte, new_page, vma, address, ptl);
pte_unmap(pte);
__SetPageUptodate(new_page);
pgtable = pmd_pgtable(_pmd);
VM_BUG_ON(page_count(pgtable) != 1);
VM_BUG_ON(page_mapcount(pgtable) != 0);
_pmd = mk_pmd(new_page, vma->vm_page_prot);
_pmd = maybe_pmd_mkwrite(pmd_mkdirty(_pmd), vma);
_pmd = pmd_mkhuge(_pmd);
smp_wmb();
spin_lock(&mm->page_table_lock);
BUG_ON(!pmd_none(*pmd));
page_add_new_anon_rmap(new_page, vma, address);
set_pmd_at(mm, address, pmd, _pmd);
update_mmu_cache(vma, address, entry);
prepare_pmd_huge_pte(pgtable, mm);
mm->nr_ptes--;
spin_unlock(&mm->page_table_lock);
#ifndef CONFIG_NUMA
*hpage = NULL;
#endif
khugepaged_pages_collapsed++;
out_up_write:
up_write(&mm->mmap_sem);
return;
out:
mem_cgroup_uncharge_page(new_page);
#ifdef CONFIG_NUMA
put_page(new_page);
#endif
goto out_up_write;
}
static int khugepaged_scan_pmd(struct mm_struct *mm,
struct vm_area_struct *vma,
unsigned long address,
struct page **hpage)
{
pgd_t *pgd;
pud_t *pud;
pmd_t *pmd;
pte_t *pte, *_pte;
int ret = 0, referenced = 0, none = 0;
struct page *page;
unsigned long _address;
spinlock_t *ptl;
int node = -1;
VM_BUG_ON(address & ~HPAGE_PMD_MASK);
pgd = pgd_offset(mm, address);
if (!pgd_present(*pgd))
goto out;
pud = pud_offset(pgd, address);
if (!pud_present(*pud))
goto out;
pmd = pmd_offset(pud, address);
if (!pmd_present(*pmd) || pmd_trans_huge(*pmd))
goto out;
pte = pte_offset_map_lock(mm, pmd, address, &ptl);
for (_address = address, _pte = pte; _pte < pte+HPAGE_PMD_NR;
_pte++, _address += PAGE_SIZE) {
pte_t pteval = *_pte;
if (pte_none(pteval)) {
if (++none <= khugepaged_max_ptes_none)
continue;
else
goto out_unmap;
}
if (!pte_present(pteval) || !pte_write(pteval))
goto out_unmap;
page = vm_normal_page(vma, _address, pteval);
if (unlikely(!page))
goto out_unmap;
if (node == -1)
node = page_to_nid(page);
VM_BUG_ON(PageCompound(page));
if (!PageLRU(page) || PageLocked(page) || !PageAnon(page))
goto out_unmap;
if (page_count(page) != 1)
goto out_unmap;
if (pte_young(pteval) || PageReferenced(page) ||
mmu_notifier_test_young(vma->vm_mm, address))
referenced = 1;
}
if (referenced)
ret = 1;
out_unmap:
pte_unmap_unlock(pte, ptl);
if (ret)
collapse_huge_page(mm, address, hpage, vma, node);
out:
return ret;
}
static void collect_mm_slot(struct mm_slot *mm_slot)
{
struct mm_struct *mm = mm_slot->mm;
VM_BUG_ON(!spin_is_locked(&khugepaged_mm_lock));
if (khugepaged_test_exit(mm)) {
hlist_del(&mm_slot->hash);
list_del(&mm_slot->mm_node);
free_mm_slot(mm_slot);
mmdrop(mm);
}
}
static unsigned int khugepaged_scan_mm_slot(unsigned int pages,
struct page **hpage)
{
struct mm_slot *mm_slot;
struct mm_struct *mm;
struct vm_area_struct *vma;
int progress = 0;
VM_BUG_ON(!pages);
VM_BUG_ON(!spin_is_locked(&khugepaged_mm_lock));
if (khugepaged_scan.mm_slot)
mm_slot = khugepaged_scan.mm_slot;
else {
mm_slot = list_entry(khugepaged_scan.mm_head.next,
struct mm_slot, mm_node);
khugepaged_scan.address = 0;
khugepaged_scan.mm_slot = mm_slot;
}
spin_unlock(&khugepaged_mm_lock);
mm = mm_slot->mm;
down_read(&mm->mmap_sem);
if (unlikely(khugepaged_test_exit(mm)))
vma = NULL;
else
vma = find_vma(mm, khugepaged_scan.address);
progress++;
for (; vma; vma = vma->vm_next) {
unsigned long hstart, hend;
cond_resched();
if (unlikely(khugepaged_test_exit(mm))) {
progress++;
break;
}
if ((!(vma->vm_flags & VM_HUGEPAGE) &&
!khugepaged_always()) ||
(vma->vm_flags & VM_NOHUGEPAGE)) {
skip:
progress++;
continue;
}
if (!vma->anon_vma || vma->vm_ops)
goto skip;
if (is_vma_temporary_stack(vma))
goto skip;
VM_BUG_ON(is_linear_pfn_mapping(vma) ||
vma->vm_flags & VM_NO_THP);
hstart = (vma->vm_start + ~HPAGE_PMD_MASK) & HPAGE_PMD_MASK;
hend = vma->vm_end & HPAGE_PMD_MASK;
if (hstart >= hend)
goto skip;
if (khugepaged_scan.address > hend)
goto skip;
if (khugepaged_scan.address < hstart)
khugepaged_scan.address = hstart;
VM_BUG_ON(khugepaged_scan.address & ~HPAGE_PMD_MASK);
while (khugepaged_scan.address < hend) {
int ret;
cond_resched();
if (unlikely(khugepaged_test_exit(mm)))
goto breakouterloop;
VM_BUG_ON(khugepaged_scan.address < hstart ||
khugepaged_scan.address + HPAGE_PMD_SIZE >
hend);
ret = khugepaged_scan_pmd(mm, vma,
khugepaged_scan.address,
hpage);
khugepaged_scan.address += HPAGE_PMD_SIZE;
progress += HPAGE_PMD_NR;
if (ret)
goto breakouterloop_mmap_sem;
if (progress >= pages)
goto breakouterloop;
}
}
breakouterloop:
up_read(&mm->mmap_sem);
breakouterloop_mmap_sem:
spin_lock(&khugepaged_mm_lock);
VM_BUG_ON(khugepaged_scan.mm_slot != mm_slot);
if (khugepaged_test_exit(mm) || !vma) {
if (mm_slot->mm_node.next != &khugepaged_scan.mm_head) {
khugepaged_scan.mm_slot = list_entry(
mm_slot->mm_node.next,
struct mm_slot, mm_node);
khugepaged_scan.address = 0;
} else {
khugepaged_scan.mm_slot = NULL;
khugepaged_full_scans++;
}
collect_mm_slot(mm_slot);
}
return progress;
}
static int khugepaged_has_work(void)
{
return !list_empty(&khugepaged_scan.mm_head) &&
khugepaged_enabled();
}
static int khugepaged_wait_event(void)
{
return !list_empty(&khugepaged_scan.mm_head) ||
!khugepaged_enabled();
}
static void khugepaged_do_scan(struct page **hpage)
{
unsigned int progress = 0, pass_through_head = 0;
unsigned int pages = khugepaged_pages_to_scan;
barrier();
while (progress < pages) {
cond_resched();
#ifndef CONFIG_NUMA
if (!*hpage) {
*hpage = alloc_hugepage(khugepaged_defrag());
if (unlikely(!*hpage)) {
count_vm_event(THP_COLLAPSE_ALLOC_FAILED);
break;
}
count_vm_event(THP_COLLAPSE_ALLOC);
}
#else
if (IS_ERR(*hpage))
break;
#endif
if (unlikely(kthread_should_stop() || freezing(current)))
break;
spin_lock(&khugepaged_mm_lock);
if (!khugepaged_scan.mm_slot)
pass_through_head++;
if (khugepaged_has_work() &&
pass_through_head < 2)
progress += khugepaged_scan_mm_slot(pages - progress,
hpage);
else
progress = pages;
spin_unlock(&khugepaged_mm_lock);
}
}
static void khugepaged_alloc_sleep(void)
{
DEFINE_WAIT(wait);
add_wait_queue(&khugepaged_wait, &wait);
schedule_timeout_interruptible(
msecs_to_jiffies(
khugepaged_alloc_sleep_millisecs));
remove_wait_queue(&khugepaged_wait, &wait);
}
static struct page *khugepaged_alloc_hugepage(void)
{
struct page *hpage;
do {
hpage = alloc_hugepage(khugepaged_defrag());
if (!hpage) {
count_vm_event(THP_COLLAPSE_ALLOC_FAILED);
khugepaged_alloc_sleep();
} else
count_vm_event(THP_COLLAPSE_ALLOC);
} while (unlikely(!hpage) &&
likely(khugepaged_enabled()));
return hpage;
}
static void khugepaged_loop(void)
{
struct page *hpage;
#ifdef CONFIG_NUMA
hpage = NULL;
#endif
while (likely(khugepaged_enabled())) {
#ifndef CONFIG_NUMA
hpage = khugepaged_alloc_hugepage();
if (unlikely(!hpage))
break;
#else
if (IS_ERR(hpage)) {
khugepaged_alloc_sleep();
hpage = NULL;
}
#endif
khugepaged_do_scan(&hpage);
#ifndef CONFIG_NUMA
if (hpage)
put_page(hpage);
#endif
try_to_freeze();
if (unlikely(kthread_should_stop()))
break;
if (khugepaged_has_work()) {
DEFINE_WAIT(wait);
if (!khugepaged_scan_sleep_millisecs)
continue;
add_wait_queue(&khugepaged_wait, &wait);
schedule_timeout_interruptible(
msecs_to_jiffies(
khugepaged_scan_sleep_millisecs));
remove_wait_queue(&khugepaged_wait, &wait);
} else if (khugepaged_enabled())
wait_event_freezable(khugepaged_wait,
khugepaged_wait_event());
}
}
static int khugepaged(void *none)
{
struct mm_slot *mm_slot;
set_freezable();
set_user_nice(current, 19);
mutex_lock(&khugepaged_mutex);
for (;;) {
mutex_unlock(&khugepaged_mutex);
VM_BUG_ON(khugepaged_thread != current);
khugepaged_loop();
VM_BUG_ON(khugepaged_thread != current);
mutex_lock(&khugepaged_mutex);
if (!khugepaged_enabled())
break;
if (unlikely(kthread_should_stop()))
break;
}
spin_lock(&khugepaged_mm_lock);
mm_slot = khugepaged_scan.mm_slot;
khugepaged_scan.mm_slot = NULL;
if (mm_slot)
collect_mm_slot(mm_slot);
spin_unlock(&khugepaged_mm_lock);
khugepaged_thread = NULL;
mutex_unlock(&khugepaged_mutex);
return 0;
}
void __split_huge_page_pmd(struct mm_struct *mm, pmd_t *pmd)
{
struct page *page;
spin_lock(&mm->page_table_lock);
if (unlikely(!pmd_trans_huge(*pmd))) {
spin_unlock(&mm->page_table_lock);
return;
}
page = pmd_page(*pmd);
VM_BUG_ON(!page_count(page));
get_page(page);
spin_unlock(&mm->page_table_lock);
split_huge_page(page);
put_page(page);
BUG_ON(pmd_trans_huge(*pmd));
}
static void split_huge_page_address(struct mm_struct *mm,
unsigned long address)
{
pgd_t *pgd;
pud_t *pud;
pmd_t *pmd;
VM_BUG_ON(!(address & ~HPAGE_PMD_MASK));
pgd = pgd_offset(mm, address);
if (!pgd_present(*pgd))
return;
pud = pud_offset(pgd, address);
if (!pud_present(*pud))
return;
pmd = pmd_offset(pud, address);
if (!pmd_present(*pmd))
return;
split_huge_page_pmd(mm, pmd);
}
void __vma_adjust_trans_huge(struct vm_area_struct *vma,
unsigned long start,
unsigned long end,
long adjust_next)
{
if (start & ~HPAGE_PMD_MASK &&
(start & HPAGE_PMD_MASK) >= vma->vm_start &&
(start & HPAGE_PMD_MASK) + HPAGE_PMD_SIZE <= vma->vm_end)
split_huge_page_address(vma->vm_mm, start);
if (end & ~HPAGE_PMD_MASK &&
(end & HPAGE_PMD_MASK) >= vma->vm_start &&
(end & HPAGE_PMD_MASK) + HPAGE_PMD_SIZE <= vma->vm_end)
split_huge_page_address(vma->vm_mm, end);
if (adjust_next > 0) {
struct vm_area_struct *next = vma->vm_next;
unsigned long nstart = next->vm_start;
nstart += adjust_next << PAGE_SHIFT;
if (nstart & ~HPAGE_PMD_MASK &&
(nstart & HPAGE_PMD_MASK) >= next->vm_start &&
(nstart & HPAGE_PMD_MASK) + HPAGE_PMD_SIZE <= next->vm_end)
split_huge_page_address(next->vm_mm, nstart);
}
}
