static long dax_map_atomic(struct block_device *bdev, struct blk_dax_ctl *dax)
{
struct request_queue *q = bdev->bd_queue;
long rc = -EIO;
dax->addr = (void __pmem *) ERR_PTR(-EIO);
if (blk_queue_enter(q, true) != 0)
return rc;
rc = bdev_direct_access(bdev, dax);
if (rc < 0) {
dax->addr = (void __pmem *) ERR_PTR(rc);
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
int dax_clear_sectors(struct block_device *bdev, sector_t _sector, long _size)
{
struct blk_dax_ctl dax = {
.sector = _sector,
.size = _size,
};
might_sleep();
do {
long count, sz;
count = dax_map_atomic(bdev, &dax);
if (count < 0)
return count;
sz = min_t(long, count, SZ_128K);
clear_pmem(dax.addr, sz);
dax.size -= sz;
dax.sector += sz / 512;
dax_unmap_atomic(bdev, &dax);
cond_resched();
} while (dax.size);
wmb_pmem();
return 0;
}
static void dax_new_buf(void __pmem *addr, unsigned size, unsigned first,
loff_t pos, loff_t end)
{
loff_t final = end - pos + first;
if (first > 0)
clear_pmem(addr, first);
if (final < size)
clear_pmem(addr + final, size - final);
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
bool hole = false, need_wmb = false;
struct block_device *bdev = NULL;
int rw = iov_iter_rw(iter), rc;
long map_len = 0;
struct blk_dax_ctl dax = {
.addr = (void __pmem *) ERR_PTR(-EIO),
};
if (rw == READ)
end = min(end, i_size_read(inode));
while (pos < end) {
size_t len;
if (pos == max) {
unsigned blkbits = inode->i_blkbits;
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
if (buffer_unwritten(bh) || buffer_new(bh)) {
dax_new_buf(dax.addr, map_len, first,
pos, end);
need_wmb = true;
}
dax.addr += first;
size = map_len - first;
}
max = min(pos + size, end);
}
if (iov_iter_rw(iter) == WRITE) {
len = copy_from_iter_pmem(dax.addr, max - pos, iter);
need_wmb = true;
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
if (need_wmb)
wmb_pmem();
dax_unmap_atomic(bdev, &dax);
return (pos == start) ? rc : pos - start;
}
ssize_t dax_do_io(struct kiocb *iocb, struct inode *inode,
struct iov_iter *iter, loff_t pos, get_block_t get_block,
dio_iodone_t end_io, int flags)
{
struct buffer_head bh;
ssize_t retval = -EINVAL;
loff_t end = pos + iov_iter_count(iter);
memset(&bh, 0, sizeof(bh));
bh.b_bdev = inode->i_sb->s_bdev;
if ((flags & DIO_LOCKING) && iov_iter_rw(iter) == READ) {
struct address_space *mapping = inode->i_mapping;
inode_lock(inode);
retval = filemap_write_and_wait_range(mapping, pos, end - 1);
if (retval) {
inode_unlock(inode);
goto out;
}
}
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
out:
return retval;
}
static int dax_load_hole(struct address_space *mapping, struct page *page,
struct vm_fault *vmf)
{
unsigned long size;
struct inode *inode = mapping->host;
if (!page)
page = find_or_create_page(mapping, vmf->pgoff,
GFP_KERNEL | __GFP_ZERO);
if (!page)
return VM_FAULT_OOM;
size = (i_size_read(inode) + PAGE_SIZE - 1) >> PAGE_SHIFT;
if (vmf->pgoff >= size) {
unlock_page(page);
put_page(page);
return VM_FAULT_SIGBUS;
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
static int dax_radix_entry(struct address_space *mapping, pgoff_t index,
sector_t sector, bool pmd_entry, bool dirty)
{
struct radix_tree_root *page_tree = &mapping->page_tree;
pgoff_t pmd_index = DAX_PMD_INDEX(index);
int type, error = 0;
void *entry;
WARN_ON_ONCE(pmd_entry && !dirty);
if (dirty)
__mark_inode_dirty(mapping->host, I_DIRTY_PAGES);
spin_lock_irq(&mapping->tree_lock);
entry = radix_tree_lookup(page_tree, pmd_index);
if (entry && RADIX_DAX_TYPE(entry) == RADIX_DAX_PMD) {
index = pmd_index;
goto dirty;
}
entry = radix_tree_lookup(page_tree, index);
if (entry) {
type = RADIX_DAX_TYPE(entry);
if (WARN_ON_ONCE(type != RADIX_DAX_PTE &&
type != RADIX_DAX_PMD)) {
error = -EIO;
goto unlock;
}
if (!pmd_entry || type == RADIX_DAX_PMD)
goto dirty;
radix_tree_delete(&mapping->page_tree, index);
mapping->nrexceptional--;
}
if (sector == NO_SECTOR) {
goto unlock;
}
error = radix_tree_insert(page_tree, index,
RADIX_DAX_ENTRY(sector, pmd_entry));
if (error)
goto unlock;
mapping->nrexceptional++;
dirty:
if (dirty)
radix_tree_tag_set(page_tree, index, PAGECACHE_TAG_DIRTY);
unlock:
spin_unlock_irq(&mapping->tree_lock);
return error;
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
wmb_pmem();
return 0;
}
static int dax_insert_mapping(struct inode *inode, struct buffer_head *bh,
struct vm_area_struct *vma, struct vm_fault *vmf)
{
unsigned long vaddr = (unsigned long)vmf->virtual_address;
struct address_space *mapping = inode->i_mapping;
struct block_device *bdev = bh->b_bdev;
struct blk_dax_ctl dax = {
.sector = to_sector(bh, inode),
.size = bh->b_size,
};
pgoff_t size;
int error;
i_mmap_lock_read(mapping);
size = (i_size_read(inode) + PAGE_SIZE - 1) >> PAGE_SHIFT;
if (unlikely(vmf->pgoff >= size)) {
error = -EIO;
goto out;
}
if (dax_map_atomic(bdev, &dax) < 0) {
error = PTR_ERR(dax.addr);
goto out;
}
if (buffer_unwritten(bh) || buffer_new(bh)) {
clear_pmem(dax.addr, PAGE_SIZE);
wmb_pmem();
}
dax_unmap_atomic(bdev, &dax);
error = dax_radix_entry(mapping, vmf->pgoff, dax.sector, false,
vmf->flags & FAULT_FLAG_WRITE);
if (error)
goto out;
error = vm_insert_mixed(vma, vaddr, dax.pfn);
out:
i_mmap_unlock_read(mapping);
return error;
}
int __dax_fault(struct vm_area_struct *vma, struct vm_fault *vmf,
get_block_t get_block, dax_iodone_t complete_unwritten)
{
struct file *file = vma->vm_file;
struct address_space *mapping = file->f_mapping;
struct inode *inode = mapping->host;
struct page *page;
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
repeat:
page = find_get_page(mapping, vmf->pgoff);
if (page) {
if (!lock_page_or_retry(page, vma->vm_mm, vmf->flags)) {
put_page(page);
return VM_FAULT_RETRY;
}
if (unlikely(page->mapping != mapping)) {
unlock_page(page);
put_page(page);
goto repeat;
}
size = (i_size_read(inode) + PAGE_SIZE - 1) >> PAGE_SHIFT;
if (unlikely(vmf->pgoff >= size)) {
error = -EIO;
goto unlock_page;
}
}
error = get_block(inode, block, &bh, 0);
if (!error && (bh.b_size < PAGE_SIZE))
error = -EIO;
if (error)
goto unlock_page;
if (!buffer_mapped(&bh) && !buffer_unwritten(&bh) && !vmf->cow_page) {
if (vmf->flags & FAULT_FLAG_WRITE) {
error = get_block(inode, block, &bh, 1);
count_vm_event(PGMAJFAULT);
mem_cgroup_count_vm_event(vma->vm_mm, PGMAJFAULT);
major = VM_FAULT_MAJOR;
if (!error && (bh.b_size < PAGE_SIZE))
error = -EIO;
if (error)
goto unlock_page;
} else {
return dax_load_hole(mapping, page, vmf);
}
}
if (vmf->cow_page) {
struct page *new_page = vmf->cow_page;
if (buffer_written(&bh))
error = copy_user_bh(new_page, inode, &bh, vaddr);
else
clear_user_highpage(new_page, vaddr);
if (error)
goto unlock_page;
vmf->page = page;
if (!page) {
i_mmap_lock_read(mapping);
size = (i_size_read(inode) + PAGE_SIZE - 1) >>
PAGE_SHIFT;
if (vmf->pgoff >= size) {
i_mmap_unlock_read(mapping);
error = -EIO;
goto out;
}
}
return VM_FAULT_LOCKED;
}
if (!page && major)
page = find_lock_page(mapping, vmf->pgoff);
if (page) {
unmap_mapping_range(mapping, vmf->pgoff << PAGE_SHIFT,
PAGE_SIZE, 0);
delete_from_page_cache(page);
unlock_page(page);
put_page(page);
page = NULL;
}
error = dax_insert_mapping(inode, &bh, vma, vmf);
if (buffer_unwritten(&bh)) {
if (complete_unwritten)
complete_unwritten(&bh, !error);
else
WARN_ON_ONCE(!(vmf->flags & FAULT_FLAG_WRITE));
}
out:
if (error == -ENOMEM)
return VM_FAULT_OOM | major;
if ((error < 0) && (error != -EBUSY))
return VM_FAULT_SIGBUS | major;
return VM_FAULT_NOPAGE | major;
unlock_page:
if (page) {
unlock_page(page);
put_page(page);
}
goto out;
}
int dax_fault(struct vm_area_struct *vma, struct vm_fault *vmf,
get_block_t get_block, dax_iodone_t complete_unwritten)
{
int result;
struct super_block *sb = file_inode(vma->vm_file)->i_sb;
if (vmf->flags & FAULT_FLAG_WRITE) {
sb_start_pagefault(sb);
file_update_time(vma->vm_file);
}
result = __dax_fault(vma, vmf, get_block, complete_unwritten);
if (vmf->flags & FAULT_FLAG_WRITE)
sb_end_pagefault(sb);
return result;
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
int __dax_pmd_fault(struct vm_area_struct *vma, unsigned long address,
pmd_t *pmd, unsigned int flags, get_block_t get_block,
dax_iodone_t complete_unwritten)
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
int error, result = 0;
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
i_mmap_lock_read(mapping);
size = (i_size_read(inode) + PAGE_SIZE - 1) >> PAGE_SHIFT;
if (pgoff >= size) {
result = VM_FAULT_SIGBUS;
goto out;
}
if ((pgoff | PG_PMD_COLOUR) >= size) {
dax_pmd_dbg(&bh, address,
"offset + huge page size > file size");
goto fallback;
}
if (!write && !buffer_mapped(&bh) && buffer_uptodate(&bh)) {
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
result = VM_FAULT_SIGBUS;
goto out;
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
if (buffer_unwritten(&bh) || buffer_new(&bh)) {
clear_pmem(dax.addr, PMD_SIZE);
wmb_pmem();
count_vm_event(PGMAJFAULT);
mem_cgroup_count_vm_event(vma->vm_mm, PGMAJFAULT);
result |= VM_FAULT_MAJOR;
}
dax_unmap_atomic(bdev, &dax);
if (write) {
error = dax_radix_entry(mapping, pgoff, dax.sector,
true, true);
if (error) {
dax_pmd_dbg(&bh, address,
"PMD radix insertion failed");
goto fallback;
}
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
i_mmap_unlock_read(mapping);
if (buffer_unwritten(&bh))
complete_unwritten(&bh, !(result & VM_FAULT_ERROR));
return result;
fallback:
count_vm_event(THP_FAULT_FALLBACK);
result = VM_FAULT_FALLBACK;
goto out;
}
int dax_pmd_fault(struct vm_area_struct *vma, unsigned long address,
pmd_t *pmd, unsigned int flags, get_block_t get_block,
dax_iodone_t complete_unwritten)
{
int result;
struct super_block *sb = file_inode(vma->vm_file)->i_sb;
if (flags & FAULT_FLAG_WRITE) {
sb_start_pagefault(sb);
file_update_time(vma->vm_file);
}
result = __dax_pmd_fault(vma, address, pmd, flags, get_block,
complete_unwritten);
if (flags & FAULT_FLAG_WRITE)
sb_end_pagefault(sb);
return result;
}
int dax_pfn_mkwrite(struct vm_area_struct *vma, struct vm_fault *vmf)
{
struct file *file = vma->vm_file;
int error;
error = dax_radix_entry(file->f_mapping, vmf->pgoff, NO_SECTOR, false,
true);
if (error == -ENOMEM)
return VM_FAULT_OOM;
if (error)
return VM_FAULT_SIGBUS;
return VM_FAULT_NOPAGE;
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
if (err < 0)
return err;
if (buffer_written(&bh)) {
struct block_device *bdev = bh.b_bdev;
struct blk_dax_ctl dax = {
.sector = to_sector(&bh, inode),
.size = PAGE_SIZE,
};
if (dax_map_atomic(bdev, &dax) < 0)
return PTR_ERR(dax.addr);
clear_pmem(dax.addr + offset, length);
wmb_pmem();
dax_unmap_atomic(bdev, &dax);
}
return 0;
}
int dax_truncate_page(struct inode *inode, loff_t from, get_block_t get_block)
{
unsigned length = PAGE_ALIGN(from) - from;
return dax_zero_page_range(inode, from, length, get_block);
}
