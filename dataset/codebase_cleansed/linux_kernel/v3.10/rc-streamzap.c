static int __init init_rc_map_streamzap(void)
{
return rc_map_register(&streamzap_map);
}
static void __exit exit_rc_map_streamzap(void)
{
rc_map_unregister(&streamzap_map);
}
