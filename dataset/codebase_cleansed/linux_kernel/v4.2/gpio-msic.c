static int msic_gpio_to_ireg(unsigned offset)
{
if (offset >= MSIC_NUM_GPIO)
return -EINVAL;
if (offset < 8)
return INTEL_MSIC_GPIO0LV0CTLI - offset;
if (offset < 16)
return INTEL_MSIC_GPIO1LV0CTLI - offset + 8;
if (offset < 20)
return INTEL_MSIC_GPIO0HV0CTLI - offset + 16;
return INTEL_MSIC_GPIO1HV0CTLI - offset + 20;
}
static int msic_gpio_to_oreg(unsigned offset)
{
if (offset >= MSIC_NUM_GPIO)
return -EINVAL;
if (offset < 8)
return INTEL_MSIC_GPIO0LV0CTLO - offset;
if (offset < 16)
return INTEL_MSIC_GPIO1LV0CTLO - offset + 8;
if (offset < 20)
return INTEL_MSIC_GPIO0HV0CTLO - offset + 16;
return INTEL_MSIC_GPIO1HV0CTLO - offset + 20;
}
static int msic_gpio_direction_input(struct gpio_chip *chip, unsigned offset)
{
int reg;
reg = msic_gpio_to_oreg(offset);
if (reg < 0)
return reg;
return intel_msic_reg_update(reg, MSIC_GPIO_DIR_IN, MSIC_GPIO_DIR_MASK);
}
static int msic_gpio_direction_output(struct gpio_chip *chip,
unsigned offset, int value)
{
int reg;
unsigned mask;
value = (!!value) | MSIC_GPIO_DIR_OUT;
mask = MSIC_GPIO_DIR_MASK | MSIC_GPIO_DOUT_MASK;
reg = msic_gpio_to_oreg(offset);
if (reg < 0)
return reg;
return intel_msic_reg_update(reg, value, mask);
}
static int msic_gpio_get(struct gpio_chip *chip, unsigned offset)
{
u8 r;
int ret;
int reg;
reg = msic_gpio_to_ireg(offset);
if (reg < 0)
return reg;
ret = intel_msic_reg_read(reg, &r);
if (ret < 0)
return ret;
return r & MSIC_GPIO_DIN_MASK;
}
static void msic_gpio_set(struct gpio_chip *chip, unsigned offset, int value)
{
int reg;
reg = msic_gpio_to_oreg(offset);
if (reg < 0)
return;
intel_msic_reg_update(reg, !!value , MSIC_GPIO_DOUT_MASK);
}
static int msic_irq_type(struct irq_data *data, unsigned type)
{
struct msic_gpio *mg = irq_data_get_irq_chip_data(data);
u32 gpio = data->irq - mg->irq_base;
if (gpio >= mg->chip.ngpio)
return -EINVAL;
mg->trig_change_mask |= (1 << gpio);
mg->trig_type = type;
return 0;
}
static int msic_gpio_to_irq(struct gpio_chip *chip, unsigned offset)
{
struct msic_gpio *mg = container_of(chip, struct msic_gpio, chip);
return mg->irq_base + offset;
}
static void msic_bus_lock(struct irq_data *data)
{
struct msic_gpio *mg = irq_data_get_irq_chip_data(data);
mutex_lock(&mg->buslock);
}
static void msic_bus_sync_unlock(struct irq_data *data)
{
struct msic_gpio *mg = irq_data_get_irq_chip_data(data);
int offset;
int reg;
u8 trig = 0;
if (mg->trig_change_mask) {
offset = __ffs(mg->trig_change_mask);
reg = msic_gpio_to_ireg(offset);
if (reg < 0)
goto out;
if (mg->trig_type & IRQ_TYPE_EDGE_RISING)
trig |= MSIC_GPIO_TRIG_RISE;
if (mg->trig_type & IRQ_TYPE_EDGE_FALLING)
trig |= MSIC_GPIO_TRIG_FALL;
intel_msic_reg_update(reg, trig, MSIC_GPIO_INTCNT_MASK);
mg->trig_change_mask = 0;
}
out:
mutex_unlock(&mg->buslock);
}
static void msic_irq_unmask(struct irq_data *data) { }
static void msic_irq_mask(struct irq_data *data) { }
static void msic_gpio_irq_handler(unsigned irq, struct irq_desc *desc)
{
struct irq_data *data = irq_desc_get_irq_data(desc);
struct msic_gpio *mg = irq_data_get_irq_handler_data(data);
struct irq_chip *chip = irq_data_get_irq_chip(data);
struct intel_msic *msic = pdev_to_intel_msic(mg->pdev);
int i;
int bitnr;
u8 pin;
unsigned long pending = 0;
for (i = 0; i < (mg->chip.ngpio / BITS_PER_BYTE); i++) {
intel_msic_irq_read(msic, INTEL_MSIC_GPIO0LVIRQ + i, &pin);
pending = pin;
if (pending) {
for_each_set_bit(bitnr, &pending, BITS_PER_BYTE)
generic_handle_irq(mg->irq_base +
(i * BITS_PER_BYTE) + bitnr);
}
}
chip->irq_eoi(data);
}
static int platform_msic_gpio_probe(struct platform_device *pdev)
{
struct device *dev = &pdev->dev;
struct intel_msic_gpio_pdata *pdata = dev_get_platdata(dev);
struct msic_gpio *mg;
int irq = platform_get_irq(pdev, 0);
int retval;
int i;
if (irq < 0) {
dev_err(dev, "no IRQ line\n");
return -EINVAL;
}
if (!pdata || !pdata->gpio_base) {
dev_err(dev, "incorrect or missing platform data\n");
return -EINVAL;
}
mg = kzalloc(sizeof(*mg), GFP_KERNEL);
if (!mg)
return -ENOMEM;
dev_set_drvdata(dev, mg);
mg->pdev = pdev;
mg->irq = irq;
mg->irq_base = pdata->gpio_base + MSIC_GPIO_IRQ_OFFSET;
mg->chip.label = "msic_gpio";
mg->chip.direction_input = msic_gpio_direction_input;
mg->chip.direction_output = msic_gpio_direction_output;
mg->chip.get = msic_gpio_get;
mg->chip.set = msic_gpio_set;
mg->chip.to_irq = msic_gpio_to_irq;
mg->chip.base = pdata->gpio_base;
mg->chip.ngpio = MSIC_NUM_GPIO;
mg->chip.can_sleep = true;
mg->chip.dev = dev;
mutex_init(&mg->buslock);
retval = gpiochip_add(&mg->chip);
if (retval) {
dev_err(dev, "Adding MSIC gpio chip failed\n");
goto err;
}
for (i = 0; i < mg->chip.ngpio; i++) {
irq_set_chip_data(i + mg->irq_base, mg);
irq_set_chip_and_handler(i + mg->irq_base,
&msic_irqchip,
handle_simple_irq);
}
irq_set_chained_handler_and_data(mg->irq, msic_gpio_irq_handler, mg);
return 0;
err:
kfree(mg);
return retval;
}
static int __init platform_msic_gpio_init(void)
{
return platform_driver_register(&platform_msic_gpio_driver);
}
