static void amd76x_get_error_info(struct mem_ctl_info *mci,
struct amd76x_error_info *info)
{
struct pci_dev *pdev;
pdev = to_pci_dev(mci->pdev);
pci_read_config_dword(pdev, AMD76X_ECC_MODE_STATUS,
&info->ecc_mode_status);
if (info->ecc_mode_status & BIT(8))
pci_write_bits32(pdev, AMD76X_ECC_MODE_STATUS,
(u32) BIT(8), (u32) BIT(8));
if (info->ecc_mode_status & BIT(9))
pci_write_bits32(pdev, AMD76X_ECC_MODE_STATUS,
(u32) BIT(9), (u32) BIT(9));
}
static int amd76x_process_error_info(struct mem_ctl_info *mci,
struct amd76x_error_info *info,
int handle_errors)
{
int error_found;
u32 row;
error_found = 0;
if (info->ecc_mode_status & BIT(8)) {
error_found = 1;
if (handle_errors) {
row = (info->ecc_mode_status >> 4) & 0xf;
edac_mc_handle_error(HW_EVENT_ERR_UNCORRECTED, mci, 1,
mci->csrows[row]->first_page, 0, 0,
row, 0, -1,
mci->ctl_name, "");
}
}
if (info->ecc_mode_status & BIT(9)) {
error_found = 1;
if (handle_errors) {
row = info->ecc_mode_status & 0xf;
edac_mc_handle_error(HW_EVENT_ERR_CORRECTED, mci, 1,
mci->csrows[row]->first_page, 0, 0,
row, 0, -1,
mci->ctl_name, "");
}
}
return error_found;
}
static void amd76x_check(struct mem_ctl_info *mci)
{
struct amd76x_error_info info;
edac_dbg(3, "\n");
amd76x_get_error_info(mci, &info);
amd76x_process_error_info(mci, &info, 1);
}
static void amd76x_init_csrows(struct mem_ctl_info *mci, struct pci_dev *pdev,
enum edac_type edac_mode)
{
struct csrow_info *csrow;
struct dimm_info *dimm;
u32 mba, mba_base, mba_mask, dms;
int index;
for (index = 0; index < mci->nr_csrows; index++) {
csrow = mci->csrows[index];
dimm = csrow->channels[0]->dimm;
pci_read_config_dword(pdev,
AMD76X_MEM_BASE_ADDR + (index * 4), &mba);
if (!(mba & BIT(0)))
continue;
mba_base = mba & 0xff800000UL;
mba_mask = ((mba & 0xff80) << 16) | 0x7fffffUL;
pci_read_config_dword(pdev, AMD76X_DRAM_MODE_STATUS, &dms);
csrow->first_page = mba_base >> PAGE_SHIFT;
dimm->nr_pages = (mba_mask + 1) >> PAGE_SHIFT;
csrow->last_page = csrow->first_page + dimm->nr_pages - 1;
csrow->page_mask = mba_mask >> PAGE_SHIFT;
dimm->grain = dimm->nr_pages << PAGE_SHIFT;
dimm->mtype = MEM_RDDR;
dimm->dtype = ((dms >> index) & 0x1) ? DEV_X4 : DEV_UNKNOWN;
dimm->edac_mode = edac_mode;
}
}
static int amd76x_probe1(struct pci_dev *pdev, int dev_idx)
{
static const enum edac_type ems_modes[] = {
EDAC_NONE,
EDAC_EC,
EDAC_SECDED,
EDAC_SECDED
};
struct mem_ctl_info *mci;
struct edac_mc_layer layers[2];
u32 ems;
u32 ems_mode;
struct amd76x_error_info discard;
edac_dbg(0, "\n");
pci_read_config_dword(pdev, AMD76X_ECC_MODE_STATUS, &ems);
ems_mode = (ems >> 10) & 0x3;
layers[0].type = EDAC_MC_LAYER_CHIP_SELECT;
layers[0].size = AMD76X_NR_CSROWS;
layers[0].is_virt_csrow = true;
layers[1].type = EDAC_MC_LAYER_CHANNEL;
layers[1].size = 1;
layers[1].is_virt_csrow = false;
mci = edac_mc_alloc(0, ARRAY_SIZE(layers), layers, 0);
if (mci == NULL)
return -ENOMEM;
edac_dbg(0, "mci = %p\n", mci);
mci->pdev = &pdev->dev;
mci->mtype_cap = MEM_FLAG_RDDR;
mci->edac_ctl_cap = EDAC_FLAG_NONE | EDAC_FLAG_EC | EDAC_FLAG_SECDED;
mci->edac_cap = ems_mode ?
(EDAC_FLAG_EC | EDAC_FLAG_SECDED) : EDAC_FLAG_NONE;
mci->mod_name = EDAC_MOD_STR;
mci->mod_ver = AMD76X_REVISION;
mci->ctl_name = amd76x_devs[dev_idx].ctl_name;
mci->dev_name = pci_name(pdev);
mci->edac_check = amd76x_check;
mci->ctl_page_to_phys = NULL;
amd76x_init_csrows(mci, pdev, ems_modes[ems_mode]);
amd76x_get_error_info(mci, &discard);
if (edac_mc_add_mc(mci)) {
edac_dbg(3, "failed edac_mc_add_mc()\n");
goto fail;
}
amd76x_pci = edac_pci_create_generic_ctl(&pdev->dev, EDAC_MOD_STR);
if (!amd76x_pci) {
printk(KERN_WARNING
"%s(): Unable to create PCI control\n",
__func__);
printk(KERN_WARNING
"%s(): PCI error report via EDAC not setup\n",
__func__);
}
edac_dbg(3, "success\n");
return 0;
fail:
edac_mc_free(mci);
return -ENODEV;
}
static int __devinit amd76x_init_one(struct pci_dev *pdev,
const struct pci_device_id *ent)
{
edac_dbg(0, "\n");
return amd76x_probe1(pdev, ent->driver_data);
}
static void __devexit amd76x_remove_one(struct pci_dev *pdev)
{
struct mem_ctl_info *mci;
edac_dbg(0, "\n");
if (amd76x_pci)
edac_pci_release_generic_ctl(amd76x_pci);
if ((mci = edac_mc_del_mc(&pdev->dev)) == NULL)
return;
edac_mc_free(mci);
}
static int __init amd76x_init(void)
{
opstate_init();
return pci_register_driver(&amd76x_driver);
}
static void __exit amd76x_exit(void)
{
pci_unregister_driver(&amd76x_driver);
}
