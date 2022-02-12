void ipx_register_sysctl(void)
{
ipx_table_header = register_net_sysctl(&init_net, "net/ipx", ipx_table);
}
void ipx_unregister_sysctl(void)
{
unregister_net_sysctl_table(ipx_table_header);
}
