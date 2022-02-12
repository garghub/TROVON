resource_size_t pcibios_align_resource(void *data, const struct resource *res,
resource_size_t size, resource_size_t align)
{
return res->start;
}
void pcibios_fixup_bus(struct pci_bus *bus)
{
}
