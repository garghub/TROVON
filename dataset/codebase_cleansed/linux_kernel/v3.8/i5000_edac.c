static void i5000_get_error_info(struct mem_ctl_info *mci,
struct i5000_error_info *info)
{
struct i5000_pvt *pvt;
u32 value;
pvt = mci->pvt_info;
pci_read_config_dword(pvt->branchmap_werrors, FERR_FAT_FBD, &value);
value &= (FERR_FAT_FBDCHAN | FERR_FAT_MASK);
if (value & FERR_FAT_MASK) {
info->ferr_fat_fbd = value;
pci_read_config_dword(pvt->branchmap_werrors,
NERR_FAT_FBD, &info->nerr_fat_fbd);
pci_read_config_word(pvt->branchmap_werrors,
NRECMEMA, &info->nrecmema);
pci_read_config_word(pvt->branchmap_werrors,
NRECMEMB, &info->nrecmemb);
pci_write_config_dword(pvt->branchmap_werrors,
FERR_FAT_FBD, value);
} else {
info->ferr_fat_fbd = 0;
info->nerr_fat_fbd = 0;
info->nrecmema = 0;
info->nrecmemb = 0;
}
pci_read_config_dword(pvt->branchmap_werrors, FERR_NF_FBD, &value);
if (value & FERR_NF_MASK) {
info->ferr_nf_fbd = value;
pci_read_config_dword(pvt->branchmap_werrors,
NERR_NF_FBD, &info->nerr_nf_fbd);
pci_read_config_word(pvt->branchmap_werrors,
RECMEMA, &info->recmema);
pci_read_config_dword(pvt->branchmap_werrors,
RECMEMB, &info->recmemb);
pci_read_config_dword(pvt->branchmap_werrors,
REDMEMB, &info->redmemb);
pci_write_config_dword(pvt->branchmap_werrors,
FERR_NF_FBD, value);
} else {
info->ferr_nf_fbd = 0;
info->nerr_nf_fbd = 0;
info->recmema = 0;
info->recmemb = 0;
info->redmemb = 0;
}
}
static void i5000_process_fatal_error_info(struct mem_ctl_info *mci,
struct i5000_error_info *info,
int handle_errors)
{
char msg[EDAC_MC_LABEL_LEN + 1 + 160];
char *specific = NULL;
u32 allErrors;
int channel;
int bank;
int rank;
int rdwr;
int ras, cas;
allErrors = (info->ferr_fat_fbd & FERR_FAT_MASK);
if (!allErrors)
return;
channel = EXTRACT_FBDCHAN_INDX(info->ferr_fat_fbd);
bank = NREC_BANK(info->nrecmema);
rank = NREC_RANK(info->nrecmema);
rdwr = NREC_RDWR(info->nrecmema);
ras = NREC_RAS(info->nrecmemb);
cas = NREC_CAS(info->nrecmemb);
edac_dbg(0, "\t\tCSROW= %d Channel= %d (DRAM Bank= %d rdwr= %s ras= %d cas= %d)\n",
rank, channel, bank,
rdwr ? "Write" : "Read", ras, cas);
switch (allErrors) {
case FERR_FAT_M1ERR:
specific = "Alert on non-redundant retry or fast "
"reset timeout";
break;
case FERR_FAT_M2ERR:
specific = "Northbound CRC error on non-redundant "
"retry";
break;
case FERR_FAT_M3ERR:
{
static int done;
if (done)
return;
done++;
specific = ">Tmid Thermal event with intelligent "
"throttling disabled";
}
break;
}
snprintf(msg, sizeof(msg),
"Bank=%d RAS=%d CAS=%d FATAL Err=0x%x (%s)",
bank, ras, cas, allErrors, specific);
edac_mc_handle_error(HW_EVENT_ERR_FATAL, mci, 1, 0, 0, 0,
channel >> 1, channel & 1, rank,
rdwr ? "Write error" : "Read error",
msg);
}
static void i5000_process_nonfatal_error_info(struct mem_ctl_info *mci,
struct i5000_error_info *info,
int handle_errors)
{
char msg[EDAC_MC_LABEL_LEN + 1 + 170];
char *specific = NULL;
u32 allErrors;
u32 ue_errors;
u32 ce_errors;
u32 misc_errors;
int branch;
int channel;
int bank;
int rank;
int rdwr;
int ras, cas;
allErrors = (info->ferr_nf_fbd & FERR_NF_MASK);
if (!allErrors)
return;
ue_errors = allErrors & FERR_NF_UNCORRECTABLE;
if (ue_errors) {
edac_dbg(0, "\tUncorrected bits= 0x%x\n", ue_errors);
branch = EXTRACT_FBDCHAN_INDX(info->ferr_nf_fbd);
channel = branch & 2;
bank = NREC_BANK(info->nrecmema);
rank = NREC_RANK(info->nrecmema);
rdwr = NREC_RDWR(info->nrecmema);
ras = NREC_RAS(info->nrecmemb);
cas = NREC_CAS(info->nrecmemb);
edac_dbg(0, "\t\tCSROW= %d Channels= %d,%d (Branch= %d DRAM Bank= %d rdwr= %s ras= %d cas= %d)\n",
rank, channel, channel + 1, branch >> 1, bank,
rdwr ? "Write" : "Read", ras, cas);
switch (ue_errors) {
case FERR_NF_M12ERR:
specific = "Non-Aliased Uncorrectable Patrol Data ECC";
break;
case FERR_NF_M11ERR:
specific = "Non-Aliased Uncorrectable Spare-Copy "
"Data ECC";
break;
case FERR_NF_M10ERR:
specific = "Non-Aliased Uncorrectable Mirrored Demand "
"Data ECC";
break;
case FERR_NF_M9ERR:
specific = "Non-Aliased Uncorrectable Non-Mirrored "
"Demand Data ECC";
break;
case FERR_NF_M8ERR:
specific = "Aliased Uncorrectable Patrol Data ECC";
break;
case FERR_NF_M7ERR:
specific = "Aliased Uncorrectable Spare-Copy Data ECC";
break;
case FERR_NF_M6ERR:
specific = "Aliased Uncorrectable Mirrored Demand "
"Data ECC";
break;
case FERR_NF_M5ERR:
specific = "Aliased Uncorrectable Non-Mirrored Demand "
"Data ECC";
break;
case FERR_NF_M4ERR:
specific = "Uncorrectable Data ECC on Replay";
break;
}
snprintf(msg, sizeof(msg),
"Rank=%d Bank=%d RAS=%d CAS=%d, UE Err=0x%x (%s)",
rank, bank, ras, cas, ue_errors, specific);
edac_mc_handle_error(HW_EVENT_ERR_UNCORRECTED, mci, 1, 0, 0, 0,
channel >> 1, -1, rank,
rdwr ? "Write error" : "Read error",
msg);
}
ce_errors = allErrors & FERR_NF_CORRECTABLE;
if (ce_errors) {
edac_dbg(0, "\tCorrected bits= 0x%x\n", ce_errors);
branch = EXTRACT_FBDCHAN_INDX(info->ferr_nf_fbd);
channel = 0;
if (REC_ECC_LOCATOR_ODD(info->redmemb))
channel = 1;
channel += branch;
bank = REC_BANK(info->recmema);
rank = REC_RANK(info->recmema);
rdwr = REC_RDWR(info->recmema);
ras = REC_RAS(info->recmemb);
cas = REC_CAS(info->recmemb);
edac_dbg(0, "\t\tCSROW= %d Channel= %d (Branch %d DRAM Bank= %d rdwr= %s ras= %d cas= %d)\n",
rank, channel, branch >> 1, bank,
rdwr ? "Write" : "Read", ras, cas);
switch (ce_errors) {
case FERR_NF_M17ERR:
specific = "Correctable Non-Mirrored Demand Data ECC";
break;
case FERR_NF_M18ERR:
specific = "Correctable Mirrored Demand Data ECC";
break;
case FERR_NF_M19ERR:
specific = "Correctable Spare-Copy Data ECC";
break;
case FERR_NF_M20ERR:
specific = "Correctable Patrol Data ECC";
break;
}
snprintf(msg, sizeof(msg),
"Rank=%d Bank=%d RDWR=%s RAS=%d "
"CAS=%d, CE Err=0x%x (%s))", branch >> 1, bank,
rdwr ? "Write" : "Read", ras, cas, ce_errors,
specific);
edac_mc_handle_error(HW_EVENT_ERR_CORRECTED, mci, 1, 0, 0, 0,
channel >> 1, channel % 2, rank,
rdwr ? "Write error" : "Read error",
msg);
}
if (!misc_messages)
return;
misc_errors = allErrors & (FERR_NF_NON_RETRY | FERR_NF_NORTH_CRC |
FERR_NF_SPD_PROTOCOL | FERR_NF_DIMM_SPARE);
if (misc_errors) {
switch (misc_errors) {
case FERR_NF_M13ERR:
specific = "Non-Retry or Redundant Retry FBD Memory "
"Alert or Redundant Fast Reset Timeout";
break;
case FERR_NF_M14ERR:
specific = "Non-Retry or Redundant Retry FBD "
"Configuration Alert";
break;
case FERR_NF_M15ERR:
specific = "Non-Retry or Redundant Retry FBD "
"Northbound CRC error on read data";
break;
case FERR_NF_M21ERR:
specific = "FBD Northbound CRC error on "
"FBD Sync Status";
break;
case FERR_NF_M22ERR:
specific = "SPD protocol error";
break;
case FERR_NF_M27ERR:
specific = "DIMM-spare copy started";
break;
case FERR_NF_M28ERR:
specific = "DIMM-spare copy completed";
break;
}
branch = EXTRACT_FBDCHAN_INDX(info->ferr_nf_fbd);
snprintf(msg, sizeof(msg),
"Err=%#x (%s)", misc_errors, specific);
edac_mc_handle_error(HW_EVENT_ERR_CORRECTED, mci, 1, 0, 0, 0,
branch >> 1, -1, -1,
"Misc error", msg);
}
}
static void i5000_process_error_info(struct mem_ctl_info *mci,
struct i5000_error_info *info,
int handle_errors)
{
i5000_process_fatal_error_info(mci, info, handle_errors);
i5000_process_nonfatal_error_info(mci, info, handle_errors);
}
static void i5000_clear_error(struct mem_ctl_info *mci)
{
struct i5000_error_info info;
i5000_get_error_info(mci, &info);
}
static void i5000_check_error(struct mem_ctl_info *mci)
{
struct i5000_error_info info;
edac_dbg(4, "MC%d\n", mci->mc_idx);
i5000_get_error_info(mci, &info);
i5000_process_error_info(mci, &info, 1);
}
static int i5000_get_devices(struct mem_ctl_info *mci, int dev_idx)
{
struct i5000_pvt *pvt;
struct pci_dev *pdev;
pvt = mci->pvt_info;
pdev = NULL;
while (1) {
pdev = pci_get_device(PCI_VENDOR_ID_INTEL,
PCI_DEVICE_ID_INTEL_I5000_DEV16, pdev);
if (pdev == NULL) {
i5000_printk(KERN_ERR,
"'system address,Process Bus' "
"device not found:"
"vendor 0x%x device 0x%x FUNC 1 "
"(broken BIOS?)\n",
PCI_VENDOR_ID_INTEL,
PCI_DEVICE_ID_INTEL_I5000_DEV16);
return 1;
}
if (PCI_FUNC(pdev->devfn) == 1)
break;
}
pvt->branchmap_werrors = pdev;
pdev = NULL;
while (1) {
pdev = pci_get_device(PCI_VENDOR_ID_INTEL,
PCI_DEVICE_ID_INTEL_I5000_DEV16, pdev);
if (pdev == NULL) {
i5000_printk(KERN_ERR,
"MC: 'branchmap,control,errors' "
"device not found:"
"vendor 0x%x device 0x%x Func 2 "
"(broken BIOS?)\n",
PCI_VENDOR_ID_INTEL,
PCI_DEVICE_ID_INTEL_I5000_DEV16);
pci_dev_put(pvt->branchmap_werrors);
return 1;
}
if (PCI_FUNC(pdev->devfn) == 2)
break;
}
pvt->fsb_error_regs = pdev;
edac_dbg(1, "System Address, processor bus- PCI Bus ID: %s %x:%x\n",
pci_name(pvt->system_address),
pvt->system_address->vendor, pvt->system_address->device);
edac_dbg(1, "Branchmap, control and errors - PCI Bus ID: %s %x:%x\n",
pci_name(pvt->branchmap_werrors),
pvt->branchmap_werrors->vendor,
pvt->branchmap_werrors->device);
edac_dbg(1, "FSB Error Regs - PCI Bus ID: %s %x:%x\n",
pci_name(pvt->fsb_error_regs),
pvt->fsb_error_regs->vendor, pvt->fsb_error_regs->device);
pdev = NULL;
pdev = pci_get_device(PCI_VENDOR_ID_INTEL,
PCI_DEVICE_ID_I5000_BRANCH_0, pdev);
if (pdev == NULL) {
i5000_printk(KERN_ERR,
"MC: 'BRANCH 0' device not found:"
"vendor 0x%x device 0x%x Func 0 (broken BIOS?)\n",
PCI_VENDOR_ID_INTEL, PCI_DEVICE_ID_I5000_BRANCH_0);
pci_dev_put(pvt->branchmap_werrors);
pci_dev_put(pvt->fsb_error_regs);
return 1;
}
pvt->branch_0 = pdev;
if (pvt->maxch >= CHANNELS_PER_BRANCH) {
pdev = NULL;
pdev = pci_get_device(PCI_VENDOR_ID_INTEL,
PCI_DEVICE_ID_I5000_BRANCH_1, pdev);
if (pdev == NULL) {
i5000_printk(KERN_ERR,
"MC: 'BRANCH 1' device not found:"
"vendor 0x%x device 0x%x Func 0 "
"(broken BIOS?)\n",
PCI_VENDOR_ID_INTEL,
PCI_DEVICE_ID_I5000_BRANCH_1);
pci_dev_put(pvt->branchmap_werrors);
pci_dev_put(pvt->fsb_error_regs);
pci_dev_put(pvt->branch_0);
return 1;
}
pvt->branch_1 = pdev;
}
return 0;
}
static void i5000_put_devices(struct mem_ctl_info *mci)
{
struct i5000_pvt *pvt;
pvt = mci->pvt_info;
pci_dev_put(pvt->branchmap_werrors);
pci_dev_put(pvt->fsb_error_regs);
pci_dev_put(pvt->branch_0);
if (pvt->maxch >= CHANNELS_PER_BRANCH)
pci_dev_put(pvt->branch_1);
}
static int determine_amb_present_reg(struct i5000_pvt *pvt, int channel)
{
int amb_present;
if (channel < CHANNELS_PER_BRANCH) {
if (channel & 0x1)
amb_present = pvt->b0_ambpresent1;
else
amb_present = pvt->b0_ambpresent0;
} else {
if (channel & 0x1)
amb_present = pvt->b1_ambpresent1;
else
amb_present = pvt->b1_ambpresent0;
}
return amb_present;
}
static int determine_mtr(struct i5000_pvt *pvt, int slot, int channel)
{
int mtr;
if (channel < CHANNELS_PER_BRANCH)
mtr = pvt->b0_mtr[slot];
else
mtr = pvt->b1_mtr[slot];
return mtr;
}
static void decode_mtr(int slot_row, u16 mtr)
{
int ans;
ans = MTR_DIMMS_PRESENT(mtr);
edac_dbg(2, "\tMTR%d=0x%x: DIMMs are %sPresent\n",
slot_row, mtr, ans ? "" : "NOT ");
if (!ans)
return;
edac_dbg(2, "\t\tWIDTH: x%d\n", MTR_DRAM_WIDTH(mtr));
edac_dbg(2, "\t\tNUMBANK: %d bank(s)\n", MTR_DRAM_BANKS(mtr));
edac_dbg(2, "\t\tNUMRANK: %s\n",
MTR_DIMM_RANK(mtr) ? "double" : "single");
edac_dbg(2, "\t\tNUMROW: %s\n",
MTR_DIMM_ROWS(mtr) == 0 ? "8,192 - 13 rows" :
MTR_DIMM_ROWS(mtr) == 1 ? "16,384 - 14 rows" :
MTR_DIMM_ROWS(mtr) == 2 ? "32,768 - 15 rows" :
"reserved");
edac_dbg(2, "\t\tNUMCOL: %s\n",
MTR_DIMM_COLS(mtr) == 0 ? "1,024 - 10 columns" :
MTR_DIMM_COLS(mtr) == 1 ? "2,048 - 11 columns" :
MTR_DIMM_COLS(mtr) == 2 ? "4,096 - 12 columns" :
"reserved");
}
static void handle_channel(struct i5000_pvt *pvt, int slot, int channel,
struct i5000_dimm_info *dinfo)
{
int mtr;
int amb_present_reg;
int addrBits;
mtr = determine_mtr(pvt, slot, channel);
if (MTR_DIMMS_PRESENT(mtr)) {
amb_present_reg = determine_amb_present_reg(pvt, channel);
if (amb_present_reg) {
dinfo->dual_rank = MTR_DIMM_RANK(mtr);
addrBits = MTR_DRAM_BANKS_ADDR_BITS(mtr);
addrBits += MTR_DIMM_ROWS_ADDR_BITS(mtr);
addrBits += MTR_DIMM_COLS_ADDR_BITS(mtr);
if (dinfo->dual_rank)
addrBits++;
addrBits += 6;
addrBits -= 20;
addrBits -= 3;
dinfo->megabytes = 1 << addrBits;
}
}
}
static void calculate_dimm_size(struct i5000_pvt *pvt)
{
struct i5000_dimm_info *dinfo;
int slot, channel, branch;
char *p, *mem_buffer;
int space, n;
space = PAGE_SIZE;
mem_buffer = p = kmalloc(space, GFP_KERNEL);
if (p == NULL) {
i5000_printk(KERN_ERR, "MC: %s:%s() kmalloc() failed\n",
__FILE__, __func__);
return;
}
for (slot = pvt->maxdimmperch - 1; slot >= 0; slot--) {
if (slot & 0x1) {
n = snprintf(p, space, "--------------------------"
"--------------------------------");
p += n;
space -= n;
edac_dbg(2, "%s\n", mem_buffer);
p = mem_buffer;
space = PAGE_SIZE;
}
n = snprintf(p, space, "slot %2d ", slot);
p += n;
space -= n;
for (channel = 0; channel < pvt->maxch; channel++) {
dinfo = &pvt->dimm_info[slot][channel];
handle_channel(pvt, slot, channel, dinfo);
if (dinfo->megabytes)
n = snprintf(p, space, "%4d MB %dR| ",
dinfo->megabytes, dinfo->dual_rank + 1);
else
n = snprintf(p, space, "%4d MB | ", 0);
p += n;
space -= n;
}
p += n;
space -= n;
edac_dbg(2, "%s\n", mem_buffer);
p = mem_buffer;
space = PAGE_SIZE;
}
n = snprintf(p, space, "--------------------------"
"--------------------------------");
p += n;
space -= n;
edac_dbg(2, "%s\n", mem_buffer);
p = mem_buffer;
space = PAGE_SIZE;
n = snprintf(p, space, " ");
p += n;
space -= n;
for (channel = 0; channel < pvt->maxch; channel++) {
n = snprintf(p, space, "channel %d | ", channel);
p += n;
space -= n;
}
edac_dbg(2, "%s\n", mem_buffer);
p = mem_buffer;
space = PAGE_SIZE;
n = snprintf(p, space, " ");
p += n;
for (branch = 0; branch < MAX_BRANCHES; branch++) {
n = snprintf(p, space, " branch %d | ", branch);
p += n;
space -= n;
}
edac_dbg(2, "%s\n", mem_buffer);
kfree(mem_buffer);
}
static void i5000_get_mc_regs(struct mem_ctl_info *mci)
{
struct i5000_pvt *pvt;
u32 actual_tolm;
u16 limit;
int slot_row;
int maxch;
int maxdimmperch;
int way0, way1;
pvt = mci->pvt_info;
pci_read_config_dword(pvt->system_address, AMBASE,
&pvt->u.ambase_bottom);
pci_read_config_dword(pvt->system_address, AMBASE + sizeof(u32),
&pvt->u.ambase_top);
maxdimmperch = pvt->maxdimmperch;
maxch = pvt->maxch;
edac_dbg(2, "AMBASE= 0x%lx MAXCH= %d MAX-DIMM-Per-CH= %d\n",
(long unsigned int)pvt->ambase, pvt->maxch, pvt->maxdimmperch);
pci_read_config_word(pvt->branchmap_werrors, TOLM, &pvt->tolm);
pvt->tolm >>= 12;
edac_dbg(2, "TOLM (number of 256M regions) =%u (0x%x)\n",
pvt->tolm, pvt->tolm);
actual_tolm = pvt->tolm << 28;
edac_dbg(2, "Actual TOLM byte addr=%u (0x%x)\n",
actual_tolm, actual_tolm);
pci_read_config_word(pvt->branchmap_werrors, MIR0, &pvt->mir0);
pci_read_config_word(pvt->branchmap_werrors, MIR1, &pvt->mir1);
pci_read_config_word(pvt->branchmap_werrors, MIR2, &pvt->mir2);
limit = (pvt->mir0 >> 4) & 0x0FFF;
way0 = pvt->mir0 & 0x1;
way1 = pvt->mir0 & 0x2;
edac_dbg(2, "MIR0: limit= 0x%x WAY1= %u WAY0= %x\n",
limit, way1, way0);
limit = (pvt->mir1 >> 4) & 0x0FFF;
way0 = pvt->mir1 & 0x1;
way1 = pvt->mir1 & 0x2;
edac_dbg(2, "MIR1: limit= 0x%x WAY1= %u WAY0= %x\n",
limit, way1, way0);
limit = (pvt->mir2 >> 4) & 0x0FFF;
way0 = pvt->mir2 & 0x1;
way1 = pvt->mir2 & 0x2;
edac_dbg(2, "MIR2: limit= 0x%x WAY1= %u WAY0= %x\n",
limit, way1, way0);
for (slot_row = 0; slot_row < NUM_MTRS; slot_row++) {
int where = MTR0 + (slot_row * sizeof(u32));
pci_read_config_word(pvt->branch_0, where,
&pvt->b0_mtr[slot_row]);
edac_dbg(2, "MTR%d where=0x%x B0 value=0x%x\n",
slot_row, where, pvt->b0_mtr[slot_row]);
if (pvt->maxch >= CHANNELS_PER_BRANCH) {
pci_read_config_word(pvt->branch_1, where,
&pvt->b1_mtr[slot_row]);
edac_dbg(2, "MTR%d where=0x%x B1 value=0x%x\n",
slot_row, where, pvt->b1_mtr[slot_row]);
} else {
pvt->b1_mtr[slot_row] = 0;
}
}
edac_dbg(2, "Memory Technology Registers:\n");
edac_dbg(2, " Branch 0:\n");
for (slot_row = 0; slot_row < NUM_MTRS; slot_row++) {
decode_mtr(slot_row, pvt->b0_mtr[slot_row]);
}
pci_read_config_word(pvt->branch_0, AMB_PRESENT_0,
&pvt->b0_ambpresent0);
edac_dbg(2, "\t\tAMB-Branch 0-present0 0x%x:\n", pvt->b0_ambpresent0);
pci_read_config_word(pvt->branch_0, AMB_PRESENT_1,
&pvt->b0_ambpresent1);
edac_dbg(2, "\t\tAMB-Branch 0-present1 0x%x:\n", pvt->b0_ambpresent1);
if (pvt->maxch < CHANNELS_PER_BRANCH) {
pvt->b1_ambpresent0 = 0;
pvt->b1_ambpresent1 = 0;
} else {
edac_dbg(2, " Branch 1:\n");
for (slot_row = 0; slot_row < NUM_MTRS; slot_row++) {
decode_mtr(slot_row, pvt->b1_mtr[slot_row]);
}
pci_read_config_word(pvt->branch_1, AMB_PRESENT_0,
&pvt->b1_ambpresent0);
edac_dbg(2, "\t\tAMB-Branch 1-present0 0x%x:\n",
pvt->b1_ambpresent0);
pci_read_config_word(pvt->branch_1, AMB_PRESENT_1,
&pvt->b1_ambpresent1);
edac_dbg(2, "\t\tAMB-Branch 1-present1 0x%x:\n",
pvt->b1_ambpresent1);
}
calculate_dimm_size(pvt);
}
static int i5000_init_csrows(struct mem_ctl_info *mci)
{
struct i5000_pvt *pvt;
struct dimm_info *dimm;
int empty, channel_count;
int max_csrows;
int mtr;
int csrow_megs;
int channel;
int slot;
pvt = mci->pvt_info;
channel_count = pvt->maxch;
max_csrows = pvt->maxdimmperch * 2;
empty = 1;
for (slot = 0; slot < max_csrows; slot++) {
for (channel = 0; channel < pvt->maxch; channel++) {
mtr = determine_mtr(pvt, slot, channel);
if (!MTR_DIMMS_PRESENT(mtr))
continue;
dimm = EDAC_DIMM_PTR(mci->layers, mci->dimms, mci->n_layers,
channel / MAX_BRANCHES,
channel % MAX_BRANCHES, slot);
csrow_megs = pvt->dimm_info[slot][channel].megabytes;
dimm->grain = 8;
dimm->mtype = MEM_FB_DDR2;
if (MTR_DRAM_WIDTH(mtr))
dimm->dtype = DEV_X8;
else
dimm->dtype = DEV_X4;
dimm->edac_mode = EDAC_S8ECD8ED;
dimm->nr_pages = csrow_megs << 8;
}
empty = 0;
}
return empty;
}
static void i5000_enable_error_reporting(struct mem_ctl_info *mci)
{
struct i5000_pvt *pvt;
u32 fbd_error_mask;
pvt = mci->pvt_info;
pci_read_config_dword(pvt->branchmap_werrors, EMASK_FBD,
&fbd_error_mask);
fbd_error_mask &= ~(ENABLE_EMASK_ALL);
pci_write_config_dword(pvt->branchmap_werrors, EMASK_FBD,
fbd_error_mask);
}
static void i5000_get_dimm_and_channel_counts(struct pci_dev *pdev,
int *num_dimms_per_channel,
int *num_channels)
{
u8 value;
pci_read_config_byte(pdev, MAXDIMMPERCH, &value);
*num_dimms_per_channel = (int)value;
pci_read_config_byte(pdev, MAXCH, &value);
*num_channels = (int)value;
}
static int i5000_probe1(struct pci_dev *pdev, int dev_idx)
{
struct mem_ctl_info *mci;
struct edac_mc_layer layers[3];
struct i5000_pvt *pvt;
int num_channels;
int num_dimms_per_channel;
edac_dbg(0, "MC: pdev bus %u dev=0x%x fn=0x%x\n",
pdev->bus->number,
PCI_SLOT(pdev->devfn), PCI_FUNC(pdev->devfn));
if (PCI_FUNC(pdev->devfn) != 0)
return -ENODEV;
i5000_get_dimm_and_channel_counts(pdev, &num_dimms_per_channel,
&num_channels);
edac_dbg(0, "MC: Number of Branches=2 Channels= %d DIMMS= %d\n",
num_channels, num_dimms_per_channel);
layers[0].type = EDAC_MC_LAYER_BRANCH;
layers[0].size = MAX_BRANCHES;
layers[0].is_virt_csrow = false;
layers[1].type = EDAC_MC_LAYER_CHANNEL;
layers[1].size = num_channels / MAX_BRANCHES;
layers[1].is_virt_csrow = false;
layers[2].type = EDAC_MC_LAYER_SLOT;
layers[2].size = num_dimms_per_channel;
layers[2].is_virt_csrow = true;
mci = edac_mc_alloc(0, ARRAY_SIZE(layers), layers, sizeof(*pvt));
if (mci == NULL)
return -ENOMEM;
edac_dbg(0, "MC: mci = %p\n", mci);
mci->pdev = &pdev->dev;
pvt = mci->pvt_info;
pvt->system_address = pdev;
pvt->maxch = num_channels;
pvt->maxdimmperch = num_dimms_per_channel;
if (i5000_get_devices(mci, dev_idx))
goto fail0;
i5000_get_mc_regs(mci);
mci->mc_idx = 0;
mci->mtype_cap = MEM_FLAG_FB_DDR2;
mci->edac_ctl_cap = EDAC_FLAG_NONE;
mci->edac_cap = EDAC_FLAG_NONE;
mci->mod_name = "i5000_edac.c";
mci->mod_ver = I5000_REVISION;
mci->ctl_name = i5000_devs[dev_idx].ctl_name;
mci->dev_name = pci_name(pdev);
mci->ctl_page_to_phys = NULL;
mci->edac_check = i5000_check_error;
if (i5000_init_csrows(mci)) {
edac_dbg(0, "MC: Setting mci->edac_cap to EDAC_FLAG_NONE because i5000_init_csrows() returned nonzero value\n");
mci->edac_cap = EDAC_FLAG_NONE;
} else {
edac_dbg(1, "MC: Enable error reporting now\n");
i5000_enable_error_reporting(mci);
}
if (edac_mc_add_mc(mci)) {
edac_dbg(0, "MC: failed edac_mc_add_mc()\n");
goto fail1;
}
i5000_clear_error(mci);
i5000_pci = edac_pci_create_generic_ctl(&pdev->dev, EDAC_MOD_STR);
if (!i5000_pci) {
printk(KERN_WARNING
"%s(): Unable to create PCI control\n",
__func__);
printk(KERN_WARNING
"%s(): PCI error report via EDAC not setup\n",
__func__);
}
return 0;
fail1:
i5000_put_devices(mci);
fail0:
edac_mc_free(mci);
return -ENODEV;
}
static int i5000_init_one(struct pci_dev *pdev, const struct pci_device_id *id)
{
int rc;
edac_dbg(0, "MC:\n");
rc = pci_enable_device(pdev);
if (rc)
return rc;
return i5000_probe1(pdev, id->driver_data);
}
static void i5000_remove_one(struct pci_dev *pdev)
{
struct mem_ctl_info *mci;
edac_dbg(0, "\n");
if (i5000_pci)
edac_pci_release_generic_ctl(i5000_pci);
if ((mci = edac_mc_del_mc(&pdev->dev)) == NULL)
return;
i5000_put_devices(mci);
edac_mc_free(mci);
}
static int __init i5000_init(void)
{
int pci_rc;
edac_dbg(2, "MC:\n");
opstate_init();
pci_rc = pci_register_driver(&i5000_driver);
return (pci_rc < 0) ? pci_rc : 0;
}
static void __exit i5000_exit(void)
{
edac_dbg(2, "MC:\n");
pci_unregister_driver(&i5000_driver);
}
