static inline unsigned int to_reg(int gpio, enum ctrl_register reg_type)
{
unsigned int reg;
int bank;
if (gpio < BANK0_NR_PINS)
bank = 0;
else if (gpio < BANK0_NR_PINS + BANK1_NR_PINS)
bank = 1;
else
bank = 2;
if (reg_type == CTRL_IN)
reg = GPIO_IN_CTRL_BASE + bank;
else
reg = GPIO_OUT_CTRL_BASE + bank;
return reg;
}
static void wcove_update_irq_mask(struct wcove_gpio *wg, int gpio)
{
unsigned int reg, mask;
if (gpio < GROUP0_NR_IRQS) {
reg = IRQ_MASK_BASE;
mask = BIT(gpio % GROUP0_NR_IRQS);
} else {
reg = IRQ_MASK_BASE + 1;
mask = BIT((gpio - GROUP0_NR_IRQS) % GROUP1_NR_IRQS);
}
if (wg->set_irq_mask)
regmap_update_bits(wg->regmap, reg, mask, mask);
else
regmap_update_bits(wg->regmap, reg, mask, 0);
}
static void wcove_update_irq_ctrl(struct wcove_gpio *wg, int gpio)
{
unsigned int reg = to_reg(gpio, CTRL_IN);
regmap_update_bits(wg->regmap, reg, CTLI_INTCNT_BE, wg->intcnt);
}
static int wcove_gpio_dir_in(struct gpio_chip *chip, unsigned int gpio)
{
struct wcove_gpio *wg = gpiochip_get_data(chip);
return regmap_write(wg->regmap, to_reg(gpio, CTRL_OUT),
CTLO_INPUT_SET);
}
static int wcove_gpio_dir_out(struct gpio_chip *chip, unsigned int gpio,
int value)
{
struct wcove_gpio *wg = gpiochip_get_data(chip);
return regmap_write(wg->regmap, to_reg(gpio, CTRL_OUT),
CTLO_OUTPUT_SET | value);
}
static int wcove_gpio_get_direction(struct gpio_chip *chip, unsigned int gpio)
{
struct wcove_gpio *wg = gpiochip_get_data(chip);
unsigned int val;
int ret;
ret = regmap_read(wg->regmap, to_reg(gpio, CTRL_OUT), &val);
if (ret)
return ret;
return !(val & CTLO_DIR_OUT);
}
static int wcove_gpio_get(struct gpio_chip *chip, unsigned int gpio)
{
struct wcove_gpio *wg = gpiochip_get_data(chip);
unsigned int val;
int ret;
ret = regmap_read(wg->regmap, to_reg(gpio, CTRL_IN), &val);
if (ret)
return ret;
return val & 0x1;
}
static void wcove_gpio_set(struct gpio_chip *chip,
unsigned int gpio, int value)
{
struct wcove_gpio *wg = gpiochip_get_data(chip);
if (value)
regmap_update_bits(wg->regmap, to_reg(gpio, CTRL_OUT), 1, 1);
else
regmap_update_bits(wg->regmap, to_reg(gpio, CTRL_OUT), 1, 0);
}
static int wcove_gpio_set_single_ended(struct gpio_chip *chip,
unsigned int gpio,
enum single_ended_mode mode)
{
struct wcove_gpio *wg = gpiochip_get_data(chip);
switch (mode) {
case LINE_MODE_OPEN_DRAIN:
return regmap_update_bits(wg->regmap, to_reg(gpio, CTRL_OUT),
CTLO_DRV_MASK, CTLO_DRV_OD);
case LINE_MODE_PUSH_PULL:
return regmap_update_bits(wg->regmap, to_reg(gpio, CTRL_OUT),
CTLO_DRV_MASK, CTLO_DRV_CMOS);
default:
break;
}
return -ENOTSUPP;
}
static int wcove_irq_type(struct irq_data *data, unsigned int type)
{
struct gpio_chip *chip = irq_data_get_irq_chip_data(data);
struct wcove_gpio *wg = gpiochip_get_data(chip);
switch (type) {
case IRQ_TYPE_NONE:
wg->intcnt = CTLI_INTCNT_DIS;
break;
case IRQ_TYPE_EDGE_BOTH:
wg->intcnt = CTLI_INTCNT_BE;
break;
case IRQ_TYPE_EDGE_RISING:
wg->intcnt = CTLI_INTCNT_PE;
break;
case IRQ_TYPE_EDGE_FALLING:
wg->intcnt = CTLI_INTCNT_NE;
break;
default:
return -EINVAL;
}
wg->update |= UPDATE_IRQ_TYPE;
return 0;
}
static void wcove_bus_lock(struct irq_data *data)
{
struct gpio_chip *chip = irq_data_get_irq_chip_data(data);
struct wcove_gpio *wg = gpiochip_get_data(chip);
mutex_lock(&wg->buslock);
}
static void wcove_bus_sync_unlock(struct irq_data *data)
{
struct gpio_chip *chip = irq_data_get_irq_chip_data(data);
struct wcove_gpio *wg = gpiochip_get_data(chip);
int gpio = data->hwirq;
if (wg->update & UPDATE_IRQ_TYPE)
wcove_update_irq_ctrl(wg, gpio);
if (wg->update & UPDATE_IRQ_MASK)
wcove_update_irq_mask(wg, gpio);
wg->update = 0;
mutex_unlock(&wg->buslock);
}
static void wcove_irq_unmask(struct irq_data *data)
{
struct gpio_chip *chip = irq_data_get_irq_chip_data(data);
struct wcove_gpio *wg = gpiochip_get_data(chip);
wg->set_irq_mask = false;
wg->update |= UPDATE_IRQ_MASK;
}
static void wcove_irq_mask(struct irq_data *data)
{
struct gpio_chip *chip = irq_data_get_irq_chip_data(data);
struct wcove_gpio *wg = gpiochip_get_data(chip);
wg->set_irq_mask = true;
wg->update |= UPDATE_IRQ_MASK;
}
static irqreturn_t wcove_gpio_irq_handler(int irq, void *data)
{
struct wcove_gpio *wg = (struct wcove_gpio *)data;
unsigned int pending, virq, gpio, mask, offset;
u8 p[2];
if (regmap_bulk_read(wg->regmap, IRQ_STATUS_BASE, p, 2)) {
dev_err(wg->dev, "Failed to read irq status register\n");
return IRQ_NONE;
}
pending = p[0] | (p[1] << 8);
if (!pending)
return IRQ_NONE;
while (pending) {
for_each_set_bit(gpio, (const unsigned long *)&pending,
GROUP0_NR_IRQS) {
offset = (gpio > GROUP0_NR_IRQS) ? 1 : 0;
mask = (offset == 1) ? BIT(gpio - GROUP0_NR_IRQS) :
BIT(gpio);
virq = irq_find_mapping(wg->chip.irqdomain, gpio);
handle_nested_irq(virq);
regmap_update_bits(wg->regmap, IRQ_STATUS_BASE + offset,
mask, mask);
}
if (regmap_bulk_read(wg->regmap, IRQ_STATUS_BASE, p, 2)) {
dev_err(wg->dev, "Failed to read irq status\n");
break;
}
pending = p[0] | (p[1] << 8);
}
return IRQ_HANDLED;
}
static void wcove_gpio_dbg_show(struct seq_file *s,
struct gpio_chip *chip)
{
unsigned int ctlo, ctli, irq_mask, irq_status;
struct wcove_gpio *wg = gpiochip_get_data(chip);
int gpio, offset, group, ret = 0;
for (gpio = 0; gpio < WCOVE_GPIO_NUM; gpio++) {
group = gpio < GROUP0_NR_IRQS ? 0 : 1;
ret += regmap_read(wg->regmap, to_reg(gpio, CTRL_OUT), &ctlo);
ret += regmap_read(wg->regmap, to_reg(gpio, CTRL_IN), &ctli);
ret += regmap_read(wg->regmap, IRQ_MASK_BASE + group,
&irq_mask);
ret += regmap_read(wg->regmap, IRQ_STATUS_BASE + group,
&irq_status);
if (ret) {
pr_err("Failed to read registers: ctrl out/in or irq status/mask\n");
break;
}
offset = gpio % 8;
seq_printf(s, " gpio-%-2d %s %s %s %s ctlo=%2x,%s %s\n",
gpio, ctlo & CTLO_DIR_OUT ? "out" : "in ",
ctli & 0x1 ? "hi" : "lo",
ctli & CTLI_INTCNT_NE ? "fall" : " ",
ctli & CTLI_INTCNT_PE ? "rise" : " ",
ctlo,
irq_mask & BIT(offset) ? "mask " : "unmask",
irq_status & BIT(offset) ? "pending" : " ");
}
}
static int wcove_gpio_probe(struct platform_device *pdev)
{
struct intel_soc_pmic *pmic;
struct wcove_gpio *wg;
int virq, ret, irq;
struct device *dev;
pmic = dev_get_drvdata(pdev->dev.parent);
if (!pmic)
return -ENODEV;
irq = platform_get_irq(pdev, 0);
if (irq < 0)
return irq;
dev = &pdev->dev;
wg = devm_kzalloc(dev, sizeof(*wg), GFP_KERNEL);
if (!wg)
return -ENOMEM;
wg->regmap_irq_chip = pmic->irq_chip_data_level2;
platform_set_drvdata(pdev, wg);
mutex_init(&wg->buslock);
wg->chip.label = KBUILD_MODNAME;
wg->chip.direction_input = wcove_gpio_dir_in;
wg->chip.direction_output = wcove_gpio_dir_out;
wg->chip.get_direction = wcove_gpio_get_direction;
wg->chip.get = wcove_gpio_get;
wg->chip.set = wcove_gpio_set;
wg->chip.set_single_ended = wcove_gpio_set_single_ended,
wg->chip.base = -1;
wg->chip.ngpio = WCOVE_VGPIO_NUM;
wg->chip.can_sleep = true;
wg->chip.parent = pdev->dev.parent;
wg->chip.dbg_show = wcove_gpio_dbg_show;
wg->dev = dev;
wg->regmap = pmic->regmap;
ret = devm_gpiochip_add_data(dev, &wg->chip, wg);
if (ret) {
dev_err(dev, "Failed to add gpiochip: %d\n", ret);
return ret;
}
ret = gpiochip_irqchip_add(&wg->chip, &wcove_irqchip, 0,
handle_simple_irq, IRQ_TYPE_NONE);
if (ret) {
dev_err(dev, "Failed to add irqchip: %d\n", ret);
return ret;
}
virq = regmap_irq_get_virq(wg->regmap_irq_chip, irq);
if (virq < 0) {
dev_err(dev, "Failed to get virq by irq %d\n", irq);
return virq;
}
ret = devm_request_threaded_irq(dev, virq, NULL,
wcove_gpio_irq_handler, IRQF_ONESHOT, pdev->name, wg);
if (ret) {
dev_err(dev, "Failed to request irq %d\n", virq);
return ret;
}
return 0;
}
