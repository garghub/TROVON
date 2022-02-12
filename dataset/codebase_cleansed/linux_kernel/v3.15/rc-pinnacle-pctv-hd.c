static int __init init_rc_map_pinnacle_pctv_hd(void)
{
return rc_map_register(&pinnacle_pctv_hd_map);
}
static void __exit exit_rc_map_pinnacle_pctv_hd(void)
{
rc_map_unregister(&pinnacle_pctv_hd_map);
}
