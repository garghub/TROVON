static unsigned long romfs_get_unmapped_area(struct file *file,
unsigned long addr,
unsigned long len,
unsigned long pgoff,
unsigned long flags)
{
struct inode *inode = file->f_mapping->host;
struct mtd_info *mtd = inode->i_sb->s_mtd;
unsigned long isize, offset, maxpages, lpages;
if (!mtd)
goto cant_map_directly;
lpages = (len + PAGE_SIZE - 1) >> PAGE_SHIFT;
isize = i_size_read(inode);
offset = pgoff << PAGE_SHIFT;
maxpages = (isize + PAGE_SIZE - 1) >> PAGE_SHIFT;
if ((pgoff >= maxpages) || (maxpages - pgoff < lpages))
return (unsigned long) -EINVAL;
if (mtd->get_unmapped_area) {
if (addr != 0)
return (unsigned long) -EINVAL;
if (len > mtd->size || pgoff >= (mtd->size >> PAGE_SHIFT))
return (unsigned long) -EINVAL;
offset += ROMFS_I(inode)->i_dataoffset;
if (offset > mtd->size - len)
return (unsigned long) -EINVAL;
return mtd->get_unmapped_area(mtd, len, offset, flags);
}
cant_map_directly:
return (unsigned long) -ENOSYS;
}
static int romfs_mmap(struct file *file, struct vm_area_struct *vma)
{
return vma->vm_flags & (VM_SHARED | VM_MAYSHARE) ? 0 : -ENOSYS;
}
