static int __init init_dax_wait_table(void)
{
int i;
for (i = 0; i < DAX_WAIT_TABLE_ENTRIES; i++)
init_waitqueue_head(wait_table + i);
return 0;
}
static long dax_map_atomic(struct block_device *bdev, struct blk_dax_ctl *dax)
{
struct request_queue *q = bdev->bd_queue;
long rc = -EIO;
dax->addr = ERR_PTR(-EIO);
if (blk_queue_enter(q, true) != 0)
return rc;
rc = bdev_direct_access(bdev, dax);
if (rc < 0) {
dax->addr = ERR_PTR(rc);
blk_queue_exit(q);
return rc;
}
return rc;
}
static void dax_unmap_atomic(struct block_device *bdev,
const struct blk_dax_ctl *dax)
{
if (IS_ERR(dax->addr))
return;
blk_queue_exit(bdev->bd_queue);
}
static int dax_is_pmd_entry(void *entry)
{
return (unsigned long)entry & RADIX_DAX_PMD;
}
static int dax_is_pte_entry(void *entry)
{
return !((unsigned long)entry & RADIX_DAX_PMD);
}
static int dax_is_zero_entry(void *entry)
{
return (unsigned long)entry & RADIX_DAX_HZP;
}
static int dax_is_empty_entry(void *entry)
{
return (unsigned long)entry & RADIX_DAX_EMPTY;
}
struct page *read_dax_sector(struct block_device *bdev, sector_t n)
{
struct page *page = alloc_pages(GFP_KERNEL, 0);
struct blk_dax_ctl dax = {
.size = PAGE_SIZE,
.sector = n & ~((((int) PAGE_SIZE) / 512) - 1),
};
long rc;
if (!page)
return ERR_PTR(-ENOMEM);
rc = dax_map_atomic(bdev, &dax);
if (rc < 0)
return ERR_PTR(rc);
memcpy_from_pmem(page_address(page), dax.addr, PAGE_SIZE);
dax_unmap_atomic(bdev, &dax);
return page;
}
static wait_queue_head_t *dax_entry_waitqueue(struct address_space *mapping,
pgoff_t index, void *entry, struct exceptional_entry_key *key)
{
unsigned long hash;
if (dax_is_pmd_entry(entry))
index &= ~((1UL << (PMD_SHIFT - PAGE_SHIFT)) - 1);
key->mapping = mapping;
key->entry_start = index;
hash = hash_long((unsigned long)mapping ^ index, DAX_WAIT_TABLE_BITS);
return wait_table + hash;
}
static int wake_exceptional_entry_func(wait_queue_t *wait, unsigned int mode,
int sync, void *keyp)
{
struct exceptional_entry_key *key = keyp;
struct wait_exceptional_entry_queue *ewait =
container_of(wait, struct wait_exceptional_entry_queue, wait);
if (key->mapping != ewait->key.mapping ||
key->entry_start != ewait->key.entry_start)
return 0;
return autoremove_wake_function(wait, mode, sync, NULL);
}
static inline int slot_locked(struct address_space *mapping, void **slot)
{
unsigned long entry = (unsigned long)
radix_tree_deref_slot_protected(slot, &mapping->tree_lock);
return entry & RADIX_DAX_ENTRY_LOCK;
}
static inline void *lock_slot(struct address_space *mapping, void **slot)
{
unsigned long entry = (unsigned long)
radix_tree_deref_slot_protected(slot, &mapping->tree_lock);
entry |= RADIX_DAX_ENTRY_LOCK;
radix_tree_replace_slot(&mapping->page_tree, slot, (void *)entry);
return (void *)entry;
}
static inline void *unlock_slot(struct address_space *mapping, void **slot)
{
unsigned long entry = (unsigned long)
radix_tree_deref_slot_protected(slot, &mapping->tree_lock);
entry &= ~(unsigned long)RADIX_DAX_ENTRY_LOCK;
radix_tree_replace_slot(&mapping->page_tree, slot, (void *)entry);
return (void *)entry;
}
static void *get_unlocked_mapping_entry(struct address_space *mapping,
pgoff_t index, void ***slotp)
{
void *entry, **slot;
struct wait_exceptional_entry_queue ewait;
wait_queue_head_t *wq;
init_wait(&ewait.wait);
ewait.wait.func = wake_exceptional_entry_func;
for (;;) {
entry = __radix_tree_lookup(&mapping->page_tree, index, NULL,
&slot);
if (!entry || !radix_tree_exceptional_entry(entry) ||
!slot_locked(mapping, slot)) {
if (slotp)
*slotp = slot;
return entry;
}
wq = dax_entry_waitqueue(mapping, index, entry, &ewait.key);
prepare_to_wait_exclusive(wq, &ewait.wait,
TASK_UNINTERRUPTIBLE);
spin_unlock_irq(&mapping->tree_lock);
schedule();
finish_wait(wq, &ewait.wait);
spin_lock_irq(&mapping->tree_lock);
}
}
static void dax_unlock_mapping_entry(struct address_space *mapping,
pgoff_t index)
{
void *entry, **slot;
spin_lock_irq(&mapping->tree_lock);
entry = __radix_tree_lookup(&mapping->page_tree, index, NULL, &slot);
if (WARN_ON_ONCE(!entry || !radix_tree_exceptional_entry(entry) ||
!slot_locked(mapping, slot))) {
spin_unlock_irq(&mapping->tree_lock);
return;
}
unlock_slot(mapping, slot);
spin_unlock_irq(&mapping->tree_lock);
dax_wake_mapping_entry_waiter(mapping, index, entry, false);
}
static void put_locked_mapping_entry(struct address_space *mapping,
pgoff_t index, void *entry)
{
if (!radix_tree_exceptional_entry(entry)) {
unlock_page(entry);
put_page(entry);
} else {
dax_unlock_mapping_entry(mapping, index);
}
}
static void put_unlocked_mapping_entry(struct address_space *mapping,
pgoff_t index, void *entry)
{
if (!radix_tree_exceptional_entry(entry))
return;
dax_wake_mapping_entry_waiter(mapping, index, entry, false);
}
static void *grab_mapping_entry(struct address_space *mapping, pgoff_t index,
unsigned long size_flag)
{
bool pmd_downgrade = false;
void *entry, **slot;
restart:
spin_lock_irq(&mapping->tree_lock);
entry = get_unlocked_mapping_entry(mapping, index, &slot);
if (entry) {
if (size_flag & RADIX_DAX_PMD) {
if (!radix_tree_exceptional_entry(entry) ||
dax_is_pte_entry(entry)) {
put_unlocked_mapping_entry(mapping, index,
entry);
entry = ERR_PTR(-EEXIST);
goto out_unlock;
}
} else {
if (radix_tree_exceptional_entry(entry) &&
dax_is_pmd_entry(entry) &&
(dax_is_zero_entry(entry) ||
dax_is_empty_entry(entry))) {
pmd_downgrade = true;
}
}
}
if (!entry || pmd_downgrade) {
int err;
if (pmd_downgrade) {
entry = lock_slot(mapping, slot);
}
spin_unlock_irq(&mapping->tree_lock);
if (pmd_downgrade && dax_is_zero_entry(entry))
unmap_mapping_range(mapping,
(index << PAGE_SHIFT) & PMD_MASK, PMD_SIZE, 0);
err = radix_tree_preload(
mapping_gfp_mask(mapping) & ~__GFP_HIGHMEM);
if (err) {
if (pmd_downgrade)
put_locked_mapping_entry(mapping, index, entry);
return ERR_PTR(err);
}
spin_lock_irq(&mapping->tree_lock);
if (pmd_downgrade) {
radix_tree_delete(&mapping->page_tree, index);
mapping->nrexceptional--;
dax_wake_mapping_entry_waiter(mapping, index, entry,
true);
}
entry = dax_radix_locked_entry(0, size_flag | RADIX_DAX_EMPTY);
err = __radix_tree_insert(&mapping->page_tree, index,
dax_radix_order(entry), entry);
radix_tree_preload_end();
if (err) {
spin_unlock_irq(&mapping->tree_lock);
if (err == -EEXIST && !(size_flag & RADIX_DAX_PMD))
goto restart;
return ERR_PTR(err);
}
mapping->nrexceptional++;
spin_unlock_irq(&mapping->tree_lock);
return entry;
}
if (!radix_tree_exceptional_entry(entry)) {
struct page *page = entry;
get_page(page);
spin_unlock_irq(&mapping->tree_lock);
lock_page(page);
if (unlikely(page->mapping != mapping)) {
unlock_page(page);
put_page(page);
goto restart;
}
return page;
}
entry = lock_slot(mapping, slot);
out_unlock:
spin_unlock_irq(&mapping->tree_lock);
return entry;
}
void dax_wake_mapping_entry_waiter(struct address_space *mapping,
pgoff_t index, void *entry, bool wake_all)
{
struct exceptional_entry_key key;
wait_queue_head_t *wq;
wq = dax_entry_waitqueue(mapping, index, entry, &key);
if (waitqueue_active(wq))
__wake_up(wq, TASK_NORMAL, wake_all ? 0 : 1, &key);
}
static int __dax_invalidate_mapping_entry(struct address_space *mapping,
pgoff_t index, bool trunc)
{
int ret = 0;
void *entry;
struct radix_tree_root *page_tree = &mapping->page_tree;
spin_lock_irq(&mapping->tree_lock);
entry = get_unlocked_mapping_entry(mapping, index, NULL);
if (!entry || !radix_tree_exceptional_entry(entry))
goto out;
if (!trunc &&
(radix_tree_tag_get(page_tree, index, PAGECACHE_TAG_DIRTY) ||
radix_tree_tag_get(page_tree, index, PAGECACHE_TAG_TOWRITE)))
goto out;
radix_tree_delete(page_tree, index);
mapping->nrexceptional--;
ret = 1;
out:
put_unlocked_mapping_entry(mapping, index, entry);
spin_unlock_irq(&mapping->tree_lock);
return ret;
}
int dax_delete_mapping_entry(struct address_space *mapping, pgoff_t index)
{
int ret = __dax_invalidate_mapping_entry(mapping, index, true);
WARN_ON_ONCE(!ret);
return ret;
}
int dax_invalidate_mapping_entry(struct address_space *mapping, pgoff_t index)
{
int ret = 0;
void *entry, **slot;
struct radix_tree_root *page_tree = &mapping->page_tree;
spin_lock_irq(&mapping->tree_lock);
entry = __radix_tree_lookup(page_tree, index, NULL, &slot);
if (!entry || !radix_tree_exceptional_entry(entry) ||
slot_locked(mapping, slot))
goto out;
if (radix_tree_tag_get(page_tree, index, PAGECACHE_TAG_DIRTY) ||
radix_tree_tag_get(page_tree, index, PAGECACHE_TAG_TOWRITE))
goto out;
radix_tree_delete(page_tree, index);
mapping->nrexceptional--;
ret = 1;
out:
spin_unlock_irq(&mapping->tree_lock);
if (ret)
dax_wake_mapping_entry_waiter(mapping, index, entry, true);
return ret;
}
int dax_invalidate_mapping_entry_sync(struct address_space *mapping,
pgoff_t index)
{
return __dax_invalidate_mapping_entry(mapping, index, false);
}
static int dax_load_hole(struct address_space *mapping, void **entry,
struct vm_fault *vmf)
{
struct page *page;
int ret;
if (!radix_tree_exceptional_entry(*entry)) {
page = *entry;
goto out;
}
page = find_or_create_page(mapping, vmf->pgoff,
vmf->gfp_mask | __GFP_ZERO);
if (!page)
return VM_FAULT_OOM;
out:
vmf->page = page;
ret = finish_fault(vmf);
vmf->page = NULL;
*entry = page;
if (!ret) {
get_page(page);
return VM_FAULT_NOPAGE;
}
return ret;
}
static int copy_user_dax(struct block_device *bdev, sector_t sector, size_t size,
struct page *to, unsigned long vaddr)
{
struct blk_dax_ctl dax = {
.sector = sector,
.size = size,
};
void *vto;
if (dax_map_atomic(bdev, &dax) < 0)
return PTR_ERR(dax.addr);
vto = kmap_atomic(to);
copy_user_page(vto, (void __force *)dax.addr, vaddr, to);
kunmap_atomic(vto);
dax_unmap_atomic(bdev, &dax);
return 0;
}
static void *dax_insert_mapping_entry(struct address_space *mapping,
struct vm_fault *vmf,
void *entry, sector_t sector,
unsigned long flags)
{
struct radix_tree_root *page_tree = &mapping->page_tree;
int error = 0;
bool hole_fill = false;
void *new_entry;
pgoff_t index = vmf->pgoff;
if (vmf->flags & FAULT_FLAG_WRITE)
__mark_inode_dirty(mapping->host, I_DIRTY_PAGES);
if (!radix_tree_exceptional_entry(entry)) {
hole_fill = true;
unmap_mapping_range(mapping, vmf->pgoff << PAGE_SHIFT,
PAGE_SIZE, 0);
error = radix_tree_preload(vmf->gfp_mask & ~__GFP_HIGHMEM);
if (error)
return ERR_PTR(error);
} else if (dax_is_zero_entry(entry) && !(flags & RADIX_DAX_HZP)) {
unmap_mapping_range(mapping,
(vmf->pgoff << PAGE_SHIFT) & PMD_MASK, PMD_SIZE, 0);
}
spin_lock_irq(&mapping->tree_lock);
new_entry = dax_radix_locked_entry(sector, flags);
if (hole_fill) {
__delete_from_page_cache(entry, NULL);
put_page(entry);
error = __radix_tree_insert(page_tree, index,
dax_radix_order(new_entry), new_entry);
if (error) {
new_entry = ERR_PTR(error);
goto unlock;
}
mapping->nrexceptional++;
} else if (dax_is_zero_entry(entry) || dax_is_empty_entry(entry)) {
struct radix_tree_node *node;
void **slot;
void *ret;
ret = __radix_tree_lookup(page_tree, index, &node, &slot);
WARN_ON_ONCE(ret != entry);
__radix_tree_replace(page_tree, node, slot,
new_entry, NULL, NULL);
}
if (vmf->flags & FAULT_FLAG_WRITE)
radix_tree_tag_set(page_tree, index, PAGECACHE_TAG_DIRTY);
unlock:
spin_unlock_irq(&mapping->tree_lock);
if (hole_fill) {
radix_tree_preload_end();
if (mapping->a_ops->freepage)
mapping->a_ops->freepage(entry);
unlock_page(entry);
put_page(entry);
}
return new_entry;
}
static inline unsigned long
pgoff_address(pgoff_t pgoff, struct vm_area_struct *vma)
{
unsigned long address;
address = vma->vm_start + ((pgoff - vma->vm_pgoff) << PAGE_SHIFT);
VM_BUG_ON_VMA(address < vma->vm_start || address >= vma->vm_end, vma);
return address;
}
static void dax_mapping_entry_mkclean(struct address_space *mapping,
pgoff_t index, unsigned long pfn)
{
struct vm_area_struct *vma;
pte_t pte, *ptep = NULL;
pmd_t *pmdp = NULL;
spinlock_t *ptl;
bool changed;
i_mmap_lock_read(mapping);
vma_interval_tree_foreach(vma, &mapping->i_mmap, index, index) {
unsigned long address;
cond_resched();
if (!(vma->vm_flags & VM_SHARED))
continue;
address = pgoff_address(index, vma);
changed = false;
if (follow_pte_pmd(vma->vm_mm, address, &ptep, &pmdp, &ptl))
continue;
if (pmdp) {
#ifdef CONFIG_FS_DAX_PMD
pmd_t pmd;
if (pfn != pmd_pfn(*pmdp))
goto unlock_pmd;
if (!pmd_dirty(*pmdp) && !pmd_write(*pmdp))
goto unlock_pmd;
flush_cache_page(vma, address, pfn);
pmd = pmdp_huge_clear_flush(vma, address, pmdp);
pmd = pmd_wrprotect(pmd);
pmd = pmd_mkclean(pmd);
set_pmd_at(vma->vm_mm, address, pmdp, pmd);
changed = true;
unlock_pmd:
spin_unlock(ptl);
#endif
} else {
if (pfn != pte_pfn(*ptep))
goto unlock_pte;
if (!pte_dirty(*ptep) && !pte_write(*ptep))
goto unlock_pte;
flush_cache_page(vma, address, pfn);
pte = ptep_clear_flush(vma, address, ptep);
pte = pte_wrprotect(pte);
pte = pte_mkclean(pte);
set_pte_at(vma->vm_mm, address, ptep, pte);
changed = true;
unlock_pte:
pte_unmap_unlock(ptep, ptl);
}
if (changed)
mmu_notifier_invalidate_page(vma->vm_mm, address);
}
i_mmap_unlock_read(mapping);
}
static int dax_writeback_one(struct block_device *bdev,
struct address_space *mapping, pgoff_t index, void *entry)
{
struct radix_tree_root *page_tree = &mapping->page_tree;
struct blk_dax_ctl dax;
void *entry2, **slot;
int ret = 0;
if (WARN_ON(!radix_tree_exceptional_entry(entry)))
return -EIO;
spin_lock_irq(&mapping->tree_lock);
entry2 = get_unlocked_mapping_entry(mapping, index, &slot);
if (!entry2 || !radix_tree_exceptional_entry(entry2))
goto put_unlocked;
if (dax_radix_sector(entry2) != dax_radix_sector(entry))
goto put_unlocked;
if (WARN_ON_ONCE(dax_is_empty_entry(entry) ||
dax_is_zero_entry(entry))) {
ret = -EIO;
goto put_unlocked;
}
if (!radix_tree_tag_get(page_tree, index, PAGECACHE_TAG_TOWRITE))
goto put_unlocked;
entry = lock_slot(mapping, slot);
radix_tree_tag_clear(page_tree, index, PAGECACHE_TAG_TOWRITE);
spin_unlock_irq(&mapping->tree_lock);
dax.sector = dax_radix_sector(entry);
dax.size = PAGE_SIZE << dax_radix_order(entry);
ret = dax_map_atomic(bdev, &dax);
if (ret < 0) {
put_locked_mapping_entry(mapping, index, entry);
return ret;
}
if (WARN_ON_ONCE(ret < dax.size)) {
ret = -EIO;
goto unmap;
}
dax_mapping_entry_mkclean(mapping, index, pfn_t_to_pfn(dax.pfn));
wb_cache_pmem(dax.addr, dax.size);
spin_lock_irq(&mapping->tree_lock);
radix_tree_tag_clear(page_tree, index, PAGECACHE_TAG_DIRTY);
spin_unlock_irq(&mapping->tree_lock);
unmap:
dax_unmap_atomic(bdev, &dax);
put_locked_mapping_entry(mapping, index, entry);
return ret;
put_unlocked:
put_unlocked_mapping_entry(mapping, index, entry2);
spin_unlock_irq(&mapping->tree_lock);
return ret;
}
int dax_writeback_mapping_range(struct address_space *mapping,
struct block_device *bdev, struct writeback_control *wbc)
{
struct inode *inode = mapping->host;
pgoff_t start_index, end_index;
pgoff_t indices[PAGEVEC_SIZE];
struct pagevec pvec;
bool done = false;
int i, ret = 0;
if (WARN_ON_ONCE(inode->i_blkbits != PAGE_SHIFT))
return -EIO;
if (!mapping->nrexceptional || wbc->sync_mode != WB_SYNC_ALL)
return 0;
start_index = wbc->range_start >> PAGE_SHIFT;
end_index = wbc->range_end >> PAGE_SHIFT;
tag_pages_for_writeback(mapping, start_index, end_index);
pagevec_init(&pvec, 0);
while (!done) {
pvec.nr = find_get_entries_tag(mapping, start_index,
PAGECACHE_TAG_TOWRITE, PAGEVEC_SIZE,
pvec.pages, indices);
if (pvec.nr == 0)
break;
for (i = 0; i < pvec.nr; i++) {
if (indices[i] > end_index) {
done = true;
break;
}
ret = dax_writeback_one(bdev, mapping, indices[i],
pvec.pages[i]);
if (ret < 0)
return ret;
}
}
return 0;
}
static int dax_insert_mapping(struct address_space *mapping,
struct block_device *bdev, sector_t sector, size_t size,
void **entryp, struct vm_area_struct *vma, struct vm_fault *vmf)
{
unsigned long vaddr = vmf->address;
struct blk_dax_ctl dax = {
.sector = sector,
.size = size,
};
void *ret;
void *entry = *entryp;
if (dax_map_atomic(bdev, &dax) < 0)
return PTR_ERR(dax.addr);
dax_unmap_atomic(bdev, &dax);
ret = dax_insert_mapping_entry(mapping, vmf, entry, dax.sector, 0);
if (IS_ERR(ret))
return PTR_ERR(ret);
*entryp = ret;
return vm_insert_mixed(vma, vaddr, dax.pfn);
}
int dax_pfn_mkwrite(struct vm_area_struct *vma, struct vm_fault *vmf)
{
struct file *file = vma->vm_file;
struct address_space *mapping = file->f_mapping;
void *entry, **slot;
pgoff_t index = vmf->pgoff;
spin_lock_irq(&mapping->tree_lock);
entry = get_unlocked_mapping_entry(mapping, index, &slot);
if (!entry || !radix_tree_exceptional_entry(entry)) {
if (entry)
put_unlocked_mapping_entry(mapping, index, entry);
spin_unlock_irq(&mapping->tree_lock);
return VM_FAULT_NOPAGE;
}
radix_tree_tag_set(&mapping->page_tree, index, PAGECACHE_TAG_DIRTY);
entry = lock_slot(mapping, slot);
spin_unlock_irq(&mapping->tree_lock);
finish_mkwrite_fault(vmf);
put_locked_mapping_entry(mapping, index, entry);
return VM_FAULT_NOPAGE;
}
static bool dax_range_is_aligned(struct block_device *bdev,
unsigned int offset, unsigned int length)
{
unsigned short sector_size = bdev_logical_block_size(bdev);
if (!IS_ALIGNED(offset, sector_size))
return false;
if (!IS_ALIGNED(length, sector_size))
return false;
return true;
}
int __dax_zero_page_range(struct block_device *bdev, sector_t sector,
unsigned int offset, unsigned int length)
{
struct blk_dax_ctl dax = {
.sector = sector,
.size = PAGE_SIZE,
};
if (dax_range_is_aligned(bdev, offset, length)) {
sector_t start_sector = dax.sector + (offset >> 9);
return blkdev_issue_zeroout(bdev, start_sector,
length >> 9, GFP_NOFS, true);
} else {
if (dax_map_atomic(bdev, &dax) < 0)
return PTR_ERR(dax.addr);
clear_pmem(dax.addr + offset, length);
dax_unmap_atomic(bdev, &dax);
}
return 0;
}
static sector_t dax_iomap_sector(struct iomap *iomap, loff_t pos)
{
return iomap->blkno + (((pos & PAGE_MASK) - iomap->offset) >> 9);
}
static loff_t
dax_iomap_actor(struct inode *inode, loff_t pos, loff_t length, void *data,
struct iomap *iomap)
{
struct iov_iter *iter = data;
loff_t end = pos + length, done = 0;
ssize_t ret = 0;
if (iov_iter_rw(iter) == READ) {
end = min(end, i_size_read(inode));
if (pos >= end)
return 0;
if (iomap->type == IOMAP_HOLE || iomap->type == IOMAP_UNWRITTEN)
return iov_iter_zero(min(length, end - pos), iter);
}
if (WARN_ON_ONCE(iomap->type != IOMAP_MAPPED))
return -EIO;
if ((iomap->flags & IOMAP_F_NEW) && inode->i_mapping->nrpages) {
invalidate_inode_pages2_range(inode->i_mapping,
pos >> PAGE_SHIFT,
(end - 1) >> PAGE_SHIFT);
}
while (pos < end) {
unsigned offset = pos & (PAGE_SIZE - 1);
struct blk_dax_ctl dax = { 0 };
ssize_t map_len;
if (fatal_signal_pending(current)) {
ret = -EINTR;
break;
}
dax.sector = dax_iomap_sector(iomap, pos);
dax.size = (length + offset + PAGE_SIZE - 1) & PAGE_MASK;
map_len = dax_map_atomic(iomap->bdev, &dax);
if (map_len < 0) {
ret = map_len;
break;
}
dax.addr += offset;
map_len -= offset;
if (map_len > end - pos)
map_len = end - pos;
if (iov_iter_rw(iter) == WRITE)
map_len = copy_from_iter_pmem(dax.addr, map_len, iter);
else
map_len = copy_to_iter(dax.addr, map_len, iter);
dax_unmap_atomic(iomap->bdev, &dax);
if (map_len <= 0) {
ret = map_len ? map_len : -EFAULT;
break;
}
pos += map_len;
length -= map_len;
done += map_len;
}
return done ? done : ret;
}
ssize_t
dax_iomap_rw(struct kiocb *iocb, struct iov_iter *iter,
struct iomap_ops *ops)
{
struct address_space *mapping = iocb->ki_filp->f_mapping;
struct inode *inode = mapping->host;
loff_t pos = iocb->ki_pos, ret = 0, done = 0;
unsigned flags = 0;
if (iov_iter_rw(iter) == WRITE)
flags |= IOMAP_WRITE;
while (iov_iter_count(iter)) {
ret = iomap_apply(inode, pos, iov_iter_count(iter), flags, ops,
iter, dax_iomap_actor);
if (ret <= 0)
break;
pos += ret;
done += ret;
}
iocb->ki_pos += done;
return done ? done : ret;
}
static int dax_fault_return(int error)
{
if (error == 0)
return VM_FAULT_NOPAGE;
if (error == -ENOMEM)
return VM_FAULT_OOM;
return VM_FAULT_SIGBUS;
}
int dax_iomap_fault(struct vm_area_struct *vma, struct vm_fault *vmf,
struct iomap_ops *ops)
{
struct address_space *mapping = vma->vm_file->f_mapping;
struct inode *inode = mapping->host;
unsigned long vaddr = vmf->address;
loff_t pos = (loff_t)vmf->pgoff << PAGE_SHIFT;
sector_t sector;
struct iomap iomap = { 0 };
unsigned flags = IOMAP_FAULT;
int error, major = 0;
int vmf_ret = 0;
void *entry;
if (pos >= i_size_read(inode))
return VM_FAULT_SIGBUS;
if ((vmf->flags & FAULT_FLAG_WRITE) && !vmf->cow_page)
flags |= IOMAP_WRITE;
error = ops->iomap_begin(inode, pos, PAGE_SIZE, flags, &iomap);
if (error)
return dax_fault_return(error);
if (WARN_ON_ONCE(iomap.offset + iomap.length < pos + PAGE_SIZE)) {
vmf_ret = dax_fault_return(-EIO);
goto finish_iomap;
}
entry = grab_mapping_entry(mapping, vmf->pgoff, 0);
if (IS_ERR(entry)) {
vmf_ret = dax_fault_return(PTR_ERR(entry));
goto finish_iomap;
}
sector = dax_iomap_sector(&iomap, pos);
if (vmf->cow_page) {
switch (iomap.type) {
case IOMAP_HOLE:
case IOMAP_UNWRITTEN:
clear_user_highpage(vmf->cow_page, vaddr);
break;
case IOMAP_MAPPED:
error = copy_user_dax(iomap.bdev, sector, PAGE_SIZE,
vmf->cow_page, vaddr);
break;
default:
WARN_ON_ONCE(1);
error = -EIO;
break;
}
if (error)
goto error_unlock_entry;
__SetPageUptodate(vmf->cow_page);
vmf_ret = finish_fault(vmf);
if (!vmf_ret)
vmf_ret = VM_FAULT_DONE_COW;
goto unlock_entry;
}
switch (iomap.type) {
case IOMAP_MAPPED:
if (iomap.flags & IOMAP_F_NEW) {
count_vm_event(PGMAJFAULT);
mem_cgroup_count_vm_event(vma->vm_mm, PGMAJFAULT);
major = VM_FAULT_MAJOR;
}
error = dax_insert_mapping(mapping, iomap.bdev, sector,
PAGE_SIZE, &entry, vma, vmf);
if (error == -EBUSY)
error = 0;
break;
case IOMAP_UNWRITTEN:
case IOMAP_HOLE:
if (!(vmf->flags & FAULT_FLAG_WRITE)) {
vmf_ret = dax_load_hole(mapping, &entry, vmf);
goto unlock_entry;
}
default:
WARN_ON_ONCE(1);
error = -EIO;
break;
}
error_unlock_entry:
vmf_ret = dax_fault_return(error) | major;
unlock_entry:
put_locked_mapping_entry(mapping, vmf->pgoff, entry);
finish_iomap:
if (ops->iomap_end) {
int copied = PAGE_SIZE;
if (vmf_ret & VM_FAULT_ERROR)
copied = 0;
ops->iomap_end(inode, pos, PAGE_SIZE, copied, flags, &iomap);
}
return vmf_ret;
}
static int dax_pmd_insert_mapping(struct vm_area_struct *vma, pmd_t *pmd,
struct vm_fault *vmf, unsigned long address,
struct iomap *iomap, loff_t pos, bool write, void **entryp)
{
struct address_space *mapping = vma->vm_file->f_mapping;
struct block_device *bdev = iomap->bdev;
struct blk_dax_ctl dax = {
.sector = dax_iomap_sector(iomap, pos),
.size = PMD_SIZE,
};
long length = dax_map_atomic(bdev, &dax);
void *ret;
if (length < 0)
return VM_FAULT_FALLBACK;
if (length < PMD_SIZE)
goto unmap_fallback;
if (pfn_t_to_pfn(dax.pfn) & PG_PMD_COLOUR)
goto unmap_fallback;
if (!pfn_t_devmap(dax.pfn))
goto unmap_fallback;
dax_unmap_atomic(bdev, &dax);
ret = dax_insert_mapping_entry(mapping, vmf, *entryp, dax.sector,
RADIX_DAX_PMD);
if (IS_ERR(ret))
return VM_FAULT_FALLBACK;
*entryp = ret;
return vmf_insert_pfn_pmd(vma, address, pmd, dax.pfn, write);
unmap_fallback:
dax_unmap_atomic(bdev, &dax);
return VM_FAULT_FALLBACK;
}
static int dax_pmd_load_hole(struct vm_area_struct *vma, pmd_t *pmd,
struct vm_fault *vmf, unsigned long address,
struct iomap *iomap, void **entryp)
{
struct address_space *mapping = vma->vm_file->f_mapping;
unsigned long pmd_addr = address & PMD_MASK;
struct page *zero_page;
spinlock_t *ptl;
pmd_t pmd_entry;
void *ret;
zero_page = mm_get_huge_zero_page(vma->vm_mm);
if (unlikely(!zero_page))
return VM_FAULT_FALLBACK;
ret = dax_insert_mapping_entry(mapping, vmf, *entryp, 0,
RADIX_DAX_PMD | RADIX_DAX_HZP);
if (IS_ERR(ret))
return VM_FAULT_FALLBACK;
*entryp = ret;
ptl = pmd_lock(vma->vm_mm, pmd);
if (!pmd_none(*pmd)) {
spin_unlock(ptl);
return VM_FAULT_FALLBACK;
}
pmd_entry = mk_pmd(zero_page, vma->vm_page_prot);
pmd_entry = pmd_mkhuge(pmd_entry);
set_pmd_at(vma->vm_mm, pmd_addr, pmd, pmd_entry);
spin_unlock(ptl);
return VM_FAULT_NOPAGE;
}
int dax_iomap_pmd_fault(struct vm_area_struct *vma, unsigned long address,
pmd_t *pmd, unsigned int flags, struct iomap_ops *ops)
{
struct address_space *mapping = vma->vm_file->f_mapping;
unsigned long pmd_addr = address & PMD_MASK;
bool write = flags & FAULT_FLAG_WRITE;
unsigned int iomap_flags = (write ? IOMAP_WRITE : 0) | IOMAP_FAULT;
struct inode *inode = mapping->host;
int result = VM_FAULT_FALLBACK;
struct iomap iomap = { 0 };
pgoff_t max_pgoff, pgoff;
struct vm_fault vmf;
void *entry;
loff_t pos;
int error;
if (write && !(vma->vm_flags & VM_SHARED))
goto fallback;
if (pmd_addr < vma->vm_start)
goto fallback;
if ((pmd_addr + PMD_SIZE) > vma->vm_end)
goto fallback;
pgoff = linear_page_index(vma, pmd_addr);
max_pgoff = (i_size_read(inode) - 1) >> PAGE_SHIFT;
if (pgoff > max_pgoff)
return VM_FAULT_SIGBUS;
if ((pgoff | PG_PMD_COLOUR) > max_pgoff)
goto fallback;
pos = (loff_t)pgoff << PAGE_SHIFT;
error = ops->iomap_begin(inode, pos, PMD_SIZE, iomap_flags, &iomap);
if (error)
goto fallback;
if (iomap.offset + iomap.length < pos + PMD_SIZE)
goto finish_iomap;
entry = grab_mapping_entry(mapping, pgoff, RADIX_DAX_PMD);
if (IS_ERR(entry))
goto finish_iomap;
vmf.pgoff = pgoff;
vmf.flags = flags;
vmf.gfp_mask = mapping_gfp_mask(mapping) | __GFP_IO;
switch (iomap.type) {
case IOMAP_MAPPED:
result = dax_pmd_insert_mapping(vma, pmd, &vmf, address,
&iomap, pos, write, &entry);
break;
case IOMAP_UNWRITTEN:
case IOMAP_HOLE:
if (WARN_ON_ONCE(write))
goto unlock_entry;
result = dax_pmd_load_hole(vma, pmd, &vmf, address, &iomap,
&entry);
break;
default:
WARN_ON_ONCE(1);
break;
}
unlock_entry:
put_locked_mapping_entry(mapping, pgoff, entry);
finish_iomap:
if (ops->iomap_end) {
int copied = PMD_SIZE;
if (result == VM_FAULT_FALLBACK)
copied = 0;
ops->iomap_end(inode, pos, PMD_SIZE, copied, iomap_flags,
&iomap);
}
fallback:
if (result == VM_FAULT_FALLBACK) {
split_huge_pmd(vma, pmd, address);
count_vm_event(THP_FAULT_FALLBACK);
}
return result;
}
