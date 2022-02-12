static int __init init_rc_map_pixelview(void)
{
return rc_map_register(&pixelview_map);
}
static void __exit exit_rc_map_pixelview(void)
{
rc_map_unregister(&pixelview_map);
}
