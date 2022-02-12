static int __init init_rc_map_azurewave_ad_tu700(void)
{
return rc_map_register(&azurewave_ad_tu700_map);
}
static void __exit exit_rc_map_azurewave_ad_tu700(void)
{
rc_map_unregister(&azurewave_ad_tu700_map);
}
