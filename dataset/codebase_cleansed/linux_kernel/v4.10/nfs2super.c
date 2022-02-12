static int __init init_nfs_v2(void)
{
register_nfs_version(&nfs_v2);
return 0;
}
static void __exit exit_nfs_v2(void)
{
unregister_nfs_version(&nfs_v2);
}
