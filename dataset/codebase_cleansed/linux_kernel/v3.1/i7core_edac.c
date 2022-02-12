static inline int numdimms(u32 dimms)
{
return (dimms & 0x3) + 1;
}
static inline int numrank(u32 rank)
{
static int ranks[4] = { 1, 2, 4, -EINVAL };
return ranks[rank & 0x3];
}
static inline int numbank(u32 bank)
{
static int banks[4] = { 4, 8, 16, -EINVAL };
return banks[bank & 0x3];
}
static inline int numrow(u32 row)
{
static int rows[8] = {
1 << 12, 1 << 13, 1 << 14, 1 << 15,
1 << 16, -EINVAL, -EINVAL, -EINVAL,
};
return rows[row & 0x7];
}
static inline int numcol(u32 col)
{
static int cols[8] = {
1 << 10, 1 << 11, 1 << 12, -EINVAL,
};
return cols[col & 0x3];
}
static struct i7core_dev *get_i7core_dev(u8 socket)
{
struct i7core_dev *i7core_dev;
list_for_each_entry(i7core_dev, &i7core_edac_list, list) {
if (i7core_dev->socket == socket)
return i7core_dev;
}
return NULL;
}
static struct i7core_dev *alloc_i7core_dev(u8 socket,
const struct pci_id_table *table)
{
struct i7core_dev *i7core_dev;
i7core_dev = kzalloc(sizeof(*i7core_dev), GFP_KERNEL);
if (!i7core_dev)
return NULL;
i7core_dev->pdev = kzalloc(sizeof(*i7core_dev->pdev) * table->n_devs,
GFP_KERNEL);
if (!i7core_dev->pdev) {
kfree(i7core_dev);
return NULL;
}
i7core_dev->socket = socket;
i7core_dev->n_devs = table->n_devs;
list_add_tail(&i7core_dev->list, &i7core_edac_list);
return i7core_dev;
}
static void free_i7core_dev(struct i7core_dev *i7core_dev)
{
list_del(&i7core_dev->list);
kfree(i7core_dev->pdev);
kfree(i7core_dev);
}
static struct pci_dev *get_pdev_slot_func(u8 socket, unsigned slot,
unsigned func)
{
struct i7core_dev *i7core_dev = get_i7core_dev(socket);
int i;
if (!i7core_dev)
return NULL;
for (i = 0; i < i7core_dev->n_devs; i++) {
if (!i7core_dev->pdev[i])
continue;
if (PCI_SLOT(i7core_dev->pdev[i]->devfn) == slot &&
PCI_FUNC(i7core_dev->pdev[i]->devfn) == func) {
return i7core_dev->pdev[i];
}
}
return NULL;
}
static int i7core_get_active_channels(const u8 socket, unsigned *channels,
unsigned *csrows)
{
struct pci_dev *pdev = NULL;
int i, j;
u32 status, control;
*channels = 0;
*csrows = 0;
pdev = get_pdev_slot_func(socket, 3, 0);
if (!pdev) {
i7core_printk(KERN_ERR, "Couldn't find socket %d fn 3.0!!!\n",
socket);
return -ENODEV;
}
pci_read_config_dword(pdev, MC_STATUS, &status);
pci_read_config_dword(pdev, MC_CONTROL, &control);
for (i = 0; i < NUM_CHANS; i++) {
u32 dimm_dod[3];
if (!(control & (1 << (8 + i))))
continue;
if (status & (1 << i))
continue;
pdev = get_pdev_slot_func(socket, i + 4, 1);
if (!pdev) {
i7core_printk(KERN_ERR, "Couldn't find socket %d "
"fn %d.%d!!!\n",
socket, i + 4, 1);
return -ENODEV;
}
pci_read_config_dword(pdev,
MC_DOD_CH_DIMM0, &dimm_dod[0]);
pci_read_config_dword(pdev,
MC_DOD_CH_DIMM1, &dimm_dod[1]);
pci_read_config_dword(pdev,
MC_DOD_CH_DIMM2, &dimm_dod[2]);
(*channels)++;
for (j = 0; j < 3; j++) {
if (!DIMM_PRESENT(dimm_dod[j]))
continue;
(*csrows)++;
}
}
debugf0("Number of active channels on socket %d: %d\n",
socket, *channels);
return 0;
}
static int get_dimm_config(const struct mem_ctl_info *mci)
{
struct i7core_pvt *pvt = mci->pvt_info;
struct csrow_info *csr;
struct pci_dev *pdev;
int i, j;
int csrow = 0;
unsigned long last_page = 0;
enum edac_type mode;
enum mem_type mtype;
pdev = pvt->pci_mcr[0];
if (!pdev)
return -ENODEV;
pci_read_config_dword(pdev, MC_CONTROL, &pvt->info.mc_control);
pci_read_config_dword(pdev, MC_STATUS, &pvt->info.mc_status);
pci_read_config_dword(pdev, MC_MAX_DOD, &pvt->info.max_dod);
pci_read_config_dword(pdev, MC_CHANNEL_MAPPER, &pvt->info.ch_map);
debugf0("QPI %d control=0x%08x status=0x%08x dod=0x%08x map=0x%08x\n",
pvt->i7core_dev->socket, pvt->info.mc_control, pvt->info.mc_status,
pvt->info.max_dod, pvt->info.ch_map);
if (ECC_ENABLED(pvt)) {
debugf0("ECC enabled with x%d SDCC\n", ECCx8(pvt) ? 8 : 4);
if (ECCx8(pvt))
mode = EDAC_S8ECD8ED;
else
mode = EDAC_S4ECD4ED;
} else {
debugf0("ECC disabled\n");
mode = EDAC_NONE;
}
debugf0("DOD Max limits: DIMMS: %d, %d-ranked, %d-banked "
"x%x x 0x%x\n",
numdimms(pvt->info.max_dod),
numrank(pvt->info.max_dod >> 2),
numbank(pvt->info.max_dod >> 4),
numrow(pvt->info.max_dod >> 6),
numcol(pvt->info.max_dod >> 9));
for (i = 0; i < NUM_CHANS; i++) {
u32 data, dimm_dod[3], value[8];
if (!pvt->pci_ch[i][0])
continue;
if (!CH_ACTIVE(pvt, i)) {
debugf0("Channel %i is not active\n", i);
continue;
}
if (CH_DISABLED(pvt, i)) {
debugf0("Channel %i is disabled\n", i);
continue;
}
pci_read_config_dword(pvt->pci_ch[i][0],
MC_CHANNEL_DIMM_INIT_PARAMS, &data);
pvt->channel[i].ranks = (data & QUAD_RANK_PRESENT) ?
4 : 2;
if (data & REGISTERED_DIMM)
mtype = MEM_RDDR3;
else
mtype = MEM_DDR3;
#if 0
if (data & THREE_DIMMS_PRESENT)
pvt->channel[i].dimms = 3;
else if (data & SINGLE_QUAD_RANK_PRESENT)
pvt->channel[i].dimms = 1;
else
pvt->channel[i].dimms = 2;
#endif
pci_read_config_dword(pvt->pci_ch[i][1],
MC_DOD_CH_DIMM0, &dimm_dod[0]);
pci_read_config_dword(pvt->pci_ch[i][1],
MC_DOD_CH_DIMM1, &dimm_dod[1]);
pci_read_config_dword(pvt->pci_ch[i][1],
MC_DOD_CH_DIMM2, &dimm_dod[2]);
debugf0("Ch%d phy rd%d, wr%d (0x%08x): "
"%d ranks, %cDIMMs\n",
i,
RDLCH(pvt->info.ch_map, i), WRLCH(pvt->info.ch_map, i),
data,
pvt->channel[i].ranks,
(data & REGISTERED_DIMM) ? 'R' : 'U');
for (j = 0; j < 3; j++) {
u32 banks, ranks, rows, cols;
u32 size, npages;
if (!DIMM_PRESENT(dimm_dod[j]))
continue;
banks = numbank(MC_DOD_NUMBANK(dimm_dod[j]));
ranks = numrank(MC_DOD_NUMRANK(dimm_dod[j]));
rows = numrow(MC_DOD_NUMROW(dimm_dod[j]));
cols = numcol(MC_DOD_NUMCOL(dimm_dod[j]));
size = (rows * cols * banks * ranks) >> (20 - 3);
pvt->channel[i].dimms++;
debugf0("\tdimm %d %d Mb offset: %x, "
"bank: %d, rank: %d, row: %#x, col: %#x\n",
j, size,
RANKOFFSET(dimm_dod[j]),
banks, ranks, rows, cols);
npages = MiB_TO_PAGES(size);
csr = &mci->csrows[csrow];
csr->first_page = last_page + 1;
last_page += npages;
csr->last_page = last_page;
csr->nr_pages = npages;
csr->page_mask = 0;
csr->grain = 8;
csr->csrow_idx = csrow;
csr->nr_channels = 1;
csr->channels[0].chan_idx = i;
csr->channels[0].ce_count = 0;
pvt->csrow_map[i][j] = csrow;
switch (banks) {
case 4:
csr->dtype = DEV_X4;
break;
case 8:
csr->dtype = DEV_X8;
break;
case 16:
csr->dtype = DEV_X16;
break;
default:
csr->dtype = DEV_UNKNOWN;
}
csr->edac_mode = mode;
csr->mtype = mtype;
csrow++;
}
pci_read_config_dword(pdev, MC_SAG_CH_0, &value[0]);
pci_read_config_dword(pdev, MC_SAG_CH_1, &value[1]);
pci_read_config_dword(pdev, MC_SAG_CH_2, &value[2]);
pci_read_config_dword(pdev, MC_SAG_CH_3, &value[3]);
pci_read_config_dword(pdev, MC_SAG_CH_4, &value[4]);
pci_read_config_dword(pdev, MC_SAG_CH_5, &value[5]);
pci_read_config_dword(pdev, MC_SAG_CH_6, &value[6]);
pci_read_config_dword(pdev, MC_SAG_CH_7, &value[7]);
debugf1("\t[%i] DIVBY3\tREMOVED\tOFFSET\n", i);
for (j = 0; j < 8; j++)
debugf1("\t\t%#x\t%#x\t%#x\n",
(value[j] >> 27) & 0x1,
(value[j] >> 24) & 0x7,
(value[j] && ((1 << 24) - 1)));
}
return 0;
}
static int disable_inject(const struct mem_ctl_info *mci)
{
struct i7core_pvt *pvt = mci->pvt_info;
pvt->inject.enable = 0;
if (!pvt->pci_ch[pvt->inject.channel][0])
return -ENODEV;
pci_write_config_dword(pvt->pci_ch[pvt->inject.channel][0],
MC_CHANNEL_ERROR_INJECT, 0);
return 0;
}
static ssize_t i7core_inject_section_store(struct mem_ctl_info *mci,
const char *data, size_t count)
{
struct i7core_pvt *pvt = mci->pvt_info;
unsigned long value;
int rc;
if (pvt->inject.enable)
disable_inject(mci);
rc = strict_strtoul(data, 10, &value);
if ((rc < 0) || (value > 3))
return -EIO;
pvt->inject.section = (u32) value;
return count;
}
static ssize_t i7core_inject_section_show(struct mem_ctl_info *mci,
char *data)
{
struct i7core_pvt *pvt = mci->pvt_info;
return sprintf(data, "0x%08x\n", pvt->inject.section);
}
static ssize_t i7core_inject_type_store(struct mem_ctl_info *mci,
const char *data, size_t count)
{
struct i7core_pvt *pvt = mci->pvt_info;
unsigned long value;
int rc;
if (pvt->inject.enable)
disable_inject(mci);
rc = strict_strtoul(data, 10, &value);
if ((rc < 0) || (value > 7))
return -EIO;
pvt->inject.type = (u32) value;
return count;
}
static ssize_t i7core_inject_type_show(struct mem_ctl_info *mci,
char *data)
{
struct i7core_pvt *pvt = mci->pvt_info;
return sprintf(data, "0x%08x\n", pvt->inject.type);
}
static ssize_t i7core_inject_eccmask_store(struct mem_ctl_info *mci,
const char *data, size_t count)
{
struct i7core_pvt *pvt = mci->pvt_info;
unsigned long value;
int rc;
if (pvt->inject.enable)
disable_inject(mci);
rc = strict_strtoul(data, 10, &value);
if (rc < 0)
return -EIO;
pvt->inject.eccmask = (u32) value;
return count;
}
static ssize_t i7core_inject_eccmask_show(struct mem_ctl_info *mci,
char *data)
{
struct i7core_pvt *pvt = mci->pvt_info;
return sprintf(data, "0x%08x\n", pvt->inject.eccmask);
}
static int write_and_test(struct pci_dev *dev, const int where, const u32 val)
{
u32 read;
int count;
debugf0("setting pci %02x:%02x.%x reg=%02x value=%08x\n",
dev->bus->number, PCI_SLOT(dev->devfn), PCI_FUNC(dev->devfn),
where, val);
for (count = 0; count < 10; count++) {
if (count)
msleep(100);
pci_write_config_dword(dev, where, val);
pci_read_config_dword(dev, where, &read);
if (read == val)
return 0;
}
i7core_printk(KERN_ERR, "Error during set pci %02x:%02x.%x reg=%02x "
"write=%08x. Read=%08x\n",
dev->bus->number, PCI_SLOT(dev->devfn), PCI_FUNC(dev->devfn),
where, val, read);
return -EINVAL;
}
static ssize_t i7core_inject_enable_store(struct mem_ctl_info *mci,
const char *data, size_t count)
{
struct i7core_pvt *pvt = mci->pvt_info;
u32 injectmask;
u64 mask = 0;
int rc;
long enable;
if (!pvt->pci_ch[pvt->inject.channel][0])
return 0;
rc = strict_strtoul(data, 10, &enable);
if ((rc < 0))
return 0;
if (enable) {
pvt->inject.enable = 1;
} else {
disable_inject(mci);
return count;
}
if (pvt->inject.dimm < 0)
mask |= 1LL << 41;
else {
if (pvt->channel[pvt->inject.channel].dimms > 2)
mask |= (pvt->inject.dimm & 0x3LL) << 35;
else
mask |= (pvt->inject.dimm & 0x1LL) << 36;
}
if (pvt->inject.rank < 0)
mask |= 1LL << 40;
else {
if (pvt->channel[pvt->inject.channel].dimms > 2)
mask |= (pvt->inject.rank & 0x1LL) << 34;
else
mask |= (pvt->inject.rank & 0x3LL) << 34;
}
if (pvt->inject.bank < 0)
mask |= 1LL << 39;
else
mask |= (pvt->inject.bank & 0x15LL) << 30;
if (pvt->inject.page < 0)
mask |= 1LL << 38;
else
mask |= (pvt->inject.page & 0xffff) << 14;
if (pvt->inject.col < 0)
mask |= 1LL << 37;
else
mask |= (pvt->inject.col & 0x3fff);
injectmask = (pvt->inject.type & 1) |
(pvt->inject.section & 0x3) << 1 |
(pvt->inject.type & 0x6) << (3 - 1);
pci_write_config_dword(pvt->pci_noncore,
MC_CFG_CONTROL, 0x2);
write_and_test(pvt->pci_ch[pvt->inject.channel][0],
MC_CHANNEL_ADDR_MATCH, mask);
write_and_test(pvt->pci_ch[pvt->inject.channel][0],
MC_CHANNEL_ADDR_MATCH + 4, mask >> 32L);
write_and_test(pvt->pci_ch[pvt->inject.channel][0],
MC_CHANNEL_ERROR_MASK, pvt->inject.eccmask);
write_and_test(pvt->pci_ch[pvt->inject.channel][0],
MC_CHANNEL_ERROR_INJECT, injectmask);
pci_write_config_dword(pvt->pci_noncore,
MC_CFG_CONTROL, 8);
debugf0("Error inject addr match 0x%016llx, ecc 0x%08x,"
" inject 0x%08x\n",
mask, pvt->inject.eccmask, injectmask);
return count;
}
static ssize_t i7core_inject_enable_show(struct mem_ctl_info *mci,
char *data)
{
struct i7core_pvt *pvt = mci->pvt_info;
u32 injectmask;
if (!pvt->pci_ch[pvt->inject.channel][0])
return 0;
pci_read_config_dword(pvt->pci_ch[pvt->inject.channel][0],
MC_CHANNEL_ERROR_INJECT, &injectmask);
debugf0("Inject error read: 0x%018x\n", injectmask);
if (injectmask & 0x0c)
pvt->inject.enable = 1;
return sprintf(data, "%d\n", pvt->inject.enable);
}
static void i7core_put_devices(struct i7core_dev *i7core_dev)
{
int i;
debugf0(__FILE__ ": %s()\n", __func__);
for (i = 0; i < i7core_dev->n_devs; i++) {
struct pci_dev *pdev = i7core_dev->pdev[i];
if (!pdev)
continue;
debugf0("Removing dev %02x:%02x.%d\n",
pdev->bus->number,
PCI_SLOT(pdev->devfn), PCI_FUNC(pdev->devfn));
pci_dev_put(pdev);
}
}
static void i7core_put_all_devices(void)
{
struct i7core_dev *i7core_dev, *tmp;
list_for_each_entry_safe(i7core_dev, tmp, &i7core_edac_list, list) {
i7core_put_devices(i7core_dev);
free_i7core_dev(i7core_dev);
}
}
static void __init i7core_xeon_pci_fixup(const struct pci_id_table *table)
{
struct pci_dev *pdev = NULL;
int i;
while (table && table->descr) {
pdev = pci_get_device(PCI_VENDOR_ID_INTEL, table->descr[0].dev_id, NULL);
if (unlikely(!pdev)) {
for (i = 0; i < MAX_SOCKET_BUSES; i++)
pcibios_scan_specific_bus(255-i);
}
pci_dev_put(pdev);
table++;
}
}
static unsigned i7core_pci_lastbus(void)
{
int last_bus = 0, bus;
struct pci_bus *b = NULL;
while ((b = pci_find_next_bus(b)) != NULL) {
bus = b->number;
debugf0("Found bus %d\n", bus);
if (bus > last_bus)
last_bus = bus;
}
debugf0("Last bus %d\n", last_bus);
return last_bus;
}
static int i7core_get_onedevice(struct pci_dev **prev,
const struct pci_id_table *table,
const unsigned devno,
const unsigned last_bus)
{
struct i7core_dev *i7core_dev;
const struct pci_id_descr *dev_descr = &table->descr[devno];
struct pci_dev *pdev = NULL;
u8 bus = 0;
u8 socket = 0;
pdev = pci_get_device(PCI_VENDOR_ID_INTEL,
dev_descr->dev_id, *prev);
if (!pdev) {
if (*prev) {
*prev = pdev;
return 0;
}
if (dev_descr->optional)
return 0;
if (devno == 0)
return -ENODEV;
i7core_printk(KERN_INFO,
"Device not found: dev %02x.%d PCI ID %04x:%04x\n",
dev_descr->dev, dev_descr->func,
PCI_VENDOR_ID_INTEL, dev_descr->dev_id);
return -ENODEV;
}
bus = pdev->bus->number;
socket = last_bus - bus;
i7core_dev = get_i7core_dev(socket);
if (!i7core_dev) {
i7core_dev = alloc_i7core_dev(socket, table);
if (!i7core_dev) {
pci_dev_put(pdev);
return -ENOMEM;
}
}
if (i7core_dev->pdev[devno]) {
i7core_printk(KERN_ERR,
"Duplicated device for "
"dev %02x:%02x.%d PCI ID %04x:%04x\n",
bus, dev_descr->dev, dev_descr->func,
PCI_VENDOR_ID_INTEL, dev_descr->dev_id);
pci_dev_put(pdev);
return -ENODEV;
}
i7core_dev->pdev[devno] = pdev;
if (unlikely(PCI_SLOT(pdev->devfn) != dev_descr->dev ||
PCI_FUNC(pdev->devfn) != dev_descr->func)) {
i7core_printk(KERN_ERR,
"Device PCI ID %04x:%04x "
"has dev %02x:%02x.%d instead of dev %02x:%02x.%d\n",
PCI_VENDOR_ID_INTEL, dev_descr->dev_id,
bus, PCI_SLOT(pdev->devfn), PCI_FUNC(pdev->devfn),
bus, dev_descr->dev, dev_descr->func);
return -ENODEV;
}
if (unlikely(pci_enable_device(pdev) < 0)) {
i7core_printk(KERN_ERR,
"Couldn't enable "
"dev %02x:%02x.%d PCI ID %04x:%04x\n",
bus, dev_descr->dev, dev_descr->func,
PCI_VENDOR_ID_INTEL, dev_descr->dev_id);
return -ENODEV;
}
debugf0("Detected socket %d dev %02x:%02x.%d PCI ID %04x:%04x\n",
socket, bus, dev_descr->dev,
dev_descr->func,
PCI_VENDOR_ID_INTEL, dev_descr->dev_id);
pci_dev_get(pdev);
*prev = pdev;
return 0;
}
static int i7core_get_all_devices(void)
{
int i, rc, last_bus;
struct pci_dev *pdev = NULL;
const struct pci_id_table *table = pci_dev_table;
last_bus = i7core_pci_lastbus();
while (table && table->descr) {
for (i = 0; i < table->n_devs; i++) {
pdev = NULL;
do {
rc = i7core_get_onedevice(&pdev, table, i,
last_bus);
if (rc < 0) {
if (i == 0) {
i = table->n_devs;
break;
}
i7core_put_all_devices();
return -ENODEV;
}
} while (pdev);
}
table++;
}
return 0;
}
static int mci_bind_devs(struct mem_ctl_info *mci,
struct i7core_dev *i7core_dev)
{
struct i7core_pvt *pvt = mci->pvt_info;
struct pci_dev *pdev;
int i, func, slot;
pvt->is_registered = 0;
for (i = 0; i < i7core_dev->n_devs; i++) {
pdev = i7core_dev->pdev[i];
if (!pdev)
continue;
func = PCI_FUNC(pdev->devfn);
slot = PCI_SLOT(pdev->devfn);
if (slot == 3) {
if (unlikely(func > MAX_MCR_FUNC))
goto error;
pvt->pci_mcr[func] = pdev;
} else if (likely(slot >= 4 && slot < 4 + NUM_CHANS)) {
if (unlikely(func > MAX_CHAN_FUNC))
goto error;
pvt->pci_ch[slot - 4][func] = pdev;
} else if (!slot && !func)
pvt->pci_noncore = pdev;
else
goto error;
debugf0("Associated fn %d.%d, dev = %p, socket %d\n",
PCI_SLOT(pdev->devfn), PCI_FUNC(pdev->devfn),
pdev, i7core_dev->socket);
if (PCI_SLOT(pdev->devfn) == 3 &&
PCI_FUNC(pdev->devfn) == 2)
pvt->is_registered = 1;
}
return 0;
error:
i7core_printk(KERN_ERR, "Device %d, function %d "
"is out of the expected range\n",
slot, func);
return -EINVAL;
}
static void i7core_rdimm_update_csrow(struct mem_ctl_info *mci,
const int chan,
const int dimm,
const int add)
{
char *msg;
struct i7core_pvt *pvt = mci->pvt_info;
int row = pvt->csrow_map[chan][dimm], i;
for (i = 0; i < add; i++) {
msg = kasprintf(GFP_KERNEL, "Corrected error "
"(Socket=%d channel=%d dimm=%d)",
pvt->i7core_dev->socket, chan, dimm);
edac_mc_handle_fbd_ce(mci, row, 0, msg);
kfree (msg);
}
}
static void i7core_rdimm_update_ce_count(struct mem_ctl_info *mci,
const int chan,
const int new0,
const int new1,
const int new2)
{
struct i7core_pvt *pvt = mci->pvt_info;
int add0 = 0, add1 = 0, add2 = 0;
if (pvt->ce_count_available) {
add2 = new2 - pvt->rdimm_last_ce_count[chan][2];
add1 = new1 - pvt->rdimm_last_ce_count[chan][1];
add0 = new0 - pvt->rdimm_last_ce_count[chan][0];
if (add2 < 0)
add2 += 0x7fff;
pvt->rdimm_ce_count[chan][2] += add2;
if (add1 < 0)
add1 += 0x7fff;
pvt->rdimm_ce_count[chan][1] += add1;
if (add0 < 0)
add0 += 0x7fff;
pvt->rdimm_ce_count[chan][0] += add0;
} else
pvt->ce_count_available = 1;
pvt->rdimm_last_ce_count[chan][2] = new2;
pvt->rdimm_last_ce_count[chan][1] = new1;
pvt->rdimm_last_ce_count[chan][0] = new0;
if (add0 != 0)
i7core_rdimm_update_csrow(mci, chan, 0, add0);
if (add1 != 0)
i7core_rdimm_update_csrow(mci, chan, 1, add1);
if (add2 != 0)
i7core_rdimm_update_csrow(mci, chan, 2, add2);
}
static void i7core_rdimm_check_mc_ecc_err(struct mem_ctl_info *mci)
{
struct i7core_pvt *pvt = mci->pvt_info;
u32 rcv[3][2];
int i, new0, new1, new2;
pci_read_config_dword(pvt->pci_mcr[2], MC_COR_ECC_CNT_0,
&rcv[0][0]);
pci_read_config_dword(pvt->pci_mcr[2], MC_COR_ECC_CNT_1,
&rcv[0][1]);
pci_read_config_dword(pvt->pci_mcr[2], MC_COR_ECC_CNT_2,
&rcv[1][0]);
pci_read_config_dword(pvt->pci_mcr[2], MC_COR_ECC_CNT_3,
&rcv[1][1]);
pci_read_config_dword(pvt->pci_mcr[2], MC_COR_ECC_CNT_4,
&rcv[2][0]);
pci_read_config_dword(pvt->pci_mcr[2], MC_COR_ECC_CNT_5,
&rcv[2][1]);
for (i = 0 ; i < 3; i++) {
debugf3("MC_COR_ECC_CNT%d = 0x%x; MC_COR_ECC_CNT%d = 0x%x\n",
(i * 2), rcv[i][0], (i * 2) + 1, rcv[i][1]);
if (pvt->channel[i].dimms > 2) {
new0 = DIMM_BOT_COR_ERR(rcv[i][0]);
new1 = DIMM_TOP_COR_ERR(rcv[i][0]);
new2 = DIMM_BOT_COR_ERR(rcv[i][1]);
} else {
new0 = DIMM_TOP_COR_ERR(rcv[i][0]) +
DIMM_BOT_COR_ERR(rcv[i][0]);
new1 = DIMM_TOP_COR_ERR(rcv[i][1]) +
DIMM_BOT_COR_ERR(rcv[i][1]);
new2 = 0;
}
i7core_rdimm_update_ce_count(mci, i, new0, new1, new2);
}
}
static void i7core_udimm_check_mc_ecc_err(struct mem_ctl_info *mci)
{
struct i7core_pvt *pvt = mci->pvt_info;
u32 rcv1, rcv0;
int new0, new1, new2;
if (!pvt->pci_mcr[4]) {
debugf0("%s MCR registers not found\n", __func__);
return;
}
pci_read_config_dword(pvt->pci_mcr[4], MC_TEST_ERR_RCV1, &rcv1);
pci_read_config_dword(pvt->pci_mcr[4], MC_TEST_ERR_RCV0, &rcv0);
new2 = DIMM2_COR_ERR(rcv1);
new1 = DIMM1_COR_ERR(rcv0);
new0 = DIMM0_COR_ERR(rcv0);
if (pvt->ce_count_available) {
int add0, add1, add2;
add2 = new2 - pvt->udimm_last_ce_count[2];
add1 = new1 - pvt->udimm_last_ce_count[1];
add0 = new0 - pvt->udimm_last_ce_count[0];
if (add2 < 0)
add2 += 0x7fff;
pvt->udimm_ce_count[2] += add2;
if (add1 < 0)
add1 += 0x7fff;
pvt->udimm_ce_count[1] += add1;
if (add0 < 0)
add0 += 0x7fff;
pvt->udimm_ce_count[0] += add0;
if (add0 | add1 | add2)
i7core_printk(KERN_ERR, "New Corrected error(s): "
"dimm0: +%d, dimm1: +%d, dimm2 +%d\n",
add0, add1, add2);
} else
pvt->ce_count_available = 1;
pvt->udimm_last_ce_count[2] = new2;
pvt->udimm_last_ce_count[1] = new1;
pvt->udimm_last_ce_count[0] = new0;
}
static void i7core_mce_output_error(struct mem_ctl_info *mci,
const struct mce *m)
{
struct i7core_pvt *pvt = mci->pvt_info;
char *type, *optype, *err, *msg;
unsigned long error = m->status & 0x1ff0000l;
u32 optypenum = (m->status >> 4) & 0x07;
u32 core_err_cnt = (m->status >> 38) & 0x7fff;
u32 dimm = (m->misc >> 16) & 0x3;
u32 channel = (m->misc >> 18) & 0x3;
u32 syndrome = m->misc >> 32;
u32 errnum = find_first_bit(&error, 32);
int csrow;
if (m->mcgstatus & 1)
type = "FATAL";
else
type = "NON_FATAL";
switch (optypenum) {
case 0:
optype = "generic undef request";
break;
case 1:
optype = "read error";
break;
case 2:
optype = "write error";
break;
case 3:
optype = "addr/cmd error";
break;
case 4:
optype = "scrubbing error";
break;
default:
optype = "reserved";
break;
}
switch (errnum) {
case 16:
err = "read ECC error";
break;
case 17:
err = "RAS ECC error";
break;
case 18:
err = "write parity error";
break;
case 19:
err = "redundacy loss";
break;
case 20:
err = "reserved";
break;
case 21:
err = "memory range error";
break;
case 22:
err = "RTID out of range";
break;
case 23:
err = "address parity error";
break;
case 24:
err = "byte enable parity error";
break;
default:
err = "unknown";
}
msg = kasprintf(GFP_ATOMIC,
"%s (addr = 0x%08llx, cpu=%d, Dimm=%d, Channel=%d, "
"syndrome=0x%08x, count=%d, Err=%08llx:%08llx (%s: %s))\n",
type, (long long) m->addr, m->cpu, dimm, channel,
syndrome, core_err_cnt, (long long)m->status,
(long long)m->misc, optype, err);
debugf0("%s", msg);
csrow = pvt->csrow_map[channel][dimm];
if (m->mcgstatus & 1)
edac_mc_handle_fbd_ue(mci, csrow, 0,
0 , msg);
else if (!pvt->is_registered)
edac_mc_handle_fbd_ce(mci, csrow,
0 , msg);
kfree(msg);
}
static void i7core_check_error(struct mem_ctl_info *mci)
{
struct i7core_pvt *pvt = mci->pvt_info;
int i;
unsigned count = 0;
struct mce *m;
smp_rmb();
count = (pvt->mce_out + MCE_LOG_LEN - pvt->mce_in)
% MCE_LOG_LEN;
if (!count)
goto check_ce_error;
m = pvt->mce_outentry;
if (pvt->mce_in + count > MCE_LOG_LEN) {
unsigned l = MCE_LOG_LEN - pvt->mce_in;
memcpy(m, &pvt->mce_entry[pvt->mce_in], sizeof(*m) * l);
smp_wmb();
pvt->mce_in = 0;
count -= l;
m += l;
}
memcpy(m, &pvt->mce_entry[pvt->mce_in], sizeof(*m) * count);
smp_wmb();
pvt->mce_in += count;
smp_rmb();
if (pvt->mce_overrun) {
i7core_printk(KERN_ERR, "Lost %d memory errors\n",
pvt->mce_overrun);
smp_wmb();
pvt->mce_overrun = 0;
}
for (i = 0; i < count; i++)
i7core_mce_output_error(mci, &pvt->mce_outentry[i]);
check_ce_error:
if (!pvt->is_registered)
i7core_udimm_check_mc_ecc_err(mci);
else
i7core_rdimm_check_mc_ecc_err(mci);
}
static int i7core_mce_check_error(void *priv, struct mce *mce)
{
struct mem_ctl_info *mci = priv;
struct i7core_pvt *pvt = mci->pvt_info;
if (((mce->status & 0xffff) >> 7) != 1)
return 0;
if (mce->bank != 8)
return 0;
#ifdef CONFIG_SMP
if (cpu_data(mce->cpu).phys_proc_id != pvt->i7core_dev->socket)
return 0;
#endif
smp_rmb();
if ((pvt->mce_out + 1) % MCE_LOG_LEN == pvt->mce_in) {
smp_wmb();
pvt->mce_overrun++;
return 0;
}
memcpy(&pvt->mce_entry[pvt->mce_out], mce, sizeof(*mce));
smp_wmb();
pvt->mce_out = (pvt->mce_out + 1) % MCE_LOG_LEN;
if (mce->mcgstatus & 1)
i7core_check_error(mci);
return 1;
}
static void i7core_pci_ctl_create(struct i7core_pvt *pvt)
{
pvt->i7core_pci = edac_pci_create_generic_ctl(
&pvt->i7core_dev->pdev[0]->dev,
EDAC_MOD_STR);
if (unlikely(!pvt->i7core_pci))
pr_warn("Unable to setup PCI error report via EDAC\n");
}
static void i7core_pci_ctl_release(struct i7core_pvt *pvt)
{
if (likely(pvt->i7core_pci))
edac_pci_release_generic_ctl(pvt->i7core_pci);
else
i7core_printk(KERN_ERR,
"Couldn't find mem_ctl_info for socket %d\n",
pvt->i7core_dev->socket);
pvt->i7core_pci = NULL;
}
static void i7core_unregister_mci(struct i7core_dev *i7core_dev)
{
struct mem_ctl_info *mci = i7core_dev->mci;
struct i7core_pvt *pvt;
if (unlikely(!mci || !mci->pvt_info)) {
debugf0("MC: " __FILE__ ": %s(): dev = %p\n",
__func__, &i7core_dev->pdev[0]->dev);
i7core_printk(KERN_ERR, "Couldn't find mci handler\n");
return;
}
pvt = mci->pvt_info;
debugf0("MC: " __FILE__ ": %s(): mci = %p, dev = %p\n",
__func__, mci, &i7core_dev->pdev[0]->dev);
edac_mce_unregister(&pvt->edac_mce);
i7core_pci_ctl_release(pvt);
edac_mc_del_mc(mci->dev);
debugf1("%s: free mci struct\n", mci->ctl_name);
kfree(mci->ctl_name);
edac_mc_free(mci);
i7core_dev->mci = NULL;
}
static int i7core_register_mci(struct i7core_dev *i7core_dev)
{
struct mem_ctl_info *mci;
struct i7core_pvt *pvt;
int rc, channels, csrows;
rc = i7core_get_active_channels(i7core_dev->socket, &channels, &csrows);
if (unlikely(rc < 0))
return rc;
mci = edac_mc_alloc(sizeof(*pvt), csrows, channels, i7core_dev->socket);
if (unlikely(!mci))
return -ENOMEM;
debugf0("MC: " __FILE__ ": %s(): mci = %p, dev = %p\n",
__func__, mci, &i7core_dev->pdev[0]->dev);
pvt = mci->pvt_info;
memset(pvt, 0, sizeof(*pvt));
pvt->i7core_dev = i7core_dev;
i7core_dev->mci = mci;
mci->mtype_cap = MEM_FLAG_DDR3;
mci->edac_ctl_cap = EDAC_FLAG_NONE;
mci->edac_cap = EDAC_FLAG_NONE;
mci->mod_name = "i7core_edac.c";
mci->mod_ver = I7CORE_REVISION;
mci->ctl_name = kasprintf(GFP_KERNEL, "i7 core #%d",
i7core_dev->socket);
mci->dev_name = pci_name(i7core_dev->pdev[0]);
mci->ctl_page_to_phys = NULL;
rc = mci_bind_devs(mci, i7core_dev);
if (unlikely(rc < 0))
goto fail0;
if (pvt->is_registered)
mci->mc_driver_sysfs_attributes = i7core_sysfs_rdimm_attrs;
else
mci->mc_driver_sysfs_attributes = i7core_sysfs_udimm_attrs;
get_dimm_config(mci);
mci->dev = &i7core_dev->pdev[0]->dev;
mci->edac_check = i7core_check_error;
if (unlikely(edac_mc_add_mc(mci))) {
debugf0("MC: " __FILE__
": %s(): failed edac_mc_add_mc()\n", __func__);
rc = -EINVAL;
goto fail0;
}
pvt->inject.channel = 0;
pvt->inject.dimm = -1;
pvt->inject.rank = -1;
pvt->inject.bank = -1;
pvt->inject.page = -1;
pvt->inject.col = -1;
i7core_pci_ctl_create(pvt);
pvt->edac_mce.priv = mci;
pvt->edac_mce.check_error = i7core_mce_check_error;
rc = edac_mce_register(&pvt->edac_mce);
if (unlikely(rc < 0)) {
debugf0("MC: " __FILE__
": %s(): failed edac_mce_register()\n", __func__);
goto fail1;
}
return 0;
fail1:
i7core_pci_ctl_release(pvt);
edac_mc_del_mc(mci->dev);
fail0:
kfree(mci->ctl_name);
edac_mc_free(mci);
i7core_dev->mci = NULL;
return rc;
}
static int __devinit i7core_probe(struct pci_dev *pdev,
const struct pci_device_id *id)
{
int rc;
struct i7core_dev *i7core_dev;
mutex_lock(&i7core_edac_lock);
if (unlikely(probed >= 1)) {
mutex_unlock(&i7core_edac_lock);
return -ENODEV;
}
probed++;
rc = i7core_get_all_devices();
if (unlikely(rc < 0))
goto fail0;
list_for_each_entry(i7core_dev, &i7core_edac_list, list) {
rc = i7core_register_mci(i7core_dev);
if (unlikely(rc < 0))
goto fail1;
}
i7core_printk(KERN_INFO, "Driver loaded.\n");
mutex_unlock(&i7core_edac_lock);
return 0;
fail1:
list_for_each_entry(i7core_dev, &i7core_edac_list, list)
i7core_unregister_mci(i7core_dev);
i7core_put_all_devices();
fail0:
mutex_unlock(&i7core_edac_lock);
return rc;
}
static void __devexit i7core_remove(struct pci_dev *pdev)
{
struct i7core_dev *i7core_dev;
debugf0(__FILE__ ": %s()\n", __func__);
mutex_lock(&i7core_edac_lock);
if (unlikely(!probed)) {
mutex_unlock(&i7core_edac_lock);
return;
}
list_for_each_entry(i7core_dev, &i7core_edac_list, list)
i7core_unregister_mci(i7core_dev);
i7core_put_all_devices();
probed--;
mutex_unlock(&i7core_edac_lock);
}
static int __init i7core_init(void)
{
int pci_rc;
debugf2("MC: " __FILE__ ": %s()\n", __func__);
opstate_init();
if (use_pci_fixup)
i7core_xeon_pci_fixup(pci_dev_table);
pci_rc = pci_register_driver(&i7core_driver);
if (pci_rc >= 0)
return 0;
i7core_printk(KERN_ERR, "Failed to register device with error %d.\n",
pci_rc);
return pci_rc;
}
static void __exit i7core_exit(void)
{
debugf2("MC: " __FILE__ ": %s()\n", __func__);
pci_unregister_driver(&i7core_driver);
}
