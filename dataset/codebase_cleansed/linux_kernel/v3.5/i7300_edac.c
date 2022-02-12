static const char *get_err_from_table(const char *table[], int size, int pos)
{
if (unlikely(pos >= size))
return "Reserved";
if (unlikely(!table[pos]))
return "Reserved";
return table[pos];
}
static void i7300_process_error_global(struct mem_ctl_info *mci)
{
struct i7300_pvt *pvt;
u32 errnum, error_reg;
unsigned long errors;
const char *specific;
bool is_fatal;
pvt = mci->pvt_info;
pci_read_config_dword(pvt->pci_dev_16_2_fsb_err_regs,
FERR_GLOBAL_HI, &error_reg);
if (unlikely(error_reg)) {
errors = error_reg;
errnum = find_first_bit(&errors,
ARRAY_SIZE(ferr_global_hi_name));
specific = GET_ERR_FROM_TABLE(ferr_global_hi_name, errnum);
is_fatal = ferr_global_hi_is_fatal(errnum);
pci_write_config_dword(pvt->pci_dev_16_2_fsb_err_regs,
FERR_GLOBAL_HI, error_reg);
goto error_global;
}
pci_read_config_dword(pvt->pci_dev_16_2_fsb_err_regs,
FERR_GLOBAL_LO, &error_reg);
if (unlikely(error_reg)) {
errors = error_reg;
errnum = find_first_bit(&errors,
ARRAY_SIZE(ferr_global_lo_name));
specific = GET_ERR_FROM_TABLE(ferr_global_lo_name, errnum);
is_fatal = ferr_global_lo_is_fatal(errnum);
pci_write_config_dword(pvt->pci_dev_16_2_fsb_err_regs,
FERR_GLOBAL_LO, error_reg);
goto error_global;
}
return;
error_global:
i7300_mc_printk(mci, KERN_EMERG, "%s misc error: %s\n",
is_fatal ? "Fatal" : "NOT fatal", specific);
}
static void i7300_process_fbd_error(struct mem_ctl_info *mci)
{
struct i7300_pvt *pvt;
u32 errnum, value, error_reg;
u16 val16;
unsigned branch, channel, bank, rank, cas, ras;
u32 syndrome;
unsigned long errors;
const char *specific;
bool is_wr;
pvt = mci->pvt_info;
pci_read_config_dword(pvt->pci_dev_16_1_fsb_addr_map,
FERR_FAT_FBD, &error_reg);
if (unlikely(error_reg & FERR_FAT_FBD_ERR_MASK)) {
errors = error_reg & FERR_FAT_FBD_ERR_MASK ;
errnum = find_first_bit(&errors,
ARRAY_SIZE(ferr_fat_fbd_name));
specific = GET_ERR_FROM_TABLE(ferr_fat_fbd_name, errnum);
branch = (GET_FBD_FAT_IDX(error_reg) == 2) ? 1 : 0;
pci_read_config_word(pvt->pci_dev_16_1_fsb_addr_map,
NRECMEMA, &val16);
bank = NRECMEMA_BANK(val16);
rank = NRECMEMA_RANK(val16);
pci_read_config_dword(pvt->pci_dev_16_1_fsb_addr_map,
NRECMEMB, &value);
is_wr = NRECMEMB_IS_WR(value);
cas = NRECMEMB_CAS(value);
ras = NRECMEMB_RAS(value);
pci_write_config_dword(pvt->pci_dev_16_1_fsb_addr_map,
FERR_FAT_FBD, error_reg);
snprintf(pvt->tmp_prt_buffer, PAGE_SIZE,
"Bank=%d RAS=%d CAS=%d Err=0x%lx (%s))",
bank, ras, cas, errors, specific);
edac_mc_handle_error(HW_EVENT_ERR_FATAL, mci, 0, 0, 0,
branch, -1, rank,
is_wr ? "Write error" : "Read error",
pvt->tmp_prt_buffer, NULL);
}
pci_read_config_dword(pvt->pci_dev_16_1_fsb_addr_map,
FERR_NF_FBD, &error_reg);
if (unlikely(error_reg & FERR_NF_FBD_ERR_MASK)) {
errors = error_reg & FERR_NF_FBD_ERR_MASK;
errnum = find_first_bit(&errors,
ARRAY_SIZE(ferr_nf_fbd_name));
specific = GET_ERR_FROM_TABLE(ferr_nf_fbd_name, errnum);
branch = (GET_FBD_FAT_IDX(error_reg) == 2) ? 1 : 0;
pci_read_config_dword(pvt->pci_dev_16_1_fsb_addr_map,
REDMEMA, &syndrome);
pci_read_config_word(pvt->pci_dev_16_1_fsb_addr_map,
RECMEMA, &val16);
bank = RECMEMA_BANK(val16);
rank = RECMEMA_RANK(val16);
pci_read_config_dword(pvt->pci_dev_16_1_fsb_addr_map,
RECMEMB, &value);
is_wr = RECMEMB_IS_WR(value);
cas = RECMEMB_CAS(value);
ras = RECMEMB_RAS(value);
pci_read_config_dword(pvt->pci_dev_16_1_fsb_addr_map,
REDMEMB, &value);
channel = (branch << 1);
if (IS_SECOND_CH(value))
channel++;
pci_write_config_dword(pvt->pci_dev_16_1_fsb_addr_map,
FERR_NF_FBD, error_reg);
snprintf(pvt->tmp_prt_buffer, PAGE_SIZE,
"DRAM-Bank=%d RAS=%d CAS=%d, Err=0x%lx (%s))",
bank, ras, cas, errors, specific);
edac_mc_handle_error(HW_EVENT_ERR_CORRECTED, mci, 0, 0,
syndrome,
branch >> 1, channel % 2, rank,
is_wr ? "Write error" : "Read error",
pvt->tmp_prt_buffer, NULL);
}
return;
}
static void i7300_check_error(struct mem_ctl_info *mci)
{
i7300_process_error_global(mci);
i7300_process_fbd_error(mci);
}
static void i7300_clear_error(struct mem_ctl_info *mci)
{
struct i7300_pvt *pvt = mci->pvt_info;
u32 value;
pci_read_config_dword(pvt->pci_dev_16_2_fsb_err_regs,
FERR_GLOBAL_HI, &value);
pci_write_config_dword(pvt->pci_dev_16_2_fsb_err_regs,
FERR_GLOBAL_HI, value);
pci_read_config_dword(pvt->pci_dev_16_2_fsb_err_regs,
FERR_GLOBAL_LO, &value);
pci_write_config_dword(pvt->pci_dev_16_2_fsb_err_regs,
FERR_GLOBAL_LO, value);
pci_read_config_dword(pvt->pci_dev_16_1_fsb_addr_map,
FERR_FAT_FBD, &value);
pci_write_config_dword(pvt->pci_dev_16_1_fsb_addr_map,
FERR_FAT_FBD, value);
pci_read_config_dword(pvt->pci_dev_16_1_fsb_addr_map,
FERR_NF_FBD, &value);
pci_write_config_dword(pvt->pci_dev_16_1_fsb_addr_map,
FERR_NF_FBD, value);
}
static void i7300_enable_error_reporting(struct mem_ctl_info *mci)
{
struct i7300_pvt *pvt = mci->pvt_info;
u32 fbd_error_mask;
pci_read_config_dword(pvt->pci_dev_16_1_fsb_addr_map,
EMASK_FBD, &fbd_error_mask);
fbd_error_mask &= ~(EMASK_FBD_ERR_MASK);
pci_write_config_dword(pvt->pci_dev_16_1_fsb_addr_map,
EMASK_FBD, fbd_error_mask);
}
static int decode_mtr(struct i7300_pvt *pvt,
int slot, int ch, int branch,
struct i7300_dimm_info *dinfo,
struct dimm_info *dimm)
{
int mtr, ans, addrBits, channel;
channel = to_channel(ch, branch);
mtr = pvt->mtr[slot][branch];
ans = MTR_DIMMS_PRESENT(mtr) ? 1 : 0;
debugf2("\tMTR%d CH%d: DIMMs are %s (mtr)\n",
slot, channel,
ans ? "Present" : "NOT Present");
if (!ans)
return 0;
addrBits = MTR_DRAM_BANKS_ADDR_BITS;
addrBits += MTR_DIMM_ROWS_ADDR_BITS(mtr);
addrBits += MTR_DIMM_COLS_ADDR_BITS(mtr);
addrBits += MTR_DIMM_RANKS(mtr);
addrBits += 6;
addrBits -= 20;
addrBits -= 3;
dinfo->megabytes = 1 << addrBits;
debugf2("\t\tWIDTH: x%d\n", MTR_DRAM_WIDTH(mtr));
debugf2("\t\tELECTRICAL THROTTLING is %s\n",
MTR_DIMMS_ETHROTTLE(mtr) ? "enabled" : "disabled");
debugf2("\t\tNUMBANK: %d bank(s)\n", MTR_DRAM_BANKS(mtr));
debugf2("\t\tNUMRANK: %s\n", MTR_DIMM_RANKS(mtr) ? "double" : "single");
debugf2("\t\tNUMROW: %s\n", numrow_toString[MTR_DIMM_ROWS(mtr)]);
debugf2("\t\tNUMCOL: %s\n", numcol_toString[MTR_DIMM_COLS(mtr)]);
debugf2("\t\tSIZE: %d MB\n", dinfo->megabytes);
dimm->nr_pages = MiB_TO_PAGES(dinfo->megabytes);
dimm->grain = 8;
dimm->mtype = MEM_FB_DDR2;
if (IS_SINGLE_MODE(pvt->mc_settings_a)) {
dimm->edac_mode = EDAC_SECDED;
debugf2("\t\tECC code is 8-byte-over-32-byte SECDED+ code\n");
} else {
debugf2("\t\tECC code is on Lockstep mode\n");
if (MTR_DRAM_WIDTH(mtr) == 8)
dimm->edac_mode = EDAC_S8ECD8ED;
else
dimm->edac_mode = EDAC_S4ECD4ED;
}
if (MTR_DRAM_WIDTH(mtr) == 8) {
debugf2("\t\tScrub algorithm for x8 is on %s mode\n",
IS_SCRBALGO_ENHANCED(pvt->mc_settings) ?
"enhanced" : "normal");
dimm->dtype = DEV_X8;
} else
dimm->dtype = DEV_X4;
return mtr;
}
static void print_dimm_size(struct i7300_pvt *pvt)
{
#ifdef CONFIG_EDAC_DEBUG
struct i7300_dimm_info *dinfo;
char *p;
int space, n;
int channel, slot;
space = PAGE_SIZE;
p = pvt->tmp_prt_buffer;
n = snprintf(p, space, " ");
p += n;
space -= n;
for (channel = 0; channel < MAX_CHANNELS; channel++) {
n = snprintf(p, space, "channel %d | ", channel);
p += n;
space -= n;
}
debugf2("%s\n", pvt->tmp_prt_buffer);
p = pvt->tmp_prt_buffer;
space = PAGE_SIZE;
n = snprintf(p, space, "-------------------------------"
"------------------------------");
p += n;
space -= n;
debugf2("%s\n", pvt->tmp_prt_buffer);
p = pvt->tmp_prt_buffer;
space = PAGE_SIZE;
for (slot = 0; slot < MAX_SLOTS; slot++) {
n = snprintf(p, space, "csrow/SLOT %d ", slot);
p += n;
space -= n;
for (channel = 0; channel < MAX_CHANNELS; channel++) {
dinfo = &pvt->dimm_info[slot][channel];
n = snprintf(p, space, "%4d MB | ", dinfo->megabytes);
p += n;
space -= n;
}
debugf2("%s\n", pvt->tmp_prt_buffer);
p = pvt->tmp_prt_buffer;
space = PAGE_SIZE;
}
n = snprintf(p, space, "-------------------------------"
"------------------------------");
p += n;
space -= n;
debugf2("%s\n", pvt->tmp_prt_buffer);
p = pvt->tmp_prt_buffer;
space = PAGE_SIZE;
#endif
}
static int i7300_init_csrows(struct mem_ctl_info *mci)
{
struct i7300_pvt *pvt;
struct i7300_dimm_info *dinfo;
int rc = -ENODEV;
int mtr;
int ch, branch, slot, channel;
struct dimm_info *dimm;
pvt = mci->pvt_info;
debugf2("Memory Technology Registers:\n");
for (branch = 0; branch < MAX_BRANCHES; branch++) {
channel = to_channel(0, branch);
pci_read_config_word(pvt->pci_dev_2x_0_fbd_branch[branch],
AMBPRESENT_0,
&pvt->ambpresent[channel]);
debugf2("\t\tAMB-present CH%d = 0x%x:\n",
channel, pvt->ambpresent[channel]);
channel = to_channel(1, branch);
pci_read_config_word(pvt->pci_dev_2x_0_fbd_branch[branch],
AMBPRESENT_1,
&pvt->ambpresent[channel]);
debugf2("\t\tAMB-present CH%d = 0x%x:\n",
channel, pvt->ambpresent[channel]);
}
for (slot = 0; slot < MAX_SLOTS; slot++) {
int where = mtr_regs[slot];
for (branch = 0; branch < MAX_BRANCHES; branch++) {
pci_read_config_word(pvt->pci_dev_2x_0_fbd_branch[branch],
where,
&pvt->mtr[slot][branch]);
for (ch = 0; ch < MAX_CH_PER_BRANCH; ch++) {
int channel = to_channel(ch, branch);
dimm = EDAC_DIMM_PTR(mci->layers, mci->dimms,
mci->n_layers, branch, ch, slot);
dinfo = &pvt->dimm_info[slot][channel];
mtr = decode_mtr(pvt, slot, ch, branch,
dinfo, dimm);
if (!MTR_DIMMS_PRESENT(mtr))
continue;
rc = 0;
}
}
}
return rc;
}
static void decode_mir(int mir_no, u16 mir[MAX_MIR])
{
if (mir[mir_no] & 3)
debugf2("MIR%d: limit= 0x%x Branch(es) that participate:"
" %s %s\n",
mir_no,
(mir[mir_no] >> 4) & 0xfff,
(mir[mir_no] & 1) ? "B0" : "",
(mir[mir_no] & 2) ? "B1" : "");
}
static int i7300_get_mc_regs(struct mem_ctl_info *mci)
{
struct i7300_pvt *pvt;
u32 actual_tolm;
int i, rc;
pvt = mci->pvt_info;
pci_read_config_dword(pvt->pci_dev_16_0_fsb_ctlr, AMBASE,
(u32 *) &pvt->ambase);
debugf2("AMBASE= 0x%lx\n", (long unsigned int)pvt->ambase);
pci_read_config_word(pvt->pci_dev_16_1_fsb_addr_map, TOLM, &pvt->tolm);
pvt->tolm >>= 12;
debugf2("TOLM (number of 256M regions) =%u (0x%x)\n", pvt->tolm,
pvt->tolm);
actual_tolm = (u32) ((1000l * pvt->tolm) >> (30 - 28));
debugf2("Actual TOLM byte addr=%u.%03u GB (0x%x)\n",
actual_tolm/1000, actual_tolm % 1000, pvt->tolm << 28);
pci_read_config_dword(pvt->pci_dev_16_1_fsb_addr_map, MC_SETTINGS,
&pvt->mc_settings);
pci_read_config_dword(pvt->pci_dev_16_1_fsb_addr_map, MC_SETTINGS_A,
&pvt->mc_settings_a);
if (IS_SINGLE_MODE(pvt->mc_settings_a))
debugf0("Memory controller operating on single mode\n");
else
debugf0("Memory controller operating on %s mode\n",
IS_MIRRORED(pvt->mc_settings) ? "mirrored" : "non-mirrored");
debugf0("Error detection is %s\n",
IS_ECC_ENABLED(pvt->mc_settings) ? "enabled" : "disabled");
debugf0("Retry is %s\n",
IS_RETRY_ENABLED(pvt->mc_settings) ? "enabled" : "disabled");
pci_read_config_word(pvt->pci_dev_16_1_fsb_addr_map, MIR0,
&pvt->mir[0]);
pci_read_config_word(pvt->pci_dev_16_1_fsb_addr_map, MIR1,
&pvt->mir[1]);
pci_read_config_word(pvt->pci_dev_16_1_fsb_addr_map, MIR2,
&pvt->mir[2]);
for (i = 0; i < MAX_MIR; i++)
decode_mir(i, pvt->mir);
rc = i7300_init_csrows(mci);
if (rc < 0)
return rc;
print_dimm_size(pvt);
return 0;
}
static void i7300_put_devices(struct mem_ctl_info *mci)
{
struct i7300_pvt *pvt;
int branch;
pvt = mci->pvt_info;
for (branch = 0; branch < MAX_CH_PER_BRANCH; branch++)
pci_dev_put(pvt->pci_dev_2x_0_fbd_branch[branch]);
pci_dev_put(pvt->pci_dev_16_2_fsb_err_regs);
pci_dev_put(pvt->pci_dev_16_1_fsb_addr_map);
}
static int __devinit i7300_get_devices(struct mem_ctl_info *mci)
{
struct i7300_pvt *pvt;
struct pci_dev *pdev;
pvt = mci->pvt_info;
pdev = NULL;
while (!pvt->pci_dev_16_1_fsb_addr_map ||
!pvt->pci_dev_16_2_fsb_err_regs) {
pdev = pci_get_device(PCI_VENDOR_ID_INTEL,
PCI_DEVICE_ID_INTEL_I7300_MCH_ERR, pdev);
if (!pdev) {
i7300_printk(KERN_ERR,
"'system address,Process Bus' "
"device not found:"
"vendor 0x%x device 0x%x ERR funcs "
"(broken BIOS?)\n",
PCI_VENDOR_ID_INTEL,
PCI_DEVICE_ID_INTEL_I7300_MCH_ERR);
goto error;
}
switch (PCI_FUNC(pdev->devfn)) {
case 1:
pvt->pci_dev_16_1_fsb_addr_map = pdev;
break;
case 2:
pvt->pci_dev_16_2_fsb_err_regs = pdev;
break;
}
}
debugf1("System Address, processor bus- PCI Bus ID: %s %x:%x\n",
pci_name(pvt->pci_dev_16_0_fsb_ctlr),
pvt->pci_dev_16_0_fsb_ctlr->vendor,
pvt->pci_dev_16_0_fsb_ctlr->device);
debugf1("Branchmap, control and errors - PCI Bus ID: %s %x:%x\n",
pci_name(pvt->pci_dev_16_1_fsb_addr_map),
pvt->pci_dev_16_1_fsb_addr_map->vendor,
pvt->pci_dev_16_1_fsb_addr_map->device);
debugf1("FSB Error Regs - PCI Bus ID: %s %x:%x\n",
pci_name(pvt->pci_dev_16_2_fsb_err_regs),
pvt->pci_dev_16_2_fsb_err_regs->vendor,
pvt->pci_dev_16_2_fsb_err_regs->device);
pvt->pci_dev_2x_0_fbd_branch[0] = pci_get_device(PCI_VENDOR_ID_INTEL,
PCI_DEVICE_ID_INTEL_I7300_MCH_FB0,
NULL);
if (!pvt->pci_dev_2x_0_fbd_branch[0]) {
i7300_printk(KERN_ERR,
"MC: 'BRANCH 0' device not found:"
"vendor 0x%x device 0x%x Func 0 (broken BIOS?)\n",
PCI_VENDOR_ID_INTEL, PCI_DEVICE_ID_INTEL_I7300_MCH_FB0);
goto error;
}
pvt->pci_dev_2x_0_fbd_branch[1] = pci_get_device(PCI_VENDOR_ID_INTEL,
PCI_DEVICE_ID_INTEL_I7300_MCH_FB1,
NULL);
if (!pvt->pci_dev_2x_0_fbd_branch[1]) {
i7300_printk(KERN_ERR,
"MC: 'BRANCH 1' device not found:"
"vendor 0x%x device 0x%x Func 0 "
"(broken BIOS?)\n",
PCI_VENDOR_ID_INTEL,
PCI_DEVICE_ID_INTEL_I7300_MCH_FB1);
goto error;
}
return 0;
error:
i7300_put_devices(mci);
return -ENODEV;
}
static int __devinit i7300_init_one(struct pci_dev *pdev,
const struct pci_device_id *id)
{
struct mem_ctl_info *mci;
struct edac_mc_layer layers[3];
struct i7300_pvt *pvt;
int rc;
rc = pci_enable_device(pdev);
if (rc == -EIO)
return rc;
debugf0("MC: " __FILE__ ": %s(), pdev bus %u dev=0x%x fn=0x%x\n",
__func__,
pdev->bus->number,
PCI_SLOT(pdev->devfn), PCI_FUNC(pdev->devfn));
if (PCI_FUNC(pdev->devfn) != 0)
return -ENODEV;
layers[0].type = EDAC_MC_LAYER_BRANCH;
layers[0].size = MAX_BRANCHES;
layers[0].is_virt_csrow = false;
layers[1].type = EDAC_MC_LAYER_CHANNEL;
layers[1].size = MAX_CH_PER_BRANCH;
layers[1].is_virt_csrow = true;
layers[2].type = EDAC_MC_LAYER_SLOT;
layers[2].size = MAX_SLOTS;
layers[2].is_virt_csrow = true;
mci = edac_mc_alloc(0, ARRAY_SIZE(layers), layers, sizeof(*pvt));
if (mci == NULL)
return -ENOMEM;
debugf0("MC: " __FILE__ ": %s(): mci = %p\n", __func__, mci);
mci->dev = &pdev->dev;
pvt = mci->pvt_info;
pvt->pci_dev_16_0_fsb_ctlr = pdev;
pvt->tmp_prt_buffer = kmalloc(PAGE_SIZE, GFP_KERNEL);
if (!pvt->tmp_prt_buffer) {
edac_mc_free(mci);
return -ENOMEM;
}
if (i7300_get_devices(mci))
goto fail0;
mci->mc_idx = 0;
mci->mtype_cap = MEM_FLAG_FB_DDR2;
mci->edac_ctl_cap = EDAC_FLAG_NONE;
mci->edac_cap = EDAC_FLAG_NONE;
mci->mod_name = "i7300_edac.c";
mci->mod_ver = I7300_REVISION;
mci->ctl_name = i7300_devs[0].ctl_name;
mci->dev_name = pci_name(pdev);
mci->ctl_page_to_phys = NULL;
mci->edac_check = i7300_check_error;
if (i7300_get_mc_regs(mci)) {
debugf0("MC: Setting mci->edac_cap to EDAC_FLAG_NONE\n"
" because i7300_init_csrows() returned nonzero "
"value\n");
mci->edac_cap = EDAC_FLAG_NONE;
} else {
debugf1("MC: Enable error reporting now\n");
i7300_enable_error_reporting(mci);
}
if (edac_mc_add_mc(mci)) {
debugf0("MC: " __FILE__
": %s(): failed edac_mc_add_mc()\n", __func__);
goto fail1;
}
i7300_clear_error(mci);
i7300_pci = edac_pci_create_generic_ctl(&pdev->dev, EDAC_MOD_STR);
if (!i7300_pci) {
printk(KERN_WARNING
"%s(): Unable to create PCI control\n",
__func__);
printk(KERN_WARNING
"%s(): PCI error report via EDAC not setup\n",
__func__);
}
return 0;
fail1:
i7300_put_devices(mci);
fail0:
kfree(pvt->tmp_prt_buffer);
edac_mc_free(mci);
return -ENODEV;
}
static void __devexit i7300_remove_one(struct pci_dev *pdev)
{
struct mem_ctl_info *mci;
char *tmp;
debugf0(__FILE__ ": %s()\n", __func__);
if (i7300_pci)
edac_pci_release_generic_ctl(i7300_pci);
mci = edac_mc_del_mc(&pdev->dev);
if (!mci)
return;
tmp = ((struct i7300_pvt *)mci->pvt_info)->tmp_prt_buffer;
i7300_put_devices(mci);
kfree(tmp);
edac_mc_free(mci);
}
static int __init i7300_init(void)
{
int pci_rc;
debugf2("MC: " __FILE__ ": %s()\n", __func__);
opstate_init();
pci_rc = pci_register_driver(&i7300_driver);
return (pci_rc < 0) ? pci_rc : 0;
}
static void __exit i7300_exit(void)
{
debugf2("MC: " __FILE__ ": %s()\n", __func__);
pci_unregister_driver(&i7300_driver);
}
