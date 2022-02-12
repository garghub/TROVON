static int __init init_rc_map_cec(void)
{
return rc_map_register(&cec_map);
}
static void __exit exit_rc_map_cec(void)
{
rc_map_unregister(&cec_map);
}
