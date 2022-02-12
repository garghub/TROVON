static u32 pasemi_edac_get_error_info(struct mem_ctl_info *mci)
{
struct pci_dev *pdev = to_pci_dev(mci->pdev);
u32 tmp;
pci_read_config_dword(pdev, MCDEBUG_ERRSTA,
&tmp);
tmp &= (MCDEBUG_ERRSTA_RFL_STATUS | MCDEBUG_ERRSTA_MBE_STATUS
| MCDEBUG_ERRSTA_SBE_STATUS);
if (tmp) {
if (tmp & MCDEBUG_ERRSTA_SBE_STATUS)
pci_write_config_dword(pdev, MCDEBUG_ERRCNT1,
MCDEBUG_ERRCNT1_SBE_CNT_OVRFLO);
pci_write_config_dword(pdev, MCDEBUG_ERRSTA, tmp);
}
return tmp;
}
static void pasemi_edac_process_error_info(struct mem_ctl_info *mci, u32 errsta)
{
struct pci_dev *pdev = to_pci_dev(mci->pdev);
u32 errlog1a;
u32 cs;
if (!errsta)
return;
pci_read_config_dword(pdev, MCDEBUG_ERRLOG1A, &errlog1a);
cs = (errlog1a & MCDEBUG_ERRLOG1A_MERR_CS_M) >>
MCDEBUG_ERRLOG1A_MERR_CS_S;
if (errsta & (MCDEBUG_ERRSTA_MBE_STATUS |
MCDEBUG_ERRSTA_RFL_STATUS)) {
edac_mc_handle_error(HW_EVENT_ERR_UNCORRECTED, mci, 1,
mci->csrows[cs]->first_page, 0, 0,
cs, 0, -1, mci->ctl_name, "");
}
if (errsta & MCDEBUG_ERRSTA_SBE_STATUS)
edac_mc_handle_error(HW_EVENT_ERR_CORRECTED, mci, 1,
mci->csrows[cs]->first_page, 0, 0,
cs, 0, -1, mci->ctl_name, "");
}
static void pasemi_edac_check(struct mem_ctl_info *mci)
{
u32 errsta;
errsta = pasemi_edac_get_error_info(mci);
if (errsta)
pasemi_edac_process_error_info(mci, errsta);
}
static int pasemi_edac_init_csrows(struct mem_ctl_info *mci,
struct pci_dev *pdev,
enum edac_type edac_mode)
{
struct csrow_info *csrow;
struct dimm_info *dimm;
u32 rankcfg;
int index;
for (index = 0; index < mci->nr_csrows; index++) {
csrow = mci->csrows[index];
dimm = csrow->channels[0]->dimm;
pci_read_config_dword(pdev,
MCDRAM_RANKCFG + (index * 12),
&rankcfg);
if (!(rankcfg & MCDRAM_RANKCFG_EN))
continue;
switch ((rankcfg & MCDRAM_RANKCFG_TYPE_SIZE_M) >>
MCDRAM_RANKCFG_TYPE_SIZE_S) {
case 0:
dimm->nr_pages = 128 << (20 - PAGE_SHIFT);
break;
case 1:
dimm->nr_pages = 256 << (20 - PAGE_SHIFT);
break;
case 2:
case 3:
dimm->nr_pages = 512 << (20 - PAGE_SHIFT);
break;
case 4:
dimm->nr_pages = 1024 << (20 - PAGE_SHIFT);
break;
case 5:
dimm->nr_pages = 2048 << (20 - PAGE_SHIFT);
break;
default:
edac_mc_printk(mci, KERN_ERR,
"Unrecognized Rank Config. rankcfg=%u\n",
rankcfg);
return -EINVAL;
}
csrow->first_page = last_page_in_mmc;
csrow->last_page = csrow->first_page + dimm->nr_pages - 1;
last_page_in_mmc += dimm->nr_pages;
csrow->page_mask = 0;
dimm->grain = PASEMI_EDAC_ERROR_GRAIN;
dimm->mtype = MEM_DDR;
dimm->dtype = DEV_UNKNOWN;
dimm->edac_mode = edac_mode;
}
return 0;
}
static int pasemi_edac_probe(struct pci_dev *pdev,
const struct pci_device_id *ent)
{
struct mem_ctl_info *mci = NULL;
struct edac_mc_layer layers[2];
u32 errctl1, errcor, scrub, mcen;
pci_read_config_dword(pdev, MCCFG_MCEN, &mcen);
if (!(mcen & MCCFG_MCEN_MMC_EN))
return -ENODEV;
pci_read_config_dword(pdev, MCDEBUG_ERRCTL1, &errctl1);
errctl1 |= MCDEBUG_ERRCTL1_SBE_LOG_EN |
MCDEBUG_ERRCTL1_MBE_LOG_EN |
MCDEBUG_ERRCTL1_RFL_LOG_EN;
pci_write_config_dword(pdev, MCDEBUG_ERRCTL1, errctl1);
layers[0].type = EDAC_MC_LAYER_CHIP_SELECT;
layers[0].size = PASEMI_EDAC_NR_CSROWS;
layers[0].is_virt_csrow = true;
layers[1].type = EDAC_MC_LAYER_CHANNEL;
layers[1].size = PASEMI_EDAC_NR_CHANS;
layers[1].is_virt_csrow = false;
mci = edac_mc_alloc(system_mmc_id++, ARRAY_SIZE(layers), layers,
0);
if (mci == NULL)
return -ENOMEM;
pci_read_config_dword(pdev, MCCFG_ERRCOR, &errcor);
errcor |= MCCFG_ERRCOR_RNK_FAIL_DET_EN |
MCCFG_ERRCOR_ECC_GEN_EN |
MCCFG_ERRCOR_ECC_CRR_EN;
mci->pdev = &pdev->dev;
mci->mtype_cap = MEM_FLAG_DDR | MEM_FLAG_RDDR;
mci->edac_ctl_cap = EDAC_FLAG_NONE | EDAC_FLAG_EC | EDAC_FLAG_SECDED;
mci->edac_cap = (errcor & MCCFG_ERRCOR_ECC_GEN_EN) ?
((errcor & MCCFG_ERRCOR_ECC_CRR_EN) ?
(EDAC_FLAG_EC | EDAC_FLAG_SECDED) : EDAC_FLAG_EC) :
EDAC_FLAG_NONE;
mci->mod_name = MODULE_NAME;
mci->dev_name = pci_name(pdev);
mci->ctl_name = "pasemi,pwrficient-mc";
mci->edac_check = pasemi_edac_check;
mci->ctl_page_to_phys = NULL;
pci_read_config_dword(pdev, MCCFG_SCRUB, &scrub);
mci->scrub_cap = SCRUB_FLAG_HW_PROG | SCRUB_FLAG_HW_SRC;
mci->scrub_mode =
((errcor & MCCFG_ERRCOR_ECC_CRR_EN) ? SCRUB_FLAG_HW_SRC : 0) |
((scrub & MCCFG_SCRUB_RGLR_SCRB_EN) ? SCRUB_FLAG_HW_PROG : 0);
if (pasemi_edac_init_csrows(mci, pdev,
(mci->edac_cap & EDAC_FLAG_SECDED) ?
EDAC_SECDED :
((mci->edac_cap & EDAC_FLAG_EC) ?
EDAC_EC : EDAC_NONE)))
goto fail;
pasemi_edac_get_error_info(mci);
if (edac_mc_add_mc(mci))
goto fail;
return 0;
fail:
edac_mc_free(mci);
return -ENODEV;
}
static void pasemi_edac_remove(struct pci_dev *pdev)
{
struct mem_ctl_info *mci = edac_mc_del_mc(&pdev->dev);
if (!mci)
return;
edac_mc_free(mci);
}
static int __init pasemi_edac_init(void)
{
opstate_init();
return pci_register_driver(&pasemi_edac_driver);
}
static void __exit pasemi_edac_exit(void)
{
pci_unregister_driver(&pasemi_edac_driver);
}
