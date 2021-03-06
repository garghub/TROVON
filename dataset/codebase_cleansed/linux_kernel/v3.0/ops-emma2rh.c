static int check_args(struct pci_bus *bus, u32 devfn, u32 * bus_num)
{
if (bus->parent != NULL) {
*bus_num = bus->number;
db_assert(bus_num != NULL);
} else
*bus_num = 0;
if (*bus_num == 0) {
if (PCI_SLOT(devfn) >= 10)
return PCIBIOS_DEVICE_NOT_FOUND;
} else {
if ((*bus_num >= 64) || (PCI_SLOT(devfn) >= 16))
return PCIBIOS_DEVICE_NOT_FOUND;
}
return 0;
}
static inline int set_pci_configuration_address(unsigned char bus_num,
unsigned int devfn, int where)
{
u32 config_win0;
emma2rh_out32(EMMA2RH_PCI_INT, ~RMABORT);
if (bus_num == 0)
config_win0 = (1 << (22 + PCI_SLOT(devfn))) | (5 << 9);
else
config_win0 = (bus_num << 26) | (PCI_SLOT(devfn) << 22) |
(1 << 15) | (5 << 9);
emma2rh_out32(EMMA2RH_PCI_IWIN0_CTR, config_win0);
return 0;
}
static int pci_config_read(struct pci_bus *bus, unsigned int devfn, int where,
int size, uint32_t * val)
{
u32 bus_num;
u32 base = KSEG1ADDR(EMMA2RH_PCI_CONFIG_BASE);
u32 backup_win0;
u32 data;
*val = 0xffffffffU;
if (check_args(bus, devfn, &bus_num) == PCIBIOS_DEVICE_NOT_FOUND)
return PCIBIOS_DEVICE_NOT_FOUND;
backup_win0 = emma2rh_in32(EMMA2RH_PCI_IWIN0_CTR);
if (set_pci_configuration_address(bus_num, devfn, where) < 0)
return PCIBIOS_DEVICE_NOT_FOUND;
data =
*(volatile u32 *)(base + (PCI_FUNC(devfn) << 8) +
(where & 0xfffffffc));
switch (size) {
case 1:
*val = (data >> ((where & 3) << 3)) & 0xffU;
break;
case 2:
*val = (data >> ((where & 2) << 3)) & 0xffffU;
break;
case 4:
*val = data;
break;
default:
emma2rh_out32(EMMA2RH_PCI_IWIN0_CTR, backup_win0);
return PCIBIOS_FUNC_NOT_SUPPORTED;
}
emma2rh_out32(EMMA2RH_PCI_IWIN0_CTR, backup_win0);
if (emma2rh_in32(EMMA2RH_PCI_INT) & RMABORT)
return PCIBIOS_DEVICE_NOT_FOUND;
return PCIBIOS_SUCCESSFUL;
}
static int pci_config_write(struct pci_bus *bus, unsigned int devfn, int where,
int size, u32 val)
{
u32 bus_num;
u32 base = KSEG1ADDR(EMMA2RH_PCI_CONFIG_BASE);
u32 backup_win0;
u32 data;
int shift;
if (check_args(bus, devfn, &bus_num) == PCIBIOS_DEVICE_NOT_FOUND)
return PCIBIOS_DEVICE_NOT_FOUND;
backup_win0 = emma2rh_in32(EMMA2RH_PCI_IWIN0_CTR);
if (set_pci_configuration_address(bus_num, devfn, where) < 0)
return PCIBIOS_DEVICE_NOT_FOUND;
data =
*(volatile u32 *)(base + (PCI_FUNC(devfn) << 8) +
(where & 0xfffffffc));
switch (size) {
case 1:
shift = (where & 3) << 3;
data &= ~(0xffU << shift);
data |= ((val & 0xffU) << shift);
break;
case 2:
shift = (where & 2) << 3;
data &= ~(0xffffU << shift);
data |= ((val & 0xffffU) << shift);
break;
case 4:
data = val;
break;
default:
emma2rh_out32(EMMA2RH_PCI_IWIN0_CTR, backup_win0);
return PCIBIOS_FUNC_NOT_SUPPORTED;
}
*(volatile u32 *)(base + (PCI_FUNC(devfn) << 8) +
(where & 0xfffffffc)) = data;
emma2rh_out32(EMMA2RH_PCI_IWIN0_CTR, backup_win0);
if (emma2rh_in32(EMMA2RH_PCI_INT) & RMABORT)
return PCIBIOS_DEVICE_NOT_FOUND;
return PCIBIOS_SUCCESSFUL;
}
