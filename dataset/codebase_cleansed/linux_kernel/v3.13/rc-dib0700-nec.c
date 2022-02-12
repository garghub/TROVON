static int __init init_rc_map(void)
{
return rc_map_register(&dib0700_nec_map);
}
static void __exit exit_rc_map(void)
{
rc_map_unregister(&dib0700_nec_map);
}
