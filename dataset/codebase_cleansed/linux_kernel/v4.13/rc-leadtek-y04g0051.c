static int __init init_rc_map_leadtek_y04g0051(void)
{
return rc_map_register(&leadtek_y04g0051_map);
}
static void __exit exit_rc_map_leadtek_y04g0051(void)
{
rc_map_unregister(&leadtek_y04g0051_map);
}
