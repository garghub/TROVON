static unsigned long ramfs_mmu_get_unmapped_area(struct file *file,
unsigned long addr, unsigned long len, unsigned long pgoff,
unsigned long flags)
{
return current->mm->get_unmapped_area(file, addr, len, pgoff, flags);
}
