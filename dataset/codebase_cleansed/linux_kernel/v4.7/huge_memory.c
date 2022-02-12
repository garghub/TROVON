static void set_recommended_min_free_kbytes(void)
{
struct zone *zone;
int nr_zones = 0;
unsigned long recommended_min;
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
pr_info("raising min_free_kbytes from %d to %lu to help transparent hugepage allocations\n",
min_free_kbytes, recommended_min);
min_free_kbytes = recommended_min;
}
setup_per_zone_wmarks();
}
static int start_stop_khugepaged(void)
{
int err = 0;
if (khugepaged_enabled()) {
if (!khugepaged_thread)
khugepaged_thread = kthread_run(khugepaged, NULL,
"khugepaged");
if (IS_ERR(khugepaged_thread)) {
pr_err("khugepaged: kthread_run(khugepaged) failed\n");
err = PTR_ERR(khugepaged_thread);
khugepaged_thread = NULL;
goto fail;
}
if (!list_empty(&khugepaged_scan.mm_head))
wake_up_interruptible(&khugepaged_wait);
set_recommended_min_free_kbytes();
} else if (khugepaged_thread) {
kthread_stop(khugepaged_thread);
khugepaged_thread = NULL;
}
fail:
return err;
}
struct page *get_huge_zero_page(void)
{
struct page *zero_page;
retry:
if (likely(atomic_inc_not_zero(&huge_zero_refcount)))
return READ_ONCE(huge_zero_page);
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
return READ_ONCE(huge_zero_page);
}
void put_huge_zero_page(void)
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
static ssize_t triple_flag_store(struct kobject *kobj,
struct kobj_attribute *attr,
const char *buf, size_t count,
enum transparent_hugepage_flag enabled,
enum transparent_hugepage_flag deferred,
enum transparent_hugepage_flag req_madv)
{
if (!memcmp("defer", buf,
min(sizeof("defer")-1, count))) {
if (enabled == deferred)
return -EINVAL;
clear_bit(enabled, &transparent_hugepage_flags);
clear_bit(req_madv, &transparent_hugepage_flags);
set_bit(deferred, &transparent_hugepage_flags);
} else if (!memcmp("always", buf,
min(sizeof("always")-1, count))) {
clear_bit(deferred, &transparent_hugepage_flags);
clear_bit(req_madv, &transparent_hugepage_flags);
set_bit(enabled, &transparent_hugepage_flags);
} else if (!memcmp("madvise", buf,
min(sizeof("madvise")-1, count))) {
clear_bit(enabled, &transparent_hugepage_flags);
clear_bit(deferred, &transparent_hugepage_flags);
set_bit(req_madv, &transparent_hugepage_flags);
} else if (!memcmp("never", buf,
min(sizeof("never")-1, count))) {
clear_bit(enabled, &transparent_hugepage_flags);
clear_bit(req_madv, &transparent_hugepage_flags);
clear_bit(deferred, &transparent_hugepage_flags);
} else
return -EINVAL;
return count;
}
static ssize_t enabled_show(struct kobject *kobj,
struct kobj_attribute *attr, char *buf)
{
if (test_bit(TRANSPARENT_HUGEPAGE_FLAG, &transparent_hugepage_flags))
return sprintf(buf, "[always] madvise never\n");
else if (test_bit(TRANSPARENT_HUGEPAGE_REQ_MADV_FLAG, &transparent_hugepage_flags))
return sprintf(buf, "always [madvise] never\n");
else
return sprintf(buf, "always madvise [never]\n");
}
static ssize_t enabled_store(struct kobject *kobj,
struct kobj_attribute *attr,
const char *buf, size_t count)
{
ssize_t ret;
ret = triple_flag_store(kobj, attr, buf, count,
TRANSPARENT_HUGEPAGE_FLAG,
TRANSPARENT_HUGEPAGE_FLAG,
TRANSPARENT_HUGEPAGE_REQ_MADV_FLAG);
if (ret > 0) {
int err;
mutex_lock(&khugepaged_mutex);
err = start_stop_khugepaged();
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
if (test_bit(TRANSPARENT_HUGEPAGE_DEFRAG_DIRECT_FLAG, &transparent_hugepage_flags))
return sprintf(buf, "[always] defer madvise never\n");
if (test_bit(TRANSPARENT_HUGEPAGE_DEFRAG_KSWAPD_FLAG, &transparent_hugepage_flags))
return sprintf(buf, "always [defer] madvise never\n");
else if (test_bit(TRANSPARENT_HUGEPAGE_DEFRAG_REQ_MADV_FLAG, &transparent_hugepage_flags))
return sprintf(buf, "always defer [madvise] never\n");
else
return sprintf(buf, "always defer madvise [never]\n");
}
static ssize_t defrag_store(struct kobject *kobj,
struct kobj_attribute *attr,
const char *buf, size_t count)
{
return triple_flag_store(kobj, attr, buf, count,
TRANSPARENT_HUGEPAGE_DEFRAG_DIRECT_FLAG,
TRANSPARENT_HUGEPAGE_DEFRAG_KSWAPD_FLAG,
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
khugepaged_sleep_expire = 0;
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
khugepaged_sleep_expire = 0;
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
khugepaged_pages_to_scan = HPAGE_PMD_NR * 8;
khugepaged_max_ptes_none = HPAGE_PMD_NR - 1;
MAYBE_BUILD_BUG_ON(HPAGE_PMD_ORDER >= MAX_ORDER);
MAYBE_BUILD_BUG_ON(HPAGE_PMD_ORDER < 2);
err = hugepage_init_sysfs(&hugepage_kobj);
if (err)
goto err_sysfs;
err = khugepaged_slab_init();
if (err)
goto err_slab;
err = register_shrinker(&huge_zero_page_shrinker);
if (err)
goto err_hzp_shrinker;
err = register_shrinker(&deferred_split_shrinker);
if (err)
goto err_split_shrinker;
if (totalram_pages < (512 << (20 - PAGE_SHIFT))) {
transparent_hugepage_flags = 0;
return 0;
}
err = start_stop_khugepaged();
if (err)
goto err_khugepaged;
return 0;
err_khugepaged:
unregister_shrinker(&deferred_split_shrinker);
err_split_shrinker:
unregister_shrinker(&huge_zero_page_shrinker);
err_hzp_shrinker:
khugepaged_slab_exit();
err_slab:
hugepage_exit_sysfs(hugepage_kobj);
err_sysfs:
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
return pmd_mkhuge(mk_pmd(page, prot));
}
static inline struct list_head *page_deferred_list(struct page *page)
{
return (struct list_head *)&page[2].mapping;
}
void prep_transhuge_page(struct page *page)
{
INIT_LIST_HEAD(page_deferred_list(page));
set_compound_page_dtor(page, TRANSHUGE_PAGE_DTOR);
}
static int __do_huge_pmd_anonymous_page(struct mm_struct *mm,
struct vm_area_struct *vma,
unsigned long address, pmd_t *pmd,
struct page *page, gfp_t gfp,
unsigned int flags)
{
struct mem_cgroup *memcg;
pgtable_t pgtable;
spinlock_t *ptl;
unsigned long haddr = address & HPAGE_PMD_MASK;
VM_BUG_ON_PAGE(!PageCompound(page), page);
if (mem_cgroup_try_charge(page, mm, gfp, &memcg, true)) {
put_page(page);
count_vm_event(THP_FAULT_FALLBACK);
return VM_FAULT_FALLBACK;
}
pgtable = pte_alloc_one(mm, haddr);
if (unlikely(!pgtable)) {
mem_cgroup_cancel_charge(page, memcg, true);
put_page(page);
return VM_FAULT_OOM;
}
clear_huge_page(page, haddr, HPAGE_PMD_NR);
__SetPageUptodate(page);
ptl = pmd_lock(mm, pmd);
if (unlikely(!pmd_none(*pmd))) {
spin_unlock(ptl);
mem_cgroup_cancel_charge(page, memcg, true);
put_page(page);
pte_free(mm, pgtable);
} else {
pmd_t entry;
if (userfaultfd_missing(vma)) {
int ret;
spin_unlock(ptl);
mem_cgroup_cancel_charge(page, memcg, true);
put_page(page);
pte_free(mm, pgtable);
ret = handle_userfault(vma, address, flags,
VM_UFFD_MISSING);
VM_BUG_ON(ret & VM_FAULT_FALLBACK);
return ret;
}
entry = mk_huge_pmd(page, vma->vm_page_prot);
entry = maybe_pmd_mkwrite(pmd_mkdirty(entry), vma);
page_add_new_anon_rmap(page, vma, haddr, true);
mem_cgroup_commit_charge(page, memcg, false, true);
lru_cache_add_active_or_unevictable(page, vma);
pgtable_trans_huge_deposit(mm, pmd, pgtable);
set_pmd_at(mm, haddr, pmd, entry);
add_mm_counter(mm, MM_ANONPAGES, HPAGE_PMD_NR);
atomic_long_inc(&mm->nr_ptes);
spin_unlock(ptl);
count_vm_event(THP_FAULT_ALLOC);
}
return 0;
}
static inline gfp_t alloc_hugepage_direct_gfpmask(struct vm_area_struct *vma)
{
gfp_t reclaim_flags = 0;
if (test_bit(TRANSPARENT_HUGEPAGE_DEFRAG_REQ_MADV_FLAG, &transparent_hugepage_flags) &&
(vma->vm_flags & VM_HUGEPAGE))
reclaim_flags = __GFP_DIRECT_RECLAIM;
else if (test_bit(TRANSPARENT_HUGEPAGE_DEFRAG_KSWAPD_FLAG, &transparent_hugepage_flags))
reclaim_flags = __GFP_KSWAPD_RECLAIM;
else if (test_bit(TRANSPARENT_HUGEPAGE_DEFRAG_DIRECT_FLAG, &transparent_hugepage_flags))
reclaim_flags = __GFP_DIRECT_RECLAIM;
return GFP_TRANSHUGE | reclaim_flags;
}
static inline gfp_t alloc_hugepage_khugepaged_gfpmask(void)
{
return GFP_TRANSHUGE | (khugepaged_defrag() ? __GFP_DIRECT_RECLAIM : 0);
}
static bool set_huge_zero_page(pgtable_t pgtable, struct mm_struct *mm,
struct vm_area_struct *vma, unsigned long haddr, pmd_t *pmd,
struct page *zero_page)
{
pmd_t entry;
if (!pmd_none(*pmd))
return false;
entry = mk_pmd(zero_page, vma->vm_page_prot);
entry = pmd_mkhuge(entry);
if (pgtable)
pgtable_trans_huge_deposit(mm, pmd, pgtable);
set_pmd_at(mm, haddr, pmd, entry);
atomic_long_inc(&mm->nr_ptes);
return true;
}
int do_huge_pmd_anonymous_page(struct mm_struct *mm, struct vm_area_struct *vma,
unsigned long address, pmd_t *pmd,
unsigned int flags)
{
gfp_t gfp;
struct page *page;
unsigned long haddr = address & HPAGE_PMD_MASK;
if (haddr < vma->vm_start || haddr + HPAGE_PMD_SIZE > vma->vm_end)
return VM_FAULT_FALLBACK;
if (unlikely(anon_vma_prepare(vma)))
return VM_FAULT_OOM;
if (unlikely(khugepaged_enter(vma, vma->vm_flags)))
return VM_FAULT_OOM;
if (!(flags & FAULT_FLAG_WRITE) && !mm_forbids_zeropage(mm) &&
transparent_hugepage_use_zero_page()) {
spinlock_t *ptl;
pgtable_t pgtable;
struct page *zero_page;
bool set;
int ret;
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
ret = 0;
set = false;
if (pmd_none(*pmd)) {
if (userfaultfd_missing(vma)) {
spin_unlock(ptl);
ret = handle_userfault(vma, address, flags,
VM_UFFD_MISSING);
VM_BUG_ON(ret & VM_FAULT_FALLBACK);
} else {
set_huge_zero_page(pgtable, mm, vma,
haddr, pmd,
zero_page);
spin_unlock(ptl);
set = true;
}
} else
spin_unlock(ptl);
if (!set) {
pte_free(mm, pgtable);
put_huge_zero_page();
}
return ret;
}
gfp = alloc_hugepage_direct_gfpmask(vma);
page = alloc_hugepage_vma(gfp, vma, haddr, HPAGE_PMD_ORDER);
if (unlikely(!page)) {
count_vm_event(THP_FAULT_FALLBACK);
return VM_FAULT_FALLBACK;
}
prep_transhuge_page(page);
return __do_huge_pmd_anonymous_page(mm, vma, address, pmd, page, gfp,
flags);
}
static void insert_pfn_pmd(struct vm_area_struct *vma, unsigned long addr,
pmd_t *pmd, pfn_t pfn, pgprot_t prot, bool write)
{
struct mm_struct *mm = vma->vm_mm;
pmd_t entry;
spinlock_t *ptl;
ptl = pmd_lock(mm, pmd);
entry = pmd_mkhuge(pfn_t_pmd(pfn, prot));
if (pfn_t_devmap(pfn))
entry = pmd_mkdevmap(entry);
if (write) {
entry = pmd_mkyoung(pmd_mkdirty(entry));
entry = maybe_pmd_mkwrite(entry, vma);
}
set_pmd_at(mm, addr, pmd, entry);
update_mmu_cache_pmd(vma, addr, pmd);
spin_unlock(ptl);
}
int vmf_insert_pfn_pmd(struct vm_area_struct *vma, unsigned long addr,
pmd_t *pmd, pfn_t pfn, bool write)
{
pgprot_t pgprot = vma->vm_page_prot;
BUG_ON(!(vma->vm_flags & (VM_PFNMAP|VM_MIXEDMAP)));
BUG_ON((vma->vm_flags & (VM_PFNMAP|VM_MIXEDMAP)) ==
(VM_PFNMAP|VM_MIXEDMAP));
BUG_ON((vma->vm_flags & VM_PFNMAP) && is_cow_mapping(vma->vm_flags));
BUG_ON(!pfn_t_devmap(pfn));
if (addr < vma->vm_start || addr >= vma->vm_end)
return VM_FAULT_SIGBUS;
if (track_pfn_insert(vma, &pgprot, pfn))
return VM_FAULT_SIGBUS;
insert_pfn_pmd(vma, addr, pmd, pfn, pgprot, write);
return VM_FAULT_NOPAGE;
}
static void touch_pmd(struct vm_area_struct *vma, unsigned long addr,
pmd_t *pmd)
{
pmd_t _pmd;
_pmd = pmd_mkyoung(pmd_mkdirty(*pmd));
if (pmdp_set_access_flags(vma, addr & HPAGE_PMD_MASK,
pmd, _pmd, 1))
update_mmu_cache_pmd(vma, addr, pmd);
}
struct page *follow_devmap_pmd(struct vm_area_struct *vma, unsigned long addr,
pmd_t *pmd, int flags)
{
unsigned long pfn = pmd_pfn(*pmd);
struct mm_struct *mm = vma->vm_mm;
struct dev_pagemap *pgmap;
struct page *page;
assert_spin_locked(pmd_lockptr(mm, pmd));
if (flags & FOLL_WRITE && !pmd_write(*pmd))
return NULL;
if (pmd_present(*pmd) && pmd_devmap(*pmd))
;
else
return NULL;
if (flags & FOLL_TOUCH)
touch_pmd(vma, addr, pmd);
if (!(flags & FOLL_GET))
return ERR_PTR(-EEXIST);
pfn += (addr & ~PMD_MASK) >> PAGE_SHIFT;
pgmap = get_dev_pagemap(pfn, NULL);
if (!pgmap)
return ERR_PTR(-EFAULT);
page = pfn_to_page(pfn);
get_page(page);
put_dev_pagemap(pgmap);
return page;
}
int copy_huge_pmd(struct mm_struct *dst_mm, struct mm_struct *src_mm,
pmd_t *dst_pmd, pmd_t *src_pmd, unsigned long addr,
struct vm_area_struct *vma)
{
spinlock_t *dst_ptl, *src_ptl;
struct page *src_page;
pmd_t pmd;
pgtable_t pgtable = NULL;
int ret;
if (!vma_is_dax(vma)) {
ret = -ENOMEM;
pgtable = pte_alloc_one(dst_mm, addr);
if (unlikely(!pgtable))
goto out;
}
dst_ptl = pmd_lock(dst_mm, dst_pmd);
src_ptl = pmd_lockptr(src_mm, src_pmd);
spin_lock_nested(src_ptl, SINGLE_DEPTH_NESTING);
ret = -EAGAIN;
pmd = *src_pmd;
if (unlikely(!pmd_trans_huge(pmd) && !pmd_devmap(pmd))) {
pte_free(dst_mm, pgtable);
goto out_unlock;
}
if (is_huge_zero_pmd(pmd)) {
struct page *zero_page;
zero_page = get_huge_zero_page();
set_huge_zero_page(pgtable, dst_mm, vma, addr, dst_pmd,
zero_page);
ret = 0;
goto out_unlock;
}
if (!vma_is_dax(vma)) {
src_page = pmd_page(pmd);
VM_BUG_ON_PAGE(!PageHead(src_page), src_page);
get_page(src_page);
page_dup_rmap(src_page, true);
add_mm_counter(dst_mm, MM_ANONPAGES, HPAGE_PMD_NR);
atomic_long_inc(&dst_mm->nr_ptes);
pgtable_trans_huge_deposit(dst_mm, dst_pmd, pgtable);
}
pmdp_set_wrprotect(src_mm, addr, src_pmd);
pmd = pmd_mkold(pmd_wrprotect(pmd));
set_pmd_at(dst_mm, addr, dst_pmd, pmd);
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
&memcg, false))) {
if (pages[i])
put_page(pages[i]);
while (--i >= 0) {
memcg = (void *)page_private(pages[i]);
set_page_private(pages[i], 0);
mem_cgroup_cancel_charge(pages[i], memcg,
false);
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
pmdp_huge_clear_flush_notify(vma, haddr, pmd);
pgtable = pgtable_trans_huge_withdraw(mm, pmd);
pmd_populate(mm, &_pmd, pgtable);
for (i = 0; i < HPAGE_PMD_NR; i++, haddr += PAGE_SIZE) {
pte_t *pte, entry;
entry = mk_pte(pages[i], vma->vm_page_prot);
entry = maybe_mkwrite(pte_mkdirty(entry), vma);
memcg = (void *)page_private(pages[i]);
set_page_private(pages[i], 0);
page_add_new_anon_rmap(pages[i], vma, haddr, false);
mem_cgroup_commit_charge(pages[i], memcg, false, false);
lru_cache_add_active_or_unevictable(pages[i], vma);
pte = pte_offset_map(&_pmd, haddr);
VM_BUG_ON(!pte_none(*pte));
set_pte_at(mm, haddr, pte, entry);
pte_unmap(pte);
}
kfree(pages);
smp_wmb();
pmd_populate(mm, pmd, pgtable);
page_remove_rmap(page, true);
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
mem_cgroup_cancel_charge(pages[i], memcg, false);
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
gfp_t huge_gfp;
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
if (page_trans_huge_mapcount(page, NULL) == 1) {
pmd_t entry;
entry = pmd_mkyoung(orig_pmd);
entry = maybe_pmd_mkwrite(pmd_mkdirty(entry), vma);
if (pmdp_set_access_flags(vma, haddr, pmd, entry, 1))
update_mmu_cache_pmd(vma, address, pmd);
ret |= VM_FAULT_WRITE;
goto out_unlock;
}
get_page(page);
spin_unlock(ptl);
alloc:
if (transparent_hugepage_enabled(vma) &&
!transparent_hugepage_debug_cow()) {
huge_gfp = alloc_hugepage_direct_gfpmask(vma);
new_page = alloc_hugepage_vma(huge_gfp, vma, haddr, HPAGE_PMD_ORDER);
} else
new_page = NULL;
if (likely(new_page)) {
prep_transhuge_page(new_page);
} else {
if (!page) {
split_huge_pmd(vma, pmd, address);
ret |= VM_FAULT_FALLBACK;
} else {
ret = do_huge_pmd_wp_page_fallback(mm, vma, address,
pmd, orig_pmd, page, haddr);
if (ret & VM_FAULT_OOM) {
split_huge_pmd(vma, pmd, address);
ret |= VM_FAULT_FALLBACK;
}
put_page(page);
}
count_vm_event(THP_FAULT_FALLBACK);
goto out;
}
if (unlikely(mem_cgroup_try_charge(new_page, mm, huge_gfp, &memcg,
true))) {
put_page(new_page);
if (page) {
split_huge_pmd(vma, pmd, address);
put_page(page);
} else
split_huge_pmd(vma, pmd, address);
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
put_page(page);
if (unlikely(!pmd_same(*pmd, orig_pmd))) {
spin_unlock(ptl);
mem_cgroup_cancel_charge(new_page, memcg, true);
put_page(new_page);
goto out_mn;
} else {
pmd_t entry;
entry = mk_huge_pmd(new_page, vma->vm_page_prot);
entry = maybe_pmd_mkwrite(pmd_mkdirty(entry), vma);
pmdp_huge_clear_flush_notify(vma, haddr, pmd);
page_add_new_anon_rmap(new_page, vma, haddr, true);
mem_cgroup_commit_charge(new_page, memcg, false, true);
lru_cache_add_active_or_unevictable(new_page, vma);
set_pmd_at(mm, haddr, pmd, entry);
update_mmu_cache_pmd(vma, address, pmd);
if (!page) {
add_mm_counter(mm, MM_ANONPAGES, HPAGE_PMD_NR);
put_huge_zero_page();
} else {
VM_BUG_ON_PAGE(!PageHead(page), page);
page_remove_rmap(page, true);
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
if ((flags & FOLL_NUMA) && pmd_protnone(*pmd))
goto out;
page = pmd_page(*pmd);
VM_BUG_ON_PAGE(!PageHead(page), page);
if (flags & FOLL_TOUCH)
touch_pmd(vma, addr, pmd);
if ((flags & FOLL_MLOCK) && (vma->vm_flags & VM_LOCKED)) {
if (compound_mapcount(page) == 1 && !PageDoubleMap(page) &&
page->mapping && trylock_page(page)) {
lru_add_drain();
if (page->mapping)
mlock_vma_page(page);
unlock_page(page);
}
}
page += (addr & ~HPAGE_PMD_MASK) >> PAGE_SHIFT;
VM_BUG_ON_PAGE(!PageCompound(page), page);
if (flags & FOLL_GET)
get_page(page);
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
bool was_writable;
int flags = 0;
BUG_ON(!(vma->vm_flags & (VM_READ | VM_EXEC | VM_WRITE)));
ptl = pmd_lock(mm, pmdp);
if (unlikely(!pmd_same(pmd, *pmdp)))
goto out_unlock;
if (unlikely(pmd_trans_migrating(*pmdp))) {
page = pmd_page(*pmdp);
spin_unlock(ptl);
wait_on_page_locked(page);
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
if (!(vma->vm_flags & VM_WRITE))
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
} else
flags |= TNF_MIGRATE_FAIL;
goto out;
clear_pmdnuma:
BUG_ON(!PageLocked(page));
was_writable = pmd_write(pmd);
pmd = pmd_modify(pmd, vma->vm_page_prot);
pmd = pmd_mkyoung(pmd);
if (was_writable)
pmd = pmd_mkwrite(pmd);
set_pmd_at(mm, haddr, pmdp, pmd);
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
int madvise_free_huge_pmd(struct mmu_gather *tlb, struct vm_area_struct *vma,
pmd_t *pmd, unsigned long addr, unsigned long next)
{
spinlock_t *ptl;
pmd_t orig_pmd;
struct page *page;
struct mm_struct *mm = tlb->mm;
int ret = 0;
ptl = pmd_trans_huge_lock(pmd, vma);
if (!ptl)
goto out_unlocked;
orig_pmd = *pmd;
if (is_huge_zero_pmd(orig_pmd)) {
ret = 1;
goto out;
}
page = pmd_page(orig_pmd);
if (page_mapcount(page) != 1)
goto out;
if (!trylock_page(page))
goto out;
if (next - addr != HPAGE_PMD_SIZE) {
get_page(page);
spin_unlock(ptl);
split_huge_page(page);
put_page(page);
unlock_page(page);
goto out_unlocked;
}
if (PageDirty(page))
ClearPageDirty(page);
unlock_page(page);
if (PageActive(page))
deactivate_page(page);
if (pmd_young(orig_pmd) || pmd_dirty(orig_pmd)) {
orig_pmd = pmdp_huge_get_and_clear_full(tlb->mm, addr, pmd,
tlb->fullmm);
orig_pmd = pmd_mkold(orig_pmd);
orig_pmd = pmd_mkclean(orig_pmd);
set_pmd_at(mm, addr, pmd, orig_pmd);
tlb_remove_pmd_tlb_entry(tlb, pmd, addr);
}
ret = 1;
out:
spin_unlock(ptl);
out_unlocked:
return ret;
}
int zap_huge_pmd(struct mmu_gather *tlb, struct vm_area_struct *vma,
pmd_t *pmd, unsigned long addr)
{
pmd_t orig_pmd;
spinlock_t *ptl;
ptl = __pmd_trans_huge_lock(pmd, vma);
if (!ptl)
return 0;
orig_pmd = pmdp_huge_get_and_clear_full(tlb->mm, addr, pmd,
tlb->fullmm);
tlb_remove_pmd_tlb_entry(tlb, pmd, addr);
if (vma_is_dax(vma)) {
spin_unlock(ptl);
if (is_huge_zero_pmd(orig_pmd))
tlb_remove_page(tlb, pmd_page(orig_pmd));
} else if (is_huge_zero_pmd(orig_pmd)) {
pte_free(tlb->mm, pgtable_trans_huge_withdraw(tlb->mm, pmd));
atomic_long_dec(&tlb->mm->nr_ptes);
spin_unlock(ptl);
tlb_remove_page(tlb, pmd_page(orig_pmd));
} else {
struct page *page = pmd_page(orig_pmd);
page_remove_rmap(page, true);
VM_BUG_ON_PAGE(page_mapcount(page) < 0, page);
add_mm_counter(tlb->mm, MM_ANONPAGES, -HPAGE_PMD_NR);
VM_BUG_ON_PAGE(!PageHead(page), page);
pte_free(tlb->mm, pgtable_trans_huge_withdraw(tlb->mm, pmd));
atomic_long_dec(&tlb->mm->nr_ptes);
spin_unlock(ptl);
tlb_remove_page(tlb, page);
}
return 1;
}
bool move_huge_pmd(struct vm_area_struct *vma, unsigned long old_addr,
unsigned long new_addr, unsigned long old_end,
pmd_t *old_pmd, pmd_t *new_pmd)
{
spinlock_t *old_ptl, *new_ptl;
pmd_t pmd;
struct mm_struct *mm = vma->vm_mm;
if ((old_addr & ~HPAGE_PMD_MASK) ||
(new_addr & ~HPAGE_PMD_MASK) ||
old_end - old_addr < HPAGE_PMD_SIZE)
return false;
if (WARN_ON(!pmd_none(*new_pmd))) {
VM_BUG_ON(pmd_trans_huge(*new_pmd));
return false;
}
old_ptl = __pmd_trans_huge_lock(old_pmd, vma);
if (old_ptl) {
new_ptl = pmd_lockptr(mm, new_pmd);
if (new_ptl != old_ptl)
spin_lock_nested(new_ptl, SINGLE_DEPTH_NESTING);
pmd = pmdp_huge_get_and_clear(mm, old_addr, old_pmd);
VM_BUG_ON(!pmd_none(*new_pmd));
if (pmd_move_must_withdraw(new_ptl, old_ptl) &&
vma_is_anonymous(vma)) {
pgtable_t pgtable;
pgtable = pgtable_trans_huge_withdraw(mm, old_pmd);
pgtable_trans_huge_deposit(mm, new_pmd, pgtable);
}
set_pmd_at(mm, new_addr, new_pmd, pmd_mksoft_dirty(pmd));
if (new_ptl != old_ptl)
spin_unlock(new_ptl);
spin_unlock(old_ptl);
return true;
}
return false;
}
int change_huge_pmd(struct vm_area_struct *vma, pmd_t *pmd,
unsigned long addr, pgprot_t newprot, int prot_numa)
{
struct mm_struct *mm = vma->vm_mm;
spinlock_t *ptl;
int ret = 0;
ptl = __pmd_trans_huge_lock(pmd, vma);
if (ptl) {
pmd_t entry;
bool preserve_write = prot_numa && pmd_write(*pmd);
ret = 1;
if (prot_numa && is_huge_zero_pmd(*pmd)) {
spin_unlock(ptl);
return ret;
}
if (!prot_numa || !pmd_protnone(*pmd)) {
entry = pmdp_huge_get_and_clear_notify(mm, addr, pmd);
entry = pmd_modify(entry, newprot);
if (preserve_write)
entry = pmd_mkwrite(entry);
ret = HPAGE_PMD_NR;
set_pmd_at(mm, addr, pmd, entry);
BUG_ON(!preserve_write && pmd_write(entry));
}
spin_unlock(ptl);
}
return ret;
}
spinlock_t *__pmd_trans_huge_lock(pmd_t *pmd, struct vm_area_struct *vma)
{
spinlock_t *ptl;
ptl = pmd_lock(vma->vm_mm, pmd);
if (likely(pmd_trans_huge(*pmd) || pmd_devmap(*pmd)))
return ptl;
spin_unlock(ptl);
return NULL;
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
if (*vm_flags & VM_NO_THP)
return -EINVAL;
*vm_flags &= ~VM_NOHUGEPAGE;
*vm_flags |= VM_HUGEPAGE;
if (unlikely(khugepaged_enter_vma_merge(vma, *vm_flags)))
return -ENOMEM;
break;
case MADV_NOHUGEPAGE:
if (*vm_flags & VM_NO_THP)
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
static void __init khugepaged_slab_exit(void)
{
kmem_cache_destroy(mm_slot_cache);
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
if (vma->vm_ops || (vm_flags & VM_NO_THP))
return 0;
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
if (!pte_none(pteval) && !is_zero_pfn(pte_pfn(pteval)))
release_pte_page(pte_page(pteval));
}
}
static int __collapse_huge_page_isolate(struct vm_area_struct *vma,
unsigned long address,
pte_t *pte)
{
struct page *page = NULL;
pte_t *_pte;
int none_or_zero = 0, result = 0;
bool referenced = false, writable = false;
for (_pte = pte; _pte < pte+HPAGE_PMD_NR;
_pte++, address += PAGE_SIZE) {
pte_t pteval = *_pte;
if (pte_none(pteval) || (pte_present(pteval) &&
is_zero_pfn(pte_pfn(pteval)))) {
if (!userfaultfd_armed(vma) &&
++none_or_zero <= khugepaged_max_ptes_none) {
continue;
} else {
result = SCAN_EXCEED_NONE_PTE;
goto out;
}
}
if (!pte_present(pteval)) {
result = SCAN_PTE_NON_PRESENT;
goto out;
}
page = vm_normal_page(vma, address, pteval);
if (unlikely(!page)) {
result = SCAN_PAGE_NULL;
goto out;
}
VM_BUG_ON_PAGE(PageCompound(page), page);
VM_BUG_ON_PAGE(!PageAnon(page), page);
VM_BUG_ON_PAGE(!PageSwapBacked(page), page);
if (!trylock_page(page)) {
result = SCAN_PAGE_LOCK;
goto out;
}
if (page_count(page) != 1 + !!PageSwapCache(page)) {
unlock_page(page);
result = SCAN_PAGE_COUNT;
goto out;
}
if (pte_write(pteval)) {
writable = true;
} else {
if (PageSwapCache(page) &&
!reuse_swap_page(page, NULL)) {
unlock_page(page);
result = SCAN_SWAP_CACHE_PAGE;
goto out;
}
}
if (isolate_lru_page(page)) {
unlock_page(page);
result = SCAN_DEL_PAGE_LRU;
goto out;
}
inc_zone_page_state(page, NR_ISOLATED_ANON + 0);
VM_BUG_ON_PAGE(!PageLocked(page), page);
VM_BUG_ON_PAGE(PageLRU(page), page);
if (pte_young(pteval) ||
page_is_young(page) || PageReferenced(page) ||
mmu_notifier_test_young(vma->vm_mm, address))
referenced = true;
}
if (likely(writable)) {
if (likely(referenced)) {
result = SCAN_SUCCEED;
trace_mm_collapse_huge_page_isolate(page, none_or_zero,
referenced, writable, result);
return 1;
}
} else {
result = SCAN_PAGE_RO;
}
out:
release_pte_pages(pte, _pte);
trace_mm_collapse_huge_page_isolate(page, none_or_zero,
referenced, writable, result);
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
if (pte_none(pteval) || is_zero_pfn(pte_pfn(pteval))) {
clear_user_highpage(page, address);
add_mm_counter(vma->vm_mm, MM_ANONPAGES, 1);
if (is_zero_pfn(pte_pfn(pteval))) {
spin_lock(ptl);
pte_clear(vma->vm_mm, address, _pte);
spin_unlock(ptl);
}
} else {
src_page = pte_page(pteval);
copy_user_highpage(page, src_page, address, vma);
VM_BUG_ON_PAGE(page_mapcount(src_page) != 1, src_page);
release_pte_page(src_page);
spin_lock(ptl);
pte_clear(vma->vm_mm, address, _pte);
page_remove_rmap(src_page, false);
spin_unlock(ptl);
free_page_and_swap_cache(src_page);
}
address += PAGE_SIZE;
page++;
}
}
static void khugepaged_alloc_sleep(void)
{
DEFINE_WAIT(wait);
add_wait_queue(&khugepaged_wait, &wait);
freezable_schedule_timeout_interruptible(
msecs_to_jiffies(khugepaged_alloc_sleep_millisecs));
remove_wait_queue(&khugepaged_wait, &wait);
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
static struct page *
khugepaged_alloc_page(struct page **hpage, gfp_t gfp, struct mm_struct *mm,
unsigned long address, int node)
{
VM_BUG_ON_PAGE(*hpage, *hpage);
up_read(&mm->mmap_sem);
*hpage = __alloc_pages_node(node, gfp, HPAGE_PMD_ORDER);
if (unlikely(!*hpage)) {
count_vm_event(THP_COLLAPSE_ALLOC_FAILED);
*hpage = ERR_PTR(-ENOMEM);
return NULL;
}
prep_transhuge_page(*hpage);
count_vm_event(THP_COLLAPSE_ALLOC);
return *hpage;
}
static int khugepaged_find_target_node(void)
{
return 0;
}
static inline struct page *alloc_khugepaged_hugepage(void)
{
struct page *page;
page = alloc_pages(alloc_hugepage_khugepaged_gfpmask(),
HPAGE_PMD_ORDER);
if (page)
prep_transhuge_page(page);
return page;
}
static struct page *khugepaged_alloc_hugepage(bool *wait)
{
struct page *hpage;
do {
hpage = alloc_khugepaged_hugepage();
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
static struct page *
khugepaged_alloc_page(struct page **hpage, gfp_t gfp, struct mm_struct *mm,
unsigned long address, int node)
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
return !(vma->vm_flags & VM_NO_THP);
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
int isolated = 0, result = 0;
unsigned long hstart, hend;
struct mem_cgroup *memcg;
unsigned long mmun_start;
unsigned long mmun_end;
gfp_t gfp;
VM_BUG_ON(address & ~HPAGE_PMD_MASK);
gfp = alloc_hugepage_khugepaged_gfpmask() | __GFP_OTHER_NODE | __GFP_THISNODE;
new_page = khugepaged_alloc_page(hpage, gfp, mm, address, node);
if (!new_page) {
result = SCAN_ALLOC_HUGE_PAGE_FAIL;
goto out_nolock;
}
if (unlikely(mem_cgroup_try_charge(new_page, mm, gfp, &memcg, true))) {
result = SCAN_CGROUP_CHARGE_FAIL;
goto out_nolock;
}
down_write(&mm->mmap_sem);
if (unlikely(khugepaged_test_exit(mm))) {
result = SCAN_ANY_PROCESS;
goto out;
}
vma = find_vma(mm, address);
if (!vma) {
result = SCAN_VMA_NULL;
goto out;
}
hstart = (vma->vm_start + ~HPAGE_PMD_MASK) & HPAGE_PMD_MASK;
hend = vma->vm_end & HPAGE_PMD_MASK;
if (address < hstart || address + HPAGE_PMD_SIZE > hend) {
result = SCAN_ADDRESS_RANGE;
goto out;
}
if (!hugepage_vma_check(vma)) {
result = SCAN_VMA_CHECK;
goto out;
}
pmd = mm_find_pmd(mm, address);
if (!pmd) {
result = SCAN_PMD_NULL;
goto out;
}
anon_vma_lock_write(vma->anon_vma);
pte = pte_offset_map(pmd, address);
pte_ptl = pte_lockptr(mm, pmd);
mmun_start = address;
mmun_end = address + HPAGE_PMD_SIZE;
mmu_notifier_invalidate_range_start(mm, mmun_start, mmun_end);
pmd_ptl = pmd_lock(mm, pmd);
_pmd = pmdp_collapse_flush(vma, address, pmd);
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
result = SCAN_FAIL;
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
page_add_new_anon_rmap(new_page, vma, address, true);
mem_cgroup_commit_charge(new_page, memcg, false, true);
lru_cache_add_active_or_unevictable(new_page, vma);
pgtable_trans_huge_deposit(mm, pmd, pgtable);
set_pmd_at(mm, address, pmd, _pmd);
update_mmu_cache_pmd(vma, address, pmd);
spin_unlock(pmd_ptl);
*hpage = NULL;
khugepaged_pages_collapsed++;
result = SCAN_SUCCEED;
out_up_write:
up_write(&mm->mmap_sem);
trace_mm_collapse_huge_page(mm, isolated, result);
return;
out_nolock:
trace_mm_collapse_huge_page(mm, isolated, result);
return;
out:
mem_cgroup_cancel_charge(new_page, memcg, true);
goto out_up_write;
}
static int khugepaged_scan_pmd(struct mm_struct *mm,
struct vm_area_struct *vma,
unsigned long address,
struct page **hpage)
{
pmd_t *pmd;
pte_t *pte, *_pte;
int ret = 0, none_or_zero = 0, result = 0;
struct page *page = NULL;
unsigned long _address;
spinlock_t *ptl;
int node = NUMA_NO_NODE;
bool writable = false, referenced = false;
VM_BUG_ON(address & ~HPAGE_PMD_MASK);
pmd = mm_find_pmd(mm, address);
if (!pmd) {
result = SCAN_PMD_NULL;
goto out;
}
memset(khugepaged_node_load, 0, sizeof(khugepaged_node_load));
pte = pte_offset_map_lock(mm, pmd, address, &ptl);
for (_address = address, _pte = pte; _pte < pte+HPAGE_PMD_NR;
_pte++, _address += PAGE_SIZE) {
pte_t pteval = *_pte;
if (pte_none(pteval) || is_zero_pfn(pte_pfn(pteval))) {
if (!userfaultfd_armed(vma) &&
++none_or_zero <= khugepaged_max_ptes_none) {
continue;
} else {
result = SCAN_EXCEED_NONE_PTE;
goto out_unmap;
}
}
if (!pte_present(pteval)) {
result = SCAN_PTE_NON_PRESENT;
goto out_unmap;
}
if (pte_write(pteval))
writable = true;
page = vm_normal_page(vma, _address, pteval);
if (unlikely(!page)) {
result = SCAN_PAGE_NULL;
goto out_unmap;
}
if (PageCompound(page)) {
result = SCAN_PAGE_COMPOUND;
goto out_unmap;
}
node = page_to_nid(page);
if (khugepaged_scan_abort(node)) {
result = SCAN_SCAN_ABORT;
goto out_unmap;
}
khugepaged_node_load[node]++;
if (!PageLRU(page)) {
result = SCAN_PAGE_LRU;
goto out_unmap;
}
if (PageLocked(page)) {
result = SCAN_PAGE_LOCK;
goto out_unmap;
}
if (!PageAnon(page)) {
result = SCAN_PAGE_ANON;
goto out_unmap;
}
if (page_count(page) != 1 + !!PageSwapCache(page)) {
result = SCAN_PAGE_COUNT;
goto out_unmap;
}
if (pte_young(pteval) ||
page_is_young(page) || PageReferenced(page) ||
mmu_notifier_test_young(vma->vm_mm, address))
referenced = true;
}
if (writable) {
if (referenced) {
result = SCAN_SUCCEED;
ret = 1;
} else {
result = SCAN_NO_REFERENCED_PAGE;
}
} else {
result = SCAN_PAGE_RO;
}
out_unmap:
pte_unmap_unlock(pte, ptl);
if (ret) {
node = khugepaged_find_target_node();
collapse_huge_page(mm, address, hpage, vma, node);
}
out:
trace_mm_khugepaged_scan_pmd(mm, page, writable, referenced,
none_or_zero, result);
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
if (unlikely(kthread_should_stop() || try_to_freeze()))
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
static bool khugepaged_should_wakeup(void)
{
return kthread_should_stop() ||
time_after_eq(jiffies, khugepaged_sleep_expire);
}
static void khugepaged_wait_work(void)
{
if (khugepaged_has_work()) {
const unsigned long scan_sleep_jiffies =
msecs_to_jiffies(khugepaged_scan_sleep_millisecs);
if (!scan_sleep_jiffies)
return;
khugepaged_sleep_expire = jiffies + scan_sleep_jiffies;
wait_event_freezable_timeout(khugepaged_wait,
khugepaged_should_wakeup(),
scan_sleep_jiffies);
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
pmdp_huge_clear_flush_notify(vma, haddr, pmd);
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
static void __split_huge_pmd_locked(struct vm_area_struct *vma, pmd_t *pmd,
unsigned long haddr, bool freeze)
{
struct mm_struct *mm = vma->vm_mm;
struct page *page;
pgtable_t pgtable;
pmd_t _pmd;
bool young, write, dirty;
unsigned long addr;
int i;
VM_BUG_ON(haddr & ~HPAGE_PMD_MASK);
VM_BUG_ON_VMA(vma->vm_start > haddr, vma);
VM_BUG_ON_VMA(vma->vm_end < haddr + HPAGE_PMD_SIZE, vma);
VM_BUG_ON(!pmd_trans_huge(*pmd) && !pmd_devmap(*pmd));
count_vm_event(THP_SPLIT_PMD);
if (vma_is_dax(vma)) {
pmd_t _pmd = pmdp_huge_clear_flush_notify(vma, haddr, pmd);
if (is_huge_zero_pmd(_pmd))
put_huge_zero_page();
return;
} else if (is_huge_zero_pmd(*pmd)) {
return __split_huge_zero_page_pmd(vma, haddr, pmd);
}
page = pmd_page(*pmd);
VM_BUG_ON_PAGE(!page_count(page), page);
page_ref_add(page, HPAGE_PMD_NR - 1);
write = pmd_write(*pmd);
young = pmd_young(*pmd);
dirty = pmd_dirty(*pmd);
pmdp_huge_split_prepare(vma, haddr, pmd);
pgtable = pgtable_trans_huge_withdraw(mm, pmd);
pmd_populate(mm, &_pmd, pgtable);
for (i = 0, addr = haddr; i < HPAGE_PMD_NR; i++, addr += PAGE_SIZE) {
pte_t entry, *pte;
if (freeze) {
swp_entry_t swp_entry;
swp_entry = make_migration_entry(page + i, write);
entry = swp_entry_to_pte(swp_entry);
} else {
entry = mk_pte(page + i, vma->vm_page_prot);
entry = maybe_mkwrite(entry, vma);
if (!write)
entry = pte_wrprotect(entry);
if (!young)
entry = pte_mkold(entry);
}
if (dirty)
SetPageDirty(page + i);
pte = pte_offset_map(&_pmd, addr);
BUG_ON(!pte_none(*pte));
set_pte_at(mm, addr, pte, entry);
atomic_inc(&page[i]._mapcount);
pte_unmap(pte);
}
if (compound_mapcount(page) > 1 && !TestSetPageDoubleMap(page)) {
for (i = 0; i < HPAGE_PMD_NR; i++)
atomic_inc(&page[i]._mapcount);
}
if (atomic_add_negative(-1, compound_mapcount_ptr(page))) {
__dec_zone_page_state(page, NR_ANON_TRANSPARENT_HUGEPAGES);
if (TestClearPageDoubleMap(page)) {
for (i = 0; i < HPAGE_PMD_NR; i++)
atomic_dec(&page[i]._mapcount);
}
}
smp_wmb();
pmdp_invalidate(vma, haddr, pmd);
pmd_populate(mm, pmd, pgtable);
if (freeze) {
for (i = 0; i < HPAGE_PMD_NR; i++) {
page_remove_rmap(page + i, false);
put_page(page + i);
}
}
}
void __split_huge_pmd(struct vm_area_struct *vma, pmd_t *pmd,
unsigned long address, bool freeze, struct page *page)
{
spinlock_t *ptl;
struct mm_struct *mm = vma->vm_mm;
unsigned long haddr = address & HPAGE_PMD_MASK;
mmu_notifier_invalidate_range_start(mm, haddr, haddr + HPAGE_PMD_SIZE);
ptl = pmd_lock(mm, pmd);
VM_BUG_ON(freeze && !page);
if (page && page != pmd_page(*pmd))
goto out;
if (pmd_trans_huge(*pmd)) {
page = pmd_page(*pmd);
if (PageMlocked(page))
clear_page_mlock(page);
} else if (!pmd_devmap(*pmd))
goto out;
__split_huge_pmd_locked(vma, pmd, haddr, freeze);
out:
spin_unlock(ptl);
mmu_notifier_invalidate_range_end(mm, haddr, haddr + HPAGE_PMD_SIZE);
}
void split_huge_pmd_address(struct vm_area_struct *vma, unsigned long address,
bool freeze, struct page *page)
{
pgd_t *pgd;
pud_t *pud;
pmd_t *pmd;
pgd = pgd_offset(vma->vm_mm, address);
if (!pgd_present(*pgd))
return;
pud = pud_offset(pgd, address);
if (!pud_present(*pud))
return;
pmd = pmd_offset(pud, address);
__split_huge_pmd(vma, pmd, address, freeze, page);
}
void vma_adjust_trans_huge(struct vm_area_struct *vma,
unsigned long start,
unsigned long end,
long adjust_next)
{
if (start & ~HPAGE_PMD_MASK &&
(start & HPAGE_PMD_MASK) >= vma->vm_start &&
(start & HPAGE_PMD_MASK) + HPAGE_PMD_SIZE <= vma->vm_end)
split_huge_pmd_address(vma, start, false, NULL);
if (end & ~HPAGE_PMD_MASK &&
(end & HPAGE_PMD_MASK) >= vma->vm_start &&
(end & HPAGE_PMD_MASK) + HPAGE_PMD_SIZE <= vma->vm_end)
split_huge_pmd_address(vma, end, false, NULL);
if (adjust_next > 0) {
struct vm_area_struct *next = vma->vm_next;
unsigned long nstart = next->vm_start;
nstart += adjust_next << PAGE_SHIFT;
if (nstart & ~HPAGE_PMD_MASK &&
(nstart & HPAGE_PMD_MASK) >= next->vm_start &&
(nstart & HPAGE_PMD_MASK) + HPAGE_PMD_SIZE <= next->vm_end)
split_huge_pmd_address(next, nstart, false, NULL);
}
}
static void freeze_page(struct page *page)
{
enum ttu_flags ttu_flags = TTU_MIGRATION | TTU_IGNORE_MLOCK |
TTU_IGNORE_ACCESS | TTU_RMAP_LOCKED;
int i, ret;
VM_BUG_ON_PAGE(!PageHead(page), page);
ret = try_to_unmap(page, ttu_flags | TTU_SPLIT_HUGE_PMD);
for (i = 1; !ret && i < HPAGE_PMD_NR; i++) {
if (page_count(page) == 1)
return;
ret = try_to_unmap(page + i, ttu_flags);
}
VM_BUG_ON(ret);
}
static void unfreeze_page(struct page *page)
{
int i;
for (i = 0; i < HPAGE_PMD_NR; i++)
remove_migration_ptes(page + i, page + i, true);
}
static void __split_huge_page_tail(struct page *head, int tail,
struct lruvec *lruvec, struct list_head *list)
{
struct page *page_tail = head + tail;
VM_BUG_ON_PAGE(atomic_read(&page_tail->_mapcount) != -1, page_tail);
VM_BUG_ON_PAGE(page_ref_count(page_tail) != 0, page_tail);
page_ref_inc(page_tail);
page_tail->flags &= ~PAGE_FLAGS_CHECK_AT_PREP;
page_tail->flags |= (head->flags &
((1L << PG_referenced) |
(1L << PG_swapbacked) |
(1L << PG_mlocked) |
(1L << PG_uptodate) |
(1L << PG_active) |
(1L << PG_locked) |
(1L << PG_unevictable) |
(1L << PG_dirty)));
smp_wmb();
clear_compound_head(page_tail);
if (page_is_young(head))
set_page_young(page_tail);
if (page_is_idle(head))
set_page_idle(page_tail);
VM_BUG_ON_PAGE(tail > 2 && page_tail->mapping != TAIL_MAPPING,
page_tail);
page_tail->mapping = head->mapping;
page_tail->index = head->index + tail;
page_cpupid_xchg_last(page_tail, page_cpupid_last(head));
lru_add_page_tail(head, page_tail, lruvec, list);
}
static void __split_huge_page(struct page *page, struct list_head *list)
{
struct page *head = compound_head(page);
struct zone *zone = page_zone(head);
struct lruvec *lruvec;
int i;
spin_lock_irq(&zone->lru_lock);
lruvec = mem_cgroup_page_lruvec(head, zone);
mem_cgroup_split_huge_fixup(head);
for (i = HPAGE_PMD_NR - 1; i >= 1; i--)
__split_huge_page_tail(head, i, lruvec, list);
ClearPageCompound(head);
spin_unlock_irq(&zone->lru_lock);
unfreeze_page(head);
for (i = 0; i < HPAGE_PMD_NR; i++) {
struct page *subpage = head + i;
if (subpage == page)
continue;
unlock_page(subpage);
put_page(subpage);
}
}
int total_mapcount(struct page *page)
{
int i, ret;
VM_BUG_ON_PAGE(PageTail(page), page);
if (likely(!PageCompound(page)))
return atomic_read(&page->_mapcount) + 1;
ret = compound_mapcount(page);
if (PageHuge(page))
return ret;
for (i = 0; i < HPAGE_PMD_NR; i++)
ret += atomic_read(&page[i]._mapcount) + 1;
if (PageDoubleMap(page))
ret -= HPAGE_PMD_NR;
return ret;
}
int page_trans_huge_mapcount(struct page *page, int *total_mapcount)
{
int i, ret, _total_mapcount, mapcount;
VM_BUG_ON_PAGE(PageHuge(page), page);
if (likely(!PageTransCompound(page))) {
mapcount = atomic_read(&page->_mapcount) + 1;
if (total_mapcount)
*total_mapcount = mapcount;
return mapcount;
}
page = compound_head(page);
_total_mapcount = ret = 0;
for (i = 0; i < HPAGE_PMD_NR; i++) {
mapcount = atomic_read(&page[i]._mapcount) + 1;
ret = max(ret, mapcount);
_total_mapcount += mapcount;
}
if (PageDoubleMap(page)) {
ret -= 1;
_total_mapcount -= HPAGE_PMD_NR;
}
mapcount = compound_mapcount(page);
ret += mapcount;
_total_mapcount += mapcount;
if (total_mapcount)
*total_mapcount = _total_mapcount;
return ret;
}
int split_huge_page_to_list(struct page *page, struct list_head *list)
{
struct page *head = compound_head(page);
struct pglist_data *pgdata = NODE_DATA(page_to_nid(head));
struct anon_vma *anon_vma;
int count, mapcount, ret;
bool mlocked;
unsigned long flags;
VM_BUG_ON_PAGE(is_huge_zero_page(page), page);
VM_BUG_ON_PAGE(!PageAnon(page), page);
VM_BUG_ON_PAGE(!PageLocked(page), page);
VM_BUG_ON_PAGE(!PageSwapBacked(page), page);
VM_BUG_ON_PAGE(!PageCompound(page), page);
anon_vma = page_get_anon_vma(head);
if (!anon_vma) {
ret = -EBUSY;
goto out;
}
anon_vma_lock_write(anon_vma);
if (total_mapcount(head) != page_count(head) - 1) {
ret = -EBUSY;
goto out_unlock;
}
mlocked = PageMlocked(page);
freeze_page(head);
VM_BUG_ON_PAGE(compound_mapcount(head), head);
if (mlocked)
lru_add_drain();
spin_lock_irqsave(&pgdata->split_queue_lock, flags);
count = page_count(head);
mapcount = total_mapcount(head);
if (!mapcount && count == 1) {
if (!list_empty(page_deferred_list(head))) {
pgdata->split_queue_len--;
list_del(page_deferred_list(head));
}
spin_unlock_irqrestore(&pgdata->split_queue_lock, flags);
__split_huge_page(page, list);
ret = 0;
} else if (IS_ENABLED(CONFIG_DEBUG_VM) && mapcount) {
spin_unlock_irqrestore(&pgdata->split_queue_lock, flags);
pr_alert("total_mapcount: %u, page_count(): %u\n",
mapcount, count);
if (PageTail(page))
dump_page(head, NULL);
dump_page(page, "total_mapcount(head) > 0");
BUG();
} else {
spin_unlock_irqrestore(&pgdata->split_queue_lock, flags);
unfreeze_page(head);
ret = -EBUSY;
}
out_unlock:
anon_vma_unlock_write(anon_vma);
put_anon_vma(anon_vma);
out:
count_vm_event(!ret ? THP_SPLIT_PAGE : THP_SPLIT_PAGE_FAILED);
return ret;
}
void free_transhuge_page(struct page *page)
{
struct pglist_data *pgdata = NODE_DATA(page_to_nid(page));
unsigned long flags;
spin_lock_irqsave(&pgdata->split_queue_lock, flags);
if (!list_empty(page_deferred_list(page))) {
pgdata->split_queue_len--;
list_del(page_deferred_list(page));
}
spin_unlock_irqrestore(&pgdata->split_queue_lock, flags);
free_compound_page(page);
}
void deferred_split_huge_page(struct page *page)
{
struct pglist_data *pgdata = NODE_DATA(page_to_nid(page));
unsigned long flags;
VM_BUG_ON_PAGE(!PageTransHuge(page), page);
spin_lock_irqsave(&pgdata->split_queue_lock, flags);
if (list_empty(page_deferred_list(page))) {
count_vm_event(THP_DEFERRED_SPLIT_PAGE);
list_add_tail(page_deferred_list(page), &pgdata->split_queue);
pgdata->split_queue_len++;
}
spin_unlock_irqrestore(&pgdata->split_queue_lock, flags);
}
static unsigned long deferred_split_count(struct shrinker *shrink,
struct shrink_control *sc)
{
struct pglist_data *pgdata = NODE_DATA(sc->nid);
return ACCESS_ONCE(pgdata->split_queue_len);
}
static unsigned long deferred_split_scan(struct shrinker *shrink,
struct shrink_control *sc)
{
struct pglist_data *pgdata = NODE_DATA(sc->nid);
unsigned long flags;
LIST_HEAD(list), *pos, *next;
struct page *page;
int split = 0;
spin_lock_irqsave(&pgdata->split_queue_lock, flags);
list_for_each_safe(pos, next, &pgdata->split_queue) {
page = list_entry((void *)pos, struct page, mapping);
page = compound_head(page);
if (get_page_unless_zero(page)) {
list_move(page_deferred_list(page), &list);
} else {
list_del_init(page_deferred_list(page));
pgdata->split_queue_len--;
}
if (!--sc->nr_to_scan)
break;
}
spin_unlock_irqrestore(&pgdata->split_queue_lock, flags);
list_for_each_safe(pos, next, &list) {
page = list_entry((void *)pos, struct page, mapping);
lock_page(page);
if (!split_huge_page(page))
split++;
unlock_page(page);
put_page(page);
}
spin_lock_irqsave(&pgdata->split_queue_lock, flags);
list_splice_tail(&list, &pgdata->split_queue);
spin_unlock_irqrestore(&pgdata->split_queue_lock, flags);
if (!split && list_empty(&pgdata->split_queue))
return SHRINK_STOP;
return split;
}
static int split_huge_pages_set(void *data, u64 val)
{
struct zone *zone;
struct page *page;
unsigned long pfn, max_zone_pfn;
unsigned long total = 0, split = 0;
if (val != 1)
return -EINVAL;
for_each_populated_zone(zone) {
max_zone_pfn = zone_end_pfn(zone);
for (pfn = zone->zone_start_pfn; pfn < max_zone_pfn; pfn++) {
if (!pfn_valid(pfn))
continue;
page = pfn_to_page(pfn);
if (!get_page_unless_zero(page))
continue;
if (zone != page_zone(page))
goto next;
if (!PageHead(page) || !PageAnon(page) ||
PageHuge(page))
goto next;
total++;
lock_page(page);
if (!split_huge_page(page))
split++;
unlock_page(page);
next:
put_page(page);
}
}
pr_info("%lu of %lu THP split\n", split, total);
return 0;
}
static int __init split_huge_pages_debugfs(void)
{
void *ret;
ret = debugfs_create_file("split_huge_pages", 0200, NULL, NULL,
&split_huge_pages_fops);
if (!ret)
pr_warn("Failed to create split_huge_pages in debugfs");
return 0;
}
