static int fc_open(struct inode *ino, struct file *f)
{
struct fmc_device *fmc;
struct fc_instance *fc;
int minor = iminor(ino);
list_for_each_entry(fc, &fc_devices, list)
if (fc->misc.minor == minor)
break;
if (fc->misc.minor != minor)
return -ENODEV;
fmc = fc->fmc;
if (try_module_get(fmc->owner) == 0)
return -ENODEV;
f->private_data = fmc;
return 0;
}
static int fc_release(struct inode *ino, struct file *f)
{
struct fmc_device *fmc = f->private_data;
module_put(fmc->owner);
return 0;
}
static ssize_t fc_read(struct file *f, char __user *buf, size_t count,
loff_t *offp)
{
struct fmc_device *fmc = f->private_data;
unsigned long addr;
uint32_t val;
if (count < sizeof(val))
return -EINVAL;
count = sizeof(val);
addr = *offp;
if (addr > fmc->memlen)
return -ESPIPE;
val = fmc_readl(fmc, addr);
if (copy_to_user(buf, &val, count))
return -EFAULT;
*offp += count;
return count;
}
static ssize_t fc_write(struct file *f, const char __user *buf, size_t count,
loff_t *offp)
{
struct fmc_device *fmc = f->private_data;
unsigned long addr;
uint32_t val;
if (count < sizeof(val))
return -EINVAL;
count = sizeof(val);
addr = *offp;
if (addr > fmc->memlen)
return -ESPIPE;
if (copy_from_user(&val, buf, count))
return -EFAULT;
fmc_writel(fmc, val, addr);
*offp += count;
return count;
}
static int fc_probe(struct fmc_device *fmc)
{
int ret;
int index = 0;
struct fc_instance *fc;
index = fmc_validate(fmc, &fc_drv);
if (index < 0)
return -EINVAL;
fc = kzalloc(sizeof(*fc), GFP_KERNEL);
if (!fc)
return -ENOMEM;
fc->fmc = fmc;
fc->misc.minor = MISC_DYNAMIC_MINOR;
fc->misc.fops = &fc_fops;
fc->misc.name = kstrdup(dev_name(&fmc->dev), GFP_KERNEL);
ret = misc_register(&fc->misc);
if (ret < 0)
goto out;
spin_lock(&fc_lock);
list_add(&fc->list, &fc_devices);
spin_unlock(&fc_lock);
dev_info(&fc->fmc->dev, "Created misc device \"%s\"\n",
fc->misc.name);
return 0;
out:
kfree(fc->misc.name);
kfree(fc);
return ret;
}
static int fc_remove(struct fmc_device *fmc)
{
struct fc_instance *fc;
list_for_each_entry(fc, &fc_devices, list)
if (fc->fmc == fmc)
break;
if (fc->fmc != fmc) {
dev_err(&fmc->dev, "remove called but not found\n");
return -ENODEV;
}
spin_lock(&fc_lock);
list_del(&fc->list);
spin_unlock(&fc_lock);
misc_deregister(&fc->misc);
kfree(fc->misc.name);
kfree(fc);
return 0;
}
static int fc_init(void)
{
int ret;
ret = fmc_driver_register(&fc_drv);
return ret;
}
static void fc_exit(void)
{
fmc_driver_unregister(&fc_drv);
}
