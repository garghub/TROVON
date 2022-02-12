static int __init init_rc_map(void)
{
return rc_map_register(&technisat_usb2_map);
}
static void __exit exit_rc_map(void)
{
rc_map_unregister(&technisat_usb2_map);
}
