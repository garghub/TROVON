static int __init init_rc_map_avermedia_m733a_rm_k6(void)
{
return rc_map_register(&avermedia_m733a_rm_k6_map);
}
static void __exit exit_rc_map_avermedia_m733a_rm_k6(void)
{
rc_map_unregister(&avermedia_m733a_rm_k6_map);
}
