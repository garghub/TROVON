static int __init init_rc_map_avermedia_cardbus(void)
{
return rc_map_register(&avermedia_cardbus_map);
}
static void __exit exit_rc_map_avermedia_cardbus(void)
{
rc_map_unregister(&avermedia_cardbus_map);
}
