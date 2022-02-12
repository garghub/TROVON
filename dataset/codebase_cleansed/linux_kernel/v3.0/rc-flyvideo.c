static int __init init_rc_map_flyvideo(void)
{
return rc_map_register(&flyvideo_map);
}
static void __exit exit_rc_map_flyvideo(void)
{
rc_map_unregister(&flyvideo_map);
}
