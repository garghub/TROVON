int ramfs_nommu_expand_for_mapping(struct inode *inode, size_t newsize)
{
unsigned long npages, xpages, loop;
struct page *pages;
unsigned order;
void *data;
int ret;
order = get_order(newsize);
if (unlikely(order >= MAX_ORDER))
return -EFBIG;
ret = inode_newsize_ok(inode, newsize);
if (ret)
return ret;
i_size_write(inode, newsize);
pages = alloc_pages(mapping_gfp_mask(inode->i_mapping), order);
if (!pages)
return -ENOMEM;
xpages = 1UL << order;
npages = (newsize + PAGE_SIZE - 1) >> PAGE_SHIFT;
split_page(pages, order);
for (loop = npages; loop < xpages; loop++)
__free_page(pages + loop);
newsize = PAGE_SIZE * npages;
data = page_address(pages);
memset(data, 0, newsize);
for (loop = 0; loop < npages; loop++) {
struct page *page = pages + loop;
ret = add_to_page_cache_lru(page, inode->i_mapping, loop,
GFP_KERNEL);
if (ret < 0)
goto add_error;
SetPageDirty(page);
SetPageUptodate(page);
unlock_page(page);
put_page(page);
}
return 0;
add_error:
while (loop < npages)
__free_page(pages + loop++);
return ret;
}
static int ramfs_nommu_resize(struct inode *inode, loff_t newsize, loff_t size)
{
int ret;
if (size == 0) {
if (unlikely(newsize >> 32))
return -EFBIG;
return ramfs_nommu_expand_for_mapping(inode, newsize);
}
if (newsize < size) {
ret = nommu_shrink_inode_mappings(inode, size, newsize);
if (ret < 0)
return ret;
}
truncate_setsize(inode, newsize);
return 0;
}
static int ramfs_nommu_setattr(struct dentry *dentry, struct iattr *ia)
{
struct inode *inode = dentry->d_inode;
unsigned int old_ia_valid = ia->ia_valid;
int ret = 0;
ret = inode_change_ok(inode, ia);
if (ret)
return ret;
if (ia->ia_valid & ATTR_SIZE) {
loff_t size = inode->i_size;
if (ia->ia_size != size) {
ret = ramfs_nommu_resize(inode, ia->ia_size, size);
if (ret < 0 || ia->ia_valid == ATTR_SIZE)
goto out;
} else {
ia->ia_valid |= ATTR_MTIME|ATTR_CTIME;
}
}
setattr_copy(inode, ia);
out:
ia->ia_valid = old_ia_valid;
return ret;
}
static unsigned long ramfs_nommu_get_unmapped_area(struct file *file,
unsigned long addr, unsigned long len,
unsigned long pgoff, unsigned long flags)
{
unsigned long maxpages, lpages, nr, loop, ret;
struct inode *inode = file_inode(file);
struct page **pages = NULL, **ptr, *page;
loff_t isize;
if (!(flags & MAP_SHARED))
return addr;
lpages = (len + PAGE_SIZE - 1) >> PAGE_SHIFT;
isize = i_size_read(inode);
ret = -EINVAL;
maxpages = (isize + PAGE_SIZE - 1) >> PAGE_SHIFT;
if (pgoff >= maxpages)
goto out;
if (maxpages - pgoff < lpages)
goto out;
ret = -ENOMEM;
pages = kzalloc(lpages * sizeof(struct page *), GFP_KERNEL);
if (!pages)
goto out_free;
nr = find_get_pages(inode->i_mapping, pgoff, lpages, pages);
if (nr != lpages)
goto out_free_pages;
ptr = pages;
page = *ptr++;
page++;
for (loop = lpages; loop > 1; loop--)
if (*ptr++ != page++)
goto out_free_pages;
ret = (unsigned long) page_address(pages[0]);
out_free_pages:
ptr = pages;
for (loop = nr; loop > 0; loop--)
put_page(*ptr++);
out_free:
kfree(pages);
out:
return ret;
}
static int ramfs_nommu_mmap(struct file *file, struct vm_area_struct *vma)
{
if (!(vma->vm_flags & VM_SHARED))
return -ENOSYS;
file_accessed(file);
vma->vm_ops = &generic_file_vm_ops;
return 0;
}
