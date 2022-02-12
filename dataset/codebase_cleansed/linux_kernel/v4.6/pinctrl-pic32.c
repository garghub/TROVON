static inline struct pic32_gpio_bank *irqd_to_bank(struct irq_data *d)
{
return gpiochip_get_data(irq_data_get_irq_chip_data(d));
}
static inline struct pic32_gpio_bank *pctl_to_bank(struct pic32_pinctrl *pctl,
unsigned pin)
{
return &pctl->gpio_banks[pin / PINS_PER_BANK];
}
static int pic32_pinctrl_get_groups_count(struct pinctrl_dev *pctldev)
{
struct pic32_pinctrl *pctl = pinctrl_dev_get_drvdata(pctldev);
return pctl->ngroups;
}
static const char *pic32_pinctrl_get_group_name(struct pinctrl_dev *pctldev,
unsigned group)
{
struct pic32_pinctrl *pctl = pinctrl_dev_get_drvdata(pctldev);
return pctl->groups[group].name;
}
static int pic32_pinctrl_get_group_pins(struct pinctrl_dev *pctldev,
unsigned group,
const unsigned **pins,
unsigned *num_pins)
{
struct pic32_pinctrl *pctl = pinctrl_dev_get_drvdata(pctldev);
*pins = &pctl->groups[group].pin;
*num_pins = 1;
return 0;
}
static int pic32_pinmux_get_functions_count(struct pinctrl_dev *pctldev)
{
struct pic32_pinctrl *pctl = pinctrl_dev_get_drvdata(pctldev);
return pctl->nfunctions;
}
static const char *
pic32_pinmux_get_function_name(struct pinctrl_dev *pctldev, unsigned func)
{
struct pic32_pinctrl *pctl = pinctrl_dev_get_drvdata(pctldev);
return pctl->functions[func].name;
}
static int pic32_pinmux_get_function_groups(struct pinctrl_dev *pctldev,
unsigned func,
const char * const **groups,
unsigned * const num_groups)
{
struct pic32_pinctrl *pctl = pinctrl_dev_get_drvdata(pctldev);
*groups = pctl->functions[func].groups;
*num_groups = pctl->functions[func].ngroups;
return 0;
}
static int pic32_pinmux_enable(struct pinctrl_dev *pctldev,
unsigned func, unsigned group)
{
struct pic32_pinctrl *pctl = pinctrl_dev_get_drvdata(pctldev);
const struct pic32_pin_group *pg = &pctl->groups[group];
const struct pic32_function *pf = &pctl->functions[func];
const char *fname = pf->name;
struct pic32_desc_function *functions = pg->functions;
while (functions->name) {
if (!strcmp(functions->name, fname)) {
dev_dbg(pctl->dev,
"setting function %s reg 0x%x = %d\n",
fname, functions->muxreg, functions->muxval);
writel(functions->muxval, pctl->reg_base + functions->muxreg);
return 0;
}
functions++;
}
dev_err(pctl->dev, "cannot mux pin %u to function %u\n", group, func);
return -EINVAL;
}
static int pic32_gpio_request_enable(struct pinctrl_dev *pctldev,
struct pinctrl_gpio_range *range,
unsigned offset)
{
struct pic32_pinctrl *pctl = pinctrl_dev_get_drvdata(pctldev);
struct pic32_gpio_bank *bank = gpiochip_get_data(range->gc);
u32 mask = BIT(offset - bank->gpio_chip.base);
dev_dbg(pctl->dev, "requesting gpio %d in bank %d with mask 0x%x\n",
offset, bank->gpio_chip.base, mask);
writel(mask, bank->reg_base + PIC32_CLR(ANSEL_REG));
return 0;
}
static int pic32_gpio_direction_input(struct gpio_chip *chip,
unsigned offset)
{
struct pic32_gpio_bank *bank = gpiochip_get_data(chip);
u32 mask = BIT(offset);
writel(mask, bank->reg_base + PIC32_SET(TRIS_REG));
return 0;
}
static int pic32_gpio_get(struct gpio_chip *chip, unsigned offset)
{
struct pic32_gpio_bank *bank = gpiochip_get_data(chip);
return !!(readl(bank->reg_base + PORT_REG) & BIT(offset));
}
static void pic32_gpio_set(struct gpio_chip *chip, unsigned offset,
int value)
{
struct pic32_gpio_bank *bank = gpiochip_get_data(chip);
u32 mask = BIT(offset);
if (value)
writel(mask, bank->reg_base + PIC32_SET(PORT_REG));
else
writel(mask, bank->reg_base + PIC32_CLR(PORT_REG));
}
static int pic32_gpio_direction_output(struct gpio_chip *chip,
unsigned offset, int value)
{
struct pic32_gpio_bank *bank = gpiochip_get_data(chip);
u32 mask = BIT(offset);
pic32_gpio_set(chip, offset, value);
writel(mask, bank->reg_base + PIC32_CLR(TRIS_REG));
return 0;
}
static int pic32_gpio_set_direction(struct pinctrl_dev *pctldev,
struct pinctrl_gpio_range *range,
unsigned offset, bool input)
{
struct gpio_chip *chip = range->gc;
if (input)
pic32_gpio_direction_input(chip, offset);
else
pic32_gpio_direction_output(chip, offset, 0);
return 0;
}
static int pic32_pinconf_get(struct pinctrl_dev *pctldev, unsigned pin,
unsigned long *config)
{
struct pic32_pinctrl *pctl = pinctrl_dev_get_drvdata(pctldev);
struct pic32_gpio_bank *bank = pctl_to_bank(pctl, pin);
unsigned param = pinconf_to_config_param(*config);
u32 mask = BIT(pin - bank->gpio_chip.base);
u32 arg;
switch (param) {
case PIN_CONFIG_BIAS_PULL_UP:
arg = !!(readl(bank->reg_base + CNPU_REG) & mask);
break;
case PIN_CONFIG_BIAS_PULL_DOWN:
arg = !!(readl(bank->reg_base + CNPD_REG) & mask);
break;
case PIN_CONFIG_MICROCHIP_DIGITAL:
arg = !(readl(bank->reg_base + ANSEL_REG) & mask);
break;
case PIN_CONFIG_MICROCHIP_ANALOG:
arg = !!(readl(bank->reg_base + ANSEL_REG) & mask);
break;
case PIN_CONFIG_DRIVE_OPEN_DRAIN:
arg = !!(readl(bank->reg_base + ODCU_REG) & mask);
break;
case PIN_CONFIG_INPUT_ENABLE:
arg = !!(readl(bank->reg_base + TRIS_REG) & mask);
break;
case PIN_CONFIG_OUTPUT:
arg = !(readl(bank->reg_base + TRIS_REG) & mask);
break;
default:
dev_err(pctl->dev, "Property %u not supported\n", param);
return -ENOTSUPP;
}
*config = pinconf_to_config_packed(param, arg);
return 0;
}
static int pic32_pinconf_set(struct pinctrl_dev *pctldev, unsigned pin,
unsigned long *configs, unsigned num_configs)
{
struct pic32_pinctrl *pctl = pinctrl_dev_get_drvdata(pctldev);
struct pic32_gpio_bank *bank = pctl_to_bank(pctl, pin);
unsigned param;
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
writel(mask, bank->reg_base +PIC32_SET(CNPU_REG));
break;
case PIN_CONFIG_BIAS_PULL_DOWN:
dev_dbg(pctl->dev, " pulldown\n");
writel(mask, bank->reg_base + PIC32_SET(CNPD_REG));
break;
case PIN_CONFIG_MICROCHIP_DIGITAL:
dev_dbg(pctl->dev, " digital\n");
writel(mask, bank->reg_base + PIC32_CLR(ANSEL_REG));
break;
case PIN_CONFIG_MICROCHIP_ANALOG:
dev_dbg(pctl->dev, " analog\n");
writel(mask, bank->reg_base + PIC32_SET(ANSEL_REG));
break;
case PIN_CONFIG_DRIVE_OPEN_DRAIN:
dev_dbg(pctl->dev, " opendrain\n");
writel(mask, bank->reg_base + PIC32_SET(ODCU_REG));
break;
case PIN_CONFIG_INPUT_ENABLE:
pic32_gpio_direction_input(&bank->gpio_chip, offset);
break;
case PIN_CONFIG_OUTPUT:
pic32_gpio_direction_output(&bank->gpio_chip,
offset, arg);
break;
default:
dev_err(pctl->dev, "Property %u not supported\n",
param);
return -ENOTSUPP;
}
}
return 0;
}
static int pic32_gpio_get_direction(struct gpio_chip *chip, unsigned offset)
{
struct pic32_gpio_bank *bank = gpiochip_get_data(chip);
return !!(readl(bank->reg_base + TRIS_REG) & BIT(offset));
}
static void pic32_gpio_irq_ack(struct irq_data *data)
{
struct pic32_gpio_bank *bank = irqd_to_bank(data);
writel(0, bank->reg_base + CNF_REG);
}
static void pic32_gpio_irq_mask(struct irq_data *data)
{
struct pic32_gpio_bank *bank = irqd_to_bank(data);
writel(BIT(PIC32_CNCON_ON), bank->reg_base + PIC32_CLR(CNCON_REG));
}
static void pic32_gpio_irq_unmask(struct irq_data *data)
{
struct pic32_gpio_bank *bank = irqd_to_bank(data);
writel(BIT(PIC32_CNCON_ON), bank->reg_base + PIC32_SET(CNCON_REG));
}
static unsigned int pic32_gpio_irq_startup(struct irq_data *data)
{
struct gpio_chip *chip = irq_data_get_irq_chip_data(data);
pic32_gpio_direction_input(chip, data->hwirq);
pic32_gpio_irq_unmask(data);
return 0;
}
static int pic32_gpio_irq_set_type(struct irq_data *data, unsigned int type)
{
struct pic32_gpio_bank *bank = irqd_to_bank(data);
u32 mask = BIT(data->hwirq);
switch (type & IRQ_TYPE_SENSE_MASK) {
case IRQ_TYPE_EDGE_RISING:
writel(mask, bank->reg_base + PIC32_SET(CNEN_REG));
writel(mask, bank->reg_base + PIC32_CLR(CNNE_REG));
writel(BIT(PIC32_CNCON_EDGE), bank->reg_base + PIC32_SET(CNCON_REG));
break;
case IRQ_TYPE_EDGE_FALLING:
writel(mask, bank->reg_base + PIC32_CLR(CNEN_REG));
writel(mask, bank->reg_base + PIC32_SET(CNNE_REG));
writel(BIT(PIC32_CNCON_EDGE), bank->reg_base + PIC32_SET(CNCON_REG));
break;
case IRQ_TYPE_EDGE_BOTH:
writel(mask, bank->reg_base + PIC32_SET(CNEN_REG));
writel(mask, bank->reg_base + PIC32_SET(CNNE_REG));
writel(BIT(PIC32_CNCON_EDGE), bank->reg_base + PIC32_SET(CNCON_REG));
break;
default:
return -EINVAL;
}
irq_set_handler_locked(data, handle_edge_irq);
return 0;
}
static u32 pic32_gpio_get_pending(struct gpio_chip *gc, unsigned long status)
{
struct pic32_gpio_bank *bank = gpiochip_get_data(gc);
u32 pending = 0;
u32 cnen_rise, cnne_fall;
u32 pin;
cnen_rise = readl(bank->reg_base + CNEN_REG);
cnne_fall = readl(bank->reg_base + CNNE_REG);
for_each_set_bit(pin, &status, BITS_PER_LONG) {
u32 mask = BIT(pin);
if ((mask & cnen_rise) || (mask && cnne_fall))
pending |= mask;
}
return pending;
}
static void pic32_gpio_irq_handler(struct irq_desc *desc)
{
struct gpio_chip *gc = irq_desc_get_handler_data(desc);
struct pic32_gpio_bank *bank = gpiochip_get_data(gc);
struct irq_chip *chip = irq_desc_get_chip(desc);
unsigned long pending;
unsigned int pin;
u32 stat;
chained_irq_enter(chip, desc);
stat = readl(bank->reg_base + CNF_REG);
pending = pic32_gpio_get_pending(gc, stat);
for_each_set_bit(pin, &pending, BITS_PER_LONG)
generic_handle_irq(irq_linear_revmap(gc->irqdomain, pin));
chained_irq_exit(chip, desc);
}
static int pic32_pinctrl_probe(struct platform_device *pdev)
{
struct pic32_pinctrl *pctl;
struct resource *res;
int ret;
pctl = devm_kzalloc(&pdev->dev, sizeof(*pctl), GFP_KERNEL);
if (!pctl)
return -ENOMEM;
pctl->dev = &pdev->dev;
dev_set_drvdata(&pdev->dev, pctl);
res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
pctl->reg_base = devm_ioremap_resource(&pdev->dev, res);
if (IS_ERR(pctl->reg_base))
return PTR_ERR(pctl->reg_base);
pctl->clk = devm_clk_get(&pdev->dev, NULL);
if (IS_ERR(pctl->clk)) {
ret = PTR_ERR(pctl->clk);
dev_err(&pdev->dev, "clk get failed\n");
return ret;
}
ret = clk_prepare_enable(pctl->clk);
if (ret) {
dev_err(&pdev->dev, "clk enable failed\n");
return ret;
}
pctl->pins = pic32_pins;
pctl->npins = ARRAY_SIZE(pic32_pins);
pctl->functions = pic32_functions;
pctl->nfunctions = ARRAY_SIZE(pic32_functions);
pctl->groups = pic32_groups;
pctl->ngroups = ARRAY_SIZE(pic32_groups);
pctl->gpio_banks = pic32_gpio_banks;
pctl->nbanks = ARRAY_SIZE(pic32_gpio_banks);
pic32_pinctrl_desc.pins = pctl->pins;
pic32_pinctrl_desc.npins = pctl->npins;
pic32_pinctrl_desc.custom_params = pic32_mpp_bindings;
pic32_pinctrl_desc.num_custom_params = ARRAY_SIZE(pic32_mpp_bindings);
pctl->pctldev = pinctrl_register(&pic32_pinctrl_desc, &pdev->dev, pctl);
if (IS_ERR(pctl->pctldev)) {
dev_err(&pdev->dev, "Failed to register pinctrl device\n");
return PTR_ERR(pctl->pctldev);
}
return 0;
}
static int pic32_gpio_probe(struct platform_device *pdev)
{
struct device_node *np = pdev->dev.of_node;
struct pic32_gpio_bank *bank;
u32 id;
int irq, ret;
struct resource *res;
if (of_property_read_u32(np, "microchip,gpio-bank", &id)) {
dev_err(&pdev->dev, "microchip,gpio-bank property not found\n");
return -EINVAL;
}
if (id >= ARRAY_SIZE(pic32_gpio_banks)) {
dev_err(&pdev->dev, "invalid microchip,gpio-bank property\n");
return -EINVAL;
}
bank = &pic32_gpio_banks[id];
res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
bank->reg_base = devm_ioremap_resource(&pdev->dev, res);
if (IS_ERR(bank->reg_base))
return PTR_ERR(bank->reg_base);
irq = platform_get_irq(pdev, 0);
if (irq < 0) {
dev_err(&pdev->dev, "irq get failed\n");
return irq;
}
bank->clk = devm_clk_get(&pdev->dev, NULL);
if (IS_ERR(bank->clk)) {
ret = PTR_ERR(bank->clk);
dev_err(&pdev->dev, "clk get failed\n");
return ret;
}
ret = clk_prepare_enable(bank->clk);
if (ret) {
dev_err(&pdev->dev, "clk enable failed\n");
return ret;
}
bank->gpio_chip.parent = &pdev->dev;
bank->gpio_chip.of_node = np;
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
irq, pic32_gpio_irq_handler);
return 0;
}
static int __init pic32_gpio_register(void)
{
return platform_driver_register(&pic32_gpio_driver);
}
static int __init pic32_pinctrl_register(void)
{
return platform_driver_register(&pic32_pinctrl_driver);
}
