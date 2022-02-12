void atalk_register_sysctl(void)
{
atalk_table_header = register_net_sysctl(&init_net, "net/appletalk", atalk_table);
}
void atalk_unregister_sysctl(void)
{
unregister_net_sysctl_table(atalk_table_header);
}
