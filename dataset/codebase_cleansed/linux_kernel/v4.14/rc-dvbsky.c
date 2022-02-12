static int __init init_rc_map_rc5_dvbsky(void)
{
return rc_map_register(&rc5_dvbsky_map);
}
static void __exit exit_rc_map_rc5_dvbsky(void)
{
rc_map_unregister(&rc5_dvbsky_map);
}
