static int __init virtex_device_probe(void)
{
of_platform_bus_probe(NULL, xilinx_of_bus_ids, NULL);
return 0;
}
static int __init virtex_probe(void)
{
if (!of_machine_is_compatible("xlnx,virtex440"))
return 0;
return 1;
}
