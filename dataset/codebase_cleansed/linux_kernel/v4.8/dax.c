static int __init init_dax_wait_table(void)
{
int i;
for (i = 0; i < DAX_WAIT_TABLE_ENTRIES; i++)
init_waitqueue_head(wait_table + i);
return 0;
}
static wait_queue_head_t *dax_entry_waitqueue(struct address_space *mapping,
pgoff_t index)
{
unsigned long hash = hash_long((unsigned long)mapping ^ index,
DAX_WAIT_TABLE_BITS);
return wait_table + hash;
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
static bool buffer_written(struct buffer_head *bh)
{
return buffer_mapped(bh) && !buffer_unwritten(bh);
}
static bool buffer_size_valid(struct buffer_head *bh)
{
return bh->b_state != 0;
}
static sector_t to_sector(const struct buffer_head *bh,
const struct inode *inode)
{
sector_t sector = bh->b_blocknr << (inode->i_blkbits - 9);
return sector;
}
static ssize_t dax_io(struct inode *inode, struct iov_iter *iter,
loff_t start, loff_t end, get_block_t get_block,
struct buffer_head *bh)
{
loff_t pos = start, max = start, bh_max = start;
bool hole = false;
struct block_device *bdev = NULL;
int rw = iov_iter_rw(iter), rc;
long map_len = 0;
struct blk_dax_ctl dax = {
.addr = ERR_PTR(-EIO),
};
unsigned blkbits = inode->i_blkbits;
sector_t file_blks = (i_size_read(inode) + (1 << blkbits) - 1)
>> blkbits;
if (rw == READ)
end = min(end, i_size_read(inode));
while (pos < end) {
size_t len;
if (pos == max) {
long page = pos >> PAGE_SHIFT;
sector_t block = page << (PAGE_SHIFT - blkbits);
unsigned first = pos - (block << blkbits);
long size;
if (pos == bh_max) {
bh->b_size = PAGE_ALIGN(end - pos);
bh->b_state = 0;
rc = get_block(inode, block, bh, rw == WRITE);
if (rc)
break;
if (!buffer_size_valid(bh))
bh->b_size = 1 << blkbits;
bh_max = pos - first + bh->b_size;
bdev = bh->b_bdev;
WARN_ON_ONCE(
(buffer_new(bh) && block < file_blks) ||
(rw == WRITE && buffer_unwritten(bh)));
} else {
unsigned done = bh->b_size -
(bh_max - (pos - first));
bh->b_blocknr += done >> blkbits;
bh->b_size -= done;
}
hole = rw == READ && !buffer_written(bh);
if (hole) {
size = bh->b_size - first;
} else {
dax_unmap_atomic(bdev, &dax);
dax.sector = to_sector(bh, inode);
dax.size = bh->b_size;
map_len = dax_map_atomic(bdev, &dax);
if (map_len < 0) {
rc = map_len;
break;
}
dax.addr += first;
size = map_len - first;
}
max = min_t(u64, pos + size, end);
}
if (iov_iter_rw(iter) == WRITE) {
len = copy_from_iter_pmem(dax.addr, max - pos, iter);
} else if (!hole)
len = copy_to_iter((void __force *) dax.addr, max - pos,
iter);
else
len = iov_iter_zero(max - pos, iter);
if (!len) {
rc = -EFAULT;
break;
}
pos += len;
if (!IS_ERR(dax.addr))
dax.addr += len;
}
dax_unmap_atomic(bdev, &dax);
return (pos == start) ? rc : pos - start;
}
ssize_t dax_do_io(struct kiocb *iocb, struct inode *inode,
struct iov_iter *iter, get_block_t get_block,
dio_iodone_t end_io, int flags)
{
struct buffer_head bh;
ssize_t retval = -EINVAL;
loff_t pos = iocb->ki_pos;
loff_t end = pos + iov_iter_count(iter);
memset(&bh, 0, sizeof(bh));
bh.b_bdev = inode->i_sb->s_bdev;
if ((flags & DIO_LOCKING) && iov_iter_rw(iter) == READ)
inode_lock(inode);
if (!(flags & DIO_SKIP_DIO_COUNT))
inode_dio_begin(inode);
retval = dax_io(inode, iter, pos, end, get_block, &bh);
if ((flags & DIO_LOCKING) && iov_iter_rw(iter) == READ)
inode_unlock(inode);
if (end_io) {
int err;
err = end_io(iocb, pos, retval, bh.b_private);
if (err)
retval = err;
}
if (!(flags & DIO_SKIP_DIO_COUNT))
inode_dio_end(inode);
return retval;
}
static int wake_exceptional_entry_func(wait_queue_t *wait, unsigned int mode,
int sync, void *keyp)
{
struct exceptional_entry_key *key = keyp;
struct wait_exceptional_entry_queue *ewait =
container_of(wait, struct wait_exceptional_entry_queue, wait);
if (key->mapping != ewait->key.mapping ||
key->index != ewait->key.index)
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
radix_tree_replace_slot(slot, (void *)entry);
return (void *)entry;
}
static inline void *unlock_slot(struct address_space *mapping, void **slot)
{
unsigned long entry = (unsigned long)
radix_tree_deref_slot_protected(slot, &mapping->tree_lock);
entry &= ~(unsigned long)RADIX_DAX_ENTRY_LOCK;
radix_tree_replace_slot(slot, (void *)entry);
return (void *)entry;
}
static void *get_unlocked_mapping_entry(struct address_space *mapping,
pgoff_t index, void ***slotp)
{
void *ret, **slot;
struct wait_exceptional_entry_queue ewait;
wait_queue_head_t *wq = dax_entry_waitqueue(mapping, index);
init_wait(&ewait.wait);
ewait.wait.func = wake_exceptional_entry_func;
ewait.key.mapping = mapping;
ewait.key.index = index;
for (;;) {
ret = __radix_tree_lookup(&mapping->page_tree, index, NULL,
&slot);
if (!ret || !radix_tree_exceptional_entry(ret) ||
!slot_locked(mapping, slot)) {
if (slotp)
*slotp = slot;
return ret;
}
prepare_to_wait_exclusive(wq, &ewait.wait,
TASK_UNINTERRUPTIBLE);
spin_unlock_irq(&mapping->tree_lock);
schedule();
finish_wait(wq, &ewait.wait);
spin_lock_irq(&mapping->tree_lock);
}
}
static void *grab_mapping_entry(struct address_space *mapping, pgoff_t index)
{
void *ret, **slot;
restart:
spin_lock_irq(&mapping->tree_lock);
ret = get_unlocked_mapping_entry(mapping, index, &slot);
if (!ret) {
int err;
spin_unlock_irq(&mapping->tree_lock);
err = radix_tree_preload(
mapping_gfp_mask(mapping) & ~__GFP_HIGHMEM);
if (err)
return ERR_PTR(err);
ret = (void *)(RADIX_TREE_EXCEPTIONAL_ENTRY |
RADIX_DAX_ENTRY_LOCK);
spin_lock_irq(&mapping->tree_lock);
err = radix_tree_insert(&mapping->page_tree, index, ret);
radix_tree_preload_end();
if (err) {
spin_unlock_irq(&mapping->tree_lock);
if (err == -EEXIST)
goto restart;
return ERR_PTR(err);
}
mapping->nrexceptional++;
spin_unlock_irq(&mapping->tree_lock);
return ret;
}
if (!radix_tree_exceptional_entry(ret)) {
struct page *page = ret;
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
ret = lock_slot(mapping, slot);
spin_unlock_irq(&mapping->tree_lock);
return ret;
}
void dax_wake_mapping_entry_waiter(struct address_space *mapping,
pgoff_t index, bool wake_all)
{
wait_queue_head_t *wq = dax_entry_waitqueue(mapping, index);
if (waitqueue_active(wq)) {
struct exceptional_entry_key key;
key.mapping = mapping;
key.index = index;
__wake_up(wq, TASK_NORMAL, wake_all ? 0 : 1, &key);
}
}
void dax_unlock_mapping_entry(struct address_space *mapping, pgoff_t index)
{
void *ret, **slot;
spin_lock_irq(&mapping->tree_lock);
ret = __radix_tree_lookup(&mapping->page_tree, index, NULL, &slot);
if (WARN_ON_ONCE(!ret || !radix_tree_exceptional_entry(ret) ||
!slot_locked(mapping, slot))) {
spin_unlock_irq(&mapping->tree_lock);
return;
}
unlock_slot(mapping, slot);
spin_unlock_irq(&mapping->tree_lock);
dax_wake_mapping_entry_waiter(mapping, index, false);
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
dax_wake_mapping_entry_waiter(mapping, index, false);
}
int dax_delete_mapping_entry(struct address_space *mapping, pgoff_t index)
{
void *entry;
spin_lock_irq(&mapping->tree_lock);
entry = get_unlocked_mapping_entry(mapping, index, NULL);
if (WARN_ON_ONCE(!entry || !radix_tree_exceptional_entry(entry))) {
spin_unlock_irq(&mapping->tree_lock);
return 0;
}
radix_tree_delete(&mapping->page_tree, index);
mapping->nrexceptional--;
spin_unlock_irq(&mapping->tree_lock);
dax_wake_mapping_entry_waiter(mapping, index, true);
return 1;
}
static int dax_load_hole(struct address_space *mapping, void *entry,
struct vm_fault *vmf)
{
struct page *page;
if (!radix_tree_exceptional_entry(entry)) {
vmf->page = entry;
return VM_FAULT_LOCKED;
}
page = find_or_create_page(mapping, vmf->pgoff,
vmf->gfp_mask | __GFP_ZERO);
if (!page) {
put_locked_mapping_entry(mapping, vmf->pgoff, entry);
return VM_FAULT_OOM;
}
vmf->page = page;
return VM_FAULT_LOCKED;
}
static int copy_user_bh(struct page *to, struct inode *inode,
struct buffer_head *bh, unsigned long vaddr)
{
struct blk_dax_ctl dax = {
.sector = to_sector(bh, inode),
.size = bh->b_size,
};
struct block_device *bdev = bh->b_bdev;
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
void *entry, sector_t sector)
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
}
spin_lock_irq(&mapping->tree_lock);
new_entry = (void *)((unsigned long)RADIX_DAX_ENTRY(sector, false) |
RADIX_DAX_ENTRY_LOCK);
if (hole_fill) {
__delete_from_page_cache(entry, NULL);
put_page(entry);
error = radix_tree_insert(page_tree, index, new_entry);
if (error) {
new_entry = ERR_PTR(error);
goto unlock;
}
mapping->nrexceptional++;
} else {
void **slot;
void *ret;
ret = __radix_tree_lookup(page_tree, index, NULL, &slot);
WARN_ON_ONCE(ret != entry);
radix_tree_replace_slot(slot, new_entry);
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
static int dax_writeback_one(struct block_device *bdev,
struct address_space *mapping, pgoff_t index, void *entry)
{
struct radix_tree_root *page_tree = &mapping->page_tree;
int type = RADIX_DAX_TYPE(entry);
struct radix_tree_node *node;
struct blk_dax_ctl dax;
void **slot;
int ret = 0;
spin_lock_irq(&mapping->tree_lock);
if (!__radix_tree_lookup(page_tree, index, &node, &slot))
goto unlock;
if (*slot != entry)
goto unlock;
if (!radix_tree_tag_get(page_tree, index, PAGECACHE_TAG_TOWRITE))
goto unlock;
if (WARN_ON_ONCE(type != RADIX_DAX_PTE && type != RADIX_DAX_PMD)) {
ret = -EIO;
goto unlock;
}
dax.sector = RADIX_DAX_SECTOR(entry);
dax.size = (type == RADIX_DAX_PMD ? PMD_SIZE : PAGE_SIZE);
spin_unlock_irq(&mapping->tree_lock);
ret = dax_map_atomic(bdev, &dax);
if (ret < 0)
return ret;
if (WARN_ON_ONCE(ret < dax.size)) {
ret = -EIO;
goto unmap;
}
wb_cache_pmem(dax.addr, dax.size);
spin_lock_irq(&mapping->tree_lock);
radix_tree_tag_clear(page_tree, index, PAGECACHE_TAG_TOWRITE);
spin_unlock_irq(&mapping->tree_lock);
unmap:
dax_unmap_atomic(bdev, &dax);
return ret;
unlock:
spin_unlock_irq(&mapping->tree_lock);
return ret;
}
int dax_writeback_mapping_range(struct address_space *mapping,
struct block_device *bdev, struct writeback_control *wbc)
{
struct inode *inode = mapping->host;
pgoff_t start_index, end_index, pmd_index;
pgoff_t indices[PAGEVEC_SIZE];
struct pagevec pvec;
bool done = false;
int i, ret = 0;
void *entry;
if (WARN_ON_ONCE(inode->i_blkbits != PAGE_SHIFT))
return -EIO;
if (!mapping->nrexceptional || wbc->sync_mode != WB_SYNC_ALL)
return 0;
start_index = wbc->range_start >> PAGE_SHIFT;
end_index = wbc->range_end >> PAGE_SHIFT;
pmd_index = DAX_PMD_INDEX(start_index);
rcu_read_lock();
entry = radix_tree_lookup(&mapping->page_tree, pmd_index);
rcu_read_unlock();
if (entry && RADIX_DAX_TYPE(entry) == RADIX_DAX_PMD)
start_index = pmd_index;
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
struct buffer_head *bh, void **entryp,
struct vm_area_struct *vma, struct vm_fault *vmf)
{
unsigned long vaddr = (unsigned long)vmf->virtual_address;
struct block_device *bdev = bh->b_bdev;
struct blk_dax_ctl dax = {
.sector = to_sector(bh, mapping->host),
.size = bh->b_size,
};
void *ret;
void *entry = *entryp;
if (dax_map_atomic(bdev, &dax) < 0)
return PTR_ERR(dax.addr);
dax_unmap_atomic(bdev, &dax);
ret = dax_insert_mapping_entry(mapping, vmf, entry, dax.sector);
if (IS_ERR(ret))
return PTR_ERR(ret);
*entryp = ret;
return vm_insert_mixed(vma, vaddr, dax.pfn);
}
int dax_fault(struct vm_area_struct *vma, struct vm_fault *vmf,
get_block_t get_block)
{
struct file *file = vma->vm_file;
struct address_space *mapping = file->f_mapping;
struct inode *inode = mapping->host;
void *entry;
struct buffer_head bh;
unsigned long vaddr = (unsigned long)vmf->virtual_address;
unsigned blkbits = inode->i_blkbits;
sector_t block;
pgoff_t size;
int error;
int major = 0;
size = (i_size_read(inode) + PAGE_SIZE - 1) >> PAGE_SHIFT;
if (vmf->pgoff >= size)
return VM_FAULT_SIGBUS;
memset(&bh, 0, sizeof(bh));
block = (sector_t)vmf->pgoff << (PAGE_SHIFT - blkbits);
bh.b_bdev = inode->i_sb->s_bdev;
bh.b_size = PAGE_SIZE;
entry = grab_mapping_entry(mapping, vmf->pgoff);
if (IS_ERR(entry)) {
error = PTR_ERR(entry);
goto out;
}
error = get_block(inode, block, &bh, 0);
if (!error && (bh.b_size < PAGE_SIZE))
error = -EIO;
if (error)
goto unlock_entry;
if (vmf->cow_page) {
struct page *new_page = vmf->cow_page;
if (buffer_written(&bh))
error = copy_user_bh(new_page, inode, &bh, vaddr);
else
clear_user_highpage(new_page, vaddr);
if (error)
goto unlock_entry;
if (!radix_tree_exceptional_entry(entry)) {
vmf->page = entry;
return VM_FAULT_LOCKED;
}
vmf->entry = entry;
return VM_FAULT_DAX_LOCKED;
}
if (!buffer_mapped(&bh)) {
if (vmf->flags & FAULT_FLAG_WRITE) {
error = get_block(inode, block, &bh, 1);
count_vm_event(PGMAJFAULT);
mem_cgroup_count_vm_event(vma->vm_mm, PGMAJFAULT);
major = VM_FAULT_MAJOR;
if (!error && (bh.b_size < PAGE_SIZE))
error = -EIO;
if (error)
goto unlock_entry;
} else {
return dax_load_hole(mapping, entry, vmf);
}
}
WARN_ON_ONCE(buffer_unwritten(&bh) || buffer_new(&bh));
error = dax_insert_mapping(mapping, &bh, &entry, vma, vmf);
unlock_entry:
put_locked_mapping_entry(mapping, vmf->pgoff, entry);
out:
if (error == -ENOMEM)
return VM_FAULT_OOM | major;
if ((error < 0) && (error != -EBUSY))
return VM_FAULT_SIGBUS | major;
return VM_FAULT_NOPAGE | major;
}
static void __dax_dbg(struct buffer_head *bh, unsigned long address,
const char *reason, const char *fn)
{
if (bh) {
char bname[BDEVNAME_SIZE];
bdevname(bh->b_bdev, bname);
pr_debug("%s: %s addr: %lx dev %s state %lx start %lld "
"length %zd fallback: %s\n", fn, current->comm,
address, bname, bh->b_state, (u64)bh->b_blocknr,
bh->b_size, reason);
} else {
pr_debug("%s: %s addr: %lx fallback: %s\n", fn,
current->comm, address, reason);
}
}
int dax_pmd_fault(struct vm_area_struct *vma, unsigned long address,
pmd_t *pmd, unsigned int flags, get_block_t get_block)
{
struct file *file = vma->vm_file;
struct address_space *mapping = file->f_mapping;
struct inode *inode = mapping->host;
struct buffer_head bh;
unsigned blkbits = inode->i_blkbits;
unsigned long pmd_addr = address & PMD_MASK;
bool write = flags & FAULT_FLAG_WRITE;
struct block_device *bdev;
pgoff_t size, pgoff;
sector_t block;
int result = 0;
bool alloc = false;
if (!IS_ENABLED(CONFIG_FS_DAX_PMD))
return VM_FAULT_FALLBACK;
if (write && !(vma->vm_flags & VM_SHARED)) {
split_huge_pmd(vma, pmd, address);
dax_pmd_dbg(NULL, address, "cow write");
return VM_FAULT_FALLBACK;
}
if (pmd_addr < vma->vm_start) {
dax_pmd_dbg(NULL, address, "vma start unaligned");
return VM_FAULT_FALLBACK;
}
if ((pmd_addr + PMD_SIZE) > vma->vm_end) {
dax_pmd_dbg(NULL, address, "vma end unaligned");
return VM_FAULT_FALLBACK;
}
pgoff = linear_page_index(vma, pmd_addr);
size = (i_size_read(inode) + PAGE_SIZE - 1) >> PAGE_SHIFT;
if (pgoff >= size)
return VM_FAULT_SIGBUS;
if ((pgoff | PG_PMD_COLOUR) >= size) {
dax_pmd_dbg(NULL, address,
"offset + huge page size > file size");
return VM_FAULT_FALLBACK;
}
memset(&bh, 0, sizeof(bh));
bh.b_bdev = inode->i_sb->s_bdev;
block = (sector_t)pgoff << (PAGE_SHIFT - blkbits);
bh.b_size = PMD_SIZE;
if (get_block(inode, block, &bh, 0) != 0)
return VM_FAULT_SIGBUS;
if (!buffer_mapped(&bh) && write) {
if (get_block(inode, block, &bh, 1) != 0)
return VM_FAULT_SIGBUS;
alloc = true;
WARN_ON_ONCE(buffer_unwritten(&bh) || buffer_new(&bh));
}
bdev = bh.b_bdev;
if (!buffer_size_valid(&bh) || bh.b_size < PMD_SIZE) {
dax_pmd_dbg(&bh, address, "allocated block too small");
return VM_FAULT_FALLBACK;
}
if (alloc) {
loff_t lstart = pgoff << PAGE_SHIFT;
loff_t lend = lstart + PMD_SIZE - 1;
truncate_pagecache_range(inode, lstart, lend);
}
if (!write && !buffer_mapped(&bh)) {
spinlock_t *ptl;
pmd_t entry;
struct page *zero_page = get_huge_zero_page();
if (unlikely(!zero_page)) {
dax_pmd_dbg(&bh, address, "no zero page");
goto fallback;
}
ptl = pmd_lock(vma->vm_mm, pmd);
if (!pmd_none(*pmd)) {
spin_unlock(ptl);
dax_pmd_dbg(&bh, address, "pmd already present");
goto fallback;
}
dev_dbg(part_to_dev(bdev->bd_part),
"%s: %s addr: %lx pfn: <zero> sect: %llx\n",
__func__, current->comm, address,
(unsigned long long) to_sector(&bh, inode));
entry = mk_pmd(zero_page, vma->vm_page_prot);
entry = pmd_mkhuge(entry);
set_pmd_at(vma->vm_mm, pmd_addr, pmd, entry);
result = VM_FAULT_NOPAGE;
spin_unlock(ptl);
} else {
struct blk_dax_ctl dax = {
.sector = to_sector(&bh, inode),
.size = PMD_SIZE,
};
long length = dax_map_atomic(bdev, &dax);
if (length < 0) {
dax_pmd_dbg(&bh, address, "dax-error fallback");
goto fallback;
}
if (length < PMD_SIZE) {
dax_pmd_dbg(&bh, address, "dax-length too small");
dax_unmap_atomic(bdev, &dax);
goto fallback;
}
if (pfn_t_to_pfn(dax.pfn) & PG_PMD_COLOUR) {
dax_pmd_dbg(&bh, address, "pfn unaligned");
dax_unmap_atomic(bdev, &dax);
goto fallback;
}
if (!pfn_t_devmap(dax.pfn)) {
dax_unmap_atomic(bdev, &dax);
dax_pmd_dbg(&bh, address, "pfn not in memmap");
goto fallback;
}
dax_unmap_atomic(bdev, &dax);
if (write) {
}
dev_dbg(part_to_dev(bdev->bd_part),
"%s: %s addr: %lx pfn: %lx sect: %llx\n",
__func__, current->comm, address,
pfn_t_to_pfn(dax.pfn),
(unsigned long long) dax.sector);
result |= vmf_insert_pfn_pmd(vma, address, pmd,
dax.pfn, write);
}
out:
return result;
fallback:
count_vm_event(THP_FAULT_FALLBACK);
result = VM_FAULT_FALLBACK;
goto out;
}
int dax_pfn_mkwrite(struct vm_area_struct *vma, struct vm_fault *vmf)
{
struct file *file = vma->vm_file;
struct address_space *mapping = file->f_mapping;
void *entry;
pgoff_t index = vmf->pgoff;
spin_lock_irq(&mapping->tree_lock);
entry = get_unlocked_mapping_entry(mapping, index, NULL);
if (!entry || !radix_tree_exceptional_entry(entry))
goto out;
radix_tree_tag_set(&mapping->page_tree, index, PAGECACHE_TAG_DIRTY);
put_unlocked_mapping_entry(mapping, index, entry);
out:
spin_unlock_irq(&mapping->tree_lock);
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
int dax_zero_page_range(struct inode *inode, loff_t from, unsigned length,
get_block_t get_block)
{
struct buffer_head bh;
pgoff_t index = from >> PAGE_SHIFT;
unsigned offset = from & (PAGE_SIZE-1);
int err;
if (!length)
return 0;
BUG_ON((offset + length) > PAGE_SIZE);
memset(&bh, 0, sizeof(bh));
bh.b_bdev = inode->i_sb->s_bdev;
bh.b_size = PAGE_SIZE;
err = get_block(inode, index, &bh, 0);
if (err < 0 || !buffer_written(&bh))
return err;
return __dax_zero_page_range(bh.b_bdev, to_sector(&bh, inode),
offset, length);
}
int dax_truncate_page(struct inode *inode, loff_t from, get_block_t get_block)
{
unsigned length = PAGE_ALIGN(from) - from;
return dax_zero_page_range(inode, from, length, get_block);
}
