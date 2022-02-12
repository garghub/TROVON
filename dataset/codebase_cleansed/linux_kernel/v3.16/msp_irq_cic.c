static inline void cic_wmb(void)
{
const volatile void __iomem *cic_mem = CIC_VPE0_MSK_REG;
volatile u32 dummy_read;
wmb();
dummy_read = __raw_readl(cic_mem);
dummy_read++;
}
static void unmask_cic_irq(struct irq_data *d)
{
volatile u32 *cic_msk_reg = CIC_VPE0_MSK_REG;
int vpe;
#ifdef CONFIG_SMP
unsigned int mtflags;
unsigned long flags;
if (!cpumask_test_cpu(smp_processor_id(), d->affinity))
return;
#endif
vpe = get_current_vpe();
LOCK_VPE(flags, mtflags);
cic_msk_reg[vpe] |= (1 << (d->irq - MSP_CIC_INTBASE));
UNLOCK_VPE(flags, mtflags);
cic_wmb();
}
static void mask_cic_irq(struct irq_data *d)
{
volatile u32 *cic_msk_reg = CIC_VPE0_MSK_REG;
int vpe = get_current_vpe();
#ifdef CONFIG_SMP
unsigned long flags, mtflags;
#endif
LOCK_VPE(flags, mtflags);
cic_msk_reg[vpe] &= ~(1 << (d->irq - MSP_CIC_INTBASE));
UNLOCK_VPE(flags, mtflags);
cic_wmb();
}
static void msp_cic_irq_ack(struct irq_data *d)
{
mask_cic_irq(d);
*CIC_STS_REG = (1 << (d->irq - MSP_CIC_INTBASE));
}
static int msp_cic_irq_set_affinity(struct irq_data *d,
const struct cpumask *cpumask, bool force)
{
int cpu;
unsigned long flags;
unsigned int mtflags;
unsigned long imask = (1 << (irq - MSP_CIC_INTBASE));
volatile u32 *cic_mask = (volatile u32 *)CIC_VPE0_MSK_REG;
BUG_ON(irq == MSP_INT_VPE0_TIMER || irq == MSP_INT_VPE1_TIMER);
LOCK_CORE(flags, mtflags);
for_each_online_cpu(cpu) {
if (cpumask_test_cpu(cpu, cpumask))
cic_mask[cpu] |= imask;
else
cic_mask[cpu] &= ~imask;
}
UNLOCK_CORE(flags, mtflags);
return 0;
}
void __init msp_cic_irq_init(void)
{
int i;
*CIC_VPE0_MSK_REG = 0x00000000;
*CIC_VPE1_MSK_REG = 0x00000000;
*CIC_STS_REG = 0xFFFFFFFF;
*CIC_EXT_CFG_REG &= 0xFFFF8F8F;
for (i = MSP_CIC_INTBASE ; i < MSP_CIC_INTBASE + 32 ; i++) {
irq_set_chip_and_handler(i, &msp_cic_irq_controller,
handle_level_irq);
}
msp_per_irq_init();
}
void msp_cic_irq_dispatch(void)
{
volatile u32 *cic_msk_reg = (volatile u32 *)CIC_VPE0_MSK_REG;
u32 cic_mask;
u32 pending;
int cic_status = *CIC_STS_REG;
cic_mask = cic_msk_reg[get_current_vpe()];
pending = cic_status & cic_mask;
if (pending & (1 << (MSP_INT_VPE0_TIMER - MSP_CIC_INTBASE))) {
do_IRQ(MSP_INT_VPE0_TIMER);
} else if (pending & (1 << (MSP_INT_VPE1_TIMER - MSP_CIC_INTBASE))) {
do_IRQ(MSP_INT_VPE1_TIMER);
} else if (pending & (1 << (MSP_INT_PER - MSP_CIC_INTBASE))) {
msp_per_irq_dispatch();
} else if (pending) {
do_IRQ(ffs(pending) + MSP_CIC_INTBASE - 1);
} else{
spurious_interrupt();
}
}
