static int gio_open(struct inode *inode, struct file *filp)
{
int minor;
int ret = -ENOENT;
preempt_disable();
minor = MINOR(inode->i_rdev);
if (minor < DEVCOUNT) {
if (openCnt > 0) {
ret = -EALREADY;
} else {
openCnt++;
ret = 0;
}
}
preempt_enable();
return ret;
}
static int gio_close(struct inode *inode, struct file *filp)
{
int minor;
minor = MINOR(inode->i_rdev);
if (minor < DEVCOUNT) {
openCnt--;
}
return 0;
}
static long gio_ioctl(struct file *filp, unsigned int cmd, unsigned long arg)
{
unsigned int data;
static unsigned int addr = 0;
if (cmd & 0x01) {
if (copy_from_user(&data, (int *)arg, sizeof(int))) {
return -EFAULT;
}
}
switch (cmd) {
case GIODRV_IOCSGIOSETADDR:
addr = data;
break;
case GIODRV_IOCSGIODATA1:
__raw_writeb((unsigned char)(0x0ff & data), addr);
break;
case GIODRV_IOCSGIODATA2:
if (addr & 0x01) {
return -EFAULT;
}
__raw_writew((unsigned short int)(0x0ffff & data), addr);
break;
case GIODRV_IOCSGIODATA4:
if (addr & 0x03) {
return -EFAULT;
}
__raw_writel(data, addr);
break;
case GIODRV_IOCGGIODATA1:
data = __raw_readb(addr);
break;
case GIODRV_IOCGGIODATA2:
if (addr & 0x01) {
return -EFAULT;
}
data = __raw_readw(addr);
break;
case GIODRV_IOCGGIODATA4:
if (addr & 0x03) {
return -EFAULT;
}
data = __raw_readl(addr);
break;
default:
return -EFAULT;
break;
}
if ((cmd & 0x01) == 0) {
if (copy_to_user((int *)arg, &data, sizeof(int))) {
return -EFAULT;
}
}
return 0;
}
static int __init gio_init(void)
{
int error;
printk(KERN_INFO "gio: driver initialized\n");
openCnt = 0;
if ((error = alloc_chrdev_region(&dev, 0, DEVCOUNT, "gio")) < 0) {
printk(KERN_ERR
"gio: Couldn't alloc_chrdev_region, error=%d\n",
error);
return 1;
}
cdev_p = cdev_alloc();
cdev_p->ops = &gio_fops;
error = cdev_add(cdev_p, dev, DEVCOUNT);
if (error) {
printk(KERN_ERR
"gio: Couldn't cdev_add, error=%d\n", error);
return 1;
}
return 0;
}
static void __exit gio_exit(void)
{
cdev_del(cdev_p);
unregister_chrdev_region(dev, DEVCOUNT);
}
