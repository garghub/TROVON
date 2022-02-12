static int s3c64xx_irq_get_trigger(unsigned int type)
{
int trigger;
switch (type) {
case IRQ_TYPE_EDGE_RISING:
trigger = EINT_EDGE_RISING;
break;
case IRQ_TYPE_EDGE_FALLING:
trigger = EINT_EDGE_FALLING;
break;
case IRQ_TYPE_EDGE_BOTH:
trigger = EINT_EDGE_BOTH;
break;
case IRQ_TYPE_LEVEL_HIGH:
trigger = EINT_LEVEL_HIGH;
break;
case IRQ_TYPE_LEVEL_LOW:
trigger = EINT_LEVEL_LOW;
break;
default:
return -EINVAL;
}
return trigger;
}
static void s3c64xx_irq_set_handler(unsigned int irq, unsigned int type)
{
if (type & IRQ_TYPE_EDGE_BOTH)
__irq_set_handler_locked(irq, handle_edge_irq);
else
__irq_set_handler_locked(irq, handle_level_irq);
}
static void s3c64xx_irq_set_function(struct samsung_pinctrl_drv_data *d,
struct samsung_pin_bank *bank, int pin)
{
const struct samsung_pin_bank_type *bank_type = bank->type;
unsigned long flags;
void __iomem *reg;
u8 shift;
u32 mask;
u32 val;
reg = d->virt_base + bank->pctl_offset;
shift = pin;
if (bank_type->fld_width[PINCFG_TYPE_FUNC] * shift >= 32) {
reg += 4;
shift -= 8;
}
shift = shift * bank_type->fld_width[PINCFG_TYPE_FUNC];
mask = (1 << bank_type->fld_width[PINCFG_TYPE_FUNC]) - 1;
spin_lock_irqsave(&bank->slock, flags);
val = readl(reg);
val &= ~(mask << shift);
val |= bank->eint_func << shift;
writel(val, reg);
spin_unlock_irqrestore(&bank->slock, flags);
}
static inline void s3c64xx_gpio_irq_set_mask(struct irq_data *irqd, bool mask)
{
struct samsung_pin_bank *bank = irq_data_get_irq_chip_data(irqd);
struct samsung_pinctrl_drv_data *d = bank->drvdata;
unsigned char index = EINT_OFFS(bank->eint_offset) + irqd->hwirq;
void __iomem *reg = d->virt_base + EINTMASK_REG(bank->eint_offset);
u32 val;
val = readl(reg);
if (mask)
val |= 1 << index;
else
val &= ~(1 << index);
writel(val, reg);
}
static void s3c64xx_gpio_irq_unmask(struct irq_data *irqd)
{
s3c64xx_gpio_irq_set_mask(irqd, false);
}
static void s3c64xx_gpio_irq_mask(struct irq_data *irqd)
{
s3c64xx_gpio_irq_set_mask(irqd, true);
}
static void s3c64xx_gpio_irq_ack(struct irq_data *irqd)
{
struct samsung_pin_bank *bank = irq_data_get_irq_chip_data(irqd);
struct samsung_pinctrl_drv_data *d = bank->drvdata;
unsigned char index = EINT_OFFS(bank->eint_offset) + irqd->hwirq;
void __iomem *reg = d->virt_base + EINTPEND_REG(bank->eint_offset);
writel(1 << index, reg);
}
static int s3c64xx_gpio_irq_set_type(struct irq_data *irqd, unsigned int type)
{
struct samsung_pin_bank *bank = irq_data_get_irq_chip_data(irqd);
struct samsung_pinctrl_drv_data *d = bank->drvdata;
void __iomem *reg;
int trigger;
u8 shift;
u32 val;
trigger = s3c64xx_irq_get_trigger(type);
if (trigger < 0) {
pr_err("unsupported external interrupt type\n");
return -EINVAL;
}
s3c64xx_irq_set_handler(irqd->irq, type);
reg = d->virt_base + EINTCON_REG(bank->eint_offset);
shift = EINT_OFFS(bank->eint_offset) + irqd->hwirq;
shift = 4 * (shift / 4);
val = readl(reg);
val &= ~(EINT_CON_MASK << shift);
val |= trigger << shift;
writel(val, reg);
s3c64xx_irq_set_function(d, bank, irqd->hwirq);
return 0;
}
static int s3c64xx_gpio_irq_map(struct irq_domain *h, unsigned int virq,
irq_hw_number_t hw)
{
struct samsung_pin_bank *bank = h->host_data;
if (!(bank->eint_mask & (1 << hw)))
return -EINVAL;
irq_set_chip_and_handler(virq,
&s3c64xx_gpio_irq_chip, handle_level_irq);
irq_set_chip_data(virq, bank);
set_irq_flags(virq, IRQF_VALID);
return 0;
}
static void s3c64xx_eint_gpio_irq(unsigned int irq, struct irq_desc *desc)
{
struct irq_chip *chip = irq_get_chip(irq);
struct s3c64xx_eint_gpio_data *data = irq_get_handler_data(irq);
struct samsung_pinctrl_drv_data *drvdata = data->drvdata;
chained_irq_enter(chip, desc);
do {
unsigned int svc;
unsigned int group;
unsigned int pin;
unsigned int virq;
svc = readl(drvdata->virt_base + SERVICE_REG);
group = SVC_GROUP(svc);
pin = svc & SVC_NUM_MASK;
if (!group)
break;
if (group == 1) {
if (pin < 8)
group = 0;
else
pin -= 8;
}
virq = irq_linear_revmap(data->domains[group], pin);
BUG_ON(!virq);
generic_handle_irq(virq);
} while (1);
chained_irq_exit(chip, desc);
}
static int s3c64xx_eint_gpio_init(struct samsung_pinctrl_drv_data *d)
{
struct s3c64xx_eint_gpio_data *data;
struct samsung_pin_bank *bank;
struct device *dev = d->dev;
unsigned int nr_domains;
unsigned int i;
if (!d->irq) {
dev_err(dev, "irq number not available\n");
return -EINVAL;
}
nr_domains = 0;
bank = d->pin_banks;
for (i = 0; i < d->nr_banks; ++i, ++bank) {
unsigned int nr_eints;
unsigned int mask;
if (bank->eint_type != EINT_TYPE_GPIO)
continue;
mask = bank->eint_mask;
nr_eints = fls(mask);
bank->irq_domain = irq_domain_add_linear(bank->of_node,
nr_eints, &s3c64xx_gpio_irqd_ops, bank);
if (!bank->irq_domain) {
dev_err(dev, "gpio irq domain add failed\n");
return -ENXIO;
}
++nr_domains;
}
data = devm_kzalloc(dev, sizeof(*data)
+ nr_domains * sizeof(*data->domains), GFP_KERNEL);
if (!data) {
dev_err(dev, "failed to allocate handler data\n");
return -ENOMEM;
}
data->drvdata = d;
bank = d->pin_banks;
nr_domains = 0;
for (i = 0; i < d->nr_banks; ++i, ++bank) {
if (bank->eint_type != EINT_TYPE_GPIO)
continue;
data->domains[nr_domains++] = bank->irq_domain;
}
irq_set_chained_handler(d->irq, s3c64xx_eint_gpio_irq);
irq_set_handler_data(d->irq, data);
return 0;
}
static inline void s3c64xx_eint0_irq_set_mask(struct irq_data *irqd, bool mask)
{
struct s3c64xx_eint0_domain_data *ddata =
irq_data_get_irq_chip_data(irqd);
struct samsung_pinctrl_drv_data *d = ddata->bank->drvdata;
u32 val;
val = readl(d->virt_base + EINT0MASK_REG);
if (mask)
val |= 1 << ddata->eints[irqd->hwirq];
else
val &= ~(1 << ddata->eints[irqd->hwirq]);
writel(val, d->virt_base + EINT0MASK_REG);
}
static void s3c64xx_eint0_irq_unmask(struct irq_data *irqd)
{
s3c64xx_eint0_irq_set_mask(irqd, false);
}
static void s3c64xx_eint0_irq_mask(struct irq_data *irqd)
{
s3c64xx_eint0_irq_set_mask(irqd, true);
}
static void s3c64xx_eint0_irq_ack(struct irq_data *irqd)
{
struct s3c64xx_eint0_domain_data *ddata =
irq_data_get_irq_chip_data(irqd);
struct samsung_pinctrl_drv_data *d = ddata->bank->drvdata;
writel(1 << ddata->eints[irqd->hwirq],
d->virt_base + EINT0PEND_REG);
}
static int s3c64xx_eint0_irq_set_type(struct irq_data *irqd, unsigned int type)
{
struct s3c64xx_eint0_domain_data *ddata =
irq_data_get_irq_chip_data(irqd);
struct samsung_pin_bank *bank = ddata->bank;
struct samsung_pinctrl_drv_data *d = bank->drvdata;
void __iomem *reg;
int trigger;
u8 shift;
u32 val;
trigger = s3c64xx_irq_get_trigger(type);
if (trigger < 0) {
pr_err("unsupported external interrupt type\n");
return -EINVAL;
}
s3c64xx_irq_set_handler(irqd->irq, type);
reg = d->virt_base + EINT0CON0_REG;
shift = ddata->eints[irqd->hwirq];
if (shift >= EINT_MAX_PER_REG) {
reg += 4;
shift -= EINT_MAX_PER_REG;
}
shift = EINT_CON_LEN * (shift / 2);
val = readl(reg);
val &= ~(EINT_CON_MASK << shift);
val |= trigger << shift;
writel(val, reg);
s3c64xx_irq_set_function(d, bank, irqd->hwirq);
return 0;
}
static inline void s3c64xx_irq_demux_eint(unsigned int irq,
struct irq_desc *desc, u32 range)
{
struct irq_chip *chip = irq_get_chip(irq);
struct s3c64xx_eint0_data *data = irq_get_handler_data(irq);
struct samsung_pinctrl_drv_data *drvdata = data->drvdata;
unsigned int pend, mask;
chained_irq_enter(chip, desc);
pend = readl(drvdata->virt_base + EINT0PEND_REG);
mask = readl(drvdata->virt_base + EINT0MASK_REG);
pend = pend & range & ~mask;
pend &= range;
while (pend) {
unsigned int virq;
irq = fls(pend) - 1;
pend &= ~(1 << irq);
virq = irq_linear_revmap(data->domains[irq], data->pins[irq]);
BUG_ON(!virq);
generic_handle_irq(virq);
}
chained_irq_exit(chip, desc);
}
static void s3c64xx_demux_eint0_3(unsigned int irq, struct irq_desc *desc)
{
s3c64xx_irq_demux_eint(irq, desc, 0xf);
}
static void s3c64xx_demux_eint4_11(unsigned int irq, struct irq_desc *desc)
{
s3c64xx_irq_demux_eint(irq, desc, 0xff0);
}
static void s3c64xx_demux_eint12_19(unsigned int irq, struct irq_desc *desc)
{
s3c64xx_irq_demux_eint(irq, desc, 0xff000);
}
static void s3c64xx_demux_eint20_27(unsigned int irq, struct irq_desc *desc)
{
s3c64xx_irq_demux_eint(irq, desc, 0xff00000);
}
static int s3c64xx_eint0_irq_map(struct irq_domain *h, unsigned int virq,
irq_hw_number_t hw)
{
struct s3c64xx_eint0_domain_data *ddata = h->host_data;
struct samsung_pin_bank *bank = ddata->bank;
if (!(bank->eint_mask & (1 << hw)))
return -EINVAL;
irq_set_chip_and_handler(virq,
&s3c64xx_eint0_irq_chip, handle_level_irq);
irq_set_chip_data(virq, ddata);
set_irq_flags(virq, IRQF_VALID);
return 0;
}
static int s3c64xx_eint_eint0_init(struct samsung_pinctrl_drv_data *d)
{
struct device *dev = d->dev;
struct device_node *eint0_np = NULL;
struct device_node *np;
struct samsung_pin_bank *bank;
struct s3c64xx_eint0_data *data;
unsigned int i;
for_each_child_of_node(dev->of_node, np) {
if (of_match_node(s3c64xx_eint0_irq_ids, np)) {
eint0_np = np;
break;
}
}
if (!eint0_np)
return -ENODEV;
data = devm_kzalloc(dev, sizeof(*data), GFP_KERNEL);
if (!data) {
dev_err(dev, "could not allocate memory for wkup eint data\n");
return -ENOMEM;
}
data->drvdata = d;
for (i = 0; i < NUM_EINT0_IRQ; ++i) {
unsigned int irq;
irq = irq_of_parse_and_map(eint0_np, i);
if (!irq) {
dev_err(dev, "failed to get wakeup EINT IRQ %d\n", i);
return -ENXIO;
}
irq_set_chained_handler(irq, s3c64xx_eint0_handlers[i]);
irq_set_handler_data(irq, data);
}
bank = d->pin_banks;
for (i = 0; i < d->nr_banks; ++i, ++bank) {
struct s3c64xx_eint0_domain_data *ddata;
unsigned int nr_eints;
unsigned int mask;
unsigned int irq;
unsigned int pin;
if (bank->eint_type != EINT_TYPE_WKUP)
continue;
mask = bank->eint_mask;
nr_eints = fls(mask);
ddata = devm_kzalloc(dev,
sizeof(*ddata) + nr_eints, GFP_KERNEL);
if (!ddata) {
dev_err(dev, "failed to allocate domain data\n");
return -ENOMEM;
}
ddata->bank = bank;
bank->irq_domain = irq_domain_add_linear(bank->of_node,
nr_eints, &s3c64xx_eint0_irqd_ops, ddata);
if (!bank->irq_domain) {
dev_err(dev, "wkup irq domain add failed\n");
return -ENXIO;
}
irq = bank->eint_offset;
mask = bank->eint_mask;
for (pin = 0; mask; ++pin, mask >>= 1) {
if (!(mask & 1))
continue;
data->domains[irq] = bank->irq_domain;
data->pins[irq] = pin;
ddata->eints[pin] = irq;
++irq;
}
}
return 0;
}
