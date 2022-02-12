static int xenbus_backend_open(struct inode *inode, struct file *filp)
{
if (!capable(CAP_SYS_ADMIN))
return -EPERM;
return nonseekable_open(inode, filp);
}
static long xenbus_backend_ioctl(struct file *file, unsigned int cmd, unsigned long data)
{
if (!capable(CAP_SYS_ADMIN))
return -EPERM;
switch (cmd) {
case IOCTL_XENBUS_BACKEND_EVTCHN:
if (xen_store_evtchn > 0)
return xen_store_evtchn;
return -ENODEV;
default:
return -ENOTTY;
}
}
static int xenbus_backend_mmap(struct file *file, struct vm_area_struct *vma)
{
size_t size = vma->vm_end - vma->vm_start;
if (!capable(CAP_SYS_ADMIN))
return -EPERM;
if ((size > PAGE_SIZE) || (vma->vm_pgoff != 0))
return -EINVAL;
if (remap_pfn_range(vma, vma->vm_start,
virt_to_pfn(xen_store_interface),
size, vma->vm_page_prot))
return -EAGAIN;
return 0;
}
static int __init xenbus_backend_init(void)
{
int err;
if (!xen_initial_domain())
return -ENODEV;
err = misc_register(&xenbus_backend_dev);
if (err)
printk(KERN_ERR "Could not register xenbus backend device\n");
return err;
}
static void __exit xenbus_backend_exit(void)
{
misc_deregister(&xenbus_backend_dev);
}
