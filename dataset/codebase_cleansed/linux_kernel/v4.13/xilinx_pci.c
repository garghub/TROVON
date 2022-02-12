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
static void __init xilinx_early_pci_scan(struct pci_controller *hose)
{
u32 bus = 0;
u32 val, dev, func, offset;
for (dev = 0; dev < 2; dev++) {
for (func = 0; func < 1; func++) {
pr_info("%02x:%02x:%02x", bus, dev, func);
for (offset = 0; offset < 64; offset += 4) {
early_read_config_dword(hose, bus,
PCI_DEVFN(dev, func), offset, &val);
if (offset == 0 && val == 0xFFFFFFFF) {
pr_cont("\nABSENT");
break;
}
if (!(offset % 0x10))
pr_cont("\n%04x: ", offset);
pr_cont("%08x ", val);
}
pr_info("\n");
}
}
}
static void __init xilinx_early_pci_scan(struct pci_controller *hose)
{
}
void __init xilinx_pci_init(void)
{
struct pci_controller *hose;
struct resource r;
void __iomem *pci_reg;
struct device_node *pci_node;
pci_node = of_find_matching_node(NULL, xilinx_pci_match);
if (!pci_node)
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
INDIRECT_TYPE_SET_CFG_TYPE);
early_write_config_word(hose, 0, 0, PCI_COMMAND, PCI_HOST_ENABLE_CMD);
early_write_config_byte(hose, 0, 0, PCI_LATENCY_TIMER, 0xff);
pci_reg = of_iomap(pci_node, 0);
out_be32(pci_reg + XPLB_PCI_BUS, 0x000000ff);
iounmap(pci_reg);
pci_process_bridge_OF_ranges(hose, pci_node,
INDIRECT_TYPE_SET_CFG_TYPE);
pr_info("xilinx-pci: Registered PCI host bridge\n");
xilinx_early_pci_scan(hose);
}
