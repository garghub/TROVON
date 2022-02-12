void __init x25_register_sysctl(void)
{
x25_table_header = register_net_sysctl(&init_net, "net/x25", x25_table);
}
void x25_unregister_sysctl(void)
{
unregister_net_sysctl_table(x25_table_header);
}
