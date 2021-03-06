static inline int __query(const struct pci_dev *dev)
{
return 0;
}
static int pci_frv_read_config(struct pci_bus *bus, unsigned int devfn, int where, int size,
u32 *val)
{
u32 _value;
if (bus->number == 0 && devfn == PCI_DEVFN(0, 0)) {
_value = __get_PciBridgeDataL(where & ~3);
}
else {
__set_PciCfgAddr(CONFIG_CMD(bus, devfn, where));
_value = __get_PciCfgDataL(where & ~3);
}
switch (size) {
case 1:
_value = _value >> ((where & 3) * 8);
break;
case 2:
_value = _value >> ((where & 2) * 8);
break;
case 4:
break;
default:
BUG();
}
*val = _value;
return PCIBIOS_SUCCESSFUL;
}
static int pci_frv_write_config(struct pci_bus *bus, unsigned int devfn, int where, int size,
u32 value)
{
switch (size) {
case 1:
if (bus->number == 0 && devfn == PCI_DEVFN(0, 0)) {
__set_PciBridgeDataB(where, value);
}
else {
__set_PciCfgAddr(CONFIG_CMD(bus, devfn, where));
__set_PciCfgDataB(where, value);
}
break;
case 2:
if (bus->number == 0 && devfn == PCI_DEVFN(0, 0)) {
__set_PciBridgeDataW(where, value);
}
else {
__set_PciCfgAddr(CONFIG_CMD(bus, devfn, where));
__set_PciCfgDataW(where, value);
}
break;
case 4:
if (bus->number == 0 && devfn == PCI_DEVFN(0, 0)) {
__set_PciBridgeDataL(where, value);
}
else {
__set_PciCfgAddr(CONFIG_CMD(bus, devfn, where));
__set_PciCfgDataL(where, value);
}
break;
default:
BUG();
}
return PCIBIOS_SUCCESSFUL;
}
static int __init pci_sanity_check(struct pci_ops *o)
{
struct pci_bus bus;
u32 id;
bus.number = 0;
if (o->read(&bus, 0, PCI_VENDOR_ID, 4, &id) == PCIBIOS_SUCCESSFUL) {
printk("PCI: VDK Bridge device:vendor: %08x\n", id);
if (id == 0x200e10cf)
return 1;
}
printk("PCI: VDK Bridge: Sanity check failed\n");
return 0;
}
static struct pci_ops * __init pci_check_direct(void)
{
unsigned long flags;
local_irq_save(flags);
if (pci_sanity_check(&pci_direct_frv)) {
local_irq_restore(flags);
printk("PCI: Using configuration frv\n");
return &pci_direct_frv;
}
local_irq_restore(flags);
return NULL;
}
static void __init pcibios_fixup_peer_bridges(void)
{
struct pci_bus bus;
struct pci_dev dev;
int n;
u16 l;
if (pcibios_last_bus <= 0 || pcibios_last_bus >= 0xff)
return;
printk("PCI: Peer bridge fixup\n");
for (n=0; n <= pcibios_last_bus; n++) {
if (pci_find_bus(0, n))
continue;
bus.number = n;
bus.ops = pci_root_ops;
dev.bus = &bus;
for(dev.devfn=0; dev.devfn<256; dev.devfn += 8)
if (!pci_read_config_word(&dev, PCI_VENDOR_ID, &l) &&
l != 0x0000 && l != 0xffff) {
printk("Found device at %02x:%02x [%04x]\n", n, dev.devfn, l);
printk("PCI: Discovered peer bus %02x\n", n);
pci_scan_bus(n, pci_root_ops, NULL);
break;
}
}
}
static void __init pci_fixup_umc_ide(struct pci_dev *d)
{
int i;
printk("PCI: Fixing base address flags for device %s\n", pci_name(d));
for(i=0; i<4; i++)
d->resource[i].flags |= PCI_BASE_ADDRESS_SPACE_IO;
}
static void __init pci_fixup_ide_bases(struct pci_dev *d)
{
int i;
if ((d->class >> 8) != PCI_CLASS_STORAGE_IDE)
return;
printk("PCI: IDE base address fixup for %s\n", pci_name(d));
for(i=0; i<4; i++) {
struct resource *r = &d->resource[i];
if ((r->start & ~0x80) == 0x374) {
r->start |= 2;
r->end = r->start;
}
}
}
static void __init pci_fixup_ide_trash(struct pci_dev *d)
{
int i;
printk("PCI: IDE base address trash cleared for %s\n", pci_name(d));
for(i=0; i<4; i++)
d->resource[i].start = d->resource[i].end = d->resource[i].flags = 0;
}
static void __devinit pci_fixup_latency(struct pci_dev *d)
{
DBG("PCI: Setting max latency to 32\n");
pcibios_max_latency = 32;
}
void __init pcibios_fixup_bus(struct pci_bus *bus)
{
#if 0
printk("### PCIBIOS_FIXUP_BUS(%d)\n",bus->number);
#endif
pci_read_bridge_bases(bus);
if (bus->number == 0) {
struct list_head *ln;
struct pci_dev *dev;
for (ln=bus->devices.next; ln != &bus->devices; ln=ln->next) {
dev = pci_dev_b(ln);
if (dev->devfn == 0) {
dev->resource[0].start = 0;
dev->resource[0].end = 0;
}
}
}
}
int __init pcibios_init(void)
{
struct pci_ops *dir = NULL;
LIST_HEAD(resources);
if (!mb93090_mb00_detected)
return -ENXIO;
__reg_MB86943_sl_ctl |= MB86943_SL_CTL_DRCT_MASTER_SWAP | MB86943_SL_CTL_DRCT_SLAVE_SWAP;
__reg_MB86943_ecs_base(1) = ((__region_CS2 + 0x01000000) >> 9) | 0x08000000;
__reg_MB86943_ecs_base(2) = ((__region_CS2 + 0x00000000) >> 9) | 0x08000000;
*(volatile uint32_t *) (__region_CS1 + 0x848) = 0xe0000000;
*(volatile uint32_t *) (__region_CS1 + 0x8b8) = 0x00000000;
__reg_MB86943_sl_pci_io_base = (__region_CS2 + 0x04000000) >> 9;
__reg_MB86943_sl_pci_mem_base = (__region_CS2 + 0x08000000) >> 9;
__reg_MB86943_pci_sl_io_base = __region_CS2 + 0x04000000;
__reg_MB86943_pci_sl_mem_base = __region_CS2 + 0x08000000;
mb();
__reg_MB86943_pci_arbiter = MB86943_PCIARB_EN;
pci_ioport_resource.start = (__reg_MB86943_sl_pci_io_base << 9) & 0xfffffc00;
pci_ioport_resource.end = (__reg_MB86943_sl_pci_io_range << 9) | 0x3ff;
pci_ioport_resource.end += pci_ioport_resource.start;
printk("PCI IO window: %08llx-%08llx\n",
(unsigned long long) pci_ioport_resource.start,
(unsigned long long) pci_ioport_resource.end);
pci_iomem_resource.start = (__reg_MB86943_sl_pci_mem_base << 9) & 0xfffffc00;
pci_iomem_resource.end = (__reg_MB86943_sl_pci_mem_range << 9) | 0x3ff;
pci_iomem_resource.end += pci_iomem_resource.start;
pci_iomem_resource.start += 0x400;
printk("PCI MEM window: %08llx-%08llx\n",
(unsigned long long) pci_iomem_resource.start,
(unsigned long long) pci_iomem_resource.end);
printk("PCI DMA memory: %08lx-%08lx\n",
dma_coherent_mem_start, dma_coherent_mem_end);
if (insert_resource(&iomem_resource, &pci_iomem_resource) < 0)
panic("Unable to insert PCI IOMEM resource\n");
if (insert_resource(&ioport_resource, &pci_ioport_resource) < 0)
panic("Unable to insert PCI IOPORT resource\n");
if (!pci_probe)
return -ENXIO;
dir = pci_check_direct();
if (dir)
pci_root_ops = dir;
else {
printk("PCI: No PCI bus detected\n");
return -ENXIO;
}
printk("PCI: Probing PCI hardware\n");
pci_add_resource(&resources, &pci_ioport_resource);
pci_add_resource(&resources, &pci_iomem_resource);
pci_root_bus = pci_scan_root_bus(NULL, 0, pci_root_ops, NULL,
&resources);
pcibios_irq_init();
pcibios_fixup_peer_bridges();
pcibios_fixup_irqs();
pcibios_resource_survey();
return 0;
}
char * __init pcibios_setup(char *str)
{
if (!strcmp(str, "off")) {
pci_probe = 0;
return NULL;
} else if (!strncmp(str, "lastbus=", 8)) {
pcibios_last_bus = simple_strtol(str+8, NULL, 0);
return NULL;
}
return str;
}
int pcibios_enable_device(struct pci_dev *dev, int mask)
{
int err;
if ((err = pci_enable_resources(dev, mask)) < 0)
return err;
if (!dev->msi_enabled)
pcibios_enable_irq(dev);
return 0;
}
