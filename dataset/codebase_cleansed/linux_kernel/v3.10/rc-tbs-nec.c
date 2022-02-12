static int __init init_rc_map_tbs_nec(void)
{
return rc_map_register(&tbs_nec_map);
}
static void __exit exit_rc_map_tbs_nec(void)
{
rc_map_unregister(&tbs_nec_map);
}
