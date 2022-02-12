void __init nr_register_sysctl(void)
{
nr_table_header = register_net_sysctl(&init_net, "net/netrom", nr_table);
}
void nr_unregister_sysctl(void)
{
unregister_net_sysctl_table(nr_table_header);
}
