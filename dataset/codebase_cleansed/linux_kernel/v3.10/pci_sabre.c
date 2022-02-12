static irqreturn_t sabre_ue_intr(int irq, void *dev_id)
{
struct pci_pbm_info *pbm = dev_id;
unsigned long afsr_reg = pbm->controller_regs + SABRE_UE_AFSR;
unsigned long afar_reg = pbm->controller_regs + SABRE_UECE_AFAR;
unsigned long afsr, afar, error_bits;
int reported;
afar = upa_readq(afar_reg);
afsr = upa_readq(afsr_reg);
error_bits = afsr &
(SABRE_UEAFSR_PDRD | SABRE_UEAFSR_PDWR |
SABRE_UEAFSR_SDRD | SABRE_UEAFSR_SDWR |
SABRE_UEAFSR_SDTE | SABRE_UEAFSR_PDTE);
if (!error_bits)
return IRQ_NONE;
upa_writeq(error_bits, afsr_reg);
printk("%s: Uncorrectable Error, primary error type[%s%s]\n",
pbm->name,
((error_bits & SABRE_UEAFSR_PDRD) ?
"DMA Read" :
((error_bits & SABRE_UEAFSR_PDWR) ?
"DMA Write" : "???")),
((error_bits & SABRE_UEAFSR_PDTE) ?
":Translation Error" : ""));
printk("%s: bytemask[%04lx] dword_offset[%lx] was_block(%d)\n",
pbm->name,
(afsr & SABRE_UEAFSR_BMSK) >> 32UL,
(afsr & SABRE_UEAFSR_OFF) >> 29UL,
((afsr & SABRE_UEAFSR_BLK) ? 1 : 0));
printk("%s: UE AFAR [%016lx]\n", pbm->name, afar);
printk("%s: UE Secondary errors [", pbm->name);
reported = 0;
if (afsr & SABRE_UEAFSR_SDRD) {
reported++;
printk("(DMA Read)");
}
if (afsr & SABRE_UEAFSR_SDWR) {
reported++;
printk("(DMA Write)");
}
if (afsr & SABRE_UEAFSR_SDTE) {
reported++;
printk("(Translation Error)");
}
if (!reported)
printk("(none)");
printk("]\n");
psycho_check_iommu_error(pbm, afsr, afar, UE_ERR);
return IRQ_HANDLED;
}
static irqreturn_t sabre_ce_intr(int irq, void *dev_id)
{
struct pci_pbm_info *pbm = dev_id;
unsigned long afsr_reg = pbm->controller_regs + SABRE_CE_AFSR;
unsigned long afar_reg = pbm->controller_regs + SABRE_UECE_AFAR;
unsigned long afsr, afar, error_bits;
int reported;
afar = upa_readq(afar_reg);
afsr = upa_readq(afsr_reg);
error_bits = afsr &
(SABRE_CEAFSR_PDRD | SABRE_CEAFSR_PDWR |
SABRE_CEAFSR_SDRD | SABRE_CEAFSR_SDWR);
if (!error_bits)
return IRQ_NONE;
upa_writeq(error_bits, afsr_reg);
printk("%s: Correctable Error, primary error type[%s]\n",
pbm->name,
((error_bits & SABRE_CEAFSR_PDRD) ?
"DMA Read" :
((error_bits & SABRE_CEAFSR_PDWR) ?
"DMA Write" : "???")));
printk("%s: syndrome[%02lx] bytemask[%04lx] dword_offset[%lx] "
"was_block(%d)\n",
pbm->name,
(afsr & SABRE_CEAFSR_ESYND) >> 48UL,
(afsr & SABRE_CEAFSR_BMSK) >> 32UL,
(afsr & SABRE_CEAFSR_OFF) >> 29UL,
((afsr & SABRE_CEAFSR_BLK) ? 1 : 0));
printk("%s: CE AFAR [%016lx]\n", pbm->name, afar);
printk("%s: CE Secondary errors [", pbm->name);
reported = 0;
if (afsr & SABRE_CEAFSR_SDRD) {
reported++;
printk("(DMA Read)");
}
if (afsr & SABRE_CEAFSR_SDWR) {
reported++;
printk("(DMA Write)");
}
if (!reported)
printk("(none)");
printk("]\n");
return IRQ_HANDLED;
}
static void sabre_register_error_handlers(struct pci_pbm_info *pbm)
{
struct device_node *dp = pbm->op->dev.of_node;
struct platform_device *op;
unsigned long base = pbm->controller_regs;
u64 tmp;
int err;
if (pbm->chip_type == PBM_CHIP_TYPE_SABRE)
dp = dp->parent;
op = of_find_device_by_node(dp);
if (!op)
return;
if (op->archdata.num_irqs < 4)
return;
upa_writeq((SABRE_UEAFSR_PDRD | SABRE_UEAFSR_PDWR |
SABRE_UEAFSR_SDRD | SABRE_UEAFSR_SDWR |
SABRE_UEAFSR_SDTE | SABRE_UEAFSR_PDTE),
base + SABRE_UE_AFSR);
err = request_irq(op->archdata.irqs[1], sabre_ue_intr, 0, "SABRE_UE", pbm);
if (err)
printk(KERN_WARNING "%s: Couldn't register UE, err=%d.\n",
pbm->name, err);
upa_writeq((SABRE_CEAFSR_PDRD | SABRE_CEAFSR_PDWR |
SABRE_CEAFSR_SDRD | SABRE_CEAFSR_SDWR),
base + SABRE_CE_AFSR);
err = request_irq(op->archdata.irqs[2], sabre_ce_intr, 0, "SABRE_CE", pbm);
if (err)
printk(KERN_WARNING "%s: Couldn't register CE, err=%d.\n",
pbm->name, err);
err = request_irq(op->archdata.irqs[0], psycho_pcierr_intr, 0,
"SABRE_PCIERR", pbm);
if (err)
printk(KERN_WARNING "%s: Couldn't register PCIERR, err=%d.\n",
pbm->name, err);
tmp = upa_readq(base + SABRE_PCICTRL);
tmp |= SABRE_PCICTRL_ERREN;
upa_writeq(tmp, base + SABRE_PCICTRL);
}
static void apb_init(struct pci_bus *sabre_bus)
{
struct pci_dev *pdev;
list_for_each_entry(pdev, &sabre_bus->devices, bus_list) {
if (pdev->vendor == PCI_VENDOR_ID_SUN &&
pdev->device == PCI_DEVICE_ID_SUN_SIMBA) {
u16 word16;
pci_read_config_word(pdev, PCI_COMMAND, &word16);
word16 |= PCI_COMMAND_SERR | PCI_COMMAND_PARITY |
PCI_COMMAND_MASTER | PCI_COMMAND_MEMORY |
PCI_COMMAND_IO;
pci_write_config_word(pdev, PCI_COMMAND, word16);
pci_write_config_word(pdev, PCI_STATUS, 0xffff);
pci_write_config_word(pdev, PCI_SEC_STATUS, 0xffff);
pci_write_config_byte(pdev, PCI_LATENCY_TIMER, 64);
pci_write_config_byte(pdev, PCI_SEC_LATENCY_TIMER, 64);
pci_write_config_byte(pdev, PCI_BRIDGE_CONTROL,
(PCI_BRIDGE_CTL_PARITY |
PCI_BRIDGE_CTL_SERR |
PCI_BRIDGE_CTL_MASTER_ABORT));
}
}
}
static void sabre_scan_bus(struct pci_pbm_info *pbm, struct device *parent)
{
static int once;
if (hummingbird_p)
pbm->is_66mhz_capable = 1;
else
pbm->is_66mhz_capable = 0;
if (once != 0) {
printk(KERN_ERR PFX "Multiple controllers unsupported.\n");
return;
}
once++;
pbm->pci_bus = pci_scan_one_pbm(pbm, parent);
if (!pbm->pci_bus)
return;
sabre_root_bus = pbm->pci_bus;
apb_init(pbm->pci_bus);
sabre_register_error_handlers(pbm);
}
static void sabre_pbm_init(struct pci_pbm_info *pbm,
struct platform_device *op)
{
psycho_pbm_init_common(pbm, op, "SABRE", PBM_CHIP_TYPE_SABRE);
pbm->pci_afsr = pbm->controller_regs + SABRE_PIOAFSR;
pbm->pci_afar = pbm->controller_regs + SABRE_PIOAFAR;
pbm->pci_csr = pbm->controller_regs + SABRE_PCICTRL;
sabre_scan_bus(pbm, &op->dev);
}
static int sabre_probe(struct platform_device *op)
{
const struct of_device_id *match;
const struct linux_prom64_registers *pr_regs;
struct device_node *dp = op->dev.of_node;
struct pci_pbm_info *pbm;
u32 upa_portid, dma_mask;
struct iommu *iommu;
int tsbsize, err;
const u32 *vdma;
u64 clear_irq;
match = of_match_device(sabre_match, &op->dev);
hummingbird_p = match && (match->data != NULL);
if (!hummingbird_p) {
struct device_node *cpu_dp;
for_each_node_by_type(cpu_dp, "cpu") {
if (!strcmp(cpu_dp->name, "SUNW,UltraSPARC-IIe"))
hummingbird_p = 1;
}
}
err = -ENOMEM;
pbm = kzalloc(sizeof(*pbm), GFP_KERNEL);
if (!pbm) {
printk(KERN_ERR PFX "Cannot allocate pci_pbm_info.\n");
goto out_err;
}
iommu = kzalloc(sizeof(*iommu), GFP_KERNEL);
if (!iommu) {
printk(KERN_ERR PFX "Cannot allocate PBM iommu.\n");
goto out_free_controller;
}
pbm->iommu = iommu;
upa_portid = of_getintprop_default(dp, "upa-portid", 0xff);
pbm->portid = upa_portid;
pr_regs = of_get_property(dp, "reg", NULL);
err = -ENODEV;
if (!pr_regs) {
printk(KERN_ERR PFX "No reg property\n");
goto out_free_iommu;
}
pbm->controller_regs = pr_regs[0].phys_addr;
for (clear_irq = SABRE_ICLR_A_SLOT0; clear_irq < SABRE_ICLR_B_SLOT0 + 0x80; clear_irq += 8)
upa_writeq(0x0UL, pbm->controller_regs + clear_irq);
for (clear_irq = SABRE_ICLR_SCSI; clear_irq < SABRE_ICLR_SCSI + 0x80; clear_irq += 8)
upa_writeq(0x0UL, pbm->controller_regs + clear_irq);
upa_writeq((SABRE_PCICTRL_MRLEN | SABRE_PCICTRL_SERR |
SABRE_PCICTRL_ARBPARK | SABRE_PCICTRL_AEN),
pbm->controller_regs + SABRE_PCICTRL);
pbm->config_space = pbm->controller_regs + SABRE_CONFIGSPACE;
vdma = of_get_property(dp, "virtual-dma", NULL);
if (!vdma) {
printk(KERN_ERR PFX "No virtual-dma property\n");
goto out_free_iommu;
}
dma_mask = vdma[0];
switch(vdma[1]) {
case 0x20000000:
dma_mask |= 0x1fffffff;
tsbsize = 64;
break;
case 0x40000000:
dma_mask |= 0x3fffffff;
tsbsize = 128;
break;
case 0x80000000:
dma_mask |= 0x7fffffff;
tsbsize = 128;
break;
default:
printk(KERN_ERR PFX "Strange virtual-dma size.\n");
goto out_free_iommu;
}
err = psycho_iommu_init(pbm, tsbsize, vdma[0], dma_mask, SABRE_WRSYNC);
if (err)
goto out_free_iommu;
sabre_pbm_init(pbm, op);
pbm->next = pci_pbm_root;
pci_pbm_root = pbm;
dev_set_drvdata(&op->dev, pbm);
return 0;
out_free_iommu:
kfree(pbm->iommu);
out_free_controller:
kfree(pbm);
out_err:
return err;
}
static int __init sabre_init(void)
{
return platform_driver_register(&sabre_driver);
}
