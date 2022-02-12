static void get_total_mem(struct cpc925_mc_pdata *pdata)
{
struct device_node *np = NULL;
const unsigned int *reg, *reg_end;
int len, sw, aw;
unsigned long start, size;
np = of_find_node_by_type(NULL, "memory");
if (!np)
return;
aw = of_n_addr_cells(np);
sw = of_n_size_cells(np);
reg = (const unsigned int *)of_get_property(np, "reg", &len);
reg_end = reg + len/4;
pdata->total_mem = 0;
do {
start = of_read_number(reg, aw);
reg += aw;
size = of_read_number(reg, sw);
reg += sw;
debugf1("%s: start 0x%lx, size 0x%lx\n", __func__,
start, size);
pdata->total_mem += size;
} while (reg < reg_end);
of_node_put(np);
debugf0("%s: total_mem 0x%lx\n", __func__, pdata->total_mem);
}
static void cpc925_init_csrows(struct mem_ctl_info *mci)
{
struct cpc925_mc_pdata *pdata = mci->pvt_info;
struct csrow_info *csrow;
struct dimm_info *dimm;
int index, j;
u32 mbmr, mbbar, bba;
unsigned long row_size, nr_pages, last_nr_pages = 0;
get_total_mem(pdata);
for (index = 0; index < mci->nr_csrows; index++) {
mbmr = __raw_readl(pdata->vbase + REG_MBMR_OFFSET +
0x20 * index);
mbbar = __raw_readl(pdata->vbase + REG_MBBAR_OFFSET +
0x20 + index);
bba = (((mbmr & MBMR_BBA_MASK) >> MBMR_BBA_SHIFT) << 8) |
((mbbar & MBBAR_BBA_MASK) >> MBBAR_BBA_SHIFT);
if (bba == 0)
continue;
csrow = &mci->csrows[index];
row_size = bba * (1UL << 28);
csrow->first_page = last_nr_pages;
nr_pages = row_size >> PAGE_SHIFT;
csrow->last_page = csrow->first_page + nr_pages - 1;
last_nr_pages = csrow->last_page + 1;
for (j = 0; j < csrow->nr_channels; j++) {
dimm = csrow->channels[j].dimm;
dimm->nr_pages = nr_pages / csrow->nr_channels;
dimm->mtype = MEM_RDDR;
dimm->edac_mode = EDAC_SECDED;
switch (csrow->nr_channels) {
case 1:
dimm->grain = 32;
break;
case 2:
default:
dimm->grain = 64;
break;
}
switch ((mbmr & MBMR_MODE_MASK) >> MBMR_MODE_SHIFT) {
case 6:
case 5:
case 8:
dimm->dtype = DEV_X16;
break;
case 7:
case 9:
dimm->dtype = DEV_X8;
break;
default:
dimm->dtype = DEV_UNKNOWN;
break;
}
}
}
}
static void cpc925_mc_init(struct mem_ctl_info *mci)
{
struct cpc925_mc_pdata *pdata = mci->pvt_info;
u32 apimask;
u32 mccr;
apimask = __raw_readl(pdata->vbase + REG_APIMASK_OFFSET);
if ((apimask & ECC_MASK_ENABLE) == 0) {
apimask |= ECC_MASK_ENABLE;
__raw_writel(apimask, pdata->vbase + REG_APIMASK_OFFSET);
}
mccr = __raw_readl(pdata->vbase + REG_MCCR_OFFSET);
if ((mccr & MCCR_ECC_EN) == 0) {
mccr |= MCCR_ECC_EN;
__raw_writel(mccr, pdata->vbase + REG_MCCR_OFFSET);
}
}
static void cpc925_mc_exit(struct mem_ctl_info *mci)
{
return;
}
static void cpc925_mc_get_pfn(struct mem_ctl_info *mci, u32 mear,
unsigned long *pfn, unsigned long *offset, int *csrow)
{
u32 bcnt, rank, col, bank, row;
u32 c;
unsigned long pa;
int i;
bcnt = (mear & MEAR_BCNT_MASK) >> MEAR_BCNT_SHIFT;
rank = (mear & MEAR_RANK_MASK) >> MEAR_RANK_SHIFT;
col = (mear & MEAR_COL_MASK) >> MEAR_COL_SHIFT;
bank = (mear & MEAR_BANK_MASK) >> MEAR_BANK_SHIFT;
row = mear & MEAR_ROW_MASK;
*csrow = rank;
#ifdef CONFIG_EDAC_DEBUG
if (mci->csrows[rank].first_page == 0) {
cpc925_mc_printk(mci, KERN_ERR, "ECC occurs in a "
"non-populated csrow, broken hardware?\n");
return;
}
#endif
pa = mci->csrows[rank].first_page << PAGE_SHIFT;
col += bcnt;
for (i = 0; i < 11; i++) {
c = col & 0x1;
col >>= 1;
pa |= c << (14 - i);
}
pa |= bank << 19;
for (i = 0; i < 3; i++) {
c = row & 0x1;
row >>= 1;
pa |= c << (26 - i);
}
for (i = 0; i < 3; i++) {
c = row & 0x1;
row >>= 1;
pa |= c << (21 + i);
}
for (i = 0; i < 4; i++) {
c = row & 0x1;
row >>= 1;
pa |= c << (18 - i);
}
for (i = 0; i < 3; i++) {
c = row & 0x1;
row >>= 1;
pa |= c << (29 - i);
}
*offset = pa & (PAGE_SIZE - 1);
*pfn = pa >> PAGE_SHIFT;
debugf0("%s: ECC physical address 0x%lx\n", __func__, pa);
}
static int cpc925_mc_find_channel(struct mem_ctl_info *mci, u16 syndrome)
{
if ((syndrome & MESR_ECC_SYN_H_MASK) == 0)
return 0;
if ((syndrome & MESR_ECC_SYN_L_MASK) == 0)
return 1;
cpc925_mc_printk(mci, KERN_INFO, "Unexpected syndrome value: 0x%x\n",
syndrome);
return 1;
}
static void cpc925_mc_check(struct mem_ctl_info *mci)
{
struct cpc925_mc_pdata *pdata = mci->pvt_info;
u32 apiexcp;
u32 mear;
u32 mesr;
u16 syndrome;
unsigned long pfn = 0, offset = 0;
int csrow = 0, channel = 0;
apiexcp = __raw_readl(pdata->vbase + REG_APIEXCP_OFFSET);
if ((apiexcp & ECC_EXCP_DETECTED) == 0)
return;
mesr = __raw_readl(pdata->vbase + REG_MESR_OFFSET);
syndrome = mesr | (MESR_ECC_SYN_H_MASK | MESR_ECC_SYN_L_MASK);
mear = __raw_readl(pdata->vbase + REG_MEAR_OFFSET);
cpc925_mc_get_pfn(mci, mear, &pfn, &offset, &csrow);
if (apiexcp & CECC_EXCP_DETECTED) {
cpc925_mc_printk(mci, KERN_INFO, "DRAM CECC Fault\n");
channel = cpc925_mc_find_channel(mci, syndrome);
edac_mc_handle_error(HW_EVENT_ERR_CORRECTED, mci,
pfn, offset, syndrome,
csrow, channel, -1,
mci->ctl_name, "", NULL);
}
if (apiexcp & UECC_EXCP_DETECTED) {
cpc925_mc_printk(mci, KERN_INFO, "DRAM UECC Fault\n");
edac_mc_handle_error(HW_EVENT_ERR_CORRECTED, mci,
pfn, offset, 0,
csrow, -1, -1,
mci->ctl_name, "", NULL);
}
cpc925_mc_printk(mci, KERN_INFO, "Dump registers:\n");
cpc925_mc_printk(mci, KERN_INFO, "APIMASK 0x%08x\n",
__raw_readl(pdata->vbase + REG_APIMASK_OFFSET));
cpc925_mc_printk(mci, KERN_INFO, "APIEXCP 0x%08x\n",
apiexcp);
cpc925_mc_printk(mci, KERN_INFO, "Mem Scrub Ctrl 0x%08x\n",
__raw_readl(pdata->vbase + REG_MSCR_OFFSET));
cpc925_mc_printk(mci, KERN_INFO, "Mem Scrub Rge Start 0x%08x\n",
__raw_readl(pdata->vbase + REG_MSRSR_OFFSET));
cpc925_mc_printk(mci, KERN_INFO, "Mem Scrub Rge End 0x%08x\n",
__raw_readl(pdata->vbase + REG_MSRER_OFFSET));
cpc925_mc_printk(mci, KERN_INFO, "Mem Scrub Pattern 0x%08x\n",
__raw_readl(pdata->vbase + REG_MSPR_OFFSET));
cpc925_mc_printk(mci, KERN_INFO, "Mem Chk Ctrl 0x%08x\n",
__raw_readl(pdata->vbase + REG_MCCR_OFFSET));
cpc925_mc_printk(mci, KERN_INFO, "Mem Chk Rge End 0x%08x\n",
__raw_readl(pdata->vbase + REG_MCRER_OFFSET));
cpc925_mc_printk(mci, KERN_INFO, "Mem Err Address 0x%08x\n",
mesr);
cpc925_mc_printk(mci, KERN_INFO, "Mem Err Syndrome 0x%08x\n",
syndrome);
}
static u32 cpc925_cpu_mask_disabled(void)
{
struct device_node *cpus;
struct device_node *cpunode = NULL;
static u32 mask = 0;
if (mask != 0)
return mask;
mask = APIMASK_ADI0 | APIMASK_ADI1;
cpus = of_find_node_by_path("/cpus");
if (cpus == NULL) {
cpc925_printk(KERN_DEBUG, "No /cpus node !\n");
return 0;
}
while ((cpunode = of_get_next_child(cpus, cpunode)) != NULL) {
const u32 *reg = of_get_property(cpunode, "reg", NULL);
if (strcmp(cpunode->type, "cpu")) {
cpc925_printk(KERN_ERR, "Not a cpu node in /cpus: %s\n", cpunode->name);
continue;
}
if (reg == NULL || *reg > 2) {
cpc925_printk(KERN_ERR, "Bad reg value at %s\n", cpunode->full_name);
continue;
}
mask &= ~APIMASK_ADI(*reg);
}
if (mask != (APIMASK_ADI0 | APIMASK_ADI1)) {
cpc925_printk(KERN_WARNING,
"Assuming PI id is equal to CPU MPIC id!\n");
}
of_node_put(cpunode);
of_node_put(cpus);
return mask;
}
static void cpc925_cpu_init(struct cpc925_dev_info *dev_info)
{
u32 apimask;
u32 cpumask;
apimask = __raw_readl(dev_info->vbase + REG_APIMASK_OFFSET);
cpumask = cpc925_cpu_mask_disabled();
if (apimask & cpumask) {
cpc925_printk(KERN_WARNING, "CPU(s) not present, "
"but enabled in APIMASK, disabling\n");
apimask &= ~cpumask;
}
if ((apimask & CPU_MASK_ENABLE) == 0)
apimask |= CPU_MASK_ENABLE;
__raw_writel(apimask, dev_info->vbase + REG_APIMASK_OFFSET);
}
static void cpc925_cpu_exit(struct cpc925_dev_info *dev_info)
{
return;
}
static void cpc925_cpu_check(struct edac_device_ctl_info *edac_dev)
{
struct cpc925_dev_info *dev_info = edac_dev->pvt_info;
u32 apiexcp;
u32 apimask;
apiexcp = __raw_readl(dev_info->vbase + REG_APIEXCP_OFFSET);
if ((apiexcp & CPU_EXCP_DETECTED) == 0)
return;
if ((apiexcp & ~cpc925_cpu_mask_disabled()) == 0)
return;
apimask = __raw_readl(dev_info->vbase + REG_APIMASK_OFFSET);
cpc925_printk(KERN_INFO, "Processor Interface Fault\n"
"Processor Interface register dump:\n");
cpc925_printk(KERN_INFO, "APIMASK 0x%08x\n", apimask);
cpc925_printk(KERN_INFO, "APIEXCP 0x%08x\n", apiexcp);
edac_device_handle_ue(edac_dev, 0, 0, edac_dev->ctl_name);
}
static void cpc925_htlink_init(struct cpc925_dev_info *dev_info)
{
u32 ht_errctrl;
ht_errctrl = __raw_readl(dev_info->vbase + REG_ERRCTRL_OFFSET);
if ((ht_errctrl & HT_ERRCTRL_ENABLE) == 0) {
ht_errctrl |= HT_ERRCTRL_ENABLE;
__raw_writel(ht_errctrl, dev_info->vbase + REG_ERRCTRL_OFFSET);
}
}
static void cpc925_htlink_exit(struct cpc925_dev_info *dev_info)
{
u32 ht_errctrl;
ht_errctrl = __raw_readl(dev_info->vbase + REG_ERRCTRL_OFFSET);
ht_errctrl &= ~HT_ERRCTRL_ENABLE;
__raw_writel(ht_errctrl, dev_info->vbase + REG_ERRCTRL_OFFSET);
}
static void cpc925_htlink_check(struct edac_device_ctl_info *edac_dev)
{
struct cpc925_dev_info *dev_info = edac_dev->pvt_info;
u32 brgctrl = __raw_readl(dev_info->vbase + REG_BRGCTRL_OFFSET);
u32 linkctrl = __raw_readl(dev_info->vbase + REG_LINKCTRL_OFFSET);
u32 errctrl = __raw_readl(dev_info->vbase + REG_ERRCTRL_OFFSET);
u32 linkerr = __raw_readl(dev_info->vbase + REG_LINKERR_OFFSET);
if (!((brgctrl & BRGCTRL_DETSERR) ||
(linkctrl & HT_LINKCTRL_DETECTED) ||
(errctrl & HT_ERRCTRL_DETECTED) ||
(linkerr & HT_LINKERR_DETECTED)))
return;
cpc925_printk(KERN_INFO, "HT Link Fault\n"
"HT register dump:\n");
cpc925_printk(KERN_INFO, "Bridge Ctrl 0x%08x\n",
brgctrl);
cpc925_printk(KERN_INFO, "Link Config Ctrl 0x%08x\n",
linkctrl);
cpc925_printk(KERN_INFO, "Error Enum and Ctrl 0x%08x\n",
errctrl);
cpc925_printk(KERN_INFO, "Link Error 0x%08x\n",
linkerr);
if (brgctrl & BRGCTRL_DETSERR)
__raw_writel(BRGCTRL_DETSERR,
dev_info->vbase + REG_BRGCTRL_OFFSET);
if (linkctrl & HT_LINKCTRL_DETECTED)
__raw_writel(HT_LINKCTRL_DETECTED,
dev_info->vbase + REG_LINKCTRL_OFFSET);
if (errctrl & ERRCTRL_CHN_FAL)
__raw_writel(BRGCTRL_SECBUSRESET,
dev_info->vbase + REG_BRGCTRL_OFFSET);
if (errctrl & ERRCTRL_RSP_ERR)
__raw_writel(ERRCTRL_RSP_ERR,
dev_info->vbase + REG_ERRCTRL_OFFSET);
if (linkerr & HT_LINKERR_DETECTED)
__raw_writel(HT_LINKERR_DETECTED,
dev_info->vbase + REG_LINKERR_OFFSET);
edac_device_handle_ce(edac_dev, 0, 0, edac_dev->ctl_name);
}
static void cpc925_add_edac_devices(void __iomem *vbase)
{
struct cpc925_dev_info *dev_info;
if (!vbase) {
cpc925_printk(KERN_ERR, "MMIO not established yet\n");
return;
}
for (dev_info = &cpc925_devs[0]; dev_info->init; dev_info++) {
dev_info->vbase = vbase;
dev_info->pdev = platform_device_register_simple(
dev_info->ctl_name, 0, NULL, 0);
if (IS_ERR(dev_info->pdev)) {
cpc925_printk(KERN_ERR,
"Can't register platform device for %s\n",
dev_info->ctl_name);
continue;
}
dev_info->edac_idx = edac_device_alloc_index();
dev_info->edac_dev =
edac_device_alloc_ctl_info(0, dev_info->ctl_name,
1, NULL, 0, 0, NULL, 0, dev_info->edac_idx);
if (!dev_info->edac_dev) {
cpc925_printk(KERN_ERR, "No memory for edac device\n");
goto err1;
}
dev_info->edac_dev->pvt_info = dev_info;
dev_info->edac_dev->dev = &dev_info->pdev->dev;
dev_info->edac_dev->ctl_name = dev_info->ctl_name;
dev_info->edac_dev->mod_name = CPC925_EDAC_MOD_STR;
dev_info->edac_dev->dev_name = dev_name(&dev_info->pdev->dev);
if (edac_op_state == EDAC_OPSTATE_POLL)
dev_info->edac_dev->edac_check = dev_info->check;
if (dev_info->init)
dev_info->init(dev_info);
if (edac_device_add_device(dev_info->edac_dev) > 0) {
cpc925_printk(KERN_ERR,
"Unable to add edac device for %s\n",
dev_info->ctl_name);
goto err2;
}
debugf0("%s: Successfully added edac device for %s\n",
__func__, dev_info->ctl_name);
continue;
err2:
if (dev_info->exit)
dev_info->exit(dev_info);
edac_device_free_ctl_info(dev_info->edac_dev);
err1:
platform_device_unregister(dev_info->pdev);
}
}
static void cpc925_del_edac_devices(void)
{
struct cpc925_dev_info *dev_info;
for (dev_info = &cpc925_devs[0]; dev_info->init; dev_info++) {
if (dev_info->edac_dev) {
edac_device_del_device(dev_info->edac_dev->dev);
edac_device_free_ctl_info(dev_info->edac_dev);
platform_device_unregister(dev_info->pdev);
}
if (dev_info->exit)
dev_info->exit(dev_info);
debugf0("%s: Successfully deleted edac device for %s\n",
__func__, dev_info->ctl_name);
}
}
static int cpc925_get_sdram_scrub_rate(struct mem_ctl_info *mci)
{
struct cpc925_mc_pdata *pdata = mci->pvt_info;
int bw;
u32 mscr;
u8 si;
mscr = __raw_readl(pdata->vbase + REG_MSCR_OFFSET);
si = (mscr & MSCR_SI_MASK) >> MSCR_SI_SHIFT;
debugf0("%s, Mem Scrub Ctrl Register 0x%x\n", __func__, mscr);
if (((mscr & MSCR_SCRUB_MOD_MASK) != MSCR_BACKGR_SCRUB) ||
(si == 0)) {
cpc925_mc_printk(mci, KERN_INFO, "Scrub mode not enabled\n");
bw = 0;
} else
bw = CPC925_SCRUB_BLOCK_SIZE * 0xFA67 / si;
return bw;
}
static int cpc925_mc_get_channels(void __iomem *vbase)
{
int dual = 0;
u32 mbcr;
mbcr = __raw_readl(vbase + REG_MBCR_OFFSET);
if (((mbcr & MBCR_64BITCFG_MASK) == 0) &&
((mbcr & MBCR_64BITBUS_MASK) == 0))
dual = 1;
debugf0("%s: %s channel\n", __func__,
(dual > 0) ? "Dual" : "Single");
return dual;
}
static int __devinit cpc925_probe(struct platform_device *pdev)
{
static int edac_mc_idx;
struct mem_ctl_info *mci;
struct edac_mc_layer layers[2];
void __iomem *vbase;
struct cpc925_mc_pdata *pdata;
struct resource *r;
int res = 0, nr_channels;
debugf0("%s: %s platform device found!\n", __func__, pdev->name);
if (!devres_open_group(&pdev->dev, cpc925_probe, GFP_KERNEL)) {
res = -ENOMEM;
goto out;
}
r = platform_get_resource(pdev, IORESOURCE_MEM, 0);
if (!r) {
cpc925_printk(KERN_ERR, "Unable to get resource\n");
res = -ENOENT;
goto err1;
}
if (!devm_request_mem_region(&pdev->dev,
r->start,
resource_size(r),
pdev->name)) {
cpc925_printk(KERN_ERR, "Unable to request mem region\n");
res = -EBUSY;
goto err1;
}
vbase = devm_ioremap(&pdev->dev, r->start, resource_size(r));
if (!vbase) {
cpc925_printk(KERN_ERR, "Unable to ioremap device\n");
res = -ENOMEM;
goto err2;
}
nr_channels = cpc925_mc_get_channels(vbase) + 1;
layers[0].type = EDAC_MC_LAYER_CHIP_SELECT;
layers[0].size = CPC925_NR_CSROWS;
layers[0].is_virt_csrow = true;
layers[1].type = EDAC_MC_LAYER_CHANNEL;
layers[1].size = nr_channels;
layers[1].is_virt_csrow = false;
mci = edac_mc_alloc(edac_mc_idx, ARRAY_SIZE(layers), layers,
sizeof(struct cpc925_mc_pdata));
if (!mci) {
cpc925_printk(KERN_ERR, "No memory for mem_ctl_info\n");
res = -ENOMEM;
goto err2;
}
pdata = mci->pvt_info;
pdata->vbase = vbase;
pdata->edac_idx = edac_mc_idx++;
pdata->name = pdev->name;
mci->dev = &pdev->dev;
platform_set_drvdata(pdev, mci);
mci->dev_name = dev_name(&pdev->dev);
mci->mtype_cap = MEM_FLAG_RDDR | MEM_FLAG_DDR;
mci->edac_ctl_cap = EDAC_FLAG_NONE | EDAC_FLAG_SECDED;
mci->edac_cap = EDAC_FLAG_SECDED;
mci->mod_name = CPC925_EDAC_MOD_STR;
mci->mod_ver = CPC925_EDAC_REVISION;
mci->ctl_name = pdev->name;
if (edac_op_state == EDAC_OPSTATE_POLL)
mci->edac_check = cpc925_mc_check;
mci->ctl_page_to_phys = NULL;
mci->scrub_mode = SCRUB_SW_SRC;
mci->set_sdram_scrub_rate = NULL;
mci->get_sdram_scrub_rate = cpc925_get_sdram_scrub_rate;
cpc925_init_csrows(mci);
cpc925_mc_init(mci);
if (edac_mc_add_mc(mci) > 0) {
cpc925_mc_printk(mci, KERN_ERR, "Failed edac_mc_add_mc()\n");
goto err3;
}
cpc925_add_edac_devices(vbase);
debugf0("%s: success\n", __func__);
res = 0;
goto out;
err3:
cpc925_mc_exit(mci);
edac_mc_free(mci);
err2:
devm_release_mem_region(&pdev->dev, r->start, resource_size(r));
err1:
devres_release_group(&pdev->dev, cpc925_probe);
out:
return res;
}
static int cpc925_remove(struct platform_device *pdev)
{
struct mem_ctl_info *mci = platform_get_drvdata(pdev);
cpc925_del_edac_devices();
cpc925_mc_exit(mci);
edac_mc_del_mc(&pdev->dev);
edac_mc_free(mci);
return 0;
}
static int __init cpc925_edac_init(void)
{
int ret = 0;
printk(KERN_INFO "IBM CPC925 EDAC driver " CPC925_EDAC_REVISION "\n");
printk(KERN_INFO "\t(c) 2008 Wind River Systems, Inc\n");
edac_op_state = EDAC_OPSTATE_POLL;
ret = platform_driver_register(&cpc925_edac_driver);
if (ret) {
printk(KERN_WARNING "Failed to register %s\n",
CPC925_EDAC_MOD_STR);
}
return ret;
}
static void __exit cpc925_edac_exit(void)
{
platform_driver_unregister(&cpc925_edac_driver);
}
