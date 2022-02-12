static int __init init_rc_map_flydvb(void)
{
return rc_map_register(&flydvb_map);
}
static void __exit exit_rc_map_flydvb(void)
{
rc_map_unregister(&flydvb_map);
}
