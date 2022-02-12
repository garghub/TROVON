static irqreturn_t psycho_ue_intr(int irq, void *dev_id)
{
struct pci_pbm_info *pbm = dev_id;
unsigned long afsr_reg = pbm->controller_regs + PSYCHO_UE_AFSR;
unsigned long afar_reg = pbm->controller_regs + PSYCHO_UE_AFAR;
unsigned long afsr, afar, error_bits;
int reported;
afar = upa_readq(afar_reg);
afsr = upa_readq(afsr_reg);
error_bits = afsr &
(PSYCHO_UEAFSR_PPIO | PSYCHO_UEAFSR_PDRD | PSYCHO_UEAFSR_PDWR |
PSYCHO_UEAFSR_SPIO | PSYCHO_UEAFSR_SDRD | PSYCHO_UEAFSR_SDWR);
if (!error_bits)
return IRQ_NONE;
upa_writeq(error_bits, afsr_reg);
printk("%s: Uncorrectable Error, primary error type[%s]\n",
pbm->name,
(((error_bits & PSYCHO_UEAFSR_PPIO) ?
"PIO" :
((error_bits & PSYCHO_UEAFSR_PDRD) ?
"DMA Read" :
((error_bits & PSYCHO_UEAFSR_PDWR) ?
"DMA Write" : "???")))));
printk("%s: bytemask[%04lx] dword_offset[%lx] UPA_MID[%02lx] was_block(%d)\n",
pbm->name,
(afsr & PSYCHO_UEAFSR_BMSK) >> 32UL,
(afsr & PSYCHO_UEAFSR_DOFF) >> 29UL,
(afsr & PSYCHO_UEAFSR_MID) >> 24UL,
((afsr & PSYCHO_UEAFSR_BLK) ? 1 : 0));
printk("%s: UE AFAR [%016lx]\n", pbm->name, afar);
printk("%s: UE Secondary errors [", pbm->name);
reported = 0;
if (afsr & PSYCHO_UEAFSR_SPIO) {
reported++;
printk("(PIO)");
}
if (afsr & PSYCHO_UEAFSR_SDRD) {
reported++;
printk("(DMA Read)");
}
if (afsr & PSYCHO_UEAFSR_SDWR) {
reported++;
printk("(DMA Write)");
}
if (!reported)
printk("(none)");
printk("]\n");
psycho_check_iommu_error(pbm, afsr, afar, UE_ERR);
if (pbm->sibling)
psycho_check_iommu_error(pbm->sibling, afsr, afar, UE_ERR);
return IRQ_HANDLED;
}
static irqreturn_t psycho_ce_intr(int irq, void *dev_id)
{
struct pci_pbm_info *pbm = dev_id;
unsigned long afsr_reg = pbm->controller_regs + PSYCHO_CE_AFSR;
unsigned long afar_reg = pbm->controller_regs + PSYCHO_CE_AFAR;
unsigned long afsr, afar, error_bits;
int reported;
afar = upa_readq(afar_reg);
afsr = upa_readq(afsr_reg);
error_bits = afsr &
(PSYCHO_CEAFSR_PPIO | PSYCHO_CEAFSR_PDRD | PSYCHO_CEAFSR_PDWR |
PSYCHO_CEAFSR_SPIO | PSYCHO_CEAFSR_SDRD | PSYCHO_CEAFSR_SDWR);
if (!error_bits)
return IRQ_NONE;
upa_writeq(error_bits, afsr_reg);
printk("%s: Correctable Error, primary error type[%s]\n",
pbm->name,
(((error_bits & PSYCHO_CEAFSR_PPIO) ?
"PIO" :
((error_bits & PSYCHO_CEAFSR_PDRD) ?
"DMA Read" :
((error_bits & PSYCHO_CEAFSR_PDWR) ?
"DMA Write" : "???")))));
printk("%s: syndrome[%02lx] bytemask[%04lx] dword_offset[%lx] "
"UPA_MID[%02lx] was_block(%d)\n",
pbm->name,
(afsr & PSYCHO_CEAFSR_ESYND) >> 48UL,
(afsr & PSYCHO_CEAFSR_BMSK) >> 32UL,
(afsr & PSYCHO_CEAFSR_DOFF) >> 29UL,
(afsr & PSYCHO_CEAFSR_MID) >> 24UL,
((afsr & PSYCHO_CEAFSR_BLK) ? 1 : 0));
printk("%s: CE AFAR [%016lx]\n", pbm->name, afar);
printk("%s: CE Secondary errors [", pbm->name);
reported = 0;
if (afsr & PSYCHO_CEAFSR_SPIO) {
reported++;
printk("(PIO)");
}
if (afsr & PSYCHO_CEAFSR_SDRD) {
reported++;
printk("(DMA Read)");
}
if (afsr & PSYCHO_CEAFSR_SDWR) {
reported++;
printk("(DMA Write)");
}
if (!reported)
printk("(none)");
printk("]\n");
return IRQ_HANDLED;
}
static void psycho_register_error_handlers(struct pci_pbm_info *pbm)
{
struct platform_device *op = of_find_device_by_node(pbm->op->dev.of_node);
unsigned long base = pbm->controller_regs;
u64 tmp;
int err;
if (!op)
return;
if (op->archdata.num_irqs < 6)
return;
err = request_irq(op->archdata.irqs[1], psycho_ue_intr, IRQF_SHARED,
"PSYCHO_UE", pbm);
err = request_irq(op->archdata.irqs[2], psycho_ce_intr, IRQF_SHARED,
"PSYCHO_CE", pbm);
err = request_irq(op->archdata.irqs[0], psycho_pcierr_intr, IRQF_SHARED,
"PSYCHO_PCIERR", pbm);
if (err)
printk(KERN_WARNING "%s: Could not register PCIERR, "
"err=%d\n", pbm->name, err);
upa_writeq((PSYCHO_ECCCTRL_EE |
PSYCHO_ECCCTRL_UE |
PSYCHO_ECCCTRL_CE), base + PSYCHO_ECC_CTRL);
tmp = upa_readq(base + PSYCHO_PCIA_CTRL);
tmp |= (PSYCHO_PCICTRL_SERR |
PSYCHO_PCICTRL_SBH_ERR |
PSYCHO_PCICTRL_EEN);
tmp &= ~(PSYCHO_PCICTRL_SBH_INT);
upa_writeq(tmp, base + PSYCHO_PCIA_CTRL);
tmp = upa_readq(base + PSYCHO_PCIB_CTRL);
tmp |= (PSYCHO_PCICTRL_SERR |
PSYCHO_PCICTRL_SBH_ERR |
PSYCHO_PCICTRL_EEN);
tmp &= ~(PSYCHO_PCICTRL_SBH_INT);
upa_writeq(tmp, base + PSYCHO_PCIB_CTRL);
}
static void pbm_config_busmastering(struct pci_pbm_info *pbm)
{
u8 *addr;
addr = psycho_pci_config_mkaddr(pbm, pbm->pci_first_busno,
0, PCI_CACHE_LINE_SIZE);
pci_config_write8(addr, 64 / sizeof(u32));
addr = psycho_pci_config_mkaddr(pbm, pbm->pci_first_busno,
0, PCI_LATENCY_TIMER);
pci_config_write8(addr, 64);
}
static void psycho_scan_bus(struct pci_pbm_info *pbm,
struct device *parent)
{
pbm_config_busmastering(pbm);
pbm->is_66mhz_capable = 0;
pbm->pci_bus = pci_scan_one_pbm(pbm, parent);
psycho_register_error_handlers(pbm);
}
static void psycho_controller_hwinit(struct pci_pbm_info *pbm)
{
u64 tmp;
upa_writeq(5, pbm->controller_regs + PSYCHO_IRQ_RETRY);
tmp = upa_readq(pbm->controller_regs + PSYCHO_PCIA_CTRL);
tmp |= PSYCHO_PCICTRL_AEN;
upa_writeq(tmp, pbm->controller_regs + PSYCHO_PCIA_CTRL);
tmp = upa_readq(pbm->controller_regs + PSYCHO_PCIB_CTRL);
tmp |= PSYCHO_PCICTRL_AEN;
upa_writeq(tmp, pbm->controller_regs + PSYCHO_PCIB_CTRL);
tmp = upa_readq(pbm->controller_regs + PSYCHO_PCIA_DIAG);
tmp |= PSYCHO_PCIDIAG_DDWSYNC;
upa_writeq(tmp, pbm->controller_regs + PSYCHO_PCIA_DIAG);
tmp = upa_readq(pbm->controller_regs + PSYCHO_PCIB_DIAG);
tmp |= PSYCHO_PCIDIAG_DDWSYNC;
upa_writeq(tmp, pbm->controller_regs + PSYCHO_PCIB_DIAG);
}
static void psycho_pbm_strbuf_init(struct pci_pbm_info *pbm,
int is_pbm_a)
{
unsigned long base = pbm->controller_regs;
u64 control;
if (is_pbm_a) {
pbm->stc.strbuf_control = base + PSYCHO_STRBUF_CONTROL_A;
pbm->stc.strbuf_pflush = base + PSYCHO_STRBUF_FLUSH_A;
pbm->stc.strbuf_fsync = base + PSYCHO_STRBUF_FSYNC_A;
pbm->stc.strbuf_err_stat = base + PSYCHO_STC_ERR_A;
pbm->stc.strbuf_tag_diag = base + PSYCHO_STC_TAG_A;
pbm->stc.strbuf_line_diag= base + PSYCHO_STC_LINE_A;
} else {
pbm->stc.strbuf_control = base + PSYCHO_STRBUF_CONTROL_B;
pbm->stc.strbuf_pflush = base + PSYCHO_STRBUF_FLUSH_B;
pbm->stc.strbuf_fsync = base + PSYCHO_STRBUF_FSYNC_B;
pbm->stc.strbuf_err_stat = base + PSYCHO_STC_ERR_B;
pbm->stc.strbuf_tag_diag = base + PSYCHO_STC_TAG_B;
pbm->stc.strbuf_line_diag= base + PSYCHO_STC_LINE_B;
}
pbm->stc.strbuf_ctxflush = 0;
pbm->stc.strbuf_ctxmatch_base = 0;
pbm->stc.strbuf_flushflag = (volatile unsigned long *)
((((unsigned long)&pbm->stc.__flushflag_buf[0])
+ 63UL)
& ~63UL);
pbm->stc.strbuf_flushflag_pa = (unsigned long)
__pa(pbm->stc.strbuf_flushflag);
#undef PSYCHO_STRBUF_RERUN_ENABLE
#undef PSYCHO_STRBUF_RERUN_DISABLE
control = upa_readq(pbm->stc.strbuf_control);
control |= PSYCHO_STRBUF_CTRL_ENAB;
control &= ~(PSYCHO_STRBUF_CTRL_LENAB | PSYCHO_STRBUF_CTRL_LPTR);
#ifdef PSYCHO_STRBUF_RERUN_ENABLE
control &= ~(PSYCHO_STRBUF_CTRL_RRDIS);
#else
#ifdef PSYCHO_STRBUF_RERUN_DISABLE
control |= PSYCHO_STRBUF_CTRL_RRDIS;
#endif
#endif
upa_writeq(control, pbm->stc.strbuf_control);
pbm->stc.strbuf_enabled = 1;
}
static void psycho_pbm_init(struct pci_pbm_info *pbm,
struct platform_device *op, int is_pbm_a)
{
psycho_pbm_init_common(pbm, op, "PSYCHO", PBM_CHIP_TYPE_PSYCHO);
psycho_pbm_strbuf_init(pbm, is_pbm_a);
psycho_scan_bus(pbm, &op->dev);
}
static struct pci_pbm_info *psycho_find_sibling(u32 upa_portid)
{
struct pci_pbm_info *pbm;
for (pbm = pci_pbm_root; pbm; pbm = pbm->next) {
if (pbm->portid == upa_portid)
return pbm;
}
return NULL;
}
static int psycho_probe(struct platform_device *op)
{
const struct linux_prom64_registers *pr_regs;
struct device_node *dp = op->dev.of_node;
struct pci_pbm_info *pbm;
struct iommu *iommu;
int is_pbm_a, err;
u32 upa_portid;
upa_portid = of_getintprop_default(dp, "upa-portid", 0xff);
err = -ENOMEM;
pbm = kzalloc(sizeof(*pbm), GFP_KERNEL);
if (!pbm) {
printk(KERN_ERR PFX "Cannot allocate pci_pbm_info.\n");
goto out_err;
}
pbm->sibling = psycho_find_sibling(upa_portid);
if (pbm->sibling) {
iommu = pbm->sibling->iommu;
} else {
iommu = kzalloc(sizeof(struct iommu), GFP_KERNEL);
if (!iommu) {
printk(KERN_ERR PFX "Cannot allocate PBM iommu.\n");
goto out_free_controller;
}
}
pbm->iommu = iommu;
pbm->portid = upa_portid;
pr_regs = of_get_property(dp, "reg", NULL);
err = -ENODEV;
if (!pr_regs) {
printk(KERN_ERR PFX "No reg property.\n");
goto out_free_iommu;
}
is_pbm_a = ((pr_regs[0].phys_addr & 0x6000) == 0x2000);
pbm->controller_regs = pr_regs[2].phys_addr;
pbm->config_space = (pr_regs[2].phys_addr + PSYCHO_CONFIGSPACE);
if (is_pbm_a) {
pbm->pci_afsr = pbm->controller_regs + PSYCHO_PCI_AFSR_A;
pbm->pci_afar = pbm->controller_regs + PSYCHO_PCI_AFAR_A;
pbm->pci_csr = pbm->controller_regs + PSYCHO_PCIA_CTRL;
} else {
pbm->pci_afsr = pbm->controller_regs + PSYCHO_PCI_AFSR_B;
pbm->pci_afar = pbm->controller_regs + PSYCHO_PCI_AFAR_B;
pbm->pci_csr = pbm->controller_regs + PSYCHO_PCIB_CTRL;
}
psycho_controller_hwinit(pbm);
if (!pbm->sibling) {
err = psycho_iommu_init(pbm, 128, 0xc0000000,
0xffffffff, PSYCHO_CONTROL);
if (err)
goto out_free_iommu;
if (this_is_starfire)
starfire_hookup(pbm->portid);
}
psycho_pbm_init(pbm, op, is_pbm_a);
pbm->next = pci_pbm_root;
pci_pbm_root = pbm;
if (pbm->sibling)
pbm->sibling->sibling = pbm;
dev_set_drvdata(&op->dev, pbm);
return 0;
out_free_iommu:
if (!pbm->sibling)
kfree(pbm->iommu);
out_free_controller:
kfree(pbm);
out_err:
return err;
}
static int __init psycho_init(void)
{
return platform_driver_register(&psycho_driver);
}
