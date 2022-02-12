static int __init walnut_device_probe(void)
{
of_platform_bus_probe(NULL, walnut_of_bus, NULL);
of_instantiate_rtc();
return 0;
}
static int __init walnut_probe(void)
{
if (!of_machine_is_compatible("ibm,walnut"))
return 0;
pci_set_flags(PCI_REASSIGN_ALL_RSRC);
return 1;
}
