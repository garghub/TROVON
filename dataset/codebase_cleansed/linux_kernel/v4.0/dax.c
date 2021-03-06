int dax_clear_blocks(struct inode *inode, sector_t block, long size)
{
struct block_device *bdev = inode->i_sb->s_bdev;
sector_t sector = block << (inode->i_blkbits - 9);
might_sleep();
do {
void *addr;
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
if (pgsz < PAGE_SIZE)
memset(addr, 0, pgsz);
else
clear_page(addr);
addr += pgsz;
size -= pgsz;
count -= pgsz;
BUG_ON(pgsz & 511);
sector += pgsz / 512;
cond_resched();
}
} while (size);
return 0;
}
static long dax_get_addr(struct buffer_head *bh, void **addr, unsigned blkbits)
{
unsigned long pfn;
sector_t sector = bh->b_blocknr << (blkbits - 9);
return bdev_direct_access(bh->b_bdev, sector, addr, &pfn, bh->b_size);
}
static void dax_new_buf(void *addr, unsigned size, unsigned first, loff_t pos,
loff_t end)
{
loff_t final = end - pos + first;
if (first > 0)
memset(addr, 0, first);
if (final < size)
memset(addr + final, 0, size - final);
}
static bool buffer_written(struct buffer_head *bh)
{
return buffer_mapped(bh) && !buffer_unwritten(bh);
}
static bool buffer_size_valid(struct buffer_head *bh)
{
return bh->b_state != 0;
}
static ssize_t dax_io(int rw, struct inode *inode, struct iov_iter *iter,
loff_t start, loff_t end, get_block_t get_block,
struct buffer_head *bh)
{
ssize_t retval = 0;
loff_t pos = start;
loff_t max = start;
loff_t bh_max = start;
void *addr;
bool hole = false;
if (rw != WRITE)
end = min(end, i_size_read(inode));
while (pos < end) {
unsigned len;
if (pos == max) {
unsigned blkbits = inode->i_blkbits;
sector_t block = pos >> blkbits;
unsigned first = pos - (block << blkbits);
long size;
if (pos == bh_max) {
bh->b_size = PAGE_ALIGN(end - pos);
bh->b_state = 0;
retval = get_block(inode, block, bh,
rw == WRITE);
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
hole = (rw != WRITE) && !buffer_written(bh);
if (hole) {
addr = NULL;
size = bh->b_size - first;
} else {
retval = dax_get_addr(bh, &addr, blkbits);
if (retval < 0)
break;
if (buffer_unwritten(bh) || buffer_new(bh))
dax_new_buf(addr, retval, first, pos,
end);
addr += first;
size = retval - first;
}
max = min(pos + size, end);
}
if (rw == WRITE)
len = copy_from_iter(addr, max - pos, iter);
else if (!hole)
len = copy_to_iter(addr, max - pos, iter);
else
len = iov_iter_zero(max - pos, iter);
if (!len)
break;
pos += len;
addr += len;
}
return (pos == start) ? retval : pos - start;
}
ssize_t dax_do_io(int rw, struct kiocb *iocb, struct inode *inode,
struct iov_iter *iter, loff_t pos,
get_block_t get_block, dio_iodone_t end_io, int flags)
{
struct buffer_head bh;
ssize_t retval = -EINVAL;
loff_t end = pos + iov_iter_count(iter);
memset(&bh, 0, sizeof(bh));
if ((flags & DIO_LOCKING) && (rw == READ)) {
struct address_space *mapping = inode->i_mapping;
mutex_lock(&inode->i_mutex);
retval = filemap_write_and_wait_range(mapping, pos, end - 1);
if (retval) {
mutex_unlock(&inode->i_mutex);
goto out;
}
}
atomic_inc(&inode->i_dio_count);
retval = dax_io(rw, inode, iter, pos, end, get_block, &bh);
if ((flags & DIO_LOCKING) && (rw == READ))
mutex_unlock(&inode->i_mutex);
if ((retval > 0) && end_io)
end_io(iocb, pos, retval, bh.b_private);
inode_dio_done(inode);
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
void *vfrom, *vto;
if (dax_get_addr(bh, &vfrom, blkbits) < 0)
return -EIO;
vto = kmap_atomic(to);
copy_user_page(vto, vfrom, vaddr, to);
kunmap_atomic(vto);
return 0;
}
static int dax_insert_mapping(struct inode *inode, struct buffer_head *bh,
struct vm_area_struct *vma, struct vm_fault *vmf)
{
struct address_space *mapping = inode->i_mapping;
sector_t sector = bh->b_blocknr << (inode->i_blkbits - 9);
unsigned long vaddr = (unsigned long)vmf->virtual_address;
void *addr;
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
if (buffer_unwritten(bh) || buffer_new(bh))
clear_page(addr);
error = vm_insert_mixed(vma, vaddr, pfn);
out:
i_mmap_unlock_read(mapping);
if (bh->b_end_io)
bh->b_end_io(bh, 1);
return error;
}
static int do_dax_fault(struct vm_area_struct *vma, struct vm_fault *vmf,
get_block_t get_block)
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
get_block_t get_block)
{
int result;
struct super_block *sb = file_inode(vma->vm_file)->i_sb;
if (vmf->flags & FAULT_FLAG_WRITE) {
sb_start_pagefault(sb);
file_update_time(vma->vm_file);
}
result = do_dax_fault(vma, vmf, get_block);
if (vmf->flags & FAULT_FLAG_WRITE)
sb_end_pagefault(sb);
return result;
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
void *addr;
err = dax_get_addr(&bh, &addr, inode->i_blkbits);
if (err < 0)
return err;
memset(addr + offset, 0, length);
}
return 0;
}
int dax_truncate_page(struct inode *inode, loff_t from, get_block_t get_block)
{
unsigned length = PAGE_CACHE_ALIGN(from) - from;
return dax_zero_page_range(inode, from, length, get_block);
}
