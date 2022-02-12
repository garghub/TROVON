static irqreturn_t sh73a0_intcs_demux(int irq, void *dev_id)
{
unsigned int evtcodeas = ioread32((void __iomem *)dev_id);
generic_handle_irq(intcs_evt2irq(evtcodeas));
return IRQ_HANDLED;
}
static int sh73a0_set_wake(struct irq_data *data, unsigned int on)
{
return 0;
}
static int to_gic_irq(struct irq_data *data)
{
unsigned int vect = irq2evt(data->irq) - INTCS_VECT_BASE;
if (vect >= 0x3200)
vect -= 0x3000;
else
vect -= 0x0200;
return gic_spi((vect >> 5) + 1);
}
static int to_intca_reloc_irq(struct irq_data *data)
{
return data->irq + (RELOC_BASE >> 5);
}
static void intca_gic_enable(struct irq_data *data)
{
irq_cb(irq_unmask, to_intca_reloc_irq(data));
irq_cb(irq_unmask, to_gic_irq(data));
}
static void intca_gic_disable(struct irq_data *data)
{
irq_cb(irq_mask, to_gic_irq(data));
irq_cb(irq_mask, to_intca_reloc_irq(data));
}
static void intca_gic_mask_ack(struct irq_data *data)
{
irq_cb(irq_mask, to_gic_irq(data));
irq_cb(irq_mask_ack, to_intca_reloc_irq(data));
}
static void intca_gic_eoi(struct irq_data *data)
{
irq_cb(irq_eoi, to_gic_irq(data));
}
static int intca_gic_set_type(struct irq_data *data, unsigned int type)
{
return irq_cbp(irq_set_type, to_intca_reloc_irq(data), type);
}
static int intca_gic_set_affinity(struct irq_data *data,
const struct cpumask *cpumask,
bool force)
{
return irq_cbp(irq_set_affinity, to_gic_irq(data), cpumask, force);
}
static int to_intc_vect(int irq)
{
unsigned int irq_pin = irq - gic_spi(1);
unsigned int offs;
if (irq_pin < 16)
offs = 0x0200;
else
offs = 0x3000;
return offs + (irq_pin << 5);
}
static irqreturn_t sh73a0_irq_pin_demux(int irq, void *dev_id)
{
generic_handle_irq(intcs_evt2irq(to_intc_vect(irq)));
return IRQ_HANDLED;
}
static void pint_demux(void __iomem *rr, void __iomem *er, int base_irq)
{
unsigned long value = ioread32(rr) & ioread32(er);
int k;
for (k = 0; k < 32; k++) {
if (value & (1 << (31 - k))) {
generic_handle_irq(base_irq + k);
iowrite32(~(1 << (31 - k)), rr);
}
}
}
static irqreturn_t sh73a0_pint0_demux(int irq, void *dev_id)
{
pint_demux(PINTRR0, PINTER0_VIRT, SH73A0_PINT0_IRQ(0));
return IRQ_HANDLED;
}
static irqreturn_t sh73a0_pint1_demux(int irq, void *dev_id)
{
pint_demux(PINTRR1, PINTER1_VIRT, SH73A0_PINT1_IRQ(0));
return IRQ_HANDLED;
}
void __init sh73a0_init_irq(void)
{
void __iomem *gic_dist_base = IOMEM(0xf0001000);
void __iomem *gic_cpu_base = IOMEM(0xf0000100);
void __iomem *intevtsa = ioremap_nocache(0xffd20100, PAGE_SIZE);
int k, n;
gic_init(0, 29, gic_dist_base, gic_cpu_base);
gic_arch_extn.irq_set_wake = sh73a0_set_wake;
register_intc_controller(&intcs_desc);
register_intc_controller(&intca_irq_pins_desc);
register_intc_controller(&intc_pint0_desc);
register_intc_controller(&intc_pint1_desc);
sh73a0_intcs_cascade.name = "INTCS cascade";
sh73a0_intcs_cascade.handler = sh73a0_intcs_demux;
sh73a0_intcs_cascade.dev_id = intevtsa;
setup_irq(gic_spi(50), &sh73a0_intcs_cascade);
for (k = 0; k < 32; k++) {
sh73a0_irq_pin_cascade[k].name = "INTCA-GIC cascade";
sh73a0_irq_pin_cascade[k].handler = sh73a0_irq_pin_demux;
setup_irq(gic_spi(1 + k), &sh73a0_irq_pin_cascade[k]);
n = intcs_evt2irq(to_intc_vect(gic_spi(1 + k)));
WARN_ON(irq_alloc_desc_at(n, numa_node_id()) != n);
irq_set_chip_and_handler_name(n, &intca_gic_irq_chip,
handle_level_irq, "level");
set_irq_flags(n, IRQF_VALID);
}
sh73a0_pint0_cascade.name = "PINT0 cascade";
sh73a0_pint0_cascade.handler = sh73a0_pint0_demux;
setup_irq(gic_spi(33), &sh73a0_pint0_cascade);
sh73a0_pint1_cascade.name = "PINT1 cascade";
sh73a0_pint1_cascade.handler = sh73a0_pint1_demux;
setup_irq(gic_spi(34), &sh73a0_pint1_cascade);
}
void __init sh73a0_init_irq_dt(void)
{
irqchip_init();
gic_arch_extn.irq_set_wake = sh73a0_set_wake;
}
