static inline struct anon_vma *anon_vma_alloc(void)
{
struct anon_vma *anon_vma;
anon_vma = kmem_cache_alloc(anon_vma_cachep, GFP_KERNEL);
if (anon_vma) {
atomic_set(&anon_vma->refcount, 1);
anon_vma->degree = 1;
anon_vma->parent = anon_vma;
anon_vma->root = anon_vma;
}
return anon_vma;
}
static inline void anon_vma_free(struct anon_vma *anon_vma)
{
VM_BUG_ON(atomic_read(&anon_vma->refcount));
might_sleep();
if (rwsem_is_locked(&anon_vma->root->rwsem)) {
anon_vma_lock_write(anon_vma);
anon_vma_unlock_write(anon_vma);
}
kmem_cache_free(anon_vma_cachep, anon_vma);
}
static inline struct anon_vma_chain *anon_vma_chain_alloc(gfp_t gfp)
{
return kmem_cache_alloc(anon_vma_chain_cachep, gfp);
}
static void anon_vma_chain_free(struct anon_vma_chain *anon_vma_chain)
{
kmem_cache_free(anon_vma_chain_cachep, anon_vma_chain);
}
static void anon_vma_chain_link(struct vm_area_struct *vma,
struct anon_vma_chain *avc,
struct anon_vma *anon_vma)
{
avc->vma = vma;
avc->anon_vma = anon_vma;
list_add(&avc->same_vma, &vma->anon_vma_chain);
anon_vma_interval_tree_insert(avc, &anon_vma->rb_root);
}
int anon_vma_prepare(struct vm_area_struct *vma)
{
struct anon_vma *anon_vma = vma->anon_vma;
struct anon_vma_chain *avc;
might_sleep();
if (unlikely(!anon_vma)) {
struct mm_struct *mm = vma->vm_mm;
struct anon_vma *allocated;
avc = anon_vma_chain_alloc(GFP_KERNEL);
if (!avc)
goto out_enomem;
anon_vma = find_mergeable_anon_vma(vma);
allocated = NULL;
if (!anon_vma) {
anon_vma = anon_vma_alloc();
if (unlikely(!anon_vma))
goto out_enomem_free_avc;
allocated = anon_vma;
}
anon_vma_lock_write(anon_vma);
spin_lock(&mm->page_table_lock);
if (likely(!vma->anon_vma)) {
vma->anon_vma = anon_vma;
anon_vma_chain_link(vma, avc, anon_vma);
anon_vma->degree++;
allocated = NULL;
avc = NULL;
}
spin_unlock(&mm->page_table_lock);
anon_vma_unlock_write(anon_vma);
if (unlikely(allocated))
put_anon_vma(allocated);
if (unlikely(avc))
anon_vma_chain_free(avc);
}
return 0;
out_enomem_free_avc:
anon_vma_chain_free(avc);
out_enomem:
return -ENOMEM;
}
static inline struct anon_vma *lock_anon_vma_root(struct anon_vma *root, struct anon_vma *anon_vma)
{
struct anon_vma *new_root = anon_vma->root;
if (new_root != root) {
if (WARN_ON_ONCE(root))
up_write(&root->rwsem);
root = new_root;
down_write(&root->rwsem);
}
return root;
}
static inline void unlock_anon_vma_root(struct anon_vma *root)
{
if (root)
up_write(&root->rwsem);
}
int anon_vma_clone(struct vm_area_struct *dst, struct vm_area_struct *src)
{
struct anon_vma_chain *avc, *pavc;
struct anon_vma *root = NULL;
list_for_each_entry_reverse(pavc, &src->anon_vma_chain, same_vma) {
struct anon_vma *anon_vma;
avc = anon_vma_chain_alloc(GFP_NOWAIT | __GFP_NOWARN);
if (unlikely(!avc)) {
unlock_anon_vma_root(root);
root = NULL;
avc = anon_vma_chain_alloc(GFP_KERNEL);
if (!avc)
goto enomem_failure;
}
anon_vma = pavc->anon_vma;
root = lock_anon_vma_root(root, anon_vma);
anon_vma_chain_link(dst, avc, anon_vma);
if (!dst->anon_vma && anon_vma != src->anon_vma &&
anon_vma->degree < 2)
dst->anon_vma = anon_vma;
}
if (dst->anon_vma)
dst->anon_vma->degree++;
unlock_anon_vma_root(root);
return 0;
enomem_failure:
unlink_anon_vmas(dst);
return -ENOMEM;
}
int anon_vma_fork(struct vm_area_struct *vma, struct vm_area_struct *pvma)
{
struct anon_vma_chain *avc;
struct anon_vma *anon_vma;
int error;
if (!pvma->anon_vma)
return 0;
vma->anon_vma = NULL;
error = anon_vma_clone(vma, pvma);
if (error)
return error;
if (vma->anon_vma)
return 0;
anon_vma = anon_vma_alloc();
if (!anon_vma)
goto out_error;
avc = anon_vma_chain_alloc(GFP_KERNEL);
if (!avc)
goto out_error_free_anon_vma;
anon_vma->root = pvma->anon_vma->root;
anon_vma->parent = pvma->anon_vma;
get_anon_vma(anon_vma->root);
vma->anon_vma = anon_vma;
anon_vma_lock_write(anon_vma);
anon_vma_chain_link(vma, avc, anon_vma);
anon_vma->parent->degree++;
anon_vma_unlock_write(anon_vma);
return 0;
out_error_free_anon_vma:
put_anon_vma(anon_vma);
out_error:
unlink_anon_vmas(vma);
return -ENOMEM;
}
void unlink_anon_vmas(struct vm_area_struct *vma)
{
struct anon_vma_chain *avc, *next;
struct anon_vma *root = NULL;
list_for_each_entry_safe(avc, next, &vma->anon_vma_chain, same_vma) {
struct anon_vma *anon_vma = avc->anon_vma;
root = lock_anon_vma_root(root, anon_vma);
anon_vma_interval_tree_remove(avc, &anon_vma->rb_root);
if (RB_EMPTY_ROOT(&anon_vma->rb_root)) {
anon_vma->parent->degree--;
continue;
}
list_del(&avc->same_vma);
anon_vma_chain_free(avc);
}
if (vma->anon_vma)
vma->anon_vma->degree--;
unlock_anon_vma_root(root);
list_for_each_entry_safe(avc, next, &vma->anon_vma_chain, same_vma) {
struct anon_vma *anon_vma = avc->anon_vma;
BUG_ON(anon_vma->degree);
put_anon_vma(anon_vma);
list_del(&avc->same_vma);
anon_vma_chain_free(avc);
}
}
static void anon_vma_ctor(void *data)
{
struct anon_vma *anon_vma = data;
init_rwsem(&anon_vma->rwsem);
atomic_set(&anon_vma->refcount, 0);
anon_vma->rb_root = RB_ROOT;
}
void __init anon_vma_init(void)
{
anon_vma_cachep = kmem_cache_create("anon_vma", sizeof(struct anon_vma),
0, SLAB_DESTROY_BY_RCU|SLAB_PANIC, anon_vma_ctor);
anon_vma_chain_cachep = KMEM_CACHE(anon_vma_chain, SLAB_PANIC);
}
struct anon_vma *page_get_anon_vma(struct page *page)
{
struct anon_vma *anon_vma = NULL;
unsigned long anon_mapping;
rcu_read_lock();
anon_mapping = (unsigned long) ACCESS_ONCE(page->mapping);
if ((anon_mapping & PAGE_MAPPING_FLAGS) != PAGE_MAPPING_ANON)
goto out;
if (!page_mapped(page))
goto out;
anon_vma = (struct anon_vma *) (anon_mapping - PAGE_MAPPING_ANON);
if (!atomic_inc_not_zero(&anon_vma->refcount)) {
anon_vma = NULL;
goto out;
}
if (!page_mapped(page)) {
rcu_read_unlock();
put_anon_vma(anon_vma);
return NULL;
}
out:
rcu_read_unlock();
return anon_vma;
}
struct anon_vma *page_lock_anon_vma_read(struct page *page)
{
struct anon_vma *anon_vma = NULL;
struct anon_vma *root_anon_vma;
unsigned long anon_mapping;
rcu_read_lock();
anon_mapping = (unsigned long) ACCESS_ONCE(page->mapping);
if ((anon_mapping & PAGE_MAPPING_FLAGS) != PAGE_MAPPING_ANON)
goto out;
if (!page_mapped(page))
goto out;
anon_vma = (struct anon_vma *) (anon_mapping - PAGE_MAPPING_ANON);
root_anon_vma = ACCESS_ONCE(anon_vma->root);
if (down_read_trylock(&root_anon_vma->rwsem)) {
if (!page_mapped(page)) {
up_read(&root_anon_vma->rwsem);
anon_vma = NULL;
}
goto out;
}
if (!atomic_inc_not_zero(&anon_vma->refcount)) {
anon_vma = NULL;
goto out;
}
if (!page_mapped(page)) {
rcu_read_unlock();
put_anon_vma(anon_vma);
return NULL;
}
rcu_read_unlock();
anon_vma_lock_read(anon_vma);
if (atomic_dec_and_test(&anon_vma->refcount)) {
anon_vma_unlock_read(anon_vma);
__put_anon_vma(anon_vma);
anon_vma = NULL;
}
return anon_vma;
out:
rcu_read_unlock();
return anon_vma;
}
void page_unlock_anon_vma_read(struct anon_vma *anon_vma)
{
anon_vma_unlock_read(anon_vma);
}
static inline unsigned long
__vma_address(struct page *page, struct vm_area_struct *vma)
{
pgoff_t pgoff = page_to_pgoff(page);
return vma->vm_start + ((pgoff - vma->vm_pgoff) << PAGE_SHIFT);
}
inline unsigned long
vma_address(struct page *page, struct vm_area_struct *vma)
{
unsigned long address = __vma_address(page, vma);
VM_BUG_ON_VMA(address < vma->vm_start || address >= vma->vm_end, vma);
return address;
}
unsigned long page_address_in_vma(struct page *page, struct vm_area_struct *vma)
{
unsigned long address;
if (PageAnon(page)) {
struct anon_vma *page__anon_vma = page_anon_vma(page);
if (!vma->anon_vma || !page__anon_vma ||
vma->anon_vma->root != page__anon_vma->root)
return -EFAULT;
} else if (page->mapping && !(vma->vm_flags & VM_NONLINEAR)) {
if (!vma->vm_file ||
vma->vm_file->f_mapping != page->mapping)
return -EFAULT;
} else
return -EFAULT;
address = __vma_address(page, vma);
if (unlikely(address < vma->vm_start || address >= vma->vm_end))
return -EFAULT;
return address;
}
pmd_t *mm_find_pmd(struct mm_struct *mm, unsigned long address)
{
pgd_t *pgd;
pud_t *pud;
pmd_t *pmd = NULL;
pmd_t pmde;
pgd = pgd_offset(mm, address);
if (!pgd_present(*pgd))
goto out;
pud = pud_offset(pgd, address);
if (!pud_present(*pud))
goto out;
pmd = pmd_offset(pud, address);
pmde = *pmd;
barrier();
if (!pmd_present(pmde) || pmd_trans_huge(pmde))
pmd = NULL;
out:
return pmd;
}
pte_t *__page_check_address(struct page *page, struct mm_struct *mm,
unsigned long address, spinlock_t **ptlp, int sync)
{
pmd_t *pmd;
pte_t *pte;
spinlock_t *ptl;
if (unlikely(PageHuge(page))) {
pte = huge_pte_offset(mm, address);
if (!pte)
return NULL;
ptl = huge_pte_lockptr(page_hstate(page), mm, pte);
goto check;
}
pmd = mm_find_pmd(mm, address);
if (!pmd)
return NULL;
pte = pte_offset_map(pmd, address);
if (!sync && !pte_present(*pte)) {
pte_unmap(pte);
return NULL;
}
ptl = pte_lockptr(mm, pmd);
check:
spin_lock(ptl);
if (pte_present(*pte) && page_to_pfn(page) == pte_pfn(*pte)) {
*ptlp = ptl;
return pte;
}
pte_unmap_unlock(pte, ptl);
return NULL;
}
int page_mapped_in_vma(struct page *page, struct vm_area_struct *vma)
{
unsigned long address;
pte_t *pte;
spinlock_t *ptl;
address = __vma_address(page, vma);
if (unlikely(address < vma->vm_start || address >= vma->vm_end))
return 0;
pte = page_check_address(page, vma->vm_mm, address, &ptl, 1);
if (!pte)
return 0;
pte_unmap_unlock(pte, ptl);
return 1;
}
static int page_referenced_one(struct page *page, struct vm_area_struct *vma,
unsigned long address, void *arg)
{
struct mm_struct *mm = vma->vm_mm;
spinlock_t *ptl;
int referenced = 0;
struct page_referenced_arg *pra = arg;
if (unlikely(PageTransHuge(page))) {
pmd_t *pmd;
pmd = page_check_address_pmd(page, mm, address,
PAGE_CHECK_ADDRESS_PMD_FLAG, &ptl);
if (!pmd)
return SWAP_AGAIN;
if (vma->vm_flags & VM_LOCKED) {
spin_unlock(ptl);
pra->vm_flags |= VM_LOCKED;
return SWAP_FAIL;
}
if (pmdp_clear_flush_young_notify(vma, address, pmd))
referenced++;
spin_unlock(ptl);
} else {
pte_t *pte;
pte = page_check_address(page, mm, address, &ptl, 0);
if (!pte)
return SWAP_AGAIN;
if (vma->vm_flags & VM_LOCKED) {
pte_unmap_unlock(pte, ptl);
pra->vm_flags |= VM_LOCKED;
return SWAP_FAIL;
}
if (ptep_clear_flush_young_notify(vma, address, pte)) {
if (likely(!(vma->vm_flags & VM_SEQ_READ)))
referenced++;
}
pte_unmap_unlock(pte, ptl);
}
if (referenced) {
pra->referenced++;
pra->vm_flags |= vma->vm_flags;
}
pra->mapcount--;
if (!pra->mapcount)
return SWAP_SUCCESS;
return SWAP_AGAIN;
}
static bool invalid_page_referenced_vma(struct vm_area_struct *vma, void *arg)
{
struct page_referenced_arg *pra = arg;
struct mem_cgroup *memcg = pra->memcg;
if (!mm_match_cgroup(vma->vm_mm, memcg))
return true;
return false;
}
int page_referenced(struct page *page,
int is_locked,
struct mem_cgroup *memcg,
unsigned long *vm_flags)
{
int ret;
int we_locked = 0;
struct page_referenced_arg pra = {
.mapcount = page_mapcount(page),
.memcg = memcg,
};
struct rmap_walk_control rwc = {
.rmap_one = page_referenced_one,
.arg = (void *)&pra,
.anon_lock = page_lock_anon_vma_read,
};
*vm_flags = 0;
if (!page_mapped(page))
return 0;
if (!page_rmapping(page))
return 0;
if (!is_locked && (!PageAnon(page) || PageKsm(page))) {
we_locked = trylock_page(page);
if (!we_locked)
return 1;
}
if (memcg) {
rwc.invalid_vma = invalid_page_referenced_vma;
}
ret = rmap_walk(page, &rwc);
*vm_flags = pra.vm_flags;
if (we_locked)
unlock_page(page);
return pra.referenced;
}
static int page_mkclean_one(struct page *page, struct vm_area_struct *vma,
unsigned long address, void *arg)
{
struct mm_struct *mm = vma->vm_mm;
pte_t *pte;
spinlock_t *ptl;
int ret = 0;
int *cleaned = arg;
pte = page_check_address(page, mm, address, &ptl, 1);
if (!pte)
goto out;
if (pte_dirty(*pte) || pte_write(*pte)) {
pte_t entry;
flush_cache_page(vma, address, pte_pfn(*pte));
entry = ptep_clear_flush(vma, address, pte);
entry = pte_wrprotect(entry);
entry = pte_mkclean(entry);
set_pte_at(mm, address, pte, entry);
ret = 1;
}
pte_unmap_unlock(pte, ptl);
if (ret) {
mmu_notifier_invalidate_page(mm, address);
(*cleaned)++;
}
out:
return SWAP_AGAIN;
}
static bool invalid_mkclean_vma(struct vm_area_struct *vma, void *arg)
{
if (vma->vm_flags & VM_SHARED)
return false;
return true;
}
int page_mkclean(struct page *page)
{
int cleaned = 0;
struct address_space *mapping;
struct rmap_walk_control rwc = {
.arg = (void *)&cleaned,
.rmap_one = page_mkclean_one,
.invalid_vma = invalid_mkclean_vma,
};
BUG_ON(!PageLocked(page));
if (!page_mapped(page))
return 0;
mapping = page_mapping(page);
if (!mapping)
return 0;
rmap_walk(page, &rwc);
return cleaned;
}
void page_move_anon_rmap(struct page *page,
struct vm_area_struct *vma, unsigned long address)
{
struct anon_vma *anon_vma = vma->anon_vma;
VM_BUG_ON_PAGE(!PageLocked(page), page);
VM_BUG_ON_VMA(!anon_vma, vma);
VM_BUG_ON_PAGE(page->index != linear_page_index(vma, address), page);
anon_vma = (void *) anon_vma + PAGE_MAPPING_ANON;
page->mapping = (struct address_space *) anon_vma;
}
static void __page_set_anon_rmap(struct page *page,
struct vm_area_struct *vma, unsigned long address, int exclusive)
{
struct anon_vma *anon_vma = vma->anon_vma;
BUG_ON(!anon_vma);
if (PageAnon(page))
return;
if (!exclusive)
anon_vma = anon_vma->root;
anon_vma = (void *) anon_vma + PAGE_MAPPING_ANON;
page->mapping = (struct address_space *) anon_vma;
page->index = linear_page_index(vma, address);
}
static void __page_check_anon_rmap(struct page *page,
struct vm_area_struct *vma, unsigned long address)
{
#ifdef CONFIG_DEBUG_VM
BUG_ON(page_anon_vma(page)->root != vma->anon_vma->root);
BUG_ON(page->index != linear_page_index(vma, address));
#endif
}
void page_add_anon_rmap(struct page *page,
struct vm_area_struct *vma, unsigned long address)
{
do_page_add_anon_rmap(page, vma, address, 0);
}
void do_page_add_anon_rmap(struct page *page,
struct vm_area_struct *vma, unsigned long address, int exclusive)
{
int first = atomic_inc_and_test(&page->_mapcount);
if (first) {
if (PageTransHuge(page))
__inc_zone_page_state(page,
NR_ANON_TRANSPARENT_HUGEPAGES);
__mod_zone_page_state(page_zone(page), NR_ANON_PAGES,
hpage_nr_pages(page));
}
if (unlikely(PageKsm(page)))
return;
VM_BUG_ON_PAGE(!PageLocked(page), page);
if (first)
__page_set_anon_rmap(page, vma, address, exclusive);
else
__page_check_anon_rmap(page, vma, address);
}
void page_add_new_anon_rmap(struct page *page,
struct vm_area_struct *vma, unsigned long address)
{
VM_BUG_ON_VMA(address < vma->vm_start || address >= vma->vm_end, vma);
SetPageSwapBacked(page);
atomic_set(&page->_mapcount, 0);
if (PageTransHuge(page))
__inc_zone_page_state(page, NR_ANON_TRANSPARENT_HUGEPAGES);
__mod_zone_page_state(page_zone(page), NR_ANON_PAGES,
hpage_nr_pages(page));
__page_set_anon_rmap(page, vma, address, 1);
}
void page_add_file_rmap(struct page *page)
{
struct mem_cgroup *memcg;
unsigned long flags;
bool locked;
memcg = mem_cgroup_begin_page_stat(page, &locked, &flags);
if (atomic_inc_and_test(&page->_mapcount)) {
__inc_zone_page_state(page, NR_FILE_MAPPED);
mem_cgroup_inc_page_stat(memcg, MEM_CGROUP_STAT_FILE_MAPPED);
}
mem_cgroup_end_page_stat(memcg, &locked, &flags);
}
static void page_remove_file_rmap(struct page *page)
{
struct mem_cgroup *memcg;
unsigned long flags;
bool locked;
memcg = mem_cgroup_begin_page_stat(page, &locked, &flags);
if (!atomic_add_negative(-1, &page->_mapcount))
goto out;
if (unlikely(PageHuge(page)))
goto out;
__dec_zone_page_state(page, NR_FILE_MAPPED);
mem_cgroup_dec_page_stat(memcg, MEM_CGROUP_STAT_FILE_MAPPED);
if (unlikely(PageMlocked(page)))
clear_page_mlock(page);
out:
mem_cgroup_end_page_stat(memcg, &locked, &flags);
}
void page_remove_rmap(struct page *page)
{
if (!PageAnon(page)) {
page_remove_file_rmap(page);
return;
}
if (!atomic_add_negative(-1, &page->_mapcount))
return;
if (unlikely(PageHuge(page)))
return;
if (PageTransHuge(page))
__dec_zone_page_state(page, NR_ANON_TRANSPARENT_HUGEPAGES);
__mod_zone_page_state(page_zone(page), NR_ANON_PAGES,
-hpage_nr_pages(page));
if (unlikely(PageMlocked(page)))
clear_page_mlock(page);
}
static int try_to_unmap_one(struct page *page, struct vm_area_struct *vma,
unsigned long address, void *arg)
{
struct mm_struct *mm = vma->vm_mm;
pte_t *pte;
pte_t pteval;
spinlock_t *ptl;
int ret = SWAP_AGAIN;
enum ttu_flags flags = (enum ttu_flags)arg;
pte = page_check_address(page, mm, address, &ptl, 0);
if (!pte)
goto out;
if (!(flags & TTU_IGNORE_MLOCK)) {
if (vma->vm_flags & VM_LOCKED)
goto out_mlock;
if (flags & TTU_MUNLOCK)
goto out_unmap;
}
if (!(flags & TTU_IGNORE_ACCESS)) {
if (ptep_clear_flush_young_notify(vma, address, pte)) {
ret = SWAP_FAIL;
goto out_unmap;
}
}
flush_cache_page(vma, address, page_to_pfn(page));
pteval = ptep_clear_flush(vma, address, pte);
if (pte_dirty(pteval))
set_page_dirty(page);
update_hiwater_rss(mm);
if (PageHWPoison(page) && !(flags & TTU_IGNORE_HWPOISON)) {
if (!PageHuge(page)) {
if (PageAnon(page))
dec_mm_counter(mm, MM_ANONPAGES);
else
dec_mm_counter(mm, MM_FILEPAGES);
}
set_pte_at(mm, address, pte,
swp_entry_to_pte(make_hwpoison_entry(page)));
} else if (pte_unused(pteval)) {
if (PageAnon(page))
dec_mm_counter(mm, MM_ANONPAGES);
else
dec_mm_counter(mm, MM_FILEPAGES);
} else if (PageAnon(page)) {
swp_entry_t entry = { .val = page_private(page) };
pte_t swp_pte;
if (PageSwapCache(page)) {
if (swap_duplicate(entry) < 0) {
set_pte_at(mm, address, pte, pteval);
ret = SWAP_FAIL;
goto out_unmap;
}
if (list_empty(&mm->mmlist)) {
spin_lock(&mmlist_lock);
if (list_empty(&mm->mmlist))
list_add(&mm->mmlist, &init_mm.mmlist);
spin_unlock(&mmlist_lock);
}
dec_mm_counter(mm, MM_ANONPAGES);
inc_mm_counter(mm, MM_SWAPENTS);
} else if (IS_ENABLED(CONFIG_MIGRATION)) {
BUG_ON(!(flags & TTU_MIGRATION));
entry = make_migration_entry(page, pte_write(pteval));
}
swp_pte = swp_entry_to_pte(entry);
if (pte_soft_dirty(pteval))
swp_pte = pte_swp_mksoft_dirty(swp_pte);
set_pte_at(mm, address, pte, swp_pte);
BUG_ON(pte_file(*pte));
} else if (IS_ENABLED(CONFIG_MIGRATION) &&
(flags & TTU_MIGRATION)) {
swp_entry_t entry;
entry = make_migration_entry(page, pte_write(pteval));
set_pte_at(mm, address, pte, swp_entry_to_pte(entry));
} else
dec_mm_counter(mm, MM_FILEPAGES);
page_remove_rmap(page);
page_cache_release(page);
out_unmap:
pte_unmap_unlock(pte, ptl);
if (ret != SWAP_FAIL && !(flags & TTU_MUNLOCK))
mmu_notifier_invalidate_page(mm, address);
out:
return ret;
out_mlock:
pte_unmap_unlock(pte, ptl);
if (down_read_trylock(&vma->vm_mm->mmap_sem)) {
if (vma->vm_flags & VM_LOCKED) {
mlock_vma_page(page);
ret = SWAP_MLOCK;
}
up_read(&vma->vm_mm->mmap_sem);
}
return ret;
}
static int try_to_unmap_cluster(unsigned long cursor, unsigned int *mapcount,
struct vm_area_struct *vma, struct page *check_page)
{
struct mm_struct *mm = vma->vm_mm;
pmd_t *pmd;
pte_t *pte;
pte_t pteval;
spinlock_t *ptl;
struct page *page;
unsigned long address;
unsigned long mmun_start;
unsigned long mmun_end;
unsigned long end;
int ret = SWAP_AGAIN;
int locked_vma = 0;
address = (vma->vm_start + cursor) & CLUSTER_MASK;
end = address + CLUSTER_SIZE;
if (address < vma->vm_start)
address = vma->vm_start;
if (end > vma->vm_end)
end = vma->vm_end;
pmd = mm_find_pmd(mm, address);
if (!pmd)
return ret;
mmun_start = address;
mmun_end = end;
mmu_notifier_invalidate_range_start(mm, mmun_start, mmun_end);
if (down_read_trylock(&vma->vm_mm->mmap_sem)) {
locked_vma = (vma->vm_flags & VM_LOCKED);
if (!locked_vma)
up_read(&vma->vm_mm->mmap_sem);
}
pte = pte_offset_map_lock(mm, pmd, address, &ptl);
update_hiwater_rss(mm);
for (; address < end; pte++, address += PAGE_SIZE) {
if (!pte_present(*pte))
continue;
page = vm_normal_page(vma, address, *pte);
BUG_ON(!page || PageAnon(page));
if (locked_vma) {
if (page == check_page) {
mlock_vma_page(page);
ret = SWAP_MLOCK;
} else if (trylock_page(page)) {
mlock_vma_page(page);
unlock_page(page);
}
continue;
}
if (ptep_clear_flush_young(vma, address, pte))
continue;
flush_cache_page(vma, address, pte_pfn(*pte));
pteval = ptep_clear_flush_notify(vma, address, pte);
if (page->index != linear_page_index(vma, address)) {
pte_t ptfile = pgoff_to_pte(page->index);
if (pte_soft_dirty(pteval))
ptfile = pte_file_mksoft_dirty(ptfile);
set_pte_at(mm, address, pte, ptfile);
}
if (pte_dirty(pteval))
set_page_dirty(page);
page_remove_rmap(page);
page_cache_release(page);
dec_mm_counter(mm, MM_FILEPAGES);
(*mapcount)--;
}
pte_unmap_unlock(pte - 1, ptl);
mmu_notifier_invalidate_range_end(mm, mmun_start, mmun_end);
if (locked_vma)
up_read(&vma->vm_mm->mmap_sem);
return ret;
}
static int try_to_unmap_nonlinear(struct page *page,
struct address_space *mapping, void *arg)
{
struct vm_area_struct *vma;
int ret = SWAP_AGAIN;
unsigned long cursor;
unsigned long max_nl_cursor = 0;
unsigned long max_nl_size = 0;
unsigned int mapcount;
list_for_each_entry(vma,
&mapping->i_mmap_nonlinear, shared.nonlinear) {
cursor = (unsigned long) vma->vm_private_data;
if (cursor > max_nl_cursor)
max_nl_cursor = cursor;
cursor = vma->vm_end - vma->vm_start;
if (cursor > max_nl_size)
max_nl_size = cursor;
}
if (max_nl_size == 0) {
return SWAP_FAIL;
}
mapcount = page_mapcount(page);
if (!mapcount)
return ret;
cond_resched();
max_nl_size = (max_nl_size + CLUSTER_SIZE - 1) & CLUSTER_MASK;
if (max_nl_cursor == 0)
max_nl_cursor = CLUSTER_SIZE;
do {
list_for_each_entry(vma,
&mapping->i_mmap_nonlinear, shared.nonlinear) {
cursor = (unsigned long) vma->vm_private_data;
while (cursor < max_nl_cursor &&
cursor < vma->vm_end - vma->vm_start) {
if (try_to_unmap_cluster(cursor, &mapcount,
vma, page) == SWAP_MLOCK)
ret = SWAP_MLOCK;
cursor += CLUSTER_SIZE;
vma->vm_private_data = (void *) cursor;
if ((int)mapcount <= 0)
return ret;
}
vma->vm_private_data = (void *) max_nl_cursor;
}
cond_resched();
max_nl_cursor += CLUSTER_SIZE;
} while (max_nl_cursor <= max_nl_size);
list_for_each_entry(vma, &mapping->i_mmap_nonlinear, shared.nonlinear)
vma->vm_private_data = NULL;
return ret;
}
bool is_vma_temporary_stack(struct vm_area_struct *vma)
{
int maybe_stack = vma->vm_flags & (VM_GROWSDOWN | VM_GROWSUP);
if (!maybe_stack)
return false;
if ((vma->vm_flags & VM_STACK_INCOMPLETE_SETUP) ==
VM_STACK_INCOMPLETE_SETUP)
return true;
return false;
}
static bool invalid_migration_vma(struct vm_area_struct *vma, void *arg)
{
return is_vma_temporary_stack(vma);
}
static int page_not_mapped(struct page *page)
{
return !page_mapped(page);
}
int try_to_unmap(struct page *page, enum ttu_flags flags)
{
int ret;
struct rmap_walk_control rwc = {
.rmap_one = try_to_unmap_one,
.arg = (void *)flags,
.done = page_not_mapped,
.file_nonlinear = try_to_unmap_nonlinear,
.anon_lock = page_lock_anon_vma_read,
};
VM_BUG_ON_PAGE(!PageHuge(page) && PageTransHuge(page), page);
if ((flags & TTU_MIGRATION) && !PageKsm(page) && PageAnon(page))
rwc.invalid_vma = invalid_migration_vma;
ret = rmap_walk(page, &rwc);
if (ret != SWAP_MLOCK && !page_mapped(page))
ret = SWAP_SUCCESS;
return ret;
}
int try_to_munlock(struct page *page)
{
int ret;
struct rmap_walk_control rwc = {
.rmap_one = try_to_unmap_one,
.arg = (void *)TTU_MUNLOCK,
.done = page_not_mapped,
.file_nonlinear = NULL,
.anon_lock = page_lock_anon_vma_read,
};
VM_BUG_ON_PAGE(!PageLocked(page) || PageLRU(page), page);
ret = rmap_walk(page, &rwc);
return ret;
}
void __put_anon_vma(struct anon_vma *anon_vma)
{
struct anon_vma *root = anon_vma->root;
anon_vma_free(anon_vma);
if (root != anon_vma && atomic_dec_and_test(&root->refcount))
anon_vma_free(root);
}
static struct anon_vma *rmap_walk_anon_lock(struct page *page,
struct rmap_walk_control *rwc)
{
struct anon_vma *anon_vma;
if (rwc->anon_lock)
return rwc->anon_lock(page);
anon_vma = page_anon_vma(page);
if (!anon_vma)
return NULL;
anon_vma_lock_read(anon_vma);
return anon_vma;
}
static int rmap_walk_anon(struct page *page, struct rmap_walk_control *rwc)
{
struct anon_vma *anon_vma;
pgoff_t pgoff;
struct anon_vma_chain *avc;
int ret = SWAP_AGAIN;
anon_vma = rmap_walk_anon_lock(page, rwc);
if (!anon_vma)
return ret;
pgoff = page_to_pgoff(page);
anon_vma_interval_tree_foreach(avc, &anon_vma->rb_root, pgoff, pgoff) {
struct vm_area_struct *vma = avc->vma;
unsigned long address = vma_address(page, vma);
if (rwc->invalid_vma && rwc->invalid_vma(vma, rwc->arg))
continue;
ret = rwc->rmap_one(page, vma, address, rwc->arg);
if (ret != SWAP_AGAIN)
break;
if (rwc->done && rwc->done(page))
break;
}
anon_vma_unlock_read(anon_vma);
return ret;
}
static int rmap_walk_file(struct page *page, struct rmap_walk_control *rwc)
{
struct address_space *mapping = page->mapping;
pgoff_t pgoff;
struct vm_area_struct *vma;
int ret = SWAP_AGAIN;
VM_BUG_ON_PAGE(!PageLocked(page), page);
if (!mapping)
return ret;
pgoff = page_to_pgoff(page);
i_mmap_lock_read(mapping);
vma_interval_tree_foreach(vma, &mapping->i_mmap, pgoff, pgoff) {
unsigned long address = vma_address(page, vma);
if (rwc->invalid_vma && rwc->invalid_vma(vma, rwc->arg))
continue;
ret = rwc->rmap_one(page, vma, address, rwc->arg);
if (ret != SWAP_AGAIN)
goto done;
if (rwc->done && rwc->done(page))
goto done;
}
if (!rwc->file_nonlinear)
goto done;
if (list_empty(&mapping->i_mmap_nonlinear))
goto done;
ret = rwc->file_nonlinear(page, mapping, rwc->arg);
done:
i_mmap_unlock_read(mapping);
return ret;
}
int rmap_walk(struct page *page, struct rmap_walk_control *rwc)
{
if (unlikely(PageKsm(page)))
return rmap_walk_ksm(page, rwc);
else if (PageAnon(page))
return rmap_walk_anon(page, rwc);
else
return rmap_walk_file(page, rwc);
}
static void __hugepage_set_anon_rmap(struct page *page,
struct vm_area_struct *vma, unsigned long address, int exclusive)
{
struct anon_vma *anon_vma = vma->anon_vma;
BUG_ON(!anon_vma);
if (PageAnon(page))
return;
if (!exclusive)
anon_vma = anon_vma->root;
anon_vma = (void *) anon_vma + PAGE_MAPPING_ANON;
page->mapping = (struct address_space *) anon_vma;
page->index = linear_page_index(vma, address);
}
void hugepage_add_anon_rmap(struct page *page,
struct vm_area_struct *vma, unsigned long address)
{
struct anon_vma *anon_vma = vma->anon_vma;
int first;
BUG_ON(!PageLocked(page));
BUG_ON(!anon_vma);
first = atomic_inc_and_test(&page->_mapcount);
if (first)
__hugepage_set_anon_rmap(page, vma, address, 0);
}
void hugepage_add_new_anon_rmap(struct page *page,
struct vm_area_struct *vma, unsigned long address)
{
BUG_ON(address < vma->vm_start || address >= vma->vm_end);
atomic_set(&page->_mapcount, 0);
__hugepage_set_anon_rmap(page, vma, address, 1);
}
