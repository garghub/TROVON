static int __init init_rc_map_msi_digivox_ii(void)
{
return rc_map_register(&msi_digivox_ii_map);
}
static void __exit exit_rc_map_msi_digivox_ii(void)
{
rc_map_unregister(&msi_digivox_ii_map);
}
