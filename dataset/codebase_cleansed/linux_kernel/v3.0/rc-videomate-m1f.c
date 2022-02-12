static int __init init_rc_map_videomate_m1f(void)
{
return rc_map_register(&videomate_m1f_map);
}
static void __exit exit_rc_map_videomate_m1f(void)
{
rc_map_unregister(&videomate_m1f_map);
}
