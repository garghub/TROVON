static int __init init_rc_map_d680_dmb(void)
{
return rc_map_register(&d680_dmb_map);
}
static void __exit exit_rc_map_d680_dmb(void)
{
rc_map_unregister(&d680_dmb_map);
}
