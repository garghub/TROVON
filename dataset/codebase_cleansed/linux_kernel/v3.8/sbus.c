void sbus_set_sbus64(struct device *dev, int bursts)
{
struct iommu *iommu = dev->archdata.iommu;
struct platform_device *op = to_platform_device(dev);
const struct linux_prom_registers *regs;
unsigned long cfg_reg;
int slot;
u64 val;
regs = of_get_property(op->dev.of_node, "reg", NULL);
if (!regs) {
printk(KERN_ERR "sbus_set_sbus64: Cannot find regs for %s\n",
op->dev.of_node->full_name);
return;
}
slot = regs->which_io;
cfg_reg = iommu->write_complete_reg;
switch (slot) {
case 0:
cfg_reg += 0x20UL;
break;
case 1:
cfg_reg += 0x28UL;
break;
case 2:
cfg_reg += 0x30UL;
break;
case 3:
cfg_reg += 0x38UL;
break;
case 13:
cfg_reg += 0x40UL;
break;
case 14:
cfg_reg += 0x48UL;
break;
case 15:
cfg_reg += 0x50UL;
break;
default:
return;
}
val = upa_readq(cfg_reg);
if (val & (1UL << 14UL)) {
return;
}
val |= (1UL << 14UL);
if (bursts & DMA_BURST8)
val |= (1UL << 1UL);
if (bursts & DMA_BURST16)
val |= (1UL << 2UL);
if (bursts & DMA_BURST32)
val |= (1UL << 3UL);
if (bursts & DMA_BURST64)
val |= (1UL << 4UL);
upa_writeq(val, cfg_reg);
}
static unsigned long sysio_imap_to_iclr(unsigned long imap)
{
unsigned long diff = SYSIO_ICLR_UNUSED0 - SYSIO_IMAP_SLOT0;
return imap + diff;
}
static unsigned int sbus_build_irq(struct platform_device *op, unsigned int ino)
{
struct iommu *iommu = op->dev.archdata.iommu;
unsigned long reg_base = iommu->write_complete_reg - 0x2000UL;
unsigned long imap, iclr;
int sbus_level = 0;
imap = sysio_irq_offsets[ino];
if (imap == ((unsigned long)-1)) {
prom_printf("get_irq_translations: Bad SYSIO INO[%x]\n",
ino);
prom_halt();
}
imap += reg_base;
if (ino >= 0x20) {
iclr = sysio_imap_to_iclr(imap);
} else {
int sbus_slot = (ino & 0x18)>>3;
sbus_level = ino & 0x7;
switch(sbus_slot) {
case 0:
iclr = reg_base + SYSIO_ICLR_SLOT0;
break;
case 1:
iclr = reg_base + SYSIO_ICLR_SLOT1;
break;
case 2:
iclr = reg_base + SYSIO_ICLR_SLOT2;
break;
default:
case 3:
iclr = reg_base + SYSIO_ICLR_SLOT3;
break;
}
iclr += ((unsigned long)sbus_level - 1UL) * 8UL;
}
return build_irq(sbus_level, iclr, imap);
}
static irqreturn_t sysio_ue_handler(int irq, void *dev_id)
{
struct platform_device *op = dev_id;
struct iommu *iommu = op->dev.archdata.iommu;
unsigned long reg_base = iommu->write_complete_reg - 0x2000UL;
unsigned long afsr_reg, afar_reg;
unsigned long afsr, afar, error_bits;
int reported, portid;
afsr_reg = reg_base + SYSIO_UE_AFSR;
afar_reg = reg_base + SYSIO_UE_AFAR;
afsr = upa_readq(afsr_reg);
afar = upa_readq(afar_reg);
error_bits = afsr &
(SYSIO_UEAFSR_PPIO | SYSIO_UEAFSR_PDRD | SYSIO_UEAFSR_PDWR |
SYSIO_UEAFSR_SPIO | SYSIO_UEAFSR_SDRD | SYSIO_UEAFSR_SDWR);
upa_writeq(error_bits, afsr_reg);
portid = of_getintprop_default(op->dev.of_node, "portid", -1);
printk("SYSIO[%x]: Uncorrectable ECC Error, primary error type[%s]\n",
portid,
(((error_bits & SYSIO_UEAFSR_PPIO) ?
"PIO" :
((error_bits & SYSIO_UEAFSR_PDRD) ?
"DVMA Read" :
((error_bits & SYSIO_UEAFSR_PDWR) ?
"DVMA Write" : "???")))));
printk("SYSIO[%x]: DOFF[%lx] SIZE[%lx] MID[%lx]\n",
portid,
(afsr & SYSIO_UEAFSR_DOFF) >> 45UL,
(afsr & SYSIO_UEAFSR_SIZE) >> 42UL,
(afsr & SYSIO_UEAFSR_MID) >> 37UL);
printk("SYSIO[%x]: AFAR[%016lx]\n", portid, afar);
printk("SYSIO[%x]: Secondary UE errors [", portid);
reported = 0;
if (afsr & SYSIO_UEAFSR_SPIO) {
reported++;
printk("(PIO)");
}
if (afsr & SYSIO_UEAFSR_SDRD) {
reported++;
printk("(DVMA Read)");
}
if (afsr & SYSIO_UEAFSR_SDWR) {
reported++;
printk("(DVMA Write)");
}
if (!reported)
printk("(none)");
printk("]\n");
return IRQ_HANDLED;
}
static irqreturn_t sysio_ce_handler(int irq, void *dev_id)
{
struct platform_device *op = dev_id;
struct iommu *iommu = op->dev.archdata.iommu;
unsigned long reg_base = iommu->write_complete_reg - 0x2000UL;
unsigned long afsr_reg, afar_reg;
unsigned long afsr, afar, error_bits;
int reported, portid;
afsr_reg = reg_base + SYSIO_CE_AFSR;
afar_reg = reg_base + SYSIO_CE_AFAR;
afsr = upa_readq(afsr_reg);
afar = upa_readq(afar_reg);
error_bits = afsr &
(SYSIO_CEAFSR_PPIO | SYSIO_CEAFSR_PDRD | SYSIO_CEAFSR_PDWR |
SYSIO_CEAFSR_SPIO | SYSIO_CEAFSR_SDRD | SYSIO_CEAFSR_SDWR);
upa_writeq(error_bits, afsr_reg);
portid = of_getintprop_default(op->dev.of_node, "portid", -1);
printk("SYSIO[%x]: Correctable ECC Error, primary error type[%s]\n",
portid,
(((error_bits & SYSIO_CEAFSR_PPIO) ?
"PIO" :
((error_bits & SYSIO_CEAFSR_PDRD) ?
"DVMA Read" :
((error_bits & SYSIO_CEAFSR_PDWR) ?
"DVMA Write" : "???")))));
printk("SYSIO[%x]: DOFF[%lx] ECC Syndrome[%lx] Size[%lx] MID[%lx]\n",
portid,
(afsr & SYSIO_CEAFSR_DOFF) >> 45UL,
(afsr & SYSIO_CEAFSR_ESYND) >> 48UL,
(afsr & SYSIO_CEAFSR_SIZE) >> 42UL,
(afsr & SYSIO_CEAFSR_MID) >> 37UL);
printk("SYSIO[%x]: AFAR[%016lx]\n", portid, afar);
printk("SYSIO[%x]: Secondary CE errors [", portid);
reported = 0;
if (afsr & SYSIO_CEAFSR_SPIO) {
reported++;
printk("(PIO)");
}
if (afsr & SYSIO_CEAFSR_SDRD) {
reported++;
printk("(DVMA Read)");
}
if (afsr & SYSIO_CEAFSR_SDWR) {
reported++;
printk("(DVMA Write)");
}
if (!reported)
printk("(none)");
printk("]\n");
return IRQ_HANDLED;
}
static irqreturn_t sysio_sbus_error_handler(int irq, void *dev_id)
{
struct platform_device *op = dev_id;
struct iommu *iommu = op->dev.archdata.iommu;
unsigned long afsr_reg, afar_reg, reg_base;
unsigned long afsr, afar, error_bits;
int reported, portid;
reg_base = iommu->write_complete_reg - 0x2000UL;
afsr_reg = reg_base + SYSIO_SBUS_AFSR;
afar_reg = reg_base + SYSIO_SBUS_AFAR;
afsr = upa_readq(afsr_reg);
afar = upa_readq(afar_reg);
error_bits = afsr &
(SYSIO_SBAFSR_PLE | SYSIO_SBAFSR_PTO | SYSIO_SBAFSR_PBERR |
SYSIO_SBAFSR_SLE | SYSIO_SBAFSR_STO | SYSIO_SBAFSR_SBERR);
upa_writeq(error_bits, afsr_reg);
portid = of_getintprop_default(op->dev.of_node, "portid", -1);
printk("SYSIO[%x]: SBUS Error, primary error type[%s] read(%d)\n",
portid,
(((error_bits & SYSIO_SBAFSR_PLE) ?
"Late PIO Error" :
((error_bits & SYSIO_SBAFSR_PTO) ?
"Time Out" :
((error_bits & SYSIO_SBAFSR_PBERR) ?
"Error Ack" : "???")))),
(afsr & SYSIO_SBAFSR_RD) ? 1 : 0);
printk("SYSIO[%x]: size[%lx] MID[%lx]\n",
portid,
(afsr & SYSIO_SBAFSR_SIZE) >> 42UL,
(afsr & SYSIO_SBAFSR_MID) >> 37UL);
printk("SYSIO[%x]: AFAR[%016lx]\n", portid, afar);
printk("SYSIO[%x]: Secondary SBUS errors [", portid);
reported = 0;
if (afsr & SYSIO_SBAFSR_SLE) {
reported++;
printk("(Late PIO Error)");
}
if (afsr & SYSIO_SBAFSR_STO) {
reported++;
printk("(Time Out)");
}
if (afsr & SYSIO_SBAFSR_SBERR) {
reported++;
printk("(Error Ack)");
}
if (!reported)
printk("(none)");
printk("]\n");
return IRQ_HANDLED;
}
static void __init sysio_register_error_handlers(struct platform_device *op)
{
struct iommu *iommu = op->dev.archdata.iommu;
unsigned long reg_base = iommu->write_complete_reg - 0x2000UL;
unsigned int irq;
u64 control;
int portid;
portid = of_getintprop_default(op->dev.of_node, "portid", -1);
irq = sbus_build_irq(op, SYSIO_UE_INO);
if (request_irq(irq, sysio_ue_handler, 0,
"SYSIO_UE", op) < 0) {
prom_printf("SYSIO[%x]: Cannot register UE interrupt.\n",
portid);
prom_halt();
}
irq = sbus_build_irq(op, SYSIO_CE_INO);
if (request_irq(irq, sysio_ce_handler, 0,
"SYSIO_CE", op) < 0) {
prom_printf("SYSIO[%x]: Cannot register CE interrupt.\n",
portid);
prom_halt();
}
irq = sbus_build_irq(op, SYSIO_SBUSERR_INO);
if (request_irq(irq, sysio_sbus_error_handler, 0,
"SYSIO_SBERR", op) < 0) {
prom_printf("SYSIO[%x]: Cannot register SBUS Error interrupt.\n",
portid);
prom_halt();
}
upa_writeq((SYSIO_ECNTRL_ECCEN |
SYSIO_ECNTRL_UEEN |
SYSIO_ECNTRL_CEEN),
reg_base + ECC_CONTROL);
control = upa_readq(iommu->write_complete_reg);
control |= 0x100UL;
upa_writeq(control, iommu->write_complete_reg);
}
static void __init sbus_iommu_init(struct platform_device *op)
{
const struct linux_prom64_registers *pr;
struct device_node *dp = op->dev.of_node;
struct iommu *iommu;
struct strbuf *strbuf;
unsigned long regs, reg_base;
int i, portid;
u64 control;
pr = of_get_property(dp, "reg", NULL);
if (!pr) {
prom_printf("sbus_iommu_init: Cannot map SYSIO "
"control registers.\n");
prom_halt();
}
regs = pr->phys_addr;
iommu = kzalloc(sizeof(*iommu), GFP_ATOMIC);
strbuf = kzalloc(sizeof(*strbuf), GFP_ATOMIC);
if (!iommu || !strbuf)
goto fatal_memory_error;
op->dev.archdata.iommu = iommu;
op->dev.archdata.stc = strbuf;
op->dev.archdata.numa_node = -1;
reg_base = regs + SYSIO_IOMMUREG_BASE;
iommu->iommu_control = reg_base + IOMMU_CONTROL;
iommu->iommu_tsbbase = reg_base + IOMMU_TSBBASE;
iommu->iommu_flush = reg_base + IOMMU_FLUSH;
iommu->iommu_tags = iommu->iommu_control +
(IOMMU_TAGDIAG - IOMMU_CONTROL);
reg_base = regs + SYSIO_STRBUFREG_BASE;
strbuf->strbuf_control = reg_base + STRBUF_CONTROL;
strbuf->strbuf_pflush = reg_base + STRBUF_PFLUSH;
strbuf->strbuf_fsync = reg_base + STRBUF_FSYNC;
strbuf->strbuf_enabled = 1;
strbuf->strbuf_flushflag = (volatile unsigned long *)
((((unsigned long)&strbuf->__flushflag_buf[0])
+ 63UL)
& ~63UL);
strbuf->strbuf_flushflag_pa = (unsigned long)
__pa(strbuf->strbuf_flushflag);
iommu->write_complete_reg = regs + 0x2000UL;
portid = of_getintprop_default(op->dev.of_node, "portid", -1);
printk(KERN_INFO "SYSIO: UPA portID %x, at %016lx\n",
portid, regs);
if (iommu_table_init(iommu, IO_TSB_SIZE, MAP_BASE, 0xffffffff, -1))
goto fatal_memory_error;
control = upa_readq(iommu->iommu_control);
control = ((7UL << 16UL) |
(0UL << 2UL) |
(1UL << 1UL) |
(1UL << 0UL));
upa_writeq(control, iommu->iommu_control);
for (i = 0; i < 16; i++) {
unsigned long dram, tag;
dram = iommu->iommu_control + (IOMMU_DRAMDIAG - IOMMU_CONTROL);
tag = iommu->iommu_control + (IOMMU_TAGDIAG - IOMMU_CONTROL);
dram += (unsigned long)i * 8UL;
tag += (unsigned long)i * 8UL;
upa_writeq(0, dram);
upa_writeq(0, tag);
}
upa_readq(iommu->write_complete_reg);
upa_writeq(__pa(iommu->page_table), iommu->iommu_tsbbase);
control = (1UL << 1UL) | (1UL << 0UL);
upa_writeq(control, strbuf->strbuf_control);
for (i = 0; i < 16; i++) {
unsigned long ptag, ltag;
ptag = strbuf->strbuf_control +
(STRBUF_PTAGDIAG - STRBUF_CONTROL);
ltag = strbuf->strbuf_control +
(STRBUF_LTAGDIAG - STRBUF_CONTROL);
ptag += (unsigned long)i * 8UL;
ltag += (unsigned long)i * 8UL;
upa_writeq(0UL, ptag);
upa_writeq(0UL, ltag);
}
control = upa_readq(iommu->write_complete_reg);
control |= 0x3fUL;
upa_writeq(control, iommu->write_complete_reg);
if (this_is_starfire)
starfire_hookup(portid);
sysio_register_error_handlers(op);
return;
fatal_memory_error:
kfree(iommu);
kfree(strbuf);
prom_printf("sbus_iommu_init: Fatal memory allocation error.\n");
}
static int __init sbus_init(void)
{
struct device_node *dp;
for_each_node_by_name(dp, "sbus") {
struct platform_device *op = of_find_device_by_node(dp);
sbus_iommu_init(op);
of_propagate_archdata(op);
}
return 0;
}
