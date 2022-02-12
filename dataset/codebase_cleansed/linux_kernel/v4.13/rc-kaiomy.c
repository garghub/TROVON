static int __init init_rc_map_kaiomy(void)
{
return rc_map_register(&kaiomy_map);
}
static void __exit exit_rc_map_kaiomy(void)
{
rc_map_unregister(&kaiomy_map);
}
