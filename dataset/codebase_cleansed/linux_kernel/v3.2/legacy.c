static void __devinit pcibios_fixup_peer_bridges(void)
{
int n;
if (pcibios_last_bus <= 0 || pcibios_last_bus > 0xff)
return;
DBG("PCI: Peer bridge fixup\n");
for (n=0; n <= pcibios_last_bus; n++)
pcibios_scan_specific_bus(n);
}
int __init pci_legacy_init(void)
{
if (!raw_pci_ops) {
printk("PCI: System does not support PCI\n");
return 0;
}
printk("PCI: Probing PCI hardware\n");
pci_root_bus = pcibios_scan_root(0);
if (pci_root_bus)
pci_bus_add_devices(pci_root_bus);
return 0;
}
void __devinit pcibios_scan_specific_bus(int busn)
{
int devfn;
long node;
u32 l;
if (pci_find_bus(0, busn))
return;
node = get_mp_bus_to_node(busn);
for (devfn = 0; devfn < 256; devfn += 8) {
if (!raw_pci_read(0, busn, devfn, PCI_VENDOR_ID, 2, &l) &&
l != 0x0000 && l != 0xffff) {
DBG("Found device at %02x:%02x [%04x]\n", busn, devfn, l);
printk(KERN_INFO "PCI: Discovered peer bus %02x\n", busn);
pci_scan_bus_on_node(busn, &pci_root_ops, node);
return;
}
}
}
int __init pci_subsys_init(void)
{
if (x86_init.pci.init())
pci_legacy_init();
pcibios_fixup_peer_bridges();
x86_init.pci.init_irq();
pcibios_init();
return 0;
}
