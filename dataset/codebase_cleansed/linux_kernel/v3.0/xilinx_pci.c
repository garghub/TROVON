static void xilinx_pci_fixup_bridge(struct pci_dev *dev)
{
struct pci_controller *hose;
int i;
if (dev->devfn || dev->bus->self)
return;
hose = pci_bus_to_host(dev->bus);
if (!hose)
return;
if (!of_match_node(xilinx_pci_match, hose->dn))
return;
for (i = 0; i < DEVICE_COUNT_RESOURCE; i++) {
dev->resource[i].start = 0;
dev->resource[i].end = 0;
dev->resource[i].flags = 0;
}
dev_info(&dev->dev, "Hiding Xilinx plb-pci host bridge resources %s\n",
pci_name(dev));
}
static int
xilinx_pci_exclude_device(struct pci_controller *hose, u_char bus, u8 devfn)
{
return (bus != 0);
}
void __init xilinx_pci_init(void)
{
struct pci_controller *hose;
struct resource r;
void __iomem *pci_reg;
struct device_node *pci_node;
pci_node = of_find_matching_node(NULL, xilinx_pci_match);
if(!pci_node)
return;
if (of_address_to_resource(pci_node, 0, &r)) {
pr_err("xilinx-pci: cannot resolve base address\n");
return;
}
hose = pcibios_alloc_controller(pci_node);
if (!hose) {
pr_err("xilinx-pci: pcibios_alloc_controller() failed\n");
return;
}
setup_indirect_pci(hose, r.start + XPLB_PCI_ADDR,
r.start + XPLB_PCI_DATA,
PPC_INDIRECT_TYPE_SET_CFG_TYPE);
early_write_config_word(hose, 0, 0, PCI_COMMAND, PCI_HOST_ENABLE_CMD);
early_write_config_byte(hose, 0, 0, PCI_LATENCY_TIMER, 0xff);
pci_reg = of_iomap(pci_node, 0);
out_8(pci_reg + XPLB_PCI_BUS, 0xff);
iounmap(pci_reg);
if (!ppc_md.pci_exclude_device)
ppc_md.pci_exclude_device = xilinx_pci_exclude_device;
pci_process_bridge_OF_ranges(hose, pci_node, 1);
pr_info("xilinx-pci: Registered PCI host bridge\n");
}
