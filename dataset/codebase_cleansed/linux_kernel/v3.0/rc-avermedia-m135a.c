static int __init init_rc_map_avermedia_m135a(void)
{
return rc_map_register(&avermedia_m135a_map);
}
static void __exit exit_rc_map_avermedia_m135a(void)
{
rc_map_unregister(&avermedia_m135a_map);
}
