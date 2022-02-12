int __init scsi_init_sysctl(void)
{
scsi_table_header = register_sysctl_table(scsi_root_table);
if (!scsi_table_header)
return -ENOMEM;
return 0;
}
void scsi_exit_sysctl(void)
{
unregister_sysctl_table(scsi_table_header);
}
