static int xenbus_backend_open(struct inode *inode, struct file *filp)
{
if (!capable(CAP_SYS_ADMIN))
return -EPERM;
return nonseekable_open(inode, filp);
}
static long xenbus_alloc(domid_t domid)
{
struct evtchn_alloc_unbound arg;
int err = -EEXIST;
xs_suspend();
if (xenstored_ready)
goto out_err;
gnttab_grant_foreign_access_ref(GNTTAB_RESERVED_XENSTORE, domid,
virt_to_mfn(xen_store_interface), 0 );
arg.dom = DOMID_SELF;
arg.remote_dom = domid;
err = HYPERVISOR_event_channel_op(EVTCHNOP_alloc_unbound, &arg);
if (err)
goto out_err;
if (xen_store_evtchn > 0)
xb_deinit_comms();
xen_store_evtchn = arg.port;
xs_resume();
return arg.port;
out_err:
xs_suspend_cancel();
return err;
}
static long xenbus_backend_ioctl(struct file *file, unsigned int cmd,
unsigned long data)
{
if (!capable(CAP_SYS_ADMIN))
return -EPERM;
switch (cmd) {
case IOCTL_XENBUS_BACKEND_EVTCHN:
if (xen_store_evtchn > 0)
return xen_store_evtchn;
return -ENODEV;
case IOCTL_XENBUS_BACKEND_SETUP:
return xenbus_alloc(data);
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
pr_err("Could not register xenbus backend device\n");
return err;
}
static void __exit xenbus_backend_exit(void)
{
misc_deregister(&xenbus_backend_dev);
}
