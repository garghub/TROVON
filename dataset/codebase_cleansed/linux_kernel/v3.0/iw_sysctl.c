void rds_iw_sysctl_exit(void)
{
if (rds_iw_sysctl_hdr)
unregister_sysctl_table(rds_iw_sysctl_hdr);
}
int rds_iw_sysctl_init(void)
{
rds_iw_sysctl_hdr = register_sysctl_paths(rds_iw_sysctl_path, rds_iw_sysctl_table);
if (!rds_iw_sysctl_hdr)
return -ENOMEM;
return 0;
}
