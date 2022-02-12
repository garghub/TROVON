static inline u32 cs5535_lowhigh_base(int reg)
{
return (reg & 0x10) << 3;
}
static ssize_t cs5535_gpio_write(struct file *file, const char __user *data,
size_t len, loff_t *ppos)
{
u32 m = iminor(file->f_path.dentry->d_inode);
int i, j;
u32 base = gpio_base + cs5535_lowhigh_base(m);
u32 m0, m1;
char c;
m1 = 1 << (m & 0x0F);
m0 = m1 << 16;
for (i = 0; i < len; ++i) {
if (get_user(c, data+i))
return -EFAULT;
for (j = 0; j < ARRAY_SIZE(rm); j++) {
if (c == rm[j].on) {
outl(m1, base + rm[j].wr_offset);
if (c == 'O') {
outl(m0, base + 0x10);
outl(m0, base + 0x14);
}
break;
} else if (c == rm[j].off) {
outl(m0, base + rm[j].wr_offset);
break;
}
}
}
*ppos = 0;
return len;
}
static ssize_t cs5535_gpio_read(struct file *file, char __user *buf,
size_t len, loff_t *ppos)
{
u32 m = iminor(file->f_path.dentry->d_inode);
u32 base = gpio_base + cs5535_lowhigh_base(m);
int rd_bit = 1 << (m & 0x0f);
int i;
char ch;
ssize_t count = 0;
if (*ppos >= ARRAY_SIZE(rm))
return 0;
for (i = *ppos; (i < (*ppos + len)) && (i < ARRAY_SIZE(rm)); i++) {
ch = (inl(base + rm[i].rd_offset) & rd_bit) ?
rm[i].on : rm[i].off;
if (put_user(ch, buf+count))
return -EFAULT;
count++;
}
if ((i == ARRAY_SIZE(rm)) && (count < len)) {
if (put_user('\n', buf + count))
return -EFAULT;
count++;
}
*ppos += count;
return count;
}
static int cs5535_gpio_open(struct inode *inode, struct file *file)
{
u32 m = iminor(inode);
if ((mask & (1 << m)) == 0)
return -EINVAL;
return nonseekable_open(inode, file);
}
static int __init cs5535_gpio_init(void)
{
dev_t dev_id;
u32 low, hi;
int retval;
if (pci_dev_present(divil_pci) == 0) {
printk(KERN_WARNING NAME ": DIVIL not found\n");
return -ENODEV;
}
rdmsr(MSR_LBAR_GPIO, low, hi);
if (hi != 0x0000f001) {
printk(KERN_WARNING NAME ": GPIO not enabled\n");
return -ENODEV;
}
gpio_base = low & 0x0000ff00;
if (mask != 0)
mask &= 0x1f7fffff;
else
mask = 0x0b003c66;
if (!request_region(gpio_base, CS5535_GPIO_SIZE, NAME)) {
printk(KERN_ERR NAME ": can't allocate I/O for GPIO\n");
return -ENODEV;
}
if (major) {
dev_id = MKDEV(major, 0);
retval = register_chrdev_region(dev_id, CS5535_GPIO_COUNT,
NAME);
} else {
retval = alloc_chrdev_region(&dev_id, 0, CS5535_GPIO_COUNT,
NAME);
major = MAJOR(dev_id);
}
if (retval) {
release_region(gpio_base, CS5535_GPIO_SIZE);
return -1;
}
printk(KERN_DEBUG NAME ": base=%#x mask=%#lx major=%d\n",
gpio_base, mask, major);
cdev_init(&cs5535_gpio_cdev, &cs5535_gpio_fops);
cdev_add(&cs5535_gpio_cdev, dev_id, CS5535_GPIO_COUNT);
return 0;
}
static void __exit cs5535_gpio_cleanup(void)
{
dev_t dev_id = MKDEV(major, 0);
cdev_del(&cs5535_gpio_cdev);
unregister_chrdev_region(dev_id, CS5535_GPIO_COUNT);
release_region(gpio_base, CS5535_GPIO_SIZE);
}
