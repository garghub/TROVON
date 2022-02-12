static int __init init_rc_map_asus_ps3_100(void)
{
return rc_map_register(&asus_ps3_100_map);
}
static void __exit exit_rc_map_asus_ps3_100(void)
{
rc_map_unregister(&asus_ps3_100_map);
}
