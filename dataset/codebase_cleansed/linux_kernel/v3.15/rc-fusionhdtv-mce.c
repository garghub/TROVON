static int __init init_rc_map_fusionhdtv_mce(void)
{
return rc_map_register(&fusionhdtv_mce_map);
}
static void __exit exit_rc_map_fusionhdtv_mce(void)
{
rc_map_unregister(&fusionhdtv_mce_map);
}
