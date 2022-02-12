static void i82443bxgx_edacmc_get_error_info(struct mem_ctl_info *mci,
struct i82443bxgx_edacmc_error_info
*info)
{
struct pci_dev *pdev;
pdev = to_pci_dev(mci->pdev);
pci_read_config_dword(pdev, I82443BXGX_EAP, &info->eap);
if (info->eap & I82443BXGX_EAP_OFFSET_SBE)
pci_write_bits32(pdev, I82443BXGX_EAP,
I82443BXGX_EAP_OFFSET_SBE,
I82443BXGX_EAP_OFFSET_SBE);
if (info->eap & I82443BXGX_EAP_OFFSET_MBE)
pci_write_bits32(pdev, I82443BXGX_EAP,
I82443BXGX_EAP_OFFSET_MBE,
I82443BXGX_EAP_OFFSET_MBE);
}
static int i82443bxgx_edacmc_process_error_info(struct mem_ctl_info *mci,
struct
i82443bxgx_edacmc_error_info
*info, int handle_errors)
{
int error_found = 0;
u32 eapaddr, page, pageoffset;
eapaddr = (info->eap & 0xfffff000);
page = eapaddr >> PAGE_SHIFT;
pageoffset = eapaddr - (page << PAGE_SHIFT);
if (info->eap & I82443BXGX_EAP_OFFSET_SBE) {
error_found = 1;
if (handle_errors)
edac_mc_handle_error(HW_EVENT_ERR_CORRECTED, mci, 1,
page, pageoffset, 0,
edac_mc_find_csrow_by_page(mci, page),
0, -1, mci->ctl_name, "");
}
if (info->eap & I82443BXGX_EAP_OFFSET_MBE) {
error_found = 1;
if (handle_errors)
edac_mc_handle_error(HW_EVENT_ERR_UNCORRECTED, mci, 1,
page, pageoffset, 0,
edac_mc_find_csrow_by_page(mci, page),
0, -1, mci->ctl_name, "");
}
return error_found;
}
static void i82443bxgx_edacmc_check(struct mem_ctl_info *mci)
{
struct i82443bxgx_edacmc_error_info info;
edac_dbg(1, "MC%d\n", mci->mc_idx);
i82443bxgx_edacmc_get_error_info(mci, &info);
i82443bxgx_edacmc_process_error_info(mci, &info, 1);
}
static void i82443bxgx_init_csrows(struct mem_ctl_info *mci,
struct pci_dev *pdev,
enum edac_type edac_mode,
enum mem_type mtype)
{
struct csrow_info *csrow;
struct dimm_info *dimm;
int index;
u8 drbar, dramc;
u32 row_base, row_high_limit, row_high_limit_last;
pci_read_config_byte(pdev, I82443BXGX_DRAMC, &dramc);
row_high_limit_last = 0;
for (index = 0; index < mci->nr_csrows; index++) {
csrow = mci->csrows[index];
dimm = csrow->channels[0]->dimm;
pci_read_config_byte(pdev, I82443BXGX_DRB + index, &drbar);
edac_dbg(1, "MC%d: Row=%d DRB = %#0x\n",
mci->mc_idx, index, drbar);
row_high_limit = ((u32) drbar << 23);
edac_dbg(1, "MC%d: Row=%d, Boundary Address=%#0x, Last = %#0x\n",
mci->mc_idx, index, row_high_limit,
row_high_limit_last);
if (row_high_limit_last && !row_high_limit)
row_high_limit = 1UL << 31;
if (row_high_limit == row_high_limit_last)
continue;
row_base = row_high_limit_last;
csrow->first_page = row_base >> PAGE_SHIFT;
csrow->last_page = (row_high_limit >> PAGE_SHIFT) - 1;
dimm->nr_pages = csrow->last_page - csrow->first_page + 1;
dimm->grain = 1 << 12;
dimm->mtype = mtype;
dimm->dtype = DEV_UNKNOWN;
dimm->edac_mode = edac_mode;
row_high_limit_last = row_high_limit;
}
}
static int i82443bxgx_edacmc_probe1(struct pci_dev *pdev, int dev_idx)
{
struct mem_ctl_info *mci;
struct edac_mc_layer layers[2];
u8 dramc;
u32 nbxcfg, ecc_mode;
enum mem_type mtype;
enum edac_type edac_mode;
edac_dbg(0, "MC:\n");
if (pci_read_config_dword(pdev, I82443BXGX_NBXCFG, &nbxcfg))
return -EIO;
layers[0].type = EDAC_MC_LAYER_CHIP_SELECT;
layers[0].size = I82443BXGX_NR_CSROWS;
layers[0].is_virt_csrow = true;
layers[1].type = EDAC_MC_LAYER_CHANNEL;
layers[1].size = I82443BXGX_NR_CHANS;
layers[1].is_virt_csrow = false;
mci = edac_mc_alloc(0, ARRAY_SIZE(layers), layers, 0);
if (mci == NULL)
return -ENOMEM;
edac_dbg(0, "MC: mci = %p\n", mci);
mci->pdev = &pdev->dev;
mci->mtype_cap = MEM_FLAG_EDO | MEM_FLAG_SDR | MEM_FLAG_RDR;
mci->edac_ctl_cap = EDAC_FLAG_NONE | EDAC_FLAG_EC | EDAC_FLAG_SECDED;
pci_read_config_byte(pdev, I82443BXGX_DRAMC, &dramc);
switch ((dramc >> I82443BXGX_DRAMC_OFFSET_DT) & (BIT(0) | BIT(1))) {
case I82443BXGX_DRAMC_DRAM_IS_EDO:
mtype = MEM_EDO;
break;
case I82443BXGX_DRAMC_DRAM_IS_SDRAM:
mtype = MEM_SDR;
break;
case I82443BXGX_DRAMC_DRAM_IS_RSDRAM:
mtype = MEM_RDR;
break;
default:
edac_dbg(0, "Unknown/reserved DRAM type value in DRAMC register!\n");
mtype = -MEM_UNKNOWN;
}
if ((mtype == MEM_SDR) || (mtype == MEM_RDR))
mci->edac_cap = mci->edac_ctl_cap;
else
mci->edac_cap = EDAC_FLAG_NONE;
mci->scrub_cap = SCRUB_FLAG_HW_SRC;
pci_read_config_dword(pdev, I82443BXGX_NBXCFG, &nbxcfg);
ecc_mode = ((nbxcfg >> I82443BXGX_NBXCFG_OFFSET_DRAM_INTEGRITY) &
(BIT(0) | BIT(1)));
mci->scrub_mode = (ecc_mode == I82443BXGX_NBXCFG_INTEGRITY_SCRUB)
? SCRUB_HW_SRC : SCRUB_NONE;
switch (ecc_mode) {
case I82443BXGX_NBXCFG_INTEGRITY_NONE:
edac_mode = EDAC_NONE;
break;
case I82443BXGX_NBXCFG_INTEGRITY_EC:
edac_mode = EDAC_EC;
break;
case I82443BXGX_NBXCFG_INTEGRITY_ECC:
case I82443BXGX_NBXCFG_INTEGRITY_SCRUB:
edac_mode = EDAC_SECDED;
break;
default:
edac_dbg(0, "Unknown/reserved ECC state in NBXCFG register!\n");
edac_mode = EDAC_UNKNOWN;
break;
}
i82443bxgx_init_csrows(mci, pdev, edac_mode, mtype);
pci_write_bits32(pdev, I82443BXGX_EAP,
(I82443BXGX_EAP_OFFSET_SBE |
I82443BXGX_EAP_OFFSET_MBE),
(I82443BXGX_EAP_OFFSET_SBE |
I82443BXGX_EAP_OFFSET_MBE));
mci->mod_name = EDAC_MOD_STR;
mci->ctl_name = "I82443BXGX";
mci->dev_name = pci_name(pdev);
mci->edac_check = i82443bxgx_edacmc_check;
mci->ctl_page_to_phys = NULL;
if (edac_mc_add_mc(mci)) {
edac_dbg(3, "failed edac_mc_add_mc()\n");
goto fail;
}
i82443bxgx_pci = edac_pci_create_generic_ctl(&pdev->dev, EDAC_MOD_STR);
if (!i82443bxgx_pci) {
printk(KERN_WARNING
"%s(): Unable to create PCI control\n",
__func__);
printk(KERN_WARNING
"%s(): PCI error report via EDAC not setup\n",
__func__);
}
edac_dbg(3, "MC: success\n");
return 0;
fail:
edac_mc_free(mci);
return -ENODEV;
}
static int i82443bxgx_edacmc_init_one(struct pci_dev *pdev,
const struct pci_device_id *ent)
{
int rc;
edac_dbg(0, "MC:\n");
rc = i82443bxgx_edacmc_probe1(pdev, ent->driver_data);
if (mci_pdev == NULL)
mci_pdev = pci_dev_get(pdev);
return rc;
}
static void i82443bxgx_edacmc_remove_one(struct pci_dev *pdev)
{
struct mem_ctl_info *mci;
edac_dbg(0, "\n");
if (i82443bxgx_pci)
edac_pci_release_generic_ctl(i82443bxgx_pci);
if ((mci = edac_mc_del_mc(&pdev->dev)) == NULL)
return;
edac_mc_free(mci);
}
static int __init i82443bxgx_edacmc_init(void)
{
int pci_rc;
opstate_init();
pci_rc = pci_register_driver(&i82443bxgx_edacmc_driver);
if (pci_rc < 0)
goto fail0;
if (mci_pdev == NULL) {
const struct pci_device_id *id = &i82443bxgx_pci_tbl[0];
int i = 0;
i82443bxgx_registered = 0;
while (mci_pdev == NULL && id->vendor != 0) {
mci_pdev = pci_get_device(id->vendor,
id->device, NULL);
i++;
id = &i82443bxgx_pci_tbl[i];
}
if (!mci_pdev) {
edac_dbg(0, "i82443bxgx pci_get_device fail\n");
pci_rc = -ENODEV;
goto fail1;
}
pci_rc = i82443bxgx_edacmc_init_one(mci_pdev, i82443bxgx_pci_tbl);
if (pci_rc < 0) {
edac_dbg(0, "i82443bxgx init fail\n");
pci_rc = -ENODEV;
goto fail1;
}
}
return 0;
fail1:
pci_unregister_driver(&i82443bxgx_edacmc_driver);
fail0:
pci_dev_put(mci_pdev);
return pci_rc;
}
static void __exit i82443bxgx_edacmc_exit(void)
{
pci_unregister_driver(&i82443bxgx_edacmc_driver);
if (!i82443bxgx_registered)
i82443bxgx_edacmc_remove_one(mci_pdev);
pci_dev_put(mci_pdev);
}
