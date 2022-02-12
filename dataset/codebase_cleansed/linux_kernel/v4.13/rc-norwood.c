static int __init init_rc_map_norwood(void)
{
return rc_map_register(&norwood_map);
}
static void __exit exit_rc_map_norwood(void)
{
rc_map_unregister(&norwood_map);
}
