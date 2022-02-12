static int int0002_gpio_get(struct gpio_chip *chip, unsigned int offset)
{
return 0;
}
static void int0002_gpio_set(struct gpio_chip *chip, unsigned int offset,
int value)
{
}
static int int0002_gpio_direction_output(struct gpio_chip *chip,
unsigned int offset, int value)
{
return 0;
}
static void int0002_irq_ack(struct irq_data *data)
{
outl(GPE0A_PME_B0_STS_BIT, GPE0A_STS_PORT);
}
static void int0002_irq_unmask(struct irq_data *data)
{
u32 gpe_en_reg;
gpe_en_reg = inl(GPE0A_EN_PORT);
gpe_en_reg |= GPE0A_PME_B0_EN_BIT;
outl(gpe_en_reg, GPE0A_EN_PORT);
}
static void int0002_irq_mask(struct irq_data *data)
{
u32 gpe_en_reg;
gpe_en_reg = inl(GPE0A_EN_PORT);
gpe_en_reg &= ~GPE0A_PME_B0_EN_BIT;
outl(gpe_en_reg, GPE0A_EN_PORT);
}
static irqreturn_t int0002_irq(int irq, void *data)
{
struct gpio_chip *chip = data;
u32 gpe_sts_reg;
gpe_sts_reg = inl(GPE0A_STS_PORT);
if (!(gpe_sts_reg & GPE0A_PME_B0_STS_BIT))
return IRQ_NONE;
generic_handle_irq(irq_find_mapping(chip->irqdomain,
GPE0A_PME_B0_VIRT_GPIO_PIN));
pm_system_wakeup();
return IRQ_HANDLED;
}
static int int0002_probe(struct platform_device *pdev)
{
struct device *dev = &pdev->dev;
const struct x86_cpu_id *cpu_id;
struct gpio_chip *chip;
int irq, ret;
cpu_id = x86_match_cpu(int0002_cpu_ids);
if (!cpu_id)
return -ENODEV;
irq = platform_get_irq(pdev, 0);
if (irq < 0) {
dev_err(dev, "Error getting IRQ: %d\n", irq);
return irq;
}
chip = devm_kzalloc(dev, sizeof(*chip), GFP_KERNEL);
if (!chip)
return -ENOMEM;
chip->label = DRV_NAME;
chip->parent = dev;
chip->owner = THIS_MODULE;
chip->get = int0002_gpio_get;
chip->set = int0002_gpio_set;
chip->direction_input = int0002_gpio_get;
chip->direction_output = int0002_gpio_direction_output;
chip->base = -1;
chip->ngpio = GPE0A_PME_B0_VIRT_GPIO_PIN + 1;
chip->irq_need_valid_mask = true;
ret = devm_gpiochip_add_data(&pdev->dev, chip, NULL);
if (ret) {
dev_err(dev, "Error adding gpio chip: %d\n", ret);
return ret;
}
bitmap_clear(chip->irq_valid_mask, 0, GPE0A_PME_B0_VIRT_GPIO_PIN);
ret = devm_request_irq(dev, irq, int0002_irq,
IRQF_SHARED | IRQF_NO_THREAD, "INT0002", chip);
if (ret) {
dev_err(dev, "Error requesting IRQ %d: %d\n", irq, ret);
return ret;
}
ret = gpiochip_irqchip_add(chip, &int0002_irqchip, 0, handle_edge_irq,
IRQ_TYPE_NONE);
if (ret) {
dev_err(dev, "Error adding irqchip: %d\n", ret);
return ret;
}
gpiochip_set_chained_irqchip(chip, &int0002_irqchip, irq, NULL);
return 0;
}
