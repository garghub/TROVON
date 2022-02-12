static int __init ksm_slab_init(void)
{
rmap_item_cache = KSM_KMEM_CACHE(rmap_item, 0);
if (!rmap_item_cache)
goto out;
stable_node_cache = KSM_KMEM_CACHE(stable_node, 0);
if (!stable_node_cache)
goto out_free1;
mm_slot_cache = KSM_KMEM_CACHE(mm_slot, 0);
if (!mm_slot_cache)
goto out_free2;
return 0;
out_free2:
kmem_cache_destroy(stable_node_cache);
out_free1:
kmem_cache_destroy(rmap_item_cache);
out:
return -ENOMEM;
}
static void __init ksm_slab_free(void)
{
kmem_cache_destroy(mm_slot_cache);
kmem_cache_destroy(stable_node_cache);
kmem_cache_destroy(rmap_item_cache);
mm_slot_cache = NULL;
}
static __always_inline bool is_stable_node_chain(struct stable_node *chain)
{
return chain->rmap_hlist_len == STABLE_NODE_CHAIN;
}
static __always_inline bool is_stable_node_dup(struct stable_node *dup)
{
return dup->head == STABLE_NODE_DUP_HEAD;
}
static inline void stable_node_chain_add_dup(struct stable_node *dup,
struct stable_node *chain)
{
VM_BUG_ON(is_stable_node_dup(dup));
dup->head = STABLE_NODE_DUP_HEAD;
VM_BUG_ON(!is_stable_node_chain(chain));
hlist_add_head(&dup->hlist_dup, &chain->hlist);
ksm_stable_node_dups++;
}
static inline void __stable_node_dup_del(struct stable_node *dup)
{
VM_BUG_ON(!is_stable_node_dup(dup));
hlist_del(&dup->hlist_dup);
ksm_stable_node_dups--;
}
static inline void stable_node_dup_del(struct stable_node *dup)
{
VM_BUG_ON(is_stable_node_chain(dup));
if (is_stable_node_dup(dup))
__stable_node_dup_del(dup);
else
rb_erase(&dup->node, root_stable_tree + NUMA(dup->nid));
#ifdef CONFIG_DEBUG_VM
dup->head = NULL;
#endif
}
static inline struct rmap_item *alloc_rmap_item(void)
{
struct rmap_item *rmap_item;
rmap_item = kmem_cache_zalloc(rmap_item_cache, GFP_KERNEL |
__GFP_NORETRY | __GFP_NOWARN);
if (rmap_item)
ksm_rmap_items++;
return rmap_item;
}
static inline void free_rmap_item(struct rmap_item *rmap_item)
{
ksm_rmap_items--;
rmap_item->mm = NULL;
kmem_cache_free(rmap_item_cache, rmap_item);
}
static inline struct stable_node *alloc_stable_node(void)
{
return kmem_cache_alloc(stable_node_cache, GFP_KERNEL | __GFP_HIGH);
}
static inline void free_stable_node(struct stable_node *stable_node)
{
VM_BUG_ON(stable_node->rmap_hlist_len &&
!is_stable_node_chain(stable_node));
kmem_cache_free(stable_node_cache, stable_node);
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
struct mm_slot *slot;
hash_for_each_possible(mm_slots_hash, slot, link, (unsigned long)mm)
if (slot->mm == mm)
return slot;
return NULL;
}
static void insert_to_mm_slots_hash(struct mm_struct *mm,
struct mm_slot *mm_slot)
{
mm_slot->mm = mm;
hash_add(mm_slots_hash, &mm_slot->link, (unsigned long)mm);
}
static inline bool ksm_test_exit(struct mm_struct *mm)
{
return atomic_read(&mm->mm_users) == 0;
}
static int break_ksm(struct vm_area_struct *vma, unsigned long addr)
{
struct page *page;
int ret = 0;
do {
cond_resched();
page = follow_page(vma, addr,
FOLL_GET | FOLL_MIGRATION | FOLL_REMOTE);
if (IS_ERR_OR_NULL(page))
break;
if (PageKsm(page))
ret = handle_mm_fault(vma, addr,
FAULT_FLAG_WRITE | FAULT_FLAG_REMOTE);
else
ret = VM_FAULT_WRITE;
put_page(page);
} while (!(ret & (VM_FAULT_WRITE | VM_FAULT_SIGBUS | VM_FAULT_SIGSEGV | VM_FAULT_OOM)));
return (ret & VM_FAULT_OOM) ? -ENOMEM : 0;
}
static struct vm_area_struct *find_mergeable_vma(struct mm_struct *mm,
unsigned long addr)
{
struct vm_area_struct *vma;
if (ksm_test_exit(mm))
return NULL;
vma = find_vma(mm, addr);
if (!vma || vma->vm_start > addr)
return NULL;
if (!(vma->vm_flags & VM_MERGEABLE) || !vma->anon_vma)
return NULL;
return vma;
}
static void break_cow(struct rmap_item *rmap_item)
{
struct mm_struct *mm = rmap_item->mm;
unsigned long addr = rmap_item->address;
struct vm_area_struct *vma;
put_anon_vma(rmap_item->anon_vma);
down_read(&mm->mmap_sem);
vma = find_mergeable_vma(mm, addr);
if (vma)
break_ksm(vma, addr);
up_read(&mm->mmap_sem);
}
static struct page *get_mergeable_page(struct rmap_item *rmap_item)
{
struct mm_struct *mm = rmap_item->mm;
unsigned long addr = rmap_item->address;
struct vm_area_struct *vma;
struct page *page;
down_read(&mm->mmap_sem);
vma = find_mergeable_vma(mm, addr);
if (!vma)
goto out;
page = follow_page(vma, addr, FOLL_GET);
if (IS_ERR_OR_NULL(page))
goto out;
if (PageAnon(page)) {
flush_anon_page(vma, page, addr);
flush_dcache_page(page);
} else {
put_page(page);
out:
page = NULL;
}
up_read(&mm->mmap_sem);
return page;
}
static inline int get_kpfn_nid(unsigned long kpfn)
{
return ksm_merge_across_nodes ? 0 : NUMA(pfn_to_nid(kpfn));
}
static struct stable_node *alloc_stable_node_chain(struct stable_node *dup,
struct rb_root *root)
{
struct stable_node *chain = alloc_stable_node();
VM_BUG_ON(is_stable_node_chain(dup));
if (likely(chain)) {
INIT_HLIST_HEAD(&chain->hlist);
chain->chain_prune_time = jiffies;
chain->rmap_hlist_len = STABLE_NODE_CHAIN;
#if defined (CONFIG_DEBUG_VM) && defined(CONFIG_NUMA)
chain->nid = -1;
#endif
ksm_stable_node_chains++;
rb_replace_node(&dup->node, &chain->node, root);
stable_node_chain_add_dup(dup, chain);
}
return chain;
}
static inline void free_stable_node_chain(struct stable_node *chain,
struct rb_root *root)
{
rb_erase(&chain->node, root);
free_stable_node(chain);
ksm_stable_node_chains--;
}
static void remove_node_from_stable_tree(struct stable_node *stable_node)
{
struct rmap_item *rmap_item;
BUG_ON(stable_node->rmap_hlist_len < 0);
hlist_for_each_entry(rmap_item, &stable_node->hlist, hlist) {
if (rmap_item->hlist.next)
ksm_pages_sharing--;
else
ksm_pages_shared--;
VM_BUG_ON(stable_node->rmap_hlist_len <= 0);
stable_node->rmap_hlist_len--;
put_anon_vma(rmap_item->anon_vma);
rmap_item->address &= PAGE_MASK;
cond_resched();
}
#if GCC_VERSION >= 40903
BUILD_BUG_ON(STABLE_NODE_DUP_HEAD <= &migrate_nodes);
BUILD_BUG_ON(STABLE_NODE_DUP_HEAD >= &migrate_nodes + 1);
#endif
if (stable_node->head == &migrate_nodes)
list_del(&stable_node->list);
else
stable_node_dup_del(stable_node);
free_stable_node(stable_node);
}
static struct page *get_ksm_page(struct stable_node *stable_node, bool lock_it)
{
struct page *page;
void *expected_mapping;
unsigned long kpfn;
expected_mapping = (void *)((unsigned long)stable_node |
PAGE_MAPPING_KSM);
again:
kpfn = READ_ONCE(stable_node->kpfn);
page = pfn_to_page(kpfn);
smp_read_barrier_depends();
if (READ_ONCE(page->mapping) != expected_mapping)
goto stale;
while (!get_page_unless_zero(page)) {
if (!PageSwapCache(page))
goto stale;
cpu_relax();
}
if (READ_ONCE(page->mapping) != expected_mapping) {
put_page(page);
goto stale;
}
if (lock_it) {
lock_page(page);
if (READ_ONCE(page->mapping) != expected_mapping) {
unlock_page(page);
put_page(page);
goto stale;
}
}
return page;
stale:
smp_rmb();
if (READ_ONCE(stable_node->kpfn) != kpfn)
goto again;
remove_node_from_stable_tree(stable_node);
return NULL;
}
static void remove_rmap_item_from_tree(struct rmap_item *rmap_item)
{
if (rmap_item->address & STABLE_FLAG) {
struct stable_node *stable_node;
struct page *page;
stable_node = rmap_item->head;
page = get_ksm_page(stable_node, true);
if (!page)
goto out;
hlist_del(&rmap_item->hlist);
unlock_page(page);
put_page(page);
if (!hlist_empty(&stable_node->hlist))
ksm_pages_sharing--;
else
ksm_pages_shared--;
VM_BUG_ON(stable_node->rmap_hlist_len <= 0);
stable_node->rmap_hlist_len--;
put_anon_vma(rmap_item->anon_vma);
rmap_item->address &= PAGE_MASK;
} else if (rmap_item->address & UNSTABLE_FLAG) {
unsigned char age;
age = (unsigned char)(ksm_scan.seqnr - rmap_item->address);
BUG_ON(age > 1);
if (!age)
rb_erase(&rmap_item->node,
root_unstable_tree + NUMA(rmap_item->nid));
ksm_pages_unshared--;
rmap_item->address &= PAGE_MASK;
}
out:
cond_resched();
}
static void remove_trailing_rmap_items(struct mm_slot *mm_slot,
struct rmap_item **rmap_list)
{
while (*rmap_list) {
struct rmap_item *rmap_item = *rmap_list;
*rmap_list = rmap_item->rmap_list;
remove_rmap_item_from_tree(rmap_item);
free_rmap_item(rmap_item);
}
}
static int unmerge_ksm_pages(struct vm_area_struct *vma,
unsigned long start, unsigned long end)
{
unsigned long addr;
int err = 0;
for (addr = start; addr < end && !err; addr += PAGE_SIZE) {
if (ksm_test_exit(vma->vm_mm))
break;
if (signal_pending(current))
err = -ERESTARTSYS;
else
err = break_ksm(vma, addr);
}
return err;
}
static int remove_stable_node(struct stable_node *stable_node)
{
struct page *page;
int err;
page = get_ksm_page(stable_node, true);
if (!page) {
return 0;
}
if (WARN_ON_ONCE(page_mapped(page))) {
err = -EBUSY;
} else {
set_page_stable_node(page, NULL);
remove_node_from_stable_tree(stable_node);
err = 0;
}
unlock_page(page);
put_page(page);
return err;
}
static int remove_stable_node_chain(struct stable_node *stable_node,
struct rb_root *root)
{
struct stable_node *dup;
struct hlist_node *hlist_safe;
if (!is_stable_node_chain(stable_node)) {
VM_BUG_ON(is_stable_node_dup(stable_node));
if (remove_stable_node(stable_node))
return true;
else
return false;
}
hlist_for_each_entry_safe(dup, hlist_safe,
&stable_node->hlist, hlist_dup) {
VM_BUG_ON(!is_stable_node_dup(dup));
if (remove_stable_node(dup))
return true;
}
BUG_ON(!hlist_empty(&stable_node->hlist));
free_stable_node_chain(stable_node, root);
return false;
}
static int remove_all_stable_nodes(void)
{
struct stable_node *stable_node, *next;
int nid;
int err = 0;
for (nid = 0; nid < ksm_nr_node_ids; nid++) {
while (root_stable_tree[nid].rb_node) {
stable_node = rb_entry(root_stable_tree[nid].rb_node,
struct stable_node, node);
if (remove_stable_node_chain(stable_node,
root_stable_tree + nid)) {
err = -EBUSY;
break;
}
cond_resched();
}
}
list_for_each_entry_safe(stable_node, next, &migrate_nodes, list) {
if (remove_stable_node(stable_node))
err = -EBUSY;
cond_resched();
}
return err;
}
static int unmerge_and_remove_all_rmap_items(void)
{
struct mm_slot *mm_slot;
struct mm_struct *mm;
struct vm_area_struct *vma;
int err = 0;
spin_lock(&ksm_mmlist_lock);
ksm_scan.mm_slot = list_entry(ksm_mm_head.mm_list.next,
struct mm_slot, mm_list);
spin_unlock(&ksm_mmlist_lock);
for (mm_slot = ksm_scan.mm_slot;
mm_slot != &ksm_mm_head; mm_slot = ksm_scan.mm_slot) {
mm = mm_slot->mm;
down_read(&mm->mmap_sem);
for (vma = mm->mmap; vma; vma = vma->vm_next) {
if (ksm_test_exit(mm))
break;
if (!(vma->vm_flags & VM_MERGEABLE) || !vma->anon_vma)
continue;
err = unmerge_ksm_pages(vma,
vma->vm_start, vma->vm_end);
if (err)
goto error;
}
remove_trailing_rmap_items(mm_slot, &mm_slot->rmap_list);
up_read(&mm->mmap_sem);
spin_lock(&ksm_mmlist_lock);
ksm_scan.mm_slot = list_entry(mm_slot->mm_list.next,
struct mm_slot, mm_list);
if (ksm_test_exit(mm)) {
hash_del(&mm_slot->link);
list_del(&mm_slot->mm_list);
spin_unlock(&ksm_mmlist_lock);
free_mm_slot(mm_slot);
clear_bit(MMF_VM_MERGEABLE, &mm->flags);
mmdrop(mm);
} else
spin_unlock(&ksm_mmlist_lock);
}
remove_all_stable_nodes();
ksm_scan.seqnr = 0;
return 0;
error:
up_read(&mm->mmap_sem);
spin_lock(&ksm_mmlist_lock);
ksm_scan.mm_slot = &ksm_mm_head;
spin_unlock(&ksm_mmlist_lock);
return err;
}
static u32 calc_checksum(struct page *page)
{
u32 checksum;
void *addr = kmap_atomic(page);
checksum = jhash2(addr, PAGE_SIZE / 4, 17);
kunmap_atomic(addr);
return checksum;
}
static int memcmp_pages(struct page *page1, struct page *page2)
{
char *addr1, *addr2;
int ret;
addr1 = kmap_atomic(page1);
addr2 = kmap_atomic(page2);
ret = memcmp(addr1, addr2, PAGE_SIZE);
kunmap_atomic(addr2);
kunmap_atomic(addr1);
return ret;
}
static inline int pages_identical(struct page *page1, struct page *page2)
{
return !memcmp_pages(page1, page2);
}
static int write_protect_page(struct vm_area_struct *vma, struct page *page,
pte_t *orig_pte)
{
struct mm_struct *mm = vma->vm_mm;
struct page_vma_mapped_walk pvmw = {
.page = page,
.vma = vma,
};
int swapped;
int err = -EFAULT;
unsigned long mmun_start;
unsigned long mmun_end;
pvmw.address = page_address_in_vma(page, vma);
if (pvmw.address == -EFAULT)
goto out;
BUG_ON(PageTransCompound(page));
mmun_start = pvmw.address;
mmun_end = pvmw.address + PAGE_SIZE;
mmu_notifier_invalidate_range_start(mm, mmun_start, mmun_end);
if (!page_vma_mapped_walk(&pvmw))
goto out_mn;
if (WARN_ONCE(!pvmw.pte, "Unexpected PMD mapping?"))
goto out_unlock;
if (pte_write(*pvmw.pte) || pte_dirty(*pvmw.pte) ||
(pte_protnone(*pvmw.pte) && pte_savedwrite(*pvmw.pte)) ||
mm_tlb_flush_pending(mm)) {
pte_t entry;
swapped = PageSwapCache(page);
flush_cache_page(vma, pvmw.address, page_to_pfn(page));
entry = ptep_clear_flush_notify(vma, pvmw.address, pvmw.pte);
if (page_mapcount(page) + 1 + swapped != page_count(page)) {
set_pte_at(mm, pvmw.address, pvmw.pte, entry);
goto out_unlock;
}
if (pte_dirty(entry))
set_page_dirty(page);
if (pte_protnone(entry))
entry = pte_mkclean(pte_clear_savedwrite(entry));
else
entry = pte_mkclean(pte_wrprotect(entry));
set_pte_at_notify(mm, pvmw.address, pvmw.pte, entry);
}
*orig_pte = *pvmw.pte;
err = 0;
out_unlock:
page_vma_mapped_walk_done(&pvmw);
out_mn:
mmu_notifier_invalidate_range_end(mm, mmun_start, mmun_end);
out:
return err;
}
static int replace_page(struct vm_area_struct *vma, struct page *page,
struct page *kpage, pte_t orig_pte)
{
struct mm_struct *mm = vma->vm_mm;
pmd_t *pmd;
pte_t *ptep;
pte_t newpte;
spinlock_t *ptl;
unsigned long addr;
int err = -EFAULT;
unsigned long mmun_start;
unsigned long mmun_end;
addr = page_address_in_vma(page, vma);
if (addr == -EFAULT)
goto out;
pmd = mm_find_pmd(mm, addr);
if (!pmd)
goto out;
mmun_start = addr;
mmun_end = addr + PAGE_SIZE;
mmu_notifier_invalidate_range_start(mm, mmun_start, mmun_end);
ptep = pte_offset_map_lock(mm, pmd, addr, &ptl);
if (!pte_same(*ptep, orig_pte)) {
pte_unmap_unlock(ptep, ptl);
goto out_mn;
}
if (!is_zero_pfn(page_to_pfn(kpage))) {
get_page(kpage);
page_add_anon_rmap(kpage, vma, addr, false);
newpte = mk_pte(kpage, vma->vm_page_prot);
} else {
newpte = pte_mkspecial(pfn_pte(page_to_pfn(kpage),
vma->vm_page_prot));
}
flush_cache_page(vma, addr, pte_pfn(*ptep));
ptep_clear_flush_notify(vma, addr, ptep);
set_pte_at_notify(mm, addr, ptep, newpte);
page_remove_rmap(page, false);
if (!page_mapped(page))
try_to_free_swap(page);
put_page(page);
pte_unmap_unlock(ptep, ptl);
err = 0;
out_mn:
mmu_notifier_invalidate_range_end(mm, mmun_start, mmun_end);
out:
return err;
}
static int try_to_merge_one_page(struct vm_area_struct *vma,
struct page *page, struct page *kpage)
{
pte_t orig_pte = __pte(0);
int err = -EFAULT;
if (page == kpage)
return 0;
if (!PageAnon(page))
goto out;
if (!trylock_page(page))
goto out;
if (PageTransCompound(page)) {
if (split_huge_page(page))
goto out_unlock;
}
if (write_protect_page(vma, page, &orig_pte) == 0) {
if (!kpage) {
set_page_stable_node(page, NULL);
mark_page_accessed(page);
if (!PageDirty(page))
SetPageDirty(page);
err = 0;
} else if (pages_identical(page, kpage))
err = replace_page(vma, page, kpage, orig_pte);
}
if ((vma->vm_flags & VM_LOCKED) && kpage && !err) {
munlock_vma_page(page);
if (!PageMlocked(kpage)) {
unlock_page(page);
lock_page(kpage);
mlock_vma_page(kpage);
page = kpage;
}
}
out_unlock:
unlock_page(page);
out:
return err;
}
static int try_to_merge_with_ksm_page(struct rmap_item *rmap_item,
struct page *page, struct page *kpage)
{
struct mm_struct *mm = rmap_item->mm;
struct vm_area_struct *vma;
int err = -EFAULT;
down_read(&mm->mmap_sem);
vma = find_mergeable_vma(mm, rmap_item->address);
if (!vma)
goto out;
err = try_to_merge_one_page(vma, page, kpage);
if (err)
goto out;
remove_rmap_item_from_tree(rmap_item);
rmap_item->anon_vma = vma->anon_vma;
get_anon_vma(vma->anon_vma);
out:
up_read(&mm->mmap_sem);
return err;
}
static struct page *try_to_merge_two_pages(struct rmap_item *rmap_item,
struct page *page,
struct rmap_item *tree_rmap_item,
struct page *tree_page)
{
int err;
err = try_to_merge_with_ksm_page(rmap_item, page, NULL);
if (!err) {
err = try_to_merge_with_ksm_page(tree_rmap_item,
tree_page, page);
if (err)
break_cow(rmap_item);
}
return err ? NULL : page;
}
static __always_inline
bool __is_page_sharing_candidate(struct stable_node *stable_node, int offset)
{
VM_BUG_ON(stable_node->rmap_hlist_len < 0);
return stable_node->rmap_hlist_len &&
stable_node->rmap_hlist_len + offset < ksm_max_page_sharing;
}
static __always_inline
bool is_page_sharing_candidate(struct stable_node *stable_node)
{
return __is_page_sharing_candidate(stable_node, 0);
}
struct page *stable_node_dup(struct stable_node **_stable_node_dup,
struct stable_node **_stable_node,
struct rb_root *root,
bool prune_stale_stable_nodes)
{
struct stable_node *dup, *found = NULL, *stable_node = *_stable_node;
struct hlist_node *hlist_safe;
struct page *_tree_page, *tree_page = NULL;
int nr = 0;
int found_rmap_hlist_len;
if (!prune_stale_stable_nodes ||
time_before(jiffies, stable_node->chain_prune_time +
msecs_to_jiffies(
ksm_stable_node_chains_prune_millisecs)))
prune_stale_stable_nodes = false;
else
stable_node->chain_prune_time = jiffies;
hlist_for_each_entry_safe(dup, hlist_safe,
&stable_node->hlist, hlist_dup) {
cond_resched();
_tree_page = get_ksm_page(dup, false);
if (!_tree_page)
continue;
nr += 1;
if (is_page_sharing_candidate(dup)) {
if (!found ||
dup->rmap_hlist_len > found_rmap_hlist_len) {
if (found)
put_page(tree_page);
found = dup;
found_rmap_hlist_len = found->rmap_hlist_len;
tree_page = _tree_page;
if (!prune_stale_stable_nodes)
break;
continue;
}
}
put_page(_tree_page);
}
if (found) {
if (prune_stale_stable_nodes && nr == 1) {
BUG_ON(stable_node->hlist.first->next);
rb_replace_node(&stable_node->node, &found->node,
root);
free_stable_node(stable_node);
ksm_stable_node_chains--;
ksm_stable_node_dups--;
*_stable_node = found;
stable_node = NULL;
} else if (stable_node->hlist.first != &found->hlist_dup &&
__is_page_sharing_candidate(found, 1)) {
hlist_del(&found->hlist_dup);
hlist_add_head(&found->hlist_dup,
&stable_node->hlist);
}
}
*_stable_node_dup = found;
return tree_page;
}
static struct stable_node *stable_node_dup_any(struct stable_node *stable_node,
struct rb_root *root)
{
if (!is_stable_node_chain(stable_node))
return stable_node;
if (hlist_empty(&stable_node->hlist)) {
free_stable_node_chain(stable_node, root);
return NULL;
}
return hlist_entry(stable_node->hlist.first,
typeof(*stable_node), hlist_dup);
}
static struct page *__stable_node_chain(struct stable_node **_stable_node_dup,
struct stable_node **_stable_node,
struct rb_root *root,
bool prune_stale_stable_nodes)
{
struct stable_node *stable_node = *_stable_node;
if (!is_stable_node_chain(stable_node)) {
if (is_page_sharing_candidate(stable_node)) {
*_stable_node_dup = stable_node;
return get_ksm_page(stable_node, false);
}
*_stable_node_dup = NULL;
return NULL;
}
return stable_node_dup(_stable_node_dup, _stable_node, root,
prune_stale_stable_nodes);
}
static struct page *stable_tree_search(struct page *page)
{
int nid;
struct rb_root *root;
struct rb_node **new;
struct rb_node *parent;
struct stable_node *stable_node, *stable_node_dup, *stable_node_any;
struct stable_node *page_node;
page_node = page_stable_node(page);
if (page_node && page_node->head != &migrate_nodes) {
get_page(page);
return page;
}
nid = get_kpfn_nid(page_to_pfn(page));
root = root_stable_tree + nid;
again:
new = &root->rb_node;
parent = NULL;
while (*new) {
struct page *tree_page;
int ret;
cond_resched();
stable_node = rb_entry(*new, struct stable_node, node);
stable_node_any = NULL;
tree_page = chain_prune(&stable_node_dup, &stable_node, root);
if (!stable_node_dup) {
stable_node_any = stable_node_dup_any(stable_node,
root);
if (!stable_node_any) {
goto again;
}
tree_page = get_ksm_page(stable_node_any, false);
}
VM_BUG_ON(!stable_node_dup ^ !!stable_node_any);
if (!tree_page) {
goto again;
}
ret = memcmp_pages(page, tree_page);
put_page(tree_page);
parent = *new;
if (ret < 0)
new = &parent->rb_left;
else if (ret > 0)
new = &parent->rb_right;
else {
if (page_node) {
VM_BUG_ON(page_node->head != &migrate_nodes);
if (page_mapcount(page) > 1)
goto chain_append;
}
if (!stable_node_dup) {
return NULL;
}
tree_page = get_ksm_page(stable_node_dup, true);
if (unlikely(!tree_page))
goto again;
unlock_page(tree_page);
if (get_kpfn_nid(stable_node_dup->kpfn) !=
NUMA(stable_node_dup->nid)) {
put_page(tree_page);
goto replace;
}
return tree_page;
}
}
if (!page_node)
return NULL;
list_del(&page_node->list);
DO_NUMA(page_node->nid = nid);
rb_link_node(&page_node->node, parent, new);
rb_insert_color(&page_node->node, root);
out:
if (is_page_sharing_candidate(page_node)) {
get_page(page);
return page;
} else
return NULL;
replace:
if (stable_node_dup == stable_node) {
VM_BUG_ON(is_stable_node_chain(stable_node_dup));
VM_BUG_ON(is_stable_node_dup(stable_node_dup));
if (page_node) {
VM_BUG_ON(page_node->head != &migrate_nodes);
list_del(&page_node->list);
DO_NUMA(page_node->nid = nid);
rb_replace_node(&stable_node_dup->node,
&page_node->node,
root);
if (is_page_sharing_candidate(page_node))
get_page(page);
else
page = NULL;
} else {
rb_erase(&stable_node_dup->node, root);
page = NULL;
}
} else {
VM_BUG_ON(!is_stable_node_chain(stable_node));
__stable_node_dup_del(stable_node_dup);
if (page_node) {
VM_BUG_ON(page_node->head != &migrate_nodes);
list_del(&page_node->list);
DO_NUMA(page_node->nid = nid);
stable_node_chain_add_dup(page_node, stable_node);
if (is_page_sharing_candidate(page_node))
get_page(page);
else
page = NULL;
} else {
page = NULL;
}
}
stable_node_dup->head = &migrate_nodes;
list_add(&stable_node_dup->list, stable_node_dup->head);
return page;
chain_append:
if (!stable_node_dup)
stable_node_dup = stable_node_any;
if (stable_node_dup == stable_node) {
VM_BUG_ON(is_stable_node_chain(stable_node_dup));
VM_BUG_ON(is_stable_node_dup(stable_node_dup));
stable_node = alloc_stable_node_chain(stable_node_dup,
root);
if (!stable_node)
return NULL;
}
VM_BUG_ON(!is_stable_node_chain(stable_node));
VM_BUG_ON(!is_stable_node_dup(stable_node_dup));
VM_BUG_ON(page_node->head != &migrate_nodes);
list_del(&page_node->list);
DO_NUMA(page_node->nid = nid);
stable_node_chain_add_dup(page_node, stable_node);
goto out;
}
static struct stable_node *stable_tree_insert(struct page *kpage)
{
int nid;
unsigned long kpfn;
struct rb_root *root;
struct rb_node **new;
struct rb_node *parent;
struct stable_node *stable_node, *stable_node_dup, *stable_node_any;
bool need_chain = false;
kpfn = page_to_pfn(kpage);
nid = get_kpfn_nid(kpfn);
root = root_stable_tree + nid;
again:
parent = NULL;
new = &root->rb_node;
while (*new) {
struct page *tree_page;
int ret;
cond_resched();
stable_node = rb_entry(*new, struct stable_node, node);
stable_node_any = NULL;
tree_page = chain(&stable_node_dup, stable_node, root);
if (!stable_node_dup) {
stable_node_any = stable_node_dup_any(stable_node,
root);
if (!stable_node_any) {
goto again;
}
tree_page = get_ksm_page(stable_node_any, false);
}
VM_BUG_ON(!stable_node_dup ^ !!stable_node_any);
if (!tree_page) {
goto again;
}
ret = memcmp_pages(kpage, tree_page);
put_page(tree_page);
parent = *new;
if (ret < 0)
new = &parent->rb_left;
else if (ret > 0)
new = &parent->rb_right;
else {
need_chain = true;
break;
}
}
stable_node_dup = alloc_stable_node();
if (!stable_node_dup)
return NULL;
INIT_HLIST_HEAD(&stable_node_dup->hlist);
stable_node_dup->kpfn = kpfn;
set_page_stable_node(kpage, stable_node_dup);
stable_node_dup->rmap_hlist_len = 0;
DO_NUMA(stable_node_dup->nid = nid);
if (!need_chain) {
rb_link_node(&stable_node_dup->node, parent, new);
rb_insert_color(&stable_node_dup->node, root);
} else {
if (!is_stable_node_chain(stable_node)) {
struct stable_node *orig = stable_node;
stable_node = alloc_stable_node_chain(orig, root);
if (!stable_node) {
free_stable_node(stable_node_dup);
return NULL;
}
}
stable_node_chain_add_dup(stable_node_dup, stable_node);
}
return stable_node_dup;
}
static
struct rmap_item *unstable_tree_search_insert(struct rmap_item *rmap_item,
struct page *page,
struct page **tree_pagep)
{
struct rb_node **new;
struct rb_root *root;
struct rb_node *parent = NULL;
int nid;
nid = get_kpfn_nid(page_to_pfn(page));
root = root_unstable_tree + nid;
new = &root->rb_node;
while (*new) {
struct rmap_item *tree_rmap_item;
struct page *tree_page;
int ret;
cond_resched();
tree_rmap_item = rb_entry(*new, struct rmap_item, node);
tree_page = get_mergeable_page(tree_rmap_item);
if (!tree_page)
return NULL;
if (page == tree_page) {
put_page(tree_page);
return NULL;
}
ret = memcmp_pages(page, tree_page);
parent = *new;
if (ret < 0) {
put_page(tree_page);
new = &parent->rb_left;
} else if (ret > 0) {
put_page(tree_page);
new = &parent->rb_right;
} else if (!ksm_merge_across_nodes &&
page_to_nid(tree_page) != nid) {
put_page(tree_page);
return NULL;
} else {
*tree_pagep = tree_page;
return tree_rmap_item;
}
}
rmap_item->address |= UNSTABLE_FLAG;
rmap_item->address |= (ksm_scan.seqnr & SEQNR_MASK);
DO_NUMA(rmap_item->nid = nid);
rb_link_node(&rmap_item->node, parent, new);
rb_insert_color(&rmap_item->node, root);
ksm_pages_unshared++;
return NULL;
}
static void stable_tree_append(struct rmap_item *rmap_item,
struct stable_node *stable_node,
bool max_page_sharing_bypass)
{
BUG_ON(stable_node->rmap_hlist_len < 0);
stable_node->rmap_hlist_len++;
if (!max_page_sharing_bypass)
WARN_ON_ONCE(stable_node->rmap_hlist_len >
ksm_max_page_sharing);
rmap_item->head = stable_node;
rmap_item->address |= STABLE_FLAG;
hlist_add_head(&rmap_item->hlist, &stable_node->hlist);
if (rmap_item->hlist.next)
ksm_pages_sharing++;
else
ksm_pages_shared++;
}
static void cmp_and_merge_page(struct page *page, struct rmap_item *rmap_item)
{
struct mm_struct *mm = rmap_item->mm;
struct rmap_item *tree_rmap_item;
struct page *tree_page = NULL;
struct stable_node *stable_node;
struct page *kpage;
unsigned int checksum;
int err;
bool max_page_sharing_bypass = false;
stable_node = page_stable_node(page);
if (stable_node) {
if (stable_node->head != &migrate_nodes &&
get_kpfn_nid(READ_ONCE(stable_node->kpfn)) !=
NUMA(stable_node->nid)) {
stable_node_dup_del(stable_node);
stable_node->head = &migrate_nodes;
list_add(&stable_node->list, stable_node->head);
}
if (stable_node->head != &migrate_nodes &&
rmap_item->head == stable_node)
return;
if (!is_page_sharing_candidate(stable_node))
max_page_sharing_bypass = true;
}
kpage = stable_tree_search(page);
if (kpage == page && rmap_item->head == stable_node) {
put_page(kpage);
return;
}
remove_rmap_item_from_tree(rmap_item);
if (kpage) {
err = try_to_merge_with_ksm_page(rmap_item, page, kpage);
if (!err) {
lock_page(kpage);
stable_tree_append(rmap_item, page_stable_node(kpage),
max_page_sharing_bypass);
unlock_page(kpage);
}
put_page(kpage);
return;
}
checksum = calc_checksum(page);
if (rmap_item->oldchecksum != checksum) {
rmap_item->oldchecksum = checksum;
return;
}
if (ksm_use_zero_pages && (checksum == zero_checksum)) {
struct vm_area_struct *vma;
down_read(&mm->mmap_sem);
vma = find_mergeable_vma(mm, rmap_item->address);
err = try_to_merge_one_page(vma, page,
ZERO_PAGE(rmap_item->address));
up_read(&mm->mmap_sem);
if (!err)
return;
}
tree_rmap_item =
unstable_tree_search_insert(rmap_item, page, &tree_page);
if (tree_rmap_item) {
kpage = try_to_merge_two_pages(rmap_item, page,
tree_rmap_item, tree_page);
put_page(tree_page);
if (kpage) {
lock_page(kpage);
stable_node = stable_tree_insert(kpage);
if (stable_node) {
stable_tree_append(tree_rmap_item, stable_node,
false);
stable_tree_append(rmap_item, stable_node,
false);
}
unlock_page(kpage);
if (!stable_node) {
break_cow(tree_rmap_item);
break_cow(rmap_item);
}
}
}
}
static struct rmap_item *get_next_rmap_item(struct mm_slot *mm_slot,
struct rmap_item **rmap_list,
unsigned long addr)
{
struct rmap_item *rmap_item;
while (*rmap_list) {
rmap_item = *rmap_list;
if ((rmap_item->address & PAGE_MASK) == addr)
return rmap_item;
if (rmap_item->address > addr)
break;
*rmap_list = rmap_item->rmap_list;
remove_rmap_item_from_tree(rmap_item);
free_rmap_item(rmap_item);
}
rmap_item = alloc_rmap_item();
if (rmap_item) {
rmap_item->mm = mm_slot->mm;
rmap_item->address = addr;
rmap_item->rmap_list = *rmap_list;
*rmap_list = rmap_item;
}
return rmap_item;
}
static struct rmap_item *scan_get_next_rmap_item(struct page **page)
{
struct mm_struct *mm;
struct mm_slot *slot;
struct vm_area_struct *vma;
struct rmap_item *rmap_item;
int nid;
if (list_empty(&ksm_mm_head.mm_list))
return NULL;
slot = ksm_scan.mm_slot;
if (slot == &ksm_mm_head) {
lru_add_drain_all();
if (!ksm_merge_across_nodes) {
struct stable_node *stable_node, *next;
struct page *page;
list_for_each_entry_safe(stable_node, next,
&migrate_nodes, list) {
page = get_ksm_page(stable_node, false);
if (page)
put_page(page);
cond_resched();
}
}
for (nid = 0; nid < ksm_nr_node_ids; nid++)
root_unstable_tree[nid] = RB_ROOT;
spin_lock(&ksm_mmlist_lock);
slot = list_entry(slot->mm_list.next, struct mm_slot, mm_list);
ksm_scan.mm_slot = slot;
spin_unlock(&ksm_mmlist_lock);
if (slot == &ksm_mm_head)
return NULL;
next_mm:
ksm_scan.address = 0;
ksm_scan.rmap_list = &slot->rmap_list;
}
mm = slot->mm;
down_read(&mm->mmap_sem);
if (ksm_test_exit(mm))
vma = NULL;
else
vma = find_vma(mm, ksm_scan.address);
for (; vma; vma = vma->vm_next) {
if (!(vma->vm_flags & VM_MERGEABLE))
continue;
if (ksm_scan.address < vma->vm_start)
ksm_scan.address = vma->vm_start;
if (!vma->anon_vma)
ksm_scan.address = vma->vm_end;
while (ksm_scan.address < vma->vm_end) {
if (ksm_test_exit(mm))
break;
*page = follow_page(vma, ksm_scan.address, FOLL_GET);
if (IS_ERR_OR_NULL(*page)) {
ksm_scan.address += PAGE_SIZE;
cond_resched();
continue;
}
if (PageAnon(*page)) {
flush_anon_page(vma, *page, ksm_scan.address);
flush_dcache_page(*page);
rmap_item = get_next_rmap_item(slot,
ksm_scan.rmap_list, ksm_scan.address);
if (rmap_item) {
ksm_scan.rmap_list =
&rmap_item->rmap_list;
ksm_scan.address += PAGE_SIZE;
} else
put_page(*page);
up_read(&mm->mmap_sem);
return rmap_item;
}
put_page(*page);
ksm_scan.address += PAGE_SIZE;
cond_resched();
}
}
if (ksm_test_exit(mm)) {
ksm_scan.address = 0;
ksm_scan.rmap_list = &slot->rmap_list;
}
remove_trailing_rmap_items(slot, ksm_scan.rmap_list);
spin_lock(&ksm_mmlist_lock);
ksm_scan.mm_slot = list_entry(slot->mm_list.next,
struct mm_slot, mm_list);
if (ksm_scan.address == 0) {
hash_del(&slot->link);
list_del(&slot->mm_list);
spin_unlock(&ksm_mmlist_lock);
free_mm_slot(slot);
clear_bit(MMF_VM_MERGEABLE, &mm->flags);
up_read(&mm->mmap_sem);
mmdrop(mm);
} else {
up_read(&mm->mmap_sem);
spin_unlock(&ksm_mmlist_lock);
}
slot = ksm_scan.mm_slot;
if (slot != &ksm_mm_head)
goto next_mm;
ksm_scan.seqnr++;
return NULL;
}
static void ksm_do_scan(unsigned int scan_npages)
{
struct rmap_item *rmap_item;
struct page *uninitialized_var(page);
while (scan_npages-- && likely(!freezing(current))) {
cond_resched();
rmap_item = scan_get_next_rmap_item(&page);
if (!rmap_item)
return;
cmp_and_merge_page(page, rmap_item);
put_page(page);
}
}
static int ksmd_should_run(void)
{
return (ksm_run & KSM_RUN_MERGE) && !list_empty(&ksm_mm_head.mm_list);
}
static int ksm_scan_thread(void *nothing)
{
set_freezable();
set_user_nice(current, 5);
while (!kthread_should_stop()) {
mutex_lock(&ksm_thread_mutex);
wait_while_offlining();
if (ksmd_should_run())
ksm_do_scan(ksm_thread_pages_to_scan);
mutex_unlock(&ksm_thread_mutex);
try_to_freeze();
if (ksmd_should_run()) {
schedule_timeout_interruptible(
msecs_to_jiffies(ksm_thread_sleep_millisecs));
} else {
wait_event_freezable(ksm_thread_wait,
ksmd_should_run() || kthread_should_stop());
}
}
return 0;
}
int ksm_madvise(struct vm_area_struct *vma, unsigned long start,
unsigned long end, int advice, unsigned long *vm_flags)
{
struct mm_struct *mm = vma->vm_mm;
int err;
switch (advice) {
case MADV_MERGEABLE:
if (*vm_flags & (VM_MERGEABLE | VM_SHARED | VM_MAYSHARE |
VM_PFNMAP | VM_IO | VM_DONTEXPAND |
VM_HUGETLB | VM_MIXEDMAP))
return 0;
#ifdef VM_SAO
if (*vm_flags & VM_SAO)
return 0;
#endif
if (!test_bit(MMF_VM_MERGEABLE, &mm->flags)) {
err = __ksm_enter(mm);
if (err)
return err;
}
*vm_flags |= VM_MERGEABLE;
break;
case MADV_UNMERGEABLE:
if (!(*vm_flags & VM_MERGEABLE))
return 0;
if (vma->anon_vma) {
err = unmerge_ksm_pages(vma, start, end);
if (err)
return err;
}
*vm_flags &= ~VM_MERGEABLE;
break;
}
return 0;
}
int __ksm_enter(struct mm_struct *mm)
{
struct mm_slot *mm_slot;
int needs_wakeup;
mm_slot = alloc_mm_slot();
if (!mm_slot)
return -ENOMEM;
needs_wakeup = list_empty(&ksm_mm_head.mm_list);
spin_lock(&ksm_mmlist_lock);
insert_to_mm_slots_hash(mm, mm_slot);
if (ksm_run & KSM_RUN_UNMERGE)
list_add_tail(&mm_slot->mm_list, &ksm_mm_head.mm_list);
else
list_add_tail(&mm_slot->mm_list, &ksm_scan.mm_slot->mm_list);
spin_unlock(&ksm_mmlist_lock);
set_bit(MMF_VM_MERGEABLE, &mm->flags);
mmgrab(mm);
if (needs_wakeup)
wake_up_interruptible(&ksm_thread_wait);
return 0;
}
void __ksm_exit(struct mm_struct *mm)
{
struct mm_slot *mm_slot;
int easy_to_free = 0;
spin_lock(&ksm_mmlist_lock);
mm_slot = get_mm_slot(mm);
if (mm_slot && ksm_scan.mm_slot != mm_slot) {
if (!mm_slot->rmap_list) {
hash_del(&mm_slot->link);
list_del(&mm_slot->mm_list);
easy_to_free = 1;
} else {
list_move(&mm_slot->mm_list,
&ksm_scan.mm_slot->mm_list);
}
}
spin_unlock(&ksm_mmlist_lock);
if (easy_to_free) {
free_mm_slot(mm_slot);
clear_bit(MMF_VM_MERGEABLE, &mm->flags);
mmdrop(mm);
} else if (mm_slot) {
down_write(&mm->mmap_sem);
up_write(&mm->mmap_sem);
}
}
struct page *ksm_might_need_to_copy(struct page *page,
struct vm_area_struct *vma, unsigned long address)
{
struct anon_vma *anon_vma = page_anon_vma(page);
struct page *new_page;
if (PageKsm(page)) {
if (page_stable_node(page) &&
!(ksm_run & KSM_RUN_UNMERGE))
return page;
} else if (!anon_vma) {
return page;
} else if (anon_vma->root == vma->anon_vma->root &&
page->index == linear_page_index(vma, address)) {
return page;
}
if (!PageUptodate(page))
return page;
new_page = alloc_page_vma(GFP_HIGHUSER_MOVABLE, vma, address);
if (new_page) {
copy_user_highpage(new_page, page, address, vma);
SetPageDirty(new_page);
__SetPageUptodate(new_page);
__SetPageLocked(new_page);
}
return new_page;
}
void rmap_walk_ksm(struct page *page, struct rmap_walk_control *rwc)
{
struct stable_node *stable_node;
struct rmap_item *rmap_item;
int search_new_forks = 0;
VM_BUG_ON_PAGE(!PageKsm(page), page);
VM_BUG_ON_PAGE(!PageLocked(page), page);
stable_node = page_stable_node(page);
if (!stable_node)
return;
again:
hlist_for_each_entry(rmap_item, &stable_node->hlist, hlist) {
struct anon_vma *anon_vma = rmap_item->anon_vma;
struct anon_vma_chain *vmac;
struct vm_area_struct *vma;
cond_resched();
anon_vma_lock_read(anon_vma);
anon_vma_interval_tree_foreach(vmac, &anon_vma->rb_root,
0, ULONG_MAX) {
cond_resched();
vma = vmac->vma;
if (rmap_item->address < vma->vm_start ||
rmap_item->address >= vma->vm_end)
continue;
if ((rmap_item->mm == vma->vm_mm) == search_new_forks)
continue;
if (rwc->invalid_vma && rwc->invalid_vma(vma, rwc->arg))
continue;
if (!rwc->rmap_one(page, vma,
rmap_item->address, rwc->arg)) {
anon_vma_unlock_read(anon_vma);
return;
}
if (rwc->done && rwc->done(page)) {
anon_vma_unlock_read(anon_vma);
return;
}
}
anon_vma_unlock_read(anon_vma);
}
if (!search_new_forks++)
goto again;
}
void ksm_migrate_page(struct page *newpage, struct page *oldpage)
{
struct stable_node *stable_node;
VM_BUG_ON_PAGE(!PageLocked(oldpage), oldpage);
VM_BUG_ON_PAGE(!PageLocked(newpage), newpage);
VM_BUG_ON_PAGE(newpage->mapping != oldpage->mapping, newpage);
stable_node = page_stable_node(newpage);
if (stable_node) {
VM_BUG_ON_PAGE(stable_node->kpfn != page_to_pfn(oldpage), oldpage);
stable_node->kpfn = page_to_pfn(newpage);
smp_wmb();
set_page_stable_node(oldpage, NULL);
}
}
static void wait_while_offlining(void)
{
while (ksm_run & KSM_RUN_OFFLINE) {
mutex_unlock(&ksm_thread_mutex);
wait_on_bit(&ksm_run, ilog2(KSM_RUN_OFFLINE),
TASK_UNINTERRUPTIBLE);
mutex_lock(&ksm_thread_mutex);
}
}
static bool stable_node_dup_remove_range(struct stable_node *stable_node,
unsigned long start_pfn,
unsigned long end_pfn)
{
if (stable_node->kpfn >= start_pfn &&
stable_node->kpfn < end_pfn) {
remove_node_from_stable_tree(stable_node);
return true;
}
return false;
}
static bool stable_node_chain_remove_range(struct stable_node *stable_node,
unsigned long start_pfn,
unsigned long end_pfn,
struct rb_root *root)
{
struct stable_node *dup;
struct hlist_node *hlist_safe;
if (!is_stable_node_chain(stable_node)) {
VM_BUG_ON(is_stable_node_dup(stable_node));
return stable_node_dup_remove_range(stable_node, start_pfn,
end_pfn);
}
hlist_for_each_entry_safe(dup, hlist_safe,
&stable_node->hlist, hlist_dup) {
VM_BUG_ON(!is_stable_node_dup(dup));
stable_node_dup_remove_range(dup, start_pfn, end_pfn);
}
if (hlist_empty(&stable_node->hlist)) {
free_stable_node_chain(stable_node, root);
return true;
} else
return false;
}
static void ksm_check_stable_tree(unsigned long start_pfn,
unsigned long end_pfn)
{
struct stable_node *stable_node, *next;
struct rb_node *node;
int nid;
for (nid = 0; nid < ksm_nr_node_ids; nid++) {
node = rb_first(root_stable_tree + nid);
while (node) {
stable_node = rb_entry(node, struct stable_node, node);
if (stable_node_chain_remove_range(stable_node,
start_pfn, end_pfn,
root_stable_tree +
nid))
node = rb_first(root_stable_tree + nid);
else
node = rb_next(node);
cond_resched();
}
}
list_for_each_entry_safe(stable_node, next, &migrate_nodes, list) {
if (stable_node->kpfn >= start_pfn &&
stable_node->kpfn < end_pfn)
remove_node_from_stable_tree(stable_node);
cond_resched();
}
}
static int ksm_memory_callback(struct notifier_block *self,
unsigned long action, void *arg)
{
struct memory_notify *mn = arg;
switch (action) {
case MEM_GOING_OFFLINE:
mutex_lock(&ksm_thread_mutex);
ksm_run |= KSM_RUN_OFFLINE;
mutex_unlock(&ksm_thread_mutex);
break;
case MEM_OFFLINE:
ksm_check_stable_tree(mn->start_pfn,
mn->start_pfn + mn->nr_pages);
case MEM_CANCEL_OFFLINE:
mutex_lock(&ksm_thread_mutex);
ksm_run &= ~KSM_RUN_OFFLINE;
mutex_unlock(&ksm_thread_mutex);
smp_mb();
wake_up_bit(&ksm_run, ilog2(KSM_RUN_OFFLINE));
break;
}
return NOTIFY_OK;
}
static void wait_while_offlining(void)
{
}
static ssize_t sleep_millisecs_show(struct kobject *kobj,
struct kobj_attribute *attr, char *buf)
{
return sprintf(buf, "%u\n", ksm_thread_sleep_millisecs);
}
static ssize_t sleep_millisecs_store(struct kobject *kobj,
struct kobj_attribute *attr,
const char *buf, size_t count)
{
unsigned long msecs;
int err;
err = kstrtoul(buf, 10, &msecs);
if (err || msecs > UINT_MAX)
return -EINVAL;
ksm_thread_sleep_millisecs = msecs;
return count;
}
static ssize_t pages_to_scan_show(struct kobject *kobj,
struct kobj_attribute *attr, char *buf)
{
return sprintf(buf, "%u\n", ksm_thread_pages_to_scan);
}
static ssize_t pages_to_scan_store(struct kobject *kobj,
struct kobj_attribute *attr,
const char *buf, size_t count)
{
int err;
unsigned long nr_pages;
err = kstrtoul(buf, 10, &nr_pages);
if (err || nr_pages > UINT_MAX)
return -EINVAL;
ksm_thread_pages_to_scan = nr_pages;
return count;
}
static ssize_t run_show(struct kobject *kobj, struct kobj_attribute *attr,
char *buf)
{
return sprintf(buf, "%lu\n", ksm_run);
}
static ssize_t run_store(struct kobject *kobj, struct kobj_attribute *attr,
const char *buf, size_t count)
{
int err;
unsigned long flags;
err = kstrtoul(buf, 10, &flags);
if (err || flags > UINT_MAX)
return -EINVAL;
if (flags > KSM_RUN_UNMERGE)
return -EINVAL;
mutex_lock(&ksm_thread_mutex);
wait_while_offlining();
if (ksm_run != flags) {
ksm_run = flags;
if (flags & KSM_RUN_UNMERGE) {
set_current_oom_origin();
err = unmerge_and_remove_all_rmap_items();
clear_current_oom_origin();
if (err) {
ksm_run = KSM_RUN_STOP;
count = err;
}
}
}
mutex_unlock(&ksm_thread_mutex);
if (flags & KSM_RUN_MERGE)
wake_up_interruptible(&ksm_thread_wait);
return count;
}
static ssize_t merge_across_nodes_show(struct kobject *kobj,
struct kobj_attribute *attr, char *buf)
{
return sprintf(buf, "%u\n", ksm_merge_across_nodes);
}
static ssize_t merge_across_nodes_store(struct kobject *kobj,
struct kobj_attribute *attr,
const char *buf, size_t count)
{
int err;
unsigned long knob;
err = kstrtoul(buf, 10, &knob);
if (err)
return err;
if (knob > 1)
return -EINVAL;
mutex_lock(&ksm_thread_mutex);
wait_while_offlining();
if (ksm_merge_across_nodes != knob) {
if (ksm_pages_shared || remove_all_stable_nodes())
err = -EBUSY;
else if (root_stable_tree == one_stable_tree) {
struct rb_root *buf;
buf = kcalloc(nr_node_ids + nr_node_ids, sizeof(*buf),
GFP_KERNEL);
if (!buf)
err = -ENOMEM;
else {
root_stable_tree = buf;
root_unstable_tree = buf + nr_node_ids;
root_unstable_tree[0] = one_unstable_tree[0];
}
}
if (!err) {
ksm_merge_across_nodes = knob;
ksm_nr_node_ids = knob ? 1 : nr_node_ids;
}
}
mutex_unlock(&ksm_thread_mutex);
return err ? err : count;
}
static ssize_t use_zero_pages_show(struct kobject *kobj,
struct kobj_attribute *attr, char *buf)
{
return sprintf(buf, "%u\n", ksm_use_zero_pages);
}
static ssize_t use_zero_pages_store(struct kobject *kobj,
struct kobj_attribute *attr,
const char *buf, size_t count)
{
int err;
bool value;
err = kstrtobool(buf, &value);
if (err)
return -EINVAL;
ksm_use_zero_pages = value;
return count;
}
static ssize_t max_page_sharing_show(struct kobject *kobj,
struct kobj_attribute *attr, char *buf)
{
return sprintf(buf, "%u\n", ksm_max_page_sharing);
}
static ssize_t max_page_sharing_store(struct kobject *kobj,
struct kobj_attribute *attr,
const char *buf, size_t count)
{
int err;
int knob;
err = kstrtoint(buf, 10, &knob);
if (err)
return err;
if (knob < 2)
return -EINVAL;
if (READ_ONCE(ksm_max_page_sharing) == knob)
return count;
mutex_lock(&ksm_thread_mutex);
wait_while_offlining();
if (ksm_max_page_sharing != knob) {
if (ksm_pages_shared || remove_all_stable_nodes())
err = -EBUSY;
else
ksm_max_page_sharing = knob;
}
mutex_unlock(&ksm_thread_mutex);
return err ? err : count;
}
static ssize_t pages_shared_show(struct kobject *kobj,
struct kobj_attribute *attr, char *buf)
{
return sprintf(buf, "%lu\n", ksm_pages_shared);
}
static ssize_t pages_sharing_show(struct kobject *kobj,
struct kobj_attribute *attr, char *buf)
{
return sprintf(buf, "%lu\n", ksm_pages_sharing);
}
static ssize_t pages_unshared_show(struct kobject *kobj,
struct kobj_attribute *attr, char *buf)
{
return sprintf(buf, "%lu\n", ksm_pages_unshared);
}
static ssize_t pages_volatile_show(struct kobject *kobj,
struct kobj_attribute *attr, char *buf)
{
long ksm_pages_volatile;
ksm_pages_volatile = ksm_rmap_items - ksm_pages_shared
- ksm_pages_sharing - ksm_pages_unshared;
if (ksm_pages_volatile < 0)
ksm_pages_volatile = 0;
return sprintf(buf, "%ld\n", ksm_pages_volatile);
}
static ssize_t stable_node_dups_show(struct kobject *kobj,
struct kobj_attribute *attr, char *buf)
{
return sprintf(buf, "%lu\n", ksm_stable_node_dups);
}
static ssize_t stable_node_chains_show(struct kobject *kobj,
struct kobj_attribute *attr, char *buf)
{
return sprintf(buf, "%lu\n", ksm_stable_node_chains);
}
static ssize_t
stable_node_chains_prune_millisecs_show(struct kobject *kobj,
struct kobj_attribute *attr,
char *buf)
{
return sprintf(buf, "%u\n", ksm_stable_node_chains_prune_millisecs);
}
static ssize_t
stable_node_chains_prune_millisecs_store(struct kobject *kobj,
struct kobj_attribute *attr,
const char *buf, size_t count)
{
unsigned long msecs;
int err;
err = kstrtoul(buf, 10, &msecs);
if (err || msecs > UINT_MAX)
return -EINVAL;
ksm_stable_node_chains_prune_millisecs = msecs;
return count;
}
static ssize_t full_scans_show(struct kobject *kobj,
struct kobj_attribute *attr, char *buf)
{
return sprintf(buf, "%lu\n", ksm_scan.seqnr);
}
static int __init ksm_init(void)
{
struct task_struct *ksm_thread;
int err;
zero_checksum = calc_checksum(ZERO_PAGE(0));
ksm_use_zero_pages = false;
err = ksm_slab_init();
if (err)
goto out;
ksm_thread = kthread_run(ksm_scan_thread, NULL, "ksmd");
if (IS_ERR(ksm_thread)) {
pr_err("ksm: creating kthread failed\n");
err = PTR_ERR(ksm_thread);
goto out_free;
}
#ifdef CONFIG_SYSFS
err = sysfs_create_group(mm_kobj, &ksm_attr_group);
if (err) {
pr_err("ksm: register sysfs failed\n");
kthread_stop(ksm_thread);
goto out_free;
}
#else
ksm_run = KSM_RUN_MERGE;
#endif
#ifdef CONFIG_MEMORY_HOTREMOVE
hotplug_memory_notifier(ksm_memory_callback, 100);
#endif
return 0;
out_free:
ksm_slab_free();
out:
return err;
}
