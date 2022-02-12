static int __init init_rc_map_trekstor(void)
{
return rc_map_register(&trekstor_map);
}
static void __exit exit_rc_map_trekstor(void)
{
rc_map_unregister(&trekstor_map);
}
