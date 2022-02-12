static int devinfo_show(struct seq_file *f, void *v)
{
int i = *(loff_t *) v;
if (i < CHRDEV_MAJOR_HASH_SIZE) {
if (i == 0)
seq_puts(f, "Character devices:\n");
chrdev_show(f, i);
}
#ifdef CONFIG_BLOCK
else {
i -= CHRDEV_MAJOR_HASH_SIZE;
if (i == 0)
seq_puts(f, "\nBlock devices:\n");
blkdev_show(f, i);
}
#endif
return 0;
}
static void *devinfo_start(struct seq_file *f, loff_t *pos)
{
if (*pos < (BLKDEV_MAJOR_HASH_SIZE + CHRDEV_MAJOR_HASH_SIZE))
return pos;
return NULL;
}
static void *devinfo_next(struct seq_file *f, void *v, loff_t *pos)
{
(*pos)++;
if (*pos >= (BLKDEV_MAJOR_HASH_SIZE + CHRDEV_MAJOR_HASH_SIZE))
return NULL;
return pos;
}
static void devinfo_stop(struct seq_file *f, void *v)
{
}
static int devinfo_open(struct inode *inode, struct file *filp)
{
return seq_open(filp, &devinfo_ops);
}
static int __init proc_devices_init(void)
{
proc_create("devices", 0, NULL, &proc_devinfo_operations);
return 0;
}
