static int __init init_rc_map_msi_tvanywhere(void)
{
return rc_map_register(&msi_tvanywhere_map);
}
static void __exit exit_rc_map_msi_tvanywhere(void)
{
rc_map_unregister(&msi_tvanywhere_map);
}
