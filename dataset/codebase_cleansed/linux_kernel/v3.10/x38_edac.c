static int how_many_channel(struct pci_dev *pdev)
{
unsigned char capid0_8b;
pci_read_config_byte(pdev, X38_CAPID0 + 8, &capid0_8b);
if (capid0_8b & 0x20) {
edac_dbg(0, "In single channel mode\n");
x38_channel_num = 1;
} else {
edac_dbg(0, "In dual channel mode\n");
x38_channel_num = 2;
}
return x38_channel_num;
}
static unsigned long eccerrlog_syndrome(u64 log)
{
return (log & X38_ECCERRLOG_SYNDROME_BITS) >> 16;
}
static int eccerrlog_row(int channel, u64 log)
{
return ((log & X38_ECCERRLOG_RANK_BITS) >> 27) |
(channel * X38_RANKS_PER_CHANNEL);
}
static void x38_clear_error_info(struct mem_ctl_info *mci)
{
struct pci_dev *pdev;
pdev = to_pci_dev(mci->pdev);
pci_write_bits16(pdev, X38_ERRSTS, X38_ERRSTS_BITS,
X38_ERRSTS_BITS);
}
static u64 x38_readq(const void __iomem *addr)
{
return readl(addr) | (((u64)readl(addr + 4)) << 32);
}
static void x38_get_and_clear_error_info(struct mem_ctl_info *mci,
struct x38_error_info *info)
{
struct pci_dev *pdev;
void __iomem *window = mci->pvt_info;
pdev = to_pci_dev(mci->pdev);
pci_read_config_word(pdev, X38_ERRSTS, &info->errsts);
if (!(info->errsts & X38_ERRSTS_BITS))
return;
info->eccerrlog[0] = x38_readq(window + X38_C0ECCERRLOG);
if (x38_channel_num == 2)
info->eccerrlog[1] = x38_readq(window + X38_C1ECCERRLOG);
pci_read_config_word(pdev, X38_ERRSTS, &info->errsts2);
if ((info->errsts ^ info->errsts2) & X38_ERRSTS_BITS) {
info->eccerrlog[0] = x38_readq(window + X38_C0ECCERRLOG);
if (x38_channel_num == 2)
info->eccerrlog[1] =
x38_readq(window + X38_C1ECCERRLOG);
}
x38_clear_error_info(mci);
}
static void x38_process_error_info(struct mem_ctl_info *mci,
struct x38_error_info *info)
{
int channel;
u64 log;
if (!(info->errsts & X38_ERRSTS_BITS))
return;
if ((info->errsts ^ info->errsts2) & X38_ERRSTS_BITS) {
edac_mc_handle_error(HW_EVENT_ERR_UNCORRECTED, mci, 1, 0, 0, 0,
-1, -1, -1,
"UE overwrote CE", "");
info->errsts = info->errsts2;
}
for (channel = 0; channel < x38_channel_num; channel++) {
log = info->eccerrlog[channel];
if (log & X38_ECCERRLOG_UE) {
edac_mc_handle_error(HW_EVENT_ERR_UNCORRECTED, mci, 1,
0, 0, 0,
eccerrlog_row(channel, log),
-1, -1,
"x38 UE", "");
} else if (log & X38_ECCERRLOG_CE) {
edac_mc_handle_error(HW_EVENT_ERR_CORRECTED, mci, 1,
0, 0, eccerrlog_syndrome(log),
eccerrlog_row(channel, log),
-1, -1,
"x38 CE", "");
}
}
}
static void x38_check(struct mem_ctl_info *mci)
{
struct x38_error_info info;
edac_dbg(1, "MC%d\n", mci->mc_idx);
x38_get_and_clear_error_info(mci, &info);
x38_process_error_info(mci, &info);
}
void __iomem *x38_map_mchbar(struct pci_dev *pdev)
{
union {
u64 mchbar;
struct {
u32 mchbar_low;
u32 mchbar_high;
};
} u;
void __iomem *window;
pci_read_config_dword(pdev, X38_MCHBAR_LOW, &u.mchbar_low);
pci_write_config_dword(pdev, X38_MCHBAR_LOW, u.mchbar_low | 0x1);
pci_read_config_dword(pdev, X38_MCHBAR_HIGH, &u.mchbar_high);
u.mchbar &= X38_MCHBAR_MASK;
if (u.mchbar != (resource_size_t)u.mchbar) {
printk(KERN_ERR
"x38: mmio space beyond accessible range (0x%llx)\n",
(unsigned long long)u.mchbar);
return NULL;
}
window = ioremap_nocache(u.mchbar, X38_MMR_WINDOW_SIZE);
if (!window)
printk(KERN_ERR "x38: cannot map mmio space at 0x%llx\n",
(unsigned long long)u.mchbar);
return window;
}
static void x38_get_drbs(void __iomem *window,
u16 drbs[X38_CHANNELS][X38_RANKS_PER_CHANNEL])
{
int i;
for (i = 0; i < X38_RANKS_PER_CHANNEL; i++) {
drbs[0][i] = readw(window + X38_C0DRB + 2*i) & X38_DRB_MASK;
drbs[1][i] = readw(window + X38_C1DRB + 2*i) & X38_DRB_MASK;
}
}
static bool x38_is_stacked(struct pci_dev *pdev,
u16 drbs[X38_CHANNELS][X38_RANKS_PER_CHANNEL])
{
u16 tom;
pci_read_config_word(pdev, X38_TOM, &tom);
tom &= X38_TOM_MASK;
return drbs[X38_CHANNELS - 1][X38_RANKS_PER_CHANNEL - 1] == tom;
}
static unsigned long drb_to_nr_pages(
u16 drbs[X38_CHANNELS][X38_RANKS_PER_CHANNEL],
bool stacked, int channel, int rank)
{
int n;
n = drbs[channel][rank];
if (rank > 0)
n -= drbs[channel][rank - 1];
if (stacked && (channel == 1) && drbs[channel][rank] ==
drbs[channel][X38_RANKS_PER_CHANNEL - 1]) {
n -= drbs[0][X38_RANKS_PER_CHANNEL - 1];
}
n <<= (X38_DRB_SHIFT - PAGE_SHIFT);
return n;
}
static int x38_probe1(struct pci_dev *pdev, int dev_idx)
{
int rc;
int i, j;
struct mem_ctl_info *mci = NULL;
struct edac_mc_layer layers[2];
u16 drbs[X38_CHANNELS][X38_RANKS_PER_CHANNEL];
bool stacked;
void __iomem *window;
edac_dbg(0, "MC:\n");
window = x38_map_mchbar(pdev);
if (!window)
return -ENODEV;
x38_get_drbs(window, drbs);
how_many_channel(pdev);
layers[0].type = EDAC_MC_LAYER_CHIP_SELECT;
layers[0].size = X38_RANKS;
layers[0].is_virt_csrow = true;
layers[1].type = EDAC_MC_LAYER_CHANNEL;
layers[1].size = x38_channel_num;
layers[1].is_virt_csrow = false;
mci = edac_mc_alloc(0, ARRAY_SIZE(layers), layers, 0);
if (!mci)
return -ENOMEM;
edac_dbg(3, "MC: init mci\n");
mci->pdev = &pdev->dev;
mci->mtype_cap = MEM_FLAG_DDR2;
mci->edac_ctl_cap = EDAC_FLAG_SECDED;
mci->edac_cap = EDAC_FLAG_SECDED;
mci->mod_name = EDAC_MOD_STR;
mci->mod_ver = X38_REVISION;
mci->ctl_name = x38_devs[dev_idx].ctl_name;
mci->dev_name = pci_name(pdev);
mci->edac_check = x38_check;
mci->ctl_page_to_phys = NULL;
mci->pvt_info = window;
stacked = x38_is_stacked(pdev, drbs);
for (i = 0; i < mci->nr_csrows; i++) {
unsigned long nr_pages;
struct csrow_info *csrow = mci->csrows[i];
nr_pages = drb_to_nr_pages(drbs, stacked,
i / X38_RANKS_PER_CHANNEL,
i % X38_RANKS_PER_CHANNEL);
if (nr_pages == 0)
continue;
for (j = 0; j < x38_channel_num; j++) {
struct dimm_info *dimm = csrow->channels[j]->dimm;
dimm->nr_pages = nr_pages / x38_channel_num;
dimm->grain = nr_pages << PAGE_SHIFT;
dimm->mtype = MEM_DDR2;
dimm->dtype = DEV_UNKNOWN;
dimm->edac_mode = EDAC_UNKNOWN;
}
}
x38_clear_error_info(mci);
rc = -ENODEV;
if (edac_mc_add_mc(mci)) {
edac_dbg(3, "MC: failed edac_mc_add_mc()\n");
goto fail;
}
edac_dbg(3, "MC: success\n");
return 0;
fail:
iounmap(window);
if (mci)
edac_mc_free(mci);
return rc;
}
static int x38_init_one(struct pci_dev *pdev, const struct pci_device_id *ent)
{
int rc;
edac_dbg(0, "MC:\n");
if (pci_enable_device(pdev) < 0)
return -EIO;
rc = x38_probe1(pdev, ent->driver_data);
if (!mci_pdev)
mci_pdev = pci_dev_get(pdev);
return rc;
}
static void x38_remove_one(struct pci_dev *pdev)
{
struct mem_ctl_info *mci;
edac_dbg(0, "\n");
mci = edac_mc_del_mc(&pdev->dev);
if (!mci)
return;
iounmap(mci->pvt_info);
edac_mc_free(mci);
}
static int __init x38_init(void)
{
int pci_rc;
edac_dbg(3, "MC:\n");
opstate_init();
pci_rc = pci_register_driver(&x38_driver);
if (pci_rc < 0)
goto fail0;
if (!mci_pdev) {
x38_registered = 0;
mci_pdev = pci_get_device(PCI_VENDOR_ID_INTEL,
PCI_DEVICE_ID_INTEL_X38_HB, NULL);
if (!mci_pdev) {
edac_dbg(0, "x38 pci_get_device fail\n");
pci_rc = -ENODEV;
goto fail1;
}
pci_rc = x38_init_one(mci_pdev, x38_pci_tbl);
if (pci_rc < 0) {
edac_dbg(0, "x38 init fail\n");
pci_rc = -ENODEV;
goto fail1;
}
}
return 0;
fail1:
pci_unregister_driver(&x38_driver);
fail0:
if (mci_pdev)
pci_dev_put(mci_pdev);
return pci_rc;
}
static void __exit x38_exit(void)
{
edac_dbg(3, "MC:\n");
pci_unregister_driver(&x38_driver);
if (!x38_registered) {
x38_remove_one(mci_pdev);
pci_dev_put(mci_pdev);
}
}
