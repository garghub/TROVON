static int __init init_rc_map_behold_columbus(void)
{
return rc_map_register(&behold_columbus_map);
}
static void __exit exit_rc_map_behold_columbus(void)
{
rc_map_unregister(&behold_columbus_map);
}
