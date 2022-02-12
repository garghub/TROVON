int __init llc_sysctl_init(void)
{
llc2_timeout_header = register_net_sysctl(&init_net, "net/llc/llc2/timeout", llc2_timeout_table);
llc_station_header = register_net_sysctl(&init_net, "net/llc/station", llc_station_table);
if (!llc2_timeout_header || !llc_station_header) {
llc_sysctl_exit();
return -ENOMEM;
}
return 0;
}
void llc_sysctl_exit(void)
{
if (llc2_timeout_header) {
unregister_net_sysctl_table(llc2_timeout_header);
llc2_timeout_header = NULL;
}
if (llc_station_header) {
unregister_net_sysctl_table(llc_station_header);
llc_station_header = NULL;
}
}
