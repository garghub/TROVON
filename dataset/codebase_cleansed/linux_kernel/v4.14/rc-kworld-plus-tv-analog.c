static int __init init_rc_map_kworld_plus_tv_analog(void)
{
return rc_map_register(&kworld_plus_tv_analog_map);
}
static void __exit exit_rc_map_kworld_plus_tv_analog(void)
{
rc_map_unregister(&kworld_plus_tv_analog_map);
}
