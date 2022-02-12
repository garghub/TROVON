static int fram_mmap(struct file *filp, struct vm_area_struct *vma)
{
int ret;
ret = remap_pfn_range(vma,
vma->vm_start,
virt_to_phys((void *)((unsigned long)FRAM_BASE)) >> PAGE_SHIFT,
vma->vm_end-vma->vm_start,
PAGE_SHARED);
if (ret != 0)
return -EAGAIN;
return 0;
}
static int __init
fram_init(void)
{
int ret;
ret = misc_register(&fram_dev);
if (ret) {
printk(KERN_ERR "fram: can't misc_register on minor=%d\n",
FRAM_MINOR);
return ret;
}
printk(KERN_INFO "FRAM memory driver v" FRAM_VERSION "\n");
return 0;
}
static void __exit
fram_cleanup_module(void)
{
misc_deregister(&fram_dev);
}
