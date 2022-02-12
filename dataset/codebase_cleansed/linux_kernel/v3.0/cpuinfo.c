static int cpuinfo_open(struct inode *inode, struct file *file)
{
return seq_open(file, &cpuinfo_op);
}
static int __init proc_cpuinfo_init(void)
{
proc_create("cpuinfo", 0, NULL, &proc_cpuinfo_operations);
return 0;
}
