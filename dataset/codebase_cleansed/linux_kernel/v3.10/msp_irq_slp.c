static inline void unmask_msp_slp_irq(struct irq_data *d)
{
unsigned int irq = d->irq;
if (irq < MSP_PER_INTBASE)
*SLP_INT_MSK_REG |= (1 << (irq - MSP_SLP_INTBASE));
else
*PER_INT_MSK_REG |= (1 << (irq - MSP_PER_INTBASE));
}
static inline void mask_msp_slp_irq(struct irq_data *d)
{
unsigned int irq = d->irq;
if (irq < MSP_PER_INTBASE)
*SLP_INT_MSK_REG &= ~(1 << (irq - MSP_SLP_INTBASE));
else
*PER_INT_MSK_REG &= ~(1 << (irq - MSP_PER_INTBASE));
}
static inline void ack_msp_slp_irq(struct irq_data *d)
{
unsigned int irq = d->irq;
if (irq < MSP_PER_INTBASE)
*SLP_INT_STS_REG = (1 << (irq - MSP_SLP_INTBASE));
else
*PER_INT_STS_REG = (1 << (irq - MSP_PER_INTBASE));
}
void __init msp_slp_irq_init(void)
{
int i;
*SLP_INT_MSK_REG = 0x00000000;
*PER_INT_MSK_REG = 0x00000000;
*SLP_INT_STS_REG = 0xFFFFFFFF;
*PER_INT_STS_REG = 0xFFFFFFFF;
for (i = MSP_SLP_INTBASE; i < MSP_PER_INTBASE + 32; i++)
irq_set_chip_and_handler(i, &msp_slp_irq_controller,
handle_level_irq);
}
void msp_slp_irq_dispatch(void)
{
u32 pending;
int intbase;
intbase = MSP_SLP_INTBASE;
pending = *SLP_INT_STS_REG & *SLP_INT_MSK_REG;
if (pending == (1 << (MSP_INT_PER - MSP_SLP_INTBASE))) {
intbase = MSP_PER_INTBASE;
pending = *PER_INT_STS_REG & *PER_INT_MSK_REG;
}
if (pending == 0x00000000) {
printk(KERN_ERR "Spurious %s interrupt?\n",
(intbase == MSP_SLP_INTBASE) ? "SLP" : "PER");
return;
}
do_IRQ(ffs(pending) + intbase - 1);
}
