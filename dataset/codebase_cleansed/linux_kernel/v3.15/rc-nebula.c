static int __init init_rc_map_nebula(void)
{
return rc_map_register(&nebula_map);
}
static void __exit exit_rc_map_nebula(void)
{
rc_map_unregister(&nebula_map);
}
