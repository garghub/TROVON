static int __init arch_kdebugfs_init(void)
{
arch_debugfs_dir = debugfs_create_dir("sh", NULL);
if (!arch_debugfs_dir)
return -ENOMEM;
return 0;
}
