static int __init init_rc_map_twinhan_dtv_cab_ci(void)
{
return rc_map_register(&twinhan_dtv_cab_ci_map);
}
static void __exit exit_rc_map_twinhan_dtv_cab_ci(void)
{
rc_map_unregister(&twinhan_dtv_cab_ci_map);
}
