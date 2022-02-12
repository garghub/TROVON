static int __init ppc44x_device_probe(void)
{
of_platform_bus_probe(NULL, ppc44x_of_bus, NULL);
return 0;
}
static int __init ppc44x_probe(void)
{
unsigned long root = of_get_flat_dt_root();
int i = 0;
for (i = 0; i < ARRAY_SIZE(board); i++) {
if (of_flat_dt_is_compatible(root, board[i])) {
pci_set_flags(PCI_REASSIGN_ALL_RSRC);
return 1;
}
}
return 0;
}
