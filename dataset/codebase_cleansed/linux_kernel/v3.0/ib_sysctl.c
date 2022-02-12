void rds_ib_sysctl_exit(void)
{
if (rds_ib_sysctl_hdr)
unregister_sysctl_table(rds_ib_sysctl_hdr);
}
int rds_ib_sysctl_init(void)
{
rds_ib_sysctl_hdr = register_sysctl_paths(rds_ib_sysctl_path, rds_ib_sysctl_table);
if (!rds_ib_sysctl_hdr)
return -ENOMEM;
return 0;
}
