static inline __u64 readq(const volatile void __iomem *addr)
{
const volatile u32 __iomem *p = addr;
u32 low, high;
low = readl(p);
high = readl(p + 1);
return low + ((u64)high << 32);
}
static int how_many_channels(struct pci_dev *pdev)
{
unsigned char capid0_8b;
pci_read_config_byte(pdev, I3200_CAPID0 + 8, &capid0_8b);
if (capid0_8b & 0x20) {
debugf0("In single channel mode.\n");
return 1;
} else {
debugf0("In dual channel mode.\n");
return 2;
}
}
static unsigned long eccerrlog_syndrome(u64 log)
{
return (log & I3200_ECCERRLOG_SYNDROME_BITS) >>
I3200_ECCERRLOG_SYNDROME_SHIFT;
}
static int eccerrlog_row(int channel, u64 log)
{
u64 rank = ((log & I3200_ECCERRLOG_RANK_BITS) >>
I3200_ECCERRLOG_RANK_SHIFT);
return rank | (channel * I3200_RANKS_PER_CHANNEL);
}
static void i3200_clear_error_info(struct mem_ctl_info *mci)
{
struct pci_dev *pdev;
pdev = to_pci_dev(mci->dev);
pci_write_bits16(pdev, I3200_ERRSTS, I3200_ERRSTS_BITS,
I3200_ERRSTS_BITS);
}
static void i3200_get_and_clear_error_info(struct mem_ctl_info *mci,
struct i3200_error_info *info)
{
struct pci_dev *pdev;
struct i3200_priv *priv = mci->pvt_info;
void __iomem *window = priv->window;
pdev = to_pci_dev(mci->dev);
pci_read_config_word(pdev, I3200_ERRSTS, &info->errsts);
if (!(info->errsts & I3200_ERRSTS_BITS))
return;
info->eccerrlog[0] = readq(window + I3200_C0ECCERRLOG);
if (nr_channels == 2)
info->eccerrlog[1] = readq(window + I3200_C1ECCERRLOG);
pci_read_config_word(pdev, I3200_ERRSTS, &info->errsts2);
if ((info->errsts ^ info->errsts2) & I3200_ERRSTS_BITS) {
info->eccerrlog[0] = readq(window + I3200_C0ECCERRLOG);
if (nr_channels == 2)
info->eccerrlog[1] = readq(window + I3200_C1ECCERRLOG);
}
i3200_clear_error_info(mci);
}
static void i3200_process_error_info(struct mem_ctl_info *mci,
struct i3200_error_info *info)
{
int channel;
u64 log;
if (!(info->errsts & I3200_ERRSTS_BITS))
return;
if ((info->errsts ^ info->errsts2) & I3200_ERRSTS_BITS) {
edac_mc_handle_ce_no_info(mci, "UE overwrote CE");
info->errsts = info->errsts2;
}
for (channel = 0; channel < nr_channels; channel++) {
log = info->eccerrlog[channel];
if (log & I3200_ECCERRLOG_UE) {
edac_mc_handle_ue(mci, 0, 0,
eccerrlog_row(channel, log),
"i3200 UE");
} else if (log & I3200_ECCERRLOG_CE) {
edac_mc_handle_ce(mci, 0, 0,
eccerrlog_syndrome(log),
eccerrlog_row(channel, log), 0,
"i3200 CE");
}
}
}
static void i3200_check(struct mem_ctl_info *mci)
{
struct i3200_error_info info;
debugf1("MC%d: %s()\n", mci->mc_idx, __func__);
i3200_get_and_clear_error_info(mci, &info);
i3200_process_error_info(mci, &info);
}
void __iomem *i3200_map_mchbar(struct pci_dev *pdev)
{
union {
u64 mchbar;
struct {
u32 mchbar_low;
u32 mchbar_high;
};
} u;
void __iomem *window;
pci_read_config_dword(pdev, I3200_MCHBAR_LOW, &u.mchbar_low);
pci_read_config_dword(pdev, I3200_MCHBAR_HIGH, &u.mchbar_high);
u.mchbar &= I3200_MCHBAR_MASK;
if (u.mchbar != (resource_size_t)u.mchbar) {
printk(KERN_ERR
"i3200: mmio space beyond accessible range (0x%llx)\n",
(unsigned long long)u.mchbar);
return NULL;
}
window = ioremap_nocache(u.mchbar, I3200_MMR_WINDOW_SIZE);
if (!window)
printk(KERN_ERR "i3200: cannot map mmio space at 0x%llx\n",
(unsigned long long)u.mchbar);
return window;
}
static void i3200_get_drbs(void __iomem *window,
u16 drbs[I3200_CHANNELS][I3200_RANKS_PER_CHANNEL])
{
int i;
for (i = 0; i < I3200_RANKS_PER_CHANNEL; i++) {
drbs[0][i] = readw(window + I3200_C0DRB + 2*i) & I3200_DRB_MASK;
drbs[1][i] = readw(window + I3200_C1DRB + 2*i) & I3200_DRB_MASK;
}
}
static bool i3200_is_stacked(struct pci_dev *pdev,
u16 drbs[I3200_CHANNELS][I3200_RANKS_PER_CHANNEL])
{
u16 tom;
pci_read_config_word(pdev, I3200_TOM, &tom);
tom &= I3200_TOM_MASK;
return drbs[I3200_CHANNELS - 1][I3200_RANKS_PER_CHANNEL - 1] == tom;
}
static unsigned long drb_to_nr_pages(
u16 drbs[I3200_CHANNELS][I3200_RANKS_PER_CHANNEL], bool stacked,
int channel, int rank)
{
int n;
n = drbs[channel][rank];
if (rank > 0)
n -= drbs[channel][rank - 1];
if (stacked && (channel == 1) &&
drbs[channel][rank] == drbs[channel][I3200_RANKS_PER_CHANNEL - 1])
n -= drbs[0][I3200_RANKS_PER_CHANNEL - 1];
n <<= (I3200_DRB_SHIFT - PAGE_SHIFT);
return n;
}
static int i3200_probe1(struct pci_dev *pdev, int dev_idx)
{
int rc;
int i;
struct mem_ctl_info *mci = NULL;
unsigned long last_page;
u16 drbs[I3200_CHANNELS][I3200_RANKS_PER_CHANNEL];
bool stacked;
void __iomem *window;
struct i3200_priv *priv;
debugf0("MC: %s()\n", __func__);
window = i3200_map_mchbar(pdev);
if (!window)
return -ENODEV;
i3200_get_drbs(window, drbs);
nr_channels = how_many_channels(pdev);
mci = edac_mc_alloc(sizeof(struct i3200_priv), I3200_RANKS,
nr_channels, 0);
if (!mci)
return -ENOMEM;
debugf3("MC: %s(): init mci\n", __func__);
mci->dev = &pdev->dev;
mci->mtype_cap = MEM_FLAG_DDR2;
mci->edac_ctl_cap = EDAC_FLAG_SECDED;
mci->edac_cap = EDAC_FLAG_SECDED;
mci->mod_name = EDAC_MOD_STR;
mci->mod_ver = I3200_REVISION;
mci->ctl_name = i3200_devs[dev_idx].ctl_name;
mci->dev_name = pci_name(pdev);
mci->edac_check = i3200_check;
mci->ctl_page_to_phys = NULL;
priv = mci->pvt_info;
priv->window = window;
stacked = i3200_is_stacked(pdev, drbs);
last_page = -1UL;
for (i = 0; i < mci->nr_csrows; i++) {
unsigned long nr_pages;
struct csrow_info *csrow = &mci->csrows[i];
nr_pages = drb_to_nr_pages(drbs, stacked,
i / I3200_RANKS_PER_CHANNEL,
i % I3200_RANKS_PER_CHANNEL);
if (nr_pages == 0) {
csrow->mtype = MEM_EMPTY;
continue;
}
csrow->first_page = last_page + 1;
last_page += nr_pages;
csrow->last_page = last_page;
csrow->nr_pages = nr_pages;
csrow->grain = nr_pages << PAGE_SHIFT;
csrow->mtype = MEM_DDR2;
csrow->dtype = DEV_UNKNOWN;
csrow->edac_mode = EDAC_UNKNOWN;
}
i3200_clear_error_info(mci);
rc = -ENODEV;
if (edac_mc_add_mc(mci)) {
debugf3("MC: %s(): failed edac_mc_add_mc()\n", __func__);
goto fail;
}
debugf3("MC: %s(): success\n", __func__);
return 0;
fail:
iounmap(window);
if (mci)
edac_mc_free(mci);
return rc;
}
static int __devinit i3200_init_one(struct pci_dev *pdev,
const struct pci_device_id *ent)
{
int rc;
debugf0("MC: %s()\n", __func__);
if (pci_enable_device(pdev) < 0)
return -EIO;
rc = i3200_probe1(pdev, ent->driver_data);
if (!mci_pdev)
mci_pdev = pci_dev_get(pdev);
return rc;
}
static void __devexit i3200_remove_one(struct pci_dev *pdev)
{
struct mem_ctl_info *mci;
struct i3200_priv *priv;
debugf0("%s()\n", __func__);
mci = edac_mc_del_mc(&pdev->dev);
if (!mci)
return;
priv = mci->pvt_info;
iounmap(priv->window);
edac_mc_free(mci);
}
static int __init i3200_init(void)
{
int pci_rc;
debugf3("MC: %s()\n", __func__);
opstate_init();
pci_rc = pci_register_driver(&i3200_driver);
if (pci_rc < 0)
goto fail0;
if (!mci_pdev) {
i3200_registered = 0;
mci_pdev = pci_get_device(PCI_VENDOR_ID_INTEL,
PCI_DEVICE_ID_INTEL_3200_HB, NULL);
if (!mci_pdev) {
debugf0("i3200 pci_get_device fail\n");
pci_rc = -ENODEV;
goto fail1;
}
pci_rc = i3200_init_one(mci_pdev, i3200_pci_tbl);
if (pci_rc < 0) {
debugf0("i3200 init fail\n");
pci_rc = -ENODEV;
goto fail1;
}
}
return 0;
fail1:
pci_unregister_driver(&i3200_driver);
fail0:
if (mci_pdev)
pci_dev_put(mci_pdev);
return pci_rc;
}
static void __exit i3200_exit(void)
{
debugf3("MC: %s()\n", __func__);
pci_unregister_driver(&i3200_driver);
if (!i3200_registered) {
i3200_remove_one(mci_pdev);
pci_dev_put(mci_pdev);
}
}
