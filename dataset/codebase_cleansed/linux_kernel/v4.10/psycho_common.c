static void psycho_check_stc_error(struct pci_pbm_info *pbm)
{
unsigned long err_base, tag_base, line_base;
struct strbuf *strbuf = &pbm->stc;
u64 control;
int i;
if (!strbuf->strbuf_control)
return;
err_base = strbuf->strbuf_err_stat;
tag_base = strbuf->strbuf_tag_diag;
line_base = strbuf->strbuf_line_diag;
spin_lock(&stc_buf_lock);
control = upa_readq(strbuf->strbuf_control);
upa_writeq(control | PSYCHO_STRBUF_CTRL_DENAB, strbuf->strbuf_control);
for (i = 0; i < 128; i++) {
u64 val;
val = upa_readq(err_base + (i * 8UL));
upa_writeq(0UL, err_base + (i * 8UL));
stc_error_buf[i] = val;
}
for (i = 0; i < 16; i++) {
stc_tag_buf[i] = upa_readq(tag_base + (i * 8UL));
stc_line_buf[i] = upa_readq(line_base + (i * 8UL));
upa_writeq(0UL, tag_base + (i * 8UL));
upa_writeq(0UL, line_base + (i * 8UL));
}
upa_writeq(control, strbuf->strbuf_control);
for (i = 0; i < 16; i++) {
int j, saw_error, first, last;
saw_error = 0;
first = i * 8;
last = first + 8;
for (j = first; j < last; j++) {
u64 errval = stc_error_buf[j];
if (errval != 0) {
saw_error++;
printk(KERN_ERR "%s: STC_ERR(%d)[wr(%d)"
"rd(%d)]\n",
pbm->name,
j,
(errval & PSYCHO_STCERR_WRITE) ? 1 : 0,
(errval & PSYCHO_STCERR_READ) ? 1 : 0);
}
}
if (saw_error != 0) {
u64 tagval = stc_tag_buf[i];
u64 lineval = stc_line_buf[i];
printk(KERN_ERR "%s: STC_TAG(%d)[PA(%016llx)VA(%08llx)"
"V(%d)W(%d)]\n",
pbm->name,
i,
((tagval & PSYCHO_STCTAG_PPN) >> 19UL),
(tagval & PSYCHO_STCTAG_VPN),
((tagval & PSYCHO_STCTAG_VALID) ? 1 : 0),
((tagval & PSYCHO_STCTAG_WRITE) ? 1 : 0));
printk(KERN_ERR "%s: STC_LINE(%d)[LIDX(%llx)SP(%llx)"
"LADDR(%llx)EP(%llx)V(%d)FOFN(%d)]\n",
pbm->name,
i,
((lineval & PSYCHO_STCLINE_LINDX) >> 21UL),
((lineval & PSYCHO_STCLINE_SPTR) >> 15UL),
((lineval & PSYCHO_STCLINE_LADDR) >> 8UL),
((lineval & PSYCHO_STCLINE_EPTR) >> 2UL),
((lineval & PSYCHO_STCLINE_VALID) ? 1 : 0),
((lineval & PSYCHO_STCLINE_FOFN) ? 1 : 0));
}
}
spin_unlock(&stc_buf_lock);
}
static void psycho_record_iommu_tags_and_data(struct pci_pbm_info *pbm,
u64 *tag, u64 *data)
{
int i;
for (i = 0; i < 16; i++) {
unsigned long base = pbm->controller_regs;
unsigned long off = i * 8UL;
tag[i] = upa_readq(base + PSYCHO_IOMMU_TAG+off);
data[i] = upa_readq(base + PSYCHO_IOMMU_DATA+off);
upa_writeq(0, base + PSYCHO_IOMMU_TAG + off);
upa_writeq(0, base + PSYCHO_IOMMU_DATA + off);
}
}
static void psycho_dump_iommu_tags_and_data(struct pci_pbm_info *pbm,
u64 *tag, u64 *data)
{
int i;
for (i = 0; i < 16; i++) {
u64 tag_val, data_val;
const char *type_str;
tag_val = tag[i];
if (!(tag_val & PSYCHO_IOMMU_TAG_ERR))
continue;
data_val = data[i];
switch((tag_val & PSYCHO_IOMMU_TAG_ERRSTS) >> 23UL) {
case 0:
type_str = "Protection Error";
break;
case 1:
type_str = "Invalid Error";
break;
case 2:
type_str = "TimeOut Error";
break;
case 3:
default:
type_str = "ECC Error";
break;
}
printk(KERN_ERR "%s: IOMMU TAG(%d)[error(%s) wr(%d) "
"str(%d) sz(%dK) vpg(%08llx)]\n",
pbm->name, i, type_str,
((tag_val & PSYCHO_IOMMU_TAG_WRITE) ? 1 : 0),
((tag_val & PSYCHO_IOMMU_TAG_STREAM) ? 1 : 0),
((tag_val & PSYCHO_IOMMU_TAG_SIZE) ? 64 : 8),
(tag_val & PSYCHO_IOMMU_TAG_VPAGE) << IOMMU_PAGE_SHIFT);
printk(KERN_ERR "%s: IOMMU DATA(%d)[valid(%d) cache(%d) "
"ppg(%016llx)]\n",
pbm->name, i,
((data_val & PSYCHO_IOMMU_DATA_VALID) ? 1 : 0),
((data_val & PSYCHO_IOMMU_DATA_CACHE) ? 1 : 0),
(data_val & PSYCHO_IOMMU_DATA_PPAGE) << IOMMU_PAGE_SHIFT);
}
}
void psycho_check_iommu_error(struct pci_pbm_info *pbm,
unsigned long afsr,
unsigned long afar,
enum psycho_error_type type)
{
u64 control, iommu_tag[16], iommu_data[16];
struct iommu *iommu = pbm->iommu;
unsigned long flags;
spin_lock_irqsave(&iommu->lock, flags);
control = upa_readq(iommu->iommu_control);
if (control & PSYCHO_IOMMU_CTRL_XLTEERR) {
const char *type_str;
control &= ~PSYCHO_IOMMU_CTRL_XLTEERR;
upa_writeq(control, iommu->iommu_control);
switch ((control & PSYCHO_IOMMU_CTRL_XLTESTAT) >> 25UL) {
case 0:
type_str = "Protection Error";
break;
case 1:
type_str = "Invalid Error";
break;
case 2:
type_str = "TimeOut Error";
break;
case 3:
default:
type_str = "ECC Error";
break;
}
printk(KERN_ERR "%s: IOMMU Error, type[%s]\n",
pbm->name, type_str);
psycho_record_iommu_tags_and_data(pbm, iommu_tag, iommu_data);
psycho_dump_iommu_tags_and_data(pbm, iommu_tag, iommu_data);
}
psycho_check_stc_error(pbm);
spin_unlock_irqrestore(&iommu->lock, flags);
}
static irqreturn_t psycho_pcierr_intr_other(struct pci_pbm_info *pbm)
{
irqreturn_t ret = IRQ_NONE;
u64 csr, csr_error_bits;
u16 stat, *addr;
csr = upa_readq(pbm->pci_csr);
csr_error_bits = csr & (PSYCHO_PCICTRL_SBH_ERR | PSYCHO_PCICTRL_SERR);
if (csr_error_bits) {
upa_writeq(csr, pbm->pci_csr);
if (csr_error_bits & PSYCHO_PCICTRL_SBH_ERR)
printk(KERN_ERR "%s: PCI streaming byte hole "
"error asserted.\n", pbm->name);
if (csr_error_bits & PSYCHO_PCICTRL_SERR)
printk(KERN_ERR "%s: PCI SERR signal asserted.\n",
pbm->name);
ret = IRQ_HANDLED;
}
addr = psycho_pci_config_mkaddr(pbm, pbm->pci_first_busno,
0, PCI_STATUS);
pci_config_read16(addr, &stat);
if (stat & (PCI_STATUS_PARITY |
PCI_STATUS_SIG_TARGET_ABORT |
PCI_STATUS_REC_TARGET_ABORT |
PCI_STATUS_REC_MASTER_ABORT |
PCI_STATUS_SIG_SYSTEM_ERROR)) {
printk(KERN_ERR "%s: PCI bus error, PCI_STATUS[%04x]\n",
pbm->name, stat);
pci_config_write16(addr, 0xffff);
ret = IRQ_HANDLED;
}
return ret;
}
irqreturn_t psycho_pcierr_intr(int irq, void *dev_id)
{
struct pci_pbm_info *pbm = dev_id;
u64 afsr, afar, error_bits;
int reported;
afsr = upa_readq(pbm->pci_afsr);
afar = upa_readq(pbm->pci_afar);
error_bits = afsr &
(PSYCHO_PCIAFSR_PMA | PSYCHO_PCIAFSR_PTA |
PSYCHO_PCIAFSR_PRTRY | PSYCHO_PCIAFSR_PPERR |
PSYCHO_PCIAFSR_SMA | PSYCHO_PCIAFSR_STA |
PSYCHO_PCIAFSR_SRTRY | PSYCHO_PCIAFSR_SPERR);
if (!error_bits)
return psycho_pcierr_intr_other(pbm);
upa_writeq(error_bits, pbm->pci_afsr);
printk(KERN_ERR "%s: PCI Error, primary error type[%s]\n",
pbm->name,
(((error_bits & PSYCHO_PCIAFSR_PMA) ?
"Master Abort" :
((error_bits & PSYCHO_PCIAFSR_PTA) ?
"Target Abort" :
((error_bits & PSYCHO_PCIAFSR_PRTRY) ?
"Excessive Retries" :
((error_bits & PSYCHO_PCIAFSR_PPERR) ?
"Parity Error" : "???"))))));
printk(KERN_ERR "%s: bytemask[%04llx] UPA_MID[%02llx] was_block(%d)\n",
pbm->name,
(afsr & PSYCHO_PCIAFSR_BMSK) >> 32UL,
(afsr & PSYCHO_PCIAFSR_MID) >> 25UL,
(afsr & PSYCHO_PCIAFSR_BLK) ? 1 : 0);
printk(KERN_ERR "%s: PCI AFAR [%016llx]\n", pbm->name, afar);
printk(KERN_ERR "%s: PCI Secondary errors [", pbm->name);
reported = 0;
if (afsr & PSYCHO_PCIAFSR_SMA) {
reported++;
printk("(Master Abort)");
}
if (afsr & PSYCHO_PCIAFSR_STA) {
reported++;
printk("(Target Abort)");
}
if (afsr & PSYCHO_PCIAFSR_SRTRY) {
reported++;
printk("(Excessive Retries)");
}
if (afsr & PSYCHO_PCIAFSR_SPERR) {
reported++;
printk("(Parity Error)");
}
if (!reported)
printk("(none)");
printk("]\n");
if (error_bits & (PSYCHO_PCIAFSR_PTA | PSYCHO_PCIAFSR_STA)) {
psycho_check_iommu_error(pbm, afsr, afar, PCI_ERR);
pci_scan_for_target_abort(pbm, pbm->pci_bus);
}
if (error_bits & (PSYCHO_PCIAFSR_PMA | PSYCHO_PCIAFSR_SMA))
pci_scan_for_master_abort(pbm, pbm->pci_bus);
if (error_bits & (PSYCHO_PCIAFSR_PPERR | PSYCHO_PCIAFSR_SPERR))
pci_scan_for_parity_error(pbm, pbm->pci_bus);
return IRQ_HANDLED;
}
static void psycho_iommu_flush(struct pci_pbm_info *pbm)
{
int i;
for (i = 0; i < 16; i++) {
unsigned long off = i * 8;
upa_writeq(0, pbm->controller_regs + PSYCHO_IOMMU_TAG + off);
upa_writeq(0, pbm->controller_regs + PSYCHO_IOMMU_DATA + off);
}
}
int psycho_iommu_init(struct pci_pbm_info *pbm, int tsbsize,
u32 dvma_offset, u32 dma_mask,
unsigned long write_complete_offset)
{
struct iommu *iommu = pbm->iommu;
u64 control;
int err;
iommu->iommu_control = pbm->controller_regs + PSYCHO_IOMMU_CONTROL;
iommu->iommu_tsbbase = pbm->controller_regs + PSYCHO_IOMMU_TSBBASE;
iommu->iommu_flush = pbm->controller_regs + PSYCHO_IOMMU_FLUSH;
iommu->iommu_tags = pbm->controller_regs + PSYCHO_IOMMU_TAG;
iommu->write_complete_reg = (pbm->controller_regs +
write_complete_offset);
iommu->iommu_ctxflush = 0;
control = upa_readq(iommu->iommu_control);
control |= PSYCHO_IOMMU_CTRL_DENAB;
upa_writeq(control, iommu->iommu_control);
psycho_iommu_flush(pbm);
err = iommu_table_init(iommu, tsbsize * 1024 * 8,
dvma_offset, dma_mask, pbm->numa_node);
if (err)
return err;
upa_writeq(__pa(iommu->page_table), iommu->iommu_tsbbase);
control = upa_readq(iommu->iommu_control);
control &= ~(PSYCHO_IOMMU_CTRL_TSBSZ | PSYCHO_IOMMU_CTRL_TBWSZ);
control |= PSYCHO_IOMMU_CTRL_ENAB;
switch (tsbsize) {
case 64:
control |= PSYCHO_IOMMU_TSBSZ_64K;
break;
case 128:
control |= PSYCHO_IOMMU_TSBSZ_128K;
break;
default:
return -EINVAL;
}
upa_writeq(control, iommu->iommu_control);
return 0;
}
void psycho_pbm_init_common(struct pci_pbm_info *pbm, struct platform_device *op,
const char *chip_name, int chip_type)
{
struct device_node *dp = op->dev.of_node;
pbm->name = dp->full_name;
pbm->numa_node = -1;
pbm->chip_type = chip_type;
pbm->chip_version = of_getintprop_default(dp, "version#", 0);
pbm->chip_revision = of_getintprop_default(dp, "module-revision#", 0);
pbm->op = op;
pbm->pci_ops = &sun4u_pci_ops;
pbm->config_space_reg_bits = 8;
pbm->index = pci_num_pbms++;
pci_get_pbm_props(pbm);
pci_determine_mem_io_space(pbm);
printk(KERN_INFO "%s: %s PCI Bus Module ver[%x:%x]\n",
pbm->name, chip_name,
pbm->chip_version, pbm->chip_revision);
}
