static int __init init_rc_map_reddo(void)
{
return rc_map_register(&reddo_map);
}
static void __exit exit_rc_map_reddo(void)
{
rc_map_unregister(&reddo_map);
}
