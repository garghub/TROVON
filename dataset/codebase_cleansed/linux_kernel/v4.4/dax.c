int dax_clear_blocks(struct inode *inode, sector_t block, long size)
{
struct block_device *bdev = inode->i_sb->s_bdev;
sector_t sector = block << (inode->i_blkbits - 9);
might_sleep();
do {
void __pmem *addr;
unsigned long pfn;
long count;
count = bdev_direct_access(bdev, sector, &addr, &pfn, size);
if (count < 0)
return count;
BUG_ON(size < count);
while (count > 0) {
unsigned pgsz = PAGE_SIZE - offset_in_page(addr);
if (pgsz > count)
pgsz = count;
clear_pmem(addr, pgsz);
addr += pgsz;
size -= pgsz;
count -= pgsz;
BUG_ON(pgsz & 511);
sector += pgsz / 512;
cond_resched();
}
} while (size);
wmb_pmem();
return 0;
}
static long dax_get_addr(struct buffer_head *bh, void __pmem **addr,
unsigned blkbits)
{
unsigned long pfn;
sector_t sector = bh->b_blocknr << (blkbits - 9);
return bdev_direct_access(bh->b_bdev, sector, addr, &pfn, bh->b_size);
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
static ssize_t dax_io(struct inode *inode, struct iov_iter *iter,
loff_t start, loff_t end, get_block_t get_block,
struct buffer_head *bh)
{
ssize_t retval = 0;
loff_t pos = start;
loff_t max = start;
loff_t bh_max = start;
void __pmem *addr;
bool hole = false;
bool need_wmb = false;
if (iov_iter_rw(iter) != WRITE)
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
retval = get_block(inode, block, bh,
iov_iter_rw(iter) == WRITE);
if (retval)
break;
if (!buffer_size_valid(bh))
bh->b_size = 1 << blkbits;
bh_max = pos - first + bh->b_size;
} else {
unsigned done = bh->b_size -
(bh_max - (pos - first));
bh->b_blocknr += done >> blkbits;
bh->b_size -= done;
}
hole = iov_iter_rw(iter) != WRITE && !buffer_written(bh);
if (hole) {
addr = NULL;
size = bh->b_size - first;
} else {
retval = dax_get_addr(bh, &addr, blkbits);
if (retval < 0)
break;
if (buffer_unwritten(bh) || buffer_new(bh)) {
dax_new_buf(addr, retval, first, pos,
end);
need_wmb = true;
}
addr += first;
size = retval - first;
}
max = min(pos + size, end);
}
if (iov_iter_rw(iter) == WRITE) {
len = copy_from_iter_pmem(addr, max - pos, iter);
need_wmb = true;
} else if (!hole)
len = copy_to_iter((void __force *)addr, max - pos,
iter);
else
len = iov_iter_zero(max - pos, iter);
if (!len) {
retval = -EFAULT;
break;
}
pos += len;
addr += len;
}
if (need_wmb)
wmb_pmem();
return (pos == start) ? retval : pos - start;
}
ssize_t dax_do_io(struct kiocb *iocb, struct inode *inode,
struct iov_iter *iter, loff_t pos, get_block_t get_block,
dio_iodone_t end_io, int flags)
{
struct buffer_head bh;
ssize_t retval = -EINVAL;
loff_t end = pos + iov_iter_count(iter);
memset(&bh, 0, sizeof(bh));
if ((flags & DIO_LOCKING) && iov_iter_rw(iter) == READ) {
struct address_space *mapping = inode->i_mapping;
mutex_lock(&inode->i_mutex);
retval = filemap_write_and_wait_range(mapping, pos, end - 1);
if (retval) {
mutex_unlock(&inode->i_mutex);
goto out;
}
}
if (!(flags & DIO_SKIP_DIO_COUNT))
inode_dio_begin(inode);
retval = dax_io(inode, iter, pos, end, get_block, &bh);
if ((flags & DIO_LOCKING) && iov_iter_rw(iter) == READ)
mutex_unlock(&inode->i_mutex);
if ((retval > 0) && end_io)
end_io(iocb, pos, retval, bh.b_private);
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
page_cache_release(page);
return VM_FAULT_SIGBUS;
}
vmf->page = page;
return VM_FAULT_LOCKED;
}
static int copy_user_bh(struct page *to, struct buffer_head *bh,
unsigned blkbits, unsigned long vaddr)
{
void __pmem *vfrom;
void *vto;
if (dax_get_addr(bh, &vfrom, blkbits) < 0)
return -EIO;
vto = kmap_atomic(to);
copy_user_page(vto, (void __force *)vfrom, vaddr, to);
kunmap_atomic(vto);
return 0;
}
static int dax_insert_mapping(struct inode *inode, struct buffer_head *bh,
struct vm_area_struct *vma, struct vm_fault *vmf)
{
struct address_space *mapping = inode->i_mapping;
sector_t sector = bh->b_blocknr << (inode->i_blkbits - 9);
unsigned long vaddr = (unsigned long)vmf->virtual_address;
void __pmem *addr;
unsigned long pfn;
pgoff_t size;
int error;
i_mmap_lock_read(mapping);
size = (i_size_read(inode) + PAGE_SIZE - 1) >> PAGE_SHIFT;
if (unlikely(vmf->pgoff >= size)) {
error = -EIO;
goto out;
}
error = bdev_direct_access(bh->b_bdev, sector, &addr, &pfn, bh->b_size);
if (error < 0)
goto out;
if (error < PAGE_SIZE) {
error = -EIO;
goto out;
}
if (buffer_unwritten(bh) || buffer_new(bh)) {
clear_pmem(addr, PAGE_SIZE);
wmb_pmem();
}
error = vm_insert_mixed(vma, vaddr, pfn);
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
bh.b_size = PAGE_SIZE;
repeat:
page = find_get_page(mapping, vmf->pgoff);
if (page) {
if (!lock_page_or_retry(page, vma->vm_mm, vmf->flags)) {
page_cache_release(page);
return VM_FAULT_RETRY;
}
if (unlikely(page->mapping != mapping)) {
unlock_page(page);
page_cache_release(page);
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
error = copy_user_bh(new_page, &bh, blkbits, vaddr);
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
PAGE_CACHE_SIZE, 0);
delete_from_page_cache(page);
unlock_page(page);
page_cache_release(page);
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
page_cache_release(page);
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
long length;
void __pmem *kaddr;
pgoff_t size, pgoff;
sector_t block, sector;
unsigned long pfn;
int result = 0;
if (!IS_ENABLED(CONFIG_FS_DAX_PMD))
return VM_FAULT_FALLBACK;
if (write && !(vma->vm_flags & VM_SHARED))
return VM_FAULT_FALLBACK;
if (pmd_addr < vma->vm_start)
return VM_FAULT_FALLBACK;
if ((pmd_addr + PMD_SIZE) > vma->vm_end)
return VM_FAULT_FALLBACK;
pgoff = linear_page_index(vma, pmd_addr);
size = (i_size_read(inode) + PAGE_SIZE - 1) >> PAGE_SHIFT;
if (pgoff >= size)
return VM_FAULT_SIGBUS;
if ((pgoff | PG_PMD_COLOUR) >= size)
return VM_FAULT_FALLBACK;
memset(&bh, 0, sizeof(bh));
block = (sector_t)pgoff << (PAGE_SHIFT - blkbits);
bh.b_size = PMD_SIZE;
length = get_block(inode, block, &bh, write);
if (length)
return VM_FAULT_SIGBUS;
i_mmap_lock_read(mapping);
if (!buffer_size_valid(&bh) || bh.b_size < PMD_SIZE)
goto fallback;
if (buffer_new(&bh)) {
i_mmap_unlock_read(mapping);
unmap_mapping_range(mapping, pgoff << PAGE_SHIFT, PMD_SIZE, 0);
i_mmap_lock_read(mapping);
}
size = (i_size_read(inode) + PAGE_SIZE - 1) >> PAGE_SHIFT;
if (pgoff >= size) {
result = VM_FAULT_SIGBUS;
goto out;
}
if ((pgoff | PG_PMD_COLOUR) >= size)
goto fallback;
if (!write && !buffer_mapped(&bh) && buffer_uptodate(&bh)) {
spinlock_t *ptl;
pmd_t entry;
struct page *zero_page = get_huge_zero_page();
if (unlikely(!zero_page))
goto fallback;
ptl = pmd_lock(vma->vm_mm, pmd);
if (!pmd_none(*pmd)) {
spin_unlock(ptl);
goto fallback;
}
entry = mk_pmd(zero_page, vma->vm_page_prot);
entry = pmd_mkhuge(entry);
set_pmd_at(vma->vm_mm, pmd_addr, pmd, entry);
result = VM_FAULT_NOPAGE;
spin_unlock(ptl);
} else {
sector = bh.b_blocknr << (blkbits - 9);
length = bdev_direct_access(bh.b_bdev, sector, &kaddr, &pfn,
bh.b_size);
if (length < 0) {
result = VM_FAULT_SIGBUS;
goto out;
}
if ((length < PMD_SIZE) || (pfn & PG_PMD_COLOUR))
goto fallback;
if (pfn_valid(pfn))
goto fallback;
if (buffer_unwritten(&bh) || buffer_new(&bh)) {
int i;
for (i = 0; i < PTRS_PER_PMD; i++)
clear_pmem(kaddr + i * PAGE_SIZE, PAGE_SIZE);
wmb_pmem();
count_vm_event(PGMAJFAULT);
mem_cgroup_count_vm_event(vma->vm_mm, PGMAJFAULT);
result |= VM_FAULT_MAJOR;
}
result |= vmf_insert_pfn_pmd(vma, address, pmd, pfn, write);
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
struct super_block *sb = file_inode(vma->vm_file)->i_sb;
sb_start_pagefault(sb);
file_update_time(vma->vm_file);
sb_end_pagefault(sb);
return VM_FAULT_NOPAGE;
}
int dax_zero_page_range(struct inode *inode, loff_t from, unsigned length,
get_block_t get_block)
{
struct buffer_head bh;
pgoff_t index = from >> PAGE_CACHE_SHIFT;
unsigned offset = from & (PAGE_CACHE_SIZE-1);
int err;
if (!length)
return 0;
BUG_ON((offset + length) > PAGE_CACHE_SIZE);
memset(&bh, 0, sizeof(bh));
bh.b_size = PAGE_CACHE_SIZE;
err = get_block(inode, index, &bh, 0);
if (err < 0)
return err;
if (buffer_written(&bh)) {
void __pmem *addr;
err = dax_get_addr(&bh, &addr, inode->i_blkbits);
if (err < 0)
return err;
clear_pmem(addr + offset, length);
wmb_pmem();
}
return 0;
}
int dax_truncate_page(struct inode *inode, loff_t from, get_block_t get_block)
{
unsigned length = PAGE_CACHE_ALIGN(from) - from;
return dax_zero_page_range(inode, from, length, get_block);
}
