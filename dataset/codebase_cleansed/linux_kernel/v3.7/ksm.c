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
static inline struct rmap_item *alloc_rmap_item(void)
{
struct rmap_item *rmap_item;
rmap_item = kmem_cache_zalloc(rmap_item_cache, GFP_KERNEL);
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
return kmem_cache_alloc(stable_node_cache, GFP_KERNEL);
}
static inline void free_stable_node(struct stable_node *stable_node)
{
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
struct mm_slot *mm_slot;
struct hlist_head *bucket;
struct hlist_node *node;
bucket = &mm_slots_hash[hash_ptr(mm, MM_SLOTS_HASH_SHIFT)];
hlist_for_each_entry(mm_slot, node, bucket, link) {
if (mm == mm_slot->mm)
return mm_slot;
}
return NULL;
}
static void insert_to_mm_slots_hash(struct mm_struct *mm,
struct mm_slot *mm_slot)
{
struct hlist_head *bucket;
bucket = &mm_slots_hash[hash_ptr(mm, MM_SLOTS_HASH_SHIFT)];
mm_slot->mm = mm;
hlist_add_head(&mm_slot->link, bucket);
}
static inline int in_stable_tree(struct rmap_item *rmap_item)
{
return rmap_item->address & STABLE_FLAG;
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
page = follow_page(vma, addr, FOLL_GET);
if (IS_ERR_OR_NULL(page))
break;
if (PageKsm(page))
ret = handle_mm_fault(vma->vm_mm, vma, addr,
FAULT_FLAG_WRITE);
else
ret = VM_FAULT_WRITE;
put_page(page);
} while (!(ret & (VM_FAULT_WRITE | VM_FAULT_SIGBUS | VM_FAULT_OOM)));
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
static struct page *page_trans_compound_anon(struct page *page)
{
if (PageTransCompound(page)) {
struct page *head = compound_trans_head(page);
if (PageAnon(head))
return head;
}
return NULL;
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
if (PageAnon(page) || page_trans_compound_anon(page)) {
flush_anon_page(vma, page, addr);
flush_dcache_page(page);
} else {
put_page(page);
out: page = NULL;
}
up_read(&mm->mmap_sem);
return page;
}
static void remove_node_from_stable_tree(struct stable_node *stable_node)
{
struct rmap_item *rmap_item;
struct hlist_node *hlist;
hlist_for_each_entry(rmap_item, hlist, &stable_node->hlist, hlist) {
if (rmap_item->hlist.next)
ksm_pages_sharing--;
else
ksm_pages_shared--;
put_anon_vma(rmap_item->anon_vma);
rmap_item->address &= PAGE_MASK;
cond_resched();
}
rb_erase(&stable_node->node, &root_stable_tree);
free_stable_node(stable_node);
}
static struct page *get_ksm_page(struct stable_node *stable_node)
{
struct page *page;
void *expected_mapping;
page = pfn_to_page(stable_node->kpfn);
expected_mapping = (void *)stable_node +
(PAGE_MAPPING_ANON | PAGE_MAPPING_KSM);
rcu_read_lock();
if (page->mapping != expected_mapping)
goto stale;
if (!get_page_unless_zero(page))
goto stale;
if (page->mapping != expected_mapping) {
put_page(page);
goto stale;
}
rcu_read_unlock();
return page;
stale:
rcu_read_unlock();
remove_node_from_stable_tree(stable_node);
return NULL;
}
static void remove_rmap_item_from_tree(struct rmap_item *rmap_item)
{
if (rmap_item->address & STABLE_FLAG) {
struct stable_node *stable_node;
struct page *page;
stable_node = rmap_item->head;
page = get_ksm_page(stable_node);
if (!page)
goto out;
lock_page(page);
hlist_del(&rmap_item->hlist);
unlock_page(page);
put_page(page);
if (stable_node->hlist.first)
ksm_pages_sharing--;
else
ksm_pages_shared--;
put_anon_vma(rmap_item->anon_vma);
rmap_item->address &= PAGE_MASK;
} else if (rmap_item->address & UNSTABLE_FLAG) {
unsigned char age;
age = (unsigned char)(ksm_scan.seqnr - rmap_item->address);
BUG_ON(age > 1);
if (!age)
rb_erase(&rmap_item->node, &root_unstable_tree);
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
spin_lock(&ksm_mmlist_lock);
ksm_scan.mm_slot = list_entry(mm_slot->mm_list.next,
struct mm_slot, mm_list);
if (ksm_test_exit(mm)) {
hlist_del(&mm_slot->link);
list_del(&mm_slot->mm_list);
spin_unlock(&ksm_mmlist_lock);
free_mm_slot(mm_slot);
clear_bit(MMF_VM_MERGEABLE, &mm->flags);
up_read(&mm->mmap_sem);
mmdrop(mm);
} else {
spin_unlock(&ksm_mmlist_lock);
up_read(&mm->mmap_sem);
}
}
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
unsigned long addr;
pte_t *ptep;
spinlock_t *ptl;
int swapped;
int err = -EFAULT;
unsigned long mmun_start;
unsigned long mmun_end;
addr = page_address_in_vma(page, vma);
if (addr == -EFAULT)
goto out;
BUG_ON(PageTransCompound(page));
mmun_start = addr;
mmun_end = addr + PAGE_SIZE;
mmu_notifier_invalidate_range_start(mm, mmun_start, mmun_end);
ptep = page_check_address(page, mm, addr, &ptl, 0);
if (!ptep)
goto out_mn;
if (pte_write(*ptep) || pte_dirty(*ptep)) {
pte_t entry;
swapped = PageSwapCache(page);
flush_cache_page(vma, addr, page_to_pfn(page));
entry = ptep_clear_flush(vma, addr, ptep);
if (page_mapcount(page) + 1 + swapped != page_count(page)) {
set_pte_at(mm, addr, ptep, entry);
goto out_unlock;
}
if (pte_dirty(entry))
set_page_dirty(page);
entry = pte_mkclean(pte_wrprotect(entry));
set_pte_at_notify(mm, addr, ptep, entry);
}
*orig_pte = *ptep;
err = 0;
out_unlock:
pte_unmap_unlock(ptep, ptl);
out_mn:
mmu_notifier_invalidate_range_end(mm, mmun_start, mmun_end);
out:
return err;
}
static int replace_page(struct vm_area_struct *vma, struct page *page,
struct page *kpage, pte_t orig_pte)
{
struct mm_struct *mm = vma->vm_mm;
pgd_t *pgd;
pud_t *pud;
pmd_t *pmd;
pte_t *ptep;
spinlock_t *ptl;
unsigned long addr;
int err = -EFAULT;
unsigned long mmun_start;
unsigned long mmun_end;
addr = page_address_in_vma(page, vma);
if (addr == -EFAULT)
goto out;
pgd = pgd_offset(mm, addr);
if (!pgd_present(*pgd))
goto out;
pud = pud_offset(pgd, addr);
if (!pud_present(*pud))
goto out;
pmd = pmd_offset(pud, addr);
BUG_ON(pmd_trans_huge(*pmd));
if (!pmd_present(*pmd))
goto out;
mmun_start = addr;
mmun_end = addr + PAGE_SIZE;
mmu_notifier_invalidate_range_start(mm, mmun_start, mmun_end);
ptep = pte_offset_map_lock(mm, pmd, addr, &ptl);
if (!pte_same(*ptep, orig_pte)) {
pte_unmap_unlock(ptep, ptl);
goto out_mn;
}
get_page(kpage);
page_add_anon_rmap(kpage, vma, addr);
flush_cache_page(vma, addr, pte_pfn(*ptep));
ptep_clear_flush(vma, addr, ptep);
set_pte_at_notify(mm, addr, ptep, mk_pte(kpage, vma->vm_page_prot));
page_remove_rmap(page);
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
static int page_trans_compound_anon_split(struct page *page)
{
int ret = 0;
struct page *transhuge_head = page_trans_compound_anon(page);
if (transhuge_head) {
if (get_page_unless_zero(transhuge_head)) {
if (PageAnon(transhuge_head))
ret = split_huge_page(transhuge_head);
else
ret = 1;
put_page(transhuge_head);
} else
ret = 1;
}
return ret;
}
static int try_to_merge_one_page(struct vm_area_struct *vma,
struct page *page, struct page *kpage)
{
pte_t orig_pte = __pte(0);
int err = -EFAULT;
if (page == kpage)
return 0;
if (!(vma->vm_flags & VM_MERGEABLE))
goto out;
if (PageTransCompound(page) && page_trans_compound_anon_split(page))
goto out;
BUG_ON(PageTransCompound(page));
if (!PageAnon(page))
goto out;
if (!trylock_page(page))
goto out;
if (write_protect_page(vma, page, &orig_pte) == 0) {
if (!kpage) {
set_page_stable_node(page, NULL);
mark_page_accessed(page);
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
if (ksm_test_exit(mm))
goto out;
vma = find_vma(mm, rmap_item->address);
if (!vma || vma->vm_start > rmap_item->address)
goto out;
err = try_to_merge_one_page(vma, page, kpage);
if (err)
goto out;
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
static struct page *stable_tree_search(struct page *page)
{
struct rb_node *node = root_stable_tree.rb_node;
struct stable_node *stable_node;
stable_node = page_stable_node(page);
if (stable_node) {
get_page(page);
return page;
}
while (node) {
struct page *tree_page;
int ret;
cond_resched();
stable_node = rb_entry(node, struct stable_node, node);
tree_page = get_ksm_page(stable_node);
if (!tree_page)
return NULL;
ret = memcmp_pages(page, tree_page);
if (ret < 0) {
put_page(tree_page);
node = node->rb_left;
} else if (ret > 0) {
put_page(tree_page);
node = node->rb_right;
} else
return tree_page;
}
return NULL;
}
static struct stable_node *stable_tree_insert(struct page *kpage)
{
struct rb_node **new = &root_stable_tree.rb_node;
struct rb_node *parent = NULL;
struct stable_node *stable_node;
while (*new) {
struct page *tree_page;
int ret;
cond_resched();
stable_node = rb_entry(*new, struct stable_node, node);
tree_page = get_ksm_page(stable_node);
if (!tree_page)
return NULL;
ret = memcmp_pages(kpage, tree_page);
put_page(tree_page);
parent = *new;
if (ret < 0)
new = &parent->rb_left;
else if (ret > 0)
new = &parent->rb_right;
else {
return NULL;
}
}
stable_node = alloc_stable_node();
if (!stable_node)
return NULL;
rb_link_node(&stable_node->node, parent, new);
rb_insert_color(&stable_node->node, &root_stable_tree);
INIT_HLIST_HEAD(&stable_node->hlist);
stable_node->kpfn = page_to_pfn(kpage);
set_page_stable_node(kpage, stable_node);
return stable_node;
}
static
struct rmap_item *unstable_tree_search_insert(struct rmap_item *rmap_item,
struct page *page,
struct page **tree_pagep)
{
struct rb_node **new = &root_unstable_tree.rb_node;
struct rb_node *parent = NULL;
while (*new) {
struct rmap_item *tree_rmap_item;
struct page *tree_page;
int ret;
cond_resched();
tree_rmap_item = rb_entry(*new, struct rmap_item, node);
tree_page = get_mergeable_page(tree_rmap_item);
if (IS_ERR_OR_NULL(tree_page))
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
} else {
*tree_pagep = tree_page;
return tree_rmap_item;
}
}
rmap_item->address |= UNSTABLE_FLAG;
rmap_item->address |= (ksm_scan.seqnr & SEQNR_MASK);
rb_link_node(&rmap_item->node, parent, new);
rb_insert_color(&rmap_item->node, &root_unstable_tree);
ksm_pages_unshared++;
return NULL;
}
static void stable_tree_append(struct rmap_item *rmap_item,
struct stable_node *stable_node)
{
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
struct rmap_item *tree_rmap_item;
struct page *tree_page = NULL;
struct stable_node *stable_node;
struct page *kpage;
unsigned int checksum;
int err;
remove_rmap_item_from_tree(rmap_item);
kpage = stable_tree_search(page);
if (kpage) {
err = try_to_merge_with_ksm_page(rmap_item, page, kpage);
if (!err) {
lock_page(kpage);
stable_tree_append(rmap_item, page_stable_node(kpage));
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
tree_rmap_item =
unstable_tree_search_insert(rmap_item, page, &tree_page);
if (tree_rmap_item) {
kpage = try_to_merge_two_pages(rmap_item, page,
tree_rmap_item, tree_page);
put_page(tree_page);
if (kpage) {
remove_rmap_item_from_tree(tree_rmap_item);
lock_page(kpage);
stable_node = stable_tree_insert(kpage);
if (stable_node) {
stable_tree_append(tree_rmap_item, stable_node);
stable_tree_append(rmap_item, stable_node);
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
if (list_empty(&ksm_mm_head.mm_list))
return NULL;
slot = ksm_scan.mm_slot;
if (slot == &ksm_mm_head) {
lru_add_drain_all();
root_unstable_tree = RB_ROOT;
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
if (PageAnon(*page) ||
page_trans_compound_anon(*page)) {
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
hlist_del(&slot->link);
list_del(&slot->mm_list);
spin_unlock(&ksm_mmlist_lock);
free_mm_slot(slot);
clear_bit(MMF_VM_MERGEABLE, &mm->flags);
up_read(&mm->mmap_sem);
mmdrop(mm);
} else {
spin_unlock(&ksm_mmlist_lock);
up_read(&mm->mmap_sem);
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
if (!PageKsm(page) || !in_stable_tree(rmap_item))
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
VM_HUGETLB | VM_NONLINEAR | VM_MIXEDMAP))
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
list_add_tail(&mm_slot->mm_list, &ksm_scan.mm_slot->mm_list);
spin_unlock(&ksm_mmlist_lock);
set_bit(MMF_VM_MERGEABLE, &mm->flags);
atomic_inc(&mm->mm_count);
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
hlist_del(&mm_slot->link);
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
struct page *ksm_does_need_to_copy(struct page *page,
struct vm_area_struct *vma, unsigned long address)
{
struct page *new_page;
new_page = alloc_page_vma(GFP_HIGHUSER_MOVABLE, vma, address);
if (new_page) {
copy_user_highpage(new_page, page, address, vma);
SetPageDirty(new_page);
__SetPageUptodate(new_page);
SetPageSwapBacked(new_page);
__set_page_locked(new_page);
if (!mlocked_vma_newpage(vma, new_page))
lru_cache_add_lru(new_page, LRU_ACTIVE_ANON);
else
add_page_to_unevictable_list(new_page);
}
return new_page;
}
int page_referenced_ksm(struct page *page, struct mem_cgroup *memcg,
unsigned long *vm_flags)
{
struct stable_node *stable_node;
struct rmap_item *rmap_item;
struct hlist_node *hlist;
unsigned int mapcount = page_mapcount(page);
int referenced = 0;
int search_new_forks = 0;
VM_BUG_ON(!PageKsm(page));
VM_BUG_ON(!PageLocked(page));
stable_node = page_stable_node(page);
if (!stable_node)
return 0;
again:
hlist_for_each_entry(rmap_item, hlist, &stable_node->hlist, hlist) {
struct anon_vma *anon_vma = rmap_item->anon_vma;
struct anon_vma_chain *vmac;
struct vm_area_struct *vma;
anon_vma_lock(anon_vma);
anon_vma_interval_tree_foreach(vmac, &anon_vma->rb_root,
0, ULONG_MAX) {
vma = vmac->vma;
if (rmap_item->address < vma->vm_start ||
rmap_item->address >= vma->vm_end)
continue;
if ((rmap_item->mm == vma->vm_mm) == search_new_forks)
continue;
if (memcg && !mm_match_cgroup(vma->vm_mm, memcg))
continue;
referenced += page_referenced_one(page, vma,
rmap_item->address, &mapcount, vm_flags);
if (!search_new_forks || !mapcount)
break;
}
anon_vma_unlock(anon_vma);
if (!mapcount)
goto out;
}
if (!search_new_forks++)
goto again;
out:
return referenced;
}
int try_to_unmap_ksm(struct page *page, enum ttu_flags flags)
{
struct stable_node *stable_node;
struct hlist_node *hlist;
struct rmap_item *rmap_item;
int ret = SWAP_AGAIN;
int search_new_forks = 0;
VM_BUG_ON(!PageKsm(page));
VM_BUG_ON(!PageLocked(page));
stable_node = page_stable_node(page);
if (!stable_node)
return SWAP_FAIL;
again:
hlist_for_each_entry(rmap_item, hlist, &stable_node->hlist, hlist) {
struct anon_vma *anon_vma = rmap_item->anon_vma;
struct anon_vma_chain *vmac;
struct vm_area_struct *vma;
anon_vma_lock(anon_vma);
anon_vma_interval_tree_foreach(vmac, &anon_vma->rb_root,
0, ULONG_MAX) {
vma = vmac->vma;
if (rmap_item->address < vma->vm_start ||
rmap_item->address >= vma->vm_end)
continue;
if ((rmap_item->mm == vma->vm_mm) == search_new_forks)
continue;
ret = try_to_unmap_one(page, vma,
rmap_item->address, flags);
if (ret != SWAP_AGAIN || !page_mapped(page)) {
anon_vma_unlock(anon_vma);
goto out;
}
}
anon_vma_unlock(anon_vma);
}
if (!search_new_forks++)
goto again;
out:
return ret;
}
int rmap_walk_ksm(struct page *page, int (*rmap_one)(struct page *,
struct vm_area_struct *, unsigned long, void *), void *arg)
{
struct stable_node *stable_node;
struct hlist_node *hlist;
struct rmap_item *rmap_item;
int ret = SWAP_AGAIN;
int search_new_forks = 0;
VM_BUG_ON(!PageKsm(page));
VM_BUG_ON(!PageLocked(page));
stable_node = page_stable_node(page);
if (!stable_node)
return ret;
again:
hlist_for_each_entry(rmap_item, hlist, &stable_node->hlist, hlist) {
struct anon_vma *anon_vma = rmap_item->anon_vma;
struct anon_vma_chain *vmac;
struct vm_area_struct *vma;
anon_vma_lock(anon_vma);
anon_vma_interval_tree_foreach(vmac, &anon_vma->rb_root,
0, ULONG_MAX) {
vma = vmac->vma;
if (rmap_item->address < vma->vm_start ||
rmap_item->address >= vma->vm_end)
continue;
if ((rmap_item->mm == vma->vm_mm) == search_new_forks)
continue;
ret = rmap_one(page, vma, rmap_item->address, arg);
if (ret != SWAP_AGAIN) {
anon_vma_unlock(anon_vma);
goto out;
}
}
anon_vma_unlock(anon_vma);
}
if (!search_new_forks++)
goto again;
out:
return ret;
}
void ksm_migrate_page(struct page *newpage, struct page *oldpage)
{
struct stable_node *stable_node;
VM_BUG_ON(!PageLocked(oldpage));
VM_BUG_ON(!PageLocked(newpage));
VM_BUG_ON(newpage->mapping != oldpage->mapping);
stable_node = page_stable_node(newpage);
if (stable_node) {
VM_BUG_ON(stable_node->kpfn != page_to_pfn(oldpage));
stable_node->kpfn = page_to_pfn(newpage);
}
}
static struct stable_node *ksm_check_stable_tree(unsigned long start_pfn,
unsigned long end_pfn)
{
struct rb_node *node;
for (node = rb_first(&root_stable_tree); node; node = rb_next(node)) {
struct stable_node *stable_node;
stable_node = rb_entry(node, struct stable_node, node);
if (stable_node->kpfn >= start_pfn &&
stable_node->kpfn < end_pfn)
return stable_node;
}
return NULL;
}
static int ksm_memory_callback(struct notifier_block *self,
unsigned long action, void *arg)
{
struct memory_notify *mn = arg;
struct stable_node *stable_node;
switch (action) {
case MEM_GOING_OFFLINE:
mutex_lock_nested(&ksm_thread_mutex, SINGLE_DEPTH_NESTING);
break;
case MEM_OFFLINE:
while ((stable_node = ksm_check_stable_tree(mn->start_pfn,
mn->start_pfn + mn->nr_pages)) != NULL)
remove_node_from_stable_tree(stable_node);
case MEM_CANCEL_OFFLINE:
mutex_unlock(&ksm_thread_mutex);
break;
}
return NOTIFY_OK;
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
err = strict_strtoul(buf, 10, &msecs);
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
err = strict_strtoul(buf, 10, &nr_pages);
if (err || nr_pages > UINT_MAX)
return -EINVAL;
ksm_thread_pages_to_scan = nr_pages;
return count;
}
static ssize_t run_show(struct kobject *kobj, struct kobj_attribute *attr,
char *buf)
{
return sprintf(buf, "%u\n", ksm_run);
}
static ssize_t run_store(struct kobject *kobj, struct kobj_attribute *attr,
const char *buf, size_t count)
{
int err;
unsigned long flags;
err = strict_strtoul(buf, 10, &flags);
if (err || flags > UINT_MAX)
return -EINVAL;
if (flags > KSM_RUN_UNMERGE)
return -EINVAL;
mutex_lock(&ksm_thread_mutex);
if (ksm_run != flags) {
ksm_run = flags;
if (flags & KSM_RUN_UNMERGE) {
int oom_score_adj;
oom_score_adj = test_set_oom_score_adj(OOM_SCORE_ADJ_MAX);
err = unmerge_and_remove_all_rmap_items();
compare_swap_oom_score_adj(OOM_SCORE_ADJ_MAX,
oom_score_adj);
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
static ssize_t full_scans_show(struct kobject *kobj,
struct kobj_attribute *attr, char *buf)
{
return sprintf(buf, "%lu\n", ksm_scan.seqnr);
}
static int __init ksm_init(void)
{
struct task_struct *ksm_thread;
int err;
err = ksm_slab_init();
if (err)
goto out;
ksm_thread = kthread_run(ksm_scan_thread, NULL, "ksmd");
if (IS_ERR(ksm_thread)) {
printk(KERN_ERR "ksm: creating kthread failed\n");
err = PTR_ERR(ksm_thread);
goto out_free;
}
#ifdef CONFIG_SYSFS
err = sysfs_create_group(mm_kobj, &ksm_attr_group);
if (err) {
printk(KERN_ERR "ksm: register sysfs failed\n");
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
