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
static irqreturn_t corehi_handler(int irq, void *dev_id)
{
corehi_irqdispatch();
return IRQ_HANDLED;
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
generic_smp_call_function_interrupt();
return IRQ_HANDLED;
}
void __init arch_init_ipiirq(int irq, struct irqaction *action)
{
setup_irq(irq, action);
irq_set_handler(irq, handle_percpu_irq);
}
void __init arch_init_irq(void)
{
int corehi_irq;
i8259_set_poll(mips_pcibios_iack);
irqchip_init();
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
if (gic_present) {
corehi_irq = MIPS_CPU_IRQ_BASE + MIPSCPU_INT_COREHI;
} else {
#if defined(CONFIG_MIPS_MT_SMP)
if (cpu_has_veic) {
set_vi_handler (MSC01E_INT_SW0, ipi_resched_dispatch);
set_vi_handler (MSC01E_INT_SW1, ipi_call_dispatch);
cpu_ipi_resched_irq = MSC01E_INT_SW0;
cpu_ipi_call_irq = MSC01E_INT_SW1;
} else {
cpu_ipi_resched_irq = MIPS_CPU_IRQ_BASE +
MIPS_CPU_IPI_RESCHED_IRQ;
cpu_ipi_call_irq = MIPS_CPU_IRQ_BASE +
MIPS_CPU_IPI_CALL_IRQ;
}
arch_init_ipiirq(cpu_ipi_resched_irq, &irq_resched);
arch_init_ipiirq(cpu_ipi_call_irq, &irq_call);
#endif
if (cpu_has_veic) {
set_vi_handler(MSC01E_INT_COREHI,
corehi_irqdispatch);
corehi_irq = MSC01E_INT_BASE + MSC01E_INT_COREHI;
} else {
corehi_irq = MIPS_CPU_IRQ_BASE + MIPSCPU_INT_COREHI;
}
}
setup_irq(corehi_irq, &corehi_irqaction);
}
