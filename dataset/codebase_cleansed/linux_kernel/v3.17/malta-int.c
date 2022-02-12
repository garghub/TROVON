static inline int mips_pcibios_iack(void)
{
int irq;
switch (mips_revision_sconid) {
case MIPS_REVISION_SCON_SOCIT:
case MIPS_REVISION_SCON_ROCIT:
case MIPS_REVISION_SCON_SOCITSC:
case MIPS_REVISION_SCON_SOCITSCP:
MSC_READ(MSC01_PCI_IACK, irq);
irq &= 0xff;
break;
case MIPS_REVISION_SCON_GT64120:
irq = GT_READ(GT_PCI0_IACK_OFS);
irq &= 0xff;
break;
case MIPS_REVISION_SCON_BONITO:
BONITO_PCIMAP_CFG = 0x20000;
(void) BONITO_PCIMAP_CFG;
iob();
irq = __raw_readl((u32 *)_pcictrl_bonito_pcicfg);
iob();
irq &= 0xff;
BONITO_PCIMAP_CFG = 0;
break;
default:
pr_emerg("Unknown system controller.\n");
return -1;
}
return irq;
}
static inline int get_int(void)
{
unsigned long flags;
int irq;
raw_spin_lock_irqsave(&mips_irq_lock, flags);
irq = mips_pcibios_iack();
raw_spin_unlock_irqrestore(&mips_irq_lock, flags);
return irq;
}
static void malta_hw0_irqdispatch(void)
{
int irq;
irq = get_int();
if (irq < 0) {
return;
}
do_IRQ(MALTA_INT_BASE + irq);
#ifdef CONFIG_MIPS_VPE_APSP_API_MT
if (aprp_hook)
aprp_hook();
#endif
}
static void malta_ipi_irqdispatch(void)
{
#ifdef CONFIG_MIPS_GIC_IPI
unsigned long irq;
DECLARE_BITMAP(pending, GIC_NUM_INTRS);
gic_get_int_mask(pending, ipi_ints);
irq = find_first_bit(pending, GIC_NUM_INTRS);
while (irq < GIC_NUM_INTRS) {
do_IRQ(MIPS_GIC_IRQ_BASE + irq);
irq = find_next_bit(pending, GIC_NUM_INTRS, irq + 1);
}
#endif
if (gic_compare_int())
do_IRQ(MIPS_GIC_IRQ_BASE);
}
static void corehi_irqdispatch(void)
{
unsigned int intedge, intsteer, pcicmd, pcibadaddr;
unsigned int pcimstat, intisr, inten, intpol;
unsigned int intrcause, datalo, datahi;
struct pt_regs *regs = get_irq_regs();
pr_emerg("CoreHI interrupt, shouldn't happen, we die here!\n");
pr_emerg("epc : %08lx\nStatus: %08lx\n"
"Cause : %08lx\nbadVaddr : %08lx\n",
regs->cp0_epc, regs->cp0_status,
regs->cp0_cause, regs->cp0_badvaddr);
switch (mips_revision_sconid) {
case MIPS_REVISION_SCON_SOCIT:
case MIPS_REVISION_SCON_ROCIT:
case MIPS_REVISION_SCON_SOCITSC:
case MIPS_REVISION_SCON_SOCITSCP:
ll_msc_irq();
break;
case MIPS_REVISION_SCON_GT64120:
intrcause = GT_READ(GT_INTRCAUSE_OFS);
datalo = GT_READ(GT_CPUERR_ADDRLO_OFS);
datahi = GT_READ(GT_CPUERR_ADDRHI_OFS);
pr_emerg("GT_INTRCAUSE = %08x\n", intrcause);
pr_emerg("GT_CPUERR_ADDR = %02x%08x\n",
datahi, datalo);
break;
case MIPS_REVISION_SCON_BONITO:
pcibadaddr = BONITO_PCIBADADDR;
pcimstat = BONITO_PCIMSTAT;
intisr = BONITO_INTISR;
inten = BONITO_INTEN;
intpol = BONITO_INTPOL;
intedge = BONITO_INTEDGE;
intsteer = BONITO_INTSTEER;
pcicmd = BONITO_PCICMD;
pr_emerg("BONITO_INTISR = %08x\n", intisr);
pr_emerg("BONITO_INTEN = %08x\n", inten);
pr_emerg("BONITO_INTPOL = %08x\n", intpol);
pr_emerg("BONITO_INTEDGE = %08x\n", intedge);
pr_emerg("BONITO_INTSTEER = %08x\n", intsteer);
pr_emerg("BONITO_PCICMD = %08x\n", pcicmd);
pr_emerg("BONITO_PCIBADADDR = %08x\n", pcibadaddr);
pr_emerg("BONITO_PCIMSTAT = %08x\n", pcimstat);
break;
}
die("CoreHi interrupt", regs);
}
static inline int clz(unsigned long x)
{
__asm__(
" .set push \n"
" .set mips32 \n"
" clz %0, %1 \n"
" .set pop \n"
: "=r" (x)
: "r" (x));
return x;
}
static inline unsigned int irq_ffs(unsigned int pending)
{
#if defined(CONFIG_CPU_MIPS32) || defined(CONFIG_CPU_MIPS64)
return -clz(pending) + 31 - CAUSEB_IP;
#else
unsigned int a0 = 7;
unsigned int t0;
t0 = pending & 0xf000;
t0 = t0 < 1;
t0 = t0 << 2;
a0 = a0 - t0;
pending = pending << t0;
t0 = pending & 0xc000;
t0 = t0 < 1;
t0 = t0 << 1;
a0 = a0 - t0;
pending = pending << t0;
t0 = pending & 0x8000;
t0 = t0 < 1;
a0 = a0 - t0;
return a0;
#endif
}
asmlinkage void plat_irq_dispatch(void)
{
unsigned int pending = read_c0_cause() & read_c0_status() & ST0_IM;
int irq;
if (unlikely(!pending)) {
spurious_interrupt();
return;
}
irq = irq_ffs(pending);
if (irq == MIPSCPU_INT_I8259A)
malta_hw0_irqdispatch();
else if (gic_present && ((1 << irq) & ipi_map[smp_processor_id()]))
malta_ipi_irqdispatch();
else
do_IRQ(MIPS_CPU_IRQ_BASE + irq);
}
static void ipi_resched_dispatch(void)
{
do_IRQ(MIPS_CPU_IRQ_BASE + MIPS_CPU_IPI_RESCHED_IRQ);
}
static void ipi_call_dispatch(void)
{
do_IRQ(MIPS_CPU_IRQ_BASE + MIPS_CPU_IPI_CALL_IRQ);
}
static irqreturn_t ipi_resched_interrupt(int irq, void *dev_id)
{
#ifdef CONFIG_MIPS_VPE_APSP_API_CMP
if (aprp_hook)
aprp_hook();
#endif
scheduler_ipi();
return IRQ_HANDLED;
}
static irqreturn_t ipi_call_interrupt(int irq, void *dev_id)
{
smp_call_function_interrupt();
return IRQ_HANDLED;
}
unsigned int plat_ipi_call_int_xlate(unsigned int cpu)
{
return GIC_CALL_INT(cpu);
}
unsigned int plat_ipi_resched_int_xlate(unsigned int cpu)
{
return GIC_RESCHED_INT(cpu);
}
static void __init fill_ipi_map1(int baseintr, int cpu, int cpupin)
{
int intr = baseintr + cpu;
gic_intr_map[intr].cpunum = cpu;
gic_intr_map[intr].pin = cpupin;
gic_intr_map[intr].polarity = GIC_POL_POS;
gic_intr_map[intr].trigtype = GIC_TRIG_EDGE;
gic_intr_map[intr].flags = 0;
ipi_map[cpu] |= (1 << (cpupin + 2));
bitmap_set(ipi_ints, intr, 1);
}
static void __init fill_ipi_map(void)
{
int cpu;
for (cpu = 0; cpu < nr_cpu_ids; cpu++) {
fill_ipi_map1(gic_resched_int_base, cpu, GIC_CPU_INT1);
fill_ipi_map1(gic_call_int_base, cpu, GIC_CPU_INT2);
}
}
void __init arch_init_ipiirq(int irq, struct irqaction *action)
{
setup_irq(irq, action);
irq_set_handler(irq, handle_percpu_irq);
}
void __init arch_init_irq(void)
{
init_i8259_irqs();
if (!cpu_has_veic)
mips_cpu_irq_init();
if (mips_cm_present()) {
write_gcr_gic_base(GIC_BASE_ADDR | CM_GCR_GIC_BASE_GICEN_MSK);
gic_present = 1;
} else {
if (mips_revision_sconid == MIPS_REVISION_SCON_ROCIT) {
_msc01_biu_base = (unsigned long)
ioremap_nocache(MSC01_BIU_REG_BASE,
MSC01_BIU_ADDRSPACE_SZ);
gic_present = (REG(_msc01_biu_base, MSC01_SC_CFG) &
MSC01_SC_CFG_GICPRES_MSK) >>
MSC01_SC_CFG_GICPRES_SHF;
}
}
if (gic_present)
pr_debug("GIC present\n");
switch (mips_revision_sconid) {
case MIPS_REVISION_SCON_SOCIT:
case MIPS_REVISION_SCON_ROCIT:
if (cpu_has_veic)
init_msc_irqs(MIPS_MSC01_IC_REG_BASE,
MSC01E_INT_BASE, msc_eicirqmap,
msc_nr_eicirqs);
else
init_msc_irqs(MIPS_MSC01_IC_REG_BASE,
MSC01C_INT_BASE, msc_irqmap,
msc_nr_irqs);
break;
case MIPS_REVISION_SCON_SOCITSC:
case MIPS_REVISION_SCON_SOCITSCP:
if (cpu_has_veic)
init_msc_irqs(MIPS_SOCITSC_IC_REG_BASE,
MSC01E_INT_BASE, msc_eicirqmap,
msc_nr_eicirqs);
else
init_msc_irqs(MIPS_SOCITSC_IC_REG_BASE,
MSC01C_INT_BASE, msc_irqmap,
msc_nr_irqs);
}
if (cpu_has_veic) {
set_vi_handler(MSC01E_INT_I8259A, malta_hw0_irqdispatch);
set_vi_handler(MSC01E_INT_COREHI, corehi_irqdispatch);
setup_irq(MSC01E_INT_BASE+MSC01E_INT_I8259A, &i8259irq);
setup_irq(MSC01E_INT_BASE+MSC01E_INT_COREHI, &corehi_irqaction);
} else if (cpu_has_vint) {
set_vi_handler(MIPSCPU_INT_I8259A, malta_hw0_irqdispatch);
set_vi_handler(MIPSCPU_INT_COREHI, corehi_irqdispatch);
setup_irq(MIPS_CPU_IRQ_BASE+MIPSCPU_INT_I8259A, &i8259irq);
setup_irq(MIPS_CPU_IRQ_BASE+MIPSCPU_INT_COREHI,
&corehi_irqaction);
} else {
setup_irq(MIPS_CPU_IRQ_BASE+MIPSCPU_INT_I8259A, &i8259irq);
setup_irq(MIPS_CPU_IRQ_BASE+MIPSCPU_INT_COREHI,
&corehi_irqaction);
}
if (gic_present) {
int i;
#if defined(CONFIG_MIPS_GIC_IPI)
gic_call_int_base = GIC_NUM_INTRS -
(NR_CPUS - nr_cpu_ids) * 2 - nr_cpu_ids;
gic_resched_int_base = gic_call_int_base - nr_cpu_ids;
fill_ipi_map();
#endif
gic_init(GIC_BASE_ADDR, GIC_ADDRSPACE_SZ, gic_intr_map,
ARRAY_SIZE(gic_intr_map), MIPS_GIC_IRQ_BASE);
if (!mips_cm_present()) {
i = REG(_msc01_biu_base, MSC01_SC_CFG);
REG(_msc01_biu_base, MSC01_SC_CFG) =
(i | (0x1 << MSC01_SC_CFG_GICENA_SHF));
pr_debug("GIC Enabled\n");
}
#if defined(CONFIG_MIPS_GIC_IPI)
if (cpu_has_vint) {
set_vi_handler(MIPSCPU_INT_IPI0, malta_ipi_irqdispatch);
set_vi_handler(MIPSCPU_INT_IPI1, malta_ipi_irqdispatch);
}
pr_info("CPU%d: status register was %08x\n",
smp_processor_id(), read_c0_status());
write_c0_status(read_c0_status() | STATUSF_IP3 | STATUSF_IP4);
pr_info("CPU%d: status register now %08x\n",
smp_processor_id(), read_c0_status());
write_c0_status(0x1100dc00);
pr_info("CPU%d: status register frc %08x\n",
smp_processor_id(), read_c0_status());
for (i = 0; i < nr_cpu_ids; i++) {
arch_init_ipiirq(MIPS_GIC_IRQ_BASE +
GIC_RESCHED_INT(i), &irq_resched);
arch_init_ipiirq(MIPS_GIC_IRQ_BASE +
GIC_CALL_INT(i), &irq_call);
}
#endif
} else {
#if defined(CONFIG_MIPS_MT_SMP)
if (cpu_has_veic) {
set_vi_handler (MSC01E_INT_SW0, ipi_resched_dispatch);
set_vi_handler (MSC01E_INT_SW1, ipi_call_dispatch);
cpu_ipi_resched_irq = MSC01E_INT_SW0;
cpu_ipi_call_irq = MSC01E_INT_SW1;
} else {
if (cpu_has_vint) {
set_vi_handler (MIPS_CPU_IPI_RESCHED_IRQ,
ipi_resched_dispatch);
set_vi_handler (MIPS_CPU_IPI_CALL_IRQ,
ipi_call_dispatch);
}
cpu_ipi_resched_irq = MIPS_CPU_IRQ_BASE +
MIPS_CPU_IPI_RESCHED_IRQ;
cpu_ipi_call_irq = MIPS_CPU_IRQ_BASE +
MIPS_CPU_IPI_CALL_IRQ;
}
arch_init_ipiirq(cpu_ipi_resched_irq, &irq_resched);
arch_init_ipiirq(cpu_ipi_call_irq, &irq_call);
#endif
}
}
void malta_be_init(void)
{
}
int malta_be_handler(struct pt_regs *regs, int is_fixup)
{
int retval = is_fixup ? MIPS_BE_FIXUP : MIPS_BE_FATAL;
if (mips_cm_present()) {
unsigned long cm_error = read_gcr_error_cause();
unsigned long cm_addr = read_gcr_error_addr();
unsigned long cm_other = read_gcr_error_mult();
unsigned long cause, ocause;
char buf[256];
cause = cm_error & CM_GCR_ERROR_CAUSE_ERRTYPE_MSK;
if (cause != 0) {
cause >>= CM_GCR_ERROR_CAUSE_ERRTYPE_SHF;
if (cause < 16) {
unsigned long cca_bits = (cm_error >> 15) & 7;
unsigned long tr_bits = (cm_error >> 12) & 7;
unsigned long cmd_bits = (cm_error >> 7) & 0x1f;
unsigned long stag_bits = (cm_error >> 3) & 15;
unsigned long sport_bits = (cm_error >> 0) & 7;
snprintf(buf, sizeof(buf),
"CCA=%lu TR=%s MCmd=%s STag=%lu "
"SPort=%lu\n",
cca_bits, tr[tr_bits], mcmd[cmd_bits],
stag_bits, sport_bits);
} else {
unsigned long c3_bits = (cm_error >> 18) & 7;
unsigned long c2_bits = (cm_error >> 15) & 7;
unsigned long c1_bits = (cm_error >> 12) & 7;
unsigned long c0_bits = (cm_error >> 9) & 7;
unsigned long sc_bit = (cm_error >> 8) & 1;
unsigned long cmd_bits = (cm_error >> 3) & 0x1f;
unsigned long sport_bits = (cm_error >> 0) & 7;
snprintf(buf, sizeof(buf),
"C3=%s C2=%s C1=%s C0=%s SC=%s "
"MCmd=%s SPort=%lu\n",
core[c3_bits], core[c2_bits],
core[c1_bits], core[c0_bits],
sc_bit ? "True" : "False",
mcmd[cmd_bits], sport_bits);
}
ocause = (cm_other & CM_GCR_ERROR_MULT_ERR2ND_MSK) >>
CM_GCR_ERROR_MULT_ERR2ND_SHF;
pr_err("CM_ERROR=%08lx %s <%s>\n", cm_error,
causes[cause], buf);
pr_err("CM_ADDR =%08lx\n", cm_addr);
pr_err("CM_OTHER=%08lx %s\n", cm_other, causes[ocause]);
write_gcr_error_cause(0);
}
}
return retval;
}
void gic_enable_interrupt(int irq_vec)
{
GIC_SET_INTR_MASK(irq_vec);
}
void gic_disable_interrupt(int irq_vec)
{
GIC_CLR_INTR_MASK(irq_vec);
}
void gic_irq_ack(struct irq_data *d)
{
int irq = (d->irq - gic_irq_base);
GIC_CLR_INTR_MASK(irq);
if (gic_irq_flags[irq] & GIC_TRIG_EDGE)
GICWRITE(GIC_REG(SHARED, GIC_SH_WEDGE), irq);
}
void gic_finish_irq(struct irq_data *d)
{
GIC_SET_INTR_MASK(d->irq - gic_irq_base);
}
void __init gic_platform_init(int irqs, struct irq_chip *irq_controller)
{
int i;
for (i = gic_irq_base; i < (gic_irq_base + irqs); i++)
irq_set_chip(i, irq_controller);
}
