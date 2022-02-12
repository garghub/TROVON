static int __init init_rc_map_medion_x10(void)
{
return rc_map_register(&medion_x10_map);
}
static void __exit exit_rc_map_medion_x10(void)
{
rc_map_unregister(&medion_x10_map);
}
