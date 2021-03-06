static void __init
pciauto_setup_bars(struct pci_dev *dev, int bar_limit)
{
int bar_size;
int bar, bar_nr;
int *upper_limit;
int found_mem64 = 0;
for (bar = PCI_BASE_ADDRESS_0, bar_nr = 0;
bar <= bar_limit;
bar+=4, bar_nr++)
{
pci_write_config_dword(dev, bar, 0xffffffff);
pci_read_config_dword(dev, bar, &bar_size);
if (!bar_size)
continue;
if (bar_size & PCI_BASE_ADDRESS_SPACE_IO)
{
bar_size &= PCI_BASE_ADDRESS_IO_MASK;
upper_limit = &pciauto_upper_iospc;
DBG("PCI Autoconfig: BAR %d, I/O, ", bar_nr);
}
else
{
if ((bar_size & PCI_BASE_ADDRESS_MEM_TYPE_MASK) ==
PCI_BASE_ADDRESS_MEM_TYPE_64)
found_mem64 = 1;
bar_size &= PCI_BASE_ADDRESS_MEM_MASK;
upper_limit = &pciauto_upper_memspc;
DBG("PCI Autoconfig: BAR %d, Mem, ", bar_nr);
}
*upper_limit = (*upper_limit + bar_size) & bar_size;
pci_write_config_dword(dev, bar, *upper_limit);
if (found_mem64)
pci_write_config_dword(dev, (bar+=4), 0x00000000);
DBG("size=0x%x, address=0x%x\n", ~bar_size + 1, *upper_limit);
}
}
static void __init
pciauto_setup_irq(struct pci_controller* pci_ctrl,struct pci_dev *dev,int devfn)
{
u8 pin;
int irq = 0;
pci_read_config_byte(dev, PCI_INTERRUPT_PIN, &pin);
if (pin == 0 || pin > 4)
pin = 1;
if (pci_ctrl->map_irq)
irq = pci_ctrl->map_irq(dev, PCI_SLOT(devfn), pin);
if (irq == -1)
irq = 0;
DBG("PCI Autoconfig: Interrupt %d, pin %d\n", irq, pin);
pci_write_config_byte(dev, PCI_INTERRUPT_LINE, irq);
}
static void __init
pciauto_prescan_setup_bridge(struct pci_dev *dev, int current_bus,
int sub_bus, int *iosave, int *memsave)
{
pci_write_config_byte(dev, PCI_PRIMARY_BUS, current_bus);
pci_write_config_byte(dev, PCI_SECONDARY_BUS, sub_bus + 1);
pci_write_config_byte(dev, PCI_SUBORDINATE_BUS, 0xff);
pciauto_upper_memspc &= ~(0x100000 - 1);
*memsave = pciauto_upper_memspc;
pciauto_upper_iospc &= ~(0x1000 - 1);
*iosave = pciauto_upper_iospc;
pci_write_config_word(dev, PCI_MEMORY_LIMIT,
((pciauto_upper_memspc - 1) & 0xfff00000) >> 16);
pci_write_config_byte(dev, PCI_IO_LIMIT,
((pciauto_upper_iospc - 1) & 0x0000f000) >> 8);
pci_write_config_word(dev, PCI_IO_LIMIT_UPPER16,
((pciauto_upper_iospc - 1) & 0xffff0000) >> 16);
}
static void __init
pciauto_postscan_setup_bridge(struct pci_dev *dev, int current_bus, int sub_bus,
int *iosave, int *memsave)
{
int cmdstat;
pci_write_config_byte(dev, PCI_SUBORDINATE_BUS, sub_bus);
pciauto_upper_memspc &= ~(0x100000 - 1);
if (*memsave == pciauto_upper_memspc)
pciauto_upper_memspc -= 0x00100000;
pci_write_config_word(dev, PCI_MEMORY_BASE, pciauto_upper_memspc >> 16);
pci_write_config_word(dev, PCI_PREF_MEMORY_LIMIT,
((pciauto_upper_memspc - 1) & 0xfff00000) >> 16);
pciauto_upper_memspc -= 0x100000;
pci_write_config_word(dev, PCI_PREF_MEMORY_BASE,
pciauto_upper_memspc >> 16);
pciauto_upper_iospc &= ~(0x1000 - 1);
if (*iosave == pciauto_upper_iospc)
pciauto_upper_iospc -= 0x1000;
pci_write_config_byte(dev, PCI_IO_BASE,
(pciauto_upper_iospc & 0x0000f000) >> 8);
pci_write_config_word(dev, PCI_IO_BASE_UPPER16,
pciauto_upper_iospc >> 16);
pci_read_config_dword(dev, PCI_COMMAND, &cmdstat);
pci_write_config_dword(dev, PCI_COMMAND,
cmdstat |
PCI_COMMAND_IO |
PCI_COMMAND_MEMORY |
PCI_COMMAND_MASTER);
}
int __init pciauto_bus_scan(struct pci_controller *pci_ctrl, int current_bus)
{
int sub_bus, pci_devfn, pci_class, cmdstat, found_multi=0;
unsigned short vid;
unsigned char header_type;
struct pci_dev *dev = &pciauto_dev;
pciauto_dev.bus = &pciauto_bus;
pciauto_dev.sysdata = pci_ctrl;
pciauto_bus.ops = pci_ctrl->ops;
if (current_bus == pci_ctrl->first_busno)
{
pciauto_upper_iospc = pci_ctrl->io_resource.end + 1;
pciauto_upper_memspc = pci_ctrl->mem_resources[0].end + 1;
}
sub_bus = current_bus;
for (pci_devfn = 0; pci_devfn < 0xff; pci_devfn++)
{
if ((current_bus == pci_ctrl->first_busno) && (pci_devfn == 0))
continue;
if (PCI_FUNC(pci_devfn) && !found_multi)
continue;
pciauto_bus.number = current_bus;
pciauto_dev.devfn = pci_devfn;
if (pci_read_config_byte(dev, PCI_HEADER_TYPE, &header_type))
continue;
if (!PCI_FUNC(pci_devfn))
found_multi = header_type & 0x80;
pci_read_config_word(dev, PCI_VENDOR_ID, &vid);
if (vid == 0xffff || vid == 0x0000) {
found_multi = 0;
continue;
}
pci_read_config_dword(dev, PCI_CLASS_REVISION, &pci_class);
if ((pci_class >> 16) == PCI_CLASS_BRIDGE_PCI) {
int iosave, memsave;
DBG("PCI Autoconfig: Found P2P bridge, device %d\n",
PCI_SLOT(pci_devfn));
pciauto_setup_bars(dev, PCI_BASE_ADDRESS_1);
pciauto_prescan_setup_bridge(dev, current_bus, sub_bus,
&iosave, &memsave);
sub_bus = pciauto_bus_scan(pci_ctrl, sub_bus+1);
pciauto_postscan_setup_bridge(dev, current_bus, sub_bus,
&iosave, &memsave);
pciauto_bus.number = current_bus;
continue;
}
#if 0
if ((pci_class >> 16) == PCI_CLASS_STORAGE_IDE) {
unsigned char prg_iface;
pci_read_config_byte(dev, PCI_CLASS_PROG, &prg_iface);
if (!(prg_iface & PCIAUTO_IDE_MODE_MASK)) {
DBG("PCI Autoconfig: Skipping legacy mode "
"IDE controller\n");
continue;
}
}
#endif
pci_read_config_dword(dev, PCI_COMMAND, &cmdstat);
pci_write_config_dword(dev, PCI_COMMAND,
cmdstat |
PCI_COMMAND_IO |
PCI_COMMAND_MEMORY |
PCI_COMMAND_MASTER);
pci_write_config_byte(dev, PCI_LATENCY_TIMER, 0x80);
DBG("PCI Autoconfig: Found Bus %d, Device %d, Function %d\n",
current_bus, PCI_SLOT(pci_devfn), PCI_FUNC(pci_devfn) );
pciauto_setup_bars(dev, PCI_BASE_ADDRESS_5);
pciauto_setup_irq(pci_ctrl, dev, pci_devfn);
}
return sub_bus;
}
