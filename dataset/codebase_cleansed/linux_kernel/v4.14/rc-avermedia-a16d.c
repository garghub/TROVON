static int __init init_rc_map_avermedia_a16d(void)
{
return rc_map_register(&avermedia_a16d_map);
}
static void __exit exit_rc_map_avermedia_a16d(void)
{
rc_map_unregister(&avermedia_a16d_map);
}
