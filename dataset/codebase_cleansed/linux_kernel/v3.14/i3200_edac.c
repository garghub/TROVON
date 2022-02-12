static int how_many_channels(struct pci_dev *pdev)
{
int n_channels;
unsigned char capid0_8b;
pci_read_config_byte(pdev, I3200_CAPID0 + 8, &capid0_8b);
if (capid0_8b & 0x20) {
edac_dbg(0, "In single channel mode\n");
n_channels = 1;
} else {
edac_dbg(0, "In dual channel mode\n");
n_channels = 2;
}
if (capid0_8b & 0x10)
edac_dbg(0, "2 DIMMS per channel disabled\n");
else
edac_dbg(0, "2 DIMMS per channel enabled\n");
return n_channels;
}
static unsigned long eccerrlog_syndrome(u64 log)
{
return (log & I3200_ECCERRLOG_SYNDROME_BITS) >>
I3200_ECCERRLOG_SYNDROME_SHIFT;
}
static int eccerrlog_row(int channel, u64 log)
{
u64 rank = ((log & I3200_ECCERRLOG_RANK_BITS) >>
I3200_ECCERRLOG_RANK_SHIFT);
return rank | (channel * I3200_RANKS_PER_CHANNEL);
}
static void i3200_clear_error_info(struct mem_ctl_info *mci)
{
struct pci_dev *pdev;
pdev = to_pci_dev(mci->pdev);
pci_write_bits16(pdev, I3200_ERRSTS, I3200_ERRSTS_BITS,
I3200_ERRSTS_BITS);
}
static void i3200_get_and_clear_error_info(struct mem_ctl_info *mci,
struct i3200_error_info *info)
{
struct pci_dev *pdev;
struct i3200_priv *priv = mci->pvt_info;
void __iomem *window = priv->window;
pdev = to_pci_dev(mci->pdev);
pci_read_config_word(pdev, I3200_ERRSTS, &info->errsts);
if (!(info->errsts & I3200_ERRSTS_BITS))
return;
info->eccerrlog[0] = readq(window + I3200_C0ECCERRLOG);
if (nr_channels == 2)
info->eccerrlog[1] = readq(window + I3200_C1ECCERRLOG);
pci_read_config_word(pdev, I3200_ERRSTS, &info->errsts2);
if ((info->errsts ^ info->errsts2) & I3200_ERRSTS_BITS) {
info->eccerrlog[0] = readq(window + I3200_C0ECCERRLOG);
if (nr_channels == 2)
info->eccerrlog[1] = readq(window + I3200_C1ECCERRLOG);
}
i3200_clear_error_info(mci);
}
static void i3200_process_error_info(struct mem_ctl_info *mci,
struct i3200_error_info *info)
{
int channel;
u64 log;
if (!(info->errsts & I3200_ERRSTS_BITS))
return;
if ((info->errsts ^ info->errsts2) & I3200_ERRSTS_BITS) {
edac_mc_handle_error(HW_EVENT_ERR_UNCORRECTED, mci, 1, 0, 0, 0,
-1, -1, -1, "UE overwrote CE", "");
info->errsts = info->errsts2;
}
for (channel = 0; channel < nr_channels; channel++) {
log = info->eccerrlog[channel];
if (log & I3200_ECCERRLOG_UE) {
edac_mc_handle_error(HW_EVENT_ERR_UNCORRECTED, mci, 1,
0, 0, 0,
eccerrlog_row(channel, log),
-1, -1,
"i3000 UE", "");
} else if (log & I3200_ECCERRLOG_CE) {
edac_mc_handle_error(HW_EVENT_ERR_UNCORRECTED, mci, 1,
0, 0, eccerrlog_syndrome(log),
eccerrlog_row(channel, log),
-1, -1,
"i3000 UE", "");
}
}
}
static void i3200_check(struct mem_ctl_info *mci)
{
struct i3200_error_info info;
edac_dbg(1, "MC%d\n", mci->mc_idx);
i3200_get_and_clear_error_info(mci, &info);
i3200_process_error_info(mci, &info);
}
static void __iomem *i3200_map_mchbar(struct pci_dev *pdev)
{
union {
u64 mchbar;
struct {
u32 mchbar_low;
u32 mchbar_high;
};
} u;
void __iomem *window;
pci_read_config_dword(pdev, I3200_MCHBAR_LOW, &u.mchbar_low);
pci_read_config_dword(pdev, I3200_MCHBAR_HIGH, &u.mchbar_high);
u.mchbar &= I3200_MCHBAR_MASK;
if (u.mchbar != (resource_size_t)u.mchbar) {
printk(KERN_ERR
"i3200: mmio space beyond accessible range (0x%llx)\n",
(unsigned long long)u.mchbar);
return NULL;
}
window = ioremap_nocache(u.mchbar, I3200_MMR_WINDOW_SIZE);
if (!window)
printk(KERN_ERR "i3200: cannot map mmio space at 0x%llx\n",
(unsigned long long)u.mchbar);
return window;
}
static void i3200_get_drbs(void __iomem *window,
u16 drbs[I3200_CHANNELS][I3200_RANKS_PER_CHANNEL])
{
int i;
for (i = 0; i < I3200_RANKS_PER_CHANNEL; i++) {
drbs[0][i] = readw(window + I3200_C0DRB + 2*i) & I3200_DRB_MASK;
drbs[1][i] = readw(window + I3200_C1DRB + 2*i) & I3200_DRB_MASK;
edac_dbg(0, "drb[0][%d] = %d, drb[1][%d] = %d\n", i, drbs[0][i], i, drbs[1][i]);
}
}
static bool i3200_is_stacked(struct pci_dev *pdev,
u16 drbs[I3200_CHANNELS][I3200_RANKS_PER_CHANNEL])
{
u16 tom;
pci_read_config_word(pdev, I3200_TOM, &tom);
tom &= I3200_TOM_MASK;
return drbs[I3200_CHANNELS - 1][I3200_RANKS_PER_CHANNEL - 1] == tom;
}
static unsigned long drb_to_nr_pages(
u16 drbs[I3200_CHANNELS][I3200_RANKS_PER_CHANNEL], bool stacked,
int channel, int rank)
{
int n;
n = drbs[channel][rank];
if (!n)
return 0;
if (rank > 0)
n -= drbs[channel][rank - 1];
if (stacked && (channel == 1) &&
drbs[channel][rank] == drbs[channel][I3200_RANKS_PER_CHANNEL - 1])
n -= drbs[0][I3200_RANKS_PER_CHANNEL - 1];
n <<= (I3200_DRB_SHIFT - PAGE_SHIFT);
return n;
}
static int i3200_probe1(struct pci_dev *pdev, int dev_idx)
{
int rc;
int i, j;
struct mem_ctl_info *mci = NULL;
struct edac_mc_layer layers[2];
u16 drbs[I3200_CHANNELS][I3200_RANKS_PER_CHANNEL];
bool stacked;
void __iomem *window;
struct i3200_priv *priv;
edac_dbg(0, "MC:\n");
window = i3200_map_mchbar(pdev);
if (!window)
return -ENODEV;
i3200_get_drbs(window, drbs);
nr_channels = how_many_channels(pdev);
layers[0].type = EDAC_MC_LAYER_CHIP_SELECT;
layers[0].size = I3200_DIMMS;
layers[0].is_virt_csrow = true;
layers[1].type = EDAC_MC_LAYER_CHANNEL;
layers[1].size = nr_channels;
layers[1].is_virt_csrow = false;
mci = edac_mc_alloc(0, ARRAY_SIZE(layers), layers,
sizeof(struct i3200_priv));
if (!mci)
return -ENOMEM;
edac_dbg(3, "MC: init mci\n");
mci->pdev = &pdev->dev;
mci->mtype_cap = MEM_FLAG_DDR2;
mci->edac_ctl_cap = EDAC_FLAG_SECDED;
mci->edac_cap = EDAC_FLAG_SECDED;
mci->mod_name = EDAC_MOD_STR;
mci->mod_ver = I3200_REVISION;
mci->ctl_name = i3200_devs[dev_idx].ctl_name;
mci->dev_name = pci_name(pdev);
mci->edac_check = i3200_check;
mci->ctl_page_to_phys = NULL;
priv = mci->pvt_info;
priv->window = window;
stacked = i3200_is_stacked(pdev, drbs);
for (i = 0; i < I3200_DIMMS; i++) {
unsigned long nr_pages;
for (j = 0; j < nr_channels; j++) {
struct dimm_info *dimm = EDAC_DIMM_PTR(mci->layers, mci->dimms,
mci->n_layers, i, j, 0);
nr_pages = drb_to_nr_pages(drbs, stacked, j, i);
if (nr_pages == 0)
continue;
edac_dbg(0, "csrow %d, channel %d%s, size = %ld Mb\n", i, j,
stacked ? " (stacked)" : "", PAGES_TO_MiB(nr_pages));
dimm->nr_pages = nr_pages;
dimm->grain = nr_pages << PAGE_SHIFT;
dimm->mtype = MEM_DDR2;
dimm->dtype = DEV_UNKNOWN;
dimm->edac_mode = EDAC_UNKNOWN;
}
}
i3200_clear_error_info(mci);
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
static int i3200_init_one(struct pci_dev *pdev, const struct pci_device_id *ent)
{
int rc;
edac_dbg(0, "MC:\n");
if (pci_enable_device(pdev) < 0)
return -EIO;
rc = i3200_probe1(pdev, ent->driver_data);
if (!mci_pdev)
mci_pdev = pci_dev_get(pdev);
return rc;
}
static void i3200_remove_one(struct pci_dev *pdev)
{
struct mem_ctl_info *mci;
struct i3200_priv *priv;
edac_dbg(0, "\n");
mci = edac_mc_del_mc(&pdev->dev);
if (!mci)
return;
priv = mci->pvt_info;
iounmap(priv->window);
edac_mc_free(mci);
}
static int __init i3200_init(void)
{
int pci_rc;
edac_dbg(3, "MC:\n");
opstate_init();
pci_rc = pci_register_driver(&i3200_driver);
if (pci_rc < 0)
goto fail0;
if (!mci_pdev) {
i3200_registered = 0;
mci_pdev = pci_get_device(PCI_VENDOR_ID_INTEL,
PCI_DEVICE_ID_INTEL_3200_HB, NULL);
if (!mci_pdev) {
edac_dbg(0, "i3200 pci_get_device fail\n");
pci_rc = -ENODEV;
goto fail1;
}
pci_rc = i3200_init_one(mci_pdev, i3200_pci_tbl);
if (pci_rc < 0) {
edac_dbg(0, "i3200 init fail\n");
pci_rc = -ENODEV;
goto fail1;
}
}
return 0;
fail1:
pci_unregister_driver(&i3200_driver);
fail0:
if (mci_pdev)
pci_dev_put(mci_pdev);
return pci_rc;
}
static void __exit i3200_exit(void)
{
edac_dbg(3, "MC:\n");
pci_unregister_driver(&i3200_driver);
if (!i3200_registered) {
i3200_remove_one(mci_pdev);
pci_dev_put(mci_pdev);
}
}
