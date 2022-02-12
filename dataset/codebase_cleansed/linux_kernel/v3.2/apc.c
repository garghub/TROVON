static int __init apc_setup(char *str)
{
if(!strncmp(str, "noidle", strlen("noidle"))) {
apc_no_idle = 1;
return 1;
}
return 0;
}
static void apc_swift_idle(void)
{
#ifdef APC_DEBUG_LED
set_auxio(0x00, AUXIO_LED);
#endif
apc_writeb(apc_readb(APC_IDLE_REG) | APC_IDLE_ON, APC_IDLE_REG);
#ifdef APC_DEBUG_LED
set_auxio(AUXIO_LED, 0x00);
#endif
}
static inline void apc_free(struct platform_device *op)
{
of_iounmap(&op->resource[0], regs, resource_size(&op->resource[0]));
}
static int apc_open(struct inode *inode, struct file *f)
{
return 0;
}
static int apc_release(struct inode *inode, struct file *f)
{
return 0;
}
static long apc_ioctl(struct file *f, unsigned int cmd, unsigned long __arg)
{
__u8 inarg, __user *arg = (__u8 __user *) __arg;
switch (cmd) {
case APCIOCGFANCTL:
if (put_user(apc_readb(APC_FANCTL_REG) & APC_REGMASK, arg))
return -EFAULT;
break;
case APCIOCGCPWR:
if (put_user(apc_readb(APC_CPOWER_REG) & APC_REGMASK, arg))
return -EFAULT;
break;
case APCIOCGBPORT:
if (put_user(apc_readb(APC_BPORT_REG) & APC_BPMASK, arg))
return -EFAULT;
break;
case APCIOCSFANCTL:
if (get_user(inarg, arg))
return -EFAULT;
apc_writeb(inarg & APC_REGMASK, APC_FANCTL_REG);
break;
case APCIOCSCPWR:
if (get_user(inarg, arg))
return -EFAULT;
apc_writeb(inarg & APC_REGMASK, APC_CPOWER_REG);
break;
case APCIOCSBPORT:
if (get_user(inarg, arg))
return -EFAULT;
apc_writeb(inarg & APC_BPMASK, APC_BPORT_REG);
break;
default:
return -EINVAL;
}
return 0;
}
static int __devinit apc_probe(struct platform_device *op)
{
int err;
regs = of_ioremap(&op->resource[0], 0,
resource_size(&op->resource[0]), APC_OBPNAME);
if (!regs) {
printk(KERN_ERR "%s: unable to map registers\n", APC_DEVNAME);
return -ENODEV;
}
err = misc_register(&apc_miscdev);
if (err) {
printk(KERN_ERR "%s: unable to register device\n", APC_DEVNAME);
apc_free(op);
return -ENODEV;
}
if (!apc_no_idle)
pm_idle = apc_swift_idle;
printk(KERN_INFO "%s: power management initialized%s\n",
APC_DEVNAME, apc_no_idle ? " (CPU idle disabled)" : "");
return 0;
}
static int __init apc_init(void)
{
return platform_driver_register(&apc_driver);
}
