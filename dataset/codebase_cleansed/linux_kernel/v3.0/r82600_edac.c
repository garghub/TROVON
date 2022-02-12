static void r82600_get_error_info(struct mem_ctl_info *mci,
struct r82600_error_info *info)
{
struct pci_dev *pdev;
pdev = to_pci_dev(mci->dev);
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
edac_mc_handle_ce(mci, page, 0,
syndrome,
edac_mc_find_csrow_by_page(mci, page),
0, mci->ctl_name);
}
if (info->eapr & BIT(1)) {
error_found = 1;
if (handle_errors)
edac_mc_handle_ue(mci, page, 0,
edac_mc_find_csrow_by_page(mci, page),
mci->ctl_name);
}
return error_found;
}
static void r82600_check(struct mem_ctl_info *mci)
{
struct r82600_error_info info;
debugf1("MC%d: %s()\n", mci->mc_idx, __func__);
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
int index;
u8 drbar;
u32 row_high_limit, row_high_limit_last;
u32 reg_sdram, ecc_on, row_base;
ecc_on = ecc_enabled(dramcr);
reg_sdram = dramcr & BIT(4);
row_high_limit_last = 0;
for (index = 0; index < mci->nr_csrows; index++) {
csrow = &mci->csrows[index];
pci_read_config_byte(pdev, R82600_DRBA + index, &drbar);
debugf1("%s() Row=%d DRBA = %#0x\n", __func__, index, drbar);
row_high_limit = ((u32) drbar << 24);
debugf1("%s() Row=%d, Boundary Address=%#0x, Last = %#0x\n",
__func__, index, row_high_limit, row_high_limit_last);
if (row_high_limit == row_high_limit_last)
continue;
row_base = row_high_limit_last;
csrow->first_page = row_base >> PAGE_SHIFT;
csrow->last_page = (row_high_limit >> PAGE_SHIFT) - 1;
csrow->nr_pages = csrow->last_page - csrow->first_page + 1;
csrow->grain = 1 << 14;
csrow->mtype = reg_sdram ? MEM_RDDR : MEM_DDR;
csrow->dtype = DEV_UNKNOWN;
csrow->edac_mode = ecc_on ? EDAC_SECDED : EDAC_NONE;
row_high_limit_last = row_high_limit;
}
}
static int r82600_probe1(struct pci_dev *pdev, int dev_idx)
{
struct mem_ctl_info *mci;
u8 dramcr;
u32 eapr;
u32 scrub_disabled;
u32 sdram_refresh_rate;
struct r82600_error_info discard;
debugf0("%s()\n", __func__);
pci_read_config_byte(pdev, R82600_DRAMC, &dramcr);
pci_read_config_dword(pdev, R82600_EAP, &eapr);
scrub_disabled = eapr & BIT(31);
sdram_refresh_rate = dramcr & (BIT(0) | BIT(1));
debugf2("%s(): sdram refresh rate = %#0x\n", __func__,
sdram_refresh_rate);
debugf2("%s(): DRAMC register = %#0x\n", __func__, dramcr);
mci = edac_mc_alloc(0, R82600_NR_CSROWS, R82600_NR_CHANS, 0);
if (mci == NULL)
return -ENOMEM;
debugf0("%s(): mci = %p\n", __func__, mci);
mci->dev = &pdev->dev;
mci->mtype_cap = MEM_FLAG_RDDR | MEM_FLAG_DDR;
mci->edac_ctl_cap = EDAC_FLAG_NONE | EDAC_FLAG_EC | EDAC_FLAG_SECDED;
mci->edac_cap = EDAC_FLAG_NONE | EDAC_FLAG_EC | EDAC_FLAG_SECDED;
if (ecc_enabled(dramcr)) {
if (scrub_disabled)
debugf3("%s(): mci = %p - Scrubbing disabled! EAP: "
"%#0x\n", __func__, mci, eapr);
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
debugf3("%s(): failed edac_mc_add_mc()\n", __func__);
goto fail;
}
if (disable_hardware_scrub) {
debugf3("%s(): Disabling Hardware Scrub (scrub on error)\n",
__func__);
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
debugf3("%s(): success\n", __func__);
return 0;
fail:
edac_mc_free(mci);
return -ENODEV;
}
static int __devinit r82600_init_one(struct pci_dev *pdev,
const struct pci_device_id *ent)
{
debugf0("%s()\n", __func__);
return r82600_probe1(pdev, ent->driver_data);
}
static void __devexit r82600_remove_one(struct pci_dev *pdev)
{
struct mem_ctl_info *mci;
debugf0("%s()\n", __func__);
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
