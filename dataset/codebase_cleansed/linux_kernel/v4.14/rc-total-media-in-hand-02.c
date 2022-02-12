static int __init init_rc_map_total_media_in_hand_02(void)
{
return rc_map_register(&total_media_in_hand_02_map);
}
static void __exit exit_rc_map_total_media_in_hand_02(void)
{
rc_map_unregister(&total_media_in_hand_02_map);
}
