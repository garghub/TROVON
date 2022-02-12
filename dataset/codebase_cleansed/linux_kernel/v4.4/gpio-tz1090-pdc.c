static inline void pdc_write(struct tz1090_pdc_gpio *priv, unsigned int reg_offs,
unsigned int data)
{
writel(data, priv->reg + reg_offs);
}
static inline unsigned int pdc_read(struct tz1090_pdc_gpio *priv,
unsigned int reg_offs)
{
return readl(priv->reg + reg_offs);
}
static int tz1090_pdc_gpio_direction_input(struct gpio_chip *chip,
unsigned int offset)
{
struct tz1090_pdc_gpio *priv = to_pdc(chip);
u32 value;
int lstat;
__global_lock2(lstat);
value = pdc_read(priv, REG_SOC_GPIO_CONTROL1);
value |= BIT(offset);
pdc_write(priv, REG_SOC_GPIO_CONTROL1, value);
__global_unlock2(lstat);
return 0;
}
static int tz1090_pdc_gpio_direction_output(struct gpio_chip *chip,
unsigned int offset,
int output_value)
{
struct tz1090_pdc_gpio *priv = to_pdc(chip);
u32 value;
int lstat;
__global_lock2(lstat);
if (offset < 6) {
value = pdc_read(priv, REG_SOC_GPIO_CONTROL0);
if (output_value)
value |= BIT(offset);
else
value &= ~BIT(offset);
pdc_write(priv, REG_SOC_GPIO_CONTROL0, value);
}
value = pdc_read(priv, REG_SOC_GPIO_CONTROL1);
value &= ~BIT(offset);
pdc_write(priv, REG_SOC_GPIO_CONTROL1, value);
__global_unlock2(lstat);
return 0;
}
static int tz1090_pdc_gpio_get(struct gpio_chip *chip, unsigned int offset)
{
struct tz1090_pdc_gpio *priv = to_pdc(chip);
return pdc_read(priv, REG_SOC_GPIO_STATUS) & BIT(offset);
}
static void tz1090_pdc_gpio_set(struct gpio_chip *chip, unsigned int offset,
int output_value)
{
struct tz1090_pdc_gpio *priv = to_pdc(chip);
u32 value;
int lstat;
if (offset >= 6)
return;
__global_lock2(lstat);
value = pdc_read(priv, REG_SOC_GPIO_CONTROL0);
if (output_value)
value |= BIT(offset);
else
value &= ~BIT(offset);
pdc_write(priv, REG_SOC_GPIO_CONTROL0, value);
__global_unlock2(lstat);
}
static int tz1090_pdc_gpio_to_irq(struct gpio_chip *chip, unsigned int offset)
{
struct tz1090_pdc_gpio *priv = to_pdc(chip);
unsigned int syswake = offset - GPIO_PDC_IRQ_FIRST;
int irq;
if (syswake >= GPIO_PDC_NIRQ)
return -EINVAL;
irq = priv->irq[syswake];
if (!irq)
return -EINVAL;
return irq;
}
static int tz1090_pdc_gpio_probe(struct platform_device *pdev)
{
struct device_node *np = pdev->dev.of_node;
struct resource *res_regs;
struct tz1090_pdc_gpio *priv;
unsigned int i;
if (!np) {
dev_err(&pdev->dev, "must be instantiated via devicetree\n");
return -ENOENT;
}
res_regs = platform_get_resource(pdev, IORESOURCE_MEM, 0);
if (!res_regs) {
dev_err(&pdev->dev, "cannot find registers resource\n");
return -ENOENT;
}
priv = devm_kzalloc(&pdev->dev, sizeof(*priv), GFP_KERNEL);
if (!priv) {
dev_err(&pdev->dev, "unable to allocate driver data\n");
return -ENOMEM;
}
priv->reg = devm_ioremap(&pdev->dev, res_regs->start,
resource_size(res_regs));
if (!priv->reg) {
dev_err(&pdev->dev, "unable to ioremap registers\n");
return -ENOMEM;
}
priv->chip.label = "tz1090-pdc-gpio";
priv->chip.dev = &pdev->dev;
priv->chip.direction_input = tz1090_pdc_gpio_direction_input;
priv->chip.direction_output = tz1090_pdc_gpio_direction_output;
priv->chip.get = tz1090_pdc_gpio_get;
priv->chip.set = tz1090_pdc_gpio_set;
priv->chip.free = gpiochip_generic_free;
priv->chip.request = gpiochip_generic_request;
priv->chip.to_irq = tz1090_pdc_gpio_to_irq;
priv->chip.of_node = np;
priv->chip.base = GPIO_PDC_BASE;
priv->chip.ngpio = GPIO_PDC_NGPIO;
for (i = 0; i < GPIO_PDC_NIRQ; ++i)
priv->irq[i] = irq_of_parse_and_map(np, i);
gpiochip_add(&priv->chip);
return 0;
}
static int __init tz1090_pdc_gpio_init(void)
{
return platform_driver_register(&tz1090_pdc_gpio_driver);
}
