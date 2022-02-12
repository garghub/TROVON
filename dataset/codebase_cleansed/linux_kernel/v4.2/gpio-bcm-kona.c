static inline struct bcm_kona_gpio *to_kona_gpio(struct gpio_chip *chip)
{
return container_of(chip, struct bcm_kona_gpio, gpio_chip);
}
static inline void bcm_kona_gpio_write_lock_regs(void __iomem *reg_base,
int bank_id, u32 lockcode)
{
writel(BCM_GPIO_PASSWD, reg_base + GPIO_GPPWR_OFFSET);
writel(lockcode, reg_base + GPIO_PWD_STATUS(bank_id));
}
static void bcm_kona_gpio_lock_gpio(struct bcm_kona_gpio *kona_gpio,
unsigned gpio)
{
u32 val;
unsigned long flags;
int bank_id = GPIO_BANK(gpio);
spin_lock_irqsave(&kona_gpio->lock, flags);
val = readl(kona_gpio->reg_base + GPIO_PWD_STATUS(bank_id));
val |= BIT(gpio);
bcm_kona_gpio_write_lock_regs(kona_gpio->reg_base, bank_id, val);
spin_unlock_irqrestore(&kona_gpio->lock, flags);
}
static void bcm_kona_gpio_unlock_gpio(struct bcm_kona_gpio *kona_gpio,
unsigned gpio)
{
u32 val;
unsigned long flags;
int bank_id = GPIO_BANK(gpio);
spin_lock_irqsave(&kona_gpio->lock, flags);
val = readl(kona_gpio->reg_base + GPIO_PWD_STATUS(bank_id));
val &= ~BIT(gpio);
bcm_kona_gpio_write_lock_regs(kona_gpio->reg_base, bank_id, val);
spin_unlock_irqrestore(&kona_gpio->lock, flags);
}
static int bcm_kona_gpio_get_dir(struct gpio_chip *chip, unsigned gpio)
{
struct bcm_kona_gpio *kona_gpio = to_kona_gpio(chip);
void __iomem *reg_base = kona_gpio->reg_base;
u32 val;
val = readl(reg_base + GPIO_CONTROL(gpio)) & GPIO_GPCTR0_IOTR_MASK;
return val ? GPIOF_DIR_IN : GPIOF_DIR_OUT;
}
static void bcm_kona_gpio_set(struct gpio_chip *chip, unsigned gpio, int value)
{
struct bcm_kona_gpio *kona_gpio;
void __iomem *reg_base;
int bank_id = GPIO_BANK(gpio);
int bit = GPIO_BIT(gpio);
u32 val, reg_offset;
unsigned long flags;
kona_gpio = to_kona_gpio(chip);
reg_base = kona_gpio->reg_base;
spin_lock_irqsave(&kona_gpio->lock, flags);
if (bcm_kona_gpio_get_dir(chip, gpio) == GPIOF_DIR_IN)
goto out;
reg_offset = value ? GPIO_OUT_SET(bank_id) : GPIO_OUT_CLEAR(bank_id);
val = readl(reg_base + reg_offset);
val |= BIT(bit);
writel(val, reg_base + reg_offset);
out:
spin_unlock_irqrestore(&kona_gpio->lock, flags);
}
static int bcm_kona_gpio_get(struct gpio_chip *chip, unsigned gpio)
{
struct bcm_kona_gpio *kona_gpio;
void __iomem *reg_base;
int bank_id = GPIO_BANK(gpio);
int bit = GPIO_BIT(gpio);
u32 val, reg_offset;
unsigned long flags;
kona_gpio = to_kona_gpio(chip);
reg_base = kona_gpio->reg_base;
spin_lock_irqsave(&kona_gpio->lock, flags);
if (bcm_kona_gpio_get_dir(chip, gpio) == GPIOF_DIR_IN)
reg_offset = GPIO_IN_STATUS(bank_id);
else
reg_offset = GPIO_OUT_STATUS(bank_id);
val = readl(reg_base + reg_offset);
spin_unlock_irqrestore(&kona_gpio->lock, flags);
return !!(val & BIT(bit));
}
static int bcm_kona_gpio_request(struct gpio_chip *chip, unsigned gpio)
{
struct bcm_kona_gpio *kona_gpio = to_kona_gpio(chip);
bcm_kona_gpio_unlock_gpio(kona_gpio, gpio);
return 0;
}
static void bcm_kona_gpio_free(struct gpio_chip *chip, unsigned gpio)
{
struct bcm_kona_gpio *kona_gpio = to_kona_gpio(chip);
bcm_kona_gpio_lock_gpio(kona_gpio, gpio);
}
static int bcm_kona_gpio_direction_input(struct gpio_chip *chip, unsigned gpio)
{
struct bcm_kona_gpio *kona_gpio;
void __iomem *reg_base;
u32 val;
unsigned long flags;
kona_gpio = to_kona_gpio(chip);
reg_base = kona_gpio->reg_base;
spin_lock_irqsave(&kona_gpio->lock, flags);
val = readl(reg_base + GPIO_CONTROL(gpio));
val &= ~GPIO_GPCTR0_IOTR_MASK;
val |= GPIO_GPCTR0_IOTR_CMD_INPUT;
writel(val, reg_base + GPIO_CONTROL(gpio));
spin_unlock_irqrestore(&kona_gpio->lock, flags);
return 0;
}
static int bcm_kona_gpio_direction_output(struct gpio_chip *chip,
unsigned gpio, int value)
{
struct bcm_kona_gpio *kona_gpio;
void __iomem *reg_base;
int bank_id = GPIO_BANK(gpio);
int bit = GPIO_BIT(gpio);
u32 val, reg_offset;
unsigned long flags;
kona_gpio = to_kona_gpio(chip);
reg_base = kona_gpio->reg_base;
spin_lock_irqsave(&kona_gpio->lock, flags);
val = readl(reg_base + GPIO_CONTROL(gpio));
val &= ~GPIO_GPCTR0_IOTR_MASK;
val |= GPIO_GPCTR0_IOTR_CMD_0UTPUT;
writel(val, reg_base + GPIO_CONTROL(gpio));
reg_offset = value ? GPIO_OUT_SET(bank_id) : GPIO_OUT_CLEAR(bank_id);
val = readl(reg_base + reg_offset);
val |= BIT(bit);
writel(val, reg_base + reg_offset);
spin_unlock_irqrestore(&kona_gpio->lock, flags);
return 0;
}
static int bcm_kona_gpio_to_irq(struct gpio_chip *chip, unsigned gpio)
{
struct bcm_kona_gpio *kona_gpio;
kona_gpio = to_kona_gpio(chip);
if (gpio >= kona_gpio->gpio_chip.ngpio)
return -ENXIO;
return irq_create_mapping(kona_gpio->irq_domain, gpio);
}
static int bcm_kona_gpio_set_debounce(struct gpio_chip *chip, unsigned gpio,
unsigned debounce)
{
struct bcm_kona_gpio *kona_gpio;
void __iomem *reg_base;
u32 val, res;
unsigned long flags;
kona_gpio = to_kona_gpio(chip);
reg_base = kona_gpio->reg_base;
if ((debounce > 0 && debounce < 1000) || debounce > 128000) {
dev_err(chip->dev, "Debounce value %u not in range\n",
debounce);
return -EINVAL;
}
if (debounce != 0) {
debounce /= 1000;
res = fls(debounce) - 1;
if (res > 0 && (debounce & BIT(res - 1)))
res++;
}
spin_lock_irqsave(&kona_gpio->lock, flags);
val = readl(reg_base + GPIO_CONTROL(gpio));
val &= ~GPIO_GPCTR0_DBR_MASK;
if (debounce == 0) {
val &= ~GPIO_GPCTR0_DB_ENABLE_MASK;
} else {
val |= GPIO_GPCTR0_DB_ENABLE_MASK |
(res << GPIO_GPCTR0_DBR_SHIFT);
}
writel(val, reg_base + GPIO_CONTROL(gpio));
spin_unlock_irqrestore(&kona_gpio->lock, flags);
return 0;
}
static void bcm_kona_gpio_irq_ack(struct irq_data *d)
{
struct bcm_kona_gpio *kona_gpio;
void __iomem *reg_base;
unsigned gpio = d->hwirq;
int bank_id = GPIO_BANK(gpio);
int bit = GPIO_BIT(gpio);
u32 val;
unsigned long flags;
kona_gpio = irq_data_get_irq_chip_data(d);
reg_base = kona_gpio->reg_base;
spin_lock_irqsave(&kona_gpio->lock, flags);
val = readl(reg_base + GPIO_INT_STATUS(bank_id));
val |= BIT(bit);
writel(val, reg_base + GPIO_INT_STATUS(bank_id));
spin_unlock_irqrestore(&kona_gpio->lock, flags);
}
static void bcm_kona_gpio_irq_mask(struct irq_data *d)
{
struct bcm_kona_gpio *kona_gpio;
void __iomem *reg_base;
unsigned gpio = d->hwirq;
int bank_id = GPIO_BANK(gpio);
int bit = GPIO_BIT(gpio);
u32 val;
unsigned long flags;
kona_gpio = irq_data_get_irq_chip_data(d);
reg_base = kona_gpio->reg_base;
spin_lock_irqsave(&kona_gpio->lock, flags);
val = readl(reg_base + GPIO_INT_MASK(bank_id));
val |= BIT(bit);
writel(val, reg_base + GPIO_INT_MASK(bank_id));
spin_unlock_irqrestore(&kona_gpio->lock, flags);
}
static void bcm_kona_gpio_irq_unmask(struct irq_data *d)
{
struct bcm_kona_gpio *kona_gpio;
void __iomem *reg_base;
unsigned gpio = d->hwirq;
int bank_id = GPIO_BANK(gpio);
int bit = GPIO_BIT(gpio);
u32 val;
unsigned long flags;
kona_gpio = irq_data_get_irq_chip_data(d);
reg_base = kona_gpio->reg_base;
spin_lock_irqsave(&kona_gpio->lock, flags);
val = readl(reg_base + GPIO_INT_MSKCLR(bank_id));
val |= BIT(bit);
writel(val, reg_base + GPIO_INT_MSKCLR(bank_id));
spin_unlock_irqrestore(&kona_gpio->lock, flags);
}
static int bcm_kona_gpio_irq_set_type(struct irq_data *d, unsigned int type)
{
struct bcm_kona_gpio *kona_gpio;
void __iomem *reg_base;
unsigned gpio = d->hwirq;
u32 lvl_type;
u32 val;
unsigned long flags;
kona_gpio = irq_data_get_irq_chip_data(d);
reg_base = kona_gpio->reg_base;
switch (type & IRQ_TYPE_SENSE_MASK) {
case IRQ_TYPE_EDGE_RISING:
lvl_type = GPIO_GPCTR0_ITR_CMD_RISING_EDGE;
break;
case IRQ_TYPE_EDGE_FALLING:
lvl_type = GPIO_GPCTR0_ITR_CMD_FALLING_EDGE;
break;
case IRQ_TYPE_EDGE_BOTH:
lvl_type = GPIO_GPCTR0_ITR_CMD_BOTH_EDGE;
break;
case IRQ_TYPE_LEVEL_HIGH:
case IRQ_TYPE_LEVEL_LOW:
default:
dev_err(kona_gpio->gpio_chip.dev,
"Invalid BCM GPIO irq type 0x%x\n", type);
return -EINVAL;
}
spin_lock_irqsave(&kona_gpio->lock, flags);
val = readl(reg_base + GPIO_CONTROL(gpio));
val &= ~GPIO_GPCTR0_ITR_MASK;
val |= lvl_type << GPIO_GPCTR0_ITR_SHIFT;
writel(val, reg_base + GPIO_CONTROL(gpio));
spin_unlock_irqrestore(&kona_gpio->lock, flags);
return 0;
}
static void bcm_kona_gpio_irq_handler(unsigned int irq, struct irq_desc *desc)
{
void __iomem *reg_base;
int bit, bank_id;
unsigned long sta;
struct bcm_kona_gpio_bank *bank = irq_get_handler_data(irq);
struct irq_chip *chip = irq_desc_get_chip(desc);
chained_irq_enter(chip, desc);
reg_base = bank->kona_gpio->reg_base;
bank_id = bank->id;
while ((sta = readl(reg_base + GPIO_INT_STATUS(bank_id)) &
(~(readl(reg_base + GPIO_INT_MASK(bank_id)))))) {
for_each_set_bit(bit, &sta, 32) {
int hwirq = GPIO_PER_BANK * bank_id + bit;
int child_irq =
irq_find_mapping(bank->kona_gpio->irq_domain,
hwirq);
writel(readl(reg_base + GPIO_INT_STATUS(bank_id)) |
BIT(bit), reg_base + GPIO_INT_STATUS(bank_id));
generic_handle_irq(child_irq);
}
}
chained_irq_exit(chip, desc);
}
static int bcm_kona_gpio_irq_reqres(struct irq_data *d)
{
struct bcm_kona_gpio *kona_gpio = irq_data_get_irq_chip_data(d);
if (gpiochip_lock_as_irq(&kona_gpio->gpio_chip, d->hwirq)) {
dev_err(kona_gpio->gpio_chip.dev,
"unable to lock HW IRQ %lu for IRQ\n",
d->hwirq);
return -EINVAL;
}
return 0;
}
static void bcm_kona_gpio_irq_relres(struct irq_data *d)
{
struct bcm_kona_gpio *kona_gpio = irq_data_get_irq_chip_data(d);
gpiochip_unlock_as_irq(&kona_gpio->gpio_chip, d->hwirq);
}
static int bcm_kona_gpio_irq_map(struct irq_domain *d, unsigned int irq,
irq_hw_number_t hwirq)
{
int ret;
ret = irq_set_chip_data(irq, d->host_data);
if (ret < 0)
return ret;
irq_set_lockdep_class(irq, &gpio_lock_class);
irq_set_chip_and_handler(irq, &bcm_gpio_irq_chip, handle_simple_irq);
#ifdef CONFIG_ARM
set_irq_flags(irq, IRQF_VALID);
#else
irq_set_noprobe(irq);
#endif
return 0;
}
static void bcm_kona_gpio_irq_unmap(struct irq_domain *d, unsigned int irq)
{
irq_set_chip_and_handler(irq, NULL, NULL);
irq_set_chip_data(irq, NULL);
}
static void bcm_kona_gpio_reset(struct bcm_kona_gpio *kona_gpio)
{
void __iomem *reg_base;
int i;
reg_base = kona_gpio->reg_base;
for (i = 0; i < kona_gpio->num_bank; i++) {
bcm_kona_gpio_write_lock_regs(kona_gpio, i, UNLOCK_CODE);
writel(0xffffffff, reg_base + GPIO_INT_MASK(i));
writel(0xffffffff, reg_base + GPIO_INT_STATUS(i));
bcm_kona_gpio_write_lock_regs(kona_gpio, i, LOCK_CODE);
}
}
static int bcm_kona_gpio_probe(struct platform_device *pdev)
{
struct device *dev = &pdev->dev;
const struct of_device_id *match;
struct resource *res;
struct bcm_kona_gpio_bank *bank;
struct bcm_kona_gpio *kona_gpio;
struct gpio_chip *chip;
int ret;
int i;
match = of_match_device(bcm_kona_gpio_of_match, dev);
if (!match) {
dev_err(dev, "Failed to find gpio controller\n");
return -ENODEV;
}
kona_gpio = devm_kzalloc(dev, sizeof(*kona_gpio), GFP_KERNEL);
if (!kona_gpio)
return -ENOMEM;
kona_gpio->gpio_chip = template_chip;
chip = &kona_gpio->gpio_chip;
kona_gpio->num_bank = of_irq_count(dev->of_node);
if (kona_gpio->num_bank == 0) {
dev_err(dev, "Couldn't determine # GPIO banks\n");
return -ENOENT;
}
if (kona_gpio->num_bank > GPIO_MAX_BANK_NUM) {
dev_err(dev, "Too many GPIO banks configured (max=%d)\n",
GPIO_MAX_BANK_NUM);
return -ENXIO;
}
kona_gpio->banks = devm_kzalloc(dev,
kona_gpio->num_bank *
sizeof(*kona_gpio->banks), GFP_KERNEL);
if (!kona_gpio->banks)
return -ENOMEM;
kona_gpio->pdev = pdev;
platform_set_drvdata(pdev, kona_gpio);
chip->of_node = dev->of_node;
chip->ngpio = kona_gpio->num_bank * GPIO_PER_BANK;
kona_gpio->irq_domain = irq_domain_add_linear(dev->of_node,
chip->ngpio,
&bcm_kona_irq_ops,
kona_gpio);
if (!kona_gpio->irq_domain) {
dev_err(dev, "Couldn't allocate IRQ domain\n");
return -ENXIO;
}
res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
kona_gpio->reg_base = devm_ioremap_resource(dev, res);
if (IS_ERR(kona_gpio->reg_base)) {
ret = -ENXIO;
goto err_irq_domain;
}
for (i = 0; i < kona_gpio->num_bank; i++) {
bank = &kona_gpio->banks[i];
bank->id = i;
bank->irq = platform_get_irq(pdev, i);
bank->kona_gpio = kona_gpio;
if (bank->irq < 0) {
dev_err(dev, "Couldn't get IRQ for bank %d", i);
ret = -ENOENT;
goto err_irq_domain;
}
}
dev_info(&pdev->dev, "Setting up Kona GPIO\n");
bcm_kona_gpio_reset(kona_gpio);
ret = gpiochip_add(chip);
if (ret < 0) {
dev_err(dev, "Couldn't add GPIO chip -- %d\n", ret);
goto err_irq_domain;
}
for (i = 0; i < chip->ngpio; i++) {
int irq = bcm_kona_gpio_to_irq(chip, i);
irq_set_lockdep_class(irq, &gpio_lock_class);
irq_set_chip_and_handler(irq, &bcm_gpio_irq_chip,
handle_simple_irq);
#ifdef CONFIG_ARM
set_irq_flags(irq, IRQF_VALID);
#else
irq_set_noprobe(irq);
#endif
}
for (i = 0; i < kona_gpio->num_bank; i++) {
bank = &kona_gpio->banks[i];
irq_set_chained_handler_and_data(bank->irq,
bcm_kona_gpio_irq_handler,
bank);
}
spin_lock_init(&kona_gpio->lock);
return 0;
err_irq_domain:
irq_domain_remove(kona_gpio->irq_domain);
return ret;
}
