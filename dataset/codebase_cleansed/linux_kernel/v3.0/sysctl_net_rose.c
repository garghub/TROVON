void __init rose_register_sysctl(void)
{
rose_table_header = register_sysctl_paths(rose_path, rose_table);
}
void rose_unregister_sysctl(void)
{
unregister_sysctl_table(rose_table_header);
}
