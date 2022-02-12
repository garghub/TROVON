static inline PCI_IO_ADDR celleb_epci_get_epci_base(
struct pci_controller *hose)
{
return hose->cfg_addr;
}
static inline PCI_IO_ADDR celleb_epci_get_epci_cfg(
struct pci_controller *hose)
{
return hose->cfg_data;
}
static inline void clear_and_disable_master_abort_interrupt(
struct pci_controller *hose)
{
PCI_IO_ADDR epci_base;
PCI_IO_ADDR reg;
epci_base = celleb_epci_get_epci_base(hose);
reg = epci_base + PCI_COMMAND;
out_be32(reg, in_be32(reg) | (PCI_STATUS_REC_MASTER_ABORT << 16));
}
static int celleb_epci_check_abort(struct pci_controller *hose,
PCI_IO_ADDR addr)
{
PCI_IO_ADDR reg;
PCI_IO_ADDR epci_base;
u32 val;
iob();
epci_base = celleb_epci_get_epci_base(hose);
reg = epci_base + PCI_COMMAND;
val = in_be32(reg);
if (val & (PCI_STATUS_REC_MASTER_ABORT << 16)) {
out_be32(reg,
(val & 0xffff) | (PCI_STATUS_REC_MASTER_ABORT << 16));
reg = epci_base + SCC_EPCI_STATUS;
out_be32(reg, SCC_EPCI_INT_PAI);
reg = epci_base + SCC_EPCI_VCSR;
val = in_be32(reg) & 0xffff;
val |= SCC_EPCI_VCSR_FRE;
out_be32(reg, val);
reg = epci_base + SCC_EPCI_VISTAT;
out_be32(reg, SCC_EPCI_VISTAT_PMFE);
return PCIBIOS_DEVICE_NOT_FOUND;
}
return PCIBIOS_SUCCESSFUL;
}
static PCI_IO_ADDR celleb_epci_make_config_addr(struct pci_bus *bus,
struct pci_controller *hose, unsigned int devfn, int where)
{
PCI_IO_ADDR addr;
if (bus != hose->bus)
addr = celleb_epci_get_epci_cfg(hose) +
(((bus->number & 0xff) << 16)
| ((devfn & 0xff) << 8)
| (where & 0xff)
| 0x01000000);
else
addr = celleb_epci_get_epci_cfg(hose) +
(((devfn & 0xff) << 8) | (where & 0xff));
pr_debug("EPCI: config_addr = 0x%p\n", addr);
return addr;
}
static int celleb_epci_read_config(struct pci_bus *bus,
unsigned int devfn, int where, int size, u32 *val)
{
PCI_IO_ADDR epci_base;
PCI_IO_ADDR addr;
struct pci_controller *hose = pci_bus_to_host(bus);
BUG_ON(where % size);
if (!celleb_epci_get_epci_cfg(hose))
return PCIBIOS_DEVICE_NOT_FOUND;
if (bus->number == hose->first_busno && devfn == 0) {
epci_base = celleb_epci_get_epci_base(hose);
addr = epci_base + where;
switch (size) {
case 1:
*val = in_8(addr);
break;
case 2:
*val = in_be16(addr);
break;
case 4:
*val = in_be32(addr);
break;
default:
return PCIBIOS_DEVICE_NOT_FOUND;
}
} else {
clear_and_disable_master_abort_interrupt(hose);
addr = celleb_epci_make_config_addr(bus, hose, devfn, where);
switch (size) {
case 1:
*val = in_8(addr);
break;
case 2:
*val = in_le16(addr);
break;
case 4:
*val = in_le32(addr);
break;
default:
return PCIBIOS_DEVICE_NOT_FOUND;
}
}
pr_debug("EPCI: "
"addr=0x%p, devfn=0x%x, where=0x%x, size=0x%x, val=0x%x\n",
addr, devfn, where, size, *val);
return celleb_epci_check_abort(hose, NULL);
}
static int celleb_epci_write_config(struct pci_bus *bus,
unsigned int devfn, int where, int size, u32 val)
{
PCI_IO_ADDR epci_base;
PCI_IO_ADDR addr;
struct pci_controller *hose = pci_bus_to_host(bus);
BUG_ON(where % size);
if (!celleb_epci_get_epci_cfg(hose))
return PCIBIOS_DEVICE_NOT_FOUND;
if (bus->number == hose->first_busno && devfn == 0) {
epci_base = celleb_epci_get_epci_base(hose);
addr = epci_base + where;
switch (size) {
case 1:
out_8(addr, val);
break;
case 2:
out_be16(addr, val);
break;
case 4:
out_be32(addr, val);
break;
default:
return PCIBIOS_DEVICE_NOT_FOUND;
}
} else {
clear_and_disable_master_abort_interrupt(hose);
addr = celleb_epci_make_config_addr(bus, hose, devfn, where);
switch (size) {
case 1:
out_8(addr, val);
break;
case 2:
out_le16(addr, val);
break;
case 4:
out_le32(addr, val);
break;
default:
return PCIBIOS_DEVICE_NOT_FOUND;
}
}
return celleb_epci_check_abort(hose, addr);
}
static int __init celleb_epci_init(struct pci_controller *hose)
{
u32 val;
PCI_IO_ADDR reg;
PCI_IO_ADDR epci_base;
int hwres = 0;
epci_base = celleb_epci_get_epci_base(hose);
reg = epci_base + SCC_EPCI_CKCTRL;
val = in_be32(reg);
if (val == 0x00030101)
hwres = 1;
else {
val &= ~(SCC_EPCI_CKCTRL_CRST0 | SCC_EPCI_CKCTRL_CRST1);
out_be32(reg, val);
val = in_be32(reg);
val |= (SCC_EPCI_CKCTRL_OCLKEN | SCC_EPCI_CKCTRL_LCLKEN);
out_be32(reg, val);
val = in_be32(reg);
val |= SCC_EPCI_CKCTRL_CRST0;
out_be32(reg, val);
reg = epci_base + SCC_EPCI_CLKRST;
val = in_be32(reg);
val &= ~SCC_EPCI_CLKRST_CKS_MASK;
val |= SCC_EPCI_CLKRST_CKS_2;
out_be32(reg, val);
reg = epci_base + SCC_EPCI_ABTSET;
out_be32(reg, 0x0f1f001f);
reg = epci_base + SCC_EPCI_CLKRST;
val = in_be32(reg);
val |= SCC_EPCI_CLKRST_BC;
out_be32(reg, val);
val = in_be32(reg);
val |= SCC_EPCI_CLKRST_PCKEN;
out_be32(reg, val);
reg = epci_base + SCC_EPCI_CKCTRL;
val = in_be32(reg);
val |= (SCC_EPCI_CKCTRL_CRST0 | SCC_EPCI_CKCTRL_CRST1);
out_be32(reg, val);
}
reg = epci_base + SCC_EPCI_INTSET;
out_be32(reg, 0x013f011f);
reg = epci_base + SCC_EPCI_VIENAB;
val = SCC_EPCI_VIENAB_PMPEE | SCC_EPCI_VIENAB_PMFEE;
out_be32(reg, val);
reg = epci_base + SCC_EPCI_STATUS;
out_be32(reg, 0xffffffff);
reg = epci_base + SCC_EPCI_VISTAT;
out_be32(reg, 0xffffffff);
reg = epci_base + SCC_EPCI_VCSR;
val = in_be32(reg);
val &= ~(SCC_EPCI_VCSR_DR | SCC_EPCI_VCSR_AT);
out_be32(reg, val);
reg = epci_base + PCI_COMMAND;
val = PCI_COMMAND_MEMORY | PCI_COMMAND_MASTER;
out_be32(reg, val);
reg = epci_base + SCC_EPCI_ECMODE;
val = 0x00550155;
out_be32(reg, val);
reg = epci_base + SCC_EPCI_CNTOPT;
val = in_be32(reg);
val |= SCC_EPCI_CNTOPT_O2PMB;
out_be32(reg, val);
reg = epci_base + SCC_EPCI_CNF10_REG;
out_be32(reg, 0x80000008);
reg = epci_base + SCC_EPCI_CNF14_REG;
out_be32(reg, 0x40000008);
reg = epci_base + SCC_EPCI_BAM0;
out_be32(reg, 0x80000000);
reg = epci_base + SCC_EPCI_BAM1;
out_be32(reg, 0xe0000000);
reg = epci_base + SCC_EPCI_PVBAT;
out_be32(reg, 0x80000000);
if (!hwres) {
reg = epci_base + SCC_EPCI_CLKRST;
val = in_be32(reg);
val |= SCC_EPCI_CLKRST_PCIRST;
out_be32(reg, val);
}
return 0;
}
static int __init celleb_setup_epci(struct device_node *node,
struct pci_controller *hose)
{
struct resource r;
pr_debug("PCI: celleb_setup_epci()\n");
if (of_address_to_resource(node, 0, &r))
goto error;
hose->cfg_addr = ioremap(r.start, (r.end - r.start + 1));
if (!hose->cfg_addr)
goto error;
pr_debug("EPCI: cfg_addr map 0x%016llx->0x%016lx + 0x%016llx\n",
r.start, (unsigned long)hose->cfg_addr, (r.end - r.start + 1));
if (of_address_to_resource(node, 2, &r))
goto error;
hose->cfg_data = ioremap(r.start, (r.end - r.start + 1));
if (!hose->cfg_data)
goto error;
pr_debug("EPCI: cfg_data map 0x%016llx->0x%016lx + 0x%016llx\n",
r.start, (unsigned long)hose->cfg_data, (r.end - r.start + 1));
hose->ops = &celleb_epci_ops;
celleb_epci_init(hose);
return 0;
error:
if (hose->cfg_addr)
iounmap(hose->cfg_addr);
if (hose->cfg_data)
iounmap(hose->cfg_data);
return 1;
}
