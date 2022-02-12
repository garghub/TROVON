static int __init init_rc_map_lirc(void)
{
return rc_map_register(&lirc_map);
}
static void __exit exit_rc_map_lirc(void)
{
rc_map_unregister(&lirc_map);
}
