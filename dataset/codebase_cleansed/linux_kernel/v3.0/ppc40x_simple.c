static int __init ppc40x_device_probe(void)
{
of_platform_bus_probe(NULL, ppc40x_of_bus, NULL);
return 0;
}
static int __init ppc40x_probe(void)
{
if (of_flat_dt_match(of_get_flat_dt_root(), board)) {
ppc_pci_set_flags(PPC_PCI_REASSIGN_ALL_RSRC);
return 1;
}
return 0;
}
