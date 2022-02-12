static void exynos_gpio_irq_unmask(struct irq_data *irqd)
{
struct samsung_pinctrl_drv_data *d = irqd->domain->host_data;
struct exynos_geint_data *edata = irq_data_get_irq_handler_data(irqd);
unsigned long reg_mask = d->ctrl->geint_mask + edata->eint_offset;
unsigned long mask;
mask = readl(d->virt_base + reg_mask);
mask &= ~(1 << edata->pin);
writel(mask, d->virt_base + reg_mask);
}
static void exynos_gpio_irq_mask(struct irq_data *irqd)
{
struct samsung_pinctrl_drv_data *d = irqd->domain->host_data;
struct exynos_geint_data *edata = irq_data_get_irq_handler_data(irqd);
unsigned long reg_mask = d->ctrl->geint_mask + edata->eint_offset;
unsigned long mask;
mask = readl(d->virt_base + reg_mask);
mask |= 1 << edata->pin;
writel(mask, d->virt_base + reg_mask);
}
static void exynos_gpio_irq_ack(struct irq_data *irqd)
{
struct samsung_pinctrl_drv_data *d = irqd->domain->host_data;
struct exynos_geint_data *edata = irq_data_get_irq_handler_data(irqd);
unsigned long reg_pend = d->ctrl->geint_pend + edata->eint_offset;
writel(1 << edata->pin, d->virt_base + reg_pend);
}
static int exynos_gpio_irq_set_type(struct irq_data *irqd, unsigned int type)
{
struct samsung_pinctrl_drv_data *d = irqd->domain->host_data;
struct samsung_pin_ctrl *ctrl = d->ctrl;
struct exynos_geint_data *edata = irq_data_get_irq_handler_data(irqd);
struct samsung_pin_bank *bank = edata->bank;
unsigned int shift = EXYNOS_EINT_CON_LEN * edata->pin;
unsigned int con, trig_type;
unsigned long reg_con = ctrl->geint_con + edata->eint_offset;
unsigned int mask;
switch (type) {
case IRQ_TYPE_EDGE_RISING:
trig_type = EXYNOS_EINT_EDGE_RISING;
break;
case IRQ_TYPE_EDGE_FALLING:
trig_type = EXYNOS_EINT_EDGE_FALLING;
break;
case IRQ_TYPE_EDGE_BOTH:
trig_type = EXYNOS_EINT_EDGE_BOTH;
break;
case IRQ_TYPE_LEVEL_HIGH:
trig_type = EXYNOS_EINT_LEVEL_HIGH;
break;
case IRQ_TYPE_LEVEL_LOW:
trig_type = EXYNOS_EINT_LEVEL_LOW;
break;
default:
pr_err("unsupported external interrupt type\n");
return -EINVAL;
}
if (type & IRQ_TYPE_EDGE_BOTH)
__irq_set_handler_locked(irqd->irq, handle_edge_irq);
else
__irq_set_handler_locked(irqd->irq, handle_level_irq);
con = readl(d->virt_base + reg_con);
con &= ~(EXYNOS_EINT_CON_MASK << shift);
con |= trig_type << shift;
writel(con, d->virt_base + reg_con);
reg_con = bank->pctl_offset;
shift = edata->pin * bank->func_width;
mask = (1 << bank->func_width) - 1;
con = readl(d->virt_base + reg_con);
con &= ~(mask << shift);
con |= EXYNOS_EINT_FUNC << shift;
writel(con, d->virt_base + reg_con);
return 0;
}
static struct exynos_geint_data *exynos_get_eint_data(irq_hw_number_t hw,
struct samsung_pinctrl_drv_data *d)
{
struct samsung_pin_bank *bank = d->ctrl->pin_banks;
struct exynos_geint_data *eint_data;
unsigned int nr_banks = d->ctrl->nr_banks, idx;
unsigned int irq_base = 0, eint_offset = 0;
if (hw >= d->ctrl->nr_gint) {
dev_err(d->dev, "unsupported ext-gpio interrupt\n");
return NULL;
}
for (idx = 0; idx < nr_banks; idx++, bank++) {
if (bank->eint_type != EINT_TYPE_GPIO)
continue;
if ((hw >= irq_base) && (hw < (irq_base + bank->nr_pins)))
break;
irq_base += bank->nr_pins;
eint_offset += 4;
}
if (idx == nr_banks) {
dev_err(d->dev, "pin bank not found for ext-gpio interrupt\n");
return NULL;
}
eint_data = devm_kzalloc(d->dev, sizeof(*eint_data), GFP_KERNEL);
if (!eint_data) {
dev_err(d->dev, "no memory for eint-gpio data\n");
return NULL;
}
eint_data->bank = bank;
eint_data->pin = hw - irq_base;
eint_data->eint_offset = eint_offset;
return eint_data;
}
static int exynos_gpio_irq_map(struct irq_domain *h, unsigned int virq,
irq_hw_number_t hw)
{
struct samsung_pinctrl_drv_data *d = h->host_data;
struct exynos_geint_data *eint_data;
eint_data = exynos_get_eint_data(hw, d);
if (!eint_data)
return -EINVAL;
irq_set_handler_data(virq, eint_data);
irq_set_chip_data(virq, h->host_data);
irq_set_chip_and_handler(virq, &exynos_gpio_irq_chip,
handle_level_irq);
set_irq_flags(virq, IRQF_VALID);
return 0;
}
static void exynos_gpio_irq_unmap(struct irq_domain *h, unsigned int virq)
{
struct samsung_pinctrl_drv_data *d = h->host_data;
struct exynos_geint_data *eint_data;
eint_data = irq_get_handler_data(virq);
devm_kfree(d->dev, eint_data);
}
static irqreturn_t exynos_eint_gpio_irq(int irq, void *data)
{
struct samsung_pinctrl_drv_data *d = data;
struct samsung_pin_ctrl *ctrl = d->ctrl;
struct samsung_pin_bank *bank = ctrl->pin_banks;
unsigned int svc, group, pin, virq;
svc = readl(d->virt_base + ctrl->svc);
group = EXYNOS_SVC_GROUP(svc);
pin = svc & EXYNOS_SVC_NUM_MASK;
if (!group)
return IRQ_HANDLED;
bank += (group - 1);
virq = irq_linear_revmap(d->gpio_irqd, bank->irq_base + pin);
if (!virq)
return IRQ_NONE;
generic_handle_irq(virq);
return IRQ_HANDLED;
}
static int exynos_eint_gpio_init(struct samsung_pinctrl_drv_data *d)
{
struct device *dev = d->dev;
unsigned int ret;
if (!d->irq) {
dev_err(dev, "irq number not available\n");
return -EINVAL;
}
ret = devm_request_irq(dev, d->irq, exynos_eint_gpio_irq,
0, dev_name(dev), d);
if (ret) {
dev_err(dev, "irq request failed\n");
return -ENXIO;
}
d->gpio_irqd = irq_domain_add_linear(dev->of_node, d->ctrl->nr_gint,
&exynos_gpio_irqd_ops, d);
if (!d->gpio_irqd) {
dev_err(dev, "gpio irq domain allocation failed\n");
return -ENXIO;
}
return 0;
}
static void exynos_wkup_irq_unmask(struct irq_data *irqd)
{
struct samsung_pinctrl_drv_data *d = irq_data_get_irq_chip_data(irqd);
unsigned int bank = irqd->hwirq / EXYNOS_EINT_MAX_PER_BANK;
unsigned int pin = irqd->hwirq & (EXYNOS_EINT_MAX_PER_BANK - 1);
unsigned long reg_mask = d->ctrl->weint_mask + (bank << 2);
unsigned long mask;
mask = readl(d->virt_base + reg_mask);
mask &= ~(1 << pin);
writel(mask, d->virt_base + reg_mask);
}
static void exynos_wkup_irq_mask(struct irq_data *irqd)
{
struct samsung_pinctrl_drv_data *d = irq_data_get_irq_chip_data(irqd);
unsigned int bank = irqd->hwirq / EXYNOS_EINT_MAX_PER_BANK;
unsigned int pin = irqd->hwirq & (EXYNOS_EINT_MAX_PER_BANK - 1);
unsigned long reg_mask = d->ctrl->weint_mask + (bank << 2);
unsigned long mask;
mask = readl(d->virt_base + reg_mask);
mask |= 1 << pin;
writel(mask, d->virt_base + reg_mask);
}
static void exynos_wkup_irq_ack(struct irq_data *irqd)
{
struct samsung_pinctrl_drv_data *d = irq_data_get_irq_chip_data(irqd);
unsigned int bank = irqd->hwirq / EXYNOS_EINT_MAX_PER_BANK;
unsigned int pin = irqd->hwirq & (EXYNOS_EINT_MAX_PER_BANK - 1);
unsigned long pend = d->ctrl->weint_pend + (bank << 2);
writel(1 << pin, d->virt_base + pend);
}
static int exynos_wkup_irq_set_type(struct irq_data *irqd, unsigned int type)
{
struct samsung_pinctrl_drv_data *d = irq_data_get_irq_chip_data(irqd);
unsigned int bank = irqd->hwirq / EXYNOS_EINT_MAX_PER_BANK;
unsigned int pin = irqd->hwirq & (EXYNOS_EINT_MAX_PER_BANK - 1);
unsigned long reg_con = d->ctrl->weint_con + (bank << 2);
unsigned long shift = EXYNOS_EINT_CON_LEN * pin;
unsigned long con, trig_type;
switch (type) {
case IRQ_TYPE_EDGE_RISING:
trig_type = EXYNOS_EINT_EDGE_RISING;
break;
case IRQ_TYPE_EDGE_FALLING:
trig_type = EXYNOS_EINT_EDGE_FALLING;
break;
case IRQ_TYPE_EDGE_BOTH:
trig_type = EXYNOS_EINT_EDGE_BOTH;
break;
case IRQ_TYPE_LEVEL_HIGH:
trig_type = EXYNOS_EINT_LEVEL_HIGH;
break;
case IRQ_TYPE_LEVEL_LOW:
trig_type = EXYNOS_EINT_LEVEL_LOW;
break;
default:
pr_err("unsupported external interrupt type\n");
return -EINVAL;
}
if (type & IRQ_TYPE_EDGE_BOTH)
__irq_set_handler_locked(irqd->irq, handle_edge_irq);
else
__irq_set_handler_locked(irqd->irq, handle_level_irq);
con = readl(d->virt_base + reg_con);
con &= ~(EXYNOS_EINT_CON_MASK << shift);
con |= trig_type << shift;
writel(con, d->virt_base + reg_con);
return 0;
}
static void exynos_irq_eint0_15(unsigned int irq, struct irq_desc *desc)
{
struct exynos_weint_data *eintd = irq_get_handler_data(irq);
struct irq_chip *chip = irq_get_chip(irq);
int eint_irq;
chained_irq_enter(chip, desc);
chip->irq_mask(&desc->irq_data);
if (chip->irq_ack)
chip->irq_ack(&desc->irq_data);
eint_irq = irq_linear_revmap(eintd->domain, eintd->irq);
generic_handle_irq(eint_irq);
chip->irq_unmask(&desc->irq_data);
chained_irq_exit(chip, desc);
}
static inline void exynos_irq_demux_eint(int irq_base, unsigned long pend,
struct irq_domain *domain)
{
unsigned int irq;
while (pend) {
irq = fls(pend) - 1;
generic_handle_irq(irq_find_mapping(domain, irq_base + irq));
pend &= ~(1 << irq);
}
}
static void exynos_irq_demux_eint16_31(unsigned int irq, struct irq_desc *desc)
{
struct irq_chip *chip = irq_get_chip(irq);
struct exynos_weint_data *eintd = irq_get_handler_data(irq);
struct samsung_pinctrl_drv_data *d = eintd->domain->host_data;
unsigned long pend;
unsigned long mask;
chained_irq_enter(chip, desc);
pend = readl(d->virt_base + d->ctrl->weint_pend + 0x8);
mask = readl(d->virt_base + d->ctrl->weint_mask + 0x8);
exynos_irq_demux_eint(16, pend & ~mask, eintd->domain);
pend = readl(d->virt_base + d->ctrl->weint_pend + 0xC);
mask = readl(d->virt_base + d->ctrl->weint_mask + 0xC);
exynos_irq_demux_eint(24, pend & ~mask, eintd->domain);
chained_irq_exit(chip, desc);
}
static int exynos_wkup_irq_map(struct irq_domain *h, unsigned int virq,
irq_hw_number_t hw)
{
irq_set_chip_and_handler(virq, &exynos_wkup_irq_chip, handle_level_irq);
irq_set_chip_data(virq, h->host_data);
set_irq_flags(virq, IRQF_VALID);
return 0;
}
static int exynos_eint_wkup_init(struct samsung_pinctrl_drv_data *d)
{
struct device *dev = d->dev;
struct device_node *wkup_np = NULL;
struct device_node *np;
struct exynos_weint_data *weint_data;
int idx, irq;
for_each_child_of_node(dev->of_node, np) {
if (of_match_node(exynos_wkup_irq_ids, np)) {
wkup_np = np;
break;
}
}
if (!wkup_np)
return -ENODEV;
d->wkup_irqd = irq_domain_add_linear(wkup_np, d->ctrl->nr_wint,
&exynos_wkup_irqd_ops, d);
if (!d->wkup_irqd) {
dev_err(dev, "wakeup irq domain allocation failed\n");
return -ENXIO;
}
weint_data = devm_kzalloc(dev, sizeof(*weint_data) * 17, GFP_KERNEL);
if (!weint_data) {
dev_err(dev, "could not allocate memory for weint_data\n");
return -ENOMEM;
}
irq = irq_of_parse_and_map(wkup_np, 16);
if (irq) {
weint_data[16].domain = d->wkup_irqd;
irq_set_chained_handler(irq, exynos_irq_demux_eint16_31);
irq_set_handler_data(irq, &weint_data[16]);
} else {
dev_err(dev, "irq number for EINT16-32 not found\n");
}
for (idx = 0; idx < 16; idx++) {
weint_data[idx].domain = d->wkup_irqd;
weint_data[idx].irq = idx;
irq = irq_of_parse_and_map(wkup_np, idx);
if (irq) {
irq_set_handler_data(irq, &weint_data[idx]);
irq_set_chained_handler(irq, exynos_irq_eint0_15);
} else {
dev_err(dev, "irq number for eint-%x not found\n", idx);
}
}
return 0;
}
