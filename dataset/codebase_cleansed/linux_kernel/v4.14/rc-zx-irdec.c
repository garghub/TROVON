static int __init init_rc_map_zx_irdec(void)
{
return rc_map_register(&zx_irdec_map);
}
static void __exit exit_rc_map_zx_irdec(void)
{
rc_map_unregister(&zx_irdec_map);
}
