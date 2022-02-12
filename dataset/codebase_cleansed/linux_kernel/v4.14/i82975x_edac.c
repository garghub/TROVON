static void i82975x_get_error_info(struct mem_ctl_info *mci,
struct i82975x_error_info *info)
{
struct pci_dev *pdev;
pdev = to_pci_dev(mci->pdev);
pci_read_config_word(pdev, I82975X_ERRSTS, &info->errsts);
pci_read_config_dword(pdev, I82975X_EAP, &info->eap);
pci_read_config_byte(pdev, I82975X_XEAP, &info->xeap);
pci_read_config_byte(pdev, I82975X_DES, &info->des);
pci_read_config_byte(pdev, I82975X_DERRSYN, &info->derrsyn);
pci_read_config_word(pdev, I82975X_ERRSTS, &info->errsts2);
pci_write_bits16(pdev, I82975X_ERRSTS, 0x0003, 0x0003);
if (!(info->errsts2 & 0x0003))
return;
if ((info->errsts ^ info->errsts2) & 0x0003) {
pci_read_config_dword(pdev, I82975X_EAP, &info->eap);
pci_read_config_byte(pdev, I82975X_XEAP, &info->xeap);
pci_read_config_byte(pdev, I82975X_DES, &info->des);
pci_read_config_byte(pdev, I82975X_DERRSYN,
&info->derrsyn);
}
}
static int i82975x_process_error_info(struct mem_ctl_info *mci,
struct i82975x_error_info *info, int handle_errors)
{
int row, chan;
unsigned long offst, page;
if (!(info->errsts2 & 0x0003))
return 0;
if (!handle_errors)
return 1;
if ((info->errsts ^ info->errsts2) & 0x0003) {
edac_mc_handle_error(HW_EVENT_ERR_UNCORRECTED, mci, 1, 0, 0, 0,
-1, -1, -1, "UE overwrote CE", "");
info->errsts = info->errsts2;
}
page = (unsigned long) info->eap;
page >>= 1;
if (info->xeap & 1)
page |= 0x80000000;
page >>= (PAGE_SHIFT - 1);
row = edac_mc_find_csrow_by_page(mci, page);
if (row == -1) {
i82975x_mc_printk(mci, KERN_ERR, "error processing EAP:\n"
"\tXEAP=%u\n"
"\t EAP=0x%08x\n"
"\tPAGE=0x%08x\n",
(info->xeap & 1) ? 1 : 0, info->eap, (unsigned int) page);
return 0;
}
chan = (mci->csrows[row]->nr_channels == 1) ? 0 : info->eap & 1;
offst = info->eap
& ((1 << PAGE_SHIFT) -
(1 << mci->csrows[row]->channels[chan]->dimm->grain));
if (info->errsts & 0x0002)
edac_mc_handle_error(HW_EVENT_ERR_UNCORRECTED, mci, 1,
page, offst, 0,
row, -1, -1,
"i82975x UE", "");
else
edac_mc_handle_error(HW_EVENT_ERR_CORRECTED, mci, 1,
page, offst, info->derrsyn,
row, chan ? chan : 0, -1,
"i82975x CE", "");
return 1;
}
static void i82975x_check(struct mem_ctl_info *mci)
{
struct i82975x_error_info info;
edac_dbg(1, "MC%d\n", mci->mc_idx);
i82975x_get_error_info(mci, &info);
i82975x_process_error_info(mci, &info, 1);
}
static int dual_channel_active(void __iomem *mch_window)
{
u8 drb[4][2];
int row;
int dualch;
for (dualch = 1, row = 0; dualch && (row < 4); row++) {
drb[row][0] = readb(mch_window + I82975X_DRB + row);
drb[row][1] = readb(mch_window + I82975X_DRB + row + 0x80);
dualch = dualch && (drb[row][0] == drb[row][1]);
}
return dualch;
}
static enum dev_type i82975x_dram_type(void __iomem *mch_window, int rank)
{
return DEV_X8;
}
static void i82975x_init_csrows(struct mem_ctl_info *mci,
struct pci_dev *pdev, void __iomem *mch_window)
{
struct csrow_info *csrow;
unsigned long last_cumul_size;
u8 value;
u32 cumul_size, nr_pages;
int index, chan;
struct dimm_info *dimm;
enum dev_type dtype;
last_cumul_size = 0;
for (index = 0; index < mci->nr_csrows; index++) {
csrow = mci->csrows[index];
value = readb(mch_window + I82975X_DRB + index +
((index >= 4) ? 0x80 : 0));
cumul_size = value;
cumul_size <<= (I82975X_DRB_SHIFT - PAGE_SHIFT);
if (csrow->nr_channels > 1)
cumul_size <<= 1;
edac_dbg(3, "(%d) cumul_size 0x%x\n", index, cumul_size);
nr_pages = cumul_size - last_cumul_size;
if (!nr_pages)
continue;
dtype = i82975x_dram_type(mch_window, index);
for (chan = 0; chan < csrow->nr_channels; chan++) {
dimm = mci->csrows[index]->channels[chan]->dimm;
dimm->nr_pages = nr_pages / csrow->nr_channels;
snprintf(csrow->channels[chan]->dimm->label, EDAC_MC_LABEL_LEN, "DIMM %c%d",
(chan == 0) ? 'A' : 'B',
index);
dimm->grain = 1 << 7;
dimm->dtype = i82975x_dram_type(mch_window, index);
dimm->mtype = MEM_DDR2;
dimm->edac_mode = EDAC_SECDED;
}
csrow->first_page = last_cumul_size;
csrow->last_page = cumul_size - 1;
last_cumul_size = cumul_size;
}
}
static void i82975x_print_dram_timings(void __iomem *mch_window)
{
static const int caslats[4] = { 5, 4, 3, 6 };
u32 dtreg[2];
dtreg[0] = readl(mch_window + 0x114);
dtreg[1] = readl(mch_window + 0x194);
i82975x_printk(KERN_INFO, "DRAM Timings : Ch0 Ch1\n"
" RAS Active Min = %d %d\n"
" CAS latency = %d %d\n"
" RAS to CAS = %d %d\n"
" RAS precharge = %d %d\n",
(dtreg[0] >> 19 ) & 0x0f,
(dtreg[1] >> 19) & 0x0f,
caslats[(dtreg[0] >> 8) & 0x03],
caslats[(dtreg[1] >> 8) & 0x03],
((dtreg[0] >> 4) & 0x07) + 2,
((dtreg[1] >> 4) & 0x07) + 2,
(dtreg[0] & 0x07) + 2,
(dtreg[1] & 0x07) + 2
);
}
static int i82975x_probe1(struct pci_dev *pdev, int dev_idx)
{
int rc = -ENODEV;
struct mem_ctl_info *mci;
struct edac_mc_layer layers[2];
struct i82975x_pvt *pvt;
void __iomem *mch_window;
u32 mchbar;
u32 drc[2];
struct i82975x_error_info discard;
int chans;
#ifdef i82975x_DEBUG_IOMEM
u8 c0drb[4];
u8 c1drb[4];
#endif
edac_dbg(0, "\n");
pci_read_config_dword(pdev, I82975X_MCHBAR, &mchbar);
if (!(mchbar & 1)) {
edac_dbg(3, "failed, MCHBAR disabled!\n");
goto fail0;
}
mchbar &= 0xffffc000;
mch_window = ioremap_nocache(mchbar, 0x1000);
if (!mch_window) {
edac_dbg(3, "error ioremapping MCHBAR!\n");
goto fail0;
}
#ifdef i82975x_DEBUG_IOMEM
i82975x_printk(KERN_INFO, "MCHBAR real = %0x, remapped = %p\n",
mchbar, mch_window);
c0drb[0] = readb(mch_window + I82975X_DRB_CH0R0);
c0drb[1] = readb(mch_window + I82975X_DRB_CH0R1);
c0drb[2] = readb(mch_window + I82975X_DRB_CH0R2);
c0drb[3] = readb(mch_window + I82975X_DRB_CH0R3);
c1drb[0] = readb(mch_window + I82975X_DRB_CH1R0);
c1drb[1] = readb(mch_window + I82975X_DRB_CH1R1);
c1drb[2] = readb(mch_window + I82975X_DRB_CH1R2);
c1drb[3] = readb(mch_window + I82975X_DRB_CH1R3);
i82975x_printk(KERN_INFO, "DRBCH0R0 = 0x%02x\n", c0drb[0]);
i82975x_printk(KERN_INFO, "DRBCH0R1 = 0x%02x\n", c0drb[1]);
i82975x_printk(KERN_INFO, "DRBCH0R2 = 0x%02x\n", c0drb[2]);
i82975x_printk(KERN_INFO, "DRBCH0R3 = 0x%02x\n", c0drb[3]);
i82975x_printk(KERN_INFO, "DRBCH1R0 = 0x%02x\n", c1drb[0]);
i82975x_printk(KERN_INFO, "DRBCH1R1 = 0x%02x\n", c1drb[1]);
i82975x_printk(KERN_INFO, "DRBCH1R2 = 0x%02x\n", c1drb[2]);
i82975x_printk(KERN_INFO, "DRBCH1R3 = 0x%02x\n", c1drb[3]);
#endif
drc[0] = readl(mch_window + I82975X_DRC_CH0M0);
drc[1] = readl(mch_window + I82975X_DRC_CH1M0);
#ifdef i82975x_DEBUG_IOMEM
i82975x_printk(KERN_INFO, "DRC_CH0 = %0x, %s\n", drc[0],
((drc[0] >> 21) & 3) == 1 ?
"ECC enabled" : "ECC disabled");
i82975x_printk(KERN_INFO, "DRC_CH1 = %0x, %s\n", drc[1],
((drc[1] >> 21) & 3) == 1 ?
"ECC enabled" : "ECC disabled");
i82975x_printk(KERN_INFO, "C0 BNKARC = %0x\n",
readw(mch_window + I82975X_C0BNKARC));
i82975x_printk(KERN_INFO, "C1 BNKARC = %0x\n",
readw(mch_window + I82975X_C1BNKARC));
i82975x_print_dram_timings(mch_window);
goto fail1;
#endif
if (!(((drc[0] >> 21) & 3) == 1 || ((drc[1] >> 21) & 3) == 1)) {
i82975x_printk(KERN_INFO, "ECC disabled on both channels.\n");
goto fail1;
}
chans = dual_channel_active(mch_window) + 1;
layers[0].type = EDAC_MC_LAYER_CHIP_SELECT;
layers[0].size = I82975X_NR_DIMMS;
layers[0].is_virt_csrow = true;
layers[1].type = EDAC_MC_LAYER_CHANNEL;
layers[1].size = I82975X_NR_CSROWS(chans);
layers[1].is_virt_csrow = false;
mci = edac_mc_alloc(0, ARRAY_SIZE(layers), layers, sizeof(*pvt));
if (!mci) {
rc = -ENOMEM;
goto fail1;
}
edac_dbg(3, "init mci\n");
mci->pdev = &pdev->dev;
mci->mtype_cap = MEM_FLAG_DDR2;
mci->edac_ctl_cap = EDAC_FLAG_NONE | EDAC_FLAG_SECDED;
mci->edac_cap = EDAC_FLAG_NONE | EDAC_FLAG_SECDED;
mci->mod_name = EDAC_MOD_STR;
mci->ctl_name = i82975x_devs[dev_idx].ctl_name;
mci->dev_name = pci_name(pdev);
mci->edac_check = i82975x_check;
mci->ctl_page_to_phys = NULL;
edac_dbg(3, "init pvt\n");
pvt = (struct i82975x_pvt *) mci->pvt_info;
pvt->mch_window = mch_window;
i82975x_init_csrows(mci, pdev, mch_window);
mci->scrub_mode = SCRUB_HW_SRC;
i82975x_get_error_info(mci, &discard);
if (edac_mc_add_mc(mci)) {
edac_dbg(3, "failed edac_mc_add_mc()\n");
goto fail2;
}
edac_dbg(3, "success\n");
return 0;
fail2:
edac_mc_free(mci);
fail1:
iounmap(mch_window);
fail0:
return rc;
}
static int i82975x_init_one(struct pci_dev *pdev,
const struct pci_device_id *ent)
{
int rc;
edac_dbg(0, "\n");
if (pci_enable_device(pdev) < 0)
return -EIO;
rc = i82975x_probe1(pdev, ent->driver_data);
if (mci_pdev == NULL)
mci_pdev = pci_dev_get(pdev);
return rc;
}
static void i82975x_remove_one(struct pci_dev *pdev)
{
struct mem_ctl_info *mci;
struct i82975x_pvt *pvt;
edac_dbg(0, "\n");
mci = edac_mc_del_mc(&pdev->dev);
if (mci == NULL)
return;
pvt = mci->pvt_info;
if (pvt->mch_window)
iounmap( pvt->mch_window );
edac_mc_free(mci);
}
static int __init i82975x_init(void)
{
int pci_rc;
edac_dbg(3, "\n");
opstate_init();
pci_rc = pci_register_driver(&i82975x_driver);
if (pci_rc < 0)
goto fail0;
if (mci_pdev == NULL) {
mci_pdev = pci_get_device(PCI_VENDOR_ID_INTEL,
PCI_DEVICE_ID_INTEL_82975_0, NULL);
if (!mci_pdev) {
edac_dbg(0, "i82975x pci_get_device fail\n");
pci_rc = -ENODEV;
goto fail1;
}
pci_rc = i82975x_init_one(mci_pdev, i82975x_pci_tbl);
if (pci_rc < 0) {
edac_dbg(0, "i82975x init fail\n");
pci_rc = -ENODEV;
goto fail1;
}
}
return 0;
fail1:
pci_unregister_driver(&i82975x_driver);
fail0:
pci_dev_put(mci_pdev);
return pci_rc;
}
static void __exit i82975x_exit(void)
{
edac_dbg(3, "\n");
pci_unregister_driver(&i82975x_driver);
if (!i82975x_registered) {
i82975x_remove_one(mci_pdev);
pci_dev_put(mci_pdev);
}
}
