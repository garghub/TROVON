static int __init init_rc_map_pinnacle_color(void)
{
return rc_map_register(&pinnacle_color_map);
}
static void __exit exit_rc_map_pinnacle_color(void)
{
rc_map_unregister(&pinnacle_color_map);
}
