static void riowd_writereg(struct riowd *p, u8 val, int index)
{
unsigned long flags;
spin_lock_irqsave(&p->lock, flags);
writeb(index, p->regs + 0);
writeb(val, p->regs + 1);
spin_unlock_irqrestore(&p->lock, flags);
}
static int riowd_open(struct inode *inode, struct file *filp)
{
nonseekable_open(inode, filp);
return 0;
}
static int riowd_release(struct inode *inode, struct file *filp)
{
return 0;
}
static long riowd_ioctl(struct file *filp, unsigned int cmd, unsigned long arg)
{
static const struct watchdog_info info = {
.options = WDIOF_SETTIMEOUT,
.firmware_version = 1,
.identity = DRIVER_NAME,
};
void __user *argp = (void __user *)arg;
struct riowd *p = riowd_device;
unsigned int options;
int new_margin;
switch (cmd) {
case WDIOC_GETSUPPORT:
if (copy_to_user(argp, &info, sizeof(info)))
return -EFAULT;
break;
case WDIOC_GETSTATUS:
case WDIOC_GETBOOTSTATUS:
if (put_user(0, (int __user *)argp))
return -EFAULT;
break;
case WDIOC_KEEPALIVE:
riowd_writereg(p, riowd_timeout, WDTO_INDEX);
break;
case WDIOC_SETOPTIONS:
if (copy_from_user(&options, argp, sizeof(options)))
return -EFAULT;
if (options & WDIOS_DISABLECARD)
riowd_writereg(p, 0, WDTO_INDEX);
else if (options & WDIOS_ENABLECARD)
riowd_writereg(p, riowd_timeout, WDTO_INDEX);
else
return -EINVAL;
break;
case WDIOC_SETTIMEOUT:
if (get_user(new_margin, (int __user *)argp))
return -EFAULT;
if ((new_margin < 60) || (new_margin > (255 * 60)))
return -EINVAL;
riowd_timeout = (new_margin + 59) / 60;
riowd_writereg(p, riowd_timeout, WDTO_INDEX);
case WDIOC_GETTIMEOUT:
return put_user(riowd_timeout * 60, (int __user *)argp);
default:
return -EINVAL;
};
return 0;
}
static ssize_t riowd_write(struct file *file, const char __user *buf,
size_t count, loff_t *ppos)
{
struct riowd *p = riowd_device;
if (count) {
riowd_writereg(p, riowd_timeout, WDTO_INDEX);
return 1;
}
return 0;
}
static int __devinit riowd_probe(struct platform_device *op)
{
struct riowd *p;
int err = -EINVAL;
if (riowd_device)
goto out;
err = -ENOMEM;
p = kzalloc(sizeof(*p), GFP_KERNEL);
if (!p)
goto out;
spin_lock_init(&p->lock);
p->regs = of_ioremap(&op->resource[0], 0, 2, DRIVER_NAME);
if (!p->regs) {
pr_err("Cannot map registers\n");
goto out_free;
}
riowd_device = p;
err = misc_register(&riowd_miscdev);
if (err) {
pr_err("Cannot register watchdog misc device\n");
goto out_iounmap;
}
pr_info("Hardware watchdog [%i minutes], regs at %p\n",
riowd_timeout, p->regs);
dev_set_drvdata(&op->dev, p);
return 0;
out_iounmap:
riowd_device = NULL;
of_iounmap(&op->resource[0], p->regs, 2);
out_free:
kfree(p);
out:
return err;
}
static int __devexit riowd_remove(struct platform_device *op)
{
struct riowd *p = dev_get_drvdata(&op->dev);
misc_deregister(&riowd_miscdev);
of_iounmap(&op->resource[0], p->regs, 2);
kfree(p);
return 0;
}
