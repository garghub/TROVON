static int __init init_rc_map_videomate_tv_pvr(void)
{
return rc_map_register(&videomate_tv_pvr_map);
}
static void __exit exit_rc_map_videomate_tv_pvr(void)
{
rc_map_unregister(&videomate_tv_pvr_map);
}
