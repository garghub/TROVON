resource_size_t pcibios_align_resource(void *data, const struct resource *res,
resource_size_t size, resource_size_t align)
{
struct pci_dev *dev = data;
resource_size_t start = res->start;
struct pci_host_bridge *host_bridge;
if (res->flags & IORESOURCE_IO && start & 0x300)
start = (start + 0x3ff) & ~0x3ff;
start = (start + align - 1) & ~(align - 1);
host_bridge = pci_find_host_bridge(dev->bus);
if (host_bridge->align_resource)
return host_bridge->align_resource(dev, res,
start, size, align);
return start;
}
void pcibios_fixup_bus(struct pci_bus *bus)
{
pci_read_bridge_bases(bus);
}
