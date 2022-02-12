int gsc_alloc_irq(struct gsc_irq *i)
{
int irq = txn_alloc_irq(GSC_EIM_WIDTH);
if (irq < 0) {
printk("cannot get irq\n");
return irq;
}
i->txn_addr = txn_alloc_addr(irq);
i->txn_data = txn_alloc_data(irq);
i->irq = irq;
return irq;
}
int gsc_claim_irq(struct gsc_irq *i, int irq)
{
int c = irq;
irq += CPU_IRQ_BASE;
irq = txn_claim_irq(irq);
if (irq < 0) {
printk("cannot claim irq %d\n", c);
return irq;
}
i->txn_addr = txn_alloc_addr(irq);
i->txn_data = txn_alloc_data(irq);
i->irq = irq;
return irq;
}
irqreturn_t gsc_asic_intr(int gsc_asic_irq, void *dev)
{
unsigned long irr;
struct gsc_asic *gsc_asic = dev;
irr = gsc_readl(gsc_asic->hpa + OFFSET_IRR);
if (irr == 0)
return IRQ_NONE;
DEBPRINTK("%s intr, mask=0x%x\n", gsc_asic->name, irr);
do {
int local_irq = __ffs(irr);
unsigned int irq = gsc_asic->global_irq[local_irq];
generic_handle_irq(irq);
irr &= ~(1 << local_irq);
} while (irr);
return IRQ_HANDLED;
}
int gsc_find_local_irq(unsigned int irq, int *global_irqs, int limit)
{
int local_irq;
for (local_irq = 0; local_irq < limit; local_irq++) {
if (global_irqs[local_irq] == irq)
return local_irq;
}
return NO_IRQ;
}
static void gsc_asic_mask_irq(struct irq_data *d)
{
struct gsc_asic *irq_dev = irq_data_get_irq_chip_data(d);
int local_irq = gsc_find_local_irq(d->irq, irq_dev->global_irq, 32);
u32 imr;
DEBPRINTK(KERN_DEBUG "%s(%d) %s: IMR 0x%x\n", __func__, d->irq,
irq_dev->name, imr);
imr = gsc_readl(irq_dev->hpa + OFFSET_IMR);
imr &= ~(1 << local_irq);
gsc_writel(imr, irq_dev->hpa + OFFSET_IMR);
}
static void gsc_asic_unmask_irq(struct irq_data *d)
{
struct gsc_asic *irq_dev = irq_data_get_irq_chip_data(d);
int local_irq = gsc_find_local_irq(d->irq, irq_dev->global_irq, 32);
u32 imr;
DEBPRINTK(KERN_DEBUG "%s(%d) %s: IMR 0x%x\n", __func__, d->irq,
irq_dev->name, imr);
imr = gsc_readl(irq_dev->hpa + OFFSET_IMR);
imr |= 1 << local_irq;
gsc_writel(imr, irq_dev->hpa + OFFSET_IMR);
}
int gsc_assign_irq(struct irq_chip *type, void *data)
{
static int irq = GSC_IRQ_BASE;
if (irq > GSC_IRQ_MAX)
return NO_IRQ;
irq_set_chip_and_handler(irq, type, handle_simple_irq);
irq_set_chip_data(irq, data);
return irq++;
}
void gsc_asic_assign_irq(struct gsc_asic *asic, int local_irq, int *irqp)
{
int irq = asic->global_irq[local_irq];
if (irq <= 0) {
irq = gsc_assign_irq(&gsc_asic_interrupt_type, asic);
if (irq == NO_IRQ)
return;
asic->global_irq[local_irq] = irq;
}
*irqp = irq;
}
static int gsc_fixup_irqs_callback(struct device *dev, void *data)
{
struct parisc_device *padev = to_parisc_device(dev);
struct gsc_fixup_struct *gf = data;
if (padev->id.hw_type == HPHW_FAULTY)
gsc_fixup_irqs(padev, gf->ctrl, gf->choose_irq);
gf->choose_irq(padev, gf->ctrl);
return 0;
}
void gsc_fixup_irqs(struct parisc_device *parent, void *ctrl,
void (*choose_irq)(struct parisc_device *, void *))
{
struct gsc_fixup_struct data = {
.choose_irq = choose_irq,
.ctrl = ctrl,
};
device_for_each_child(&parent->dev, &data, gsc_fixup_irqs_callback);
}
int gsc_common_setup(struct parisc_device *parent, struct gsc_asic *gsc_asic)
{
struct resource *res;
int i;
gsc_asic->gsc = parent;
for (i = 0; i < 32; i++) {
gsc_asic->global_irq[i] = NO_IRQ;
}
res = request_mem_region(gsc_asic->hpa, 0x100000, gsc_asic->name);
if (res) {
res->flags = IORESOURCE_MEM;
}
#if 0
printk(KERN_WARNING "%s IRQ %d EIM 0x%x", gsc_asic->name,
parent->irq, gsc_asic->eim);
if (gsc_readl(gsc_asic->hpa + OFFSET_IMR))
printk(" IMR is non-zero! (0x%x)",
gsc_readl(gsc_asic->hpa + OFFSET_IMR));
printk("\n");
#endif
return 0;
}
void __init gsc_init(void)
{
#ifdef CONFIG_GSC_LASI
register_parisc_driver(&lasi_driver);
register_parisc_driver(&asp_driver);
#endif
#ifdef CONFIG_GSC_WAX
register_parisc_driver(&wax_driver);
#endif
}
