static int __init init_rc_map_evga_indtube(void)
{
return rc_map_register(&evga_indtube_map);
}
static void __exit exit_rc_map_evga_indtube(void)
{
rc_map_unregister(&evga_indtube_map);
}
