static int __init init_rc_map_dvico_portable(void)
{
return rc_map_register(&dvico_portable_map);
}
static void __exit exit_rc_map_dvico_portable(void)
{
rc_map_unregister(&dvico_portable_map);
}
