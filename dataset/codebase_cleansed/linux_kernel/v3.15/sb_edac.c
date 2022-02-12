static char *get_dram_attr(u32 reg)
{
switch(DRAM_ATTR(reg)) {
case 0:
return "DRAM";
case 1:
return "MMCFG";
case 2:
return "NXM";
default:
return "unknown";
}
}
static inline int sad_pkg(const struct interleave_pkg *table, u32 reg,
int interleave)
{
return GET_BITFIELD(reg, table[interleave].start,
table[interleave].end);
}
static inline int numrank(u32 mtr)
{
int ranks = (1 << RANK_CNT_BITS(mtr));
if (ranks > 4) {
edac_dbg(0, "Invalid number of ranks: %d (max = 4) raw value = %x (%04x)\n",
ranks, (unsigned int)RANK_CNT_BITS(mtr), mtr);
return -EINVAL;
}
return ranks;
}
static inline int numrow(u32 mtr)
{
int rows = (RANK_WIDTH_BITS(mtr) + 12);
if (rows < 13 || rows > 18) {
edac_dbg(0, "Invalid number of rows: %d (should be between 14 and 17) raw value = %x (%04x)\n",
rows, (unsigned int)RANK_WIDTH_BITS(mtr), mtr);
return -EINVAL;
}
return 1 << rows;
}
static inline int numcol(u32 mtr)
{
int cols = (COL_WIDTH_BITS(mtr) + 10);
if (cols > 12) {
edac_dbg(0, "Invalid number of cols: %d (max = 4) raw value = %x (%04x)\n",
cols, (unsigned int)COL_WIDTH_BITS(mtr), mtr);
return -EINVAL;
}
return 1 << cols;
}
static struct sbridge_dev *get_sbridge_dev(u8 bus)
{
struct sbridge_dev *sbridge_dev;
list_for_each_entry(sbridge_dev, &sbridge_edac_list, list) {
if (sbridge_dev->bus == bus)
return sbridge_dev;
}
return NULL;
}
static struct sbridge_dev *alloc_sbridge_dev(u8 bus,
const struct pci_id_table *table)
{
struct sbridge_dev *sbridge_dev;
sbridge_dev = kzalloc(sizeof(*sbridge_dev), GFP_KERNEL);
if (!sbridge_dev)
return NULL;
sbridge_dev->pdev = kzalloc(sizeof(*sbridge_dev->pdev) * table->n_devs,
GFP_KERNEL);
if (!sbridge_dev->pdev) {
kfree(sbridge_dev);
return NULL;
}
sbridge_dev->bus = bus;
sbridge_dev->n_devs = table->n_devs;
list_add_tail(&sbridge_dev->list, &sbridge_edac_list);
return sbridge_dev;
}
static void free_sbridge_dev(struct sbridge_dev *sbridge_dev)
{
list_del(&sbridge_dev->list);
kfree(sbridge_dev->pdev);
kfree(sbridge_dev);
}
static u64 sbridge_get_tolm(struct sbridge_pvt *pvt)
{
u32 reg;
pci_read_config_dword(pvt->pci_sad1, TOLM, &reg);
return GET_TOLM(reg);
}
static u64 sbridge_get_tohm(struct sbridge_pvt *pvt)
{
u32 reg;
pci_read_config_dword(pvt->pci_sad1, TOHM, &reg);
return GET_TOHM(reg);
}
static u64 ibridge_get_tolm(struct sbridge_pvt *pvt)
{
u32 reg;
pci_read_config_dword(pvt->pci_br1, TOLM, &reg);
return GET_TOLM(reg);
}
static u64 ibridge_get_tohm(struct sbridge_pvt *pvt)
{
u32 reg;
pci_read_config_dword(pvt->pci_br1, TOHM, &reg);
return GET_TOHM(reg);
}
static inline u8 sad_pkg_socket(u8 pkg)
{
return (pkg >> 3) | (pkg & 0x3);
}
static inline u8 sad_pkg_ha(u8 pkg)
{
return (pkg >> 2) & 0x1;
}
static struct pci_dev *get_pdev_slot_func(u8 bus, unsigned slot,
unsigned func)
{
struct sbridge_dev *sbridge_dev = get_sbridge_dev(bus);
int i;
if (!sbridge_dev)
return NULL;
for (i = 0; i < sbridge_dev->n_devs; i++) {
if (!sbridge_dev->pdev[i])
continue;
if (PCI_SLOT(sbridge_dev->pdev[i]->devfn) == slot &&
PCI_FUNC(sbridge_dev->pdev[i]->devfn) == func) {
edac_dbg(1, "Associated %02x.%02x.%d with %p\n",
bus, slot, func, sbridge_dev->pdev[i]);
return sbridge_dev->pdev[i];
}
}
return NULL;
}
static int check_if_ecc_is_active(const u8 bus)
{
struct pci_dev *pdev = NULL;
u32 mcmtr;
pdev = get_pdev_slot_func(bus, 15, 0);
if (!pdev) {
sbridge_printk(KERN_ERR, "Couldn't find PCI device "
"%2x.%02d.%d!!!\n",
bus, 15, 0);
return -ENODEV;
}
pci_read_config_dword(pdev, MCMTR, &mcmtr);
if (!IS_ECC_ENABLED(mcmtr)) {
sbridge_printk(KERN_ERR, "ECC is disabled. Aborting\n");
return -ENODEV;
}
return 0;
}
static int get_dimm_config(struct mem_ctl_info *mci)
{
struct sbridge_pvt *pvt = mci->pvt_info;
struct dimm_info *dimm;
unsigned i, j, banks, ranks, rows, cols, npages;
u64 size;
u32 reg;
enum edac_type mode;
enum mem_type mtype;
pci_read_config_dword(pvt->pci_br0, SAD_TARGET, &reg);
pvt->sbridge_dev->source_id = SOURCE_ID(reg);
pci_read_config_dword(pvt->pci_br0, SAD_CONTROL, &reg);
pvt->sbridge_dev->node_id = NODE_ID(reg);
edac_dbg(0, "mc#%d: Node ID: %d, source ID: %d\n",
pvt->sbridge_dev->mc,
pvt->sbridge_dev->node_id,
pvt->sbridge_dev->source_id);
pci_read_config_dword(pvt->pci_ras, RASENABLES, &reg);
if (IS_MIRROR_ENABLED(reg)) {
edac_dbg(0, "Memory mirror is enabled\n");
pvt->is_mirrored = true;
} else {
edac_dbg(0, "Memory mirror is disabled\n");
pvt->is_mirrored = false;
}
pci_read_config_dword(pvt->pci_ta, MCMTR, &pvt->info.mcmtr);
if (IS_LOCKSTEP_ENABLED(pvt->info.mcmtr)) {
edac_dbg(0, "Lockstep is enabled\n");
mode = EDAC_S8ECD8ED;
pvt->is_lockstep = true;
} else {
edac_dbg(0, "Lockstep is disabled\n");
mode = EDAC_S4ECD4ED;
pvt->is_lockstep = false;
}
if (IS_CLOSE_PG(pvt->info.mcmtr)) {
edac_dbg(0, "address map is on closed page mode\n");
pvt->is_close_pg = true;
} else {
edac_dbg(0, "address map is on open page mode\n");
pvt->is_close_pg = false;
}
if (pvt->pci_ddrio) {
pci_read_config_dword(pvt->pci_ddrio, pvt->info.rankcfgr,
&reg);
if (IS_RDIMM_ENABLED(reg)) {
edac_dbg(0, "Memory is registered\n");
mtype = MEM_RDDR3;
} else {
edac_dbg(0, "Memory is unregistered\n");
mtype = MEM_DDR3;
}
} else {
edac_dbg(0, "Cannot determine memory type\n");
mtype = MEM_UNKNOWN;
}
banks = 8;
for (i = 0; i < NUM_CHANNELS; i++) {
u32 mtr;
for (j = 0; j < ARRAY_SIZE(mtr_regs); j++) {
dimm = EDAC_DIMM_PTR(mci->layers, mci->dimms, mci->n_layers,
i, j, 0);
pci_read_config_dword(pvt->pci_tad[i],
mtr_regs[j], &mtr);
edac_dbg(4, "Channel #%d MTR%d = %x\n", i, j, mtr);
if (IS_DIMM_PRESENT(mtr)) {
pvt->channel[i].dimms++;
ranks = numrank(mtr);
rows = numrow(mtr);
cols = numcol(mtr);
size = ((u64)rows * cols * banks * ranks) >> (20 - 3);
npages = MiB_TO_PAGES(size);
edac_dbg(0, "mc#%d: channel %d, dimm %d, %Ld Mb (%d pages) bank: %d, rank: %d, row: %#x, col: %#x\n",
pvt->sbridge_dev->mc, i, j,
size, npages,
banks, ranks, rows, cols);
dimm->nr_pages = npages;
dimm->grain = 32;
dimm->dtype = (banks == 8) ? DEV_X8 : DEV_X4;
dimm->mtype = mtype;
dimm->edac_mode = mode;
snprintf(dimm->label, sizeof(dimm->label),
"CPU_SrcID#%u_Channel#%u_DIMM#%u",
pvt->sbridge_dev->source_id, i, j);
}
}
}
return 0;
}
static void get_memory_layout(const struct mem_ctl_info *mci)
{
struct sbridge_pvt *pvt = mci->pvt_info;
int i, j, k, n_sads, n_tads, sad_interl;
u32 reg;
u64 limit, prv = 0;
u64 tmp_mb;
u32 mb, kb;
u32 rir_way;
pvt->tolm = pvt->info.get_tolm(pvt);
tmp_mb = (1 + pvt->tolm) >> 20;
mb = div_u64_rem(tmp_mb, 1000, &kb);
edac_dbg(0, "TOLM: %u.%03u GB (0x%016Lx)\n", mb, kb, (u64)pvt->tolm);
pvt->tohm = pvt->info.get_tohm(pvt);
tmp_mb = (1 + pvt->tohm) >> 20;
mb = div_u64_rem(tmp_mb, 1000, &kb);
edac_dbg(0, "TOHM: %u.%03u GB (0x%016Lx)\n", mb, kb, (u64)pvt->tohm);
prv = 0;
for (n_sads = 0; n_sads < pvt->info.max_sad; n_sads++) {
pci_read_config_dword(pvt->pci_sad0, pvt->info.dram_rule[n_sads],
&reg);
limit = SAD_LIMIT(reg);
if (!DRAM_RULE_ENABLE(reg))
continue;
if (limit <= prv)
break;
tmp_mb = (limit + 1) >> 20;
mb = div_u64_rem(tmp_mb, 1000, &kb);
edac_dbg(0, "SAD#%d %s up to %u.%03u GB (0x%016Lx) Interleave: %s reg=0x%08x\n",
n_sads,
get_dram_attr(reg),
mb, kb,
((u64)tmp_mb) << 20L,
INTERLEAVE_MODE(reg) ? "8:6" : "[8:6]XOR[18:16]",
reg);
prv = limit;
pci_read_config_dword(pvt->pci_sad0, pvt->info.interleave_list[n_sads],
&reg);
sad_interl = sad_pkg(pvt->info.interleave_pkg, reg, 0);
for (j = 0; j < 8; j++) {
u32 pkg = sad_pkg(pvt->info.interleave_pkg, reg, j);
if (j > 0 && sad_interl == pkg)
break;
edac_dbg(0, "SAD#%d, interleave #%d: %d\n",
n_sads, j, pkg);
}
}
prv = 0;
for (n_tads = 0; n_tads < MAX_TAD; n_tads++) {
pci_read_config_dword(pvt->pci_ha0, tad_dram_rule[n_tads],
&reg);
limit = TAD_LIMIT(reg);
if (limit <= prv)
break;
tmp_mb = (limit + 1) >> 20;
mb = div_u64_rem(tmp_mb, 1000, &kb);
edac_dbg(0, "TAD#%d: up to %u.%03u GB (0x%016Lx), socket interleave %d, memory interleave %d, TGT: %d, %d, %d, %d, reg=0x%08x\n",
n_tads, mb, kb,
((u64)tmp_mb) << 20L,
(u32)TAD_SOCK(reg),
(u32)TAD_CH(reg),
(u32)TAD_TGT0(reg),
(u32)TAD_TGT1(reg),
(u32)TAD_TGT2(reg),
(u32)TAD_TGT3(reg),
reg);
prv = limit;
}
for (i = 0; i < NUM_CHANNELS; i++) {
if (!pvt->channel[i].dimms)
continue;
for (j = 0; j < n_tads; j++) {
pci_read_config_dword(pvt->pci_tad[i],
tad_ch_nilv_offset[j],
&reg);
tmp_mb = TAD_OFFSET(reg) >> 20;
mb = div_u64_rem(tmp_mb, 1000, &kb);
edac_dbg(0, "TAD CH#%d, offset #%d: %u.%03u GB (0x%016Lx), reg=0x%08x\n",
i, j,
mb, kb,
((u64)tmp_mb) << 20L,
reg);
}
}
for (i = 0; i < NUM_CHANNELS; i++) {
if (!pvt->channel[i].dimms)
continue;
for (j = 0; j < MAX_RIR_RANGES; j++) {
pci_read_config_dword(pvt->pci_tad[i],
rir_way_limit[j],
&reg);
if (!IS_RIR_VALID(reg))
continue;
tmp_mb = RIR_LIMIT(reg) >> 20;
rir_way = 1 << RIR_WAY(reg);
mb = div_u64_rem(tmp_mb, 1000, &kb);
edac_dbg(0, "CH#%d RIR#%d, limit: %u.%03u GB (0x%016Lx), way: %d, reg=0x%08x\n",
i, j,
mb, kb,
((u64)tmp_mb) << 20L,
rir_way,
reg);
for (k = 0; k < rir_way; k++) {
pci_read_config_dword(pvt->pci_tad[i],
rir_offset[j][k],
&reg);
tmp_mb = RIR_OFFSET(reg) << 6;
mb = div_u64_rem(tmp_mb, 1000, &kb);
edac_dbg(0, "CH#%d RIR#%d INTL#%d, offset %u.%03u GB (0x%016Lx), tgt: %d, reg=0x%08x\n",
i, j, k,
mb, kb,
((u64)tmp_mb) << 20L,
(u32)RIR_RNK_TGT(reg),
reg);
}
}
}
}
static struct mem_ctl_info *get_mci_for_node_id(u8 node_id)
{
struct sbridge_dev *sbridge_dev;
list_for_each_entry(sbridge_dev, &sbridge_edac_list, list) {
if (sbridge_dev->node_id == node_id)
return sbridge_dev->mci;
}
return NULL;
}
static int get_memory_error_data(struct mem_ctl_info *mci,
u64 addr,
u8 *socket,
long *channel_mask,
u8 *rank,
char **area_type, char *msg)
{
struct mem_ctl_info *new_mci;
struct sbridge_pvt *pvt = mci->pvt_info;
struct pci_dev *pci_ha;
int n_rir, n_sads, n_tads, sad_way, sck_xch;
int sad_interl, idx, base_ch;
int interleave_mode;
unsigned sad_interleave[pvt->info.max_interleave];
u32 reg;
u8 ch_way, sck_way, pkg, sad_ha = 0;
u32 tad_offset;
u32 rir_way;
u32 mb, kb;
u64 ch_addr, offset, limit = 0, prv = 0;
if ((addr > (u64) pvt->tolm) && (addr < (1LL << 32))) {
sprintf(msg, "Error at TOLM area, on addr 0x%08Lx", addr);
return -EINVAL;
}
if (addr >= (u64)pvt->tohm) {
sprintf(msg, "Error at MMIOH area, on addr 0x%016Lx", addr);
return -EINVAL;
}
for (n_sads = 0; n_sads < pvt->info.max_sad; n_sads++) {
pci_read_config_dword(pvt->pci_sad0, pvt->info.dram_rule[n_sads],
&reg);
if (!DRAM_RULE_ENABLE(reg))
continue;
limit = SAD_LIMIT(reg);
if (limit <= prv) {
sprintf(msg, "Can't discover the memory socket");
return -EINVAL;
}
if (addr <= limit)
break;
prv = limit;
}
if (n_sads == pvt->info.max_sad) {
sprintf(msg, "Can't discover the memory socket");
return -EINVAL;
}
*area_type = get_dram_attr(reg);
interleave_mode = INTERLEAVE_MODE(reg);
pci_read_config_dword(pvt->pci_sad0, pvt->info.interleave_list[n_sads],
&reg);
if (pvt->info.type == SANDY_BRIDGE) {
sad_interl = sad_pkg(pvt->info.interleave_pkg, reg, 0);
for (sad_way = 0; sad_way < 8; sad_way++) {
u32 pkg = sad_pkg(pvt->info.interleave_pkg, reg, sad_way);
if (sad_way > 0 && sad_interl == pkg)
break;
sad_interleave[sad_way] = pkg;
edac_dbg(0, "SAD interleave #%d: %d\n",
sad_way, sad_interleave[sad_way]);
}
edac_dbg(0, "mc#%d: Error detected on SAD#%d: address 0x%016Lx < 0x%016Lx, Interleave [%d:6]%s\n",
pvt->sbridge_dev->mc,
n_sads,
addr,
limit,
sad_way + 7,
!interleave_mode ? "" : "XOR[18:16]");
if (interleave_mode)
idx = ((addr >> 6) ^ (addr >> 16)) & 7;
else
idx = (addr >> 6) & 7;
switch (sad_way) {
case 1:
idx = 0;
break;
case 2:
idx = idx & 1;
break;
case 4:
idx = idx & 3;
break;
case 8:
break;
default:
sprintf(msg, "Can't discover socket interleave");
return -EINVAL;
}
*socket = sad_interleave[idx];
edac_dbg(0, "SAD interleave index: %d (wayness %d) = CPU socket %d\n",
idx, sad_way, *socket);
} else {
idx = (addr >> 6) & 7;
pkg = sad_pkg(pvt->info.interleave_pkg, reg, idx);
*socket = sad_pkg_socket(pkg);
sad_ha = sad_pkg_ha(pkg);
edac_dbg(0, "SAD interleave package: %d = CPU socket %d, HA %d\n",
idx, *socket, sad_ha);
}
new_mci = get_mci_for_node_id(*socket);
if (!new_mci) {
sprintf(msg, "Struct for socket #%u wasn't initialized",
*socket);
return -EINVAL;
}
mci = new_mci;
pvt = mci->pvt_info;
prv = 0;
if (pvt->info.type == SANDY_BRIDGE)
pci_ha = pvt->pci_ha0;
else {
if (sad_ha)
pci_ha = pvt->pci_ha1;
else
pci_ha = pvt->pci_ha0;
}
for (n_tads = 0; n_tads < MAX_TAD; n_tads++) {
pci_read_config_dword(pci_ha, tad_dram_rule[n_tads], &reg);
limit = TAD_LIMIT(reg);
if (limit <= prv) {
sprintf(msg, "Can't discover the memory channel");
return -EINVAL;
}
if (addr <= limit)
break;
prv = limit;
}
if (n_tads == MAX_TAD) {
sprintf(msg, "Can't discover the memory channel");
return -EINVAL;
}
ch_way = TAD_CH(reg) + 1;
sck_way = TAD_SOCK(reg) + 1;
if (ch_way == 3)
idx = addr >> 6;
else
idx = addr >> (6 + sck_way);
idx = idx % ch_way;
switch (idx) {
case 0:
base_ch = TAD_TGT0(reg);
break;
case 1:
base_ch = TAD_TGT1(reg);
break;
case 2:
base_ch = TAD_TGT2(reg);
break;
case 3:
base_ch = TAD_TGT3(reg);
break;
default:
sprintf(msg, "Can't discover the TAD target");
return -EINVAL;
}
*channel_mask = 1 << base_ch;
pci_read_config_dword(pvt->pci_tad[base_ch],
tad_ch_nilv_offset[n_tads],
&tad_offset);
if (pvt->is_mirrored) {
*channel_mask |= 1 << ((base_ch + 2) % 4);
switch(ch_way) {
case 2:
case 4:
sck_xch = 1 << sck_way * (ch_way >> 1);
break;
default:
sprintf(msg, "Invalid mirror set. Can't decode addr");
return -EINVAL;
}
} else
sck_xch = (1 << sck_way) * ch_way;
if (pvt->is_lockstep)
*channel_mask |= 1 << ((base_ch + 1) % 4);
offset = TAD_OFFSET(tad_offset);
edac_dbg(0, "TAD#%d: address 0x%016Lx < 0x%016Lx, socket interleave %d, channel interleave %d (offset 0x%08Lx), index %d, base ch: %d, ch mask: 0x%02lx\n",
n_tads,
addr,
limit,
(u32)TAD_SOCK(reg),
ch_way,
offset,
idx,
base_ch,
*channel_mask);
if (offset > addr) {
sprintf(msg, "Can't calculate ch addr: TAD offset 0x%08Lx is too high for addr 0x%08Lx!",
offset, addr);
return -EINVAL;
}
addr -= offset;
ch_addr = addr & 0x7f;
addr >>= 6;
addr = div_u64(addr, sck_xch);
#if 0
addr = addr / ch_way;
#endif
ch_addr |= addr << 6;
for (n_rir = 0; n_rir < MAX_RIR_RANGES; n_rir++) {
pci_read_config_dword(pvt->pci_tad[base_ch],
rir_way_limit[n_rir],
&reg);
if (!IS_RIR_VALID(reg))
continue;
limit = RIR_LIMIT(reg);
mb = div_u64_rem(limit >> 20, 1000, &kb);
edac_dbg(0, "RIR#%d, limit: %u.%03u GB (0x%016Lx), way: %d\n",
n_rir,
mb, kb,
limit,
1 << RIR_WAY(reg));
if (ch_addr <= limit)
break;
}
if (n_rir == MAX_RIR_RANGES) {
sprintf(msg, "Can't discover the memory rank for ch addr 0x%08Lx",
ch_addr);
return -EINVAL;
}
rir_way = RIR_WAY(reg);
if (pvt->is_close_pg)
idx = (ch_addr >> 6);
else
idx = (ch_addr >> 13);
idx %= 1 << rir_way;
pci_read_config_dword(pvt->pci_tad[base_ch],
rir_offset[n_rir][idx],
&reg);
*rank = RIR_RNK_TGT(reg);
edac_dbg(0, "RIR#%d: channel address 0x%08Lx < 0x%08Lx, RIR interleave %d, index %d\n",
n_rir,
ch_addr,
limit,
rir_way,
idx);
return 0;
}
static void sbridge_put_devices(struct sbridge_dev *sbridge_dev)
{
int i;
edac_dbg(0, "\n");
for (i = 0; i < sbridge_dev->n_devs; i++) {
struct pci_dev *pdev = sbridge_dev->pdev[i];
if (!pdev)
continue;
edac_dbg(0, "Removing dev %02x:%02x.%d\n",
pdev->bus->number,
PCI_SLOT(pdev->devfn), PCI_FUNC(pdev->devfn));
pci_dev_put(pdev);
}
}
static void sbridge_put_all_devices(void)
{
struct sbridge_dev *sbridge_dev, *tmp;
list_for_each_entry_safe(sbridge_dev, tmp, &sbridge_edac_list, list) {
sbridge_put_devices(sbridge_dev);
free_sbridge_dev(sbridge_dev);
}
}
static int sbridge_get_onedevice(struct pci_dev **prev,
u8 *num_mc,
const struct pci_id_table *table,
const unsigned devno)
{
struct sbridge_dev *sbridge_dev;
const struct pci_id_descr *dev_descr = &table->descr[devno];
struct pci_dev *pdev = NULL;
u8 bus = 0;
sbridge_printk(KERN_DEBUG,
"Seeking for: dev %02x.%d PCI ID %04x:%04x\n",
dev_descr->dev, dev_descr->func,
PCI_VENDOR_ID_INTEL, dev_descr->dev_id);
pdev = pci_get_device(PCI_VENDOR_ID_INTEL,
dev_descr->dev_id, *prev);
if (!pdev) {
if (*prev) {
*prev = pdev;
return 0;
}
if (dev_descr->optional)
return 0;
if (devno == 0)
return -ENODEV;
sbridge_printk(KERN_INFO,
"Device not found: dev %02x.%d PCI ID %04x:%04x\n",
dev_descr->dev, dev_descr->func,
PCI_VENDOR_ID_INTEL, dev_descr->dev_id);
return -ENODEV;
}
bus = pdev->bus->number;
sbridge_dev = get_sbridge_dev(bus);
if (!sbridge_dev) {
sbridge_dev = alloc_sbridge_dev(bus, table);
if (!sbridge_dev) {
pci_dev_put(pdev);
return -ENOMEM;
}
(*num_mc)++;
}
if (sbridge_dev->pdev[devno]) {
sbridge_printk(KERN_ERR,
"Duplicated device for "
"dev %02x:%d.%d PCI ID %04x:%04x\n",
bus, dev_descr->dev, dev_descr->func,
PCI_VENDOR_ID_INTEL, dev_descr->dev_id);
pci_dev_put(pdev);
return -ENODEV;
}
sbridge_dev->pdev[devno] = pdev;
if (unlikely(PCI_SLOT(pdev->devfn) != dev_descr->dev ||
PCI_FUNC(pdev->devfn) != dev_descr->func)) {
sbridge_printk(KERN_ERR,
"Device PCI ID %04x:%04x "
"has dev %02x:%d.%d instead of dev %02x:%02x.%d\n",
PCI_VENDOR_ID_INTEL, dev_descr->dev_id,
bus, PCI_SLOT(pdev->devfn), PCI_FUNC(pdev->devfn),
bus, dev_descr->dev, dev_descr->func);
return -ENODEV;
}
if (unlikely(pci_enable_device(pdev) < 0)) {
sbridge_printk(KERN_ERR,
"Couldn't enable "
"dev %02x:%d.%d PCI ID %04x:%04x\n",
bus, dev_descr->dev, dev_descr->func,
PCI_VENDOR_ID_INTEL, dev_descr->dev_id);
return -ENODEV;
}
edac_dbg(0, "Detected dev %02x:%d.%d PCI ID %04x:%04x\n",
bus, dev_descr->dev, dev_descr->func,
PCI_VENDOR_ID_INTEL, dev_descr->dev_id);
pci_dev_get(pdev);
*prev = pdev;
return 0;
}
static int sbridge_get_all_devices(u8 *num_mc,
const struct pci_id_table *table)
{
int i, rc;
struct pci_dev *pdev = NULL;
while (table && table->descr) {
for (i = 0; i < table->n_devs; i++) {
pdev = NULL;
do {
rc = sbridge_get_onedevice(&pdev, num_mc,
table, i);
if (rc < 0) {
if (i == 0) {
i = table->n_devs;
break;
}
sbridge_put_all_devices();
return -ENODEV;
}
} while (pdev);
}
table++;
}
return 0;
}
static int sbridge_mci_bind_devs(struct mem_ctl_info *mci,
struct sbridge_dev *sbridge_dev)
{
struct sbridge_pvt *pvt = mci->pvt_info;
struct pci_dev *pdev;
int i, func, slot;
for (i = 0; i < sbridge_dev->n_devs; i++) {
pdev = sbridge_dev->pdev[i];
if (!pdev)
continue;
slot = PCI_SLOT(pdev->devfn);
func = PCI_FUNC(pdev->devfn);
switch (slot) {
case 12:
switch (func) {
case 6:
pvt->pci_sad0 = pdev;
break;
case 7:
pvt->pci_sad1 = pdev;
break;
default:
goto error;
}
break;
case 13:
switch (func) {
case 6:
pvt->pci_br0 = pdev;
break;
default:
goto error;
}
break;
case 14:
switch (func) {
case 0:
pvt->pci_ha0 = pdev;
break;
default:
goto error;
}
break;
case 15:
switch (func) {
case 0:
pvt->pci_ta = pdev;
break;
case 1:
pvt->pci_ras = pdev;
break;
case 2:
case 3:
case 4:
case 5:
pvt->pci_tad[func - 2] = pdev;
break;
default:
goto error;
}
break;
case 17:
switch (func) {
case 0:
pvt->pci_ddrio = pdev;
break;
default:
goto error;
}
break;
default:
goto error;
}
edac_dbg(0, "Associated PCI %02x.%02d.%d with dev = %p\n",
sbridge_dev->bus,
PCI_SLOT(pdev->devfn), PCI_FUNC(pdev->devfn),
pdev);
}
if (!pvt->pci_sad0 || !pvt->pci_sad1 || !pvt->pci_ha0 ||
!pvt-> pci_tad || !pvt->pci_ras || !pvt->pci_ta)
goto enodev;
for (i = 0; i < NUM_CHANNELS; i++) {
if (!pvt->pci_tad[i])
goto enodev;
}
return 0;
enodev:
sbridge_printk(KERN_ERR, "Some needed devices are missing\n");
return -ENODEV;
error:
sbridge_printk(KERN_ERR, "Device %d, function %d "
"is out of the expected range\n",
slot, func);
return -EINVAL;
}
static int ibridge_mci_bind_devs(struct mem_ctl_info *mci,
struct sbridge_dev *sbridge_dev)
{
struct sbridge_pvt *pvt = mci->pvt_info;
struct pci_dev *pdev, *tmp;
int i, func, slot;
bool mode_2ha = false;
tmp = pci_get_device(PCI_VENDOR_ID_INTEL,
PCI_DEVICE_ID_INTEL_IBRIDGE_IMC_HA1, NULL);
if (tmp) {
mode_2ha = true;
pci_dev_put(tmp);
}
for (i = 0; i < sbridge_dev->n_devs; i++) {
pdev = sbridge_dev->pdev[i];
if (!pdev)
continue;
slot = PCI_SLOT(pdev->devfn);
func = PCI_FUNC(pdev->devfn);
switch (slot) {
case 14:
if (func == 0) {
pvt->pci_ha0 = pdev;
break;
}
goto error;
case 15:
switch (func) {
case 0:
pvt->pci_ta = pdev;
break;
case 1:
pvt->pci_ras = pdev;
break;
case 4:
case 5:
if (mode_2ha)
break;
case 2:
case 3:
pvt->pci_tad[func - 2] = pdev;
break;
default:
goto error;
}
break;
case 17:
if (func == 4) {
pvt->pci_ddrio = pdev;
break;
} else if (func == 0) {
if (!mode_2ha)
pvt->pci_ddrio = pdev;
break;
}
goto error;
case 22:
switch (func) {
case 0:
pvt->pci_sad0 = pdev;
break;
case 1:
pvt->pci_br0 = pdev;
break;
case 2:
pvt->pci_br1 = pdev;
break;
default:
goto error;
}
break;
case 28:
if (func == 0) {
pvt->pci_ha1 = pdev;
break;
}
goto error;
case 29:
WARN_ON(!mode_2ha);
if (func == 2 || func == 3) {
pvt->pci_tad[func] = pdev;
break;
}
goto error;
default:
goto error;
}
edac_dbg(0, "Associated PCI %02x.%02d.%d with dev = %p\n",
sbridge_dev->bus,
PCI_SLOT(pdev->devfn), PCI_FUNC(pdev->devfn),
pdev);
}
if (!pvt->pci_sad0 || !pvt->pci_ha0 || !pvt->pci_br0 ||
!pvt->pci_br1 || !pvt->pci_tad || !pvt->pci_ras ||
!pvt->pci_ta)
goto enodev;
for (i = 0; i < NUM_CHANNELS; i++) {
if (!pvt->pci_tad[i])
goto enodev;
}
return 0;
enodev:
sbridge_printk(KERN_ERR, "Some needed devices are missing\n");
return -ENODEV;
error:
sbridge_printk(KERN_ERR,
"Device %d, function %d is out of the expected range\n",
slot, func);
return -EINVAL;
}
static void sbridge_mce_output_error(struct mem_ctl_info *mci,
const struct mce *m)
{
struct mem_ctl_info *new_mci;
struct sbridge_pvt *pvt = mci->pvt_info;
enum hw_event_mc_err_type tp_event;
char *type, *optype, msg[256];
bool ripv = GET_BITFIELD(m->mcgstatus, 0, 0);
bool overflow = GET_BITFIELD(m->status, 62, 62);
bool uncorrected_error = GET_BITFIELD(m->status, 61, 61);
bool recoverable;
u32 core_err_cnt = GET_BITFIELD(m->status, 38, 52);
u32 mscod = GET_BITFIELD(m->status, 16, 31);
u32 errcode = GET_BITFIELD(m->status, 0, 15);
u32 channel = GET_BITFIELD(m->status, 0, 3);
u32 optypenum = GET_BITFIELD(m->status, 4, 6);
long channel_mask, first_channel;
u8 rank, socket;
int rc, dimm;
char *area_type = NULL;
if (pvt->info.type == IVY_BRIDGE)
recoverable = true;
else
recoverable = GET_BITFIELD(m->status, 56, 56);
if (uncorrected_error) {
if (ripv) {
type = "FATAL";
tp_event = HW_EVENT_ERR_FATAL;
} else {
type = "NON_FATAL";
tp_event = HW_EVENT_ERR_UNCORRECTED;
}
} else {
type = "CORRECTED";
tp_event = HW_EVENT_ERR_CORRECTED;
}
if (! ((errcode & 0xef80) == 0x80)) {
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
if (!GET_BITFIELD(m->status, 58, 58))
return;
rc = get_memory_error_data(mci, m->addr, &socket,
&channel_mask, &rank, &area_type, msg);
if (rc < 0)
goto err_parsing;
new_mci = get_mci_for_node_id(socket);
if (!new_mci) {
strcpy(msg, "Error: socket got corrupted!");
goto err_parsing;
}
mci = new_mci;
pvt = mci->pvt_info;
first_channel = find_first_bit(&channel_mask, NUM_CHANNELS);
if (rank < 4)
dimm = 0;
else if (rank < 8)
dimm = 1;
else
dimm = 2;
snprintf(msg, sizeof(msg),
"%s%s area:%s err_code:%04x:%04x socket:%d channel_mask:%ld rank:%d",
overflow ? " OVERFLOW" : "",
(uncorrected_error && recoverable) ? " recoverable" : "",
area_type,
mscod, errcode,
socket,
channel_mask,
rank);
edac_dbg(0, "%s\n", msg);
edac_mc_handle_error(tp_event, mci, core_err_cnt,
m->addr >> PAGE_SHIFT, m->addr & ~PAGE_MASK, 0,
channel, dimm, -1,
optype, msg);
return;
err_parsing:
edac_mc_handle_error(tp_event, mci, core_err_cnt, 0, 0, 0,
-1, -1, -1,
msg, "");
}
static void sbridge_check_error(struct mem_ctl_info *mci)
{
struct sbridge_pvt *pvt = mci->pvt_info;
int i;
unsigned count = 0;
struct mce *m;
smp_rmb();
count = (pvt->mce_out + MCE_LOG_LEN - pvt->mce_in)
% MCE_LOG_LEN;
if (!count)
return;
m = pvt->mce_outentry;
if (pvt->mce_in + count > MCE_LOG_LEN) {
unsigned l = MCE_LOG_LEN - pvt->mce_in;
memcpy(m, &pvt->mce_entry[pvt->mce_in], sizeof(*m) * l);
smp_wmb();
pvt->mce_in = 0;
count -= l;
m += l;
}
memcpy(m, &pvt->mce_entry[pvt->mce_in], sizeof(*m) * count);
smp_wmb();
pvt->mce_in += count;
smp_rmb();
if (pvt->mce_overrun) {
sbridge_printk(KERN_ERR, "Lost %d memory errors\n",
pvt->mce_overrun);
smp_wmb();
pvt->mce_overrun = 0;
}
for (i = 0; i < count; i++)
sbridge_mce_output_error(mci, &pvt->mce_outentry[i]);
}
static int sbridge_mce_check_error(struct notifier_block *nb, unsigned long val,
void *data)
{
struct mce *mce = (struct mce *)data;
struct mem_ctl_info *mci;
struct sbridge_pvt *pvt;
char *type;
if (get_edac_report_status() == EDAC_REPORTING_DISABLED)
return NOTIFY_DONE;
mci = get_mci_for_node_id(mce->socketid);
if (!mci)
return NOTIFY_BAD;
pvt = mci->pvt_info;
if ((mce->status & 0xefff) >> 7 != 1)
return NOTIFY_DONE;
if (mce->mcgstatus & MCG_STATUS_MCIP)
type = "Exception";
else
type = "Event";
sbridge_mc_printk(mci, KERN_DEBUG, "HANDLING MCE MEMORY ERROR\n");
sbridge_mc_printk(mci, KERN_DEBUG, "CPU %d: Machine Check %s: %Lx "
"Bank %d: %016Lx\n", mce->extcpu, type,
mce->mcgstatus, mce->bank, mce->status);
sbridge_mc_printk(mci, KERN_DEBUG, "TSC %llx ", mce->tsc);
sbridge_mc_printk(mci, KERN_DEBUG, "ADDR %llx ", mce->addr);
sbridge_mc_printk(mci, KERN_DEBUG, "MISC %llx ", mce->misc);
sbridge_mc_printk(mci, KERN_DEBUG, "PROCESSOR %u:%x TIME %llu SOCKET "
"%u APIC %x\n", mce->cpuvendor, mce->cpuid,
mce->time, mce->socketid, mce->apicid);
if (cpu_data(mce->cpu).phys_proc_id != pvt->sbridge_dev->mc)
return NOTIFY_DONE;
smp_rmb();
if ((pvt->mce_out + 1) % MCE_LOG_LEN == pvt->mce_in) {
smp_wmb();
pvt->mce_overrun++;
return NOTIFY_DONE;
}
memcpy(&pvt->mce_entry[pvt->mce_out], mce, sizeof(*mce));
smp_wmb();
pvt->mce_out = (pvt->mce_out + 1) % MCE_LOG_LEN;
if (mce->mcgstatus & 1)
sbridge_check_error(mci);
return NOTIFY_STOP;
}
static void sbridge_unregister_mci(struct sbridge_dev *sbridge_dev)
{
struct mem_ctl_info *mci = sbridge_dev->mci;
struct sbridge_pvt *pvt;
if (unlikely(!mci || !mci->pvt_info)) {
edac_dbg(0, "MC: dev = %p\n", &sbridge_dev->pdev[0]->dev);
sbridge_printk(KERN_ERR, "Couldn't find mci handler\n");
return;
}
pvt = mci->pvt_info;
edac_dbg(0, "MC: mci = %p, dev = %p\n",
mci, &sbridge_dev->pdev[0]->dev);
edac_mc_del_mc(mci->pdev);
edac_dbg(1, "%s: free mci struct\n", mci->ctl_name);
kfree(mci->ctl_name);
edac_mc_free(mci);
sbridge_dev->mci = NULL;
}
static int sbridge_register_mci(struct sbridge_dev *sbridge_dev, enum type type)
{
struct mem_ctl_info *mci;
struct edac_mc_layer layers[2];
struct sbridge_pvt *pvt;
struct pci_dev *pdev = sbridge_dev->pdev[0];
int rc;
rc = check_if_ecc_is_active(sbridge_dev->bus);
if (unlikely(rc < 0))
return rc;
layers[0].type = EDAC_MC_LAYER_CHANNEL;
layers[0].size = NUM_CHANNELS;
layers[0].is_virt_csrow = false;
layers[1].type = EDAC_MC_LAYER_SLOT;
layers[1].size = MAX_DIMMS;
layers[1].is_virt_csrow = true;
mci = edac_mc_alloc(sbridge_dev->mc, ARRAY_SIZE(layers), layers,
sizeof(*pvt));
if (unlikely(!mci))
return -ENOMEM;
edac_dbg(0, "MC: mci = %p, dev = %p\n",
mci, &pdev->dev);
pvt = mci->pvt_info;
memset(pvt, 0, sizeof(*pvt));
pvt->sbridge_dev = sbridge_dev;
sbridge_dev->mci = mci;
mci->mtype_cap = MEM_FLAG_DDR3;
mci->edac_ctl_cap = EDAC_FLAG_NONE;
mci->edac_cap = EDAC_FLAG_NONE;
mci->mod_name = "sbridge_edac.c";
mci->mod_ver = SBRIDGE_REVISION;
mci->dev_name = pci_name(pdev);
mci->ctl_page_to_phys = NULL;
mci->edac_check = sbridge_check_error;
pvt->info.type = type;
if (type == IVY_BRIDGE) {
pvt->info.rankcfgr = IB_RANK_CFG_A;
pvt->info.get_tolm = ibridge_get_tolm;
pvt->info.get_tohm = ibridge_get_tohm;
pvt->info.dram_rule = ibridge_dram_rule;
pvt->info.max_sad = ARRAY_SIZE(ibridge_dram_rule);
pvt->info.interleave_list = ibridge_interleave_list;
pvt->info.max_interleave = ARRAY_SIZE(ibridge_interleave_list);
pvt->info.interleave_pkg = ibridge_interleave_pkg;
mci->ctl_name = kasprintf(GFP_KERNEL, "Ivy Bridge Socket#%d", mci->mc_idx);
rc = ibridge_mci_bind_devs(mci, sbridge_dev);
if (unlikely(rc < 0))
goto fail0;
} else {
pvt->info.rankcfgr = SB_RANK_CFG_A;
pvt->info.get_tolm = sbridge_get_tolm;
pvt->info.get_tohm = sbridge_get_tohm;
pvt->info.dram_rule = sbridge_dram_rule;
pvt->info.max_sad = ARRAY_SIZE(sbridge_dram_rule);
pvt->info.interleave_list = sbridge_interleave_list;
pvt->info.max_interleave = ARRAY_SIZE(sbridge_interleave_list);
pvt->info.interleave_pkg = sbridge_interleave_pkg;
mci->ctl_name = kasprintf(GFP_KERNEL, "Sandy Bridge Socket#%d", mci->mc_idx);
rc = sbridge_mci_bind_devs(mci, sbridge_dev);
if (unlikely(rc < 0))
goto fail0;
}
get_dimm_config(mci);
get_memory_layout(mci);
mci->pdev = &pdev->dev;
if (unlikely(edac_mc_add_mc(mci))) {
edac_dbg(0, "MC: failed edac_mc_add_mc()\n");
rc = -EINVAL;
goto fail0;
}
return 0;
fail0:
kfree(mci->ctl_name);
edac_mc_free(mci);
sbridge_dev->mci = NULL;
return rc;
}
static int sbridge_probe(struct pci_dev *pdev, const struct pci_device_id *id)
{
int rc;
u8 mc, num_mc = 0;
struct sbridge_dev *sbridge_dev;
enum type type;
mutex_lock(&sbridge_edac_lock);
if (unlikely(probed >= 1)) {
mutex_unlock(&sbridge_edac_lock);
return -ENODEV;
}
probed++;
if (pdev->device == PCI_DEVICE_ID_INTEL_IBRIDGE_IMC_HA0_TA) {
rc = sbridge_get_all_devices(&num_mc, pci_dev_descr_ibridge_table);
type = IVY_BRIDGE;
} else {
rc = sbridge_get_all_devices(&num_mc, pci_dev_descr_sbridge_table);
type = SANDY_BRIDGE;
}
if (unlikely(rc < 0))
goto fail0;
mc = 0;
list_for_each_entry(sbridge_dev, &sbridge_edac_list, list) {
edac_dbg(0, "Registering MC#%d (%d of %d)\n",
mc, mc + 1, num_mc);
sbridge_dev->mc = mc++;
rc = sbridge_register_mci(sbridge_dev, type);
if (unlikely(rc < 0))
goto fail1;
}
sbridge_printk(KERN_INFO, "Driver loaded.\n");
mutex_unlock(&sbridge_edac_lock);
return 0;
fail1:
list_for_each_entry(sbridge_dev, &sbridge_edac_list, list)
sbridge_unregister_mci(sbridge_dev);
sbridge_put_all_devices();
fail0:
mutex_unlock(&sbridge_edac_lock);
return rc;
}
static void sbridge_remove(struct pci_dev *pdev)
{
struct sbridge_dev *sbridge_dev;
edac_dbg(0, "\n");
mutex_lock(&sbridge_edac_lock);
if (unlikely(!probed)) {
mutex_unlock(&sbridge_edac_lock);
return;
}
list_for_each_entry(sbridge_dev, &sbridge_edac_list, list)
sbridge_unregister_mci(sbridge_dev);
sbridge_put_all_devices();
probed--;
mutex_unlock(&sbridge_edac_lock);
}
static int __init sbridge_init(void)
{
int pci_rc;
edac_dbg(2, "\n");
opstate_init();
pci_rc = pci_register_driver(&sbridge_driver);
if (pci_rc >= 0) {
mce_register_decode_chain(&sbridge_mce_dec);
if (get_edac_report_status() == EDAC_REPORTING_DISABLED)
sbridge_printk(KERN_WARNING, "Loading driver, error reporting disabled.\n");
return 0;
}
sbridge_printk(KERN_ERR, "Failed to register device with error %d.\n",
pci_rc);
return pci_rc;
}
static void __exit sbridge_exit(void)
{
edac_dbg(2, "\n");
pci_unregister_driver(&sbridge_driver);
mce_unregister_decode_chain(&sbridge_mce_dec);
}
