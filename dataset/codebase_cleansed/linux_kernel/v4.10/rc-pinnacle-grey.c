static int __init init_rc_map_pinnacle_grey(void)
{
return rc_map_register(&pinnacle_grey_map);
}
static void __exit exit_rc_map_pinnacle_grey(void)
{
rc_map_unregister(&pinnacle_grey_map);
}
