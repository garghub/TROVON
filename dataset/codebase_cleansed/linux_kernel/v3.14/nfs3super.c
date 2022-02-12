static int __init init_nfs_v3(void)
{
register_nfs_version(&nfs_v3);
return 0;
}
static void __exit exit_nfs_v3(void)
{
unregister_nfs_version(&nfs_v3);
}
