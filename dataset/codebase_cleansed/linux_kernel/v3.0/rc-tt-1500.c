static int __init init_rc_map_tt_1500(void)
{
return rc_map_register(&tt_1500_map);
}
static void __exit exit_rc_map_tt_1500(void)
{
rc_map_unregister(&tt_1500_map);
}
