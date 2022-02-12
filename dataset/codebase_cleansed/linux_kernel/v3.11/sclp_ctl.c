static int sclp_ctl_cmdw_supported(unsigned int cmdw)
{
int i;
for (i = 0; i < ARRAY_SIZE(sclp_ctl_sccb_wlist); i++) {
if (cmdw == sclp_ctl_sccb_wlist[i])
return 1;
}
return 0;
}
static void __user *u64_to_uptr(u64 value)
{
if (is_compat_task())
return compat_ptr(value);
else
return (void __user *)(unsigned long)value;
}
static int sclp_ctl_ioctl_sccb(void __user *user_area)
{
struct sclp_ctl_sccb ctl_sccb;
struct sccb_header *sccb;
int rc;
if (copy_from_user(&ctl_sccb, user_area, sizeof(ctl_sccb)))
return -EFAULT;
if (!sclp_ctl_cmdw_supported(ctl_sccb.cmdw))
return -EOPNOTSUPP;
sccb = (void *) get_zeroed_page(GFP_KERNEL | GFP_DMA);
if (!sccb)
return -ENOMEM;
if (copy_from_user(sccb, u64_to_uptr(ctl_sccb.sccb), sizeof(*sccb))) {
rc = -EFAULT;
goto out_free;
}
if (sccb->length > PAGE_SIZE || sccb->length < 8)
return -EINVAL;
if (copy_from_user(sccb, u64_to_uptr(ctl_sccb.sccb), sccb->length)) {
rc = -EFAULT;
goto out_free;
}
rc = sclp_sync_request(ctl_sccb.cmdw, sccb);
if (rc)
goto out_free;
if (copy_to_user(u64_to_uptr(ctl_sccb.sccb), sccb, sccb->length))
rc = -EFAULT;
out_free:
free_page((unsigned long) sccb);
return rc;
}
static long sclp_ctl_ioctl(struct file *filp, unsigned int cmd,
unsigned long arg)
{
void __user *argp;
if (is_compat_task())
argp = compat_ptr(arg);
else
argp = (void __user *) arg;
switch (cmd) {
case SCLP_CTL_SCCB:
return sclp_ctl_ioctl_sccb(argp);
default:
return -ENOTTY;
}
}
static int __init sclp_ctl_init(void)
{
return misc_register(&sclp_ctl_device);
}
static void __exit sclp_ctl_exit(void)
{
misc_deregister(&sclp_ctl_device);
}
