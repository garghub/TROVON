static ssize_t mmapper_read(struct file *file, char __user *buf, size_t count,
loff_t *ppos)
{
return simple_read_from_buffer(buf, count, ppos, v_buf, mmapper_size);
}
static ssize_t mmapper_write(struct file *file, const char __user *buf,
size_t count, loff_t *ppos)
{
if (*ppos > mmapper_size)
return -EINVAL;
return simple_write_to_buffer(v_buf, mmapper_size, ppos, buf, count);
}
static long mmapper_ioctl(struct file *file, unsigned int cmd, unsigned long arg)
{
return -ENOIOCTLCMD;
}
static int mmapper_mmap(struct file *file, struct vm_area_struct *vma)
{
int ret = -EINVAL;
int size;
if (vma->vm_pgoff != 0)
goto out;
size = vma->vm_end - vma->vm_start;
if (size > mmapper_size)
return -EFAULT;
if (remap_pfn_range(vma, vma->vm_start, p_buf >> PAGE_SHIFT, size,
vma->vm_page_prot))
goto out;
ret = 0;
out:
return ret;
}
static int mmapper_open(struct inode *inode, struct file *file)
{
return 0;
}
static int mmapper_release(struct inode *inode, struct file *file)
{
return 0;
}
static int __init mmapper_init(void)
{
int err;
printk(KERN_INFO "Mapper v0.1\n");
v_buf = (char *) find_iomem("mmapper", &mmapper_size);
if (mmapper_size == 0) {
printk(KERN_ERR "mmapper_init - find_iomem failed\n");
return -ENODEV;
}
p_buf = __pa(v_buf);
err = misc_register(&mmapper_dev);
if (err) {
printk(KERN_ERR "mmapper - misc_register failed, err = %d\n",
err);
return err;
}
return 0;
}
static void mmapper_exit(void)
{
misc_deregister(&mmapper_dev);
}
