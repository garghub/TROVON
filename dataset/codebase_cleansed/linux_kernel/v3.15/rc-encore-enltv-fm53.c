static int __init init_rc_map_encore_enltv_fm53(void)
{
return rc_map_register(&encore_enltv_fm53_map);
}
static void __exit exit_rc_map_encore_enltv_fm53(void)
{
rc_map_unregister(&encore_enltv_fm53_map);
}
