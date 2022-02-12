void __init x25_register_sysctl(void)
{
x25_table_header = register_sysctl_paths(x25_path, x25_table);
}
void x25_unregister_sysctl(void)
{
unregister_sysctl_table(x25_table_header);
}
