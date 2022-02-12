static void exynos_gpio_irq_mask(struct irq_data *irqd)
{
struct samsung_pin_bank *bank = irq_data_get_irq_chip_data(irqd);
struct samsung_pinctrl_drv_data *d = bank->drvdata;
unsigned long reg_mask = d->ctrl->geint_mask + bank->eint_offset;
unsigned long mask;
unsigned long flags;
spin_lock_irqsave(&bank->slock, flags);
mask = readl(d->virt_base + reg_mask);
mask |= 1 << irqd->hwirq;
writel(mask, d->virt_base + reg_mask);
spin_unlock_irqrestore(&bank->slock, flags);
}
static void exynos_gpio_irq_ack(struct irq_data *irqd)
{
struct samsung_pin_bank *bank = irq_data_get_irq_chip_data(irqd);
struct samsung_pinctrl_drv_data *d = bank->drvdata;
unsigned long reg_pend = d->ctrl->geint_pend + bank->eint_offset;
writel(1 << irqd->hwirq, d->virt_base + reg_pend);
}
static void exynos_gpio_irq_unmask(struct irq_data *irqd)
{
struct samsung_pin_bank *bank = irq_data_get_irq_chip_data(irqd);
struct samsung_pinctrl_drv_data *d = bank->drvdata;
unsigned long reg_mask = d->ctrl->geint_mask + bank->eint_offset;
unsigned long mask;
unsigned long flags;
if (irqd_get_trigger_type(irqd) & IRQ_TYPE_LEVEL_MASK)
exynos_gpio_irq_ack(irqd);
spin_lock_irqsave(&bank->slock, flags);
mask = readl(d->virt_base + reg_mask);
mask &= ~(1 << irqd->hwirq);
writel(mask, d->virt_base + reg_mask);
spin_unlock_irqrestore(&bank->slock, flags);
}
static int exynos_gpio_irq_set_type(struct irq_data *irqd, unsigned int type)
{
struct samsung_pin_bank *bank = irq_data_get_irq_chip_data(irqd);
struct samsung_pin_bank_type *bank_type = bank->type;
struct samsung_pinctrl_drv_data *d = bank->drvdata;
struct samsung_pin_ctrl *ctrl = d->ctrl;
unsigned int pin = irqd->hwirq;
unsigned int shift = EXYNOS_EINT_CON_LEN * pin;
unsigned int con, trig_type;
unsigned long reg_con = ctrl->geint_con + bank->eint_offset;
unsigned long flags;
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
reg_con = bank->pctl_offset + bank_type->reg_offset[PINCFG_TYPE_FUNC];
shift = pin * bank_type->fld_width[PINCFG_TYPE_FUNC];
mask = (1 << bank_type->fld_width[PINCFG_TYPE_FUNC]) - 1;
spin_lock_irqsave(&bank->slock, flags);
con = readl(d->virt_base + reg_con);
con &= ~(mask << shift);
con |= EXYNOS_EINT_FUNC << shift;
writel(con, d->virt_base + reg_con);
spin_unlock_irqrestore(&bank->slock, flags);
return 0;
}
static int exynos_gpio_irq_map(struct irq_domain *h, unsigned int virq,
irq_hw_number_t hw)
{
struct samsung_pin_bank *b = h->host_data;
irq_set_chip_data(virq, b);
irq_set_chip_and_handler(virq, &exynos_gpio_irq_chip,
handle_level_irq);
set_irq_flags(virq, IRQF_VALID);
return 0;
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
virq = irq_linear_revmap(bank->irq_domain, pin);
if (!virq)
return IRQ_NONE;
generic_handle_irq(virq);
return IRQ_HANDLED;
}
static int exynos_eint_gpio_init(struct samsung_pinctrl_drv_data *d)
{
struct samsung_pin_bank *bank;
struct device *dev = d->dev;
int ret;
int i;
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
bank = d->ctrl->pin_banks;
for (i = 0; i < d->ctrl->nr_banks; ++i, ++bank) {
if (bank->eint_type != EINT_TYPE_GPIO)
continue;
bank->irq_domain = irq_domain_add_linear(bank->of_node,
bank->nr_pins, &exynos_gpio_irqd_ops, bank);
if (!bank->irq_domain) {
dev_err(dev, "gpio irq domain add failed\n");
ret = -ENXIO;
goto err_domains;
}
bank->soc_priv = devm_kzalloc(d->dev,
sizeof(struct exynos_eint_gpio_save), GFP_KERNEL);
if (!bank->soc_priv) {
irq_domain_remove(bank->irq_domain);
ret = -ENOMEM;
goto err_domains;
}
}
return 0;
err_domains:
for (--i, --bank; i >= 0; --i, --bank) {
if (bank->eint_type != EINT_TYPE_GPIO)
continue;
irq_domain_remove(bank->irq_domain);
}
return ret;
}
static void exynos_wkup_irq_mask(struct irq_data *irqd)
{
struct samsung_pin_bank *b = irq_data_get_irq_chip_data(irqd);
struct samsung_pinctrl_drv_data *d = b->drvdata;
unsigned long reg_mask = d->ctrl->weint_mask + b->eint_offset;
unsigned long mask;
unsigned long flags;
spin_lock_irqsave(&b->slock, flags);
mask = readl(d->virt_base + reg_mask);
mask |= 1 << irqd->hwirq;
writel(mask, d->virt_base + reg_mask);
spin_unlock_irqrestore(&b->slock, flags);
}
static void exynos_wkup_irq_ack(struct irq_data *irqd)
{
struct samsung_pin_bank *b = irq_data_get_irq_chip_data(irqd);
struct samsung_pinctrl_drv_data *d = b->drvdata;
unsigned long pend = d->ctrl->weint_pend + b->eint_offset;
writel(1 << irqd->hwirq, d->virt_base + pend);
}
static void exynos_wkup_irq_unmask(struct irq_data *irqd)
{
struct samsung_pin_bank *b = irq_data_get_irq_chip_data(irqd);
struct samsung_pinctrl_drv_data *d = b->drvdata;
unsigned long reg_mask = d->ctrl->weint_mask + b->eint_offset;
unsigned long mask;
unsigned long flags;
if (irqd_get_trigger_type(irqd) & IRQ_TYPE_LEVEL_MASK)
exynos_wkup_irq_ack(irqd);
spin_lock_irqsave(&b->slock, flags);
mask = readl(d->virt_base + reg_mask);
mask &= ~(1 << irqd->hwirq);
writel(mask, d->virt_base + reg_mask);
spin_unlock_irqrestore(&b->slock, flags);
}
static int exynos_wkup_irq_set_type(struct irq_data *irqd, unsigned int type)
{
struct samsung_pin_bank *bank = irq_data_get_irq_chip_data(irqd);
struct samsung_pin_bank_type *bank_type = bank->type;
struct samsung_pinctrl_drv_data *d = bank->drvdata;
unsigned int pin = irqd->hwirq;
unsigned long reg_con = d->ctrl->weint_con + bank->eint_offset;
unsigned long shift = EXYNOS_EINT_CON_LEN * pin;
unsigned long con, trig_type;
unsigned long flags;
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
reg_con = bank->pctl_offset + bank_type->reg_offset[PINCFG_TYPE_FUNC];
shift = pin * bank_type->fld_width[PINCFG_TYPE_FUNC];
mask = (1 << bank_type->fld_width[PINCFG_TYPE_FUNC]) - 1;
spin_lock_irqsave(&bank->slock, flags);
con = readl(d->virt_base + reg_con);
con &= ~(mask << shift);
con |= EXYNOS_EINT_FUNC << shift;
writel(con, d->virt_base + reg_con);
spin_unlock_irqrestore(&bank->slock, flags);
return 0;
}
u32 exynos_get_eint_wake_mask(void)
{
return exynos_eint_wake_mask;
}
static int exynos_wkup_irq_set_wake(struct irq_data *irqd, unsigned int on)
{
struct samsung_pin_bank *bank = irq_data_get_irq_chip_data(irqd);
unsigned long bit = 1UL << (2 * bank->eint_offset + irqd->hwirq);
pr_info("wake %s for irq %d\n", on ? "enabled" : "disabled", irqd->irq);
if (!on)
exynos_eint_wake_mask |= bit;
else
exynos_eint_wake_mask &= ~bit;
return 0;
}
static void exynos_irq_eint0_15(unsigned int irq, struct irq_desc *desc)
{
struct exynos_weint_data *eintd = irq_get_handler_data(irq);
struct samsung_pin_bank *bank = eintd->bank;
struct irq_chip *chip = irq_get_chip(irq);
int eint_irq;
chained_irq_enter(chip, desc);
chip->irq_mask(&desc->irq_data);
if (chip->irq_ack)
chip->irq_ack(&desc->irq_data);
eint_irq = irq_linear_revmap(bank->irq_domain, eintd->irq);
generic_handle_irq(eint_irq);
chip->irq_unmask(&desc->irq_data);
chained_irq_exit(chip, desc);
}
static inline void exynos_irq_demux_eint(unsigned long pend,
struct irq_domain *domain)
{
unsigned int irq;
while (pend) {
irq = fls(pend) - 1;
generic_handle_irq(irq_find_mapping(domain, irq));
pend &= ~(1 << irq);
}
}
static void exynos_irq_demux_eint16_31(unsigned int irq, struct irq_desc *desc)
{
struct irq_chip *chip = irq_get_chip(irq);
struct exynos_muxed_weint_data *eintd = irq_get_handler_data(irq);
struct samsung_pinctrl_drv_data *d = eintd->banks[0]->drvdata;
struct samsung_pin_ctrl *ctrl = d->ctrl;
unsigned long pend;
unsigned long mask;
int i;
chained_irq_enter(chip, desc);
for (i = 0; i < eintd->nr_banks; ++i) {
struct samsung_pin_bank *b = eintd->banks[i];
pend = readl(d->virt_base + ctrl->weint_pend + b->eint_offset);
mask = readl(d->virt_base + ctrl->weint_mask + b->eint_offset);
exynos_irq_demux_eint(pend & ~mask, b->irq_domain);
}
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
struct samsung_pin_bank *bank;
struct exynos_weint_data *weint_data;
struct exynos_muxed_weint_data *muxed_data;
unsigned int muxed_banks = 0;
unsigned int i;
int idx, irq;
for_each_child_of_node(dev->of_node, np) {
if (of_match_node(exynos_wkup_irq_ids, np)) {
wkup_np = np;
break;
}
}
if (!wkup_np)
return -ENODEV;
bank = d->ctrl->pin_banks;
for (i = 0; i < d->ctrl->nr_banks; ++i, ++bank) {
if (bank->eint_type != EINT_TYPE_WKUP)
continue;
bank->irq_domain = irq_domain_add_linear(bank->of_node,
bank->nr_pins, &exynos_wkup_irqd_ops, bank);
if (!bank->irq_domain) {
dev_err(dev, "wkup irq domain add failed\n");
return -ENXIO;
}
if (!of_find_property(bank->of_node, "interrupts", NULL)) {
bank->eint_type = EINT_TYPE_WKUP_MUX;
++muxed_banks;
continue;
}
weint_data = devm_kzalloc(dev, bank->nr_pins
* sizeof(*weint_data), GFP_KERNEL);
if (!weint_data) {
dev_err(dev, "could not allocate memory for weint_data\n");
return -ENOMEM;
}
for (idx = 0; idx < bank->nr_pins; ++idx) {
irq = irq_of_parse_and_map(bank->of_node, idx);
if (!irq) {
dev_err(dev, "irq number for eint-%s-%d not found\n",
bank->name, idx);
continue;
}
weint_data[idx].irq = idx;
weint_data[idx].bank = bank;
irq_set_handler_data(irq, &weint_data[idx]);
irq_set_chained_handler(irq, exynos_irq_eint0_15);
}
}
if (!muxed_banks)
return 0;
irq = irq_of_parse_and_map(wkup_np, 0);
if (!irq) {
dev_err(dev, "irq number for muxed EINTs not found\n");
return 0;
}
muxed_data = devm_kzalloc(dev, sizeof(*muxed_data)
+ muxed_banks*sizeof(struct samsung_pin_bank *), GFP_KERNEL);
if (!muxed_data) {
dev_err(dev, "could not allocate memory for muxed_data\n");
return -ENOMEM;
}
irq_set_chained_handler(irq, exynos_irq_demux_eint16_31);
irq_set_handler_data(irq, muxed_data);
bank = d->ctrl->pin_banks;
idx = 0;
for (i = 0; i < d->ctrl->nr_banks; ++i, ++bank) {
if (bank->eint_type != EINT_TYPE_WKUP_MUX)
continue;
muxed_data->banks[idx++] = bank;
}
muxed_data->nr_banks = muxed_banks;
return 0;
}
static void exynos_pinctrl_suspend_bank(
struct samsung_pinctrl_drv_data *drvdata,
struct samsung_pin_bank *bank)
{
struct exynos_eint_gpio_save *save = bank->soc_priv;
void __iomem *regs = drvdata->virt_base;
save->eint_con = readl(regs + EXYNOS_GPIO_ECON_OFFSET
+ bank->eint_offset);
save->eint_fltcon0 = readl(regs + EXYNOS_GPIO_EFLTCON_OFFSET
+ 2 * bank->eint_offset);
save->eint_fltcon1 = readl(regs + EXYNOS_GPIO_EFLTCON_OFFSET
+ 2 * bank->eint_offset + 4);
pr_debug("%s: save con %#010x\n", bank->name, save->eint_con);
pr_debug("%s: save fltcon0 %#010x\n", bank->name, save->eint_fltcon0);
pr_debug("%s: save fltcon1 %#010x\n", bank->name, save->eint_fltcon1);
}
static void exynos_pinctrl_suspend(struct samsung_pinctrl_drv_data *drvdata)
{
struct samsung_pin_ctrl *ctrl = drvdata->ctrl;
struct samsung_pin_bank *bank = ctrl->pin_banks;
int i;
for (i = 0; i < ctrl->nr_banks; ++i, ++bank)
if (bank->eint_type == EINT_TYPE_GPIO)
exynos_pinctrl_suspend_bank(drvdata, bank);
}
static void exynos_pinctrl_resume_bank(
struct samsung_pinctrl_drv_data *drvdata,
struct samsung_pin_bank *bank)
{
struct exynos_eint_gpio_save *save = bank->soc_priv;
void __iomem *regs = drvdata->virt_base;
pr_debug("%s: con %#010x => %#010x\n", bank->name,
readl(regs + EXYNOS_GPIO_ECON_OFFSET
+ bank->eint_offset), save->eint_con);
pr_debug("%s: fltcon0 %#010x => %#010x\n", bank->name,
readl(regs + EXYNOS_GPIO_EFLTCON_OFFSET
+ 2 * bank->eint_offset), save->eint_fltcon0);
pr_debug("%s: fltcon1 %#010x => %#010x\n", bank->name,
readl(regs + EXYNOS_GPIO_EFLTCON_OFFSET
+ 2 * bank->eint_offset + 4), save->eint_fltcon1);
writel(save->eint_con, regs + EXYNOS_GPIO_ECON_OFFSET
+ bank->eint_offset);
writel(save->eint_fltcon0, regs + EXYNOS_GPIO_EFLTCON_OFFSET
+ 2 * bank->eint_offset);
writel(save->eint_fltcon1, regs + EXYNOS_GPIO_EFLTCON_OFFSET
+ 2 * bank->eint_offset + 4);
}
static void exynos_pinctrl_resume(struct samsung_pinctrl_drv_data *drvdata)
{
struct samsung_pin_ctrl *ctrl = drvdata->ctrl;
struct samsung_pin_bank *bank = ctrl->pin_banks;
int i;
for (i = 0; i < ctrl->nr_banks; ++i, ++bank)
if (bank->eint_type == EINT_TYPE_GPIO)
exynos_pinctrl_resume_bank(drvdata, bank);
}
