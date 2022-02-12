static int __init init_rc_map_pv951(void)
{
return rc_map_register(&pv951_map);
}
static void __exit exit_rc_map_pv951(void)
{
rc_map_unregister(&pv951_map);
}
