static char *show_dram_attr(u32 attr)
{
switch (attr) {
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
static inline int numrank(enum type type, u32 mtr)
{
int ranks = (1 << RANK_CNT_BITS(mtr));
int max = 4;
if (type == HASWELL || type == BROADWELL || type == KNIGHTS_LANDING)
max = 8;
if (ranks > max) {
edac_dbg(0, "Invalid number of ranks: %d (max = %i) raw value = %x (%04x)\n",
ranks, max, (unsigned int)RANK_CNT_BITS(mtr), mtr);
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
static struct sbridge_dev *get_sbridge_dev(u8 bus, int multi_bus)
{
struct sbridge_dev *sbridge_dev;
if (multi_bus) {
return list_first_entry_or_null(&sbridge_edac_list,
struct sbridge_dev, list);
}
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
static u64 rir_limit(u32 reg)
{
return ((u64)GET_BITFIELD(reg, 1, 10) << 29) | 0x1fffffff;
}
static u64 sad_limit(u32 reg)
{
return (GET_BITFIELD(reg, 6, 25) << 26) | 0x3ffffff;
}
static u32 interleave_mode(u32 reg)
{
return GET_BITFIELD(reg, 1, 1);
}
static u32 dram_attr(u32 reg)
{
return GET_BITFIELD(reg, 2, 3);
}
static u64 knl_sad_limit(u32 reg)
{
return (GET_BITFIELD(reg, 7, 26) << 26) | 0x3ffffff;
}
static u32 knl_interleave_mode(u32 reg)
{
return GET_BITFIELD(reg, 1, 2);
}
static const char *get_intlv_mode_str(u32 reg, enum type t)
{
if (t == KNIGHTS_LANDING)
return knl_intlv_mode[knl_interleave_mode(reg)];
else
return interleave_mode(reg) ? "[8:6]" : "[8:6]XOR[18:16]";
}
static u32 dram_attr_knl(u32 reg)
{
return GET_BITFIELD(reg, 3, 4);
}
static enum mem_type get_memory_type(struct sbridge_pvt *pvt)
{
u32 reg;
enum mem_type mtype;
if (pvt->pci_ddrio) {
pci_read_config_dword(pvt->pci_ddrio, pvt->info.rankcfgr,
&reg);
if (GET_BITFIELD(reg, 11, 11))
mtype = MEM_RDDR3;
else
mtype = MEM_DDR3;
} else
mtype = MEM_UNKNOWN;
return mtype;
}
static enum mem_type haswell_get_memory_type(struct sbridge_pvt *pvt)
{
u32 reg;
bool registered = false;
enum mem_type mtype = MEM_UNKNOWN;
if (!pvt->pci_ddrio)
goto out;
pci_read_config_dword(pvt->pci_ddrio,
HASWELL_DDRCRCLKCONTROLS, &reg);
if (GET_BITFIELD(reg, 16, 16))
registered = true;
pci_read_config_dword(pvt->pci_ta, MCMTR, &reg);
if (GET_BITFIELD(reg, 14, 14)) {
if (registered)
mtype = MEM_RDDR4;
else
mtype = MEM_DDR4;
} else {
if (registered)
mtype = MEM_RDDR3;
else
mtype = MEM_DDR3;
}
out:
return mtype;
}
static enum dev_type knl_get_width(struct sbridge_pvt *pvt, u32 mtr)
{
return DEV_X16;
}
static enum dev_type sbridge_get_width(struct sbridge_pvt *pvt, u32 mtr)
{
return DEV_UNKNOWN;
}
static enum dev_type __ibridge_get_width(u32 mtr)
{
enum dev_type type;
switch (mtr) {
case 3:
type = DEV_UNKNOWN;
break;
case 2:
type = DEV_X16;
break;
case 1:
type = DEV_X8;
break;
case 0:
type = DEV_X4;
break;
}
return type;
}
static enum dev_type ibridge_get_width(struct sbridge_pvt *pvt, u32 mtr)
{
return __ibridge_get_width(GET_BITFIELD(mtr, 7, 8));
}
static enum dev_type broadwell_get_width(struct sbridge_pvt *pvt, u32 mtr)
{
return __ibridge_get_width(GET_BITFIELD(mtr, 8, 9));
}
static enum mem_type knl_get_memory_type(struct sbridge_pvt *pvt)
{
return MEM_RDDR4;
}
static u8 get_node_id(struct sbridge_pvt *pvt)
{
u32 reg;
pci_read_config_dword(pvt->pci_br0, SAD_CONTROL, &reg);
return GET_BITFIELD(reg, 0, 2);
}
static u8 haswell_get_node_id(struct sbridge_pvt *pvt)
{
u32 reg;
pci_read_config_dword(pvt->pci_sad1, SAD_CONTROL, &reg);
return GET_BITFIELD(reg, 0, 3);
}
static u8 knl_get_node_id(struct sbridge_pvt *pvt)
{
u32 reg;
pci_read_config_dword(pvt->pci_sad1, SAD_CONTROL, &reg);
return GET_BITFIELD(reg, 0, 2);
}
static u64 haswell_get_tolm(struct sbridge_pvt *pvt)
{
u32 reg;
pci_read_config_dword(pvt->info.pci_vtd, HASWELL_TOLM, &reg);
return (GET_BITFIELD(reg, 26, 31) << 26) | 0x3ffffff;
}
static u64 haswell_get_tohm(struct sbridge_pvt *pvt)
{
u64 rc;
u32 reg;
pci_read_config_dword(pvt->info.pci_vtd, HASWELL_TOHM_0, &reg);
rc = GET_BITFIELD(reg, 26, 31);
pci_read_config_dword(pvt->info.pci_vtd, HASWELL_TOHM_1, &reg);
rc = ((reg << 6) | rc) << 26;
return rc | 0x1ffffff;
}
static u64 knl_get_tolm(struct sbridge_pvt *pvt)
{
u32 reg;
pci_read_config_dword(pvt->knl.pci_mc_info, KNL_TOLM, &reg);
return (GET_BITFIELD(reg, 26, 31) << 26) | 0x3ffffff;
}
static u64 knl_get_tohm(struct sbridge_pvt *pvt)
{
u64 rc;
u32 reg_lo, reg_hi;
pci_read_config_dword(pvt->knl.pci_mc_info, KNL_TOHM_0, &reg_lo);
pci_read_config_dword(pvt->knl.pci_mc_info, KNL_TOHM_1, &reg_hi);
rc = ((u64)reg_hi << 32) | reg_lo;
return rc | 0x3ffffff;
}
static u64 haswell_rir_limit(u32 reg)
{
return (((u64)GET_BITFIELD(reg, 1, 11) + 1) << 29) - 1;
}
static inline u8 sad_pkg_socket(u8 pkg)
{
return ((pkg >> 3) << 2) | (pkg & 0x3);
}
static inline u8 sad_pkg_ha(u8 pkg)
{
return (pkg >> 2) & 0x1;
}
static int haswell_chan_hash(int idx, u64 addr)
{
int i;
for (i = 12; i < 28; i += 2)
idx ^= (addr >> i) & 3;
return idx;
}
static struct pci_dev *get_pdev_same_bus(u8 bus, u32 id)
{
struct pci_dev *pdev = NULL;
do {
pdev = pci_get_device(PCI_VENDOR_ID_INTEL, id, pdev);
if (pdev && pdev->bus->number == bus)
break;
} while (pdev);
return pdev;
}
static int check_if_ecc_is_active(const u8 bus, enum type type)
{
struct pci_dev *pdev = NULL;
u32 mcmtr, id;
switch (type) {
case IVY_BRIDGE:
id = PCI_DEVICE_ID_INTEL_IBRIDGE_IMC_HA0_TA;
break;
case HASWELL:
id = PCI_DEVICE_ID_INTEL_HASWELL_IMC_HA0_TA;
break;
case SANDY_BRIDGE:
id = PCI_DEVICE_ID_INTEL_SBRIDGE_IMC_TA;
break;
case BROADWELL:
id = PCI_DEVICE_ID_INTEL_BROADWELL_IMC_HA0_TA;
break;
case KNIGHTS_LANDING:
id = PCI_DEVICE_ID_INTEL_KNL_IMC_TA;
break;
default:
return -ENODEV;
}
if (type != KNIGHTS_LANDING)
pdev = get_pdev_same_bus(bus, id);
else
pdev = pci_get_device(PCI_VENDOR_ID_INTEL, id, 0);
if (!pdev) {
sbridge_printk(KERN_ERR, "Couldn't find PCI device "
"%04x:%04x! on bus %02d\n",
PCI_VENDOR_ID_INTEL, id, bus);
return -ENODEV;
}
pci_read_config_dword(pdev,
type == KNIGHTS_LANDING ? KNL_MCMTR : MCMTR, &mcmtr);
if (!IS_ECC_ENABLED(mcmtr)) {
sbridge_printk(KERN_ERR, "ECC is disabled. Aborting\n");
return -ENODEV;
}
return 0;
}
static int knl_get_tad(const struct sbridge_pvt *pvt,
const int entry,
const int mc,
u64 *offset,
u64 *limit,
int *ways)
{
u32 reg_limit_lo, reg_offset_lo, reg_hi;
struct pci_dev *pci_mc;
int way_id;
switch (mc) {
case 0:
pci_mc = pvt->knl.pci_mc0;
break;
case 1:
pci_mc = pvt->knl.pci_mc1;
break;
default:
WARN_ON(1);
return -EINVAL;
}
pci_read_config_dword(pci_mc,
knl_tad_dram_limit_lo[entry], &reg_limit_lo);
pci_read_config_dword(pci_mc,
knl_tad_dram_offset_lo[entry], &reg_offset_lo);
pci_read_config_dword(pci_mc,
knl_tad_dram_hi[entry], &reg_hi);
if (!GET_BITFIELD(reg_limit_lo, 0, 0))
return -ENODEV;
way_id = GET_BITFIELD(reg_limit_lo, 3, 5);
if (way_id < ARRAY_SIZE(knl_tad_ways)) {
*ways = knl_tad_ways[way_id];
} else {
*ways = 0;
sbridge_printk(KERN_ERR,
"Unexpected value %d in mc_tad_limit_lo wayness field\n",
way_id);
return -ENODEV;
}
*offset = ((u64) GET_BITFIELD(reg_offset_lo, 6, 31) << 6) |
((u64) GET_BITFIELD(reg_hi, 0, 15) << 32);
*limit = ((u64) GET_BITFIELD(reg_limit_lo, 6, 31) << 6) | 63 |
((u64) GET_BITFIELD(reg_hi, 16, 31) << 32);
return 0;
}
static int knl_channel_mc(int channel)
{
WARN_ON(channel < 0 || channel >= 6);
return channel < 3 ? 1 : 0;
}
static u32 knl_get_edc_route(int entry, u32 reg)
{
WARN_ON(entry >= KNL_MAX_EDCS);
return GET_BITFIELD(reg, entry*3, (entry*3)+2);
}
static u32 knl_get_mc_route(int entry, u32 reg)
{
int mc, chan;
WARN_ON(entry >= KNL_MAX_CHANNELS);
mc = GET_BITFIELD(reg, entry*3, (entry*3)+2);
chan = GET_BITFIELD(reg, (entry*2) + 18, (entry*2) + 18 + 1);
return knl_channel_remap(mc, chan);
}
static void knl_show_edc_route(u32 reg, char *s)
{
int i;
for (i = 0; i < KNL_MAX_EDCS; i++) {
s[i*2] = knl_get_edc_route(i, reg) + '0';
s[i*2+1] = '-';
}
s[KNL_MAX_EDCS*2 - 1] = '\0';
}
static void knl_show_mc_route(u32 reg, char *s)
{
int i;
for (i = 0; i < KNL_MAX_CHANNELS; i++) {
s[i*2] = knl_get_mc_route(i, reg) + '0';
s[i*2+1] = '-';
}
s[KNL_MAX_CHANNELS*2 - 1] = '\0';
}
static int knl_get_dimm_capacity(struct sbridge_pvt *pvt, u64 *mc_sizes)
{
u64 sad_base, sad_size, sad_limit = 0;
u64 tad_base, tad_size, tad_limit, tad_deadspace, tad_livespace;
int sad_rule = 0;
int tad_rule = 0;
int intrlv_ways, tad_ways;
u32 first_pkg, pkg;
int i;
u64 sad_actual_size[2];
u32 dram_rule, interleave_reg;
u32 mc_route_reg[KNL_MAX_CHAS];
u32 edc_route_reg[KNL_MAX_CHAS];
int edram_only;
char edc_route_string[KNL_MAX_EDCS*2];
char mc_route_string[KNL_MAX_CHANNELS*2];
int cur_reg_start;
int mc;
int channel;
int way;
int participants[KNL_MAX_CHANNELS];
int participant_count = 0;
for (i = 0; i < KNL_MAX_CHANNELS; i++)
mc_sizes[i] = 0;
cur_reg_start = 0;
for (i = 0; i < KNL_MAX_CHAS; i++) {
pci_read_config_dword(pvt->knl.pci_cha[i],
KNL_EDC_ROUTE, &edc_route_reg[i]);
if (i > 0 && edc_route_reg[i] != edc_route_reg[i-1]) {
knl_show_edc_route(edc_route_reg[i-1],
edc_route_string);
if (cur_reg_start == i-1)
edac_dbg(0, "edc route table for CHA %d: %s\n",
cur_reg_start, edc_route_string);
else
edac_dbg(0, "edc route table for CHA %d-%d: %s\n",
cur_reg_start, i-1, edc_route_string);
cur_reg_start = i;
}
}
knl_show_edc_route(edc_route_reg[i-1], edc_route_string);
if (cur_reg_start == i-1)
edac_dbg(0, "edc route table for CHA %d: %s\n",
cur_reg_start, edc_route_string);
else
edac_dbg(0, "edc route table for CHA %d-%d: %s\n",
cur_reg_start, i-1, edc_route_string);
cur_reg_start = 0;
for (i = 0; i < KNL_MAX_CHAS; i++) {
pci_read_config_dword(pvt->knl.pci_cha[i],
KNL_MC_ROUTE, &mc_route_reg[i]);
if (i > 0 && mc_route_reg[i] != mc_route_reg[i-1]) {
knl_show_mc_route(mc_route_reg[i-1], mc_route_string);
if (cur_reg_start == i-1)
edac_dbg(0, "mc route table for CHA %d: %s\n",
cur_reg_start, mc_route_string);
else
edac_dbg(0, "mc route table for CHA %d-%d: %s\n",
cur_reg_start, i-1, mc_route_string);
cur_reg_start = i;
}
}
knl_show_mc_route(mc_route_reg[i-1], mc_route_string);
if (cur_reg_start == i-1)
edac_dbg(0, "mc route table for CHA %d: %s\n",
cur_reg_start, mc_route_string);
else
edac_dbg(0, "mc route table for CHA %d-%d: %s\n",
cur_reg_start, i-1, mc_route_string);
for (sad_rule = 0; sad_rule < pvt->info.max_sad; sad_rule++) {
sad_base = sad_limit;
pci_read_config_dword(pvt->pci_sad0,
pvt->info.dram_rule[sad_rule], &dram_rule);
if (!DRAM_RULE_ENABLE(dram_rule))
break;
edram_only = KNL_EDRAM_ONLY(dram_rule);
sad_limit = pvt->info.sad_limit(dram_rule)+1;
sad_size = sad_limit - sad_base;
pci_read_config_dword(pvt->pci_sad0,
pvt->info.interleave_list[sad_rule], &interleave_reg);
first_pkg = sad_pkg(pvt->info.interleave_pkg,
interleave_reg, 0);
for (intrlv_ways = 1; intrlv_ways < 8; intrlv_ways++) {
pkg = sad_pkg(pvt->info.interleave_pkg,
interleave_reg, intrlv_ways);
if ((pkg & 0x8) == 0) {
edac_dbg(0, "Unexpected interleave target %d\n",
pkg);
return -1;
}
if (pkg == first_pkg)
break;
}
if (KNL_MOD3(dram_rule))
intrlv_ways *= 3;
edac_dbg(3, "dram rule %d (base 0x%llx, limit 0x%llx), %d way interleave%s\n",
sad_rule,
sad_base,
sad_limit,
intrlv_ways,
edram_only ? ", EDRAM" : "");
for (mc = 0; mc < 2; mc++) {
sad_actual_size[mc] = 0;
tad_livespace = 0;
for (tad_rule = 0;
tad_rule < ARRAY_SIZE(
knl_tad_dram_limit_lo);
tad_rule++) {
if (knl_get_tad(pvt,
tad_rule,
mc,
&tad_deadspace,
&tad_limit,
&tad_ways))
break;
tad_size = (tad_limit+1) -
(tad_livespace + tad_deadspace);
tad_livespace += tad_size;
tad_base = (tad_limit+1) - tad_size;
if (tad_base < sad_base) {
if (tad_limit > sad_base)
edac_dbg(0, "TAD region overlaps lower SAD boundary -- TAD tables may be configured incorrectly.\n");
} else if (tad_base < sad_limit) {
if (tad_limit+1 > sad_limit) {
edac_dbg(0, "TAD region overlaps upper SAD boundary -- TAD tables may be configured incorrectly.\n");
} else {
edac_dbg(3, "TAD region %d 0x%llx - 0x%llx (%lld bytes) table%d\n",
tad_rule, tad_base,
tad_limit, tad_size,
mc);
sad_actual_size[mc] += tad_size;
}
}
tad_base = tad_limit+1;
}
}
for (mc = 0; mc < 2; mc++) {
edac_dbg(3, " total TAD DRAM footprint in table%d : 0x%llx (%lld bytes)\n",
mc, sad_actual_size[mc], sad_actual_size[mc]);
}
if (edram_only)
continue;
for (channel = 0; channel < KNL_MAX_CHANNELS; channel++)
participants[channel] = 0;
for (channel = 0; channel < KNL_MAX_CHANNELS; channel++) {
for (way = 0; way < intrlv_ways; way++) {
int target;
int cha;
if (KNL_MOD3(dram_rule))
target = way;
else
target = 0x7 & sad_pkg(
pvt->info.interleave_pkg, interleave_reg, way);
for (cha = 0; cha < KNL_MAX_CHAS; cha++) {
if (knl_get_mc_route(target,
mc_route_reg[cha]) == channel
&& !participants[channel]) {
participant_count++;
participants[channel] = 1;
break;
}
}
}
}
if (participant_count != intrlv_ways)
edac_dbg(0, "participant_count (%d) != interleave_ways (%d): DIMM size may be incorrect\n",
participant_count, intrlv_ways);
for (channel = 0; channel < KNL_MAX_CHANNELS; channel++) {
mc = knl_channel_mc(channel);
if (participants[channel]) {
edac_dbg(4, "mc channel %d contributes %lld bytes via sad entry %d\n",
channel,
sad_actual_size[mc]/intrlv_ways,
sad_rule);
mc_sizes[channel] +=
sad_actual_size[mc]/intrlv_ways;
}
}
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
int channels = pvt->info.type == KNIGHTS_LANDING ?
KNL_MAX_CHANNELS : NUM_CHANNELS;
u64 knl_mc_sizes[KNL_MAX_CHANNELS];
if (pvt->info.type == HASWELL || pvt->info.type == BROADWELL) {
pci_read_config_dword(pvt->pci_ha0, HASWELL_HASYSDEFEATURE2, &reg);
pvt->is_chan_hash = GET_BITFIELD(reg, 21, 21);
}
if (pvt->info.type == HASWELL || pvt->info.type == BROADWELL ||
pvt->info.type == KNIGHTS_LANDING)
pci_read_config_dword(pvt->pci_sad1, SAD_TARGET, &reg);
else
pci_read_config_dword(pvt->pci_br0, SAD_TARGET, &reg);
if (pvt->info.type == KNIGHTS_LANDING)
pvt->sbridge_dev->source_id = SOURCE_ID_KNL(reg);
else
pvt->sbridge_dev->source_id = SOURCE_ID(reg);
pvt->sbridge_dev->node_id = pvt->info.get_node_id(pvt);
edac_dbg(0, "mc#%d: Node ID: %d, source ID: %d\n",
pvt->sbridge_dev->mc,
pvt->sbridge_dev->node_id,
pvt->sbridge_dev->source_id);
if (pvt->info.type == KNIGHTS_LANDING) {
mode = EDAC_S4ECD4ED;
pvt->is_mirrored = false;
if (knl_get_dimm_capacity(pvt, knl_mc_sizes) != 0)
return -1;
} else {
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
}
mtype = pvt->info.get_memory_type(pvt);
if (mtype == MEM_RDDR3 || mtype == MEM_RDDR4)
edac_dbg(0, "Memory is registered\n");
else if (mtype == MEM_UNKNOWN)
edac_dbg(0, "Cannot determine memory type\n");
else
edac_dbg(0, "Memory is unregistered\n");
if (mtype == MEM_DDR4 || mtype == MEM_RDDR4)
banks = 16;
else
banks = 8;
for (i = 0; i < channels; i++) {
u32 mtr;
int max_dimms_per_channel;
if (pvt->info.type == KNIGHTS_LANDING) {
max_dimms_per_channel = 1;
if (!pvt->knl.pci_channel[i])
continue;
} else {
max_dimms_per_channel = ARRAY_SIZE(mtr_regs);
if (!pvt->pci_tad[i])
continue;
}
for (j = 0; j < max_dimms_per_channel; j++) {
dimm = EDAC_DIMM_PTR(mci->layers, mci->dimms, mci->n_layers,
i, j, 0);
if (pvt->info.type == KNIGHTS_LANDING) {
pci_read_config_dword(pvt->knl.pci_channel[i],
knl_mtr_reg, &mtr);
} else {
pci_read_config_dword(pvt->pci_tad[i],
mtr_regs[j], &mtr);
}
edac_dbg(4, "Channel #%d MTR%d = %x\n", i, j, mtr);
if (IS_DIMM_PRESENT(mtr)) {
pvt->channel[i].dimms++;
ranks = numrank(pvt->info.type, mtr);
if (pvt->info.type == KNIGHTS_LANDING) {
cols = 1 << 10;
rows = knl_mc_sizes[i] /
((u64) cols * ranks * banks * 8);
} else {
rows = numrow(mtr);
cols = numcol(mtr);
}
size = ((u64)rows * cols * banks * ranks) >> (20 - 3);
npages = MiB_TO_PAGES(size);
edac_dbg(0, "mc#%d: ha %d channel %d, dimm %d, %lld Mb (%d pages) bank: %d, rank: %d, row: %#x, col: %#x\n",
pvt->sbridge_dev->mc, i/4, i%4, j,
size, npages,
banks, ranks, rows, cols);
dimm->nr_pages = npages;
dimm->grain = 32;
dimm->dtype = pvt->info.get_width(pvt, mtr);
dimm->mtype = mtype;
dimm->edac_mode = mode;
snprintf(dimm->label, sizeof(dimm->label),
"CPU_SrcID#%u_Ha#%u_Chan#%u_DIMM#%u",
pvt->sbridge_dev->source_id, i/4, i%4, j);
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
u32 gb, mb;
u32 rir_way;
pvt->tolm = pvt->info.get_tolm(pvt);
tmp_mb = (1 + pvt->tolm) >> 20;
gb = div_u64_rem(tmp_mb, 1024, &mb);
edac_dbg(0, "TOLM: %u.%03u GB (0x%016Lx)\n",
gb, (mb*1000)/1024, (u64)pvt->tolm);
pvt->tohm = pvt->info.get_tohm(pvt);
tmp_mb = (1 + pvt->tohm) >> 20;
gb = div_u64_rem(tmp_mb, 1024, &mb);
edac_dbg(0, "TOHM: %u.%03u GB (0x%016Lx)\n",
gb, (mb*1000)/1024, (u64)pvt->tohm);
prv = 0;
for (n_sads = 0; n_sads < pvt->info.max_sad; n_sads++) {
pci_read_config_dword(pvt->pci_sad0, pvt->info.dram_rule[n_sads],
&reg);
limit = pvt->info.sad_limit(reg);
if (!DRAM_RULE_ENABLE(reg))
continue;
if (limit <= prv)
break;
tmp_mb = (limit + 1) >> 20;
gb = div_u64_rem(tmp_mb, 1024, &mb);
edac_dbg(0, "SAD#%d %s up to %u.%03u GB (0x%016Lx) Interleave: %s reg=0x%08x\n",
n_sads,
show_dram_attr(pvt->info.dram_attr(reg)),
gb, (mb*1000)/1024,
((u64)tmp_mb) << 20L,
get_intlv_mode_str(reg, pvt->info.type),
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
if (pvt->info.type == KNIGHTS_LANDING)
return;
prv = 0;
for (n_tads = 0; n_tads < MAX_TAD; n_tads++) {
pci_read_config_dword(pvt->pci_ha0, tad_dram_rule[n_tads],
&reg);
limit = TAD_LIMIT(reg);
if (limit <= prv)
break;
tmp_mb = (limit + 1) >> 20;
gb = div_u64_rem(tmp_mb, 1024, &mb);
edac_dbg(0, "TAD#%d: up to %u.%03u GB (0x%016Lx), socket interleave %d, memory interleave %d, TGT: %d, %d, %d, %d, reg=0x%08x\n",
n_tads, gb, (mb*1000)/1024,
((u64)tmp_mb) << 20L,
(u32)(1 << TAD_SOCK(reg)),
(u32)TAD_CH(reg) + 1,
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
gb = div_u64_rem(tmp_mb, 1024, &mb);
edac_dbg(0, "TAD CH#%d, offset #%d: %u.%03u GB (0x%016Lx), reg=0x%08x\n",
i, j,
gb, (mb*1000)/1024,
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
tmp_mb = pvt->info.rir_limit(reg) >> 20;
rir_way = 1 << RIR_WAY(reg);
gb = div_u64_rem(tmp_mb, 1024, &mb);
edac_dbg(0, "CH#%d RIR#%d, limit: %u.%03u GB (0x%016Lx), way: %d, reg=0x%08x\n",
i, j,
gb, (mb*1000)/1024,
((u64)tmp_mb) << 20L,
rir_way,
reg);
for (k = 0; k < rir_way; k++) {
pci_read_config_dword(pvt->pci_tad[i],
rir_offset[j][k],
&reg);
tmp_mb = RIR_OFFSET(pvt->info.type, reg) << 6;
gb = div_u64_rem(tmp_mb, 1024, &mb);
edac_dbg(0, "CH#%d RIR#%d INTL#%d, offset %u.%03u GB (0x%016Lx), tgt: %d, reg=0x%08x\n",
i, j, k,
gb, (mb*1000)/1024,
((u64)tmp_mb) << 20L,
(u32)RIR_RNK_TGT(pvt->info.type, reg),
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
u8 *socket, u8 *ha,
long *channel_mask,
u8 *rank,
char **area_type, char *msg)
{
struct mem_ctl_info *new_mci;
struct sbridge_pvt *pvt = mci->pvt_info;
struct pci_dev *pci_ha;
int n_rir, n_sads, n_tads, sad_way, sck_xch;
int sad_interl, idx, base_ch;
int interleave_mode, shiftup = 0;
unsigned sad_interleave[pvt->info.max_interleave];
u32 reg, dram_rule;
u8 ch_way, sck_way, pkg, sad_ha = 0, ch_add = 0;
u32 tad_offset;
u32 rir_way;
u32 mb, gb;
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
limit = pvt->info.sad_limit(reg);
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
dram_rule = reg;
*area_type = show_dram_attr(pvt->info.dram_attr(dram_rule));
interleave_mode = pvt->info.interleave_mode(dram_rule);
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
} else if (pvt->info.type == HASWELL || pvt->info.type == BROADWELL) {
int bits, a7mode = A7MODE(dram_rule);
if (a7mode) {
bits = GET_BITFIELD(addr, 7, 8) << 1;
bits |= GET_BITFIELD(addr, 9, 9);
} else
bits = GET_BITFIELD(addr, 6, 8);
if (interleave_mode == 0) {
idx = GET_BITFIELD(addr, 16, 18);
idx ^= bits;
} else
idx = bits;
pkg = sad_pkg(pvt->info.interleave_pkg, reg, idx);
*socket = sad_pkg_socket(pkg);
sad_ha = sad_pkg_ha(pkg);
if (sad_ha)
ch_add = 4;
if (a7mode) {
pci_read_config_dword(pvt->pci_ha0,
HASWELL_HASYSDEFEATURE2, &reg);
shiftup = GET_BITFIELD(reg, 22, 22);
}
edac_dbg(0, "SAD interleave package: %d = CPU socket %d, HA %i, shiftup: %i\n",
idx, *socket, sad_ha, shiftup);
} else {
idx = (addr >> 6) & 7;
pkg = sad_pkg(pvt->info.interleave_pkg, reg, idx);
*socket = sad_pkg_socket(pkg);
sad_ha = sad_pkg_ha(pkg);
if (sad_ha)
ch_add = 4;
edac_dbg(0, "SAD interleave package: %d = CPU socket %d, HA %d\n",
idx, *socket, sad_ha);
}
*ha = sad_ha;
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
sck_way = TAD_SOCK(reg);
if (ch_way == 3)
idx = addr >> 6;
else {
idx = (addr >> (6 + sck_way + shiftup)) & 0x3;
if (pvt->is_chan_hash)
idx = haswell_chan_hash(idx, addr);
}
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
pci_read_config_dword(pvt->pci_tad[ch_add + base_ch],
tad_ch_nilv_offset[n_tads],
&tad_offset);
if (pvt->is_mirrored) {
*channel_mask |= 1 << ((base_ch + 2) % 4);
switch(ch_way) {
case 2:
case 4:
sck_xch = (1 << sck_way) * (ch_way >> 1);
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
sck_way,
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
ch_addr = addr - offset;
ch_addr >>= (6 + shiftup);
ch_addr /= sck_xch;
ch_addr <<= (6 + shiftup);
ch_addr |= addr & ((1 << (6 + shiftup)) - 1);
for (n_rir = 0; n_rir < MAX_RIR_RANGES; n_rir++) {
pci_read_config_dword(pvt->pci_tad[ch_add + base_ch],
rir_way_limit[n_rir],
&reg);
if (!IS_RIR_VALID(reg))
continue;
limit = pvt->info.rir_limit(reg);
gb = div_u64_rem(limit >> 20, 1024, &mb);
edac_dbg(0, "RIR#%d, limit: %u.%03u GB (0x%016Lx), way: %d\n",
n_rir,
gb, (mb*1000)/1024,
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
pci_read_config_dword(pvt->pci_tad[ch_add + base_ch],
rir_offset[n_rir][idx],
&reg);
*rank = RIR_RNK_TGT(pvt->info.type, reg);
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
const unsigned devno,
const int multi_bus)
{
struct sbridge_dev *sbridge_dev;
const struct pci_id_descr *dev_descr = &table->descr[devno];
struct pci_dev *pdev = NULL;
u8 bus = 0;
sbridge_printk(KERN_DEBUG,
"Seeking for: PCI ID %04x:%04x\n",
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
"Device not found: %04x:%04x\n",
PCI_VENDOR_ID_INTEL, dev_descr->dev_id);
return -ENODEV;
}
bus = pdev->bus->number;
sbridge_dev = get_sbridge_dev(bus, multi_bus);
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
"Duplicated device for %04x:%04x\n",
PCI_VENDOR_ID_INTEL, dev_descr->dev_id);
pci_dev_put(pdev);
return -ENODEV;
}
sbridge_dev->pdev[devno] = pdev;
if (unlikely(pci_enable_device(pdev) < 0)) {
sbridge_printk(KERN_ERR,
"Couldn't enable %04x:%04x\n",
PCI_VENDOR_ID_INTEL, dev_descr->dev_id);
return -ENODEV;
}
edac_dbg(0, "Detected %04x:%04x\n",
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
int allow_dups = 0;
int multi_bus = 0;
if (table->type == KNIGHTS_LANDING)
allow_dups = multi_bus = 1;
while (table && table->descr) {
for (i = 0; i < table->n_devs; i++) {
if (!allow_dups || i == 0 ||
table->descr[i].dev_id !=
table->descr[i-1].dev_id) {
pdev = NULL;
}
do {
rc = sbridge_get_onedevice(&pdev, num_mc,
table, i, multi_bus);
if (rc < 0) {
if (i == 0) {
i = table->n_devs;
break;
}
sbridge_put_all_devices();
return -ENODEV;
}
} while (pdev && !allow_dups);
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
u8 saw_chan_mask = 0;
int i;
for (i = 0; i < sbridge_dev->n_devs; i++) {
pdev = sbridge_dev->pdev[i];
if (!pdev)
continue;
switch (pdev->device) {
case PCI_DEVICE_ID_INTEL_SBRIDGE_SAD0:
pvt->pci_sad0 = pdev;
break;
case PCI_DEVICE_ID_INTEL_SBRIDGE_SAD1:
pvt->pci_sad1 = pdev;
break;
case PCI_DEVICE_ID_INTEL_SBRIDGE_BR:
pvt->pci_br0 = pdev;
break;
case PCI_DEVICE_ID_INTEL_SBRIDGE_IMC_HA0:
pvt->pci_ha0 = pdev;
break;
case PCI_DEVICE_ID_INTEL_SBRIDGE_IMC_TA:
pvt->pci_ta = pdev;
break;
case PCI_DEVICE_ID_INTEL_SBRIDGE_IMC_RAS:
pvt->pci_ras = pdev;
break;
case PCI_DEVICE_ID_INTEL_SBRIDGE_IMC_TAD0:
case PCI_DEVICE_ID_INTEL_SBRIDGE_IMC_TAD1:
case PCI_DEVICE_ID_INTEL_SBRIDGE_IMC_TAD2:
case PCI_DEVICE_ID_INTEL_SBRIDGE_IMC_TAD3:
{
int id = pdev->device - PCI_DEVICE_ID_INTEL_SBRIDGE_IMC_TAD0;
pvt->pci_tad[id] = pdev;
saw_chan_mask |= 1 << id;
}
break;
case PCI_DEVICE_ID_INTEL_SBRIDGE_IMC_DDRIO:
pvt->pci_ddrio = pdev;
break;
default:
goto error;
}
edac_dbg(0, "Associated PCI %02x:%02x, bus %d with dev = %p\n",
pdev->vendor, pdev->device,
sbridge_dev->bus,
pdev);
}
if (!pvt->pci_sad0 || !pvt->pci_sad1 || !pvt->pci_ha0 ||
!pvt->pci_ras || !pvt->pci_ta)
goto enodev;
if (saw_chan_mask != 0x0f)
goto enodev;
return 0;
enodev:
sbridge_printk(KERN_ERR, "Some needed devices are missing\n");
return -ENODEV;
error:
sbridge_printk(KERN_ERR, "Unexpected device %02x:%02x\n",
PCI_VENDOR_ID_INTEL, pdev->device);
return -EINVAL;
}
static int ibridge_mci_bind_devs(struct mem_ctl_info *mci,
struct sbridge_dev *sbridge_dev)
{
struct sbridge_pvt *pvt = mci->pvt_info;
struct pci_dev *pdev;
u8 saw_chan_mask = 0;
int i;
for (i = 0; i < sbridge_dev->n_devs; i++) {
pdev = sbridge_dev->pdev[i];
if (!pdev)
continue;
switch (pdev->device) {
case PCI_DEVICE_ID_INTEL_IBRIDGE_IMC_HA0:
pvt->pci_ha0 = pdev;
break;
case PCI_DEVICE_ID_INTEL_IBRIDGE_IMC_HA0_TA:
pvt->pci_ta = pdev;
case PCI_DEVICE_ID_INTEL_IBRIDGE_IMC_HA0_RAS:
pvt->pci_ras = pdev;
break;
case PCI_DEVICE_ID_INTEL_IBRIDGE_IMC_HA0_TAD0:
case PCI_DEVICE_ID_INTEL_IBRIDGE_IMC_HA0_TAD1:
case PCI_DEVICE_ID_INTEL_IBRIDGE_IMC_HA0_TAD2:
case PCI_DEVICE_ID_INTEL_IBRIDGE_IMC_HA0_TAD3:
{
int id = pdev->device - PCI_DEVICE_ID_INTEL_IBRIDGE_IMC_HA0_TAD0;
pvt->pci_tad[id] = pdev;
saw_chan_mask |= 1 << id;
}
break;
case PCI_DEVICE_ID_INTEL_IBRIDGE_IMC_2HA_DDRIO0:
pvt->pci_ddrio = pdev;
break;
case PCI_DEVICE_ID_INTEL_IBRIDGE_IMC_1HA_DDRIO0:
pvt->pci_ddrio = pdev;
break;
case PCI_DEVICE_ID_INTEL_IBRIDGE_SAD:
pvt->pci_sad0 = pdev;
break;
case PCI_DEVICE_ID_INTEL_IBRIDGE_BR0:
pvt->pci_br0 = pdev;
break;
case PCI_DEVICE_ID_INTEL_IBRIDGE_BR1:
pvt->pci_br1 = pdev;
break;
case PCI_DEVICE_ID_INTEL_IBRIDGE_IMC_HA1:
pvt->pci_ha1 = pdev;
break;
case PCI_DEVICE_ID_INTEL_IBRIDGE_IMC_HA1_TAD0:
case PCI_DEVICE_ID_INTEL_IBRIDGE_IMC_HA1_TAD1:
case PCI_DEVICE_ID_INTEL_IBRIDGE_IMC_HA1_TAD2:
case PCI_DEVICE_ID_INTEL_IBRIDGE_IMC_HA1_TAD3:
{
int id = pdev->device - PCI_DEVICE_ID_INTEL_IBRIDGE_IMC_HA1_TAD0 + 4;
pvt->pci_tad[id] = pdev;
saw_chan_mask |= 1 << id;
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
if (!pvt->pci_sad0 || !pvt->pci_ha0 || !pvt->pci_br0 ||
!pvt->pci_br1 || !pvt->pci_ras || !pvt->pci_ta)
goto enodev;
if (saw_chan_mask != 0x0f &&
saw_chan_mask != 0x33 &&
saw_chan_mask != 0xff)
goto enodev;
return 0;
enodev:
sbridge_printk(KERN_ERR, "Some needed devices are missing\n");
return -ENODEV;
error:
sbridge_printk(KERN_ERR,
"Unexpected device %02x:%02x\n", PCI_VENDOR_ID_INTEL,
pdev->device);
return -EINVAL;
}
static int haswell_mci_bind_devs(struct mem_ctl_info *mci,
struct sbridge_dev *sbridge_dev)
{
struct sbridge_pvt *pvt = mci->pvt_info;
struct pci_dev *pdev;
u8 saw_chan_mask = 0;
int i;
if (pvt->info.pci_vtd == NULL)
pvt->info.pci_vtd = pci_get_device(PCI_VENDOR_ID_INTEL,
PCI_DEVICE_ID_INTEL_HASWELL_IMC_VTD_MISC,
NULL);
for (i = 0; i < sbridge_dev->n_devs; i++) {
pdev = sbridge_dev->pdev[i];
if (!pdev)
continue;
switch (pdev->device) {
case PCI_DEVICE_ID_INTEL_HASWELL_IMC_CBO_SAD0:
pvt->pci_sad0 = pdev;
break;
case PCI_DEVICE_ID_INTEL_HASWELL_IMC_CBO_SAD1:
pvt->pci_sad1 = pdev;
break;
case PCI_DEVICE_ID_INTEL_HASWELL_IMC_HA0:
pvt->pci_ha0 = pdev;
break;
case PCI_DEVICE_ID_INTEL_HASWELL_IMC_HA0_TA:
pvt->pci_ta = pdev;
break;
case PCI_DEVICE_ID_INTEL_HASWELL_IMC_HA0_THERMAL:
pvt->pci_ras = pdev;
break;
case PCI_DEVICE_ID_INTEL_HASWELL_IMC_HA0_TAD0:
case PCI_DEVICE_ID_INTEL_HASWELL_IMC_HA0_TAD1:
case PCI_DEVICE_ID_INTEL_HASWELL_IMC_HA0_TAD2:
case PCI_DEVICE_ID_INTEL_HASWELL_IMC_HA0_TAD3:
{
int id = pdev->device - PCI_DEVICE_ID_INTEL_HASWELL_IMC_HA0_TAD0;
pvt->pci_tad[id] = pdev;
saw_chan_mask |= 1 << id;
}
break;
case PCI_DEVICE_ID_INTEL_HASWELL_IMC_HA1_TAD0:
case PCI_DEVICE_ID_INTEL_HASWELL_IMC_HA1_TAD1:
case PCI_DEVICE_ID_INTEL_HASWELL_IMC_HA1_TAD2:
case PCI_DEVICE_ID_INTEL_HASWELL_IMC_HA1_TAD3:
{
int id = pdev->device - PCI_DEVICE_ID_INTEL_HASWELL_IMC_HA1_TAD0 + 4;
pvt->pci_tad[id] = pdev;
saw_chan_mask |= 1 << id;
}
break;
case PCI_DEVICE_ID_INTEL_HASWELL_IMC_DDRIO0:
case PCI_DEVICE_ID_INTEL_HASWELL_IMC_DDRIO1:
case PCI_DEVICE_ID_INTEL_HASWELL_IMC_DDRIO2:
case PCI_DEVICE_ID_INTEL_HASWELL_IMC_DDRIO3:
if (!pvt->pci_ddrio)
pvt->pci_ddrio = pdev;
break;
case PCI_DEVICE_ID_INTEL_HASWELL_IMC_HA1:
pvt->pci_ha1 = pdev;
break;
case PCI_DEVICE_ID_INTEL_HASWELL_IMC_HA1_TA:
pvt->pci_ha1_ta = pdev;
break;
default:
break;
}
edac_dbg(0, "Associated PCI %02x.%02d.%d with dev = %p\n",
sbridge_dev->bus,
PCI_SLOT(pdev->devfn), PCI_FUNC(pdev->devfn),
pdev);
}
if (!pvt->pci_sad0 || !pvt->pci_ha0 || !pvt->pci_sad1 ||
!pvt->pci_ras || !pvt->pci_ta || !pvt->info.pci_vtd)
goto enodev;
if (saw_chan_mask != 0x0f &&
saw_chan_mask != 0x33 &&
saw_chan_mask != 0xff)
goto enodev;
return 0;
enodev:
sbridge_printk(KERN_ERR, "Some needed devices are missing\n");
return -ENODEV;
}
static int broadwell_mci_bind_devs(struct mem_ctl_info *mci,
struct sbridge_dev *sbridge_dev)
{
struct sbridge_pvt *pvt = mci->pvt_info;
struct pci_dev *pdev;
u8 saw_chan_mask = 0;
int i;
if (pvt->info.pci_vtd == NULL)
pvt->info.pci_vtd = pci_get_device(PCI_VENDOR_ID_INTEL,
PCI_DEVICE_ID_INTEL_BROADWELL_IMC_VTD_MISC,
NULL);
for (i = 0; i < sbridge_dev->n_devs; i++) {
pdev = sbridge_dev->pdev[i];
if (!pdev)
continue;
switch (pdev->device) {
case PCI_DEVICE_ID_INTEL_BROADWELL_IMC_CBO_SAD0:
pvt->pci_sad0 = pdev;
break;
case PCI_DEVICE_ID_INTEL_BROADWELL_IMC_CBO_SAD1:
pvt->pci_sad1 = pdev;
break;
case PCI_DEVICE_ID_INTEL_BROADWELL_IMC_HA0:
pvt->pci_ha0 = pdev;
break;
case PCI_DEVICE_ID_INTEL_BROADWELL_IMC_HA0_TA:
pvt->pci_ta = pdev;
break;
case PCI_DEVICE_ID_INTEL_BROADWELL_IMC_HA0_THERMAL:
pvt->pci_ras = pdev;
break;
case PCI_DEVICE_ID_INTEL_BROADWELL_IMC_HA0_TAD0:
case PCI_DEVICE_ID_INTEL_BROADWELL_IMC_HA0_TAD1:
case PCI_DEVICE_ID_INTEL_BROADWELL_IMC_HA0_TAD2:
case PCI_DEVICE_ID_INTEL_BROADWELL_IMC_HA0_TAD3:
{
int id = pdev->device - PCI_DEVICE_ID_INTEL_BROADWELL_IMC_HA0_TAD0;
pvt->pci_tad[id] = pdev;
saw_chan_mask |= 1 << id;
}
break;
case PCI_DEVICE_ID_INTEL_BROADWELL_IMC_HA1_TAD0:
case PCI_DEVICE_ID_INTEL_BROADWELL_IMC_HA1_TAD1:
case PCI_DEVICE_ID_INTEL_BROADWELL_IMC_HA1_TAD2:
case PCI_DEVICE_ID_INTEL_BROADWELL_IMC_HA1_TAD3:
{
int id = pdev->device - PCI_DEVICE_ID_INTEL_BROADWELL_IMC_HA1_TAD0 + 4;
pvt->pci_tad[id] = pdev;
saw_chan_mask |= 1 << id;
}
break;
case PCI_DEVICE_ID_INTEL_BROADWELL_IMC_DDRIO0:
pvt->pci_ddrio = pdev;
break;
case PCI_DEVICE_ID_INTEL_BROADWELL_IMC_HA1:
pvt->pci_ha1 = pdev;
break;
case PCI_DEVICE_ID_INTEL_BROADWELL_IMC_HA1_TA:
pvt->pci_ha1_ta = pdev;
break;
default:
break;
}
edac_dbg(0, "Associated PCI %02x.%02d.%d with dev = %p\n",
sbridge_dev->bus,
PCI_SLOT(pdev->devfn), PCI_FUNC(pdev->devfn),
pdev);
}
if (!pvt->pci_sad0 || !pvt->pci_ha0 || !pvt->pci_sad1 ||
!pvt->pci_ras || !pvt->pci_ta || !pvt->info.pci_vtd)
goto enodev;
if (saw_chan_mask != 0x0f &&
saw_chan_mask != 0x33 &&
saw_chan_mask != 0xff)
goto enodev;
return 0;
enodev:
sbridge_printk(KERN_ERR, "Some needed devices are missing\n");
return -ENODEV;
}
static int knl_mci_bind_devs(struct mem_ctl_info *mci,
struct sbridge_dev *sbridge_dev)
{
struct sbridge_pvt *pvt = mci->pvt_info;
struct pci_dev *pdev;
int dev, func;
int i;
int devidx;
for (i = 0; i < sbridge_dev->n_devs; i++) {
pdev = sbridge_dev->pdev[i];
if (!pdev)
continue;
dev = (pdev->devfn >> 3) & 0x1f;
func = pdev->devfn & 0x7;
switch (pdev->device) {
case PCI_DEVICE_ID_INTEL_KNL_IMC_MC:
if (dev == 8)
pvt->knl.pci_mc0 = pdev;
else if (dev == 9)
pvt->knl.pci_mc1 = pdev;
else {
sbridge_printk(KERN_ERR,
"Memory controller in unexpected place! (dev %d, fn %d)\n",
dev, func);
continue;
}
break;
case PCI_DEVICE_ID_INTEL_KNL_IMC_SAD0:
pvt->pci_sad0 = pdev;
break;
case PCI_DEVICE_ID_INTEL_KNL_IMC_SAD1:
pvt->pci_sad1 = pdev;
break;
case PCI_DEVICE_ID_INTEL_KNL_IMC_CHA:
devidx = ((dev-14)*8)+func;
if (devidx < 0 || devidx >= KNL_MAX_CHAS) {
sbridge_printk(KERN_ERR,
"Caching and Home Agent in unexpected place! (dev %d, fn %d)\n",
dev, func);
continue;
}
WARN_ON(pvt->knl.pci_cha[devidx] != NULL);
pvt->knl.pci_cha[devidx] = pdev;
break;
case PCI_DEVICE_ID_INTEL_KNL_IMC_CHANNEL:
devidx = -1;
if (dev == 9)
devidx = func-2;
else if (dev == 8)
devidx = 3 + (func-2);
if (devidx < 0 || devidx >= KNL_MAX_CHANNELS) {
sbridge_printk(KERN_ERR,
"DRAM Channel Registers in unexpected place! (dev %d, fn %d)\n",
dev, func);
continue;
}
WARN_ON(pvt->knl.pci_channel[devidx] != NULL);
pvt->knl.pci_channel[devidx] = pdev;
break;
case PCI_DEVICE_ID_INTEL_KNL_IMC_TOLHM:
pvt->knl.pci_mc_info = pdev;
break;
case PCI_DEVICE_ID_INTEL_KNL_IMC_TA:
pvt->pci_ta = pdev;
break;
default:
sbridge_printk(KERN_ERR, "Unexpected device %d\n",
pdev->device);
break;
}
}
if (!pvt->knl.pci_mc0 || !pvt->knl.pci_mc1 ||
!pvt->pci_sad0 || !pvt->pci_sad1 ||
!pvt->pci_ta) {
goto enodev;
}
for (i = 0; i < KNL_MAX_CHANNELS; i++) {
if (!pvt->knl.pci_channel[i]) {
sbridge_printk(KERN_ERR, "Missing channel %d\n", i);
goto enodev;
}
}
for (i = 0; i < KNL_MAX_CHAS; i++) {
if (!pvt->knl.pci_cha[i]) {
sbridge_printk(KERN_ERR, "Missing CHA %d\n", i);
goto enodev;
}
}
return 0;
enodev:
sbridge_printk(KERN_ERR, "Some needed devices are missing\n");
return -ENODEV;
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
u8 rank, socket, ha;
int rc, dimm;
char *area_type = NULL;
if (pvt->info.type != SANDY_BRIDGE)
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
if (pvt->info.type == KNIGHTS_LANDING) {
if (channel == 14) {
edac_dbg(0, "%s%s err_code:%04x:%04x EDRAM bank %d\n",
overflow ? " OVERFLOW" : "",
(uncorrected_error && recoverable)
? " recoverable" : "",
mscod, errcode,
m->bank);
} else {
char A = *("A");
channel = knl_channel_remap(m->bank == 16, channel);
channel_mask = 1 << channel;
snprintf(msg, sizeof(msg),
"%s%s err_code:%04x:%04x channel:%d (DIMM_%c)",
overflow ? " OVERFLOW" : "",
(uncorrected_error && recoverable)
? " recoverable" : " ",
mscod, errcode, channel, A + channel);
edac_mc_handle_error(tp_event, mci, core_err_cnt,
m->addr >> PAGE_SHIFT, m->addr & ~PAGE_MASK, 0,
channel, 0, -1,
optype, msg);
}
return;
} else {
rc = get_memory_error_data(mci, m->addr, &socket, &ha,
&channel_mask, &rank, &area_type, msg);
}
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
if (!pvt->is_lockstep && !pvt->is_mirrored && !pvt->is_close_pg)
channel = first_channel;
snprintf(msg, sizeof(msg),
"%s%s area:%s err_code:%04x:%04x socket:%d ha:%d channel_mask:%ld rank:%d",
overflow ? " OVERFLOW" : "",
(uncorrected_error && recoverable) ? " recoverable" : "",
area_type,
mscod, errcode,
socket, ha,
channel_mask,
rank);
edac_dbg(0, "%s\n", msg);
if (channel == CHANNEL_UNSPECIFIED)
channel = -1;
edac_mc_handle_error(tp_event, mci, core_err_cnt,
m->addr >> PAGE_SHIFT, m->addr & ~PAGE_MASK, 0,
4*ha+channel, dimm, -1,
optype, msg);
return;
err_parsing:
edac_mc_handle_error(tp_event, mci, core_err_cnt, 0, 0, 0,
-1, -1, -1,
msg, "");
}
static int sbridge_mce_check_error(struct notifier_block *nb, unsigned long val,
void *data)
{
struct mce *mce = (struct mce *)data;
struct mem_ctl_info *mci;
struct sbridge_pvt *pvt;
char *type;
if (edac_get_report_status() == EDAC_REPORTING_DISABLED)
return NOTIFY_DONE;
mci = get_mci_for_node_id(mce->socketid);
if (!mci)
return NOTIFY_DONE;
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
sbridge_mce_output_error(mci, mce);
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
rc = check_if_ecc_is_active(sbridge_dev->bus, type);
if (unlikely(rc < 0))
return rc;
layers[0].type = EDAC_MC_LAYER_CHANNEL;
layers[0].size = type == KNIGHTS_LANDING ?
KNL_MAX_CHANNELS : NUM_CHANNELS;
layers[0].is_virt_csrow = false;
layers[1].type = EDAC_MC_LAYER_SLOT;
layers[1].size = type == KNIGHTS_LANDING ? 1 : MAX_DIMMS;
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
mci->mtype_cap = type == KNIGHTS_LANDING ?
MEM_FLAG_DDR4 : MEM_FLAG_DDR3;
mci->edac_ctl_cap = EDAC_FLAG_NONE;
mci->edac_cap = EDAC_FLAG_NONE;
mci->mod_name = "sbridge_edac.c";
mci->mod_ver = SBRIDGE_REVISION;
mci->dev_name = pci_name(pdev);
mci->ctl_page_to_phys = NULL;
pvt->info.type = type;
switch (type) {
case IVY_BRIDGE:
pvt->info.rankcfgr = IB_RANK_CFG_A;
pvt->info.get_tolm = ibridge_get_tolm;
pvt->info.get_tohm = ibridge_get_tohm;
pvt->info.dram_rule = ibridge_dram_rule;
pvt->info.get_memory_type = get_memory_type;
pvt->info.get_node_id = get_node_id;
pvt->info.rir_limit = rir_limit;
pvt->info.sad_limit = sad_limit;
pvt->info.interleave_mode = interleave_mode;
pvt->info.dram_attr = dram_attr;
pvt->info.max_sad = ARRAY_SIZE(ibridge_dram_rule);
pvt->info.interleave_list = ibridge_interleave_list;
pvt->info.max_interleave = ARRAY_SIZE(ibridge_interleave_list);
pvt->info.interleave_pkg = ibridge_interleave_pkg;
pvt->info.get_width = ibridge_get_width;
mci->ctl_name = kasprintf(GFP_KERNEL, "Ivy Bridge Socket#%d", mci->mc_idx);
rc = ibridge_mci_bind_devs(mci, sbridge_dev);
if (unlikely(rc < 0))
goto fail0;
break;
case SANDY_BRIDGE:
pvt->info.rankcfgr = SB_RANK_CFG_A;
pvt->info.get_tolm = sbridge_get_tolm;
pvt->info.get_tohm = sbridge_get_tohm;
pvt->info.dram_rule = sbridge_dram_rule;
pvt->info.get_memory_type = get_memory_type;
pvt->info.get_node_id = get_node_id;
pvt->info.rir_limit = rir_limit;
pvt->info.sad_limit = sad_limit;
pvt->info.interleave_mode = interleave_mode;
pvt->info.dram_attr = dram_attr;
pvt->info.max_sad = ARRAY_SIZE(sbridge_dram_rule);
pvt->info.interleave_list = sbridge_interleave_list;
pvt->info.max_interleave = ARRAY_SIZE(sbridge_interleave_list);
pvt->info.interleave_pkg = sbridge_interleave_pkg;
pvt->info.get_width = sbridge_get_width;
mci->ctl_name = kasprintf(GFP_KERNEL, "Sandy Bridge Socket#%d", mci->mc_idx);
rc = sbridge_mci_bind_devs(mci, sbridge_dev);
if (unlikely(rc < 0))
goto fail0;
break;
case HASWELL:
pvt->info.get_tolm = haswell_get_tolm;
pvt->info.get_tohm = haswell_get_tohm;
pvt->info.dram_rule = ibridge_dram_rule;
pvt->info.get_memory_type = haswell_get_memory_type;
pvt->info.get_node_id = haswell_get_node_id;
pvt->info.rir_limit = haswell_rir_limit;
pvt->info.sad_limit = sad_limit;
pvt->info.interleave_mode = interleave_mode;
pvt->info.dram_attr = dram_attr;
pvt->info.max_sad = ARRAY_SIZE(ibridge_dram_rule);
pvt->info.interleave_list = ibridge_interleave_list;
pvt->info.max_interleave = ARRAY_SIZE(ibridge_interleave_list);
pvt->info.interleave_pkg = ibridge_interleave_pkg;
pvt->info.get_width = ibridge_get_width;
mci->ctl_name = kasprintf(GFP_KERNEL, "Haswell Socket#%d", mci->mc_idx);
rc = haswell_mci_bind_devs(mci, sbridge_dev);
if (unlikely(rc < 0))
goto fail0;
break;
case BROADWELL:
pvt->info.get_tolm = haswell_get_tolm;
pvt->info.get_tohm = haswell_get_tohm;
pvt->info.dram_rule = ibridge_dram_rule;
pvt->info.get_memory_type = haswell_get_memory_type;
pvt->info.get_node_id = haswell_get_node_id;
pvt->info.rir_limit = haswell_rir_limit;
pvt->info.sad_limit = sad_limit;
pvt->info.interleave_mode = interleave_mode;
pvt->info.dram_attr = dram_attr;
pvt->info.max_sad = ARRAY_SIZE(ibridge_dram_rule);
pvt->info.interleave_list = ibridge_interleave_list;
pvt->info.max_interleave = ARRAY_SIZE(ibridge_interleave_list);
pvt->info.interleave_pkg = ibridge_interleave_pkg;
pvt->info.get_width = broadwell_get_width;
mci->ctl_name = kasprintf(GFP_KERNEL, "Broadwell Socket#%d", mci->mc_idx);
rc = broadwell_mci_bind_devs(mci, sbridge_dev);
if (unlikely(rc < 0))
goto fail0;
break;
case KNIGHTS_LANDING:
pvt->info.get_tolm = knl_get_tolm;
pvt->info.get_tohm = knl_get_tohm;
pvt->info.dram_rule = knl_dram_rule;
pvt->info.get_memory_type = knl_get_memory_type;
pvt->info.get_node_id = knl_get_node_id;
pvt->info.rir_limit = NULL;
pvt->info.sad_limit = knl_sad_limit;
pvt->info.interleave_mode = knl_interleave_mode;
pvt->info.dram_attr = dram_attr_knl;
pvt->info.max_sad = ARRAY_SIZE(knl_dram_rule);
pvt->info.interleave_list = knl_interleave_list;
pvt->info.max_interleave = ARRAY_SIZE(knl_interleave_list);
pvt->info.interleave_pkg = ibridge_interleave_pkg;
pvt->info.get_width = knl_get_width;
mci->ctl_name = kasprintf(GFP_KERNEL,
"Knights Landing Socket#%d", mci->mc_idx);
rc = knl_mci_bind_devs(mci, sbridge_dev);
if (unlikely(rc < 0))
goto fail0;
break;
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
static int sbridge_probe(const struct x86_cpu_id *id)
{
int rc = -ENODEV;
u8 mc, num_mc = 0;
struct sbridge_dev *sbridge_dev;
struct pci_id_table *ptable = (struct pci_id_table *)id->driver_data;
rc = sbridge_get_all_devices(&num_mc, ptable);
if (unlikely(rc < 0)) {
edac_dbg(0, "couldn't get all devices\n");
goto fail0;
}
mc = 0;
list_for_each_entry(sbridge_dev, &sbridge_edac_list, list) {
edac_dbg(0, "Registering MC#%d (%d of %d)\n",
mc, mc + 1, num_mc);
sbridge_dev->mc = mc++;
rc = sbridge_register_mci(sbridge_dev, ptable->type);
if (unlikely(rc < 0))
goto fail1;
}
sbridge_printk(KERN_INFO, "%s\n", SBRIDGE_REVISION);
return 0;
fail1:
list_for_each_entry(sbridge_dev, &sbridge_edac_list, list)
sbridge_unregister_mci(sbridge_dev);
sbridge_put_all_devices();
fail0:
return rc;
}
static void sbridge_remove(void)
{
struct sbridge_dev *sbridge_dev;
edac_dbg(0, "\n");
list_for_each_entry(sbridge_dev, &sbridge_edac_list, list)
sbridge_unregister_mci(sbridge_dev);
sbridge_put_all_devices();
}
static int __init sbridge_init(void)
{
const struct x86_cpu_id *id;
int rc;
edac_dbg(2, "\n");
id = x86_match_cpu(sbridge_cpuids);
if (!id)
return -ENODEV;
opstate_init();
rc = sbridge_probe(id);
if (rc >= 0) {
mce_register_decode_chain(&sbridge_mce_dec);
if (edac_get_report_status() == EDAC_REPORTING_DISABLED)
sbridge_printk(KERN_WARNING, "Loading driver, error reporting disabled.\n");
return 0;
}
sbridge_printk(KERN_ERR, "Failed to register device with error %d.\n",
rc);
return rc;
}
static void __exit sbridge_exit(void)
{
edac_dbg(2, "\n");
sbridge_remove();
mce_unregister_decode_chain(&sbridge_mce_dec);
}
