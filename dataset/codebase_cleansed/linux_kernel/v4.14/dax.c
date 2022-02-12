static int __init init_dax_wait_table(void)
{
int i;
for (i = 0; i < DAX_WAIT_TABLE_ENTRIES; i++)
init_waitqueue_head(wait_table + i);
return 0;
}
static unsigned long dax_radix_sector(void *entry)
{
return (unsigned long)entry >> RADIX_DAX_SHIFT;
}
static void *dax_radix_locked_entry(sector_t sector, unsigned long flags)
{
return (void *)(RADIX_TREE_EXCEPTIONAL_ENTRY | flags |
((unsigned long)sector << RADIX_DAX_SHIFT) |
RADIX_DAX_ENTRY_LOCK);
}
static unsigned int dax_radix_order(void *entry)
{
if ((unsigned long)entry & RADIX_DAX_PMD)
return PMD_SHIFT - PAGE_SHIFT;
return 0;
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
return (unsigned long)entry & RADIX_DAX_ZERO_PAGE;
}
static int dax_is_empty_entry(void *entry)
{
return (unsigned long)entry & RADIX_DAX_EMPTY;
}
static wait_queue_head_t *dax_entry_waitqueue(struct address_space *mapping,
pgoff_t index, void *entry, struct exceptional_entry_key *key)
{
unsigned long hash;
if (dax_is_pmd_entry(entry))
index &= ~PG_PMD_COLOUR;
key->mapping = mapping;
key->entry_start = index;
hash = hash_long((unsigned long)mapping ^ index, DAX_WAIT_TABLE_BITS);
return wait_table + hash;
}
static int wake_exceptional_entry_func(wait_queue_entry_t *wait, unsigned int mode,
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
static void dax_wake_mapping_entry_waiter(struct address_space *mapping,
pgoff_t index, void *entry, bool wake_all)
{
struct exceptional_entry_key key;
wait_queue_head_t *wq;
wq = dax_entry_waitqueue(mapping, index, entry, &key);
if (waitqueue_active(wq))
__wake_up(wq, TASK_NORMAL, wake_all ? 0 : 1, &key);
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
if (!entry ||
WARN_ON_ONCE(!radix_tree_exceptional_entry(entry)) ||
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
pgoff_t index)
{
dax_unlock_mapping_entry(mapping, index);
}
static void put_unlocked_mapping_entry(struct address_space *mapping,
pgoff_t index, void *entry)
{
if (!entry)
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
if (WARN_ON_ONCE(entry && !radix_tree_exceptional_entry(entry))) {
entry = ERR_PTR(-EIO);
goto out_unlock;
}
if (entry) {
if (size_flag & RADIX_DAX_PMD) {
if (dax_is_pte_entry(entry)) {
put_unlocked_mapping_entry(mapping, index,
entry);
entry = ERR_PTR(-EEXIST);
goto out_unlock;
}
} else {
if (dax_is_pmd_entry(entry) &&
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
put_locked_mapping_entry(mapping, index);
return ERR_PTR(err);
}
spin_lock_irq(&mapping->tree_lock);
if (!entry) {
entry = __radix_tree_lookup(&mapping->page_tree, index,
NULL, &slot);
if (entry) {
radix_tree_preload_end();
spin_unlock_irq(&mapping->tree_lock);
goto restart;
}
}
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
return ERR_PTR(err);
}
mapping->nrexceptional++;
spin_unlock_irq(&mapping->tree_lock);
return entry;
}
entry = lock_slot(mapping, slot);
out_unlock:
spin_unlock_irq(&mapping->tree_lock);
return entry;
}
static int __dax_invalidate_mapping_entry(struct address_space *mapping,
pgoff_t index, bool trunc)
{
int ret = 0;
void *entry;
struct radix_tree_root *page_tree = &mapping->page_tree;
spin_lock_irq(&mapping->tree_lock);
entry = get_unlocked_mapping_entry(mapping, index, NULL);
if (!entry || WARN_ON_ONCE(!radix_tree_exceptional_entry(entry)))
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
int dax_invalidate_mapping_entry_sync(struct address_space *mapping,
pgoff_t index)
{
return __dax_invalidate_mapping_entry(mapping, index, false);
}
static int copy_user_dax(struct block_device *bdev, struct dax_device *dax_dev,
sector_t sector, size_t size, struct page *to,
unsigned long vaddr)
{
void *vto, *kaddr;
pgoff_t pgoff;
pfn_t pfn;
long rc;
int id;
rc = bdev_dax_pgoff(bdev, sector, size, &pgoff);
if (rc)
return rc;
id = dax_read_lock();
rc = dax_direct_access(dax_dev, pgoff, PHYS_PFN(size), &kaddr, &pfn);
if (rc < 0) {
dax_read_unlock(id);
return rc;
}
vto = kmap_atomic(to);
copy_user_page(vto, (void __force *)kaddr, vaddr, to);
kunmap_atomic(vto);
dax_read_unlock(id);
return 0;
}
static void *dax_insert_mapping_entry(struct address_space *mapping,
struct vm_fault *vmf,
void *entry, sector_t sector,
unsigned long flags)
{
struct radix_tree_root *page_tree = &mapping->page_tree;
void *new_entry;
pgoff_t index = vmf->pgoff;
if (vmf->flags & FAULT_FLAG_WRITE)
__mark_inode_dirty(mapping->host, I_DIRTY_PAGES);
if (dax_is_zero_entry(entry) && !(flags & RADIX_DAX_ZERO_PAGE)) {
if (dax_is_pmd_entry(entry))
unmap_mapping_range(mapping,
(vmf->pgoff << PAGE_SHIFT) & PMD_MASK,
PMD_SIZE, 0);
else
unmap_mapping_range(mapping, vmf->pgoff << PAGE_SHIFT,
PAGE_SIZE, 0);
}
spin_lock_irq(&mapping->tree_lock);
new_entry = dax_radix_locked_entry(sector, flags);
if (dax_is_zero_entry(entry) || dax_is_empty_entry(entry)) {
struct radix_tree_node *node;
void **slot;
void *ret;
ret = __radix_tree_lookup(page_tree, index, &node, &slot);
WARN_ON_ONCE(ret != entry);
__radix_tree_replace(page_tree, node, slot,
new_entry, NULL, NULL);
entry = new_entry;
}
if (vmf->flags & FAULT_FLAG_WRITE)
radix_tree_tag_set(page_tree, index, PAGECACHE_TAG_DIRTY);
spin_unlock_irq(&mapping->tree_lock);
return entry;
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
i_mmap_lock_read(mapping);
vma_interval_tree_foreach(vma, &mapping->i_mmap, index, index) {
unsigned long address, start, end;
cond_resched();
if (!(vma->vm_flags & VM_SHARED))
continue;
address = pgoff_address(index, vma);
if (follow_pte_pmd(vma->vm_mm, address, &start, &end, &ptep, &pmdp, &ptl))
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
mmu_notifier_invalidate_range(vma->vm_mm, start, end);
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
mmu_notifier_invalidate_range(vma->vm_mm, start, end);
unlock_pte:
pte_unmap_unlock(ptep, ptl);
}
mmu_notifier_invalidate_range_end(vma->vm_mm, start, end);
}
i_mmap_unlock_read(mapping);
}
static int dax_writeback_one(struct block_device *bdev,
struct dax_device *dax_dev, struct address_space *mapping,
pgoff_t index, void *entry)
{
struct radix_tree_root *page_tree = &mapping->page_tree;
void *entry2, **slot, *kaddr;
long ret = 0, id;
sector_t sector;
pgoff_t pgoff;
size_t size;
pfn_t pfn;
if (WARN_ON(!radix_tree_exceptional_entry(entry)))
return -EIO;
spin_lock_irq(&mapping->tree_lock);
entry2 = get_unlocked_mapping_entry(mapping, index, &slot);
if (!entry2 || WARN_ON_ONCE(!radix_tree_exceptional_entry(entry2)))
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
sector = dax_radix_sector(entry);
size = PAGE_SIZE << dax_radix_order(entry);
id = dax_read_lock();
ret = bdev_dax_pgoff(bdev, sector, size, &pgoff);
if (ret)
goto dax_unlock;
ret = dax_direct_access(dax_dev, pgoff, size / PAGE_SIZE, &kaddr, &pfn);
if (ret < 0)
goto dax_unlock;
if (WARN_ON_ONCE(ret < size / PAGE_SIZE)) {
ret = -EIO;
goto dax_unlock;
}
dax_mapping_entry_mkclean(mapping, index, pfn_t_to_pfn(pfn));
dax_flush(dax_dev, kaddr, size);
spin_lock_irq(&mapping->tree_lock);
radix_tree_tag_clear(page_tree, index, PAGECACHE_TAG_DIRTY);
spin_unlock_irq(&mapping->tree_lock);
trace_dax_writeback_one(mapping->host, index, size >> PAGE_SHIFT);
dax_unlock:
dax_read_unlock(id);
put_locked_mapping_entry(mapping, index);
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
struct dax_device *dax_dev;
struct pagevec pvec;
bool done = false;
int i, ret = 0;
if (WARN_ON_ONCE(inode->i_blkbits != PAGE_SHIFT))
return -EIO;
if (!mapping->nrexceptional || wbc->sync_mode != WB_SYNC_ALL)
return 0;
dax_dev = dax_get_by_host(bdev->bd_disk->disk_name);
if (!dax_dev)
return -EIO;
start_index = wbc->range_start >> PAGE_SHIFT;
end_index = wbc->range_end >> PAGE_SHIFT;
trace_dax_writeback_range(inode, start_index, end_index);
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
ret = dax_writeback_one(bdev, dax_dev, mapping,
indices[i], pvec.pages[i]);
if (ret < 0) {
mapping_set_error(mapping, ret);
goto out;
}
}
start_index = indices[pvec.nr - 1] + 1;
}
out:
put_dax(dax_dev);
trace_dax_writeback_range_done(inode, start_index, end_index);
return (ret < 0 ? ret : 0);
}
static int dax_insert_mapping(struct address_space *mapping,
struct block_device *bdev, struct dax_device *dax_dev,
sector_t sector, size_t size, void *entry,
struct vm_area_struct *vma, struct vm_fault *vmf)
{
unsigned long vaddr = vmf->address;
void *ret, *kaddr;
pgoff_t pgoff;
int id, rc;
pfn_t pfn;
rc = bdev_dax_pgoff(bdev, sector, size, &pgoff);
if (rc)
return rc;
id = dax_read_lock();
rc = dax_direct_access(dax_dev, pgoff, PHYS_PFN(size), &kaddr, &pfn);
if (rc < 0) {
dax_read_unlock(id);
return rc;
}
dax_read_unlock(id);
ret = dax_insert_mapping_entry(mapping, vmf, entry, sector, 0);
if (IS_ERR(ret))
return PTR_ERR(ret);
trace_dax_insert_mapping(mapping->host, vmf, ret);
if (vmf->flags & FAULT_FLAG_WRITE)
return vm_insert_mixed_mkwrite(vma, vaddr, pfn);
else
return vm_insert_mixed(vma, vaddr, pfn);
}
static int dax_load_hole(struct address_space *mapping, void *entry,
struct vm_fault *vmf)
{
struct inode *inode = mapping->host;
unsigned long vaddr = vmf->address;
int ret = VM_FAULT_NOPAGE;
struct page *zero_page;
void *entry2;
zero_page = ZERO_PAGE(0);
if (unlikely(!zero_page)) {
ret = VM_FAULT_OOM;
goto out;
}
entry2 = dax_insert_mapping_entry(mapping, vmf, entry, 0,
RADIX_DAX_ZERO_PAGE);
if (IS_ERR(entry2)) {
ret = VM_FAULT_SIGBUS;
goto out;
}
vm_insert_mixed(vmf->vma, vaddr, page_to_pfn_t(zero_page));
out:
trace_dax_load_hole(inode, vmf, ret);
return ret;
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
int __dax_zero_page_range(struct block_device *bdev,
struct dax_device *dax_dev, sector_t sector,
unsigned int offset, unsigned int size)
{
if (dax_range_is_aligned(bdev, offset, size)) {
sector_t start_sector = sector + (offset >> 9);
return blkdev_issue_zeroout(bdev, start_sector,
size >> 9, GFP_NOFS, 0);
} else {
pgoff_t pgoff;
long rc, id;
void *kaddr;
pfn_t pfn;
rc = bdev_dax_pgoff(bdev, sector, PAGE_SIZE, &pgoff);
if (rc)
return rc;
id = dax_read_lock();
rc = dax_direct_access(dax_dev, pgoff, 1, &kaddr,
&pfn);
if (rc < 0) {
dax_read_unlock(id);
return rc;
}
memset(kaddr + offset, 0, size);
dax_flush(dax_dev, kaddr + offset, size);
dax_read_unlock(id);
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
struct block_device *bdev = iomap->bdev;
struct dax_device *dax_dev = iomap->dax_dev;
struct iov_iter *iter = data;
loff_t end = pos + length, done = 0;
ssize_t ret = 0;
int id;
if (iov_iter_rw(iter) == READ) {
end = min(end, i_size_read(inode));
if (pos >= end)
return 0;
if (iomap->type == IOMAP_HOLE || iomap->type == IOMAP_UNWRITTEN)
return iov_iter_zero(min(length, end - pos), iter);
}
if (WARN_ON_ONCE(iomap->type != IOMAP_MAPPED))
return -EIO;
if (iomap->flags & IOMAP_F_NEW) {
invalidate_inode_pages2_range(inode->i_mapping,
pos >> PAGE_SHIFT,
(end - 1) >> PAGE_SHIFT);
}
id = dax_read_lock();
while (pos < end) {
unsigned offset = pos & (PAGE_SIZE - 1);
const size_t size = ALIGN(length + offset, PAGE_SIZE);
const sector_t sector = dax_iomap_sector(iomap, pos);
ssize_t map_len;
pgoff_t pgoff;
void *kaddr;
pfn_t pfn;
if (fatal_signal_pending(current)) {
ret = -EINTR;
break;
}
ret = bdev_dax_pgoff(bdev, sector, size, &pgoff);
if (ret)
break;
map_len = dax_direct_access(dax_dev, pgoff, PHYS_PFN(size),
&kaddr, &pfn);
if (map_len < 0) {
ret = map_len;
break;
}
map_len = PFN_PHYS(map_len);
kaddr += offset;
map_len -= offset;
if (map_len > end - pos)
map_len = end - pos;
if (iov_iter_rw(iter) == WRITE)
map_len = dax_copy_from_iter(dax_dev, pgoff, kaddr,
map_len, iter);
else
map_len = copy_to_iter(kaddr, map_len, iter);
if (map_len <= 0) {
ret = map_len ? map_len : -EFAULT;
break;
}
pos += map_len;
length -= map_len;
done += map_len;
}
dax_read_unlock(id);
return done ? done : ret;
}
ssize_t
dax_iomap_rw(struct kiocb *iocb, struct iov_iter *iter,
const struct iomap_ops *ops)
{
struct address_space *mapping = iocb->ki_filp->f_mapping;
struct inode *inode = mapping->host;
loff_t pos = iocb->ki_pos, ret = 0, done = 0;
unsigned flags = 0;
if (iov_iter_rw(iter) == WRITE) {
lockdep_assert_held_exclusive(&inode->i_rwsem);
flags |= IOMAP_WRITE;
} else {
lockdep_assert_held(&inode->i_rwsem);
}
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
static int dax_iomap_pte_fault(struct vm_fault *vmf,
const struct iomap_ops *ops)
{
struct address_space *mapping = vmf->vma->vm_file->f_mapping;
struct inode *inode = mapping->host;
unsigned long vaddr = vmf->address;
loff_t pos = (loff_t)vmf->pgoff << PAGE_SHIFT;
sector_t sector;
struct iomap iomap = { 0 };
unsigned flags = IOMAP_FAULT;
int error, major = 0;
int vmf_ret = 0;
void *entry;
trace_dax_pte_fault(inode, vmf, vmf_ret);
if (pos >= i_size_read(inode)) {
vmf_ret = VM_FAULT_SIGBUS;
goto out;
}
if ((vmf->flags & FAULT_FLAG_WRITE) && !vmf->cow_page)
flags |= IOMAP_WRITE;
entry = grab_mapping_entry(mapping, vmf->pgoff, 0);
if (IS_ERR(entry)) {
vmf_ret = dax_fault_return(PTR_ERR(entry));
goto out;
}
if (pmd_trans_huge(*vmf->pmd) || pmd_devmap(*vmf->pmd)) {
vmf_ret = VM_FAULT_NOPAGE;
goto unlock_entry;
}
error = ops->iomap_begin(inode, pos, PAGE_SIZE, flags, &iomap);
if (error) {
vmf_ret = dax_fault_return(error);
goto unlock_entry;
}
if (WARN_ON_ONCE(iomap.offset + iomap.length < pos + PAGE_SIZE)) {
error = -EIO;
goto error_finish_iomap;
}
sector = dax_iomap_sector(&iomap, pos);
if (vmf->cow_page) {
switch (iomap.type) {
case IOMAP_HOLE:
case IOMAP_UNWRITTEN:
clear_user_highpage(vmf->cow_page, vaddr);
break;
case IOMAP_MAPPED:
error = copy_user_dax(iomap.bdev, iomap.dax_dev,
sector, PAGE_SIZE, vmf->cow_page, vaddr);
break;
default:
WARN_ON_ONCE(1);
error = -EIO;
break;
}
if (error)
goto error_finish_iomap;
__SetPageUptodate(vmf->cow_page);
vmf_ret = finish_fault(vmf);
if (!vmf_ret)
vmf_ret = VM_FAULT_DONE_COW;
goto finish_iomap;
}
switch (iomap.type) {
case IOMAP_MAPPED:
if (iomap.flags & IOMAP_F_NEW) {
count_vm_event(PGMAJFAULT);
count_memcg_event_mm(vmf->vma->vm_mm, PGMAJFAULT);
major = VM_FAULT_MAJOR;
}
error = dax_insert_mapping(mapping, iomap.bdev, iomap.dax_dev,
sector, PAGE_SIZE, entry, vmf->vma, vmf);
if (error == -EBUSY)
error = 0;
break;
case IOMAP_UNWRITTEN:
case IOMAP_HOLE:
if (!(vmf->flags & FAULT_FLAG_WRITE)) {
vmf_ret = dax_load_hole(mapping, entry, vmf);
goto finish_iomap;
}
default:
WARN_ON_ONCE(1);
error = -EIO;
break;
}
error_finish_iomap:
vmf_ret = dax_fault_return(error) | major;
finish_iomap:
if (ops->iomap_end) {
int copied = PAGE_SIZE;
if (vmf_ret & VM_FAULT_ERROR)
copied = 0;
ops->iomap_end(inode, pos, PAGE_SIZE, copied, flags, &iomap);
}
unlock_entry:
put_locked_mapping_entry(mapping, vmf->pgoff);
out:
trace_dax_pte_fault_done(inode, vmf, vmf_ret);
return vmf_ret;
}
static int dax_pmd_insert_mapping(struct vm_fault *vmf, struct iomap *iomap,
loff_t pos, void *entry)
{
struct address_space *mapping = vmf->vma->vm_file->f_mapping;
const sector_t sector = dax_iomap_sector(iomap, pos);
struct dax_device *dax_dev = iomap->dax_dev;
struct block_device *bdev = iomap->bdev;
struct inode *inode = mapping->host;
const size_t size = PMD_SIZE;
void *ret = NULL, *kaddr;
long length = 0;
pgoff_t pgoff;
pfn_t pfn = {};
int id;
if (bdev_dax_pgoff(bdev, sector, size, &pgoff) != 0)
goto fallback;
id = dax_read_lock();
length = dax_direct_access(dax_dev, pgoff, PHYS_PFN(size), &kaddr, &pfn);
if (length < 0)
goto unlock_fallback;
length = PFN_PHYS(length);
if (length < size)
goto unlock_fallback;
if (pfn_t_to_pfn(pfn) & PG_PMD_COLOUR)
goto unlock_fallback;
if (!pfn_t_devmap(pfn))
goto unlock_fallback;
dax_read_unlock(id);
ret = dax_insert_mapping_entry(mapping, vmf, entry, sector,
RADIX_DAX_PMD);
if (IS_ERR(ret))
goto fallback;
trace_dax_pmd_insert_mapping(inode, vmf, length, pfn, ret);
return vmf_insert_pfn_pmd(vmf->vma, vmf->address, vmf->pmd,
pfn, vmf->flags & FAULT_FLAG_WRITE);
unlock_fallback:
dax_read_unlock(id);
fallback:
trace_dax_pmd_insert_mapping_fallback(inode, vmf, length, pfn, ret);
return VM_FAULT_FALLBACK;
}
static int dax_pmd_load_hole(struct vm_fault *vmf, struct iomap *iomap,
void *entry)
{
struct address_space *mapping = vmf->vma->vm_file->f_mapping;
unsigned long pmd_addr = vmf->address & PMD_MASK;
struct inode *inode = mapping->host;
struct page *zero_page;
void *ret = NULL;
spinlock_t *ptl;
pmd_t pmd_entry;
zero_page = mm_get_huge_zero_page(vmf->vma->vm_mm);
if (unlikely(!zero_page))
goto fallback;
ret = dax_insert_mapping_entry(mapping, vmf, entry, 0,
RADIX_DAX_PMD | RADIX_DAX_ZERO_PAGE);
if (IS_ERR(ret))
goto fallback;
ptl = pmd_lock(vmf->vma->vm_mm, vmf->pmd);
if (!pmd_none(*(vmf->pmd))) {
spin_unlock(ptl);
goto fallback;
}
pmd_entry = mk_pmd(zero_page, vmf->vma->vm_page_prot);
pmd_entry = pmd_mkhuge(pmd_entry);
set_pmd_at(vmf->vma->vm_mm, pmd_addr, vmf->pmd, pmd_entry);
spin_unlock(ptl);
trace_dax_pmd_load_hole(inode, vmf, zero_page, ret);
return VM_FAULT_NOPAGE;
fallback:
trace_dax_pmd_load_hole_fallback(inode, vmf, zero_page, ret);
return VM_FAULT_FALLBACK;
}
static int dax_iomap_pmd_fault(struct vm_fault *vmf,
const struct iomap_ops *ops)
{
struct vm_area_struct *vma = vmf->vma;
struct address_space *mapping = vma->vm_file->f_mapping;
unsigned long pmd_addr = vmf->address & PMD_MASK;
bool write = vmf->flags & FAULT_FLAG_WRITE;
unsigned int iomap_flags = (write ? IOMAP_WRITE : 0) | IOMAP_FAULT;
struct inode *inode = mapping->host;
int result = VM_FAULT_FALLBACK;
struct iomap iomap = { 0 };
pgoff_t max_pgoff, pgoff;
void *entry;
loff_t pos;
int error;
pgoff = linear_page_index(vma, pmd_addr);
max_pgoff = (i_size_read(inode) - 1) >> PAGE_SHIFT;
trace_dax_pmd_fault(inode, vmf, max_pgoff, 0);
if ((vmf->pgoff & PG_PMD_COLOUR) !=
((vmf->address >> PAGE_SHIFT) & PG_PMD_COLOUR))
goto fallback;
if (write && !(vma->vm_flags & VM_SHARED))
goto fallback;
if (pmd_addr < vma->vm_start)
goto fallback;
if ((pmd_addr + PMD_SIZE) > vma->vm_end)
goto fallback;
if (pgoff > max_pgoff) {
result = VM_FAULT_SIGBUS;
goto out;
}
if ((pgoff | PG_PMD_COLOUR) > max_pgoff)
goto fallback;
entry = grab_mapping_entry(mapping, pgoff, RADIX_DAX_PMD);
if (IS_ERR(entry))
goto fallback;
if (!pmd_none(*vmf->pmd) && !pmd_trans_huge(*vmf->pmd) &&
!pmd_devmap(*vmf->pmd)) {
result = 0;
goto unlock_entry;
}
pos = (loff_t)pgoff << PAGE_SHIFT;
error = ops->iomap_begin(inode, pos, PMD_SIZE, iomap_flags, &iomap);
if (error)
goto unlock_entry;
if (iomap.offset + iomap.length < pos + PMD_SIZE)
goto finish_iomap;
switch (iomap.type) {
case IOMAP_MAPPED:
result = dax_pmd_insert_mapping(vmf, &iomap, pos, entry);
break;
case IOMAP_UNWRITTEN:
case IOMAP_HOLE:
if (WARN_ON_ONCE(write))
break;
result = dax_pmd_load_hole(vmf, &iomap, entry);
break;
default:
WARN_ON_ONCE(1);
break;
}
finish_iomap:
if (ops->iomap_end) {
int copied = PMD_SIZE;
if (result == VM_FAULT_FALLBACK)
copied = 0;
ops->iomap_end(inode, pos, PMD_SIZE, copied, iomap_flags,
&iomap);
}
unlock_entry:
put_locked_mapping_entry(mapping, pgoff);
fallback:
if (result == VM_FAULT_FALLBACK) {
split_huge_pmd(vma, vmf->pmd, vmf->address);
count_vm_event(THP_FAULT_FALLBACK);
}
out:
trace_dax_pmd_fault_done(inode, vmf, max_pgoff, result);
return result;
}
static int dax_iomap_pmd_fault(struct vm_fault *vmf,
const struct iomap_ops *ops)
{
return VM_FAULT_FALLBACK;
}
int dax_iomap_fault(struct vm_fault *vmf, enum page_entry_size pe_size,
const struct iomap_ops *ops)
{
switch (pe_size) {
case PE_SIZE_PTE:
return dax_iomap_pte_fault(vmf, ops);
case PE_SIZE_PMD:
return dax_iomap_pmd_fault(vmf, ops);
default:
return VM_FAULT_FALLBACK;
}
}
