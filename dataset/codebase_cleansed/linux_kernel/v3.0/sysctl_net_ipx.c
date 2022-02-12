void ipx_register_sysctl(void)
{
ipx_table_header = register_sysctl_paths(ipx_path, ipx_table);
}
void ipx_unregister_sysctl(void)
{
unregister_sysctl_table(ipx_table_header);
}
