static int __init init_rc_map_winfast_usbii_deluxe(void)
{
return rc_map_register(&winfast_usbii_deluxe_map);
}
static void __exit exit_rc_map_winfast_usbii_deluxe(void)
{
rc_map_unregister(&winfast_usbii_deluxe_map);
}
