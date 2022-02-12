static int __init init_rc_map_ati_x10(void)
{
return rc_map_register(&ati_x10_map);
}
static void __exit exit_rc_map_ati_x10(void)
{
rc_map_unregister(&ati_x10_map);
}
