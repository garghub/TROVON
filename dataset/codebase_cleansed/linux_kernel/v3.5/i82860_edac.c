static void i82860_get_error_info(struct mem_ctl_info *mci,
struct i82860_error_info *info)
{
struct pci_dev *pdev;
pdev = to_pci_dev(mci->dev);
pci_read_config_word(pdev, I82860_ERRSTS, &info->errsts);
pci_read_config_dword(pdev, I82860_EAP, &info->eap);
pci_read_config_word(pdev, I82860_DERRCTL_STS, &info->derrsyn);
pci_read_config_word(pdev, I82860_ERRSTS, &info->errsts2);
pci_write_bits16(pdev, I82860_ERRSTS, 0x0003, 0x0003);
if (!(info->errsts2 & 0x0003))
return;
if ((info->errsts ^ info->errsts2) & 0x0003) {
pci_read_config_dword(pdev, I82860_EAP, &info->eap);
pci_read_config_word(pdev, I82860_DERRCTL_STS, &info->derrsyn);
}
}
static int i82860_process_error_info(struct mem_ctl_info *mci,
struct i82860_error_info *info,
int handle_errors)
{
struct dimm_info *dimm;
int row;
if (!(info->errsts2 & 0x0003))
return 0;
if (!handle_errors)
return 1;
if ((info->errsts ^ info->errsts2) & 0x0003) {
edac_mc_handle_error(HW_EVENT_ERR_UNCORRECTED, mci, 0, 0, 0,
-1, -1, -1, "UE overwrote CE", "", NULL);
info->errsts = info->errsts2;
}
info->eap >>= PAGE_SHIFT;
row = edac_mc_find_csrow_by_page(mci, info->eap);
dimm = mci->csrows[row].channels[0].dimm;
if (info->errsts & 0x0002)
edac_mc_handle_error(HW_EVENT_ERR_UNCORRECTED, mci,
info->eap, 0, 0,
dimm->location[0], dimm->location[1], -1,
"i82860 UE", "", NULL);
else
edac_mc_handle_error(HW_EVENT_ERR_UNCORRECTED, mci,
info->eap, 0, info->derrsyn,
dimm->location[0], dimm->location[1], -1,
"i82860 CE", "", NULL);
return 1;
}
static void i82860_check(struct mem_ctl_info *mci)
{
struct i82860_error_info info;
debugf1("MC%d: %s()\n", mci->mc_idx, __func__);
i82860_get_error_info(mci, &info);
i82860_process_error_info(mci, &info, 1);
}
static void i82860_init_csrows(struct mem_ctl_info *mci, struct pci_dev *pdev)
{
unsigned long last_cumul_size;
u16 mchcfg_ddim;
u16 value;
u32 cumul_size;
struct csrow_info *csrow;
struct dimm_info *dimm;
int index;
pci_read_config_word(pdev, I82860_MCHCFG, &mchcfg_ddim);
mchcfg_ddim = mchcfg_ddim & 0x180;
last_cumul_size = 0;
for (index = 0; index < mci->nr_csrows; index++) {
csrow = &mci->csrows[index];
dimm = csrow->channels[0].dimm;
pci_read_config_word(pdev, I82860_GBA + index * 2, &value);
cumul_size = (value & I82860_GBA_MASK) <<
(I82860_GBA_SHIFT - PAGE_SHIFT);
debugf3("%s(): (%d) cumul_size 0x%x\n", __func__, index,
cumul_size);
if (cumul_size == last_cumul_size)
continue;
csrow->first_page = last_cumul_size;
csrow->last_page = cumul_size - 1;
dimm->nr_pages = cumul_size - last_cumul_size;
last_cumul_size = cumul_size;
dimm->grain = 1 << 12;
dimm->mtype = MEM_RMBS;
dimm->dtype = DEV_UNKNOWN;
dimm->edac_mode = mchcfg_ddim ? EDAC_SECDED : EDAC_NONE;
}
}
static int i82860_probe1(struct pci_dev *pdev, int dev_idx)
{
struct mem_ctl_info *mci;
struct edac_mc_layer layers[2];
struct i82860_error_info discard;
layers[0].type = EDAC_MC_LAYER_CHANNEL;
layers[0].size = 2;
layers[0].is_virt_csrow = true;
layers[1].type = EDAC_MC_LAYER_SLOT;
layers[1].size = 8;
layers[1].is_virt_csrow = true;
mci = edac_mc_alloc(0, ARRAY_SIZE(layers), layers, 0);
if (!mci)
return -ENOMEM;
debugf3("%s(): init mci\n", __func__);
mci->dev = &pdev->dev;
mci->mtype_cap = MEM_FLAG_DDR;
mci->edac_ctl_cap = EDAC_FLAG_NONE | EDAC_FLAG_SECDED;
mci->edac_cap = EDAC_FLAG_SECDED;
mci->mod_name = EDAC_MOD_STR;
mci->mod_ver = I82860_REVISION;
mci->ctl_name = i82860_devs[dev_idx].ctl_name;
mci->dev_name = pci_name(pdev);
mci->edac_check = i82860_check;
mci->ctl_page_to_phys = NULL;
i82860_init_csrows(mci, pdev);
i82860_get_error_info(mci, &discard);
if (edac_mc_add_mc(mci)) {
debugf3("%s(): failed edac_mc_add_mc()\n", __func__);
goto fail;
}
i82860_pci = edac_pci_create_generic_ctl(&pdev->dev, EDAC_MOD_STR);
if (!i82860_pci) {
printk(KERN_WARNING
"%s(): Unable to create PCI control\n",
__func__);
printk(KERN_WARNING
"%s(): PCI error report via EDAC not setup\n",
__func__);
}
debugf3("%s(): success\n", __func__);
return 0;
fail:
edac_mc_free(mci);
return -ENODEV;
}
static int __devinit i82860_init_one(struct pci_dev *pdev,
const struct pci_device_id *ent)
{
int rc;
debugf0("%s()\n", __func__);
i82860_printk(KERN_INFO, "i82860 init one\n");
if (pci_enable_device(pdev) < 0)
return -EIO;
rc = i82860_probe1(pdev, ent->driver_data);
if (rc == 0)
mci_pdev = pci_dev_get(pdev);
return rc;
}
static void __devexit i82860_remove_one(struct pci_dev *pdev)
{
struct mem_ctl_info *mci;
debugf0("%s()\n", __func__);
if (i82860_pci)
edac_pci_release_generic_ctl(i82860_pci);
if ((mci = edac_mc_del_mc(&pdev->dev)) == NULL)
return;
edac_mc_free(mci);
}
static int __init i82860_init(void)
{
int pci_rc;
debugf3("%s()\n", __func__);
opstate_init();
if ((pci_rc = pci_register_driver(&i82860_driver)) < 0)
goto fail0;
if (!mci_pdev) {
mci_pdev = pci_get_device(PCI_VENDOR_ID_INTEL,
PCI_DEVICE_ID_INTEL_82860_0, NULL);
if (mci_pdev == NULL) {
debugf0("860 pci_get_device fail\n");
pci_rc = -ENODEV;
goto fail1;
}
pci_rc = i82860_init_one(mci_pdev, i82860_pci_tbl);
if (pci_rc < 0) {
debugf0("860 init fail\n");
pci_rc = -ENODEV;
goto fail1;
}
}
return 0;
fail1:
pci_unregister_driver(&i82860_driver);
fail0:
if (mci_pdev != NULL)
pci_dev_put(mci_pdev);
return pci_rc;
}
static void __exit i82860_exit(void)
{
debugf3("%s()\n", __func__);
pci_unregister_driver(&i82860_driver);
if (mci_pdev != NULL)
pci_dev_put(mci_pdev);
}
