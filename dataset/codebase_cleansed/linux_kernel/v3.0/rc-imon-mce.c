static int __init init_rc_map_imon_mce(void)
{
return rc_map_register(&imon_mce_map);
}
static void __exit exit_rc_map_imon_mce(void)
{
rc_map_unregister(&imon_mce_map);
}
