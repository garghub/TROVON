static int __init init_rc_map_ati_tv_wonder_hd_600(void)
{
return rc_map_register(&ati_tv_wonder_hd_600_map);
}
static void __exit exit_rc_map_ati_tv_wonder_hd_600(void)
{
rc_map_unregister(&ati_tv_wonder_hd_600_map);
}
