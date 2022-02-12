static int __init init_rc_map_manli(void)
{
return rc_map_register(&manli_map);
}
static void __exit exit_rc_map_manli(void)
{
rc_map_unregister(&manli_map);
}
