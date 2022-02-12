static inline void zynq_gpio_get_bank_pin(unsigned int pin_num,
unsigned int *bank_num,
unsigned int *bank_pin_num,
struct zynq_gpio *gpio)
{
int bank;
for (bank = 0; bank < gpio->p_data->max_bank; bank++) {
if ((pin_num >= gpio->p_data->bank_min[bank]) &&
(pin_num <= gpio->p_data->bank_max[bank])) {
*bank_num = bank;
*bank_pin_num = pin_num -
gpio->p_data->bank_min[bank];
return;
}
}
WARN(true, "invalid GPIO pin number: %u", pin_num);
*bank_num = 0;
*bank_pin_num = 0;
}
static int zynq_gpio_get_value(struct gpio_chip *chip, unsigned int pin)
{
u32 data;
unsigned int bank_num, bank_pin_num;
struct zynq_gpio *gpio = container_of(chip, struct zynq_gpio, chip);
zynq_gpio_get_bank_pin(pin, &bank_num, &bank_pin_num, gpio);
data = readl_relaxed(gpio->base_addr +
ZYNQ_GPIO_DATA_RO_OFFSET(bank_num));
return (data >> bank_pin_num) & 1;
}
static void zynq_gpio_set_value(struct gpio_chip *chip, unsigned int pin,
int state)
{
unsigned int reg_offset, bank_num, bank_pin_num;
struct zynq_gpio *gpio = container_of(chip, struct zynq_gpio, chip);
zynq_gpio_get_bank_pin(pin, &bank_num, &bank_pin_num, gpio);
if (bank_pin_num >= ZYNQ_GPIO_MID_PIN_NUM) {
bank_pin_num -= ZYNQ_GPIO_MID_PIN_NUM;
reg_offset = ZYNQ_GPIO_DATA_MSW_OFFSET(bank_num);
} else {
reg_offset = ZYNQ_GPIO_DATA_LSW_OFFSET(bank_num);
}
state = !!state;
state = ~(1 << (bank_pin_num + ZYNQ_GPIO_MID_PIN_NUM)) &
((state << bank_pin_num) | ZYNQ_GPIO_UPPER_MASK);
writel_relaxed(state, gpio->base_addr + reg_offset);
}
static int zynq_gpio_dir_in(struct gpio_chip *chip, unsigned int pin)
{
u32 reg;
unsigned int bank_num, bank_pin_num;
struct zynq_gpio *gpio = container_of(chip, struct zynq_gpio, chip);
zynq_gpio_get_bank_pin(pin, &bank_num, &bank_pin_num, gpio);
if (bank_num == 0 && (bank_pin_num == 7 || bank_pin_num == 8))
return -EINVAL;
reg = readl_relaxed(gpio->base_addr + ZYNQ_GPIO_DIRM_OFFSET(bank_num));
reg &= ~BIT(bank_pin_num);
writel_relaxed(reg, gpio->base_addr + ZYNQ_GPIO_DIRM_OFFSET(bank_num));
return 0;
}
static int zynq_gpio_dir_out(struct gpio_chip *chip, unsigned int pin,
int state)
{
u32 reg;
unsigned int bank_num, bank_pin_num;
struct zynq_gpio *gpio = container_of(chip, struct zynq_gpio, chip);
zynq_gpio_get_bank_pin(pin, &bank_num, &bank_pin_num, gpio);
reg = readl_relaxed(gpio->base_addr + ZYNQ_GPIO_DIRM_OFFSET(bank_num));
reg |= BIT(bank_pin_num);
writel_relaxed(reg, gpio->base_addr + ZYNQ_GPIO_DIRM_OFFSET(bank_num));
reg = readl_relaxed(gpio->base_addr + ZYNQ_GPIO_OUTEN_OFFSET(bank_num));
reg |= BIT(bank_pin_num);
writel_relaxed(reg, gpio->base_addr + ZYNQ_GPIO_OUTEN_OFFSET(bank_num));
zynq_gpio_set_value(chip, pin, state);
return 0;
}
static void zynq_gpio_irq_mask(struct irq_data *irq_data)
{
unsigned int device_pin_num, bank_num, bank_pin_num;
struct zynq_gpio *gpio = irq_data_get_irq_chip_data(irq_data);
device_pin_num = irq_data->hwirq;
zynq_gpio_get_bank_pin(device_pin_num, &bank_num, &bank_pin_num, gpio);
writel_relaxed(BIT(bank_pin_num),
gpio->base_addr + ZYNQ_GPIO_INTDIS_OFFSET(bank_num));
}
static void zynq_gpio_irq_unmask(struct irq_data *irq_data)
{
unsigned int device_pin_num, bank_num, bank_pin_num;
struct zynq_gpio *gpio = irq_data_get_irq_chip_data(irq_data);
device_pin_num = irq_data->hwirq;
zynq_gpio_get_bank_pin(device_pin_num, &bank_num, &bank_pin_num, gpio);
writel_relaxed(BIT(bank_pin_num),
gpio->base_addr + ZYNQ_GPIO_INTEN_OFFSET(bank_num));
}
static void zynq_gpio_irq_ack(struct irq_data *irq_data)
{
unsigned int device_pin_num, bank_num, bank_pin_num;
struct zynq_gpio *gpio = irq_data_get_irq_chip_data(irq_data);
device_pin_num = irq_data->hwirq;
zynq_gpio_get_bank_pin(device_pin_num, &bank_num, &bank_pin_num, gpio);
writel_relaxed(BIT(bank_pin_num),
gpio->base_addr + ZYNQ_GPIO_INTSTS_OFFSET(bank_num));
}
static void zynq_gpio_irq_enable(struct irq_data *irq_data)
{
zynq_gpio_irq_ack(irq_data);
zynq_gpio_irq_unmask(irq_data);
}
static int zynq_gpio_set_irq_type(struct irq_data *irq_data, unsigned int type)
{
u32 int_type, int_pol, int_any;
unsigned int device_pin_num, bank_num, bank_pin_num;
struct zynq_gpio *gpio = irq_data_get_irq_chip_data(irq_data);
device_pin_num = irq_data->hwirq;
zynq_gpio_get_bank_pin(device_pin_num, &bank_num, &bank_pin_num, gpio);
int_type = readl_relaxed(gpio->base_addr +
ZYNQ_GPIO_INTTYPE_OFFSET(bank_num));
int_pol = readl_relaxed(gpio->base_addr +
ZYNQ_GPIO_INTPOL_OFFSET(bank_num));
int_any = readl_relaxed(gpio->base_addr +
ZYNQ_GPIO_INTANY_OFFSET(bank_num));
switch (type) {
case IRQ_TYPE_EDGE_RISING:
int_type |= BIT(bank_pin_num);
int_pol |= BIT(bank_pin_num);
int_any &= ~BIT(bank_pin_num);
break;
case IRQ_TYPE_EDGE_FALLING:
int_type |= BIT(bank_pin_num);
int_pol &= ~BIT(bank_pin_num);
int_any &= ~BIT(bank_pin_num);
break;
case IRQ_TYPE_EDGE_BOTH:
int_type |= BIT(bank_pin_num);
int_any |= BIT(bank_pin_num);
break;
case IRQ_TYPE_LEVEL_HIGH:
int_type &= ~BIT(bank_pin_num);
int_pol |= BIT(bank_pin_num);
break;
case IRQ_TYPE_LEVEL_LOW:
int_type &= ~BIT(bank_pin_num);
int_pol &= ~BIT(bank_pin_num);
break;
default:
return -EINVAL;
}
writel_relaxed(int_type,
gpio->base_addr + ZYNQ_GPIO_INTTYPE_OFFSET(bank_num));
writel_relaxed(int_pol,
gpio->base_addr + ZYNQ_GPIO_INTPOL_OFFSET(bank_num));
writel_relaxed(int_any,
gpio->base_addr + ZYNQ_GPIO_INTANY_OFFSET(bank_num));
if (type & IRQ_TYPE_LEVEL_MASK) {
__irq_set_chip_handler_name_locked(irq_data->irq,
&zynq_gpio_level_irqchip, handle_fasteoi_irq, NULL);
} else {
__irq_set_chip_handler_name_locked(irq_data->irq,
&zynq_gpio_edge_irqchip, handle_level_irq, NULL);
}
return 0;
}
static int zynq_gpio_set_wake(struct irq_data *data, unsigned int on)
{
struct zynq_gpio *gpio = irq_data_get_irq_chip_data(data);
irq_set_irq_wake(gpio->irq, on);
return 0;
}
static void zynq_gpio_handle_bank_irq(struct zynq_gpio *gpio,
unsigned int bank_num,
unsigned long pending)
{
unsigned int bank_offset = gpio->p_data->bank_min[bank_num];
struct irq_domain *irqdomain = gpio->chip.irqdomain;
int offset;
if (!pending)
return;
for_each_set_bit(offset, &pending, 32) {
unsigned int gpio_irq;
gpio_irq = irq_find_mapping(irqdomain, offset + bank_offset);
generic_handle_irq(gpio_irq);
}
}
static void zynq_gpio_irqhandler(unsigned int irq, struct irq_desc *desc)
{
u32 int_sts, int_enb;
unsigned int bank_num;
struct zynq_gpio *gpio = irq_get_handler_data(irq);
struct irq_chip *irqchip = irq_desc_get_chip(desc);
chained_irq_enter(irqchip, desc);
for (bank_num = 0; bank_num < gpio->p_data->max_bank; bank_num++) {
int_sts = readl_relaxed(gpio->base_addr +
ZYNQ_GPIO_INTSTS_OFFSET(bank_num));
int_enb = readl_relaxed(gpio->base_addr +
ZYNQ_GPIO_INTMASK_OFFSET(bank_num));
zynq_gpio_handle_bank_irq(gpio, bank_num, int_sts & ~int_enb);
}
chained_irq_exit(irqchip, desc);
}
static int __maybe_unused zynq_gpio_suspend(struct device *dev)
{
struct platform_device *pdev = to_platform_device(dev);
int irq = platform_get_irq(pdev, 0);
struct irq_data *data = irq_get_irq_data(irq);
if (!irqd_is_wakeup_set(data))
return pm_runtime_force_suspend(dev);
return 0;
}
static int __maybe_unused zynq_gpio_resume(struct device *dev)
{
struct platform_device *pdev = to_platform_device(dev);
int irq = platform_get_irq(pdev, 0);
struct irq_data *data = irq_get_irq_data(irq);
if (!irqd_is_wakeup_set(data))
return pm_runtime_force_resume(dev);
return 0;
}
static int __maybe_unused zynq_gpio_runtime_suspend(struct device *dev)
{
struct platform_device *pdev = to_platform_device(dev);
struct zynq_gpio *gpio = platform_get_drvdata(pdev);
clk_disable_unprepare(gpio->clk);
return 0;
}
static int __maybe_unused zynq_gpio_runtime_resume(struct device *dev)
{
struct platform_device *pdev = to_platform_device(dev);
struct zynq_gpio *gpio = platform_get_drvdata(pdev);
return clk_prepare_enable(gpio->clk);
}
static int zynq_gpio_request(struct gpio_chip *chip, unsigned offset)
{
int ret;
ret = pm_runtime_get_sync(chip->dev);
return ret < 0 ? ret : 0;
}
static void zynq_gpio_free(struct gpio_chip *chip, unsigned offset)
{
pm_runtime_put(chip->dev);
}
static int zynq_gpio_probe(struct platform_device *pdev)
{
int ret, bank_num;
struct zynq_gpio *gpio;
struct gpio_chip *chip;
struct resource *res;
const struct of_device_id *match;
gpio = devm_kzalloc(&pdev->dev, sizeof(*gpio), GFP_KERNEL);
if (!gpio)
return -ENOMEM;
match = of_match_node(zynq_gpio_of_match, pdev->dev.of_node);
if (!match) {
dev_err(&pdev->dev, "of_match_node() failed\n");
return -EINVAL;
}
gpio->p_data = match->data;
platform_set_drvdata(pdev, gpio);
res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
gpio->base_addr = devm_ioremap_resource(&pdev->dev, res);
if (IS_ERR(gpio->base_addr))
return PTR_ERR(gpio->base_addr);
gpio->irq = platform_get_irq(pdev, 0);
if (gpio->irq < 0) {
dev_err(&pdev->dev, "invalid IRQ\n");
return gpio->irq;
}
chip = &gpio->chip;
chip->label = gpio->p_data->label;
chip->owner = THIS_MODULE;
chip->dev = &pdev->dev;
chip->get = zynq_gpio_get_value;
chip->set = zynq_gpio_set_value;
chip->request = zynq_gpio_request;
chip->free = zynq_gpio_free;
chip->direction_input = zynq_gpio_dir_in;
chip->direction_output = zynq_gpio_dir_out;
chip->base = -1;
chip->ngpio = gpio->p_data->ngpio;
gpio->clk = devm_clk_get(&pdev->dev, NULL);
if (IS_ERR(gpio->clk)) {
dev_err(&pdev->dev, "input clock not found.\n");
return PTR_ERR(gpio->clk);
}
ret = clk_prepare_enable(gpio->clk);
if (ret) {
dev_err(&pdev->dev, "Unable to enable clock.\n");
return ret;
}
ret = gpiochip_add(chip);
if (ret) {
dev_err(&pdev->dev, "Failed to add gpio chip\n");
goto err_disable_clk;
}
for (bank_num = 0; bank_num < gpio->p_data->max_bank; bank_num++)
writel_relaxed(ZYNQ_GPIO_IXR_DISABLE_ALL, gpio->base_addr +
ZYNQ_GPIO_INTDIS_OFFSET(bank_num));
ret = gpiochip_irqchip_add(chip, &zynq_gpio_edge_irqchip, 0,
handle_level_irq, IRQ_TYPE_NONE);
if (ret) {
dev_err(&pdev->dev, "Failed to add irq chip\n");
goto err_rm_gpiochip;
}
gpiochip_set_chained_irqchip(chip, &zynq_gpio_edge_irqchip, gpio->irq,
zynq_gpio_irqhandler);
pm_runtime_set_active(&pdev->dev);
pm_runtime_enable(&pdev->dev);
return 0;
err_rm_gpiochip:
gpiochip_remove(chip);
err_disable_clk:
clk_disable_unprepare(gpio->clk);
return ret;
}
static int zynq_gpio_remove(struct platform_device *pdev)
{
struct zynq_gpio *gpio = platform_get_drvdata(pdev);
pm_runtime_get_sync(&pdev->dev);
gpiochip_remove(&gpio->chip);
clk_disable_unprepare(gpio->clk);
device_set_wakeup_capable(&pdev->dev, 0);
pm_runtime_disable(&pdev->dev);
return 0;
}
static int __init zynq_gpio_init(void)
{
return platform_driver_register(&zynq_gpio_driver);
}
