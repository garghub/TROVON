static int __init init_rc_map_anysee(void)
{
return rc_map_register(&anysee_map);
}
static void __exit exit_rc_map_anysee(void)
{
rc_map_unregister(&anysee_map);
}
