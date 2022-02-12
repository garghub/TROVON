static int __init init_rc_map_behold(void)
{
return rc_map_register(&behold_map);
}
static void __exit exit_rc_map_behold(void)
{
rc_map_unregister(&behold_map);
}
