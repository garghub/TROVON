static inline struct cygnus_gpio *to_cygnus_gpio(struct gpio_chip *gc)
{
return container_of(gc, struct cygnus_gpio, gc);
}
static inline unsigned cygnus_pin_to_gpio(unsigned pin)
{
return pin;
}
static inline void cygnus_set_bit(struct cygnus_gpio *chip, unsigned int reg,
unsigned gpio, bool set)
{
unsigned int offset = CYGNUS_GPIO_REG(gpio, reg);
unsigned int shift = CYGNUS_GPIO_SHIFT(gpio);
u32 val;
val = readl(chip->base + offset);
if (set)
val |= BIT(shift);
else
val &= ~BIT(shift);
writel(val, chip->base + offset);
}
static inline bool cygnus_get_bit(struct cygnus_gpio *chip, unsigned int reg,
unsigned gpio)
{
unsigned int offset = CYGNUS_GPIO_REG(gpio, reg);
unsigned int shift = CYGNUS_GPIO_SHIFT(gpio);
return !!(readl(chip->base + offset) & BIT(shift));
}
static void cygnus_gpio_irq_handler(struct irq_desc *desc)
{
struct gpio_chip *gc = irq_desc_get_handler_data(desc);
struct cygnus_gpio *chip = to_cygnus_gpio(gc);
struct irq_chip *irq_chip = irq_desc_get_chip(desc);
int i, bit;
chained_irq_enter(irq_chip, desc);
for (i = 0; i < chip->num_banks; i++) {
unsigned long val = readl(chip->base + (i * GPIO_BANK_SIZE) +
CYGNUS_GPIO_INT_MSTAT_OFFSET);
for_each_set_bit(bit, &val, NGPIOS_PER_BANK) {
unsigned pin = NGPIOS_PER_BANK * i + bit;
int child_irq = irq_find_mapping(gc->irqdomain, pin);
writel(BIT(bit), chip->base + (i * GPIO_BANK_SIZE) +
CYGNUS_GPIO_INT_CLR_OFFSET);
generic_handle_irq(child_irq);
}
}
chained_irq_exit(irq_chip, desc);
}
static void cygnus_gpio_irq_ack(struct irq_data *d)
{
struct gpio_chip *gc = irq_data_get_irq_chip_data(d);
struct cygnus_gpio *chip = to_cygnus_gpio(gc);
unsigned gpio = d->hwirq;
unsigned int offset = CYGNUS_GPIO_REG(gpio,
CYGNUS_GPIO_INT_CLR_OFFSET);
unsigned int shift = CYGNUS_GPIO_SHIFT(gpio);
u32 val = BIT(shift);
writel(val, chip->base + offset);
}
static void cygnus_gpio_irq_set_mask(struct irq_data *d, bool unmask)
{
struct gpio_chip *gc = irq_data_get_irq_chip_data(d);
struct cygnus_gpio *chip = to_cygnus_gpio(gc);
unsigned gpio = d->hwirq;
cygnus_set_bit(chip, CYGNUS_GPIO_INT_MSK_OFFSET, gpio, unmask);
}
static void cygnus_gpio_irq_mask(struct irq_data *d)
{
struct gpio_chip *gc = irq_data_get_irq_chip_data(d);
struct cygnus_gpio *chip = to_cygnus_gpio(gc);
unsigned long flags;
spin_lock_irqsave(&chip->lock, flags);
cygnus_gpio_irq_set_mask(d, false);
spin_unlock_irqrestore(&chip->lock, flags);
}
static void cygnus_gpio_irq_unmask(struct irq_data *d)
{
struct gpio_chip *gc = irq_data_get_irq_chip_data(d);
struct cygnus_gpio *chip = to_cygnus_gpio(gc);
unsigned long flags;
spin_lock_irqsave(&chip->lock, flags);
cygnus_gpio_irq_set_mask(d, true);
spin_unlock_irqrestore(&chip->lock, flags);
}
static int cygnus_gpio_irq_set_type(struct irq_data *d, unsigned int type)
{
struct gpio_chip *gc = irq_data_get_irq_chip_data(d);
struct cygnus_gpio *chip = to_cygnus_gpio(gc);
unsigned gpio = d->hwirq;
bool level_triggered = false;
bool dual_edge = false;
bool rising_or_high = false;
unsigned long flags;
switch (type & IRQ_TYPE_SENSE_MASK) {
case IRQ_TYPE_EDGE_RISING:
rising_or_high = true;
break;
case IRQ_TYPE_EDGE_FALLING:
break;
case IRQ_TYPE_EDGE_BOTH:
dual_edge = true;
break;
case IRQ_TYPE_LEVEL_HIGH:
level_triggered = true;
rising_or_high = true;
break;
case IRQ_TYPE_LEVEL_LOW:
level_triggered = true;
break;
default:
dev_err(chip->dev, "invalid GPIO IRQ type 0x%x\n",
type);
return -EINVAL;
}
spin_lock_irqsave(&chip->lock, flags);
cygnus_set_bit(chip, CYGNUS_GPIO_INT_TYPE_OFFSET, gpio,
level_triggered);
cygnus_set_bit(chip, CYGNUS_GPIO_INT_DE_OFFSET, gpio, dual_edge);
cygnus_set_bit(chip, CYGNUS_GPIO_INT_EDGE_OFFSET, gpio,
rising_or_high);
spin_unlock_irqrestore(&chip->lock, flags);
dev_dbg(chip->dev,
"gpio:%u level_triggered:%d dual_edge:%d rising_or_high:%d\n",
gpio, level_triggered, dual_edge, rising_or_high);
return 0;
}
static int cygnus_gpio_request(struct gpio_chip *gc, unsigned offset)
{
struct cygnus_gpio *chip = to_cygnus_gpio(gc);
unsigned gpio = gc->base + offset;
if (!chip->pinmux_is_supported)
return 0;
return pinctrl_request_gpio(gpio);
}
static void cygnus_gpio_free(struct gpio_chip *gc, unsigned offset)
{
struct cygnus_gpio *chip = to_cygnus_gpio(gc);
unsigned gpio = gc->base + offset;
if (!chip->pinmux_is_supported)
return;
pinctrl_free_gpio(gpio);
}
static int cygnus_gpio_direction_input(struct gpio_chip *gc, unsigned gpio)
{
struct cygnus_gpio *chip = to_cygnus_gpio(gc);
unsigned long flags;
spin_lock_irqsave(&chip->lock, flags);
cygnus_set_bit(chip, CYGNUS_GPIO_OUT_EN_OFFSET, gpio, false);
spin_unlock_irqrestore(&chip->lock, flags);
dev_dbg(chip->dev, "gpio:%u set input\n", gpio);
return 0;
}
static int cygnus_gpio_direction_output(struct gpio_chip *gc, unsigned gpio,
int val)
{
struct cygnus_gpio *chip = to_cygnus_gpio(gc);
unsigned long flags;
spin_lock_irqsave(&chip->lock, flags);
cygnus_set_bit(chip, CYGNUS_GPIO_OUT_EN_OFFSET, gpio, true);
cygnus_set_bit(chip, CYGNUS_GPIO_DATA_OUT_OFFSET, gpio, !!(val));
spin_unlock_irqrestore(&chip->lock, flags);
dev_dbg(chip->dev, "gpio:%u set output, value:%d\n", gpio, val);
return 0;
}
static void cygnus_gpio_set(struct gpio_chip *gc, unsigned gpio, int val)
{
struct cygnus_gpio *chip = to_cygnus_gpio(gc);
unsigned long flags;
spin_lock_irqsave(&chip->lock, flags);
cygnus_set_bit(chip, CYGNUS_GPIO_DATA_OUT_OFFSET, gpio, !!(val));
spin_unlock_irqrestore(&chip->lock, flags);
dev_dbg(chip->dev, "gpio:%u set, value:%d\n", gpio, val);
}
static int cygnus_gpio_get(struct gpio_chip *gc, unsigned gpio)
{
struct cygnus_gpio *chip = to_cygnus_gpio(gc);
unsigned int offset = CYGNUS_GPIO_REG(gpio,
CYGNUS_GPIO_DATA_IN_OFFSET);
unsigned int shift = CYGNUS_GPIO_SHIFT(gpio);
return !!(readl(chip->base + offset) & BIT(shift));
}
static int cygnus_get_groups_count(struct pinctrl_dev *pctldev)
{
return 1;
}
static const char *cygnus_get_group_name(struct pinctrl_dev *pctldev,
unsigned selector)
{
return "gpio_grp";
}
static int cygnus_gpio_set_pull(struct cygnus_gpio *chip, unsigned gpio,
bool disable, bool pull_up)
{
unsigned long flags;
spin_lock_irqsave(&chip->lock, flags);
if (disable) {
cygnus_set_bit(chip, CYGNUS_GPIO_RES_EN_OFFSET, gpio, false);
} else {
cygnus_set_bit(chip, CYGNUS_GPIO_PAD_RES_OFFSET, gpio,
pull_up);
cygnus_set_bit(chip, CYGNUS_GPIO_RES_EN_OFFSET, gpio, true);
}
spin_unlock_irqrestore(&chip->lock, flags);
dev_dbg(chip->dev, "gpio:%u set pullup:%d\n", gpio, pull_up);
return 0;
}
static void cygnus_gpio_get_pull(struct cygnus_gpio *chip, unsigned gpio,
bool *disable, bool *pull_up)
{
unsigned long flags;
spin_lock_irqsave(&chip->lock, flags);
*disable = !cygnus_get_bit(chip, CYGNUS_GPIO_RES_EN_OFFSET, gpio);
*pull_up = cygnus_get_bit(chip, CYGNUS_GPIO_PAD_RES_OFFSET, gpio);
spin_unlock_irqrestore(&chip->lock, flags);
}
static int cygnus_gpio_set_strength(struct cygnus_gpio *chip, unsigned gpio,
unsigned strength)
{
void __iomem *base;
unsigned int i, offset, shift;
u32 val;
unsigned long flags;
if (strength < 2 || strength > 16 || (strength % 2))
return -ENOTSUPP;
if (chip->io_ctrl) {
base = chip->io_ctrl;
offset = CYGNUS_GPIO_DRV0_CTRL_OFFSET;
} else {
base = chip->base;
offset = CYGNUS_GPIO_REG(gpio,
CYGNUS_GPIO_ASIU_DRV0_CTRL_OFFSET);
}
shift = CYGNUS_GPIO_SHIFT(gpio);
dev_dbg(chip->dev, "gpio:%u set drive strength:%d mA\n", gpio,
strength);
spin_lock_irqsave(&chip->lock, flags);
strength = (strength / 2) - 1;
for (i = 0; i < GPIO_DRV_STRENGTH_BITS; i++) {
val = readl(base + offset);
val &= ~BIT(shift);
val |= ((strength >> i) & 0x1) << shift;
writel(val, base + offset);
offset += 4;
}
spin_unlock_irqrestore(&chip->lock, flags);
return 0;
}
static int cygnus_gpio_get_strength(struct cygnus_gpio *chip, unsigned gpio,
u16 *strength)
{
void __iomem *base;
unsigned int i, offset, shift;
u32 val;
unsigned long flags;
if (chip->io_ctrl) {
base = chip->io_ctrl;
offset = CYGNUS_GPIO_DRV0_CTRL_OFFSET;
} else {
base = chip->base;
offset = CYGNUS_GPIO_REG(gpio,
CYGNUS_GPIO_ASIU_DRV0_CTRL_OFFSET);
}
shift = CYGNUS_GPIO_SHIFT(gpio);
spin_lock_irqsave(&chip->lock, flags);
*strength = 0;
for (i = 0; i < GPIO_DRV_STRENGTH_BITS; i++) {
val = readl(base + offset) & BIT(shift);
val >>= shift;
*strength += (val << i);
offset += 4;
}
*strength = (*strength + 1) * 2;
spin_unlock_irqrestore(&chip->lock, flags);
return 0;
}
static int cygnus_pin_config_get(struct pinctrl_dev *pctldev, unsigned pin,
unsigned long *config)
{
struct cygnus_gpio *chip = pinctrl_dev_get_drvdata(pctldev);
enum pin_config_param param = pinconf_to_config_param(*config);
unsigned gpio = cygnus_pin_to_gpio(pin);
u16 arg;
bool disable, pull_up;
int ret;
switch (param) {
case PIN_CONFIG_BIAS_DISABLE:
cygnus_gpio_get_pull(chip, gpio, &disable, &pull_up);
if (disable)
return 0;
else
return -EINVAL;
case PIN_CONFIG_BIAS_PULL_UP:
cygnus_gpio_get_pull(chip, gpio, &disable, &pull_up);
if (!disable && pull_up)
return 0;
else
return -EINVAL;
case PIN_CONFIG_BIAS_PULL_DOWN:
cygnus_gpio_get_pull(chip, gpio, &disable, &pull_up);
if (!disable && !pull_up)
return 0;
else
return -EINVAL;
case PIN_CONFIG_DRIVE_STRENGTH:
ret = cygnus_gpio_get_strength(chip, gpio, &arg);
if (ret)
return ret;
else
*config = pinconf_to_config_packed(param, arg);
return 0;
default:
return -ENOTSUPP;
}
return -ENOTSUPP;
}
static int cygnus_pin_config_set(struct pinctrl_dev *pctldev, unsigned pin,
unsigned long *configs, unsigned num_configs)
{
struct cygnus_gpio *chip = pinctrl_dev_get_drvdata(pctldev);
enum pin_config_param param;
u16 arg;
unsigned i, gpio = cygnus_pin_to_gpio(pin);
int ret = -ENOTSUPP;
for (i = 0; i < num_configs; i++) {
param = pinconf_to_config_param(configs[i]);
arg = pinconf_to_config_argument(configs[i]);
switch (param) {
case PIN_CONFIG_BIAS_DISABLE:
ret = cygnus_gpio_set_pull(chip, gpio, true, false);
if (ret < 0)
goto out;
break;
case PIN_CONFIG_BIAS_PULL_UP:
ret = cygnus_gpio_set_pull(chip, gpio, false, true);
if (ret < 0)
goto out;
break;
case PIN_CONFIG_BIAS_PULL_DOWN:
ret = cygnus_gpio_set_pull(chip, gpio, false, false);
if (ret < 0)
goto out;
break;
case PIN_CONFIG_DRIVE_STRENGTH:
ret = cygnus_gpio_set_strength(chip, gpio, arg);
if (ret < 0)
goto out;
break;
default:
dev_err(chip->dev, "invalid configuration\n");
return -ENOTSUPP;
}
}
out:
return ret;
}
static int cygnus_gpio_pinmux_add_range(struct cygnus_gpio *chip)
{
struct device_node *node = chip->dev->of_node;
struct device_node *pinmux_node;
struct platform_device *pinmux_pdev;
struct gpio_chip *gc = &chip->gc;
int i, ret = 0;
pinmux_node = of_parse_phandle(node, "pinmux", 0);
if (!pinmux_node)
return -ENODEV;
pinmux_pdev = of_find_device_by_node(pinmux_node);
of_node_put(pinmux_node);
if (!pinmux_pdev) {
dev_err(chip->dev, "failed to get pinmux device\n");
return -EINVAL;
}
for (i = 0; i < ARRAY_SIZE(cygnus_gpio_pintable); i++) {
ret = gpiochip_add_pin_range(gc, dev_name(&pinmux_pdev->dev),
cygnus_gpio_pintable[i].offset,
cygnus_gpio_pintable[i].pin_base,
cygnus_gpio_pintable[i].num_pins);
if (ret) {
dev_err(chip->dev, "unable to add GPIO pin range\n");
goto err_put_device;
}
}
chip->pinmux_is_supported = true;
put_device(&pinmux_pdev->dev);
return 0;
err_put_device:
put_device(&pinmux_pdev->dev);
gpiochip_remove_pin_ranges(gc);
return ret;
}
static int cygnus_gpio_register_pinconf(struct cygnus_gpio *chip)
{
struct pinctrl_desc *pctldesc = &chip->pctldesc;
struct pinctrl_pin_desc *pins;
struct gpio_chip *gc = &chip->gc;
int i;
pins = devm_kcalloc(chip->dev, gc->ngpio, sizeof(*pins), GFP_KERNEL);
if (!pins)
return -ENOMEM;
for (i = 0; i < gc->ngpio; i++) {
pins[i].number = i;
pins[i].name = devm_kasprintf(chip->dev, GFP_KERNEL,
"gpio-%d", i);
if (!pins[i].name)
return -ENOMEM;
}
pctldesc->name = dev_name(chip->dev);
pctldesc->pctlops = &cygnus_pctrl_ops;
pctldesc->pins = pins;
pctldesc->npins = gc->ngpio;
pctldesc->confops = &cygnus_pconf_ops;
chip->pctl = pinctrl_register(pctldesc, chip->dev, chip);
if (IS_ERR(chip->pctl)) {
dev_err(chip->dev, "unable to register pinctrl device\n");
return PTR_ERR(chip->pctl);
}
return 0;
}
static void cygnus_gpio_unregister_pinconf(struct cygnus_gpio *chip)
{
if (chip->pctl)
pinctrl_unregister(chip->pctl);
}
static int cygnus_gpio_probe(struct platform_device *pdev)
{
struct device *dev = &pdev->dev;
struct resource *res;
struct cygnus_gpio *chip;
struct gpio_chip *gc;
u32 ngpios;
int irq, ret;
const struct of_device_id *match;
const struct cygnus_gpio_data *gpio_data;
match = of_match_device(cygnus_gpio_of_match, dev);
if (!match)
return -ENODEV;
gpio_data = match->data;
ngpios = gpio_data->num_gpios;
chip = devm_kzalloc(dev, sizeof(*chip), GFP_KERNEL);
if (!chip)
return -ENOMEM;
chip->dev = dev;
platform_set_drvdata(pdev, chip);
res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
chip->base = devm_ioremap_resource(dev, res);
if (IS_ERR(chip->base)) {
dev_err(dev, "unable to map I/O memory\n");
return PTR_ERR(chip->base);
}
res = platform_get_resource(pdev, IORESOURCE_MEM, 1);
if (res) {
chip->io_ctrl = devm_ioremap_resource(dev, res);
if (IS_ERR(chip->io_ctrl)) {
dev_err(dev, "unable to map I/O memory\n");
return PTR_ERR(chip->io_ctrl);
}
}
spin_lock_init(&chip->lock);
gc = &chip->gc;
gc->base = -1;
gc->ngpio = ngpios;
chip->num_banks = (ngpios + NGPIOS_PER_BANK - 1) / NGPIOS_PER_BANK;
gc->label = dev_name(dev);
gc->dev = dev;
gc->of_node = dev->of_node;
gc->request = cygnus_gpio_request;
gc->free = cygnus_gpio_free;
gc->direction_input = cygnus_gpio_direction_input;
gc->direction_output = cygnus_gpio_direction_output;
gc->set = cygnus_gpio_set;
gc->get = cygnus_gpio_get;
ret = gpiochip_add(gc);
if (ret < 0) {
dev_err(dev, "unable to add GPIO chip\n");
return ret;
}
ret = cygnus_gpio_pinmux_add_range(chip);
if (ret && ret != -ENODEV) {
dev_err(dev, "unable to add GPIO pin range\n");
goto err_rm_gpiochip;
}
ret = cygnus_gpio_register_pinconf(chip);
if (ret) {
dev_err(dev, "unable to register pinconf\n");
goto err_rm_gpiochip;
}
irq = platform_get_irq(pdev, 0);
if (irq) {
ret = gpiochip_irqchip_add(gc, &cygnus_gpio_irq_chip, 0,
handle_simple_irq, IRQ_TYPE_NONE);
if (ret) {
dev_err(dev, "no GPIO irqchip\n");
goto err_unregister_pinconf;
}
gpiochip_set_chained_irqchip(gc, &cygnus_gpio_irq_chip, irq,
cygnus_gpio_irq_handler);
}
return 0;
err_unregister_pinconf:
cygnus_gpio_unregister_pinconf(chip);
err_rm_gpiochip:
gpiochip_remove(gc);
return ret;
}
static int __init cygnus_gpio_init(void)
{
return platform_driver_probe(&cygnus_gpio_driver, cygnus_gpio_probe);
}
