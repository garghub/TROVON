static int __init init_rc_map_gadmei_rm008z(void)
{
return rc_map_register(&gadmei_rm008z_map);
}
static void __exit exit_rc_map_gadmei_rm008z(void)
{
rc_map_unregister(&gadmei_rm008z_map);
}
