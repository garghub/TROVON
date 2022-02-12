void __init nr_register_sysctl(void)
{
nr_table_header = register_sysctl_paths(nr_path, nr_table);
}
void nr_unregister_sysctl(void)
{
unregister_sysctl_table(nr_table_header);
}
