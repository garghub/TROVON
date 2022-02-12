void rds_iw_sysctl_exit(void)
{
unregister_net_sysctl_table(rds_iw_sysctl_hdr);
}
int rds_iw_sysctl_init(void)
{
rds_iw_sysctl_hdr = register_net_sysctl(&init_net, "net/rds/iw", rds_iw_sysctl_table);
if (!rds_iw_sysctl_hdr)
return -ENOMEM;
return 0;
}
