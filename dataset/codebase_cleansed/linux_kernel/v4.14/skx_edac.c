static struct skx_dev *get_skx_dev(u8 bus, u8 idx)
{
struct skx_dev *d;
list_for_each_entry(d, &skx_edac_list, list) {
if (d->bus[idx] == bus)
return d;
}
return NULL;
}
static int get_all_bus_mappings(void)
{
struct pci_dev *pdev, *prev;
struct skx_dev *d;
u32 reg;
int ndev = 0;
prev = NULL;
for (;;) {
pdev = pci_get_device(PCI_VENDOR_ID_INTEL, 0x2016, prev);
if (!pdev)
break;
ndev++;
d = kzalloc(sizeof(*d), GFP_KERNEL);
if (!d) {
pci_dev_put(pdev);
return -ENOMEM;
}
pci_read_config_dword(pdev, 0xCC, &reg);
d->bus[0] = GET_BITFIELD(reg, 0, 7);
d->bus[1] = GET_BITFIELD(reg, 8, 15);
d->bus[2] = GET_BITFIELD(reg, 16, 23);
d->bus[3] = GET_BITFIELD(reg, 24, 31);
edac_dbg(2, "busses: %x, %x, %x, %x\n",
d->bus[0], d->bus[1], d->bus[2], d->bus[3]);
list_add_tail(&d->list, &skx_edac_list);
skx_num_sockets++;
prev = pdev;
}
return ndev;
}
static int get_all_munits(const struct munit *m)
{
struct pci_dev *pdev, *prev;
struct skx_dev *d;
u32 reg;
int i = 0, ndev = 0;
prev = NULL;
for (;;) {
pdev = pci_get_device(PCI_VENDOR_ID_INTEL, m->did, prev);
if (!pdev)
break;
ndev++;
if (m->per_socket == NUM_IMC) {
for (i = 0; i < NUM_IMC; i++)
if (m->devfn[i] == pdev->devfn)
break;
if (i == NUM_IMC)
goto fail;
}
d = get_skx_dev(pdev->bus->number, m->busidx);
if (!d)
goto fail;
if (unlikely(pci_enable_device(pdev) < 0)) {
skx_printk(KERN_ERR,
"Couldn't enable %04x:%04x\n", PCI_VENDOR_ID_INTEL, m->did);
goto fail;
}
switch (m->mtype) {
case CHAN0: case CHAN1: case CHAN2:
pci_dev_get(pdev);
d->imc[i].chan[m->mtype].cdev = pdev;
break;
case SAD_ALL:
pci_dev_get(pdev);
d->sad_all = pdev;
break;
case UTIL_ALL:
pci_dev_get(pdev);
d->util_all = pdev;
break;
case SAD:
pci_read_config_dword(pdev, 0xB4, &reg);
if (reg != 0) {
if (d->mcroute == 0)
d->mcroute = reg;
else if (d->mcroute != reg) {
skx_printk(KERN_ERR,
"mcroute mismatch\n");
goto fail;
}
}
ndev--;
break;
}
prev = pdev;
}
return ndev;
fail:
pci_dev_put(pdev);
return -ENODEV;
}
static u8 get_src_id(struct skx_dev *d)
{
u32 reg;
pci_read_config_dword(d->util_all, 0xF0, &reg);
return GET_BITFIELD(reg, 12, 14);
}
static u8 skx_get_node_id(struct skx_dev *d)
{
u32 reg;
pci_read_config_dword(d->util_all, 0xF4, &reg);
return GET_BITFIELD(reg, 0, 2);
}
static int get_dimm_attr(u32 reg, int lobit, int hibit, int add, int minval,
int maxval, char *name)
{
u32 val = GET_BITFIELD(reg, lobit, hibit);
if (val < minval || val > maxval) {
edac_dbg(2, "bad %s = %d (raw=%x)\n", name, val, reg);
return -EINVAL;
}
return val + add;
}
static int get_width(u32 mtr)
{
switch (GET_BITFIELD(mtr, 8, 9)) {
case 0:
return DEV_X4;
case 1:
return DEV_X8;
case 2:
return DEV_X16;
}
return DEV_UNKNOWN;
}
static int skx_get_hi_lo(void)
{
struct pci_dev *pdev;
u32 reg;
pdev = pci_get_device(PCI_VENDOR_ID_INTEL, 0x2034, NULL);
if (!pdev) {
edac_dbg(0, "Can't get tolm/tohm\n");
return -ENODEV;
}
pci_read_config_dword(pdev, 0xD0, &reg);
skx_tolm = reg;
pci_read_config_dword(pdev, 0xD4, &reg);
skx_tohm = reg;
pci_read_config_dword(pdev, 0xD8, &reg);
skx_tohm |= (u64)reg << 32;
pci_dev_put(pdev);
edac_dbg(2, "tolm=%llx tohm=%llx\n", skx_tolm, skx_tohm);
return 0;
}
static int get_dimm_info(u32 mtr, u32 amap, struct dimm_info *dimm,
struct skx_imc *imc, int chan, int dimmno)
{
int banks = 16, ranks, rows, cols, npages;
u64 size;
if (!IS_DIMM_PRESENT(mtr))
return 0;
ranks = numrank(mtr);
rows = numrow(mtr);
cols = numcol(mtr);
size = ((1ull << (rows + cols + ranks)) * banks) >> (20 - 3);
npages = MiB_TO_PAGES(size);
edac_dbg(0, "mc#%d: channel %d, dimm %d, %lld Mb (%d pages) bank: %d, rank: %d, row: %#x, col: %#x\n",
imc->mc, chan, dimmno, size, npages,
banks, ranks, rows, cols);
imc->chan[chan].dimms[dimmno].close_pg = GET_BITFIELD(mtr, 0, 0);
imc->chan[chan].dimms[dimmno].bank_xor_enable = GET_BITFIELD(mtr, 9, 9);
imc->chan[chan].dimms[dimmno].fine_grain_bank = GET_BITFIELD(amap, 0, 0);
imc->chan[chan].dimms[dimmno].rowbits = rows;
imc->chan[chan].dimms[dimmno].colbits = cols;
dimm->nr_pages = npages;
dimm->grain = 32;
dimm->dtype = get_width(mtr);
dimm->mtype = MEM_DDR4;
dimm->edac_mode = EDAC_SECDED;
snprintf(dimm->label, sizeof(dimm->label), "CPU_SrcID#%u_MC#%u_Chan#%u_DIMM#%u",
imc->src_id, imc->lmc, chan, dimmno);
return 1;
}
static bool skx_check_ecc(struct pci_dev *pdev)
{
u32 mtmtr;
SKX_GET_MTMTR(pdev, mtmtr);
return !!GET_BITFIELD(mtmtr, 2, 2);
}
static int skx_get_dimm_config(struct mem_ctl_info *mci)
{
struct skx_pvt *pvt = mci->pvt_info;
struct skx_imc *imc = pvt->imc;
struct dimm_info *dimm;
int i, j;
u32 mtr, amap;
int ndimms;
for (i = 0; i < NUM_CHANNELS; i++) {
ndimms = 0;
pci_read_config_dword(imc->chan[i].cdev, 0x8C, &amap);
for (j = 0; j < NUM_DIMMS; j++) {
dimm = EDAC_DIMM_PTR(mci->layers, mci->dimms,
mci->n_layers, i, j, 0);
pci_read_config_dword(imc->chan[i].cdev,
0x80 + 4*j, &mtr);
ndimms += get_dimm_info(mtr, amap, dimm, imc, i, j);
}
if (ndimms && !skx_check_ecc(imc->chan[0].cdev)) {
skx_printk(KERN_ERR, "ECC is disabled on imc %d\n", imc->mc);
return -ENODEV;
}
}
return 0;
}
static void skx_unregister_mci(struct skx_imc *imc)
{
struct mem_ctl_info *mci = imc->mci;
if (!mci)
return;
edac_dbg(0, "MC%d: mci = %p\n", imc->mc, mci);
edac_mc_del_mc(mci->pdev);
edac_dbg(1, "%s: free mci struct\n", mci->ctl_name);
kfree(mci->ctl_name);
edac_mc_free(mci);
}
static int skx_register_mci(struct skx_imc *imc)
{
struct mem_ctl_info *mci;
struct edac_mc_layer layers[2];
struct pci_dev *pdev = imc->chan[0].cdev;
struct skx_pvt *pvt;
int rc;
layers[0].type = EDAC_MC_LAYER_CHANNEL;
layers[0].size = NUM_CHANNELS;
layers[0].is_virt_csrow = false;
layers[1].type = EDAC_MC_LAYER_SLOT;
layers[1].size = NUM_DIMMS;
layers[1].is_virt_csrow = true;
mci = edac_mc_alloc(imc->mc, ARRAY_SIZE(layers), layers,
sizeof(struct skx_pvt));
if (unlikely(!mci))
return -ENOMEM;
edac_dbg(0, "MC#%d: mci = %p\n", imc->mc, mci);
imc->mci = mci;
pvt = mci->pvt_info;
pvt->imc = imc;
mci->ctl_name = kasprintf(GFP_KERNEL, "Skylake Socket#%d IMC#%d",
imc->node_id, imc->lmc);
mci->mtype_cap = MEM_FLAG_DDR4;
mci->edac_ctl_cap = EDAC_FLAG_NONE;
mci->edac_cap = EDAC_FLAG_NONE;
mci->mod_name = "skx_edac.c";
mci->dev_name = pci_name(imc->chan[0].cdev);
mci->ctl_page_to_phys = NULL;
rc = skx_get_dimm_config(mci);
if (rc < 0)
goto fail;
mci->pdev = &pdev->dev;
if (unlikely(edac_mc_add_mc(mci))) {
edac_dbg(0, "MC: failed edac_mc_add_mc()\n");
rc = -EINVAL;
goto fail;
}
return 0;
fail:
kfree(mci->ctl_name);
edac_mc_free(mci);
imc->mci = NULL;
return rc;
}
static bool skx_sad_decode(struct decoded_addr *res)
{
struct skx_dev *d = list_first_entry(&skx_edac_list, typeof(*d), list);
u64 addr = res->addr;
int i, idx, tgt, lchan, shift;
u32 sad, ilv;
u64 limit, prev_limit;
int remote = 0;
if (addr >= skx_tohm || (addr >= skx_tolm && addr < BIT_ULL(32))) {
edac_dbg(0, "Address %llx out of range\n", addr);
return false;
}
restart:
prev_limit = 0;
for (i = 0; i < SKX_MAX_SAD; i++) {
SKX_GET_SAD(d, i, sad);
limit = SKX_SAD_LIMIT(sad);
if (SKX_SAD_ENABLE(sad)) {
if (addr >= prev_limit && addr <= limit)
goto sad_found;
}
prev_limit = limit + 1;
}
edac_dbg(0, "No SAD entry for %llx\n", addr);
return false;
sad_found:
SKX_GET_ILV(d, i, ilv);
switch (SKX_SAD_INTERLEAVE(sad)) {
case 0:
idx = GET_BITFIELD(addr, 6, 8);
break;
case 1:
idx = GET_BITFIELD(addr, 8, 10);
break;
case 2:
idx = GET_BITFIELD(addr, 12, 14);
break;
case 3:
idx = GET_BITFIELD(addr, 30, 32);
break;
}
tgt = GET_BITFIELD(ilv, 4 * idx, 4 * idx + 3);
if (SKX_ILV_REMOTE(tgt)) {
if (remote) {
edac_dbg(0, "Double remote!\n");
return false;
}
remote = 1;
list_for_each_entry(d, &skx_edac_list, list) {
if (d->imc[0].src_id == SKX_ILV_TARGET(tgt))
goto restart;
}
edac_dbg(0, "Can't find node %d\n", SKX_ILV_TARGET(tgt));
return false;
}
if (SKX_SAD_MOD3(sad) == 0)
lchan = SKX_ILV_TARGET(tgt);
else {
switch (SKX_SAD_MOD3MODE(sad)) {
case 0:
shift = 6;
break;
case 1:
shift = 8;
break;
case 2:
shift = 12;
break;
default:
edac_dbg(0, "illegal mod3mode\n");
return false;
}
switch (SKX_SAD_MOD3ASMOD2(sad)) {
case 0:
lchan = (addr >> shift) % 3;
break;
case 1:
lchan = (addr >> shift) % 2;
break;
case 2:
lchan = (addr >> shift) % 2;
lchan = (lchan << 1) | ~lchan;
break;
case 3:
lchan = ((addr >> shift) % 2) << 1;
break;
}
lchan = (lchan << 1) | (SKX_ILV_TARGET(tgt) & 1);
}
res->dev = d;
res->socket = d->imc[0].src_id;
res->imc = GET_BITFIELD(d->mcroute, lchan * 3, lchan * 3 + 2);
res->channel = GET_BITFIELD(d->mcroute, lchan * 2 + 18, lchan * 2 + 19);
edac_dbg(2, "%llx: socket=%d imc=%d channel=%d\n",
res->addr, res->socket, res->imc, res->channel);
return true;
}
static u64 skx_do_interleave(u64 addr, int shift, int ways, u64 lowbits)
{
addr >>= shift;
addr /= ways;
addr <<= shift;
return addr | (lowbits & ((1ull << shift) - 1));
}
static bool skx_tad_decode(struct decoded_addr *res)
{
int i;
u32 base, wayness, chnilvoffset;
int skt_interleave_bit, chn_interleave_bit;
u64 channel_addr;
for (i = 0; i < SKX_MAX_TAD; i++) {
SKX_GET_TADBASE(res->dev, res->imc, i, base);
SKX_GET_TADWAYNESS(res->dev, res->imc, i, wayness);
if (SKX_TAD_BASE(base) <= res->addr && res->addr <= SKX_TAD_LIMIT(wayness))
goto tad_found;
}
edac_dbg(0, "No TAD entry for %llx\n", res->addr);
return false;
tad_found:
res->sktways = SKX_TAD_SKTWAYS(wayness);
res->chanways = SKX_TAD_CHNWAYS(wayness);
skt_interleave_bit = skx_granularity[SKX_TAD_SKT_GRAN(base)];
chn_interleave_bit = skx_granularity[SKX_TAD_CHN_GRAN(base)];
SKX_GET_TADCHNILVOFFSET(res->dev, res->imc, res->channel, i, chnilvoffset);
channel_addr = res->addr - SKX_TAD_OFFSET(chnilvoffset);
if (res->chanways == 3 && skt_interleave_bit > chn_interleave_bit) {
channel_addr = skx_do_interleave(channel_addr, chn_interleave_bit,
res->chanways, channel_addr);
channel_addr = skx_do_interleave(channel_addr, skt_interleave_bit,
res->sktways, channel_addr);
} else {
channel_addr = skx_do_interleave(channel_addr, skt_interleave_bit,
res->sktways, res->addr);
channel_addr = skx_do_interleave(channel_addr, chn_interleave_bit,
res->chanways, res->addr);
}
res->chan_addr = channel_addr;
edac_dbg(2, "%llx: chan_addr=%llx sktways=%d chanways=%d\n",
res->addr, res->chan_addr, res->sktways, res->chanways);
return true;
}
static bool skx_rir_decode(struct decoded_addr *res)
{
int i, idx, chan_rank;
int shift;
u32 rirway, rirlv;
u64 rank_addr, prev_limit = 0, limit;
if (res->dev->imc[res->imc].chan[res->channel].dimms[0].close_pg)
shift = 6;
else
shift = 13;
for (i = 0; i < SKX_MAX_RIR; i++) {
SKX_GET_RIRWAYNESS(res->dev, res->imc, res->channel, i, rirway);
limit = SKX_RIR_LIMIT(rirway);
if (SKX_RIR_VALID(rirway)) {
if (prev_limit <= res->chan_addr &&
res->chan_addr <= limit)
goto rir_found;
}
prev_limit = limit;
}
edac_dbg(0, "No RIR entry for %llx\n", res->addr);
return false;
rir_found:
rank_addr = res->chan_addr >> shift;
rank_addr /= SKX_RIR_WAYS(rirway);
rank_addr <<= shift;
rank_addr |= res->chan_addr & GENMASK_ULL(shift - 1, 0);
res->rank_address = rank_addr;
idx = (res->chan_addr >> shift) % SKX_RIR_WAYS(rirway);
SKX_GET_RIRILV(res->dev, res->imc, res->channel, idx, i, rirlv);
res->rank_address = rank_addr - SKX_RIR_OFFSET(rirlv);
chan_rank = SKX_RIR_CHAN_RANK(rirlv);
res->channel_rank = chan_rank;
res->dimm = chan_rank / 4;
res->rank = chan_rank % 4;
edac_dbg(2, "%llx: dimm=%d rank=%d chan_rank=%d rank_addr=%llx\n",
res->addr, res->dimm, res->rank,
res->channel_rank, res->rank_address);
return true;
}
static int skx_bits(u64 addr, int nbits, u8 *bits)
{
int i, res = 0;
for (i = 0; i < nbits; i++)
res |= ((addr >> bits[i]) & 1) << i;
return res;
}
static int skx_bank_bits(u64 addr, int b0, int b1, int do_xor, int x0, int x1)
{
int ret = GET_BITFIELD(addr, b0, b0) | (GET_BITFIELD(addr, b1, b1) << 1);
if (do_xor)
ret ^= GET_BITFIELD(addr, x0, x0) | (GET_BITFIELD(addr, x1, x1) << 1);
return ret;
}
static bool skx_mad_decode(struct decoded_addr *r)
{
struct skx_dimm *dimm = &r->dev->imc[r->imc].chan[r->channel].dimms[r->dimm];
int bg0 = dimm->fine_grain_bank ? 6 : 13;
if (dimm->close_pg) {
r->row = skx_bits(r->rank_address, dimm->rowbits, skx_close_row);
r->column = skx_bits(r->rank_address, dimm->colbits, skx_close_column);
r->column |= 0x400;
r->bank_address = skx_bank_bits(r->rank_address, 8, 9, dimm->bank_xor_enable, 22, 28);
r->bank_group = skx_bank_bits(r->rank_address, 6, 7, dimm->bank_xor_enable, 20, 21);
} else {
r->row = skx_bits(r->rank_address, dimm->rowbits, skx_open_row);
if (dimm->fine_grain_bank)
r->column = skx_bits(r->rank_address, dimm->colbits, skx_open_fine_column);
else
r->column = skx_bits(r->rank_address, dimm->colbits, skx_open_column);
r->bank_address = skx_bank_bits(r->rank_address, 18, 19, dimm->bank_xor_enable, 22, 23);
r->bank_group = skx_bank_bits(r->rank_address, bg0, 17, dimm->bank_xor_enable, 20, 21);
}
r->row &= (1u << dimm->rowbits) - 1;
edac_dbg(2, "%llx: row=%x col=%x bank_addr=%d bank_group=%d\n",
r->addr, r->row, r->column, r->bank_address,
r->bank_group);
return true;
}
static bool skx_decode(struct decoded_addr *res)
{
return skx_sad_decode(res) && skx_tad_decode(res) &&
skx_rir_decode(res) && skx_mad_decode(res);
}
static int debugfs_u64_set(void *data, u64 val)
{
struct decoded_addr res;
res.addr = val;
skx_decode(&res);
return 0;
}
static struct dentry *mydebugfs_create(const char *name, umode_t mode,
struct dentry *parent, u64 *value)
{
return debugfs_create_file(name, mode, parent, value, &fops_u64_wo);
}
static void setup_skx_debug(void)
{
skx_test = debugfs_create_dir("skx_edac_test", NULL);
mydebugfs_create("addr", S_IWUSR, skx_test, &skx_fake_addr);
}
static void teardown_skx_debug(void)
{
debugfs_remove_recursive(skx_test);
}
static void setup_skx_debug(void)
{
}
static void teardown_skx_debug(void)
{
}
static void skx_mce_output_error(struct mem_ctl_info *mci,
const struct mce *m,
struct decoded_addr *res)
{
enum hw_event_mc_err_type tp_event;
char *type, *optype, msg[256];
bool ripv = GET_BITFIELD(m->mcgstatus, 0, 0);
bool overflow = GET_BITFIELD(m->status, 62, 62);
bool uncorrected_error = GET_BITFIELD(m->status, 61, 61);
bool recoverable;
u32 core_err_cnt = GET_BITFIELD(m->status, 38, 52);
u32 mscod = GET_BITFIELD(m->status, 16, 31);
u32 errcode = GET_BITFIELD(m->status, 0, 15);
u32 optypenum = GET_BITFIELD(m->status, 4, 6);
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
snprintf(msg, sizeof(msg),
"%s%s err_code:%04x:%04x socket:%d imc:%d rank:%d bg:%d ba:%d row:%x col:%x",
overflow ? " OVERFLOW" : "",
(uncorrected_error && recoverable) ? " recoverable" : "",
mscod, errcode,
res->socket, res->imc, res->rank,
res->bank_group, res->bank_address, res->row, res->column);
edac_dbg(0, "%s\n", msg);
edac_mc_handle_error(tp_event, mci, core_err_cnt,
m->addr >> PAGE_SHIFT, m->addr & ~PAGE_MASK, 0,
res->channel, res->dimm, -1,
optype, msg);
}
static int skx_mce_check_error(struct notifier_block *nb, unsigned long val,
void *data)
{
struct mce *mce = (struct mce *)data;
struct decoded_addr res;
struct mem_ctl_info *mci;
char *type;
if (edac_get_report_status() == EDAC_REPORTING_DISABLED)
return NOTIFY_DONE;
if ((mce->status & 0xefff) >> 7 != 1 || !(mce->status & MCI_STATUS_ADDRV))
return NOTIFY_DONE;
res.addr = mce->addr;
if (!skx_decode(&res))
return NOTIFY_DONE;
mci = res.dev->imc[res.imc].mci;
if (mce->mcgstatus & MCG_STATUS_MCIP)
type = "Exception";
else
type = "Event";
skx_mc_printk(mci, KERN_DEBUG, "HANDLING MCE MEMORY ERROR\n");
skx_mc_printk(mci, KERN_DEBUG, "CPU %d: Machine Check %s: %Lx "
"Bank %d: %016Lx\n", mce->extcpu, type,
mce->mcgstatus, mce->bank, mce->status);
skx_mc_printk(mci, KERN_DEBUG, "TSC %llx ", mce->tsc);
skx_mc_printk(mci, KERN_DEBUG, "ADDR %llx ", mce->addr);
skx_mc_printk(mci, KERN_DEBUG, "MISC %llx ", mce->misc);
skx_mc_printk(mci, KERN_DEBUG, "PROCESSOR %u:%x TIME %llu SOCKET "
"%u APIC %x\n", mce->cpuvendor, mce->cpuid,
mce->time, mce->socketid, mce->apicid);
skx_mce_output_error(mci, mce, &res);
return NOTIFY_DONE;
}
static void skx_remove(void)
{
int i, j;
struct skx_dev *d, *tmp;
edac_dbg(0, "\n");
list_for_each_entry_safe(d, tmp, &skx_edac_list, list) {
list_del(&d->list);
for (i = 0; i < NUM_IMC; i++) {
skx_unregister_mci(&d->imc[i]);
for (j = 0; j < NUM_CHANNELS; j++)
pci_dev_put(d->imc[i].chan[j].cdev);
}
pci_dev_put(d->util_all);
pci_dev_put(d->sad_all);
kfree(d);
}
}
static int __init skx_init(void)
{
const struct x86_cpu_id *id;
const struct munit *m;
int rc = 0, i;
u8 mc = 0, src_id, node_id;
struct skx_dev *d;
edac_dbg(2, "\n");
id = x86_match_cpu(skx_cpuids);
if (!id)
return -ENODEV;
rc = skx_get_hi_lo();
if (rc)
return rc;
rc = get_all_bus_mappings();
if (rc < 0)
goto fail;
if (rc == 0) {
edac_dbg(2, "No memory controllers found\n");
return -ENODEV;
}
for (m = skx_all_munits; m->did; m++) {
rc = get_all_munits(m);
if (rc < 0)
goto fail;
if (rc != m->per_socket * skx_num_sockets) {
edac_dbg(2, "Expected %d, got %d of %x\n",
m->per_socket * skx_num_sockets, rc, m->did);
rc = -ENODEV;
goto fail;
}
}
list_for_each_entry(d, &skx_edac_list, list) {
src_id = get_src_id(d);
node_id = skx_get_node_id(d);
edac_dbg(2, "src_id=%d node_id=%d\n", src_id, node_id);
for (i = 0; i < NUM_IMC; i++) {
d->imc[i].mc = mc++;
d->imc[i].lmc = i;
d->imc[i].src_id = src_id;
d->imc[i].node_id = node_id;
rc = skx_register_mci(&d->imc[i]);
if (rc < 0)
goto fail;
}
}
opstate_init();
setup_skx_debug();
mce_register_decode_chain(&skx_mce_dec);
return 0;
fail:
skx_remove();
return rc;
}
static void __exit skx_exit(void)
{
edac_dbg(2, "\n");
mce_unregister_decode_chain(&skx_mce_dec);
skx_remove();
teardown_skx_debug();
}
