static int __init ppc40x_device_probe(void)
{
of_platform_bus_probe(NULL, ppc40x_of_bus, NULL);
return 0;
}
static int __init ppc40x_probe(void)
{
if (of_device_compatible_match(of_root, board)) {
pci_set_flags(PCI_REASSIGN_ALL_RSRC);
return 1;
}
return 0;
}
