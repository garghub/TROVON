static unsigned long ctl_page_to_phys(struct mem_ctl_info *mci,
unsigned long page)
{
u32 remap;
struct e752x_pvt *pvt = (struct e752x_pvt *)mci->pvt_info;
debugf3("%s()\n", __func__);
if (page < pvt->tolm)
return page;
if ((page >= 0x100000) && (page < pvt->remapbase))
return page;
remap = (page - pvt->tolm) + pvt->remapbase;
if (remap < pvt->remaplimit)
return remap;
e752x_printk(KERN_ERR, "Invalid page %lx - out of range\n", page);
return pvt->tolm - 1;
}
static void do_process_ce(struct mem_ctl_info *mci, u16 error_one,
u32 sec1_add, u16 sec1_syndrome)
{
u32 page;
int row;
int channel;
int i;
struct e752x_pvt *pvt = (struct e752x_pvt *)mci->pvt_info;
debugf3("%s()\n", __func__);
page = sec1_add >> (PAGE_SHIFT - 4);
if (pvt->mc_symmetric) {
row = ((page >> 1) & 3);
e752x_printk(KERN_WARNING,
"Test row %d Table %d %d %d %d %d %d %d %d\n", row,
pvt->map[0], pvt->map[1], pvt->map[2], pvt->map[3],
pvt->map[4], pvt->map[5], pvt->map[6],
pvt->map[7]);
for (i = 0; i < 8; i++) {
if (pvt->map[i] == row)
break;
}
e752x_printk(KERN_WARNING, "Test computed row %d\n", i);
if (i < 8)
row = i;
else
e752x_mc_printk(mci, KERN_WARNING,
"row %d not found in remap table\n",
row);
} else
row = edac_mc_find_csrow_by_page(mci, page);
channel = !(error_one & 1);
edac_mc_handle_error(HW_EVENT_ERR_CORRECTED, mci,
page, offset_in_page(sec1_add << 4), sec1_syndrome,
row, channel, -1,
"e752x CE", "", NULL);
}
static inline void process_ce(struct mem_ctl_info *mci, u16 error_one,
u32 sec1_add, u16 sec1_syndrome, int *error_found,
int handle_error)
{
*error_found = 1;
if (handle_error)
do_process_ce(mci, error_one, sec1_add, sec1_syndrome);
}
static void do_process_ue(struct mem_ctl_info *mci, u16 error_one,
u32 ded_add, u32 scrb_add)
{
u32 error_2b, block_page;
int row;
struct e752x_pvt *pvt = (struct e752x_pvt *)mci->pvt_info;
debugf3("%s()\n", __func__);
if (error_one & 0x0202) {
error_2b = ded_add;
block_page = error_2b >> (PAGE_SHIFT - 4);
row = pvt->mc_symmetric ?
((block_page >> 1) & 3) :
edac_mc_find_csrow_by_page(mci, block_page);
edac_mc_handle_error(HW_EVENT_ERR_UNCORRECTED, mci,
block_page,
offset_in_page(error_2b << 4), 0,
row, -1, -1,
"e752x UE from Read", "", NULL);
}
if (error_one & 0x0404) {
error_2b = scrb_add;
block_page = error_2b >> (PAGE_SHIFT - 4);
row = pvt->mc_symmetric ?
((block_page >> 1) & 3) :
edac_mc_find_csrow_by_page(mci, block_page);
edac_mc_handle_error(HW_EVENT_ERR_UNCORRECTED, mci,
block_page,
offset_in_page(error_2b << 4), 0,
row, -1, -1,
"e752x UE from Scruber", "", NULL);
}
}
static inline void process_ue(struct mem_ctl_info *mci, u16 error_one,
u32 ded_add, u32 scrb_add, int *error_found,
int handle_error)
{
*error_found = 1;
if (handle_error)
do_process_ue(mci, error_one, ded_add, scrb_add);
}
static inline void process_ue_no_info_wr(struct mem_ctl_info *mci,
int *error_found, int handle_error)
{
*error_found = 1;
if (!handle_error)
return;
debugf3("%s()\n", __func__);
edac_mc_handle_error(HW_EVENT_ERR_UNCORRECTED, mci, 0, 0, 0,
-1, -1, -1,
"e752x UE log memory write", "", NULL);
}
static void do_process_ded_retry(struct mem_ctl_info *mci, u16 error,
u32 retry_add)
{
u32 error_1b, page;
int row;
struct e752x_pvt *pvt = (struct e752x_pvt *)mci->pvt_info;
error_1b = retry_add;
page = error_1b >> (PAGE_SHIFT - 4);
row = pvt->mc_symmetric ? ((page >> 1) & 3) :
edac_mc_find_csrow_by_page(mci, page);
e752x_mc_printk(mci, KERN_WARNING,
"CE page 0x%lx, row %d : Memory read retry\n",
(long unsigned int)page, row);
}
static inline void process_ded_retry(struct mem_ctl_info *mci, u16 error,
u32 retry_add, int *error_found,
int handle_error)
{
*error_found = 1;
if (handle_error)
do_process_ded_retry(mci, error, retry_add);
}
static inline void process_threshold_ce(struct mem_ctl_info *mci, u16 error,
int *error_found, int handle_error)
{
*error_found = 1;
if (handle_error)
e752x_mc_printk(mci, KERN_WARNING, "Memory threshold CE\n");
}
static void do_global_error(int fatal, u32 errors)
{
int i;
for (i = 0; i < 11; i++) {
if (errors & (1 << i)) {
if ((i == DRAM_ENTRY) || report_non_memory_errors)
e752x_printk(KERN_WARNING, "%sError %s\n",
fatal_message[fatal],
global_message[i]);
}
}
}
static inline void global_error(int fatal, u32 errors, int *error_found,
int handle_error)
{
*error_found = 1;
if (handle_error)
do_global_error(fatal, errors);
}
static void do_hub_error(int fatal, u8 errors)
{
int i;
for (i = 0; i < 7; i++) {
if (errors & (1 << i))
e752x_printk(KERN_WARNING, "%sError %s\n",
fatal_message[fatal], hub_message[i]);
}
}
static inline void hub_error(int fatal, u8 errors, int *error_found,
int handle_error)
{
*error_found = 1;
if (handle_error)
do_hub_error(fatal, errors);
}
static void do_nsi_error(int fatal, u32 errors)
{
int i;
for (i = 0; i < 30; i++) {
if (errors & (1 << i))
printk(KERN_WARNING "%sError %s\n",
fatal_message[fatal], nsi_message[i]);
}
}
static inline void nsi_error(int fatal, u32 errors, int *error_found,
int handle_error)
{
*error_found = 1;
if (handle_error)
do_nsi_error(fatal, errors);
}
static void do_membuf_error(u8 errors)
{
int i;
for (i = 0; i < 4; i++) {
if (errors & (1 << i))
e752x_printk(KERN_WARNING, "Non-Fatal Error %s\n",
membuf_message[i]);
}
}
static inline void membuf_error(u8 errors, int *error_found, int handle_error)
{
*error_found = 1;
if (handle_error)
do_membuf_error(errors);
}
static void do_sysbus_error(int fatal, u32 errors)
{
int i;
for (i = 0; i < 10; i++) {
if (errors & (1 << i))
e752x_printk(KERN_WARNING, "%sError System Bus %s\n",
fatal_message[fatal], sysbus_message[i]);
}
}
static inline void sysbus_error(int fatal, u32 errors, int *error_found,
int handle_error)
{
*error_found = 1;
if (handle_error)
do_sysbus_error(fatal, errors);
}
static void e752x_check_hub_interface(struct e752x_error_info *info,
int *error_found, int handle_error)
{
u8 stat8;
stat8 = info->hi_ferr;
if (stat8 & 0x7f) {
stat8 &= 0x7f;
if (stat8 & 0x2b)
hub_error(1, stat8 & 0x2b, error_found, handle_error);
if (stat8 & 0x54)
hub_error(0, stat8 & 0x54, error_found, handle_error);
}
stat8 = info->hi_nerr;
if (stat8 & 0x7f) {
stat8 &= 0x7f;
if (stat8 & 0x2b)
hub_error(1, stat8 & 0x2b, error_found, handle_error);
if (stat8 & 0x54)
hub_error(0, stat8 & 0x54, error_found, handle_error);
}
}
static void e752x_check_ns_interface(struct e752x_error_info *info,
int *error_found, int handle_error)
{
u32 stat32;
stat32 = info->nsi_ferr;
if (stat32 & NSI_ERR_MASK) {
if (stat32 & NSI_FATAL_MASK)
nsi_error(1, stat32 & NSI_FATAL_MASK, error_found,
handle_error);
if (stat32 & NSI_NON_FATAL_MASK)
nsi_error(0, stat32 & NSI_NON_FATAL_MASK, error_found,
handle_error);
}
stat32 = info->nsi_nerr;
if (stat32 & NSI_ERR_MASK) {
if (stat32 & NSI_FATAL_MASK)
nsi_error(1, stat32 & NSI_FATAL_MASK, error_found,
handle_error);
if (stat32 & NSI_NON_FATAL_MASK)
nsi_error(0, stat32 & NSI_NON_FATAL_MASK, error_found,
handle_error);
}
}
static void e752x_check_sysbus(struct e752x_error_info *info,
int *error_found, int handle_error)
{
u32 stat32, error32;
stat32 = info->sysbus_ferr + (info->sysbus_nerr << 16);
if (stat32 == 0)
return;
error32 = (stat32 >> 16) & 0x3ff;
stat32 = stat32 & 0x3ff;
if (stat32 & 0x087)
sysbus_error(1, stat32 & 0x087, error_found, handle_error);
if (stat32 & 0x378)
sysbus_error(0, stat32 & 0x378, error_found, handle_error);
if (error32 & 0x087)
sysbus_error(1, error32 & 0x087, error_found, handle_error);
if (error32 & 0x378)
sysbus_error(0, error32 & 0x378, error_found, handle_error);
}
static void e752x_check_membuf(struct e752x_error_info *info,
int *error_found, int handle_error)
{
u8 stat8;
stat8 = info->buf_ferr;
if (stat8 & 0x0f) {
stat8 &= 0x0f;
membuf_error(stat8, error_found, handle_error);
}
stat8 = info->buf_nerr;
if (stat8 & 0x0f) {
stat8 &= 0x0f;
membuf_error(stat8, error_found, handle_error);
}
}
static void e752x_check_dram(struct mem_ctl_info *mci,
struct e752x_error_info *info, int *error_found,
int handle_error)
{
u16 error_one, error_next;
error_one = info->dram_ferr;
error_next = info->dram_nerr;
if (error_one & 0x0101)
process_ce(mci, error_one, info->dram_sec1_add,
info->dram_sec1_syndrome, error_found, handle_error);
if (error_next & 0x0101)
process_ce(mci, error_next, info->dram_sec2_add,
info->dram_sec2_syndrome, error_found, handle_error);
if (error_one & 0x4040)
process_ue_no_info_wr(mci, error_found, handle_error);
if (error_next & 0x4040)
process_ue_no_info_wr(mci, error_found, handle_error);
if (error_one & 0x2020)
process_ded_retry(mci, error_one, info->dram_retr_add,
error_found, handle_error);
if (error_next & 0x2020)
process_ded_retry(mci, error_next, info->dram_retr_add,
error_found, handle_error);
if (error_one & 0x0808)
process_threshold_ce(mci, error_one, error_found, handle_error);
if (error_next & 0x0808)
process_threshold_ce(mci, error_next, error_found,
handle_error);
if (error_one & 0x0606)
process_ue(mci, error_one, info->dram_ded_add,
info->dram_scrb_add, error_found, handle_error);
if (error_next & 0x0606)
process_ue(mci, error_next, info->dram_ded_add,
info->dram_scrb_add, error_found, handle_error);
}
static void e752x_get_error_info(struct mem_ctl_info *mci,
struct e752x_error_info *info)
{
struct pci_dev *dev;
struct e752x_pvt *pvt;
memset(info, 0, sizeof(*info));
pvt = (struct e752x_pvt *)mci->pvt_info;
dev = pvt->dev_d0f1;
pci_read_config_dword(dev, E752X_FERR_GLOBAL, &info->ferr_global);
if (info->ferr_global) {
if (pvt->dev_info->err_dev == PCI_DEVICE_ID_INTEL_3100_1_ERR) {
pci_read_config_dword(dev, I3100_NSI_FERR,
&info->nsi_ferr);
info->hi_ferr = 0;
} else {
pci_read_config_byte(dev, E752X_HI_FERR,
&info->hi_ferr);
info->nsi_ferr = 0;
}
pci_read_config_word(dev, E752X_SYSBUS_FERR,
&info->sysbus_ferr);
pci_read_config_byte(dev, E752X_BUF_FERR, &info->buf_ferr);
pci_read_config_word(dev, E752X_DRAM_FERR, &info->dram_ferr);
pci_read_config_dword(dev, E752X_DRAM_SEC1_ADD,
&info->dram_sec1_add);
pci_read_config_word(dev, E752X_DRAM_SEC1_SYNDROME,
&info->dram_sec1_syndrome);
pci_read_config_dword(dev, E752X_DRAM_DED_ADD,
&info->dram_ded_add);
pci_read_config_dword(dev, E752X_DRAM_SCRB_ADD,
&info->dram_scrb_add);
pci_read_config_dword(dev, E752X_DRAM_RETR_ADD,
&info->dram_retr_add);
if (info->hi_ferr & 0x7f)
pci_write_config_byte(dev, E752X_HI_FERR,
info->hi_ferr);
if (info->nsi_ferr & NSI_ERR_MASK)
pci_write_config_dword(dev, I3100_NSI_FERR,
info->nsi_ferr);
if (info->sysbus_ferr)
pci_write_config_word(dev, E752X_SYSBUS_FERR,
info->sysbus_ferr);
if (info->buf_ferr & 0x0f)
pci_write_config_byte(dev, E752X_BUF_FERR,
info->buf_ferr);
if (info->dram_ferr)
pci_write_bits16(pvt->bridge_ck, E752X_DRAM_FERR,
info->dram_ferr, info->dram_ferr);
pci_write_config_dword(dev, E752X_FERR_GLOBAL,
info->ferr_global);
}
pci_read_config_dword(dev, E752X_NERR_GLOBAL, &info->nerr_global);
if (info->nerr_global) {
if (pvt->dev_info->err_dev == PCI_DEVICE_ID_INTEL_3100_1_ERR) {
pci_read_config_dword(dev, I3100_NSI_NERR,
&info->nsi_nerr);
info->hi_nerr = 0;
} else {
pci_read_config_byte(dev, E752X_HI_NERR,
&info->hi_nerr);
info->nsi_nerr = 0;
}
pci_read_config_word(dev, E752X_SYSBUS_NERR,
&info->sysbus_nerr);
pci_read_config_byte(dev, E752X_BUF_NERR, &info->buf_nerr);
pci_read_config_word(dev, E752X_DRAM_NERR, &info->dram_nerr);
pci_read_config_dword(dev, E752X_DRAM_SEC2_ADD,
&info->dram_sec2_add);
pci_read_config_word(dev, E752X_DRAM_SEC2_SYNDROME,
&info->dram_sec2_syndrome);
if (info->hi_nerr & 0x7f)
pci_write_config_byte(dev, E752X_HI_NERR,
info->hi_nerr);
if (info->nsi_nerr & NSI_ERR_MASK)
pci_write_config_dword(dev, I3100_NSI_NERR,
info->nsi_nerr);
if (info->sysbus_nerr)
pci_write_config_word(dev, E752X_SYSBUS_NERR,
info->sysbus_nerr);
if (info->buf_nerr & 0x0f)
pci_write_config_byte(dev, E752X_BUF_NERR,
info->buf_nerr);
if (info->dram_nerr)
pci_write_bits16(pvt->bridge_ck, E752X_DRAM_NERR,
info->dram_nerr, info->dram_nerr);
pci_write_config_dword(dev, E752X_NERR_GLOBAL,
info->nerr_global);
}
}
static int e752x_process_error_info(struct mem_ctl_info *mci,
struct e752x_error_info *info,
int handle_errors)
{
u32 error32, stat32;
int error_found;
error_found = 0;
error32 = (info->ferr_global >> 18) & 0x3ff;
stat32 = (info->ferr_global >> 4) & 0x7ff;
if (error32)
global_error(1, error32, &error_found, handle_errors);
if (stat32)
global_error(0, stat32, &error_found, handle_errors);
error32 = (info->nerr_global >> 18) & 0x3ff;
stat32 = (info->nerr_global >> 4) & 0x7ff;
if (error32)
global_error(1, error32, &error_found, handle_errors);
if (stat32)
global_error(0, stat32, &error_found, handle_errors);
e752x_check_hub_interface(info, &error_found, handle_errors);
e752x_check_ns_interface(info, &error_found, handle_errors);
e752x_check_sysbus(info, &error_found, handle_errors);
e752x_check_membuf(info, &error_found, handle_errors);
e752x_check_dram(mci, info, &error_found, handle_errors);
return error_found;
}
static void e752x_check(struct mem_ctl_info *mci)
{
struct e752x_error_info info;
debugf3("%s()\n", __func__);
e752x_get_error_info(mci, &info);
e752x_process_error_info(mci, &info, 1);
}
static int set_sdram_scrub_rate(struct mem_ctl_info *mci, u32 new_bw)
{
const struct scrubrate *scrubrates;
struct e752x_pvt *pvt = (struct e752x_pvt *) mci->pvt_info;
struct pci_dev *pdev = pvt->dev_d0f0;
int i;
if (pvt->dev_info->ctl_dev == PCI_DEVICE_ID_INTEL_3100_0)
scrubrates = scrubrates_i3100;
else
scrubrates = scrubrates_e752x;
for (i = 0; scrubrates[i].bandwidth != SDRATE_EOT; i++)
if (scrubrates[i].bandwidth >= new_bw)
break;
if (scrubrates[i].bandwidth == SDRATE_EOT)
return -1;
pci_write_config_word(pdev, E752X_MCHSCRB, scrubrates[i].scrubval);
return scrubrates[i].bandwidth;
}
static int get_sdram_scrub_rate(struct mem_ctl_info *mci)
{
const struct scrubrate *scrubrates;
struct e752x_pvt *pvt = (struct e752x_pvt *) mci->pvt_info;
struct pci_dev *pdev = pvt->dev_d0f0;
u16 scrubval;
int i;
if (pvt->dev_info->ctl_dev == PCI_DEVICE_ID_INTEL_3100_0)
scrubrates = scrubrates_i3100;
else
scrubrates = scrubrates_e752x;
pci_read_config_word(pdev, E752X_MCHSCRB, &scrubval);
scrubval = scrubval & 0x0f;
for (i = 0; scrubrates[i].bandwidth != SDRATE_EOT; i++)
if (scrubrates[i].scrubval == scrubval)
break;
if (scrubrates[i].bandwidth == SDRATE_EOT) {
e752x_printk(KERN_WARNING,
"Invalid sdram scrub control value: 0x%x\n", scrubval);
return -1;
}
return scrubrates[i].bandwidth;
}
static inline int dual_channel_active(u16 ddrcsr)
{
return (((ddrcsr >> 12) & 3) == 3);
}
static inline int remap_csrow_index(struct mem_ctl_info *mci, int index)
{
struct e752x_pvt *pvt = mci->pvt_info;
if (!pvt->map_type)
return (7 - index);
return (index);
}
static void e752x_init_csrows(struct mem_ctl_info *mci, struct pci_dev *pdev,
u16 ddrcsr)
{
struct csrow_info *csrow;
unsigned long last_cumul_size;
int index, mem_dev, drc_chan;
int drc_drbg;
int drc_ddim;
u8 value;
u32 dra, drc, cumul_size, i, nr_pages;
dra = 0;
for (index = 0; index < 4; index++) {
u8 dra_reg;
pci_read_config_byte(pdev, E752X_DRA + index, &dra_reg);
dra |= dra_reg << (index * 8);
}
pci_read_config_dword(pdev, E752X_DRC, &drc);
drc_chan = dual_channel_active(ddrcsr) ? 1 : 0;
drc_drbg = drc_chan + 1;
drc_ddim = (drc >> 20) & 0x3;
for (last_cumul_size = index = 0; index < mci->nr_csrows; index++) {
mem_dev = (dra >> (index * 4 + 2)) & 0x3;
csrow = &mci->csrows[remap_csrow_index(mci, index)];
mem_dev = (mem_dev == 2);
pci_read_config_byte(pdev, E752X_DRB + index, &value);
cumul_size = value << (25 + drc_drbg - PAGE_SHIFT);
debugf3("%s(): (%d) cumul_size 0x%x\n", __func__, index,
cumul_size);
if (cumul_size == last_cumul_size)
continue;
csrow->first_page = last_cumul_size;
csrow->last_page = cumul_size - 1;
nr_pages = cumul_size - last_cumul_size;
last_cumul_size = cumul_size;
for (i = 0; i < csrow->nr_channels; i++) {
struct dimm_info *dimm = csrow->channels[i].dimm;
debugf3("Initializing rank at (%i,%i)\n", index, i);
dimm->nr_pages = nr_pages / csrow->nr_channels;
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
static void e752x_init_mem_map_table(struct pci_dev *pdev,
struct e752x_pvt *pvt)
{
int index;
u8 value, last, row;
last = 0;
row = 0;
for (index = 0; index < 8; index += 2) {
pci_read_config_byte(pdev, E752X_DRB + index, &value);
if (value == last) {
pvt->map[index] = 0xff;
pvt->map[index + 1] = 0xff;
} else {
pvt->map[index] = row;
row++;
last = value;
pci_read_config_byte(pdev, E752X_DRB + index + 1,
&value);
pvt->map[index + 1] = (value == last) ? 0xff : row;
row++;
last = value;
}
}
}
static int e752x_get_devs(struct pci_dev *pdev, int dev_idx,
struct e752x_pvt *pvt)
{
struct pci_dev *dev;
pvt->bridge_ck = pci_get_device(PCI_VENDOR_ID_INTEL,
pvt->dev_info->err_dev, pvt->bridge_ck);
if (pvt->bridge_ck == NULL)
pvt->bridge_ck = pci_scan_single_device(pdev->bus,
PCI_DEVFN(0, 1));
if (pvt->bridge_ck == NULL) {
e752x_printk(KERN_ERR, "error reporting device not found:"
"vendor %x device 0x%x (broken BIOS?)\n",
PCI_VENDOR_ID_INTEL, e752x_devs[dev_idx].err_dev);
return 1;
}
dev = pci_get_device(PCI_VENDOR_ID_INTEL,
e752x_devs[dev_idx].ctl_dev,
NULL);
if (dev == NULL)
goto fail;
pvt->dev_d0f0 = dev;
pvt->dev_d0f1 = pci_dev_get(pvt->bridge_ck);
return 0;
fail:
pci_dev_put(pvt->bridge_ck);
return 1;
}
static void e752x_init_sysbus_parity_mask(struct e752x_pvt *pvt)
{
char *cpu_id = cpu_data(0).x86_model_id;
struct pci_dev *dev = pvt->dev_d0f1;
int enable = 1;
if (sysbus_parity != -1) {
enable = sysbus_parity;
} else if (cpu_id[0] && !strstr(cpu_id, "Xeon")) {
e752x_printk(KERN_INFO, "System Bus Parity not "
"supported by CPU, disabling\n");
enable = 0;
}
if (enable)
pci_write_config_word(dev, E752X_SYSBUS_ERRMASK, 0x0000);
else
pci_write_config_word(dev, E752X_SYSBUS_ERRMASK, 0x0309);
}
static void e752x_init_error_reporting_regs(struct e752x_pvt *pvt)
{
struct pci_dev *dev;
dev = pvt->dev_d0f1;
if (pvt->dev_info->err_dev == PCI_DEVICE_ID_INTEL_3100_1_ERR) {
pci_write_config_dword(dev, I3100_NSI_EMASK, 0);
pci_write_config_dword(dev, I3100_NSI_SMICMD, 0);
} else {
pci_write_config_byte(dev, E752X_HI_ERRMASK, 0x00);
pci_write_config_byte(dev, E752X_HI_SMICMD, 0x00);
}
e752x_init_sysbus_parity_mask(pvt);
pci_write_config_word(dev, E752X_SYSBUS_SMICMD, 0x00);
pci_write_config_byte(dev, E752X_BUF_ERRMASK, 0x00);
pci_write_config_byte(dev, E752X_BUF_SMICMD, 0x00);
pci_write_config_byte(dev, E752X_DRAM_ERRMASK, 0x00);
pci_write_config_byte(dev, E752X_DRAM_SMICMD, 0x00);
}
static int e752x_probe1(struct pci_dev *pdev, int dev_idx)
{
u16 pci_data;
u8 stat8;
struct mem_ctl_info *mci;
struct edac_mc_layer layers[2];
struct e752x_pvt *pvt;
u16 ddrcsr;
int drc_chan;
struct e752x_error_info discard;
debugf0("%s(): mci\n", __func__);
debugf0("Starting Probe1\n");
pci_read_config_byte(pdev, E752X_DEVPRES1, &stat8);
if (!force_function_unhide && !(stat8 & (1 << 5))) {
printk(KERN_INFO "Contact your BIOS vendor to see if the "
"E752x error registers can be safely un-hidden\n");
return -ENODEV;
}
stat8 |= (1 << 5);
pci_write_config_byte(pdev, E752X_DEVPRES1, stat8);
pci_read_config_word(pdev, E752X_DDRCSR, &ddrcsr);
drc_chan = dual_channel_active(ddrcsr);
layers[0].type = EDAC_MC_LAYER_CHIP_SELECT;
layers[0].size = E752X_NR_CSROWS;
layers[0].is_virt_csrow = true;
layers[1].type = EDAC_MC_LAYER_CHANNEL;
layers[1].size = drc_chan + 1;
layers[1].is_virt_csrow = false;
mci = edac_mc_alloc(0, ARRAY_SIZE(layers), layers, sizeof(*pvt));
if (mci == NULL)
return -ENOMEM;
debugf3("%s(): init mci\n", __func__);
mci->mtype_cap = MEM_FLAG_RDDR;
mci->edac_ctl_cap = (dev_idx == I3100) ? EDAC_FLAG_SECDED :
(EDAC_FLAG_NONE | EDAC_FLAG_SECDED | EDAC_FLAG_S4ECD4ED);
mci->mod_name = EDAC_MOD_STR;
mci->mod_ver = E752X_REVISION;
mci->dev = &pdev->dev;
debugf3("%s(): init pvt\n", __func__);
pvt = (struct e752x_pvt *)mci->pvt_info;
pvt->dev_info = &e752x_devs[dev_idx];
pvt->mc_symmetric = ((ddrcsr & 0x10) != 0);
if (e752x_get_devs(pdev, dev_idx, pvt)) {
edac_mc_free(mci);
return -ENODEV;
}
debugf3("%s(): more mci init\n", __func__);
mci->ctl_name = pvt->dev_info->ctl_name;
mci->dev_name = pci_name(pdev);
mci->edac_check = e752x_check;
mci->ctl_page_to_phys = ctl_page_to_phys;
mci->set_sdram_scrub_rate = set_sdram_scrub_rate;
mci->get_sdram_scrub_rate = get_sdram_scrub_rate;
pci_read_config_byte(pdev, E752X_DRM, &stat8);
pvt->map_type = ((stat8 & 0x0f) > ((stat8 >> 4) & 0x0f));
e752x_init_csrows(mci, pdev, ddrcsr);
e752x_init_mem_map_table(pdev, pvt);
if (dev_idx == I3100)
mci->edac_cap = EDAC_FLAG_SECDED;
else
mci->edac_cap |= EDAC_FLAG_NONE;
debugf3("%s(): tolm, remapbase, remaplimit\n", __func__);
pci_read_config_word(pdev, E752X_TOLM, &pci_data);
pvt->tolm = ((u32) pci_data) << 4;
pci_read_config_word(pdev, E752X_REMAPBASE, &pci_data);
pvt->remapbase = ((u32) pci_data) << 14;
pci_read_config_word(pdev, E752X_REMAPLIMIT, &pci_data);
pvt->remaplimit = ((u32) pci_data) << 14;
e752x_printk(KERN_INFO,
"tolm = %x, remapbase = %x, remaplimit = %x\n",
pvt->tolm, pvt->remapbase, pvt->remaplimit);
if (edac_mc_add_mc(mci)) {
debugf3("%s(): failed edac_mc_add_mc()\n", __func__);
goto fail;
}
e752x_init_error_reporting_regs(pvt);
e752x_get_error_info(mci, &discard);
e752x_pci = edac_pci_create_generic_ctl(&pdev->dev, EDAC_MOD_STR);
if (!e752x_pci) {
printk(KERN_WARNING
"%s(): Unable to create PCI control\n", __func__);
printk(KERN_WARNING
"%s(): PCI error report via EDAC not setup\n",
__func__);
}
debugf3("%s(): success\n", __func__);
return 0;
fail:
pci_dev_put(pvt->dev_d0f0);
pci_dev_put(pvt->dev_d0f1);
pci_dev_put(pvt->bridge_ck);
edac_mc_free(mci);
return -ENODEV;
}
static int __devinit e752x_init_one(struct pci_dev *pdev,
const struct pci_device_id *ent)
{
debugf0("%s()\n", __func__);
if (pci_enable_device(pdev) < 0)
return -EIO;
return e752x_probe1(pdev, ent->driver_data);
}
static void __devexit e752x_remove_one(struct pci_dev *pdev)
{
struct mem_ctl_info *mci;
struct e752x_pvt *pvt;
debugf0("%s()\n", __func__);
if (e752x_pci)
edac_pci_release_generic_ctl(e752x_pci);
if ((mci = edac_mc_del_mc(&pdev->dev)) == NULL)
return;
pvt = (struct e752x_pvt *)mci->pvt_info;
pci_dev_put(pvt->dev_d0f0);
pci_dev_put(pvt->dev_d0f1);
pci_dev_put(pvt->bridge_ck);
edac_mc_free(mci);
}
static int __init e752x_init(void)
{
int pci_rc;
debugf3("%s()\n", __func__);
opstate_init();
pci_rc = pci_register_driver(&e752x_driver);
return (pci_rc < 0) ? pci_rc : 0;
}
static void __exit e752x_exit(void)
{
debugf3("%s()\n", __func__);
pci_unregister_driver(&e752x_driver);
}
