static int __init init_rc_map_powercolor_real_angel(void)
{
return rc_map_register(&powercolor_real_angel_map);
}
static void __exit exit_rc_map_powercolor_real_angel(void)
{
rc_map_unregister(&powercolor_real_angel_map);
}
