static void __init cnb20le_res(u8 bus, u8 slot, u8 func)
{
struct pci_root_info *info;
struct pci_root_res *root_res;
struct resource res;
u16 word1, word2;
u8 fbus, lbus;
fbus = read_pci_config_byte(bus, slot, func, 0x44);
lbus = read_pci_config_byte(bus, slot, func, 0x45);
info = alloc_pci_root_info(fbus, lbus, 0, 0);
if (fbus == 0) {
update_res(info, 0x01f0, 0x01f7, IORESOURCE_IO, 0);
update_res(info, 0x03f6, 0x03f6, IORESOURCE_IO, 0);
update_res(info, 0x0170, 0x0177, IORESOURCE_IO, 0);
update_res(info, 0x0376, 0x0376, IORESOURCE_IO, 0);
update_res(info, 0xffa0, 0xffaf, IORESOURCE_IO, 0);
}
word1 = read_pci_config_16(bus, slot, func, 0xc0);
word2 = read_pci_config_16(bus, slot, func, 0xc2);
if (word1 != word2) {
res.start = (word1 << 16) | 0x0000;
res.end = (word2 << 16) | 0xffff;
res.flags = IORESOURCE_MEM;
update_res(info, res.start, res.end, res.flags, 0);
}
word1 = read_pci_config_16(bus, slot, func, 0xc4);
word2 = read_pci_config_16(bus, slot, func, 0xc6);
if (word1 != word2) {
res.start = (word1 << 16) | 0x0000;
res.end = (word2 << 16) | 0xffff;
res.flags = IORESOURCE_MEM | IORESOURCE_PREFETCH;
update_res(info, res.start, res.end, res.flags, 0);
}
word1 = read_pci_config_16(bus, slot, func, 0xd0);
word2 = read_pci_config_16(bus, slot, func, 0xd2);
if (word1 != word2) {
res.start = word1;
res.end = word2;
res.flags = IORESOURCE_IO;
update_res(info, res.start, res.end, res.flags, 0);
}
res.start = fbus;
res.end = lbus;
res.flags = IORESOURCE_BUS;
printk(KERN_INFO "CNB20LE PCI Host Bridge (domain 0000 %pR)\n", &res);
list_for_each_entry(root_res, &info->resources, list)
printk(KERN_INFO "host bridge window %pR\n", &root_res->res);
}
static int __init broadcom_postcore_init(void)
{
u8 bus = 0, slot = 0;
u32 id;
u16 vendor, device;
#ifdef CONFIG_ACPI
if (acpi_os_get_root_pointer())
return 0;
#endif
id = read_pci_config(bus, slot, 0, PCI_VENDOR_ID);
vendor = id & 0xffff;
device = (id >> 16) & 0xffff;
if (vendor == PCI_VENDOR_ID_SERVERWORKS &&
device == PCI_DEVICE_ID_SERVERWORKS_LE) {
cnb20le_res(bus, slot, 0);
cnb20le_res(bus, slot, 1);
}
return 0;
}
