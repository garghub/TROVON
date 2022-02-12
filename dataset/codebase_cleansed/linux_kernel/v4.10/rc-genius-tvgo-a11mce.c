static int __init init_rc_map_genius_tvgo_a11mce(void)
{
return rc_map_register(&genius_tvgo_a11mce_map);
}
static void __exit exit_rc_map_genius_tvgo_a11mce(void)
{
rc_map_unregister(&genius_tvgo_a11mce_map);
}
