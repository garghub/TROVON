static inline u32 pctl_readl(struct pistachio_pinctrl *pctl, u32 reg)
{
return readl(pctl->base + reg);
}
static inline void pctl_writel(struct pistachio_pinctrl *pctl, u32 val, u32 reg)
{
writel(val, pctl->base + reg);
}
static inline struct pistachio_gpio_bank *gc_to_bank(struct gpio_chip *gc)
{
return container_of(gc, struct pistachio_gpio_bank, gpio_chip);
}
static inline struct pistachio_gpio_bank *irqd_to_bank(struct irq_data *d)
{
return gc_to_bank(irq_data_get_irq_chip_data(d));
}
static inline u32 gpio_readl(struct pistachio_gpio_bank *bank, u32 reg)
{
return readl(bank->base + reg);
}
static inline void gpio_writel(struct pistachio_gpio_bank *bank, u32 val,
u32 reg)
{
writel(val, bank->base + reg);
}
static inline void gpio_mask_writel(struct pistachio_gpio_bank *bank,
u32 reg, unsigned int bit, u32 val)
{
gpio_writel(bank, (0x10000 | val) << bit, reg);
}
static inline void gpio_enable(struct pistachio_gpio_bank *bank,
unsigned offset)
{
gpio_mask_writel(bank, GPIO_BIT_EN, offset, 1);
}
static inline void gpio_disable(struct pistachio_gpio_bank *bank,
unsigned offset)
{
gpio_mask_writel(bank, GPIO_BIT_EN, offset, 0);
}
static int pistachio_pinctrl_get_groups_count(struct pinctrl_dev *pctldev)
{
struct pistachio_pinctrl *pctl = pinctrl_dev_get_drvdata(pctldev);
return pctl->ngroups;
}
static const char *pistachio_pinctrl_get_group_name(struct pinctrl_dev *pctldev,
unsigned group)
{
struct pistachio_pinctrl *pctl = pinctrl_dev_get_drvdata(pctldev);
return pctl->groups[group].name;
}
static int pistachio_pinctrl_get_group_pins(struct pinctrl_dev *pctldev,
unsigned group,
const unsigned **pins,
unsigned *num_pins)
{
struct pistachio_pinctrl *pctl = pinctrl_dev_get_drvdata(pctldev);
*pins = &pctl->groups[group].pin;
*num_pins = 1;
return 0;
}
static int pistachio_pinmux_get_functions_count(struct pinctrl_dev *pctldev)
{
struct pistachio_pinctrl *pctl = pinctrl_dev_get_drvdata(pctldev);
return pctl->nfunctions;
}
static const char *
pistachio_pinmux_get_function_name(struct pinctrl_dev *pctldev, unsigned func)
{
struct pistachio_pinctrl *pctl = pinctrl_dev_get_drvdata(pctldev);
return pctl->functions[func].name;
}
static int pistachio_pinmux_get_function_groups(struct pinctrl_dev *pctldev,
unsigned func,
const char * const **groups,
unsigned * const num_groups)
{
struct pistachio_pinctrl *pctl = pinctrl_dev_get_drvdata(pctldev);
*groups = pctl->functions[func].groups;
*num_groups = pctl->functions[func].ngroups;
return 0;
}
static int pistachio_pinmux_enable(struct pinctrl_dev *pctldev,
unsigned func, unsigned group)
{
struct pistachio_pinctrl *pctl = pinctrl_dev_get_drvdata(pctldev);
const struct pistachio_pin_group *pg = &pctl->groups[group];
const struct pistachio_function *pf = &pctl->functions[func];
struct pinctrl_gpio_range *range;
unsigned int i;
u32 val;
if (pg->mux_reg > 0) {
for (i = 0; i < ARRAY_SIZE(pg->mux_option); i++) {
if (pg->mux_option[i] == func)
break;
}
if (i == ARRAY_SIZE(pg->mux_option)) {
dev_err(pctl->dev, "Cannot mux pin %u to function %u\n",
group, func);
return -EINVAL;
}
val = pctl_readl(pctl, pg->mux_reg);
val &= ~(pg->mux_mask << pg->mux_shift);
val |= i << pg->mux_shift;
pctl_writel(pctl, val, pg->mux_reg);
if (pf->scenarios) {
for (i = 0; i < pf->nscenarios; i++) {
if (pf->scenarios[i] == group)
break;
}
if (WARN_ON(i == pf->nscenarios))
return -EINVAL;
val = pctl_readl(pctl, pf->scenario_reg);
val &= ~(pf->scenario_mask << pf->scenario_shift);
val |= i << pf->scenario_shift;
pctl_writel(pctl, val, pf->scenario_reg);
}
}
range = pinctrl_find_gpio_range_from_pin(pctl->pctldev, pg->pin);
if (range)
gpio_disable(gc_to_bank(range->gc), pg->pin - range->pin_base);
return 0;
}
static int pistachio_pinconf_get(struct pinctrl_dev *pctldev, unsigned pin,
unsigned long *config)
{
struct pistachio_pinctrl *pctl = pinctrl_dev_get_drvdata(pctldev);
enum pin_config_param param = pinconf_to_config_param(*config);
u32 val, arg;
switch (param) {
case PIN_CONFIG_INPUT_SCHMITT_ENABLE:
val = pctl_readl(pctl, PADS_SCHMITT_EN_REG(pin));
arg = !!(val & PADS_SCHMITT_EN_BIT(pin));
break;
case PIN_CONFIG_BIAS_HIGH_IMPEDANCE:
val = pctl_readl(pctl, PADS_PU_PD_REG(pin)) >>
PADS_PU_PD_SHIFT(pin);
arg = (val & PADS_PU_PD_MASK) == PADS_PU_PD_HIGHZ;
break;
case PIN_CONFIG_BIAS_PULL_UP:
val = pctl_readl(pctl, PADS_PU_PD_REG(pin)) >>
PADS_PU_PD_SHIFT(pin);
arg = (val & PADS_PU_PD_MASK) == PADS_PU_PD_UP;
break;
case PIN_CONFIG_BIAS_PULL_DOWN:
val = pctl_readl(pctl, PADS_PU_PD_REG(pin)) >>
PADS_PU_PD_SHIFT(pin);
arg = (val & PADS_PU_PD_MASK) == PADS_PU_PD_DOWN;
break;
case PIN_CONFIG_BIAS_BUS_HOLD:
val = pctl_readl(pctl, PADS_PU_PD_REG(pin)) >>
PADS_PU_PD_SHIFT(pin);
arg = (val & PADS_PU_PD_MASK) == PADS_PU_PD_BUS;
break;
case PIN_CONFIG_SLEW_RATE:
val = pctl_readl(pctl, PADS_SLEW_RATE_REG(pin));
arg = !!(val & PADS_SLEW_RATE_BIT(pin));
break;
case PIN_CONFIG_DRIVE_STRENGTH:
val = pctl_readl(pctl, PADS_DRIVE_STRENGTH_REG(pin)) >>
PADS_DRIVE_STRENGTH_SHIFT(pin);
switch (val & PADS_DRIVE_STRENGTH_MASK) {
case PADS_DRIVE_STRENGTH_2MA:
arg = 2;
break;
case PADS_DRIVE_STRENGTH_4MA:
arg = 4;
break;
case PADS_DRIVE_STRENGTH_8MA:
arg = 8;
break;
case PADS_DRIVE_STRENGTH_12MA:
default:
arg = 12;
break;
}
break;
default:
dev_dbg(pctl->dev, "Property %u not supported\n", param);
return -ENOTSUPP;
}
*config = pinconf_to_config_packed(param, arg);
return 0;
}
static int pistachio_pinconf_set(struct pinctrl_dev *pctldev, unsigned pin,
unsigned long *configs, unsigned num_configs)
{
struct pistachio_pinctrl *pctl = pinctrl_dev_get_drvdata(pctldev);
enum pin_config_param param;
u32 drv, val, arg;
unsigned int i;
for (i = 0; i < num_configs; i++) {
param = pinconf_to_config_param(configs[i]);
arg = pinconf_to_config_argument(configs[i]);
switch (param) {
case PIN_CONFIG_INPUT_SCHMITT_ENABLE:
val = pctl_readl(pctl, PADS_SCHMITT_EN_REG(pin));
if (arg)
val |= PADS_SCHMITT_EN_BIT(pin);
else
val &= ~PADS_SCHMITT_EN_BIT(pin);
pctl_writel(pctl, val, PADS_SCHMITT_EN_REG(pin));
break;
case PIN_CONFIG_BIAS_HIGH_IMPEDANCE:
val = pctl_readl(pctl, PADS_PU_PD_REG(pin));
val &= ~(PADS_PU_PD_MASK << PADS_PU_PD_SHIFT(pin));
val |= PADS_PU_PD_HIGHZ << PADS_PU_PD_SHIFT(pin);
pctl_writel(pctl, val, PADS_PU_PD_REG(pin));
break;
case PIN_CONFIG_BIAS_PULL_UP:
val = pctl_readl(pctl, PADS_PU_PD_REG(pin));
val &= ~(PADS_PU_PD_MASK << PADS_PU_PD_SHIFT(pin));
val |= PADS_PU_PD_UP << PADS_PU_PD_SHIFT(pin);
pctl_writel(pctl, val, PADS_PU_PD_REG(pin));
break;
case PIN_CONFIG_BIAS_PULL_DOWN:
val = pctl_readl(pctl, PADS_PU_PD_REG(pin));
val &= ~(PADS_PU_PD_MASK << PADS_PU_PD_SHIFT(pin));
val |= PADS_PU_PD_DOWN << PADS_PU_PD_SHIFT(pin);
pctl_writel(pctl, val, PADS_PU_PD_REG(pin));
break;
case PIN_CONFIG_BIAS_BUS_HOLD:
val = pctl_readl(pctl, PADS_PU_PD_REG(pin));
val &= ~(PADS_PU_PD_MASK << PADS_PU_PD_SHIFT(pin));
val |= PADS_PU_PD_BUS << PADS_PU_PD_SHIFT(pin);
pctl_writel(pctl, val, PADS_PU_PD_REG(pin));
break;
case PIN_CONFIG_SLEW_RATE:
val = pctl_readl(pctl, PADS_SLEW_RATE_REG(pin));
if (arg)
val |= PADS_SLEW_RATE_BIT(pin);
else
val &= ~PADS_SLEW_RATE_BIT(pin);
pctl_writel(pctl, val, PADS_SLEW_RATE_REG(pin));
break;
case PIN_CONFIG_DRIVE_STRENGTH:
val = pctl_readl(pctl, PADS_DRIVE_STRENGTH_REG(pin));
val &= ~(PADS_DRIVE_STRENGTH_MASK <<
PADS_DRIVE_STRENGTH_SHIFT(pin));
switch (arg) {
case 2:
drv = PADS_DRIVE_STRENGTH_2MA;
break;
case 4:
drv = PADS_DRIVE_STRENGTH_4MA;
break;
case 8:
drv = PADS_DRIVE_STRENGTH_8MA;
break;
case 12:
drv = PADS_DRIVE_STRENGTH_12MA;
break;
default:
dev_err(pctl->dev,
"Drive strength %umA not supported\n",
arg);
return -EINVAL;
}
val |= drv << PADS_DRIVE_STRENGTH_SHIFT(pin);
pctl_writel(pctl, val, PADS_DRIVE_STRENGTH_REG(pin));
break;
default:
dev_err(pctl->dev, "Property %u not supported\n",
param);
return -ENOTSUPP;
}
}
return 0;
}
static int pistachio_gpio_get_direction(struct gpio_chip *chip, unsigned offset)
{
struct pistachio_gpio_bank *bank = gc_to_bank(chip);
return !(gpio_readl(bank, GPIO_OUTPUT_EN) & BIT(offset));
}
static int pistachio_gpio_get(struct gpio_chip *chip, unsigned offset)
{
struct pistachio_gpio_bank *bank = gc_to_bank(chip);
u32 reg;
if (gpio_readl(bank, GPIO_OUTPUT_EN) & BIT(offset))
reg = GPIO_OUTPUT;
else
reg = GPIO_INPUT;
return !!(gpio_readl(bank, reg) & BIT(offset));
}
static void pistachio_gpio_set(struct gpio_chip *chip, unsigned offset,
int value)
{
struct pistachio_gpio_bank *bank = gc_to_bank(chip);
gpio_mask_writel(bank, GPIO_OUTPUT, offset, !!value);
}
static int pistachio_gpio_direction_input(struct gpio_chip *chip,
unsigned offset)
{
struct pistachio_gpio_bank *bank = gc_to_bank(chip);
gpio_mask_writel(bank, GPIO_OUTPUT_EN, offset, 0);
gpio_enable(bank, offset);
return 0;
}
static int pistachio_gpio_direction_output(struct gpio_chip *chip,
unsigned offset, int value)
{
struct pistachio_gpio_bank *bank = gc_to_bank(chip);
pistachio_gpio_set(chip, offset, value);
gpio_mask_writel(bank, GPIO_OUTPUT_EN, offset, 1);
gpio_enable(bank, offset);
return 0;
}
static void pistachio_gpio_irq_ack(struct irq_data *data)
{
struct pistachio_gpio_bank *bank = irqd_to_bank(data);
gpio_mask_writel(bank, GPIO_INTERRUPT_STATUS, data->hwirq, 0);
}
static void pistachio_gpio_irq_mask(struct irq_data *data)
{
struct pistachio_gpio_bank *bank = irqd_to_bank(data);
gpio_mask_writel(bank, GPIO_INTERRUPT_EN, data->hwirq, 0);
}
static void pistachio_gpio_irq_unmask(struct irq_data *data)
{
struct pistachio_gpio_bank *bank = irqd_to_bank(data);
gpio_mask_writel(bank, GPIO_INTERRUPT_EN, data->hwirq, 1);
}
static unsigned int pistachio_gpio_irq_startup(struct irq_data *data)
{
struct gpio_chip *chip = irq_data_get_irq_chip_data(data);
pistachio_gpio_direction_input(chip, data->hwirq);
pistachio_gpio_irq_unmask(data);
return 0;
}
static int pistachio_gpio_irq_set_type(struct irq_data *data, unsigned int type)
{
struct pistachio_gpio_bank *bank = irqd_to_bank(data);
switch (type & IRQ_TYPE_SENSE_MASK) {
case IRQ_TYPE_EDGE_RISING:
gpio_mask_writel(bank, GPIO_INPUT_POLARITY, data->hwirq, 1);
gpio_mask_writel(bank, GPIO_INTERRUPT_TYPE, data->hwirq,
GPIO_INTERRUPT_TYPE_EDGE);
gpio_mask_writel(bank, GPIO_INTERRUPT_EDGE, data->hwirq,
GPIO_INTERRUPT_EDGE_SINGLE);
break;
case IRQ_TYPE_EDGE_FALLING:
gpio_mask_writel(bank, GPIO_INPUT_POLARITY, data->hwirq, 0);
gpio_mask_writel(bank, GPIO_INTERRUPT_TYPE, data->hwirq,
GPIO_INTERRUPT_TYPE_EDGE);
gpio_mask_writel(bank, GPIO_INTERRUPT_EDGE, data->hwirq,
GPIO_INTERRUPT_EDGE_SINGLE);
break;
case IRQ_TYPE_EDGE_BOTH:
gpio_mask_writel(bank, GPIO_INTERRUPT_TYPE, data->hwirq,
GPIO_INTERRUPT_TYPE_EDGE);
gpio_mask_writel(bank, GPIO_INTERRUPT_EDGE, data->hwirq,
GPIO_INTERRUPT_EDGE_DUAL);
break;
case IRQ_TYPE_LEVEL_HIGH:
gpio_mask_writel(bank, GPIO_INPUT_POLARITY, data->hwirq, 1);
gpio_mask_writel(bank, GPIO_INTERRUPT_TYPE, data->hwirq,
GPIO_INTERRUPT_TYPE_LEVEL);
break;
case IRQ_TYPE_LEVEL_LOW:
gpio_mask_writel(bank, GPIO_INPUT_POLARITY, data->hwirq, 0);
gpio_mask_writel(bank, GPIO_INTERRUPT_TYPE, data->hwirq,
GPIO_INTERRUPT_TYPE_LEVEL);
break;
default:
return -EINVAL;
}
if (type & IRQ_TYPE_LEVEL_MASK)
irq_set_handler_locked(data, handle_level_irq);
else
irq_set_handler_locked(data, handle_edge_irq);
return 0;
}
static void pistachio_gpio_irq_handler(struct irq_desc *desc)
{
struct gpio_chip *gc = irq_desc_get_handler_data(desc);
struct pistachio_gpio_bank *bank = gc_to_bank(gc);
struct irq_chip *chip = irq_desc_get_chip(desc);
unsigned long pending;
unsigned int pin;
chained_irq_enter(chip, desc);
pending = gpio_readl(bank, GPIO_INTERRUPT_STATUS) &
gpio_readl(bank, GPIO_INTERRUPT_EN);
for_each_set_bit(pin, &pending, 16)
generic_handle_irq(irq_linear_revmap(gc->irqdomain, pin));
chained_irq_exit(chip, desc);
}
static int pistachio_gpio_register(struct pistachio_pinctrl *pctl)
{
struct device_node *node = pctl->dev->of_node;
struct pistachio_gpio_bank *bank;
unsigned int i;
int irq, ret = 0;
for (i = 0; i < pctl->nbanks; i++) {
char child_name[sizeof("gpioXX")];
struct device_node *child;
snprintf(child_name, sizeof(child_name), "gpio%d", i);
child = of_get_child_by_name(node, child_name);
if (!child) {
dev_err(pctl->dev, "No node for bank %u\n", i);
ret = -ENODEV;
goto err;
}
if (!of_find_property(child, "gpio-controller", NULL)) {
dev_err(pctl->dev,
"No gpio-controller property for bank %u\n", i);
ret = -ENODEV;
goto err;
}
irq = irq_of_parse_and_map(child, 0);
if (irq < 0) {
dev_err(pctl->dev, "No IRQ for bank %u: %d\n", i, irq);
ret = irq;
goto err;
}
bank = &pctl->gpio_banks[i];
bank->pctl = pctl;
bank->base = pctl->base + GPIO_BANK_BASE(i);
bank->gpio_chip.dev = pctl->dev;
bank->gpio_chip.of_node = child;
ret = gpiochip_add(&bank->gpio_chip);
if (ret < 0) {
dev_err(pctl->dev, "Failed to add GPIO chip %u: %d\n",
i, ret);
goto err;
}
ret = gpiochip_irqchip_add(&bank->gpio_chip, &bank->irq_chip,
0, handle_level_irq, IRQ_TYPE_NONE);
if (ret < 0) {
dev_err(pctl->dev, "Failed to add IRQ chip %u: %d\n",
i, ret);
gpiochip_remove(&bank->gpio_chip);
goto err;
}
gpiochip_set_chained_irqchip(&bank->gpio_chip, &bank->irq_chip,
irq, pistachio_gpio_irq_handler);
ret = gpiochip_add_pin_range(&bank->gpio_chip,
dev_name(pctl->dev), 0,
bank->pin_base, bank->npins);
if (ret < 0) {
dev_err(pctl->dev, "Failed to add GPIO range %u: %d\n",
i, ret);
gpiochip_remove(&bank->gpio_chip);
goto err;
}
}
return 0;
err:
for (; i > 0; i--) {
bank = &pctl->gpio_banks[i - 1];
gpiochip_remove(&bank->gpio_chip);
}
return ret;
}
static int pistachio_pinctrl_probe(struct platform_device *pdev)
{
struct pistachio_pinctrl *pctl;
struct resource *res;
int ret;
pctl = devm_kzalloc(&pdev->dev, sizeof(*pctl), GFP_KERNEL);
if (!pctl)
return -ENOMEM;
pctl->dev = &pdev->dev;
dev_set_drvdata(&pdev->dev, pctl);
res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
pctl->base = devm_ioremap_resource(&pdev->dev, res);
if (IS_ERR(pctl->base))
return PTR_ERR(pctl->base);
pctl->pins = pistachio_pins;
pctl->npins = ARRAY_SIZE(pistachio_pins);
pctl->functions = pistachio_functions;
pctl->nfunctions = ARRAY_SIZE(pistachio_functions);
pctl->groups = pistachio_groups;
pctl->ngroups = ARRAY_SIZE(pistachio_groups);
pctl->gpio_banks = pistachio_gpio_banks;
pctl->nbanks = ARRAY_SIZE(pistachio_gpio_banks);
pistachio_pinctrl_desc.pins = pctl->pins;
pistachio_pinctrl_desc.npins = pctl->npins;
pctl->pctldev = pinctrl_register(&pistachio_pinctrl_desc, &pdev->dev,
pctl);
if (IS_ERR(pctl->pctldev)) {
dev_err(&pdev->dev, "Failed to register pinctrl device\n");
return PTR_ERR(pctl->pctldev);
}
ret = pistachio_gpio_register(pctl);
if (ret < 0) {
pinctrl_unregister(pctl->pctldev);
return ret;
}
return 0;
}
static int __init pistachio_pinctrl_register(void)
{
return platform_driver_register(&pistachio_pinctrl_driver);
}
