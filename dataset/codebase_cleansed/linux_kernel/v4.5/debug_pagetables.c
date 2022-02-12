static int ptdump_show(struct seq_file *m, void *v)
{
ptdump_walk_pgd_level(m, NULL);
return 0;
}
static int ptdump_open(struct inode *inode, struct file *filp)
{
return single_open(filp, ptdump_show, NULL);
}
static int __init pt_dump_debug_init(void)
{
pe = debugfs_create_file("kernel_page_tables", S_IRUSR, NULL, NULL,
&ptdump_fops);
if (!pe)
return -ENOMEM;
return 0;
}
static void __exit pt_dump_debug_exit(void)
{
debugfs_remove_recursive(pe);
}
