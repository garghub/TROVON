static int __init init_rc_map_tivo(void)
{
return rc_map_register(&tivo_map);
}
static void __exit exit_rc_map_tivo(void)
{
rc_map_unregister(&tivo_map);
}
