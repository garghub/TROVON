static inline int e7xxx_find_channel(u16 syndrome)
{
debugf3("%s()\n", __func__);
if ((syndrome & 0xff00) == 0)
return 0;
if ((syndrome & 0x00ff) == 0)
return 1;
if ((syndrome & 0xf000) == 0 || (syndrome & 0x0f00) == 0)
return 0;
return 1;
}
static unsigned long ctl_page_to_phys(struct mem_ctl_info *mci,
unsigned long page)
{
u32 remap;
struct e7xxx_pvt *pvt = (struct e7xxx_pvt *)mci->pvt_info;
debugf3("%s()\n", __func__);
if ((page < pvt->tolm) ||
((page >= 0x100000) && (page < pvt->remapbase)))
return page;
remap = (page - pvt->tolm) + pvt->remapbase;
if (remap < pvt->remaplimit)
return remap;
e7xxx_printk(KERN_ERR, "Invalid page %lx - out of range\n", page);
return pvt->tolm - 1;
}
static void process_ce(struct mem_ctl_info *mci, struct e7xxx_error_info *info)
{
u32 error_1b, page;
u16 syndrome;
int row;
int channel;
debugf3("%s()\n", __func__);
error_1b = info->dram_celog_add;
page = error_1b >> 6;
syndrome = info->dram_celog_syndrome;
row = edac_mc_find_csrow_by_page(mci, page);
channel = e7xxx_find_channel(syndrome);
edac_mc_handle_error(HW_EVENT_ERR_CORRECTED, mci, page, 0, syndrome,
row, channel, -1, "e7xxx CE", "", NULL);
}
static void process_ce_no_info(struct mem_ctl_info *mci)
{
debugf3("%s()\n", __func__);
edac_mc_handle_error(HW_EVENT_ERR_UNCORRECTED, mci, 0, 0, 0, -1, -1, -1,
"e7xxx CE log register overflow", "", NULL);
}
static void process_ue(struct mem_ctl_info *mci, struct e7xxx_error_info *info)
{
u32 error_2b, block_page;
int row;
debugf3("%s()\n", __func__);
error_2b = info->dram_uelog_add;
block_page = error_2b >> 6;
row = edac_mc_find_csrow_by_page(mci, block_page);
edac_mc_handle_error(HW_EVENT_ERR_UNCORRECTED, mci, block_page, 0, 0,
row, -1, -1, "e7xxx UE", "", NULL);
}
static void process_ue_no_info(struct mem_ctl_info *mci)
{
debugf3("%s()\n", __func__);
edac_mc_handle_error(HW_EVENT_ERR_UNCORRECTED, mci, 0, 0, 0, -1, -1, -1,
"e7xxx UE log register overflow", "", NULL);
}
static void e7xxx_get_error_info(struct mem_ctl_info *mci,
struct e7xxx_error_info *info)
{
struct e7xxx_pvt *pvt;
pvt = (struct e7xxx_pvt *)mci->pvt_info;
pci_read_config_byte(pvt->bridge_ck, E7XXX_DRAM_FERR, &info->dram_ferr);
pci_read_config_byte(pvt->bridge_ck, E7XXX_DRAM_NERR, &info->dram_nerr);
if ((info->dram_ferr & 1) || (info->dram_nerr & 1)) {
pci_read_config_dword(pvt->bridge_ck, E7XXX_DRAM_CELOG_ADD,
&info->dram_celog_add);
pci_read_config_word(pvt->bridge_ck,
E7XXX_DRAM_CELOG_SYNDROME,
&info->dram_celog_syndrome);
}
if ((info->dram_ferr & 2) || (info->dram_nerr & 2))
pci_read_config_dword(pvt->bridge_ck, E7XXX_DRAM_UELOG_ADD,
&info->dram_uelog_add);
if (info->dram_ferr & 3)
pci_write_bits8(pvt->bridge_ck, E7XXX_DRAM_FERR, 0x03, 0x03);
if (info->dram_nerr & 3)
pci_write_bits8(pvt->bridge_ck, E7XXX_DRAM_NERR, 0x03, 0x03);
}
static int e7xxx_process_error_info(struct mem_ctl_info *mci,
struct e7xxx_error_info *info,
int handle_errors)
{
int error_found;
error_found = 0;
if (info->dram_ferr & 1) {
error_found = 1;
if (handle_errors)
process_ce(mci, info);
}
if (info->dram_ferr & 2) {
error_found = 1;
if (handle_errors)
process_ue(mci, info);
}
if (info->dram_nerr & 1) {
error_found = 1;
if (handle_errors) {
if (info->dram_ferr & 1)
process_ce_no_info(mci);
else
process_ce(mci, info);
}
}
if (info->dram_nerr & 2) {
error_found = 1;
if (handle_errors) {
if (info->dram_ferr & 2)
process_ue_no_info(mci);
else
process_ue(mci, info);
}
}
return error_found;
}
static void e7xxx_check(struct mem_ctl_info *mci)
{
struct e7xxx_error_info info;
debugf3("%s()\n", __func__);
e7xxx_get_error_info(mci, &info);
e7xxx_process_error_info(mci, &info, 1);
}
static inline int dual_channel_active(u32 drc, int dev_idx)
{
return (dev_idx == E7501) ? ((drc >> 22) & 0x1) : 1;
}
static inline int drb_granularity(u32 drc, int dev_idx)
{
return (dev_idx == E7501) ? ((drc >> 18) & 0x3) : 1;
}
static void e7xxx_init_csrows(struct mem_ctl_info *mci, struct pci_dev *pdev,
int dev_idx, u32 drc)
{
unsigned long last_cumul_size;
int index, j;
u8 value;
u32 dra, cumul_size, nr_pages;
int drc_chan, drc_drbg, drc_ddim, mem_dev;
struct csrow_info *csrow;
struct dimm_info *dimm;
pci_read_config_dword(pdev, E7XXX_DRA, &dra);
drc_chan = dual_channel_active(drc, dev_idx);
drc_drbg = drb_granularity(drc, dev_idx);
drc_ddim = (drc >> 20) & 0x3;
last_cumul_size = 0;
for (index = 0; index < mci->nr_csrows; index++) {
mem_dev = (dra >> (index * 4 + 3)) & 0x1;
csrow = &mci->csrows[index];
pci_read_config_byte(pdev, E7XXX_DRB + index, &value);
cumul_size = value << (25 + drc_drbg - PAGE_SHIFT);
debugf3("%s(): (%d) cumul_size 0x%x\n", __func__, index,
cumul_size);
if (cumul_size == last_cumul_size)
continue;
csrow->first_page = last_cumul_size;
csrow->last_page = cumul_size - 1;
nr_pages = cumul_size - last_cumul_size;
last_cumul_size = cumul_size;
for (j = 0; j < drc_chan + 1; j++) {
dimm = csrow->channels[j].dimm;
dimm->nr_pages = nr_pages / (drc_chan + 1);
dimm->grain = 1 << 12;
dimm->mtype = MEM_RDDR;
dimm->dtype = mem_dev ? DEV_X4 : DEV_X8;
if (drc_ddim) {
if (drc_chan && mem_dev) {
dimm->edac_mode = EDAC_S4ECD4ED;
mci->edac_cap |= EDAC_FLAG_S4ECD4ED;
} else {
dimm->edac_mode = EDAC_SECDED;
mci->edac_cap |= EDAC_FLAG_SECDED;
}
} else
dimm->edac_mode = EDAC_NONE;
}
}
}
static int e7xxx_probe1(struct pci_dev *pdev, int dev_idx)
{
u16 pci_data;
struct mem_ctl_info *mci = NULL;
struct edac_mc_layer layers[2];
struct e7xxx_pvt *pvt = NULL;
u32 drc;
int drc_chan;
struct e7xxx_error_info discard;
debugf0("%s(): mci\n", __func__);
pci_read_config_dword(pdev, E7XXX_DRC, &drc);
drc_chan = dual_channel_active(drc, dev_idx);
layers[0].type = EDAC_MC_LAYER_CHIP_SELECT;
layers[0].size = E7XXX_NR_CSROWS;
layers[0].is_virt_csrow = true;
layers[1].type = EDAC_MC_LAYER_CHANNEL;
layers[1].size = drc_chan + 1;
layers[1].is_virt_csrow = false;
mci = edac_mc_alloc(0, ARRAY_SIZE(layers), layers, sizeof(*pvt));
if (mci == NULL)
return -ENOMEM;
debugf3("%s(): init mci\n", __func__);
mci->mtype_cap = MEM_FLAG_RDDR;
mci->edac_ctl_cap = EDAC_FLAG_NONE | EDAC_FLAG_SECDED |
EDAC_FLAG_S4ECD4ED;
mci->mod_name = EDAC_MOD_STR;
mci->mod_ver = E7XXX_REVISION;
mci->dev = &pdev->dev;
debugf3("%s(): init pvt\n", __func__);
pvt = (struct e7xxx_pvt *)mci->pvt_info;
pvt->dev_info = &e7xxx_devs[dev_idx];
pvt->bridge_ck = pci_get_device(PCI_VENDOR_ID_INTEL,
pvt->dev_info->err_dev, pvt->bridge_ck);
if (!pvt->bridge_ck) {
e7xxx_printk(KERN_ERR, "error reporting device not found:"
"vendor %x device 0x%x (broken BIOS?)\n",
PCI_VENDOR_ID_INTEL, e7xxx_devs[dev_idx].err_dev);
goto fail0;
}
debugf3("%s(): more mci init\n", __func__);
mci->ctl_name = pvt->dev_info->ctl_name;
mci->dev_name = pci_name(pdev);
mci->edac_check = e7xxx_check;
mci->ctl_page_to_phys = ctl_page_to_phys;
e7xxx_init_csrows(mci, pdev, dev_idx, drc);
mci->edac_cap |= EDAC_FLAG_NONE;
debugf3("%s(): tolm, remapbase, remaplimit\n", __func__);
pci_read_config_word(pdev, E7XXX_TOLM, &pci_data);
pvt->tolm = ((u32) pci_data) << 4;
pci_read_config_word(pdev, E7XXX_REMAPBASE, &pci_data);
pvt->remapbase = ((u32) pci_data) << 14;
pci_read_config_word(pdev, E7XXX_REMAPLIMIT, &pci_data);
pvt->remaplimit = ((u32) pci_data) << 14;
e7xxx_printk(KERN_INFO,
"tolm = %x, remapbase = %x, remaplimit = %x\n", pvt->tolm,
pvt->remapbase, pvt->remaplimit);
e7xxx_get_error_info(mci, &discard);
if (edac_mc_add_mc(mci)) {
debugf3("%s(): failed edac_mc_add_mc()\n", __func__);
goto fail1;
}
e7xxx_pci = edac_pci_create_generic_ctl(&pdev->dev, EDAC_MOD_STR);
if (!e7xxx_pci) {
printk(KERN_WARNING
"%s(): Unable to create PCI control\n",
__func__);
printk(KERN_WARNING
"%s(): PCI error report via EDAC not setup\n",
__func__);
}
debugf3("%s(): success\n", __func__);
return 0;
fail1:
pci_dev_put(pvt->bridge_ck);
fail0:
edac_mc_free(mci);
return -ENODEV;
}
static int __devinit e7xxx_init_one(struct pci_dev *pdev,
const struct pci_device_id *ent)
{
debugf0("%s()\n", __func__);
return pci_enable_device(pdev) ?
-EIO : e7xxx_probe1(pdev, ent->driver_data);
}
static void __devexit e7xxx_remove_one(struct pci_dev *pdev)
{
struct mem_ctl_info *mci;
struct e7xxx_pvt *pvt;
debugf0("%s()\n", __func__);
if (e7xxx_pci)
edac_pci_release_generic_ctl(e7xxx_pci);
if ((mci = edac_mc_del_mc(&pdev->dev)) == NULL)
return;
pvt = (struct e7xxx_pvt *)mci->pvt_info;
pci_dev_put(pvt->bridge_ck);
edac_mc_free(mci);
}
static int __init e7xxx_init(void)
{
opstate_init();
return pci_register_driver(&e7xxx_driver);
}
static void __exit e7xxx_exit(void)
{
pci_unregister_driver(&e7xxx_driver);
}
