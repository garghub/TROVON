static void __devinit cnb20le_res(struct pci_dev *dev)
{
struct pci_root_info *info;
struct resource res;
u16 word1, word2;
u8 fbus, lbus;
int i;
#ifdef CONFIG_ACPI
if (acpi_os_get_root_pointer())
return;
#endif
info = &pci_root_info[pci_root_num];
pci_root_num++;
pci_read_config_byte(dev, 0x44, &fbus);
pci_read_config_byte(dev, 0x45, &lbus);
info->bus_min = fbus;
info->bus_max = lbus;
if (fbus == 0) {
update_res(info, 0x01f0, 0x01f7, IORESOURCE_IO, 0);
update_res(info, 0x03f6, 0x03f6, IORESOURCE_IO, 0);
update_res(info, 0x0170, 0x0177, IORESOURCE_IO, 0);
update_res(info, 0x0376, 0x0376, IORESOURCE_IO, 0);
update_res(info, 0xffa0, 0xffaf, IORESOURCE_IO, 0);
}
pci_read_config_word(dev, 0xc0, &word1);
pci_read_config_word(dev, 0xc2, &word2);
if (word1 != word2) {
res.start = (word1 << 16) | 0x0000;
res.end = (word2 << 16) | 0xffff;
res.flags = IORESOURCE_MEM;
update_res(info, res.start, res.end, res.flags, 0);
}
pci_read_config_word(dev, 0xc4, &word1);
pci_read_config_word(dev, 0xc6, &word2);
if (word1 != word2) {
res.start = (word1 << 16) | 0x0000;
res.end = (word2 << 16) | 0xffff;
res.flags = IORESOURCE_MEM | IORESOURCE_PREFETCH;
update_res(info, res.start, res.end, res.flags, 0);
}
pci_read_config_word(dev, 0xd0, &word1);
pci_read_config_word(dev, 0xd2, &word2);
if (word1 != word2) {
res.start = word1;
res.end = word2;
res.flags = IORESOURCE_IO;
update_res(info, res.start, res.end, res.flags, 0);
}
res.start = fbus;
res.end = lbus;
res.flags = IORESOURCE_BUS;
dev_info(&dev->dev, "CNB20LE PCI Host Bridge (domain %04x %pR)\n",
pci_domain_nr(dev->bus), &res);
for (i = 0; i < info->res_num; i++)
dev_info(&dev->dev, "host bridge window %pR\n", &info->res[i]);
}
