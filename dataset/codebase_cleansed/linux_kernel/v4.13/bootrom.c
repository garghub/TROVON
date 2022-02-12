static int bootrom_show(struct seq_file *s, void *unused)
{
seq_write(s, membase, BOOTROM_SIZE);
return 0;
}
static int bootrom_open(struct inode *inode, struct file *file)
{
return single_open(file, bootrom_show, NULL);
}
static int bootrom_setup(void)
{
if (!debugfs_create_file("bootrom", 0444,
NULL, NULL, &bootrom_file_ops)) {
pr_err("Failed to create bootrom debugfs file\n");
return -EINVAL;
}
return 0;
}
