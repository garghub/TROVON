static int __init init_rc_map_iodata_bctv7e(void)
{
return rc_map_register(&iodata_bctv7e_map);
}
static void __exit exit_rc_map_iodata_bctv7e(void)
{
rc_map_unregister(&iodata_bctv7e_map);
}
