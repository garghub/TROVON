static inline u32 i5100_mc_scrben(u32 mc)
{
return mc >> 7 & 1;
}
static inline u32 i5100_mc_errdeten(u32 mc)
{
return mc >> 5 & 1;
}
static inline u32 i5100_mc_scrbdone(u32 mc)
{
return mc >> 4 & 1;
}
static inline u16 i5100_spddata_rdo(u16 a)
{
return a >> 15 & 1;
}
static inline u16 i5100_spddata_sbe(u16 a)
{
return a >> 13 & 1;
}
static inline u16 i5100_spddata_busy(u16 a)
{
return a >> 12 & 1;
}
static inline u16 i5100_spddata_data(u16 a)
{
return a & ((1 << 8) - 1);
}
static inline u32 i5100_spdcmd_create(u32 dti, u32 ckovrd, u32 sa, u32 ba,
u32 data, u32 cmd)
{
return ((dti & ((1 << 4) - 1)) << 28) |
((ckovrd & 1) << 27) |
((sa & ((1 << 3) - 1)) << 24) |
((ba & ((1 << 8) - 1)) << 16) |
((data & ((1 << 8) - 1)) << 8) |
(cmd & 1);
}
static inline u16 i5100_tolm_tolm(u16 a)
{
return a >> 12 & ((1 << 4) - 1);
}
static inline u16 i5100_mir_limit(u16 a)
{
return a >> 4 & ((1 << 12) - 1);
}
static inline u16 i5100_mir_way1(u16 a)
{
return a >> 1 & 1;
}
static inline u16 i5100_mir_way0(u16 a)
{
return a & 1;
}
static inline u32 i5100_ferr_nf_mem_chan_indx(u32 a)
{
return a >> 28 & 1;
}
static inline u32 i5100_ferr_nf_mem_any(u32 a)
{
return a & I5100_FERR_NF_MEM_ANY_MASK;
}
static inline u32 i5100_nerr_nf_mem_any(u32 a)
{
return i5100_ferr_nf_mem_any(a);
}
static inline u32 i5100_dmir_limit(u32 a)
{
return a >> 16 & ((1 << 11) - 1);
}
static inline u32 i5100_dmir_rank(u32 a, u32 i)
{
return a >> (4 * i) & ((1 << 2) - 1);
}
static inline u16 i5100_mtr_present(u16 a)
{
return a >> 10 & 1;
}
static inline u16 i5100_mtr_ethrottle(u16 a)
{
return a >> 9 & 1;
}
static inline u16 i5100_mtr_width(u16 a)
{
return a >> 8 & 1;
}
static inline u16 i5100_mtr_numbank(u16 a)
{
return a >> 6 & 1;
}
static inline u16 i5100_mtr_numrow(u16 a)
{
return a >> 2 & ((1 << 2) - 1);
}
static inline u16 i5100_mtr_numcol(u16 a)
{
return a & ((1 << 2) - 1);
}
static inline u32 i5100_validlog_redmemvalid(u32 a)
{
return a >> 2 & 1;
}
static inline u32 i5100_validlog_recmemvalid(u32 a)
{
return a >> 1 & 1;
}
static inline u32 i5100_validlog_nrecmemvalid(u32 a)
{
return a & 1;
}
static inline u32 i5100_nrecmema_merr(u32 a)
{
return a >> 15 & ((1 << 5) - 1);
}
static inline u32 i5100_nrecmema_bank(u32 a)
{
return a >> 12 & ((1 << 3) - 1);
}
static inline u32 i5100_nrecmema_rank(u32 a)
{
return a >> 8 & ((1 << 3) - 1);
}
static inline u32 i5100_nrecmema_dm_buf_id(u32 a)
{
return a & ((1 << 8) - 1);
}
static inline u32 i5100_nrecmemb_cas(u32 a)
{
return a >> 16 & ((1 << 13) - 1);
}
static inline u32 i5100_nrecmemb_ras(u32 a)
{
return a & ((1 << 16) - 1);
}
static inline u32 i5100_redmemb_ecc_locator(u32 a)
{
return a & ((1 << 18) - 1);
}
static inline u32 i5100_recmema_merr(u32 a)
{
return i5100_nrecmema_merr(a);
}
static inline u32 i5100_recmema_bank(u32 a)
{
return i5100_nrecmema_bank(a);
}
static inline u32 i5100_recmema_rank(u32 a)
{
return i5100_nrecmema_rank(a);
}
static inline u32 i5100_recmema_dm_buf_id(u32 a)
{
return i5100_nrecmema_dm_buf_id(a);
}
static inline u32 i5100_recmemb_cas(u32 a)
{
return i5100_nrecmemb_cas(a);
}
static inline u32 i5100_recmemb_ras(u32 a)
{
return i5100_nrecmemb_ras(a);
}
static int i5100_rank_to_slot(const struct mem_ctl_info *mci,
int chan, int rank)
{
const struct i5100_priv *priv = mci->pvt_info;
int i;
for (i = 0; i < I5100_MAX_DIMM_SLOTS_PER_CHAN; i++) {
int j;
const int numrank = priv->dimm_numrank[chan][i];
for (j = 0; j < numrank; j++)
if (priv->dimm_csmap[i][j] == rank)
return i * 2 + chan;
}
return -1;
}
static const char *i5100_err_msg(unsigned err)
{
static const char *merrs[] = {
"unknown",
"uncorrectable data ECC on replay",
"unknown",
"unknown",
"aliased uncorrectable demand data ECC",
"aliased uncorrectable spare-copy data ECC",
"aliased uncorrectable patrol data ECC",
"unknown",
"unknown",
"unknown",
"non-aliased uncorrectable demand data ECC",
"non-aliased uncorrectable spare-copy data ECC",
"non-aliased uncorrectable patrol data ECC",
"unknown",
"correctable demand data ECC",
"correctable spare-copy data ECC",
"correctable patrol data ECC",
"unknown",
"SPD protocol error",
"unknown",
"spare copy initiated",
"spare copy completed",
};
unsigned i;
for (i = 0; i < ARRAY_SIZE(merrs); i++)
if (1 << i & err)
return merrs[i];
return "none";
}
static int i5100_csrow_to_rank(const struct mem_ctl_info *mci, int csrow)
{
const struct i5100_priv *priv = mci->pvt_info;
return csrow % priv->ranksperchan;
}
static int i5100_csrow_to_chan(const struct mem_ctl_info *mci, int csrow)
{
const struct i5100_priv *priv = mci->pvt_info;
return csrow / priv->ranksperchan;
}
static void i5100_handle_ce(struct mem_ctl_info *mci,
int chan,
unsigned bank,
unsigned rank,
unsigned long syndrome,
unsigned cas,
unsigned ras,
const char *msg)
{
char detail[80];
snprintf(detail, sizeof(detail),
"bank %u, cas %u, ras %u\n",
bank, cas, ras);
edac_mc_handle_error(HW_EVENT_ERR_CORRECTED, mci, 1,
0, 0, syndrome,
chan, rank, -1,
msg, detail);
}
static void i5100_handle_ue(struct mem_ctl_info *mci,
int chan,
unsigned bank,
unsigned rank,
unsigned long syndrome,
unsigned cas,
unsigned ras,
const char *msg)
{
char detail[80];
snprintf(detail, sizeof(detail),
"bank %u, cas %u, ras %u\n",
bank, cas, ras);
edac_mc_handle_error(HW_EVENT_ERR_UNCORRECTED, mci, 1,
0, 0, syndrome,
chan, rank, -1,
msg, detail);
}
static void i5100_read_log(struct mem_ctl_info *mci, int chan,
u32 ferr, u32 nerr)
{
struct i5100_priv *priv = mci->pvt_info;
struct pci_dev *pdev = (chan) ? priv->ch1mm : priv->ch0mm;
u32 dw;
u32 dw2;
unsigned syndrome = 0;
unsigned ecc_loc = 0;
unsigned merr;
unsigned bank;
unsigned rank;
unsigned cas;
unsigned ras;
pci_read_config_dword(pdev, I5100_VALIDLOG, &dw);
if (i5100_validlog_redmemvalid(dw)) {
pci_read_config_dword(pdev, I5100_REDMEMA, &dw2);
syndrome = dw2;
pci_read_config_dword(pdev, I5100_REDMEMB, &dw2);
ecc_loc = i5100_redmemb_ecc_locator(dw2);
}
if (i5100_validlog_recmemvalid(dw)) {
const char *msg;
pci_read_config_dword(pdev, I5100_RECMEMA, &dw2);
merr = i5100_recmema_merr(dw2);
bank = i5100_recmema_bank(dw2);
rank = i5100_recmema_rank(dw2);
pci_read_config_dword(pdev, I5100_RECMEMB, &dw2);
cas = i5100_recmemb_cas(dw2);
ras = i5100_recmemb_ras(dw2);
if (!merr)
msg = i5100_err_msg(ferr);
else
msg = i5100_err_msg(nerr);
i5100_handle_ce(mci, chan, bank, rank, syndrome, cas, ras, msg);
}
if (i5100_validlog_nrecmemvalid(dw)) {
const char *msg;
pci_read_config_dword(pdev, I5100_NRECMEMA, &dw2);
merr = i5100_nrecmema_merr(dw2);
bank = i5100_nrecmema_bank(dw2);
rank = i5100_nrecmema_rank(dw2);
pci_read_config_dword(pdev, I5100_NRECMEMB, &dw2);
cas = i5100_nrecmemb_cas(dw2);
ras = i5100_nrecmemb_ras(dw2);
if (!merr)
msg = i5100_err_msg(ferr);
else
msg = i5100_err_msg(nerr);
i5100_handle_ue(mci, chan, bank, rank, syndrome, cas, ras, msg);
}
pci_write_config_dword(pdev, I5100_VALIDLOG, dw);
}
static void i5100_check_error(struct mem_ctl_info *mci)
{
struct i5100_priv *priv = mci->pvt_info;
u32 dw, dw2;
pci_read_config_dword(priv->mc, I5100_FERR_NF_MEM, &dw);
if (i5100_ferr_nf_mem_any(dw)) {
pci_read_config_dword(priv->mc, I5100_NERR_NF_MEM, &dw2);
i5100_read_log(mci, i5100_ferr_nf_mem_chan_indx(dw),
i5100_ferr_nf_mem_any(dw),
i5100_nerr_nf_mem_any(dw2));
pci_write_config_dword(priv->mc, I5100_NERR_NF_MEM, dw2);
}
pci_write_config_dword(priv->mc, I5100_FERR_NF_MEM, dw);
}
static void i5100_refresh_scrubbing(struct work_struct *work)
{
struct delayed_work *i5100_scrubbing = container_of(work,
struct delayed_work,
work);
struct i5100_priv *priv = container_of(i5100_scrubbing,
struct i5100_priv,
i5100_scrubbing);
u32 dw;
pci_read_config_dword(priv->mc, I5100_MC, &dw);
if (priv->scrub_enable) {
pci_read_config_dword(priv->mc, I5100_MC, &dw);
if (i5100_mc_scrbdone(dw)) {
dw |= I5100_MC_SCRBEN_MASK;
pci_write_config_dword(priv->mc, I5100_MC, dw);
pci_read_config_dword(priv->mc, I5100_MC, &dw);
}
schedule_delayed_work(&(priv->i5100_scrubbing),
I5100_SCRUB_REFRESH_RATE);
}
}
static int i5100_set_scrub_rate(struct mem_ctl_info *mci, u32 bandwidth)
{
struct i5100_priv *priv = mci->pvt_info;
u32 dw;
pci_read_config_dword(priv->mc, I5100_MC, &dw);
if (bandwidth) {
priv->scrub_enable = 1;
dw |= I5100_MC_SCRBEN_MASK;
schedule_delayed_work(&(priv->i5100_scrubbing),
I5100_SCRUB_REFRESH_RATE);
} else {
priv->scrub_enable = 0;
dw &= ~I5100_MC_SCRBEN_MASK;
cancel_delayed_work(&(priv->i5100_scrubbing));
}
pci_write_config_dword(priv->mc, I5100_MC, dw);
pci_read_config_dword(priv->mc, I5100_MC, &dw);
bandwidth = 5900000 * i5100_mc_scrben(dw);
return bandwidth;
}
static int i5100_get_scrub_rate(struct mem_ctl_info *mci)
{
struct i5100_priv *priv = mci->pvt_info;
u32 dw;
pci_read_config_dword(priv->mc, I5100_MC, &dw);
return 5900000 * i5100_mc_scrben(dw);
}
static struct pci_dev *pci_get_device_func(unsigned vendor,
unsigned device,
unsigned func)
{
struct pci_dev *ret = NULL;
while (1) {
ret = pci_get_device(vendor, device, ret);
if (!ret)
break;
if (PCI_FUNC(ret->devfn) == func)
break;
}
return ret;
}
static unsigned long i5100_npages(struct mem_ctl_info *mci, int csrow)
{
struct i5100_priv *priv = mci->pvt_info;
const unsigned chan_rank = i5100_csrow_to_rank(mci, csrow);
const unsigned chan = i5100_csrow_to_chan(mci, csrow);
unsigned addr_lines;
if (!priv->mtr[chan][chan_rank].present)
return 0ULL;
addr_lines =
I5100_DIMM_ADDR_LINES +
priv->mtr[chan][chan_rank].numcol +
priv->mtr[chan][chan_rank].numrow +
priv->mtr[chan][chan_rank].numbank;
return (unsigned long)
((unsigned long long) (1ULL << addr_lines) / PAGE_SIZE);
}
static void i5100_init_mtr(struct mem_ctl_info *mci)
{
struct i5100_priv *priv = mci->pvt_info;
struct pci_dev *mms[2] = { priv->ch0mm, priv->ch1mm };
int i;
for (i = 0; i < I5100_CHANNELS; i++) {
int j;
struct pci_dev *pdev = mms[i];
for (j = 0; j < I5100_MAX_RANKS_PER_CHAN; j++) {
const unsigned addr =
(j < 4) ? I5100_MTR_0 + j * 2 :
I5100_MTR_4 + (j - 4) * 2;
u16 w;
pci_read_config_word(pdev, addr, &w);
priv->mtr[i][j].present = i5100_mtr_present(w);
priv->mtr[i][j].ethrottle = i5100_mtr_ethrottle(w);
priv->mtr[i][j].width = 4 + 4 * i5100_mtr_width(w);
priv->mtr[i][j].numbank = 2 + i5100_mtr_numbank(w);
priv->mtr[i][j].numrow = 13 + i5100_mtr_numrow(w);
priv->mtr[i][j].numcol = 10 + i5100_mtr_numcol(w);
}
}
}
static int i5100_read_spd_byte(const struct mem_ctl_info *mci,
u8 ch, u8 slot, u8 addr, u8 *byte)
{
struct i5100_priv *priv = mci->pvt_info;
u16 w;
unsigned long et;
pci_read_config_word(priv->mc, I5100_SPDDATA, &w);
if (i5100_spddata_busy(w))
return -1;
pci_write_config_dword(priv->mc, I5100_SPDCMD,
i5100_spdcmd_create(0xa, 1, ch * 4 + slot, addr,
0, 0));
et = jiffies + HZ / 10;
udelay(100);
while (1) {
pci_read_config_word(priv->mc, I5100_SPDDATA, &w);
if (!i5100_spddata_busy(w))
break;
udelay(100);
}
if (!i5100_spddata_rdo(w) || i5100_spddata_sbe(w))
return -1;
*byte = i5100_spddata_data(w);
return 0;
}
static void i5100_init_dimm_csmap(struct mem_ctl_info *mci)
{
struct i5100_priv *priv = mci->pvt_info;
int i;
for (i = 0; i < I5100_MAX_DIMM_SLOTS_PER_CHAN; i++) {
int j;
for (j = 0; j < I5100_MAX_RANKS_PER_DIMM; j++)
priv->dimm_csmap[i][j] = -1;
}
if (priv->ranksperchan == 4) {
priv->dimm_csmap[0][0] = 0;
priv->dimm_csmap[0][1] = 3;
priv->dimm_csmap[1][0] = 1;
priv->dimm_csmap[1][1] = 2;
priv->dimm_csmap[2][0] = 2;
priv->dimm_csmap[3][0] = 3;
} else {
priv->dimm_csmap[0][0] = 0;
priv->dimm_csmap[0][1] = 1;
priv->dimm_csmap[1][0] = 2;
priv->dimm_csmap[1][1] = 3;
priv->dimm_csmap[2][0] = 4;
priv->dimm_csmap[2][1] = 5;
}
}
static void i5100_init_dimm_layout(struct pci_dev *pdev,
struct mem_ctl_info *mci)
{
struct i5100_priv *priv = mci->pvt_info;
int i;
for (i = 0; i < I5100_CHANNELS; i++) {
int j;
for (j = 0; j < I5100_MAX_DIMM_SLOTS_PER_CHAN; j++) {
u8 rank;
if (i5100_read_spd_byte(mci, i, j, 5, &rank) < 0)
priv->dimm_numrank[i][j] = 0;
else
priv->dimm_numrank[i][j] = (rank & 3) + 1;
}
}
i5100_init_dimm_csmap(mci);
}
static void i5100_init_interleaving(struct pci_dev *pdev,
struct mem_ctl_info *mci)
{
u16 w;
u32 dw;
struct i5100_priv *priv = mci->pvt_info;
struct pci_dev *mms[2] = { priv->ch0mm, priv->ch1mm };
int i;
pci_read_config_word(pdev, I5100_TOLM, &w);
priv->tolm = (u64) i5100_tolm_tolm(w) * 256 * 1024 * 1024;
pci_read_config_word(pdev, I5100_MIR0, &w);
priv->mir[0].limit = (u64) i5100_mir_limit(w) << 28;
priv->mir[0].way[1] = i5100_mir_way1(w);
priv->mir[0].way[0] = i5100_mir_way0(w);
pci_read_config_word(pdev, I5100_MIR1, &w);
priv->mir[1].limit = (u64) i5100_mir_limit(w) << 28;
priv->mir[1].way[1] = i5100_mir_way1(w);
priv->mir[1].way[0] = i5100_mir_way0(w);
pci_read_config_word(pdev, I5100_AMIR_0, &w);
priv->amir[0] = w;
pci_read_config_word(pdev, I5100_AMIR_1, &w);
priv->amir[1] = w;
for (i = 0; i < I5100_CHANNELS; i++) {
int j;
for (j = 0; j < 5; j++) {
int k;
pci_read_config_dword(mms[i], I5100_DMIR + j * 4, &dw);
priv->dmir[i][j].limit =
(u64) i5100_dmir_limit(dw) << 28;
for (k = 0; k < I5100_MAX_RANKS_PER_DIMM; k++)
priv->dmir[i][j].rank[k] =
i5100_dmir_rank(dw, k);
}
}
i5100_init_mtr(mci);
}
static void i5100_init_csrows(struct mem_ctl_info *mci)
{
int i;
struct i5100_priv *priv = mci->pvt_info;
for (i = 0; i < mci->tot_dimms; i++) {
struct dimm_info *dimm;
const unsigned long npages = i5100_npages(mci, i);
const unsigned chan = i5100_csrow_to_chan(mci, i);
const unsigned rank = i5100_csrow_to_rank(mci, i);
if (!npages)
continue;
dimm = EDAC_DIMM_PTR(mci->layers, mci->dimms, mci->n_layers,
chan, rank, 0);
dimm->nr_pages = npages;
dimm->grain = 32;
dimm->dtype = (priv->mtr[chan][rank].width == 4) ?
DEV_X4 : DEV_X8;
dimm->mtype = MEM_RDDR2;
dimm->edac_mode = EDAC_SECDED;
snprintf(dimm->label, sizeof(dimm->label), "DIMM%u",
i5100_rank_to_slot(mci, chan, rank));
edac_dbg(2, "dimm channel %d, rank %d, size %ld\n",
chan, rank, (long)PAGES_TO_MiB(npages));
}
}
static void i5100_do_inject(struct mem_ctl_info *mci)
{
struct i5100_priv *priv = mci->pvt_info;
u32 mask0;
u16 mask1;
mask0 = ((priv->inject_hlinesel & 0x3) << 28) |
I5100_MEMXEINJMSK0_EINJEN |
((priv->inject_eccmask1 & 0xffff) << 10) |
((priv->inject_deviceptr2 & 0x1f) << 5) |
(priv->inject_deviceptr1 & 0x1f);
mask1 = priv->inject_eccmask2;
if (priv->inject_channel == 0) {
pci_write_config_dword(priv->mc, I5100_MEM0EINJMSK0, mask0);
pci_write_config_word(priv->mc, I5100_MEM0EINJMSK1, mask1);
} else {
pci_write_config_dword(priv->mc, I5100_MEM1EINJMSK0, mask0);
pci_write_config_word(priv->mc, I5100_MEM1EINJMSK1, mask1);
}
pci_write_config_byte(priv->einj, I5100_DINJ0, 0xaa);
pci_write_config_byte(priv->einj, I5100_DINJ0, 0xab);
}
static ssize_t inject_enable_write(struct file *file, const char __user *data,
size_t count, loff_t *ppos)
{
struct device *dev = file->private_data;
struct mem_ctl_info *mci = to_mci(dev);
i5100_do_inject(mci);
return count;
}
static int i5100_setup_debugfs(struct mem_ctl_info *mci)
{
struct i5100_priv *priv = mci->pvt_info;
if (!i5100_debugfs)
return -ENODEV;
priv->debugfs = debugfs_create_dir(mci->bus->name, i5100_debugfs);
if (!priv->debugfs)
return -ENOMEM;
debugfs_create_x8("inject_channel", S_IRUGO | S_IWUSR, priv->debugfs,
&priv->inject_channel);
debugfs_create_x8("inject_hlinesel", S_IRUGO | S_IWUSR, priv->debugfs,
&priv->inject_hlinesel);
debugfs_create_x8("inject_deviceptr1", S_IRUGO | S_IWUSR, priv->debugfs,
&priv->inject_deviceptr1);
debugfs_create_x8("inject_deviceptr2", S_IRUGO | S_IWUSR, priv->debugfs,
&priv->inject_deviceptr2);
debugfs_create_x16("inject_eccmask1", S_IRUGO | S_IWUSR, priv->debugfs,
&priv->inject_eccmask1);
debugfs_create_x16("inject_eccmask2", S_IRUGO | S_IWUSR, priv->debugfs,
&priv->inject_eccmask2);
debugfs_create_file("inject_enable", S_IWUSR, priv->debugfs,
&mci->dev, &i5100_inject_enable_fops);
return 0;
}
static int i5100_init_one(struct pci_dev *pdev, const struct pci_device_id *id)
{
int rc;
struct mem_ctl_info *mci;
struct edac_mc_layer layers[2];
struct i5100_priv *priv;
struct pci_dev *ch0mm, *ch1mm, *einj;
int ret = 0;
u32 dw;
int ranksperch;
if (PCI_FUNC(pdev->devfn) != 1)
return -ENODEV;
rc = pci_enable_device(pdev);
if (rc < 0) {
ret = rc;
goto bail;
}
pci_read_config_dword(pdev, I5100_MC, &dw);
if (!i5100_mc_errdeten(dw)) {
printk(KERN_INFO "i5100_edac: ECC not enabled.\n");
ret = -ENODEV;
goto bail_pdev;
}
pci_read_config_dword(pdev, I5100_MS, &dw);
ranksperch = !!(dw & (1 << 8)) * 2 + 4;
pci_read_config_dword(pdev, I5100_EMASK_MEM, &dw);
dw &= ~I5100_FERR_NF_MEM_ANY_MASK;
pci_write_config_dword(pdev, I5100_EMASK_MEM, dw);
ch0mm = pci_get_device_func(PCI_VENDOR_ID_INTEL,
PCI_DEVICE_ID_INTEL_5100_21, 0);
if (!ch0mm) {
ret = -ENODEV;
goto bail_pdev;
}
rc = pci_enable_device(ch0mm);
if (rc < 0) {
ret = rc;
goto bail_ch0;
}
ch1mm = pci_get_device_func(PCI_VENDOR_ID_INTEL,
PCI_DEVICE_ID_INTEL_5100_22, 0);
if (!ch1mm) {
ret = -ENODEV;
goto bail_disable_ch0;
}
rc = pci_enable_device(ch1mm);
if (rc < 0) {
ret = rc;
goto bail_ch1;
}
layers[0].type = EDAC_MC_LAYER_CHANNEL;
layers[0].size = 2;
layers[0].is_virt_csrow = false;
layers[1].type = EDAC_MC_LAYER_SLOT;
layers[1].size = ranksperch;
layers[1].is_virt_csrow = true;
mci = edac_mc_alloc(0, ARRAY_SIZE(layers), layers,
sizeof(*priv));
if (!mci) {
ret = -ENOMEM;
goto bail_disable_ch1;
}
einj = pci_get_device_func(PCI_VENDOR_ID_INTEL,
PCI_DEVICE_ID_INTEL_5100_19, 0);
if (!einj) {
ret = -ENODEV;
goto bail_einj;
}
rc = pci_enable_device(einj);
if (rc < 0) {
ret = rc;
goto bail_disable_einj;
}
mci->pdev = &pdev->dev;
priv = mci->pvt_info;
priv->ranksperchan = ranksperch;
priv->mc = pdev;
priv->ch0mm = ch0mm;
priv->ch1mm = ch1mm;
priv->einj = einj;
INIT_DELAYED_WORK(&(priv->i5100_scrubbing), i5100_refresh_scrubbing);
pci_read_config_dword(pdev, I5100_MC, &dw);
if (i5100_mc_scrben(dw)) {
priv->scrub_enable = 1;
schedule_delayed_work(&(priv->i5100_scrubbing),
I5100_SCRUB_REFRESH_RATE);
}
i5100_init_dimm_layout(pdev, mci);
i5100_init_interleaving(pdev, mci);
mci->mtype_cap = MEM_FLAG_FB_DDR2;
mci->edac_ctl_cap = EDAC_FLAG_SECDED;
mci->edac_cap = EDAC_FLAG_SECDED;
mci->mod_name = "i5100_edac.c";
mci->mod_ver = "not versioned";
mci->ctl_name = "i5100";
mci->dev_name = pci_name(pdev);
mci->ctl_page_to_phys = NULL;
mci->edac_check = i5100_check_error;
mci->set_sdram_scrub_rate = i5100_set_scrub_rate;
mci->get_sdram_scrub_rate = i5100_get_scrub_rate;
priv->inject_channel = 0;
priv->inject_hlinesel = 0;
priv->inject_deviceptr1 = 0;
priv->inject_deviceptr2 = 0;
priv->inject_eccmask1 = 0;
priv->inject_eccmask2 = 0;
i5100_init_csrows(mci);
switch (edac_op_state) {
case EDAC_OPSTATE_POLL:
case EDAC_OPSTATE_NMI:
break;
default:
edac_op_state = EDAC_OPSTATE_POLL;
break;
}
if (edac_mc_add_mc(mci)) {
ret = -ENODEV;
goto bail_scrub;
}
i5100_setup_debugfs(mci);
return ret;
bail_scrub:
priv->scrub_enable = 0;
cancel_delayed_work_sync(&(priv->i5100_scrubbing));
edac_mc_free(mci);
bail_disable_einj:
pci_disable_device(einj);
bail_einj:
pci_dev_put(einj);
bail_disable_ch1:
pci_disable_device(ch1mm);
bail_ch1:
pci_dev_put(ch1mm);
bail_disable_ch0:
pci_disable_device(ch0mm);
bail_ch0:
pci_dev_put(ch0mm);
bail_pdev:
pci_disable_device(pdev);
bail:
return ret;
}
static void i5100_remove_one(struct pci_dev *pdev)
{
struct mem_ctl_info *mci;
struct i5100_priv *priv;
mci = edac_mc_del_mc(&pdev->dev);
if (!mci)
return;
priv = mci->pvt_info;
debugfs_remove_recursive(priv->debugfs);
priv->scrub_enable = 0;
cancel_delayed_work_sync(&(priv->i5100_scrubbing));
pci_disable_device(pdev);
pci_disable_device(priv->ch0mm);
pci_disable_device(priv->ch1mm);
pci_disable_device(priv->einj);
pci_dev_put(priv->ch0mm);
pci_dev_put(priv->ch1mm);
pci_dev_put(priv->einj);
edac_mc_free(mci);
}
static int __init i5100_init(void)
{
int pci_rc;
i5100_debugfs = debugfs_create_dir("i5100_edac", NULL);
pci_rc = pci_register_driver(&i5100_driver);
return (pci_rc < 0) ? pci_rc : 0;
}
static void __exit i5100_exit(void)
{
debugfs_remove(i5100_debugfs);
pci_unregister_driver(&i5100_driver);
}
