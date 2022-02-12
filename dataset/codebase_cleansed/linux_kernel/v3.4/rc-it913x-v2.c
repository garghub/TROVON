static int __init init_rc_it913x_v2_map(void)
{
return rc_map_register(&it913x_v2_map);
}
static void __exit exit_rc_it913x_v2_map(void)
{
rc_map_unregister(&it913x_v2_map);
}
