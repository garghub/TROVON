static int __init init_rc_map_msi_digivox_iii(void)
{
return rc_map_register(&msi_digivox_iii_map);
}
static void __exit exit_rc_map_msi_digivox_iii(void)
{
rc_map_unregister(&msi_digivox_iii_map);
}
