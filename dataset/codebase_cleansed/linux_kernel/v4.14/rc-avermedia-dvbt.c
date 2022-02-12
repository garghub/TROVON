static int __init init_rc_map_avermedia_dvbt(void)
{
return rc_map_register(&avermedia_dvbt_map);
}
static void __exit exit_rc_map_avermedia_dvbt(void)
{
rc_map_unregister(&avermedia_dvbt_map);
}
