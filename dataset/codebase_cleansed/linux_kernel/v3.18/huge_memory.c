static int set_recommended_min_free_kbytes(void)
{
struct zone *zone;
int nr_zones = 0;
unsigned long recommended_min;
if (!khugepaged_enabled())
return 0;
for_each_populated_zone(zone)
nr_zones++;
recommended_min = pageblock_nr_pages * nr_zones * 2;
recommended_min += pageblock_nr_pages * nr_zones *
MIGRATE_PCPTYPES * MIGRATE_PCPTYPES;
recommended_min = min(recommended_min,
(unsigned long) nr_free_buffer_pages() / 20);
recommended_min <<= (PAGE_SHIFT-10);
if (recommended_min > min_free_kbytes) {
if (user_min_free_kbytes >= 0)
pr_info("raising min_free_kbytes from %d to %lu "
"to help transparent hugepage allocations\n",
min_free_kbytes, recommended_min);
min_free_kbytes = recommended_min;
}
setup_per_zone_wmarks();
return 0;
}
static int start_khugepaged(void)
{
int err = 0;
if (khugepaged_enabled()) {
if (!khugepaged_thread)
khugepaged_thread = kthread_run(khugepaged, NULL,
"khugepaged");
if (unlikely(IS_ERR(khugepaged_thread))) {
pr_err("khugepaged: kthread_run(khugepaged) failed\n");
err = PTR_ERR(khugepaged_thread);
khugepaged_thread = NULL;
}
if (!list_empty(&khugepaged_scan.mm_head))
wake_up_interruptible(&khugepaged_wait);
set_recommended_min_free_kbytes();
} else if (khugepaged_thread) {
kthread_stop(khugepaged_thread);
khugepaged_thread = NULL;
}
return err;
}
static inline bool is_huge_zero_page(struct page *page)
{
return ACCESS_ONCE(huge_zero_page) == page;
}
static inline bool is_huge_zero_pmd(pmd_t pmd)
{
return is_huge_zero_page(pmd_page(pmd));
}
static struct page *get_huge_zero_page(void)
{
struct page *zero_page;
retry:
if (likely(atomic_inc_not_zero(&huge_zero_refcount)))
return ACCESS_ONCE(huge_zero_page);
zero_page = alloc_pages((GFP_TRANSHUGE | __GFP_ZERO) & ~__GFP_MOVABLE,
HPAGE_PMD_ORDER);
if (!zero_page) {
count_vm_event(THP_ZERO_PAGE_ALLOC_FAILED);
return NULL;
}
count_vm_event(THP_ZERO_PAGE_ALLOC);
preempt_disable();
if (cmpxchg(&huge_zero_page, NULL, zero_page)) {
preempt_enable();
__free_pages(zero_page, compound_order(zero_page));
goto retry;
}
atomic_set(&huge_zero_refcount, 2);
preempt_enable();
return ACCESS_ONCE(huge_zero_page);
}
static void put_huge_zero_page(void)
{
BUG_ON(atomic_dec_and_test(&huge_zero_refcount));
}
static unsigned long shrink_huge_zero_page_count(struct shrinker *shrink,
struct shrink_control *sc)
{
return atomic_read(&huge_zero_refcount) == 1 ? HPAGE_PMD_NR : 0;
}
static unsigned long shrink_huge_zero_page_scan(struct shrinker *shrink,
struct shrink_control *sc)
{
if (atomic_cmpxchg(&huge_zero_refcount, 1, 0) == 1) {
struct page *zero_page = xchg(&huge_zero_page, NULL);
BUG_ON(zero_page == NULL);
__free_pages(zero_page, compound_order(zero_page));
return HPAGE_PMD_NR;
}
return 0;
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
int err;
mutex_lock(&khugepaged_mutex);
err = start_khugepaged();
mutex_unlock(&khugepaged_mutex);
if (err)
ret = err;
}
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
static ssize_t use_zero_page_show(struct kobject *kobj,
struct kobj_attribute *attr, char *buf)
{
return single_flag_show(kobj, attr, buf,
TRANSPARENT_HUGEPAGE_USE_ZERO_PAGE_FLAG);
}
static ssize_t use_zero_page_store(struct kobject *kobj,
struct kobj_attribute *attr, const char *buf, size_t count)
{
return single_flag_store(kobj, attr, buf, count,
TRANSPARENT_HUGEPAGE_USE_ZERO_PAGE_FLAG);
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
err = kstrtoul(buf, 10, &msecs);
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
err = kstrtoul(buf, 10, &msecs);
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
err = kstrtoul(buf, 10, &pages);
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
err = kstrtoul(buf, 10, &max_ptes_none);
if (err || max_ptes_none > HPAGE_PMD_NR-1)
return -EINVAL;
khugepaged_max_ptes_none = max_ptes_none;
return count;
}
static int __init hugepage_init_sysfs(struct kobject **hugepage_kobj)
{
int err;
*hugepage_kobj = kobject_create_and_add("transparent_hugepage", mm_kobj);
if (unlikely(!*hugepage_kobj)) {
pr_err("failed to create transparent hugepage kobject\n");
return -ENOMEM;
}
err = sysfs_create_group(*hugepage_kobj, &hugepage_attr_group);
if (err) {
pr_err("failed to register transparent hugepage group\n");
goto delete_obj;
}
err = sysfs_create_group(*hugepage_kobj, &khugepaged_attr_group);
if (err) {
pr_err("failed to register transparent hugepage group\n");
goto remove_hp_group;
}
return 0;
remove_hp_group:
sysfs_remove_group(*hugepage_kobj, &hugepage_attr_group);
delete_obj:
kobject_put(*hugepage_kobj);
return err;
}
static void __init hugepage_exit_sysfs(struct kobject *hugepage_kobj)
{
sysfs_remove_group(hugepage_kobj, &khugepaged_attr_group);
sysfs_remove_group(hugepage_kobj, &hugepage_attr_group);
kobject_put(hugepage_kobj);
}
static inline int hugepage_init_sysfs(struct kobject **hugepage_kobj)
{
return 0;
}
static inline void hugepage_exit_sysfs(struct kobject *hugepage_kobj)
{
}
static int __init hugepage_init(void)
{
int err;
struct kobject *hugepage_kobj;
if (!has_transparent_hugepage()) {
transparent_hugepage_flags = 0;
return -EINVAL;
}
err = hugepage_init_sysfs(&hugepage_kobj);
if (err)
return err;
err = khugepaged_slab_init();
if (err)
goto out;
register_shrinker(&huge_zero_page_shrinker);
if (totalram_pages < (512 << (20 - PAGE_SHIFT)))
transparent_hugepage_flags = 0;
start_khugepaged();
return 0;
out:
hugepage_exit_sysfs(hugepage_kobj);
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
pr_warn("transparent_hugepage= cannot parse, ignored\n");
return ret;
}
pmd_t maybe_pmd_mkwrite(pmd_t pmd, struct vm_area_struct *vma)
{
if (likely(vma->vm_flags & VM_WRITE))
pmd = pmd_mkwrite(pmd);
return pmd;
}
static inline pmd_t mk_huge_pmd(struct page *page, pgprot_t prot)
{
pmd_t entry;
entry = mk_pmd(page, prot);
entry = pmd_mkhuge(entry);
return entry;
}
static int __do_huge_pmd_anonymous_page(struct mm_struct *mm,
struct vm_area_struct *vma,
unsigned long haddr, pmd_t *pmd,
struct page *page)
{
struct mem_cgroup *memcg;
pgtable_t pgtable;
spinlock_t *ptl;
VM_BUG_ON_PAGE(!PageCompound(page), page);
if (mem_cgroup_try_charge(page, mm, GFP_TRANSHUGE, &memcg))
return VM_FAULT_OOM;
pgtable = pte_alloc_one(mm, haddr);
if (unlikely(!pgtable)) {
mem_cgroup_cancel_charge(page, memcg);
return VM_FAULT_OOM;
}
clear_huge_page(page, haddr, HPAGE_PMD_NR);
__SetPageUptodate(page);
ptl = pmd_lock(mm, pmd);
if (unlikely(!pmd_none(*pmd))) {
spin_unlock(ptl);
mem_cgroup_cancel_charge(page, memcg);
put_page(page);
pte_free(mm, pgtable);
} else {
pmd_t entry;
entry = mk_huge_pmd(page, vma->vm_page_prot);
entry = maybe_pmd_mkwrite(pmd_mkdirty(entry), vma);
page_add_new_anon_rmap(page, vma, haddr);
mem_cgroup_commit_charge(page, memcg, false);
lru_cache_add_active_or_unevictable(page, vma);
pgtable_trans_huge_deposit(mm, pmd, pgtable);
set_pmd_at(mm, haddr, pmd, entry);
add_mm_counter(mm, MM_ANONPAGES, HPAGE_PMD_NR);
atomic_long_inc(&mm->nr_ptes);
spin_unlock(ptl);
}
return 0;
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
static bool set_huge_zero_page(pgtable_t pgtable, struct mm_struct *mm,
struct vm_area_struct *vma, unsigned long haddr, pmd_t *pmd,
struct page *zero_page)
{
pmd_t entry;
if (!pmd_none(*pmd))
return false;
entry = mk_pmd(zero_page, vma->vm_page_prot);
entry = pmd_wrprotect(entry);
entry = pmd_mkhuge(entry);
pgtable_trans_huge_deposit(mm, pmd, pgtable);
set_pmd_at(mm, haddr, pmd, entry);
atomic_long_inc(&mm->nr_ptes);
return true;
}
int do_huge_pmd_anonymous_page(struct mm_struct *mm, struct vm_area_struct *vma,
unsigned long address, pmd_t *pmd,
unsigned int flags)
{
struct page *page;
unsigned long haddr = address & HPAGE_PMD_MASK;
if (haddr < vma->vm_start || haddr + HPAGE_PMD_SIZE > vma->vm_end)
return VM_FAULT_FALLBACK;
if (unlikely(anon_vma_prepare(vma)))
return VM_FAULT_OOM;
if (unlikely(khugepaged_enter(vma, vma->vm_flags)))
return VM_FAULT_OOM;
if (!(flags & FAULT_FLAG_WRITE) &&
transparent_hugepage_use_zero_page()) {
spinlock_t *ptl;
pgtable_t pgtable;
struct page *zero_page;
bool set;
pgtable = pte_alloc_one(mm, haddr);
if (unlikely(!pgtable))
return VM_FAULT_OOM;
zero_page = get_huge_zero_page();
if (unlikely(!zero_page)) {
pte_free(mm, pgtable);
count_vm_event(THP_FAULT_FALLBACK);
return VM_FAULT_FALLBACK;
}
ptl = pmd_lock(mm, pmd);
set = set_huge_zero_page(pgtable, mm, vma, haddr, pmd,
zero_page);
spin_unlock(ptl);
if (!set) {
pte_free(mm, pgtable);
put_huge_zero_page();
}
return 0;
}
page = alloc_hugepage_vma(transparent_hugepage_defrag(vma),
vma, haddr, numa_node_id(), 0);
if (unlikely(!page)) {
count_vm_event(THP_FAULT_FALLBACK);
return VM_FAULT_FALLBACK;
}
if (unlikely(__do_huge_pmd_anonymous_page(mm, vma, haddr, pmd, page))) {
put_page(page);
count_vm_event(THP_FAULT_FALLBACK);
return VM_FAULT_FALLBACK;
}
count_vm_event(THP_FAULT_ALLOC);
return 0;
}
int copy_huge_pmd(struct mm_struct *dst_mm, struct mm_struct *src_mm,
pmd_t *dst_pmd, pmd_t *src_pmd, unsigned long addr,
struct vm_area_struct *vma)
{
spinlock_t *dst_ptl, *src_ptl;
struct page *src_page;
pmd_t pmd;
pgtable_t pgtable;
int ret;
ret = -ENOMEM;
pgtable = pte_alloc_one(dst_mm, addr);
if (unlikely(!pgtable))
goto out;
dst_ptl = pmd_lock(dst_mm, dst_pmd);
src_ptl = pmd_lockptr(src_mm, src_pmd);
spin_lock_nested(src_ptl, SINGLE_DEPTH_NESTING);
ret = -EAGAIN;
pmd = *src_pmd;
if (unlikely(!pmd_trans_huge(pmd))) {
pte_free(dst_mm, pgtable);
goto out_unlock;
}
if (is_huge_zero_pmd(pmd)) {
struct page *zero_page;
bool set;
zero_page = get_huge_zero_page();
set = set_huge_zero_page(pgtable, dst_mm, vma, addr, dst_pmd,
zero_page);
BUG_ON(!set);
ret = 0;
goto out_unlock;
}
if (unlikely(pmd_trans_splitting(pmd))) {
spin_unlock(src_ptl);
spin_unlock(dst_ptl);
pte_free(dst_mm, pgtable);
wait_split_huge_page(vma->anon_vma, src_pmd);
goto out;
}
src_page = pmd_page(pmd);
VM_BUG_ON_PAGE(!PageHead(src_page), src_page);
get_page(src_page);
page_dup_rmap(src_page);
add_mm_counter(dst_mm, MM_ANONPAGES, HPAGE_PMD_NR);
pmdp_set_wrprotect(src_mm, addr, src_pmd);
pmd = pmd_mkold(pmd_wrprotect(pmd));
pgtable_trans_huge_deposit(dst_mm, dst_pmd, pgtable);
set_pmd_at(dst_mm, addr, dst_pmd, pmd);
atomic_long_inc(&dst_mm->nr_ptes);
ret = 0;
out_unlock:
spin_unlock(src_ptl);
spin_unlock(dst_ptl);
out:
return ret;
}
void huge_pmd_set_accessed(struct mm_struct *mm,
struct vm_area_struct *vma,
unsigned long address,
pmd_t *pmd, pmd_t orig_pmd,
int dirty)
{
spinlock_t *ptl;
pmd_t entry;
unsigned long haddr;
ptl = pmd_lock(mm, pmd);
if (unlikely(!pmd_same(*pmd, orig_pmd)))
goto unlock;
entry = pmd_mkyoung(orig_pmd);
haddr = address & HPAGE_PMD_MASK;
if (pmdp_set_access_flags(vma, haddr, pmd, entry, dirty))
update_mmu_cache_pmd(vma, address, pmd);
unlock:
spin_unlock(ptl);
}
static void get_user_huge_page(struct page *page)
{
if (IS_ENABLED(CONFIG_DEBUG_PAGEALLOC)) {
struct page *endpage = page + HPAGE_PMD_NR;
atomic_add(HPAGE_PMD_NR, &page->_count);
while (++page < endpage)
get_huge_page_tail(page);
} else {
get_page(page);
}
}
static void put_user_huge_page(struct page *page)
{
if (IS_ENABLED(CONFIG_DEBUG_PAGEALLOC)) {
struct page *endpage = page + HPAGE_PMD_NR;
while (page < endpage)
put_page(page++);
} else {
put_page(page);
}
}
static int do_huge_pmd_wp_page_fallback(struct mm_struct *mm,
struct vm_area_struct *vma,
unsigned long address,
pmd_t *pmd, pmd_t orig_pmd,
struct page *page,
unsigned long haddr)
{
struct mem_cgroup *memcg;
spinlock_t *ptl;
pgtable_t pgtable;
pmd_t _pmd;
int ret = 0, i;
struct page **pages;
unsigned long mmun_start;
unsigned long mmun_end;
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
mem_cgroup_try_charge(pages[i], mm, GFP_KERNEL,
&memcg))) {
if (pages[i])
put_page(pages[i]);
while (--i >= 0) {
memcg = (void *)page_private(pages[i]);
set_page_private(pages[i], 0);
mem_cgroup_cancel_charge(pages[i], memcg);
put_page(pages[i]);
}
kfree(pages);
ret |= VM_FAULT_OOM;
goto out;
}
set_page_private(pages[i], (unsigned long)memcg);
}
for (i = 0; i < HPAGE_PMD_NR; i++) {
copy_user_highpage(pages[i], page + i,
haddr + PAGE_SIZE * i, vma);
__SetPageUptodate(pages[i]);
cond_resched();
}
mmun_start = haddr;
mmun_end = haddr + HPAGE_PMD_SIZE;
mmu_notifier_invalidate_range_start(mm, mmun_start, mmun_end);
ptl = pmd_lock(mm, pmd);
if (unlikely(!pmd_same(*pmd, orig_pmd)))
goto out_free_pages;
VM_BUG_ON_PAGE(!PageHead(page), page);
pmdp_clear_flush(vma, haddr, pmd);
pgtable = pgtable_trans_huge_withdraw(mm, pmd);
pmd_populate(mm, &_pmd, pgtable);
for (i = 0; i < HPAGE_PMD_NR; i++, haddr += PAGE_SIZE) {
pte_t *pte, entry;
entry = mk_pte(pages[i], vma->vm_page_prot);
entry = maybe_mkwrite(pte_mkdirty(entry), vma);
memcg = (void *)page_private(pages[i]);
set_page_private(pages[i], 0);
page_add_new_anon_rmap(pages[i], vma, haddr);
mem_cgroup_commit_charge(pages[i], memcg, false);
lru_cache_add_active_or_unevictable(pages[i], vma);
pte = pte_offset_map(&_pmd, haddr);
VM_BUG_ON(!pte_none(*pte));
set_pte_at(mm, haddr, pte, entry);
pte_unmap(pte);
}
kfree(pages);
smp_wmb();
pmd_populate(mm, pmd, pgtable);
page_remove_rmap(page);
spin_unlock(ptl);
mmu_notifier_invalidate_range_end(mm, mmun_start, mmun_end);
ret |= VM_FAULT_WRITE;
put_page(page);
out:
return ret;
out_free_pages:
spin_unlock(ptl);
mmu_notifier_invalidate_range_end(mm, mmun_start, mmun_end);
for (i = 0; i < HPAGE_PMD_NR; i++) {
memcg = (void *)page_private(pages[i]);
set_page_private(pages[i], 0);
mem_cgroup_cancel_charge(pages[i], memcg);
put_page(pages[i]);
}
kfree(pages);
goto out;
}
int do_huge_pmd_wp_page(struct mm_struct *mm, struct vm_area_struct *vma,
unsigned long address, pmd_t *pmd, pmd_t orig_pmd)
{
spinlock_t *ptl;
int ret = 0;
struct page *page = NULL, *new_page;
struct mem_cgroup *memcg;
unsigned long haddr;
unsigned long mmun_start;
unsigned long mmun_end;
ptl = pmd_lockptr(mm, pmd);
VM_BUG_ON_VMA(!vma->anon_vma, vma);
haddr = address & HPAGE_PMD_MASK;
if (is_huge_zero_pmd(orig_pmd))
goto alloc;
spin_lock(ptl);
if (unlikely(!pmd_same(*pmd, orig_pmd)))
goto out_unlock;
page = pmd_page(orig_pmd);
VM_BUG_ON_PAGE(!PageCompound(page) || !PageHead(page), page);
if (page_mapcount(page) == 1) {
pmd_t entry;
entry = pmd_mkyoung(orig_pmd);
entry = maybe_pmd_mkwrite(pmd_mkdirty(entry), vma);
if (pmdp_set_access_flags(vma, haddr, pmd, entry, 1))
update_mmu_cache_pmd(vma, address, pmd);
ret |= VM_FAULT_WRITE;
goto out_unlock;
}
get_user_huge_page(page);
spin_unlock(ptl);
alloc:
if (transparent_hugepage_enabled(vma) &&
!transparent_hugepage_debug_cow())
new_page = alloc_hugepage_vma(transparent_hugepage_defrag(vma),
vma, haddr, numa_node_id(), 0);
else
new_page = NULL;
if (unlikely(!new_page)) {
if (!page) {
split_huge_page_pmd(vma, address, pmd);
ret |= VM_FAULT_FALLBACK;
} else {
ret = do_huge_pmd_wp_page_fallback(mm, vma, address,
pmd, orig_pmd, page, haddr);
if (ret & VM_FAULT_OOM) {
split_huge_page(page);
ret |= VM_FAULT_FALLBACK;
}
put_user_huge_page(page);
}
count_vm_event(THP_FAULT_FALLBACK);
goto out;
}
if (unlikely(mem_cgroup_try_charge(new_page, mm,
GFP_TRANSHUGE, &memcg))) {
put_page(new_page);
if (page) {
split_huge_page(page);
put_user_huge_page(page);
} else
split_huge_page_pmd(vma, address, pmd);
ret |= VM_FAULT_FALLBACK;
count_vm_event(THP_FAULT_FALLBACK);
goto out;
}
count_vm_event(THP_FAULT_ALLOC);
if (!page)
clear_huge_page(new_page, haddr, HPAGE_PMD_NR);
else
copy_user_huge_page(new_page, page, haddr, vma, HPAGE_PMD_NR);
__SetPageUptodate(new_page);
mmun_start = haddr;
mmun_end = haddr + HPAGE_PMD_SIZE;
mmu_notifier_invalidate_range_start(mm, mmun_start, mmun_end);
spin_lock(ptl);
if (page)
put_user_huge_page(page);
if (unlikely(!pmd_same(*pmd, orig_pmd))) {
spin_unlock(ptl);
mem_cgroup_cancel_charge(new_page, memcg);
put_page(new_page);
goto out_mn;
} else {
pmd_t entry;
entry = mk_huge_pmd(new_page, vma->vm_page_prot);
entry = maybe_pmd_mkwrite(pmd_mkdirty(entry), vma);
pmdp_clear_flush(vma, haddr, pmd);
page_add_new_anon_rmap(new_page, vma, haddr);
mem_cgroup_commit_charge(new_page, memcg, false);
lru_cache_add_active_or_unevictable(new_page, vma);
set_pmd_at(mm, haddr, pmd, entry);
update_mmu_cache_pmd(vma, address, pmd);
if (!page) {
add_mm_counter(mm, MM_ANONPAGES, HPAGE_PMD_NR);
put_huge_zero_page();
} else {
VM_BUG_ON_PAGE(!PageHead(page), page);
page_remove_rmap(page);
put_page(page);
}
ret |= VM_FAULT_WRITE;
}
spin_unlock(ptl);
out_mn:
mmu_notifier_invalidate_range_end(mm, mmun_start, mmun_end);
out:
return ret;
out_unlock:
spin_unlock(ptl);
return ret;
}
struct page *follow_trans_huge_pmd(struct vm_area_struct *vma,
unsigned long addr,
pmd_t *pmd,
unsigned int flags)
{
struct mm_struct *mm = vma->vm_mm;
struct page *page = NULL;
assert_spin_locked(pmd_lockptr(mm, pmd));
if (flags & FOLL_WRITE && !pmd_write(*pmd))
goto out;
if ((flags & FOLL_DUMP) && is_huge_zero_pmd(*pmd))
return ERR_PTR(-EFAULT);
if ((flags & FOLL_NUMA) && pmd_numa(*pmd))
goto out;
page = pmd_page(*pmd);
VM_BUG_ON_PAGE(!PageHead(page), page);
if (flags & FOLL_TOUCH) {
pmd_t _pmd;
_pmd = pmd_mkyoung(pmd_mkdirty(*pmd));
if (pmdp_set_access_flags(vma, addr & HPAGE_PMD_MASK,
pmd, _pmd, 1))
update_mmu_cache_pmd(vma, addr, pmd);
}
if ((flags & FOLL_MLOCK) && (vma->vm_flags & VM_LOCKED)) {
if (page->mapping && trylock_page(page)) {
lru_add_drain();
if (page->mapping)
mlock_vma_page(page);
unlock_page(page);
}
}
page += (addr & ~HPAGE_PMD_MASK) >> PAGE_SHIFT;
VM_BUG_ON_PAGE(!PageCompound(page), page);
if (flags & FOLL_GET)
get_page_foll(page);
out:
return page;
}
int do_huge_pmd_numa_page(struct mm_struct *mm, struct vm_area_struct *vma,
unsigned long addr, pmd_t pmd, pmd_t *pmdp)
{
spinlock_t *ptl;
struct anon_vma *anon_vma = NULL;
struct page *page;
unsigned long haddr = addr & HPAGE_PMD_MASK;
int page_nid = -1, this_nid = numa_node_id();
int target_nid, last_cpupid = -1;
bool page_locked;
bool migrated = false;
int flags = 0;
ptl = pmd_lock(mm, pmdp);
if (unlikely(!pmd_same(pmd, *pmdp)))
goto out_unlock;
if (unlikely(pmd_trans_migrating(*pmdp))) {
spin_unlock(ptl);
wait_migrate_huge_page(vma->anon_vma, pmdp);
goto out;
}
page = pmd_page(pmd);
BUG_ON(is_huge_zero_page(page));
page_nid = page_to_nid(page);
last_cpupid = page_cpupid_last(page);
count_vm_numa_event(NUMA_HINT_FAULTS);
if (page_nid == this_nid) {
count_vm_numa_event(NUMA_HINT_FAULTS_LOCAL);
flags |= TNF_FAULT_LOCAL;
}
if (!pmd_write(pmd))
flags |= TNF_NO_GROUP;
page_locked = trylock_page(page);
target_nid = mpol_misplaced(page, vma, haddr);
if (target_nid == -1) {
if (page_locked)
goto clear_pmdnuma;
}
if (!page_locked) {
spin_unlock(ptl);
wait_on_page_locked(page);
page_nid = -1;
goto out;
}
get_page(page);
spin_unlock(ptl);
anon_vma = page_lock_anon_vma_read(page);
spin_lock(ptl);
if (unlikely(!pmd_same(pmd, *pmdp))) {
unlock_page(page);
put_page(page);
page_nid = -1;
goto out_unlock;
}
if (unlikely(!anon_vma)) {
put_page(page);
page_nid = -1;
goto clear_pmdnuma;
}
spin_unlock(ptl);
migrated = migrate_misplaced_transhuge_page(mm, vma,
pmdp, pmd, addr, page, target_nid);
if (migrated) {
flags |= TNF_MIGRATED;
page_nid = target_nid;
}
goto out;
clear_pmdnuma:
BUG_ON(!PageLocked(page));
pmd = pmd_mknonnuma(pmd);
set_pmd_at(mm, haddr, pmdp, pmd);
VM_BUG_ON(pmd_numa(*pmdp));
update_mmu_cache_pmd(vma, addr, pmdp);
unlock_page(page);
out_unlock:
spin_unlock(ptl);
out:
if (anon_vma)
page_unlock_anon_vma_read(anon_vma);
if (page_nid != -1)
task_numa_fault(last_cpupid, page_nid, HPAGE_PMD_NR, flags);
return 0;
}
int zap_huge_pmd(struct mmu_gather *tlb, struct vm_area_struct *vma,
pmd_t *pmd, unsigned long addr)
{
spinlock_t *ptl;
int ret = 0;
if (__pmd_trans_huge_lock(pmd, vma, &ptl) == 1) {
struct page *page;
pgtable_t pgtable;
pmd_t orig_pmd;
orig_pmd = pmdp_get_and_clear(tlb->mm, addr, pmd);
tlb_remove_pmd_tlb_entry(tlb, pmd, addr);
pgtable = pgtable_trans_huge_withdraw(tlb->mm, pmd);
if (is_huge_zero_pmd(orig_pmd)) {
atomic_long_dec(&tlb->mm->nr_ptes);
spin_unlock(ptl);
put_huge_zero_page();
} else {
page = pmd_page(orig_pmd);
page_remove_rmap(page);
VM_BUG_ON_PAGE(page_mapcount(page) < 0, page);
add_mm_counter(tlb->mm, MM_ANONPAGES, -HPAGE_PMD_NR);
VM_BUG_ON_PAGE(!PageHead(page), page);
atomic_long_dec(&tlb->mm->nr_ptes);
spin_unlock(ptl);
tlb_remove_page(tlb, page);
}
pte_free(tlb->mm, pgtable);
ret = 1;
}
return ret;
}
int mincore_huge_pmd(struct vm_area_struct *vma, pmd_t *pmd,
unsigned long addr, unsigned long end,
unsigned char *vec)
{
spinlock_t *ptl;
int ret = 0;
if (__pmd_trans_huge_lock(pmd, vma, &ptl) == 1) {
spin_unlock(ptl);
memset(vec, 1, (end - addr) >> PAGE_SHIFT);
ret = 1;
}
return ret;
}
int move_huge_pmd(struct vm_area_struct *vma, struct vm_area_struct *new_vma,
unsigned long old_addr,
unsigned long new_addr, unsigned long old_end,
pmd_t *old_pmd, pmd_t *new_pmd)
{
spinlock_t *old_ptl, *new_ptl;
int ret = 0;
pmd_t pmd;
struct mm_struct *mm = vma->vm_mm;
if ((old_addr & ~HPAGE_PMD_MASK) ||
(new_addr & ~HPAGE_PMD_MASK) ||
old_end - old_addr < HPAGE_PMD_SIZE ||
(new_vma->vm_flags & VM_NOHUGEPAGE))
goto out;
if (WARN_ON(!pmd_none(*new_pmd))) {
VM_BUG_ON(pmd_trans_huge(*new_pmd));
goto out;
}
ret = __pmd_trans_huge_lock(old_pmd, vma, &old_ptl);
if (ret == 1) {
new_ptl = pmd_lockptr(mm, new_pmd);
if (new_ptl != old_ptl)
spin_lock_nested(new_ptl, SINGLE_DEPTH_NESTING);
pmd = pmdp_get_and_clear(mm, old_addr, old_pmd);
VM_BUG_ON(!pmd_none(*new_pmd));
if (pmd_move_must_withdraw(new_ptl, old_ptl)) {
pgtable_t pgtable;
pgtable = pgtable_trans_huge_withdraw(mm, old_pmd);
pgtable_trans_huge_deposit(mm, new_pmd, pgtable);
}
set_pmd_at(mm, new_addr, new_pmd, pmd_mksoft_dirty(pmd));
if (new_ptl != old_ptl)
spin_unlock(new_ptl);
spin_unlock(old_ptl);
}
out:
return ret;
}
int change_huge_pmd(struct vm_area_struct *vma, pmd_t *pmd,
unsigned long addr, pgprot_t newprot, int prot_numa)
{
struct mm_struct *mm = vma->vm_mm;
spinlock_t *ptl;
int ret = 0;
if (__pmd_trans_huge_lock(pmd, vma, &ptl) == 1) {
pmd_t entry;
ret = 1;
if (!prot_numa) {
entry = pmdp_get_and_clear(mm, addr, pmd);
if (pmd_numa(entry))
entry = pmd_mknonnuma(entry);
entry = pmd_modify(entry, newprot);
ret = HPAGE_PMD_NR;
set_pmd_at(mm, addr, pmd, entry);
BUG_ON(pmd_write(entry));
} else {
struct page *page = pmd_page(*pmd);
if (!is_huge_zero_page(page) &&
!pmd_numa(*pmd)) {
pmdp_set_numa(mm, addr, pmd);
ret = HPAGE_PMD_NR;
}
}
spin_unlock(ptl);
}
return ret;
}
int __pmd_trans_huge_lock(pmd_t *pmd, struct vm_area_struct *vma,
spinlock_t **ptl)
{
*ptl = pmd_lock(vma->vm_mm, pmd);
if (likely(pmd_trans_huge(*pmd))) {
if (unlikely(pmd_trans_splitting(*pmd))) {
spin_unlock(*ptl);
wait_split_huge_page(vma->anon_vma, pmd);
return -1;
} else {
return 1;
}
}
spin_unlock(*ptl);
return 0;
}
pmd_t *page_check_address_pmd(struct page *page,
struct mm_struct *mm,
unsigned long address,
enum page_check_address_pmd_flag flag,
spinlock_t **ptl)
{
pgd_t *pgd;
pud_t *pud;
pmd_t *pmd;
if (address & ~HPAGE_PMD_MASK)
return NULL;
pgd = pgd_offset(mm, address);
if (!pgd_present(*pgd))
return NULL;
pud = pud_offset(pgd, address);
if (!pud_present(*pud))
return NULL;
pmd = pmd_offset(pud, address);
*ptl = pmd_lock(mm, pmd);
if (!pmd_present(*pmd))
goto unlock;
if (pmd_page(*pmd) != page)
goto unlock;
if (flag == PAGE_CHECK_ADDRESS_PMD_NOTSPLITTING_FLAG &&
pmd_trans_splitting(*pmd))
goto unlock;
if (pmd_trans_huge(*pmd)) {
VM_BUG_ON(flag == PAGE_CHECK_ADDRESS_PMD_SPLITTING_FLAG &&
!pmd_trans_splitting(*pmd));
return pmd;
}
unlock:
spin_unlock(*ptl);
return NULL;
}
static int __split_huge_page_splitting(struct page *page,
struct vm_area_struct *vma,
unsigned long address)
{
struct mm_struct *mm = vma->vm_mm;
spinlock_t *ptl;
pmd_t *pmd;
int ret = 0;
const unsigned long mmun_start = address;
const unsigned long mmun_end = address + HPAGE_PMD_SIZE;
mmu_notifier_invalidate_range_start(mm, mmun_start, mmun_end);
pmd = page_check_address_pmd(page, mm, address,
PAGE_CHECK_ADDRESS_PMD_NOTSPLITTING_FLAG, &ptl);
if (pmd) {
pmdp_splitting_flush(vma, address, pmd);
ret = 1;
spin_unlock(ptl);
}
mmu_notifier_invalidate_range_end(mm, mmun_start, mmun_end);
return ret;
}
static void __split_huge_page_refcount(struct page *page,
struct list_head *list)
{
int i;
struct zone *zone = page_zone(page);
struct lruvec *lruvec;
int tail_count = 0;
spin_lock_irq(&zone->lru_lock);
lruvec = mem_cgroup_page_lruvec(page, zone);
compound_lock(page);
mem_cgroup_split_huge_fixup(page);
for (i = HPAGE_PMD_NR - 1; i >= 1; i--) {
struct page *page_tail = page + i;
BUG_ON(page_mapcount(page_tail) < 0);
tail_count += page_mapcount(page_tail);
BUG_ON(tail_count < 0);
BUG_ON(atomic_read(&page_tail->_count) != 0);
atomic_add(page_mapcount(page) + page_mapcount(page_tail) + 1,
&page_tail->_count);
smp_mb__after_atomic();
page_tail->flags &= ~PAGE_FLAGS_CHECK_AT_PREP | __PG_HWPOISON;
page_tail->flags |= (page->flags &
((1L << PG_referenced) |
(1L << PG_swapbacked) |
(1L << PG_mlocked) |
(1L << PG_uptodate) |
(1L << PG_active) |
(1L << PG_unevictable)));
page_tail->flags |= (1L << PG_dirty);
smp_wmb();
page_tail->_mapcount = page->_mapcount;
BUG_ON(page_tail->mapping);
page_tail->mapping = page->mapping;
page_tail->index = page->index + i;
page_cpupid_xchg_last(page_tail, page_cpupid_last(page));
BUG_ON(!PageAnon(page_tail));
BUG_ON(!PageUptodate(page_tail));
BUG_ON(!PageDirty(page_tail));
BUG_ON(!PageSwapBacked(page_tail));
lru_add_page_tail(page, page_tail, lruvec, list);
}
atomic_sub(tail_count, &page->_count);
BUG_ON(atomic_read(&page->_count) <= 0);
__mod_zone_page_state(zone, NR_ANON_TRANSPARENT_HUGEPAGES, -1);
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
spinlock_t *ptl;
pmd_t *pmd, _pmd;
int ret = 0, i;
pgtable_t pgtable;
unsigned long haddr;
pmd = page_check_address_pmd(page, mm, address,
PAGE_CHECK_ADDRESS_PMD_SPLITTING_FLAG, &ptl);
if (pmd) {
pgtable = pgtable_trans_huge_withdraw(mm, pmd);
pmd_populate(mm, &_pmd, pgtable);
if (pmd_write(*pmd))
BUG_ON(page_mapcount(page) != 1);
haddr = address;
for (i = 0; i < HPAGE_PMD_NR; i++, haddr += PAGE_SIZE) {
pte_t *pte, entry;
BUG_ON(PageCompound(page+i));
entry = mk_pte(page + i, vma->vm_page_prot);
entry = maybe_mkwrite(pte_mkdirty(entry), vma);
if (!pmd_write(*pmd))
entry = pte_wrprotect(entry);
if (!pmd_young(*pmd))
entry = pte_mkold(entry);
pte = pte_offset_map(&_pmd, haddr);
BUG_ON(!pte_none(*pte));
set_pte_at(mm, haddr, pte, entry);
pte_unmap(pte);
}
smp_wmb();
pmdp_invalidate(vma, address, pmd);
pmd_populate(mm, pmd, pgtable);
ret = 1;
spin_unlock(ptl);
}
return ret;
}
static void __split_huge_page(struct page *page,
struct anon_vma *anon_vma,
struct list_head *list)
{
int mapcount, mapcount2;
pgoff_t pgoff = page->index << (PAGE_CACHE_SHIFT - PAGE_SHIFT);
struct anon_vma_chain *avc;
BUG_ON(!PageHead(page));
BUG_ON(PageTail(page));
mapcount = 0;
anon_vma_interval_tree_foreach(avc, &anon_vma->rb_root, pgoff, pgoff) {
struct vm_area_struct *vma = avc->vma;
unsigned long addr = vma_address(page, vma);
BUG_ON(is_vma_temporary_stack(vma));
mapcount += __split_huge_page_splitting(page, vma, addr);
}
if (mapcount != page_mapcount(page)) {
pr_err("mapcount %d page_mapcount %d\n",
mapcount, page_mapcount(page));
BUG();
}
__split_huge_page_refcount(page, list);
mapcount2 = 0;
anon_vma_interval_tree_foreach(avc, &anon_vma->rb_root, pgoff, pgoff) {
struct vm_area_struct *vma = avc->vma;
unsigned long addr = vma_address(page, vma);
BUG_ON(is_vma_temporary_stack(vma));
mapcount2 += __split_huge_page_map(page, vma, addr);
}
if (mapcount != mapcount2) {
pr_err("mapcount %d mapcount2 %d page_mapcount %d\n",
mapcount, mapcount2, page_mapcount(page));
BUG();
}
}
int split_huge_page_to_list(struct page *page, struct list_head *list)
{
struct anon_vma *anon_vma;
int ret = 1;
BUG_ON(is_huge_zero_page(page));
BUG_ON(!PageAnon(page));
anon_vma = page_get_anon_vma(page);
if (!anon_vma)
goto out;
anon_vma_lock_write(anon_vma);
ret = 0;
if (!PageCompound(page))
goto out_unlock;
BUG_ON(!PageSwapBacked(page));
__split_huge_page(page, anon_vma, list);
count_vm_event(THP_SPLIT);
BUG_ON(PageCompound(page));
out_unlock:
anon_vma_unlock_write(anon_vma);
put_anon_vma(anon_vma);
out:
return ret;
}
int hugepage_madvise(struct vm_area_struct *vma,
unsigned long *vm_flags, int advice)
{
switch (advice) {
case MADV_HUGEPAGE:
#ifdef CONFIG_S390
if (mm_has_pgste(vma->vm_mm))
return 0;
#endif
if (*vm_flags & (VM_HUGEPAGE | VM_NO_THP))
return -EINVAL;
*vm_flags &= ~VM_NOHUGEPAGE;
*vm_flags |= VM_HUGEPAGE;
if (unlikely(khugepaged_enter_vma_merge(vma, *vm_flags)))
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
static struct mm_slot *get_mm_slot(struct mm_struct *mm)
{
struct mm_slot *mm_slot;
hash_for_each_possible(mm_slots_hash, mm_slot, hash, (unsigned long)mm)
if (mm == mm_slot->mm)
return mm_slot;
return NULL;
}
static void insert_to_mm_slots_hash(struct mm_struct *mm,
struct mm_slot *mm_slot)
{
mm_slot->mm = mm;
hash_add(mm_slots_hash, &mm_slot->hash, (long)mm);
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
VM_BUG_ON_MM(khugepaged_test_exit(mm), mm);
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
int khugepaged_enter_vma_merge(struct vm_area_struct *vma,
unsigned long vm_flags)
{
unsigned long hstart, hend;
if (!vma->anon_vma)
return 0;
if (vma->vm_ops)
return 0;
VM_BUG_ON_VMA(vm_flags & VM_NO_THP, vma);
hstart = (vma->vm_start + ~HPAGE_PMD_MASK) & HPAGE_PMD_MASK;
hend = vma->vm_end & HPAGE_PMD_MASK;
if (hstart < hend)
return khugepaged_enter(vma, vm_flags);
return 0;
}
void __khugepaged_exit(struct mm_struct *mm)
{
struct mm_slot *mm_slot;
int free = 0;
spin_lock(&khugepaged_mm_lock);
mm_slot = get_mm_slot(mm);
if (mm_slot && khugepaged_scan.mm_slot != mm_slot) {
hash_del(&mm_slot->hash);
list_del(&mm_slot->mm_node);
free = 1;
}
spin_unlock(&khugepaged_mm_lock);
if (free) {
clear_bit(MMF_VM_HUGEPAGE, &mm->flags);
free_mm_slot(mm_slot);
mmdrop(mm);
} else if (mm_slot) {
down_write(&mm->mmap_sem);
up_write(&mm->mmap_sem);
}
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
static int __collapse_huge_page_isolate(struct vm_area_struct *vma,
unsigned long address,
pte_t *pte)
{
struct page *page;
pte_t *_pte;
int referenced = 0, none = 0;
for (_pte = pte; _pte < pte+HPAGE_PMD_NR;
_pte++, address += PAGE_SIZE) {
pte_t pteval = *_pte;
if (pte_none(pteval)) {
if (++none <= khugepaged_max_ptes_none)
continue;
else
goto out;
}
if (!pte_present(pteval) || !pte_write(pteval))
goto out;
page = vm_normal_page(vma, address, pteval);
if (unlikely(!page))
goto out;
VM_BUG_ON_PAGE(PageCompound(page), page);
VM_BUG_ON_PAGE(!PageAnon(page), page);
VM_BUG_ON_PAGE(!PageSwapBacked(page), page);
if (page_count(page) != 1)
goto out;
if (!trylock_page(page))
goto out;
if (isolate_lru_page(page)) {
unlock_page(page);
goto out;
}
inc_zone_page_state(page, NR_ISOLATED_ANON + 0);
VM_BUG_ON_PAGE(!PageLocked(page), page);
VM_BUG_ON_PAGE(PageLRU(page), page);
if (pte_young(pteval) || PageReferenced(page) ||
mmu_notifier_test_young(vma->vm_mm, address))
referenced = 1;
}
if (likely(referenced))
return 1;
out:
release_pte_pages(pte, _pte);
return 0;
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
VM_BUG_ON_PAGE(page_mapcount(src_page) != 1, src_page);
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
static void khugepaged_alloc_sleep(void)
{
wait_event_freezable_timeout(khugepaged_wait, false,
msecs_to_jiffies(khugepaged_alloc_sleep_millisecs));
}
static bool khugepaged_scan_abort(int nid)
{
int i;
if (!zone_reclaim_mode)
return false;
if (khugepaged_node_load[nid])
return false;
for (i = 0; i < MAX_NUMNODES; i++) {
if (!khugepaged_node_load[i])
continue;
if (node_distance(nid, i) > RECLAIM_DISTANCE)
return true;
}
return false;
}
static int khugepaged_find_target_node(void)
{
static int last_khugepaged_target_node = NUMA_NO_NODE;
int nid, target_node = 0, max_value = 0;
for (nid = 0; nid < MAX_NUMNODES; nid++)
if (khugepaged_node_load[nid] > max_value) {
max_value = khugepaged_node_load[nid];
target_node = nid;
}
if (target_node <= last_khugepaged_target_node)
for (nid = last_khugepaged_target_node + 1; nid < MAX_NUMNODES;
nid++)
if (max_value == khugepaged_node_load[nid]) {
target_node = nid;
break;
}
last_khugepaged_target_node = target_node;
return target_node;
}
static bool khugepaged_prealloc_page(struct page **hpage, bool *wait)
{
if (IS_ERR(*hpage)) {
if (!*wait)
return false;
*wait = false;
*hpage = NULL;
khugepaged_alloc_sleep();
} else if (*hpage) {
put_page(*hpage);
*hpage = NULL;
}
return true;
}
static struct page
*khugepaged_alloc_page(struct page **hpage, struct mm_struct *mm,
struct vm_area_struct *vma, unsigned long address,
int node)
{
VM_BUG_ON_PAGE(*hpage, *hpage);
up_read(&mm->mmap_sem);
*hpage = alloc_pages_exact_node(node, alloc_hugepage_gfpmask(
khugepaged_defrag(), __GFP_OTHER_NODE), HPAGE_PMD_ORDER);
if (unlikely(!*hpage)) {
count_vm_event(THP_COLLAPSE_ALLOC_FAILED);
*hpage = ERR_PTR(-ENOMEM);
return NULL;
}
count_vm_event(THP_COLLAPSE_ALLOC);
return *hpage;
}
static int khugepaged_find_target_node(void)
{
return 0;
}
static inline struct page *alloc_hugepage(int defrag)
{
return alloc_pages(alloc_hugepage_gfpmask(defrag, 0),
HPAGE_PMD_ORDER);
}
static struct page *khugepaged_alloc_hugepage(bool *wait)
{
struct page *hpage;
do {
hpage = alloc_hugepage(khugepaged_defrag());
if (!hpage) {
count_vm_event(THP_COLLAPSE_ALLOC_FAILED);
if (!*wait)
return NULL;
*wait = false;
khugepaged_alloc_sleep();
} else
count_vm_event(THP_COLLAPSE_ALLOC);
} while (unlikely(!hpage) && likely(khugepaged_enabled()));
return hpage;
}
static bool khugepaged_prealloc_page(struct page **hpage, bool *wait)
{
if (!*hpage)
*hpage = khugepaged_alloc_hugepage(wait);
if (unlikely(!*hpage))
return false;
return true;
}
static struct page
*khugepaged_alloc_page(struct page **hpage, struct mm_struct *mm,
struct vm_area_struct *vma, unsigned long address,
int node)
{
up_read(&mm->mmap_sem);
VM_BUG_ON(!*hpage);
return *hpage;
}
static bool hugepage_vma_check(struct vm_area_struct *vma)
{
if ((!(vma->vm_flags & VM_HUGEPAGE) && !khugepaged_always()) ||
(vma->vm_flags & VM_NOHUGEPAGE))
return false;
if (!vma->anon_vma || vma->vm_ops)
return false;
if (is_vma_temporary_stack(vma))
return false;
VM_BUG_ON_VMA(vma->vm_flags & VM_NO_THP, vma);
return true;
}
static void collapse_huge_page(struct mm_struct *mm,
unsigned long address,
struct page **hpage,
struct vm_area_struct *vma,
int node)
{
pmd_t *pmd, _pmd;
pte_t *pte;
pgtable_t pgtable;
struct page *new_page;
spinlock_t *pmd_ptl, *pte_ptl;
int isolated;
unsigned long hstart, hend;
struct mem_cgroup *memcg;
unsigned long mmun_start;
unsigned long mmun_end;
VM_BUG_ON(address & ~HPAGE_PMD_MASK);
new_page = khugepaged_alloc_page(hpage, mm, vma, address, node);
if (!new_page)
return;
if (unlikely(mem_cgroup_try_charge(new_page, mm,
GFP_TRANSHUGE, &memcg)))
return;
down_write(&mm->mmap_sem);
if (unlikely(khugepaged_test_exit(mm)))
goto out;
vma = find_vma(mm, address);
if (!vma)
goto out;
hstart = (vma->vm_start + ~HPAGE_PMD_MASK) & HPAGE_PMD_MASK;
hend = vma->vm_end & HPAGE_PMD_MASK;
if (address < hstart || address + HPAGE_PMD_SIZE > hend)
goto out;
if (!hugepage_vma_check(vma))
goto out;
pmd = mm_find_pmd(mm, address);
if (!pmd)
goto out;
anon_vma_lock_write(vma->anon_vma);
pte = pte_offset_map(pmd, address);
pte_ptl = pte_lockptr(mm, pmd);
mmun_start = address;
mmun_end = address + HPAGE_PMD_SIZE;
mmu_notifier_invalidate_range_start(mm, mmun_start, mmun_end);
pmd_ptl = pmd_lock(mm, pmd);
_pmd = pmdp_clear_flush(vma, address, pmd);
spin_unlock(pmd_ptl);
mmu_notifier_invalidate_range_end(mm, mmun_start, mmun_end);
spin_lock(pte_ptl);
isolated = __collapse_huge_page_isolate(vma, address, pte);
spin_unlock(pte_ptl);
if (unlikely(!isolated)) {
pte_unmap(pte);
spin_lock(pmd_ptl);
BUG_ON(!pmd_none(*pmd));
pmd_populate(mm, pmd, pmd_pgtable(_pmd));
spin_unlock(pmd_ptl);
anon_vma_unlock_write(vma->anon_vma);
goto out;
}
anon_vma_unlock_write(vma->anon_vma);
__collapse_huge_page_copy(pte, new_page, vma, address, pte_ptl);
pte_unmap(pte);
__SetPageUptodate(new_page);
pgtable = pmd_pgtable(_pmd);
_pmd = mk_huge_pmd(new_page, vma->vm_page_prot);
_pmd = maybe_pmd_mkwrite(pmd_mkdirty(_pmd), vma);
smp_wmb();
spin_lock(pmd_ptl);
BUG_ON(!pmd_none(*pmd));
page_add_new_anon_rmap(new_page, vma, address);
mem_cgroup_commit_charge(new_page, memcg, false);
lru_cache_add_active_or_unevictable(new_page, vma);
pgtable_trans_huge_deposit(mm, pmd, pgtable);
set_pmd_at(mm, address, pmd, _pmd);
update_mmu_cache_pmd(vma, address, pmd);
spin_unlock(pmd_ptl);
*hpage = NULL;
khugepaged_pages_collapsed++;
out_up_write:
up_write(&mm->mmap_sem);
return;
out:
mem_cgroup_cancel_charge(new_page, memcg);
goto out_up_write;
}
static int khugepaged_scan_pmd(struct mm_struct *mm,
struct vm_area_struct *vma,
unsigned long address,
struct page **hpage)
{
pmd_t *pmd;
pte_t *pte, *_pte;
int ret = 0, referenced = 0, none = 0;
struct page *page;
unsigned long _address;
spinlock_t *ptl;
int node = NUMA_NO_NODE;
VM_BUG_ON(address & ~HPAGE_PMD_MASK);
pmd = mm_find_pmd(mm, address);
if (!pmd)
goto out;
memset(khugepaged_node_load, 0, sizeof(khugepaged_node_load));
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
node = page_to_nid(page);
if (khugepaged_scan_abort(node))
goto out_unmap;
khugepaged_node_load[node]++;
VM_BUG_ON_PAGE(PageCompound(page), page);
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
if (ret) {
node = khugepaged_find_target_node();
collapse_huge_page(mm, address, hpage, vma, node);
}
out:
return ret;
}
static void collect_mm_slot(struct mm_slot *mm_slot)
{
struct mm_struct *mm = mm_slot->mm;
VM_BUG_ON(NR_CPUS != 1 && !spin_is_locked(&khugepaged_mm_lock));
if (khugepaged_test_exit(mm)) {
hash_del(&mm_slot->hash);
list_del(&mm_slot->mm_node);
free_mm_slot(mm_slot);
mmdrop(mm);
}
}
static unsigned int khugepaged_scan_mm_slot(unsigned int pages,
struct page **hpage)
__releases(&khugepaged_mm_lock
static int khugepaged_has_work(void)
{
return !list_empty(&khugepaged_scan.mm_head) &&
khugepaged_enabled();
}
static int khugepaged_wait_event(void)
{
return !list_empty(&khugepaged_scan.mm_head) ||
kthread_should_stop();
}
static void khugepaged_do_scan(void)
{
struct page *hpage = NULL;
unsigned int progress = 0, pass_through_head = 0;
unsigned int pages = khugepaged_pages_to_scan;
bool wait = true;
barrier();
while (progress < pages) {
if (!khugepaged_prealloc_page(&hpage, &wait))
break;
cond_resched();
if (unlikely(kthread_should_stop() || freezing(current)))
break;
spin_lock(&khugepaged_mm_lock);
if (!khugepaged_scan.mm_slot)
pass_through_head++;
if (khugepaged_has_work() &&
pass_through_head < 2)
progress += khugepaged_scan_mm_slot(pages - progress,
&hpage);
else
progress = pages;
spin_unlock(&khugepaged_mm_lock);
}
if (!IS_ERR_OR_NULL(hpage))
put_page(hpage);
}
static void khugepaged_wait_work(void)
{
try_to_freeze();
if (khugepaged_has_work()) {
if (!khugepaged_scan_sleep_millisecs)
return;
wait_event_freezable_timeout(khugepaged_wait,
kthread_should_stop(),
msecs_to_jiffies(khugepaged_scan_sleep_millisecs));
return;
}
if (khugepaged_enabled())
wait_event_freezable(khugepaged_wait, khugepaged_wait_event());
}
static int khugepaged(void *none)
{
struct mm_slot *mm_slot;
set_freezable();
set_user_nice(current, MAX_NICE);
while (!kthread_should_stop()) {
khugepaged_do_scan();
khugepaged_wait_work();
}
spin_lock(&khugepaged_mm_lock);
mm_slot = khugepaged_scan.mm_slot;
khugepaged_scan.mm_slot = NULL;
if (mm_slot)
collect_mm_slot(mm_slot);
spin_unlock(&khugepaged_mm_lock);
return 0;
}
static void __split_huge_zero_page_pmd(struct vm_area_struct *vma,
unsigned long haddr, pmd_t *pmd)
{
struct mm_struct *mm = vma->vm_mm;
pgtable_t pgtable;
pmd_t _pmd;
int i;
pmdp_clear_flush(vma, haddr, pmd);
pgtable = pgtable_trans_huge_withdraw(mm, pmd);
pmd_populate(mm, &_pmd, pgtable);
for (i = 0; i < HPAGE_PMD_NR; i++, haddr += PAGE_SIZE) {
pte_t *pte, entry;
entry = pfn_pte(my_zero_pfn(haddr), vma->vm_page_prot);
entry = pte_mkspecial(entry);
pte = pte_offset_map(&_pmd, haddr);
VM_BUG_ON(!pte_none(*pte));
set_pte_at(mm, haddr, pte, entry);
pte_unmap(pte);
}
smp_wmb();
pmd_populate(mm, pmd, pgtable);
put_huge_zero_page();
}
void __split_huge_page_pmd(struct vm_area_struct *vma, unsigned long address,
pmd_t *pmd)
{
spinlock_t *ptl;
struct page *page;
struct mm_struct *mm = vma->vm_mm;
unsigned long haddr = address & HPAGE_PMD_MASK;
unsigned long mmun_start;
unsigned long mmun_end;
BUG_ON(vma->vm_start > haddr || vma->vm_end < haddr + HPAGE_PMD_SIZE);
mmun_start = haddr;
mmun_end = haddr + HPAGE_PMD_SIZE;
again:
mmu_notifier_invalidate_range_start(mm, mmun_start, mmun_end);
ptl = pmd_lock(mm, pmd);
if (unlikely(!pmd_trans_huge(*pmd))) {
spin_unlock(ptl);
mmu_notifier_invalidate_range_end(mm, mmun_start, mmun_end);
return;
}
if (is_huge_zero_pmd(*pmd)) {
__split_huge_zero_page_pmd(vma, haddr, pmd);
spin_unlock(ptl);
mmu_notifier_invalidate_range_end(mm, mmun_start, mmun_end);
return;
}
page = pmd_page(*pmd);
VM_BUG_ON_PAGE(!page_count(page), page);
get_page(page);
spin_unlock(ptl);
mmu_notifier_invalidate_range_end(mm, mmun_start, mmun_end);
split_huge_page(page);
put_page(page);
if (unlikely(pmd_trans_huge(*pmd)))
goto again;
}
void split_huge_page_pmd_mm(struct mm_struct *mm, unsigned long address,
pmd_t *pmd)
{
struct vm_area_struct *vma;
vma = find_vma(mm, address);
BUG_ON(vma == NULL);
split_huge_page_pmd(vma, address, pmd);
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
split_huge_page_pmd_mm(mm, address, pmd);
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
