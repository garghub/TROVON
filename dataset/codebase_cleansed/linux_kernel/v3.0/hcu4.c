static int __init hcu4_device_probe(void)
{
of_platform_bus_probe(NULL, hcu4_of_bus, NULL);
return 0;
}
static int __init hcu4_probe(void)
{
unsigned long root = of_get_flat_dt_root();
if (!of_flat_dt_is_compatible(root, "netstal,hcu4"))
return 0;
return 1;
}
