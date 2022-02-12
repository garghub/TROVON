static int __init mpc512x_generic_probe(void)
{
if (!of_device_compatible_match(of_root, board))
return 0;
mpc512x_init_early();
return 1;
}
