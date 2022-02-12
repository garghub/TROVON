static int __init walnut_device_probe(void)
{
of_platform_bus_probe(NULL, walnut_of_bus, NULL);
of_instantiate_rtc();
return 0;
}
static int __init walnut_probe(void)
{
unsigned long root = of_get_flat_dt_root();
if (!of_flat_dt_is_compatible(root, "ibm,walnut"))
return 0;
ppc_pci_flags = PPC_PCI_REASSIGN_ALL_RSRC;
return 1;
}
