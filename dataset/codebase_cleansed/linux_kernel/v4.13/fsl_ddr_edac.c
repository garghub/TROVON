static inline u32 ddr_in32(void __iomem *addr)
{
return little_endian ? ioread32(addr) : ioread32be(addr);
}
static inline void ddr_out32(void __iomem *addr, u32 value)
{
if (little_endian)
iowrite32(value, addr);
else
iowrite32be(value, addr);
}
static ssize_t fsl_mc_inject_data_hi_show(struct device *dev,
struct device_attribute *mattr,
char *data)
{
struct mem_ctl_info *mci = to_mci(dev);
struct fsl_mc_pdata *pdata = mci->pvt_info;
return sprintf(data, "0x%08x",
ddr_in32(pdata->mc_vbase + FSL_MC_DATA_ERR_INJECT_HI));
}
static ssize_t fsl_mc_inject_data_lo_show(struct device *dev,
struct device_attribute *mattr,
char *data)
{
struct mem_ctl_info *mci = to_mci(dev);
struct fsl_mc_pdata *pdata = mci->pvt_info;
return sprintf(data, "0x%08x",
ddr_in32(pdata->mc_vbase + FSL_MC_DATA_ERR_INJECT_LO));
}
static ssize_t fsl_mc_inject_ctrl_show(struct device *dev,
struct device_attribute *mattr,
char *data)
{
struct mem_ctl_info *mci = to_mci(dev);
struct fsl_mc_pdata *pdata = mci->pvt_info;
return sprintf(data, "0x%08x",
ddr_in32(pdata->mc_vbase + FSL_MC_ECC_ERR_INJECT));
}
static ssize_t fsl_mc_inject_data_hi_store(struct device *dev,
struct device_attribute *mattr,
const char *data, size_t count)
{
struct mem_ctl_info *mci = to_mci(dev);
struct fsl_mc_pdata *pdata = mci->pvt_info;
unsigned long val;
int rc;
if (isdigit(*data)) {
rc = kstrtoul(data, 0, &val);
if (rc)
return rc;
ddr_out32(pdata->mc_vbase + FSL_MC_DATA_ERR_INJECT_HI, val);
return count;
}
return 0;
}
static ssize_t fsl_mc_inject_data_lo_store(struct device *dev,
struct device_attribute *mattr,
const char *data, size_t count)
{
struct mem_ctl_info *mci = to_mci(dev);
struct fsl_mc_pdata *pdata = mci->pvt_info;
unsigned long val;
int rc;
if (isdigit(*data)) {
rc = kstrtoul(data, 0, &val);
if (rc)
return rc;
ddr_out32(pdata->mc_vbase + FSL_MC_DATA_ERR_INJECT_LO, val);
return count;
}
return 0;
}
static ssize_t fsl_mc_inject_ctrl_store(struct device *dev,
struct device_attribute *mattr,
const char *data, size_t count)
{
struct mem_ctl_info *mci = to_mci(dev);
struct fsl_mc_pdata *pdata = mci->pvt_info;
unsigned long val;
int rc;
if (isdigit(*data)) {
rc = kstrtoul(data, 0, &val);
if (rc)
return rc;
ddr_out32(pdata->mc_vbase + FSL_MC_ECC_ERR_INJECT, val);
return count;
}
return 0;
}
static u8 calculate_ecc(u32 high, u32 low)
{
u32 mask_low;
u32 mask_high;
int bit_cnt;
u8 ecc = 0;
int i;
int j;
for (i = 0; i < 8; i++) {
mask_high = ecc_table[i * 2];
mask_low = ecc_table[i * 2 + 1];
bit_cnt = 0;
for (j = 0; j < 32; j++) {
if ((mask_high >> j) & 1)
bit_cnt ^= (high >> j) & 1;
if ((mask_low >> j) & 1)
bit_cnt ^= (low >> j) & 1;
}
ecc |= bit_cnt << i;
}
return ecc;
}
static u8 syndrome_from_bit(unsigned int bit) {
int i;
u8 syndrome = 0;
for (i = bit < 32; i < 16; i += 2)
syndrome |= ((ecc_table[i] >> (bit % 32)) & 1) << (i / 2);
return syndrome;
}
static void sbe_ecc_decode(u32 cap_high, u32 cap_low, u32 cap_ecc,
int *bad_data_bit, int *bad_ecc_bit)
{
int i;
u8 syndrome;
*bad_data_bit = -1;
*bad_ecc_bit = -1;
syndrome = calculate_ecc(cap_high, cap_low) ^ cap_ecc;
for (i = 0; i < 64; i++) {
if (syndrome == syndrome_from_bit(i)) {
*bad_data_bit = i;
return;
}
}
for (i = 0; i < 8; i++) {
if ((syndrome >> i) & 0x1) {
*bad_ecc_bit = i;
return;
}
}
}
static void fsl_mc_check(struct mem_ctl_info *mci)
{
struct fsl_mc_pdata *pdata = mci->pvt_info;
struct csrow_info *csrow;
u32 bus_width;
u32 err_detect;
u32 syndrome;
u64 err_addr;
u32 pfn;
int row_index;
u32 cap_high;
u32 cap_low;
int bad_data_bit;
int bad_ecc_bit;
err_detect = ddr_in32(pdata->mc_vbase + FSL_MC_ERR_DETECT);
if (!err_detect)
return;
fsl_mc_printk(mci, KERN_ERR, "Err Detect Register: %#8.8x\n",
err_detect);
if (!(err_detect & (DDR_EDE_SBE | DDR_EDE_MBE))) {
ddr_out32(pdata->mc_vbase + FSL_MC_ERR_DETECT, err_detect);
return;
}
syndrome = ddr_in32(pdata->mc_vbase + FSL_MC_CAPTURE_ECC);
bus_width = (ddr_in32(pdata->mc_vbase + FSL_MC_DDR_SDRAM_CFG) &
DSC_DBW_MASK) ? 32 : 64;
if (bus_width == 64)
syndrome &= 0xff;
else
syndrome &= 0xffff;
err_addr = make64(
ddr_in32(pdata->mc_vbase + FSL_MC_CAPTURE_EXT_ADDRESS),
ddr_in32(pdata->mc_vbase + FSL_MC_CAPTURE_ADDRESS));
pfn = err_addr >> PAGE_SHIFT;
for (row_index = 0; row_index < mci->nr_csrows; row_index++) {
csrow = mci->csrows[row_index];
if ((pfn >= csrow->first_page) && (pfn <= csrow->last_page))
break;
}
cap_high = ddr_in32(pdata->mc_vbase + FSL_MC_CAPTURE_DATA_HI);
cap_low = ddr_in32(pdata->mc_vbase + FSL_MC_CAPTURE_DATA_LO);
if ((err_detect & DDR_EDE_SBE) && (bus_width == 64)) {
sbe_ecc_decode(cap_high, cap_low, syndrome,
&bad_data_bit, &bad_ecc_bit);
if (bad_data_bit != -1)
fsl_mc_printk(mci, KERN_ERR,
"Faulty Data bit: %d\n", bad_data_bit);
if (bad_ecc_bit != -1)
fsl_mc_printk(mci, KERN_ERR,
"Faulty ECC bit: %d\n", bad_ecc_bit);
fsl_mc_printk(mci, KERN_ERR,
"Expected Data / ECC:\t%#8.8x_%08x / %#2.2x\n",
cap_high ^ (1 << (bad_data_bit - 32)),
cap_low ^ (1 << bad_data_bit),
syndrome ^ (1 << bad_ecc_bit));
}
fsl_mc_printk(mci, KERN_ERR,
"Captured Data / ECC:\t%#8.8x_%08x / %#2.2x\n",
cap_high, cap_low, syndrome);
fsl_mc_printk(mci, KERN_ERR, "Err addr: %#8.8llx\n", err_addr);
fsl_mc_printk(mci, KERN_ERR, "PFN: %#8.8x\n", pfn);
if (row_index == mci->nr_csrows)
fsl_mc_printk(mci, KERN_ERR, "PFN out of range!\n");
if (err_detect & DDR_EDE_SBE)
edac_mc_handle_error(HW_EVENT_ERR_CORRECTED, mci, 1,
pfn, err_addr & ~PAGE_MASK, syndrome,
row_index, 0, -1,
mci->ctl_name, "");
if (err_detect & DDR_EDE_MBE)
edac_mc_handle_error(HW_EVENT_ERR_UNCORRECTED, mci, 1,
pfn, err_addr & ~PAGE_MASK, syndrome,
row_index, 0, -1,
mci->ctl_name, "");
ddr_out32(pdata->mc_vbase + FSL_MC_ERR_DETECT, err_detect);
}
static irqreturn_t fsl_mc_isr(int irq, void *dev_id)
{
struct mem_ctl_info *mci = dev_id;
struct fsl_mc_pdata *pdata = mci->pvt_info;
u32 err_detect;
err_detect = ddr_in32(pdata->mc_vbase + FSL_MC_ERR_DETECT);
if (!err_detect)
return IRQ_NONE;
fsl_mc_check(mci);
return IRQ_HANDLED;
}
static void fsl_ddr_init_csrows(struct mem_ctl_info *mci)
{
struct fsl_mc_pdata *pdata = mci->pvt_info;
struct csrow_info *csrow;
struct dimm_info *dimm;
u32 sdram_ctl;
u32 sdtype;
enum mem_type mtype;
u32 cs_bnds;
int index;
sdram_ctl = ddr_in32(pdata->mc_vbase + FSL_MC_DDR_SDRAM_CFG);
sdtype = sdram_ctl & DSC_SDTYPE_MASK;
if (sdram_ctl & DSC_RD_EN) {
switch (sdtype) {
case 0x02000000:
mtype = MEM_RDDR;
break;
case 0x03000000:
mtype = MEM_RDDR2;
break;
case 0x07000000:
mtype = MEM_RDDR3;
break;
case 0x05000000:
mtype = MEM_RDDR4;
break;
default:
mtype = MEM_UNKNOWN;
break;
}
} else {
switch (sdtype) {
case 0x02000000:
mtype = MEM_DDR;
break;
case 0x03000000:
mtype = MEM_DDR2;
break;
case 0x07000000:
mtype = MEM_DDR3;
break;
case 0x05000000:
mtype = MEM_DDR4;
break;
default:
mtype = MEM_UNKNOWN;
break;
}
}
for (index = 0; index < mci->nr_csrows; index++) {
u32 start;
u32 end;
csrow = mci->csrows[index];
dimm = csrow->channels[0]->dimm;
cs_bnds = ddr_in32(pdata->mc_vbase + FSL_MC_CS_BNDS_0 +
(index * FSL_MC_CS_BNDS_OFS));
start = (cs_bnds & 0xffff0000) >> 16;
end = (cs_bnds & 0x0000ffff);
if (start == end)
continue;
start <<= (24 - PAGE_SHIFT);
end <<= (24 - PAGE_SHIFT);
end |= (1 << (24 - PAGE_SHIFT)) - 1;
csrow->first_page = start;
csrow->last_page = end;
dimm->nr_pages = end + 1 - start;
dimm->grain = 8;
dimm->mtype = mtype;
dimm->dtype = DEV_UNKNOWN;
if (sdram_ctl & DSC_X32_EN)
dimm->dtype = DEV_X32;
dimm->edac_mode = EDAC_SECDED;
}
}
int fsl_mc_err_probe(struct platform_device *op)
{
struct mem_ctl_info *mci;
struct edac_mc_layer layers[2];
struct fsl_mc_pdata *pdata;
struct resource r;
u32 sdram_ctl;
int res;
if (!devres_open_group(&op->dev, fsl_mc_err_probe, GFP_KERNEL))
return -ENOMEM;
layers[0].type = EDAC_MC_LAYER_CHIP_SELECT;
layers[0].size = 4;
layers[0].is_virt_csrow = true;
layers[1].type = EDAC_MC_LAYER_CHANNEL;
layers[1].size = 1;
layers[1].is_virt_csrow = false;
mci = edac_mc_alloc(edac_mc_idx, ARRAY_SIZE(layers), layers,
sizeof(*pdata));
if (!mci) {
devres_release_group(&op->dev, fsl_mc_err_probe);
return -ENOMEM;
}
pdata = mci->pvt_info;
pdata->name = "fsl_mc_err";
mci->pdev = &op->dev;
pdata->edac_idx = edac_mc_idx++;
dev_set_drvdata(mci->pdev, mci);
mci->ctl_name = pdata->name;
mci->dev_name = pdata->name;
little_endian = of_property_read_bool(op->dev.of_node, "little-endian");
res = of_address_to_resource(op->dev.of_node, 0, &r);
if (res) {
pr_err("%s: Unable to get resource for MC err regs\n",
__func__);
goto err;
}
if (!devm_request_mem_region(&op->dev, r.start, resource_size(&r),
pdata->name)) {
pr_err("%s: Error while requesting mem region\n",
__func__);
res = -EBUSY;
goto err;
}
pdata->mc_vbase = devm_ioremap(&op->dev, r.start, resource_size(&r));
if (!pdata->mc_vbase) {
pr_err("%s: Unable to setup MC err regs\n", __func__);
res = -ENOMEM;
goto err;
}
sdram_ctl = ddr_in32(pdata->mc_vbase + FSL_MC_DDR_SDRAM_CFG);
if (!(sdram_ctl & DSC_ECC_EN)) {
pr_warn("%s: No ECC DIMMs discovered\n", __func__);
res = -ENODEV;
goto err;
}
edac_dbg(3, "init mci\n");
mci->mtype_cap = MEM_FLAG_DDR | MEM_FLAG_RDDR |
MEM_FLAG_DDR2 | MEM_FLAG_RDDR2 |
MEM_FLAG_DDR3 | MEM_FLAG_RDDR3 |
MEM_FLAG_DDR4 | MEM_FLAG_RDDR4;
mci->edac_ctl_cap = EDAC_FLAG_NONE | EDAC_FLAG_SECDED;
mci->edac_cap = EDAC_FLAG_SECDED;
mci->mod_name = EDAC_MOD_STR;
if (edac_op_state == EDAC_OPSTATE_POLL)
mci->edac_check = fsl_mc_check;
mci->ctl_page_to_phys = NULL;
mci->scrub_mode = SCRUB_SW_SRC;
fsl_ddr_init_csrows(mci);
orig_ddr_err_disable = ddr_in32(pdata->mc_vbase + FSL_MC_ERR_DISABLE);
ddr_out32(pdata->mc_vbase + FSL_MC_ERR_DISABLE, 0);
ddr_out32(pdata->mc_vbase + FSL_MC_ERR_DETECT, ~0);
res = edac_mc_add_mc_with_groups(mci, fsl_ddr_dev_groups);
if (res) {
edac_dbg(3, "failed edac_mc_add_mc()\n");
goto err;
}
if (edac_op_state == EDAC_OPSTATE_INT) {
ddr_out32(pdata->mc_vbase + FSL_MC_ERR_INT_EN,
DDR_EIE_MBEE | DDR_EIE_SBEE);
orig_ddr_err_sbe = ddr_in32(pdata->mc_vbase +
FSL_MC_ERR_SBE) & 0xff0000;
ddr_out32(pdata->mc_vbase + FSL_MC_ERR_SBE, 0x10000);
pdata->irq = platform_get_irq(op, 0);
res = devm_request_irq(&op->dev, pdata->irq,
fsl_mc_isr,
IRQF_SHARED,
"[EDAC] MC err", mci);
if (res < 0) {
pr_err("%s: Unable to request irq %d for FSL DDR DRAM ERR\n",
__func__, pdata->irq);
res = -ENODEV;
goto err2;
}
pr_info(EDAC_MOD_STR " acquired irq %d for MC\n",
pdata->irq);
}
devres_remove_group(&op->dev, fsl_mc_err_probe);
edac_dbg(3, "success\n");
pr_info(EDAC_MOD_STR " MC err registered\n");
return 0;
err2:
edac_mc_del_mc(&op->dev);
err:
devres_release_group(&op->dev, fsl_mc_err_probe);
edac_mc_free(mci);
return res;
}
int fsl_mc_err_remove(struct platform_device *op)
{
struct mem_ctl_info *mci = dev_get_drvdata(&op->dev);
struct fsl_mc_pdata *pdata = mci->pvt_info;
edac_dbg(0, "\n");
if (edac_op_state == EDAC_OPSTATE_INT) {
ddr_out32(pdata->mc_vbase + FSL_MC_ERR_INT_EN, 0);
}
ddr_out32(pdata->mc_vbase + FSL_MC_ERR_DISABLE,
orig_ddr_err_disable);
ddr_out32(pdata->mc_vbase + FSL_MC_ERR_SBE, orig_ddr_err_sbe);
edac_mc_del_mc(&op->dev);
edac_mc_free(mci);
return 0;
}
