static void cardbus_config_irq_and_cls(struct pci_bus *bus, int irq)
{
struct pci_dev *dev;
list_for_each_entry(dev, &bus->devices, bus_list) {
u8 irq_pin;
pci_read_config_byte(dev, PCI_INTERRUPT_PIN, &irq_pin);
if (irq_pin) {
dev->irq = irq;
pci_write_config_byte(dev, PCI_INTERRUPT_LINE, dev->irq);
}
pci_set_cacheline_size(dev);
if (dev->subordinate)
cardbus_config_irq_and_cls(dev->subordinate, irq);
}
}
int __ref cb_alloc(struct pcmcia_socket *s)
{
struct pci_bus *bus = s->cb_dev->subordinate;
struct pci_dev *dev;
unsigned int max, pass;
s->functions = pci_scan_slot(bus, PCI_DEVFN(0, 0));
pci_fixup_cardbus(bus);
max = bus->busn_res.start;
for (pass = 0; pass < 2; pass++)
list_for_each_entry(dev, &bus->devices, bus_list)
if (dev->hdr_type == PCI_HEADER_TYPE_BRIDGE ||
dev->hdr_type == PCI_HEADER_TYPE_CARDBUS)
max = pci_scan_bridge(bus, dev, max, pass);
pci_bus_size_bridges(bus);
pci_bus_assign_resources(bus);
cardbus_config_irq_and_cls(bus, s->pci_irq);
if (s->tune_bridge)
s->tune_bridge(s, bus);
pci_bus_add_devices(bus);
return 0;
}
void cb_free(struct pcmcia_socket *s)
{
struct pci_dev *bridge, *dev, *tmp;
struct pci_bus *bus;
bridge = s->cb_dev;
if (!bridge)
return;
bus = bridge->subordinate;
if (!bus)
return;
list_for_each_entry_safe(dev, tmp, &bus->devices, bus_list)
pci_stop_and_remove_bus_device(dev);
}
