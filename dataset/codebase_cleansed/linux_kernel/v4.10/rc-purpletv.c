static int __init init_rc_map_purpletv(void)
{
return rc_map_register(&purpletv_map);
}
static void __exit exit_rc_map_purpletv(void)
{
rc_map_unregister(&purpletv_map);
}
