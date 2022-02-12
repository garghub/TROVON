static int how_many_channels(struct pci_dev *pdev)
{
int n_channels;
unsigned char capid0_2b;
pci_read_config_byte(pdev, IE31200_CAPID0 + 1, &capid0_2b);
if (capid0_2b & IE31200_CAPID0_PDCD) {
edac_dbg(0, "In single channel mode\n");
n_channels = 1;
} else {
edac_dbg(0, "In dual channel mode\n");
n_channels = 2;
}
if (capid0_2b & IE31200_CAPID0_DDPCD)
edac_dbg(0, "2 DIMMS per channel disabled\n");
else
edac_dbg(0, "2 DIMMS per channel enabled\n");
return n_channels;
}
static bool ecc_capable(struct pci_dev *pdev)
{
unsigned char capid0_4b;
pci_read_config_byte(pdev, IE31200_CAPID0 + 3, &capid0_4b);
if (capid0_4b & IE31200_CAPID0_ECC)
return false;
return true;
}
static int eccerrlog_row(u64 log)
{
return ((log & IE31200_ECCERRLOG_RANK_BITS) >>
IE31200_ECCERRLOG_RANK_SHIFT);
}
static void ie31200_clear_error_info(struct mem_ctl_info *mci)
{
pci_write_bits16(to_pci_dev(mci->pdev), IE31200_ERRSTS,
IE31200_ERRSTS_BITS, IE31200_ERRSTS_BITS);
}
static void ie31200_get_and_clear_error_info(struct mem_ctl_info *mci,
struct ie31200_error_info *info)
{
struct pci_dev *pdev;
struct ie31200_priv *priv = mci->pvt_info;
pdev = to_pci_dev(mci->pdev);
pci_read_config_word(pdev, IE31200_ERRSTS, &info->errsts);
if (!(info->errsts & IE31200_ERRSTS_BITS))
return;
info->eccerrlog[0] = lo_hi_readq(priv->c0errlog);
if (nr_channels == 2)
info->eccerrlog[1] = lo_hi_readq(priv->c1errlog);
pci_read_config_word(pdev, IE31200_ERRSTS, &info->errsts2);
if ((info->errsts ^ info->errsts2) & IE31200_ERRSTS_BITS) {
info->eccerrlog[0] = lo_hi_readq(priv->c0errlog);
if (nr_channels == 2)
info->eccerrlog[1] =
lo_hi_readq(priv->c1errlog);
}
ie31200_clear_error_info(mci);
}
static void ie31200_process_error_info(struct mem_ctl_info *mci,
struct ie31200_error_info *info)
{
int channel;
u64 log;
if (!(info->errsts & IE31200_ERRSTS_BITS))
return;
if ((info->errsts ^ info->errsts2) & IE31200_ERRSTS_BITS) {
edac_mc_handle_error(HW_EVENT_ERR_UNCORRECTED, mci, 1, 0, 0, 0,
-1, -1, -1, "UE overwrote CE", "");
info->errsts = info->errsts2;
}
for (channel = 0; channel < nr_channels; channel++) {
log = info->eccerrlog[channel];
if (log & IE31200_ECCERRLOG_UE) {
edac_mc_handle_error(HW_EVENT_ERR_UNCORRECTED, mci, 1,
0, 0, 0,
eccerrlog_row(log),
channel, -1,
"ie31200 UE", "");
} else if (log & IE31200_ECCERRLOG_CE) {
edac_mc_handle_error(HW_EVENT_ERR_CORRECTED, mci, 1,
0, 0,
IE31200_ECCERRLOG_SYNDROME(log),
eccerrlog_row(log),
channel, -1,
"ie31200 CE", "");
}
}
}
static void ie31200_check(struct mem_ctl_info *mci)
{
struct ie31200_error_info info;
edac_dbg(1, "MC%d\n", mci->mc_idx);
ie31200_get_and_clear_error_info(mci, &info);
ie31200_process_error_info(mci, &info);
}
static void __iomem *ie31200_map_mchbar(struct pci_dev *pdev)
{
union {
u64 mchbar;
struct {
u32 mchbar_low;
u32 mchbar_high;
};
} u;
void __iomem *window;
pci_read_config_dword(pdev, IE31200_MCHBAR_LOW, &u.mchbar_low);
pci_read_config_dword(pdev, IE31200_MCHBAR_HIGH, &u.mchbar_high);
u.mchbar &= IE31200_MCHBAR_MASK;
if (u.mchbar != (resource_size_t)u.mchbar) {
ie31200_printk(KERN_ERR, "mmio space beyond accessible range (0x%llx)\n",
(unsigned long long)u.mchbar);
return NULL;
}
window = ioremap_nocache(u.mchbar, IE31200_MMR_WINDOW_SIZE);
if (!window)
ie31200_printk(KERN_ERR, "Cannot map mmio space at 0x%llx\n",
(unsigned long long)u.mchbar);
return window;
}
static void __skl_populate_dimm_info(struct dimm_data *dd, u32 addr_decode,
int chan)
{
dd->size = (addr_decode >> (chan << 4)) & IE31200_MAD_DIMM_SIZE;
dd->dual_rank = (addr_decode & (IE31200_MAD_DIMM_A_RANK_SKL << (chan << 4))) ? 1 : 0;
dd->x16_width = ((addr_decode & (IE31200_MAD_DIMM_A_WIDTH_SKL << (chan << 4))) >>
(IE31200_MAD_DIMM_A_WIDTH_SKL_SHIFT + (chan << 4)));
}
static void __populate_dimm_info(struct dimm_data *dd, u32 addr_decode,
int chan)
{
dd->size = (addr_decode >> (chan << 3)) & IE31200_MAD_DIMM_SIZE;
dd->dual_rank = (addr_decode & (IE31200_MAD_DIMM_A_RANK << chan)) ? 1 : 0;
dd->x16_width = (addr_decode & (IE31200_MAD_DIMM_A_WIDTH << chan)) ? 1 : 0;
}
static void populate_dimm_info(struct dimm_data *dd, u32 addr_decode, int chan,
bool skl)
{
if (skl)
__skl_populate_dimm_info(dd, addr_decode, chan);
else
__populate_dimm_info(dd, addr_decode, chan);
}
static int ie31200_probe1(struct pci_dev *pdev, int dev_idx)
{
int i, j, ret;
struct mem_ctl_info *mci = NULL;
struct edac_mc_layer layers[2];
struct dimm_data dimm_info[IE31200_CHANNELS][IE31200_DIMMS_PER_CHANNEL];
void __iomem *window;
struct ie31200_priv *priv;
u32 addr_decode, mad_offset;
bool skl = (pdev->device == PCI_DEVICE_ID_INTEL_IE31200_HB_8);
edac_dbg(0, "MC:\n");
if (!ecc_capable(pdev)) {
ie31200_printk(KERN_INFO, "No ECC support\n");
return -ENODEV;
}
nr_channels = how_many_channels(pdev);
layers[0].type = EDAC_MC_LAYER_CHIP_SELECT;
layers[0].size = IE31200_DIMMS;
layers[0].is_virt_csrow = true;
layers[1].type = EDAC_MC_LAYER_CHANNEL;
layers[1].size = nr_channels;
layers[1].is_virt_csrow = false;
mci = edac_mc_alloc(0, ARRAY_SIZE(layers), layers,
sizeof(struct ie31200_priv));
if (!mci)
return -ENOMEM;
window = ie31200_map_mchbar(pdev);
if (!window) {
ret = -ENODEV;
goto fail_free;
}
edac_dbg(3, "MC: init mci\n");
mci->pdev = &pdev->dev;
if (skl)
mci->mtype_cap = MEM_FLAG_DDR4;
else
mci->mtype_cap = MEM_FLAG_DDR3;
mci->edac_ctl_cap = EDAC_FLAG_SECDED;
mci->edac_cap = EDAC_FLAG_SECDED;
mci->mod_name = EDAC_MOD_STR;
mci->mod_ver = IE31200_REVISION;
mci->ctl_name = ie31200_devs[dev_idx].ctl_name;
mci->dev_name = pci_name(pdev);
mci->edac_check = ie31200_check;
mci->ctl_page_to_phys = NULL;
priv = mci->pvt_info;
priv->window = window;
if (skl) {
priv->c0errlog = window + IE31200_C0ECCERRLOG_SKL;
priv->c1errlog = window + IE31200_C1ECCERRLOG_SKL;
mad_offset = IE31200_MAD_DIMM_0_OFFSET_SKL;
} else {
priv->c0errlog = window + IE31200_C0ECCERRLOG;
priv->c1errlog = window + IE31200_C1ECCERRLOG;
mad_offset = IE31200_MAD_DIMM_0_OFFSET;
}
for (i = 0; i < IE31200_CHANNELS; i++) {
addr_decode = readl(window + mad_offset +
(i * 4));
edac_dbg(0, "addr_decode: 0x%x\n", addr_decode);
for (j = 0; j < IE31200_DIMMS_PER_CHANNEL; j++) {
populate_dimm_info(&dimm_info[i][j], addr_decode, j,
skl);
edac_dbg(0, "size: 0x%x, rank: %d, width: %d\n",
dimm_info[i][j].size,
dimm_info[i][j].dual_rank,
dimm_info[i][j].x16_width);
}
}
for (i = 0; i < IE31200_DIMMS_PER_CHANNEL; i++) {
for (j = 0; j < IE31200_CHANNELS; j++) {
struct dimm_info *dimm;
unsigned long nr_pages;
nr_pages = IE31200_PAGES(dimm_info[j][i].size, skl);
if (nr_pages == 0)
continue;
if (dimm_info[j][i].dual_rank) {
nr_pages = nr_pages / 2;
dimm = EDAC_DIMM_PTR(mci->layers, mci->dimms,
mci->n_layers, (i * 2) + 1,
j, 0);
dimm->nr_pages = nr_pages;
edac_dbg(0, "set nr pages: 0x%lx\n", nr_pages);
dimm->grain = 8;
if (skl)
dimm->mtype = MEM_DDR4;
else
dimm->mtype = MEM_DDR3;
dimm->dtype = DEV_UNKNOWN;
dimm->edac_mode = EDAC_UNKNOWN;
}
dimm = EDAC_DIMM_PTR(mci->layers, mci->dimms,
mci->n_layers, i * 2, j, 0);
dimm->nr_pages = nr_pages;
edac_dbg(0, "set nr pages: 0x%lx\n", nr_pages);
dimm->grain = 8;
if (skl)
dimm->mtype = MEM_DDR4;
else
dimm->mtype = MEM_DDR3;
dimm->dtype = DEV_UNKNOWN;
dimm->edac_mode = EDAC_UNKNOWN;
}
}
ie31200_clear_error_info(mci);
if (edac_mc_add_mc(mci)) {
edac_dbg(3, "MC: failed edac_mc_add_mc()\n");
ret = -ENODEV;
goto fail_unmap;
}
edac_dbg(3, "MC: success\n");
return 0;
fail_unmap:
iounmap(window);
fail_free:
edac_mc_free(mci);
return ret;
}
static int ie31200_init_one(struct pci_dev *pdev,
const struct pci_device_id *ent)
{
edac_dbg(0, "MC:\n");
if (pci_enable_device(pdev) < 0)
return -EIO;
return ie31200_probe1(pdev, ent->driver_data);
}
static void ie31200_remove_one(struct pci_dev *pdev)
{
struct mem_ctl_info *mci;
struct ie31200_priv *priv;
edac_dbg(0, "\n");
mci = edac_mc_del_mc(&pdev->dev);
if (!mci)
return;
priv = mci->pvt_info;
iounmap(priv->window);
edac_mc_free(mci);
}
static int __init ie31200_init(void)
{
edac_dbg(3, "MC:\n");
opstate_init();
return pci_register_driver(&ie31200_driver);
}
static void __exit ie31200_exit(void)
{
edac_dbg(3, "MC:\n");
pci_unregister_driver(&ie31200_driver);
}
