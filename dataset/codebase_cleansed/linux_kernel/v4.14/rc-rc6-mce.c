static int __init init_rc_map_rc6_mce(void)
{
return rc_map_register(&rc6_mce_map);
}
static void __exit exit_rc_map_rc6_mce(void)
{
rc_map_unregister(&rc6_mce_map);
}
