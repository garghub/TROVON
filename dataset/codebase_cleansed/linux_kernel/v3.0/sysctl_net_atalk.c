void atalk_register_sysctl(void)
{
atalk_table_header = register_sysctl_paths(atalk_path, atalk_table);
}
void atalk_unregister_sysctl(void)
{
unregister_sysctl_table(atalk_table_header);
}
