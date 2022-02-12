static int __init virtex_device_probe(void)
{
of_platform_bus_probe(NULL, xilinx_of_bus_ids, NULL);
return 0;
}
static int __init virtex_probe(void)
{
unsigned long root = of_get_flat_dt_root();
if (!of_flat_dt_is_compatible(root, "xlnx,virtex"))
return 0;
return 1;
}
