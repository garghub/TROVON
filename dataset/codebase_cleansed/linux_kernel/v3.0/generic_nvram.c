static loff_t nvram_llseek(struct file *file, loff_t offset, int origin)
{
switch (origin) {
case 1:
offset += file->f_pos;
break;
case 2:
offset += nvram_len;
break;
}
if (offset < 0)
return -EINVAL;
file->f_pos = offset;
return file->f_pos;
}
static ssize_t read_nvram(struct file *file, char __user *buf,
size_t count, loff_t *ppos)
{
unsigned int i;
char __user *p = buf;
if (!access_ok(VERIFY_WRITE, buf, count))
return -EFAULT;
if (*ppos >= nvram_len)
return 0;
for (i = *ppos; count > 0 && i < nvram_len; ++i, ++p, --count)
if (__put_user(nvram_read_byte(i), p))
return -EFAULT;
*ppos = i;
return p - buf;
}
static ssize_t write_nvram(struct file *file, const char __user *buf,
size_t count, loff_t *ppos)
{
unsigned int i;
const char __user *p = buf;
char c;
if (!access_ok(VERIFY_READ, buf, count))
return -EFAULT;
if (*ppos >= nvram_len)
return 0;
for (i = *ppos; count > 0 && i < nvram_len; ++i, ++p, --count) {
if (__get_user(c, p))
return -EFAULT;
nvram_write_byte(c, i);
}
*ppos = i;
return p - buf;
}
static int nvram_ioctl(struct file *file, unsigned int cmd, unsigned long arg)
{
switch(cmd) {
#ifdef CONFIG_PPC_PMAC
case OBSOLETE_PMAC_NVRAM_GET_OFFSET:
printk(KERN_WARNING "nvram: Using obsolete PMAC_NVRAM_GET_OFFSET ioctl\n");
case IOC_NVRAM_GET_OFFSET: {
int part, offset;
if (!machine_is(powermac))
return -EINVAL;
if (copy_from_user(&part, (void __user*)arg, sizeof(part)) != 0)
return -EFAULT;
if (part < pmac_nvram_OF || part > pmac_nvram_NR)
return -EINVAL;
offset = pmac_get_partition(part);
if (copy_to_user((void __user*)arg, &offset, sizeof(offset)) != 0)
return -EFAULT;
break;
}
#endif
case IOC_NVRAM_SYNC:
nvram_sync();
break;
default:
return -EINVAL;
}
return 0;
}
static long nvram_unlocked_ioctl(struct file *file, unsigned int cmd, unsigned long arg)
{
int ret;
mutex_lock(&nvram_mutex);
ret = nvram_ioctl(file, cmd, arg);
mutex_unlock(&nvram_mutex);
return ret;
}
int __init nvram_init(void)
{
int ret = 0;
printk(KERN_INFO "Generic non-volatile memory driver v%s\n",
NVRAM_VERSION);
ret = misc_register(&nvram_dev);
if (ret != 0)
goto out;
nvram_len = nvram_get_size();
if (nvram_len < 0)
nvram_len = NVRAM_SIZE;
out:
return ret;
}
void __exit nvram_cleanup(void)
{
misc_deregister( &nvram_dev );
}
