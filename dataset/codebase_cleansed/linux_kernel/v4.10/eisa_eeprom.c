static loff_t eisa_eeprom_llseek(struct file *file, loff_t offset, int origin)
{
return fixed_size_llseek(file, offset, origin, HPEE_MAX_LENGTH);
}
static ssize_t eisa_eeprom_read(struct file * file,
char __user *buf, size_t count, loff_t *ppos )
{
unsigned char *tmp;
ssize_t ret;
int i;
if (*ppos < 0 || *ppos >= HPEE_MAX_LENGTH)
return 0;
count = *ppos + count < HPEE_MAX_LENGTH ? count : HPEE_MAX_LENGTH - *ppos;
tmp = kmalloc(count, GFP_KERNEL);
if (tmp) {
for (i = 0; i < count; i++)
tmp[i] = readb(eisa_eeprom_addr+(*ppos)++);
if (copy_to_user (buf, tmp, count))
ret = -EFAULT;
else
ret = count;
kfree (tmp);
} else
ret = -ENOMEM;
return ret;
}
static int eisa_eeprom_open(struct inode *inode, struct file *file)
{
if (file->f_mode & FMODE_WRITE)
return -EINVAL;
return 0;
}
static int eisa_eeprom_release(struct inode *inode, struct file *file)
{
return 0;
}
static int __init eisa_eeprom_init(void)
{
int retval;
if (!eisa_eeprom_addr)
return -ENODEV;
retval = misc_register(&eisa_eeprom_dev);
if (retval < 0) {
printk(KERN_ERR "EISA EEPROM: cannot register misc device.\n");
return retval;
}
printk(KERN_INFO "EISA EEPROM at 0x%p\n", eisa_eeprom_addr);
return 0;
}
