static void r82600_get_error_info(struct mem_ctl_info *mci,
struct r82600_error_info *info)
{
struct pci_dev *pdev;
pdev = to_pci_dev(mci->pdev);
pci_read_config_dword(pdev, R82600_EAP, &info->eapr);
if (info->eapr & BIT(0))
pci_write_bits32(pdev, R82600_EAP,
((u32) BIT(0) & (u32) BIT(1)),
((u32) BIT(0) & (u32) BIT(1)));
if (info->eapr & BIT(1))
pci_write_bits32(pdev, R82600_EAP,
((u32) BIT(0) & (u32) BIT(1)),
((u32) BIT(0) & (u32) BIT(1)));
}
static int r82600_process_error_info(struct mem_ctl_info *mci,
struct r82600_error_info *info,
int handle_errors)
{
int error_found;
u32 eapaddr, page;
u32 syndrome;
error_found = 0;
eapaddr = ((info->eapr >> 12) & 0x7FFF) << 13;
syndrome = (info->eapr >> 4) & 0xFF;
page = eapaddr >> PAGE_SHIFT;
if (info->eapr & BIT(0)) {
error_found = 1;
if (handle_errors)
edac_mc_handle_error(HW_EVENT_ERR_CORRECTED, mci, 1,
page, 0, syndrome,
edac_mc_find_csrow_by_page(mci, page),
0, -1,
mci->ctl_name, "");
}
if (info->eapr & BIT(1)) {
error_found = 1;
if (handle_errors)
edac_mc_handle_error(HW_EVENT_ERR_UNCORRECTED, mci, 1,
page, 0, 0,
edac_mc_find_csrow_by_page(mci, page),
0, -1,
mci->ctl_name, "");
}
return error_found;
}
static void r82600_check(struct mem_ctl_info *mci)
{
struct r82600_error_info info;
edac_dbg(1, "MC%d\n", mci->mc_idx);
r82600_get_error_info(mci, &info);
r82600_process_error_info(mci, &info, 1);
}
static inline int ecc_enabled(u8 dramcr)
{
return dramcr & BIT(5);
}
static void r82600_init_csrows(struct mem_ctl_info *mci, struct pci_dev *pdev,
u8 dramcr)
{
struct csrow_info *csrow;
struct dimm_info *dimm;
int index;
u8 drbar;
u32 row_high_limit, row_high_limit_last;
u32 reg_sdram, ecc_on, row_base;
ecc_on = ecc_enabled(dramcr);
reg_sdram = dramcr & BIT(4);
row_high_limit_last = 0;
for (index = 0; index < mci->nr_csrows; index++) {
csrow = mci->csrows[index];
dimm = csrow->channels[0]->dimm;
pci_read_config_byte(pdev, R82600_DRBA + index, &drbar);
edac_dbg(1, "Row=%d DRBA = %#0x\n", index, drbar);
row_high_limit = ((u32) drbar << 24);
edac_dbg(1, "Row=%d, Boundary Address=%#0x, Last = %#0x\n",
index, row_high_limit, row_high_limit_last);
if (row_high_limit == row_high_limit_last)
continue;
row_base = row_high_limit_last;
csrow->first_page = row_base >> PAGE_SHIFT;
csrow->last_page = (row_high_limit >> PAGE_SHIFT) - 1;
dimm->nr_pages = csrow->last_page - csrow->first_page + 1;
dimm->grain = 1 << 14;
dimm->mtype = reg_sdram ? MEM_RDDR : MEM_DDR;
dimm->dtype = DEV_UNKNOWN;
dimm->edac_mode = ecc_on ? EDAC_SECDED : EDAC_NONE;
row_high_limit_last = row_high_limit;
}
}
static int r82600_probe1(struct pci_dev *pdev, int dev_idx)
{
struct mem_ctl_info *mci;
struct edac_mc_layer layers[2];
u8 dramcr;
u32 eapr;
u32 scrub_disabled;
u32 sdram_refresh_rate;
struct r82600_error_info discard;
edac_dbg(0, "\n");
pci_read_config_byte(pdev, R82600_DRAMC, &dramcr);
pci_read_config_dword(pdev, R82600_EAP, &eapr);
scrub_disabled = eapr & BIT(31);
sdram_refresh_rate = dramcr & (BIT(0) | BIT(1));
edac_dbg(2, "sdram refresh rate = %#0x\n", sdram_refresh_rate);
edac_dbg(2, "DRAMC register = %#0x\n", dramcr);
layers[0].type = EDAC_MC_LAYER_CHIP_SELECT;
layers[0].size = R82600_NR_CSROWS;
layers[0].is_virt_csrow = true;
layers[1].type = EDAC_MC_LAYER_CHANNEL;
layers[1].size = R82600_NR_CHANS;
layers[1].is_virt_csrow = false;
mci = edac_mc_alloc(0, ARRAY_SIZE(layers), layers, 0);
if (mci == NULL)
return -ENOMEM;
edac_dbg(0, "mci = %p\n", mci);
mci->pdev = &pdev->dev;
mci->mtype_cap = MEM_FLAG_RDDR | MEM_FLAG_DDR;
mci->edac_ctl_cap = EDAC_FLAG_NONE | EDAC_FLAG_EC | EDAC_FLAG_SECDED;
mci->edac_cap = EDAC_FLAG_NONE | EDAC_FLAG_EC | EDAC_FLAG_SECDED;
if (ecc_enabled(dramcr)) {
if (scrub_disabled)
edac_dbg(3, "mci = %p - Scrubbing disabled! EAP: %#0x\n",
mci, eapr);
} else
mci->edac_cap = EDAC_FLAG_NONE;
mci->mod_name = EDAC_MOD_STR;
mci->mod_ver = R82600_REVISION;
mci->ctl_name = "R82600";
mci->dev_name = pci_name(pdev);
mci->edac_check = r82600_check;
mci->ctl_page_to_phys = NULL;
r82600_init_csrows(mci, pdev, dramcr);
r82600_get_error_info(mci, &discard);
if (edac_mc_add_mc(mci)) {
edac_dbg(3, "failed edac_mc_add_mc()\n");
goto fail;
}
if (disable_hardware_scrub) {
edac_dbg(3, "Disabling Hardware Scrub (scrub on error)\n");
pci_write_bits32(pdev, R82600_EAP, BIT(31), BIT(31));
}
r82600_pci = edac_pci_create_generic_ctl(&pdev->dev, EDAC_MOD_STR);
if (!r82600_pci) {
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
static int r82600_init_one(struct pci_dev *pdev,
const struct pci_device_id *ent)
{
edac_dbg(0, "\n");
return r82600_probe1(pdev, ent->driver_data);
}
static void r82600_remove_one(struct pci_dev *pdev)
{
struct mem_ctl_info *mci;
edac_dbg(0, "\n");
if (r82600_pci)
edac_pci_release_generic_ctl(r82600_pci);
if ((mci = edac_mc_del_mc(&pdev->dev)) == NULL)
return;
edac_mc_free(mci);
}
static int __init r82600_init(void)
{
opstate_init();
return pci_register_driver(&r82600_driver);
}
static void __exit r82600_exit(void)
{
pci_unregister_driver(&r82600_driver);
}
