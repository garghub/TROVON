static unsigned long romfs_get_unmapped_area(struct file *file,
unsigned long addr,
unsigned long len,
unsigned long pgoff,
unsigned long flags)
{
struct inode *inode = file->f_mapping->host;
struct mtd_info *mtd = inode->i_sb->s_mtd;
unsigned long isize, offset, maxpages, lpages;
int ret;
if (!mtd)
return (unsigned long) -ENOSYS;
lpages = (len + PAGE_SIZE - 1) >> PAGE_SHIFT;
isize = i_size_read(inode);
offset = pgoff << PAGE_SHIFT;
maxpages = (isize + PAGE_SIZE - 1) >> PAGE_SHIFT;
if ((pgoff >= maxpages) || (maxpages - pgoff < lpages))
return (unsigned long) -EINVAL;
if (addr != 0)
return (unsigned long) -EINVAL;
if (len > mtd->size || pgoff >= (mtd->size >> PAGE_SHIFT))
return (unsigned long) -EINVAL;
offset += ROMFS_I(inode)->i_dataoffset;
if (offset > mtd->size - len)
return (unsigned long) -EINVAL;
ret = mtd_get_unmapped_area(mtd, len, offset, flags);
if (ret == -EOPNOTSUPP)
ret = -ENOSYS;
return (unsigned long) ret;
}
static int romfs_mmap(struct file *file, struct vm_area_struct *vma)
{
return vma->vm_flags & (VM_SHARED | VM_MAYSHARE) ? 0 : -ENOSYS;
}
