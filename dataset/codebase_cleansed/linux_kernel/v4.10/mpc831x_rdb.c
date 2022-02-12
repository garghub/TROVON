static void __init mpc831x_rdb_setup_arch(void)
{
mpc83xx_setup_arch();
mpc831x_usb_cfg();
}
static int __init mpc831x_rdb_probe(void)
{
return of_device_compatible_match(of_root, board);
}
