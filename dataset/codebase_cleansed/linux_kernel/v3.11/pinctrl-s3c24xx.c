static int s3c24xx_eint_get_trigger(unsigned int type)
{
switch (type) {
case IRQ_TYPE_EDGE_RISING:
return EINT_EDGE_RISING;
break;
case IRQ_TYPE_EDGE_FALLING:
return EINT_EDGE_FALLING;
break;
case IRQ_TYPE_EDGE_BOTH:
return EINT_EDGE_BOTH;
break;
case IRQ_TYPE_LEVEL_HIGH:
return EINT_LEVEL_HIGH;
break;
case IRQ_TYPE_LEVEL_LOW:
return EINT_LEVEL_LOW;
break;
default:
return -EINVAL;
}
}
static void s3c24xx_eint_set_handler(unsigned int irq, unsigned int type)
{
if (type & IRQ_TYPE_EDGE_BOTH)
__irq_set_handler_locked(irq, handle_edge_irq);
else
__irq_set_handler_locked(irq, handle_level_irq);
}
static void s3c24xx_eint_set_function(struct samsung_pinctrl_drv_data *d,
struct samsung_pin_bank *bank, int pin)
{
struct samsung_pin_bank_type *bank_type = bank->type;
unsigned long flags;
void __iomem *reg;
u8 shift;
u32 mask;
u32 val;
reg = d->virt_base + bank->pctl_offset;
shift = pin * bank_type->fld_width[PINCFG_TYPE_FUNC];
mask = (1 << bank_type->fld_width[PINCFG_TYPE_FUNC]) - 1;
spin_lock_irqsave(&bank->slock, flags);
val = readl(reg);
val &= ~(mask << shift);
val |= bank->eint_func << shift;
writel(val, reg);
spin_unlock_irqrestore(&bank->slock, flags);
}
static int s3c24xx_eint_type(struct irq_data *data, unsigned int type)
{
struct samsung_pin_bank *bank = irq_data_get_irq_chip_data(data);
struct samsung_pinctrl_drv_data *d = bank->drvdata;
int index = bank->eint_offset + data->hwirq;
void __iomem *reg;
int trigger;
u8 shift;
u32 val;
trigger = s3c24xx_eint_get_trigger(type);
if (trigger < 0) {
dev_err(d->dev, "unsupported external interrupt type\n");
return -EINVAL;
}
s3c24xx_eint_set_handler(data->irq, type);
reg = d->virt_base + EINT_REG(index);
shift = EINT_OFFS(index);
val = readl(reg);
val &= ~(EINT_MASK << shift);
val |= trigger << shift;
writel(val, reg);
s3c24xx_eint_set_function(d, bank, data->hwirq);
return 0;
}
static void s3c2410_eint0_3_ack(struct irq_data *data)
{
struct samsung_pin_bank *bank = irq_data_get_irq_chip_data(data);
struct s3c24xx_eint_domain_data *ddata = bank->irq_domain->host_data;
struct s3c24xx_eint_data *eint_data = ddata->eint_data;
int parent_irq = eint_data->parents[data->hwirq];
struct irq_chip *parent_chip = irq_get_chip(parent_irq);
parent_chip->irq_ack(irq_get_irq_data(parent_irq));
}
static void s3c2410_eint0_3_mask(struct irq_data *data)
{
struct samsung_pin_bank *bank = irq_data_get_irq_chip_data(data);
struct s3c24xx_eint_domain_data *ddata = bank->irq_domain->host_data;
struct s3c24xx_eint_data *eint_data = ddata->eint_data;
int parent_irq = eint_data->parents[data->hwirq];
struct irq_chip *parent_chip = irq_get_chip(parent_irq);
parent_chip->irq_mask(irq_get_irq_data(parent_irq));
}
static void s3c2410_eint0_3_unmask(struct irq_data *data)
{
struct samsung_pin_bank *bank = irq_data_get_irq_chip_data(data);
struct s3c24xx_eint_domain_data *ddata = bank->irq_domain->host_data;
struct s3c24xx_eint_data *eint_data = ddata->eint_data;
int parent_irq = eint_data->parents[data->hwirq];
struct irq_chip *parent_chip = irq_get_chip(parent_irq);
parent_chip->irq_unmask(irq_get_irq_data(parent_irq));
}
static void s3c2410_demux_eint0_3(unsigned int irq, struct irq_desc *desc)
{
struct irq_data *data = irq_desc_get_irq_data(desc);
struct s3c24xx_eint_data *eint_data = irq_get_handler_data(irq);
unsigned int virq;
virq = irq_linear_revmap(eint_data->domains[data->hwirq], data->hwirq);
BUG_ON(!virq);
generic_handle_irq(virq);
}
static void s3c2412_eint0_3_ack(struct irq_data *data)
{
struct samsung_pin_bank *bank = irq_data_get_irq_chip_data(data);
struct samsung_pinctrl_drv_data *d = bank->drvdata;
unsigned long bitval = 1UL << data->hwirq;
writel(bitval, d->virt_base + EINTPEND_REG);
}
static void s3c2412_eint0_3_mask(struct irq_data *data)
{
struct samsung_pin_bank *bank = irq_data_get_irq_chip_data(data);
struct samsung_pinctrl_drv_data *d = bank->drvdata;
unsigned long mask;
mask = readl(d->virt_base + EINTMASK_REG);
mask |= (1UL << data->hwirq);
writel(mask, d->virt_base + EINTMASK_REG);
}
static void s3c2412_eint0_3_unmask(struct irq_data *data)
{
struct samsung_pin_bank *bank = irq_data_get_irq_chip_data(data);
struct samsung_pinctrl_drv_data *d = bank->drvdata;
unsigned long mask;
mask = readl(d->virt_base + EINTMASK_REG);
mask &= ~(1UL << data->hwirq);
writel(mask, d->virt_base + EINTMASK_REG);
}
static void s3c2412_demux_eint0_3(unsigned int irq, struct irq_desc *desc)
{
struct irq_chip *chip = irq_get_chip(irq);
struct irq_data *data = irq_desc_get_irq_data(desc);
struct s3c24xx_eint_data *eint_data = irq_get_handler_data(irq);
unsigned int virq;
chained_irq_enter(chip, desc);
virq = irq_linear_revmap(eint_data->domains[data->hwirq], data->hwirq);
BUG_ON(!virq);
generic_handle_irq(virq);
chained_irq_exit(chip, desc);
}
static void s3c24xx_eint_ack(struct irq_data *data)
{
struct samsung_pin_bank *bank = irq_data_get_irq_chip_data(data);
struct samsung_pinctrl_drv_data *d = bank->drvdata;
unsigned char index = bank->eint_offset + data->hwirq;
writel(1UL << index, d->virt_base + EINTPEND_REG);
}
static void s3c24xx_eint_mask(struct irq_data *data)
{
struct samsung_pin_bank *bank = irq_data_get_irq_chip_data(data);
struct samsung_pinctrl_drv_data *d = bank->drvdata;
unsigned char index = bank->eint_offset + data->hwirq;
unsigned long mask;
mask = readl(d->virt_base + EINTMASK_REG);
mask |= (1UL << index);
writel(mask, d->virt_base + EINTMASK_REG);
}
static void s3c24xx_eint_unmask(struct irq_data *data)
{
struct samsung_pin_bank *bank = irq_data_get_irq_chip_data(data);
struct samsung_pinctrl_drv_data *d = bank->drvdata;
unsigned char index = bank->eint_offset + data->hwirq;
unsigned long mask;
mask = readl(d->virt_base + EINTMASK_REG);
mask &= ~(1UL << index);
writel(mask, d->virt_base + EINTMASK_REG);
}
static inline void s3c24xx_demux_eint(unsigned int irq, struct irq_desc *desc,
u32 offset, u32 range)
{
struct irq_chip *chip = irq_get_chip(irq);
struct s3c24xx_eint_data *data = irq_get_handler_data(irq);
struct samsung_pinctrl_drv_data *d = data->drvdata;
unsigned int pend, mask;
chained_irq_enter(chip, desc);
pend = readl(d->virt_base + EINTPEND_REG);
mask = readl(d->virt_base + EINTMASK_REG);
pend &= ~mask;
pend &= range;
while (pend) {
unsigned int virq;
irq = __ffs(pend);
pend &= ~(1 << irq);
virq = irq_linear_revmap(data->domains[irq], irq - offset);
BUG_ON(!virq);
generic_handle_irq(virq);
}
chained_irq_exit(chip, desc);
}
static void s3c24xx_demux_eint4_7(unsigned int irq, struct irq_desc *desc)
{
s3c24xx_demux_eint(irq, desc, 0, 0xf0);
}
static void s3c24xx_demux_eint8_23(unsigned int irq, struct irq_desc *desc)
{
s3c24xx_demux_eint(irq, desc, 8, 0xffff00);
}
static int s3c24xx_gpf_irq_map(struct irq_domain *h, unsigned int virq,
irq_hw_number_t hw)
{
struct s3c24xx_eint_domain_data *ddata = h->host_data;
struct samsung_pin_bank *bank = ddata->bank;
if (!(bank->eint_mask & (1 << (bank->eint_offset + hw))))
return -EINVAL;
if (hw <= 3) {
if (ddata->eint0_3_parent_only)
irq_set_chip_and_handler(virq, &s3c2410_eint0_3_chip,
handle_edge_irq);
else
irq_set_chip_and_handler(virq, &s3c2412_eint0_3_chip,
handle_edge_irq);
} else {
irq_set_chip_and_handler(virq, &s3c24xx_eint_chip,
handle_edge_irq);
}
irq_set_chip_data(virq, bank);
set_irq_flags(virq, IRQF_VALID);
return 0;
}
static int s3c24xx_gpg_irq_map(struct irq_domain *h, unsigned int virq,
irq_hw_number_t hw)
{
struct s3c24xx_eint_domain_data *ddata = h->host_data;
struct samsung_pin_bank *bank = ddata->bank;
if (!(bank->eint_mask & (1 << (bank->eint_offset + hw))))
return -EINVAL;
irq_set_chip_and_handler(virq, &s3c24xx_eint_chip, handle_edge_irq);
irq_set_chip_data(virq, bank);
set_irq_flags(virq, IRQF_VALID);
return 0;
}
static int s3c24xx_eint_init(struct samsung_pinctrl_drv_data *d)
{
struct device *dev = d->dev;
const struct of_device_id *match;
struct device_node *eint_np = NULL;
struct device_node *np;
struct samsung_pin_bank *bank;
struct s3c24xx_eint_data *eint_data;
const struct irq_domain_ops *ops;
unsigned int i;
bool eint0_3_parent_only;
irq_flow_handler_t *handlers;
for_each_child_of_node(dev->of_node, np) {
match = of_match_node(s3c24xx_eint_irq_ids, np);
if (match) {
eint_np = np;
eint0_3_parent_only = (bool)match->data;
break;
}
}
if (!eint_np)
return -ENODEV;
eint_data = devm_kzalloc(dev, sizeof(*eint_data), GFP_KERNEL);
if (!eint_data)
return -ENOMEM;
eint_data->drvdata = d;
handlers = eint0_3_parent_only ? s3c2410_eint_handlers
: s3c2412_eint_handlers;
for (i = 0; i < NUM_EINT_IRQ; ++i) {
unsigned int irq;
irq = irq_of_parse_and_map(eint_np, i);
if (!irq) {
dev_err(dev, "failed to get wakeup EINT IRQ %d\n", i);
return -ENXIO;
}
eint_data->parents[i] = irq;
irq_set_chained_handler(irq, handlers[i]);
irq_set_handler_data(irq, eint_data);
}
bank = d->ctrl->pin_banks;
for (i = 0; i < d->ctrl->nr_banks; ++i, ++bank) {
struct s3c24xx_eint_domain_data *ddata;
unsigned int mask;
unsigned int irq;
unsigned int pin;
if (bank->eint_type != EINT_TYPE_WKUP)
continue;
ddata = devm_kzalloc(dev, sizeof(*ddata), GFP_KERNEL);
if (!ddata)
return -ENOMEM;
ddata->bank = bank;
ddata->eint_data = eint_data;
ddata->eint0_3_parent_only = eint0_3_parent_only;
ops = (bank->eint_offset == 0) ? &s3c24xx_gpf_irq_ops
: &s3c24xx_gpg_irq_ops;
bank->irq_domain = irq_domain_add_linear(bank->of_node,
bank->nr_pins, ops, ddata);
if (!bank->irq_domain) {
dev_err(dev, "wkup irq domain add failed\n");
return -ENXIO;
}
irq = bank->eint_offset;
mask = bank->eint_mask;
for (pin = 0; mask; ++pin, mask >>= 1) {
if (irq > NUM_EINT)
break;
if (!(mask & 1))
continue;
eint_data->domains[irq] = bank->irq_domain;
++irq;
}
}
return 0;
}
