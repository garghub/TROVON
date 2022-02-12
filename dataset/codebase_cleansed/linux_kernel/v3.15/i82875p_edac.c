static void i82875p_get_error_info(struct mem_ctl_info *mci,
struct i82875p_error_info *info)
{
struct pci_dev *pdev;
pdev = to_pci_dev(mci->pdev);
pci_read_config_word(pdev, I82875P_ERRSTS, &info->errsts);
if (!(info->errsts & 0x0081))
return;
pci_read_config_dword(pdev, I82875P_EAP, &info->eap);
pci_read_config_byte(pdev, I82875P_DES, &info->des);
pci_read_config_byte(pdev, I82875P_DERRSYN, &info->derrsyn);
pci_read_config_word(pdev, I82875P_ERRSTS, &info->errsts2);
if ((info->errsts ^ info->errsts2) & 0x0081) {
pci_read_config_dword(pdev, I82875P_EAP, &info->eap);
pci_read_config_byte(pdev, I82875P_DES, &info->des);
pci_read_config_byte(pdev, I82875P_DERRSYN, &info->derrsyn);
}
pci_write_bits16(pdev, I82875P_ERRSTS, 0x0081, 0x0081);
}
static int i82875p_process_error_info(struct mem_ctl_info *mci,
struct i82875p_error_info *info,
int handle_errors)
{
int row, multi_chan;
multi_chan = mci->csrows[0]->nr_channels - 1;
if (!(info->errsts & 0x0081))
return 0;
if (!handle_errors)
return 1;
if ((info->errsts ^ info->errsts2) & 0x0081) {
edac_mc_handle_error(HW_EVENT_ERR_UNCORRECTED, mci, 1, 0, 0, 0,
-1, -1, -1,
"UE overwrote CE", "");
info->errsts = info->errsts2;
}
info->eap >>= PAGE_SHIFT;
row = edac_mc_find_csrow_by_page(mci, info->eap);
if (info->errsts & 0x0080)
edac_mc_handle_error(HW_EVENT_ERR_UNCORRECTED, mci, 1,
info->eap, 0, 0,
row, -1, -1,
"i82875p UE", "");
else
edac_mc_handle_error(HW_EVENT_ERR_CORRECTED, mci, 1,
info->eap, 0, info->derrsyn,
row, multi_chan ? (info->des & 0x1) : 0,
-1, "i82875p CE", "");
return 1;
}
static void i82875p_check(struct mem_ctl_info *mci)
{
struct i82875p_error_info info;
edac_dbg(1, "MC%d\n", mci->mc_idx);
i82875p_get_error_info(mci, &info);
i82875p_process_error_info(mci, &info, 1);
}
static int i82875p_setup_overfl_dev(struct pci_dev *pdev,
struct pci_dev **ovrfl_pdev,
void __iomem **ovrfl_window)
{
struct pci_dev *dev;
void __iomem *window;
int err;
*ovrfl_pdev = NULL;
*ovrfl_window = NULL;
dev = pci_get_device(PCI_VEND_DEV(INTEL, 82875_6), NULL);
if (dev == NULL) {
pci_write_bits8(pdev, 0xf4, 0x2, 0x2);
dev = pci_scan_single_device(pdev->bus, PCI_DEVFN(6, 0));
if (dev == NULL)
return 1;
err = pci_bus_add_device(dev);
if (err) {
i82875p_printk(KERN_ERR,
"%s(): pci_bus_add_device() Failed\n",
__func__);
}
pci_bus_assign_resources(dev->bus);
}
*ovrfl_pdev = dev;
if (pci_enable_device(dev)) {
i82875p_printk(KERN_ERR, "%s(): Failed to enable overflow "
"device\n", __func__);
return 1;
}
if (pci_request_regions(dev, pci_name(dev))) {
#ifdef CORRECT_BIOS
goto fail0;
#endif
}
window = pci_ioremap_bar(dev, 0);
if (window == NULL) {
i82875p_printk(KERN_ERR, "%s(): Failed to ioremap bar6\n",
__func__);
goto fail1;
}
*ovrfl_window = window;
return 0;
fail1:
pci_release_regions(dev);
#ifdef CORRECT_BIOS
fail0:
pci_disable_device(dev);
#endif
return 1;
}
static inline int dual_channel_active(u32 drc)
{
return (drc >> 21) & 0x1;
}
static void i82875p_init_csrows(struct mem_ctl_info *mci,
struct pci_dev *pdev,
void __iomem * ovrfl_window, u32 drc)
{
struct csrow_info *csrow;
struct dimm_info *dimm;
unsigned nr_chans = dual_channel_active(drc) + 1;
unsigned long last_cumul_size;
u8 value;
u32 drc_ddim;
u32 cumul_size, nr_pages;
int index, j;
drc_ddim = (drc >> 18) & 0x1;
last_cumul_size = 0;
for (index = 0; index < mci->nr_csrows; index++) {
csrow = mci->csrows[index];
value = readb(ovrfl_window + I82875P_DRB + index);
cumul_size = value << (I82875P_DRB_SHIFT - PAGE_SHIFT);
edac_dbg(3, "(%d) cumul_size 0x%x\n", index, cumul_size);
if (cumul_size == last_cumul_size)
continue;
csrow->first_page = last_cumul_size;
csrow->last_page = cumul_size - 1;
nr_pages = cumul_size - last_cumul_size;
last_cumul_size = cumul_size;
for (j = 0; j < nr_chans; j++) {
dimm = csrow->channels[j]->dimm;
dimm->nr_pages = nr_pages / nr_chans;
dimm->grain = 1 << 12;
dimm->mtype = MEM_DDR;
dimm->dtype = DEV_UNKNOWN;
dimm->edac_mode = drc_ddim ? EDAC_SECDED : EDAC_NONE;
}
}
}
static int i82875p_probe1(struct pci_dev *pdev, int dev_idx)
{
int rc = -ENODEV;
struct mem_ctl_info *mci;
struct edac_mc_layer layers[2];
struct i82875p_pvt *pvt;
struct pci_dev *ovrfl_pdev;
void __iomem *ovrfl_window;
u32 drc;
u32 nr_chans;
struct i82875p_error_info discard;
edac_dbg(0, "\n");
if (i82875p_setup_overfl_dev(pdev, &ovrfl_pdev, &ovrfl_window))
return -ENODEV;
drc = readl(ovrfl_window + I82875P_DRC);
nr_chans = dual_channel_active(drc) + 1;
layers[0].type = EDAC_MC_LAYER_CHIP_SELECT;
layers[0].size = I82875P_NR_CSROWS(nr_chans);
layers[0].is_virt_csrow = true;
layers[1].type = EDAC_MC_LAYER_CHANNEL;
layers[1].size = nr_chans;
layers[1].is_virt_csrow = false;
mci = edac_mc_alloc(0, ARRAY_SIZE(layers), layers, sizeof(*pvt));
if (!mci) {
rc = -ENOMEM;
goto fail0;
}
edac_dbg(3, "init mci\n");
mci->pdev = &pdev->dev;
mci->mtype_cap = MEM_FLAG_DDR;
mci->edac_ctl_cap = EDAC_FLAG_NONE | EDAC_FLAG_SECDED;
mci->edac_cap = EDAC_FLAG_UNKNOWN;
mci->mod_name = EDAC_MOD_STR;
mci->mod_ver = I82875P_REVISION;
mci->ctl_name = i82875p_devs[dev_idx].ctl_name;
mci->dev_name = pci_name(pdev);
mci->edac_check = i82875p_check;
mci->ctl_page_to_phys = NULL;
edac_dbg(3, "init pvt\n");
pvt = (struct i82875p_pvt *)mci->pvt_info;
pvt->ovrfl_pdev = ovrfl_pdev;
pvt->ovrfl_window = ovrfl_window;
i82875p_init_csrows(mci, pdev, ovrfl_window, drc);
i82875p_get_error_info(mci, &discard);
if (edac_mc_add_mc(mci)) {
edac_dbg(3, "failed edac_mc_add_mc()\n");
goto fail1;
}
i82875p_pci = edac_pci_create_generic_ctl(&pdev->dev, EDAC_MOD_STR);
if (!i82875p_pci) {
printk(KERN_WARNING
"%s(): Unable to create PCI control\n",
__func__);
printk(KERN_WARNING
"%s(): PCI error report via EDAC not setup\n",
__func__);
}
edac_dbg(3, "success\n");
return 0;
fail1:
edac_mc_free(mci);
fail0:
iounmap(ovrfl_window);
pci_release_regions(ovrfl_pdev);
pci_disable_device(ovrfl_pdev);
return rc;
}
static int i82875p_init_one(struct pci_dev *pdev,
const struct pci_device_id *ent)
{
int rc;
edac_dbg(0, "\n");
i82875p_printk(KERN_INFO, "i82875p init one\n");
if (pci_enable_device(pdev) < 0)
return -EIO;
rc = i82875p_probe1(pdev, ent->driver_data);
if (mci_pdev == NULL)
mci_pdev = pci_dev_get(pdev);
return rc;
}
static void i82875p_remove_one(struct pci_dev *pdev)
{
struct mem_ctl_info *mci;
struct i82875p_pvt *pvt = NULL;
edac_dbg(0, "\n");
if (i82875p_pci)
edac_pci_release_generic_ctl(i82875p_pci);
if ((mci = edac_mc_del_mc(&pdev->dev)) == NULL)
return;
pvt = (struct i82875p_pvt *)mci->pvt_info;
if (pvt->ovrfl_window)
iounmap(pvt->ovrfl_window);
if (pvt->ovrfl_pdev) {
#ifdef CORRECT_BIOS
pci_release_regions(pvt->ovrfl_pdev);
#endif
pci_disable_device(pvt->ovrfl_pdev);
pci_dev_put(pvt->ovrfl_pdev);
}
edac_mc_free(mci);
}
static int __init i82875p_init(void)
{
int pci_rc;
edac_dbg(3, "\n");
opstate_init();
pci_rc = pci_register_driver(&i82875p_driver);
if (pci_rc < 0)
goto fail0;
if (mci_pdev == NULL) {
mci_pdev = pci_get_device(PCI_VENDOR_ID_INTEL,
PCI_DEVICE_ID_INTEL_82875_0, NULL);
if (!mci_pdev) {
edac_dbg(0, "875p pci_get_device fail\n");
pci_rc = -ENODEV;
goto fail1;
}
pci_rc = i82875p_init_one(mci_pdev, i82875p_pci_tbl);
if (pci_rc < 0) {
edac_dbg(0, "875p init fail\n");
pci_rc = -ENODEV;
goto fail1;
}
}
return 0;
fail1:
pci_unregister_driver(&i82875p_driver);
fail0:
if (mci_pdev != NULL)
pci_dev_put(mci_pdev);
return pci_rc;
}
static void __exit i82875p_exit(void)
{
edac_dbg(3, "\n");
i82875p_remove_one(mci_pdev);
pci_dev_put(mci_pdev);
pci_unregister_driver(&i82875p_driver);
}
