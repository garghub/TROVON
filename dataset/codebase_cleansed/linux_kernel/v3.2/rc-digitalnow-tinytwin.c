static int __init init_rc_map_digitalnow_tinytwin(void)
{
return rc_map_register(&digitalnow_tinytwin_map);
}
static void __exit exit_rc_map_digitalnow_tinytwin(void)
{
rc_map_unregister(&digitalnow_tinytwin_map);
}
