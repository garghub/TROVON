static int __init init_rc_map_alink_dtu_m(void)
{
return rc_map_register(&alink_dtu_m_map);
}
static void __exit exit_rc_map_alink_dtu_m(void)
{
rc_map_unregister(&alink_dtu_m_map);
}
