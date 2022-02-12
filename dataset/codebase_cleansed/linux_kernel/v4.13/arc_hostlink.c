static int arc_hl_mmap(struct file *fp, struct vm_area_struct *vma)
{
vma->vm_page_prot = pgprot_noncached(vma->vm_page_prot);
if (io_remap_pfn_range(vma, vma->vm_start, vma->vm_pgoff,
vma->vm_end - vma->vm_start,
vma->vm_page_prot)) {
pr_warn("Hostlink buffer mmap ERROR\n");
return -EAGAIN;
}
return 0;
}
static long arc_hl_ioctl(struct file *file, unsigned int cmd,
unsigned long arg)
{
put_user((unsigned int)__HOSTLINK__, (int __user *)arg);
return 0;
}
static int __init arc_hl_init(void)
{
pr_info("ARC Hostlink driver mmap at 0x%p\n", __HOSTLINK__);
return misc_register(&arc_hl_dev);
}
