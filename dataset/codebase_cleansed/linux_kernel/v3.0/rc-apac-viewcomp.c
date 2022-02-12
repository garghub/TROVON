static int __init init_rc_map_apac_viewcomp(void)
{
return rc_map_register(&apac_viewcomp_map);
}
static void __exit exit_rc_map_apac_viewcomp(void)
{
rc_map_unregister(&apac_viewcomp_map);
}
