static int __init init_rc_map_dm1105_nec(void)
{
return rc_map_register(&dm1105_nec_map);
}
static void __exit exit_rc_map_dm1105_nec(void)
{
rc_map_unregister(&dm1105_nec_map);
}
