int bridge_probe(nasid_t nasid, int widget_id, int masterwid)
{
unsigned long offset = NODE_OFFSET(nasid);
struct bridge_controller *bc;
static int num_bridges = 0;
bridge_t *bridge;
int slot;
pci_set_flags(PCI_PROBE_ONLY);
printk("a bridge\n");
if (!num_bridges)
ioport_resource.end = ~0UL;
bc = &bridges[num_bridges];
bc->pc.pci_ops = &bridge_pci_ops;
bc->pc.mem_resource = &bc->mem;
bc->pc.io_resource = &bc->io;
bc->pc.index = num_bridges;
bc->mem.name = "Bridge PCI MEM";
bc->pc.mem_offset = offset;
bc->mem.start = 0;
bc->mem.end = ~0UL;
bc->mem.flags = IORESOURCE_MEM;
bc->io.name = "Bridge IO MEM";
bc->pc.io_offset = offset;
bc->io.start = 0UL;
bc->io.end = ~0UL;
bc->io.flags = IORESOURCE_IO;
bc->irq_cpu = smp_processor_id();
bc->widget_id = widget_id;
bc->nasid = nasid;
bc->baddr = (u64)masterwid << 60 | PCI64_ATTR_BAR;
bridge = (bridge_t *) RAW_NODE_SWIN_BASE(nasid, widget_id);
bridge->b_int_rst_stat = BRIDGE_IRR_ALL_CLR;
bridge->b_int_device = 0x0;
bridge->b_wid_control |= BRIDGE_CTRL_IO_SWAP |
BRIDGE_CTRL_MEM_SWAP;
#ifdef CONFIG_PAGE_SIZE_4KB
bridge->b_wid_control &= ~BRIDGE_CTRL_PAGE_SIZE;
#else
bridge->b_wid_control |= BRIDGE_CTRL_PAGE_SIZE;
#endif
bridge->b_wid_int_upper = 0x8000 | (masterwid << 16);
bridge->b_wid_int_lower = 0x01800090;
bridge->b_dir_map = (masterwid << 20);
bridge->b_int_enable = 0;
for (slot = 0; slot < 8; slot ++) {
bridge->b_device[slot].reg |= BRIDGE_DEV_SWAP_DIR;
bc->pci_int[slot] = -1;
}
bridge->b_wid_tflush;
bc->base = bridge;
register_pci_controller(&bc->pc);
num_bridges++;
return 0;
}
int pcibios_map_irq(const struct pci_dev *dev, u8 slot, u8 pin)
{
return 0;
}
static inline struct pci_dev *bridge_root_dev(struct pci_dev *dev)
{
while (dev->bus->parent) {
dev = dev->bus->self;
}
return dev;
}
int pcibios_plat_dev_init(struct pci_dev *dev)
{
struct bridge_controller *bc = BRIDGE_CONTROLLER(dev->bus);
struct pci_dev *rdev = bridge_root_dev(dev);
int slot = PCI_SLOT(rdev->devfn);
int irq;
irq = bc->pci_int[slot];
if (irq == -1) {
irq = request_bridge_irq(bc);
if (irq < 0)
return irq;
bc->pci_int[slot] = irq;
}
irq_to_bridge[irq] = bc;
irq_to_slot[irq] = slot;
dev->irq = irq;
return 0;
}
static inline void pci_disable_swapping(struct pci_dev *dev)
{
struct bridge_controller *bc = BRIDGE_CONTROLLER(dev->bus);
bridge_t *bridge = bc->base;
int slot = PCI_SLOT(dev->devfn);
bridge->b_device[slot].reg &= ~BRIDGE_DEV_SWAP_DIR;
bridge->b_widget.w_tflush;
}
static inline void pci_enable_swapping(struct pci_dev *dev)
{
struct bridge_controller *bc = BRIDGE_CONTROLLER(dev->bus);
bridge_t *bridge = bc->base;
int slot = PCI_SLOT(dev->devfn);
bridge->b_device[slot].reg |= BRIDGE_DEV_SWAP_DIR;
bridge->b_widget.w_tflush;
}
static void pci_fixup_ioc3(struct pci_dev *d)
{
pci_disable_swapping(d);
}
int pcibus_to_node(struct pci_bus *bus)
{
struct bridge_controller *bc = BRIDGE_CONTROLLER(bus);
return bc->nasid;
}
