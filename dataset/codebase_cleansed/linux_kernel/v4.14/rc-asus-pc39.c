static int __init init_rc_map_asus_pc39(void)
{
return rc_map_register(&asus_pc39_map);
}
static void __exit exit_rc_map_asus_pc39(void)
{
rc_map_unregister(&asus_pc39_map);
}
