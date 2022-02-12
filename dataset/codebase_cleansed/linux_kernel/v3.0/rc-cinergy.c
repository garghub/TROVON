static int __init init_rc_map_cinergy(void)
{
return rc_map_register(&cinergy_map);
}
static void __exit exit_rc_map_cinergy(void)
{
rc_map_unregister(&cinergy_map);
}
