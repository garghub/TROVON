void __init rose_register_sysctl(void)
{
rose_table_header = register_net_sysctl(&init_net, "net/rose", rose_table);
}
void rose_unregister_sysctl(void)
{
unregister_net_sysctl_table(rose_table_header);
}
