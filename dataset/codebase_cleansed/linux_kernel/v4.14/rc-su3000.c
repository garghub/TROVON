static int __init init_rc_map_su3000(void)
{
return rc_map_register(&su3000_map);
}
static void __exit exit_rc_map_su3000(void)
{
rc_map_unregister(&su3000_map);
}
