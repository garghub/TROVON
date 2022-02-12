static inline u8 _irq_to_addr(enum lp8788_int_id id)
{
return id / SIZE_REG;
}
static inline u8 _irq_to_enable_addr(enum lp8788_int_id id)
{
return _irq_to_addr(id) + BASE_INTEN_ADDR;
}
static inline u8 _irq_to_mask(enum lp8788_int_id id)
{
return 1 << (id % SIZE_REG);
}
static inline u8 _irq_to_val(enum lp8788_int_id id, int enable)
{
return enable << (id % SIZE_REG);
}
static void lp8788_irq_enable(struct irq_data *data)
{
struct lp8788_irq_data *irqd = irq_data_get_irq_chip_data(data);
irqd->enabled[data->hwirq] = 1;
}
static void lp8788_irq_disable(struct irq_data *data)
{
struct lp8788_irq_data *irqd = irq_data_get_irq_chip_data(data);
irqd->enabled[data->hwirq] = 0;
}
static void lp8788_irq_bus_lock(struct irq_data *data)
{
struct lp8788_irq_data *irqd = irq_data_get_irq_chip_data(data);
mutex_lock(&irqd->irq_lock);
}
static void lp8788_irq_bus_sync_unlock(struct irq_data *data)
{
struct lp8788_irq_data *irqd = irq_data_get_irq_chip_data(data);
enum lp8788_int_id irq = data->hwirq;
u8 addr, mask, val;
addr = _irq_to_enable_addr(irq);
mask = _irq_to_mask(irq);
val = _irq_to_val(irq, irqd->enabled[irq]);
lp8788_update_bits(irqd->lp, addr, mask, val);
mutex_unlock(&irqd->irq_lock);
}
static irqreturn_t lp8788_irq_handler(int irq, void *ptr)
{
struct lp8788_irq_data *irqd = ptr;
struct lp8788 *lp = irqd->lp;
u8 status[NUM_REGS], addr, mask;
bool handled;
int i;
if (lp8788_read_multi_bytes(lp, LP8788_INT_1, status, NUM_REGS))
return IRQ_NONE;
for (i = 0 ; i < LP8788_INT_MAX ; i++) {
addr = _irq_to_addr(i);
mask = _irq_to_mask(i);
if (status[addr] & mask) {
handle_nested_irq(irq_find_mapping(irqd->domain, i));
handled = true;
}
}
return handled ? IRQ_HANDLED : IRQ_NONE;
}
static int lp8788_irq_map(struct irq_domain *d, unsigned int virq,
irq_hw_number_t hwirq)
{
struct lp8788_irq_data *irqd = d->host_data;
struct irq_chip *chip = &lp8788_irq_chip;
irq_set_chip_data(virq, irqd);
irq_set_chip_and_handler(virq, chip, handle_edge_irq);
irq_set_nested_thread(virq, 1);
#ifdef CONFIG_ARM
set_irq_flags(virq, IRQF_VALID);
#else
irq_set_noprobe(virq);
#endif
return 0;
}
int lp8788_irq_init(struct lp8788 *lp, int irq)
{
struct lp8788_irq_data *irqd;
int ret;
if (irq <= 0) {
dev_warn(lp->dev, "invalid irq number: %d\n", irq);
return 0;
}
irqd = devm_kzalloc(lp->dev, sizeof(*irqd), GFP_KERNEL);
if (!irqd)
return -ENOMEM;
irqd->lp = lp;
irqd->domain = irq_domain_add_linear(lp->dev->of_node, LP8788_INT_MAX,
&lp8788_domain_ops, irqd);
if (!irqd->domain) {
dev_err(lp->dev, "failed to add irq domain err\n");
return -EINVAL;
}
lp->irqdm = irqd->domain;
mutex_init(&irqd->irq_lock);
ret = request_threaded_irq(irq, NULL, lp8788_irq_handler,
IRQF_TRIGGER_FALLING | IRQF_ONESHOT,
"lp8788-irq", irqd);
if (ret) {
dev_err(lp->dev, "failed to create a thread for IRQ_N\n");
return ret;
}
lp->irq = irq;
return 0;
}
void lp8788_irq_exit(struct lp8788 *lp)
{
if (lp->irq)
free_irq(lp->irq, lp->irqdm);
}
