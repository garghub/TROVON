static void quirk_fsl_pcie_header(struct pci_dev *dev)
{
u8 hdr_type;
if (!pci_find_capability(dev, PCI_CAP_ID_EXP))
return;
pci_read_config_byte(dev, PCI_HEADER_TYPE, &hdr_type);
if ((hdr_type & 0x7f) != PCI_HEADER_TYPE_BRIDGE)
return;
dev->class = PCI_CLASS_BRIDGE_PCI << 8;
fsl_pcie_bus_fixup = 1;
return;
}
static int fsl_pcie_check_link(struct pci_controller *hose)
{
u32 val = 0;
if (hose->indirect_type & PPC_INDIRECT_TYPE_FSL_CFG_REG_LINK) {
if (hose->ops->read == fsl_indirect_read_config) {
struct pci_bus bus;
bus.number = hose->first_busno;
bus.sysdata = hose;
bus.ops = hose->ops;
indirect_read_config(&bus, 0, PCIE_LTSSM, 4, &val);
} else
early_read_config_dword(hose, 0, 0, PCIE_LTSSM, &val);
if (val < PCIE_LTSSM_L0)
return 1;
} else {
struct ccsr_pci __iomem *pci = hose->private_data;
val = (in_be32(&pci->pex_csr0) & PEX_CSR0_LTSSM_MASK)
>> PEX_CSR0_LTSSM_SHIFT;
if (val != PEX_CSR0_LTSSM_L0)
return 1;
}
return 0;
}
static int fsl_indirect_read_config(struct pci_bus *bus, unsigned int devfn,
int offset, int len, u32 *val)
{
struct pci_controller *hose = pci_bus_to_host(bus);
if (fsl_pcie_check_link(hose))
hose->indirect_type |= PPC_INDIRECT_TYPE_NO_PCIE_LINK;
else
hose->indirect_type &= ~PPC_INDIRECT_TYPE_NO_PCIE_LINK;
return indirect_read_config(bus, devfn, offset, len, val);
}
static int fsl_pci_dma_set_mask(struct device *dev, u64 dma_mask)
{
if (!dev->dma_mask || !dma_supported(dev, dma_mask))
return -EIO;
if ((dev->bus == &pci_bus_type) &&
dma_mask >= DMA_BIT_MASK(MAX_PHYS_ADDR_BITS)) {
set_dma_ops(dev, &dma_direct_ops);
set_dma_offset(dev, pci64_dma_offset);
}
*dev->dma_mask = dma_mask;
return 0;
}
static int setup_one_atmu(struct ccsr_pci __iomem *pci,
unsigned int index, const struct resource *res,
resource_size_t offset)
{
resource_size_t pci_addr = res->start - offset;
resource_size_t phys_addr = res->start;
resource_size_t size = resource_size(res);
u32 flags = 0x80044000;
unsigned int i;
pr_debug("PCI MEM resource start 0x%016llx, size 0x%016llx.\n",
(u64)res->start, (u64)size);
if (res->flags & IORESOURCE_PREFETCH)
flags |= 0x10000000;
for (i = 0; size > 0; i++) {
unsigned int bits = min(ilog2(size),
__ffs(pci_addr | phys_addr));
if (index + i >= 5)
return -1;
out_be32(&pci->pow[index + i].potar, pci_addr >> 12);
out_be32(&pci->pow[index + i].potear, (u64)pci_addr >> 44);
out_be32(&pci->pow[index + i].powbar, phys_addr >> 12);
out_be32(&pci->pow[index + i].powar, flags | (bits - 1));
pci_addr += (resource_size_t)1U << bits;
phys_addr += (resource_size_t)1U << bits;
size -= (resource_size_t)1U << bits;
}
return i;
}
static void setup_pci_atmu(struct pci_controller *hose)
{
struct ccsr_pci __iomem *pci = hose->private_data;
int i, j, n, mem_log, win_idx = 3, start_idx = 1, end_idx = 4;
u64 mem, sz, paddr_hi = 0;
u64 offset = 0, paddr_lo = ULLONG_MAX;
u32 pcicsrbar = 0, pcicsrbar_sz;
u32 piwar = PIWAR_EN | PIWAR_PF | PIWAR_TGI_LOCAL |
PIWAR_READ_SNOOP | PIWAR_WRITE_SNOOP;
const char *name = hose->dn->full_name;
const u64 *reg;
int len;
if (early_find_capability(hose, 0, 0, PCI_CAP_ID_EXP)) {
if (in_be32(&pci->block_rev1) >= PCIE_IP_REV_2_2) {
win_idx = 2;
start_idx = 0;
end_idx = 3;
}
}
for(i = 1; i < 5; i++)
out_be32(&pci->pow[i].powar, 0);
for (i = start_idx; i < end_idx; i++)
out_be32(&pci->piw[i].piwar, 0);
for(i = 0, j = 1; i < 3; i++) {
if (!(hose->mem_resources[i].flags & IORESOURCE_MEM))
continue;
paddr_lo = min(paddr_lo, (u64)hose->mem_resources[i].start);
paddr_hi = max(paddr_hi, (u64)hose->mem_resources[i].end);
offset = hose->mem_offset[i];
n = setup_one_atmu(pci, j, &hose->mem_resources[i], offset);
if (n < 0 || j >= 5) {
pr_err("Ran out of outbound PCI ATMUs for resource %d!\n", i);
hose->mem_resources[i].flags |= IORESOURCE_DISABLED;
} else
j += n;
}
if (hose->io_resource.flags & IORESOURCE_IO) {
if (j >= 5) {
pr_err("Ran out of outbound PCI ATMUs for IO resource\n");
} else {
pr_debug("PCI IO resource start 0x%016llx, size 0x%016llx, "
"phy base 0x%016llx.\n",
(u64)hose->io_resource.start,
(u64)resource_size(&hose->io_resource),
(u64)hose->io_base_phys);
out_be32(&pci->pow[j].potar, (hose->io_resource.start >> 12));
out_be32(&pci->pow[j].potear, 0);
out_be32(&pci->pow[j].powbar, (hose->io_base_phys >> 12));
out_be32(&pci->pow[j].powar, 0x80088000
| (ilog2(hose->io_resource.end
- hose->io_resource.start + 1) - 1));
}
}
paddr_hi -= offset;
paddr_lo -= offset;
if (paddr_hi == paddr_lo) {
pr_err("%s: No outbound window space\n", name);
return;
}
if (paddr_lo == 0) {
pr_err("%s: No space for inbound window\n", name);
return;
}
early_write_config_dword(hose, 0, 0, PCI_BASE_ADDRESS_0, 0xffffffff);
early_read_config_dword(hose, 0, 0, PCI_BASE_ADDRESS_0, &pcicsrbar_sz);
pcicsrbar_sz = ~pcicsrbar_sz + 1;
if (paddr_hi < (0x100000000ull - pcicsrbar_sz) ||
(paddr_lo > 0x100000000ull))
pcicsrbar = 0x100000000ull - pcicsrbar_sz;
else
pcicsrbar = (paddr_lo - pcicsrbar_sz) & -pcicsrbar_sz;
early_write_config_dword(hose, 0, 0, PCI_BASE_ADDRESS_0, pcicsrbar);
paddr_lo = min(paddr_lo, (u64)pcicsrbar);
pr_info("%s: PCICSRBAR @ 0x%x\n", name, pcicsrbar);
mem = memblock_end_of_DRAM();
reg = of_get_property(hose->dn, "msi-address-64", &len);
if (reg && (len == sizeof(u64))) {
u64 address = be64_to_cpup(reg);
if ((address >= mem) && (address < (mem + PAGE_SIZE))) {
pr_info("%s: extending DDR ATMU to cover MSIIR", name);
mem += PAGE_SIZE;
} else {
pr_warn("%s: msi-address-64 address of %llx is "
"unsupported\n", name, address);
}
}
sz = min(mem, paddr_lo);
mem_log = ilog2(sz);
if (early_find_capability(hose, 0, 0, PCI_CAP_ID_EXP)) {
if ((1ull << mem_log) != mem) {
mem_log++;
if ((1ull << mem_log) > mem)
pr_info("%s: Setting PCI inbound window "
"greater than memory size\n", name);
}
piwar |= ((mem_log - 1) & PIWAR_SZ_MASK);
out_be32(&pci->piw[win_idx].pitar, 0x00000000);
out_be32(&pci->piw[win_idx].piwbar, 0x00000000);
out_be32(&pci->piw[win_idx].piwar, piwar);
win_idx--;
hose->dma_window_base_cur = 0x00000000;
hose->dma_window_size = (resource_size_t)sz;
if (sz != mem) {
mem_log = ilog2(mem);
if ((1ull << mem_log) != mem)
mem_log++;
piwar = (piwar & ~PIWAR_SZ_MASK) | (mem_log - 1);
out_be32(&pci->piw[win_idx].pitar, 0x00000000);
out_be32(&pci->piw[win_idx].piwbear,
pci64_dma_offset >> 44);
out_be32(&pci->piw[win_idx].piwbar,
pci64_dma_offset >> 12);
out_be32(&pci->piw[win_idx].piwar, piwar);
ppc_md.dma_set_mask = fsl_pci_dma_set_mask;
pr_info("%s: Setup 64-bit PCI DMA window\n", name);
}
} else {
u64 paddr = 0;
out_be32(&pci->piw[win_idx].pitar, paddr >> 12);
out_be32(&pci->piw[win_idx].piwbar, paddr >> 12);
out_be32(&pci->piw[win_idx].piwar, (piwar | (mem_log - 1)));
win_idx--;
paddr += 1ull << mem_log;
sz -= 1ull << mem_log;
if (sz) {
mem_log = ilog2(sz);
piwar |= (mem_log - 1);
out_be32(&pci->piw[win_idx].pitar, paddr >> 12);
out_be32(&pci->piw[win_idx].piwbar, paddr >> 12);
out_be32(&pci->piw[win_idx].piwar, piwar);
win_idx--;
paddr += 1ull << mem_log;
}
hose->dma_window_base_cur = 0x00000000;
hose->dma_window_size = (resource_size_t)paddr;
}
if (hose->dma_window_size < mem) {
#ifdef CONFIG_SWIOTLB
ppc_swiotlb_enable = 1;
#else
pr_err("%s: ERROR: Memory size exceeds PCI ATMU ability to "
"map - enable CONFIG_SWIOTLB to avoid dma errors.\n",
name);
#endif
if (paddr_hi < 0xffffffffull)
pr_warning("%s: WARNING: Outbound window cfg leaves "
"gaps in memory map. Adjusting the memory map "
"could reduce unnecessary bounce buffering.\n",
name);
pr_info("%s: DMA window size is 0x%llx\n", name,
(u64)hose->dma_window_size);
}
}
static void __init setup_pci_cmd(struct pci_controller *hose)
{
u16 cmd;
int cap_x;
early_read_config_word(hose, 0, 0, PCI_COMMAND, &cmd);
cmd |= PCI_COMMAND_SERR | PCI_COMMAND_MASTER | PCI_COMMAND_MEMORY
| PCI_COMMAND_IO;
early_write_config_word(hose, 0, 0, PCI_COMMAND, cmd);
cap_x = early_find_capability(hose, 0, 0, PCI_CAP_ID_PCIX);
if (cap_x) {
int pci_x_cmd = cap_x + PCI_X_CMD;
cmd = PCI_X_CMD_MAX_SPLIT | PCI_X_CMD_MAX_READ
| PCI_X_CMD_ERO | PCI_X_CMD_DPERR_E;
early_write_config_word(hose, 0, 0, pci_x_cmd, cmd);
} else {
early_write_config_byte(hose, 0, 0, PCI_LATENCY_TIMER, 0x80);
}
}
void fsl_pcibios_fixup_bus(struct pci_bus *bus)
{
struct pci_controller *hose = pci_bus_to_host(bus);
int i, is_pcie = 0, no_link;
if (fsl_pcie_bus_fixup)
is_pcie = early_find_capability(hose, 0, 0, PCI_CAP_ID_EXP);
no_link = !!(hose->indirect_type & PPC_INDIRECT_TYPE_NO_PCIE_LINK);
if (bus->parent == hose->bus && (is_pcie || no_link)) {
for (i = 0; i < PCI_BRIDGE_RESOURCE_NUM; ++i) {
struct resource *res = bus->resource[i];
struct resource *par;
if (!res)
continue;
if (i == 0)
par = &hose->io_resource;
else if (i < 4)
par = &hose->mem_resources[i-1];
else par = NULL;
res->start = par ? par->start : 0;
res->end = par ? par->end : 0;
res->flags = par ? par->flags : 0;
}
}
}
int __init fsl_add_bridge(struct platform_device *pdev, int is_primary)
{
int len;
struct pci_controller *hose;
struct resource rsrc;
const int *bus_range;
u8 hdr_type, progif;
struct device_node *dev;
struct ccsr_pci __iomem *pci;
dev = pdev->dev.of_node;
if (!of_device_is_available(dev)) {
pr_warning("%s: disabled\n", dev->full_name);
return -ENODEV;
}
pr_debug("Adding PCI host bridge %s\n", dev->full_name);
if (of_address_to_resource(dev, 0, &rsrc)) {
printk(KERN_WARNING "Can't get pci register base!");
return -ENOMEM;
}
bus_range = of_get_property(dev, "bus-range", &len);
if (bus_range == NULL || len < 2 * sizeof(int))
printk(KERN_WARNING "Can't get bus-range for %s, assume"
" bus 0\n", dev->full_name);
pci_add_flags(PCI_REASSIGN_ALL_BUS);
hose = pcibios_alloc_controller(dev);
if (!hose)
return -ENOMEM;
hose->parent = &pdev->dev;
hose->first_busno = bus_range ? bus_range[0] : 0x0;
hose->last_busno = bus_range ? bus_range[1] : 0xff;
pr_debug("PCI memory map start 0x%016llx, size 0x%016llx\n",
(u64)rsrc.start, (u64)resource_size(&rsrc));
pci = hose->private_data = ioremap(rsrc.start, resource_size(&rsrc));
if (!hose->private_data)
goto no_bridge;
setup_indirect_pci(hose, rsrc.start, rsrc.start + 0x4,
PPC_INDIRECT_TYPE_BIG_ENDIAN);
if (in_be32(&pci->block_rev1) < PCIE_IP_REV_3_0)
hose->indirect_type |= PPC_INDIRECT_TYPE_FSL_CFG_REG_LINK;
if (early_find_capability(hose, 0, 0, PCI_CAP_ID_EXP)) {
hose->ops = &fsl_indirect_pcie_ops;
early_read_config_byte(hose, 0, 0, PCI_HEADER_TYPE, &hdr_type);
if ((hdr_type & 0x7f) != PCI_HEADER_TYPE_BRIDGE)
goto no_bridge;
} else {
early_read_config_byte(hose, 0, 0, PCI_CLASS_PROG, &progif);
if ((progif & 1) == 1)
goto no_bridge;
}
setup_pci_cmd(hose);
if (early_find_capability(hose, 0, 0, PCI_CAP_ID_EXP)) {
hose->indirect_type |= PPC_INDIRECT_TYPE_EXT_REG |
PPC_INDIRECT_TYPE_SURPRESS_PRIMARY_BUS;
if (fsl_pcie_check_link(hose))
hose->indirect_type |= PPC_INDIRECT_TYPE_NO_PCIE_LINK;
}
printk(KERN_INFO "Found FSL PCI host bridge at 0x%016llx. "
"Firmware bus number: %d->%d\n",
(unsigned long long)rsrc.start, hose->first_busno,
hose->last_busno);
pr_debug(" ->Hose at 0x%p, cfg_addr=0x%p,cfg_data=0x%p\n",
hose, hose->cfg_addr, hose->cfg_data);
pci_process_bridge_OF_ranges(hose, dev, is_primary);
setup_pci_atmu(hose);
return 0;
no_bridge:
iounmap(hose->private_data);
if (((unsigned long)hose->cfg_data & PAGE_MASK) !=
((unsigned long)hose->cfg_addr & PAGE_MASK))
iounmap(hose->cfg_data);
iounmap(hose->cfg_addr);
pcibios_free_controller(hose);
return -ENODEV;
}
static int mpc83xx_pcie_exclude_device(struct pci_bus *bus, unsigned int devfn)
{
struct pci_controller *hose = pci_bus_to_host(bus);
if (hose->indirect_type & PPC_INDIRECT_TYPE_NO_PCIE_LINK)
return PCIBIOS_DEVICE_NOT_FOUND;
if (bus->number == hose->first_busno ||
bus->primary == hose->first_busno) {
if (devfn & 0xf8)
return PCIBIOS_DEVICE_NOT_FOUND;
}
if (ppc_md.pci_exclude_device) {
if (ppc_md.pci_exclude_device(hose, bus->number, devfn))
return PCIBIOS_DEVICE_NOT_FOUND;
}
return PCIBIOS_SUCCESSFUL;
}
static void __iomem *mpc83xx_pcie_remap_cfg(struct pci_bus *bus,
unsigned int devfn, int offset)
{
struct pci_controller *hose = pci_bus_to_host(bus);
struct mpc83xx_pcie_priv *pcie = hose->dn->data;
u32 dev_base = bus->number << 24 | devfn << 16;
int ret;
ret = mpc83xx_pcie_exclude_device(bus, devfn);
if (ret)
return NULL;
offset &= 0xfff;
if (bus->number == hose->first_busno)
return pcie->cfg_type0 + offset;
if (pcie->dev_base == dev_base)
goto mapped;
out_le32(pcie->cfg_type0 + PEX_OUTWIN0_TAL, dev_base);
pcie->dev_base = dev_base;
mapped:
return pcie->cfg_type1 + offset;
}
static int mpc83xx_pcie_read_config(struct pci_bus *bus, unsigned int devfn,
int offset, int len, u32 *val)
{
void __iomem *cfg_addr;
cfg_addr = mpc83xx_pcie_remap_cfg(bus, devfn, offset);
if (!cfg_addr)
return PCIBIOS_DEVICE_NOT_FOUND;
switch (len) {
case 1:
*val = in_8(cfg_addr);
break;
case 2:
*val = in_le16(cfg_addr);
break;
default:
*val = in_le32(cfg_addr);
break;
}
return PCIBIOS_SUCCESSFUL;
}
static int mpc83xx_pcie_write_config(struct pci_bus *bus, unsigned int devfn,
int offset, int len, u32 val)
{
struct pci_controller *hose = pci_bus_to_host(bus);
void __iomem *cfg_addr;
cfg_addr = mpc83xx_pcie_remap_cfg(bus, devfn, offset);
if (!cfg_addr)
return PCIBIOS_DEVICE_NOT_FOUND;
if (offset == PCI_PRIMARY_BUS && bus->number == hose->first_busno)
val &= 0xffffff00;
switch (len) {
case 1:
out_8(cfg_addr, val);
break;
case 2:
out_le16(cfg_addr, val);
break;
default:
out_le32(cfg_addr, val);
break;
}
return PCIBIOS_SUCCESSFUL;
}
static int __init mpc83xx_pcie_setup(struct pci_controller *hose,
struct resource *reg)
{
struct mpc83xx_pcie_priv *pcie;
u32 cfg_bar;
int ret = -ENOMEM;
pcie = zalloc_maybe_bootmem(sizeof(*pcie), GFP_KERNEL);
if (!pcie)
return ret;
pcie->cfg_type0 = ioremap(reg->start, resource_size(reg));
if (!pcie->cfg_type0)
goto err0;
cfg_bar = in_le32(pcie->cfg_type0 + PEX_OUTWIN0_BAR);
if (!cfg_bar) {
ret = -ENODEV;
goto err1;
}
pcie->cfg_type1 = ioremap(cfg_bar, 0x1000);
if (!pcie->cfg_type1)
goto err1;
WARN_ON(hose->dn->data);
hose->dn->data = pcie;
hose->ops = &mpc83xx_pcie_ops;
hose->indirect_type |= PPC_INDIRECT_TYPE_FSL_CFG_REG_LINK;
out_le32(pcie->cfg_type0 + PEX_OUTWIN0_TAH, 0);
out_le32(pcie->cfg_type0 + PEX_OUTWIN0_TAL, 0);
if (fsl_pcie_check_link(hose))
hose->indirect_type |= PPC_INDIRECT_TYPE_NO_PCIE_LINK;
return 0;
err1:
iounmap(pcie->cfg_type0);
err0:
kfree(pcie);
return ret;
}
int __init mpc83xx_add_bridge(struct device_node *dev)
{
int ret;
int len;
struct pci_controller *hose;
struct resource rsrc_reg;
struct resource rsrc_cfg;
const int *bus_range;
int primary;
is_mpc83xx_pci = 1;
if (!of_device_is_available(dev)) {
pr_warning("%s: disabled by the firmware.\n",
dev->full_name);
return -ENODEV;
}
pr_debug("Adding PCI host bridge %s\n", dev->full_name);
if (of_address_to_resource(dev, 0, &rsrc_reg)) {
printk(KERN_WARNING "Can't get pci register base!\n");
return -ENOMEM;
}
memset(&rsrc_cfg, 0, sizeof(rsrc_cfg));
if (of_address_to_resource(dev, 1, &rsrc_cfg)) {
printk(KERN_WARNING
"No pci config register base in dev tree, "
"using default\n");
if ((rsrc_reg.start & 0xfffff) == 0x8500)
rsrc_cfg.start = (rsrc_reg.start & 0xfff00000) + 0x8300;
else if ((rsrc_reg.start & 0xfffff) == 0x8600)
rsrc_cfg.start = (rsrc_reg.start & 0xfff00000) + 0x8380;
}
if ((rsrc_reg.start & 0xfffff) == 0x8500)
primary = 1;
else
primary = 0;
bus_range = of_get_property(dev, "bus-range", &len);
if (bus_range == NULL || len < 2 * sizeof(int)) {
printk(KERN_WARNING "Can't get bus-range for %s, assume"
" bus 0\n", dev->full_name);
}
pci_add_flags(PCI_REASSIGN_ALL_BUS);
hose = pcibios_alloc_controller(dev);
if (!hose)
return -ENOMEM;
hose->first_busno = bus_range ? bus_range[0] : 0;
hose->last_busno = bus_range ? bus_range[1] : 0xff;
if (of_device_is_compatible(dev, "fsl,mpc8314-pcie")) {
ret = mpc83xx_pcie_setup(hose, &rsrc_reg);
if (ret)
goto err0;
} else {
setup_indirect_pci(hose, rsrc_cfg.start,
rsrc_cfg.start + 4, 0);
}
printk(KERN_INFO "Found FSL PCI host bridge at 0x%016llx. "
"Firmware bus number: %d->%d\n",
(unsigned long long)rsrc_reg.start, hose->first_busno,
hose->last_busno);
pr_debug(" ->Hose at 0x%p, cfg_addr=0x%p,cfg_data=0x%p\n",
hose, hose->cfg_addr, hose->cfg_data);
pci_process_bridge_OF_ranges(hose, dev, primary);
return 0;
err0:
pcibios_free_controller(hose);
return ret;
}
u64 fsl_pci_immrbar_base(struct pci_controller *hose)
{
#ifdef CONFIG_PPC_83xx
if (is_mpc83xx_pci) {
struct mpc83xx_pcie_priv *pcie = hose->dn->data;
struct pex_inbound_window *in;
int i;
in = pcie->cfg_type0 + PEX_RC_INWIN_BASE;
for (i = 0; i < 4; i++) {
if (!in_le32(&in[i].ar) & PEX_RCIWARn_EN)
continue;
if (get_immrbase() == in_le32(&in[i].tar))
return (u64)in_le32(&in[i].barh) << 32 |
in_le32(&in[i].barl);
}
printk(KERN_WARNING "could not find PCI BAR matching IMMR\n");
}
#endif
#if defined(CONFIG_FSL_SOC_BOOKE) || defined(CONFIG_PPC_86xx)
if (!is_mpc83xx_pci) {
u32 base;
pci_bus_read_config_dword(hose->bus,
PCI_DEVFN(0, 0), PCI_BASE_ADDRESS_0, &base);
return base;
}
#endif
return 0;
}
static int mcheck_handle_load(struct pt_regs *regs, u32 inst)
{
unsigned int rd, ra, rb, d;
rd = get_rt(inst);
ra = get_ra(inst);
rb = get_rb(inst);
d = get_d(inst);
switch (get_op(inst)) {
case 31:
switch (get_xop(inst)) {
case OP_31_XOP_LWZX:
case OP_31_XOP_LWBRX:
regs->gpr[rd] = 0xffffffff;
break;
case OP_31_XOP_LWZUX:
regs->gpr[rd] = 0xffffffff;
regs->gpr[ra] += regs->gpr[rb];
break;
case OP_31_XOP_LBZX:
regs->gpr[rd] = 0xff;
break;
case OP_31_XOP_LBZUX:
regs->gpr[rd] = 0xff;
regs->gpr[ra] += regs->gpr[rb];
break;
case OP_31_XOP_LHZX:
case OP_31_XOP_LHBRX:
regs->gpr[rd] = 0xffff;
break;
case OP_31_XOP_LHZUX:
regs->gpr[rd] = 0xffff;
regs->gpr[ra] += regs->gpr[rb];
break;
case OP_31_XOP_LHAX:
regs->gpr[rd] = ~0UL;
break;
case OP_31_XOP_LHAUX:
regs->gpr[rd] = ~0UL;
regs->gpr[ra] += regs->gpr[rb];
break;
default:
return 0;
}
break;
case OP_LWZ:
regs->gpr[rd] = 0xffffffff;
break;
case OP_LWZU:
regs->gpr[rd] = 0xffffffff;
regs->gpr[ra] += (s16)d;
break;
case OP_LBZ:
regs->gpr[rd] = 0xff;
break;
case OP_LBZU:
regs->gpr[rd] = 0xff;
regs->gpr[ra] += (s16)d;
break;
case OP_LHZ:
regs->gpr[rd] = 0xffff;
break;
case OP_LHZU:
regs->gpr[rd] = 0xffff;
regs->gpr[ra] += (s16)d;
break;
case OP_LHA:
regs->gpr[rd] = ~0UL;
break;
case OP_LHAU:
regs->gpr[rd] = ~0UL;
regs->gpr[ra] += (s16)d;
break;
default:
return 0;
}
return 1;
}
static int is_in_pci_mem_space(phys_addr_t addr)
{
struct pci_controller *hose;
struct resource *res;
int i;
list_for_each_entry(hose, &hose_list, list_node) {
if (!(hose->indirect_type & PPC_INDIRECT_TYPE_EXT_REG))
continue;
for (i = 0; i < 3; i++) {
res = &hose->mem_resources[i];
if ((res->flags & IORESOURCE_MEM) &&
addr >= res->start && addr <= res->end)
return 1;
}
}
return 0;
}
int fsl_pci_mcheck_exception(struct pt_regs *regs)
{
u32 inst;
int ret;
phys_addr_t addr = 0;
if (regs->msr & MSR_GS)
return 0;
#ifdef CONFIG_PHYS_64BIT
addr = mfspr(SPRN_MCARU);
addr <<= 32;
#endif
addr += mfspr(SPRN_MCAR);
if (is_in_pci_mem_space(addr)) {
if (user_mode(regs)) {
pagefault_disable();
ret = get_user(regs->nip, &inst);
pagefault_enable();
} else {
ret = probe_kernel_address(regs->nip, inst);
}
if (mcheck_handle_load(regs, inst)) {
regs->nip += 4;
return 1;
}
}
return 0;
}
void fsl_pci_assign_primary(void)
{
struct device_node *np;
if (fsl_pci_primary)
return;
np = of_find_node_by_type(NULL, "isa");
while ((fsl_pci_primary = of_get_parent(np))) {
of_node_put(np);
np = fsl_pci_primary;
if (of_match_node(pci_ids, np) && of_device_is_available(np))
return;
}
for_each_matching_node(np, pci_ids) {
if (of_device_is_available(np)) {
fsl_pci_primary = np;
of_node_put(np);
return;
}
}
}
static int fsl_pci_probe(struct platform_device *pdev)
{
int ret;
struct device_node *node;
node = pdev->dev.of_node;
ret = fsl_add_bridge(pdev, fsl_pci_primary == node);
mpc85xx_pci_err_probe(pdev);
return 0;
}
static int fsl_pci_resume(struct device *dev)
{
struct pci_controller *hose;
struct resource pci_rsrc;
hose = pci_find_hose_for_OF_device(dev->of_node);
if (!hose)
return -ENODEV;
if (of_address_to_resource(dev->of_node, 0, &pci_rsrc)) {
dev_err(dev, "Get pci register base failed.");
return -ENODEV;
}
setup_pci_atmu(hose);
return 0;
}
static int __init fsl_pci_init(void)
{
return platform_driver_register(&fsl_pci_driver);
}
