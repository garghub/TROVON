static int sbi_send(int port, int off, int op, u32 *data)
{
struct sbi_apl_message sbi_arg;
int ret, read = 0;
memset(&sbi_arg, 0, sizeof(sbi_arg));
if (op == 0 || op == 4 || op == 6)
read = 1;
else
sbi_arg.data = *data;
sbi_arg.opcode = op;
sbi_arg.port_address = port;
sbi_arg.register_offset = off;
ret = sbi_apl_commit(&sbi_arg);
if (ret || sbi_arg.status)
edac_dbg(2, "sbi_send status=%d ret=%d data=%x\n",
sbi_arg.status, ret, sbi_arg.data);
if (ret == 0)
ret = sbi_arg.status;
if (ret == 0 && read)
*data = sbi_arg.data;
return ret;
}
static int sbi_send(int port, int off, int op, u32 *data)
{
return -EUNATCH;
}
static int apl_rd_reg(int port, int off, int op, void *data, size_t sz, char *name)
{
int ret = 0;
edac_dbg(2, "Read %s port=%x off=%x op=%x\n", name, port, off, op);
switch (sz) {
case 8:
ret = sbi_send(port, off + 4, op, (u32 *)(data + 4));
case 4:
ret |= sbi_send(port, off, op, (u32 *)data);
pnd2_printk(KERN_DEBUG, "%s=%x%08x ret=%d\n", name,
sz == 8 ? *((u32 *)(data + 4)) : 0, *((u32 *)data), ret);
break;
}
return ret;
}
static u64 get_mem_ctrl_hub_base_addr(void)
{
struct b_cr_mchbar_lo_pci lo;
struct b_cr_mchbar_hi_pci hi;
struct pci_dev *pdev;
pdev = pci_get_device(PCI_VENDOR_ID_INTEL, 0x1980, NULL);
if (pdev) {
pci_read_config_dword(pdev, 0x48, (u32 *)&lo);
pci_read_config_dword(pdev, 0x4c, (u32 *)&hi);
pci_dev_put(pdev);
} else {
return 0;
}
if (!lo.enable) {
edac_dbg(2, "MMIO via memory controller hub base address is disabled!\n");
return 0;
}
return U64_LSHIFT(hi.base, 32) | U64_LSHIFT(lo.base, 15);
}
static u64 get_sideband_reg_base_addr(void)
{
struct pci_dev *pdev;
u32 hi, lo;
pdev = pci_get_device(PCI_VENDOR_ID_INTEL, 0x19dd, NULL);
if (pdev) {
pci_read_config_dword(pdev, 0x10, &lo);
pci_read_config_dword(pdev, 0x14, &hi);
pci_dev_put(pdev);
return (U64_LSHIFT(hi, 32) | U64_LSHIFT(lo, 0));
} else {
return 0xfd000000;
}
}
static int dnv_rd_reg(int port, int off, int op, void *data, size_t sz, char *name)
{
struct pci_dev *pdev;
char *base;
u64 addr;
if (op == 4) {
pdev = pci_get_device(PCI_VENDOR_ID_INTEL, 0x1980, NULL);
if (!pdev)
return -ENODEV;
pci_read_config_dword(pdev, off, data);
pci_dev_put(pdev);
} else {
if (op == 0 && port == 0x4c) {
addr = get_mem_ctrl_hub_base_addr();
if (!addr)
return -ENODEV;
} else {
addr = get_sideband_reg_base_addr();
if (!addr)
return -ENODEV;
addr += (port << 16);
}
base = ioremap((resource_size_t)addr, 0x10000);
if (!base)
return -ENODEV;
if (sz == 8)
*(u32 *)(data + 4) = *(u32 *)(base + off + 4);
*(u32 *)data = *(u32 *)(base + off);
iounmap(base);
}
edac_dbg(2, "Read %s=%.8x_%.8x\n", name,
(sz == 8) ? *(u32 *)(data + 4) : 0, *(u32 *)data);
return 0;
}
static void mk_region(char *name, struct region *rp, u64 base, u64 limit)
{
rp->enabled = 1;
rp->base = base;
rp->limit = limit;
edac_dbg(2, "Region:%s [%llx, %llx]\n", name, base, limit);
}
static void mk_region_mask(char *name, struct region *rp, u64 base, u64 mask)
{
if (mask == 0) {
pr_info(FW_BUG "MOT mask cannot be zero\n");
return;
}
if (mask != GENMASK_ULL(PND_MAX_PHYS_BIT, __ffs(mask))) {
pr_info(FW_BUG "MOT mask not power of two\n");
return;
}
if (base & ~mask) {
pr_info(FW_BUG "MOT region base/mask alignment error\n");
return;
}
rp->base = base;
rp->limit = (base | ~mask) & GENMASK_ULL(PND_MAX_PHYS_BIT, 0);
rp->enabled = 1;
edac_dbg(2, "Region:%s [%llx, %llx]\n", name, base, rp->limit);
}
static bool in_region(struct region *rp, u64 addr)
{
if (!rp->enabled)
return false;
return rp->base <= addr && addr <= rp->limit;
}
static int gen_sym_mask(struct b_cr_slice_channel_hash *p)
{
int mask = 0;
if (!p->slice_0_mem_disabled)
mask |= p->sym_slice0_channel_enabled;
if (!p->slice_1_disabled)
mask |= p->sym_slice1_channel_enabled << 2;
if (p->ch_1_disabled || p->enable_pmi_dual_data_mode)
mask &= 0x5;
return mask;
}
static int gen_asym_mask(struct b_cr_slice_channel_hash *p,
struct b_cr_asym_mem_region0_mchbar *as0,
struct b_cr_asym_mem_region1_mchbar *as1,
struct b_cr_asym_2way_mem_region_mchbar *as2way)
{
const int intlv[] = { 0x5, 0xA, 0x3, 0xC };
int mask = 0;
if (as2way->asym_2way_interleave_enable)
mask = intlv[as2way->asym_2way_intlv_mode];
if (as0->slice0_asym_enable)
mask |= (1 << as0->slice0_asym_channel_select);
if (as1->slice1_asym_enable)
mask |= (4 << as1->slice1_asym_channel_select);
if (p->slice_0_mem_disabled)
mask &= 0xc;
if (p->slice_1_disabled)
mask &= 0x3;
if (p->ch_1_disabled || p->enable_pmi_dual_data_mode)
mask &= 0x5;
return mask;
}
static void apl_mk_region(char *name, struct region *rp, void *asym)
{
struct b_cr_asym_mem_region0_mchbar *a = asym;
mk_region(name, rp,
U64_LSHIFT(a->slice0_asym_base, APL_ASYMSHIFT),
U64_LSHIFT(a->slice0_asym_limit, APL_ASYMSHIFT) +
GENMASK_ULL(APL_ASYMSHIFT - 1, 0));
}
static void dnv_mk_region(char *name, struct region *rp, void *asym)
{
struct b_cr_asym_mem_region_denverton *a = asym;
mk_region(name, rp,
U64_LSHIFT(a->slice_asym_base, DNV_ASYMSHIFT),
U64_LSHIFT(a->slice_asym_limit, DNV_ASYMSHIFT) +
GENMASK_ULL(DNV_ASYMSHIFT - 1, 0));
}
static int apl_get_registers(void)
{
int ret = -ENODEV;
int i;
if (RD_REG(&asym_2way, b_cr_asym_2way_mem_region_mchbar))
return -ENODEV;
for (i = 0; i < APL_NUM_CHANNELS; i++)
if (!RD_REGP(&drp0[i], d_cr_drp0, apl_dports[i]))
ret = 0;
return ret;
}
static int dnv_get_registers(void)
{
int i;
if (RD_REG(&dsch, d_cr_dsch))
return -ENODEV;
for (i = 0; i < DNV_NUM_CHANNELS; i++)
if (RD_REGP(&ecc_ctrl[i], d_cr_ecc_ctrl, dnv_dports[i]) ||
RD_REGP(&drp[i], d_cr_drp, dnv_dports[i]) ||
RD_REGP(&dmap[i], d_cr_dmap, dnv_dports[i]) ||
RD_REGP(&dmap1[i], d_cr_dmap1, dnv_dports[i]) ||
RD_REGP(&dmap2[i], d_cr_dmap2, dnv_dports[i]) ||
RD_REGP(&dmap3[i], d_cr_dmap3, dnv_dports[i]) ||
RD_REGP(&dmap4[i], d_cr_dmap4, dnv_dports[i]) ||
RD_REGP(&dmap5[i], d_cr_dmap5, dnv_dports[i]))
return -ENODEV;
return 0;
}
static int get_registers(void)
{
const int intlv[] = { 10, 11, 12, 12 };
if (RD_REG(&tolud, b_cr_tolud_pci) ||
RD_REG(&touud_lo, b_cr_touud_lo_pci) ||
RD_REG(&touud_hi, b_cr_touud_hi_pci) ||
RD_REG(&asym0, b_cr_asym_mem_region0_mchbar) ||
RD_REG(&asym1, b_cr_asym_mem_region1_mchbar) ||
RD_REG(&mot_base, b_cr_mot_out_base_mchbar) ||
RD_REG(&mot_mask, b_cr_mot_out_mask_mchbar) ||
RD_REG(&chash, b_cr_slice_channel_hash))
return -ENODEV;
if (ops->get_registers())
return -ENODEV;
if (ops->type == DNV) {
asym0.slice0_asym_channel_select = 0;
asym1.slice1_asym_channel_select = 0;
chash.sym_slice0_channel_enabled = 0x1;
chash.sym_slice1_channel_enabled = 0x1;
}
if (asym0.slice0_asym_enable)
ops->mk_region("as0", &as0, &asym0);
if (asym1.slice1_asym_enable)
ops->mk_region("as1", &as1, &asym1);
if (asym_2way.asym_2way_interleave_enable) {
mk_region("as2way", &as2,
U64_LSHIFT(asym_2way.asym_2way_base, APL_ASYMSHIFT),
U64_LSHIFT(asym_2way.asym_2way_limit, APL_ASYMSHIFT) +
GENMASK_ULL(APL_ASYMSHIFT - 1, 0));
}
if (mot_base.imr_en) {
mk_region_mask("mot", &mot,
U64_LSHIFT(mot_base.mot_out_base, MOT_SHIFT),
U64_LSHIFT(mot_mask.mot_out_mask, MOT_SHIFT));
}
top_lm = U64_LSHIFT(tolud.tolud, 20);
top_hm = U64_LSHIFT(touud_hi.touud, 32) | U64_LSHIFT(touud_lo.touud, 20);
two_slices = !chash.slice_1_disabled &&
!chash.slice_0_mem_disabled &&
(chash.sym_slice0_channel_enabled != 0) &&
(chash.sym_slice1_channel_enabled != 0);
two_channels = !chash.ch_1_disabled &&
!chash.enable_pmi_dual_data_mode &&
((chash.sym_slice0_channel_enabled == 3) ||
(chash.sym_slice1_channel_enabled == 3));
sym_chan_mask = gen_sym_mask(&chash);
asym_chan_mask = gen_asym_mask(&chash, &asym0, &asym1, &asym_2way);
chan_mask = sym_chan_mask | asym_chan_mask;
if (two_slices && !two_channels) {
if (chash.hvm_mode)
slice_selector = 29;
else
slice_selector = intlv[chash.interleave_mode];
} else if (!two_slices && two_channels) {
if (chash.hvm_mode)
chan_selector = 29;
else
chan_selector = intlv[chash.interleave_mode];
} else if (two_slices && two_channels) {
if (chash.hvm_mode) {
slice_selector = 29;
chan_selector = 30;
} else {
slice_selector = intlv[chash.interleave_mode];
chan_selector = intlv[chash.interleave_mode] + 1;
}
}
if (two_slices) {
if (!chash.hvm_mode)
slice_hash_mask = chash.slice_hash_mask << SLICE_HASH_MASK_LSB;
if (!two_channels)
slice_hash_mask |= BIT_ULL(slice_selector);
}
if (two_channels) {
if (!chash.hvm_mode)
chan_hash_mask = chash.ch_hash_mask << CH_HASH_MASK_LSB;
if (!two_slices)
chan_hash_mask |= BIT_ULL(chan_selector);
}
return 0;
}
static u64 remove_mmio_gap(u64 sys)
{
return (sys < _4GB) ? sys : sys - (_4GB - top_lm);
}
static void remove_addr_bit(u64 *addr, int bitidx)
{
u64 mask;
if (bitidx == -1)
return;
mask = (1ull << bitidx) - 1;
*addr = ((*addr >> 1) & ~mask) | (*addr & mask);
}
static int hash_by_mask(u64 addr, u64 mask)
{
u64 result = addr & mask;
result = (result >> 32) ^ result;
result = (result >> 16) ^ result;
result = (result >> 8) ^ result;
result = (result >> 4) ^ result;
result = (result >> 2) ^ result;
result = (result >> 1) ^ result;
return (int)result & 1;
}
static int sys2pmi(const u64 addr, u32 *pmiidx, u64 *pmiaddr, char *msg)
{
u64 contig_addr, contig_base, contig_offset, contig_base_adj;
int mot_intlv_bit = two_slices ? MOT_CHAN_INTLV_BIT_2SLC_2CH :
MOT_CHAN_INTLV_BIT_1SLC_2CH;
int slice_intlv_bit_rm = SELECTOR_DISABLED;
int chan_intlv_bit_rm = SELECTOR_DISABLED;
bool mot_hit = in_region(&mot, addr);
int sym_channels = hweight8(sym_chan_mask);
int sym_chan_shift = sym_channels >> 1;
if (addr >= (1ul << PND_MAX_PHYS_BIT) ||
(addr >= top_lm && addr < _4GB) || addr >= top_hm) {
snprintf(msg, PND2_MSG_SIZE, "Error address 0x%llx is not DRAM", addr);
return -EINVAL;
}
contig_addr = remove_mmio_gap(addr);
if (in_region(&as0, addr)) {
*pmiidx = asym0.slice0_asym_channel_select;
contig_base = remove_mmio_gap(as0.base);
contig_offset = contig_addr - contig_base;
contig_base_adj = (contig_base >> sym_chan_shift) *
((chash.sym_slice0_channel_enabled >> (*pmiidx & 1)) & 1);
contig_addr = contig_offset + ((sym_channels > 0) ? contig_base_adj : 0ull);
} else if (in_region(&as1, addr)) {
*pmiidx = 2u + asym1.slice1_asym_channel_select;
contig_base = remove_mmio_gap(as1.base);
contig_offset = contig_addr - contig_base;
contig_base_adj = (contig_base >> sym_chan_shift) *
((chash.sym_slice1_channel_enabled >> (*pmiidx & 1)) & 1);
contig_addr = contig_offset + ((sym_channels > 0) ? contig_base_adj : 0ull);
} else if (in_region(&as2, addr) && (asym_2way.asym_2way_intlv_mode == 0x3ul)) {
bool channel1;
mot_intlv_bit = MOT_CHAN_INTLV_BIT_1SLC_2CH;
*pmiidx = (asym_2way.asym_2way_intlv_mode & 1) << 1;
channel1 = mot_hit ? ((bool)((addr >> mot_intlv_bit) & 1)) :
hash_by_mask(contig_addr, chan_hash_mask);
*pmiidx |= (u32)channel1;
contig_base = remove_mmio_gap(as2.base);
chan_intlv_bit_rm = mot_hit ? mot_intlv_bit : chan_selector;
contig_offset = contig_addr - contig_base;
remove_addr_bit(&contig_offset, chan_intlv_bit_rm);
contig_addr = (contig_base >> sym_chan_shift) + contig_offset;
} else {
*pmiidx = 0u;
if (two_slices) {
bool slice1;
if (mot_hit) {
slice_intlv_bit_rm = MOT_SLC_INTLV_BIT;
slice1 = (addr >> MOT_SLC_INTLV_BIT) & 1;
} else {
slice_intlv_bit_rm = slice_selector;
slice1 = hash_by_mask(addr, slice_hash_mask);
}
*pmiidx = (u32)slice1 << 1;
}
if (two_channels) {
bool channel1;
mot_intlv_bit = two_slices ? MOT_CHAN_INTLV_BIT_2SLC_2CH :
MOT_CHAN_INTLV_BIT_1SLC_2CH;
if (mot_hit) {
chan_intlv_bit_rm = mot_intlv_bit;
channel1 = (addr >> mot_intlv_bit) & 1;
} else {
chan_intlv_bit_rm = chan_selector;
channel1 = hash_by_mask(contig_addr, chan_hash_mask);
}
*pmiidx |= (u32)channel1;
}
}
remove_addr_bit(&contig_addr, chan_intlv_bit_rm);
remove_addr_bit(&contig_addr, slice_intlv_bit_rm);
*pmiaddr = contig_addr;
return 0;
}
static int bank_hash(u64 pmiaddr, int idx, int shft)
{
int bhash = 0;
switch (idx) {
case 0:
bhash ^= ((pmiaddr >> (12 + shft)) ^ (pmiaddr >> (9 + shft))) & 1;
break;
case 1:
bhash ^= (((pmiaddr >> (10 + shft)) ^ (pmiaddr >> (8 + shft))) & 1) << 1;
bhash ^= ((pmiaddr >> 22) & 1) << 1;
break;
case 2:
bhash ^= (((pmiaddr >> (13 + shft)) ^ (pmiaddr >> (11 + shft))) & 1) << 2;
break;
}
return bhash;
}
static int rank_hash(u64 pmiaddr)
{
return ((pmiaddr >> 16) ^ (pmiaddr >> 10)) & 1;
}
static int apl_pmi2mem(struct mem_ctl_info *mci, u64 pmiaddr, u32 pmiidx,
struct dram_addr *daddr, char *msg)
{
struct d_cr_drp0 *cr_drp0 = &drp0[pmiidx];
struct pnd2_pvt *pvt = mci->pvt_info;
int g = pvt->dimm_geom[pmiidx];
struct dimm_geometry *d = &dimms[g];
int column = 0, bank = 0, row = 0, rank = 0;
int i, idx, type, skiprs = 0;
for (i = 0; i < PMI_ADDRESS_WIDTH; i++) {
int bit = (pmiaddr >> i) & 1;
if (i + skiprs >= PMI_ADDRESS_WIDTH) {
snprintf(msg, PND2_MSG_SIZE, "Bad dimm_geometry[] table\n");
return -EINVAL;
}
type = d->bits[i + skiprs] & ~0xf;
idx = d->bits[i + skiprs] & 0xf;
if (type == RS && (cr_drp0->rken0 + cr_drp0->rken1) == 1) {
skiprs = 1;
type = d->bits[i + skiprs] & ~0xf;
idx = d->bits[i + skiprs] & 0xf;
}
switch (type) {
case C(0):
column |= (bit << idx);
break;
case B(0):
bank |= (bit << idx);
if (cr_drp0->bahen)
bank ^= bank_hash(pmiaddr, idx, d->addrdec);
break;
case R(0):
row |= (bit << idx);
break;
case RS:
rank = bit;
if (cr_drp0->rsien)
rank ^= rank_hash(pmiaddr);
break;
default:
if (bit) {
snprintf(msg, PND2_MSG_SIZE, "Bad translation\n");
return -EINVAL;
}
goto done;
}
}
done:
daddr->col = column;
daddr->bank = bank;
daddr->row = row;
daddr->rank = rank;
daddr->dimm = 0;
return 0;
}
static int dnv_pmi2mem(struct mem_ctl_info *mci, u64 pmiaddr, u32 pmiidx,
struct dram_addr *daddr, char *msg)
{
daddr->rank = dnv_get_bit(pmiaddr, dmap[pmiidx].rs0 + 13, 0);
daddr->rank |= dnv_get_bit(pmiaddr, dmap[pmiidx].rs1 + 13, 1);
daddr->dimm = (daddr->rank >= 2) ^ drp[pmiidx].dimmflip;
daddr->bank = dnv_get_bit(pmiaddr, dmap[pmiidx].ba0 + 6, 0);
daddr->bank |= dnv_get_bit(pmiaddr, dmap[pmiidx].ba1 + 6, 1);
daddr->bank |= dnv_get_bit(pmiaddr, dmap[pmiidx].bg0 + 6, 2);
if (dsch.ddr4en)
daddr->bank |= dnv_get_bit(pmiaddr, dmap[pmiidx].bg1 + 6, 3);
if (dmap1[pmiidx].bxor) {
if (dsch.ddr4en) {
daddr->bank ^= dnv_get_bit(pmiaddr, dmap3[pmiidx].row6 + 6, 0);
daddr->bank ^= dnv_get_bit(pmiaddr, dmap3[pmiidx].row7 + 6, 1);
if (dsch.chan_width == 0)
daddr->bank ^= dnv_get_bit(pmiaddr, dmap5[pmiidx].ca3 + 6, 2);
else
daddr->bank ^= dnv_get_bit(pmiaddr, dmap5[pmiidx].ca4 + 6, 2);
daddr->bank ^= dnv_get_bit(pmiaddr, dmap2[pmiidx].row2 + 6, 3);
} else {
daddr->bank ^= dnv_get_bit(pmiaddr, dmap2[pmiidx].row2 + 6, 0);
daddr->bank ^= dnv_get_bit(pmiaddr, dmap3[pmiidx].row6 + 6, 1);
if (dsch.chan_width == 0)
daddr->bank ^= dnv_get_bit(pmiaddr, dmap5[pmiidx].ca3 + 6, 2);
else
daddr->bank ^= dnv_get_bit(pmiaddr, dmap5[pmiidx].ca4 + 6, 2);
}
}
daddr->row = dnv_get_bit(pmiaddr, dmap2[pmiidx].row0 + 6, 0);
daddr->row |= dnv_get_bit(pmiaddr, dmap2[pmiidx].row1 + 6, 1);
daddr->row |= dnv_get_bit(pmiaddr, dmap2[pmiidx].row2 + 6, 2);
daddr->row |= dnv_get_bit(pmiaddr, dmap2[pmiidx].row3 + 6, 3);
daddr->row |= dnv_get_bit(pmiaddr, dmap2[pmiidx].row4 + 6, 4);
daddr->row |= dnv_get_bit(pmiaddr, dmap2[pmiidx].row5 + 6, 5);
daddr->row |= dnv_get_bit(pmiaddr, dmap3[pmiidx].row6 + 6, 6);
daddr->row |= dnv_get_bit(pmiaddr, dmap3[pmiidx].row7 + 6, 7);
daddr->row |= dnv_get_bit(pmiaddr, dmap3[pmiidx].row8 + 6, 8);
daddr->row |= dnv_get_bit(pmiaddr, dmap3[pmiidx].row9 + 6, 9);
daddr->row |= dnv_get_bit(pmiaddr, dmap3[pmiidx].row10 + 6, 10);
daddr->row |= dnv_get_bit(pmiaddr, dmap3[pmiidx].row11 + 6, 11);
daddr->row |= dnv_get_bit(pmiaddr, dmap4[pmiidx].row12 + 6, 12);
daddr->row |= dnv_get_bit(pmiaddr, dmap4[pmiidx].row13 + 6, 13);
if (dmap4[pmiidx].row14 != 31)
daddr->row |= dnv_get_bit(pmiaddr, dmap4[pmiidx].row14 + 6, 14);
if (dmap4[pmiidx].row15 != 31)
daddr->row |= dnv_get_bit(pmiaddr, dmap4[pmiidx].row15 + 6, 15);
if (dmap4[pmiidx].row16 != 31)
daddr->row |= dnv_get_bit(pmiaddr, dmap4[pmiidx].row16 + 6, 16);
if (dmap4[pmiidx].row17 != 31)
daddr->row |= dnv_get_bit(pmiaddr, dmap4[pmiidx].row17 + 6, 17);
daddr->col = dnv_get_bit(pmiaddr, dmap5[pmiidx].ca3 + 6, 3);
daddr->col |= dnv_get_bit(pmiaddr, dmap5[pmiidx].ca4 + 6, 4);
daddr->col |= dnv_get_bit(pmiaddr, dmap5[pmiidx].ca5 + 6, 5);
daddr->col |= dnv_get_bit(pmiaddr, dmap5[pmiidx].ca6 + 6, 6);
daddr->col |= dnv_get_bit(pmiaddr, dmap5[pmiidx].ca7 + 6, 7);
daddr->col |= dnv_get_bit(pmiaddr, dmap5[pmiidx].ca8 + 6, 8);
daddr->col |= dnv_get_bit(pmiaddr, dmap5[pmiidx].ca9 + 6, 9);
if (!dsch.ddr4en && dmap1[pmiidx].ca11 != 0x3f)
daddr->col |= dnv_get_bit(pmiaddr, dmap1[pmiidx].ca11 + 13, 11);
return 0;
}
static int check_channel(int ch)
{
if (drp0[ch].dramtype != 0) {
pnd2_printk(KERN_INFO, "Unsupported DIMM in channel %d\n", ch);
return 1;
} else if (drp0[ch].eccen == 0) {
pnd2_printk(KERN_INFO, "ECC disabled on channel %d\n", ch);
return 1;
}
return 0;
}
static int apl_check_ecc_active(void)
{
int i, ret = 0;
for (i = 0; i < APL_NUM_CHANNELS; i++)
if (chan_mask & BIT(i))
ret += check_channel(i);
return ret ? -EINVAL : 0;
}
static int check_unit(int ch)
{
struct d_cr_drp *d = &drp[ch];
if (DIMMS_PRESENT(d) && !ecc_ctrl[ch].eccen) {
pnd2_printk(KERN_INFO, "ECC disabled on channel %d\n", ch);
return 1;
}
return 0;
}
static int dnv_check_ecc_active(void)
{
int i, ret = 0;
for (i = 0; i < DNV_NUM_CHANNELS; i++)
ret += check_unit(i);
return ret ? -EINVAL : 0;
}
static int get_memory_error_data(struct mem_ctl_info *mci, u64 addr,
struct dram_addr *daddr, char *msg)
{
u64 pmiaddr;
u32 pmiidx;
int ret;
ret = sys2pmi(addr, &pmiidx, &pmiaddr, msg);
if (ret)
return ret;
pmiaddr >>= ops->pmiaddr_shift;
pmiidx >>= ops->pmiidx_shift;
daddr->chan = pmiidx;
ret = ops->pmi2mem(mci, pmiaddr, pmiidx, daddr, msg);
if (ret)
return ret;
edac_dbg(0, "SysAddr=%llx PmiAddr=%llx Channel=%d DIMM=%d Rank=%d Bank=%d Row=%d Column=%d\n",
addr, pmiaddr, daddr->chan, daddr->dimm, daddr->rank, daddr->bank, daddr->row, daddr->col);
return 0;
}
static void pnd2_mce_output_error(struct mem_ctl_info *mci, const struct mce *m,
struct dram_addr *daddr)
{
enum hw_event_mc_err_type tp_event;
char *optype, msg[PND2_MSG_SIZE];
bool ripv = m->mcgstatus & MCG_STATUS_RIPV;
bool overflow = m->status & MCI_STATUS_OVER;
bool uc_err = m->status & MCI_STATUS_UC;
bool recov = m->status & MCI_STATUS_S;
u32 core_err_cnt = GET_BITFIELD(m->status, 38, 52);
u32 mscod = GET_BITFIELD(m->status, 16, 31);
u32 errcode = GET_BITFIELD(m->status, 0, 15);
u32 optypenum = GET_BITFIELD(m->status, 4, 6);
int rc;
tp_event = uc_err ? (ripv ? HW_EVENT_ERR_FATAL : HW_EVENT_ERR_UNCORRECTED) :
HW_EVENT_ERR_CORRECTED;
if (!((errcode & 0xef80) == 0x80)) {
optype = "Can't parse: it is not a mem";
} else {
switch (optypenum) {
case 0:
optype = "generic undef request error";
break;
case 1:
optype = "memory read error";
break;
case 2:
optype = "memory write error";
break;
case 3:
optype = "addr/cmd error";
break;
case 4:
optype = "memory scrubbing error";
break;
default:
optype = "reserved";
break;
}
}
if (!(m->status & MCI_STATUS_ADDRV))
return;
rc = get_memory_error_data(mci, m->addr, daddr, msg);
if (rc)
goto address_error;
snprintf(msg, sizeof(msg),
"%s%s err_code:%04x:%04x channel:%d DIMM:%d rank:%d row:%d bank:%d col:%d",
overflow ? " OVERFLOW" : "", (uc_err && recov) ? " recoverable" : "", mscod,
errcode, daddr->chan, daddr->dimm, daddr->rank, daddr->row, daddr->bank, daddr->col);
edac_dbg(0, "%s\n", msg);
edac_mc_handle_error(tp_event, mci, core_err_cnt, m->addr >> PAGE_SHIFT,
m->addr & ~PAGE_MASK, 0, daddr->chan, daddr->dimm, -1, optype, msg);
return;
address_error:
edac_mc_handle_error(tp_event, mci, core_err_cnt, 0, 0, 0, -1, -1, -1, msg, "");
}
static void apl_get_dimm_config(struct mem_ctl_info *mci)
{
struct pnd2_pvt *pvt = mci->pvt_info;
struct dimm_info *dimm;
struct d_cr_drp0 *d;
u64 capacity;
int i, g;
for (i = 0; i < APL_NUM_CHANNELS; i++) {
if (!(chan_mask & BIT(i)))
continue;
dimm = EDAC_DIMM_PTR(mci->layers, mci->dimms, mci->n_layers, i, 0, 0);
if (!dimm) {
edac_dbg(0, "No allocated DIMM for channel %d\n", i);
continue;
}
d = &drp0[i];
for (g = 0; g < ARRAY_SIZE(dimms); g++)
if (dimms[g].addrdec == d->addrdec &&
dimms[g].dden == d->dden &&
dimms[g].dwid == d->dwid)
break;
if (g == ARRAY_SIZE(dimms)) {
edac_dbg(0, "Channel %d: unrecognized DIMM\n", i);
continue;
}
pvt->dimm_geom[i] = g;
capacity = (d->rken0 + d->rken1) * 8 * (1ul << dimms[g].rowbits) *
(1ul << dimms[g].colbits);
edac_dbg(0, "Channel %d: %lld MByte DIMM\n", i, capacity >> (20 - 3));
dimm->nr_pages = MiB_TO_PAGES(capacity >> (20 - 3));
dimm->grain = 32;
dimm->dtype = (d->dwid == 0) ? DEV_X8 : DEV_X16;
dimm->mtype = MEM_DDR3;
dimm->edac_mode = EDAC_SECDED;
snprintf(dimm->label, sizeof(dimm->label), "Slice#%d_Chan#%d", i / 2, i % 2);
}
}
static void dnv_get_dimm_config(struct mem_ctl_info *mci)
{
int i, j, ranks_of_dimm[DNV_MAX_DIMMS], banks, rowbits, colbits, memtype;
struct dimm_info *dimm;
struct d_cr_drp *d;
u64 capacity;
if (dsch.ddr4en) {
memtype = MEM_DDR4;
banks = 16;
colbits = 10;
} else {
memtype = MEM_DDR3;
banks = 8;
}
for (i = 0; i < DNV_NUM_CHANNELS; i++) {
if (dmap4[i].row14 == 31)
rowbits = 14;
else if (dmap4[i].row15 == 31)
rowbits = 15;
else if (dmap4[i].row16 == 31)
rowbits = 16;
else if (dmap4[i].row17 == 31)
rowbits = 17;
else
rowbits = 18;
if (memtype == MEM_DDR3) {
if (dmap1[i].ca11 != 0x3f)
colbits = 12;
else
colbits = 10;
}
d = &drp[i];
ranks_of_dimm[0] = d->rken0 + d->rken1;
ranks_of_dimm[1] = d->rken2 + d->rken3;
for (j = 0; j < DNV_MAX_DIMMS; j++) {
if (!ranks_of_dimm[j])
continue;
dimm = EDAC_DIMM_PTR(mci->layers, mci->dimms, mci->n_layers, i, j, 0);
if (!dimm) {
edac_dbg(0, "No allocated DIMM for channel %d DIMM %d\n", i, j);
continue;
}
capacity = ranks_of_dimm[j] * banks * (1ul << rowbits) * (1ul << colbits);
edac_dbg(0, "Channel %d DIMM %d: %lld MByte DIMM\n", i, j, capacity >> (20 - 3));
dimm->nr_pages = MiB_TO_PAGES(capacity >> (20 - 3));
dimm->grain = 32;
dimm->dtype = dnv_dtypes[j ? d->dimmdwid0 : d->dimmdwid1];
dimm->mtype = memtype;
dimm->edac_mode = EDAC_SECDED;
snprintf(dimm->label, sizeof(dimm->label), "Chan#%d_DIMM#%d", i, j);
}
}
}
static int pnd2_register_mci(struct mem_ctl_info **ppmci)
{
struct edac_mc_layer layers[2];
struct mem_ctl_info *mci;
struct pnd2_pvt *pvt;
int rc;
rc = ops->check_ecc();
if (rc < 0)
return rc;
layers[0].type = EDAC_MC_LAYER_CHANNEL;
layers[0].size = ops->channels;
layers[0].is_virt_csrow = false;
layers[1].type = EDAC_MC_LAYER_SLOT;
layers[1].size = ops->dimms_per_channel;
layers[1].is_virt_csrow = true;
mci = edac_mc_alloc(0, ARRAY_SIZE(layers), layers, sizeof(*pvt));
if (!mci)
return -ENOMEM;
pvt = mci->pvt_info;
memset(pvt, 0, sizeof(*pvt));
mci->mod_name = "pnd2_edac.c";
mci->dev_name = ops->name;
mci->ctl_name = "Pondicherry2";
ops->get_dimm_config(mci);
if (edac_mc_add_mc(mci)) {
edac_dbg(0, "MC: failed edac_mc_add_mc()\n");
edac_mc_free(mci);
return -EINVAL;
}
*ppmci = mci;
return 0;
}
static void pnd2_unregister_mci(struct mem_ctl_info *mci)
{
if (unlikely(!mci || !mci->pvt_info)) {
pnd2_printk(KERN_ERR, "Couldn't find mci handler\n");
return;
}
edac_mc_del_mc(NULL);
edac_dbg(1, "%s: free mci struct\n", mci->ctl_name);
edac_mc_free(mci);
}
static int pnd2_mce_check_error(struct notifier_block *nb, unsigned long val, void *data)
{
struct mce *mce = (struct mce *)data;
struct mem_ctl_info *mci;
struct dram_addr daddr;
char *type;
if (edac_get_report_status() == EDAC_REPORTING_DISABLED)
return NOTIFY_DONE;
mci = pnd2_mci;
if (!mci)
return NOTIFY_DONE;
if ((mce->status & 0xefff) >> 7 != 1)
return NOTIFY_DONE;
if (mce->mcgstatus & MCG_STATUS_MCIP)
type = "Exception";
else
type = "Event";
pnd2_mc_printk(mci, KERN_INFO, "HANDLING MCE MEMORY ERROR\n");
pnd2_mc_printk(mci, KERN_INFO, "CPU %u: Machine Check %s: %llx Bank %u: %llx\n",
mce->extcpu, type, mce->mcgstatus, mce->bank, mce->status);
pnd2_mc_printk(mci, KERN_INFO, "TSC %llx ", mce->tsc);
pnd2_mc_printk(mci, KERN_INFO, "ADDR %llx ", mce->addr);
pnd2_mc_printk(mci, KERN_INFO, "MISC %llx ", mce->misc);
pnd2_mc_printk(mci, KERN_INFO, "PROCESSOR %u:%x TIME %llu SOCKET %u APIC %x\n",
mce->cpuvendor, mce->cpuid, mce->time, mce->socketid, mce->apicid);
pnd2_mce_output_error(mci, mce, &daddr);
return NOTIFY_STOP;
}
static int debugfs_u64_set(void *data, u64 val)
{
struct dram_addr daddr;
struct mce m;
*(u64 *)data = val;
m.mcgstatus = 0;
m.status = MCI_STATUS_ADDRV + 0x9f;
m.addr = val;
pnd2_mce_output_error(pnd2_mci, &m, &daddr);
snprintf(pnd2_blob.data, PND2_BLOB_SIZE,
"SysAddr=%llx Channel=%d DIMM=%d Rank=%d Bank=%d Row=%d Column=%d\n",
m.addr, daddr.chan, daddr.dimm, daddr.rank, daddr.bank, daddr.row, daddr.col);
pnd2_blob.size = strlen(pnd2_blob.data);
return 0;
}
static void setup_pnd2_debug(void)
{
pnd2_test = edac_debugfs_create_dir("pnd2_test");
edac_debugfs_create_file("pnd2_debug_addr", 0200, pnd2_test,
&pnd2_fake_addr, &fops_u64_wo);
debugfs_create_blob("pnd2_debug_results", 0400, pnd2_test, &pnd2_blob);
}
static void teardown_pnd2_debug(void)
{
debugfs_remove_recursive(pnd2_test);
}
static void setup_pnd2_debug(void) {}
static void teardown_pnd2_debug(void) {}
static int pnd2_probe(void)
{
int rc;
edac_dbg(2, "\n");
rc = get_registers();
if (rc)
return rc;
return pnd2_register_mci(&pnd2_mci);
}
static void pnd2_remove(void)
{
edac_dbg(0, "\n");
pnd2_unregister_mci(pnd2_mci);
}
static int __init pnd2_init(void)
{
const struct x86_cpu_id *id;
int rc;
edac_dbg(2, "\n");
id = x86_match_cpu(pnd2_cpuids);
if (!id)
return -ENODEV;
ops = (struct dunit_ops *)id->driver_data;
opstate_init();
rc = pnd2_probe();
if (rc < 0) {
pnd2_printk(KERN_ERR, "Failed to register device with error %d.\n", rc);
return rc;
}
if (!pnd2_mci)
return -ENODEV;
mce_register_decode_chain(&pnd2_mce_dec);
setup_pnd2_debug();
return 0;
}
static void __exit pnd2_exit(void)
{
edac_dbg(2, "\n");
teardown_pnd2_debug();
mce_unregister_decode_chain(&pnd2_mce_dec);
pnd2_remove();
}
