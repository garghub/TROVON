static int __init init_rc_map_twinhan_vp1027(void)
{
return rc_map_register(&twinhan_vp1027_map);
}
static void __exit exit_rc_map_twinhan_vp1027(void)
{
rc_map_unregister(&twinhan_vp1027_map);
}
