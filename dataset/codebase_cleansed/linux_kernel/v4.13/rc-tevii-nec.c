static int __init init_rc_map_tevii_nec(void)
{
return rc_map_register(&tevii_nec_map);
}
static void __exit exit_rc_map_tevii_nec(void)
{
rc_map_unregister(&tevii_nec_map);
}
