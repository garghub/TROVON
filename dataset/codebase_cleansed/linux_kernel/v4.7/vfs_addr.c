static int v9fs_fid_readpage(struct p9_fid *fid, struct page *page)
{
struct inode *inode = page->mapping->host;
struct bio_vec bvec = {.bv_page = page, .bv_len = PAGE_SIZE};
struct iov_iter to;
int retval, err;
p9_debug(P9_DEBUG_VFS, "\n");
BUG_ON(!PageLocked(page));
retval = v9fs_readpage_from_fscache(inode, page);
if (retval == 0)
return retval;
iov_iter_bvec(&to, ITER_BVEC | READ, &bvec, 1, PAGE_SIZE);
retval = p9_client_read(fid, page_offset(page), &to, &err);
if (err) {
v9fs_uncache_page(inode, page);
retval = err;
goto done;
}
zero_user(page, retval, PAGE_SIZE - retval);
flush_dcache_page(page);
SetPageUptodate(page);
v9fs_readpage_to_fscache(inode, page);
retval = 0;
done:
unlock_page(page);
return retval;
}
static int v9fs_vfs_readpage(struct file *filp, struct page *page)
{
return v9fs_fid_readpage(filp->private_data, page);
}
static int v9fs_vfs_readpages(struct file *filp, struct address_space *mapping,
struct list_head *pages, unsigned nr_pages)
{
int ret = 0;
struct inode *inode;
inode = mapping->host;
p9_debug(P9_DEBUG_VFS, "inode: %p file: %p\n", inode, filp);
ret = v9fs_readpages_from_fscache(inode, mapping, pages, &nr_pages);
if (ret == 0)
return ret;
ret = read_cache_pages(mapping, pages, (void *)v9fs_vfs_readpage, filp);
p9_debug(P9_DEBUG_VFS, " = %d\n", ret);
return ret;
}
static int v9fs_release_page(struct page *page, gfp_t gfp)
{
if (PagePrivate(page))
return 0;
return v9fs_fscache_release_page(page, gfp);
}
static void v9fs_invalidate_page(struct page *page, unsigned int offset,
unsigned int length)
{
if (offset == 0 && length == PAGE_SIZE)
v9fs_fscache_invalidate_page(page);
}
static int v9fs_vfs_writepage_locked(struct page *page)
{
struct inode *inode = page->mapping->host;
struct v9fs_inode *v9inode = V9FS_I(inode);
loff_t size = i_size_read(inode);
struct iov_iter from;
struct bio_vec bvec;
int err, len;
if (page->index == size >> PAGE_SHIFT)
len = size & ~PAGE_MASK;
else
len = PAGE_SIZE;
bvec.bv_page = page;
bvec.bv_offset = 0;
bvec.bv_len = len;
iov_iter_bvec(&from, ITER_BVEC | WRITE, &bvec, 1, len);
BUG_ON(!v9inode->writeback_fid);
set_page_writeback(page);
p9_client_write(v9inode->writeback_fid, page_offset(page), &from, &err);
end_page_writeback(page);
return err;
}
static int v9fs_vfs_writepage(struct page *page, struct writeback_control *wbc)
{
int retval;
p9_debug(P9_DEBUG_VFS, "page %p\n", page);
retval = v9fs_vfs_writepage_locked(page);
if (retval < 0) {
if (retval == -EAGAIN) {
redirty_page_for_writepage(wbc, page);
retval = 0;
} else {
SetPageError(page);
mapping_set_error(page->mapping, retval);
}
} else
retval = 0;
unlock_page(page);
return retval;
}
static int v9fs_launder_page(struct page *page)
{
int retval;
struct inode *inode = page->mapping->host;
v9fs_fscache_wait_on_page_write(inode, page);
if (clear_page_dirty_for_io(page)) {
retval = v9fs_vfs_writepage_locked(page);
if (retval)
return retval;
}
return 0;
}
static ssize_t
v9fs_direct_IO(struct kiocb *iocb, struct iov_iter *iter)
{
struct file *file = iocb->ki_filp;
loff_t pos = iocb->ki_pos;
ssize_t n;
int err = 0;
if (iov_iter_rw(iter) == WRITE) {
n = p9_client_write(file->private_data, pos, iter, &err);
if (n) {
struct inode *inode = file_inode(file);
loff_t i_size = i_size_read(inode);
if (pos + n > i_size)
inode_add_bytes(inode, pos + n - i_size);
}
} else {
n = p9_client_read(file->private_data, pos, iter, &err);
}
return n ? n : err;
}
static int v9fs_write_begin(struct file *filp, struct address_space *mapping,
loff_t pos, unsigned len, unsigned flags,
struct page **pagep, void **fsdata)
{
int retval = 0;
struct page *page;
struct v9fs_inode *v9inode;
pgoff_t index = pos >> PAGE_SHIFT;
struct inode *inode = mapping->host;
p9_debug(P9_DEBUG_VFS, "filp %p, mapping %p\n", filp, mapping);
v9inode = V9FS_I(inode);
start:
page = grab_cache_page_write_begin(mapping, index, flags);
if (!page) {
retval = -ENOMEM;
goto out;
}
BUG_ON(!v9inode->writeback_fid);
if (PageUptodate(page))
goto out;
if (len == PAGE_SIZE)
goto out;
retval = v9fs_fid_readpage(v9inode->writeback_fid, page);
put_page(page);
if (!retval)
goto start;
out:
*pagep = page;
return retval;
}
static int v9fs_write_end(struct file *filp, struct address_space *mapping,
loff_t pos, unsigned len, unsigned copied,
struct page *page, void *fsdata)
{
loff_t last_pos = pos + copied;
struct inode *inode = page->mapping->host;
p9_debug(P9_DEBUG_VFS, "filp %p, mapping %p\n", filp, mapping);
if (unlikely(copied < len)) {
unsigned from = pos & (PAGE_SIZE - 1);
zero_user(page, from + copied, len - copied);
flush_dcache_page(page);
}
if (!PageUptodate(page))
SetPageUptodate(page);
if (last_pos > inode->i_size) {
inode_add_bytes(inode, last_pos - inode->i_size);
i_size_write(inode, last_pos);
}
set_page_dirty(page);
unlock_page(page);
put_page(page);
return copied;
}
