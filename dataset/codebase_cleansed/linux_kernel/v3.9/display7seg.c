static int d7s_open(struct inode *inode, struct file *f)
{
if (D7S_MINOR != iminor(inode))
return -ENODEV;
atomic_inc(&d7s_users);
return 0;
}
static int d7s_release(struct inode *inode, struct file *f)
{
if (atomic_dec_and_test(&d7s_users) && !sol_compat) {
struct d7s *p = d7s_device;
u8 regval = 0;
regval = readb(p->regs);
if (p->flipped)
regval |= D7S_FLIP;
else
regval &= ~D7S_FLIP;
writeb(regval, p->regs);
}
return 0;
}
static long d7s_ioctl(struct file *file, unsigned int cmd, unsigned long arg)
{
struct d7s *p = d7s_device;
u8 regs = readb(p->regs);
int error = 0;
u8 ireg = 0;
if (D7S_MINOR != iminor(file_inode(file)))
return -ENODEV;
mutex_lock(&d7s_mutex);
switch (cmd) {
case D7SIOCWR:
if (get_user(ireg, (int __user *) arg)) {
error = -EFAULT;
break;
}
if (sol_compat) {
if (regs & D7S_FLIP)
ireg |= D7S_FLIP;
else
ireg &= ~D7S_FLIP;
}
writeb(ireg, p->regs);
break;
case D7SIOCRD:
if (put_user(regs, (int __user *) arg)) {
error = -EFAULT;
break;
}
break;
case D7SIOCTM:
if (regs & D7S_FLIP)
regs &= ~D7S_FLIP;
else
regs |= D7S_FLIP;
writeb(regs, p->regs);
break;
}
mutex_unlock(&d7s_mutex);
return error;
}
static int d7s_probe(struct platform_device *op)
{
struct device_node *opts;
int err = -EINVAL;
struct d7s *p;
u8 regs;
if (d7s_device)
goto out;
p = kzalloc(sizeof(*p), GFP_KERNEL);
err = -ENOMEM;
if (!p)
goto out;
p->regs = of_ioremap(&op->resource[0], 0, sizeof(u8), "d7s");
if (!p->regs) {
printk(KERN_ERR PFX "Cannot map chip registers\n");
goto out_free;
}
err = misc_register(&d7s_miscdev);
if (err) {
printk(KERN_ERR PFX "Unable to acquire miscdevice minor %i\n",
D7S_MINOR);
goto out_iounmap;
}
regs = readb(p->regs);
opts = of_find_node_by_path("/options");
if (opts &&
of_get_property(opts, "d7s-flipped?", NULL))
p->flipped = true;
if (p->flipped)
regs |= D7S_FLIP;
else
regs &= ~D7S_FLIP;
writeb(regs, p->regs);
printk(KERN_INFO PFX "7-Segment Display%s at [%s:0x%llx] %s\n",
op->dev.of_node->full_name,
(regs & D7S_FLIP) ? " (FLIPPED)" : "",
op->resource[0].start,
sol_compat ? "in sol_compat mode" : "");
dev_set_drvdata(&op->dev, p);
d7s_device = p;
err = 0;
out:
return err;
out_iounmap:
of_iounmap(&op->resource[0], p->regs, sizeof(u8));
out_free:
kfree(p);
goto out;
}
static int d7s_remove(struct platform_device *op)
{
struct d7s *p = dev_get_drvdata(&op->dev);
u8 regs = readb(p->regs);
if (sol_compat) {
if (p->flipped)
regs |= D7S_FLIP;
else
regs &= ~D7S_FLIP;
writeb(regs, p->regs);
}
misc_deregister(&d7s_miscdev);
of_iounmap(&op->resource[0], p->regs, sizeof(u8));
kfree(p);
return 0;
}
