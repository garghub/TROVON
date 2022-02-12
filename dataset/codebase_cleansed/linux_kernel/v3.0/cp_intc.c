static inline unsigned int cp_intc_read(unsigned offset)
{
return __raw_readl(davinci_intc_base + offset);
}
static inline void cp_intc_write(unsigned long value, unsigned offset)
{
__raw_writel(value, davinci_intc_base + offset);
}
static void cp_intc_ack_irq(struct irq_data *d)
{
cp_intc_write(d->irq, CP_INTC_SYS_STAT_IDX_CLR);
}
static void cp_intc_mask_irq(struct irq_data *d)
{
cp_intc_write(1, CP_INTC_HOST_ENABLE_IDX_CLR);
cp_intc_write(d->irq, CP_INTC_SYS_ENABLE_IDX_CLR);
cp_intc_write(1, CP_INTC_HOST_ENABLE_IDX_SET);
}
static void cp_intc_unmask_irq(struct irq_data *d)
{
cp_intc_write(d->irq, CP_INTC_SYS_ENABLE_IDX_SET);
}
static int cp_intc_set_irq_type(struct irq_data *d, unsigned int flow_type)
{
unsigned reg = BIT_WORD(d->irq);
unsigned mask = BIT_MASK(d->irq);
unsigned polarity = cp_intc_read(CP_INTC_SYS_POLARITY(reg));
unsigned type = cp_intc_read(CP_INTC_SYS_TYPE(reg));
switch (flow_type) {
case IRQ_TYPE_EDGE_RISING:
polarity |= mask;
type |= mask;
break;
case IRQ_TYPE_EDGE_FALLING:
polarity &= ~mask;
type |= mask;
break;
case IRQ_TYPE_LEVEL_HIGH:
polarity |= mask;
type &= ~mask;
break;
case IRQ_TYPE_LEVEL_LOW:
polarity &= ~mask;
type &= ~mask;
break;
default:
return -EINVAL;
}
cp_intc_write(polarity, CP_INTC_SYS_POLARITY(reg));
cp_intc_write(type, CP_INTC_SYS_TYPE(reg));
return 0;
}
static int cp_intc_set_wake(struct irq_data *d, unsigned int on)
{
return 0;
}
void __init cp_intc_init(void)
{
unsigned long num_irq = davinci_soc_info.intc_irq_num;
u8 *irq_prio = davinci_soc_info.intc_irq_prios;
u32 *host_map = davinci_soc_info.intc_host_map;
unsigned num_reg = BITS_TO_LONGS(num_irq);
int i;
davinci_intc_type = DAVINCI_INTC_TYPE_CP_INTC;
davinci_intc_base = ioremap(davinci_soc_info.intc_base, SZ_8K);
if (WARN_ON(!davinci_intc_base))
return;
cp_intc_write(0, CP_INTC_GLOBAL_ENABLE);
cp_intc_write(0, CP_INTC_HOST_ENABLE(0));
for (i = 0; i < num_reg; i++)
cp_intc_write(~0, CP_INTC_SYS_ENABLE_CLR(i));
cp_intc_write(0, CP_INTC_CTRL);
cp_intc_write(0, CP_INTC_HOST_CTRL);
for (i = 0; i < num_reg; i++)
cp_intc_write(~0, CP_INTC_SYS_STAT_CLR(i));
cp_intc_write(1, CP_INTC_HOST_ENABLE_IDX_SET);
num_reg = (num_irq + 3) >> 2;
if (irq_prio) {
unsigned j, k;
u32 val;
for (k = i = 0; i < num_reg; i++) {
for (val = j = 0; j < 4; j++, k++) {
val >>= 8;
if (k < num_irq)
val |= irq_prio[k] << 24;
}
cp_intc_write(val, CP_INTC_CHAN_MAP(i));
}
} else {
for (i = 0; i < num_reg; i++)
cp_intc_write(0x0f0f0f0f, CP_INTC_CHAN_MAP(i));
}
if (host_map)
for (i = 0; host_map[i] != -1; i++)
cp_intc_write(host_map[i], CP_INTC_HOST_MAP(i));
for (i = 0; i < num_irq; i++) {
irq_set_chip(i, &cp_intc_irq_chip);
set_irq_flags(i, IRQF_VALID | IRQF_PROBE);
irq_set_handler(i, handle_edge_irq);
}
cp_intc_write(1, CP_INTC_GLOBAL_ENABLE);
}
