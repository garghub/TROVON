static int __init init_rc_map_imon_pad(void)
{
return rc_map_register(&imon_pad_map);
}
static void __exit exit_rc_map_imon_pad(void)
{
rc_map_unregister(&imon_pad_map);
}
