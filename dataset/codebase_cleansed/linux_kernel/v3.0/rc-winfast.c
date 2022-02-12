static int __init init_rc_map_winfast(void)
{
return rc_map_register(&winfast_map);
}
static void __exit exit_rc_map_winfast(void)
{
rc_map_unregister(&winfast_map);
}
