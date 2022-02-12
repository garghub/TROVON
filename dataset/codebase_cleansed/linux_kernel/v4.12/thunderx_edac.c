static void decode_register(char *str, size_t size,
const struct error_descr *descr,
const uint64_t reg)
{
int ret = 0;
while (descr->type && descr->mask && descr->descr) {
if (reg & descr->mask) {
ret = snprintf(str, size, "\n\t%s, %s",
descr->type == ERR_CORRECTED ?
"Corrected" : "Uncorrected",
descr->descr);
str += ret;
size -= ret;
}
descr++;
}
}
static unsigned long get_bits(unsigned long data, int pos, int width)
{
return (data >> pos) & ((1 << width) - 1);
}
static ssize_t thunderx_lmc_inject_int_write(struct file *file,
const char __user *data,
size_t count, loff_t *ppos)
{
struct thunderx_lmc *lmc = file->private_data;
u64 val;
int res;
res = kstrtoull_from_user(data, count, 0, &val);
if (!res) {
writeq(val, lmc->regs + LMC_INT_W1S);
res = count;
}
return res;
}
static ssize_t thunderx_lmc_int_read(struct file *file,
char __user *data,
size_t count, loff_t *ppos)
{
struct thunderx_lmc *lmc = file->private_data;
char buf[20];
u64 lmc_int = readq(lmc->regs + LMC_INT);
snprintf(buf, sizeof(buf), "0x%016llx", lmc_int);
return simple_read_from_buffer(data, count, ppos, buf, sizeof(buf));
}
static int inject_ecc_fn(void *arg)
{
struct thunderx_lmc *lmc = arg;
uintptr_t addr, phys;
unsigned int cline_size = cache_line_size();
const unsigned int lines = PAGE_SIZE / cline_size;
unsigned int i, cl_idx;
addr = (uintptr_t)page_address(lmc->mem);
phys = (uintptr_t)page_to_phys(lmc->mem);
cl_idx = (phys & 0x7f) >> 4;
lmc->parity_test &= ~(7ULL << 8);
lmc->parity_test |= (cl_idx << 8);
writeq(lmc->mask0, lmc->regs + LMC_CHAR_MASK0);
writeq(lmc->mask2, lmc->regs + LMC_CHAR_MASK2);
writeq(lmc->parity_test, lmc->regs + LMC_ECC_PARITY_TEST);
readq(lmc->regs + LMC_CHAR_MASK0);
readq(lmc->regs + LMC_CHAR_MASK2);
readq(lmc->regs + LMC_ECC_PARITY_TEST);
for (i = 0; i < lines; i++) {
memset((void *)addr, TEST_PATTERN, cline_size);
barrier();
asm volatile("dc civac, %0\n"
"dsb sy\n"
: : "r"(addr + i * cline_size));
}
for (i = 0; i < lines; i++) {
__asm__ volatile("sys #0,c11,C1,#2, %0\n"
: : "r"(phys + i * cline_size));
}
for (i = 0; i < lines; i++) {
__asm__ volatile("sys #0,c11,C1,#1, %0"
: : "r"(phys + i * cline_size));
}
for (i = 0; i < lines; i++) {
asm volatile("dc ivac, %0\n"
"dsb sy\n"
: : "r"(addr + i * cline_size));
}
return 0;
}
static ssize_t thunderx_lmc_inject_ecc_write(struct file *file,
const char __user *data,
size_t count, loff_t *ppos)
{
struct thunderx_lmc *lmc = file->private_data;
unsigned int cline_size = cache_line_size();
u8 tmp[cline_size];
void __iomem *addr;
unsigned int offs, timeout = 100000;
atomic_set(&lmc->ecc_int, 0);
lmc->mem = alloc_pages_node(lmc->node, GFP_KERNEL, 0);
if (!lmc->mem)
return -ENOMEM;
addr = page_address(lmc->mem);
while (!atomic_read(&lmc->ecc_int) && timeout--) {
stop_machine(inject_ecc_fn, lmc, NULL);
for (offs = 0; offs < PAGE_SIZE; offs += sizeof(tmp)) {
memcpy(tmp, addr + offs, cline_size);
asm volatile("dsb ld\n");
}
}
__free_pages(lmc->mem, 0);
return count;
}
static int thunderx_create_debugfs_nodes(struct dentry *parent,
struct debugfs_entry *attrs[],
void *data,
size_t num)
{
int i;
struct dentry *ent;
if (!IS_ENABLED(CONFIG_EDAC_DEBUG))
return 0;
if (!parent)
return -ENOENT;
for (i = 0; i < num; i++) {
ent = edac_debugfs_create_file(attrs[i]->name, attrs[i]->mode,
parent, data, &attrs[i]->fops);
if (!ent)
break;
}
return i;
}
static phys_addr_t thunderx_faddr_to_phys(u64 faddr, struct thunderx_lmc *lmc)
{
phys_addr_t addr = 0;
int bank, xbits;
addr |= lmc->node << 40;
addr |= LMC_FADR_FDIMM(faddr) << lmc->dimm_lsb;
addr |= LMC_FADR_FBUNK(faddr) << lmc->rank_lsb;
addr |= LMC_FADR_FROW(faddr) << lmc->row_lsb;
addr |= (LMC_FADR_FCOL(faddr) >> 4) << lmc->col_hi_lsb;
bank = LMC_FADR_FBANK(faddr) << lmc->bank_lsb;
if (lmc->xor_bank)
bank ^= get_bits(addr, 12 + lmc->xbits, lmc->bank_width);
addr |= bank << lmc->bank_lsb;
xbits = PCI_FUNC(lmc->pdev->devfn);
if (lmc->l2c_alias)
xbits ^= get_bits(addr, 20, lmc->xbits) ^
get_bits(addr, 12, lmc->xbits);
addr |= xbits << 7;
return addr;
}
static unsigned int thunderx_get_num_lmcs(unsigned int node)
{
unsigned int number = 0;
struct pci_dev *pdev = NULL;
do {
pdev = pci_get_device(PCI_VENDOR_ID_CAVIUM,
PCI_DEVICE_ID_THUNDER_LMC,
pdev);
if (pdev) {
#ifdef CONFIG_NUMA
if (pdev->dev.numa_node == node)
number++;
#else
number++;
#endif
}
} while (pdev);
return number;
}
static irqreturn_t thunderx_lmc_err_isr(int irq, void *dev_id)
{
struct mem_ctl_info *mci = dev_id;
struct thunderx_lmc *lmc = mci->pvt_info;
unsigned long head = ring_pos(lmc->ring_head, ARRAY_SIZE(lmc->err_ctx));
struct lmc_err_ctx *ctx = &lmc->err_ctx[head];
writeq(0, lmc->regs + LMC_CHAR_MASK0);
writeq(0, lmc->regs + LMC_CHAR_MASK2);
writeq(0x2, lmc->regs + LMC_ECC_PARITY_TEST);
ctx->reg_int = readq(lmc->regs + LMC_INT);
ctx->reg_fadr = readq(lmc->regs + LMC_FADR);
ctx->reg_nxm_fadr = readq(lmc->regs + LMC_NXM_FADR);
ctx->reg_scram_fadr = readq(lmc->regs + LMC_SCRAM_FADR);
ctx->reg_ecc_synd = readq(lmc->regs + LMC_ECC_SYND);
lmc->ring_head++;
atomic_set(&lmc->ecc_int, 1);
writeq(ctx->reg_int, lmc->regs + LMC_INT);
return IRQ_WAKE_THREAD;
}
static irqreturn_t thunderx_lmc_threaded_isr(int irq, void *dev_id)
{
struct mem_ctl_info *mci = dev_id;
struct thunderx_lmc *lmc = mci->pvt_info;
phys_addr_t phys_addr;
unsigned long tail;
struct lmc_err_ctx *ctx;
irqreturn_t ret = IRQ_NONE;
char *msg;
char *other;
msg = kmalloc(LMC_MESSAGE_SIZE, GFP_KERNEL);
other = kmalloc(LMC_OTHER_SIZE, GFP_KERNEL);
if (!msg || !other)
goto err_free;
while (CIRC_CNT(lmc->ring_head, lmc->ring_tail,
ARRAY_SIZE(lmc->err_ctx))) {
tail = ring_pos(lmc->ring_tail, ARRAY_SIZE(lmc->err_ctx));
ctx = &lmc->err_ctx[tail];
dev_dbg(&lmc->pdev->dev, "LMC_INT: %016llx\n",
ctx->reg_int);
dev_dbg(&lmc->pdev->dev, "LMC_FADR: %016llx\n",
ctx->reg_fadr);
dev_dbg(&lmc->pdev->dev, "LMC_NXM_FADR: %016llx\n",
ctx->reg_nxm_fadr);
dev_dbg(&lmc->pdev->dev, "LMC_SCRAM_FADR: %016llx\n",
ctx->reg_scram_fadr);
dev_dbg(&lmc->pdev->dev, "LMC_ECC_SYND: %016llx\n",
ctx->reg_ecc_synd);
snprintf(msg, LMC_MESSAGE_SIZE,
"DIMM %lld rank %lld bank %lld row %lld col %lld",
LMC_FADR_FDIMM(ctx->reg_scram_fadr),
LMC_FADR_FBUNK(ctx->reg_scram_fadr),
LMC_FADR_FBANK(ctx->reg_scram_fadr),
LMC_FADR_FROW(ctx->reg_scram_fadr),
LMC_FADR_FCOL(ctx->reg_scram_fadr));
decode_register(other, LMC_OTHER_SIZE, lmc_errors,
ctx->reg_int);
phys_addr = thunderx_faddr_to_phys(ctx->reg_fadr, lmc);
if (ctx->reg_int & LMC_INT_UE)
edac_mc_handle_error(HW_EVENT_ERR_UNCORRECTED, mci, 1,
phys_to_pfn(phys_addr),
offset_in_page(phys_addr),
0, -1, -1, -1, msg, other);
else if (ctx->reg_int & LMC_INT_CE)
edac_mc_handle_error(HW_EVENT_ERR_CORRECTED, mci, 1,
phys_to_pfn(phys_addr),
offset_in_page(phys_addr),
0, -1, -1, -1, msg, other);
lmc->ring_tail++;
}
ret = IRQ_HANDLED;
err_free:
kfree(msg);
kfree(other);
return ret;
}
static int thunderx_lmc_suspend(struct pci_dev *pdev, pm_message_t state)
{
pci_save_state(pdev);
pci_disable_device(pdev);
pci_set_power_state(pdev, pci_choose_state(pdev, state));
return 0;
}
static int thunderx_lmc_resume(struct pci_dev *pdev)
{
pci_set_power_state(pdev, PCI_D0);
pci_enable_wake(pdev, PCI_D0, 0);
pci_restore_state(pdev);
return 0;
}
static inline int pci_dev_to_mc_idx(struct pci_dev *pdev)
{
int node = dev_to_node(&pdev->dev);
int ret = PCI_FUNC(pdev->devfn);
ret += max(node, 0) << 3;
return ret;
}
static int thunderx_lmc_probe(struct pci_dev *pdev,
const struct pci_device_id *id)
{
struct thunderx_lmc *lmc;
struct edac_mc_layer layer;
struct mem_ctl_info *mci;
u64 lmc_control, lmc_ddr_pll_ctl, lmc_config;
int ret;
u64 lmc_int;
void *l2c_ioaddr;
layer.type = EDAC_MC_LAYER_SLOT;
layer.size = 2;
layer.is_virt_csrow = false;
ret = pcim_enable_device(pdev);
if (ret) {
dev_err(&pdev->dev, "Cannot enable PCI device: %d\n", ret);
return ret;
}
ret = pcim_iomap_regions(pdev, BIT(0), "thunderx_lmc");
if (ret) {
dev_err(&pdev->dev, "Cannot map PCI resources: %d\n", ret);
return ret;
}
mci = edac_mc_alloc(pci_dev_to_mc_idx(pdev), 1, &layer,
sizeof(struct thunderx_lmc));
if (!mci)
return -ENOMEM;
mci->pdev = &pdev->dev;
lmc = mci->pvt_info;
pci_set_drvdata(pdev, mci);
lmc->regs = pcim_iomap_table(pdev)[0];
lmc_control = readq(lmc->regs + LMC_CONTROL);
lmc_ddr_pll_ctl = readq(lmc->regs + LMC_DDR_PLL_CTL);
lmc_config = readq(lmc->regs + LMC_CONFIG);
if (lmc_control & LMC_CONTROL_RDIMM) {
mci->mtype_cap = FIELD_GET(LMC_DDR_PLL_CTL_DDR4,
lmc_ddr_pll_ctl) ?
MEM_RDDR4 : MEM_RDDR3;
} else {
mci->mtype_cap = FIELD_GET(LMC_DDR_PLL_CTL_DDR4,
lmc_ddr_pll_ctl) ?
MEM_DDR4 : MEM_DDR3;
}
mci->edac_ctl_cap = EDAC_FLAG_NONE | EDAC_FLAG_SECDED;
mci->edac_cap = EDAC_FLAG_SECDED;
mci->mod_name = "thunderx-lmc";
mci->mod_ver = "1";
mci->ctl_name = "thunderx-lmc";
mci->dev_name = dev_name(&pdev->dev);
mci->scrub_mode = SCRUB_NONE;
lmc->pdev = pdev;
lmc->msix_ent.entry = 0;
lmc->ring_head = 0;
lmc->ring_tail = 0;
ret = pci_enable_msix_exact(pdev, &lmc->msix_ent, 1);
if (ret) {
dev_err(&pdev->dev, "Cannot enable interrupt: %d\n", ret);
goto err_free;
}
ret = devm_request_threaded_irq(&pdev->dev, lmc->msix_ent.vector,
thunderx_lmc_err_isr,
thunderx_lmc_threaded_isr, 0,
"[EDAC] ThunderX LMC", mci);
if (ret) {
dev_err(&pdev->dev, "Cannot set ISR: %d\n", ret);
goto err_free;
}
lmc->node = FIELD_GET(THUNDERX_NODE, pci_resource_start(pdev, 0));
lmc->xbits = thunderx_get_num_lmcs(lmc->node) >> 1;
lmc->bank_width = (FIELD_GET(LMC_DDR_PLL_CTL_DDR4, lmc_ddr_pll_ctl) &&
FIELD_GET(LMC_CONFIG_BG2, lmc_config)) ? 4 : 3;
lmc->pbank_lsb = (lmc_config >> 5) & 0xf;
lmc->dimm_lsb = 28 + lmc->pbank_lsb + lmc->xbits;
lmc->rank_lsb = lmc->dimm_lsb;
lmc->rank_lsb -= FIELD_GET(LMC_CONFIG_RANK_ENA, lmc_config) ? 1 : 0;
lmc->bank_lsb = 7 + lmc->xbits;
lmc->row_lsb = 14 + LMC_CONFIG_ROW_LSB(lmc_config) + lmc->xbits;
lmc->col_hi_lsb = lmc->bank_lsb + lmc->bank_width;
lmc->xor_bank = lmc_control & LMC_CONTROL_XOR_BANK;
l2c_ioaddr = ioremap(L2C_CTL | FIELD_PREP(THUNDERX_NODE, lmc->node),
PAGE_SIZE);
if (!l2c_ioaddr) {
dev_err(&pdev->dev, "Cannot map L2C_CTL\n");
goto err_free;
}
lmc->l2c_alias = !(readq(l2c_ioaddr) & L2C_CTL_DISIDXALIAS);
iounmap(l2c_ioaddr);
ret = edac_mc_add_mc(mci);
if (ret) {
dev_err(&pdev->dev, "Cannot add the MC: %d\n", ret);
goto err_free;
}
lmc_int = readq(lmc->regs + LMC_INT);
writeq(lmc_int, lmc->regs + LMC_INT);
writeq(LMC_INT_ENA_ALL, lmc->regs + LMC_INT_ENA_W1S);
if (IS_ENABLED(CONFIG_EDAC_DEBUG)) {
ret = thunderx_create_debugfs_nodes(mci->debugfs,
lmc_dfs_ents,
lmc,
ARRAY_SIZE(lmc_dfs_ents));
if (ret != ARRAY_SIZE(lmc_dfs_ents)) {
dev_warn(&pdev->dev, "Error creating debugfs entries: %d%s\n",
ret, ret >= 0 ? " created" : "");
}
}
return 0;
err_free:
pci_set_drvdata(pdev, NULL);
edac_mc_free(mci);
return ret;
}
static void thunderx_lmc_remove(struct pci_dev *pdev)
{
struct mem_ctl_info *mci = pci_get_drvdata(pdev);
struct thunderx_lmc *lmc = mci->pvt_info;
writeq(LMC_INT_ENA_ALL, lmc->regs + LMC_INT_ENA_W1C);
edac_mc_del_mc(&pdev->dev);
edac_mc_free(mci);
}
static irqreturn_t thunderx_ocx_com_isr(int irq, void *irq_id)
{
struct msix_entry *msix = irq_id;
struct thunderx_ocx *ocx = container_of(msix, struct thunderx_ocx,
msix_ent[msix->entry]);
int lane;
unsigned long head = ring_pos(ocx->com_ring_head,
ARRAY_SIZE(ocx->com_err_ctx));
struct ocx_com_err_ctx *ctx = &ocx->com_err_ctx[head];
ctx->reg_com_int = readq(ocx->regs + OCX_COM_INT);
for (lane = 0; lane < OCX_RX_LANES; lane++) {
ctx->reg_lane_int[lane] =
readq(ocx->regs + OCX_LNE_INT(lane));
ctx->reg_lane_stat11[lane] =
readq(ocx->regs + OCX_LNE_STAT(lane, 11));
writeq(ctx->reg_lane_int[lane], ocx->regs + OCX_LNE_INT(lane));
}
writeq(ctx->reg_com_int, ocx->regs + OCX_COM_INT);
ocx->com_ring_head++;
return IRQ_WAKE_THREAD;
}
static irqreturn_t thunderx_ocx_com_threaded_isr(int irq, void *irq_id)
{
struct msix_entry *msix = irq_id;
struct thunderx_ocx *ocx = container_of(msix, struct thunderx_ocx,
msix_ent[msix->entry]);
irqreturn_t ret = IRQ_NONE;
unsigned long tail;
struct ocx_com_err_ctx *ctx;
int lane;
char *msg;
char *other;
msg = kmalloc(OCX_MESSAGE_SIZE, GFP_KERNEL);
other = kmalloc(OCX_OTHER_SIZE, GFP_KERNEL);
if (!msg || !other)
goto err_free;
while (CIRC_CNT(ocx->com_ring_head, ocx->com_ring_tail,
ARRAY_SIZE(ocx->com_err_ctx))) {
tail = ring_pos(ocx->com_ring_tail,
ARRAY_SIZE(ocx->com_err_ctx));
ctx = &ocx->com_err_ctx[tail];
snprintf(msg, OCX_MESSAGE_SIZE, "%s: OCX_COM_INT: %016llx",
ocx->edac_dev->ctl_name, ctx->reg_com_int);
decode_register(other, OCX_OTHER_SIZE,
ocx_com_errors, ctx->reg_com_int);
strncat(msg, other, OCX_MESSAGE_SIZE);
for (lane = 0; lane < OCX_RX_LANES; lane++)
if (ctx->reg_com_int & BIT(lane)) {
snprintf(other, OCX_OTHER_SIZE,
"\n\tOCX_LNE_INT[%02d]: %016llx OCX_LNE_STAT11[%02d]: %016llx",
lane, ctx->reg_lane_int[lane],
lane, ctx->reg_lane_stat11[lane]);
strncat(msg, other, OCX_MESSAGE_SIZE);
decode_register(other, OCX_OTHER_SIZE,
ocx_lane_errors,
ctx->reg_lane_int[lane]);
strncat(msg, other, OCX_MESSAGE_SIZE);
}
if (ctx->reg_com_int & OCX_COM_INT_CE)
edac_device_handle_ce(ocx->edac_dev, 0, 0, msg);
ocx->com_ring_tail++;
}
ret = IRQ_HANDLED;
err_free:
kfree(other);
kfree(msg);
return ret;
}
static irqreturn_t thunderx_ocx_lnk_isr(int irq, void *irq_id)
{
struct msix_entry *msix = irq_id;
struct thunderx_ocx *ocx = container_of(msix, struct thunderx_ocx,
msix_ent[msix->entry]);
unsigned long head = ring_pos(ocx->link_ring_head,
ARRAY_SIZE(ocx->link_err_ctx));
struct ocx_link_err_ctx *ctx = &ocx->link_err_ctx[head];
ctx->link = msix->entry;
ctx->reg_com_link_int = readq(ocx->regs + OCX_COM_LINKX_INT(ctx->link));
writeq(ctx->reg_com_link_int, ocx->regs + OCX_COM_LINKX_INT(ctx->link));
ocx->link_ring_head++;
return IRQ_WAKE_THREAD;
}
static irqreturn_t thunderx_ocx_lnk_threaded_isr(int irq, void *irq_id)
{
struct msix_entry *msix = irq_id;
struct thunderx_ocx *ocx = container_of(msix, struct thunderx_ocx,
msix_ent[msix->entry]);
irqreturn_t ret = IRQ_NONE;
unsigned long tail;
struct ocx_link_err_ctx *ctx;
char *msg;
char *other;
msg = kmalloc(OCX_MESSAGE_SIZE, GFP_KERNEL);
other = kmalloc(OCX_OTHER_SIZE, GFP_KERNEL);
if (!msg || !other)
goto err_free;
while (CIRC_CNT(ocx->link_ring_head, ocx->link_ring_tail,
ARRAY_SIZE(ocx->link_err_ctx))) {
tail = ring_pos(ocx->link_ring_head,
ARRAY_SIZE(ocx->link_err_ctx));
ctx = &ocx->link_err_ctx[tail];
snprintf(msg, OCX_MESSAGE_SIZE,
"%s: OCX_COM_LINK_INT[%d]: %016llx",
ocx->edac_dev->ctl_name,
ctx->link, ctx->reg_com_link_int);
decode_register(other, OCX_OTHER_SIZE,
ocx_com_link_errors, ctx->reg_com_link_int);
strncat(msg, other, OCX_MESSAGE_SIZE);
if (ctx->reg_com_link_int & OCX_COM_LINK_INT_UE)
edac_device_handle_ue(ocx->edac_dev, 0, 0, msg);
else if (ctx->reg_com_link_int & OCX_COM_LINK_INT_CE)
edac_device_handle_ce(ocx->edac_dev, 0, 0, msg);
ocx->link_ring_tail++;
}
ret = IRQ_HANDLED;
err_free:
kfree(other);
kfree(msg);
return ret;
}
static void thunderx_ocx_clearstats(struct thunderx_ocx *ocx)
{
int lane, stat, cfg;
for (lane = 0; lane < OCX_RX_LANES; lane++) {
cfg = readq(ocx->regs + OCX_LNE_CFG(lane));
cfg |= OCX_LNE_CFG_RX_STAT_RDCLR;
cfg &= ~OCX_LNE_CFG_RX_STAT_ENA;
writeq(cfg, ocx->regs + OCX_LNE_CFG(lane));
for (stat = 0; stat < OCX_RX_LANE_STATS; stat++)
readq(ocx->regs + OCX_LNE_STAT(lane, stat));
}
}
static int thunderx_ocx_probe(struct pci_dev *pdev,
const struct pci_device_id *id)
{
struct thunderx_ocx *ocx;
struct edac_device_ctl_info *edac_dev;
char name[32];
int idx;
int i;
int ret;
u64 reg;
ret = pcim_enable_device(pdev);
if (ret) {
dev_err(&pdev->dev, "Cannot enable PCI device: %d\n", ret);
return ret;
}
ret = pcim_iomap_regions(pdev, BIT(0), "thunderx_ocx");
if (ret) {
dev_err(&pdev->dev, "Cannot map PCI resources: %d\n", ret);
return ret;
}
idx = edac_device_alloc_index();
snprintf(name, sizeof(name), "OCX%d", idx);
edac_dev = edac_device_alloc_ctl_info(sizeof(struct thunderx_ocx),
name, 1, "CCPI", 1,
0, NULL, 0, idx);
if (!edac_dev) {
dev_err(&pdev->dev, "Cannot allocate EDAC device: %d\n", ret);
return -ENOMEM;
}
ocx = edac_dev->pvt_info;
ocx->edac_dev = edac_dev;
ocx->com_ring_head = 0;
ocx->com_ring_tail = 0;
ocx->link_ring_head = 0;
ocx->link_ring_tail = 0;
ocx->regs = pcim_iomap_table(pdev)[0];
if (!ocx->regs) {
dev_err(&pdev->dev, "Cannot map PCI resources: %d\n", ret);
ret = -ENODEV;
goto err_free;
}
ocx->pdev = pdev;
for (i = 0; i < OCX_INTS; i++) {
ocx->msix_ent[i].entry = i;
ocx->msix_ent[i].vector = 0;
}
ret = pci_enable_msix_exact(pdev, ocx->msix_ent, OCX_INTS);
if (ret) {
dev_err(&pdev->dev, "Cannot enable interrupt: %d\n", ret);
goto err_free;
}
for (i = 0; i < OCX_INTS; i++) {
ret = devm_request_threaded_irq(&pdev->dev,
ocx->msix_ent[i].vector,
(i == 3) ?
thunderx_ocx_com_isr :
thunderx_ocx_lnk_isr,
(i == 3) ?
thunderx_ocx_com_threaded_isr :
thunderx_ocx_lnk_threaded_isr,
0, "[EDAC] ThunderX OCX",
&ocx->msix_ent[i]);
if (ret)
goto err_free;
}
edac_dev->dev = &pdev->dev;
edac_dev->dev_name = dev_name(&pdev->dev);
edac_dev->mod_name = "thunderx-ocx";
edac_dev->ctl_name = "thunderx-ocx";
ret = edac_device_add_device(edac_dev);
if (ret) {
dev_err(&pdev->dev, "Cannot add EDAC device: %d\n", ret);
goto err_free;
}
if (IS_ENABLED(CONFIG_EDAC_DEBUG)) {
ocx->debugfs = edac_debugfs_create_dir(pdev->dev.kobj.name);
ret = thunderx_create_debugfs_nodes(ocx->debugfs,
ocx_dfs_ents,
ocx,
ARRAY_SIZE(ocx_dfs_ents));
if (ret != ARRAY_SIZE(ocx_dfs_ents)) {
dev_warn(&pdev->dev, "Error creating debugfs entries: %d%s\n",
ret, ret >= 0 ? " created" : "");
}
}
pci_set_drvdata(pdev, edac_dev);
thunderx_ocx_clearstats(ocx);
for (i = 0; i < OCX_RX_LANES; i++) {
writeq(OCX_LNE_INT_ENA_ALL,
ocx->regs + OCX_LNE_INT_EN(i));
reg = readq(ocx->regs + OCX_LNE_INT(i));
writeq(reg, ocx->regs + OCX_LNE_INT(i));
}
for (i = 0; i < OCX_LINK_INTS; i++) {
reg = readq(ocx->regs + OCX_COM_LINKX_INT(i));
writeq(reg, ocx->regs + OCX_COM_LINKX_INT(i));
writeq(OCX_COM_LINKX_INT_ENA_ALL,
ocx->regs + OCX_COM_LINKX_INT_ENA_W1S(i));
}
reg = readq(ocx->regs + OCX_COM_INT);
writeq(reg, ocx->regs + OCX_COM_INT);
writeq(OCX_COM_INT_ENA_ALL, ocx->regs + OCX_COM_INT_ENA_W1S);
return 0;
err_free:
edac_device_free_ctl_info(edac_dev);
return ret;
}
static void thunderx_ocx_remove(struct pci_dev *pdev)
{
struct edac_device_ctl_info *edac_dev = pci_get_drvdata(pdev);
struct thunderx_ocx *ocx = edac_dev->pvt_info;
int i;
writeq(OCX_COM_INT_ENA_ALL, ocx->regs + OCX_COM_INT_ENA_W1C);
for (i = 0; i < OCX_INTS; i++) {
writeq(OCX_COM_LINKX_INT_ENA_ALL,
ocx->regs + OCX_COM_LINKX_INT_ENA_W1C(i));
}
edac_debugfs_remove_recursive(ocx->debugfs);
edac_device_del_device(&pdev->dev);
edac_device_free_ctl_info(edac_dev);
}
static irqreturn_t thunderx_l2c_tad_isr(int irq, void *irq_id)
{
struct msix_entry *msix = irq_id;
struct thunderx_l2c *tad = container_of(msix, struct thunderx_l2c,
msix_ent);
unsigned long head = ring_pos(tad->ring_head, ARRAY_SIZE(tad->err_ctx));
struct l2c_err_ctx *ctx = &tad->err_ctx[head];
ctx->reg_int = readq(tad->regs + L2C_TAD_INT_W1C);
if (ctx->reg_int & L2C_TAD_INT_ECC) {
ctx->reg_ext_name = "TQD_ERR";
ctx->reg_ext = readq(tad->regs + L2C_TAD_TQD_ERR);
} else if (ctx->reg_int & L2C_TAD_INT_TAG) {
ctx->reg_ext_name = "TTG_ERR";
ctx->reg_ext = readq(tad->regs + L2C_TAD_TTG_ERR);
} else if (ctx->reg_int & L2C_TAD_INT_LFBTO) {
ctx->reg_ext_name = "TIMEOUT";
ctx->reg_ext = readq(tad->regs + L2C_TAD_TIMEOUT);
} else if (ctx->reg_int & L2C_TAD_INT_DISOCI) {
ctx->reg_ext_name = "ERR";
ctx->reg_ext = readq(tad->regs + L2C_TAD_ERR);
}
writeq(ctx->reg_int, tad->regs + L2C_TAD_INT_W1C);
tad->ring_head++;
return IRQ_WAKE_THREAD;
}
static irqreturn_t thunderx_l2c_cbc_isr(int irq, void *irq_id)
{
struct msix_entry *msix = irq_id;
struct thunderx_l2c *cbc = container_of(msix, struct thunderx_l2c,
msix_ent);
unsigned long head = ring_pos(cbc->ring_head, ARRAY_SIZE(cbc->err_ctx));
struct l2c_err_ctx *ctx = &cbc->err_ctx[head];
ctx->reg_int = readq(cbc->regs + L2C_CBC_INT_W1C);
if (ctx->reg_int & L2C_CBC_INT_RSD) {
ctx->reg_ext_name = "RSDERR";
ctx->reg_ext = readq(cbc->regs + L2C_CBC_RSDERR);
} else if (ctx->reg_int & L2C_CBC_INT_MIB) {
ctx->reg_ext_name = "MIBERR";
ctx->reg_ext = readq(cbc->regs + L2C_CBC_MIBERR);
} else if (ctx->reg_int & L2C_CBC_INT_IODISOCI) {
ctx->reg_ext_name = "IODISOCIERR";
ctx->reg_ext = readq(cbc->regs + L2C_CBC_IODISOCIERR);
}
writeq(ctx->reg_int, cbc->regs + L2C_CBC_INT_W1C);
cbc->ring_head++;
return IRQ_WAKE_THREAD;
}
static irqreturn_t thunderx_l2c_mci_isr(int irq, void *irq_id)
{
struct msix_entry *msix = irq_id;
struct thunderx_l2c *mci = container_of(msix, struct thunderx_l2c,
msix_ent);
unsigned long head = ring_pos(mci->ring_head, ARRAY_SIZE(mci->err_ctx));
struct l2c_err_ctx *ctx = &mci->err_ctx[head];
ctx->reg_int = readq(mci->regs + L2C_MCI_INT_W1C);
ctx->reg_ext = readq(mci->regs + L2C_MCI_ERR);
writeq(ctx->reg_int, mci->regs + L2C_MCI_INT_W1C);
ctx->reg_ext_name = "ERR";
mci->ring_head++;
return IRQ_WAKE_THREAD;
}
static irqreturn_t thunderx_l2c_threaded_isr(int irq, void *irq_id)
{
struct msix_entry *msix = irq_id;
struct thunderx_l2c *l2c = container_of(msix, struct thunderx_l2c,
msix_ent);
unsigned long tail = ring_pos(l2c->ring_tail, ARRAY_SIZE(l2c->err_ctx));
struct l2c_err_ctx *ctx = &l2c->err_ctx[tail];
irqreturn_t ret = IRQ_NONE;
u64 mask_ue, mask_ce;
const struct error_descr *l2_errors;
char *reg_int_name;
char *msg;
char *other;
msg = kmalloc(OCX_MESSAGE_SIZE, GFP_KERNEL);
other = kmalloc(OCX_OTHER_SIZE, GFP_KERNEL);
if (!msg || !other)
goto err_free;
switch (l2c->pdev->device) {
case PCI_DEVICE_ID_THUNDER_L2C_TAD:
reg_int_name = "L2C_TAD_INT";
mask_ue = L2C_TAD_INT_UE;
mask_ce = L2C_TAD_INT_CE;
l2_errors = l2_tad_errors;
break;
case PCI_DEVICE_ID_THUNDER_L2C_CBC:
reg_int_name = "L2C_CBC_INT";
mask_ue = L2C_CBC_INT_UE;
mask_ce = L2C_CBC_INT_CE;
l2_errors = l2_cbc_errors;
break;
case PCI_DEVICE_ID_THUNDER_L2C_MCI:
reg_int_name = "L2C_MCI_INT";
mask_ue = L2C_MCI_INT_VBFDBE;
mask_ce = L2C_MCI_INT_VBFSBE;
l2_errors = l2_mci_errors;
break;
default:
dev_err(&l2c->pdev->dev, "Unsupported device: %04x\n",
l2c->pdev->device);
return IRQ_NONE;
}
while (CIRC_CNT(l2c->ring_head, l2c->ring_tail,
ARRAY_SIZE(l2c->err_ctx))) {
snprintf(msg, L2C_MESSAGE_SIZE,
"%s: %s: %016llx, %s: %016llx",
l2c->edac_dev->ctl_name, reg_int_name, ctx->reg_int,
ctx->reg_ext_name, ctx->reg_ext);
decode_register(other, L2C_OTHER_SIZE, l2_errors, ctx->reg_int);
strncat(msg, other, L2C_MESSAGE_SIZE);
if (ctx->reg_int & mask_ue)
edac_device_handle_ue(l2c->edac_dev, 0, 0, msg);
else if (ctx->reg_int & mask_ce)
edac_device_handle_ce(l2c->edac_dev, 0, 0, msg);
l2c->ring_tail++;
}
return IRQ_HANDLED;
err_free:
kfree(other);
kfree(msg);
return ret;
}
static int thunderx_l2c_probe(struct pci_dev *pdev,
const struct pci_device_id *id)
{
struct thunderx_l2c *l2c;
struct edac_device_ctl_info *edac_dev;
struct debugfs_entry **l2c_devattr;
size_t dfs_entries;
irqreturn_t (*thunderx_l2c_isr)(int, void *) = NULL;
char name[32];
const char *fmt;
u64 reg_en_offs, reg_en_mask;
int idx;
int ret;
ret = pcim_enable_device(pdev);
if (ret) {
dev_err(&pdev->dev, "Cannot enable PCI device: %d\n", ret);
return ret;
}
ret = pcim_iomap_regions(pdev, BIT(0), "thunderx_l2c");
if (ret) {
dev_err(&pdev->dev, "Cannot map PCI resources: %d\n", ret);
return ret;
}
switch (pdev->device) {
case PCI_DEVICE_ID_THUNDER_L2C_TAD:
thunderx_l2c_isr = thunderx_l2c_tad_isr;
l2c_devattr = l2c_tad_dfs_ents;
dfs_entries = ARRAY_SIZE(l2c_tad_dfs_ents);
fmt = "L2C-TAD%d";
reg_en_offs = L2C_TAD_INT_ENA_W1S;
reg_en_mask = L2C_TAD_INT_ENA_ALL;
break;
case PCI_DEVICE_ID_THUNDER_L2C_CBC:
thunderx_l2c_isr = thunderx_l2c_cbc_isr;
l2c_devattr = l2c_cbc_dfs_ents;
dfs_entries = ARRAY_SIZE(l2c_cbc_dfs_ents);
fmt = "L2C-CBC%d";
reg_en_offs = L2C_CBC_INT_ENA_W1S;
reg_en_mask = L2C_CBC_INT_ENA_ALL;
break;
case PCI_DEVICE_ID_THUNDER_L2C_MCI:
thunderx_l2c_isr = thunderx_l2c_mci_isr;
l2c_devattr = l2c_mci_dfs_ents;
dfs_entries = ARRAY_SIZE(l2c_mci_dfs_ents);
fmt = "L2C-MCI%d";
reg_en_offs = L2C_MCI_INT_ENA_W1S;
reg_en_mask = L2C_MCI_INT_ENA_ALL;
break;
default:
dev_err(&pdev->dev, "Unsupported PCI device: %04x\n",
pdev->device);
return -EINVAL;
}
idx = edac_device_alloc_index();
snprintf(name, sizeof(name), fmt, idx);
edac_dev = edac_device_alloc_ctl_info(sizeof(struct thunderx_l2c),
name, 1, "L2C", 1, 0,
NULL, 0, idx);
if (!edac_dev) {
dev_err(&pdev->dev, "Cannot allocate EDAC device\n");
return -ENOMEM;
}
l2c = edac_dev->pvt_info;
l2c->edac_dev = edac_dev;
l2c->regs = pcim_iomap_table(pdev)[0];
if (!l2c->regs) {
dev_err(&pdev->dev, "Cannot map PCI resources\n");
ret = -ENODEV;
goto err_free;
}
l2c->pdev = pdev;
l2c->ring_head = 0;
l2c->ring_tail = 0;
l2c->msix_ent.entry = 0;
l2c->msix_ent.vector = 0;
ret = pci_enable_msix_exact(pdev, &l2c->msix_ent, 1);
if (ret) {
dev_err(&pdev->dev, "Cannot enable interrupt: %d\n", ret);
goto err_free;
}
ret = devm_request_threaded_irq(&pdev->dev, l2c->msix_ent.vector,
thunderx_l2c_isr,
thunderx_l2c_threaded_isr,
0, "[EDAC] ThunderX L2C",
&l2c->msix_ent);
if (ret)
goto err_free;
edac_dev->dev = &pdev->dev;
edac_dev->dev_name = dev_name(&pdev->dev);
edac_dev->mod_name = "thunderx-l2c";
edac_dev->ctl_name = "thunderx-l2c";
ret = edac_device_add_device(edac_dev);
if (ret) {
dev_err(&pdev->dev, "Cannot add EDAC device: %d\n", ret);
goto err_free;
}
if (IS_ENABLED(CONFIG_EDAC_DEBUG)) {
l2c->debugfs = edac_debugfs_create_dir(pdev->dev.kobj.name);
thunderx_create_debugfs_nodes(l2c->debugfs, l2c_devattr,
l2c, dfs_entries);
if (ret != dfs_entries) {
dev_warn(&pdev->dev, "Error creating debugfs entries: %d%s\n",
ret, ret >= 0 ? " created" : "");
}
}
pci_set_drvdata(pdev, edac_dev);
writeq(reg_en_mask, l2c->regs + reg_en_offs);
return 0;
err_free:
edac_device_free_ctl_info(edac_dev);
return ret;
}
static void thunderx_l2c_remove(struct pci_dev *pdev)
{
struct edac_device_ctl_info *edac_dev = pci_get_drvdata(pdev);
struct thunderx_l2c *l2c = edac_dev->pvt_info;
switch (pdev->device) {
case PCI_DEVICE_ID_THUNDER_L2C_TAD:
writeq(L2C_TAD_INT_ENA_ALL, l2c->regs + L2C_TAD_INT_ENA_W1C);
break;
case PCI_DEVICE_ID_THUNDER_L2C_CBC:
writeq(L2C_CBC_INT_ENA_ALL, l2c->regs + L2C_CBC_INT_ENA_W1C);
break;
case PCI_DEVICE_ID_THUNDER_L2C_MCI:
writeq(L2C_MCI_INT_ENA_ALL, l2c->regs + L2C_MCI_INT_ENA_W1C);
break;
}
edac_debugfs_remove_recursive(l2c->debugfs);
edac_device_del_device(&pdev->dev);
edac_device_free_ctl_info(edac_dev);
}
static int __init thunderx_edac_init(void)
{
int rc = 0;
rc = pci_register_driver(&thunderx_lmc_driver);
if (rc)
return rc;
rc = pci_register_driver(&thunderx_ocx_driver);
if (rc)
goto err_lmc;
rc = pci_register_driver(&thunderx_l2c_driver);
if (rc)
goto err_ocx;
return rc;
err_ocx:
pci_unregister_driver(&thunderx_ocx_driver);
err_lmc:
pci_unregister_driver(&thunderx_lmc_driver);
return rc;
}
static void __exit thunderx_edac_exit(void)
{
pci_unregister_driver(&thunderx_l2c_driver);
pci_unregister_driver(&thunderx_ocx_driver);
pci_unregister_driver(&thunderx_lmc_driver);
}
