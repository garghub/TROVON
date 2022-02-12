static int __init init_rc_map_encore_enltv2(void)
{
return rc_map_register(&encore_enltv2_map);
}
static void __exit exit_rc_map_encore_enltv2(void)
{
rc_map_unregister(&encore_enltv2_map);
}
