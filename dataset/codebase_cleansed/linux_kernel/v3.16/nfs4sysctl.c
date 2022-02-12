int nfs4_register_sysctl(void)
{
nfs4_callback_sysctl_table = register_sysctl_table(nfs4_cb_sysctl_root);
if (nfs4_callback_sysctl_table == NULL)
return -ENOMEM;
return 0;
}
void nfs4_unregister_sysctl(void)
{
unregister_sysctl_table(nfs4_callback_sysctl_table);
nfs4_callback_sysctl_table = NULL;
}
