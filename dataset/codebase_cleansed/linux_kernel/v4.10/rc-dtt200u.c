static int __init init_rc_map_dtt200u(void)
{
return rc_map_register(&dtt200u_map);
}
static void __exit exit_rc_map_dtt200u(void)
{
rc_map_unregister(&dtt200u_map);
}
