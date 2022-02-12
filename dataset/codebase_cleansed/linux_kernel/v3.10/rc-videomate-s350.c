static int __init init_rc_map_videomate_s350(void)
{
return rc_map_register(&videomate_s350_map);
}
static void __exit exit_rc_map_videomate_s350(void)
{
rc_map_unregister(&videomate_s350_map);
}
