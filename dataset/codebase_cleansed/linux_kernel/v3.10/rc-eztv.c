static int __init init_rc_map_eztv(void)
{
return rc_map_register(&eztv_map);
}
static void __exit exit_rc_map_eztv(void)
{
rc_map_unregister(&eztv_map);
}
