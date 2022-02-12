static inline u64 sal_get_hubdev_info(u64 handle, u64 address)
{
struct ia64_sal_retval ret_stuff;
ret_stuff.status = 0;
ret_stuff.v0 = 0;
SAL_CALL_NOLOCK(ret_stuff,
(u64) SN_SAL_IOIF_GET_HUBDEV_INFO,
(u64) handle, (u64) address, 0, 0, 0, 0, 0);
return ret_stuff.v0;
}
static inline u64 sal_get_pcibus_info(u64 segment, u64 busnum, u64 address)
{
struct ia64_sal_retval ret_stuff;
ret_stuff.status = 0;
ret_stuff.v0 = 0;
SAL_CALL_NOLOCK(ret_stuff,
(u64) SN_SAL_IOIF_GET_PCIBUS_INFO,
(u64) segment, (u64) busnum, (u64) address, 0, 0, 0, 0);
return ret_stuff.v0;
}
static inline u64
sal_get_pcidev_info(u64 segment, u64 bus_number, u64 devfn, u64 pci_dev,
u64 sn_irq_info)
{
struct ia64_sal_retval ret_stuff;
ret_stuff.status = 0;
ret_stuff.v0 = 0;
SAL_CALL_NOLOCK(ret_stuff,
(u64) SN_SAL_IOIF_GET_PCIDEV_INFO,
(u64) segment, (u64) bus_number, (u64) devfn,
(u64) pci_dev,
sn_irq_info, 0, 0);
return ret_stuff.v0;
}
static void __init sn_fixup_ionodes(void)
{
struct hubdev_info *hubdev;
u64 status;
u64 nasid;
int i;
extern void sn_common_hubdev_init(struct hubdev_info *);
for (i = 0; i < num_cnodes; i++) {
hubdev = (struct hubdev_info *)(NODEPDA(i)->pdinfo);
nasid = cnodeid_to_nasid(i);
hubdev->max_segment_number = 0xffffffff;
hubdev->max_pcibus_number = 0xff;
status = sal_get_hubdev_info(nasid, (u64) __pa(hubdev));
if (status)
continue;
if (hubdev->max_segment_number) {
max_segment_number = hubdev->max_segment_number;
max_pcibus_number = hubdev->max_pcibus_number;
}
sn_common_hubdev_init(hubdev);
}
}
static void
sn_legacy_pci_window_fixup(struct resource *res,
u64 legacy_io, u64 legacy_mem)
{
res[0].name = "legacy_io";
res[0].flags = IORESOURCE_IO;
res[0].start = legacy_io;
res[0].end = res[0].start + 0xffff;
res[0].parent = &ioport_resource;
res[1].name = "legacy_mem";
res[1].flags = IORESOURCE_MEM;
res[1].start = legacy_mem;
res[1].end = res[1].start + (1024 * 1024) - 1;
res[1].parent = &iomem_resource;
}
void
sn_io_slot_fixup(struct pci_dev *dev)
{
int idx;
struct resource *res;
unsigned long addr, size;
struct pcidev_info *pcidev_info;
struct sn_irq_info *sn_irq_info;
int status;
pcidev_info = kzalloc(sizeof(struct pcidev_info), GFP_KERNEL);
if (!pcidev_info)
panic("%s: Unable to alloc memory for pcidev_info", __func__);
sn_irq_info = kzalloc(sizeof(struct sn_irq_info), GFP_KERNEL);
if (!sn_irq_info)
panic("%s: Unable to alloc memory for sn_irq_info", __func__);
status = sal_get_pcidev_info((u64) pci_domain_nr(dev),
(u64) dev->bus->number,
dev->devfn,
(u64) __pa(pcidev_info),
(u64) __pa(sn_irq_info));
BUG_ON(status);
for (idx = 0; idx <= PCI_ROM_RESOURCE; idx++) {
if (!pcidev_info->pdi_pio_mapped_addr[idx])
continue;
res = &dev->resource[idx];
size = res->end - res->start;
if (size == 0)
continue;
res->start = pcidev_info->pdi_pio_mapped_addr[idx];
res->end = addr + size;
if (res->parent && res->parent->child)
release_resource(res);
if (res->flags & IORESOURCE_IO)
insert_resource(&ioport_resource, res);
else
insert_resource(&iomem_resource, res);
if (idx == PCI_ROM_RESOURCE) {
pci_disable_rom(dev);
res->flags = IORESOURCE_MEM | IORESOURCE_ROM_SHADOW |
IORESOURCE_PCI_FIXED;
}
}
sn_pci_fixup_slot(dev, pcidev_info, sn_irq_info);
}
static void __init
sn_pci_controller_fixup(int segment, int busnum, struct pci_bus *bus)
{
s64 status = 0;
struct pci_controller *controller;
struct pcibus_bussoft *prom_bussoft_ptr;
struct resource *res;
LIST_HEAD(resources);
status = sal_get_pcibus_info((u64) segment, (u64) busnum,
(u64) ia64_tpa(&prom_bussoft_ptr));
if (status > 0)
return;
prom_bussoft_ptr = __va(prom_bussoft_ptr);
controller = kzalloc(sizeof(*controller), GFP_KERNEL);
BUG_ON(!controller);
controller->segment = segment;
res = kcalloc(2, sizeof(struct resource), GFP_KERNEL);
BUG_ON(!res);
controller->platform_data = prom_bussoft_ptr;
sn_legacy_pci_window_fixup(res,
prom_bussoft_ptr->bs_legacy_io,
prom_bussoft_ptr->bs_legacy_mem);
pci_add_resource_offset(&resources, &res[0],
prom_bussoft_ptr->bs_legacy_io);
pci_add_resource_offset(&resources, &res[1],
prom_bussoft_ptr->bs_legacy_mem);
bus = pci_scan_root_bus(NULL, busnum, &pci_root_ops, controller,
&resources);
if (bus == NULL) {
kfree(res);
kfree(controller);
return;
}
pci_bus_add_devices(bus);
}
void
sn_bus_fixup(struct pci_bus *bus)
{
struct pci_dev *pci_dev = NULL;
struct pcibus_bussoft *prom_bussoft_ptr;
if (!bus->parent) {
prom_bussoft_ptr = PCI_CONTROLLER(bus)->platform_data;
if (prom_bussoft_ptr == NULL) {
printk(KERN_ERR
"sn_bus_fixup: 0x%04x:0x%02x Unable to "
"obtain prom_bussoft_ptr\n",
pci_domain_nr(bus), bus->number);
return;
}
sn_common_bus_fixup(bus, prom_bussoft_ptr);
}
list_for_each_entry(pci_dev, &bus->devices, bus_list) {
sn_io_slot_fixup(pci_dev);
}
}
void __init sn_io_init(void)
{
int i, j;
sn_fixup_ionodes();
for (i = 0; i <= max_segment_number; i++)
for (j = 0; j <= max_pcibus_number; j++)
sn_pci_controller_fixup(i, j, NULL);
}
