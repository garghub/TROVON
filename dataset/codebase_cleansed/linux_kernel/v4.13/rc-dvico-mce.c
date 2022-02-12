static int __init init_rc_map_dvico_mce(void)
{
return rc_map_register(&dvico_mce_map);
}
static void __exit exit_rc_map_dvico_mce(void)
{
rc_map_unregister(&dvico_mce_map);
}
