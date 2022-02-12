static inline unsigned long deap_pfn(u8 edeap, u32 deap)
{
deap >>= PAGE_SHIFT;
deap |= (edeap & 1) << (32 - PAGE_SHIFT);
return deap;
}
static inline unsigned long deap_offset(u32 deap)
{
return deap & ~(I3000_DEAP_GRAIN - 1) & ~PAGE_MASK;
}
static inline int deap_channel(u32 deap)
{
return deap & 1;
}
static inline unsigned char odd_rank_attrib(unsigned char dra)
{
return (dra & 0x70) >> 4;
}
static inline unsigned char even_rank_attrib(unsigned char dra)
{
return dra & 0x07;
}
static void i3000_get_error_info(struct mem_ctl_info *mci,
struct i3000_error_info *info)
{
struct pci_dev *pdev;
pdev = to_pci_dev(mci->pdev);
pci_read_config_word(pdev, I3000_ERRSTS, &info->errsts);
if (!(info->errsts & I3000_ERRSTS_BITS))
return;
pci_read_config_byte(pdev, I3000_EDEAP, &info->edeap);
pci_read_config_dword(pdev, I3000_DEAP, &info->deap);
pci_read_config_byte(pdev, I3000_DERRSYN, &info->derrsyn);
pci_read_config_word(pdev, I3000_ERRSTS, &info->errsts2);
if ((info->errsts ^ info->errsts2) & I3000_ERRSTS_BITS) {
pci_read_config_byte(pdev, I3000_EDEAP, &info->edeap);
pci_read_config_dword(pdev, I3000_DEAP, &info->deap);
pci_read_config_byte(pdev, I3000_DERRSYN, &info->derrsyn);
}
pci_write_bits16(pdev, I3000_ERRSTS, I3000_ERRSTS_BITS,
I3000_ERRSTS_BITS);
}
static int i3000_process_error_info(struct mem_ctl_info *mci,
struct i3000_error_info *info,
int handle_errors)
{
int row, multi_chan, channel;
unsigned long pfn, offset;
multi_chan = mci->csrows[0]->nr_channels - 1;
if (!(info->errsts & I3000_ERRSTS_BITS))
return 0;
if (!handle_errors)
return 1;
if ((info->errsts ^ info->errsts2) & I3000_ERRSTS_BITS) {
edac_mc_handle_error(HW_EVENT_ERR_UNCORRECTED, mci, 1, 0, 0, 0,
-1, -1, -1,
"UE overwrote CE", "");
info->errsts = info->errsts2;
}
pfn = deap_pfn(info->edeap, info->deap);
offset = deap_offset(info->deap);
channel = deap_channel(info->deap);
row = edac_mc_find_csrow_by_page(mci, pfn);
if (info->errsts & I3000_ERRSTS_UE)
edac_mc_handle_error(HW_EVENT_ERR_UNCORRECTED, mci, 1,
pfn, offset, 0,
row, -1, -1,
"i3000 UE", "");
else
edac_mc_handle_error(HW_EVENT_ERR_CORRECTED, mci, 1,
pfn, offset, info->derrsyn,
row, multi_chan ? channel : 0, -1,
"i3000 CE", "");
return 1;
}
static void i3000_check(struct mem_ctl_info *mci)
{
struct i3000_error_info info;
edac_dbg(1, "MC%d\n", mci->mc_idx);
i3000_get_error_info(mci, &info);
i3000_process_error_info(mci, &info, 1);
}
static int i3000_is_interleaved(const unsigned char *c0dra,
const unsigned char *c1dra,
const unsigned char *c0drb,
const unsigned char *c1drb)
{
int i;
for (i = 0; i < I3000_RANKS_PER_CHANNEL / 2; i++)
if (odd_rank_attrib(c0dra[i]) != odd_rank_attrib(c1dra[i]) ||
even_rank_attrib(c0dra[i]) !=
even_rank_attrib(c1dra[i]))
return 0;
for (i = 0; i < I3000_RANKS_PER_CHANNEL; i++)
if (c0drb[i] != c1drb[i])
return 0;
return 1;
}
static int i3000_probe1(struct pci_dev *pdev, int dev_idx)
{
int rc;
int i, j;
struct mem_ctl_info *mci = NULL;
struct edac_mc_layer layers[2];
unsigned long last_cumul_size, nr_pages;
int interleaved, nr_channels;
unsigned char dra[I3000_RANKS / 2], drb[I3000_RANKS];
unsigned char *c0dra = dra, *c1dra = &dra[I3000_RANKS_PER_CHANNEL / 2];
unsigned char *c0drb = drb, *c1drb = &drb[I3000_RANKS_PER_CHANNEL];
unsigned long mchbar;
void __iomem *window;
edac_dbg(0, "MC:\n");
pci_read_config_dword(pdev, I3000_MCHBAR, (u32 *) & mchbar);
mchbar &= I3000_MCHBAR_MASK;
window = ioremap_nocache(mchbar, I3000_MMR_WINDOW_SIZE);
if (!window) {
printk(KERN_ERR "i3000: cannot map mmio space at 0x%lx\n",
mchbar);
return -ENODEV;
}
c0dra[0] = readb(window + I3000_C0DRA + 0);
c0dra[1] = readb(window + I3000_C0DRA + 1);
c1dra[0] = readb(window + I3000_C1DRA + 0);
c1dra[1] = readb(window + I3000_C1DRA + 1);
for (i = 0; i < I3000_RANKS_PER_CHANNEL; i++) {
c0drb[i] = readb(window + I3000_C0DRB + i);
c1drb[i] = readb(window + I3000_C1DRB + i);
}
iounmap(window);
interleaved = i3000_is_interleaved(c0dra, c1dra, c0drb, c1drb);
nr_channels = interleaved ? 2 : 1;
layers[0].type = EDAC_MC_LAYER_CHIP_SELECT;
layers[0].size = I3000_RANKS / nr_channels;
layers[0].is_virt_csrow = true;
layers[1].type = EDAC_MC_LAYER_CHANNEL;
layers[1].size = nr_channels;
layers[1].is_virt_csrow = false;
mci = edac_mc_alloc(0, ARRAY_SIZE(layers), layers, 0);
if (!mci)
return -ENOMEM;
edac_dbg(3, "MC: init mci\n");
mci->pdev = &pdev->dev;
mci->mtype_cap = MEM_FLAG_DDR2;
mci->edac_ctl_cap = EDAC_FLAG_SECDED;
mci->edac_cap = EDAC_FLAG_SECDED;
mci->mod_name = EDAC_MOD_STR;
mci->mod_ver = I3000_REVISION;
mci->ctl_name = i3000_devs[dev_idx].ctl_name;
mci->dev_name = pci_name(pdev);
mci->edac_check = i3000_check;
mci->ctl_page_to_phys = NULL;
for (last_cumul_size = i = 0; i < mci->nr_csrows; i++) {
u8 value;
u32 cumul_size;
struct csrow_info *csrow = mci->csrows[i];
value = drb[i];
cumul_size = value << (I3000_DRB_SHIFT - PAGE_SHIFT);
if (interleaved)
cumul_size <<= 1;
edac_dbg(3, "MC: (%d) cumul_size 0x%x\n", i, cumul_size);
if (cumul_size == last_cumul_size)
continue;
csrow->first_page = last_cumul_size;
csrow->last_page = cumul_size - 1;
nr_pages = cumul_size - last_cumul_size;
last_cumul_size = cumul_size;
for (j = 0; j < nr_channels; j++) {
struct dimm_info *dimm = csrow->channels[j]->dimm;
dimm->nr_pages = nr_pages / nr_channels;
dimm->grain = I3000_DEAP_GRAIN;
dimm->mtype = MEM_DDR2;
dimm->dtype = DEV_UNKNOWN;
dimm->edac_mode = EDAC_UNKNOWN;
}
}
pci_write_bits16(pdev, I3000_ERRSTS, I3000_ERRSTS_BITS,
I3000_ERRSTS_BITS);
rc = -ENODEV;
if (edac_mc_add_mc(mci)) {
edac_dbg(3, "MC: failed edac_mc_add_mc()\n");
goto fail;
}
i3000_pci = edac_pci_create_generic_ctl(&pdev->dev, EDAC_MOD_STR);
if (!i3000_pci) {
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
if (mci)
edac_mc_free(mci);
return rc;
}
static int i3000_init_one(struct pci_dev *pdev, const struct pci_device_id *ent)
{
int rc;
edac_dbg(0, "MC:\n");
if (pci_enable_device(pdev) < 0)
return -EIO;
rc = i3000_probe1(pdev, ent->driver_data);
if (!mci_pdev)
mci_pdev = pci_dev_get(pdev);
return rc;
}
static void i3000_remove_one(struct pci_dev *pdev)
{
struct mem_ctl_info *mci;
edac_dbg(0, "\n");
if (i3000_pci)
edac_pci_release_generic_ctl(i3000_pci);
mci = edac_mc_del_mc(&pdev->dev);
if (!mci)
return;
edac_mc_free(mci);
}
static int __init i3000_init(void)
{
int pci_rc;
edac_dbg(3, "MC:\n");
opstate_init();
pci_rc = pci_register_driver(&i3000_driver);
if (pci_rc < 0)
goto fail0;
if (!mci_pdev) {
i3000_registered = 0;
mci_pdev = pci_get_device(PCI_VENDOR_ID_INTEL,
PCI_DEVICE_ID_INTEL_3000_HB, NULL);
if (!mci_pdev) {
edac_dbg(0, "i3000 pci_get_device fail\n");
pci_rc = -ENODEV;
goto fail1;
}
pci_rc = i3000_init_one(mci_pdev, i3000_pci_tbl);
if (pci_rc < 0) {
edac_dbg(0, "i3000 init fail\n");
pci_rc = -ENODEV;
goto fail1;
}
}
return 0;
fail1:
pci_unregister_driver(&i3000_driver);
fail0:
if (mci_pdev)
pci_dev_put(mci_pdev);
return pci_rc;
}
static void __exit i3000_exit(void)
{
edac_dbg(3, "MC:\n");
pci_unregister_driver(&i3000_driver);
if (!i3000_registered) {
i3000_remove_one(mci_pdev);
pci_dev_put(mci_pdev);
}
}
