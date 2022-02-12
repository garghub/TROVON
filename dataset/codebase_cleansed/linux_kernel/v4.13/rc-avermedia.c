static int __init init_rc_map_avermedia(void)
{
return rc_map_register(&avermedia_map);
}
static void __exit exit_rc_map_avermedia(void)
{
rc_map_unregister(&avermedia_map);
}
