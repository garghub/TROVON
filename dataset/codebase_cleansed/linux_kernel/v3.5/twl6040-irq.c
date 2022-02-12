static inline
struct twl6040_irq_data *irq_to_twl6040_irq(struct twl6040 *twl6040,
int irq)
{
return &twl6040_irqs[irq - twl6040->irq_base];
}
static void twl6040_irq_lock(struct irq_data *data)
{
struct twl6040 *twl6040 = irq_data_get_irq_chip_data(data);
mutex_lock(&twl6040->irq_mutex);
}
static void twl6040_irq_sync_unlock(struct irq_data *data)
{
struct twl6040 *twl6040 = irq_data_get_irq_chip_data(data);
if (twl6040->irq_masks_cur != twl6040->irq_masks_cache) {
twl6040->irq_masks_cache = twl6040->irq_masks_cur;
twl6040_reg_write(twl6040, TWL6040_REG_INTMR,
twl6040->irq_masks_cur);
}
mutex_unlock(&twl6040->irq_mutex);
}
static void twl6040_irq_enable(struct irq_data *data)
{
struct twl6040 *twl6040 = irq_data_get_irq_chip_data(data);
struct twl6040_irq_data *irq_data = irq_to_twl6040_irq(twl6040,
data->irq);
twl6040->irq_masks_cur &= ~irq_data->mask;
}
static void twl6040_irq_disable(struct irq_data *data)
{
struct twl6040 *twl6040 = irq_data_get_irq_chip_data(data);
struct twl6040_irq_data *irq_data = irq_to_twl6040_irq(twl6040,
data->irq);
twl6040->irq_masks_cur |= irq_data->mask;
}
static irqreturn_t twl6040_irq_thread(int irq, void *data)
{
struct twl6040 *twl6040 = data;
u8 intid;
int i;
intid = twl6040_reg_read(twl6040, TWL6040_REG_INTID);
for (i = ARRAY_SIZE(twl6040_irqs) - 1; i >= 0; i--) {
if (twl6040->irq_masks_cur & twl6040_irqs[i].mask)
intid &= ~twl6040_irqs[i].status;
if (intid & twl6040_irqs[i].status)
handle_nested_irq(twl6040->irq_base + i);
}
twl6040_reg_write(twl6040, TWL6040_REG_INTID, intid);
return IRQ_HANDLED;
}
int twl6040_irq_init(struct twl6040 *twl6040)
{
struct device_node *node = twl6040->dev->of_node;
int i, nr_irqs, irq_base, ret;
u8 val;
mutex_init(&twl6040->irq_mutex);
twl6040->irq_masks_cur = TWL6040_ALLINT_MSK;
twl6040->irq_masks_cache = TWL6040_ALLINT_MSK;
twl6040_reg_write(twl6040, TWL6040_REG_INTMR, TWL6040_ALLINT_MSK);
nr_irqs = ARRAY_SIZE(twl6040_irqs);
irq_base = irq_alloc_descs(-1, 0, nr_irqs, 0);
if (IS_ERR_VALUE(irq_base)) {
dev_err(twl6040->dev, "Fail to allocate IRQ descs\n");
return irq_base;
}
twl6040->irq_base = irq_base;
irq_domain_add_legacy(node, ARRAY_SIZE(twl6040_irqs), irq_base, 0,
&irq_domain_simple_ops, NULL);
for (i = irq_base; i < irq_base + nr_irqs; i++) {
irq_set_chip_data(i, twl6040);
irq_set_chip_and_handler(i, &twl6040_irq_chip,
handle_level_irq);
irq_set_nested_thread(i, 1);
#ifdef CONFIG_ARM
set_irq_flags(i, IRQF_VALID);
#else
irq_set_noprobe(i);
#endif
}
ret = request_threaded_irq(twl6040->irq, NULL, twl6040_irq_thread,
IRQF_ONESHOT, "twl6040", twl6040);
if (ret) {
dev_err(twl6040->dev, "failed to request IRQ %d: %d\n",
twl6040->irq, ret);
return ret;
}
val = twl6040_reg_read(twl6040, TWL6040_REG_INTID);
twl6040_clear_bits(twl6040, TWL6040_REG_ACCCTL, TWL6040_INTCLRMODE);
return 0;
}
void twl6040_irq_exit(struct twl6040 *twl6040)
{
free_irq(twl6040->irq, twl6040);
}
