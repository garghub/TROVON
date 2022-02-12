static int execdomains_proc_show(struct seq_file *m, void *v)
{
seq_puts(m, "0-0\tLinux \t[kernel]\n");
return 0;
}
static int execdomains_proc_open(struct inode *inode, struct file *file)
{
return single_open(file, execdomains_proc_show, NULL);
}
static int __init proc_execdomains_init(void)
{
proc_create("execdomains", 0, NULL, &execdomains_proc_fops);
return 0;
}
