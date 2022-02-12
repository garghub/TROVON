static inline struct oxnas_gpio_bank *pctl_to_bank(struct oxnas_pinctrl *pctl,
unsigned int pin)
{
return &pctl->gpio_banks[pin / PINS_PER_BANK];
}
static int oxnas_pinctrl_get_groups_count(struct pinctrl_dev *pctldev)
{
struct oxnas_pinctrl *pctl = pinctrl_dev_get_drvdata(pctldev);
return pctl->ngroups;
}
static const char *oxnas_pinctrl_get_group_name(struct pinctrl_dev *pctldev,
unsigned int group)
{
struct oxnas_pinctrl *pctl = pinctrl_dev_get_drvdata(pctldev);
return pctl->groups[group].name;
}
static int oxnas_pinctrl_get_group_pins(struct pinctrl_dev *pctldev,
unsigned int group,
const unsigned int **pins,
unsigned int *num_pins)
{
struct oxnas_pinctrl *pctl = pinctrl_dev_get_drvdata(pctldev);
*pins = &pctl->groups[group].pin;
*num_pins = 1;
return 0;
}
static int oxnas_pinmux_get_functions_count(struct pinctrl_dev *pctldev)
{
struct oxnas_pinctrl *pctl = pinctrl_dev_get_drvdata(pctldev);
return pctl->nfunctions;
}
static const char *
oxnas_pinmux_get_function_name(struct pinctrl_dev *pctldev, unsigned int func)
{
struct oxnas_pinctrl *pctl = pinctrl_dev_get_drvdata(pctldev);
return pctl->functions[func].name;
}
static int oxnas_pinmux_get_function_groups(struct pinctrl_dev *pctldev,
unsigned int func,
const char * const **groups,
unsigned int * const num_groups)
{
struct oxnas_pinctrl *pctl = pinctrl_dev_get_drvdata(pctldev);
*groups = pctl->functions[func].groups;
*num_groups = pctl->functions[func].ngroups;
return 0;
}
static int oxnas_ox810se_pinmux_enable(struct pinctrl_dev *pctldev,
unsigned int func, unsigned int group)
{
struct oxnas_pinctrl *pctl = pinctrl_dev_get_drvdata(pctldev);
const struct oxnas_pin_group *pg = &pctl->groups[group];
const struct oxnas_function *pf = &pctl->functions[func];
const char *fname = pf->name;
struct oxnas_desc_function *functions = pg->functions;
u32 mask = BIT(pg->pin);
while (functions->name) {
if (!strcmp(functions->name, fname)) {
dev_dbg(pctl->dev,
"setting function %s bank %d pin %d fct %d mask %x\n",
fname, pg->bank, pg->pin,
functions->fct, mask);
regmap_write_bits(pctl->regmap,
(pg->bank ?
PINMUX_810_PRIMARY_SEL1 :
PINMUX_810_PRIMARY_SEL0),
mask,
(functions->fct == 1 ?
mask : 0));
regmap_write_bits(pctl->regmap,
(pg->bank ?
PINMUX_810_SECONDARY_SEL1 :
PINMUX_810_SECONDARY_SEL0),
mask,
(functions->fct == 2 ?
mask : 0));
regmap_write_bits(pctl->regmap,
(pg->bank ?
PINMUX_810_TERTIARY_SEL1 :
PINMUX_810_TERTIARY_SEL0),
mask,
(functions->fct == 3 ?
mask : 0));
return 0;
}
functions++;
}
dev_err(pctl->dev, "cannot mux pin %u to function %u\n", group, func);
return -EINVAL;
}
static int oxnas_ox820_pinmux_enable(struct pinctrl_dev *pctldev,
unsigned int func, unsigned int group)
{
struct oxnas_pinctrl *pctl = pinctrl_dev_get_drvdata(pctldev);
const struct oxnas_pin_group *pg = &pctl->groups[group];
const struct oxnas_function *pf = &pctl->functions[func];
const char *fname = pf->name;
struct oxnas_desc_function *functions = pg->functions;
unsigned int offset = (pg->bank ? PINMUX_820_BANK_OFFSET : 0);
u32 mask = BIT(pg->pin);
while (functions->name) {
if (!strcmp(functions->name, fname)) {
dev_dbg(pctl->dev,
"setting function %s bank %d pin %d fct %d mask %x\n",
fname, pg->bank, pg->pin,
functions->fct, mask);
regmap_write_bits(pctl->regmap,
offset + PINMUX_820_SECONDARY_SEL,
mask,
(functions->fct == 1 ?
mask : 0));
regmap_write_bits(pctl->regmap,
offset + PINMUX_820_TERTIARY_SEL,
mask,
(functions->fct == 2 ?
mask : 0));
regmap_write_bits(pctl->regmap,
offset + PINMUX_820_QUATERNARY_SEL,
mask,
(functions->fct == 3 ?
mask : 0));
regmap_write_bits(pctl->regmap,
offset + PINMUX_820_DEBUG_SEL,
mask,
(functions->fct == 4 ?
mask : 0));
regmap_write_bits(pctl->regmap,
offset + PINMUX_820_ALTERNATIVE_SEL,
mask,
(functions->fct == 5 ?
mask : 0));
return 0;
}
functions++;
}
dev_err(pctl->dev, "cannot mux pin %u to function %u\n", group, func);
return -EINVAL;
}
static int oxnas_ox810se_gpio_request_enable(struct pinctrl_dev *pctldev,
struct pinctrl_gpio_range *range,
unsigned int offset)
{
struct oxnas_pinctrl *pctl = pinctrl_dev_get_drvdata(pctldev);
struct oxnas_gpio_bank *bank = gpiochip_get_data(range->gc);
u32 mask = BIT(offset - bank->gpio_chip.base);
dev_dbg(pctl->dev, "requesting gpio %d in bank %d (id %d) with mask 0x%x\n",
offset, bank->gpio_chip.base, bank->id, mask);
regmap_write_bits(pctl->regmap,
(bank->id ?
PINMUX_810_PRIMARY_SEL1 :
PINMUX_810_PRIMARY_SEL0),
mask, 0);
regmap_write_bits(pctl->regmap,
(bank->id ?
PINMUX_810_SECONDARY_SEL1 :
PINMUX_810_SECONDARY_SEL0),
mask, 0);
regmap_write_bits(pctl->regmap,
(bank->id ?
PINMUX_810_TERTIARY_SEL1 :
PINMUX_810_TERTIARY_SEL0),
mask, 0);
return 0;
}
static int oxnas_ox820_gpio_request_enable(struct pinctrl_dev *pctldev,
struct pinctrl_gpio_range *range,
unsigned int offset)
{
struct oxnas_pinctrl *pctl = pinctrl_dev_get_drvdata(pctldev);
struct oxnas_gpio_bank *bank = gpiochip_get_data(range->gc);
unsigned int bank_offset = (bank->id ? PINMUX_820_BANK_OFFSET : 0);
u32 mask = BIT(offset - bank->gpio_chip.base);
dev_dbg(pctl->dev, "requesting gpio %d in bank %d (id %d) with mask 0x%x\n",
offset, bank->gpio_chip.base, bank->id, mask);
regmap_write_bits(pctl->regmap,
bank_offset + PINMUX_820_SECONDARY_SEL,
mask, 0);
regmap_write_bits(pctl->regmap,
bank_offset + PINMUX_820_TERTIARY_SEL,
mask, 0);
regmap_write_bits(pctl->regmap,
bank_offset + PINMUX_820_QUATERNARY_SEL,
mask, 0);
regmap_write_bits(pctl->regmap,
bank_offset + PINMUX_820_DEBUG_SEL,
mask, 0);
regmap_write_bits(pctl->regmap,
bank_offset + PINMUX_820_ALTERNATIVE_SEL,
mask, 0);
return 0;
}
static int oxnas_gpio_get_direction(struct gpio_chip *chip,
unsigned int offset)
{
struct oxnas_gpio_bank *bank = gpiochip_get_data(chip);
u32 mask = BIT(offset);
return !(readl_relaxed(bank->reg_base + OUTPUT_EN) & mask);
}
static int oxnas_gpio_direction_input(struct gpio_chip *chip,
unsigned int offset)
{
struct oxnas_gpio_bank *bank = gpiochip_get_data(chip);
u32 mask = BIT(offset);
writel_relaxed(mask, bank->reg_base + OUTPUT_EN_CLEAR);
return 0;
}
static int oxnas_gpio_get(struct gpio_chip *chip, unsigned int offset)
{
struct oxnas_gpio_bank *bank = gpiochip_get_data(chip);
u32 mask = BIT(offset);
return (readl_relaxed(bank->reg_base + INPUT_VALUE) & mask) != 0;
}
static void oxnas_gpio_set(struct gpio_chip *chip, unsigned int offset,
int value)
{
struct oxnas_gpio_bank *bank = gpiochip_get_data(chip);
u32 mask = BIT(offset);
if (value)
writel_relaxed(mask, bank->reg_base + OUTPUT_SET);
else
writel_relaxed(mask, bank->reg_base + OUTPUT_CLEAR);
}
static int oxnas_gpio_direction_output(struct gpio_chip *chip,
unsigned int offset, int value)
{
struct oxnas_gpio_bank *bank = gpiochip_get_data(chip);
u32 mask = BIT(offset);
oxnas_gpio_set(chip, offset, value);
writel_relaxed(mask, bank->reg_base + OUTPUT_EN_SET);
return 0;
}
static int oxnas_gpio_set_direction(struct pinctrl_dev *pctldev,
struct pinctrl_gpio_range *range,
unsigned int offset, bool input)
{
struct gpio_chip *chip = range->gc;
if (input)
oxnas_gpio_direction_input(chip, offset);
else
oxnas_gpio_direction_output(chip, offset, 0);
return 0;
}
static int oxnas_ox810se_pinconf_get(struct pinctrl_dev *pctldev,
unsigned int pin, unsigned long *config)
{
struct oxnas_pinctrl *pctl = pinctrl_dev_get_drvdata(pctldev);
struct oxnas_gpio_bank *bank = pctl_to_bank(pctl, pin);
unsigned int param = pinconf_to_config_param(*config);
u32 mask = BIT(pin - bank->gpio_chip.base);
int ret;
u32 arg;
switch (param) {
case PIN_CONFIG_BIAS_PULL_UP:
ret = regmap_read(pctl->regmap,
(bank->id ?
PINMUX_810_PULLUP_CTRL1 :
PINMUX_810_PULLUP_CTRL0),
&arg);
if (ret)
return ret;
arg = !!(arg & mask);
break;
default:
return -ENOTSUPP;
}
*config = pinconf_to_config_packed(param, arg);
return 0;
}
static int oxnas_ox820_pinconf_get(struct pinctrl_dev *pctldev,
unsigned int pin, unsigned long *config)
{
struct oxnas_pinctrl *pctl = pinctrl_dev_get_drvdata(pctldev);
struct oxnas_gpio_bank *bank = pctl_to_bank(pctl, pin);
unsigned int param = pinconf_to_config_param(*config);
unsigned int bank_offset = (bank->id ? PINMUX_820_BANK_OFFSET : 0);
u32 mask = BIT(pin - bank->gpio_chip.base);
int ret;
u32 arg;
switch (param) {
case PIN_CONFIG_BIAS_PULL_UP:
ret = regmap_read(pctl->regmap,
bank_offset + PINMUX_820_PULLUP_CTRL,
&arg);
if (ret)
return ret;
arg = !!(arg & mask);
break;
default:
return -ENOTSUPP;
}
*config = pinconf_to_config_packed(param, arg);
return 0;
}
static int oxnas_ox810se_pinconf_set(struct pinctrl_dev *pctldev,
unsigned int pin, unsigned long *configs,
unsigned int num_configs)
{
struct oxnas_pinctrl *pctl = pinctrl_dev_get_drvdata(pctldev);
struct oxnas_gpio_bank *bank = pctl_to_bank(pctl, pin);
unsigned int param;
u32 arg;
unsigned int i;
u32 offset = pin - bank->gpio_chip.base;
u32 mask = BIT(offset);
dev_dbg(pctl->dev, "setting pin %d bank %d mask 0x%x\n",
pin, bank->gpio_chip.base, mask);
for (i = 0; i < num_configs; i++) {
param = pinconf_to_config_param(configs[i]);
arg = pinconf_to_config_argument(configs[i]);
switch (param) {
case PIN_CONFIG_BIAS_PULL_UP:
dev_dbg(pctl->dev, " pullup\n");
regmap_write_bits(pctl->regmap,
(bank->id ?
PINMUX_810_PULLUP_CTRL1 :
PINMUX_810_PULLUP_CTRL0),
mask, mask);
break;
default:
dev_err(pctl->dev, "Property %u not supported\n",
param);
return -ENOTSUPP;
}
}
return 0;
}
static int oxnas_ox820_pinconf_set(struct pinctrl_dev *pctldev,
unsigned int pin, unsigned long *configs,
unsigned int num_configs)
{
struct oxnas_pinctrl *pctl = pinctrl_dev_get_drvdata(pctldev);
struct oxnas_gpio_bank *bank = pctl_to_bank(pctl, pin);
unsigned int bank_offset = (bank->id ? PINMUX_820_BANK_OFFSET : 0);
unsigned int param;
u32 arg;
unsigned int i;
u32 offset = pin - bank->gpio_chip.base;
u32 mask = BIT(offset);
dev_dbg(pctl->dev, "setting pin %d bank %d mask 0x%x\n",
pin, bank->gpio_chip.base, mask);
for (i = 0; i < num_configs; i++) {
param = pinconf_to_config_param(configs[i]);
arg = pinconf_to_config_argument(configs[i]);
switch (param) {
case PIN_CONFIG_BIAS_PULL_UP:
dev_dbg(pctl->dev, " pullup\n");
regmap_write_bits(pctl->regmap,
bank_offset + PINMUX_820_PULLUP_CTRL,
mask, mask);
break;
default:
dev_err(pctl->dev, "Property %u not supported\n",
param);
return -ENOTSUPP;
}
}
return 0;
}
static void oxnas_gpio_irq_ack(struct irq_data *data)
{
struct gpio_chip *chip = irq_data_get_irq_chip_data(data);
struct oxnas_gpio_bank *bank = gpiochip_get_data(chip);
u32 mask = BIT(data->hwirq);
writel(mask, bank->reg_base + IRQ_PENDING);
}
static void oxnas_gpio_irq_mask(struct irq_data *data)
{
struct gpio_chip *chip = irq_data_get_irq_chip_data(data);
struct oxnas_gpio_bank *bank = gpiochip_get_data(chip);
unsigned int type = irqd_get_trigger_type(data);
u32 mask = BIT(data->hwirq);
if (type & IRQ_TYPE_EDGE_RISING)
writel(readl(bank->reg_base + RE_IRQ_ENABLE) & ~mask,
bank->reg_base + RE_IRQ_ENABLE);
if (type & IRQ_TYPE_EDGE_FALLING)
writel(readl(bank->reg_base + FE_IRQ_ENABLE) & ~mask,
bank->reg_base + FE_IRQ_ENABLE);
}
static void oxnas_gpio_irq_unmask(struct irq_data *data)
{
struct gpio_chip *chip = irq_data_get_irq_chip_data(data);
struct oxnas_gpio_bank *bank = gpiochip_get_data(chip);
unsigned int type = irqd_get_trigger_type(data);
u32 mask = BIT(data->hwirq);
if (type & IRQ_TYPE_EDGE_RISING)
writel(readl(bank->reg_base + RE_IRQ_ENABLE) | mask,
bank->reg_base + RE_IRQ_ENABLE);
if (type & IRQ_TYPE_EDGE_FALLING)
writel(readl(bank->reg_base + FE_IRQ_ENABLE) | mask,
bank->reg_base + FE_IRQ_ENABLE);
}
static unsigned int oxnas_gpio_irq_startup(struct irq_data *data)
{
struct gpio_chip *chip = irq_data_get_irq_chip_data(data);
oxnas_gpio_direction_input(chip, data->hwirq);
oxnas_gpio_irq_unmask(data);
return 0;
}
static int oxnas_gpio_irq_set_type(struct irq_data *data, unsigned int type)
{
if ((type & (IRQ_TYPE_EDGE_RISING|IRQ_TYPE_EDGE_FALLING)) == 0)
return -EINVAL;
irq_set_handler_locked(data, handle_edge_irq);
return 0;
}
static void oxnas_gpio_irq_handler(struct irq_desc *desc)
{
struct gpio_chip *gc = irq_desc_get_handler_data(desc);
struct oxnas_gpio_bank *bank = gpiochip_get_data(gc);
struct irq_chip *chip = irq_desc_get_chip(desc);
unsigned long stat;
unsigned int pin;
chained_irq_enter(chip, desc);
stat = readl(bank->reg_base + IRQ_PENDING);
for_each_set_bit(pin, &stat, BITS_PER_LONG)
generic_handle_irq(irq_linear_revmap(gc->irqdomain, pin));
chained_irq_exit(chip, desc);
}
static int oxnas_pinctrl_probe(struct platform_device *pdev)
{
const struct of_device_id *id;
const struct oxnas_pinctrl_data *data;
struct oxnas_pinctrl *pctl;
id = of_match_node(oxnas_pinctrl_of_match, pdev->dev.of_node);
if (!id)
return -ENODEV;
data = id->data;
if (!data || !data->pctl || !data->desc)
return -EINVAL;
pctl = devm_kzalloc(&pdev->dev, sizeof(*pctl), GFP_KERNEL);
if (!pctl)
return -ENOMEM;
pctl->dev = &pdev->dev;
dev_set_drvdata(&pdev->dev, pctl);
pctl->regmap = syscon_regmap_lookup_by_phandle(pdev->dev.of_node,
"oxsemi,sys-ctrl");
if (IS_ERR(pctl->regmap)) {
dev_err(&pdev->dev, "failed to get sys ctrl regmap\n");
return -ENODEV;
}
pctl->functions = data->pctl->functions;
pctl->nfunctions = data->pctl->nfunctions;
pctl->groups = data->pctl->groups;
pctl->ngroups = data->pctl->ngroups;
pctl->gpio_banks = data->pctl->gpio_banks;
pctl->nbanks = data->pctl->nbanks;
pctl->pctldev = pinctrl_register(data->desc, &pdev->dev, pctl);
if (IS_ERR(pctl->pctldev)) {
dev_err(&pdev->dev, "Failed to register pinctrl device\n");
return PTR_ERR(pctl->pctldev);
}
return 0;
}
static int oxnas_gpio_probe(struct platform_device *pdev)
{
struct device_node *np = pdev->dev.of_node;
struct of_phandle_args pinspec;
struct oxnas_gpio_bank *bank;
unsigned int id, ngpios;
int irq, ret;
struct resource *res;
if (of_parse_phandle_with_fixed_args(np, "gpio-ranges",
3, 0, &pinspec)) {
dev_err(&pdev->dev, "gpio-ranges property not found\n");
return -EINVAL;
}
id = pinspec.args[1] / PINS_PER_BANK;
ngpios = pinspec.args[2];
if (id >= ARRAY_SIZE(oxnas_gpio_banks)) {
dev_err(&pdev->dev, "invalid gpio-ranges base arg\n");
return -EINVAL;
}
if (ngpios > PINS_PER_BANK) {
dev_err(&pdev->dev, "invalid gpio-ranges count arg\n");
return -EINVAL;
}
bank = &oxnas_gpio_banks[id];
res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
bank->reg_base = devm_ioremap_resource(&pdev->dev, res);
if (IS_ERR(bank->reg_base))
return PTR_ERR(bank->reg_base);
irq = platform_get_irq(pdev, 0);
if (irq < 0) {
dev_err(&pdev->dev, "irq get failed\n");
return irq;
}
bank->id = id;
bank->gpio_chip.parent = &pdev->dev;
bank->gpio_chip.of_node = np;
bank->gpio_chip.ngpio = ngpios;
ret = gpiochip_add_data(&bank->gpio_chip, bank);
if (ret < 0) {
dev_err(&pdev->dev, "Failed to add GPIO chip %u: %d\n",
id, ret);
return ret;
}
ret = gpiochip_irqchip_add(&bank->gpio_chip, &bank->irq_chip,
0, handle_level_irq, IRQ_TYPE_NONE);
if (ret < 0) {
dev_err(&pdev->dev, "Failed to add IRQ chip %u: %d\n",
id, ret);
gpiochip_remove(&bank->gpio_chip);
return ret;
}
gpiochip_set_chained_irqchip(&bank->gpio_chip, &bank->irq_chip,
irq, oxnas_gpio_irq_handler);
return 0;
}
static int __init oxnas_gpio_register(void)
{
return platform_driver_register(&oxnas_gpio_driver);
}
static int __init oxnas_pinctrl_register(void)
{
return platform_driver_register(&oxnas_pinctrl_driver);
}
