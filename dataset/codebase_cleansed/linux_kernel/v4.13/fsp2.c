static int __init fsp2_device_probe(void)
{
of_platform_bus_probe(NULL, fsp2_of_bus, NULL);
return 0;
}
static int __init fsp2_probe(void)
{
unsigned long root = of_get_flat_dt_root();
if (!of_flat_dt_is_compatible(root, "ibm,fsp2"))
return 0;
return 1;
}
