static int __init init_rc_map_pixelview_new(void)
{
return rc_map_register(&pixelview_new_map);
}
static void __exit exit_rc_map_pixelview_new(void)
{
rc_map_unregister(&pixelview_new_map);
}
