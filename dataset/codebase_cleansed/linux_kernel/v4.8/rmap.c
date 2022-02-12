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
dst->anon_vma = NULL;
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
VM_WARN_ON(anon_vma->degree);
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
0, SLAB_DESTROY_BY_RCU|SLAB_PANIC|SLAB_ACCOUNT,
anon_vma_ctor);
anon_vma_chain_cachep = KMEM_CACHE(anon_vma_chain,
SLAB_PANIC|SLAB_ACCOUNT);
}
struct anon_vma *page_get_anon_vma(struct page *page)
{
struct anon_vma *anon_vma = NULL;
unsigned long anon_mapping;
rcu_read_lock();
anon_mapping = (unsigned long)READ_ONCE(page->mapping);
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
anon_mapping = (unsigned long)READ_ONCE(page->mapping);
if ((anon_mapping & PAGE_MAPPING_FLAGS) != PAGE_MAPPING_ANON)
goto out;
if (!page_mapped(page))
goto out;
anon_vma = (struct anon_vma *) (anon_mapping - PAGE_MAPPING_ANON);
root_anon_vma = READ_ONCE(anon_vma->root);
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
void try_to_unmap_flush(void)
{
struct tlbflush_unmap_batch *tlb_ubc = &current->tlb_ubc;
int cpu;
if (!tlb_ubc->flush_required)
return;
cpu = get_cpu();
if (cpumask_test_cpu(cpu, &tlb_ubc->cpumask)) {
count_vm_tlb_event(NR_TLB_LOCAL_FLUSH_ALL);
local_flush_tlb();
trace_tlb_flush(TLB_LOCAL_SHOOTDOWN, TLB_FLUSH_ALL);
}
if (cpumask_any_but(&tlb_ubc->cpumask, cpu) < nr_cpu_ids)
flush_tlb_others(&tlb_ubc->cpumask, NULL, 0, TLB_FLUSH_ALL);
cpumask_clear(&tlb_ubc->cpumask);
tlb_ubc->flush_required = false;
tlb_ubc->writable = false;
put_cpu();
}
void try_to_unmap_flush_dirty(void)
{
struct tlbflush_unmap_batch *tlb_ubc = &current->tlb_ubc;
if (tlb_ubc->writable)
try_to_unmap_flush();
}
static void set_tlb_ubc_flush_pending(struct mm_struct *mm,
struct page *page, bool writable)
{
struct tlbflush_unmap_batch *tlb_ubc = &current->tlb_ubc;
cpumask_or(&tlb_ubc->cpumask, &tlb_ubc->cpumask, mm_cpumask(mm));
tlb_ubc->flush_required = true;
if (writable)
tlb_ubc->writable = true;
}
static bool should_defer_flush(struct mm_struct *mm, enum ttu_flags flags)
{
bool should_defer = false;
if (!(flags & TTU_BATCH_FLUSH))
return false;
if (cpumask_any_but(mm_cpumask(mm), get_cpu()) < nr_cpu_ids)
should_defer = true;
put_cpu();
return should_defer;
}
static void set_tlb_ubc_flush_pending(struct mm_struct *mm,
struct page *page, bool writable)
{
}
static bool should_defer_flush(struct mm_struct *mm, enum ttu_flags flags)
{
return false;
}
unsigned long page_address_in_vma(struct page *page, struct vm_area_struct *vma)
{
unsigned long address;
if (PageAnon(page)) {
struct anon_vma *page__anon_vma = page_anon_vma(page);
if (!vma->anon_vma || !page__anon_vma ||
vma->anon_vma->root != page__anon_vma->root)
return -EFAULT;
} else if (page->mapping) {
if (!vma->vm_file || vma->vm_file->f_mapping != page->mapping)
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
bool page_check_address_transhuge(struct page *page, struct mm_struct *mm,
unsigned long address, pmd_t **pmdp,
pte_t **ptep, spinlock_t **ptlp)
{
pgd_t *pgd;
pud_t *pud;
pmd_t *pmd;
pte_t *pte;
spinlock_t *ptl;
if (unlikely(PageHuge(page))) {
pte = huge_pte_offset(mm, address);
if (!pte)
return false;
ptl = huge_pte_lockptr(page_hstate(page), mm, pte);
pmd = NULL;
goto check_pte;
}
pgd = pgd_offset(mm, address);
if (!pgd_present(*pgd))
return false;
pud = pud_offset(pgd, address);
if (!pud_present(*pud))
return false;
pmd = pmd_offset(pud, address);
if (pmd_trans_huge(*pmd)) {
ptl = pmd_lock(mm, pmd);
if (!pmd_present(*pmd))
goto unlock_pmd;
if (unlikely(!pmd_trans_huge(*pmd))) {
spin_unlock(ptl);
goto map_pte;
}
if (pmd_page(*pmd) != page)
goto unlock_pmd;
pte = NULL;
goto found;
unlock_pmd:
spin_unlock(ptl);
return false;
} else {
pmd_t pmde = *pmd;
barrier();
if (!pmd_present(pmde) || pmd_trans_huge(pmde))
return false;
}
map_pte:
pte = pte_offset_map(pmd, address);
if (!pte_present(*pte)) {
pte_unmap(pte);
return false;
}
ptl = pte_lockptr(mm, pmd);
check_pte:
spin_lock(ptl);
if (!pte_present(*pte)) {
pte_unmap_unlock(pte, ptl);
return false;
}
if (pte_pfn(*pte) - page_to_pfn(page) >= hpage_nr_pages(page)) {
pte_unmap_unlock(pte, ptl);
return false;
}
found:
*ptep = pte;
*pmdp = pmd;
*ptlp = ptl;
return true;
}
static int page_referenced_one(struct page *page, struct vm_area_struct *vma,
unsigned long address, void *arg)
{
struct mm_struct *mm = vma->vm_mm;
struct page_referenced_arg *pra = arg;
pmd_t *pmd;
pte_t *pte;
spinlock_t *ptl;
int referenced = 0;
if (!page_check_address_transhuge(page, mm, address, &pmd, &pte, &ptl))
return SWAP_AGAIN;
if (vma->vm_flags & VM_LOCKED) {
if (pte)
pte_unmap(pte);
spin_unlock(ptl);
pra->vm_flags |= VM_LOCKED;
return SWAP_FAIL;
}
if (pte) {
if (ptep_clear_flush_young_notify(vma, address, pte)) {
if (likely(!(vma->vm_flags & VM_SEQ_READ)))
referenced++;
}
pte_unmap(pte);
} else if (IS_ENABLED(CONFIG_TRANSPARENT_HUGEPAGE)) {
if (pmdp_clear_flush_young_notify(vma, address, pmd))
referenced++;
} else {
WARN_ON_ONCE(1);
}
spin_unlock(ptl);
if (referenced)
clear_page_idle(page);
if (test_and_clear_page_young(page))
referenced++;
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
.mapcount = total_mapcount(page),
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
void page_move_anon_rmap(struct page *page, struct vm_area_struct *vma)
{
struct anon_vma *anon_vma = vma->anon_vma;
page = compound_head(page);
VM_BUG_ON_PAGE(!PageLocked(page), page);
VM_BUG_ON_VMA(!anon_vma, vma);
anon_vma = (void *) anon_vma + PAGE_MAPPING_ANON;
WRITE_ONCE(page->mapping, (struct address_space *) anon_vma);
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
BUG_ON(page_to_pgoff(page) != linear_page_index(vma, address));
#endif
}
void page_add_anon_rmap(struct page *page,
struct vm_area_struct *vma, unsigned long address, bool compound)
{
do_page_add_anon_rmap(page, vma, address, compound ? RMAP_COMPOUND : 0);
}
void do_page_add_anon_rmap(struct page *page,
struct vm_area_struct *vma, unsigned long address, int flags)
{
bool compound = flags & RMAP_COMPOUND;
bool first;
if (compound) {
atomic_t *mapcount;
VM_BUG_ON_PAGE(!PageLocked(page), page);
VM_BUG_ON_PAGE(!PageTransHuge(page), page);
mapcount = compound_mapcount_ptr(page);
first = atomic_inc_and_test(mapcount);
} else {
first = atomic_inc_and_test(&page->_mapcount);
}
if (first) {
int nr = compound ? hpage_nr_pages(page) : 1;
if (compound)
__inc_node_page_state(page, NR_ANON_THPS);
__mod_node_page_state(page_pgdat(page), NR_ANON_MAPPED, nr);
}
if (unlikely(PageKsm(page)))
return;
VM_BUG_ON_PAGE(!PageLocked(page), page);
if (first)
__page_set_anon_rmap(page, vma, address,
flags & RMAP_EXCLUSIVE);
else
__page_check_anon_rmap(page, vma, address);
}
void page_add_new_anon_rmap(struct page *page,
struct vm_area_struct *vma, unsigned long address, bool compound)
{
int nr = compound ? hpage_nr_pages(page) : 1;
VM_BUG_ON_VMA(address < vma->vm_start || address >= vma->vm_end, vma);
__SetPageSwapBacked(page);
if (compound) {
VM_BUG_ON_PAGE(!PageTransHuge(page), page);
atomic_set(compound_mapcount_ptr(page), 0);
__inc_node_page_state(page, NR_ANON_THPS);
} else {
VM_BUG_ON_PAGE(PageTransCompound(page), page);
atomic_set(&page->_mapcount, 0);
}
__mod_node_page_state(page_pgdat(page), NR_ANON_MAPPED, nr);
__page_set_anon_rmap(page, vma, address, 1);
}
void page_add_file_rmap(struct page *page, bool compound)
{
int i, nr = 1;
VM_BUG_ON_PAGE(compound && !PageTransHuge(page), page);
lock_page_memcg(page);
if (compound && PageTransHuge(page)) {
for (i = 0, nr = 0; i < HPAGE_PMD_NR; i++) {
if (atomic_inc_and_test(&page[i]._mapcount))
nr++;
}
if (!atomic_inc_and_test(compound_mapcount_ptr(page)))
goto out;
VM_BUG_ON_PAGE(!PageSwapBacked(page), page);
__inc_node_page_state(page, NR_SHMEM_PMDMAPPED);
} else {
if (PageTransCompound(page) && page_mapping(page)) {
VM_WARN_ON_ONCE(!PageLocked(page));
SetPageDoubleMap(compound_head(page));
if (PageMlocked(page))
clear_page_mlock(compound_head(page));
}
if (!atomic_inc_and_test(&page->_mapcount))
goto out;
}
__mod_node_page_state(page_pgdat(page), NR_FILE_MAPPED, nr);
mem_cgroup_inc_page_stat(page, MEM_CGROUP_STAT_FILE_MAPPED);
out:
unlock_page_memcg(page);
}
static void page_remove_file_rmap(struct page *page, bool compound)
{
int i, nr = 1;
VM_BUG_ON_PAGE(compound && !PageHead(page), page);
lock_page_memcg(page);
if (unlikely(PageHuge(page))) {
atomic_dec(compound_mapcount_ptr(page));
goto out;
}
if (compound && PageTransHuge(page)) {
for (i = 0, nr = 0; i < HPAGE_PMD_NR; i++) {
if (atomic_add_negative(-1, &page[i]._mapcount))
nr++;
}
if (!atomic_add_negative(-1, compound_mapcount_ptr(page)))
goto out;
VM_BUG_ON_PAGE(!PageSwapBacked(page), page);
__dec_node_page_state(page, NR_SHMEM_PMDMAPPED);
} else {
if (!atomic_add_negative(-1, &page->_mapcount))
goto out;
}
__mod_node_page_state(page_pgdat(page), NR_FILE_MAPPED, -nr);
mem_cgroup_dec_page_stat(page, MEM_CGROUP_STAT_FILE_MAPPED);
if (unlikely(PageMlocked(page)))
clear_page_mlock(page);
out:
unlock_page_memcg(page);
}
static void page_remove_anon_compound_rmap(struct page *page)
{
int i, nr;
if (!atomic_add_negative(-1, compound_mapcount_ptr(page)))
return;
if (unlikely(PageHuge(page)))
return;
if (!IS_ENABLED(CONFIG_TRANSPARENT_HUGEPAGE))
return;
__dec_node_page_state(page, NR_ANON_THPS);
if (TestClearPageDoubleMap(page)) {
for (i = 0, nr = 0; i < HPAGE_PMD_NR; i++) {
if (atomic_add_negative(-1, &page[i]._mapcount))
nr++;
}
} else {
nr = HPAGE_PMD_NR;
}
if (unlikely(PageMlocked(page)))
clear_page_mlock(page);
if (nr) {
__mod_node_page_state(page_pgdat(page), NR_ANON_MAPPED, -nr);
deferred_split_huge_page(page);
}
}
void page_remove_rmap(struct page *page, bool compound)
{
if (!PageAnon(page))
return page_remove_file_rmap(page, compound);
if (compound)
return page_remove_anon_compound_rmap(page);
if (!atomic_add_negative(-1, &page->_mapcount))
return;
__dec_node_page_state(page, NR_ANON_MAPPED);
if (unlikely(PageMlocked(page)))
clear_page_mlock(page);
if (PageTransCompound(page))
deferred_split_huge_page(compound_head(page));
}
static int try_to_unmap_one(struct page *page, struct vm_area_struct *vma,
unsigned long address, void *arg)
{
struct mm_struct *mm = vma->vm_mm;
pte_t *pte;
pte_t pteval;
spinlock_t *ptl;
int ret = SWAP_AGAIN;
struct rmap_private *rp = arg;
enum ttu_flags flags = rp->flags;
if ((flags & TTU_MUNLOCK) && !(vma->vm_flags & VM_LOCKED))
goto out;
if (flags & TTU_SPLIT_HUGE_PMD) {
split_huge_pmd_address(vma, address,
flags & TTU_MIGRATION, page);
if (page_mapcount(page) == 0)
goto out;
}
pte = page_check_address(page, mm, address, &ptl,
PageTransCompound(page));
if (!pte)
goto out;
if (!(flags & TTU_IGNORE_MLOCK)) {
if (vma->vm_flags & VM_LOCKED) {
if (!PageTransCompound(page)) {
mlock_vma_page(page);
}
ret = SWAP_MLOCK;
goto out_unmap;
}
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
if (should_defer_flush(mm, flags)) {
pteval = ptep_get_and_clear(mm, address, pte);
set_tlb_ubc_flush_pending(mm, page, pte_dirty(pteval));
} else {
pteval = ptep_clear_flush(vma, address, pte);
}
if (pte_dirty(pteval))
set_page_dirty(page);
update_hiwater_rss(mm);
if (PageHWPoison(page) && !(flags & TTU_IGNORE_HWPOISON)) {
if (PageHuge(page)) {
hugetlb_count_sub(1 << compound_order(page), mm);
} else {
dec_mm_counter(mm, mm_counter(page));
}
set_pte_at(mm, address, pte,
swp_entry_to_pte(make_hwpoison_entry(page)));
} else if (pte_unused(pteval)) {
dec_mm_counter(mm, mm_counter(page));
} else if (IS_ENABLED(CONFIG_MIGRATION) && (flags & TTU_MIGRATION)) {
swp_entry_t entry;
pte_t swp_pte;
entry = make_migration_entry(page, pte_write(pteval));
swp_pte = swp_entry_to_pte(entry);
if (pte_soft_dirty(pteval))
swp_pte = pte_swp_mksoft_dirty(swp_pte);
set_pte_at(mm, address, pte, swp_pte);
} else if (PageAnon(page)) {
swp_entry_t entry = { .val = page_private(page) };
pte_t swp_pte;
VM_BUG_ON_PAGE(!PageSwapCache(page), page);
if (!PageDirty(page) && (flags & TTU_LZFREE)) {
dec_mm_counter(mm, MM_ANONPAGES);
rp->lazyfreed++;
goto discard;
}
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
swp_pte = swp_entry_to_pte(entry);
if (pte_soft_dirty(pteval))
swp_pte = pte_swp_mksoft_dirty(swp_pte);
set_pte_at(mm, address, pte, swp_pte);
} else
dec_mm_counter(mm, mm_counter_file(page));
discard:
page_remove_rmap(page, PageHuge(page));
put_page(page);
out_unmap:
pte_unmap_unlock(pte, ptl);
if (ret != SWAP_FAIL && ret != SWAP_MLOCK && !(flags & TTU_MUNLOCK))
mmu_notifier_invalidate_page(mm, address);
out:
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
static int page_mapcount_is_zero(struct page *page)
{
return !page_mapcount(page);
}
int try_to_unmap(struct page *page, enum ttu_flags flags)
{
int ret;
struct rmap_private rp = {
.flags = flags,
.lazyfreed = 0,
};
struct rmap_walk_control rwc = {
.rmap_one = try_to_unmap_one,
.arg = &rp,
.done = page_mapcount_is_zero,
.anon_lock = page_lock_anon_vma_read,
};
if ((flags & TTU_MIGRATION) && !PageKsm(page) && PageAnon(page))
rwc.invalid_vma = invalid_migration_vma;
if (flags & TTU_RMAP_LOCKED)
ret = rmap_walk_locked(page, &rwc);
else
ret = rmap_walk(page, &rwc);
if (ret != SWAP_MLOCK && !page_mapcount(page)) {
ret = SWAP_SUCCESS;
if (rp.lazyfreed && !PageDirty(page))
ret = SWAP_LZFREE;
}
return ret;
}
static int page_not_mapped(struct page *page)
{
return !page_mapped(page);
}
int try_to_munlock(struct page *page)
{
int ret;
struct rmap_private rp = {
.flags = TTU_MUNLOCK,
.lazyfreed = 0,
};
struct rmap_walk_control rwc = {
.rmap_one = try_to_unmap_one,
.arg = &rp,
.done = page_not_mapped,
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
static int rmap_walk_anon(struct page *page, struct rmap_walk_control *rwc,
bool locked)
{
struct anon_vma *anon_vma;
pgoff_t pgoff;
struct anon_vma_chain *avc;
int ret = SWAP_AGAIN;
if (locked) {
anon_vma = page_anon_vma(page);
VM_BUG_ON_PAGE(!anon_vma, page);
} else {
anon_vma = rmap_walk_anon_lock(page, rwc);
}
if (!anon_vma)
return ret;
pgoff = page_to_pgoff(page);
anon_vma_interval_tree_foreach(avc, &anon_vma->rb_root, pgoff, pgoff) {
struct vm_area_struct *vma = avc->vma;
unsigned long address = vma_address(page, vma);
cond_resched();
if (rwc->invalid_vma && rwc->invalid_vma(vma, rwc->arg))
continue;
ret = rwc->rmap_one(page, vma, address, rwc->arg);
if (ret != SWAP_AGAIN)
break;
if (rwc->done && rwc->done(page))
break;
}
if (!locked)
anon_vma_unlock_read(anon_vma);
return ret;
}
static int rmap_walk_file(struct page *page, struct rmap_walk_control *rwc,
bool locked)
{
struct address_space *mapping = page_mapping(page);
pgoff_t pgoff;
struct vm_area_struct *vma;
int ret = SWAP_AGAIN;
VM_BUG_ON_PAGE(!PageLocked(page), page);
if (!mapping)
return ret;
pgoff = page_to_pgoff(page);
if (!locked)
i_mmap_lock_read(mapping);
vma_interval_tree_foreach(vma, &mapping->i_mmap, pgoff, pgoff) {
unsigned long address = vma_address(page, vma);
cond_resched();
if (rwc->invalid_vma && rwc->invalid_vma(vma, rwc->arg))
continue;
ret = rwc->rmap_one(page, vma, address, rwc->arg);
if (ret != SWAP_AGAIN)
goto done;
if (rwc->done && rwc->done(page))
goto done;
}
done:
if (!locked)
i_mmap_unlock_read(mapping);
return ret;
}
int rmap_walk(struct page *page, struct rmap_walk_control *rwc)
{
if (unlikely(PageKsm(page)))
return rmap_walk_ksm(page, rwc);
else if (PageAnon(page))
return rmap_walk_anon(page, rwc, false);
else
return rmap_walk_file(page, rwc, false);
}
int rmap_walk_locked(struct page *page, struct rmap_walk_control *rwc)
{
VM_BUG_ON_PAGE(PageKsm(page), page);
if (PageAnon(page))
return rmap_walk_anon(page, rwc, true);
else
return rmap_walk_file(page, rwc, true);
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
first = atomic_inc_and_test(compound_mapcount_ptr(page));
if (first)
__hugepage_set_anon_rmap(page, vma, address, 0);
}
void hugepage_add_new_anon_rmap(struct page *page,
struct vm_area_struct *vma, unsigned long address)
{
BUG_ON(address < vma->vm_start || address >= vma->vm_end);
atomic_set(compound_mapcount_ptr(page), 0);
__hugepage_set_anon_rmap(page, vma, address, 1);
}
