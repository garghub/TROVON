static int ltq_pci_config_access(unsigned char access_type, struct pci_bus *bus,
unsigned int devfn, unsigned int where, u32 *data)
{
unsigned long cfg_base;
unsigned long flags;
u32 temp;
if ((bus->number != 0) || ((devfn & 0xf8) > 0x78)
|| ((devfn & 0xf8) == 0) || ((devfn & 0xf8) == 0x68))
return 1;
spin_lock_irqsave(&ebu_lock, flags);
cfg_base = (unsigned long) ltq_pci_mapped_cfg;
cfg_base |= (bus->number << LTQ_PCI_CFG_BUSNUM_SHF) | (devfn <<
LTQ_PCI_CFG_FUNNUM_SHF) | (where & ~0x3);
if (access_type == PCI_ACCESS_WRITE) {
ltq_w32(swab32(*data), ((u32 *)cfg_base));
} else {
*data = ltq_r32(((u32 *)(cfg_base)));
*data = swab32(*data);
}
wmb();
cfg_base = (unsigned long) ltq_pci_mapped_cfg;
cfg_base |= (0x0 << LTQ_PCI_CFG_FUNNUM_SHF) + 4;
temp = ltq_r32(((u32 *)(cfg_base)));
temp = swab32(temp);
cfg_base = (unsigned long) ltq_pci_mapped_cfg;
cfg_base |= (0x68 << LTQ_PCI_CFG_FUNNUM_SHF) + 4;
ltq_w32(temp, ((u32 *)cfg_base));
spin_unlock_irqrestore(&ebu_lock, flags);
if (((*data) == 0xffffffff) && (access_type == PCI_ACCESS_READ))
return 1;
return 0;
}
int ltq_pci_read_config_dword(struct pci_bus *bus, unsigned int devfn,
int where, int size, u32 *val)
{
u32 data = 0;
if (ltq_pci_config_access(PCI_ACCESS_READ, bus, devfn, where, &data))
return PCIBIOS_DEVICE_NOT_FOUND;
if (size == 1)
*val = (data >> ((where & 3) << 3)) & 0xff;
else if (size == 2)
*val = (data >> ((where & 3) << 3)) & 0xffff;
else
*val = data;
return PCIBIOS_SUCCESSFUL;
}
int ltq_pci_write_config_dword(struct pci_bus *bus, unsigned int devfn,
int where, int size, u32 val)
{
u32 data = 0;
if (size == 4) {
data = val;
} else {
if (ltq_pci_config_access(PCI_ACCESS_READ, bus,
devfn, where, &data))
return PCIBIOS_DEVICE_NOT_FOUND;
if (size == 1)
data = (data & ~(0xff << ((where & 3) << 3))) |
(val << ((where & 3) << 3));
else if (size == 2)
data = (data & ~(0xffff << ((where & 3) << 3))) |
(val << ((where & 3) << 3));
}
if (ltq_pci_config_access(PCI_ACCESS_WRITE, bus, devfn, where, &data))
return PCIBIOS_DEVICE_NOT_FOUND;
return PCIBIOS_SUCCESSFUL;
}
