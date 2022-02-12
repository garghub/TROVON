static void pmic_program_irqtype(int gpio, int type)
{
if (type & IRQ_TYPE_EDGE_RISING)
intel_scu_ipc_update_register(GPIO0 + gpio, 0x20, 0x20);
else
intel_scu_ipc_update_register(GPIO0 + gpio, 0x00, 0x20);
if (type & IRQ_TYPE_EDGE_FALLING)
intel_scu_ipc_update_register(GPIO0 + gpio, 0x10, 0x10);
else
intel_scu_ipc_update_register(GPIO0 + gpio, 0x00, 0x10);
}
static int pmic_gpio_direction_input(struct gpio_chip *chip, unsigned offset)
{
if (offset > 8) {
pr_err("only pin 0-7 support input\n");
return -1;
}
return intel_scu_ipc_update_register(GPIO0 + offset,
GPIO_DIR, GPIO_DIR);
}
static int pmic_gpio_direction_output(struct gpio_chip *chip,
unsigned offset, int value)
{
int rc = 0;
if (offset < 8)
rc = intel_scu_ipc_update_register(GPIO0 + offset,
GPIO_DRV | (value ? GPIO_DOU : 0),
GPIO_DRV | GPIO_DOU | GPIO_DIR);
else if (offset < 16)
rc = intel_scu_ipc_update_register(GPOSWCTL0 + offset - 8,
GPOSW_DRV | (value ? GPOSW_DOU : 0),
GPOSW_DRV | GPOSW_DOU | GPOSW_RDRV);
else if (offset > 15 && offset < 24)
rc = intel_scu_ipc_update_register(GPO,
value ? 1 << (offset - 16) : 0,
1 << (offset - 16));
else {
pr_err("invalid PMIC GPIO pin %d!\n", offset);
WARN_ON(1);
}
return rc;
}
static int pmic_gpio_get(struct gpio_chip *chip, unsigned offset)
{
u8 r;
int ret;
if (offset > 8)
return -EOPNOTSUPP;
ret = intel_scu_ipc_ioread8(GPIO0 + offset, &r);
if (ret < 0)
return ret;
return r & GPIO_DIN;
}
static void pmic_gpio_set(struct gpio_chip *chip, unsigned offset, int value)
{
if (offset < 8)
intel_scu_ipc_update_register(GPIO0 + offset,
GPIO_DRV | (value ? GPIO_DOU : 0),
GPIO_DRV | GPIO_DOU);
else if (offset < 16)
intel_scu_ipc_update_register(GPOSWCTL0 + offset - 8,
GPOSW_DRV | (value ? GPOSW_DOU : 0),
GPOSW_DRV | GPOSW_DOU | GPOSW_RDRV);
else if (offset > 15 && offset < 24)
intel_scu_ipc_update_register(GPO,
value ? 1 << (offset - 16) : 0,
1 << (offset - 16));
}
static int pmic_irq_type(struct irq_data *data, unsigned type)
{
struct pmic_gpio *pg = irq_data_get_irq_chip_data(data);
u32 gpio = data->irq - pg->irq_base;
if (gpio >= pg->chip.ngpio)
return -EINVAL;
pg->trigger_type = type;
pg->update_type = gpio | GPIO_UPDATE_TYPE;
return 0;
}
static int pmic_gpio_to_irq(struct gpio_chip *chip, unsigned offset)
{
struct pmic_gpio *pg = container_of(chip, struct pmic_gpio, chip);
return pg->irq_base + offset;
}
static void pmic_bus_lock(struct irq_data *data)
{
struct pmic_gpio *pg = irq_data_get_irq_chip_data(data);
mutex_lock(&pg->buslock);
}
static void pmic_bus_sync_unlock(struct irq_data *data)
{
struct pmic_gpio *pg = irq_data_get_irq_chip_data(data);
if (pg->update_type) {
unsigned int gpio = pg->update_type & ~GPIO_UPDATE_TYPE;
pmic_program_irqtype(gpio, pg->trigger_type);
pg->update_type = 0;
}
mutex_unlock(&pg->buslock);
}
static void pmic_irq_unmask(struct irq_data *data) { }
static void pmic_irq_mask(struct irq_data *data) { }
static irqreturn_t pmic_irq_handler(int irq, void *data)
{
struct pmic_gpio *pg = data;
u8 intsts = *((u8 *)pg->gpiointr + 4);
int gpio;
irqreturn_t ret = IRQ_NONE;
for (gpio = 0; gpio < 8; gpio++) {
if (intsts & (1 << gpio)) {
pr_debug("pmic pin %d triggered\n", gpio);
generic_handle_irq(pg->irq_base + gpio);
ret = IRQ_HANDLED;
}
}
return ret;
}
static int platform_pmic_gpio_probe(struct platform_device *pdev)
{
struct device *dev = &pdev->dev;
int irq = platform_get_irq(pdev, 0);
struct intel_pmic_gpio_platform_data *pdata = dev->platform_data;
struct pmic_gpio *pg;
int retval;
int i;
if (irq < 0) {
dev_dbg(dev, "no IRQ line\n");
return -EINVAL;
}
if (!pdata || !pdata->gpio_base || !pdata->irq_base) {
dev_dbg(dev, "incorrect or missing platform data\n");
return -EINVAL;
}
pg = kzalloc(sizeof(*pg), GFP_KERNEL);
if (!pg)
return -ENOMEM;
dev_set_drvdata(dev, pg);
pg->irq = irq;
pg->gpiointr = ioremap_nocache(pdata->gpiointr, 8);
if (!pg->gpiointr) {
pr_err("Can not map GPIOINT\n");
retval = -EINVAL;
goto err2;
}
pg->irq_base = pdata->irq_base;
pg->chip.label = "intel_pmic";
pg->chip.direction_input = pmic_gpio_direction_input;
pg->chip.direction_output = pmic_gpio_direction_output;
pg->chip.get = pmic_gpio_get;
pg->chip.set = pmic_gpio_set;
pg->chip.to_irq = pmic_gpio_to_irq;
pg->chip.base = pdata->gpio_base;
pg->chip.ngpio = NUM_GPIO;
pg->chip.can_sleep = 1;
pg->chip.dev = dev;
mutex_init(&pg->buslock);
pg->chip.dev = dev;
retval = gpiochip_add(&pg->chip);
if (retval) {
pr_err("Can not add pmic gpio chip\n");
goto err;
}
retval = request_irq(pg->irq, pmic_irq_handler, 0, "pmic", pg);
if (retval) {
pr_warn("Interrupt request failed\n");
goto fail_request_irq;
}
for (i = 0; i < 8; i++) {
irq_set_chip_and_handler_name(i + pg->irq_base,
&pmic_irqchip,
handle_simple_irq,
"demux");
irq_set_chip_data(i + pg->irq_base, pg);
}
return 0;
fail_request_irq:
if (gpiochip_remove(&pg->chip))
pr_err("gpiochip_remove failed\n");
err:
iounmap(pg->gpiointr);
err2:
kfree(pg);
return retval;
}
static int __init platform_pmic_gpio_init(void)
{
return platform_driver_register(&platform_pmic_gpio_driver);
}
