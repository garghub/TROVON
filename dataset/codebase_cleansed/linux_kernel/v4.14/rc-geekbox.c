static int __init init_rc_map_geekbox(void)
{
return rc_map_register(&geekbox_map);
}
static void __exit exit_rc_map_geekbox(void)
{
rc_map_unregister(&geekbox_map);
}
