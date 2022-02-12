static int __init init_rc_map_kworld_pc150u(void)
{
return rc_map_register(&kworld_pc150u_map);
}
static void __exit exit_rc_map_kworld_pc150u(void)
{
rc_map_unregister(&kworld_pc150u_map);
}
