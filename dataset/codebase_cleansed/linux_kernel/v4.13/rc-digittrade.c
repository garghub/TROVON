static int __init init_rc_map_digittrade(void)
{
return rc_map_register(&digittrade_map);
}
static void __exit exit_rc_map_digittrade(void)
{
rc_map_unregister(&digittrade_map);
}
