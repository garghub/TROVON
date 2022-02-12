static int __init init_rc_map_snapstream_firefly(void)
{
return rc_map_register(&snapstream_firefly_map);
}
static void __exit exit_rc_map_snapstream_firefly(void)
{
rc_map_unregister(&snapstream_firefly_map);
}
