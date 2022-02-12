SYSCALL_DEFINE(fadvise64_64)(int fd, loff_t offset, loff_t len, int advice)
{
struct fd f = fdget(fd);
struct address_space *mapping;
struct backing_dev_info *bdi;
loff_t endbyte;
pgoff_t start_index;
pgoff_t end_index;
unsigned long nrpages;
int ret = 0;
if (!f.file)
return -EBADF;
if (S_ISFIFO(f.file->f_path.dentry->d_inode->i_mode)) {
ret = -ESPIPE;
goto out;
}
mapping = f.file->f_mapping;
if (!mapping || len < 0) {
ret = -EINVAL;
goto out;
}
if (mapping->a_ops->get_xip_mem) {
switch (advice) {
case POSIX_FADV_NORMAL:
case POSIX_FADV_RANDOM:
case POSIX_FADV_SEQUENTIAL:
case POSIX_FADV_WILLNEED:
case POSIX_FADV_NOREUSE:
case POSIX_FADV_DONTNEED:
break;
default:
ret = -EINVAL;
}
goto out;
}
endbyte = offset + len;
if (!len || endbyte < len)
endbyte = -1;
else
endbyte--;
bdi = mapping->backing_dev_info;
switch (advice) {
case POSIX_FADV_NORMAL:
f.file->f_ra.ra_pages = bdi->ra_pages;
spin_lock(&f.file->f_lock);
f.file->f_mode &= ~FMODE_RANDOM;
spin_unlock(&f.file->f_lock);
break;
case POSIX_FADV_RANDOM:
spin_lock(&f.file->f_lock);
f.file->f_mode |= FMODE_RANDOM;
spin_unlock(&f.file->f_lock);
break;
case POSIX_FADV_SEQUENTIAL:
f.file->f_ra.ra_pages = bdi->ra_pages * 2;
spin_lock(&f.file->f_lock);
f.file->f_mode &= ~FMODE_RANDOM;
spin_unlock(&f.file->f_lock);
break;
case POSIX_FADV_WILLNEED:
start_index = offset >> PAGE_CACHE_SHIFT;
end_index = endbyte >> PAGE_CACHE_SHIFT;
nrpages = end_index - start_index + 1;
if (!nrpages)
nrpages = ~0UL;
force_page_cache_readahead(mapping, f.file, start_index,
nrpages);
break;
case POSIX_FADV_NOREUSE:
break;
case POSIX_FADV_DONTNEED:
if (!bdi_write_congested(mapping->backing_dev_info))
__filemap_fdatawrite_range(mapping, offset, endbyte,
WB_SYNC_NONE);
start_index = (offset+(PAGE_CACHE_SIZE-1)) >> PAGE_CACHE_SHIFT;
end_index = (endbyte >> PAGE_CACHE_SHIFT);
if (end_index >= start_index)
invalidate_mapping_pages(mapping, start_index,
end_index);
break;
default:
ret = -EINVAL;
}
out:
fdput(f);
return ret;
}
asmlinkage long SyS_fadvise64_64(long fd, loff_t offset, loff_t len, long advice)
{
return SYSC_fadvise64_64((int) fd, offset, len, (int) advice);
}
SYSCALL_DEFINE(fadvise64)(int fd, loff_t offset, size_t len, int advice)
{
return sys_fadvise64_64(fd, offset, len, advice);
}
asmlinkage long SyS_fadvise64(long fd, loff_t offset, long len, long advice)
{
return SYSC_fadvise64((int) fd, offset, (size_t)len, (int)advice);
}
