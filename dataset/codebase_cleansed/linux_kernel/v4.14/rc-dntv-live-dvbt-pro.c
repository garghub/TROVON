static int __init init_rc_map_dntv_live_dvbt_pro(void)
{
return rc_map_register(&dntv_live_dvbt_pro_map);
}
static void __exit exit_rc_map_dntv_live_dvbt_pro(void)
{
rc_map_unregister(&dntv_live_dvbt_pro_map);
}
