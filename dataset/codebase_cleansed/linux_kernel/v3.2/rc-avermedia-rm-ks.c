static int __init init_rc_map_avermedia_rm_ks(void)
{
return rc_map_register(&avermedia_rm_ks_map);
}
static void __exit exit_rc_map_avermedia_rm_ks(void)
{
rc_map_unregister(&avermedia_rm_ks_map);
}
